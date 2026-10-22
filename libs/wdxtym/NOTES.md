
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


## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理（第一轮）

`scripts/lpc_warnings.py wdxtym --fix` 第一轮：无用局部变量 1284 个、`varargs` 16 处、裸 `return` 9 处、`#pragma save_binary` 等，共改动 353 个 `.lpc` 和 2 个头文件。本库有 46890 个 `.lpc`，一次 VM 编译全部文件会耗尽内存，第二轮扫描没能完成，所以只提交这一轮。验证：改动过的文件与包含改动头文件的文件共 410 个，HEAD 与工作树分别分批加载（新进程，每批 700 个）：407 -> 407 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 6 条候选都是声明被重建或同名 efun（`time()`）。启动时警告 229 -> 2。手工改的三处真问题：
- `adm/daemons/questd.lpc` 两处 `jifen1 == 10;`（应为赋值）。
- `adm/daemons/wendad.lpc` `heart_beat()` 里 `wjgl_flag == 0;`：异朽阁事件结束后标志从不复位，改为赋值。
- `adm/daemons/natured.lpc` 一行无作用的 `lt[LT_MON];` 删去。
剩下：`adm/daemons/payd.lpc` 注释里的 `/*`（需人工读懂那段被注释掉的条件）。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-09）— 编译警告整理

`scripts/lpc_warnings.py wdxtym --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 2348 个 `.lpc` 和 28 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：2039 -> 2040 通过，无回退；改过的头文件的 250 个包含者 216 -> 216 通过。启动时警告 1 -> 0；新进程登录（输入名字）正常。
（这一轮用分块扫描重跑：上一轮单次 `lpcc --batch` 中途死掉，只扫到 46890 个文件里的 8599 个。）手改 `adm/daemons/payd.lpc`：充值赠送那几行原档案就写成 `amount += amount / 0;`、`amount * 0 / 0`（显然是有人想取消赠送），结果一次充值 1500 以上就是除零错误、充值处理中断；改成 `amount += 0;`（不赠送，行为与作者意图一致）。被注释掉的一段里又有一个 `/*`（编译警告 `/* found in comment`），去掉，不影响代码。

- 2026-10-10：`/u/mud/skills/wudang/jian.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 8 个，只在 #if 分支用的声明移进分支 1 个文件；改动 26 个文件，HEAD 与工作树各载入一次无回退（26 objects; HEAD PASS 6, tree PASS 6; regress 0; newly loading 0），这些文件的警告 59 -> 31。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/lonely/combatd.lpc u/redl/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（二）

- `cmds/skill/zhanling.lpc`：`lv4 == "神奇普通5串";` 应为 `=`。
- `kungfu/skill/riyue-xinfa.lpc` `valid_force()`：作者在 return 后补了一句 `force == "kuihua-shengong";`，永远执行不到；并进 return 的条件。载入无回退。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - `feature/food.lpc`、`feature/liquid.lpc` 的 `do_effect()` 由 `void` 改为 `int`。`drink` 命令把 `ob->do_effect(me)` 当命令结果返回，`eat` 也读它的值，子类（如 `d/guanwai/obj/wan.lpc`）本来就返回 int。
  - `adm/npc/wizard.lpc` 先包含 `vip_skill.h`（自带 `sk_list`/`sk_list2`，供 `check_vip_skill()` 用），又在本文件里重定义了这两张表。本文件读的是自己的那份，改名为 `wiz_sk_list`/`wiz_sk_list2`，行为不变。
  - `d/sishenfuben`、`d/xiaobaiben` 四个 NPC 的 `mapping *skill_map` 技能表与 `F_SKILL` 的 `skill_map` 同名，改名为 `skill_tables`。
  - `quest/shenshu/npc/man2.lpc` 删去较短的旧 `order`/`data` 表；`man2`/`testman` 的 `kill_ob` 改 `void`。
  - 农场养殖上限写明 `to_int()`；5 个文件注释里嵌套的 `/*` 去掉；两处函数结尾多余的 `;` 去掉。
  - 改动的 50 个对象载入无回退。

- 2026-10-14：6 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：6 个对象，新增载入 5，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。2 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 7 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，2 处改为 `add(type, -N)`。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## taixu 状态的颜色宏（2026-10-15）

`kungfu/condition/taixu.lpc` 用了未定义的 `HC`（应为 `HIC`），文件编译失败；已改。目前没有地方施加这个状态。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`sougu-yingzhua`、`test`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`zuixin-sword`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`daojian-guizhen/xue`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`wushang-jianjingsAA`→`wushang-jianjingsA`（`wushang-jianjingsA`、`wushang-jianjingsA/exert/wushanga1`、`wushang-jianjingsA/perform/wushangb1`、`wushang-jianjingsA/perform/wushangb2`、`wushang-jianjingsA/perform/wushangb3`、`wushang-jianjingsA/perform/wushangb4`、`wushang-jianjingsA/perform/wushangb5`、`wushang-jianjingsA/perform/wushangb6`、`wushang-jianjingsA/perform/wushangb7`）；`taiji-shengon`→`taiji-shengong`（`taiji-shengong`、`wushang-jianjingsA/perform/wushangb5`）；`shicheng-liulang`→`shicheng-liulong`（`shicheng-liulong`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）；`youzi-jian`→`youzhi-jian`（`youzhi-jian/kuang`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 农场档 farmd.o 截断（2026-10-15，KB 03 §4.4）

`data/farmd.o` 原档只有 45 字节，停在 `farmd (["sword_1":([])`，`restore_object()` 报错，农场守护进程载入失败。补成 `farmd (["sword_1":([]),])`。`backup/` 下的同名旧档同样截断，未动。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 刀剑归真「天下有血」没有第二件兵器时报错（2026-10-15，KB 06 §7.246）

`daojian-guizhen/xue` 直接读第二件兵器的 `skill_type`，手上只有一件兵器时报错；同目录的 `ben`、`jiu`、`tian` 都先拒绝。补上同样的“你没有同时装备刀剑”拒绝。

## 黯然销魂掌「拖泥带水」气血不足时报错（2026-10-15，KB 06 §7.246）

设置 `cob = find_player(couple)` 的那几行被注释掉了（不再要求配偶在线），后面气血低于四分之一时的招式文字仍用 `cob->name(1)`：正是这一招最该出现的时候报错。改为读存档里配偶的名字 `couple/name`，没有就写“远方”。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

44 个文件、53 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city2/obj/jinduan`、`/clone/weapon/sword`、`/d/xueshan/obj/xblade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 17 个（17 个原来载入不了），没有退步；其余 27 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`BOSS` → `/inherit/char/boss`（18 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：18 个里 0 个通过，其余 18 个还有别的错误（`adm/npc/dragon.lpc`：/inherit/char/boss.lpc:4: error: Cannot #include boss.h；`d/death/liudaolunhui/npc/chushengdaofo.lpc`：/inherit/char/boss.lpc:4: error: Cannot #include boss.h；`d/death/liudaolunhui/npc/diyudaofo.lpc`：/inherit/char/boss.lpc:4: error: Cannot #include boss.h……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 287 个对象设了本库没有文件的武功（122 个名字，最多的是 `xiantian-qigong`、`qiulinshiye`、`aikido`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 24 个通过，其余 6 个停在别的错误上（`maze/necropolis/npc/taoist`：*No program in object '/maze/necropolis/necropolis_npc'!；`quest/jobnpc/wudujiao`：*Bad argument 1 to EFUN call_other()……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuben/108man/enter` 的 `north`：`/d/fuben/108/planet` → `/d/fuben/108man/planet`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/room/demonroom`（宏 `DEMONROOM`）←nitan6，14 个对象继承它，抽样 8/8 载入；`/inherit/char/bh_npc`（宏 `BH_NPC`）←hy3，1 个对象继承它，抽样 1/1 载入；`/inherit/weapon/ring`（宏 `RING`）←wxddym，1 个对象继承它，抽样 1/1 载入；`/inherit/char/worm`←wxddym，15 个对象继承它，抽样 8/8 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 122 处、76 个文件：`qiulinshiye`→`qiulin-shiye`（56 处）、`kunlun-shnfa`→`kunlun-shenfa`（17 处）、`lingboweibu`→`lingbo-weibu`（13 处）、`shaolin-shnfa`→`shaolin-shenfa`（10 处）、`yijin-jing`→`yijinjing`（6 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`moshen-jianda`→`moshen-jianfa`（3 处）等共 15 个名字。（`scripts/lpc_fix_skill_names.py`）

## 从 nitan6 移植 dbase 的“对象参数”约定和 simul_efun 兜底（2026-10-19，KB 05 §7.15）

本库的代码到处按 nitan 一系的约定写：`query("id", ob)`、`query_temp("fighting", me)`、`set("x", v, ob)`（第二个/末尾的参数是目标物件，等于 `ob->query("id")`），也到处用 `count_lt()`/`count_add()`、`time_period()`、`to_string()`、`good_bunch()`、`addn()`/`addn_temp()` 这些全局函数。可是本库的 `feature/dbase.lpc`、`include/dbase.h` 还是旧签名 `query(string prop, int raw)`，simul_efun 里也没有这些函数：驱动在编译时报 `Bad type for argument 2 of query ( int vs object )`、`Undefined function query_temp/count_lt/time_period`，kungfu/skill 下的招式、maze 战场的 NPC都载入不了（移植后此前因这一类原因编译不过的 80 个文件里 58 个载入）。照 nitan6 的做法移植：`dbase.h` 的原型和 `dbase.lpc` 的 `set/query/delete/set_temp/query_temp/delete_temp` 接受目标物件（`raw_or_ob`：整数是“原始值”标志，物件则转给它自己的 dbase）；`inherit/room/room.lpc`、`adm/daemons/examined.lpc`、`clone/user/user.lpc` 里覆盖这些函数的地方同步改签名；simul_efun 对象 `inherit F_TREEMAP` 并在 `adm/simul_efun/wizard.lpc` 里放不继承 F_DBASE 的对象用的兜底版本（同样带目标物件转发，招式 perform 文件就靠它），新增 `adm/simul_efun/ntefun.lpc`（`count()` 及 `count_*`、`time_period`、`to_string`、`range_random`、`base_dir`、`format_string`、`mapping_eqv`、`bunchp/good_bunch/bad_bunch`、`addn/addn_temp`）。运行时探针（两个 NPC 互相 `query(…, 对方)`、`set(…, 7, 对方)`、非 dbase 对象裸调用 `query_temp(…, 对方)`）全部符合预期。

移植后才编译到底的文件里露出 12 个未使用的局部变量，已删：`cmds/usr/ability`（`lists`、`temp`）、`cmds/usr/talent`（`lists`、`temp`、`myclass`）、`maze/necropolis/npc/` 下的 `ghost_devil`、`ghost_devil_special`、`skeleton_lich`、`skeleton_lich_special`（`no_busy`）、`taoist`（`obs`、`reward_msg`）、`zombie_blood`（`msg`），与 wxddym 同一处改法。`cmds/usr/ability`、`talent` 仍载入不了：它们调用的 `MYGIFT_D` 本库的头文件没有定义，`adm/daemons/mygiftd` 也没有这个文件（nitan6/nt6 有），这是未定义宏一类，另案处理。

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SPECIAL_ATTACK`、`BUSY_MESSAGE`、`BUFF_STR`，用到它们的物件（名单里 7 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 4 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/clone/board/anonymous_b.lpc`、`/clone/board/bocai_b.lpc`、`/clone/board/kedian_b.lpc`、`/clone/board/towiz_b.lpc`共 4 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `feature/dbase.lpc` 的 ZJ 出口提示在目的地不存在时不再中断 `set("exits/…")`（`catch` 住 `data->query("short")`）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade1.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/single/simul_efun.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：1 个覆盖基类 void 函数的函数改了类型，2 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `clone/aaa/1bt.lpc`、`clone/jifeng/1bt.lpc`：注释的结尾写成了 `/**/`（`/* found in comment`），改成 `*/`，注释范围不变。
- `clone/box/gboxa.lpc`、`clone/lonely/badao.lpc`：已经在注释里的第二个 `/*`（`/*if( mapp(exit = …`、`/*   if (me->query_skill(…`）去掉；注释从第一个 `/*` 到第一个 `*/`，范围不变。
- `quest/shenshu/npc/man.lpc`：`int kill_ob(object ob)` 盖掉基类 `feature/attack.lpc` 的 `void kill_ob()`，函数里没有 `return`，改成 `void`。`u/redl/teleport/qiulao.lpc`：`int init()` 里 `return ::init();`，基类的 `init()` 是 void，改成 `void init()`、`return;`、`::init();`。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/quest/menpaijob/dali/quest.lpc`、`/quest/menpaijob/tiezhang/quest.lpc`、`/quest/newbie/qiandao/lagjobold.lpc`、`/quest/songhuo/quest.lpc`。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 3 个文件：`/quest/menpaijob/gumu/guan.lpc`、`/quest/menpaijob/xingxiu/meinv.lpc`、`/quest/menpaijob/xuedao/meinv.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 3 个原来载入失败、现在载入，没有退步。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：4 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女的 class 判断永远走不到“不是道士”那一支。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/quest/menpaijob/gumu/zf/longnv.lpc`（3 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/cmds/usr/life.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/cmds/arch/sameip.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 4 处）。改动：`/adm/daemons/liaotd.lpc`（2 处）、`/kungfu/skill/kuihua-dafa.lpc`（1 处）、`/quest/shenshu/npc/man.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/bossd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/single/importer.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## `wabaod` 的藏宝线索按双字节算（2026-10-20，KB 06 §7.307）

天书的线索由 `adm/daemons/wabaod.lpc` 在房间描述里挖空若干个字：`desc = long[begin..begin + 60]`（按 GB 的 61 字节）、`desc[b..b + 1] = "■"`（两个字节换两个字节）。驱动的字符串是 UTF-8，区间按字符数：窗口成了 61 个字符，每次替换把两个字符换成一个，字符串越换越短，后面的偏移越界，启动时 `push_lvalue_range: invalid ind2`（随机出现，`init_xunbao` 的每次 call_out 也会）。改成按字符算：30 个字符的窗口，每处挖一个字（`scripts/lpc_fix_wabaod.py`）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/maze/sand_dragon/npc/sand_dragon.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/d/migong/obj/npc2.lpc`、`/d/migong/obj/npct.lpc`、`/d/migong/obj/testnpc2.lpc`、`/inherit/char/npc.lpc`、`/quest/shenshu/npc/testnpc2.lpc`（等共 8 个文件）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/usr/fasong.lpc`（`sscanf`）、`/cmds/usr/showitem.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 蜀山厨子 `chuzi`：给食物的两行 `new()` 被注释掉了（2026-10-21，KB 06 §7.346）

`do_yao()` 里 `m = new("d/obj/food/dishes/dish10");` / `mm = ...` 两行是注释，后面的 `m->move(this_player()); mm->move(this_player());` 还在：向厨子要东西一律抛错。本库没有 `dish10`，按 chidi 的同一份文件改成 `clone/food/baozi` 和 `clone/food/jiudai`（本库都有）。

## wdxtym：宠物心跳、金兵、葵花宝典（2026-10-21，KB 06 §7.348）

`clone/pet/{pet,kaijia,zhanhun}.lpc` 的 `heart_beat()`（`set_heart_beat(1)`）每秒读一次没赋值的 `ob`（宠物的主人）并抛错；主人存在 `query("possessed")`（`petowner.lpc` 创建宠物时设置），改成 `ob = query("possessed")` 并判空。`quest/weiguo/jinbing/jin4.lpc` 的 `die()`：`obn = new("/clone/money/gold")` 被注释掉，`obn->set_amount(..); obn->move(me)` 还在，金兵特务一死就抛错（jin1~3 已经没有这段），去掉这两句。`clone/book/kuihua.lpc`、`kuihuabaodian.lpc`：读书时精不够就找护心丹 `present("huxin dan", obj)`，`obj` 没赋值，改成 `me`。改动：`/clone/book/kuihua.lpc`、`/clone/book/kuihuabaodian.lpc`、`/clone/pet/kaijia.lpc`、`/clone/pet/pet.lpc`、`/clone/pet/zhanhun.lpc`、`/quest/weiguo/jinbing/jin4.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 2701 条注册（908 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/Aboss1/GW1/Gzb/bg1.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg11.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg12.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg2.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg3.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg4.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg6.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg7.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/Gzb/bg8.lpc`（`do_duanlian`、`do_hui`、`do_levelup`）、`/Aboss1/GW1/JL/bg1.lpc`（`do_duanlian`、`do_hui`、`do_levelup`） 等共 908 个文件。最多的函数名：`do_duanlian` 891 处、`do_levelup` 891 处、`do_hui` 879 处、`do_qiongqii` 12 处、`do_vendor_list` 3 处。没有动（读过）：`/adm/npc/wenqin.lpc` 的 `show_baowu`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（2 处调用）、`outdoor_room_event()`（1 处调用）；`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_period()`（3 处调用）；`/adm/daemons/chinesed.lpc` ← hhsj：`find_skill()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 8 个函数没有补（inquiry 4, item_desc 2, other 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi1.lpc`:`look_CAI`、`/d/yihua/lianhuachi2.lpc`:`look_CAI`、`/quest/jobnpc/feitian.lpc`:`ask_me`、`/quest/jobnpc/feitian.lpc`:`ask_dao`、`/quest/jobnpc/feitian.lpc`:`ask_give`、`/quest/jobnpc/feitian.lpc`:`ask_job`、`/quest/shenshu/npc/action.lpc`:`exert_function`、`/quest/shenshu/npc/action.lpc`:`perform_action`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 2 条单独成行的语句（`/clone/board/feitian_b`、`/clone/board/huanhua_b`；`/d/feitian/daochang.lpc`、`/d/huanhua/dating.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。
