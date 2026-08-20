
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云（古龙小说题材），管理密码+登录密码双密码注册流程。新发现的 bug，已收录进 AGENTS.md §7.60：master.lpc 的 log_error()——每一条普通的编译警告（不只是真正的错误）都会调用它——最后会呼叫 CHANNEL_D->do_channel(...)；如果 CHANNEL_D 这时候还没有被预载（取决于它在 adm/etc/preload 里排第几个），这次呼叫会在调用者自己还在编译的过程中，悄悄触发对 channeld.lpc 的一次新编译——这个驱动禁止这种嵌套编译，于是抛出"*Object cannot be loaded during compilation."，又被 log_error() 自己捕获并重新记录一次，如此循环，把一条本来毫无意义的 pragma 警告变成了几万行重复的错误堆栈输出。这个问题只存在于 CHANNEL_D 加载完成之前的启动窗口内（之后完全正常），但足以把真实输出淹没到没法看，因此还是修了：在广播前先判断 find_object(CHANNEL_D)。另外也修复了 is_chinese() 和 check_legal_name() 里经典的 §8.1 中文名字 bug（长度界限+字节步进循环，会静默拒绝所有真实中文名字）。排版格式化工具的第三类盲点检查在 12 个命中里抓到了两处真正的损坏（一份巫师培训测验文字档案和一份带有未转义尾随中文注释的代码速查表）——两处都已还原。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 13 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

管理员账号 `fluffos`/`Mud@2026`（管理密码 `AdminPw1`，与上面 WASM 摘要记录的
一致）在本仓库当前 checkout 里其实**没有**实际的存档数据（只有
`data/{login,user}/{a-z}/` 的空骨架目录被播种进 git，账号本身的 `.o` 存档
从未提交）——先用 `ls data/login/f data/user/f` 验证过，确认为空后，本轮
按 README 记录的凭证通过真实注册流程重新建立了一次（英文 id 沿用
`fluffos`，登录密码沿用 `Mud@2026`，管理密码沿用 `AdminPw1`）。

新手引导先读了 `doc/help/newbie.txt`：文档描述的注册流程（单一密码→确认→
email→性别→民族）已经**过时**，与当前 `logind.lpc` 实际代码不符——真实流程
是 README 记录的双密码版本（英文名→确认→中文名→管理密码→确认→普通密码→
确认→民族→性别，注册时**不问 email**）。`doc/help/newbie.txt` 关于
`apprentice`/`skills`/`learn`/战斗系统的说明与代码基本一致，仅密码段落已
过时，未改动帮助文档本身（内容维护，不在本轮范围）。

用真实中文名字 `云舒`（英文 id `ceshiwo`）走完整个注册流程：`look`/
`score`/`i` 在角色创建后、`register <email>`+`decide`（風雲用开封府门口的
神仙姐姐 NPC 做真人自助注册，不是 `cmds/arch/register.lpc`——那个指令需要
`(arch)` 权限，是给巫师手动帮别人登记用的，一般新玩家永远碰不到，房间牌子
上写的 `register your-email` 指的是神仙姐姐身上的本地 `register`/`decide`
动作）自助完成注册后，均正确响应、无崩溃。

战斗安全陪练机制：`cmds/std/fight.lpc` 读到确认，判断依据是
`obj->query("can_speak")`（不是 `civilized`）——`adm/daemons/race/human.lpc`
的 `create()` 无条件把人类设成 `can_speak=1`，`beast.lpc`/`monster.lpc`
两个种族档案都没有设这个属性，因此人形 NPC 走 `fight_ob()`/`fight_ob()`
双向切磋分支，兽类/妖魔走 `kill_ob()` 真杀分支——与本项目本轮反复确认的
"can_speak/civilized 二选一分流"模式一致，本档案用的是 `can_speak`。现场
用管理员账号对 `quest/kaifeng/npc/zhanzhao.lpc`（展昭，人类，`can_speak=1`）
分别测试了 `fight`（见下方"发现但判定为既有设计"关于死亡的记录）和真实的
可用 NPC 人数极少这一事实本身（见下）。

### 组织/门派技能获取：organic 与管理员捷径都验证了，但都撞上同一个内容缺口

- **organic 路径（`apprentice`）**：`cmds/skill/apprentice.lpc` 本身逻辑完
  整（`ob->query("family")` 判断对方是否已开山立派、`family/privs`==-1
  判断是否掌门），但全档案（`u/` 巫师个人目录除外）没有任何一个 NPC 设置了
  `"family"` 属性——`grep '"family"'` 全档案命中的都是读取/展示 `family` 的
  命令文件，没有任何 NPC 的 `create()` 真正 `set("family", ...)`。也就是说
  官方内容里没有一个可以拜师的门派掌门，`apprentice` 指令本身可用，但找不
  到合法目标——与 README 已经记录的"地图是骨架"是同一类内容缺口的延伸（不
  只是地图，门派体系本身在官方内容里也从未搭建），未改动代码。
- **管理员捷径**：`cmds/adm/setskill.lpc`（`(admin)` 权限）存在，可以直接
  `ob->set_skill(skill, level)`/`ob->delete_skill(skill)`，但没有任何单独
  的"授予门派"指令（`grep -rl '"family"' cmds/adm cmds/wiz cmds/arch` 零命
  中）。如实记录：技能有捷径，门派没有。

### 修复的程序性 bug

- **AGENTS.md §7.12 的又一个确认实例：`adm/simul_efun/message.lpc` 的
  `message()` 模拟函式对第 4 个参数（`exclude`）零校验直接转发给
  `efun::message()`，而这份驱动的 `message()` efun 要求第 4 参数必须是
  `object`/`array`，传 `int 0` 会抛 `*Bad argument 4 to EFUN
  message()`**：全档案有几十处调用点（`message
  ("system", str, me)`、`message("vision", ..., obj)`、
  `adm/daemons/channeld.lpc:474` 的频道广播等）沿用旧驱动"缺省参数静默补
  0"的写法只传 3 个参数，这份 `message()` 本身**没有** `varargs`，缺的参
  数按这份驱动的行为会被填成 `int 0`，然后原样转发给 `efun::message()`
  炸掉。**爆炸半径极大且会自我循环**：任何一次编译警告触发
  `master.lpc` 的 `log_error()`→`CHANNEL_D->do_channel()`→这个
  `message()`，报错本身又被当成新的一条编译期错误重新走一遍同样的路径，
  冷启动单次干净重启就能刷出 1500+ 行重复堆栈（比 §7.60 已经修过的嵌套编
  译问题更隐蔽，因为 §7.60 的 guard 已经生效但这个是一个完全独立的第二个
  循环源）；玩家侧最直接的后果是**每一次重新登录都会在 `enter_world()` 的
  `tell_room()` 广播处崩溃**（`obj/user#N` 的 `move()`→
  `tell_room(startroom, ..., ({user}))`→`message()`），并被
  `logind.lpc:check_ok()` 的外层 `catch()` 拦下显示"你无法进入这个世界，
  可能你的档案出了一些问题"——每个已注册玩家的每一次重新登录都会看到这条
  吓人的错误。修复：在 `message()` 里补一道类型校验，`exclude` 不是
  `object`/`array` 就强制改成 `({})` 再转发。现场复测：冷启动干净（0 处
  `Bad argument 4`），重新登录不再触发这条错误路径。
- **AGENTS.md §7.25 的又一个确认实例：`std/room/room.lpc` 的
  `make_inventory()` 对 `new(file)` 的返回值零校验**：`new()` 对一个不
  存在/已搬迁的路径静默返回 `0`（不抛错），随后
  `ob->set(...)`/`ob->move(...)` 对 `0` 呼叫 `call_other` 直接抛
  `*Bad argument 1 to EFUN call_other()`，而且这个未捕获的错误会从
  `reset()` 的物件生成迴圈里一路往外抛，**导致同一个房间"objects"清单里
  排在它后面的其它 NPC/物品全部被跳过、整个房间一次 reset() 全部作废**
  （现场用 `quest/kaifeng/zhengtang.lpc` 复现：清单第二项 `yayi` 路径写
  错——见下——导致清单第一项 `bao`（包拯）也从未真正摆进房间，`look` 只
  看到空房间）。修复两处：①`make_inventory()` 本身对 `new()` 返回 `0`
  的情况直接跳过（不再对空物件呼叫方法）；②`reset()` 迴圈里两处
  `make_inventory()` 调用都补上 `catch()`，让单个坏条目不再连累同一次
  reset() 里其它条目的生成。现场复测：`quest/kaifeng/zhengtang.lpc`
  reset 后 `look` 正确显示包拯，即使清单里第二项 `yayi` 因为下面记录的
  另一处独立内容缺口仍然创建失败，也不再拖累包拯。
- **`adm/simul_efun/object.lpc` 的 `unew()` 对 `new(str)` 返回值零校验**：
  和上一条同一种形状，`ob = new(str)` 之后立刻 `ob->query("unique")`，
  `str` 指向不存在的档案时 `ob` 是 `0`，直接抛 `*Bad argument 1 to EFUN
  call_other()`。`unew()` 是 `carry_object()`（几乎每一个 NPC 的
  `create()` 用来穿装备）的底层实现，任何 NPC 的任意一件"应该存在但其实
  不存在"的装备档案都会让该 NPC 的 `create()` 整个中断（后面的技能/
  金钱/inquiry 设定全部不执行）。修复：`ob` 为 `0` 时直接原样回传，不再
  继续 `query`。
- **`quest/kaifeng/zhengtang.lpc` 的 `"objects"` 清单里 `yayi` 的路径写
  死成 `/d/fy/npc/yayi`（本档案从未出货的 `d/fy` 地图树下），但真正的
  `yayi.lpc` 其实就在同一个 `quest/kaifeng/npc/` 目录下（挨着清单第一项
  `bao` 用的 `__DIR__ "npc/bao"`）**：明显是复制/搬迁时漏改的路径错字，
  已改成 `__DIR__ "npc/yayi"`（与清单里 `bao` 那一项写法保持一致）。改完
  后 `yayi` 能正确装载，但其 `create()` 自己又装备了两件 `/d/fy/npc/
  obj/` 下的兵器/护具（这部分才是真正的内容缺口，见下方"既有设计"一节，
  未改动）。
- **`quest/kaifeng/npc/zhanzhao.lpc` 的 `carry_object("/obj/cloth")`**：
  路径缺了档名，应该是 `/obj/cloth/cloth`（全档案其它每一处需要给 NPC
  穿基础布衣的地方——`obj/npc/garrison.lpc`、`bing.lpc`、`bingtou.lpc`、
  `danei.lpc`、`logind.lpc` 的新角色初始化——全部用的是 `/obj/cloth/
  cloth`，只有这一处写漏了）。`/obj/cloth` 本身是目录不是物件档案，
  `new("/obj/cloth")` 返回 `0`，接上面 `unew()` 修复后不再崩溃，但穿戴
  会静默失败；已改成正确路径 `/obj/cloth/cloth`。
- **`feature/skill.lpc` 的 `set_skill()`/`map_skill()`/`improve_skill()`/
  `decrease_skill()`/`research_skill()` 五处 `error("F_SKILL: No such
  skill (...)")` ——本档案（`u/` 巫师个人目录除外）从未出货 `/daemon/
  skill/` 目录下的任何技能档案（`unarmed`/`dodge`/`parry`/`force`/
  `literate`/... 全部缺失，已用 `ls /daemon/skill`（管理员实测"没有这个
  目录"）和 `find -iname unarmed*` 等交叉确认过不是 AGENTS.md §7.5 那种
  ACL false-negative，是货真价实的内容缺口）。技能档案缺失本身不在本轮
  修复范围（补上 100+ 个技能档案属于游戏内容创作），但 `error()` 直接
  中断调用者整个函式这件事本身是可以修的：`set_skill()` 抛出时会让呼叫
  它的 NPC `create()` 从那一行整个中断，后面所有还没执行到的技能/装备/
  `setup()`/金钱/`inquiry` 全部不会执行（现场复现：`quest/kaifeng/npc/
  bao.lpc` 的 `set_skill("dodge", ...)` 是 `create()` 里第一条技能呼叫，
  炸了以后包拯连衣服/钱/任务对话都没有）；如果这次 reset() 又是从
  `make_inventory()` 里发生的，还会连累同一房间后续物品（即上面已修的
  第二条 bug）。五处全部改成：目标技能不存在时写一条日志
  （`/log/nosave/missing_skill`）然后直接跳过这一项，不再中断调用者。
  现场复测：`bao`/`yayi`/`zhanzhao` 全部能正常摆出装备、`setskill`
  管理员指令能正常执行完（虽然因为技能档案本身缺失，实际不会真的写入
  `skills` 映射——如实告知管理员这一点在指令输出里不会体现，`setskill`
  自己的 "setting-> ..." 提示不检查返回值，永远显示"成功"，这是既有的
  UI 诚实度问题，未改动）。
- **新收录进 AGENTS.md §7.96：`adm/daemons/logind.lpc:enter_world()` 依赖
  `catch(load_object(...))` 判断房间是否存在，但这份驱动的
  `load_object()` 对不存在的档案不抛错、只是静默返回 `0`，导致这段"起始
  房间不存在就退回 START_ROOM"的容错逻辑
  从来没真正生效过**：`START_ROOM`（`/d/fy/church`）本身就是本档案从未
  出货的地图（同一个已知内容缺口），玩家自助注册（`decide`）后
  `startroom` 被设成这个不存在的常量，下一次登录 `catch(load_object
  (startroom))` 因为不抛错而误判"成功"，接着 `user->move(startroom)`
  对不存在的房间呼叫 `call_other`，未捕获，被 `check_ok()` 外层
  `catch()` 拦下显示"你无法进入这个世界"——**每一个完成过自助注册的玩家，
  之后每一次登录都会看到这条错误**，本质是上面 `message()` bug 修好之
  后暴露出的下一层问题（两者会先后触发，`message()` 没修之前这条甚至看
  不清）。改用 `file_size(startroom + ".lpc") < 0` 直接判断是否存在（不
  再依赖 `load_object()` 的抛错语义），如果连 `START_ROOM` 自己也不存在
  则再退一步落地到 `REGISTER_ROOM`（`/adm/etc/register`，本档案确实出货
  了）。现场复测：`ceshiwo`/`fluffos` 两个已注册角色重新登录都不再报错，
  正确落地世外桃源。
- **`feature/damage.lpc:die()` 同一形状：死亡后 `move(DEATH_ROOM)`
  （`/d/death/gate`，同样是从未出货的地图）未捕获**，导致死后的幽灵化
  状态（`ghost=1`、`gin`/`kee`/`sen` 清零、`save()`）已经落盘，但角色
  卡在死亡时所在的房间、且 `DEATH_ROOM->start_death()` 的复活流程初始化
  完全没跑到。现场用管理员角色故意输给展昭复现（见下方陪练分流的死亡记
  录），确认崩溃点。修复：`file_size` 判断 `DEATH_ROOM`/`DEATH_ROOM_NO_PEN`
  是否存在，不存在则退回 `REGISTER_ROOM`。现场复测：死亡后正确移动到
  世外桃源（不再崩溃卡死在原地），复活/幽灵状态其余逻辑未改动。
- **`adm/daemons/channeld.lpc:do_channel()` 假设呼叫者 `me` 一定是有
  `name()` 的角色物件，但 `adm/daemons/combatd.lpc:victim_penalty()`
  用 `this_object()`（也就是 combatd 这个 daemon 自己）当发言者广播死亡
  谣言**：daemon 没有 `name()`，`call_other` 静默返回 `0`（不是字串），
  `who = 0` 之后 `who == me->name(1)`（同样是 `0`）判断为真，进入
  `who += ...` 分支时因为 `who` 是数字类型直接抛 `*Left hand side of +=
  is a number`，导致这条死亡广播（连带 `victim_penalty()` 后续所有death
  penalty 逻辑）在 `heart_beat()` 里未捕获地中断。现场复现：管理员角色
  被展昭打死后触发。修复：`who` 取到非字串时退回通用的 "系统" 标签，不
  再让 `who += ...` 对数字做字串拼接。现场复测：死亡广播和后续 penalty
  逻辑正常跑完，不再报错。
- **`adm/daemons/logind.lpc::get_name()` 里一处遗留的 `printf("%O\n",
  ob)`**（AGENTS.md §7.34 常见形状的又一实例）：中文名字确认成功后立刻
  把整个 login 物件的原始表示（`/obj/user/login#0 ("0(ceshiwo)")` 这种）
  直接印给正在注册的新玩家看。已删除，不影响后续逻辑。
- **`config.fluffos` 的 `maximum evaluation cost : 700000`（AGENTS.md
  §7.90 项目模板默认值）**：冷启动首次因编译警告堆栈过深时命中
  `Eval interrupted: ... cost limit reached, limit: 700000 usec`，
  已提到 `5000000`（本项目 30+ 个库的常用值）。
- **`adm/simul_efun/file.lpc:log_file()` 缺 `assure_file()` 导向导致
  `/log/` 目录不存在时崩溃（AGENTS.md §7.11 标准形状）**：新checkout没
  有预先 `mkdir` 出 `log/` 目录时，`master.lpc:log_error()` 里
  `efun::write_file(home + "log", message)` 直接抛 `*Wrong permissions
  for opening file /log/log for append. "No such file or directory"`，
  同一份 `log_error()` 里紧接着的 `CHANNEL_D->do_channel()` 广播（在
  §7.60 已修的 guard 保护下不会再嵌套编译，但仍然会把这条错误继续往外
  传递）。修复：`log_file()` 简单模拟函式补 `assure_file()` 导向；
  `master.lpc:log_error()` 自己直接呼叫 `efun::write_file()`（绕过
  simul_efun），单独补一次 `assure_file()`。现场复测：冷启动 0 处
  `Wrong permissions`。

### 发现但判定为既有设计、未改动的现象

- **地图/装备/门派/技能内容大面积缺失，是同一份"骨架存档"问题的不同表
  现**：官方"/d/fy"地图树整体不存在（README 已记录）；`/d/wiz`（巫师新
  闻板挂载点）、`/d/death`（死亡/复活房间）同样不存在；`/daemon/skill/`
  下没有任何技能档案；官方 NPC 里没有一个设置了 `"family"` 门派归属。这
  些全部是内容缺口，不是程序逻辑缺陷，本轮只修复了"缺失内容不应该让呼叫
  者整个崩溃/中断"这一层健壮性问题（见上），没有也不打算补全任何实际的
  房间/装备/技能/门派内容。
- **`fight`（"安全"陪练）在极端实力差距下仍然可能一击致死，与帮助文档
  "点到为止，不会真的受伤"的承诺不完全一致**：`adm/daemons/combatd.lpc`
  对 `victim->receive_damage("kee", damage, me)` 的呼叫在 `fight`/`kill`
  两种模式下完全一样（唯一的区别是 `kill` 模式会额外叠加
  `receive_wound()` 造成的永久创伤），而 `std/char/char.lpc:heart_beat()`
  的死亡判定里，`kee`（不需要真的伤到 `eff_kee`）单独跌破 `-10 * dur`
  就会直接死亡，不会先进入"昏迷"缓冲状态。现场用一个全新零基础的管理员
  角色（对空手战力接近 0）对 `quest/kaifeng/npc/zhanzhao.lpc`（`combat_
  exp` 1200万，装备夺命剑）连续测试两次，两次都是单招直接从满血打到
  "你死了"，全程没有经过"你想要逃跑"式的昏迷/求饶缓冲。鉴于：①这属于战
  斗数值平衡/伤害公式的设计范畴，不是崩溃/静默失败/逻辑颠倒；②不清楚原
  作者是否本来就设计成"实力差距过大的陪练仍有一击猝死风险"（帮助文档没
  有明确排除这种情况，只是没提到）；③修改伤害封顶/血量下限属于会改变战
  斗数值体验的设计决策——未改动代码，如实记录在此，供后续如果要专门核实
  伤害公式时参考。
- **管理员/普通玩家的角色重连都会先落回世外桃源**：`quit`/断线重连都没
  有恢复"上次所在房间"的逻辑（`enter_world()` 本身就是按
  `registered`/`startroom` 状态重新计算落地点，不是靠断线前记忆位置）；
  已注册但 `startroom` 指向不存在地图的角色会被上面已修的容错逻辑统一送
  回世外桃源。神仙姐姐的 `greeting()` 对非巫师角色只要出现在世外桃源就
  会直接丢进空洞（`VOID_OB`）——这是这份代码自己的既有设计（"已经注册的
  普通玩家不该待在这个欢迎房间"），不是本轮改动引入的。
- **`register`（`cmds/arch/register.lpc`）只有 `(arch)` 权限能用，与房
  间牌子上呼吁新玩家"register your-email"的字面指令名字撞车**：实测确
  认新玩家真正走的是神仙姐姐 NPC 本地挂载的 `register`/`decide` 两个
  动作（`add_action`），不是这个巫师专用的全局指令；两者恰好同名但是完
  全独立的两套实现，不冲突（driver 优先解析房间/NPC 的本地 `add_action`，
  全局 `cmds/arch/` 指令要显式 `(arch)` 权限才会被列入候选，新玩家权限
  下 `SECURITY_D->valid_grant(me, "(arch)")` 恒为假，指令直接不可见）。
  如实记录，未改动，帮助文字/牌子描述与实际机制一致（只是描述得不够精确，
  容易让人误以为是同一个指令）。

### 未验证事项

- **WASM**：driver 编译工具链需要访问 `storage.googleapis.com`（被代理拒
  绝），本轮未验证 WASM 下的行为，只在原生 driver 上完成全部测试。
- 门派/技能内容缺口意味着"角色成长"这条主线（学武功、拜师、参数点分配到
  实战技能上）在当前存档状态下事实上不可玩；已在上面如实记录，供后续如
  果要专门"填内容"时参考起点。

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
extensive round-one writeup above. All 10+ round-one fixes confirmed
still present (code inspection for all, live re-exercise of the
highest-value ones — the §7.12 `message()` type check and the §7.96
`START_ROOM` fallback, both exercised on literally the first login).
Found and fixed one small remaining gap this round's own checklist
covers that round one's pass didn't touch.

### New fix: `adm/simul_efun/file.lpc`'s `cat()` still had no null-guard

Round one already fixed `log_file()`'s `assure_file()` gap (§7.11) but
missed `cat()`'s separate null-guard need. One-line fix:
`write(read_file(file) || "");`.

### Re-verified live: the two highest-value round-one fixes

- **§7.12 `message()` 4th-arg type check**: first admin login this pass
  completed with zero `Bad argument 4` errors (the original bug made
  EVERY login crash at `enter_world()`'s `tell_room()` broadcast).
- **§7.96 `START_ROOM`-doesn't-exist fallback**: landed cleanly at
  `世外桃源`/`REGISTER_ROOM` on login, exactly the fallback the fix
  produces (`START_ROOM` genuinely doesn't exist in this archive, a
  documented content gap, not something to fabricate).
- **§7.25 `make_inventory()` isolation fix**: `goto
  /quest/kaifeng/zhengtang` (admin teleport, since `/d/fy` doesn't exist
  for organic navigation) reproduced `yayi.lpc`'s own `create()` still
  throwing repeatedly (`*Bad argument 1 to EFUN call_other()`) — this is
  the ALREADY-DOCUMENTED, deliberately-unfixed content gap (yayi's own
  equipment references `/d/fy/npc/obj/...`, which doesn't exist).
  Critically, despite yayi's own failure, the room and 包拯/Bao daren
  both loaded and displayed correctly — confirming the isolation fix
  (one broken NPC doesn't take down the room or its siblings) still
  holds exactly as designed.
- **Other fixes** (`unew()` guard, the `yayi` path fix itself, the
  `zhanzhao` cloth-path fix, the 5 `feature/skill.lpc` error→log-and-skip
  sites, `channeld.lpc`'s non-string-speaker guard, the printf leak
  removal, the §7.90 eval-cost bump): all code-confirmed present via
  direct grep, not independently re-triggered live this pass given the
  time budget — round one's own writeup already live-verified each of
  these individually and in detail.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`) —
clean on the first attempt. `update /adm/daemons/logind` as the real
privileged-action check (succeeded). `goto /quest/kaifeng/zhengtang` as
a targeted re-exercise of the make_inventory isolation fix. Two full
rapid reconnects, both clean. `work/log/debug.log` grepped for the
original error signatures (`Bad argument 4`, `Wrong permissions`,
`F_SKILL`) after the whole session — zero hits; all new log growth was
either harmless compile warnings or the already-documented `yayi`
content-gap trace. Driver killed by exact PID after testing; incidental
`fluffos.o` save-timestamp churn reverted before commit.

### Files modified this pass

- `work/adm/simul_efun/file.lpc` — `cat()` null-guard.

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 40 live
`replace_program(ROOM);` occurrences across 31 files: 26 standalone
room-file/heredoc-template lines (real `.lpc` room files,
`data/group/groom/*.lpc`, `feature/up.lpc`,
`quest/kaifeng/qianyafang.lpc`) plus 14 string-builder-embedded
occurrences (literal `\n  replace_program(ROOM);\n` escape sequences
inside generated-code strings) across `data/group/obj/ling.lpc`,
`data/group/obj/ling-pai.lpc`, a garbled-filename duplicate/backup of
`ling.lpc` under `data/group/obj/`, and this lib's own room-building
tools `u/island/obj/roommaker.lpc`/`u/island/obj/roommaker1.lpc` (two
copies, both fixed — so newly-built rooms were inheriting the bug too).
A full post-fix grep confirms 0 live occurrences remain. Verified via a
clean native driver boot (zero new `debug.log` errors, port listening,
killed by exact PID after ~8s).

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
