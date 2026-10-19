
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行一百，厦门热线一百分支，MudOS V22pre11——和 110 号 xkx100 标题相同（都叫"侠客行一百"），但内容是真正不同的、更小的一份快照（6456 对 14255 个 .lpc 档案，目录结构也不一样，有 ftp/mudos.etc/www 这些 xkx100 没有的目录），尽管显示名字容易混淆，但不是重复压缩包，没有标记 duplicate_of。WASM 修复了和 xkx2000zxb/xkxyb 自己的表亲档案上已经见过的相同 §7.52 类从零手写 HTTP 服务器 bug：adm/daemons/httpd.lpc（经典的 Truilkan/Jacques Interstice httpd.c，这里的档头注释明确标注是由 xiaobao/ken@XAJH 移植到 XAJH mudlib 底座）直接呼叫 socket_create()/socket_bind()/socket_close()，没有任何存在性判断，导致整个档案在 WASM 下编译失败；已确认零外部呼叫者，按 §7.52 的默认做法，把每一个碰 socket 的函式（setup()、write_data_retry()、store_client_info()、listen_callback()、close_connection() 和 remove() 里的 socket_close 呼叫）都掏空。没有发现 is_chinese()/check_legal_name() bug——"小浮侠"（三个字）第一次尝试就通过了，不需要修，这和本轮好几份手足档案不同。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST；wiz_levels 顶层是 (admin)）。注册流程在一次连续的 WASM 客户端会话里完整验证过：按任意键横幅→英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 6456 个档案运行（写入 6420 个，19 个报错，17 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 3 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 54 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:177`、`d/city/npc/jinyong.lpc:197`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。
- **一次性 `Too deep recursion.`（`adm/simul_efun/wizard.lpc:4`，
  `wizhood()`），确认是冷启动伪影，不是真实 bug**：首次注册流程走
  到显示"目前权限"那一刻（第一次实际呼叫 `wizhood()`/编译
  `securityd.lpc` 相关调用链）触发了一次 `Too deep recursion.`（此
  档案 `maximum call depth` 设成 30，比驱动默认的 150 低很多——但
  这个值在同一血统的 `xkx100`/`xkxlb`/`xkx2017`/`xjcq2000` 等档案
  上都一样是 30，那几份都没有触发同样的错误，说明不是这个配置值本
  身普遍导致崩溃，而是这份档案自己某个调用链首次编译时恰好够深，
  和已确认的 §7.90/§10.8"冷启动 eval-cost 耗尽"是同一类现象，只
  是这次撞上的是调用深度而不是求值时间）。已用第二次全新连线复测：
  同样走到"目前权限"这一步，`debug.log` 完全干净，零 `Too deep
  recursion`——确认非持续性，按既定纪律不修改（自愈，不是真实
  bug）。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程创建（含开头"输入任意键继续..."这一步），
落地"巫师休息室"（这份档案的管理员默认出生点），`score`
显示"【天神】"头衔，食物/饮水满格。随后**单独一步**做了真实断线重
连+密码验证：用刚设的密码重新连线成功登录，`debug.log` 全程干净。
驱动按精确 PID 结束；管理员存档已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,225 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
用 `fix_710_room.py` 扫过 `work/`，删除 2,224 处标准形状；
`clone/misc/roommaker.lpc` 剩下 1 处字符串拼接变体
`str += "...replace_program(ROOM);..."`，手工改成
`str += "\n\tsetup();\n}\n";`（同一工具的 heredoc 模板已被脚本正常
扫到）。修复后 `work/` 下 0 处存活残留，44 处转档之前已注释掉的
`//` 行原样保留，`work/data/` 下没有真实 `.lpc` 源码命中。`git diff
--stat` 显示 2224 个文件净删 2225 行，与脚本自报数字 + 1 处手工编
辑吻合。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行）。这次没有走完整的实机登录走读
——本档案的登录横幅带一个每秒刷新的存活运行时长计数器（"侠客行一
百已经执行了 N 秒/分"），"press any key"过场画面之后又紧跟一个需
要"等静默"式识别的英文名字提示，多次脚本化尝试（不同的读取策略）
都在"fluffos"这个已知有效账号名上被驱动拒绝为"只能用英文字母"，
怀疑是这份档案自己的横幅注释里提到的"用 telnet/Ptelnet 因为密码
输入等待时间太长而无法成功登录，需要用 Zmud"那类客户端时序敏感问
题，而不是这次改动引入的回归——按 AGENTS.md 既定的"某些档案有不
寻常登录协议，退回到仅编译验证"policy 处理，未继续深挖。`debug.log`
在整个驱动运行期间（含上述失败的登录尝试）没有任何
"cannot replace"/"cannot bind"行。驱动按精确 PID 结束。

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

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了注册 + 重连（含「输入任意键继续」），
没测商店和拜师。本轮用既有 `fluffos`/`Mud@2026`（中文名「浮浮」）。

- **登录**：先空行过欢迎页，再 id/密码。落地巫师休息室。本轮第一
  次进世界再次打出 `Too deep recursion.`（`wizard.lpc:4`
  `wizhood()`）——和 08-13 记下的冷启动伪影同一处；同一次 boot 的
  第二次重连没有再出现。
- **商店**：`goto /d/city/zuixianlou`，`list` 列出烤鸡腿 80 文铜板
  / 牛皮酒袋一两白银 / 包子 50 文铜板。无现金时 `buy jitui` 正确
  拒绝「穷光蛋，一边呆着去！」。`clone /clone/money/gold` 后再买
  成功。`feature/dealer.lpc` 里丐帮「穷叫化」判断已被注释掉，先买
  后拜不是硬性要求。
- **拜师**：`goto /d/gaibang/inhole`，`apprentice zuo`（左全）一次
  完成 →「恭喜您成为丐帮的第二十代弟子」。`score`「丐帮第二十代
  弟子」、「你的师父是左全」。
- **持久化**：立刻重连（巫师只提示「距上次退出仅 13 tick」），称
  谓/师傅/99 两白银 + 20 文铜板均在；烤鸡腿未随存档回来。
- **日志**：live `debug.log` 是 `libs/xkxyb/log/debug.log`（Boot
  Time Thu Sep 3 22:25:55 2026）。除上述已记录的一次性
  `Too deep recursion` 外无新 `error:`。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 84 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 84 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xkxyb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 440 个 `.lpc` 和 11 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：397 -> 397 通过，无回退；改过的头文件的 134 个包含者 129 -> 129 通过。启动时警告 16 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 25 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 17 个文件，HEAD 与工作树各载入一次无回退（17 objects; HEAD PASS 17, tree PASS 17; regress 0; newly loading 0），这些文件的警告 25 -> 0。

## 深度功能测试（§10.7，2026-10-12）：黑木崖老者

- `d/heimuya/npc/laozhe.lpc` `init()`：残留调试行 `sprintf("%s \n", what);`，`what` 是对象，本驱动 `sprintf` 的 `%s` 遇对象报错，进房间时 `init()` 每次中断、招呼从不执行；删去（与 fys 同）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 26 处多余继承（另有 139 处列为“需人工”，都在不能编译的文件里或靠作用域名调用，未动）；照 xzyx（b2d1074232f）：`include/daemons.h` 重定义 `globals.h` 已有的六个守护进程路径（值不同，包含它的文件一直用它的值），每个先 `#undef`，`d/death/god1.lpc` 写明用驱动原先选的 `clean_up()`；`kungfu/skill/huashan-jian.lpc` 多余的 `;` 删去。能编译的文件警告清零；改动的 30 个对象在 HEAD 与工作树各载入一次：HEAD PASS 22，tree PASS 22，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。10 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 4 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`lm-shaoshang`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-fu/hongtianza`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`liancheng-jian/ci`、`liancheng-jian/erguang`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 圣火令法「吸焰令」从未编译通过（2026-10-15）

`shenghuo-lingfa/xiyanling` 原档 `else if (!objectp(weapon = target->query_temp("weapon"))` 少一个右括号，文件编译失败，这一招从来用不了；后面的兵器判断 `skill_type != "tieling" || skill_type != "shenghuo-ling"` 恒为真，就算编译通过也只会说“你使用的武器不对”。补上括号，兵器判断照同目录的 `duo` 改为 `skill_type != "lingfa"`（本库的铁令、圣火令都是 lingfa 类兵器，`shenghuo-lingfa` 也只能 enable 为 lingfa）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`taiji-shengong`、`xiantian-gong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`tanzhi_shentong`→`tanzhi-shentong`（`tanzhi-shentong/hui`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。5 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事要离开时报错，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

131 个文件、157 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/shaolin/obj/sl-cloth`、`/d/shaolin/obj/sl-jiasha`、`/d/obj/greenrobe`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 129 个（129 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 9 个对象设了本库没有文件的武功（8 个名字，最多的是 `shenlong-quanfa`、`xiake-force`、`xiake-strike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：9 个里 6 个通过，其余 3 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!；`quest/leftkiller`：*No program in object '/quest/leftkiller'!……）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 9 处、8 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`yan-fly`→`yanfly`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::setup()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。
