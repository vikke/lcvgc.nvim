describe("lcvgc.flash", function()
  local flash
  local extmark_calls
  local clear_ns_calls

  before_each(function()
    clear_notifications()
    extmark_calls = {}
    clear_ns_calls = {}

    -- extmark 呼び出し記録
    vim.api.nvim_buf_set_extmark = function(bufnr, ns, row, col, opts)
      table.insert(extmark_calls, {
        bufnr = bufnr,
        ns = ns,
        row = row,
        col = col,
        opts = opts,
      })
      return 1
    end

    -- clear_namespace 呼び出し記録
    vim.api.nvim_buf_clear_namespace = function(bufnr, ns, start, stop)
      table.insert(clear_ns_calls, {
        bufnr = bufnr,
        ns = ns,
        start = start,
        stop = stop,
      })
    end

    -- バッファは常に有効
    vim.api.nvim_buf_is_valid = function() return true end

    -- lcvgc.opts モック (flash_duration のデフォルト)
    package.loaded["lcvgc"] = { opts = { flash_duration = 300 } }

    flash = reload_module("lcvgc.flash")
  end)

  describe("flash_range", function()
    it("extmark でフラッシュハイライトを設定する", function()
      flash.flash_range(1, 3, 7)

      -- extmark が1つ設定される
      assert.equals(1, #extmark_calls)
      local call = extmark_calls[1]
      assert.equals(1, call.bufnr)
      -- start_line=3 → 0-indexed で row=2
      assert.equals(2, call.row)
      assert.equals(0, call.col)
      -- end_row は exclusive: end_line=7 → end_row=7
      assert.equals(7, call.opts.end_row)
      assert.equals("LcvgcEvalFlash", call.opts.hl_group)
      assert.is_true(call.opts.hl_eol)
    end)

    it("前回のフラッシュをクリアしてから新しいフラッシュを設定する", function()
      flash.flash_range(1, 1, 5)

      -- clear_namespace は少なくとも1回呼ばれる（設定前のクリア）
      -- defer_fn は即時実行なので、クリア後も呼ばれる
      assert.is_true(#clear_ns_calls >= 1)
      -- 最初のクリアは設定前
      assert.equals(1, clear_ns_calls[1].bufnr)
      assert.equals(0, clear_ns_calls[1].start)
      assert.equals(-1, clear_ns_calls[1].stop)
    end)

    it("defer_fn でタイマー後にクリアされる", function()
      -- defer_fn はモックで即時実行されるため、
      -- extmark 設定後に clear_namespace が呼ばれる
      flash.flash_range(1, 1, 3)

      -- 設定前クリア + タイマー後クリア = 2回
      assert.equals(2, #clear_ns_calls)
    end)

    it("カスタム duration を受け取れる", function()
      local captured_timeout
      vim.defer_fn = function(fn, timeout)
        captured_timeout = timeout
        fn()
      end
      flash = reload_module("lcvgc.flash")

      flash.flash_range(1, 1, 3, 500)
      assert.equals(500, captured_timeout)
    end)

    it("config の flash_duration をデフォルトで使用する", function()
      local captured_timeout
      vim.defer_fn = function(fn, timeout)
        captured_timeout = timeout
        fn()
      end
      package.loaded["lcvgc"] = { opts = { flash_duration = 200 } }
      flash = reload_module("lcvgc.flash")

      flash.flash_range(1, 1, 3)
      assert.equals(200, captured_timeout)
    end)

    it("無効なバッファではタイマー後にクリアしない", function()
      vim.api.nvim_buf_is_valid = function() return false end
      flash = reload_module("lcvgc.flash")
      clear_ns_calls = {}

      flash.flash_range(1, 1, 3)

      -- 設定前クリアのみ（タイマー後はバッファ無効でスキップ）
      assert.equals(1, #clear_ns_calls)
    end)

    it("連続呼び出しで前のフラッシュがクリアされる", function()
      flash.flash_range(1, 1, 3)
      local calls_after_first = #clear_ns_calls

      flash.flash_range(1, 5, 8)
      -- 2回目の呼び出し前にもクリアが呼ばれる
      assert.is_true(#clear_ns_calls > calls_after_first)
    end)
  end)
end)
