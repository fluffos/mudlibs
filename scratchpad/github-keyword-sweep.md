# GitHub keyword paging (2026-09-04)

User asked to page similar keywords to the completed `q=Mudos` search (179 repos), using subagents slowly to avoid 429.

## Method

- Source of truth: `gh api search/repositories` at 100/page, not `github.com/search` HTML.
- Search API budget: 30 req/min shared. Agents staggered (8s / 28s / 55s / 90s) with 4–5s between pages.
- Known remotes + prior Mudos list: `/tmp/gh-keyword-search/`

## Queries

Already done this session: `Mudos` (179). Case-insensitive; do not redo `mudos` / `MudOS`.

Skipped: bare `mud` (~41370 repos — not a mudlib query). Bare `nitan` (~267, mostly people).

| Agent | Queries | Out dir | Status |
|---|---|---|---|
| fluffos | `fluffos` (~99) | `/tmp/gh-keyword-search/fluffos/` | **done** 99/99, no 429. 4 new LPC (queued below). |
| mudlib | `mudlib` (~112) | `/tmp/gh-keyword-search/mudlib/` | in flight |
| lpmud-family | `lpmud`, `lpc mudlib`, `mudos lib`, `dead souls mud`, `mudos-game`, `lpc mud` (cap 100), `lp-mud` (cap 100) | `/tmp/gh-keyword-search/lpmud-family/` | in flight |
| topics-mudren | `topic:mudos`, `topic:fluffos`, `topic:lpmud`, `topic:mudlib`, `MudRen`, `fluffos mudlib`, `nitan mud` | `/tmp/gh-keyword-search/topics-mudren/` | in flight |

## Already queued

1. `gllort/mud` (Mundo Oscuro) — from q=Mudos. Next onboard.
2. `oiuv/mud` — 炎黃群俠傳 (yh2003 + MudCore). Not `yanhuangwuhun`; not `oiuv/mudcore` (that is immaster's engine).
3. `ly19811105/pkuxkx-utf8` — 北大侠客行. No `pkuxkx` slug.
4. `fluffos/xkx100` — GitHub 侠客行100 UTF-8. Collection `xkx100` NOTES already say the Coollizard/yoyo.xm.fj.cn tree is a different codebase that only shares the name. `MudRen/xkx100` is the MudCore wrap of this same GitHub tree — do not onboard twice.
5. `Nuiio/fluffos-xiuxian-mud` — small original 修仙 lib (`mymud/single/{master,login,simul_efun}.c`).

## On merge

Dedup new_lpc_mudlib across the four `classified.json` files against known remotes and `/tmp/mudos-search/classified.json`. Append only genuine new LPC libs to `scratchpad/librarian-next.txt` after `gllort/mud`.
