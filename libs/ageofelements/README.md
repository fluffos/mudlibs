# Age of Elements (ageofelements)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/age-of-elements/age-of-elements`.
Slug `ageofelements`, number **975**, port **40284**.
This collection’s copy is a snapshot, not a live mirror.

Age of Elements, an English LPMud built from the classic 2.4.5 village
(church, village green, shop, Harry, Adventurers' Guild, plains, mine,
south forest) on the LDMud driver (historically telnet://ageofelements.org).
LDMud → FluffOS conversion.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) → Village church.
Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This conversion does not auto-god
  the first player.

Verified live 2026-09-05: fluffos / Mud@2026 → church; shop buy torch;
kill Harry; death; church pray; Adventurers' Guild `cost`; hump stick/coins;
yard knife; well; bank guard; Eastroad Inn `buy 1`; plains → mine entrance
(sign + dark tunnels); south forest past the aggressive troll; quit persist.

## Local run

```
cd libs/ageofelements
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40284**.

```
python3 scripts/mudclient.py 127.0.0.1 40284 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
