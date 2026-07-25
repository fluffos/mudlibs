# 狂想空间

游戏配置和进游戏后的横幅上写的都是《狂想空间》，压缩包文件名里的
"新狂想空间II"其实是收藏站点自己加的标题，并非游戏本名。这是一套
1995 年起源自"ES II"（Eastern Stories II）架构的老牌 Mud 引擎，
2002 年由台湾巫师 wade 发布，与本项目里的 es1_win、esI、xkx2001、
辽宁热线站等多个库同属 ES II 大家族。

## 内容亮点

- 背景设定是一个"古代中国"的江湖世界，主打门派、帮派制度和轻功、内功
  养成。
- 新手报到的地方叫"狂想空间新手入门房间"，里面直接给出各个方向的
  导览（新手介绍、指令快速上手、帮派说明、小秘技等），非常照顾第一次
  玩这类 Mud 的玩家。
- 天赋点数分配系统涵盖体格、定性、悟性、胆识、根骨、灵性、容貌七项
  属性，另有一项"根骨/福气"按剩余点数自动计算。
- 本地/浏览器连线现已豁免所有 IP 封禁、重连限制与同 IP 人数上限。

## 在线试玩

https://mudlibs.fluffos.info/xinkuangxiangkongjian2/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **显示名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(manager)` —— 本 lib `securityd.lpc` 权限表
  （`wiz_levels`）的最高一级（高于 `(admin)`），通过 `/adm/etc/wizlist`
  名单授予（`fluffos (manager)`）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此默认密码。

## 本地运行

```
cd libs/xinkuangxiangkongjian2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40047**。
