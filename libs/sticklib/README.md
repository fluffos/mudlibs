# StickLib (sticklib)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/StickMUD/StickLib`.
Slug `sticklib`, number **977**, port **40286**.
This collection’s copy is a snapshot, not a live mirror.

StickLib, a legacy public dump of StickMUD (turn-of-century LPMud 2.4.5 lineage on the LDMud driver, with later GMCP/MSSP/MXP/MSP/MCMP protocol work). LDMud → FluffOS conversion: catalog overlay for login/look/score/quit; original /secure/master_ldmud.lpc keeps set_driver_hook and closures. Live StickMUD historically at stickmud.com. Not collection ageofelements (different 2.4.5 fork).

Upstream StickMUD: telnet://stickmud.com:7680. This snapshot is
LDMud → FluffOS catalog play, not the full live StickMUD world.

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
cd libs/sticklib
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40286**.

```
python3 scripts/mudclient.py 127.0.0.1 40286 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
