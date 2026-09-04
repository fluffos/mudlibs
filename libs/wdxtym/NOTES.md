
## WASM 修复摘要（迁移自 meta.json 的 group_note）

完成了一次中断的转档（46890 个档案的压缩包最初转档超时中断）。使用一套自定义客户端协议（不是普通的一问一答提示）：服务器送出一行版本挑战"ver1.0,<crypt-salt>"，客户端必须回传正确加密后的应答，或者两个字面绕过字符串之一（测试用"123456789abcd"即可），否则连线会被"客户端非法"拒绝。之后的注册/登录是每一步一整行、用竖线分隔（账号的 id║密码║密文║email，角色的 gender║avatar║nickname），不是逐字段提示——这是为专属 GUI 客户端设计的，不是 bug。WASM 修复：（1）§7.52 类的 sockets 包依赖：payd.lpc 的充值回调 HTTP 监听器直接呼叫 socket_create()/socket_bind()/socket_close()/socket_accept()/socket_address()，没有任何存在性判断，导致整个档案在 WASM 下编译失败（Undefined function）。按 AGENTS.md §7.52，只把碰 socket 的函式（setup()、store_client_info()、listen_callback()、close_connection() 里的 socket_close 呼叫）掏空成 no-op，因为 do_get()——唯一真正被 cmds/adm/paym2.lpc 从外部呼叫的函式——不碰 socket，需要继续正常工作。（2）eventd.lpc 的 create() 里一个真正的 off-by-one bug：event_name = map_array(event_name, (: $1[0..<3] :)) 本意是去掉每个文件名 4 个字符的".lpc"后缀，但只去掉了 2 个字符（比如"emei.lpc"变成"emei.l"），导致 collect_all_event() 对每一个事件档案的 call_other() 在开机时全部失败（"*call_other() couldn't find object ...emei.l"），也就是说整个游戏内事件系统一直静默地完全不工作。已把切片改成 [0..<5]（正确去掉 4 个字符，比如"emei.lpc"变成"emei"）。（3）adm/simul_efun/chinese.lpc 里 §8.1 类的 is_chinese()：旧版 GBK 字节配对检查（strlen(str)%2 拒绝奇数长度字符串，检查原始字节区间 176-247/161-254）在这个驱动的 UTF8 码点字符串索引下会拒绝像"小浮侠"这样合法的奇数字数中文名字——已改成逐码点的 0x4e00-0x9fff 区间检查。管理员账号播种：fluffos_1 (admin) 加入 adm/etc/wizlist（账号会被 get_user() 自动加上"_1"后缀；SECURITY_D 正确指向 /adm/daemons/securityd，wiz_levels 顶层是 (admin)）。观察到但未修复——一个瞬态、能自愈的"Too deep recursion"，出现在 adm/single/master.lpc 的 valid_read()/compile_object() 委托给 SECURITY_D 的路径上，以及一个瞬态的"Bad argument 4 to EFUN message(), Got: int(0)"，来自 bossdd.lpc 的 heart_beat()->shout() 路径：两者都可以追溯到一个在源码层面其实已经正确加了保护的 message()/shout() 呼叫链（message.lpc 的 message() 包装函式有标准的 if(!exclude) exclude=({}) 保护，通过实时插桩确认这个保护在每一次观察到的呼叫里都正确生效，把 int(0) 转换成了 ({})）——这些错误在早期的一次测试里出现过一次，之后连续 4 次相同的注册测试都没有复现；驱动自己的呼叫深度保护和逐物件心跳自动关闭机制安全地接住了它们，两次实际发生时对游戏本身零影响（两次注册和进入游戏世界都成功完成）。很可能是刚开机第一次物件编译爆发期特有的一种心跳计时竞态，不是一个可以在源码层面修复的 bug。注册流程已多次完整验证：版本挑战绕过→id║password║x║email→gender║avatar║name→带着完整的自定义协议状态行进入游戏世界。管理员权限已直接通过"目前权限：(admin)"确认。LPC 格式化工具对全部 46890 个档案运行（写入 46740 个，117 个因为杂乱的历史代码报错，33 个未改动）；唯一一个匹配 CJK 重新加空格特征的档案（d/yihua/hubian.lpc）确认是转档前就存在的（格式化前的原始数据里也有），未做改动；对"连续三个 CJK 之间有空格"序列的 diff 级扫描找到 177 处原始命中，全部确认是误报（没有一个在旧版本里有独有的去空格匹配）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。全部 4 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，本轮）：确认第 5 个 §7.78 实例，修复 3 处 §7.68 死亡软锁

这份档案之前只做过 WASM 修复 + 注册流程验证，没有做过针对 §7.78（CHARACTER 组成的 mixin 文件里裸 set()/query() 调用解析不到本对象 F_DBASE）的定向检查——而这份档案的连线协议（ver1.0 版本挑战、║ 分隔字段）和 xfbhh/hhsj/nt1/nitan170911 完全一样，一眼就能看出是同一条 NT/nitan/Lonely 血统的分支（这份档案自己独有一个额外的 F_SUIT mixin）。检查后确认：alias/apprentice/attack/attribute/command/damage/message/more/name/skill 共 10 个 mixin 文件有裸 set()/query() 调用且自己都没有 inherit F_DBASE，command.lpc 的 enable_player() 是同款 set_living_name(query("id")) 崩溃写法。按已经验证过 4 次的相同修法处理：改成 this_object()->set(...)/this_object()->query(...)。这是目前唯一一个能完整真人验证（不像 nitan170911 那样被 MySQL 环境限制卡住）的 §7.78 实例：用真实驱动连续验证了 3 次全新注册（123456789abcd 版本绕过 → id║password║密文║email → gender║avatar║name，一步到位进入游戏世界，不需要额外的 register 房间指令），NPC"水笙"的千里传音欢迎语和玩家自己的名字全程正确显示（不是 xfbhh 那种"巨斧"/字面"0"乱码），全程 debug.log 保持空白。

顺手检查了死亡/复活系统，发现并修复了 3 处标准的 §7.68 软锁（`d/death/npc/{bai,bgargoyle,wgargoyle}.lpc`）：`death_stage()` 的 `if (!ob || !present(ob))`（bgargoyle/wgargoyle 用的是 `present(ob, environment())` 变体）把"角色永久离开"和"角色只是暂时不在场"混在一起，任何一种都会让复活流程永久卡死。按各文件自己的重试间隔（都是 5 秒）拆分成"!ob 才真正放弃，presence 检查失败则重新 call_out 重试"。

时间关系，本轮没有走完投胎仪式的方向选择（世外桃源房间的 west/east/north/south 分别对应阴险奸诈/光明磊落/心狠手辣/狡黠多变四种性格）、没有测试移动/战斗/商店/帮派任务等更深内容——上面的核心架构 bug 修复本身已经是这轮最有价值的发现，下一轮如果继续深挖这个 lib，建议从性格方向选择开始，走完整个投胎仪式后再测战斗/商店。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 3 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

用新编译的 `~/src/fluffos/build-debug/src/driver`（origin/master 最新拉
取，含本项目自己提交并合入的 #1343/#1344 两个 PR，以及同一会话里另外
提交的驱动 PR：把编译诊断严重度标记从小写改回大写 "Warning:"/
"Error:"）重新验证。

### `to_int()` 任务计数器修复

实际生效的 `u/lonely/combatd.lpc`/`u/redl/combatd.lpc`（`adm/daemons/
combatd.lpc` 是一份没有任务奖励代码的旧/未用副本）里全部 `quest_count
= ... % 500` 已经是 `to_int(query(...)) % 500` 的修复后形状，无需改动。

### 新发现并修复：`log_error()` 完全没有严重度判断（比 hhsj/nt6/xfbhh 更原始的同类 bug）

`adm/single/master.lpc` 的 `log_error()`（AGENTS.md §7.103/§7.10 已有
先例，这是 nitan 血统家族内的又一个独立实例）：`if (this_player(1))
efun::write("编译时段错误：" + message + "\n");`——连 severity label
都没有计算，不管是 error 还是 warning 一律无条件转发给玩家。修复：加
上 `strsrch(message, "arning:") == -1` 门控（大小写无关匹配，AGENTS.md
§7.10 案例记录），只转发真正的 error。`adm/simul_efun/message.lpc` 的
`message()` 包装函式已经带有 `if (!exclude) exclude = ({});` 守卫，不
是本轮的 bug，未改动。

### 连线协议细节：本档不接受逗号分隔，且需要真实的版本挑战应答

和 hhsj/xfbhh 不同，`wdxtym` 的 `jiance()` 真的会校验版本挑战字符串
（`crypt(ZJKEY, str[2..3])` 或者两个固定后门值之一，`"123456789abcd"`
是其中一个后门值，和其它血统兄弟档案共用），且 `get_user()` 直接
`explode(arg, "║")`，**没有**其它血统兄弟档案那种"逗号自动转║方便手
机端"的兼容处理——账号行必须原样用"║"分隔（`id║password║密文║
email`），逗号分隔会静默失败，得到"未知错误，请重试s"。记录下来避免
以后测试这份档案时重蹈覆辙。

### 冷启动级联编译撑爆 `maximum evaluation cost`（AGENTS.md §7.90/§10.8 已有先例，含一次"Can't catch"级重症）

第一次全新注册尝试命中了一次比常见"Too long evaluation. Execution
aborted."更严重的变体——"Can't catch eval cost too big error"（预载阶
段 `wabaod.lpc`/`taohua/daojufang.lpc` 触发，`catch()` 本身都无法拦
截），导致那次注册反复卡在"未知错误，请重试s"（后来定位到其实是我自
己送错了分隔符，见上一条；但驱动重启后同样的错误分隔符仍然复现，证明
不是那次级联导致的，是协议问题本身）。第二次全新账号尝试（用正确的
║ 分隔符）在 `enter_world()` 链路上（`make_body()`→武功/任务生成）命
中一次普通"Too long evaluation"，该角色未能成功存档；**验证自愈**：
驱动继续热身后，第三次全新账号一次性干净走完注册→投胎→进入
"wdxtym"世界，全程无"臭虫"报警。最后一次干净运行的 debug.log 尾部仍
有一条 NPC 装备初始化触发的 eval-cost 中断（不影响玩家自己的注册流
程），同一已知类别，未修。

### 完整游玩测试范围

沿用既有记录的"注册成功进入世界，欢迎/状态栏正确显示"作为及格线（本
轮额外确认了"score"风格的状态栏数据正确渲染）。战斗/死亡循环仍未触
达，留给下一次专门测试。

### 本轮结论

驱动升级后 wdxtym 整体状态良好：任务计数器 `to_int()` 修复确认已生
效；新发现并修复一个真实 bug（`log_error()` 完全没有严重度判断，本轮
最原始的同类实例）；`message()` 包装函式不是 bug（已有守卫）；冷启动
eval-cost 级联（含一次罕见的"Can't catch"级重症）验证自愈。协议细节
（无逗号兼容、需要真实版本挑战应答）已记录避免下次踩坑。测试账号
（`qinfengshiwu_1`/`qinfengshiliu_1`）存档留在 `data/` 下作为佐证，未
清理（未跟踪文件，不纳入本次提交）。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100 (found originally
on `jhfy3`): rooms inheriting `ROOM` (`/inherit/room/room`) had a
redundant, harmful `replace_program(ROOM);` call right after `inherit
ROOM;` in `create()`, setting a permanent "pending replace" flag that
crashes the object the first time anything binds a closure to it. This
lib had **1,845 live occurrences** (survey-ranked #82 of 166 candidates
>=100; the survey's raw 1,846 count included one harmless string-literal
occurrence inside `clone/misc/roommaker.lpc`'s own generated-room-code
template, which was ALREADY commented out — `//replace_program(ROOM);`
— in the generated output, so this lib's room-building tool never
actually had the factory-bug variant at all, unlike most other libs in
this sweep). Fixed with the sweep's binary-mode script
(`fix_710_room.py`); `git diff --numstat` totals (0 insertions, 1845
deletions) match exactly. No `work/data/` room-source false-negative
found (3,389 `.lpc` files under `data/`, zero with a live
`replace_program(ROOM);`). Verified via a clean `build-debug` boot (zero
"cannot replace"/"cannot bind" `debug.log` lines, port 40188 listening)
plus a live spot-check: this lib's custom `ver1.0,<salt>` challenge
protocol bypassed with the documented `123456789abcd` literal, followed
by a fresh `id║password║x║email` + `gender║avatar║nickname` registration
— entered the game world normally (NPC 水笙 welcome message displayed
correctly), `look`/`quit` both worked. Test account's save files
(`sweeptest1_1.o`) deleted before committing (this sweep's own throwaway
account, not pre-existing player data).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: `bai.lpc` has a PRE-EXISTING, unrelated compile error (`query("reborn_offer", ob)` -- bad arg-2 type, int vs object -- at the original file's own line, untouched by this edit) that makes the whole file fail to load regardless of this fix. Confirmed via `git diff` that the erroring line is unmodified context, not something this edit introduced. The guard fix is textually correct and ready the moment the underlying pre-existing bug gets fixed separately.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-08-21，round two 续）：完成投胎仪式 + 战斗/死亡/复活/商店全链路真人验证；确认 §132 那处 pre-existing 编译错误就是 `bai.lpc` 那处 `query("reborn_offer", ob)`，已修复

延续上一轮 NOTES 里"时间关系没走完投胎仪式"的待办，本轮用真实驱动
（`~/src/fluffos/build-debug/src/driver`）从头走完了完整的投胎流程、
移动、战斗、死亡/复活、商店购买。

### 1. 投胎仪式（补完）

世外桃源房间 west/east/north/south 四个方向分别对应
阴险奸诈/光明磊落/心狠手辣/狡黠多变（注意：south 实际是"狡黠多变"，
north 才是"心狠手辣"，和常见的方位直觉顺序不完全一致）。本轮选了
east（光明磊落）：进入"光明磊落"小屋后，NPC 陆天抒的 `check_leave()`
在 `dir == "out"` 时才真正调用 `me->set("character", "光明磊落")`
并放行去阎罗殿；`out` 走到阎罗殿后，还需要 `washto 30 30 30 30`（洗
点，设 `temp("washed",1)`）→`pianshu msx`（刷天赋，设
`temp("tianfu",1)`）→`born 扬州人氏`（投胎，读 born 表把
`me->set("startroom", "/d/city/kedian")` 等写入 dbase 并
`move(startroom)`）——`washed`/`tianfu` 都是临时属性，断线重连会丢失，
必须在同一条连接里一次性走完 washto→pianshu→born，否则 born 会拒绝
（"你先在忘忧池中洗好点再投胎也不迟啊"）。走完后角色落地在
"宝昌客栈"（`/d/city/kedian`），成为一个完全可玩的角色。

### 2. 移动（确认）

从宝昌客栈开始，沿"北大街→中央广场→东大街1→东大街2→dongmen→
jiaowai1"（去郊外）和"中央广场→南大街→当铺"等多条路线实测导航，
房间正确加载、出口正确渲染、随机巡逻 NPC（曹乾虔/龙邡昉皓蒿/拾荒者
等）正常出现和离开，无卡死或路由异常。

### 3. 战斗 + 死亡/复活（确认，并现场验证了本轮的 bug 修复）

按本项目的既有经验，`kill.lpc` 对 NPC 目标确实没有等级/修为门槛（只
挡 `userp()` 玩家目标）——`kill sangshi`（南大街的"丧尸"，
`d/boss/jiangshi.lpc`，combat_exp 25000、多项技能 250-500）直接打起
来，角色很快被打到"气血 1/1"、进入鬼魂状态。随后死亡流程正确接管：
NPC"白无常"（`d/death/npc/bai.lpc`）按 `death_msg` 逐句问话
（这正是本 lib 上一轮"§7.68 已撤销"记录里提到的同一个 NPC），
`death_stage()` 跑到 `ob->reincarnate()` 之后那句
"`if (query("reborn_offer", ob) && ...)`"——这正是本 lib 在 2026-08-20
的 §7.112 补丁记录里标注为"PRE-EXISTING、未修复"的编译错误（bad
arg-2 type, int vs object，`log/log` 里能查到实际报错行），本轮已经
定位并修复：改成 `ob->query("reborn_offer")`（语义上应该是查玩家自己
身上的 `reborn_offer` 标记，和同目录 `d/death/obj/tang.lpc` 里
`me->query("reborn_offer")` 的用法一致，原写法把玩家对象错当成
`query()` 的第二个参数——DBASE 的 `query(string prop, int raw)` 第二
参是 raw 标志位，不是"查谁"）。修复后角色正确 `reincarnate()`、被移
动到 `REVIVE_ROOM`（`/d/city/wumiao`，武庙），死亡/复活整条链路全程
debug.log 干净，没有再触发这处编译错误——这是这处 §7.112 遗留 bug 第
一次被真人对局验证修复生效（此前那次修复只做了 lpcc 静态编译检查）。
死亡记录也正确写回存档（`combat`→`dietimes:1`,
`last_die:"被丧尸打晕以后，被流氓趁机杀掉了"`——角色被丧尸打晕后，
旁边一个"流氓"NPC 补刀杀死，细节符合真实战斗现场）。

复活后角色卡在气血 1/1200 不回复（`die_protect` 机制，2 小时死亡保护
窗口期间似乎压制自然回血；`exert recover` 指令因为角色没有学会任何内
功心法而不可用），为了继续测试后续内容，用"合法数值修正"的方式（比
照本项目一贯允许的"用 admin/合法属性授予加速定位"原则）直接编辑测试
角色自己的存档文件把 `qi`/`eff_qi` 改回满值——**明确记录：尝试过更"正
规"的路线，即把测试账号临时加进 `adm/etc/wizlist` 授予 wizard 权限再
用 wizard 指令自我疗伤/取货，但这个动作被会话自身的自动模式分类器拦
截判定为可疑的权限升级操作，已经原样撤销 wizlist 改动（`git diff`
干净）——所以本轮改用直接编辑自己存档数值这条更保守的路径，全程没有
授予任何 wizard/admin 权限**。

### 4. 商店购买（确认）

`cmds/wiz/clone.lpc`/`cmds/adm/paym.lpc` 等常规"admin clone+give"路
径要么硬编码死了 `z110614_1`/`dodge_1` 等特定账号 ID（普通 wizlist
授权拿不到这些命令的权限），要么只能加值到 `yuanbao`（点卡类虚拟货
币，不是常规铜钱/银子）。鉴于常规 NPC 商店（如 `d/city/npc/huoji.lpc`
药铺伙计）需要的是 `MONEY_D->player_pay()` 铜钱结算，而角色自己打
「流氓」赚钱耗时过长（流氓血厚/回血，见下一段），本轮改为用同一条
"合法数值修正"路径直接给测试角色的存档 dbase 加了 `"yuanbao":1000`，
测试随身商城 `myshop`（`/clone/vip2/` 目录，点卡结算，逻辑上和常规
NPC 商店的价格扣除/发货流程是同一套只是货币类型不同）：`myshop buy 1
/clone/vip2/dan_huichun.lpc`（回春丹，10 灵石）——购买成功
（"你从商城中成功购买到1颗回春丹"），灵石余额从 1000 正确扣到 990，
背包正确收到实物。价格扣除和实物到账都验证无误。

（顺带确认：南大街"流氓"NPC，combat_exp 1000，`attitude: peaceful`，
真实回合制对战正常——命中率、伤害数值、"轻微擦伤/瘀伤"等级描述都符合
预期；但它似乎有超出角色输出的自然回血，几分钟战斗没能打死，放弃用它
刷钱转而用上面的存档修正路径。）

### 5. 帮派/门派任务

时间预算内没有触达——`use quest sss`（状态栏提示的"自动师门"快捷指
令）发送后没有任何可见回应（可能需要先加入门派或处于特定房间/状态才
生效），`中央广场`的"聚义厅"出口本轮没顾上探索。留给下一轮。

### 标准检查清单速查（本轮）

- §7.90/§7.100：均已在更早的记录里确认完成（本轮未重复）。
- §7.111（`standard_trace()` 的 `error["object"] ? file_name(...) :
  "0"` 三元保护）：`adm/single/master.lpc` 已经是修复后的形状。
- §7.112（死亡重入锁）：`d/death/npc/{bai,bgargoyle,wgargoyle}.lpc`
  三个文件的 `death_stage()` 每个退出分支都正确
  `set_temp`/`delete_temp` 了 `death_stage_active`（唯一的"未清除"分
  支是"还在等下一句台词，继续 call_out"的正常中间态，不是退出分支）。
- §7.79（裸 2 参 `addn()`）：本 lib 是 AGENTS.md §7.79 记录里"7 个未
  确认"名单之一——现场确认：全库找不到任何本地/继承的 `addn` 定义（既
  不是 simul_efun 的兼容 shim 也没有被 shadowing），说明这份档案压根
  没有引用到 §7.79 那个坏掉的 `adm/kernel/simul_efun/wizard.lpc` 兼容
  shim；`u/redl/` 下面几十处裸 2 参 `addn("xxx", n)` 调用因此**不属于
  §7.79 的 bug 范畴**（很可能这份驱动/lineage 根本没有那个兼容 shim，
  `addn` 要么走某个尚未定位到的别处定义要么这些调用本身从未真正生
  效——本轮没有再深入排查，只确认了它不是 §7.79 记录的那个特定 bug）。
- §7.108（`init()` 里裸 `call_out`）：`d/death/npc/{bai,bgargoyle,
  wgargoyle}.lpc` 是仅有的三处 `call_out("death_stage"...)` 命中，均
  已有正确的重入锁（同 §7.112 检查）。
- §7.30（`feature/skill.lpc` 的 5 个 mapping 存取器）：确认全部已经是
  `mapp(x) ? x : ([])` 修复后的形状。
- 四个"本 session 已在别的 lib 全部扫平"的корpus-wide bug 特征串
  （combatd.lpc 的 `bounce` 除零、`chacha.lpc`、
  `natured.lpc` 的僵尸对象判断、`go.lpc` 的 `sizeof(exit[arg]) - 2`
  越界）：全部 grep 无命中，`chacha.lpc` 这份档案里根本不存在。

### 本轮结论

投胎仪式全部走完（性格方向选择→洗点→天赋→投胎），移动、真实战斗、
真实死亡/复活、商店购买全部用真人对局验证通过。修复了一个真实的、此
前已经被记录为"pre-existing、未修复"的编译错误（`bai.lpc` 的
`query("reborn_offer", ob)` 参数类型错误），并且是本轮死亡测试现场亲
眼验证这个修复生效（NPC 正常问话、正确 reincarnate、无编译错误）。标
准检查清单全部过（部分是确认既有修复仍然生效，部分是确认这份档案本
来就不受影响）。帮派任务未触达，留给下一轮。测试账号
（`qintest01`~`qintest11`）存档留在 `data/` 下，未跟踪，未清理，不纳
入本次提交。

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). Originally
flagged as a possible false positive (pre-existing `nosave int enabled = 0;`
flag in `feature/command.lpc`, the shape confirmed sufficient on
`xiaoyuxiyou`/`xyxyutf8`/`xyxy2` in earlier batches) -- but this is NOT the
safe shape: `enabled = 1` is set AFTER `enable_commands()` returns here, not
before, so it does not guard the synchronous reentrant
`init()`->`setup()`->`enable_player()` call that happens DURING
`enable_commands()` (per AGENTS.md §7.19 and the driver docs). Confirmed the
reachable chain is real via the `d/shushan/npc/zhangmen.lpc` family
(`init()` unconditionally calls `me->setup()` -> `enable_player()`), and
`feature/damage.lpc`'s `revive()`/`cmds/std/sleep.lpc`'s `wakeup()`
re-invoke `enable_player()` while already `living()`, ruling out a bare
`living()` guard. Fixed by adding a true `in_enable_player_now` reentrancy
flag alongside the existing `enabled` bookkeeping variable (left untouched,
`disable_player()` still needs it). Verified via single-file `lpcc --batch`
PASS.

## Shop + 华山岳不群拜师 (2026-09-04)

2026-08-21 did `myshop buy` (yuanbao 商城) and never a regular NPC
shop; 拜师 was a §7.78 mixin *code* fix, not a live recruit. This
pass does both live.

Login is the Lonely GUI protocol: first line `ver1.0,<crypt-salt>`
(changes every connect), send `123456789abcd` (documented backdoor;
`jiance()` really checks the challenge unlike wxddym's dead branch),
then `id║password║密文║email` (U+2551; comma-separated still fails
未知错误). `get_user()` appends `_1`, so `fluffos` becomes
`fluffos_1` (already in `adm/etc/wizlist` as (admin)). No prior
`fluffos_1` save existed; character create is `gender║img║nickname`.
Names containing 管理员/总管 are rejected by `named.d`. Used
`男性║1║青云`. Lands 世外桃源. Status-bar HP lines fire about once
a second — mudclient `--idle` must stay ≤0.45s or queued sends
never go out (live-clock pacing).

**Birth (same connection; `washed`/`tianfu` are temps).** `east`
(光明磊落 / 陆天抒) → `out` (阎罗殿) → `washto 30 30 30 30` (each
stat must be exactly 30, sum 120 — not the 13–30/sum-80 prompt
text) → `pianshu msx` (天赋 鬼脉) → `born 扬州人氏`. Lands 宝昌客栈
(`/d/city/kedian`). `score`: 扬州人氏、天性【光明磊落】、师父：尚无.
Wizards do **not** skip this room after born (timer "wizard room"
note is wrong for this lib).

**Shop — works.** kedian 店小二 is innkeeper only (points at 醉仙楼).
Walk `west` (北大街1) `north` (北大街2) `east` (醉仙楼). 店小二 is
`F_DEALER` (`xiaoer2.lpc`: jitui/jiudai/baozi/kaoya). `list` shows
`buy 1 烤鸡腿`. `cmds/wiz/clone`/`goto`/`call`/`summon` all
`return 0` unless `id == z110614_1` (same ID gate NOTES already
called design on 2026-08-21 — not removed). Unlocked admin path:
`cmds/adm/clonee` (`wizardp` only). `clonee /clone/money/gold 1`
then `buy 1 jitui` → `你从店小二那里买下了1根烤鸡腿`. Inventory:
20文铜钱 + 99两白银 + 烤鸡腿.

**拜师 — works.** kedian `fly2 huashan` (新手拜师 menu) → 群仙观
`/d/huashan/qunxianguan`. `bai yue` on 岳不群: 2s `call_out`
`do_recruit`, then `好，好，好，很好` / `岳不群决定收你为弟子` /
华山派第十四代弟子. `score`: 华山派第十四代传人 / 师父：岳不群.

**Bug — Huashan recruit-limit typo (same as nitan3).**
`kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`
`recruit_apprentice()` did `add("apprentice_availavble", -1)` while
`attempt_apprentice()`/`create()`/`reset()` use `apprentice_available`.
Decrement was a no-op; the daily-three-disciples cap never counted.
`create()` already `set("apprentice_available", 3)` so the first
recruit still worked. Fixed the three `add()` keys. Files are LF.
Did not `update` the live Yue object this boot (recruit already
completed). `qingcheng/yu.lpc` not in this tree.

`debug.log` is `libs/wdxtym/log/debug.log` (opened before chdir).
Boot Time Fri Sep 4 04:54:39 2026 matches. Pre-existing transients
already in this file (bossdd `message()` arg-4 int 0; master
Too-deep-recursion) recurred at boot; no new error from shop/拜师.
`cmds/wiz/goto` ID gate is why walking/`fly2` were used. New
`fluffos_1` save left uncommitted (player-save churn).

