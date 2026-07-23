# 炎黄英雄史 (Yanhuang Heroic History) — conversion notes

Archive: `archives/炎黄英雄史.rar` (archive #67). Extracted root:
`raw/yh2003/mud/` (the archive bundles the mudlib source alongside a
prebuilt Windows MudOS driver/binaries — `MudOS.exe`, `MudOSxp.exe`,
`mudos.dll`, `runmud`/`runqym` launch scripts, an `addr_server` helper —
all ignored, only the LPC mudlib under `mud/` was converted).

## Identity / naming

- `config.cfg`'s own `name : 炎黄英雄传` field says "Yanhuang Heroic
  **Legend**" (传), but the live banner text baked into `logind.lpc`
  (shown at the character-type-selection prompt: `在「炎黄英雄史」中您想要
  扮演的角色类型`) says "Yanhuang Heroic **History**" (史) — matching the
  archive's own title exactly. Slug kept as `yanhuangyingxiongshi` to match
  the archive; `name` in `config.fluffos` left as the config file's own
  value (炎黄英雄传) since that's what the config itself declares, with a
  comment noting the discrepancy.
- Collector-site marker file `小熊泥苑.txt` (converted, readable) confirms
  this came through the same "小熊泥苑" (dtxy.126.com) collector/rehost as
  `shujiantianxia` (archive #36) — unrelated to this lib's actual game
  content, just a distribution wrapper.
- Credits inside the code: `master.lpc`: "for ES II mudlib / original from
  Lil / rewritten by Annihilator (11/07/94) / modified by Xiang for XKX
  (12/15/95) / updated by Doing Lu for hell (2K) / **Modify By Linux@lxtx
  for yh 2003.3**". `securityd.lpc`: "Modified by Xiang for XKX / Updated
  by DOing Lu for ULTRA HELL". `chinesed.lpc`: "modified by Xiang@XKX".

## Lineage: confirmed shared codebase with yanhuangwuhun (archive #66)

Per the task's explicit instruction to check this, diffed this lib's core
files directly against `libs/yanhuangwuhun/work/` (both are "yh"/炎黄-
branded forks of the same ES II-family codebase, per the identical
"Linux@lxtx for yh 2003.3" master.lpc credit line — confirmed NOT a
coincidence of similar titles, but genuinely close-cousin lineage):

| file | diff size vs yanhuangwuhun | verdict |
|---|---|---|
| `adm/single/master.lpc` | 44 lines | near byte-identical; all diffs are wuhun's own already-applied fixes (§14 3-arg valid_override, `.c`→`.lpc` refs) or its bespoke `STATIC_VAR_TAG`/`STATIC_FUNC_TAG` macro naming choice (this lib used the standard `nosave` sed instead, see below) |
| `adm/daemons/securityd.lpc` | 44 lines | same story — content identical, diffs are wuhun's §15n fix (already ported here) + macro-naming choice |
| `adm/daemons/chinesed.lpc` | 33 lines | same engine, different site credit ("modified by Xiang@XKX" vs wuhun's "modified by Ivy@Heros.YD"); one extra `chinese_date()` arg difference (unrelated, cosmetic) |
| `adm/daemons/named.lpc` | 69 lines | same `PATH()`/sliding-window shape, diffs are wuhun's already-applied §15h fix |
| `adm/simul_efun/chinese.lpc` | 17 lines | **identical** `is_chinese()` GBK byte-range bug, byte-for-byte, diffs are wuhun's already-applied §15h fix |
| `adm/simul_efun/message.lpc` | large | **identical** §15aa forward-reference bug (bare `message(...)` calls before the file's own override), diffs are wuhun's already-applied fix |
| `adm/daemons/logind.lpc` | 192 lines | same overall flow (id → confirm → surname → given-name → admin-password → password → type → gender → enter_world); diffs are wuhun's fixes plus genuine site-specific content differences (banner name, item drop tables, `banned_id` list wuhun added, balance numbers) — NOT a byte-identical file, a real (if close) sibling, not a re-host |
| `adm/single/simul_efun.c`/`.lpc` (composition list), `wizard.lpc`, `object.lpc`, `gender.lpc`, `override.lpc` | 0-13 lines | effectively identical; **confirms no simul_efun-based `set`/`query`/dbase architecture bug (§15) in this lineage** — same as every other ES II-family lib processed so far (es1_win/esI/xkx2001/rzrmud/xo/yueyingqiyuan/wuhanzhan/haiyang2/yanhuangwuhun) |

**Verdict**: genuinely the same underlying "yh 2003" ES II derivative as
yanhuangwuhun, most likely two different sites' snapshots/branches of the
same base rather than one being a copy of the other (both have real,
independent gameplay-content differences, not just branding). Every proven
fix from yanhuangwuhun's pass was ported directly here after confirming
each one's exact shape still matches (rather than re-discovered from
scratch), and this DID save real time — but two NEW bugs were found here
that yanhuangwuhun's NOTES.md never mentions (see below), so this was not
a rubber-stamp port; each fix was verified against this lib's own source
before applying.

## Fixes applied (with why)

1. **§15h — `is_chinese()` GBK byte-range check** (`adm/simul_efun/
   chinese.lpc`): byte-for-byte identical bug to every other lib in this
   project — `str[i] < 161 || str[i] == 255` / `!(i%2) && (str[i] < 176 ||
   str[i] >= 248)` are GBK lead/trail-byte range checks, meaningless
   against this driver's UTF-8 codepoints. Rewritten as a CJK Unified
   Ideographs codepoint range check (`str[i] >= 0x4e00 && str[i] <=
   0x9fff`), `strlen(str) < 2` relaxed to `< 1` (was "at least one full
   GBK char" = 2 bytes).
2. **§15h — `named.lpc`'s `PATH()` macro + sliding-window + length
   guards**: `PATH(name)` used `name[0..1]` ("first GBK char", 2 bytes) →
   `name[0..0]` (first character). Every `strlen(name) < 2`/`< 4` guard
   halved to `< 1`/`< 2`. The similar-name sliding-window loop
   (`name[i..i+3]` 2-char window / `name[i..i+5]` 3-char window, `i <= l -
   4`) converted to character-width (`name[i..i+1]` / `name[i..i+2]`, `i <=
   l - 2`).
3. **§15h — `logind.lpc`'s `check_legal_name()`**: byte-length bound
   `maxlen` (called as `check_legal_name(arg, 4)` for both surname and
   given name) halved via `maxlen / 2` inside the function; minimum bound
   `strlen(name) < 2` → `< 1`. Separately, the **combined** surname+given-
   name length guard (`if (strlen(fname) < 4)` after concatenating both
   parts, message says "至少要有两个汉字" — "at least 2 Chinese
   characters") halved to `< 2`, matching the message text exactly (this
   is the same "second site, found only by testing all the way through"
   gotcha documented in AGENTS.md §15h — a text search for
   `check_legal_name` alone would have missed this one).
4. **§14 — `valid_override()` 2-arg → 3-arg** (`adm/single/master.lpc`):
   added the `main_file` parameter and the `main_file == SIMUL_EFUN_OB ||
   main_file == MASTER_OB` check, so an `efun::` override written in an
   `#include`d simul_efun fragment (e.g. `message.lpc`, `#include`d into
   `simul_efun.lpc`) is correctly recognized as legitimate.
5. **§15n — `securityd.lpc`'s `valid_read` ACL allowlist**: added the
   `switch(func) { case "load_object": case "recompile_object": case
   "include": return 1; }` early-allow (same insertion point as every
   other lib with a custom securityd — right after the existing `func ==
   "file_size"` check), so the driver's own compile-time lazy
   load/recompile/`#include` never gets attributed to a fresh
   not-yet-authenticated connection's `(player)` status and denied.
6. **§15aa/§15s — `message.lpc`'s forward-reference + int-0-exclude bug**
   (`adm/simul_efun/message.lpc`): `tell_object()`/`tell_room()`/
   `shout()`/`write()`/`say()` all call the bare `message(...)` name
   BEFORE the file's own `message()` override is textually defined further
   down — silently binding straight to the real efun (no "undefined
   function" error, since `message` IS a real efun name) and bypassing the
   override's exclude-argument fix entirely for every one of those call
   sites. Fixed with a `varargs void message(...)` forward declaration at
   the top of the file, and the override itself made `varargs` with an
   explicit `if (!exclude) efun::message(arg,message,target); else
   efun::message(arg,message,target,exclude);` guard (a bare `int 0`
   passed as the 4th/"exclude" argument does not satisfy this driver's
   `void | object | object *` type for that parameter and throws "Bad
   argument 4 to EFUN message()" at runtime otherwise).
7. **§15p — `dns_master` excluded from `adm/etc/preload`**: was present
   (`/adm/daemons/network/dns_master`), removed proactively before the
   first boot attempt. Grepped the whole lib for inline `DNS_MASTER`/
   `Mud_name()` calls from login/display code per §15ab's follow-up
   lesson — none found outside `adm/daemons/network/` itself and header
   macro definitions, so the preload exclusion alone is sufficient here
   (unlike haiyang2, which needed a second inline-call fix too).
8. **NEW — `clone/user/user.lpc`'s `is_killing(ob)` type mismatch**
   (found via interactive testing, not the lpcc sweep — this file is only
   ever reached live via `new(USER_OB)` mid-connection, never preloaded):
   `accept_kill(object ob)` called `is_killing(ob)` directly (a bare,
   non-`->` call) where `is_killing(string id)` (defined in
   `feature/attack.lpc`) declares a `string` parameter — every one of the
   ~50 other call sites in the lib correctly calls
   `is_killing(ob->query("id"))`. Because it's a **direct** function call
   (not `->`), this driver's static type checker enforces the declared
   parameter type strictly and refused to compile the whole
   `/clone/user/user.lpc` file — silently blocking `make_body()` right
   after gender selection, with **zero error visible to the connecting
   player** (the connection just stalled with no room/prompt after "您要
   扮演男性(m)的角色或女性(f)的角色？"). This is the exact same failure
   shape documented in AGENTS.md §15b's "General lesson" (found originally
   on `nitan_ceshi`/archive #60, unrelated lineage — same bug pattern
   recurring independently, not shared code). Root cause confirmed by
   reading `debug.log`'s compile-error section
   (`clone/user/user.lpc:568:26: error: Bad type for argument 1 of
   is_killing ( string vs object )`) rather than guessing. Fixed by
   changing the one call site to `is_killing(ob->query("id"))`. **This bug
   is NOT present in yanhuangwuhun's NOTES.md** — a genuine new finding on
   this sibling lib, not something that could have been ported.
9. **NEW — `master.lpc`'s `error_handler()` given a permanent log-write
   insurance** (§15w's second finding): the existing `error_handler()`
   only calls `tell_object()` when there's an interactive `this_player()`
   present; its own comment ("whatever we return goes to the debug.log")
   is stale — this driver's `error_handler` apply is declared `void`, so
   the return value is discarded, not logged. Added an unconditional
   `efun::write_file(LOG_DIR + "RUNTIME_ERRORS", standard_trace(error,
   caught));` at the top of the function so runtime errors are never
   silently lost when there's no player to show them to. (This lib's
   `log_error()` — the OTHER apply, for compile *warnings* — already had
   its player-facing broadcast lines commented out by the original author,
   so §15w's main "warning-spam" bug does NOT apply here; see "confirmed
   not needed" below.)
10. **§3 — `static` → `nosave` blanket sed** (via `convert_lib.sh`, 147
    files touched) — standard mechanical fix for the "static on a
    function is a hard parse error" issue.
11. **§3 counterexample — string-literal collision revert** (moniHuafu-
    style, found independently here, same magnitude as yanhuangwuhun's own
    105-occurrence finding): the blanket sed also rewrote **104
    occurrences across 64 files** of `"static/..."`-prefixed property keys
    and log-file paths (e.g. `log_file("static/CRASHES", ...)`,
    `me->query("static/marry")`, `me->add_temp("static/drop_npc", 1)`) to
    `"nosave/..."`, silently changing on-disk log paths and in-memory
    property key names away from what the rest of the (unconverted, or
    correctly-untouched) code and existing save data still expect.
    Reverted all 104 with `sed -i 's/"nosave/"static/g'` scoped to the 64
    affected files. Confirmed correct (not a guess) by checking that
    `log/static/` is a real, pre-existing, populated directory in this
    lib's `work/` tree (`log/static/bug`, `log/static/call_player`, etc.)
    — the sed would have orphaned all of that.

6 more genuine fixes were found via the `lpcc` sweep (not needed for the
registration path itself, but real compile bugs nonetheless) — see the
"lpcc sweep" section near the end of this file for the full writeup:
`inherit/condition/damo.lpc` (missing-quote typo, §10), `inherit/misc/
quest.lpc` (`set_information()` signature), `adm/daemons/questd11.lpc`
(9 split-identifier/string corruptions, a new pattern), `adm/daemons/
eventd.lpc` + `adm/daemons/storyd.lpc` (§2 rename-width bug, `[0..<3]` →
`[0..<5]`, also applied proactively to `adm/npc/luban.lpc`), and
`d/city/npc/guidao.lpc` (a second, independent instance of the
`is_killing()` type-mismatch bug).

## Confirmed NOT needed (and how confirmed)

- **§4 (master.lpc lazy security-daemon load recursion)**: `master.lpc`'s
  `valid_read`/`valid_write` use the simple `find_object(SECURITY_D)`
  pattern (no `load_object()` call at all) — read the actual functions,
  confirmed no lazy-load-during-compile recursion risk.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both already present and
  correctly implemented in `master.lpc` (return `ROOT_UID`/`BACKBONE_UID`)
  — grepped and read, no fix needed.
- **§8d/§15o (`get_include_path()`)**: no lib-relative `<local.h>`-next-
  to-its-user `#include` pattern found anywhere (checked every `#include
  <x.h>` against the actual on-disk location of `x.h`) — neither this lib
  nor yanhuangwuhun implements `get_include_path()`, consistent with this
  lineage simply not using that idiom.
- **§15 (simul_efun-based dbase architecture bug)**: `adm/simul_efun/
  wizard.lpc`/`object.lpc` etc. have no bare `set`/`query`/`delete`
  simul_efuns at all (confirmed identical to yanhuangwuhun's own, already-
  verified-clean copies) — this ES II-lineage family uses per-object
  `inherit F_DBASE` throughout, the architecturally correct pattern, not
  the nitan-family bug.
- **§15l (master.lpc destructing `SIMUL_EFUN_OB` in `create()`)**:
  `master.lpc create()` is a single `write()` line, no `destruct()` call
  anywhere near it — read directly, confirmed absent.
- **§15u (dormant phone-home license-check function)**: grepped
  `securityd.lpc`/`master.lpc` for `shutdown()`/mass-`rm`/`unlink`
  patterns gated on an opaque check — none found.
- **§15r (check_config.lpc driver-version self-check)**: no such file
  exists in this lib at all.
- **§15t (absolute-path angle-bracket includes / `..`-relative includes /
  inherit-after-globals ordering)**: grepped for all three patterns
  lib-wide — zero hits of any of the three.
- **§8f (bare `TYPE * name1, name2;` forgotten-star bug)**: 74 lines match
  the shape on a first grep, but spot-checking several (e.g.
  `feature/equip.lpc`'s `string *apply, type;`) confirmed the scalar
  variable (`type`) is genuinely only ever assigned/used as a scalar
  (`stringp(type = query("armor_type"))`) — the shared declaration line is
  intentional, not a "forgotten star" bug (unlike ds386/Dead Souls, a
  different, English-language lineage where this pattern was a genuine
  bug). No fix applied; the lpcc sweep (below) would have caught any
  genuine instance as a "Bad assignment"/"bad type" error and none turned
  up tied to this pattern.
- **§15f (bare `array` type declaration)**: zero hits — this ES
  II-lineage family doesn't use the "NT/nitan/Lonely" idioms at all.
- **§15v (`LONELY_IMPROVED`-gated `efun::` calls)**: not applicable, wrong
  lineage (nitan-family only).
- **§8h (convertd.lpc Greek-table backslash typo)**: no `convertd.lpc` file
  exists in this lib at all.
- **§15k (case-sensitive data file paths)**: checked `WIZLIST` (`/adm/etc/
  wizlist`, referenced exactly as `"/adm/etc/wizlist"`) and the `welcome`
  banner file (`/adm/etc/welcome`, referenced exactly) — both match
  on-disk case exactly.
- **§15ab-1 (missing `!stringp(str)` guard in the pre-login
  `receive_message()`)**: `clone/user/login.lpc`'s `receive_message()`
  calls `receive(str)` unconditionally with no guard — a latent risk
  matching this pattern, BUT no code path in this lib calls `write(0)`
  during connection setup (no `LASTCRASH`-reading `uptime.lpc`, unlike
  wuhanzhan/haiyang2 — this lib's `uptime.lpc` never reads a file at all),
  so it was never actually triggered; confirmed via full interactive
  testing (multiple clean connects with zero crash) rather than left as a
  pure guess.
- **§15x (hardcoded `MUD_PORT` mismatch)**: `master.lpc`'s `connect()`
  apply does no port-based dispatch/validation at all (just creates a
  `LOGIN_OB` and returns it) — confirmed by reading the function; no
  MUD_PORT-style constant gates the connection anywhere.
- **§15y (mixed GBK+BIG5 config.cfg)**: visually skimmed every
  user-facing string in the converted `config.fluffos` (`default fail
  message`, `default error message`, the mud `name` field) plus
  `小熊泥苑.txt` — all read as coherent, correctly-topical Chinese, no
  BIG5-decoded-as-GBK mojibake found. `convert_lib.sh` logged zero lossy
  conversions for `config.cfg` itself.
- **§15z (`#define nosave static` compatibility-shim collision)**: no
  `#define nosave static` / `#define protected static` shim present
  anywhere in `include/*.h` — grepped, zero hits.
- **§15w main finding (log_error() broadcasting warnings as errors)**:
  `master.lpc`'s `log_error()` has its player-facing `tell_object()`/
  `efun::write()` broadcast lines **already commented out** by the
  original author (only `efun::write_file(LOG_DIR + "log", message)`
  remains active) — confirmed by reading the function directly; no
  spam-to-players risk exists here at all, so nothing to fix (only the
  secondary `error_handler()` insurance write was added, per fix #9
  above).

## New finding NOT yet in AGENTS.md's catalog: `get_config()`/
`runtime_config.h` numeric-ID mismatch (flagged for the main session to
consider cataloguing)

`adm/daemons/versiond.lpc:245` does `port = get_config(__MUD_PORT__) +
VERSION_PORT;` then `socket_bind(vfd, port)`. `__MUD_PORT__` is defined in
this lib's own `include/runtime_config.h` as `CFG_INT(0)` under an
old-MudOS-era numbering scheme (`BASE_CONFIG_INT = 14`, so `__MUD_PORT__`
= numeric ID 14) — but this modern FluffOS driver's actual `get_config()`
implementation uses its OWN internal numeric-ID table (unrelated to this
old header's numbering), so `get_config(14)` silently queries the WRONG
config slot on this driver (empirically returned an empty string, not the
real port int). `"" + VERSION_PORT` (a string + an int) then string-
concatenates instead of adding, producing the literal string `"12"`,
which fails `socket_bind()`'s type check (`Bad argument 2 to socket_bind()
Expected: int Got: "12"`). This is a **non-fatal runtime error** (caught
by the driver at the point of the bad efun call, doesn't crash the whole
process or block boot/login) that fires exactly once per boot (`versiond`
calls this from a single `call_out("in_server", 2)` 2 seconds after
`create()`, not on a repeating heartbeat).

**Confirmed harmless to the registration/login flow, not just assumed**:
read `versiond.lpc`'s `setup()` — `version_ok` is set to `1`
**synchronously inside `create()`** (before the 2-second delayed
`in_server()` call ever fires) whenever `RELEASE_SERVER() == "local"`,
which this lib's `adm/etc/config` does declare (`release server : local`).
`logind.lpc`'s login-gate check (`! VERSION_D->is_version_ok() && !
VERSION_D->query_temp("operator")`) is therefore already satisfied by the
time any player could possibly connect, completely independent of whether
the later broken `socket_bind()` call succeeds — unlike zhonghua2's §15m
finding, this is NOT a case of a crashed `create()` silently blocking a
readiness flag. Left unfixed (out of scope: `versiond`'s peer-sync
listening socket is release-server-to-release-server functionality,
irrelevant to a single standalone instance in this project), but flagged
here in case another lib in this batch hits the same `get_config()`
numeric-ID mismatch in a context that DOES matter (e.g. if some other
lib's registration-critical code path also calls `get_config()` with one
of these old-style numeric macros) — this project's fix catalog
(AGENTS.md) doesn't have a section for this class of bug yet.

## Other observations (not bugs)

- `feature/feature/` is a whole duplicate copy of most of `feature/`'s
  files, present in the RAW archive itself (not a conversion artifact) —
  confirmed nothing references any `feature/feature/...` path anywhere in
  the lib (`grep -rl` came up empty besides the files themselves).
  Harmless orphaned content from the original author, left as-is (same
  "don't fabricate/prune content that isn't actually broken" policy as
  AGENTS.md §12/§13).
- 5 files hit `convert_lib.sh`'s lossy-conversion path (invalid GBK bytes
  dropped): 2 `data/analecta/2003/*.txt` seed data files, `adm/daemons/
  quest/{capture,deliver}.c`, and `cmds/{arch,archBAK}/recovermud.c` (a
  duplicate pair). Inspected all 5 post-conversion — all end cleanly at a
  normal function-closing brace, no truncated string literals or merged
  heredoc-tag lines (the §"iconv -c eats a real byte too" failure mode
  documented for other libs) — confirmed non-issues, not just assumed.
- The old `config.cfg` has a genuinely duplicate `global include file`
  directive (`<globals.h>` early in the file, `<global.h>` — no `s`,
  referencing a file that doesn't exist — later, both outside any comment
  block). Confirmed harmless by reading FluffOS's own config parser
  (`src/base/internal/rc.cc`'s `scan_config_line()`): it scans line-by-
  line and takes the FIRST match, so the correct `<globals.h>` wins
  regardless of the later duplicate. No fix needed in `config.fluffos`.

## Registration flow — exact transcript outcome

Read `logind.lpc`'s full `input_to` callback chain first
(`logon → get_id → confirm_id → get_surname → get_name → [invalid_new_name
check] → new_ad_password → confirm_ad_password → new_password →
confirm_password → get_type → get_gender → make_body/enter_world`) before
scripting the test — no hidden pre-id gate (no BIG5/student-age/client-
version prompt); the very first prompt genuinely is the English id.

**Gotcha hit while testing** (worth recording as it re-confirms an
existing AGENTS.md lesson): a first attempt used `qinfeng2` as the English
id — REJECTED (`check_legal_id` requires pure English letters, 3-10
chars), which loops back to the SAME "您的英文名字" prompt. Every
subsequent `--send` in that run (`y`, `秦`, `岭`, ...) was silently
consumed as a FAILED retry of the id prompt (each one also failing the
letters-only check) until the literal string `"look"` (from later in the
send list) accidentally satisfied the id format and got treated as a real
id attempt, followed by `"quit"` being consumed as its y/n confirmation
answer — producing a confusing, cascading-looking transcript that had
nothing to do with the Chinese-name logic at all. Re-verified with a
corrected id (`qinfeng`, no digit) and the flow proceeded correctly (same
"always read the actual callback chain" + "re-verify one prompt at a
time" lessons AGENTS.md already documents for other libs, re-confirmed
here for a completely mundane reason — a bad test id, not a mudlib bug).

**Full successful run** (`mudclient.py 127.0.0.1 40061`, one continuous
connection, after the `is_killing()` fix):
```
--send "qinfeng"     -> accepted as new id
--send "y"           -> confirmed new-character creation
--send "秦"          -> accepted as surname (real Chinese character)
--send "岭"          -> accepted as given name (real Chinese character,
                        combined "秦岭" passes is_chinese/length/
                        invalid_new_name checks)
--send "adminpass1"  -> admin password set
--send "adminpass1"  -> admin password confirmed
--send "userpass1"   -> normal password set
--send "userpass1"   -> normal password confirmed
--send "5"           -> character type "均衡型" (balanced) selected
--send "m"           -> gender "男性" (male) selected
```
Result: **character successfully created and entered the actual game
world**, landing in the starting room **「世外桃源」** (same start-room
name as yanhuangwuhun, another lineage-consistency data point), full room
description with exits (`west/east/north/south`) and two NPCs (水笙/狄云)
rendered correctly in UTF-8, followed by the live-ticking time-based
command prompt. Save files confirmed written to disk (`data/user/q/
qinfeng.o`, `data/login/q/qinfeng.o`).

**Second, separate connection** (existing-user login + command handling,
`--idle 0.3` to beat the once-per-second ticking prompt that otherwise
prevents the idle-gated client from ever sending queued input):
```
--send "qinfeng"     -> recognized as existing id, save file found
--send "userpass1"   -> password accepted, "重新连线完毕。" (reconnected
                        successfully)
--send "look"        -> full 「世外桃源」 room description printed again,
                        correctly rendered
--send "quit"        -> "欢迎下次再来！" (graceful disconnect message)
```
Confirms save/restore, password auth, and ordinary command dispatch
(`look`/`quit`) all work correctly end-to-end, not just the one-shot
creation path.

**Before the `is_killing()` fix** (2 separate attempts, both with a valid
id): registration proceeded correctly through the Chinese name, both
passwords, character type, and gender prompt — then **silently stalled
with no further output at all** (no room, no error visible to the
client). `debug.log` showed the real cause: `/clone/user/user.lpc:568:26:
error: Bad type for argument 1 of is_killing ( string vs object )`
followed by `*No program in object '/clone/user/user'!` — the player body
class failed to compile, so `make_body()` returned 0 and the connection
just hung. This is exactly the failure mode AGENTS.md §15b warns about:
never consider a registration flow verified just because it reaches
password/type/gender prompts — it must actually complete into the game
world.

## lpcc sweep

`scripts/lpcc_check.sh libs/yanhuangyingxiongshi/config.fluffos
libs/yanhuangyingxiongshi/work` — file count 11,001 (well under the
mega-lib bracket), run in full, three times (once to find the initial
failure set, twice more after each round of fixes to confirm progress).
Host memory monitored throughout every run (stayed under ~2.2GB RSS for
this lib's own `lpcc --batch` process; other agents' concurrent sweeps on
other libs pushed system-wide available memory down to ~1.3GB at one
point, but this lib's own process was never the concern and finished
without incident).

**Final result: 10,980 / 11,001 pass (99.81%)**, up from 10,965/11,001
(99.67%) on the very first sweep — the gap was closed by 6 genuine fixes
found via the sweep (in addition to the `is_killing()` bug already found
via interactive testing, listed above):

1. **`inherit/condition/damo.lpc`** — a genuine pre-existing typo
   (§10-style missing closing quote: `return name + HIM "发作身亡了;`,
   missing the `"` before the semicolon) desynced the parser for the rest
   of the file, producing a cascade of nonsensical "Illegal character
   0xe9/0x95/0xbf" errors on a much later, perfectly-valid line of UTF-8
   Chinese text (confirmed the file's UTF-8 is completely well-formed
   throughout via `iconv -f UTF-8 -t UTF-8` round-trip — the "illegal
   character" reports were 100% a downstream parser-desync artifact of
   the one real typo, not a second bug). One `inherit`ed file, fixed
   once — resolved this file plus all 4 files that `inherit` it
   (`kungfu/condition/damo_luanqi`, `damo_shangshen`, `damo_zheyuan`,
   `kungfu/class/misc/laonu`'s sibling `kungfu/class/sky/sky5` was
   unrelated) in one shot (§8g pattern).
2. **`inherit/misc/quest.lpc`'s `set_information()` signature** — declared
   `string info` but virtually every quest file's `create()` calls it with
   a closure (`set_information(NPC1_NAME, (: ask_npc1 :))`); `QUEST_D`'s
   own real implementation already declares this parameter `mixed`. Fixed
   the wrapper to match, resolving all **7** affected quest template files
   (`capture`, `deliver`, `explore`, `judge`, `search`, `shen`, `supply`)
   in one shot — the exact same shared-root shape documented for
   `nitan_san` (a different, unrelated lineage) in AGENTS.md, recurring
   independently here.
3. **`adm/daemons/questd11.lpc`** — a distinct, NEW corruption pattern not
   yet in AGENTS.md's catalog: several places in this ONE file have a
   literal newline inserted in the middle of an identifier or string
   literal (e.g. `me, w` on one line, `ho);` starting the next — splitting
   the identifier `who` in two; `ob->na` / `me()` splitting `name()`;
   `db` / `ase[...]` splitting `dbase`; `bas` / `e_name` splitting
   `base_name`; `query_enti` / `re_dbase()` splitting `query_entire_dbase`;
   `$(kno` / `wer))` splitting a closure macro parameter name `knower`),
   plus several purely-cosmetic string-literal splits (`"experien` /
   `ce"`, `q["i` / `d"]`, `"reply_` / `by"`, `"family/fami` / `ly_name"`,
   `"potential` / `"`) that don't break compilation (LPC allows an
   embedded literal newline inside a string) but silently corrupt the
   stored value (e.g. a property key becomes `"experien\nce"` instead of
   `"experience"`). Confirmed identical corruption already present in the
   RAW pre-conversion archive (diffed against `raw/.../questd11.c`) — not
   something our pipeline introduced. Looks like the original file was
   edited at some point with a tool that hard-wrapped long lines at a
   fixed column width, occasionally landing mid-token. Found all 9
   instances with a small Python scan (line N ends with an
   identifier-continuing character, line N+1 starts with one) and fixed
   each by hand (rejoining the split token/string) rather than a blind
   regex, per AGENTS.md's standing caution about bulk fixes on this class
   of corruption.
4. **`adm/daemons/eventd.lpc` / `adm/daemons/storyd.lpc`'s `[0..<3]` →
   `[0..<5]` rename-width bug** (§2's documented pattern, recurring
   independently — same shape as yanhuangwuhun's own finding, ported
   directly once recognized): both build an event/story name list via
   `get_dir(DIR + "*.lpc")` then strip the extension with a hardcoded
   `map_array(names, (: $1[0..<3] :))`, correct for the original 2-char
   `.c` extension but leaving a trailing `.l` after the `.c`→`.lpc`
   rename (e.g. `emei.lpc` → `emei.l` instead of `emei`). This broke
   EVERY event/story lookup with `call_other() couldn't find object
   '.../emei.l'` — surfaced in the sweep as 8 unrelated-looking failures
   (`u/rcwiz/mailbox/mailbox`, `u/rcwiz/xmas/man`, `d/city/zuixianlou2`,
   `d/city/npc/guidao`, `adm/daemons/network/services/ping_q`,
   `adm/daemons/network/messaged`, `adm/daemons/story/pangtong`,
   `adm/daemons/story/mengzi`) all sharing the identical error string,
   resolved in one shot by fixing the 2 daemon files (§8g pattern again).
   **Proactively applied the identical fix to `adm/npc/luban.lpc`'s two
   own `[0..<3]` occurrences** (a room-building NPC feature, confirmed via
   reading that both operate on `.lpc`-suffixed filenames) even though
   neither was caught by the sweep or reachable in our registration test —
   this NPC's "build a room" feature is never exercised by either, so
   this fix is unverified by any live test, flagged here honestly rather
   than claimed as confirmed.
5. **`d/city/npc/guidao.lpc`'s `is_killing(who)` type mismatch** — the
   exact same bug shape as `clone/user/user.lpc` above (direct call
   passing an object where `is_killing(string id)` expects a string),
   independently present in a second file. Fixed identically
   (`is_killing(who->query("id"))`); this also resolved the cascading
   `d/city/zuixianlou2` failure (the room that creates this NPC).

**Remaining 21 failures, all confirmed non-critical / expected noise**
(none appear anywhere in `log/debug.log` across 3 separate boot+play
sessions):
- **9 files under `/b/yitian/`** (`was_lou2/4/dayuan`,
  `npc/{zheng7,wang8,zhou5,wu6,sun3,li4}`) — genuine missing zone content
  (§13): all reference `/d/tulong/yitian/npc/obj/...` paths, and
  `d/tulong/yitian/` **does not exist anywhere in this archive** (only
  bare `d/tulong/` does) — the archive shipped without this sub-zone's
  content, not a bug to fabricate a fix for.
- **`kungfu/class/misc/laonu`** — same category: `carry_object("/d/baituo
  /obj/shezhang")` references a file that doesn't exist anywhere in
  `d/baituo/obj/` (confirmed via `find`/`ls`).
- **`kungfu/class/sky/sky5`** (cascades from `kungfu/class/sky/npc/
  beichou.lpc`) — `set_skill("six-finger", ...)` references a skill that
  was never defined anywhere in this lib's `kungfu/` tree — another
  missing-content gap, not fixed.
- **`clone/board/gumu_b`** — pre-existing corrupted save data
  (`data/board/gumu_b.o` has a truncated `"title":"旅,]),` entry with no
  closing quote on a real player-submitted board post from 2002,
  confirmed present in the raw archive itself) throwing `restore_object():
  Illegal mapping format` — same general shape as §15m (corrupted seed
  data crashing an unguarded `restore()`), but this is genuine historical
  player-submitted board content on a board that's never touched by
  preload/registration, so left as-is rather than editing/deleting real
  seed data.
- **`clone/board/wfoxd_b`** — references `/d/city/wfoxd`, which doesn't
  exist anywhere in the archive — another §13 missing-room gap.
- **`u/rcwiz/mailbox/mailbox`, `u/rcwiz/xmas/man`** — classic §6b
  isolated-compile artifact: both `create()`s start with `object me =
  this_player();` then immediately `seteuid(geteuid(me))` — `this_player()`
  is legitimately `0` in a bare `lpcc` context with no real connection,
  so `geteuid(0)` throws. Would work fine wherever these are actually
  `new()`'d from a real player context in-game (personal wizard-dir
  feature objects, never preloaded, never touched by registration).
- **`adm/daemons/network/services/ping_q`, `adm/daemons/network/
  messaged`** — both transitively load `adm/daemons/network/dns_master.lpc`
  (`ping_q` directly; `messaged` via its own `startup_udp()`), which hits
  the **exact same `get_config()`/`runtime_config.h` numeric-ID mismatch**
  already documented above for `versiond.lpc` (`Bad argument 2 to
  socket_bind() Expected: int Got: "4"`/`"10"`) — same non-fatal root
  cause, not a new bug. `dns_master` itself is correctly excluded from
  preload (§15p) and neither of these two files is ever preloaded or
  touched by registration either.
- **`adm/daemons/story/{pangtong,mengzi}`** — fail to load with no
  diagnostic text at all in an isolated `lpcc` run (unlike every other
  failure here, no error/warning printed between the last compile trace
  line and "Fail to load object"). Not investigated further — these
  story-content files are never preloaded, never appear in `debug.log`
  across 3 real boot+play sessions, and chasing a silent isolated-compile
  failure with no error text for two files this deep in a rarely-touched
  daemon subsystem was judged not worth the time budget per AGENTS.md's
  explicit "prioritize breadth over depth" / "long tail, not all
  reachable at once" guidance (§15f's closing note makes the same call
  for a different bug class). Flagged here for whoever revisits this lib.
- **`adm/simul_efun/util`** — confirmed §6b's documented `#include`-only-
  fragment false positive: `util.lpc` is `#include`d into
  `simul_efun.lpc` and uses the `NOR` ansi-color macro (defined via
  `simul_efun.lpc`'s own `#include <ansi.h>`, not its own) — fails
  standalone, compiles and runs fine as part of the real composed file
  (verified: `/adm/single/simul_efun` itself passes a direct `lpcc` check
  with zero errors, and zero mentions of `util.lpc` appear anywhere in
  `log/debug.log`).
