# 月影奇缘

登录横幅原文亦作"世纪西游之月影奇缘"/"Moon Love Story"，一个以《西游记》 世界观为背景改编的老牌 MUD。属于 ES II 引擎系列（与 `es1_win`、 `xkx2001`、`rzrmud`、`xo` 等同源，master 文件署名可追溯到 "Lil"→ "Annihilator" 这一支）。

## 内容亮点

- 游戏架设在"西天取经"的大框架之下，新角色一入门便会被卷入取经故事线，
  还有专属的天赋点分配、师承拜师等武侠/仙侠常见玩法。
- 文本描述带有明显的世纪之交（2000 年前后）老式中文 MUD 的风味，NPC
  对话和场景描写都比较古早、朴素。
- 注册邮箱有一个历史遗留的怪规则：必须包含 "ccb" 这个子串（例如
  `xxx@ccb.com`），否则会一直提示格式不对。

## 在线试玩

https://mudlibs.fluffos.info/yueyingqiyuan/

## 管理员账号 / Admin account

- **ID**: `fluffos`　**密码**: `Mud@2026`　**中文名**: 浮浮
- **权限**: `(admin)`（最高级；通过 `adm/etc/wizlist` 授予，登录后自动
  进入巫师会议厅）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/yueyingqiyuan
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40048**。
