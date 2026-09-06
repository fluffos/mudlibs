# MorgenGrauen (morgengrauen)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/MorgenGrauen/mg-mudlib`.
Slug `morgengrauen`, number **974**, port **40283**.
This collection’s copy is a snapshot, not a live mirror.

Official public MorgenGrauen mudlib (German LPMud, LDMud 3.x). LDMud → FluffOS conversion: archive master uses set_driver_hook/closures; catalog login lands in Die beruehmte Abenteurergilde (Port Vain). Full LDMud source tree is preserved. Not Shea690901/Sagenwelt-Lib (collection sagenwelt).

German LDMud sources are preserved for study. Interactive play
is a Strategy A start hall, not the full LDMud world. Not on the
public play site until shop/combat/guild commands are deep-tested.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) →
Die beruehmte Abenteurergilde. Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This overlay does not auto-god
  the first player.

Verified live: fluffos / Mud@2026 → Die beruehmte Abenteurergilde;
`look` / `look at tuer` / north Hafenstrasse / up Buero / `score` /
`quit`; reconnect lands in the guild again.

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
