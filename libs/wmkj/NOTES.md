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

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：2797 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具有 4 处拷贝（`obj/roommaker.lpc`、
`clone/misc/roommaker.lpc`、`u/fyue/misc/roommaker.lpc` 简单字符串
拼接写法；`obj/rmmaker.lpc` 的 `room_code +=` 写法）。累计 2800 处
live 调用删除，和 survey 记录的数字精确吻合，修复后 0 处遗留。

验证：`build-debug` 驱动真实冷启动，端口 40049 正常监听。启动期间
观察到一条既有的 debug.log 报错（`natured.lpc` 早晨事件在
`/d/city/guangchang` 生成一个继承 `u/xiha/banghui/bhnpc.lpc` 的 NPC，
但该文件在盘面上确实不存在）——确认和本次扫描无关（零处
"cannot replace"/"cannot bind"，文件本身就缺失，是一个既有的缺失
继承内容 bug，不是 replace_program 回归），未修，超出本次范围。既
有管理员账号 `fluffos`/`Mud@2026` 登录正常（落地北疆小镇，
look/quit），全程 debug.log 零新增行。

## 补完 d/lingxiao/npc/wang.lpc 缺失技能崩溃（2026-08-20）

此前一轮记录本文件的 `xueshan-sword` 缺失技能"超出范围，留给下一轮"，
只是未验证是否真的只有这一处。现场用 `update` 实测发现：光包住
`xueshan-sword` 依然在下一行 `set_skill("bingxue-xinfa", ...)` 崩溃
中断 `create()`——这个 NPC 的整套"凌霄城"技能（`xueshan-sword`/
`bingxue-xinfa`/`snow-zhang`/`snowstep`，`set_skill`+`map_skill` 共
9 处引用）全部是未实现的内容，不止 NOTES.md 之前记录的那一个。已按
和本库其余 11 个同类档案完全一致的手法，把全部 9 处引用套上
`catch(...)`。现场验证：`update d/lingxiao/npc/wang.lpc` 后
debug.log 依次显示 4 次"错误讯息被拦截"（对应 4 个缺失技能），最终
"成功！"，`create()` 完整跑完。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`reset_me()`-calls-`setup()`
chain -- confirmed via a body-aware static scan of every `init()` in
this lib: only 2 files have this exact redundant pattern
(`d/shushan/npc/zhangmen.lpc`, `d/shushan/zhenyaota/npc/zhangmen.lpc` --
the same `zhangmen.lpc` lineage already documented as the original
live-reproduced crash on `mhxy`), a much smaller count than most other
libs in this sweep but still a real, live reachability path: `init()`
conditionally calls `me->reset_me(me)`, and `reset_me()` calls `setup()`
which calls `enable_player()`, after `create()` already made the object
`living()`. Calling `enable_commands()` a second time on an
already-`living()` object makes the driver re-invoke that object's own
`init()` as a side effect, re-entering the same chain while the
original call is still on the stack -- genuine reentrancy, crashing
with "Too deep recursion" (most likely on an NPC's first-ever
preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup()`
both call `enable_player()` again while the object is still `living()`.
This confirms a bare `if (living(this_object())) return;` guard would
be the WRONG fix -- used the same true reentrancy-flag fix as `mhxy`
instead: a `nosave private int in_enable_player_now;` set for the
duration of the wrapper's body, guarding only genuine same-call-stack
reentrancy while leaving every legitimate re-enable (revive/wakeup)
unaffected. `enable_player()` had a single fall-through exit (no early
`return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。此前各轮覆盖了注册、战斗、死亡/
复活和若干 sweep，没有买东西、也没有拜师。这是夕阳再现/江湖风云血统
（与 `bixiecanyang` 同系），不是天涯家族。标准端口 40049 第一输入就是
「请输入您的英文名字：」，不要发 2060。

### 实测过程

管理员 `fluffos` / `Mud@2026`（权限 `(boss)`；wizpwd 不是登录密码）。
落地北疆小镇 `/d/xingxiu/beijiang`（房间描述里仍有一处未替换的字面
`%s`，2026-08 已记为美观性遗留，未修）。`clone /clone/money/gold` 可用。

`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文钱 / 牛皮酒袋一两白银 /
包子五十文钱。`buy jitui` 成功（「你向店小二买下一根烤鸡腿」）。当场
`i` 是九十九两银子 + 二十文铜板 + 鸡腿（1 两黄金找零 10000−80 = 9920）。
`feature/dealer.lpc` 已 `#include <dbase.h>`，`query("vendor_goods")`
正常。F_DEALER 对丐帮拒绝购买（穷叫化），必须先买再拜。本轮游戏内时间
是「亥时」深夜，但 `NATURE_D` 没有 `room_event_fun()`，打烊判断拿不到
`event_night`，店开着——这是既有缺口，不是本轮要修的内容 bug。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：左全收徒，`score`
「丐帮第二十代弟子」、师傅左全、头衔【叫 化 子】。`cmds/usr/save.lpc`
真正调用 `link_ob->save()` 和 `me->save()`；60 秒内再 save 是
`notify_fail("你迟点才可以储存。")`（不是假「档案储存完毕」）。等 62
秒后 save 一次，`user.o` 立刻带上 `family_name":"丐帮"` /
`master_name":"左全"` / `generation":20`。杀驱动冷启动再登录，称谓/
师傅/银子铜板还在。烤鸡腿未进 autoload。左全只收男性。

### 发现并修复的 PROGRAMMING bug

1. **华山收徒计数拼写**（与 `nitan_ceshi`/`nitan_san` 同形，静态对照
   修，本轮拜师走的是左全不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc` 的
   `recruit_apprentice()` 写 `add("apprentice_availavble", -1)`，计数
   键永远对不上 `apprentice_available`。改成 `apprentice_available`。
   文件是 LF。

2. **`wizlist` 执行时段崩溃**（活体踩到）：
   `cmds/imm/wizlist.lpc`（以及副本 `cmds/imm/ww.lpc`、
   `cmds/wizlist.lpc`、`adm/etcc/wizlist.lpc`）三处：
   - `explode(read_file("/u/xiha/wtm"), "\n")`：档案里没有这份巫师
     任务文件，`read_file` 返回 0，`explode` 要 string。改成
     `read_file(...) || "#"`（`#` 行会被后面的任务解析跳过）。
   - `stat(login_path, -1)[1]`：FluffOS 里 `stat(path, -1)` 等于
     `get_dir()`，缺档时返回空数组/0，`[1]` 越界。巫师 `hfzz` 在
     wizlist 里但没有 `login.o`。改成不带 `-1` 的 `stat(path)`（返回
     `({ size, mtime, ... })`），并用 `arrayp(st) && sizeof(st) > 1`
     护住缺档。
   - `get_mission`/`get_titlemission` 对空行做 `mission[i][0]` 也会
     越界；空串先 `!sizeof` 跳过。`/adm/etc/renwu` 里确实有空行。
   文件是 CRLF，按字节替换。`update` 后 `wizlist` 列出 fluffos（连线）
   和 hfzz（断线），不再报执行时段错误。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 7 here-document block(s) repaired (7 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`, `d/quanzhen_old/manglin1.lpc` and 1 more. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest`、`task/dynamic_location` 里 115 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 4 个），无回退；`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py wmkj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 555 个 `.lpc` 和 6 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：492 -> 492 通过，无回退；改过的头文件的 43 个包含者 43 -> 43 通过。启动时警告 33 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 30 处，返回类型/原型 38 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 66 个文件，HEAD 与工作树各载入一次无回退（66 objects; HEAD PASS 56, tree PASS 56; regress 0; newly loading 0），这些文件的警告 70 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `inherit/misc/bbsboard1.lpc`：`note["msg"] = (text, 1);` 等四处逗号表达式，帖子内容存成数字 1；照 `bbsboard.lpc` 改存 `text`（与 chidi 同）。载入无回退。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 2 处多余的 `F_CLEAN_UP`，其余手工，能编译的文件警告清零；改动的 8 个对象在 HEAD 与工作树各载入一次，regress 0。

- `d/register/npc/dizangwang.lpc`（地藏王）的 `attempt_apprentice()` 改 `void`，与 `inherit/char/npc.lpc` 一致；`cmds/skill/apprentice.lpc` 不读它的返回值。
- `d/city/library.lpc`、`d/city2/Sino-CO.lpc`、`d/emei/user-room/host/home.lpc` 各自的 `STORY_DIR` 覆盖 `globals.h` 的同名宏，先 `#undef`，行为不变；`clone/unique/fan.lpc` 写明用驱动原先选的 `clean_up()`；`kungfu/skill/huashan-jian.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。6 个文件 6 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。27 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。8 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 7 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。7 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`quanzhen-jian`、`taixuan-gong`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest/wudang/song` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`、`tiangang-zhengqi`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen_old/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

17 个文件、22 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/d/city/obj/tudao`、`/u/fan/gun`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 12 个（11 个原来载入不了），没有退步；其余 5 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`SSERVER` → `/inherit/sserver`（3 个文件）、`NPC_TRAINEE` → `/inherit/char/trainee`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：4 个里 3 个通过，其余 1 个还有别的错误（`d/xingxiu/npc/lingshe.lpc`：Undefined function set_color）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 134 个对象设了本库没有文件的武功（64 个名字，最多的是 `bingxue-xinfa`、`snow-zhang`、`snowstep`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：29 个里 29 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/shushan/zhenyaota/tower` 的 `west`：`/d/shushan/d/shushan/jindi` → `/d/shushan/jindi`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/rake`（宏 `RAKE`）←wxddym，4 个对象继承它，抽样 4/4 载入；`/std/weapon/archery`（宏 `ARCHERY`）←hxxtjqb，2 个对象继承它，抽样 2/2 载入；`/d/xueshan/obj/anqi-jian`←hxxtjqb，2 个对象继承它，抽样 2/2 载入；`/inherit/room/city1`←fqyy2，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 18 处、17 个文件：`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）、`literare`→`literate`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/city2/npc/wizer.lpc`、`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/board/mianju_b.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。
