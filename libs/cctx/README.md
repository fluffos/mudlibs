# 驰骋天下

一个 ES2/XKX 血统的传统中文 MUD，含嘉峪关（西北边塞）相关地图区域。

## 内容亮点

- 除了华山、武当、少林、丐帮、峨嵋、明教等常见门派场景，`d/jyguan/`
  是一整片嘉峪关边塞荒漠地图（多个"荒漠"场景加城门、当铺），是这
  批档案里比较少见的西北边塞题材延伸。
- 曾有一处真实的死代码陷阱：`globals.h` 的 `SIMUL_EFUN_OB`/
  `MASTER_OB` 宏原本指向未被使用的 `/adm/single/` 副本，而真正生
  效的 `/adm/obj/` 版本才带有 `destruct()`/`remove()` 安全检查——
  不修的话迟早会重演"每个新玩家 quit 都失败"的经典故障（详见下方
  bug 修复说明）。
- 移动到欢迎室外的第一个房间会遇到"接客童子"NPC，主动介绍
  eat/drink/get/buy/sell/sleep 等基本生存指令，还会主动提示没有
  盘缠（路费）可以直接找他要——一整条由 NPC 主动搭话驱动的新手引
  导，不需要玩家先去翻帮助文件。

## 注册流程

英文名字（3-12 个英文字母）→ 确认创建（y/n）→ 中文名字 → 密码（≥5
字元）→ 确认密码 → 天赋确认（y/n）→ 电子邮件地址 → 性别（m/f）。

## 本次修复的关键 bug

- `include/globals.h` 里的 `SIMUL_EFUN_OB` 和 `MASTER_OB` 两个宏都指
  向未被使用的死代码文件 `/adm/single/{master,simul_efun}.lpc`，而
  `config.fluffos` 的 `master file`/`simulated efun file` 实际指向
  `/adm/obj/{master,simul_efun}.lpc`——两者路径不一致（和之前某些 lib
  里 `securityd.lpc`/`securd.lpc` 或 `SIMUL_EFUN_OB` 的陷阱是同一种
  教训）。真正被使用的 `simul_efun.lpc` 带有 `destruct()`/`remove()`
  安全检查覆盖，而死代码副本没有——如果不修，迟早会重演"每个新玩家
  `quit` 都失败"的经典故障。已将两个宏都指向真正被使用的文件。
- `adm/daemons/httpd.lpc`（纯 HTTP 服务器，全篇无条件调用
  `socket_*`）在 WASM 下无法编译；按"禁用整个文件的入口点"方式清空
  为 no-op。

## 深度功能测试新发现的 bug（详见 NOTES.md）

- `feature/command.lpc`（真正生效的玩家指令分发中枢）的
  `command_hook` 声明为 `private nomask`，在这个驱动上继承后会静默
  破坏 NPC `command()` 自呼叫路径（AGENTS.md §8.3a）。已去掉
  `private`，保留 `nomask`。
- `adm/daemons/logind.lpc` 的 `get_name()` 有一行调试用的
  `printf("%O\n", ob)`，会把登录物件的内部路径（如
  `/clone/user/login#1`）直接打在"您的中文名字："和"请设定您的密
  码："两个提示之间，每一个新玩家都会看到（AGENTS.md §7.34）。已
  删除。
- `adm/daemons/logind.lpc` 的食物/饮水初始化判断条件混用了两个不同
  的物件——`!user->query("food") && !user->query("water") &&
  ob->query("age") == 14`——前两个读 `user`（玩家身体），最后一个
  却读 `ob`（登录连线物件，全代码库没有任何地方给它设过 age）。这
  个条件因此永远为假，**每一个全新玩家食物/饮水槽永远是空的**，一
  进游戏就会看到"你饿得直冒金星"的挨饿提示。已改成
  `user->query("age")`（新增 AGENTS.md §8.9）。修复前后各注册一个
  全新角色对照验证：修复前食物/饮水槽全空，修复后全满。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常注
册流程创建。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/cctx
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40161**。
