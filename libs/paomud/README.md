# PaoMUD (paomud)

Snapshot of `https://github.com/dzpao/pao-mud` (commit `f855715`,
2022-12-14). A tiny from-scratch FluffOS learning lib (“LPC 练习场”).
Slug `paomud`, number **972**, port **40281**. This collection’s copy
is a snapshot, not a live mirror.

Not a game: no accounts, rooms, or combat. Connecting drops you at a
prompt. `look` / `score` / `hello` / `test` / `quit` work. `fb` tries
a local 副本 socket on `127.0.0.1:8000` (fails cleanly if nothing is
listening).

Not a duplicate of collection `scratch` or `imud`.

## Registration flow

None. Telnet in.

## Admin / test account

None. There is no login.

Verified live 2026-09-05: connect → `look` / `score` / `quit`.

## Local run

```
cd libs/paomud
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40281**.

```
python3 scripts/mudclient.py 127.0.0.1 40281 --timeout 15 --idle 0.5 \
  --send look --send score --send quit
```
