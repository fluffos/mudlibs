
## WASM 修复摘要（迁移自 meta.json 的 group_note）

内容和 xxcqii 的小雪初晴II.rar 完全相同的 .zip 重新打包版——全部 3033 个共有 .lpc 档案逐字节相同（已通过对照 xxcqii 修复前那次提交的全量内容哈希比对确认）；唯一差异是多出一个档案 topten/topbook.lpc（一份运行时排行榜存档，不是源代码内容）。真正的 WASM 修复过程（httpd/dns_master 的 §7.52 socket 精灵修复、管理员播种、格式化）见 xxcqii，这里不再重复。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类：删除 846 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），另修正
`clone/misc/roommaker.lpc` 字符串拼接模板里同一枚烤死的
`replace_program(ROOM);`——和手足档案 `xxcqii` 是完全相同的 bug 形
状与命中数（847 处），但注意这次逐档对照发现两份档案在当前状态下
并**不是**逐字节相同（`roommaker.lpc` 等大量档案存在缩进风格差异，
制表符 vs 空格、大括号换行位置等），和本档案 NOTES.md 早先记录的
"与 xxcqii 完全相同"结论不一致（那条结论应是修复前某次格式化差异
导致，或指的是逻辑内容而非字节级别）——因此本次按独立档案完整走
了一遍验证流程，而不是假定与 xxcqii 的结果可以直接照搬。已用
`build-debug` 驱动干净启动验证（0 个新增编译错误，端口正常监听）；
未做完整 §10.7 深度游玩测试。

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

## 针对性排查：xxcqii 的 §10.7 round-two 7 类 bug 逐项核对（2026-08-27）

来源：`libs/xxcqii/NOTES.md`"深度功能测试（2026-08-27，round two,
AGENTS.md §10.7）"一节记录的 7 类 bug（同属小雪初晴系列，共享同一份
引擎代码）。逐一在本档案（`xxcqii2`）里定位对应档案并核对，7 类全部
存在，已全部按 `xxcqii` 的原始修复方式逐字修正：

1. **注册流程 debug 遗留 `printf("%O\n", ob)`**：`adm/daemons/
   logind.lpc`/`logind1.lpc`/`logind2.lpc` 的 `get_name()` 三份都有，
   已全部删除该行。用真实 socket 脚本连续注册一个新角色验证：设定
   中文名字之后到"请设定您的临时密码"提示之间，不再出现任何裸露的
   `/clone/user/loginXXX` 内部对象路径。

2. **`valid_learn()` 0/1 参数签名不一致**：`inherit/skill/skill.lpc`
   基类是 0 参数，`kungfu/skill/force.lpc` 也是 0 参数（本档案的
   93+ 个其它技能档案都是 1 参数），和 `xxcqii` 完全同型。两处都改成
   `int valid_learn(object me) { return 1; }`。用 `lpcc --batch` 单独
   编译 `/kungfu/skill/force` 验证：干净通过，无"Number of
   arguments...disagrees with previous definition"警告（driver 完整
   启动日志里也未见此警告）。

3. **AGENTS.md §7.11 实例**：`adm/simul_efun/file.lpc` 的
   `log_file()` 没有调用同档案里已有的 `assure_file()`，已加上
   `assure_file(LOG_DIR + file);`（连同前向声明）。本次未走管理员
   `call` 审计日志路径现场触发（测试预算用在了其余 6 类上），改用
   `lpcc --batch` 编译干净 + 静态核对修复后的函数体确认。已在
   AGENTS.md §7.11 补充条目。

4. **AGENTS.md §7.112 实例**：`d/shaolin/kfroom_1.lpc`~`kfroom_6.lpc`
   六个档案的形状和 `xxcqii` 完全一致——`kfroom_5`/`kfroom_6` 的
   `init()` 完全没有防重入保护，`kfroom_1`~`4` 只有一次性入场旗标、
   没有"本轮机关阵正在进行中"的防护。六个档案均按 `xxcqii` 的原始
   补丁逐字修正。由于少林寺前山门广场的守门僧（`d/shaolin/
   guangchang1.lpc`的`valid_leave()`）会拦下所有非"少林派"归属的
   角色（"这位施主请回罢，本寺不接待俗人"），无法靠纯步行到达
   `kfroom_5`，改用临时管理员账号（往 `adm/etc/wizlist` 追加一行、
   重启 driver 生效、验证完毕后已恢复原始档案内容，未保留）执行
   `call me->move("/d/shaolin/kfroom_5")` 直接传送进入——传送本身
   只是绕过 RP 前置任务，机关阵触发/断线/重连的验证路径和真实玩家
   完全一致。真实断线-重连复现实验（`socket.close()`模拟真实掉线，
   非清洁 `quit`）确认："一走进始武房...机关开动了"这句开场白在整个
   会话里只出现了 1 次（`grep -c` 核实），重连后机关阵继续原有进度
   （斗志数值连续下降），没有叠加第二条奖励链。

5. **AGENTS.md §7.151 实例**：`feature/dealer.lpc` 的 `do_list()`
   同样是 `j=tmp[goods];`（应为 `j=tmp[goods[i]];`），已修正。现场用
   `d/bianliang/npc/wei.lpc`（韦鸭毛，杂货铺，`carry_object()`带一件
   布衣，从新手初始房间往东、北、东三步可达）验证：`list` 命令修复后
   正确显示"1件布衣"（该 NPC 实际只带一件）。

6. **AGENTS.md §7.86 实例**：`d/kunming/dangpu.lpc`/`d/kunming/obj/
   dpm.lpc` 都有 `inherit SR_DANGPU;` 之后多余的
   `replace_program(SR_DANGPU);`，已删除两处。`dangpu.lpc` 经
   `lpcc --batch` 编译干净；`dpm.lpc` 全档案搜索确认同样是从未被
   引用的死代码，且带有与本次修复无关的既存编译错误
   （`set_name()` 未定义，`SR_DANGPU` 祖先链没有提供），按"存疑不动"
   处理，不修复，仅记录。

7. **AGENTS.md §7.152 实例**：`clone/user/user.lpc` 的 `reconnect()`
   同样缺少 `set_living_name()`，已在函数开头补上与 `xxcqii` 相同的
   两行。用真实双 socket 复现实验验证：角色 A 断线（`socket.close()`
   不发 quit）后在约 2 秒内重连，角色 B 立刻 `tell <A的id> ...`
   （注意用 id 而非中文名——`find_player()`按注册的 living name 也就
   是 id 匹配），A 端正常收到消息，未出现"没有这个人"报错。

**结算与清理**：测试角色（tstsnowc/d/f/g/h 等，含临时管理员
tstsnowf）的存档、`adm/etc/wizlist` 的临时追加行均已在提交前删除/
还原；`adm/etc/users`（访客计数器）因真实注册流程自然增长，比照
`xxcqii` 原提交的先例保留未回滚。`lpcc --batch` 全库编译检查：
3034 个档案里 2932 通过、102 失败——除已知的 `d/kunming/obj/dpm`
（见上方第 6 类，预先已知且与本次修复无关）外，其余失败与本次
7 处改动的档案均无交集，属于本库既有的历史遗留问题。`grep -h
'"port"'` 端口唯一性检查已过。

## Shop + 拜师 (2026-09-04)

Live native play on port **40138**. First send **`g`**. Seeded `fluffos
(admin)` in `adm/etc/wizlist` (sibling `xxcqii` already has this line;
the 2026-08-27 pass had appended it only temporarily). Registered
`fluffos`/`Mud@2026`, display 浮浮, 【天神】(admin), wizard guild.

**Shop.** `goto /d/bianliang/sanhelou`, 店小二 `list` already showed
`1件布衣` (2026-08-27 §7.151 `tmp[goods[i]]` fix still in place) plus
烤鸡腿 八十文. Cloned 一两白银, `buy jitui` → 买下烤鸡腿, leftover
二十文铜板. Relog kept the 二十文; food is not autoload.

**拜师.** `goto /d/huanhua/huzu` — unlike sibling `xxcq`, this tree
ships `npc/zuyuan_h.lpc`, so both 李子木 and 虎组组员 spawned.
`bai li` → 好吧…收你为弟子, 浣花剑派第六代弟子、虎组组员. Relog
`score` still 师父是李子木.

**Bug ported.** `inherit/room/room.lpc` `make_inventory()` had no
`objectp` guard after `new()` (same abort-rest-of-reset shape as
`xxcq` 2026-09-04). `zuyuan_h` exists here so 拜师 was not blocked,
but `reset()` still did unguarded `ob[list[i]]->is_character()` after
a failed `new()`. Added `if (!objectp(ob)) return 0;` plus the two
`objectp` checks in `reset()`. CRLF preserved. Dealer list-index was
already fixed (2026-08-27).

How to run: `cd libs/xxcqii2 && ~/src/fluffos/build-debug/src/driver
config.fluffos` then `g` / `fluffos` / `Mud@2026`.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/tangmen/nzlangn1.lpc`, `d/longmen/xuehepai/chenei.lpc`, `d/huanhua/wuroad2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xxcqii2`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 1 path reference(s) in 1 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 1 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 1 PASS, 0 that loaded before fail now, 0 more load.

1 files moved (1 `.HTM`); mostly under `www/html/WARNING.HTM` (1). A rescan with `scripts/lpc_warnings.py xxcqii2` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xxcqii2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 105 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：94 -> 94 通过，无回退；改过的头文件的 1 个包含者 0 -> 0 通过。启动时警告 3 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：与 xxcq 相同的两处编译错误：`kungfu/skill/wenjia-daofa/wryd.lpc`（「温柔一刀」）的 `if` 括号放错、`d/wenjia/obj/xiangshi.lpc` 的 `me->die;` 少括号，从未能编译；已改正，改动文件 HEAD 0 个、工作树全部载入。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 1 个文件，HEAD 与工作树各载入一次无回退（1 objects; HEAD PASS 0, tree PASS 1; regress 0; newly loading 1），这些文件的警告 2 -> 1。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。23 个文件 23 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - `d/wenjia/wenjia/wenjia/npc/wenliangyu.lpc` 先 `inherit NPC;` 又 `inherit F_DEALER;`，而 `F_DEALER` 自己已经继承 `NPC`，整套角色变量被带进来两份；删去前一行。
  - `adm/daemons/network/mail_serv.lpc` 的 `tmp[i] == EOT+"."` 改为赋值。
  - `inherit/private_room.lpc`、`recordable_room.lpc` 的 `setup()` 改 `void`。
  - `d/murong/hssg.lpc` 删去未用的 `skill`。
  - `include/daemons.h` 重定义的宏先 `#undef`；多余的 `inherit F_CLEAN_UP` 删去。
  - 改动的 52 个对象 HEAD 与工作树各载入一次，无回退；原报警告的 30 个对象重编译后没有警告。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

27 个文件来自侠客行体系：本库把 jing 改叫 jingli（`receive_damage()` 只接受 jingli/qi/douzhi/shenzhi），`receive_damage("jing", ...)` 报 `伤害种类错误`。按 jing→jingli、kee→qi、force→neili 改名；其中本库自己的 `cmds/skill/learn.lpc`：玩家教玩家时扣教者的 `jing` 报错，学不动时 `query("jing")` 永远为 0（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。17 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`bupangguan`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`wenjia-daofa`、`zhuifeng-zhang`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yiqi-guanriyue`→`yiqiguan-riyue`（`yiqi-guanriyue/heal`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

16 个文件、16 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/wenjia/obj/chouduan`、`/clone/weapon/blade`、`/d/wenjia/obj/grnduanda`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 15 个（15 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 16 个对象设了本库没有文件的武功（5 个名字，最多的是 `yanling-shenfa`、`shenyuan-gong`、`canhe-zhi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：16 个里 15 个通过，其余 1 个停在别的错误上（`d/murong/npc/job-dizi`：*Bad argument 1 to EFUN call_other()）。（`scripts/lpc_guard_set_skill.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/adm/daemons/securd.lpc`：`#include <login.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，0 个原来编译不过、现在载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/murong/npc/skill.h`：`mapping *skills=({ … })` 是慕容复能传授的武功表，和 NPC 基类 `feature/skill.lpc` 的 `mapping skills`（本人的武功等级）同名；驱动让后声明的盖掉先声明的（`define_variable`），`murong-fu.lpc` 的 `ask_learn()` 读到的一直是这张表，后声明的这份还被强制成 `nosave`。把表改名 `skill_table` 并明写 `nosave`，`ask_learn()` 里 `mapping skills = skill_table[random(sizeof(skill_table))];` 一行跟着改（初始化表达式里的名字指全局表，局部的 `skills` 在初始化之后才进入作用域：`rule_new_local_def_with_init`）。
- `d/murong/npc/dizi.h`：开头 `mapping skills; mapping learned;` 是从基类抄来的，`job-dizi.lpc` 一次也没用到，删掉（`Redeclaration of global variable 'skills'`、`'learned'`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/wenjia/skill/xiangshi_poison.lpc`（xxcq）、`/d/wenjia/wenjia/xiangshi_poison.lpc`（xxcq）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：驿站把任何输入都当成合法的去处；`valid_enable()` 对任何 usage 都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/inherit/room/yizhan.lpc`（7 处）、`/kungfu/skill/tianyu-bufa.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：百日十龙丸怎么 `eat` 都只得到“你要吃什么？”。改动：`/d/longmen/xuehepai/obj/bairiwan.lpc`（1 处）、`/d/wenjia/square.lpc`（2 处）。另有 `/d/murong/npc/laoda.lpc`（1 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/adm/sameip.lpc`（1 处）。

## `boss` 指令：`/open/shit.txt` 不在存档里，`write(0)` 报错（2026-10-20，KB 06 §7.285）

`boss 1` 先清屏、屏蔽所有消息，再 `msg = read_file("/open/shit.txt"); write(msg);`。`/open/` 是巫师目录，存档里没有这个文件，`read_file()` 返回 0，`write(0)` 报 `Bad argument 1 to receive()`，玩家的屏幕还被屏蔽着。改为 `if (stringp(msg)) write(msg);`（`cmds/usr/boss.lpc`）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/d/huanhua/npc/obj/saozhou.lpc`（1 处）、`/d/murong/hhyuan.lpc`（1 处）、`/d/yaowang/lufeng.lpc`（1 处）、`/d/yaowang/npc/lufeng.lpc`（1 处）、`/d/yaowang/npc/zhanggui.lpc`（1 处）、`/feature/skill.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 简易 `cat()` 把 simul_efun 对象的 euid 改成了玩家：存档时 `Too deep recursion`（2026-10-20，KB 06 §7.313）

`adm/simul_efun/file.lpc` 的 `cat()` 是 `seteuid(geteuid(this_player())); write(read_file(file));`，它在 simul_efun 对象里执行：玩家敲过一次 `help` 之后，这个对象的 euid 就一直是那个玩家的。它自己的 `log_file()` → `assure_file()` → `file_size(LOG_DIR + file)` 于是按玩家权限过 `valid_read()`，被拒绝，`securityd` 再用 `log_file()` 记一笔拒绝，又走回 `file_size()`……直到调用深度耗尽。第二次连线（角色已保存）时第一次被拒的是 `restore_object` 读 `/data/login/s/<id>.o`，之后控制台出现两条 `Too deep recursion.`（`securityd.lpc:173` 和 `:247`），`log/read_fail.log` 写满同一行，角色不再被保存。现在 `cat()` 先记下 simul_efun 自己的 euid，用调用者的权限读文件（`catch()` 里读），读完再还原，`read_file()` 返回 0 时不 `write()`。实测：第一次连线跑 `help`，立刻第二次连线，无递归、无 `read_fail.log`。xxcq 的 `securityd` 没有走到同一条路，同一份 `cat()` 一并改了（潜在的）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `nodjoin`：没有参数时 `present(0, ...)`（2026-10-21，KB 06 §7.336）

`cmds/skill/nodjoin.lpc`（`recruit.c` 的副本）第一句就是 `ob = present(arg, environment(me));`，裸命令 `nodjoin` 时 `arg` 是 0，`present(0, ...)` 在这个驱动里报 `Bad argument 1 to present()`，而且排在 `userp(me)` 的拒绝之前（玩家本来就用不了这个命令）。先拒绝玩家，再 `if (!arg || !objectp(ob = present(arg, environment(me)))) return notify_fail("指令格式 : recruit|shou [cancel]|<对象>\n");`（帮助里的那一行）。xxcq、xxcqii、xxcqii2 三份同样的改法。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/blockade.lpc`、`/cmds/adm/recover.lpc`。

## `xupdate`：`file[sizeof(file)] != '/'` 永远为真（2026-10-21，KB 06 §7.343）

管理员扫描里 `xupdate`（xyj2000）从根目录 `/` 开始递归时报 `Bad argument 2 to foreach Expected: array Got: 0.`：`UpdateDir()` 用 `file[sizeof(file)] != '/'` 判断路径是否已经以 `/` 结尾，下标等于长度读到的是 0，条件永远成立，`/` 变成 `//`，`get_dir("//")` 答 0。改成 `file[<1] != '/'`。同一个写法在 `xrm`、`rm`、`rmdir1`、`rmhir` 里有 55 处，没有动：对普通路径新旧写法的行为相同，唯一改变的是 `xrm /`，旧写法让它死在第一个 `get_dir("//")`，改了它就能递归删光整个游戏目录。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/hufa/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 30 条注册（26 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/wizmisc/zhihuan.lpc`（`test`）、`/d/bianliang/npc/tiejiang.lpc`（`do_buy`、`do_list`）、`/d/huafu/obj/gaoliang.lpc`（`do_bann`）、`/d/moto.lpc`（`do_list`）、`/d/murong/npc/murong-fu.lpc`（`do_jiaoliang`）、`/d/quanli/npc/dujue.lpc`（`do_join`）、`/d/quanli/npc/futianyi.lpc`（`do_join`）、`/d/quanli/npc/guan.lpc`（`do_join`）、`/d/quanli/npc/kang.lpc`（`do_join`）、`/d/quanli/npc/kong.lpc`（`do_join`） 等共 26 个文件。最多的函数名：`do_join` 19 处、`do_list` 2 处、`test` 1 处、`do_buy` 1 处、`do_bann` 1 处。没有动（读过）：`/d/quanli/npc/hua.lpc` 的 `do_join`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/murong/hole.lpc`:`look_out`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 13 个文件里有 16 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/promotion`、`nosave/CALL_PLAYER` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/wenjia_b`；`/d/wenjia/wenjia/wenjia/square.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 3 行只含这个指针的行（`"window" : (: look_out :),` `"震天鼓" : (: ask_me :),` `"gu" : (: ask_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 28 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 28 处（20 个文件）：拼名字的赋值 19 处、与汉字常量比较 9 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/baocan.lpc:170`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/tong.h:68`）；`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:2192`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：8 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 8 处（4 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 8 ) )`（`/adm/daemons/logind.lpc:714`）；`if( (strlen(name) < 2) || (strlen(name) > 12 ) )`（`/adm/daemons/logind1.lpc:696`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
