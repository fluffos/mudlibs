# 铁血江湖 (Tie Xue Jiang Hu)

属于 ES II（Eastern Stories II）引擎系列武侠 mudlib，与本项目中的
wuhanzhan《大话西游》、wmkj《未明空间》等同属一个大家族，
但代码库本身是独立分支。

## 内容亮点

- 由作者 "hxsd" 开发，以帮派经营和 NPC 招募为核心特色，还内置了一套
  相当完整的商人/贸易子系统（作者自称"和大航海时代差不多"）。
- 游戏世界以中州、少林、全真等门派/城镇为骨架展开，新玩家从"英豪酒楼"
  起步，可以习武、闯荡江湖、加入帮派赚取产业收入。
- 原始服务器因人气不足与内部巫师团队矛盾而停运，此后作者公开发布了
  源码——这份归档就是那次公开发布的产物。

## 在线试玩

https://mudlibs.fluffos.info/tiexuejianghu/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: 天神 `(admin)` —— 本 lib 的最高等级，拥有完整
  巫师权限。
- 授权方式：`adm/etc/wizlist`。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/tiexuejianghu
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40087**。
