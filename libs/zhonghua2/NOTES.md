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
   (nitan170911/nitan6/chidi/dtsl/llmud_datangshuanglong):
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
  anti-steal quirk as yuxuechongsheng (here keyed on "(admin)" and
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
   `yueyingqiyuan`, `zhongjidiyu`, `zhongjidiyu_airuoyoulan`,
   `zhongjidiyu_zhijian`, `zitengzhan`, `zuizhonghuanjing`, `zzfy` (only
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
   fix ported to `zhongjidiyu`, `zhongjidiyu_airuoyoulan`,
   `zhongjidiyu_zhijian`**, which share this identical file; only
   `zhongjidiyu_zhijian`'s sit happened to trigger it live.

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
