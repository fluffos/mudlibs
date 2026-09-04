
## WASM 修复摘要（迁移自 meta.json 的 group_note）

游侠笑传II。双编码客户端支持（新连线会先提示选择 GB 或 BIG5 才继续登录流程——BIG5 风格的提示行如果用 GBK 解读会故意显得乱码，这不是转档错误）。WASM 修复找到并修好了一个严重的、转档之前就存在（不是 WASM 特有）的 bug：include/globals.h 的 SECURITY_D 宏指向 '/adm/obj/securityd'，但真正的 securityd.lpc 档案其实一直放在 'adm/daemons/securityd.lpc'——这是一条从未真正有效过的路径。adm/etc/preload 里也引用了同样错误的 '/adm/obj/securityd' 路径，导致 master.lpc 自己那个受 file_size() 门槛保护的 preload() 对它静默地空转（从未真正加载），而每一个其它被预加载、create() 里呼叫了 seteuid() 的精灵（band、channeld、convertd、chinesed、combatd、fingerd、natured、saved、tengaoshou、tenrichman）都会因为 master.lpc 未加保护的 valid_seteuid() 而崩溃报"call_other() couldn't find object /adm/obj/securityd"——更糟的是，第一个玩家连线的 logind.lpc create()（本身是通过 clone/user/login.lpc 编译过程中的 seteuid() 触发的）也撞上了同一个崩溃，驱动直接把用户断线了（"new_conn_handler: logon() ... has failed"）。已把宏和 preload 条目都修正指向真实路径（还把 securityd 挪到了预加载列表最前面，让之后每一个精灵的 seteuid() 呼叫都能成功）。另外还修复了：（1）经典的 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug（adm/daemons/chinesed.lpc 的 is_chinese() 用的是 strlen%2 奇偶门槛加只检查 str[0] 的字节判断；adm/daemons/logind.lpc 的 check_legal_name() 有对应的 i%2==0/[i..<0] 写法）——两处都重写成逐码点 0x4e00-0x9fff 检查，界限从 2/12 减半为 1/6。（2）master.lpc（adm/single/master.lpc）的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 短路判断——两处都已加上（securityd.lpc 的 save_object() 快速路径本来就正确使用了 query_save_file()+__SAVE_EXTENSION__，不需要修）。（3）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 49 处呼叫点（大多是 kungfu/skill/*.lpc 的 roar/suck/zhua/shoot 档案用 is_killing(me) 和 is_killing(ob[i])，另外还有 d/city/npc/guidao.lpc、d/npc/robber.lpc、cmds/std/ansuan.lpc、cmds/std/surrender.lpc、cmds/std/nuoyi.lpc）。（4）压缩包里缺少 log/nosave/ 目录，导致巫师丢弃道具日志时出现一个被捕获但可见的'Wrong permissions for opening file /log/nosave/wizdrop'——已创建该目录。adm/daemons/httpd.lpc、adm/daemons/ftpd.lpc、adm/daemons/network/dns_master.lpc 都处于休眠状态（httpd 完全不在预加载列表里；ftpd/dns_master 被注释掉；剩下的呼叫者只是档头宏定义或已经带保护的指令）——保持原样。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（在这份档案的中文 wiz_levels 标签里显示为'主管巫师'）。注册流程在格式化前后都完整验证过（GB/BIG5 编码选择→id→y 确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件→性别→进入客店），管理员权限已通过'目前权限：(主管巫师)'确认。LPC 格式化工具对全部 6493 个档案运行（写入 6465 个，28 个转档之前就存在的错误，0 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 48 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/single/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   `read_file()` 对不存在的文件返回非字符串 `0`，直接传给
   `write()` 会崩溃——未在本档案现场触发，属主动加固，改成
   `write(msg || "");`。

### Proactive checks（无需改动）

- §8.9 食物/饮水初始化不适用：`init_new_player()` 直接无条件
  `user->set("food", 700); user->set("water", 700);`，不涉及
  `ob`/`user` 混淆读取。
- `logind.lpc` 里唯一的 `printf("%O", ...)` 出现在一段已经被
  `/* ... */` 整体注释掉的死代码块里，不是活跃泄漏，未改动。
- `get_id()` 签名是 `(string arg, object ob)`，全档案三处
  `input_to("get_id", ob)` 调用点参数个数都一致，未发现
  yxjh 那种参数错位。
- `feature/dbase.lpc` 未发现密码写保护，不适用 tybxjh/wlhd 那一类
  bug。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:177`、`d/city/npc/jinyong.lpc:199`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`。

### 实测过程

`adm/etc/wizlist` 里的 `fluffos (admin)` 一直没有对应存档。本轮通
过完整注册流程创建（先选 GB 编码 → id → y → 中文名 → 密码 ×2 → 天
赋接受 y → email → 性别 m），落地"巫师休息室"，`score` 显示"目前
权限：(主管巫师)"，食物/饮水满格。随后**连续两次**真实断线重连+
密码验证（每次都重新走一遍 GB 编码选择）：均成功登录，存档数据一
致，两次重连均未触发任何异常（未复现 yxjh 那类仅在连续快速重连时
才出现的错位崩溃）。全程 `debug.log` 无运行时错误。驱动按精确 PID
结束；管理员存档已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,160 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
用 `fix_710_room.py` 扫过 `work/`，删除 2,159 处标准形状；
`clone/misc/roommaker.lpc` 剩下 1 处字符串拼接变体，手工改成
`str += "\n\tsetup();\n}\n";`（同一工具的 heredoc 模板已被脚本正
常扫到）。修复后 `work/` 下 0 处存活残留，39 处转档之前已注释掉的
`//` 行原样保留，`work/data/` 下没有真实 `.lpc` 源码命中。`git diff
--stat` 显示 2159 个文件净删 2160 行，与脚本自报数字 + 1 处手工编
辑吻合。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行）。登录用了这份档案自己的
GB/BIG5 双编码选择流程（先送 `gb`），巫师账号 `fluffos`/`Mud@2026`
登录后确认"目前权限：(维护巫师)"，`look`/`goto` 走读了 2 个曾经命
中过这个 bug 的房间
（`kungfu/class/shaolin/hsyuan2.lpc`、`u/michael/workroom.lpc`）均
正常，`quit` 干净退出（退出时自动丢弃了几件不值钱的随身物品，是
这份档案 quit 流程本身的既有行为，与本次改动无关）。登录存档的时
间戳增量已用 `git checkout HEAD --` 撤销，未落入提交。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。第一行选 `GB`（国标/BIG5 编码
闸），然后 `fluffos`/`Mud@2026`。MOTD 有「请按任意键继续」。

### 实测过程

落地巫师休息室。`goto /d/city/zuixianlou`，`list` 为铜钱尺度（烤鸡
腿八十文铜板）。`clone /clone/money/gold` 后 `buy jitui` 成功。本
血统 `feature/dealer.lpc` 的丐帮「穷叫化」检查已被注释掉，拜师后
也能买。`goto /d/gaibang/inhole`，`apprentice zuo` 一次成功，
`score` 「丐帮第二十代弟子」、师傅左全。`save`/`quit` 会丢掉非
autoload 随身物（鸡腿、袍子），人物档本身保存。

巫师重连只有「距上次退出仅 N 秒」警告，无硬冷却。再选 `GB` 重连：
门派仍在，找零银子还在。驱动 `log/debug.log` 无运行时错误（本档
`error_handler` 把 trace 交回驱动 debug.log）。无新编程 bug。
