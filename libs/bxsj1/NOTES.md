# bxsj1.rar → `bxsj1`

- Archive: `archives/bxsj1.rar` (23.8MB — "书剑·经典"/"ShuJian Classic",
  the SAME lineage as archive #4 (`bxsj.rar`/书剑天下), but a much more
  complete/later snapshot: bundles production driver binaries for
  multiple platforms (Windows/Cygwin, ARM, MIPS) plus leftover
  `.exe.stackdump` crash dumps from real prior usage.
- Mudlib root in archive: `bxsj1/shujian/` (config at `bxsj1/bin/
  config.sj`, sibling to a `bin/` dir of platform binaries — all ignored,
  we use our own driver). `mudlib directory : /home/sjmud/shujian/` in
  the shipped config is the original server's absolute path — overridden
  as always.
- Port: **40005**. 9938 `.lpc` files — similar size to bxsj.

## Status: DONE — boots clean, playable over telnet

Reached name entry / length validation / existing-ID detection / password
prompt, same as bxsj. Given the shared lineage with archive #4, the three
bugs found there (AGENTS.md §4/§8/§8c/§14) were applied **proactively**,
before ever attempting a first boot, by checking this lib's `master.lpc`/
`securityd.lpc` for the identical code shapes first — confirmed present,
fixed immediately, and the lib booted clean on the very next attempt (only
the `log_error()`/`CHANNEL_D` guard's benign caught-error log lines showed
up, matching bxsj's known-fine post-fix behavior, not a new problem).

## What was fixed

Same three fixes as `bxsj` (see that lib's NOTES.md / AGENTS.md §8/§8c/§14
for the full write-up), applied directly since this is the same codebase
lineage:
1. `master.lpc` `log_error()`: added the reentrancy-guard + `catch()`
   around `CHANNEL_D->do_channel(...)`.
2. `master.lpc` `valid_override()`: added the 3rd `main_file` parameter,
   plus the `shout`/`write`/`tell_object`/`tell_room`/`say` allow-list.
3. `securityd.lpc` `valid_read()`: only fall back to `this_player()` when
   the passed-in `user` has no resolvable euid/uid of its own.

Plus the routine per-lib steps: encoding (10883 converted, 743 already
UTF-8/ASCII, 37 skipped binary, 39 lossy), `.c`→`.lpc` rename (9938 files,
836 refs auto-fixed, 0 left over), `static`→`nosave` (197 files + 2 more
fixed by hand — **found a `convert_lib.sh` bug here**: a filename
containing a literal space (`"char - 副本.lpc"`, a Chinese-annotated
backup/duplicate file — "副本" = "copy") broke the newline-delimited
`xargs` pipe in the static-fix step, silently skipping just those 2
files. Fixed the script to use NUL-delimited (`-print0`/`grep -Z`/
`xargs -0`) throughout that step, matching how the `.c"`-reference-fix
step already did it correctly.

## Known remaining issues (documented, not fixed)

Same shape as `bxsj`: 74 lpcc-sweep failures, dominated by
`Bad type for argument 1 of is_killing`, `Undefined function
set`/`set_temp`/`query_lord`/`change_state`, a few `Illegal character`
(genuine source typos, not individually triaged), and the two expected
`#include`-fragment false positives (`adm/simul_efun/{message,object}` —
AGENTS.md §6b, confirmed harmless in a real boot).

## How to run

```
cd libs/bxsj1
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40005 --timeout 10 --send "n" --send "testuser" --send "quit"
```
