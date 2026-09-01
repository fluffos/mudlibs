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

## 9. WASM status: `playable`, zero code fixes needed

Tested with `node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/residuum --timeout 25 --idle 1.0` driving the exact flow real
players use: `fluffos` (account name) -> `Mud@2026` (password) ->
`fluffos` (select the existing, already-chargen'd character from §10)
-> `look` -> `score` -> `quit`. No fresh registration was needed since
this lib already carries a seeded, fully-chargen'd admin
account/character from the native §10 pass (Level 2 Warrior, standing
in Origin Point) -- reusing it exercises the account-menu/character-
select half of the login flow that a brand-new registration wouldn't.

Transcript was completely clean end to end: `Enter account name:` ->
`Existing account 'fluffos'...` -> `Password:` -> the full
`border()`-rendered account menu (correctly listing "Fluffos, Level 2
Human, Origin Point") -> selecting the character produced the real
room description of Origin Point (ASCII mini-map, four exits, the
`R-0111010` NPC's greeting) -> `look` re-rendered the identical room ->
`score` produced the full character-sheet box (Warrior, Level 2, XP
896, HP/SP/MP 140/84/72, stats, connected time) -> `quit` cleanly
dropped back to the account menu with `Fluffos exits Nightmare
Residuum.` logged, exactly matching native behavior. Grepped the full
driver console output for `Error`/`FATAL`/`Undefined function`/`No
program in object`/`Bad argument` and found none -- no
`sockets`-package crash, no `pcre` issue, no `uptime()` gate, no
`log/`-path ENOENT. This lines up with §8's own finding that this
lib's only socket user (`secure/daemon/ipc.lpc`) is inbound-only and
not preloaded, so the WASM build's absent `sockets` package was never
going to be exercised on this path in the first place -- no
`#ifdef __PACKAGE_SOCKETS__` guard or `catch()` wrap was needed
anywhere. This is one of this project's "clean WASM session, zero
fixes needed" cases, alongside `demonangel`/`dreamofseven`/
`immaster`/`lpmud141`/`mortremains`.

Since the WASM harness runs the whole mudlib out of an in-memory
filesystem (MEMFS) copied at boot, none of this touched
`libs/residuum/work/` on disk at all -- no save-data churn to clean up,
and the seeded `fluffos` account's on-disk save is unchanged from §10's
own native-testing state.

`meta.json`'s `wasm_status` set to `"playable"`.

## 10. Deep functional test, round two (2026-08-27, AGENTS.md §10.7)

One continuous session via a raw Python socket client (`~/src/fluffos/build-debug/src/driver config.fluffos`), covering both halves of this lib's distinct account/character split as two separate steps, plus the six standing cross-cutting patterns (§7.121/§8.3a/§7.122/§7.123/§7.124/§7.126) checked explicitly by grep against this codebase.

### 10.1 Newbie path and chargen (previously undiscovered at onboarding)

This lib has no `help newbie`-style doc (`doc/help/` only has `syntax`); the real onboarding path is architectural, not documentation-driven. Onboarding's own NOTES.md (§7) had only verified registration through the very first `look` in `/domain/Origin/room/enter.lpc` ("deep in darkness") and a `quit` — it never actually progressed past that. This session discovered the rest of the flow: `enter.lpc`'s `handle_receive()` always fires an `M_STORY` intro sequence (six timed lines over several seconds) that ends by moving the character into `/domain/Origin/room/tank.lpc`, a **second, distinct chargen step** — a "STATUS" panel with `download [class]` (warrior/mystic/scoundrel/ranger/psionist/paladin), `encode [attribute] [value]`, `randomize`, and `done`. A character's class stays the placeholder `"adventurer"` (and physical attributes stay unset, silently re-randomized on each re-entry into the tank) until `done` is run, which requires a real class to have been picked first (`"Specimen must have a class before process is complete."` if not). Only after `done` does the character reach the real, persistent starting room (`/domain/Origin/room/center.lpc`, "Origin Point"). This is not a bug — the code is internally consistent and works correctly — just an undocumented second gate worth recording so a future re-test doesn't have to rediscover it. The admin account's seeded `Fluffos` character (previously left mid-way through this flow, per onboarding's own transcript) was carried through `download warrior` + `done` as part of this session.

### 10.2 `domain/Start` (a large hand-built human town) is completely unreachable in this snapshot

`domain/Start/human/` contains ~150 fully-built rooms (a whole town: streets, a bank, shops, apartments, a museum, a church, a school, a gym) plus starter weapons/armor items — but a corpus-wide grep (`grep -rln "domain/Start" **/*.lpc`, and specifically for `Start/human/room/square` as the likely hub) found **zero references to any `domain/Start` file from anywhere outside `domain/Start` itself** — no `set_exit`, no teleporter, no admin-only shortcut. The only way out of `domain/Origin` is the `pad` exit in `/domain/Origin/room/west.lpc`, which leads into the separate procedural `domain/Planet` coordinate-grid surface (real, reachable, and working — see §10.3), never into `Start`. Net effect: a brand-new character has **no organic way to ever reach a shop and no starting weapon or armor is ever granted** (`set_class()` in `std/living/class.lpc` only sets the class name and recalculates vitals; no gear-granting code exists anywhere). This reads as unfinished world-wiring in this snapshot rather than a programming bug (no crash, no wrong efun/API usage — the `Start` domain simply isn't linked into the graph yet), so it was **not fixed** per the scope boundary (connecting it would require deciding *where* and *how*, a content/design call). Documented here so a future pass doesn't waste time re-deriving this; also explains why a level-1 character can be beaten by a level-1 wild animal (§10.4) — they have no armor and are mechanically incapable of getting any.

### 10.3 Procedural planet surface works correctly; FFI-fallback error is expected, benign noise

Descending via `pad` correctly compiles a virtual room (`/domain/Planet/virtual/room/surface/Terra/250.250`, real Perlin/simplex-noise-driven biome/heat/humidity/height values, e.g. "tropical rainforest"). The first virtual-room compile of each boot throws a full driver backtrace to the console/`debug.log` (`*get_os_env: 'NR_NOISE_SO' is not in the 'allowed os environment variables' list`, from `secure/sefun/noise.lpc:108`'s `__ffi_init()`) — this looked alarming live but is a **caught, intentional fallback**: `__ffi_init()` wraps the `get_os_env()` call in `catch()` and falls through to `debug_message("noise: FFI disabled (NR_NOISE_SO unset)\n")`, exactly as the repo's own `native/noise` Rust FFI addon (explicitly out of scope for this project per §0/§1) is meant to degrade when unavailable. FluffOS logs a thrown error's backtrace to the console even when an LPC `catch()` up the stack handles it, which is what makes a fully-expected, fully-handled condition look like a crash. Confirmed the pure-LPC fallback produces real, working terrain regardless. Not a bug; not fixed.

### 10.4 Combat, `check_lifesigns()`: real off-by-one bug, found but a fix was **reverted** after breaking an existing test

`std/living/combat.lpc`'s `check_lifesigns()` has the code's own author-left marker:
```lpc
// TODO: this should be 1
if (this_object()->query_hp() < 0) {
    dead = 1;
}
```
i.e. the author already knows defeat should trigger at `hp <= 0` (`< 1`), not only at `hp < 0`. Changing it to `< 1` looked like a trivial, author-confirmed one-token fix, but running `test /std/living/combat` immediately caught a regression: `test_check_lifesigns()`'s very first assertion (before the test ever calls `set_hp()`) failed with `*Bad argument 1 to EFUN call_other(): Got int(0)`, because a freshly-`new()`'d `STD_LIVING`/mock object's `query_hp()` legitimately reads `0` before `update_vitals()` has ever run (vitals are only computed once a class is set), and `< 1` now flags that transient pre-initialization state as "dead" too, destructing the object as a side effect the very first time `check_lifesigns()` is ever called. A real player character never hits this window in practice (vitals are established during chargen long before any combat), but the mock/test object does, which is almost certainly *why* the author's own TODO was left unresolved rather than applied outright — completing it correctly would require also guaranteeing hp is never observed at `0` pre-initialization (e.g. gating `check_lifesigns()` behind "vitals have been computed at least once"), which is more than a one-line change and starts to make judgment calls about combat/lifecycle sequencing. Per this project's scope boundary ("when genuinely unsure... document, don't guess"), **the change was reverted** back to the original `< 0` + TODO comment, and is recorded here instead as a confirmed-but-deliberately-untouched author-acknowledged bug. Live-observed consequence: a character's own HP can go visibly negative (`-8` in this session's test fight) before `"You have been defeated!"` fires — cosmetic only (the eventual defeat still happens correctly one attack-round later), not a soft-lock or crash.

### 10.5 Real bug fixed: `/log/` write ACL silently dropped nearly all in-game action logging

`secure/etc/write.cfg` gated `/log/` writes to `ASSIST:MUDLIB` only. `secure/daemon/access.lpc`'s `query_allowed()` requires **every object in the call stack** (not just the immediate writer) to individually hold one of the path's allowed privileges (`query_file_privs()` classes `/cmd/` files as `COMMAND`, confirmed in `secure/include/access.h`). Since `D_LOG->log()` is called either directly from a `/cmd/*.lpc` file (`cmd/character/advance.lpc`, `cmd/character/improve.lpc`) or from `std/character.lpc` via a call chain that passes through one (`cmd/character/quit.lpc` → `exit_world()` → `D_LOG->log("character/enter", ...)` for the disconnect-side log line), and `COMMAND` was never in `/log/`'s allowed set, **every such write was silently denied** (`debug_message`'d to the driver console as `"/daemon/log denied write (write_file) to /log/character/..."`, never surfaced to any player). Confirmed live: `/log/character/advance` had never once been successfully created despite the feature existing and firing every time `advance` runs; `/log/character/enter` existed but was missing every disconnect-side entry, only ever recording the connect side (which is reached via `std/user/character.lpc`/`std/user.lpc`, i.e. no `/cmd/` frame in that particular chain). By contrast `/realm/` and `/save/` — the *other* two paths ordinary player commands legitimately write through — both already include `COMMAND` in their own `write.cfg` lines, making `/log/`'s omission of it look like a straightforward oversight rather than a deliberate security boundary (this is a game's own first-party log directory, not user-supplied content, so no injection-style risk from allowing it). **Fix**: `secure/etc/write.cfg`, `(/log/) ASSIST:MUDLIB` → `(/log/) ASSIST:MUDLIB:COMMAND`. Verified live: re-ran `test /secure/daemon/access` (100% asserts pass, no regression), then a fresh `quit` correctly appended a `"... exits from 127.0.0.1"` line to `/log/character/enter` where it previously silently failed. This is a config/access-control bug, not a game-content decision, so it was fixed in place.

### 10.6 The six standing cross-cutting patterns — all checked, none found

- **§7.121** (float math in a declared-`int` function, no `to_int()`): checked `secure/sefun/color.lpc` and `domain/Start/human/item/clock.lpc` (the only files mixing `float`/`int` return types) and the entire currency system (`std/module/currency.lpc`, integer-only, single "copper" currency, no division at all) — every float-computing function correctly wraps its return in `to_int()`. Clean.
- **§8.3a** (a `private`-declared dispatch/callback function silently demoted, breaking an external dispatch mechanism): this codebase never calls `add_action` anywhere (confirmed by corpus grep — zero hits), consistent with onboarding's own NO_ADD_ACTION finding, so the classic shape can't occur. The one close analog investigated — `std/user/input.lpc`'s `private nomask string process_input(string str)`, which shares a name with a real driver apply (`APPLY_PROCESS_INPUT`, fired by `comm.cc` when a `"!"`-prefixed command arrives with no active `input_to()`) — turned out to be a false lead: every `input_to()`/`get_char()` registration in this codebase explicitly passes the `NOESC` flag (`input["secure"] | 2`), which makes the driver's C-level `escape_command()` skip the raw-apply path entirely and route `"!"` through the ordinary registered closure instead, where `dispatch_input()`'s own in-LPC `str[0]=='!'` check handles it. `process_input()` is consequently dead code, never invoked by anyone, but harmlessly so. Clean.
- **§7.122** (unguarded autoload/class-marker duplication on reconnect): grepped for `query_auto_load`/`compute_autoload_array`/`load_autoload_obj` (the exact TMI-2-lineage function names from the AGENTS.md entry) and for any other "regenerate on login" mechanism — this codebase's `std/character/autoload.lpc` (`update_autoload()`/`restore_autoload()`/`reset_autoload()`) is a from-scratch, unrelated design with no TMI-2 ancestry. Not exercised deeply live (no items with an autoload-equivalent flag were available given §10.2's gearless start), but the code shape doesn't match the vulnerable pattern. Clean/not applicable.
- **§7.123** (bare file-scope `IDENT = (...)` statement silently failing a whole file's compile): grepped for the pattern directly and for the companion "declared-then-later-assigned" shape (a `nosave` global declared without an initializer followed by a bare top-level assignment) across the whole lib — zero matches. Cross-checked against the live boot's own preload log and the onboarding session's already-recorded 674/677 `lpcc_check.sh` pass rate (3 known, unrelated gaps — `codesay.lpc`'s new-ed API and the two `USE_SQLITE3__`-gated database files); nothing newly failing. Clean.
- **§7.124** (int-declared threshold field initialized with a 0.0–1.0 fraction where 0–100 was meant): grepped for every `= 0\.[0-9]+;` literal in the codebase — all hits are genuine `float`-typed noise/procgen math (`secure/sefun/noise.lpc`, `daemon/planet.lpc`, `cmd/immortal/noise_perf.lpc`) or a commented-out line; none are a mistyped fraction on an `int` field. This lib also has no wimpy/auto-flee-style safety threshold at all to check. Clean.
- **§7.126** (a stale pre-`.lpc`-rename `.c` extension baked into `.o` save data, breaking `load_object()`): this lib has no coordinate-AREA engine that stores exit destinations as data — the only virtual/procedural rooms (`domain/Planet`) generate their own exits live in LPC (`terrain.lpc`), never from persisted path strings, and a direct scan of all 4 real save files under `save/` (`daemon/soul.o`, `planet/t/Terra.o`, both shipped in the raw upstream archive; the admin's own `account`/`character` saves) found the only `.c`-suffixed string is `daemon/soul.o`'s cosmetic `save_object()` header line (`#/daemon/soul.c`, written before this project's `.c`→`.lpc` rename) — confirmed this header is never parsed for path resolution by `restore_object()` (read directly from `~/src/fluffos/src/vm/internal/base/object.cc`; it's a version-marker comment line, not consulted for loading). Not applicable/clean.

One more near-miss worth recording for future sibling checks even though it turned out safe: `domain/Planet/virtual/room/base/terrain.lpc`'s wildlife-spawn `switch` builds `PLANET_NPC + npc + ".lpc"` where the `random(2)==1` branch's own `npc` value (`"plasma_snail.lpc"`) is *already* suffixed, producing a double `"plasma_snail.lpc.lpc"` key — but `std/module/reset.lpc`'s `set_reset_data()` independently strips exactly one trailing `.lpc` from every key it stores (its own `[<4..]`/`[0..<5]` guard, added for the same corpus-wide `.c`→`.lpc` slice-width class documented elsewhere in AGENTS.md), which silently repairs the double-suffix back down to the correct filename before it's ever used in `new()`. No live bug results, but the inconsistent suffixing in `terrain.lpc`'s own switch (one branch bare, one branch pre-suffixed) is sloppy and would break if `set_reset_data()`'s defensive stripping were ever changed — not fixed, since it causes no live-observable bug today and touching it would be tidying rather than fixing.

### 10.7 Persistence verified across a real reconnect

Sequence: joined `Fluffos`, completed chargen (§10.1), fought a cloned `curious_raccoon` (`domain/Planet/npc/curious_raccoon.lpc`) unarmed/unarmored to a loss (`"You have been defeated!"`, Defeats: 0→1), `recall`ed to Origin Point, granted the character `add_experience(1000)` via `eval` (immortal-only, used to exercise `advance`/`improve` without a multi-hour grind — a legitimate test shortcut, not a live gameplay bug), `advance`d one level (2, XP 896 remaining), then a clean `quit`. Reconnecting on a **new** socket a few minutes later showed the account menu correctly reporting `Level 2 Human`, `Origin Point`; joining the character showed the exact same `score` (Level 2, XP 896, Defeats 1, HP 140/140 SP 84/84 MP 72/72 — HP/SP/MP had regenerated to full between sessions, which reads as ordinary passive regen, not a bug) and the exact same room (`Origin Point`, not reset back to the intro/tank). Both account-level (last-seen time, character list) and character-level (class, level, XP, defeat count, location) state persisted correctly. Also incidentally confirmed the earlier abrupt-disconnect (non-`quit`, plain socket close) behavior is NOT a bug: `net_dead()` → `character_linkdead()` intentionally does not force a save (only `exit_world()`/`heart_beat()`'s 60-second autosave do), so progress made after the last autosave tick and before an abrupt disconnect is expected to be lost — this is a normal autosave-interval tradeoff, not investigated further as a "bug."

### 10.8 In-game self-test framework (`D_TEST`) used directly as part of this pass

This lib's own `test [file]`/`test all` immortal command (`secure/cmd/immortal/test.lpc` → `D_TEST`) was used live to spot-check files touched or investigated during this session (`/std/living/combat`, `/std/module/reset`, `/std/user/account`, `/std/user/character`, `/std/character`, `/secure/daemon/access`) — all passed 100% of their own assertions both before and after the §10.5 fix, and this is exactly what caught the §10.4 regression before it was committed. Did not run the full `test all` (227 test files) given the time budget; the targeted subset above covers every file this session actually changed or seriously suspected.

### Verification / cleanup

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` fresh after the §10.5 fix — clean `Initializations complete.`, zero new `debug.log`/console errors beyond the already-documented, expected §10.3 FFI-fallback notice. Killed by exact PID after each boot (never `pkill -f`). Removed all testing byproducts before committing: the throwaway `qatester` account+character (`save/account/q/qatester.o`, `save/character/q/qatester/`), D_TEST coverage-instrumentation files (`*.lpcoverage.lpc`, auto-generated by `test -c`), the immortal `eval` command's scratch file (`realm/fluffos/CMD_EVAL_FILE.lpc`), and this session's own driver stdout logs — kept only the seeded `fluffos` admin account/character save (now reflecting real, verified play: Level 2, Warrior, 896 XP, 1 Defeat, standing in Origin Point). Re-ran the port-conflict sanity check (`grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort -n | uniq -c | awk '$1>1'`) — no output, clean.
