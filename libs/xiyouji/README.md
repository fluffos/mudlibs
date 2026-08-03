# 西游记 (A Journey to the West)

登录画面自称 *A Journey to the West*，版本号 2.01，最早制作于
1996-1998 年。本项目考证认为它极可能是"ES II / 西游记"这一整个引擎
家族（包括 `xyj2000f`、`mhxy`、`xiyouji2003`、`xiyouji2006`、
`xiyouji450`、`shenmo` 等在内的众多同题材姊妹游戏）**最早的祖先版本**
——文件时间戳最早，且没有任何后续站点加上的"破解者"署名痕迹。

## 内容亮点

- 以《西游记》原著世界观为背景的武侠/神话文字 MUD，玩家从长安城出发
  游历天下，探索小说中的经典地点（如盘丝洞、五指山、南海等）。
- 作为整个"西游记" MUD 世系的源头版本，世界内容相对朴素，是这一系列
  游戏最原始的样貌，适合对比后续各分支演化的玩家。
- 是本项目西游记大家族中唯一没有"连线地址格式"限制问题的版本。

## 在线试玩

https://mudlibs.fluffos.info/xiyouji/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 本 lib 最高权限（通过 `adm/etc/wizlist`
  授予），可使用 `update`、`goto` 等全部巫师指令。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiyouji
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40079**。
