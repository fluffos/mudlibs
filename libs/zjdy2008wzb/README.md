# 终极地狱2008完整版 (zjdy2008wzb)

《终极地狱2008完整版》（REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM
1999.11.13，CDS 出品）。和本次会话已经处理过的 `hell` 档案是同一
个 Doing 血统的家族，`master.lpc`/`logind.lpc`/`named.lpc`/
`versiond.lpc` 的结构几乎逐行一致。注册流程为英文 ID → 中文姓氏 →
中文名字 → 管理密码 + 确认 → 登陆密码 + 确认 → 角色类型菜单
（1-5）→ 性别。这份档案的提示行有实时时钟，测试时用了
`--idle 0.3`。

## 内容亮点

- 姓氏 + 名字分开输入（先中文姓氏，再中文名字），并有独立的角色类
  型菜单（1-5）供开局选择，比单纯挑性别的注册流程更细致；新角色从
  "世外桃源"起步。
- 门派地图齐全（华山、武当、少林、丐帮、峨嵋、明教等），另有"屠
  龙"（`d/tulong/`）、"血刀"（`d/xuedao/`）等呼应金庸原著兵器/门派
  梗的场景。
- 注册提示行带实时时钟显示，是这批"Doing/地狱"血统档案的共同特征
  之一（和已处理过的 `hell` 档案同源，`master.lpc`/`logind.lpc`/
  `named.lpc`/`versiond.lpc` 结构几乎逐行一致）。
- 一个真正会挡住每一次连线的严重 bug：档案里根本没有 `log/nosave/`
  目录，导致每个玩家一连线就被 `logon()` 的日志呼叫直接断线（详见
  下方 bug 修复第 4 条）——这不是测试环境限定的问题。

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

## 深度功能测试（§10.7，2026-08-08）修复的 bug

手足档案 `zjdywzb` 的 §10.7 深挖发现的 §7.88/§7.89 逐条重新核实
（"移植的修复仍需逐库验证"），另外发现两处已知 bug 类别（§7.80、
§7.81）在这份档案里的独立命中。详见 `NOTES.md`；摘要：

- **§7.89（索引错位的 `runtime_config.h`）确认命中并修复**：换成驱
  动自带的权威版本，`__SAVE_BINARIES_DIR__` 别名成 `__MUD_LIB_
  DIR__`，删掉 `cmds/arch/config.lpc` 里展示 `__ADDR_SERVER_IP__`
  的那一行。修复后巫师 `fluffos` 登录、`look`、`goto`、`update` 全
  部正常。
- **§7.88（`message()` 包装函数漏标 `varargs`）代码形状相同，但本
  次未能在当前驱动构建上实测复现崩溃**——保留了修复（更严谨、和
  家族先例一致），但诚实记录这一点，详见 `NOTES.md` 与 AGENTS.md
  §7.88 的补充说明。
- **§7.80（`eventd.lpc` 文件名后缀切片 off-by-one）新命中**：
  `[0..<3]` 只删掉 3 个字符，把 `"emei.lpc"` 切成 `"emei.l"`，导致
  整个事件系统的 `collect_all_event()` 每次都打在不存在的路径上。
  改成 `[0..<5]`，修复并重启后 `debug.log` 里不再出现相关错误。
- **§7.81（`inherit/misc/quest.lpc` 的 `set_information()` 参数类
  型过窄）新命中**：8 个任务档案（`capture`/`shen`/`deliver`/
  `search`/`supply`/`judge`/`explore`/`avoid`）全部因为闭包参数类
  型不匹配而编译失败，整个随机任务子系统从存档转换之初就静默失
  效。把 `info` 参数类型从 `string` 拓宽成 `mixed`，8 个档案全部
  `update` 编译成功。
- **§7.86 留言板 `post`**：上次跨库扫描已修好，本次确认无遗漏，
  live 验证发帖成功。
- **战斗与死亡/复活流程全程走通**：与"北大街"欧阳克多回合拳脚攻
  防判定正常；巫师 `smash` 秒杀测试角色后完整走完鬼门关 → 白无常
  对话轮次（约 3 分钟）→ `reincarnate()` → 落地"武庙"（复活室）的
  全流程，没有 §7.68 类型的卡死。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（管理密码 `Mud@2026Adm`），两个
  密码都被验证流程直接接受，未触发任何变体。
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"目前权限：(admin)"确认生效。
- 注：此前 README 记录的"已播种"实际已过时——`data/login/f/`、
  `data/user/f/` 下之前没有 `fluffos` 的存档文件，说明早前的注册
  从未真正落地。本次（2026-08-08）通过正常注册流程重新播种并三重
  验证（`look` 房间路径显示、`goto`、`update`）。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/zjdy2008wzb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40110**。
