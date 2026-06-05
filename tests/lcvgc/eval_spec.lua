describe("lcvgc.eval", function()
  local eval
  local sent_messages

  before_each(function()
    clear_notifications()
    sent_messages = {}

    -- connection.send モック
    package.loaded["lcvgc.connection"] = {
      send = function(msg)
        table.insert(sent_messages, msg)
      end,
      is_connected = function() return true end,
    }

    eval = reload_module("lcvgc.eval")
  end)

  describe("read_file", function()
    it("存在するファイルを読み込む", function()
      -- テスト用一時ファイル作成
      local tmpfile = os.tmpname()
      local f = io.open(tmpfile, "w")
      f:write("line1\nline2\nline3")
      f:close()

      local lines, err = eval.read_file(tmpfile)
      assert.is_nil(err)
      assert.equals(3, #lines)
      assert.equals("line1", lines[1])
      assert.equals("line2", lines[2])
      assert.equals("line3", lines[3])

      os.remove(tmpfile)
    end)

    it("存在しないファイルはエラーを返す", function()
      local lines, err = eval.read_file("/nonexistent/path/file.cvg")
      assert.is_nil(lines)
      assert.is_truthy(err)
      assert.is_truthy(err:match("Cannot read"))
    end)
  end)

  describe("expand_includes", function()
    local tmpdir

    before_each(function()
      tmpdir = os.tmpname()
      os.remove(tmpdir)
      os.execute("mkdir -p " .. tmpdir)
    end)

    after_each(function()
      os.execute("rm -rf " .. tmpdir)
    end)

    local function write_tmp(name, content)
      local path = tmpdir .. "/" .. name
      local dir = path:match("(.+)/")
      if dir then os.execute("mkdir -p " .. dir) end
      local f = io.open(path, "w")
      f:write(content)
      f:close()
      return path
    end

    it("includeなしの行をそのまま返す", function()
      local lines = { "tempo 120", "clip drums" }
      local result, source_map = eval.expand_includes(lines, "test.cvg", tmpdir, {})
      assert.same({ "tempo 120", "clip drums" }, result)
      assert.equals(2, #source_map)
      assert.equals("test.cvg", source_map[1].file)
      assert.equals(1, source_map[1].line)
    end)

    it("include文を展開する", function()
      write_tmp("header.cvg", "tempo 120\nscale C major")
      local lines = { 'include header.cvg', "clip drums" }
      local result, source_map = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.equals(3, #result)
      assert.equals("tempo 120", result[1])
      assert.equals("scale C major", result[2])
      assert.equals("clip drums", result[3])
      -- ソースマップ: 展開された行はheader.cvgを指す
      assert.equals("header.cvg", source_map[1].file:match("[^/]+$"))
      assert.equals(1, source_map[1].line)
      assert.equals("header.cvg", source_map[2].file:match("[^/]+$"))
      assert.equals(2, source_map[2].line)
      assert.equals("main.cvg", source_map[3].file)
      assert.equals(2, source_map[3].line)
    end)

    it("再帰的にincludeを展開する", function()
      write_tmp("a.cvg", 'include b.cvg\nline_a')
      write_tmp("b.cvg", "line_b")
      local lines = { 'include a.cvg', "line_main" }
      local result, source_map = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.equals(3, #result)
      assert.equals("line_b", result[1])
      assert.equals("line_a", result[2])
      assert.equals("line_main", result[3])
      -- line_bはb.cvg由来
      assert.equals("b.cvg", source_map[1].file:match("[^/]+$"))
    end)

    it("重複includeをスキップする", function()
      write_tmp("shared.cvg", "shared_line")
      local lines = { 'include shared.cvg', 'include shared.cvg', "main_line" }
      local result, _ = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      -- sharedは1回だけ展開される
      assert.equals(2, #result)
      assert.equals("shared_line", result[1])
      assert.equals("main_line", result[2])
    end)

    it("存在しないファイルのincludeでエラーを返す", function()
      local lines = { 'include nonexistent.cvg' }
      local result, source_map, err = eval.expand_includes(lines, "main.cvg", tmpdir, {})
      assert.is_truthy(err)
      assert.is_truthy(err:match("Cannot read"))
    end)
  end)

  describe("find_block_at_row", function()
    it("clipブロック全体（ヘッダ + プロパティ + 本体）を返す", function()
      local lines = {
        "clip drums_main [bars 4] {",
        "\tuse vdrum",
        "\tbd X...|X...|X...|X...",
        "}",
      }
      -- カーソルが本体の中
      local s, e = eval.find_block_at_row(lines, 3)
      assert.equals(1, s)
      assert.equals(4, e)
    end)

    it("ヘッダ行にカーソルがあってもブロック全体を返す", function()
      local lines = {
        "clip drums_main [bars 4] {",
        "\tuse vdrum",
        "}",
      }
      local s, e = eval.find_block_at_row(lines, 1)
      assert.equals(1, s)
      assert.equals(3, e)
    end)

    it("閉じブレース行にカーソルがあってもブロック全体を返す", function()
      local lines = {
        "scene intro {",
        "\tdrums_break",
        "}",
      }
      local s, e = eval.find_block_at_row(lines, 3)
      assert.equals(1, s)
      assert.equals(3, e)
    end)

    it("ネストしたkitブロックでも外側全体を返す", function()
      local lines = {
        "kit vdrum {",
        "\tdevice volca_drum",
        "\tbd { channel 10, note c2 }",
        "\tsd { channel 10, note d2 }",
        "}",
      }
      -- bd { ... } の中
      local s, e = eval.find_block_at_row(lines, 3)
      assert.equals(1, s)
      assert.equals(5, e)
    end)

    it("device/instrument/session ブロックも検出する", function()
      for _, kw in ipairs({ "device", "instrument", "session" }) do
        local lines = {
          kw .. " foo {",
          "\tbody",
          "}",
        }
        local s, e = eval.find_block_at_row(lines, 2)
        assert.equals(1, s, kw)
        assert.equals(3, e, kw)
      end
    end)

    it("トップレベル単独行 (tempo) はその1行を返す", function()
      local lines = {
        "tempo 130",
        "scale c minor",
      }
      local s, e = eval.find_block_at_row(lines, 1)
      assert.equals(1, s)
      assert.equals(1, e)
    end)

    it("トップレベル単独行 (scale) はその1行を返す", function()
      local lines = {
        "tempo 130",
        "scale c minor",
      }
      local s, e = eval.find_block_at_row(lines, 2)
      assert.equals(2, s)
      assert.equals(2, e)
    end)

    it("トップレベル単独行 (include / play / stop) も検出する", function()
      local lines = {
        "include ./drums.cvg",
        "play intro",
        "stop bass_main",
      }
      for row = 1, 3 do
        local s, e = eval.find_block_at_row(lines, row)
        assert.equals(row, s)
        assert.equals(row, e)
      end
    end)

    it("空行や認識されない行は nil を返す", function()
      local lines = {
        "",
        "// comment",
        "tempo 130",
        "garbage line",
      }
      assert.is_nil(eval.find_block_at_row(lines, 1))
      assert.is_nil(eval.find_block_at_row(lines, 2))
      assert.equals(3, (eval.find_block_at_row(lines, 3)))
      assert.is_nil(eval.find_block_at_row(lines, 4))
    end)

    it("コメント中の { } は無視する", function()
      local lines = {
        "clip foo [bars 4] {",
        "\t// stray } in comment",
        "\tuse vdrum",
        "}",
      }
      local s, e = eval.find_block_at_row(lines, 3)
      assert.equals(1, s)
      assert.equals(4, e)
    end)

    it("ブロック内のtempoはトップレベルでなく外側ブロックを返す", function()
      local lines = {
        "scene buildup {",
        "\tdrums_main",
        "\ttempo +2",
        "}",
      }
      local s, e = eval.find_block_at_row(lines, 3)
      assert.equals(1, s)
      assert.equals(4, e)
    end)

    it("複数ブロックが連続している場合、カーソルを含む方を返す", function()
      local lines = {
        "clip a [bars 4] {",
        "\tuse vdrum",
        "}",
        "clip b [bars 4] {",
        "\tuse vdrum",
        "}",
      }
      local s1, e1 = eval.find_block_at_row(lines, 2)
      assert.equals(1, s1)
      assert.equals(3, e1)
      local s2, e2 = eval.find_block_at_row(lines, 5)
      assert.equals(4, s2)
      assert.equals(6, e2)
    end)

    it("ブロック間の空行は nil を返す", function()
      local lines = {
        "clip a [bars 4] {",
        "}",
        "",
        "clip b [bars 4] {",
        "}",
      }
      assert.is_nil(eval.find_block_at_row(lines, 3))
    end)
  end)

  describe("strip_playback_controls", function()
    it("トップレベルの play 行を除外する", function()
      local lines = { "tempo 120", "play verse", "scale c minor" }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "tempo 120", "scale c minor" }, result)
    end)

    it("トップレベルの stop 行を除外する", function()
      local lines = { "tempo 120", "stop", "scale c minor" }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "tempo 120", "scale c minor" }, result)
    end)

    it("引数付きの play / stop 行も除外する", function()
      local lines = {
        "play session my_song [repeat 2]",
        "stop verse",
        "tempo 120",
      }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "tempo 120" }, result)
    end)

    it("コメント行の play / stop は除外しない", function()
      local lines = {
        "// play verse",
        "// stop",
        "tempo 120",
      }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "// play verse", "// stop", "tempo 120" }, result)
    end)

    it("インデントされた play / stop（ブロック内）は除外しない", function()
      local lines = {
        "scene verse {",
        "\tplay drums_a",
        "\tstop bass_a",
        "}",
      }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "scene verse {", "\tplay drums_a", "\tstop bass_a", "}" }, result)
    end)

    it("play / stop で始まる別の語（playback 等）は除外しない", function()
      local lines = { "playback_mode on", "stopwatch 1", "tempo 120" }
      local result = eval.strip_playback_controls(lines)
      assert.same({ "playback_mode on", "stopwatch 1", "tempo 120" }, result)
    end)

    it("元のテーブルを破壊しない", function()
      local lines = { "play verse", "tempo 120" }
      eval.strip_playback_controls(lines)
      assert.equals(2, #lines)
      assert.equals("play verse", lines[1])
    end)
  end)

  describe("eval_definitions", function()
    it("include 展開し play/stop を除いて eval 送信する", function()
      -- バッファ内容をモック
      local buf_lines = {
        "tempo 120",
        "scene verse {",
        "\tdrums_a",
        "}",
        "play verse",
        "stop",
      }
      vim.api.nvim_buf_get_name = function() return "/mock/main.cvg" end
      vim.api.nvim_buf_line_count = function() return #buf_lines end
      vim.api.nvim_buf_get_lines = function() return buf_lines end

      eval.eval_definitions()

      assert.equals(1, #sent_messages)
      assert.equals("eval", sent_messages[1].type)
      -- play / stop は除外され、定義のみ送信される
      local expected = table.concat({
        "tempo 120",
        "scene verse {",
        "\tdrums_a",
        "}",
      }, "\n")
      assert.equals(expected, sent_messages[1].source)
    end)
  end)
end)
