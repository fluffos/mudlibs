# Wilderness (wilderness)

A production game built on the LIMA Mudlib -- the same natural-language- parser, capability-security, wizard-Unix-shell framework already onboarded in this collection standalone as `libs/lima`, but this is an independent, much older snapshot (dated May 2000) with the framework's own `AUTO_WIZ` demo convenience turned off. Real characters here start as ordinary mortals in a real, populated game world -- floating in "The Void" and stepping through a randomized portal into one of several wizard-built areas -- not as instant wizards in a bare-bones framework demo.

Source: `wlib051100.tar.gz` (`https://www.cs.hmc.edu/~jhsu/wilderness/`),
credited in its own `USAGE` file to the original LIMA Mudlib authors
(John Viega/Rust, Greg Stein/Deathblade, Tim Hollebeek/Beek, security
system by Reimer Behrends/Ellery at TMI-2). Slug `wilderness`, number
949, port 40251.

## Shared academic origin with `lpmud141`, unrelated codebase

This archive and `libs/lpmud141` ("HMC LP-mud") were both hosted on
Harvey Mudd College's `cs.hmc.edu` -- the same computer science
department's LPMud hosting tradition spanned at least two very different
eras and codebases. `lpmud141` is a mid-1990s archive so old its bundled
driver predates the "master object" security architecture altogether
(a from-scratch `master.lpc`/`simul_efun.lpc` had to be authored just to
run it on a modern driver -- see that lib's own NOTES.md). Wilderness,
by contrast, is a genuine MudOS v22.2-era game with a full, standard
master-object security daemon out of the box -- no architectural
reconstruction needed, just the usual driver-dialect porting work (see
this lib's own NOTES.md for the details, including a genuinely
infinite-recursion bug found and fixed in a stringify-macro misuse, and
a driver compile-flag conflict shared with -- but distinct from --
`libs/lima`'s own).

## Status

Boots clean under a dedicated FluffOS build (see "Local run" below --
this lib needs different driver compile flags than every other lib in
this collection, including `libs/lima`). 853 of 887 `.lpc` files pass a
full `lpcc_check.sh` batch compile sweep; the remainder are confirmed
batch-tool artifacts, one suspected driver-level (not mudlib) struct-
naming bug in an unreachable file, and pre-existing incomplete/dead
archive content (an unfinished drink-themed room, two easter-egg
"attic" NPCs, an optional contrib bulletin-board module, etc.) -- full
per-file detail in `NOTES.md`.

Verified live end to end with a real driver and a raw socket client:
registering a brand-new mortal character (8-attribute point-buy stat
allocation, a size choice, a short personality quiz), arriving correctly
lit and described in the starting room, stepping through its portal
into a real, furnished part of the world, moving between rooms,
`look`/`score`/`inventory`, `quit`, and reconnecting into the same saved
character afterward. A from-scratch admin account (`fluffos`/`Mud@2026`,
this project's standing convention) was seeded via the archive's own
"promote the first character created" bootstrap and verified functional
(`who`, `admtool`).

No outbound network connections observed or expected in normal play
(Intermud-3/`imud_d` support exists in the code but isn't preloaded by
default in this archive's own shipped `data/config/preload`).

WASM status: not yet attempted (`wasm_status` left `""` -- would need a
WASM build with the same special compile flags described below).

## Local run

This lib requires a **dedicated FluffOS build**, not the project's
shared default driver -- its own `secure/check_config.c` refuses to
boot on any driver that isn't compiled with a specific flag set (a
security check this codebase inherited from the LIMA framework). See
`NOTES.md` for exactly which flags and how the dedicated
`~/src/fluffos-wilderness` worktree was built (a few minutes, one-time,
if that checkout is ever lost). Once built:

```
cd libs/wilderness
~/src/fluffos-wilderness/build-debug/src/driver config.fluffos
```

Game port: **40251**.

Connect and give a name (letters only) to register a new character, or
an existing name to log back in; you'll be prompted for a password
either way. A brand-new character walks through 8 attribute-point
prompts, a size choice, and a short personality quiz before arriving in
the game world.
