# 仙侣情缘（早期测试版）

属于 ES II 引擎家族，与同批的"新仙侣情缘之飘渺纪元"（xlqy_new2007）
同宗同源，是同一套代码更早、更粗糙的一个开发快照。根据这份存档自带的
说明文件，它原本就是作者用来测试驱动兼容性的"半成品"版本。

## 内容亮点

- 以《西游记》为背景的仙侣题材 MUD，讲述一段人与妖、仙与凡之间的情缘
  故事，游戏世界围绕西天取经的旅程展开，穿插各类神话人物与门派恩怨。
- 内容不算完整，但核心的登录、探索、战斗流程都可以正常运作。
- 存档自带 100 个自动游走的"人造人"NPC，开服几分钟后会逐渐把地图上的
  房间全部触发编译一遍，是这份存档的特色设定。

## 在线试玩

https://mudlibs.fluffos.info/xlqy_early/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 本 lib 的最高巫师权限（通过
  `/adm/etc/wizlist` 授予，`SECURITY_D->get_status()` 据此判定）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xlqy_early
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40076**。
