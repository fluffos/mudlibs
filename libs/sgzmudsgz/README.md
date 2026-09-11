# 三国志MUD

2000 年前后的 Lima mudlib 三国志游戏，来源是档案 `145_sgzmudsgz_三国志MUDsgz.tar.gz` 里的 `sgz/lib` 树（同档还有 `sgz_old` / `sgzmud`，本馆只用这一份）。和馆里已经 playable 的 `sanguozhi`（162，GitHub `fluffos/sanguozhi`）是同一家族的**不同快照**。145 已改到共享默认 FluffOS（不再需要 `ARRAY_RESERVED_WORD` / `fluffos-wilderness`）。

新玩家在华阴**草庐**（`/a/huayin/vhall`）落地：水镜先生、大砍刀、草庐留言板；西边是小村中心。中文名不能用三国人物真名（刘备、赵云会被拒）。`AUTO_WIZ` 在这份存档里是关掉的；Admin 域里已经有 2011 年线上巫师，所以新号是凡人，直接进档案世界，不必先走巫师大厅的轮回台。

## 内容亮点

- 华阴草庐起步，西去小村，再往洛阳等三国城池。
- 国家 / 官职 / 亲兵 / 历史名马，和 `sanguozhi` 同一套 SGZ 玩法。
- Lima 双层命令：`look` / `score` 走自然语言动词，`quit` / `help` 走 unix shell。

## 在线试玩

https://mudlibs.fluffos.info/sgzmudsgz/

## 试玩账号 / Play account

- **ID**: `fluffos`
- **密码 / Password**: `Play2026x`
- **显示名 / Display name**: 云游
- **权限 / Level**: 凡人（这份快照的 Admin 域已有历史巫师，不会再把第一个新号抬成 Admin）

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前请务必修改。

## 本地运行

```
cd libs/sgzmudsgz
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40196**。走共享默认 FluffOS，不要用捆绑的 32 位 ELF，也不要再用 `~/src/fluffos-wilderness`。
