# 笑傲江湖（最终版）

属于 TMI-2/ES2（Falcon 系）引擎家族，是在"笑傲江湖迷你版"（xo）基础上
大幅扩充开发而成的完整版本，作者自称"自玩测试站"，内容体量是迷你版
的数倍。

## 内容亮点

- 以金庸小说《笑傲江湖》为背景的武侠 MUD，相比迷你版拥有丰富得多的
  城市、门派、武功与任务内容。
- 玩家从"新手培训站"开始，逐步学习基本指令，领取新手礼包，然后踏入
  江湖闯荡——比迷你版更照顾新手的引导设计。
- 新角色前 10 分钟游戏内时间还不能存档退出，`quit` 时会提示二次确认，
  是防止刷号的设计。

## 在线试玩

https://mudlibs.fluffos.info/xo_final/

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
cd libs/xo_final
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40024**。
