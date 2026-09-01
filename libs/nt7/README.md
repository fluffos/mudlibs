# 王者归来 (nt7)

底层标注"NTLIB V7"，属于本项目"泥潭/NT/nitan/Lonely"系列引擎家族的
又一独立分支——与 nitan170911（仙剑奇侠传）、nitan6（笑傲江湖）、
hhsj（洪荒世界）等库同宗同源，但核心档案（master.lpc、logind.lpc、
securityd.lpc 等）均已各自独立演化，属于不同的具体游戏。开局同样
是盘古开天地的创世场景：在"生命之谷"选择角色性格（`choose 1`-
`4`），然后在忘忧池"洗"天赋（`washto <膂力> <悟性> <根骨> <身
法>`，13-30 之间、总和不超过 80），随即自动"投胎"进入古村的世界
之树；门派、帮派威望、军功、结婚生子等系统与同家族的 hhsj/nitan6
类似，并提供 5555（GBK）、6666（UTF-8）、8888（网页版 WebSocket）
三个不同字符集/协议的端口。源码来自 GitHub 上一个已经完成 UTF-8
转码、并已适配现代 FluffOS v2019 驱动的社群维护分支
（`github.com/fluffos/nt7`）。

## 内容亮点

内容与角色创建流程详见上方简介。

## 在线试玩

（本库尚未纳入 WASM 站点批量打包流程；本地驱动运行方式见下方。）

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **普通密码 / Password**: `Mud@2026wiz`（平时登录用这个）
- **管理密码 / Admin(recovery) password**: `Mud@2026`
- **中文名 / Display name**: 浮云（姓"浮"名"云"）
- **权限 / Level**: `(boss)`（本库的最高级别，高于 `(admin)`），通过
  `/adm/etc/wizlist` 授予，已验证 `update` 指令可正常执行。
- 巫师账号会直接进入巫师休息室，不会经过普通玩家的投胎流程。

> 警告：对外公开架设前请务必修改这两个密码。

## 本地运行

```
cd libs/nt7
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40211**。
