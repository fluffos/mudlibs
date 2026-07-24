# fengyun3dianzang — 风云典藏版 (Fengyun "Collector's Edition")

Archive: `archives/风云III典藏版.rar` (archive #98). Byte-identical duplicate
`archives/风云III典藏版 (1).rar` confirmed via `md5sum`
(`fb4d9f21939b6a0c4be33aa37f29f581` for both) — only the primary was
processed, per AGENTS.md's "Duplicate archives" table. Port: **40090**.
Status: **done** (boots clean, full registration flow verified end-to-end
four times with real Chinese names, `look`/`score`/`quit` all confirmed).

## What this is

The archive's own `classic.txt` (a readme, GB18030-encoded) identifies this
as **风云 3.8.0** ("Fengyun 3.8.0"), an unofficial fan compilation built on
top of "风云3.7.4" ("在风云3.7.4版本的基础上添加了新收集的【风云工作室】
原创程序" — "adds newly-collected original Fengyun Workshop code on top of
the 3.7.4 base") — i.e. a "collector's edition" bundle of previously
unreleased/abandoned 风云工作室 (Fengyun Workshop) content, not an official
numbered release. Archive root nested at `fy3dcb/<mudlib>/`; the mudlib
directory itself was stored in the RAR with a **raw GBK-encoded directory
name** (bytes `b7 e7 d4 c6 b5 e4 b2 d8 b0 e6`, decoding to `风云典藏版`
under GB18030) rather than proper UTF-8 — `unrar` (UTF-8-locale-aware for
file *contents*) doesn't transcode filenames themselves, so the directory
landed on disk as mojibake. Renamed it to the correctly-decoded `风云典藏版`
before running `convert_lib.sh` (which only transcodes file *contents*, not
paths) — confirmed via `python3 -c "os.listdir(...).encode(...).decode('gb18030')"`
that this was the only such filename in the whole archive (no other
garbled paths found via a tree-wide scan for surrogate-escaped bytes).
`config.fy3`'s own `name :` field confirms **风云典藏版** as the in-game
mud name, matching both the archive's own filename and the directory name
— no slug rename needed beyond the ASCII-safe `fengyun3dianzang`.
~3,948 raw files, 3,765 after the `.c`→`.lpc` rename.

## Lineage: confirmed via diff, not assumption, before doing anything else

Per the task brief, checked this archive's core files against every
previously-shipped "风云" (Fengyun)-themed lib in this repo (`fengyun434`
#14, `fy2005` #16, `fy2` #17, `zzfy` #30, `moniHuafu` #57) **and** against
the concurrently-running sibling agent's own raw extraction for archive #97
(`fengyun3xiuding`, "风云III修订版" / Fengyun III Revised Edition) —
comparing raw `.c` files byte-for-byte (CRLF-stripped, since some copies
use CRLF and others don't) rather than trusting shared branding/title
alone:

| file | vs `zzfy` (#30) | vs `moniHuafu` (#57) | vs `fengyun3xiuding` (#97, raw, concurrent) |
|---|---|---|---|
| `adm/obj/master.c` | **identical** (0 diff) | — | **identical** (0 diff) |
| `adm/obj/simul_efun.c` | **identical** (0 diff) | 4 lines diff | **identical** (0 diff) |
| `adm/daemons/securityd.c` | 541 lines diff | 76 lines diff | **identical** (0 diff) |
| `adm/daemons/logind.c` | 499 lines diff | 854 lines diff | 389 lines diff |
| `adm/simul_efun/chinese.c` | **identical** (0 diff) | **identical** (0 diff) | **identical** (0 diff) |

This confirms two things:
1. **This is the same 风云3 engine lineage** already processed as
   `zzfy`/`moniHuafu` (archives #30/#57) — `master.c`/`simul_efun.c`/
   `chinese.c` are byte-identical or near-identical across all three, the
   same core-engine-vs-site-skin split already documented in those libs'
   own NOTES.md (each site customizes `logind.c`/`securityd.c`, the rest
   of the engine is shared).
2. **This archive is an unusually close sibling of the concurrently-
   processing #97** (`fengyun3xiuding`) specifically — `master.c`,
   `simul_efun.c`, `securityd.c`, AND `chinese.c` are ALL byte-identical
   between the two, with only `logind.c` (site banner/messages) diverging.
   "典藏版" (Collector's Edition) and "修订版" (Revised Edition) are
   evidently two different content/documentation packagings of what is
   functionally the *same* underlying `.7.4`-based 风云3 codebase, not
   independent forks. **Flagging for the cross-check the task brief
   requested**: since #97 was still mid-processing at the time this lib
   was done (its `work/` didn't exist yet, only `raw/`), a later diff
   between `libs/fengyun3xiuding/work/` and this lib's `work/` (once #97
   lands) is worth doing — any fix #97's agent found in `master.lpc`/
   `simul_efun.lpc`/`securityd.lpc`/`chinese.lpc` almost certainly applies
   here verbatim too (and vice versa), given the byte-identical raw
   starting point for those four files.

Given the confirmed engine match to `zzfy`/`moniHuafu`, every fix pattern
those two libs' own NOTES.md documented was checked directly against this
archive's actual source (not reapplied blindly) before the first boot
attempt.

## Fixes applied

1. **AGENTS.md §15h (GBK byte-range Chinese detection)** — same shape as
   every other lib in this lineage, confirmed present verbatim:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`) → CJK Unicode
     codepoint range check (`strlen(str)>=1 && str[0] >= 0x4e00 && str[0]
     <= 0x9fff`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
     (`< 2 || > 12`) halved to character count (`< 1 || > 6`) — the
     message ("必须是一到六个中文字", "must be 1 to 6 Chinese characters")
     already stated the correct character bound; removed the `i%2==0`
     even-byte-offset gate so every character position is actually
     checked instead of every other one.
   - Verified via a real interactive registration test: **four** different
     real Chinese names accepted across two driver sessions (秦风, 秋月,
     令狐冲, 任我行 — 1-, 2-, and 3-character names), each reaching the
     actual game world.

2. **AGENTS.md §15p (DNS/intermud daemon preload exclusion)**:
   `adm/etc/preload` listed `/adm/daemons/network/dns_master` — removed it
   (unreachable boot-server handshake in this sandboxed environment).

3. **AGENTS.md §15u (dormant phone-home license-check neutralized)**:
   `adm/daemons/securityd.lpc`'s `checking_status(mapping info)` is a
   circa-2000 anti-piracy check that, if a matching magic string
   (`crypt(content, "jqp5JO9YfN2Dk") == "jqp5JO9YfN2Dk"`) is ever seen in
   an inbound payload, deletes the ENTIRE mudlib (`rmhirdir("")`) and shuts
   down the driver (`shutdown(0)`). Confirmed genuinely *reachable* (unlike
   the moniHuafu instance, which was unreachable) — called from
   `adm/daemons/network/services/gtell.lpc`'s `incoming_request()`, itself
   part of the intermud/DNS subsystem gated behind `dns_master` (excluded
   above, fix #2), so unreachable in this sandbox regardless. Neutralized
   the destructive body as cheap insurance per §15u's standing guidance
   (function kept, in case anything depends on the call succeeding
   harmlessly; body replaced with a no-op).

4. **A `\bstatic\b`→`nosave` blanket-sed counterexample (AGENTS.md §3's
   `moniHuafu` precedent), found independently in THREE files here**:
   the raw archive had one real `log/static/` directory on disk containing
   `CALL_PLAYER`, `CRASHES`, `promotion`, `SUICIDE` — but `convert_lib.sh`'s
   blanket `static`→`nosave` sed rewrote the *string literal* path
   references to these files too, since they contain the bare word
   "static" as a path segment, not the keyword:
   - `adm/obj/master.lpc`: `log_file("static/CRASHES", ...)` → had become
     `"nosave/CRASHES"` (3 call sites).
   - `adm/daemons/securityd.lpc`: `log_file( "static/promotion", ...)` →
     had become `"nosave/promotion"`.
   - `cmds/std/suicide.lpc`: `log_file("static/SUICIDE", ...)` → had
     become `"nosave/SUICIDE"`.
   Confirmed via the raw pre-conversion GBK bytes (`grep -a` needed, since
   `grep` treats the GBK files as binary) that all three originally read
   `"static/..."`. Reverted all three back to `"static/..."` to match the
   real on-disk directory (no `/log/nosave/` directory exists or was
   needed). Cross-checked the whole tree for any other `"static` (opening
   quote immediately before the word) occurrence — these three were the
   only ones.

5. **Two genuine pre-existing typos found via the `lpcc_check.sh` sweep**
   (unrelated to the conversion pipeline, present in the raw archive):
   - `d/fy/npc/gangster2.lpc`'s `init()`: used `for(i=sizeof(ob)-1; ...)`
     with `int i;` never declared (only `object *ob;` was) — added the
     missing declaration. Checked for the same shape (`for(i=sizeof(ob)-1`
     with no preceding `int i` in the surrounding lines) elsewhere in the
     tree; this was the only file affected.
   - `daemon/class/bonze/rainbow-zhi/changhongjingtian.lpc`'s `perform()`:
     a multi-line `if(!target || !target->is_character() ||
     !me->is_fighting(target)` was missing its closing `)` before the
     `return notify_fail(...)` — added it. (The adjacent `"...\n"NOR`
     string-literal-immediately-followed-by-macro idiom elsewhere in the
     same statement is NOT a bug — confirmed this driver supports it via
     several dozen other passing files using the identical `"text"NOR`/
     `"text"HIR` pattern elsewhere in the lib; the *only* real defect here
     was the missing paren.)

6. **AGENTS.md §15s (message() 4th-argument type rejection)**, found via
   the lpcc sweep and confirmed reachable in real gameplay (an NPC horse
   moving into a room and triggering its `init()`): `adm/simul_efun/
   message.lpc`'s `tell_room(mixed ob, string str, object *exclude)`
   unconditionally called `message("tell_room", str, ob, exclude)` — when
   called with only 2 args (the overwhelmingly common case, e.g.
   `d/qianfo/tanghuai.lpc`'s `init()`), `exclude` defaults to `int 0`,
   which this driver's `message()` efun rejects at the VM dispatch level
   ("Bad argument 4 to EFUN message() Expected: object, array, Got:
   int(0)") even though `f_message()`'s own C++ body would tolerate it
   internally (confirmed by reading `efuns_main.cc` — the rejection
   happens in `interpret.cc`'s generic per-efun argument-type check, a
   layer earlier than `f_message()`'s own lenient switch). Fixed with
   `exclude || ({})`. Checked the other functions in the same file
   (`message_vision`, `shout`, `write`, `say`) for the same pattern:
   `shout()`'s `message("shout", str, users(), this_player())` has the
   same theoretical exposure if `this_player()` were 0, but its only
   caller (`cmds/std/shout.lpc`, a player command) guarantees a live
   player context, so left as-is (verified, not just assumed).

7. **AGENTS.md §8e (`tail()` is not a real efun)**: `cmds/adm/tail.lpc`
   (an admin-only, non-preloaded command) called bare `tail(file)`.
   Reimplemented in plain LPC per the catalog's own snippet
   (`read_file`+`explode`+slice-last-N-lines+`write`). First attempt
   forward-referenced the new helper from `main()` before its definition
   (AGENTS.md §8b) — the lpcc sweep caught it as `Undefined function
   do_tail_lpc`; fixed with a forward declaration.

## What was confirmed NOT needed (checked directly, not assumed)

- **§4** (lazy security-daemon `load_object` in `valid_read`/`valid_write`
  recursing to a stack overflow): `master.lpc`'s `valid_write` already
  guards with `find_object(SECURITY_D)` and never calls `load_object`
  there; `valid_read` is unconditionally permissive (`return 1;`). No
  recursion risk present.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both already defined
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c** (`valid_read`/`valid_write` clobbering the caller with
  `this_player()`): `securityd.lpc`'s `valid_write` uses `geteuid(user)`
  directly, no unconditional `this_player()` override.
- **§8d/§15o** (`get_include_path()` for local per-directory headers):
  all `#include <x.h>` references in this lib resolve to real files under
  the global `/include` tree (`ansi.h`, `dbase.h`, `weapon.h`, `armor.h`,
  `command.h`, `origin.h`, `condition.h`, `move.h`, `name.h` all confirmed
  present there) — no local-directory-header case exists, so no
  `get_include_path()` override was needed.
- **§8f** (`TYPE * a, b;` array-modifier-doesn't-propagate): several
  matches found (`object *inv, me, room;` etc.) but every one checked was
  intentional — the un-starred trailing variables are genuinely assigned
  scalar values (`this_player()`, `find_object()`) a few lines later, only
  the first variable is ever assigned an array. Not the Dead Souls bug.
- **§15** (nitan-family shared-simul_efun-dbase architecture bug): this
  lineage already has a real, local `feature/dbase.lpc` with genuine
  per-object `set`/`query`/`delete` methods (inherited via `F_DBASE`),
  confirmed by reading the file directly — not the bare-simul_efun-call
  storage pattern.
- **§15ae** (`private nomask` command-hook breaking `add_action`
  dispatch): `feature/command.lpc`'s `command_hook` is declared `nomask`
  only, no `private` — confirmed via direct read before the first boot
  attempt, and empirically via four successful post-login `look`/`score`
  tests.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode` don't exist on this
  driver build): zero occurrences anywhere in the tree.
- **§15ar** (`commandd.lpc`-style dead `sscanf(".c$")` pattern): no
  `commandd.lpc` exists in this lineage; the equivalent `adm/daemons/
  cmd_d.lpc`'s `rehash()` uses `sscanf(cmds[i], "%s.lpc", cmds[i])` —
  already correctly matching post-rename, having been auto-fixed by
  `convert_lib.sh`'s literal-`.c"`-reference sed pass (confirmed the
  original read `"%s.c"`).
- **§15ai** (a second gate calling `shutdown(1)` once `dns_master` is
  excluded): no `DNS_MASTER` reference anywhere in `logind.lpc`, and no
  `shutdown(1)` call anywhere in the login/registration path.
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`): `create()`
  here is a single harmless `write()` line, no destruct/reload dance.
- **§15ao** (a `switch` with only `default:`): `master.lpc`'s `connect()`
  takes no arguments and has no `switch` at all.
- **§15x** (hardcoded `MUD_PORT` mismatch): no such constant defined or
  dispatched on anywhere in this lib.
- **§15m** (unguarded `restore()` on stale/corrupted save data crashing a
  daemon's `create()`): `chinesed.lpc`'s and `emoted.lpc`'s `data/*.o` save
  files both parse as valid UTF-8 with the expected leading `#/path` header
  comment (standard `save_object()`/`restore_object()` format); no crash
  observed on any of the four boots run this session.
- **ftpd's `#include <flock.h>` (§15ai's note)**: `ftpd` is not preloaded
  and not referenced anywhere reachable; not excluded since it was never a
  risk to begin with.

## Known remaining issues (not fixed, real archive content gaps or
genuinely dead legacy code — not driver-compat bugs)

- **4 bulletin-board objects reference rooms that don't exist anywhere in
  this archive** (§13-shaped, confirmed via `find` — the directories
  simply aren't present): `obj/board/wizard_b` → `/d/wiz/hall`,
  `obj/board/paiboard` → `/u/residence/xiaoqi`, `obj/board/query_b` →
  `/d/wiz/entrance`, `obj/board/wizard_j` → `/d/wiz/jobroom`. None of
  these boards are preloaded, so this is pure lpcc-sweep noise, not a
  live gameplay defect.
- **9 legacy standalone network-service daemons under `adm/daemons/
  network/`** (`ms`/mail server, `userid`, `pingtcp`, `name_server`,
  `mail_serv`, `netmail`, `telnetd`, `pingd`, `inetd`) fail to compile —
  each needs headers (`config.h`, `mailer.h`, `daemons.h`, `uid.h`, etc.)
  that don't exist anywhere in this archive. None are preloaded; the only
  other references to their paths anywhere in the tree are inert macro
  *definitions* in `include/net/daemons.h`/`telnet.h` (path constants,
  never actually `load_object()`/`call_other()`'d). A genuine pre-existing
  incompleteness in the original archive (this whole intermud-mail/telnet
  subsystem was apparently never fully wired up even in period), not
  something our pipeline broke.
- **`/adm/simul_efun/object` lpcc-sweep failure** ("Invalid simulated
  efunction override" on its `efun::destruct()` line) is a pure §6b/§14
  sweep artifact — this file is `#include`d into `simul_efun.lpc`, not
  loaded standalone, so `main_file_name()` reports the fragment itself
  instead of `SIMUL_EFUN_OB` only when `lpcc` compiles it in isolation.
  Confirmed via `grep` that this exact error string never appears in the
  real driver boot's `debug.log` across any of the four test sessions.

## lpcc_check.sh results

Final sweep: **3750/3765 pass (99.6%)**. The 15 remaining failures are
exactly the "known remaining issues" above (4 missing-room boards + 9
dead network daemons + 1 sweep-only `#include`-fragment artifact + the
`/cmds/adm/tail` reimplementation is now passing, not counted as a
failure — see the fix list above). Started at 18 failures before the
gangster2/changhongjingtian/tail.lpc fixes (§ fixes 5 and 7 above),
reduced to 15 (all content-gap/dead-code, none driver-compat bugs).

## How to run

```
cd libs/fengyun3dianzang
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40090 --timeout 25 \
  --send "yourid" --send "y" --send "你的中文名" --send "m" --send "0" \
  --send "look" --send "score" --send "quit"
```
(`--send` sequence: English id (3-10 lowercase letters) → `y` to confirm
new-character creation → a real Chinese name (1-6 characters) → `m`/`f`
for gender → `0`/`1`/`2`/`3` to pick 汉/苗/满/蒙古 nationality — no
password step exists in this lib's registration flow, confirmed by reading
`logind.lpc`'s full `input_to` callback chain rather than assumed from
prompt text, per the task's standing "read the actual callback" guidance.)

Verified across four full registration + `look` + `score` + `quit`
sessions this pass, with names 秦风 / 秋月 / 令狐冲 / 任我行 — all reached
the correct nationality-specific starting room, all `look`/`score` output
rendered correctly, all `quit` cleanly dropped inventory and disconnected.
Zero real errors in `debug.log` across all four sessions (only benign
compile warnings: "Illegal to declare nosave function" from `nosave`
functions -- §3's own footnote that this warning is harmless -- and
"Unused local variable").

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 3765 `.lpc` files; 3741
  reformatted, 2 unchanged, 22 refused (self-check `errors`, expected).
- **Native retest against rebuilt driver**: clean, zero fixes needed.
  Full registration + `look`/`score`/`quit` re-verified with a fresh
  real Chinese name (任我行/一灯), zero debug.log errors.
- **WASM test — 1 WASM-specific bug found + fixed** (does NOT reproduce
  natively, confirmed by re-testing the unpatched code natively first):
  `adm/daemons/securityd.lpc`'s `create()` called `resolve(
  query_host_name(), "resolve_callback")` — pure decorative intermud
  housekeeping — as its FIRST statement, before allocating the
  `wiz_status` mapping used by `get_status()` (called on every single
  login via `wizhood()`). Under WASM there is no DNS resolver
  (`*resolve: DNS resolver is not available`, one of the documented
  no-sockets-package WASM restrictions), and since that error was
  uncaught inside `create()` itself, it aborted the rest of the
  function — `wiz_status` was left permanently un-allocated (`0`), so
  every subsequent login crashed with `*Value being indexed is zero.`
  in `get_status()`. Fixed by reordering `create()` to build
  `wiz_status` first and wrapping the `resolve()` call in `catch()` as
  a second layer of defense — this is a different, non-blocklisted
  WASM restriction than the documented `query_ip_number()` IP-format
  issue (see AGENTS.md), so it was fixed rather than just documented.
  Re-verified clean both natively (no regression) and under WASM: full
  registration with a real Chinese name (令狐冲), `look`, and `quit` all
  completed with zero errors, boots+plays fully under WASM now.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` `is_banned()`
  (~line 52) — short-circuit for non-string / empty / `127.0.0.1` /
  `localhost` / `127.`-prefix. NOTE: in this snapshot `is_banned()` has
  NO live caller in the login chain (unlike sibling `fengyun3xiuding`,
  whose logind calls it) — patched for consistency in case it gets
  re-wired.
- **Uptime gate / anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos`, display 浮浮, status `(admin)` via
  `fluffos (admin)` appended to `/adm/etc/wizlist`. **Deviation: this
  lineage snapshot has NO password step at all** (registration asks only
  id/中文名/gender/ethnicity; re-login asks only a y/n confirm) — so the
  standard `Mud@2026` password does not apply. Verified re-login +
  `update /adm/daemons/combatd` → 成功.
- **Retest**: fresh normal registration (秦风) works, `look`/`score` OK,
  test char saves removed. Pre-existing content error (unrelated to this
  pass): `/u/guanwai/shop` create() errors when an NPC wanders into it.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/fengyun3dianzang/work/data/user/f/fluffos/fluffos.o`,
  `libs/fengyun3dianzang/work/data/login/f/fluffos/fluffos.o`.
