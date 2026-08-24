
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
