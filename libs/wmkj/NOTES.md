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
