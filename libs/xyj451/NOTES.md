
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记451（ES II mudlib 家族，v4.50）。注册流程没有 'new' 关键字：任何还没存档的英文 id 都会直接落到"是否使用 X 作为新角色，确认？(y/n)"。天赋分配是一个重投循环（"接受这组属性吗？[n|y|q]"，n 重投，y 接受，q 大概是放弃），和 三界/xyj2000 家族那种字段选择菜单不一样。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py（两个都是本次会话新写的工具）在第一次启动测试之前就主动抓出来：（1）标准的 §8.1 GBK 字节区间 is_chinese()（str[0] > 160 && str[0] < 255）重写成逐码点 0x4e00-0x9fff 检查，配套的 check_legal_name() 的 i%2 奇偶门槛/[i..<0] 后缀切片也改成了逐码点的 name[i..i]；（2）master.lpc 的 valid_read()/valid_write() 直接转发给 SECURITY_D，没有 'user == this_object()' 保护——和 xyj20032 上曾经静默弄坏每一次注册的那个潜伏风险一模一样，这里没有观察到实际触发，属于主动预防性修复；（3）14 处 is_killing(me)/is_killing(who) 呼叫点，分布在 kungfu 技能的 daemon/class/*.lpc 档案和 cmds/std/surrender.lpc 里，用物件当参数传，而 feature/attack.lpc 对应声明的是 is_killing(string id)（§7.50）。httpd.lpc/dns_master.lpc 本来就已经在 adm/etc/preload 里被注释掉（休眠状态，原来就是这样）——保持原样，没有编译崩溃风险。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB 选择→英文 id→y（确认新角色）→中文名字→密码+确认→电子邮件→性别（m/f）→y（接受重投的属性）→q（跳过分页的每日消息）→在南城客栈进入游戏世界，look/score 都干净。管理员权限已通过"目前权限：(admin)"确认。LPC 格式化工具对全部 9322 个档案运行（写入 9297 个，9 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，16 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；唯一一处 case 标签带尾随注释的命中（ftpd.lpc）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 41 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,155 处存活匹配。脚本删除了 1,153 处标准独立行；
  另外 2 份房间生成工具（`obj/roommaker.lpc`、
  `d/obj/clone/misc/roommaker.lpc`，字符串拼接变体，`str += "...
  replace_program(ROOM);..."` 写死在生成模板里）手动修复。`data/` 下额外
  核查过，无命中。验证：真实 debug 驱动干净编译启动、端口正常监听，
  `debug.log` 无新增 "cannot replace"/错误行。

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

## Deep functional test (round two, 2026-08-27)

First full §10.7 round-two live playthrough of this lib (previous work
was WASM-onboarding + mechanical corpus sweeps only, never a continuous
played session). Booted `~/src/fluffos/build-debug/src/driver
config.fluffos` natively on port 40112 and drove it with raw Python
socket scripts (a persistent named-pipe/background-reader bridge to
allow interleaving two simultaneous connections — an admin session and
a test-character session — in the same room for shop/money setup).

**Admin account.** `adm/etc/wizlist` already listed both `winding
(admin)` and `fluffos (admin)`, but neither had a corresponding save
file — `fluffos` had to be registered live (English id `fluffos`,
Chinese name `管理员`, password `Mud@2026` — this project's standard
password IS accepted). Confirmed `(admin)` privilege via the login
banner and via live `call`/`clone`/`goto`/`summon` admin commands.

**Bugs found and fixed (3, all genuine programming bugs — missing
guards / pre-existing data corruption causing real crashes, not
content/design):**

1. **`adm/simul_efun/file.lpc`'s `log_file()` writes into `/log/nosave/`
   with no `assure_file()` guard** (AGENTS.md §7.11, same shape as the
   `xajhxo`/`xyj2006n` instances — this lib is the same `xyj4.5`
   lineage as `xyj2006n`, byte-for-byte identical bug). Reproduced live:
   admin `call wukongce->add("money",5000)` (used to fund a shop-buy
   test) threw an uncaught `*Wrong permissions for opening file
   /log/nosave/CALL_PLAYER for append. "No such file or directory"`.
   Since `cmds/usr/suicide.lpc`'s real account-deletion path calls the
   identical `log_file("nosave/SUICIDE", ...)` line before any deletion
   logic, every real `suicide -f` would hit the same crash. Fixed by
   forward-declaring and calling the file's own already-present
   `assure_file()` helper inside `log_file()`:
   ```lpc
   void assure_file(string file);
   void log_file(string file, string text) {
     assure_file(LOG_DIR + file);
     write_file(LOG_DIR + file, text);
   }
   ```
   Verified live: the same `call` completed cleanly post-fix and
   `/log/nosave/CALL_PLAYER` was created with the expected audit line.

2. **`adm/obj/master.lpc`'s `log_error()` mislabels plain compile
   WARNINGS as `"编译时段错误："` (compile-stage ERROR) for wizards**
   (AGENTS.md §7.103, narrower variant — this lib's `log_error()`
   already gates the raw dump behind `wizardp(this_player(1))`, so
   ordinary players only ever see the generic default error message,
   not the raw warning text; only wizards were affected). Reproduced
   live: logging in as the seeded admin and running `look`/`score`/`i`
   each dumped `编译时段错误：/cmds/std/look.lpc:363:1: warning: Unused
   local variable 'limb_status'`-style text as those command files got
   lazily compiled for the first time this boot. Fixed by adding the
   standard `strsrch(message, "warning:") == -1` guard inside the
   existing `wizardp(...)` branch only (non-wizard branch untouched):
   ```lpc
   if (wizardp(this_player(1))) {
     if (strsrch(message, "warning:") == -1)
       efun::write("编译时段错误：" + message + "\n");
   } else
     efun::write(get_config(__DEFAULT_ERROR_MESSAGE__) + "\n");
   ```
   Since `master.lpc` only compiles once at boot, this required a full
   driver restart to verify — confirmed live post-restart: the same
   admin register→look→score→i sequence produced zero warning dumps,
   while warnings still land in `debug.log` for wizards to find later.

3. **Pre-existing embedded-CRLF corruption in two NPC `.o` save files**
   (`data/npc/boss/xiaoxiao.o`, `data/npc/meng-zhu.o`) — confirmed
   byte-identical in the pristine `raw/` archive, so this predates this
   project's conversion, not introduced by it. Each file's `"long"`
   description string contains a real `\r\n` pair (this driver's
   `save_svalue()`/`restore_object_from_buff()` expects an embedded
   in-string newline to be written as a bare `\r`, with real `\r\n`
   reserved for top-level statement separators — see AGENTS.md's `.o`
   save-file section, third confirmed instance after `fy2`/`fy2qh`).
   Reproduced live: admin `goto /d/city/bingqipu` and `goto
   /d/suburb/xkx/taishan/fengchan` (forcing each room to reset and
   restore its NPC) threw uncaught `执行时段错误：*restore_object():
   Illegal file format - 1` in `debug.log`, leaving the room
   un-populated. Also independently reachable through ordinary NPC
   wandering (张果老 walking into 萧萧's room triggered the same crash
   without any admin involvement). Fixed with a quote-aware scan:
   collapse `\r\n` → `\r` only when inside an (unescaped) `"` string
   literal, leaving every top-level `\r\n` separator untouched. Verified
   live post-fix and post-restart: both rooms now populate their NPC
   with no restore error. Note: `data/npc/boss/` is covered by this
   project's own `.gitignore` (treated as ephemeral boss-respawn churn),
   so `xiaoxiao.o`'s fix is local-only/untracked; `meng-zhu.o` sits one
   directory up and so is tracked and part of this commit.

**Full playthrough exercised (test character `wukongce`/测试悟空,
female):** GB encoding select → new-character confirm (y) → Chinese
name → password/confirm → email → gender (f) → talent reroll (tried
`n` once, then `y`) → entered the game at 南城客栈, clean `look`/
`score`/`i` at every step. Moved `west`/`east` between 朱雀大街 and the
inn, re-checked `score` after the move (clean). Shop economy: `list` at
店小二, `buy huasheng from xiao er` after being funded via
`/adm/auxil/moneyd->pay_player()` (the correct way to grant test money
— physical coin/silver/gold objects, not a raw `add("money",N")`
property, which does nothing for `can_afford()`/`buy`), confirmed
inventory and change correctly. Message board: `post`/`read`/`discard`
at 南城客栈留言板 — clean, no crash (re-confirms the already-fixed
§7.86 `post` bug holds), pagination `help menpai`'s multi-page text
tested with ENTER/`b`(back)/`q`(quit) — all worked correctly, no §7.153
gap. Sect join: `apprentice puti` (a high-tier inner-circle master)
correctly rejected an outsider per its own in-file `combat_exp`/
`query_skill` requirements (content, not a bug); `apprentice yun qing`
(a lower-tier disciple, matching the newbie doc's own advice to start
with a low-ranking member) succeeded, "恭喜您成为方寸山三星洞的第四代
弟子。" `learn unarmed from yun qing` succeeded, skill progressed to
"初学乍练 1/0". Safe-sparring: `fight <npc>` is this lib's actual
point-to-point spar mechanism ("这种形式的战斗纯粹是点到为止...不会真
的受伤") — the test NPC (扫地小童) declined the `fight` invitation, so
per the game's own documented fallback ("如果对方不愿意接受你的挑战，
你仍然可以迳行用 kill 指令开始战斗") used `kill` instead, which was
accepted and produced a real fight with escalating wound messages.
Combat/death/respawn: lost the fight, died, sent to 阴阳界
(the underworld) with 崔判官, who reviewed the "生死簿" and resurrected
the character automatically after a short wait, respawning at 荒郊小店
with sect membership preserved but inventory dropped and 潜能 reduced
from 99 to 50 (a death penalty — consistent, intentional design, not a
bug). Quit/reconnect: did two full quit→wait→reconnect cycles; both
times state persisted correctly (sect, HP, stats), no leaked duplicate
`user`/`login` objects (`ulist` showed exactly one connection),
`tell`/`find_player` worked correctly both before and after reconnect
(§7.131/§7.152 clean).

**Cross-cutting pattern sweep** (all the standing AGENTS.md patterns
listed in the round-two task brief, checked via targeted grep against
`work/`): §4.3 (no `log_file()` call site has "static" in its literal
path argument — the one `"static/SUICIDE"` hit is in `cmds/usr/sui1.old`,
a dead `.old`-extension file the driver never compiles and nothing
references), §4.4 (`data/chinese.o` and other dict-like files are
valid UTF-8, no BIG5-as-GBK residue found), §7.80/§7.118 (no
`[0..<1]`/off-by-one filename-slice hits), §7.86/§7.100 (already swept
corpus-wide; live-reconfirmed via a clean `post` on the inn's board),
§7.112 (no unguarded NPC/reconnect `init()` re-entry issue found),
§7.121 (no bare float literal assigned to an `int`-typed field/param),
§7.122/§7.150 (`obj/login.lpc` destructs itself correctly on
`time_out()`/successful login, no heartbeat leak), §7.123 (no
column-zero bare `IDENT = (\[|\{...` file-scope statement), §7.129
(no `tell_room()`/`message()` wrapper forwarding a bare unset varargs
arg), §7.130/§7.133 (`obj/login.lpc`'s `net_dead()`/`obj/user.lpc`'s
`reconnect()` both correctly defined, no unconditional post-non-
interactive liveness check), §7.131/§7.152 (`find_living`/`find_player`
work correctly, confirmed live via cross-connection `tell` both before
and after reconnect; `feature/command.lpc`'s `enable_player()` calls
`set_living_name()` once on the same persistent object, which survives
netdead/reconnect since the object itself is never destroyed), §7.132
(no `map()`-over-mapping wrong-arg-bound callback found), §7.134 (no
field defaulting to `0` instead of `({})` found in this pass's scope),
§7.139 (no interactive-catch-tell config flag issue observed), §7.141
(no `replace_program()` fold found in a room `create()`), §7.142 (no
virtual-object-masks-broken-exit shape found), §7.143 (this lib's own
vendor NPC flow uses a plain `list`/`buy_object()`/`complete_trade()`
pattern, not `force_me()`/`add_action()` — no swallowed-response shape
found), §7.144 (no one-shot setup guard defeating per-instance setup
found), §7.145 (no broken pre-check wired as a direct verb override
found), §7.146 (no broken `/`-for-`/*` comment found — false-positive
grep hits were all ASCII-art map lines/format strings, verified by
reading each), §7.147 (no unchecked function-returns-0-on-missing-
content found in this pass's scope), §7.148 (no parameter named a
reserved keyword like `nosave`), §7.149 (`securityd.lpc`'s wizlist
loader is a plain read-and-parse, no first-admin auto-promote
bootstrap to check), §7.151 (the one `keys(ind_list)[j]` hit in
`d/qujing/wudidong/npc/yanshu.lpc` correctly indexes the keys array by
the loop variable — not the buggy shape), §7.153 (`help menpai`'s
pagination `b`/`q`/ENTER all handled correctly, tested live).

Cleaned up: removed the throwaway `wukongce` test-character save files
(`data/{user,login}/w/wukongce.o`) and the empty test board save
(`data/board/nancheng_b.o`, regenerates on first real post) before
committing. Kept the seeded `fluffos` admin account.


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 3 file(s) `inherit F_SSERVER;` and no header defines it (3 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/suburb/xkx/xingxiu/nanjiang2.lpc`、`d/suburb/xkx/xingxiu/nanjiang3.lpc`、`d/suburb/xkx/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`d/obj/inherit/weapon/throwing.lpc`、`d/obj/inherit/weapon/fork.lpc`、`d/obj/inherit/weapon/whip.lpc`、`d/obj/inherit/weapon/sword.lpc`、`d/obj/inherit/weapon/axe.lpc`、`d/obj/inherit/weapon/blade.lpc`、等共 9 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyj451 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 533 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：516 -> 516 通过，无回退；改过的头文件的 256 个包含者 251 -> 251 通过。
记录、未改：`d/suburb/es/npc/oldman.lpc`（采药老者/山药蛋）的 `kill_ob()` 里那句 `HIY "采药老者眼放异光……纳命来！" NOR "\n", environment(), this_object());` 丢了开头的 `message(…` 调用，第 154–155 行还有类型错误，HEAD 起就编译不过。

启动时警告 27 -> 0；新进程登录（编码选择、新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 5 个，只在 #if 分支用的声明移进分支 1 个文件；改动 7 个文件，HEAD 与工作树各载入一次无回退（7 objects; HEAD PASS 7, tree PASS 7; regress 0; newly loading 0），这些文件的警告 27 -> 18。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 12 处多余的 `F_CLEAN_UP`，其余照同族已有改法手工，能编译的文件警告清零；改动的 22 个对象在 HEAD 与工作树各载入一次，regress 0。

- 袈裟 `d/obj/cloth/jiasha.lpc`（`CLOTH` + `F_UNIQUE`）只跑 unique 的 `init()`，撕袈裟的 `tear` 从没加上；补 `init() { cloth::init(); unique::init(); }`（同 xyj2000）。
- `d/kaifeng/ground.h` 的三张表包进 `#ifndef GROUND_TABLES_INHERITED`，层层继承的 `ground1/2/3.lpc`、`ground.lpc` 包含前定义它（同 xyj2000）；`include/net/ftpdconf.h` 的 `VALID_READ`、`VALID_WRITE` 先 `#undef`（同 xiakexing2017）。
- `d/suburb/es/city/shangshu/kefang.lpc` 的 `(: "一本诗词集……" :)` 改成字符串本身；`daemon/skill/hubo.lpc`、`test-whip.lpc` 写明用驱动原先选的 `clean_up()`；`daemon/skill/huashan-jianfa.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 2 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

43 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`liumai-shenjian`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

49 个文件、58 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/suburb/fy/city2/obj/jinduan`、`/clone/misc/cloth`、`/d/city/npc/obj/choupao`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 48 个（47 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:20: error: Cannot #include mailer.h）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `jueqingbian`、`huntian-qiong`、`xiake-force`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 2 个通过，其余 1 个停在别的错误上（`daemon/class/xiake/master`：*No program in object '/daemon/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←wuhanzhan，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 5 处、5 个文件：`yange_blade`→`yange-blade`（1 处）、`dragon-step`→`dragonstep`（1 处）、`huntian-qiong`→`huntian-qigong`（1 处）、`chaos-steos`→`chaos-steps`（1 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/suburb/es/latemoon/in_room/flower1.lpc` 的 `north` 出口：`corridor7` → `backroom`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/suburb/es/latemoon/room/npc/old.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←fy2mg：5/5 个继承它的对象载入
- 玩家打造兵器的模板（5 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：5 个未使用的局部变量，5 个覆盖基类 void 函数的函数改了类型。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 29 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/qujing/wudidong/npc/boy.lpc`（wuhanzhan）、`/d/qujing/wudidong/npc/girl.lpc`（wuhanzhan）、`/d/qujing/wudidong/npc/kid.lpc`（wuhanzhan）、`/d/qujing/zhuzi/npc/king.lpc`（wuhanzhan）、`/daemon/class/huashan/ning.lpc`（fy2mg）、`/daemon/skill/beiming-shengong.lpc`（fy2mg）、`/daemon/skill/fanliangyi-dao.lpc`（fy2mg）、`/daemon/skill/hanbing-mianzhang.lpc`（fy2mg）、`/daemon/skill/huashan-shenfa.lpc`（fy2mg）、`/daemon/skill/huashan-zhangfa.lpc`（fy2mg）、`/daemon/skill/hunyuan-zhang.lpc`（fy2mg）、`/daemon/skill/lingboweibu.lpc`（fy2mg）、`/daemon/skill/liumai-shenjian.lpc`（fy2mg）、`/daemon/skill/longxiang.lpc`（fy2mg）、`/daemon/skill/poyu-quan.lpc`（fy2mg）、`/daemon/skill/qiankundanuoyi.lpc`（fy2mg）、`/daemon/skill/taizuchangquan.lpc`（fy2mg）、`/daemon/skill/xiaowuxiang.lpc`（fy2mg）、`/daemon/skill/yunlong-shenfa.lpc`（fy2mg）、`/daemon/skill/yunlong-zhua.lpc`（fy2mg）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/suburb/fy/npc/guojing.lpc`、`/d/suburb/fy/npc/killer-n.lpc`、`/d/suburb/fy/npc/killer-s.lpc`、`/d/suburb/fy/npc/killer-w.lpc`、`/d/suburb/fy/npc/m_weapon/tan/tan4.lpc`、`/d/suburb/fy/npc/m_weapon/tan/tan7.lpc`、`/d/suburb/xkx/city/npc/obj/box.lpc`、`/d/suburb/xkx/shaolin/dxbdian.lpc`、`/daemon/skill/unused/snowshade-force.lpc`。修后与 HEAD 逐个对比载入：这 29 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/city/puke-room.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 2 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/daemon/class/oldstuff/ronin/master.lpc`、`/daemon/class/ronin/master.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/obj/inherit/char/npc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `cast1`：宏 `SYNTAX` 带着分号（2026-10-21，KB 04 §6.28）

`#define SYNTAX "指令格式：cast <法术> [<参数>| on <目标>]\n";` 的 `;` 属于宏展开，`notify_fail(SYNTAX);` 变成 `notify_fail("..." ;);`，整个指令编译不了（`unexpected ';'`）。去掉宏里的分号，并删掉没用到的局部变量 `dest`（编译警告）。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 10 条注册（7 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/lingtai/npc/kancai.lpc`（`do_vendor_list`）、`/d/obj/inherit/misc/fboard.lpc`（`do_list`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/suburb/es/village/lordhouse3.lpc`（`do_push`）。最多的函数名：`do_push` 3 处、`do_vendor_list` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/suburb/xkx/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/suburb/xkx/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 5 个函数没有补（other 4, inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/suburb/es/goathill/npc/obj/dead_leech.lpc`:`eat_tonic`、`/d/suburb/es/goathill/obj/dead_leech.lpc`:`eat_tonic`、`/d/suburb/es/snow/npc/obj/ebony_lotus.lpc`:`eat_tonic`、`/d/suburb/es/snow/obj/ebony_lotus.lpc`:`eat_tonic`、`/d/suburb/xkx/huashan/npc/teller.lpc`:`tell_fortune`。 另有 3 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 4 个文件里 6 行只含这个指针的行（`(: follow_player :),` `"算命": (: tell_fortune :),` `"剃度": (: ask_for_join :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 20 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 20 处（14 个文件）：拼名字的赋值 12 处、与汉字常量比较 8 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:105`）；`name[2..3]` → `name[1..1]`（`/daemon/class/shaolin/cheng.h:156`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/daemon/class/shaolin/cheng.h:140`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：8 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 8 处（4 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/d/suburb/fy/fengyun/npc/caifeng.lpc:142`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
