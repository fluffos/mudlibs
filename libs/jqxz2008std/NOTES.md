# jqxz2008std — 金庸群侠传 (Jin Yong Heroes Gathering, standard edition)

Archive: `archives/金庸群侠传2008版.rar` ("Jin Yong Heroes Gathering 2008,
standard edition" — plain "2008版" title, as opposed to archive #91's
"2008加强版"/enhanced edition). Extracted mudlib root: `raw/jy/` (a single
top-level `jy/` directory inside the archive — same layout as #91). Port:
**40084**. Status: **done** (boots clean, full registration flow verified
with a real Chinese name, post-login `look`/`score` verified working).

## Lineage confirmation (evidence, not assumption)

This archive is **not merely "the same family" as #91/`jqxz2008`
— it is the exact same codebase at an earlier/lighter content-configuration
point**, confirmed by direct `md5sum`/`diff` comparison of the raw archives
before any conversion:

- **Byte-identical (`md5sum` match) between this archive's raw `jy/` and
  #91's raw `jy/`**: `adm/obj/master.c`, `adm/single/master.c`,
  `adm/daemons/logind.c`, `adm/daemons/securityd.c`,
  `adm/daemons/chinesed.c`, `config.cfg`. (Recall #91 vs `xiakexing3`
  already found `securityd.c` to differ between those two — here it's
  identical even to #91's own securityd.c, an even tighter match than the
  #91-vs-xiakexing3 pairing that established this lineage originally.)
- **Full-tree `diff -rq` between the two raw archives** (3772 files here vs
  3773 in #91) turned up only **22 differing files total**, none of them
  engine/security/login/encoding-relevant:
  - `adm/tmp/swapfile.ZY054.4000` — a runtime-only artifact present in #91's
    archive but not this one (leftover editor swapfile, irrelevant).
  - `log/debug.log`, `log/log`, `log/USAGE`, `mud.dat` — pre-existing
    runtime logs/state from whatever original server session produced each
    archive; irrelevant to source content.
  - `d/shaolin/matou3.c` — one NPC/room text file with a shorter room
    description in this ("std") archive vs a longer one in #91
    ("加强版"/enhanced) — consistent with "enhanced edition adds more
    flavor text."
  - `quest/qlist*.c` (20 files) — quest-list content-data files; #91's
    "加强版" copies have MORE quest entries than this archive's (e.g.
    `qlist0.c` here has fewer `mapping` entries than #91's) — consistent
    with "加强版 add more quest content on top of the same engine," exactly
    what the "enhanced edition" branding implies.
  - **Zero differences** in any of `master.c`/`securityd.c`/`logind.c`/
    `chinesed.c`/`config.cfg`/`chinese.lpc`/`command.lpc`/`combatd.lpc`/
    `name.lpc`/any of the other files this pass needed to fix (verified
    individually below, not inferred).

**Practical consequence**: rather than rediscovering #91's bugs from
scratch, this pass converted the archive with the standard pipeline, then
for every fix location documented in #91's `NOTES.md`, diffed this lib's
freshly-converted (pre-fix) file against **both** the pre-fix state
implied by #91's diffs and #91's own fixed file. Every single one of the
~26 files fixed in #91 was confirmed **byte-identical, pre-fix**, to this
archive's own freshly-converted copy (i.e., the exact same bug, in the
exact same file, with the exact same surrounding code) — so #91's fixed
versions were copied over directly rather than re-typed, with a final
`diff -q` verification pass confirming every copied file now matches #91's
fixed version exactly.

**Cross-check note carried forward** (per #91's own NOTES.md): archives #93
(`金庸群侠传2008超豪华版.rar`, concurrent sibling agent) and #94
(`金庸群侠传2015版.rar`, not yet started) are still queued in this same
title family. Given how tight the match turned out to be between #91 and
this archive (engine 100% identical, only quest-content-depth differs),
there's a good chance #93/#94 are further snapshots of the same underlying
codebase too — worth a follow-up `md5sum` cross-check against this lib's
(and #91's) core files once both land, the same way this pass cross-checked
against #91.

## Fixes applied (all ported directly from #91 — verified byte-identical
## pre-fix source, not independently rediscovered)

1. **AGENTS.md §15h** (is_chinese / check_legal_name — GBK byte-range
   checks silently wrong under UTF-8 strings):
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK Unified
     Ideographs codepoint range check (`str[0] >= 0x4e00 && str[0] <=
     0x9fff`, `strlen>=1`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()` (inline in
     logind.lpc, same as #91 — no separate `named.lpc` in this lib
     either): byte-count bound `strlen(name) < 2 || > 12` → character-count
     bound `< 1 || > 6`; dropped the `i%2==0 &&` even-byte-offset gate in
     the per-character sliding-window loop.
   - **Verified working**: real Chinese name "秦风" accepted on the first
     attempt during the registration transcript below.

2. **AGENTS.md §15ae** (`private nomask` command-hook breaks every
   post-login command silently): `feature/command.lpc`'s
   `command_hook(string arg)` was `private nomask` — dropped `private`
   (kept `nomask`). `home/command.lpc`'s copy was already correct in the
   raw archive (confirmed identical to #91's already-correct copy, no fix
   needed there — same as #91). **Verified**: `look`/`score` both work
   post-login.

3. **AGENTS.md §15t (variant 1)**: `adm/daemons/combatd.lpc` had
   `#include </quest/quest.h>` (absolute path inside angle brackets, never
   resolved by this driver's `inc_open()`). Fixed to
   `#include "/quest/quest.h"`.

4. **AGENTS.md §15t (variant 3)**: fixing #3 then surfaced `quest.h`'s
   file-scope global `mapping quest_name` landing textually before
   `combatd.lpc`'s own `inherit F_DBASE;` — fatal "Illegal to inherit after
   defining global variables". Fixed by moving `inherit F_DBASE;` above all
   of `combatd.lpc`'s `#include` lines.

5. **`capitalize()`-on-`0` robustness bug in `feature/name.lpc`**:
   `short(int raw)`'s fallback assumed `query("id")` is always a string;
   any board/item without an explicit `"short"` property (e.g.
   `/clone/board/kedian_b`, the starting-room bulletin board) has no `"id"`
   at all, crashing every `look` in that room with `*Bad argument 1 to
   capitalize() Expected: string Got: 0`. Fixed with a `stringp(id)` guard.

6. **`d/city/npc/guidao.lpc`'s `is_killing(who)` direct-call type
   mismatch**: `is_killing(string id)` called directly with a raw object
   instead of `who->query("id")` — every other call site in the lib does
   it correctly. Since it's a same-object direct call (not `->`), the
   static type checker rejected the whole file. Fixed to
   `is_killing(who->query("id"))`.

7. **Duplicate `inherit F_UNIQUE;` (pre-existing copy-paste typo)**:
   `d/mingjiao/npc/{yinwushou,yinwulu,yinwufu}.lpc` each had it listed
   twice — fatal "Illegal to redefine 'nomask' function" on this driver.
   Removed the duplicate line in all 3 files.

8. **The "tang"-family NPC template's `new` used as a bare variable name**
   (pre-existing bug, `new` is a reserved efun/keyword here): 7 files —
   `d/quanzhou/npc/{tang,tang1,tang2,tang3}.lpc`,
   `d/taishan/{tang2,tang3,xingtang}.lpc` — renamed the local variable to
   `newob` throughout (declaration + both usages); actual `new(...)` efun
   calls untouched.

9. **AGENTS.md §15ac** (bare `SAVE_EXTENSION` instead of
   `__SAVE_EXTENSION__`): `include/net/ftpdsupp.h`,
   `adm/daemons/network/netmail.lpc`, `cmds/arch/purge.lpc`, and 3 of the
   "tang"-family files (`d/quanzhou/npc/tang.lpc`,
   `d/quanzhou/npc/tang3.lpc`, `d/taishan/tang3.lpc`). Fixed all 6.

10. **`kungfu/class/mingjiao/mingjiao.h`'s string-literal-adjacent-to-
    macro-expansion syntax error**: `HIG "明教" NOR` (no `+` between two
    macro-expanded string literals) — rewrote as `HIG + "明教" + NOR`.
    Also added `#include <ansi.h>` to this header (some includers reach it
    transitively without ever including `<ansi.h>` themselves, leaving
    `HIG`/`NOR` genuinely undefined once the syntax error above stopped
    masking it).

11. **`d/mingjiao/npc/changjinpeng.lpc`'s wrong absolute `#include` path**:
    `#include "/kungfu/class/mingjiao/tanzhu.h"` (doesn't exist — the real
    file lives next to this NPC file). Fixed to `#include "tanzhu.h"`.

12. **`d/mingjiao/npc/{fenggongying,baiguishou}.lpc`'s
    `#include __DIR__"tanzhu.h"`** (unquoted macro-concatenated form,
    "Cannot read #include file"). Rewrote both to the plain quoted form
    `#include "tanzhu.h"`.

13. **`d/baituo/ouyangfeng.lpc`, two independent pre-existing typos**:
    (a) missing semicolon after a `write("...")` inside a `switch case 0:`
    block; (b) `object me=this-player();` (subtraction instead of
    `this_player()`, missing underscore). Fixed both.

14. **`d/shaolin/obj/shuitan.lpc`: `ging_cost` typo** for the declared
    variable `jing_cost` (transposed letters). Fixed.

15. **`d/mingjiao/jmqshenmu.lpc` was genuinely truncated in the raw
    archive** (confirmed against the pre-conversion `.c`, same as #91 —
    ends mid-`void init() {` with no closing braces). Closed with an
    empty body rather than fabricating content.

All 26 fixed files were verified with a final `diff -q` against #91's
corresponding fixed file: zero differences remain.

## Confirmed NOT needed (checked directly against this lib's own source,
## not assumed from #91)

- **§4** (master's lazy security-daemon load recursing to a stack
  overflow): `master.lpc`'s `valid_write` only does
  `find_object(SECURITY_D)` (no `load_object()`); `valid_read` is a bare
  `return 1;`. Byte-identical to #91's master.c (confirmed via md5sum), so
  this holds here too by construction.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both present in
  `master.lpc` (same file as #91's).
- **§8c** (`valid_read`/`valid_write` overriding caller with
  `this_player()`): `securityd.lpc` has no `valid_read` at all — confirmed
  via direct grep (this file is byte-identical to #91's, and #91's own
  securityd.c, unlike xiakexing3's, was already confirmed byte-identical
  between the two 金庸群侠传2008 variants).
- **§15n/§15o**: no custom `valid_read` ACL, no `<local.h>`-next-to-its-
  user `#include` collisions.
- **§15p** (DNS/intermud daemon in preload): `adm/etc/preload` (11-entry
  list, identical text to #91's) never listed `network/dns_master` —
  nothing to exclude.
- **§15l** (master.lpc destructing `SIMUL_EFUN_OB` in `create()`):
  `master.lpc create()` has no `destruct()` call.
- **§15u** (dormant "phone home" destructive license check): grepped
  `master.lpc`/`securityd.lpc` for `shutdown`/`rm(`/`rmdir(`/`unlink(` —
  only one harmless comment hit.
- **§15r** (`check_config.lpc`-style driver-version self-check): no such
  file anywhere in this lib.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`): only appear under
  `doc/efuns/` (documentation stub files, not real code) — zero real hits.
- Uppercase `.C` files: same 4 found as #91, all under `u/jackyboy/`
  (`TOKEN.C`, `WIZ_CLOA.C`, `CLOTH1.C`, `GLASS.C`) — renamed to `.lpc`.

## Interactive test result — full registration + post-login flow

Full registration + post-login test, one continuous `mudclient.py`
session:

```
金庸群侠传已经执行了三十九秒
目前共有 0 位巫师、0 位玩家在线上，以及 1 位使用者尝试连线中。
您的英文名字：              <- sent "qinfengstd"
...您确定吗(y/n)？          <- sent "y"
请输入您的高姓大名，...
您的中文名字：              <- sent real Chinese name "秦风" -- ACCEPTED first try
请设定您的密码：            <- sent "test1234"
请再输入一次您的密码...     <- sent "test1234"
...您接受这一组天赋吗？     <- sent "y"
您的电子邮件地址：          <- sent "test@example.com"
...男性(m)的角色或女性(f)... <- sent "m"

[1;36m客店[2;37;0m -
    这是一家价钱低廉的客栈，生意非常兴隆。...
    这里明显的出口是 west 和 up。
  /clone/board/kedian_b [ 没有任何留言 ]
  店小二(Xiao er)
你上次连线是从0 on Wed Dec 31 16:00:00 1969
```

Post-login commands, same connection:
- `look`: works, re-renders room + board + NPC cleanly, no crash (the
  `name.lpc` capitalize()-on-0 fix from #91 applies here identically —
  `/clone/board/kedian_b` has no `"short"` set, same as #91).
- `score`: works, full real character sheet — 平民/普通百姓, 秦风
  (Qinfengstd), age/gender/birthdate, 膂力/悟性/根骨/身法 stats, 精/气
  bars, 食物/饮水 bars, kill count, 潜能/实战经验. (This is the
  `combatd.lpc quest.h` include fix from #91 — without it `score` throws
  `*No program in object '/adm/daemons/combatd'!`.)
- `quit`: clean save (drops a starting item, "你丢下一件布衣"), proper
  disconnect message.

`log/debug.log` across the whole run: **zero `error:` lines**, zero
fatal/segfault-shaped lines. Only expected non-fatal noise:
- Compile *warnings* funneled through `log_error()`/§15w (visible to the
  connecting client as "编译时段错误：..." — "Unused local variable",
  "Illegal to declare nosave function" — cosmetic, matches #91's
  already-documented, not-separately-fixed §15w finding).
- One known pre-existing corrupted-save-data issue (below).

## Known non-fatal pre-existing issue (not fixed, matches #91 exactly)

`adm/daemons/chinesed.lpc`'s `create()` calls `restore()` unconditionally
on `data/e2c_dict.o` (English→Chinese dictionary save file). That file's
raw bytes do not decode as a valid LPC mapping
(`restore_object(): Illegal file format`) — genuinely corrupted seed data
in the original archive (same file, same corruption, as #91 — consistent
with both archives sharing this exact save file). Fully caught by
`master.lpc`'s own `preload()` catch wrapper ("错误讯息被拦截"), entirely
non-fatal; `chinesed.lpc`'s `dict` mapping just stays empty. Does not
affect registration, `look`, or `score`.

## Content gaps (same as #91, not independently re-verified per-item since
## the raw trees are confirmed near-byte-identical outside the 22 files
## listed under "Lineage confirmation" above — none of those 22 touch any
## of the content-gap areas #91 documented)

See `libs/jqxz2008/NOTES.md`'s "Content gaps confirmed as
real archive gaps" section — `d/mingjiao/yuan/*` missing skills, missing
`/d/yanziwu/` zone, orphaned `d/wudang/taoyuan/*` drafts, dead
`adm/daemons/network/*` intermud code, corrupted board save data, etc. all
apply identically here (verified the specific files involved are outside
this archive's 22-file diff from #91).

## lpcc sweep

Single sweep via `scripts/lpcc_check.sh` (small/medium lib, no
fix-iteration cycle needed since every fix was ported pre-verified from
#91): **3064/3135 pass (97.74%)** — numerically identical to #91's final
sweep result.

Diffed the two libs' failure lists directly: **70 of 71 failing files are
byte-for-byte the same set** as #91's. The one apparent difference
(`/d/mingjiao/npc/bigmonkey` fails here where #91's sweep instead flagged
`/d/mingjiao/npc/monkey`) is confirmed to be a **batch-sweep ordering
artifact, not a real content difference** — both `monkey.lpc` and
`bigmonkey.lpc` exist, unchanged, and byte-identical between this lib and
#91 (`diff` confirms zero differences in either file); which one happens
to surface as the sweep's `FAIL` line depends on load/object-table state
carried across the whole `--batch` run (AGENTS.md §6b), not on file
content. Same underlying failure category (missing race `走兽` in this
zone's NPC template) either way.

Memory stayed healthy (`free -h`: ~11GB free, well under 1 minute
runtime) — nowhere near mega-lib territory, no backing-off needed.

## Process notes

- Driver launched via `setsid nohup ~/src/fluffos/build-debug/src/driver
  config.fluffos & disown` from within
  `libs/jqxz2008std/` (required for `log/debug.log` to
  resolve, per AGENTS.md §6). Single boot needed (no fix-iteration reboot
  cycle, since every fix was pre-verified against #91 before the first
  boot attempt). PID 859297, killed by exact PID after all testing
  completed; confirmed gone via `kill -0` and `ss -tlnp` no longer showing
  port 40084.
- Test id used: `qinfengstd` (distinct from #91's `qinfengwu` — separate
  lib, separate save-data namespace, no collision risk, but kept distinct
  anyway for clarity in any shared debug.log grep).

## 2026-07-23 re-verification pass (driver rebuild + formatter + WASM)

- **LPC reformat**: ran `format-corpus.mjs` over all of `work/` (3,135
  `.lpc` files) — 3,102 written, 13 already-idempotent, 20 refused
  (self-checked round-trip failures on messy legacy syntax, matching
  #91's own reformat numbers, as expected for this near-identical
  codebase).
- **Native retest against the freshly-rebuilt driver**: booted clean on
  port 40084, zero fatal preload errors. Full registration flow with a
  fresh real Chinese name ("秦风标"/`qinfengstdb`, distinct from the
  earlier `qinfengstd` test id) through the complete wizard (id →
  confirm → Chinese name → password → confirm → gift accept → email →
  gender) into the actual game world (客店); `look`, `score` (correct
  stats/HP/potential), and `quit` (correct item-drop + clean save) all
  verified with real output, zero runtime errors in the session. No
  regressions from the reformat or the new driver binary.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly, same preload warnings as native. **Full registration +
  login + look + quit all work end-to-end under WASM**, same as #91 —
  this codebase doesn't gate login on `query_ip_number()`'s format, so
  the documented WASM IP-check limitation doesn't apply. Same harmless
  cosmetic artifact as #91: a fresh registration's "上次连线" timestamp
  shows the Unix epoch ("Wed Dec 31 16:00:00 1969") under WASM's
  synthetic clock — not a functional issue.

## WASM-enablement pass (2026-07: loopback-allow + admin seeding)

Standard pass per AGENTS.md §1.3b/e + §1.5 (applied identically across
the three jqxz2008 builds — engine files are byte-identical
in this group):

- `adm/daemons/band.lpc:39` `is_banned()`: short-circuit `return 0` for
  loopback (`127.0.0.1`/`127.*`), empty, or non-string site values
  before the regexp ban-list scan. `logind.lpc:67`'s
  `BAN_D->is_banned(query_ip_name(ob))` gate in `logon()` is thereby
  loopback-proof (and robust against the WASM `query_ip_number()`/
  `query_ip_name()` garbage-return bug).
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (checked `logind.lpc`'s full input_to
  chain; the only other connection gate is the in-memory `mad_lock`
  admin lockdown flag, default off — left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real native flow (id → y → Chinese name → password ×2 → gift y → email
→ gender m). Granted `(admin)` via `adm/etc/wizlist` (file was shipped
empty; now contains `fluffos (admin)`), which `securityd.lpc` reads at
create(). Verified after restart: login shows `目前权限：(admin)`,
`update /cmds/usr/score` prints 重新编译成功. Save files (must be
committed): `work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

Retest: fresh registration (秦风/ceshizhe) end-to-end + look/score/quit
clean; fluffos login + wizard update clean; debug.log shows only the
known pre-existing corrupted-save restore errors (chinesed e2c dict /
kedian board) documented above — zero new errors; test character saves
removed.

## Dual-mode verification pass (2026-07-24)

- **Native** (port 40084): fresh registration `ceshier`/秦风 end-to-end
  into 客店 + look/score/quit all correct; `fluffos`/`Mud@2026` login
  shows `(admin)`, `update /cmds/usr/score` prints 成功. debug.log:
  only the two documented pre-existing corrupted-save restore errors
  (caught by the lib's handler) — zero new errors. Driver killed by
  exact PID.
- **WASM** (build-wasm with query_ip_number/resolve fixes): fresh
  registration `wasmceshi`/秦风 end-to-end + look/score/quit all
  correct; second invocation: `fluffos` admin login `(admin)` +
  `update` 成功. **Verdict: native OK + wasm OK.** No fixes needed this
  pass. Test character saves removed; fluffos.o timestamp churn
  reverted.

## 2026-07-25 深度功能测试 / Deep functional test (AGENTS.md §10.7)

One continuous native `mudclient.py` session against a freshly-built
native driver (port 40084), plus a second `fluffos` admin session used
specifically to reach real combat/death/reincarnation (same reasoning as
`jqxz2008`'s own §10.7 pass: the main test character never
accumulated enough money/combat standing to safely risk real `kill`
within the time budget). This lib is the confirmed-identical-engine
lightweight-content sibling of `jqxz2008` (see "Lineage
confirmation" above) — this pass independently re-derived the starting
zone's room graph and NPC ids from THIS lib's own source (not assumed
from the sibling) and live-reproduced every bug it fixed, since none of
`jqxz2008`'s own §10.7-round fixes (chinesed restore guard,
`/log/nosave` `assure_file()`, the `bai`/`apprentice` paren bug) had been
ported to this archive yet — they are engine-level files outside the
22-file diff between the two archives, so they carried the exact same
pre-fix bugs untouched.

**Test character**: id `shenrongfeng`, password `xia2026wu`, Chinese name
沈容风 (male). Left in a clean, alive, fully-saved state at `/d/city/kedian`
(客店, the starting inn), title 叫化子/丐帮第二十代弟子 (Beggars' Sect,
20th generation, master 左全/Zuo Quan), `begging` skill improved once via
the organic teacher path, 潜能 98/99%. Save files left in place per the
task instructions (`work/data/user/s/shenrongfeng.o`,
`work/data/login/s/shenrongfeng.o`) as evidence. Admin account
`fluffos`/`Mud@2026` (pre-existing) reused for the death/reincarnation
leg; left alive, at `/d/city/wumiao` (its own now-legitimate chosen home
per the reincarnation flow's own explicit `ob->move("/d/city/wumiao")` —
see the startroom-discriminator finding below), title 天神, stats reduced
from the death (this is expected/correct post-death state, not a bug).

### What was verified working, live

- Full registration wizard with a real Chinese name (沈容风), landing in
  客店 — `look`/`score`/`i` all correct at every step.
- Starting-zone navigation read from this lib's own room source
  (`d/city/{kedian,beidajie1,guangchang}.lpc`), not guessed/assumed from
  the sibling.
- Safe sparring: `help newbie` (`work/doc/help/newbie`) documents `fight`
  (较量) as the non-lethal form (stops automatically at ~50% health) vs
  `kill` (real, lethal) — identical wording to the sibling. Used
  `fight liu` against 流氓头 at 中央广场 (learned live that the NPC's real
  id is the 2-word `"liumang tou"`/alias `"liu"`, NOT the no-space
  `"liumangtou"` a first guess produced — a `fight liumangtou` typed
  command correctly no-ops with "你想攻击谁？", not a bug, just the wrong
  id) — auto-stopped correctly at reduced health, zero real damage risk.
- Sect join via the organic path: `guangchang`'s tree-hole
  (`enter shudong` — the room's actual verb/arg shape, not a bare
  direction) → `d/gaibang/inhole.lpc`'s passphrase gate
  (`say 天堂有路你不走`, which only opens a DOWN exit to a deeper jail-guarded
  room; 左全/Zuo Quan the teacher NPC is itself already standing in the
  passphrase-gated inhole room, so `down` is a wrong turn into the
  九袋长老-guarded `undertre` room and gets you kicked back out — confirmed
  live, not a bug, just extra map topology) → `bai zuo` — worked, correct
  flavor text, `score` afterward shows the new title/master.
  Also traced (not exercised, to keep the character simple) the White
  Camel Mount (白驼山) sect's alternate teacher-recruit gate at
  `kungfu/class/btshan/ouyangke.lpc`'s `attempt_apprentice()`-style flow —
  confirms a second, independent join mechanism exists, same as the
  sibling's finding.
- Organic skill learning from a teacher NPC: `xue zuo begging` (after the
  chinesed fix below) — consumed 潜能 correctly, printed the expected
  "你的「begging」进步了！" message, confirmed via `score`.
- `cha zuo` (list a teacher's skills), once the crash below was fixed:
  full skill list rendered correctly.
- Clean `quit` (multiple times) followed immediately by a `debug.log`
  line-count check each time — **zero new `error:`/fatal lines** any
  time, on the fully-fixed driver.
- State persistence across BOTH a clean `quit` + a real **~90-second**
  wall-clock wait + fresh restore-login, AND a driver-level test: killing
  the driver process outright (SIGTERM, no graceful shutdown/autosave —
  confirmed the hard way, see "Testing-methodology note" below) loses any
  state that was never explicitly saved, exactly as expected — not a bug,
  a property of an abrupt process kill with no autosave, and a useful
  reminder to `quit`/`save` before any driver restart during a test pass.
  After the real fix cycle (driver restarted with the fixes in place),
  location, sect membership, master, skill level, 潜能 spend all
  correctly round-tripped through a clean `quit` → **real ~90s wait** →
  restore-login.
- Unclean (net-dead, not `quit`) disconnect + reconnect: exercised both
  promptly (reconnect within seconds, "重新连线完毕", landed exactly where
  standing) and after a real **~150-second** wall-clock wait (backgrounded
  `sleep`, not a short synthetic gap) — same clean result both times, all
  state intact. Did **not** attempt the full 600s `NET_DEAD_TIMEOUT`
  wait (`include/user.h:10`) for time-budget reasons — but see the bug
  found below, which makes this exact code path's correctness far more
  than a formality this time.
- Real combat + death + corpse + ghost + reincarnation, end to end, live
  (not code-reviewed): the `fluffos` admin character (`goto
  /d/death/gateway`) fought a 黑无常 (Black gargoyle) NPC and **actually
  died**. Confirmed the full chain once the `/log/nosave` bug below was
  fixed: `你死了` → ghost title (【鬼魂】) → corpse object left in the
  room → `score` shows reduced stats/empty jing-qi bars → the documented
  "ask yourself about 回家" ritual at `/d/death/inn1.lpc` (`gate` →
  `gateway` → `road1` → `inn1`, `ask fluffos about 回家`) →
  `reincarnate()` fires and `ob->move("/d/city/wumiao")` moves the
  (now living again) character there, title back to 天神. Zero new
  `debug.log` lines across the whole fight+death+reincarnation sequence
  on the fixed driver.
- Shop (`buy`/`list`, F_DEALER pattern via `feature/dealer.lpc`): reached
  醉仙楼 (a food stall) by the same room-graph route as the sibling
  (`beidajie2` → east). `list` rendered correctly (烤鸡腿/牛皮酒袋/包子 with
  prices). `buy` exercised three times, all three produced the CORRECT
  rejection with no crash: `buy` bare ("你想买什么？ 1"), `buy 长剑` for an
  item this shop doesn't sell ("你想买什么？ 2"), and `buy jitui` for an
  item the shop DOES sell but the admin character has no money for
  ("穷光蛋，一边呆着去！" — genuine insufficient-funds rejection via
  `MONEY_D->player_pay()`).

### Not verified live (honest gap)

- **A completed, successful purchase.** Same root cause as the sibling:
  no starting-balance grant for new characters (nothing else in this
  archive's 22-file diff from the sibling touches money init either), and
  the beggar-sect membership the test character organically joined is
  explicitly forbidden from buying at all
  (`feature/dealer.lpc:116-117`). Reaching a real purchase would need a
  separate non-beggar character with a source of starting gold, beyond
  this pass's time budget. The rejection paths (bare/missing-item/
  insufficient-funds) were all verified live and crash-free, which is the
  strongest evidence available that the success path (an ordinary
  `ob->move(this_player())` after `MONEY_D->player_pay()` returns
  nonzero) is very likely fine too, but that's a code-review conclusion
  for the success branch specifically, not a live one.
- **The full 600-second `NET_DEAD_TIMEOUT` wait**, i.e. letting a REAL
  net-dead player sit disconnected long enough for `user_dump()` to fire
  on its own `call_out`, rather than invoking it directly via `call`.
  Forced it directly instead (see bug #4) — the shortcut is justified
  here specifically because the whole point of that live test was to
  reproduce the crash INSIDE `user_dump()`, which is fully deterministic
  regardless of whether the `call_out` fires naturally at 600s or is
  invoked directly; the direct-call route reproduced the crash, confirmed
  the fix, and additionally proved `command("quit")` (the actual
  force-quit save) now runs afterward — the real-world consequence the
  full-duration wait exists to check.

### Bugs found and fixed

**1. `adm/daemons/chinesed.lpc` — corrupted save data leaves a global
`mapping` as raw `0`, crashing the FIRST real use of `cha`/`chinese()`
(AGENTS.md §7.7, third bullet — identical bug, identical file, to
`jqxz2008`'s own §7.7 finding; this archive carried the
exact same pre-fix `create()`, confirmed byte-identical before the fix)**

```lpc
// BEFORE:
void create() {
  seteuid(getuid());
  restore();
}
// AFTER:
void create() {
  seteuid(getuid());
  catch(restore());
  if (!mapp(dict)) dict = ([]);
}
```
`restore()` throws on this archive's malformed `data/e2c_dict.o` (same
known-corrupted seed data documented since the very first pass on this
lib); uncaught, it aborts `create()` before local recovery can run, and
`§7.7`'s exact mechanism zeroes `dict` back to raw `0`. Live-reproduced:
`cha zuo` and `xue zuo begging` both crashed with `*Value being indexed
is zero.` at `chinesed.lpc:94` before the fix. **Verified**: rebooted,
repeated `bai zuo` → `xue zuo begging` → `cha zuo` — all three now work
cleanly, zero new `debug.log` lines.

**2. Missing `/log/nosave/` runtime directory crashes `combatd.lpc`'s
`killer_reward()` on EVERY death and `kill.lpc`'s PK-attempt logger on
every player-vs-player `kill` (AGENTS.md §7.11, exact match — same
example directory the catalog entry already names; identical bug/files to
`jqxz2008`'s own §7.11 finding, confirmed byte-identical
pre-fix)**

`work/log/nosave/` did not exist in this archive either. Fixed the same
two live write sites plus the `bai`/`apprentice` `FENG` counter (bug #3
below shares the same missing-directory root cause) using the lib's own
`assure_file()` idiom (`adm/simul_efun/file.lpc:11`):
```lpc
// combatd.lpc killer_reward(), kill.lpc do_kill():
assure_file("/log/nosave/KILLRECORD");   // or ATTEMP_KILL
write_file("/log/nosave/KILLRECORD", ...);
```
**Live-reproduced and verified the severe shape this catalog entry
warns about**: before the fix, killing the `fluffos` admin character in
real combat threw `*Wrong permissions for opening file
/log/nosave/KILLRECORD for append. "No such file or directory"`
UNCAUGHT inside `die()`, aborting every statement after it (corpse
creation, moving the player to the death room, setting the ghost flag) —
the character was left standing in the combat room, still "alive" by the
engine's bookkeeping. After the fix: full death → corpse → ghost →
`/d/death/gate` chain completes cleanly in one shot, confirmed live,
`log/nosave/KILLRECORD` created on disk.

**3. `cmds/skill/bai.lpc` / `cmds/skill/apprentice.lpc` (identical
duplicate files) — misplaced parenthesis passes the WRONG ARGUMENT TYPE
to `query()`, so the Feng-Qingyang defection-counter check never actually
ran (same class as `jqxz2008`'s own bug #4 finding,
identical files, confirmed byte-identical pre-fix)**

```lpc
// BEFORE (both files, same line):
if (((string)me->query("family/master_id" == "feng qingyang")) || ((string)me->query("family/master_name" == "风清扬"))) {
// AFTER:
if (((string)me->query("family/master_id") == "feng qingyang") || ((string)me->query("family/master_name") == "风清扬")) {
```
The `==` comparison sat INSIDE `query()`'s argument list, so `query()`
was actually invoked with a boolean (always producing `0`/false for any
real property name) instead of the intended string key — the branch
could never fire regardless of the player's actual master. Also added the
matching `stringp()` guard on the `FENG` counter's `read_file()` result
(§7.9-shaped: `read_file()` on a not-yet-created file returns `0`, which
would otherwise flow into `atoi(0)`) and `assure_file()` before its
`write_file()`, same as bug #2's fix. Not separately live-exercised (would
need a character to actually be Feng Qingyang's disciple first, out of
scope for this pass) but confirmed by direct read that it now matches
every other correctly-written call site in the same file.

**4. Shared `tell_room()` simul_efun passes a raw `int 0` as
`message()`'s 4th (exclude) argument when called with only 2 args — an
UNCAUGHT crash inside the net-dead force-quit handler `user_dump()`
silently disables the ENTIRE net-dead safety net (AGENTS.md §7.12, exact
match to its "Severity escalation" paragraph — this pass independently
found and live-reproduced the SAME shape in the SAME function
(`user_dump()`'s `DUMP_NET_DEAD` case) that the catalog entry's own
severity-escalation example describes on `dtsl`, in a completely
unrelated lineage — strong evidence this shape is worth actively
hunting for on every future §10.7 pass, not just noting when stumbled
upon)**

```lpc
// adm/simul_efun/message.lpc — BEFORE:
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude);
}
// AFTER:
varargs void tell_room(mixed ob, string str, object *exclude) {
  if (ob) message("tell_room", str, ob, exclude || ({}));
}
```
`clone/user/user.lpc`'s `user_dump(DUMP_NET_DEAD)` — the function that
runs when a net-dead player's `NET_DEAD_TIMEOUT` (600s) `call_out`
finally fires — opens with a bare 2-arg `tell_room(environment(), ...)`
call (no exclude list), leaving `exclude` at its varargs default of `0`
(a plain int, not an array). **Live-reproduced directly** (via the
`fluffos` admin's own `call me->user_dump(1)` wizard command, matching
`DUMP_NET_DEAD`'s constant value — chosen specifically so the crash could
be confirmed deterministically without a real 600-second wait, see the
"not verified live" section above for why this substitution is sound
here): before the fix, this threw `*Bad argument 4 to EFUN message()
Expected: object, array, Got: int(0).` **uncaught inside `user_dump()`
itself**, which aborts the function at that exact line — the very next
statement, `command("quit")` (the actual force-quit save), **never ran**.
Net real-world consequence, exactly as §7.12 warns: any player who
genuinely net-deads and never manually reconnects would stay alive in
server memory forever (until a driver restart), never actually saved via
this path — the safety net the whole mechanism exists for silently does
nothing. This is a SHARED simul_efun wrapper (29 call sites across 16
files use the vulnerable 2-arg form lib-wide, per a `grep -c` sweep), so
the single fix above covers all of them, not just this one call site.
**Verified**: rebooted, re-ran `call me->user_dump(1)` on the admin
account — the "断线超过 10 分钟，自动退出这个世界" message now prints
correctly AND the admin is actually logged out via a real, clean `quit`
(save confirmed via the "当你下次连线进来时，会从这里开始" prompt),
zero new `debug.log` lines.

### Startroom-discriminator check (per this task's explicit instructions)

`d/city/wumiao.lpc`'s `init()` and `d/death/gate.lpc`'s `init()` both
unconditionally write the entering player's permanent `startroom` field
on mere room entry — structurally the exact shape AGENTS.md §7.24
describes, and the exact same two files `jqxz2008`'s own
§10.7 pass flagged, briefly "fixed," and then retracted on user review.
Applying that pass's own discriminator explicitly, on THIS archive's own
source (not assumed from the sibling, though the files are confirmed
byte-identical): **both rooms carry `set("valid_startroom", 1)` /
`set("valid_startroom", "1")` in their own `create()`** — grepped and
confirmed directly:
```
d/city/wumiao.lpc:20:  set("valid_startroom", "1");
d/city/wumiao.lpc:38:  me->set("startroom", base_name(environment(me)));
d/death/gate.lpc:18:  set("valid_startroom", 1);
d/death/gate.lpc:31:  ob->set("startroom", "/d/death/gate");
```
Per the discriminator ("more likely a genuine bug if the target room
does NOT carry `valid_startroom`... more likely intentional design if
the target DOES carry that flag"), this is **not treated as a bug** —
left exactly as shipped, consistent with the sibling's own retraction.
Reinforcing evidence found live this pass: `d/death/inn1.lpc`'s
reincarnation ritual (`do_stuff()`) EXPLICITLY does
`ob->move("/d/city/wumiao")` right after `ob->reincarnate()` — i.e. the
game's own death-recovery flow deliberately routes every reincarnated
player through wumiao regardless of where they died, which only makes
narrative/mechanical sense if standing there is SUPPOSED to (re-)anchor
your home, matching the "deliberate checkpoint" reading from the
sibling's retraction writeup.

As an extra due-diligence step (verifying the OTHER `set("startroom"`
call sites in this lib don't hide a same-shaped bug the sibling's pass
didn't have occasion to check, since it's a different, if
byte-identical, archive), grepped every `set("startroom"` site
lib-wide (28 hits): the large majority (`kongkong.lpc`,
`killer-{n,s,e,w}.lpc` ×2 (both `clone/npc/` and `d/npc/` copies),
`mao18.lpc`, `shisong.lpc`, `ouyangke.lpc`) are NPC files calling bare
`set(...)` on their OWN object in their own `create()` — cosmetic
NPC-flavor data, never touches a player object, not this bug shape at
all. Of the remainder that DO write to a player object
(`ob->set`/`me->set`/`dest->set`): `cmds/usr/save.lpc`,
`cmds/usr/quit.lpc`, `adm/daemons/logind.lpc` are the lib's own
legitimate save/quit/login mechanism (the thing the bug pattern is
defined relative to, not an instance of it); `d/city/cangku.lpc`,
`d/shaolin/cangku.lpc`, and the `d/shaolin/` jail-cluster files
(`jianyu.lpc`, `jlyuan.lpc`, `shulin9/11/13.lpc`, `andao2.lpc`) are a
matched capture/release mechanic already separately confirmed genuine by
the sibling's own pass (identical files); `kungfu/condition/bonze_jail.lpc`
resets a released prisoner's startroom to the `START_ROOM` macro itself
(`/d/city/kedian`, which — checked directly — carries `valid_startroom`
as the archive's own default landing room, so this is the SAFEST possible
target, not a bug); `d/city/npc/tang.lpc`'s ransom-redemption flow moves
a freed captive to `/d/city/kedian` and sets that same already-`valid_startroom`
room. **No additional instances of the bug pattern found.**

### Testing-methodology note (not a mudlib bug — a note for future passes)

Killing the driver process via plain `kill <PID>` (SIGTERM) does **not**
autosave connected players — `debug.log` logs `FATAL ERROR: SIGTERM:
Process terminated` with no save/cleanup step visible before it. A
character's in-memory-only changes since their last `quit`/`save` are
lost if the driver is restarted this way. This bit this pass directly:
the test character's freshly-joined sect membership (from `bai zuo`,
never followed by `quit`) was lost across a driver restart done to load
the chinesed fix, and had to be redone. Not a mudlib defect — restarting
a live driver to pick up simul_efun/daemon-file changes without asking
connected players to `quit`/`save` first is inherently lossy on any
lib, and worth remembering on any future fix-then-reboot iteration cycle:
either `quit` test characters before a restart, or expect to redo
whatever wasn't saved.

### Bug-class mapping

- Bug 1 → **§7.7**. Bug 2 → **§7.11**. Bug 3: same
  misplaced-parenthesis/wrong-argument-type shape as several other
  "obviously-wrong call-site" fixes already cataloged in this file and
  the sibling's own NOTES.md — not a numbered AGENTS.md class of its own.
- **Bug 4 → §7.12**, specifically its "Severity escalation" paragraph
  (added after `dtsl`'s pass) — this pass is a SECOND independent
  live confirmation of that exact escalation shape (crash inside
  `user_dump()`'s net-dead branch silently disabling the force-quit
  safety net) in an unrelated lineage, strengthening the catalog's own
  suggestion to treat any lib carrying this `tell_room()` shape as a
  live crash risk rather than cosmetic. No new AGENTS.md entry needed —
  cited directly.
- Startroom check → **§7.24**'s own discriminator, applied explicitly
  per this task's instructions; confirmed NOT a bug on this lib, matching
  the sibling's retraction, with additional due diligence across every
  other `startroom`-writing file in this archive (not just the two
  flagged ones).

### Process notes

Driver run from `libs/jqxz2008std/` via `setsid nohup ...
driver config.fluffos > driver_stdout.log 2>&1 & disown`, restarted twice
across the fix-iteration cycle (once after the chinesed/`log/nosave`/
bai-paren fixes, once — unnecessary in hindsight but done for a clean
before/after comparison — after the `tell_room()` fix). Each old PID
killed only after confirming `readlink -f /proc/<pid>/cwd` matched this
lib's own `work/` directory; several other agents' driver processes for
other libs (`fy2qh`, `hymud`, `xajh2`, and others)
were running concurrently throughout and were never touched. Final
driver killed by exact PID after all testing completed, confirmed gone
via `ps -p`/`ss -tlnp` no longer showing port 40084. Scratch file
`driver_stdout.log` removed before finishing, per task instructions.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一代码库，内容更精简。
