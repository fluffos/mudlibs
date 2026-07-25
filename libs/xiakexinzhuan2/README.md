# 侠客新传 (New Legend of the Wandering Swordsman)

由"Xkxz MUD Wizard Group"团队开发的武侠 mudlib，config 文件里残留着
一个"海洋II上海总站"的字段，说明这份代码大概率是从"海洋II"的引擎基
础上二次开发而来，但实际游戏内容与登录横幅都是独立的"侠客新传"。

## 内容亮点

- 游戏以"世外桃源"为起点场景，融合了角色类型（猛士/智慧/耐力/敏捷/均
  衡）、门派武功等武侠养成要素。
- 比较有特色的一点是：新角色完成基础注册后并不会立刻"投胎做人"，而是
  需要在游戏里找到 NPC"水笙"用 `register <email>` 指令完成邮箱注册，
  才能进一步选择资质、正式获得完整属性——这是这款游戏自己的新手引导
  设计，不是故障。
- 本库的定时事件系统（`adm/daemons/eventd.lpc`）因一处 `.c`→`.lpc` 改名
  遗留的字符串截取错误，启动时会静默失败（被上层 catch 住，不影响正
  常启动和游玩），详见 NOTES.md，暂未修复。

## 在线试玩

https://mudlibs.fluffos.info/xiakexinzhuan2/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib 的最高等级，通过
  `adm/etc/wizlist` 授予。该账号尚未完成本库单独的"注册邮箱
  (register/decide)"投胎流程，`score` 会和任何未投胎角色一样提示
  "还没有出生呐"——这与巫师权限无关，不影响管理使用。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiakexinzhuan2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40035**。
