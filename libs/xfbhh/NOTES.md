
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
