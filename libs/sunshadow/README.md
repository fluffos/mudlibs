# Sundering Shadows (sunshadow)

A still-live, actively-developed English-language fantasy LPMud, built on a
heavily customized Nightmare/TMI-lineage mudlib base. Source cloned from
`git clone https://github.com/MudRen/SunderingShadows` (a fork of
`SuS-Tsera/SunderingShadows`). Slug `sunshadow`, number 930, port 40232.

A real, substantial archive: 43,147 files (~47MB) that the live game
auto-commits every 30 minutes, per the repo's own README. Ships a full
15-stage, command-driven character-creation wizard (class, gender, race,
subrace, template, age, stat rolling, body type, hair/eye color, language,
alignment, deity, class-special), a scripted basic-commands tutorial, and a
large, long-developed world tree. See `NOTES.md` for the full porting log,
including the two silent, total blockers found and fixed: a `set_short()`/
`set_long()` closure gap in `std/Object.lpc` that broke the very first room
every new character entered, and a `.c`-to-`.lpc`-rename casualty in the
command-dispatch daemon's filename parser that silently corrupted every
single ordinary player command name.

## Registration flow

`name` -> "Do you really wish NAME to be your name? (y/n)" -> password ->
confirm password -> ANSI color test (y/n) -> screen reader (y/n) -> email ->
lands in a void room; `press button` spawns the character-creation object
and starts the 15-stage wizard (`select OPTION` / `select random` per
stage, `sheet` to review, `reset STAGE` to redo a stage, `finalize` once
all stages are answered) -> a short scripted tutorial (`skip` to bypass) ->
the real game world.

## Status

Boots clean on the real FluffOS driver. Verified end-to-end with a raw
socket client: full registration, the complete 15-stage creation wizard,
`finalize`, tutorial skip, and `look`/`score`/`who`/`say`/`quit` all
producing correct output post-login. A character genuinely persists to
disk only once creation completes (`query_level() >= 1`), matching this
codebase's own intended save-gating, not a bug.

Known gaps (documented, not invented): `/cmds/soul/atmos.lpc` (the
emote/soul-verb fallback daemon) is referenced but entirely missing from
the archive, so emote-only input that doesn't match any real command will
fail. A handful of content files reached only via non-core background
daemons (a mage spellbook's magic-school helper, two tower/marsh-zone NPCs)
still fail to compile and were left for a future pass -- none of them sit
on the registration or basic-play path. See `NOTES.md` \S10.

WASM status: not attempted (`wasm_status` left `""`).

## Local run

```
cd libs/sunshadow
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40232**.
