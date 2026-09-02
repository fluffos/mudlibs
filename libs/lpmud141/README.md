# LPmud 1.4.1-A (lpmud141)

A historically significant early LPMud reference mudlib -- "HMC LP-mud" (Harvey Mudd College), version 1.4.1-A, bundled together with the original classic C-language LPMud driver it shipped with (ignored here; this project uses its own FluffOS build). Only the mudlib itself was ported. This is a genuinely small, from-a-university-account game, not a commercial title: a starter guild, an Endoplasmatorium, a village green, a clinic, an elevator, some mines, a maze, basic wizard tooling and soul/emote commands -- thin by design, not by omission.

Source: `lpmud-1.4.1-A-r10.tar.gz`, recovered via the Wayback Machine
from mudmagic.com (`codes/dl/2154/lpmud-1.4.1-A-r10.tar.gz`), a now-defunct
MUD community site. Slug `lpmud141`, number 941, port 40243.

## Historical note

This driver's own source has no concept of a "master object" anywhere --
confirmed by reading it directly, not by absence of a file. It predates
the security-daemon/uid architecture that every later LPMud/MudOS/FluffOS
descendant (including every other lib in this collection) standardized
on. Bringing this online required authoring a `secure/master.lpc` and
`secure/simul_efun.lpc` from scratch (pure driver-glue reproducing this
driver's own hardcoded C behavior), plus fixes for several fundamental
dialect differences: a two-call `add_action()`/`add_verb()` verb
registration idiom, a `move_object(item, dest)` that moves an arbitrary
object rather than just the caller, and a `reset(arg==0)` "first-time
setup" convention that this driver's own object lifecycle doesn't fire
synchronously the way this archive expects. Full technical detail,
including exactly what was authored vs. what's original archive content,
is in `NOTES.md`.

## Status

Boots clean. 146 of 150 `.lpc` files pass a full `lpcc_check.sh` batch
compile sweep; the 4 that don't are confirmed test-harness-only false
positives (two files that are genuinely include-only/template fragments
never meant to compile standalone, and two files whose first-run setup
code needs a real connected player that the standalone compile-checker
doesn't provide) -- see `NOTES.md` for the per-file detail.

Verified live end to end with a real driver and a raw socket client:
registering a brand-new character (letters-only name, matching this
archive's own original `valid_name()` rule), arriving in a correctly
lit and described starting room, moving between several different rooms,
`soul on` plus emote commands (e.g. `smile`), `score`, `quit`, and
reconnecting into the same saved character afterward -- including across
a full driver restart.

No outbound network connections of any kind (confirmed by source
inspection, not just by absence of symptoms).

WASM status: `playable`. Clean WASM boot and full session (register,
look, score, quit) with zero fixes needed. See `NOTES.md` \S10.

## Local run

```
cd libs/lpmud141
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40243**.

Connect and give a name (1-11 lowercase letters, no digits -- this
archive's own original rule) to register a new character, or an existing
name to log back in; you'll be prompted for a password either way (typed
twice for a new character).
