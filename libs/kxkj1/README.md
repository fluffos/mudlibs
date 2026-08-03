# 狂想空间

1995 年 9 月 22 日创建的老牌台湾 MUD（创始团队 wade、shorst、jcder
等），属于 ES II 引擎系列（与本项目中的 es1_win、esI、xkx2001、
rzrmud、侠客行系列等同宗）。本项目中还有另一个档案"新狂想空间II"
（增加了邮箱注册等更新内容），两者虽然都自称"狂想空间"，但经比对是
两个不同时期、独立流传的版本。本档案是相对更早的一个存档快照。

## 内容亮点

- 早期台湾武侠/奇幻风格 MUD，世界观相对自由，更偏向"帮派"社群玩法——
  新手会先进入"世界的入口"，再决定是否加入某个帮派闯荡江湖。
- 整体节奏偏休闲，历史悠久，保留了不少早期台湾 MUD 特有的界面风格和
  玩法设计（如 tintin 客户端脚本支持提示等）。
- 与"新狂想空间II"不同，本版没有邮箱注册这一步，注册流程更简洁。

## 在线试玩

https://mudlibs.fluffos.info/kxkj1/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` — 最高权限。
- 授权方式：`work/adm/etc/wizlist` 加入 `fluffos (admin)`。

> 警告：正式对外开放前请务必修改此密码。

## 本地运行

```
cd libs/kxkj1
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40063**。
