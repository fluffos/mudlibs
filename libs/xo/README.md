# 笑傲江湖（迷你版）

属于 TMI-2/ES2（Falcon 系）引擎家族，是"笑傲江湖"系列里体积最小、内容
最精简的一个版本（作者称之为"mini xo"），与同批的"笑傲江湖最终版"
（xo_final）同宗，后者正是在这个迷你版基础上扩充而成。

## 内容亮点

- 以金庸小说《笑傲江湖》为背景的武侠 MUD，玩家扮演初入江湖的侠客，从
  一座扬州城开始自己的武林生涯。
- 作为"迷你版"，地图和门派数量都比较精简（目前只有扬州城和无量派两大
  门派），适合体验这套引擎最原始、最基础的玩法框架。

## 在线试玩

https://mudlibs.fluffos.info/xo/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 本 lib 的最高巫师权限（通过
  `/secure/etc/wizlist` 授予，`SECURITY_D->get_status()` 据此判定）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xo
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40023**。
