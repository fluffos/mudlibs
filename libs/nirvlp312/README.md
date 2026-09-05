# Nirvana LP312 (nirvlp312)

Snapshot of `https://github.com/rumplemintz/Nirvlp312mudlib` (commit
`616cad7`, 2017-09-21). LPMud 3.1.02-DR / modified 2.44 mudlib,
established 26 February 1991. Slug `nirvlp312`, number **968**, port
**40277**. This collection’s copy is a snapshot, not a live mirror.

Welcome banner: “Nirvana / An LpMud version 3.1.02-DR / running a
modified 2.44 mudlib”. English play. New characters finish creation
in the Adventurers' guild; later logins land on the Village Green.

Not a duplicate of `lpmud141` (that archive has no master) or
collection `questmud`.

## Registration flow

Name → New character → password (≥6, twice) → password hint →
gender (`male`/`female`) → race (`human`/`elf`/`dwarf`/`custom …`)
→ height feet → inches → weight (lbs) → approve (`y`) → where you
heard of Nirvana (`none` is fine).

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This lib does not auto-god
  the first player.

Verified live 2026-09-05: create fluffos / Mud@2026 → Adventurers'
guild; reconnect lands on Village Green; `look` / `score` / `quit`.

## Local run

```
cd libs/nirvlp312
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40277**.

```
python3 scripts/mudclient.py 127.0.0.1 40277 --timeout 55 --idle 0.7 \
  --send fluffos --send Mud@2026 --send none \
  --send look --send score --send quit
```
