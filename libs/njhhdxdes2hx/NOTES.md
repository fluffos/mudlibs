
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/xkx 衍生的校园题材构建版。WASM 修复：修好了 check_legal_name() 里 §8.1 长度界限没减半的部分和残留的 i%2==0 字节步进门槛（is_chinese() 本身已经是正确的码点判断）；修复了 feature/team.lpc 里 §7.47 的 origin()==ORIGIN_LOCAL/ORIGIN_CALL_OUT（整数 vs 字符串）问题；修复了 §7.48 的跨档案非法 private 呼叫（treemap.lpc 的 _query/_set/_delete、action.lpc 的 continue_action、attack.lpc 的 attack——private 改成 protected）；修复了 §7.49 的 valid_write() 存档扩展名不匹配导致 quit 失败报"Denied write permission"。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。用真实中文名字（秦风）完整注册+look/score/quit 在 WASM 下全程验证，管理员 update 指令也已验证。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身，本轮原生 driver（端口 40194）走完了移
动、留言板、钱庄 NPC 观察、战斗、以及一轮完整的死亡→复活验证。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三类真实
bug**：

1. **全新发现：新角色食物/饮水初始化永远为 0**（现场一注册完就能
   看到 `score` 里食物/饮水两条进度条完全是空的 `□□□□...`）。根
   因：`adm/daemons/logind.lpc` 的 `init_new_player()` 在角色刚创
   建、还没有任何随身衣物时就调用了
   `user->set("food", user->max_food_capacity());`，而这份档案的
   `feature/damage.lpc` 把 `max_food_capacity()`/
   `max_water_capacity()` 定义成 `query_weight() / 200`——新角色此
   时负重为 0，除出来自然永远是 0。这不是 §8.9 的"查询了错误对象
   的 age"变体（这里压根没有 age 判断），而是一个新的、初始化顺
   序错误的 bug：食物/饮水的容量计算依赖一个此刻还不存在的状态
   （随身重量）。已把这两行从 `init_new_player()` 挪到
   `enter_world()` 里"给新手穿上衣服"（`cloth->wear()`）**之后**，
   这时负重才是真实值，并加了 `!user->query("food")` 之类的判断避
   免误伤已有存档的老角色。现场验证：修复后新角色 `score` 食物/饮
   水两条都是满格。
2. **§7.7 的又一次实例（已归档，非新类别）：留言板对象因为存档解
   码失败，导致 `capitalize(query("id"))` 崩溃**——`look` 一进饮风
   客栈就报 `执行时段错误：*Bad argument 1 to capitalize() Expected:
   string Got: 0.`，调用栈和这个 bug 类在 `jyqxc` 上发现时的一模一
   样：`feature/name.lpc` 的 `short()` 无防护地对 `query("id")` 调
   用 `capitalize()`。`data/board/common_b.o` 存档本身是一份从未转
   码、留言内容仍是原始 GBK 字节的旧存档（正文一堆乱码，但顶层字
   段名本身是 ASCII，能正常解析出 "id":"board" 之类的键），怀疑是
   `restore_object()` 在解析内嵌的乱码字节时整体失败、按驱动语义把
   `dbase` 清零，抹掉了 `create()` 里刚设好的 `id`。按 AGENTS.md
   §7.7 的既定结论（重新整理几十份旧存档超出范围，修共享崩溃点才
   是正确做法）在 `capitalize()` 调用处加了 `stringp()` 判断，现场
   确认 `look` 不再崩溃（留言板显示退化成 `文件路径(?)` 这种不好
   看但不崩溃的占位符，符合预期）。
3. **第 14 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（`DEATH_ROOM` 直接指向白无常所在房间，其
   `north` 出口可达黑无常）已按标准修法拆分。这次 `REVIVE_ROOM`
   （`/d/snow/temple`）和 `DEATH_ROOM` 指向的文件都确认存在——**不
   是**上一轮 `fys` 那种宏指错文件的情况。现场用一个近乎无法被真
   正打赢的强力 NPC（安记钱庄老板"安惜迩"，`combat_exp` 高达
   200000）一击致命触发死亡，然后完全不打断地等待白无常五段对话
   （含下面提到的错字修复）全部播完，确认 `reincarnate()` 成功、
   角色正确落地"城隍庙"，`score` 恢复正常可玩状态。

**顺手修复几处确认为原始压缩包本身损坏的字符**（均用 Python 直接
读取 raw 归档字节核实过，不是转码流程引入的，比对本项目另外 12+
个不同血统档案的同款白无常/黑无常对话逐字印证）：
- 白无常/黑无常对话"阁上册子"应为"合上册子"（GBK 字节层面确认
  "阁"字本身就在原始档案里，推断是原作者当年手误——"阁"和"合"字
  形相近容易混淆）。
- `d/snow/npc/fist_trainer.lpc` 两处台词里混进了游离的反斜杠字节
  （"说来惭愧\，" "不许\和来这里的客人"），编译时报
  `Unknown escape sequence`，已删除多余的 `\`。
- `d/snow/npc/annihir.lpc`（钱庄老板"安惜迩"）同样两处台词里混进
  了游离反斜杠（"古怪的武功\，所" "也许\是你的错觉"），一并修复。

**主动检查确认不是 bug 的项**：`command_hook`
（`feature/command.lpc`）此前已经是 `nomask`；全文搜索未发现
`MESSAGE_D->` 未加防护的调用；`d/snow/npc/guard.lpc`（淳风武馆门
房"刘安禄"）战斗中反复"忽然像是想起什么，急忙收招"，读代码+游玩
确认这是角色设定好的"只对本派弟子认真出手"（`accept_fight()`
风格逻辑），不是伤害计算 bug，属于内容设计。

**完整游玩记录**：
1. 用真实中文名字"秦风"（id `qinfeng`）注册成功，落地"饮风客栈"
   （雪亭镇），场景里有真正可读的留言板（原本因 §7.7 崩溃，修复
   后能正常 `look`/`read`）、店小二、以及一个客串 NPC"孙悟空"。
2. 移动：饮风客栈→广场→雪亭镇街道→淳风武馆大门→安记钱庄，沿途
   场景描述、出口、NPC 列表均正常渲染。
3. 战斗测试：`wimpy 0` 后先后尝试"旅客"（战斗力低，几回合分不出
   胜负）、"刘安禄"（门房，读代码确认了"不真打"的设计）、最终用
   "安惜迩"（`combat_exp` 200000）一击致命，成功触发完整的死亡→
   复活流程。
4. 死亡→复活验证（如上文详述）：完全不打断地等待白无常五段对话
   播完，确认修复后的资源软锁死 bug 不再复现，角色正确落地"城隍
   庙"。

**结果**：整个测试会话（含一轮死亡复活循环、两次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录。测试角色存档
（`data/{login,user}/{q/qinfeng,s/shenmu}.o`，后者是命名冲突后弃
用的第一次尝试）保持未跟踪；六处 `.lpc` 代码改动均已用 formatter
校验（`{"errors":0}`）。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 23 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100, this time on the
universal `ROOM` base class (`/std/room`) instead of just boards: rooms
inheriting `ROOM` had a redundant, harmful `replace_program(ROOM);` call
right after `inherit ROOM;` in `create()`, setting a permanent "pending
replace" flag that crashes the object the first time anything binds a
closure to it. This lib had **1,703 live occurrences** (survey-ranked
#86 of 166 candidates >=100). Fixed with the sweep's binary-mode script
(`fix_710_room.py`, 1,439 files) plus **a new irregular shape not seen
in prior batches**: 261 files under `d/road/*.lpc` share the call on
the SAME LINE as `setup()` (`setup(); replace_program(ROOM);`, one with
no space — `setup();replace_program(ROOM);`), which the strict
standalone-line script correctly leaves alone; hand-fixed via a
targeted byte-replace keeping `setup();` and dropping the trailing
call. Also fixed two room-building-tool copies
(`obj/roommaker.lpc`, `obj/wizard/roommaker.lpc`, the simple
`str += "...replace_program(ROOM);..."` string-builder variant) and a
THIRD, different kind of factory: `d/heimuya/midao/mud/room/
flatroom.lpc`, a maze/area room-code generator whose `fprintf(out,
"replace_program(ROOM); \n}\n")` line baked the same bug into every
auto-generated maze room file — fixed the same way (drop the
`fprintf` call emitting the redundant line). `git diff --numstat`
totals (264 insertions, 1703 deletions) match the survey's
live-occurrence count exactly (1439 + 261 + 3 tool-template edits).
No `work/data/` room-source false-negative found. Verified via a clean
`build-debug` boot (zero "cannot replace"/"cannot bind" `debug.log`
lines, port 40194 listening) plus a live admin login
(`fluffos`/`Mud@2026`) — landed at 饮风客栈, `look`/`quit` both worked
normally, `debug.log` stayed clean throughout. Incidental admin
save-timestamp drift from the spot-check reverted before committing.

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

## §10.7 深度功能测试第二轮 (2026-09-01): 拜师/门派、店铺交易、邮件、§7.19 排查

本轮刻意挑选上一轮（2026-08-04）明确跳过的角度：拜师/门派系统、真
正的买卖交易（不只是被动观察 NPC），以及邮件系统；同时按 AGENTS.md
§7.19 的形状专门排查这份档案是否有 NPC `init()` 里无条件呼叫
`enable_player()`/`enable_commands()` 导致首次访问某房间时同一调用
栈重入触发 "Too deep recursion" 的隐患。全程使用原生 Python socket
脚本（未用 `scripts/tmux_mud.sh`），真实中文名字"周文"（id
`wenzhouqi`）注册。

**§7.19 静态排查（未发现漏洞）**：`feature/command.lpc::enable_player()`
只从 `std/char.lpc::setup()`（NPC/玩家 `create()` 阶段调用一次）和
`feature/damage.lpc::revive()`（合法的"昏迷→复活"重新启用流程，配对
`disable_player()`）调用；`std/char/npc.lpc`本身不定义 `init()`，各
NPC 自己的 `init()`（如 `herbalist.lpc`、`daemon/class/swordsman/
master.lpc`）只做 `::init(); add_action(...)`，`::init()` 解析到
`feature/attack.lpc` 的自动索敌逻辑，与 `enable_player()` 无关。本轮
实际游玩中新访问了雪亭镇街道×3、淳风武馆大门/教练场/大厅、桑邻药
铺、丰登当铺、谷物加工厂等多个"首次进入即有活体 NPC"的房间，
`debug.log` 全程未出现任何 "Too deep recursion"。结论：这份档案目前
没有 §7.19 的漏洞形状。

**拜师/门派系统测试（此前完全未测试的角度）**：`cmds/std/
apprentice.lpc`（`apprentice <目标>` 指令，档名即指令名）+
`feature/apprentice.lpc`（`create_family`/`recruit_apprentice`/
`is_apprentice_of` 等 dbase 逻辑）是全局挂在 `CHARACTER` 上的完整拜
师机制。找到 `淳风武馆大厅`（`d/snow/schoolhall.lpc`）的
`daemon/class/swordsman/master.lpc`（柳淳风，`封山剑派`）——这一支
`attempt_apprentice()` 只检查 `cor`/`cps` 属性门槛，不需要额外任务
道具，是本档案里最容易直接验证整条链路的一个。现场 `apprentice
master` 一次性走完"表态拜师→师父直接 command 触发 recruit→
`recruit_apprentice()` 写入 `family` dbase→称号/score 更新"全链路，
`score` 正确显示"封山剑派第十四代弟子"、"你的师父是柳淳风"，
`debug.log` 全程干净。也顺手验证了 `apprentice cancel`（无 pending
时正确 notify_fail）。**结果：拜师系统工作正常，未发现 bug。**

**店铺交易测试（买+当，此前只观察未交易）**：
1. 桑邻药铺（`herbalist.lpc`，`F_VENDOR`/`feature/vendor.lpc`）：
   `list` 指令正常列出六项商品及价目（`do_vendor_list()` 用
   `goods[key]->query("value")` 这种"字符串路径当 call_other 目标"
   的写法，现场确认能正常触发按需装载，不崩溃）；`buy 金疮药 from
   yang` 因新角色身无分文被正确地 notify_fail "你的钱不够"，未崩
   溃。
2. 丰登当铺（`d/snow/hockshop.lpc` + `std/room/hockshop.lpc`）：
   `value cloth`/`pawn cloth` 均因布衣一文不值被正确拒绝
   （"布衣一文不值。"/"这样东西不值钱。"）；`pawn`（查询已当物品，
   无参数）正确回报"你目前没有典当任何物品。"；`redeem 0`（赎回不
   存在的当票）正确回报"你要取回什么物品？"。均是设计内的正常边
   界拒绝，不是 bug。
3. 安记钱庄（银行 `convert`/`cun`/`qu`/`check`）：无参数/无存款情
   况下均返回正确的用法提示或"您在敝商号没有存钱。"，同样干净。
两处商店的门（"红漆大门"/"店铺门"）默认关闭，需要先 `open door`
才能进入——这是正常的房间机制，不是 bug（第一次不知道要开门时
"east"会提示"你必须先把...打开！"，行为符合预期）。

**邮件系统检查（结果：未对玩家开放，非 bug）**：`obj/mailbox.lpc`、
`obj/misc/mailbox.lpc`、`adm/daemons/network/mail_serv.lpc` 等邮件基
础设施文件存在，但全档案 `cmds/` 下没有任何 `mail` 指令文件，
`d/` 下也没有任何房间把 mailbox 对象放进 `"objects"`。也就是说邮件
系统从未真正连接到玩家可用的指令或场景——这是内容/部署缺口，不在
本项目"只修程序 bug"的范围内，如实记录，不动它。

**发现并修复一处真实 bug（AGENTS.md §7.11 同型，第 N+1 例）**：用
`(admin)` 权限的 `call` 指令（`cmds/arch/call.lpc`）对在线玩家对象
执行 `call wenzhouqi->add_money(coin,1000)`（用来给测试角色发钱，
以便完整走一次购买流程）时，驱动直接报出未捕获运行时错误：

```
执行时段错误：*Wrong permissions for opening file /log/nosave/CALL_PLAYER for append.
"No such file or directory"
```

根因：`call.lpc` 每次对另一个玩家对象执行 call 都会无条件
`log_file("nosave/CALL_PLAYER", ...)` 记审计日志，而
`adm/simul_efun/file.lpc::log_file()` 是裸 `write_file(LOG_DIR +
file, text)`，完全没有调用同文件里紧接着定义的 `assure_file()`
——`/log/nosave/` 这个目录本来就没有随档案打包，第一次真正命中这
条日志路径时必然崩溃。这正是 AGENTS.md §7.11（"Missing runtime
directories and the silent write_file abort"）已经归档的经典形状
（`zjmudhell`/`xajh2`/等多个不相关血统都独立踩过一样的坑），只是
这次的触发点是 `call` 指令自己的审计日志，不是 registration 流程。
按 §7.11 的标准修法在共享的 `log_file()` 里补上
`assure_file(LOG_DIR + file);`——由于 `assure_file()` 在文件里定义
在 `log_file()` 后面，作为 simul_efun 单文件内的前向引用需要一个
函数原型声明，否则编译报 "Undefined function assure_file"（已加
`void assure_file(string file);` 原型声明一并解决）。修复后重启驱
动，用两个并发连线（测试角色在线 + admin 连线）重放同一条 `call`
指令，确认 `add_money("coin", 1000) = 0` 正常返回、`log/
nosave/CALL_PLAYER` 被成功创建并写入、`debug.log` 全程干净。

**改动文件**：`work/adm/simul_efun/file.lpc`（2 行改动：`log_file()`
内加 `assure_file()` 调用 + 文件顶部加前向原型声明）。测试角色存档
（`data/{login,user}/{w/wenzhouqi,z/zhouwen}.o`，后者是命名规则试
错留下的半成品）保持未跟踪；`data/{login,user}/f/fluffos.o` 的
admin 登入时间戳漂移已在提交前用 `git checkout --` 撤销。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 106 file(s) `inherit F_SSERVER;` and no header defines it (104 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/fangtang.lpc`, `d/road/rdktojd0.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`std/weapon/throwing.lpc`、`std/weapon/fork.lpc`、`std/weapon/hook.lpc`、`std/weapon/qin.lpc`、`std/weapon/whip.lpc`、`std/weapon/pestle.lpc`、等共 17 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py njhhdxdes2hx --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 842 个 `.lpc` 和 5 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：803 -> 803 通过，无回退；改过的头文件的 84 个包含者 81 -> 81 通过。启动时警告 11 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：仓库顶层 `.gitignore` 的 `libs/*/work/**/log` 本为运行日志而设，却把存档里名为 `log` 的源码目录也挡在版本库外（站点下载缺这些文件）：`d/heimuya/log/`（巫师补丁包：文件清单与改过的技能、命令副本，41 个文件）。已 `git add -f`（KB 02 §2.2）。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 6 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 6 个文件，HEAD 与工作树各载入一次无回退（6 objects; HEAD PASS 6, tree PASS 6; regress 0; newly loading 0），这些文件的警告 10 -> 4。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：d/heimuya/log/xkx/inherbit/weapon/gou.lpc d/heimuya/log/xkx/inherbit/weapon/ji.lpc d/heimuya/log/xkx/inherbit/weapon/qian.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 26 处，未用局部变量 2 个）加手工收尾，能编译的文件警告清零。改动的 47 个对象 HEAD 与工作树各载入一次：HEAD PASS 46，tree PASS 46，regress 0。

- `item_desc`/`inquiry` 里的 `(: "字符串" :)`（函数指针只返回一个字符串常量；`taolin.lpc` 两份、`d/city/npc/walker.lpc`、`shangshu/kefang.lpc`、`street3.lpc`）改成字符串本身，显示不变。
- `d/jingcheng/npc/kid2.lpc`：候选糖人名单 `string *name` 与选中的 `string name = comm_name();` 同名，后面的代码读的是选中的那个；名单改名 `name_list`。
- `d/guanwai/yizhan.lpc`：同一文件先 `#define BASE_MONEY 1000` 再 `#define BASE_MONEY 300`，生效的是后者，删去前者。
- 函数体后多余的 `};`（8 个文件）、招式表后多余的 `;`（`u/hacky` 的两个剑法）；`daemon/skill/pixie-jian/shuangda.lpc`、`u/hacky/d/skill/skill/hubo.lpc` 用 `lpc_name_winner.py` 写明 `clean_up()`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。4 个文件 4 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：8 个存档文件（留言板 2 个、玩家/登录存档 6 个；`data/board/common_b.o`, `data/board/lasa_b.o`, `data/login/c/collin.o` …）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-14：1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/d/jingcheng/npc/miaozhu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。3 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

36 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/class/shaolin/du`、`/daemon/class/shaolin/du`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

补（同日）：上面两份 `du.h` 的修改当时漏提交了（提交时只取了 `.lpc`），现补上；`du-e1` 两份没有 `#include <ansi.h>`，`du.h` 里的 `HIR`/`NOR` 成了未定义标识符，一并补上。HEAD 上 `du-*` 8 个文件一个都载入不了，伏魔圈（`/d/shaolin/fumoquan`）的渡难、渡厄、渡劫三僧从未出现；现在 8 个全部通过。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

42 个文件、53 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/tangmen/obj/jinyi`、`/d/yueyang/npc/obj/tiejia`、`/d/tangmen/obj/skirt`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 41 个，改后 41 个（0 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`cmds/arch/purge.lpc`、`cmds/std/suicide.lpc`、`include/net/ftpdsupp.h`、`obj/token.lpc`。`token` 是帮派领袖信物；`suicide` 是自杀指令；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：3 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（8 个名字，最多的是 `xiake-force`、`xiake-strike`、`xiake-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 9 处、4 个文件：`stuff`→`staff`（6 处）、`shenghuo-shenggong`→`shenghuo-shengong`（2 处）、`chaos-steos`→`chaos-steps`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/latemoon/in_room/flower1.lpc` 的 `north` 出口：`corridor7` → `backroom`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/suzhou/npc/kiss.lpc` 的 `set("vendor_goods", ([ "路径", ... ]))` 是只有键没有值的映射，语法错误；店主代码读的是数组，改成 `({ ... })`。

逐个载入与 HEAD 对比，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 8 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/class/shaolin/bak/dao-guo.lpc`、`/d/huashan/q.lpc`（2 个）、`/d/jingcheng/npc/obj/qin1.lpc`、`/d/taohua/yinggu.lpc`、`/d/taohua/zhaozhe.lpc`、`/daemon/class/shaolin/bak/dao-guo.lpc`、`/u/hacky/d/yueyang/npc/obj/box.lpc`、`/u/hacky/d/yueyang/npc/obj/guiyuan.lpc`。修后与 HEAD 逐个对比载入：这 8 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/obj/example/math_master.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/std/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 3 处）。改动：`/d/suzhou/npc/meipo.lpc`（1 处）、`/d/taohua/andao.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/daemon/class/ronin/master.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 6 个存档共 6 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/userbak/d/dirrid.o`（1 处）、`/data/userbak/h/hacky.o`（1 处）、`/data/userbak/l/list.o`（1 处）、`/data/userbak/p/pps.o`（1 处）（等共 6 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 16 条注册（11 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/class/tieflag/master2.lpc`（`give_quest`）、`/d/heimuya/npc/master2.lpc`（`give_quest`）、`/d/heimuya/npc/xiaoer.lpc`（`do_buy`）、`/d/heimuya/qlt2.lpc`（`do_2`）、`/d/jingcheng/chanf.lpc`（`do_balance`、`do_convert`、`do_deposit`、`do_loan`等）、`/d/taishan/npc/xiao-fan.lpc`（`do_buy`、`do_list`）、`/d/tieflag/npc/master2.lpc`（`give_quest`）、`/d/village/lordhouse3.lpc`（`do_push`）、`/daemon/class/tieflag/master2.lpc`（`give_quest`）、`/obj/npc/smith.lpc`（`do_buy`） 等共 11 个文件。最多的函数名：`give_quest` 4 处、`do_buy` 4 处、`do_2` 1 处、`do_balance` 1 处、`do_convert` 1 处。没有动（读过）：`/d/suzhou/wmci.lpc` 的 `do_ketou`（对象本身编译不过，登记留着，等对象能加载再处理）、`/obj/misc/mbox.lpc` 的 `do_copy`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 4 处、4 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/class/tieflag/master.lpc`（`give_quest`）、`/d/heimuya/npc/master.lpc`（`give_quest`）、`/d/tieflag/npc/master.lpc`（`give_quest`）、`/daemon/class/tieflag/master.lpc`（`give_quest`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 14 个函数没有补（other 10, chat_msg_combat 2, chat_msg 1, inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/goathill/npc/obj/dead_leech.lpc`:`eat_tonic`、`/d/goathill/obj/dead_leech.lpc`:`eat_tonic`、`/d/green.n/npc/oldman2.lpc`:`do_sigh`、`/d/huashan/npc/teller.lpc`:`tell_fortune`、`/d/snow/npc/obj/agaric.lpc`:`eat_tonic`、`/d/snow/npc/obj/ebony_lotus.lpc`:`eat_tonic`、`/d/snow/npc/obj/ginseng.lpc`:`eat_tonic`、`/d/snow/npc/obj/ice_lotus.lpc`:`eat_tonic`、`/d/snow/obj/agaric.lpc`:`eat_tonic`、`/d/snow/obj/ebony_lotus.lpc`:`eat_tonic` 等另外 4 个。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 2 处（`d/city/obj/cloth`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 5 个文件里 5 行只含这个指针的行（`(: do_sigh :),` `"算命": (: tell_fortune :),` `(: follow_player :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 46 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 46 处（32 个文件）：拼名字的赋值 24 处、与汉字常量比较 22 处。例：`name[0..1]` → `name[0..0]`（`/class/bonze/master.lpc:111`）；`name[2..3]` → `name[1..1]`（`/class/shaolin/cheng.h:157`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/class/shaolin/cheng.h:141`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：4 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 4 处（2 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/jingcheng/npc/liu.lpc:171`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 3 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 2 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

## example/book 注释折行无法加载（2026-10-27，KB 04 §6.25 Also）

`obj/example/book.lpc` 的 `// name of the skill` 等注释被折行，下一行 `the skill` 成了裸标识符，驱动报 `unexpected L_IDENTIFIER`。用手足 sjsh 完好副本覆盖。证明：HEAD 加载失败；改后加载成功。
