# 游侠笑传II (yxxcii)

《游侠笑传II》。支持双编码客户端（连线后先选择 GB 或 BIG5，BIG5
提示行在 GBK 视角下故意显示成乱码，这是刻意设计，不是转码 bug）。
注册流程为编码选择 → 英文 ID → 中文名字 → 密码 + 确认 → 天赋
（y 接受）→ 电子邮件 → 性别。

## 内容亮点

- 支持双编码客户端，BIG5 提示行在 GBK 视角下故意显示成乱码，是刻
  意设计而非转码 bug。
- 管理员称号走"主管巫师"（而非常见的"(admin)"）这套中文标签体系。
- 本次修复中发现一个真正严重、和 WASM 无关的路径错误：`SECURITY_D`
  宏指向的路径从来没对过，导致安全精灵从未被真正预载，进而让每一
  个在 `create()` 里呼叫 `seteuid()` 的其他精灵都会崩溃——包括第一
  个玩家连线本身，任何真实部署（不只是这次转档测试）都会在第一次
  连线时被驱动直接踢下线（详见下方 bug 修复第 1 条）。
- `is_killing()` 参数类型不匹配这一类 bug（详见下方第 3 条）波及
  49 处呼叫点，是本轮修复过的档案里迄今波及范围最大的一次（此前
  `zzfy3` 的 25 处曾是最大记录）。

## 本次修复的关键 bug

1. **严重的（非 WASM 专属）路径错误**：`include/globals.h` 的
   `SECURITY_D` 宏指向 `/adm/obj/securityd`，但真正的
   `securityd.lpc` 一直都放在 `adm/daemons/securityd.lpc`——这个路
   径从来没对过。`adm/etc/preload` 里也是同一个错误路径，导致
   `master.lpc` 自己 `file_size()` 判断过的 `preload()` 直接静默
   跳过（安全精灵从来没被真正预载过），而每一个在 `create()` 里呼
   叫 `seteuid()` 的其他精灵（`band`、`channeld`、`convertd`、
   `chinesed`、`combatd`、`fingerd`、`natured`、`saved`、
   `tengaoshou`、`tenrichman`）都会在 `master.lpc` 没有保护的
   `valid_seteuid()` 里崩溃，报"call_other() couldn't find object
   /adm/obj/securityd"——更严重的是，**第一个玩家连线**时
   `logind.lpc` 的 `create()`（透过编译 `clone/user/login.lpc` 时
   触发 `seteuid()`）也撞上同一个崩溃，直接被驱动断线（"logon()
   ... has failed"）。修好了宏定义和 `preload` 里的路径，还把安全
   精灵挪到 `preload` 列表最前面，让后面所有精灵的 `seteuid()` 都
   能成功。
2. **经典 §8.1 GBK 字节区间 `is_chinese()`/`check_legal_name()`**
   （`chinesed.lpc` 的 `is_chinese()` 用 `strlen%2` 奇偶判断加只
   看第一个字节；`logind.lpc` 的 `check_legal_name()` 是对应的
   `i%2==0`/`[i..<0]` 写法）——都改成逐码点的
   `0x4e00`-`0x9fff` 判断，上下限从 2/12 减半成 1/6。
3. **`master.lpc`（`adm/single/master.lpc`）的
   `valid_read()`/`valid_write()`** 补上了标准的
   `user == this_object()` 短路判断（`securityd.lpc` 的
   `save_object` 快速通道本来就正确用了
   `query_save_file()+__SAVE_EXTENSION__`，不用改）。
4. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型不
   匹配**，修好了 49 处呼叫点（主要是 `kungfu/skill/*.lpc` 底下的
   `roar`/`suck`/`zhua`/`shoot` 档案，用 `is_killing(me)` 或
   `is_killing(ob[i])`，还有 `d/city/npc/guidao.lpc`、
   `d/npc/robber.lpc`、`cmds/std/ansuan.lpc`、
   `cmds/std/surrender.lpc`、`cmds/std/nuoyi.lpc`）。
5. **档案里没有 `log/nosave/` 目录**，导致巫师丢东西时会报一次被
   拦截但看得到的"Wrong permissions for opening file
   /log/nosave/wizdrop"——建好了这个目录。

`adm/daemons/httpd.lpc`（`preload` 里根本没提到）、
`adm/daemons/ftpd.lpc`、`adm/daemons/network/dns_master.lpc`（都
已注释掉）都属于完全休眠，剩下的呼叫者也都只是宏定义或已经受保护
的指令，本次没有改动。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`（这份档案的中文标签显示为"主管巫
  师"），通过 `/adm/etc/wizlist` 授予，登录后自动显示"目前权限：
  (主管巫师)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

先选 `gb` 或 `big5` 编码 → 英文 ID → `y`（确认创建新角色）→ 中文
名字 → 密码 + 确认 → 天赋接受（`y`）→ 电子邮件 → 性别（m/f）→ 进
入游戏（客店）。

## 本地运行

```
cd libs/yxxcii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40136**。
