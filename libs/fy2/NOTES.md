# fy2.rar → `fy2`

- Archive: `archives/fy2.rar` (2.8MB — "风云再起Ⅱ"/"Storm Rises Again
  II", 河海大学计算机及信息工程学院/Hohai University). Mudlib root at
  `fy/fy/`, config in the same directory (`config.FY2`). Same `fy4`-style
  master.lpc lineage as fengyun434/fy2005 (default-allow `valid_override`,
  no `load_object` in `valid_read`/`valid_write`).
- Port: **40014**.

## Status: DONE — boots clean, playable over telnet

Zero fixes needed to boot — clean on the first attempt. Full login flow
confirmed (name-length validation, re-prompt).

## What was fixed

Nothing needed for boot. Routine conversion: `.c`→`.lpc` refs auto-fixed,
9 local angle-bracket includes converted to quotes automatically,
`static`→`nosave` (39 files).

## Known remaining issues

- lpcc-sweep failures down to 43 (of 2839, was 73) after the §10.7 deep
  functional test pass — the remaining ones are genuine archive content
  gaps (undefined armor-property macros, missing `/adm/daemons/network/*`
  sockets-package daemons, orphaned wizard-workspace objects under
  `/u/cloud/`, a handful of NPCs referencing content this archive never
  shipped). Not triaged further; boot/login/gameplay path unaffected.
  See "深度功能测试" below for what WAS fixed this pass.
- Removed `data/emoted.lpc`, `data/emoted.o.old`, `data/emoted.o.new` —
  stale debris (predating this pass, from an earlier abandoned attempt
  at the `data/emoted.o` GBK-corruption fix documented below) that was
  never referenced by any `load_object`/`inherit`/`call_other` in the
  live tree but WAS picked up by `lpcc`'s blanket `*.lpc` sweep as a
  spurious `FAIL /data/emoted` (garbage save-data text parsed as if it
  were LPC source) — see AGENTS.md §4.2 item 8's "orphaned non-LPC file"
  guidance. Cost real time on this pass (a red herring while diagnosing
  the real `data/emoted.o` corruption below); removed so it doesn't cost
  a future pass the same time.

## How to run

```
cd libs/fy2
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40014 --timeout 10 --send "" --send "look" --send "quit"
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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 2839 `.lpc` files; 2837
  reformatted, 2 unchanged, **0 errors**.
- **Proactive fix applied before the first boot attempt of this pass**:
  this lib is confirmed byte-identical to `fengyun2qinghua` (same
  distribution, per that lib's own NOTES.md cross-check), which this
  pass found has a `cmds/usr/quit.lpc` bug: `message("system", ...,
  environment(me), me)` assumes `environment(me)` is always non-zero,
  and a mistimed `quit` (racing the post-registration RETURN prompt)
  can crash it, leaving the connection stuck repeating the same crash
  on every subsequent `quit`. Applied the identical `if
  (environment(me))` guard here proactively before booting, rather than
  waiting to rediscover it independently.
- **Native retest against rebuilt driver**: clean, zero fixes needed
  beyond the proactive one. Full registration + `look`/`score`/`quit`
  verified with a real Chinese name (王语嫣, female), zero debug.log
  errors.
- **WASM test**: boots and plays fully. No errors of any kind (not even
  the usual non-fatal sockets-package warnings — this lib doesn't
  preload a network daemon, same as `fengyun2qinghua`). Full
  registration with a real Chinese name (段誉), `look`, and `quit` all
  completed cleanly. Not affected by the documented `query_ip_number()`
  WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` `is_banned()`
  (~line 47) — short-circuit at top: non-string / empty / `127.0.0.1` /
  `localhost` / `127.`-prefix sites return 0. Called from
  `adm/daemons/logind.lpc:72-73` with both `query_ip_name()` and
  `query_ip_number()`; original regexp ban logic unchanged below.
- **Uptime gate**: none (no `uptime()` connection gate in logind).
- **Anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via a `fluffos (admin)` line appended to `/adm/etc/wizlist`
  (read by `adm/daemons/securityd.lpc` create()). Registered through the
  real flow; verified re-login + `update /adm/daemons/combatd` →
  "重新编译 ... 成功". Retest: fresh normal registration (秦风) into the
  world with working `look`/`score` (test char saves removed).
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/fy2/work/data/user/f/fluffos/fluffos.o`,
  `libs/fy2/work/data/login/f/fluffos/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-07-24/25, round two)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + WASM boot). Played as an ordinary
new player through registration, exploration, organic sect-joining and
skill-learning, combat, board reading, the emote system, shop purchase,
a real `quit` with a debug.log grep, prompt AND long-wait net-dead
disconnect/reconnect cycles, and a driver restart to confirm save
persistence. Native driver (`build-debug`) only — WASM not re-verified
this pass (all fixes are shared LPC/data-file changes with no
WASM-specific risk, but stated explicitly rather than silently skipped).

Test characters kept as playthrough evidence (native saves, untracked):
`qinfengz`/秦风 (male, 金钱帮 third-generation disciple under 荆无命,
`data/user/q/qinfengz/`), `duanyuu`/段誉 (male, used for board/emote
verification, `data/user/d/duanyuu/`), `muyi`/沐忆 (female, used for the
final full-flow regression, `data/user/m/muyi/`). All in the Han-ethnicity
start room 凤求凰客栈.

This lib turned out to share its lineage sibling `fengyun434`'s and
`zzfy`'s already-cataloged bug classes almost exactly (confirmed, not
just suspected), plus two bug classes new to this catalog.

### Bugs found and fixed

**1. `adm/simul_efun/message.lpc` — AGENTS.md §7.12, the shared
`tell_room()` 2-arg exclude bug.** Confirmed present (byte-identical to
the unfixed copy `fengyun434`'s own NOTES.md flagged as still-outstanding
in this lib's own family). Fixed proactively before booting:
`exclude || ({ })`. **This was not just theoretical** — `obj/user.lpc`'s
`user_dump()` (the `NET_DEAD_TIMEOUT`=900s force-quit handler, invoked
from a `call_out` with no enclosing `catch()`, exactly §7.12's escalation
shape) calls the 2-arg form on its very first line
(`tell_room(environment(), query("name") + "断线超过...", ...)`), so an
unfixed copy of this lib would have silently disabled the net-dead
force-quit safety net on literally every timeout, for the same reason
`dtsl` found live. Verified via `lpcc` (see below) and via exercising
`tell_room()`/`message_vision()` throughout the whole session (room
transitions, combat, board reads) with zero argument-type errors.

**2. `d/death/npc/bgargoyle.lpc`, `wgargoyle.lpc`, `d/death/inn1.lpc` —
AGENTS.md §7.24, death code stomping the permanent login-location
field.** All three death/limbo NPCs did
`ob->set("startroom", base_name(environment(ob)))` right after moving a
reincarnating/redeemed player to one of two waypoints
(`/d/fy/church`, `/u/guanwai/tower`) — **byte-identical to `zzfy`'s own
already-fixed instance of this exact bug**, down to the same two
waypoint paths and the same flavor-text message. Neither waypoint carries
the `valid_startroom` flag that `cmds/usr/save.lpc` (the only other
place that legitimately updates this field) requires. Fix: removed the
`set("startroom", ...)` line from all three files, matching `zzfy`'s
established fix — the `move()` already handles the immediate post-death
placement; future logins keep going to the player's real, previously
chosen home. Not exercised via an actual live death this pass (see "Not
verified live" below) but the code-shape match to `zzfy`'s
already-live-confirmed instance is exact.

**3. `std/room.lpc`'s `make_inventory()` — AGENTS.md §7.25, unguarded
`new()`/`move()` chain.** **Reproduced live via `lpcc`**: `/obj/sbaa/ym`
(a room) populates `/obj/sbaa/rong` (an NPC) via its `"objects"` mapping;
`rong.lpc`'s `create()` calls `set_skill("wu-shun", ...)`, a skill that
doesn't exist in this archive's skill tables, which throws
(`*F_SKILL: No such skill (wu-shun)`) from inside `new()` — uncaught,
this aborted the ENTIRE ROOM's load (`Fail to load object /obj/sbaa/ym`),
not just the one NPC. Fixed with the same `catch(ob = new(file))`
pattern `zzfy` already carries, plus an `objectp()` guard at the `reset()`
call site (case-1 branch) since `make_inventory()` can now legitimately
return 0. Re-verified via `lpcc`: `/obj/sbaa/ym` now PASSes.

### New bug class: unguarded `move()`/`restore()` in a board's `setup()` collateral-damages its owning room (AGENTS.md §7.7-adjacent, new instance)

`std/bboard.lpc`'s (and the parallel `std/jboard.lpc`'s) `setup()` did
`move(loc); ...; restore();` with neither call guarded. **Confirmed
live, two independent trigger mechanisms**:

- `data/board/fysquare_b.o` (the central-square 风云广场 message board —
  a room every new player walks through on their very first exploration)
  shipped as raw un-transcoded GBK bytes (`restore_object(): Invalid utf8
  string`) — a conversion-pipeline gap (§4.1), not a code bug by itself.
  Uncaught, this threw out of `restore()`, aborting the board's own
  `create()` **before** it reached `set_name()`/`set("long", ...)` —
  leaving the board permanently un-named for the rest of the boot, so
  EVERY subsequent `look` at the central square crashed a SECOND time
  (`*Bad argument 1 to capitalize()`, `feature/name.lpc:63`, `id` still
  unset) trying to display the broken board's short description. This
  is a first-boot-load, not first-visit, so unlike the §7.17/§7.19/§7.22
  family it does NOT self-heal after one visit — it keeps crashing every
  `look` at that room for the rest of the boot, since the underlying
  in-memory name/id state is genuinely never set, not just racily
  populated.
- `data/board/wizard_b.o`'s and `wizard_j.o`'s owning rooms
  (`d/waterfog/hall1.lpc`/`jobroom.lpc`) hit the identical collateral
  damage via the OTHER guardable call: their board's `"location"` field
  was a stale path (see bug class below), so `move()` threw
  `*call_other() couldn't find object`.

Fix: `catch()` around both the `move()` and `restore()` calls in both
`std/bboard.lpc` and `std/jboard.lpc`'s `setup()` — a bad board (missing
location, corrupt save data) now degrades to an unpopulated-but-present
board object instead of aborting the caller's `create()`.

**Data fix, and an important correction to how to fix this class**:
`data/board/fysquare_b.o` and `data/board/emoted.o` (see next section)
were the only two GBK-un-transcoded `.o` files in the whole lib (found by
scanning every `data/**/*.o` for invalid UTF-8) — both re-converted with
`iconv -f GB18030 -t UTF-8`. **First attempt at this was itself subtly
wrong and worth recording**: this driver's `save_svalue()` writes an
embedded real `\n` inside a saved string as a bare `\r` byte (NOT `\r\n`,
NOT an escaped `\n`) — see `src/vm/internal/base/object.cc`'s
`save_svalue()`/`restore_string()` — and `restore_object_from_buff()`
splits the WHOLE file strictly on literal `\n` bytes with **no
bracket-balance continuation logic**, so a genuine `\r\n` pair anywhere
in the body (this archive's `.o` files carry real Windows-style CRLF
line endings pre-dating this project, most plausibly from the original
Windows-hosted server or a Windows-based archival step) desyncs the
whole file's variable-boundary parsing. A first-pass fix that blindly
collapsed every `\r\n` → `\r` broke `data/emoted.o` in a NEW way (see
below) by merging the genuine top-level line boundary between its
`dbase (...)` and `emote (...)` variables into one un-parseable
statement. **The correct fix needs a quote-aware scan**: walk the
decoded text tracking whether the cursor is inside an (unescaped) `"`
string literal, and only collapse `\r\n` → `\r` when inside one — every
`\r\n` OUTSIDE a string literal is a genuine top-level statement
separator and must stay a real `\n`. Re-derived both `data/board/
fysquare_b.o` and `data/board/poem_b.o` (see below) from the pristine
`git show HEAD:...` bytes with this scanner; this restored ALL of
`poem_b`'s real 1998-era board posts, including a garbled multi-`\r`
control-sequence-spam post from a player named "杰" that an earlier,
cruder attempt at this fix had manually "cleaned" into one line — the
quote-aware fix preserves it verbatim as the real archived multi-line
content instead.

### New bug class: `data/board/poem_b.o`'s own save format was independently malformed (not the same as the class above)

Distinct from the GBK/CRLF issue above: `poem_b.o` (the "探花诗台"
poem board, `/d/fy/poemp`) was **already valid UTF-8** but still threw
`restore_object(): Illegal file format - 1 (...)` — a DIFFERENT parse
failure, traced to the exact same root mechanism described above (a
genuine embedded `\r\n` from Windows-style archival splitting the
`"notes"` mapping literal mid-value). Same fix (quote-aware `\r\n`→`\r`
collapse from pristine bytes) resolved it; see the shared writeup above.

### New bug class: stale `/d/wiz/` paths from a zone rename to `/d/waterfog/` (AGENTS.md §7.18, new instance)

`d/waterfog/hall1.lpc`, `d/waterfog/jobroom.lpc` (both carry
`// Room: /d/wiz/....c` header comments — the tell), and their two
message boards `obj/board/wizard_b.lpc`/`wizard_j.lpc`, all hardcoded
absolute exits/`"location"` values under the old `/d/wiz/` path, even
though the zone's own `d/waterfog/entrance.lpc` (which DOES exist,
alongside the rest of this small wizard-lounge zone) already correctly
uses `__DIR__`-relative exits for the same neighbors — the inconsistency
is the tell, exactly per §7.18's detection guidance. A FOURTH live
instance of the same stale path: `feature/alias.lpc`'s anti-bot
"you look like a script" auto-teleport (`repeat_cnt > MAX_REPEAT`, a
genuinely reachable safety mechanism, not dead code) sent the accused
player to `load_object("/d/wiz/courthouse")` — also nonexistent, would
have silently `move()`d the player into environment 0 (§7.14's "no
environment" shape) had it ever fired. Fixed all four to point at
`/d/waterfog/...` (or `__DIR__`); added an `objectp()` guard on the
alias.lpc teleport as defense-in-depth. Re-verified via `lpcc`: all
affected files now PASS. **Left alone, a genuine archive gap**:
`d/waterfog/entrance.lpc`'s own `"north"` exit points at
`/d/wizard/bigroom.lpc` (note: `wizard`, a THIRD spelling, not `wiz` or
`waterfog`) — this file doesn't exist anywhere in the archive; documented
here rather than fabricated per §7.14/AGENTS's missing-content policy.

### New bug class: `adm/daemons/emoted.lpc`'s shipped emote database was un-transcoded GBK, silently disabling the entire emote-command system

`data/emoted.o` (~72KB, the ENTIRE `smile`/`nod`/`bow`/`wave`/... emote
pattern database, hundreds of entries) was raw GBK, same class as
`fysquare_b.o` above. `emoted.lpc`'s `create()` did
`if (!restore() && !mapp(emote)) emote = ([]);` — restore() threw
uncaught, aborting create() before even the `set("channel_id", ...)`
fallback line, so this wasn't just "corrupt data ignored", it was
**every single emote command silently unrecognized** (`smile` etc. all
printed the generic "什麽？" unknown-command message) — reproduced live
before the fix, confirmed fixed after (`smile`/`nod` both render
correctly with their real Chinese flavor text). Same
data-fix-plus-defensive-`catch()` treatment as the board class above;
see that section for the quote-aware `\r\n` scanner this data file also
needed (the first, cruder attempt silently produced an EMPTY `emote`
mapping — `mapp()`-true but `sizeof()==0` — because it merged the real
top-level line boundary between this file's `dbase (...)` and
`emote (...)` variables; confirmed via temporary
`efun::write_file()`/`keys(emote)` instrumentation in `create()`, removed
after diagnosis). **Sibling lineage note**: `fengyun2qinghua` (confirmed
elsewhere to be byte-identical to this archive) carries the exact same
corrupted `data/emoted.o` — `fysquare_b.o`/`poem_b.o` were NOT checked
there but are plausible candidates too, given the identical distribution;
worth a follow-up pass on that lib specifically for this class rather
than re-discovering it from scratch.

### Bug found and fixed: `feature/command.lpc`'s `enable_player()` — AGENTS.md §7.28, redundant `add_action` stacking

`enable_player()` (the shared `command_hook` dispatcher registration)
did a bare `add_action("command_hook", "", 1)` with no idempotency
guard. `feature/damage.lpc`'s `revive()` — scheduled via a plain
`call_out` **every time a character is knocked unconscious in ordinary
combat**, not just death, so this is a very common repeat-trigger, not
an edge case — legitimately re-calls `enable_player()` while already
`living()`. Per §7.28's own documented caution, a `living()`-gated guard
would be WRONG here (this lib doesn't have the exact `mhxy`-style
sleep/wake shape, but `revive()`'s legitimate re-enable is the same
class of false positive) — used the correct, call-count-independent fix:
`remove_action("command_hook", "")` immediately before the
`add_action()` call. Not reproduced live via an actual knockout+revive
cycle this pass (see "Not verified live" below), but the fix is
structurally inert for the normal case and was exercised indirectly many
times over (every login, movement, apprentice/learn/combat/emote command
in this whole session calls through `command_hook`, all continued
working normally after the fix).

### What was tested and confirmed working

- **Registration**: real Chinese names, both genders (秦风 male, 沐忆
  female), full flow (encoding choice → id → confirm → Chinese name →
  password → confirm → email → gender → ethnicity), landing in the
  Han-ethnicity start room (凤求凰客栈) per `doc/help/newbie`'s own
  documented room list.
- **Movement/exploration**: walked the route from 凤求凰客栈 through
  南风大街/风云广场/北风大街 and separately through 金钱帮总舵
  (帮主堂/黄衣室/会客厅/金钱帮大院) to 帮主堂; separately confirmed the
  探花诗台 (poem board zone, west of the square) and the previously-broken
  巫师交谊厅/工作进度简报室 (`d/waterfog/`) reachable and error-free
  after the path fixes.
- **`score`/`hp`/`i`**: correct at every stage (fresh, post-sect-join,
  post-skill-learn-attempt), matching `doc/help/newbie`'s documented
  format.
- **Sect-join mechanism**: `apprentice master jin` on 荆无命
  (`d/fy/npc/jinwuming.lpc`, a genuine 金钱帮 第二代护法 recruiting
  master at `d/fy/jbang.lpc`, `valid_startroom`-flagged) completed
  immediately on both test characters — `score` afterward correctly
  showed "金钱帮第三代弟子" title and "你的师父是荆无命。".
- **Organic skill-learning**: `skills master jin` correctly listed his
  10 skills (sword/dodge/force/parry/... — no `unarmed`, matching
  `doc/help/newbie`'s own documented caveat "如果你师父并不全会以上技能，
  你也只能委屈一下了"); `learn sword from master jin with N` correctly
  consumed 精力/潜能 either way (one attempt succeeded, one rolled "你今天
  太累了，结果什麽也没有学到" — RNG-gated, not a bug).
- **Combat**: no dedicated stat-mirroring training dummy reachable from
  the starting zone (`obj/muren.lpc` exists but is placed only in the
  `d/snow/` — 雪山派-adjacent — zone, per `d/snow/guestroom.lpc`, not
  reachable from the Han start area). Followed the checklist's
  documented fallback: `doc/help/newbie`'s own graduated safe-target list
  ("无知小童，教书先生，...，农夫") points at weak roadside NPCs;
  fought 登徒子 (`d/fy/npc/dtz.lpc`, unarmed/parry/dodge 20, "heroism"
  attitude) at 北风大街 — engaged correctly, exchanged rounds, took
  moderate but non-critical damage (250→~134/250 HP), disengaged safely
  by leaving the room. No dedicated stat-mirroring dummy found within the
  reachable zone, but combat mechanics themselves (attack resolution,
  damage, HP recovery on disengagement) all functioned correctly.
- **Board system**: `read`/list-with-count all correct after the fixes —
  风云广场留言版 (13 messages) and 探花诗台 (4 messages, including the
  garbled 1998-era control-sequence-spam post, now rendered as its real
  multi-line paginated content).
- **Emote system**: `smile`/`nod` both render correct flavor text after
  the fix (verified broken-then-fixed, both states reproduced live).
- **Shop purchase**: `list` at 凤求凰客栈's 店小二 correctly showed the
  price table; `buy dumpling from waiter` correctly refused with
  "你的钱不够" (a brand-new character starts with 0 money) — **not
  completed live**, same as `fengyun434`'s own finding; reaching real
  starting capital was outside this pass's time budget.
- **`quit` + debug.log grep**: clean on every explicit `quit` this
  session (multiple), zero `error:`/`Too deep recursion`/`Bad
  argument`/`couldn't find object`/`Illegal file format` lines beyond
  routine compiler warnings.
- **Net-dead / reconnect (prompt)**: disconnect without `quit`,
  reconnect within seconds — lands back in the same room with
  "重新连线完毕。", no void-parking. `obj/user.lpc`'s design (same as
  `fengyun434`'s) never moves a disconnected player to a temporary void
  room at all, structurally immune to §7.20's class by construction —
  confirmed by reading `net_dead()`/`reconnect()` in full, not just
  inferred from behavior.
- **State persistence across a real driver restart**: killed and
  rebooted the native driver several times over this pass (once per
  batch of code fixes); each time, reconnecting as `qinfengz` correctly
  restored location, sect membership, and stats from disk.
- **Net-dead → automatic force-quit after the real timeout**: **budget
  note, not a silent skip** — a genuine full 900s (`NET_DEAD_TIMEOUT`)
  real-wall-clock wait was completed once; that specific occurrence
  left the character stuck net-dead indefinitely (still shown
  `<断线中>` in its room via `who`/room-listing 20+ minutes later, with
  ZERO trace in `debug.log`, `user_dump`'s own `USAGE` "quits" line
  never written). This was **not reproduced** on two follow-up attempts
  using a temporarily-shortened timeout (12s) plus targeted
  `efun::write_file()` instrumentation in `net_dead()`/`user_dump()`
  (removed after diagnosis, see git history/diff for the exact revert) —
  both follow-ups completed the SAME code path cleanly end-to-end
  (`net_dead()` → `user_dump()` → `command("quit")` → real `destruct()`
  → `USAGE` "quits" line written), on both a fresh throwaway character
  and `qinfengz` itself. The one failure coincided with a large
  concurrent `lpcc --batch` full-tree sweep (~22 real seconds of heavy
  compilation) running in a separate process against the SAME work
  tree while the live driver's call_out was due to fire — a plausible
  but unproven confound. **Honestly flagged as an unresolved, likely
  environmental/non-reproducible anomaly, not a diagnosed-and-fixed
  mudlib bug** — logged here per AGENTS.md's standing instruction to
  document rather than guess when genuinely unsure, and per §10.8's own
  precedent for exactly this shape of rare, hard-to-reproduce finding.
  If this recurs on a future pass (this lib or a sibling), the
  instrumentation pattern used here (`efun::write_file("/log/...", ...)`
  — note it must be under `/log/`, the only unconditionally-write-allowed
  path for a non-root euid per `securityd.lpc`'s `valid_write()` — at
  each step of `net_dead()`/`user_dump()`) is a fast, cheap way to
  pinpoint exactly where execution stops.

### Not verified live, and why

- **Death/reincarnation flow** (bug #2 above): the fix's correctness was
  established by exact code-shape match to `zzfy`'s own already-verified
  fix (same two waypoint paths, same message, same missing
  `valid_startroom` flag on both), not by walking a character through an
  actual death this pass — reaching a real death safely within budget
  after the extensive board/emote/path debugging above wasn't feasible.
- **`enable_player()` double-stacking** (§7.28 fix): not reproduced via
  an actual knockout+`revive()` cycle; verified only that the fix doesn't
  break the many ordinary `command_hook` dispatches already exercised
  this session.
- **WASM**: not re-tested this pass (native-only); all fixes are shared
  LPC/data-file changes with no WASM-specific risk identified.
- **The stuck-net-dead anomaly**: see above — actively investigated,
  not fixed, explicitly flagged as unresolved rather than presented as
  diagnosed.
