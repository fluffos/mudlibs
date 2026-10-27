
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

## 明教留言板的位置（2026-10-19，KB 06 §7.269）

`clone/board/mingjiao_b.lpc` 的 `location` 写着不存在的 `/d/mj/zongtan`，明教广场 `d/mingjiao/square.lpc` 载入留言板时报错，整个房间载入不了；改成 `/d/mingjiao/square`（xkx100 的写法）。与 HEAD 对比载入，广场现在可以载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/hangzhou/npc/{tangzi,guanjia,jiading,wolfdog}.lpc`：整个文件只是 UTF-16 的空格（`\x00 \x00 …`，作者把这个物件清空了），驱动报 `Illegal embedded NUL byte (0x00) in source`；旧驱动编出一个空程序。改成一个换行，行为和原来一样（空程序），不从 xkx100 抄回同名 NPC。

逐个载入与 HEAD 对比，没有退步。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `valid_read()` 不信任 sefun 对象的 euid `"NONAME"`（2026-10-20，KB 06 §7.304）

第一次登录时 `Too deep recursion.`（`program: /adm/obj/simul_efun.lpc ... file: /adm/simul_efun/wizard.lpc:4`）：`valid_write()` 信任 `"NONAME"`，`valid_read()` 不信任，sefun 对象的读被拒绝，拒绝记录又经 `wizhood()` / `log_file()` 读取，如此递归。`securityd.lpc` 的 `valid_read()` 补上 `euid == "NONAME"` 的判断。

## 华山论剑排行榜：第一场比武就读不到 `/data/ladder.txt`（2026-10-20，KB 06 §7.326）

比武裁判在一场比武结束时先 `list = explode(read_file("/data/ladder.txt"), "\n")`，读完再 `rm` 并 `write_file` 写回；`/data/ladder.txt` 是比武本身写出来的，全新的树里没有，第一场比武结束就是 `Bad argument 1 to explode()`，排行榜永远建不起来。把写回之前的那一次读改成 `read_file(...) || ""`（空表走原来的 `lost == -1 && win == -1` 分支，把第一对名字写进去）；写回之后的第二次读文件已经存在，没有动。加载检查各 1/1。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/blockade.lpc`、`/cmds/adm/recover.lpc`。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/hufa/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## `wrt`、`wrt1`：不带参数（2026-10-21，KB 06 §7.336）

巫师指令 `wrt`、`wrt1`（`cmds/wiz`）整条指令就是 `write_file(arg, <欢迎词>)`，不带参数时报 `Bad argument 1 to write_file() Expected: string Got: 0.`。加了 `if (!arg) return notify_fail(...)`（`write_file`、`rm`、`mkdir`、`cp` 等文件 efun 对 0 都会抛错，已用 `lpcc_eval.py` 逐个测过，扫描现在也认它们）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 3 条注册（2 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_pass` 1 处、`do_resign` 1 处、`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（chat_msg_combat 2, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/ximenroad.lpc`:`look_gaoshi`、`/kungfu/class/tangmen/tang_fang.lpc`:`perform_action`、`/kungfu/class/tangmen/tang_fang.lpc`:`exert_function`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 12 个文件里有 17 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`/log/nosave/FENG` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 5 行只含这个指针的行（`"gaoshi": (: look_gaoshi :),` `(: perform_action, "sword.lian" :),` `(: perform_action, "sword.wumei" :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 45 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 45 处（31 个文件）：拼名字的赋值 23 处、与汉字常量比较 22 处。例：`name[0..1]` → `name[0..0]`（`/d/tianlongsi/npc/kurong.lpc:371`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/miejue.lpc:110`）；`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:1999`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.lpc:544`）；`if ((strlen(name) < 4) || (strlen(name) > 16)) {`（`/adm/npc/luban.lpc:1243`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 3 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 1 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## tianluo-diwang 知识武功引号剥离（2026-10-27，KB 04 §6.25 Also）

`kungfu/skill/tianluo-diwang.lpc`（Kayin 古墓知识武功短桩）丢了 `inherit SKILL` 后的 `;` 以及几乎所有引号（`return knowledge`、`query(dex)`、汉字通知里字间插空格）。按原意重写成可加载的 knowledge skill（未并入带招式的战斗版手足）。证明：HEAD 加载失败；改后加载成功。
