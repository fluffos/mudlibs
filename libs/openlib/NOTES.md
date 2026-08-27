# OpenLib -- porting notes

Source: `git clone https://github.com/tmcintos/OpenLib` (commit
`044c60a5266e40f9b469503cf73fa06534d67df7`, cloned 2026-08-27). Real
MudOS v22.1a6 mudlib by Tim McIntosh, formerly called "UltraLib" --
released as a single alpha snapshot (v0.1) in late 1996, per the repo's
own README ("There was an alpha release in late 1996 (v0.1) after which
development ceased"). Top level bundles `LICENSE` and a short `README.md`
alongside the real mudlib root, `mudlib/`. 776 raw files (LICENSE +
README.md + mudlib/), 3.8MB excluding `.git`. Slug `openlib`, number
943, port 40245.

Genuinely distinct from everything else in this collection: an
English-language, from-scratch codebase (`adm/obj/daemon/master.c`
confirms real MudOS structure) built around a UNIX-flavored
security/shell model rather than the usual Chinese-wuxia lineage. `ls
libs/` was checked for anything similarly named before starting; nothing
close exists.

## 1. Conversion

Pure ASCII/English archive -- `convert_lib.sh` reported
`already_utf8=685 converted=1 lossy=0 skipped_binary=88` (the "88
binary" count is real: `www/` has a handful of image assets, `doc/man/`
has troff-formatted man pages the text-extension sweep still handled
fine, and a couple of true 0-byte/binary placeholders). Renamed 242
`.c` files to `.lpc`, fixed 62 literal `.c"` references, converted 16
local angle-bracket `#include`s to quotes, and ran the `static`->`nosave`
sweep across 41 files with zero collisions (no `"static` path-literal
hits, no `#define nosave static` compatibility shim).

One rename casualty needing a manual fix: `adm/cmd/player/unsetenv.lpc`
was a raw filesystem **symlink** (`unsetenv.c -> setenv.c`) in the
original archive -- the rename script renamed the real target file
(`setenv.c` -> `setenv.lpc`) but left the symlink itself pointing at the
now-nonexistent `setenv.c`, since symlink targets aren't text content
the rename sweep rewrites. Fixed by recreating the symlink to point at
`setenv.lpc`. Two more symlinks exist (`doc/man/man2..man7 ->
cat2..cat7`) but those target directories, unaffected by the file
rename.

## 2. `include/runtime_config.h` divergence (AGENTS.md §7.89), found and
   fixed before ever booting

This archive bundles its own `include/runtime_config.h` (a copy of the
driver's own header, since OpenLib shipped alongside driver source
historically) with its own from-scratch `get_config()` slot numbering:
`BASE_CONFIG_INT = BASE_CONFIG_STR + 14` (i.e. `CFG_INT(0)` == 14),
versus this driver build's real internal numbering
(`~/src/fluffos/src/include/runtime_config.h`), where
`RC_BASE_CONFIG_INT = RC_LAST_CONFIG_STR + 1` == 256. Since this
driver's `#include <...>` resolution would pick up the mudlib's own
copy under `include/` (per the config's `include directories` list)
rather than the driver-canonical one, every `get_config()` call using
this header's macros would silently read the WRONG config slot.
`adm/include/config.h`'s `mud_name()`/`mud_port()` macros are the only
two symbols this archive actually calls `get_config()` through
(confirmed via a corpus-wide grep for `get_config(`) -- both map to
index 0 in either header (`CFG_STR(0)`/`CFG_INT(0)`), so this
particular archive would likely have degraded rather than crashed
outright, but per the established fix (`ds386`, `zjdywzb`,
`yhwhpublicfi`), the header itself was replaced wholesale with the
driver's canonical copy rather than trusting the coincidence. Diffed
the two headers' symbol sets first: the mudlib's own extra symbols
(`__ADDR_SERVER_IP__`, `__SAVE_BINARIES_DIR__`, `__ADDR_SERVER_PORT__`,
`__RESERVED_MEM_SIZE__`, `__COMPILER_STACK_SIZE__`,
`__EVALUATOR_STACK_SIZE__`, `__MAX_LOCAL_VARIABLES__`) are used nowhere
outside the header itself, so no alias/reconciliation was needed.

## 3. `get_root_uid()`/`get_bb_uid()`/`creator_file()` (AGENTS.md §7.2)

This driver build has `PACKAGE_UIDS` on, which requires these applies on
`master.lpc` or the whole process `exit(-1)`s at boot. This mudlib's own
access-control model is entirely privilege-based (a custom
`security_d.lpc` consulting per-directory read/write protection tables,
walked up the path hierarchy -- see §5 below) and never touches
`getuid()`/`seteuid()` anywhere (corpus-wide grep: zero hits). Added the
same flat "everyone is Root" stub used for `nightmare3`/`nightmare4`/
`residuum`:

```lpc
string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }
string creator_file(string file) { return get_root_uid(); }
```

## 4. Master's lazy `SECURITY_D` auto-load recurses forever (AGENTS.md
   §7.1) -- 40MB of `debug.log` on the very first boot attempt

`adm/obj/daemon/master/valid.lpc`'s `valid_read()`/`valid_write()` do
`check_priv(SECURITY_D->get_file_protection(file, N))` unconditionally
on every single file access -- an implicit `->` call that lazily
compiles `/adm/obj/daemon/security_d` the very first time either apply
runs (this daemon isn't preloaded). While `security_d.lpc` is mid-
compile, the driver calls `valid_read()` again for every file IT needs
(its own source, its `#include`s), which again finds `SECURITY_D`
still not resident and tries to load it again -- unbounded recursion,
exactly AGENTS.md's §7.1 shape (previously seen as an explicit
`load_object()`/`find_object()` pair; here it's the same trap but
triggered through a bare `->` auto-load instead). Symptom on the first
raw boot attempt: the driver never crashed outright, but spammed the
identical `valid_read` error trace to `log/debug` for the full 8-second
test window, producing a 40MB, 800,000-line log file before being
killed -- a genuine near-miss for the kind of runaway-log/disk-fill
incident this session's safety notes warn about, caught immediately by
watching the log size rather than assuming "no crash" meant "fine".

Fixed with the standard re-entrancy-flag guard, applied to BOTH
`valid_read()` and `valid_write()` (the archive's `valid_write()` has
the identical `SECURITY_D->get_file_protection()` call on its own
fall-through path, so it carries the exact same latent bug even though
it wasn't the one that fired first):

```lpc
private nosave int loading_security_d;
// ...
if( !find_object(SECURITY_D) ) {
  if( loading_security_d ) return 1;
  loading_security_d = 1;
  catch(load_object(SECURITY_D));
  loading_security_d = 0;
  if( !find_object(SECURITY_D) ) return 1;
}
```

`SAVE_D` (the other daemon `valid_write`/`valid_read` reference) is
NOT at the same risk: it's only consulted when `func == "save_object"`/
`"restore_object"` specifically, so a `save_d.lpc` compile (itself with
no `#include`s and no inherit) never re-enters that specific branch the
way `SECURITY_D`'s unconditional else-path did. Confirmed via a clean
post-fix boot (774-line `debug.log`, only preload compile warnings, no
error-trace spam) and via `grep -c "valid_read\|recursion"` staying at
1 (the fix's own guard-comment text, not a real hit).

## 5. §7.118 `.c`->`.lpc` filename-slice bug -- broke the entire
   command-dispatch registry

`adm/obj/daemon/cmd_d.lpc`'s `hash_path()` builds the per-directory
command lookup table every wizard/player command dispatches through
(`find_cmd()`, called from `adm/obj/clone/user.lpc`'s `cmd_hook()` --
the single command dispatcher this whole mudlib routes through):

```lpc
cmdpathmap[path] = map(filter(files, (: $1[<2..<1] == ".lpc" :)),
                       (: $1[0..<3] :));
```

The filter guard slices the LAST 2 characters of each filename and
compares to the 4-character literal `".lpc"` -- a 2-character slice can
never equal a 4-character string, so the filter always returned an
EMPTY array, and `cmdpathmap[path]` for any freshly-hashed directory
was always `({})`. `find_cmd()`'s `member_array(name, cmdpathmap[path])`
then always returns -1, so it always returns 0 -- **every ordinary
command would silently fail to dispatch**, project-wide -- this archive
ships NO pre-populated `adm/data/cmd_d.o` cache at all (confirmed: no
such file exists anywhere in the raw clone), so `cmdpathmap` starts
empty on every fresh boot and EVERY command directory gets hashed fresh,
via this exact buggy function, the first time anything in it is ever
looked up. Found and fixed via static code inspection before the first
live boot, so the broken behavior itself was never directly observed
live -- but the shape matches AGENTS.md's §7.118 catalog entry exactly:
`[<2..<1]`/`[0..<3]` are correct only
for the archive's original 2-character `.c` extension, silently wrong
after this project's `.c`->`.lpc` rename (a 4-character extension).

Fixed by widening both slices from 2 to 4 characters:
```lpc
cmdpathmap[path] = map(filter(files, (: $1[<4..<1] == ".lpc" :)),
                       (: $1[0..<5] :));
```
Verified via `lpcc` (clean compile, no change in pass/fail count) and
live: every command dispatched during testing (`look`/`score`/`who`/
`tell`/`save`/`quit`/`eval`, both as `root` and as a fresh non-admin
registration) exercised this exact function on its directory's first
lookup, and `adm/data/cmd_d.o` (freshly written by `reset()`'s
`save_object()` after the fix, not shipped by the archive) shows the
correctly-stripped, extensionless command names for every hashed
directory.

## 6. `ed_start()`/`ed_cmd()`/`query_ed_mode()` on the real player body
   (AGENTS.md §6.2, same class as `residuum`'s writeup)

This driver build has `__OLD_ED__` (single-arg classic `ed()`, not the
new synchronous `ed_start`/`ed_cmd`/`query_ed_mode` API this archive's
`adm/obj/clone/user.lpc` was written against). This mattered far more
here than on most archives with this same gap: `adm/obj/clone/user.lpc`
(`DEFAULT_BODY`, `login.h`'s `SECURE_CLONE_DIR "/user"`) is the REAL
player body class every login actually clones (a naive grep for the
literal string `"clone/user"` misses this -- the only real reference is
through the `DEFAULT_BODY` macro, used by `login_d.lpc`'s
`player_enter_world2()`: "guaranteed to load *grin*", per the original
author's own comment). Fixed the same way as `residuum`:

- `start_ed(file, restrict)` now calls old `ed(file, "ed_exit",
  restrict)` and a new `ed_exit()` apply (empty body -- nothing needs
  to run when a session closes) replaces the removed manual-driving
  pair.
- `process_ed_input()` (which manually looped `ed_cmd()`/`input_to()`)
  is deleted outright, not shimmed -- under `__OLD_ED__` the driver's
  own C-level input loop owns an active ed session directly, so nothing
  else in the file called it.
- `net_dead()`'s crash-recovery block (`if(in_edit()) { ed_cmd(".");
  ed_cmd("w ..."); ed_cmd("Q"); }` -- an attempt to auto-save-and-quit
  an in-progress edit session if the connection drops) has no
  achievable equivalent under `__OLD_ED__`: there is no LPC-callable
  `ed_cmd()` to script into the driver-owned session from here. Removed
  with a code comment explaining why, rather than fabricating
  replacement behavior -- documented as a known, non-portable gap (the
  underlying driver-level old-ed implementation may or may not have its
  own internal disconnect handling; not verified either way this pass).

Verified via `lpcc` (the file's only remaining warning is a pre-existing,
harmless `remove()` return-type mismatch against `living.lpc`, unrelated
to this fix) and live play (see §8).

## 7. SEVERE: password verification used a classic 2-character DES
   crypt() salt against this driver's modern `$6$` SHA-512 hashes --
   **no account could ever log back in a second time**

Found live, during the very first restart-and-reconnect verification
pass (exactly the class of bug that a single continuous test session
can't catch -- see AGENTS.md §7.120's precedent). `root` registered
fine, played, and quit cleanly in the first session; reconnecting with
the exact same password on the very next connection (same driver
process, no restart even needed to reproduce it) failed with "login
incorrect."

Root cause, in `adm/obj/daemon/login_d.lpc`:
- `set_password(crypt(password, 0))` -- passing `0` (an int, not a
  string) as the salt makes this driver's `crypt()` efun auto-generate
  a real modern salt and return a full `$6$<16-char-salt>$<hash>`
  SHA-512 string (confirmed directly from the saved connection file:
  `password "$6$KpTiRSCHtOQQGXdM$u/QCiJj9C13yaDdskl0Go8S0y.tAgO4EBW5vZ7sZ1cGLqLKPgT/y4N6ZxKaVG6IaDLm0NiWrEQUzjpLhEhHBK."`).
- `check_passwd()`'s verification step, though, did
  `crypt(passwd, crypted_pass[0..1]) == crypted_pass` -- `[0..1]`
  extracts only the first TWO characters of the stored hash (`"$6"`),
  which was the correct, complete salt under the classic MudOS-era DES
  `crypt()` this code was originally written against in 1996. Against
  this driver's `crypt()` (`packages/core/efuns_main.cc`'s `f_crypt()`),
  a 2-character salt string that doesn't match the `$1$`/`$5$`/`$6$`
  prefix pattern (which requires at least 3 characters, with the 3rd
  being `$`) falls through to the driver's OWN "old crypt() password
  detected" 2-char-key compatibility path, re-hashing with a
  completely different algorithm/salt than the one the password was
  actually stored with -- so `crypt(passwd, "$6") != crypted_pass`
  ALWAYS, for every account, on every login after the very first.

  This is the single most severe bug found on this lib: it didn't just
  degrade some rarely-exercised feature, it made the mudlib's own
  registration/login flow **completely non-functional for returning
  players** -- every account was permanently a one-time-use account.

  Fixed by passing the WHOLE stored hash back in as the salt argument,
  which is the standard POSIX `crypt()` verification idiom (`crypt(3)`
  itself only reads as much of the string as it needs for the salt and
  ignores the rest):
  ```lpc
  return ( crypt(passwd, crypted_pass) == crypted_pass );
  ```
  Verified live end-to-end: killed and restarted the driver process
  (a genuine process restart, not just a reconnect within the same
  session), reconnected as `root` with the exact original password, and
  logged in successfully; repeated a second restart-and-reconnect cycle
  afterward to confirm stability. Also registered a brand-new,
  non-admin account (`testuser`) through the full name/password/email/
  real-name/gender flow and confirmed `look`/`score`/`quit` all produce
  correct output.

## 8. Verification -- full registration through world entry, both admin
   and ordinary accounts, across two genuine process restarts

- `root` (this archive's own documented bootstrap superuser, see
  `GETTING_STARTED`) registered with a fresh password, reached
  `/d/base/start` (the mudlib's single starting room, "the exact center
  of the MUD"), and `look`/`score`/`who`/`tell root <msg>` (self-tell,
  confirming `find_player()`/`set_living_name()` -- see §10 below --
  actually work) /`save`/`quit` all produced correct output.
- A second, ordinary non-admin account (`testuser`, gender `f`) went
  through the FULL registration flow (username, password+verify, cap-
  name, email, real name, gender) and reached the same starting room
  with working `look`/`score`/`quit`.
- Two independent full driver-process kill+restart cycles were run
  (the second specifically to confirm the crypt() fix above holds
  across a real restart, not just a same-process reconnect); `root`
  logged back in successfully both times with the same password.
- `log/debug` stayed small and warning-only across every boot in this
  pass (no repeat of the §4 recursion incident).

## 9. Known content gaps -- NOT fixed (author's own incomplete v0.1
   alpha content, not driver-compat)

Per the archive's own `GETTING_STARTED` ("Since the lib is incomplete,
you will have to 'ls' /adm/cmd/* and /cmd/* to find out what commands
are available"), several files were shipped unfinished by the original
1996 author and fail `lpcc_check.sh` for reasons unrelated to this
project's conversion -- confirmed genuinely pre-existing, not touched,
per this project's standing "never fix content/design, never invent
missing files" policy:

- **`obj/inherit/shop.lpc`** ("Fail to load object", no compile error at
  all) -- root-caused live via `eval` + a temporary `debug_message()`
  trace in `valid_read()` (removed again afterward): its `initialize()`
  hardcodes `new("/u/k/kyricc/WEAPONS/kdofa.lpc")` /
  `.../ARMOURS/kcod.lpc"` -- the original author's (Jason "Kyricc"
  Borgmann, per the file's own copyright header) own personal test
  items under his own `/u/k/kyricc/` wizard directory, never shipped in
  this archive. This mudlib's real, correctly-functioning
  privilege-based ACL (see §3) protects `/u/` (`USER_DIR`) reads to
  priv `1` (admin-only) by design -- a plain content object (default
  priv `@mudlib`) attempting to `load_object()` into another wizard's
  private directory is CORRECTLY denied ("*Read access denied.",
  confirmed via the driver's real `check_valid_path()`/`valid_read()`
  path, not a bug in either the ACL or the rename). This would have
  failed identically on the original 1996 driver for the same reason --
  it's an authorial reference to content that was simply never
  committed to the repo, not a driver incompatibility.
- **`obj/clone/money.lpc`** / **`obj/clone/reinzombie.lpc`** -- both
  define their own `create()`, which is illegal on this codebase's own
  terms: `obj/inherit/base.lpc`'s `BASE::create(int no_setup)` is
  declared `nomask` specifically so that "mudlib level objects" are
  meant to override `initialize()`/`low_setup()`/`setup()` instead (the
  file's own doc comment says so explicitly). Both example files
  predate any FluffOS involvement and violate the framework's own
  documented convention; `money.lpc` additionally calls a `set_ids()`
  function that was never implemented anywhere in the shipped library
  (only this one call site exists in the whole corpus) and references
  `OBJECT_LIVING`, a constant explicitly commented out in
  `include/object_types.h`.
- **`cmd/wiz/netstat.lpc`** -- calls `dump_socket_status()`, an old
  MudOS-era diagnostic efun with no equivalent on this driver (AGENTS.md
  §6.2 class: "efuns that were never real on this driver"). A single
  wizard-only diagnostic command; not fabricated.
- **`doc/misc/m_ansi.lpc`** -- a documentation/example snippet (zero
  references anywhere in the real mudlib tree) demonstrating a
  `this_body()`-based ANSI-preference pattern that doesn't exist as a
  concept anywhere else in this codebase. Dead example content.
- **`adm/obj/daemon/master_old.lpc`** -- an old backup copy of the
  master object (confirmed zero references anywhere; the live config
  points at plain `master`). Genuinely dead, matching this project's
  established "personal backup/variant file" precedent.
- **`adm/obj/daemon/master/valid.lpc`** -- this "failure" is a false
  positive of the batch `lpcc_check.sh` sweep itself: this file is
  textually `#include`d into `master.lpc` (`#include
  "master/valid.lpc"`) and was never meant to compile as a standalone
  object -- its `SIMUL_EFUN`/`BASE` macro references resolve fine in
  context (via `master.lpc`'s own `#include <mudlib.h>`) but not when
  the batch sweep tries to load `master/valid.lpc` in isolation with
  only its own `#include <daemons.h>`. No fix needed; `master.lpc`
  itself compiles and boots clean.
- **The player-visible "compile: error: Check ... for more information"
  spam on nearly every first-time file compile** -- `master.lpc`'s own
  `log_error()` unconditionally shows this line to `this_interactive()`
  for EVERY compile diagnostic it receives, warnings included, with no
  severity filter at all (unlike AGENTS.md §7.103/§7.119's "missing or
  case-mismatched filter" classes, this mudlib never attempted a filter
  in the first place). Since this apply fires identically for warnings
  on the classic MudOS driver too (calling `log_error` for every
  compile diagnostic, not just fatal ones, is standard driver behavior
  on both), this is original 1996 design, not a driver-compat
  regression -- left as-is per this project's "never fix content/
  design" policy, but flagged here since it's very visible in play (the
  vast majority of the diagnostics themselves are the harmless
  §4.3-class "Illegal to declare nosave function" warning, left over
  from the archive's original `static`-declared functions).

## 10. Other checklist items checked, no bug found

- `find_living()`/`find_player()` (AGENTS.md §7.131): `set_living_name()`
  IS called, correctly, from the shared `m_living.lpc` module's
  `set_name()` (itself called from `user.lpc`'s `init_player()` on every
  login) -- verified live via a self-`tell`.
  `private nomask command_hook` (§8.3a): `user.lpc`'s real dispatcher is
  `cmd_hook()` (not `command_hook`), registered via
  `add_action((: this_object()->cmd_hook($1) :), "")` -- a closure, not
  a bare string dispatch -- and is NOT declared `private` at its actual
  definition (only an unused, stale `private` forward-declaration
  comment exists in the "Applies" block up top); confirmed working live
  regardless (every tested command dispatched correctly).
- No float-returned-as-declared-int arithmetic (§7.121), no bare
  file-scope `IDENT = (...)` initializer statements (§7.123), no
  fraction-vs-percentage literal mismatches (§7.124), no stale-`.c`
  extension in `.o` save data (§7.126 -- no archive ships any `.o` data
  referencing an object path by string at all; the one runtime-generated
  cache with path-shaped content, `adm/data/cmd_d.o`, stores bare
  extensionless command names post-fix, unaffected by the rename either
  way), no unconditional `query_idle()`-after-non-interactive shape
  (§7.130 -- this codebase uses the driver's real
  `net_dead()` apply directly, no self-polling `heart_beat()` net-dead
  check on the player body at all), no `tell_room()`/`message()`
  optional-argument-as-bare-0 crash (§7.129 -- `simul_efun/tell_room.lpc`
  already correctly guards `exclude` before forwarding to `message()`).
- No `MUD_PORT`/hardcoded-port self-rejection (§5.3): the live config's
  port (40245) is read from `get_config()`, not a compiled-in constant.
- No outbound network connections at boot or during the compile sweep:
  the three real listening daemons this archive preloads
  (`adm/obj/daemon/net/http_d.lpc`, `net/ftp_d.lpc`, `net/finger_d.lpc`)
  each only `socket_bind()`/`socket_listen()` an INBOUND port
  (`PORT_HTTP`, `PORT_FTP`, `mud_port()+79`) -- genuine local server
  functionality, not a phone-home. `net/intermud.lpc`, `net/oob_d.lpc`,
  `net/auth_d.lpc`, `net/ucache_d.lpc`, and `net/remote.lpc` are also
  preloaded but never call `socket_connect()`/`resolve()` from their own
  `create()` -- confirmed via a corpus-wide grep for `socket_connect`
  (only `obj/inherit/server.lpc`/`client.lpc`'s generic wrapper methods
  reference it, and nothing calls either wrapper automatically at boot).

## 11. RAM safety

This archive is small (774 files, 3.8MB). `lpcc_check.sh`'s batch sweep
was run under a `ps -o rss=` watch the whole time; peak RSS stayed under
4MB throughout (finished in under 4 seconds both times it was run).

## 12. Deep functional test (round two, AGENTS.md §10.7)

One continuous session (a raw Python socket client against
`~/src/fluffos/build-debug/src/driver config.fluffos`), covering the
newbie `GETTING_STARTED` flow end-to-end plus the mandatory
restart-and-reconnect verification. `root`'s password from the
onboarding pass was not recorded anywhere retrievable, so its saved
`connection.o`/`body.o` were backed up and reset to force a fresh
registration; **`root`'s current password for future testing is
`RootPass2026!`** (documenting this now so the next tester doesn't hit
the same gap).

### Found and fixed: `sprintf()` missing its `%s` argument in
    `obj/clone/monster.lpc`'s `die()` -- crashed every undead-monster kill

```lpc
tell_room(environment(this_object()),
	  sprintf("%s turns to dust before your eyes.\n"));
```

`sprintf()` with a `%s` directive and zero arguments throws a driver
runtime error ("Not enough arguments to sprintf") on every call --
this fires unconditionally whenever any `monster.lpc` instance with
`undead` set dies, a real driver-API misuse (efun argument-count
mismatch), not a content/balance question. Fixed by passing the
monster's own name:

```lpc
tell_room(environment(this_object()),
	  sprintf("%s turns to dust before your eyes.\n",
		  query_cap_name()));
```

Verified live via `eval`: cloned a `/obj/clone/monster`, named it,
`set_undead()`, then `die()` -- correct message ("Testzombie2 turns to
dust before your eyes.") printed, monster's inventory dropped, object
destructed, no runtime-error trace in `log/errors/runtime` or
`log/debug`. (An earlier attempt in the same session hit the driver's
"Bad argument 1 to EFUN call_other()" trace inside
`security_d.lpc`'s `eval_unguarded()` -- root-caused to a test-script
mistake, not a mudlib bug: `present()` searches an object's `id()`
list, set by `set_name()`, not the capitalized `set_cap_name()` string
used in the first attempt's search term.)

### Registration, privilege commands, and reconnect verification

- `root` (bootstrap account, see §GETTING_STARTED) logged in,
  `look`/`score`/`i` all correct.
- A fresh non-admin registration (`walker`) went through the full
  username/password+verify/cap-name/email/real-name/gender flow,
  reached `/d/base/start`, and `look`/`score`/`i`/`help`/`west`/`east`
  all worked. `help` prints the general player help file correctly.
- As `root`: `mkwiz walker`, `addmem walker Admin`, `chmem adm walker
  Admin` all succeeded (`lswiz`/`lsdom`/`lspriv` confirmed the new
  wizard/admin state); logging in as `walker` afterward showed the
  wizard-only `nmsh` shell features (`cd`/`pwd`/`ls` against real
  mudlib paths) working correctly -- `CurrentWorkingDirectory` in
  `adm/obj/clone/shells/nmsh.lpc`'s `shell_init()` is only initialized
  `if(wizardp(owner))`, so a non-wizard's `pwd`/`cwd` prints a bare
  `0` (the field's un-set default value concatenated into
  `write(...+"\n")`) instead of a path -- this is `cmd/wiz/pwd.lpc`
  being reachable at all by a non-wizard (no ACL gate on the command
  itself, just on what it can usefully show), not a crash, and not
  fixed: `pwd`/`cd`/`ls` are documented wizard-only tools in this
  lib's own UNIX-flavored design (`GETTING_STARTED`'s "Wizard:"
  command list), and a non-wizard genuinely has no filesystem cwd
  concept to report. Left as an observation, not a bug, per this
  pass's design-vs-programming boundary.
- **Two full quit-and-reconnect cycles**, the second across a genuine
  driver process kill+restart (not just a same-process reconnect):
  `root` logged back in with `RootPass2026!` both times, reaching the
  same room with saved state (`score`/`i` correct), confirming the
  onboarding pass's crypt()-salt fix (§7 in this file) still holds.
  `log/debug` stayed warning-only (compile-warning noise plus the
  intentional `log_error()`-shows-every-diagnostic behavior already
  documented in §9) across every boot and quit in this pass --
  grepped after each `quit`, not just eyeballed.

### Thirteen standing cross-cutting patterns, explicitly checked

Eight were already confirmed clean during onboarding (§10 above):
§7.121 float-in-declared-int, §8.3a private dispatch-target, §7.123
bare file-scope initializer, §7.124 fraction/percentage mismatch,
§7.126 stale `.c`-extension save data, §7.129 `tell_room`/`message`
omitted-arg-as-0, §7.130 unconditional post-non-interactive liveness
check, §7.131 `find_living`/`find_player` registration. This pass
additionally checked the five newer ones:

- **§7.122** (class/marker-item duplication on disconnect/reconnect):
  N/A -- this lib has no starting-equipment/quest-item-granting system
  at all (confirmed via `login_d.lpc`'s `player_enter_world()` --
  it only creates the body/shell objects themselves via `new()`, never
  clones any game item). Nothing for this pattern to duplicate.
- **§7.132** (`map()` over a mapping bound to the wrong arg count): no
  instance found. Corpus-wide grep for every `map(` call site shows
  every one operating on an array (a `sort_array()`/`filter()`/
  `explode()`/`keys()`/`values()` result, or a literal `object *`),
  never a bare mapping passed directly.
- **§7.133** (`net_dead()`-class apply never defined): not applicable
  here -- `adm/obj/clone/user.lpc:218` DOES define `net_dead()` (see
  §6 above for its own, separately-documented `__OLD_ED__` gap);
  confirmed present and reachable, not a silent no-op.
- **§7.134** (array/mapping field defaulting to `0` instead of `({})`/
  `([])`): `user.lpc`'s `channels`/`aliases`/`env_vars`/`msgbuf`
  fields are all explicitly zeroed to their empty-collection form in
  `initialize()` (called on every fresh `new()`) before
  `restore_player()` ever runs, so a genuinely new character never
  sees a bare `0` on these fields.
- **§7.135** (accessor missing a lazy-init guard, often crashing
  `quit()`): `quit.lpc`/`net_dead()`/`save`'s call paths were all
  exercised live, repeatedly, across every test character and both
  reconnect cycles with zero crashes.

### Verification character/state left as evidence

`root` (password `RootPass2026!`, documented above) is the only
account left in the saved data after this pass -- the throwaway
`walker` (promoted wizard/Admin-domain member) and its wizard home
directory, plus the runtime-only `adm/data/security.o` domain/priv
save it created, were deleted before committing so `security_d.lpc`
falls back to its pristine `create()` defaults (root-only admin) on
next boot, matching the state this lib shipped in.

## 13. Round-two follow-up: `ls` crash for non-wizards, plus an
    independent cross-check of §12

This session dispatched a research subagent mid-pass (originally scoped
to just extracting the AGENTS.md §7.121-135/§8.3a pattern definitions)
that ended up independently re-running this exact §10.7 pass itself in
parallel on the same lib -- same driver, overlapping connections (a
stray "Walker" registration and a mid-session `quit` visible in this
session's own test transcripts), converging on the identical `root`
password and the identical `sprintf()` fix in `obj/clone/monster.lpc`
documented in §12 above, which it committed first (`62e0d51659c`).
Confirmed via `git log`/`git show` that no work was lost or
double-applied; this section is a genuine follow-up, not a redo.

One item in §12's writeup benefits from a small correction: the
non-wizard `pwd`/`ls`/`cwd` gap was described there as "not a crash".
That's true for `pwd` (bare `cmd/wiz/pwd.lpc` prints a literal `0`,
since `int + string` concatenation doesn't error on this driver) but
NOT true for `ls`: a non-wizard's bare `ls` (no filespec) hit `do_ls()`
in `adm/cmd/wiz/ls.lpc:88`, which called `file_size(dir)` on `dir`
still holding its uninitialized int `0` value (the same
`this_player()->query_cwd()`-returns-unset root cause documented in
§12 -- `nmsh.lpc`'s `shell_init()` only sets `CurrentWorkingDirectory`
`if(wizardp(owner))`) -- confirmed live, freshly reproduced against a
brand-new non-wizard registration (`morgan`), with the driver's own
`log/errors/runtime` capturing `**Bad argument 1 to file_size()
Expected: string Got: 0.` This is a real, unguarded crash (the player
sees a bare `runtime: error: Check /log/errors/runtime for more
information.` with no listing at all), not a graceful degraded
message, and squarely a "missing `stringp()` guard" case per this
project's own §10.7 scope boundary -- independent of whatever the
correct answer turns out to be on the separate, genuinely-uncertain
question §12 already flagged (whether non-wizards are meant to have
real filesystem-navigation commands at all in this lib's design, which
this fix does NOT attempt to resolve either way).

Fixed with a narrow guard in `do_ls()`, added right after path
resolution:
```lpc
if( !stringp(dir) )
  return write("ls: unable to resolve current directory.\n");
```
This only changes the failure mode from a raw driver crash to a clean
one-line message; it does not touch `wizardp()` gating, ACL behavior,
or grant non-wizards any new capability. Verified live: fresh
non-wizard registration (`morgan`) hit the exact same code path
post-fix and got the clean message instead of a crash;
`log/errors/runtime` did not grow (stayed at 413 lines, unchanged from
before the test); `log/debug` stayed warning-only. `morgan`'s test save
was deleted before committing, along with a leftover `testuser.o`
save/connection pair from the original onboarding pass (§1-11) that
had never been cleaned up -- `root` remains the only saved account.

The other wiz-only file commands sharing the same
`RESOLVE_PATH`/`file_size()` shape (`rm`, `rmdir`, `cp`, `mv`, `du`,
`cat`, `head`, `tail`, `more`, `touch`) all require an explicit
filename/path argument rather than defaulting to the bare, no-arg
`do_ls(0, ...)` shape that triggers this specific crash, and an
absolute path argument bypasses `query_cwd()` entirely -- not
independently re-verified live one by one this pass, but flagged here
in case a future relative-path-as-non-wizard test surfaces the same
shape elsewhere in this file family.
