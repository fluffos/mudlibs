
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
