# 西游记[光辉岁月]

一款 2003 年前后的"西游记"系列文字 MUD，与本项目中的
`fluffos_xiyou2000`、`xiyouji`、`xiyouji2006`、`xiyouji450`、`mhxy` 等
同属"ES II / 西游记"这一大家族——它与 `fluffos_xiyou2000` 的核心引擎
代码（`master.c`）几乎完全一致，是这条支线中较晚、内容更丰富的一个
独立站点。

## 内容亮点

- 以《西游记》世界观为背景的武侠/神话文字 MUD，玩家从长安城的南城
  客栈出发，历经"九九八十一道劫难"探索天地三界。
- 兼具门派、帮会、战役、婚姻、五行属性等较为完善的成长系统。
- 游戏内有专门的分时在线人数统计板与投票箱，社区氛围感较强，是这一
  系列中内容较为成熟的一个版本。

## 在线试玩

https://mudlibs.fluffos.info/xiyouji2003/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **巫师专用密码 / wizard second password**: `Wiz@2026`
  —— 本 lib 要求巫师账号在普通密码之外另设一个"巫师专用密码"（需包含
  大小写字母和其它字符）。巫师登录时会依次询问两个密码。
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` 主管天神 —— 最高权限（通过 `adm/etc/wizlist`
  授予），可使用 `update`、`goto` 等全部巫师指令。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改以上两个密码。

## 本地运行

```
cd libs/xiyouji2003
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40075**。
