# QuestMud (questmud)

QuestMud (source: <https://github.com/vlehtola/questmud>) is a real, English-language LPMud restored from a 2012 backup of a game whose "golden age" ran 1996-2000, per its own upstream README: up to 35 concurrent players and over a thousand individual registered accounts at its peak. It's a full game mudlib set in "The Isles of Deleria" -- 20 playable races (from Human and Dwarf through Golem, Lich, Demon, and Spirit rebirth races), 9 base guilds (Fighters, Mages, Clerics, Necromancers, Psionicists, Warlocks, Martial Artists, Abjurers, plus a handful of multiguild combinations like Paladin and Battlemage), a stronghold/ housing system, a mail system, and years of individual wizards' own personal build areas.

## The port: LDMud, not MudOS

Every other classic-LPMud lib in this collection so far has been
MudOS-lineage, close enough to this project's FluffOS target that the
compatibility gaps were mostly small dialect differences. QuestMud is
different: its original driver was **LDMud** (`bin/ldmud 3000` per the
archive's own `StartMud` script), a genuinely different LPC dialect --
closures (`#'name`, `lambda`/`unbound_lambda`/`bind_lambda`), a
`set_driver_hook()`-based master-object architecture instead of
FluffOS's hardcoded apply conventions, wide/multi-value mappings
(`(["key": v0; v1; v2])` with `map[key, N]` column indexing, no
FluffOS equivalent at all), and several LDMud-only efuns
(`cat()`, `tail()`, `strstr()`, `to_string()`, `object_name()`,
`unshadow()`) that simply don't exist on this driver. Porting it was a
substantially different job from every other lib here -- see `NOTES.md`
for the full technical writeup.

## Severe bugs found

Several genuinely severe, totally-blocking bugs were found and fixed,
each of which alone would have made this lib permanently unbootable:

- **`master::valid_read()` never had a case for `"load_object"`/
  `"include"`** -- FluffOS routes every single object compile and every
  `#include` resolution through `valid_read()` with these call_fun
  values, which this LDMud-derived master had never needed to handle
  (LDMud doesn't route compilation through valid_read at all). Without
  it, *every* object load and *every* `#include` in the entire 12,500+
  file mudlib was silently denied -- the single highest-impact fix in
  this whole port.
- **`master::creator_file()`'s "no special uid" case returned a bare
  int** (LDMud's own sentinel for "ordinary, non-wizard object"), but
  this driver's uid system requires a real string return always, and
  silently destructed the object being loaded if it didn't get one.
  This broke loading almost every non-wizard-owned file in the mudlib.
- **A `creator()` simul_efun used as a "reject if this looks like a
  wizard's ad-hoc clone" guard in `obj/player.lpc`'s own `reset()`**
  became permanently true for every legitimate connection once
  `creator_file()` above was fixed to always return a real uid string,
  self-destructing every single newly-registered character immediately
  after `clone_object()`. Root-caused by tracing all the way down to a
  raw uid-vs-backbone-uid comparison; see `NOTES.md` \S2.
- **This driver's `move_object()` efun is 1-arg** (moves `this_object()`
  only); this whole session's corpus-wide fix for that (`A->move_object(B)`)
  turns out to silently no-op whenever `A` isn't already `this_object()`,
  because `call_other()` never falls back to an efun of the same name.
  This affected roughly ten thousand call sites across the archive and
  is only partially remediated here (a real `move_object(dest)` method
  added to `obj/living.lpc`, covering players and monsters) -- see
  `NOTES.md` \S2 for the full severity assessment and what's still open.
- **`efun::name(...)` calls anywhere outside `secure/simul_efun.lpc`
  itself require `master::valid_override()`**, which this master never
  defined -- every `efun::` override compiled fine inside
  `simul_efun.lpc` (which loads before `master_ob` is even set) but
  failed everywhere else with "Invalid simulated efunction override."
- **FluffOS's `reset()` is scheduled/lazy, not synchronous-on-load like
  LDMud** -- several daemons whose `reset()` populates state their own
  other functions depend on (`daemons/guildrank_d.lpc`,
  `daemons/multiguild_d.lpc`, `daemons/race_stats.lpc`,
  `world/special/traits.lpc`, `guilds/guilds/guild_init.lpc`) crashed
  the very first character's own registration flow with "Value being
  indexed is zero" before their `reset()` had ever run. Fixed with an
  explicit `create() { reset(0); }` (or a direct global initializer)
  on each one -- confirmed to be a real, repeatable, and *not yet
  corpus-wide-audited* class; see `NOTES.md` \S2.

## Registration flow

`c` (create) -> character name (2-10 letters, no digits) -> password
(4+ characters) -> confirm password -> race selection room (`select
<race>`, then `continue`) -> optional special traits (`list`, `select
<trait>`, `continue`) -> guild selection (`select <guild>`) -> the real
game world. `g` logs in as a guest; `w` lists who's online; `q` quits
from the login menu.

## Status

Boots clean under the native `build-debug` driver with a
"lazy resets : 1" config override (see `NOTES.md` \S1 for why). Full
registration verified live and end-to-end with a raw socket client: a
brand-new character all the way through race selection, trait
selection, and guild selection into the real game world, followed by
working `look` (real room description, "No obvious exits.") and `score`
(a complete, correctly-formatted character sheet -- level, race, guild,
stats, HP/SP/EP, bank balance, alignment, age) and a clean `quit` that
saves the character file.

A large compile-sweep tail remains: of the archive's 12,565 `.lpc`
files, 5,829 compile clean and 6,736 do not. The overwhelming majority
(6,021 of 6,736, 89%) are inside individual wizards' own personal
sandbox directories under `wizards/` -- each wizard kept full private
copies of core files like `player.lpc`/`living.lpc` to experiment on,
never loaded by the live game (the canonical `obj/player.lpc`/
`obj/living.lpc` etc. are the only copies actually referenced). Of the
715 failures outside `wizards/`, a large fraction are
`doc/examples/*` tutorial/template content and a handful are the
`stronghold/` housing subsystem -- none block registration or the
verified play session above. See `NOTES.md` \S3 for the fix patterns
that would close most of this tail, if picked up as future work.

WASM status: **playable**. Shared WASM driver. Full new-character
registration (`c` / `wasmqm` / password / `select human` / `continue` /
`continue` / `select fighter`) into the Fighter guild of Duranghom
(five exits, guildmaster visible), plus `look` / `score` ("level 1
Human", "Primary guild: Fighters") / `quit` ("Saving Wasmqm."),
verified with `scripts/wasm_client.js`. The compile-sweep tail (LDMud
leftover syntax in wizard/cmd files) still prints at boot and on
`quit`'s drop-all path; none of it blocked the login or play session.
Play: https://mudlibs.fluffos.info/questmud/

## Local run

```
cd libs/questmud
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40247**.
