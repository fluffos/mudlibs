# 终极地狱完整版 (zjdywzb)

《终极地狱完整版》（游戏内横幅：EMPEROR OF ULTRA HELL(BLOOD &
MAGIC) FROM 2002.06.2）。和本次会话已经处理过的 `zjdy2008wzb` 是
同一个 Doing 血统的家族，`master.lpc`/`logind.lpc`/`named.lpc` 结
构几乎逐行一致（原始档案本身就叫 `hell`）。注册流程为英文 ID →
确认(y/n) → 中文姓氏 → 中文名字 → 管理密码 + 确认 → 登陆密码 +
确认 → 角色类型菜单（1-5）→ 性别。这份档案的提示行也有实时时
钟，但测试时用 `--idle 1.0` 就够用了。

## 内容亮点

- 和 `zjdy2008wzb` 是同一个"地狱"（原始档案名就叫 `hell`）家族的
  另一个版本，游戏内横幅换成了"EMPEROR OF ULTRA HELL"，地图与门派
  布局（华山、武当、少林、丐帮、屠龙、血刀等）高度重合。
- 这份版本的 `versiond.lpc`（2194 行）远比 `zjdy2008wzb` 那份完整，
  是一个更成熟的构建/同步精灵实现，但同样因为直连 socket 而需要在
  WASM 下掏空。
- 不同于 `zjdy2008wzb`，这份档案本来就有 `log/nosave/` 目录，没有
  撞上那个会让所有连线直接断线的致命 bug；`securityd.lpc` 的存档
  权限判断也已经是正确写法，不需要修。

## 本次修复的关键 bug

1. **经典 §8.1 GBK 字节区间 `is_chinese()`**（`str[i]` 字节对判
   断，161/255/176/248 阈值 + `i%2` 奇偶判断）——改成逐码点的
   `0x4e00`-`0x9fff`；`check_legal_name()` 对应的下限从 2 改成
   1，`maxlen` 没有减半的上限也一并改成 `maxlen/2`。
2. **`master.lpc`（`adm/single/master.lpc`）的
   `valid_read()`/`valid_write()` 都缺少标准的
   `user == this_object()` 短路判断**——都补上了。
3. **姓名组合最短长度检查**（`get_name()` 里的
   `strlen(fname)<4`，字节数没减半）和 **`named.lpc` 的
   `invalid_new_name()` 滑窗查重逻辑**（下限 2→1，切片
   `name[i..i+3]`/`name[i..i+5]`→`name[i..i+1]`/
   `name[i..i+2]`，循环上限 `l-4`→`l-2`，判断门槛
   `i+6<=l`→`i+3<=l`），都按 `hell` 家族已经确认的减半模式修
   了——修好前，单字姓氏和任何两字全名都会被误判"太短"。
4. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型
   不匹配**，修好了 11 处呼叫点（几个门派 `suck`/`tan`/`zhua`/
   `hua`/`huolang` 档案、`clone/user/user.lpc`、
   `d/city/npc/guidao.lpc`、`cmds/std/ansuan.lpc`、
   `cmds/std/surrender.lpc`）。
5. **`versiond.lpc`**（2194 行，比 `zjdy2008wzb` 那份完整很多的
   构建/同步版本精灵，但属于同一类 socket 精灵 bug）——通过
   `logind.lpc` `logon()` 里直接、没有保护的
   `VERSION_D->is_version_ok()`/`query_temp()` 呼叫触发，所以即
   使不在 `adm/etc/preload` 里，每次连线都会被编译——按
   AGENTS.md §7.52 掏空了 `in_server()`、`connect_server()`、
   `clear_syn_info()`（只去掉 socket_close 循环）、
   `send_command()`、`send_client_pending_msg()`、
   `syn_finish()`（只去掉 socket_close）、
   `in_listen_callback()`、`in_write_callback()`、
   `in_close_callback()`、`cmd_close()`、`send_pending_msg()`、
   `send_result()`、`remove_connection()`（只去掉
   socket_close）里所有真正碰 socket 的呼叫；确认掏空后档案里
   已经没有任何裸的 `socket_*()` efun 呼叫，大括号也配平
   （145==145）。

`adm/daemons/ftpd.lpc`（117 处 socket 呼叫）和
`adm/daemons/network/dns_master.lpc`（5 处）都已经在
`adm/etc/preload` 里被注释掉，剩下的呼叫者也都是受保护的巫师指
令，属于完全休眠，本次没有改动。

另外确认了几处从共同的 `hell` 源码继承下来、已经是正确写法、不
需要修的地方：`securityd.lpc` 的 `save_object` `valid_write()`
判断已经正确比较 `query_save_file()+__SAVE_EXTENSION__`；
`SECURITY_D` 宏和 `adm/etc/preload` 里的路径本来就是对的，
`adm/daemons/securityd` 也已经在列表最前面；`log/nosave/` 目录
本来就存在（不像 `zjdy2008wzb` 那份缺目录导致每个连线都被断开的
致命 bug，这份档案没有这个问题）。

启动过程和退出时会反复出现一个不影响功能的
`Bad argument 4 to EFUN message()` 运行时错误（几个精灵的
`create()`/`sys_info()` 经由 `channeld.lpc` 呼叫
`simul_efun.lpc` 的 `message()` 时第四个参数传了 `int(0)`），不
影响开机、注册和管理员权限验证，本次判定为已有的驱动
`message()` 签名问题，不在这次 WASM 修复范围内，未处理。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（管理密码 `Mud@2026Adm`）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（原档
  案里已有的 `doing (admin)` 保留未动），登录后自动显示"目前权
  限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/zjdywzb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40109**。
