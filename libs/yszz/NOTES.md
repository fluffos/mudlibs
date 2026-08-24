
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道：`feature/
command.lpc`（以及一份 `edit/` 目录下的镜像副本，核实不是生效路
径）里的"private nomask command_hook"只是历史注释保留的旧代码痕
迹（`// private nomask int command_hook(...)`），真正生效的声明
早已是干净的 `nomask int command_hook(...)`；命中了一处 `adm/
daemons/logind.lpc` 里的 printf("%O") 调试残留（新增 `yszz` 到
AGENTS.md §7.34 确认实例列表）；未命中 unguarded MESSAGE_D->、
stat/water 键名、§8.9 坏 age 判断。

**完整流程验证**：注册全新角色（沐妖神/id `yszzdive`），从"南城
客栈"起步，`hp` 确认食物/饮水/气血/精神槽均满值；向"疥顶小僧"
（这批西游记题材姊妹档案里反复出现的同一个高战力 NPC，
combat_exp 50000）发起战斗——完整交手数回合后被击昏迷致死（"你
死了"），送往"阴阳界"由"朱笔判官 崔珏"接引，明确提示"你莫乱跑，
画了生死簿，我好送你还阳"（和 `bmxkx2001` 那次发现的"鬼魂在复活
过程中被强制移动会永久卡死"是同一类设计警示，但本次静候没有被
任何其它系统打断，正常复活成功，`score` 数据完整）；`quit` 干净
退出。全程 debug.log 零报错。

**未覆盖范围**：拜师（五庄观/月宫/龙宫/普陀/方寸山/无底洞/轩辕古
墓/水帘洞/大雪山/地府共十个门派可选）、西行取经任务线、留言板因
时间原因未实测。

## 深度功能测试补测：拜师／西行取经／留言板（2026-08-24）

补测第二轮 NOTES 标记的三处未覆盖范围。

**留言板**：南城客栈留言板 `post <标题>` 进入内建编辑器，输入正文
以单独一行 `.` 结束，`留言完毕`；`look board` 正确显示新留言，作
者本人 `discard <编号>` 成功删除。round-trip 干净，无 debug.log 报
错。（测试中途一次通过 `scripts/tmux_mud.sh multi` 发送多行编辑器
正文时，`。` 结尾的中文句子在 telnet 层被截断、误触发本地
telnet 客户端的 `Ctrl-]` 转义——这是已知的 tmux/telnet 多字节透传
假警报，不是驱动或代码问题；改用一次性发送的原始 Python socket
脚本后单行/多行中文输入都稳定无误。同样的假警报又在 `ask yin
about 陈光蕊` 上重现了一次（`光` 被替换成 `�`），换用 raw socket
脚本发送同一条命令后文字完全正确，NPC 对话也正常，确认属于同一传
输假警报，不是取经任务线代码的问题。）

**拜师（选测月宫，嫦娥）**：新角色（女性，容貌 30）`goto`/`summon`
传送至嫦娥所在的"长思馆"，`apprentice change` 一次性走完全套流程
（嫦娥的 `attempt_apprentice` 检查性别+容貌门槛通过后自动
`recruit`），`score` 的"师傅"字段正确从"鬼才知道"变为"嫦娥"，并
获得师门长剑。十个门派共用同一套 `feature/apprentice.lpc` /
`cmds/std/{apprentice,recruit}.lpc` 机制，本次仅实测月宫一支，但
逻辑路径对全部门派通用。

**发现并修复一个真实的 programming bug**（非平衡性/内容问题）：
`cmds/std/apprentice.lpc` 里"对方已经用 recruit 表态愿意收我为徒"
分支（`ob->query_temp("pending/recruit") == me` 时），判断是否为
"背叛师门投入新门派"时直接比较
`me->query("family/family_name") != ob->query("family/family_name")`，
没有先判断 `me`（申请人）本来就有没有 `family`——对于第一次拜师、
从未加入过任何门派的角色，`me->query("family/family_name")` 恒为
0，永远不等于新师父的门派名，导致每一次「正常首次拜师」都被误判
成「背叛师门投入别人门下」，弹出错误的台词且把 `score` 清零。姊
妹指令 `cmds/std/recruit.lpc` 里对称的分支（`me->recruit_apprentice`
一侧）正确地先用 `(ob->query("family")) && (...)` 守卫，
`apprentice.lpc` 漏掉了同样的守卫，help 文本本身也写明"你已经有
了师父，又背叛师门投入别人门下"才会触发这个惩罚——代码与文档意
图不符。加了同样的 `me->query("family") &&` 守卫修复。

**修复前后均现场复现验证**：造出两名全新无门派角色，让已拜入月宫
的 `yszzcy` 先用 `recruit <目标>` 主动收徒（模拟玩家师父主动招募
从未拜师的新人这一常见场景），目标再用 `apprentice yszzcy` 确
认——修复前，回应是错误的"你决定投入云裳仙门下！！"（背叛台词）；
`update /cmds/std/apprentice` 热更新代码后，同样操作对第二个全新
角色正确显示"你决定拜云裳仙为师。"（正常拜师台词）。两次全程
debug.log 零报错，确认是纯逻辑 bug，不是编译/崩溃类问题，但确有
实际错误行为（错误台词+错误清零 score）。

**西行取经任务线**：`doc/help/newqujing` 里有完整的攻略文档，全线
共 36 "关"（`obstacle/number`），score 里"任务行动篇"栏正确显示
"你尚未踏上西行大道"（`obstacle/number == 0`）。实测了第一关"江
州／金山寺"的头两步：`goto /d/jz/fzroom` 找法明长老 `ask faming
about 血书` 正确给出反应并交出信物；`goto /d/jz/in` 找殷温娇 `ask
yin about 陈光蕊` 正确触发她的伤心台词。两步均无崩溃、无
debug.log 报错。后续关卡（双叉岭杀虎、`nianjing` 念经、流沙河跳
水等）因深度游玩成本高（帮助文档标注全线需要上千年道行/极高战力
才能推进到后期关卡）未继续深入，但已验证任务线的入口和早期节点
是可达、可交互、无编程错误的。

测试用角色（`yszzcy`/`yszztsb`/`yszztsc`）及其存档已清理；南城客
栈留言板测试留言已通过 `discard` 删除。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

WASM 修复：修好了 §8.1 GBK 字节区间 is_chinese()/check_legal_name() bug（这个驱动下 str[i] 是一个码点，不是一个 GBK 字节——真实的中文名字会被静默拒绝）；给 band.lpc 的 is_banned()/create_char_banned() 打上了本地回环放行补丁；通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。在 WASM 下用一个真实的中文名字（秦风）完整验证了注册+look/score/quit，管理员账号的 update 指令也验证可用。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 38 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 305 live occurrences deleted: 303 via scripted sweep (`fix_710_room.py`), plus 2 hand-fixed roommaker-tool templates (`clone/misc/roommaker.lpc`, `obj/roommaker.lpc` — both simple string-builder variant). 7 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40192 listening, zero new "cannot replace"/"cannot bind" debug.log lines. Pre-existing untracked test-account debris (`data/{login,user}/y/yszzdive.o`) confirmed left untouched by `git status` review before staging.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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
