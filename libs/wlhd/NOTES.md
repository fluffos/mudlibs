
## WASM 修复摘要（迁移自 meta.json 的 group_note）

武林浩荡，游戏内品牌为《金庸梦II》/《武林浩荡》。和 tybxjh（天涯之碧血江湖）同一血统/代码库——master.lpc/securityd.lpc/logind.lpc 字节相似，注册提示文字完全相同，wiz_levels 阶梯同样到 (ceo) 为止，globals.h 里同一条注释掉的 '// #define SECURITY_D "/adm/daemons/securd"' 诱饵档案提醒也一样。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误——没有发现任何 LPC bug。唯一的改动：把 fluffos (admin) 播种进 adm/etc/wizlist（已有三个 (ceo) 级创始人账号——rock/jerry/kjh；SECURITY_D 正确指向 /adm/daemons/securityd）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→管理密码+确认→普通密码（必须不同）+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过登录后的横幅"您目前权限：(admin)"确认。LPC 格式化工具对全部 11160 个档案运行（写入 10179 个，945 个报错——大多是杂乱的 kungfu/quest 内容无法幂等往返触发的 TOKEN MISMATCH 安全门跳过，加上一处确认的未结束字符串词法失败，全都安全地保持原样未动，36 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 4 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §10.7 深度功能测试（本次新增）

此前只做过一次浅层的注册流程验证，声称"没有发现需要修复的程序 bug"。
本次实际深入游玩后发现这个结论过于乐观——本档案和逐字节共享地图的
手足档案 `yxjh`（浴血江湖）用了完全独立的两份 `logind.lpc`，`yxjh`
自己 §10.7 pass 里发现的三类 bug，直接在 `wlhd` 的源码里逐一核对后
确认**全部命中**，属于两个独立代码库各自平行犯下同样错误（不是复制
粘贴），照搬已验证过的修法后逐一实测确认。

### 修复 1、2：logind.lpc 里两处 printf("%O") 调试残留

分布在两条并行的取名流程上——接受系统随机生成的中文名
(`get_resp()`，第 693 行) 和自己手动输入中文名 (`get_name()`，第
740 行)——都紧挨在"请设置你的管理密码"提示之前，会把登录连线对象
的内部路径（如 `/clone/user/login#0`）直接打印在新玩家屏幕上。和
`yxjh`/`hc` 那次发现的形状完全一样（同一行调试代码被复制到两条并
行流程里）。两处都已删除，实测确认新流程里不再出现。

### 修复 3：§8.9 同款 bug（yxjh 的精简写法）

`logind.lpc` 的 `user->setup()` 之后：`if (ob->query("age") == 14) {
user->set("food", ...); user->set("water", ...); }`——`ob` 是登录连
线对象，从未被赋过 age，条件永久为假，食物/饮水满血初始化从未真正
生效过。已改为 `user->query("age")`。

### 修复 4（本次独立新发现，未见于 yxjh 自己的记录）：d/jerry/saveme.lpc 的 exert_function() 类型错误彻底压垮了新手起始房间的 NPC

`d/jerry/saveme.lpc` 的 `create()` 里有一行
`exert_function(10);`——`exert_function()`（定义在
`inherit/char/npc.lpc`）需要的是一个技能名字符串，不是整数，导致这
个 NPC（"江湖医生"）完全编译不过：`*error: Bad type for argument 1 of
exert_function ( string vs int )`。这份档案恰好被放置在
`d/city/wumiao`（武庙）——也就是**本档案巫师角色的起始房间**——第
一次注册管理员账号、进入武庙查看房间内容时，"江湖医生"这个 NPC 完
全没有出现在房间物品列表里，直接验证了这个编译失败确实会静默抹掉一
个本该存在的 NPC。这个具体的死代码调用（`exert_function(10)`）此前
已经在手足档案 `yxjh` 的 WASM 修复阶段被发现并删除过，但那是**两份
完全独立的档案**（各自的原始压缩包各自打包了一份这个死代码文件），
`yxjh` 那次的修复没有、也不可能自动带到 `wlhd` 这边——本次是在这份
档案自己的 WASM 修复阶段之后、第一次真正深度游玩时才被发现。已比照
`yxjh` 的处理方式（原始意图已经无法还原）直接删除这一行调用。

### 检查、确认不适用的已知 bug 类别

- §7.68 复活软锁：`d/death/npc/{b,w}gargoyle.lpc` 确实存在同样的
  `if (!ob || !present(ob)) return;` 一次性判定形状，已按标准修法
  拆开重试逻辑（虽然 `yxjh` 自己的 §10.7 记录没提到这一条，可能是
  当时没有触发或者没记录）。
- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 ES2 家族（shujian3/hy2002/jh2006/xxcq/sj）相同形
  状的结构，但这是**完全不同的"天涯"血统**，此前从未在这个血统里
  验证过。本次时间关系未做实测（比如取一份角色存档在战斗前后核对
  裸 set/query 是否真正写入了角色本体），留给未来 pass 补做，不能
  直接照搬 ES2 家族"已排除"的结论。

### 实战验证

用管理员角色在南大街对"小贩"（`combat_exp` 10000，`attitude`
peaceful，正确的调用别名是 `fan`——`xiaofan` 整体不是有效别名）发起
攻击，完整交手至将其击杀，战斗叙述、伤害递进、"倒地不省人事"到"死
了"的完整流程均正常。受限于本次会话时间，未能找到足够强的对手来触
发管理员自己的死亡/复活测试（管理员默认属性异常高：攻击力 240000/
躲闪 160000），`bgargoyle.lpc`/`wgargoyle.lpc` 的 §7.68 修复只做到
编译层面确认。

### 本次会话的一次工具使用事故（已在提交前完全修复，无遗留影响）

为了让 fluffos 账号能重新走一次干净的注册流程，误执行了
`rm -rf work/data/login/f work/data/user/f`——这份档案在这两个目录
下除了 `fluffos.o` 之外，还存有几十个真实存在的历史玩家存档（凡是
英文 id 以字母 f 开头的玩家都归在同一个目录桶里，不是按账号单独存
放）。在 `git status` 里发现大量意外的 `D`（删除）之后，立即用
`git checkout --` 完整还原了这些档案，确认恢复后的档案数量
（`login/f` 63 个、`user/f` 100 个）和还原前一致，本次提交只包含
真正想要的源码改动和新增的 `fluffos.o`。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。这份档案和 `tybxjh`（天涯之碧血江湖）是同一套"天
涯"引擎的姊妹档案（`master.lpc`/`securityd.lpc`/`logind.lpc`/
`feature/dbase.lpc` 逐字节相似），本轮三个 bug 全部命中，和
`tybxjh` 完全同一形状，修法也完全相同。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，CRLF 行尾档案）完全没有严
   重度检查**：和 `tybxjh` 完全同一形状，同一修法
   （`strsrch(message, "arning:") == -1`）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护**：和 `tybxjh` 完全同一形状（`login/newid.log` 在
   `get_gender()` 注册最后一步调用），同一修法。这份档案的
   `assure_file()` 也定义在 `log_file()` 后面，同样需要前向声明
   （这次没有漏加）。
3. **`feature/dbase.lpc` 的 `set()` 密码防劫持保护错误拦截了自己第
   一次的密码设置——这份档案不仅命中了和 `tybxjh` 完全相同的这个
   新发现 bug 类别，而且是**活生生的现场证据**：此前提交的
   `data/{login,user}/f/fluffos.o` 存档（"WASM 修复摘要"一节声称
   "登录横幅直接显示确认生效"）打开一看，`dbase` 映射里根本没有
   `"password"`/`"ad_password"` 这两个键——和 `tybxjh` 修复前的现
   场复现结果一模一样，证实这个旧存档从一开始就是坏的，账号从未真
   正能够登录。已应用和 `tybxjh` 完全相同的修法（只在
   `dbase[prop]` 已存在时才触发保护）。删除旧的坏存档，重新走完整
   注册流程，新存档的 `dbase` 映射正确包含两个密码哈希；用刚设置
   的普通密码断线重连，"重新连线完毕"确认真正登录成功。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数。

### 实测过程

登录流程和 `tybxjh` 完全一致（英文 id → y/n 确认 → 中文名字 → 管理
密码+确认 → 普通密码+确认 → 天赋 0 随机+接受 → 邮箱 → 性别）。
`log/debug.log` 里全是 `*Too long evaluation`/`*Can't catch eval
cost too big error`，追查后确认全部发生在全新驱动进程首次预载/注
册触发的冷编译级联期间（AGENTS.md §7.90/§10.8 已归档类别），断线
重连后未再出现，确认已自愈，非持久性 bug。驱动最终按精确 PID
kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已更新提交（`data/{login,user}/f/
  fluffos.o`，密码：管理密码 `AdminPass123`，普通密码
  `LoginPass456`；旧的、从未真正可用的存档已删除重建）。
- `data/{login,user}/c/ccc.o` 是此前会话遗留的角色存档，本轮某个
  背景守护进程（`closed.lpc` 的 `heart_beat()`）的例行存盘产生了
  纯粹的时间戳类 diff，已用 `git checkout` 撤销，不提交。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,384 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed both room-building tool copies'
string-builder template (`work/clone/misc/roommaker.lpc`,
`work/u/tyui/obj/roommaker.lpc`). Checked 98 real `.lpc` files under
`work/data/{area,room,proom,...}` for the known data/-exclusion
false-negative — none had the bug pattern. All remaining
`replace_program(ROOM)` matches after the fix are pre-existing
`//`-commented lines only.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`LoginPass456`) into the game world, `look`/`west`/`score`/
`quit` all worked cleanly.

**Extra caution note per this lib's standing player-save-damage
history**: the live login run left several incidental data/ diffs —
routine `heart_beat()` background saves on unrelated player accounts
(`ccc.o`, `cscb.o`, `seven.o`, `area/*.o`), the `fluffos` account
picking up starting equipment from normal gameplay, AND (more
notably) a **deletion** of `data/login/f/fluffos.o` (the credential/
password-hash file) observed after `quit`, even though that same file
was used successfully to log in during this very session. Root cause
not investigated (out of scope for this sweep — not related to the
replace_program fix), but ALL data/ drift including this deletion was
reverted via `git checkout HEAD -- work/data` before committing, so
the credential file and all other player saves are untouched in the
committed diff. Flagging for whoever next touches this lib's `fluffos`
account or investigates login/logout save behavior.

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

## §10.7 deep functional test, round three (2026-08-24): closing the four gaps flagged by NOTES.md audit

Prior passes never actually exercised death/revival, shop `buy`, sect
apprenticeship, or a message-board `post`/read round trip. This pass
closed all four, live, against a freshly-rebuilt `fluffos` driver
(`build-debug/src/driver`, `src/fluffos` checkout at `1e74a758`).

### Found and fixed: `securityd.lpc` `valid_read()` self-recursive infinite loop — hits EVERY non-rock/jerry login

`adm/daemons/securityd.lpc`'s `valid_read(file, user, func)` has a
trusted-caller bypass list (`sscanf(base_name(user), "/adm/daemons/%*s")
|| ".../adm/etc/%*s" || ".../feature/%*s" || ".../inherit/%*s" ||
".../include/%*s" || ".../cmds/%*s")` that lets system code read
anything. It was **missing `/adm/obj/`** — the directory holding
`master.lpc` and, critically, the special object the driver attributes
every **simul_efun** call to (`base_name(user)` prints as
`/adm/obj/simul_efun` for any call made from inside a simul_efun body).

The deny branch a few lines below (for any non-rock/jerry player reading
a path under `/log/`, `/u/rock/`, `/u/jerry/`, or `/u/kjh/`) calls
`log_file("file/bug_read", ...)` to record the violation. `log_file()`
(`adm/simul_efun/file.lpc`) calls `assure_file()`, which calls
`file_size()` on that *same* `"/log/file/bug_read"` target path before
writing it — and that `file_size()` call re-enters `valid_read()` with
`user` = the simul_efun wrapper object. Because `/adm/obj/` wasn't in
the trusted-caller list, that nested call takes the *same* deny branch
again, logging the violation again, forever — a textbook
self-recursive cycle, not just an incidentally-deep call chain — until
the driver's call-depth limit aborts with `Too deep recursion.` This
fires on **every single login by any account that isn't `rock`/`jerry`**
(including the seeded admin, `fluffos`), because `clone/user/logind.lpc`'s
own `enter_world()` unconditionally probes `file_size("/log/login/notice")`
right before the "身份消息" banner — that first denied read starts the
cycle. It's non-fatal (the driver's per-call catch absorbs it and login
continues) but wastes real cycles on every login and floods the
player's screen with ~35 repeated "警告：你不能操作这些目录下的文件。"
lines before the "身份消息" banner appears — confirmed 100%
reproducible across repeated fresh admin logins before the fix, and
gone (clean login, zero `Too deep recursion` in `debug.log`) after
adding `sscanf(base_name(user), "/adm/obj/%*s")` to the bypass list, on
both the admin account and a fresh non-admin registration.

### 1. Death/revival: clean, full cycle verified

`admin call <id>->die()` shortcut used per this project's established
pattern (registered a fresh non-admin test character, `wlhdtest`/
`测试武林`, since the seeded admin's 240000/174000/218400 attack/dodge/
defense make it unkillable via normal combat — and per AGENTS.md
§10.7's item 6a, an admin/`wizardp()` account can also be silently
excluded from the ghost-NPC flow by design, so a non-admin target is
the correct choice regardless). `call wlhdtest->die()` triggered the
real death sequence: "你大叫一声倒在地上，挣扎了几下，死了！" → moved to
`鬼门关` (`d/death/npc/wgargoyle.lpc`'s room) → all 5 `death_msg` stages
fired automatically via `call_out` over ~25s (no player input required,
despite the flavor text reading like a question) → `reincarnate()` →
moved to `REVIVE_ROOM` (`d/city/wumiao`). `score` afterward showed
"你共死亡：1 次" and reduced `<精>`/`<气>` (expected death penalty), no
`debug.log` errors. Confirms the §7.68 fix from an earlier pass
(`bgargoyle`/`wgargoyle`'s retry-guard, later reverted per the
2026-08-05 correction — see above) never actually needed the revert's
concern to trigger: this is a clean single-pass `init()`/`call_out()`
flow, no reentrancy hazard exercised.

### 2. Shop `buy`: clean, correct change/inventory math

`小贩` NPC (`d/village/npc/seller.lpc`, `feature/dealer.lpc`'s
`do_buy()`) in `d/village/ehouse1`. Gave the test character 500 coin
(admin `clone`d a `/clone/money/coin`, `set_amount(500)`, `give`'d it —
note `give` requires `wizardp()` to bypass `no_give`, and requires the
target to be genuinely `interactive()`, i.e. actually connected, not a
stale disconnected body left in the room from a prior test connection).
`buy stick` ("手杖", value 100) succeeded: "你向小贩买下一根手杖。", the
item appeared in inventory, and the money correctly decremented by
exactly 100 (500 coin → auto-consolidated display as "四两银子", i.e.
400 remaining at the coin/silver conversion rate). No bug.

### 3. Sect apprenticeship (拜师): clean, `score` reflects new sect

`bai`/`apprentice` (`cmds/skill/apprentice.lpc`) against 欧阳不空
(`d/tongchi/npc/ouyang.lpc`, 通吃帮 second-generation elder, whose
`attempt_apprentice()` auto-accepts any non-`无性`-gender applicant via
`command("recruit " + ...)`) — reached via admin `goto`/`summon` since
the test character has no wizard-level travel shortcuts. Checked this
lib's `apprentice.lpc`/`feature/apprentice.lpc` against the §7.117
"betrayal check missing a first-timer guard" pattern flagged for this
session: **not present here** — every family-name comparison is
correctly guarded by `mapp(me->query("family"))`/`mapp(ob->query("family"))`
before dereferencing, both in `apprentice.lpc` (line ~40) and
`feature/apprentice.lpc`'s `recruit_apprentice()`/`is_apprentice_of()`.
`bai ouyang` completed cleanly: "你跪了下来向欧阳不空恭恭敬敬地磕了四个
响头，叫道：「师父！」恭喜您成为通吃帮的第三代弟子。" — `score`
afterward showed 称谓 "通吃帮第三代弟子" and 师傅 "欧阳不空". No bug.

**Note, first attempt used the seeded admin account and silently
failed** (no error, no message, `bai ouyang` just printed "你想要拜欧阳
不空为师。" and nothing further) — root-caused via temporary
`debug_message()` instrumentation (removed before finishing) to
`clone/user/user.lpc`'s `id()`: `if (this_player() &&
!this_player()->visible(this_object())) return 0;` — an ordinary NPC
(`this_player()` during the NPC's own `command("recruit ...")`) cannot
`present()`-match an admin whose `env/invisibility` is set (which
`logind.lpc` sets by default for every `wizardp()` login), so
`recruit.lpc`'s `present(arg, environment(me))` never finds the admin
at all. This is the same documented class as AGENTS.md §10.7 item 6a
(admin accounts are deliberately invisible to ordinary NPC-driven
interactions) — not a bug, just another reason to always keep a
non-admin test character on hand.

### 4. Message board `post`/read: clean round trip

`post <title>` → line editor (`.` to save) → `read <num>` at 意见簿
(`d/city/wumiao`'s board, `inherit/misc/bboard.lpc`). Full round trip
(title + body, correct author/timestamp, board's unread/total counts
incrementing) confirmed clean via a fresh raw Python socket connection.
Test posts deleted afterward (`delete <num>`, works because the poster
owns their own post) to leave the board exactly as before (11 posts).

**Two test-tooling false alarms hit and resolved along the way (not
mudlib bugs)**: (1) `scripts/tmux_mud.sh`'s multi-line send into the
board's line editor tripped the local `telnet` client's own escape
handling, dropping the session into a dead `telnet>` prompt — recovered
by switching to a raw Python socket for this specific interaction
(matches this session's guidance to cross-check `tmux_mud.sh` mojibake/
corruption against a fresh raw socket, generalized here to a different
tmux/telnet client-side artifact, same remedy). (2) The first raw-socket
attempt used the wrong wire encoding (GBK) and produced mojibake
("锟斤拷...") in the posted title/body — this lib's actual wire encoding
is UTF-8 (confirmed by decoding the login banner correctly only under
UTF-8); redone with the correct encoding and the round trip was clean.

### Cleanup

Test character `wlhdtest`/`测试武林` was **not** committed (its save
files were deleted before finishing, per the driver's own built-in
"logged in under 30 minutes → save deleted on quit" resource-saving
rule — see below — plus a manual `rm` of the residual file after the
final driver shutdown autosave). All incidental `data/` drift from this
session (`fluffos`'s equipment/gold from normal play, `ccc`/`cscb`/
`seven`/`area/*` background `heart_beat()` saves, the board's pure
resave-reordering diff) was reverted via `git checkout` before
committing — only the `securityd.lpc` fix is in the diff.

### Observation (not a bug, documented for whoever next investigates `fluffos` account save/quit behavior)

This session finally explains the "mysterious `fluffos.o` deletion after
`quit`" flagged as unexplained in the 2026-08-19 §7.100 entry above:
`cmds/usr/quit.lpc` has an explicit, intentional resource-saving rule —
any account that has been logged in less than 30 minutes
(`me->query("mud_age") < 1800`) gets **both** its `login/` and `user/`
save files `rm()`'d on `quit`, with a player-facing warning message
("注意：由于您这个ID登陆不到30分钟，系统为了节省资源不给予存档!")
printed at the exact same time. This is deliberate design, not a bug —
confirmed by the matching warning text and reproduced consistently
every time a short session `quit`s. Not previously connected to the
2026-08-19 observation because that pass didn't have a `quit` message
correlated with the deletion in the same session.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/system_1/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/system_1/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py wlhd --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 830 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：759 -> 759 通过，无回退；改过的头文件的 38 个包含者 38 -> 38 通过。`d/feitian/npc/xunbu.lpc` 的 `(: random_move() :);` 只造函数指针不调用，属内容设计，未动。

启动时警告 54 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/app/ls2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 23 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 33 个文件，HEAD 与工作树各载入一次无回退（33 objects; HEAD PASS 33, tree PASS 33; regress 0; newly loading 0），这些文件的警告 33 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `u/rock/duihuan.lpc`：`for (i - 0; …)` 应为 `i = 0`（局部变量本为 0，行为不变）。载入无回退。

- 2026-10-12：`u/jerry/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 5 处多余继承；照 tybxjh（72440a6be25）手工：`d/jerry/job/peng/peng.lpc` 的 `ask_fail` 原型改 `int`（`dojob.lpc` 定义的是 `int`），`quest/chousha/killer.lpc` 写明用驱动原先选的 `clean_up()`，`u/system_1/ansi2.h` 的 `ESC`、`BEEP` 先 `#undef` 再定义。能编译的文件警告清零；改动的 8 个对象在 HEAD 与工作树各载入一次：HEAD PASS 5，tree PASS 5，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：一个技能文件的 `int power_point()` 返回 1.5，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（KB 04 §6.10）。
- 2026-10-14（续）：`data/area/好吃党.o` 末尾多一个零字节，转码解析失败；去掉末尾的零字节后按 GB18030 转为 UTF-8（`scripts/lpc_save_encoding.py`）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。25 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-dafa`、`quanzhen-jian`、`wugong-zhao`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`zidian-jianfa`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/chuo`、`dagou-bang/pi`、`dagou-bang/tiao`、`dagou-bang/yin`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest2/jinyong`、`/quest2/jinyong/jinyong`、`/quest2/quest2/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`；落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`wangran-xinfa`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`palm-sword`→`plam-sword`（`hand-blade`、`plam-sword`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yunv-xinjing`→`yunu-xinjing`（`wangran-xinfa`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）。

## 帮派地盘档截断（2026-10-15，KB 03 §4.4）

`data/area/天安门妓院.o` 原档停在 `"banghui":"$HIY$【中华大帝国】",`，少了结尾的 `])`，地盘对象读档报错。补上。（这个档的内容其实是天安门钱庄的数据，原档如此，未动；同目录的 `钱庄.o` 是截断的废档，没有地盘用它。）

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunu-jianfa/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`、`data/area/天安门钱庄.o`、`data/area/成都广场.o`、`data/area/扬州铁匠铺.o`、`data/npc/+瘭+.o`、`data/npc/xianlaoban.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 死神刀「死神锁」命中时报错（2026-10-15，KB 06 §7.246）

命中时要把对方的兵器震飞，用的 `weapon2` 却从未赋值：每次命中都在扣完内力后报错。改为当场取对方的兵器；对方空手就只有“人也彻底崩溃了”那半句。


## 弹指神通「漫天花雨」每次报错（2026-10-15，KB 06 §7.246）

绝招声明了 `object weapon;` 却从不赋值，接着就 `weapon->query_amount()` 数暗器：每次使用都报错。补上取兵器的判断，手里没有暗器时拒绝（“你手中没有暗器”）。


## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

7 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/jyquest/sword`、`/jyquest/armor`、`/obj/cloth/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 3 个，改后 6 个（3 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：2 个通过。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（4 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 2 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/stick`（宏 `STICK`）←zxty，3 个对象继承它，抽样 1/3 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 19 处、16 个文件：`yan-fly`→`yanfly`（3 处）、`yijin-jing`→`yijinjing`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc`、`/d/rock/shengji.lpc`、`/u/jerry/npc/shengji.lpc`、`/u/rock/hlxy/zs.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/clone/unique/fumo-dao.lpc`、`/clone/unique/jinfu.lpc`、`/clone/unique/jinshe-jian.lpc`、`/clone/unique/jiuyin_force_book.lpc`等共 17 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_sword2.lpc`、`/d/npc/m_weapon/weapon/m_sword3.lpc`、`/d/npc/m_weapon/weapon/sword.lpc`（共 5 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`（共 3 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/rock/paimai.lpc`：拍卖房的 `add("pnum",1)`（竞买者计数）被 `//归还前一个竞买者的钱` 注释吞掉，计数从不增加

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `clone/unique/fan.lpc`：同时继承 `STICK` 和 `SKILL`，两条路径都带来 `/feature/clean_up.lpc` 的 `clean_up()`（`clean_up() inherited from both …`），驱动用了后继承的 SKILL 那条；写出 `int clean_up() { return skill::clean_up(); }`，行为不变（`scripts/lpc_name_winner.py`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 6 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/jerry/obj/huwan.lpc`。修后与 HEAD 逐个对比载入：这 6 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。
