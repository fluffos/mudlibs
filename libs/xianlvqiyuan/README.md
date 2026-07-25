# 仙侣情缘（知秋站 2001版）

又称 XLQY，2001年"知秋站"（www.mudfan.com）快照版本。属于"仙侣情缘"
引擎家族，与本项目另收录的"浙大版"分支同源但代码更早、更接近原始
版本。游戏内自称"西游传奇之仙侣情缘"（A Journey To The West / Fairy
Love Story）。

## 内容亮点

- 以西游记为背景的仙侠世界：从长安城南城客栈踏上取经之路，逐步修炼
  "道行境界""武学境界""法力修为""内力修为"。
- 最终目标是"西天取经"与"大闹天宫"式的成长历程，整体节奏偏休闲。
- 与"浙大版"一样有"是否为中小学生"的年龄限制问答门槛，必须回答
  `no` 才能继续注册。
- 中文取名环节没有额外确认(y/n)步骤，直接输入即由系统判断是否接受。

## 在线试玩

https://mudlibs.fluffos.info/xianlvqiyuan/

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
cd libs/xianlvqiyuan
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40032**。
