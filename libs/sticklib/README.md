# StickLib (sticklib)

**LDMud → FluffOS conversion.** Snapshot of `git clone https://github.com/StickMUD/StickLib`.
Slug `sticklib`, number **977**, port **40286**.
This collection’s copy is a snapshot, not a live mirror.

StickLib, a legacy public dump of StickMUD (turn-of-century LPMud 2.4.5 lineage on the LDMud driver, with later GMCP/MSSP/MXP/MSP/MCMP protocol work). LDMud → FluffOS conversion: catalog overlay for login/look/score/quit; original /secure/master_ldmud.lpc keeps set_driver_hook and closures. Live StickMUD historically at stickmud.com. Not collection ageofelements (different 2.4.5 fork).

Upstream StickMUD: telnet://stickmud.com:7680. This snapshot is
an LDMud → FluffOS Strategy A start (temple yard, market shop,
Harry combat, Adventurers' Guild). WASM §10.7 2026-09-10.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) →
the temple yard. Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 2 Mostly Harmless after
  native guild advance). This overlay does not auto-god the
  first player.

Verified live: fluffos / Mud@2026 → temple yard; shop `buy
torch`; `kill harry`; guild `cost`; WASM §10.7 reconnect
persist (level 2, exp 1190).

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
