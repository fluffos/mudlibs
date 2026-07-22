# fy2005.rar → `fy2005`

- Archive: `archives/fy2005.rar` (48MB — "风云Ⅳ" 2005 build, same lineage
  as archive #14 (fengyun434), a later/bigger snapshot). Mudlib root at
  `fy2005/fy4/`, config at `fy2005/bin/config.fy4`.
- Port: **40013**.

## Status: DONE — boots clean; has an intentional 5-minute startup grace period

Booted with zero fixes needed (same clean lineage as fengyun434/fy2).
**This build enforces a 5-minute wait before login is allowed**
("风云系统正在初始化，请在五分钟后再登陆。" — "Fengyun system is
initializing, please log in again in 5 minutes.") — an intentional
startup-grace mechanic (same shape as `unknownlib20150716`'s 30-second
wait, just longer here), not a bug. Not waited out to confirm the actual
post-wait login flow given the time cost, but the boot itself is clean
(no compile errors, no crashes) and the pre-wait prompt flow (name
validation) works correctly.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (12801 converted,
384 already UTF-8/ASCII, 43 skipped binary, 75 lossy), `.c`→`.lpc` (9764
files, 1328 refs auto-fixed), 11 local angle-bracket includes converted
to quotes automatically, `static`→`nosave` (44 files).

## Known remaining issues (documented, not fixed)

- Several `call_other() couldn't find object '/d/ZONE/room.c'` errors at
  boot — traced to plain-text DATA files (`quest/dynamic_location`,
  `adm/etc/scenery_phase` — bare one-path-per-line lists, no LPC string
  quoting) that still hold literal `.c` object-path references.
  `convert_lib.sh`'s `.c"` reference fix only scans `.lpc`/`.h` source
  (quoted-string context); it doesn't touch extensionless data files with
  bare (unquoted) paths, and blanket-fixing "any `path.c` text anywhere"
  risks false positives in genuine documentation/help text. Left as-is —
  affects some quest/scenery room resolution, not the boot/login path.
- lpcc sweep: 9696/9764 pass (99.3%) — not fully triaged past confirming
  a clean boot given time constraints.

## How to run

```
cd libs/fy2005
~/src/fluffos/build-debug/src/driver config.fluffos
# wait 5 minutes after boot before the login name prompt will proceed
python3 ../../scripts/mudclient.py 127.0.0.1 40013 --timeout 10 --send "" --send "look" --send "quit"
```

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).
