# 小雨西游Ⅱ (Xiaoyu Xiyou II)

原始压缩包名为"20150716未知lib.zip"（来源不明），实际是**西游记题材、
"泥潭"（nitan）系 MudOS 老牌 mudlib** 家族的一支，与本项目中的
xiaoyuxiyou（同名系列的另一个快照）同源。

## 内容亮点

- 以《西游记》神话世界为背景，围绕取经路上的门派、法宝、妖魔展开，
  融入了经验值/潜能等类 RPG 数值成长要素。
- 游戏从长安"英豪酒楼"一类的市井场景起步，新人物可以拜师习武、结交
  江湖侠士、闯荡各地妖魔盘踞的秘境。
- 整体风格轻松、偏合家欢向，站点自述"多谢你看一看上面的游戏建议，
  祝你游戏愉快"。
- 注册需要设置两组密码（管理密码 + 登陆密码），管理密码强度要求较高
  （需混合大小写字母和数字/符号）。

## 在线试玩

https://mudlibs.fluffos.info/unknownlib20150716/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **登陆密码 / Password**: `Mud@2026`
- **管理密码 / Super password**: `Adm@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib 的最高等级（通过
  `adm/etc/notices` 授予——注意本库把 `WIZLIST` 指到这个文件而不是
  常见的 `adm/etc/wizlist`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改两个密码。

## 本地运行

```
cd libs/unknownlib20150716
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40003**。驱动内置 30 秒启动保护期，请稍候后再连接。
