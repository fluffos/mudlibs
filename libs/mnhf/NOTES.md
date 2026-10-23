
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道，命中了一类：
`adm/daemons/logind.lpc` 里两处 `printf("%O\n", ob)` 调试残留（`hc`/
`yxjh`/`xkyx3b` 那种"两条并行取名流程各自一份"的经典形状）。已删
除两处，新增 `mnhf` 到 AGENTS.md §7.34 确认实例列表。其余三类
（private command_hook、未防护 MESSAGE_D->、stat/water 键名、§8.9
坏 age 判断）均未命中。

**完整流程验证**：注册全新角色（沐华附/id `mnhdive`），走完游戏
自带的"军训"新手引导（教官依次介绍生存/经济系统、拜师/读书/任务
系统、最后在"欢迎光临模拟华附"的枢纽房间用数字菜单 1-6 选择去
处）；到"聚清园"向任务 NPC"夜刻名"用 `quest` 指令（不是
`ask...about quest`，指令直接注册在 `add_action("give_quest",
"quest")` 上）领到一个限时寻物任务（"给我八分五秒内找回我要的
『大青菜』"）；以管理员身份 `goto` 到广播里提到的新手练功用"草
坪"场景，对"小鸟"NPC 发起战斗，完整交手十余回合，攻防叙述、命
中/闪避/招架判定均正常；`quit` 干净退出。全程 debug.log 零报错。

顺带确认了这份档案的管理员账号 fluffos 之前只在 `adm/etc/
wizlist` 里列了名，实际存档从未真正创建过（本轮通过正常注册流程
用密码 `Test1234` 创建，符合这份档案自己"必须同时包含大小写字母
和数字"的密码规则），已随本次改动一并提交存档文件。

**未覆盖范围**：拜师、读书系统、工作赚钱（单车楼看车/麦当劳洗盘
子/钓鱼/扫楼梯等）、完整走完已领取的寻物任务，因时间原因未实
测。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

校园题材 mudlib（模拟华附，背景设在华南师范大学附属中学）。WASM 修复：修好了两个 bug。（1）cmds/usr/uptime.lpc 的 write(read_file("/log/nosave/LASTCRASH"))（§7.54 类）——全新安装下这个档案不存在，read_file() 回传 0，write(0) 会崩溃报"Bad argument 1 to receive()"；由于 UPTIME_CMD->main() 在每一次 logon() 里、英文名字提示之前都会执行，这会导致每一次连线尝试都崩溃断线。已用 stringp() 保护修复。（2）adm/daemons/httpd.lpc（§7.52）——socket_create()/socket_bind()/socket_accept()/socket_write()/socket_close() 在这个 WASM 构建下都是未定义的 efun；导致的编译失败（"No program in object"）发生在预载阶段，甚至在上面那个 uptime 崩溃有机会发作之前就先出现了。既然这个精灵存在的唯一目的就是通过 socket 提供 HTTP 服务，已按既定的"整个档案禁用"方针把 setup()/write_data_retry()/store_client_info()/listen_callback()/close_connection()/remove() 整批掏空，而不是逐个呼叫点修补。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断）。通过 adm/etc/wizlist 把 fluffos/Test1234 播种为 (admin)（这份档案的 check_legal_password 要求至少 6 位且同时包含大小写字母和数字，常用的 Mud2026Adm 式密码不满足小写字母要求——改用 Test1234 来匹配这份档案自己的规则）。完整的注册（id→确认→直接输入中文名字→密码→确认→电子邮件→性别→角色类型 0-3）和 look→score→quit 流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 4 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## eval-cost 核实（2026-08-17）——检查过，700000 够用，未改动

同源孪生档案 `moniHuafu`（meta.json 标了 `duplicate_of: mnhf`）在自己
的 §10.7 测试中发现 `maximum evaluation cost : 300000` 太低，冷启动
编译 `std/char.lpc` 本身和死亡区判官 NPC 时会撞上
`Eval interrupted: ... cost limit reached`（AGENTS.md §7.90 同类）。
`mnhf` 自己的 `config.fluffos` 用的是 `700000`——比 `moniHuafu` 高，
但仍然低于本项目"确认已知偏低"名单里的门槛，值得专门核实是不是
也有同样的风险（之前那轮"第二轮"战斗测试很可能只是被同会话内先
前的注册尝试"预热"过，见 AGENTS.md §7.90 第三个实例的先例）。

**核实方法**：(1) `lpcc_check.sh` 全档案重新编译一遍——933/945 通
过，12 个失败和早前记录的完全一致（都是已确认无害的孤立网络精灵/
example 档案/lpcc-sweep-only 的 `valid_override` 假阳性），零处
`cost limit reached`。(2) 单独重开一个全新驱动进程，`fluffos` 账号
**在这个全新进程里的第一次连线**（`std/char.lpc`/`std/char/npc.lpc`
的冷启动编译现场发生，日志里能看到成串的编译警告）直接 `goto
/d/death/yanluo`——房间、判官 NPC（"监考官"、"铁索 数学老师"、"枷
铐 语文老师"、阎王爷）全部正常载入；监考官甚至主动攻击了测试角色，
完整交手数回合直到角色"死亡"，正确移动回 `/d/death/gate`——全程
`debug.log` 零 `cost limit reached`/`Too long evaluation` 记录。

**结论：`mnhf` 的 `700000` 在这份档案里是够用的，不是虚惊后侥幸——
两种独立方法（批量编译扫描 + 全新进程现场战斗/死亡验证）都没有触
发问题。未改动 `config.fluffos`。`moniHuafu` 的问题是它自己配置值
（`300000`）明显更低导致的，不是这份共享代码本身的通病。**

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 61 live
`replace_program(ROOM);` occurrences across 61 room files
(`obj/void.lpc`, `d/huafu/*.lpc`, `d/new/wel1-3.lpc`,
`d/wiz/jobroom.lpc`, and a large `d/death/*.lpc` cluster of 38 rooms) —
same fatal redundant-replace-after-inherit shape as the rest of the
§7.100 family. No room-building tool exists in this lib. Fixed by
deleting the redundant lines. Verified via a clean native driver boot
(zero new `debug.log` errors, port listening, killed by exact PID after
~8s).

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

## 深度功能测试（第二轮补测，2026-08-23）——补齐此前未测的四项

针对第二轮 NOTES 里明确标注"未覆盖范围"的四项，本轮逐一补测，全程
用管理员账号 `fluffos`（Test1234）经 `goto` 直达各场景，真人指令驱动，
非代码走查。

**1. 拜师（这份档案没有传统武侠式的"门派"，但有对等机制）**：这份
校园题材档案确实用 `apprentice <目标>` 指令实现和武侠 mudlib 一样的
师徒/门派系统，只是包装成"班级/学生"而非"帮派"——在西教学楼向
NPC「熔尸红」用 `apprentice rong` 成功拜师，`ob->attempt_apprentice()`
→`recruit_apprentice()`→`re_rank()` 全链路走通，`score` 正确显示
"华师附中第四十六届学生"称号。所以标题说的"拜师"是字面意义上的真
实存在的机制，不是要另外找一个类比。

**2. 读书系统**：图书馆一楼（`d/huafu/libzixi.lpc`）的 `zixi`/`read`
指令验证通过——`improve_skill("literate", ...)` 累计进度，多次
`zixi` 后触发"你的「读书识字」进步了！"，`start_busy()` 冷却门槛
（"你还在自习之后的回味之中"）也生效。

**3. 四种打工赚钱小游戏（`doc/help/hfjobs.txt` 列出的前四种，均已
补测，全部走通）**：
   - 单车楼看单车（`d/huafu/dclou.lpc`+`npc/laobo.lpc`）：`work` 指令
     → 短暂"昏迷"状态几秒后清醒，拿到一块钱、经验，偶尔改善
     unarmed 技能。
   - 麦当劳洗盘子（`d/huafu/mdc.lpc`+`hguitai.lpc`+`chufang.lpc`+
     `npc/fuwu3.lpc`(总管)+`npc/fuwu4.lpc`(服务员)）：`ask guan about
     job`→`ask yuan about panzi`→（东行进厨房）`xi panzi`→（回餐厅）
     `give panzi to guan`，全链路给薪水正确（本次拿了脏盘子数量对应
     的银两）。注意：`mdc.lpc` 按模拟的"营业时间"会周期性
     `kick_all()` 把非用餐的人赶到 `xjjicun`，这是设计好的餐厅打烊
     机制，不是 bug，赶紧办完最后一步交易即可。
   - 锦鲤池钓鱼（`d/huafu/jlchi.lpc`+`npc/laobo.lpc`）：`ask laobo
     about fishing` 借到鱼竿，`diao yu` 成功钓鱼拿到银两/鱼获。
     **顺带发现一个小 typo bug，已修复**：`jlchi.lpc` 的 `init()`
     里 `add_action("do_fishing", "fighing")`——`fighing` 明显是
     `fishing` 的拼写错误（同一行还注册了 `diao`/`钓` 两个可用的
     同义词，唯独这个英文别名打错了字母顺序，导致这个本该可用的
     英文同义词从未真正生效）。改成 `add_action("do_fishing",
     "fishing")`，`update` 重编译后现场验证 `fishing yu` 可以正确
     触发钓鱼。不影响已有的 `diao`/`钓` 路径，纯粹是补上一个死掉的
     别名，不涉及数值/平衡。
   - 钟楼扫楼梯（`d/huafu/zhonglou1.lpc`+`npc/tiguan.lpc`）：
     `ask guan about 扫把` 拿到扫把，`sao di` 成功打扫（扣"精力"、
     加学分/潜能），`give broom to guan` 正确回收扫把并清除
     `clean_floor*` 临时标记。
   - 第 5-7 种（值日/杀小流氓/电脑内部打病毒，`hfjobs.txt` 里编号
     5-7）时间预算内未测，留给以后。

**4. 完整走完一个已领取的寻物任务**：向聚清园 NPC「夜刻名」用
`quest` 领到限时任务（先后拿到"『洗好的盘子』"这个目标——凑巧和
打工小游戏3的产出重叠，用麦当劳洗盘子那条链路现造了一个交上去），
`give <目标物> to ye` 正确判定 `quest["quest"]` 匹配、`task_time`
未过期，发放学分/潜能奖励，`me->set("quest", 0)` 正确清空任务状态。

**已知但未处理的悬空 exit（观察记录，不是本轮修复）**：驱动 stdout
（非 `debug.log`，与 AGENTS.md §10.8 记录的同一现象）里两次刷出
`执行时段错误：*call_other() couldn't find object
'/d/huafu/xxiang'.`，触发点是 `d/huafu/hgate.lpc`（"华附后门"）的
`south` exit 指向 `__DIR__ "xxiang"`，这个文件在整个档案里从未存在
过（`d/huafu/` 目录下没有任何 `xiang` 相关文件，也没有 git 历史）。
两次都是 NPC（`npc/trashcan#43`「金冬瓜」）在 `heart_beat()`→
`do_flee()` 里试图往南逃跑触发的，`cmds/std/go.lpc` 本身已经用了
AGENTS.md §9220 记录过的"先 `call_other(dest,"???")` 探测再
`find_object()` 复查"防御写法，所以这个错误是可恢复的（NPC 逃跑失
败，返回 `notify_fail`，不会崩溃、不会卡死任何指令），只是每次触
发都会在驱动输出里留一条噪声。按 AGENTS.md §7.14 同类"悬空 exit"
先例（`u/lxh/dufang.lpc` 那次的处理方式）：没有同名/改名文件之类
的结构性证据支持"应该指向哪里"，所以照抄先例的做法——只记录，不
瞎猜目标去乱改。

全程 `debug.log`/驱动 stdout 除上述已知的可恢复 `xxiang` 噪声外零
新增报错；`quit` 干净退出，退出前经验正确结算。测试用管理员账号
`fluffos` 自身状态（家族、任务记录、金钱等）本轮做了较多改动并随
存档一并提交——这是这份档案里可复用的标准巫师测试账号，历次深度
测试都会累积游玩痕迹，属预期行为。此前"第二轮"测试注册的一次性角
色 `mnhdive` 存档（未提交过的 untracked 文件）本轮已清理删除。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 83 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py mnhf --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 148 个 `.lpc`。HEAD 与工作树分别加载（新进程）：142 -> 142 通过，无回退。

启动时警告 62 -> 0；新进程登录（新人物确认）正常。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 启动后第一个登录的玩家，在 0、25、50 分碰到 `Too deep recursion`（2026-10-21，KB 06 §7.335）

`adm/daemons/upgraded.lpc`（`logind.lpc` 的 `UPGRADE_D->upgrade(user)` 在启动后第一次登录时才把它载入）的 `create()` 调 `ready_to_start()`：`localtime(time())[1] % 25 == 0`（0、25、50 分）就 `check_all()`，而 `check_all()` 末尾又 `ready_to_start()`，同一分钟里条件仍然成立，一路递归到控制栈满：`Too deep recursion. program: /feature/message.lpc, object: /obj/user#33, file: /feature/message.lpc:34`（栈顶刚好是 `check_all()` 里 `message("system", ...)` 发给玩家的那条）。每小时 3 分钟、每次启动后的第一个登录会撞上；战斗探针的登录控制台里 3–15 次出现一次。临时在 `receive_message()` 开头用 `call_stack()` 打出的调用链：`check_all` / `ready_to_start` 交替 109 层，再上面是 `create`、`logind.enter_world`。04:25 整点对 HEAD 和修好的树各登录一次，HEAD 报错、修好的没有。wqfy / zzfy / zzfy3 里同名文件是原版（`ready_to_start()` 里 `call_out("check_all", 500)`，`check_all()` 末尾重新挂上）；这里的 localtime 改写去掉了定时器，留下了递归的尾巴。删去 `check_all()` 末尾的 `ready_to_start();`（到点检查一轮，和原意一致）。archive 里没有任何地方在 `create()` 之后再调 `ready_to_start()`，所以每 25 分钟一次的检测本来就没有跑过，没有补回（升级仍在每次登录时由 `upgrade()` 检查）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/arch/coordinate.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `refresh`（`retask`）：动词函数不返回 1，搬动或销毁带动作的物件时报错（2026-10-21，KB 06 §7.339）

管理员扫描里 `refresh` 在重新分布使命之后报 `Illegal to move or destruct an object (/questobj/...) defining actions from a verb function(refresh) in object(/obj/user#...) which returns zero.`：`main()` 以第二条 `message()` 结尾、没有 `return`，答 0，而 `TASK_D->init_dynamic_quest(1)` 销毁了给玩家定义过动作（`init()` 里的 `add_action`）的使命物件：驱动只在动词答非 0 时才允许这样搬动或销毁，否则它接着遍历的动作表会悬空；答 0 还会让解析器在指令做完之后再补一句“什么？”。`main()` 末尾加 `return 1;`（同系已经返回 1 的 11 个同名文件没有动）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 5 条注册（2 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/huafu/obj/donkey.lpc`（`do_unride`）、`/d/huafu/obj/staff.lpc`（`full`、`gan`、`jianting`、`ls_ls`）。最多的函数名：`do_unride` 1 处、`full` 1 处、`gan` 1 处、`jianting` 1 处、`ls_ls` 1 处。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（other 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/usr/bbshelp.lpc`:`confirm_l_choice`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 8 个文件里有 17 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`/log/nosave/LASTCRASH`、`nosave/PURGE` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 长度检查按字节写，旁边的提示按汉字写：8 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 8 处（4 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logind.lpc:708`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/std/buildroom.lpc:68`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

