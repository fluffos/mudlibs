# yhwhckdm（炎黄武魂参考代码）-- porting notes

原档只有 `d/`、`kungfu/`、`clone/` 三棵树，没有 master，原先标 `not-convertible`。发布说明（薪有所属，2017-03-03）写明这是当时炎黄武魂的参考代码，方便规划 id。

按用户指示接到已转换的 `yanhuangwuhun` 骨架上：

1. `rsync` `libs/yanhuangwuhun/work/` → `libs/yhwhckdm/work/`。
2. `convert_lib.sh` 转好的参考树覆盖 `clone/`、`d/`、`kungfu/`（already_utf8=61 converted=10123 lossy=1）。
3. 引擎仍是 yh 2003 的 `/adm/single/master`。

端口 **40321**（原 40270；§10.7 改到空闲段）。注册流程与 `yanhuangwuhun` 相同（`washto` / `born`）。
骨架带过来的管理员 `fluffos`/`Mud@2026` 可直接登录，落地扬州客店
`/d/city/kedian`（参考树覆盖了原炎黄的世外桃源起点）。`look`/`quit` 正常。

## 商店 + 拜师（2026-09-04 librarian shop slice）

新角度：扬州醉仙楼付费购买。进口笔记只写了骨架落地。参考树覆盖
了 `d/`，但醉仙楼 `/d/city/zuixianlou` 和黎生路径与
`yanhuangwuhun` 2026-09-03 相同。管理员存档从骨架带过来时已经是
丐帮第二十代 / 师父黎生，本轮不再重拜。

本轮没有新的 programming bug。`goto` / `clone` / `MESSAGE_D` 的
`to_int` 和 `log_file assure_file` 已在骨架里。`log directory :
/log` 仍是绝对路径，本机 `debug.log` 不打开。

### 实测过程

`fluffos` / `Mud@2026`，第一输入是英文 id。落地扬州客店
`/d/city/kedian`（北丑、戚长发、店小二在场）。`score`：「丐帮第二
十代传人 浮浮」「师父是黎生」。`goto /d/city/zuixianlou`，店小二
`list` 烤鸡腿八十文。`clone /clone/money/gold`「黄金复制成功」。
`buy jitui`：「你从店小二那里买下了一根烤鸡腿。」`i` 一两黄金 +
九十八两白银 + 四十文铜钱 + 烤鸡腿。`quit` 后再登：门派、黎生、
银钱都在；烤鸡腿是食物，不进档（手足 yh 已知）。

管理员存档未提交。

## WASM (2026-09-11 leftover 652)

`wasm_client.js`：`fluffos` / `Mud@2026` → 扬州客店 `/d/city/kedian`
（戚长发、北丑、店小二），`look` 同文，`score`「丐帮第二十代传人
浮浮」，`quit`「欢迎下次再来」。`wasm_status` 改为 `playable`。

## 深度功能测试（§10.7，2026-09-13）

原生 driver 端口 **40321**（原笔记 40270；本轮改到 §10.7 惯用
40320–40380 空闲段），`fluffos` / `Mud@2026`。从 slug 目录启动：
`~/src/fluffos/build-debug/src/driver config.fluffos`，stdout →
`/tmp/yhwh-driver.out`。slug `libs/yhwhckdm/log/debug.log` 与 mudlib
`work/log/log`（`master->log_error()`）都按本轮 mtime 查了；`call`/
`clone` 审计还写了 `work/log/static/{call_player,clone}`。

这是 **yanhuangwuhun 骨架 + 炎黄武魂参考代码叠层**：引擎仍是 yh
2003 master，`d/`/`clone/`/`kungfu/` 被参考树覆盖。`help newbie` 仍
写桃源起步，实际落地是参考树的扬州客店——文档与地图不一致是嫁接
事实，不是本轮新洞。

### 游玩证据

- 登录落地扬州客店 `/d/city/kedian`（戚长发、北丑、店小二）；
  `score`「【 小叫花 】丐帮第二十代传人 浮浮 / 师父是黎生」。
- 商店：`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文；
  `clone /clone/money/gold` 后 `buy jitui` →
  「你从店小二那里买下了一根烤鸡腿。」`i`：1 金 + 98 银 + 40 铜 +
  烤鸡腿。
- 门派点：`goto /d/gaibang/inhole`，黎生在场；本号已是弟子，未重拜。
- 任务：`quest` →「你现在没有领任何任务！」；`job`/`jobs`/`task`
  均「什么？」。环境里任务精灵仍在 ambient 创建
  （SUPPLY/DELIVER/SHEN 等日志），玩家侧无已领任务。
- 战斗：`goto /d/city/guangchang`，`clone /clone/npc/mu-ren`；新手
  `fight mu ren` 被拒「这点身手还不足以和木人练功」（木人门槛，
  设计如此）。巫师 `call` 把 unarmed/dodge/parry 提到 50、
  `combat_exp` 5 万后，`fight mu ren` 互出拳脚，`halt` 干净跳出。
- `quit`「欢迎下次再来」；重连后门派/师父/银钱仍在。烤鸡腿未随档
  （食物常见 `no_save`，与手足 `yanhuangwuhun` 相同）。

### 日志

本轮 boot + 游玩：slug `debug.log` **无** `执行时段错误` /
`Bad argument` / `Too long evaluation`。`work/log/log` 本轮增量主要是
preload/`shopd`/`quit` 的 unused-variable 警告，无同形功能缺口。

### 未改 / 剩余缺口

- 管理员运行时存档未提交。
- 嫁接上限：`help newbie` 桃源文案与参考树扬州起点不一致；玩家
  `quest` 空、无 `job` 指令（任务精灵 ambient 自转不等于可玩任务线）。
- 端口配置已改为 40321（本轮空闲优先），未改回 40270。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/swear.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py yhwhckdm --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 458 个 `.lpc` 和 12 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：454 -> 454 通过，无回退；改过的头文件的 22 个包含者 21 -> 21 通过。启动时警告 2 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `adm/daemons/huanjing2003/room_master_hj.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：adm/daemons/combatd2.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-12）

`scripts/lpc_twin_port.py adopt yanhuangwuhun yhwhckdm` 搬来 yanhuangwuhun 同日整理（89552da089f）里与本库逐 token 相同的文件，能编译的文件警告清零；改动的对象在 HEAD 与工作树各载入一次，regress 0。

- `adm/daemons/huanjing2003/` 四国 NPC/宝物与 `room_readygo_hj.lpc`：同一条声明里先裸声明再带初值声明的变量去掉裸的那份。
- `feature/food.lpc`、`feature/liquid.lpc` 的 `do_effect()` 改 `varargs int`，与重载它、被 `eat`/`drink` 用返回值的物品同型；`adm/daemons/network/cmwhod.lpc` 的 `nosave` 函数改 `protected`；`adm/daemons/vrm_server.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`dacidabei-shou`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`）；`taiji-shengon`→`taiji-shengong`（`taiji-shengong`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`jiujin-shengong`→`jiuyin-shengong`（`jiuyin-shengong/perform/zhang`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 回龙杖「神龙摆尾」从来用不出（2026-10-15，KB 06 §7.246）

`if (!objectp(me->query_temp("weapon") || weapon->query("skill_type") != "staff"))`：括号放错，`objectp()` 包住了整个 `||`，拿着兵器时 `objectp(1)` 为假，永远“双手应该持杖”；空手时又去读从未赋值的 `weapon`，报错。改为先存兵器再判断。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 16 处、10 个文件：`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenhuo-shengong`→`shenghuo-shengong`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`yan-fly`→`yanfly`（1 处）、`zhoangnan-zhi`→`zhongnan-zhi`（1 处）、`jinwu-goufan`→`jinwu-goufa`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/corpse_poison.lpc`、`/kungfu/condition/fire_poison.lpc`、`/kungfu/condition/freezing.lpc`、`/kungfu/condition/freezingbc.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/medicine/pill`←zhyx：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/obj/bowl.lpc`（cctx）、`/kungfu/skill/kuihua-mogong/perform/wswd.lpc`（yanhuangwuhun）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/d/mingjiao/shanmen.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）。
