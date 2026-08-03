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
