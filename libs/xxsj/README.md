# 修仙世界 (xxsj)

Snapshot of `https://github.com/Nuiio/fluffos-xiuxian-mud` (commit
`d46eef2`, 2026-06-07). A small original FluffOS 修仙 lib set on
青云宗. Slug `xxsj`, number **970**, port **40279**. This collection’s
copy is a snapshot, not a live mirror.

New characters pick a 道号 and password, awaken a random 灵根, and
start on 宗门广场. Play is Chinese: `look` / `score` (or `status`) /
`xiulian` / `quit`. Movement is `go north` (or `go 修炼室`).

## Registration flow

`2` 注册 → 道号 → password (≥4, twice) → 宗门广场.
Existing 道号: `1` 登录 → 道号 → password.

## Admin / test accounts

- **道号**: `秦风` — password `Mud@2026` (凡人, 冰灵根)
- **道号**: `fluffos` — password `Mud@2026` (凡人, 金灵根)
- Neither is auto-god.

Verified live 2026-09-05: register, `look` / `score` / `quit`,
reconnect.

## Local run

```
cd libs/xxsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40279**.

```
python3 scripts/mudclient.py 127.0.0.1 40279 --timeout 25 --idle 0.6 \
  --send 1 --send 秦风 --send Mud@2026 \
  --send look --send score --send quit
```
