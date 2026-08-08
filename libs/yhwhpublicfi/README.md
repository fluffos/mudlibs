# 炎黄武魂public-final-2016-12-08 (yhwhpublicfi)

Doing 一脉的又一个分支（`master.lpc` 文件头注明"for ES II mudlib...
updated by Doing Lu for hell (2K), modified by Linux@lxtx for yh
2003.3"），游戏内标题为《武林群侠传》之炎黄武魂。注册流程采用姓+
名分开输入，管理密码/登陆密码双密码制，角色创建时以 5 选 1 的角色
类型菜单（猛士/智慧/耐力/敏捷/均衡）取代天赋随机菜单，且没有电子
邮箱这一步。

## 内容亮点

- `master.lpc` 文件头自己的注释写明了完整传承脉络："for ES II
  mudlib... updated by Doing Lu for hell (2K), modified by
  Linux@lxtx for yh 2003.3"——直接确认这是在 `hell`（本轮已处理的
  "地狱"档案）基础上二次修改而来，地图也高度重合（同样从"世外桃
  源"起步），但新增了"药王谷"（`d/yaowang/`）等场景。
- 角色创建用 5 选 1 的角色类型菜单（猛士/智慧/耐力/敏捷/均衡）取
  代天赋随机菜单，且完全没有电子邮箱这一步，是这份档案自己的简化
  设计。
- 管理员名单是按 ID 字符串直接查表，新注册的角色不需要重新登录就
  能立刻看到管理权限生效，比大多数档案的验证方式更直接。
- 与同血统手足 `yhyxs`/`yanhuangwuhun`（yh2003 分支）一样，转档管
  线遗漏了 3 个无后缀的纯文本档案：`help/rules`（游戏规则，投胎完
  成时自动展示）和纸牌小游戏说明 `clone/game/{8,21}_hlp`，一直是
  原始 GB18030 字节，本轮已按 §4.1 的既有先例转码为 UTF-8。

## 本次修复的关键 bug

1. **经典的 §8.1 GBK 字节区间 `is_chinese()` 问题**（奇偶校验 +
   176-247/161-254 字节区间判断）——改成逐码点的
   `0x4e00`-`0x9fff` 判断，且改成检查每一个字符，而不只是第一个。
2. **三处同源的"字节数减半"长度边界 bug**，都需要按这台驱动逐码点
   字符串索引的方式减半：`check_legal_name()` 的下限
   （`strlen<2`→`strlen<1`）和上限（`maxlen`→`maxlen/2`）；
   `get_name()` 里姓名合并后的最短长度判断
   （`strlen(fname)<4`→`<2`）；以及 `named.lpc` 的
   `invalid_new_name()` 滑窗查重逻辑（下限 2→1，切片
   `name[i..i+3]`/`name[i..i+5]`→`name[i..i+1]`/`name[i..i+2]`，
   循环上限 `l-4`→`l-2`，判断门槛 `i+6<=l`→`i+3<=l`）。修复前，单
   字姓氏（比如"张"）会被误判"太长"，任何两字全名都会被误判"太
   短"。
3. **`master.lpc`（注意路径是少见的 `adm/single/master.lpc`，不是
   常见的 `adm/obj/master.lpc`）的 `valid_read()`/`valid_write()`
   直接转发给 `SECURITY_D`，没有标准的
   `user == this_object()` 短路判断**——补上后修复了注册流程中
   `new()` 静默失败卡死的问题。
4. **`versiond.lpc` 的 `in_server()` 计算
   `get_config(__MUD_PORT__) + VERSION_PORT`** 在这台 WASM 驱动
   下没有得到预期的整数，导致端口变成了字符串拼接结果
   `"12"`，每次开机都会在 `socket_bind()` 上崩溃报错"Bad argument
   2"。按 AGENTS.md §7.52（做法和 hell 系同一份 `versiond.lpc`几
   乎一致）掏空了全部 13 个碰 socket 的函式（`in_server`、
   `connect_server`、`clear_syn_info` 里的 `socket_close` 循环、
   `send_command`、`send_client_pending_msg`、`syn_finish` 里的
   `socket_close`、`in_listen_callback`、`in_write_callback`、
   `in_close_callback`、`cmd_close`、`send_pending_msg`、
   `send_result`、`remove_connection` 里的 `socket_close`），周围
   不碰 socket 的版本追踪逻辑原样保留。
5. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型不
   匹配**，在 15 处呼叫点（`kungfu/skill/*.lpc` 10 处、
   `clone/user/user.lpc`、`clone/lonely/sheying.lpc`、
   `d/city/npc/guidao.lpc`、`cmds/std/surrender.lpc`、
   `cmds/std/ansuan.lpc`）统一改成 `->query("id")` 包装。

`adm/daemons/ftpd.lpc` 和 `adm/daemons/network/dns_master.lpc` 都
已经在 `adm/etc/preload` 里被注释掉，而且除了各自 `network/` 目录
下的兄弟档案外没有其它呼叫者，属于完全休眠状态，本次没有改动。

**后续 §10.7 深度功能测试（2026-08-07）额外发现并修复**（详见
`NOTES.md`）：

6. 项目 4 当时只是给 `versiond.lpc` 一个受害者打了补丁（AGENTS.md
   §7.52 掏空 socket 呼叫），没有修根——同一份坏掉的
   `include/runtime_config.h` 索引编号还坑了 `messaged.lpc`（跨服
   UDP 聊天精灵，`tell`/`chat` 等指令依赖它），且它是**每一次新登
   录**都可能触碰到的懒加载路径，不是可以随手掏空的休眠精灵。这
   次把 `include/runtime_config.h` 整份换成驱动自带的权威版本，逐
   一处理了三处仍在用旧符号的呼叫点。
7. `adm/simul_efun/message.lpc` 的 `message()` 包装函式只声明了 4
   个必填参数，但同文件 `tell_object()`/`write()` 两处只传 3 个参
   数——每次干净重启在预加载阶段就会炸（AGENTS.md §7.88 的第二个
   独立实例），且和手足档案 `zjdywzb` 一样卡在角色创建"选品质"必
   经步骤上。已改成 `varargs`，缺参数补 `|| ({})`。
8. 任务系统共享的 `inherit/misc/quest.lpc` 的 `set_information()`
   包装函式参数类型（`string`）比它转发的精灵（`mixed`）窄，导致
   全部 8 种随机任务档案永远编译不出来（AGENTS.md §7.81 的第二个
   独立实例，另一次发生在完全不同血统的 `nt1` 上）。已放宽为
   `mixed`，一次性修好全部 8 个任务档案。

## 管理员账号 / Admin account

- **ID**: `wlqxztest`（WASM 阶段播种，密码为当时自设、本次会话无
  法复用）；**`fluffos` / `MudLogin2026`**（本轮 §10.7 深度测试按
  AGENTS.md §1.5 标准约定新增播种，两个 id 并存）。
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（这份
  档案的 wizlist 是按 ID 字符串直接查表，新注册的角色无需重新登
  录即可立刻看到管理权限），登录后自动显示"目前权限：(admin)"确
  认生效；`update`/`config` 等需要实际写权限的指令均已实测成功。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

英文 ID → `y`（确认创建新角色）→ 中文姓氏 → 中文名字 → 管理密码 +
确认 → 登陆密码 + 确认 → 角色类型菜单（`1`-`5`，例如 `5` 均衡型）
→ 性别（m/f）→ 进入游戏（世外桃源）。`score` 需要先在游戏内完成
"出生"这一步才有数据，这是游戏设计本身的限制，不是 bug。

## 本地运行

```
cd libs/yhwhpublicfi
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40132**。
