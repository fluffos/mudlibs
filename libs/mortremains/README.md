# Mortal Remains (mortremains)

A classic English-language LPMud, admin'd by "Cyanide" from 1997 to
2000, built on the TMI-2 ("The Mud Institute") 1.4alpha mudlib base.
Released into the public domain by its original admin; source cloned
from `git clone https://github.com/clockworksoul/MortalRemains`. Slug
`mortremains`, number 929, port 40231.

A real, messy multi-author archive: ~13,500 files of genuine 1997-2000
wizard-home content from dozens of authors (Cyanide, Chronos,
Nightmask, Spooner, and many more), full TMI-2 character creation
(name, password, email, real name, then a menu-driven race/gender/
handedness/alignment/stat-reroll wizard), and a real starting town,
Decatur. See `NOTES.md` for the full porting log, including the most
severe bug found (a driver-dialect mismatch in `deep_inherit_list()`
that silently blocked every new character's registration from ever
completing) and the classic `std/monster.lpc` fix that alone recovered
~1770 cascading compile failures across the codebase's entire
NPC/monster class hierarchy.

## Registration flow

`name` -> "Is this really the name you wish to use? (y/n)" -> password
-> confirm password -> email (any format accepted) -> real name
(optional) -> a menu (`1` reroll stats, `2` swap two stats, `3`
handedness, `4` gender, `5` race, `6` alignment, `0` done, `?` help) ->
"Are you SURE..." confirm -> lands in the real game world (The YMAA,
Decatur).

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: `(adminaccess)` group membership (`adm/etc/groups`,
  grants global read/write ACL) plus the in-game wizard rank/PATH
  (seeded directly into the account's save data, since this codebase's
  own promotion command requires an already-active admin to run it --
  see `NOTES.md` \S10 for why and exactly what was seeded).

Verified live: wizard news section on login, `[NEO]` marker in `who`,
correct routing to the wizard start room, and `update <path>`
succeeding (this project's standard admin/ACL smoke test).

## Status

Boots clean, zero fatal errors. A brand-new character registers all
the way into the game world through the real registration flow (not
just "reaches a prompt"), and `look`/`score`/`who`/`quit` all produce
correct output. 6246 of 7928 `.lpc` files pass a full `lpcc_check.sh`
compile sweep -- the remainder is dominated by a completely orphaned,
unreferenced ~870-file legacy subtree (`adm/AFD/`, dead code bundled in
the archive but inherited by nothing live) plus genuinely pre-existing,
non-preloaded content gaps in personal wizard-home directories (missing
headers, abandoned drafts, truncated experiments) -- none of it
reachable from the standard registration/gameplay path. See `NOTES.md`
for the full breakdown.

**Note**: the preloaded channel daemon makes a real outbound
socket-connect attempt to a hardcoded, real (long-dead) 1999-era
Intermud-3 router address on every boot. This is genuine intended
upstream behavior, not a bug -- see `NOTES.md` \S12 before adding this
lib to any automated high-frequency reboot/test loop.

WASM status: not attempted (`wasm_status` left `""`).

## Local run

```
cd libs/mortremains
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40231**.
