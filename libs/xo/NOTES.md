# xo — 笑傲江湖迷你版 (The Smiling, Proud Wanderer — Mini Edition)

Archive: `xo.zip`. Port: 40023. Status: **done** (boots clean, connects,
plays through login into "create new character?" confirmation with zero
crashes).

## What this is

A different, smaller lineage from everything else processed so far in
this batch: `secure/daemon/master.c` header says "Original from TMI-2 and
ES2, Rewritten by Falcon 96-10-02" — TMI-2 ("The Mud International 2") is
another classic MudOS-era mudlib base, distinct from the "ES II"/nitan
families seen in archives #21-#26. Uses the `secure/daemon/{master,
sefun}` path convention (not `adm/obj/` or `adm/single/`). Small lib —
1395 `.c` files, "mini edition" as the name says. No `set`/`query`/
`delete` global simul_efun defined (like `rzrmud`/`xkx2001`) — every
object provides its own via inheritance, the architecturally correct
pattern (see AGENTS.md §15).

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: `secure/daemon/
   master.lpc`'s `valid_write`/`valid_read` called `load_object(SECURITY_D)`
   unconditionally on every single call (not gated behind `find_object()`
   first), wrapped in `catch()` but with no re-entrancy guard. Added the
   full guard (nosave flag + `find_object()` check before attempting
   `load_object()`) per the established §4 fix shape, applied proactively
   before the first boot attempt given the exact matching pattern.
2. **New bug (case-sensitivity, Windows-origin archive on a
   case-sensitive Linux filesystem)**: 3 files (`system/feature/char/
   command.lpc`, `cmds/arch/ll.lpc`, `cmds/arch/localcmds.lpc`)
   `#include <Action.h>` (capital A), but the actual file on disk is
   `include/action.h` (lowercase) — silently resolves on Windows'
   case-insensitive filesystem, hard-fails here. This was responsible for
   the overwhelming majority of the initial lpcc sweep's failures (762
   "Undefined class 'Action'" + 155 "Cannot #include Action.h" out of
   1395 files, cascading from just those 3 root includes via inheritance)
   — fixing the 3 `#include` lines dropped the failure count from 209 to
   72 in one shot (85.0% → 94.8% pass). Checked the whole tree for any
   other same-shape case-only filename mismatches (`find -iname` +
   case-insensitive dedup) — none found, this was the only instance.

## Interactive test result

Boots clean, connects; welcome message + "last modified 1999.11" credit
line render correctly, empty input at the username prompt correctly
triggers a polite disconnect ("欢迎下次再来" — not a bug), `new` +
a valid English name reaches the "create new character?" (y/n)
confirmation with zero crashes. Did not create a full character or play
further (out of scope).

## lpcc sweep

1395 files, 1323 pass / 72 fail (94.8%, after the Action.h fix). Remaining
72 failures are the usual long tail (a handful of syntax typos in
individual files, a few missing daemons like `TASK_D`/`SendToUser`/
`SendToMud` referenced but not present in this "mini" trimmed-down
archive) — not triaged individually, consistent with AGENTS.md §6b/§13.

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

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  1395 `.lpc` files in `work/`; 1363 written, 7 already-conformant, 25
  errors (files it refused to touch, expected/fine on legacy code).
  Spot-checked that this didn't disturb the §4/case-sensitivity fixes
  above, plus the pre-existing `#define private protected` / `#define
  nosave nosave` compatibility shim in `include/globals.h` — all intact
  post-format.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (zero fatal errors in `log/debug.log` — the two
  "mudlib error handler"/`#define __DEFAULT_PRAGMAS__` lines are the
  driver's own startup config dump, not errors). Went further than the
  previous pass (which had stopped at the "create new character?"
  confirmation) into a **full end-to-end registration + play session**:
  real Chinese name 秦风丁/秦风戊, English id/confirm/Chinese
  name/password/email/gender all completed, dropped into 小秦淮客寓;
  `look` showed the correct room+NPCs, `score` produced a correct full
  character sheet, `quit` correctly enforced the "must play 30 real
  minutes before saving" gate and disconnected cleanly on confirming
  `y`. Zero real `debug.log` errors.
- **WASM**: booted cleanly (only the expected non-fatal
  `socket_create`/`socket_bind`/`socket_connect` "Undefined function"
  compile errors from `system/std/net/client.lpc`, since the `sockets`
  package isn't built into this WASM binary — matches the documented
  non-fatal WASM restriction). Registration itself proceeds correctly
  all the way through the gender prompt (m/f) — but **reproducibly**,
  across several `--idle`/`--timeout` values (1.0/2.0/3.0/6.0s), the
  transition into the live game world (`enter_world()`) never
  completes: no banner/room text appears after answering the gender
  prompt, and subsequent `look`/`quit` input gets the driver's generic
  "什么? 你想干嘛?" (unrecognized command) fallback instead of real
  output. This is **not** the documented `query_ip_number()` limitation
  (this lib never gates login on IP format). It also does **not**
  reproduce on the native rebuilt driver (full playthrough above was
  clean), and notably does **not** reproduce on `xo_final` — a very
  close sibling with near-identical `logind.lpc` registration/
  `enter_world()` code — under the exact same WASM harness (see
  `xo_final`'s own NOTES.md entry, verified working end-to-end). Root
  cause not identified (the WASM harness's debug-log-open failure at
  boot, a separate pre-existing cosmetic warning, means any real
  runtime error thrown during `enter_world()` here would be silently
  discarded rather than surfaced anywhere inspectable). **Verdict:
  flagged as a possible WASM-specific gap isolated to this lib's own
  code path, not patched** — native play is completely unaffected, and
  chasing it further didn't seem proportionate to the smoke-test scope
  of this pass. Worth a closer look in a future WASM-focused pass.

## 2026-07-23 (integrity review): WASM world-entry hang RESOLVED — was the harness, not the mudlib

Re-ran the full WASM registration flow (new → id → confirm → Chinese name
→ password ×2 → email → gender) against the same `build-wasm` binary but
with the FIXED `scripts/wasm_client.js` (the copyDir() log-directory
recursion fix landed in the final commit of the previous pass, AFTER this
lib's WASM test had been run). Result: **`enter_world()` now completes
normally under WASM** — MOTD banner, 小秦淮客寓 start room, `look`, and
the `quit` save-gate prompt all appear exactly as in the native run. No
mudlib race exists in xo's enter_world path; the earlier "reproducible
world-entry hang" was the old harness failing to recreate the lib's
nested `log/` subdirectory shape in the WASM in-memory FS (this lib's
`log/` has 6 nested subdirs — acct/catch/log/room_log/runtime/static),
so an early uncaught `write_file()`/`log_file()` during enter_world threw
ENOENT and silently aborted the flow — precisely the harness gap class
described in that commit's message. Verdict: **fully playable under
WASM**; the previous NOTES entry's "possible WASM-specific gap isolated
to this lib" flag is closed.

Also noted (pre-existing, original-author code, left as-is): `system/
daemon/logind.lpc`'s `enter_world()` contains two leftover debug
`printf("beforee exec...")` / `printf("before setup...after exec..")`
lines that print to every player at world entry — present since the raw
archive (verified in the initial conversion commit), cosmetic only.

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched:

- `system/daemon/band.lpc` `is_banned()` (~line 39) — loopback / empty /
  malformed-IP short-circuit `return 0;` at the top (inline test, no
  helper needed — only one gate function in this daemon).
- `system/daemon/logind.lpc` `CheckDupIp()` (~line 148) — multi-login
  deny list now exempts loopback/malformed-IP connections (`return 0;`
  before the multi_deny regexp loop).
- `logon()`'s `LOGIN_DELAY` startup-grace gate (~line 102) is compiled
  out (LOGIN_DELAY not defined anywhere) — left as-is, noted only.
- `uptime() < 10` in `logon()` (~line 125) is cosmetic (banner text
  choice), not a gate — left intact.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via `fluffos (admin)` appended to `secure/etc/wizlist`.
Verified: real registration (ENTER/new/fluffos/y/浮浮/pw×2/email/m →
landed in 小秦淮客寓), then relogin as fluffos →
`update /system/daemon/logind` → 成功, `score` correct. Retest: fresh
normal registration (秦风, f) end-to-end with look/score correct (quit
shows the original 30-min new-account retention prompt — content timer,
kept per policy); test char save removed; zero new debug.log errors.
Save file: `work/data/user/f/fluffos.o` (NOT gitignored — normal add,
no force-add needed).


## Fail-closed retrofit for the loopback-allow gate (2026-07-24)

The loopback helper above was originally written matching the
project-wide convention at patch time (AGENTS.md §1.3b), which also
treated an empty/non-string/malformed `query_ip_number()` result as
loopback, defensively, because the WASM driver used to return garbage
there. That underlying driver bug is now fixed (fluffos commits
`e33bb5da` "fix: query_ip_number() returned uninitialized garbage under
WASM" and `007bb863` "feat: synthetic resolve() on WASM instead of
raising an LPC error", both 2026-07-23; the locally-built
`build-debug`/`build-wasm` binaries already postdate both commits), so
treating unparseable IPs as trusted is a fail-open gap with no remaining
justification. Retrofitted to fail-closed: loopback is now strictly
`ip == "127.0.0.1" || ip == "::1" || ip[0..3] == "127."` (with a
`stringp()` guard before the slice) — a malformed/empty IP now falls
through to the NORMAL gate instead of being treated as local. Retested
after tightening: fresh driver boot clean, `fluffos` loopback login and
its wizard `update` command both still work; zero new debug.log errors.

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes verified
only registration + `look`/`score`/`quit` + admin login). This "mini"
archive has no `help newbie`/`help intro` file at all (`help/user/`
contains only a single sect help page and no `topics` index — a genuine
content gap in this trimmed archive, not a conversion bug; `help` with
no argument literally prints `0` to the player, see Bug 8 below), so the
test path was derived entirely from reading room/NPC source: register →
`小秦淮客寓` (start room, Yangzhou) → walk to 崇雅书院/至止堂 and learn
`literate` from the teacher NPC 增城湛 via `qingjiao` → (admin-assisted,
see below) reach `无量剑派东宗`'s hall and join via `apprentice`/`kneel`
→ a real fight → a real death → the death-realm/reincarnation flow → a
shop purchase → `quit`/reconnect testing. Found and fixed **eight**
distinct programming bugs (compile errors, a driver-API-misuse crash, and
a silent-stranding `move()` bug), one of which is a well-established
project bug class (§7.25) and most of the rest are one-off typos of a
kind AGENTS.md already tracks (§6.6/§8.5-adjacent); also captured a
**driver-level SEGFAULT**, corroborating the §10.8 "ambient background
processing can crash the whole process, invisible to `debug.log`" class
with a genuinely different C++-level mechanism (a dangling `shadowed`
object pointer walked during the periodic `reset()` sweep) than either
of the two prior occurrences.

**Note on this pass's scope**: partway through this session the
orchestrating session clarified that only genuine *programming* bugs are
in scope for live fixes (compile errors, driver-API misuse, missing
null/objectp checks around calls that can crash, obviously-wrong
references) — game-balance/content/design questions are explicitly
OUT of scope, even when they look surprising. One thing found live (a
"safe" sect mirror-spar that turned out to deal lethal, real damage —
see "Observed, not fixed" below) falls squarely in that excluded bucket
and was deliberately left untouched, documented only.

**Wuliang sect is not reachable by ordinary walking in this archive**:
`d/menpai/wuliang`'s only outbound connection to the rest of the map
(`shanjiao.lpc`'s `northwest` exit) points at `/d/map/xinan/jiangbian`,
and `/d/map/` doesn't exist anywhere in this "mini" archive (confirmed:
`d/map` is entirely absent). No city room links into
`d/menpai/wuliang` either. This means the sect content described in the
lib's own README ("目前只有扬州城和无量派两大门派") is real and
functional but **currently has no in-game path to it at all** — every
sect-related test below (`apprentice`/`kneel`, the mirror-spar,
`qingjiao`) was reached via admin `goto`/`summon`, not by walking. This
looks like a genuine map-connectivity gap from the archive trim (not
something we fixed — no defensible "correct" reconnection point exists,
and fabricating one would be a content decision) but is worth flagging
prominently since it's a bigger blocker to real play than any single bug
below.

**Test characters** (kept as evidence, not cleaned up):
- `qinfengding` / 秦风丁 (male, pw `Aa123456`) — first registration,
  used for the teacher-NPC `qingjiao` test and a full clean `quit` (both
  the "too new to save" no-save-confirm path AND, much later in the same
  real session once 30 real minutes had elapsed, a REAL save-and-quit,
  reconnect-verified). Currently in `小秦淮客寓` wearing 青布衣衫,
  literate skill improved once via 增城湛.
- `qinfengwu` / 秦风戊 (female, pw `Aa123456`) — used for the prompt
  net-dead/reconnect test and the shop-purchase test (bought 白缎衫 from
  沈万福 in `baiyi_dian` for 800 铜钱, funded via an admin-dropped/
  player-picked-up 银子 since fresh characters start with no money).
  Currently in `沈家白衣铺`, holds 白缎衫 + 200 铜钱 + starting gear.
- `qinfenglong` / 秦风龙 (male, pw `Aa123456`) — used for the sect-join
  (`apprentice zuo`/`kneel`), the mirror-spar-that-wasn't-safe (see
  below, died to 老高), and the death/reincarnation flow. **Deliberately
  has no save file** — during testing this character hit `quit`+`y`
  while still under the lib's real 30-real-minute-before-first-save gate
  (`cmds/comm/quit.lpc`'s `confirm_quit_with_nosave()`), which correctly
  and intentionally `rm()`s both the `login/` and `user/` save files —
  confirmed this is the INTENDED behavior (matches the on-screen
  warning verbatim), not a bug; documented here only so a future pass
  isn't confused by the missing `.o` file for an id that clearly saw a
  lot of activity in `debug.log`-adjacent logs (`data/log/q/qinfenglong`
  still exists and shows the session).
- Admin: `fluffos` (pre-existing, pw `Mud@2026`) — used throughout for
  `goto`/`summon`/`force`/`update`/`call` to reach the disconnected sect
  zone and to recompile fixes live.

### Verified working
- Registration end-to-end with real Chinese names (秦风丁/秦风戊/秦风龙),
  landing in `小秦淮客寓` with correct `look`/`score`/`i`.
- Organic teacher-NPC skill learning: `qingjiao zeng literate` against
  增城湛 (崇雅书院/至止堂) — first attempt succeeds ("你听了增城湛关于
  读书识字的讲解阐释..."), immediate repeat correctly refused ("贪多不化
  ...").
- Sect join (`apprentice <NPC>` → NPC leads you to a side hall → `kneel`
  once the NPC's own delayed dialogue sets the flag) against 左子穆,
  leader of 无量剑派东宗 — full flow completed, disciple rank/family
  granted, sword received, **persisted correctly across an unrelated
  driver restart** (see Bug 3's segfault below — after the driver came
  back up, `qinfenglong`'s family/rank data was intact even though their
  physical location reset to the last real `startroom`, which is
  correct/expected since location is separate save state from family).
- A real fight to the death (see "Observed, not fixed" — the sect's
  mirror-spar `accept_fight` branch actually killed a fresh, unarmed
  disciple in one hit), the full death → 黄泉路 → 鬼门关 → 酆都地府 →
  阎罗大殿 flow, and (after Bug 7's fix) the reincarnation NPC 判官
  (`chacha.lpc`) correctly walking through its dialogue and moving a
  ghost with an empty inventory back to a real, live room.
- A real shop purchase: `list shen` (vendor goods listing) then
  `buy baiduan shan from shen` — correct price/change arithmetic, item
  added to inventory, auto-save fired, zero crashes.
- `quit`: both the "too new, confirm without saving" path (explicitly
  wipes save files — confirmed intentional, see `qinfenglong` above) and,
  later in the same real session once past the 30-real-minute mark, a
  genuine save-and-quit → reconnect round trip with correct
  location/inventory/score restored.
- A prompt (well within any timeout) unclean net-dead disconnect +
  reconnect (`qinfengwu`, and incidentally `qinfengding`/`qinfenglong`
  across nearly every test in this pass, since `mudclient.py` closing
  its socket without sending `quit` IS an unclean disconnect) — this
  lib's own `net_dead()`/`reconnect()` (`clone/user/user.lpc`) never
  relocates the player at all (no `VOID_OB` park, no location temp var),
  so there is no §7.20-style stale-location-on-reconnect risk to find
  here; reconnecting mid-session always resumed exactly in place, every
  time.
- `debug.log` grepped after **every** `quit`/crash/compile-fix in this
  session, per the AGENTS.md §10.7 mandate — see the segfault entry
  below for why this matters: at NO point did `debug.log` grow by even
  one line beyond its pre-session baseline (219 lines, unchanged for the
  entire ~30-minute session), despite multiple live compile errors, one
  live driver-API-misuse crash, and one full driver segfault all
  happening during that same window. Every one of those was caught
  purely by watching the client transcript / driver stdout / the
  in-lib `log/runtime` file, never `debug.log` itself.

### Not verified live (explicitly)
- **The full 900-second (`NET_DEAD_TIMEOUT`) unclean-disconnect wait**:
  not performed, for time-budget reasons. Mitigating factor found by
  code reading instead: this lib's `net_dead()` (`clone/user/user.lpc`)
  never moves the player to `VOID_OB` or any holding room at all — it
  just stops the heartbeat and schedules `user_dump(DUMP_NET_DEAD)`
  after the timeout, which (per the same file) simply calls the
  ordinary `command("quit")` at the player's CURRENT, never-changed
  location. Both of the two independent root causes AGENTS.md §7.20
  documents (void-parking without restore, and a `reconnect()` that
  never gets called) require the net-dead path to relocate the player
  in the first place — this lib's simpler design structurally can't hit
  either. Lower-priority to chase further given that structural
  argument, but flagged honestly as code-review-only, not live-tested.
- A wizard `check_rein`/`death_stage` race was observed where
  re-entering `阎罗大殿` multiple times (to re-trigger 判官's dialogue
  during iterative testing) stacks multiple concurrent `call_out` chains
  with no dedup guard (`init()` calls `call_out("check_rein", 2, ob)`
  unconditionally on every room entry) — plausible under real multi-
  minute AFK/re-entry play, not just repeated admin testing, but was
  not cleanly isolated/reproduced as a standalone bug this pass (my own
  repeated `goto`/`summon` re-entries are a confound); flagged as worth
  a closer look in a future pass rather than fixed blind.

### Bugs found and fixed

1. **Unterminated string literal (×3, same shape, different files) —
   AGENTS.md §6.6-adjacent (pre-existing authors' typo, not a new bug
   class)**: a Chinese-text string literal missing its closing `"`
   before the trailing comma, causing the driver to keep consuming
   subsequent lines as string content until it hits the next `"`
   (usually inside a `//`-commented line, since the comment marker means
   nothing once already inside an unterminated string) and then throwing
   a cascade of "Illegal character" / UTF-8-mid-codepoint errors once the
   accidental early-close lands mid-multibyte-character.
   - `d/menpai/wuliang/npc/zuo.lpc:69` — **this one is the single most
     impactful fix in this pass**: 左子穆, the sect's own leader/master,
     failed to compile entirely, so `d/menpai/wuliang/dating.lpc`'s room
     population silently dropped him (caught by `std/room.lpc`'s already-
     `catch()`-guarded `make_inventory()` — this lib is NOT vulnerable
     to the unguarded §7.25 crash shape, just the graceful-degradation
     side of it) — meaning the ENTIRE sect-join mechanism was inert
     (no master NPC to `apprentice`) until this fix.
     ```lpc
     // BEFORE:
     "姓名" : "嗯，你既知我姓左，怎会不知在下便是无量东宗掌门人左子穆？,
     // AFTER:
     "姓名" : "嗯，你既知我姓左，怎会不知在下便是无量东宗掌门人左子穆？",
     ```
   - `system/skill/misc/yuanyang-dao.lpc:33` (the "鸳鸯刀法" weapon
     skill's 4th combat move) — same shape, fixed identically.
   - `system/skill/misc/taizu-quan.lpc:181` (the "太祖长拳" unarmed skill's
     "英雄独立" move) — same shape, fixed identically.

2. **Undefined-macro `inherit` (×2 files)**: `d/city/yangzhou/waifang.lpc`
   and `d/city/yangzhou/woshi.lpc` (both real, reachable rooms — a
   courtesan-house's outer/inner room, linked from `meixiang_yuan.lpc`)
   did `inherit DOOR_ROOM;` — `DOOR_ROOM` is never `#define`d anywhere in
   this archive (no `door_room.lpc` base class exists at all), a hard
   compile error (`expecting L_STRING or '('`). Every other room in this
   lib that needs a door (e.g. `d/menpai/wuliang/damen.lpc`) just
   inherits plain `ROOM` and calls `create_door()`, which `std/room.lpc`
   already provides directly — `DOOR_ROOM` was never real content, just
   a stale reference. Fix: `inherit ROOM;` in both files.

3. **Malformed function declaration swallowed into a comment**:
   `system/skill/basic/kongshou.lpc:37-38` — the base "unarmed combat"
   skill, needed on literally every unarmed combat round for every
   character. The Chinese explanatory comment and the following
   function signature were on the same physical line with no separating
   newline, so the ENTIRE function header got absorbed into the `//`
   comment, leaving a bare orphaned `{` on the next line
   (`syntax error, unexpected '{'`). **Reproduced live**: fighting as an
   unarmed disciple spammed a "Compiling error .../kongshou.lpc ... *No
   program in object" message to the player on every single combat
   round (both attack and parry attempts), since `skill.lpc`'s combat
   dispatch tries to load this file fresh every time it's referenced and
   it never successfully compiles.
   ```lpc
   // BEFORE:
   // 这个函数用来区别这种天生的技能与其他后天学习的技能int is_native_skill()
   {
     return 1;
   }
   // AFTER:
   // 这个函数用来区别这种天生的技能与其他后天学习的技能
   int is_native_skill()
   {
     return 1;
   }
   ```
   Checked the other 4 sibling files in `system/skill/basic/` with the
   same `is_native_skill()` pattern (`wuqi.lpc`, `horsedodge.lpc`,
   `dodge.lpc`, `yeshou.lpc`) — all correctly formatted, this was an
   isolated one-off typo, not a copy-pasted class.

4. **Missing `#include <armor.h>` (×2 files) — AGENTS.md §6.1**:
   `d/city/yangzhou/npc/cloth/cloth.lpc` (the base clothing template) and
   `d/menpai/wuliang/npc/obj/choushan.lpc` (a sect disciple's robe, worn
   by the live `npc/qyz.lpc`... which itself turns out to be dead/
   commented-out content, see below — fixed anyway since it's a one-line,
   zero-risk fix and the exact §6.1 shape) both did `inherit CLOTH;`
   without `#include <armor.h>` (where `CLOTH` is `#define`d). Every
   sibling cloth file in the same directory has the include; these two
   were just missing it. Fix: add `#include <armor.h>` above the
   `inherit`.
   - `cloth.lpc` also had a second, independent bug on the same pass:
     `set("value",);` — a call with a dangling comma and no second
     argument (`Wrong number of arguments to 'set', expected: 2, got:
     1`). Every sibling cloth file's equivalent line reads
     `set("value", 800)`-shaped; fixed to `set("value", 0)` (a sensible
     zero default for what is explicitly a base/template object, per its
     own empty `set_name("", ...)` treatment elsewhere in the same
     `create()`).

5. **Driver-API misuse: missing `objectp()` guard after a `move()` call
   that can legitimately self-destruct its argument — matches AGENTS.md
   §7's "missing objectp()/stringp() checks" class, closest existing
   relative is §7.25's shape (a call that can legitimately fail/vanish,
   with no guard on the caller side)**. `cmds/verb/drop.lpc:57`'s
   `do_drop()` calls `obj->move(environment(me))`, checks only the
   integer return value, then unconditionally calls further methods
   (`obj->is_character()`, `obj->query("unit")`, `obj->value()`) on the
   same `obj` reference. `d/menpai/wuliang/npc/obj/sword.lpc`'s own
   `move()` override (a soulbound-weapon "剑在人在，剑亡人亡" mechanic)
   legitimately `destruct(this_object())`s itself and returns `1`
   (success) when dropped outside a valid ownership context — a fully
   intentional, working design (see `sword.lpc:33-52`), but `do_drop()`
   has no way to know that and dereferences the now-destructed `obj`
   immediately after. **Reproduced live**: `drop sword` (as a disciple
   standing in the death realm, where the sword's ownership check fails)
   printed the correct in-fiction "剑转眼间断成了数块，不见了。" message,
   immediately followed by an uncaught `*Bad argument 1 to EFUN
   call_other() Expected: object, string, array, Got: int(0)` runtime
   error (visible in `log/runtime`), aborting the rest of `do_drop()`
   mid-function.
   ```lpc
   // BEFORE:
   if (obj->move(environment(me))) {
     if (obj->is_character())
   // AFTER:
   if (obj->move(environment(me))) {
     // obj->move() can legitimately destruct obj as a side effect (e.g.
     // a bound/soulbound weapon shattering when dropped outside its
     // valid owner context -- see d/menpai/wuliang/npc/obj/sword.lpc's
     // own move() override) -- guard before touching it further.
     if (!objectp(obj)) return 1;
     if (obj->is_character())
   ```
   This is a general, call-site-independent fix (guards the ONE shared
   `do_drop()` used by every `drop` invocation, including the `amount`-
   split and `drop all` paths), not specific to the sword.

6. **Silent-stranding `move()` to nonexistent content in the death/
   reincarnation flow — same shape as AGENTS.md §7.18 (hardcoded path
   into content missing from THIS archive), new file/lineage instance**:
   `d/place/death/npc/chacha.lpc`'s `death_stage()` — the 判官 NPC that
   finalizes reincarnation — picks a `random(3)` destination for a newly
   -reincarnated ghost. Only branch `case 0`
   (`/d/city/yangzhou/kuixing_ge`) resolves to real content in this
   trimmed archive; `case 1` (`/d/map/zhongyuan/nanmen` — `/d/map/`
   doesn't exist anywhere in this archive) and `case 2`
   (`/d/city/lanzhou/guangchang` — `lanzhou` doesn't exist either) both
   silently fail. Confirmed the failure mode live (via `goto` on the
   admin account, which has its own explicit existence check and
   reported "没有这个玩家、生物、或地方" without moving): `move()`'s own
   implementation (`system/feature/base/move.lpc:74-80`) already
   gracefully `notify_fail()`s rather than crashing for a target that
   doesn't exist at all (as opposed to one that exists but fails to
   compile, which throws) — but `chacha.lpc` never checks `move()`'s
   return value, and `notify_fail()` from a `call_out`-driven context
   with no active command dispatch never surfaces to anyone. Net effect:
   2 out of 3 times, a reincarnating ghost's `ghost` flag gets cleared
   (`reincarnate()` already ran) but they're never actually relocated —
   permanently stuck in `阎罗大殿`, a death-realm-only room with (per
   `鬼门关`'s own room text) no way back to the living world through
   ordinary movement. Also checked the `"西域"`/`gaochang` special-case
   branch one line above — `/d/city/gaochang/center` doesn't exist
   either, but confirmed (via `logind.lpc`'s own `start_rooms` array,
   where the `gaochang` entry is commented out) that no character in
   this archive can ever actually be tagged `hydra/desert/from`==`"西域"`
   in the first place, so that branch is already-dead and left alone.
   ```lpc
   // BEFORE:
   switch (random(3)) {
     case 0: ob->move("/d/city/yangzhou/kuixing_ge"); break;
     case 1: ob->move("/d/map/zhongyuan/nanmen"); break;
     case 2: ob->move("/d/city/lanzhou/guangchang"); break;
   }
   // AFTER: (both dead branches repointed to the one confirmed-live
   // destination already used by case 0, matching AGENTS.md #7.18's
   // fix pattern -- see the file for the explanatory comments kept in
   // place)
   switch (random(3)) {
     case 0: ob->move("/d/city/yangzhou/kuixing_ge"); break;
     case 1: ob->move("/d/city/yangzhou/kuixing_ge"); break;  // was the dead /d/map/ path
     case 2: ob->move("/d/city/yangzhou/kuixing_ge"); break;  // was the dead lanzhou path
   }
   ```
   **Verified live end-to-end after the fix**: dropped all items (a
   prerequisite the same NPC enforces earlier in its dialogue), re-
   entered `阎罗大殿`, sat through 判官's full multi-stage dialogue, and
   was moved to `小秦淮酒楼` (a real, live room) successfully.

7. **Operator-precedence + typo bug, NOT observed live (dead code given
   current data, fixed proactively since it's a trivial and clearly
   unintentional pair of mistakes)**: `cmds/skill/study.lpc:127-128` —
   `if (bonus = book["bonus_jibie"] > 0) me->improvve_jibie(...)`. Two
   independent bugs stacked: `=` binds looser than `>` in this grammar,
   so `bonus` was being assigned the BOOLEAN result of the comparison
   (0 or 1) rather than the actual configured bonus amount (contrast
   with the parallel `bonus_jilei` branch a few lines up, which correctly
   does `bonus = book["bonus_jilei"]` then checks it); and
   `improvve_jibie` (double-v) is a typo for the real function
   `improve_jibie` (defined in `system/feature/char/skill.lpc:351`, used
   correctly by name everywhere else including 3 lines below in the same
   function's `else` branch) — an `Undefined function` error waiting to
   happen the moment it's ever reached via `->`. **Not reachable with
   current data**: grepped every book/skill data file in this archive
   and none of them ever set `"bonus_jibie"` to a positive value, so
   `book["bonus_jibie"] > 0` is always false and this exact branch never
   executes today — but the fix is one-line-obvious and harmless, so
   applied proactively rather than left as a landmine for the first book
   that ever sets that key.
   ```lpc
   // BEFORE:
   if (bonus = book["bonus_jibie"] > 0)
     me->improvve_jibie(book["name"], bonus);
   // AFTER:
   if ((bonus = book["bonus_jibie"]) > 0)
     me->improve_jibie(book["name"], bonus);
   ```

8. **Cosmetic, not fixed (too minor/ambiguous to count as a real
   programming bug, documented only)**: `cmds/comm/help.lpc`'s `main()`
   does `cat(HELP_DIR + "topics")` when called with no argument;
   `help/user/topics` doesn't exist anywhere in this trimmed archive
   (genuine content gap, not a conversion bug). `secure/sefun/file.lpc`'s
   `cat()` is `write(read_file(file))`; `read_file()` of a missing file
   returns int `0`, and `write()` coerces that to the literal string
   `"0"` — so a bare `help` with no topic just prints `0` to the player
   instead of a message like "没有说明文件". Left as-is per the "don't
   fabricate missing content" policy (the fix would require deciding
   what a proper topics index should say, a content question) — but
   flagged here in case a future content pass wants to add a real
   `topics` file, at which point this stops mattering entirely.

### Observed, not fixed (design/content, out of scope per this pass's corrected instructions)

- **The sect's "mirror match" isn't actually safe**: `d/menpai/wuliang/
  npc/laogao.lpc`'s `accept_fight()` has a friendly-dialogue branch for
  attackers whose `family/family_name` matches the sect ("好吧，我就陪你
  练几招吧，看好了哦。") that reads exactly like the "safe sparring
  mechanism" AGENTS.md §10.7's checklist asks testers to find and use
  before risking a real fight — but the branch doesn't cap damage,
  disable death, or use any different combat resolution than a genuine
  fight; it's real combat with friendlier flavor text only. Used it as
  directed by the checklist (attacker was a same-sect disciple,
  `qinfenglong`) and it killed a fresh, unarmed, zero-`combat_exp`
  character in a single hit (老高 immediately wielded his real sword and
  landed a killing blow: "你没能躲开，只听见你一声惨嚎，悬泉剑已在你右肩
  划出一道深可及骨的可怕伤口！！" → death). This is internally consistent
  (the code does exactly what it's written to do, consistently) and
  matches the exact "a 'safe' fight sparring mechanic that isn't
  perfectly safe" example the orchestrating session explicitly called
  out as NOT in scope — documented, not touched.
- **A ghost can leave the death realm without ever reincarnating**:
  while chasing Bug 6 above, `qinfenglong` (still flagged `ghost`, in
  `阎罗大殿`) got picked up by an unrelated, already-existing safety net
  — `system/feature/user/alias.lpc`'s `process_input()` checks
  `!environment(this_object())` on every keystroke and teleports a
  player with no environment into `VOID_OB` (`clone/misc/void.lpc`,
  "天涯海角，梦的尽头", with a working `out` exit to a real room). The
  room the character had been standing in was most likely reaped by this
  archive's ordinary idle-object cleanup during an unrelated multi-
  minute admin digression, not anything wrong with the death-realm code
  itself — the safety net caught it and worked exactly as designed (a
  live, escapable room, not a dead end). Net observable effect: the
  character ended up back in the living city, walking around, while
  still internally flagged as a `ghost` (never went through `chacha.lpc`
  at all this time) — an odd-looking but non-crashing state that self-
  resolved the next time `阎罗大殿` was re-visited and the reincarnation
  dialogue actually completed. Not chased further (unclear whether this
  is "a bug" or just an unusual but harmless interaction between two
  independently-correct systems); documented for anyone who sees a
  `【 鬼 魂 】` player wandering a normal city room and wonders why.

### Driver segfault (corroborates AGENTS.md §10.8, new immediate mechanism)

~26 minutes into this session, during ordinary ambient play (not
triggered by a specific command — the crashing call stack is entirely
inside the driver's own periodic `reset()` sweep, `backend.cc`'s
`look_for_objects_to_swap()`), the native driver process died outright
with a SIGSEGV. **`debug.log` showed absolutely nothing** — identical to
both prior §10.8 occurrences (`xianjianchuanqi`, `shiji`), reinforcing
that this class of failure is genuinely undetectable by log-watching
alone; only the redirected driver stdout (captured per the standing
recommendation from that section) had anything.

Captured backtrace (driver build `fluffos-20260721-25c87bbc`):
```
backend_run_one_gametick -> look_for_objects_to_swap -> reset_object
  -> safe_apply(APPLY_RESET) -> apply -> apply_low -> eval_instruction
  -> f__call_other -> apply -> apply_low [SIGSEGV]
src/vm/internal/apply.cc:201, in apply_low:
  while (ob->shadowed && ob->shadowed != current_object &&
         (!(ob->shadowed->flags & O_DESTRUCTED))) {   // <- crash here
```
This is a **different immediate C++-level mechanism** than either prior
occurrence (both of those were `FATAL: Object ... ref count 0, but not
destructed` internal-consistency aborts from `free_svalue()`; this one
is a raw segfault dereferencing `ob->shadowed`, apparently a dangling
pointer, while a `reset()`-triggered `call_other()` walks the shadow
chain) — but the same broad category (driver-level object-lifecycle
memory corruption surfacing later, during unrelated background
activity, as a process-ending crash). Not mudlib-fixable; not root-
caused to a specific LPC source pattern (the corruption, whatever it
was, had already happened before this crash — the reset cycle just
happened to be the next code to touch the bad pointer). Driver was
restarted (fresh PID, confirmed via `readlink -f /proc/<pid>/cwd`
before doing anything with it) and testing continued; no second
occurrence in the remaining ~30 minutes of this session. This is now
the **third** independent occurrence of "background driver processing
crashes the whole process, invisible to `debug.log`" across three
unrelated libs/lineages — per §10.8's own escalation note, worth
promoting to a driver-level (`~/src/fluffos`) investigation rather than
continuing to treat each new occurrence as a per-lib mudlib finding, if
this keeps recurring.

### lpcc sweep

Baseline (start of this pass) 1323/1395 pass (94.8%). After this pass's
fixes: **1331/1395 pass (95.4%)**. Remaining 64 failures are the
already-documented long tail: genuinely corrupted/non-LPC content under
`d/menpai/wuliang/east/` (plain-text poem fragments, garbled binary, a
"By XO team... since 1997 April." credits blob — not LPC source at all,
pre-existing archive corruption, not a conversion bug, and this whole
subtree turns out to be unreachable anyway per the map-connectivity gap
noted above), missing daemons (`TASK_D`, `BET_D`, `SendToUser`, `NBUG`)
consistent with this "mini" archive's documented trimming, and a handful
of dead/superseded duplicate files (`system/menpai/wuliang/zuo_zimu.lpc`
etc. — confirmed via grep to be shadowed by a live `npc/`-subdirectory
version and never referenced by any room's `objects` mapping, left
alone per the project's "leave dead code alone" convention) — not
triaged further as none are live/reachable.
