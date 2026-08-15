# fy3dz — 风云典藏版 (Fengyun "Collector's Edition")

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
— no slug rename needed beyond the ASCII-safe `fy3dz`.
~3,948 raw files, 3,765 after the `.c`→`.lpc` rename.

## Lineage: confirmed via diff, not assumption, before doing anything else

Per the task brief, checked this archive's core files against every
previously-shipped "风云" (Fengyun)-themed lib in this repo (`fengyun434`
#14, `fy2005` #16, `fy2` #17, `zzfy` #30, `moniHuafu` #57) **and** against
the concurrently-running sibling agent's own raw extraction for archive #97
(`fy3xd`, "风云III修订版" / Fengyun III Revised Edition) —
comparing raw `.c` files byte-for-byte (CRLF-stripped, since some copies
use CRLF and others don't) rather than trusting shared branding/title
alone:

| file | vs `zzfy` (#30) | vs `moniHuafu` (#57) | vs `fy3xd` (#97, raw, concurrent) |
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
   processing #97** (`fy3xd`) specifically — `master.c`,
   `simul_efun.c`, `securityd.c`, AND `chinese.c` are ALL byte-identical
   between the two, with only `logind.c` (site banner/messages) diverging.
   "典藏版" (Collector's Edition) and "修订版" (Revised Edition) are
   evidently two different content/documentation packagings of what is
   functionally the *same* underlying `.7.4`-based 风云3 codebase, not
   independent forks. **Flagging for the cross-check the task brief
   requested**: since #97 was still mid-processing at the time this lib
   was done (its `work/` didn't exist yet, only `raw/`), a later diff
   between `libs/fy3xd/work/` and this lib's `work/` (once #97
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
cd libs/fy3dz
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
  NO live caller in the login chain (unlike sibling `fy3xd`,
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
  `libs/fy3dz/work/data/user/f/fluffos/fluffos.o`,
  `libs/fy3dz/work/data/login/f/fluffos/fluffos.o`.

## 深度功能测试 / Deep functional test (AGENTS.md §10.7, round two)

One continuous native session (native driver, `scripts/mudclient.py`),
following the lib's own `doc/help/newbie.txt` as the intended test path
(拜师 via `apprentice`, `learn <skill> from <master> with <potential>`,
`fight` for safe sparring, `list`/`buy` for shop purchases). Several real
Chinese-name test characters registered across the session (沈风/曲阳/
林风/北斗), landing correctly in nationality-specific start zones (汉族
→ 凤求凰客栈; 苗族 → 沉香镇/沉香南宫). `look`/`score`/`i`/`hp` all
correct at every state change.

### Bugs found and fixed

1. **`file_owner()` path-depth off-by-one — confirmed live instance of
   AGENTS.md §7.26**, `adm/simul_efun/object.lpc`. The original
   `sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3; return name;`
   returned the SECOND segment after `/u/` (e.g. `"npc"` for
   `/u/guanwai/npc/petowner.lpc`) instead of the wizard's own directory
   name — correct only for the rare exactly-2-levels-deep case. Every
   compile diagnostic (even a harmless "Unused local variable" warning)
   on nested `/u/` content (the normal case — `npc/`, `obj/` subdirs)
   made `master.lpc`'s `log_error()` write to a bogus path
   (`/u/n/npc/log`), throwing `*Wrong permissions for opening file ...
   for append. "No such file or directory"` — caught by the driver so
   nothing crashed visibly, but spammed `debug.log` with a real error on
   ordinary lazy compiles (reproduced live: any command that triggers a
   fresh compile of `/u/guanwai/npc/*` or `/u/guanwai/obj/*` content,
   e.g. an NPC wandering there, or an admin `update`). Fixed per §7.26's
   own established pattern: capture only the first segment after `/u/`
   (`sscanf(file, "/u/%s/%s", name, rest) == 2; return name;`).

2. **NEW bug class: `user_path()`/`user_cwd()` assume a letter-sharded
   wizard-directory layout that this archive's `/u/` tree never had**,
   `adm/simul_efun/path.lpc`. `user_cwd(name)` returned `"/u/" +
   name[0..0] + "/" + name` (e.g. `/u/g/guanwai/`, the ES II-family
   letter-sharding convention seen elsewhere in this project), but this
   archive's actual `/u/` tree is flat (`/u/guanwai/`, `/u/palace/`,
   etc.) — confirmed present in the RAW, pre-conversion archive too
   (`raw/fy3dcb/风云典藏版/u/` has the same flat layout), so this is a
   pre-existing mismatch in the original code, not something the
   conversion pipeline introduced. Only 3 call sites lib-wide
   (`cmds/adm/cd.lpc`, `adm/obj/master.lpc`'s `log_error()`,
   `path.lpc` itself), both wizard/admin-facing: bare `cd` (no
   argument) resolved to a directory that never exists for EVERY
   wizard (`没有这个目录。`), and — chained with bug #1 above — even
   after fixing `file_owner()`, `log_error()` still failed one level
   further down (`/u/g/guanwai/log` instead of `/u/guanwai/log`) until
   this was also fixed. Fixed by dropping the letter-shard segment:
   `return ("/u/" + name);`. Verified live after a fresh driver
   restart: `update /u/guanwai/npc/petowner` now recompiles cleanly
   with zero `debug.log` errors, and `cd ~guanwai` correctly resolves
   to `/u/guanwai/` (bare `cd` for `fluffos` itself still reports "没
   有这个目录" — expected, since the seeded admin account has no real
   `/u/fluffos/` wizard-content directory of its own, not a bug).
   **Likely affects other ES II-lineage siblings with a flat `/u/`
   archive layout** — worth a quick `ls u/` + grep `user_cwd\(` check
   on `fy3xd` (confirmed byte-identical `master.c`/
   `simul_efun.c`/`securityd.c`/`chinese.c` to this lib per the lineage
   table above) and the other 风云3 siblings.

3. **`cmds/usr/save.lpc`'s unguarded `environment(me)->query(...)` —
   same class as the already-fixed AGENTS.md §7.14 instance in
   `cmds/usr/quit.lpc` (same lib, explicit code comment there credits
   "Same fix as fy2qh/fy2")**. The `save` command's
   `valid_startroom` check dereferenced `environment(me)` without a
   null guard; `quit.lpc`'s sibling call site already carries the
   defensive `if (environment(me))` guard for the identical
   post-registration-race class, but `save.lpc` was missed. Added the
   same guard (`if (environment(me) && environment(me)->query(...))`).
   Not independently reproduced live (the race window is narrow and
   this lib's `enter_world()` has no intervening `input_to` pause that
   would make it easy to hit), but the fix is cheap, safe, and directly
   mirrors an already-established, already-fixed pattern in the exact
   same file tree — applied proactively per AGENTS.md's own "port to
   every sibling immediately" guidance, scoped here to a sibling call
   site within the SAME lib rather than a different lib.

### Confirmed working (no bug)

- **Safe-sparring mechanism**: the `fight` command (documented in its
  own `help fight`: "这种形式的战斗纯粹是点到为止，因此只会消耗体力，
  不会真的受伤" — pulls punches, costs stamina only, no real injury).
  Traced into `adm/daemons/combatd.lpc`: `receive_wound()` (real injury)
  only fires when `me->is_killing(victim) || weapon` is true; a bare
  `fight` never sets `is_killing`, so damage only depletes `kee`
  (stamina) and the match auto-stops at 50% kee on either side. Verified
  live against 寒梅先生 (a "peaceful"-attitude NPC near the start zone,
  reachable from `fqkhotel` via one `west`) — full HP/kee/gin/sen intact
  after a full exchange, "结果没有造成任何伤害" (no damage resulted) on
  the received hits. Note: `accept_fight()` (`std/char/npc.lpc`) always
  refuses for `"friendly"`-attitude NPCs (confirmed against `npc/waiter`
  and the 黄衣卫 guards — "在下怎麽可能是小兄弟的对手？") — pick a
  `"peaceful"`- or unlabeled-attitude NPC for the safe-spar test, not a
  friendly shopkeeper.
- **Organic sect-join + skill-learning path**: `apprentice master jin`
  (荆无命, 金钱帮/Money Gang, reachable from `fqkhotel` via
  west/south/west/west/south/south) worked exactly per `attempt_apprentice()`
  → `recruit` → `recruit_apprentice()`; `score` correctly updated title
  to "金钱帮第三代弟子" with "你的师父是荆无命". `learn move from master
  with 10` (exact syntax required — bare `learn move` just prints the
  format string) correctly deducted 10 潜能/consumed 精力, and `skills`
  showed the new skill at level 1. No sect-join shortcut/admin command
  found elsewhere to cross-check against (per §10.7 item 4) — the
  organic NPC path is confirmed to be the only route in this lib.
- **Net-dead handling, prompt reconnect**: `obj/user.lpc`'s `net_dead()`
  does NOT void-park the player (no `VOID_OB` move at all — structurally
  immune to the AGENTS.md §7.20 bug class) — it just flags `netdead`,
  schedules a `user_dump` force-quit `call_out` at `NET_DEAD_TIMEOUT`
  (900s), and leaves the player body in place. A prompt reconnect
  (disconnect without `quit`, immediately reconnect with the same id)
  correctly hit `reconnect()`, which cancels the pending `user_dump` and
  restores the SAME room/state with zero loss — verified live (character
  `北斗` disconnected then promptly reconnected at `沉香南宫`, `score`
  unchanged).
- **`tell_room()` 2-arg wrapper bug (§7.12)**: `user_dump()`'s
  `DUMP_NET_DEAD` branch calls the 2-arg form
  (`tell_room(environment(), "...")`); confirmed the lib-wide fix
  documented above (fix #6 in the original pass, `exclude || ({})`) is
  in effect, so this specific call site is NOT vulnerable to §7.12's
  crash shape.
- **Quit-time `environment(me)` guard (§7.14)**: `cmds/usr/quit.lpc`
  already carries the defensive guard (see bug #3 above for the sibling
  gap this pass found and fixed in `save.lpc`).
- **Admin account**: re-verified `fluffos`/`(admin)` login and
  `update /adm/daemons/combatd`-equivalent access still work against the
  rebuilt driver (`update /u/guanwai/npc/petowner` used as this pass's
  ACL-exercising check, succeeding cleanly after the fixes above).

### Not independently verified this pass (honest gaps)

- **Long-duration net-dead force-quit (past the 900s `NET_DEAD_TIMEOUT`)
  and a real-wall-clock-gap reconnect-after-clean-quit check** — per
  §10.7 item 8/9. A test character (`北斗`) was deliberately left
  net-dead specifically to run this check, but the only available
  multi-minute wait mechanism in this environment (a genuinely blocking
  `sleep 900+`) is blocked by this session's own tool policy (which
  requires either `Monitor`/`run_in_background`, both of which this
  task's own instructions separately prohibit using passively), and a
  background sleep was armed and then explicitly stopped short per a
  live course-correction mid-task rather than left to complete. The
  short/prompt net-dead reconnect path IS verified live (see above); the
  driver's own `user_dump()`/`DUMP_NET_DEAD` code path past the full
  900s timeout, and whatever a real ≥45-minute gap would do to the
  `cron.lpc` autosave-adjacent state, were reviewed by reading the code
  (see "Confirmed working" above and the `tell_room()`/`environment()`
  guard checks) but not independently exercised live end-to-end this
  pass. `北斗` was left connected-then-disconnected (net-dead) at
  `沉香南宫`/南宫钱庄 mid-pass; its actual disk save reflects only the
  pre-net-dead state (no family/skills — this character never
  apprenticed or learned anything, only walked and looked).
- **Shop purchase / economy**: attempted (`list`/`buy dumpling from
  waiter` at the start-zone waiter vendor) but every fresh character
  starts with 0 money ("你的钱不够" — insufficient funds) and no
  in-session way to earn any was exercised, so a successful purchase was
  never completed live. Code-reviewed only (F_VENDOR's `vendor_goods`
  mapping, `std/room/shop.lpc`'s save-on-purchase) — not exercised.
- **Combat progression to death/respawn**: not reached — time budget
  went to the sect-join/skill-learn/safe-spar/net-dead checks instead,
  per §10.7 item 6's explicit permission to state this honestly rather
  than presenting it as tested.
- **Ambient NPC violence observation (not a bug, noting for context)**:
  partway through this pass, `npc/waiter` (the start-zone shopkeeper)
  was found dead (`店小二的尸体`/Waiter's corpse) with no live
  replacement, most plausibly killed by one of the newbie-doc's own
  documented "see you, kill you" wandering hostiles (强盗/土匪/疯狗) —
  ambient world simulation the newbie doc itself warns new players
  about, not something this pass's testing triggered. `std/room.lpc`'s
  `reset()`/`make_inventory()` correctly re-clones a dead NPC (`die()`
  destructs the original object, so `objectp()` on the tracked reference
  goes false and a fresh clone is made on the room's next `reset()`) —
  confirmed by reading the code, not confirmed live within this pass's
  time budget (the room's `time to reset` is 900s and the corpse was
  still present when last checked, but that observation window was
  itself well under 900s of continuous room-idle time, so it isn't
  conclusive either way). If a future pass finds the shop permanently
  vendor-less across a real reset interval, that would be worth
  revisiting as a genuine reset/repopulation bug — not confirmed as one
  here.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 8 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Deep functional test round three (2026-08-14)

Independently re-verified against current code rather than trusting the
round-two writeup above. All 3 prior fixes confirmed still present and
live-re-exercised. Found and fixed a fourth bug — the same
`cmds/wiz/update.lpc`-class `present(environment(me))` crash found
repeatedly this session, but at this lib's own alternate path
(`cmds/adm/update.lpc`), which the original 135-file corpus sweep didn't
cover. That discovery led to a small follow-up sweep across the corpus
for the same alternate path — see the separate `corpus sweep:
cmds/adm/update.lpc` commit for the other 5 libs found. Plus the two
now-standard checklist gaps (`file.lpc` hardening, one printf leak).

### New fix: `cmds/adm/update.lpc` — `present(file, environment(me))` crash, alternate path

Byte-identical crash shape to the one found on `xiakexing2017`/
`dtslmud`/`dtxywzxzb` earlier this session, just living at
`cmds/adm/update.lpc` instead of the more common `cmds/wiz/update.lpc` —
this lib doesn't have a `cmds/wiz/` directory equivalent. Fixed with the
same `environment(me) &&` guard. Live-verified: `update
/u/guanwai/npc/petowner` succeeded cleanly.

### New fix: `adm/simul_efun/file.lpc` — same §7.11-class gap as siblings

`log_file()` missing `assure_file()`, `cat()` missing a null-guard.
Fixed both (with the forward declaration this driver requires).

### New fix: one active `printf("%O\n", ob)` debug leak in `logind.lpc`

This lib only has the manual-name-entry branch (`get_resp()` is
forward-declared but never implemented, so there's no separate random-
name-accept path to check) — one leak found and removed.

### Re-verified live: all 3 round-two fixes still hold

- **§7.26 `file_owner()` path-depth fix**: code-confirmed
  `sscanf(file, "/u/%s/%s", name, rest) == 2` present. Live-verified by
  running `update /u/guanwai/npc/petowner` as admin — succeeded cleanly
  ("重新编译 ... 成功！"), the exact command the original bug made throw
  `*Wrong permissions for opening file ... for append`.
- **`user_cwd()`/flat-`/u/`-layout fix**: code-confirmed `return ("/u/"
  + name);` present. Live-verified: `cd ~guanwai` correctly resolved to
  `/u/guanwai/` (not the broken letter-sharded `/u/g/guanwai/`).
- **`cmds/usr/save.lpc`'s `environment(me)` guard (§7.14-class)**:
  code-confirmed `if (environment(me) && environment(me)->query(...))`
  present.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`, no password
step in this lineage — confirmed flow, not a bug). `update
/u/guanwai/npc/petowner` and `cd ~guanwai` as the real privileged-action
checks that also re-exercise the two path-fix bugs. Two full rapid
reconnects, both clean. `work/log/debug.log` line count checked before/
after (357→363, only harmless compile warnings, zero error-signature
matches for either original bug). Driver killed by exact PID after
testing; incidental `fluffos.o` save-timestamp churn reverted before
commit.

### Files modified this pass

- `work/cmds/adm/update.lpc` — new fix (`environment(me)` null-check,
  §7.106 path variant).
- `work/adm/simul_efun/file.lpc` — `log_file()` `assure_file()` guard
  (with forward declaration), `cat()` null-guard.
- `work/adm/daemons/logind.lpc` — removed one `printf("%O\n", ob)` debug
  leak.
