# Nightmare 4 -- porting notes

Source: `git clone https://github.com/MudRen/nightmare4` (commit
`ad4235d477f9cf7bdc67893fd26d6e6722c39e31`... actually `first commit`
per its single-commit history, cloned 2026-08-26). The repo's own
description: "An influential early lib family. Newly revamped: Unix and
Windows driver included together." Top level bundles a full
`fluffos-2.9-ds2.14` driver source tree, `bin/mudos.cfg`, and
`win32/driver.exe` alongside the actual mudlib -- all ignored per this
project's convention (own driver build at `~/src/fluffos`). Mudlib root
is the repo's `lib/` directory: 1018 raw files, 18MB. Slug `nightmare4`,
number 931, port 40233.

## 0. Confirmed genuinely distinct from `nightmare3`

Before investing effort: `nightmare3` (already in this collection, port
40208) is the `fluffos/nightmare3` fork -- its own Praxis-domain
snapshot. This archive ships a completely different example domain
(`domains/Ylsrim`, a desert bazaar town, vs. `nightmare3`'s
`domains/Praxis`/`Examples`), a different file layout (`lib/std/` for
base object classes, `secure/lib/net/` for a dedicated socket-object
layer that `nightmare3` doesn't have, class-based `Race`/`Class`/
`Season` data daemons), 568 `.lpc` files after conversion vs.
`nightmare3`'s 822, and its own header versioning that alternates
between "Nightmare IV"/"Nightmare IVr2/r3/r6" and "Nightmare V" across
files (incremental in-house revisions, not a rename) -- a genuinely
different generation/snapshot of the same family, not a duplicate.

## 1. Conversion

Pure ASCII archive -- no encoding-normalization work needed.
`convert_lib.sh` renamed 568 `.c` files to `.lpc`, fixed 125 literal
`.c"` references, converted 26 local angle-bracket includes to quotes,
and ran the `static`->`nosave` sweep across 498 files with no
string-literal or `#define nosave static`-shim collisions found.

One file entirely escaped this pipeline: **`secure/lib/connect.real`**
(no `.c` extension, so `convert_lib.sh`'s glob never touched it). This
is real, live LPC source -- the mudlib's own one-time admin-installer
(`secure/lib/connect.lpc`) `cp()`s this file over itself once the admin
account is created, so it becomes the actual live login/registration
object for every subsequent connection. It still had 31 raw `static`
keywords on functions (fixed with the same `\bstatic\b`->`nosave` sed)
and three `TYPE array NAME`/`(TYPE array)` dialect sites (see \S3) that
only surfaced once compiled standalone -- both bugs would otherwise
have surfaced silently, well after this port's own testing, the moment
a real admin install ran on a copy that skipped this manual step. Any
future archive in this collection should be checked for other
non-`.c`-extensioned live source the mechanical pipeline would miss
(`grep -rL` for text files containing `inherit`/`#include` outside
`*.lpc`/`*.h`) -- `secure/sefun/to_object.orig` and a couple of Emacs
`.h~` backups were also found this way but confirmed genuinely dead
(never referenced by any `cp()`/`#include`/`load_object()`), left alone.

## 2. Missing `get_root_uid()`/`get_bb_uid()`/`creator_file()` --
   blocked literally every single object load

The single most severe bug in this port, exactly AGENTS.md \S7.2's
catalogued class but with an extra wrinkle. This driver was built with
`PACKAGE_UIDS`, which makes `set_master()` call `master::get_root_uid()`
and (on first load) `master::get_bb_uid()` -- if either is undefined,
the driver `exit(-1)`s the whole process immediately, with only
`No function get_root_uid() in master object; possibly the mudlib
doesn't want PACKAGE_UIDS to be defined.` printed. `master.lpc` had
neither. Added both as flat stubs (`"Root"`/`"Backbone"`), matching the
identical fix already present in this collection's `nightmare3`
sibling.

That alone was NOT enough: with both defined, `give_uid_to_object()`
(called on **every single object load**, not just at master-boot) then
requires `master::creator_file()` too -- entirely missing here. Every
load silently failed via a `catch()`-swallowed `error()`, so the very
first individual-file compile tests (`/lib/std/room`, `/lib/std/item`)
both "failed to load" with **zero output on stdout** -- only
`log/catch`/`log/runtime` (this mudlib's own separate error log,
written by `master.lpc`'s `error_handler()`) showed the real message:
`*master object: No function creator_file() defined!`. Since this
codebase's actual ACL model is built entirely on `query_privs()`/
`file_privs()` (`check_access()` in `master.lpc`), not on driver-level
uids -- nothing else in the archive ever calls `getuid()`/`seteuid()`
for a real decision (confirmed by grep) -- a flat "everyone is Root"
stub is a minimal, behavior-preserving fix, not a new ownership scheme:

```lpc
string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }
string creator_file(string str) { return get_root_uid(); }
```

`master.lpc` also used `ref` (a reserved word on this driver, \S7.2's
sibling class) as a plain mapping parameter name in
`load_access(string cfg, mapping ref)`/`ref[fl] = ...` -- the exact
class documented for `mortremains` earlier this session. Renamed to
`refmap` (3 sites: the `.h` prototype, the definition, and the one use).

## 3. The pervasive `.c`->`.lpc` filename-slice bug -- this driver
   build's whole command/verb/help dispatch architecture assumes a
   2-character extension

Exactly the bug class flagged before starting this port (previously
found in `sunshadow`'s `daemon/command.lpc`), except here it is not one
isolated instance but the **dominant recurring pattern across this
entire codebase's dispatch machinery** -- Nightmare's command daemon,
verb daemon, spell-casting daemon, help-index daemon, room/door
`ResolveObjectName()`, `update`/`clone`/`create`/`showtree` (wizard file
commands), and inventory-key normalization all independently reimplement
"strip the trailing extension" using either:

- an unconditional `file[0..<3]` (assumes exactly a 2-character
  extension, i.e. `.c`) -- silently produces `"look.l"` instead of
  `"look"` once files are 4-character `.lpc`; or
- a guard-then-strip pair, `if (file[<2..] == ".c") file = file[0..<3];`
  -- `convert_lib.sh`'s own literal-`.c"`-reference fix (correctly)
  rewrites the quoted `".c"` to `".lpc"`, but leaves the **numeric
  slice widths untouched**, so the guard's 2-character `file[<2..]`
  comparison against the now-4-character `".lpc"` literal can never be
  true again -- the strip silently stops firing at all, leaving the
  full `.lpc` extension baked into every derived command/verb name.

Both shapes are equally fatal, just failing in opposite directions (one
corrupts the name, the other leaves it un-stripped) -- either way every
command lookup, verb lookup, spell-cast, and help-topic match breaks
silently, with no compile error and no crash. Root-caused via a direct
compile of `/daemon/command` (the file `/lib/lib/command.c`'s
`cmdAll()` calls into for every ordinary player command) once the \S2
fix let objects load at all. Swept the whole corpus for this shape
(`grep` for `\[0\.\.<3\]` and `[<2..] ==/!= ".lpc"`) and fixed every
site by widening the arithmetic from a 2-character to a 4-character
extension (`[0..<3]`->`[0..<5]`, `[<2..]`->`[<4..]`, and the
accompanying `strlen(x) > 2` guards to `> 4`):

`daemon/command.lpc` (command-name dispatch, unconditional -- the most
severe: every ordinary command in the entire mudlib routes through
this), `daemon/verbs.lpc` (2 sites: verb registration + reload),
`daemon/help.lpc` (4 sites: the index-builder closure plus 3 more
inline slices, and a guarded `topic` normalizer), `lib/detect.lpc` (2
sites, spell-cast verb matching), `lib/enter.lpc` and `lib/exits.lpc`
(`ResolveObjectName()`, identical in both), `lib/props/inventory.lpc`
(`SetInventory()`'s key normalizer), `secure/cmds/creators/update.lpc`
(2 sites: the wizard `update` command's own extension-append AND
extension-strip, the append side previously **always** true post-
rename -- `update /std/room` would have looked for
`/std/room.lpc.lpc`), `secure/cmds/creators/create.lpc`,
`cmds/creators/clone.lpc`, `secure/sefun/to_object.lpc`, and
`cmds/creators/showtree.lpc`. `lib/history.lpc:118`'s superficially
similar `neu[<2..] == "/g"` / `neu[0..<3]` was checked and confirmed
unrelated (stripping a 2-character `sed`-style `/g` flag suffix from a
user-typed regex, not a filename) -- left untouched.

## 4. Old-MudOS `TYPE array NAME` declaration dialect -- systemic, not
   an isolated slip

This codebase's actual house style writes every array-typed
declaration as two words (`string array foo`, `mixed array bar...`)
rather than `string *foo` -- 376 sites across 109 files, both for
function return types/parameters and local variable declarations, plus
a `class X array` variant (structs-of-arrays) that a plain
`(string|int|...) array` regex misses. Swept mechanically: every
`(string|int|object|mixed|float|mapping|buffer|function)\s+array\b` ->
`\1 *` (one false positive reverted: a string literal in
`lib/events/dig.lpc`'s own error message, "...or mixed array, Got:
..."), plus the two `class NAME array` sites by hand
(`lib/body.lpc`'s `GetMagicProtection()`, `secure/daemon/finger.lpc`'s
`Marriages`). The same dialect resurfaced in `secure/lib/connect.real`
(\S1, escaped the mechanical sweep entirely) as both a declaration and
two `(string array)` casts on `RACES_D->GetRaces(1)`.

## 5. `TYPE * a, b;` -- the `*` binds to the first declarator only

The other half of AGENTS.md's general \S6.3 catalog, found repeatedly:
old code intends every comma-separated name in a multi-declarator line
to share the pointer/array-ness of the first, but this driver (like
standard C) only applies `*` to the first name -- silent until the
second name is later used as an array and hits a hard `Bad assignment`/
`Invalid types to '-'` error. Fixed only the instances that actually
failed to compile (per this project's policy against blind bulk-fixing
every superficially similar declaration): `daemon/races.lpc`'s
`AddRace()` (`tmp`), `daemon/classes.lpc`'s `AddClass()` (`tmp`),
`daemon/help.lpc`'s `GetIndices()` (`val`, confirmed via its
`member_array(tmp, val)` use requiring an array), `lib/chapel.lpc`'s
`Religion`/`Deities`/`DeityIds` (all three, confirmed via `Religion[1]`/
`member_array(deus, DeityIds)`/etc.), `secure/cmds/players/history.lpc`
(`arr`, `tmp`), and `cmds/creators/clean.lpc` (`items`, `users`).
Several superficially identical lines elsewhere (`daemon/banish.lpc`'s
loop-counter `i`, `cmds/players/date.lpc`, `secure/daemon/finger.lpc`'s
`Religion`, `secure/cmds/players/peer.lpc`'s `ret`) were checked and
left alone -- they compile cleanly as-is, meaning the second name is
genuinely used as a scalar there.

## 6. Bare `array` declaration -- hard syntax error here, not a silent
   no-op

`lib/history.lpc`'s `private nosave array History;` (no element type)
is AGENTS.md's general "bare `array x;`" class, but manifests as a hard
compile error on this driver (`unexpected L_IDENTIFIER`) rather than
the silently-inert declaration documented elsewhere in this project's
catalog -- and since `lib/history.lpc` is inherited straight into the
player body class (`lib/interface`/`lib/creator`/`lib/player`/
`lib/interactive` all failed transitively from this one line), it
blocked every player body from compiling at all. Fixed to `mixed
*History` (confirmed via its `allocate()`/`sizeof()`/string-indexing
uses).

## 7. `ed_start()`/`ed_cmd()`/`query_ed_mode()` -- this build uses
   `__OLD_ED__`, only the old `ed()` efun exists

Exactly the catalogued class, hit in **two** independent files:

- **`lib/editor.lpc`** (`eventEdit()`/`process_input()`) -- the
  general-purpose "edit this file, then call me back" mixin used by
  mail, bug reports, room-building, and the bare `ed` command. Rewrote
  against `ed(file, exit_fn, restricted)`: `eventEdit()` now calls
  `ed(file, "ed_exit", !creatorp())` and stores the caller's callback;
  the driver invokes the named `ed_exit()` function on this object when
  the interactive session ends (replacing the old manual
  `query_ed_mode()==-1` polling in `process_input()`, which is now
  unreachable dead code kept only so files chaining
  `editor::process_input()` still compile -- the driver's C-level input
  loop intercepts every keystroke directly for the whole session under
  `__OLD_ED__`, bypassing `process_input()`/`input_to()` entirely).
  This file is inherited into the player body class, so before this fix
  no player body could compile at all -- the single most severe finding
  in this port after \S2.
- **`lib/nmsh.lpc`** (the Nightmare shell mixin, also inherited into the
  player body) -- `write_prompt()` called `query_ed_mode()` to draw a
  different prompt while mid-edit. Since the driver draws its own
  prompt for the whole duration of an old-style `ed()` session (same
  reasoning as above), this branch can never fire under either ed
  model; dropped rather than ported.

`secure/cmds/creators/lsed.lpc` (a wizard utility that drives the
editor **programmatically**, feeding it a whole script of `ed` commands
with no real user typing, to batch sed-style edits across many files)
depends on the synchronous, in-process "new ed" API in a way that has
no equivalent under `__OLD_ED__` at all -- old `ed()` hands control to
the driver's C-level input loop for a real interactive user, there is
no way to feed it commands programmatically from LPC. Left as a
documented, non-portable gap (see \S10) rather than reimplementing a
text editor in LPC.

## 8. `SetLong()`/closures -- the same class already seen this session
   in `sunshadow`, independently present here

`obj/wed_ring.lpc`, `obj/portal.lpc`, and three `domains/Ylsrim/room/`
files (`armoury`, `sand_room`, `weaponry`) call the single-argument
`SetLong()` with an old-style closure (`SetLong((: RealLong :))`) for a
dynamic long description, but every implementation in the inherit chain
(`lib/std/room.lpc`, `lib/events/look.lpc`) only accepted `string`. Both
already had the machinery to evaluate a `functionp()`/`arrayp()` value
at *read* time (`GetInternalDesc()`/`GetExternalDesc()` already branch
on `functionp(val)`/`arrayp(val)`) -- only the *setters* and their
backing fields were narrowly typed. Widened `SetLong()`/
`SetInternalDesc()`/`SetExternalDesc()` to `mixed`, and the backing
`InternalDesc` field (`lib/events/look_in.lpc`) from `string` to
`mixed` (`ExternalDesc` in `look.lpc` was already `mixed`). `door.lpc`'s
own two-argument `SetLong(side, long)` already took `mixed long` and
needed no change. Left `lib/interactive.lpc`'s player-body override of
`SetLong()` narrow (`string`, doing a `strsrch(str, "$N")` check) since
nothing calls it with a closure and widening it would need an
additional `stringp()` guard for no exercised benefit.

Related, smaller: `lib/comp/seal.lpc`'s `eventOpen()` called
`eventPick(who, tool)` -- the real signature is `varargs mixed
eventPick(object who, string id, object tool)` (three params: an
optional lock/key id string in the *middle*, then the tool). The
2-argument call is missing the `id` argument entirely, most likely an
artifact of `eventPick()` being extended with a new middle parameter
after this call site was written and never updated -- fixed to
`eventPick(who, 0, tool)`, preserving the exact same runtime behavior
(the function already treats a missing/0 `id` as "no specific key")
while satisfying the compiler's arity/type check. This blocked every
lockable door/container in the inherit chain
(`lib/std/limb`/`corpse`/`storage`, `lib/door`, `lib/trap`, several
`domains/Ylsrim` rooms) from loading.

## 9. Missing directory breaks a `get_dir()` `+`-chain

`daemon/help.lpc`'s `LoadIndices()` builds the "commands" help index by
`+`-concatenating nine `get_dir()` calls across nine different command/
verb directories -- but `secure/cmds/common/` doesn't exist in this
archive snapshot (confirmed: `verbs/spells`, `verbs/undead`,
`cmds/undead` are ALSO missing, and the original author already
guarded those specific calls with `|| ({})`, just not this one). This
driver's `get_dir()` on a directory that doesn't exist returns something
that isn't an array, so mid-chain `array + non-array` throws `Bad type
argument to +. Had array and int.` at runtime, breaking `create()` for
the whole help daemon -- caught by nothing, since `create()` isn't
wrapped in a `catch()` anywhere in its call chain, so `daemon/help`
itself never finished loading. Guarded the one unguarded call the same
way the original author already guarded its siblings:
`(get_dir(DIR_SECURE_COMMON_CMDS + "/*.lpc") || ({}))`.

## 10. Known gaps -- documented, not invented or mechanically forced

Four files remain uncompilable after the fixes above (a 99.3% pass
rate, 564/568, on the full `lpcc_check.sh` batch sweep); none of them
are preloaded in a way that blocks boot (`master.lpc`'s `preload()`
wraps every preload call in its own `catch()`), and none are reachable
from the standard registration/gameplay path exercised in \S11:

- **`secure/cmds/creators/lsed.lpc`** -- see \S7; needs the "new ed"
  synchronous API this driver build doesn't have. A wizard-only batch
  scripted-edit utility, not core gameplay.
- **`secure/daemon/remote.lpc`** (preloaded, but preload failures are
  caught) -- the "Remote Creator Protocol" daemon, a legacy inbound
  socket letting a separate client program edit files over a raw TCP
  connection on `PORT_RCP`. Every `eventWrite(fd, ...)` call site passes
  the connection's raw `int` file descriptor where the inherited
  `LIB_SERVER::eventWrite(object owner, mixed val, int close)` expects
  the owning socket *object* (`owner->GetDescriptor()`) -- a
  pre-existing arity/type mismatch against remote.lpc's own declared
  base class, not something this port introduced (nothing in the file
  defines a local, differently-typed `eventWrite()` override, and no
  git history exists to show it ever did). Whether old MudOS's looser
  compile-time type checking simply let this call through uncaught, or
  this daemon was already non-functional in the original archive, is
  unrecoverable from a single-commit clone; left uncompiled rather than
  reworking a niche wizard-only network protocol's calling convention.
- **`secure/daemon/bugs.lpc`** -- an in-mudlib bug-tracker daemon
  explicitly gated `#ifdef __PACKAGE_DB__` with the file's own comment
  "only useable if you can define PACKAGE_DB". This driver build
  happens to unconditionally predefine `__PACKAGE_DB__` (advertising
  SQL package support), which the original authors evidently never
  expected any real deployment to enable -- the gated body itself is
  genuinely unfinished/truncated (a bare `ret[row[0]] = (...` with no
  closing braces, an undefined `ret` variable, a `tmp` used before
  declaration in `eventAssign()`, a hardcoded `nightmare.imaginary.com`
  DB host). Not touched -- reconstructing a truncated, never-finished
  feature would be inventing content, not fixing a driver
  incompatibility.
- **`daemon/tmp/A_WEARON.lpc`** -- one of ~30 tiny runtime-generated
  cache files under `daemon/tmp/` (each does `int TYPE() { return
  SOME_MACRO; }`, a classic old-MudOS trick for resolving a `#define`'s
  value dynamically without a real efun). All the others reference a
  real macro from `include/armour_types.h`; this one references
  `A_WEARON`, which doesn't exist anywhere in that header (the real
  macro is `A_WEAPON`) -- almost certainly a typo baked into this
  snapshot's cache by whatever process originally generated it, not
  authored content. Left in place as a harmless, non-preloaded, already-
  broken cache artifact rather than guessing at and "fixing" a
  generated file's intended macro name.

## 11. Verification

Booted the real FluffOS driver (`~/src/fluffos/build-debug/src/driver`)
against `config.fluffos` -- `Initializations complete.` reached, clean
of any new fatal errors in `log/catch`/`log/runtime` beyond the single,
already-documented `secure/daemon/remote` preload failure (\S10).
Verified end to end with a raw Python socket client (no
`tmux_mud.sh`/`mudclient.py` shortcuts):

- **Admin install**: `secure/lib/connect.lpc` (the mudlib's real,
  built-in one-time installer, active only until the first admin is
  created) walked through completely -- MUD name (`fluffos`), password
  + confirm (`Mud@2026`), display name, gender, real name, email --
  correctly added `fluffos` to both the `SECURE` and `ASSIST` groups in
  `secure/cfg/groups.cfg`, created `secure/save/creators/f/fluffos.o`,
  and self-replaced `secure/lib/connect.lpc` with the fixed
  `connect.real` (confirmed identical via `diff` afterward) -- exactly
  the mechanism this codebase intends for admin bootstrap, not a
  hand-edited save file.
- **Admin login** (separate connection, post-install): name + password
  -> three news screens (general/creator/admin, confirming the `SECURE`
  group grant actually took) -> real starting room (Ylsrim's central
  bazaar) -> `look` (full room description), `score` ("Creators have no
  score, get a life." -- correct, intentional creator-exempt response,
  not a bug), `who` (shows `Arch: Newbie Wanderer Fluffos the
  unaccomplished`, confirming admin rank), `say hello world`
  (broadcasts correctly), `quit` (clean disconnect, `[Fluffos quits]`
  logged).
- **Full new-character registration** (separate connection): name
  (`testchar`) -> confirm y/n -> password + confirm -> gender -> display
  name -> email -> real name (optional) -> race selection (`list` shows
  17 races, `pick human`) -> newbie news screen -> real starting room,
  landing correctly alongside the admin -- `look`/`score` (correct
  level-1-human character sheet: town, alignment, age, hunger/thirst/
  mood) both producing correct output, `quit` clean. Removed the
  throwaway `testchar` save afterward; kept the seeded `fluffos` admin
  account and its `realms/fluffos/workroom.lpc`, matching this
  collection's existing convention for `nightmare3`.
- Driver killed by exact PID after testing (never `pkill -f`).

## 12. Genuine outbound network connection at boot

`daemon/intermud.lpc` (**preloaded**) is the Intermud-3-protocol
daemon; its `create()` hardcodes `Nameservers = ({ ({ "*i4",
"204.209.44.3 8080" }) })` and, 2 seconds after boot (`call_out((:
Setup :), 2)`), opens an outbound socket to that address to register
with the Intermud nameserver network. Unlike the similar `mortremains`/
`sunshadow`-adjacent findings this session (where the hardcoded 1990s
target address was confirmed unreachable), a live `ss -tnp` check
during this port's own boot test found the connection actually reached
**ESTABLISHED** state -- that specific address apparently still answers
on port 8080 today. This is genuine, intended upstream functionality
(not a bug to patch away), but per this project's established
convention, **`nightmare4` should not be swept into high-frequency
automated reboot/deep-test loops** the way most of this corpus safely
can be -- each boot is a real outbound network event to a real, live
remote host, more so than the merely-attempted connections documented
elsewhere in this collection.

## 13. WASM status

Not attempted (`wasm_status` left `""` per task scope).
