# RealmsMUD core-lib (realms)

The official mudlib of RealmsMUD (source:
<https://github.com/realms-mud/core-lib>). Unlike some engine-only ports in
this collection, this is not a bare engine -- it ships a real,
substantial game world alongside the framework: 9,994 files under `guilds/`
(class/profession systems), 2,577 files under `areas/` (rooms, NPCs, items),
plus full quest, research, crafting, and trading systems. A fresh character
can register, create a character through an 11-step creation wizard
(color/charset/minimap/gender/race/subrace/hair/eye/attribute/skills/trait
selectors), and land in the actual game world.

RealmsMUD is built for a mixed LDMud/FluffOS dialect with a MySQL-backed
persistence layer for login credentials and player-character records (via
this driver's own `db_*` package) -- the only lib in this collection with a
real external database dependency. MySQL is not part of the shipped
repo; it's session-local test infrastructure this port needed to provision
itself (see "Local run" below).

## Highlights

Porting this ~16,570-file codebase surfaced an unusually deep chain of
FluffOS-compat bugs, several of which masked each other -- fixing one
uncovered the next:

- **`add_action()`'s `command_giver`-at-call-time requirement.** This
  driver's `add_action()` (see `packages/core/add_action.cc`) silently
  no-ops unless `current_object == command_giver` (or an environment
  relation) *at the exact moment it's called* -- no error, nothing. Upstream
  calls `add_action()` from `player.lpc`'s `create()`, which runs *before*
  `exec()` ever attaches the real network connection to the new player
  object, so `command_giver` is still the login object. Every freshly
  logged-in character could reach the game but every single command,
  including `look`, silently failed with the driver's own default `"> "`
  prompt and `"What?"` fail message -- forever. Fixed by re-running command
  registration immediately after `exec()`, once the driver has actually
  reassigned `command_giver` to the new player.
- **`strsrch()`'s 3rd argument is a direction flag, not a start offset.**
  This driver's `strsrch(big, little, flag)` treats *any* non-zero 3rd
  argument as "search from the right" -- not a position to resume from. A
  hand-written `regreplace()`/`regexplode()` shim (this driver has no native
  equivalent) used it as a start-offset cursor for locating successive
  matches, which silently corrupted every multi-match global replace.
  Concretely: `baseCommand.lpc`'s command-template builder (which converts
  `"who [-w] [-p] [-r ##Value##] [-g ##Value##]"`-style templates into
  regexes) produced malformed patterns with dangling unmatched `]`
  characters for any command with 3+ bracket groups (`who`, `say`, `shout`,
  `traits`, `skills`), which then hard-errored ("unexpected ]") the moment
  another player's `look` tried to match against the combined command
  table. Fixed by never asking `strsrch()` to start from a position --
  slicing the unsearched tail first (real LPC range indexing) and searching
  that from its own start instead.
- **This driver's legacy `regexp()` efun hard-caps at 10 capture groups**
  (`NSUBEXP == 10` in `packages/core/regexp.cc`). Several commands compile a
  single combined regex across all their aliases/flags (`"look"`'s 5
  aliases with `[-b]`/`[(at|in) ...]` groups reach 13+; the `"'"`/`say`
  command's own single template reaches exactly 10, i.e. one over the
  limit) -- breaking the single most basic command in the game, `look`,
  the moment a player actually reached gameplay. Switched command dispatch
  to this driver's PCRE-backed `pcre_match()`, which has no such cap.
- **LDMud's `save_value()`/`restore_value()` don't exist on this driver at
  all** -- and there's no `eval-a-string-as-LPC-literal` primitive to build
  them from. `/lib/items/item.lpc` (the base class nearly every
  equippable/usable item in the game inherits) used them for its bulk
  `query(item, "all")`/`set(item, "all", data)` accessor, so item.lpc had
  **no compiled program at all** until this was fixed -- which would have
  cascaded to every item subclass. Implemented from scratch: a small
  recursive serializer producing LPC-literal-shaped text and a matching
  hand-written recursive-descent parser to read it back.
- **This driver's `inherit_list()` never includes an object's own program**,
  only what it *directly inherits from* -- confirmed against
  `vm/internal/base/array.cc`. Upstream's `member(inherit_list(x),
  "/path/to/wizard.lpc") > -1` idiom (used to detect "is this object a
  wizard") only makes sense if `inherit_list()` includes the queried
  object's own class, apparently true under LDMud. On this driver it's
  always `-1` for a genuine `wizard.lpc` instance too (`wizard.lpc` doesn't
  inherit itself) -- so wizard-only commands were unreachable for *every*
  account regardless of rank. This exact idiom recurs elsewhere in the
  codebase (e.g. `who.lpc`'s wizard-listing filter); only the
  `commandRegistry.lpc` instance blocking real wizard command dispatch was
  fixed this session.
- A handful of smaller, individually-confirmed gaps: `catch(expr; nolog)`
  (an LDMud-only modifier syntax) was a hard syntax error here -- swept
  across 51 files; string `-=` (LDMud's substring-removal operator) doesn't
  exist for strings on this driver at all (only int/float/array); a literal
  `"?"` verb (`score`'s `"? [-v]"` alias) needed escaping once regex
  matching switched to PCRE's stricter parser; `copy_file()` doesn't exist
  (this driver's own file-copy efun is `cp()`); `all_inventory(0)`
  hard-errors here instead of returning an empty array.

See `NOTES.md` for the full, much longer list (this is the highlights
summary).

## Registration flow

Login name (letters/apostrophe/hyphen only) -> confirm new user (`y`/`n`) ->
password -> confirm password -> in, immediately presented with the 11-step
character creation wizard (color/charset/minimap/gender/race/subrace/hair/
eye/attribute/skills/trait selectors, each a numbered menu) -- **not** on
a delayed "next login" as an earlier draft of this file assumed; see
NOTES.md section 14 for why that earlier assumption was untested and
wrong (the wizard never actually ran at all until this session's fixes).
Any login whose saved character data is still incomplete (including one
where the player deliberately skipped trait selection) re-triggers the
full wizard from scratch on the next login too -- this is
`validatePlayerData()`'s own intentional design, not a bug. The very first
character ever registered against a fresh database is automatically
granted the game's top `owner` rank (upstream's own design, not a port
addition).

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **rank**: `owner` (this mudlib's top rank), granted via a direct database
  insert into the `wizards`/`wizardTypes` tables (the DB-driven equivalent
  of this project's usual `update`-command convention -- RealmsMUD has no
  `update` wizard command; `aldarion`, an earlier test account, had already
  claimed the automatic first-registrant `owner` grant by the time `fluffos`
  was created, so this account's rank was set directly rather than relying
  on that one-time bootstrap).

The `fluffos` account itself was created during onboarding against that
session's own MySQL instance (session-local/throwaway, see "Local run"
below) and does not exist in a freshly re-provisioned database -- the
account was re-created as `cepheus` (the automatic first-registrant
`owner` grant) during this session's own deep functional test pass
instead. **Wizard command *execution* (`ls`, `pwd`, `cc`, ...) is
confirmed still denied for the `owner` rank** even after a real, fixed bug
in this exact chain (`baseGroup.lpc`'s `group()` matched the wrong file
extension, see NOTES.md section 14) -- everything downstream of that fix
checks out structurally (group registration, command-list wizard-stripping
logic) but access is still denied by something not yet pinned down. Flagged
as an open residual gap, not a confirmed driver bug (see NOTES.md section
14 for the full trace).

## Status

Boots clean. A real §10.7 deep functional test pass (see NOTES.md section
14) found and fixed a severe, previously-undiscovered chain of bugs: **the
11-step character-creation wizard had never actually worked for any
character** (a `restore()`-before-`exec()` timing bug plus a missing
`thing.lpc` inherit on the base selector class), and **character
persistence had never actually worked either** (`getPlayerInfo()` never
included a `"name"` key, which every save silently required; separately,
`has()`/`getModule()` used a shallow `inherit_list()` that missed 11 of 15
per-character data services entirely). Both are now fixed and verified
end-to-end: registered a fresh account, completed the real 11-step wizard,
confirmed populated stats via `score`, `quit`, verified the saved row
directly in MySQL, and reconnected after a real gap to confirm the
character restores correctly with **no** re-triggered wizard. Along the
way, fixing the character-creation wizard's own live minimap-demo step
surfaced that `/lib/environment/environment.lpc` (the base class for
*every room in the game*, including this lib's own `StartLocation()`) had
never successfully compiled either, due to a wide diamond-inheritance
`nomask` conflict plus several instances of this driver's lack of a
nested-array (`type **`) type; both swept and fixed across the affected
files (see NOTES.md for the full file list). `score`'s combat-math display
hit two more instances of the already-documented null-`getModule
("inventory")` guard gap (now fixed, matching the one instance fixed
during onboarding). Wizard `patch.lpc` now compiles clean (`to_object`/
`apply`, neither exists on this driver, replaced with `find_object()`/
`arr...` spread) but could not be live-tested given the still-open wizard
command-execution gap above. Real combat, guild-joining, and skill/trait
*advancement* (as opposed to display) were not reached this session --
flagged as unverified-live, not silently presented as tested.

WASM status: `noboot` -- this lib's entire login/persistence model is
built on `db_*` efuns against a real external MySQL server, and the
`db` package (like `sockets`) is entirely absent from WASM builds by
design (no way to reach an external TCP service from a browser sandbox).
Unlike a peripheral `sockets`-absent daemon, this can't be guarded away
-- there's no flat-file fallback anywhere in this codebase. See
`NOTES.md` \S15 for the full reasoning.

## Local run

This lib needs a running MySQL instance (not part of the repo) before the
driver will boot successfully -- `secure/master/security.lpc`'s
`valid_database()` grants the login/player-record connection, and login
itself depends on it. Point `secure/simulated-efuns/database.lpc`'s
`RealmsDatabase()` (returns `"RealmsLib"`) at a MySQL 8.0+ server reachable
via this driver's own `db_connect()` with `log_bin_trust_function_creators`
enabled (needed for the schema's stored functions), then:

```
cd libs/realms
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40215**.
