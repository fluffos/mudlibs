# dfgs2 — 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire)

Archive: `东方故事二.rar` (byte-identical duplicate: `东方故事二 (1).rar`,
already listed in AGENTS.md's Duplicate archives table — this row covers
both). Port: 40027. Status: **done** (boots clean, full registration
flow verified end-to-end through an unusually long chain, including a
real Chinese name).

## What this is

"东方故事Ⅱ之天朝帝国" ("Eastern Story II: The Celestial Empire"),
credited to Annihilator and Phoebus.suny, "建立架构 Nov 6, 1995" / "测试
游戏制度 Apr 22, 1996". Mudlib root at `es2/es2/`, config at
`es2/config.cfg`. Same `adm/obj/{master,simul_efun}` layout convention as
`es1_win`/`esI` (archives #12/#13, also "东方故事" lineage) — but a
genuinely **different, smaller, distinct codebase** (564 raw files vs.
es1_win's ~8000+), not a snapshot of the same tree: no `std/object/
prop.lpc` angle-bracket-include bug here, different `domain_file()`
implementation (no `explode("/","/")` empty-array bug). Don't assume
lineage-shared fixes transfer 1:1 just because the directory layout
matches — verify each one is actually present before applying it.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**, applied to **both**
   `valid_write` AND `valid_read` in `adm/obj/master.lpc` — unlike most
   libs processed so far (where `valid_read` is often a hardcoded
   `return 1`), this build's `valid_read` ALSO called
   `load_object(SECURITY_D)` unconditionally with no re-entrancy guard.
   Both fixed with the standard `nosave` flag + `find_object()` gate.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `adm/
   simul_efun/chinese.lpc`'s `is_chinese()` and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → `< 1 || > 6`,
   removed `i%2==0` gate) — same shape as every prior lib. Also found a
   **new sub-variant of fix pattern #5** (sliding-window byte-width):
   `check_legal_name()` had a *separate* full-width-space rejection check,
   `if( name[i..i+1]=="　" )`, a 2-BYTE window under the old GBK
   assumption — under UTF-8 this is a 2-CHARACTER slice that can never
   equal the 1-character string `"　"`, so the check silently never
   fired. Fixed to `name[i..i]` (1-character slice, matching the fixed
   `is_chinese`'s per-character indexing used elsewhere in the same
   function).
3. **New: a driver-crash bug, not a compile error** — `master.lpc`'s
   `create()` unconditionally did:
   ```lpc
   if( ob = find_object(SIMUL_EFUN_OB) ) {
       efun::destruct(ob);
       call_other(SIMUL_EFUN_OB, "???");
   }
   ```
   an old-MudOS trick to force-reload simul_efun. On this driver,
   destructing the simul_efun object from inside master's OWN `create()`
   — i.e. during the driver's own early bootstrap, before
   `master_ob`/`simul_efun_ob` are fully settled — **segfaults the whole
   driver process**, crash trace rooted in `destruct_object()` dereferencing
   `master_ob->obname` on a not-yet-initialized pointer (`vm/internal/
   simulate.cc`). Not an LPC-level error at all — nothing in `debug.log`
   short of the raw backward-cpp stack dump gave any clue beyond "it
   segfaults right after boot starts." Fixed by simply dropping the
   destruct+reload dance entirely: the driver already loads simul_efun
   fresh before master's `create()` ever runs, so there was nothing stale
   to work around here in the first place.

## Interactive test result — full registration flow

This build's registration chain is noticeably longer than every other
lib processed so far — `id → confirm → password → confirm password →
email → race select → gender → THEN Chinese name` (most libs go straight
from id-confirm to Chinese name). Verified the ENTIRE chain in one
continuous connection:

1. `dfgstwo` → passes `check_legal_id` (letters only, no digits — an
   earlier attempt with a digit in the id, e.g. `dfgs2test`, was
   correctly rejected, not a bug).
2. `y` → password prompt.
3. `password1` (twice, matching) → accepted, email prompt.
4. `a@b.com` → race selection prompt (`human`/`yenhold`/`woochan`/
   `jiaojao`).
5. `human` → gender prompt.
6. `m` → **real Chinese name prompt**.
7. **`萧峰`** → accepted by the fixed `check_legal_name` — and this time
   verification went all the way to actually **entering the game world**:
   the session landed in an actual room ("小客栈" / Small Inn) with a
   full room description, not just a password/next-step prompt. This is
   the deepest registration verification done on any lib so far in this
   project.

## Known remaining issues (documented, not fixed)

(none outstanding — the `eval_chat()` issue formerly documented here was
fixed during the 2026-07-23 QA re-verification pass; see below.)

## Retroactive fixes (QA re-verification pass, 2026-07-23)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test in a fresh session) — both are genuine bugs, not
present in the original conversion notes above:

1. **`adm/obj/master.lpc`'s `log_error()` showed raw compiler diagnostics
   (including harmless warnings) to ANY connected player, not just
   wizards** (AGENTS.md §15af family, but a distinct/worse variant: this
   lib's version had no `wizardp()` gate at all, so ordinary players saw
   the full `"编译时段错误：" + message` text — file paths, line numbers,
   "Unused local variable" noise — every time an as-yet-uncompiled
   room/NPC was first touched, e.g. simply typing `look` in the starting
   room). Fixed to only show the full diagnostic to a wizard, and only
   alarm an ordinary player with the generic `default error message` for
   a genuine compile **error** (gated on absence of `"warning:"` in the
   message, same pattern as `dtsl`/`wuhanzhan`/`shenzhou`). This also
   required `#include "/include/runtime_config.h"` at the top of
   `master.lpc` (for the `__DEFAULT_ERROR_MESSAGE__` macro used in the
   fix) since the file had no includes at all before.
2. **The previously-documented `eval_chat()` bug (see git history) was
   actually blocking the starting-room innkeeper NPC from compiling at
   all** — once (1) above stopped masking it with raw compiler spam, it
   became clear this fires on literally every single new character's
   first room entry (`/d/snow/npc/innkeeper` inherits the broken
   `std/char/npc.lpc`). Given the outsized, first-impression impact and
   the trivial/safe fix, this was resolved rather than left as a
   documented gap: `eval_chat()`'s `switch(typeof(chat))` had a dead
   `case MATCH:` (an int constant, `0x102`) with a body byte-identical to
   the preceding `case STRING:` — this driver's `typeof()` returns string
   type-name constants (`STRING`/`ARRAY`/`FUNCTION` from `include/type.h`
   are themselves strings), so mixing the stray int case label in was a
   hard "Mixed case label list not allowed" compile error, not a
   different behavior being lost. Removed the redundant `case MATCH:`
   label (its body was already covered by `case STRING:`) — not
   fabricating new behavior, just deleting dead/incorrect duplicate code.

Re-verified with a fresh registration (real name `秦兰`, female) followed
by `look`/`score`/`quit`: the innkeeper NPC now greets the player
correctly ("掌柜说道：欢迎！欢迎！请里面坐！"), zero spam, zero real
`error:` lines in `debug.log`.

## lpcc sweep

427 files, 367 pass / 60 fail (85.9%). Memory stayed healthy throughout
(~17GB free, no pressure — this is a small lib). Failure tail not
triaged individually per AGENTS.md §6b/§13 — the full interactive
registration test (which went deeper than any prior lib, reaching an
actual room) is the verification gate.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (427 files,
  426 written/reformatted, 1 already-clean, 0 errors).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦凡`, ID
  `qinfan`, following this lib's own long ID→confirm→password→email→
  race→gender→Chinese-name flow, race `human`) reaching the actual game
  world (小客栈 starting room), innkeeper NPC greeting correctly
  ("掌柜说道：欢迎！欢迎！请里面坐！"); `look`/`score`/`quit` all
  produced correct output (full 精气神 status bars rendered correctly),
  zero real errors in `debug.log`. No regressions from the reformat or
  the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`'s
  `socket_create`/`socket_bind`/`socket_close` → `Undefined function`,
  caught non-fatally, `Initializations complete.` still printed). Like
  `dtsl2`, this lib's login path does **not** gate on
  `query_ip_number()`'s format, so a full registration proceeded all
  the way through under WASM too: ID `qinlan` → password → email →
  race `human` → gender `f` → Chinese name `秦岚` → reached the actual
  game world (小客栈), innkeeper NPC greeted correctly, `look` produced
  correct room output, `quit` exited cleanly. **This lib is confirmed
  fully playable under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched (fail-closed: only an exact `127.0.0.1`/`127.`-prefix
match is exempt; a malformed/non-string address is treated as remote):

- `adm/daemons/logind.lpc` `logon()` (~line 56): the `ANTI_BUZZER`
  per-IP character-creation throttle (`buzzer_ip[ip] >= 10` ->
  `destruct(ob)`) now exempts loopback. `ANTI_BUZZER` IS defined
  (`include/login.h`), so this gate is live, unlike some other
  `#ifdef`-gated checks in this file.
- No live ban-site/site-restriction daemon (no `band.lpc`/`sited.lpc`
  shipped or preloaded in this lib). `get_id()`'s `ENABLE_BAN_SITE`
  block (~line 117) IS defined and live, but only applies to
  `wizhood(arg) == "(player)"` accounts against a 2-entry static IP
  list (`202.96.134.135`, `202.102.111.2`) that can never match
  loopback -- left unpatched as genuinely out of scope (not a
  loopback-relevant gate).
- No `uptime()` startup-grace gate found (the `UPTIME_CMD->main()` call
  in `logon()` is a cosmetic "uptime so far" banner, not a grace-period
  check).

**Real bug found and fixed while verifying re-login (distinct from
registration) as required by AGENTS.md §10.1** -- this is the more
significant fix from this pass, not loopback-related:
`adm/daemons/securityd.lpc`'s `valid_read()` had a `restore_object`
special case intended to let the login object read back its own save
file:
```
if (func == "restore_object")
  if (sscanf(base_name(user), "/obj/%*s") && sscanf(file, "/data/%*s")
      && file == (string)user->query_save_file())
    return 1;
```
but the driver's `restore_object()` (`vm/internal/base/object.cc`)
always appends the save extension (`.o`) to the `file` argument passed
to `valid_read`, while `obj/login.lpc`'s `query_save_file()` returns the
bare path with no extension -- so `file == query_save_file()` was
**always false**. The euid-based fallback below it also always denied,
because `obj/login.lpc`'s own `logon()` deliberately clears the login
object's OWN euid to null (`seteuid(0); // Let LOGIN_D export proper uid
to us.`) so that `LOGIN_D`'s later `export_uid(ob)` call (which only
succeeds when `ob->euid` is falsy, per the driver's `f_export_uid`) can
set `ob`'s UID -- `export_uid()` only ever sets `uid`, never `euid`
(confirmed by reading `packages/uids/uids.cc`), so the login object's
euid stays null for its entire life by design. Net effect: **every
returning player's `restore_object()` call was permission-denied,
100% of the time** -- confirmed via `catch()`+`efun::write()`
instrumentation showing `euid=0 uid=fluffos ... err=*restore_object:
read permission denied`. This silently dropped straight into "对不起，
您的人物储存挡出了一些问题" and destructed the connection on EVERY
re-login attempt for EVERY account, not just the newly-seeded admin --
a pre-existing bug, invisible until now because every prior
verification pass in this lib's history tested registration through to
`quit` but never a SECOND connection logging back into the same id
(exactly the gap AGENTS.md §10.1 warns about). Fixed by accepting the
save-extension-qualified path too (`file == save_file || file ==
save_file + ".o"`), which is the minimal correct fix (the intended
"user may read back their own save file" grant, just written against
the wrong path shape). Verified: both `fluffos` and a fresh throwaway
player (`ceshiba`) can now fully disconnect and reconnect into their
existing character. This was NOT present in the original registration-
only NOTES above and NOT something this pass introduced -- it dates to
however this lineage's `securityd.lpc` was originally authored/forked.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, registered through the
normal long flow (id -> confirm y -> password x2 -> email -> race
`human` -> gender -> Chinese name 浮浮), pre-granted `(admin)` via
`adm/etc/wizlist` (`fluffos (admin)` line, `test`'s existing entry kept)
before registration so the account came out already showing "目前权限：
(admin)". Verified on a SEPARATE re-login (exercising the restore-path
fix above): password accepted, `update /d/snow/inn_hall` succeeded
("重新编译 /d/snow/inn_hall.lpc ...Ok."). Save files
(`data/user/f/fluffos.o`, `data/login/f/fluffos.o`) are plain untracked
paths, not covered by any `.gitignore` pattern -- a normal
`git add libs/dfgs2/` picks them up, no force-add needed.

Retest: fresh normal registration (id `ceshiba`, name 秦月, female)
reached 小客栈, innkeeper greeted correctly, look/quit correct; a
SECOND connection re-logging into `ceshiba` (the restore path) also
succeeded post-fix. debug.log clean across all four driver runs this
pass (only expected boot-time config dump and SIGTERM-on-kill lines).
Four driver instances started/killed by exact PID during this pass
(one extra cycle for the diagnostic instrumentation added and then
removed while root-causing the restore bug). Test character `ceshiba`'s
saves removed afterward; `fluffos`'s kept.

## 深度功能测试 / Deep functional test (2026-07-24)

Round-two deep playthrough pass (see `libs/bxsj/NOTES.md` and
`libs/xiyouji/NOTES.md`'s own "深度功能测试" sections for the worked
examples this follows — both found real quit-time/first-visit crashes
invisible to every earlier verification layer). This lib has no
`doc/help/` directory at all (`work/doc/` only has `wiz/`, and
`cmds/usr/help.lpc`'s `DEFAULT_SEARCH_PATHS` point at `/doc/help/`,
`/doc/skill/`, `/doc/efuns/`, `/doc/lfuns/`, `/doc/applies/` — none of
which exist in this archive), so there is no shipped `help newbie` to
read; planning was done by reading room/NPC `.lpc` source directly, per
the checklist's own fallback instruction. Native driver (`build-debug`),
played as an ordinary new player through registration, exploration,
safe sparring, the organic apprentice/class-join path, a real `quit`,
and a real-wall-clock-gap reconnect.

**Test character** (kept, not cleaned up, as playthrough evidence): id
`shenluoy`, Chinese name 沈落雁 (male), password `TestPass1`. State at
end of pass: 【方士】(alchemist-class apprentice of 陈维侠/Chen Weixia),
skills `dodge` (0/8) and `parry` (0/2) learned passively from the
sparring fight below, 30/30 精气神, food/water ticking down normally,
empty inventory, located at 小客栈 (its saved `startroom`). Saves:
`work/data/user/s/shenluoy.o`, `work/data/login/s/shenluoy.o`.

### Bug found and fixed: 4 rooms reference their own objects via the wrong subdirectory, crashing the town square's first-ever visit every boot

**New bug shape for this project's catalog** — not the §7.16 stale-
timestamp class, not the §7.17 reset/init-reentrancy class. This is a
plain wrong-path typo (per §6.6's "pre-existing typo classes" family)
but promoted here because of its severity: it crashes `/d/snow/square`
("广场中央", the town's central 4-way hub, one hop from the inn in every
direction) on literally the first move any fresh character makes past
the starting room, on every fresh boot.

- **Symptom** (reproduced live, pre-fix, fresh boot, fresh character):
  walking `小客栈` → `east` (广场) → `east` (广场中央) throws
  ```
  执行时段错误: *Bad argument 1 to EFUN call_other()
  Expected: object, string, array,  Got: int(0).
  程式: /std/room.lpc:76
  物件: /d/snow/square
  呼叫调用错误在:
  command_hook()            /feature/char/command.lpc:37
  main()                    /cmds/std/go.lpc:65
  create()                  /d/snow/square.lpc:32
  setup()                   /std/room.lpc:362
  reset()                   /std/room.lpc:101
  make_inventory()          /std/room.lpc:76
  ```
  The crash is caught (driver error handler), so the room is still
  entered and looks superficially fine on screen — exactly the class of
  bug `quit`-and-eyeball testing (and even a `look` right after) will
  never catch; only `debug.log` shows it. Because it fires on the
  room's *first* `reset()` of the process's life, once the object is in
  memory every later visit is clean — invisible to boot-log watching and
  to any registration smoke test that doesn't specifically walk a fresh
  character past the starting room's immediate neighbors.
- **Root cause**: `d/snow/square.lpc:14` declares its `"objects"`
  mapping with `__DIR__ "obj/pot": 1`. `square.lpc` lives directly under
  `/d/snow/`, so `__DIR__` there is `/d/snow/`, and `/d/snow/obj/pot`
  **does not exist** — this archive keeps ALL of `d/snow`'s plain
  (non-NPC) object files under `/d/snow/npc/obj/`, not `/d/snow/obj/`
  (confirmed against the pristine `raw/` extraction too — this is a
  pre-existing authorial typo, not a conversion artifact). `std/
  room.lpc`'s `make_inventory()` does `ob = new(file); if
  (ob->violate_unique()) ...` with no null-check between the two —
  `new()` on a nonexistent file returns `0`, and `0->violate_unique()`
  is exactly the "Got: int(0)" `call_other()` crash above. Every other
  `d/snow` file that references `__DIR__ "obj/..."` lives under `/d/
  snow/npc/`, where the path resolves correctly (confirmed by grepping
  every `__DIR__ "obj/` hit in the tree) — `square.lpc`, plus 3 more
  files living directly under `/d/snow/` (not `/d/snow/npc/`), all have
  the identical wrong-subdirectory typo:
  - `d/snow/square.lpc:14` — `"objects"` mapping entry `obj/pot`
    (**the one live-reproduced above** — 广场中央 is unavoidable
    starting-zone traffic).
  - `d/snow/fireplace.lpc:18` — `"objects"` mapping entry `obj/
    woodsword` (same `make_inventory()` crash shape, on first entry to
    `大灶内`, a hideable side-room off the inn's kitchen).
  - `d/snow/kitchen.lpc:16` — `"objects"` mapping entry `obj/dumpling`
    (same shape, a private-house kitchen reachable by climbing a wall
    from `/d/snow/epath`).
  - `d/snow/ruin1.lpc:62` — `ob = new(__DIR__ "obj/hairpin"); ob-
    >move(this_player());` inside `do_search()`'s "search 杂草" player
    action (only active 10:00–13:00 game-time) — same `new()`-returns-0
    root cause, but the crash site is `ob->move(...)` instead of `ob-
    >violate_unique()` since this call bypasses `make_inventory()`
    entirely; not live-reproduced (would require hitting the exact
    in-game hour window) but fixed by the identical code-shape match,
    consistent with this project's standing "port the sibling's proven
    fix" practice (AGENTS.md §2.1) — flagged here as the one-of-four not
    directly reproduced live.
- **Fix**: change all 4 to the correct `npc/obj/...` subpath (the actual
  location of `pot.lpc`/`woodsword.lpc`/`dumpling.lpc`/`hairpin.lpc`,
  confirmed present on disk in every case — this is a wrong path to
  *existing* content, not missing content, so fixing the reference is
  correct per AGENTS.md's "missing zone content is an archive gap,
  don't fabricate" vs. "wrong path" distinction):
  ```diff
  -    __DIR__ "obj/pot": 1,
  +    __DIR__ "npc/obj/pot": 1,
  ```
  (and the same `obj/` → `npc/obj/` change at `fireplace.lpc:18`,
  `kitchen.lpc:16`, `ruin1.lpc:62`).
- **Verified**: post-fix, fresh driver restart, fresh walk `小客栈` →
  `east` → `east` reaches `广场中央` cleanly, `大水缸(Pot)` now visible
  in the room's object listing (`look` output), `debug.log` grepped for
  `error:`/`fatal`/`Too deep recursion`/`Too long evaluation` after the
  full session (registration → exploration → sparring → apprentice →
  acquire → `quit`) — **zero hits**. `fireplace.lpc`/`kitchen.lpc`/
  `ruin1.lpc` fixed by code-shape match and code-read confirmation
  (file existence at the corrected path checked for each) but not
  independently walked to live, given the time budget for this pass —
  a future pass reaching `大灶内`/private-house `厨房`/`search 杂草` at
  10–13点 in `破旧大宅` should spot-check these three specifically.

### What was tested and confirmed working

- **Registration**: one real Chinese name (沈落雁/Shenluoy, male),
  reaching 小客栈, innkeeper greeting correctly (already verified in
  earlier passes above, re-confirmed here as the entry point for this
  playthrough).
- **Exploration**: walked 小客栈 → 广场(west) → 广场中央 → 广场(north,
  child NPCs) → back through 广场 → 广场(west) → 广场(southwest) →
  街道(wstreet1) → 私塾(school, teacher+alchemist NPCs). Room
  descriptions, exits, and day-time flavor text (太阳正高挂在东方的天空
  中 etc.) all correct throughout.
- **Character info**: `score` (title/attributes/精气神 bars/食物饮水/
  经验评价) and `hp` both correct at every stage (fresh, post-sparring,
  post-apprentice); `i`/`skills` correct throughout.
- **Safe sparring** (checklist step 5): this lib's `cmds/std/fight.lpc`
  implements safe/lethal combat as a `query("civilized")` branch per
  target, not a dedicated training-dummy object — `"civilized"` is set
  to `1` generically by every human-race daemon's `initialize()`
  (`daemon/race/human.lpc` etc.; `daemon/race/beast.lpc` pointedly has
  the same line **commented out**, so non-human "beast"-race NPCs would
  get the real `kill_ob()` path instead — none exist in this archive's
  reachable content to confirm live). Used `fight child` against one of
  the two `小孩`(child) NPCs in 广场(north) — both `child1.lpc`/
  `child2.lpc` have `accept_fight()` return `1` unconditionally, an
  explicit "always spar" village-kid pair, matching the checklist's
  "safe sparring before a real fight" mechanism. Produced a normal
  turn-by-turn bout, child fled crying ("哇地一声哭了起来：你打我！妈妈
  ！") then resumed playing, both fighters ended at full 精/气/神 —
  confirmed non-lethal, `combat`/`unarmed mastery` exp gained, and (a
  side finding, not tested for further depth) `dodge`/`parry` skills
  were silently auto-granted at level 0 purely from having fought once
  — this lib's skill-acquisition-by-doing path, separate from the
  broken `acquire` NPC-teacher path below.
- **Sect/class-join mechanism** (checklist step 6, sect half): the
  `apprentice <NPC>` command is this lib's class-join mechanism (no
  separate menpai/sect system exists in this small archive — see intro
  section above, 564 raw files vs. es1_win's ~8000+). Confirmed the full
  2-step organic flow live: `feature/char/master.lpc`'s
  `accept_apprentice()` is deliberately unimplemented in the base class
  (commented out, so `ob->accept_apprentice(me)` on any NPC that doesn't
  override it silently `call_other`s to nothing and returns 0) —
  **`d/snow/npc/alchemist.lpc` (陈维侠) is the ONLY NPC in the entire
  codebase that overrides `accept_apprentice`/`init_apprentice`**
  (confirmed via `grep -rl accept_apprentice`), so it is also the only
  reachable class-join path in this archive. First `apprentice chen`
  attempt correctly fails with a queued multi-line persuasion dialogue
  (`陈维侠说道：拜我为师？呵呵...` → ... → an internal `set_flag`
  closure that flips a `pending/alchemist` temp flag once the dialogue
  finishes draining over several heartbeats); a SECOND `apprentice chen`
  after waiting for the chat queue to drain succeeds
  (`你跪下来恭恭敬敬地向陈维侠磕了四个响头，叫道：师父！`), title
  changes from `【 平民 】` to `【 方士 】`, `score` gains a new
  `alchemy` score category. This 2-attempt "convince them first" shape
  is a legitimate designed mechanic, not a bug — worth recording so a
  future tester doesn't mistake the first `notify_fail` for a dead end.

### Finding, not a crash bug: the organic skill-teacher path is a dead end for every NPC in this archive (documented, not fabricated)

Checklist step 6's other half — "learn at least one skill via the
organic NPC-teacher path" — **could not be completed live, and static
analysis says it cannot succeed for ANY NPC in this codebase, not just
the ones tried**. This is a content-completeness gap, not a crash, so
per AGENTS.md's "missing zone content is an archive gap, not a bug...
don't fabricate" precedent (§7.14) this was **left as documented, not
implemented** — filling in real skill-teaching values (which skills,
what levels, what cost/gating) would be inventing game balance not
present in the source, unlike the wrong-path bug above which restores
an already-authored reference.

- `cmds/std/acquire.lpc`'s `acquire <skill> from <NPC>` command (the
  only skill-learning verb in this archive — there is no separate
  `learn` command) always ends in `return ob->acquire_skill(me,
  skill)`. `grep -rl acquire_skill` across the whole tree finds exactly
  **one** implementation in the entire codebase,
  `d/snow/npc/alchemist.lpc`:
  ```lpc
  int acquire_skill(object ob, string skill) {
    switch (skill) {
      case "alchemy-medication":
      case "alchemy-wealth":
      case "alchemy-magic":
      case "alchemy-immortality":
      default:
    }
    return 0;
  }
  ```
  every case (including the real alchemy skills 陈维侠 himself knows,
  set via `set_skill()` in his own `create()`) falls through to an empty
  body and an unconditional `return 0` — this is a stub/placeholder, not
  wired to actually call `me->improve_skill()`/`advance_skill()` for
  any skill, ever. `d/snow/npc/teacher.lpc` (王怀芝, teaches `literate`
  per its `set_skill("literate", 60)` and its room's flavor text) has no
  `acquire_skill` override at all, and (per the apprentice finding
  above) no `accept_apprentice` either, so he can never accept a student
  in the first place.
- **Live-verified** (post successfully becoming 陈维侠's apprentice):
  `acquire alchemy-medication from chen` → the flavored master-request
  message prints correctly (`你向陈维侠磕头行礼，恭恭敬敬地说道：师父在
  上，求您传授徒儿「alchemy-medication」！`) then
  `看起来陈维侠不想教你这项技能` (the command's own generic failure
  message) — confirming the stub really does refuse unconditionally,
  live, not just on paper. Also tried `acquire literate from wang`
  (未曾拜师/never apprenticed to him) — same generic refusal, expected
  given no `accept_apprentice` exists for him either.
- Net effect: a new player can walk the entire intended "become a
  disciple" ritual (the multi-stage persuasion dialogue, the kowtow
  message, the class-title change, the `score` category) and it *reads*
  complete, but the promised payoff — actually learning a skill from
  your new master — never fires for anyone, for any skill, in this
  archive as shipped. This is consistent with the intro section's
  characterization of this lib as a genuinely smaller/less-finished
  codebase than its `es1_win`/`esI` siblings, not a regression from
  conversion.

### Explicitly not verified live (time/reachability budget), stated per §10.7 item 6

- **Shop purchase**: `buy <item> from <NPC>` was exercised live against
  `店小二`(waiter) in 小客栈, but a fresh character starts with **zero
  money** (no starting-money grant found anywhere in `logind.lpc`/
  `CHAR_D->setup_char`) and this archive's only discovered in-world
  income source is a day-labor job at `货栈`(store, `d/snow/store.lpc`)
  run by `工头`(foreman) — moving crates for 5 coin each. `buy dumpling
  from waiter` correctly hit the `can_afford()` rejection path
  (`你身上的钱不够`), proving that half of the transaction code live,
  but earning money first (and then a full successful `buy` →
  `deliver_merchandise` → `handover` round trip) was not pursued given
  this pass's time budget. The underlying code
  (`feature/npc/vendor.lpc`, `d/snow/npc/waiter.lpc`) was read and
  appears structurally sound (mirrors the same pattern verified working
  in other libs' NOTES).
- **Real combat and death/respawn**: not reached live. `fight.lpc`'s
  lethal branch only triggers against NPCs whose race daemon does NOT
  grant `"civilized"` (every human-race NPC gets it automatically; see
  above) — no non-human/"beast"-race NPC exists anywhere in this
  archive's reachable content to test that branch against, and the
  only other candidate hostile content (`d/goat`, 野羊山 bandits) is
  permanently unreachable: `d/snow/ngate.lpc`'s only northward exit
  clones `/d/domain/snow2goat`, a file that **does not exist anywhere
  in the archive** (confirmed — genuinely missing content, not a typo:
  no `snow2goat` file exists under any plausible path in `raw/`
  either), and is additionally blocked by 4 `garrison` NPCs + 1
  `lieutenant` at the same gate whose `intercept()` unconditionally
  refuses any `go north` with an in-character "盗匪出没" excuse. Reaching
  real combat would require deliberately attacking one of these
  civilized guard NPCs (triggering `soldier_assist` group retaliation)
  purely to force the non-civilized `kill_ob` path — assessed as a
  time-costly, one-way (character-risking) grind not justified by this
  pass's remaining budget, so explicitly left unverified rather than
  attempted partially. `d/hell` (阴曹地府, the death realm) exists and
  is presumably the intended post-death destination
  (`DEATH_ROOM`/`user->is_ghost()` handling seen in `logind.lpc`'s
  `enter_world()`) but was not reached or reviewed further.

### State persistence across quit/reconnect (checklist step 8)

`quit` (typed explicitly, not a connection timeout) produced the
expected `欢迎下次再来！` message; `debug.log` grepped immediately after
(`error:`/`fatal`/`Too deep recursion`/`Too long evaluation`) —
**zero hits**, across the whole session including the fix verification,
the sparring fight, and both apprentice attempts. Waited a real ~2.5
minutes of wall-clock time (backgrounded `sleep`, confirmed elapsed via
`date` before/after, not simulated), then reconnected with `shenluoy`/
`TestPass1` — this exercised the actual save/restore path (the
"目前权限：(player)" banner reprinted, confirming a real reload from
disk rather than the same-process "linkless reconnect" seen during
mid-session probing, where a dropped-but-not-quit connection can rejoin
with just id+password and skip straight back into the still-live
object). Post-reconnect `score`/`skills` showed 【方士】 title and the
`alchemy` score category, `dodge`/`parry` skills, and 精气神/食物/饮水
all correctly persisted; location correctly returned to `小客栈` (NOT
`私塾`, where the character was standing at `quit` time) — confirmed by
reading `cmds/usr/quit.lpc`/`cmds/usr/save.lpc` that this is **by
design**, not a bug: only rooms flagged `"valid_startroom"` (e.g. 小客栈
itself) can ever become a saved login point via the separate `save`
command, and plain `quit` never updates `"startroom"` on its own — so
relogging back at the inn rather than at the last-visited room is
correct, intended behavior for this codebase, not a state-loss bug.

### Process hygiene for this pass

Two driver instances (pre-fix reproduction, post-fix verification),
started with `setsid nohup ... & disown`, killed by exact recorded PID
(`1377932`, then `1387464`) — both confirmed dead via `ps`/`ss` after
kill, not `pkill -f`. `log/debug.log` cleared once between the two runs
to isolate the pre/post-fix comparison; no other scratch/instrumentation
files were created. `shenluoy`'s saves kept as playthrough evidence per
this pass's own test-character convention (matching `xiyouji`'s
`shenqy`/`shenqf`).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。
