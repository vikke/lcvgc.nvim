describe("lcvgc.midi_in", function()
  local midi_in
  local connection
  local put_calls
  local select_calls

  before_each(function()
    clear_notifications()
    connection = reload_module("lcvgc.connection")
    midi_in = reload_module("lcvgc.midi_in")

    put_calls = {}
    vim.api.nvim_put = function(lines, type_, after, follow)
      table.insert(put_calls, { lines = lines, type = type_, after = after, follow = follow })
    end

    select_calls = {}
    vim.ui.select = function(items, opts, on_choice)
      table.insert(select_calls, { items = items, opts = opts, on_choice = on_choice })
    end
  end)

  describe("_on_midi_in_event", function()
    it("dsl をスペース付きでカーソル位置に挿入する", function()
      midi_in._on_midi_in_event({ type = "midi_in_event", dsl = "c:4", note = 60 })
      assert.equals(1, #put_calls)
      assert.same({ "c:4 " }, put_calls[1].lines)
      assert.equals("c", put_calls[1].type)
    end)

    it("dsl が無いイベントは挿入しない", function()
      midi_in._on_midi_in_event({ type = "midi_in_event", note = 60 })
      assert.equals(0, #put_calls)
    end)

    it("dsl が空文字なら挿入しない", function()
      midi_in._on_midi_in_event({ type = "midi_in_event", dsl = "" })
      assert.equals(0, #put_calls)
    end)

    it("複数イベントを順に挿入してトークンが並ぶ", function()
      midi_in._on_midi_in_event({ dsl = "c:4" })
      midi_in._on_midi_in_event({ dsl = "e:4" })
      midi_in._on_midi_in_event({ dsl = "g:4" })
      assert.equals(3, #put_calls)
      assert.same({ "c:4 " }, put_calls[1].lines)
      assert.same({ "e:4 " }, put_calls[2].lines)
      assert.same({ "g:4 " }, put_calls[3].lines)
    end)
  end)

  describe("subscribe", function()
    before_each(function()
      vim.fn.sockconnect = function() return 42 end
      connection.connect(5555, function() end)
      clear_notifications()
    end)

    after_each(function()
      vim.fn.sockconnect = function() return 0 end
    end)

    it("subscribe_midi_in をポート名付きで送信する", function()
      local sent = {}
      local orig = connection.send
      connection.send = function(p) table.insert(sent, p); return orig(p) end

      midi_in.subscribe("Launchkey")
      assert.equals(1, #sent)
      assert.equals("subscribe_midi_in", sent[1].type)
      assert.equals("Launchkey", sent[1].port)

      connection.send = orig
    end)

    it("成功応答で購読状態になり INFO 通知する", function()
      midi_in.subscribe("Launchkey")
      connection._on_data({ '{"success":true,"message":"subscribed: Launchkey"}\n' })

      assert.is_true(midi_in.is_subscribed())
      assert.equals("Launchkey", midi_in._subscribed_port)

      local found = false
      for _, n in ipairs(vim._notifications) do
        if n.level == vim.log.levels.INFO then found = true end
      end
      assert.is_true(found)
    end)

    it("失敗応答では購読状態にならずエラー通知する", function()
      midi_in.subscribe("Bad")
      connection._on_data({ '{"success":false,"error":"no such port"}\n' })

      assert.is_false(midi_in.is_subscribed())

      local found = false
      for _, n in ipairs(vim._notifications) do
        if n.level == vim.log.levels.ERROR then found = true end
      end
      assert.is_true(found)
    end)

    it("ポート名が空なら警告して送信しない", function()
      local sent = {}
      local orig = connection.send
      connection.send = function(p) table.insert(sent, p); return orig(p) end

      midi_in.subscribe("")
      assert.equals(0, #sent)
      assert.equals(vim.log.levels.WARN, vim._notifications[#vim._notifications].level)

      connection.send = orig
    end)
  end)

  describe("unsubscribe", function()
    before_each(function()
      vim.fn.sockconnect = function() return 42 end
      connection.connect(5555, function() end)
      midi_in._subscribed_port = "Launchkey"
      clear_notifications()
    end)

    after_each(function()
      vim.fn.sockconnect = function() return 0 end
    end)

    it("unsubscribe_midi_in を送信する", function()
      local sent = {}
      local orig = connection.send
      connection.send = function(p) table.insert(sent, p); return orig(p) end

      midi_in.unsubscribe()
      assert.equals(1, #sent)
      assert.equals("unsubscribe_midi_in", sent[1].type)

      connection.send = orig
    end)

    it("応答で購読解除状態になる", function()
      midi_in.unsubscribe()
      connection._on_data({ '{"success":true,"message":"unsubscribed"}\n' })
      assert.is_false(midi_in.is_subscribed())
    end)
  end)

  describe("toggle", function()
    before_each(function()
      vim.fn.sockconnect = function() return 42 end
      connection.connect(5555, function() end)
      clear_notifications()
    end)

    after_each(function()
      vim.fn.sockconnect = function() return 0 end
    end)

    it("未購読なら入力ポート選択フローを起動する", function()
      midi_in.toggle()
      -- fetch -> list_ports リクエストへの応答を流す
      connection._on_data({ '{"ports":[{"name":"Launchkey","direction":"in"},{"name":"IAC","direction":"out"}]}\n' })

      assert.equals(1, #select_calls)
      assert.same({ "Launchkey" }, select_calls[1].items)
    end)

    it("選択したポートで購読する", function()
      midi_in.toggle()
      connection._on_data({ '{"ports":[{"name":"Launchkey","direction":"in"}]}\n' })

      local sent = {}
      local orig = connection.send
      connection.send = function(p) table.insert(sent, p); return orig(p) end

      -- vim.ui.select のコールバックを実行
      select_calls[1].on_choice("Launchkey")
      assert.equals("subscribe_midi_in", sent[1].type)
      assert.equals("Launchkey", sent[1].port)

      connection.send = orig
    end)

    it("購読中なら解除する", function()
      midi_in._subscribed_port = "Launchkey"
      local sent = {}
      local orig = connection.send
      connection.send = function(p) table.insert(sent, p); return orig(p) end

      midi_in.toggle()
      assert.equals("unsubscribe_midi_in", sent[1].type)

      connection.send = orig
    end)
  end)
end)
