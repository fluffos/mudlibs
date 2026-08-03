# zhonghua2 — 中华英雄苏州站 (Chinese Hero — Suzhou Station)

Archive: `中华2.rar`. Port: 40028. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese surname
and given name).

## What this is

"中华英雄II武侠世界" ("Chinese Hero II Wuxia World"), this snapshot
branded "苏州站" ("Suzhou Station"), a specific server instance of the
中华英雄 mudlib, up since 2006-03-01 per its own banner. `adm/single/`
layout (same convention as `shiji`, archive #32). ~17,806 raw files,
11,739 after `.c`→`.lpc` rename — the largest lib processed since the
nitan family, though still well within normal `lpcc_check.sh` sweep
range (no memory pressure observed).

## Fixes applied

1. **No §4 fix needed**: `adm/single/master.lpc`'s `valid_write`/
   `valid_read` only ever call `find_object(SECURITY_D)` (never
   `load_object`), degrading gracefully with no re-entrancy risk. No
   §15l destruct-simul_efun trick in `create()` either (just a bare
   `write()`).
2. **AGENTS.md §15h, with a genuinely different `is_chinese`
   implementation** than every prior lib: instead of checking only the
   first character, this one scans the WHOLE string byte-by-byte with
   `i%2` gating for GBK lead/trail-byte ranges (161-254 for any byte,
   176-247 for even/lead positions) — because it's used to validate an
   entire surname/given-name field, not just detect "is this Chinese at
   all". Rewritten to check every CHARACTER is in the CJK range
   (U+4E00-U+9FFF) instead of every byte.
3. **`check_legal_name(string name, int maxlen)`**: `maxlen` is a
   byte-count passed from the call sites (`get_surname()`/`get_name()`,
   both passing literal `4` = 2 GBK characters) — halved both call-site
   literals to `2`, and halved the internal bound `strlen(name) < 2` to
   `< 1`.
4. **A separate combined-length guard**: after collecting BOTH surname
   and given name, `get_name()` checks `strlen(fname) < 4` (`fname` =
   surname + given name concatenated) before accepting the full name —
   halved to `< 2`. Found via the ACTUAL interactive test: "萧" (surname)
   + "峰" (given name) = 2 real characters was being rejected as "至少
   要有两个汉字" (must be at least 2 Chinese characters) despite already
   being exactly 2.
5. **`adm/daemons/named.lpc`** — same deep-fix shape as the nitan family
   (nitan170911/nitan6/chidi/dtsl/dtslmud):
   - `PATH(name)` macro: `name[0..1]` (first GBK char) → `name[0..0]`
     (first character), plus a direct `name[0..1]` reference outside the
     macro in `remove_name()`.
   - Every `strlen(name) < 2` guard → `< 1` (5 occurrences across
     `remove_name`/`map_name`/`who_is`/`invalid_new_name`).
   - `invalid_new_name()`'s combined check `strlen(name) < 4` → `< 2`.
   - Sliding-window similar-name detection: `name[i..i+3]`/`name[i..i+5]`
     (2-char/3-char GBK byte windows) → `name[i..i+1]`/`name[i..i+2]`
     (2-char/3-char UTF8 windows), loop bound `i <= l - 4` → `i <= l -
     2`, inner guard `i + 6 <= l` → `i + 3 <= l`.

## New bug: stale corrupted save-file data blocking ALL non-wizard logins

`adm/daemons/versiond.lpc` (a version-sync/replication daemon for
multi-server "release server" setups) calls `restore()` in its own
`create()`. The archive's `data/versiond.o` save file — a huge nested
mapping cataloging every file+mtime in the original 2006-era snapshot —
threw `*restore_object(): Illegal mapping format while restoring dbase`,
which is NOT caught anywhere in the call chain, aborting `create()`
before it ever reaches the code that sets `version_ok = 1`. Confirmed
via byte-for-byte comparison against the raw pre-conversion archive file
(identical byte count and content) that this is **pre-existing data
corruption in the original archive, not something our UTF-8 conversion
introduced**. Since `adm/etc/config`'s `release server` is set to
`local` (this station doesn't actually need to sync from anywhere),
`version_ok` should trivially be `1` — but the crash during `restore()`
prevented that code from ever running, leaving every non-wizard
connection stuck behind "现在本站正在同步版本，如果你不是巫师，请稍候
再登录" (misleadingly implying an ACTIVE, ongoing sync, when actually
nothing was syncing — the daemon's init had just silently crashed).
Fixed by renaming the file out of the way
(`data/versiond.o.stale-corrupt-disabled`) so `restore()` finds nothing
and returns cleanly instead of throwing, letting `create()` reach the
`RELEASE_SERVER() == "local"` branch and set `version_ok = 1` normally.

**Worth watching for on other libs**: any daemon whose `create()` calls
`restore()`/`restore_object()` unguarded (no `catch()`) can turn a
corrupted/stale save file into a hard init failure for that ENTIRE
daemon — and if that daemon gates the login/registration flow (directly
or via a state flag another daemon checks), the symptom looks like a
deliberate maintenance-mode message, not a crash. If a fresh boot's
first-connection banner shows any kind of unexpected "syncing" / "please
wait" / maintenance-sounding message that doesn't match anything in
`config`, check `debug.log` for a `restore_object()` error near that
daemon's name before assuming it's an intentional gate to test around.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:

1. `zhonghuab` → passes `check_legal_id` (letters only), reaches
   confirmation.
2. `y` → reaches the surname prompt (this lib collects surname and given
   name as two SEPARATE fields, like `nitan170911`).
3. **`萧`** (real Chinese surname, 1 character) → accepted.
4. **`峰`** (real Chinese given name, 1 character) → accepted, combined
   name "萧峰" passes both the fixed `check_legal_name` and the fixed
   combined-length guard — proceeds straight to admin-password setup.
   This is the actual proof the §15h + named.lpc fixes work together,
   not just that prompts render.

## lpcc sweep

11,739 files, 11,426 pass / 313 fail (97.3%). Failure tail is the usual
shape (a `set_skill`/`set_information` type-mismatch pattern accounting
for ~83 of the 313, missing daemons/functions, a handful of syntax
typos) — not triaged individually per AGENTS.md §6b/§13, boot + full
interactive registration test is the verification gate. Memory stayed
healthy throughout (~16-17GB free consistently, no pressure, despite
this being the largest lib since the nitan family by file count).

## Prior regression-fix pass (repo-wide QA sweep, commit 96d2ee3436)

A later repo-wide sweep found and fixed 5 real regressions in this lib
that this NOTES.md hadn't yet documented (re-confirmed all 5 are still
present/intact in the current source before this re-verification pass
touched anything):
1. **is_killing() type mismatches** (`clone/user/user.lpc`,
   `u/smallfish/npc/user.lpc`, `d/city/npc/guidao.lpc`): `is_killing(ob)`
   (object) → `is_killing(ob->query("id"))` (string), matching
   `feature/attack.lpc`'s real `varargs int is_killing(string id)`
   signature.
2. **§15s** (`adm/simul_efun/message.lpc`): `message()`'s bare-`int 0`
   4th-arg guard — `(objectp(exclude) || pointerp(exclude)) ? exclude :
   ({})`.
3. **§15w** (`adm/single/master.lpc`'s `log_error()`): player-facing
   write gated on `strsrch(message, "warning:") == -1`.
4. **Rename-width leftover** (`adm/daemons/eventd.lpc`): `.c`→`.lpc`
   extension-strip slice `$1[0..<3]` → `$1[0..<5]`.
5. **Unguarded factory-call** (`d/hangzhou/npc/shusheng.lpc`):
   `carry_object(...)->wear()` chained straight onto a factory call with
   no null-check → assigned to a local `cloth` var, guarded by
   `if (objectp(cloth))`.

All 5 verified intact through this pass's reformat + rebuilt-driver
retest (see below) — none were touched or reverted.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (11,739 total,
  11,562 written, 51 unchanged, 126 self-checked errors left untouched
  as expected on legacy code). Spot-checked the 5 regression-fix files
  above post-format — all 5 fixes survived unchanged in substance.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot. The only
  runtime message in `log/log` (this lib's debug-log file, named `log`
  not `debug.log` — see `config.fluffos`) is the pre-existing, already-
  documented §15ad `versiond.lpc`/`socket_bind()` config-ID-mismatch
  non-fatal error; `data/versiond.o.stale-corrupt-disabled` (the earlier
  stale-save-file fix) is still in place, no `Illegal mapping format`
  restore errors. Full registration flow re-verified end-to-end: new id
  `zhtestz`, real surname/given-name **萧**/**峰**, admin password +
  regular password (this lib has TWO separate passwords, not one —
  re-confirmed the full prompt chain), character-type selection (5 =
  均衡型/balanced), gender (m), landed in 世外桃源; a SECOND connection
  then logged back in as the same `zhtestz`/萧峰 with the regular
  password and ran `look`/`score`/`quit` all correctly (score showed the
  real character sheet, quit saved and disconnected cleanly) — confirms
  persistence across reconnects still works post-reformat.
  **Testing-methodology note**: this lib has the same per-second live
  clock prompt (`14:32:07>`) documented on `zhongjidiyu` (AGENTS.md
  §15an) — a normal `--idle 1.2` pace caused sends after login to be
  swallowed/misdirected; dropping to `--idle 0.4-0.5` fixed it.
- **NEW WASM-specific finding (distinct from the documented
  `query_ip_number()` limitation)**: this lib's `logon()`
  (`adm/daemons/logind.lpc`) calls `VERSION_D->is_version_ok()`
  (`VERSION_D` = `/adm/daemons/versiond`) with **no `catch()`** (unlike
  the adjacent `catch(MUDLIST_CMD->main())` one line above it).
  `versiond.lpc` genuinely uses raw `socket_create()`/`socket_bind()`/
  `socket_listen()` for its cross-server version-sync feature — under
  WASM (no `sockets` package) these are hard "Undefined function"
  compile errors, so `/adm/daemons/versiond` preloads as a program-less
  object. The subsequent unguarded `VERSION_D->is_version_ok()` call
  then throws `*No program in object '/adm/daemons/versiond'!`,
  uncaught, and the driver's own `new_conn_handler()` treats that as a
  failed `logon()` and **disconnects the user immediately after the
  banner, before the id prompt ever appears** — confirmed via the
  WASM harness's raw log (`new_conn_handler: logon() on object
  clone/user/login#0 has failed, the user is disconnected.` appearing
  right after the `versiond` error). This blocks **every** login attempt
  under WASM for this lib, not just IP-gated ones. Root cause is
  entirely the WASM sandbox's missing `sockets` package colliding with a
  genuinely socket-based feature this lib relies on — confirmed NOT a
  mudlib bug (native boots and completes full registration/login/persist
  cleanly, verified extensively above) — so, per the standing instruction
  for WASM-mode limitations, **not patched**. Documented here instead of
  papered over; a future pass wanting WASM playability for this specific
  lib would need to either wrap that one call in `catch()` (a real,
  minimal, low-risk mudlib fix) or accept it as out of scope for a
  sockets-dependent daemon. (Done in the 2026-07 WASM-enablement pass
  below, via `find_object()` guards.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3c/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local); `is_banned()` returns 0 for local
  sites before any parsing.
- `adm/daemons/logind.lpc`:
  - `logon()` (~line 75) and `get_id()` (~line 158): both
    `VERSION_D->is_version_ok()` gates now guarded with
    `find_object(VERSION_D)` — absent versiond (WASM, no sockets
    package ⇒ program-less object ⇒ uncaught "No program" throw that
    killed every WASM login) now means "version ok". This was the
    documented WASM login blocker for this lib.
  - `logon()`: `iplimit > 15` per-IP multi-login cap — loopback exempt.
- `adm/daemons/closed.lpc` `heart_beat()`: same `find_object(VERSION_D)`
  guard (preloaded daemon, would throw every heartbeat under WASM).
- No `uptime()` startup-grace gate or registration throttle exists in
  this lib's login chain — nothing else to bypass.
- Admin seeded: `fluffos` / 浮云, rank `(admin)` via `adm/etc/wizlist`.
  This lineage requires TWO different passwords: 管理密码 (recovery)
  `Admin@2026`, 普通密码 (daily login) `Mud@2026` — the lib rejects
  identical values, so the admin/recovery password deviates from the
  standard convention (documented in README). Same `feature/dbase.lpc`
  anti-steal quirk as yxcs (here keyed on "(admin)" and
  covering "password"/"ad_password"/"wizpwd" AND blocking
  `set("id", <admin id>)` on login obs): register first as a plain
  player, then add to wizlist and restart. Verified: login shows
  目前权限：(admin), lands in 巫师休息室,
  `update /d/wizard/wizard_room.lpc` → 成功.
- Retest: fresh normal registration (`regtest`/秦风) end-to-end into
  世外桃源 with look/score/quit correct; test saves removed. debug.log
  shows only the pre-existing §15ad `socket_bind()` versiond error plus
  a few pre-existing log-ACL denials (`/u/task/log`, `/log/nosave/quest`
  append permission, debug-log rotation lstat) — none new to this pass,
  none login-affecting.

## WASM long-sit boot-watch pass (2026-07): 4 real bugs root-caused and fixed

A 200s+ `scripts/wasm_boot_watch.sh` sit (AGENTS.md §10.0) surfaced
several lazily-triggered failures that a quick smoke test never
exercises. All four below were previously visible only as unexplained
noise in a prior pass's debug.log ("a few pre-existing log-ACL denials
... none login-affecting", above) — this pass actually root-caused and
fixed them:

1. **`adm/simul_efun/object.lpc`'s `file_owner()` misattributes every
   3-level-deep `/u/<wiz>/<subdir>/<file>` path to `<subdir>` instead of
   `<wiz>`**: `sscanf(file, "/u/%s/%s/%s", dir, name, rest)` correctly
   captures the wizard name in `dir` (first match) and the subdirectory
   in `name` (second match), but the function `return`ed `name`. Any
   compile warning/error for a file under a wizard's own subdirectory
   (e.g. `/u/sanben/task/set_task.lpc`) got logged via
   `master.lpc log_error()` to a bogus `/u/task/log` instead of
   `/u/sanben/log` — silently swallowed since `/u/task/` doesn't exist
   ("Wrong permissions for opening file /u/task/log for append"/"No
   such file or directory"). Fixed: `return dir;`. **Same bug ported to
   7 sibling libs** that share this identical file byte-for-byte:
   `yueyingqiyuan`, `zhongjidiyu`, `zjdyaryl`,
   `zjdyzj`, `zitengzhan`, `zzhj`, `zzfy` (only
   `zhonghua2` happened to trip it live during this pass's sit; the
   others have the identical latent bug, fixed proactively).
2. **`adm/daemons/questd.lpc`'s `collect_all_quest_information()`
   `log_file("nosave/quest", ...)` had no `/log/nosave/` directory to
   write into** (§7.11 class — gitignored runtime dir, absent on a
   fresh checkout). Created `work/log/nosave/` and added
   `zhonghua2  log/nosave` to `scripts/wasm_keep_dirs.txt` so the
   packaged WASM/browser artifact recreates it too.
3. **`adm/daemons/cleard.lpc`'s `auto_clear()` heartbeat** (fires 30s
   after boot, then every 30 min) called `cp("/log/debug.log", ...)`
   unconditionally right after a 1-in-3-chance `rm("/log/debug.log")` of
   its own — an uncaught `cp()` on a missing source ("lstat failed")
   aborted the function BEFORE its own `call_out("auto_clear", 1800)`
   reschedule, permanently killing the debug-log-backup heartbeat after
   its first unlucky (or WASM-harness-log-gap) run. Guarded both `cp()`
   calls with `file_size(...) >= 0`.
4. **`kungfu/class/generate/chinese.lpc`'s `from_wudang()`/
   `from_shaolin()` NPC-skill setup** called
   `set_skill("parry", "taiji-jian")` / `set_skill("parry",
   "damo-jian")` — `set_skill(string skill, int val)` needs an int
   second argument, not a weapon-name string (author typo, part of the
   lib's own previously-documented "~83 files" `set_skill`/
   `set_information` type-mismatch lpcc-sweep tail, never triaged
   individually until this daemon actually got lazily loaded 180s into
   the sit via `/u/sanben/task/set_task.lpc`'s `set_task()` call_out).
   Fixed both to `set_skill("parry", 1)`, matching every other
   `set_skill(..., 1)` baseline call in the same functions.
5. **`feature/command.lpc`'s `command_hook()` is `private nomask`**
   (AGENTS.md §8.3a's documented class — a previous pass's "empirical
   caveat" noted `zhonghua2`'s PLAYER dispatch works fine despite
   `private`, so it was left alone). This sit proved the caveat doesn't
   extend to NPCs: every `u/sanben/task/npc/task_carrier#N` and
   `clone/npc/walker#N` NPC hit "apply() with insufficient permission
   ... function: command_hook, origin: efun, needs: private, has:
   hidden" repeatedly (their autonomous action-scheduling calls
   `command_hook` via the `command()` efun on themselves, an
   ORIGIN_EFUN self-call that needs DECL_PRIVATE, which the
   inherited-and-thus-DECL_HIDDEN `private` function falls short of —
   normal player input dispatch is ORIGIN_DRIVER and tolerates it, which
   is why the earlier pass's player-only test missed this). Dropped
   `private`, kept `nomask`, per the standard §8.3a fix.
6. **Same root cause as #5, different symptom**:
   `inherit/item/combined.lpc`'s `private void destruct_me()`,
   self-invoked via `call_out("destruct_me", 0)` (ORIGIN_INTERNAL, also
   needs DECL_PRIVATE) when a money stack's amount hits 0 — denied the
   same way, so spent-down money stacks never actually self-destruct
   (a harmless but permanent resource leak). Dropped `private`. **Same
   fix ported to `zhongjidiyu`, `zjdyaryl`,
   `zjdyzj`**, which share this identical file; only
   `zjdyzj`'s sit happened to trigger it live.

Retest after all six fixes: native registration (`zhtestqg`/李白) +
look/score/quit clean, no regressions (an NPC — 水笙 — audibly
whispered a chat-heartbeat line mid-session, confirming NPC command
dispatch generally still works). WASM 200s re-sit: `/u/task/log`,
`/log/nosave/quest`, the `chinese.lpc` compile errors, and the
`command_hook`/`destruct_me` "insufficient permission" lines are all
gone; only the already-documented sockets-absent
(`dns_master`/`versiond`) and pre-existing `set_information` type-
mismatch quest-daemon compile errors remain (both out of scope, per
this lib's own already-documented lpcc-sweep tail).

## 深度功能测试 / Deep functional test (2026-07, round two, §10.7)

First genuine hands-on *playthrough* pass on this lib (all prior passes
verified registration + `look`/`score`/`quit`, a WASM long-sit boot-watch,
and admin login only — never a real multi-room, multi-system session).
Read `doc/help/newbie` in full first. Played as an ordinary new player
through the full registration flow, the "select your inherent quality"
four-room mini-quest (`桃源石屋`/`竹屋`/`茅屋`/`瓦房` → `阎罗殿` →
`wash`/`born`), the newbie-gift NPC (`ask zhyx_boss about 天赋`), the
starting Yangzhou zone (武庙/北大街/醉仙楼), a shop `list`, a real `quit`
+ `debug.log` grep, a real PROMPT net-dead disconnect/reconnect, and —
critically — **two** full real **15-minute** (`NET_DEAD_TIMEOUT` = 900s,
`include/user.h:10`) unclean-disconnect waits on the native driver
(`build-debug`): the first one, run before any fix, is what surfaced the
critical Bug 3 below; the second, run after fixing it, is what confirmed
the fix actually holds under the exact same real-world conditions
(driver alive, listening, and error-free throughout and after the full
wait, then a clean reconnect with full state intact). Found and fixed
**five** bugs — one already-known class (cited), one CRITICAL bug
matching and reinforcing an existing catalog class from a sibling
lineage (§7.12, escalated by `dtsl`), and effectively one NEW closely-related
class (the off-by-width post-`.c`→`.lpc`-rename slice bug, §4.2-shaped
but in a runtime file-scan rather than a directory listing) plus its two
smaller companions in the same file.

**§7.14 pre-check (per task brief)**: AGENTS.md §7.14's `file_size()`
boolean-context bug is attributed there to `zhongjidiyu`, not
`zhonghua2` — these are two different libs in the same family (probable
mix-up in the task brief, likely from the similar names). Checked this
lib specifically anyway: grepped every `file_size(` call site under
`work/` for a bare boolean-context use (`if (file_size(...))` with no
comparison operator) — all ~50 hits use a proper `< 0`/`>= 0`/`== -2`
comparison already. Separately, this lib's `master.lpc`'s
`compile_object()` (the actual MudOS "virtual object" hook) delegates to
`/adm/daemons/virtuald.lpc`, which is a pure no-op stub (`return 0;`,
no virtual objects implemented at all) — so the "infinite virtual-object
recompiles" mechanism §7.14 describes has no code path to trigger here.
Confirmed clean; not re-flagged.

**Test character** (kept, not cleaned up, as representative playthrough
evidence): id `shenfengid`, Chinese name 沈风 (male), 均衡型/balanced,
passwords `ShenAdmin@2026` (管理密码) / `ShenNorm@2026` (普通密码). State:
personality 阴险奸诈 (chosen via 桃源石屋's 花铁干), reborn 扬州人氏,
received the newbie gift from 浪翻云 (level-up, +24 skill pts, +1200
potential, +120 combat_exp/灵慧), currently in 武庙 (Yangzhou), no gold on
hand (newbie gift is stats/exp only, not currency — confirmed via a real
`buy baozi` attempt at 醉仙楼: 店小二 correctly refused a penniless
customer, "穷光蛋，一边呆着去！" — this is the shop's intended behavior,
not a bug). Survived: a clean `quit` → real wall-clock wait → reconnect
(state fully intact), a prompt net-dead disconnect → reconnect (location
preserved, no void-parking), and was the character used for both full
15-minute net-dead waits (before and after the Bug 3 fix). Saves:
`work/data/user/s/shenfengid.o`, `work/data/login/s/shenfengid.o`.
Several throwaway registrations made while isolating the whisper-
duplication bug (`linfeng`/林风, `zhaoyid`/赵毅, `wangxid`, `sunlid`,
`wugexid`, `chenlid`/陈丽, `fangmid`/方敏, `shenxinid`/沈心) were deleted
after use — only `shenfengid`'s save data was kept.

### Bug 1: `cmds/usr/league.lpc`'s `main()` has no `"check"` case, so a
silent internal call on EVERY login/reconnect fell through to the
player-visible "无效的参数。" default

`adm/daemons/logind.lpc`'s `enter_world()` (line 937) and `reconnect()`
(line 1006) both unconditionally call
`"/cmds/usr/league"->main(this_player(), "check")` — the comment above
each call site says `// 检查同盟情况` ("silently check league status"),
clearly intended to have no visible output. But `league.lpc`'s `main()`
switch only ever handled `info`/`member`/`dismiss`/`top`/`hatred`/`out`
— `"check"` was never a real case, confirmed byte-identical in
`raw/中华2/cmds/usr/league.c` (a pre-existing archive bug, not a
conversion artifact). Every single login and every single reconnect
therefore printed a nonsensical `无效的参数。` to the player, straight
after the welcome banner — reproduced live on the very first login of
this pass.

**Fix** (`cmds/usr/league.lpc`, `main()`): added a `case "check":
return 1;` that does nothing, matching the call sites' own documented
intent (a silent check) without changing behavior for any real player
subcommand (`"check"` was never a documented/reachable player command).

### Bug 2: `cmds/std/whisper.lpc` printed every whisper to a real player TWICE (copy-pasted `tell_object()`)

`main()` used to be two separate `if (!userp(ob)) ... else
tell_object(ob, ... "在你的耳边悄声说道：" ...)` blocks in a row — the
first delivers the whisper to a player target correctly; the **second
block's `else` branch was a byte-for-byte copy** of the exact same
`tell_object()` call (confirmed identical in `raw/中华2/cmds/std/
whisper.c` — pre-existing, not introduced by conversion). Since a
player target is `userp(ob) == 1` in both blocks, both `else` branches
fired, printing the identical line twice for every whisper any NPC or
player ever sends to a real player. Reproduced immediately and
reliably: `/d/register/npc/shuisheng`'s `greeting()` whispers two lines
to every new registrant, and both were doubled on-screen, every single
time, in every fresh registration this pass ran before the fix.

**Fix**: removed the duplicate `else tell_object(...)` from the second
`if (!userp(ob)) {...}` block — its only real job is the NPC-target
quest-bonus branch (`ultra_whisper`), which needs nothing further for a
player target now that the first block already sent the message once.
Re-verified live post-fix: 地藏王's (阎罗殿) and 水笙's whispers each
print exactly once now, both in registration and in a subsequent
`born`-flow session.

**A red herring worth recording**: `inherit/room/room.lpc`'s `reset()`
has the exact structural shape of the already-cataloged **§7.17**
reentrancy bug (`setup()` calls `this_object()->reset()` synchronously
as the last line of `create()`, and `reset()`'s own NPC-population
tracking mapping — `query_temp("objects")` — is only written on its
LAST line via `set_temp("objects", ob)`, the same "population-done flag
set too late" shape §7.17 describes). Given the duplicate-whisper
symptom looked exactly like §7.17's "a room's first-ever visit clones
every NPC twice, each with its own call_out-scheduled side effects" —
this was the first suspect. **Directly disproved by instrumentation**:
added a temporary `write()` at the top of `shuisheng.lpc`'s `init()`
and confirmed via three separate fresh registrations that `init()` fires
**exactly once** per player-entry even while the duplicate whisper
still reproduced — ruling out a duplicate NPC clone. The real cause was
Bug 2 above. **Applied the §7.17 reentrancy guard to `room.lpc` anyway,
proactively** (a `nosave int resetting_now;` flag, checked/set at
`reset()`'s top, cleared on every return path) — it's a zero-side-effect
defensive fix matching an already-proven catalog pattern, and this room
class genuinely has the vulnerable shape, but **be aware this specific
fix's live necessity was not proven on this lib** — the duplicate-
message bug it might have prevented never actually needed it; Bug 2 was
the real, confirmed, live cause.

### Bug 3 (CRITICAL, same underlying class as AGENTS.md §7.12, escalated by `dtsl`'s §10.7 pass): the net-dead force-quit path's `tell_room()` call silently bound to the wrong function, defeating an already-fixed argument-type guard

**Files: `adm/simul_efun/message.lpc` (root cause + fix) and
`adm/daemons/logind.lpc`'s sibling bug (Bug 4, unguarded lazy load —
different mechanism, same login-path blast radius, documented
separately below since it's not a §7.12 instance).**

- **How found**: `clone/user/user.lpc`'s `user_dump()` — the
  `NET_DEAD_TIMEOUT`-driven (900s) `call_out` handler that force-quits a
  player who net-deads and never reconnects — calls `tell_room(environment(),
  ...)` with only 2 arguments (line 212-213). This is EXACTLY the shape
  AGENTS.md §7.12 (with its `dtsl` severity escalation) already
  documents: a `varargs void tell_room(mixed ob, string str, object
  *exclude)` wrapper whose omitted 3rd argument defaults to int 0, fed
  straight into the real `message()` efun's 4th parameter — which
  rejects a bare int. Found by doing the exact thing AGENTS.md's own
  methodology calls for: a genuine 15-minute net-dead wait (not a prompt
  reconnect, which never reaches this code path) on the FIRST attempt
  (before any fix), watching `debug.log` throughout via periodic
  `ps`/`grep` checks rather than just at the end.
- **Compounding mechanism specific to this lib (worse than a plain
  missing-guard)**: this file's `message()` wrapper (line 388,
  `adm/simul_efun/message.lpc`) **already has the correct fix** —
  `efun::message(arg, message, target, (objectp(exclude) ||
  pointerp(exclude)) ? exclude : ({}))` — matching this project's own
  previously-documented §15s regression fix for this exact file. But
  `tell_room()` (line 286) and several other functions in the same file
  (`message_vision()` at line 72, two `message("say", ...)` calls, etc.)
  all call plain `message(...)` **textually before** the wrapper's own
  definition, with no forward declaration anywhere in the file — the
  exact AGENTS.md **§6.5** trap ("a wrapper named after a real efun
  called before its own definition silently binds to the REAL efun").
  So the already-fixed wrapper was **silently bypassed** for every one
  of these earlier call sites, `tell_room()` included, and the real
  driver `message()` efun received the raw, unguarded int 0 every time.
- **Symptom, confirmed live pre-fix**: `debug.log` showed (after the
  first 15-minute wait):
  ```
  执行时段错误：*Bad argument 4 to EFUN message()
  Expected: object, array,  Got: int(0).
  程式：... 呼叫来自：/clone/user/user.lpc 的 user_dump() 第 21X 行 ...
  ```
  — an **uncaught** runtime error (no `错误讯息被拦截` marker, unlike
  the preload-context occurrences of the sibling config-ID bug below),
  meaning it aborted `user_dump()` before reaching `command("quit")`/
  `QUIT_CMD->force_quit(...)`, silently disabling the entire net-dead
  force-quit safety net for this lib — a net-dead player who never
  manually reconnects would stay resident in server memory forever
  (until restart), exactly matching `dtsl`'s already-documented finding.
  Given `dtsl`'s pass additionally observed an actual **native driver
  crash** shortly after two characters hit this in close succession
  (§7.12's escalation), this was treated as maximum priority and fixed
  immediately rather than deferred to the write-up phase.
- **Fix** (`adm/simul_efun/message.lpc`): added a forward declaration
  right after the `#include`, before any call site —
  `varargs void message(mixed arg, string message, mixed target, mixed
  exclude);` — so every `message(...)` call in the file (§6.5's own
  prescribed fix) now resolves to the local guarded wrapper regardless
  of its position in the file. This is a ONE-LINE fix that closes the
  hole for `tell_room()` and every other early caller at once (grep
  found roughly 70 candidate 2-argument `tell_room()` call sites across
  the lib — this fixes all of them via the wrapper, not per-call-site).
- **Live re-verification (the important part)**: restarted the driver,
  re-net-deaded the SAME test character (`shenfengid`) at the same
  location (武庙), and ran a **second full real 15-minute wait**. Result:
  driver (`ps`-confirmed) stayed alive and listening on port 40028
  throughout and after the full window; `debug.log` grepped immediately
  after showed **zero** occurrences of `Bad argument 4`/`tell_room`/
  `user_dump`/`force_quit` anywhere; a fresh reconnect as `shenfengid`
  afterward worked cleanly with full character state intact. (One
  caveat, documented honestly: under the heavy ambient background
  compilation load this lib generates — see the RSS note below — the
  driver's `call_out` queue may lag real wall-clock time, so it wasn't
  possible to pin the EXACT moment `user_dump()` fired relative to the
  reconnect attempt; what IS confirmed is that the driver ran well past
  the nominal 900s window under real load with zero crash-shaped errors
  at any point, which is the property that matters.)
- **Lineages likely affected**: any lib sharing this `adm/simul_efun/
  message.lpc` file shape (a same-named `message()` wrapper defined
  after `tell_room()`/`message_vision()`/other early callers in the same
  file) — worth a proactive grep across the wider ES II/中华英雄/终极地狱
  family for the same binding-order gap, independent of whether the
  wrapper itself already has the §15s-style exclude-argument guard.

### Bug 4: `adm/daemons/logind.lpc`'s `check_ok()` had one unguarded lazy-load call site left, and it broke the very first relogin/reconnect after every fresh boot

`MESSAGE_D` (`/adm/daemons/network/messaged.lpc`) is never actually
preloaded — `adm/etc/preload` lists `/adm/daemons/messaged`, a path that
doesn't exist (the real file lives at `/adm/daemons/network/messaged.lpc`)
— so `check_ok()`'s `user = MESSAGE_D->find_chatter(ob->query("id"))`
(line 308, reached on every EXISTING-id password login, i.e. every
ordinary relogin/reconnect) is normally the first-ever lazy load of that
daemon each boot. `messaged.lpc`'s `create()` calls `startup_udp()`,
which does `my_port = LOCAL_PORT() + MESSAGE_PORT;` where `LOCAL_PORT()`
is `(int) get_config(__MUD_PORT__)` — on this driver build,
`get_config(__MUD_PORT__)` (confirmed live via a temporary
`write_file()` probe) returns an **empty string**, not the real port
int, and this driver's `(int)` cast is a compile-time-only type
annotation under weak typing — it does NOT coerce a string result at
runtime. So `LOCAL_PORT()` genuinely evaluates to `""`, and `"" +
MESSAGE_PORT` (string + int) is LPC string concatenation, producing the
literal string `"10"`. `socket_bind(socket_id, "10")` then throws
`*Bad argument 2 to socket_bind() Expected: int Got: "10"` — this is
the same `get_config(__MUD_PORT__)`-vs-actual-driver-numbering config-ID
mismatch already documented for `versiond.lpc`/`dns_master.lpc`
elsewhere in this lib's own NOTES.md, just hitting a THIRD daemon.
Unlike those two (already safely isolated — `dns_master`'s load is
wrapped in `master.lpc`'s own preload `CATCH()`, `versiond`'s fires from
inside a `call_out` with no LPC caller to propagate to), this occurrence
was **uncaught** and sat directly in the synchronous password-check path
`check_ok()` → `get_passwd()`, aborting the whole login attempt: every
player whose relogin happened to be the first one this boot got
"重新连线完毕。" printed (from an earlier partial success) followed by
**every subsequent command silently swallowed** (`看什么？` for `look`,
etc.) — the account was never actually logged in, `make_body()`/
`restore()`/`move()` never ran.

**Fix** (`adm/daemons/logind.lpc`, `check_ok()`): wrapped the call in
`catch()`, degrading to "not currently chatting" on failure (the same
graceful-degradation contract already used for `VERSION_D` elsewhere in
this same file) — `if (catch(user = MESSAGE_D->find_chatter(ob->query("id"))))
user = 0;`. Re-verified live: a fresh boot's first relogin now completes
normally (confirmed `debug.log` shows `错误讯息被拦截：` immediately
before this exact error, i.e. now cleanly caught, and the login/`look`/
`score`/`quit` flow that follows works correctly).

### Bug 5 (NEW class, §4.2-shaped): a post-`.c`→`.lpc`-rename slice left 2 characters short, permanently breaking a self-rescheduling daemon's random-room-picker and eventually eval-cost-aborting it

**File: `adm/daemons/rebornd.lpc`, functions `jingyan_open()` (line 58)
and `wudie_open()` (line 111), plus a smaller companion bug in
`qilin_open()`/`qilin_close()` in the same file.**

`jingyan_open()`/`wudie_open()` each pick a random file out of a city
directory's listing and check whether it's a valid room to attach a
temporary "mystery entrance" exit to:
```lpc
i = sizeof(s_place);
if (s_place[(i - 2)..i] != ".lpc") continue;
```
`s_place[(i - 2)..i]` is only 3 characters (`i-2`, `i-1`, `i` — and index
`i` is one past the end of a 0-indexed string of length `i` besides).
This is a leftover from when the comparison target was the original
2-character `.c` extension (`.c` = 2 chars, needing indices `i-2..i-1`,
so a 3-wide slice already over-captured slightly, but close enough to
possibly match with LPC's out-of-range-clamps-rather-than-errors
semantics) — the conversion pipeline updated the compared STRING to
`".lpc"` (4 chars) but nobody widened the SLICE to match, exactly
AGENTS.md **§4.2 item 4**'s "fixed-width slices instead of extension
ops" class, just in a live runtime file-scan rather than a `get_dir()`
+ `map_array()` directory listing. A 3-character (or fewer, once
clamped) slice can **never** equal a 4-character string, so this
`continue` fired unconditionally for every single randomly-picked file
— the enclosing `do...while` loop could never find a valid room and
looped until the driver's eval-cost limit aborted it. **Reproduced
live** (found during the same testing session as Bug 3, via routine
`debug.log` monitoring during a long-sit wait): both failure shapes
fired from ordinary ambient play with zero player action involved —
`jingyan_open()` additionally crashed with `*Value being indexed is
zero.` when a particular city's `get_dir()` happened to return `0`
instead of an array (a second, independent missing-null-check bug in
the same unbounded loop), and `wudie_open()` hit `*Too long evaluation.
Execution aborted.` (the eval-cost abort). Both are **self-rescheduling
`call_out` chains** (`jingyan_open()` → schedules `jingyan_close()` →
which reschedules `jingyan_open()`, and the same shape for `wudie_*`) —
since the crash/infinite-loop-abort happens BEFORE the function ever
reaches its own `call_out("..._close", ...)` line, **the entire
reschedule chain permanently dies after the very first attempt each
boot**, silently killing this lib's "惊雁宫"/"舞蝶山庄" mystery-entrance
features for the rest of the session with no player-visible symptom at
all (nothing ever announces on the "wiz" channel, and nobody would
think to look for content that was simply never going to appear).

A third, related bug in the same file: `qilin_open()` (the third mystery
entrance, a fixed target room rather than a random pick) does
`find_object()`/`load_object()` on `/d/city3/shudao8` with **no
`objectp()` guard** before calling `room->set(...)` on the result —
`/d/city3/shudao8.lpc` genuinely doesn't exist in this archive (a real
content gap, confirmed absent from `raw/` too, not fabricated), so
`load_object()` legitimately returns 0, and the unguarded `call_other`
on that 0 threw `*Bad argument 1 to EFUN call_other() ... Got: int(0)`
— reproduced live, same self-rescheduling-chain-permanently-dies
consequence as above. A fourth, purely-cosmetic-until-now bug in the
same file: `qilin_close()`'s `if (room && room->query("exits/qilinku"));`
has a stray trailing semicolon (confirmed pre-existing in the raw
archive), making the guard's body empty and the following
`room->delete(...)` run unconditionally — currently inert in practice
since `qilin_open()` (after its own fix) never calls `qilin_close()`
with a falsy `room`, but fixed anyway as a dead-conditional trap for any
future call site.

**Fix**: widened both slices to the correct 4-character, bounds-safe
form (`s_place[(i - 4)..(i - 1)]`, guarded by `i >= 4`); replaced the
unbounded `do...while` with a bounded `for` loop (200 attempts) so a
future edge case degrades to "try again in 30 minutes" instead of
hanging until an eval-cost abort; guarded `plist` being a real non-empty
array before indexing into it; and made every failure path (`plist`
invalid, no room found after 200 tries) explicitly reschedule the
function via `call_out(..., 1800)` instead of silently falling through
crashed/hung, so the mystery-entrance features always retry rather than
permanently dying after one bad boot-time pick. `qilin_open()` got the
equivalent `objectp()` guard + reschedule-on-failure. `qilin_close()`'s
stray semicolon was removed (proper `if (...) { ... }` block).
**Live re-verification**: post-fix, a fresh boot ran past the 350s mark
(when `jingyan_open()`/`wudie_open()` first fire) and well beyond with
**zero** `rebornd.lpc` entries in `debug.log`'s error listing (previously
present on every boot pre-fix); the final confirmation session (registration
→ look/score/quit) showed `debug.log`'s error sources reduced to exactly
the 3 already-documented benign ones (`dns_master`/`messaged`/`versiond`
config-ID noise, all now safely caught) with `rebornd`/`qilin` absent
entirely.

### Observation (not a bug, documented per AGENTS.md §10.8): substantial ambient-compilation memory growth during the long-sit waits

During both 15-minute net-dead waits, the driver's RSS grew steadily
from its ~60MB fresh-boot baseline up to roughly **1.2-1.3GB** by the
end of the second wait, with `debug.log` showing continuous lazy
compilation of large swaths of the map (many `d/<city>/...` rooms/NPCs,
`kungfu/skill/...` files, etc.) with **no player connected and no
player action** during most of that window — matching §10.8's
already-documented "ambient NPC `heart_beat()`/`random_move()` wandering
forces lazy compilation of much of the map" pattern from a different
lib (`xjcq2000`). The growth rate fluctuated (sometimes near-flat
for 30+ seconds, sometimes 20-30MB in a few seconds) but never became
runaway/exponential, and the driver remained fully responsive
throughout both waits with zero errors and a clean final reconnect —
unlike §10.8's `xjcq2000`/`shiji` cases, **no driver-fatal crash
occurred here**. Flagged as an observation worth watching on any future
long-sit pass on this lib (or its `zhongjidiyu`/`yueyingqiyuan`/etc.
siblings), not escalated to a new bug entry, since it never crossed into
the multi-GB driver-fatal territory those two prior cases hit and this
project's driver-level refcount-corruption class remains unproven at
the mudlib level regardless.

### Not verified live (explicitly, per §10.7 item 6)

- **Safe-sparring (`fight`/较量) and organic teacher (`bai`/`xue`) /
  sect-join (`bai <NPC>` with a `family`) paths**: both mechanisms were
  located and read in full (`cmds/std/fight.lpc`'s `accept_fight()`
  dispatch; `cmds/skill/bai.lpc`'s family/apprentice logic) and confirmed
  to match `doc/help/newbie`'s documented flow exactly (安全的打架方式
  「较量」("fight"); 拜一个好师父 "bai"). Not completed live: the
  starting Yangzhou zone's immediate NPCs (中华英雄/浪翻云 at 武庙) are
  explicitly a no-`family` milestone NPC and a gift-dispenser respectively
  (confirmed via `bai`/`fight` attempts — "既不属於任何门派，也没有开山
  立派，不能拜师" / "这里禁止战斗"), and per the newbie help's own text
  every real sect is "远离尘嚣，处在丛山峻林之中" (far from the
  starting city) — reaching one was out of scope for this pass's time
  budget, which was dominated by the two mandatory 15-minute net-dead
  waits and the resulting bug investigation/fixes.
- **Combat and death/respawn**: not reached, same time-budget reason as
  above — no fight was ever actually engaged in.
- **Shop purchase completion**: `list` verified working live; `buy`
  correctly rejected for lack of funds (intended design, not a bug) — a
  genuine successful purchase was not completed, since the newbie gift
  provides no starting currency and earning any (work/quests) was out of
  this pass's scope.

### lpcc / regression baseline

No `lpcc_check.sh` re-sweep run this pass (out of scope for a
functional-test pass per this lib's own established convention — the
boot + full interactive test is the verification gate, as documented in
this lib's earlier lpcc-sweep section above). All 5 previously-documented
regression-fixes (is_killing() type mismatches, message() bare-int
guard, log_error() warning gate, eventd.lpc rename-width fix, shusheng.lpc
factory-call guard) spot-checked present and untouched by this pass.
