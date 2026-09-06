# Age of Heroes (aoh)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/seikichin/aoh`.
Slug `aoh`, number **976**, port **40285**.
This collection’s copy is a snapshot, not a live mirror.

Age of Heroes, an experimental English LDMud mudlib based on One Step Beyond (OSB). LDMud → FluffOS conversion: archive master uses closures and LDMud kernel applies; catalog login lands on the docks of Silvere harbour. Full OSB-derived source tree is preserved under /d, /lib, /std.

Based on One Step Beyond (OSB). Interactive play is a Strategy A
harbour start, not the full LDMud world. Not on the public play
site until shop/combat/guild are deep-tested.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) →
The docks (Silvere harbour). Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This overlay does not auto-god
  the first player.

Verified live: fluffos / Mud@2026 → The docks; east / southeast
to City Gate; south Seaman's Rest (`look at menu`); north
harbourmaster office; `score` / `quit`; reconnect lands on
the docks again.

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
