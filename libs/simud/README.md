# SIMud (simud)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/shentino/simud`.
Slug `simud`, number **978**, port **40287**.
This collection’s copy is a snapshot, not a live mirror.

SIMud, an Apache-2.0 English LDMud-style mudlib by Allaryin, Acius, Venger, and Malap. LDMud → FluffOS conversion: archive master uses set_driver_hook and closures; this collection boots a FluffOS catalog overlay (Void + workshop look/score/quit) while keeping the full mud/ tree (rooms, races, magic, economy). Not StickLib or Age of Elements.

Authors: Allaryin, Acius, Venger, Malap (Apache 2.0). Full mud/
tree preserved; interactive play here is the FluffOS catalog overlay.

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
cd libs/simud
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40287**.

```
python3 scripts/mudclient.py 127.0.0.1 40287 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
