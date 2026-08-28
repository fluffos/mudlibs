# merentha (176)

## Provenance

`merentha_fluffos_v2.zip` from `lpmuds.net/files/` (a maintained,
already-FluffOS-adapted release bundling a FluffOS 2.9-ds2.03 driver
source snapshot alongside the mudlib -- the driver snapshot was ignored;
this project uses its own driver at `~/src/fluffos`). The original
`lpmuds.net` site is now defunct; this archive was recovered from the
Wayback Machine snapshot
<https://web.archive.org/web/20120225071653id_/http://lpmuds.net/files/merentha_fluffos_v2.zip>
and was already content-verified (real, non-corrupted LPC source, e.g.
`merentha_fluffos_v2/bin/local_options`) before this pass began.

Mudlib root: `merentha_fluffos_v2/lib/` (the archive also ships
`bin/`, `win32/`, and the `fluffos-2.9-ds2.03/` driver-source tree,
all ignored).

Merentha is explicitly derived from Nightmare 3 -- its own description
advertises "the Nightmare feel and robustness without the complications
of verbs or weird lfun names." This collection already has `nightmare3`
(160), which needed essentially zero driver-compat fixes; Merentha
turned out to need exactly one.

## Conversion (`scripts/convert_lib.sh`)

Ran unconditionally per AGENTS.md convention even though the archive was
already clean English UTF-8/ASCII (verified: `already_utf8=756
converted=0 lossy=0` across all 757 files):

- `.c` -> `.lpc` rename: 143 files.
- 67 literal `.c"` string references auto-fixed.
- 3 local `#include <x.lpc>` angle-bracket includes converted to quoted
  form (AGENTS.md \S8d -- angle brackets only search the configured
  include path, never the including file's own directory; safe/additive).
- `static` -> `nosave`: 11 files touched.

## Proactive checklist (AGENTS.md \S2.2) -- none of the 6 known
recurring bug classes from this archive family applied here

Checked all six classes flagged from sibling `lpmuds.net`-family
archives (`genesis`, `finalrealms`, `foundation2`, `discworld`,
`tmi2`) before the first boot attempt; none were present:

1. `add_action()` with a bare function value instead of a string --
   every `add_action()` call in the tree uses a string literal.
2. `ed_start()`/`ed_cmd()`/`query_ed_mode()` (new editor API) --
   zero hits anywhere in the tree; the `ed` command isn't part of this
   mudlib's admin toolset at all.
3. `.c`->`.lpc` rename breaking fixed-width filename-slice arithmetic in
   a command-dispatch table -- `commandHook()` in
   `std/inheritables/user.lpc` resolves commands via
   `file_exists(path+cmd_path+".lpc")`, not by slicing filenames pulled
   from a `get_dir()` listing, so the rename is a non-issue here.
4. `ref` used as an ordinary identifier -- the only `\bref\b` hits in
   the whole tree are inside `doc/old/lpc/constructs/ref.lpc`, a
   plain-text help-file describing the LPC `ref` keyword itself (not
   real code -- see below).
5. Missing `creator_file()` master apply -- already defined in
   `daemon/master.lpc` (delegates to `/sefun/sefun`), and works.
   (What *was* missing turned out to be a different pair, see below.)
6. `explode()` on `SANE_EXPLODE_STRING` builds -- `master.lpc` contains
   no `explode()` calls at all.

## The one real fix: missing `get_root_uid()`/`get_bb_uid()`

This driver build has `PACKAGE_UIDS` enabled, which requires
`get_root_uid()`/`get_bb_uid()` applies on the master object --
`vm/internal/master.cc`'s `set_master()` calls `exit(-1)` immediately
if either is missing or returns a non-string, with only a `debug_message`
("No function get_root_uid() in master object...") as a clue, no crash
trace. Neither was ever defined anywhere in this archive (unlike
`creator_file()`, which was), so the driver silently exited (255) right
after loading `master.lpc`, before ever reaching any of the actual
mudlib content -- this is exactly the same driver requirement (and
exact same fix shape) documented for `foundation2` (174) in this
collection, and the closely-related `nightmare3` (160) already carries
the identical two-line pair with the identical values. Ported as-is
into `daemon/master.lpc` right next to the existing `creator_file()`:

```lpc
string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }
```

This was the *only* driver-compat fix needed anywhere in the ~140-file
mudlib. Confirmed via `lpcc --batch`: 142/143 pass after this one
change (the remaining "failure" is inert doc content, see below).

## Compile-sweep tail: `doc/old/lpc/constructs/ref.lpc` (expected, not a
bug)

The only file that fails to "compile" in the `lpcc --batch` sweep:

```
/doc/old/lpc/constructs/ref.lpc:1:7: error: syntax error, unexpected L_REF
```

This isn't LPC source at all -- it's a plain-text help/documentation
file (using `TITLE()`/`PRE`/`ENDPRE` markup consumed by the `man`/`help`
daemons as raw text, not compiled) that describes the `ref` keyword
construct, and happens to sit in a `doc/` tree that got the project's
blanket `.c`->`.lpc` rename along with everything else. Confirmed dead
for compilation purposes: nothing anywhere in the tree `inherit`s or
`load_object()`s it; the `doc/` help system only ever `read_file()`s
these as text. Left as-is -- not a conversion bug, and not reachable
via the compiler at all under real play.

## Cosmetic pre-existing content bug, NOT fixed (out of this project's
scope per AGENTS.md's programming-bugs-only rule)

`score` (and any other UI panel built with `sefun/strings.lpc`'s
`border()` helper, e.g. money/inventory display) shows the literal
string `__BORDER_LINE__` as a padded content row instead of a dashed
separator line:

```
|  Score  : 0 (level 1 child)                                             |
| __BORDER_LINE__                                                         |
|  Vitals : Health 91(91)       Magic 90(90)        Stamina 95(95)        |
```

`cmds/player/score.lpc` builds its message with a sentinel line
`string line="__BORDER_LINE__";` interleaved between sections, relying
on `border()` splitting the *wrapped* text back into an array with
`explode(wrap(str,...), "\n")` and matching `strs[y]=="__BORDER_LINE__"`
exactly to swap in a real dashed line. In practice the `wrap()` call
(via the `terminal_colour()` efun, which reflows/pads text to a target
width) doesn't preserve that line as an exact standalone array element,
so the equality check never matches and the sentinel falls through to
the generic "format this as a content row" branch instead, printing the
raw placeholder text with padding.

This is a display-only cosmetic glitch (every underlying value --
level, HP/MP/SP, stats, money -- displays correctly) that this project's
standing scope rule (fix programming/driver-compat bugs, not
content/design issues -- and there's no error signature here, just a
cosmetic mismatch) puts out of scope to "fix" by rewriting the
mudlib's own line-splitting logic. Documented here rather than patched.

## Boot + play verification

Boots clean: `lpcc --batch` 142/143 pass (see above), zero fatal errors
on driver boot, `log/errors_*` show only pre-existing warnings
(`nosave` on functions -- a driver pedantry warning, not an error) plus
the doc-file line noted above.

Verified live over a raw Python socket client against the real driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`), full
registration flow: name -> confirm keep name (y/n) -> password (4-8
chars) -> confirm password -> name capitalization format -> drops
straight into the game world (a race-selection limbo room, not a
separate out-of-world lobby). Then, in a second full run:
`become male human` (this mudlib's race/gender-selection command,
one of six races: human/giant/gnome/elf/dwarf/fairy) -> moves into a
"becoming" transition room -> `look`, `score`, `inventory` all produce
correct, well-formatted output (money correctly shows the starting 100
gold granted by `become`) -> `quit` saves cleanly and disconnects.

Re-login as a returning character (existing name -> password prompt ->
correct password accepted) also verified working.

One easy-to-misread transient during testing, not a bug: an early test
run disconnected via a raw socket close instead of `quit`, leaving a
live (never-saved) in-memory player object resident under that name.
Subsequent logins to that same name reconnected to the *stale live
object* (`reconnect()`/"link-dead" recovery -- an intentional Merentha
feature so a dropped connection doesn't lose your live character) rather
than loading fresh save data, which looked at first like a save-file
edit not taking effect. A full driver restart (clearing all in-memory
state) confirmed the save file itself was correct all along.

## Admin account seeding

`fluffos` / `Mud2026` registered through the normal registration flow
(see above). Grant mechanism: `sefun/preds.lpc`'s `admin_p(ob)` treats
any `__Position` value other than the literal string `"player"` as an
administrator; `std/inheritables/user.lpc`'s own `set_position()`
setter is itself gated behind `admin_p()` (a chicken-and-egg problem for
the very first admin), so the account's own save file,
`save/users/f/fluffos.o`, was edited directly (per AGENTS.md \S1.5:
"Prefer editing the *data* ... over code") to change
`__Position "player"` to `__Position "admin"`.

Verified after a full driver restart (see the stale-object note above):
login banner shows "You are logged in as an administrator", the prompt
switches to the admin `<cwd> > ` form, `/cmds/admin/` commands become
reachable via `commandHook()`'s path search, and
`update /cmds/admin/update` returns "Update Successful." -- confirms
both the rank grant and that the admin-only command path resolves and
compiles/reloads correctly.

## Networking: local UDP daemon, but no live outbound traffic by default

`daemon/network.lpc` (preloaded at boot) binds a local UDP socket
(`MERENTHA_INTERMUD`, `query_host_port()+6`) and schedules a periodic
`send_ping_request()` call-out -- but that function only pings muds
already present in its own `__MUDS` peer table, restored from
`/save/daemons/network`. The shipped save data has `__MUDS ([])` (empty),
so with no peer mud ever registered, no outbound packets are actually
sent; the socket bind is purely passive. Unlike `imud`/`tmi2` in this
collection (which hardcode a live public router IP and register with a
real Intermud-3 network on every boot), Merentha's peer-discovery
protocol here is opt-in and inert out of the box -- no live-network
caveat needed for repeated automated re-boot testing.

## WASM status update (2026-08-26, another session)

Promoted `wasm_status` from `""` to `playable`. Booted clean under
WASM with zero fixes needed -- unlike most sibling libs from this same
source, no eager simul_efun/master socket call was present. The only
sockets-related output is `daemon/intermud.lpc`'s own deliberate
`#error` guard (refuses to load without the sockets package, working
as designed, not a bug). Verified with a scripted WASM session: login
(`fluffos`/`Mud2026`), `look`, and `score` (reproducing the exact same
cosmetic `__BORDER_LINE__` display quirk already documented above,
confirming consistent behavior between native and WASM). `quit` wasn't
recaptured distinctly in this transcript but is already verified clean
under native testing above.

## Deep functional test (round two), 2026-08-27

Full continuous playthrough per AGENTS.md §10.7, against
`~/src/fluffos/build-debug/src/driver` booted from `libs/merentha/`.
Read `doc/news/welcome`, `doc/CLASSES`, `doc/SKILLS`, and the in-game
`help` menu first; the intended path is: register -> land in the
race-selection room -> `become <gender> <race>` -> an optional
personality-quiz room (`begin`, five multiple-choice questions that
nudge starting skills) -> Cabeiri square (guild halls, a supply shop).
Registered a real English-named test character (`Corwin`, later also
`Aldric`/`Brannor`/`Delwyn` as throwaways) via a raw Python socket
script; `look`/`score`/`i` checked after registration, after
`become`, after guild sign-up, after combat, and after every
quit/reconnect cycle.

### SEVERE bug found and fixed: orphaned password-check clone leaks a
live heartbeat that silently corrupts every character's save data on
reconnect

New AGENTS.md entry **§7.150** (full writeup there). Summary:
`std/login/login.lpc`'s `check_password()` clones a throwaway
`new(USER)` object purely to `restore_object()` the save file and
compare the password hash. Whenever a player reconnects to an
already-resident (link-dead) copy of their character -- the completely
ordinary case of a client disconnecting without typing `quit` -- both
`query_password()` and `query_override()` reassign the local `__User`
variable to the found live object, silently discarding the reference
to the just-created verification clone **without destructing it**.
`std/inheritables/living.lpc`'s `create()` unconditionally does
`set_heart_beat(1);` for every clone of the class with no "is this a
real playable character or a scratch object" distinction, so the
orphan keeps ticking forever. `std/inheritables/user.lpc`'s
`heart_beat()` does `if(autosave>25) save_player(query_name());
autosave++;` -- once the tick counter passes 25 (~25 real seconds),
the orphan saves **every subsequent tick, forever**, using the single,
increasingly-stale snapshot it loaded at creation time, overwriting
the real, currently-live character's save file under the identical
name. Every unclean reconnect (a dropped connection, the normal
failure mode for any real client) leaks one more such orphan, all
racing to stomp the same file.

Caught live, not by code review: repeated `score`/`sign up`/combat
progress on a real test character (level 1 "child" -> fighter,
level 2, after killing the `helper` NPC) visibly vanished from the
save file within about a second of a clean `quit` -- the quit's own
save was correct, but a still-ticking orphan from several reconnects
earlier immediately overwrote it. Confirmed the exact mechanism via
the admin account's `eval` command and the `objects()`/
`query_heart_beat()` efuns: after ordinary play spanning six
reconnect attempts, **six** independent `/std/inheritables/user`
clones shared the name `aldric`, five of them still ticking with no
relationship to any interactive session.

**Fix** (`std/login/login.lpc`): destruct the orphaned clone
immediately before each of the two `__User=find_player(...)`
reassignments (`if(__User && __User!=find_player(player_name(__Name)))
destruct(__User);`), plus a new `net_dead()` apply on the login
handler itself that destructs `__User` if a connection drops while
still mid-password-prompt (a case the two call-site fixes don't cover
on their own).

**Verified live, end-to-end**, with a fresh `corwin` test character:
- Before the fix: 3 consecutive unclean (raw-socket) reconnects to the
  same still-resident character produced 3 additional ticking orphans
  (`objects()` count for that name climbed 1 -> 4).
- After the fix: the identical reconnect sequence, repeated across
  4 separate connections, left exactly **1** object for that name
  throughout (`corwin_count=1` every time, via admin `eval`).
- Waited past the ~25-tick autosave threshold with 2 more unclean
  reconnects mixed in, then inspected `save/users/c/corwin.o` directly:
  correctly showed the real, current character state (`female elf`,
  100 gold), not a reverted snapshot.
- `quit` itself was independently confirmed correct throughout (it
  always destructed the real object properly) -- the visible
  "progress reverted" symptom was entirely caused by a LATER orphan's
  autosave overwriting quit's own correct save, which is why it was
  initially easy to misdiagnose as `quit` itself being broken.
- Full boot + a fresh multi-character session re-run cleanly after the
  fix, zero new compile warnings/errors introduced (`std/login/
  login.lpc` was already compiling with several pre-existing, harmless
  "prototype disagrees" warnings from its own forward declarations;
  unchanged by this fix).

### Secondary fix: seeded admin account was missing its `/realms/`
directory, silently breaking the `eval` admin command

Per this file's own "Admin account seeding" section above, `fluffos`
was promoted to admin by hand-editing its save file directly (since
`set_position()` is itself gated behind `admin_p()` -- the standard
chicken-and-egg bootstrap problem for a lib with no working
auto-promote-first-admin mechanism, and merentha genuinely has none,
so §7.149 does not apply here). The *normal* promotion path,
`cmds/admin/promote.lpc`, also does `mkdir("/realms/"+ob->query_name());`
as its last step -- since the hand-edit skipped this, `fluffos` was
missing `/realms/fluffos/`, and `cmds/admin/eval.lpc` (which
`write_file()`s a scratch `.lpc` into that directory on every use)
failed outright: `Error: *Wrong permissions for opening file
/realms/fluffos/eval.lpc for append. "No such file or directory"`.
Every OTHER admin command tested (`update`, `score`, `stat`, `call`)
worked correctly with full privileges -- this was specifically an
`eval`-only gap from an incomplete manual seed, not a broader §7.149-
style "admin promotion doesn't actually work" problem. Fixed by
creating the missing directory (`mkdir -p work/realms/fluffos`,
matching what `promote.lpc` itself would have done); verified `eval`
works correctly afterward (used extensively for the diagnosis above).

### Cross-cutting bug-pattern sweep (§7.80/118, §7.121, §8.3a, §7.112,
§7.122-149): clean

Grepped systematically for every standing pattern from the current
AGENTS.md checklist. None present in this lib:
- No `explode(__FILE__,...)` filename-slicing anywhere (§7.80/§7.118).
- No `private`-declared functions at all in the tree (§8.3a moot --
  only a few `private` *variables* exist, all correctly used).
- No death/NPC `init()` scheduling an unguarded `call_out` chain
  (§7.112) -- player death is a simple synchronous `die()` that moves
  to `DEATH_ROOM` and restores partial HP/SP/MP, no call_out at all.
- No class/marker-item duplication mechanism on reconnect (§7.122) --
  `reconnect()` only re-arms the heartbeat and does a `force_me("look")`.
- No bare file-scope `IDENT = (...)` statements (§7.123).
- No percent/fraction threshold fields analogous to §7.124's `Wimpy`
  shape (no wimpy/auto-flee mechanism exists in this lib at all).
- No `.c`-suffixed references baked into `.o` save data (§7.126) --
  the historical `log/errors_compile` etc. entries referencing
  `.c` paths are pre-existing 2003-era archive content, not live.
- No custom `message()`/`tell_room()` wrapper exists at all (§7.129) --
  every call site uses the driver's own `message()` efun directly.
- No `query_idle()`-after-non-interactive shape in `heart_beat()`
  (§7.130) -- this lib uses a real `net_dead()` apply, not inline
  heart_beat-based liveness polling.
- `find_living()`/`find_player()` usage (`cmds/admin/call.lpc`,
  `stat.lpc`) always tries `present()` in the current room FIRST, so
  the admin tools work correctly for any NPC actually present; NPCs
  never call `set_living_name()` so a cross-room `find_living()`
  lookup by name would fail for them specifically (falls through to
  "could not find them") -- a minor completeness gap in admin tooling,
  not a live-play-breaking bug, left as an observation (§7.131-shaped
  but not actually exercised by anything in normal play).
- No `map()`-over-a-mapping misuse (§7.132) -- the few `map()` calls
  all operate over arrays (`keys(...)`), correctly bound.
- `net_dead()` IS defined (§7.133 does not apply) -- see the new
  §7.150 finding above, which is about lifecycle of a *different*
  object, not this apply being undefined.
- No array/mapping field defaulting to bare `0` with a missing
  guard at its use sites (§7.134/§7.135/§7.30) -- `living.lpc`'s
  `__Classes`/`user.lpc`'s `__Channels` have no initializer (default
  `0`), but every real accessor (`query_class()`, `add_class()`)
  already guards with `!__Classes`; `query_classes()` returns the raw
  value but has no callers anywhere in the tree.
- No one-shot setup guard defeating a per-instance setup call (§7.144).
- No broken pre-check wired as a verb override instead of a base-class
  hook (§7.145).
- No broken `/`-for-`/*` comments (§7.146).
- No reserved-keyword parameter names, e.g. `nosave` (§7.148).
- §7.121 (float arithmetic in an `int`-declared function/parameter):
  `daemon/advance.lpc`'s `query_needed_exp(int l)` does assign float
  results (`l*33.0/25`, `(l+6)*1.5`) into `int`-declared locals
  mid-formula -- but unlike every confirmed §7.121 instance, the
  function's own final `return to_int(b);` already converts correctly,
  and the intermediate float-into-int values are only ever consumed by
  further pure-float arithmetic in the same expression (never fed to
  an efun requiring a true int, e.g. array indexing or `random()`),
  so no observable corruption or crash results. Left unfixed as a
  cosmetic type-declaration mismatch, not a functional bug -- confirmed
  by direct reasoning through every use of the affected locals, not
  just pattern-matching the shape.
- `random()` call sites (`std/inheritables/living.lpc`'s combat code,
  `cmds/spells/fireball.lpc`, `cmds/abilities/swing.lpc`) all take
  genuinely-int `query_skill_level()`/`query_stat()`-derived
  arguments; no float ever reaches `random()`.

### Observations, NOT fixed (content/design judgment calls)

- `domains/ROOMS/setter2.lpc`'s personality-quiz `alter_skills()`,
  question 5 ("where would you go on vacation?"), answers "a" and "b":
  `tp->set_skill("survival", tp->query_base_skill("swimming")+10);`
  reads `swimming`'s base level to set `survival`'s level (rather than
  reading `survival`'s own base), and never calls
  `set_skill_adjustment("survival", ...)` the way every other quiz
  answer's skill bumps do for their own skills. This has the shape of
  a copy-paste slip (every other question/answer branch in the same
  function is internally consistent: read a skill's own base, bump it,
  set its own adjustment) but produces no crash, no type error, and no
  wildly-out-of-range value -- just a plausible, if probably
  unintended, coupling between two skills' starting values. Since
  distinguishing "typo" from "the author wanted these two skills
  linked" requires a content judgment call this project's scope
  explicitly excludes, left untouched and documented here per the
  "no error signature = design" standing rule.
- No dedicated safe-sparring mechanism exists in this lib at all (no
  `accept_fight()` override, no training dummy) -- confirmed via a
  whole-tree grep for `spar`/`dummy`/`accept_fight`, zero hits. The
  only combat-capable NPC anywhere in the shipped map is
  `domains/obj/monsters/helper.lpc` ("Helper", level 5, wields a
  sword, explicitly described in its own source comment as "also
  serves the purpose of being a monster example") -- used as the
  combat test target for lack of any better-suited alternative; a
  fresh level-1 character reliably won the fight and leveled up.
- The shipped map is intentionally minimal: 9 rooms total (Cabeiri
  square + 4 sub-squares + 4 guild/shop halls), one shopkeeper NPC
  (`Simon`), one example monster (`Helper`) -- consistent with this
  being an engine/framework release rather than a finished game world,
  matching this file's existing provenance notes. Shop economy (buy/
  sell/value/list, `Simon`'s dispatch on the room rather than the NPC
  itself so no §7.143 command_giver mismatch is possible) and guild
  sign-up (`fighter_hall`'s `sign up` command) both verified working
  correctly live.
- Driver-launch quirk, not a mudlib bug: this driver's
  `reset_debug_message_fp()` (opens `<log directory>/debug.log`) runs
  BEFORE the `chdir()` into the configured mudlib directory, so
  launching `driver config.fluffos` from `libs/merentha/` (as directed)
  rather than from `libs/merentha/work/` itself causes the *literal*
  `debug.log` file to never actually receive this session's output
  (the open fails silently against the wrong relative path at that
  point in boot) -- `errors_compile`/`login_passed`/etc. under
  `work/log/` DO update correctly since those are written after the
  `chdir()`. `debug_message()` always echoes to stdout regardless, so
  capturing the driver's own stdout (already this project's standing
  practice per §10.8) still catches everything `debug.log` would have;
  no fatal errors or crashes appeared in stdout across the full test
  session.

### Test evidence left in place

Seeded admin `fluffos`/`Mud2026` (verified live: admin-only prompt,
`/cmds/admin/` command path, `update`, `stat`, `call`, and now `eval`
all working). All throwaway test characters (`corwin`, `aldric`,
`brannor`, `delwyn`) and their save files were deleted before this
commit; `git status` shows only the `std/login/login.lpc` fix and the
new (now non-empty, via a leftover diagnostic `eval.lpc` matching the
existing `realms/petrarch/` precedent) `realms/fluffos/` directory.
