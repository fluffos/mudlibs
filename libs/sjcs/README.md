# 三界传说 (San Jie Chuan Shuo)

以中国古典神话"三界"（天界/人间/地府）为背景的江湖世界，新角色从长安城"南城客栈"起步，客栈内的告示板汇聚玩家心得、巫师反馈与最新更新公告。注册时天赋分配全程透明：玩家自行决定体格/根骨/悟性/灵性四项点数的分配比例，默认平均分配，也可调整后再确认；拜师体系分明，门派各有不同门槛，可先拜同门中的低阶师父再逐步靠近掌门；法术体系分修行/攻击/防御/其它四大类，涵盖飞行、变化、天眼通、天耳通等经典法术效果，`wimpy` 自动逃命阈值可自行调节比率（新手建议设高一些，50-70，以避免无谓战死），`fight`/`kill` 均支持，特殊技能需先 `enable` 才能在战斗中使用。与本项目中同样带"三界"招牌的 `sanjieshenhua` 只是名字相似，经逐文件比对确认并非同一份代码（`master.lpc`/`securityd.lpc`/`logind.lpc` 均差异显著），两者是各自独立的作品。

## 在线试玩

https://mudlibs.fluffos.info/sjcs/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/sjcs
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40097**。
