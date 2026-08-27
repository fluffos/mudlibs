# Nightmare Residuum -- porting notes

Source: `git clone https://github.com/michaelprograms/nightmare-residuum`
(commit `d9336dbcad231b34ac751e9e41946b52efbbd309`, cloned 2026-08-26).
The repo's own description: "An LPMud inspired by the Nightmare Mudlib
but utilizing modern fluffos driver features." Top level bundles a
`driver/` git submodule (tracking `fluffos/fluffos`, not fetched), a
`native/noise` Rust FFI addon for procedural planet rendering, and a
`tools/planet-render` helper -- all ignored per this project's
convention (own driver build at `~/src/fluffos`, no Rust toolchain
invoked). Mudlib root is the repo's `lib/` directory: 712 raw files,
4.3MB -- by far the smallest and most modern archive processed in this
session so far. Slug `residuum`, number 935, port 40237.

## 0. Confirmed genuinely distinct from `nightmare3`/`nightmare4`

Before investing effort: this is NOT a period MudOS snapshot at all --
it's a from-scratch modern codebase that merely takes thematic
inspiration from the original Nightmare lib (its own README says so
explicitly, linking to `fluffos/nightmare3` as the inspiration, not the
source). Confirmed via file layout (`lib/std`, `lib/secure`,
`lib/daemon`, `lib/cmd`, `lib/domain`, `lib/realm` -- no overlap with
either sibling's directory names or file contents beyond generic
LPC-family naming), example domain (`domain/Origin`, a small space
station, vs `nightmare3`'s Praxis and `nightmare4`'s Ylsrim), and
architecture (a genuine account/character split with a`D_TEST` unit-test
framework built in from day one -- 227 of the 677 real `.lpc`/`.c` files
are `.test.lpc`/`.mock.lpc` companions, something neither sibling has
any equivalent of). Not a duplicate.

## 1. Conversion

Pure ASCII/UTF-8 archive already -- `convert_lib.sh` reported
`already_utf8=708 converted=0 lossy=0 skipped_binary=4`, no encoding
work needed. Renamed 677 `.c` files to `.lpc`, fixed 1051 literal `.c"`
references, and ran the `static`->`nosave` sweep across only 2 files
(this codebase's own house style already avoids `static` almost
entirely) with no collisions.

## 2. No `get_root_uid()`/`get_bb_uid()`/`creator_file()` needed at the
   mudlib-design level, but still required by THIS driver build

This driver was built with `PACKAGE_UIDS`, so `set_master()` demands
`master::get_root_uid()`/`get_bb_uid()` exist or the whole process
`exit(-1)`s at boot (AGENTS.md's general \S7.2 class) -- and every
subsequent object load then needs `master::creator_file()` too. Unlike
most archives in this catalog, this codebase's real access-control
model has NOTHING to do with driver uids at all (grep confirms zero
`getuid()`/`seteuid()` calls anywhere) -- it's entirely privs-based via
its own `D_ACCESS` daemon consulting `read.cfg`/`write.cfg`. Added the
same flat "everyone is Root" stub as this project's `nightmare3`/
`nightmare4` (`secure/daemon/master.lpc`, next to the existing
`privs_file()` apply):

```lpc
string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }
string creator_file(string file) { return get_root_uid(); }
```

## 3. `ed_start()`/`ed_cmd()`/`query_ed_mode()` -- this build has
   `__OLD_ED__`, opposite of what this codebase's own `local_options`
   (meant for a self-built driver) asks for

The repo's own `local_options` (top level, for anyone building their
own driver per `build.sh`) explicitly sets `#undef OLD_ED` -- i.e. it
wants the new synchronous ed API. This project's shared driver build
has `__OLD_ED__` defined instead (confirmed via `debug.log`'s predefine
dump and by directly test-compiling a bare `ed("/tmp/x")` call, which
compiles clean, vs `ed_start`/`ed_cmd`/`query_ed_mode`, which don't).
Two files affected:

- **`secure/std/editor.lpc`** -- the general clone-per-session `ed`
  wrapper (`editor_start(file, endFn)`, used by the immortal `eval`
  command's "no arguments -> open the editor" path). Rewrote against
  old `ed(file, exit_fn, restricted)`: `editor_start()` now calls
  `ed(file, "ed_exit", 0)` and stores the caller's end-callback; the
  driver invokes the object's own `ed_exit()` when the session closes
  (added). The old `editor_input()`/`query_prompt()` pair (registered
  via `__User->input_push()` to manually feed `ed_cmd()` per keystroke)
  is gone entirely, not just dead-code-shimmed -- nothing else called
  either function, and under `__OLD_ED__` the driver's C-level input
  loop owns the whole session directly, bypassing `input_to()`/
  `process_input()` for its duration, so there was nothing for that
  pair to still do. `clean_up()`'s `query_ed_mode() == -1` check became
  a plain instance-variable flag (`__EdDone`) set by the new
  `ed_exit()`.
- **`cmd/immortal/codesay.lpc`** -- a wizard-only novelty command that
  drives `ed_start`/two `ed_cmd()` calls **programmatically** (write a
  temp file, insert a comment prefix, save) with no real interactive
  user typing at all. This has no equivalent under `__OLD_ED__` --
  old `ed()` hands the whole session to a real interactive user via the
  driver's C-level input loop; there's no way to script it from LPC.
  Left uncompiled, exactly this project's precedent for the same class
  on `nightmare4`'s `secure/cmds/creators/lsed.lpc`.

## 4. The `.c`->`.lpc` filename-slice bug -- present here too, and this
   time it broke the WHOLE command/verb/ability dispatch registry AND
   silently disabled `set_password()`

The exact class flagged before starting this port (previously the
dominant pattern in `nightmare4`, and in `sunshadow`'s
`daemon/command.lpc`): code that slices a filename to strip its
extension using an arithmetic width that assumed the archive's original
2-character `.c`, now wrong against the 4-character `.lpc` this
project's convention renames to. This driver's `str[0..<n]` keeps
`len-n+1` characters (AGENTS.md \S7.80's off-by-one), so a correct strip
needs `n = suffix_length + 1` -- `.lpc` needs `[0..<5]`, not `[0..<3]`.
Found in two distinct shapes, the second more severe than anything a
first-pass grep for the literal `.c"` string would ever catch (these are
all bare numeric slices, no quoted extension string involved):

- **`secure/daemon/command.lpc`'s `scan()`** -- the `D_COMMAND` daemon
  (**preloaded**) that builds the registries every ordinary command,
  ability, and verb dispatch through: `cmd = file[0..<3]` from
  `get_dir(path + "/*.lpc")` turned `"look.lpc"` into the registry key
  `"look.l"` instead of `"look"` -- **every single command/verb/ability
  in the entire mudlib** got registered under a corrupted key, so
  `D_COMMAND->query_command("look")` (the one call
  `std/living/command.lpc`'s `handle_command()` makes for every typed
  command) always returned 0. Root-caused only after a live boot showed
  `score`/`who` (implemented as literal `border()`/`write()` calls, not
  routed through `D_COMMAND`) worked while nothing else responded at
  all. Fixed the one slice (`[0..<3]` -> `[0..<5]`) that every command
  in the mudlib depends on.
- **The "guard-then-strip pair" shape** (nightmare4 \S3's second
  bullet): `convert_lib.sh`'s literal-`.c"`-reference fixup correctly
  rewrote a quoted `".c"` comparison to `".lpc"`, but left the slice
  WIDTHS at their old 2-character values, so a guard like
  `x[<2..] == ".lpc"` can now never be true (comparing a 2-character
  substring to a 4-character literal) -- silently disabling the strip
  it used to guard, rather than corrupting anything outright. Three
  instances, one inverted (append instead of strip):
  - `std/user/account.lpc`'s `set_password()` -- `STD_USER[0..<3]` is
    `"/std/user.l"`, which can never equal `base_name(previous_object())`'s
    extension-free `"/std/user"`, so this self-defense check rejected
    every legitimate caller. This one doesn't even need a
    live-connection guard to be caught by; it directly blocked the
    password-creation step of registration on the very first
    connection test (`*Illegal attempt to account->set_password`,
    `log/runtime`). The sibling `set_name()` allowlist regex two
    functions down has the identical `STD_USER[0..<3]`/`D_TEST[0..<3]`
    pattern; fixed both to `[0..<5]`.
  - `secure/daemon/master.lpc` (2 sites) and `secure/sefun/user.lpc`
    (the `this_user()` sefun) -- `D_TEST[0..<3]` comparisons gating a
    test-runner-only code path (suppressing expected-error noise during
    `D_TEST` runs, and redirecting `this_user()` when called from
    inside a test). Doesn't affect ordinary play, but is the same
    fallout and was fixed the same way for consistency.
  - `secure/cmd/immortal/test.lpc` and `std/module/reset.lpc`'s
    `set_reset_data()` -- both `if (x[<2..] == ".lpc") x = x[0..<3];`,
    fixed to `[<4..]`/`[0..<5]`.
  - `cmd/immortal/goto.lpc` -- the INVERTED guard,
    `if (path[<2..] != ".lpc") path += ".lpc";`, meant "append the
    extension if it's not already there" but (same length-mismatch
    reasoning) was now unconditionally true, so `goto /std/room.lpc`
    always produced `/std/room.lpc.lpc`. Fixed to `[<4..]`.
  - Also swept the corpus's own `D_TEST` file-discovery regexes in
    `secure/daemon/test.lpc`, which independently still matched literal
    `\.c$`/`\.test\.c$` against real files that no longer end that way
    (never disabling anything -- the .c file just doesn't exist -- but
    silently made this codebase's own test-coverage scanner discover
    zero files post-rename): rewrote the two regexes and one path
    exclusion to `.lpc`, and replaced one more `x[0..<2] + "test.lpc"`
    site with the file's own already-correct
    `replace_string(file[0], ".lpc", ".test.lpc", 1)` helper rather than
    re-deriving a third slice width by hand.

`secure/cmd/immortal/update.lpc:114`'s superficially identical
`input[0..<2] + "test.lpc"` was checked and left alone: unlike the
`daemon/test.lpc` site, `input` here is NOT reliably extension-suffixed
at that point (it can arrive via `file_name(environment(...))`, which
returns the driver's own extension-free canonical object path) -- this
looks like a pre-existing, load-bearing-on-context author quirk rather
than something this port's `.c`->`.lpc` rename specifically broke
(the exact same ambiguity would have existed against the original
2-character `.c` too), so left untouched per this project's policy
against fixing what isn't a clear conversion regression.

## 5. `message()` never reached any target that wasn't itself the
   driver's INTERACTIVE connection object -- this codebase's whole
   account/character split depends on a driver flag this build's
   `local_options` doesn't set

By far the most severe and most interesting finding in this port,
because it isn't a bug in the mudlib source at all -- it's a genuine
mismatch between what this codebase's own architecture requires and
what this project's shared driver binary was compiled with.

**Symptom**: registration completed and `write()`-based output (the
`eval` command's results, `score`/`who`'s `border()`-rendered boxes)
displayed correctly, but `look`, `say`, and the room description shown
on first entering the world all produced **silently empty output** --
no error, nothing in `log/runtime`, not even `catch()` reporting a
thrown error (`catch(message("room", "TESTMSG", this_character()))`
returned `0`).

**Root cause**: this codebase's account/character split means the
*character* object (`STD_CHARACTER`, what `previous_object()` resolves
to inside a verb like `cmd/verb/look.lpc`) is never itself the driver's
interactive connection -- that's a separate `STD_USER` object the
character only holds a reference to (`__User`). Every description,
speech, and room broadcast in this mudlib goes through a `message()`
sefun wrapper (`secure/sefun/override.lpc`) that calls the real
`efun::message(type, msg, target, exclude)`, relying on the *character*
object having its `receive_message(type, msg)` apply (which forwards to
`__User->receive_message(...)`) actually invoked by the driver's
`do_message()` dispatch. But `do_message()`
(`src/vm/internal/simulate.cc`) only calls that apply on a target
object flagged `O_LISTENER` or truly `interactive` -- and `O_LISTENER`
is *only* ever auto-set, at object-creation time, `#ifdef
NO_ADD_ACTION`. This repo's own `local_options` (meant for a
self-built driver, `#define NO_ADD_ACTION`) sets exactly that flag,
which is presumably why this architecture works fine on the driver the
authors actually build and test against. This project's shared driver
build (`~/src/fluffos/build-debug`) was **not** compiled with
`NO_ADD_ACTION` (confirmed directly: `debug_info(0, ob)`'s output
prints `O_ENABLE_COMMANDS` where it would print `O_LISTENER` if the
flag were set) -- so the character object's `O_LISTENER` flag is never
set, `do_message()` never calls its `receive_message()`, and every
`message()` call to a character (or to a room, to reach the characters
standing in it) is silently swallowed. `write()` worked throughout only
because its own implementation (also in `override.lpc`) calls
`character->receive_message(...)` **directly** via `->`, sidestepping
`efun::message()`'s listener-flag gate entirely -- which is exactly
the tell that pointed at this root cause rather than a broken room or a
broken verb parser.

This is the same general class as AGENTS.md \S7.46 (a mudlib demanding
driver compile-time flags this project's shared build doesn't have,
previously found on a LIMA-derived lib) -- normally "not fixable at the
mudlib-source level; would require a second, separately-compiled driver
binary." Rebuilding a second driver just for this one lib was out of
scope for this port, so instead **reimplemented `message()` itself
against `receive_message()`, replicating `do_message()`'s own dispatch
logic entirely in LPC** (`secure/sefun/override.lpc`): for each target,
if it (or an item in its direct contents, one level -- matching
`do_message()`'s own single-level recursion into a non-listener
target's contents, e.g. a room reaching the characters standing in it)
is `interactive()` or defines `receive_message()`, call that apply
directly. This is a behavior-preserving driver-compatibility shim, not
a content change -- it makes `message()` do exactly what this codebase
already assumed it did, without touching any of the ~30 call sites
across the mudlib that use it. (One acknowledged fidelity gap: the
driver's internal recursion additionally forces hidden objects visible
during delivery; the LPC replacement uses the plain `all_inventory()`
efun, which respects normal hide rules -- a minor content-visibility
nuance, not a functional blocker, and not worth a custom recursive
walk to close.)

Verified fixed live: `catch(message("room", "TESTMSG", ob))` before vs.
after showed the same `0` (no error) both times, but only after the fix
did "TESTMSG" actually reach the connection; a full registration-to-quit
session then showed real room descriptions on `look` and entry, and
`say hello world` correctly producing `"You say: hello world"` plus the
bystander line.

## 6. Known gaps -- documented, not invented or mechanically forced

3 files remain uncompilable after the fixes above (99.6% pass rate,
674/677 on the full `lpcc_check.sh` batch sweep); none are preloaded
and none are reachable from the standard registration/gameplay path
exercised in \S7:

- **`cmd/immortal/codesay.lpc`** -- see \S3; needs the programmatic
  "new ed" API this driver build doesn't have. A wizard-only novelty
  command, not core gameplay.
- **`std/database.lpc` / `std/database.test.lpc`** -- both reference
  `__USE_SQLITE3__`, a driver predefine
  (`src/compiler/internal/lexer_utils.cc`) that only exists when the
  driver itself was built with `USE_SQLITE3` (a CMake option under
  `PACKAGE_DB`). This project's shared driver build has `PACKAGE_DB`
  and `PACKAGE_DB_MYSQL` enabled but not `PACKAGE_DB_SQLITE`
  (confirmed via `CMakeCache.txt`), so the predefine genuinely doesn't
  exist here -- a driver-package configuration gap, not a mudlib bug.
  `STD_DATABASE` (`/std/database.lpc`) is defined in `global.h` but
  never actually inherited or referenced by anything else in the
  archive (confirmed by grep) -- optional, unused infrastructure in
  this snapshot, not something blocking any exercised feature.

## 7. Verification

Booted the real FluffOS driver (`~/src/fluffos/build-debug/src/driver`)
against `config.fluffos` -- `Initializations complete.`, clean of any
new fatal errors in `log/debug.log`/`log/runtime` beyond the 3
documented gaps above. Verified end to end with a raw Python socket
client (no `tmux_mud.sh`/`mudclient.py` shortcuts), twice -- once as the
admin account and once as an ordinary second character:

- **Admin registration** (`fluffos`/`Mud@2026`): account name -> confirm
  (y) -> password + confirm -> screenreader preference (n) -> character
  name (`fluffos`) -> confirm (y) -> species (`human`, the only one
  unlocked) -> entered Origin's starting room, correctly auto-granted
  immortal on this first-ever character (`"Since this appears to be the
  first connection, you have been set as immortal."`).
- **`look`**: full room description with the ASCII mini-map, short
  description ("deep in darkness"), and "There are no exits."
- **`score`**: full `border()`-rendered character sheet box (species,
  class, level, stats, HP/SP/MP, connected time).
- **`who`**: correctly lists "1 immortal, 0 characters connected".
- **`say hello world`**: `"You say: hello world"` plus the bystander
  broadcast line (no other characters present, so only the self-message
  showed, exactly as expected for an empty room).
- **`quit`**: clean disconnect, `(connection) Fluffos exits Nightmare
  Residuum.` logged, returned to the account menu on the (still-open in
  this test) connection.
- **Second, ordinary character** (`testchar`/`TestPass123`): identical
  registration flow, correctly NOT granted immortal (`who` showed "1
  character connected", no immortal line), `look`/`score`/`say`/`quit`
  all correct. Removed the throwaway `testchar` account/character save
  afterward; kept the seeded `fluffos` admin account, matching this
  collection's existing convention.
- Driver killed by exact PID after each test (never `pkill -f`).

## 8. No outbound network connections at boot or during testing

Unlike `nightmare4`/`nightmare3` (both run a live Intermud-3 daemon),
this codebase's only socket-using file, `secure/daemon/ipc.lpc`, is an
**inbound-only** loopback listener (binds `127.0.0.1`, explicitly
rejects any connection whose address doesn't match
`^127\.0\.0\.1 [0-9]+$`) for a local "Remote Creator Protocol"-style
tool -- and it isn't even preloaded (`secure/etc/preload.cfg` has it
commented out). `secure/module/http.lpc` (an HTTP-over-websocket
responder) is likewise inbound-only. Confirmed via `ss -tnp` during a
live boot: no established or attempted outbound connections at any
point. This lib is safe for high-frequency automated reboot/deep-test
loops, unlike its two Nightmare-lineage siblings in this collection.

## 9. WASM status

Not attempted (`wasm_status` left `""` per task scope).
