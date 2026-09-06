# MorgenGrauen (morgengrauen)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/MorgenGrauen/mg-mudlib`.
Slug `morgengrauen`, number **974**, port **40283**.
This collection’s copy is a snapshot, not a live mirror.

Official public MorgenGrauen mudlib (German LPMud, LDMud 3.x). LDMud → FluffOS conversion: archive master uses set_driver_hook/closures; this collection boots a FluffOS catalog overlay (login/look/score/quit in The Void) while preserving the full LDMud source tree. Not Shea690901/Sagenwelt-Lib (collection sagenwelt).

German LDMud sources are preserved for study; interactive play
here is the FluffOS catalog overlay only. Not on the public play
site until the real world is ported and deep-tested.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) → The Void.
Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This overlay does not auto-god
  the first player.

Verified live after onboard: create fluffos / Mud@2026 → The Void;
`look` / `score` / `quit`; reconnect after quit.

## Local run

```
cd libs/morgengrauen
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40283**.

```
python3 scripts/mudclient.py 127.0.0.1 40283 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
