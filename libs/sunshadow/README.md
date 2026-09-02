# Sundering Shadows (sunshadow)

A long-running, still-live English-language fantasy LPMud built on a heavily customized Nightmare/TMI-lineage mudlib base. Source cloned from `git clone https://github.com/MudRen/SunderingShadows` (a fork of `SuS-Tsera/SunderingShadows`). Slug `sunshadow`, number 930, port 40232.

## The world

A real, substantial archive: 43,147 files (~47MB) that the live game
auto-commits every 30 minutes, per the repo's own README. The
`std/races/` library lists 43 playable races: humans, elves, dwarves,
gnomes, halflings, half-elves, half-orcs, and drow sit alongside
centaurs, minotaurs, satyrs, dragonkin, wemics, kitsune, saurians,
yuan-ti, firbolgs, gnolls, bugbears, and troll-kin, with a further tier
(devils, imps, devas, soulforged, strix) locked behind account-level
approval rather than open to every newcomer. Base classes offered at
creation (fighter, thief, mage, cleric, druid, ranger, paladin, bard,
barbarian, sorcerer, monk, warlock, psion, inquisitor, magus, cavalier,
and more) are only the entry point -- dozens of prestige classes are
earned in play, from archmage, assassin, eldritch knight, and
shadowdancer to hexblade, warmind, hierophant, and arcane trickster. The
setting runs its own homegrown ten-deity pantheon -- Jarmila, Callamir,
Kreysneothosies, Ryorik, Nilith, Lord Shadow, The Faceless One, Kismet,
Lysara, and Nimnavanon -- each with a distinct portfolio and alignment
restrictions that gate which deities and class-special options a given
character can take. The persistent world spans dozens of named zones
built up over decades of individual-wizard development: the newbie
cities of Tabor and Muuldaan, the city of Shadow with its own coliseum
sparring grounds, an Underdark drow-and-derro tunnel network, a
Ravenloft-flavored gothic-horror domain, a Mesoamerican-styled
Atoyatl/Tecqumin jungle region with its own tabaxi denizens, the Dagger
forest and marsh territories, plus dedicated guild halls, a magic
college with its own demiplane, and player-run housing and shops.

## Registration flow

`name` -> "Do you really wish NAME to be your name? (y/n)" -> password ->
confirm password -> ANSI color test (y/n) -> screen reader (y/n) -> email ->
lands in a void room; `press button` spawns the character-creation object
and starts the 15-stage wizard (`select OPTION` / `select random` per
stage -- except the `stats` stage, which instead uses
`recommended`/`add N to STAT`/`reroll`/`done`; `sheet` to review, `reset
STAGE` to redo a stage, `finalize` once all stages are answered) -> a
short scripted tutorial (`skip` to bypass) -> the real game world.

## Status

Boots clean on both the native FluffOS driver and under WASM. Verified
end-to-end with a raw socket client (native) and `wasm_client.js`
(WASM): full registration, the complete 15-stage creation wizard,
`finalize`, tutorial skip, and `look`/`score`/`who`/`say`/`quit` all
producing correct output post-login on both, with no mudlib-side changes
needed for the WASM pass. A character genuinely persists to disk only
once creation completes (`query_level() >= 1`), matching this codebase's
own intended save-gating, not a bug.

Known gaps (documented, not invented): `/cmds/soul/atmos.lpc` (the
emote/soul-verb fallback daemon) is referenced but entirely missing from
the archive, so emote-only input that doesn't match any real command will
fail. A handful of content files reached only via non-core background
daemons (a mage spellbook's magic-school helper, two tower/marsh-zone NPCs)
still fail to compile and were left for a future pass -- none of them sit
on the registration or basic-play path. `adm/daemon/ipc.lpc` (an
unreferenced admin chat-relay daemon using raw sockets) fails to compile
under WASM, where the `sockets` package doesn't exist -- harmless, since
nothing else in the archive calls it. See `NOTES.md` for the full
porting and deep-functional-test log.

## Local run

```
cd libs/sunshadow
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: 40232.
