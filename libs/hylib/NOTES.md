# hylib — `git clone https://github.com/MudRen/HYLib` → duplicate of `haiyang2`

- Source: `git clone https://github.com/MudRen/HYLib` (commit
  `dd7832c`, "Update README.md", authored 2018-12-03; ~172MB clone,
  29,716 tracked files). Identified via a research pass checking
  MudRen's other public repos for overlap with libs already in this
  collection, given `es2`, `finalrealms`, etc. all traced back to the
  same account/org.

## Duplicate check (done before any conversion work, per AGENTS.md §2.1)

The repo's own `README.md` literally identifies itself as "海洋II
MUD" (Ocean/Haiyang II) — the same title already preserved here as
`haiyang2` ("海洋II 2010 正式无错完整版下载", Ocean II / Star and Moon
Legend, ES II engine family). Verified by structure, not name alone:
the domain directory listing (141 entries — `annan`, `baituo`,
`beihai`, `wudang`, `emei`, `kunlun`, and so on) is byte-for-byte
identical, in the same order, to `haiyang2`'s own domain list. This is
the same "same title, same domain-list fingerprint" signal this
project has used to confirm duplicates elsewhere (e.g. `mhxy2002` vs.
`mhxyqd`).

## Disposition

Per this project's standing convention for confirmed duplicates
(`duplicate_of` in `meta.json`; duplicate-archive entries never own a
live `libs/` build and are skipped from the generated site by
`scripts/gen_site_index.py`), this entry is recorded as metadata only.

- **No independent `work/`, `config.fluffos`, or boot test was
  produced** — reproducing the conversion here would exactly duplicate
  `haiyang2`'s already-committed `work/` tree, zero new information.
- **The live, playable instance for this codebase is `haiyang2`**
  (port 40057, https://mudlibs.fluffos.info/haiyang2/). Its own
  NOTES.md documents the full ES II family fix catalog that applies
  equally to this source.
- `port` and `wasm_status` are left `""` — no driver instance runs
  under this slug.
