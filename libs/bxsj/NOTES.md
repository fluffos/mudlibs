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

## Retroactive fix (found via archive #90, jinyongwenzi): this lib was completely command-dead after registration (AGENTS.md §15ae + a new commandd.lpc variant)

Archive #90 (`金庸文字版.exe`) turned out to be the literal same codebase as
this lib (byte-identical `master.c`/`securityd.c`/`chinese.c` after CRLF
normalization -- confirmed via diff, not assumed) processed much later in
the project, after §15ae (the `private nomask` command-hook bug) had
already been discovered and fixed elsewhere. That later pass found this
exact lib had TWO independent bugs compounding into the same symptom --
every single post-login command (even `look`) silently doing nothing at
all, with zero error anywhere:

1. **`feature/command.lpc`'s `command_hook()`** was `private nomask` --
   unreachable via `add_action`'s external dispatch on this driver (§15ae).
2. **`adm/daemons/commandd.lpc`'s `rehash()`** filtered `get_dir()` output
   via `sscanf(cmds[i]+"$", "%s.c$", cmds[i])` -- a live `sscanf` pattern
   invisible to both the `.c`→`.lpc` rename's quoted-string fixer and the
   bare-data-file fixer, since it's neither. After the rename this matched
   zero files forever, so `commandd`'s command-search table was never
   populated and `find_command()` always returned 0 -- a second,
   independent cause of the exact same symptom. Fixing only one of the two
   would still have left every command dead.

Both fixed here (dropped `private`; changed the sscanf pattern to
`"%s.lpc$"`), then re-verified with a full fresh registration (real name,
one of "秦风"/"秦岭"/"秦河" tested across a few runs) followed by `look`,
`score`, and `quit` all producing correct real output, and `debug.log`
confirmed clean (0 `error:` lines). This lib's ORIGINAL testing pass (see
above) never verified a post-login command -- exactly the blind spot §15ae
warns about -- so this had been silently broken since this lib was first
marked "done," undetected until the sibling codebase surfaced it. See
AGENTS.md §15ae and the new commandd.lpc sscanf-pattern addition for the
general writeup.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (9,936
  files, 9,681 written/reformatted, 102 already-clean, 153 refused with
  an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦叔`, ID
  `qinshu`) through the complete flow (ID → password, which must contain
  both a digit and an uppercase letter and not be "too simple"/derived
  from the ID → Chinese name → talent roll → email → gender), reaching
  the actual game world (武馆前院 starting room) with the welcome-NPC
  escort dialog (`狄云`) firing correctly; `look`/`score`/`quit` all
  produced correct output (the full 个人资料卡 stat card rendered
  correctly), zero real errors in `debug.log`. No regressions from the
  reformat or the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/network/dns_master.lpc`'s
  `socket_create`/`socket_close` → `Undefined function`, caught by
  `master.lpc`'s own error handler exactly as for a missing daemon
  natively — `Initializations complete.` still printed). Registration
  itself is blocked by the **exact** documented `query_ip_number()`
  WASM-mode limitation this project's tooling docs call out by name for
  this lib: `adm/daemons/sited.lpc`'s site-restriction check rejects
  every attempted ID with "对不起，这个英文名字不能从当前地址登录。"
  ("sorry, this name cannot log in from the current address") because
  the wasm loopback connection's `query_ip_number()` doesn't format as a
  real dotted-quad. **Not a mudlib bug** — this is the documented
  driver-side gap, not something to patch. Verdict: boots cleanly under
  WASM; registration cannot complete due to the driver's IP-check
  limitation.
