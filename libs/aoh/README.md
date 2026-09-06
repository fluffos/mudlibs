# Age of Heroes (aoh)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/seikichin/aoh`.
Slug `aoh`, number **976**, port **40285**.
This collection’s copy is a snapshot, not a live mirror.

Age of Heroes, an experimental English LDMud mudlib based on One Step Beyond (OSB). LDMud → FluffOS conversion: archive master uses closures and LDMud kernel applies; this collection boots a FluffOS catalog overlay (Void + workshop look/score/quit) while keeping the full OSB-derived source tree under /d, /lib, /std.

Based on One Step Beyond (OSB). Full world code is preserved;
interactive play here is the FluffOS catalog overlay.

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
cd libs/aoh
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40285**.

```
python3 scripts/mudclient.py 127.0.0.1 40285 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
