# GitHub keyword paging (2026-09-04)

User asked to page similar keywords to the completed `q=Mudos` search (179 repos), using subagents slowly to avoid 429.

## Method

- Source of truth: `gh api search/repositories` at 100/page, not `github.com/search` HTML.
- Search API budget: 30 req/min shared. Agents staggered (8s / 28s / 55s / 90s) with 4–5s between pages.
- No 429/403 on any query.
- Known remotes + prior Mudos list: `/tmp/gh-keyword-search/` (ephemeral)

## Queries (all paged)

Already done earlier this session: `Mudos` (179). Case-insensitive; do not redo `mudos` / `MudOS`.

Skipped: bare `mud` (~41370). Bare `nitan` (~267, mostly people). `MudRen` keyword mostly hit Ukrainian surnames; real MudRen org repos came in via topic queries.

| Query | total | fetched |
|---|---|---|
| fluffos | 99 | 99 |
| mudlib | 112 | 112 |
| lpmud | 65 | 65 |
| lpc mudlib | 22 | 22 |
| mudos lib | 5 | 5 |
| dead souls mud | 9 | 9 |
| mudos-game | 5 | 5 |
| lpc mud | 42 | 42 |
| lp-mud | 20 | 20 |
| topic:mudos | 10 | 10 |
| topic:fluffos | 20 | 20 |
| topic:lpmud | 18 | 18 |
| topic:mudlib | 20 | 20 |
| MudRen | 21 | 21 |
| fluffos mudlib | 22 | 22 |
| nitan mud | 2 | 2 |

Almost everything was already in the collection, a driver, a wrong platform, a false positive, or a repack of a game we have.

## Deduped new FluffOS/MudOS-compatible LPC (onboard queue)

1. `gllort/mud` — Mundo Oscuro (from q=Mudos). **Next onboard.**
2. `ly19811105/pkuxkx-utf8` — 北大侠客行. No `pkuxkx` slug.
3. `fluffos/xkx100` — GitHub 侠客行100 UTF-8. Collection `xkx100` is the Coollizard/yoyo.xm.fj.cn tree; NOTES already say they only share the name. `MudRen/xkx100` is the MudCore wrap of this same GitHub tree — do not onboard twice.
4. `wade-fs/FormosaSaga` — original Taiwan-history LPC lib (`mudlib/master.c`) on a Go MudOS-v22 simulator.
5. `rumplemintz/Nirvlp312mudlib` — full Nirvana LP312 (`secure/master.c` + `simul_efun.c`).
6. `acmemud/acme-mudlib` — Acme mudlib root. `Cloudxtreme/eotl-mudlib` is only a utility fragment.
7. `DoubleIce/Mud_NitanVersions` — complete **nitan4** tree (`name : 泥潭`). Collection has 泥潭三 (`nitan3`/`nitan_san`/`nitan_ceshi`) and nitan6/nitan170911, not IV. Compare to nitan3 before treating as a unique game. Sibling `nitian6/` dir is binaries+SQL only.
8. `Nuiio/fluffos-xiuxian-mud` — small original 修仙 lib.
9. `rmanis/scratch` — minimal starter by the lil author (`name : Scratch`). After real games.
10. `dzpao/pao-mud` — tiny from-scratch FluffOS learning lib. After real games.
11. `Shea690901/Sagenwelt-Lib` — FluffOS skeleton; `Domains/` empty. Last.

## Same game, not a new onboard

- `oiuv/mud` — zhyx README's recommended 基础无错版. config `name : 炎黃群俠傳`, 71 `d/` domains vs zhyx's 80 and `name : 中华英雄`. Cleaner/smaller base of the same yh2003+MudCore site, not a new unique game. `oiuv/mudcore` remains immaster's engine only.
- `MudRen/xkx100` = `fluffos/xkx100` (MudCore wrap).
- `Shea690901/MorgenGrauen` = older dump of `MorgenGrauen/mg-mudlib`.
- Topic-query MudRen games: `es`, `Myth`, `sgz`, `bxcy`, `ES2-big5` = already es1 / sanjieshenhua / sanguozhi / bixiecanyang / es2.

## LDMud-lineage (found; default drop from onboard queue)

Discovery triage drops LDMud unless someone explicitly wants a `questmud`-style port. First-of-lineage architecture gaps are cataloged in AGENTS.md §7.158.

- `MorgenGrauen/mg-mudlib` — official public MorgenGrauen (20★). Hit in mudlib + lpmud-family + topics.
- `age-of-elements/age-of-elements` — the GitHub tree for the `age-of-elements-master.zip` we do not have as an archive.
- `seikichin/aoh` — Age of Heroes / One Step Beyond.

## On merge

Done 2026-09-04. Queue is `scratchpad/librarian-next.txt`.
