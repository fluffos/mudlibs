# dtxy — `git clone https://github.com/MudRen/dtxy` → duplicate of `dtxywzxzb`

- Source: `git clone https://github.com/MudRen/dtxy` (commit
  `6d3c609`, "修BUG无数个", authored 2021-06-18; ~101MB clone, 13,598
  tracked files). Identified via the same MudRen-org overlap check
  that surfaced `hylib`.

## Duplicate check (done before any conversion work, per AGENTS.md §2.1)

"大唐西游" (Great Tang Journey to the West) is an artificial-human/NPC-
themed Journey to the West lineage MUD, matching the codebase already
preserved here as `dtxywzxzb` ("大唐西游完整修正版"). Verified by
structure: the domain directory list (`12gong`, `33tian`, `changan`,
`emei`, `kunlun`, `shushan`, ...) is essentially identical to
`dtxywzxzb`'s, differing only by one extra stray file and one extra
domain directory — consistent with this being an earlier or
independently-drifted snapshot of the same base codebase rather than a
distinct game.

## Disposition

Per this project's standing convention for confirmed duplicates
(`duplicate_of` in `meta.json`; duplicate-archive entries never own a
live `libs/` build and are skipped from the generated site by
`scripts/gen_site_index.py`), this entry is recorded as metadata only.

- **No independent `work/`, `config.fluffos`, or boot test was
  produced** — reproducing the conversion here would almost entirely
  duplicate `dtxywzxzb`'s already-committed `work/` tree.
- **The live, playable instance for this codebase is `dtxywzxzb`**
  (port 40150, https://mudlibs.fluffos.info/dtxywzxzb/). Its own
  NOTES.md/README.md document the full fix catalog and registration
  flow that applies equally to this source.
- `port` and `wasm_status` are left `""` — no driver instance runs
  under this slug.
- The one extra domain directory and one extra stray file present here
  but not in `dtxywzxzb` were not investigated further (this is a
  metadata-only entry) — if a future pass ever wants to check whether
  that extra content is worth merging into `dtxywzxzb`, the clone is
  still available at `/tmp/mudren_check/dtxy` on this machine as of
  2026-08-26 (not committed to this repo).
