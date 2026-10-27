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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'目前权限：(admin)'。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 75 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08，round two 补做：战斗/拜师 + 新驱动重测）

延续 2026-07 的第一轮 §10.7 深度测试（见上方，已完成注册、四合院"选品质"迷你任务、
新手礼物、商店 `list`、一次真实 quit+reconnect，以及两次完整 15 分钟 net-dead 等待
并修复了 Bug 3）。那一轮明确记录**未**做到战斗、拜师/门派获取、完整任务奖励流程。
本轮针对新编译的 `~/src/fluffos/build-debug`（含最新合并的 PR）重新验证，并补做
上一轮跳过的战斗/拜师测试。

### 驱动升级重测

`cd libs/zhonghua2 && ~/src/fluffos/build-debug/src/driver config.fluffos`（PID
882921，测试结束后已按精确 PID kill 并用 `ss -tlnp` 确认端口 40028 不再监听）：干净
启动，`log/log`（此档案的 debug-log 文件名，参见 `config.fluffos`）里唯一出现的运行
时讯息仍是既有已记录的 §15ad `versiond.lpc`/`socket_bind()` 配置 ID 不匹配错误（非
致命，早已归档），没有任何新的编译或运行时错误。

### `to_int()` 任务计数器修复：通过一次性测试对象 `call`/`update` 验证

会话上文（非本次 subagent 所做）诊断出一次真实的生产崩溃：`u/yuchang/combatd.lpc`
的任务奖励代码 `killer->query("questsn_times") % 500`（以及 `questdg_times`/
`quesths_times`/`questkh_times` 的兄弟写法）在拿到一个损坏成 FLOAT 类型的玩家属性
时崩溃——`*Bad argument 1 to % Expected: int Got: 97467776479476432.000000`——因为
这个驱动方言里的 `%` 运算符对 float 左操作数直接抛错。已用 `to_int()` 包裹修复（**不是**
`(int)`，那只是编译期类型标注，不做运行期转换）。本次已确认这个 lib 里的修复确实存在
且形状正确：`u/yuchang/combatd.lpc` 第 2040/2111/2183 行、`kungfu/class/dugu.lpc`
第 668 行均为 `to_int(...) % 500`。

任务奖励代码本身要走到 `独孤求败`（`d/emei/duguangtai.lpc`）在峨嵋（`d/emei/`，"远离
尘嚣，处在丛山峻林之中"，与上一轮已记录的"真实门派都很远"结论一致）才能触发，在测试
预算内不现实。按任务本身给出的兜底方案，改用**一次性测试对象**直接验证同一个表达式
形状：

在 `work/adm/daemons/qftest.lpc`（临时脚手架，测试完已删除，`git status` 确认未残留）
写入用 `mapping` 间接取值（保持编译期类型为 `mixed`，而不是像 `float bad = ...;` 那样
被编译器静态推断出具体类型——首次尝试直接用 `float` 局部变量时，编译器在**编译期**就
以 `error: Bad left argument to '%' : "float "` 拒绝了，这反而不是生产环境真实触发的
那种"运行期才发现是 float"的路径，所以改用 mapping 取值伪装成 `mixed`，才是对生产
`query()` 返回值场景的忠实复现）：

```lpc
mapping bad_data = (["k": 97467776479476432.000000]);
mixed bad = bad_data["k"];
```

由于此档案的 `call` 巫师指令（`cmds/arch/call.lpc`）要求 `me->is_admin()`，而
`clone/user/user.lpc` 第 63 行的 `is_admin()` **硬编码判断 `getuid() == "yuchang"`**
（原始 2006 年真实站点的超级管理员账号名，与巫师名单等级/`(admin)` rank 无关），本项目
按惯例种下的 `fluffos` 管理员账号（虽然 `(admin)` 权限、`wizlist` 里也是 `(admin)`）
**无法**使用 `call` 指令（`你没有使用该命令的权限。`）。这是一处观察记录，不是本轮要修的
bug——它是一个内部自洽、刻意的访问控制设计（只有原始超级管理员账号能用 `call`/`clone`/
`smash`/`copyskill` 等危险指令），属于 AGENTS.md §10.7 明确排除的"设计选择"范畴，未作
修改；只是记录下来避免未来的 pass 把它当成权限系统坏掉来排查。改用 `update <文件>`
指令触发 `create()` 里直接调用测试函数（`update` 指令本身只需要 `(arch)` grant，
`fluffos` 账号具备）：

- **修复前**（`create()` 直接调用未加 `to_int()` 保护的 `test_unfixed_shape()`）：
  ```
  执行时段错误：*Bad argument 1 to %
  Expected: int Got: 97467776479476432.000000.
  程式：/adm/daemons/qftest.lpc 第 12 行
  ...
  呼叫来自：/adm/daemons/qftest.lpc 的 create() 第 16 行，物件： /adm/daemons/qftest
  呼叫来自：/adm/daemons/qftest.lpc 的 test_unfixed_shape() 第 12 行，物件： /adm/daemons/qftest
  发生错误：
  *Bad argument 1 to %
  Expected: int Got: 97467776479476432.000000.
  ```
  与生产崩溃报告的错误文本逐字一致，确认测试忠实复现了原始崩溃形状。这条错误被
  `cmds/wiz/update.lpc` 自己的 `CATCH()` 拦住（"错误讯息被拦截："），只回显给当前
  连线的巫师，不会写进 `log/log`——这是这个 lib 特有的行为（`update` 指令自身 catch
  编译期加载错误），跟生产代码里那次真正未捕获的崩溃（走的是 `user_dump()`/正常游戏
  逻辑路径，没有类似 `update` 的外层 catch）不是同一条日志路径，属于测试脚手架本身
  的传输方式差异，不影响验证结论。
- **修复后**（改成 `to_int(bad) % 500`）：`update` 显示"重新编译 ... 成功！"，
  `create()` 里 `write_file()` 把返回值写到 `qftest_result.log`：
  `test_fix returned: 432`。独立用 Python 验证
  `int(97467776479476432.0) % 500 == 432`，与驱动内计算结果一致——确认修复后的
  表达式对完全相同的损坏输入返回一个合理的 int（0-499 区间），且不抛任何错误。

结论：`combatd.lpc`/`dugu.lpc` 里 `to_int(x) % 500` 的修复形状，针对确切的报告故障
条件，被直接、诚实地验证有效——虽然不是通过一次真实的完整任务达成，但复现了完全相同
的表达式与完全相同的损坏输入，前后对比证据充分。

### 战斗测试（本轮新补做，上一轮明确记录为未验证）

`cmds/std/fight.lpc` 的安全切磋机制 `fight <目标>`：武庙本身设了 `no_fight`
房间标记（"这里禁止战斗。"，与上一轮记录的中华英雄/浪翻云"这里禁止战斗"一致，是房间
标记而非这两个特定 NPC 的属性），北大街/中央广场沿途的 NPC（欧阳克、小混混、捡破烂的、
李阿婆等）`attitude` 都是 `"friendly"`——`inherit/char/npc.lpc` 的通用
`accept_fight()` 对 `friendly` 属性在玩家气血/精神值 ≥75% 时**必定拒绝**（"某某怎么
可能是您的对手？"），所以新手在城内主干道上找不到会接受切磋的目标。往南走到
`/d/city/nandajie1.lpc`（南大街，中央广场再往南一格）的"流氓"与"流氓头"NPC
（`d/city/npc/liumang.lpc`）`attitude` 是 `"peaceful"`——通用 `accept_fight()`
对非 `friendly`/非 `heroism` 的属性、气血精神值 ≥75% 时会接受。

实测路径：武庙 → east（北大街，实为 beidajie2）→ south（北大街，beidajie1，遇到
欧阳克，未攻击）→ south（中央广场）→ south（南大街/nandajie1）→ `fight liu`。
战斗完整走完整个回合序列（拳脚交替、命中/擦身而过描述），最终"流氓头"服输
（"流氓头脸色微变，说道：佩服，佩服！"），全程无崩溃、无异常。`log/log` 全程无
新增错误。确认此档案的安全切磋机制在新驱动上功能完全正常。

### 拜师/门派测试（本轮新补做）

`cmds/skill/bai.lpc` 对没有 `family` 属性的 NPC 正确报错、不崩溃：`bai liu`
（对刚切磋过的"流氓头"）返回"流氓头既不属於任何门派，也没有开山立派，不能拜师。"，
与上一轮对中华英雄/浪翻云观察到的同类拒绝一致。真正拥有 `family` 的门派 NPC（独孤
求败等）都在远离扬州新手区的深山（峨嵋等），本轮测试预算内未能实际走到并完成拜师，
与上一轮"远离尘嚣"的结论一致——机制本身（家族检查、失败路径）经两个不同 NPC 交叉验证
均无异常，未发现新 bug，只是仍未走完一次真正的成功拜师。

### `tmux_mud.sh` 的 CJK 传输损坏问题再次命中（非 bug，AGENTS.md §10.2 已有前例）

用 `tmux_mud.sh` 发送 `born 扬州人氏` 时，服务端收到的参数没有正确解析（"牛头恶狠狠
的对你说：你要干什么！投胎去哪里？"），后续同一条 telnet 连线连纯 ASCII 的 `look`
都不再有任何响应，怀疑连线状态已经损坏。改用 `scripts/mudclient.py`（原始 socket，
无本地 telnet/pty）在**新连线**上重发完全相同的 `born 扬州人氏`，一次成功——角色正确
落地扬州武庙（`startroom":"/d/city/wumiao"`、`"born":"扬州人氏"`、`"registered":1`
均已写入存档）。这与 AGENTS.md §10.2 已经记录的 `zjdywzb` 传输层问题同一类：本地
telnet CLI/pty 会损坏特定的 CJK 字节序列，不是驱动或 mudlib 的 bug。之后的 `look`/
`score`/`fight`/`bai`/`quit` 等纯 ASCII 指令改回 `tmux_mud.sh` 均正常，无需继续用
mudclient.py。

### quit + reconnect（本轮新测试角色）

新注册角色 `shenqingz`（秦云，男，均衡型，阴险奸诈，扬州人氏——与已保留的
`shenfengid` 证据角色完全独立，测试完已删除其 `data/user/s/`、`data/login/s/`
存档，不影响 `shenfengid`）：完整走完注册 → 桃源石屋选品质 → wash → born → 新手
礼物 → 战斗 → 拜师测试全流程，`quit` 干净退出（"欢迎下次再来！"），`log/log` 全程
grep 无新增错误，约 50 秒后重新连线，完整走一遍正常登录流程（非静默重连），经验
350000/潜能 101299 等全部数值原样保留，位置回到 `startroom`（武庙——此档案的角色
似乎总是回到 `startroom` 而非精确的退出房间，这是既有设计，不是本轮新发现的问题）。

### 本轮结论

未发现新的编程 bug。驱动升级后干净启动、无新增错误；`to_int()` 任务计数器修复通过
一次性测试对象直接验证生效；战斗与拜师这两个上一轮标记"未验证"的系统本轮均已实际
走通（战斗完整验证成功案例，拜师验证了失败路径且逻辑正确，真正的门派 NPC 仍因地理
距离在预算内不可达，与上一轮结论一致，非新增缺口）。对这个 lib 在新驱动构建下的
整体信心：高——核心系统（注册、任务奖励防崩溃、战斗、拜师失败路径、断线重连持久化）
均已验证正常。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 `work/` 下 2,715 处存活的 standalone `replace_program(ROOM);` 行
  （脚本删除），另外手工修复了三处建房工具代码生成模板里的同形状变体
  （`clone/misc/roommaker.lpc`、`u/smallfish/editroom.lpc`、
  `u/smallfish/obj/editroom.lpc` 的 `str += "...replace_program(ROOM);
  ..."` 拼接行），共 2,718 处，与普查记录的存活计数一致。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行；一次实机 socket 连接确认登录/
  注册欢迎屏正常渲染。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/1.lpc`, `d/death/npc/bgargoyle.lpc`, `d/death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc` 在新进程里加载，HEAD 通过 0 个、工作树通过 0 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py zhonghua2 --fix`：无用局部变量 2529 个、`varargs` 67 处、转义 36 处、裸 `return` 2 处、`nosave` 函数 27 个改 `protected`，共改动 1255 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1220 -> 1220 通过，无回退；改过的头文件的 223 个包含者 217 -> 217 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 55 条候选都是声明被重建（同一行剩下的变量还在）或同名 efun（`time()`）。
手工：
- `include/npc/indian.lpc` 与 `include/npc/masia.lpc` 都声明全局 `ma_sname`/`ma_pname`，`adm/daemons/npcd.lpc`、`group_questd.lpc` 两个都包含，后包含的印度名表覆盖了马来名表，`generate_ma_name()` 生成的其实是印度名字。印度表改名 `in_sname`/`in_pname`。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，按原意改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。
- `cmds/std/swear.lpc`、`cmds/std/team/swear.lpc`、`cmds/std/team/bunch.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `adm/daemons/combatd.lpc`、`combatd1.lpc`：招架反击里的 `your_temp["guarding"];` 是什么也不做的语句（别的库作者把它注释掉了），删去，行为不变。
- `adm/daemons/dns_master.lpc`、`network/dns_master.lpc` `query_services()`：`PREF_FINGER`/`PREF_TELL` 不含 TCP 时 `if` 体被 `#if` 掏空；把 `#if` 移到 `if` 外面，行为不变。
- `clone/obj/genmap.lpc`、`traverser.lpc`、`kungfu/skill/linji-zhuang/youming.lpc`：关掉的 `#define DEBUG`（空）让 `DEBUG("…", x);` 成了无用表达式；本驱动的预处理器不支持可变参数宏，改成 `#define DEBUG debug_off` 加一个空的 `private void debug_off(string fmt, mixed args...)`。
- 未动：`adm/daemons/questd11.lpc` 是没人引用的旧副本，本身有语法错误；`clone/obj/genmap.lpc` 里 `#include "harbor.h"` 在函数内声明的局部变量没用到（头文件共用）。

启动时警告 134 -> 0；新进程登录（标题画面、英文名、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 3 处比较、0 处去后缀（如 `u/sanben/giftd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 5 个文件，HEAD 与工作树各载入一次无回退（5 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 5 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/combatd.lpc u/yuchang/combatd.lpc u/yuchang/combatd1.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（同码收尾）

- 改动文件：u/smallfish/linji-zhuang/youming.lpc 
- 与前几批同型：`youming.lpc` 空 `DEBUG` 宏改空函数；`who1.lpc` 孤立的分隔线字符串删去；`jing.lpc` 被分号截断的“惨叫一声，血流如注。”接回上一句；`_dashi.lpc` 三行只造不调的 `(: call_other, __FILE__, "…_name_skill", who :);` 改成注释（行为不变）。
- 载入无回退。

- 2026-10-12：`adm/npc/obj/jubaoxiang.lpc`、`adm/npc/obj/xiang.lpc`、`adm/npc/obj/xiang1.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

`scripts/lpc_twin_port.py adopt yanhuangwuhun zhonghua2` 搬来 yanhuangwuhun 整理（89552da089f）里与本库逐 token 相同的 11 个文件（huanjing2003 的重复声明、`food`/`liquid` 的 `do_effect` 改 `varargs int`、`cmwhod` 的 `nosave` 函数改 `protected`），`scripts/toolkit_fix.sh` 去掉 3 处多余继承，其余手工，能编译的文件警告清零。改动的 18 个对象在 HEAD 与工作树各载入一次：HEAD PASS 17，tree PASS 17，regress 0。

- `clone/megazine/obj/duka_3b.lpc`（赌球卡 B）同一个赔率变量声明两次（`peis = 3` 与 `peis = 4`），代码用的是后一份；删去前一行，赔率不变（4.5）。
- `u/smallfish/mj.lpc`（麻将）自己的 `count` 遮住了基类的同名变量，改名 `mj_count`。
- `clone/obj/genmap.lpc` 在函数里 `#include "harbor.h"`，函数并不用那些港口表；删去（同 ntii）。
- `clone/book/yjj_book2.lpc`（易筋经残篇，`ITEM` + `SKILL`）写明用 `skill::clean_up()`，与驱动原先的选择相同。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 14 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里多行写的 `int hard_point() { return 2.5; }` 之类浮点经 int 返回被截断；本库没有调用者，改成 `float`，保留原数值。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/pangen-cuojiefu`、`/kungfu/skill/yiwei-dujiang`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。12 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/chan`、`huashan-sword/feilong`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`taiji-shengon`→`taiji-shengong`（`jidao-shaqi`、`jingshen-jue`、`taiji-shengong`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`、`jingshen-jue`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`jiuyin-zhua`→`jiuyin-zhao`（`huagu-mianzhang`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`shicheng-liulang`→`shicheng-liulong`（`shicheng-liulong`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/backup/2006-5-24/versiond.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`shenlong-jian/anxi`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、2 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/meizhuang/obj/panguanbi`、`/d/ajszhuang/npc/obj/female2-cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`quest/quest_jun/look.lpc`。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`SKI_ZHEN` → `/inherit/skill/array`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：4 个里 0 个通过，其余 4 个还有别的错误（`kungfu/skill/dagou-zhen.lpc`：!= always true because of incompatible types ( string vs int ).；`kungfu/skill/hebi-jianzhen.lpc`：!= always true because of incompatible types ( string vs int ).；`kungfu/skill/quanzhen-jianzhen.lpc`：!= always true because of incompatible types ( string vs int ).……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（5 个名字，最多的是 `paiyun-zhang`、`longxiang-banruo`、`puyaogedou`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 6 个通过，其余 1 个停在别的错误上（`clone/pet/pet`：*No program in object '/clone/pet/pet'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/d/xueshan/inherit/liquid_container`←nte，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 28 处、14 个文件：`jinyin-baiguzhao`→`jiuyin-baiguzhao`（8 处）、`shenzhao-jing`→`shenzhaojing`（7 处）、`tiaji-jian`→`taiji-jian`（4 处）、`changquana`→`changquan`（4 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`yan-fly`→`yanfly`（1 处）、`jiahua-neigong`→`jiaohua-neigong`（1 处）、`jinggang-zhi`→`jingang-zhi`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SKILL_USAGE_DODGE`，用到它们的物件（名单里 3 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的基类宏（2026-10-19，KB 04 §6.13、§6.16）

`include/globals.h` 补回 `STICK`、`SPEAR`、`MACE` 指向 `/inherit/weapon/` 下同名文件：`clone/newitem/newweapon/` 或 `d/city/obj/` 里 `inherit` 这些宏的物件找不到宏，载入失败（一个只在巫师目录的头文件里定义的宏，对正式文件不算已定义，`scripts/lpc_restore_macros.py` 以前把它当成了已定义）。补完后这些物件载入，没有警告。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/adm/daemons/gift/danshen.lpc`（1 处）、`/adm/daemons/gift/huangqi.lpc`（1 处）、`/adm/daemons/gift/pantao-gao.lpc`（1 处）、`/adm/daemons/gift/pantao.lpc`（1 处）、`/adm/daemons/gift/zicao.lpc`（1 处）、`/clone/medicine/zicao.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`valid_learn()` 对任何性格都拒绝。改动：`/kungfu/skill/qiankundanuoyi.lpc`（1 处）、`/kungfu/skill/zhonghua-aojue.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/d/zhuanshi/ajszhuang/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 3 处）。改动：`/adm/daemons/competed.lpc`（1 处）、`/cmds/adm/watch.lpc`（1 处）、`/kungfu/class/gaibang/lu.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## `quest_chinese.lpc` 从未编译：`set_skill("parry", "...")`（2026-10-20，KB 06 §7.328）

`kungfu/class/generate/quest_chinese.lpc` 第 60、102、143 行写成 `set_skill("parry", "taiji-jian")`（另两处是 `damo-jian`、`huashan-sword`），应当是 `map_skill("parry", ...)`：`Bad type for argument 2 of set_skill ( int vs string )`，继承它的任务 NPC 也跟着加载不了。改为 `map_skill`。加载检查（这个文件和继承它的对象共 2 个）：HEAD 通过 1 个，tree 通过 2 个，回归 0。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/adm/daemons/npc.lpc`、`/inherit/char/npc.lpc`、`/inherit/char/npc1.lpc`、`/inherit/char/npc2.lpc`（共 4 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recovermud.lpc`。

## 任务守护进程的 `clear_room()` 加载档案里没有的房间（2026-10-21，KB 06 §7.299）

管理员扫描里 `task1`（玩家指令；同系的库里还有别的入口）在 `/adm/daemons/taskd.lpc` 的 `clear_room()` 里报 `Bad argument 1 to EFUN call_other() Got: int(0)`：守护进程写死的 19 个房间里有 19 个本库没有，`room = load_object(localroom);` 答 0，下一句 `room->reset();` 就是对 0 的调用。`load_object()` 之后加 `if (!room) continue;`，有的房间照常重置。

## `board` 把 `/clone/board/` 里的数据文件当成留言板（2026-10-21，KB 06 §7.299）

管理员扫描里 `board`（`cmds/arch/board.lpc`）报 `call_other() couldn't find object '/clone/board/Answer.txt'`：指令把 `get_dir("/clone/board/")` 的每个名字都当成留言板对象去 `->short()`，目录里有一个 `Answer.txt`，不是对象。改成 `get_dir("/clone/board/*.lpc")`。

## `dual` 不带参数：`evaluate_shell()` 对 0 取下标（2026-10-21，KB 06 §7.336）

`dual`（`cmds/arch/dual.lpc`）把参数原样交给 `me->evaluate_shell(arg, flag)`，那里第一件事是 `arg[<1] == ';'`，参数为 0 时报 `Value being indexed is zero.`（`feature/shell.lpc`）；静态扫描只认直接传给 efun 的参数，看不见这种经过 `call_other` 的。命令开头加 `if (!arg) return notify_fail("指令格式 : dual [detail]\n");`（同系 16 个 `dual` 里另外 7 个本来就有这个检查）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 41 条注册（23 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/referee.lpc`（`do_halt`）、`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`）、`/clone/heidian/beijing_huoji.lpc`（`do_value`）、`/clone/heidian/chengdu_huoji.lpc`（`do_value`）、`/clone/heidian/dali_huoji.lpc`（`do_value`）、`/clone/heidian/foshan_huoji.lpc`（`do_value`） 等共 23 个文件。最多的函数名：`do_pour` 6 处、`do_value` 5 处、`do_halt` 2 处、`do_bcheck` 2 处、`do_bcun` 2 处。没有动（读过）：`/clone/pet/pet.lpc` 的 `do_move`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（7 处调用）；`/cmds/std/go.lpc` ← fyzfqyy：`query_chinese_dir()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city2/npc/zhuangyu.lpc`:`ask_weiwang`、`/d/xiakedao/npc/shipotian.lpc`:`ask_weiwang`。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 2 处（`d/city/obj/jiasha`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 2 个（新增可加载 2 个，回归 0 个）。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 4 个子目录写日志：`log/job`（`d/baituo/npc/guaishe.lpc`）、`log/money`（`d/suzhou/npc/meipo.lpc`）、`log/test`（`d/baituo/npc/shenu.lpc`）等。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/job`、`log/money`、`log/test`、`log/voting` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 3 行只含这个指针的行（`"威望": (: ask_weiwang :),` `"江湖威望": (: ask_weiwang :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 17 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 17 处（12 个文件）：拼名字的赋值 9 处、与汉字常量比较 6 处、`to_chinese()[..]` 2 处。例：`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/miejue.lpc:117`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/cheng.h:164`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/adm/npc/ganjiang.lpc:542`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：10 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 10 处（5 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1767`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/clone/pet/petowner.lpc:156`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件；`channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 14 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 6 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。


## 无参数时命令对 0 的调用（玩家/--all-dirs 残留，2026-10-27，KB 06 §7.336 Also）

无参数命令把 0 交给 `present` / `sscanf` / `file_exists` 等会运行时报错。`lpc_fix_bare_arg.py --all-dirs` 在首次使用参数前加守卫。多行 `if (arg && !sscanf)`（吐纳默认消耗）与已有 `can_learn`/`get_object` 守卫的误报已回退；本库本批改动见该提交。


## yuanwai 孤儿 call_out announce_success（2026-10-27，KB 06 §7.349 Also）

`d/changan/npc/yuanwai.lpc`（及 aoxiangtianji 的 `d/city` 副本）在 `check_daughter` 里 `call_out("announce_success", …)`，但本文件从未定义该函数；同系也无实现。到点会 *Undefined function*。`cry_daughter` 已完成认亲与赠书，删除这对 `remove_call_out`/`call_out`。证明：扫描 HIT call_out→announce_success 且无定义；改后残渣 0。
