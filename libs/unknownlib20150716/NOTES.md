# 20150716未知lib.zip → `unknownlib20150716`

- Archive: `archives/20150716未知lib.zip` (9.5MB, "unknown lib" dated
  2015-07-16 in the filename — actually **『小雨西游Ⅱ』(Xiaoyu Xiyou II /
  "Light Rain Journey to the West II")**, v3.0, confirmed from the live
  banner ("站点创建时间：2013年12月30日"). Journey-to-the-West themed,
  MudOS 0.9.20 lineage.
- Mudlib root in archive: `20150716/` (single top-level folder).
- Config: **no config.cfg at archive top level** — found at
  `20150716/adm/etc/config.xiyou` (`xiyou` = 西游, "Journey to the West").
  Always check `adm/etc/*` for a config-shaped file when none is obvious
  at the top.
- Port: **40003**. Biggest lib so far: 9635 raw files / 8467 `.lpc` after
  conversion.

## Status: DONE — boots clean, playable over telnet

Full ASCII-art Monkey King banner, GB/BIG5 encoding-selection prompt (a
legacy dual-encoding-era feature — answering either way is fine since
everything here is UTF-8 now), then normal login flow, all confirmed
working. **Note: this lib enforces a 30-second startup grace period**
(`adm/daemons/logind.lpc`'s `logon()`: `if (uptime() < 30) { ...still
starting up, try later... }`) — intentional, not a bug; wait >30s after
boot before testing a connection.

## What was fixed

1. Encoding: 9208 converted, 320 already UTF-8/ASCII, 31 skipped binary,
   76 lossy (-c fallback, pre-existing stray bytes).
2. `.c` → `.lpc`: 8467 files. 1914 literal `.c"` refs auto-fixed, 0 left over.
3. `static` → `nosave`: 203 files.
4. `master.lpc` has neither the §4 (`load_object` in `valid_read`) nor the
   §14 (2-arg `valid_override`) issues — checked, both already fine in
   this lib (it uses `sscanf(file, "/adm/simul_efun/%s", file)` to detect
   simul_efun fragments for the `destruct` override case, a different but
   equally valid solution to the same problem AGENTS.md §14 documents).
5. `adm/etc/log/` directory was missing entirely from the archive (not
   just the driver's debug-log dir — the mudlib's OWN runtime log dir).
   Symptom: repeated `*Wrong permissions for opening file /log/log for
   append` errors at boot (misleading — it's a missing-directory issue,
   not an actual permission problem; `SECURITY_D`'s write-permission check
   for a nonexistent path denies rather than erroring with ENOENT).
   Fixed: `mkdir work/log`.
6. **Found and fixed a new general pattern** (AGENTS.md §8d): ~200+ files
   `#include <local.h>`-style a per-file header living in their OWN
   directory (e.g. `d/kaifeng/ground0.lpc`'s `#include <ground.h>`, with
   `ground.h` sitting right next to it) — `<...>` never searches the
   including file's own directory in this driver (only `"..."` does).
   Fixed with ONE addition to `master.lpc`: implemented
   `get_include_path()` to prepend the compiling file's own directory to
   the search path. This alone dropped the lpcc sweep's failure count
   from 289 to 64 (of 9017 checked).

## Known remaining issues (documented, not fixed)

- 64 remaining lpcc-sweep failures, not individually triaged past a
  category scan — dominated by scattered `Undefined function/variable`
  errors (`greeting1`/`greeting2`/`reporting`/`order_list`/
  `quest_accurate_index`/`can_enter`/`you_leave`/etc, `RED`/`NOR`/`GRN`/
  `BLK`/`DEBUG`/`flowers`/`obstacles`/`banned_cast`/`banned_action`) that
  look like content-completeness gaps (quest/greeting content referencing
  things not present in this particular archive), same shape as other
  libs' missing-zone-content findings (AGENTS.md §13). None of the
  affected files are on the boot/login critical path.

## How to run

```
cd libs/unknownlib20150716
~/src/fluffos/build-debug/src/driver config.fluffos
# wait >30s after boot before connecting (see startup grace period above)
python3 ../../scripts/mudclient.py 127.0.0.1 40003 --timeout 10 --send "gb" --send "" --send "look" --send "quit"
```
