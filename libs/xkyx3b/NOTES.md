# xkyx3b — 侠客英雄传 III

Archive: `侠客英雄传III 可用.zip`. Port: 40036. Status: **done** (boots
clean and quick, full registration flow verified end-to-end including a
real Chinese name).

## What this is

"侠客英雄传" — its own connection banner describes the setting as "以
金庸小说、西欧中世纪传说及漫画为背景的世界" (a world set against a
backdrop of Jin Yong novels, Western European medieval legend, and
manga — an unusual crossover premise). `adm/obj/{master,simul_efun}`
layout. Small lib, ~3,839 raw files.

## Fixes applied

1. **AGENTS.md §15h**, with a pre-existing (non-UTF8) typo along for the
   ride: `adm/daemons/chinesed.c`'s `is_chinese()` had a `for` loop that
   always checked `str[0]` instead of `str[i]` — a genuine authoring bug
   predating this pass, not introduced by conversion. It was **harmless
   in practice** because the only caller, `logind.lpc`'s
   `check_legal_name()`, always invokes it with a fresh per-character
   slice (`CHINESE_D->is_chinese(name[i..<0])`) — so "always check index
   0 of whatever was passed" is equivalent to "check character i of the
   original name." Fixed to the standard single-character CJK codepoint
   check, which preserves this same effective (harmless) behavior while
   correcting the actual GBK byte-range logic (dropped the now-
   meaningless even-byte-length check and the loop, since only the first
   character of the argument ever mattered anyway).
2. `check_legal_name()`'s bound `strlen(name) < 2 || > 12` → `< 1 || > 6`
   (halved to character count), removed the `i % 2==0` even-byte-offset
   gate.
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in well under 10 seconds, zero compile errors,
   no hang.

## Interactive test result — full registration flow

No hidden pre-id prompts here (banner → stats → straight to the English
id prompt). Verified the complete registration path in one continuous
connection: id `xkyxbtest` → confirm `y` → **real Chinese name `秦风`**
(avoiding "张三丰"/Zhang Sanfeng — a real historical/wuxia figure found
in this lib's `banned_name` list, alongside game-specific terms) →
accepted, proceeds straight to "请设定您的密码：".

## lpcc sweep

3,178 files, 3,116 pass / 62 fail (98.0%). Failure tail is the usual
shape (missing globals, a handful of syntax typos) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~13GB free).

## Re-verification pass (2026-07-23)

Boot + registration re-tested end-to-end (real Chinese name 秦岭, English
id + race selection this time, since the original pass only verified up
to the password prompt). Found and fixed one new regression, same bug
class as AGENTS.md §15ah:

- **Missing `/log/nosave/` directory** (archive shipped without it, same
  "RAR/zip drops empty dirs" class as several sibling libs): `enter_world()`
  in `adm/daemons/logind.lpc` unconditionally `log_file("nosave/WARNING",
  ...)`s a potential/exp sanity-check note for every new player, and
  `adm/simul_efun/file.lpc`'s `log_file()` did an unguarded
  `write_file()` with no directory to write into — this **runtime error
  aborted the rest of `enter_world()`**, so the new character was never
  actually `move()`d to the start room (`look` showed the literal empty
  void, "你的四周灰蒙蒙地一片"), and `quit`'s `message("system", ...,
  environment(me), me)` then crashed on `environment(me)` being `0`
  (`Bad argument 3 to EFUN message()`). Fixed by creating `work/log/nosave/`
  and hardening `log_file()` (wrap `write_file()` in `catch()`) and `cat()`
  (guard with `stringp()`) in `adm/simul_efun/file.lpc`, matching the
  established pattern from sibling libs. Re-verified with a fresh
  registration (id `xkyxfixver`, name `秦岭`): `look` now shows the real
  start room content (the color-dog greeting from `d/beginner/start1.lpc`),
  `score` renders correctly, and `quit` completes cleanly with zero
  runtime errors in `debug.log`.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** (`tools/lpc-syntax/format-corpus.mjs`) run over all
  `work/*.lpc`: 3,178 total, 3,146 written, 21 already-idempotent, 11
  refused (self-check errors — expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver** (`build-debug`,
  rebuilt from latest upstream master today): clean boot, zero fatal
  errors. Full registration flow re-verified end-to-end in one continuous
  connection (id `qinlingueb`, real Chinese name `秦岭岳`, race `0`/human,
  gender `m`): `look` showed the real 小花狗/color-dog start-room greeting,
  `score` rendered the full character sheet, `quit` completed cleanly.
  Zero code changes needed — the reformatted source booted and played
  identically to before formatting.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm`): boots
  clean through preload (only the expected non-fatal `ftpd` preload
  error, same shape as native). The banner displays correctly, but the
  single WASM connection then dies during `logind.lpc`'s
  visitor-counter bookkeeping (`write_file(LOG_DIR "login/users", ...)`)
  before the English-name prompt is ever reached — **not the documented
  `query_ip_number()` limitation**, but a different WASM-harness gap:
  `wasm_client.js`'s `copyDir()` deliberately only creates a bare `log/`
  directory in the in-memory FS (skips copying subdirectory contents to
  avoid runtime-churn bloat), so `log/login/` doesn't exist inside the
  WASM instance even though it's a real, populated directory in the
  native `work/` tree. The unguarded `write_file()` in `logind.lpc`
  (not the hardened `log_file()` simul_efun) throws, and the connection
  is dropped. **Not a mudlib bug** — natively this directory exists and
  the counter update works fine — and not patched here (out of this
  pass's scope to modify the shared test harness or add defensive
  wrapping for a directory that's only missing under this specific
  test tool). Playability under WASM for this lib should be considered
  "boots, but blocked at the very first prompt by a harness FS gap,"
  distinct from the true IP-gating limitation seen on other libs.

## WASM-enablement pass (2026-07-23)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched:

1. **Loopback always allowed** — `adm/daemons/logind.lpc` `logon()`
   (around line 78-95): added an `_local` predicate computed from
   `query_ip_number(ob)` (true for `127.0.0.1`, a leading `127.` prefix,
   an empty/non-string IP, or any IP that fails a 4-part `sscanf` — i.e.
   WASM garbage). Guarded both connection-rejection gates with it:
   - the `BAN_D->is_banned(query_ip_name(ob))` destruct gate (line ~89),
   - the per-IP multi-login cap `if (IPCount > 10) destruct(ob)` (line ~113).
   `adm/daemons/band.lpc`'s `is_banned()` takes a *site name* string (not
   a raw connection) and is only reached via the guarded logind gate, so
   no separate patch there.
2. **Uptime startup gate** — none in the login path (no `uptime()<N`
   connection gate exists in logind); nothing to bypass.
3. **Anti-flood throttle** — the only per-IP throttle is the `IPCount>10`
   multi-login cap, now loopback-exempt via the same `_local` guard.
4. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   registered through the normal flow; granted `(admin)` by adding
   `fluffos (admin)` to `adm/etc/wizlist`. Verified `update` works.
   Save file: `work/data/user/f/fluffos/{user.o,login.o}` (NOT gitignored;
   shows as untracked — orchestrator must `git add` it).

Retest: fresh registration (秦风, race human, male) reaches world, `score`
renders; fluffos login + `update` works; zero new runtime errors in
debug.log. Test char `freshtest` removed; fluffos kept.

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** The original loopback
predicate above (item 1) treated an empty/non-string/malformed IP as
"local" (fail-open) — a defensive stopgap for a since-fixed WASM driver
bug (`query_ip_number()` used to return garbage like `"("` on WASM
connections). That bug is now fixed upstream, so this lib's `_local`
check was tightened to **fail-closed**: `adm/daemons/logind.lpc`'s
`logon()`, `_local` is now `stringp(_ip) && (_ip == "127.0.0.1" ||
_ip == "::1" || (strlen(_ip) >= 4 && _ip[0..3] == "127."))` — an
unparseable/empty IP is now treated as remote/untrusted (subject to the
normal ban/multi-login gates), not as loopback. Retested: fresh
registration (id `gatetesterone`→`gatetestone`, name 秦岭客, race human,
male) still reaches the world via loopback with `look`/`score`/`quit`
all correct; fluffos login + `update /adm/daemons/logind` still
succeeds. Zero new runtime errors from this change (the pre-existing
`apply() with insufficient permission ... command_hook ... needs:
private, has: hidden` lines seen in `debug.log` are the known §8.3a
`private nomask command_hook` class in `feature/command.lpc` — NOT
introduced by this pass, and did not block `look`/`score`/`update`/`quit`
in any observed session here; flagging for a future pass rather than
fixing now since it's outside this pass's four-item scope).

## 深度功能测试（第二轮，2026-08-03）

之前的会话只做过注册流程 + 管理员权限验证，本轮做了完整的 §10.7
深度功能测试。proactive 检查 AGENTS.md 已归档的四类常见坏味道：

- **§8.3a `private nomask command_hook`**：只在死档案
  `feature/command.c.new`/`feature/command.bak` 里还留着，真正生效
  的 `feature/command.lpc` 已经是 `nomask int command_hook`（没有
  `private`）——查了 git log 确认这是本项目更早一次系统性排查
  （`20f407c4048`）就已经修好的，上面"已知但未修复"那条关于
  `apply() with insufficient permission ... command_hook` 的记录已
  经过时，本轮重新测试全程没有再出现这条报错——**更正**：这条不再
  是待办事项。
- 命中了新的一类：`logind.lpc` 里两条并行取名流程（接受系统随机中
  文名 / 自己手动输入）都各自残留一行调试用的 `printf("%O\n", ob)`，
  紧挨在"请设定您的密码："提示之前，每一个新玩家注册时都会看到
  （AGENTS.md §7.34，新增 `xkyx3b` 到确认实例列表）。已删除两处。
- 未命中 unguarded MESSAGE_D->、stat/water 键名、§8.9 坏 age 判断
  这三类。

**完整流程验证**：连续注册多个全新角色，走完整个官方新手教程（游
戏本身把教程做成了六个连续房间：`start1`如何移动→`start2`如何看/
捡→`start3`如何吃喝购买→`start4`如何求助→`start5`关于战斗→`down`
进入正式世界），教程房间之间的出口方向并不是简单的连续东进（
`start2`出口是south，`start3`出口是west，`start4`出口是north），
按各房间实际定义的方向走通；`start5`教程明确指引"wear cloth"/
"wield sword"装备防具武器后"fight dog"和野狗打一场——照做，完整
交手十余回合，伤害叙述随野狗伤势分级变化（从"可能受了点轻伤"一路
到"受了相当重的伤，只怕会有生命危险"再到力竭倒地），战斗系统工作
正常；`score`/`hp`面板渲染正确（食物/饮水槽创建时即为满值，没有
§8.9 症状）；一路到达"中央广场"（登录留言板显示15张留言），
`quit`干净退出（"欢迎下次再来！"）。全程 debug.log 没有任何一条
`执行时段错误`——是这次会话覆盖的几个 lib 里少见的、从注册到教程
到战斗到 quit 全程零报错的一次。

**未覆盖范围**：留言板内容、拜师、商店购买、种族差异（矮人/精灵/
妖精/龙人/兽人五个非人类种族本轮未测）因时间原因未实测。

## Round-four gap-closing pass: board/apprentice/shop/race (2026-08-24)

Closed all four gaps flagged above. `scripts/tmux_mud.sh` hit its known
telnet-escape-character artifact partway through the board test (a
Chinese UTF-8 byte sequence tripped the *local* telnet client's `^]`
command mode, not a mudlib bug) — switched to `scripts/mudclient.py`
(raw socket, no local telnet interpretation) for the rest of the
session, which had no such issue.

- **Message board**: `post <title>` → in-line editor (end with `.`) →
  `look`/`read <n>` all worked correctly on `/d/center/guangchang`'s
  board (count went 15→16, title/author/body all round-tripped
  correctly); cleaned up with `discard 16` afterward. Clean.
- **Shop (`buy`)**: `/d/beginner/start3`'s waiter NPC (`F_VENDOR`
  mixin) — granted admin 10 两白银 (1000 value) via `clone` + `call
  ->set_amount()`, then `buy long sword` (id price 5 两白银/500):
  correct item added to inventory, correct change left (500, i.e.
  1000-500). `MONEY_D`'s change-making arithmetic in
  `adm/daemons/moneyd.lpc` is correct. Clean.
- **Sect apprenticeship (拜师)**: real master NPCs (`master-zhang`
  武当派, `hong-qigong` 丐帮, etc.) all gate `attempt_apprentice()` on
  skill levels far beyond what a fresh character has (50-150+), so
  admin used `call me->set(...)`/`set_skill(...)` to satisfy
  `master-zhang`'s requirement (`cps>=20`, `con>=25`, `int>=34`,
  `taiji-sword>=50`, `taiji-force>=60`), then `apprentice zhang` from
  `/d/wudangshan/wd-zl-4`: full flow worked end-to-end (NPC accepts,
  auto-`recruit`s, kowtow messages, "恭喜您成为武当派的第二代弟子").
  Reverted the admin's stats/skills/family/title back to pre-test
  values afterward. Clean — no crash anywhere in the apprentice/recruit
  code path.
- **Non-human race creation**: fresh registration (id `xkyxraceb`, name
  秦晓月, race `2`=精灵/Elf) all the way through `look`/`score`/`quit`.
  `种族：精灵族` displayed correctly, title `精灵族普通百姓`, and all
  eight base stats matched the elf stat block in `logind.lpc`'s
  `init_new_player()` (`13,14,21,21,14,20,15,17`-shaped, ± the 0-2
  random per-stat bonus `set_attribute()` adds) — no crash, no
  mismapped stat. Test character's save deleted afterward.

**Bug found and fixed (real crash, confirmed live in `debug.log`, not
content)**: wandering NPCs (`巡捕`/`捕快`, `xun-bu`) periodically drift
into rooms that haven't been visited yet, triggering that room's first
`reset()` → `make_inventory()` for its `"objects"` mapping. A handful of
rooms/NPCs reference files that don't exist in this archive:

- `/u/bibi/hai`, `/u/bibi/baotu`, `/u/bibi/shounao`,
  `/u/bibi/xiaoruer` — items/NPCs from a wizard's `/u/bibi/` home
  directory not included in this archive (referenced from
  `d/center/furen.lpc`, `d/center/zhu.lpc`,
  `d/quanzhou/main-e2n3.lpc`'s `"objects"` mappings).
- `/obj/weapon/ling` (铜铃) — compiles, but its own `inherit LING`
  (`/std/weapon/ling`) doesn't exist anywhere under `std/weapon/`
  (only sword/blade/axe/dagger/fork/hammer/multi/staff/stick/
  throwing/whip base classes are present) — referenced from
  `d/tianshigu/ts-dyl.lpc`.
- `/u/bibi/yitian` (倚天剑) — same missing-home-dir shape, but reached
  via an **unguarded chained call** instead of the `"objects"` mapping:
  `d/wizard/npc/{shizhe,shenxian-shizhe}.lpc`'s `create()` does
  `carry_object("/u/bibi/yitian")->wield();` — `carry_object()` already
  guards its own `new()` and returns `0` for a missing file, but the
  immediate `->wield()` chain on that `0` crashes anyway.

Root cause in the shared code: `std/room.lpc`'s `make_inventory()` did
`ob = new(file); ob->move(this_object());` with **no check that `new()`
succeeded** — for an ordinary missing file this is `Bad argument 1 to
EFUN call_other() ... Got: int(0)`, and for a file that exists but has
a bad `inherit` (the `ling` case) `new()` itself throws
(`Inherited file '.../ling' does not exist!`) rather than quietly
returning 0. Fixed by wrapping the `new()` in `catch()` and returning 0
on failure; `reset()`'s `case 1` branch (single-instance `"objects"`
entries) also lacked the same "skip if the object didn't load" guard
that the `default:` (multi-instance) branch already had via its
`continue`, so added a matching `if (!objectp(...)) break;` there too.
Also fixed the two `carry_object(...)->wield()` unguarded chains in
`shizhe.lpc`/`shenxian-shizhe.lpc` directly (assign-then-check instead
of chaining).

Also fixed a **hard compile error** discovered via the same
`lpcc_check.sh` pass, unrelated to the missing-`/u` pattern:
`d/beijing2/zhang/npc/wife3.lpc`'s `create()` called
`return_home("/beijing2/zhang/room7.lpc")` — a bare string — but
`return_home(object home)` (this file even carries its own byte-for-byte
copy of the parent `std/char/npc.lpc` implementation, doing nothing
custom) requires an `object`. This is dead/erroneous leftover code (the
NPC already manages its own coming-and-going via `goout()`/`do_return()`
with hardcoded `move()` paths); the call has no effect on anything else
in the file and its bad-type argument was a **hard compile failure**
that took the whole NPC object (and by extension its room's `"objects"`
entry) down. Removed the line.

**Verification**: `scripts/lpcc_check.sh` pass count went from
3116→**3142**/3178 (fail 62→**36**) purely from these fixes (no other
changes) — the room-load crash was cascading into several other
objects' compile counts. Live-boot spot check: fresh driver restart,
visited `/d/center/furen`, `/d/center/zhu`, and
`/d/wizard/guest_room` (where `shenxian-shizhe` really lives) directly
— all load cleanly, `shenxian-shizhe`'s missing sword silently and
correctly skipped (just wears the cloth, no crash). Zero new
`执行时段错误` in `debug.log` from normal play afterward. (One
artifact-only error was seen mid-session from `goto <bare npc file>`
directly instantiating `shizhe.lpc` outside any room, so its `greeting()`
→ `command("say ...")` hit a null `environment()` — not reachable in
normal play since `shizhe.lpc` isn't placed in any room's `"objects"`
mapping at all, and `shenxian-shizhe.lpc` (which is) works fine when
visited the normal way.) Remaining `lpcc` failures are pre-existing,
individually-untriaged content gaps (missing globals, syntax typos,
plus the still-irreducible `/obj/weapon/ling` compile failure since
its `/std/weapon/ling` base class was simply never included in this
archive and authoring a new weapon-type class is out of this pass's
scope).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'目前权限：(admin)'，quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 4 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 信件系统整体死亡（与 xkyxciii 完全同源的 bug）

`adm/daemons/logind.lpc` 的 `enter_world()` 在创建/挂载玩家的邮箱物件
之后紧跟一行多余的 `destruct(mail_box)`——这销毁了那个在 `init()`
里注册全部六个信件指令（`send`/`mail`/`forward`/`check`/`from`/
`read`/`discard`）的物件，导致每一次登录、每一位玩家的信件系统
完全失效，报"什么？"（未知指令），且没有任何玩家可见的错误提示。
这个 bug 是 `xkyxciii` 那一轮 round-three 深度测试发现并修复后，
用同一行代码做全库 grep 时命中的姐妹档案（`libs/xkyxciii` 的
NOTES.md round-three 章节里已经记录了这条线索）。修复：删除多余的
`destruct(mail_box)` 调用。已用干净重启的驱动实测验证：
`fluffos`/`Mud@2026` 登录后，`send`/`check`/`from`/`read` 全部给出
正常的交互式提示（标题/内容/是否留底 y-n 询问、"没有这个编号的
信件"等），不再是未知指令；`debug.log` 全程干净。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/std/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,452 live
occurrences** (survey-ranked #90 of 166 candidates >=100, tied with
sibling lib `xkyxciii`, both 侠客英雄传III but distinct archives/
snapshots). Fixed with the sweep's binary-mode script
(`fix_710_room.py`); `git diff --numstat` totals (0 insertions, 1452
deletions) match the survey's live-occurrence count exactly. Like
`xkyxciii`, this lib has no in-game room-building tool, so no
factory-bug variant to fix. No `work/data/` room-source false-negative
found. Verified via a clean `build-debug` boot (zero "cannot
replace"/"cannot bind" `debug.log` lines, port 40036 listening) plus a
live spot-check: no admin `fluffos` save currently exists in
`data/login/`, so a fresh test account was registered through the full
flow (id → confirm → Chinese name → password → email → gender → race)
and landed at the new-player training room; `look`/`quit` both worked,
`debug.log` stayed clean throughout. Test account's save directory
deleted before committing.

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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 1 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 1 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/huashan/yongdao2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/apr/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt xkyxciii xkyx3b` 把 xkyxciii 警告整理提交（59e3eb25955）里的改动搬到 210 个修改前与它一致的文件（逐文件核对非 ASCII 文字：没有丢失或改动），剩下的再跑 `scripts/lpc_warnings.py xkyx3b --fix`，共改动 214 个 `.lpc`。HEAD 与工作树分别加载（新进程）：206 -> 206 通过，无回退。

启动时警告 37 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `adm/daemons/natured.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 0, tree PASS 0; regress 0; newly loading 0），这些文件的警告 2 -> 0。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 编译警告收尾（2026-10-12）

孪生库 xkyxciii 同日的整理（f771e14aebc）用 `scripts/lpc_twin_port.py adopt xkyxciii xkyx3b --pre f771e14aebc~1` 搬来，8 个文件与 xkyxciii 修前逐 token 相同：`std/skill.lpc` 的 `mapping action` 栏位说明改成注释（71 个武功的 `Redeclaration of global variable 'action'` 由此而来），真正拿它当缓冲的 `baigu-claw.lpc`、`example.lpc` 各自声明；`dog.lpc` 的 `(: "random_move" :)` 改 `(: random_move :)`（狗从不走动）；`biantai-kuangmo.lpc` 的 `killer` 改名 `target_ob`；`killa.lpc` 多余的 `};`。继承 `SKILL` 的全部对象加改动文件 HEAD 与工作树各载入一次：156 个，HEAD PASS 155，tree PASS 155，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/adm/daemons/combatd.lpc`（`damage -=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：2 个对象，新增载入 0，回退 0。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、5 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/quanzhou/npc/obj/yellow_cloth`、`/d/quanzhou/npc/obj/green_cloth`、`/d/quanzhou/npc/obj/yayifu`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 5 个（5 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 14 个对象设了本库没有文件的武功（4 个名字，最多的是 `kunlun-force`、`kunlun-zhang`、`kunlun-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：14 个里 14 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/dali/d-jiangjun-s` 的 `south`：`d-xiaogongyuan` → `d-xiaohuayuan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/obj/wizard/workroom.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/usr/to.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `teamkill` 指令编译不过：条件少了右括号（2026-10-20，KB 04 §6.25）

`cmds/std/teamkill.lpc` 第 43 行 `if (userp(obj) && (int)obj->query("combat_exp") < LOWER_LIMIT && !me->query("licensed_to_kill")` 的条件没有收尾的 `)`，下一行的 `return notify_fail(...)` 就成了条件里的语法错误（`syntax error, unexpected L_RETURN`），指令从来没有加载过。补上 `)`，其余照原样（同一目录的 `kill.lpc` 里这个条件多一个 `|| obj->query("age") < 16` 分支，没有搬过来）。xkyx3b 和 xkyxciii 的同一行相同，同样修改。加载检查：各 1/1，HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 4 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/center/npc/biantai-kuangmo.lpc`、`/d/gaibang/npc/traitor.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/apr/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 4 条注册（3 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/center/gongzi.lpc`（`do_vendor_list`）、`/d/center/npc/gongzi.lpc`（`do_vendor_list`）、`/obj/npc/meng-zhu.old.lpc`（`do_answer`）。最多的函数名：`do_vendor_list` 2 处、`do_answer` 2 处。没有动（读过）：`/d/beijing2/zhang/obj/room7.lpc` 的 `do_get`（对象本身编译不过，登记留着，等对象能加载再处理）。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/chance`（`d/beijing2/curio_seller.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。测试对象里本库的 `log_file()` 什么也没写（探针对象没有写权限，`log_file()` 自己也不建目录），所以真实调用者会得到什么没有测出来。把 `log/chance` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 2 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

