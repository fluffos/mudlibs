# KB 05 — Boot-time and runtime crash classes, part 1 (§7.1–§7.60)

Format: symptom → cause → fix → detection. Instance lists were trimmed;
see `docs/agents-catalog-full.md` and each lib's `NOTES.md`.

### 7.1 Master's lazy security-daemon load recurses
**Symptom:** a segfault, or a permanently empty `wiz_status` with no
visible error.
**Cause:** `valid_read`/`valid_write` call `load_object(SECURITY_D)`
mid-compile, so the error path re-enters `valid_read` forever. A guard
based on `previous_object()` doesn't help.
**Fix:** a re-entrancy flag plus `catch`, degrading to allow:
```lpc
private nosave int loading_security_d;
int valid_read(string file, mixed user, string func) {
    if (!find_object(SECURITY_D)) {
        if (loading_security_d) return 1;
        loading_security_d = 1; catch(load_object(SECURITY_D)); loading_security_d = 0;
        if (!find_object(SECURITY_D)) return 1;
    }
    return (int)SECURITY_D->valid_read(file, user, func);
}
```

### 7.2 Missing `get_root_uid()` / `get_bb_uid()`
**Symptom:** the driver calls `exit(-1)` during boot.
**Cause:** `PACKAGE_UIDS` requires both applies.
**Fix:** add stubs returning the lib's uid constants.
**Note:** `creator_file()` is required too (§7.175).

### 7.3 `create()` destructs SIMUL_EFUN_OB
**Symptom:** a C-level segfault during bootstrap.
**Fix:** delete the force-reload trick from master's `create()`.

### 7.4 `this_player()` overrides the ACL caller identity
**Symptom:** privileged lazy loads are denied whenever any player is
mid-login.
**Fix:**
`if (this_player() && !geteuid(user) && !getuid(user)) user = this_player();`
**Note:** also exclude compile funcs (§7.59).

### 7.5 Custom ACLs must allowlist the driver's own func strings
**Symptom:** "Read access denied" on every lazy compile. Variants:
- A silent false `file_size()` result: `F_SKILL: No such skill` the
  first time each skill loads.
- A silently empty `get_dir()` (`func=="stat"`): every command answers
  "什么？".

**Cause:** the driver routes `load_object`, `recompile_object`,
`include`, `file_size`, and `stat` through `valid_read`, and the custom
ACL denies objects that have no euid yet.

**Fix:** add this to `valid_read`, before the euid check:
```lpc
switch (func) { case "load_object": case "recompile_object": case "include":
                case "file_size": case "stat": return 1; }
```
Add a `switch` if the ACL doesn't already have one (`hy5`).

**Detection:** when every command fails identically and §8.3a/b are
clean, grep the driver source for the func string the efun actually
passes. Affects the hy/海洋 family (`hy`, `hy2000`, `hy2002`, `hy5`) and
custom securityd libs.

### 7.6 DNS/intermud daemons
**Policy:** remove them from preload before the first boot.
**Then guard:**
- Inline callers (`Mud_name()`, mudlist displays).
- Site-verification gates that call `shutdown(1)` when the daemon is
  absent: guard with `find_object(DNS_MASTER)`, absent means skip.

Always boot and connect afterwards to confirm.

### 7.7 Unguarded `restore()` / corrupted saves
**Symptoms:**
- A crash in a daemon's `create()` that looks like an intentional
  "syncing" banner.
- A daemon left half-initialized.
- `restore_object(file)` without flag 1 ZEROES globals missing from the
  file. Guard defaults after restoring:
  `if (!pointerp(x)) x = allocate(10);`.

**Corruption sources seen:**
- Legacy binary `#inh` saves.
- Unconverted GBK.
- Unguarded `move()`/`restore()` in a board's `setup()`.

**Fix:**
- Corpus-wide: guard the shared `feature/name.lpc` crash site with
  `(stringp(query("id")) ? capitalize(query("id")) : "?")` (154 libs,
  done).
- Per-lib: wrap the board's `move`/`restore` in `catch`.

### 7.8 Case-sensitive data-file paths
**Symptom:** `read_file("/adm/single/MUDVISITOR")` returns 0 when the
file on disk is lowercase. If that path runs in `logon()`, every
connection dies with an empty transcript.
**Fix:** `find -iname` and correct the path.

### 7.9 `sscanf(read_file(...))` / `write(read_file(...))` crash bombs
**Cause:** counter and banner files are runtime data, gitignored or
absent in a fresh checkout. `read_file()` returns 0, and the
`sscanf`/`write` on it crashes, killing logins (every connection, or the
first one).
**Fix:** `string s = read_file(f); if (stringp(s)) ...`. Guard every
`write(read_file(...))` that runs before the room-move in
`enter_world()`. A missing MOTD otherwise strands the character with no
environment.
**Note:** when a guard yields an EMPTY collection (`day_phase`), install
a minimal one-entry fallback. Otherwise downstream indexing or modulo by
zero crashes.
**Detection:** `grep -rn "sscanf(read_file\|write(read_file"`.

### 7.10 `log_error()` receives warnings too
- **Gating a broadcast on severity:** match `"arning:"`, without the
  leading W. The driver has flip-flopped between "Warning:" and
  "warning:".
- **ACL calls:** `log_error()` calling `wizardp()` or anything that
  loads securityd can fire on the first preload compile. Guard it with
  `find_object`.
- **`error_handler()` is a `void` apply.** Add a cheap
  `efun::write_file("/log/RUNTIME_ERRORS", trace)`. A `CHANNEL_D` call
  inside the handler must be `find_object`-guarded.

### 7.11 Missing runtime directories → write_file aborts
**Symptom:** an uncaught `write_file`/`log_file` into a dir that was
never shipped (`/log/nosave/`, `/data/topten/`, `/topten/`) aborts the
rest of the caller. The error often lands only in the lib's own custom
log.
**Common blast sites:**
- Registration (`get_gender` → `log_login`).
- `enter_world` (anomaly-detection `log_file("nosave/WARNING")` fires
  for nearly every fresh character).
- `combatd::killer_reward()` (death loops forever, or PvP state is left
  stale).
- `toptend::topten_save()`. Overwrite-mode `write_file(f,s,1)` THROWS
  rather than returning 0.
- The admin `call` audit log, which runs before the call itself.
- The `suicide` account-delete path.

**Fix:** fix the shared wrapper itself, in `adm/simul_efun/file.lpc`:
```lpc
void assure_file(string file);          // forward decl: it is defined later in the file
nosave int in_log_file;
void log_file(string file, string text) {
    if (!in_log_file) { in_log_file = 1; assure_file(LOG_DIR + file); in_log_file = 0; }
    write_file(LOG_DIR + file, text);
}
```
- The re-entrancy flag matters: hy/ocean `securd` denial paths call
  `log_file()` themselves, which recurses into "Too deep recursion"
  (`fqyy2`).
- An `#include`-built simul_efun can't be hot-`update`d. Restart the
  driver.
- `get_dir()` on a missing dir returns 0, and a bare `foreach` over it
  throws mid-init, which can leave a later global unset
  (`revivalworld`'s `city_d`).
- **Git doesn't track empty dirs:** add `.gitkeep` files or mkdir in
  code. `.gitignore`d log trees never survive a fresh clone, so assure
  them in code.

**Detection:** grep `log_file(` and `write_file(` in each lib's
simul_efun and in the daemons that run on common player actions. The
pairing "`log_file()` sits two functions above its own unused
`assure_file()`" is near-universal.

### 7.12 Shared message-wrapper argument bugs
**Symptom:** `Bad argument 4 to message()`.
**Cause:** a 2-arg `tell_room()` (or a 3-arg `message()`) forwards an
omitted `exclude` as int 0.
**Fix:** fix the wrapper:
```lpc
varargs void tell_room(mixed ob, string str, object *exclude) {
    if (!ob) return;
    if (exclude) efun::message("tell_room", str, ob, exclude);
    else efun::message("tell_room", str, ob);
}
```
**Gotchas:**
- Inside the simul_efun file itself, a bare `message(...)` binds to the
  hard efun, not to the same file's guarded override. Use `efun::` with
  the guard in `tell_room`, `shout`, and `message_system` (`zhyx`).
  Verify with `eval tell_room(room,"x")`.
- **Severity:** when this fires from a `call_out` (the net-dead
  `user_dump`), it aborts the force-quit safety net, and a native
  double-free crash was observed (`dtsl`).

Related: §7.61, §7.88, §7.129, §7.165.

### 7.13 Booby traps
**Symptom:** a `securityd`-like function with a mass-delete or
`shutdown` body, gated on a license or date (a year-2109 bomb was seen
on `fy2005`).
**Fix:** neutralize the body but keep the function.
**Detection:** grep `rm(`, `unlink`, and `shutdown` in non-admin code.

### 7.14 Assorted runtime traps
- **`file_size()` is -1 or -2 (both truthy) for missing files and
  dirs.** Test `>= 0`.
- **`crypt(str, 0)` uses a fresh random salt per call.** A
  challenge/response handshake can never pass. Use an explicit salt
  (`zjdyzj`).
- **Factories return 0 on missing content.** Guard
  `X->create()->move()` chains (§7.147).
- **Unguarded `environment(me)` in quit/command paths.** 风云 family:
  port the guard to every sibling.
- **A post-registration move to a missing room** leaves the player with
  no environment; it looks like the §8.3 symptom. Use
  `load_object` with a `START_ROOM` fallback.
- **Missing zone content is an archive gap.** Document it; don't
  fabricate rooms.
- **`__FILE__` inside an `#include`d fragment** names the fragment. Use
  `file_name(this_object())` for the includer, or `base_name()` when the
  intent is the master copy (`es1`'s `compress_obj.h`).
- **`check_config`-style self-checks built on stale `#ifdef`
  assumptions:** disable only the failing checks.
- **One non-fatal versiond `socket_bind` line** may be harmless. Read
  the code before chasing it.
- **`users()` returning `({})` is truthy**, so `u[random(sizeof(u))]`
  goes out of bounds. Guard with `sizeof`.

### 7.15 The nitan `set`/`query`/`dbase` architecture bug
**Cause:** NT/nitan-lineage property storage uses bare simul_efun
`set`/`query`/`delete`. Inside a simul_efun, `this_object()` is the
simul_efun object, so every object without a local override shares one
property bag.
**Fix:**
1. Give `feature/dbase.lpc` real local
   `set`/`query`/`delete`/`*_temp`/`add`. A 3-arg call with a different
   `ob` redirects via `ob->set(...)`.
2. Keep a simul_efun fallback for non-F_DBASE objects.
3. Partial overrides fall through via `::set()`, never via the
   simul_efun (that recurses).
4. Then `efun::set/query/delete` won't compile. Use `::set`.
   `addn` is simul_efun-only: use `ob->add(...)`, or `::add` if it was a
   typo.

**Scope:** `nitan170911`, `nitan6`, `nt6`, `nt6nitan6win`.
`nitan_ceshi` and `nitan_san` predate the bug.
**Warning:** don't trust a comment claiming the fix is in place. Grep
for the actual function signatures. Companion bugs: §7.78, §7.79.

### 7.16 Stale shipped timestamps feed an unbounded catch-up loop
**Symptom:** `while (rank["time"] + 3600 < t) {...decay...}` over
2008-era data runs about 157k iterations, hits "Too long evaluation",
and crashes on every `quit` (silent to the player: `bxsj`).
**Fix:** cap the iterations, then jump the timestamp to `t`.
**Detection:** grep `while.*\["time"\].*<` across the whole lib. Grep
`debug.log` after `quit`, not just after login.

### 7.17 `init()`/`reset()` re-entrancy on a room's first-ever visit
**Symptom:** "Too deep recursion" with a stray `0` in an NPC's title.
The blamed line moves around between runs.
**Cause:** `reset()` is double-fired during the first compile. Duplicate
NPCs self-locate their room by force-loading it, which re-enters the
compile.
**Fix:**
- A `nosave int resetting_now` guard in room `reset()`.
- A `nosave` guard in the NPC `init()`.
- Prefer `environment(this_object())` over force-loading.

**Note:** raising `maximum call depth` does nothing (it's a compile-time
constant).

### 7.18 A room path left stale after the original game replaced its own zone
**Symptom:** `REVIVE_ROOM` points into a zone that was rewritten, while
the old zone survives under `*_bak/`. Every death strands the player.
**Fix:** repoint to an always-loadable fallback (`START_ROOM`). Don't
resurrect the old zone.
**Detection:** check every room `#define` in `include/login.h` against
live-map files. Also seen: zone renames leaving stale exits or boards
(`fy2`'s `/d/wiz` → `/d/waterfog`).

### 7.19 Calling `enable_commands()`/`enable_player()` from `init()`
**Symptom:** first-visit "Too deep recursion".
**Cause:** the driver re-invokes `init()` while the original `init()` is
still on the stack.
**Fix:** guard the wrapper with a re-entrancy flag
(`nosave int in_enable_player_now`). Do NOT use a `living()` guard:
legitimate sleep/revive/disable flows re-enable while already living
(`mhxy`).
**Status:** corpus sweep done (73 libs).

### 7.20 Net-dead void-parking without location restore
**Symptom:** no log signal at all. After an unclean disconnect, the
player starts every future session in the void.
**Causes:**
1. The force-quit runs while parked in `VOID_OB` and saves the void as
   `startroom`.
2. A `reconnect()` that restores the location exists, but the login
   daemon calls a different function.

**Fix:** special-case the void in quit (use the remembered temp
location), and restore that location in whichever reconnect function is
actually called.
**Detection:** test both a prompt reconnect and a timed-out one.

### 7.21 A reconnect in the middle of a mandatory setup wizard strands the player
**Cause:** `input_to()` doesn't survive net-dead. The room's catch-all
blocker does, so every command is swallowed.
**Fix:** in `reconnect()`, detect "still in the wizard room, not
complete" and call the room's resume entry point. See also §10.10.

### 7.22 An uncatchable eval-cost abort during a cold first compile leaves a login with no environment
**Cause:** `*Can't catch eval cost too big error` unwinds past `catch()`
and past `enter_world`'s own `!environment` safety net. A plain compile
error in the start room's dependency chain does the same thing.
**Fix:** schedule a `call_out(...,0)` recovery that moves the
environment-less player to a safe room. Audit quit for an
`environment == 0` assumption.
**Grep pitfall:** search `exert_function([0-9]+)`, not `[0-9]`.

### 7.23 A missing `return` after a retry reschedule doubles a `call_out` chain
**Symptom:** an escort NPC's retry branch falls through and schedules a
second `call_out`.
**Fix:** add `return`, so there is exactly one registration per
invocation on every exit path.
**Correction (2026-08-17):** the claimed driver segfault does NOT
reproduce on current master. The driver safely drops `call_out`s
against destructed objects. The mudlib fix stands. Swept across the
`longx.lpc` copies.

### 7.24 Death code overwrites the permanent login location
`set("startroom", base_name(env))` in death/limbo NPCs relocates every
future login. Never write the login-location field from death code.
Check for a `valid_startroom` flag gate (`zzfy`).

### 7.25 Unguarded population helper `new()`/`move()`
**Symptom:** a room crashes on its first-ever visit.
**Cause:** `new()` returns 0 for a missing file but THROWS for a file
that fails to compile, so a post-hoc `objectp` check is too late.
**Fix:**
- `catch` inside the shared `make_inventory()`.
- `catch` force-loads of companion boards.
- Separately, guard individual NPC/quest `create()`/`init_*` chains such
  as `carry_object(missing)->wear()`. The shared-helper fix doesn't
  cover those (`revive`).

**Second half (2026-10-05): `reset()` of the same room base, and the rest of `make_inventory()`.** With the helper fixed,
`case 1:` still went on with `environment(ob[list[i]])` / `ob[list[i]]->is_character()` on the 0 it returned, and both raise
(`Bad argument 1 to environment()`): the first listed NPC the archive never shipped kept the room, and the area behind it,
from loading (xyj2006n: 50 rooms). Three shapes, three edits:
- `case 1:` -> `if (!objectp(ob[list[i]])) break;` behind the make_inventory statement (`scripts/lpc_room_reset_guard.py`,
  also the `if (!ob[list[i]]) { ... }` brace form of hy5 / hymud / yszz). A base whose statement carries an `else`, or that
  already tests the entry (es2, fy2, tianlongbabu, zjdyzj ...), is left.
- `default:` (cctx / jhfy / xajh / pkuxkx): `ob[list[i]][j] = make_inventory(...)` followed by `ob[list[i]][j]->is_character()`
  instead of `continue;` -> `if (!objectp(ob[list[i]][j])) continue;` (same tool). `if (ob[list[i]][j] && ...)` counts as a test.
- The unique-object helper of sje / shujian / sjsh (`ob = unew(file);` raises inside the simul_efun, `new()` being 0 for a
  file that is not there, and the `else` takes `[<1]` of an empty `children()` list) -> `catch` + a size check
  (`scripts/lpc_resilient_room.py`, which also gave the plain `catch` of the first half to 90 more bases).
**Check:** `scripts/lpc_room_reset_probe.py SLUG...` loads the room base, lists `/zz/none/a` (1 copy) and `/zz/none/b` (2 copies)
in `objects`, calls `reset()` under `catch()` and prints HEAD against the tree; it reports through `debug_message()` because
some error handlers only log (jhfy family). 2026-10-05, 149 bases: at HEAD 148 crashed on the single entry and 120 on the
double one, in the tree all 149 are OK.

Don't fabricate missing content.

### 7.26 `file_owner()` captures the wrong path segment
**Symptom:** `sscanf(file,"/u/%s/%s/%s",dir,name,rest)` returns the
subdirectory for nested content. `log_error` then writes to a missing
dir, and every compile diagnostic under `/u/` crashes.
**Fix:** capture only the first segment. Swept across the
`mhxy`/xyj family.

### 7.27 RETRACTED: a raft room deleting its exit
This is plausible intentional design. Document it; don't restore the
exit.

### 7.28 Redundant `enable_player()` calls stack duplicate `add_action`s
**Symptom:** FAILED commands re-run their side effects once per stacked
copy (double charges).
**Fix:** `remove_action("command_hook","")` immediately before the
`add_action`. Don't use a `living()` guard (it breaks disable/re-enable).

### 7.29 A passthrough to a same-named efun can be semantically wrong
`changed_match_path` → `match_path()` (ACL prefix matching on a flat
map) broke every 2+-level `query("a/b")`, silently: bare directions
stopped working while `go` still worked.
**Fix:** implement real nested descent.
**Note:** `dfgsiiv13b` called `match_path` directly with the same wrong
assumption. Before restoring a missing function by its name, read what
the callers actually expect.

### 7.30 A mapping accessor returns a raw uninitialized `int 0`
**Symptom:** `keys(query_skills())` crashes for fresh characters.
**Fix:** `return mapp(x) ? x : ([]);` at the accessor.
**Status:** swept across 178 libs.
**Second shape (NOT swept):** `ob->query("family")["family_name"]`. A
grep is too imprecise for that; fix per site (`ldtx`).
**Regression risk:** §7.156.

### 7.31 `enter_world()` copies stale login-object flags onto the restored body
`user->set("registered", ob->query("registered"))` resets a persistent
flag on every login. Make the flag monotonic, or stop copying it.

### 7.32 A sequential `if` chain ending in one trailing `else`
The `else` binds only to the last `if`, so every earlier match also gets
rejected. Convert the chain to `else if`.

### 7.33 Persisting state before validating it
`set("startroom", dest)` ran before `if (!objectp(obj))`. Validate
before any `set()` of a permanent field.

### 7.34 Leftover debug output in login prompts
Typically `printf("%O\n", ob)` (in both the random-name and typed-name
paths) or `tell_object(...,"ttt")` checkpoints. Delete them. They are
cosmetic, but safe to fix on sight.
**Detection:** grep `printf("%O` in the live `LOGIN_D` file only (dead
`logind*` copies don't matter).

### 7.35 Object-vs-string argument mismatches
A bare call fails at compile time; the same mistake through `->`
compiles and silently misbehaves (`is_killing(ob)`). After fixing a bare
call, grep the `->` sites for the same function. Evaluate each one's
blast radius.

### 7.36 Idle-room cleanup checks only `interactive()`
**Symptom:** it destructs a room a net-dead player is standing in.
**Fix:** `|| userp(inv[i])`. Also `objectp`-guard the `tell_room` in
`user_dump`.

### 7.37 `ob->efun_name(...)` with no such method silently no-ops
`me->command("start")` returns 0 with no error, because `call_other`
never falls back to an efun. Call the logic directly, and re-check any
`this_player()`-dependent efuns inside `call_out`s.

### 7.38 `destruct()` can't be overridden as a simul_efun
Delete the override. Audit callers if its pre-cleanup mattered (haiyang
family, `xkx100`).

### 7.39 The mudlib redefines `MUD_NAME`
The driver predefines it from the config's `name`. Delete the mudlib's
`#define`.

### 7.40 A daemon `#include`d into `simul_efun.lpc` duplicates `create()`
`#include "/adm/daemons/ftpd.lpc"` inside simul_efun. Delete the stray
include.

### 7.41 A literal `\r` byte inside a `.o` mapping key
This is pre-existing corruption in cached ACL state. Move the file aside
(`.corrupt-bak`); the daemon regenerates it.

### 7.42 A content NPC named `master.c` misdetected as the master object
The real master defines `object connect(`. Prefer that file over
filename matches (Century/adm-single bulk-convert libs).

### 7.43 `creator_file`/`domain_file`/`author_file` forward to an unloaded simul_efun
**Symptom:** a warning during the simul_efun compile becomes boot-fatal.
**Fix:** `if (!find_object(SIMUL_EFUN_OB)) return "";`.

### 7.44 The lib assumes `/log/...` or `/topten/` already exists
`mkdir -p` the exact paths named in the errors. Gitignored dirs need
code-level assurance (§7.11).

### 7.45 `global include file` names a header that doesn't exist
Check with `find -iname "global*.h"` (`global.h` vs `globals.h`).

### 7.46 LIMA-lineage libs need their own driver flags (resolved)
**Cause:** `check_config.lpc` requires `NO_LIGHT`, `NO_ADD_ACTION`,
`NO_WIZARDS`, `undef OLD_ED`, and `undef PACKAGE_UIDS`, plus
`ARRAY_RESERVED_WORD` in EITHER direction depending on the snapshot.
**Fix:** a separate driver built from a `git worktree` off
`~/src/fluffos`, with flag flips and `-DPACKAGE_UIDS=OFF`:
- `~/src/fluffos-lima` serves `lima`, `swmud`, and `spacemud`
  (`custom_drivers/lima_swmud`).
- `~/src/fluffos-wilderness` (`#define ARRAY_RESERVED_WORD`) serves
  `wilderness` only.

`sgzmudsgz` was rewritten (`array` → `mixed *`) and runs on the default
driver. `LPCC=` overrides `lpcc_check.sh`'s binary. Check each new
LIMA-lineage lib's `check_config.lpc`.

### 7.47 `origin()` returns a string here
The mapping:

| old constant | value | now returns |
|---|---|---|
| ORIGIN_DRIVER | 0x1 | `"driver"` |
| ORIGIN_LOCAL | 0x2 | `"local"` |
| ORIGIN_CALL_OTHER | 0x4 | `"call_other"` |
| ORIGIN_SIMUL_EFUN | 0x8 | `"simul"` |
| ORIGIN_CALL_OUT | 0x10 | `"internal"` |
| ORIGIN_EFUN | 0x20 | `"efun"` |
| ORIGIN_FUNCTION_POINTER | 0x40 | `"function pointer"` |
| ORIGIN_FUNCTIONAL | 0x80 | `"functional"` |

Grep `origin()\s*==\s*ORIGIN_` and replace with the string compare.

### 7.48 A `private` member called from an inheriting program
This is illegal here (old MudOS `private` ≈ today's `protected`).
Change it to `protected` where the error is reported. Leave a
deliberately `private nomask command_hook` alone unless §8.3a applies.

### 7.49 A `valid_write` save-file check forgets the save extension
`save_object()` passes the full `.o` path, so compare with
`file == qsf || file == qsf + ".o"`. Shows up as `quit` failing.

### 7.50 `accept_kill()` passes an object to `is_killing()`
Pass `ob->query("id")`. Seen in 5 unrelated lineages; check on sight.

### 7.51 NTOS `query_heartbeat_interval` / `set_heartbeat_interval`
No equivalent exists. Delete the calls.

### 7.52 Socket daemons (`mudlistd`, `dns_master`, `httpd`, `messaged`, `versiond`)
**Default fix:** gut the entry points (`create`, `startup_udp`,
listener setup) to no-ops, plus every function body that contains a
`socket_*` call. Unreachable code is still type-checked.
**Exception:** a multi-purpose daemon (`versiond` with dozens of
callers). Gut only its socket functions. Count callers with
`grep -rl "VERSION_D->"`.
**`messaged` socket_bind trap:** `"" + 10` produces the string `"10"`
when `get_config(__MUD_PORT__)` returns a string (§7.89), and
`socket_bind()` then throws.
- The fix is `startup_udp(){return 0;}` plus a `!socket_id` guard in
  `send_udp`.
- Results are lineage-INDEPENDENT. 5 of 16 libs crashed and the rest
  were clean, so check each lib live. A good trigger is
  `call /adm/daemons/network/messaged->query_udp_port()`.

**Simul_efun with `socket_*` is boot-fatal under WASM.** Check it first.

### 7.53 A defensive `seteuid(getuid())` undoes `create()`'s `seteuid(ROOT_UID)`
This happens when the uid never resolved. Grep the whole file for
`seteuid(` and use the intended uid everywhere.

### 7.54 `sscanf(read_file(counter))` on a fresh checkout
`log/` is gitignored project-wide, so this is real, not harness-only.
Guard it.
- Variant 1: `file_size(...) == 0` instead of `<= 0`. Compare with the
  sibling checks in the same file.
- Variant 2: a fallback `sscanf(astr, ...)` passed the whole array where
  `astr[i]` was meant.
- Wrap `toptend` calls in `catch` in `enter_world`.

### 7.55 Re-entrant call into a daemon before its later globals are initialized
Top-level initializers run in declaration order, so a reentrant
`get_status()` sees `wiz_levels` still at 0. Guard with
`arrayp(wiz_levels) &&`.

### 7.56 Two plausible "security daemon" files
Confirm which file `#define SECURITY_D` (or `LOGIN_D`, etc.) points to
before editing (`hy`, `dtxywzxzb`).

### 7.57 Editing `.o` files in text mode corrupts embedded `\r` keys
Use `rb`/`wb`, and compare CR counts before and after.

### 7.58 A stale `SIMUL_EFUN_OB` macro breaks `remove()` gates
**Symptom:** every `destruct()` fails "remove() can only be called by
destruct()", and `quit` fails for new players.
**Fix:** point the macro at the `simulated efun file` named in the
config.

### 7.59 Custom `valid_read` substitutes `this_player()` (or `previous_object()`, in master) for the driver's `user`
**Symptom:** compiles and `#include`s are denied while a low-privilege
player is connected, which breaks registration.
**Fix:**
`if (this_player() && func != "load_object" && func != "include") user = this_player();`
Apply the same exclusion in master's wrapper (`hy3`).
**Debugging:** wrap the failing call in `catch` and `write()` the
file/user/func at every deny return.

### 7.60 `log_error()` → `CHANNEL_D->do_channel()` before CHANNEL_D is loaded
**Symptom:** a benign `#pragma` warning recurses into tens of thousands
of trace lines.
**Fix:** `if (find_object(CHANNEL_D)) ...`.
