# Scratch (scratch)

Snapshot of `https://github.com/rmanis/scratch` (commit `4ac1a4e`,
2013-08-10). A three-file FluffOS starter by the Lil author. Slug
`scratch`, number **971**, port **40280**. This collection’s copy is a
snapshot, not a live mirror.

Not a game: no accounts, rooms, or combat. Connecting drops you in an
echo chamber. Unknown input is printed as `%O`. `look` / `score` /
`quit` work.

Not a duplicate of collection `lil`.

## Registration flow

None. Telnet in.

## Admin / test account

None. There is no login.

Verified live 2026-09-05: connect → `look` / `score` / `quit`.

## Local run

```
cd libs/scratch
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40280**.

```
python3 scripts/mudclient.py 127.0.0.1 40280 --timeout 15 --idle 0.5 \
  --send look --send score --send quit
```
