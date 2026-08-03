# 夕阳再现·疯狂江湖

站点子名"疯狂江湖"。属于"夕阳再现"这一支武侠 MUD 引擎家族——与本项目
中的 `xiyangzaixian_fengyun2`（风云再起Ⅱ）、`weimingkongjian`（未明
空间）、`jianghufengyun`（江湖风云单机）、`bixiecanyang`（碧血残阳）
等同源，各自是不同站点在同一套引擎基础上发展出的独立游戏世界。这一
支和另一轮处理过的 `xyzx`/`jhfy3`/`xajh4gkb`/`xyzxyl201412` 是同一
个真正的"夕阳再现"血统（`d/city/sj.lpc` 逐字节相同）——注意本项目里
还有另一批同样打着"夕阳再现"招牌、地图却是完全不同的"天涯"家族的档
案（`xysylmhb`/`xyzxiiylzymh`/`yzxiiizylfy`/`xiyangzaixian3` 等），
品牌名称不能作为判断血统的依据。

## 内容亮点

- 传统金庸武侠题材：玩家扮演初入江湖的少年少女，从平民百姓做起，游历
  各地城镇、结交门派、习练武功，逐步成长为江湖中人。
- 新手出生地点会在几个不同的江湖城镇中随机分配（如北疆小镇、铁枪庙
  等），带有典型的门派养成与角色扮演元素。
- 连线封禁检查（`band.lpc`）现在对本地/回环地址（含 WASM 浏览器连线）
  直接放行，不会再被误判为"地址不受欢迎"。

## 在线试玩

https://mudlibs.fluffos.info/xiyangzaixian_fengkuang/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 本 lib 最高权限（通过 `adm/etc/wizlist`
  授予），可使用 `update`、`goto` 等所有巫师指令。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xiyangzaixian_fengkuang
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40040**。
