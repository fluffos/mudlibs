# 笑傲江湖（迷你版）

笑傲江湖（迷你版）是以金庸小说《笑傲江湖》为背景的武侠 MUD，属于 TMI-2/ES2（Falcon 系）引擎家族，是"笑傲江湖"系列里体积最小、内容最精简的一个版本（作者称之为"mini xo"）：地图刻意做得极简，只有扬州城和一座码头小镇两座城市，可加入的门派也只有无量派一家，很适合用来体验这套引擎最原始、最基础的玩法框架；同批的"笑傲江湖最终版"（xo_final）与本档几乎逐文件沿用同一张地图、同一个无量派设定（差异只在少量文件的细节修改），再在此基础上大幅扩充出 10 座城市、16 大门派的更大世界。

## 内容亮点

- 详见上方简介：极简的双城单派地图与 xo_final 的扩充关系。

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
