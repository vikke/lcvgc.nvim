--- LSP用includeファイル解決モジュール
--- Resolves include files for LSP requests
--- eval.luaとは異なり、テキスト展開はせず、
--- include_sources（パスとソースのペアリスト）と診断情報を返す
local M = {}

local eval = require('lcvgc.eval')

--- includeファイルを再帰的に解決し、include_sourcesと診断を返す
--- Recursively resolves include files and returns include_sources and diagnostics
--- @param source string バッファのソーステキスト
--- @param base_dir string ベースディレクトリのパス
--- @return table include_sources {path: string, source: string}のリスト
--- @return table diagnostics vim.diagnostic形式の診断リスト
function M.resolve_includes(source, base_dir)
  local include_sources = {}
  local diagnostics = {}
  local visited = {}

  -- ソースからinclude行を抽出して処理
  -- Extract and process include lines from source
  local lines = {}
  local line_num = 0
  for line in (source .. '\n'):gmatch('(.-)\n') do
    line_num = line_num + 1
    table.insert(lines, { text = line, num = line_num })
  end
  -- 末尾の空行を除去
  -- Remove trailing empty line
  if #lines > 0 and lines[#lines].text == '' then
    table.remove(lines)
  end

  M._resolve_recursive(lines, base_dir, visited, include_sources, diagnostics)

  return include_sources, diagnostics
end

--- 再帰的にincludeを解決する内部関数
--- Internal function to recursively resolve includes
--- @param lines table {text: string, num: number}のリスト
--- @param base_dir string ベースディレクトリ
--- @param visited table 訪問済みパスのセット（循環検出用）
--- @param include_sources table 結果を蓄積するinclude_sourcesリスト
--- @param diagnostics table 結果を蓄積する診断リスト
function M._resolve_recursive(lines, base_dir, visited, include_sources, diagnostics)
  local include_phase = true

  for _, entry in ipairs(lines) do
    if not include_phase then
      break
    end

    local line = entry.text
    -- include行を検出（eval.luaと同じパターン）
    -- Detect include lines (same pattern as eval.lua)
    local include_path = line:match('^%s*include%s+(.-)%s*$')
    if include_path then
      -- 行末コメントを除去
      -- Remove trailing comment
      include_path = include_path:match('^(.-)%s*//') or include_path
      -- 前後の空白をトリム
      -- Trim whitespace
      include_path = include_path:match('^%s*(.-)%s*$')
      if include_path == '' then
        include_path = nil
      end
    end

    if include_path then
      local full_path = base_dir .. '/' .. include_path
      -- パスの正規化
      -- Normalize path
      local normalized = vim.fn.fnamemodify(full_path, ':p')

      if visited[normalized] then
        -- 循環include: スキップ（診断は出さない、eval.luaと同じ挙動）
        -- Circular include: skip without diagnostic (same as eval.lua)
      else
        visited[normalized] = true

        -- ファイル読み込み
        -- Read file
        local inc_lines, err = eval.read_file(full_path)
        if not inc_lines then
          -- ファイル未検出診断を追加
          -- Add file-not-found diagnostic
          table.insert(diagnostics, {
            lnum = entry.num - 1, -- 0始まり / 0-based
            col = 0,
            end_lnum = entry.num - 1,
            end_col = #line,
            message = "インクルードファイル未検出: '" .. include_path .. "'",
            severity = vim.diagnostic.severity.WARN,
            source = 'lcvgc',
          })
        else
          -- include_sourcesに追加
          -- Add to include_sources
          local content = table.concat(inc_lines, '\n')
          table.insert(include_sources, {
            path = include_path,
            source = content,
          })

          -- include先のincludeも再帰的に解決
          -- Recursively resolve includes in included file
          local child_lines = {}
          for j, l in ipairs(inc_lines) do
            table.insert(child_lines, { text = l, num = j })
          end
          local inc_dir = full_path:match('(.+)/') or base_dir
          M._resolve_recursive(child_lines, inc_dir, visited, include_sources, diagnostics)
        end
      end
    elseif line:match('^%s*//') or line:match('^%s*$') then
      -- コメント行・空行はスキップしてincludeフェーズを継続
      -- Skip comment lines and blank lines, continue include phase
    else
      -- 非include・非コメント・非空行が出現したらincludeフェーズ終了
      -- End include phase when non-include, non-comment, non-blank line appears
      include_phase = false
    end
  end
end

return M
