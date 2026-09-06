# Age of Elements (ageofelements)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/age-of-elements/age-of-elements`.
Slug `ageofelements`, number **975**, port **40284**.
This collection’s copy is a snapshot, not a live mirror.

Age of Elements, an English LPMud built from the classic 2.4.5 mudlib on the LDMud driver (telnet://ageofelements.org). Focuses on telnet protocol demos (GMCP/MSSP/MXP/MSP/MCMP). LDMud → FluffOS conversion: catalog overlay for login/look/score/quit; original /obj/master_ldmud.lpc keeps set_driver_hook and closures.

Live game historically at ageofelements.org:7680. This snapshot
is LDMud → FluffOS catalog play, not the full protocol suite.

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
cd libs/ageofelements
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40284**.

```
python3 scripts/mudclient.py 127.0.0.1 40284 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
