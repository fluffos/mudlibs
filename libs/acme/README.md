# Acme MUD (acme)

Snapshot assembled from `https://github.com/acmemud/acme-mudlib` plus
sibling repos `acme-platform`, `acme-flavor-basic`, and
`acme-flavor-rpg` (2016–2017). Experimental LDMud 3.x framework by
`devo@eotl`, formerly “untitled gamification platform.” Slug `acme`,
number **969**, port **40278**. This collection’s copy is a snapshot,
not a live mirror.

English play. The archive never shipped a finished world (the RPG
flavor is one combat module). New characters land in The Void; a
workshop sits to the north.

Not a duplicate of any lib already in this collection.
`Cloudxtreme/eotl-mudlib` is a separate utility fragment.

## Registration flow

Name (2–16 letters) → new character: password (≥6, twice) → The Void.
Existing names prompt for password only.

## Admin / test account

- **name**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: seeded mortal (level 1). This lib does not auto-god
  the first player.

Verified live 2026-09-05: create fluffos / Mud@2026 → The Void;
reconnect after quit; `look` / `score` / `quit`.

## Local run

```
cd libs/acme
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40278**.

```
python3 scripts/mudclient.py 127.0.0.1 40278 --timeout 25 --idle 0.6 \
  --send fluffos --send Mud@2026 \
  --send look --send score --send quit
```
