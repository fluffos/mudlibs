# Mortal Remains -- porting notes

Source: `git clone https://github.com/clockworksoul/MortalRemains` (commit
`3e9c6a98f9f78629d6e693570f698a043be634d2`, cloned 2026-08-26). The
repo's own `README.md` is a short first-person note from "Cyanide", the
mud's original admin, releasing the code into the public domain: "Mortal
Remains was based on the TMI-2 mudlib version 1.4 alpha." Confirmed
genuine and sizeable before investing further effort: 13,515 files,
85MB raw, real multi-year (1997-2000) wizard-authored content across
dozens of home directories, a real historical `log/runtime`/`log/log`
with entries dated back to 1999-2000, and archived player save data
(`.o` files) for real accounts from that era. Slug `mortremains`,
number 929, port 40231.

## 1. Two subtrees excluded/noted before conversion

- **`lima-1.0a8/`** (top-level sibling of `1.4alpha/`): a completely
  separate, self-contained mudlib (the Lima mudlib) with its own
  `lib/`, `etc/config.lima`, driver-build scaffolding. Nothing under
  `1.4alpha/` references it (confirmed by grep). Excluded from
  `raw/`/`work/` entirely before running `convert_lib.sh`, matching
  this project's convention for bundled-but-unrelated codebases.
- **`adm/AFD/`** (~870 files, inside the real mudlib root): a
  completely orphaned, self-contained alternate object-system snapshot
  (its own `body.c`, `room.c`, `object/prop_logic.c`, etc., with its
  own `attic/`/`old/` subdirectories) that nothing anywhere else in the
  live tree inherits, includes, or references (confirmed: `grep -l
  "adm/AFD"` across the rest of the tree returns zero hits). Left in
  place, undocumented as dead weight -- not deleted, not fixed. This
  subtree alone accounts for roughly a third of the compile sweep's
  remaining failures (515 of ~3287 in the first pass); none of it is
  reachable from the live game.

## 2. Conversion

Pure ASCII archive (English-language mud) -- confirmed via a
pre-check (`grep -rlP '[\x80-\xFF]'` found zero non-ASCII source
files) before running `convert_lib.sh`, so the encoding step was a
no-op as expected. 7928 `.lpc` files after the `.c`->`.lpc` rename;
9208 literal `.c"` references fixed; 284 local angle-bracket includes
converted to quotes; 214 files touched by the `static`->`nosave`
sweep. One collision from the `static`->`nosave` sweep, per AGENTS.md
\S4.3's known class: `u/l/lysander/workroom.lpc` had a `"static":
"..."` mapping key (a help-topic word, not a path) that the sed
rewrote to `"nosave":...`; reverted by hand. No `#define nosave
static`/`#define protected static` compatibility-shim collision found.
All headers resolve through a single global `/include/` directory (no
`<local.h>`-style per-directory includes anywhere in this codebase),
so no `get_include_path()` master apply was needed.

## 3. The master-boot-blocking crash: `explode("/", "/")` returns an
   EMPTY array on this driver, not MudOS's two empty strings

The single highest-impact bug in this port, and the hardest to
diagnose -- a completely silent crash with no error text printed
anywhere, discovered only via `gdb --batch -x 'catch throw' -x run`.

Boot got as far as compiling master.lpc and simul_efun.lpc cleanly
(warnings only), then aborted with just:

```
The simul_efun (/adm/obj/simul_efun) and master (/adm/obj/master) objects must be loadable.
Please check log files for exact error.
```

...with genuinely nothing else in `debug.log`, `log/runtime`, or
stdout -- the driver's own `mudlib_error_handler` path apparently
swallows the underlying error text when it fires this early in boot
(worth a look for whoever hits this again, but not investigated
further here since the crash itself was fully diagnosed another way).
A gdb backtrace on the C++ exception throw nailed it exactly:

```
#1  error_handler (err=0x... "*Array index out of bounds.\n")
#2  error (fmt=0x... "Array index out of bounds.\n")
...
#5  apply_master_ob (fun=5 [APPLY_DOMAIN_FILE], num_arg=1)
#6  set_master (ob=...)
```

`set_master()` (part of the driver's `PACKAGE_MUDLIB_STATS`
bootstrap, called from `init_master()` the moment `master.lpc` first
loads) calls `master->domain_file("/")` to establish the backbone
domain name. `master.lpc`'s `domain_file()`:

```lpc
string domain_file( string filename )
{
    string *path;
    path = explode( filename, "/" );
    if( !path ) return "NONAME";
    switch( path[0] )        // <-- crashes here for filename == "/"
    { ... }
}
```

The original TMI-2 authors clearly wrote this expecting old MudOS's
`explode("/", "/")` to return `({ "", "" })` (or at least some
non-empty array) -- `path[0]` would then safely be `""`, falling
through to `default: return "NONAME";`. This driver's sane-explode
semantics instead return a genuinely **empty** array for that input,
so `path[0]` throws `Array index out of bounds.` immediately, before
`master_ob` is even fully live, aborting the whole boot. `author_file()`
has the exact same latent defect (same `if (!path) return...` guard
that never checks `sizeof(path)`), though it happens not to be
reachable with an empty-array input from this driver's own bootstrap
call (it's invoked with the master file's own path, which always
explodes non-empty). Fixed both defensively:

```lpc
if( !path || !sizeof(path) ) return "NONAME";
```

This is the same underlying "SANE_EXPLODE_STRING empty-array edge
case" bug class flagged in this project's general checklist, just
hitting a master-apply chokepoint instead of ordinary mudlib code, and
therefore fatal to the entire boot rather than a single feature.

## 4. `ref` is a reserved word on this driver (`__REF_RESERVED_WORD__`)

Confirmed via the compiler source (`lexer_utils.cc`: `{"ref", L_REF,
0}`) and this driver's own advertised feature list
(`__REF_RESERVED_WORD__` in its startup dump) before touching
anything. Four sites used `ref` as a plain identifier (parameter or
local variable name):

- `adm/daemons/channels.lpc` (**preloaded**) -- `object ref` parameter
  to `create_channel()`, plus a local `object ref;` in
  `register_channel()`. Renamed to `refob`.
- `adm/daemons/ref_d.lpc` -- `string ref;` local in `resolv_ref()`.
  Renamed to `refname` (only the identifier; the quoted string key
  `"ref"` used elsewhere in the same function via
  `this_player()->query("ref")` is untouched, since that's genuinely a
  property name, not the reserved word).
- `cmds/file/_changelog.lpc` -- `void pop_coder(int ref)`. Renamed to
  `refidx`.
- `u/c/cyanide/working/channelsFE.lpc` -- a personal wizard-sandbox
  draft copy of `channels.lpc` with the identical bug shape; fixed for
  consistency even though it's not reachable from anything live.

`cmds/object/_ref.lpc` (a genuine "ref" command implementation) was
checked and does NOT hit this bug -- it only uses `ref_name` and the
quoted string `"ref"`, never a bare `ref` identifier.

## 5. `inherit` textually after global variables -- four independent
   instances, one with severe cascading impact

The classic \S6.1 dialect bug ("Illegal to inherit after defining
global variables"), but this codebase has it as a **recurring
authoring habit** rather than a single shared-header bug -- found
independently in at least 4 completely unrelated files, plus ~200
more scattered across individual non-preloaded personal content files
(see \S8 below):

- **`adm/daemons/rebootd.lpc`** (**preloaded**) -- `int count_down =
  28800;` before `inherit TIME_D; inherit DAEMON;`. Reordered.
- **`adm/daemons/registryd.lpc`** -- `int active = INACTIVE; mapping
  reg_map = ([]);` before `inherit "/adm/daemons/timezone";`. This one
  is called (unguarded) from `logind.lpc`'s very first `get_name()`
  handler on every login attempt (`REGISTRY_D->query_active()`), so a
  broken `registryd.lpc` meant **every single connection attempt**
  crashed with `*No program in object '/adm/daemons/registryd'!` the
  instant a name was typed. Reordered.
- **`std/monster.lpc`** -- `object tmp; nosave int speed, hb_status;`
  before `inherit LIVING;`. **The single biggest compile-sweep win in
  this port**: `std/monster.lpc` is the universal NPC/monster base
  class (every mob, animal, and non-player creature in the entire
  ~13,500-file archive ultimately inherits it), so this one fix
  resolved **1770 of the ~3287** first-pass compile failures in a
  single edit -- a textbook instance of AGENTS.md \S6.4's "one shared
  root cause, not N bugs." Reordered.
- **`d/Ancients/rooms/wizrm.lpc`** -- `object maker;` before `inherit
  ROOM;`. This is "The Immortal's Hall", the room every *promoted
  wizard* lands in on login (distinct from the ordinary player start
  room) -- a broken copy meant every wizard login crashed with `*No
  program in object '/d/Ancients/rooms/wizrm'!` right after the news
  screen, immediately followed by a secondary `*Bad argument 3 to EFUN
  message()` from the failed move. Only surfaced once the admin
  account was actually promoted to wizard and logged back in (see \S7)
  -- ordinary player accounts never touch this file. Reordered.

## 6. `std/user/tsh.lpc`: `private inherit` + qualified super-call
   (`Name::func()`) is rejected by this driver even from the SAME
   file that declared the private inherit

A new driver-dialect finding for this project's catalog. `tsh.lpc`
does `private inherit STACK_ADT;` (a directory-stack push/pop/query
ADT) and then, from **within its own `pushd()`/`popd()`/`dirs()`/
`initialize_tsh()` functions**, calls the base class's functions via
the qualified super-call syntax: `stack::push(path)`, `stack::pop()`,
`stack::query_stack()`, `stack::alloc(pushd_size)`. This is the
idiomatic way to reach a privately-inherited base's functions and
compiles fine on many LPC drivers -- but this driver's compiler
(`compiler.cc`'s function-lookup logic) rejects ANY qualified
`Name::func()` call to a function whose inherit was declared
`private`, unconditionally, with no special case for "the caller is
the very file that declared the private inherit":

```cc
if (tmp == -1 || (ip->type_mod & DECL_PRIVATE)) {
  yyerror("Called function is private.");
  goto invalid;
}
```

Confirmed by compiling `tsh.lpc` standalone (not just as part of a
larger inheritance chain) -- identical 4 errors either way, ruling out
any interaction with how `tsh.lpc` itself later gets inherited into
`std/user.lpc` via `include/user.h`. Fixed by dropping the `stack::`
qualifier -- privately-inherited functions remain directly (unqualified)
callable from within the declaring file on this driver, so `push(path)`,
`pop()`, `query_stack()`, `alloc(pushd_size)` resolve correctly without
the qualifier. (A separate, pre-existing dangling reference in the same
file -- `history::hist_alloc(hist_size)`, where no `HISTORY_ADT` is
ever inherited at all -- was investigated and left alone: this driver
does NOT flag it as a compile error at all for reasons not fully
tracked down, and a code comment in the same block ("According to Beek,
the next 2 lines should go, but that kills history completely") shows
the original authors already considered this code suspect; not a
driver-compat blocker either way, so left as pre-existing dead-ish
content per policy.)

## 7. Master's `valid_write()`/`valid_read()` bare-equality fallback
   never matches the driver's extension-appended filename (\S7.49)

Exactly the catalogued bug class. `master.lpc`'s `valid_write()`/
`valid_read()` fall back to `file == data_file(user) ||
file == user_data_file(user)` when the group/path-based ACL doesn't
otherwise grant access -- but `data_file()`/`user_data_file()` both
return the BARE path (no extension), while this driver's
`save_object()`/`restore_object()` efuns pass the FULL filename
(`.o` already appended) to the master apply. The two never matched,
so **every player's own save silently failed ACL** the moment a real
save fired. This didn't show up at boot or at `look`/`score` -- it
first fired at the password-confirmation step of brand-new character
registration (`std/connection.lpc`'s `set("password", ...)` triggers
an autosave via `save_data_conn()`), with the exact symptom AGENTS.md
predicts: `*Denied write permission in save_object().` Fixed both
functions:

```lpc
return( file == data_file( user ) || file == data_file( user ) + ".o" ||
  file == user_data_file( user ) || file == user_data_file( user ) + ".o" );
```

## 8. THE most severe bug: `exec()`'s ACL wrapper's `deep_inherit_list()`
   check silently denied EVERY new character's connect(), forever

The single most severe bug found in this port -- it silently blocked
**100% of new character registrations** from ever completing, with no
compile error, no crash, and no log entry of any kind; only a generic
mudlib message ("Error connecting to your body... try again...") that
looked at first glance like ordinary content/flavor text.

`std/connection.lpc`'s `connect()` (called as the very last step of
character creation, from `newuserd.lpc`'s `finish_up3()`) does:

```lpc
if (!exec(body_ob, this_object())) {
    write("Error connecting to your body... try again...\n");
    body_ob->remove();
    remove();
    return 0;
}
```

`exec` here isn't the raw driver efun -- it's shadowed by a mudlib ACL
wrapper in `adm/simul_efun/overrides.lpc`:

```lpc
nomask int exec(object to_obj, object from_obj) {
    ...
    New = base_name( to_obj );
    if( New != CONNECTION && member_array("std/body.lpc",
        deep_inherit_list( to_obj ) ) == -1 )
        return 0;
    ...
}
```

The intent is clear: allow `exec()` onto the player's own connection
object, OR onto anything that inherits `std/body.lpc` (i.e. a real
player body). But this driver's `deep_inherit_list()` efun
(`array.cc`) always prepends a leading slash to every returned program
name (`add_slash(pr->filename)`), returning `"/std/body.lpc"` --
never the bare `"std/body.lpc"` the mudlib code checks for. Since
`body_ob` for a brand-new character is never itself equal to
`CONNECTION`, this `member_array()` call ALWAYS returned `-1`, and
`exec()` ALWAYS returned `0` -- **every single new character's
connect() failed**, `body_ob` and the connection both got destructed,
and the game silently dropped the player with a plausible-sounding
"try again" message that, if actually retried, would fail exactly the
same way every time.

Diagnosed by temporarily instrumenting `connect()` to print
`interactive(this_object())` / `interactive(body_ob)` / the literal
return value of `exec()` (confirmed: both preconditions for a
*successful* `exec()` held -- `this_object()` interactive, `body_ob`
not yet interactive -- yet `exec()` still returned `0`), which ruled
out the driver's own `exec()` efun and pointed straight at a mudlib
override; `grep -n "^int exec\|nomask int exec"` then found it in one
shot. Fixed the one-line string comparison:

```lpc
if( New != CONNECTION && member_array("/std/body.lpc",
    deep_inherit_list( to_obj ) ) == -1 )
    return 0;
```

Verified with a fresh full registration end to end (see \S10) --
character creation completes, `connect()` succeeds, the new player
lands in the real game world instead of being silently dropped.

## 9. Smaller fixes

- **`AVERAGING_NUM.0` float-promotion dialect** (\S6.3's catalogued
  class) -- `adm/daemons/usage_d.lpc` (**preloaded**) and its
  near-identical twin `adm/daemons/usage_i.lpc`, both `if (times ==
  AVERAGING_NUM.0)`. Rewritten as `(AVERAGING_NUM * 1.0)`.
- **`TYPE array NAME` old-MudOS declaration dialect** -- 5 sites in
  `u/c/cyanide/public_html/cgi/autodoc.lpc` (a wizard's personal
  web-CGI handler object, real LPC despite living under
  `public_html/`), e.g. `string array commands = get_dir(...)`.
  Rewritten as `string *commands`.
- **Undefined variable `k`** (pre-existing author typo, not a
  conversion artifact) -- `std/body/attack.lpc`'s `output_attack()`
  has TWO near-identical `for` loops over `contents`; the first
  correctly declares `for (int k=0; ...)`, the second just says `for
  (k=0; ...)` with no type, so `k` was never declared in that scope.
  Fixed by adding `int`.
- **`std/private_room.lpc` (+ 10 near-identical copies across wizard
  homes) -- `void`-declared functions whose bodies use a macro that
  unconditionally returns a value.** `CHECK_PROT(n)` expands to `if
  (check_prot(this_player(), n)==0) return 1;`; six functions
  (`guest_add`/`guest_ban`/`guest_remove`/`guest_unban`/`guest_list`/
  `guest_help`) use this macro but were declared `void`, producing
  `error: Type of returned value doesn't match function return type (
  int vs void )` -- 6 sites x up to 11 independently-copy-pasted files
  (`std/private_room.lpc`, `std/attic/private_room.lpc`, and personal
  `workroom.lpc`/`lroom.lpc`/`wrkrm.lpc`/`wrkrm2.lpc` copies belonging
  to `chronos`, `cyanide`, `zur`, `kyako`, `ashdraven` (x2), `gasman`,
  and `dyrin`'s attic (x2)) for 639 raw error lines total. Verified all
  11 copies share the exact same six-function shape before applying a
  uniform, `libs/mortremains/work`-scoped sed to all of them (fixed
  9/11 outright; the two `wrkrm2.lpc` copies -- `ashdraven`'s and
  `dyrin`'s attic copy -- still fail for a separate, pre-existing,
  unrelated reason, see \S11). Fixed by changing the six functions'
  declared return type from `void` to `int` (both the forward
  prototypes and the definitions) -- their return value was already
  effectively meaningful (via the macro) and universally ignored by
  every caller either way, so this changes nothing observable.

## 10. Admin account seeding

Registered `fluffos`/`Mud@2026` through the real, full registration
flow (name -> confirm -> password -> confirm password -> email -> real
name -> stat/race/gender/alignment menu -> "done" -> confirm) exactly
like any other new character, landing in the real starting room (The
YMAA, Decatur) with `look`/`score`/`who` all producing correct output,
then a clean `quit` that closes the connection.

Granting admin here needed **two separate, independent steps**,
neither of which alone was sufficient -- worth recording since this is
a new bug-class shape for this project's \S1.5 catalog:

1. **File-permission ACL** (`adminp()` / write access): this codebase
   gates `adminp()` through `master()->query_member_group(name,
   "adminaccess")`, backed by the DATA file `adm/etc/groups`
   (`(adminaccess)    (admin):spooner`). Added `fluffos` to that line
   (`(adminaccess)    (admin):spooner:fluffos`) -- this alone grants
   full read/write ACL everywhere (`adm/etc/access`'s `(/)` line
   grants `(adminaccess)[rw]`), confirmed live via `update <path>`.
2. **Wizard command-set / rank flag**: file-permission ACL is
   completely separate from whether the *in-game command dispatcher*
   ever offers wizard commands at all. That's gated by a `wizard`
   property on the CONNECTION save object (checked by
   `std/body.lpc`'s `init_setup()`: `if ((int)(link->query("wizard")))
   { set("wizard", 1, MASTER_ONLY); enable_wizard(); }`, called on
   EVERY login via `logind.lpc`'s `enter_world()` -> `user->BODY_OB->
   setup(0)` -> `init_setup(0)`, not just first-time creation) plus the
   body's own `PATH` property (which command directories are
   searched). The mudlib's own normal promotion path
   (`cmds/adm/_makewiz.lpc`) requires an ALREADY-active admin to run
   it in-game -- but the archive's only pre-existing admin accounts
   (`cyanide`, `chronos`) have real, unknown 1999-era passwords, and
   `AUTO_WIZHOOD` (a global "everyone who registers becomes a wizard"
   switch) is `#define`d then immediately `#undef`ed in `config.h`
   (deliberately disabled by the original authors -- flipping it back
   on would be a content/behavior change affecting every future
   registration, out of scope here). Instead, replicated exactly what
   `_makewiz.lpc` itself does, directly on the save DATA: appended
   `wizard 1` to `data/std/connection/f/fluffos.o`, and in
   `data/std/user/f/fluffos.o` changed the body's saved
   `"wizard":0` to `"wizard":1` and `"PATH":"/cmds/std"` to
   `"PATH":"/cmds/std:/cmds/object:/cmds/xtra:/cmds/file:/cmds/wiz"`
   (the exact `NEW_WIZ_PATH` macro value `_makewiz.lpc` would have
   assigned). Verified live end to end on the NEXT login (not the same
   session): wizard news section appears, `who` shows the `[NEO]`
   alignment marker, login correctly routes to "The Immortal's Hall"
   (the wizard start room, itself needing the \S5 `wizrm.lpc` fix to
   even load), and `update /std/room` succeeds with "Updated and
   loaded." -- this project's canonical read+compile ACL smoke test.

## 11. Compile sweep results and known remaining gaps

`lpcc_check.sh`'s full batch sweep, after the fixes above: **6246
pass / 1682 fail** out of 7928 total `.lpc` files (78.8% pass rate).
Given this archive's real composition -- an entirely orphaned ~870-file
dead subtree (\S1) plus roughly 13,000 files of genuine, messy,
multi-author 1997-2000 wizard-home content including abandoned drafts,
truncated experiments, and personal scratch files -- this is
consistent with (proportionally messier than, but the same *kind* of
gap as) the handful of non-boot-critical failures documented on
smaller, cleaner archives elsewhere in this collection. None of the
remaining failures are preloaded or reachable from the standard
registration/gameplay path exercised in \S10. Breakdown of the
remaining 1682:

- **~515 attributable to `adm/AFD/`** (\S1) -- entirely dead, orphaned
  code, not investigated further.
- **~200 more scattered instances of the \S5 "inherit after global
  variables" bug**, now diffuse across individual non-preloaded
  content files (personal monsters/spells/rooms/items) with no single
  file responsible for more than 5 occurrences -- the shared-root-cause
  phase is exhausted (per AGENTS.md \S6.4's own guidance: fix the
  *shared* causes, don't blindly bulk-fix scattered per-file instances
  in a 13,000-file archive). Left as a known, mechanically-identical,
  low-priority content gap.
- **Missing headers, truncated files, and genuinely abandoned/dead
  experiments scattered across personal wizard homes** (`u/*/`) --
  e.g. `#include shit.h`, `#include /players/jyd/lib/strings.h`
  (a path from a different, unrelated mud entirely), a wizard's own
  `.plan.lpc`/`plans/plan76453.lpc` scratch files. Per this project's
  policy, not fabricated or fixed -- these predate this port and are
  not driver-compat issues.
- **Two `wrkrm2.lpc` copies** (`u/a/ashdraven/rooms/wrkrm2.lpc` and
  `attic/dyrin/rooms/wrkrm2.lpc`) still fail after the \S9 CHECK_PROT
  fix, for an unrelated, pre-existing reason (`warning: Non-void
  functions must return a value` at a bare `return;` in an
  `int`-returning function, present in the ORIGINAL archive before any
  of this port's edits) -- confirmed via the pre-fix sweep log that
  this was already a separate failure mode on these two files
  specifically (their `wrkrm.lpc` siblings in the same two home
  directories compile clean). Not investigated further; personal,
  non-preloaded, non-boot-critical content.
- **A pre-existing, cosmetic author bug in `cmds/object/_update.lpc`**
  (the wizard `update` command itself): `if(extract(file,
  strlen(file)-2, strlen(file)-1) != ".lpc") file += ".lpc";` compares
  a 2-character slice against a 4-character literal, so the condition
  is ALWAYS true and `.lpc` gets appended even when the caller already
  included it (`update /std/room.lpc` -> looks for
  `/std/room.lpc.lpc`, "does not exist"). Harmless in normal use since
  players conventionally omit the extension (`update /std/room` works
  correctly, verified in \S10); left alone as original-author content,
  not a driver-compat issue.

## 12. Genuine outbound network connection at boot -- do not sweep into
    automated reboot loops

`adm/daemons/channels.lpc` (**preloaded** by default) calls
`I3_DAEMON->query_chanlist()` from its own `create()`, which
auto-loads `adm/daemons/network/I3.lpc`. That file's `create()`
unconditionally does:

```lpc
router_socket = clone_object(SOCKET, SKT_STYLE_CONNECT_M,
                             I3_ROUTER, (: read_callback :),
                             (: close_callback :) );
```

`I3_ROUTER` is `"205.218.122.131 9000"` -- a real, hardcoded public IP
from the Intermud-3 network circa 1999-2000 (almost certainly long
dead by now, but the attempt itself is real and unconditional on
every boot; a live `ss`/`ping` check during this port's own test boots
found no established connection or SYN-SENT socket, consistent with
that address being unreachable today, not with the mudlib refraining
from trying). Also opens a local **listening** socket on `__PORT__ +
3` (40234 for this port assignment) for `OOB_TCP`. This is genuine,
intended upstream functionality (the same class of finding as `imud`
and `dsI` elsewhere in this collection), not a bug to patch away -- but
per this project's established convention, **`mortremains` should not
be swept into high-frequency automated re-boot/deep-test loops** the
way most of this corpus safely can be, since each boot is a real
outbound network event, even if the far end is currently unreachable.

## 13. Verification performed

- Full clean boot with zero fatal errors, `Initializations complete.`
  reached, driver idles normally in its event loop (confirmed by
  letting a `timeout` SIGTERM catch it mid-`epoll_wait`, not mid-crash).
- A brand-new character (`Fluffos`) registered end to end through the
  REAL menu-driven creation flow (name, confirm, password, confirm
  password, email, real name, stat-reroll/race/gender/alignment menu,
  "done", confirm) -- landing in the real starting room (The YMAA,
  Decatur), not a void or error state.
- `look`, `score`, `who`, and a clean `quit` (server closes the
  connection) all verified producing correct, well-formatted output
  post-login.
- Admin account (`fluffos`/`Mud@2026`) verified on a SEPARATE, later
  login: wizard news section, `[NEO]` marker in `who`, correct routing
  to the wizard start room, and `update /std/room` succeeding
  ("Updated and loaded.") -- this project's canonical read+compile ACL
  smoke test.
- `log/debug.log` and `log/runtime` (the latter a real historical file
  dating to 1999-2000, confirmed via `stat` that this port's own test
  sessions never appended to it once the fixes above landed) both
  clean of any new fatal errors across every verification pass above.
- Outbound-network check performed (\S12) -- no established connection
  found live, but the code path and hardcoded target address are real
  and documented regardless.
- WASM status: not attempted (`wasm_status` left `""` per task scope).

## 深度功能测试 / Deep functional test (round two, AGENTS.md \S10.7)

First real *playthrough* pass on this lib (the onboarding session above
only verified registration + `look`/`score`/`who`/`quit` + the admin
promotion). Read `help newbie` first (points at "the fellow in the
center of town" for starter equipment/leaflet/map, and `help classes`
names Alucard at the Intersection as the class-hall directory), then
played a full, continuous session as a real English-named character
(`Bramwell`) on the native driver, using a second admin connection
(`fluffos`/`Mud@2026`) only for `update`s and diagnosis. Found and
fixed four independent, severe, live-blocking bugs plus one duplication
bug -- collectively the newbie helper, ~95% of ordinary room-to-room
movement, and two of the five advertised class halls were all
unreachable before this pass, none of it visible to `lpcc_check.sh`,
a clean boot, or the earlier registration-only smoke test.

### 1. `cmds/std/_go.lpc`'s extension-check slice is 2 characters, not 4 -- blocks essentially every ordinary room exit whose destination path literal already includes `.lpc`

The single most severe bug found in this pass. `cmd_go()` (the
function underlying every directional movement command -- `north`,
`east`, etc. all alias to `go <dir>`) does:

```lpc
fn = exits[dir];
if (fn[<2..<1] != ".lpc") {
    fn += ".lpc";
}
if (file_exists(fn)) {
    to = find_object_or_load( exits[dir] );
    ...
```

`fn[<2..<1]` is only the LAST TWO characters of the path, which can
never equal the 4-character string `".lpc"` -- so the append always
fires. If the room author's own `exits` mapping literal already ends
in `.lpc` (confirmed the overwhelming majority convention in this
archive: 4597 grepped exit-value literals include `.lpc` explicitly,
vs. 225 that don't), `fn` becomes a doubled `...lpc.lpc` path that
`file_exists()` correctly reports as missing, so `cmd_go()` prints
"The mists of creation are still active in that direction" and the
move silently fails -- indistinguishable from an actually-unbuilt
room. Reproduced live: moving `east` from the very first room
(`startroom.lpc`'s only non-wizard-gated exit, to
`d/Prime/Central/room/road0_0.lpc`, the Intersection) failed this way
immediately after registration; `south` from the same room happened to
work only because it points at `WIZHALL` (`/d/Ancients/rooms/wizrm`,
no `.lpc` suffix in the macro) and is wizard-gated besides, which is
exactly why this was invisible to the earlier onboarding pass (it
never actually walked a second room).

This is very likely a **port-introduced regression, not a pre-existing
1997 bug**: the archive's real extension was `.c`, and this project's
own `convert_lib.sh` does a blanket literal `".c"`->`".lpc"` string
rewrite as a normal part of conversion (per \S2 above, "9208 literal
`.c\"` references fixed"). The original line was almost certainly
`fn[<2..<1] != ".c"` -- a correct 2-character check against the
original 2-character extension -- and the automated rewrite updated
the string literal but had no way to know it also needed to update the
slice-length arithmetic next to it. This is the exact bug class
catalogued in AGENTS.md \S7.118 ("hardcoded 2-character-extension math
left over from the archive's original naming"), just manifesting as an
"always append a redundant extension" checking bug rather than that
section's "always corrupt a derived key" stripping bug -- worth adding
to that section's watch-list shape. (A cosmetically-identical but
functionally harmless sibling of this exact slice-vs-literal-length
mismatch was already documented pre-existing in this same lib's own
\S11, in `cmds/object/_update.lpc` -- that one predates conversion and
never bit because players conventionally omit the extension when
typing `update`.)

**Fix**: `fn[<2..<1]` -> `fn[<4..<1]` (the last 4 characters,
correctly matching the 4-character `.lpc` string). Verified live:
after `update /cmds/std/_go`, `east` from the Intersection correctly
loaded and entered `road0_0.lpc`, and the entire pit-fighter-guild
navigation route below (10 more moves) worked cleanly end to end.

### 2. Newbie-helper NPC `u/c/chronos/alucard.lpc` -- and, as a direct consequence, the room that clones him -- both failed to load at all

`Alucard` is the exact NPC `help newbie`/`help classes` point players
at for starter equipment and class-hall directions, cloned into
`d/Prime/Central/room/road0_0.lpc` ("the Intersection", one room east
of the start room) via `reset()`. His file has the classic \S5
"inherit after global variables" defect (`string *PUNC;` declared
before `inherit MONSTER;`), the exact same bug class as 4 other
individually-fixed instances documented in \S5 above. What's new here:
because `road0_0.lpc`'s own `create()`/`reset()` calls
`clone_object("/u/c/chronos/alucard.lpc")`, and this driver propagates
an inherited file's compile error up through the caller, **the room
itself failed to compile and load** (confirmed identical in
`lpcc_fail.log`) -- so this one `inherit`-ordering typo alone took out
both the newbie helper AND the entire Intersection room (compounding
with bug \S1 above, since bug \S1's "mists of creation" symptom was
the FIRST thing masking this one until \S1 was fixed and `east`
actually attempted to load the destination).

**Fix**: moved `inherit MONSTER;` above `string *PUNC;` (same pattern
as \S5). Verified live end to end: after `update`ing both the file and
the room, `Bramwell` walked east into the Intersection, `Alucard` was
present, `say help` triggered his `process_say()`/`help()` handler,
and he handed over the real starter kit (`boots`, `leaflet`, `bat`,
`armour` clones) exactly as the newbie doc promises.

### 3. Two of the five class halls Alucard advertises had the identical \S5 defect, blocking `join` entirely

`d/class/warrior/pit_fighter/rooms/pitfighterguild.lpc` and
`d/class/warrior/Sharpshooter/room/SS_guild.lpc` -- two independently
copy-pasted files sharing the same header comment ("Pit pit fighter's
guild ilz code ... Cyanide corrupted this room") -- both declare
`mapping skills = ([]); mapping min_levels = ([]); int *v_skills, ...`
before `inherit GUILD;`. Reproduced live: walking the pit-fighter-guild
route Alucard gives ("5 south, 2 east, 2 south, and 1 west" from the
Intersection) hit `*No program in object
'/d/class/warrior/pit_fighter/rooms/pitfighterguild'!` on the final
step. Per AGENTS.md \S6.4/this lib's own \S11 guidance (fix
shared-root-cause bugs found live, don't blanket-sweep the ~200
scattered non-preloaded instances), both were fixed individually since
they sit directly on the newbie class-acquisition path this pass is
meant to exercise -- the other three halls Alucard mentions (mages,
thieves, priests) do NOT have this defect (checked via `lpcc_fail.log`
before touching anything).

**Fix**: reordered `inherit GUILD;` above the global variable block in
both files (same pattern as \S5/\S2 above). Verified live: `Bramwell`
(strength 15, meets the pit fighter's `base_stat/strength >= 10` gate)
successfully `join`ed, title changed to "Cage Cleaner"/"Level 1 Pit
fighter", and received "A Pit Fighter's Scars" (the class marker
item). The Temple of Talos (priest hall, 2e/1s from the Intersection)
was also reached and correctly, gracefully rejected `join` for not
being chaotic evil -- confirming the rejection path itself works fine
and this is content gating, not a bug.

### 4. `d/class/rogue/obj/dummy.lpc` (this lib's own safe-sparring/backstab-testing dummy) had a broken array literal, AND a crash-on-clone bug hiding behind it

This file's own `long` description ("This is a dummy to test you
backstab out on ... type halt to stop your onslaught") makes clear
intent: a zero-risk training target (`execute_attack()` is hardcoded
to always return 0, so it can never actually hurt a player), matching
AGENTS.md \S10.7 point 3's "find the lib's own safe-sparring mechanism"
guidance. It failed to compile at all: `set("damage", ({ 0 )} );` has
`)` and `}` swapped (should be `({ 0 }) )`), cascading into further
spurious errors on every line after it in the same function. Fixed the
bracket swap -- but doing so exposed a SECOND, real bug underneath:
`adm/daemons/catalog_d.lpc`'s `get_level()` (which every wizard
`clone` invocation runs automatically, to register the new monster in
the summoning catalog) does
`counter = ((int *)wep->query("damage"))[1];` -- unconditionally
indexing element 1 of the `"damage"` array. Every other monster in
this codebase sets `"damage"` as a 2-element `({min, max})` array
(confirmed via `alucard.lpc`'s `({3, 30})` and the real combat-damage
code in `std/body/attack.lpc`, which reads both `damrange[0]` and
`damrange[1]`) -- but `dummy.lpc`'s array had only ONE element even
after the bracket fix, so cloning it live threw `*Array index out of
bounds.` (reproduced: `clone /d/class/rogue/obj/dummy` as admin,
confirmed via `/log/runtime`'s stack trace pointing at
`catalog_d.lpc:187` <- `cmd_clone` <- `cmd_hook`).

**Fix**: `({ 0 })` -> `({ 0, 0 })`, matching the universal 2-element
convention and the object's own intent (a target that deals zero
damage either way). Verified live: `clone /d/class/rogue/obj/dummy`
succeeded cleanly after the fix (correctly auto-cataloged, no error),
and a full live fight (`kill dummy`) confirmed the safe-sparring
guarantee end to end -- every one of the dummy's attacks reported
"does nothing to you" while its `receive_damage()` correctly echoed
back each hit's damage ("Dummy screeches: You just did N points of
bludgeoning damage"), with zero crashes and zero risk to the player
across dozens of combat rounds.

(Separately, `dummy.lpc`'s own `long` text tells players to "type halt
to stop your onslaught" -- `halt` is in fact a **wizard-only** command
(`cmds/wiz/_halt.lpc`; no player-facing equivalent exists,
`cmds/std`/`cmds/object` have no `_halt`/`_flee`/`_stop`). An ordinary
player typing `halt` gets a plain `What?`. This is pre-existing 1997
flavor-text content, not something the port touched, and fixing it
would mean either adding a new player command or rewriting the
dummy's documentation -- a content/behavior decision, not a
programming bug, so left alone and just noted here per the task's
scope boundary.)

### 5. Class-marker items ("A Pit Fighter's Scars") permanently duplicate across disconnect/reconnect cycles -- new AGENTS.md \S7.122

Found by accident while doing the required \S10.7 step-5
quit-then-relogin check: `Bramwell`'s `i` after a real quit-and-relogin
cycle showed **five** copies of "A Pit Fighter's Scars" (only one was
ever legitimately granted, via a single `join`). Root-caused and fixed
-- full writeup, including why the fix targets the reload side rather
than reordering the save/destroy calls, is in AGENTS.md \S7.122 (new
entry, since this exact `auto_load`/`compute_autoload_array`/
`destroy_autoload_obj`/`load_autoload_obj` mechanism is verbatim
shared TMI-2 lineage code per its own header credit to "Truilkan@TMI",
and is a plausible sibling-check candidate for any other TMI-2-based
lib in this corpus). One-line summary: `std/user.lpc`'s quit paths
save the character (baking any carried auto-load item into the normal
serialized inventory) before removing that item from inventory, and
`net_dead()` never removes it at all -- so a subsequent full restore
recreates the item twice (once from the leftover inventory data, once
from the separate `auto_load` re-clone list), with no dedup) on either
side. Fixed in `std/user/autoload.lpc`'s `load_autoload_obj()` by
skipping any `auto_load` entry whose `base_name()` already matches an
object already present in inventory. Verified live: a further clean
quit-and-relogin on the already-corrupted `Bramwell` character held
steady at 5 copies (did not grow to 6) after the fix landed --
confirms no further duplication, though the fix does not retroactively
clean up the pre-existing 5 (left as visible evidence on the test
character rather than hand-edited away).

### 6. Currency/economy check (per this pass's mandate to watch for the \S7.121 float-corruption shape)

Checked `std/shop.lpc`, `std/bank.lpc`, `std/coins.lpc`, `std/pub.lpc`,
`std/buy_only_shop.lpc`, `std/container.lpc`, and
`adm/daemons/gang_d.lpc` (every file referencing `credits`/`price`/
`cost`/`gold`) for the \S7.121 shape (a function doing real float
arithmetic but declared to return `int` with no `to_int()`). **Clean**
-- this lib's economy code is plain-integer throughout with no float
arithmetic anywhere in the money path; `std/shop.lpc`'s
`get_ob_value()` in particular already guards every branch
(`intp()`/`mapp()`/`pointerp()` checks) before returning. No instance
of this bug class found.

### 7. Verification performed

- Full continuous playthrough as `Bramwell` (male human, pit fighter):
  register -> `look`/`score`/`i` at the start room -> navigate to the
  Intersection (bug \S1) -> meet Alucard and receive starter equipment
  (bug \S2) -> navigate to the Temple of Talos (correctly, gracefully
  rejected -- content gating, not a bug) -> navigate to the Pit
  Fighter Class Hall (bug \S3) -> `join` (received class marker item)
  -> `score`/`i` confirming the class, title, and item -> live combat
  against the fixed training dummy (bug \S4), including a `score`
  mid-combat showing "is attacking Dummy" state -> `quit` (mid-combat,
  correctly dropped non-wielded unequipped items) -> `debug.log`/
  `log/runtime`/`log/log` grepped clean after every fix and after the
  quit -> reconnected after a real wall-clock gap, confirmed a genuine
  fresh restore (full news splash + "Last logon" banner, not a silent
  same-session reattach) with class/stats/credits all correctly
  persisted -- but also surfaced bug \S5 (item duplication) this way.
- Distinguished the two reconnect variants explicitly per \S10.7 point
  5's own warning: several intermediate reconnects during testing
  showed the bare `Reconnected.\n` single-line response (a live/
  interactive session reattach), while the post-quit reconnect showed
  the full news/banner sequence (a genuine `restore_object()`) --
  confirmed this distinction actually matters for this lib (only the
  latter path is where bug \S5 accumulates further duplicates).
- Shop/economy: code-reviewed only (bug \S6 above) -- did not reach a
  live shop transaction with real gold in this pass; stated explicitly
  as unverified-live per \S10.7 point 6, not silently presented as
  tested.
- Death/respawn: **not reached live** in this pass (budget went to the
  five bugs above instead) -- stated explicitly as unverified-live per
  \S10.7 point 6.
- Admin `update` used to hot-load every fix above without a full
  reboot; each fix's live effect was independently confirmed (a room
  becoming enterable, an NPC appearing and responding, a `join`
  succeeding, a `clone` no longer crashing, a duplicate count no
  longer growing) rather than just trusting a clean recompile.
- Test characters left as evidence: `Bramwell` (pit fighter, the main
  playthrough character, 5 duplicate scars pre-fix visible as
  evidence), plus several earlier fresh-name attempts
  (`Wrenmoor`/`Corvasel`/`Dorrick`/`Halvard`/`Perrin`) left in various
  partial-registration or early-exploration states as ordinary
  incidental test debris from iterating on the navigation script.
- No new fatal errors in `log/debug.log`/`log/runtime`/`log/log` from
  any of the above beyond the ones being actively diagnosed and fixed.
- Driver killed cleanly by exact PID after this pass; no automated
  reboot loop was set up, consistent with \S12's standing caution
  about this lib's genuine outbound I3 connection attempt at boot.

## WASM status audit (2026-09-01)

`playable`. Booted `~/src/fluffos/build-wasm/src` via
`scripts/wasm_client.js` -- clean boot, zero fixes needed; the
preloaded channel daemon's outbound I3 socket-connect attempt (\S12)
fails silently/gracefully under WASM's no-`sockets` build without
affecting anything else. Full session verified: real TMI-2 registration
flow (name, y/n confirm, password + confirm, email, real name, the
1/2/3/4/5/6/0 stat-optimization menu), landing in The YMAA (Decatur),
`look`/`score`/`quit` all correct.
