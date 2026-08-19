# 最终幻境.zip → `zzhj`

- Archive: `archives/最终幻境.zip`. Mudlib root at the archive top level,
  alongside a bundled Windows `mudos.exe`/`mudos.log` (ignored — our own
  driver is used). ~1.6k raw files, 643 `.lpc` files after conversion —
  a small, focused lib (not a mega-lib).
- Identified via the archive's own `README`/`readme.txt`: this is
  **"The Final Frontier" v0.6e** ("最终边界"/"最终幻境"), an ES2-mudlib
  extension by Spock (`bbs.csmc.edu.tw/spock`), Traditional
  Chinese/BIG5-origin ("由著名的『打混蟑螂史巴克』所創立" — in-game
  banner credits "Spock, the roach"). `config.cfg`'s `name :` field and
  the in-game banner both confirm **最终幻境/The Final Frontier** as the
  actual mud name — matches the archive filename, no stale-name surprise
  (contrast AGENTS.md §5.1's `dtsl2`/`xkxz2` cases).
- Proposed number: **061** (new, unique).
- Port: **40099** (as assigned; confirmed free).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (韩风 natively, 沐晨 under WASM), admin
  (`fluffos`) verified via `update` on both drivers.

## Triage / lineage

Genuine LPC mudlib. This is the **ES II / 东方故事 mega-family** per
AGENTS.md §11 (explicit in-game credit: "FF 的 MUD 函數庫改寫自東方故事
II, 在此叩謝" — "FF's MUD library is adapted from ES2, thanks"), but a
distinct, much smaller/differently-shaped game from either
`sjcs` or `sanjieshenhua` — confirmed via diff (369-line
`master.lpc`/331-line `securityd.lpc`/658-line `logind.lpc` here vs
495/416 and 316/747 for the other two). Not a derivative of either
sibling in this batch.

## State at handoff (this session)

A previous agent session had already: extracted the archive, converted
encoding/renamed, written `config.fluffos` (port 40099), applied the §7.1
`load_object(SECURITY_D)` recursion guard in `master.lpc`, fixed
`private`→`nosave nomask` on `command_hook` (old copy kept alongside as
`feature/command.c.old` for reference), disabled `dns_master` in preload,
seeded `fluffos (admin)` in `adm/etc/wizlist`, and had ALREADY run a full
registration test through to a real Chinese name (`fluffos`/浮浮 and a
second test account `qinfeng`/秦风 both have complete `.o` saves under
`data/user/`/`data/login/`). This lib had no ban/site/uptime gates to
begin with (grepped for `is_banned`/`sited`/`uptime()`-gates — none
found), so no loopback-allow patch was needed here (documented as a
deliberate no-op, not an oversight). No NOTES.md/README.md existed yet.
This session verified the existing work end-to-end (native + WASM,
including the admin `update` check that hadn't been run yet) and found no
further code fixes were needed — `default_trusted_write` here already
includes `"(admin)"` for `/` out of the box (unlike sibling
`sanjieshenhua`'s commented-out default), so the admin write-ACL just
worked on the first try.

## Verification (native)

Booted `cd libs/zzhj && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log`.

Full registration flow (fresh id `haifengc`, real Chinese name **韩风**):
English id (3-20 lowercase letters; note — unlike the two 三界 siblings,
this lib has **no** special `new` keyword: ANY unregistered id goes
straight to a "create new character?" confirm) → `y` → Chinese name (1-10
hanzi) → password (≥5 chars) → confirm → email → **6-attribute point-buy**
(`str`/`dex`/`int`/`not`/`con`/`tec`, each within a fixed per-attribute
range, must sum to exactly 60 — e.g. `10 10 10 10 10 10`) → gender (m/f)
→ entered `FF 新手學院大廳` (newbie academy hall). `look`, `score` (full
attribute+combat stat card), and `quit` all correct.

Admin: logged in as `fluffos`/`Mud@2026` (already registered by the prior
session, display name 浮浮, `(admin)` status shown immediately via the
pre-seeded wizlist line) → `update /adm/obj/master.lpc` →
`重新編譯 /adm/obj/master.lpc﹕成功﹗` → `quit` clean. No data-file fix
needed (unlike `sanjieshenhua`) — this lib's `securityd.lpc` ships a live
(uncommented) `"/" : ({"Root","(admin)","(arch)"})` in
`default_trusted_write`.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/zzhj` — same full registration flow (fresh id
`wasmren`, real Chinese name 沐晨) reached the same starting room;
`look`/`score`/`quit` all correct. Admin login as `fluffos` +
`update /adm/obj/master.lpc` also succeeded under WASM. **This lib is
fully playable under WASM** — no IP-format/sockets-absent blockers hit on
this login path, and no ban/site gate existed to need a loopback patch in
the first place.

## Known remaining issues (documented, not fixed)

- The archive's own in-game banner states the mud is no longer under
  active development by its original author ("即日起, 本 mud 停止研發") —
  cosmetic/historical, does not affect playability.
- lpcc sweep not re-run this session (no fresh `lpcc_fail.log`); the real
  boot + full interactive registration/admin test on both drivers is the
  verification gate actually used here (small lib, fast enough to fully
  play-test directly).

## How to run

```
cd libs/zzhj
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40099 --timeout 20 --idle 1.0 \
  --send "yourid" --send "y" --send "你的中文名" \
  --send "yourpass" --send "yourpass" --send "you@example.com" \
  --send "10 10 10 10 10 10" --send "m" \
  --send "look" --send "score" --send "quit"
```

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: completely clean, zero grep
hits beyond the known-benign early `Unable to open log file:
"log/debug.log"` line and the harmless `nosave crash(string error,
...)` false-positive — no new findings. Proactively fixed
`adm/simul_efun/object.lpc`'s `file_owner()` (`return name` → `return
dir`) as part of a repo-wide port of a bug found live on sibling
`zhonghua2` (misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>`
log_error writes to a bogus path); didn't fire in this lib's own sit,
fixed proactively since it's the identical shared file. Retest: fresh
registration (id `haiyunb`) through look/quit, clean.

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

Full continuous session: read `doc/help/newbie`, `doc/help/combat`,
`doc/help/skill` first (this lib's own newbie primer, `kill`/`fight`
distinction, and skill-learning overview) → fresh registration (id
`shenqiao`, real Chinese name **沈翘**) → `look`/`score`/`i` at every
state change → guildhall/sect-join organic path (blocked, see below,
but not before it surfaced 4 real bugs) → admin-shortcut skill grant
via `call` → combat-mechanism code read + `no_fight` gate live-check →
`quit` (no new-account grace-period/delete window exists — grepped,
none found, so a real `quit` was used, not a simulated disconnect) →
`debug.log` grep → real wall-clock reconnect (~9 min gap, spent
drafting this section and auditing all 9 other class masters via
`update`) → confirmed state persisted (room, stats, id/password).

### Bugs found and fixed

1. **§7.90 (`maximum evaluation cost` too low for this lib's own
   `make_body()` cold-compile), harsher variant matching the
   `xyj2000f`/`xiyouji450` shape exactly.** `config.fluffos` shipped
   `300000`; `/std/char`'s full inheritance chain (`feature/action`,
   `feature/attack`, `feature/command`, `feature/damage`, `feature/
   skill`, ...) compiling for the first time during
   `logind.lpc::make_body()` (called from `get_email()`, the very next
   step after entering an email address during registration) reliably
   tripped `Eval interrupted: object adm/obj/master cost limit
   reached, limit: 300000 usec` / `*Too long evaluation. Execution
   aborted.`, 100% reproducible on a fresh driver process — every new
   registration silently hung right after the email prompt, no
   player-visible error. Confirmed by reproducing on a fresh boot,
   then fixing (`5000000`, this project's common raised value) and
   reproducing a clean full registration on a second fresh boot with
   zero further `cost limit reached` hits in `debug.log`.
2. **§7.11 (`log_file()` missing `assure_file()` guard).**
   `adm/simul_efun/file.lpc`'s `log_file()` did a bare `write_file(LOG_DIR
   + file, text)` with no directory guard; `logind.lpc::get_gender()`
   (the last registration step, right before `enter_world()`) calls
   `log_file("USAGE", ...)`. This lib got lucky in that a bare 2-arg
   `write_file()` into a missing dir just silently no-ops on this
   driver build rather than throwing (unlike `xixingzhanji`'s 3-arg
   overwrite-mode variant), so it didn't crash registration outright —
   but the USAGE log was silently never written on a fresh checkout
   (no `work/log/` tree shipped). Fixed with this lineage's
   established pattern: `assure_file(LOG_DIR + file); write_file(...)`
   plus a forward declaration (same-file forward-reference needed,
   `assure_file()` is defined textually after `log_file()`). Verified:
   `work/log/USAGE` now gets created and appended on every
   registration/login.
3. **New instance of the §8.3a `private eval_function()` /
   `start_call_out()` shape**, independently confirmed on this
   ES2-derived-but-distinct lineage (zzhj is explicitly NOT a
   derivative of any other lib in this batch per AGENTS.md §11, so
   this is a fresh, unrelated occurrence of the same underlying driver
   quirk, not a copy-paste). `feature/action.lpc`'s
   `start_call_out()` schedules `call_out("eval_function", delay,
   fun)`, but `eval_function()` was declared `private` in the same
   file — once `feature/action` gets `inherit`ed into `std/char.lpc`
   (the universal player/NPC base), the driver's own internal
   `call_out` dispatch sees `DECL_HIDDEN` instead of `DECL_PRIVATE`
   and silently no-ops with `apply() with insufficient permission`
   whenever any temporary-condition recovery call_out actually fires.
   Fixed identically to precedent: dropped `private`.
4. **New, codebase-wide finding: two bare function calls
   (`exert_function`, `map_skill`) referenced by nearly every
   class/guild master NPC's `create()` (`daemon/class/*/master.lpc`,
   `champion.lpc`, `executioner.lpc`, `taolord.lpc`, ...) were never
   implemented ANYWHERE in this archive.** `exert_function` is used as
   `(: exert_function, "powerup" :)` in `chat_msg_combat` arrays (8
   files); `map_skill(base, special)` is called directly in `create()`
   to presumably link a base skill to a sect's signature technique (9
   files). Neither is defined in any inherited base, any simul_efun,
   or anywhere else in the tree (`grep -rn` returns zero definitions,
   only call sites). Compounding effect: `exert_function` is a
   compile-time "Undefined variable" error (file fails to compile at
   all); `map_skill` compiles fine but throws "Undefined function
   called: map_skill" as an uncaught RUNTIME error mid-`create()`. On
   `daemon/class/fighter/guildhall.lpc` (the ONLY class/guild room
   placed anywhere in the entire game world — see below), this
   uncaught error propagated up through `std/room.lpc`'s
   `make_inventory()` → `reset()` → `setup()` → `create()` chain,
   which is itself called UNCAUGHT from `feature/move.lpc`'s
   `move()` (`call_other(dest, "???")`, line 70, not wrapped in
   `catch()`) — meaning literally EVERY attempt to enter this one
   reachable guildhall aborted mid-`move()`, silently parking the
   mover in `/obj/void.lpc` ("虛無") instead. Fixed both as safe
   no-op stubs in the shared bases already universally inherited
   (`feature/attack.lpc` for `exert_function`, since it's part of
   `std/char.lpc`'s inherit chain; `feature/skill.lpc` for
   `map_skill`, same reasoning) — deliberately NOT guessing at real
   combat-flavor/skill-linkage behavior (game-design judgment call,
   out of scope per §10.7). This unblocked `champion.lpc` and 7 of the
   9 other class masters (`assassin`, `beggar`, `lama`, `scholar`,
   `bonze`, `ronin`, `executioner` — verified via `update` on each)
   to compile and `create()` cleanly. **Not a new AGENTS.md catalog
   entry**: checked §11 first — zzhj is explicitly not a derivative of
   any sibling in this batch, so this exact missing-function pair has
   no portability value to other libs; documented here only.
5. **§7.20 flavor 2 (net-dead reconnect never restores location),
   confirmed instance — AGENTS.md already flags FF/ES2-derived
   codebases sharing this exact `net_dead()`/`VOID_OB`/`user_dump()`
   shape as likely-affected, and this is that shape exactly.**
   `obj/user.lpc`'s own `reconnect()` method correctly restores
   `query_temp("last_location")` (set by `net_dead()` when the
   connection drops) via `move(last_loc)` — but nothing ever called
   it. `grep -rn "->reconnect(" work/` returned zero hits, the exact
   tell described in §7.20. The login flow actually reconnects through
   `adm/daemons/logind.lpc`'s own differently-scoped `reconnect(ob,
   user, silent)`, which only does `set_link`/`set_body`/`exec` +
   channel announcements and never touches location. **Live-reproduced
   before fixing**: registered fresh, let the connection idle-close
   without `quit` (net_dead), reconnected — landed in "虛無"
   (`/obj/void.lpc`) instead of `新手學院大廳`, zero trace in
   `debug.log` (exactly as §7.20 describes — the hardest bug class in
   the catalog to spot). Fixed per the established pattern: added
   `user->reconnect()` to `logind.lpc`'s `reconnect()`, called before
   the "reconnected" announcement so it fires in the real room, not
   the void. **Re-verified live post-fix**: same disconnect/reconnect
   sequence now correctly lands back in `新手學院大廳`.

### Skill/sect acquisition: both paths tested, organic path found broken (pre-existing, not fixed further)

- **Admin shortcut**: no dedicated `setskill`/grant-sect admin command
  exists in `cmds/wiz/`, `cmds/adm/`, or `cmds/arch/` (checked all
  three) — but the generic `call <obj>-><func>(<args>)` wizard command
  (`cmds/wiz/call.lpc`) works as the de facto shortcut. Live-verified:
  `call shenqiao->query_skill("unarmed")` → `0`, `call
  shenqiao->set_skill("unarmed", 50)` → `50`, `call
  shenqiao->query_skill("unarmed")` → `50`. Documented honestly per
  §10.7 point 4 rather than claiming a dedicated command exists.
- **Organic path — found broken by multiple independent, pre-existing
  content gaps, none introduced by this project's conversion (all
  present in the very first commit that added this lib's tree
  unchanged)**:
  - `learn`/`practice`/`apprentice` — the commands `doc/help/skill`
    and `doc/help/combat` themselves document — exist ONLY as
    `cmds/std/learn.old` / `cmds/std/practice.old` (no live `.lpc`),
    and even `learn.old`'s own logic calls `ob->recognize_apprentice(me)`,
    a function that doesn't exist anywhere either — restoring the
    `.old` file as-is would introduce a NEW crash on first use, so
    this isn't a simple §7.94 rename-restore; left alone.
  - `study` (the other documented organic path, per `doc/help/skill`)
    IS a live, well-formed command — but the only object anywhere in
    the archive with a `"skill"` property for it to read is
    `obj/example/book.lpc`, an unplaced template file (grepped, zero
    references from any room/NPC). Nothing studyable actually exists
    in the reachable game world.
  - Of the 10 `daemon/class/*/` sects defined in code, exactly ONE
    (`fighter`) has ANY room (`guildhall.lpc`) placing its NPCs
    anywhere in the game world at all — grepped every other class
    directory name against the whole tree, zero references outside
    each class's own subdirectory. The other 9 sects' master NPCs are
    unreachable dead code regardless of any function-availability fix.
  - Even after fixing `exert_function`/`map_skill` (bug 4 above) so
    `fighter/guildhall.lpc`'s `champion` NPC spawns cleanly, the
    `master` NPC (蕭辟塵, the actual sect teacher and the one
    `do_join`'s `join` command would lead toward) still fails
    `create()` on `carry_object(__DIR__"icy_girth")->wear()`:
    `icy_girth.lpc`/`icy_cloth.lpc` `inherit WAIST;` / `inherit
    CLOTH;`, but no `WAIST`/`CLOTH` macro or `std/armor/{waist,cloth}.lpc`
    exists anywhere (only 15 slots are defined:
    belt/boots/cloak/coat/earring/gloves/head/l_armor/mask/neck/
    pants/ring/shield/u_armor/wrists). `BELT` and
    `COAT`/`U_ARMOR` are plausible substitutes by name, but which
    (if either) matches the author's actual intent is a design guess,
    not a mechanical fix — left undone. Auditing the other 9 classes
    via `update` (admin) turned up yet MORE independent missing
    functions in the same shape (`swordsman/master.lpc`:
    `perform_action` undefined; `taoist/taolord.lpc`: `cast_spell`
    undefined) — since none of those 9 classes are reachable anyway
    (no room places them), these were left unfixed as pure academic
    findings, not touched.
  - **Net result**: the organic sect-join path (`join` command itself,
    read and confirmed correct/self-contained in
    `std/room/class_guild.lpc`) could not be live-verified — the one
    room it would work from can't currently be entered due to the
    `WAIST`/`CLOTH` gap above. Documented as unverified-live, not
    silently presented as tested.

### Combat mechanism: read, gate live-verified; live damage exchange not reached (documented, not faked)

- Read `cmds/std/kill.lpc`, `cmds/std/attack.lpc`,
  `feature/attack.lpc` in full. **This lib has no `fight` command
  at all** (despite `doc/help/combat` explicitly documenting `fight`
  as the safe non-lethal alternative to `kill`) — grepped for
  `fight.lpc`/`surrender.lpc` and any `"fight"` add_action string,
  zero hits, and no `.old`/`.bak` backup copies exist either (unlike
  the learn/practice case, this one has no leftover draft to restore
  from — it appears to genuinely never have shipped in this frozen
  snapshot). So there is no `can_speak`-style safe/unsafe split to
  find here — `kill` is the ONLY combat-starting command, and by its
  own source it's unconditionally lethal against a non-player target
  (`if(!userp(obj)) obj->kill_ob(me);` — the target always retaliates
  with real `kill_ob()`, not the softer `fight_ob()`). PvP is the only
  case where `kill` isn't automatically mutual.
- The `no_fight` room flag IS live-verified working:
  `kill joan` (a harmless newbie-hall NPC) in the starting hall
  correctly returned `<神諭> 這裡不准戰鬥.` and did not start combat.
  Every room reachable from spawn within the newbie academy (checked
  all of `entrance`/`training_1_info`/`stairs_1`/`stairs_2`/`cafe`) is
  `no_fight`-flagged by design — a deliberate newbie safe-zone, not a
  bug. The other player-reachable transporter destination (`ceres`
  space station) has combat allowed but zero combat-capable NPCs
  (only unlivinng shuttle vehicles). The one guildhall with actual
  combat NPCs is the same one blocked above. Given no safely-reachable
  fight-capable target exists within a reasonable navigation/risk
  budget this pass, the actual damage-exchange path was verified by
  code read only, not live combat — documented explicitly as
  unverified-live per §10.7 point 6, not presented as tested.

### 发现但判定为既有设计、未改动的现象

- The archive's own in-game banner states development stopped
  ("即日起, 本 mud 停止研發") — this deep-test pass independently found
  concrete evidence backing that claim: `learn`/`practice` shipped as
  `.old` files, an unplaced example skill-book, 9 of 10 sects with no
  room placement anywhere, and 4 separate missing-function/missing-slot
  gaps blocking the one sect that IS reachable. All pre-existing,
  present in the very first commit for this lib, none introduced by
  this project's conversion — a frozen, genuinely-unfinished snapshot,
  consistent with the shipped banner.
- `kill`'s unconditional lethality against non-player targets (no
  in-lib safe-sparring alternative) is internally consistent with
  `doc/help/newbie`'s own warning ("在 FF 中別任意砍殺人類的 NPC") —
  the game clearly intends `kill` to be a real, risky choice; the
  missing `fight` command is a content gap (see above), not something
  papered over by a design decision elsewhere.

### WASM

Not re-verified under WASM this pass (native-only this session; this
project's WASM build path is permanently blocked). Confirm via:
`curl -sS "$HTTPS_PROXY/__agentproxy/status"` — emsdk's
`storage.googleapis.com` dependency is denied by the proxy, unchanged
from every other lib checked this session. The prior WASM pass
(2026-07, above) already covers WASM-specific gates (loopback
exemptions, admin seed) and found the lib fully playable there; the 5
fixes in this pass are driver-behavior-general (eval-cost ceiling,
missing-directory guard, `private`-visibility, two missing-function
stubs, a dead reconnect-location-restore call) and apply identically
under WASM once that build path is unblocked.

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.

Findings:

1. **AGENTS.md §7.108** (`obj/user.lpc`'s `reconnect()` missing
   `enable_commands()`): this lib has the kick-duplicate-login pattern
   (`adm/daemons/logind.lpc` calls `user->reconnect()` on the character
   body). Fixed by adding `enable_commands();` as the first statement.
   Live-verified with two concurrent telnet sessions: session 2 logged in
   as `fluffos`, confirmed the "趕出去, 取而代之嗎? (y/n)" prompt with
   `y`, and the resulting session correctly dispatched `look` (real room
   description) and `score` (real stat panel).
2. **AGENTS.md §7.10** (`adm/obj/master.lpc`'s `log_error()`): had no
   compile-severity filter at all — every message, including routine
   compile warnings, was unconditionally written to the admin's screen.
   Added the standard `strsrch(message, "arning:") == -1` guard.
3. **`adm/simul_efun/file.lpc`**: `cat()`'s `write(read_file(file))` had
   no null-guard; changed to `write(read_file(file) || "")`. `log_file()`
   already correctly called `assure_file()` first — no change needed
   there.
4. **Already correct, no change needed**: `cmds/wiz/update.lpc` (only
   `update.lpc` in this lib) already guards with `environment(me) &&`.
   No `adm/daemons/closed.lpc` exists, so AGENTS.md §7.107 does not
   apply. `maximum evaluation cost` was already `5000000`.

Live verification summary: booted the native driver on port 40099 (clean
boot, only pre-existing unused-variable/unknown-pragma warnings, no
fatals; `Initializations complete` / `Accepting telnet connections` both
printed). Logged in as the seeded `fluffos` admin (`Mud@2026`), confirmed
real write access via `update /adm/simul_efun/file` (recompiled
successfully). Ran the two-session kick-duplicate-login reconnect test
described above and confirmed the §7.108 fix live. No fatal errors in
the driver's console output. Killed the driver by exact PID when done.

本轮修改的文件 / Files modified this round:
- `libs/zzhj/work/obj/user.lpc`
- `libs/zzhj/work/adm/obj/master.lpc`
- `libs/zzhj/work/adm/simul_efun/file.lpc`

## §7.114 fix: `private input_line()` broke multi-line board post (2026-08-19)

`work/feature/edit.lpc` (this lib's `F_EDIT` mixin, inherited by
`std/char.lpc`) declared its `input_to()` re-arm target `private`:
`private void input_line(string line, string text, function callback)`.
Per AGENTS.md §7.114, this silently breaks the recursive `input_to()`
re-arm on every line after the first, since the function is reached
through the inherited mixin rather than defined directly on the player
object. Fix: dropped `private` (one-line change, `input_line` was never
player-typeable as a command anyway).

Live-verified on a fresh driver boot (port 40099), fresh character
(`秦柒壹肆`/`qinqiba`): `post <title>` → two body lines → `.` →
`留言完畢.` (success). `read 23` confirmed both `Body line one.` and
`Body line two.` were saved (not truncated after the first line, which
is the pre-fix symptom). Killed the driver by exact PID when done.

Files modified this pass:
- `libs/zzhj/work/feature/edit.lpc` — dropped `private` from
  `input_line()`.
