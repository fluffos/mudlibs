# wmkj — 未明空间

Archive: `未明空间.rar` (#55). Port: 40049. Status: **done** (boots
clean, full registration flow verified end-to-end twice, with two
different real Chinese names, both reaching the actual game world).

## What this is

The archive's own `raw/wmkjlib/README.txt` (GBK, converted before reading)
identifies it explicitly: this is a single-player/offline snapshot of
**未明空间 ("Unnamed/Unclear Space", "wmkj")**, dumped by its author
"龙宝宝 (xiha)" on **Dec 13, 2001**, described as "a backup from the end
of September [2001]" made obsolete by later changes, released for other
players to run standalone. The raw root directory is literally
`wmkjlib/`, and the mudlib itself lives at `wmkjlib/world/` (identified
via `wmkjlib/config.jh`'s `master file : /adm/obj/master` /
`mudlib directory : ./world` directives) — the slug `wmkj` is
a pinyin transliteration of 未明空间 chosen for this port, it does not
appear literally in the archive.

The archive also bundles a second text file, `小熊泥苑.txt` — this is
**not** specific to this game; it's the generic download-site
boilerplate/branding for `小熊泥苑` (dtxy.126.com, a mudlib-hosting site
seen bundled with several other unrelated archives in this project, e.g.
shujian2008/sjtx2) and its body text is actually about a
completely different game ("狂想"/Kuangxiang), not 未明空间 — a
site-wide readme that got bundled with this download by habit, not a
clue about wmkj's own lineage. Ignored for lineage purposes.

**Live banner identifies the actual displayed game name as "江湖风云"
("Jianghu Fengyun") "之 夕阳再现"** (`adm/daemons/logind.lpc`'s `logon()`
banner) — i.e. wmkj is itself a rebrand/fork of the 夕阳再现
("Sunset Reappears") lineage already seen twice in this project
(archives #46 `xyzxfk` and #47
`xyzxfy2`). Confirmed via md5sum: `adm/simul_efun/chinese.c`
is **byte-identical** to `xyzxfk`'s copy
(`961d77af057bb93db320af05be5883fc`), while `master.c`/`logind.c`/
`securityd.c` all differ (not a duplicate archive — a genuine, separately
maintained fork sharing a common ancestor, same pattern as previously
documented "similar titles/some shared files ≠ full shared lineage").
`u/snow/logind.c` (a per-wizard sandbox copy) exists in both archives too.

Layout: `adm/{daemons,obj,simul_efun,etc,etcc,tmp}` (not `adm/single/`).
Uses `feature/dbase.lpc`'s real local `set`/`query`/`delete`
(`inherit F_DBASE`) for per-object property storage — **not** the
nitan-family shared-simul_efun-dbase architecture bug (confirmed by
reading `feature/dbase.lpc` directly: real local functions, no bare
`efun::set`/`query`/`delete` calls anywhere in the lib — `grep` came up
empty). ~11,736 raw files, 10,641 `.lpc` files after the rename — a
mid-sized lib for this batch.

## Fixes applied

1. **AGENTS.md §15h**, standard shape, `adm/simul_efun/chinese.lpc`'s
   `is_chinese()`: GBK lead-byte range check
   (`strlen(str)>=2 && str[0]>160 && str[0]<255`) rewritten to a CJK
   Unicode codepoint check
   (`strlen(str)>=1 && str[0]>=0x4e00 && str[0]<=0x9fff`).
2. **AGENTS.md §15h**, `check_legal_name()` in `adm/daemons/logind.lpc`
   (this lib has no separate `named.lpc`-based `check_legal_name` —
   it's defined directly in `logind.lpc`):
   - Byte-count bound `strlen(name) < 2 || > 10` → character-count bound
     `< 1 || > 5` (the message text, "必须是 1 到 5 个中文字", already
     stated the correct intended character count).
   - Sliding check `i%2==0 && !is_chinese(name[i..<0])` (alternating
     GBK-lead-byte offsets, checking a variable-length tail slice) →
     `!is_chinese(name[i..i])` on every index (one whole character per
     index now, no `<0]`-tail-slice trick needed since `is_chinese` only
     ever inspected `str[0]`).
3. **AGENTS.md §15h**, `adm/daemons/named.lpc`'s `PATH()` macro +
   sliding-window `invalid_new_name()` (applied proactively per standing
   policy even though **this file turned out to be dead code** — see
   "Confirmed NOT needed" below for how that was verified):
   - `PATH(name)` macro: `name[0..1]` ("first GBK char") →
     `name[0..0]` (first character).
   - `strlen(name) < 2` empty-name guards (4 call sites: `remove_name`,
     `map_name`, `who_is`, `invalid_new_name`) → `< 1`.
   - `invalid_new_name()`'s combined-length guard `strlen(name) < 4` →
     `< 2`; sliding-window loop bound `i <= l - 4` → `i <= l - 2`;
     2-character-equivalent windows `name[i..i+3]` (4 bytes) →
     `name[i..i+1]`; 3-character-equivalent windows `name[i..i+5]`
     (6 bytes) → `name[i..i+2]`; corresponding `i+6<=l` guard → `i+3<=l`.
4. **AGENTS.md §15p**: `adm/etc/preload` had
   `/adm/daemons/network/dns_master` live — commented it out
   proactively before the first boot attempt.
5. **AGENTS.md §8d/§15o**: `adm/obj/master.lpc` had **no**
   `get_include_path()` apply at all. Added the standard shape
   (prepend the compiling file's own directory, fall back to
   `:DEFAULT:`). This is a correct, harmless, by-the-book fix per the
   documented pattern — see "Confirmed NOT needed" below for the
   important caveat that it did **not** turn out to be the actual cause
   of this lib's largest lpcc-sweep failure cluster (verified by direct
   A/B testing, not assumed).
6. **AGENTS.md §8b** (new mudlib-bug instance, same shape as the
   `xzyx` finding): `message_combatd(msg, me, victim)` is
   called from `adm/daemons/combatd.lpc` and two `kungfu/skill/*.lpc`
   files, but was never defined anywhere in this lib. Every call site
   passes the same 3 args as `message_vision`, so added it as a plain
   alias `varargs void message_combatd(string msg, object me, object you)
   { message_vision(msg, me, you); }` in `adm/simul_efun/message.lpc`,
   placed **after** `message_vision`'s own definition (§8b same-file
   ordering gotcha).
7. **AGENTS.md §11** (copy-paste bug, new instance):
   `clone/weapon/panguanbi.lpc` (判官笔, "judge's writing-brush") did
   `inherit PEN; ... init_pen(25);` — `PEN`/`init_pen` are not defined
   *anywhere* in this archive (no `/inherit/weapon/pen.lpc` exists at
   all). The file's own description text ("这是一柄普通的精钢剑" — "an
   ordinary refined-steel **sword**") and its `material`/`unit` fields
   match the `SWORD` template exactly, confirming this was cloned from
   a sword weapon file and half-renamed. Fixed to `inherit SWORD;
   ... init_sword(25);` (matching `/inherit/weapon/sword.lpc`'s real
   `init_sword(int damage, int flag)` signature).
8. **Pre-existing typo, new instance**: `d/wudang/taoyuan/tyroad{4,5,6,7}.lpc`
   all had `#include __DIR_"feng.h"` (missing the second underscore in
   `__DIR__`, a genuinely undefined macro/token) — the intended header
   `d/wudang/feng.h` (defining `look_feng()`, referenced via
   `(:look_feng:)` in each room's `item_desc`) is one directory **up**
   from `taoyuan/`, not in the same directory, so even a correct
   `__DIR__"feng.h"` wouldn't have resolved it. Fixed to
   `#include "../feng.h"` in all 4 files (confirmed correct against
   `d/wudang/wulao.lpc`/`sanlao.lpc`/etc, which already correctly
   `#include "feng.h"` from `d/wudang/` itself).
9. **Pre-existing missing-opening-quote typos** (AGENTS.md §10-shape,
   several new instances, confirmed against the raw pre-conversion GBK
   bytes — not an encoding artifact): a `set("long", <bare Chinese
   text>` with no opening `"` before the text (closing `"` present or,
   in one case, also missing) in:
   - `d/quanzhen/hudi6.lpc`, `d/quanzhen_old/hudi4.lpc`,
     `d/quanzhen_old/hudi6.lpc` (a third, separate copy of the exact
     same "小湖底" room text under a different directory — found only
     after re-sweeping post-fix) — added the missing opening `"`.
   - `d/quanzhen_old/hudi5.lpc` — missing **both** opening and closing
     quote/`\n` around the same text block — added both.
   - `d/player/fyue_room.lpc` — same shape, one `"long"` description
     missing its opening quote (and a trailing `\n"` before the closing
     paren) — fixed.
   - `d/city/sj.lpc` — a much larger instance: the whole `do_out()` /
     `look_out()` tail of the file had **every** string literal argument
     written bare with no quotes at all (`add_action(do_out, out)`,
     `message_vision($N大喊一声...\n, me)`, `me->move(__DIR__guangchang)`,
     `me->command(chat 啊～～～)`, `me->set_temp(die_for,...)`, a bare
     `return <text>;`, etc — a decorative, non-critical "jump off the
     world's edge" easter-egg room, not on the boot/registration path).
     Quoted every literal to match evident intent; also initialized the
     previously-unset `object me;` to `this_player()` (the function is
     bound via `add_action`, so `this_player()` is the correct actor —
     the original code declared but never assigned `me` before using it).

## Confirmed NOT needed (verified by reading source, not assumed)

- **§4** (master.lpc `load_object()`-during-compile recursion in
  `valid_read`/`valid_write`): this lib's `master.lpc` only ever calls
  `find_object(SECURITY_D)` in both applies, never `load_object()` — no
  lazy-load recursion is possible. Confirmed by reading the full
  `valid_read`/`valid_write` bodies before the first boot attempt.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both already present
  and correct in the original `master.c` (`return ROOT_UID;` /
  `return BACKBONE_UID;`).
- **§15l** (master.lpc `create()` destructing `SIMUL_EFUN_OB`): this
  lib's `master.lpc create()` is a single `write()` line, nothing else —
  no destruct/reload dance present.
- **§15 / nitan-family shared-simul_efun dbase bug**: `grep`ped the
  whole lib for `efun::set(`/`efun::query(`/`efun::delete(`/`addn(` —
  zero hits. `feature/dbase.lpc` implements real local
  `set`/`query`/`delete`/`add` (+ `_temp` variants) as genuine functions,
  inherited directly by `char.lpc`/`room.lpc`/etc — the architecturally
  correct pattern (same family as `rzrmud`/`xkx2001`), not the bare-
  simul_efun-call architecture bug.
- **§14** (2-arg `valid_override`): this lib's `master.lpc` has the old
  2-arg `valid_override(file, name)`. Checked every `#include`d
  simul_efun fragment (`atoi.c`, `chinese.c`, `gender.c`, `object.c`,
  `path.c`, `wizard.c`, `message.c`, `file.c`) for an `efun::destruct`/
  `efun::move_object` override written inside a *fragment* file (which
  is the specific scenario §14 protects against) — the only
  `efun::destruct` override in the whole simul_efun composition is in
  `adm/obj/simul_efun.c` itself (the real `SIMUL_EFUN_OB`, which already
  passes the existing 2-arg check's `file == SIMUL_EFUN_OB` branch), so
  the gap is real but provably unreachable in this lib. Left as-is
  (matches AGENTS.md's own guidance that this fix is "free" when
  applicable but not worth forcing when confirmed inert).
- **§15n/§15o custom-securityd func-discrimination gap**: this lib's
  `securityd.lpc` (`adm/daemons/securityd.lpc`) *is* a genuinely custom
  ACL (`trusted_read`/`exclude_read` mappings keyed by directory +
  wizard-status), not the simpler `find_object`-only pattern — but its
  `valid_read` already has its own escape hatch for exactly this
  scenario: `if (!sscanf(base_name(user),"/clone/user/%*s") &&
  author_file(base_name(user))==ROOT_UID) return 1;` — i.e. any read
  attributed to a ROOT-owned (system) calling object is allowed
  unconditionally, which covers the driver's own lazy compile-time reads
  triggered from system daemons. Confirmed no `Read access denied`
  errors anywhere in `debug.log` across two full interactive registration
  sessions.
- **§8e** (`tail()` non-efun): zero call sites found via
  `grep -rn '\btail(' --include="*.lpc"`.
- **§8f** (`TYPE * name1, name2;` array-modifier-doesn't-propagate bug):
  156 lines matched the shape via grep, but spot-checking several (e.g.
  `feature/dealer.lpc:277`'s `string *goods,nature,respect,rude;`)
  showed `nature`/`respect`/`rude` are genuinely used as plain strings
  later in the same function, not arrays — correctly-written C-style
  declarations, not the Dead-Souls-lineage bug. This is a different,
  unrelated codebase lineage (Chinese wuxia, not English/Nightmare) and
  the bug class does not recur here; left unfixed per AGENTS.md's own
  caution against blind bulk-fixing a regex-shaped pattern without
  verifying genuine instances exist.
- **§15j** (per-IP registration throttle): grepped `adm/daemons/band.lpc`
  for `IsTimeAllowed`/`NewIps`-shaped anti-flood logic — not present;
  no throttle to work around when testing registration twice.

## The get_include_path() investigation (§8d/§15o) — added the fix, but it wasn't the actual cause

The lpcc sweep's largest single failure cluster (30 files, all under
`u/snow/wudujiao/` and `u/fyue/`, personal wizard-zone content) all
showed `error: Cannot #include globals.h` cascading into
`Undefined variable`/`syntax error` noise for macros like `NPC`/`SWORD`/
`ITEM` that `globals.h` itself defines. This matched the documented
§15o shape closely enough that `get_include_path()` was added to
`master.lpc` proactively (a correct, harmless improvement, kept in the
final code) — but **re-running the sweep after adding it changed
nothing** (still exactly 30 failures in that category). Direct A/B
testing (adding/removing the apply, `lpcc --batch` on the same file
list) confirmed the fix had zero effect on this specific cluster.

Further isolation testing revealed the real cause: compiling **any**
single file completely alone via `lpcc --batch` — including files
proven to load perfectly cleanly in a real driver boot, e.g.
`/d/city/wumiao` (one of the 4 actual player start rooms, exercised
directly by the interactive registration test below with zero errors)
— reliably FAILS the same way, while the exact same file passes when
compiled as part of the full ~10,641-file batch. This is a pure
artifact of `lpcc --batch`/a from-scratch VM session needing some
amount of "warm-up" compiling before certain inherit chains resolve
correctly when tested against a near-empty file list — not a real bug,
and not specific to the wizard-zone files (confirmed by reproducing it
on an unrelated, known-good start room). Matches AGENTS.md §6b's
guidance exactly ("verify against the real full-driver boot log before
trusting an lpcc-only failure... if grep for the error string comes up
empty in an actual driver boot log, it's a sweep artifact"): `grep`ping
`log/debug.log` from both real interactive sessions for `wumiao`,
`kedian`, `yandang`, or any `Cannot #include` string returns nothing but
clean compile-note lines, confirming these 30 (and likely a good
fraction of the other 335 no-error-message "Fail to load object"
entries — see lpcc pass-rate section below) are sweep-only noise, not
live bugs. `get_include_path()` was kept anyway since it's a correct,
free improvement per the documented pattern, just not the fix for this
particular cluster.

## Registration-flow verification (the critical check)

Read `adm/daemons/logind.lpc`'s full callback chain
(`logon → get_id → confirm_id → get_name/get_resp → new_password →
confirm_password → select_gift/set_gift → get_gift → get_email →
get_gender → init_new_player/enter_world`) before scripting the test.
No hidden pre-id BIG5/student/client-version gate in this lib — the
very first prompt ("请输入您的英文名字：") really is `get_id`, gated only
by `check_legal_id()` (3-14 lowercase English letters) and a
`banned_id`/`"guest"` substring check.

**Test 1** — `python3 scripts/mudclient.py 127.0.0.1 40049 --timeout 25
--idle 2 --send "qinfeng" --send "y" --send "秦风" --send "test1234"
--send "test1234" --send "0" --send "y" --send "test@test.com" --send "m"
--send "look" --send "quit"`:
- `qinfeng` accepted as a new id → confirm prompt → `y` → Chinese-name
  prompt.
- **Real Chinese name "秦风" accepted on the first try** (no rejection
  loop) → password prompts accepted → gift selection (`0`=random,
  `y`=accept) → email accepted → gender `m` accepted →
  `init_new_player`/`enter_world` ran → dropped into the actual game
  world ("客店" room, one of the 4 `start_room` entries) → chat channel
  broadcast confirmed: `听说又来了一位叫做秦风的小兄弟` (visible,
  correctly-rendered Chinese, proving `is_chinese`/`check_legal_name`'s
  fix works and the name round-trips correctly through
  storage/display). `look` and `quit` both worked normally (`quit`
  dropped the starting cloth item and printed the standard farewell).

Then applied the remaining fixes (get_include_path, message_combatd,
panguanbi, feng.h, the 6 missing-quote files) — since LPC objects don't
recompile just from editing the file on disk, **restarted the driver
process** and re-ran a **second, independent** full registration test
with a different name to confirm nothing regressed:

**Test 2** — same script, `--send "linfeng"` / `--send "林风"`
(different id and Chinese name, to avoid the first test's now-existing
save file): accepted through the identical full chain, landed in a
**different** start room this time (`random(4)` picked "北疆小镇" /
"Northern Frontier Town", `/d/xingxiu/beijiang`) confirming the
`start_room` random-pick logic itself works, saw the correct channel
broadcast (`听说又来了一位叫做林风的少年侠士`), `look`/`quit` both
worked. `debug.log` for both sessions greps clean for
`error`/`Undefined function`/`Read access denied`/`Bad argument`/
`segmentation` (only benign config-echo lines and the pre-existing,
intentional `log_error()`-to-player mechanism that surfaces harmless
`Unknown #pragma, ignored` compile warnings live to whoever triggers a
lazy compile — original mudlib behavior, not a bug introduced here).

Both driver processes were killed after their respective tests; no
driver process is left running on port 40049.

## lpcc_check.sh sweep

10,641 files total. Ran 4 times as fixes were discovered (each re-run
confirmed via `free -h`/a memory-watching background monitor that this
mid-sized lib never came close to the host's 23GB capacity — peak
usage stayed well under half of available RAM throughout, no need to
abort per §6b):

| Pass | Result |
|---|---|
| 1 (pre-fix) | 10138 / 10641 = 95.3% |
| 2 (+ get_include_path, panguanbi) | 10139 / 10641 (get_include_path fix confirmed NOT the cause of the big cluster — see investigation above) |
| 3 (+ message_combatd, feng.h×4, 5 missing-quote fixes) | 10151 / 10641 |
| 4 (+ 1 more duplicate missing-quote file found post-sweep) | **10152 / 10641 = 95.4%** (final) |

Triage of the remaining 489 failures (categorized by error text, per
AGENTS.md §6b):
- **365 of 489 (75%)** have **no error message at all** — just a bare
  "Fail to load object". Directly confirmed via reproduction (see the
  get_include_path investigation above) that this category includes
  known-good, real-boot-verified files (`/d/city/wumiao`) failing purely
  because of how few files are in that particular `lpcc --batch`
  invocation — a sweep artifact, not a real defect. Not chased further
  file-by-file given the direct proof this class is not a live bug.
- **30 files** (`Cannot #include globals.h`, all under
  `u/snow/wudujiao/`/`u/fyue/` personal wizard-zone content) — same
  artifact category as above, all confirmed clean in real boot's
  `debug.log`.
- **~10 files**: genuinely missing macros/base classes with zero
  definition anywhere in the whole archive (§13-style content gap, not
  fabricated): `RAKE`, `SSERVER`, `ARCHERY`, `YIZHAN`, `KZZNPC`,
  `NPC_TRAINEE` (weapon/NPC base-class inherits, `d/obj/weapon/rake/*`,
  `d/obj/weapon/archery/*`, etc), and `guanli.h`/`npc.h`/`npcneed.h`
  (missing headers, `d/kaifeng/{east,backup/east}.lpc`,
  `cmds/{std,usr}/yaoqing.lpc`) — none on the preload/registration path.
- **~9 files** (`meskill/skill_model_{default,weapon,unarmed}.lpc` +
  their 2 callers `cmds/{bakcmds/meskills,skill/meskills,bakcmds/csc}.lpc`):
  confirmed these are **code TEMPLATES** read as plain text and
  macro-substituted by an in-game skill-authoring tool
  (`SKILL_BASE_NAME`/`SKILL_CH_NAME`/`SKILL_EN_NAME`/`action` are never
  `#define`d anywhere — by design, they're meant to be filled in by the
  generator, not compiled directly) — the exact "fragment file not
  meant to be a standalone compile unit" false-positive shape from §6b,
  just via text-templating instead of `#include`.
  `NewRandom` (4 more "Undefined variable" hits) is a real function
  (`inherit/skill/skill.lpc:110`), just unavailable to files that don't
  inherit that skill base when compiled standalone — same context-
  artifact shape.
- **`db_affected`** (3 files, all `adm/daemons/databased.lpc` — a
  daemon whose preload entry is **already commented out in the raw,
  unmodified archive**, i.e. never loaded in real play): matches
  AGENTS.md §15b's documented gap exactly, but left unfixed since the
  daemon isn't reachable in normal operation anyway and isn't part of
  registration/boot.
- **`exert_function(10)`** (2 files, `d/city2/npc/wizer.lpc` and
  `d/player/ltsh/npc/saveme.lpc`, likely clones of each other): a
  genuine pre-existing content bug — `exert_function` (defined in
  `inherit/char/npc.lpc`) expects a **string** skill-name argument
  (every other of the ~100+ call sites in this lib passes one, e.g.
  `"recover"`/`"powerup"`), but these two pass a bare int `10` with no
  surrounding context suggesting what string was intended. Left
  unfixed (fabricating a guessed skill name would be inventing content,
  not fixing a diagnosable bug) — both are decorative/minor NPC files,
  not on the registration path.
- **A handful of one-off pre-existing gaps** not investigated further
  given diminishing returns (`cmds/wiz/mapp.lpc`'s "Illegal to declare
  varargs variable", `d/board/mianju_b.lpc`/`d/objj/cloth/tianyi.lpc`'s
  "Unable to find the inherited function") — all non-critical admin/
  decorative content, not reachable from registration or the interactive
  test's actual path.

## Encoding

`convert_lib.sh`'s automated pass: 11,325 converted cleanly, 340
already-UTF-8, 62 lossy (invalid bytes dropped — mostly NPC/room files
under `d/shushan/npc/`, `d/quanzhen*/obj/bookshelf.c`, and a few
`.bek`/map/log data files), 6 skipped as genuinely binary. Re-ran the
AGENTS.md straggler check (`file -b` not reporting text/script/empty
for any `.lpc`/`.h`) afterward: only one false-positive hit
(`d/emei/shenshuige.lpc`, a short room file that `file`'s heuristic
misclassified as "data" despite being valid, clean UTF-8 — verified by
hand, no action needed).

## Config

`config.fluffos` adapted from `wmkjlib/config.jh` (labeled "MudOS
0.9.20"). Original `port number : 6666` replaced with **40049** (this
project's port assignment for archive #55, per TODO.md's sequential
scheme after 40046-40048 reserved for archives #52-54). `mudlib
directory` points at `libs/wmkj/work` (absolute path). All
other directives (`master file`, `simulated efun file`, `include
directories`, etc) carried over unchanged; standard modern-FluffOS
tuning knobs (`time to clean up`, `maximum evaluation cost`, etc) copied
from the same template used for the last several libs in this batch
(matches `xiakexing3`'s `config.fluffos` shape).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 10641 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 10534 written, 41 already
  idempotent-clean, 66 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦岭`/id `wmkjre`), reaching the actual starting room (`客店`),
  `look`/`score`/`quit` all producing correct output — no regressions
  from either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly, only benign compile-
  warning spam, zero fatal errors. Login is blocked by
  `adm/daemons/logind.lpc`'s `logon()`: `str = query_ip_number(ob); if
  (BAN_D->is_banned(str) == 1) { ...你的地址在本 MUD 不受欢迎...;
  destruct(ob); }` — this is exactly the documented known WASM-mode
  limitation (`query_ip_number()` not returning a real dotted-quad under
  `wasm_console_connect()`, causing `BAN_D`'s IP-ban parsing to
  misclassify the connection as banned). **Not a mudlib bug** — the
  identical code path already works correctly natively (confirmed
  above), and this driver-side WASM gap is documented in AGENTS.md's
  "Post-conversion tooling" section. Marking this lib as "boots under
  wasm, login gated by IP-check limitation" rather than "fails under
  wasm."

## WASM-enablement pass (loopback-allow / throttle exemption / admin seeding)

Gates found and patched (AGENTS.md §1.3b/§1.3e/§1.5):

- `adm/daemons/band.lpc` `is_banned()` — used to return 1 (BANNED) for
  any empty or non-dotted-quad ip, i.e. it rejected every WASM
  connection by design. Now short-circuits return 0 for loopback /
  "127."-prefix / empty / malformed ips before the old logic.
- `adm/daemons/band.lpc` `vaild_allow_address()` — per-user allowed-IP
  ACL now always passes for loopback/malformed ips.
- `adm/daemons/logind.lpc` `logon()` — the `ban_cnt > 16`
  connecting-from-same-IP throttle is now loopback-exempt.
- `adm/daemons/logind.lpc` `get_id()` — the `ip_cnt > 8` per-IP login
  cap is now skipped for loopback/malformed ips (band.lpc's `Netclubs`
  already whitelisted exact "127.0.0.1"; the guard now also covers the
  WASM malformed-ip shapes).

**Retrofitted fail-open → fail-closed (2026-07-24)**: the three
`band.lpc` spots (`is_banned()`, `vaild_allow_address()`) and the
`logind.lpc get_id()` per-IP login cap were all originally written so
that ANY malformed/non-string ip bypassed the gate, not just genuine
loopback — defensive against the old WASM driver bug where
`query_ip_number()` returned garbage for every WASM connection. That
driver bug is now fixed (WASM reports a clean `"127.0.0.1"` same as
native), so there is no remaining justification for "can't parse it" ⇒
"must be loopback". Changed:
  - `band.lpc is_banned()`: `!stringp(site) || site=="127.0.0.1" ||
    strsrch(site,"127.")==0 || sscanf(site,"%*d.%*d.%*d.%*d")!=4` (any
    unparseable site returns "not banned") → `stringp(site) &&
    (site=="127.0.0.1" || strsrch(site,"127.")==0)` for the bypass —
    a non-string site now falls through to the pre-existing `if
    (!site) return 1;`/sscanf-based logic below, same as the
    original pre-WASM code.
  - `band.lpc vaild_allow_address()`: same shape fix, plus an added
    `if (!stringp(vip)) return 0;` right after the loopback check (deny
    rather than crash on a non-string ip reaching the allow-list
    `regexp()` call below).
  - `logind.lpc get_id()`: the per-IP login-cap condition required
    `stringp(query_ip_number(ob))` to be true before the cap would even
    apply (`ip != "127.0.0.1" && stringp(ip) && strsrch(ip,"127.")!=0 &&
    wiz_level<2`) — so a non-string ip made the whole condition false
    and skipped the cap entirely. Introduced a `cur_ip`/`is_local_conn`
    pair computed once (`stringp(cur_ip) && (cur_ip=="127.0.0.1" ||
    strsrch(cur_ip,"127.")==0)`) and gated the cap on `!is_local_conn`
    instead — a non-string ip is no longer local, so the cap still
    applies to it.
- No `uptime()` startup gate exists in this lib (`mad_lock` is a manual
  wizlock, left alone). The 50-second quit-retention re-login delay and
  10-minute kickout penalty are game design — kept.

Pre-existing re-login bug found and fixed during this pass:
- `adm/daemons/logind.lpc` `enter_world()` — `ctime(login_ob->query("last_on"))`
  threw on every RE-login because the quit path saves `last_on` as an
  already-formatted STRING; the throw aborted enter_world before the
  room move, stranding the body in the void with every command dead
  (update/quit then crashed on `environment(me)`). Now formats via
  `intp() ? ctime(...) : ...`. (First-time registration was unaffected,
  which is why earlier passes never saw it.)

Admin account: id `fluffos`, password `Mud@2026`, name 浮浮, granted
`(boss)` (same rank as the shipped `hfzz` admin; BOS_PATH command dirs)
via `adm/etc/wizlist`. Verified post-restart: re-login lands in 客店,
`update /adm/daemons/logind` → 成功, clean quit.

Save files for the orchestrator to force-add (untracked, not gitignored):
- `libs/wmkj/work/data/user/f/fluffos.o`
- `libs/wmkj/work/data/login/f/fluffos.o`

Retest: fresh registration (qinshiyi / 秦十一) end-to-end with
look/score/quit all correct; zero 执行时段错误 in both sessions;
test char removed (fluffos kept).

**Re-retest after the fail-closed retrofit (2026-07-24)**: fresh boot,
fresh registration (id `qretest`, real Chinese name 秦风九, talent `0`
then `y`) through `look`/`score`/`quit` — landed in a random starting
scene, `score` output correct, clean quit farewell. `fluffos`/`Mud@2026`
admin (`boss`) login re-verified: `look` then `update
/adm/daemons/logind` → `重新编译 /adm/daemons/logind.lpc：成功！`, then
clean `quit`. Zero `执行时段错误` lines in `debug.log` for the whole
session. Test char `qretest` removed afterward; fluffos kept.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

"夕阳再现"衍生引擎上的一款独立游戏。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，等级确认（"您目前权限：(boss)"），进入起始区域，quit 干净。记录了一处不阻断游戏的历史遗留美观性 bug（本轮未修）：某个房间的夜间氛围文字里有一处没有被替换掉的字面 '%s'。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40049）跑了一遍超出注册流程的完整游玩。这份档案
和 `bixiecanyang` 同属"夕阳再现"血统（同源 chinese.lpc/securityd.lpc
等工具文件），注册流程也高度相似：单组密码、天赋可选 1-4 项自定或
0=全随机、六项天赋（含福缘/容貌两项隐藏属性）、email、性别。

**主动检查命中 3 处，都在 `adm/daemons/logind.lpc`**：两处紧挨在
`ob->set("name", ...)` 之前的 `printf("%O\n", ob)` 调试残留（§7.34，
随机取名/手动取名两条平行路径各一处，和 `bixiecanyang` 逐字节相同
的形状）；`enter_world()` 里食物/饮水初始化用错对象的经典 §8.9
bug（`ob->query("age")` 应为 `user->query("age")`）。三处均已修
复；注册后食物/饮水显示 280/280（满值），确认 §8.9 修复生效。
`command_hook`（`feature/command.lpc`）是干净的 `nomask`，没有
`private`，不是 bug；没有 MESSAGE_D-> 未防护调用；全树 UTF-8 解码
扫描没有发现 extensionless GBK 文本残留（唯一的 6 个解码失败文件全
部确认是二进制可执行档、tar 归档或巫师私人调试日志，不是应该转码
的内容）；`feature/alias.lpc` 没有 `command("quit")`，不适用
§7.72 那类 flood-kick bug。

**注册与游玩**：注册测试角色，落在"铁枪庙"（随机起始点之一，另有
"客店""嘉兴南门"等），携带"法传送帖"道具。探索了客店（有间客栈）、
钱庄方向的南大街、当铺、天安门广场等区域，地图连通性正常。

**死亡系统：修复了标准的 §7.68，但同时发现并诚实记录了一个更深、
未能在本轮定位根因的独立异常**：`d/death/npc/{wgargoyle,bgargoyle}.lpc`
（只有 `wgargoyle.lpc` 真正生效，`DEATH_ROOM` 宏指向它所在的
`d/death/gate.lpc`；`bgargoyle.lpc` 未被任何房间引用，是死代码）
和 `d/shaolin/npc/yu-zu2.lpc`（同样是被 `yu-zu.lpc` 取代的死代码，
和 `jyqxc`/`syxjl`/`wmkj` 此前发现的同一个监狱机制 bug 一致）都有
标准的 `if (!ob || !present(ob)) return;` 复活软锁死守卫，已按已
验证的修法全部拆分修复。

**现场测试时发现**：死亡后被"四只乌鸦"或"小贩"这类极弱的 NPC 杀死
（战力 300 左右，说明测试角色初始战斗力极低，"攻击力：1"，几乎任
何 NPC 都能致命——这是内容/数值现象，不是 bug），落到"鬼门关"，
"白无常"在场。**用临时插入的 `tell_object` 调试探针逐行追踪**确认：
五阶段死亡对话在 §7.68 修复后能完整走完（`stage` 从 0 递增到 4，
每条 `death_msg` 文本都正确显示），`ob->reincarnate()` 也确认执行
成功（探针显示 `ghost=0`），但**紧接着的 `ob->move(REVIVE_ROOM)`
调用之后，连一条最简单、不涉及任何字符串拼接或返回值处理的
`tell_object` 探针都没有再显示过**——反复用不同测试角色、不同起始
房间复现了同样的结果：五段对话全部显示完毕后，角色仍然留在"鬼门
关"，只收到白无常的日常闲聊（`chat_msg`），从未真正传送到"武庙"。
`debug.log` 和 driver 自身的 stdout（`boot.log`）全程没有任何报
错，driver 进程本身也没有崩溃。追查了 `feature/move.lpc` 里
`move()` 自己的"如果身上有装备就先卸下"逻辑（`if (query("equipped")
&& !this_object()->unequip()) return notify_fail(...)`，怀疑
`notify_fail()` 在没有活跃玩家指令的 call_out 语境下可能返回一个
让调用方误判的值）、`reincarnate()` 内部 `UPDATE_D->check_user()`
的 `is_ghost()` 时序等几个假设，但在本轮的时间预算内未能定位到确
切根因就没有继续深挖，也没有做任何"猜测性"修复——**诚实记录为一
个新发现、尚未解决的独立异常，不是 §7.68 那个已经验证过的 bug
类，也没有被本次的 §7.68 修复引入**（§7.68 修复本身已经证明是正
确的：如果没有这个修复，五阶段对话根本不可能完整走完）。已将调试
探针代码全部还原，不带任何调试残留提交。建议下一次有余力时，从
`feature/move.lpc` 的 `move()` 全函数体（不只是 equip 检查那一段）
逐行插桩来精确定位。

`quit` 正常退出，driver 全程存活未崩溃。`debug.log` 全程没有真实
的 `error:`/`denied`/`Bad argument`/`Too deep recursion` 行。
formatter 检查（改动文件均已是干净格式或首次接触触发全文件重排
版，语义改动已逐一核对）、`git status --short libs/wmkj/` 复查均
确认改动范围干净——四处源码修改是跟踪变更，测试角色的新存档保持未
跟踪、未提交。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 142 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。`log_error()`（`adm/obj/master.lpc`）已经在更早一
轮正确修复过，管理员账号（`fluffos`/`Mud@2026`，`adm/etc/wizlist`
已有 `fluffos (boss)`）此前的存档也已经**真正可用**——`feature/
dbase.lpc` 检查确认这份档案**不属于** `tybxjh`/`wlhd` 那个"天涯"
血统，没有那条会拦截首次密码设置的防劫持保护，存档文件里
`password` 字段本身就有正确的哈希值，直接登录 + `update` 验证全部
一次通过。本轮只发现并修复了 `log_file()` 一处。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`adm/daemons/
   logind.lpc` 的 `get_gender()`（新角色注册流程的最后一步）紧跟
   着调用 `log_file("login/newid.log", ...)`。已补上
   `assure_file(LOG_DIR + file);`（含前向声明）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数。
- `feature/dbase.lpc` 确认没有 `tybxjh`/`wlhd` 那条
  `wizhood(id)=="(admin)"` 密码防劫持保护的 bug 形状——不适用本轮
  新增的这一类检查。

### 实测过程

用已提交的 `fluffos`/`Mud@2026` 直接登录（本代码线无双密码机制，
只有一个普通密码），断线重连（"重新连线完毕"）+ `update
/adm/simul_efun/file`（就是本轮改过的文件，"重新编译...成功！"）
均一次通过验证。

### 发现但未修复：多条 debug.log 记录，均为既有游戏内容问题（世界
   模拟背景活动，和注册/登录/管理员流程无关）

登录测试期间 `log/debug.log` 新增了不少条目，追查后确认全部是背景
世界模拟活动触发的既有内容问题，和本轮任何改动都无关：
`adm/daemons/feizeid.lpc`（飞贼精灵）的 `choose_npc()` 传了一个
`int(0)` 给 `call_other()`；某个帮会房间 `inherit` 了一个不存在的
文件 `/u/xiha/banghui/bhnpc`；两处 NPC `create()` 里 `set_skill()`
引用了并不存在的技能名（`kuang-jian`/`feitian-yujianliu`）。这些都
是纯内容/数据层面的既有问题，按项目惯例不在本轮 §10.7 标准检查范
围内展开修复，如实记录。`log/debug.log` 里没有任何和
`log_error()`/`log_file()`/注册/登录路径相关的条目。驱动最终按精
确 PID kill，`ps -p` 确认已退出。

### 已清理

- 登录测试产生的存档时间戳类微小 diff 已用 `git checkout` 撤销，不
  提交。

## 后续处理（2026-08-13）：上面三项被记录为"世界内容问题、暂不修复"的发现，逐一深挖并按可行程度修复

用户明确要求把上面标记为"内容层面既有问题、本轮不修"的三项拿回来
实际修：`feizeid.lpc` 的 `call_other(0,...)`、缺失的
`/u/xiha/banghui/bhnpc`、以及 `kuang-jian`/`feitian-yujianliu` 两个
不存在的技能名。三项各自的根因、范围比原始记录深很多，逐一说明：

1. **`adm/daemons/feizeid.lpc`（飞贼精灵）—— 已修复。** 根因：
   `choose_npc()` 第 44 行 `newob = new("/u/xiha/npc/" + feizei[...]);`
   ——`/u/xiha/npc/` 整个目录在 `work/` 和 `raw/` 里都完全不存在（不
   是某几个文件缺失，是这个 12 个飞贼 NPC 的目录从来没进过这份归
   档），所以 `new()` **每次**都回传 `0`，紧接着的
   `newob->set(...)` 就是对 `int(0)` 的 `call_other`——这正是
   AGENTS.md §7.63/§7.73 的标准形状。由于飞贼精灵的 `call_out`
   周期是 320 秒且从 `create()` 就排上，这个 crash 在驱动运行期间
   持续、周期性发生，不是偶发。修复：`new()` 后立即判空，`return`
   之前重排下一次 `call_out`，不吞掉整个报错循环：
   ```lpc
   newob = new("/u/xiha/npc/" + feizei[random(sizeof(feizei))]);
   if (!newob) {
     remove_call_out("choose_npc");
     call_out("choose_npc", 320);
     return;
   }
   ```
   验证：`update /adm/daemons/feizeid` 编译干净；驱动运行期间不再
   出现相关报错（此前 `debug.log` 会每 320 秒新增一条）。

2. **`/u/xiha/banghui/bhnpc`（以及同目录下的 `banghui.lpc`/
   `vendor.lpc`）—— 无法恢复原内容，已改为让崩溃不再发生。**
   `include/globals.h` 里 `BHNPC`/`F_BH`/`F_BVENDOR` 三个宏都指向
   `/u/xiha/banghui/` 下的文件；这整个目录在 `work/` 和归档原始的
   `raw/wmkjlib/world/u/` 里都不存在（`u/` 下只有 `fyue`、`snow`、
   `workroom.c`，从来没有过 `xiha`）——这份归档本身的说明文件就写
   明作者的 ID 正是 "xiha"，所以这是这份 2001 年"离线备份"归档在
   打包时就已经缺失的作者个人目录，不是转换流程的问题，也没有任何
   同名/近似的候选文件可以恢复（§7.94 式判断：不是"选哪份候选"的
   内容判断，是彻底找不到）。按项目惯例不编造替代内容。真正会崩溃
   的不是那 28 个直接 `inherit BHNPC` 的 NPC 文件本身（它们只是编
   译失败，不会产生游戏内容之外的连带崩溃）——而是
   `inherit/room/room.lpc`（几乎所有房间的公共基类）的
   `make_inventory()`：
   ```lpc
   ob = new(file);
   ob->move(this_object());   // new() 对编译失败的文件回传 0，这里是 call_other(0,...)
   ```
   以及 `reset()` 里同一个模式的两处调用点（`case 1` 单件、
   `default` 多件分支）。凡是房间的 `"objects"` 表里放了这 28 个
   NPC 之一，`reset()`（包括 `natured.lpc` 的日夜事件、NPC
   `random_move()` 换房间触发的目标房间 `reset()`，两条路径实测都
   命中过）就会在 `make_inventory()` 里对 `0` 做 `call_other`。修
   复：给 `make_inventory()` 的 `new()` 结果判空，`reset()` 两处调
   用点在使用前也判空——这是修复"房间生成逻辑"本身，不是编造缺失
   的帮会内容，28 个 NPC 依然会因为找不到 `bhnpc` 编译失败（这点
   没变、也不可能变），只是不再把这个失败向上传播成整栋房间的
   crash。验证：实测触发过两条不同路径（`/d/city3/guangchang` 经
   `natured.lpc` 的清晨事件、`/d/city3/xijie2` 经 NPC 游走进房间触
   发的 `reset()`），`debug.log` 里两次都只留下预期中的"继承文件不
   存在"记录，driver 全程存活，没有级联报错。

3. **`kuang-jian`（有正确技能实现，只是放错目录，已修复）和
   `feitian-yujianliu`（连同同一批彻底缺失的 14 个"飞天"专属技
   能，无法恢复，已加保护）—— 两者根因完全不同，分开处理。**

   - **`kuang-jian`**：不是缺失内容，是**放错了目录**。
     `quest/weiguo/xixiabing/kuang-jian.lpc`（以及配套的
     `kuang-jian/kuang.lpc`、`kuang-jian/leitingpili.lpc` 招式文
     件）本身是一份完整、可用的 `SKILL` 类实现（"狂风快剑"），`raw/`
     归档里就已经放在这个任务目录下，从来没在
     `kungfu/skill/`（`feature/skill.lpc` 的 `SKILL_D()` 宏硬编码
     指向的技能查找目录，`learn`/`practice`/`perform`/`chkskill`
     等**所有**技能相关指令都走这个宏）出现过——所以哪怕
     `set_skill()` 的存在性检查侥幸通过，`perform_action()` 也永
     远解析不到招式文件。这不是"选哪个候选实现"的内容判断（本作者
     只写了这一份实现，没有竞争版本），是把已确认正确的文件挪到引
     擎唯一认可的位置，对应 AGENTS.md §7.94 的"用归档里已证明正确
     的内容补回缺失文件名"这类判断。用 `git mv` 把三个文件整体搬到
     `kungfu/skill/kuang-jian.lpc` + `kungfu/skill/kuang-jian/`（保
     持 `__DIR__` 相对招式文件路径不变，`perform_action_file()` 不
     用改）。验证：`update` 三份文件、以及 4 个引用它的
     `quest/weiguo/xixiabing/xixia{1..4}.lpc` 全部编译成功；现场
     `clone` 了一个 `xixia1` 西夏兵实测，`set_skill("kuang-jian",..)`
     不再报错，且在真实战斗里触发了"雷霆霹雳"/风系剑招的战斗文本
     （证实 `perform_action()` → `SKILL_D("kuang-jian")` →
     `perform_action_file()` 整条链路已经生效，不只是编译通过）。

   - **`feitian-yujianliu`**：深挖后发现原始记录的"两处 NPC"严重低
     估了范围——`d/feitian/`（"飞天御剑流"门派区域，绯村剑心/比古
     清十郎等 NPC）整个技能体系一共引用了 **15 个** `kungfu/skill/`
     下完全不存在的技能名（`feitian-yujianliu`、`wuxing-dun`、
     `shayi-xinfa`、`shayi`、`aikido`、`bearart`、
     `xuanhualiu-quanfa`、`edge`、`huoxinliu-jianfa` 等），分布在
     **11 个 NPC 文件**（`biguqing`/`jianxin`/`qingyun`/`axun`/
     `miyan`/`dizi`/`luo`/`luoren`/`shiren`/`xunjing`/`zuo`）里，
     `raw/` 归档同样完全没有——是这整片"飞天"（其实是新选组／绯村
     剑心题材）门派区域自带的一整套自定义技能树，连同 `xiha` 的个
     人目录一起，从归档诞生起就没有实现文件。`feature/skill.lpc`
     的 `set_skill()`/`map_skill()` 对不存在的技能名是故意
     `error()`（这是这份代码库统一、正确的校验逻辑，其它调用点用
     的都是真实存在的技能，不能因为这三个区域性文件就改
     `feature/skill.lpc` 本身），而这些 NPC 的 `create()` 里，缺失
     技能的 `set_skill()`/`map_skill()` 调用夹在正常技能中间——一
     旦抛错，`create()` 当场中断，后面的 `create_family()`（帮派注
     册）、`setup()`、穿装备统统执行不到，等于这整个门派的掌门/长
     老 NPC 从未正常初始化过。既不编造这 15 个技能的具体实现（属于
     游戏设计/平衡工作，超出本项目范围），也不能改
     `feature/skill.lpc` 的校验语义，所以修复落在调用点：给这 15
     个引用（`set_skill()` 及唯一一处第一参数就是缺失技能名的
     `map_skill("edge", "feitian-yujianliu")`）逐一套上
     `catch(...)`，让 `create()` 能跳过这一句继续往下执行——这些
     NPC 该有的技能数值就是少了几项（本来就从未真正生效过），但至
     少角色本身、帮派注册、装备穿戴这些不该被牵连的初始化逻辑都恢
     复正常。验证：对全部 11 个文件逐一 `update`，`debug.log`
     显示每一处缺失技能都变成"错误讯息被拦截"（`catch()` 生效）后
     紧跟"成功！"（`create()` 完整跑完），不再有任何未捕获的
     `F_SKILL: No such skill` 中断 `create()`。

   顺带在同一次测试中发现一个**范围外**的同类实例：
   `d/lingxiao/npc/wang.lpc` 引用了同样不存在的技能 `xueshan-sword`
   （`baoshid.lpc` 的 `choose_baosi()`/`random_place()` 触发），未
   修——不属于本轮明确要处理的 `kuang-jian`/`feitian-yujianliu`
   范围，留给下一轮处理。

### 验证方式（本次三项修复共用）

原生 driver（端口 40049）重新起过一轮，用 `fluffos`/`Mud@2026`
（`(boss)`）登录后对全部改动文件逐一 `update` 确认编译/`create()`
干净；另注册了一个全新测试角色（`wmkjqatest`/中文名"秦风测"）走完
整个注册流程直达游戏世界，`score` 输出正确，`quit` 后等满 50 秒冷
却、用同一账号密码重新连线，成功恢复到退出前所在房间（断线重连闭
环）。驱动最终按精确 PID `kill`，`ps -p` 确认已退出。测试产生的
`fluffos` 存档时间戳类微小 diff 已 `git checkout` 撤销；新注册的
`wmkjqatest` 测试存档文件（未追踪）已删除，未提交。
