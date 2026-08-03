# 浴血重生

登录横幅自称 "1.YXCS"/"浴血重生"。血统比较特殊：既有 ES II 引擎系列的
痕迹（`chinesed.lpc` 等文件署名可追溯到 "ES"→"XKX" 一支），又混入了
"Lonely"（"nitan/NT" 系列的作者）后期改写的部分模块，属于一个 ES 系底子
上被二次深度魔改的分支，不是纯血统的任何一支。地图这一层可以更精确地
定位：`d/city/sj.lpc`（"世界之巅"跳崖场景）和"天涯"家族逐字节相同
（与 `xysylmhb`/`xyzxiiylzymh`/`yzxiiizylfy`/`xyzx3`/
`tianxiawuxue` 这批同样打着别的招牌、实际却是"天涯"血统的档案一致），
"Lonely"这条线索也和 `tianxiawuxue` 鸣谢名单里的同一位作者相呼应。

## 内容亮点

- 传统武侠江湖设定，主线围绕"浴血重生"这个带有江湖恩怨、重新做人的
  主题展开。
- 角色创建时可以自由选择"国际挑战者"式的比武活动、门派拜师、以及各类
  武功技能，整体内容比较完整、系统衔接也比较扎实。
- 有一处防盗号保护：已在 wizlist 中登记为高权限的 ID 无法在注册流程中
  设置密码，需先从名单移除、注册完成后再加回去。

## 在线试玩

https://mudlibs.fluffos.info/yxcs/

## 管理员账号 / Admin account

- **ID**: `fluffos`　**密码**: `Mud@2026`　**中文名**: 浮浮
- **权限**: `(boss)`（本 lib 巫师等级表的最高级"巫师协会懂事"；通过
  `adm/etc/wizlist` 授予）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/yxcs
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40056**。
