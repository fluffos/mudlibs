# Final Realms (finalrealms)

Final Realms (source: <https://github.com/quixadhal/fr>) is a classic, from-scratch English-language MudOS mudlib -- the last commit in its own history dates to 1998, making it the oldest-vintage lib onboarded into this collection so far. It's a full game mudlib, not just an engine: race selection (12 playable races -- Drow, Duergar, Dwarf, Elf, Half-Elf, Gnome, Goblin, Halfling, Human, Lizard-Man, Orc, Half-Orc), a real starting-zone "newbie" world per race, guilds, shops, taverns, and a full wizard toolset.

## Highlights

- Being MudOS-native (not a CD-driver codebase like some other libs in this
  collection), the compat gap with FluffOS was narrower in *kind* -- no
  `&operator(...)`/`@` composition syntax, no arbitrary uid:euid string-pair
  model -- but the 1998-era archive itself carried more incidental bitrot:
  a legacy `status` type keyword (an old LPmud alias for `int`) used
  throughout with no FluffOS equivalent, an `add_item()`/`add_feel()` pair
  declared narrower (`string`) than 1000+ live call sites actually pass
  (arrays), a missing base case for a `::`-chained save-data accessor
  quartet used by every weapon/armour object, and several newbie zones
  missing directory-local path macros or per-domain error-log directories
  (the latter was silently masking hundreds of *other* real errors behind
  a secondary "can't open the log to report this" crash). See `NOTES.md`
  for the full list.
- The single most severe bug found: this driver build was compiled with
  the older, single-efun `OLD_ED` editor interface, but this codebase's
  editor glue (`global/new_ed.lpc`, `#include`-fragmented directly into the
  player object) was written against FluffOS's newer `ed_start()`/
  `ed_cmd()`/`query_ed_mode()` API, none of which exist in this driver
  binary. Left unfixed, this would have broken compilation of the *entire
  player object* -- no one, wizard or mortal, could have connected at all.
  Rewritten against the real `ed()` efun (with a `query_ed_mode()`
  simul_efun approximated via the `in_edit()` efun this build does have).
  See `NOTES.md` \S2.
- A second, quieter but mud-wide bug: `secure/gods.lpc`/`secure/lords.lpc`
  never actually defined the `query_gods()`/`query_lords()` functions
  `secure/master.lpc` calls on every boot to build its core admin-
  permission list -- silently breaking `query_lord()`/`high_programmer()`
  for every account except the archive's own pre-blessed `god` character
  (which carries admin status directly in its save file, independent of
  this bug). Fixed; see `NOTES.md`.

## Registration flow

`name` -> confirm (`y`/`n`) -> password (real validation, hit live during
testing) -> confirm password -> gender (`male`/`female`) -> drops into the
"Hall of Creation" -> `become <race>` (one-time, permanent) -> the actual
game world. Name rules: 3-11 characters, letters only (no digits).

## Admin account

- **id**: `fluffos`
- **password**: `FluffOS2026Admin`
- **rank**: god (added to `secure/gods.lpc`'s `query_gods()` list, then
  promoted in-game with `promote fluffos` run as the archive's own
  pre-existing `god` account)

Registered through the normal registration flow first (as a mortal, so a
real player save file exists), then promoted via the in-game `promote`
command (which itself only works because of the `gods.lpc` fix above).
Verified live: `update /secure/simul_efun` (the canonical ACL check, since
it exercises both read and compile permission) succeeds for `fluffos`.

The archive's own original admin account, `god` / password `god` (per the
game's own first-boot banner), also still works and was used to perform
the promotion above -- both accounts have god-level access.

## Status

Boots clean: zero compile errors and zero uncaught runtime errors in
`log/errors/*.err` / the per-domain `d/*/log/debug.err` files across
repeated fresh-driver boots. Full registration (a brand-new character all
the way through race selection into the actual game world), `look`/
`score`/`inventory`/`quit`, re-login as an existing character, and wizard-
level `update`/`promote` all verified end-to-end with a real driver
session and a raw socket client.

A large compile-sweep tail remains beyond the fixes above (see `NOTES.md`
\S3 for the full breakdown) -- the overwhelming majority is either
genuinely dead/unreferenced legacy content shipped in the archive
(confirmed via repo-wide reference search before excluding, not guessed),
template files read as raw text rather than compiled, `#include`-fragment
files that only compile as part of their aggregator, or a repeatable
`lpcc`-batch-harness-only artifact (a per-monster `call_out` nesting
counter that only accumulates because `lpcc --batch` loads hundreds of
objects with no event-loop yielding between them -- confirmed absent on a
real driver boot). None of it blocks a real boot or blocks play.

WASM status: not attempted this session (`wasm_status` left `""`).

## Local run

```
cd libs/finalrealms
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40216**.
