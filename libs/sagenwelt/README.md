# Sagenwelt (sagenwelt)

Snapshot of `https://github.com/Shea690901/Sagenwelt-Lib`
(`feature/player` commit `77266da`, 2016-04-03). An unfinished FluffOS
skeleton. Slug `sagenwelt`, number **973**, port **40282**. This
collection’s copy is a snapshot, not a live mirror.

Not a game: `Domains/` is empty. The archive login/player never
shipped a room. Catalog overlay: connect drops you in The Void.
`look` / `score` / `quit` work.

Not a duplicate of MorgenGrauen.

## Registration flow

None. Telnet in.

## Admin / test account

None. There is no working login.

Verified live 2026-09-05: connect → `look` / `score` / `quit`.

## Local run

```
cd libs/sagenwelt
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40282**.

```
python3 scripts/mudclient.py 127.0.0.1 40282 --timeout 15 --idle 0.5 \
  --send look --send score --send quit
```
