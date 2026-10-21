# mhxy.rar → `mhxy`

- Archive: `archives/mhxy.rar` (18.8MB — "梦幻西游"/"Fantasy Journey to
  the West", 青岛站/Qingdao station, running since 2002-01-15). Same
  西游记 lineage as archive #15 (xyj2000f) — shares the
  age-gate question, `convertd.lpc` Greek-table typo shape, etc.
  **Not a byte-duplicate of `梦幻西游2002版.rar` (a separate archive in
  this collection with the same game name)** — different snapshot,
  processed separately; cross-reference when that archive's turn comes.
- Mudlib root: nested at `梦幻西游2002版/mhxy/world/` (the archive's own
  top folder is a snapshot-dated Chinese name, then an `mhxy/` dir with
  Windows driver binaries + client-facing files, then `world/` is the
  actual mudlib). Config at `mhxy/config.mhxy`.
- Port: **40016**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, GB/BIG5 prompt (same legacy pattern as
`xyj2000f`), stats, age-gate question. Note: the BIG5 hint text
in the banner is mojibake (same shape as other libs — a BIG5-encoded
substring inside an otherwise-GBK file), cosmetic only.

## What was fixed

1. Encoding + `.c`→`.lpc`: 1506 refs auto-fixed, 99 angle-bracket `.c>`
   refs, and **304 local angle-bracket includes converted to quotes
   automatically** (`convert_lib.sh`'s generalized fix — by far the
   largest count seen yet, confirms this pattern is very common in the
   西游记/xiyouji lineage specifically). `static`→`nosave`: 104 files.
   Two files triggered a `grep: binary file matches` warning during the
   local-include conversion step (`d/lingtai/obj/yuanpinzhu.lpc`,
   `daemon/class/yaomo/xueshan/cuixin-zhang/cuixin.lpc`) — the script
   handled it gracefully and continued; not investigated further (not on
   the boot path).
2. `adm/daemons/convertd.lpc` — the SAME Greek-alphabet-table stray-
   trailing-backslash bug as `xyj2000f` (`"α\",` should be
   `"α",`, repeated ~45 times in this file specifically). **Gotcha this
   time**: this file has CRLF line endings, so the straightforward
   `s/\\"(,)?$/"\1/` fix from `xyj2000f` silently did nothing
   (sed's `$` anchors before the `\n`, not before a preceding `\r`) —
   needed `s/\\"(,)?\r?$/"\1\r/` to actually match. Worth remembering:
   **always check for a stray `\r` before concluding an end-of-line sed
   fix "did nothing" quietly** (0 change reported, no error) — CRLF
   content is common across this whole archive family.
3. `/u/feizei/log` (a wizard's personal log directory) was missing from
   the archive, causing repeated `Wrong permissions for opening file
   .../log for append` at boot (same shape as the missing-directory
   pattern documented for lib #3 — a nonexistent directory manifests as
   a permission denial, not ENOENT). Created it.

## Known remaining issues (documented, not fixed)

- 315 lpcc-sweep failures (of 11785, 97.3% pass) — not triaged further
  given time constraints; boot/login path unaffected.

## How to run

```
cd libs/mhxy
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40016 --timeout 10 --send "gb" --send "" --send "quit"
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

- **LPC formatter**: ran `format-corpus.mjs` across all 11785 `.lpc`
  files under `work/` — 11635 reformatted, 112 unchanged, 38 refused
  (token-mismatch safety gate, expected/fine on this size of legacy
  corpus, not investigated further).
- **Native retest against the freshly-rebuilt driver**: booted (this lib
  doesn't print a driver-level "Initializations complete" line the way
  some other libs' `master.lpc`s do, but a `debug.log` review + a live
  `mudclient.py` connection confirm it's up and fully responsive — a
  large 11785-file preload does take a little over a minute of CPU time
  and produces routine `Eval interrupted`/`Too long evaluation` traces
  from a couple of preload-time content-placement daemons walking large
  zones, all caught/non-fatal, same shape as ordinary mega-content
  preload noise, not new). Ran the **full** interactive flow (`gb`
  encoding select → age-gate `no` → `new` → English id → Chinese name
  → password ×2 → "SuperPassWord" secondary identity ×2 → email →
  webpage → ICQ → gender → an in-game gift/attribute-point wizard `9`/`y`
  confirm) with a real Chinese name (`秦风三` / id `qflibc`), reached the
  actual starting room (南城客栈), and confirmed `score` renders a
  complete, correctly-populated character sheet and `quit` exits
  cleanly. Zero fatal errors in `debug.log`. No regression from the
  reformat or the driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): boots cleanly (only
  the expected non-fatal preload warnings/errors — missing network
  daemon programs, `dns_master`/`ftpd`/`httpd` — same non-fatal shape as
  native). **Login is blocked by the documented `query_ip_number()`
  WASM limitation**, but via a different call site than the
  `sscanf`-based site-ban pattern already known from `rzrmud`/`bxsj`:
  `logind.lpc`'s `encoding()` calls `"/adm/daemons/ipd"
  ->seek_ip_address(query_ip_number(ob))` to look up a friendly
  "connecting from" description; under WASM `query_ip_number()` returned
  an **empty string** for the console connection (confirmed directly
  from the driver's own error trace: `seek_ip_address("")`), and
  `ipd.lpc`'s `seek_ip_address()` does `user_ip = explode(ip, ".")` then
  unconditionally indexes `user_ip[1]` — with an empty IP, `explode`
  yields a single-element array, so `user_ip[1]` throws `*Array index
  out of bounds`, uncaught, right in the middle of `logon()`'s encoding
  callback. This aborts the rest of the login sequence for that
  connection, leaving it in a bare command loop that replies "什么？" to
  everything instead of ever reaching the id prompt. **This is the same
  class of driver-level WASM gap the project already documents (an
  IP-format-dependent code path breaking on a malformed/empty
  `query_ip_number()` under WASM), not a mudlib bug** — the identical
  code path works perfectly natively (confirmed above, real Chinese-name
  registration completing end-to-end). Not patched, per the standing
  policy against fixing WASM-only driver gaps in the mudlib. Status:
  **boots under WASM; login blocked by a query_ip_number()-under-WASM
  limitation** (different trigger site than the already-documented
  `sscanf`-ban-check shape, same root cause).

## WASM-enablement pass (2026-07-23): loopback-allow + throttle bypass + admin seeding

Gates patched (loopback = `127.0.0.1`, any `127.*`, or an empty/malformed
non-dotted-quad string, which is what current WASM builds return):

- `adm/daemons/band.lpc` — `is_banned()`, `create_char_banned()`,
  `is_strict_banned()` short-circuit return 0 for loopback;
  `allow_multi_login()` returns 1000 (effectively unlimited) for loopback.
- `adm/daemons/logind.lpc` `encoding()` — new `local_conn` flag; the
  `!ip_name` destruct and the "Non_number" character-scan destruct are
  skipped for loopback/malformed IPs (this was the WASM login blocker).
- `adm/daemons/logind.lpc` (~line 567) — the 40-second "刚退出就想进来"
  quick-reconnect throttle now exempts loopback (kickout punishment timer
  kept — game design).
- `adm/daemons/ipd.lpc` `seek_ip_address()` — returns "本地连接" for
  loopback/short IPs instead of crashing on `explode(ip,".")[1]` (this was
  the documented WASM `Array index out of bounds` blocker).
- `adm/daemons/securityd.lpc` `match_wiz_site()` — loopback always passes
  wizard site restriction.
- No `uptime()` startup gate exists in this lib (checked; only cosmetic
  uses in httpd/cmwhod).

Admin account: `fluffos` / `Mud@2026` (SuperPassWord also `Mud@2026`),
Chinese name 浮浮, granted `(admin)` via `/adm/etc/wizlist` (file also
normalized from CRLF to LF; previously the CR was absorbed into the parsed
level string). Verified: registration via real flow, re-login, and
`update /d/city/kezhan.lpc` succeeds. Saves at `data/login/f/fluffos.o` +
`data/user/f/fluffos.o` (not gitignored). Fresh normal registration
re-verified end-to-end (test char removed); debug.log clean.

### Fail-closed retrofit (2026-07-24)

The loopback carve-out above was originally written to ALSO treat any
empty/non-string/unparseable IP as trusted-local (a fail-open pattern,
written defensively against an older WASM `query_ip_number()` bug that is
now fixed upstream). Corrected to strict loopback only (`"127.0.0.1"`,
`"::1"`, or a `"127."` prefix) in `band.lpc` (×4), `securityd.lpc`'s
`match_wiz_site`, `ipd.lpc` (now falls back to an "未知地区" placeholder
for unparseable input instead of "本地连接"), and `logind.lpc`'s
`local_conn` flag and reconnect throttle. Re-verified the loopback path
still logs in, looks, and quits cleanly after tightening.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

Native driver (`build-debug`), one continuous playthrough per the §10.7
methodology, following `libs/bxsj/NOTES.md`/`libs/xiyouji/NOTES.md`'s
worked examples. Read `doc/help/specials/newbie` in full first — it named
the starting inn (南城客栈), the `answer 拜师`/`apprentice`/`learn ...
from ...` sect-join and skill-learning idiom, the `fight`-vs-`kill`
safety distinction, and a rough "who's weak enough to spar" heuristic
(judge by name: 小学童/小丫环/etc.). This lib shares the `d/jjf`
将军府-sect-entrance shape with `xiyouji`'s already-documented §7.17 bug
(same lineage, noted in this file's own header), so that room got
specific attention — and did turn out to have a live crash, though a
different root cause than §7.17's (see below).

**Test characters** (all kept as playthrough evidence):
- id `qinfeng`, Chinese name 秦风扬, password `Test1234`, male — the main
  playthrough character. State at end of session: apprenticed to 秦富
  (Qin Fu, 将军府/General's-Mansion sect, `将军府第四代弟子`), learned
  `force`(内功心法, organic teacher path) and `unarmed`(扑击格斗之技,
  gained from a real fight), survived a `fight` against a `little jap`
  NPC (took real damage, HP bar showed `伤残`/crippled, did not die),
  slept and woke cleanly in `/d/jjf/guest_bedroom`, quit cleanly at
  least twice (dropping its starting 粗布衣 each time, same
  item-drop-on-quit shape `xiyouji`'s NOTES.md documents for this
  lineage), and was reconnected into successfully many times, including
  after real wall-clock gaps and after simulated unclean (RST) network
  drops. Saves: `work/data/user/q/qinfeng.o`, `work/data/login/q/qinfeng.o`,
  plus `work/data/zhangmen/zhangmen_qin_qiong.o` (the sect-teacher NPC's
  own save record, updated by the successful `apprentice` — concrete
  on-disk evidence the fixed sect-join path persists correctly end to
  end).
- id `shenqing`, Chinese name 沈清扬, password `Test5678`, female — a
  second fresh registration used to confirm the fixes work for the other
  gender branch and from a clean state. Reached 南城客栈, `score`
  rendered correctly, quit cleanly. Saves: `work/data/user/s/shenqing.o`,
  `work/data/login/s/shenqing.o`.
- id `cehsheng`, Chinese name 程星辰, password `Test9999`, male — a third
  fresh registration used as the final post-`.C`-rename regression check
  (see bug 5 below). Reached 南城客栈, `score` correct, quit cleanly.
  Saves: `work/data/user/c/cehsheng.o`, `work/data/login/c/cehsheng.o`.

### What was tested and confirmed working

- **Registration**: three independent real Chinese names, both genders,
  full flow (`gb` encoding choice → student age-gate `no` → `new` →
  English id → Chinese name → password ×2 → SuperPassWord ×2 → email →
  webpage → ICQ → gender → gift-point wizard `9`/`y` confirm), landing in
  `南城客栈` every time.
- **Exploration**: read room `.lpc` source to plan routes (exits aren't
  always the ones the room description implies) — `南城客栈` →
  `朱雀大街` → `十字街头` → `青龙大街` ×2 → `answer 拜师` → `将军府` →
  `练武场`(front_yard, sandbags/秦富) → `练武场`(front_yard2,
  logs/pits/秦叔宝's actual sect-entrance NPC) → `正厅`(main hall, 秦琼)
  → `客房`(guest_bedroom) → `兵器架`(jjf_bingqi) → `玄武大街`
  (xuanwu-n0/n1) → `天监台`. Room descriptions, exits, and day/night
  flavor text all correct throughout.
- **Sect join**: `answer 拜师` at the gate NPC (秦安) unlocks entry;
  `apprentice qin fu` in `front_yard` (NOT the gate) succeeds
  ("秦富决定收你为弟子...恭喜您成为将军府的第四代弟子"), confirmed via
  `score`'s `师承` field. This is the exact room whose first-ever compile
  crashed pre-fix (bug 1 below) — re-verified post-fix across several
  fresh-driver-restart boots with zero recurrence.
  **`d/jjf/front_yard2.lpc`'s `zhangmen`-shaped NPC now shows its
  correct title (`大唐天下兵马大元帅 朝廷兵马大元帅(Zhang men)`) on the
  very first visit of a fresh boot**, not the corrupted-stray-`0` shape
  §7.17 documents for `xiyouji`.
- **Skill learning (organic teacher path)**: `skills qin fu` lists the
  sect's 9 techniques; `learn force from qin fu` succeeds
  ("你听了秦富的指导，似乎有些心得...你的「内功心法」进步了！"),
  confirmed via `skills`.
- **Combat**: found no literal training-dummy `accept_fight()`-mirror
  object actually placed in any live room (`d/city/obj/muren.lpc` exists
  but isn't referenced from any room's `objects` list — dead content,
  not investigated further, out of scope); used `/d/city/npc/japan2.lpc`
  instead (`combat_exp = random(200)`, `init()`'s own auto-attack is
  commented out — passive, safe, explicitly room-`no_fight`-aware in its
  own dead code, confirms the author intended it as a low-stakes
  sparring target). `fight jap` in `玄武大街`(xuanwu-n0, NOT `no_fight`)
  worked correctly: combat opened, both sides exchanged blows over
  several heartbeat ticks, character took real damage (`气血` bar
  degraded to `伤残`) and survived; fleeing by moving rooms mid-fight
  (per `help combat`'s documented `fight` semantics) also worked cleanly.
  `南城客栈`(kezhan) is a deliberate `no_fight` safe zone by design
  (confirmed in source, `set("no_fight", 1)`) — not a bug, matches the
  MOTD's own "本站对新手将提供适当的保护" newbie-protection claim.
- **Sleep/wake**: `sleep` in `/d/jjf/guest_bedroom` (`if_bed`+
  `sleep_room`) → `disable_player()` → `wakeup1()` call_out fires later
  → `enable_player()` called again on the SAME (already-`living()`)
  object — this is the exact reentrant-call shape bug 1 guards against,
  and re-verified LIVE that the fix does NOT block this legitimate path:
  woke up correctly ("你一觉醒来，只觉精力充沛"), and `look`/`score`/`i`
  all worked immediately after (proving `enable_player()`'s
  `delete_temp("disabled")` genuinely ran, not silently skipped).
- **Shop**: `list` at the inn's 店小二 renders the full price list
  correctly; `buy jiudai from xiao er` correctly rejects with
  "你的钱不够" — **not fully verified live**: a fresh character starts
  with zero gold, and no gold-earning path was pursued in the time
  budget, so an actual successful purchase was never completed. Stated
  explicitly rather than silently skipped, per §10.7 rule 6.
- **Death/respawn**: **not verified live** — reaching lethal combat
  against a deliberately outmatched NPC was out of the time budget for
  this pass; the one real fight conducted (see above) was won safely.
  Stated explicitly per §10.7 rule 6.
- **`quit`**: clean both times used, drops the starting 粗布衣 (matches
  this lineage's established item-drop-on-quit design per `xiyouji`'s
  NOTES.md — not re-litigated here), `debug.log` grepped immediately
  after each `quit` and stayed clean (no new `执行时段错误`/`Too deep
  recursion`/`error:` lines) — the exact check the §7.16 `bxsj` bug
  taught this project to never skip.
- **Unclean (net-dead) disconnect + reconnect**, tested twice: once
  reconnecting within a couple seconds of an RST-forced socket close
  (`SO_LINGER`+0, closer to a real network drop than a plain
  `socket.close()`), once waiting ~35 real seconds first (past this
  lib's own internal 15-second `net_dead()`→`do_net_dead()` mark-as-dead
  delay, well inside its 600-second `NET_DEAD_TIMEOUT`/`user_dump`
  window). Both times: `debug.log` stayed completely clean through the
  disconnect, the wait, AND the reconnect, and the reconnect landed the
  character back in a fully valid, explorable room with all state
  (`score`/`i`/`skills`) intact — no void-room stranding, no crash.
  **This lib structurally does not have the §7.20 void-parking bug
  class at all**: read `obj/user.lpc`'s `net_dead()`/`do_net_dead()`/
  `reconnect()` — unlike the ES2/`xiyouji`-lineage shape §7.20 documents,
  this lib's `net_dead` handler never `move()`s the player anywhere
  (no `VOID_OB`/temporary holding room mechanism exists at all); it just
  disables the heart_beat and schedules a delayed `user_dump()` while the
  player object stays exactly where it was, so there's no location to
  restore and nothing for a broken `reconnect()` to fail to do. Confirmed
  `->reconnect(` IS actually called from the login flow
  (`adm/daemons/logind.lpc:1083`), unlike the "defined but never called"
  flavor §7.20 also warns about. Worth recording as a clean bill of
  health on this specific bug class, checked (not assumed) via both
  source read and live reproduction.
- **Reconnect after a clean `quit` + a real wall-clock gap** (100
  real seconds, not simulated): re-logged in as `qinfeng`, confirmed via
  `look`/`score`/`i`/`skills` that location, sect membership, learned
  skills, and inventory (the 粗布衣, re-donned by then per its own logic)
  all persisted correctly.
- **Mid-wizard-reconnect (§7.21 shape) — NOT tested live**: this lib's
  character-creation gift-point wizard (`0`-`3` reroll / `9`+`y` confirm)
  is short enough, and every registration in this pass was completed in
  one sitting before any disconnect test, that net-deading specifically
  mid-wizard was not attempted given the time budget. Stated explicitly
  as unverified rather than silently assumed safe.

### Bug 1: `enable_player()` reentrancy crashes a sect-entrance NPC's first-ever preload compile — matches AGENTS.md §7.19, but the DOCUMENTED FIX ITSELF would have been wrong here

**This matches the existing §7.19 class** (`enable_commands()`/
`enable_player()` called again on an already-`living()` object from
inside that object's own `init()` chain re-invokes `init()` while the
original call is still on the stack) — **not a new bug class** — but
applying §7.19's literally-documented fix (`if (living(this_object()))
return;`) would have introduced a real regression on this lib, which is
worth recording as an addendum to that section.

- **Symptom**: reproduces on PRELOAD ALONE, no player connection needed
  — `/tmp/mhxy_boot.log` (captured stdout of the very first boot attempt
  this pass, before any fix) shows, right after preload reaches
  `/d/xueshan/npc/zhangmen.lpc`:
  ```
  Too deep recursion.
  program: /feature/name.lpc, object: /d/xueshan/npc/zhangmen#114, file: /feature/name.lpc:14
  ```
  Same first-visit/first-compile-only timing sensitivity §7.17/§7.19
  document elsewhere in this catalog — the blamed file:line is whatever
  happened to be executing when the call-depth limit tipped over, not a
  fixed location.
- **Root cause**: `std/char.lpc`'s `setup()` (inherited by every
  character, NPC or player) unconditionally calls `enable_player()`
  (`feature/command.lpc`). Every one of this lib's `d/*/npc/zhangmen.lpc`
  sect-entrance NPCs (9 copies, one per sect, same shape as `xiyouji`'s
  documented family) calls `setup()` twice: once from its own `create()`
  (line 29, the legitimate call), and again from its own `init()` (line
  55, `me->setup();`, AFTER `create_identity()`/`reset_me()`/`restore()`/
  `fully_recover()` have already run) — a redundant call with no
  apparent purpose beyond "make sure everything's set up," but on this
  driver it re-invokes `enable_commands()` on an object the driver
  already knows is `living()`, which re-triggers that object's own
  `init()` **while the original `init()` call is still on the stack** —
  genuinely reentrant, repeating until `Too deep recursion.` aborts it.
- **Fix, and why the naive `living()` guard is WRONG on this lib
  specifically**: guarded `enable_player()` itself (the shared choke
  point) with a dedicated `nosave private int in_enable_player_now;`
  reentrancy flag — set at entry, checked before doing anything, cleared
  on the one exit path. **Deliberately did NOT use
  `if (living(this_object())) return;`**, which is what §7.19 literally
  prescribes and what an earlier draft of this fix used, until a
  targeted regression test caught the problem: `disable_player()` (same
  file, `feature/command.lpc`) calls `disable_commands()` immediately
  followed by `enable_commands()` again — its own comment explains why
  ("enable command again so this object would be marked living again...
  block command in alias.c instead of here"). That means `living()` is
  **already true** across every one of this lib's real disable/re-enable
  cycles: `feature/damage.lpc`'s unconscious→`revive()`,
  `cmds/std/sleep.lpc`'s sleep→`wakeup1()`/`wakeup2()`, and several
  disguise-item flows (`leaf.lpc`/`baoyi.lpc`/`yi.lpc`/`clloth.lpc`/
  `jia.lpc`, all `do_enable_player()` command handlers). A
  `living()`-gated guard would have SILENTLY NO-OPED every one of those
  legitimate re-enables — in particular skipping `delete_temp("disabled")`,
  which is what actually lets a player type commands again — while still
  blocking the one pathological case it was meant to catch. Caught this
  BEFORE shipping it by grepping every `enable_player(` call site (29
  hits across the lib) and specifically tracing the sleep/wake and
  unconscious/revive flows, then live-testing both end to end (see
  "What was tested" above) with the corrected reentrancy-flag version.
- **Verified**: reproduced live pre-fix (see the crash log above, from
  the very first boot of this pass); post-fix, re-tested via three
  separate fresh `driver` restarts with zero recurrence (`grep -a
  "recursion\|Too deep" log/debug.log` empty every time), the
  `front_yard2` sect-entrance room's NPC title renders correctly on
  first visit (not the corrupted-`0` shape), and the sleep/wake +
  unconscious-adjacent `enable_player()` call sites were confirmed still
  functional (see "What was tested"). **Scope**: the fix is at the
  shared `enable_player()` choke point, so it protects all 9 of this
  lib's `zhangmen`-shaped sect-entrance NPCs (`d/jjf`, `d/nanhai`,
  `d/sea`, `d/xueshan`, `d/death`, `d/lingtai`, `d/moon`,
  `d/qujing/wudidong`, `d/wusheng`, plus several more per `find . -iname
  zhangmen*`) regardless of individual verification — only the `d/jjf`
  (将军府) and `d/xueshan` (雪山, the one that happened to crash first
  during preload) instances were directly walked to/observed live.
- **File:line**: `libs/mhxy/work/feature/command.lpc` — new
  `in_enable_player_now` declaration + guard around `enable_player()`
  (function starts at what was line 119, now offset by the added
  comment block). Crash site was `libs/mhxy/work/d/xueshan/npc/zhangmen.lpc`
  (structurally identical to `libs/mhxy/work/d/jjf/npc/zhangmen.lpc:35-56`,
  the copy actually walked to live).

### Bug 2: `std/room.lpc` `reset()` reentrancy — same shape as AGENTS.md §7.17, applied proactively as defense in depth

`std/room.lpc`'s `setup()` calls `this_object()->reset()` synchronously
as the last step of every room's `create()` (line ~210, now ~223), and
`reset()` only marks its NPC-population bookkeeping done on its very
last line (`set_temp("objects", ob)`) — the identical structural shape
§7.17 documents for `xiyouji`. Not independently reproduced as the
proximate cause of any crash THIS pass (bug 1's `enable_player()` guard
alone closed every reproduction attempted), but the underlying
reentrancy hazard is real and lib-wide (every room inherits
`std/room.lpc`), so applied the same `nosave int resetting_now;` guard
`xiyouji`'s fix uses, at the top of `reset()` and cleared on both return
paths. Confirmed inert for the normal case: re-tested several
multi-NPC rooms (`南城客栈`/kezhan with 4 NPCs, `朱雀大街`/zhuque-s1,
`练武场`/front_yard and front_yard2) after the fix and saw identical,
correct NPC population every time. **File:line**:
`libs/mhxy/work/std/room.lpc:10-19` (declaration), `:44-47` and `:70-73`
and `:113` (guard entry/both exits).

### Bug 3: absolute path in angle-bracket `#include` — matches AGENTS.md §6.1 exactly

`d/obj/books-nonskill/book-qujing.lpc:4`: `#include </d/qujing/obstacle.h>`
— an absolute path inside angle brackets never resolves on this driver
(the `<>` resolver doesn't special-case absolute names), so the file
failed to compile at all (`Cannot #include /d/qujing/obstacle.h` cascading
into `Undefined variable 'obstacles'`). This item is carried by
`/d/city/npc/jieding.lpc` (西行游客/疥顶小僧, a wandering-monk NPC placed
in `朱雀大街`, one hop west of the starting inn — encountered on this
pass's very first exploration move), whose own `create()` does
`carry_object("/d/obj/books-nonskill/book-qujing")` — crashing with
`*No program in object 'book-qujing'!` the first time ANY player walks
west out of `南城客栈` on a fresh boot.

- **Fix**: `#include "/d/qujing/obstacle.h"` (quoted). Swept the whole
  lib case-insensitively for the same shape
  (`grep -rniE '#include\s*<\s*/'`) — this was the only instance.
- **Verified**: pre-fix, reproduced live (`debug.log` showed the
  compile errors + the runtime `No program in object` crash, blamed
  `/std/char/npc.lpc:14`'s `carry_object()`, called from
  `jieding.lpc:60`'s `create()`, called from the room's `reset()`/
  `make_inventory()` chain — same "first-ever compile aborts the room's
  reset() partway" shape as bugs 1/2, just via a different mechanism: a
  genuinely broken dependency rather than reentrancy). Post-fix,
  re-walked `南城客栈`→西→`朱雀大街` on three separate fresh-boot
  sessions; `疥顶小僧` now appears correctly with no crash.

### Bug 4: `tell_room()` 2-arg exclude defaults to raw `int 0` — matches AGENTS.md §7.12 exactly

`adm/simul_efun/message.lpc`'s `tell_room(mixed ob, string str, object
*exclude)` passes `exclude` straight into `message("tell_room", str, ob,
exclude)` — when called with only 2 arguments (the overwhelmingly common
case; grep shows dozens of call sites across the lib, including several
rooms' own `init()`-time welcome broadcasts), `exclude` is the driver
default `0`, and this driver's `message()` efun requires
`object`/`array` for its 4th argument, rejecting a bare `int`.

- **Symptom**: `/d/city/chatroom.lpc`'s `init()` (line 48) calls
  `tell_room(environment(me), "...")` with no 3rd argument — crashes
  with `*Bad argument 4 to EFUN message()  Expected: object, array,
  Got: int(0).` on EVERY entry into the chat room (reproduced twice in
  one session: once for an NPC/wizard body already in the room, once for
  the player's own arrival), not first-visit-only like bugs 1-3.
- **Fix**: `message("tell_room", str, ob, exclude || ({ }));` — the
  documented §7.12 fix verbatim.
- **Verified**: pre-fix, reproduced live twice (`debug.log`, both hits
  traced to `chatroom.lpc:48`'s `tell_room()` via `command_hook()` →
  `go.lpc` → `move()`/`_move()` → the room's `init()`). Post-fix,
  re-entered `聊天室`(chatroom, reachable `south` from `南城客栈`) —
  clean welcome broadcast, no crash, `debug.log` stayed clean.

### Bug 5: 302 uppercase `.C` files never renamed to `.lpc` — matches AGENTS.md §4.2 item 7, a notably large instance

Not previously flagged in this lib's own "What was fixed"/"Known
remaining issues" sections despite being exactly the documented
`find work/ -name '*.C'` check. `find libs/mhxy/work -name '*.C'` found
**302** files across `clone/armor/`, `clone/bq/`, an entire side zone
(`d/newjob/longzhu/`, ~90 files: NPCs, weapons, armor, quest objects),
another entire zone (`d/youxia/`, ~50 files: rooms, NPCs, a `BAGUA/`
puzzle subdirectory), several `daemon/class/youxia/*` skill files (a
"游侠"/wanderer class's kungfu implementations), two wizards' personal
`clone/`/`wuqi/` staging directories (`u/tianlin/`, `u/valen/` — mirror
copies of each other), and scattered individual files elsewhere. Since
this driver's extensionless `load_object()`/`new()` resolution tries
`.lpc` then `.c` and never a literal `.C`, every one of these was
permanently unloadable — orphaned content, not merely "unconverted"
(290 of the 302 were already valid UTF-8 from an earlier bulk pass that
evidently used a case-sensitive rename glob; only 12 — all under
`u/{tianlin,valen}/clone/{HELL,LONGGONG,QIANG,MOON,SHUSHAN,JJF}.C` —
were still raw GB18030 bytes, confirmed via a per-file UTF-8 decode
check rather than assumed from the `.C` extension alone).

- **Live reproduction**: `/u/tianlin/obj/goldarmor.C` — a content-
  placement daemon (`adm/daemons/baoshi.lpc`'s `choose_baosi()`/
  `random_place()`, triggered from `/d/qujing/wudidong/npc/luyue.lpc`'s
  `create()`, itself triggered by ordinary zone preload) tried
  `carry_object("/u/tianlin/obj/goldarmor")` and got `*call_other()
  couldn't find object '/u/tianlin/obj/goldarmor'.` — caught, preload
  continued, but the intended treasure/equipment was silently never
  placed. This is the shape most likely to recur unpredictably during
  real play: any zone whose content-placement or shop-stocking daemon
  references one of these 302 files by its correct extensionless path
  gets a silent no-op instead of the intended item/NPC/room.
- **Fix**: `iconv -f GB18030 -t UTF-8` (verified success, no lossy-drop
  warnings) on the 12 still-GBK files, then batch-renamed all 302
  `.C` → `.lpc`. Checked BOTH traps before renaming: no
  `<same-basename>.lpc`/`.c` already existing at any of the 302 paths
  (so no §4.2-item-5-style stale-backup-promotion risk), and no literal
  `"...FOO.C"`-style hardcoded string references anywhere in the lib
  (`grep -rlE '"[^"]*\.C"'` — zero hits) — every real reference to these
  files is extensionless, so the rename alone fixes resolution with no
  further reference-path edits needed.
- **Verified**: pre-fix, reproduced live (see above). Post-fix, three
  separate fresh-driver-restart boots all show zero `goldarmor`-related
  errors and zero new compile failures anywhere in `debug.log`
  (`grep -a -c "执行时段错误"` stayed at the same pre-existing baseline
  count across all three boots — see "Known remaining issues," below —
  meaning the 302-file rename introduced no NEW failures). A full fresh
  registration + `look`/`score`/`quit` was re-run after the rename
  (character `cehsheng`/程星辰) with a clean result. **Not exhaustively
  content-tested**: given the scale (302 files across zones this
  playthrough never visited — `d/youxia/`, `d/newjob/longzhu/`, the
  游侠-class skill files), only the one live-reproduced instance
  (`goldarmor`) and the boot-clean/no-new-compile-error check were
  directly verified; the other 301 are fixed proactively by the same
  mechanical rename, consistent with this project's standing practice
  for large mechanical fixes, but a future pass through `d/youxia/` or
  `d/newjob/longzhu/` specifically would be the way to verify content
  correctness (not just loadability) for those zones.

### Confirmed NOT a bug (checked and ruled out)

- **§7.20 void-parking class**: structurally absent from this lib — see
  "What was tested" above. `obj/user.lpc`'s `net_dead()` never moves the
  player anywhere; `reconnect()` (actually called from
  `adm/daemons/logind.lpc:1083`, not merely defined-and-orphaned) only
  needs to clear flags and resume the heartbeat, since there's no
  location to restore in the first place.
- **`南城客栈`/`天监台`/`醉星楼` etc. rejecting `fight`**: `no_fight`
  zones by explicit design (newbie-protection inn, a scholarly
  observatory, a royal pavilion) — verified via source (`set("no_fight",
  1)`), not a bug.
- **Shop purchase rejecting a broke new character**: correct, expected
  behavior (`score` confirms 0 savings) — see "not fully verified live"
  above for what this means for purchase-flow coverage specifically.

### Known remaining issues (pre-existing, not fixed — out of scope for this pass)

Confirmed present in `debug.log` identically across every boot in this
pass (before AND after all the fixes above, i.e. unrelated to anything
touched here), all preload-time, all caught by the driver's own error
handler, none reachable from the login/registration/exploration path
this pass exercised:

- `/adm/daemons/emoted.lpc`'s `restore()` — `*restore_object(): Illegal
  mapping format while restoring emote.` on its own shipped save data,
  at `create()` time during preload.
- `/adm/daemons/questd.lpc`'s `spread_quest()`/`init_dynamic_quest()` —
  `*Bad argument 1 to EFUN call_other()` (passing `0` as a target),
  fired both once during preload and again from a live `cron.lpc`-driven
  re-trigger later in the same boot.
- A handful of `*Too long evaluation. Execution aborted.`/`*Can't catch
  eval cost too big error.` traces from `/adm/daemons/baoshi.lpc`'s
  `random_place()`/`choose_baosi()` and `/adm/daemons/myupdated.lpc`'s
  batch-recompile daemon walking large zones during preload — same
  "routine mega-content preload noise" shape this file's own
  "Re-verification pass" section (above) already documented.

Given none of these are on the player-facing path this pass exercised
and all are caught, they're recorded here for completeness rather than
chased down — consistent with this project's established practice of
not exhaustively fixing every preload-time diagnostic on a lib this
large (11785 `.lpc` files).

### Not verified live (explicit, per §10.7 rule 6)

- **Shop purchase completing successfully** — character never
  accumulated gold in the time budget; the rejection path (`list`/`buy`
  with insufficient funds) WAS verified. **Resolved in the 2026-08-20
  round-four pass** — see "深度功能测试第四轮" below (admin-granted money
  via the lib's own `clone`, real `buy`, price/receipt both verified).
- **Death and respawn** — the one real fight conducted was won safely;
  deliberately seeking out a lethal fight was out of scope for the time
  budget. **Resolved in the 2026-08-20 round-four pass** — real death via
  `kill` against a genuinely lethal NPC, full ghost/`death_stage`/revive
  flow completed live, no bugs found (see below).
- **Net-dead disconnect specifically mid the gift-point creation
  wizard** (the §7.21 shape) — every registration in this pass completed
  in one sitting before any disconnect test. **Resolved in the 2026-08-20
  round-four pass** — both a graceful and a real RST-forced disconnect
  mid-wizard reconnected cleanly (see below).
- **Content correctness of the other 301 `.C`→`.lpc` renames** beyond
  the one live-reproduced instance (`goldarmor`) — fixed proactively by
  mechanical rename, boot-clean confirmed, but not walked to in-game.
- **WASM re-verification** against these specific fixes — this pass was
  native-only per the task's stated scope; the existing "WASM build
  test" section above (from an earlier pass) is unrelated to what was
  found/fixed here and was not re-run.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

梦幻西游基础版（青岛）。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：和手足档案 mhxyqd（012-1）流程相同——GB/BIG5 选择→未成年人关卡（否）→管理员 id+密码→首次天赋/礼物画面（9 然后 y）→干净地进入"南城客栈"，quit 也干净（"浮浮(Fluffos)离开游戏了"）。

## 补充修复（来自对手足档案 mhxyqd 的深度测试）

mhxyqd（012-1，同一套 2002 年代码库的"青岛站"品牌分支）这轮的深度功能测试发现了两处这份档案（mhxy 本体）也逐字节共有的 bug：(1) `adm/daemons/logind.lpc` 的 `get_name()` 在接受玩家中文名字后有一行调试残留 `printf("%O\n", ob);`，会把原始物件引用（如 `/obj/login#123`）显示给每一个刚完成中文取名的新玩家——已删除，用真实驱动重新注册验证过（不再出现物件引用，直接进入密码设定）。(2) `d/death/npc/{b,bgargoyle,wgargoyle}.lpc` 的 `death_stage()` 都有 §7.68 那种把"角色永久离开"和"暂时不在场"混在一起的 `if (!ob || !present(ob)) return;` 写法，已按各文件自己的 5 秒重试间隔拆分成"暂时不在场则重试"。两处修复均直接照搬 mhxyqd 那轮已验证过的修法，本轮只做了格式化+编译+一次干净注册的快速复核，没有重新走完整的战斗/死亡流程（该流程已经在 mhxyqd 上完整验证过，两份档案这部分代码逐字节相同）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第三轮 / Deep functional test round three (2026-08-14, post driver-upgrade re-test)

Re-verification pass against the 2026-08-12 driver rebuild (upstream
PRs #1343/#1344) per this project's round-two re-test campaign. This
lib's last live pass was 2026-07-24 (the "round two" section above,
before the rebuild), so this is a fresh boot-and-play confirmation
against the current driver, not a repeat of that pass's full
exploration.

### Independently re-verified (grepped the actual code, not trusted from prose)

All five bugs from the 2026-07-24 pass, the two fixes borrowed from
`mhxyqd`, and the §7.68 revert are confirmed still present/correct:

- `feature/command.lpc`: `in_enable_player_now` reentrancy guard around
  `enable_player()` — present (declaration line 119, checked/set/cleared
  lines 150-191).
- `std/room.lpc`: `resetting_now` reentrancy guard in `reset()` —
  present (declaration line 22, guard lines 45-108).
- `d/obj/books-nonskill/book-qujing.lpc:4`: `#include
  "/d/qujing/obstacle.h"` — still quoted, not angle-bracket.
- `adm/simul_efun/message.lpc`'s `tell_room()`: `exclude || ({ })` fix —
  present (line 56).
- `find libs/mhxy/work -name '*.C'` — zero results, the 302-file rename
  held.
- `adm/daemons/logind.lpc`'s `get_name()` — no `printf("%O\n", ob);`
  debug leak; the function goes straight from the legal-name check to
  `ob->set("name", arg)` and the password prompt, matching the
  mhxyqd-borrowed fix. (Two ORPHANED copies of `logind.lpc` under
  `www/cgi-bin/` and `www/relative/` DO still carry the old
  `printf("%O\n", ob);` line — confirmed via grep that nothing in the
  live tree references either path; this lib has no httpd wiring
  reaching them, so left alone as genuinely dead code, not a live bug.)
- `d/death/npc/{b,bgargoyle,wgargoyle}.lpc`'s `death_stage()` — all
  three still have the original single-check
  `if (!ob || !present(ob)) return;` shape, no retry-`call_out` loop
  grafted back in. The §7.68 revert is intact.

### New checklist items checked this pass (not covered by 2026-07-24's pass)

- **`cmds/wiz/update.lpc`§7.106**: already has the guarded form
  (`environment(me) && (obj = present(file, environment(me))) &&
  interactive(obj)`) — no fix needed here, presumably shipped this way
  originally (this lib doesn't show up as vulnerable in the
  corpus-wide §7.106 sweep record).
- **`adm/simul_efun/file.lpc` — new §7.11-class fix applied.**
  `log_file()` was a bare `write_file(LOG_DIR + file, text)` with no
  `assure_file()` guard, despite `assure_file()` being defined 4 lines
  below it in the same file (unused by `log_file()` itself). `log/` is
  driver-recreated (gitignored), and several subdirectories `log_file()`
  targets don't exist on disk pre-boot — most notably `log/nosave/`,
  referenced by ~30 call sites including `master.lpc`'s own crash
  logger (`log_file("nosave/CRASHES", ...)`), several admin commands
  (`full`/`shutdown`/`purge`/`qiangpo`/`call`), gift-item objects
  (`cookie.lpc`/`giftbox.lpc`/`tang.lpc`), and `cmds/usr/quit.lpc`'s
  large-stat-gain audit log (gated behind high thresholds so not hit by
  ordinary play, but real for any long-lived character). Confirmed via
  driver source (`fluffos/src/packages/core/file.cc`'s `write_file()`)
  that a missing parent directory makes `fopen()` fail and the efun
  `error()`s — an uncaught throw, not a quiet return-0 — so this is a
  live crash risk, not cosmetic. Fixed with the project's standard
  `assure_file(LOG_DIR + file);` guard before the `write_file()` call,
  plus a one-line forward declaration (`void assure_file(string
  file);`) since `assure_file()` is defined textually after
  `log_file()` and this compiler needs one. Also fixed `cat()`'s
  `write(read_file(file))` → `write(read_file(file) || "")` (minor,
  cosmetic-only — `write(0)` just prints a literal "0" to the caller
  rather than crashing, confirmed via `print_svalue()`'s `T_NUMBER`
  case in the driver source — but a one-line fix matching this
  project's established convention for this file, see `kxkj`'s
  round-two pass for the same pairing). Compile-verified via a live
  `update /adm/daemons/logind` (which recompiles the whole simul_efun
  chain including `file.lpc`) — succeeded cleanly. **Not live-triggered
  this pass** (would need e.g. a real `master.lpc` crash or one of the
  gated `quit.lpc` thresholds to prove the pre-fix throw live) — fixed
  proactively on the strength of the driver-source read and the
  extremely well-established §7.11 precedent (10+ prior lineages), same
  verification depth this project uses for other mechanical §7.11
  instances.
- **`config.fluffos`'s `maximum evaluation cost`**: was `400000` — in
  the documented risky range (300000/700000 known to cause
  `enter_world()`/`make_body()` aborts on this project's debug driver
  build). Raised to `5000000`, this project's standard safe value. No
  eval-cost abort was actually observed pre-fix in this pass (boot and
  play were already clean), so this is a preventative fix per the
  standard checklist, not a reproduced-and-fixed live bug.
- `log_error()` (`adm/obj/master.lpc`) already has the standard severity
  gate (only broadcasts to the triggering player if one exists, skips
  broadcasting compiler warnings per the AGENTS.md §15w convention) —
  no fix needed.
- Scanned `logind.lpc` end to end for any other stray `printf("%O"` /
  raw debug leaks beyond the already-checked `get_name()` — none found;
  every other `printf`/`write` call in the file is legitimate
  player-facing banner/status text.
- `file_owner()` (§7.26, originally found and fixed ON this lib):
  re-confirmed the correct first-segment-capture version
  (`adm/simul_efun/object.lpc`) is the one actually wired into
  `simul_efun.lpc`'s `#include` chain; a second, still-buggy
  fixed-depth-3 copy exists at `adm/simul_efun/oo.lpc` but is NOT
  `#include`d anywhere — dead code, confirmed not a live risk.

### 现场验证 / Live verification

Native `build-debug` driver, launched from `libs/mhxy` per this file's
"How to run" section. **Boot: completely clean** — the entire
`/tmp/mhxy_boot.log` capture (1816 lines) contains nothing but routine
"Unknown #pragma, ignored" / "In file included from" preload noise;
zero eval-cost errors, zero new compile errors, and notably *cleaner*
than the 2026-07-24 pass's own boot (which logged non-fatal
`emoted.lpc`/`questd.lpc`/`baoshi.lpc` preload traces — those didn't
reproduce this run, consistent with them being incidental/order-
dependent preload noise rather than deterministic, not investigated
further since they're already documented as known-harmless).
`work/log/debug.log` stayed at **0 lines for the entire session** —
before, during, and after every test step below.

Connected via `scripts/tmux_mud.sh`, logged in as `fluffos`/`Mud@2026`,
landed in `南城客栈` with `目前权限：(admin)`. Verified REAL write
access (not just the login banner) via `update /adm/daemons/logind` —
"重新编译 /adm/daemons/logind.lpc：成功！" — which also compile-verified
this pass's own `file.lpc` edit (loaded via the same simul_efun
recompile chain).

Targeted spot-checks of the three highest-value original crash
triggers:

- `west` from `南城客栈` to `朱雀大街` — `疥顶小僧` (the book-qujing
  NPC, bug 3's original crash site) present, no crash.
- `south` from `南城客栈` to `聊天室` (bug 4's `tell_room()` crash site)
  — clean welcome broadcast ("热烈欢迎，普通百姓 浮浮(fluffos)来到梦幻
  西游聊天室！"), no crash.
- `goto /d/jjf/front_yard2` (bug 1's original crash site, the
  `将军府`/`jjf` sect-entrance `zhangmen` NPC) — correct title on load
  (`大唐天下兵马大元帅 朝廷兵马大元帅(Zhang men)`), not the corrupted
  shape; no reentrancy crash.

`quit` — clean, standard farewell banner, `debug.log` unchanged. Two
rapid reconnects (`fluffos`/`Mud@2026` each time) — both landed
correctly in `南城客栈` with `目前权限：(admin)` intact, `debug.log`
unchanged throughout.

### 进程与仓库卫生 / Process and repo hygiene

Driver killed by exact PID (`kill 1633949`, confirmed dead via `ps`),
never `pkill -f`. `git status --short libs/mhxy/` post-test showed four
incidental save-timestamp-churn files from the login/test cycle
(`data/login/f/fluffos.o`, `data/user/f/fluffos.o`,
`data/zhangmen/zhangmen_qin_qiong.o`,
`data/zhangmen/zhangmen_master_puti.o` — mapping key re-serialization
order only, same content — plus `u/tianlin/log`, a duplicate append of
this boot's own compile-warning noise) — all reverted via `git
checkout --`. Only the two genuine fixes (`config.fluffos`,
`adm/simul_efun/file.lpc`) remain staged.

### Net result

No new crash-class bugs found in this pass — the 2026-07-24 pass was
thorough enough that the driver rebuild alone introduced no
regressions. Two proactive standard-checklist fixes applied
(`file.lpc`'s `log_file()`/`cat()` guards, `config.fluffos`'s eval
cost) per this pass's standard checklist, neither live-reproduced as a
crash this session but both matching well-established bug classes
(§7.11, the eval-cost-abort risk) with real (if not this-session-
triggered) blast radius.

## 深度功能测试第四轮 / Round four (2026-08-20): the 3 explicitly-flagged §10.7-rule-6 gaps, resolved live

Targeted pass specifically closing the three "not verified live" items the
2026-07-24 pass named. Native `build-debug` driver, own raw-Python-socket
telnet client (not `tmux_mud.sh`), each response inspected before sending
the next command. `work/log/debug.log` stayed at **0 lines for the entire
session** — before, during, and after every step below, including the
death sequence.

### Gap 1: shop purchase — RESOLVED, completed live, correct

No in-game gold-earning path was chased (out of scope to hunt for a
starter quest reward under time pressure); instead followed the task's
sanctioned pattern: as admin (`fluffos`), `clone /clone/money/silver 5`
(the lib's own `/clone/money/silver.lpc` — clone.lpc has dedicated,
built-in handling for exactly this file plus gold/coin, so this is a
first-class supported admin action, not an exploit) then `give 5 silver
to luchen` to a fresh, ordinarily-registered test character (`luchen`/
陆晨, id `luchen`, password `Test2026`) standing in the same room
(南城客栈). Confirmed via `i` the money object actually landed
(`五两银子`). `list` at 店小二 showed `桂花酒袋(jiudai) ：一两银子`;
`buy jiudai from xiao er` succeeded ("你向店小二买下一个桂花酒袋。"),
and `i` afterward showed **exactly** the expected result: `五两银子` →
`四两银子` (1 silver unit deducted, matching the listed price) and the
new `桂花酒袋(Jiudai)` present in inventory. Both the price deduction and
the item receipt verified correct via before/after inventory snapshots,
not just the transaction message. `feature/finance.lpc`'s `can_afford()`/
`pay_money()` (checked while tracing this) confirmed the earlier-observed
"你的钱不够" rejection path uses physical carried money objects
(`gold_money`/`silver_money`/`coin_money` presence), not the separate bank
`balance` attribute (`deposit`/`withdraw` in `std/room/bank.lpc`) — the
two economies are distinct in this lib, `buy` only cares about the former.

### Gap 2: death/respawn — RESOLVED, completed live via real combat, no bugs found

Used the admin connection to scout (read room/NPC source, not live-teleport
the test character) for a genuinely lethal, reliably-reachable target
rather than the deliberately-weak `japan2.lpc` sparring dummy already
confirmed safe in the 2026-07-24 pass. Found `d/jjf/npc/jiajiang.lpc`
(家将, "jia jiang"/"jia"/"jiang", **not** the same file as the
already-documented `d/city/npc/jiajiang.lpc` 校尉 despite the identical
basename — a second, separate, much stronger NPC class): `combat_exp`
200000-250000, `force` 500, skills 70 across spear/dodge/parry/unarmed,
statically placed ×2 in `d/jjf/keting.lpc` (正厅, the general's own hall,
reached via the already-mapped route `南城客栈`→west→`朱雀大街`→north→
`十字街头`→east→`青龙大街`(qinglong-e1)→east→`青龙大街`(qinglong-e2)→
south→`将军府`(gate, `answer 拜师` required to unlock `south` per
`gate.lpc`'s `valid_leave()`)→south→`练武场`(front_yard)→south→
`练武场`(front_yard2)→south→`正厅`/keting). Walked there for real with
`luchen` (no teleport), then `kill jia` (not `fight` — `cmds/std/kill.lpc`
was checked first per the task's dtsl2-precedent question: its only
`combat_exp` gate, `if (me->query("combat_exp") < 100000 && userp(obj))
return notify_fail(...)`, is guarded by `userp(obj)` and so does **not**
apply to an NPC target; `kill` worked immediately with no gate).

Real, unmodified combat played out over several heartbeat rounds with
escalating injury text (受伤不轻 → 气息粗重 → 受了相当重的伤 → 受伤过重
已经奄奄一息 → 已经陷入半昏迷状态 → "你的眼前一黑，接着什么也不知道
了" (`unconcious()`) → "你死了" (`die()`, confirming `std/char.lpc`'s
`heart_beat()` mortal-wound check, `eff_kee/eff_sen/eff_gin < 0`, fired
for real, not just the `kee/sen/gin < 0` unconscious branch). Moved
correctly to `阴阳界`/`DEATH_ROOM` (`d/death/gate.lpc`) with `崔判官`
(`d/death/npc/pang.lpc`) present; its `death_stage()` reentrancy-guarded
init (the §7.68-shape code already audited clean in this file's earlier
sections) ran its full 5-stage dialogue at the coded 5-second cadence
with no overlap or corruption, then `reincarnate()`'d the character into
`荒郊小店`/REVIVE_ROOM — a fully valid, populated room (店小二, a board,
a working exit). Reconnecting afterward confirmed persistent state:
`score` correctly shows `死亡记录：你在战斗中被杀害过一次`, `气血` at a
recovering-but-not-full level (expected post-respawn regen, not a bug),
inventory empty (matches `die()`'s `command("drop all")` in
`reincarnate()` plus the self-made-fabao destruction loop — same
item-loss-on-death design this lineage already documents for `quit`).
`quit` afterward was clean.

**Incidentally checked and ruled out as a bug**: `feature/damage.lpc`'s
`die()` calls `DEATH_ROOM->start_death(this_object())`
(`DEATH_ROOM` = `/d/death/gate`), but **no `start_death()` function is
defined anywhere in this lib** (`grep -rn start_death` across all
`.lpc`/`.h` finds only the two call sites, one live one in `feature/back/
damage.lpc`'s unused backup copy) — this call always resolves to a
missing function. It is provably harmless: the actual ghost/`death_stage`
flow triggers independently, through the ordinary room-entry `init()` of
whatever `npc/pang`-shaped NPC the `gate.lpc`-family room happens to
carry (confirmed exactly this way above, live), not through
`start_death()` at all — and the live reproduction above proves a
call_other to this permanently-undefined function produces **no**
`debug.log` entry (FluffOS's call_other-to-missing-function behavior is a
silent no-op here, not a catchable/logged error). Per this project's
scope rule (only real crash/`debug.log`-error signatures count), this is
dead/vestigial code, not a bug — left untouched.

### Gap 3: mid-wizard net-dead reconnect (§7.21 shape) — RESOLVED, clean on two separate live reproductions

First (incidental): an earlier registration script for `luchen` dropped
the connection right at the gift-wizard's opening menu (a plain,
non-forced TCP close). Reconnecting (`luchen`/`Test2026`) produced
"重新连线完毕。" and cleanly re-presented the exact same top-level wizard
menu — resumed, not stuck, not corrupted.

Then (deliberate, rigorous): registered a second fresh character
(`hujie`/胡杰, id `hujie`, password `Test2026`) through to the wizard,
sent `0` to start a stat-reroll, waited for the **sub-prompt**
("请输入体格的新取值[10-30]：" — deeper into the wizard state than the
top-level menu, mid-reroll with no answer given), then force-closed the
socket with `SO_LINGER=0` (a real RST, not a graceful close, matching
`xiyouji`/this-file's own established net-dead-testing technique).
Reconnecting immediately afterward: "重新连线完毕。", and the wizard
**discarded the orphaned reroll sub-state cleanly and re-presented the
top-level menu** (not stuck waiting on the abandoned sub-prompt, not
duplicated, not corrupted). Completed the wizard normally (`9`/`y`),
`score` rendered a fully correct fresh character, `quit` was clean.
`debug.log` stayed empty through both reproductions. **This lib's
character-creation wizard has no §7.21-shape bug** — net-dead mid-wizard,
even via a genuine RST at the deepest (sub-prompt) point tested, resumes
safely.

### Standard checklist re-confirmation pass (all previously fixed, spot-checked, no regressions)

- **§7.90** (`config.fluffos` eval cost): `5000000` — already fixed
  (2026-08-14 pass), confirmed still in place.
- **§7.100** (`replace_program(ROOM);`): zero live hits. The only
  `grep` matches left are inside `u/Love/`'s and `u/linger/`'s numbered
  `workroom.c.<timestamp>` backup files (a room-builder tool's auto-saved
  revision history, not `.lpc`/`.c`-suffixed, never resolved by this
  driver's extensionless `load_object()`) and one doc-directory prose
  mention (`doc/build/room`) — neither is live code. The 563-line
  original sweep (documented above) holds.
- **§7.111** (`file_name(error["object"])` null-guard): present, both
  call sites in `adm/obj/master.lpc` (lines ~240, ~334) still guarded
  with `undefinedp(error["object"]) || !error["object"]`.
- **§7.112** (`death_stage()` reentrancy guard): re-checked all 5 files
  with a `call_out("death_stage", ...)` site in this lib
  (`d/death/npc/{b,bgargoyle,wgargoyle,pang}.lpc` and
  `u/tianlin/d/shaolin/npc/yu-zu2.lpc`) — every one already has the
  `query_temp("death_stage_active")`/`set_temp(...)` guard in `init()`,
  matching the fix shape found on 3 other libs this session. No gap here.
  (`pang.lpc`'s own guard was exercised live for real by the death test
  above, not just grepped.)
- **§7.79** (bare 2-arg `addn`/`addn_temp()`): zero hits
  (`grep -rn 'addn_temp(\|addn('` with a check for a 3rd argument found
  none missing one).

### Process and repo hygiene

Driver killed by exact PID (`kill 800001`, confirmed dead via `ps`),
never `pkill -f`. Post-test `git status --short libs/mhxy` showed the two
new test characters' saves (`luchen`, `hujie` — kept as playthrough
evidence, per this project's established convention) plus admin
(`fluffos`) login/user churn from repeated logins; three `zhangmen_*.o`
files (`ao_guang`, `guanyin_pusa`, `qin_qiong` — sects never touched this
pass beyond walking past `qin_qiong`'s own NPC) and a duplicate
`u/tianlin/log` append were confirmed pure re-serialization/background-
daemon noise (byte-diffed: same content, reordered mapping keys plus a
`mana`/`force_factor` recompute artifact matching the exact shape already
documented in this file's 2026-08-14 pass) and reverted via `git checkout
--`.

## §7.100 sweep fix (`ROOM` base-class redundant `replace_program()`)

`#define ROOM "/std/room"`: deleted 563 redundant, live, standalone
`replace_program(ROOM);` lines (kept `inherit ROOM;`) — 561 caught by
the scripted sweep, plus 2 hand-fixed instances baked into the two
copies of this lib's in-game room-building tool
(`obj/roommaker.lpc`, `clone/misc/roommaker.lpc` — near-identical,
differ only in one `is_monitored` set() call and encoding of two
traditional-vs-simplified characters). Both tools have the standard
two-template shape: the "make an empty room" heredoc was already
clean, only the "clone the room I'm standing in" command's
`str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";` string-builder
carried the bug — fixed to drop the redundant call and keep
`setup();`. 8 pre-existing `//`-commented instances remain untouched,
confirmed harmless. Verified via a clean `build-debug` driver boot
(0 new compile errors, port 40016 listening, zero new "cannot
replace"/"cannot bind" `debug.log` lines); no full §10.7 gameplay
walkthrough this pass.

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

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply mhxy`: 79 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 2 path reference(s) in 2 file(s) rewritten to the new spelling; 0 skipped, 1 ambiguous. Load check of the 88 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 5 PASS -> 77 PASS, 0 that loaded before fail now, 72 more load.

79 files moved (79 `.lpc`); mostly under `d/youxia/OBJ` (32), `d/youxia/NPC` (14), `d/youxia/BAGUA` (9), `u/tianlin/clone` (3). A rescan with `scripts/lpc_warnings.py mhxy` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 281 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 2 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py mhxy --fix`：无用局部变量 2294 个、`varargs` 69 处、转义 50 处、`nosave` 函数 17 个改 `protected`、裸 `return` 7 处，共改动 1230 个 `.lpc`。这些文件在 HEAD 与工作树分别加载（新进程）：1200 -> 1200 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 21 条候选都是声明被重建（仍在用的名字保留；有 `#if` 的只有 `d/city/piggy*.lpc`，与被删的名字无关）。手工：`adm/daemons/logind.lpc` `enter_world()` 里的 `if (!silent) { }` 只剩一行被注释掉的进场消息，空的条件判断删去（注释保留）。启动时警告 490 -> 0；新进程启动后新角色注册（英文名、中文名、密码、身份标识、邮箱、性别、天赋）进入游戏，`look`、`score`、`quit` 正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 28 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 15 个，只在 #if 分支用的声明移进分支 0 个文件；改动 39 个文件，HEAD 与工作树各载入一次无回退（39 objects; HEAD PASS 38, tree PASS 38; regress 0; newly loading 0），这些文件的警告 83 -> 40。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `d/city/silao.lpc`：`if (msg == "ground") msg == "center";` 应为 `=`。
- `d/youxia/npc/shaolong.lpc`：注释掉的 `chat_msg` 里漏了一行字符串没注释，成了独立语句；一并注释。
- `daemon/skill_wiz/archery/xuanyuan-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用，删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 67 -> 0（`lpc_warnings.py mhxy` 重扫：11861 -> 11863 个文件可编译；剩下 2 条警告都在本来就编译不过的文件里）。同内容的 rzrmud（提交 0089d52b3fd）有 9 个文件是 token 级孪生（`lpc_twin_port.py classify`），用 `adopt` 搬过来：`d/kaifeng/ground*.lpc` 的 `GROUND_TABLES_INHERITED`、`npc/colors.h` 的 guard、`reporting.lpc` 未用的 `str`、`lijing.lpc` 的 `void die()/unconcious()`、`jiasha.lpc` 的 `init()`；`ground.h` 本库有自己的表，手工包上 `#ifndef GROUND_TABLES_INHERITED`。`u/redrain/menpai/d/kaifeng/` 是同一份拷贝，照抄。

**真问题：**
- `d/qujing/sanda/npc/pusa.lpc`（三打白骨精的菩萨）和 `d/qujing/xihai/npc/aoshun.lpc`（西海敖顺）：本站给关卡加了前置条件，却把括号写错成 `if (who->query("obstacle/sanda") == "done") || who->query("obstacle/heishui") != "done"` 再另起一行 `)`，整个文件编译不过，这两关的 NPC 从来载不进来、关卡没法完成。改成 `if (A == "done" || B != "done")`，两个文件现在能载入。
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟：`inherit CLOTH; inherit F_UNIQUE;` 两个基类都有 `init()`，驱动只用了 unique 的 `check_owner()`，cloth 的 `tear` 动作丢了；叶子里写 `init() { cloth::init(); unique::init(); }`。

**其余：**
- `d/city/npc/sanhua-counter.lpc` 自己的 `int last_time` 与 `feature/alias.lpc` 的 `nosave int last_time` 同名。查过驱动 `compiler.cc` 的 `define_variable()`：只有前一个声明可存档时才把后一个强制成 nosave；alias 那份本来就是 nosave，所以三花计数器这份一直正常存档。按 KB 04 的做法改名 alias 这边的私有变量为 `last_cmd_time`（只有本文件读它），叶子和已有存档都不动。
- `d/city/npc/yg/yaoguai.lpc`：自己的 `int yaoguai_type = 0;` 从来不读（只有基类 `d/dntg/yunlou/npc/yaoguai.lpc` 用它，基类也初始化为 0），删掉；13 个 `yg-*` 的重复声明警告随之消失。
- `d/lingtai/npc/jiefei.lpc` `unconcious()`、`d/qujing/niulang/xiwangmu.lpc` `die()/unconcious()` 改 `void`（基类是 void 的钩子，没人读返回值）；`d/moon/npc/yutu.lpc`、`d/wusheng/npc/jinren.lpc` 的 `kill_ob()` 改 `void`，仍调用 `::kill_ob()`；`d/newjob/longzhu/npc/long.lpc` 删掉没有函数体的 `int long();` 原型（继承来的是 `string long()`）。
- `www/relative/dns_master.lpc`：`#if PREF_X & SVC_TCP` 挪到空 if 外面（`lpc_fix_no_effect.py`）。
- `toolkit_fix.sh`：14 个多余的 `inherit F_CLEAN_UP`（NPC/武器/护甲已经带了），`u/*/clone/YI.lpc` 的 `query_autoload()` 改 `mixed`。

验证：改动文件、开封擂台和任务两处目录下全部对象、`d/city/npc` 及 `yg/`、`/obj/user`、`/std/char` 共 519 个对象，HEAD 与工作树各用新进程载入：477 -> 479 通过（新增载入 pusa、aoshun），regress 0；删除声明审计 0 项待看。519 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。11 个文件 20 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemon/class/wudang/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/daemon/skill/evilmove`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。7 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

13 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`、`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`lingguan-quan`→`lingguang-quan`（`lingguang-quan`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

34 个文件、41 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/u/fly/obj/jinshan`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 31 个（30 个原来载入不了），没有退步；其余 4 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（14 个名字，最多的是 `strike`、`cuff`、`qiankun-danuoyi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 5 个通过，其余 2 个停在别的错误上（`d/city/obj/npc/zhong`：*No program in object '/d/city/obj/npc/zhong'!；`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/qujing/baoxiang/gongmen` 的 `west`：`jitan1` → `jitan`；`/d/qujing/biqiu/jie4` 的 `north`：`jitan1` → `jitan`；`/d/qujing/chechi/xinshi` 的 `south`：`jitan6` → `jitan`；`/d/qujing/fengxian/shikou` 的 `up`：`jitai1` → `jitai`；`/d/qujing/jinping/fumen` 的 `north`：`jitan1` → `jitan`；`/d/qujing/jisaiguo/centermarket` 的 `north`：`jitan1` → `jitan`；`/d/qujing/nuerguo/towna2` 的 `north`：`jitan1` → `jitan`；`/d/qujing/qinfa/qiankun` 的 `north`：`jitan1` → `jitan`；`/d/qujing/tianzhu/jiedao18` 的 `north`：`jitan1` → `jitan`；`/d/qujing/wudidong/temple-houdian` 的 `south`：`jitan1` → `jitan`；`/d/qujing/wuji/square` 的 `south`：`jitan1` → `jitan`；`/d/qujing/yuhua/fumen` 的 `west`：`jitan1` → `jitan`；`/d/qujing/zhuzi/gulou` 的 `up`：`jitan1` → `jitan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/qin`（宏 `QIN`）←sjshwzjqb，1 个对象继承它，抽样 1/1 载入；`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 18 处、18 个文件：`dagonforce`→`dragonforce`（4 处）、`dragon-step`→`dragonstep`（4 处）、`yange_blade`→`yange-blade`（3 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`lahua-shou`→`lanhua-shou`（2 处）、`changqaun`→`changquan`（2 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 2 个：`d/city/obj/npc/zhong`、`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`、`MAILDIR`、`F_DISASTER`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/youxia/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/city/obj/npc/daiyu.lpc` 的 `#include "/u/fly/npc/npc.h"` 改成 `/d/city/obj/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `daemon/class/yaomo/xueshan/cuixin-zhang/cuixin.lpc` 的一句出招描述里夹着一个 NUL 字节（`接着\0:`），`d/lingtai/obj/yuanpinzhu.lpc` 的第一行注释里也有一个（`张天师\0,`）：驱动报 `Illegal embedded NUL byte (0x00) in source`，技能和物件都载入不了。删掉 NUL，其余文字不动。

逐个载入与 HEAD 对比，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 个未使用的局部变量，1 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/daemon/class/mojie/liejiuquan/ball.lpc`（1 处）、`/daemon/class/mojie/lingguang-quan/shoot.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/back/disaster.lpc`（2 处）、`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 21 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/cmds/wiz/finger.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/wiz/npc/jing.lpc`（3 处）、`/daemon/class/bonze/lunhui-zhang/puzhao.lpc`（1 处）、`/daemon/class/fighter/bawang-qiang/bailie.lpc`（1 处）、`/daemon/class/mojie/evilfight/dragonshoot.lpc`（3 处）、`/daemon/class/mojie/evilsword/16slash.lpc`（1 处）、`/daemon/class/mojie/segokee/mindshock.lpc`（1 处）、`/www/cgi-bin/board_h.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/cgi-bin/logind.lpc`、`/www/relative/logind.lpc`。

## `setmission`：`explode(read_file("/adm/daemons/wizmission"))`（2026-10-21，KB 06 §7.326）

巫师命令 `cmds/wiz/setmission` 读 `/adm/daemons/wizmission`（归档里没有，由这条命令自己写），`explode(0)` 抛错，读在写之前所以这个文件永远建不出来。`read_file(...) || ""`，第一次用时走 `write_file()` 新建的分支。mhxy 和 mhxyqd 同一处。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/adm/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。
