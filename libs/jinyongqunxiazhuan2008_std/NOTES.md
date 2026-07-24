# jinyongqunxiazhuan2008_std — 金庸群侠传 (Jin Yong Heroes Gathering, standard edition)

Archive: `archives/金庸群侠传2008版.rar` ("Jin Yong Heroes Gathering 2008,
standard edition" — plain "2008版" title, as opposed to archive #91's
"2008加强版"/enhanced edition). Extracted mudlib root: `raw/jy/` (a single
top-level `jy/` directory inside the archive — same layout as #91). Port:
**40084**. Status: **done** (boots clean, full registration flow verified
with a real Chinese name, post-login `look`/`score` verified working).

## Lineage confirmation (evidence, not assumption)

This archive is **not merely "the same family" as #91/`jinyongqunxiazhuan2008`
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

See `libs/jinyongqunxiazhuan2008/NOTES.md`'s "Content gaps confirmed as
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
  `libs/jinyongqunxiazhuan2008_std/` (required for `log/debug.log` to
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
the three jinyongqunxiazhuan2008 builds — engine files are byte-identical
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
