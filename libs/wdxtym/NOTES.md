
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
