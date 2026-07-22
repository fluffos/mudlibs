# bxsj.rar → `bxsj`

- Archive: `archives/bxsj.rar` (15.4MB — "书剑天下"/"ShuJian MUD", a
  substantial, actively-maintained-looking codebase, MudOS-lineage,
  `Copyright 1997-2004 ShuJian MUD Wizard Group`).
- Mudlib root in archive: `shujian/` (config lives one level up in
  `shujian/mudos/config.txt`, alongside a bundled `mudos/driver` Windows
  binary — ignored, we use our own driver). `mudlib directory : /tx` in
  the shipped config is the ORIGINAL developer's absolute server path,
  unrelated to our layout — always override, never trust this value.
- Port: **40004**. 9936 `.lpc` files after conversion — second-biggest
  lib so far.
- Note: this lib's `name :` is also "书剑天下", the SAME name as another
  archive in this collection (`书剑天下.rar`, TODO #36) — likely a
  different snapshot/version of the same underlying mud. Not the same
  archive (not a byte-duplicate), so processed separately per the
  standard pipeline; cross-reference when that archive's turn comes.

## Status: DONE — boots clean, playable over telnet

Reached name entry, length validation, existing-ID detection, and the
password prompt — full login flow confirmed working. This lib surfaced
three genuinely new (to this project) driver-interaction bugs, all
generalizable patterns now cataloged in `AGENTS.md`.

## What was fixed

1. Encoding: 10865 converted, 737 already UTF-8/ASCII, 75 skipped binary,
   36 lossy. **Found the `convert_lib.sh` binary-detection bug here**
   (AGENTS.md, "Encoding — `file`'s text/binary guess is not reliable
   enough to gate on"): `file` misclassified several genuine GBK **source**
   files as `data` (unusual CRCRLF line endings apparently confuse its
   heuristic) and the script silently skipped converting them, leaving raw
   GBK bytes in `work/`. Fixed the shared script (forces known text
   extensions regardless of `file`'s guess) AND manually converted the
   9 affected files found here (`feature/save.lpc`, `clone/user/
   olduser{,2}.lpc`, `adm/daemons/bbsd.lpc`, `cmds/std/testsjmud{1,2}.lpc`,
   `cmds/arch/ucp.lpc`, `cmds/wiz/movedata{2,cq}.lpc`) plus re-scanned
   libs #1-3 for the same issue (clean, 0 hits — this bug's impact was
   specific to whatever tool/era produced this particular archive).
2. `.c` → `.lpc`: 9936 files. 834 literal `.c"` refs auto-fixed, 0 left over.
3. `static` → `nosave`: 199 files.
4. No §4 (`load_object` in `valid_read`) issue in this master — checked,
   `valid_write`/`valid_read` call `SECURITY_D` via `find_object` only
   (no lazy `load_object`), so no recursion risk there.
5. **New bug (AGENTS.md §8, extended)**: `master.lpc`'s `log_error()` —
   the driver's own error-reporting callback — calls
   `CHANNEL_D->do_channel(...)` unconditionally. If `CHANNEL_D` isn't
   actually loaded at the moment a PRELOADED file fails to compile (which
   is exactly when `log_error()` runs), that call needs a fresh compile,
   which is forbidden mid-compile → `Object cannot be loaded during
   compilation` → which re-enters `log_error()` → cascades. This fired
   repeatedly during boot for multiple different failing preload entries.
   Fixed with the same reentrancy-guard + `catch()` shape as AGENTS.md §4.
6. **New bug (AGENTS.md §14 cousin)**: `master.lpc`'s `valid_override()`
   was 2-arg (missing the `main_file` parameter needed for `efun::` calls
   inside `#include`d simul_efun fragments) AND defaulted to **deny**
   (`return 0`) rather than allow for anything not explicitly listed —
   stricter than lib #1's version. Added the 3rd parameter, plus an
   explicit allow-list for the simul_efun message-formatting wrappers
   (`shout`/`write`/`tell_object`/`tell_room`/`say`) that `cmds/adm/ad.lpc`
   needed via `efun::shout(...)`.
7. **New bug, the real blocker for this lib (AGENTS.md §8c) — took the
   most effort to find**: `securityd.lpc`'s `valid_read()` had
   `if (this_player()) user = this_player();` unconditionally, which
   wrongly attributed a SYSTEM-initiated lazy `load_object()` (master
   loading `BAN_D`/`band` and `UPTIME_CMD`/`cmds/usr/uptime`, neither
   preloaded, both first touched from inside a brand-new connection's own
   login sequence) to that connecting player's own unprivileged
   permissions instead of the real (root-euid) caller — an `exclude_read`
   rule protecting `/adm` from ordinary players then denied it, **which
   permanently stranded every single new connection** at the login banner
   (no compile errors anywhere — looked like a total, silent hang).
   Diagnosed via a temporary instrumented `master.lpc valid_read()`
   (logged file/user/func/result to a scratch file) rather than guessing
   from the generic `*Read access denied.` message — found the exact two
   denied `load_object` calls in minutes. Fixed: only override with
   `this_player()` when the passed-in `user` doesn't already have a
   resolvable euid/uid.

## Known remaining issues (documented, not fixed)

- 78 lpcc-sweep failures (post-fixes; was many more before). Notable
  categories left un-triaged: `Bad type for argument 1 of is_killing`
  (9 files), `Undefined function set`/`set_temp` (10 files combined),
  optional network/mail daemon cluster (`member_group`,
  `data_netmail_file` — same missing-headers shape as libs #1/#2), a
  handful of scattered `Undefined function/variable` content gaps.
- `clone/misc/tang.lpc`: one string literal built entirely from octal
  byte escapes (`"\377\371\377\376\042\377\374\005..."` — raw telnet
  protocol/control bytes, not text) that has no valid representation as a
  UTF-8 LPC string in this driver (old drivers had raw 8-bit strings).
  Would need converting to a `buffer` literal to fix properly; one
  obscure clone item, not fixed.

## How to run

```
cd libs/bxsj
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40004 --timeout 10 --send "n" --send "testuser" --send "quit"
```
