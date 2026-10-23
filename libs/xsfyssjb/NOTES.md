
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ（Sumxin fengyun），一款以古龙小说为题材的 MUD（sumxin.com/bbs、fy.sumxin.com）。和 wqfy（本轮另一个风云系手足档案）血统/bug 模式相同，但是不同的代码库。WASM 修复了经典的 §8.1 GBK 字节区间 is_chinese() bug：adm/simul_efun/chinese.lpc 的 is_chinese() 要求偶数字节对长度，还检查 str[0] 的原始字节区间（161-254），会拒绝合法的奇数字符数 UTF8 中文名字；adm/daemons/logind.lpc 自己的 check_legal_name() 有对应的 i%2 奇偶门槛，以及按字节数算的长度界限（2-10，本意是按用户提示"一到五个中文字"应为 1-5 个字符）。已把 is_chinese() 改成逐码点 0x4e00-0x9fff 区间检查，check_legal_name() 改成逐字符检查，长度界限修正为 1-5。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（存在两个 securityd.lpc 候选档案——adm/securityd.lpc 和 adm/daemons/securityd.lpc——已通过 SECURITY_D 宏确认 /adm/daemons/securityd 才是真正生效的那份，符合 §7.56 记载的双档案歧义模式；WIZLIST 真的会在开机时被读取）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→英文 id→y/n 确认创建→中文名字→密码+确认→性别（m/f）→民族选择（0-3）→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。测试笔记：性别/民族选择正好接在 std/char.lpc 首次编译的大量负荷之后，引发了和 xhcii/xkyxciii 上记载过的同一类测试工具时序竞争——用 --idle 4 补发额外的 'm'/'0' 能可靠绕过；这是客户端时序上的假象，不是 mudlib 本身的缺陷。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 8238 个档案运行（写入 6459 个，1775 个报错——几乎全部是安全的 TOKEN MISMATCH 安全闸门跳过，针对无法幂等往返的杂乱历史代码，跳过比例明显偏高但无害，因为被跳过的档案完全没有被改动——4 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,188 处存活匹配，全部标准独立行形式，脚本一次
  性删除，无不规则残留。本库没有房间生成类工具（`roommaker`/
  `makeroom` 均未找到），不涉及工厂模板修复。`data/` 下额外核查过，无
  命中。验证：真实 debug 驱动干净编译启动、端口正常监听，`debug.log`
  无新增 "cannot replace"/错误行。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（round two，2026-08-27）

第一次完整的 §10.7 连续游玩测试（此前该库从未做过完整 round-two
playthrough）。用真实原生 driver（端口 40149）走完了：注册（中文名
"沈牧"，id `shenmu`）→ look/score/i/hp → 移动 → 商店购买 → 帮派拜师
两条路径 → study/learn 技能路径 → fight（安全切磋）/kill（真实战
斗）→ 留言板只读测试 → 两轮断线重连 → 管理员账号验证 → 系统性 grep
排查了任务里列出的全部标准 cross-cutting bug 类别。

**发现并修复了 3 个真实 bug：**

1. **`adm/obj/master.lpc::log_error()` 把编译 WARNING 当错误播给玩家
   看（AGENTS.md §7.103 的确认实例）。** 注册后走 `look`/`score`/`i`
   立刻触发多条 `编译时段错误：...warning: Unused local variable 'x'`
   字样的原始编译警告文本，直接打印在普通玩家屏幕上（`cmds/std/
   look.lpc`/`cmds/usr/inventory.lpc`/`std/char/master.lpc` 首次编译
   触发）。修法：`if (this_player(1)) efun::write(...)` 改成
   `if (this_player(1) && strsrch(message, "warning:") == -1)
   efun::write(...)`。重启驱动后用同样的 register→look→score→i 流程
   复测，干净无警告输出。

2. **`adm/simul_efun/file.lpc::log_file()` 缺少 `assure_file()` 目录
   保护，导致管理员 `call` 指令对玩家目标彻底失效（AGENTS.md §7.11
   的确认实例，和 `xyj2006n`/`xyj2006zzzhx` 同一形状同一文件）。**
   现场复现：用管理员账号 `call shenmu->add_money("coin", 5000)` 给
   测试角色注资时，`call.lpc` 自己在真正调用目标函数之前先往
   `/log/nosave/CALL_PLAYER` 写审计日志——但 `/log/nosave/` 目录从未
   存在于本库归档里，`write_file()` 静默失败并抛出未捕获的执行时段
   错误（"Wrong permissions...No such file or directory"），导致后面
   的 `call_other()` 根本没有执行——确认了目标角色的物品栏完全没有
   变化。这意味着管理员最常用的调试指令 `call` 对任何玩家目标从来
   没有真正生效过。修法：在 `log_file()` 里实际调用文件里已经写好但
   从未被使用的 `assure_file(LOG_DIR + file)`（因为它在同文件里定义
   在 `log_file()` 之后，加了一行前向声明）。重启后复测：同样的
   `call` 指令干净执行，目标角色物品栏真的发生了变化，
   `/log/nosave/CALL_PLAYER` 按需自动创建。

3. **`adm/daemons/logind.lpc::reconnect()` 断线重连时泄漏旧的
   `link_ob`（新增 AGENTS.md §7.155，和 §7.150 的检查目的相同但是不
   同的具体形状）。** 按任务要求做了两轮"断线（非 quit）→ 等待→重
   连"循环，发现 `reconnect()` 把 `user` 的 `link_ob` 临时变量直接
   覆盖成本次新连线对象，却从未 `destruct()` 掉上一次会话遗留的旧
   `link_ob`——而同一文件里几行之外的"踢掉重复登录"分支
   (`confirm_relogin()`) 是正确处理这个场景的。旧 `/obj/login` 对象
   因为自己的 `time_out()` 自清理逻辑在 `body_ob` 被设置后会主动放
   弃（`if (objectp(query_temp("body_ob"))) return;`），所以永远不会
   自行销毁，每一次非 quit 的断线重连都会永久泄漏一个对象。本库这份
   `/obj/login` 没有 heart_beat，所以不会像经典 §7.150 那样反复用陈
   旧数据覆盖存档，但仍然是一个真实、会无限累积的对象泄漏。修法：在
   `reconnect()` 里补上和 `confirm_relogin()` 一样的
   `old_link = user->query_temp("link_ob"); if (old_link && old_link
   != ob) destruct(old_link);`。重启后复测两轮"断线→等待→重连"循环，
   `debug.log` 干净无错误，且 `find_player()`/管理员 `call`/`tell`
   在两轮重连之后依然能正确找到角色（本库的 `set_living_name()` 注
   册挂在常驻的角色对象本身而不是登录壳对象上，所以 §7.152 描述的
   "重连后 find_player 失效" 这条具体症状在本库并不成立——但泄漏对象
   本身仍然是一个需要修的真实 bug）。

**测试过但确认干净、未改动的部分：**

- `fight`（安全切磋）指令：对满血友好型 NPC（店小二）测试，正确按
  `accept_fight()` 逻辑婉拒——设计如此，不是 bug。
- `kill`（真实战斗）指令：对丐帮"一袋弟子"老乞丐（combat_exp 100）
  测试，双方多回合互有攻防、无一方造成伤害（数值层面，不是 bug），
  中途用移动指令安全撤离，`debug.log` 全程无错误。
- 帮派拜师：测试了两条路径——`apprentice old beggar`（丐帮普通乞丐，
  没有覆写 `attempt_apprentice()`，调用未定义函数在本驱动上静默返回
  0，师父不会主动收徒；这是"只有真正的帮主才能收徒"设计的自然结
  果，不是 bug）和 `apprentice tianji`（风云天下的天机老人，明确注
  释"收徒极挑剔"，`attempt_apprentice()` 只出一道机锋考题、没有任何
  代码路径真正完成收徒——和它自己的角色设定"极其挑剔"完全吻合，判定
  为有意的设计，不是 bug，未改动）。
- `study`/`learn` 技能路径：从警世书局读千里处购买《轻功简介》
  (movebook) 成功（`buy movebook from duqianli`，正确扣款找零）；
  `study movebook <神数量>` 因为角色 `literate` 技能为 0 被拒绝
  （"你看不懂耶"），`learn <技能> from <NPC> with <潜能点>` 对没有
  覆写 `recognize_apprentice()` 的普通人类 NPC（读千里）同样被拒绝
  ——这些都是 `cmds/std/study.lpc`/`cmds/std/learn.lpc` 自身文档化的
  前提条件在正确生效，不是 bug。
- 留言板（风云天下"盘龙摩天柱(Stone)"）：255 条真实历史留言，
  `read 1` 读出一条 2001 年前后的真实存档内容（茶茶/teatea 的
  emote 收集通告）；`read next`/`read new` 依次正确前进到 #2、#3，
  没有 §7.153 的分页 bug。严格只读，未使用任何 discard/delete 类指
  令。
- `quit` 会无差别丢弃玩家身上所有非 autoload 物品（金钱、书籍、衣
  服）——这正是 `newbie.txt` 自己第 5 条明确警告过的设计（"暂时离开
  风云之前应先当铺/银行寄存"），不是 bug。
- 断线重连：`find_player()`/管理员 `call`/`tell` 两轮重连后均正常，
  唯一发现的问题已在上面第 3 条修复。
- 管理员账号：`adm/etc/wizlist` 里列有 `fluffos (admin)`，但存档目
  录里此前从未真正存在过 `fluffos` 的注册档案（`data/{login,user}/
  f/fluffos/` 不存在）——本轮通过真实注册流程补种（id `fluffos`，
  密码 `Mud@2026`），登录时立即显示"目前权限：(admin)"，
  `wizlist` 指令输出确认在场。这不是代码 bug（wizlist 权限判定本身
  是正确的、按 id 动态查表），只是此前的"已验证"记录缺少实际存档
  佐证；现已实际播种并提交。
- 系统性检查了任务列出的全部标准 cross-cutting bug 类别（§4.3 静态
  转 nosave、§4.4 BIG5 0x5C、§7.80/§7.118 文件名切片、§7.121 浮点/整
  数、§7.122 autoload 重复、§7.123 裸文件作用域 mapping/array 赋值、
  §7.124 百分比阈值、§7.126 stale .c 扩展名、§7.129 tell_room 传
  0、§7.130 query_idle 无条件调用、§7.131 find_living 注册、§7.132
  map() 绑定、§7.133 net_dead apply、§7.134 无初始化累加器、§7.136
  verb soul 剥离、§7.139 catch_tell 配置、§7.141 replace_program 折
  叠、§7.142 虚拟对象引擎、§7.143 force_me 不匹配、§7.144 一次性
  set_name、§7.145 verb 遮蔽、§7.146 单斜杠注释、§7.147 factory 空
  指针、§7.148 保留字参数名、§7.149 首位管理员自动提升）——均未发现
  新的命中；`feature/vendor.lpc`/`adm/simul_efun/message.lpc` 里的
  `tell_room`/`message()` 转发已经是正确的 `exclude || ({})` 写法，
  没有 §7.129 的问题。

**测试角色**：`shenmu`（沈牧）在提交前已清理（`data/{login,user}/s/
shenmu/` 已删除）。保留的唯一存档账号是管理员种子账号
`data/{login,user}/f/fluffos/`（id `fluffos`，密码 `Mud@2026`，
`(admin)` 权限）。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— compile-warning pass and wrong-case paths (ported from fengyun434)

`scripts/lpc_warnings.py xsfyssjb` (9247 files): 2578 distinct diagnostics and 83 files that did not compile at the start, 127 diagnostics and 72 files at the end
(8228 compile). 981 files changed. The code is the fengyun434 root's, so the pass is its pass (libs/fengyun434/NOTES.md has the classes, among them the 87 prototypes
for functions called before their definition): `lpc_twin_port.py adopt fengyun434 xsfyssjb` carried the fixes of the files whose code is the root's (711 reformatted,
252 verbatim), then `lpc_warnings.py --fix` and the tools of `scripts/lpc_family_pass.py`. `adm/simul_efun/file.lpc` defines `tail()` in LPC like the root's.
The only file that failed here and not in the root was `cmds/wiz/tail.lpc` (no `tail()` yet).

**Wrong-case paths (KB 03 §4.5).** `scripts/lpc_case_paths.py --apply xsfyssjb`: 62 `.C` files renamed to `.lpc`, none of the references needed a rewrite; load check of the
98 affected objects, HEAD against the working tree: 29 PASS -> 98 PASS, 69 more load, none fewer. What is left is the root's list (`ed.c`-style leftovers, the TMI-2 network daemons
without headers, drafts).

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1509 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`adm/daemons/tasknpcd1.lpc`、`d/biancheng/taskd.lpc`、`d/for_martea/for_suu/tasknpcd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 8 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：4 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`adm/daemons/tasknpcd1.lpc`、`d/biancheng/taskd.lpc`、`d/for_martea/for_suu/tasknpcd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 6 个），无回退；`adm/daemons/tasknpcd1.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 2 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/tieflag/npc/drinkmonk.lpc` `go_in()`：`for (int i = 0; i < sizeof(enemy); i)` 没有自增，第一个敌人不在同一房间时死循环（直到 eval cost 报错）；改为 `i++`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 编译警告收尾（2026-10-12）

孪生库 fengyun434 同日的整理（238c181110e：`kill_ob`/`die`/`check_status` 在 `void` 基类上写成 `int` 的改为 `void`，`snake-spear.lpc` 的 `action` 改名 `spear_action`，`qiankun.lpc` 的 `enemy` 改名 `foes`，`newsman.lpc` 补 `ask_question()` 原型）用 `scripts/lpc_twin_port.py adopt fengyun434 xsfyssjb --pre 238c181110e~1` 搬来：14 个文件与 fengyun434 修前逐 token 相同，清单里的警告全部落在这些文件里。HEAD 与工作树各载入一次：14 个对象，HEAD PASS 14，tree PASS 14，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。5 个文件 10 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：连击之术 `dual-attack` 的 `valid_learn()`（风云的 `query_skill()` 去载入 `/daemon/skill/combat_exp`，报错）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

9 个文件、17 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/questnpc/obj/yueshenblade`、`/questnpc/obj/yueshencloth`、`/d/fy/obj/whitecloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 10 个（10 个原来载入不了），没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（1 个名字，最多的是 `qingfengsword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 1 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/for_martea/neon_playground/grassland` 的 `south`：`shanpo` → `kezhan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 31 处、13 个文件：`dabei-trike`→`dabei-strike`（12 处）、`qingping-sword`→`qingpingsword`（10 处）、`fumotaff`→`fumostaff`（4 处）、`draginstrike`→`dragonstrike`（2 处）、`cloud-staff`→`cloudstaff`（2 处）、`qingfengsword`→`qingfeng-sword`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `ROOM_D`、`BACKUP_DIR`、`MONEY_D`，用到它们的物件（名单里 3 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## sanniang 的 query(environment(...))->query（2026-10-19，KB 06 §7.266）

`d/biancheng/npc/sanniang.lpc`（边城的三娘）里写成了 `query(environment(this_object()))->query("discussion_shen")`，多了外面一层 `query(`，驱动报 `Bad type for argument 1 of query ( string vs object )`，整个 NPC 载入不了；同一个文件另一处正确写成 `environment(ob)->query("discussion_shen")`。去掉多余的 `query(`。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/taoyuan/npc/kid.lpc`、`/daemon/condition/idiot.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

4 个文件、4 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/bat/npc/dizi.lpc`、`/d/cave2/npc/dizi.lpc`、`/d/eren2/npc/dizi.lpc`、`/d/eren2/npc/dizi_a.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/d/eren2/npc/fighter1.lpc`、`/d/eren2/npc/fightnpc.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现；战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/adm/daemons/combatd-4-17.lpc`（1 处）、`/adm/daemons/combatd-4-20.lpc`（1 处）、`/daemon/skill/xuemo-blade.lpc`（1 处）、`/std/char/quest_npc.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d2/shanxi/obj/jiuwan.lpc`（1 处）、`/gift/jiuwan.lpc`（1 处）。另有 `/d/jinan/npc/1mj.lpc`（3 处）、`/d/jinan/npc/jiaoqi.lpc`（2 处）、`/d/jinan/npc/mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/d/for_martea/neon_playground/migong/adm/daemons/vrm_server.lpc`（1 处）、`/std/room/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 24 处）。改动：`/d/damage1.lpc`（2 处）、`/d/eren2/npc/obj/key.lpc`（1 处）、`/d/for_martea/maze/wood-room.lpc`（1 处）、`/d/huangshan/jiusi.lpc`（2 处）、`/d/jinan/mjroom.lpc`（1 处）、`/d/jinan/mjroomBUG.lpc`（1 处）、`/d/resort/teagarden.lpc`（2 处）、`/d/shanliu/npc/xiucai.lpc`（1 处）、`/d/taiping/npc/obj/key.lpc`（1 处）、`/d/yinghe/irongate.lpc`（1 处）、`/d/yinghe/irongate2.lpc`（1 处）、`/d/zangbei/cave.lpc`（2 处） 等 16 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 任务守护进程启动时崩溃（2026-10-20，KB 06 §7.303）

`quest/dynamic_npc_quest` 列了 12 个 `/questnpc/` 下的 NPC，压缩包没有这个目录，`tasknpcd::create()` 里 `load_object()` 回 0，`item->query("name")` 报 `Bad argument 1 to EFUN call_other()`，`auto_reset_quest()` 永远没有启动。现在跳过加载不了的行，一行也没有时直接返回（`adm/daemons/tasknpcd.lpc`）。

## `TASKNPC_D` 的路径少了一个 s：`/adm/daemon/tasknpcd`（2026-10-20，KB 06 §7.325）

`include/globals.h` 里 `#define TASKNPC_D "/adm/daemon/tasknpcd"`，守护进程文件是 `/adm/daemons/tasknpcd.lpc`：裸指令 `enroll` 在扫描里打印了 24 次 `call_other() couldn't find object '/adm/daemon/tasknpcd'`（任务 NPC 每次心跳问这个守护进程都是同样的错误）。同一棵树里 `d/for_suu/globals.h` 的写法是对的。改成 `/adm/daemons/tasknpcd`（fengyun434、fysjmb、xsfyssjb 三个飞扬系库同一处）。实测：`enroll` 显示用法，控制台无报错。`QUESTNPC_D`（`/adm/daemons/questnpcd`，`questnpc` 指令用）指向一个所有库都没带的守护进程，属于内容缺失，没动。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 93 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/biancheng/npc/bandit1.lpc`、`/d/biancheng/npc/tuozi.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/for_martea/for_suu/tasknpc.lpc`、`/std/char/quest_npc.lpc`、`/std/char/tasknpc.lpc`（共 3 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 41 个存档共 41 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/amine1027580822.o`（1 处）、`/p/residence/amine1027587616.o`（1 处）、`/p/residence/amine1027594915.o`（1 处）、`/p/residence/baby1032108114.o`（1 处）（等共 41 个存档）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 12 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/baiyun/beach1.lpc`（`do_dive`）、`/d/biancheng/npc/oldman.lpc`（`do_vendor_list`）、`/d/fugui/npc/dashuai.lpc`（`do_accept`）、`/d/fugui/npc/robleader.lpc`（`do_accept`）、`/d/huashan/npc/obj/bamboo_cont.lpc`（`do_use`）、`/d/shanliu/npc/taoist1.lpc`（`do_answer`）、`/d/shanliu/npc/yang.lpc`（`do_answer`）、`/d/shaolin/fangnan.lpc`（`do_look`）、`/d/songshan/damocave.lpc`（`do_look`）、`/d/wanmei/woodhouse.lpc`（`do_fillwater`） 等共 12 个文件。最多的函数名：`do_accept` 2 处、`do_answer` 2 处、`do_look` 2 处、`do_dive` 1 处、`do_vendor_list` 1 处。没有动（读过）：`/d/huashan/npc/snake.lpc` 的 `do_train`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/fy/npc/gangster2.lpc`:`goaway`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`(: goaway :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 2 处（2 个文件）：拼名字的赋值 1 处、与汉字常量比较 1 处。例：`name[0..1]` → `name[0..0]`（`/d/qianfo/npc/master2.lpc:96`）；`things[0..13] == "天南地北双飞客"` → `things[0..6] == "天南地北双飞客"`（`/d/tieflag/magroom.lpc:41`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 10 ) )`（`/adm/daemons/logind.zh.lpc:735`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/fy/npc/caifeng.lpc:213`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 12 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
