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
  this lib is confirmed byte-identical to `fy2qh` (same
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
  preload a network daemon, same as `fy2qh`). Full
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
after diagnosis). **Sibling lineage note**: `fy2qh` (confirmed
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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云再起Ⅱ 基础版。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
extensive round-one writeup above. All 9 round-one fixes confirmed still
present (code/data inspection for all 9, live re-exercise for the
highest-value ones — tell_room, the board/emote data fixes, and the
waterfog path fixes' zone was not re-walked but the underlying files were
grep-checked). Found and fixed two new standard-checklist gaps, plus one
genuinely new §7.90-class eval-cost crash not caught by round one.

### New fix: §7.90-class eval-cost abort during `make_body()` — 100% reproducible on this lib's configured budget

First admin login this pass hit a real, live `*Too long evaluation`
abort during `get_passwd()`/`make_body()` (`maximum evaluation cost :
300000`, the low end of this project's range). Fixed with the
established remedy: `config.fluffos` → `5000000`. Verified: fresh
reboot, first login attempt succeeded cleanly (previously failed),
zero eval-cost errors for the rest of the session.

### New fix: `adm/simul_efun/file.lpc` — same §7.11-class gap as sibling `fengyun434`

`log_file()` had no `assure_file()` guard, `cat()` had no null-guard.
Fixed both (with the forward declaration this driver requires).

### New fix: two active `printf("%O\n", ob)` debug leaks in `logind.lpc`

Byte-identical shape and location to `fengyun434`'s own finding earlier
this session (both name-confirmation branches, right before the password
prompt) — this lib shares that sibling's `logind.lpc` lineage closely.
Removed both.

### Re-verified live: the highest-value round-one fixes

- **§7.12 `tell_room()`**: code-confirmed `exclude || ({ })` present,
  then live-exercised throughout the whole session (room transitions,
  `smile`, board interactions) — the shared wrapper is called
  constantly by ordinary play, and zero argument-type errors occurred.
- **Board/emote GBK+CRLF data fixes (bugs 4/5/6/8)**: walked the exact
  original crash room (风云广场) — the board rendered as
  "风云广场留言版(Board) [ 13 张留言，13 张未读]", not the broken/unnamed
  state the pre-fix `capitalize()` crash would have produced on every
  subsequent `look` at that room. `smile` rendered its real Chinese
  flavor text ("你愉快地微笑着。"), confirming `emoted.o`'s dictionary is
  intact. `debug.log` line count unchanged across the whole navigation
  + emote + `update` session.
- **§7.25 `make_inventory()` catch guard**: code-confirmed
  `catch(ob = new(file)) || !objectp(ob)` present in `std/room.lpc`.
- **§7.28 `enable_player()` fix**: code-confirmed the
  `remove_action("command_hook", "")`-before-`add_action()` guard is
  present.
- **§7.24 death-code startroom stomp removal**: code-confirmed zero
  `set("startroom", ...)` matches remain in the three flagged death/limbo
  files.
- **§7.18 stale `/d/wiz/` path fixes**: code-confirmed all four
  call-site fixes present (only harmless historical header comments like
  `// Room: /d/wiz/hall1.c` still mention the old path, which is
  expected and inert).

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`).
`update /adm/daemons/logind` as the real privileged-action check
(succeeded). Two full rapid reconnects, both clean fresh logins (this
lib's `net_dead()` design never void-parks, matching `fengyun434`'s own
sibling architecture). Same test-harness pacing note as `fengyun434`:
this lib's id/password prompts need individually-paced sends, not a
batched `multi` burst. Driver killed by exact PID after each reboot (two
total: initial boot where the eval-cost crash was found, clean reboot
for verification); incidental `fluffos.o` save-timestamp churn reverted
before commit.

### Files modified this pass

- `config.fluffos` — §7.90 fix (`maximum evaluation cost` 300000 →
  5000000).
- `work/adm/simul_efun/file.lpc` — `log_file()` `assure_file()` guard
  (with forward declaration), `cat()` null-guard.
- `work/adm/daemons/logind.lpc` — removed two `printf("%O\n", ob)` debug
  leaks (both name-confirmation branches).

## §7.100 sweep fix (`ROOM` base-class redundant `replace_program()`)

`#define ROOM "/std/room"`: deleted 525 redundant, live, standalone
`replace_program(ROOM);` lines (kept `inherit ROOM;`) — 524 caught by
the scripted sweep, plus 1 hand-fixed instance in this lib's
room-building tool (`obj/roommaker.lpc`)'s "clone this room"
string-builder template. `work/data/` holds 85 real `.lpc` source
files (per-account starting-equipment templates named e.g.
`data/login/g/god/god896950960.lpc`), independently checked and
confirmed to contain zero occurrences of the bug pattern — not a real
gap in the sweep. 3 pre-existing `//`-commented instances remain
untouched, confirmed harmless. Verified via a clean `build-debug`
driver boot (0 new compile errors, port 40014 listening, zero new
"cannot replace"/"cannot bind" `debug.log` lines); no full §10.7
gameplay walkthrough this pass.

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

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py fy2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 236 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：225 -> 225 通过，无回退。启动时警告 23 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 4 -> 2。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮去掉 `obj/sbaa/` 六个物件多余的 `inherit F_CLEAN_UP`（NPC/ITEM 基类已带），手工清掉剩下两条，能编译的文件警告清零。改动的 8 个对象在 HEAD 与工作树各载入一次：HEAD PASS 5，tree PASS 6，regress 0。

- 药店 `u/cloud/drugstore.lpc` 的 `init()` 用 `in` 做局部变量名，而 `in` 是 FluffOS 的关键字（`foreach (x in y)`），整个文件编译失败，房间从没载入过；改名 `me` 后载入（药店人满时把新来的人请出去的逻辑才第一次生效）。
- `obj/sbaa/sbgod.lpc` 函数后多余的 `;` 删去。
- 未改：`obj/sbaa/sbgod.lpc`、`rong.lpc` 设了本库没有的武功（`snowshade-force` 等），`set_skill()` 报 `No such skill`，载入失败，HEAD 也一样，是内容缺口。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、5 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/fy/npc/obj/raincoat`、`/d/fy/npc/obj/sandals`、`/d/tianfeng/npc/obj/obj/robe`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/fs.h`、`include/net/ftpdsupp.h`、`obj/token.lpc`。`token` 是帮派领袖信物；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：1 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（2 个名字，最多的是 `wu-shun`、`snowshade-force`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 2 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 1 处、1 个文件：`taiji-force`→`taijiforce`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 6 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MUDLIB_UID`、`DOMAIN_UID`、`MAILDIR`、`TYPE_CAPE`、`TYPE_LEGGINGS`、`TYPE_PANTS`，用到它们的物件（名单里 5 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/d/fy/npc/mei_po.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/daemon/class/ronin/master.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

同一轮里 `/cmds/wiz/daemon.lpc` 也编译不了：它写 `DAEMON_D->query_daemons()`，而本库的 `include/globals.h` 没有 `DAEMON_D`（`Undefined variable 'DAEMON_D'`），`adm/daemons/daemond.lpc`（有 `query_daemons()`）却在。`globals.h` 在 `COMMAND_D` 之后补 `#define DAEMON_D "/adm/daemons/daemond"`（KB 04 §6.16），`daemon` 指令重新可用（列出已登记的 daemon，本库没有谁去登记，所以是空表）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 1 条注册（1 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/obj/npc/mianhua.lpc`（`do_vendor_list`）。最多的函数名：`do_vendor_list` 1 处。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 1 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 1 处（1 个文件）：拼名字的赋值 1 处。例：`name[0..1]` → `name[0..0]`（`/daemon/class/bonze/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
