# 最终幻境 (The Final Frontier)

「最终幻境」（The Final Frontier，简称 FF）是一个改写自「东方故事II」(ES2) 函数库的太空科幻题材 MUD，由 Spock 创立——是本项目 ES II/东方故事大家族里罕见的科幻换皮版本，而非武侠题材。新角色从「新手學院大廳」起步，创角时需要自行分配六项人物属性（力量/敏捷/智力/注意/體質/技術）点数，总和须为 60，游戏内的传送装置还能抵达一处「谷神星」太空站；存档自带的游戏公告声明作者已停止后续开发，十个职业/门派设定里目前也只有一个真正在世界地图上拥有落脚房间，是一份真正停摆、内容未完工的历史存档。存档原为繁体中文（BIG5）内容，已转换为 UTF-8。

## 在线试玩

https://mudlibs.fluffos.info/zzhj/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/zzhj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40099**。
