# 终极地狱2008完整版 (zjdy2008wzb)

《终极地狱2008完整版》（REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM
1999.11.13，CDS 出品）。和本次会话已经处理过的 `hell` 档案是同一
个 Doing 血统的家族，`master.lpc`/`logind.lpc`/`named.lpc`/
`versiond.lpc` 的结构几乎逐行一致。注册流程为英文 ID → 中文姓氏 →
中文名字 → 管理密码 + 确认 → 登陆密码 + 确认 → 角色类型菜单
（1-5）→ 性别。这份档案的提示行有实时时钟，测试时用了
`--idle 0.3`。

## 本次修复的关键 bug

1. **经典 §8.1 GBK 字节区间 `is_chinese()`**（`str[i..i+1]` 字节
   对判断，176-247/161-254 区间）——改成逐码点的
   `0x4e00`-`0x9fff`；`check_legal_name()` 对应的
   `maxlen` 没有减半的上限也一并改成 `maxlen/2`，下限从 2 改成
   1。
2. **`master.lpc`（`adm/single/master.lpc`）的
   `valid_read()`/`valid_write()` 都缺少标准的
   `user == this_object()` 短路判断**——都补上了。
3. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型
   不匹配**，修好了 12 处呼叫点（几个门派 `suck`/`tan`/`zhua`/
   `hua` 档案、`clone/user/user.lpc`、`d/city/npc/guidao.lpc`、
   `cmds/std/ansuan.lpc`、`cmds/std/surrender.lpc`）。
4. **档案里没有 `log/nosave/` 目录**，导致 `logon()` 一开始的
   `log_file()` 呼叫就报"Wrong permissions for opening file
   /log/nosave/logon"，**直接把每一个连线的玩家断线**（"logon()
   ... has failed"）——建好了这个目录。这和 `yxxcii` 那份档案的同
   类问题相比，这里是会挡住整个连线的严重 bug，不只是巫师丢东西
   时的日志噪音。
5. **姓名组合最短长度检查**（`get_name()` 里的
   `strlen(fname)<4`，字节数没减半）和 **`named.lpc` 的
   `invalid_new_name()` 滑窗查重逻辑**（下限 2→1，切片
   `name[i..i+3]`/`name[i..i+5]`→`name[i..i+1]`/
   `name[i..i+2]`，循环上限 `l-4`→`l-2`，判断门槛
   `i+6<=l`→`i+3<=l`），都按 `hell` 家族已经确认的减半模式修
   了——修好前，单字姓氏和任何两字全名都会被误判"太短"。
6. **`versiond.lpc` 的 `in_server()`**（通过 `logind.lpc`
   `logon()` 里直接、没有保护的 `VERSION_D->is_version_ok()`/
   `query_temp()` 呼叫触发，所以即使不在 `adm/etc/preload` 里，
   第一次连线时也会被编译）和 `hell` 那份 `versiond.lpc` 一样，
   有真正没被掏空的 `socket_create()`/`socket_bind()` 呼叫——按
   AGENTS.md §7.52 掏空了全部 13 个碰 socket 的函式（做法和
   `hell` 的修复几乎一样）。

`adm/daemons/ftpd.lpc`、`adm/daemons/network/dns_master.lpc` 都已
经在 `adm/etc/preload` 里被注释掉，剩下的呼叫者也都是受保护的巫师
指令，属于完全休眠，本次没有改动。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（管理密码 `Mud@2026Adm`）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/zjdy2008wzb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40110**。
