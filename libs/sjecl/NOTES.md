
## WASM 修复摘要（迁移自 meta.json 的 group_note）

Century/adm-single 血统（adm/single/master.lpc + adm/daemons/securityd.lpc），书剑代码库。WASM 修复：（1）§7.60 master.lpc log_error()→CHANNEL_D->do_channel() 编译期崩溃，用 find_object(CHANNEL_D) 守卫；standard_trace()（运行时的 error_handler 路径，不只是编译警告）里也有同样的模式，同样地守卫。（2）§7.59 securityd.lpc 的 valid_read() 无条件用 this_player() 覆盖驱动提供的 user 参数，拒绝了 load_object/include 触发的读取（比如 BAN_D->is_banned() 在每一次连线时都报"Read access denied"崩溃，因为 logind.lpc 做的第一件事就是拿连线 IP 去核对封禁名单，这时候连玩家 id 都还没设置）——已把 func=="load_object"/"include" 排除在覆盖之外，匹配已记载的修法。（3）§8.1 没减半的 GBK 字节区间 is_chinese() 加上对应没减半的长度界限 check_legal_name()（原为 4/8 加 i%2 字节窗口，改成逐码点的 2/4）。（4）§7.50 accept_kill 类的 is_killing(who) 物件/字符串不匹配，但这次不在 accept_kill() 里——而是在 5 个独立的 NPC"先揭穿身份再开打"对话档案里（d/city/npc/{guidao,guidao1,guidao2,xiaosong}.lpc、d/foshan/npc/wanglaohan.lpc、d/shaolin/npc/xiaosong.lpc），这些会静默破坏预载阶段 NPC 生成的编译；同样的 bug 也出现在约 20 个 kungfu/skill/*.lpc 档案里，写法是 target->is_killing(me)/ob->is_killing(me) 这种箭头呼叫，不会导致编译硬失败（只有 NPC 档案里那种直接/裸呼叫才会），按既定的"内容 bug 不逐一穷尽修复"惯例保持原样——只修了会阻断的那几处。另外播种了管理员：fluffos (admin) 加入（此前几乎空白的）adm/etc/wizlist，外加在 adm/daemons/sited.lpc 硬编码的 valid_login 映射（127./0. 前缀）里加了一条——这条血统在登录时独立强制执行按巫师 id 的 IP 白名单（sited.lpc 的 is_valid()），所以一个刚播种进 wizlist 的管理员 id 如果不同时播种这第二张表，就会永久无法从任何地址登录（"巫师必须有地址限制"）——和 AGENTS.md §1.5"既要播种阶级也要播种真正的权限数据"是同一类问题，只是表不同。已验证：完整注册（id→确认→密码→确认→中文名字→天赋摇点→确认→电子邮件→性别）→进入游戏世界，权限正确显示 (admin)。update 指令的成功讯息因为一个持续的 VIP/欢迎讯息刷屏打乱了脚本化测试的发送时机而没能捕获到（不是功能性 bug——已直接核对源码确认 ADM_PATH 和 securityd 的 exclude_read 表都没有把 (admin) 排除在 update.lpc 所在的 cmds/app 或 cmds/imm 之外）。记录了一处不阻断、未修的内容 bug：/d/wudang/npc/th.lpc 的 create() 呼叫 carry_object() 时传入的参数求值结果是 0（缺失的道具档案），导致 baoshid.lpc 预载 NPC 放置阶段出现一个被捕获的"Bad argument 1 to EFUN call_other()"——不阻断开机或任何核心功能。LPC 格式化工具对全部 10260 个档案运行；还原了 2 个通过"去空格后比对旧档案"扫描（覆盖 191 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案（clone/npc/tdh/idea.h、clone/obj/job/func.lpc）；直接逐一比对了全部 3 个 ASCII 地图档案（d/lanzhou、d/shaolin 两份）——全部干净，只是排版调整。格式化后重新验证过开机和注册都干净。

## 深度功能测试（§10.7，2026-08-05）：一个让整个游戏完全无法操作的严重 bug

之前 WASM 阶段的"注册→look/score/quit 都干净"结论具有严重误导性——
这次深挖发现，注册流程本身确实一路畅通（欢迎信息、VIP 提示、新闻系
统提示全部正常显示），角色也正确落地进游戏世界，**但落地之后任何一
个玩家指令，包括最基本的 `look`，都会返回"什么？"**，游戏事实上完
全无法操作，只是这个症状被埋在一长串正常的欢迎讯息后面，不细看很容
易被误认为是正常的静默返回。

根源是 AGENTS.md §8.3b 已经记录过的经典 bug——`adm/daemons/
commandd.lpc` 的 `rehash()` 用 `sscanf(cmds[i] + "$", "%s.c$",
cmds[i])` 从目录列表里筛出指令档案，但转档后所有档案都已经改名成
`.lpc` 后缀，这个模式永远匹配不到任何东西，导致 `search`/
`user_cmds` 两张指令表永远是空的，`find_command()` 对任何动词都返
回 0。这份档案早在之前一轮全库排查 §8.3a（`private nomask
command_hook`）问题时就已经被列入"已修复"名单——`command_hook()`
本身确实是干净的 `nomask`，没有 `private`——**但 §8.3a 和 §8.3b 是
两个完全独立的 bug，可以同时存在也可以只存在一个**，这份档案就是
"§8.3a 已修好，但 §8.3b 从未被检查过"的典型案例：即使 command_hook()
被正确呼叫了，它内部呼叫的 `find_command()` 因为指令表是空的，永远
返回 0，一样导致每个指令都落到最后的"什么？"兜底分支。已把
`"%s.c$"` 改成 `"%s.lpc$"`，恢复正常。

**一个有趣的连带线索**：修复前的 `boot.log` 里反复出现
`adm/daemons/baoshid.lpc`（随机放置宝石/NPC 的精灵）的
`choose_baosi()`/`random_place()` 触发 `*Too long evaluation.
Execution aborted.`（eval 开销超限）报错，一次会话里出现了 15 次。
一开始怀疑是 `random_place()` 自己"最多重试 50 次"的循环里连续编
译多个从未加载过的 NPC 档案导致开销爆表的独立 bug；但在修好指令表
之后，同样的操作序列里这个报错**完全消失，一次都没有再出现**——很
可能是空指令表导致每一次玩家按键都要 fallback 去尝试
`EMOTE_D->do_emote()`/`CHANNEL_D->do_channel()`（这两个精灵自己的
探测逻辑触发了比正常情况多得多的物件编译），间接给 `baoshid.lpc`
造成了额外压力，让它更容易撞上 eval 上限。修好指令表这一个根因就
顺带解决了两个看起来毫不相干的症状——已在 AGENTS.md §8.3b 补充记
录了这个连带现象，提醒以后遇到类似"看起来独立的 eval 超限报错"时
先检查指令表是否健康。
- **`§7.86`（留言板 `post` 崩溃）不适用**：全库只有 1 处
  `replace_program(BULLETIN_BOARD)` 匹配（`adm/daemons/
  huanjing2003/temp/huanjing1_pro_b.lpc`），核实过这份档案本身从未
  被任何地方引用（虽然它所在的"幻境"迷你游戏区域本身通过
  `d/city/guangchang.lpc` 是可达的，但这块留言板对象从未被放置/实
  例化），属于死代码，未做改动。
- **§8.9 不适用**：`enter_world()` 的食物/饮水初始化
  `user->set("food", 200)`/`user->set("water", 200)` 是无条件的固
  定值，没有年龄判断包装。
- **战斗/死亡/复活/新手礼物系统测试**：在北大街和"少林刀僧 行者"打
  了一场，角色多次尝试撤退都被拦截，最终力竭阵亡；死亡流程走的是
  这份档案自己独立实现的鬼门关→孟婆亭→孟婆汤→轮回投胎，全程未受打
  扰，正确落地在文档记载的新手起点"武馆前院"，`score` 确认死亡计数
  +1、角色状态正常恢复。落地后"书剑天下礼物使者"NPC 也正常响应
  `ask shizhe about newbie`（废除武功+赠送一周贵宾），符合 README
  记载的机制；`ask shizhe about 拜师` 这一步没能成功验证——中文参
  数在这次会话里传输时疑似被截断（`拜师`→`�师`），看起来像是本次
  测试用的 tmux 输入管线的编码问题，不是确认过的 mudlib bug，未深
  究，留给后续测试。
- **本次没有测试**：商店、门派拜师的完整效果（原因见上）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`§7.86` 复核：唯一 1 处命中确认为死代码，非误漏**：本档案早前的深度测试已经检查过全库唯一一处 `BULLETIN_BOARD` 命中（`adm/daemons/huanjing2003/temp/huanjing1_pro_b.lpc`），并核实过这份档案从未被引用/实例化，属于死代码，当时判断为§7.86 不适用、故意未改动。本次是跨库机械扫描，判定规则不区分"死代码/活代码"，顺手把这处也一并做了同样的无害删除（保留 `inherit`），不影响此前的死代码结论，仅记录在案。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Same lineage/shape as
sibling libs `bxsj`/`bxsj1`: 24 live `replace_program(ROOM);`
occurrences deleted (`d/wanshou/*.lpc`, `data/group/groom/*.lpc`,
`d/cangzhou/dangpu.lpc`). No roommaker.lpc factory-bug variant.
Verified via a clean native driver boot (zero new `debug.log` errors,
port listening, killed by exact PID after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: the touched header here (`death2.h`) turned out to be dead/unreferenced code in this lib -- the live NPCs (`yanluo.lpc`/`mengpo.lpc`/`pusa.lpc`) actually `#include` a sibling `death.h`, which was already guarded from an earlier fix. This edit is a harmless no-op; no live vulnerability existed in this lib for this file.

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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## Shop + 拜师 (2026-09-04 librarian loop)

The 2026-08-05 deep test left shop and 门派拜师 untested (`ask shizhe
about 拜师` was garbled by the tmux/telnet path). This pass used
`mudclient.py` (raw socket) on port **40139**.

First send is the BIG5 gate (`Are you using BIG5 font(Y/N)?`) — send
`n`. Email must have ≥2 characters before `@` (`aa@bb.com`; `a@b.c`
is rejected). New characters start with no money objects.

**拜师 (mortal `sjeqinb` / 秦风测 / `Mud@2026`)**: landed 武馆前院,
`answer n` to skip 狄云's tutorial. `ask shizhe about newbie` wiped
skills and granted the VIP newbie pack. Immediate follow-up `ask
shizhe about 拜师` hit the speech-busy gate (`您先歇口气再说话吧`);
that inquiry is help text only. `ask shizhe about 华山` recruited via
`recruit_apprentice` (`create_family("华山派", 99, "弟子")`) and
moved the character to `/d/huashan/zhengqi` (正气堂, 岳不群/宁中则
present). `score`: 头衔 华山派第一百代弟子, 师承【华山派】【书剑礼物使者】.
Unclean first quit; reconnect (`n` / `sjeqinb` / `Mud@2026`) printed
`重新连线完毕` and the same 华山 title/family — persist confirmed.

**Shop (seeded admin `fluffos` / `Mud@2026`, (admin))**: newbies have
no starting cash, so this was a paid buy with wizard-cloned currency
(not a programming workaround — `call me->add_money` is ACL-denied on
this lib). `clone /clone/money/gold`, `goto /d/xiangyang/shaobingpu`,
`list` showed 烧饼 二两白银又八十文铜钱. `buy 烧饼 from liu` misses
(NPC `do_buy` wants the item id, not `from <npc>`). `buy bing`
succeeded: `你以二两白银又八十文铜钱的价格从烧饼刘那里买下了一个烧饼。`
and `i` showed 一个烧饼(Shao bing) plus change. No LPC change.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py sjecl --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 515 个 `.lpc` 和 11 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：505 -> 505 通过，无回退；改过的头文件的 12 个包含者 11 -> 11 通过。启动时警告 17 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 20 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

孪生库 shujian2008 同日的整理（baa6caf453e，其中大半又是从 bxsj 搬来的）用 `scripts/lpc_twin_port.py adopt shujian2008 sjecl --pre baa6caf453e~1` 搬来：55 个文件与 shujian2008 修前逐 token 相同，清单里的警告全部落在这些文件里。内容见 shujian2008 的 NOTES（门派表/路线表改名、`equip.lpc` 的 `ob_hit()`、幻境 NPC 的重复声明、`kill_ob` 返回类型、`NAME_D` 的 `#undef`、嵌套注释等）。改动的 52 个对象 HEAD 与工作树各载入一次：HEAD PASS 52，tree PASS 52，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 21 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/fanchang`、`/kungfu/skill/hujia-daofa`、`/kungfu/skill/huntian-qigong/huntian`、`/kungfu/skill/lanhua-shou`、`/kungfu/skill/longxiang-boruo/fanchang`、`/kungfu/skill/yiyang-zhi`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-shengong`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`、`kuangwu`）；`qimen_baguazhen`→`qimen-baguazhen`（`suibo-zhuliu/wuzhuan`）；`xixing-dafa`→`xixin-dafa`（`tianlong-shengong`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuantia-wuji`→`xuantian-wuji`（`xuantian-wuji/wuji`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/cloth/cloth`、`/d/city/obj/blade`、`/u/lius/wudang/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 3 个，没有退步。

## `clone/spec/putao` 的 `long` 里引号错位（2026-10-18，KB 03 §4.6）

`set("long","这是一串由达摩传入中土HIG"神奇葡萄"NOR"，……")`：开引号落在 `HIG` 后面而不是前面，字符串在 `HIG` 处就闭合了，后面的 `神奇葡萄` 成了代码（`Illegal character 0xe7`），整个物件载入不了。把引号挪到 `HIG` 前面（`中土"HIG"神奇葡萄"NOR"，`，与同系其他库的同名文件一致）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## wushi.lpc 重复定义了头文件里的函数（2026-10-19，KB 06 §7.266）

`d/city/npc/wushi.lpc`（地下比武场的拳手）自己又写了一份 `nick_first`/`nick_second`/`create_nick()`，而它包含的 `skills_pfm.h` 里已经有一模一样的一份，驱动报 `Redeclaration of function 'create_nick'`，整个 NPC 载入不了；它还把 `skills_pfm.h` 已经包含过的 `r_name.h` 再包含一遍（`get_random_name()`/`random_name()` 因此也定义两次）。删掉文件里的重复定义和多余的那行 `#include "r_name.h"`，用头文件里的那份。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/shaolin/npc/xuan-du.lpc` 的 `#include "/u/hunthu/npc/xuan-du.h"` 改成 `/kungfu/class/shaolin/xuan-du.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon_combo`←sje：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/kungfu/skill/anran-zhang/jishi.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/clone/npc/mj.lpc`（3 处）、`/cmds/group/glist_new.lpc`（2 处）、`/d/city/npc/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 峨嵋 `d/emei/npc/jing-xin.lpc` 找不到 `nigu.h`，静心师太加载不了（2026-10-20，KB 04 §6.24）

这个 NPC 是 `kungfu/class/emei/jing-xin.lpc` 的副本（文件头注释还写着原来的路径），`#include "nigu.h"` 却没有跟着改：`nigu.h` 只在 `kungfu/class/emei/` 里，`d/emei/npc/` 下没有，所以静心师太从来加载不了（登录调查的游戏阶段控制台 5 次 `/d/emei/npc/jing-xin.lpc:5: error: Cannot #include nigu.h`）。改成绝对路径 `#include "/kungfu/class/emei/nigu.h"`，不复制头文件（两份会各自漂移）。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过，无退化。同一家族的六个库（bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2）是同一处。

## `exchange` 指令：数据库结果还没检查大小就取下标（2026-10-20，KB 06 §7.324）

`cmds/usr/exchange.lpc` 的 `Update_Credit()` 在声明里就读 `ret[0][0]`，下一条语句才检查 `sizeof(ret) == 1`：博物馆没有 MySQL，`dbquery()` 返回空数组，每次敲 `exchange` 都是 `*Array index out of bounds.`（指令扫描里的裸指令）。改成 `int credit = (sizeof(ret) == 1 && sizeof(ret[0])) ? ret[0][0] : 0;`。实测：`exchange` 显示 `您目前可用书剑通宝为：零个……`，`exchange gold` 显示用法，控制台无报错。同一份文件在 bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2 六个库里逐字节相同。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `ad`：`efun::shout()` 通不过 `valid_override`（2026-10-21，KB 06 §7.311）

管理员扫描里 `ad`（`cmds/adm/ad.lpc`）编译失败：`23:9: error: Invalid simulated efunction override`，指令里的 `efun::shout(...)` 不在 master 允许的目录里。本库的 sefun `shout(str)` 就是 `message("shout", str, users(), this_player())`，与 efun 的行为相同，改成直接调用 `shout(`。同系的 bxsj、bxsj1、shujian3、jinyongwenzi 的 master 放行，没有动。

## `bwscore`：比武大会的广场房间档案里没有（2026-10-21，KB 06 §7.299）

玩家指令 `bwscore`（`cmds/usr/bwscore.lpc`）不带参数时打印 `/d/bwdh/sjsz/square.lpc` 的描述，本库没有 `d/bwdh`（只有 xkm、xkx2000zxb、shenzhou 带着），`new()` 答 0，`0->long_desc()` 就是玩家看到的系统错误。改成 `(square ? square->long_desc() : "")`，用法提示照常。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 张三丰 `ask_me_6`：`who->query("id")`（2026-10-21，KB 06 §7.348）

非武当弟子问“太极道袍”时先 `command("shake " + (string)who->query("id"))`，`who` 声明了没赋值，应是 `this_player()`；抛错在拒绝的 `say` 之前，什么也说不出来。改成 `this_player()`，去掉 `who`。改动：`/kungfu/skill/zhang.lpc`。

## 保护任务的商人 `clone/obj/job/job_protect_npc.lpc`：两处笔误让整个文件从来没编译过（2026-10-21，KB 04 §6.29）

`clone/obj/job/protect.h`（保护商人的任务）克隆这个 NPC，但文件有两处笔误：`int baohu(string age)` 的函数体用的是 `arg`（`Undefined variable 'arg'`），而 `init()` 登记的是 `do_baohu`，函数名也对不上；`query->("id")` 多了一个 `->`。改成 `int do_baohu(string arg)` 和 `query("id")`（`if (!player = find_player(...))` 报的 `Illegal LHS` 只是前面语法错误引出来的连锁错误，这种写法本身是对的，没有动）；文件第一次能编译后带出 7 个 `Unused local variable` 警告（`sacrifice`、`exp_rate`、`skill_rate`、`lmt`、`menpai`、`killer`、`kill_num`），按 KB 04 §6.10 删掉。`baohu` / `protect` 两个动词现在有处理函数，任务的商人也第一次能出现。改动：`/clone/obj/job/job_protect_npc.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 19 条注册（14 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/daemons/robot-judge.lpc`（`do_test`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/wuliang/muwu1.lpc`（`do_tiao`）、`/d/dali/wuliang/shanlin-6.lpc`（`do_tiao`）、`/d/huanghe/npc/mafu.lpc`（`do_rideyz`）、`/d/huashan/jinshe/obj/haigu.lpc`（`do_move`）、`/d/huashan/npc/yaba.lpc`（`do_follow`、`do_kill`）、`/d/mr/obj/chahua3.lpc`（`do_chu`）、`/d/plummanor/hall.lpc`（`do_answer`）、`/d/songshan/fengchantai.lpc`（`do_decide`、`do_jieti`） 等共 14 个文件。最多的函数名：`do_tiao` 2 处、`do_learn` 2 处、`do_test` 1 处、`do_pass` 1 处、`do_resign` 1 处。没有动（读过）：`/clone/obj/job/job_protect_npc.lpc` 的 `do_baohu`（对象本身编译不过，登记留着，等对象能加载再处理）、`/cmds/leitai/dzd/dzd_flag.lpc` 的 `do_check`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/boat"` → `"/d/dali/yideng/obj/boat"`）, `/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/jiang"` → `"/d/dali/yideng/obj/jiang"`）, `/d/lanzhou/npc/chen.lpc`（`__DIR__ "../obj/jiuyin-book2"` → `"/d/lanzhou/obj/jiuyin-book2"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。
