# 仙侣情缘·浙大版

由 bugbug 与 alading 在"缥缈水云间"站点基础上二次开发。属于"仙侣情缘
/XLQY"引擎家族的一个独立分支（与本项目另收录的《仙侣情缘》知秋站
2001版代码不同，虽然核心引擎同源）。

## 内容亮点

- 一个西游记题材的仙侠世界：从长安城的南城客栈开始冒险，逐步领悟
  "道行境界""武学境界""法力修为"等修行体系。
- 整体基调偏神话/仙侠而非纯武侠，人物成长围绕"西天取经""大闹天宫"等
  西游记经典桥段展开。
- 注册流程有一道"是否为中小学生"的年龄限制问答，回答 `no` 才能继续，
  是站方刻意设置的门槛。
- 新角色可分配体格/根骨/悟性/灵性四项天赋属性，或直接接受系统默认值。

## 在线试玩

https://mudlibs.fluffos.info/xlqyzdb/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **显示名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— securityd `wiz_levels` 中的最高级，通过
  `adm/etc/wizlist` 授予（`fluffos (admin)`，启动时读入）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xlqyzdb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40033**。
