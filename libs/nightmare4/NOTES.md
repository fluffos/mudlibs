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
number 932, port 40234.

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

`playable`. Booted `~/src/fluffos/build-wasm/src` against this lib via
`scripts/wasm_client.js`. `secure/sefun/sefun.lpc`'s `dump_socket_status()`
(a `cmds/creators/netstat.lpc`-only diagnostic, not on the boot/login
path) called `socket_status()` unconditionally, which is `Unknown efun`
without the `sockets` package -- fatal at simul_efun compile time,
identical shape to this project's `ds386`/`dsII`/`lima` entries. Guarded
the function body with `#ifdef __PACKAGE_SOCKETS__ ... #else return "";
#endif`. After the fix, a full WASM session verified clean: real
menu-driven registration (name, confirm, password + confirm, gender,
display name, email, real name), race selection (`list` / `pick human`),
landing in Ylsrim's central bazaar, `look`/`score`, and `quit`. (Initial
runs with too-short `--idle` values between `wasm_client.js` sends
appeared to hang mid-registration at the gender prompt -- reproduced
identically on the *native* driver with the same fast timing, confirmed
purely a test-harness pacing artifact via a slower `--idle 2.0`, not a
WASM-specific or mudlib bug.)

## 14. Deep functional test, round two (2026-08-27, AGENTS.md §10.7)

One continuous session against `~/src/fluffos/build-debug/src/driver`, a
raw Python socket client (no `tmux_mud.sh`), plus a separate admin
(`fluffos`/`Mud@2026`) connection for `eval`-based verification.
Registered two full new characters through the real menu-driven flow
(name -- rejects any digit, letters/`'`/`-` only, 2-15 chars --
confirm y/n, password x2, gender `male`/`female` spelled out in full,
display name, email requiring a real `user@host` shape, optional real
name, then `list`/`pick RACE`), landed in Ylsrim's bazaar both times.
Walked bazaar -> n (Kaliid Road) -> w (Kaliid Road near the Fighters'
Hall) -> enter hall -> n (through the oak door) to reach Roshd
Burlyneck, used `ask roshd to describe fighters` then `ask roshd to
join fighters` -- class join works exactly as documented (`score`
correctly flips from "Newbie Wanderer ... Drifter" to "Newbie Fighter
... Fighter", `skills` populates the fighter's primary/secondary/other
skill table from a clean zero baseline). Tested the pub economy path
(`enter pub` -> `ask lars to list` -> correct menu response "I
currently supply ale for 3747." -> `ask lars to serve ale` -> correctly
rejected with "You do not have that much in electrum" for a broke new
character -- no crash, `GetCost()` already correctly uses `to_int()`).
Confirmed the bare command forms (`list`, `serve ale` typed directly,
without `ask lars to`) are NOT valid verbs in this codebase at all --
`SetCommandResponses()` is only ever dispatched from `eventAsk()`, so
every NPC "command" here is really an `ask NPC to VERB` sentence; this
is the correct, intended dispatch shape (confirmed by reading
`lib/sentient.lpc`), not a missing-verb bug.

**Two real bugs found and fixed** (both silent -- zero compile error,
zero crash, invisible to `lpcc_check.sh` and to a clean boot):

1. **`lib/currency.lpc`'s `GetNetWorth()`** -- declared to return `int`
   but its body sums `amt / tmp` (a `float currency_rate()` divisor)
   into a `float net_worth` local and returned that float bare, with
   no `to_int()` -- the exact §7.121 shape (declared `int`, real float
   value, no runtime coercion on this driver). Live caller
   `lib/living.lpc:479`'s `eventSteal()` assigns the result straight
   into a declared-`int amt` used for `random(7*amt)`/`random(amt)`/
   `AddStatPoints("coordination", random(amt))` in the stealing-skill
   training path -- not just the cosmetic `cmds/creators/stat.lpc`
   "net worth" display. Fixed: `return net_worth;` -> `return
   to_int(net_worth);`. Verified live via admin `eval`:
   `ob->AddCurrency("gold", 37); ob->GetNetWorth()` now returns a real
   `int` (`intp()` true), previously would have been a bare float.
   (`lib/mayor.lpc`'s near-identical `int cost = (currency_rate(...) *
   Tax);` shape at lines 27/49 was checked and left alone -- `Tax`
   defaults to `0` and nothing in this archive snapshot ever inherits
   `lib/mayor.lpc` at all, confirmed by a corpus-wide `inherit`
   grep, so it's genuinely dead/unreachable code, not a live bug.)

2. **`lib/combat.lpc`'s `Wimpy` field** (the auto-flee-at-low-health
   safety threshold) -- a brand NEW bug class, written up as AGENTS.md
   §7.124. `private int Wimpy;` is initialized in `create()` with
   `Wimpy = 0.20;` (a bare fraction), but every real consumer in this
   codebase (`cmds/players/wimpy.lpc`'s player-facing `wimpy
   PERCENTAGE` command, `cmds/players/score.lpc`) treats it strictly as
   an **integer percentage 0-100** (`wimpy on` sets it to the literal
   `23`). The runtime gate in `eventReceiveDamage()`,
   `if( Wimpy < percent(hp, GetMaxHealthPoints()) ) return x;` (skip
   fleeing when true), is therefore comparing `0.20` against an integer
   0-100 -- true for virtually every nonzero health percentage, so the
   auto-flee safety net was **silently dead for every character from
   character creation**, until the player manually ran `wimpy
   NUMBER` themselves. `SetWimpy()`/`GetWimpy()` were also declared to
   return `float` (matching the buggy literal) instead of `int`
   (matching the field's own declaration and every real caller) -- a
   second, dependent bug: once a real nonzero integer sits in `Wimpy`,
   the declared-`float` return silently widens it, and callers' `(int)`
   casts (compile-time-only on this driver, see
   `reference_lpc_int_cast_is_compile_time_only`) don't convert it back,
   corrupting the player-facing display (`"Percentage: 20.000000%"`
   instead of `"20%"`). Fixed both: `Wimpy = 0.20;` -> `Wimpy = 20;`,
   and `float SetWimpy(float wimpy)`/`float GetWimpy()` -> `int
   SetWimpy(int wimpy)`/`int GetWimpy()`.

   Verified live in two independent ways: (a) a brand-new character
   (`freshtwo`) created strictly after the fix shows `score`'s mood
   line as "You are feeling wimpy." and the bare `wimpy` command
   correctly prints `"Percentage: 20%\nCommand: go out"` (a
   pre-existing character, `wanderling`, created before the fix still
   shows "You have wimpy turned off" -- expected, the fix does not
   retroactively repair an already-corrupted save, same caveat as
   §7.121/§7.122); this held after a full quit/reconnect cycle, so the
   fixed default survives a real save/restore round-trip, not just the
   in-memory session. (b) an admin `eval` directly exercised the exact
   comparison used in `eventReceiveDamage()` against `freshtwo`'s real
   `GetMaxHealthPoints()`: simulated 15%-health now correctly evaluates
   to "should flee", simulated 50%-health correctly evaluates to
   "should not flee" -- both were "should not flee" before the fix,
   confirming the safety net was unconditionally dead, not just
   mis-tuned.

   **Live combat against a real hostile was not reached** in this
   session: this archive's Ylsrim example domain ships exactly one
   NPC weak enough for a level-1 test character to safely engage
   (`domains/Ylsrim/npc/traveller.lpc`, level 5, non-aggressive,
   `s_bazaar`'s `SetInventory` spawns it via `unique(file, 1)`) --
   every other domain NPC (`max`/`shiela`, level 15 shopkeepers;
   `lars`, level 12 barkeep; `roshd`/`priest`, level 45 class leaders)
   is far too strong for a fair fight, and `domains/Ylsrim/npc/
   balrog.lpc` (an "example simple NPC" file) is never actually placed
   in any room at all (confirmed by grep -- dead/template content, not
   reachable). The traveller itself turned out to be blocked by its
   own **intended rarity design**, not a bug: `daemon/unique.lpc`'s
   `GetUniqueCopy()` enforces an `86400 * rare` second real-world
   cooldown between spawns (`rare=1` here, i.e. 24 real hours), and
   `save/unique.o` already had a timestamp from this lib's own
   onboarding-time testing less than a day old, so `unique()` correctly
   returned `0` (confirmed live via `eval`: `unique(fn,1)` returns 0,
   `catch()` shows no error) and the NPC legitimately could not
   respawn yet -- this is the same "ghost absence is often a feature"
   shape documented elsewhere in this project, not a bug to patch
   around. Given the risk of permanently disrupting a shared shopkeeper
   NPC (or the same 24h-cooldown unique mechanism) for an incremental
   confirmation, combat plumbing was instead verified end-to-end via
   the two eval checks above (b) rather than a live fight; a full live
   fight (and the death/respawn cycle) is flagged here as **not
   verified live**, an honest gap rather than a silent skip, should a
   future session have more wall-clock room (or catch the traveller's
   cooldown window) to complete it.

**All four known cross-cutting bug patterns checked explicitly**:

- **§7.121 currency float-into-int**: found and fixed (`GetNetWorth()`
  above); every other money-handling function in
  `lib/currency.lpc`/`lib/std/barkeep.lpc`/`lib/std/vendor.lpc`/
  `lib/teller.lpc`/`secure/sefun/economy.lpc` already correctly wraps
  its float arithmetic in `to_int()`/`to_float()` at every call site
  checked.
- **§8.3a `private` command-dispatch demotion**: not applicable to
  this codebase's architecture at all -- there is no `command_hook`
  mechanism; ordinary commands dispatch through `daemon/command.lpc`
  (already fixed for the §7.118 filename-slice bug at onboarding) and
  NPC "commands" dispatch only through `eventAsk()`. A script-driven
  check for the general shape (a `private` function referenced by
  string name from `add_action()`/`call_out()` within the same file,
  the `demonangel`-class pattern) found zero matches anywhere in the
  corpus.
- **§7.122 class/marker-item duplication on reconnect**: not
  applicable -- no `auto_load`/`compute_autoload_array`/
  `load_autoload_obj`-style reload mechanism exists anywhere in this
  codebase (confirmed by grep); `lib/player.lpc`'s `class quest
  *Quests`/`class death *Deaths` fields are tracking data, not
  physical reloadable items.
- **§7.123 bare file-scope assignment**: one heuristic grep hit
  corpus-wide (`secure/cmds/players/tell.lpc:101`'s `__Morse = ([...
  ]);`), hand-verified as a false positive -- it's a local variable
  inside the `morse()` function body, not file scope, and the file
  compiles and works correctly.

**Systematic re-check of the §7.118 filename-slice class** (this
lib's dominant bug at onboarding, ~15 files): every remaining
`[0..<N]`/`[<N..]`/`strlen(x)-N`-shaped slice in the corpus was
individually triaged. All were confirmed to be doing something else
entirely (stripping a trailing `/` one character at a time regardless
of length in `secure/lib/file.lpc`, dropping the last word of a
`explode(str," ")` array in `daemon/chat.lpc`/`secure/obj/post.lpc`,
dropping the last array element in `secure/daemon/bboard.lpc`,
singularizing an English category name for an error message in
`daemon/help.lpc`, trimming an appended `/` sentinel character in
`secure/cmds/creators/grant.lpc`) -- no further live instances of the
dominant onboarding-time bug class remained.

**Test characters left as evidence**: `wanderling` (pre-fix,
demonstrates the "wimpy turned off" post-restore symptom), `freshtwo`
(post-fix, level 1 human, joined the fighter class, correctly shows
`wimpy` at 20%/"go out"). `freshbie`/`freshbie2`/`grimtest`/
`grimtest2`/`freshtwo`-style throwaway registration retries with typos
were not all cleaned up; harmless partial/duplicate throwaway accounts
from mid-flow registration mistakes (invalid name/email formats
rejected before a character object was ever created) are not
persisted at all by this mudlib's own registration flow, so no
additional cleanup was needed beyond what's listed here.

**Sibling note for `nightmare3`/`residuum`**: check both for the same
`Wimpy = 0.20`-style fraction-vs-percentage literal shape in their own
combat/status mixins if they share this lineage's `lib/combat.lpc`
ancestry -- `residuum` is already known (per §7.118's own writeup) to
share the identical filename-slice dispatch bug with `nightmare4`, so
its combat internals are a plausible direct copy too.

Driver killed by exact PID after each reboot (never `pkill -f`); the
Intermud-3 outbound connection noted in §12 was observed reaching
`ESTABLISHED` again on each of the three reboots this session, exactly
as before -- no change in that behavior, and the session stayed well
within a small number of manual reboots rather than any automated
loop.
