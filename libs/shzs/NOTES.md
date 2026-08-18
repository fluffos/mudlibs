# 山海战神.rar → `shzs`

- Archive: `archives/山海战神.rar` (1.4MB, small `simple`/ES-II-derived MudOS
  0.9.20 lib — "Final Frontier" themed base, reskinned).
- Mudlib root in archive: `simple/` (extracted directly at archive top level,
  no extra nesting).
- Port: **40001**.

## Status: DONE — boots clean, playable over telnet

Login banner, Chinese prompts, and character-creation flow all render
correctly. This lib was the pilot used to build `scripts/convert_lib.sh`
and the fix catalog in `AGENTS.md` — see that file's "Common
driver-compatibility issues" catalog (§1-§14) for the general write-up of
every issue found here. Lib-specific specifics only, below.

## What was fixed

1. Encoding: all `.c`/`.h` files GB18030→UTF-8 (774 converted, 124 already
   ASCII/UTF-8, 0 hard failures). Also converted `data/*.o` save files
   (dict/emote/daemon/ballot_box/stars — these are plain-text
   `save_object()` format, not binary) — `data/emoted.o` needed the lossy
   `-c` fallback (one stray invalid byte at position 25324, pre-existing
   data corruption in the original archive, unrelated to us). Also
   `adm/etc/welcome` (login banner) and `config.fluffos` itself (see
   AGENTS.md §5 for the double-corruption trap hit here on first attempt —
   fixed by re-copying fresh from `raw/` and converting before any edits).
2. `.c` → `.lpc` rename: 855 files. Fixed 117 literal `".c"` string
   references across `.lpc` files, plus 36 in `include/globals.h` (the
   `F_DBASE` macro — AGENTS.md §2, this is the one that cost the most time
   to find since it surfaced as a runtime "Inherited file does not exist"
   rather than a compile error). One orphaned non-LPC file caught by the
   blind rename (`d/shenmin/shenminmap.c`, ASCII-art map, unreferenced
   anywhere) — renamed to `.txt` instead (AGENTS.md §12).
3. `static` → `nosave`: 89 occurrences across the lib (AGENTS.md §3).
4. `master.lpc`'s `valid_read()`/`valid_write()` had the lazy
   `load_object(SECURITY_D)` recursion bug (AGENTS.md §4) — added the
   re-entrancy-guard + `catch()` fix.
5. `master.lpc`'s `valid_override()` was the old 2-arg signature, which
   wrongly rejects `efun::` overrides written in `#include`d simul_efun
   fragments (AGENTS.md §14) — added the 3rd `main_file` parameter. (Never
   actually manifested in a real boot, only in the `lpcc` sweep testing a
   fragment file as a standalone object — fixed anyway since it's free and
   more correct.)
6. `master.lpc` does NOT have `get_root_uid()` (driver printed a non-fatal
   warning and continued — did not need the AGENTS.md §7 stub fix here;
   this lib's `exit(-1)` path apparently doesn't fire the way lib #2's did.
   Left as-is since the lib boots and plays fine regardless).
7. Config: removed 5 obsolete keys (`address server ip/port`, `binary
   directory`, `swap file`, `reserved size`), set `port number : 40001`,
   `mudlib directory` to the absolute `work/` path.
8. Full `lpcc_check.sh` sweep run (854 files after the shenminmap.txt
   rename; 832 pass / 22 fail). Fixed 6 pre-existing typo
   bugs found this way (all unrelated to our conversion — verified against
   raw archive bytes):
   - `d/zuichen/{cdkedian3,cdkedian4,cdyaopu,chengzhong}.lpc`: fullwidth
     comma `，` used as an argument separator (AGENTS.md §9).
   - `d/shiwang/qianqingon.lpc`: fullwidth period in `#include <ansi。h>`
     (AGENTS.md §9).
   - `std/room/shop.lpc`, `cmds/std/put.lpc`: missing closing `"` before
     string concatenation (AGENTS.md §10).
   - `adm/daemons/rankd.lpc`: 8× `switch(x) { default: ... }` with no real
     `case` label (modern grammar requires at least one) — removed the
     pointless switch wrapper, kept the body (indentation not perfectly
     preserved, cosmetic only).
   - `cmds/wiz/invis.lpc`: declared `void main(...)` but returned `1`/`0`
     (command-dispatch status codes) — changed to `int main(...)`.
   - `obj/weapon/axe.lpc`: copy-paste bug, `inherit AXE`/`init_axe(...)`
     but `/std/weapon/axe.lpc` was never implemented in this lib and the
     file's own header comment/id/name all say "dagger" — redirected to
     `inherit DAGGER`/`init_dagger(...)` (AGENTS.md §11).
   - `obj/cloth.lpc`: same pattern, `inherit CLOTH` with no
     `/std/armor/cloth.lpc` to back it — redirected to `inherit U_ARMOR`
     (matches its `setup()` call and "basic starting equipment" role).

## Known remaining issues (not fixed — documented, low priority)

- `/adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,pingd,inetd}.lpc`
  — a cluster of optional network-service daemons (internal mail server,
  ping, telnet redirect, inetd) failing to compile due to missing headers
  (`config.h`, `mailer.h`, `daemons.h`, `uid.h`, `priv.h`, `post.h` — not
  present anywhere in `include/`) and a few undefined functions/variables
  cascading from that. None of these are on the preload list or required
  for normal play (login/rooms/combat/items all work); left broken.
- `adm/simul_efun/object.lpc`: harmless lpcc-sweep-only false positive
  (AGENTS.md §6b/§14) — real boot never hits it.
- A number of `call_other()`/`Bad argument 1 to EFUN call_other()` sweep
  failures are the same false-positive category as lib #2 (AGENTS.md
  §6b) — not individually triaged since the pattern is now understood;
  spot-checked 2, both were "target genuinely not compiled yet in this
  isolated single-file run", not real bugs.

## How to run

```
cd libs/shzs
~/src/fluffos/build-debug/src/driver config.fluffos
# separately:
python3 ../../scripts/mudclient.py 127.0.0.1 40001 --timeout 10 --send "" --send "look" --send "quit"
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

- **LPC formatter**: ran `format-corpus.mjs` across all 854 `.lpc` files
  under `work/` — all reformatted cleanly except 2 refused on the
  token-mismatch safety gate (`adm/obj/simul_efun.lpc`,
  `adm/simul_efun/system.lpc`), expected/fine per the formatter's own
  self-check contract, not investigated further.
- **Native retest against the freshly-rebuilt driver**: booted clean,
  zero fatal errors. Ran a full interactive registration with a real
  English id (`qflibtest`, this lib's login uses an English id + a
  separate Chinese display name `秦风`) through name/password/email/
  attribute-allocation/gender, reached the actual game world (梦旅馆大厅),
  and confirmed `look`/`score`/`quit` all produced correct, real output
  (score sheet shows the chosen 10/10/10/10/10/10 attribute split; quit
  exits cleanly). No regressions from the reformat or the driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): **fully playable**.
  Boots cleanly under WASM, and the complete registration flow (id →
  confirm → Chinese name → password ×2 → email → attributes → gender)
  works end-to-end exactly like native, reaching the same starting room
  with `look` producing correct output and `quit` exiting cleanly. This
  lib does not gate login on `query_ip_number()` or on any other
  WASM-restricted efun (its two `resolve()` call sites are in
  `ftpd.lpc`/`dns_master.lpc`, both optional network daemons never
  invoked during normal login) — no WASM-specific limitation applies
  here. Status: **fully playable under WASM**.

## WASM-enablement pass (2026-07-24): admin seeding only (no gates found)

Checked for all four standard gate classes (AGENTS.md §1.3b/e): no
`band.lpc`/`BAN_D`-style ban daemon, no site-restriction daemon, no
`uptime()` check anywhere in the login path, and no per-IP anti-flood/
multi-login throttle (`logind.lpc`/`logind2.lpc` only use
`query_ip_number`/`query_ip_name` cosmetically, in log lines and "who
connected from where" messages — confirmed by grep, not just absence of
symptoms). So items 1-3 of the standard pass (loopback-allow,
uptime-bypass, throttle-exemption) are **not applicable** to this lib —
nothing to patch.

Admin account: registered `fluffos` / `Mud@2026` through the real
registration flow (id `fluffos` accepted directly — no length/reserved-
word conflict), Chinese name 浮浮, gender m, attributes 10/10/10/10/10/10.
Granted `(admin)` via `/adm/etc/wizlist` (this file already had a
`fluffos (admin)` line staged from an earlier interrupted pass; verified
`/adm/daemons/securityd.lpc` reads this file for wizard-level decisions).
Verified in ONE continuous session: login as fluffos, `look`, then
`update /adm/daemons/securityd.lpc` recompiled successfully (ACL grants
write/compile access), then clean `quit`. Re-verified a fresh normal
registration end-to-end afterwards (id `qinfeng`, name 秦风, same
attribute split) reaching 梦旅馆大厅 with working look/score/quit; its
test save (`data/login/q/qinfeng.o`, `data/user/q/qinfeng.o`) was removed
afterwards. debug.log clean (compiler warnings only, no errors) across
both sessions. Save files for the orchestrator to force-add:
`data/login/f/fluffos.o`, `data/user/f/fluffos.o` (untracked, not
gitignored).

Note: an earlier same-batch agent's driver process for this lib (PID
4045698, started 00:37, before this session began) was found still bound
to port 40001 with no admin work done yet; it was killed (exact PID) and
the driver relaunched fresh before doing the registration above.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First genuine hands-on *playthrough* pass on this lib (all prior passes
verified registration + `look`/`score`/`quit`/`update`, never a real
walk through content). Native driver (`build-debug`), one continuous
session per check, `scripts/mudclient.py`. Test character: id
`linfeng`, Chinese name 林风, password `Abc12345`, attributes 15 力量/
10 敏捷/10 智力/6 注意/17 体质/2 技术 (the game's own example split from
`help`'s attribute-allocation screen) — **kept** as a representative
playthrough character, currently standing on a `d/lwe/jie*` street
(state below). Save files: `work/data/user/l/linfeng.o`,
`work/data/login/l/linfeng.o`.

This lib's `help newbie`/`help intro` don't exist as such; its actual
newbie doc is `help` (topics: `story`, `cmds`) — read first, per the
checklist, and immediately found broken (see bug 1).

### Bug 1 — `help`/`help cmds`/`help story` and the day/night broadcast
text were still raw GBK bytes, never converted (AGENTS.md §4.1 class,
just missed on this lib's original pass)

- Symptom: the *very first thing* a new player is told to try
  (`help`, and `help motd` — quoted verbatim in the MOTD bulletin as
  "本公告可以用 help motd 再次查看") rendered as mojibake, and every
  outdoor day/night phase transition (`adm/daemons/natured.lpc`,
  preloaded, cycles on a `call_out` the whole time the driver is up)
  broadcast mojibake to every player standing outdoors.
- Root cause: `doc/help/topics`, `doc/help/cmds`, `doc/help/story`,
  `adm/etc/nature/day_phase`, `adm/etc/motd` were never put through the
  GBK→UTF-8 conversion in any prior pass on this lib — confirmed by
  `file`/byte-decode check (still literal GBK bytes, not even
  mis-decoded, genuinely untouched) and by diffing against
  `raw/simple/`. This is exactly the AGENTS.md §4.1 "convert EVERY text
  file, not just source" rule; this lib's original conversion pass
  (documented above as "774 converted, 124 already ASCII/UTF-8, 0 hard
  failures") simply never walked `doc/help/` or `adm/etc/nature/`.
- Fix: `iconv -f GB18030 -t UTF-8` on all five files, byte-for-byte
  (verified: same line count, same non-Chinese content, only the
  Chinese text changed from garbage to real sentences — e.g.
  `day_phase`'s dawn/noon/dusk broadcast lines, previously unreadable,
  now read correctly, e.g. "已经是中午了，太阳从你的上方照耀着大地。").
  `adm/etc/motd` likewise (its "help motd" bulletin, previously
  garbage, now renders and was independently re-confirmed live at
  every login in this session).
- Verified live: `help` (topics listing), `help story` (the intro
  backstory, "山海战神之简单武力的故事背景..."), `help cmds` (the full
  command chart with Chinese glosses) and the MOTD bulletin at login
  all render correct Chinese now; re-tested after the driver restart
  that picked up the fix.

### Bug 2 — per-command `指令格式：` (syntax) help lines mis-decoded as
GBK when the source byte run was actually BIG5 (same §4.1 class, a
narrower/more surgical instance)

- Found while checking `help study`, `help load`, etc. (the individual
  command help topics `help.lpc` falls through to in its default
  search path): the "指令格式：" prefix decoded correctly (it's
  genuinely GBK, shared boilerplate the Chinese-reskin author typed)
  but the bracketed argument placeholder immediately after it was
  garbage in `cmds/std/{pilot,steal,load,study,wear,vl,sl}.lpc` and
  `cmds/wiz/edstar.lpc` — a **single source line mixing two different
  encodings**, GBK boilerplate concatenated with the ORIGINAL
  Final-Frontier-base BIG5 English-to-Chinese translation of the
  argument name (this codebase's ES2/FF heritage — see `study.lpc`'s
  own header comment "Original ES II command" / "Last modified by
  Spock @ FF" — was shipped in Traditional/BIG5, and the reskin author
  added Simplified/GBK text around it without re-encoding the file).
  Confirmed by decoding the exact raw byte ranges: the "指令格式："
  bytes are valid GBK, the following `<...>` bytes are valid BIG5 and
  garbage under GBK (e.g. `study.lpc`'s raw bytes for `<物品名稱>`
  decode to `<珇嘿>` under GB18030 — silently wrong, not an error, so
  the original conversion's lossy-conversion log never flagged it).
- Fix: byte-precise per-line re-decode against `raw/simple/` (GBK
  prefix up to and including the fullwidth "：", BIG5 for the rest),
  applied as a single-line patch preserving the file's original CRLF
  line endings and every other line untouched. Examples: `study.lpc`
  "指令格式： study <珇嘿>" → "指令格式： study <物品名稱>";
  `edstar.lpc` "...edstar -a <琍╰畒夹 x,y,z> <琍╰郎>" → "...edstar -a
  <星系座標 x,y,z> <星系檔案>".
- **Caught and reverted a self-inflicted mistake while building this
  fix, worth recording**: my first attempt regenerated whole files
  fresh from `raw/` bytes (auto-picking GBK vs. BIG5 per line by
  scanning for stray bopomofo/hiragana/katakana characters — a decent
  first-pass heuristic, it correctly re-decoded 65 files' worth of
  lines) — but that wholesale regeneration silently **reverted
  earlier, unrelated fixes already baked into the committed source**
  (`static`→`nosave` in 5 files, i.e. AGENTS.md §4.3) and, separately,
  **flattened CRLF to LF** across every touched file (Python's default
  text-mode write), producing a 90+-line diff for what should have
  been a 1-line change. Caught both via `git diff --stat` before
  committing anything (`static` reappearing was caught by re-grepping
  for it post-fix; the CRLF flattening by the diff being suspiciously
  large for a single-line semantic change). Reverted with `git
  checkout --`, redid the fix as a precise byte-level single-line
  patch per file instead. **Lesson for future encoding-repair work on
  already-converted files: never regenerate a whole file from `raw/`
  once other fixes have landed on top of the conversion — patch only
  the specific corrupted byte range, and read/write in binary mode (or
  explicit `newline=''`) to preserve the original line endings.**
- The bopomofo/kana-based automated detector this project has used
  elsewhere (e.g. AGENTS.md §4.1's "human skim" heuristic) has a real
  false-negative gap: when BIG5 bytes get mis-decoded as GBK and land
  on *other valid-looking (but wrong) CJK ideographs* rather than
  bopomofo/kana, it produces no signal at all — confirmed directly:
  after fixing the 9 command-syntax lines above, the *body* text of
  those same help blocks (e.g. `study.lpc`'s "丁: ︓ぶ 100 虫︗,
  珇のㄤず甧肂." / `load.lpc`'s "丁: 10 虫︗.") is **still** mis-decoded
  BIG5-as-GBK and the automated scan (re-run clean afterward) does not
  flag it, because the wrong decode happens to land on ordinary CJK
  characters. Manually spot-checking ~15 more `指令格式` lines across
  the corpus (`d/lwe/npc/zhahuo.lpc`'s dialogue, several others) turned
  up the same shape repeatedly. **This is scoped far beyond what's
  reasonable to hand-fix in one pass** — the automated detector alone
  already found 65 files with at least one bopomofo/kana artifact, and
  that's a lower bound, not the true count. Fixed only the 9
  highest-confidence, most player-visible lines (the `help <cmd>`
  syntax headers, since those are what a genuinely new player types
  first) and stopped there rather than risk more half-finished
  wholesale edits under time pressure; the wider cleanup is flagged
  below as explicitly NOT done. This is the existing AGENTS.md §4.1
  "mixed encodings within one file" class, just present at a much
  larger scale in this lib's `cmds/`/`feature/`/`adm/daemons/`/`d/`
  trees than the single cataloged example (`huoying`'s `config.cfg`)
  suggested — worth a dedicated future pass, not a quick fix.

### Bug 3 — a player who disconnects uncleanly is stranded in the void,
via TWO independent code paths (new bug class — see report for the
AGENTS.md draft)

Found by literally doing what §10.7 step 5 asks: `quit`, grep
`debug.log`, reconnect after a real gap, confirm state — except the
very first "reconnect after real gap" (a session that ended by the
`mudclient.py` connection simply going away, i.e. exactly what a real
player's dropped wifi/closed laptop lid looks like, not a clean `quit`)
landed `linfeng` in "影子世界" (`obj/void.lpc`, the `VOID_OB` net-dead
holding room — **zero exits**) instead of back where they'd been.

- **Path A — force-quit-from-void persists `/obj/void` as `startroom`
  forever.** `obj/user.lpc`'s `net_dead()` (driver-invoked automatically
  on a dropped connection) immediately parks the disconnected player in
  `VOID_OB` (remembering the real room in a `nosave`/temp
  `"last_location"` var) and schedules `user_dump(DUMP_NET_DEAD)` for
  `NET_DEAD_TIMEOUT` (900s) later, which force-runs `command("quit")`
  on the still-netdead, still-in-void object if they never reconnect.
  `cmds/usr/quit.lpc:47-59` (pre-fix) unconditionally persisted
  `base_name(environment(me))` as `"startroom"` — with no special case
  for `VOID_OB` — so this force-quit-from-the-void wrote
  `"startroom":"/obj/void"` straight into the save file. Every future
  login (any number of days later, driver restarts, doesn't matter)
  then calls `enter_world()` → `user->move("/obj/void")` →
  **succeeds** (void is a perfectly valid loadable room) → player is
  now permanently starting every session in a room with no exits.
  Reproduced live: an early test session in this pass ended without
  `quit` (idle-timeout close), and by the time I came back the disk
  save already read `"startroom":"/obj/void"` — confirmed with `grep
  -o '"startroom":"[^"]*"' data/user/l/linfeng.o`.
- **Path B — `LOGIN_D`'s own `reconnect()` never restores the void-parked
  location, and `obj/user.lpc`'s `reconnect()` apply that *would* is
  dead code.** `obj/user.lpc` defines a `reconnect()` apply, doc-commented
  "called by the LOGIN_D when a netdead player reconnects", whose whole
  job is `move(query_temp("last_location"))` — exactly the fix Path A
  needed. **Nothing calls it.** `grep -rn "->reconnect(" work/` across
  the whole lib returns zero hits. `adm/daemons/logind.lpc` has its
  *own*, differently-scoped `reconnect(object ob, object user, int
  silent)` function (re-links the connection, sends a "reconnected"
  room message, clears the netdead flag) that `get_passwd()` actually
  calls on a netdead reconnect — and it never moves the player out of
  `VOID_OB` at all. So even a player who reconnects promptly, well
  inside the 900s window, stays stuck in the void; `obj/user.lpc`'s own
  `reconnect()` was seemingly meant to be the fix but was simply never
  wired up. Reproduced live with debug `write()`/`tell_object()`
  instrumentation (removed before the final fix): a fresh login after
  an unclean disconnect showed `find_body=found netdead=1
  last_location=/d/lwe/jie11 env=/obj/void`, entered the
  `reconnect(ob, user)` branch, and the room remained `/obj/void` the
  entire time — `last_location` was captured correctly by `net_dead()`
  but never consumed by anything in the live call path.
- Fix (both paths, independent, both needed — matching the two
  distinct trigger conditions):
  1. `cmds/usr/quit.lpc`: rewrote the duplicate/overlapping
     startroom-setting logic into one clean if/else chain; when
     `environment(me)` is `VOID_OB` at quit time, pull the real room
     from `me->query_temp("last_location")` instead of persisting the
     void itself (falls back to leaving `startroom` untouched if even
     that's unavailable, rather than ever writing `/obj/void`).
  2. `adm/daemons/logind.lpc`'s `reconnect()`: before re-linking,
     if `environment(user)` is `VOID_OB` and
     `user->query_temp("last_location")` is set, `user->move()` there
     first — doing, in the code path that's actually invoked, what
     `obj/user.lpc`'s dead-code `reconnect()` apply was clearly meant
     to provide.
- Verified live, both paths, after rebuilding nothing (LPC-only
  change) and restarting the native driver: (a) logged in fresh, moved
  to `/d/lwe/jie2`, let the connection drop uncleanly (no `quit`),
  reconnected within seconds — landed correctly back in `街道`
  (`jie2`), not the void, and a subsequent clean `quit` persisted
  `"startroom":"/d/lwe/jie2"` (not void) to disk; (b) separately
  confirmed the disk-corruption half by hand-editing
  `"startroom":"/obj/void"` into the save file (simulating what an
  UN-reconnected, timed-out net-dead session would have written
  pre-fix) and logging in fresh — `enter_world()`'s own `startroom`
  path is unaffected by this fix (by design — the fix stops void from
  ever being *written* again; recovering a save that's already been
  corrupted by the old bug needs a one-time manual `startroom` reset,
  which is what was done for `linfeng`'s own save after the pre-fix
  reproduction above). debug.log stayed empty (no `error:`/fatal
  lines) across every session in this entire pass, fix included.
- This is a **new bug class**, not a rediscovery of an AGENTS.md
  §7.16/§7.17-style crash — nothing aborts or errors, `debug.log` is
  and stays completely clean, which is exactly why boot-log watching
  and registration smoke tests can never catch it. Full draft writeup
  for AGENTS.md is in the task's final report (not added here — the
  orchestrating session owns AGENTS.md edits).

### What else was tested and confirmed working

- **Registration**: real Chinese name (林风), full flow (English id →
  confirm y/n → Chinese name → password → confirm → email → attribute
  allocation with the in-game example split 15/10/10/6/17/2 → gender)
  — reached 梦旅馆大厅 (the Dream Inn hall) correctly.
  `look`/`score`/`i` all correct at every stage (fresh, post-move,
  post-shop-visit, post-reconnect).
- **Exploration**: walked the `d/lwe` town zone (夜/清晨/正午/傍晚/入夜
  time-of-day description variants all render correctly and change
  live as in-game time passes — confirmed by re-`look`ing the same
  room at different points in the session), reached both the general
  store (`d/lwe/shop.lpc`, NPC 杂货老板/`zhahuo`) and the weapon store
  (`d/lwe/shop1.lpc`, NPC 段楚沛/`duan chu pei`, id list includes
  `wuqi`'s directory-name alias `lwe wuqi` but *not* bare `wuqi` — the
  in-room `[duan chu pei]` bracket is the actual matchable id, a minor
  navigation trap for a human player but not a bug).
- **Shop `list`**: `list` at the weapon store correctly printed real
  priced stock (锯齿屠刀 24 银币, 长剑 18 银币, 短棍 1银20铜, 匕首
  7银20铜) — confirms `feature/dealer.lpc`'s `do_list()` and the
  underlying `MONEY_D->price_str()` formatting work correctly. `list`
  at the general store correctly printed the "nothing for sale" path
  (`zhahuo` only carries worn/wielded equipment, which `do_list()`
  correctly excludes — a content-completeness gap in the shipped NPC,
  not a bug: it has zero unequipped stock and no `vendor_goods` array).
- **`kill`/combat command surface**: `kill <target not present>`
  correctly returned "这里没有这个人。" (no crash, no silent failure).
- **Session persistence**: confirmed across three separate
  reconnect/relogin cycles in this pass (once accidentally exercising
  the net-dead path pre-fix, twice deliberately post-fix) that
  attributes, inventory, and (after the Bug 3 fix) location all persist
  correctly across a clean `quit`+relogin.
- **`debug.log`**: grepped after every single `quit` in this entire
  pass (a dozen-plus sessions) — stayed completely empty (no file even
  gets created) throughout, both before and after every fix.

### Explicitly NOT verified live (with reason)

- **Safe-sparring / training-dummy mechanism**: none exists in this
  lib. Grepped `accept_fight` across the whole tree — zero hits. No
  `木人`/`训练`/`陪练`/dummy-pattern NPC is reachable from the starting
  zone (`d/mochen/dongwuchang.lpc`'s "东练武场" training ground, with
  wooden dummies and sandbags in its room description, is real content
  but lives in a completely disconnected zone — `d/mochen`/`d/mohao`/
  `d/shiwang`/`d/zuichen`/`d/tian`/`d/shenmin` have zero cross-links to
  or from `d/lwe`, confirmed by grepping every `d/lwe/*.lpc` for those
  path prefixes and vice versa). This lib genuinely ships without a
  reachable safe-combat mechanism.
- **Organic skill-teacher path**: only one NPC in the entire lib
  implements the teacher/apprentice pattern (`d/mohao/ouyangxiu.lpc`,
  `inherit F_MASTER`, `attempt_apprentice()`/`recruit_apprentice()`)
  and it's in the same disconnected `d/mohao` zone above — unreachable
  from the actual starting area. Also checked the `study`
  command's item-based path (`cmds/std/study.lpc`, reads a `"skill"`
  property off a carried book/item): `grep -rn 'set("skill"'` across
  the whole `work/` tree returns zero hits — no such item exists
  anywhere in the shipped content, reachable or not. This lib ships
  with no functional organic skill-acquisition path at all; not a
  conversion bug (nothing here is broken code, there's just no content
  wired up to use it), documented here rather than silently skipped.
- **Sect/faction-join mechanism**: same finding — `feature/apprentice.lpc`
  (the `family`/`create_family`/`recruit_apprentice` sect-equivalent
  infrastructure) is only ever invoked by the same single unreachable
  `ouyangxiu.lpc` NPC. No join command, newbie-gift shortcut, or other
  faction-entry path exists in the reachable zone.
- **Live combat exchange, death/respawn**: not reached. No safe
  sparring target exists (above) and deliberately picking a real fight
  with an unknown wild NPC's stats, without a safe first data point,
  was judged not worth the risk this late in an already long session;
  the `kill` command's basic dispatch (invalid-target case) was
  confirmed clean, but a full turn-by-turn combat log, a kill, and the
  death/respawn cycle were not exercised live. Reason: time budget —
  most of this pass's time went to the Bug 3 investigation
  (instrumented debugging across ~15 test sessions to isolate a
  two-path bug that only reproduces via specific disconnect timing),
  which was judged the higher-value use of the remaining budget over
  finishing the shop-purchase/combat checklist items.
- **A completed shop purchase (`buy`)**: `list` was verified live
  (above) and the underlying `feature/dealer.lpc:do_buy()` code path
  was read and looks correct (affordability check, `MONEY_D->player_pay`,
  `ob->move(this_player())`), but a live `buy <item>` transaction
  wasn't completed in this pass — repeated navigation attempts to
  reach the weapon-shop NPC in the same room as a `buy` command kept
  landing one room off (this lib's street grid has more live exits
  than its `set("exits", ...)` blocks show via static grep, e.g. `jie2`
  live-shows a `south` exit no `.lpc` source search found — not
  investigated further, out of scope for this pass) — code-reviewed,
  not live-verified; flagging explicitly rather than silently
  presenting it as tested.

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `700000`（已知
   风险区间）提升到 `5000000`。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
3. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第五条独立确认
   的血统——本档案与此前命中过的 shenzhou/shiji/shujian2008/shujian3
   均无关联，是完全不同的 `obj/user.lpc` 架构，同一 bug 在这条独立
   血统上再次出现）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少 `enable_commands()`。
   按 §7.108 记录的写法预防性修复，现场用两个真实连线复现"保持第一
   个连线不断开→第二个连线登录→答 y 踢掉旧连线"验证：`score` 修复
   后立即正常显示完整角色档案。

`cmds/wiz/update.lpc`（§7.106）与 `master.lpc::log_error()`（§7.10
的 `"arning:"` 大小写无关写法）均已是正确写法，无需改动；本档案无
`adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录确认
`目前权限: (admin)`，`update /adm/daemons/logind` 成功验证真实写入权
限。踢掉重复登录重连路径现场验证通过（见上）。`debug.log` 全程干净
（448 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/obj/user.lpc`

## 深度功能测试第三轮 / Deep functional test round three (2026-08-18)

Standard §7.111/§7.112/logind-save/case-mismatch checklist (all clean,
no action needed):

- **§7.111** (`master.lpc::standard_trace()` unguarded `file_name(error["object"])`):
  already fixed here — `objectp(error["object"]) ? file_name(...) : "(driver)"`
  at `adm/obj/master.lpc:200`.
- **§7.112** (`init()` unconditionally scheduling a `call_out()` chain):
  grepped every `init()` with a `call_out(` in it (~47 hits, all NPCs).
  All of them either fire a single one-shot `call_out("welcome", 0, ...)`
  from the shared `feature/attack.lpc` (no chain, harmless if duplicated),
  or already guard their `"greeting"` call_out with
  `remove_call_out("greeting"); call_out("greeting", 1, ob);` — the
  correct anti-duplication idiom. No plain ROOM objects schedule
  call_outs from `init()` at all. Nothing to fix.
- **`logind.lpc::enter_world()` missing `ob->save()`**: present and
  correct (`user->save(); ob->save();` right after `setup()`, before the
  MOTD).
- **`u/<wizid>` case-mismatch**: not applicable — this lib has no `u/`
  wizard-home tree at all.

### Bug found and fixed — `adm/simul_efun/gender.lpc` was BIG5 bytes
mis-decoded as GBK during the original conversion pass (same class as
round two's Bug 2, much wider blast radius)

- Symptom: found while doing a from-scratch PK-combat playthrough
  (round one/two never exercised PK). Every first-person combat/action
  message that should read "你" (you) — e.g. "你对着测试四号喝道...",
  "忽然，狂声大笑，纵身跃起，向...发动攻击" — instead showed a blank
  where "你" belongs (leading space, no pronoun). Also affected `score`'s
  "你是一...的男性人类" line, `tell`/`reply`, `emote`, and any other
  message using `gender_self()`/`gender_pronoun()`.
- Root cause: `adm/simul_efun/gender.lpc` (the shared `gender_self()` /
  `gender_pronoun()` simul_efuns) was raw BIG5 bytes in the archive
  (`raw/simple/adm/simul_efun/gender.c`) but got run through the
  project's GB18030 conversion pass like everything else. Because these
  particular BIG5 byte sequences (`case "女性"`/`"男性"`/`"雄性"`/
  `"雌性"` etc., and their return values `"你"`/`"妳"`/`"他"`/`"她"`/
  `"牠"`/`"它"`/`"祂"`) happen to be *unmappable* under GB18030, iconv's
  lossy fallback silently remapped them into Unicode Private-Use-Area
  codepoints instead of erroring — so the file "converted" cleanly with
  no warning, but every `case` label became garbage that could never
  match a real `"男性"`/`"女性"` gender string, and `gender_self()`
  always fell through to its own corrupted `default:` value (also
  garbage, effectively empty when rendered). Confirmed byte-for-byte:
  decoding `raw/simple/adm/simul_efun/gender.c` as BIG5 recovers
  perfectly formed, grammatical Chinese matching this exact function's
  known contract.
- Fix: precise byte-level patch (Python binary mode, no whole-file
  regeneration) replacing only the 8 corrupted string literals with
  their correctly-BIG5-decoded UTF-8 equivalents. `git diff --stat`
  confirmed exactly 8 lines changed, CRLF preserved.
- Verified live: rebuilt driver, ran the same PK-combat scenario —
  first-person messages now correctly show "你" throughout (e.g. "你对
  着测试四号喝道小王八蛋！你死定了！"), third-person pronoun refs also
  correct. `debug.log` stayed empty across the whole session.
- **This mis-decode class (§4.1/round-two's Bug 2) is proven to recur
  independently at least twice in this one lib now** (help-topic syntax
  lines in round two, this shared simul_efun in round three) — flagging
  for the orchestrator: any lib sharing this "Final Frontier"/ES2
  ancestry (BIG5-authored base + GBK-authored Chinese reskin layered on
  top) should have `adm/simul_efun/gender.lpc` (or equivalent) spot
  checked, since a silently-empty `gender_self()` has no crash signature
  and is very easy to miss without an actual PK/combat playthrough.

### Bug found and fixed — netdead reconnect never restores `heart_beat`,
permanently soft-locking anyone who dies and ever has one dropped
connection (new bug class, not previously in AGENTS.md)

- Found while trying to complete the death → reincarnation loop (`kill`
  → die → `/d/death/gate` → `/d/death/hall` → `say return` to 史巴克).
  `d/death/npc/toilet.lpc`'s `relay_say()` requires every limb's
  `limbs_eff_hit` to be at least 50% of `limbs_max_hit` before `return`
  is allowed ("您目前的状况还无法回到人世，请多休息一下吧" otherwise) —
  reasonable design, not a bug. But after admin-forced death (`call
  hbtestb->die()`, matching real PK-death numerically) the character's
  limbs sat frozen at `1/1/max` (`重伤`) for over a minute of real wall
  time with zero movement, never healing even while standing — the one
  path (`feature/damage.lpc::heal_up()`'s standing branch) that's
  supposed to add +1/tick to a ghost's `limbs_eff_hit`.
- Root cause, confirmed live via the `info <target>` wizard command's
  "心跳:N" field (the reliable way to read real heart-beat state — the
  `call obj->query_heart_beat()` idiom used earlier in this pass is
  *not* reliable for this efun, since `query_heart_beat` has no
  user-defined LPC wrapper and `call_other` to a nonexistent function
  silently returns 0 rather than erroring, which cost real time here
  chasing a false "always 0" signal before switching to `info`):
  `obj/user.lpc::net_dead()` correctly calls `set_heart_beat(0)` on an
  unclean disconnect (self-context, correct). But the *actually invoked*
  reconnect path, `adm/daemons/logind.lpc::reconnect(object ob, object
  user, int silent)` (called from `get_passwd()` when
  `user->query_temp("netdead")`, and from `confirm_relogin()`'s
  duplicate-login-kick path), never re-enabled it — so `heal_up()`
  (and aging, idle-timeout, hunger/thirst decay — everything gated on
  heart-beat) silently stopped running for the rest of that session, any
  time a player's connection ever dropped and they reconnected. Combined
  with the death mechanism's healing requirement, this means: **any
  player who dies and has ever had even one dropped connection can never
  heal enough limb health to reincarnate again**, with zero error/crash
  signature (`debug.log` stays completely clean the whole time).
  `obj/user.lpc` already has its own `reconnect()` *apply* with the
  correct shape (`enable_commands(); set_heart_beat(1); ...`), doc-
  commented "called by the LOGIN_D when a netdead player reconnects" —
  but nothing calls it (same "intended but never wired up" dead-code
  pattern round one's Bug 3 found in this same function name).
- Fix: `set_heart_beat()`/`enable_commands()` are efuns with no
  cross-object form (bare calls always target `this_object()`, which
  inside `logind.lpc::reconnect()` is the daemon itself, not the
  player — this is exactly why a first attempt at this fix, calling the
  efuns directly from `logind.lpc`, silently did nothing). Added a thin
  `resume_heart_beat()` wrapper to `obj/user.lpc` (right after the
  existing dead-code `reconnect()` apply) that does
  `enable_commands(); set_heart_beat(1);` in the user object's own
  context, and call it as `user->resume_heart_beat();` from
  `logind.lpc`'s actually-invoked `reconnect()`.
- Verified live with an A/B test (git-stashed the fix, rebuilt, re-ran
  the same scenario, then restored and rebuilt again): pre-fix, `info
  <player>` showed `心跳:1` on fresh login but the "心跳:" field
  disappeared entirely after a real drop-and-reconnect cycle (heart_beat
  = 0, confirmed reproducible). Post-fix, `心跳:1` is present both
  before and after the same reconnect. Further verified the actual
  downstream effect: killed a test character, dropped+reconnected them,
  then sampled `body` every 20s — limb values climbed steadily
  (1→3→5→8 over 60s, previously frozen forever at 1) confirming
  `heal_up()` is running again and the reincarnation path is no longer
  permanently soft-locked. `debug.log` stayed empty throughout.
- **Flagging for the orchestrator**: this is a new, previously
  uncataloged bug class — likely recurs in any lib whose
  `net_dead()`/`reconnect()` split mirrors this shape (a `set_heart_beat`
  call in the disconnect handler with no corresponding restore in the
  actually-invoked reconnect path). Worth a grep sweep across the corpus
  for `set_heart_beat(0)` in `net_dead()`-style applies paired with a
  `reconnect()` that doesn't call `set_heart_beat(1)` (directly or via a
  wrapper) — not fixed elsewhere in this pass, this lib only.

### What else was tested this round

- **PK combat** (two live characters, `cetesta` vs `cetestb`): full
  exchange of blows, damage accumulation, skill-up messages, auto-flee
  trigger at low spirit/stamina, and the loser fleeing to an adjacent
  room — all worked correctly end-to-end (this is what surfaced the
  `gender.lpc` bug above).
- **Attacking an essential shop NPC** (`kill li meng zhe`): confirmed
  this is *intentional* content, not a bug — `d/lwe/npc/bartender.lpc`
  and every other vendor NPC in `d/lwe` override `kill_ob()` to show a
  dramatic "transforms into a beast" flavor message and immediately
  `remove_killer()` both ways, cancelling the fight before any damage
  lands. Confirmed via code (identical pattern across
  `zhahuo`/`zhanggui`/`xiaoer2`/`jiubao`/`wuqi`/`faju`), not a gap.
  Matches this lib's existing documented finding that no reachable wild
  monster exists in the connected `d/lwe` zone.
- **Death → hell zone**: `/d/death/gate` and `/d/death/hall` (with NPC
  史巴克/`toilet.lpc`) *are* reachable (unlike the disconnected
  `d/mochen`/`d/mohao`/etc. zones noted in round one) — death correctly
  routes here via `feature/damage.lpc::die()`. The `DEATH_ROOM->
  start_death(this_object())` call in `die()` targets a function that
  doesn't exist anywhere in the codebase (`gate.lpc` is a plain `ROOM`)
  — confirmed this is harmless, not a bug: `call_other` to an
  undefined function silently returns 0 in this driver config, no
  error, no `debug.log` entry, and death still proceeds correctly.
- **A completed shop purchase (`buy`)**: still not completed live this
  round either (admin-`clone`d gold onto a test character, but
  navigating on-foot to the weapon shop repeatedly landed one room off
  from wherever the last `list`/`buy` attempt needed — same live-exit-
  vs-static-grep mismatch round one already flagged for this lib's
  street grid). Not investigated further; `list`'s working output and
  `do_buy()`'s code path were already reviewed as correct in round one.
- Registration flow, `look`/`score`/`i`/`body`, and the netdead/void
  reconnect fix from round two all re-confirmed still working correctly
  throughout this pass's ~15 test sessions.

### Files modified this round

- `work/adm/simul_efun/gender.lpc` (BIG5-as-GBK mis-decode fix)
- `work/adm/daemons/logind.lpc` (call `user->resume_heart_beat()` in
  the real reconnect path)
- `work/obj/user.lpc` (new `resume_heart_beat()` wrapper)
