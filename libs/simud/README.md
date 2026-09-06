# SIMud (simud)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/shentino/simud`.
Slug `simud`, number **978**, port **40287**.
This collection’s copy is a snapshot, not a live mirror.

SIMud, an Apache-2.0 English LDMud-style mudlib by Allaryin, Acius, Venger, and Malap. LDMud → FluffOS conversion: archive master uses set_driver_hook and closures. Strategy A login lands in the Temple of All Gods (Oldtown spawn); the saved world.obj tree is not in the snapshot. Not StickLib or Age of Elements.

Authors: Allaryin, Acius, Venger, Malap (Apache 2.0). Full mud/
tree preserved; interactive play here is the FluffOS catalog overlay.
Not on the public play site until the real world is ported and
deep-tested.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) → Temple of All Gods.
Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This overlay does not auto-god
  the first player.

Verified live after Strategy A: create fluffos / Mud@2026 → Temple
of All Gods; look / look at altar / north hall / north Oldtown /
south ×2 / score / quit; reconnect still the shrine.

## Local run

```
cd libs/simud
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40287**.

```
python3 scripts/mudclient.py 127.0.0.1 40287 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
