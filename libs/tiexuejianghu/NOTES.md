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
game, the same pattern already seen on `dtsl2` (archive
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
already-processed archives (shzs, wuhanzhan, huoying,
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
symptom as `xuanjianlu`/`bmxkx2001`/`bxsj`/`bxsj1`/`xiakexing3`
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

## WASM-enablement pass (loopback-allow / admin seeding)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

### 1. Loopback always allowed — ban gate (`adm/daemons/logind.lpc:48-64`)
`logon()` unconditionally ran `BAN_D->is_banned(query_ip_name(ob))` /
`BAN_D->is_banned(query_ip_number(ob))` and `destruct`ed on a hit. Wrapped
the ban block so it only runs for a non-loopback remote address.

**Retrofitted fail-open → fail-closed (2026-07-24)**: the gate as
originally patched here ran the ban check only when
`stringp(ip) && ip != "127.0.0.1" && strsrch(ip, "127.") != 0 &&
sscanf(ip, "%*d.%*d.%*d.%*d") == 4` — i.e. it required the ip to
successfully parse as a well-formed dotted-quad before the ban check
would even run, so ANY malformed/unparseable ip silently skipped the
ban gate entirely (fail-open), not just genuine loopback. This was
written defensively against the old WASM driver bug where
`query_ip_number()` returned garbage for every WASM connection; that
driver bug is now fixed (WASM reports a clean `"127.0.0.1"` same as
native), so there is no remaining justification for treating "can't
parse it" as "must be loopback". Changed to fail-closed: `if
(!(stringp(ip) && (ip == "127.0.0.1" || strsrch(ip, "127.") == 0)))`
— only a real loopback-shaped string skips the ban check; anything
else, including an unparseable/non-string ip, now goes through the
normal ban logic same as any other remote connection.

### 2. Uptime startup gates — none present
No `uptime() < N` connection-rejection gate exists in this lib. The
`uptime()` hits are all in-game gambling rooms (`d/*/duchang*.lpc`,
`npc/douji`, `npc/saigui`) and the cosmetic `cmds/usr/uptime.lpc` /
`adm/daemons/network/cmwhod.lpc` uptime display — game content, left alone.

### 3. Anti-flood throttles — none present
No per-IP connection-rate / multi-login-per-IP / registration throttle in
`logind.lpc` (only a `MAX_USERS` cap and a `wiz_lock_level` gate, neither
IP-based). Nothing to exempt.

### 4. Admin account seeded — `fluffos` / `Mud@2026` / 浮浮
Registered through the real flow (id `fluffos` → `y` → 浮浮 → `Mud@2026`
×2 → email → `m`), landed in 英豪酒楼. Granted `(admin)` by appending
`fluffos (admin)` to `adm/etc/wizlist` (the file `securityd.lpc:82`
reads into `wiz_status`; `get_status`/`wizhood` return `(admin)`, which
`feature/command.lpc:90` maps to `ADM_PATH` + `enable_wizard()`).
Verified after reboot: login as fluffos, `update /adm/daemons/logind`
→ `重新编译 ... 成功`, `who4` wizard listing works.

**Save files for the orchestrator to force-add** (currently untracked,
NOT gitignored — a plain add works, listed for completeness):
- `libs/tiexuejianghu/work/data/user/f/fluffos.o`
- `libs/tiexuejianghu/work/data/login/f/fluffos.o`

Retest: fresh normal registration (秦十/qinshi) still reaches 英豪酒楼;
debug.log had 0 runtime errors across the session; test char qinshi
removed afterward (fluffos kept).

**Re-retest after the fail-closed retrofit (2026-07-24)**: fresh boot,
fresh normal registration (id `qinretes`, real Chinese name 秦风七) all
the way through `look`/`score`/`quit` — landed in 英豪酒楼, correct
output throughout, normal 30-second delayed-quit message. `fluffos`/
`Mud@2026` admin login verified again: `look` then `update
/adm/daemons/logind` → `重新编译 /adm/daemons/logind.lpc：成功！`. Zero
`执行时段错误` lines in `debug.log` for the whole session. Test char
`qinretes` removed afterward (fluffos kept).

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

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 9190 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs` (Node): 9102 written, 58 already
  idempotent-clean, 30 refused (self-checked token/byte-identity guard,
  expected on messy legacy code, not chased). Verified afterward that the
  §15ae fix (`feature/command.lpc`'s `command_hook` staying `nomask` with
  `private` still commented out) and the §15t inherit-ordering/absolute-
  include-path fixes from the original pass all survived the reformat
  unchanged (spot-checked directly, plus the boot/registration retest
  below exercises them at runtime).
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `debug.log`. Full registration
  flow re-verified with a fresh real Chinese name (`秦风六`/id `qtretest`)
  through `look`/`score`/`quit`, landing in `英豪酒楼` exactly as before —
  no regressions from either the driver rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only the expected
  benign compile-warning spam and non-fatal preload notices, same as
  native). Full registration completed end-to-end under WASM too — id
  `wasmtxq` → real Chinese name `秦枫` → password/email/gender → landed in
  `英豪酒楼`, `look`/`score`/`quit` all produced correct output. This lib
  has **no IP-format-dependent login gate**, so it isn't affected by the
  known `query_ip_number()` WASM limitation — fully playable under WASM.

## 深度功能测试 / Deep functional test (2026-07-24)

Round-two deep playthrough pass (AGENTS.md §10.7), following the
`bxsj`/`xiyouji` worked examples. Played as an ordinary new player
through registration, exploration, organic skill-learning, sect-joining,
safe and lethal combat, a real `quit`, a real-wall-clock-gap reconnect,
and (unusually for this project's round-two passes so far) a full
death/reincarnation cycle, native driver (`build-debug`). Read
`doc/help/newbie` in full first — it named the intended test path
(中州城's 英豪酒楼 start, `hp`/`cha`/`score`/`look`, the menpai/帮会
sect list, `xue <skill> from <teacher>` syntax) but, notably, said
nothing about a safe-sparring mechanism — that had to be found by
grepping `accept_fight`/room source, and turned out to be gated behind
an in-game cost a fresh character can't pay (see below).

**Test characters** (both kept, not cleaned up, as representative
playthrough evidence):
- id `qinlangf`, Chinese name 秦朗风, password `Test1234`, male — the
  main playthrough character. State: apprenticed to 谷虚道长
  (Wudang/武当派, 4th-generation disciple, `武当派第四代弟子`), learned
  `literate` (读书写字) to level 1 via the organic teacher-NPC path,
  survived a full `quit` + real-wall-clock-gap reconnect with sect
  membership and skill intact. Saves: `work/data/user/q/qinlangf.o`,
  `work/data/login/q/qinlangf.o`.
- id `linzhu`, Chinese name 林铸, password `Test1234`, male — a second,
  disposable character used for combat testing (safe `fight`, then a
  deliberately lethal `kill`, real death, and a full reincarnation
  round-trip). Saves: `work/data/user/l/linzhu.o`,
  `work/data/login/l/linzhu.o`.

### Bug found and fixed #1: already-cataloged §7.12 class, live-reproduced here for the first time

`adm/simul_efun/message.lpc:61-62`'s `tell_room(mixed ob, string str,
object *exclude)` wrapper passes the (omitted-when-not-given) `exclude`
varargs parameter straight through to the `message()` efun, which on
this driver resolves an unsupplied array-typed varargs argument to raw
int `0`, not `({})`. `message()` requires its exclude argument to be an
object or array — this is **exactly** AGENTS.md §7.12 ("Shared
message/wrapper argument bugs"), already documented as affecting "most
of the ES II family," which `tiexuejianghu` is (per this file's own
lineage section) — but this lib's original conversion pass never
checked for it, and it shipped live.

- **Symptom, live-reproduced twice in this session**: any 2-argument
  call to `tell_room(room, msg)` (158 of 348 call sites in this lib use
  the 2-arg form) crashes with `Bad argument 4 to EFUN message()
  Expected: object, array, Got: int(0)` the moment it actually runs.
  Confirmed live via `/obj/user.lpc:69`'s `user_dump(DUMP_NET_DEAD)` —
  the routine that announces "so-and-so 断线超过 N 分钟，自动退出这个
  世界" once a dropped connection's `NET_DEAD_TIMEOUT` (300s) elapses —
  which crashed for **both** test characters (`林铸` and `秦朗风`)
  independently after their sessions net-dead'd, i.e. this fires for
  **any player whose connection drops without a clean `quit`** (browser
  close, network blip, client crash) — about as common an event as
  exists in an online mud. The crash is caught by the driver (the
  disconnect itself still completes), so it's invisible on-screen by
  construction — exactly the class of bug this methodology exists to
  catch.
- **Fix** (the exact documented §7.12 fix): `exclude || ({})`.
  ```lpc
  // before
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude);
  }
  // after
  varargs void tell_room(mixed ob, string str, object *exclude) {
    if (ob) message("tell_room", str, ob, exclude || ({}));
  }
  ```
- **Verified**: reproduced live pre-fix (`debug.log` captured the exact
  trace twice, once per test character, blaming `user.lpc`'s
  `user_dump()` → `simul_efun.lpc`'s `tell_room()`). Fix applied,
  `update /adm/simul_efun/message` recompiled clean as admin
  (`fluffos`/`Mud@2026`). **Not re-verified against a live repeat of the
  same 300-second net-dead timeout** given the time budget — a genuine
  wait that long wasn't repeated post-fix. Confidence is still high:
  this is a one-line change identical to the already-proven fix
  deployed on multiple sibling ES II libs in this corpus, the file
  compiles clean, and the bug's mechanism (an omitted varargs array
  resolving to `int 0` on this driver) is independent of which caller
  triggers it — any other 2-arg `tell_room()` call site exercised during
  the rest of this session (there are 158) would have hit the identical
  crash and did not, because none of the other 157 happened to run
  during this particular playthrough, not because this one is special.

### Bug found and fixed #2: NEW bug class — a hardcoded respawn-room path stale from an old, since-replaced zone rewrite

`include/login.h:14`'s `REVIVE_ROOM` constant (`"/d/yangzhou/temple"`)
does not point at a loadable object. `d/death/npc/{wgargoyle,
bgargoyle}.lpc` (白无常/黑无常, the two death-realm psychopomp NPCs) both
run a 5-stage, 5-second-interval dialogue (`death_stage()`) after a
player dies, then call `ob->reincarnate(); ob->move(REVIVE_ROOM);` to
send the player back to the living world.

- **Symptom, live-reproduced twice**: `kill liumang` (a genuinely lethal
  fight, as opposed to the non-lethal `fight` command — see combat
  section below) killed `林铸`; the death sequence correctly created a
  corpse, moved the player to `DEATH_ROOM` (`/d/death/gate`, 鬼门关), and
  ran all 5 stages of 白无常's dialogue over ~25 real seconds — then
  crashed: `*call_other() couldn't find object '/d/yangzhou/temple'.`,
  raised from `feature/move.lpc:54`'s `move()`, called from
  `wgargoyle.lpc:56`'s `death_stage()`. The crash is caught (the
  driver's error handler swallows it, same as every other bug in this
  catalog), so the player-visible effect is silent: the dialogue simply
  stops advancing and the player is left standing in 鬼门关 forever,
  never actually returned to the living world, with **no error message
  and no indication anything went wrong** — indistinguishable from the
  game just being slow, unless `debug.log` is checked. Every player
  death in this game runs through this exact code path, making this
  among the highest-blast-radius bugs found in this project's
  round-two pass so far (every death, not just some).
- **Root cause**: `d/yangzhou/temple.lpc` doesn't exist in the live
  `d/yangzhou/` zone — but it DOES exist, verbatim, under
  `d/yz_bak/yangzhou/temple.lpc`. Comparing the two directories'
  file listings shows `d/yangzhou/` and `d/yz_bak/yangzhou/` are **two
  entirely different, incompatible room sets** that happen to share a
  directory name (77 files each, near-zero filename overlap) — not a
  newer/older revision of the same zone, but two unrelated
  wizard-authored "Yangzhou" builds, one of which (now under `yz_bak/`)
  was fully superseded and disconnected from the live map, the other
  becoming the current `d/yangzhou/`. `REVIVE_ROOM`'s path was written
  for the old, now-archived zone and never updated when the zone was
  replaced — a genuinely new bug class for this project's catalog: a
  **hardcoded room-path constant left stale after a zone got wholesale
  replaced during the original game's own development**, as opposed to
  every previously-cataloged path bug in this project (which are all
  conversion-era typos/renames). This is NOT the same shape as
  AGENTS.md's existing "content gap, documented not fabricated" pattern
  either — the target content still exists, just under a disconnected,
  deliberately-superseded backup directory, so resurrecting it by
  pointing back at the old path would reconnect stale, replaced content
  into the live map rather than fix the actual bug.
- **Fix**: repointed `REVIVE_ROOM` at `START_ROOM` (`/d/zhongzhou/
  yinghao`, always-loadable, and already the exact fallback
  `enter_world()` itself uses for a broken/missing custom startroom —
  see the "Confirmed NOT needed" §15aj entry above) rather than at the
  disconnected old zone:
  ```lpc
  // before
  #define REVIVE_ROOM			"/d/yangzhou/temple"
  // after (see the file for the full comment explaining why)
  #define REVIVE_ROOM			START_ROOM
  ```
- **Verified**: reproduced live pre-fix twice (once accidentally
  mid-testing before the fix was written, once deliberately, both times
  identical crash + identical debug.log trace). Post-fix: killed
  `林铸` a second time via `kill liumang` from a **freshly restarted
  driver** (clean boot, zero errors), let the full 5-stage/~25-second
  白无常 dialogue play out for real (`--idle 4`, several blank sends —
  the earlier pre-fix attempts under-waited and only proved the crash
  was still reachable, not yet that the fix worked), and confirmed the
  character landed cleanly in `英豪酒楼` afterward with **zero new
  debug.log lines** for the entire death→dialogue→reincarnation
  sequence. `bgargoyle.lpc` (the parallel 黑无常/"evil path" version of
  the same flow, presumably for players who die dishonorably) shares
  the identical `REVIVE_ROOM` call and is fixed by the same `login.h`
  change, but was not itself live-reproduced — flagged as fixed by
  code-shape match, not independently verified.

### Minor logic bug found and fixed (not crash-class, but confirmed via live incorrect behavior): 徐霞客's answer-window timer had its subtraction backwards

`d/zhongzhou/npc/xuxiake.lpc:99`'s `do_answer()` — part of this NPC's
"answer my trivia question before I'll teach you 读书写字" apprenticeship
gate (the organic-skill-learning path this session used) — computed
`now_time = (int)ob->query_temp("徐/time") - time();` (stored-question-
time minus now), which is always negative or zero and can never exceed
the intended 10-second answer window (`if (now_time > 10)`), rather than
`time() - stored_time` (elapsed, positive, correctly comparable to the
window). Discovered live: an unanswered question never expired even
across brute-force wrong guesses tried well outside any reasonable
10-second window, and (worse for a tester relying on the intended
"say the question again if you got it wrong" UX) the question is only
generated once per `xue` attempt (guarded by `if
(ob->query_temp("徐/answer")) return notify_fail(...)` at the top of
`recognize_apprentice()`), so a player who doesn't see the question text
in time (this project's own `mudclient.py` `--idle` pacing raced the
question's own 1-second `call_out` delay on the first attempt) is stuck
re-guessing the SAME never-re-rolled question indefinitely rather than
getting a fresh one after 10 seconds as designed. Not a crash — the
broken timer makes the puzzle strictly easier (never expires) rather
than broken/unplayable, so it's a genuine but low-severity bug. Fixed
the subtraction order:
```lpc
// before
now_time = (int)ob->query_temp("徐/time") - time();
// after
now_time = time() - (int)ob->query_temp("徐/time");
```
Verified: `update /d/zhongzhou/npc/xuxiake` recompiled clean as admin;
re-tested the full organic-learning flow end-to-end post-fix (`xue
literate from xu xiake` → question → `answer 22` → learned) — unaffected
for the correct-answer-in-time case, which is all that was re-verified
live; the now-correctly-enforced 10-second expiry itself wasn't
separately re-timed live (low value given the trivial, mechanical
nature of the fix).

### What was tested and confirmed working

- **Registration**: real Chinese name (秦朗风), full flow (id → confirm
  new character → Chinese name → password ×2 → email → gender), landing
  in `英豪酒楼` (South-City-Inn-equivalent, `d/zhongzhou/yinghao.lpc`).
  A second independent registration (林铸/linzhu) confirmed the same
  flow twice.
- **Movement/exploration**: walked from `英豪酒楼` through `文定北街` →
  `市中心` → `延陵东路` (流氓/丫鬟 wild NPCs, a small `自助餐厅`
  restaurant/shop) → south to `书院` (`d/zhongzhou/shuyuan.lpc`, 徐霞客's
  academy) and separately the long overland route to 武当山 (南城门 →
  `叉路口` → a randomized "can't tell which way" maze room, `草丛`,
  which took several retries of the same direction to escape by design
  — not a bug, an intentional random-navigation obstacle — → up the
  mountain through `太子坡`/`小吃店`/`紫霄宫`/`十八盘`/`武当广场` to
  `三清殿`). Room descriptions, exits, and NPC presence all rendered
  correctly throughout on a first-ever visit to every room walked,
  including `三清殿` itself (see "first-visit reentrancy check" below).
- **First-visit §7.17-class reentrancy check**: `三清殿` (which
  populates 2 NPCs, 谷虚道长 and 宋远桥, via `std/room.lpc`'s
  `setup()`→`reset()`→`make_inventory()` chain — the exact same
  structural shape documented in AGENTS.md §7.17 as `xiyouji`'s root
  cause #1) was this character's first-ever visit to that room on a
  freshly booted driver. No crash, no duplicate NPCs, no corrupted
  `"0"` in either NPC's title — `debug.log` only gained benign compile
  warnings (`Illegal to declare nosave function`, an unrelated
  pre-existing `dbase.h` warning seen throughout this lib) from that
  visit. This lib does NOT have this lineage's `create_identity()`/
  forced-`call_other`-self-locate idiom anywhere (grepped, zero hits),
  which per §7.17's own analysis is the second, lib-specific half
  needed to close the reentrancy cycle into an actual crash — so
  `std/room.lpc`'s shared double-`reset()` shape alone is (as §7.17
  itself found for `xiyouji`) not sufficient by itself to reproduce the
  crash here. Not treated as a bug requiring a fix; recorded because
  checking it was part of the methodology.
- **Character info**: `score`, `hp`, `i`, and `cha` (own skill list) all
  correct at every stage (fresh, post-skill-learn, post-sect-join,
  post-death/reincarnation, post-relogin).
- **Skills — organic teacher-NPC path**: `d/zhongzhou/shuyuan.lpc`'s
  徐霞客 (`xuxiake.lpc`) gates `recognize_apprentice()` behind a
  trivia-question/`answer` mini-game (see bug above) rather than an
  unconditional grant like some sibling libs' `jiaotou`-style NPCs —
  `xue literate from xu xiake` → question → `answer 22` (his age when he
  left home) → "你听了徐霞客的指导，似乎有些心得。你的「读书写字」进步
  了！" → `cha` correctly showed `读书写字 (literate) - 新学乍用 1/0`.
  Confirms `xue`/`learn` (identical files) work end-to-end.
- **Sect-joining — organic path**: `help newbie` documents 14 门派
  (sects, direct-apprentice via `bai`) and 4 NPC-led 帮会 (guilds); no
  newbie-gift shortcut exists in this lib (grepped, none found — unlike
  `bxsj`'s `shizhe.lpc`). Walked to 武当山's `三清殿`, found 谷虚道长
  (`d/wudang/npc/guxu.lpc`), whose `attempt_apprentice()` gate is
  `mingwang < 0` — trivially satisfied by a fresh character's
  `mingwang == 0` — vs. 宋远桥/`z.lpc`/`zhang.lpc`/`yu.lpc` in the same
  room/zone, which require `mingwang` from 2,000 up to 100,000 (a fresh
  character has 0). `bai guxu` → "谷虚道长决定收你为弟子。...恭喜您成为
  武当派的第四代弟子。" — `score` afterward correctly showed
  `武当派第四代弟子 秦朗风` and "你的师父是谷虚道长". This lib gates its
  various sect-master NPCs at genuinely different newbie-accessibility
  tiers by design (matching `help newbie`'s "在门派中可以直接拜师傅学
  艺" claim for at least the most junior teacher per sect) — not a bug,
  but worth noting for future testers: don't assume the FIRST
  sect-master NPC found accepts newbies; check `attempt_apprentice()`'s
  gate or just try `bai` on more than one.
- **Combat — safe path attempted, found genuinely gated, substituted**:
  this lib's own designated "safe" combat venue is `d/zhongzhou/
  biwuchang.lpc`'s referee-supervised PvP arena (`biwu <player>`
  invite/accept handshake, auto-halts a `kee`≤50%-max loser via
  `d/zhongzhou/npc/caipan.lpc`'s `do_bihua()`) — **but its entrance
  courtyard (`biwuchangyuan.lpc`) is gated behind a `门卫` (guard) NPC
  requiring a ≥20000-money bribe** (`accept_object()` in
  `d/zhongzhou/npc/guard.lpc:53`) before `valid_leave()` allows `up`
  into the arena proper. A genuinely fresh character has **0** starting
  money (confirmed: `enter_world()`/`logind.lpc` grants no starting
  cash; a `list` at the nearby 自助餐厅 shop confirmed real, cheap
  prices — 10-20 文铜板 — that are still unaffordable at 0 money).
  **This specific mechanism was NOT reached live** — an honest,
  explicitly-flagged gap, not a silent skip, per the task's own
  instructions: a genuinely fresh newbie cannot reach this lib's
  designated safe-sparring venue without first earning money through
  some other, unexplored system (quests, selling loot, etc.), which was
  outside this session's time budget. Substituted with the general
  "fight vs kill" safety mechanism this lib documents in `help combat`/
  `cmds/std/fight.lpc`'s own help text instead: `fight <npc>` is
  explicitly non-lethal ("只会消耗体力，不会真的受伤") vs `kill <npc>`
  which is genuinely lethal. Tested `fight liumang` (a weak, `attitude:
  peaceful` street-NPC, `d/zhongzhou/npc/liumang.lpc`) — full
  turn-by-turn combat log, correctly auto-conceded ("这场比试算我输
  了，佩服，佩服！") once resources dropped low, no injury, `实战经验`
  (combat exp) correctly incremented 0→3. `wimpy <N>` (the general
  flee-threshold command) was also set and confirmed to have **no**
  effect on `fight`'s own separate, hardcoded auto-concede threshold
  (tested `wimpy 0`, the auto-concede still fired) — these are two
  independent safety mechanisms, not a bug (`std/char.lpc:94-101`'s
  `wimpy`-driven auto-flee only applies to a live `is_fighting()` heart-
  beat check with `wimpy_ratio > 0`; `fight`'s own concede narration in
  `adm/daemons/combatd.lpc`'s `winner_msg` array is a separate,
  independent, always-on mechanism for the non-lethal command).
- **Combat — lethal path and death/reincarnation, reached live**:
  `kill liumang` (same weak NPC, but via the genuinely lethal command)
  produced real injury narration and, after several exchanges,
  `你死了。` — a real player death. Confirmed the death→corpse→
  `DEATH_ROOM`(`鬼门关`)→白无常-dialogue→reincarnation→`START_ROOM`
  round-trip end-to-end post-fix (see Bug #2 above); `score` in the
  interim death-realm state correctly showed the `孤魂野鬼` (lost-soul)
  title and a `ghost`-flagged reduced stat display. This satisfies the
  checklist's "get as far as reasonably possible toward combat/death"
  item in full — death was not just attempted but completed, in both
  the broken (pre-fix) and working (post-fix) forms.
- **Shop purchase — NOT completed live, explicit reason**: reached a
  real shop (`李老板`'s 自助餐厅, `list` correctly showed real items —
  辣椒/盐巴/酱油/香油 at 10-20 文铜板 each) but could not `buy`
  anything: **a genuinely fresh character has 0 starting money** in
  this lib (confirmed by inventory inspection — only default clothing,
  no currency object, and no starting-cash grant found anywhere in
  `logind.lpc`/`enter_world()`). This is the same root gate that blocks
  `biwuchang` above. Earning starting capital (quests, selling loot,
  begging, etc.) was not pursued given the time budget already spent on
  navigation and the two crash-class bugs found — flagged here
  explicitly rather than silently presented as tested.
- **Persistence**: confirmed across a real `quit` + a genuine ~80-second
  wall-clock gap (background `sleep 80`, not merely a fast reconnect) +
  fresh full re-login for `qinlangf`: sect membership
  (`武当派第四代弟子`, "你的师父是谷虚道长") and skill (`读书写字 1/0`)
  both round-tripped correctly. Room position does **not** persist
  across a real `quit` (`enter_world()` always lands a full login at
  `START_ROOM` regardless of where the character quit) — confirmed
  intentional design matching this session's own earlier admin-seeding
  notes, not a bug. Inventory: `quit` correctly dropped the (non-
  autoload, non-`unique`) starting clothes ("你丢下一双皮靴。...因为这
  样东西并不值钱，所以人们并不会注意到它的存在。") and a fresh full
  login re-granted a (randomly re-rolled, this time 蓝马褂 instead of
  the original 紫蟒袍) default outfit — the same deliberate ES-II-family
  anti-hoarding-on-quit design already documented in `bxsj`'s deep-test
  section, not a bug specific to this lib. Also separately confirmed
  the **silent-reconnect** path (a fresh connection within the same
  session, before any real `quit`, via `id`+password) re-attaches the
  same live body with zero state loss — used throughout this session
  between `mudclient.py` invocations.
- **Debug.log hygiene**: grepped after every `quit` in this session, not
  just after login, per the methodology's central lesson — clean every
  time except for the two live-reproduced bugs above (both now fixed
  and re-verified clean).

### Process/testing note for future agents on this lib

Room navigation via a static regex-based BFS over `set("exits", ([...
]))` literals (as used successfully on other libs in this project) is
**not fully reliable here** for two lib-specific reasons hit live during
this pass: (1) some rooms (e.g. `d/yeyangzai/caocong`, "草丛") implement
a randomized "you can't tell which direction" maze where the SAME
direction command must be retried a variable number of times before it
actually succeeds — a static shortest-path graph can't capture this;
(2) `mudclient.py` sessions are not persistent connections across
separate invocations in this project's usual workflow, so a character's
*actual* position when a new session logs in is wherever the PREVIOUS
session left it (via silent reconnect), not the game's own `START_ROOM`
— sending a route computed from `START_ROOM` after actually reconnecting
mid-route produces a string of `什么？` ("what?") rejections that are
easy to misdiagnose as a game bug rather than a test-script coordinate
error. Verify current position with `look` before sending a long
movement queue, especially after any prior session that didn't end in a
full room-resetting `quit`.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。`log_error()`（`adm/obj/master.lpc`，CRLF 行尾档
案）已经在更早一轮（引用注释里的"AGENTS.md #15w"）正确修复过，管
理员账号（`fluffos`/`Mud@2026`，`adm/etc/wizlist` 已有
`fluffos (admin)` 且存档已提交）也已经全部正确，本轮只发现并修复
了 `log_file()` 一处。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`，CRLF 行尾档案）完全没
   有 `assure_file()` 保护（AGENTS.md §7.11-class 的又一确认实
   例）**：`cmds/app/{clone,rm,update}.lpc`/`cmds/wiz(/arch)/
   summon.lpc` 等文件多处 `log_file("wiz/<子目录>/<id>.log", ...)`
   调用依赖对应子目录存在，其中 `wiz/update/<id>.log` 每次巫师执
   行 `update` 指令都会触发，本轮的 `update` 验证步骤本身就顺带验
   证了这个修复。注册/登录本身只写 `log_file("USAGE", ...)`（无子
   目录，本来就存在），不受影响。已补上
   `assure_file(LOG_DIR + file);`（含前向声明，用 Python 字节级替
   换保留原 CRLF 行尾格式）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`；
  姊妹文件 `u/xxy/city2/npc/refereew.lpc:176` 同样已修。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- `logon()` 没有 GB/Big5 选码提示，也没有"Press Enter to
  Continue"分页步骤——直接进英文 id 提示，本轮读代码确认后未误踩。

### 实测过程

用已提交的 `fluffos`/`Mud@2026` 登录，`update /adm/simul_efun/file`
（就是本轮改过的文件）确认可正常重新编译，零诊断刷屏。全程未生成
`log/debug.log`（说明真的零运行期错误，不是文件被清空）。登录本
身产生的存档时间戳类微小 diff 已用 `git checkout` 撤销，不提交。
驱动最终按精确 PID kill，`ps -p` 确认已退出。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3010 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。有 5 处代码生成模板烤了同一个地雷（`obj/roommaker.lpc`、
`d/obj/clone/misc/roommaker.lpc`、`obj/rmmaker.lpc`、
`u/panguan/rmmaker.lpc`、`u/panguan/room.lpc`——和手足档案 fys 同一
套模板家族）。

本档案独有的新变体（fys 没有）：`u/heart/xuedao/` 下 143 个文件的
冗余调用和一行 UTF-8 尾随注释共享同一行
（`replace_program(ROOM);  //如果没有init函数请不要删除这句话`），
严格的独立成行脚本正确地跳过了它——另写了一个针对这个精确行形状
的脚本手动摘除。累计 3012 处 live 调用删除，和 survey 记录的数字精
确吻合，修复后 0 处遗留。

验证：`build-debug` 驱动真实冷启动，端口 40087 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（落地英豪酒楼，look/quit），全程无新增
"cannot replace"/"cannot bind" 日志行。

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

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（2026-09-04，shop）

Live pass, port **40087**. 2026-07-24 already apprenticed `qinlangf` to
谷虚道长 (武当派); this round is shop only. First send is the English
id (no GB/BIG5 menu). Admin `fluffos` / `Mud@2026` lands at 英豪酒楼
(`/d/zhongzhou/yinghao`) with 武大郎 present.

**Shop**: `list` on 武大郎 (`d/zhongzhou/npc/wudalang.lpc`, `F_VENDOR`)
shows 烤鸡腿 三十文铜板 (key `jitui`). `clone /obj/money/gold` then
`buy jitui from wu dalang` succeeded: “你向武大郎买下一根烤鸡腿”,
inventory 烤鸡腿 + 九十九两银子 + 七十文钱. `can_afford()`'s 零钱
checks are already commented out here (Huang 1996 auto-convert), so
gold-only is fine. 武大郎 `random_chat` emotes — idle 0.45.

No code change. 拜师 not re-done.
