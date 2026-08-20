
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
