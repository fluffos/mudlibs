# 终极地狱完整版 (zjdywzb)

《终极地狱完整版》（游戏内横幅：EMPEROR OF ULTRA HELL(BLOOD &
MAGIC) FROM 2002.06.2）。和本次会话已经处理过的 `zjdy2008wzb` 是
同一个 Doing 血统的家族，`master.lpc`/`logind.lpc`/`named.lpc` 结
构几乎逐行一致（原始档案本身就叫 `hell`）。注册流程为英文 ID →
确认(y/n) → 中文姓氏 → 中文名字 → 管理密码 + 确认 → 登陆密码 +
确认 → 角色类型菜单（1-5）→ 性别。这份档案的提示行也有实时时
钟，测试时用 `mudclient.py --idle 0.5`（不是 1.0——会和每秒一次的
时钟刷新赛跑导致指令发不出去，详见下方"深度功能测试"一节）。
**WASM 阶段"注册流程完整验证过"的结论具有误导性**：深度功能测试
（§10.7）发现每一个新角色都会在人物创建的强制步骤上被永久卡死，
详见下方"深度功能测试"一节。

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
- 全档案 43 处留言板都有 §7.86 的致命形状（`inherit BULLETIN_BOARD`
  又多余地对自己 `replace_program`），是这个 bug 形状第五个以上确
  认命中的独立血统家族，已全部修复并 live 验证发帖成功。

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

启动过程和退出时会反复出现一个 `Bad argument 4 to EFUN message()`
运行时错误（几个精灵的 `create()`/`sys_info()` 经由 `channeld.lpc`
呼叫 `simul_efun.lpc` 的 `message()` 时第四个参数传了 `int(0)`）；
WASM 阶段曾判定为"不影响功能的驱动签名怪癖"予以保留，**深度功能
测试（§10.7）发现这个判断是错的**——它会把每一个新角色永久卡死在
人物创建流程里，详见下方"深度功能测试"一节。

## 深度功能测试（§10.7）修复的 bug

- **§7.88（AGENTS.md 本次新增）message() 包装函数漏标 `varargs`，
  缺失参数被静默填成 `int(0)` 后传给 `efun::message()` 直接崩
  溃**——WASM 阶段那个"不影响功能"的判断是错的：新角色创建流程"选
  品质"一步（在"桃源石屋"对 NPC 花铁干 `out` 离开）的
  `check_leave()` 里一次 `command("chat ...")` 频道广播会触发这个
  崩溃，而且崩溃发生在房间放行判断"之前"，导致玩家永远无法离开这
  个房间、后续的"投胎做人"流程完全走不到。每一个新角色都会撞上，
  反复输入 `out` 只会反复重现同一个崩溃。已修复
  `adm/simul_efun/message.lpc` 的 `message()`，补上 `varargs` 并给
  缺失的 `exclude` 参数加上 `|| ({})` 兜底。live 验证：修复前 `out`
  必现崩溃、角色永远卡在原地；修复后同样的房间/NPC/指令一次成功，
  完整走完"忘忧池洗天赋 → born 中原人氏"流程，第一次真正进入游戏
  世界。
- **§7.89（AGENTS.md 本次新增）自带 `runtime_config.h` 索引编号和
  驱动实际编号不一致，巫师登录时崩溃**——用巫师账号（`fluffos`）登
  录时，密码验证通过后连线彻底卡死，任何指令（包括 `look`）都没
  有任何回应。根源是 `get_config(__MUD_PORT__)` 因为这份档案自带
  的 `include/runtime_config.h` 编号和驱动实际编号对不上，静默取到
  驱动内部另一个字符串类型的配置槽位，导致
  `adm/daemons/network/messaged.lpc` 的 `socket_bind()` 收到一个字
  符串端口号而报错崩溃，把巫师登录流程从中间截断。已把
  `include/runtime_config.h` 换成驱动自带的权威版本（旧版备份为
  `runtime_config.h.orig_zjdywzb`），三处符号差异分别处理：
  `__SAVE_BINARIES_DIR__` 别名成 `__MUD_LIB_DIR__`，
  `__ADDR_SERVER_IP__`（`cmds/arch/config.lpc` 一行纯展示文字）直
  接删除，`__PORT__` 不需要别名（这个驱动本身把它当编译期预定义常
  量）。修复后巫师登录、`look`、`goto` 全部恢复正常。
- **§7.86 留言板 `post` 崩溃**：全档案 43 处致命形状全部修复，用
  巫师账号在"客店留言板"live 验证发帖成功。
- **§7.5/§8.9/§8.3a/§8.3b 均不适用**：ACL 已在 WASM 阶段修好；食
  物/饮水初始化是无条件固定值；指令表健康，注册后所有指令正常响
  应。
- **战斗测试**：与南阳城"小贩"多回合拳脚攻防，命中/闪避/擦伤判定
  正常，血量低时角色自动逃跑到相邻场景（设计内的求生保护机制），
  全程无崩溃。
- **死亡/复活流程本次未能完整走通**，记录为已知限制而非确认 bug：
  巫师 `smash` 秒杀指令未能让测试角色真正死亡/复活，怀疑与
  `combatd.lpc` `player_escape()` 里基于 `is_want_kill()` 的"逃过
  一劫"分支有关，但未用 `call` 指令直接实测验证（巫师账号的
  `call` 指令被 `SECURITY_D->valid_grant(me,"(arch)")` 拒绝，
  "(admin)" 权限似乎不自动满足 "(arch)" 授权，原因未深入排查）；
  `DEATH_ROOM->start_death()` 这个呼叫指向的函数在全档案里也没有
  任何定义。两者都留给以后有需要时再深挖。
- 本次未测试：门派拜师、商店购物、真实死斗到死亡。

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
