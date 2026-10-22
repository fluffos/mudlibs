# xkxz2 — 侠客新传 (New Legend of the Wandering Swordsman)

Archive: `侠客新传(2).rar`. Port: 40035. Status: **done** (boots clean
and quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"「侠客新传」" v0.1b, credited to "Xkxz MUD Wizard Group",
http://xkmud.yeah.net. `config.cfg`'s leftover `MUD_NAME` field still
says "海洋II上海总站" ("Ocean II Shanghai Main Station"), suggesting
this was forked from a 海洋II codebase base and rebranded — but the
actual game per its own connection banner and `游戏说明.TXT` readme is
"侠客新传". Same "Century-family" `adm/single/{master,simul_efun}`
layout as `shiji`/`zhonghua2`/`shujian2008`/`sjpl2`/
`xjcq2000`. ~7,613 raw files, 6,903 after `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h**: `is_chinese()`'s two-specific-byte GBK check →
   single-character CJK codepoint check. `check_legal_name(string name,
   int maxlen)`'s internal bound `strlen(name) < 2` → `< 1`, and the
   call-site `maxlen` argument (`check_legal_name(arg, 8)`) halved to
   `4`. Note: `is_chinese(name)` here is called on the WHOLE name string
   directly, not per-character in a loop — since `is_chinese` itself
   only ever examines the first character, this means even the
   ORIGINAL GBK-byte-era code only ever validated the first character
   of a multi-character name (a pre-existing permissiveness quirk, not
   something introduced or fixed here beyond making `is_chinese` itself
   correct under UTF-8).
2. **Deep `named.lpc` fix**, same nitan-family shape as `zhonghua2`/
   `shujian2008`: `PATH(name)` macro `name[0..1]` → `name[0..0]`, five
   `strlen(name) < 2` guards → `< 1`, `invalid_new_name()`'s combined
   check `strlen(name) < 4` → `< 2`, sliding-window similar-name
   detection `name[i..i+3]`/`name[i..i+5]` → `name[i..i+1]`/
   `name[i..i+2]` with adjusted loop bounds (`i <= l - 4` → `i <= l -
   2`, `i + 6 <= l` → `i + 3 <= l`).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively **before the first boot
   attempt**. Booted clean in under 15 seconds, zero compile errors, no
   hang — the policy continues to work as intended.

## Testing gotcha (not a mudlib bug — a scripting trap for future retests)

This lib's connection has an **"Are you using BIG5 font [Y|N]?" prompt
right at the very start**, before the main banner even renders — visually
it blends straight into the connection output with no obvious blank
line or distinct prompt marker, making it very easy to miss when
scripting a `mudclient.py` test. The first `--send` answers THIS prompt,
not the English id. Missing this caused several confusing cascading
"必须是3到8个英文字母"/"只能用英文字母" rejections in early testing
(each subsequent `--send` value was shifted one slot into the id/
password fields, none of which matched their respective validation
rules) before the actual cause was traced. **Lesson reinforced**: when a
registration test produces confusing cascading rejections, first
re-verify with ONE input at a time and read the FULL transcript
carefully for any prompt that might have been missed, before suspecting
the fix logic itself is wrong.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:
BIG5 answer `n` → id `xkxzd` → confirm `y` → password `Pass1234` (twice)
→ **real Chinese name `秦风`** (avoiding "中神通" — a real Jin Yong
character found in this lib's `banned_name` list) → accepted, proceeds
into character-archetype selection (猛士/智慧/耐力/敏捷/均衡 type
prompt).

## lpcc sweep

6,903 files, 6,715 pass / 188 fail (97.3%). Failure tail is the usual
shape (a `set_information` type-mismatch cluster, several `nomask`
function redefinition conflicts, missing `skillN`/`set_ghost` globals)
— not triaged individually per AGENTS.md §6b/§13. Memory stayed healthy
throughout (~13GB free).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 6903 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 6814 written, 32 already
  idempotent-clean, 57 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the §15ae
  fix (`feature/command.lpc`'s `command_hook` staying `nomask` with
  `private` commented out) and the §15t include-path fixes survived the
  reformat unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxzreu`), through the BIG5-prompt gotcha documented above
  (still present and still easy to miss — re-confirmed by scripting one
  input at a time), landing in the actual starting room (`世外桃源`),
  `look`/`score`/`quit` all producing correct output (`score` before
  the archetype's "birth" step correctly replies "还没有出生呐，察看
  什么？", matching this lib's own game-design flow, not an error). No
  regressions from either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too, byte-for-byte matching the native transcript — BIG5
  prompt → id `xkxzwas` → password → real Chinese name `秦岭` →
  archetype/gender → landed in the same `世外桃源` starting room,
  `look`/`score`/`quit` all produced correct output. This lib has **no
  IP-format-dependent login gate**, so it isn't affected by the known
  `query_ip_number()` WASM limitation — fully playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib's `adm/daemons/band.lpc` is byte-identical (per §2.1 lineage
check) to the `xiakexing3`/`xiakexing2017`/`jqxz2008`
family's, whose WASM pass was already done and verified with the
correct fail-closed convention — ported that fix here and re-verified
independently.

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc:106`'s `BAN_D->is_banned(query_ip_number(ob))`
  gate in `gb_big5()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lib (checked the full `logind.lpc` input_to
  chain). Nothing else to exempt.

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (BIG5 prompt `n` → id → `y` → password ×2 (mixed-case) →
Chinese name → archetype `5`/均衡型 → gender `m`). Granted `(admin)` by
appending `fluffos (admin)` to `adm/etc/wizlist` (shipped with `hxsd
(admin)`/`jjgod (admin)` already present; `securityd.lpc` reads this
file at `create()`, so a driver restart was needed to pick up the new
line). Verified after restart: `您目前的权限是：(admin)`, `update
/adm/daemons/band` → `重新编译 /adm/daemons/band.lpc ...成功！`.
The account was NOT taken through this lib's separate `register
<email>` → `decide` mini-flow (the one that unlocks stat-rolling/
"being born"), since that's character-creation content orthogonal to
wizard status — `score` on this account still replies "还没有出生呐"
same as any other unregistered character, which is expected and
harmless; wizard permission is independent of it and was verified
working regardless.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xkxz2/work/data/user/f/fluffos.o`
- `libs/xkxz2/work/data/login/f/fluffos.o`

Pre-existing bug found (NOT fixed, out of scope for this pass — a
content/daemon bug, not a login gate): `adm/daemons/eventd.lpc`'s
`create()` builds each scheduled-event's object name from its filename
via `map_array(event_name, (: $1[0..<3] :))`, a `.c`→`.lpc` rename
leftover (§4.2-class bug) — the slice strips only 3 trailing characters
where 4 are now needed to remove the longer `.lpc` extension, so
`"emei.lpc"` becomes `"emei.l"` instead of `"emei"`. The resulting
`call_other(EVENT_DIR + "emei.l", "create_event")` throws `couldn't
find object`, caught non-fatally by `master.lpc`'s `preload()`, but
since the throw is uncaught INSIDE `collect_all_event()`'s own
`foreach` loop, it aborts that loop after the first entry — so this
lib's whole scheduled-event system (3 files: `emei`/`huanggs`/
`qiantang`) silently never initializes any of its timed world events.
Boot itself is unaffected (caught at the master level) and this has no
effect on login/registration/admin, which is why it's left for a future
content pass rather than fixed here; the one-line fix would be
`$1[0..<3]` → `$1[0..<4]`.

Retest: fresh boot, fresh registration (BIG5 `n` → id `qretest`, real
Chinese name 秦风十二, archetype 均衡型) through `look`/`score`/`quit` —
landed in 世外桃源, `look` correct, `score` correctly replied "还没有
出生呐" (pre-birth, matches documented game design), clean quit.
`fluffos`/`Mud@2026` admin login verified: `look` then `update
/adm/daemons/band` → `重新编译 ...成功！`, then clean `quit`.
`debug.log` had exactly the one pre-existing `eventd`/`emei.l` boot-time
error above (caught, non-fatal) and zero NEW runtime errors. Test
character `qretest` removed afterward; fluffos kept.

## Long-sit boot-watch pass (2026-07-24) — fixed two pre-existing
   boot-time compile bugs surfaced by a real 200s sit

`scripts/wasm_boot_watch.sh xkxz2 200` (>3 minutes, not the
usual 20-30s smoke test) surfaced two REAL compile-time bugs during
preload that a quick smoke test never exercises (both were already
partially known from the lpcc sweep/prior NOTES, but neither had
actually been fixed):

1. **`inherit/misc/quest.lpc`'s `set_information(string key, string
   info)` wrapper had the wrong parameter type** — every quest NPC's
   `register_information()` (`clone/quest/{shen,deliver,search,judge,
   supply}.lpc`, 5 files) calls it as
   `set_information(NPC_NAME, (: ask_npc :))`, passing a CLOSURE as
   `info`, but the wrapper declared it `string`. `QUEST_D->set_information()`
   itself (the function this wrapper forwards to,
   `adm/daemons/questd.lpc:16/918`) already declares this same argument
   `mixed` — the wrapper's `string` was simply a mistyped declaration,
   not an intentional restriction. This was previously bucketed as part
   of the lpcc sweep's generic "`set_information` type-mismatch cluster"
   and never individually fixed; the long-sit boot-watch showed it's
   not just a static lpcc artifact — it genuinely kills all 5 quest
   objects' compiles at boot (`*No program in object '/clone/quest/
   {shen,deliver,search,judge,supply}'!`, caught non-fatally by
   `master.lpc`'s `preload()`, but leaving the whole quest-NPC set
   broken). **Fixed**: widened the wrapper's `info` parameter to
   `mixed` to match `QUEST_D`'s own declaration and actual call-site
   usage.
2. **`adm/daemons/eventd.lpc`'s `.c`→`.lpc`-rename slice bug — actually
   fixed this time** (previously found and explicitly left unfixed as
   "out of scope" in an earlier pass, see above): `map_array(event_name,
   (: $1[0..<3] :))` turns `"emei.lpc"` into `"emei.l"` instead of
   `"emei"`. The earlier NOTES entry suggested `[0..<3]` → `[0..<4]` as
   the one-line fix, but that's actually still wrong — **verified
   empirically via two live retests**: `<3` produces `"emei.l"`, `<4`
   produces `"emei."` (with the trailing dot!), and only `<5` produces
   the correct `"emei"`. FluffOS's `str[a..<N]` strips the last `(N-1)`
   characters, so removing the 4-character `".lpc"` extension needs
   `N=5`, not `N=4` — the previously-suggested fix would have been a
   NEW bug (`"emei."`) had it been applied without retesting.
   **Fixed**: `$1[0..<3]` → `$1[0..<5]`. This restored the whole
   scheduled-event system (`emei`/`huanggs`/`qiantang`, all 3 now
   compile and load during `eventd`'s `create()`, confirmed via
   transcript).

**Retest**: re-ran `wasm_boot_watch.sh xkxz2 200` (full
200s) after each fix — the `set_information`/`No program in object
'/clone/quest/...'` errors and the `emei.l`/`couldn't find object`
error are both GONE from the transcript; `event/huanggs.lpc` and
`event/qiantang.lpc` now show up compiling cleanly during `eventd`'s
preload. Remaining transcript content is only the already-documented
`ftpd`/no-sockets-under-WASM class (§1.3c, caught, non-fatal) and
ordinary compile warnings. Native sanity check: fresh driver boot
(clean, zero errors beyond the standard `nosave crash()` cosmetic
warning), full registration flow (BIG5 `n` → id `wasmck` → password ×2
→ Chinese name `秦风测` → archetype `5`/均衡型 → gender `m`) landed in
世外桃源, `look`/`score`(`还没有出生呐`, correct pre-birth reply)/`quit`
all correct, `debug.log` clean. Test save files removed afterward (not
committed).

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib (every prior pass verified
only registration + `look`/`score`/`quit` + boot/admin checks, never a
continuous session past the born step). Read `doc/help/newbie` and
`doc/help/intro` in full first — they named the starting-money NPC
(城隍庙老和尚), the `fight`(较量)/`hit`/`kill` combat-risk ladder, the
`apprentice`(bai)/`skills`(cha)/`learn`(xue) teaching loop, and the fact
that only 武当派 is currently open, matching this lib's own README. One
continuous playthrough (with brief admin-assisted side trips, see below)
on the native driver (`build-debug`), covering registration → the
lib's own two-step "register email + decide + wash + born" character-
creation flow (not just the basic id/password registration) → starting
room → the ONLY viable way to reach the open sect (a paid NPC-guide
travel system — there is no walkable road out of Yangzhou to Wudang) →
sect-join → organic skill-learning → a safe-sparring attempt → a real
fight against a friendly NPC → a shop purchase → a clean `quit` →
multiple net-dead disconnect/reconnect cycles (prompt and, unusually,
an *involuntary* one caused by an unrelated driver-fatal crash, see
below) → relogin after real wall-clock gaps, confirming full state
persistence throughout. Found and fixed **four** bugs (three genuinely
new for this project's catalog, one an already-cataloged class), plus
one live-witnessed **third occurrence** of the still-unpinned §10.8
driver-fatal soak-testing crash class, plus one honestly-documented
content ambiguity left untouched per this pass's explicit
programming-bugs-only scope.

**Test character** (kept, representative playthrough evidence): id
`qingyunk`, real Chinese name 青云客 (male, 均衡型/balanced archetype),
password `Kx2026Test`. State at rest: registered, born 扬州人氏
(character trait 光明磊落), 武当派第四代弟子 (4th-generation Wudang
disciple, master 谷虚道长/Guxu Daozhang), `force` (基本内功) skill at
level 1 from an organic lesson, carrying 皮靴/明黄锦袍 plus 70 copper
cash change left over from a real shop purchase, located at 醉仙楼
(the room of its last clean `quit`). Saves: `work/data/user/q/qingyunk.o`,
`work/data/login/q/qingyunk.o` (both untracked, for the orchestrator to
force-add per this file's existing convention). The pre-existing
`fluffos`/`Mud@2026` admin account (§ above) was reused, read-only in
spirit, purely as a testing aid — see "Admin-assisted testing" below;
its own registration/birth status was intentionally left untouched, as
in the prior pass.

### Bug 1: `feature/action.lpc`'s `eval_function()` was `private`, silently no-oping delayed status effects for 130+ skill/item files — matches AGENTS.md §8.3a's addendum, not a new class

`feature/action.lpc:111` declared `private void eval_function(function
fun) { evaluate(fun); }`, invoked purely by name from a driver-origin
`call_out()` scheduled in the same file's `start_call_out()`
(`call_out("eval_function", delay, fun)`). Once `feature/action.lpc` is
`inherit`ed into the player-body base class, `private` demotes to
`DECL_HIDDEN` on this driver, and the `call_out`-triggered dispatch
(`origin: internal`) is silently refused — logged as `apply() with
insufficient permission: ... needs: private, has: hidden`, reproduced
live the very first time any kungfu-skill/drug file's delayed-effect
`call_out` actually fired (observed against `clone/user/user#1`).
`start_call_out()` is this lib's own shared "temporary condition
recovery" primitive, called from 59 different `kungfu/skill/*` and
`kungfu/special/*` files (buffs, poison/damage-over-time, timed
powerups, shields) — exactly the shape AGENTS.md §8.3a's addendum
describes (found originally on `xuanjianlu`). **Fixed**: dropped
`private`, matching the addendum's prescribed fix.

```lpc
// BEFORE: private void eval_function(function fun) { evaluate(fun); }
// AFTER:          void eval_function(function fun) { evaluate(fun); }
```

### Bug 2 (NEW bug class): `enter_world()` unconditionally overwrites a just-restored player's "registered" flag with a permanently-stale value from the per-connection login object, silently un-registering every returning player and rerouting them back into the newbie registration room on their NEXT full login

**File: `adm/daemons/logind.lpc:513`** (inside `enter_world()`, the
function every full/fresh login runs through — NOT `reconnect()`, which
is unaffected).

Root cause: this lib's "registered" flag (whether the player completed
`register <email>` + `decide` with 水笙) is written durably in exactly
ONE place — `d/register/npc/shuisheng.lpc`'s `do_decide()`, which calls
`me->set("registered", 1)` on `this_player()`, i.e. the persistent
player-body object (`user`), then saves it. But `enter_world()` — run
on every subsequent full login, called with BOTH the persistent `user`
object AND a brand-new, per-connection `ob` (`/clone/user/login.lpc`,
one freshly `new()`'d object per connection attempt, per
`adm/single/master.lpc`'s `connect()`) — did:

```lpc
// BEFORE:
user->set("registered", ob->query("registered"));
```

`ob`'s own "registered" field is initialized to `0` exactly once, at
new-character-creation time (`logind.lpc:441-442`, both `ob` and `user`
set to `0` together), and is NEVER independently updated anywhere except
`cmds/usr/quit.lpc`'s explicit sync-back
(`link_ob->set("registered", me->query("registered")); link_ob->save();`)
— which only runs on a **clean** `quit`. Since `ob` is a fresh object
every connection, its own "registered" field is restored from its own
tiny save file (`data/login/<c>/<id>.o`) at connect time — permanently
`0` for any player whose FIRST post-registration session ever ended via
anything other than a clean `quit` (a network drop, a driver
restart/crash, a client crash — the single most common real-world
disconnect shape). The very next full login blindly overwrote the
just-restored, correctly-`1` `user->query("registered")` back down to
`0` — which, combined with `enter_world()`'s own routing logic three
lines below
(`if (!user->query("registered") || ...) user->set("startroom",
REGISTER_ROOM);`), silently sent an already-registered, already-`born`
player back into the newbie registration room (世外桃源) on every
future login, where 水笙's own defensive greeting logic (correctly,
separately) then punts a non-wizard "already born" character it finds
there into `虚空`/limbo (`VOID_OB`, via `d/register/npc/shuisheng.lpc`'s
`greeting()`) — an inconvenient but recoverable loop (虚空 has a `down`
exit to a real room), not a permanent stranding, but a real,
100%-reproducible regression on the flag itself and, contingently
(since it happens inside `enter_world()`'s `!silent` routing block,
which is what actually persists `startroom`), can permanently corrupt
the SAVED `startroom` field too if the player quits before manually
walking back out of the register room — exactly what happened to this
pass's own `qingyunk` test character before the fix (repaired by hand
afterward, see "Testing/repair notes" below).

**Reproduced live in this exact shape**: registered+born character,
first session ended by an abrupt disconnect (no `quit`) → next full
login landed back in 世外桃源 with `score` showing "还没有出生呐"-style
symptoms again and 水笙 greeting with "你还没有注册，快注册吧" — despite
`data/user/q/qingyunk.o` on disk still correctly showing
`"registered":1` at that exact moment (proving the corruption happens
in-flight during `enter_world()`, not from a bad save).

**Fix** — treat "registered" as a monotonic flag (true on either side
wins, and re-sync both sides), rather than a one-way copy FROM the
stale per-connection object:

```lpc
// AFTER:
// "registered" is set permanently on `user` by
// /d/register/npc/shuisheng.lpc's do_decide() (this_player() there is
// always `user`, never the per-connection `ob`), but `ob` is a brand
// new /clone/user/user/login object every connection whose own
// "registered" field is only ever initialized to 0 (see the new-
// character-creation path above). Blindly overwriting `user`'s
// already-restored, correctly-persisted "registered" with `ob`'s
// permanently-stale 0 silently un-registers every returning player on
// every single fresh login (not net-dead reconnect, which doesn't call
// this function), re-triggering the "还没有注册" flow and rerouting
// them to REGISTER_ROOM instead of their real startroom. Treat it as a
// monotonic flag: true on either object wins, and keep both in sync.
if (ob->query("registered") || user->query("registered")) {
  ob->set("registered", 1);
  user->set("registered", 1);
} else {
  user->set("registered", 0);
}
```

Re-verified live end-to-end: fresh driver boot → login as the
(pre-fix-corrupted) `qingyunk` → re-did `register`/`decide` once more to
repair the corrupted flag → clean `quit` → **fresh full login** (not a
reconnect — confirmed 0 players online before reconnecting) → landed
correctly in the player's real saved room, no register-room detour, no
虚空 punt, `score` showing full registered/born data throughout. Also
directly protects a second, more severe scenario: this same
`"registered"` field is read (correctly) by `d/register/yanluodian.lpc`'s
`do_born()` gate and by every organic content check downstream of "is
this a real, playable character" — a spuriously-reset flag would have
silently gated a legitimate returning player out of normal play
indefinitely, not merely cosmetically.

Not a known AGENTS.md class — closest existing entries are §7.20/§7.21
(both about *location* fields surviving reconnect) and §7.24 (death code
overwriting the login-location field), but this is neither: it's a
*status flag* (not a location), corrupted on an ordinary FULL login (not
a reconnect, not a death), by a stale sibling object's own save data
rather than by any death/limbo code path. Proposed as a new class — see
this report's final section for the draft AGENTS.md writeup text.

### Bug 3 (NEW bug class, but the underlying efun-argument-type mistake matches AGENTS.md §7.12): a dangling `else` in a chained `if` list makes an NPC-guided paid-travel system silently reject every destination except the LAST one checked — and on this lib, that travel NPC is the ONLY way to reach the sole open sect

**Files: `d/city/npc/xu.lpc` and `d/rooms/npc/xu.lpc`** (two copies of
the same 徐霞客/Xu Xiake "travel guide" NPC — one placed in the city,
one that respawns at the destination end of every trip), both carrying
byte-identical `do_go(string target)` functions.

Root cause: a long chain of independent `if (target == "...") ...;`
statements (one per named destination — 回疆/星宿/伊犁/少林/**武当**/
扬州/明教/苏州/终南山/杭州), each setting a `set_temp("go_*", 1)` flag,
was terminated with a single `else return notify_fail(...)` attached
only to the LAST `if` in the chain (`target == "杭州"`) — a classic
dangling-else control-flow bug, not a `switch`/`else if` chain as the
logic clearly intends. For any target OTHER than "杭州"/"杭州城",
execution falls through every earlier `if` (correctly setting the
right `go_*` temp flag along the way, e.g. `go_wd` for "武当") but then
ALWAYS hits the final `if (target == "杭州"...) ...; else
return notify_fail("徐霞客皱了皱眉：那地方我可没去过。\n");` — and since
target isn't "杭州", the `else` branch fires and the function returns 0
(failure) via `notify_fail`, **before** ever reaching the
`call_out("do_goto", 0, me)` that actually starts the trip. Net effect:
paying Xu Xiake and saying `去 武当` (or ANY destination except
Hangzhou) always failed with "那地方我可没去过" ("never heard of that
place") — even though this lib has **no walkable road** connecting
Yangzhou to any other zone; `d/rooms/room3.lpc`'s own "旅途中" room and
its `wait()` function are the sole mechanism that ever moves a player
between zones, and Xu Xiake is the sole gate to it. This made 武当派 —
the only currently-open sect per this lib's own `intro` help text —
**completely unreachable** for any player following the documented
paid-travel flow, for any target other than the one the bug happened to
leave working.

**Reproduced live before the fix**: paid 2 gold to Xu Xiake, `去 武当`
→ "徐霞客皱了皱眉：那地方我可没去过。" (fails), despite `go_wd` having
been set correctly in memory moments earlier.

**Fix** (both files, identical patch — chain into proper `else if`,
preserving every existing per-target flag assignment and the commented-
out entries untouched):

```lpc
// BEFORE (both files):
  if (target == "回疆") me->set_temp("go_hj", 1);
  if (target == "星宿" || target == "星宿海") me->set_temp("go_xx", 1);
  ...
  if (target == "杭州" || target == "杭州城") me->set_temp("go_hz", 1);
  else return notify_fail("徐霞客皱了皱眉：那地方我可没去过。\n");

// AFTER:
  if (target == "回疆") me->set_temp("go_hj", 1);
  else if (target == "星宿" || target == "星宿海") me->set_temp("go_xx", 1);
  ...
  else if (target == "杭州" || target == "杭州城") me->set_temp("go_hz", 1);
  else return notify_fail("徐霞客皱了皱眉：那地方我可没去过。\n");
```

**Re-verified live, end-to-end, after the fix**: paid 2 gold to Xu
Xiake (`give gold to xu`), `去 武当` → "徐霞客点了点头。徐霞客说道：那
你就跟着我走吧。" → moved to `/d/rooms/room3` ("旅途中") → after the
scripted real-time delay, arrived at `/d/wudang/yuzhengong` (遇真宫,
Wudang's mountain gate) exactly as `room3.lpc`'s `wait()`/`go_wd` branch
intends. Confirmed `lpcc` still passes both files cleanly after the
fix (no regression; overall lib fail count improved slightly, 181→179,
consistent with removing two genuinely-broken control-flow paths).

This is the same underlying LPC-semantics mistake class as AGENTS.md
§7.12 (a raw type-unsafe fallback reached by an unguarded control-flow
gap) in spirit, but the actual *symptom* — a dangling `else` silently
disabling several `if`-branches' otherwise-correct work — doesn't match
any existing catalog entry's shape (§7.12 is specifically about a
`message()`/`tell_room()` efun-argument type mismatch). Proposed as a
new class — draft text in this report's final section.

### Bug 4 (matches EXISTING AGENTS.md §7.12, not new): `adm/simul_efun/message.lpc`'s `message_system()` passes a raw `int 0` as `message()`'s 4th (exclude) argument, crashing every broadcast — and this lib's own `tell_room()` wrapper has the SAME unguarded-`varargs`-default shape as §7.12's already-cataloged pattern

Found live via the admin-assisted testing path (see below): any
non-admin-gated `message_system()` call (`cmds/wiz/clone.lpc`'s
"non-admin wizard cloned an item" broadcast, reached even for the
`(admin)`-granted `fluffos` account because `clone.lpc`'s own
`!me->is_admin()` gating didn't suppress it — a separate, pre-existing
nested-condition oddity in `clone.lpc` not touched here since it's
`clone.lpc`'s own logic, not this bug) crashed with:

```
执行时段错误：*Bad argument 4 to EFUN message().
Expected: object, array,  Got: int(0).
程式：/adm/single/simul_efun.lpc 第 365 行 (== adm/simul_efun/message.lpc:365)
```

`adm/simul_efun/message.lpc:365`:
```lpc
// BEFORE:
void message_system(string message) {
  message("system", HIW "\n【系统提示】" + message + "\n" NOR, users(), 0);
}
```

The driver's real `message()` signature (`core.spec:118`) is `message(mixed
type, mixed msg, string|string*|object|object* scope, void|object|object*
exclude)` — the 4th argument must be an object/object-array or simply
omitted (`void`), never a bare integer. Every OTHER `message()` call
site in this same file either omits the 4th argument or passes a real
object/array (`this_player()`, `previous_object()`, `({me, you})`) —
this is an isolated typo, not a house style. **Fixed** by omitting the
argument entirely (matches the surrounding file's own convention for an
unconditional broadcast with no exclusions):

```lpc
// AFTER:
void message_system(string message) {
  message("system", HIW "\n【系统提示】" + message + "\n" NOR, users());
}
```

**While investigating this, found the SAME root shape already latent in
this file's `tell_room()` wrapper** (line 264), matching AGENTS.md
§7.12's cataloged pattern exactly (this lib is a confirmed member of the
"ES II family" §7.12 already lists as generally affected):

```lpc
// BEFORE:
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude);
}
// AFTER (§7.12's prescribed fix):
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude || ({}));
}
```

Any 2-argument `tell_room(where, msg)` call site (510 total `tell_room`
call sites in this lib, roughly a fifth of them 2-arg by a rough grep)
was one bad code path away from crashing exactly like `message_system`
did. **Concretely confirmed high-value**: this lib's own
`clone/user/user.lpc:225`'s `user_dump()` — the `NET_DEAD_TIMEOUT`
(900s/15-real-minute) force-quit handler, i.e. exactly the function
§7.12's "severity escalation" addendum (found on `dtsl`) warns is the
highest-impact call site for this bug class — itself calls a 2-arg
`tell_room(environment(), ...)` on its very first line. Before this
fix, ANY player whose net-dead timeout actually elapsed would have hit
this crash first, potentially aborting `user_dump()` before its
`command("quit")` ever ran (same mechanism §7.12 describes for `dtsl`) —
this pass's own attempted live 900-second net-dead-timeout test (see
below) didn't get to prove this conclusively end-to-end since the
driver crashed from an unrelated cause first (see "Driver-fatal crash"
below), but the fix was already applied and independently verified via
the `message_system` reproduction before that wait was attempted, and
`lpcc` confirms both wrapper functions still compile cleanly.

Not drafted as new — this is squarely AGENTS.md §7.12, just a second,
independent instance of the pattern (the `message_system` copy) found
alongside the already-cataloged `tell_room` shape. Worth noting for the
orchestrator: a quick check of `shiji` and `zhonghua2` (both in this
lib's documented ES II lineage family) shows their own
`adm/simul_efun/message.lpc` still carries the UNFIXED §7.12
`tell_room` shape (`shujian2008`, also in the family, already has the
fix) — not touched here, out of scope for this pass's assigned lib, but
flagged per §10.7's "check documented siblings" step.

### Honest observation, NOT fixed (content/design judgment call, out of this pass's scope): the wooden training dummy (`clone/misc/mu-ren.lpc`) requires 12000 `combat_exp` to spar with — unreachable for any genuinely fresh character

`clone/misc/mu-ren.lpc` (the only object in the whole lib that
`inherit`s `/inherit/char/fighter.lpc`, placed 4-per-room in Wudang's
`wclfang`/`sclfang`/`nclfang` practice halls) inherits that class's
`accept_fight()`, whose very first real check is
`if (ob->query("combat_exp") < 12000) return notify_fail("你这点身手
还不足以和" + name() + "练功。\n");`. **Reproduced live**: a
freshly-registered, freshly-apprenticed `qingyunk` (combat_exp 0)
attempting `fight mu` at the dummy got exactly that rejection. Since
`FIGHTER` is used by nothing else in this lib, this doesn't look like a
copy-pasted "elite legendary NPC" base class applied to the wrong
object by mistake (the usual shape for this kind of bug) — it may
genuinely be this lib's intended design (a "prove yourself in real
combat before the dummy is worth your time" gate), or it may be a
content oversight where the dummy's OWN description ("一个练功用的比武
木人" — "a wooden dummy FOR PRACTICE") directly contradicts a gate that
makes it unusable by exactly the newbie audience such a dummy exists
for. Genuinely ambiguous which bucket this falls in per this pass's
explicit programming-bugs-only scope, so **left untouched** — the
general-purpose `fight` command against an ordinary "friendly"/
"peaceful" city or sect NPC (used successfully below, see "What was
tested") already serves as this lib's de facto safe-sparring path for a
newbie, so this isn't a hard blocker to play, just a documented
oversight/design question for a future content-focused pass to resolve
with an actual balance decision.

### Driver-fatal crash during the live net-dead-timeout test — third corroborating occurrence of AGENTS.md §10.8's still-unpinned refcount-corruption class, NOT this lib's own bug

While deliberately waiting out the real 900-second (`NET_DEAD_TIMEOUT`)
net-dead force-quit window per §10.7 checklist item 8 (`qingyunk` left
net-dead, driver's own stdout captured to a file per §10.8's own
methodology lesson), the **whole native driver process aborted**, only
~2-3 real minutes into the wait (a much shorter window than the
20-25 minutes reported for `xjcq2000`/`shiji`, plausibly because
this pass's admin-assisted `goto`/`summon` testing (see below) had
already forced compilation across an unusually wide spread of the map
in a short time, similar in spirit to `xjcq2000`'s "ambient NPC
wandering forces lazy compilation of the whole map" mechanism):

```
******** FATAL ERROR: FATAL: Object 0x560a091b1498 /d/quanzhen/zhongxin
ref count 0, but not destructed (from free_svalue).
(current object was /d/city/zuixianlou)
...
执行时段错误：*Wrong permissions for opening file /log/nosave/CRASHES for append.
"No such file or directory"
crash() in master called successfully.  Aborting.
```

Same exact fatal signature shape as the two prior occurrences
(`xjcq2000`'s `.../d/xingxiu/silk6`, `shiji`'s
`.../cmds/skill/recruit`) — a completely unrelated object
(`/d/quanzhen/zhongxin`, a Quanzhen-sect room this test session never
even visited) had its reference count corrupted to 0 without being
destructed, surfacing only later when an unrelated `reset()` (this
lib's own `/d/city/zuixianlou`, i.e. 醉仙楼, repopulating its NPCs)
happened to touch it via `free_svalue()`. Unlike the `xjcq2000`
case, this DID leave one line in `debug.log` (the `FATAL ERROR` line
itself made it in before the process died — a minor, not-especially-
meaningful difference in exactly how much gets flushed before the
abort). This is now a **third independent lib/lineage** hitting the
identical fatal signature — strengthens the case that this is a real,
recurring driver-level bug (not mudlib-fixable, not lib-specific), per
§10.8's own note that a third occurrence is worth flagging for
escalation. **Not fixed here** (driver-level, out of scope for a
per-lib mudlib pass) — reported as corroborating evidence only.

Recovery: restarted the driver cleanly (`log/debug.log` boot section
showed zero errors), confirmed `qingyunk`'s save data survived intact
(the crash happened while net-dead, i.e. between saves — no data loss:
`registered:1`, `startroom:"/d/city/zuixianlou"`, `character`/`born`/
`family` all correct on disk), then re-verified a fresh login restored
full state correctly. Did NOT re-attempt the full 15-minute wait a
second time (reasonable stopping point given the strong corroborating
evidence already collected and the rest of the checklist already
thoroughly covered) — so the very last mile of "does `user_dump()`'s
now-fixed `tell_room()` call survive an ACTUAL elapsed 900s timeout,
start to finish, on this lib" was not proven end-to-end live, only
indirectly (the crash that would have hit it, per Bug 4 above, was
independently reproduced and fixed via the `message_system` path before
the timing test was attempted). Flagged explicitly rather than silently
presented as fully verified.

### What was tested and confirmed working (all live, one continuous
    playthrough plus documented admin-assisted side trips)

- Full two-step registration: BIG5 prompt → id/password →
  real Chinese name 青云客 → archetype/gender → landed in 世外桃源 →
  `register <email>` + `decide` with 水笙 → picked "光明磊落" quality via
  the east/`out` branch → `wash` (rolled innate stats) → `born 扬州人氏`
  → landed in the real game world (宝昌客栈/醉仙楼 area), `look`/`score`
  (full stats, no longer "还没有出生呐")/`i` all correct at each step.
- Exploration of the Yangzhou city map (醉仙楼 → 北大街 → 广场西/南/
  中央广场 → 当铺/dangpu → 南大街 → 茶馆/chaguan), reading room `.lpc`
  source directly to resolve non-obvious/renamed exits (`westup` in
  `/d/wudang/yuzhengong.lpc` is a real compound-direction exit name, not
  a display bug).
- The lib's paid NPC-guide travel system (Xu Xiake/徐霞客,
  `d/city/npc/xu.lpc`), post-fix: `give gold to xu` → `去 武当` → real
  travel delay via `/d/rooms/room3` → arrived at Wudang's mountain gate.
- Sect-join (`bai guxu` with 谷虚道长/Guxu Daozhang at 武当广场) —
  correctly gated (attempted `bai zhike` against the mountain-gate
  receptionist NPC first, who has no `attempt_apprentice()` defined and
  correctly never responds — read source to identify the real teacher
  NPC rather than assuming this was broken).
- Organic skill-learning (`learn guxu force` → "你的「基本内功」进步
  了！", confirmed via `skills`/`score`).
- A real fight (safe general-purpose `fight daotong` against a
  "peaceful"-attitude Wudang NPC after the wooden dummy's combat_exp
  gate blocked it, see above) — real combat exchange, correct
  wimpy-triggered auto-flee into an adjacent room, no crash.
- A real shop purchase (`list`/`buy huasheng` at 茶馆's 茶博士, correct
  30-copper deduction from 1 tael of silver, correct 70-copper change).
- Clean `quit` (multiple times) with an IMMEDIATE `debug.log` grep after
  each, per §10.7 item 5/7 — no new errors from any player-driven
  action across the whole pass (the one runtime error that DID appear,
  an `*Array index out of bounds` in `adm/daemons/ftpd.lpc`'s
  `parse_comm()`, has a call stack rooted entirely inside the FTP daemon
  itself with zero relation to any player object — ambient external
  connection noise on the FTP port, not caused by this session, and
  matches this project's already-documented §1.3c FTP-daemon class).
- Multiple net-dead disconnect/reconnect cycles, both deliberate
  (script ends without `quit`) and the accidental one from the driver
  crash above — every prompt reconnect showed the correct
  "重新连线完毕" message and the correct pre-disconnect room (this lib's
  `net_dead()`/`reconnect()` shape, unlike some ES II siblings, does NOT
  void-park the player at all — it just suspends the connection in
  place — so the §7.20 void-parking bug class structurally cannot occur
  here; verified by reading `clone/user/user.lpc`'s `net_dead()`/
  `reconnect()` directly, not just inferred from behavior).
- Full state persistence across a real driver restart (crash + clean
  restart) and across real wall-clock gaps between sessions spanning
  several minutes to tens of minutes over the course of this pass:
  location, sect membership, skill level, and inventory all survived
  every relogin correctly, both before and after Bug 2's fix (before
  the fix, "registered" specifically did NOT survive — that's the bug;
  everything else always did).
- Admin login (`fluffos`/`Mud@2026`) still functional post-fixes:
  `goto`/`summon`/`clone`/`give` all used live as testing aids (see
  below), clean quit, no errors.

### Admin-assisted testing (used deliberately, documented for
    transparency)

This lib has no walkable road between zones (all inter-zone travel is
the paid NPC-guide system, Bug 3 above) and no discovered newbie money
source that actually works live (see below) — reaching Wudang, joining
the sect, and completing a real shop purchase all require money a
genuinely fresh character has no organic way to earn without first
traveling somewhere that itself requires money. Rather than leave these
checklist items entirely unverified, the pre-existing `fluffos` admin
account was used as a **testing fixture**, exactly as `clone`/`summon`/
`goto` are designed for: cloned gold/silver and `give`-ed it to
`qingyunk` (an ordinary in-game item transfer, not a save-file edit),
and used `goto`/`summon` to relocate `qingyunk` to/from Wudang rather
than manually walking a mountain path with no gameplay significance to
this pass's goal. No mudlib code or save data was hand-edited to
fabricate content; every subsequent action (`去 武当`, `bai guxu`,
`learn guxu force`, `fight daotong`, `buy huasheng`) was driven entirely
by `qingyunk`'s own ordinary player commands.

Noted but not chased (content/design, out of scope): 
`d/city/npc/monk.lpc`'s 老和尚 (the NPC this lib's own newbie help text
names as the starting-money source at 扬州城隍庙) has its `give_money()`
function's actual `add_money()`/`command("give ...")` calls entirely
COMMENTED OUT — visiting him and asking `about 领钱` produces flavor
text ("可惜你来迟了" / "要钱没有，命有一条") but no money regardless of
karma. Could be an intentional later-game-era balance change by the
original archive's own developers (matches this project's established
pattern of finding disabled features from a live game's history, e.g.
AGENTS.md §7.18) or a genuine content gap — ambiguous, left untouched
per this pass's explicit scope, documented for a future content pass.

### Not verified live (explicitly flagged, not silently skipped)

- **Death/respawn**: not attempted — would require deliberately losing
  a real fight, and this pass's test character never had the combat
  power built up to do so safely within the time budget. A grep-based
  code check (`inherit/char/fighter.lpc`'s NPC-class `die()`,
  `clone/user/user.lpc:718`'s player `die()`) found no obvious §7.24-
  shaped "death code overwrites the login-location field" pattern (no
  `set("startroom"` call anywhere in the death/reincarnation code path),
  but this was a static read, not a live reproduction.
- **The full 900-second net-dead force-quit path, completed end-to-
  end**: attempted live per §10.7 item 8/§10.8's methodology, but the
  driver crashed from the unrelated §10.8-class fatal bug (see above)
  before the timeout could elapse naturally. The specific crash Bug 4
  would have caused inside `user_dump()` was independently confirmed
  and fixed via a different reproduction path (the `message_system`
  crash), so there's strong indirect evidence the fix holds, but the
  literal "wait 900 seconds, watch `user_dump()` succeed" experiment
  was not completed live in this pass.
- **A live reproduction of the mu-ren dummy's `accept_fight()` gate as
  definitively "wrong"** — reproduced the REJECTION live, but whether
  12000 `combat_exp` is a bug or intended difficulty was not resolved
  (see "Honest observation" above) and would require a content-design
  judgment call outside this pass's scope.
- The exact live confirmation that `shiji`/`zhonghua2` (noted above as
  still carrying Bug 4's `tell_room` shape) would actually crash if
  exercised — only confirmed via static code comparison against this
  lib's own (now-fixed) copy, not by booting those libs.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 27 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`adm/daemons/closed.lpc`（AGENTS.md §7.107，第三条独立确认的
   血统）**：`load_all_users()` 的两处 `restore()` 调用没有
   `catch()` 保护，结构与本 session 在 `nt1`/`shenmo` 发现的完全一
   致。按 §7.107 记录的写法预防性修复
   （`catch(ok = X->restore())` + `err || !ok` 判定）。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
3. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，第十四条
   独立确认的血统）**：`adm/daemons/logind.lpc` 有同款
   `exec(old_link, user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 Y 踢掉旧连
   线"验证：`look`/`score` 修复后立即正常响应（`score` 显示"还没有
   出生呐"是本档案自己"注册未 register/born 前 score 内容受限"的既
   有设计，不是指令派发失败——`look` 正常显示房间描述已确认指令派
   发本身工作正常）。

`cmds/wiz/update.lpc`（§7.106）与 `master.lpc::log_error()`（§7.10
的 `"arning:"` 大小写无关写法）均已是正确写法，`maximum evaluation
cost` 已经是 `5000000`，均无需改动。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录（BIG5 询问答"N"→
id+密码）确认 `您目前的权限是：(admin)`，`update /adm/daemons/
logind` 成功验证真实写入权限。踢掉重复登录重连路径现场验证通过
（见上）。`debug.log` 全程干净（488 行，无真实错误）。

### 本轮修改的文件

- `work/adm/daemons/closed.lpc`
- `work/adm/simul_efun/file.lpc`
- `work/clone/user/user.lpc`

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/inherit/room/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,715 live
occurrences** (survey-ranked #84 of 166 candidates >=100, tied with its
sibling lib `xkxc98sj`). Fixed with the sweep's binary-mode script
(`fix_710_room.py`) plus two hand-fixed room-building-tool copies
(`clone/misc/roommaker.lpc`, `cmds/debug/roommaker.lpc`, both the
simple `str += "...replace_program(ROOM);..."` string-builder variant).
`git diff --numstat` totals (2 insertions, 1715 deletions) match the
survey's live-occurrence count exactly. No `work/data/` room-source
false-negative found. Verified via a clean `build-debug` boot (zero
"cannot replace"/"cannot bind" `debug.log` lines, port 40035 listening)
plus a live admin login (`fluffos`/`Mud@2026`, after answering the
BIG5-font prompt with `n`) — `look`/`quit` both worked normally,
`debug.log` stayed clean throughout. Incidental admin save-timestamp
drift from the spot-check reverted before committing.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/dali/yuxuguanmen.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xkxz2`: 16 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 18 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 2 PASS, 0 that loaded before fail now, 0 more load.

16 files moved (16 `.C`); mostly under `kungfu/skill/never-defeated` (9), `kungfu/skill/kuihua-mogong` (7). A rescan with `scripts/lpc_warnings.py xkxz2` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xkxz2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 409 个 `.lpc` 和 6 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：381 -> 381 通过，无回退；改过的头文件的 25 个包含者 25 -> 25 通过。
手改两处：`adm/daemons/natured.lpc` 的空语句 `lt[LT_MON];` 删去（与 nitan 一系同）；`adm/daemons/logind.lpc` `get_id()` 里从未用到的 `ip` 删去。启动时警告 32 -> 0；新进程登录（编码选择、新人物确认）与 HEAD 相同。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 1。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`clone/misc/swmuding.lpc`（神木王鼎）自己声明了一张 `mapping insects` 虫表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名；读表的是木鼎的代码，读到的是木鼎自己的表，神木王鼎的虫表从来没用上（`Redeclaration of global variable 'insects'`）。改名 `sw_insects`，`create()` 里 `insects = sw_insects;` 交给木鼎（nitan170911、wxddym、zjdy 系同修）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

`scripts/lpc_twin_port.py adopt xkxc98sj xkxz2` 搬来 xkxc98sj 同日整理（a69e715c2f6）的 20 个文件，与本库逐 token 相同，能编译的文件警告清零。改动的 20 个对象在 HEAD 与工作树各载入一次：HEAD PASS 10，tree PASS 20，regress 0，新载入 10 个。

- 暗器类 10 个（`clone/weapon/feidao`、`jinhua`、`sjian`、`jin-sjian`、两处 `bqp_obj/feibiao`、两处石子 `shizi` 等）在 `THROWING` 之外又继承它已带的 `COMBINED_ITEM`，`Illegal to redefine 'nomask' function`，从没载入过；去掉多余的一行后都能载入。
- 酒楼五间（`d/city/jiulou2`、`zuixianlou2`、`d/dali/jiulou`、`d/quanzhen/jiulou2`、`d/shaolin/jiulou2`）同时继承 `ROOM` 和 `F_DEALER`，驱动只用 `dealer` 的 `reset()`，房间的 `objects` 不再刷新；写 `void reset() { room::reset(); dealer::reset(); }`。
- `d/rooms/npc/obj/jia.lpc` 写明用驱动原先选的 `clean_up()`；`d/xiangyang/npc/shanzei0.lpc` 与 `globals.h` 相同的 `MAX` 宏删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`attempt_apprentice()`、`check_reply()`、`remove_effect()`。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14（补）：上面改成有返回值的函数里残留的空 `return;` 改为 `return 0;`（值不变，消除 `Non-void functions must return a value`）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：3 个对象，新增载入 3，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，8 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。8 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`jinshemiji`、`jsmj`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/sansha`。

## 独孤九剑列不出剑法目录（2026-10-15）

`lonely-sword` 的 `query_action()` 用 `get_dir("/kungfu/skill/*.lpc")` 列出所有剑法，再随机借一招；但 `/kungfu` 下对象的 euid 是 `Domain`，安全守护（securityd 的默认规则只许 ADM/ARC/WIZ 读）不给它列目录，`get_dir()` 返回 0，`filter_array(0, ...)` 每次出招都报错。改为：列不出目录时借出手者自己会的剑法（找不到技能文件的跳过），一门也没有就用兵器本身的招式，再没有就用 weapond 的「刺」。目前这门功夫没有实际入口：唯一会它的 NPC 是黑木崖的 `npc/linghu`（令狐冲），没有房间放置他，而且他 `set_skill()` 了本库没有的 `feiyan-huixiang`、`huashan-sword`，一载入就报错。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinhse-jianfa`→`jinshe-jianfa`（`/d/jinshe/skill/jinshe`）；`xixing-dafa`→`xixin-dafa`（`qiantian-yiyang`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（7 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

9 个文件、18 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/thd/obj/biyuxiao.lpc`、`/d/xueshan/obj/y-jiasha`、`/d/dali/obj/obj/panguanbi`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 6 个（5 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 3 个，改后 8 个，没有退步。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_COAGENT` → `/feature/coagent`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 36 个对象设了本库没有文件的武功（82 个名字，最多的是 `tianlong-shengong`、`medical`、`zixia-shengong`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 11 个通过，其余 19 个停在别的错误上（`adm/daemons/story/anthem`：NOLOAD；`adm/daemons/story/baguadao`：NOLOAD……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/heimuya/houting` 的 `northdown`：`yuemen` → `yunmen`；`/d/xiangyang/kedian2` 的 `down`：`tianxianglou` → `kedian`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/inherit/char/punisher`←zjdywzb，18 个对象继承它，抽样 10/10 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 49 处、47 个文件：`shaolin-shnfa`→`shaolin-shenfa`（19 处）、`kunlun-shnfa`→`kunlun-shenfa`（15 处）、`huashen-shenfa`→`huashan-shenfa`（5 处）、`lognxiang-gong`→`longxiang-gong`（4 处）、`yunv-shenfa`→`yunu-shenfa`（2 处）、`weiituo-gun`→`weituo-gun`（1 处）、`shenhuo-shengong`→`shenghuo-shengong`（1 处）、`yunv-xinjing`→`yunu-xinjing`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::init()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 10 个：`d/shaolin/npc/muren_fighter1`、`d/shaolin/npc/muren_fighter2`、`d/shaolin/npc/muren_fighter3`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `CHAT_ROOM`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/item/medical-book`（宏 `MEDICAL_BOOK`）←zjdywzb：3/3 个继承它的对象载入，同时带来头文件 `/include/medical.h`
- `/inherit/misc/_xiao`←zjdywzb：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 4 个文件：`/clone/npc/luohantang-shouzuo.lpc`、`/clone/user/loaduser.lpc`、`/d/thd/npc/loaduser.lpc`、`/inherit/char/waiter.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 4 个原来载入失败、现在载入，没有退步。

## 比较链的人工修正（2026-10-20，KB 06 §7.282）

`d/mingjiao/bhd/xbkai.lpc`：爬岩石的判断 `arg != "yanshi" || arg != "岩石"` 永远为真，爬什么词都爬上岩石；本意是参数是 yanshi 或“岩石”，改成 `==` 和 `||`。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/cmds/adm/sameip.lpc`（1 处）、`/inherit/room/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 12 处）。改动：`/cmds/skill/quanjia.lpc`（1 处）、`/d/mingjiao/npc/zhangwuji.lpc`（1 处）、`/d/rooms/npc/yy18q9.lpc`（1 处）、`/kungfu/class/emei/fengling.lpc`（1 处）、`/kungfu/skill/meinu-quanfa.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/rooms/npc/npc.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/fill.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 昆仑派 `banshuxian`、`hetaichong`、血刀门 `laozu` 的 `ask_me()`：`ob` 从来没赋值（2026-10-21，KB 06 §7.346）

`/kungfu/class/kunlun/banshuxian.lpc`、`/kungfu/class/kunlun/hetaichong.lpc`、`/kungfu/class/xueshan/laozu.lpc`：`object ob;` 之后直接 `ob->query("gender")` / `ob->query_skill(..)`，根上的 xkx100 在声明后有一句 `ob = this_player();`，这个派生库把它丢了，`ask <师傅> about <秘籍>` 一律抛 `call_other() ... Got: int(0)`。补上这句。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 29 条注册（20 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/mdc.lpc`（`do_all`、`do_link`、`do_new`、`do_save`等）、`/adm/npc/referee.lpc`（`do_halt`）、`/d/city/leitai12.lpc`（`do_action`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/anbian.lpc`（`do_tiao`）、`/d/dali/muwu1.lpc`（`do_tiao`）、`/d/dali/npc/duan2.lpc`（`do_vendor_list`）、`/d/dali/shanlin-6.lpc`（`do_tiao`）、`/d/gumu/gmqs.lpc`（`do_play`）、`/d/jinshe/husun1.lpc`（`do_pa`） 等共 20 个文件。最多的函数名：`do_tiao` 3 处、`do_strike` 3 处、`do_halt` 2 处、`do_all` 1 处、`do_link` 1 处。没有动（读过）：`/clone/misc/bargain.lpc` 的 `do_sign`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。这个库的 NPC / 房间基类不先把路径规范化，调用它们的 NPC 在 `create()` 里就失败，克隆不出来（房间的 `objects` 表悄悄少了这些 NPC）。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py`）：`/d/dali/npc/zhang.lpc`（`__DIR__ "../obj/hammer"` → `"/d/dali/obj/hammer"`）, `/d/dali/npc/zhang.lpc`（`__DIR__ "../obj/hammer"` → `"/d/dali/obj/hammer"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）, `/d/xiaoyao/npc/qingyun.lpc`（`__DIR__ "../obj/cloth"` → `"/d/xiaoyao/obj/cloth"`） 等共 5 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。
