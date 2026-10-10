--- scale 指定（`<root>_<type>` 単一トークン）の読み取りモジュール
--- Parser for scale specifications written as a single `<root>_<type>` token.
---
--- 例 / Examples: `scale c_major`, `[scale cs_minor]`, `scale eb_harmonic_minor`
--- 旧形式（`scale c major`）は受け付けない。
--- The legacy two-word form (`scale c major`) is rejected.
local M = {}

--- 受け付けるスケール種別の集合
--- Set of accepted scale types
--- @type table<string, boolean>
M.SCALE_TYPES = {
  major = true,
  minor = true,
  harmonic_minor = true,
  melodic_minor = true,
  dorian = true,
  phrygian = true,
  lydian = true,
  mixolydian = true,
  locrian = true,
}

--- ルート音が音名として妥当か判定する（c, cs, c#, db 等）
--- Check whether the root is a valid pitch name (c, cs, c#, db, ...).
--- @param root string ルート音 / root note
--- @return boolean 妥当なら true / true if valid
local function is_valid_root(root)
  return root:match('^[a-g][#bs]?$') ~= nil
end

--- `<root>_<type>` トークンを分解する。ルート音は `_` を含まないため最初の `_` で分割する
--- Split a `<root>_<type>` token at the first `_` (roots never contain `_`).
--- @param token string scale トークン（例: "cs_minor"）/ scale token
--- @return table|nil { root = string, type = string }。不正な場合は nil / nil if invalid
function M.parse_token(token)
  local root, scale_type = token:match('^([^_%s]+)_(%S+)$')
  if not root or not is_valid_root(root) or not M.SCALE_TYPES[scale_type] then
    return nil
  end
  return { root = root, type = scale_type }
end

--- clip ヘッダ行から `[scale <root>_<type>]` を読み取る
--- Read `[scale <root>_<type>]` from a clip header line.
--- @param line string 行文字列 / line text
--- @return table|nil { root, type }。見つからない場合は nil / nil if absent
function M.from_clip_header(line)
  local token = line:match('%[scale%s+(%S+)%]')
  if not token then
    return nil
  end
  return M.parse_token(token)
end

--- グローバル `scale <root>_<type>` 行を読み取る（行末コメント `//` を許容）
--- Read a global `scale <root>_<type>` line (trailing `//` comment allowed).
--- @param line string 行文字列 / line text
--- @return table|nil { root, type }。該当しない場合は nil / nil if not a scale line
function M.from_global_line(line)
  local token, rest = line:match('^%s*scale%s+(%S+)(.*)$')
  if not token then
    return nil
  end
  if not (rest:match('^%s*$') or rest:match('^%s+//')) then
    return nil
  end
  return M.parse_token(token)
end

return M
