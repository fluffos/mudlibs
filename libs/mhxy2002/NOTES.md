# mhxy2002 — `git clone https://github.com/mudchina/mhxy2002` → duplicate of `mhxyqd`

- Source: `git clone https://github.com/mudchina/mhxy2002` (single commit
  `3be0856` "add github repo for mhxy2002", authored 2016-02-20; ~113MB
  clone incl. `.git`, 14,563 tracked files under `world/`). Pre-assigned
  identifiers for this entry: number **170**, slug `mhxy2002`, port
  **40218** (reserved but unused — see below).

## Duplicate check (done BEFORE any conversion work, per AGENTS.md §2.1)

This project already has two mhxy-named libs: `mhxy` (#012, archive
`mhxy.rar`, "梦幻西游" 青岛站-branded-at-runtime-differently) and
`mhxyqd` (#012-1, archive `梦幻西游2002版.rar` — note the archive's own
Chinese name literally translates to "Fantasy Westward Journey, 2002
Edition", i.e. the same title as this GitHub repo). Per AGENTS.md's
repeated lesson that similar titles are not proof of lineage either
way, this was verified by diff, not assumed:

1. **File tree structure**: `mhxy2002`'s `world/` (root of the mudlib —
   no nested Chinese-named wrapper directory this time, config lives at
   `config.mhxy` next to `world/`) has exactly 14,563 files, and its
   path listing is byte-for-byte identical (`diff` of sorted `find`
   output = empty) to both `mhxy`'s raw tree
   (`梦幻西游2002版/mhxy/world/`) and `mhxyqd`'s raw tree
   (`mhxy/world/`).
2. **Content vs. `mhxy` (#012)**: md5sum of every file, joined on path
   — only 2 differences out of 14,563 files: `adm/daemons/logind.c`
   (this repo has the same "(青岛站)" branding string in the banner as
   `mhxyqd` does, `mhxy` doesn't) and `adm/etc/wizlist` (site-specific
   wizard roster). Same exact 2-file diff shape already documented in
   `mhxyqd`'s own NOTES.md when it was compared against `mhxy`.
3. **Content vs. `mhxyqd` (#012-1)**: md5sum of every file, joined on
   path — **zero differences**. All 14,563 files match hash-for-hash,
   including `adm/daemons/logind.c` (identical "(青岛站)" banner
   string), `adm/etc/wizlist` (identical wizard roster — same accounts,
   same rank markers), and the top-level `config.mhxy` (`diff` exit 0).
   The two specific files AGENTS.md calls out to check
   (`adm/obj/master.c`, `adm/simul_efun/chinese.c`) are of course
   included in that zero-diff result.

**Conclusion: `mhxy2002` is a byte-for-byte identical duplicate of
`mhxyqd`**, not merely the same lineage — this GitHub repo is a
straight re-upload of the exact same 2002 snapshot already preserved
here as archive `梦幻西游2002版.rar`, down to the runtime `wizlist`
state. This is a cleaner/stronger duplicate match than the earlier
`mhxy` vs. `mhxyqd` comparison (which at least differed in the banner
branding string) — here literally every byte matches.

## Disposition

Per this project's standing convention for confirmed duplicates
(`duplicate_of` in `meta.json`, e.g. `zcjh271yb`/`sgwcxz`/`zcjh` for the
重出江湖/atlantis families, `xxcqii2`→`xxcqii`, `moniHuafu`→`mnhf`) and
per `scripts/gen_site_index.py`'s own documented behavior ("Duplicate-
archive entries (`duplicate_of` set) never own a libs/ dir" for site
purposes — they're skipped from the generated site entirely), this
entry is recorded as metadata only:

- **No independent `work/`, `config.fluffos`, or boot/play test was
  produced.** Reproducing the full GBK→UTF-8 conversion, driver-compat
  fixes, and boot verification here would exactly reproduce `mhxyqd`'s
  already-committed `work/` tree byte-for-byte (same source, same
  fixes would apply identically) — zero new information, pure
  duplicated effort. The `raw/` clone is kept for provenance only
  (gitignored, like every other lib's `raw/`).
- **The live, playable instance for this codebase is `mhxyqd`**
  (port 40050, https://mudlibs.fluffos.info/mhxyqd/, admin account
  `fluffos` / `Mud@2026`). Its `NOTES.md` documents the full fix
  catalog that applies equally to this source: standard GB18030→UTF-8
  conversion + `.c`→`.lpc` rename, the `convertd.lpc` Greek-table
  stray-backslash CRLF fix, AGENTS.md §15h's GBK-byte-range→CJK-
  Unicode-range fix for `is_chinese()`/`check_legal_name()`, and the
  later corpus-wide sweeps (formatter pass, WASM re-verification) that
  also landed on `mhxy`/`mhxyqd`.
- **Port 40218** was pre-assigned to this entry (checked against the
  whole collection to avoid collisions) but is left unused in
  `config.fluffos`-space since no driver instance runs under this slug;
  recorded here so the reservation is documented and the port isn't
  accidentally handed to a future, genuinely-distinct lib.
- `wasm_status` is left `""` (not `"playable"`) since no WASM pack/boot
  test was run under this slug specifically — the WASM-playable
  instance is `mhxyqd`'s.

## If a future pass wants an independent build anyway

Nothing above is destructive — `raw/` is present and untouched, so a
future agent could still run the full §2 pipeline here if there's ever
a reason to want two independently-built copies (e.g. testing a fix in
isolation before porting it to `mhxyqd`). Given the confirmed byte-
identical source, the expectation is that it would reproduce `mhxyqd`'s
`work/` tree and fix list exactly.
