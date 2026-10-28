
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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/arch/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py yxxcii --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 436 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：414 -> 414 通过，无回退；改过的头文件的 177 个包含者 177 -> 177 通过。

启动时警告 29 -> 0；新进程登录（编码选择、英文名、新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 2 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：同一次重扫的其余 30 条：`include/daemons.h` 6 个守护进程宏与先前的定义不同，`#undef` 后再定义（后者本来就生效）；`d/guanwai/npc/chuanfu1.lpc` 和 7 个文件在基类已有的情况下又 `inherit F_SKILL`/`F_CLEAN_UP`，删去（`skills`/`learned` 重复声明随之消失）。改动及受影响的 32 个对象新进程各载入一次，无回退。

- 2026-10-14：4 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`changeing()`、`compelete_fish()`、`shaqi()`。新进程比对 HEAD 与工作树：4 个对象，新增载入 4，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14（补）：上面改成有返回值的函数里残留的空 `return;` 改为 `return 0;`（值不变，消除 `Non-void functions must return a value`）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-fu/hongtianza`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`liancheng-jian/ci`、`liancheng-jian/erguang`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`taiji-shengong`、`xiantian-gong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`jiuyin-baiguzhua`→`jiuyin-baiguzhao`（`jiuyin-baiguzhao`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`tanzhi_shentong`→`tanzhi-shentong`（`tanzhi-shentong/hui`）。

## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。5 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

1 个文件、2 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/weapon/longsword`、`/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（5 个名字，最多的是 `shenlong-quanfa`、`meiren-sanshi`、`pixie-sword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 7 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/spear`（宏 `SPEAR`）←haiyang2，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 9 处、8 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`yan-fly`→`yanfly`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`cmds/arch/ghost`。（`scripts/lpc_transplant_function.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/city2/domitory.lpc` 的 `west` 出口：`Sino-CO` → `sino-co`
- `/d/city2/lab.lpc` 的 `east` 出口：`Sino-CO` → `sino-co`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/cmds/wiz/rm.lpc`：`#include "/doc/help.h"`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，0 个原来编译不过、现在载入，没有退步。

## 诗社的诗文（2026-10-19，KB 06 §7.276 同批检查）

`d/city4/clubpoem.lpc` 的 `create()` 读 `__DIR__ "poem/poem1"`…`poem319`，档案里没有 `d/city4/poem/` 这个目录：`read_file()` 答 0，`sscanf(buf, ...)` 报 `Bad argument 1 to sscanf`，房间载入不了。319 个文件（唐诗，第一行「作者：题目」）取自同一系的 haiyang2；hy 一族的 fqyy2、xkxyb、hy3、hy5、hy2000、haiyang2 里这个目录逐字节相同。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）、`/kungfu/skill/jiuyang-shengong/roar.lpc`（1 处）。

## `boss` 指令：`/open/shit.txt` 不在存档里，`write(0)` 报错（2026-10-20，KB 06 §7.285）

`boss 1` 先清屏、屏蔽所有消息，再 `msg = read_file("/open/shit.txt"); write(msg);`。`/open/` 是巫师目录，存档里没有这个文件，`read_file()` 返回 0，`write(0)` 报 `Bad argument 1 to receive()`，玩家的屏幕还被屏蔽着。改为 `if (stringp(msg)) write(msg);`（`cmds/usr/boss.lpc`）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/cmds/adm/watch.lpc`（1 处）、`/cmds/std/tt.lpc`（1 处）、`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`、`/feature/more2.lpc`。

## `trade` 指令编译不过：孤零零的 `#define`（2026-10-20，KB 04 §6.25）

`cmds/usr/trade.lpc` 第 8 行是一行没有名字的 `#define`（`#define: missing name`），整个文件加载失败。删掉这一行（它前面有三个完整的 `#define`，后面是 `#include <ansi.h>`）。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 丘处机、觉远的 `accept_object()`：参数和局部变量的名字对不上（2026-10-21，KB 06 §7.348）

yxxcii 的 `qiu.lpc`、`qiu1.lpc`：`accept_object(object me, object ob)` 里判断的是 `obj->query("name")`，`obj` 是没赋值的局部，交上药材一律抛错。ylfyxa3 的 `jueyuan.lpc` 把参数表丢了（`int accept_object()`），函数里读 `obj`（xajh4gkb 的同一份文件是 `accept_object(object me, object ob)`）。把参数名改回来。改动：`/d/quanzhen/npc/qiu.lpc`、`/d/quanzhen/npc/qiu1.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 4 条注册（3 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/taishan/npc/mengzhu.lpc`（`do_recover`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_pass` 1 处、`do_resign` 1 处、`do_recover` 1 处、`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 已补回 `/d/city/wudao1.lpc` 的 `look_gaoshi()`（原型还在、函数体丢了；fqyy2 里同一文件有完整函数，原样补到文件末尾，`scripts/lpc_port_function.py --lfun`；真机会话里 `look gaoshi`：HEAD 报上面的错误，改后正常输出）。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/ximenroad.lpc`:`look_gaoshi`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 21 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 21 处（16 个文件）：拼名字的赋值 13 处、与汉字常量比较 8 处。例：`name[0..1]` → `name[0..0]`（`/d/tianlongsi/npc/kurong.lpc:371`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/miejue.lpc:110`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:141`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 1 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## tianluo-diwang 知识武功引号剥离（2026-10-27，KB 04 §6.25 Also）

`kungfu/skill/tianluo-diwang.lpc`（Kayin 古墓知识武功短桩）丢了 `inherit SKILL` 后的 `;` 以及几乎所有引号（`return knowledge`、`query(dex)`、汉字通知里字间插空格）。按原意重写成可加载的 knowledge skill（未并入带招式的战斗版手足）。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 zhongling tell_object 引号错位）

`d/wanjiegu/npc/zhongling`（及同路径副本）的 `tell_object("who, 钟灵脱下一双绣花鞋。\n")` 把对象参数写进了字符串；改为 `tell_object(who, "…")`。证明：原文错位；改后加载，语料残渣 0。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

