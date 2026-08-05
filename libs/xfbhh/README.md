# 洪荒世界（修复版）

NT/泥潭（nitan）血统，与 `hhsj`（洪荒世界原版）和 `nitan170911` 共享
byte-identical 的 master 文件。新角色从「泥潭注册室」开始。

## 内容亮点

- **注册协议**（非常规 telnet 提示，与 hhsj 同源）：连线握手后，登录行
  可用逗号分隔（`id,密码,密文,邮箱`，内部自动转换为 `║`），但新角色
  创建行必须用字面 `║`（U+2551）分隔：`性别║头像║昵称`
  （如 `0║0║秦风`）。
- `score` 会提示"还没有出生呐"——与 hhsj 相同的"降生"仪式设计，
  不是 bug。
- **投胎仪式的完整指令顺序**：进入"生命之谷"后依次 `zz <编号>`（选
  种族）→ `xuan 1`-`xuan 2`（选性别）→ `choose 1`-`choose 4`（选性
  格）→ `washto 数字 数字 数字 数字`（按膂力/悟性/根骨/身法顺序分
  配 200 点属性）——顺序错了会被提示"还没有确定好性别/种族"打回。
- 深度测试发现并修复了 CHARACTER 组成的 13 个 mixin 文件（attack、
  damage、attribute、command、move 等）里裸 `set()`/`query()` 解析
  失败的问题（AGENTS.md 新增 §7.78）——修复前每个新角色登录初始化
  本身就会崩溃，只是被驱动的错误处理器悄悄吞掉。详见 NOTES.md。

- **更正（2026-08-05）**：上面提到的"7.68 复活软锁"修复已经撤销——经重新评估，鬼魂"不在场"时放弃复活流程更可能是有意的游戏设计（多数这类档案里鬼魂本身就无法自行移动，离开是一种游荡机制，回来时 init() 会重新触发流程），不是需要强制重试的 bug；详见 NOTES.md。

## 在线试玩

https://mudlibs.fluffos.info/xfbhh/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮（4 字以内，本 lib 中文名限 2-4 字）
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。
- 登录时请使用 `fluffos,Mud@2026,x,x@example.com` 格式。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xfbhh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40190**。
