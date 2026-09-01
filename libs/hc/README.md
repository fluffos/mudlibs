# 红尘

游戏内全名"红尘录"，ES II 引擎家族的一支独立武侠作品。新角色的出生
地从四个场景里随机挑选：岳王庙"武庙"正殿（殿内供奉诸葛亮等历史/小
说人物，往北通往"名人堂"）、泉州铁墙、客店，以及"北疆小镇"——一座
维吾尔族聚居的边塞小镇，NPC 会用带方言腔调的台词打招呼（"小波郎子
呀克西"），是这批档案里比较少见的西域边塞民族风情场景，和其余三个
中原/江南背景形成鲜明对比。角色天赋系统包含膂力、悟性、根骨、身法
四项明面属性，以及福缘、容貌两项隐藏属性，影响解谜、奇遇与拜师际
遇；登入画面还会显示历史累计人数、历史最高在线人数等站务统计信息。

## 内容亮点

- 新角色的出生地是从四个地点里随机挑选的（`adm/daemons/logind.lpc`
  的 `start_room` 数组）：岳王庙"武庙"正殿（殿内供奉着诸葛亮等历
  史/小说人物，往北可通往"名人堂"）、泉州铁墙、客店，以及"北疆小
  镇"——一座维吾尔族聚居的边塞小镇，NPC 会用带方言腔调的台词打招呼
  （"小波郎子呀克西"），是这批档案里比较少见的西域边塞民族风情场
  景，和其余三个中原/江南背景形成鲜明对比。
- 角色天赋系统包含膂力、悟性、根骨、身法四项明面属性，以及福缘、
  容貌两项隐藏属性，影响解谜、奇遇与拜师际遇。
- 登入画面会显示历史累计人数、注册玩家数、历史最高在线人数等站务
  统计信息。

## 在线试玩

https://mudlibs.fluffos.info/hongchen/

## WASM pass修复的 bug

1. `include/restart.h` 在原始压缩包和转换后的源码里都是**真正的空文
   件**（0 字节）——这是原始代码本身就缺失的内容，不是转换过程弄丢
   的——导致 `adm/daemons/restartd.lpc` 用到的 `SHUTDOWN`/`REBOOT`/
   `HALT`/`CALLOUT_INTERVAL`/`RESTART_INTERVAL` 全部未定义。已根据
   `restartd.lpc` 自身的使用方式补全这六个常量的合理取值。
2. `adm/daemons/logind.lpc` 每次连线最开头打印欢迎信息时用
   `socket_address(ob)` 取连接端口——这是 sockets 包的 efun，这个驱
   动没有实现——已改成这个驱动真正支持、代码库其他地方也在用的
   `query_ip_port(ob)`。

## 深度功能测试新发现的 bug（详见 NOTES.md）

`adm/daemons/logind.lpc` 有两处独立的调试用 `printf("%O\n", ob)`——
分别在 `get_name()`（手打中文名字）和 `get_resp()`（接受系统随机建
议的名字）两条平行路径上，紧接在名字确认之后、密码提示之前，导致
每一个新玩家（不管走哪条取名路径）都会看到一行登录物件的内部路径
（如 `/clone/user/xxx#N`）。已删除两处（AGENTS.md §7.34）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(boss)`，通过 `/adm/etc/wizlist` 授予——这份档案
  的 `wiz_levels` 把 `(boss)` 排在 `(admin)` 之上作为真正的最高权
  限，且 `securityd.lpc` 的 `trusted_read`/`trusted_write["/"]` 都包
  含 `(boss)`。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/hc
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40107**。
