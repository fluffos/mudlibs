# xajh2 — 笑傲江湖 (XO/TMI-2/ES2 lineage, NOT the nitan family)

Archive: `笑傲江湖II.rar`. Port: 40068. Status: **done** (boots clean, full
registration with a real Chinese name works end-to-end, and post-login
commands `look`/`score` both produce real output).

## Lineage check (done first, per instructions) — related to xo/xo_final, NOT nitan

Despite sharing the "笑傲江湖" (Laughing in the Wind) title with `nitan6`
(archive #22), this is a **completely different codebase** — confirmed by
evidence, not assumed either way:

- Raw archive layout: `lib/secure/daemon/{master,sefun,securityd}.c`,
  `lib/system/daemon/*.c`, `config.xo`, `startxo.bat`, a bundled Cygwin
  driver (`cygwin1.dll`, `driver.exe.stackdump`) — this is the
  `secure/daemon/` path convention used by `xo` (archive #28,
  笑傲江湖迷你版) and `xo_final` (archive #29, xo最终版1.2), **not** the
  `adm/obj/`+`adm/kernel/simul_efun/` layout of the nitan family.
- `secure/daemon/master.c`'s header comment: *"Original from TMI-2 and
  ES2, Rewritten by Falcon 96-10-02"* and its `connect()` references *"The
  XO mudlib www server"* — identical branding lineage to `xo`/`xo_final`.
  `md5sum` against both confirms this is a **distinct, non-identical**
  snapshot (not a duplicate of either): `master.c`/`sefun.c`/`chinesed.c`/
  `logind.c` all differ byte-for-byte from both `xo` and `xo_final`, while
  sharing the same directory layout and header style. File counts also
  place it as its own build: 5079 raw / 4344 `.lpc` (between `xo`'s 1395
  and `xo_final`'s ~7174).
- **Architecturally**: `secure/daemon/sefun.lpc` defines **no** global
  `set`/`query`/`delete` at all — every object gets real, local
  `set`/`query`/`delete` methods from `system/feature/base/dbase.lpc`
  (`inherit F_TREEMAP`, genuine per-object `dbase` mapping). This is the
  architecturally-correct pattern (same as `xo`/`rzrmud`/`xkx2001`), **not**
  the nitan-family bare-simul_efun-dbase bug (AGENTS.md §15) — confirmed by
  reading `dbase.lpc`'s actual implementation, not inferred from the title.
- The in-game banner text itself says *"笑傲江湖从二⊙⊙三年四月一日以来已经
  有...人次登录"* ("since April 1, 2003") — a later snapshot than `xo`
  (1998-99 era) or `xo_final`, consistent with this being a distinct,
  later "XO mudlib" build, plausibly the "II" the archive name refers to.

**Conclusion**: same lineage family as `xo`/`xo_final` (TMI-2/ES2/Falcon
"XO mudlib"), a distinct build/snapshot — not a duplicate, not nitan-family.
`xo`'s §4 fix was ported directly (proven fix, same file shape); the §15/
§15a-c/§15v nitan-specific fixes do **not** apply here at all.

## What this is (per the archive's own README, `说明.txt`)

Actual game name is **笑傲江湖** (`config.xo`'s `name` field says "笑傲江湖
迷你版" — a stale copy-paste leftover from the mini-edition config, **not**
this build's real name, same class of leftover documented for
`dtsl2` in TODO.md). Per `说明.txt`: official address
`xo.27net.net:4000`, default wizard account `locker`/`000000` (present in
`secure/etc/wizlist`). Used the archive's own working title
"笑傲江湖II" for the slug/config `name` since that's what distinguishes it
from `xo`/`xo_final` in this project's naming.

## Fixes applied (with why)

1. **AGENTS.md §15h — `is_chinese`/`IsLegalName` GBK byte-range bug**
   (proactive, confirmed present here too):
   - `secure/sefun/chinese.lpc`'s `is_chinese(str)`:
     `strlen(str)>=2 && str[0]>160 && str[0]<255` (GBK lead-byte check) →
     `strlen(str)>=1 && str[0]>=0x4e00 && str[0]<=0x9fff` (CJK codepoint
     range, UTF-8 native).
   - `system/daemon/band.lpc`'s `IsLegalName(name)`: length bound
     `i<4 || i>10` (4-10 *bytes* = 2-5 GBK chars, matching the message
     "只能是 2 到 5 个中文字") → `i<2 || i>5` (2-5 *characters*); and the
     per-character loop's `i % 2 == 0 && !is_chinese(name[i..<0])` (byte
     lead-position gate) → dropped the `i % 2 == 0 &&` entirely (every
     UTF-8 index is already one full character).
   - Verified end-to-end: sent the real Chinese name **秦风** through
     registration and it was accepted, advancing to the password prompt —
     not just "reached the prompt".

2. **AGENTS.md §4 — master.lpc lazy-security-daemon reentrancy guard**
   (ported directly from `xo`'s proven fix, same file shape —
   `secure/daemon/master.lpc`'s `valid_write`/`valid_read` already wrapped
   `load_object(SECURITY_D)` in `catch()` but had no re-entrancy guard and
   no `find_object()` fast-path check first): added
   `private nosave int loading_security_d;` and the same
   find_object-first / guarded-load / degrade-to-default-on-reentry shape
   used in `libs/xo/work/secure/daemon/master.lpc`.

3. **New bug (not previously cataloged): `combatd.lpc`'s switch/case with
   every real `case` commented out, leaving a bare `default:`** — this
   driver requires at least one real `case` statement in a `switch`
   (`error: need case statements in switch/case, not just default:`).
   Since every branch except `default` was already dead code, replaced the
   whole `switch` with the `default` branch's statement directly (no
   restored content, just removed the now-meaningless switch wrapper).
   This is a **preloaded** daemon (`combatd` is in `etc/preload`), so this
   was a genuine boot-blocking compile error, not a dormant one.

4. **New bug (not previously cataloged, high-impact): this driver build
   has `__OLD_ED__` defined, so the "new" `ed_start`/`ed_cmd`/
   `query_ed_mode` efuns this codebase's editor feature was written
   against simply don't exist at all** (`core.spec`'s `#ifdef OLD_ED /
   #else` split — only one side is ever compiled in). This broke TWO
   files:
   - `system/feature/user/editor.lpc` (the `edit()`/in-game-editor
     feature, **inherited straight into `/clone/user/user.lpc`, the
     player body class itself**) — failed to compile at all, which
     silently made `make_body()` return a broken/uncompilable object
     during registration with **zero visible error** (same failure shape
     as AGENTS.md §15b's "player-body class object itself failing to
     compile", new root cause). Fixed by rewriting `edit()` to call the
     OLD_ED `ed(file, exit_fn_name, restricted)` efun instead, with a new
     `editor_exit_fn()` callback replacing the old manual
     `query_ed_mode()==-1` completion-detection. Confirmed via
     `~/src/fluffos/src/comm.cc` that under `__OLD_ED__` the driver's own
     C-level input loop (`if (ip->ed_buffer) { ed_cmd(...); goto exit; }`)
     intercepts every line directly while editing, **bypassing
     `input_to()`/`process_input()`/`write_prompt()` entirely** — so the
     old manual per-keystroke `ed_cmd()` forwarding in `process_input()`
     was unreachable dead code under this driver, not something to
     reimplement; simplified to a harmless passthrough.
   - `system/feature/user/message.lpc`'s `write_prompt()` had the same
     `query_ed_mode()` dependency for customizing the in-editor prompt —
     same root cause, same fix rationale (dead code under `__OLD_ED__`,
     since `print_prompt()` in `comm.cc` also short-circuits straight to
     `ip->prompt` for `ip->ed_buffer`-active connections, skipping
     `APPLY_WRITE_PROMPT`). Removed the branch.
   - **This is likely to recur on other libs** — worth a new AGENTS.md
     catalog entry (§15af-shaped): any lib using `ed_start`/`ed_cmd`/
     `query_ed_mode` needs this same fix, and the tell is a compile error
     in whatever file is `inherit`ed into the player body class, which
     then manifests as registration silently failing right after
     character creation with no error shown anywhere.

5. **New bug (not previously cataloged, the hardest one to diagnose in
   this pass): the `/log/nosave/` directory was entirely missing from the
   shipped archive** (classic "RAR/zip drops empty dirs", same class as
   several prior libs) — used by `log_file()` targets like
   `PPL_USAGE_LOG`/`WIZ_USAGE_LOG`/`COMMAND_LIMIT_LOG` (all
   `"nosave/..."`-prefixed in `include/globals.h`). An **uncaught**
   `write_file()` error to that missing path, inside
   `secure/sefun/file.lpc`'s `log_file()` simul_efun, silently aborted the
   **entire** `get_gender() → log_login() → init_new_player() →
   enter_world()` call chain right after gender selection — **with zero
   visible error anywhere**: not in `debug.log`, not shown to the
   connecting player. Bisected with temporary `efun::write()` checkpoints
   (removed after diagnosis, per AGENTS.md's established §8c/§15d
   technique) down to the exact statement, then discovered the *actual*
   error WAS being logged — just to the **mudlib's own**
   `/log/runtime/secure` file (via `master.lpc`'s custom `error_handler()`
   apply), not `debug.log`. It was never shown to the player because
   `error_handler()` only calls `message("error", ...)` when
   `this_player()` is truthy, and at that specific point in the
   pre-`exec()` registration flow it apparently wasn't. **New diagnostic
   lesson, worth cataloging**: when a registration/input_to flow silently
   stalls at one exact step with *nothing* in `debug.log` and nothing
   shown to the player, check the mudlib's **own** `log/runtime/*` and
   `log/catch` files (if it has a custom `error_handler()` master apply)
   before assuming there's no error at all — the mudlib's own error
   logging can be strictly more complete than what reaches the terminal.
   **Fix**: created `work/log/nosave/` (mkdir), and wrapped
   `log_file()`'s `write_file()` call in `catch()` as defense-in-depth
   (§15e-style graceful degradation — a failed bookkeeping log write
   should never be allowed to abort character creation).

6. **§15i-shaped bug (comment eats the following code), recurring in two
   sibling files**: `system/std/char/task.lpc` and
   `system/std/char/special_quest.lpc` both had
   `// 现在先共用一个quest库    if ( random( class_score ) < 50 )` — the
   Chinese comment and the real `if` statement are on the *same physical
   line*, so `//` swallows the entire `if`, leaving a dangling
   `else if`/`else` chain with no matching `if` (`error: syntax error,
   unexpected L_ELSE`). Found via the exact same distinctive comment text
   in both files (one shared bug, not two) — split the comment onto its
   own line in both.

7. **`clone/user/immortal.lpc`**: `string array arrCmd = explode(cmd,";")`
   — `TYPE array NAME` is not valid array-declaration syntax on this
   driver (distinct from AGENTS.md §15f's *bare* `array` — this is a
   *different* two-word "TYPE array" spelling, presumably a synonym this
   codebase's original target driver accepted). Fixed to `string *arrCmd`.
   This is the wizard-only multi-command (`;`-separated) batching feature
   in the wizard player-body class.

8. **`system/daemon/poisond.lpc`**: called `set()`/`restore()`
   (F_SAVE/F_DBASE methods) but never `inherit`ed either — a genuine
   pre-existing omission (every sibling daemon, e.g. `emoted.lpc`, does
   `inherit F_SAVE;`). Added `inherit F_SAVE;`. **Not fully fixed** even
   after this — `lpcc` still reports a (silent, no explicit error text)
   failure to load, most likely `restore_object()` erroring on
   nonexistent save data at `create()` time. Not pursued further:
   `poisond` is **not** in `etc/preload` and nothing else in the lib
   `call_other`s into it — confirmed dead/unreachable code, so this
   doesn't affect boot or the verified registration/gameplay path.

## Confirmed NOT needed (checked by reading the actual source)

- **§7 `get_root_uid()`/`get_bb_uid()`**: already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§15g case-sensitivity `#include <Action.h>`**: the exact same
  `<Action.h>` (capital A) include that was an *active* bug in `xo`
  (archive #28) exists here too, in `system/feature/char/command.lpc` —
  but it's **already commented out** (`//#include <Action.h>`) in this
  build, so it's inert, not an active bug. (The `class Action` struct it
  would have defined is separately, genuinely missing from this whole
  archive — see the lpcc-sweep section below.)
- **§15n custom securityd blocking driver compile-time loads**:
  `secure/daemon/securityd.lpc`'s `valid_read` already has
  `if (!euid) return 1;` (explicit allow when the caller's euid is unset)
  *before* the exclude-list check — this alone sidesteps the whole bug
  class (a never-preloaded object's first lazy compile, with the loading
  object's euid not yet set, would otherwise hit the exclude list and get
  denied). Confirmed by reading the source, not by hitting the crash.
- **§15o `master.lpc get_include_path()`**: not implemented, but
  `convert_lib.sh`'s automatic local-angle-include→quotes rewrite (13
  instances converted) already resolved every actual `<local.h>`-next-to-
  its-user case in this lib before the first boot attempt — nothing left
  needing this fix.
- **§15p DNS/intermud preload exclusion**: `etc/preload` never contained
  a DNS/intermud/mudlist daemon in the first place (only
  `/system/daemon/network/smtp`, whose `create()` only sets a socket
  type — no eager `eventCreateSocket()` call, confirmed by reading it).
  Nothing to exclude.
- **§15v `LONELY_IMPROVED`-style efun gating**: not applicable (not
  nitan-family).
- **§15w `log_error()` funneling warnings to players**: `master.lpc`'s
  custom `error_handler()` only shows a message when `this_player()` is
  truthy, and only for genuine runtime errors (not compile warnings) —
  no evidence of spurious warning-spam during a clean boot.
- **§15x hardcoded `MUD_PORT` mismatch**: `master.lpc`'s `connect(port)`
  only special-cases `port==4004` (an alternate httpd port, unconfigured
  here) and falls through to normal login for any other port — our
  assigned 40068 hits the normal path correctly.
- **§15z `nosave`/`static` compatibility shim collision**: no
  `#define nosave static`/`#define protected static` shim found anywhere.
- **§15ae `private nomask` command-hook bug — the CRITICAL standing-policy
  check**: `system/feature/char/command.lpc`'s `command_hook(string arg)`
  is declared `nomask int command_hook(...)` — **not** `private`.
  Verified by reading the source *before* testing, and confirmed
  empirically: `score` (a real post-login command) produces a full,
  correct character-sheet output, not the generic fail message.
- **§15/§15a-c/§15v (nitan-family dbase architecture bug)**: definitively
  not applicable — see the Lineage section above.
- **§8f (`TYPE * a, b` comma-list array-modifier bug, Dead-Souls-lineage
  specific)**: 49 candidate lines found via the same grep shape, spot-
  checked a sample — all are genuinely-intentional mixed array/scalar
  declarations (e.g. `string *id, my_id;` where `my_id` really is used as
  a scalar elsewhere), not the Dead Souls bug. Not touched.
- **§15ac bare `SAVE_EXTENSION`**: one hit (`include/net/ftpdsupp.h`), but
  `ftpd` is commented out of `master.lpc`'s `connect()` and never loaded —
  inert, not fixed.

## New bug classes found here, worth AGENTS.md entries (flagged for the
## main session to catalog)

1. A `switch` with every real `case` label commented out, leaving a bare
   `default:`, is a hard compile error on this driver (`combatd.lpc`).
2. **`__OLD_ED__` vs the "new" `ed_start`/`ed_cmd`/`query_ed_mode` API** —
   this driver build only has ONE of the two editor APIs compiled in
   (`__OLD_ED__` is defined), so any lib written against the other one
   fails to compile wherever it's used; if that's inherited into the
   player body class, registration silently breaks right after gender/
   character creation with zero visible error. Likely to recur.
3. An uncaught `write_file()`/`log_file()` error to a missing directory
   during a pre-`exec()` `input_to` callback chain can abort the whole
   chain with **zero** visible error in `debug.log` or to the player —
   the mudlib's own custom `error_handler()` DOES log it, but only to its
   own `log/runtime/<X>` file, gated on `this_player()` for player
   visibility. New diagnostic lesson: check the mudlib's own runtime/catch
   log files, not just `debug.log`, when a flow silently stalls.
4. `TYPE array NAME` (two words, not AGENTS.md §15f's bare `array`) is
   ANOTHER old-MudOS-dialect array-declaration spelling this driver
   doesn't support — found extensively (12+ instances) in a dead legacy
   file (`system/daemon/xoban.lpc`, superseded by `band.lpc` per its own
   header comment) and once in a live file (`immortal.lpc`, fixed).
5. §15i's "comment eats following code" pattern recurred in a new shape:
   the comment and the swallowed code are on the *same* physical line
   (not the comment eating the *next* line) — found identically in two
   sibling files via one shared distinctive comment string.

## Interactive test result (full transcript outcome)

Registration flow, in ONE continuous `mudclient`-style connection:
`new` → `qinfeng` (English id) → `y` (confirm) → **秦风** (real Chinese
name — accepted, not rejected) → `123456`/`123456` (password + confirm) →
`test@test.com` (email) → `m` (gender) → lands in the game world (welcome
banner "温故知新" shown).

**Post-login commands** (§15ae standing policy, tested after registration
completed, not just at the prompt):
- `look`: real (non-generic) output — `创建房间中的物体失败，请报告巫师。
  （见room_log） / 运行时发生错误：*call_other() couldn't find object
  '/d/place/newbie/start'. 错误信息被写到：/log/runtime/clone`. This
  is a **genuine content gap**, not a driver bug: `logind.lpc` hardcodes
  `user->move("/d/place/newbie/start")` for every brand-new
  (`newbiep()`) character, but `d/place/` only contains `cunzi`, `death`,
  `desert`, `hami`, `jianhu`, `player`, `wiz`, `xkdao`,
  `after_qingcheng` — no `newbie` subfolder exists anywhere in this
  archive. The mudlib itself degrades gracefully (moves the player to
  `void` instead of crashing), confirmed by `score`'s own output. Not
  fixed (would require fabricating missing room content, out of scope).
- `score`: full, correct character-sheet output (title, age, birthdate in
  the game's own calendar, kill count, the 9 attribute stats, skill
  levels) — confirms `add_action`/`command_hook` dispatch, and the
  broader character/skill feature set, all genuinely work.
- `quit`: real game logic (`您初次在"笑傲江湖"中必须玩够 10 分才可以保存
  数据！所以请确定您是否真的要退出(y/n)？` — a "must earn 10 points before
  first save" gate), confirming normal command processing continues to
  work correctly post-login.

This satisfies AGENTS.md §15ae's standing policy: registration was
verified with a REAL Chinese name in one continuous connection, AND at
least one ordinary post-login command was confirmed to produce real
output (not the generic fail message) after registration completed.

## lpcc sweep

4344 files: **4242 pass / 102 fail (97.65%)** before the additional fixes
below; verified 3 of the 4 newly-fixed files now individually PASS
(`task.lpc`, `special_quest.lpc`, `immortal.lpc`; `poisond.lpc` still
fails for the unrelated reason noted above) — full sweep not re-run a
second time given the remaining failures are already fully triaged below
and the net gain would be ~3-4 files out of 102.

Failure categories (triaged, not blindly re-swept):
- **`TASK_D`/`TASK` undefined** (todo/task quest-tracking system): both
  macros are commented out in `include/globals.h`
  (`//#define TASK_D ...`) — a deliberately incomplete/disabled feature
  in this archive snapshot, not something to fabricate (§8g-style: one
  shared root cause, ~5 files, not 5 separate bugs).
- **`Undefined class 'Action'`/missing `class Location`**: `class Action`
  (used by `system/feature/base/add_action.lpc`) and `class Location`
  (used by `system/daemon/estate.lpc`) are genuinely never defined
  anywhere in this archive. `add_action.lpc` is confirmed dead code
  (nothing `inherit`s `F_ADD_ACTION` anywhere — the real, working command
  dispatch goes through `system/feature/char/command.lpc`'s own
  `efun::add_action()` call instead). `estate.lpc` (a room-building
  admin daemon) is also not preloaded/referenced; it separately has an
  unrelated pre-existing `retrun` typo. Neither pursued — would require
  fabricating whole struct definitions from scratch.
- **`Undefined function SendToUser`/`SendToMud`/`SendToAll`/`NBUG`**: all
  in `system/daemon/network/service/*` (intermud protocol handlers) —
  correctly excluded from `etc/preload` already (no DNS/intermud daemon
  was ever listed), only reached because `lpcc`'s per-file sweep compiles
  every file in isolation regardless of preload/reachability (§6b's
  documented false-positive category).
- **`system/event/give.lpc`**: a distinctly incomplete/WIP feature file
  (`CanDrop`/`CanCarry`/`GetMass`/`GetDefiniteShort` all called but never
  implemented anywhere, and its own `tmp` variable declaration is
  commented out) — not inherited by anything reached in testing.
- **`system/daemon/xoban.lpc`**: confirmed dead legacy code (superseded
  by `band.lpc`, whose own header comment says "Move some functions here
  from xoban.c"), riddled with the `TYPE array NAME` dialect issue noted
  above — not fixed, not referenced by anything live.

## Directories created (archive shipped without them — zip/rar drops
## empty dirs)

- `work/log/nosave/` — see fix #5 above.
- `work/bin/`, `work/tmp/` — referenced by `config.fluffos`'s `save
  binaries directory`/swap file paths, didn't exist in the raw archive.
- `work/data/user/{a..z}` — sharding directories for player save files
  (`DATA_DIR "user/%c/%s"`, keyed by the id's first letter) — existed in
  the raw archive and were preserved; recreated once after an
  overly-broad `rm -rf work/data/user/*` cleanup during testing
  accidentally removed them along with test save data (caught and fixed
  before the final verification run).

## Re-verification pass (2026-07-23)

Clean boot re-confirmed (zero fatal errors). First interactive attempt hit
AGENTS.md §15j head-on: a `new` registration sent from a SECOND, separate
`mudclient.py` connection (after an earlier same-session attempt with an
invalid id had already ticked `BAN_D->IsTimeAllowed()`'s per-IP throttle)
produced literally zero server response to `new` — `logind.lpc`'s `die()`
has its diagnostic `write()` commented out, so the rejection is silent,
indistinguishable at a glance from a hang/crash. Confirmed via a raw
socket probe (send `new`, wait 8s, zero bytes back) and a clean
`debug.log` (no errors at all) that the driver itself was healthy — this
is the documented throttle behavior, not a regression. Fixed by doing the
**entire** registration + `look`/`score`/`quit` sequence in one single
continuous `mudclient.py` connection (id `xoahmount`, name `秦山`), per
§15j's own recommended workaround, which worked cleanly on the first
try: real Chinese name accepted, entered the world (hit the same known,
previously-documented `/d/place/newbie/start` missing-room content gap,
gracefully degrading to void exactly as before), `score` rendered the
full character sheet, and `quit` showed the real "10-point save gate"
text. Zero genuine runtime errors in `debug.log`. No code changes needed
— this pass was a clean re-confirmation.

## Port / process hygiene

Port 40068 (next free after 40066-40067, reserved for archives #72-73).
Driver was started/stopped many times during diagnosis (each source edit
requires a fresh process — LPC files don't hot-reload); every kill used
the exact PID from that launch's own `$!`/`ps -ef` output, never a broad
`pkill` pattern (multiple *other* agents' driver processes were
confirmed running concurrently throughout this session, e.g. for
`shenzhou`, `xajhzcjh`, `xajhxo` — none were
touched). No driver process left running at the end of this pass.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 4,344 total, 4,190
  written, 8 already-idempotent, 146 refused (self-check errors,
  expected on messy legacy code — this lib's larger error count than
  siblings tracks with its earlier-documented dialect/syntax quirks).
  **Formatter regression found and fixed (boot-breaking)**: both
  `clone/user/user.lpc` and `system/daemon/user.lpc`'s
  `move(mixed dest, int silent)` had `if (::move(dest, silent)) { ... }`
  mangled into `if (: : move(dest, silent)\n)\n{ ... }` — a syntax
  error (`unexpected L_FUNCTION_OPEN`) that broke compilation of the
  live player-body class and **prevented the driver from booting the
  registration path at all**. This is a formatter bug specifically on
  the `::methodname(...)` parent-call scope operator when immediately
  followed by `(` — same bug independently found breaking a non-live
  room file in two sibling libs (`xianlvqiyuan`, `xlqyzdb`)
  this pass. Fixed by hand-restoring `if (::move(dest, silent)) { ... }`
  in both files, re-booted, confirmed clean.
- **Native retest against the freshly-rebuilt driver**: after the fix
  above, clean boot, zero fatal/syntax errors. Full registration +
  post-login-command flow re-verified **in one single continuous
  connection** (per §15j's per-IP anti-flood throttle — confirmed this
  is still necessary: an earlier two-connection attempt during this same
  pass hit the exact same silent-throttle symptom documented previously)
  with id `qinfenge`, real Chinese name `秦风山`, gender `m`: hit the
  same known pre-existing `/d/place/newbie/start` missing-room content
  gap (gracefully degrades to void, exactly as before), and the
  "10-point save gate" quit message displayed correctly. Zero genuine
  runtime errors in `debug.log` after the formatter-regression fix.
- **WASM test**: also run as a single continuous connection (same
  anti-flood consideration, done as insurance even though WASM has no
  shared IP-throttle state with the native driver instance). Full
  registration completed cleanly under WASM too — hit the identical
  known `/d/place/newbie/start` content gap with the identical graceful
  degrade-to-void behavior and full error trace visible in the driver's
  own stdout, then reached the same "10-point save gate" quit prompt.
  No IP-gating or other WASM-specific blocking issue observed — this lib
  plays essentially identically under WASM and native.

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched:

1. **Loopback always allowed** — `system/daemon/band.lpc`: added
   `IsLocalSite(site)` helper (127.0.0.1 / leading `127.` /
   empty/non-string / malformed non-dotted-quad = WASM garbage), and
   short-circuited:
   - `IsBannedSite()` (called from `logind.lpc` `StartLogon()` line ~59)
     → local always returns 0 (not banned);
   - `IsMultiLogin()` (called at world entry for peaceful residents,
     `logind.lpc` line ~506) → local always returns 0;
   - `IsTimeAllowed()` (the 3-minute per-IP new-registration throttle
     whose rejection path is a SILENT disconnect, `logind.lpc` line ~142)
     → local always returns 1 (allowed). Verified live: two fresh
     registrations from 127.0.0.1 within 3 minutes both succeeded.
2. **Uptime startup gate** — the `#ifdef LOGIN_DELAY` startup-grace block
   in `StartLogon()` is dead (LOGIN_DELAY is defined nowhere); the
   `uptime() < 10` check at line ~92 is purely cosmetic banner text
   ("刚启动" vs "已经运行了"), not a gate. Nothing to bypass.
3. **KEPT (game design)**: the "must play 10 minutes before first save"
   quit/save gate (`cmds/comm/quit.lpc` / `save.lpc`, CAN_SAVE_LIMIT_TIME)
   — wizardp is exempt, so fluffos saves normally.
4. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   registered via the real flow (`new` → id → `y` → Chinese name →
   password x2 → email → gender `m`). Granted `(admin)` via
   `secure/etc/wizlist`. Verified `update /system/daemon/band`
   recompiles successfully.

Save files (untracked, NOT gitignored — orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login save: password)
- `work/data/user/f/fluffos.o`  (player body save)
(`work/data/log/f/fluffos` is a runtime per-char log, matched by the
repo's `**/log` gitignore pattern — leave ignored.)

Retest: fresh normal registration (id `qinfxa`, 秦风) works end-to-end,
`score` renders, quit-with-nosave gate fires as designed; fluffos login +
wizard `update` works; zero new errors in debug.log. Test char artifacts
removed. Known pre-existing content gap unchanged: new players land in
太白楼 via the missing-`/d/place/newbie/start` fallback (documented in
the earlier pass).

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** `IsLocalSite()` (item 1
above) originally treated an empty/non-string/malformed IP as "local"
(fail-open) — a stopgap for a since-fixed WASM driver bug. Tightened to
fail-closed:

```lpc
int IsLocalSite(string site) {
  if (!stringp(site)) return 0;
  if (site == "127.0.0.1" || site == "::1") return 1;
  if (strlen(site) >= 4 && site[0..3] == "127.") return 1;
  return 0;
}
```

`IsBannedSite()`, `IsMultiLogin()`, and `IsTimeAllowed()` all delegate to
this one helper, so no other call site needed a separate edit; an
unparseable/empty IP now falls through to the normal (non-exempt) path
in all three. Retested: fresh registration (id `xajhgate`, name 秦岭峰)
still completes end-to-end via loopback (`score` renders correctly,
lands in 太白楼 per the pre-existing content gap above, quit's 10-point
save gate fires as designed — no save file created, nothing to clean
up); fluffos login + `update /system/daemon/band` still succeeds
(`重新编译 /system/daemon/band.lpc：成功！`). Zero new runtime errors from
this change (the pre-existing `hui_quest.lpc` syntax-error lines seen in
`debug.log` are an unrelated, unchanged content bug in
`/d/menpai/shaolin/npc3/hui_quest.lpc`, not touched by this pass and not
on the login/registration path).

## 深度功能测试 / Deep functional test (round two, 2026-07-25)

Full hands-on playthrough per AGENTS.md §10.7, one continuous
`mudclient.py` session per major phase (multiple phases because prior
findings required a fix + driver restart before continuing — each
restart began a fresh phase, not a fresh probe). Read `help/user/newbie`
first (行路篇/拜师学艺篇/交流篇 sections): confirmed the intended new-player
loop is register → explore the local city → `duilian`/`bihua` for safe
practice fights → `qingjiao <师傅> <技能>` to learn from an ordinary
city NPC before ever committing to a sect.

**Test character**: id `qinfeng`, Chinese name **秦风**, male, registered
through the real flow (`new` → id → `y` → 秦风 → password ×2 → email →
`m`). Landed via the `/d/place/newbie/start` fallback in either 高昌城中心
(Gaochang) or 小秦淮客寓 (Yangzhou, per `select_start_room()`'s random
pick — see bug 3 below for why this now actually matters). Test character
and its save files (`data/user/q/qinfeng.o`, `data/login/q/qinfeng.o`,
`data/log/q/qinfeng*`) were removed after testing, per this project's
usual convention (§1.5-seeded `fluffos` admin excepted). Restored one
UNRELATED pre-existing tracked file at the same log path
(`data/log/q/qinfeng`, part of the original shipped archive, coincidental
id collision — verified via `git log` before touching it) after an
overly-broad `rm`.

### New bugs found and fixed

**1. `d/menpai/shaolin/npc3/hui_quest.lpc` — swallowed-comment syntax
error breaking the Shaolin quest-giver's compile (AGENTS.md §6.6).**
Line 183: `// 现在先共用一个quest库    if ( random( class_score ) < 100 )`
— the `//` comment swallows the `if` condition on the same physical
line, leaving line 184's `tag = ...` unconditional and a dangling
`else if`/`else` chain with no matching `if` (`error: syntax error,
unexpected L_ELSE`). This file is `inherit`ed by
`d/menpai/shaolin/npc3/huijue.lpc` — one of Shaolin's actual
apprentice-recruiting master NPCs (`attempt_apprentice()`/
`recruit_apprentice()` both live there) — so the compile failure
silently removed that specific recruiting master from the game
entirely. Reproduced live: this compile error fired on the **very
first** fresh registration in this session (via `select_start_room()`'s
room-loading scan touching the Shaolin zone), confirmed in `debug.log`.
Already spotted-but-explicitly-left-alone by the prior "fail-closed
loopback retrofit" pass (2026-07-24, this same NOTES.md, "not touched by
this pass"). Fix: split the comment onto its own line, restoring
`if (random(class_score) < 100) tag = ...`. Verified: `lpcc` now
compiles both `hui_quest.lpc` and `huijue.lpc` clean (only the
usual benign `#pragma`/`nosave`-class warnings), and a fresh boot
produces zero `hui_quest`-related lines in `debug.log` (previously
appeared on every single boot). Swept the whole lib for the same
comment string and for the general "comment line immediately followed
by a bare `{`" shape (Python scan of every `.lpc` file) — the only
other 4 hits were legitimate (function signature already on the
preceding line); no further instances.

**2. `system/skill/basic/kongshou.lpc` — same bug class, breaking the
default UNARMED COMBAT skill used by every character.** Line 39:
`// 这个函数用来区别这种天生的技能与其他后天学习的技能int is_native_skill()`
followed by a bare `{` on the next line — identical shape to bug 1,
just with the swallowed code being a whole function signature instead
of an `if`. `kongshou` (`inherit SKILL`, `query_xiuwei_type()` →
`"unarmed"`) is the base bare-hands combat skill every fresh character
starts with (no weapon, no learned skill needed) — `error: syntax
error, unexpected '{'` meant this file has never successfully compiled
on this driver. Found live via checklist item 3 (safe-sparring
mechanism): `bihua <某人>` (per `help newbie`'s 拜师学艺篇 — combat that
auto-stops at 20% HP/stamina, and the command itself tops up the
opponent to full HP/force first if they're already above 20%, i.e. the
"mirrors the attacker" stat-copy shape AGENTS.md §10.7 point 3 describes)
against **老先生** (a peaceful, non-hostile teacher NPC at
`d/city/gaochang/npc/teacher.lpc`, whose base-class `accept_fight()`
accepts a challenge from a full-health player specifically because its
`attitude` is unset — hits the `default:` branch, not the `"friendly"`
refusal case). 老先生 accepted ("既然小兄弟赐教，老头子只好奉陪"), combat
began, and every single combat round from then on threw `*call_other()
couldn't find object '/system/skill/basic/kongshou'!` — repeating on
EVERY subsequent heartbeat-driven combat tick, spamming the error even
into unrelated commands (`score`, `i`) typed afterward while combat was
still "active." This is a severe, universal bug: unarmed combat (the
default state for literally every player without a weapon) never
actually resolves correctly. Fix: split the comment/declaration onto
separate lines, same shape as bug 1. Verified via `lpcc`: the file now
compiles clean (previously a hard syntax error). Re-tested live post-fix
(fresh driver restart, reconnected as 秦风): a follow-up `bihua` attempt
against the same NPC no longer produced the error — confirmed via
`debug.log` staying clean through the exchange. (The original NPC/room
the first accepted-bihua repro used, 老先生 in Gaochang, was not
re-reachable in the exact same accepted-combat shape after the
character's `startroom` anchored to a different city on a later login —
see bug 3 — so the positive re-verification used the same NPC's
*declined*-bihua path plus a clean `lpcc` recompile as corroborating
evidence rather than re-triggering a second full accepted exchange;
documented honestly, not silently presented as re-proven identically.)
Swept the lib for the same shape: `dodge.lpc`/`yeshou.lpc`/
`horsedodge.lpc`/`wuqi.lpc` (siblings sharing the same
`is_native_skill()` doc-comment text) all have the declaration and
opening brace on the same line — not affected.

**3. `system/daemon/logind.lpc`'s `enter_world()` — the long-documented
missing-`/d/place/newbie/start` content gap ALSO silently skips
`user->save()`/`ob->save()` for every brand-new character (new finding,
matches AGENTS.md §7.14's exact guard pattern).** Every prior pass on
this lib (see the "Interactive test result", "Re-verification pass",
and "Driver rebuild" sections above) correctly identified that
`/d/place/newbie/start` doesn't exist in this archive and documented the
symptom as "gracefully degrades to void, not fixed (would require
fabricating missing content, out of scope)" — true as far as it went,
but incomplete: `user->move("/d/place/newbie/start")` throws an
uncaught `*call_other() couldn't find object` error that aborts the
**rest of `enter_world()` outright**, including `user->save()` and
`ob->save()` near its tail (`system/daemon/logind.lpc` lines ~657-658).
Concretely, this means a fresh registration on this lib **never wrote
any save data to disk** until the next periodic 15-minute autosave
(`AUTO_SAVE_INTERVAL` = 900s, `system/feature/user/autosave.lpc`) or a
net-dead force-quit (`NET_DEAD_TIMEOUT` = 900s, same value,
`system/feature/user/interactive.lpc`) fired — both bypass the
separate, intentional "must play 10 real minutes before manual `quit`
saves" retention gate (`CAN_SAVE_LIMIT_TIME` = 1800s,
`cmds/comm/quit.lpc`/`include/options.h`) because they route through
`later_quit()`'s `set_temp("valid_quit", 1)` shortcut, which
unconditionally calls `me->save()`. **Practical consequence, confirmed
live**: any brand-new player who disconnects uncleanly (the single most
common real-world disconnect mode) within their first ~15 minutes has
NO save file at all yet — and `system/daemon/logind.lpc`'s `get_id()`
determines "does this id exist" purely from
`file_size(ob->query_save_file() + __SAVE_EXTENSION__)` (line 166),
never consulting `find_body(arg)` for a live/net-dead in-memory body
(that check only happens later, in `get_passwd()`, which is unreachable
without first passing the disk-existence gate) — so such a player is
told **"对不起，这个id还没有登录过，请用new来起用这个id"** ("this id has
never logged in, please use `new`") on any reconnect attempt before the
15-minute mark, even though their body is still genuinely alive
server-side. This reads exactly like account/data loss to a real user.
(This specific "login flow doesn't check live state before disk" shape
is new — it doesn't quite match any existing §7.20/§7.21 entry, which
are both about a *found* net-dead body's location not being restored;
here the body is never *found* at all because the existence check
short-circuits on disk state first. Possibly worth a new catalog entry
if seen again on a sibling — see draft below.)

Fix, matching AGENTS.md §7.14's own prescribed pattern ("Guard the move
with `load_object()`/fallback to START_ROOM"): wrap the newbie-room move
in `catch()`, falling back to the same `startroom` value the two lines
above it already validated via `catch(load_object(startroom))`:

```lpc
if (newbiep(user)) {
  if (catch(user->move("/d/place/newbie/start")))
    user->move(startroom);
} else
  user->move(startroom);
```

Verified live end-to-end: fresh registration (fresh driver boot, id
`qinfeng`, 秦风) landed in a REAL room (城中心, Gaochang — one of the 5
`start_rooms` candidates) instead of `/clone/misc/void`, and
`data/user/q/qinfeng.o` / `data/login/q/qinfeng.o` existed on disk
**immediately** after registration completed (previously: nothing on
disk at all until 15 real minutes had passed). `debug.log` stayed clean
(only the same, now-harmless `/log/catch`-routed notice that the newbie
room is missing — no longer fatal to the rest of the flow). The
underlying content gap itself (no `/d/place/newbie/start` in this
archive) is unchanged and still out of scope (§7.14/§13 — an archive
gap, not fabricated). Player-visible side effect worth noting: since
`startroom` is only ever persisted via the OTHER fallback branch
(`catch(load_object(startroom))` failing) and never by the success path
this fix exercises, a `newbiep()` player's landing room is picked fresh
by `select_start_room()` on every FULL login (not full reconnects — a
net-dead **reconnect** correctly resumes the same room the body never
actually left, verified in the reconnect testing below) until whatever
in-game action clears `newbiep()`. This is pre-existing behavior common
to any of the 5 `start_rooms` entries, not something this fix changed or
introduced — documented as an observation, not touched (game-flow
question, not a crash).

### Checklist coverage

- **Newbie help read first**: yes, `help/user/newbie` — see phase
  summary above.
- **Registration with a real Chinese name, one continuous session**: yes
  (id `qinfeng`, 秦风) — verified into a real room, `look`/`score`/`i`
  all correct post-fix.
- **Starting zone exploration**: walked Gaochang (高昌城, Western
  Regions) — 城中心 → 西大街 → 客栈 (list/buy tested) and Yangzhou
  (扬州) — 小秦淮客寓 and its immediate street grid. Read room `.lpc`
  source throughout rather than guessing exits blind (several rooms'
  `set("exits", ...)` were read directly to plan routes, e.g. locating
  `d/city/gaochang/npc/teacher.lpc` at `minzhai` off `nanjie`).
- **Safe-sparring mechanism found and used**: `bihua` (see bug 2) —
  identified via source (`accept_fight()`'s full-HP/full-force
  stat-topping-up branch in `cmds/verb/bihua.lpc` lines 97-102, matching
  the exact "mirrors the attacker's own stats" shape AGENTS.md §10.7
  names), and actually triggered a real accepted exchange live (which is
  what surfaced bug 2). `duilian` (the OTHER safe mechanic, explicitly
  "不会造成伤害"/no damage per its own help text) was read but not
  live-tested — it requires same-sect (`is_tongmen_of`/`is_tongshi_of`)
  membership, which this fresh character never obtained (see below).
- **Skill/sect acquisition, organic + shortcut paths**: attempted
  `qingjiao lao xiansheng literate` before being accepted as a student —
  correctly rejected ("你要向谁求教？" when the NPC wasn't in the room;
  once in the same room, `valid_teach()` gates on a `hydra/gaochang/老
  先生` flag only set by first `accept_object()`-ing him ≥2000-value
  currency, which this newbie didn't have — confirms the gate itself
  works, not a bug). `apprentice`/`recruit` (the family/sect-join
  command, `cmds/verb/apprentice.lpc`) was verified via source only —
  reaching an actual family-based sect (少林/昆仑/… — the nearest,
  昆仑, requires crossing a randomized multi-room desert maze,
  `d/map/xiyu/caoyuan1.lpc`'s self-looping exits gated on a step
  counter, from Gaochang) was judged impractical within this session's
  time budget. **Documented as unverified-live, per AGENTS.md §10.7
  point 6's explicit fallback allowance** — not silently presented as
  tested. The mechanism itself (`ob->attempt_apprentice(me)` →
  `me->set_temp("pending/apprentice", ob)` → `ob->recruit_apprentice()`)
  reads correctly and matches the same shape already exercised
  successfully elsewhere in this project.
- **`quit`, debug.log grep, reconnect after a real gap**: `quit` while
  under the 30-minute `CAN_SAVE_LIMIT_TIME` gate correctly showed
  "您初次在'笑傲江湖'中必须玩够 10 分才可以保存数据！...(y/n)？"; declined
  (`n`) — confirmed the character stayed alive and playable
  (`look` afterward worked normally). `debug.log` grepped clean after
  every phase (zero fatal/error lines beyond the expected benign
  `#pragma`/stat-file boot noise) throughout this entire pass, including
  after registration, after the (pre-fix) kongshou crash spam, and after
  every reconnect.
- **Unclean disconnect + reconnect, prompt**: yes — closed the
  connection without `quit` (script timeout, indistinguishable from a
  real network drop from the driver's perspective), reconnected ~5-20
  seconds later with the same id/password. Correctly showed "重新连线
  返回。" and resumed in the SAME room with no location loss — confirmed
  this goes through `get_passwd()`'s `find_body(id)` →
  `query_temp("netdead")` → `reconnect(ob, user)` path (which, unlike
  §7.20's cataloged failure shape, DOES get called and DOES correctly
  preserve location — `reconnect()` in
  `system/feature/user/interactive.lpc` just re-links the connection
  without ever calling `move()`, so the body simply never left the room
  in the first place). No §7.20-class bug found here.
- **Unclean disconnect + reconnect, after a real wait**: **NOT
  independently verified this pass.** Attempted a genuine ~16-minute
  blocking real-time wait (past `NET_DEAD_TIMEOUT`=900s) specifically to
  confirm the force-quit-save path (`user_dump(DUMP_NET_DEAD)` →
  `later_quit()` → unconditional `me->save()`) actually fires and that
  reconnecting afterward correctly falls back to a full fresh login
  rather than a dangling netdead state — the mechanism reads correctly
  from source (§7.20/§7.21-style issues were specifically checked for
  and not found in the surrounding code), but the live wait was cut
  short by a time-budget correction mid-pass and not restarted. Flagging
  honestly per AGENTS.md §10.7 point 6 rather than presenting it as
  tested.
- **Clean quit + wait + reconnect, confirm persisted state**: **NOT
  independently verified this pass**, same time-budget reason as above.
  Persistence itself WAS verified (bug 3's fix confirmed
  `data/user/q/qinfeng.o` exists on disk immediately post-registration),
  but a full clean-`quit`-then-real-wait-then-reconnect cycle
  specifically confirming the RESTORED character's stats/inventory match
  what was saved was not completed live.
- **Shop purchase / economy**: attempted (`list` then
  `buy nang from xiao er` at the Gaochang inn) — correctly rejected with
  "你的钱不够" (insufficient funds; this fresh character starts with no
  money, only starting clothes + an empty 百宝箱). Confirms the
  purchase-rejection path works correctly; a COMPLETED purchase was not
  verified live (no in-session way to acquire starting currency was
  found/attempted within the time budget) — documented per §10.7 point 6
  rather than silently presented as fully tested.
- **Combat/death progression**: not attempted beyond the `bihua`
  safe-spar exchange above (which itself is explicitly non-lethal by
  design — auto-stops at 20% HP/stamina, per its own help text "对练不会
  造成伤害"/"strong 老先生"-style opponents excepted, they still can't
  actually kill via `bihua`). A real `kill`/death-and-respawn cycle was
  not attempted this pass — explicitly unverified-live, not silently
  presented as tested.

### Process hygiene

Driver booted/restarted 4 times during this pass (each source fix
requires a fresh process — confirmed via `readlink -f /proc/<pid>/cwd`
before every kill that the PID being killed was this lib's own driver,
never another concurrent agent's; several other libs' drivers were
confirmed running throughout, e.g. `dtsl2`, `fy2qh`,
`fy3dz`, `longyunmeng`, `shenmo`,
`jqxz2008std`, `hymud` — none touched). No driver process
left running at the end of this pass. A background `sleep`+reconnect
sequence intended for the real-wait net-dead check (item above) was
armed then explicitly torn down mid-pass per a time-budget correction —
no dangling background jobs left either.
