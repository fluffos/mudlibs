# 小雪初晴II (xxcqii)

小雪初晴II（游戏内品牌"SnowMud"）同样取材温瑞安武侠小说世界观，地图可见药王谷、温家/温寨等温派小说地标；字节级比对显示，这不是姊妹档案 `xxcq`（"小雪初晴"）独立开发的续作，而是其严格意义上的超集——`xxcq` 全部约 2000 个文件的地图有 99.6% 在这里逐字节相同，另外还多出约 150 个文件的扩展内容；门派/权限阶梯用词走温瑞安风格，"护法"是介于管理员与真仙之间的一级头衔；新角色进游戏后要先在巫师楼起点场景完成邮箱登记才能继续，是这份档案独有的一道注册关卡；角色可在浣花剑庐正式拜入门下，成为"虎组"堂主李子牧名下的浣花派第六代弟子，并在少林练功房安全地对着木人桩习武。

## 内容亮点

- 取材温瑞安小说世界观（有别于金庸/古龙），地图里能看到"药王谷"
  （`d/yaowang/`）、"温家"相关场景（`wenjia`/`wenzhai`）等温派作品
  特有的地标。
- 门派/权限阶梯用词也走温瑞安风格："护法"（hufa）是介于
  `(admin)`/`(immortal)` 之间的一级头衔，档案里已经有 14 个横跨
  `(admin)`/`(hufa)`/`(immortal)`/`(apprentice)` 各阶层的既有账号。
- 新角色进入游戏后，巫师楼起点场景会要求先用 `register`/`zhuce`
  指令完成邮箱登记才能继续，是这份档案独有的一道额外注册关卡。

## 本次修复的关键 bug

**两个各自独立的 §7.52 socket 精灵 bug**：

1. `adm/daemons/httpd.lpc`——一个完全独立的网页服务器（JackyBoy@
   CuteRabbits Studio 移植），没有任何其他文件呼叫它。已经把每个碰
   socket 的函式都掏空，**并且**（按照最新的处理方式）把入口点
   `create()` 也彻底停用：不再排程 `call_out("setup", 5)`，也不再
   显示虚假的"网页服务器启动成功"讯息。
2. `adm/daemons/network/dns_master.lpc`——一个真正的多用途互联互通
   精灵（`query_mud_name()`/`muds` mapping/`query_udp_port()` 等被
   约 28 个其他服务文件呼叫：`mudlist_a`/`mudlist_q`/`gtell`/
   `gchannel`/`rwho`/`ping` 等等）。按 AGENTS.md §7.52 对多用途精灵
   的例外处理，**没有**整个文件停用，只掏空了两个真正碰 socket 的
   入口函式（`startup_udp()` 现在直接 `return 0`，正好符合它原本
   失败时的返回惯例，所以 `create()` 里的 `if (startup_udp())
   init_database();` 不需要改动就会自然跳过依赖 socket 的资料库初
   始化；`send_udp()` 变成空函式），另外清掉了 `send_shutdown()`
   里一处残留的 `socket_close()` 呼叫。

和 `xxcq` 不同，这份档案的 `SECURITY_D` 正确指向
`/adm/daemons/securityd`（不是 `securd.lpc` 的引导式模式），
`WIZLIST` 真的会在开机时被读取；`adm/etc/` 目录本身也已经存在且有
真实数据，没有 `xxcq` 那种目录缺失的问题。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（临时密码 + 确认）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（已有
  14 个跨 `(admin)`/`(hufa)`/`(immortal)`/`(apprentice)` 阶层的账
  号），登录后显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xxcqii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40131**。
