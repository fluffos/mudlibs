
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
