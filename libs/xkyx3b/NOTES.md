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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'目前权限：(admin)'，quit 正常。
