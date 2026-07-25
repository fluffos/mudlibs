# 侠客行一百 (Xia Ke Xing - Yi Bai)

取材自金庸小说《侠客行》，作者 "Coollizard" 与 "xkx100" 团队自 2001 年
起维护，属于本项目中"Century 家族"（`adm/single/` 目录结构）武侠
mudlib 分支之一，是这批游戏中文件数量最多的一个（转换后约 1.2 万个
LPC 文件）。

## 内容亮点

- 游戏世界以北京、长安、洛阳、扬州等真实历史地名为骨架，覆盖全国多个
  "出生地"供玩家选择，新角色从随机分配的出生城市客栈起步。
- 少林寺设有木人陪练（`d/shaolin/obj/mu-ren.lpc`），可通过比丘一类的
  NPC 组织的路径拜入少林门下习武。
- 融合门派、武功、天赋点数分配等传统武侠养成玩法，性格类型（冒险/
  谨慎/可人/睿智/坚韧）会影响角色的初期发展倾向。
- 独立的"侠客行时间"历法系统，会与现实时间并行显示。

## 在线试玩

https://mudlibs.fluffos.info/xiakexing100/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib 的最高等级，通过
  `adm/etc/wizlist` 授予。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiakexing100
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40037**。这是本批游戏中体积最大的一个，启动后请稍等片刻
再连接。
