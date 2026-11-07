describe("lcvgc.scale", function()
  local scale

  before_each(function()
    scale = reload_module("lcvgc.scale")
  end)

  describe("parse_token", function()
    it("c_major を root=c, type=major に分割する", function()
      assert.same({ root = "c", type = "major" }, scale.parse_token("c_major"))
    end)

    it("s 形式のシャープ cs_minor を分割する", function()
      assert.same({ root = "cs", type = "minor" }, scale.parse_token("cs_minor"))
    end)

    it("# 形式のシャープ c#_minor を分割する", function()
      assert.same({ root = "c#", type = "minor" }, scale.parse_token("c#_minor"))
    end)

    it("種別に _ を含む eb_harmonic_minor は最初の _ で分割する", function()
      assert.same({ root = "eb", type = "harmonic_minor" }, scale.parse_token("eb_harmonic_minor"))
    end)

    it("_ の無いトークン（旧形式のルート音のみ）は nil", function()
      assert.is_nil(scale.parse_token("c"))
    end)

    it("未知の種別は nil", function()
      assert.is_nil(scale.parse_token("c_foo"))
    end)

    it("不正なルート音は nil", function()
      assert.is_nil(scale.parse_token("h_major"))
    end)
  end)

  describe("from_clip_header", function()
    it("[scale c_major] を読み取る", function()
      assert.same({ root = "c", type = "major" },
        scale.from_clip_header("clip bass_a [bars 1] [scale c_major] {"))
    end)

    it("[scale cs_minor] を読み取る", function()
      assert.same({ root = "cs", type = "minor" },
        scale.from_clip_header("clip x [scale cs_minor] {"))
    end)

    it("[scale c#_minor] を読み取る", function()
      assert.same({ root = "c#", type = "minor" },
        scale.from_clip_header("clip x [scale c#_minor] {"))
    end)

    it("[scale eb_harmonic_minor] を読み取る", function()
      assert.same({ root = "eb", type = "harmonic_minor" },
        scale.from_clip_header("clip x [scale eb_harmonic_minor] {"))
    end)

    it("旧形式 [scale c major] は受け付けない", function()
      assert.is_nil(scale.from_clip_header("clip x [scale c major] {"))
    end)

    it("scale 指定の無い行は nil", function()
      assert.is_nil(scale.from_clip_header("clip x [bars 1] {"))
    end)
  end)

  describe("from_global_line", function()
    it("scale c_major を読み取る", function()
      assert.same({ root = "c", type = "major" }, scale.from_global_line("scale c_major"))
    end)

    it("scale cs_minor を読み取る", function()
      assert.same({ root = "cs", type = "minor" }, scale.from_global_line("scale cs_minor"))
    end)

    it("scale c#_minor を読み取る", function()
      assert.same({ root = "c#", type = "minor" }, scale.from_global_line("scale c#_minor"))
    end)

    it("scale eb_harmonic_minor を読み取る（前後の空白・行末コメント許容）", function()
      assert.same({ root = "eb", type = "harmonic_minor" },
        scale.from_global_line("  scale eb_harmonic_minor  // key"))
    end)

    it("旧形式 scale c major は受け付けない", function()
      assert.is_nil(scale.from_global_line("scale c major"))
    end)

    it("scale 以外の行は nil", function()
      assert.is_nil(scale.from_global_line("tempo 120"))
    end)
  end)
end)
