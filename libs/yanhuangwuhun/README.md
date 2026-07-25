# 「武林群侠传」之炎黄武魂Ⅱ

属于 ES II 引擎家族（2003 年"炎黄"分支），与同批的"炎黄英雄史"系出同门，
都源自同一套 2003 年由"lxtx"改写的引擎版本。

## 内容亮点

- 融合武侠与仙侠元素的 MUD，玩家从"世外桃源"开始自己的江湖之路。
- 可以在"猛士型""智慧型""耐力型""敏捷型""均衡型"五种角色定位中选择自己
  的发展方向，逐步在武林中闯出名堂。
- 注册时设有两套独立密码：一组用于找回普通密码的"管理密码"，一组日常
  登录密码。

## 在线试玩

https://mudlibs.fluffos.info/yanhuangwuhun/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **登录密码 / password**: `Mud@2026`（游戏内"普通密码"）
- **管理密码 / recovery password**: `Admin2026`（本 lib 注册时额外设置的
  "管理密码"，仅用于找回普通密码）
- **中文名 / display name**: 浮浮（注册时姓氏一栏直接回车跳过）
- **权限 / level**: `(admin)` —— 最高权限（通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D` 据此判定）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/yanhuangwuhun
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40060**。
