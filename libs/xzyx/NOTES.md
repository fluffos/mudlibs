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
