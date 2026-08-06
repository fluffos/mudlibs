# 风云II (清华仿写版）.ZIP → `fy2qh`

- Archive: `archives/风云II (清华仿写版）.ZIP` (3.1MB — literally "Storm
  Rises Again II (Tsinghua University imitation/rewrite edition)"). Exact
  byte-duplicate `风云II (清华仿写版） (1).ZIP` skipped per AGENTS.md's
  duplicate-archives table.
- Mudlib root at `fy/` (extracted directly, no nested `fy/fy/` like fy2's
  raw layout), config at `fy/config.cfg`. Config's own `name` field already
  self-IDs as **风云再起Ⅱ** — the same in-game name as `fy2` (archive #17).
- Port: **40091** (next free after 40089-40090, reserved concurrently for
  archives #97-98 by sibling agents — confirmed those libs' directories
  were mid-extraction, not yet using the port, at the time this was
  assigned).

## Status: DONE — boots clean, full registration + post-login commands verified

## Lineage confirmation: this is (almost) literally `fy2`, not an independent "imitation"

Despite the archive's title implying a from-scratch clone ("清华仿写版" =
"Tsinghua imitation/rewrite edition"), this is evidence-based, not
assumption-based, confirmed to be the *same distribution* as already-shipped
`fy2` (archive #17, `风云再起Ⅱ`/Hohai University), not an independent
codebase sharing only a name:

- **`adm/obj/master.c` is byte-identical** (`md5sum` match) between this
  archive's raw extraction and `fy2`'s raw extraction.
- **All of the following core files are also byte-identical** (raw,
  pre-conversion): `adm/obj/simul_efun.c`, `adm/daemons/logind.c`,
  `adm/daemons/securityd.c`, `adm/simul_efun/chinese.c`,
  `adm/daemons/chinesed.c`, `feature/command.c`.
- **Whole-tree comparison**: 4071 files here vs 4073 in fy2's raw
  archive — a `diff -rq` of the two raw trees shows the only
  differences are player-save-data (`data/user/g/guest/guest.o`,
  `data/login/g/guest/guest.o` — different play sessions), two extra
  registered characters (`roses`/`zzzz`) present only in fy2's copy, log
  files (`debug.log`/`USAGE`/`ATTEMPT_LOGIN` — different session
  history), `mud.dat`, and the bundled prebuilt Windows driver binary
  itself (`mudos.exe`/`mudos.log` in fy2's copy vs `v22pre8.exe`/
  `v22pre8.tec` here — a different MudOS build bundled with the
  redistribution). **Zero source-tree content differences** were found.
  Every game-content file (rooms, NPCs, skills, daemons) is identical.
- **`convert_lib.sh`'s own mechanical-fix counts matched almost exactly**:
  9 local angle-bracket includes converted to quotes (fy2: 9),
  `static`→`nosave` touched 39 files (fy2: 39), yielding 2839 `.lpc` files
  (matches fy2's file count exactly).
- **The `lpcc_check.sh` sweep result is the clincher**: 2839 total, 2766
  pass, 73 fail — **exactly fy2's own previously-reported 97.4% pass
  rate (73/2839)** — and a direct diff of the two lpcc failure logs'
  file-name lists shows **zero differences**: the identical 73 files fail
  for the identical reasons in both libs (missing `PROP_*`/`TYPE_*` armor
  constants in a handful of `std/armor/*.lpc` files, a pre-existing
  content gap in the original codebase, not something this pass
  introduced).

**Conclusion**: this archive is not an independent "imitation" build —
it's the exact same `风云再起Ⅱ` codebase and content as `fy2`, redistributed
by a different site/mirror (name suggests a Tsinghua University hosting of
the same public release) bundling a different MudOS driver binary and a
different snapshot of player save data. Given this, every fix already
proven on `fy2` was ported directly rather than rediscovered.

## Fixes applied (all ported directly from `fy2`, verified identical need)

1. **AGENTS.md §15h (GBK byte-range Chinese-character detection)** —
   applied proactively before the first boot, using fy2's own already-fixed
   copy as the exact reference diff:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`) → CJK
     Unicode codepoint range check
     (`strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length
     bound (`< 2 || > 12`, message already says "一到六个中文字" / "1 to
     6 Chinese characters") halved to character count (`< 1 || > 6`);
     removed the `i%2==0 &&` even-byte-offset gate so every character
     position is checked, not just every other one.
   - Confirmed via two independent full interactive registrations, both
     with real Chinese given names (see below) — both accepted on the
     first attempt with no rejection.

No other fix was needed — every other proactive check (below) came back
clean, matching `fy2`'s own "zero fixes needed to boot" outcome exactly.

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon load recursion)**: `master.lpc`'s
  `valid_write`/`valid_read` only `find_object(SECURITY_D)` (no
  `load_object`), and `valid_read` is an unconditional `return 1;` — no
  recursive-load pattern present.
- **§7 (`get_root_uid`/`get_bb_uid`)**: both present in `master.lpc`,
  returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c (`valid_read`/`valid_write` overriding caller with
  `this_player()`)**: `securityd.lpc` has no `valid_read` at all, and its
  `valid_write` does not touch `this_player()`.
- **§8e (bare `tail()` efun)**: no `tail(` call anywhere in
  `simul_efun.lpc`/`master.lpc`.
- **§15ae (`private nomask` command-hook)**: `feature/command.lpc`'s
  `command_hook` is declared plain `nomask int` (not `private`) — the
  bug does not apply to this lineage (matches `fy2`/`zzfy`'s own
  confirmation of the same).
- **§15ar (`commandd.lpc` dead `.c$` sscanf)**: this lineage has no
  `commandd.lpc` file at all (command dispatch is handled entirely via
  `add_action`), so the bug class doesn't apply.
- **§15ag (`ed_start`/`ed_cmd`/`query_ed_mode`)**: no such calls anywhere
  in the tree.
- **§15l (`destruct(SIMUL_EFUN_OB)` in master's `create()`)**: master's
  `create()` is a single harmless `write()` line, no destruct/reload trick.
- **§15p (DNS/intermud daemon in preload)**: `adm/etc/preload` already
  has `#/adm/daemons/network/dns_master` commented out in the raw
  archive (and `#/adm/daemons/ftpd` too) — no edit needed.
- **§15v (`LONELY_IMPROVED`/nitan-family `efun::` gaps) / §15 (dbase
  simul_efun architecture bug)**: this is the ES II/"Annihilator" lineage
  (same family as `fy2`/`fy2005`/`fengyun434`/`zzfy`/`rzrmud`), which
  stores per-object properties via `inherit F_DBASE`-based local
  functions, not bare simul_efun calls — the nitan-family dbase-sharing
  bug does not apply here (consistent with `zzfy`'s and `rzrmud`'s
  findings that this bug is lineage-specific).
- **§15x (hardcoded `MUD_PORT` mismatch)**: `master.lpc`'s `connect()`
  takes no port argument and does no port-based dispatch at all — no
  hardcoded-port gate to mismatch.
- **§15ao (switch-with-only-default)**: no such construct found in
  `master.lpc`.
- Uppercase `.C` files, `.c`-named directories, and same-basename
  extensionless/`.c` backup pairs (§15ak): none found.

## Known, accepted, non-fatal issue

- **`emoted` daemon's save-data restore fails at boot** (caught by
  master's own `catch()` around `preload()`, non-fatal):
  ```
  执行时段错误：*restore_object(): Invalid utf8 string while restoring dbase.
  程式：/feature/save.lpc 第 19 行
  物件: /adm/daemons/emoted
  ```
  `data/emoted.o` (the daemon's seed emote-table save file) was flagged
  by `convert_lib.sh` as a LOSSY conversion (invalid GBK bytes dropped) —
  per AGENTS.md §1, a handful of save-data `.o` files can have genuinely
  undecodable bytes; this is seed/example data, not source, and the
  driver boots and reaches `Accepting telnet connections` regardless.
  Not fixed (matches project convention for this exact class of issue).

## Interactive test — full registration flow (TWO independent runs, one continuous connection each)

**Run 1** — id `qinfengtest` → `y` (confirm new character) → Chinese name
**秦风** (accepted immediately, no rejection — the §15h fix's proof) →
password `TestPass123` (set + confirmed) → email → gender `m` → nationality
`0` (汉族) → entered the game world at `/d/fy/fqkhotel` (凤求凰客栈), NPC
店小二 present. `score` produced a full, correct character sheet ("普通百姓
秦风(Qinfengtest)... 你是一位汉族十岁的男性人类..." with all 12 stat
lines, attack/defense values, 参数点). `quit` dropped starting inventory and
disconnected cleanly ("欢迎下次再来！").

**Run 2** (separate connection, different id/name/ethnicity, explicit
`look` + `score` + `quit` sequence to unambiguously distinguish command
output from the automatic on-entry room view) — id `zhaoritian` → `y` →
Chinese name **赵日天** (again accepted immediately) → password
`TestPass456` → email → gender `f` → nationality `1` (苗族) → entered the
game world at a DIFFERENT starting room, `/d/chenxiang/cxcenter` (沉香镇中
心 — confirms the nationality-based start-room branch works), with live
NPCs (地头蛇 ×2, 卖鱼的, 买鱼的小姑娘) actively emoting in real time
(买鱼的小姑娘问道："这鱼怎么卖？" between my `look` and `score` sends —
proof this is a live, ticking game world, not a static scripted reply).
`look` produced the room description + exits + NPC list; `score` produced
"普通百姓 赵日天(Zhaoritian)... 你是一位苗族十岁的女性人类..." with
correct stats distinct from Run 1's character; `quit` again dropped
starting inventory and disconnected cleanly.

Both runs confirm: real Chinese names are accepted (§15h fix verified
twice, independently), the character actually lands in the game world (not
a void/missing-room failure per §15aj), and ordinary post-login commands
(`look`, `score`) produce real, correct, differentiated output (§15ae/§15ar
checklist satisfied — no command-dispatch bug present).

Noted, not a bug (same as `zzfy`'s identical finding): `get_name()` has a
pre-existing `printf("%O\n", ob);` debug line that prints the login
object's default toString (e.g. `/obj/login#10`) right before the password
prompt on a successful Chinese name — leftover debug output from the
original author, harmless, out of scope to remove.

## lpcc sweep

`scripts/lpcc_check.sh` — **2839 total, 2766 pass, 73 fail (97.4%)**.
Failures are exclusively pre-existing content gaps (a handful of
`std/armor/*.lpc` files reference `PROP_*`/`TYPE_*` constants that were
never `#include`d/`#define`d anywhere in this codebase — a real gap in the
original archive, confirmed present identically in `fy2` too) plus the
`emoted` restore issue above. Diffed the full list of failing file names
against `fy2`'s own `lpcc_fail.log` — **zero differences**, the identical
73 files fail for the identical reasons in both libs, reinforcing the
lineage finding above. Not triaged further given the small count and that
none affect the boot/registration/gameplay path exercised.

## How to run

```
cd libs/fy2qh
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40091 --timeout 25 --idle 0.5 \
  --send "yourid" --send "y" --send "你的中文名" \
  --send "yourpassword" --send "yourpassword" --send "you@example.com" \
  --send "m" --send "0" --send "look" --send "score" --send "quit"
```
(`m`/`f` selects gender; `0`-`3` selects ethnicity, which determines the
starting room; the English id must be pure letters, 3-12 chars, or
`check_legal_id` rejects it and re-prompts.)

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 2839 `.lpc` files; 2837
  reformatted, 2 unchanged, **0 errors** — cleanest self-check result of
  this batch.
- **Native retest against rebuilt driver — 1 regression found + fixed**:
  a mistimed test send sequence (missing the extra blank line for the
  post-registration "请敲回车键[RETURN]" prompt, so the following
  in-flight command landed while the character's move-into-room was
  still completing) reproducibly crashed `quit` with `*Bad argument 3 to
  EFUN message() ... Got: int(0)` — `cmds/usr/quit.lpc`'s farewell
  broadcast, `message("system", ..., environment(me), me)`, assumed
  `environment(me)` is always non-zero. Since the crash aborts the rest
  of `quit()` (the actual disconnect never runs), the connection stays
  open and every subsequent `quit` repeats the identical crash — a
  narrow but real robustness gap, not just a test-script artifact, since
  a real client racing the RETURN-prompt/room-entry sequence could hit
  the same window. Fixed by guarding the call with `if (environment(me))`
  (same shape as this project's other `message()`/`tell_room()`
  null-target hardening, see AGENTS.md §15s). Re-verified clean twice:
  once reproducing the exact mistimed sequence (no crash after the fix)
  and once with a correctly-paced full registration + `look`/`score`/
  `quit` run (real Chinese name 段公子), zero debug.log errors either
  way.
- **WASM test**: boots and plays fully — full registration with a real
  Chinese name (慕容复), `look`, and `quit` all completed cleanly with no
  errors of any kind (not even the usual non-fatal sockets-package
  warnings — this lib doesn't preload a network daemon). Not affected by
  the documented `query_ip_number()` WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

Identical to sibling `fy2` (风云再起Ⅱ, 011).

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` `is_banned()`
  (~line 47) — short-circuit for non-string / empty / `127.0.0.1` /
  `localhost` / `127.`-prefix. Called from `adm/daemons/logind.lpc:72-73`
  with both `query_ip_name()` and `query_ip_number()`.
- **Uptime gate / anti-flood throttle**: none found.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`.
  Registered through the real flow; verified re-login +
  `update /adm/daemons/combatd` → 成功. Retest: fresh normal registration
  (秦风) with working `look`/`score` (test char saves removed).
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
  `libs/fy2qh/work/data/user/f/fluffos/fluffos.o`,
  `libs/fy2qh/work/data/login/f/fluffos/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-07-25, round two)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + WASM boot). This lib was flagged as
a **confirmed byte-identical sibling** of `fy2` (风云再起Ⅱ, archive #17),
which was deep-tested immediately before this pass and found 6 bug
classes plus 3 corrupted save-data files (see `libs/fy2/NOTES.md`'s own
"深度功能测试" section). Confirmed via `diff -rq` of both `work/` trees:
every difference was either (a) exactly the fixes fy2's pass already
applied, not yet ported here, or (b) unrelated player-save/log/config
noise. **All of fy2's fixes were ported directly** (same file:line shape,
same root cause) rather than rediscovered from scratch, then the full
playthrough was run independently on this lib's own driver/port (40091)
to confirm each fix actually works live here too, not just by code
inspection. Native driver (`build-debug`) only — WASM not re-verified
this pass (all fixes are shared LPC/data-file changes with no
WASM-specific risk, stated explicitly rather than silently skipped).

Test characters kept as playthrough evidence (native saves, untracked):
`duanmuqing`/端木青 (male, 金钱帮 third-generation disciple under 荆无命,
`data/user/d/duanmuqing/`, learned 基本剑术 from him, fought 登徒子 to
partial HP loss and disengaged safely), `muyanqing`/慕言卿 (female, used
for the final full end-to-end regression after all fixes + revert of
diagnostic instrumentation, `data/user/m/muyanqing/`). Both in the
Han-ethnicity start room 凤求凰客栈.

### Fixes ported from `fy2` (confirmed present here, byte-identical bug shape, now fixed identically)

1. **`adm/simul_efun/message.lpc` — AGENTS.md §7.12**, the shared
   `tell_room()` 2-arg exclude bug (`exclude || ({ })`).
2. **`d/death/npc/bgargoyle.lpc`, `wgargoyle.lpc`, `d/death/inn1.lpc` —
   AGENTS.md §7.24**, death/limbo code stomping the permanent
   `startroom` login-location field. Removed the `set("startroom", ...)`
   calls; the `move()` already handles the immediate post-death
   placement. Not exercised via an actual live death this pass either
   (see "Not verified live" below) — ported on the strength of the exact
   code-shape match to fy2's own already-verified fix.
3. **`std/room.lpc`'s `make_inventory()` — AGENTS.md §7.25**, unguarded
   `new()`/`move()` chain. `catch(ob = new(file)) || !objectp(ob)` plus
   an `objectp()` guard at the `reset()` call site. Same root cause as
   fy2 (`/obj/sbaa/rong.lpc`'s `set_skill("wu-shun", ...)` throwing on a
   skill missing from this archive's tables) — confirmed still present
   and still failing the same way via this lib's own `lpcc` sweep
   (`/obj/sbaa/rong` still FAILs individually, as expected — a genuine
   content gap, not a code bug — but no longer takes its owning room
   down with it: `/obj/sbaa/ym` was NOT in this lib's own pre-fix
   `lpcc_fail.log` extras beyond the known 73, matching fy2's finding
   that the room recovers cleanly after the `catch()`).
4. **`std/bboard.lpc`, `std/jboard.lpc`'s `setup()` — AGENTS.md
   §7.7-adjacent**, unguarded `move()`/`restore()` collateral-damaging
   the owning room/caller. Both calls now wrapped in `catch()`.
5. **`adm/daemons/emoted.lpc` — AGENTS.md §7.7**, same
   restore()-throws-uncaught shape, silently disabling the entire
   emote-command system mudlib-wide. `catch(restore())` +
   `if (!mapp(emote)) emote = ([]);`.
6. **`d/waterfog/{hall1,jobroom}.lpc`, `obj/board/{wizard_b,wizard_j}.lpc`,
   `feature/alias.lpc` — new bug class (stale `/d/wiz/` paths from a zone
   rename to `/d/waterfog/`)**, ported identically: exits/`"location"`
   fields pointed at the nonexistent old path, and the anti-bot teleport
   in `alias.lpc` would have silently dropped an accused player into
   environment 0. Fixed to `/d/waterfog/...` (or `__DIR__`-relative);
   added an `objectp()` guard on the alias.lpc teleport as defense in
   depth.
7. **`feature/command.lpc`'s `enable_player()` — AGENTS.md §7.28**,
   redundant `add_action` stacking (`revive()` re-enabling commands on
   every ordinary combat knockout, not just death). `remove_action()`
   before the `add_action()`, matching fy2's guard shape exactly (not
   `living()`-gated, per §7.28's own caution).

**Data fix**: `data/emoted.o`, `data/board/fysquare_b.o`, and
`data/board/poem_b.o` were confirmed **byte-identical (md5sum match)**
to fy2's own pre-fix raw archive copies (`libs/fy2/raw/fy/fy/data/...`
vs `libs/fy2qh/raw/fy/data/...`) — i.e. this lib genuinely
ships the exact same GBK-un-transcoded / embedded-raw-newline corruption
fy2's pass diagnosed and fixed, not just a superficially similar issue.
Rather than re-deriving the quote-aware `\r\n`→`\r` transcoding scanner
from scratch, fy2's already-fixed, already-verified output files were
copied over directly (`cp libs/fy2/work/data/{emoted.o,board/fysquare_b.o,
board/poem_b.o} libs/fy2qh/work/data/...`) — safe specifically
*because* the raw inputs were confirmed byte-identical first. Spot-checked
all three decode as valid UTF-8 with sane, readable Chinese text before
and after copying (not just trusted the copy to have succeeded). Also
removed the same three-file debris fy2's pass found and removed:
`data/emoted.lpc` (a stray, unreferenced ~130KB duplicate of the emote
database misnamed with an `.lpc` extension — confirmed unreferenced by
any `inherit`/`load_object`/`call_other` here too) and
`data/emoted.o.new`/`data/emoted.o.old` (stale debris from an earlier
abandoned fix attempt, predating this pass).

### Live verification (native driver, port 40091)

- **Registration**: real Chinese names, both genders (端木青 male,
  慕言卿 female), full flow, landing in the Han-ethnicity start room
  (凤求凰客栈) with 店小二 present, matching `doc/help/newbie`'s
  documented room list (identical text to fy2's own newbie guide).
- **`score`/`hp`/`i`**: correct at every stage (fresh, post-sect-join,
  post-skill-learn, post-combat).
- **Movement/exploration**: walked 凤求凰客栈 → 南风大街(×1) →
  风云广场 → 西云大路 → 探花诗台 (poem board zone), and separately
  凤求凰客栈 → 南风大街 → 金钱帮大院 → 会客厅 → 黄衣室 → 帮主堂
  (金钱帮总舵) and 凤求凰客栈 → …→ 北风大街(×5) (登徒子's spawn room).
  All room transitions and NPC placements rendered correctly, no
  `couldn't find object` anywhere along either fixed path
  (`d/waterfog/` itself, home to the two other path fixes, was
  confirmed fixed via `lpcc` PASS status rather than walked live this
  pass — see "Not verified live" below).
- **Board system**: 风云广场留言版 read as **13 messages, 13 unread**
  and 探花诗台 as **4 messages, 4 unread** — exactly matching fy2's own
  post-fix message counts, confirming the copied data files are not
  just valid UTF-8 but structurally intact/correctly restored (same
  real board content, not an empty or truncated fallback). `read 1` on
  the poem board correctly displayed real 1998-era archived content.
- **Emote system**: `smile` → "你愉快地微笑着。", `nod` → "你点了点头。" —
  both render real Chinese flavor text (previously would have been
  "什麽？", unrecognized command, on the un-transcoded `data/emoted.o`).
- **Sect-join mechanism**: `apprentice master jin` on 荆无命
  (帮主堂, 金钱帮) completed immediately; `score` afterward correctly
  showed "金钱帮第三代弟子" title and "你的师父是荆无命。".
- **Organic skill-learning**: `skills master jin` correctly listed his
  10 skills (no `unarmed`, matching fy2's own documented caveat).
  `learn sword from jin with 5` (while standing in the same room as
  him, per `learn`'s `present()` requirement — an early attempt from a
  *different* room correctly failed with "你要向谁求教？", not a bug,
  just `learn` requiring co-location like any teacher-interaction
  command) succeeded: "你听了荆无命的指导，似乎有些心得。你的「基本剑术」
  进步了！".
- **Combat**: no dedicated stat-mirroring training dummy reachable from
  the Han start zone (`obj/muren.lpc` only placed in `d/snow/`, matching
  fy2's own finding). Followed the same fallback: fought 登徒子
  (`d/fy/npc/dtz.lpc`) at 北风大街 — exchanged rounds, took moderate
  non-critical damage (250→120/250 HP), disengaged safely.
- **Shop**: `list waiter` at 凤求凰客栈 correctly showed the price table;
  `buy dumpling from waiter` correctly refused with "你的钱不够" (a
  brand-new character starts with 0 money) — **not completed live**,
  same as fy2's own finding; reaching real starting capital was outside
  this pass's time budget.
- **`quit` + debug.log grep**: clean on every explicit `quit` this
  session (7+ across multiple test connections), zero
  `error:`/`Too deep recursion`/`Bad argument`/`couldn't find
  object`/`Illegal file format`/`Invalid utf8` lines beyond routine
  compiler warnings, confirmed via `grep` immediately after each quit,
  not just eyeballing the farewell message.
- **Net-dead / reconnect (prompt)**: disconnect without `quit`,
  reconnect within seconds — lands back in the same room with
  "重新连线完毕。", no void-parking, no RETURN-prompt re-ask (that only
  appears on a genuinely fresh login). Zero new debug.log lines from the
  cycle.
- **Clean-quit reconnect after a real wait**: `quit`, waited a real
  3 minutes (180s wall-clock, one blocking `sleep 180 && <reconnect
  command>`), reconnected — full fresh-login flow (RETURN prompt, as
  expected for a真-quit, not a netdead-reconnect), state fully persisted
  (sect membership, stats, title). Zero new debug.log errors (6 new
  lines were routine `look.lpc`/`score.lpc` recompile warnings from the
  object having been swapped out under `time to swap: 120` and reloaded
  — not errors).
- **Net-dead / reconnect after a real long wait — see dedicated section below.**
- **State persistence across driver restarts**: rebooted the native
  driver 3 times over this pass (once per batch of fixes, once to clear
  temporary diagnostic instrumentation); each time, reconnecting as
  `duanmuqing` correctly restored location, sect membership, and stats
  from disk.

### Net-dead auto-force-quit at the real `NET_DEAD_TIMEOUT` (900s): reproduced fy2's "stuck net-dead" anomaly, but with new evidence narrowing it to something OTHER than a concurrent-lpcc-sweep confound

`fy2`'s own pass hit one occurrence of a net-dead session's `user_dump()`
call_out apparently never firing at the real 900s mark, flagged as "an
unresolved, likely environmental/non-reproducible anomaly" and tentatively
attributed to a concurrent `lpcc --batch` sweep running against the same
work tree at the same time as a plausible-but-unproven confound (see
`libs/fy2/NOTES.md`).

**This pass reproduced the identical symptom, independently, with that
specific confound ruled out**: disconnected `duanmuqing` without `quit`
at 00:47:31, then waited (via two sequential blocking `sleep` calls
totaling ~1050 real seconds, no other process touching this lib's work
tree during that window) well past the 900s `NET_DEAD_TIMEOUT` threshold
(due at 01:02:31). At 01:04:59 (~17.5 real minutes post-disconnect), the
character was still shown net-dead — no "quits at ..." line had been
written to `log/USAGE` for that session, and `debug.log` showed zero new
content of any kind (not even the routine ambient-NPC compile-warning
noise that later reconnects showed). A subsequent reconnect attempt went
through the **full fresh-login flow** (RETURN prompt etc.), not the fast
"重新连线完毕" netdead-reconnect path — meaning the interactive body
object was no longer around/link-dead-recognized by that point, yet no
`user_dump`/`quit` completion was ever logged. **Zero trace in
`debug.log`**, matching the general shape (though not the specific
FATAL-crash symptom) of the driver-level anomaly class catalogued in
AGENTS.md §10.8 — the driver process itself stayed alive and healthy
throughout (confirmed via `ps`), so this is not a §10.8 FATAL crash, just
a scheduled `call_out` whose effects never became visible.

**Follow-up isolated the mudlib code itself as almost certainly NOT at
fault**: temporarily shortened `NET_DEAD_TIMEOUT` (`include/user.h`) from
900 to 12 seconds and added `write_file()` instrumentation at
`net_dead()`'s `call_out()` registration and at the top of
`user_dump()`/immediately before `command("quit")` (both reverted before
finishing — `diff` against `fy2`'s byte-identical copy confirms zero
residue). Rebooted, repeated the exact same disconnect-and-wait sequence
at the shortened interval: **fired perfectly reliably** — `call_out`
registered at 01:08:05, `user_dump(1)` invoked at exactly 01:08:17 (12s
later, precisely on schedule), `command("quit")` completed and logged
`duanmuqing quits at Sat Jul 25 01:08:17 2026` to `USAGE` correctly. This
strongly suggests `net_dead()`/`user_dump()`'s own LPC logic is correct
and reliable — the failure mode is specific to *very long* real-time
`call_out` delays specifically, not the code path itself.

**Plausible alternative explanation, offered honestly as unproven**: this
finding spans multiple separate blocking shell-tool invocations (the
harness's own tooling constraints cap a single blocking wait well under
900s, so the real wait was assembled from sequential `sleep 550` /
`sleep 400`-shaped calls across separate tool invocations, each ending
and restarting a fresh tool call). If the sandboxing environment
suspends/deprioritizes background (non-foreground-owning) processes
between tool-call boundaries as a resource-management measure, a
long-delay `call_out` timed against a clock that doesn't advance (or
whose driver-side scheduling loop doesn't get CPU time to notice it) for
part of that span could plausibly miss its own firing window in a way a
12-second delay, entirely contained within one blocking call, never
would. This would make the anomaly a **testing-environment artifact**,
not a genuine mudlib or even driver bug — but this is offered as a
plausible hypothesis, not a proven root cause; no direct evidence (e.g.
driver-side scheduler logs) was gathered to confirm or rule it out, and
`fy2`'s own occurrence happened within a single, differently-shaped test
session. Documented honestly per AGENTS.md's standing instruction to
record rather than guess, and to give the human maintainer this
corroborating (now twice-independent) data point rather than silently
re-flagging it as "unresolved" without the new context. **Not treated as
a mudlib bug and not fixed** — the short-timeout test is strong evidence
the actual `net_dead()`/`user_dump()` code is correct.

### Not verified live, and why

- **Death/reincarnation flow** (fix #2 above): established by exact
  code-shape match to fy2's own already-verified fix, not by walking a
  character through an actual death — reaching a real death safely
  within budget wasn't feasible after the extensive net-dead
  investigation above.
- **`d/waterfog/` zone itself** (fixes #6's `hall1.lpc`/`jobroom.lpc`
  room files): confirmed fixed via `lpcc` PASS status (not in this
  lib's own `lpcc_fail.log`, matching the pre-fix failures that used to
  appear there) and via the exact code-identical fix to fy2's own
  live-verified instance, but not walked to directly this pass (it's
  reachable only via `d/snow/`, a different ethnicity's starting zone,
  outside this pass's time budget after the net-dead investigation).
- **`enable_player()` double-stacking** (fix #7): not reproduced via an
  actual knockout+`revive()` cycle; verified only that the fix doesn't
  break the many ordinary `command_hook` dispatches already exercised
  this session (registration, movement, combat, sect-join, learn,
  emotes, board reads, shop).
- **The net-dead 900s stuck anomaly**: actively investigated (see
  dedicated section above), root cause narrowed but not conclusively
  pinned — explicitly flagged as unresolved/environmental rather than
  presented as diagnosed-and-fixed.
- **WASM**: not re-tested this pass (native-only); all fixes are shared
  LPC/data-file changes with no WASM-specific risk identified.

### Testing-methodology note: `lpcc --batch`'s blanket load-and-`create()` can trigger dead admin-utility side effects

While diagnosing an unexpected ~457-file mass-touch of pre-existing
shipped player-save data (`data/user/*/*.o`, all reduced to a harmless
key-reordering + one intentional-looking `"title_race":0` reset when
diffed against the committed originals), traced the cause to
`adm/daemons/startrace.lpc` — a ranking/leaderboard recalculation daemon
whose `create()` unconditionally calls `init_race()` → `findthem()`,
which `restore()`s and re-`save()`s **every single registered player's
save file** and resets everyone's `"title_race"` field to 0 before
reassigning top-3 badges. This daemon is **not preloaded and not called
by any other live code path** in this archive (confirmed via
grep — genuinely dead/orphaned, presumably meant to be invoked manually
by a wizard, never wired up) — it does not run during ordinary gameplay
at all. It ran anyway because `scripts/lpcc_check.sh`'s `lpcc --batch`
sweep (run earlier this pass, before ever booting the live driver) loads
and compiles *every* `.lpc` file in the tree by path, which triggers each
object's `create()` exactly like a real `load_object()` would — including
this one. **Reverted all 457 incidentally-touched files** (`git checkout
--`) back to their committed state after confirming via a full
character-level diff that every touched file's content was either an
exact match modulo key order, or the intentional-but-unwanted
`title_race` reset — none were genuinely lost/corrupted, so the revert
was safe. Left `startrace.lpc` itself untouched (its behavior is
presumably intentional wizard tooling, not a bug, and out of this pass's
scope) but flagging the general lesson: **an `lpcc --batch` sweep is not
side-effect-free** on any lib whose `create()` functions do more than
initialize state — run it (or budget for its side effects) before
setting up test-character save data you intend to keep as evidence, and
sanity-check `git status` afterward for surprise touches, same
discipline as checking `debug.log` after `quit`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
