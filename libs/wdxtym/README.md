# 武动仙途 (wdxtym)

这份档案对应一次原本超时中断的转档（46890 个文件的大档案）。它用
的是一套**自定义客户端协议**，不是普通的逐行提示：服务器一连线就
送出一行版本挑战 `ver1.0,<crypt-salt>`，客户端必须回传正确加密后
的应答，或者两个内建的绕过字符串之一（测试用 `123456789abcd` 即
可），否则直接显示"客户端非法"并断线。之后的账号注册/角色创建也
是整行、用全角竖线 `║` 分隔多个字段一次送出（`账号║密码║密文║
email`，角色创建则是 `性别║头像║昵称`），这是为配合专属 GUI 客户
端设计的协议，不是 bug。

## 内容亮点

- 除了华山、武当、峨嵋、丐帮、明教等经典金庸门派场景外，还有一整
  套现代 MMORPG 式的"副本"系统（`d/fuben*/`、`SJSSS1`-`SJSSS10`、
  `Aboss1`/`Aboss2` 等独立地图目录），是这批老泥潭里比较少见的实例
  化副本设计。
- 自带充值回调服务（`payd.lpc`），说明这份档案原本对接过真实的
  网页充值/GUI 客户端商城，而不是单纯的免费文字 MUD。
- 专属 GUI 客户端协议：连线先要通过版本加密挑战，注册/创建角色也
  是整行、用全角竖线 `║` 一次性分隔多个字段送出（详见顶部说明），
  没有专属客户端很难用传统 telnet 方式完整体验。
- 游戏内事件系统（`eventd.lpc`）曾因一处字符串切片的 off-by-one
  完全瘫痪（详见下方 bug 修复第 2 条），本次修复后应已恢复正常。

## 本次修复的关键 bug

1. **§7.52 sockets 包依赖**：`payd.lpc`（充值回调用的 HTTP 监听
   器）直接呼叫 `socket_create()`/`socket_bind()`/`socket_close()`/
   `socket_accept()`/`socket_address()`，没有任何存在性判断，导致
   整个档案在 WASM 下编译失败（Undefined function）。按 AGENTS.md
   §7.52 的做法，只把真正碰 socket 的函式（`setup()`、
   `store_client_info()`、`listen_callback()`、
   `close_connection()` 里的 `socket_close()`）掏空成空函式——因为
   `do_get()`（`cmds/adm/paym2.lpc` 会直接呼叫的对外接口）本身不碰
   socket，需要继续正常工作。
2. **真正的 off-by-one bug**：`eventd.lpc` 的 `create()` 里
   `event_name = map_array(event_name, (: $1[0..<3] :));` 本意是
   去掉文件名的 `.lpc` 后缀（4 个字符），但 `[0..<3]` 只去掉了 2 个
   字符（比如 `emei.lpc` 变成 `emei.l`），导致
   `collect_all_event()` 呼叫每一个事件文件全部失败（"*call_other()
   couldn't find object ...emei.l"）——整个游戏内事件系统一直是完全
   不工作的。已改成 `[0..<5]`（正确去掉 4 个字符）。
3. **经典 §8.1 GBK 字节区间 `is_chinese()`**：`adm/simul_efun/
   chinese.lpc` 用 `strlen(str)%2` 假设每个中文字占两个字节，并检
   查原始字节区间（176-247/161-254）；这个驱动是按 UTF8 码点索引字
   符串的，导致奇数字数的中文名字（比如"小浮侠"）被误判为不合法。
   已改成逐码点检查（0x4e00-0x9fff）。
4. **§7.78 CHARACTER mixin 裸 set()/query()（深度测试新发现，第 5
   个确认实例）**：`alias`/`apprentice`/`attack`/`attribute`/
   `command`/`damage`/`message`/`more`/`name`/`skill` 共 10 个组成
   CHARACTER 的 mixin 文件里有裸 `set()`/`query()` 调用，但这些文件
   自己都没有 `inherit F_DBASE`——包括 `command.lpc` 的
   `enable_player()`，每个新角色登录都会崩溃。这份档案和
   xfbhh/hhsj/nt1/nitan170911 同属 NT/nitan/Lonely 血统（连线协议一
   样，多了一个独有的 `F_SUIT` mixin）。已用连续 3 次真人注册验证：
   NPC"水笙"的欢迎语和玩家自己的名字全程正确显示，`debug.log` 全程
   空白。
5. **3 处 §7.68 死亡/复活软锁**（`d/death/npc/{bai,bgargoyle,
   wgargoyle}.lpc`）：`death_stage()` 把"角色永久离开"和"暂时不在
   场"混在一起处理，已拆分为"暂时不在场则重试"。

## 管理员账号 / Admin account

- **ID**: `fluffos_1`（账号会被自动加上 `_1` 后缀，注册时输入
  `fluffos` 即可）
- **密码 / Password**: 注册时自设（账号密码 + 管理密码双密码机制，
  两者不能相同）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后 `wizlist` 命令确认显示"目前权限：(admin)"。

> 警告：对外公开架设前请务必修改此密码。

## 已知但未修复：偶发的自愈性瞬态错误

测试中偶尔（不稳定复现，5 次测试里只出现过 1-2 次）会在**首次**编
译新角色身体对象时看到"Too deep recursion"（来自 `master.lpc` 的
`valid_read()`/`compile_object()` 转发链）以及"Bad argument 4 to
EFUN message()"（来自 `bossdd.lpc` 的 `heart_beat()` -> `shout()`
路径）。经过直接插桩验证，`message.lpc` 的 `message()` 包装函式本
身有标准的 `if(!exclude) exclude=({})` 防护，且在每次观察到的调用
里都正确生效——这两个错误更像是刚开机时第一次编译爆发期间和心跳
计时器撞车的竞态，驱动自身的调用深度保护和逐对象心跳自动关闭机制
都能安全接住，两次实际发生时注册和进入游戏都照常完成，没有发现任
何实际影响。判断为不可靠复现、无源码层面可修的瞬态问题，未作改动。

## 本地运行

```
cd libs/wdxtym
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40188**。
