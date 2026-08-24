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
