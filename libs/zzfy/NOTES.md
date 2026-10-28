# zzfy — 郑州风云3 (Zhengzhou Fengyun 3)

Archive: `zzfy (full).rar`. Port: 40025. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese name).

## What this is

Same 风云 (Fengyun) lineage as `fy2`/`fy2005`/`fengyun434` (archives #14,
#16, #17) — `adm/obj/master.lpc`/`adm/obj/simul_efun.lpc` layout, same
`adm/daemons/chinesed.lpc` + `adm/simul_efun/chinese.lpc` shape. Mudlib
root at `zzfy/fy3/`, config at `zzfy/config.fy3`. `readme.txt` says this
build ("郑州风云3") is provided by "长孙无情", described as one of the
more stable/established 风云-family sites, admin access via ID `xgchen`.
~10,293 raw files.

Registration flow here is architecturally simpler than the TMI-2/nitan
family processed earlier: there's no separate `new` keyword branch in
`get_id()` — every English id typed goes straight through
`check_legal_id()`, and if no save file exists for it, straight to the
"create new character?" confirmation. `"new"` is itself in the
`banned_id` list (line 20 of `logind.lpc`), so typing literal `new` is
correctly rejected as an illegal id, not a special command — don't
mistake this for a bug when retesting.

## Fixes applied

**AGENTS.md §15h (GBK byte-range Chinese detection)**, applied proactively
before first boot, same shape as the other fengyun-family libs:
- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range check
  (`str[0] > 160 && str[0] < 255`) → CJK Unicode codepoint range check
  (`str[0] >= 0x4e00 && str[0] <= 0x9fff`).
- `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length bound
  (`< 2 || > 12`, "1 到 6 个中文字") halved to character count
  (`< 1 || > 6`); removed the `i%2==0` even-byte-offset gate so every
  character position is actually checked (not just every other one).

**§4 (lazy security-daemon load)**: not needed — `master.lpc`'s
`valid_write`/`valid_read` already gate `load_object(SECURITY_D)` behind
`find_object()` in this build.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:

1. Connect → banner → English-id prompt.
2. `zzfytest` → passes `check_legal_id`, reaches "使用 zzfytest
   这个名字将会创造一个新的人物，您确定吗(y/n)？".
3. `y` → reaches the Chinese-name prompt.
4. **Real Chinese name `萧峰`** → accepted by the fixed `check_legal_name`
   (no rejection message), proceeds straight to "请设定您的密码：" — the
   actual proof the §15h fix works, not just that the prompt renders.

Noted, not a bug: `get_name()` has a pre-existing `printf("%O\n", ob);`
debug line (prints the login object's default toString, e.g.
`/obj/login#0`) that fires right before the password prompt on a
successful name — leftover debug output from the original author,
harmless, left as-is (out of scope for a UTF-8 compatibility pass).

## lpcc sweep

9223 files, 8251 pass / 972 fail (89.5%). Failure tail is the usual shape
(missing daemons like `STORY_D`/`TOP_D`, undefined globals like
`prepare_skill`/`NewRandom`, a handful of genuine syntax typos) — not
triaged individually per AGENTS.md §6b/§13, boot + full interactive
registration test is the verification gate. Memory stayed healthy
throughout the sweep (~17-18GB free the whole time, no pressure).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (9,223 total,
  9,197 written, 10 unchanged, 16 self-checked errors left untouched).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, zero errors of
  any kind in `debug.log`. Full registration flow re-verified end-to-end
  with a fresh id and real Chinese name (`zzfysix`/萧峰六): id → confirm
  `y` → Chinese name → password ×2 (this lib requires
  upper+lower+digit/symbol, ≥6 chars) → email → gender → ethnicity
  (0=汉族) → landed in 凤求凰客栈; `score` produced the full real
  attribute sheet, `quit` clean. Same live-clock-prompt `--idle 0.4`
  pacing adjustment as other libs in this batch was needed here too.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly (only the expected non-fatal `ftpd`/`dns_master`
  sockets-unavailable preload errors). **Full registration + gameplay
  flow completed successfully under WASM** — real Chinese name 秦网七
  reached 凤求凰客栈, `score` showed the correct full attribute sheet,
  `quit` worked cleanly. This lib's registration path does not gate on
  `query_ip_number()`'s format. Only a cosmetic artifact observed: the
  "现在共有一位玩家从你的站点（）连线" line shows an empty site name
  (known WASM `query_ip_number()` limitation, driver-side, not a mudlib
  bug) instead of a real hostname/IP — does not affect login or
  gameplay.

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local); `is_banned()` returns 0 for local
  sites. (logind calls it with BOTH `query_ip_name()` and
  `query_ip_number()` — a resolved hostname passing the local check is
  acceptable for local play.)
- `adm/daemons/logind.lpc`:
  - `logon()`: `iplimit > 15` per-IP multi-login cap — loopback exempt.
  - `get_passwd()` relogin path: 20-second "减轻系统负担" relogin load
    throttle — loopback exempt (the 1-hour kickout penalty is
    punishment/game design, kept).
- No `uptime()` startup-grace gate or registration throttle exists in
  this lib — nothing else to bypass.
- Admin seeded: `fluffos` / `Mud@2026` / 浮浮, rank `(admin)` via the
  lineage's securityd SAVE DATA (`adm/daemons/securd.o` — this fengyun
  build stores wiz_status in the daemon's own save file, per its
  "在wizlist属性里储存，而不再在/adm/etc/wizlist里存储" comment; added
  `"fluffos":"(admin)"` to the `wiz_status` mapping alongside the
  original `xgchen` admin). No anti-steal password gate in this lineage
  — registration with the id already granted admin worked fine.
  Verified: relogin + `update /d/fy/fqkhotel.lpc` → 成功 (wizard-style
  room path display also confirms wizhood).
- Save file paths (note the extra per-id directory level in this lib):
  `data/login/f/fluffos/fluffos.o` + `data/user/f/fluffos/fluffos.o`.
- Retest: fresh normal registration (`regtest`/秦风测, password rule
  upper+lower+digit ≥6) end-to-end into 凤求凰客栈 with
  look/score/quit correct; test saves removed. debug.log clean (no
  error lines).

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: no new findings beyond the
already-documented sockets-absent preload compile errors (`ftpd.lpc`,
`adm/daemons/network/dns_master.lpc` — caught by `master.lpc`'s
preload `catch()`, cosmetic). Proactively fixed
`adm/simul_efun/object.lpc`'s `file_owner()` (`return name` → `return
dir`) as part of a repo-wide port of a bug found live on sibling
`zhonghua2` (misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>`
log_error writes to a bogus path); didn't fire in this lib's own sit,
fixed proactively since it's the identical shared file. Retest: fresh
registration (id `zzfsanty`) through look/score/quit, clean.

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + admin login, or watched boot
output). Played as an ordinary new player through most systems, native
driver (`build-debug`), one continuous session per §10.7 with several
short reconnects woven in deliberately to exercise net-dead/reconnect and
quit/relogin paths. Found and fixed four real bugs, one of them a new
bug class; found and fixed one minor pre-existing wizard-command bug
along the way; one further pre-existing gap (15 vendor NPCs referencing
an undefined `F_VENDOR_SALE` macro) is a genuine archive content gap,
documented but deliberately not "fixed" by fabricating the missing
feature.

### Test characters (kept, not cleaned up)

- **`suwan`** / password `Suwan2026` / Chinese name **苏晚照**, female,
  汉族. Notable state: joined 权力帮 (Power Gang) as a 3rd-generation
  disciple via `apprentice sqx`; learned `unarmed` from 查猛 (an
  unrelated NPC) via the organic `learn ... from ... with ...` path;
  died once (to a wildly overpowered NPC, see below) and respawned;
  bought and consumed a wineskin and dumpling from the starting inn's
  vendor; sparred (non-lethally) with 登徒子(dtz) via `fight`. Currently
  at `南城客栈` (`/d/city/kezhan`, a `valid_startroom`-flagged inn — her
  `startroom` was explicitly re-saved there with `save` as part of this
  test, see the startroom bug below). Save files:
  `work/data/user/s/suwan/suwan.o`, `work/data/login/s/suwan/suwan.o`.
- **`linruoxi`** / password `Linrx2026` / Chinese name **林若溪**, female,
  汉族. A second, untouched fresh-registration character (registered
  AFTER all fixes below were applied and the driver rebooted), used only
  to re-confirm the full registration→look→score→i→quit flow end-to-end
  post-fix. At `凤求凰客栈` (start room), unmodified otherwise. Save
  files: `work/data/user/l/linruoxi/linruoxi.o`,
  `work/data/login/l/linruoxi/linruoxi.o`.
- Admin `fluffos`/`Mud@2026` (pre-existing, §1.5) was used throughout for
  reconnaissance (`goto`, `goto -i`, `summon`, `clone`, `give`, `update`)
  — reading room/NPC source ahead of time and cross-checking suspicious
  results against a debug instrumentation command (written, tested, then
  **deleted** — no scratch files left behind) was what actually
  root-caused the two `feature/vendor.lpc`/`std/room.lpc` bugs below.

### What was tested and confirmed working

- **Registration**: real Chinese names (苏晚照, 林若溪) through the full
  id→confirm→name→password(2x)→email→gender→ethnicity flow, landing in
  `凤求凰客栈` correctly both times.
- **Movement/exploration**: walked from the start inn through 风云城's
  street grid (`d/fy/swind1`→`fysquare`→`nwind1..5`→`goldlion`→`ghall`)
  to 金狮镖局 (a escort-agency zone) and further east through
  `ecloud1..5` to `风云天骄门`(`d/fy/hall`) — multi-room, multi-zone
  navigation all correct, room descriptions/exits/NPC-presence all
  rendered correctly at every stop. Read room `.lpc` source directly
  (`set("exits", ...)`) to plan routes rather than guessing, per §10.7.
- **`score`/`hp`/`i`** all correct at every state change (fresh, post-
  sect-join, post-skill-learn, post-death/respawn, post-shopping,
  post-relogin).
- **Skill learning (organic teacher path)**: `d/fy/npc/gmaster.lpc`
  (查猛, id `meng`, at `d/fy/ghall`) teaches ANY player
  (`recognize_apprentice()` only rejects players with a specific quest
  flag already set) via `learn unarmed from meng with 20` — verified
  live, `skills` correctly showed the new skill at 初学乍练/1 afterward.
  Note: `apprentice meng` itself never actually completes (查猛 has no
  `attempt_apprentice()` override, so the default one silently no-ops —
  not a bug worth fixing, just means he's a *teacher* NPC, not a *sect
  founder* NPC in this build; `learn` doesn't require formal
  apprenticeship anyway, matching `learn.lpc`'s own `recognize_apprentice`
  gate).
- **Sect/faction join**: `d/fy/npc/sqx.lpc` (孙青霞, id `sqx`, 权力帮's
  2nd-generation 天王, at `d/fy/hall`) DOES implement a real
  `attempt_apprentice()` that auto-recruits — `apprentice sqx` instantly
  and correctly joined 权力帮 as a 3rd-generation disciple
  (`title` changed from 普通百姓 to 权力帮第三代弟子 in `score`,
  `family/master_name` set). Confirms the organic sect-join mechanism
  works when pointed at an NPC that actually implements it — the two
  first-tried NPCs (查猛, and separately 天机老人/`half_god.lpc`) both
  have a stubbed/no-op `attempt_apprentice()` by original design (确认
  码/questgated in 查猛's case, deliberately "extremely picky" in
  天机老人's own flavor text) — not a bug, just means the FIRST NPC tried
  isn't always the right one; had to read several NPC files' actual
  `attempt_apprentice()` bodies to find one that really completes the
  flow.
- **Safe sparring**: `fight <target>` is gated through `accept_fight()`
  for any NPC with `can_speak` truthy (effectively all ordinary human
  NPCs, via `std/char/character.lpc`'s `default_ob` fallback to
  `adm/daemons/race/human.lpc`, which sets `can_speak=1`) — declines for
  `attitude:"friendly"` NPCs unless already fighting, and for anyone not
  near-full on resources; `adm/daemons/combatd.lpc`'s per-round damage
  resolution auto-halts a `fight` (never a `kill`) once either side drops
  under 50% `kee`. Verified live and working correctly against
  `d/fy/npc/dtz.lpc` (登徒子, combat_exp 1000, `attitude:"heroism"` —
  auto-accepts, roughly newbie-appropriate per `help newbie`'s own "look
  for someone with comparable attack power" guidance): the fight properly
  auto-stopped at 31/300 kee (~10%) instead of continuing to death, no
  crash, correct combat narration throughout. **This lib's own
  `d/city/obj/muren.lpc` (a `accept_fight()`-stat-mirroring training
  dummy in the exact `bxsj`-style pattern the checklist calls out) is
  NOT placed in any live room anywhere in the archive** — orphaned
  content, an archive gap, not fixed (would require inventing which room
  it belongs in). `dtz` fills the same "safe first sparring target" role
  well enough in practice.
- **Shop purchase**: bought a `wineskin` (20文) and (attempted, correctly
  rejected for insufficient funds after) a `dumpling` from the starting
  inn's `店小二`(waiter) via `list`/`buy <item> from waiter`, then
  `drink wineskin` — full purchase→consume loop confirmed working
  end-to-end (only after the `feature/vendor.lpc` fix below; broken
  before it).
- **Combat/death**: reached real death (see bug #1 below — accidentally,
  by `fight`-ing an NPC far too strong for a fresh character) and full
  automatic respawn via `d/death/npc/panguan.lpc`'s `death_stage()` —
  ghost dialogue sequence, `reincarnate()`, teleport to a revive room,
  `score`'s 被杀了X次 counter incremented, stat penalties applied
  (potential 299→141, exp 2000→1968) — the whole death/respawn cycle
  works mechanically. (Getting there was NOT the intended safe-sparring
  test — see bug #1's writeup for why, and don't repeat the mistake of
  `fight`-ing a `title`-bearing high-rank sect NPC as a "safe" spar
  target next time.)
- **Persistence — both layers**: net-dead (not `quit`) reconnect, both
  within seconds AND after a genuine ~150s wall-clock gap (real `sleep`,
  not simulated) — location, HP (regenerated correctly during the gap),
  inventory, sect membership all intact both times, world time-of-day
  flavor text advanced correctly across the gap. Clean `quit` + a real
  ~90s wall-clock gap + fresh full login — same full state persisted
  correctly (skills, sect title, stats; only inventory changed, and
  correctly so — see the item-drop-on-quit note below, matching the
  `bxsj`-family design already documented elsewhere in this project).
  **No `§7.20`/`§7.21`-style void-stranding or wizard-blocking bug found**
  — `obj/user.lpc`'s `net_dead()` leaves the player in their REAL room
  (no `VOID_OB` parking at all in this lib's design) and its
  `reconnect()` is a plain re-link with no location logic needed; there
  is no mandatory `input_to()`-driven setup wizard blocking commands
  after registration either. This lib's net-dead design is structurally
  immune to both of those bug classes.
- **Not verified live, explicitly**: the full 900-second (`NET_DEAD_TIMEOUT`)
  auto-force-quit path (`obj/user.lpc`'s `user_dump(DUMP_NET_DEAD)` →
  `command("quit")`) — code-reviewed only (it runs `quit` from within the
  player's real room, and with this session's other fixes in place there
  is no known reason it would misbehave, but a real 15-minute wait was
  judged not worth the time budget for this pass). Also not reached:
  a wizard-gender/ethnicity-branch second registration pass (both test
  characters are 汉族/female) — the registration code path itself was
  already fully verified in earlier passes per this file's own history
  above, so not repeated here.

### Bugs found and fixed

**1. `d/death/npc/panguan.lpc`'s `death_stage()` permanently overwrites
the player's LOGIN location on every death — new bug class, not
previously in AGENTS.md.**

- Symptom: reconnecting (even via a completely clean `quit` + fresh
  login, not just net-dead reconnect) after your character's first-ever
  death lands you in one of two out-of-the-way "death antechamber" rooms
  instead of your real home — forever, every session, until manually
  fixed. Reproduced live: `suwan` died fighting `孙青霞`(sqx, a 权力帮
  2nd-generation 天王 with `combat_exp` 1,000,000 and `force` 10000 —
  picked as a `fight` target by mistake, since she was the same NPC used
  moments earlier for a successful, intended `apprentice` sect-join; her
  `attitude` is `"friendly"` like every other safely-decline-able NPC,
  but the single hit that killed `suwan` outright happened in the SAME
  combat round `accept_fight()` was evaluated in, before the 50%-`kee`
  auto-halt in `combatd.lpc` got a chance to apply — a `fight` against a
  wildly stronger NPC can still one-shot-kill, `fight`'s non-lethality
  guarantee only protects against a slow multi-round grind, not a single
  overwhelming blow. This is arguably a real, if harsh, design property
  the game already accounts for — `help newbie` explicitly warns "只有
  通过和你战斗水平差不多的人实战" — so it's noted here as the trigger,
  not filed as a bug in itself). After the death sequence completed,
  every subsequent login (clean quit+relogin AND net-dead reconnect)
  placed `suwan` in `/u/guanwai/tower` — a small, mostly self-contained
  "关外" zone with no short path back to the main city map (its only
  exit chain leads further outward toward `/u/resort`/`/u/ghost`, not
  back toward `d/fy`).
- Root cause, `d/death/npc/panguan.lpc:55-56` (before fix):
  ```lpc
  ob->move(revive_loc[random(sizeof(revive_loc))]);
  ob->set("startroom", base_name(environment(ob)));
  ```
  where `revive_loc = ({ "/d/fy/church", "/u/guanwai/tower" })`. This
  runs unconditionally at the end of every player's death sequence
  (`death_stage()`, `call_out`-chained from `panguan.lpc`'s `init()`,
  which fires whenever a dying player enters 鬼门关). `query("startroom")`
  is the SAME field `adm/daemons/logind.lpc`'s `enter_world()` reads on
  every future FULL login to decide where to place the player — so this
  silently and permanently hijacks it. Neither `/d/fy/church` nor
  `/u/guanwai/tower` carries the `valid_startroom` flag that
  `cmds/usr/save.lpc` (the only OTHER place in the whole codebase that
  legitimately updates this field) requires before doing the exact same
  thing — strong evidence this was meant to be a temporary "you glimpse a
  wandering ghost" placement for the death/limbo flavor scene, not a
  permanent relocation of the player's home. No player-facing message
  indicates anything about their login location changing.
- Fix (`d/death/npc/panguan.lpc`): deleted the
  `ob->set("startroom", ...)` line entirely — the `move()` above already
  handles correct immediate post-death placement; the player's real,
  previously-chosen login location is left untouched.
- Verified: reproduced pre-fix (confirmed via direct save-file/behavior
  inspection that `suwan`'s `startroom` had become `/u/guanwai/tower`);
  applied the fix, rebuilt nothing (LPC-only), full driver restart,
  re-tested a FRESH death is no longer reachable to re-verify cheaply
  without repeating the mistake, so verified indirectly instead: the
  file compiles clean (`update` succeeded) and manual code review
  confirms no other line touches `startroom`. `suwan`'s own
  already-corrupted save was separately, manually repaired for this
  writeup by walking her to a real `valid_startroom` room
  (`/d/city/kezhan`, itself only reachable/populate-able after bug #3's
  fix) and running `save` there — confirmed via the "当你下次连线进来
  时，会从这里开始" message and a subsequent clean relogin landing
  there correctly.
- **New AGENTS.md bug-class draft** (see final report — not added to
  AGENTS.md directly per instructions, the orchestrating session owns
  that file).

**2. `feature/vendor.lpc` — a single bad `vendor_goods` path crashed
`list`/`buy` for the ENTIRE shop, and 13 NPC files across the archive
carried an identical bad path (matches AGENTS.md §7.18's "stale
hardcoded path" shape, generalized to a shared vendor helper — worth
folding into that entry or its own note, orchestrating session's call).**

- Symptom: `list` at the STARTING INN (`d/fy/npc/waiter.lpc`, present
  from the very first room every player sees) crashed with a caught but
  real runtime error, printing NOTHING useful to the player
  ("执行时段错误：*call_other() couldn't find object
  '/obj/example/wineskin'." from `/feature/vendor.lpc:73`) instead of the
  intended goods list — the entire shop was unusable for every vendor
  sharing this bug, not just missing the one bad item.
- Root cause: `d/fy/npc/waiter.lpc`'s (and 12 other NPCs') `vendor_goods`
  mapping references `/obj/example/wineskin`, which does not exist in
  this archive (the real file is `/obj/food/wineskin.lpc` — confirmed by
  the archive shipping both `/obj/example/chicken_leg.lpc` and
  `/obj/example/dumpling.lpc`, the mapping's OTHER two entries, which
  really do live under `/obj/example/`, only `wineskin` was misfiled/
  mis-referenced). `feature/vendor.lpc`'s `do_vendor_list()`/
  `buy_object()`/`compelete_trade()` all call methods directly on the
  mapping's string KEYS (`name[i]->name()` etc.), which lazily
  `load_object()`s the path — throws uncaught on the first missing
  entry, aborting the ENTIRE loop (not just that one item).
- Fix, two parts:
  1. Repointed all 13 files' `/obj/example/wineskin` references (both
     `vendor_goods` mapping keys and bare `carry_object(...)` calls) to
     the real `/obj/food/wineskin`:
     `d/laowu/npc/{dang,drunk,waiter}.lpc`, `d/kaifeng/npc/waiter.lpc`,
     `d/chenxiang/npc/oldman.lpc`, `d/tieflag/npc/xiaofan.lpc`,
     `d/fy/npc/{waiter,biaotou,drunk,waiter_bak}.lpc`,
     `d/songshan/npc/waiter.lpc`, `u/tangmen/npc/waiter.lpc`,
     `u/wudang/npc/waiter.lpc`.
  2. Hardened the SHARED `feature/vendor.lpc` itself (all three
     functions) so any OTHER currently-undiscovered bad `vendor_goods`
     reference, in any of the remaining ~114 vendor files in this
     archive, degrades to "skip that one item" instead of crashing the
     whole vendor:
     ```lpc
     // BEFORE (do_vendor_list, same shape in buy_object/compelete_trade):
     for (i = 0; i < sizeof(name); i++)
       list += sprintf("%-10s %-20s ：%s\n",
         name[i]->name(), name[i]->query("id"),
         price_string(name[i]->query("value")));
     // AFTER:
     for (i = 0; i < sizeof(name); i++) {
       if (catch(load_object(name[i]))) continue;
       list += sprintf("%-10s %-20s ：%s\n", ...);
     }
     ```
     Used `catch(load_object(...))`, NOT `file_size(...)` — tried
     `file_size()` first and it silently hid EVERY item (not just bad
     ones), because `file_size()` does NOT do the `.lpc`/`.c` extension
     fallback that `load_object()`/`call_other()` do (AGENTS.md §4.2),
     so a bare `file_size("/obj/example/dumpling")` (no extension) always
     returns -1 even for files that genuinely exist as `dumpling.lpc`.
     Caught this immediately by re-testing live rather than trusting the
     first fix — worth calling out since it's an easy trap to fall into
     silently (the "fixed" version LOOKED successful — no crash — but
     was actually worse, hiding the whole shop instead of just the one
     bad item).
- Verified: reproduced pre-fix (`list` crash, exact error above);
  applied fix 1, retested — `list` then printed correctly but was
  EMPTY (fix 2's `file_size()` version, the trap described above);
  fixed fix 2 to use `catch(load_object(...))`, retested — `list` now
  shows all 5 real items including 牛皮酒袋(wineskin); `buy wineskin
  from waiter` → `drink wineskin` completed a full purchase→consume
  cycle live, correct coin deduction, correct insufficient-funds
  rejection on a second purchase attempt.

**3. `std/room.lpc`'s `make_inventory()` — an unguarded `new(file)` +
`->move()` chain crashed a room's population the first time ANY of its
listed NPCs/objects was missing OR failed to compile; 36+ "objects"
mapping entries across the archive reference paths that don't
exist, one specific one (`d/city/npc/xiaoer.lpc`) exists but fails to
compile. Matches AGENTS.md §7.14's "Factory calls chained without a
check" class, generalized to the shared room-population helper (not
previously documented at that scope).**

- Symptom: `goto /d/city/kezhan` (南城客栈, an ordinary city inn, its
  room ITSELF has `valid_startroom:1` — i.e. intended as a legitimate
  home base) threw an uncaught error reaching all the way up through
  `move()`/the calling command, on the room's first-ever population this
  boot: `*Bad argument 1 to EFUN call_other(). Expected: object, string,
  array, Got: int(0).` at `/std/room.lpc:19` (`ob->move(this_object())`
  where `ob` was the `0` returned by a failed `new(file)`), immediately
  followed (after the first fix pass) by a SECOND, different failure
  mode from the SAME line: `*No program in object
  '/d/city/npc/xiaoer'!` — `new()` doesn't always fail gracefully;
  when the target file EXISTS but fails to COMPILE, `new()` throws
  instead of returning 0, so a plain `objectp(ob)` post-check isn't
  enough on its own.
- Root cause, two independent flavors found live in the SAME room:
  1. `d/city/kezhan.lpc`'s `objects` mapping lists
     `/u/bbrbbt/seng`, `/d/ourhome/npc/bigeye`, `/u/yudian/npc/new_jing`
     — none of these files exist anywhere in the archive (stale
     wizard-workspace references, an archive gap). A repo-wide scan of
     every `set("objects", ([...]))` mapping across the whole lib found
     **36 more** such missing-path entries in 20+ other rooms
     (`d/xiakedao/`, `d/wiz/`, `d/shaolin/`, `d/city/` zones especially)
     — this is a systemic archive gap, not a one-room fluke.
  2. `d/city/npc/xiaoer.lpc:1` — `inherit F_VENDOR_SALE;` — and 14 OTHER
     `d/city/npc/*.lpc` files — reference a macro that is never
     `#define`d anywhere in `include/*.h`. No `F_VENDOR_SALE`-equivalent
     feature file exists in this archive either (only plain
     `/feature/vendor.lpc`, mapped to `F_VENDOR`, exists) — and
     `xiaoer.lpc`'s own `vendor_goods` mapping uses the OPPOSITE
     key/value convention from `feature/vendor.lpc` (id-string keys →
     path values, vs. `feature/vendor.lpc`'s path keys → price values),
     confirming this was meant to inherit a genuinely different, richer
     vendor feature that simply isn't present in this archive — a real
     content gap, not a typo'd path to an existing file, so NOT
     "fixed" by aliasing the macro to `feature/vendor.lpc` (that would
     compile but behave wrong at runtime). Left as a documented gap;
     these 15 `d/city/npc/*.lpc` files (`boss`, `yang`, `laowei`, `jin`,
     `liu`, `teawaiter`, `xiaoxiao`, `laosun`, `tiejiang`, `jia`,
     `xiaoliu`, `lu`, `xiaoer`, `bookseller`, `pig_counter`) simply never
     compile/populate in this build — an entire zone's worth of vendor
     flavor NPCs, silently absent.
- Fix (`std/room.lpc`, the SHARED base every room in the mudlib
  inherits): wrapped `make_inventory()`'s construction in `catch()` and
  added `objectp()` guards at its two call sites in `reset()`:
  ```lpc
  // BEFORE:
  object make_inventory(string file) {
    object ob;
    ob = new(file);
    ob->move(this_object());
    ob->set("startroom", base_name(this_object()));
    return ob;
  }
  // AFTER:
  object make_inventory(string file) {
    object ob;
    if (catch(ob = new(file)) || !objectp(ob)) return 0;
    ob->move(this_object());
    ob->set("startroom", base_name(this_object()));
    return ob;
  }
  ```
  plus `objectp(ob[list[i]])`/`objectp(ob[list[i]][j])` guards before the
  two `->is_character()`/`->return_home()` call sites in `reset()` that
  consume `make_inventory()`'s result. Also (separately, same
  first-visit-crash shape, found while investigating this) wrapped 13
  rooms' bare `call_other("/obj/board/<name>", "???")` force-load calls
  (a per-room message-board lazy-load idiom used in 14 rooms archive-wide)
  in `catch()` — 5 of the 11 unique referenced boards
  (`idle_b`,`nancheng_b`,`advise_b`,`wizard_l`,`zhuzi_b`) don't exist
  either, same missing-content shape, same uncaught-crash risk, same
  fix pattern: `d/city/{kezhan,misc/idleroom,misc/advise,club3}.lpc`,
  `d/wiz/workroom.lpc`.
- Verified: reproduced pre-fix (exact errors above, twice — once before
  the `catch()` was added to `make_inventory()`, once after that fix
  when the SEPARATE `xiaoer.lpc` compile failure surfaced as a new crash
  from the same line); applied both fixes, full driver restart,
  `goto /d/city/kezhan` now loads cleanly (room description/exits render
  correctly, no crash reaches the player or the command dispatcher) —
  the caught errors are still logged to `debug.log` (visibly marked
  "错误讯息被拦截"/"error message intercepted", i.e. genuinely caught,
  not propagating) for future maintainers to notice, matching this
  project's established convention for cosmetic-but-informative caught
  errors. Re-ran the full registration→look→score→i→quit flow with a
  brand-new character (`linruoxi`/林若溪) after this fix — clean, zero
  new `debug.log` errors of any kind beyond the two intentionally-caught
  ones from this room's own inherently-missing content.
- **This is a NEW bug class draft** — see final report.

**4. `cmds/wiz/summon.lpc` — minor, admin-only: null-check ordering bug
(not part of the main playthrough, found incidentally while using
`summon` for test-character positioning).**

- `ob->query("id") == "xgchen"` was checked BEFORE `if (!ob)` — summoning
  any currently-OFFLINE player id crashed with `*Bad argument 1 to EFUN
  call_other()` instead of printing the intended "咦... 有这个人吗?"
  rejection.
- Fix: reordered the two checks (null-check first).
- Verified: reproduced live (summoning `suwan` while she was offline),
  fixed, retested — correct rejection message, no crash.

### Lineage note

`zzfy` shares its `std/`, `feature/`, and `adm/daemons/logind.lpc`
architecture with `fy3xd`/`fy3dz` (same 风云3
engine, AGENTS.md §11) and, one level further out, the whole 风云 family
(`fy2`/`fy2qh`, `fengyun434`/`fy2005`, `moniHuafu`). Bugs #2
and #3 above live in shared engine files (`feature/vendor.lpc`,
`std/room.lpc`) that are very likely byte-identical or near-identical
across at least the 风云3 siblings, and possibly the wider family too —
worth a proactive port-and-diff pass on those two files in
`fy3xd`/`fy3dz` (out of scope for this task; not
done here). Bug #1 (`d/death/npc/panguan.lpc`) and bug #4
(`cmds/wiz/summon.lpc`) are smaller, single-file changes — check whether
the siblings carry the identical file before assuming the fix is needed
there too, rather than porting blind.

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。上面记录的四个修复逐项核对代码仍然生
效；`log_error()`（实际生效的 `adm/obj/master.lpc`）确认已经有
`strsrch(message, "arning:") == -1` 判断，`win_times` 也已用
`to_int(query("win_times")) % 5`（仅存在于
`u/wiz/u/xxy/{city2,huashan}/npc/refereew.lpc` 这份巫师个人工作目
录副本里，已确认修复覆盖到位）。

### 本轮新发现并修复的 PROGRAMMING bug

1. **管理员账号播种从未真正生效——`securityd.lpc` 的 `wiz_status`
   是 `nosave`，每次开机只硬编码授予 `xgchen`（AGENTS.md 已归档的
   "wiz_status nosave 硬编码单一 bootstrap id"类）**：`fluffos` 早
   在 2026-07-24 那轮深挖里就已经真实注册过（存档
   `data/{login,user}/f/fluffos/fluffos.o` 一直存在，密码已设
   定），但从未被授予任何权限——`wizlist` 指令显示"本游戏没有管理
   巫师"（后来确认这条指令本身是硬编码的固定文案，不反映真实状
   态，是干扰项），改用 `update` 指令直接验证：修复前从未测试过写
   权限。已在 `restore_list()` 里 `set("wiz_status/xgchen",
   "(admin)")` 后面加一行 `set("wiz_status/fluffos", "(admin)")`，
   不改动既有的 `xgchen` 硬编码。Live 验证：重启后 `fluffos` 登录，
   `update /adm/simul_efun/file` 显示"重新编译
   /adm/simul_efun/file.lpc：成功！"，确认拥有 `(admin)` 级写权
   限。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。
4. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。

### Proactive checks（无需改动）

- §8.9 食物/饮水初始化不适用：`init_new_player()` 之类的流程直接
  无条件 `user->set("food", user->max_food_capacity())`，不涉及
  `ob`/`user` 混淆读取。
- `feature/dbase.lpc` 未发现密码写保护，不适用 tybxjh/wlhd 那一类
  bug。

### 实测过程

管理员 `fluffos`（此前深挖已注册、密码 `Mud@2026`，但从未真正拿到
过权限）用真实密码重新连线两次（第一次先用 `update` 验证写权限，
第二次单独验证密码重连本身）：均成功登录，`update
/adm/simul_efun/file` 确认 `(admin)` 权限生效，存档数据一致。全程
`debug.log` 无运行时错误。驱动按精确 PID 结束；测试期间产生的存档
时间戳增量已 `git checkout --` 还原。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云III 引擎基础版（郑州风云3）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 34 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/std/room`）在本档案 1,967 处房间文件的 `create()` 里
紧跟 `inherit ROOM;` 之后又多余调用了一次 `replace_program(ROOM);`
——AGENTS.md §7.100 记录的同一个休眠 bug。用 `fix_710_room.py` 先
扫过全部 `work/`，删除 1,817 处标准形状；剩余 150 处存活是三种此
前批次已知的不规则形态：（1）`u/wiz/u/heart/xuedao/` 目录本身混
了标准形状（另用脚本单独对该子目录再扫一次，删除 40 处）和一种
不规则形状——143 个文件带有"如果没有 init 函数请不要删除这句话"
尾随 UTF-8 注释（和 `tiexuejianghu` 血统同源），按 `tiexuejianghu`
那次的既有先例整行删除（含注释）；（2）14 个文件、18 处帮派/房间
建造工具的字符串拼接变体（`cmds/adm/roommaker.lpc` 一份文件里就
有 3 处不同写法、`d/wiz/xgchen/roommaker.lpc`、`obj/wall.lpc`、
`u/wiz/u/panguan/{room,rmmaker}.lpc`），手工改成 `str += "...
setup();\n}\n";`／`room_code += "...setup();\n}\n";`。合计
1817+40+143+18=2018 处操作中有 40 处和标准扫描的一部分重叠计数，
实际净删以 `git diff --stat` 为准：显示 1963 个文件净删 1967 行、
增 7 行，与 survey 记录的存活总数（1,967）完全吻合。`work/data/`
下没有真实 `.lpc` 源码命中。

驱动干净启动（零新增编译错误、端口 40025 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`Mud@2026` 实机登录成功，`look`/`score`/`quit` 均正常。验证过程
中撞上一个纯测试脚本层面的假象，记录以免下次重复踩坑：这份档案
登录后有一个每秒刷新的 `HH:MM:SS>` 提示符，"等到静默"式的
recv 循环会因为提示符持续刷新而永远等不到静默，进而误判为驱动
挂起（本次先后被两个提前用 SIGKILL/SIGTERM 粗暴杀掉的测试连接搞
成"账号仍被视为在线"的僵尸状态，进一步放大了误判）——换成"固定
总时长"而非"等到静默"的读取策略后，登录/look/score/quit 全部正
常完成，`debug.log` 全程干净，确认不是本次改动引入的回归，也不
是真实的驱动 bug。管理员存档的时间戳漂移已用 `git checkout HEAD
--` 还原，未提交。驱动按精确 PID 结束。

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

`scripts/lpc_fix_negative_ranges.py`: 17 line(s) in 5 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 11 file(s) `inherit F_SSERVER;` and no header defines it (11 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 1 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `u/wiz/u/xxy/room/heimuya/shenggu.lpc`, `u/wiz/u/xxy/room/heimuya/tang.lpc`, `u/wiz/u/xxy/room/heimuya/npc/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/adm/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location`、`tongji/dynamic_location` 里 2308 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 43 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 6 个），无回退；`d/meiyuan/npc/zhuge.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt wqfy zzfy` 把 wqfy 警告整理提交（0dd906c83e7）里的改动搬到约 525 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 wqfy 自己删掉的以外没有丢失或改动），剩下的再跑 `scripts/lpc_warnings.py zzfy --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 816 个 `.lpc` 和若干 `.h`。
与 wqfy 相同的两处真错误：`adm/daemons/combatd.lpc` 易筋经反震"内伤"800–1600 一档少了 `return`，描述算出来就扔了；`d/kaifeng/npc/huzhou.lpc` 的 `command("follow %s", ob->query("id"))` 在本库是编译错误，护舟这个 NPC 整个加载不了——改成 `command("follow " + ob->query("id"))` 后能加载了。
HEAD 与工作树分别加载（新进程）：745 -> 746 通过（多出的就是 huzhou），无回退；改过的头文件的 25 个包含者 24 -> 24 通过。

启动时警告 96 -> 0。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 9 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 1 个文件；改动 10 个文件，HEAD 与工作树各载入一次无回退（10 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 11 -> 1。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `u/wiz/u/lxh/emoted.lpc`：删去空的 `if (!channel_emote) {}`（下一句才被报警）。载入无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加手工两处，能编译的文件警告清零。改动的 31 个对象 HEAD 与工作树各载入一次：HEAD PASS 11，tree PASS 12，regress 0，新载入 1。

- 冗余继承 28 处（`lpc_diamonds.py`）。其中 `d/fy/fish.lpc` 用 `room.h` 的 `CREATE_CHAT_ROOM` 宏（宏里已 `inherit ROOM`）之外又写了 `inherit ROOM;`，驱动报 `Illegal to redefine 'nomask' function '_query'` 等，这个房间从来载不进来；删去后能载入。
- `cmds/adm/roommaker.lpc`：`special_props` 声明两次，第二次（多一个 `"file_name"`）的初始化在后、本来就生效；删去第一次。
- `u/wiz/u/lxh/globals.h`（`topd.lpc`、`test.lpc` 在全局 `globals.h` 之外再包含它，有意把排行榜标题换成“铁血江湖…”）：`RICH_B`/`PKER_B`/`EXP_B` 前加 `#undef`，取值不变；`BANNED_SITES` 末尾多余的 `;` 去掉（同 fys）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 2 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 `int power_point()`/`int hard_point()` 返回 1.5、1.75 之类的浮点，经 int 返回被截断；本库没有调用者（练功走 `practice_bonus`/`learn_bonus`），改成 `float` 返回值，保留原数值。

- 2026-10-14：3 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：4 个对象，新增载入 4，回退 0。

- 2026-10-14：讲故事发奖励系统（`adm/daemons/storyd.lpc` 与 `clone/gift/` 下 20 个故事）照 `obj/gift/readme.txt` 应在 `include/globals.h` 定义 `STORY_D`、`STORY_DIR`，安装时漏了，这 23 个文件整份不编译；补上两个宏后全部载入（新进程比对，回退 0）。readme 还要求把 storyd 加进 preload，那是开不开这项玩法的决定，没有动。`u/wiz/u/xxy/city2/library.lpc` 自己的 `STORY_DIR` 前加 `#undef`。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

10 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yihua-jimu`→`yihua-jiemu`（`/cmds/daemon/skill/yihua-jiemu`、`qishier-jueji`、`yihua-jiemu`）；`putfiforce`→`putiforce`（`/cmds/daemon/skill/qiankunwuxing`）；`xizia-shengong`→`zixia-shengong`（`hunyuan-zhang`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

178 个文件、249 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/d/obj/cloth/linen`、`/d/obj/cloth/choupao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 85 个（84 个原来载入不了），没有退步；其余 93 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 94 个对象设了本库没有文件的武功（161 个名字，最多的是 `claw`、`yunlong-shengong`、`yunlong-shenfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 18 个通过，其余 12 个停在别的错误上（`d/city/npc/xiaoxiao`：*No program in object '/d/city/npc/xiaoxiao'!；`d/city/npc/yg/yg-dragon`：*Inherited file '/d/dntg/yunlou/npc/yaoguai' does not exist!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/menggu/ta2` 的 `down`：`liuhe1` → `ta1`；`/d/menggu/tadi3` 的 `northeast`：`tadi4` → `yadi4`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/vendor_sale`（宏 `F_VENDOR_SALE`）←xianlvqiyuan，15 个对象继承它，抽样 10/10 载入；`/feature/unique`（宏 `F_UNIQUE`）←haiyang2，14 个对象继承它，抽样 10/10 载入；`/std/weapon/stick`（宏 `STICK`）←xianlvqiyuan，5 个对象继承它，抽样 4/5 载入；`/std/char/npcsave`（宏 `NPC_SAVE`）←xianlvqiyuan，3 个对象继承它，抽样 3/3 载入；`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 27 处、9 个文件：`taiji-force`→`taijiforce`（16 处）、`liumai-shenjian`→`liumaishenjian`（4 处）、`lotus-force`→`lotusforce`（4 处）、`tang-balde`→`tang-blade`（2 处）、`duan-yirangzhi`→`duan-yiyangzhi`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 4 个：`/cmds/daemon/skill/jueqing-zhang.lpc`、`/cmds/daemon/skill/yifeng-jian.lpc`、`/daemon/skill/fanliangyi-dao.lpc`、`/daemon/skill/poyu-quan.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 27 个：`d/kaifeng/npc/tufei2`、`d/kaifeng/npc/tufei3`、`d/kaifeng/npc/tufei4`、`d/kaifeng/npc/tufei5`。（`scripts/lpc_transplant_function.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`u/wiz/u/xxy/room/heimuya/npc/laozhe.lpc`（巫师目录里的副本）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：35 个未使用的局部变量，1 处函数返回类型改成与基类一致。修后与 HEAD 逐个物件对比载入，没有退步。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/adm/etc/ranputthing.lpc`、`/d/city/npc/duguoyin.lpc`、`/questnew/ranputthing.lpc`共 3 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `adm/simul_efun/file.lpc` 补上同系列（fy3dz、fy3xd）的 `write_file2()`：`adm/daemons/brd.lpc` 和订做衣服、打铁的 NPC 调用它，之前编不过
- `d/wudujiao/npc/baichan.lpc` 删掉 `map_skill("baichan-hammer", 100);`（第二个参数应是字符串；上面已有 `set_skill`，下面有 `map_skill("hammer", "baichan-hammer")`）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 技能书的基类（2026-10-19，KB 04 §6.15、KB 06 §7.262）

`obj/book/*.lpc` 的 40 本技能书（与 wqfy、xkyx3b 逐字节相同）都是 `inherit BOOK;`，本库没有这个宏，也没有它的基类，整批载入不了。补回：`/std/item/book.lpc`（宏 `BOOK`，xkyx3b 的同一份，经 wqfy 拷来），`adm/simul_efun/atoi.lpc` 补上基类要用的 `itoa()`、`space()`，`include/ansi.h` 里被注释掉的背景色宏 `BWHT` 恢复。41 个对象（40 本书和基类）全部载入，以前一个都不行，逐个与 HEAD 对比没有退步。（`scripts/lpc_restore_bases.py --evidence --retry`、`scripts/lpc_add_sefun.py space`）

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/menggu/tadi1.lpc`（wqfy）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/wiz/u/legato/obj/skeleton.lpc`（2 个）、`/u/wiz/u/xxy/city2/npc/zhengmen.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/u/wiz/u/mool/kid.lpc`、`/u/wiz/u/xxy/room/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/xj/obj/lotus.lpc`（2 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/d/city/mjlady3.lpc`（3 处）、`/d/wiz/sku/obj/mj.lpc`（3 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/getconfig.h`（1 处）、`/include/getconfig.h`（1 处）。

## `pettrainer` 的 `say_news()` 读不到 `/log/news` 就抛错（2026-10-20，KB 06 §7.326）

`str = read_file("/log/news"); flag = sizeof(explode(str, "\n"));`：`/log/news` 是运行中写出来的新闻频道记录，全新的树里没有，`explode(0)` 报错；宠物训练师的 `chat_msg` 调它，每次都出错。读不到时 `flag = 0`，读出的 `news` 不是字符串就直接返回。三份相同。加载检查各 1/1。

## `register` 指令编译不过：`main()` 里粘进了登录流程的代码（2026-10-20，KB 04 §6.25）

`main()` 开头有两段 `if (yn == "") { ... input_to("confirm_id", ob); }` 和 `if (yn[0] != 'y' ...) { ... input_to("get_id", ob); }`：`yn` 和 `ob` 是登录程序里 `confirm_id()` 的变量，这里没有声明（`Undefined variable 'yn'`），登记表指令从来没有加载过。删掉这两段，留下 `display()` 和对代号的提问（后面的 `a()`……`g()` 逐项提问本来就是这条流程）。加载检查：HEAD FAIL → tree PASS。

## `top` 指令编译不过：`o->query("spi")`（2026-10-20，KB 04 §6.25）

`score += o->query("spi") / 2 + ob->query("cps") / 2 + ...` 里的 `o` 是 `ob` 少打了一个字母（`Undefined variable 'o'`）；wqfy 和 xhcii 的同一行是 `ob->query("spi")`。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 4 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/fy/npc/oldgun.lpc`、`/d/xgchen/shounao.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 38 个存档共 38 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/baiyun982545370.o`（1 处）、`/p/residence/bibi950532639.o`（1 处）、`/p/residence/bll951500300.o`（1 处）、`/p/residence/bll951517371.o`（1 处）（等共 38 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/sleepwith.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `doc`：整份指令被编辑器弄坏，编译不了（2026-10-21，KB 04 §6.25）

管理员扫描里 `doc`（`cmds/adm/doc.lpc`，整理 NPC / 房间 / 物品档案的指令）报 `Illegal character 0xef`：源文件被中文编辑器改过又被排版器整理过，每个 `->` 成了全角的 `-＞`（40 处），`>`、`<` 成了 `＞`、`＜`，每个 `||` 成了 `//` 并吞掉了该行的其余部分：`if (!arg) {  // sscanf(arg, "%s %s", path, var) != 2){`（用法检查丢了 `sscanf`，`path` 和 `var` 从来没有被赋值），`if (prop[i] == "armor"  //prop[i]=="damage")`（`continue` 成了语法错误）。按原意恢复（`||`、被注释掉的 `sscanf`），`MONEY_D->price_str()`（同系没有这个守护进程）改成直接输出 `value`，删去 9 个没用的局部变量。编译没有警告，不带参数时打印用法。wqfy、zzfy、zzfy3 三个库的这个文件是同一份。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 24 条注册（23 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/dali/npc/pker.lpc`（`give_quest`）、`/d/death/npc/kkking.lpc`（`give_quest`）、`/d/fy/npc/kijy.lpc`（`give_quest`）、`/d/fy/npc/oldgun.lpc`（`give_quest`）、`/d/fy/npc/renkuang.lpc`（`give_quest`）、`/d/fy/npc/smith.lpc`（`do_buy`、`do_list`）、`/d/fy/npc/sqx.lpc`（`give_quest`）、`/d/fy/npc/tiandi.lpc`（`give_quest`）、`/d/huangshan/npc/xiangke.lpc`（`do_vendor_list`） 等共 23 个文件。最多的函数名：`give_quest` 16 处、`do_vendor_list` 3 处、`do_buy` 3 处、`do_list` 1 处、`do_jump` 1 处。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 5 个函数没有补（chat_msg 3, chat_msg_combat 1, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/fy/npc/biaotou.lpc`:`be_protect`、`/d/fy/npc/no3.b1k.lpc`:`brag`、`/d/fy/npc/no3.lpc`:`brag`、`/d/meiyuan/npc/zhuge.lpc`:`random_action`、`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 2 条单独成行的语句（`/clone/board/honghua_b`、`/clone/board/xiake_b`；`/d/menggu/ta13.lpc`、`/d/xiakedao/dating.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/doc/register`（`cmds/usr/help.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/doc/register` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 5 个文件里 5 行只含这个指针的行（`(: be_protect :),` `(: brag :)` `(: random_action :)`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 2 处（2 个文件）：拼名字的赋值 1 处、与汉字常量比较 1 处。例：`name[0..1]` → `name[0..0]`（`/d/qianfo/npc/master2.lpc:101`）；`things[0..13] == "天南地北双飞客"` → `things[0..6] == "天南地北双飞客"`（`/d/tieflag/magroom.lpc:42`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：18 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 18 处（9 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/std/buildroom.lpc:68`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/std/editskill.lpc:385`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 17 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。


## 无参数时命令对 0 的调用（2026-10-27，KB 06 §7.336 Also）

巫师/管理员命令在通过权限门之后仍会把 0 交给 `sscanf` / `read_file` / `find_living` 等。`lpc_fix_bare_arg.py` 在首次使用参数前加上 `if (!arg)`（或 `help(me)` / `GetHelp()`）。本库本批改动见该提交。

## 深度功能测试（2026-10-27，§6.25 ZHAOSHI 截断玩家技能）

玩家自创武功在 `// ZHAOSHI : 0` 处截断（EOF），无法加载。按同系完整 `moming-blade` 补一招 + valid_*/query_*/practice（2）：`daemon/skill/dianwen-unarmed.lpc`, `daemon/skill/wujoysword-sword.lpc`。
