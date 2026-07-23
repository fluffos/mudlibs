# tiexuejianghu — 铁血江湖 (Tie Xue Jiang Hu / "Bloody Jianghu")

Archive: `archives/铁血江湖.rar` (archive #95). Extracted mudlib root:
`raw/txjh/export/mudlib/` (the archive nests `txjh/export/mudlib/` — a
`config.cfg` sits at `raw/txjh/`, one level above the `export/` dir it
points into). Port: **40087**. Status: **done** (boots clean, full
registration flow verified three times with real Chinese names, post-login
`look`/`score` verified working every time, zero runtime errors in
`debug.log` across all sessions).

## What this is / lineage

The raw `config.cfg`'s own `name` field (GBK-decoded) is `风云三（本地）`
("Fengyun III (local)") — a stale copy-paste leftover unrelated to this
game, the same pattern already seen on `datangshuanglong` (archive
#71-ish). `raw/txjh/readme.txt` (by the original author, "hxsd") and
`raw/txjh/小熊泥苑.txt` (the "小熊泥苑"/Xiongxiong-Niyuan mud-resource site's
own re-packaging note) both independently confirm the real game is
**铁血江湖** ("Tie Xue Jiang Hu"): a guild-focused wuxia mud with an
unusually developed NPC-recruitment/guild-income system and a full
merchant/trade subsystem ("和大航海时代差不多" — "similar to Uncharted
Waters/Age of Discovery"). The readme states the original server shut down
due to low player counts and internal wiz-team conflict, and the archive
was released publicly afterward. `config.fluffos`'s `name` field here is
set to `铁血江湖`, not the stale `风云三（本地）` value.

`adm/obj/master.lpc`'s own header comment says `"for ES II mudlib,
original from Lil, rewritten by Annihilator (11/07/94)"` — this is the
same "ES II" (Eastern Stories II) lineage shared by the large majority of
already-processed archives (shanhaizhanshen, wuhanzhan, huoying,
yueyingqiyuan, haiyang2, yanhuangwuhun, etc.) — directory layout
(`adm/`, `feature/`, `std/`, `obj/`, `cmds/`, `d/`, `u/`), `securityd.lpc`'s
ACL shape, and `feature/dbase.lpc`'s real (non-simul_efun) `set`/`query`
implementation all match that family, NOT the "nitan"/Lonely lineage
(§15's `dbase` architecture bug doesn't apply here) and NOT the
TMI-2/ES2/Falcon "XO" lineage. Did not force a match to any specific
already-shipped sibling archive — no byte-identical core files were found
against the handful of siblings spot-checked (`master.lpc`,
`chinese.lpc`) — this looks like a genuinely distinct ES II-derived
codebase, not a rebrand of one already in the project.

## Fixes applied (with why)

### §15h — `is_chinese()` GBK byte-range check (`adm/simul_efun/chinese.lpc`)
Was `strlen(str)>=2 && str[0] > 160 && str[0] < 255` (a GBK lead-byte
range check assuming byte-indexed strings). On this driver `str[i]` is a
Unicode codepoint and `strlen()` counts characters. Fixed to
`strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff` (CJK Unified
Ideographs range, `>=1` since one character is now one index). Without
this, no real Chinese name could ever pass registration.

### §15h — `check_legal_name()` bound + sliding-window (`adm/daemons/logind.lpc`)
Same file also implements the name-length/window checks directly (no
separate `named.lpc` in this lib). Byte-length bound `strlen(name) < 4 ||
> 8` (2–4 GBK chars) halved to `< 2 || > 4` (character count). The
`i%2==0 && !is_chinese(name[i..<0])` sliding-window guard (was landing on
alternating *byte* offsets to catch each GBK character's lead byte) had
the `i%2==0 &&` dropped entirely, since every index is already one
character now.

### §15ae — `private nomask` command-hook (`feature/command.lpc`)
`command_hook(string arg)` was declared `private nomask` and dispatched
via `add_action("command_hook", "", 1)` in `enable_player()`. This driver
treats `private` as hidden from `add_action`'s external dispatch (unlike
the original target driver), so every post-login command would have
silently done nothing with zero error anywhere. Dropped `private`, kept
`nomask`. **Checked and confirmed present exactly as documented in the
catalog** — this lib would have failed the exact same silent-command
symptom as `xuanjianlu`/`beimeixiakexing2001`/`bxsj`/`bxsj1`/`xiakexing3`
had this not been caught proactively before first boot.

### §15ar-adjacent — checked, NOT needed (worth documenting explicitly)
There is no separate `commandd.lpc`-style command-directory indexer in
this lib matching the catalog's exact `sscanf(name+"$", "%s.c$", name)`
shape — `adm/daemons/cmd_d.lpc`'s `rehash()` uses
`sscanf(cmds[i], "%s.c", cmds[i])` (a quoted string ending in `.c"`,
**not** `.c$"`), so `convert_lib.sh`'s standard quoted-`".c"`-reference
fixer (§2) already turned it into `"%s.lpc"` automatically during the
mechanical conversion pass — confirmed by reading `cmd_d.lpc` post-convert
and re-testing `look`/`score` end-to-end. Documenting this because it's
the same *category* of bug as §15ar but this lib's specific text shape
happened to be inside the standard fixer's blast radius, unlike
`jinyongwenzi`'s `%s.c$` shape which needed a manual fix. Worth
double-checking on every future lib: same underlying pattern, but only
sometimes auto-fixed depending on the exact quoting.

### §15p — excluded `dns_master` from preload (`adm/etc/preload`)
Standing policy, applied proactively before first boot.

### Non-standard: excluded `ftpd` from preload too (`adm/etc/preload`)
`adm/daemons/ftpd.lpc` (preloaded in the raw archive) `#include <flock.h>`,
which does not exist anywhere in this archive (only `<net/ftpd.h>`,
`<net/ftpdconf.h>`, `<net/ftpdsupp.h>` exist) — `FLOCK_D` isn't even
`#define`d anywhere either, confirming the whole file-locking subsystem
this daemon depends on was never actually wired up in this specific
archive (present as real files in `es1_win`/`esI`, absent here). Since
`ftpd` would be a fatal preload-time compile error and nothing in the
core registration/gameplay path (`master`/`securityd`/`logind`/
`simul_efun`/`command`/`chinesed`) references `FTPD_D`, excluded it from
preload — the same "trim non-essential network daemon" treatment §15p
already applies to `dns_master`. Confirmed via `lpcc` that
`adm/obj/master` (which pulls in the whole real preload chain) compiles
clean with `ftpd` excluded.

### §14 — `valid_override()` 3-arg upgrade (`adm/obj/master.lpc`)
Added the `main_file` 3rd parameter and check, cheap/free fix per the
catalog, applied proactively. As documented, never actually observed to
matter on a real boot here either (only would affect an `lpcc`-standalone
compile of an `#include`d simul_efun fragment).

### §8g — one shared root cause spanning many "Undefined variable"/syntax errors (`include/armor.h`, `include/globals.h`)
- `armor.h` had `TYPE_SURCOAT`/`TYPE_WAIST`/`TYPE_WRISTS`/`TYPE_SHIELD`
  AND their path-macro counterparts `SURCOAT`/`WAIST`/`WRISTS`/`SHIELD`
  all commented out (pre-existing in the raw archive, not conversion
  fallout) while `std/armor/{surcoat,waist,wrists,shield}.lpc` and
  `d/obj/inherit/armor/*` still referenced them unconditionally (8+16
  lpcc-sweep failures). Confirmed real callers exist (14/10/5/5 files
  respectively `inherit` the path macros) — uncommented all 8 defines.
- `globals.h` was simply missing `F_SSERVER` entirely (every ES II
  sibling lib in this project defines it, pointing at
  `/feature/sserver.lpc` — but THIS archive's real file lives at
  `/std/sserver.lpc` instead). Added `#define F_SSERVER
  "/std/sserver.lpc"` pointing at the file that actually exists here (16
  skill files `inherit F_SSERVER`).
- `std/skill.lpc` (the real target of the `SKILL` macro) was a genuinely
  **older revision** of `d/obj/inherit/skill/skill.lpc` — a byte-for-byte
  diff showed the `d/obj/inherit` copy has 25 extra lines (`sum()` +
  `NewRandom()`, a shaolin-wugong damage-roll helper) that were added
  later but never synced back to `std/skill.lpc`, the file the `SKILL`
  macro (and therefore every skill file) actually inherits. Ported the
  two missing functions into `std/skill.lpc` verbatim. Fixed 21
  `NewRandom`-undefined failures plus their cascading `Bad type of index`
  errors in one shot (all in `d/quanzhen/skill/*`, `d/chengdu/skill/*`,
  `d/heimuya/npc/obj/pixie-jian`, `daemon/skill/old/*`).

### §12-style orphaned non-LPC content (`d/sandboy/map.lpc`)
A pure box-drawing ASCII-art room map, not a single line of LPC, caught by
the blanket `.c`→`.lpc` rename. Confirmed nothing else references it
(`grep -rl` for the basename comes up empty besides itself). Renamed to
`.txt`.

### Missing-quote typo (`d/obj/books-nonskill/hmeng014.lpc`)
`string name = "《红楼梦》第十四回;` — missing closing `"` before the `;`,
confirmed present in the raw pre-conversion GBK bytes too (not a
conversion artifact). This desynced the parser for the rest of the file,
producing a cascading "unexpected L_NUMBER" + three "Illegal character"
errors on later, perfectly valid UTF-8 bytes. Added the missing quote.

### Malformed array literal, genuine pre-existing GB18030 corruption (3 copies of `gengfu.lpc`: `d/jinling/npc/`, `d/suzhou/npc/`, `d/suzhou/qinyun/npc/`)
`nosave string *sym_dee = ({ ...,"酉","","亥" });` (or `"酉",","亥"`
depending on which lossy-conversion pass) — the raw archive's GB18030
bytes for "戌" (5th of the 10 Earthly Branches, between 酉 and 亥) contain
a genuinely invalid byte sequence (confirmed: primary `iconv -f GB18030`
fails outright with "illegal input sequence" at that exact position on
all 3 raw copies), so `convert_lib.sh`'s `-c`-fallback lossy conversion
dropped it, per the Encoding section's documented "`iconv -c` can eat an
adjacent real byte too" gotcha. Restored the correct sequence
`"酉","戌","亥"` (the 10 Earthly Branches in their canonical order) by
inference from the surrounding array, not fabricated from nothing.

### §15t variant 3 — `inherit` after global-variable declarations (8 files)
`obj/mknpc.lpc`, `d/suzhou/obj/shoulei.lpc`, `d/suzhou/npc/guan_jia.lpc`,
`d/suzhou/npc/test.lpc`, `d/suzhou/npc/wutiande.lpc`, `u/oldsix/mknpc.lpc`,
`u/oldsix/hammer.lpc`, `u/oldsix/cloth.lpc` — all had a `mapping`/`string
*` global variable declared textually before their `inherit` statement,
fatal here ("Illegal to inherit after defining global variables") even
though the original target driver tolerated it. Reordered `inherit` to
precede the global declarations in every file (content unchanged
otherwise).

### Duplicate `inherit ROOM` from two rooms merged into one file (`u/xxy/shaolin/matou1.lpc`)
The file's own header comments read `// Room: /d/shaolin/matou1.c` AND
`// Room: /u/nangong/matou.c` — two genuinely different rooms (侠客岛码头
and 南码头) concatenated into one file, each with its own `inherit
ROOM;`/`create()`. Since only one object can ever be "live" at this one
path, and the file's own name matches the FIRST room (`matou1`), removed
the second, dead block (lines 151–178: the 南码头 definition) rather than
guess how to merge them. No `/u/nangong/matou` file exists anywhere else
in the archive, so this content was already unreachable dead weight
(the duplicate `inherit` was a hard compile error, meaning this second
room was never actually loadable even in a hypothetical original-driver
boot of this exact archive) — nothing playable was lost.

### `void` functions returning a value (3 files + 1 wrong-type return)
- `d/city2/npc/{guanfuzi,qianlaob,gaoyanch,xutianch}.lpc`'s
  `void recognize_apprentice(object ob)` all `return 1;`/
  `return notify_fail(...)` (an int). Changed all 4 to `int
  recognize_apprentice(...)`.
- `d/zhongzhou/midao.lpc`'s `void greeting(object ob)` had a `return 1;`
  mid-body (an early-exit idiom, return value unused by any caller found).
  Changed to `int greeting(object ob)`.
- `u/temp/liwu.lpc`'s `int accept_object(...)` had one branch
  `return "你有礼物了呀";` (a string, not int) — genuine type mismatch, not
  a declared-type issue. Changed to `write("你有礼物了呀"); return 0;`
  matching the message-then-return-int convention every other branch in
  the same function already uses.

### `std/weapon/gun.lpc` — bad inherit target + reused BLADE helper
`inherit GUN;` — `GUN` was never a `#define`d macro anywhere in this
archive (no sibling weapon-type path entry for it in `weapon.h` either),
and this is the only file in the whole lib referencing it. `create()`
calls `init_blade(25)` (a real function only `BLADE`
provides) confirming this "手提机枪" (submachine gun — an anachronistic
one-off item) was actually meant to `inherit BLADE`, reusing its damage
helper, not some fabricated `GUN` base. Fixed to `inherit BLADE;`.

### `#include` wrong absolute path, one wizard homedir cluster (8 files, `u/xxy/shaolin/bagua*.lpc`)
All 8 hardcoded `#include "/d/shaolin/bagua.h"`, but the file actually
lives at `/u/xxy/shaolin/bagua.h` (the header, and the function
`check_dirs()` it defines, were both effectively unreachable). Fixed the
absolute path in all 8 files — this single header also defines
`check_dirs()`, so it cleared that "Undefined function" category too in
the same pass.

### §8e — `tail()` is not a real efun (`cmds/app/tail.lpc`)
Same pattern as the catalog's own first documented case. Reimplemented
`do_tail_lpc()` in plain LPC (read_file + explode + slice + write),
defined **before** `main()` per §8b (a same-file forward call to a
not-yet-defined function fails "Undefined function" here, unlike some
looser old-driver targets).

## Confirmed NOT needed (checked proactively, found clean)

- **§4** (master's lazy `load_object(SECURITY_D)` inside `valid_read`/
  `valid_write` recursing to a stack overflow) — `master.lpc`'s
  `valid_write`/`valid_read` only use `find_object()`, never
  `load_object()`; `valid_read` unconditionally `return 1;` (very
  permissive, no daemon dependency for reads at all). No guard needed.
- **§7** (`get_root_uid()`/`get_bb_uid()` missing) — both already present
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c** (`valid_read`/`valid_write` clobbering caller identity with
  `this_player()`) — `securityd.lpc`'s `valid_write` uses the passed-in
  `user` argument directly throughout, no `this_player()` override at all;
  it doesn't even implement `valid_read` (master's own hard `return 1`
  handles all reads).
- **§15l** (master's `create()` destructing/reloading `SIMUL_EFUN_OB`) —
  `master.lpc create()` is a one-line `write()`, no destruct/reload dance.
- **§15n** (custom `securityd`'s `valid_read` ACL blocking the driver's own
  compile-time reads) — moot; master's `valid_read` is a hard `return 1`,
  never defers to `securityd` at all, so this specific gap can't occur
  here.
- **§15o** (missing `get_include_path()` breaking mid-connection
  `#include`s) — checked; no `<local.h>`-next-to-its-user `#include`
  pattern found anywhere in the lib (only genuine shared-directory
  headers like `include/net/*.h`, mostly for the excluded `ftpd`/network
  daemons anyway).
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`, `__OLD_ED__`) — grepped,
  zero hits anywhere in the lib.
- **§15ah** (missing save/log directories silently swallowing
  `write_file()`/`log_file()`) — `feature/save.lpc`'s `save()` calls
  `assure_file(file)` before `save_object()` (a real efun that creates
  missing parent directories), so the empty `data/user/`, `data/login/`
  (no per-letter shard subdirectories at all) never actually breaks
  anything — confirmed by a live registration + `save` actually
  succeeding. Every `log_file()` target directory referenced anywhere in
  the lib (`log/static/`, `log/wiz/`, etc.) already exists in the raw
  archive.
- **§15ai** (dns_master exclusion surfacing a `shutdown(1)` gate elsewhere)
  — grepped every `DNS_MASTER`/`dns_master` reference in the lib; all are
  confined to `adm/daemons/network/*` (the isolated, excluded intermud
  subsystem itself), nothing in `logind.lpc` or any registration-path file
  references it.
- **§15aj** (missing mandatory gift/first-room object) — `START_ROOM`
  (`/d/zhongzhou/yinghao`) exists and loads; `enter_world()` already
  guards the (rarely-used) custom-`startroom` path with
  `catch(load_object(startroom))` falling back to `START_ROOM`.
- **§15ak** (extensionless-file/`.c`-backup pairs silently promoting the
  wrong one) — found 9 such pairs (`cmds/std/bei`, `cmds/std/xiuxing`,
  `u/panguan/banned_sites`, `u/temp/100gold`, `d/mingjiao/{shanlu2,
  lhqpaifang,tomen1}`, `d/lingjiu/obj/jiudai`,
  `daemon/class/huashan/huashan-jianfa/feilong`). 6 pairs are byte-identical
  (no risk either way); the 3 that differ (`xiuxing`, `lhqpaifang`,
  `feilong`) all have a **newer** mtime on the `.c` side, meaning
  promoting the `.c`→`.lpc` copy (this driver's actual resolution order)
  picks up the more recent edit, not a stale backup — the opposite
  direction from the `zitengzhan` precedent, but the outcome is still
  correct. None of the 9 pairs are anywhere near the boot/registration/
  look/score path (personal wizard homedir + specific zone content only).
  Left as-is.
- **§15al** (`crypt(str, 0)` random-hash-every-call footgun) —
  `logind.lpc`'s `new_password()`/`confirm_password()` use `crypt(pass,0)`
  correctly for ordinary password storage (compute once at registration,
  compare later via `crypt(entered, stored_hash)`, which reuses the real
  salt embedded in `stored_hash`) — this is the standard, safe idiom, not
  the two-independent-`crypt(KEY,0)`-calls client-challenge shape that
  actually breaks on this driver. No client-challenge/handshake protocol
  exists in this lib at all.
- **§15am** (`file_size()==-1` treated as truthy) — grepped every bare
  `file_size(...)`-as-condition site; none found using it as a naked
  boolean without an explicit comparison.
- **§15an** (live-clock prompt defeating mudclient.py's idle pacing) — no
  live-updating clock/status in the prompt; used `--idle 0.6` throughout
  anyway as a safety margin, and the transcripts show clean 1:1 send/
  response pairing.
- **§15ao** (`switch` with only `default:`, no real `case`) — grepped the
  whole lib for the shape, zero hits; `master.lpc connect()` doesn't use
  `switch` at all.
- **§15ap** (`__FILE__` inside an `#include`d, not `inherit`ed, fragment)
  — no such usage found.
- **§15aq** (forward reference to a locally-overridden inherited function
  binding to the wrong body) — not encountered; the one forward-reference
  fix needed (`cmds/app/tail.lpc`'s `do_tail_lpc`) was the simpler §8b
  case (nothing else of that name existed to accidentally bind to).
- **§8f** (`TYPE * a, b;` losing the array modifier across a comma list) —
  grepped for the shape; the only near-matches
  (`feature/condition.lpc`'s `mixed *cnd, err;`,
  `adm/daemons/network/telnetd.lpc`'s `string *tmp, file;`) use `err`/
  `file` as genuinely scalar values in their bodies (not arrays), so this
  isn't the Dead-Souls-style bug — left as-is (and `telnetd.lpc` isn't
  even preloaded).
- **Uppercase `.C` files** — found and fixed 7 (`d/yangzhou/npc/*.C`),
  renamed to `.lpc`; confirmed no literal `.C"`-cased path references
  anywhere (the 4 room files that spawn these NPCs reference them via
  `__DIR__"npc/name"`, extensionless).
- **`static`→`nosave` false positives** — `convert_lib.sh`'s blanket sed
  hit 10 genuine `log_file("static/...", ...)` string-literal path
  references (the on-disk `log/static/` directory convention, same
  counterexample shape as `moniHuafu`/archive #57), turning them into
  `"nosave/..."`. Reverted all 10 back to `"static/"` across 8 files
  after the mechanical conversion pass, before any other edit.
- **§13-style content gaps, documented not fabricated**:
  - `F_UNIQUE` (51 files `inherit` it) — no `/feature/unique.lpc` exists
    anywhere in this archive at all (present in nearly every sibling ES
    II lib in this project, genuinely absent here). Left undefined/
    unfixed; these files won't compile, none are on any preload path.
  - `STICK`/`MACE`/`RAKE`/`BOW`/`ARCHERY` (weapon-type path macros, 17+11+4+1+1
    files) and `F_FIGHTER`/`F_CLOTH`/`DAEMON` (2+2+4 files) — none defined
    anywhere in `include/`, and (unlike the armor.h/F_SSERVER cases above)
    not simply commented out either — genuinely absent content, not a
    mechanical omission to restore.
  - `prepare_skill()` (33 files), `get_npc_data()`/`set_npc_data()` (12
    files) — called everywhere, defined nowhere in the whole archive (not
    even a stub). No sibling ES II lib in this project defines these
    either (checked), so nothing to port from. NPC-combat-setup and
    NPC-stat-persistence features this specific archive never shipped a
    working implementation for.
  - `daemon/skill/old/jiuyin-shengong.lpc`'s `::hit_ob(...)` (1 file) —
    `FORCE` (`std/force.lpc`) never defines a base `hit_ob`, so the `::`
    parent-call has nothing to reach. Isolated, single file.
  - `u/xxy/city2/npc/shenzhao.lpc`'s `#include "/kungfu/class/shaolin/hui.h"`
    (2 files) and `u/aug_old/{yapu1,thd/zhou_botong}.lpc`'s
    `#include "thd.h"`/`"npc.h"` — target files genuinely don't exist
    anywhere in the archive (unlike the `bagua.h` case, this isn't a
    wrong-path typo with the real file sitting elsewhere).
  - A long tail of smaller isolated one-off/few-file categories in the
    remaining `lpcc_fail.log` entries (`mud_name`, `set_encumbrance`,
    `member_group` — mostly unreachable `adm/daemons/network/*` files,
    `set_max_items`, `data_netmail_file`, a handful of "Bad assignment
    (mapping vs unknown)"/"syntax error" entries scattered across
    personal wizard homedirs `u/aug_old`, `u/xxy`, `u/panguan`, `u/temp`)
    — each affects 1-2 files, none on the boot/registration/gameplay
    path exercised by this pass's testing. Not investigated further per
    the project's stated "breadth over exhaustive depth" priority.

## Registration-flow + post-login-command transcripts

Three full end-to-end runs, each in ONE continuous `mudclient.py`
connection (`--idle 0.6`), across three different driver boots (to also
re-verify the emoted.o fix and the full set of source fixes together):

**Run 1** (after emoted.o fix, before the lpcc-sweep-driven content fixes):
`qinfg` → `y` → `秦风二` → `test123` (×2) → `qinfeng2@test.com` → `m` →
`look` → `score` → `quit`. Landed in `英豪酒楼`; `look` printed the real
room description twice (before/after an NPC "耳光" interaction event);
`score` printed `普通百姓 秦风二(Qinfg)`, correct stats/HP bars/food/water
gauges; `quit` gave the normal `档案正在存取中,三十秒后方能下线!` delayed-
quit message. Zero `执行时段错误` (runtime error) lines in `debug.log` for
this session.

**Run 2** (after ALL fixes above, fresh boot): `tiexue` → `y` → `秦风三` →
`test123` (×2) → `tiexue@test.com` → `m` → `look` → `score` → `quit`.
Landed in `英豪酒楼`; `look` ×2 correct; `score` printed `普通百姓
秦风三(Tiexue)`, correct stats; NPC "武大郎" random_chat fired (previously
the emoted-restore bug made this crash with `Bad argument 1 to keys()`
every ~heartbeat — now silent/clean); `quit` gave the normal delayed-quit
message. Zero runtime errors in `debug.log`.

**Run 3** (final re-verification after the very last two fixes —
`gun.lpc`/`tail.lpc` — neither on the registration path, run anyway for
completeness): `muyuan` → `y` → `秦风四` → `test123` (×2) →
`muyuan@test.com` → `f` (female, to also exercise the alternate
gender/clothing branch in `enter_world()`) → `look` → `score` → `quit`.
Landed in `英豪酒楼`; `look` ×2 correct; `score` printed `普通百姓
秦风四(Muyuan)`, 女性 (female), correct stats/gauges; `quit` gave the
normal delayed-quit message. **Zero `执行时段错误` lines in `debug.log`
for the entire session** (`grep -c` confirmed 0).

All three runs used a real Chinese given name (2–3 characters), confirming
the §15h `is_chinese`/`check_legal_name` fix works correctly end-to-end,
not just in isolation.

## lpcc_check.sh sweep results

Ran the full sweep three times as fixes progressed (9190-9191 `.lpc`
files, not a mega-lib, full sweep is the required gate per AGENTS.md):

- **Before any lpcc-driven fixes**: 8332/9191 pass (90.65%).
- **After the armor.h/F_SSERVER/skill.lpc/bagua-path/inherit-order/
  matou1/gengfu/hmeng014/recognize_apprentice/greeting/accept_object
  fixes**: 8449/9190 pass (91.96%) — file count dropped by 1 from the
  `d/sandboy/map.lpc`→`.txt` rename.
- **Final** (after `gun.lpc`/`tail.lpc`): a few more files pass but a
  full re-sweep wasn't re-run after these last two single-file fixes
  (each individually confirmed clean via direct `lpcc` on that exact
  path) — the 91.96% figure is the last full-sweep baseline; true final
  pass count is at least 8451/9190.

Remaining ~740 failures are dominated by the documented content gaps
above (`F_UNIQUE` alone accounts for ~51 files, `prepare_skill`/
`get_npc_data`/`set_npc_data` another ~56, the weapon-type/feature macros
another ~35), the known `#include`-fragment sweep-artifact category
(`_axe.lpc`/`_blade.lpc`/`_sword.lpc`/`_dagger.lpc`-style `#define
AS_FEATURE; #include "X.lpc"` files failing standalone with `Unable to
find the inherited function 'setup'` — confirmed via `grep` that this
exact error string never appears in the real boot's `debug.log`, matching
§6b's documented false-positive pattern exactly), and a long tail of
1-2-file isolated content issues in personal wizard homedirs, none on the
registration/gameplay path this pass tested.
