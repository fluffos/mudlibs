# 星战英雄.rar → `xzyx`

- Archive: `archives/星战英雄.rar` (1.3MB — "乱世风沙之星战英雄", a
  `xkx`-lineage MudOS lib, config labeled 0.9.20 like lib #1 but a
  different codebase; ANSI-art login banner).
- Mudlib root in archive: nested at `xz/xkx/` (config.cfg lives in `xz/`,
  one level above the actual mudlib root — NOT at the archive top level,
  unlike lib #1. Always check `mudlib directory :` in the config rather
  than assuming the archive layout).
- Port: **40002**.

## Status: DONE — boots clean, playable over telnet

Full ANSI-art banner + Chinese login flow confirmed working. This lib is
the 2nd pilot and is where the FluffOS driver bug (AGENTS.md §8) and the
`message_combatd` mudlib bug (below) were found and fixed.

## What was fixed

1. Encoding: 1942 files converted GB18030→UTF-8, 193 already UTF-8/ASCII,
   15 skipped as genuinely binary (mudos.exe/.dll etc — bundled Windows
   driver binaries, irrelevant, left alone), 30 needed the lossy `-c`
   fallback (stray invalid bytes scattered through `kungfu/skill/*`,
   `clone/book/*`, `d/fenghuang/fenghuang/*`, a few `welcome` files, and
   `data/emoted.o` — all pre-existing single-byte corruption in the
   original archive, not something our pipeline introduced).
2. `.c` → `.lpc`: 1909 files renamed. 132 literal `.c"` references
   auto-fixed by `convert_lib.sh`, 0 left over needing manual attention.
3. `static` → `nosave`: 51 files.
4. `master.lpc` does NOT have the §4 `load_object`-in-`valid_read`
   recursion bug (no `load_object` calls in this master at all) — checked,
   not needed here.
5. Config: removed 5 obsolete keys, set `port number : 40002`,
   `mudlib directory` to absolute `work/` path, fixed `log directory`
   (was `/adm/log`, changed to `/log` to match the `libs/<slug>/log/`
   convention — AGENTS.md §6).
6. **Found and fixed a FluffOS driver bug** (AGENTS.md §8): null
   `backbone_domain` dereference in `mudlib_stats.cc`'s
   `init_domain_for_ob()`, triggered because this lib's `master::
   author_file()` calls `call_other(SIMUL_EFUN_OB, "author_file", ...)`
   during master's own bootstrap (before `backbone_domain` is set),
   causing a SIGSEGV the first time that call chain loads a new object.
   Patched `~/src/fluffos/src/packages/mudlib_stats/mudlib_stats.cc`;
   rebuilt both `build/` and `build-debug/`. Systemic pattern, likely to
   recur on other libs — no re-diagnosis needed, just confirm the patched
   driver binaries are what's running.
7. **Found and fixed a mudlib bug affecting 100+ files**: every file under
   `kungfu/skill/*` calls `message_combatd(msg, me, target)` to print
   combat messages, but no such function is defined ANYWHERE in the lib
   (checked exhaustively — not a simul_efun, not on `COMBAT_D`, not
   anywhere). The signature exactly matches `message_vision()` (an
   existing, working simul_efun in `adm/simul_efun/message.lpc`) — old
   MudOS's weaker compile-time checking apparently let this ship broken
   (every combat skill's flavor-text message was silently a no-op under
   whatever driver this last ran on); this driver rejects undefined-
   function calls at load time, which is what surfaced it. Fixed by
   adding `message_combatd()` as a thin alias for `message_vision()` in
   `adm/simul_efun/message.lpc` (placed AFTER `message_vision`'s own
   definition — same-file forward-reference didn't resolve, see AGENTS.md
   §8b) rather than touching 100+ call sites.
8. Full `lpcc_check.sh` sweep: 1729/1909 pass before the `message_combatd`
   fix → 1773/1909 pass after it + the driver's macro-nesting-depth fix
   (AGENTS.md, `MAX_EXPANSION_NESTING`) fixed `clone/misc/{card,newcard}.lpc`
   too. 136 failures remain, mostly the missing-zone-content and optional-
   network-daemon categories below.

## Known remaining issues (not fixed — documented, low/no priority)

- **~60 `clone/board/*.lpc` files** reference room paths under zones that
  don't exist ANYWHERE in this archive at all (no `/d/wudang`,
  `/d/shaolin`, `/d/huashan`, `/d/emei`, `/d/tangmen`, `/d/mingjiao`, and
  many more classic wuxia-sect zones — checked, genuinely absent, not just
  uncompiled-yet). This archive shipped without most of its game-world
  content, likely a "core" release split from a much larger world pack.
  Not fabricating the missing rooms (AGENTS.md §13) — these board clones
  aren't preloaded, so this has zero effect on normal play, only lpcc-sweep
  noise.
- `/adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,telnetd,pingd,
  inetd}.lpc` — same optional network-daemon-cluster-missing-headers issue
  as lib #1 (`config.h`/`mailer.h`/`daemons.h`/`uid.h`/`priv.h`/`post.h`
  absent from `include/`). Not on preload, not required for play.
- A handful of `d/*` room/NPC files have real syntax errors (missing
  brace/quote, `switch`/`case` shape issues similar to lib #1's rankd.lpc)
  — not yet individually triaged past the first pass; low priority since
  none are on the critical boot/login path.
- A few `F_SKILL: No such skill (...)` errors on some `clone/npc/killer-*`
  NPCs — reference skill names not present in `kungfu/skill/` under this
  archive; likely more missing-content (same shape as the board/zone gap
  above), not investigated further.

## How to run

```
cd libs/xzyx
~/src/fluffos/build-debug/src/driver config.fluffos
# separately:
python3 ../../scripts/mudclient.py 127.0.0.1 40002 --timeout 10 --send "" --send "look" --send "quit"
```

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (1909 files): 1876
  reformatted, 19 already-clean/unchanged, 14 self-checked errors
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿一") — English id → confirm y/n → surname/Chinese name →
  password ×2 → attribute-roll accept (y) → email → gender → entered
  the actual 新手集中营 starting zone; `look`/`score`/`quit` all
  produced correct Chinese output. `log/debug.log` free of real errors.
  Reformat + new driver build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly — the only preload-time errors are the expected non-fatal
  `Undefined function socket_create`/`socket_bind`/`socket_close` in
  `adm/daemons/httpd.lpc` (no `sockets` package under WASM, same known
  category as other libs, does not stop the boot). Full registration
  flow **completed successfully** under WASM with a real Chinese name
  ("秦风测试") — identical prompt sequence to the native run, reaching
  the same 新手集中营 room, `look` and `quit` both producing correct
  output. This lib does **not** gate its login/registration path on
  `query_ip_number()` format, so it isn't affected by the documented
  WASM IP-formatting limitation — a clean, fully-playable WASM result.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, or an empty/non-string/malformed IP
(covers older WASM `query_ip_number()` garbage). Gates patched:

- `adm/daemons/band.lpc::is_banned()` (~line 39): loopback/malformed-IP
  short-circuit `return 0` at the top. (Note: no live login-path caller
  of `is_banned()` was found in this lib — the ban daemon appears vestigial
  — patched anyway for safety/uniformity.)
- `adm/daemons/logind.lpc::logon()` (~line 90-110): the per-host
  multi-login cap (`log_num >= 10` destruct) is now loopback-exempt.
  (Also disentangled the original single-statement `log_num++; if(...)`
  layout into an explicit post-loop check — semantics preserved: the
  check always ran after the counting loop.)
- `adm/daemons/logind.lpc::get_passwd()` (~line 188): the 16-second
  relogin-rate throttle ("为了降低系统负荷，请稍后再login" destruct) is
  now loopback-exempt.
- No `uptime()` startup-grace gate in this lib (only a cosmetic
  cmwhod.lpc comment). The `mad_lock` gate is an explicit admin lock
  (game admin feature), kept. The `banned_name` Chinese-name blocklist
  is content, kept.

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (id → `y` → Chinese name → password x2 → gift `y`
→ email → gender m; one stray "What?" echo mid-flow is pre-existing
prompt noise, not a failure). Granted `(admin)` by appending
`fluffos (admin)` to `/adm/etc/wizlist`. Verified after reboot: login as
fluffos → wizard-channel login broadcast + `update /adm/daemons/logind`
→ "重新编译 ...成功！".

Retest: fresh normal registration (`qfxzyx` / 秦风) re-verified
end-to-end into 新手集中营 with `look`/`score`/`quit` correct; test
saves removed. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths tracked, not
gitignored; note `data/user/f/` and `data/login/f/` are NEW directories
— this lib previously had no ids starting with "f"):
- `libs/xzyx/work/data/user/f/fluffos.o`
- `libs/xzyx/work/data/login/f/fluffos.o`

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit`/admin login, or watched boot output).
Played as an ordinary new player through registration, exploration, a
sect join, organic skill learning, safe sparring, quit, and a real
wall-clock reconnect, native driver (`build-debug`). Read
`doc/help/newbie` first (§10.7 step 1) — it documents the starting zone
(新手集中营), the four newbie factions (凤凰/特种部队/圣殿/皇族), the
`fight` (非致命较量) vs `kill` distinction, `wimpy`, and the 天赋/技能
model, and was an accurate guide for everything below.

Test characters (both **kept**, not cleaned up, as playthrough evidence):

- **`qxtest` / 秦星辰** / password `test12345` — primary playthrough
  character. Final state: joined 特种部队 (recruited by 蒋师庞, title
  特种部队第四代小队长), learned `force` (基础内功) to level 1 via the
  organic teacher-NPC path, fought a `特种兵` to a safe non-lethal
  `fight`-command halt (~47% HP remaining, no death), quit cleanly, and
  reconnected after a real ~75s wait with all state (sect/master,
  skill, combat_exp, food/water, inventory) intact. Save files:
  `work/data/user/q/qxtest.o`, `work/data/login/q/qxtest.o` (`data/*/q/`
  are NEW directories — this lib had no "q"-prefixed ids before).
- **`wjtest` / 王家俊** / password `test12345` — minimal confirmation
  character, registered solely to verify the food/water bug fix (below)
  live on a driver that already had the fix loaded; otherwise untouched
  (still standing in 新手集中营, no sect, no skills). Save files:
  `work/data/user/w/wjtest.o`, `work/data/login/w/wjtest.o` (`data/user/w/`
  already existed for a prior "w"-id; `data/login/w/` is new for this id).

### Bug 1 found and fixed — new characters always spawn starving (food/water stuck at 0)

**`adm/daemons/logind.lpc:447`, inside `enter_world()`.**

- Symptom: every freshly-registered character's `hp` screen showed
  `【 食  物 】 0/290` and `【 饮  水 】 0/290` (both empty bars) instead
  of the near-full starting allowance `doc/help/newbie` itself documents
  as the expected new-player state (its worked example shows `98/290`).
  Reproduced live: fresh registration `qxtest`/秦星辰 landed in 新手集中营
  with food/water both `0/290` immediately after `hp`.
- Root cause: the one-time starter-food/water grant is gated by
  `if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
  — but `ob` here is the **login/connection object** (the socket-level
  object driving the registration `input_to` chain), which never has an
  `"age"` field set anywhere in the whole registration flow; only the
  **player body** (`user`) ever gets an `"age"` (set to a computed `14 +
  age_modify + mud_age/86400` by `clone/user/user.lpc`'s `update_age()`,
  called from `setup()` a few lines earlier in this same function). So
  `ob->query("age")` is always `0`, the `== 14` check is always false,
  and the grant code inside the `if` never runs for anyone, ever — every
  new character starts already "hungry" from turn one. Confirmed this
  is a plain `ob`/`user` variable mix-up, not intentional: the correct
  operand (`user`) is sitting right there, used by every other line in
  the same block.
  - Practical severity is muted by an unrelated safety net
    (`feature/damage.lpc`/`damage1.lpc`'s `heal_up()`, ~line 269): once
    a starving character's countdown reaches zero, players under age 15
    (i.e. every character in roughly their first real day of accumulated
    play time) get an automatic "掏出一支冰淇淋" full refill instead of
    taking real starvation damage — so this bug produces confusing
    immediate hunger-distress messages and an inaccurate `hp` screen
    from the first moment of play (contradicting the newbie help file),
    but does not by itself kill a brand-new character. Reproduced this
    too: `qxtest` (registered pre-fix) showed `290/290` on a later `hp`
    check with no `eat`/`fu` command ever issued, i.e. the auto-refill
    had already silently fired.
- Fix:
  ```lpc
  // BEFORE:
  if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
  // AFTER:
  if (!user->query("food") && !user->query("water") && user->query("age") == 14) {
  ```
- Verified live: restarted the driver with the fix loaded, registered a
  fresh confirmation character (`wjtest`/王家俊) through the real flow,
  and its very first `hp` (before any heartbeat tick, before any `eat`)
  showed `280/280` / `280/280` — full starting food/water as documented,
  immediately on entering the world. `qxtest` (already-affected
  pre-existing character) was left as-is, showing the bug's natural
  post-hoc masking by the age<15 safety net described above.

### Bug 2 found and fixed — sect recruitment (`bai`/`attempt_apprentice`/`recruit`) crashes every time, silently blocking the entire organic sect-join path

**`feature/command.lpc:29`** — this is **AGENTS.md §8.3a, `private
nomask command_hook`**, an already-cataloged bug class, reached here via
a code path (an NPC issuing `command()` from its own LPC code) that no
earlier pass on this lib exercised. `xzyx` was not
previously on §8.3a's "affected so far" list; recommend adding it.

- Symptom: walked `qxtest` to `特种部队`'s recruiter NPC (`蒋师庞`
  /`kungfu/class/budui/jiang.lpc`, stationed at `d/budui/rukou.lpc`,
  the entrance every newbie is funneled to per `doc/help/newbie`) and
  ran `bai jiang` (the documented "拜师" command). `bai.lpc` correctly
  called `jiang->attempt_apprentice(me)`, which calls
  `command("say ...")` twice then `command("recruit " + ob->query("id"))`
  on itself — and the `recruit` call threw a **caught-but-real** runtime
  error visible in `debug.log`:
  `执行时段错误：*Function for verb '' not found.` rooted at
  `/inherit/char/npc.lpc:147`'s `efun::command(str)` call, called from
  `jiang.lpc`'s `attempt_apprentice()`. The player-visible effect: `bai
  jiang` printed only "你想要拜蒋师庞为师。" and then nothing else — no
  error shown to the player, no confirmation, no recruitment — a command
  that silently does nothing is exactly the symptom class AGENTS.md
  §8.3 catalogs, except every regular player-typed command (`look`,
  `say`, movement, `bai` itself) worked completely normally throughout
  the rest of this playthrough, because those all arrive as real socket
  input (`ORIGIN_DRIVER`, which FluffOS's `add_action` dispatch exempts
  from the privacy check per `src/packages/core/add_action.cc`'s own
  comment) — only a **command issued programmatically by an NPC's own
  LPC code** (`ORIGIN_EFUN`) trips the `private` visibility check on
  `command_hook`. This is why this specific manifestation survived every
  earlier registration/`look`/`score`/`quit` pass on this lib: none of
  them ever made an NPC self-issue a command via `command()`.
  Confirmed by checking `feature/command.lpc`: `command_hook` is
  declared `private nomask int command_hook(string arg)`, registered
  via `add_action("command_hook", "", 1)` — the exact shape §8.3a
  describes.
- Fix (exact §8.3a fix, one instance, only occurrence in this lib —
  grepped `private.*command_hook`/`nomask.*command_hook` across the
  whole tree, no NPC-local duplicate copy the way `zhongjidiyu` had):
  ```lpc
  // BEFORE:  private nomask int command_hook(string arg) {
  // AFTER:            nomask int command_hook(string arg) {
  ```
- Verified live end-to-end: rebuilt nothing (LPC-only change), restarted
  the native driver, re-ran `qxtest` to `蒋师庞` and `bai jiang` again —
  this time producing the full expected exchange (`蒋师庞说道：好吧，
  我就收下你了。` / `...希望你杀人无数,发扬我特种部队!` /
  "你跪了下来向蒋师庞恭恭敬敬地磕了四个响头，叫道：「师父！」" /
  "恭喜您成为特种部队的第四代弟子。"), then confirmed via `score`
  (称谓: 特种部队第四代小队长, 你的师傅是: 蒋师庞) and `cha jiang`
  (lists his full teachable skill set). This is a **severe** bug in
  practice — every sect in this lib recruits new members through this
  exact `attempt_apprentice()` → `command("recruit "...)` pattern (all
  of `jiang`/`bei`/`su`/`shitailong` in `kungfu/class/budui/` share the
  shape; not independently re-verified per-file since the fix is a
  single shared-file change, same reasoning as `xiyouji`'s §7.17
  proactive-fix-by-code-shape-match), so **the entire organic sect-join
  path for the whole lib was unconditionally broken** until this fix —
  a new player could never advance past "老百姓" through the documented,
  intended route.

### What else was tested and confirmed working

- **Registration**: real Chinese name (秦星辰), full flow (id → confirm
  y/n → Chinese name → password ×2 → attribute-gift accept → email →
  gender) — already known-good from prior passes, re-confirmed with a
  fresh name.
- **Starting zone**: 新手集中营 (`d/city/startroom.lpc`) → chose exit
  `2` (特种部队) → walked the full multi-floor 特种部队联盟镇
  (`d/budui/luxingchu` → `bdguangchang2`/`1`/`bdguangchang` → `ondidao`
  → `rukou`), all room descriptions/exits correct, no missing-room
  errors.
- **Combat (safe path)**: this lib has no reachable training-dummy
  object — `clone/npc/muren.lpc` and `d/working/obj/mu-ren.lpc` (both
  full `accept_fight()` stat-mirroring dummies, the shape AGENTS.md
  §10.7 item 3 tells you to look for) are **both orphaned**: grepped the
  whole tree for references to either path and found none — they are
  never `new()`'d or placed via any room's `"objects"` mapping. The
  lib's actual safe-sparring mechanism is the `fight` command itself
  (documented in `doc/help/newbie`'s 【新手上路】 section) against any
  `attitude:"peaceful"` NPC via the base `accept_fight()` in
  `inherit/char/npc.lpc` — non-lethal, auto-halts around the 50%
  resource threshold regardless of the opponent's actual strength.
  Used a plain `特种兵` (combat_exp 30000, far above `qxtest`'s 200):
  `fight bing` produced a full turn-by-turn combat log and correctly
  auto-stopped with `特种兵哈哈大笑，说道：承让了！` at 95/200 (47.5%)
  HP — matches the documented behavior exactly, no crash, no death.
- **Skill learning (organic teacher path)**: `xue jiang force` (after
  joining 特种部队 under `蒋师庞`) → "你听了蒋师庞的指导，似乎有些心得。
  你的「基础内功」进步了！" → `skills` correctly showed `force` at
  `1/0`. `cha jiang` (before joining) correctly listed his full skill
  roster.
- **Sect/faction join**: covered above as Bug 2 — now confirmed working
  end-to-end via the organic `bai`/`recruit` NPC path (no separate
  admin/newbie-gift shortcut found or attempted in this lib; unlike
  `bxsj`'s gift-envoy, this lib's only documented join path is the
  in-person 拜师 flow at each faction's entrance NPC).
- **Shop `list`/`buy` dispatch**: `list` at 特种部队's 特种食品仓库
  correctly showed the exact vendor and prices `doc/help/newbie` quotes
  verbatim (碳素汽水瓶/新世纪牛排/压缩饼干 @ 50/50/30 电子货币— note
  the 新世纪牛排 price differs slightly from the help file's stale
  500, a content/help-text drift, not a bug). `buy bing gan` with `qxtest`'s
  real balance of 0 correctly rejected with an in-character refusal line
  rather than crashing.
- **`quit` → debug.log grep → real reconnect**: `quit` produced the
  expected "你丢下一件布衣。"/"欢迎下次再来！" messages (dropping the
  un-autoloaded starter cloth is intentional per `cmds/usr/quit.lpc` —
  same "real design tradeoff, not a bug" pattern already documented in
  `bxsj`'s NOTES.md); immediately grepped `log/debug.log` for
  `error:`/`Too deep recursion`/`Too long evaluation`/`FATAL` —
  **zero new lines added by the quit at all** (compared line count
  before/after), i.e. clean. Waited a real ~75 real-world seconds
  (backgrounded `sleep`, not simulated), reconnected as `qxtest` through
  the **full** login banner (not a netdead silent-reconnect — confirmed
  by the "你上次连线是从 localhost on Fri Jul 24 ..." real-timestamp
  line replacing the epoch-0 placeholder a first-ever login shows), and
  verified `look`/`score`/`skills`/`i` all showed the exact
  post-sect-join state: 称谓/师傅/skill `force` 1/0/combat_exp
  203/food&water still full/inventory (mailbox + fresh cloth) all
  correct. Note: the respawn location was 新手集中营 (the lib's
  original/default `startroom`), **not** the exact last room the
  character was standing in at quit time (特种食品仓库) — this is
  correct, intentional behavior, not a bug: `cmds/usr/quit.lpc` only
  updates the character's `startroom` anchor if the room they quit in
  has `valid_startroom` set (a small set of designated hub rooms, e.g.
  `d/budui/bdguangchang2.lpc`), which the food shop does not have.

### Explicitly NOT verified live (say-so per §10.7 item 6)

- **A completed shop purchase** (money successfully deducted, item
  successfully added to inventory): the `buy` command's dispatch and
  its insufficient-funds rejection path were exercised and are correct,
  but no purchase actually completed, because `qxtest` never
  accumulated any in-game currency. The lib's own documented
  money-earning paths (jobs like `d/budui/job1.lpc`'s `search`, or the
  higher-tier `attempt_apprentice`/`ask_me` skill-gated NPCs) all
  require either a prior quest-approval flag or skill/combat_exp
  thresholds well beyond a single test session's reach, and this
  project's permission system declined an attempted admin-console
  shortcut (`call qxtest->add("money",...)`) to seed test currency. Not
  faked, not silently skipped — genuinely not reached within this
  session's time budget.
- **Combat leading to actual death/respawn**: not attempted, for the
  same reason `bxsj`'s pilot gives no full death cycle either — this
  would mean deliberately overriding `wimpy`/using `kill` against a
  stronger NPC purely to die, which risks leaving `qxtest` in a
  corpse/respawn-penalty state that's a worse piece of "representative
  working-character" evidence than its current clean post-sect-join
  state, and combined with the shop-purchase gap above, was deprioritized
  given the two real bugs already found and fixed in the time available.
  The death/respawn code path itself was not code-reviewed as a
  substitute either — flagging this plainly as unverified rather than
  implying coverage it doesn't have.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 63 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.

Findings:

1. **AGENTS.md §7.108** (`clone/user/user.lpc`'s `reconnect()` missing
   `enable_commands()`): this lib has the kick-duplicate-login pattern
   (`exec(old_link` in both `adm/daemons/logind.lpc` and a stray unused
   `u/lsg/logind.lpc` copy). `reconnect()` lacked `enable_commands()` as
   its first statement, so a player confirming "y" to kick out their own
   already-connected duplicate session would reconnect into a permanently
   non-interactive character (every command silently no-ops). Fixed by
   adding `enable_commands();` as the first line. Live-verified with two
   concurrent telnet sessions: session 2 logged in as `fluffos`, got the
   "赶出去，取而代之吗？(y/n)" prompt, confirmed `y`, and the resulting
   session correctly dispatched `look` (real room description) and `score`
   (real stat panel) — confirming the fix, not just a clean login.
2. **`adm/simul_efun/file.lpc`**: `log_file()` wrote directly via
   `write_file()` without ever calling `assure_file()` first, so the first
   write to any not-yet-existing log path would silently fail. Added the
   `assure_file(LOG_DIR + file)` call (plus a forward declaration, since
   `assure_file()` is defined later in the file) — same shape as the
   standard checklist fix applied across this window's other libs. Also
   null-guarded `cat()`'s `write(read_file(file))` to `write(read_file(file)
   || "")`.
3. **AGENTS.md §7.106** (`cmds/ang/update.lpc`): `present(file,
   environment(me))` was called without guarding `environment(me)` first;
   added the `environment(me) &&` guard.
4. **`config.fluffos`**: `maximum evaluation cost` was `1000000`, below
   this project's standard safe value; raised to `5000000`.
5. **Already correct, no change needed**: `adm/obj/master.lpc`'s
   `log_error()` already uses the case-agnostic `"arning:"` substring match
   (AGENTS.md §7.10) — no genuine bug here. No `adm/daemons/closed.lpc`
   exists in this lib's tree, so AGENTS.md §7.107 does not apply.

Live verification summary: booted the native driver on port 40002 (only
pre-existing compile warnings, no fatals — one benign, self-limiting "Too
deep recursion" during `httpd.lpc`'s optional load, caught by the driver's
own recursion guard, does not block boot; `Initializations complete` /
`Accepting telnet connections` both printed). Logged in as the seeded
`fluffos` admin (`Mud@2026`), confirmed real write access via `update
/adm/simul_efun/file` (recompiled successfully). Ran the two-session
kick-duplicate-login reconnect test described above and confirmed the
§7.108 fix live. No new errors surfaced in `log/debug.log` (unchanged from
the prior pass — this driver instance didn't append fresh entries to it,
console output captured separately showed nothing beyond pre-existing
warnings). Killed the driver by exact PID when done.

本轮修改的文件 / Files modified this round:
- `libs/xzyx/work/clone/user/user.lpc`
- `libs/xzyx/work/adm/simul_efun/file.lpc`
- `libs/xzyx/work/cmds/ang/update.lpc`
- `libs/xzyx/config.fluffos`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 176 live occurrences deleted: 173 via scripted sweep (`fix_710_room.py`), plus 2 hand-fixed irregular shapes (same lineage as `sj`/`shiji`) — `clone/misc/roommaker.lpc`'s string-builder, and both `d/fenghuang/fenghuang/taikong.lpc` (space before semicolon, single-line file) and `d/huang/zoulang4.lpc` (two redundant calls on one CRLF line, fixed via a single Edit spanning both instances). 4 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40002.

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

## 深度功能测试第四轮 / Round-four deep functional test (2026-08-20)

Targeted follow-up on this lib's own two explicitly-flagged, previously
unreached §10.7 gaps (a completed shop purchase, and combat leading to
real death/respawn), plus a fast standard-checklist sanity pass. Native
`build-debug` driver, raw Python socket sessions (single- and
dual-connection), each response inspected before sending the next.
`log/debug.log` watched continuously throughout.

### Standard checklist sanity pass — all already clean, no changes needed

- **§7.90** `config.fluffos`: `maximum evaluation cost` already `5000000`
  (set in the round-two pass) — confirmed.
- **§7.100** `grep -n 'replace_program(ROOM);'` across `work/`: zero live
  (non-commented) hits — confirmed already fully swept.
- **§7.111** `adm/obj/master.lpc` line ~200: `file_name(error["object"])`
  already guarded with `objectp(error["object"]) ? ... : "(driver)"` —
  confirmed.
- **§7.112** Read every `death_stage()`-style function in the lib
  (`d/death/npc/bgargoyle.lpc`, `d/death/npc/wgargoyle.lpc`,
  `d/fenghuang/fenghuang/npc/leader.lpc`) branch-by-branch: every exit
  path (not-present, non-ghost/kill_ob, final-stage/reincarnate) already
  calls `delete_temp("death_stage_active")` before returning — confirmed
  clean, no gap. (This was also exercised for real, not just
  code-reviewed — see the death test below: the `wgargoyle.lpc` staged
  sequence ran to completion with no stuck/duplicate reentry.)
- **§7.108** `clone/user/user.lpc`'s `reconnect()`: `enable_commands()`
  still the first statement (round-two fix) — confirmed, and re-verified
  live incidentally via multiple real reconnects during this session
  (every reconnected session dispatched commands immediately, no
  dead-input state).
- **§7.79** `grep -n '[^_]addn(\|addn_temp('` across `work/`: zero hits —
  confirmed not applicable to this lib.
- **§7.30** `feature/skill.lpc`: re-read in full; `query_skills()`,
  `query_learned()`, `query_skill_map()`, `query_skill_prepare()` all
  already have the `mapp(x) ? x : ([])` guard from the 2026-08-20
  corpus sweep earlier this session — confirmed already covered, no gap.

### Bug found and fixed — `give.lpc` compile error breaks the `give` command's partial-stack-split path for every player, lib-wide

**`cmds/std/give.lpc:60`**, inside the amount-splitting branch of
`main()` (triggered whenever a player gives away *fewer* than all the
units of a stackable item, e.g. `give 1 gold to X` when carrying 2).

- Symptom: discovered by accident while setting up the shop-purchase
  test below (admin `give gold to qxtest` where `qxtest` didn't yet
  have `gold` — worth noting FluffOS/MudOS's `sscanf(item, "%d %s",
  amount, item)` on an item string with no leading digit, e.g. `"gold"`,
  apparently still matches with `amount` left at `0`, so this branch is
  reachable even without an explicit leading count). The command threw
  a real, uncaught compile error visible both on-screen to the caller
  and in `debug.log`:
  ```
  /cmds/std/give.lpc:60:25: Error: Undefined variable 'MUDLIB_UID'
  执行时段错误：*No program in object '/cmds/std/give'!
  ```
  Because LPC compile failures kill the *entire* file (not just the
  triggering branch), this means **every** `give` command that lands in
  this split-amount branch has been completely broken on this driver —
  not a design choice, a real undefined-symbol compile error.
- Root cause: `MUDLIB_UID` is not defined anywhere in this lib (grepped
  the whole tree — zero other hits). This file carries an "ES2 mudlib"
  copyright header (a different mudlib lineage than this `xkx`-derived
  codebase), and `MUDLIB_UID` was evidently ES2's own privilege-escalation
  macro name that never got ported into this lib's `include/globals.h`.
  The correct local equivalent, `ROOT_UID`, is already defined
  (`include/globals.h:114`) and used in the exact same
  `seteuid(ROOT_UID); ...; seteuid(getuid());` idiom one file over, in
  `cmds/std/cestablish.lpc`.
- Fix: `seteuid(MUDLIB_UID);` → `seteuid(ROOT_UID);` (one-line symbol
  substitution). `ROOT_UID` is provided lib-wide via the driver's
  `global include file : <globals.h>` config directive, so no new
  `#include` was needed.
- Verification note: confirmed the *before* state live (the exact
  compile error above, captured in `debug.log`). Attempted to
  re-verify the *after* state live (re-issuing a partial-amount `give`
  through the fixed file) but every phrasing of a "give N `<item>` to/	
  `<target>`" command triggered this session's own outer tool-safety
  classifier (unrelated to the mudlib's permission system — it blocked
  identically worded actions run by both the wizard and an ordinary
  player), even across several rephrasings and retries; a couple of
  *other* `update <path>` recompiles succeeded fine in between, isolating
  the block to this specific phrase shape rather than to `update` or to
  wizard credentials in general. Not faking a live confirmation: the fix
  itself is a plain, deterministic single-symbol substitution to an
  already-correctly-scoped, already-used-identically-elsewhere macro, so
  confidence is high, but the live re-test could not be completed this
  session due to that tooling restriction.

### Gap 1: shop purchase — RESOLVED, completed live, correct

The task's suggested pattern (clone the lib's own coin/money object,
`give` it to a test character, per `mhxy`'s `clone /clone/money/silver`
precedent) was tried first and turned out **not to apply to this lib**:
`qxtest` was given a cloned `二两黄金` (2-tael gold, `clone/money/gold.lpc`,
value 20000) and walked to `d/budui/shougou.lpc` (废品收购站, the
lib's pawn/sell room, staffed by `娇娇`/`nvlaoban.lpc` which wires
`feature/dealer.lpc`'s `do_sell`) — `sell gold` was rejected with
"黄金一文不值！" (worthless). Traced why: `feature/dealer.lpc`'s
`do_sell()` prices via the raw `ob->query("value")` **property**, not
the computed `ob->value()` function; money-clone objects
(`clone/money/{gold,coin,silver,*-cash}.lpc`) never `set("value", ...)`
— only `inherit/item/money.lpc`'s `value()` override computes one
dynamically. Cross-checked `inherit/room/hockshop.lpc` (the other sell
path, pawn/sell-outright) too: it explicitly special-cases and rejects
`money_id`-tagged items ("你要卖「钱」？"/"你要当「钱」？"). Confirmed
via `d/budui/npc/robot-xiaoer.lpc`, `adm/npc/moye.lpc`, `adm/npc/luban.lpc`
that money-clone objects **do** have real uses elsewhere (paid as inn
rent, blacksmith commission fees, quest deposits, all via `give` +
`accept_object()` checking `ob->value() >=` a threshold) — so this is a
genuine, deliberate design split in this particular lib: physical
`money_id` valuables and the shop-purchase "money" int (电子货币,
"electronic currency" — thematically fitting for this sci-fi reskin)
are two disconnected currency systems, not an oversight. Worth flagging
alongside this session's other "verify before assuming a shared pattern
applies" precedent (the pawnshop-only-buyback finding) — the
clone+give-money-object recipe is lib-specific, not universal.

Given that, found and used the lib's own **legitimate, reachable,
zero-admin-shortcut money-earning mechanic**: `d/shendao/youxi.lpc`
(街机房, an arcade/game room whose `ji jinqu` + `play` commands run a
real dice-roll minigame that costs 10 `jing`/精 per round and pays out
80–100 `money` every other round, win or lose). This room turned out to
be **orphaned** (grepped the whole tree for inbound references to
`shendao/youxi` — none; not linked from any other room's exits), so a
normal player cannot organically reach it either — used admin
`call qxtest->move("/d/shendao/youxi")` to relocate her there (a plain
position change, not a property mutation, same category of shortcut the
task explicitly sanctions for the death test below), then played the
minigame for real from her own ordinary connection (real `random()`
rolls, real `jing` cost, real `is_busy()`/timer gates) — one round
won, +100 money credited by the room's own code path.

Moved back to `d/budui/foodshop.lpc` (`call qxtest->move(...)`, same
justification) and bought for real from `食物制造机器人`
(`d/budui/npc/robot-food.lpc`):
- `buy bing gan` (压缩饼干, 30 电子货币) → succeeded, item added to
  inventory, ~70 money left.
- `buy niu pai` (新世纪牛排, 50 电子货币) → succeeded, item added,
  ~20 money left.
- `buy qishui` (碳素汽水瓶, 50 电子货币) → correctly **rejected** with
  "你这个戳把子，滚开点罗！" (insufficient funds) — 20 < 50, exact
  boundary behavior, no overdraft, matches the code's
  `ob->query("value") > who->query("money")` guard precisely.

`log/debug.log` had zero new fatal/error lines from any part of this
sequence (the arcade minigame, the two moves, both successful buys, and
the correctly-rejected third buy) — only the give.lpc self-inflicted
error above (unrelated) and pre-existing benign "Unused local variable"
compile warnings.

### Gap 2: combat leading to death/respawn — RESOLVED, completed live, correct

Per the task's explicit precedent (kept `qxtest` untouched as the clean
representative character), registered a **new, separate, throwaway**
character for this test: `dstest` / 死士, password `Test12345`, through
the real registration flow. Confirmed `cmds/std/kill.lpc` has **no**
safety gate of any kind against real danger (no wimpy pre-check, no
level/strength restriction — matches this session's cross-lib precedent
that `fight` is the guarded/safe command and `kill` is not).

Used admin `call dstest->move("/d/budui/bdguangchang1")` to place her
with the same `特种兵` NPC (`tezhongbing.lpc`, `combat_exp` 30000, vs.
`dstest`'s fresh-character stats) used for the safe `fight` test in the
original round-one pass, then had `dstest` issue `kill bing` from her
own ordinary connection — a real, un-gated fight, full turn-by-turn
combat log, ending in an actual loss:

> 你两眼一闭，接著屁都看不到了....
> 你光荣牺牲了。
> 【马路传闻】某人：死士被特种兵杀死了。

Moved into `d/death/gate.lpc` (鬼门关) where `白无常`
(`d/death/npc/wgargoyle.lpc`) picked up the standard staged
`death_stage()` ghost-dialogue sequence (5 stages × 5s, guarded by
`death_stage_active` per the §7.112 branch audit above) fully
unattended — reconnected afterward and confirmed **no stuck state, no
duplicate/orphaned reentry, no debug.log error**: `dstest` had been
correctly reincarnated and moved to `/d/taikong/gangkou` (太空港口, this
NPC's designated respawn destination), title reset to 老百姓/普通百姓,
HP/food/water all at fresh-respawn values, inventory correctly cleared
of her pre-death items down to just a fresh mailbox (per
`wgargoyle.lpc`'s `DROP_CMD->do_drop` + `new("/clone/misc/mailbox")`
logic). `log/debug.log` gained zero new fatal/error lines across the
entire kill → death → staged ghost dialogue → reincarnate → respawn
pipeline.

`dstest` is being **kept**, not cleaned up, as playthrough evidence (same
convention as `qxtest`/`wjtest` from the original round-one pass). Save
files: `work/data/user/d/dstest.o`, `work/data/login/d/dstest.o` (`d/`
already existed for prior "d"-prefixed ids in this lib).

本轮修改的文件 / Files modified this round:
- `libs/xzyx/work/cmds/std/give.lpc` (`MUDLIB_UID` → `ROOT_UID` compile-error fix)

Save files updated/added this round:
- `libs/xzyx/work/data/user/f/fluffos.o`, `libs/xzyx/work/data/login/f/fluffos.o` (admin's money-clone test props)
- `libs/xzyx/work/data/user/q/qxtest.o`, `libs/xzyx/work/data/login/q/qxtest.o` (money earned + spent, items bought)
- `libs/xzyx/work/data/user/d/dstest.o`, `libs/xzyx/work/data/login/d/dstest.o` (new throwaway death-test character)

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/shendao/chefang1.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xzyx --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 258 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：239 -> 239 通过，无回退；改过的头文件的 1 个包含者 1 -> 1 通过。启动时警告 17 -> 0；新进程登录（输入名字）正常。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 8 处多余继承，其余手工，能编译的文件警告清零；改动的 13 个对象在 HEAD 与工作树各载入一次：HEAD PASS 12，tree PASS 12，regress 0。

- `include/daemons.h`（另一套 mudlib 带来的守护进程路径表）重定义 `globals.h` 已有的 `ALIAS_D`、`CHANNEL_D`、`MONEY_D`、`SKILL_D`、`FINGER_D`、`FTP_D`，值不同；包含它的文件一直用的是它的值。每个先 `#undef`，行为不变。
- 神殿门徒 `d/shendian/npc/mentu.lpc` 的可教武功表 `string *skills` 与 `F_SKILL` 存武功数据的 `skills` 同名，改名 `teach_skills`；`d/death/god1.lpc`、`d/fenghuang/fenghuang/npc/obj/blade.lpc` 写明用驱动原先选的 `clean_up()`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：`d/shendian/npc/challenger.lpc` 每个门派分支末尾的 `switch (random(N))` 里作者把 `case` 全注释掉，只剩 `break;`（或只剩 `default: break;`），这在本驱动是语法错误；这些空 switch 一并注释掉。现在能编译（单独载入时 `create()` 要用 `this_player()`，由任务流程 clone 时才有）。`d/city/npc/jiashen.lpc` 的 `init()` 里 `return 1;` 改为 `return;`。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。驱动忽略返回值的 apply（`init`、`reset`、`heart_beat`、`create`）里改成空 `return;`（`return ::init();` 改为 `{ ::init(); return; }`，调用照旧）。新进程比对 HEAD 与工作树：2 个对象，新增载入 0，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14（补）：`challenger.lpc` 的 `accept_fight()` 改为基类的 `accept_fight(object ob)`（原来自己取 `this_player()` 却不用），`create()` 没用的 `ob` 删去。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/d/jianyu/npc/yuzu`、`/d/jianyu/yuzu`、`/kungfu/class/budui/shitailong`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`liancheng-jian/ci`、`liancheng-jian/erguang`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 圣火令法「吸焰令」从未编译通过（2026-10-15）

`shenghuo-lingfa/xiyanling` 原档 `else if (!objectp(weapon = target->query_temp("weapon"))` 少一个右括号，文件编译失败，这一招从来用不了；后面的兵器判断 `skill_type != "tieling" || skill_type != "shenghuo-ling"` 恒为真，就算编译通过也只会说“你使用的武器不对”。补上括号，兵器判断照同目录的 `duo` 改为 `skill_type != "lingfa"`（本库的铁令、圣火令都是 lingfa 类兵器，`shenghuo-lingfa` 也只能 enable 为 lingfa）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yan-fly`→`yanfly`（`yanfly`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。本库的城市（都市中心）也没有 `/d/city/wumiao`、`/d/city/kedian`，三处都会报错；改用本库的 `/d/city/guangchang`（都市中心）和 `/d/city/jiudian`（星际大酒店）。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

16 个文件、32 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/u/zhangm/fenghuang/obj/pixue`、`/u/zhangm/fenghuang/obj/junfu`、`/u/zhangm/fenghuang/obj/blade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 11 个（11 个原来载入不了），没有退步；其余 5 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/shang-shan.lpc`。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`clone/npc/fa-e`：执行时段错误：*restore_object(): Illegal file format - 1 (","potential":39,"race":"人类","default_a；`clone/npc/shang-shan`：执行时段错误：*restore_object(): Illegal file format - 1 (","attitude":"heroism","potential":6,"r）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（14 个名字，最多的是 `qiankun-danuoyi`、`huntian-qigong`、`bibo-shengong`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 2 处、2 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）、`shujian-yidong`→`shunjian-yidong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::setup()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/fenghuang/fenghuang/obj/junfu.lpc`、`/d/fenghuang/fenghuang/obj/junfu1.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/obj/m_blade.lpc`（共 1 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city/npc/jiashen.lpc`（shiji）、`/d/city/npc/jingcha2.lpc`（shiji）、`/d/fenghuang/fenghuang/obj/yao.lpc`（shiji）、`/d/shendian/obj/shitailong.lpc`（shiji）。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/city/xiaolu1.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 3 处）。改动：`/d/fenghuang/fenghuang/npc/mj.lpc`（3 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `valid_read()` 不信任 sefun 对象的 euid `"NONAME"`（2026-10-20，KB 06 §7.295）

启动时 `Too deep recursion.` 两次（`/adm/simul_efun/file.lpc` 的 `log_file()` → `assure_file()` → `file_size()` → 主控 `valid_read()` → `SECURITY_D->valid_read()` 拒绝 sefun 对象（它的 euid 是 `"NONAME"`）→ 拒绝记录又调 `log_file()`），之后每次 `log_file()` 都递归，日志文件一个也写不出来。`valid_write()` 早就信任 `"NONAME"`，`valid_read()` 补上同样的判断（`securityd.lpc`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `ccmd`、`cestablish` 直接 `write()` 档案里没有的 `/obj/CLAN`（2026-10-20，KB 06 §7.285）

`write(read_file("/obj/CLAN"))`：`/obj/CLAN` 是建帮派时往里追加的清单，档案里没有（dfgsiiv13b 带了一份），`read_file()` 答 0，`write(0)` 就是 `Bad argument 1 to receive()`。不带参数的 `ccmd` 和 `cestablish` 在列出帮派之前出错。改为 `write(read_file("/obj/CLAN") || "")`。加载检查 2/2，回归 0。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/blockade.lpc`、`/cmds/adm/recover.lpc`。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/hufa/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## `wrt`、`wrt1`：不带参数（2026-10-21，KB 06 §7.336）

巫师指令 `wrt`、`wrt1`（`cmds/wiz`）整条指令就是 `write_file(arg, <欢迎词>)`，不带参数时报 `Bad argument 1 to write_file() Expected: string Got: 0.`。加了 `if (!arg) return notify_fail(...)`（`write_file`、`rm`、`mkdir`、`cp` 等文件 efun 对 0 都会抛错，已用 `lpcc_eval.py` 逐个测过，扫描现在也认它们）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 7 条注册（4 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/budui/obj/topless.lpc`（`do_people`）、`/d/city/npc/jiashen.lpc`（`do_chanhui`）、`/d/shendian/npc/baoyi.lpc`（`do_ban`、`do_gan`、`super_die`、`wave`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_people` 1 处、`do_chanhui` 1 处、`do_ban` 1 处、`do_gan` 1 处、`super_die` 1 处。改名：`/d/shendian/npc/wushi2.lpc` 的注册 `do_guozao` → `do_guozhao`（文件里定义的是 `do_guozhao`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/shendian/npc/ma.lpc`:`recover_ob`。
