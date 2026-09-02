# 郑州风云3

游戏登录后自报家门为"天下无敌"（压缩包标题"郑州风云3"是收藏者对这个具体服务器实例的称呼），属于风云（Fengyun）引擎系列，与本项目里的 `fy2`/`fy2005`/`fengyun434`/`moniHuafu` 同属一个大家族，并且和本项目另一份同样叫"郑州风云3"的档案 `zzfy3` 是近乎重复的副本——两边工作目录各有 10345 个档案，只有 163 个内容不同；两者又都和 `wqfy`（无情风云，同样打着"天下无敌"横幅）共享同一套"郑州风云"地图与结婚系统（`d/marry/hongniang-zhang.lpc` 说媒 NPC 逐字节相同）。游戏自称"一个以古龙小说为背景的泥巴游戏"，不同于本项目里常见的金庸题材武侠，走的是古龙风格潇洒不羁的江湖路线；角色创建可选择汉族/苗族/满族/蒙古族四种民族背景，死后要经历判官在鬼门关前推动的阴间轮回仪式，与 `zzfy3` 相同。

## 内容亮点

- 密码规则较严：必须同时包含大写字母、小写字母，以及至少一个数字或
  符号，长度不少于 6 位。

## 在线试玩

https://mudlibs.fluffos.info/zzfy/

## 管理员账号 / Admin account

- **ID**: `fluffos`　**密码**: `Mud@2026`　**中文名**: 浮浮
- **权限**: `(admin)`（最高级；通过 `adm/daemons/securd.o` 里 securityd
  的 `wiz_status` 数据授予——本引擎不用 `/adm/etc/wizlist` 文件，巫师表
  存在安全精灵自己的存档里）。
- 存档：`data/login/f/fluffos/fluffos.o` + `data/user/f/fluffos/fluffos.o`
  （注意本 lib 的存档比其它 lib 多一层以 ID 命名的子目录）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/zzfy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40025**。
