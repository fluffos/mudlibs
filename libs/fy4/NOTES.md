# fy4 — `git clone https://github.com/mudchina/fy4` → duplicate of `fengyun434`

- Source: `git clone https://github.com/mudchina/fy4` (single commit
  `b79d809` "create github repo for fy4", authored 2016-02-21; mudlib
  root is `mudlib/` next to a `bin/` dir holding a Windows `mudos.exe` +
  `config.cfg`, 9,033 tracked files). Pre-assigned identifiers for this
  entry: number **171**, slug `fy4`, port **40218** (reserved but
  unused — see below).

## Duplicate check (done BEFORE any conversion work, per AGENTS.md §2.1)

This project already has a large "fy" (风云) family: `fy2`, `fy330`,
`fy3dz`, `fy3xd`, `fy2005`, `fy2mg`, `fy2qh`, `fengyun434`, and others.
Per AGENTS.md's repeated lesson that a similar name is not proof of
lineage either way, this was checked by diff, not assumed:

1. **Room-directory fingerprint**: `fy4`'s `mudlib/d/` listing (59
   dirs: `baiyun bat bawang biancheng cave chenxiang chuenyu daimiao
   eren eren2 for_martea fugui fy fycycle fywall ghost guanwai guanyin
   huangshan huashan ini jinan laowu libie loulan manglin oldpine
   palace qianfo qianjin qingping quicksand resort shanliu shaolin
   sharen shenshui songshan taiping taishan taoguan taoyuan tieflag
   wanmei wolfmount wudang xinjiang yinghe yingou zangbei zhaoze` plus
   loose files `damage1.c`, `logind.c`, `mazewalker.c`, `npc.c`,
   `tester1.c`, `MOON.doc`, `ski_lst`) is near-identical to
   `fengyun434`'s `work/d/` (same set, `.c`→`.lpc`-renamed there) —
   both far closer to each other than to any other `fy*` sibling
   (`fy2005`'s is a superset with ~15 extra dirs; `fy2`/`fy330`/
   `fy3dz`/`fy3xd`/`fy2mg`/`fy2qh` are all much smaller, ~23-27 dirs).
   `fengyun434`'s own README already documents it as one of several
   "different site/era content branches" on this same core "Fengyun"
   engine, alongside `fy2005` (which self-reports at runtime as
   "风云Ⅳ" too) — so this GitHub repo was checked first against
   `fengyun434` specifically as the most likely exact match.
2. **`fengyun434`'s raw archive contains a literal `fy4` directory**:
   `libs/fengyun434/raw/Fengyun/fy4/` — the original site dump this
   project preserved for `fengyun434` is itself named `fy4`, a strong
   signal before even diffing content.
3. **Full recursive diff**: `diff -rq libs/fy4/raw/mudlib
   libs/fengyun434/raw/Fengyun/fy4` — **zero files differ** among the
   8,932 paths present in both trees (confirmed both by `diff -rq`
   reporting no "differ" lines and by every compared file matching).
   The only asymmetry is ~101 files that exist **only** in
   `fengyun434`'s copy and none that exist only in this `fy4` clone —
   i.e. this clone is a strict, byte-identical subset. Those extra
   files are all runtime accumulation from `fengyun434` being a
   later/lived-in snapshot of the same server, not code differences:
   `.bak` backup copies of edited NPC/skill/admin source files (e.g.
   `adm/commandd.c`, several `daemon/class/*/*.c.bak` skill files,
   handful of `d/*/npc/*.bak`), `adm/etc/wizip` and
   `wizlist.bak`, accumulated `data/board`, `data/login`, `data/user`,
   `data/questitem/psrnecj.o` save state, `obj/questitem`,
   `obj/selfmake`, and — most tellingly — dozens of real player
   `p/residence/<name><timestamp>.o` save files and a populated
   `OBJ_DUMP`/`tmp` from actual play sessions.

**Conclusion: `fy4` is a byte-for-byte identical duplicate of
`fengyun434`'s codebase**, specifically an *earlier* snapshot of the
exact same server taken before those backups and player saves
accumulated — not merely the same lineage/engine family, but the same
tree.

## Disposition

Per this project's standing convention for confirmed duplicates
(`duplicate_of` in `meta.json`, e.g. `mhxy2002`→`mhxyqd`,
`xxcqii2`→`xxcqii`, `moniHuafu`→`mnhf`) and per
`scripts/gen_site_index.py`'s own documented behavior (duplicate-
archive entries never own a `libs/` dir for site purposes — they're
skipped from the generated site entirely), this entry is recorded as
metadata only:

- **No independent `work/`, `config.fluffos`, or boot/play test was
  produced.** Reproducing the GBK→UTF-8 conversion and driver-compat
  fixes here would exactly reproduce `fengyun434`'s already-committed
  `work/` tree byte-for-byte (same source, same fixes apply
  identically) — zero new information, pure duplicated effort, and
  this clone has strictly less content than `fengyun434`'s raw dump
  (no accumulated saves worth preserving either).
- **The live, playable instance for this codebase is `fengyun434`**
  (port 40011, https://mudlibs.fluffos.info/fengyun434/, admin account
  `fluffos` / `Mud@2026`). Its `NOTES.md`/fix catalog applies equally
  to this source.
- **Port 40218** was pre-assigned to this entry (checked against the
  whole collection to avoid collisions) but is left unused in
  `config.fluffos`-space since no driver instance runs under this
  slug; recorded here so the reservation is documented and the port
  isn't accidentally handed to a future, genuinely-distinct lib.
- `wasm_status` is left `""` (not `"playable"`) since no WASM
  pack/boot test was run under this slug specifically — the
  WASM-playable instance is `fengyun434`'s.
- No `README.md` is created for this entry (matching the `mhxy2002`
  precedent) — the bilingual write-up belongs on `fengyun434`, the
  entry actually reachable from the generated site.

## If a future pass wants an independent build anyway

Nothing above is destructive — `raw/` is present and untouched, so a
future agent could still run the full §2 pipeline here if there's ever
a reason to want two independently-built copies. Given the confirmed
byte-identical (subset) source, the expectation is that it would
reproduce `fengyun434`'s `work/` tree and fix list exactly.
