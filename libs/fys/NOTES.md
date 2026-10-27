
## WASM 修复摘要（迁移自 meta.json 的 group_note）

档案名叫"风云三"，但实际游戏内横幅是"铁血江湖"（内容无关，只是文件名对不上）。is_chinese() 在这份档案里本来就已经修成了正确的 CJK 码点判断，但 check_legal_name() 的长度界限（strlen<4||>8）和它的字节步进循环（i%2==0 门槛，name[i..<0] 尾部切片）底层仍然是旧的 GBK 字节配对假设，会静默拒绝所有真实中文名字，包括标准的两字测试名——已把界限改成匹配错误提示本身声明的字符数（2-6），循环改成逐字符切片（§8.1）。quit.lpc 强制了一个真实存在的 30 秒登录后冷却（游戏设计如此，不是 bug）——测试时需要更长的 idle/填充指令预算才能观察到冷却结束，而不只是立即的 notify_fail 拒绝。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 20 个总命中里抓到了 6 处真正的损坏（5 个 ASCII 地图档案加一个分词器失去同步的帮助文字档案）——全部 6 处都直接还原，没有手工修补。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身，本轮原生 driver（端口 40164）走完了移
动、留言板、商店 NPC 观察、战斗、以及**两轮**死亡→复活验证（第
一轮暴露出一个全新的、真正会把玩家永久卡死的 bug；第二轮在修复
后确认问题彻底解决）。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三个真实
bug**：

1. **§7.34 printf 调试泄漏（新实例）**：`adm/daemons/logind.lpc`
   `get_name()` 里，紧跟在中文名字校验通过之后有一行
   `printf("%O\n", ob);`——每个新玩家都会在自己屏幕上看到连线对象
   的原始调试信息。已删除。
2. **第 13 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（鬼门关的白无常/黑无常，`DEATH_ROOM` 宏
   `/d/death/gate` 直接摆着白无常，其 `north` 出口
   `/d/death/gateway` 摆着黑无常，两者均可达）的 `death_stage()`
   把"玩家暂时不在场"和"对象已销毁"合并成同一个提前 `return`。已
   拆分为标准修法：`!ob` 永久放弃，`!present(ob)` 改为 5 秒后重
   试。
3. **全新发现：`REVIVE_ROOM` 宏指向一个不存在的文件，导致复活序
   列走完对话后玩家永久卡在鬼门关（比 §7.68 更彻底——不是"暂时中
   断才卡死"，而是即使全程不被打扰也一定卡死）**。`include/
   login.h` 里 `#define REVIVE_ROOM "/d/yangzhou/temple"`
   指向的文件根本不存在；现场复现（杀死测试角色、完全不打断地等
   待超过 30 秒）后，虽然 `debug.log` 全程干净，但 driver 自己的
   stdout 捕获（`boot.log`，沿用 §10.8 的排查经验——`debug.log`
   会漏掉这类错误）明确记录了 `执行时段错误：*call_other()
   couldn't find object '/d/yangzhou/temple'.`——白无常的五段对话
   和 `reincarnate()` 都正常完成，但最后一步 `ob->move
   (REVIVE_ROOM)` 静默失败，角色永远留在鬼门关，只能看到白无常反
   复的闲聊消息。追查发现"temple.lpc"这个文件名如今只存在于一个
   完全没有被任何活跃房间引用的备份目录
   `d/yz_bak/yangzhou/`（内容是"隋炀帝陵"，和"temple"这个文件名本
   身的语义已经不匹配了——这份备份目录很可能是扬州分区某次重新整
   理之前的旧版快照）。比对 `d/yz_bak/yangzhou/daxiongbaodian.lpc`
   （"大雄宝殿"）与现役区 `d/yangzhou/damingshi1.lpc`（同样是"大雄
   宝殿"）这一对内容相同、路径不同的房间，可以确认现役的"扬州"分
   区是这个旧备份重新整理/改名后的产物；现役区里语义上真正对应
   "temple"（寺庙）的房间是 `d/yangzhou/damingshi.lpc`（"大名
   寺"，紧邻着"大雄宝殿"，房间里有一位"知客僧"）。已把
   `REVIVE_ROOM` 改指向 `/d/yangzhou/damingshi`，并在宏定义旁写
   了完整的排查注释。现场复现验证：修复后角色死亡→鬼门关→完整对
   话→`reincarnate()`→成功落地"大名寺"，不再卡死。

**顺手发现但未修复、留待观察的一处类似问题**：`u/lxh/dufang.lpc`
（"逍遥赌坊"，一位巫师自建的骰子赌场，从"英豪酒楼"往南可达）的
`east` 出口写的是 `__DIR__ "chunxilu3"`（相对路径，指向
`u/lxh/chunxilu3.lpc`，不存在），现场触发出的是同一类"目标文件不
存在"报错。项目里确实有一个同名文件 `d/chengdu/chunxilu3.lpc`
（"春熙路口"，成都分区），文件名重合但没有找到任何更直接的证据
（没有注释、没有其它文件引用）能确认这就是原作者的本意——不像
`REVIVE_ROOM` 那样有"隋炀帝陵/大雄宝殿"这种结构性配对证据支撑，
所以按本项目一贯的原则（不确信就不要瞎猜）先如实记录，不改动。

**主动检查确认不是 bug 的项**：`command_hook`
（`feature/command.lpc`）已经是 `nomask`；全文搜索未发现
`MESSAGE_D->` 未加防护的调用；食物/饮水在 `logind.lpc` 里两处都
是无条件 `user->set("food", 100); user->set("water", 100);`，没有
任何 age 判断，不是 §8.9 的错误对象变体。

**顺手修复一处确认为原始压缩包本身损坏的乱码字**（用 Python 直接
读取 raw 归档字节核实过，不是转码流程引入的）：白无常/黑无常两份
文件里"□上册子"应为"合上册子"（GBK 字节 `\xa1\xf5` 本来就是符号
表里的"□"，原作者当年大概率是手误/复制粘贴丢字）——本项目另外至
少 10 个不同血统档案的同款判官/无常对话都逐字写着"合上册子"，凭
这么多独立来源的印证还原。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）注册成功，落地"英豪酒楼"（中
   州城最大的酒楼，`no_fight` 房间），场景里有真正可读的留言板
   （当时无留言）和 NPC"武大郎"。
2. 移动：英豪酒楼→逍遥赌坊（巫师自建赌场，规则牌子文字完整）→
   文定北街→市中心→延陵东路等多个房间，沿途场景描述、出口、
   NPC 列表均正常渲染（除上文记录的 chunxilu3 死路外）。
3. 战斗测试：`wimpy 0` 后依次尝试攻击"小孩""流氓"等新手区 NPC
   （战斗力都很低，几个回合分不出胜负），最终用"侠士"（明显高出
   一个数量级的战斗力）一击致命触发死亡流程。
4. 死亡→复活验证（两轮，如上文详述）：第一轮暴露 `REVIVE_ROOM`
   bug（角色永久卡在鬼门关，即使完全不打断也一样），第二轮在修
   复+重启 driver 后验证角色成功落地"大名寺"。

**结果**：整个测试会话（含两轮死亡复活循环、一次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录——`REVIVE_ROOM` 那个 bug 的
报错只出现在 `boot.log`（driver 自己的 stdout），再次印证了
§10.8 强调的"只看 `debug.log` 会漏掉一类真实错误"的教训。测试角
色存档（`data/{login,user}/s/shenmu.o`）保持未跟踪；三处 `.lpc`
改动（`logind.lpc`/`wgargoyle.lpc`/`bgargoyle.lpc`）已用 formatter
校验（`{"errors":0}`）；`include/login.h` 的宏定义改动不在
formatter 覆盖范围内，改动很小，人工核对无误。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg` 同一原始形状）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message +
   "\n");`——不区分巫师/玩家，也不区分警告/错误。真实复现：全新驱动
   进程下首次完整注册流程（`fluffos` 管理员账号）触发的冷编译级
   联，屏幕上连续刷出 **124 行**原始诊断（本轮迄今为止最严重的一
   次，这份档案的场景/NPC 数量明显更大）。修复：加上
   `strsrch(message, "arning:") == -1` 判断。已用同一新驱动进程下的
   完整重新注册复测：零次诊断刷屏（唯一命中的"什么"是正常游戏文本
   "发生什么了？"）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，与 `fqyy2`/`fy2mg`
   同一形状）**：`LOG_DIR` 下的 `nosave/` 子目录在全新检出里不存
   在，`suicide`/崩溃日志/巫师 `clone` 日志等管理指令路径的
   `log_file()` 调用会在首次使用时未捕获抛出。注册/登录本身只写
   `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，但
   这是一个明确存在的 bug，按标准模式补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正创建（AGENTS.md §1.5 的"wizlist 有记录但角色
   从未真正建立"形状，与 `fy2mg` 同一模式）**：`adm/etc/wizlist`
   里早就有 `fluffos (admin)` 这一行，但 README 此前的记录"账号本身
   通过正常注册流程创建"经核实是错的——`git log` 确认仓库里从未提交
   过 `data/{login,user}/f/fluffos.o`。已用真实注册流程完整创建
   `fluffos` 角色，`score` 确认显示"目前权限：(admin)"，
   `update /adm/daemons/securityd` 确认可正常重新编译。README 已同
   步更正这段记录。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`
  和 `u/xxy/city2/npc/refereew.lpc:176` 均已用
  `(string)(to_int(query("win_times")) % 5)`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- `assure_file()` 本身末尾不做 `seteuid(getuid())` 重置，不属于
  `nitan_san`/`nt6nitan6win` 那种"assure_file 自己把 euid 重置掉"的
  形状。

### 实测过程

`fluffos` 管理员账号完整注册（英文 id → 确认建立 → 中文名，直接设定
不需要二次确认 → 密码（此代码线只要求 ≥3 字元，比 `fqyy2`/`fy2mg`
宽松很多）→ 确认密码 → 邮箱 → 性别）进入起始区域。修复前后各做一次
全新驱动进程下的完整注册；修复前复现了 124 行诊断刷屏，修复后干
净。`log/debug.log` 全程时间戳未变化，确认无新增未捕获运行期错误。
驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：2868 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。这份档案有 5 处代码生成模板烤了同一个地雷：
`obj/roommaker.lpc`、`d/obj/clone/misc/roommaker.lpc`（简单字符串
拼接写法）以及 `obj/rmmaker.lpc`、`u/panguan/rmmaker.lpc`、
`u/panguan/room.lpc`（`room_code +=` 缩进写法略有不同的另一套模板，
前两处修完后仍剩 3 处才发现）。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 5 处模板手动摘除字符串拼接片段。`git diff --stat`：2868 files
changed。备注：survey 记录的"live"数字（3013）和实际盘面对不上，
真实 live 数量是 2870（总匹配 3157 减去 287 处确认为既有注释的行，
逐条抽样核实过），修复后 0 处遗留 live 匹配，287 处注释原样保留未
动。

验证：`build-debug` 驱动真实冷启动，端口 40164 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（落地英豪酒楼，look/quit——quit 触发"三十秒后才能下线"的存档中提
示，属正常游戏机制不是崩溃），全程无新增
"cannot replace"/"cannot bind" 日志行。

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

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：英豪酒楼真实购买 + 泰山派天乙道人拜师。round one（2026-08-04）
只「商店 NPC 观察」，没有 `buy`。round two（2026-08-13）补了
`log_error` 闸门和 `log_file` `assure_file`，没有拜师。wakeup 说
「has buy, need 拜师」——NOTES 正文里其实没有成功购买记录，本轮两
项都做。

本轮没有新的 programming bug。`log_file()` 已有 `assure_file()`。
`log_error()` 已有 `arning:` 闸门（玩家可见 0 条编译警告）。第一
输入是「您的英文名字」。`quit` 仍有 30 秒冷却（设计，不测 quit）。

### 实测过程

管理员 `fluffos` / `Mud@2026`。端口 40164。落地英豪酒楼
`/d/zhongzhou/yinghao`，武大郎 id `wu dalang`，`F_VENDOR`。`clone
/obj/money/gold` 一次成功（`cmds/app/clone.lpc` 无 `is_admin()`
门槛）。`list` 烤鸡腿三十文 / 烧饼四十文 / 包子五十文等。`buy
jitui from wu dalang` 成功：「你向武大郎买下一根烤鸡腿。」`i` 剩
九十九两银子 + 七十文钱（10000−30=9970）+ 烤鸡腿。

`goto /d/taishan/yitian`（一天门），天乙道人 id `tianyi`。
`apprentice tianyi` 一次成功：「恭喜您成为泰山派的第十四代弟子。」
`score`「泰山派第十四代弟子」「你的师父是天乙道人」。`save`「档案
储存完毕。」峨嵋 `qingxin.lpc` 没有房间引用，未走那条。陈玉林
（丐帮成都）`int>=25` 拒收，没测。

live `debug.log` 是 `libs/fys/log/debug.log`（Boot Time Fri Sep 4
03:55:18 2026），无 `error:` / `Too deep recursion`。管理员存档未
提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 17 line(s) in 5 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 16 file(s) `inherit F_SSERVER;` and no header defines it (16 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 1 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 4 here-document block(s) repaired (4 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/wudang/bolin.lpc`, `u/xxy/room/heimuya/shenggu.lpc`, `u/xxy/room/heimuya/tang.lpc`, `u/xxy/room/heimuya/npc/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply fys`: 7 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 16 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 14 PASS, 0 that loaded before fail now, 13 more load.

7 files moved (7 `.C`); mostly under `d/yangzhou/npc` (7). A rescan with `scripts/lpc_warnings.py fys` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`d/obj/inherit/weapon/throwing.lpc`、`d/obj/inherit/weapon/fork.lpc`、`d/obj/inherit/weapon/whip.lpc`、`d/obj/inherit/weapon/sword.lpc`、`d/obj/inherit/weapon/axe.lpc`、`d/obj/inherit/weapon/blade.lpc`、等共 9 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py fys --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 532 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：485 -> 485 通过，无回退；改过的头文件的 80 个包含者 78 -> 78 通过。启动时警告 22 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 18 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 14, tree PASS 14; regress 0; newly loading 0），这些文件的警告 23 -> 5。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（二）

- `d/hangzhou/npc/mameipo.lpc` 媒婆：`return "这么小就想找对象啦,嘻嘻.\n", i = 0;` 逗号把 `i = 0` 并进 return，未满 16 岁返回 0，提示永远不出；拆成两句（tiexuejianghu 同码一并修）。
- `u/lxh/emoted.lpc`：删去空的 `if (!channel_emote) {}`。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 215 -> 0（`scripts/lpc_warnings.py fys` 重扫：8742 个文件可编译，0 条警告）。

**真问题：**
- `d/heimuya/npc/laozhe.lpc` 黑木崖老者：`init()` 里留着调试语句 `sprintf("%s \n", what);`，`what` 是物件，本驱动的 `sprintf` `%s` 遇到物件直接报错（`Bad argument`），所以每次有人进房间 `init()` 都中途出错，老者的招呼 `greeting` 从不触发。删掉这句。`u/xxy/room/heimuya/npc/laozhe.lpc`（巫师目录的副本）同样删去，并把 `command("give yancao to", me)`（参数太多，文件编译不过）改成正本的写法。
- `d/jinling/obj/y.lpc` 清水豆腐：同时继承 `F_FOOD` 和 `F_LIQUID`，两者都有 `init()`，后继承的 `liquid` 赢，`eat` 指令从未加上，这块豆腐吃不了。叶子里加 `init()` 依次调用 `food::init()` 和 `liquid::init()`。
- `include/globals.h`：`#define BANNED_SITES "/adm/etc/banned_sites";` 多一个分号（所以 `band.lpc` 们各自重定义一遍）。去掉分号，`u/lxh/globals.h` 同改。
- `u/xxy/ask.lpc`：`ob->query("name" == obj->query("who2/name") && ...)` 括号错位，改成 `ob->query("name") == ...`；删去未用的 `inquiry`。`u/temp/qiaofu.lpc`：`message_vision(...)` 后的分号被挪进了行尾注释，补回（这两个文件原先都编译不过，现在能编译）。

**其余：**
- `toolkit_fix.sh` 删去 39 个多余的 `inherit`（NPC 叶子再继承 `F_SKILL`/`F_CLEAN_UP`、房间再继承 `F_SAVE`/`ROOM` 等，`std/char/npc.lpc` 已经带上）——这是 65 条 `Redeclaration` 和 13×N 条 `inherited from both` 的来源。
- `d/zhongzhou/npc/renwu.h`：`renwu4` 表出现两次，第一份是残缺的半截粘贴（后一份的初始值本来就覆盖它），删去第一份。
- `d/meizhuang/bingqiku.lpc`：`mount/dao/jian/zhang/ding` 先声明一次、再带初值声明一次（`jian` 还第三次），保留带初值的那份，行为不变。
- `include/armor.h`、`include/weapon.h` 都定义 `FINGER`（含两者的 16 个文件都不用它），各自在定义前 `#undef FINGER`，后包含者赢，与原先一致。
- `daemon/skill/old/hubo.lpc`（旧技能，`ITEM`+`SKILL` 双继承）：点名 `clean_up()` 的赢家 `skill::clean_up()`。

验证：改动文件及包含改动头文件的对象共 1176 个，HEAD 与工作树各用新进程载入：1054 -> 1057 通过，regress 0（新载入 3 个）。删除声明审计 0 项待看。1176 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：87 个技能文件 `int power_point() { return 1.75; }` / `int hard_point() { return 2.5; }`，浮点经 int 返回被截成 1、2（FluffOS 移植以来一直如此，原 MudOS 下保留小数）。`feature/skill.lpc` 的 `query_skill()`（power_point 作有效等级系数）和学习上限（hard_point 平方作学习点门槛）都读这两个值，`point` 经 call_other 拿到的值不会再被截断。改成 `float` 返回值后恢复原设计数值：**游戏可见**——hard_point 1.75 的技能学习门槛约为现在的 3 倍，power_point 大于 1 的技能有效等级相应提高。改动的 74 个对象新进程各载入一次，无回退。
- 2026-10-14（补）：上一条把 `power_point`/`hard_point` 改成 `float` 后，有两处调用会把浮点带进整数：
  - `feature/skill.lpc` 的 `query_skill()` 里 `s += skills[...] * point`，`s` 在运行时变成浮点，`query_skill()` 返回浮点。
  - `cmds/usr/fenpei.lpc` 的 `all = ... * hard * hard`，提示里的点数会带六位小数。
  - 现把 `point`/`hard` 声明为 `float`，乘积用 `to_int()`。
  - 运行时探针：一个 NPC 的 sword 100、duanjia-sword 100（power_point 1.3），`query_skill("sword")` 返回整数 180（100/2 + 100×1.3）。
  - 另：载入时 `emoted` 恢复存档报 `Invalid utf8 string while restoring emote`，待查。
- 2026-10-14：`data/emoted.o`（表情守护进程的存档）整个还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string while restoring emote`，表情守护进程启动时一个表情都没有。现按 GB18030 转码，丢掉原文件里几个被截断的半个字符。转码后 `adm/daemons/emoted` 载入不再报错（HEAD 上报错）。

- 2026-10-14：8 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：9 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`greeting()`、`player_win()`、`recognize_apprentice()`。新进程比对 HEAD 与工作树：18 个对象，新增载入 18，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：18 个对象，新增载入 18，回退 0。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

19 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。2 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。2 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`tianyu-qijian/kuangwu`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`six_finger`→`six-finger`（`/daemon/class/dali/six-finger/star`）；`yuxuan-guizheng`→`yuxuan-guizhen`（`/daemon/class/xiake/luoyan-sword/luoyan`）。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`data/npc/` 31 个、`data/` 1 个：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事要离开时报错，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

21 个文件、29 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/clone/weapon/changjian`、`/d/suburb/xkx/shaolin/obj/changjian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 10 个（10 个原来载入不了），没有退步；其余 11 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `for (int i ...)` 的循环变量在循环外还在用（2026-10-18，KB 04 §6.12）

当铺／商店的 `do_buy()` 写成 `for (int i = 0; ...) if (...) break;`，循环一结束又读 `if (i == sizeof(inv))`。FluffOS 里 `for` 头里声明的变量只在循环内有效，所以 `Undefined variable 'i'`，整个房间（NPC）载入不了，当铺根本进不去。把 `i` 声明挪到函数开头（`int i, index;`），循环改成 `for (i = 0; ...)`：`std/room/hockshop.lpc`。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`WAIST` → `/std/armor/waist`（9 个文件）、`WRISTS` → `/std/armor/wrists`（7 个文件）、`SURCOAT` → `/std/armor/surcoat`（5 个文件）、`SHIELD` → `/std/armor/shield`（5 个文件）、`GUN` → `/std/weapon/gun`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：27 个里 0 个通过，其余 27 个还有别的错误（`d/chengdu/npc/obj/huwan.lpc`：Undefined variable 'TYPE_WRISTS'；`d/chengdu/npc/obj/huyao.lpc`：Undefined variable 'TYPE_WAIST'；`d/chengdu/npc/obj/shield.lpc`：Undefined variable 'TYPE_SHIELD'……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 35 个对象设了本库没有文件的武功（40 个名字，最多的是 `huashan-sword`、`liumai-shenjian`、`finger`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 26 个通过，其余 4 个停在别的错误上（`d/city2/npc/liling2`：*No program in object '/d/city2/npc/liling2'!；`d/dali/npc/duanyanqing`：*No program in object '/d/dali/npc/duanyanqing'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/chengdu/dao` 的 `south`：`dadao1` → `dadao2`；`/d/thd/nebeach2` 的 `northwest`：`foot` → `hill_foot`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/unique`（宏 `F_UNIQUE`）←haiyang2，22 个对象继承它，抽样 6/10 载入；`/inherit/weapon/stick`（宏 `STICK`）←wmkj，17 个对象继承它，抽样 9/9 载入；`/inherit/weapon/mace`（宏 `MACE`）←wmkj，11 个对象继承它，抽样 10/10 载入；`/std/weapon/rake`（宏 `RAKE`）←xyj451，4 个对象继承它，抽样 4/4 载入；`/inherit/weapon/bow`（宏 `BOW`）←wmkj，1 个对象继承它，抽样 1/1 载入；`/std/weapon/archery`（宏 `ARCHERY`）←xyj451，1 个对象继承它，抽样 1/1 载入；`/std/weapon/unarmed`←wuhanzhan，6 个对象继承它，抽样 6/6 载入；`/inherit/room/pigroom`←haiyang2，4 个对象继承它，抽样 4/4 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 3 处、2 个文件：`tiaji-jian`→`taiji-jian`（2 处）、`sanyang_shengong`→`sanyang-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 3 处、3 个文件：`::setup()`（3 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/d/chengdu/skill/jinshe-jianfa.lpc`、`/d/heimuya/npc/obj/pixie-jian.lpc`、`/d/quanzhen/skill/haotian-zhang.lpc`、`/d/quanzhen/skill/quanzhen-jian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 2 个：`d/city2/npc/liling2`、`d/dali/npc/huangmei`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 4 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `TYPE_WRISTS`、`TYPE_WAIST`、`TYPE_SHIELD`、`TYPE_SURCOAT`，用到它们的物件（名单里 8 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 8 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## kzznpc.h 兜底（2026-10-19，KB 06 §7.267）

`d/yangzhou/npc/xiaohuoji`（听萧伙计）没有存档，`restore()` 后 `set_name(0, ...)`，载入时报 `Bad argument 1 to set_living_name()`。`include/kzznpc.h` 在 `restore()` 之后加了兜底：存档里没有名字或 id 时，名字取存档文件名，id 取物件文件名。100 个 `kzznpc` NPC 全部载入（HEAD 99 个），没有退步。姊妹档案 `tiexuejianghu` 的 NPC 存档就是从这里的 `data/npc/` 补回去的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `d/thd/hall.lpc` 调用的留言板 `/u/aug/thd/thd_b` 改成区域里的 `/d/thd/thd_b`，留言板的 `location` 同步改成 `/d/thd/hall`（作者自己留在注释里的写法）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：27 个未使用的局部变量，1 处函数返回类型改成与基类一致。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/legato/obj/skeleton.lpc`（2 个）、`/u/xxy/city2/npc/zhengmen.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 3 个文件：`/d/heimuya/ren.lpc`、`/u/mool/kid.lpc`、`/u/xxy/room/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 3 个原来载入失败、现在载入，没有退步。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 8 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xianhe.lpc`、`/d/hainan/npc/xiaohe.lpc`）。改动：`/d/hainan/npc/xianhe.lpc`（3 处）、`/d/hainan/npc/xiaohe.lpc`（3 处）、`/d/xxy/npc/train1.lpc`（1 处）、`/d/zhongzhou/yanguan.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/obj/inherit/char/npc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 72 个存档共 86 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/guild/色魔帮.o`（1 处）、`/data/npc/liumang.o`（1 处）、`/data/npc/京千灵.o`（8 处）、`/data/npc/何红药.o`（1 处）（等共 72 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 13 条注册（8 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/obj/inherit/misc/fboard.lpc`（`do_list`）、`/d/taishan/npc/xiao-fan.lpc`（`do_buy`、`do_list`）、`/d/yandang/npc/kongmin.lpc`（`do_sell`）、`/d/yangzhou/npc/aqingsao.lpc`（`do_sell`）、`/d/yangzhou/npc/xiaofan.lpc`（`do_sell`）、`/d/zhongzhou/biwuchang.lpc`（`do_close`、`do_open`、`do_take`）、`/d/zhongzhou/biwufall.lpc`（`do_close`、`do_open`、`do_take`）、`/d/zhongzhou/npc/xiaofan.lpc`（`do_sell`）。最多的函数名：`do_sell` 4 处、`do_list` 2 处、`do_close` 2 处、`do_open` 2 处、`do_take` 2 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`clone_object`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（item_desc 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/zhongzhou/biwuchang.lpc`:`look_shelf`、`/d/zhongzhou/biwufall.lpc`:`look_shelf`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 7 个文件里有 10 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/promotion`、`nosave/PURGE` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/jail_b`；`/d/city2/jail.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 4 行只含这个指针的行（`"剃度"	: (: ask_join :),` `"出家"	: (: ask_join :),` `"shelf": (: look_shelf :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 2 处（2 个文件）：拼名字的赋值 2 处。例：`name[2..3]` → `name[1..1]`（`/d/emei/npc/miejue.lpc:106`）；`name[0..1]` → `name[0..0]`（`/d/emei/npc/tobebonze.h:35`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/daemons/logind2.lpc:555`）；`if ((strlen(name) < 4) || (strlen(name) > 16)) {`（`/d/zhongzhou/npc/hfh.lpc:39`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

## 金毛鼠 mouse 缺分号无法加载（2026-10-27，KB 04 §6.25 Also）

`open/wjw/mouse.lpc`：`inherit NPC` 与 `set_name(...)` 之后每句丢了 `;`（`) set("race"`、`setup()`、`set_leader(who) message(...)`）。同目录手足 `haozi.lpc` 完好；用 `haozi` 覆盖并把首 id 改回 `"mouse"`（fys / tiexuejianghu）。证明：HEAD 加载失败；改后加载成功，id 为 mouse/laoshu/lao shu。

## wei/duanyanqing #me->move 无法加载（2026-10-27，KB 04 §6.25 Also）

踢人分支写成了 shell 风格的 `#me->move("/d/city/...")`，驱动报 `Unknown preprocessor directive: #me`，对象无法编译。改回 `me->move(...)`（踢出门外的提示需要这次 move）。本库改动：`d/chengdu/npc/wei.lpc`、`d/dali/npc/duanyanqing.lpc`。证明：HEAD 加载失败；改后加载成功。

## 更夫 gengfu sym_dee 缺戌无法加载（2026-10-27，KB 04 §6.25 Also）

`d/jinling|suzhou|suzhou/qinyun/npc/gengfu.lpc` 的地支数组写成 `"酉",","亥"`，丢了 `戌`，驱动在「亥」上报 `Illegal character`。改回 `"酉","戌","亥"`（手足 tiexuejianghu 已正确）。证明：HEAD 加载失败；改后三处均加载成功。

## wife inquiry ask_me 前置声明（2026-10-27，KB 04 §6.25 Also）

`d/chengdu/npc/wife.lpc` 在 `create()` 里写 `"参茶": (: ask_me :)`，但 `int ask_me` 定义在后面，驱动报 `Undefined variable 'ask_me'`。在 inherit 后补 `int ask_me(object me);`。证明：HEAD 加载失败；改后加载成功。

## 铁罗汉 tie-luohan 下标丢失无法加载（2026-10-27，KB 06 §7.348 Also）

`d/chengdu/obj/tie-luohan.lpc`：`snamei` / `skill_statussname` / `hp_statusstr` 等下标括号丢失，缺 `sname = keys(...)`，`me` 未赋值，另有多余的 `return notify_fail` 使技能复制不可达。按手足技能复制形重写 `accept_fight` / `renewing`（保留 FY 的 kee/gin/force）。证明：改前加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## sandboy/map.lpc 非 LPC 地图改名（2026-10-27，KB 03 §4.2 item 8 Also）

`d/sandboy/map.lpc` 是纯框线房间示意图，没有一行 LPC；`.c`→`.lpc` 批量改名时带进来，驱动报 `Illegal character`。手足 tiexuejianghu 已改为 `.txt`，库内无引用。改名为 `map.txt`。证明：`file_size("/d/sandboy/map.txt")`>0，`.lpc` 为 -1。

## yangzhou waiter vendor_goods 多余冒号（2026-10-27，KB 04 §6.25 Also）

`d/yangzhou/npc/waiter.lpc` 的 `vendor_goods` 写成 `"包子": __DIR__ "obj/baozi": 1`，第二个 `:` 非法，驱动报 `syntax error, unexpected ':'`。`F_VENDOR` 要的是名→路径（手足 aqingsao）。去掉五个货品末尾的 `: 1`。证明：HEAD 加载失败；改后加载成功，goods 五键。

## old kuaihuo/songyang 缺右括号（2026-10-27，KB 04 §6.25 Also）

`daemon/skill/old/kuaihuo-zhang.lpc`、`songyang-zhang.lpc`：`if (ob = me->query_temp("weapon")` 丢了 `)`，后面多一个 `}` 把后续函数嵌进去，驱动报 `unexpected L_RETURN`。用同库 `daemon/skill/<name>.lpc` 的 `valid_learn` 起至文件尾覆盖。证明：HEAD 加载失败；改后加载成功。

## set_max_items 补进 move（2026-10-27，KB 04 §6.16 Also）

`d/obj/misc/hualan.lpc`、`vase.lpc` 调用 `set_max_items`，但本库 `feature/move.lpc` 没有该函数（手足 sjsh / aoxiangtianji 有），物件无法编译。在 `set_max_encumbrance` 旁补上 `max_items` 默认 10 与 `set_max_items` / `query_max_items`。证明：HEAD 加载失败；改后花篮与花瓶均加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## dou_peng inherit F_CLOTH（2026-10-27，KB 04 §6.25 Also）

`d/thd/obj/dou_peng.lpc` 写 `inherit F_CLOTH` / `setup_cloth()`，但本库 `armor.h` 没有 `F_CLOTH`（那是 dfgs2 的 feature 装甲 API），驱动报 `unexpected L_IDENTIFIER`。改为本库的 `inherit CLOTH`，保留名称与护甲 5。证明：HEAD 加载失败；改后加载成功。

## force 缺 hit_ob 桩（2026-10-27，KB 06 §7.259 Also）

本库 `std/force.lpc` 把内功钩子叫 `force_action`，但 `daemon/skill/old/jiuyin-shengong`、`xiake-shengong` 仍写 `::hit_ob(...)`，驱动报找不到父类 `hit_ob`。补 `hit_ob` 返回 0（老驱动空父调用的值）；战斗仍走 `force_action`。证明：HEAD 加载失败；改后两技能均加载成功。
