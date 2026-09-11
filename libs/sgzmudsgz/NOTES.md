# sgzmudsgz（三国志MUD）-- 当前 FluffOS 移植笔记

档案 `archives/145_sgzmudsgz_三国志MUDsgz.tar.gz`。嵌套树里只有
`sgz/lib` 是完整可玩 mudlib（`sgz_old` / `sgzmud` 不用）。2026-08-05
曾按「必须跟 32 位 Linux 2.0 捆绑 ELF」清出馆外；用户 2026-09-11
要求改到**当前 FluffOS**。这不是空骨架，不要造 void。

编号 **145**，端口 **40196**。手足 `sanguozhi`（162）是已经改过共享
FluffOS 的后来快照，**不能**拿 162 顶替 145。

## 驱动

不再需要 `#define ARRAY_RESERVED_WORD` / `~/src/fluffos-wilderness`。
Lima `array` 类型已改成 `mixed *` / `string *`（leftover 656），
`check_config.lpc` 的 `create()` 已掏空，`master.lpc` 补了 UID
applies。`set_this_player()` 按 sanguozhi 全部 no-op（默认驱动只在
`NO_ADD_ACTION` 分支暴露这个 efun）。

走共享默认驱动：

```
cd libs/sgzmudsgz
~/src/fluffos/build-debug/src/driver config.fluffos
```

站点 WASM 也走共享 `~/src/fluffos/build-wasm/src`，不再进
`scripts/custom_drivers/wilderness/`。`wilderness` 自己仍要那份二进制。

`config.fluffos`：`mudlib directory` 指 `work/`，`log directory : /log`
相对启动 CWD（必须 `cd libs/sgzmudsgz` 再跑 driver），
`inherit chain size : 300`，`global include file : <global.h>`。

## 转码

GB18030→UTF-8（排除 `*.tbz2` / `*.zip` / `*.exe` / `WWW.bak`）：
already_utf8=2214 converted=5461 lossy=74 skipped_binary=78，约 3546
个 `.lpc`。登录中文是干净的。

## 当前 FluffOS 上编不过 / 连不上的修法

无类型 `array` 再下标，现代驱动把元素当成 `unknown`：

- `daemons/imud/mudlist.lpc`：`array inf` → `mixed *`（否则
  `IMUD_D->query_mudlist()` 在 `real_logon()` 里直接把连线踢掉）
- `std/body.lpc` `channel_rcv_soul`、`help_d` / `soul_d` / `news_d` /
  `doc_d` / `country_d` / `area_d` / `ev_merchant/appear`：同样改成
  `mixed *`（或注释掉 `compose_message("", …)` 那行，第一参必须是
  object）
- `std/object/description.lpc`：`set_in_room_desc(mixed)`，留言板
  `(: do_desc :)` 才能编过（手足 sanguozhi §7.200）

`.c`→`.lpc` 后缀长度：`cmd_d` / `spell_d` / `quest_d` /
`troop_type_d` / `cmds/player/cmd` 的 `[0..<3]` 改 `[0..<5]`，
否则 `quit`/`help` 对不上。

`global.h` 补 `ADDR_SERVER_IP` / `ADMIN_EMAIL`（`login.lpc` 和
`secure_d` 要用）。`is_chinese()` / `valid_chinese_id()` 改 Unicode
`0x4e00–0x9fff`（§8.1）。`simul_efun/string.lpc` 的 `create()` 去掉
`nosave`，跳过 `chr(0)`。`master.lpc` `parser_error_message` 的
`array descs` → `mixed * descs`。`check_config.lpc` 的 `create()`
去掉 `nosave`。

`doc_d.lpc` 后半段 `get_dir` 类型仍编不过（preload `catch`，不挡登录）。

机械去掉 `array` 关键字时，Lima `string array a, b` 里的标量 `b`
曾被误加成 `string *`。`char_obj` 因此编不过，登录会被送去极乐世界。
已按 sanguozhi 把混写声明改回（`char_obj` / `check` / `country_d` 等）。

## 实测（本机默认 FluffOS，端口 40196）

`fluffos` / `Play2026x` / 云游。Admin 域已有历史成员，
号是凡人，进档案 `START` `/a/huayin/vhall` **草庐**：水镜先生、
大砍刀、草庐留言板。`look` / `west`（小村中心）/ `score`（云游 /
fluffos / 汉末 / 白身）/ `quit` 都通。

不要用捆绑的 `etc/driver` 32 位 ELF。不要用
`~/src/fluffos-wilderness`。

## WASM（2026-09-11 leftover 656）

共享默认 `~/src/fluffos/build-wasm/src`：`fluffos` / `Play2026x`
进草庐，`look` / `score`（云游）/ `quit` 通过。`socket.lpc` 在 WASM
下没有 socket efun（I3/HTTP），不挡登录。`doc_d` 仍编不过，preload
`catch`。
