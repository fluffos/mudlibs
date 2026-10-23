
## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan/Lonely 血统，master.c 和 hhsj（014-1）以及 nitan170911 逐字节相同。WASM 修复：给 clone/user/user.lpc、inherit/room/room.lpc、adm/daemons/giftd.lpc 应用了 §7.15 的 efun::set/query/delete/addn 修复（这次是按内容逐一修的，不是直接复制档案）；修复了 check_legal_name() 里长度界限没减半的部分（2-4 字符，原来还是按字节数校准的 4-8）；修复了 efun::message() 对 exc_target=0 的拒绝。登录协议：get_user 用逗号分隔（"id,password,ciphertext,email"，逗号内部会自动替换成 U+2551），但 get_char 需要字面的 ║ 分隔符（"gender║img║nickname"）——这是通过直接阅读 logind.lpc 逆向工程得出的。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。用真实中文名字（秦风）的完整注册+look/score/quit+管理员 update（针对 clone/user/login.lpc，不是 /obj/login）已全程验证。

## 深度功能测试（§10.7，本轮）

这轮之前，xfbhh 的记录只到"注册流程能走通"这一层，从来没有真正深入
测试过"生命之谷"投胎仪式之后的内容。这次用真实驱动（native driver）
起服，走了完整流程：注册 → 生命之谷见盘古 → zz（选种族）→ xuan（选
性别）→ choose（选性格）→ washto（洗点分配属性）→ 进入"世界之树"新
手村 → score 查看角色卡 → 移动（west/east 走了新手村三个房间）。

### 发现并修复的 bug

**1. §7.68 死亡/复活软锁，4 处实例**（`d/death/npc/{bai,hei,bgargoyle,wgargoyle}.lpc`）：
`death_stage()` 的 `if (!ob || !present(ob)) return;` 把"角色永久离开"
和"角色只是暂时不在场"这两种情况混在一起处理，任何一种都会让复活流
程永久卡死，不重试也不报错。按标准修法拆成两个判断：`!ob` 才真正放
弃，`!present(ob)` 则用该文件原有的重试间隔（bai/hei/bgargoyle 是 5
秒，wgargoyle 沿用其自身独有的 10 秒节奏）重新 `call_out`。

**2. §7.7 corrupted-dbase 下的 capitalize() 崩溃**（`cmds/std/say.lpc`）：
`capitalize(query("id", me))` 在 `me` 的 dbase 被清空（`id` 变成整数 0
而非字符串）时会直接报错，导致任何人在场时崩溃整个 "say"。修复为
`stringp()` 判断后再 capitalize，不再假设 `id` 一定是字符串。

**3.（本轮最大的发现）新的 §7.78：CHARACTER 的部分 mixin 文件里的裸
`set()`/`query()` 调用，即便整个 CHARACTER 对象已经通过 §7.15 修复
拿到了真正的本地 F_DBASE，依然会解析失败。** 起因是调试
`d/register/npc/pangu.lpc`：`set_name("盘古", ...)` 执行完
`query("name")` 立刻读回 `0`，玩家看到的"盘古"NPC 显示成武器名
"巨斧"，玩家自己的名字在对话里显示成字面的 "0"。

排查过程：`feature/name.lpc`（`set_name()` 的真正定义处）只
`inherit F_NATURE;`，完全没有 `F_DBASE`。LPC 的裸函数调用是按"定义
该函数的文件自己的编译期继承链"解析的，不是按"最终被组合进去的对象
的继承链"——`char.lpc` 虽然同时 `inherit F_DBASE;` 和
`inherit F_NAME;`，但 `name.lpc` 内部写的裸 `set()`/`query()` 在
`name.lpc` 自己编译时就已经因为找不到本地候选而落到 simul_efun 的共
享兜底 dbase 上了，跟 `char.lpc` 后来继承了什么完全无关。用最直接的
办法验证：`pangu.lpc` 自己 `create()` 里的裸 `set("long", ...)`（这
个调用是在 `pangu.lpc` 自己的作用域里写的，`pangu.lpc` 通过
NPC→CHARACTER 确实有 F_DBASE）事后能正确读回；而 `set_name()` 内部
的 `set("name", ...)` 不能——同一个对象、同一个时刻，只是调用发生
的"物理文件"不同，结果就天差地别。

最初想按 §7.15 的老办法给 `name.lpc` 也加一行 `inherit F_DBASE;`，
结果直接编译报错：`Illegal to redefine 'nomask' function '_query'`
——因为 `char.lpc` 已经通过另一条路径继承了同一个 `F_DBASE`，这个驱
动不会自动去重同一份文件的多路径继承，反而是硬冲突，会连累
`char.lpc` 整体编译失败（现象是每次连线登录提示都变得乱七八糟）。

最终修法：把这些 mixin 文件里"自己对自己"的裸调用统一改成
`this_object()->set(...)`/`this_object()->query(...)`（call_other），
让调用在运行时动态派发到真正组合出来的那个对象身上，行为上等价于一
次"本该正确解析"的裸调用。受影响的 CHARACTER 组成文件一共 13 个：
`action`、`apprentice`、`attack`、`attribute`、`command`、
`condition`、`damage`、`equip_liv`、`message`、`more`、`move`、
`name`、`team`（只有 `alias`/`edit`/`finance`/`skill` 没有裸调用）。

这个 bug 的严重程度远超 pangu 一个 NPC 的对话乱码：`command.lpc` 的
`enable_player()`——每一个新角色登录时 `char.lpc` 的 `setup()` 都会
调它，不是只在这一个 NPC 身上触发——里面的裸 `query("id")` 读回 0，
直接让 `set_living_name()` 崩溃（`Bad argument 1... Expected: string
Got: 0`），也就是说修复前**任何一个新角色的登录/初始化流程本身就是
崩的**，只是驱动的错误处理器把崩溃吞掉了，看起来像是正常继续。
`attribute.lpc` 的 `query_str()`/`query_int()`/`query_con()`/
`query_dex()`/`query_per()`（战斗/属性读取的核心函数）也是同样的裸
调用模式。

修复后完整重新走了一遍：注册 → zz 1 → xuan 1 → choose 1 →
washto 50 50 50 50 → 进入世界之树。`score` 显示的膂力/悟性/根骨/身
法四项精确等于 washto 分配的 50/50/50/50（修复前这些函数会返回错误
或者共享着别的对象的脏数据），气血/精气/内力/精力等状态条数值也完
全正常（600/600、450/450、2000/2000、1000/1000），全程 `debug.log`
保持空白。

**4.（已记录、本轮未修复）新的 §7.79：裸 `addn()`/`addn_temp()` 自
targeting 调用恒定出错，跟 F_DBASE 无关。** `addn` 这个函数在整个代
码树里**从来没有本地定义过**，只存在于 simul_efun 的
`wizard.lpc`（用来兼容一个这个驱动本来没有的原生 efun），任何裸调用
必然是货真价实的 simul_efun 调用；不带显式目标对象的自身增减写法
（如 `feature/pill.lpc` 的 `addn("food_remaining", -1);`）在
simul_efun 调用期间 `this_object()` 就是 simul_efun 自己，实际改的
是 simul_efun 自己的一次性 dbase，而不是技能真正想加成的角色。用
`grep -rPn '(?<!->)\baddn\(|(?<!->)\baddn_temp\(' --include="*.lpc"`
扫了一遍，命中约 **10150 处、分布在约 3590 个文件**，绝大多数在
`kungfu/` 技能特效代码里——规模远超一次深挖能处理的范围，本轮只记录
不修复，已经写进 AGENTS.md §7.79，留给以后专门的一轮处理（大概率需
要脚本化批量替换成 `this_object()->add(...)`，而不是手工逐个改）。

### 未继续测试的部分

时间关系，注册/属性分配/新手村移动验证完之后没有继续找怪打架、逛商
店、拜师门派——上面 §7.78 这个 bug 波及范围极广，判断优先级应该是先
把这个记录清楚、把 CHARACTER 的核心裸调用修完并验证登录/属性不再崩
溃，比继续往后面玩更重要。后续如果有专门针对 xfbhh 的一轮，建议先看
战斗（在新手村外找到怪物，`attack.lpc`/`damage.lpc` 这两个刚修的文
件直接决定战斗数值对不对）、然后是死亡/复活（这次 4 个 §7.68 修复
点还没有真正打死过一次角色去验证复活链路本身）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 83 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

用新编译的 `~/src/fluffos/build-debug/src/driver`（origin/master 最新拉
取，含本项目自己提交并合入的 #1343/#1344 两个 PR，以及同一会话里另外提
交的驱动 PR：把编译诊断严重度标记从小写改回大写 "Warning:"/"Error:"，
专门为了兼容本语料库大量老式 MudOS 惯例的 mudlib 代码）重新验证。

### `to_int()` 任务计数器修复

`adm/daemons/combatd.lpc`/`cmds/std/whisper.lpc` 里全部 `quest_count = ...
% 500` 已经是 `to_int(query(...)) % 500` 的修复后形状，无需改动。

### 新发现并修复：与 hhsj/nt6 逐字节相同的 `log_error()` 严重度门控缺失

`adm/kernel/master/error.lpc`——和 `hhsj`/`nt6`（同一会话本轮更早修复
过）的对应文件逐字节相同，同一个 bug。修复：只在真正的 error 时才转
发给玩家（`debug` 频道广播给巫师和 `write_file()` 落盘均保持不变），
用 `"arning:"` 大小写无关匹配（AGENTS.md §7.10 案例记录）。

`adm/kernel/simul_efun/message.lpc` 的 `message()` 包装函式**已经**带
有 `if (!exclude) exclude = ({});` 守卫（虽然没声明 `varargs`，这个驱
动仍然接受 3 个实参的呼叫），不是本轮的 bug，未改动。

### 新发现并修复：`data/emotion/` 目录缺失导致 `emote_d.lpc` 存档失败（AGENTS.md §7.11 已有先例）

`adm/daemons/emote_d.lpc` 的 `DATA` 常量是 `"/data/emotion/emotion" +
__SAVE_EXTENSION__`，但这份档案从未附带 `data/emotion/` 目录，每次表
情指令（`emote_d.lpc` 的 `create()`→`remove()`）触发存档都命中
"*Could not open /data/emotion/emotion.o.tmp for a save."，玩家端表现
为"这里发现了臭虫"。修复：`mkdir -p data/emotion`（含 `.gitkeep` 占位
以便提交这个空目录）。**现场验证**：修复前干净注册流程命中这个报
错；修复后同样的注册+欢迎序列流程零报错。

### 冷启动级联编译撑爆 `maximum evaluation cost`（AGENTS.md §7.90/§10.8 已有先例）

第一次全新注册在 `combatd.lpc`→`simul_efun.lpc` 的 `append_color()`
链路上命中一次"Too long evaluation. Execution aborted."，符合已知类
别。**验证自愈**：驱动"热身"一次注册尝试后，后续全新账号一次性干净
走完注册→欢迎序列（含活动/新闻/邮件提示），全程零报错。

### 完整游玩测试范围

沿用既有记录的"注册成功进入泥潭注册室，欢迎序列正确显示"作为及格
线。战斗/死亡循环仍未触达（上一轮已经记录过同样的时间预算取舍），留
给下一次专门测试。

### 本轮结论

驱动升级后 xfbhh 整体状态良好：任务计数器 `to_int()` 修复确认已生
效；新发现并修复两个真实 bug（与 hhsj/nt6 逐字节相同的 `log_error()`
严重度门控缺失、`data/emotion/` 目录缺失导致的存档失败）；`message()`
包装函式这次不是 bug（已经带有守卫）；冷启动 eval-cost 级联验证自
愈。测试账号（`qinfengshiyi`/`qinfengshier`/`qinfengshisan`）存档留在
`data/` 下作为佐证，未清理（未跟踪文件，不纳入本次提交）。

## AGENTS.md §7.100 修复（2026-08-19）

同 `hhsj` 同源的 `ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷
（详见 AGENTS.md §7.100）：本 lib 4984 个房间文件的 `create()` 末尾
（紧跟 `inherit ROOM;`）都有这一行多余调用，第一次对该房间对象绑定
闭包会永久失败。同款地雷也烤进了自带建房工具
`clone/misc/roommaker.lpc` 的一处字符串拼接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4985
files changed, 1 insertion(+), 4987 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40190 正常监听，
`debug.log` 全程干净。管理员 `fluffos` 账号（同 hhsj 的"自连数据
库"登录握手：单行 `id,password,x,email`）`goto` 走访 14 个刚修复的
房间（`d/huijiang`/`d/huanggong`/`d/luoyang`/`quest/zhuzao`/
`d/shenfeng`/`d/fuzhou`/`d/xingxiu`/`d/baihuagu`/`d/kunlun` 等区
域），均正常返回，无 "cannot replace"/"cannot bind" 新增日志行。按
精确 PID 结束驱动；登录产生的两处已跟踪存档增量
（`work/data/{login,user}/f/fluffos.o`）已 `git checkout --` 还原。

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果：`addn`/
`addn_temp` 只在 `adm/kernel/simul_efun/wizard.lpc` 有 shim 定义，
`ob` 缺省为 `this_object()`——但这个 `this_object()` 是在 simul_efun
内部求值，指向 simul_efun 对象自身，不是真正调用者，于是写入垃圾去
处、静默丢失。3 参及以上调用（显式传 `ob`）从调用点求值 `this_
object()`，本就正确，不受影响。

用改造版 `argcount.py`（括号深度 + 注释/字符串屏蔽的顶层参数计数器）
定位裸 2 参调用，改写为 `this_object()->add(...)`/`this_object()->
add_temp(...)`。首轮脚本一度误伤 `clone/user/user.lpc`——该文件本地
定义了一个（命名笔误，本应叫 `add` 却写成 `addn` 的）2 形参覆盖函
数，脚本把这个函数定义行当成了"2 参调用"改写，产出语法错误
（`L_ARROW unexpected`）。修复脚本加入"定义 vs 调用"通用判别（前一
个词是类型/修饰符关键字 + 右括号后紧跟 `{`/`;` → 判定为定义，绝不
改写），并逐文件探测本地覆盖：`clone/user/baby.lpc` 全 6 个 lib 都
本地覆盖了 `addn`（未覆盖 `addn_temp`），`clone/user/user.lpc` 仅
xfbhh 有上述笔误覆盖——两处的裸 `addn(...)` 调用经正常 LPC 名字解
析走本地函数，从未真正命中过 simul_efun shim，予以排除；`baby.lpc`
唯一的 `addn_temp(...)` 调用未被本地覆盖，正常修复。核实全库无任何
文件 `inherit` 这两个文件，排除范围无需向外传播。

结果：902 处改写（`clone/user/user.lpc` 排除 12 处、`clone/user/
baby.lpc` 排除 8 处但修复其 1 处 `addn_temp`），`git diff --stat`：
458 files changed, 902 insertions(+), 902 deletions(-)，与工具输出精
确吻合。`cmds/adm/rp.lpc`/`rpp.lpc`（已知损坏的旧管理工具，`addn`
参数解析本就不成立）按调查阶段结论跳过未动。

验证：`build-debug` 驱动真实冷启动，端口 40190 正常监听，`debug.
log` 全程干净，无新增编译错误。全新账号（`qintest779c`/角色名"秦
测风"）走完注册流程，成功进入泥潭注册室并收到欢迎序列，符合 §10.1
及格线。按精确 PID 结束驱动。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 6 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-04，shop + 拜师）

Lonely GUI：服务端先发 `ver1.0,<salt>` 和「版本验证成功」，`jiance()`
把第一行当 `get_user`。逗号会自动换成 U+2551，所以第一发
`fluffos,Mud@2026,x,x@x.com` 即可（不必先回 `123456789abcd`）。管理员
id 不加 `_1`。巫师落在巫师休息室，未投胎时 `score` 报「还没有出生呐」。
HP 状态条约 1Hz，脚本 idle 必须 ≤0.45。`clone` 被 `is_admin()` 锁住
（只认 `admin_flag==21` / uid `luoyun`/`modao`，`VERSION_D` 发布站判断
已注释）——设计，未改。

投胎：`goto /d/register/entry`（生命之谷）→ `zz 1` → `xuan 1` →
`choose 1` → `washto 50 50 50 50`（每项 10–200，和必须 200）→ 世界之树。
`score`：男性人类、光明磊落、膂力/悟性/根骨/身法 50/50/50/50。

拜师：未投胎时在 `/d/city/lichunyuan` `bai kong` 已被空空儿收下（丐帮
第二十代）。投胎后 `score` 仍是【门派】丐帮 / 【师承】空空儿。本 lib
的 `feature/dealer.lpc` 没有天涯系那种「丐帮拒买」门，不必先买后拜。
华山 `yue-buqun`/`yue-wife`/`feng-buping` 和青城 `yu` 的
`recruit_apprentice` 把限额键打成 `apprentice_availavble`（`create()`
写的是 `apprentice_available`），递减是空操作；已改键名。

商店：醉仙楼 `list` 只列出店小二身上那件未装备的「布衣」，
`buy 1 jitui` / `buy 1 烤鸡腿` 都回「你想买什么？」。根因是
`feature/dealer.lpc` 作为 mixin 没有自己的 `F_DBASE`，裸
`query("vendor_goods")` 打到 simul_efun 共享 dbase，`init_goods()` /
`do_list` 都读不到 NPC 在 `create()` 里 `set` 的货表；`all_goods`
只剩身上的布衣，对不上鸡腿。同文件里其它 1 参自指向
`query`/`query_temp`/`set_temp`/`delete_temp` 一并改成
`this_object()->…`（不能给 dealer 加 `inherit F_DBASE`，会跟
CHARACTER 的 nomask `_query` 冲突）。旁路文件 `feature/dealer1.lpc`
的 `init_goods` 已经是 `this_object()->query("vendor_goods")`，但
没有任何 NPC `inherit F_DEALER1`。

钱：武庙二楼 `ask gift about 礼物` 走节日奖励，当前无节日。
`ask gift about 每日礼物` 给一条小灵脉 + 500 洪荒点。巫师
`gift fluffos` 发到 `/clone/gift/xiandan` 时 `new()` 失败
（档案不存在），`item->move` 对 0 做 call_other——管理员指令缺档，
未当玩家商店 bug 修。`cmds/usr/sellitem` 把售价写入 `balance`，
`MONEY_D->player_pay` 在身上没带现钱时会扣存款。

重启驱动后现场复核：`list` 列出烤鸡腿/包子/烤鸭/酒袋/干粮等货表；
`giveall /clone/money/gold` 后 `buy 1 jitui` 得到「你从店小二那里买下
了一根烤鸡腿」，身上出现 `jitui`，找零灵石碎片/灵石。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xfbhh`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 3 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 3 PASS, 0 that loaded before fail now, 1 more load.

1 files moved (1 `.C`); mostly under `u/gigi/swing.C` (1). A rescan with `scripts/lpc_warnings.py xfbhh` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xfbhh --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 2123 个 `.lpc` 和 50 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：2039 -> 2039 通过，无回退；改过的头文件的 635 个包含者 615 -> 615 通过。启动时警告 14 -> 0；新进程登录（输入名字）正常。
手改：`adm/kernel/master.lpc` `direct_run_binary()` 的 `ob`、`vob` 只在 `#else`（BINARY_SUPPORT）里用到，声明挪进去；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去。护送任务杀手 `d/city/task2/shashou.lpc` 调用本库 namesd 没有的 `jap_name()`（三次加载一次失败）并把数组 id 再包一层，同 nitan6（KB 06 §7.237，`scripts/lpc_nitan_jap_name.py`）；修正后单独加载 6 次全过，探针 `new` 30 个 id 都正常。（裸 telnet 输入名字后 HEAD 与工作树都无回应，相同。）
（更正：本库没有任何 task2 以外的文件生成 `renzhi` 或发 `miling`，这个护送任务目前没接进游戏，上面的杀手修正是在休眠内容里。）

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 9 处比较、0 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒，`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽，`taskd` 从来加载不起来——玩家的 `task`、`locate` 指令只显示“这里发现了臭虫”。改正切片和列表（列表空了就停）；真正走房间之后首次冷加载要 5 秒以上，`maximum evaluation cost` 提到 10000000（nt6 原本就是最大值）。新进程建人物后 `task` 列出使命物品、`locate` 可用；HEAD 两者都失败。

- 2026-10-10：`/kungfu/skill/sad-strike/tuo.lpc`、`/kungfu/skill/taiji-jian/jian.lpc`、`/kungfu/skill/wanjiandian/jian.lpc`、`/u/mud/skills/wudang/jian.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 61 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 12 个，只在 #if 分支用的声明移进分支 6 个文件；改动 79 个文件，HEAD 与工作树各载入一次无回退（79 objects; HEAD PASS 79, tree PASS 79; regress 0; newly loading 0），这些文件的警告 116 -> 19。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- `d/death/qiao1.lpc`：`if (dir == "north") { /* … */ }` 只剩注释的空块，把 `if` 一起挪进注释（行为不变）。
- `d/dj/dj9.lpc`：`ob == me;` 应为 `ob = me;`，否则后面的 `if (ob == me)` 永远不成立，死因“挑战天威,最终身死道消”从不记录。
- `kungfu/skill/miaojia-jian/gan.lpc`、`zhai.lpc`：`string name() { HIY "…" NOR; }` 少了 `return`，招式名为 0；补 `return`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：adm/daemons/mysql_d.lpc u/lonely/combatd.lpc u/redl/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（二）

- `u/gigi/test/gigicook.lpc`：`arg == menu_list[0]` 改为 `=`（与 nitan170911 同）。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告清零（全库重扫：23264 个文件可编译，0 条警告；HEAD 没有单独全库扫，5667 个对象的抽样载入里 HEAD 打印 393 条警告、工作树 30 条，后者都在本来就编译不过的文件里）。内核与 nitan170911/hhsj 逐字相同：`scripts/lpc_twin_port.py adopt nitan170911 xfbhh` 搬来 99 个同码文件，`adopt hhsj xfbhh` 搬来 chard1~3、bingdong、两个 u.lpc，其余本库自己的版本手改同样的根因。载入核对：`5667 objects; HEAD PASS 5556, tree PASS 5556; regress 1; newly loading 1`——那一个回退是 `adm/daemons/taskd.lpc`，它在 HEAD 单独载入（新进程）三次里两次同样以 `cost limit reached, limit: 10000000 usec` 失败、一次通过（耗时约 11 秒，正好卡在上限），与本次改动无关。删除声明审计 0 处待看。

- **严重：F_DBASE 旁边的混入件读写 simul_efun 的共享 dbase**（详见 nitan170911 同日一节；本库 `feature/dealer.lpc` 早先只把 `init_goods()` 一处改成 `this_object()->query`）。`include/dbase.h` 补上原型，`equip`/`itemmake`/`food`/`liquid`/`pill`/`alias`/`message`/`name`/`damage`/`dealer`/`banker`/`guarder`/`apprentice`/`unique`/`control`、`inherit/char/master.lpc` 都包含它；`npcsd.lpc`、`eval.lpc` 去掉包含。
- **`inherit/char/master.lpc` 开除弟子**：`if (query("skill_expell_penalty_tsl"), me)` 逗号表达式恒真，从不削减内力/精力上限；改为 `query("skill_expell_penalty_tsl", me)`。
- 自制道具 autoload 由 `item.lpc`/`combined.lpc` 交给 itemmake 的 `query_itemmake_autoload()`/`itemmake_autoload()`；神木王鼎虫表、`xiang.lpc` 的 `remove()`、boss 任务 NPC 的 `WAIT_TIME`、幻境变量重复声明、`template/` 改名、`d/yixing/doc` 头文件守卫、宏 `#undef`（含 `chard1~3` 的 HUMAN_RACE、`bingdong` 的 BOOK、`channeld` 不再定义 GWIZ）、`kuangfeng` 的 `attempt_apprentice()` 改 `void`、三个 `combatd.lpc` 的 `def`/`armor` 挪进 `#ifdef`、注释里套的 `/*`，同 nitan170911/hhsj。toolkit 删去 8 个重复继承 F_CLEAN_UP。

## 深度功能测试（§10.7，2026-10-12）：KB 05 §7.15 残留收尾（feature/save.lpc）

- 复查当天早些时候 dbase.h 原型一轮漏掉的混入件。`feature/action.lpc`、`condition.lpc`、`move.lpc` 在本库里**没有问题**：忙乱（`me->query_all_buff("avoid_busy")`）、中毒抗性（`this_object()->query_all_buff("avoid_poison")`）、移动时的 `this_object()->query("equipped")`、`env/brief`、`guardfor` 早就写成 `this_object()->` 或带物件参数的两参形式，没有一处裸单参 `query()`/`set()`（nitan6 的同名文件是裸调用，那里才需要 `#include <dbase.h>`），所以不加包含、不改。
- 真正漏掉的是 `feature/save.lpc`：它也被不带 F_DBASE 的守护进程继承，不能加原型；`restore_package()` 两处 `log_file("restore_package", query("id") + ...)` 是裸单参调用，读的是 simul_efun 的共享 dbase，日志里的玩家 id 恒为 `0`。改为 `this_object()->query("id")`（同 nitan6 提交 3264a2e14e1）。
- 探针（新进程，HEAD 与工作树各一次）：两个店小二，一个设 `apply/avoid_busy`=77、`apply/avoid_poison`=88，另一个读到 0，`start_busy(5)` 正常；长剑 `wield` 后移给另一个 NPC，原持有者 `weapon` 清空、`equipped` 清零——改前改后相同。带 F_DBASE+F_SAVE 的探针物件 `restore_package()` 遇到不存在的物件路径：改前日志 `0:/no/such/probefile`，改后 `probesv:/no/such/probefile`。
- 载入回退检查：继承 F_SAVE 的全部对象加 `clone/`、`d/city`、`feature/`、`inherit/`、`adm/daemons/`、`cmds/` 抽样，`2493 objects; HEAD PASS 2409, tree PASS 2409; regress 0; newly loading 0`（失败的 84 个 HEAD 同样失败），改动文件无编译警告；删除声明审计 0 处。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。20 个文件 25 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/clone/npc/walker.lpc`（`pot *=`）、`/clone/npc/walker.lpc`（`score *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 hhsj/nt6 同源同修）：36 个技能文件的 `int power_point()` 分支里返回 0.6–1.4 的浮点，经 `int` 返回被截断；本库没有调用者，改为 `float`、保留原数值（`scripts/lpc_fix_float_hooks.py`）。`hockshop` 售价和 simul_efun `ntefun.lpc` 的 `sqrt` 结果写明 `to_int()`，simul_efun 能载入。改动的 250 个对象 HEAD 与工作树各载入一次，无回退。

- 2026-10-14：10 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；17 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：25 个对象，新增载入 21，回退 0。

- 2026-10-14：`foreach` 里把 `array` 当类型（`foreach (string type, array data in news)`），本驱动不认；改为 `mixed *`（`scripts/lpc_fix_array_type.py` 现在也处理 foreach 变量）。`adm/daemons/realnews_d.lpc` 还调用本驱动没有的 `to_default_encoding()`，仍不编译。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。34 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。


## 去烦恼指 `qufannao-zhi`（2026-10-15）

该技能 `inherit F_DAMAGE`，其中 `query`/`query_temp` 的成员原型遮住了 simul_efun 的 `query(prop, ob)`，于是 `valid_learn`/`practice_skill` 报 `Undefined function called: query_temp`。改为 `me->query_temp(...)` 等直接调用。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 5 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。


## 摆摊状态的指令路径（2026-10-15）

`kungfu/condition/baitan.lpc` 调用 `/cmds/std/baitan.lpc`，指令实际在 `/cmds/usr/baitan.lpc`。已改正路径；本库摆摊指令用 `start_busy()`，目前没有地方施加这个状态，属于未接线的代码。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`chongling-jian`、`duoluoye-zhi`、`feifeng-bian`、`huashan-zhang`、`murong-jianfa`、`sougu-yingzhua`、`xuedao-daofa`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`busi-shenglong`→`busi-shenlong`（`shenlong-dafa`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`jiemie-zhua`→`jimie-zhua`（`huzhua-claw`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`meiren-shanzhao`→`meiren-sanzhao`（`meiren-sanzhao/fengzi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 乾天一阳「聚精」用了未定义的 MIN（2026-10-15）

`qiantian-yiyang/jujing` 从书剑（sj）移植过来，用到 `MIN(...)`；书剑的 `globals.h` 定义了这个宏，本库没有，文件编译失败。在文件里补一个局部 `#define MIN(x, y)`，现在可以载入。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。3 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。


## 拜堂时请不来月老（2026-10-15）

苏州媒婆（`d/suzhou/npc/meipo`）和红娘（`adm/npc/hongniang`）拜堂时 `new("/d/suzhou/npc/yuelao")`，本库这个 NPC 放在 `d/ruzhou/npc/yuelao.lpc`（文件头仍写着旧路径，与 nitan3 等库的 `d/suzhou/npc/yuelao.lpc` 逐字节相同）：`new()` 得 0，`moon->move(room)` 报错，婚礼停在拜堂之前。两处都改为 ruzhou 的路径。媒婆从拜堂到送入花轿的整个流程在测试里走通。


## 虚空房间不存在（2026-10-15）

`include/globals.h` 把 `VOID_OB` 定义为 `/clone/misc/void`，本库没有这个文件：副本（`adm/daemons/fubend`）、迷宫（`vrm_server`）、排行（`paiming_d`）、版本同步（`versiond`）等 26 个文件把人或物移进虚空时都报错。补上同系 hhsj 的 `clone/misc/void.lpc`（`init()` 只替非巫师存档，NPC 进去无影响）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

33 个文件、43 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/dali/npc/obj/zipao`、`/d/tls/obj/sengxie`、`/clone/armor/baihu-qiu.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 31 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`S_RING` → `/inherit/gems/ring`（11 个文件）、`F_GEMS` → `/feature/gems`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：15 个里 4 个通过，其余 11 个还有别的错误（`clone/gem/ring.lpc`：Fail to load object /clone/gem/ring.；`clone/gem/ring0.lpc`：Fail to load object /clone/gem/ring0.；`clone/gem/ring1.lpc`：Fail to load object /clone/gem/ring1.……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 63 个对象设了本库没有文件的武功（76 个名字，最多的是 `yijin-jing`、`qingyan-zhang`、`duanjia-jianfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 16 个通过，其余 14 个停在别的错误上（`d/moon/npc/makongqun`：*Inherited file '/obj/npc/npcd' does not exist!；`d/shiliang/quest/npc/wenfangda`：*No program in object '/d/shiliang/quest/npc/wenfangda'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/shenlong/jiutou1.43` 的 `west`：`jiutou1.44` → `jiutou1.23`；`/d/shenlong/jiutou11/jiutou1.43` 的 `west`：`jiutou1.44` → `jiutou1.23`；`/d/shenlong/jiutou22/jiutou1.43` 的 `west`：`jiutou1.44` → `jiutou1.23`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/sserver`（宏 `SSERVER`）←shenmo，4 个对象继承它，抽样 1/4 载入；`/feature/ridding`（宏 `F_RIDDING`）←tianxiawuxue，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 115 处、47 个文件：`yijin-jing`→`yijinjing`（34 处）、`yunu-xinjing`→`yunv-xinjing`（20 处）、`yunu-shenfa`→`yunv-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（7 处）、`shenzhao-jing`→`shenzhaojing`（6 处）、`mizong-huoquan`→`mizong-houquan`（5 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`paiyun-zhang`→`paiyunzhang`（4 处）等共 22 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## count_* 系列简单函数被条件编译挡掉（2026-10-19，KB 05 §7.15）

`adm/kernel/simul_efun/ntefun.lpc` 里的 `count_add/sub/mul/div/lt/gt/le/ge/eq` 整组被 `#ifdef __PACKAGE_ARITH_OPERATOR__` 包着，而且调用的是原版驱动才有的大数 efun `efun::count()`；这里两样都没有，整组函数编译不进 simul_efun，凡是调用它们的对象（`adm/daemons/gambled`、擂台鼓 `adm/npc/obj/drum3/4`、`adm/daemons/enterprised`、`quest/skybook/flagwar/flagd`）都报 `Undefined function count_lt` 载入不了。与 nitan6、nitan170911 的做法一致：去掉条件，包装函数改调 `db_compat.lpc` 里本地的 `count()`。同一批里 `quest/skybook/flagwar/flagd.lpc` 还照 nitan6 把 `ANSI_D->remove_ansi(...)`（本库没有 ANSI_D）改成 `remove_ansi(...)`，把 `reward_money *= 0.9` 改成 `to_int(reward_money * (0.9))`。

## 全局头文件丢了 4 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `BOOK_D(x)`、`CENTER_OB`、`EXIT_SIZE`、`EXIT(n)`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## kedian4 的 mapping ob（2026-10-19，KB 06 §7.266）

`d/city/kedian4.lpc` 的 `give_cigarette()` 把循环变量 `ob` 声明成了 `mapping`，却拿它当物件传给 `query("online_time", ob)`，驱动报 `Bad type for argument 2 of query ( object vs mapping )`，整个房间载入不了。改成 `object ob;`。

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/kernel/simul_efun/object.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 丢失的 ARMOR_D(x)、BINGQI_D(x)（2026-10-19，KB 04 §6.16）

`include/globals.h` 没有 `ARMOR_D(x)`（`("/clone/armor/" + x)`）和 `BINGQI_D(x)`（`("/clone/weapon/" + x)`），用它们的 NPC 报 `Undefined function ARMOR_D` / `BINGQI_D`，载入不了。照同一系 19 个库里相同的定义补上（`scripts/lpc_restore_defines.py`）。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：12 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## d/ailao/yuanjiang 的 59 个房间（2026-10-19，KB 04 §6.18）

`d/ailao/yuanjiang/` 下 59 个房间开头是 `inherit __DIR__ "normal.lpc";`，也就是 `d/ailao/yuanjiang/normal.lpc`，档案里没有这个文件（有的是上一级的 `d/ailao/normal.lpc`，是这个区域的房间基类，`ailao.lpc` 继承的就是它）。编译扫描看不到这一类（`inherit` 的文件载入时才读），房间载入时报 `Inherited file '/d/ailao/yuanjiang/normal.lpc' does not exist!`。改成 `inherit "/d/ailao/normal";`，62 个对象（这 59 个房间加上目录里本来能载入的 3 个）全部载入，逐个与 HEAD 对比没有退步；`chuan71` 到 `chuan79` 能编译之后才露出的未用局部变量 `usr` 一并删掉。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `maze/yanmen/npc/horse.lpc`：`inherit NPC; inherit F_RIDDING;`，NPC 一路带来 `feature/equip_liv.lpc` 的 `unequip(object ob, int ref status)`，`feature/ridding.lpc` 也有 `unequip()`（`unequip() inherited from both …`），驱动用了后继承的 ridding 那个；写出 `int unequip() { return ridding::unequip(); }`，行为不变（`scripts/lpc_name_winner.py`）。

逐个与 HEAD 对比载入，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/cmds/usr/heta.lpc`。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 补回标点后新载入的物件里的未使用局部变量（2026-10-19，KB 04 §6.10）

之前载入失败、补回丢失的标点后才载入的物件里还有未使用的局部变量警告，共 1 个文件：`/cmds/usr/heta.lpc`。删掉没有用到的声明；用 `scripts/lpc_listcheck.sh` 对比 HEAD 和改后，物件仍然载入，没有警告。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/adm/daemons/ward.lpc`（1 处）、`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）、`/kungfu/skill/daoyu/jiu.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）、`/inherit/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 30 处）。改动：`/adm/daemons/combatd.lpc`（5 处）、`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/intermud2_d.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/clone/game/mj.lpc`（3 处）、`/clone/game/mjlady3.lpc`（3 处）、`/clone/huoniao.lpc`（2 处）、`/cmds/wiz/roomlong.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/yaowang/huichun/npc/zhanggui.lpc`（1 处）、`/kungfu/class/misc/houwang.lpc`（2 处） 等 15 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/kernel/simul_efun/object.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/battlefieldd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/kernel/importer.lpc`（1 处）、`/cmds/adm/refsum.lpc`（5 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/cmds/arch/config.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## `mroom`（帮会房间生成）读不到 `dir_pre`（2026-10-21，KB 04 §6.16）

`cmds/bunch/mroom.lpc` 的 `valid_room_position()` 和建房流程用 `dir_pre` 当帮会目录前缀，库里没有任何头文件或变量声明它（`include/bunch.h` 只剩 `room_desc_l`、`max_exits`、`r_dir`、`vdirs`，整个语料里也没有 `dir_pre` 的定义），整个命令编译失败：`Undefined variable 'dir_pre'`。`adm/daemons/bunchd.lpc` 里 `BUNCH_HOME "/data/bunch/"`（`BUNCH_HOME + id + "/center.lpc"`，模板目录 `/d/room/bunch/` 复制到那里）和 `valid_room_position()` 的路径算术（前缀 `explode()` 三段、房间路径五段，差 2，返回第四段即帮会 id）对得上，所以在 `mroom.lpc` 里加 `#define dir_pre "/data/bunch/"`。nt6、nitan170911、nitan6、hhsj、xfbhh 的 `mroom.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：nt7（gitlink）同一文件；tianxia 的 `cmds/bangzhu/mroom.lpc` 用的是 `BANGHUI_DIR`，但那里的 `banghui_d` 自己就有类型错误和未声明的变量加载不了。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 2 个 NPC 文件写成空 `chat_msg`（例如 `/d/city/npc/lulixian.lpc`、`/maze/sand_dragon/npc/sand_dragon.lpc`），它们走的基类 `chat()` 本来已经检查了列表大小（或碰巧不出错），不受影响；下面这些文件各自带着一份没有检查的 `chat()`（NPC 里的副本、旧版基类），一并加上守卫。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/u/lonely/skybook/skybooknpc.lpc`、`/u/lonely/skybook14/skybooknpc.lpc`（共 2 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/look1.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 华山密室 `stage3()`：重新登录那段被注释掉，`obj` 没赋值（2026-10-21，KB 06 §7.348）

练成之后 `obj = LOGIN_D->make_body(link_ob); ... exec(link_ob, me); destruct(me); ...` 整段在注释里，下面的 `obj->move(place); obj->write_prompt(); set(.., obj); obj->save();` 还在：属性已经加完，抛错发生在“恢复气血、存盘”之前。xkx100 系的库里这段是启用的；这里补 `obj = me;`，下面几句直接作用在玩家本人身上。改动：`/d/huashan/mishi.lpc`。

## 追杀任务 `killer1.lpc`：奖励循环里的 `me` 从没赋值（2026-10-21，KB 06 §7.348）

黑衣人 `die()` 对每个在场的追杀者发经验和潜能，循环里写的是 `me->add("combat_exp", exp)`（nitan 系是 `addn("combat_exp", exp, me)`），`me` 要到循环之后才被 `find_player(owner)` 赋值：xkx100 系抛 `Bad argument 1 to call_other()`，nitan 系把奖励悄悄记到 0 上，追杀者什么也拿不到。循环里先 `me = obs[i];`。改动：`/clone/quest/killer1.lpc`。

## 混沌天的金灵巨兽 `die()`：全服通告读没赋值的 `ob`（2026-10-21，KB 06 §7.348）

通告“某某干掉了金灵巨兽”写的是 `ob->query("name")`，杀手是 `enemy`，`ob` 没赋值：在这一句里抛错，`::die(enemy)` 没有执行，怪物不死。改成 `enemy->query("name")`。改动：`/d/hunduntian/npc/u.lpc`、`/d/u.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）；张无忌：`destrory` → `destroy`。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`、`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 42 条注册（30 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/beichou.lpc`（`do_join`）、`/adm/npc/ganjiang.lpc`（`do_merge`）、`/adm/npc/jierishizhe.lpc`（`do_vendor_list`）、`/adm/npc/referee.lpc`（`do_halt`）、`/clone/3.lpc`（`do_name`）、`/clone/dan.lpc`（`do_name`）、`/clone/dan0.lpc`（`do_name`）、`/clone/dan2.lpc`（`do_name`）、`/clone/dan6.lpc`（`do_name`）、`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`） 等共 30 个文件。最多的函数名：`do_name` 6 处、`do_bcheck` 3 处、`do_bcun` 3 处、`do_bqu` 3 处、`do_tiao` 3 处。没有动（读过）：`/clone/lkj.lpc` 的 `do_flyto`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/lingyunku/npc/niefeng.lpc` 的 `do_show`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/jiuyin/zhou.lpc` 的 `do_answer`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/jiuyin/zhou.lpc` 的 `do_learn`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest/skybook/tlbb/murong-fu.lpc` 的 `do_lingwu`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/yixing/npc/bangzhu.lpc`（`do_xue`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。11 个文件里 13 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 11 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 10 个，现在 10 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 8 个函数没有补（other 4, inquiry 4）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/adm/daemons/intermud2_d.lpc`:`receive_support_answer`、`/adm/daemons/npcsd.lpc`:`exert_function`、`/adm/daemons/npcsd.lpc`:`perform_action`、`/d/yixing/npc/bangzhu.lpc`:`ask_skills`、`/inherit/banghui/smith.lpc`:`is_money`、`/quest/skybook/jiuyin/zhou.lpc`:`questions`、`/quest/skybook/kuihua/linzhennan.lpc`:`test_dart`、`/quest/skybook/tlbb/liao-huo.lpc`:`ask_for_join`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 3 个文件里有 4 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/log_user`、`nosave/ADJUST` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 3 个子目录写日志：`log/job`（`kungfu/class/quanzhen/beidou.h`）、`log/money`（`d/suzhou/npc/meipo.lpc`）、`log/test`（`d/baituo/npc/shenu.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/job`、`log/money`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 3 行只含这个指针的行（`"support_a": (: receive_support_answer :),` `"武功": (: ask_skills :),` `"skills": (: ask_skills :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 36 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 36 处（26 个文件）：拼名字的赋值 22 处、与汉字常量比较 13 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:136`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:41`）；`name[4..5]` → `name[2..2]`（`/kungfu/class/quanzhen/chu.h:80`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 全局头文件里的宏，`carry_object` 守卫以前看不见：41 处（2026-10-22，KB 06 §7.361）

`config.fluffos` 的 `global include file` 会被驱动塞进每个对象，文件里没有写 `#include` 也能用 `ARMOR_D("shoes")` / `BINGQI_D("langya-bang")` 这类宏；`lpc_guard_carry_object.py` 的宏表只读文件自己写出来的 `#include`，认不出它们，第 46 批 `--macro` 把这些行整个跳过了——NPC 在 `create()` 里 `carry_object(ARMOR_D("shoes"))->wear()`，文件不存在，`new()` 答 0，`->wear()` 抛 `Bad argument 1 to EFUN call_other()`，NPC 加载不了。宏表现在加上全局头文件；本库 41 处改成守卫块（缺文件就不穿，文件回来照旧穿）。证明（HEAD / 工作树加载对比，只含改过的 `.lpc`）：HEAD 加载失败的对象里有 13 个现在能加载，0 退步（quest11 的镖师、金蛇、九阴、葵花、天龙八部各路 NPC 等）。其余仍失败的文件失败在别的原因（`Unable to find the inherited function`、`Undefined variable 'RNAME_D'`），不属于这一类。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1770`）；`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/d/city/npc/petseller.lpc:184`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 9 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 1 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。
