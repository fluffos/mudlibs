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
