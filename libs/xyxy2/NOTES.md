# 20150716未知lib.zip → `xyxy2`

- Archive: `archives/20150716未知lib.zip` (9.5MB, "unknown lib" dated
  2015-07-16 in the filename — actually **『小雨西游Ⅱ』(Xiaoyu Xiyou II /
  "Light Rain Journey to the West II")**, v3.0, confirmed from the live
  banner ("站点创建时间：2013年12月30日"). Journey-to-the-West themed,
  MudOS 0.9.20 lineage.
- Mudlib root in archive: `20150716/` (single top-level folder).
- Config: **no config.cfg at archive top level** — found at
  `20150716/adm/etc/config.xiyou` (`xiyou` = 西游, "Journey to the West").
  Always check `adm/etc/*` for a config-shaped file when none is obvious
  at the top.
- Port: **40003**. Biggest lib so far: 9635 raw files / 8467 `.lpc` after
  conversion.

## Status: DONE — boots clean, playable over telnet

Full ASCII-art Monkey King banner, GB/BIG5 encoding-selection prompt (a
legacy dual-encoding-era feature — answering either way is fine since
everything here is UTF-8 now), then normal login flow, all confirmed
working. **Note: this lib enforces a 30-second startup grace period**
(`adm/daemons/logind.lpc`'s `logon()`: `if (uptime() < 30) { ...still
starting up, try later... }`) — intentional, not a bug; wait >30s after
boot before testing a connection.

## What was fixed

1. Encoding: 9208 converted, 320 already UTF-8/ASCII, 31 skipped binary,
   76 lossy (-c fallback, pre-existing stray bytes).
2. `.c` → `.lpc`: 8467 files. 1914 literal `.c"` refs auto-fixed, 0 left over.
3. `static` → `nosave`: 203 files.
4. `master.lpc` has neither the §4 (`load_object` in `valid_read`) nor the
   §14 (2-arg `valid_override`) issues — checked, both already fine in
   this lib (it uses `sscanf(file, "/adm/simul_efun/%s", file)` to detect
   simul_efun fragments for the `destruct` override case, a different but
   equally valid solution to the same problem AGENTS.md §14 documents).
5. `adm/etc/log/` directory was missing entirely from the archive (not
   just the driver's debug-log dir — the mudlib's OWN runtime log dir).
   Symptom: repeated `*Wrong permissions for opening file /log/log for
   append` errors at boot (misleading — it's a missing-directory issue,
   not an actual permission problem; `SECURITY_D`'s write-permission check
   for a nonexistent path denies rather than erroring with ENOENT).
   Fixed: `mkdir work/log`.
6. **Found and fixed a new general pattern** (AGENTS.md §8d): ~200+ files
   `#include <local.h>`-style a per-file header living in their OWN
   directory (e.g. `d/kaifeng/ground0.lpc`'s `#include <ground.h>`, with
   `ground.h` sitting right next to it) — `<...>` never searches the
   including file's own directory in this driver (only `"..."` does).
   Fixed with ONE addition to `master.lpc`: implemented
   `get_include_path()` to prepend the compiling file's own directory to
   the search path. This alone dropped the lpcc sweep's failure count
   from 289 to 64 (of 9017 checked).

## Known remaining issues (documented, not fixed)

- ~62 remaining lpcc-sweep failures (was 64; 2 fixed 2026-07-24's deep
  functional test — see "深度功能测试" below, `book-qujing.lpc` and
  `tongmingdian.lpc` were both actually a fixable mudlib-root-absolute
  `#include <...>` driver-API bug, not missing content), not
  individually triaged past a category scan — dominated by scattered
  `Undefined function/variable` errors (`greeting1`/`greeting2`/
  `reporting`/`order_list`/`quest_accurate_index`/`can_enter`/
  `you_leave`/etc, `RED`/`NOR`/`GRN`/`BLK`/`DEBUG`/`flowers`/
  `obstacles`/`banned_cast`/`banned_action`) that look like
  content-completeness gaps (quest/greeting content referencing things
  not present in this particular archive), same shape as other libs'
  missing-zone-content findings (AGENTS.md §13). None of the
  affected files are on the boot/login critical path.

## How to run

```
cd libs/xyxy2
~/src/fluffos/build-debug/src/driver config.fluffos
# wait >30s after boot before connecting (see startup grace period above)
python3 ../../scripts/mudclient.py 127.0.0.1 40003 --timeout 10 --send "gb" --send "" --send "look" --send "quit"
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

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 9017 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 8813 written, 164 already
  idempotent-clean, 40 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot (waited out the lib's own 30-second startup grace
  period per its existing note above), zero fatal errors in
  `log/debug.log`. Full registration flow re-verified end-to-end with a
  fresh real Chinese name (id `unlrthr`/name `秦风`, then again with id
  `unlrfour`/name `秦枫`), reaching the actual starting room (`翠香楼`),
  `look`/`score`/`quit` all producing correct output — no regressions
  from either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly, only benign compile-
  warning spam, zero fatal errors. However, this lib's own intentional
  30-second startup grace period (`uptime() < 30` in
  `adm/daemons/logind.lpc`'s `logon()`, which unconditionally
  `destruct(ob)`s the connection object if triggered — see "Status"
  section above) fires every time under `wasm_client.js`, because that
  harness calls `fluffos_connect()` immediately after `fluffos_boot()`
  within the same single-process invocation, well before 30 seconds of
  driver uptime can elapse. This is a **test-harness timing limitation**
  (the harness has no way to wait out real uptime before opening the one
  connection it drives), **not** a WASM driver bug and **not** a mudlib
  bug — the exact same code path is only ever exercised natively after
  real wall-clock time has passed, which is how this lib was already
  fully verified above. Not investigated further per the pass's "honest
  assessment, no forced full playthrough" guidance.

## WASM-enablement pass (loopback-allow / uptime bypass / throttle exemption / admin seeding)

Gates found and patched (AGENTS.md §1.3b/§1.3e/§1.5):

- `obj/login.lpc:24-27` — the malformed-IP fallback in `logon()` used to
  set `last_from` to `"0.0.0.0"`; now sets `"127.0.0.1"` so a WASM
  driver's garbage `query_ip_number()` is treated as loopback by every
  downstream gate (all of logind's checks read `last_from`).
- `adm/daemons/logind.lpc:109-124` (`logon()`) — the `uptime() < 30`
  startup-grace destruct and the >15-connections-per-IP reconnect-flood
  destruct now apply only when `last_from != "127.0.0.1"`.
- `adm/daemons/logind.lpc` `get_id()` (`#ifdef MAX_LOGIN` block) — the
  per-IP multi-login cap (`allow_multi_login` + same-/24 counting) is
  skipped for loopback.
- `adm/daemons/band.lpc` — `is_strict_banned()` and
  `create_char_banned()` short-circuit return 0 for loopback /
  "127."-prefix / empty / malformed (non-dotted-quad) addresses before
  any regexp matching. (`allow_multi_login` needed no patch — its caller
  is already loopback-exempted above.)

**Retrofitted fail-open → fail-closed (2026-07-24)**: all four spots
above were originally written so that ANY malformed/non-string ip
bypassed its gate, not just genuine loopback — defensive against the
old WASM driver bug where `query_ip_number()` returned garbage for
every WASM connection. That driver bug is now fixed (WASM reports a
clean `"127.0.0.1"` same as native), so there is no remaining
justification for "can't parse it" ⇒ "must be loopback". Changed:
  - `obj/login.lpc`'s `logon()`: no longer coerces an unparseable ip
    into `"127.0.0.1"`. It now stores whatever `query_ip_number()`
    actually returns, falling back only to `""` (untrusted/non-local)
    when it isn't even a string — the `sscanf(...)!=4` well-formedness
    check that used to gate the coercion is gone entirely.
  - `adm/daemons/band.lpc`'s `create_char_banned()`/`is_strict_banned()`:
    changed from `!stringp(site) || site=="127.0.0.1" ||
    strsrch(site,"127.")==0 || sscanf(site,"%*d.%*d.%*d.%*d")!=4` (any
    unparseable site returns "not banned") to `stringp(site) &&
    (site=="127.0.0.1" || strsrch(site,"127.")==0)` for the bypass, with
    an added `if (!stringp(site)) return 1;` immediately after so a
    non-string site is treated as banned (deny) rather than falling
    into the regexp match on a non-string value.
  Since `last_from`/`band.lpc`'s callers all key off the corrected
  `obj/login.lpc` value now, `logind.lpc`'s own `lb_ip != "127.0.0.1"`
  comparisons needed no further change — they were already exact-match
  fail-closed; they just used to receive an already-laundered value.

Admin account: id `fluffos`, login password `Mud@2026`, super (admin)
password `Adm@2026` (the lib's two-password registration requires a
mixed-case ≥7-char super password distinct from the login password),
Chinese name 浮浮. Granted `(admin)` by adding `fluffos (admin)` to
`adm/etc/notices` — this lib's `WIZLIST` macro (include/login.h:14)
points at `/adm/etc/notices`, NOT the adjacent `adm/etc/wizlist` file.
Verified post-restart: fluffos login + talent-selection (9/y), lands in
翠香楼, `update /adm/daemons/logind` → 成功.

Save files the orchestrator must add (untracked; data/user + data/login
trees are not in git for this lib, and none of these are gitignored):
- `libs/xyxy2/work/data/user/f/fluffos.o`
- `libs/xyxy2/work/data/login/f/fluffos.o`
- `libs/xyxy2/work/data/zhaohuan/f/fluffos` (summon-pet
  state created at registration; harmless either way, listed for
  completeness)

Retest: fresh normal registration (id qintest / 秦风) end-to-end —
NOTE the flow has a first-entry talent-selection step after gender:
send `9` (accept) then `y` (confirm); look/`score`/`quit` all correct
in 翠香楼. debug.log clean (warnings only, zero runtime errors).
qintest saves removed after the test; fluffos kept.

**Re-retest after the fail-closed retrofit (2026-07-24)**: fresh boot,
fresh normal registration (`gb` → `1` → `new` → id `qretest` → real
Chinese name 秦风八 → super-password `Test123!`×2 → login password
`test1234`×2 → email → `m` → talent `9`/`y`) all the way through
`look`/`score`/`quit` — landed in 翠香楼, rich `score` output correct,
clean farewell message on quit. No 30-second startup-grace delay
needed connecting immediately after boot (loopback bypass still
working). `fluffos`/`Mud@2026` admin login re-verified: `look` then
`update /adm/daemons/logind` → `重新编译 /adm/daemons/logind.lpc
...成功！`. Zero `执行时段错误` lines in `debug.log` for the whole
session. Test char `qretest` (including its `data/zhaohuan/q/qretest`
summon-state dir) removed afterward; fluffos kept.

## 深度功能测试 / Deep functional test (2026-07-24, round two, AGENTS.md §10.7)

First genuine hands-on *playthrough* pass on this lib (every prior pass
above verified registration + `look`/`score`/`quit` + admin login, never
a real multi-system playthrough). Native driver (`build-debug`), one
continuous session per test phase, driven via `scripts/mudclient.py`.
Read `work/doc/help/newbie/newbie` first — it lays out the exact intended
early-game path (傲来武馆 safe sparring → raft to Changan → pick a sect
→ learn skills → 10级突破 dungeon) and was followed closely below.

**Test character**: id `linfeng`, Chinese name 林风, login password
`test1234`, super password `Test123!` — **kept** as a representative
playthrough character. State left behind: level 5, joined 百花谷
(Baihuagu) as 第四代外门弟子 under 百草仙, skills `unarmed` 1/`dodge`
6/`parry` 1 (dodge/parry trained organically by the real dog fight
below, unarmed taught explicitly by 东方聪), inventory `炸鸡腿`
(chicken leg, bought from the shop) + 9两20文 remaining coin, located in
翠香楼 (start room). Save files: `work/data/user/l/linfeng.o`,
`work/data/login/l/linfeng.o`, `work/data/zhaohuan/l/linfeng`.

### Bugs found and fixed

**1. (RETRACTED — content/design judgment call, not a programming bug;
reverted on user review) `d/changan/aolaiws.lpc`'s `close_passage()`
deletes the raft's exit entirely if a player misses the ~20s boarding
window, leaving them in a genuine zero-exit room for the rest of the
live session (recoverable only by disconnecting).** Originally "fixed"
by restoring the exit instead of deleting it — since reverted. The
accompanying flavor message ("一个浪头打来，木筏向海上漂去。" — a wave
hits, the raft drifts out to sea) plausibly describes an INTENTIONAL
"you missed the boat and are now stranded" consequence for a
time-gated mechanic, not an oversight — deleting an exit as a
deliberate timing-punishment is a design choice, not a proven
programming defect (no crash, no wrong efun usage, nothing the code
itself contradicts). Left as originally shipped, documented here rather
than silently re-fixed. See AGENTS.md §7.27 for the retraction writeup
and the general lesson (this exact shape is now a documented cautionary
case study, not a bug class to fix on sight).

**2. `adm/obj/master.lpc` — mudlib-root-absolute `#include </path>`
inside `<...>` never resolves, `get_include_path()` can't fix it.**

- Found while walking the map: moving through `d/city/zhuque-s1.lpc`
  (a room never visited by any prior smoke test) threw a caught
  `执行时段错误：*No program in object '/d/obj/books-nonskill/
  book-qujing'!` from an NPC's `create()` → `carry_object()` chain
  (same first-visit-only shape as AGENTS.md §7.17/§7.19, different root
  cause). Root cause: `d/obj/books-nonskill/book-qujing.lpc` and
  `d/dntg/sky/tongmingdian.lpc` both `#include` a path that is already
  mudlib-root-absolute inside `<...>` (e.g. `#include
  </d/qujing/obstacle.h>`) — the driver always resolves a `<...>`
  include as `search_dir + "/" + header_name` for each directory
  `master::get_include_path()` returns, so no list of search
  *directories* can ever make an already-absolute header name resolve
  (confirmed empirically: adding `""` to the returned list produces
  `"//d/qujing/obstacle.h"`, which this driver's `<...>` path validator
  rejects outright rather than collapsing, unlike a plain filesystem
  `open()`). These were 2 of the lib's previously-uninvestigated 64
  lpcc-sweep failures (`lpcc_fail.log`), bucketed as generic
  "content-completeness gaps" — they are not; they're a fixable
  driver-API-usage bug.
- Fix: implemented `master::include_file(compiled, from, path)`
  (`adm/obj/master.lpc`), a separate driver hook
  (`src/compiler/internal/lexer_utils.cc`,
  `lpc_lex_handle_include`/`APPLY_INCLUDE_FILE`) that lets the master
  force an include to resolve like a **quoted** (`"..."`) include
  instead — which correctly treats a leading `/` as mudlib-root-absolute
  via the driver's own `merge()`. Returning the include path unchanged
  is a no-op (falls through to the same broken `<...>` search), so the
  fix returns `"/" + path` when `path` already starts with `/` — a
  different string (which is what actually flips the driver into the
  quoted-style resolution) that still merges back down to the original
  intended path, since `merge()` treats any run of leading slashes as
  one absolute-root marker:
  ```lpc
  // ADDED:
  mixed include_file(string compiled, string from, string path) {
    if (path && strlen(path) && path[0] == '/')
      return "/" + path;
    return path;
  }
  ```
- Verified live via `update` as the `fluffos` admin: both
  `/d/obj/books-nonskill/book-qujing.lpc` and
  `/d/dntg/sky/tongmingdian.lpc` now compile cleanly (previously
  `Cannot #include /d/qujing/obstacle.h` / `.../laojunluhelp.h`, each
  with a cascading `Undefined variable`/`Undefined function` error from
  the header's missing content). `tongmingdian.lpc` still has one
  unrelated pre-existing `Undefined function you_leave` error left
  (genuine missing content, not an include problem — left as one of the
  remaining lpcc-sweep failures per the existing "known remaining
  issues" note above).
- **This is a new bug class, not yet in AGENTS.md** — see draft writeup
  in the agent's final report for §7.24 (or next free slot).

**3. `work/log/nosave/` — another missing runtime directory (same class
as this lib's pre-existing `adm/etc/log/` fix above, AGENTS.md §7.11).**

- `cmds/wiz/call.lpc`'s player-call audit trail (`log_file("nosave/
  call_player", ...)`) — and about a dozen other call sites across the
  lib (`crash`, `dump`, `purge`, `jiangli`, `TANGGIFT`, `jinchai`,
  `NEWBIEGIFTopen`, `COOKIEGIFT`, `CLONE`, `full`, ...) — all write into
  a single `/log/nosave/` directory that the archive never shipped and
  that (like `work/log` itself) is gitignored, so it needs recreating on
  any fresh checkout. Symptom: `*Wrong permissions for opening file
  /log/nosave/call_player for append` (same misleading-permissions
  framing as the original `adm/etc/log/` bug — it's a missing directory,
  not an ACL issue). Fix: `mkdir work/log/nosave`.

### What was tested and confirmed working

- **Registration → real gameplay, one continuous session**: real
  Chinese name (林风), landed in 翠香楼, `look`/`score`/`i` all correct
  at every state change (post-register, post-move, post-levelup,
  post-sect-join, post-shop, post-combat).
- **Starting-zone navigation**: walked the whole 傲来国 (Aolai) city
  map by reading room `.lpc` `exits` mappings (BFS over the actual
  source, not guesswork) — 翠香楼→北菀街→傲云广场→东苑街→东方武馆
  (school) and 傲云广场→西芫街→仓库, day/night flavor text and room
  descriptions all correct.
- **Safe-sparring mechanic** (`help newbie`'s documented "fight dizi"):
  `d/aolai/npc/dizi.lpc`'s `do_fight()`/`end_fight()` is a scripted,
  harmless mock bout (fixed 3-8s `call_out`, always "wins" for the
  player, no real damage) that grants `combat_exp`/`potential` — used
  repeatedly to level 1→5, confirmed correct exp/potential math and
  level-up messages every time.
- **Organic NPC-teacher skill learning** (two-step, both parts
  confirmed): asked 武馆馆主 东方博玉 `ask dongfang boyu about 学艺`
  (sets a `aolai_dongfang` temp flag via his `teach_me()`), then `learn
  unarmed from dongfang cong` — `skills dongfang cong` correctly listed
  his teachable skills first, the `learn` command correctly deducted
  potential and reported `你的「unarmed」升至 1 级`, confirmed via
  `skills`.
- **Sect join** (separate from the teacher path, per checklist item 6):
  followed the newbie guide's raft route (傲来国北城门 → level-5 gate
  `d/aolai/northgate.lpc`'s `valid_leave()` correctly blocked passage
  below level 5, then correctly allowed it once leveled) → `zuo mufa` →
  `enter` → `out` timed crossing (this is the exact flow that exposed
  bug #1 above) → walked Changan's map (`大官道`→`朱雀大街`→`长安乐坊`)
  to 百花谷's recruiter NPC `百草仙` → `bai xian` (the `apprentice`
  command's `bai` alias) → correctly joined as `百花谷第四代外门弟子`,
  confirmed via `score`'s 门派/师承 fields.
- **Shop purchase**: `list`/`buy <item> from <vendor>` at 翠香楼's
  in-room vendor (`d/aolai/npc/xiaoer.lpc`, `F_VENDOR_SALE`) — first
  tried broke (`你的钱不够`, correct insufficient-funds path, confirmed
  with `list` pricing shown correctly), then admin-granted coin
  (`money_add`, the real currency mutator — `add_money()` is
  NPC-only and silently no-ops on a player body, a minor API-naming
  trap worth knowing but not a bug since nothing in the shipped content
  calls it on a player) and completed a real purchase of `炸鸡腿`,
  price and remaining balance both correct in `i`/`score` afterward.
- **Real (non-scripted) combat**: `kill dog` on the wandering 黑狗
  (`d/city/npc/dog.lpc`, level 2, wanders into 西芫街) — full turn-by-
  turn hit/miss/dodge/parry narration, correct "有点累了"/"觉得头有一
  点发晕" fatigue-state messages, and organic `dodge`/`parry`
  skill-up-on-use notifications (went 0→6 dodge, 0→1 parry purely from
  this one fight) all correct. Bare-fisted `unarmed` 1 could not land a
  single point of damage on even this weak an NPC in ~10 minutes of
  real combat (near-permanent "结果没有造成任何伤害"), which reads as
  intended low-level balance (this game expects a weapon — the newbie
  guide explicitly says to buy one before the 10级突破 dungeon), not a
  bug; ended the fight via admin `dest` on the dog rather than letting
  it run indefinitely, since neither side was making real progress and
  our own health stayed comfortably above 75% (`kee` 824/1072) the
  whole time — see "Not verified live" below re: death/respawn.
- **Unclean disconnect (net-dead) + reconnect, both promptly and after
  a real wait**: closed the TCP connection without `quit` several times
  through this whole pass (mudclient.py's normal end-of-script
  behavior already does this every time it isn't told to `quit`) and
  once deliberately with an explicit 90-second real-wall-clock gap
  before reconnecting — every single time, `重新连线完毕` + exact same
  room/inventory/gold, no void-parking, no stranding. Confirms this
  lib does **not** have the AGENTS.md §7.20/§7.21 net-dead classes
  (checked explicitly per the task brief) — the only real-time-gated
  stranding found here is bug #1 above, a completely different
  mechanism (an active LIVE session losing all room exits, not a
  disconnect/reconnect path losing the saved location).
- **Clean `quit` → debug.log grep → reconnect after a real wait**: `quit`
  produced the correct farewell message; immediately grepped
  `libs/xyxy2/log/debug.log` (the actual live log path —
  **not** `work/log/debug.log`, which is a stale leftover from an
  earlier/unrelated boot despite the `mudlib directory`/`log directory`
  config values suggesting otherwise; always check which file is
  actually growing before trusting a debug.log grep) for
  `error:`/`Too deep recursion`/`执行时段错误`/`Fatal` — zero matches,
  clean. Reconnected afterward (several minutes of real elapsed time via
  the rest of this pass's own work) — correctly landed back in 翠香楼
  (this lib's only `valid_startroom`-flagged room the character had
  actually saved from; 西芫街/长安乐坊/etc. never set that flag, so
  visiting them doesn't change the save-relogin point — expected, not a
  bug), with inventory (`炸鸡腿` + gold) and all three learned skills
  (including the two trained purely by the real dog fight) intact.

### Explicitly NOT verified live (say so, don't silently skip)

- **Death/respawn**: not reached. Real (non-scripted) combat against
  even a weak level-2 wild NPC with a level-1 unarmed skill and no
  weapon converged to a near-permanent stalemate (see above) rather
  than a clean win or loss within a reasonable real-time budget for
  this pass; ended the fight via admin intervention instead of forcing
  it to a death outcome. The newbie guide's own advice (buy a weapon
  before fighting anything real) suggests this is expected difficulty
  tuning, not a bug, but the actual death → revive flow itself was not
  exercised this pass.
- **20级突破 puzzle dungeon and the 10-25级 loot dungeon**: both
  documented at length in `work/doc/help/newbie/newbie` but gated
  behind substantially more level/time investment than this pass's
  budget allowed; not attempted.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

小雨西游家族基础版。状态已从过时的 limited 修正——这份档案自己的 NOTES.md 记载着早前某次会话就已经完成的完整转换+修复过程（GBK→UTF8 编码转换、.c→.lpc 改名、static→nosave、补上缺失的 adm/etc/log/ 目录，以及一种通用的 #include <local.h> 式同目录头文件模式，靠 master.lpc 的 get_include_path() 修复），并确认"启动干净，可以通过 telnet 游玩"，带有一次真正验证过的注册流程。uptime()<30 的启动宽限门槛已经正确地对本地回环放行了（adm/daemons/logind.lpc 的 logon()："if (lb_ip != "127.0.0.1" && uptime() < 30)"）——本轮已通过一次立即（没有等 30 秒）的 WASM 连线干净到达注册 id 提示、零编译错误来现场确认。这份 meta.json/README 只是从未更新以反映已经完成的工作——除了这次冒烟级别的复核之外不需要新的测试。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第三轮 / Deep functional test round three (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复四处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `800000` 提升
   到 `5000000`（本项目标准安全值，预防性调整）。
2. **`cmds/arch/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上（`cmds/wiz/update.lpc` 已是正
   确写法）。
3. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
4. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第十九条独立确
   认的血统——与同宗 xiaoyuxiyou 共享同一份 `obj/user.lpc` 架构、同
   一处 bug）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

`master.lpc::log_error()` 已经是正确的 `"arning:"` 大小写无关写法，
无需改动；本档案无 `adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录（GB/BIG5 选择→
"进入游戏(Enter)"菜单需送出字元 `1`，纯空白 Enter 不推进→id+密码）
确认 `目前权限：(admin)`，`update /adm/daemons/logind` 成功验证真
实写入权限。踢掉重复登录重连路径现场验证通过（见上）。`debug.log`
全程干净（744 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/cmds/arch/update.lpc`
- `work/obj/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 196 live occurrences deleted: 195 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as `xyxyutf8`/`xiaoyuxiyou`). 8 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40003.

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

## 深度功能测试第四轮 / Round-four §10.7 test (2026-08-20): death/respawn gap resolved

**Primary target: the one explicitly-flagged gap from the round-two deep
test above ("Explicitly NOT verified live: Death/respawn — not
reached").** Prior pass found real (non-scripted) combat against a weak
level-2 wild NPC (`d/city/npc/dog.lpc`, 黑狗, in 西芫街) converged to a
near-permanent stalemate with bare-fisted `unarmed` 1 — consistent with
the newbie guide's own advice to buy a weapon first, not a bug, but left
death/respawn genuinely unexercised.

**Resolved: real death and full automatic reincarnation confirmed
working end-to-end, twice independently, zero debug.log errors either
time.** Rather than fight logistics (weapon shopping), used the
session's standard sanctioned shortcut — admin `call`-based stat grants
on the existing `linfeng` character (id `linfeng`, already representative
from the round-two pass) to push a **real** `kill dog` fight to a
genuine conclusion, per this session's precedent that `kill` has no
NPC-target danger gate (confirmed by reading `cmds/std/kill.lpc`: the
40-level PK gate only applies `userp(me) && userp(obj)`; for an NPC
target `do_kill()` unconditionally calls `obj->kill_ob(me)`, i.e. the
NPC always fights back for real once `kill`ed).

Mechanism (traced from `feature/damage.lpc` and
`adm/daemons/combatd.lpc`): ordinary combat reduces both `kee` (health,
regenerates via `heal_up()`) and `eff_kee` (a separate, non-regenerating
wound/damage-cap stat, only reduced when the attacker
`is_killing()`, i.e. via a real `kill`, and floored at 1 point of wound
per landing hit). `std/char.lpc::heart_beat()` checks `eff_kee < 0` FIRST
on every tick → `die()` (unconditional, no unconsciousness stage); only
if that's still non-negative does a separate `kee < 0` check fire
`unconcious()` (a temporary faint + auto-revive, `t = random(100-con)+30`
seconds later, with `kee` regenerating back up via `heal_up()` in the
meantime — this is what the round-two pass's ~10-minute stalemate
attempt was actually seeing, misread at the time as "no death path").
To force the real branch: admin `call linfeng->set("eff_kee", <small
positive number>)` right before a real `kill dog`, so the next landed
wounding hit (guaranteed floor of 1 per `receive_wound()`) pushes
`eff_kee` negative and `die()` fires unconditionally on the next tick,
bypassing the recoverable-unconsciousness branch entirely.

**Verified twice, independently:**
1. First pass (accidental/unattended): admin lowered `eff_kee`, a real
   `kill dog` fight produced one landed hit and the expected
   `unconcious()` faint message ("你的眼前一黑，接着什么也不知道了");
   watching stopped there per the original plan, but real time
   continued to elapse in the background (heart_beat doesn't depend on
   an open connection) — a later reconnect found the character already
   fully cycled through: `is_ghost()` = 0, standing in
   `d/ourhome/kedian.lpc` (`REVIVE_ROOM`, 荒郊小店), inventory emptied
   (`lose_inventory()`, expected/documented design), money and base
   stats intact (matches this lib's own login banner promise: "本泥潭
   内，人物的金钱、潜能不会因死亡而有任何损失的").
2. Second pass (directly observed): admin `powerup(1,1)`-healed the
   character to full, teleported it directly to `/d/aolai/west1` via
   `call linfeng->move(...)`, set `eff_kee` critically low again, issued
   a fresh real `kill dog`, and reconnected partway through to catch the
   fight live: same "结果造成轻微的伤势" → "半昏迷状态" →
   "你的眼前一黑" sequence captured directly on-screen this time. Left
   the world running unattended for several more minutes (heart_beat
   keeps ticking headless) and reconnected again: character now standing
   in 荒郊小店, room description confirms this is the dedicated
   death/revival waystation (`生死之间留言板` — "Board Between Life and
   Death" — is the room's actual board name), `score` shows 气血 status
   "充沛" (fully recovered, not the "伤残" seen mid-recovery in pass 1),
   `eff_kee` back to exactly `query_maxkee()` (1072, both reset by
   `reincarnate()`+`powerup()` inside the judge NPC's dialogue chain),
   `is_ghost()` = 0, and — the clinching evidence that the REAL `die()`
   path executed rather than merely another faint — remaining lifespan
   ticked down by exactly 1 (79/80 → 78/80), matching `die()`'s own
   `life/life_time - 1` decrement, a field nothing else in this code
   path touches. `debug.log` stayed at zero `执行时段错误`/`Fatal`/
   `Too deep recursion` lines across the ENTIRE multi-stage test
   (boot through final `quit`), confirming no crash anywhere in the
   death → `DEATH_ROOM`(`阴阳界`) → judge NPC (`d/death/npc/pang.lpc`,
   崔判官/崔珏) dialogue → `reincarnate()` → `REVIVE_ROOM` chain.
   Also directly re-confirmed clean netdead/reconnect handling through
   this: an abrupt disconnect mid-unconscious-state, and again
   mid-post-death, both resumed correctly with no stranding, no
   duplicate object, no error.
3. Proactively checked the `combatd.lpc` `bounce`-division-by-zero bug
   pattern flagged this session on `sjpl2`/`sjplii`/`sjplgfjxb`/`fy2mg`
   (`while (... / bounce)` with `bounce /= 2` and no `bounce > 0`
   guard): `grep -n bounce adm/daemons/combatd.lpc` — **zero matches**,
   this lib's `combatd.lpc` is a different (unrelated) lineage, not
   affected.

No code changes were needed — this is a genuinely working, unmodified
system; the round-two "not reached" note was a coverage gap in testing
budget, not a latent bug. `linfeng`'s save state now reflects a
completed death/reincarnation (empty inventory, position in 荒郊小店,
78/80 remaining lifespan) — kept as-is per the "representative
playthrough character" precedent rather than reset, since this is now
arguably a MORE informative saved state (proves the full lifecycle
works) than the pre-death one.

### Standard checklist pass (fast confirm, all already fixed/clean)

- **§7.90** (`config.fluffos` eval-cost): already `5000000` (fixed in
  round three above). Confirmed, no change needed.
- **§7.100** (live `replace_program(ROOM)`): `grep -rn
  "replace_program(ROOM)" work --include="*.lpc"` → 8 hits, all already
  `//`-commented out (matches the round-three §7.100 sweep note: "8
  already-commented-out instances left untouched"). Zero live
  occurrences.
- **§7.111** (`standard_trace()`): only defined once, in
  `adm/obj/master.lpc`, standard non-recursive shape (`error_handler()`
  calls it once, no re-entry risk). Clean.
- **§7.112** (`death_stage()` reentrancy): only one live instance,
  `d/death/npc/pang.lpc` (the same judge NPC exercised live by this
  round's own death test above). Already correctly guarded: `init()`
  sets `death_stage_active` before the first `call_out`, and EVERY exit
  branch of `death_stage()` clears it — the early `!ob->is_ghost()`
  return, and the final branch after the message sequence completes
  (the mid-sequence branch that re-arms another `call_out` correctly
  does NOT clear the guard, since the cycle isn't done yet). No gap.
- **§7.108** (`reconnect()` calls `enable_commands()`): `obj/user.lpc`'s
  `reconnect()` already does this (fixed in round three above, and
  re-exercised live by this round's own repeated netdead/reconnect
  testing during the death cycle). Confirmed.
- **§7.79** (`addn()` 2-arg): `grep -rn "addn(" work` → zero matches in
  this lib. N/A.
- **§7.30** (`feature/skill.lpc` uninitialized-mapping guard): all
  relevant accessors (`query_skills()`, `query_learned()`,
  `query_skill_map()`) already use the `mapp(x) ? x : ([])` guard
  pattern (fixed in the 2026-08-20 corpus sweep above). Confirmed.

### Secondary target (not attempted, budget spent on the primary gap)

20级突破 puzzle dungeon and the 10-25级 loot dungeon: still not
attempted this round either — the death/respawn investigation (two full
cycles, real-time-gated) consumed this pass's full budget. Left for a
future round; see the round-two notes above for the newbie-guide entry
points.

## AGENTS.md §7.156 regression fix (2026-08-27, sibling-lineage sweep)

Found live on sibling lib `xyxyutf8`'s round-two deep test, then
confirmed by a corpus-wide grep sweep for the pattern across every lib
that received the original §7.30 accessor fix: `cmds/std/learn.lpc`'s
`if (!skills || !mapp(skills)) me->set_skill(skill, 1); else
skills[skill] = my_skill;` re-derives "never initialized" from
`query_skills()`'s return shape, but `feature/skill.lpc`'s own §7.30 fix
(`return mapp(skills) ? skills : ([]);`) means that check is now always
false for a brand-new character -- the `else` branch runs and mutates a
fresh, disconnected empty mapping instead of the character's real
internal state. The success message and potential-point deduction still
fire, but the skill itself is silently discarded: every player's
first-ever learned skill was affected. `set_skill()` in this lib already
handles both the never-initialized and already-populated cases
correctly (checks `!mapp(skills)` against the real instance variable),
so the fix is to always call it with the final value instead of
re-deriving the branch caller-side. Verified via `lpcc --batch` (single
file compile, PASS) -- not re-tested with a full live playthrough this
pass, since the fix is a mechanical port of the exact fix already
verified live on `xyxyutf8`. See AGENTS.md §7.156.

## Description-quality pass correction (2026-09-01, batch 26)

The pre-existing `meta.json` `english_description` claimed new characters
"start out in worldly scenes like Chang'an's Yingxiong Restaurant" — this
was a factual error. A grep for `英豪酒楼` across `work/` returns zero
hits (in this lib or in sibling `xiaoyuxiyou`), and the actual live-tested
starting room, confirmed repeatedly in this file's own round-two/three/four
deep-test sections above, is 翠香楼 (Cuixiang Tower) in 傲来国 (the Aolai
Kingdom) — Chang'an only enters the map later, as the destination of the
raft crossing on the way to the 百花谷 sect. Rewrote the description to
name the correct starting location and dropped the invented tavern name.

## AGENTS.md §7.19 sweep (2026-09-01): false positive, not fixed

Flagged by the corpus-wide scoping scan as sharing the `mhxy`/`wuhanzhan`
`enable_player()`-reentrancy-from-`init()` shape, but on closer
inspection this lib already carries its own, differently-shaped guard
(byte-identical to sibling `xyxyutf8`'s copy of `feature/command.lpc`):
`nosave int enabled = 0;` at file scope, and `enable_player()` only
calls the raw `enable_commands()` efun (plus `add_action("command_hook",
...)`) inside `if (!enabled) { enabled = 1; ... }`. Since `enabled` is
set to `1` *before* `enable_commands()` runs, any reentrant call into
`enable_player()` triggered as a side effect of that same
`enable_commands()` call sees `enabled == 1` and skips re-invoking the
efun -- the recursion terminates at depth 2 instead of running away into
"Too deep recursion." (Same pre-existing-guard pattern Batch C found on
sibling lib `xiaoyuxiyou`.) No `in_enable_player_now` mechanical fix
applied -- would be redundant with the existing `enabled` guard.
