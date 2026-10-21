# nitan170911 — 仙剑奇侠传 (NT/nitan/Lonely mudlib lineage)

Archive: `nitan170911.7z`. Port: 40018. Status: **done** (boots clean,
connects, plays through to username entry and character-registration
gate; registration itself needs a real MySQL backend, out of scope).

## What this is

A large (~54,000 `.lpc` files under `work/`) "仙剑奇侠传" (Legend of Sword
and Fairy) themed wuxia/xianxia mudlib, "NTLIB V7.1x". Uses a MySQL-backed
account system (`db_connect`/`db_exec` via the DB package) for player
registration/login — this only partially applies here since we have no
MySQL server configured; the mudlib itself handles that failure
gracefully (see below), so this isn't a blocker for local testing.

`nitan6.zip` (archive #22, port 40019) is the same lineage — expect to
need the identical fixes described here; apply them proactively rather
than rediscovering.

## Fixes applied (see AGENTS.md §15/§15b/§15c/§15d/§15e for full writeups)

1. **`config.fluffos`**: corrected `master file`/`simulated efun file` to
   `/adm/kernel/master` and `/adm/kernel/simul_efun` (config pointed at
   `/adm/obj/...`, which doesn't exist — actual location is
   `/adm/kernel/...`).
2. **`adm/kernel/check_config.lpc`**: commented out the `#ifdef __PRIVS__
   need(...)` block — driver has PRIVS on globally, no per-lib toggle
   exists, field is inert/unused by this mudlib.
3. **The big one — simul_efun-based `set`/`query`/`delete` dbase
   architecture (AGENTS.md §15).** `this_object()` is the SIMUL_EFUN
   OBJECT during a bare simul_efun call on this driver, not the caller —
   confirmed empirically. Fixed by:
   - `feature/dbase.lpc`: added real local `set`/`query`/`delete`/
     `set_temp`/`query_temp`/`delete_temp` (with an `ob`-redirect trailing
     param, since the dominant call convention across this mudlib is
     `query(prop, ob)` / `set(prop, data, ob)`, not the documented 2-arg
     "raw flag" form). Every object inheriting F_DBASE (nearly everything)
     now gets correct per-object storage via ordinary inheritance.
   - `adm/kernel/simul_efun.lpc`: stopped `inherit F_DBASE` (which itself
     calls bare `set`/`query`/`get_object`, and during simul_efun.lpc's
     OWN self-composition those resolve against not-yet-defined local
     prototypes, not the real simul_efun functions defined later in the
     same file — a bootstrapping trap). Inherits `F_TREEMAP` directly
     instead and declares `dbase`/`tmp_dbase`/`default_ob` inline.
   - `adm/kernel/simul_efun/wizard.lpc`: kept as a fallback ONLY for
     objects that don't inherit F_DBASE, with the same `ob`-redirect.
   - Files with their OWN local set/query override (`inherit/room/
     room.lpc`, `clone/user/user.lpc`, `clone/user/baby.lpc`,
     `adm/daemons/giftd.lpc`, `adm/daemons/examined.lpc`) had their
     `efun::set/query/delete/addn(...)` fallback calls fixed to
     `::set(...)` (explicit parent-scope call to F_DBASE's real
     implementation) for the "operate on myself" case, and `ob->X(...)`
     (plain call_other) for the "operate on a different given object"
     case. **Do NOT route the self-case through the simul_efun object** —
     it recurses infinitely back into the same override (hit this on
     room.lpc: "Too deep recursion").
4. **Restored several never-actually-defined globals** (AGENTS.md §15b),
   each only surfacing at runtime the first time some code path used
   them:
   - `addn`/`addn_temp` (numeric increment-or-set) — new simul_efun in
     `wizard.lpc`, delegating to `ob->add(prop, data)` /
     `ob->add_temp(...)`.
   - `remove_ansi`/`noansi_strlen` — new `adm/kernel/simul_efun/
     ansi_util.lpc` fragment (included early, before chinese.lpc/file.lpc
     which call it).
   - `B2G` (Big5→GBK, meaningless post-UTF8-conversion) and `db_affected`
     (no driver equivalent — see below) — new `adm/kernel/simul_efun/
     db_compat.lpc` fragment.
5. **`adm/etc/preload`** (AGENTS.md §15c): stripped `.c` from every line
   (`sed -i 's/\.c$//'`) — this plain-text daemon preload list still had
   the old `.c` extensions, so `securityd`/`databased`/`logind`/etc. never
   loaded post-rename (silently — the mudlib's own preload loop
   `catch()`es load failures). Root-caused via `lpcc --batch` directly
   against `/adm/daemons/securityd` returning FAIL with no visible error,
   then a `catch()`-wrapped `restore()` revealing the real chain.
6. **`u/redl/cangku.lpc`** and **`adm/daemons/equipmentd.lpc`**
   (AGENTS.md §15e): guarded two un-checked `->method()` calls chained
   straight onto `TEMPLATE_D->create_object(...)` / `EQUIPMENT_D->
   create_dynamic(...)`, both of which can legitimately return 0 (missing/
   mismatched item template) — this only surfaces the first time
   `timed.lpc`'s cron `init_crontab()` runs (which happens to create a
   specific player's warehouse object, which happens to auto-populate
   random equipment). No other unchecked call sites of these two
   factories were audited exhaustively — if a similar crash recurs
   elsewhere, it's the same shape.

## Interactive test result

Boots clean (`Initializations complete.`), telnet connects, full ANSI-art
welcome banner renders correctly (UTF-8, Chinese glyphs intact), uptime
line prints, registered-player-count line prints (both go through
`TIME_D`/`CHINESE_D` call chains that previously crashed), username prompt
appears and validates (rejects non-alphabetic / wrong-length names
correctly), and new-account registration is correctly rejected with a
friendly message when the MySQL backend is unreachable:

> 对不起，由于连接不上数据库所在服务器，目前仙剑奇侠传暂时不接受数据漫游或
> 新玩家注册。

This is expected/correct behavior given no MySQL server is configured for
this converted lib — not a bug. Setting up a real MySQL backend to test
actual character creation/login is out of scope for this pass.

## lpcc sweep

**Not completed** — this lib has ~54,600 `.lpc` files, and `lpcc --batch`
keeps everything loaded in one VM session with no unloading; the sweep
drove this 23GB host down to ~370MB free with heavy swapping after ~18
minutes, well before finishing, so it was killed rather than risk an OOM
(see AGENTS.md §6b's mega-lib note). The boot + interactive-connect test
above is what actually found every real bug fixed in this pass (§15/§15b/
§15c/§15e) and is treated as sufficient verification for a lib this size;
a full sweep would mostly surface the same long-tail false positives
described in §6b (files needing specific runtime context to load) rather
than new architecture bugs, at real cost to run safely.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 54627 `.lpc`
  files under `work/` (mega-lib — per AGENTS.md's mega-lib guidance this
  was run anyway, just expected to take longer) — 54596 reformatted, 28
  unchanged, 3 refused (token-mismatch safety gate, negligible at this
  scale).
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`, zero fatal errors, `RSS` stayed modest —
  this only preloads a short daemon list, not the whole 54,600-file
  tree, so it's a fast/cheap boot despite the raw file count). Per
  AGENTS.md's mega-lib guidance, did **not** run the full `lpcc` sweep
  again (same reasoning as the original pass). Confirmed via
  `mudclient.py` that registration still correctly hits the same
  documented MySQL-unavailable gate as before, unchanged:
  `对不起，由于连接不上数据库所在服务器，目前仙剑奇侠传暂时不接受数据
  漫游或新玩家注册。` — expected/correct given no MySQL backend is
  configured here, not a regression.
- **Same `feature/alias.lpc` malformed-character-literal bug as
  `nitan6`** (byte-identical raw source, confirmed via diff) — fixed
  here too (`case '''` → `case '\''`), even though the MySQL gate means
  `make_body()`/this code path can't actually be exercised in this
  sandboxed environment (no player ever gets past registration to
  reach the player-body class). Applied proactively for lineage
  consistency and in case a future pass adds a real MySQL backend.
- **WASM build test** (`scripts/wasm_client.js`): contrary to this
  pass's own worst-case expectation ("copying the whole 506MB/61,157-
  file `work/` tree into an in-memory FS may be slow/memory-heavy"),
  the test **completed quickly and cleanly**, well within a bounded
  240-second wall-clock budget — boot only loads the short
  `adm/etc/preload` daemon list (same as native), not the full file
  tree, so the mega-lib's sheer file count doesn't translate into a
  slow/expensive WASM boot the way a full `lpcc` sweep would. Host
  memory stayed healthy throughout (checked via `free -h` mid-run).
  Login hit the **same documented `query_ip_number()`-under-WASM
  limitation** as `nitan6`/`nitan_ceshi`/`nitan_san`: this lineage's
  shared `BAN_D->is_banned()` (identical `sscanf(site, "%s.%s.%s.%s",
  ...) != 4` shape) rejected the connection with `你的地址在本 MUD
  不受欢迎，请去论坛 muds.cn 申述。` immediately after the banner — not
  a mudlib bug, the documented driver-side WASM gap. (The MySQL-gate
  question is moot here since the IP-ban check fires first, before the
  registration flow is ever reached.) Status: **boots under WASM
  quickly and without incident; login blocked by the query_ip_number()
  -under-WASM limitation (same root cause as the rest of the NT/nitan
  lineage in this batch)** — the mega-lib size turned out NOT to be a
  practical obstacle for this particular test, worth noting for future
  passes considering the same worry.

## WASM-enablement pass (2026-07-24): loopback-allow (admin seeding skipped)

Gates patched (same shapes as the rest of the NT/nitan lineage; loopback
= `127.0.0.1`, any `127.*`, or an empty/malformed non-dotted-quad string):

- `adm/daemons/band.lpc` `is_banned()` — loopback short-circuit return 0;
  malformed IPs (previously `return 1` = banned — this was the documented
  WASM login blocker for this lib) now return 0. `is_multi_login()` —
  loopback always allowed.
- `adm/daemons/logind.lpc` `logon()` (~line 109) — loopback/malformed IPs
  set `str = 0` and bypass: the `blocks[]` punish list, the
  >30-stale-connections `block_ip()` blocker, the same-IP `ban_cnt > 20`
  cap, and the `ip_cnt > MULTI_LOGIN` cap.
- No `uptime()` startup gate in this lib (uses the graceful
  `SYSTEM_D->valid_login()` wait queue).

**Admin seeding SKIPPED** — registration and character save/restore are
MySQL-backed (`DB_SAVE` defined; `DATABASE_D->db_save_all/db_restore_all`
in the save path, `do_sql()` user lookups in `logind.lpc`). With no DB
server the flow correctly rejects new registrations ("连接不上数据库所在
服务器"), so the real registration flow cannot produce a fluffos account,
and hand-crafting a save would not survive the DB-backed restore path.
Making this lib DB-less is real (WASM-relevant, since WASM builds have no
`db` package at all) but is an architecture change beyond this pass —
flagged as future work.

Retest: boots clean, banner + id prompt + the documented DB-unavailable
rejection all behave exactly as before the patch; debug.log clean.

### Fail-closed retrofit (2026-07-24)

The `band.lpc`/`logind.lpc` carve-outs above originally ALSO treated any
empty/non-string/unparseable IP as trusted-local (fail-open, defensive
against an older WASM `query_ip_number()` bug now fixed upstream).
Tightened to strict loopback only (`"127.0.0.1"`, `"::1"`, `"127."`
prefix); `band.lpc`'s `is_banned()`/`is_multi_login()` also had their
pre-existing malformed-format fallback restored to the ORIGINAL fail-safe
(`return 1` = banned for anything that isn't a clean loopback address or
a valid 4-part dotted quad, matching the codebase's own convention before
this pass touched it).

**Bug found and fixed during the retrofit**: `logind.lpc`'s `logon()`
reused the same `str` variable both as "the real IP" (later passed
verbatim to `BAN_D->is_banned(str)`) and as a "0 = loopback, skip
anti-flood gates" sentinel. Zeroing `str` for loopback connections meant
`is_banned(0)` was called for every local connection — which, after the
fail-safe restore above, now correctly rejects non-string input, so
**loopback connections were being banned** ("你的地址在本 MUD 不受欢迎")
until this was caught by retest. Fixed by introducing a separate
`local_conn` boolean for the anti-flood gates and leaving `str` as the
real IP throughout (same fix applied to sibling `nitan6`, which has the
identical shape). Re-verified: loopback connection reaches the id prompt
and the documented DB-unavailable rejection again, no ban message.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass per AGENTS.md §10.7. Every prior pass on
this lib stopped at the documented MySQL-unavailable registration gate
("对不起，由于连接不上数据库所在服务器…") and treated that as the
end of the road — this pass instead stood up a **real local MySQL
backend** (this lib genuinely needs one: `DB_SAVE` is active whenever
the driver is built with `PACKAGE_DB`/`PACKAGE_DB_MYSQL`, which the
project's `build-debug` driver is) specifically so the actual
registration → persistence → login chain could be exercised for the
first time, and it immediately paid off: **four real, previously-
invisible programming bugs**, one of them severe enough that no
account created under the old (broken) code could ever log back in.

### Test environment: a real local MySQL, not a mock

`db_connect(DB_HOST, DATABASE, DB_USER)` resolves (via
`/adm/etc/config`'s `mysql host`/`mysql user`/`mysql database` lines,
read by `CONFIG_D`) to a real server, with the password supplied by
`adm/kernel/master/valid_database.lpc`'s `valid_database()` hook
(hardcoded `"mud46899981"` for host `"localhost"` in the original
source — a real secret already committed in this converted lib, not
something this pass introduced). Stood up a disposable MariaDB 10.11 in
Docker (`docker run -d --name nitan170911_mysql -p 127.0.0.1:3306:3306
-e MYSQL_ROOT_PASSWORD=rootpw -e MYSQL_DATABASE=mud -e MYSQL_USER=mud
-e MYSQL_PASSWORD=mud46899981 mariadb:10.11`), created a `users` table
matching every column `databased.lpc`'s SQL touches (`id`, `name`,
`surname`, `purename`, `password`, `ad_password`, `birthday` DATETIME,
`online`/`on_time`/`fee_time`/`save_time`, `f_mail`, `last_from`,
`last_on`/`last_off`, `last_station`, `endrgt`, `login_dbase`,
`char_idname`, `f_autoload`/`f_dbase`/`f_damage`/`f_condition`/
`f_attack`/`f_skill`/`f_alias`/`f_user`/`f_business` all `LONGTEXT`,
`utf8mb4`), and — since `mysql_real_connect()` treats the literal
string `"localhost"` as "use a local unix socket", not TCP, and no
socket file exists for a Dockerized server — pointed the config at
`127.0.0.1` instead (`adm/etc/config`) with a matching case added to
`valid_database.lpc`'s host switch (kept, harmless if no DB server is
running — same graceful-rejection behavior as before). This whole
MySQL setup is **test-environment infrastructure**, not part of the
repo (the Docker container was stopped, not deleted, at the end of this
pass); reproduce with the `docker run` line above plus the `users`
table DDL in this section if continuing this work.

### Test characters

- **`qinfeng` / 秦风 (real name), password `PlayPass123`, admin
  password `AdminQin987`** — the representative playthrough character.
  Kept. Final state: registered, personality 光明磊落 (chose "choose
  1"), attributes washed to 20/20/20/20 (`washto 20 20 20 20`),
  standing at `世界之树` (World Tree) in the `古村` (Ancient Village)
  tutorial zone, inventory has the starter book/shoes/cloth plus
  duplicates from re-registering during bug-hunting (harmless). Save
  files: `work/data/user/q/qinfeng.o`, `work/data/login/q/qinfeng.o`;
  DB row `id='qinfeng'`.
- **`fluffos` / 浮夫, password `Mud@2026`, admin password
  `AdminMgmt987`** — the standard project admin account (AGENTS.md
  §1.5), seeded via `adm/etc/wizlist` (`fluffos (admin)`) rather than
  registered-then-granted, since this lib's `(admin)` wizlist status
  alone is sufficient for the canonical `update` check (verified:
  `update /d/register/regroom` → "重新编译…成功！"). Note: this
  lineage has a SEPARATE, narrower `is_admin()` gate (hardcoded to
  `getuid()=="lonely"` or `"redl"`, `clone/user/user.lpc:94-97`) that
  `eval`/`call`(non-`(arch)`-scoped modes)/`smash`/`copyskill` also
  require — `fluffos` does NOT have this narrower flag (by design;
  granting it needs root-euid code, i.e. editing the running character
  or its own dbase from something with `ROOT_UID`, out of scope here).
  This is the SAME shape as AGENTS.md §1.5's addendum bug class ("rank
  granted but write ACL empty by design" / a separate escape hatch
  hardcoded to original-author uids) — not re-documented as new.
  `fluffos` has not set a `wizpwd` (optional extra hardening the
  mudlib itself prompts for on login as a non-`(player)` account); left
  unset, matching a fresh seed. Several other throwaway ids used only
  for isolating bugs (`dbgone`..`dbgeight`, `qadebug`, a failed `redl`
  registration attempt — reserved wizlist names can't self-register,
  correct behavior not a bug) were all cleaned up (save files deleted,
  DB rows deleted, `qadebug` removed from `wizlist`).

### Newbie doc read first

`doc/help/newbie` is just an index; the real content is
`doc/help/newbie-basic` — explains the safe `fight` sparring verb
(stops before death, unlike `hit`/`kill`), `set wimpy`, the `bai`/`xue`
master-and-skill-learning pipeline, and that death is non-punishing for
newbies. Matched observed behavior closely (see below).

### Registration → persistence chain: verified end-to-end, four real bugs found and fixed

Walked the full flow live, repeatedly, across many fresh accounts:
username → Chinese surname/name → admin password → normal password →
gender → `waiting_enter_world()`'s countdown screen → landing room →
`register <email>` → character-creation room (`生命之谷`) → `choose`
personality → `washto` attributes → tutorial village (`古村`) → `ask
lao about 出村` → exit to the real world (`武庙`/`扬州城`, exactly
matching the newbie doc's documented default spawn point) → `look`/
`score`/`hp`/`i` all producing correct, fully-populated output → `fight`
sparring → `bai <npc>` apprenticeship attempts → `save`/`quit` → real
reconnect (both net-dead-resume and a genuine cold relogin after the
30-second post-quit cooldown) → state (location/attributes/personality/
inventory) all confirmed to survive, including across an unrelated
**driver crash** (see below) that happened mid-session.

**1. `feature/name.lpc` — every bare `set()`/`query()` call in this
file silently operated on the SIMUL_EFUN object's own shared dbase
instead of the caller's, so a brand-new character's "name" property
was NEVER actually set — the single root cause blocking this whole
lib's persistence.** New manifestation of the F_DBASE bare-call
bootstrapping trap already cataloged (AGENTS.md, this lib's own §15/
NOTES.md fix #3): `feature/name.lpc` is inherited by `char.lpc` as a
SIBLING of `F_DBASE` (not through it), so its own bare calls don't
resolve against the composed object's real F_DBASE the way calls from
files that themselves inherit F_DBASE do — they fall through to the
SIMUL_EFUN object's fallback `wizard.lpc` implementation, silently
reading/writing that shared object's `dbase` instead of `this_object()`'s
own. `query_idname()` (the LAST function in the file) already worked
around this correctly with an explicit `query("name", this_object())`
redirect — every OTHER function in the file (`set_name`, `set_color`,
`name`, `short`, `long`, plus the `query_temp`/`set_temp` calls) did
not. Confirmed empirically with `log_file()` instrumentation: reading
`user`'s own `surname`/`purename` via an EXTERNAL redirected call
(`query("surname", user)` from `logind.lpc`) returned the correct
value; reading the SAME properties via a BARE call from *inside*
`user`'s own `set_name()` (`this_object()` genuinely `== user` at that
point, confirmed in the log) returned `0`. `set_name(0, id)` (the
"compute name from surname+purename" path, used for every new-player
registration) therefore always saw `surname`/`purename` as unset, fell
through to the `"无名氏"` placeholder, and even THAT placeholder went
to the wrong (shared) dbase — so the real object's `"name"` property
was left permanently undefined. This silently broke
`DATABASE_D->db_new_player()`'s `!stringp(my["name"])` guard (which is
correct, defensive code) on literally every registration, so no
account's DB row was EVER created; every subsequent login for that id
then hit the DB-driven existence check, found nothing, and treated the
already-registered character as brand new again — an account, once
created, could never be logged back into. Fixed by adding an explicit
`this_object()` redirect to every `query()`/`set()`/`query_temp()` call
in the file, matching `query_idname()`'s existing pattern:
```lpc
// BEFORE (feature/name.lpc, set_name(), abbreviated):
if (!stringp(fullname = query("surname")))  fullname = "";
if (stringp(query("purename")))  fullname += query("purename");
...
set("name", fullname);
// AFTER:
if (!stringp(fullname = query("surname", this_object())))  fullname = "";
if (stringp(query("purename", this_object())))  fullname += query("purename", this_object());
...
set("name", fullname, this_object());
```
(same treatment applied to `set_color()`, `id()`'s `query_temp("apply/id")`,
`name()`, `short()`, `long()`). Verified via `log_file()` instrumentation
that `db_new_player()` now sees a real `name` and the INSERT succeeds
(`db_exec ret=0`, `db_affected=1`); verified end-to-end that a fresh
registration now produces a DB row, and that a real reconnect after a
driver restart correctly recognizes the account as existing instead of
offering to recreate it.

**2. `adm/daemons/databased.lpc`'s `db_restore_all()` — every
`restore_variable()` call on a not-yet-populated DB column crashed with
"Bad argument 1 to restore_variable() Expected: string Got: 0", and
since none of the ten calls were `catch()`-wrapped, the FIRST one to
hit a `NULL` column silently aborted the rest of the function —
including the player's own dbase restore three lines later — leaving
a freshly-logged-in character half-initialized (command dispatch
appeared to silently swallow every subsequent command with zero
response, no error, nothing — found by noticing `look`/`score` simply
produced no output at all after a first-ever login, then tracing it to
this abort via `debug.log`, not by code inspection).** Root cause:
`db_new_player()`'s own `INSERT` only ever populates
`id`/`name`/`surname`/`purename`/`password`/`ad_password`/`birthday`/
`online`/`on_time`/`fee_time`/`login_dbase`/`f_dbase` — every OTHER
column (`f_autoload`, `f_condition`, `f_business`, `f_mail`, `f_alias`,
`f_attack`, `f_damage`, `f_skill`, `f_user`, `char_idname`) stays
`NULL` until the player's first real save, and `db_fetch()` returns SQL
`NULL` as LPC `int 0`, which `restore_variable()` rejects outright.
Fixed by guarding each of the ten calls with `stringp(...)`, falling
back to the same empty value (`([])`/`({})`/`0`) the corresponding
setter's own callers already treat as "nothing saved yet" elsewhere in
the codebase:
```lpc
// BEFORE:
user->set_autoload_info(restore_variable(f_autoload));
// AFTER:
user->set_autoload_info(stringp(f_autoload) ? restore_variable(f_autoload) : ({}));
```
(same treatment for all ten calls, including the `login_dbase` →
`myob->set_dbase(...)` one, defensively, even though that column is
always populated from the very first INSERT). Verified: a brand-new
account's first-ever DB-backed login now completes cleanly, commands
work immediately, and `debug.log` gained zero new lines across an
entire subsequent playthrough (registration through `quit`).

**3. `adm/kernel/simul_efun/message.lpc` — `tell_room()`/`tell_object()`/
`shout()`/`write()`/`say()` (defined ABOVE `message()` in the same
file) all resolved their own bare `message(...)` calls to the raw
driver EFUN instead of the local wrapper defined later in the file,
because FluffOS's single-pass compiler binds a bare call to whatever is
visible AT that point in the file, not to a same-file function defined
further down without a forward prototype. Every one of those callers
either omits the optional `exclude` argument or (like
`message_system()`, itself defined below `message()` and so correctly
routed) passes literal `0` for it — and the real EFUN's signature only
accepts `void | object | object *` there, throwing "Bad argument 4 to
EFUN message() Expected: object, array, Got: int(0)" every single time
any of those five wrapper functions ran** — confirmed firing on nearly
every login (`logind.lpc:enter_world()`'s own direct `message("system",
…, users)` call, only 3 args, hits the identical shape) and on every
`heart_beat()` tick of several plaza rooms (`/d/dongtian/*/guangchang.lpc`)
that call `tell_room()`. Fixed two ways: (a) `message()` itself now
normalizes a non-object/non-array `exclude` to `({})` before calling
the real efun (so every caller, however it reaches `message()`, is
safe); (b) added an explicit forward prototype
(`varargs void message(mixed arg, string message, mixed target, mixed
exclude);`) near the top of the file so `tell_room()` and friends
actually bind to the local wrapper instead of the bare efun in the
first place — (a) alone was verified insufficient (the error kept
firing via `tell_room()` even after the wrapper was fixed, because
those call sites were never reaching it):
```lpc
// added near the top of message.lpc, before any caller:
varargs void message(mixed arg, string message, mixed target, mixed exclude);
...
// the wrapper itself, also made varargs to match:
varargs void message(mixed arg, string message, mixed target, mixed exclude) {
  if (!arrayp(exclude) && !objectp(exclude)) exclude = ({});
  efun::message(arg, message, target, exclude);
}
```
Verified: the exact error stopped appearing in `debug.log` after this
fix, across logins and across observed plaza-room heartbeat ticks.

**4. Test-environment-only, NOT an .lpc fix**: `db_save_all()`'s
`", save_time = now()"` was silently failing every single save
(`"Out of range value for column 'save_time'"`, logged to
`log/database`, never surfaced to the player — `user.lpc`'s `save()`
does `res = db_save_all(...); if (TX_SAVE) res = ::save();`,
discarding the DB result entirely, so `save`/`quit` always reported
success regardless) because THIS PASS's own test `users` table had
`save_time` typed `INT` instead of `DATETIME`. Not a mudlib bug — the
real schema this lib expects clearly wants a temporal type here (same
as `birthday`); fixed by `ALTER TABLE users MODIFY save_time DATETIME
NULL` on the test DB. Documented here because it fully explained an
alarming-looking symptom (a fresh relogin appeared to revert
`qinfeng`'s attributes/skills/registration status back to
account-creation defaults) that easily could have been mistaken for a
real persistence bug in `restore()`'s DB-over-local priority ordering —
once `db_save_all()` actually succeeded, a real cross-session,
cross-driver-restart, cross-driver-**crash** reconnect correctly
preserved full character state.

### A genuine driver-fatal crash during the net-dead soak — matches AGENTS.md §10.8's existing class, not re-documented as new

~30 real minutes into this session, while `qinfeng` sat net-dead
(disconnected without `quit`, no commands, ambient world simulation
running) for a deliberate net-dead-timeout test, the **entire driver
process died**: `******** FATAL ERROR: stralloc.c: free_string called
on non-shared string: /clone/user/user#23.` — `/clone/user/user#23`
being `qinfeng`'s own live body. `debug.log` shows nothing at all for
this (consistent with §10.8's finding that this crash class is
invisible there — only caught because the driver's own stdout was
redirected to a file). This is corroborating evidence for AGENTS.md
§10.8's already-documented, still-unpinned driver-level refcount/
double-free corruption class (four prior independent occurrences
across four other libs, "ref count 0 but not destructed" from
`free_svalue`/similar) — same signature family (a low-level allocator
consistency check aborting the process, not a catchable LPC error),
though the specific corrupted structure here is a **string** (`stralloc.c`
`free_string`) rather than an object, and the trigger context (a
player's own net-dead body, not ambient NPC wandering, an admin
reconnect, or a periodic GC sweep) is a fifth distinct trigger shape.
Not mudlib-fixable (root-caused to the driver, per §10.8); re-verified
by restarting the driver and reconnecting — `qinfeng`'s full state
(location, washed attributes, personality, inventory) survived the
crash correctly, confirming the persistence fixes above hold up even
across this kind of failure.

### Explored: 古村 tutorial zone → 扬州城/武庙 (matches newbie doc exactly)

Fresh registrations land in `生命之谷` (a shared character-creation
room: `choose <personality 1-4>` then `washto <str> <int> <con> <dex>`
teleports to `世界之树` in `古村`, a self-contained tutorial village
with an `ask lao about <topic 1-13>` info system and a `closeeye`
NPC-gift interaction that grants ten free levels each in six basic
skills — `force`/`sword`/`parry`/`dodge`/`blade`/`unarmed` — plus a
large burst of starting exp/potential). `ask hua about 出村` at the
village gate offers a menu including "直接出村（到扬州武庙）" (exit
directly to 武庙) and "拜师（到门派入门师傅处）" (go straight to a
sect's entrance master) — took the former, which places the character
exactly where `doc/help/newbie-basic` says a fresh character lands:
`武庙`/`扬州城`, with `钱庄` (bank), `客店` (inn), `醉仙楼` (a named
inn matching the doc's own example), and a central plaza with a large
tree (`中央广场`) whose `树洞` (tree hollow) is a hidden `enter`-style
passage into `丐帮`'s (Beggar Sect) underground hideout — all exactly
matching the doc's description.

### Safe sparring: confirmed working live

`fight <npc>` (e.g. `fight meipo` against the matchmaker NPC in
北大街) produced a normal multi-round combat log with real damage
numbers on both sides, no death risk apparent within the exchange —
matches `doc/help/newbie-basic`'s description of `fight` as the safe
sparring verb (vs. `hit`/`kill`, which force a real fight). Not chased
to a full "does it truly stop before death" confirmation given time
budget, but the mechanism itself (the verb exists, dispatches, and
behaves as documented) is verified live.

### Skill learning / sect join: partially verified, not a bug

`bai <npc>` (apprenticeship request) against low-rank Beggar Sect NPCs
in the tree-hollow hideout (`丐帮一袋弟子`/`丐帮二袋弟子`/`丐帮七袋
弟子`, all with randomly-generated Chinese names via
`NPC_D->generate_cn_name()`) consistently returned "…既不属於任何
门派，也没有开山立派，不能拜师" (doesn't belong to any sect, can't
recruit) — these NPCs genuinely have no `family` mapping set
(`apprentice.lpc`'s own early-return guard, not a bug: real
recruitment is gated to more senior members not reached in the time
available, the same "recruitment gated behind a real sect hall, not
the newbie-adjacent representative NPCs" shape already documented for
`xuanjianlu` in this project). The organic skill-learning path via
`closeeye`'s starting-skill grant (ten levels each in six skills) WAS
exercised live and is a genuine, working, non-code-review-only
confirmation of skill progression; a full `bai`→`xue` cycle against an
actual recruiting master was not completed live within this pass's
time budget.

### Explicitly NOT verified live (time budget)

- **A shop purchase.** `qinfeng` has no money (`没有积蓄`) at the point
  this pass ran out of time; `list`/`buy` at a real shop (e.g. 醉仙楼)
  was not attempted. `check` (bank-balance command) was tried once from
  the wrong context (tutorial village, not a real bank) and correctly
  rejected as a different command overload — not evidence of a bug.
- **A full `bai`→`xue` cycle against an actual sect-recruiting master**
  (see above) — the readily-reachable NPCs don't recruit; reaching one
  that does was not completed in time.
- **The real, full-duration `NET_DEAD_TIMEOUT` wait** (`include/user.h`:
  900 real seconds / 15 minutes) — the driver crash above (a genuine,
  if unrelated, finding) cut the net-dead soak short at ~1 minute of
  actual disconnected time before a driver restart was needed; the
  crash itself is a legitimate (if accidental) escalation per §10.8's
  own encouragement to soak-test, but the specific 900-second reconnect
  path (does `user_dump(DUMP_NET_DEAD)` correctly force-quit and clean
  up a truly-expired net-dead body) was not directly observed.
- **Progressing to real combat/death against a hostile NPC or a real
  duel.** Time budget was spent on the registration/persistence bug
  chain above instead, which was the far more consequential finding.

## 深度功能测试后续（本轮）：§7.78 第 4 个确认实例

本轮不是全新的 §10.7 深度测试——上面已有的记录已经相当完整（技能升级
实测、`message()`/`tell_room()` 修复、一次真实的驱动崩溃发现、净断连
soak test 等）。本轮专门针对 xfbhh/hhsj/nt1 三个 lib 依次确认过的
**§7.78**（CHARACTER 组成的 mixin 文件里裸 `set()`/`query()` 调用解
析不到本对象的 F_DBASE）做一次定向检查——`nitan170911` 是这整条
NT/nitan 血统的最初母本（xfbhh/hhsj/nt1 都是它的后代分支），如果连它
自己都有这个 bug，就能确认这是上游架构从一开始就带着的通病，不是后
续哪个分支自己引入的。

**结果：确实有，而且裸调用数量和 xfbhh 几乎逐行对得上**
（`attack.lpc` 12 处、`damage.lpc` 54 处等），`command.lpc` 的
`enable_player()` 也是同款 `set_living_name(query("id"))` 崩溃写法。
按已经验证过 3 次的相同修法处理：13 个 mixin 文件（`action`/
`apprentice`/`attack`/`attribute`/`command`/`condition`/`damage`/
`equip_liv`/`message`/`more`/`move`/`name`/`team`）里"自己对自己"的
裸调用改成 `this_object()->set(...)`/`this_object()->query(...)`。
`feature/message.lpc`（这次改的这个）和已经修好的
`adm/kernel/simul_efun/message.lpc`（README 里记录的
exc_target=0/tell_room() 修复）是两个完全不同的档案，互不冲突，改动
前已确认过。

**本轮明确做不到的事：真人游玩验证。** 这份档案的注册与登录**完全**
依赖 MySQL（`#ifdef DB_SAVE`分支——不只是新注册，连 `qinfeng`
这样已有本地存档的老角色登录也会先走 `DATABASE_D->query_db_status()`
检查，本环境这台机器上根本没装 MySQL/MariaDB，`which mysql` 都找不
到），这是 README 里已经记录过的真实、永久的环境限制，不是这次新发
现。因此本轮只能做到：格式化工具确认 13 个文件 0 语法错误、干净重新
编译（`debug.log`/`boot.log` 都不含任何和这 13 个档案相关的报错或警
告）、以及依赖已经在 xfbhh/hhsj/nt1 三次真人验证过的同一套修法本身的
可信度——没有再做一次真正的注册/登录/对话验证。如果将来这台机器配置
了 MySQL，建议优先用 `qinfeng`/`PlayPass123` 登录一次，走到任意一个
有 NPC 对话的场景，确认 NPC 名字和自己的名字都正确显示（不再是
xfbhh 那种"巨斧"/字面 "0" 的乱码）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan 血统；游戏内品牌为"仙剑奇侠传"。没有预先播种管理员账号（这份档案的注册/存档后端真的要跑 MySQL，本环境没有配置——这份档案自己的 README 里已经记录为一个真实、永久的例外，不是 bug）——状态是靠重新测试一次全新的 WASM 注册流程来修正过时的 limited 标记：英文 id→确认→中文姓氏+名字（常见的测试名字比如"秦风"和已有的存档玩家数据冲突，需要一个真正没被用过的组合）→管理密码+确认→登录密码+确认→角色类型菜单→性别，干净地进入游戏世界，没有任何错误；quit 正确触发了这份档案自己"新账号 30 分钟内可撤销注册"的设计（不是 bug）并干净完成。mysql_d.lpc 的 db_connect()/db_exec()"Undefined function"编译错误是预期之中、转档前就存在的（这个驱动构建没有 db 包），不影响游戏。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 83 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Round-two re-test (2026-08-14): post-driver-upgrade re-verification

Standard round-two §10.7 pass against the rebuilt driver (`~/src/fluffos`
post PRs #1343/#1344, plus the corpus-wide `%`-on-float fix). This lib
was in the round-one-only queue.

### Scope decision: light path, not a fresh MySQL playthrough

Checked for a working MySQL/MariaDB setup before starting: no `mysql`/
`mariadb` client binaries on this host, and — more importantly — the
Docker **daemon itself is not running** (`/var/run/docker.sock` doesn't
exist, `docker ps` fails with "no such file or directory") and starting
it requires `systemctl start docker`, which needs an interactive sudo
password not available in this environment. The `nitan170911_mysql`
container from the 2026-07-24 pass therefore couldn't even be inspected
(`docker ps -a` itself fails, not just "container not found"). Standing
up Docker from scratch here would mean first getting a root shell,
outside this pass's time budget, so per this task's own fallback
guidance this pass took the **lighter, non-MySQL path** (same precedent
as the §7.78 follow-up pass above): independent re-verification of every
documented fix by grep, the standard checklist, and a native boot +
connect check.

### 1. Re-verified every previously-documented fix is still in the code

All confirmed present and unchanged in shape:

- `feature/name.lpc`: every live `query()`/`set()`/`query_temp()` call
  site (`set_name`, `set_color`, `id()`, `name()`, `short()`, `long()`)
  still carries the `this_object()` redirect — 17 occurrences, all via
  the (even more explicit) `this_object()->query(..., this_object())`
  form. The one bare `query("name")` grep hit is inside a comment
  (line 60), not live code.
- `adm/daemons/databased.lpc`'s `db_restore_all()`: all ten
  `restore_variable()` calls (`f_dbase`, `f_autoload`, `f_condition`,
  `f_business`, `f_mail`, `f_alias`, `f_attack`, `f_damage`, `f_skill`,
  `f_user`, plus `char_idname`/`login_dbase`) still guarded with
  `stringp(...) ? restore_variable(...) : <fallback>`.
- `adm/kernel/simul_efun/message.lpc`: forward prototype
  (`varargs void message(...)`, line 13) present before `message_vision`/
  `message_sort`/`message_combatd`/`tell_room` etc., and the real
  `message()` wrapper still normalizes a non-array/non-object `exclude`
  to `({})` before calling the raw efun.
- The 13 §7.78 mixin files (`feature/action.lpc`,
  `apprentice.lpc`, `attack.lpc`, `attribute.lpc`, `command.lpc`,
  `condition.lpc`, `damage.lpc`, `equip_liv.lpc`, `message.lpc`,
  `more.lpc`, `move.lpc`, `name.lpc`, `team.lpc`): all still carry their
  `this_object()->set/query(...)` redirects (counts range from 1 to 150
  occurrences per file, e.g. `damage.lpc` 150, `attack.lpc` 26,
  `apprentice.lpc` 31).
- §7.86 board sweep: 84 files still `inherit BULLETIN_BOARD`
  (one more than the originally-reported 83 — harmless, likely a newly
  swept-in file counted differently), spot-checked a sample of 5 and
  confirmed none carry a lingering `replace_program(...)` call.
- The fail-closed loopback retrofit (`band.lpc`'s strict-loopback
  `is_banned()`/`is_multi_login()` checks, `logind.lpc`'s separate
  `local_conn` boolean distinct from the real `str` IP variable): both
  still present and unchanged.

### 2. Standard checklist

- **Kernel simul_efun `file.lpc`-equivalent**
  (`adm/kernel/simul_efun/file.lpc`): `assure_file()` is defined at
  line 13, textually BEFORE its only two callers `log_file()` (line 37)
  and `sys_log()` (line 125) — already correctly ordered, no forward
  declaration needed, no fix required.
- **`config.fluffos`'s `maximum evaluation cost`**: already
  `2147483647` (effectively unbounded) — well above the 5000000 safe
  floor, no change needed.
- **`cmds/wiz/update.lpc`'s `present(file, environment(me))` crash
  (§7.106)**: already correctly guarded —
  `if (environment(me) && (obj = present(file, environment(me))) &&
  playerp(obj) || ...)` (line 32) short-circuits on a null environment
  before calling `present()`. This lib apparently never had the bug in
  this exact spot (or it was fixed silently in an earlier, undocumented
  pass) — no fix needed, verified by direct reading of the current
  source.

No code changes were needed for either the re-verification pass or the
standard checklist — everything already holds.

### 3. Native boot + connect (light-path live check)

Booted `build-debug` driver from `libs/nitan170911` directly (not
inside a lib-specific working directory quirk — `config.fluffos`'s
`mudlib directory` is absolute). Boot log: clean, only routine
`Unknown #pragma`/`Unused local variable` warnings, ending in
`Accepting telnet connections on 127.0.0.1:40018.` /
`Initializations complete.`

Connected via `scripts/tmux_mud.sh`: banner renders correctly (ANSI art,
UTF-8 Chinese glyphs, uptime/registered-count lines), username prompt
validates length/alphabetic correctly. Attempted the standard project
admin id (`fluffos`, wizlist-seeded, `Mud@2026`) — this time it also hit
the documented MySQL-unavailable rejection ("对不起，由于连接不上数据
库所在服务器…") and disconnected, **not just the password prompt**.
Traced why: `logind.lpc`'s `logon()` (~line 502) runs
`DATABASE_D->do_sql("select online, ... from users where id = '"+arg+"'")`
*before* it ever calls `ob->restore()` on the local save file — with no
DB reachable, `do_sql()` returns non-array, `flag` stays 0, so the
"restore from local save, prompt for password" branch (lines 539-556)
is skipped entirely regardless of whether a local `.o` save exists
(confirmed `data/login/f/fluffos.o` and `data/user/f/fluffos.o` both do
exist on disk), and every login falls straight through to the same
`query_db_status()` gate as a brand-new registration. This is not a
new bug — it's the general case of exactly what the §7.78 follow-up
section above already documented for `qinfeng` specifically
("连 `qinfeng` 这样已有本地存档的老角色登录也会先走
`DATABASE_D->query_db_status()` 检查"); this pass empirically confirms
it also applies to the wizlist-admin id, i.e. **every** login on this
lib is unconditionally gated on DB reachability once `DB_SAVE` is
defined, with no local-save fallback path at all. Consequence for this
pass: the standard checklist's "verify admin wizlist access via
`update`" step could not be exercised live in this environment (it
requires getting past login, which requires MySQL) — documented here
rather than skipped silently.

`log/debug.log` grew from 212 to 818 lines across the session; the new
818-212=606 lines are exclusively compile-time warnings from lazily-
loaded files pulled in while attempting `make_body()`/board inherits
during the login attempt (`Unused local variable`, `Unknown #pragma`,
`Macro redefined` etc.) — zero errors, zero `FATAL`, zero "Bad
argument"/"Undefined function" lines (checked via grep on the new
lines specifically).

Driver killed by exact PID (`kill 1644111`, confirmed dead via `ps`),
never `pkill -f`. `git status --short libs/nitan170911/` after the
session showed **zero changes** — no save-timestamp churn at all (the
login attempt never got far enough to write anything), so nothing to
revert.

### Net result

No new bugs found or fixed this round. Every previously-documented fix
independently re-verified present and correct in the current source;
every standard-checklist item checked and already clean/correct. The
one substantive new finding is diagnostic, not a bug: this lib's login
path (not just registration) is unconditionally DB-gated with no
local-save fallback, confirmed for the wizlist-seeded admin account as
well as `qinfeng` — a real, permanent architectural fact about this lib
worth knowing for any future pass that has real MySQL access and wants
to do a full live playthrough re-test (which remains the recommended
higher-value follow-up whenever Docker/MySQL becomes available in this
environment).

## AGENTS.md §7.100 修复（2026-08-19）

同族（`hhsj`/`xfbhh`）共享的 `ROOM` 基类冗余
`replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md §7.100）：本 lib
作为该血统的最初母本，4976 个房间文件的 `create()` 末尾同样都有这
一行多余调用，同款地雷也烤进了自带建房工具
`clone/misc/roommaker.lpc` 的字符串拼接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4977
files changed, 1 insertion(+), 4979 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40018 正常监听，
`debug.log` 全程干净。由于本 lib 没有预置管理员账号（注册流程依赖
外部 MySQL，见上文"管理员账号"一节），无法像 hhsj/xfbhh 那样做房间
`goto` 走访回归验证——改为连通性验证：连线后输入英文名，确认原有
"由于连接不上数据库所在服务器，目前仙剑奇侠传暂时不接受数据漫游或
新玩家注册" 降级提示依旧正常触发（说明登录流程本身没有被这次修改
破坏），全程 `debug.log` 无新增错误。按精确 PID 结束驱动，因未能注
册无存档增量需要还原。

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果：simul_efun
shim 里 `ob` 缺省为 `this_object()`，但这是在 simul_efun 内部求值，
指向的是 simul_efun 对象自身而非真正调用者，写入垃圾去处、静默丢
失。3 参及以上调用（显式传 `ob`）从调用点求值，本就正确不受影响。
方法论、脚本、"定义 vs 调用"判别修法详见同源 `xfbhh` NOTES.md 对应
小节（同一 `fix_addn2.py`）。作为该血统最初母本，本 lib 未发现
`clone/user/user.lpc` 命名笔误覆盖（正确命名为 `add`）；只有
`clone/user/baby.lpc` 一处本地覆盖（覆盖 `addn` 未覆盖
`addn_temp`），排除其 8 处 `addn(...)` 调用。

结果：842 处改写，`git diff --stat`：429 files changed, 842
insertions(+), 842 deletions(-)，加上排除的 8 处，842+8=850，与调
查阶段统计精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40018 正常监听，`debug.
log` 全程干净，无新增编译错误。因本 lib 注册流程依赖外部 MySQL（见
上文"管理员账号"一节，环境中无 MySQL/MariaDB），无法做完整注册验
证——改为与 §7.100 修复同款的连通性验证：连线后输入英文名，确认原
有"由于连接不上数据库所在服务器…"降级提示依旧正常触发，说明登录流
程本身未被这次改动破坏；全程 `debug.log` 无新增错误。按精确 PID 结
束驱动。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 6 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-04，shop + 拜师）

Live native pass on port **40018** (`build-debug`). Prior notes treated
MySQL as a hard login gate and never completed a shop purchase or a
recruiting `bai`. This environment still has no MySQL; the bugs below
are what made local `TX_SAVE` playable anyway.

First send is the id **`fluffos`** (not `gb` — sending `gb` hits
`pass_id`). Password `Mud@2026`. No `wizpwd` yet: login prints the
“请登陆后用 wizpwd 命令设置” warning, then the ordinary password
prompt. After MOTD there is a 3-second “请输入任意键继续” splash —
early game commands are eaten if sent before it. Lands in
`/d/wizard/wizard_room`. `clone` is `is_admin()` locked (`lonely` /
`admin_flag==21`) — design; `giveall /clone/money/gold` works because
`valid_grant("(admin)")` is enough.

Wizards skip the born startroom, so birth is `goto /d/register/regroom`
→ `register player@me.com` (moves to `/d/register/entry`) → `choose 1`
→ `washto 20 20 20 20`. In this tree `washto` already sets `born` to
`古村`, saves, and moves to `/d/newbie/shijiezhishu`; a follow-up
`born 扬州人氏` is then just `什么？` (wrong room), not a pager miss.

**Bugs fixed**

1. `adm/daemons/logind.lpc` `get_id()`: when `DATABASE_D->query_db_status()`
   is false, `do_sql()` cannot tell “id exists” from “db unreachable”,
   so even an archived `login.o` was dumped into the “暂时不接受数据漫游
   或新玩家注册” gate. Fall back to `file_size(login.o)` like the
   non-`DB_SAVE` path (LF).
2. `clone/user/login.lpc` `restore()`: `#ifdef DB_SAVE` used to restore
   only from MySQL; a miss never called `::restore()`. Now a MySQL miss
   / unreachable still honors the local `login.o` when `TX_SAVE` is on.
3. `clone/user/user.lpc` `restore()`: `db_restore_all()` returns **-1**
   when MySQL is down. LPC treats `-1` as truthy, so a `if (!res)` (or
   the original `if (query_temp("restore_mysql"))` only) skip of the
   `TX_SAVE` fallback left a blank body. A later `save()` then clobbered
   the on-disk `user.o` (this is why an in-session 拜师 vanished across
   reboot before the fix). Treat `res < 1` as a miss and call
   `::restore()`. Also skip `db_restore_all()` entirely when
   `query_db_status()` is false.
4. `feature/dealer.lpc` `init_goods()`: mixin `query("vendor_goods")`
   resolved to simul_efun dbase (this file does **not** `#include
   <dbase.h>` — same §15 shape as `xfbhh`). `this_object()->query` so
   醉仙楼 `list`/`buy` see the 店小二货表.
5. Huashan `yue-buqun`/`yue-wife`/`feng-buping` plus `qingcheng/yu.lpc`:
   `apprentice_availavble` typo (extra “av”) so the daily recruit
   counter never decremented. LF, same as `nitan3` this slice.

**Shop**: `/d/city/zuixianlou` 店小二 (`d/city/npc/xiaoer2.lpc`). `list`
shows 烤鸡腿 80文. `buy jitui` paid 1 gold → 99 两白银 + 20 文 and
delivered 烤鸡腿. No `F_DEALER` 丐帮 refuse on this dealer.

**拜师**: `goto /d/city/lichunyuan`, `bai kong` on 空空儿 — accepted
(“恭喜您成为丐帮的第二十代弟子.”). `score` shows 【门派】丐帮 /
【师承】空空儿. `cmds/usr/save.lpc` has a 30s cooldown. After `save` +
driver kill + reboot, relogin still shows 丐帮 / 空空儿; silver/coin
change persisted. 烤鸡腿 was also in inventory after reboot (not listed
in `autoload`; food often is not — here it came back anyway). Do not
`quit` this account to test persistence when `mud_age` is still tiny.

`log/debug.log` Boot Time for the persist-check boot matches that run;
no `Error:` / `Wrong permissions` / eval-cost lines. Mudlib
`work/log/debug.log` and `work/log/log` (`error_handler` /
`log_error`) likewise had no execution-time errors on that boot.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply nitan170911`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 3 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 3 PASS, 0 that loaded before fail now, 1 more load.

1 files moved (1 `.C`); mostly under `u/gigi/swing.C` (1). A rescan with `scripts/lpc_warnings.py nitan170911` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理、使命任务、`.lpc` 切片

`scripts/lpc_warnings.py nitan170911 --fix`（分块扫描，见下）加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1990 个 `.lpc` 和 51 个 `.h`（多为删去未用的局部变量）。验证（分块加载，新进程）：改动的 1990 个文件里两边都有结果的 1399 个 HEAD 1346 -> 工作树 1930 通过、无回退，其余 7 个工作树失败的文件单独在 HEAD 加载同样失败；改过的头文件的 9323 个包含者 3439 -> 3439 通过。启动时警告 11 -> 0。
扫描工具问题：一次 `lpcc --batch` 加载全部约 5.5 万个文件时，在 `adm/daemons/taskd` 内存耗尽，进程死掉，扫描只看到 312 个文件却显得很干净；`lpc_warnings.py` 现在分块并跳过把进程弄死的文件继续。
手改（同 nitan6 一系）：`adm/kernel/master.lpc` `direct_run_binary()` 的 `ob`、`vob` 挪进 `#else`；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去；`d/city/task2/shashou.lpc` 的 `jap_name()`（KB 06 §7.237）。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒（KB 06 §7.238），`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽、不断载入房间直到内存耗尽——`taskd` 从来加载不起来，玩家的 `task`、`locate` 指令失效。改正切片和列表（列表空了就停），`maximum evaluation cost` 提到 10000000（真正走房间后首次冷加载要几秒）；改后单独加载 `taskd` 无错误。本库注册新人物需要 MySQL（见上文），本机没有，未能现场跑 `task`；同样的修正在 nitan6 现场验证过（HEAD 两个指令都只显示“这里发现了臭虫”，修正后正常）。另：`scripts/lpc_lpc_suffix_slice.py` 在本库改了 9 处 `.lpc` 定宽切片。
本地 `data/dbased.o`（23MB，.gitignore 有意不收）格式损坏，`restore_object` 报 `Illegal mapping format`；不随游戏发布，只影响本机测试。

- 2026-10-10：`/kungfu/skill/sad-strike/tuo.lpc`、`/kungfu/skill/taiji-jian/jian.lpc`、`/u/mud/skills/wudang/jian.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 61 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 11 个，只在 #if 分支用的声明移进分支 3 个文件；改动 75 个文件，HEAD 与工作树各载入一次无回退（75 objects; HEAD PASS 75, tree PASS 75; regress 0; newly loading 0），这些文件的警告 99 -> 19。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- `d/death/qiao1.lpc`：`if (dir == "north") { /* … */ }` 只剩注释的空块，把 `if` 一起挪进注释（行为不变）。
- `kungfu/skill/miaojia-jian/gan.lpc`、`zhai.lpc`：`string name() { HIY "…" NOR; }` 少了 `return`，招式名为 0；补 `return`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：adm/daemons/mysql_d.lpc u/gigi/test/gigicook.lpc u/lonely/combatd.lpc u/redl/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **11991 -> 0**（`lpc_warnings.py` 全库重扫：48355 个文件可编译，剩下 16 条警告都在本来就编译不过的文件里，如 `feature/dealer1.lpc`、`clone/pharmacy/herb/herb.lpc`、`realnews_d.lpc`）。改动的 162 个对象加上 5900 余个抽样对象（`clone/`、`d/city`、`d/xiangyang`、`d/yixing`、`feature/`、`inherit/`、`adm/daemons/`、800 件玩家自制道具）HEAD 与工作树各载入一次：`6086 objects; HEAD PASS 5995, tree PASS 5995; regress 0; newly loading 0`。删除声明审计 0 处待看。

**严重问题一：F_DBASE 旁边的混入件读写的是 simul_efun 的共享 dbase（§7.15 的残留）。** `feature/equip.lpc`、`itemmake.lpc`、`food.lpc`、`liquid.lpc`、`pill.lpc`、`alias.lpc`、`message.lpc`、`name.lpc`、`damage.lpc`、`dealer.lpc`、`banker.lpc`、`guarder.lpc`、`apprentice.lpc`、`unique.lpc`、`control.lpc`、`inherit/char/master.lpc` 都不继承 F_DBASE，自己也没有 `query` 原型，于是裸 `query("x")`/`set("x", v)` 编译成 simul_efun 的后备函数，在 simul_efun 物件里执行，读写的是所有人共用的那一个 dbase。探针（新进程）证实：修正前给 NPC `wield` 长剑，提示照常出现，但 `query_temp("weapon")` 仍是 0、`equipped` 从没写进兵器，`is_equipping()` 恒为 0，`wear` 也一样；自制道具的 `query_autoload()` 不管穿没穿都返回 `"kept"`，`is_weapon()` 恒为 0；食物的剩余份数、店铺货表、`alias` 的命令延迟、`message` 的频道屏蔽都不读自己的属性。修正：`include/dbase.h` 补上与 `feature/dbase.lpc` 完全一致的 `set/query/delete/set_temp/query_temp/delete_temp/add/add_temp` 原型（nitan_san 的 dbase.h 一直有），上面这些混入件都 `#include <dbase.h>`；`adm/daemons/npcsd.lpc` 与 `cmds/adm/eval.lpc` 本身不是 dbase 物件、只用带物件参数的写法，去掉它们的 `#include <dbase.h>`（否则调用一个没有定义的原型会出错）。修正后探针：`wield` 后 `weapon` 指向长剑、`equipped == "wielded"`，`wear` 写入 `armor`，自制道具 `query_autoload()` 返回 `"wielded"`/`"worn"`、`is_weapon()` 为 1。本机原生启动（端口 40018）用 fluffos 登入实测：`list`/`buy jitui`/`eat jitui`（份数 4 -> 3）/`wield`/`unwield`/`wear`（物品栏出现装备标记 □）/`remove`/`alias` 都正常，`log/debug.log` 无新错误。测试后把 fluffos 的三个存档还原。
- 同一处：`inherit/char/master.lpc` 开除弟子时 `if (query("skill_expell_penalty_tsl"), me)` 是逗号表达式，恒为真，所以从不按上限削减内力/精力；改为 `query("skill_expell_penalty_tsl", me)`（持青石令者免削）。

**自制道具的 autoload（11726 条 `inherited from both` 警告的根源）。** 每件玩家自制道具都是 `inherit 兵器/防具基类; inherit F_ITEMMAKE;`，`/inherit/item/item.lpc`（或 `combined.lpc`）和 `/feature/itemmake.lpc` 各有一对真实的 `query_autoload()`/`autoload()`：item 的把整个 dbase 存进 autoload 字串，itemmake 的只记 `worn`/`wielded`（道具本身由 F_OBSAVE 存盘），驱动选的是后继承的 itemmake。两边都不是空桩（§7.239），itemmake 的才对。没有改 5843 个叶子：itemmake 的这对改名为 `query_itemmake_autoload()`/`itemmake_autoload()`，`item.lpc` 与 `combined.lpc` 的 `query_autoload()`/`autoload()` 先看 `function_exists("query_itemmake_autoload", this_object())`，有就交给它。探针（u/mud 下临时文件，已删）：STAFF、HANDS、THROWING 三种基类各配 F_ITEMMAKE，修正前后 `query_autoload()`/`autoload()` 走的都是 itemmake 的逻辑（数量、名称不变），普通长剑、铁莲子（combined）的结果逐字相同。另外 42 件以 XSWORD 为基类的自制箫剑，`is_weapon()` XSWORD 与 itemmake 都有定义、在这些道具上都是 1（都调用了 `init_xsword()`），在叶子里写 `int is_weapon() { return 1; }`。

**其他：**
- 幻境 `fairyland_quest` 的四个国度 NPC/宝物和 `room_readygo_hj.lpc`：`string a, b, ..., a = "...", b = "...";` 把每个变量声明了两次（原档如此），去掉前面那串不带初值的。
- `template/gem/*.lpc`、`template/weapon/*.lpc` 自己又声明了基类 `/inherit/misc/template` 的 `dbase_format` 等变量，再传给 `set_*()`；改名为 `my_*`，行为不变。
- `clone/misc/swmuding.lpc`（神木王鼎）重新声明了木鼎的 `insects` 表，木鼎的代码读的是自己那份，所以神木王鼎的虫表从没生效；改名 `sw_insects`，在 `create()` 里赋给 `insects`。
- `d/city/npc/oldman.lpc` 的宠物体重表 `weight` 与 F_MOVE 的同名变量重名，改名 `pet_weights`；`maze/forest/maze.lpc` 的 `unique_rooms` 改名 `forest_unique_rooms`。
- `d/yixing/doc/info_store.h`、`info_biao.h`、`info_guest.h`：帮主 `bangzhu.lpc` 直接包含一次，又经 `bangzhu_duty.h` -> `guanjia.h` 再包含一次，加头文件守卫。`include/eve.h` 的 `elements` 由 `/d/war/diablo.lpc` 提供（两个包含者都继承它），删去。
- `include/boss_bad.h`/`boss_good.h` 的 `WAIT_TIME 120` 改成 `#ifndef` 默认值：包含它的 35 个任务 NPC 都先 `#define WAIT_TIME 60  // 完成不了任务的反省时间`，原来被头文件覆盖成 120，现在用各自的 60。
- `adm/npc/obj/xiang.lpc` 的 `varargs int remove() { save(); }` 盖掉了 F_MOVE 的 `remove()`（减负重、清 handing）；改为先存盘再 `::remove(euid)`。
- 返回类型与基类不符：`close_gate()`（4 个房间）、`attempt_apprentice()`（4 个 NPC）、`die()`、`heart_beat()`（u/redl 十个茶虫）、`init()` 改成 `void`（调用方都不用返回值）；`feature/food.lpc`、`liquid.lpc` 的 `do_effect()` 改成 `varargs int do_effect(object me)` 并返回 1——`drink`/`eat` 对 `only_do_effect` 物品把返回值当命令结果，两个重载它的物品本来就是 int。
- 宏重定义加 `#undef`：`invent.lpc` 的三个 SKILL_MODEL、`ultra_questd.lpc` 的 QUEST、`meng-zhu.lpc` 的 MENGZHU、`tianshen.lpc`/`u/lonely/skybook/xiaoaojianghu.lpc` 的 FUBEN_D（指向不存在的 `fuben_daemonsd`，保持原样）、`u/lonely/canhezhi.lpc` 的 BOOK_DIR；`channeld.lpc` 不再定义没用到的 `GWIZ`。
- `combatd.lpc`（含 u/ 下两个副本）：只在 `#ifdef USE_SKILLS_COMBAT`/`USE_SKILLS_SPECIAL` 里用的 `def`、`armor` 声明挪进对应分支；`genmap.lpc` 的 `find_exits()` 里包含了用不到的 `harbor.h`，删去。
- toolkit 删去 40 个重复继承（`lingpai*`、任务 NPC 再继承 F_CLEAN_UP，`smith.lpc` 再继承 F_DEALER，几个技能再继承 F_SSERVER 等）。
- 旁注（未改）：登入时 `newsd` 经 `dboard.lpc` 调用 `DATABASE_D->connect_to_database()`，该函数是 `protected`，`debug.log` 报 `apply() with insufficient permission`，只在没有 MySQL 时出现，结果与连不上一样。

## 深度功能测试（§10.7，2026-10-12）：KB 05 §7.15 残留收尾（feature/save.lpc）

- 复查当天早些时候 dbase.h 原型一轮漏掉的混入件。`feature/action.lpc`、`condition.lpc`、`move.lpc` 在本库里**没有问题**：忙乱（`me->query_all_buff("avoid_busy")`）、中毒抗性（`this_object()->query_all_buff("avoid_poison")`）、移动时的 `this_object()->query("equipped")`、`env/brief`、`guardfor` 早就写成 `this_object()->` 或带物件参数的两参形式，没有一处裸单参 `query()`/`set()`（nitan6 的同名文件是裸调用，那里才需要 `#include <dbase.h>`），所以不加包含、不改。
- 真正漏掉的是 `feature/save.lpc`：它也被不带 F_DBASE 的守护进程继承，不能加原型；`restore_package()` 两处 `log_file("restore_package", query("id") + ...)` 是裸单参调用，读的是 simul_efun 的共享 dbase，日志里的玩家 id 恒为 `0`。改为 `this_object()->query("id")`（同 nitan6 提交 3264a2e14e1）。
- 探针（新进程，HEAD 与工作树各一次）：两个店小二，一个设 `apply/avoid_busy`=77、`apply/avoid_poison`=88，另一个读到 0，`start_busy(5)` 正常；长剑 `wield` 后移给另一个 NPC，原持有者 `weapon` 清空、`equipped` 清零——改前改后相同。带 F_DBASE+F_SAVE 的探针物件 `restore_package()` 遇到不存在的物件路径：改前日志 `0:/no/such/probefile`，改后 `probesv:/no/such/probefile`。
- 载入回退检查：继承 F_SAVE 的全部对象加 `clone/`、`d/city`、`feature/`、`inherit/`、`adm/daemons/`、`cmds/` 抽样，`2437 objects; HEAD PASS 2373, tree PASS 2373; regress 0; newly loading 0`（失败的 64 个 HEAD 同样失败），改动文件无编译警告；删除声明审计 0 处。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。21 个文件 26 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/clone/npc/walker.lpc`（`pot *=`）、`/clone/npc/walker.lpc`（`score *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/quest/skybook/flagwar/flagd.lpc`（`reward_money *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 hhsj/nt6 同源同修）：36 个技能文件的 `int power_point()` 返回 0.6–1.4 的浮点（含分支写法），经 int 返回被截断；本库没有调用者，改为 `float`、保留原数值（`scripts/lpc_fix_float_hooks.py`）。当铺售价和 simul_efun `ntefun.lpc` 的 `sqrt` 写明 `to_int()`，simul_efun 能载入。改动的对象载入无回退。

- 2026-10-14：9 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；13 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：21 个对象，新增载入 17，回退 0。

- 2026-10-14：`foreach` 里把 `array` 当类型（`foreach (string type, array data in news)`），本驱动不认；改为 `mixed *`（`scripts/lpc_fix_array_type.py` 现在也处理 foreach 变量）。`adm/daemons/realnews_d.lpc` 还调用本驱动没有的 `to_default_encoding()`，仍不编译。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。34 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。


## 去烦恼指 `qufannao-zhi`（2026-10-15）

该技能 `inherit F_DAMAGE`，其中 `query`/`query_temp` 的成员原型遮住了 simul_efun 的 `query(prop, ob)`，于是 `valid_learn`/`practice_skill` 报 `Undefined function called: query_temp`。改为 `me->query_temp(...)` 等直接调用。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 5 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。


## 摆摊状态的指令路径（2026-10-15）

`kungfu/condition/baitan.lpc` 调用 `/cmds/std/baitan.lpc`，指令实际在 `/cmds/usr/baitan.lpc`。已改正路径；本库摆摊指令用 `start_busy()`，目前没有地方施加这个状态，属于未接线的代码。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`chongling-jian`、`duoluoye-zhi`、`feifeng-bian`、`huashan-zhang`、`murong-jianfa`、`sougu-yingzhua`、`xuedao-daofa`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`busi-shenglong`→`busi-shenlong`（`shenlong-dafa`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`jiemie-zhua`→`jimie-zhua`（`huzhua-claw`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`meiren-shanzhao`→`meiren-sanzhao`（`meiren-sanzhao/fengzi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 乾天一阳「聚精」用了未定义的 MIN（2026-10-15）

`qiantian-yiyang/jujing` 从书剑（sj）移植过来，用到 `MIN(...)`；书剑的 `globals.h` 定义了这个宏，本库没有，文件编译失败。在文件里补一个局部 `#define MIN(x, y)`，现在可以载入。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：临济庄「幽冥桩」每次都报 `Value being indexed is zero`。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## `call_out(0) nest level : 10`（2026-10-15，KB 03 §5.4）

这个值来自驱动测试套件的配置（`testsuite/etc/config.test`）。驱动统计的是同一个 gametick（本库 100 毫秒）里全游戏的 call_out(0) 总数，不是一条链的深度，超过 10 个就报 `Nesting call_out(0) level limit exceeded`：多段绝招（如华山剑法「剑芒」的 `call_out("perform2", 0, ...)`）在人多时会断掉。原版跑在 MudOS 上，没有这个限制；改为驱动默认值 1000。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/temp/login/s/sina.o`、`/temp/login/t/tiyan.o`、`/temp/user/s/sina.o`、`/temp/user/t/tiyan.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。3 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。


## 拜堂时请不来月老（2026-10-15）

苏州媒婆（`d/suzhou/npc/meipo`）和红娘（`adm/npc/hongniang`）拜堂时 `new("/d/suzhou/npc/yuelao")`，本库这个 NPC 放在 `d/ruzhou/npc/yuelao.lpc`（文件头仍写着旧路径，与 nitan3 等库的 `d/suzhou/npc/yuelao.lpc` 逐字节相同）：`new()` 得 0，`moon->move(room)` 报错，婚礼停在拜堂之前。两处都改为 ruzhou 的路径。媒婆从拜堂到送入花轿的整个流程在测试里走通。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

33 个文件、43 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/dali/npc/obj/zipao`、`/d/tls/obj/sengxie`、`/clone/armor/baihu-qiu.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 31 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`S_RING` → `/inherit/gems/ring`（11 个文件）、`F_GEMS` → `/feature/gems`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：15 个里 4 个通过，其余 11 个还有别的错误（`clone/gem/ring.lpc`：Fail to load object /clone/gem/ring.；`clone/gem/ring0.lpc`：Fail to load object /clone/gem/ring0.；`clone/gem/ring1.lpc`：Fail to load object /clone/gem/ring1.……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 62 个对象设了本库没有文件的武功（75 个名字，最多的是 `yijin-jing`、`qingyan-zhang`、`duanjia-jianfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 16 个通过，其余 14 个停在别的错误上（`d/shiliang/quest/npc/wenfangshi`：*No program in object '/d/shiliang/quest/npc/wenfangshi'!；`d/shiliang/quest/npc/wenfangyi`：*No program in object '/d/shiliang/quest/npc/wenfangyi'!……）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/sserver`（宏 `SSERVER`）←shenmo，4 个对象继承它，抽样 1/4 载入；`/feature/ridding`（宏 `F_RIDDING`）←xfbhh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 106 处、45 个文件：`yijin-jing`→`yijinjing`（34 处）、`yunu-xinjing`→`yunv-xinjing`（20 处）、`yunu-shenfa`→`yunv-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（7 处）、`shenzhao-jing`→`shenzhaojing`（6 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`moshen-jianda`→`moshen-jianfa`（3 处）等共 20 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 4 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `BOOK_D(x)`、`CENTER_OB`、`EXIT_SIZE`、`EXIT(n)`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## kedian4 的 mapping ob（2026-10-19，KB 06 §7.266）

`d/city/kedian4.lpc` 的 `give_cigarette()` 把循环变量 `ob` 声明成了 `mapping`，却拿它当物件传给 `query("online_time", ob)`，驱动报 `Bad type for argument 2 of query ( object vs mapping )`，整个房间载入不了。改成 `object ob;`。

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/kernel/simul_efun/object.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 丢失的 ARMOR_D(x)、BINGQI_D(x)（2026-10-19，KB 04 §6.16）

`include/globals.h` 没有 `ARMOR_D(x)`（`("/clone/armor/" + x)`）和 `BINGQI_D(x)`（`("/clone/weapon/" + x)`），用它们的 NPC 报 `Undefined function ARMOR_D` / `BINGQI_D`，载入不了。照同一系 19 个库里相同的定义补上（`scripts/lpc_restore_defines.py`）。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `maze/yanmen/npc/horse.lpc`：`inherit NPC; inherit F_RIDDING;`，NPC 一路带来 `feature/equip_liv.lpc` 的 `unequip(object ob, int ref status)`，`feature/ridding.lpc` 也有 `unequip()`（`unequip() inherited from both …`），驱动用了后继承的 ridding 那个；写出 `int unequip() { return ridding::unequip(); }`，行为不变（`scripts/lpc_name_winner.py`）。

逐个与 HEAD 对比载入，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/adm/daemons/ward.lpc`（1 处）、`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）、`/inherit/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 29 处）。改动：`/adm/daemons/combatd.lpc`（5 处）、`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/intermud2_d.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/clone/game/mj.lpc`（3 处）、`/clone/game/mjlady3.lpc`（3 处）、`/cmds/wiz/roomlong.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/jiaxing/npc/yang.lpc`（1 处）、`/d/yaowang/huichun/npc/zhanggui.lpc`（1 处）、`/kungfu/class/misc/houwang.lpc`（2 处） 等 15 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/kernel/simul_efun/object.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/battlefieldd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/kernel/importer.lpc`（1 处）、`/cmds/adm/refsum.lpc`（5 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/cmds/arch/config.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## `semote` 编译不过：函数指针里用了局部变量（2026-10-20，KB 06 §7.284）

`emotions = sort_array(emotions, (: emotion_sort[$1] > emotion_sort[$2] ? -1 : 1 :));`（`#else` 分支，因为 `__PACKAGE_ARITH_OPERATOR__` 在这个驱动里没有）里 `emotion_sort` 是局部变量：`Illegal to use local variable in functional`。按驱动的写法用 `$(emotion_sort)` 捕获。加载检查：HEAD FAIL → tree PASS。

## `mroom`（帮会房间生成）读不到 `dir_pre`（2026-10-21，KB 04 §6.16）

`cmds/bunch/mroom.lpc` 的 `valid_room_position()` 和建房流程用 `dir_pre` 当帮会目录前缀，库里没有任何头文件或变量声明它（`include/bunch.h` 只剩 `room_desc_l`、`max_exits`、`r_dir`、`vdirs`，整个语料里也没有 `dir_pre` 的定义），整个命令编译失败：`Undefined variable 'dir_pre'`。`adm/daemons/bunchd.lpc` 里 `BUNCH_HOME "/data/bunch/"`（`BUNCH_HOME + id + "/center.lpc"`，模板目录 `/d/room/bunch/` 复制到那里）和 `valid_room_position()` 的路径算术（前缀 `explode()` 三段、房间路径五段，差 2，返回第四段即帮会 id）对得上，所以在 `mroom.lpc` 里加 `#define dir_pre "/data/bunch/"`。nt6、nitan170911、nitan6、hhsj、xfbhh 的 `mroom.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：nt7（gitlink）同一文件；tianxia 的 `cmds/bangzhu/mroom.lpc` 用的是 `BANGHUI_DIR`，但那里的 `banghui_d` 自己就有类型错误和未声明的变量加载不了。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 2 个 NPC 文件写成空 `chat_msg`（例如 `/d/city/npc/lulixian.lpc`、`/maze/sand_dragon/npc/sand_dragon.lpc`），它们走的基类 `chat()` 本来已经检查了列表大小（或碰巧不出错），不受影响；下面这些文件各自带着一份没有检查的 `chat()`（NPC 里的副本、旧版基类），一并加上守卫。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/u/lonely/skybook/skybooknpc.lpc`、`/u/lonely/skybook14/skybooknpc.lpc`（共 2 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 15 个存档共 31 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/bunchd.o`（13 处）、`/data/gaoshou/npc/blue.o`（1 处）、`/data/gaoshou/npc/blue_xr.o`（1 处）、`/data/gaoshou/npc/cwz.o`（1 处）（等共 15 个存档）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。
