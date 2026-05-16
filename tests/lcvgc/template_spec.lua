describe("lcvgc.template", function()
  local template

  before_each(function()
    package.loaded["lcvgc.template"] = nil
    template = require("lcvgc.template")
  end)

  describe("is_ja", function()
    local orig_lang

    before_each(function()
      orig_lang = os.getenv("LANG")
    end)

    -- NOTE: os.getenvは直接設定できないため、内部関数を差し替えてテスト
    it("LANG=ja_JP.UTF-8 のとき true を返す", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      assert.is_true(template.is_ja())
    end)

    it("LANG=ja のとき true を返す", function()
      template._get_lang = function() return "ja" end
      assert.is_true(template.is_ja())
    end)

    it("LANG=en_US.UTF-8 のとき false を返す", function()
      template._get_lang = function() return "en_US.UTF-8" end
      assert.is_false(template.is_ja())
    end)

    it("LANG=nil のとき false を返す", function()
      template._get_lang = function() return nil end
      assert.is_false(template.is_ja())
    end)
  end)

  describe("get_lines", function()
    it("テーブルを返す", function()
      local lines = template.get_lines()
      assert.is_table(lines)
      assert.is_true(#lines > 0)
    end)

    it("日本語テンプレートに主要キーワードが含まれる", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- DSLの全主要キーワードが含まれることを検証
      local keywords = {
        "device", "instrument", "kit", "clip", "scene",
        "session", "play", "stop", "tempo", "scale", "include",
      }
      for _, kw in ipairs(keywords) do
        assert.is_truthy(
          text:find(kw),
          "キーワード '" .. kw .. "' がテンプレートに含まれていません"
        )
      end
    end)

    it("英語テンプレートに主要キーワードが含まれる", function()
      template._get_lang = function() return "en_US.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      local keywords = {
        "device", "instrument", "kit", "clip", "scene",
        "session", "play", "stop", "tempo", "scale", "include",
      }
      for _, kw in ipairs(keywords) do
        assert.is_truthy(
          text:find(kw),
          "Keyword '" .. kw .. "' is missing from template"
        )
      end
    end)

    it("日本語テンプレートにコメント記法が含まれる", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- 行コメントとブロックコメント
      assert.is_truthy(text:find("//"), "行コメント '//' が含まれていません")
      assert.is_truthy(text:find("/%*"), "ブロックコメント '/*' が含まれていません")
      assert.is_truthy(text:find("%*/"), "ブロックコメント '*/' が含まれていません")
    end)

    it("英語テンプレートにコメント記法が含まれる", function()
      template._get_lang = function() return "en_US.UTF-8" end
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      assert.is_truthy(text:find("//"), "Line comment '//' missing")
      assert.is_truthy(text:find("/%*"), "Block comment '/*' missing")
      assert.is_truthy(text:find("%*/"), "Block comment '*/' missing")
    end)

    it("テンプレートにmelody要素が含まれる", function()
      local lines = template.get_lines()
      local text = table.concat(lines, "\n")

      -- melody記法の要素
      assert.is_truthy(text:find("resolution"), "resolution が含まれていません")
      assert.is_truthy(text:find("use "), "'use' が含まれていません")
      assert.is_truthy(text:find("bars"), "'bars' が含まれていません")
    end)

    -- インデントはタブを使う (lcvgc 全体の慣習)。スペースインデント
    -- (`  port`, `    channel`) はテンプレートに含まれてはならない。
    -- Indentation must be tabs (matches the lcvgc convention). Space
    -- indentation (`  port`, `    channel`) must not appear in the template.
    it("日本語テンプレートはタブでインデントされている", function()
      template._get_lang = function() return "ja_JP.UTF-8" end
      local lines = template.get_lines()

      -- ブロック内の行 (例: `port IAC Driver`, `device my_synth`, `channel 1`)
      -- が `\t` から始まり、スペース 2 個から始まる行が無いことを確認する。
      local has_tab_indented = false
      for _, line in ipairs(lines) do
        if line:sub(1, 1) == "\t" then
          has_tab_indented = true
        end
        -- スペース 2 個から始まる行は禁止 (= 旧インデント)
        assert.is_falsy(
          line:match("^  [^ ]"),
          "スペース 2 個のインデントが残っている: '" .. line .. "'"
        )
      end
      assert.is_true(has_tab_indented, "タブインデント行が 1 つも無い")
    end)

    it("英語テンプレートはタブでインデントされている", function()
      template._get_lang = function() return "en_US.UTF-8" end
      local lines = template.get_lines()

      local has_tab_indented = false
      for _, line in ipairs(lines) do
        if line:sub(1, 1) == "\t" then
          has_tab_indented = true
        end
        assert.is_falsy(
          line:match("^  [^ ]"),
          "2-space indentation found: '" .. line .. "'"
        )
      end
      assert.is_true(has_tab_indented, "no tab-indented line found")
    end)

    -- kit などのネスト 2 段目はタブ 2 個でインデントされている。
    -- Nested-2 indentation must be exactly two tabs.
    it("kit 内のネスト 2 段目はタブ 2 個", function()
      local lines = template.get_lines()
      local found_double_tab = false
      for _, line in ipairs(lines) do
        if line:match("^\t\tchannel") or line:match("^\t\tnote") then
          found_double_tab = true
          break
        end
      end
      assert.is_true(
        found_double_tab,
        "kit 内 (channel / note) のタブ 2 個インデントが見つからない"
      )
    end)
  end)
end)
