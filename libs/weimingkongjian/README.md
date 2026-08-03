# 未明空间 (Weiming Kongjian / "wmkj")

原始压缩包自称"未明空间"，但实际连接后显示的游戏名是**"江湖风云之
夕阳再现"**——这是"夕阳再现"（Sunset Reappears）引擎系列的一个分支
版本，与本项目中的 xiyangzaixian_fengkuang、jianghufengyun 等同源，
但 master/登录/安全模块各自独立开发，并非简单换皮。这一支和另一轮
处理过的 `xyzx`/`jhfy3`/`xajh4gkb`/`xyzxyl201412` 是同一个真正的
"夕阳再现"血统——注意本项目里还有另一批同样打着"夕阳再现"招牌、地
图却是完全不同的"天涯"家族的档案（`xysylmhb`/`xyzxiiylzymh`/
`yzxiiizylfy`/`xiyangzaixian3` 等），品牌名称不能作为判断血统的依据。

## 内容亮点

- 以传统武侠江湖为背景，玩家从"武庙"一类的场景踏入江湖，习武、闯荡、
  结交侠士。
- 作者"龙宝宝(xiha)"在 2001 年发布了这份单机存档供其他人搭建自己的
  服务器游玩，因此内容截止于当时的版本状态，而非一个持续运营到今天
  的活跃游戏。
- 新角色登场时会在公共频道广播一条"听说又来了一位叫做XXX的少年侠士"
  式的欢迎消息。

## 在线试玩

https://mudlibs.fluffos.info/weimingkongjian/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(boss)` —— 与本库自带管理员 `hfzz` 同级（顶级
  实际在用等级），通过 `adm/etc/wizlist` 授予。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/weimingkongjian
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40049**。
