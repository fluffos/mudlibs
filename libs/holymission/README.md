# Holy Mission (holymission)

A large (~24,000 `.lpc` file) MudOS-lineage archive originally run out of Linz, Austria -- the login banner reads "Welcome to the Holy Mission at Linz, Austria". A guild-and-race-based fantasy game world with a village, a church, sewers, an adventurers' guild, and extensive player/wizard-authored content spanning years of active development (the archive's own comments date from the early-to-mid 1990s onward).

Source: `github.com/speedbunny/holymission-mud`, cloned 2026-08-31.
Slug `holymission`, number 958, port 40260.

## Historical note

Confirmed MudOS/FluffOS-compatible lineage (a full-tree grep for
`driver_hook`/`set_driver_hook`/`H_[A-Z_]+` came back empty -- this is
not an LDMud archive). Even so, bringing it online required substantial
recovery and fixing work: two of the archive's most important base
classes (`sys/living.lpc`, `sys/player.lpc`) were preserved as empty
0-byte files, with the real ~3500+ line implementations misfiled under
`doc/lib/` as if they were documentation. `doc/lib/player.lpc` doesn't
even inherit `doc/lib/living.lpc`, so it independently duplicates dozens
of stat/state fields and helper functions ported verbatim from its
sibling.

The single most severe and novel bug found: a direct, explicit call to
a function literally named `reset` can silently execute as a no-op on
this driver, even when called eagerly from that very object's own
`create()` on its first-ever load -- with no compile error, no runtime
error, and no trace of any kind. This broke character stat
initialization (`score` crashed on every new character) and the
password database itself (every registered password was silently lost
across a driver restart). The fix: rename the real logic to `do_reset()`
and call that directly, keeping `reset()` as a thin pass-through. Full
technical detail is in `NOTES.md` and the project's `AGENTS.md` (new
§7.177/§7.178 entries).

## Status

Boots clean (all remaining compile errors are confined to a
well-understood, already-tolerated bucket of broken personal
wizard-content files that the mudlib's own code already wraps in
`catch()`).

Verified live end to end with a real driver and a raw socket client:
registering a brand-new character, confirming a password, entering the
game, picking a gender, arriving in a correctly lit and described
starting room, listing and choosing a race (stats update correctly),
moving to the starting church with a full room description and exits,
`score`, `quit` (which hands the connection back to a fresh login menu
-- genuine archived design, not a bug), and reconnecting with the
correct password after a full driver restart, with character state
(race, stats, guild) intact. A wrong password is correctly rejected,
confirming the login check is genuinely functional.

No outbound network connections of any kind (confirmed by source
inspection).

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/holymission
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40260**.

Connect and give a name to register a new character, or an existing
name to log back in; you'll be prompted for a password either way
(typed twice for a new character). After entering the game and picking
a gender, use `list` to see available races and `choose <race>` (e.g.
`choose human`) to finish character creation.
