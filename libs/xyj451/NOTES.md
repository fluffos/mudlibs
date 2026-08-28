
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
