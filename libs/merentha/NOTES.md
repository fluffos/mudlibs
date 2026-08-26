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

## WASM

Not attempted this session; `wasm_status` left `""` in `meta.json`.
