# zhongjidiyu — 终极地狱之轩辕传说 (Ultimate Hell: The Legend of Xuanyuan)

Archive: `终极地狱.rar` (archive #78 of ~100). Port: **40072**. Status: **done**
(boots clean, full registration flow verified with two real Chinese names in
separate continuous connections, post-login commands `look`/`score`/`quit`
all confirmed producing correct real output).

## What this is

Self-extracts to a nested `revive/` root (not top-level) containing a raw
readme (`说明文件.txt`, GBK-encoded, filename itself needed a manual
re-encode pass after extraction — see "Extraction gotcha" below) that reads
(translated): "This is the bottom-layer source code released by doing...
released for study purposes, not for running a live server with." Live
banner reads "终极地狱之轩辕传说" ("Ultimate Hell: The Legend of Xuanyuan"),
MUD_NAME in the raw config is `hell.local`. `adm/single/master.c`'s own
header credits the full lineage: `for ES II mudlib / original from Lil /
rewritten by Annihilator (11/07/94) / modified by Xiang for XKX (12/15/95)
/ updated by Doing Lu for hell (2K)` — this is the same **"ES II" lineage**
already seen across ~20 prior libs (es1_win/esI/xkx2001/rzrmud/xo/
bmxkx2001/kxkj/yueyingqiyuan/wuhanzhan/haiyang2/
yanhuangwuhun/yhyxs/xuanjianlu/shenzhou/shenmo/
kxkj1/etc.), specifically closest in file layout
(`adm/single/{master,simul_efun}.c`, `adm/daemons/`, `adm/simul_efun/`) to
`xkx2001`(#25)/`rzrmud`(#23)/`bmxkx2001`(#45). `securityd.c`'s own
header credits "Annihilator@Eastern.Stories" then "Modified by Xiang for
XKX" then "Updated by DOing Lu for ULTRA HELL" — same chain. MudOS
`v22pre11`-era target.

**IMPORTANT — cross-check flagged for the main session**: two OTHER
archives sharing the "终极地狱" name are being processed concurrently by
sibling agents in this same batch: archive #79
(`终极地狱之爱若幽兰1.166正式版.rar`) and archive #80
(`终极地狱-指间mud版服务端.rar`). This agent could not cross-check against
them (concurrent extraction). **The main session should diff/md5sum core
files (`master.c`/`chinese.c`/`securityd.c`/`logind.c`) across all three
once all are done** to determine whether they're the same game at
different snapshots, forks of one lineage, or unrelated codebases that
happen to share a title — per this project's repeated lesson (shujian2008
vs sjpl2, xianlvqiyuan vs xlqy_new2007, etc.) that similar
Chinese titles are NOT a reliable lineage signal on their own.

## Extraction gotcha

The archive's own readme file extracted with a GBK-encoded filename that
`unrar`'s locale handling left as raw undecodable bytes
(`˵\udcc3\udcf7\udcceļ\udcfe.txt` — Python surrogate-escaped). Renamed it to
its correct decoded name (`说明文件.txt`) via a small Python
`os.fsencode`/`gb18030`-decode script rather than leaving the mojibake
filename in `work/`.

## Fixes applied (proactive, per AGENTS.md catalog, before first boot)

- **§15h** (`is_chinese`/`check_legal_name`): `adm/simul_efun/chinese.lpc`'s
  `is_chinese()` had the classic GBK-byte-range check (`str[i] < 161`,
  alternating-byte-offset check) — replaced with a CJK Unicode codepoint
  range test. `adm/daemons/logind.lpc`'s `check_legal_name(name, maxlen)`
  halved its GBK-byte-calibrated bound (`maxlen` → `maxlen / 2`, and
  `strlen(name) < 2` → `< 1`) and a separate combined surname+given-name
  length guard (`strlen(fname) < 4` → `< 2`, matching the message's own
  "至少要有两个汉字" wording).
- **§15h deep `named.lpc` fix** (same shape as the nitan-family/chidi/dtsl
  precedent): `adm/daemons/named.lpc`'s `PATH(name)` macro
  (`name[0..1]` → `name[0..0]`), all `strlen(name) < 2` guards → `< 1`, the
  sliding-window similar-name check (`name[i..i+3]`/`name[i..i+5]` 2/3-char
  GBK windows → `name[i..i+1]`/`name[i..i+2]` UTF-8 windows, loop bound
  `l - 4` → `l - 2`, combined guard `< 4` → `< 2`, inner guard `i+6<=l` →
  `i+3<=l`).
- **§15n** (custom `securityd.lpc` ACL blocking the driver's own
  compile-time source loading): added an explicit
  `case "load_object"/"recompile_object"/"include": return 1;` at the TOP
  of `valid_read`, before the `! objectp(user)` branch that would otherwise
  `error()` on a non-object/non-string `user` (a real risk here — this
  securityd's error-throwing branch is unguarded, unlike some sibling
  libs' softer `return 0`). Also softened both `valid_read`'s and
  `valid_write`'s `error("...Invalid argument type of user.")` calls to
  `return 0` (deny) as defense-in-depth so a driver-internal check can
  never crash this apply outright.
- **§14** (`valid_override` 3-arg upgrade): `master.lpc`'s `valid_override`
  widened from 2-arg to `varargs int valid_override(file, name, main_file)`,
  checking `main_file == SIMUL_EFUN_OB/MASTER_OB` too — relevant since
  `simul_efun.lpc` composes ~10 `#include`d fragment files under
  `/adm/simul_efun/`.
- **§8d/§15o insurance**: added `master::get_include_path()` (prepends the
  compiling file's own directory) even though no live `<local.h>`-style
  bug was found on inspection (all local headers in this lib — `herb.h`,
  `fish.h`, `medicine.h`, `wedding-ring.h` — are already `#include`d with
  quotes, not angle brackets) — cheap, free insurance matching established
  practice for any lib with a genuinely custom securityd.
- **§15ae, TWO separate instances** (private `add_action`-dispatched
  functions silently never firing):
  1. `feature/command.lpc`'s central `command_hook(string arg)` was
     `private nomask` — dropped `private`, kept `nomask`. This is the
     CORE post-login command dispatch; without this fix EVERY typed
     command (`look`, `score`, anything) would silently do nothing.
  2. **New second instance found via the mandated grep sweep**:
     `adm/npc/luban.lpc` (the "鲁班" NPC, a house-building/contractor
     feature) registers 18 of its own commands via `add_action`
     (`do_stop`/`do_answer`/`do_desc`/`do_show`/`do_changename`/
     `do_changeid`/`do_changetype`/`do_changedesc`/`do_finish`/
     `do_withdraw`/`decide_withdraw`/`do_demolish`/`do_help`/`do_list`/
     `do_type`/`do_agree`/`do_reject`/`do_delete`), every one declared
     `private int name(...)` (both forward declarations and real
     definitions). Fixed all 18 by dropping `private` from both the
     declaration and definition of each. This is an optional gameplay
     feature (build-a-house via the 鲁班 NPC), not on the critical
     registration/command path, but matches the exact same bug shape —
     worth fixing since it's mechanical and cheap. **Confirms the
     project's standing instruction to grep every add_action-dispatched
     hook for `private` is not just a formality — this lib had it twice.**
- **§15s + §15aa combined** (`adm/simul_efun/message.lpc`): the local
  `message(mixed arg, string message, mixed target, mixed exclude)`
  override is defined near the BOTTOM of the file, but
  `tell_object`/`tell_room`/`shout`/`write`/`say` (all textually earlier)
  call the bare identifier `message(...)` first — since `message` is also
  a real driver efun name, this silently binds those earlier calls
  straight to `efun::message()`, bypassing the override. Added a
  `varargs void message(...)` forward declaration at the top of the file
  (matching the real definition's signature) before any caller. Also
  fixed the real definition to coerce a falsy/omitted `exclude` (varargs
  default `0`) to `({})` before delegating to `efun::message()`, since
  this driver's real efun rejects a raw `int 0` for that argument
  (`void | object | object *` only).
- **§15w** (`log_error()` broadcasting compile *warnings*, not just real
  errors, to whoever's online): gated `master.lpc`'s `log_error()` player
  broadcast on the message NOT containing the substring `"warning:"`
  (matching this driver's actual lowercase diagnostic prefix), still
  logging everything to `/log/log` regardless.
- **§15p** (proactive DNS/intermud daemon exclusion): removed
  `/adm/daemons/network/dns_master` from `adm/etc/preload` before the
  first boot attempt. (Checked `cmds/usr/mudlist.c`'s inline `DNS_MASTER`
  call per §15ab's "can still bite even when excluded from preload" —
  already self-guarded with `if (! find_object(DNS_MASTER)) return
  notify_fail(...)`, confirmed harmless.)
- **§3 counterexample** (blanket `\bstatic\b`→`nosave` sed colliding with
  a pre-existing `"static/..."` log-path naming convention): this lib has
  ~54 `log_file("static/XXX", ...)` call sites (crash dumps, security
  logs, promotion logs, per-command usage logs, etc.) that the blanket
  sed rewrote to `"nosave/XXX"`. Reverted all of them back to `"static/`
  via a scoped `grep -l '"nosave/' | xargs sed -i 's/"nosave\//"static\//g'`
  pass (safe here since 100% of the matches were this exact naming
  convention, confirmed by diffing against the raw pre-conversion source
  first).
- **Directories created** (none of `/log`, `/log/static`, `/log/user`,
  `/binaries` existed anywhere in the raw archive, despite being written
  to by `log_file()`/`assure_file()`-less call sites): `mkdir -p
  work/log work/log/static work/log/user work/binaries` before first
  boot, per §15ah's "missing save-data directory silently aborts a
  write_file() with no catch()" lesson. `libs/zhongjidiyu/log/` (sibling
  of `config.fluffos`, the driver's own CWD-relative "log directory")
  also created.

## New/notable bugs found (not yet in AGENTS.md's numbered catalog)

1. **`virtuald.lpc`'s "virtual object" fallback treats `file_size() == -1`
   (nonexistent) as truthy "file exists"** — `compile_object(file)` walks
   `file`'s path components and does
   `if (file_size(name + ".lpc")) { ob = name->query_virtual_room(...); }`.
   Since `file_size()` returns `-1` for a missing path (a nonzero int, so
   truthy), this ALWAYS "succeeds" into calling `name->query_virtual_room()`
   for a name that doesn't exist as an object either — which triggers the
   driver to lazily `load_object(name)`, which fails (file doesn't exist),
   which calls `master::compile_object(name)` AGAIN as the driver's
   standard "couldn't find this file, try a virtual object" fallback,
   which calls `virtuald.compile_object(name)` again... recursing until
   `Inherit chain too deep: > 30` aborts it. This isn't cosmetic: it fired
   continuously (every NPC-patrol heartbeat tick referencing a room in the
   missing `/d/city`/`/d/city3` zones — see gap #2 below) and, before it
   was fixed, appeared to be eating enough eval-cost/CPU each tick that
   the FIRST test session's character landed with a corrupted room state
   (fell back to `START_ROOM` which itself doesn't exist either, see next
   item). **Fix**: `file_size(name + ".lpc") >= 0` (a real, existing file)
   instead of a bare truthy check. This is a genuine, driver-lineage-wide
   engine bug independent of missing content — worth checking any other
   ES-II-family lib with a `virtuald.lpc`/"virtual object" fallback for the
   same bare-truthy-`file_size()` shape.
2. **Missing zone content, confirmed real archive gap (§13)**: `/d`
   contains ONLY `death/`, `pk/`, `register/` — every city/sect zone
   (`/d/city`, `/d/city3`, `/d/wudang`, `/d/xuedao`, `/d/beijing`,
   `/d/shaolin`, `/d/xingxiu`, `/d/heimuya`, dozens more) referenced by
   `START_ROOM` (`/d/city/kedian`), `cmds/chat/enterworld.lpc`, `npcd.lpc`'s
   patrol tables, `mapd.lpc`'s map data, and 48 `clone/board/*_b.lpc`
   bulletin boards is genuinely absent — this really is the
   "bottom-layer source code... for study" skeleton release its own
   readme describes, not a full world pack. Also affects a whole
   sub-feature: `/data/room/moman/*` (a "house" template set, 绿竹苑) that
   `#include`s `/d/room/roomnpc/roomnpc.h` (also missing, defines
   `is_owner()`/`owner_is_present()`) — 9 files affected, all under the
   same missing `/d/room/` tree. **Because `START_ROOM` itself
   (`/d/city/kedian`) doesn't exist**, `logind.lpc`'s own fallback-to-
   `START_ROOM` path is dead code that always fails too — but this is
   masked in practice because `REGISTER_ROOM` (`/d/register/entry`, which
   DOES exist, home to NPCs 水笙/狄云) is what a genuinely fresh
   (`! registered`) player actually uses, so the missing `/d/city` never
   surfaces during ordinary registration. Documented, not fabricated.
3. **`d/register/npc/diyun.lpc` unguarded factory-chain call (§15e)**:
   `carry_object("/d/city/obj/cloth.lpc")->wear()` in this NPC's
   `create()` — `/d/city/obj/cloth.lpc` is part of the missing `/d/city`
   zone (gap #2), so `carry_object()` correctly returns `0`, and the
   unguarded `->wear()` on it threw `Bad argument 1 to EFUN call_other()`
   every time this NPC's `create()` ran (i.e. every time `/d/register/entry`,
   the REAL register room, reset) — which, because the error was inside a
   `catch(load_object(startroom))` in `logind.lpc`, made the ENTIRE
   register-room load look like it failed, sending every new character to
   the (also nonexistent) `START_ROOM` fallback instead of the real,
   populated register room. **This was the single highest-impact fix in
   this pass** — before it, characters landed with a broken/empty
   environment and `look`/`score` appeared to produce no output at all.
   Fixed with the standard `if (objectp(cloth)) cloth->wear();` guard; the
   NPC simply goes unclothed (acceptable, matches precedent).
4. **Genuinely broken/orphaned, never-loaded daemon files** (not fixed,
   not reachable in normal play — same category as §12's "orphaned
   non-LPC file", just for an incomplete `.lpc` instead): `adm/daemons/
   cruised.lpc` ("漫游精灵", cross-server player roaming) uses `vfd`/
   `socket_info` without ever declaring them, references `STREAM_BINARY`
   without `#include <net/socket.h>`, and has a `CAHNNEL_D` typo (for
   `CHANNEL_D`) — none of `CRUISE_D` is even `#define`d anywhere, and
   nothing else in the lib references it; not in `preload`. `adm/daemons/
   quest/girl.lpc` similarly references undeclared `rcv_npcs`/
   `supply_objs` globals and is never loaded by anything else either. Both
   read as genuinely incomplete/abandoned files from the original
   author, consistent with the archive's own "study source, not a full
   release" disclaimer.
5. **Pre-existing typos, fixed** (unrelated to encoding/rename, confirmed
   via raw-byte diff against the original archive):
   - `inherit/condition/damo.lpc:225`: `if (! intp(cnd["level"]) ||
     ! intp(cnd["remain"] || ! stringp(cnd["id"])))` — a misplaced closing
     paren (should close after `cnd["remain"]`, not after `cnd["id"]`).
   - Same file, a genuine corrupted byte in the RAW archive (not our
     conversion): a stray invalid `0xf7` byte immediately before a closing
     quote at raw byte offset 7414 (inside `"发作身亡了"`) made the whole
     file fail strict GB18030 decoding, so `convert_lib.sh` fell back to
     `iconv -c` (lossy), whose "eats an adjacent real byte" recovery
     heuristic then corrupted a LATER, unrelated string literal
     ("长长的吁" @ line 278) into 5 invalid UTF-8 bytes — the exact
     `xo_final`/`tianxia` pattern documented in AGENTS.md's Encoding
     section. Fixed by stripping the single stray byte from the RAW bytes
     directly (confirmed via `bytes.decode('gb18030')` raising
     `UnicodeDecodeError` at that exact offset) and re-decoding the whole
     file cleanly, rather than patching the already-corrupted UTF-8
     output.
   - `adm/simul_efun/util.lpc` never `#include <ansi.h>` despite using
     `NOR`/`HIY`/`HIW`/`HIR`/`HIG`/`HIC`/`WHT`/`BCYN` throughout — silent
     in a real boot only because `simul_efun.lpc` (which `#include`s this
     file) already pulls in `ansi.h` itself first (§6b: works fine
     composed, fails standalone under `lpcc`). Added the `#include`
     directly for correctness/self-sufficiency (harmless, header-guarded).
   - `inherit/misc/quest.lpc`'s `set_information(string key, string info)`
     — narrower than `QUEST_D`'s own `mixed info`, and 5 quest template
     files (`clone/quest/{explore,judge,search,shen,supply}.lpc`) pass a
     function-pointer closure (`(: ask_npc :)`), not a string — widened to
     `mixed info` (matches AGENTS.md's already-cataloged "quest
     set_information signature" bug class, e.g. yhyxs).

## Confirmed NOT needed (checked, not present)

- **§4** (lazy `load_object(SECURITY_D)` recursion in `master.lpc`'s
  `valid_read`/`valid_write`): not present — both applies only do
  `find_object(SECURITY_D)`, never `load_object()`.
- **§8c** (`this_player()`-override footgun in `valid_read`/`valid_write`):
  not present — this securityd's applies use the `user` parameter directly
  (as passed by the driver/master), never silently substitute
  `this_player()`.
- **§15l** (`master.lpc` destructing `SIMUL_EFUN_OB` in `create()`): not
  present — `create()` is just a `write()` banner line.
- **§8e** (`tail()` missing-efun): no `tail(` calls anywhere.
- **§15x** (hardcoded `MUD_PORT` mismatch): no such constant — `connect()`
  in `master.lpc` doesn't check the port at all; `versiond.lpc` reads the
  port dynamically via `get_config(__MUD_PORT__)`.
- **§15r** (`check_config.lpc`-style driver-version self-check): no such
  file `inherit`ed into `master.lpc`/`simul_efun.lpc`.
- **§15u** (dormant "phone-home license check"): none found in
  `securityd.lpc` (this one's fully readable, no obfuscated destructive
  function).
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`, `__OLD_ED__` gap): no
  code calls any of these (only `doc/efuns/*` reference pages and a stale
  `data/versiond.o` save blob mention the strings).
- **Uppercase `.C` files** (§ shenmo precedent): none found
  (`find work -name '*.C'` empty).
- **§15ad**-style non-fatal `versiond.lpc` config-ID mismatch: PRESENT but
  confirmed harmless by the same reasoning as yhyxs —
  `setup()` sets `version_ok = 1` synchronously (this is a `local` release
  server) BEFORE the deferred `call_out("in_server", 2)` that does the
  broken `socket_bind()` (using `get_config(__MUD_PORT__)`, which this
  driver build reports as an empty string here, so `port = "" + 12`
  becomes the string `"12"`, and `socket_bind()` rejects a
  string). Logged once per boot as `*Bad argument 2 to socket_bind()
  Expected: int Got: "12".` — cosmetic, `version_ok` is already correct by
  the time it fires.

## Testing methodology note (worth flagging for future libs)

This lib sets `user->set("env/prompt", "time")` for every new player — a
**live, once-per-second clock prompt** re-drawn from the character's own
`heart_beat()` (`inherit/char/char.lpc`), independent of the driver's
`write_prompt()`/`process_input()` applies. `scripts/mudclient.py`'s
`--idle` pacing logic resets its "quiet" timer on ANY received byte,
including these once-a-second heartbeat prompt redraws — with the default/
larger `--idle` values used successfully on most other libs (1.0–3.5s),
the heartbeat's constant ~1s drip meant the "idle" condition was **never**
satisfied, so queued `--send` lines for `look`/`score`/`quit` were silently
**never actually transmitted at all** (confirmed via `-dconnections`
driver debug output: zero `get_user_command()` calls for those lines).
This looked EXACTLY like the §15ae "commands silently do nothing" failure
mode and cost significant diagnostic time (traced through `add_action`,
`exec()`/interactive-transfer, `process_input()`/`APPLY_PROCESS_INPUT`,
even a raw byte-level socket script) before the actual cause — a test-tool
pacing artifact specific to libs with a persistent per-second heartbeat
prompt, not a mudlib bug — was found. **Fix for testing**: use a SHORT
`--idle` (0.3–0.5s, shorter than the heartbeat period) on any lib with a
live/clock-style `env/prompt`, or use a raw socket script that sends after
a fixed wait rather than an idle-detection loop. Worth promoting to
AGENTS.md as its own catalog entry for the next lib with a similar
live-prompt feature.

## Registration flow shape

`get_id` (English id, 3-10 letters) → `confirm_id` (y/n, only for a NEW
id) → `get_surname` (Chinese, ≤2 chars, optional/blank-skippable) →
`get_name` (Chinese, ≤2 chars, combined surname+name must be ≥2 chars,
checked against `NAME_D->invalid_new_name()` for banned Jin Yong character
names and near-duplicate existing names) → `new_ad_password`/
`confirm_ad_password` (a SEPARATE "admin/recovery password", ≥5 chars) →
`new_password`/`confirm_password` (the regular login password, ≥5 chars) →
`get_type` (1-5, character "build" archetype, blank defaults to 5/balanced)
→ `get_gender` (m/f) → `enter_world()`. No hidden BIG5/GB prompt, no
client-version gate, no anti-flood throttle found in `band.lpc` (only
`is_banned(site)` — a real IP-ban list, not a per-connection registration
throttle).

## Interactive test result

Full registration + post-login flow verified in **two separate continuous
connections** with real Chinese names **"秦风"** (male) and **"林枫"**
(female, type 耐力型), both reaching the actual populated starting room
"世外桃源" (with NPCs 水笙/狄云 present, exits west/east/north/south). Both
sessions then sent `look` (re-displayed the correct room description),
`score` (correctly responded "还没有出生呐，察看什么？" — a legitimate
game-rule message, since neither test character completed the additional
`register <email>` + "投胎做人" reincarnation step the unregistered banner
describes; this is real command execution, not a silent failure), and
`quit` (correctly responded "欢迎下次再来！" and disconnected). Zero
`debug.log` errors in the final clean runs beyond the confirmed-harmless
`versiond.lpc` socket_bind cosmetic line. `command_hook`'s `private`
removal (§15ae) confirmed working via this real post-login-command test,
per the project's standing policy.

## lpcc sweep

1169 files, **1072 pass / 97 fail (91.7%)**. All 97 failures triaged into
already-understood categories, none require further fixing:
- 48: `couldn't find object '/d/...'` — the missing zone content (gap #2
  above), bulletin boards referencing nonexistent rooms across dozens of
  sects/cities.
- 32: the `/data/room/moman/*` house-template module's missing
  `/d/room/roomnpc/roomnpc.h` (`is_owner`/`owner_is_present`) — same root
  cause, part of the same missing `/d/room/` tree.
- ~11: `adm/daemons/cruised.lpc` (6 distinct errors) + `adm/daemons/quest/
  girl.lpc` (2 errors) — genuinely broken/abandoned, never-loaded daemon
  files (item #4 above).
- 1: `adm/simul_efun/message.lpc`'s `message_system(string message)` —
  its OWN parameter is named `message`, shadowing the function name it
  then tries to call (`message("system", ...)`) — a real-looking bug that
  is confirmed a `lpcc`-standalone-compile artifact per §6b (this file is
  `#include`d into `simul_efun.lpc`, not a standalone object; the real
  driver boot never hits this — verified zero hits for this error text in
  a clean boot's `debug.log`). Not fixed, to avoid risking a real
  behavior change to a confirmed non-issue.

## Files touched (for reference)

`adm/simul_efun/chinese.lpc`, `adm/daemons/logind.lpc`, `adm/daemons/
named.lpc`, `adm/daemons/securityd.lpc`, `adm/single/master.lpc`,
`feature/command.lpc`, `adm/simul_efun/message.lpc`, `clone/user/user.lpc`,
`adm/etc/preload`, `adm/daemons/virtuald.lpc`, `d/register/npc/diyun.lpc`,
`adm/npc/luban.lpc`, `inherit/condition/damo.lpc`, `adm/simul_efun/
util.lpc`, `inherit/misc/quest.lpc`, plus the ~30-file `"nosave/` →
`"static/` revert (§3 counterexample) and directory creation (`log/`,
`log/static/`, `log/user/`, `binaries/`).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (1,169 total,
  1,154 written, 12 unchanged, 3 self-checked errors left untouched).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, only the
  pre-existing benign `versiond.lpc`/`socket_bind()` message in
  `debug.log` (§15ad). Full registration flow re-verified end-to-end
  with a fresh id/real Chinese surname+given-name (`zjdytest`/秦风),
  admin+regular password, character-type + gender selection, reaching
  世外桃源; `look` (re-showed room), `score` (correctly returned "还没
  有出生呐，察看什么？" — expected pre-"投胎" message, per the documented
  design, not a bug), `quit` (clean disconnect) all confirmed correct.
  Same `--idle 0.5` live-clock-prompt workaround from the original pass
  (§15an) was still needed and still works.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots (only the expected sockets-package-unavailable-class preload
  messages), but **every login is disconnected immediately after the
  banner, before the id prompt ever appears** — root-caused via the
  harness's raw log: `versiond.lpc` genuinely uses
  `socket_create()`/`socket_bind()`/`socket_listen()` (a real
  cross-server version-sync feature), which are hard "Undefined
  function" compile errors under WASM's `sockets`-less build, leaving
  `/adm/daemons/versiond` as a program-less object; `logind.lpc`'s
  `logon()` then calls `VERSION_D->is_version_ok()` with **no
  `catch()`** (unlike the adjacent `catch(MUDLIST_CMD->main())` one line
  above it), which throws `*No program in object '/adm/daemons/
  versiond'!` uncaught — the driver's own `new_conn_handler()` treats
  this as a failed `logon()` and disconnects the connection outright
  (confirmed via `new_conn_handler: logon() on object clone/user/
  login#0 has failed, the user is disconnected.` in the raw log,
  appearing immediately after the versiond error). This is the exact
  same shape independently found on `zhonghua2` (a different lineage) in
  this same pass — evidently a common idiom across several of these
  archives (an unguarded `VERSION_D->is_version_ok()` call right after a
  guarded `catch(MUDLIST_CMD->main())`). Root cause is entirely the WASM
  sandbox's missing `sockets` package colliding with a genuinely
  socket-based feature this lib relies on — confirmed NOT a mudlib bug
  (native boots and completes full registration/login cleanly, verified
  above) — so, per the standing instruction for WASM-mode limitations,
  **not patched**. This is a distinct failure mode from the documented
  `query_ip_number()` gotcha (this lib's `logon()` doesn't even reach an
  IP-format gate before hitting this one) — noted separately for whoever
  next triages WASM playability across the "hell"/ES-II family.
  (Superseded by the 2026-07 WASM-enablement pass below — now patched.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3c/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local); `is_banned()` returns 0 for local
  sites.
- `adm/daemons/logind.lpc` `logon()` (~line 67) and `get_id()`
  (~line 130): both `VERSION_D->is_version_ok()` gates guarded with
  `find_object(VERSION_D)` — absent versiond (WASM: sockets package
  missing ⇒ program-less object ⇒ uncaught throw killed every login
  before the id prompt) now means "version ok". This was the documented
  WASM login blocker.
- `adm/daemons/closed.lpc` `heart_beat()` and `adm/daemons/questd.lpc`
  `start_all_quest()`: same `find_object(VERSION_D)` guard (both
  preloaded).
- The `iplimit > 3` per-IP cap in `logon()` is already inside `#if 0`
  (disabled upstream); no uptime()/anti-flood gates exist otherwise —
  nothing else to bypass.
- **NEW pre-existing bug found & fixed — re-login was broken for ALL
  accounts**: `clone/user/user.lpc`'s `restore()` override validates a
  "sec_id" integrity checksum with `crypt(calc_sec_id(1), sec_id) !=
  sec_id`, but its own `save()` stores `set("sec_id", calc_sec_id())` —
  the PLAINTEXT stub value `"none"`, never a crypt() of it. The
  invariant can never hold, so every re-login printed
  无法读取你的数据档案 and destructed (registration itself worked, which
  is why earlier passes — which only tested registration+look/score/quit
  in one session — never hit it). Fix (user.lpc ~line 153): also accept
  the plaintext form save() actually writes
  (`&& sec_id != calc_sec_id(1)`). Verified: plain player and fluffos
  both re-login fine now.
- Admin seeded: `fluffos` / 浮云, rank `(admin)` (top of wiz_levels) via
  `adm/etc/wizlist`. Two-password lineage: 管理密码 `Admin@2026`,
  普通密码 `Mud@2026` (must differ, same deviation as zhonghua2,
  documented in README). Registered as plain player first, wizlist entry
  added afterwards + restart (consistent with the lineage's anti-steal
  conventions). Verified: 目前权限：(admin) banner, wizard-style room
  display, `update /d/register/entry.lpc` → 成功.
- Retest: fresh registration (`regtest`/秦风) end-to-end into 世外桃源 +
  re-login as regtest (exercising the fixed restore path) + look/score/
  quit all correct; test saves removed. Final boot's debug.log clean
  except the known §15ad versiond `socket_bind()` cosmetic error.
  (Longer-running boots also surface pre-existing quest-daemon
  heart_beat errors — `Bad argument 1 to call_other` / `Bad argument 2
  to present()` in `/clone/quest/*` / `/adm/daemons/quest/*` — caused by
  the skeleton archive's missing zones, present before this pass,
  unrelated to the VERSION_D guards.)
- **Second pre-existing bug found & fixed (backported from sibling
  zjdyaryl, same symptom confirmed here): first login
  after every boot had ALL commands dead** (even `quit` → 什么？),
  working from the second login on. `logind.lpc check_ok()` lazily loads
  `MESSAGE_D` (`adm/daemons/network/messaged.lpc`) whose `create()` →
  `startup_udp()` → `socket_bind(fd, "<string>")` throws uncaught (§15ad
  get_config port-ID mismatch), aborting the first login's remaining
  setup. Fixed: `messaged.lpc create()` wraps `startup_udp()` in
  `catch()`, and `check_ok()` wraps `MESSAGE_D->find_chatter()` in
  `catch()` (also required under WASM where messaged fails to compile
  entirely). Verified: first login after a fresh boot now runs `update`
  successfully.

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: the quest-daemon `heart_beat()`
"Bad argument 1 to call_other"/"Bad argument 2 to present()" errors
(`clone/quest/judge.lpc`, `.../search.lpc`, `.../supply.lpc`,
`.../shen.lpc`) reappeared, matching the already-documented
pre-existing "skeleton archive's missing zones" class (recorded above,
unrelated to the VERSION_D guards) — confirmed still the same
already-known class, no new fix needed. `ftpd.lpc`/`versiond.lpc`
sockets-absent preload errors also match the already-documented §1.3c
class (caught, cosmetic). One genuinely new proactive fix: this lib
shares `inherit/item/combined.lpc` (`private void destruct_me()`,
`call_out`-self-invoked when a money stack hits amount 0) and
`adm/simul_efun/object.lpc` (`file_owner()` `return name` bug) with
sibling `zhonghua2`, where both fired live during that lib's sit —
ported both fixes here proactively (dropped `private` on
`destruct_me`; `file_owner()` now `return dir`) even though neither
triggered visibly in this lib's own 200s window. Retest: fresh
registration (id `zjdsanb`) into 世外桃源, look/score(pre-投胎
message)/quit clean, no regressions.

## 深度功能测试 / Deep functional test (round two, per AGENTS.md §10.7)

Native driver only (`~/src/fluffos/build-debug/src/driver config.fluffos`
from `libs/zhongjidiyu/`), `scripts/mudclient.py --idle 0.5-0.6` throughout
(this lib's live per-second clock prompt requires it, §15an/AGENTS.md §8.3
item 1 — reconfirmed still necessary). Read `help/newbie` and `help/intro`
first, in full, before touching the client — they document the actual
intended flow precisely: 水笙 `register <email>` → `decide` → walk to one
of 世外桃源's 4 exits and `out` to pick a 性格/character trait → `out`
again into 阎罗殿 (Hall of Yama) → `wash` (roll 4 innate stats) → `born
<地名>` (choose birthplace, triggers reincarnation and moves the player to
their starting zone). Safe sparring is the ordinary `fight` command
("较量" — per `help/intro`, stops before either side dies); skill learning
is `bai` (apprentice) then `xue` (learn) from an NPC teacher; sect/faction
join happens the same way, via `bai`-ing a sect NPC.

**One continuous session, two test characters** (both left in place as
evidence): `hufengbo`/秦风 (male, 猛士型, admin password `Admin@2026`,
regular password `Mud@2026`) and `muyunqing`/林枫 (female, 耐力型, same
password scheme). Both completed real registration through
`register`+`decide`+personality-room+`wash` end-to-end, confirmed via
`look`/`score`/`i` at every step. Admin account `fluffos`/浮云 (seeded by
an earlier pass) also used, with `goto`, to reach content a fresh player
account cannot (see below).

**Confirmed still correctly applied, not re-diagnosed as new:**
- §7.14's `file_size()`-boolean-context fix in `adm/daemons/virtuald.lpc`
  (`file_size(name + ".lpc") >= 0`, not a bare truthy check) — read the
  live file, matches the documented fix exactly.
- §8.3a's `private nomask command_hook` fix in `feature/command.lpc` —
  confirmed working LIVE via an NPC's own `command()` self-call, not just
  player-typed commands: 陆天抒 (the 光明磊落 personality-room NPC)
  correctly greets and speaks via `init()` → `command("hi ...")` /
  `command("say ...")` the instant a fresh character walks in, and
  地藏王's own `command("kick ...")`/`command("say ...")` self-calls in
  阎罗殿 fired correctly too. The 18-handler `adm/npc/luban.lpc` fix
  wasn't independently re-verified live (费 the feature is gated behind
  the missing `/d/city` zone, see below) but the file itself still shows
  all 18 handlers correctly `private`-free.

**Bug found #1 (NEW) — a failed `born` corrupts a real account into a
permanently no-environment login, and `enter_world()`'s own fallback chain
doesn't actually catch it.** This is the highest-impact finding of this
pass. Root cause, two parts, both fixed:

1. `d/register/yanluodian.lpc`'s `do_born()` persisted
   `startroom`/`born`/`born_family` to the player's SAVE data
   unconditionally, BEFORE checking whether the destination object
   actually resolved (`obj = load_object(dest)`/`find_object(dest)`).
   Since every `born` destination in this skeleton archive points into a
   missing zone (`/d/city`, `/d/beijing`, etc. — none exist, see gap #2
   above), literally every `born` attempt "fails" (prints "牛头一呆，
   搔搔头说：怎么好像有问题...") — but the state was ALREADY written by
   then. This flips `enter_world()`'s own `!stringp(user->query("born"))`
   safety net (which would otherwise keep an unborn player parked safely
   in `BORN_ROOM`/阎罗殿 on every future login) to false, so it stops
   applying.
2. `adm/daemons/logind.lpc`'s `enter_world()` then tries to resolve the
   now-persisted (broken) `startroom`. Its own fallback logic only
   wrapped `catch(load_object(startroom))`, not the subsequent
   `user->move(startroom)` — and `load_object()` on a path that simply
   doesn't exist (with no virtual-object fallback) returns `0` **without
   throwing**, so the `catch()` sees "no error" and falls into the
   UNGUARDED `user->move(startroom)`. `feature/move.lpc`'s `move()` does
   `call_other(dest, "???")` as its very first destination-resolution
   step, which genuinely throws (`*call_other() couldn't find object
   '/d/city/kedian'.`) for a nonexistent path — uncaught here, aborting
   `enter_world()` mid-function. Confirmed live: reconnecting as the
   already-"born" `hufengbo` printed "你无法进入这个世界，可能你的档案
   出了一些问题" and then `look` returned "你的四周灰蒙蒙地一片，什么
   也没有" — the exact §7.22 "no environment at all" symptom, but via a
   distinct mechanism (neither an eval-cost abort nor a compile error —
   a plain unguarded `call_other()` inside an un-`catch()`-wrapped
   `move()`). `score` still worked (doesn't need an environment), which
   is what made this state look survivable at a glance — `look`/movement
   were the ones silently dead. This lib's own hardcoded `START_ROOM`
   fallback (`/d/city/kedian`) is ALSO one of the missing paths, so even
   the "else" branch's intended recovery was reaching for a target that
   doesn't exist either.

   **Fix, two parts** (both live-verified — see below):
   - `d/register/yanluodian.lpc`: moved the `!objectp(obj)` failure
     check to immediately after `obj` is computed, in BOTH the
     plain-string and the family/世家 branches, before any `me->set(...)`
     call. A failed `born` now leaves the account's `startroom`/`born`
     fields untouched, exactly as if `born` had never been attempted.
   - `adm/daemons/logind.lpc`'s `enter_world()`: wrapped the actual
     `user->move(startroom)` in `catch()` too (not just
     `load_object()`), and added a THIRD fallback level — if even
     `START_ROOM` fails to load/move into (true on this specific
     archive), fall back to `BORN_ROOM` (阎罗殿, always present) instead
     of leaving the player with no environment at all.

   **Live verification**: before the fix, reconnecting as `hufengbo`
   (who had already `born`ed to a missing destination in a prior session)
   reproduced the crash exactly as described, with `*call_other()
   couldn't find object '/d/city/kedian'.` in `debug.log`. After the fix
   (driver restarted to pick it up), the SAME already-corrupted
   `hufengbo` account now lands in 阎罗殿 via the `BORN_ROOM` fallback
   (kicked onward to `虚空`/void by 地藏王's own already-correct "you're
   already born, get out" NPC logic — a real, pre-existing, working game
   mechanic, not a bug), and `look`/`score`/movement/`quit` all work
   normally from there — no more no-environment state. Separately, a
   FRESH character (`muyunqing`) that ran `wash`+`born <missing dest>`
   AFTER the fix correctly stayed in the "not yet born" state
   (`score` → "还没有出生呐，察看什么？", still standing in 阎罗殿 with
   地藏王 still willing to hand over the newbie book) on both the
   immediate next command and a later real reconnect — confirming the
   root-cause fix (part 1) prevents the corruption from happening at all
   for any new account, while the defense-in-depth fix (part 2) also
   protects any account that manages to reach a broken `startroom` by
   some other path. No new `debug.log` errors from any of this.

   Doesn't match any existing catalog entry exactly — closest are §7.14
   ("missing post-registration destination room... guard the move with
   load_object()/fallback to START_ROOM") and §7.22 (the "no environment
   at all" symptom shape) but the specific mechanism (a `catch()` that
   only wraps the probe call, not the actual unguarded `move()` right
   after it, PLUS a state-mutation-before-validation ordering bug in the
   caller) is new. Worth a full write-up as a candidate new §7.x entry —
   see final report.

**Bug found #2 (matches AGENTS.md §8.3a's addendum exactly, not new) —
`feature/action.lpc`'s `eval_function()` was still `private`.** Found live:
`apply() with insufficient permission: ... function: eval_function,
origin: internal, needs: private, has: hidden` fired in `debug.log` during
ordinary play (a delayed-effect `call_out` against our own test
character's body). This is the SAME file and SAME function name as the
`xuanjianlu`-derived precedent already in §8.3a's addendum ("the shared
'delayed status effect' primitive used by 130+ kungfu-skill/drug files").
The lib's own "WASM long-sit boot-watch pass" note (above) proactively
ported §8.3a's addendum fix for `inherit/item/combined.lpc`'s
`destruct_me()` and `adm/simul_efun/object.lpc`'s `file_owner()` from
sibling `zhonghua2`, but missed this THIRD instance — `feature/action.lpc`
itself apparently wasn't part of that proactive sweep. Fixed identically:
dropped `private`, kept the function otherwise unchanged. Proactively
grepped the whole lib (every `call_out("name", ...)` site cross-referenced
against a same-file `private` declaration of `name`) for any other
instance — found none: every other flagged hit is a call_out target
defined in a standalone daemon/NPC/command file that is never `inherit`ed
elsewhere (confirmed via `grep -rl 'inherit.*"<path>"'`), so the
DECL_PRIVATE→DECL_HIDDEN-once-inherited mechanism doesn't apply to them.

**Bug found #3 (matches AGENTS.md §7.25 exactly, not new, but a genuinely
new instance/location) — `inherit/room/room.lpc`'s shared
`make_inventory()` had no guard, crashing the ENTIRE afterlife zone's
first-ever visit.** `d/death/npc/wgargoyle.lpc` ("白无常") and
`d/death/npc/bgargoyle.lpc` ("黑无常") both call `set_skill("dodge", ...)`
in their own `create()` — and this archive's `/kungfu/skill/` directory is
**entirely absent** (not just the `/d/city`-style zone rooms already
documented in gap #2 — the base skill-file tree itself is missing, a
broader gap than previously written up). `feature/skill.lpc`'s
`set_skill()` correctly `error()`s on a missing skill file, but that
`error()` fires DURING the NPC's `create()`, which `new()` propagates as
an uncaught throw — and `inherit/room/room.lpc`'s `make_inventory()`
(`ob = new(file); ob->set(...); ob->move(...); return ob;`, called from
every room's `reset()`, lib-wide) had zero `catch()` around any of it.
Live-reproduced via admin `goto /d/death/gate` (`DEATH_ROOM`, where every
player death sends them via `feature/damage.lpc`'s `die()`): the room's
FIRST-EVER `reset()` this boot aborted entirely, so `goto` silently failed
to move the admin there at all (landed back at start with only a
`debug.log` trace: `*F_SKILL: No such skill (dodge)`, blamed at
`wgargoyle.lpc`'s `create()` via `room.lpc`'s `make_inventory()`). Same
shape independently confirmed for `bgargoyle.lpc` in `/d/death/gateway`.

Fix: wrapped `make_inventory()`'s `new()`/`set()`/`move()` chain in
`catch()`, returning `0` on any failure (destructing a
partially-constructed object first if `new()` itself did return one); and
guarded the ONE call site in `reset()`'s `case 1:` branch that
dereferenced the result without an `objectp()` check
(`ob[list[i]]->is_character()`) — the `default:` (multi-object) branch
already `continue`d past the equivalent dereference for a freshly-`(re)`-
made entry, so it didn't need the same guard. **Live-verified this
unblocked the ENTIRE death/afterlife zone**, not just the one room: after
the fix, admin `goto` successfully reached and `look`ed at all 8 death-zone
rooms (`gate`/鬼门关, `road1`/`road2`/`road3`/鬼门大道, `inn1`/小店,
`inn2`/黑店, `god1`/天堂, `god2`/圣殿, `block`/空房间, `gateway`/酆都城门)
with zero further errors beyond the two now-gracefully-caught
missing-skill NPCs — this whole zone is otherwise 100% present and intact
in the archive, just unreachable-on-first-visit before this fix. Matches
§7.25's established pattern and fix precisely; the missing `/kungfu/skill/`
tree itself is left alone as a genuine archive content gap (not
fabricated) — 白无常/黑无常 simply never spawn, same graceful-degradation
outcome §7.25 already prescribes for this shape.

**Confirmed content gap, broader than previously documented**: the
`/kungfu/skill/` directory (referenced by `include/globals.h`'s
`SKILL_D(x)` macro, `"/kungfu/skill/" + x`) does not exist AT ALL in this
archive — not one basic skill file (`dodge`, `force`, `unarmed`, etc.,
all named in `help/newbie`'s own example `cha` output) is present, beyond
the previously-documented missing `/d/city`-style zone rooms. This means
even IF a player could reach a populated zone, `xue`/`learn`-style skill
acquisition would have nothing to actually load. Documented here, not
fabricated — matches the archive's own "study source, skeleton release"
disclaimer.

**Safe-sparring / skill-teacher / sect-join — confirmed NOT reachable live,
by design of this skeleton archive, not a bug.** Every currently-existing
room in the archive (`d/register/*`, `d/pk/*`, `d/death/*`) explicitly sets
`no_fight: 1` — the `fight` command (§ help/intro's "较量") is real,
present, and correctly wired (`cmds/std/fight.lpc` exists and is a normal
add_action command), but there is no reachable room anywhere in this
archive where combat is actually enabled. The `bai`(apprentice)/`xue`
(learn) skill-teacher path and every sect-join NPC live under the missing
`/d/<sect>` zones (§13/gap #2) and, per the finding above, even the
underlying skill FILES they'd teach don't exist either. `d/pk/` ("屠人场"
— a PK tournament arena, `乌老大`'s `sign`/`join` commands) is a distinct,
unrelated feature (scheduled PvP, not the newbie-doc's safe `fight` spar)
and is itself a dead end too (`west` exit → `/d/changan/...`, missing).
Consistent with, and extends, this lib's own already-documented "skeleton
archive" gap — not attempted to fabricate.

**Shop purchase / combat / death — explicitly NOT tested live, and
cannot be, given the above.** No shop, no fightable NPC, and no death
trigger is reachable by an ordinary player account in this archive's
current content. Code review only: `feature/damage.lpc`'s `die()` calls
`me->move(DEATH_ROOM)` (`/d/death/gate`, confirmed to exist and — after
Bug #3's fix — load cleanly) and `DEATH_ROOM->start_death(me)`; this path
was not exercised by an actual player death since no live combat path
exists to trigger it.

**`quit` + `debug.log` grep, both unclean (net-dead) and clean-quit
reconnect, both prompt and after a real wall-clock gap**: all tested, all
clean.
- Clean `quit` (both test characters, multiple times): correct "欢迎
  下次再来！" message, unequipped-item drop logic runs without error
  (both characters' items were all `equipped`, so the drop loop's
  `message("vision", ..., environment(me), ...)` call — which is NOT
  itself guarded by an `environment(me)` check, only by whether any items
  were actually dropped — was never exercised with a null environment;
  noted as a theoretical residual risk but not reproduced, see final
  report).
- Every `quit` immediately followed by a same-second reconnect attempt
  correctly hit the documented 30-second quit-retention lockout ("你距
  上一次退出时间只有N秒钟，请稍候再登录。") — confirms this project's own
  established §10.7 caveat about the lockout window in practice.
- Prompt reconnect after an UNCLEAN disconnect (letting `mudclient.py`'s
  connection simply close without sending `quit`, simulating a network
  drop): correctly printed "重新连线完毕" and resumed in the exact same
  room with no state loss — this lib's `net_dead()` (`clone/user/
  user.lpc`) does NOT use a `VOID_OB`-parking pattern at all (confirmed by
  reading the code: the player object is simply left in its current
  environment, heart_beat disabled, and a 900s `user_dump` call_out
  scheduled) — so the §7.20 "void-parking without a location-restore
  path" bug class structurally cannot occur here; `reconnect()` just
  clears the `net_dead` flag and re-enables commands in place. No
  location-restore step is even needed.
- Reconnect after a clean `quit` AND a genuine ~50s+ real wall-clock
  wait (past the lockout): went through the FULL fresh-login code path
  (login banner + "你上次光临终极地狱是 ... 连接的" last-visit message,
  not the short-circuit "重新连线完毕"), landed back in the exact same
  room/state (`muyunqing`: still 阎罗殿, still un-born, 地藏王 handed the
  newbie book again since it wasn't in inventory) — full persistence
  confirmed correct.
- The full `NET_DEAD_TIMEOUT` (900s / 15 minutes) `user_dump`
  force-quit-after-abandonment escalation path was NOT exercised live
  (would require a 15-minute uninterrupted wait) — reviewed via code
  instead (`clone/user/user.lpc`'s `user_dump()`/`DUMP_NET_DEAD` case:
  announces the timeout to the room, then `command("quit")` with a
  `force_quit()` fallback if that fails) and looks correct/unremarkable,
  but this specific path is unverified live, per §10.7 item 6's
  explicit-fallback allowance.

## Files touched, this pass

- `libs/zhongjidiyu/work/d/register/yanluodian.lpc` — `do_born()`: check
  `objectp(obj)` before persisting `startroom`/`born`/`born_family`
  state, in both branches (Bug #1, part 1).
- `libs/zhongjidiyu/work/adm/daemons/logind.lpc` — `enter_world()`: wrap
  `user->move(startroom)` in `catch()` too (not just `load_object()`),
  add a `BORN_ROOM` last-resort fallback beyond `START_ROOM` (Bug #1,
  part 2).
- `libs/zhongjidiyu/work/feature/action.lpc` — `eval_function()`: dropped
  `private` (Bug #2, matches §8.3a's addendum).
- `libs/zhongjidiyu/work/inherit/room/room.lpc` — `make_inventory()`:
  wrapped in `catch()`, returns `0` on failure instead of propagating;
  `reset()`'s `case 1:` call site guarded with `objectp()` before
  dereferencing (Bug #3, matches §7.25).
- Test character saves left in place as evidence:
  `data/login/h/hufengbo.o` + `data/user/h/hufengbo.o` (秦风, the account
  that reproduced Bug #1 pre-fix and was re-verified recovering post-fix),
  `data/login/m/muyunqing.o` + `data/user/m/muyunqing.o` (林枫, registered
  entirely after the fix, confirms no regression for a clean account).
  `data/user/f/fluffos.o` (admin) timestamp-touched by ordinary login, no
  content change beyond `last_on`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

尽管标题相似，但和 hell 那对"终极地狱"没有关系。状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'目前权限：(admin)'。另外还发现并修复了一个和手足档案 zjdyaryl/zjdyzj 共有的真实 bug：clone/user/login.lpc 的 query_save_file() 只防范了 id 不是字符串的情况（!stringp(id)），没有防范空字符串的情况——对 "" 取 id[0] 会回传整数 0，而 sprintf 的 %c 格式会拒绝这个值（'Incorrect argument to type %c, must be valid UTF8 char'），在任何 id 被输入之前，第一次自动呼叫 query_save_file() 就会崩溃。已通过额外检查 id == "" 修复。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 43 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 39 live
`replace_program(ROOM);` occurrences across 38 files: 18
`clone/megazine/*.lpc` rooms, `clone/misc/void.lpc`, a 12-file
`d/pk/turen*.lpc` cluster, a 6-file `d/death/*.lpc` cluster, plus this
lib's own room-building tool `clone/misc/roommaker.lpc` (both a
standalone line and a separate string-builder template line, both
fixed) — so newly-built rooms were inheriting the bug too. A full
post-fix grep confirms 0 live occurrences remain. Verified via a clean
native driver boot (zero new `debug.log` errors, port listening, killed
by exact PID after ~8s).
