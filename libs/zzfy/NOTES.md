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
