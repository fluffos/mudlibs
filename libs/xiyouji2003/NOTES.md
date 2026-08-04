# 西游记2003.rar → `xiyouji2003`

- **Archive**: `archives/西游记2003.rar` (2.9MB, archive #81). Extracted root:
  `xyj200341/` (the archive's own top-level folder name — a version-stamp
  slug, "xyj 2003-04-1(?)", not a display name). Bundles a prebuilt Windows
  MudOS driver (`MUDOS.EXE`, `mudos.dll`, `mudos.ini`) alongside the LPC
  source at the mudlib root — ignored per convention, our own
  `build-debug` driver is used throughout.
- **Self-identified name**: `config.cfg`'s `name :` field reads
  `西游记[光辉岁月]` ("Journey to the West [Glorious Years]"); the live
  banner also renders `中国文字泥潭『西游记『光辉岁月』』` and
  `西游记之光辉岁月`. This differs cosmetically from the archive's own
  filename ("西游记2003") the same way several other libs in this project
  have a distinct in-game brand name from their archive/collector-site
  title — noted here per the task instructions, slug `xiyouji2003` kept as
  a reasonable match for the archive title itself.
- Config: `xyj200341/config.cfg` (MudOS 0.9.20 format, mixed `external_port_1/2`
  + `address server` legacy directives, no `port number` key — adapted).
- Port: **40075** (per TODO.md's reservation for archive #81 at the time
  this pass started).

## Lineage: confirmed a genuine relative of BOTH `xyj2000f` (#15) and the 梦幻西游/mhxy family (#19/#56/#73) — but NOT a duplicate of any of them

Per the task's explicit instruction, all four already-processed
Journey-to-the-West-themed siblings were read (`libs/xyj2000f/NOTES.md`,
`libs/mhxy/NOTES.md`, `libs/mhxyqd/NOTES.md`,
`libs/shenmo/NOTES.md`) and this archive's `adm/obj/master.c`,
`adm/simul_efun/chinese.c`, `adm/daemons/logind.c`, `adm/daemons/securityd.c`,
`adm/daemons/named.c`, `adm/daemons/convertd.c` were diffed/md5sum'd
against the corresponding raw files of all four before any conversion work
began.

**Findings, by file** (raw pre-conversion bytes, GBK-decoded for the text
diffs):

- **`adm/obj/master.c`**: **486 lines vs. 486 lines, only 3 trivial diffs**
  against `xyj2000f`'s copy (a header-comment credit line, one
  commented-out `if` block, and a 2-line reordering) — this is
  overwhelmingly the SAME `master.c` (both trace back to "for ES II
  mudlib / original from Lil / rewritten by Annihilator (11/07/94)", the
  same lineage root as `es1_win`/`shenmo`/`xkx2001`/etc.), just with
  `xyj2000f`'s copy re-credited by a later cracker ("vikee")
  vs. this archive's own maintainer credit ("Pkyou@xyj 2002-06-12"). This
  is the single strongest piece of evidence: `master.c` is essentially
  never touched by ordinary game-content authors, so two independent
  forks staying byte-for-byte identical outside 3 lines means they share
  a very recent common ancestor. **`master.c` was NOT identical to any of
  `mhxy`/`mhxyqd`/`shenmo`'s copies** (those three inherit a
  different, longer master.c under the same `adm/obj/` layout convention
  but a different code lineage) — confirming this archive sits
  specifically on the `xyj2000f` side of the "西游记" family
  tree, not the `mhxy`/`shenmo` side, despite all sharing the same
  historical zone names (`d/lingjie`, `d/pansi`, `d/wudang`, `d/mojiao`,
  `d/shenjian`, `d/wuguan`, `d/nanhai` recur across all of them —
  confirming a MUCH older shared root further back, before the
  `master.c` fork point).
- **`adm/simul_efun/chinese.c`**: NOT byte-identical to any of the four
  (own hash), but the same `is_chinese()`/`chinese_number()`/`to_chinese()`
  function set, credited "waiwai@2003/04/25" — a different (and, per the
  §15h investigation below, more elaborate/buggier) sliding-byte-pair
  `is_chinese()` implementation than `xyj2000f`'s simple
  `str[0]>160&&str[0]<255` form.
- **`adm/daemons/logind.c`**: same "waiwai" credit trail
  (`waiwai@2001/07/02` through `waiwai@2003/04/25`), same overall registration
  shape (gb/big5 → age-style "①进入②离开" gate → English id ("new" to
  register) → Chinese name → password → confirm password → email →
  gender → auto-gift → enter_world), but nearly 2x longer than
  `xyj2000f`'s copy (1901 vs 998 lines) — a substantially
  extended, later snapshot of the same base, not the same file.
- **`adm/daemons/convertd.c`**: different hash from all three siblings
  that have this file, but the exact same §8h "Greek-alphabet lookup
  table, stray trailing backslash before the closing quote" defect,
  **45 occurrences** — the identical count found in both `mhxy` and
  `mhxyqd`'s copies of this file, strong secondary evidence of
  a shared distant ancestor for this one daemon specifically (likely
  copied around wholesale across many "西游记"-lineage mudlibs of this
  era, independent of which master.c branch a given site forked).

**Conclusion**: this is a genuine, independently-evolved 2003-era snapshot
of the SAME `master.c`/ES-II-derived "西游记" (Journey to the West) engine
that `xyj2000f` (#15) also derives from — closer to #15 than to
the `mhxy`/`mhxyqd`/`shenmo` branch, but not a duplicate of any
of the four. Per the task's instruction to port proven fixes directly when
related: `xyj2000f`'s and `mhxy`'s §8h convertd.lpc fix pattern
(CRLF-aware sed) was ported directly and worked verbatim (same shape, same
count). The §15h is_chinese/check_legal_name fix pattern was ALSO the
right family of fix, but this archive's own `is_chinese()`/`check_legal_name()`
implementations are a different (sliding-byte-pair) variant than either
sibling's, so the concrete edits were derived fresh from THIS archive's
actual code rather than pasted from a sibling (see below) — consistent
with the project's repeated finding that shared lineage does not mean
byte-identical bugs.

## Status: DONE — boots clean, full registration + post-login-command flow verified twice in independent continuous connections

## Re-verification pass (QA sweep, later session)

Re-tested the full flow end-to-end again this pass (still clean, zero
`执行时段错误` in `debug.log`). Found and fixed two real bugs shared
across this whole "西游记" sibling family:

1. **§15s, `tell_room()`'s raw-`int 0`-as-4th-arg bug, re-examined and
   found to actually apply here after all.** This file's own earlier
   pass explicitly noted the driver "tolerates a raw `0`" in
   `message()`'s exclude slot and left it unfixed -- but a live crash of
   the exact same call shape was subsequently confirmed on sibling libs
   `xkx2001` and `xiyouji2006` in this same later session (bridge-room
   `close_bridge()`/room `create()` chains hitting `Bad argument 4 to
   EFUN message() ... Got: int(0)`). Ported the standard fix
   (`exclude || ({})`) here too, defensively, since the underlying call
   shape is identical even though this specific archive's boot/
   registration path happened not to trigger it. Re-verified with a
   clean boot + fresh registration: zero regressions, zero new errors.
2. **Stray pre-existing debug leftover `printf("%O\n", ob);`** in TWO
   places in `adm/daemons/logind.lpc` (the Chinese-name-confirmation step
   and a related `get_resp`-style retry path) -- dumps a raw internal
   object reference straight to the connecting player right after their
   Chinese name is accepted, on every registration. Same shared-lineage
   leftover found (and removed) in siblings `xiyouji`/`xiyouji2006`/
   `xiyouji450`. Removed both occurrences; re-verified with a fresh
   registration (`qfmingyu`/明玉): no stray object-reference text
   anywhere in the transcript, `look`/`score` both still correct, correct
   female-specific fields.

## Conversion

`scripts/convert_lib.sh libs/xiyouji2003/raw/xyj200341 libs/xiyouji2003/work`:
GB18030→UTF-8 (already_utf8=231, converted=3046, **lossy=36**,
skipped_binary=140), `.c`→`.lpc` rename (2599 files), literal `".c"`
reference fixes (307 refs fixed, 0 remaining), angle-bracket `#include <x.c>`
fix (1 ref), local angle-bracket `#include <x.h>` → `"x.h"` conversion (28
converted), `static`→`nosave` (83 files touched). No uppercase `.C` files
found (`find . -name "*.C"` → 0, checked per §7 lessons from `shenmo`). No
stragglers missed by the file-heuristic (`file -b` check on every `.lpc`/`.h`
came back clean).

**§3 counterexample reverted**: the blanket `static`→`nosave` sed corrupted
17 files' `log_file("static/XXX", ...)` / `set("nosave/marry", ...)` -style
string literals (a pre-existing `log/static/` subdirectory naming
convention — confirmed real seed data on disk: `log/static/{CRASHES,
LASTCRASH,LASTTIME}` shipped in the raw archive) to `"nosave/XXX"`.
Reverted with a targeted `sed -i 's/"nosave\//"static\//g'` scoped to the
17 flagged files; verified 0 `"nosave/` string-literal hits remain and all
17 `"static/` literals are restored. Checked for the §15z variant (a
`#define nosave static`/`#define protected static` compatibility shim) —
none present, nothing to revert there.

## Fixes applied (in order found, with why)

1. **§15h, `is_chinese()` GBK sliding-byte-pair bug — TWO independent
   copies fixed** (this archive's own `is_chinese()` variant differs from
   every sibling's, so both had to be re-derived from source, not
   copy-pasted):
   - `adm/simul_efun/chinese.lpc`'s `is_chinese(str)`:
     `if( i < 2 || i % 2 != 0 ) return 0; while( i -= 2 ) { if( (str[i] <
     129 || str[i+1] < '@') || ... ) return 0; }` (a GBK-byte-pair
     sliding-window check assuming 2 bytes = 1 character) → rewritten to
     a straightforward per-character CJK Unicode codepoint range check
     (`str[i] >= 0x4e00 && str[i] <= 0x9fff` for every index).
   - `adm/daemons/chinesed.c`'s **separate** `is_chinese(str)` (the one
     actually called by `logind.lpc`'s `check_legal_name` via
     `CHINESE_D->is_chinese(...)`) had the SAME `%2!=0`-rejects-odd-length
     bug plus a pre-existing typo (`for(i=0;...) if(!(str[0]>170 &&
     str[0]<255))` — always checked `str[0]`, never the loop variable
     `str[i]`, harmless under the old convention since a 2-char-minimum
     check made this a no-op most of the time, but still wrong) — fixed
     to the same per-character CJK range check, using `str[i]` correctly.
2. **§15h, `check_legal_name()` in `adm/daemons/logind.lpc`**: two
   sub-fixes in the same function, confirmed by ACTUALLY testing
   registration through to completion (not just reading the code):
   - `strlen(name) < 4 || strlen(name) > 8` (message text explicitly says
     "二到四个中文字" — 2 to 4 Chinese characters — the byte-doubled
     bound of 4-8 was calibrated for the old 2-bytes-per-character GBK
     convention) → halved to `strlen(name) < 2 || strlen(name) > 4`.
   - `if( i%2==0 && !CHINESE_D->is_chinese(name[i..<0]) )` (the `i%2==0`
     gate existed to land on alternating GBK lead-byte positions; the
     `name[i..<0]` slice is this archive's own idiosyncratic single-"character"
     extraction idiom under the old byte convention) → dropped `i%2==0`
     entirely and changed the slice to `name[i..i]` (one real UTF-8
     character), checking every position.
3. **§15h, `named.lpc`'s `PATH()` sharding macro AND sliding-window
   similar-name check** (`adm/daemons/named.lpc`, this lineage's
   name↔id registry, `inherit F_DBASE` — confirmed real local
   set/query/delete, not the nitan-family bare-simul_efun bug):
   - `#define PATH(name) (name[0..1] + "/" + name)` ("first GBK
     character") → `name[0..0]` (first UTF-8 character).
   - `invalid_new_name()`'s similar-name detector: `strlen(name) < 4`
     guard + `for (i = 0; i <= l - 4; i++) { assure_map_name(name[i..i+3]);
     if (i+6<=l) assure_map_name(name[i..i+5]); ... }` (4-byte/6-byte
     windows = 2-char/3-char windows under the old convention) → halved
     to `strlen(name) < 2` guard + `for (i = 0; i <= l - 2; i++) {
     assure_map_name(name[i..i+1]); if (i+3<=l) assure_map_name(name[i..i+2]);
     ... }` (2-char/3-char windows directly).
4. **§8h, `adm/daemons/convertd.lpc`'s Greek-alphabet-table stray-trailing-backslash
   typo** — same defect shape as `xyj2000f`/`mhxy`
   (`"α\",` should be `"α",`), **45 occurrences**, same count as `mhxy`'s
   copy. File has CRLF line endings (confirmed via `file -b`), so the
   CRLF-aware pattern from `mhxy`'s precedent was used directly:
   `s/\\"(,)?\r?$/"\1\r/`. All 45 fixed, 0 remaining afterward.
5. **NEW, most impactful bug in this pass — `logind.lpc`'s intermud
   DNS-daemon "site verification" gate self-shutting-down the server on
   the very first connection (§15ab/§15p/§15u-adjacent)**: `encoding()`'s
   `if(new_start==0) { if(!find_object(DNS_MASTER) || !check_ip_(...))
   { ... shutdown(1); return; } new_start++; }`. With `dns_master`
   correctly excluded from `adm/etc/preload` (§15p, applied proactively
   before first boot), `find_object(DNS_MASTER)` is unconditionally null
   on a fresh boot, so `!find_object(DNS_MASTER)` is unconditionally
   true — **the driver called `shutdown(1)` on the FIRST player to type
   `gb`/select an encoding, taking down the entire process**, before this
   fix was found (discovered on the very first interactive test attempt:
   `check_ip_()` itself is a hardcoded `return 1;` stub in
   `adm/daemons/band.lpc`, so this gate only ever existed to punish a
   missing/unreachable intermud daemon). Fixed by requiring
   `find_object(DNS_MASTER)` to be truthy before the whole condition can
   fire at all (`if(find_object(DNS_MASTER) && !check_ip_(...)) {...}`),
   matching the shape of every other `DNS_MASTER`-gated call in this same
   file (lines 156/159's `total_players()` already had this exact
   `!find_object(DNS_MASTER) → return 0` early-out pattern; the
   `encoding()` gate just never got the same treatment). **Worth adding
   to AGENTS.md's catalog as a distinct variant of §15ab**: a
   DNS/intermud daemon excluded from preload per §15p can still be relied
   upon (incorrectly) as an ALWAYS-loaded precondition elsewhere in the
   same file, and when the consequence of it being absent is
   `shutdown()` rather than a crash/error, the failure mode is "the whole
   server dies silently on the first real connection" rather than a
   visible LPC error anywhere in `debug.log`.
6. **NEW content gap on the mandatory registration path — `/d/wiz/init`
   ("choose your gift" staging room) does not exist anywhere in this
   archive (§13/§15e)**: `enter_world()`'s `if(user->query("no_gift"))
   user->move("/d/wiz/init",1);` branch fires for EVERY new character
   (`confirm_gift()` unconditionally sets `no_gift=1` for all new
   players before calling `enter_world()`), but `/d/wiz/init.lpc` does
   not exist on disk anywhere in the archive (confirmed via `find`).
   `move()` to a nonexistent object silently left every new character
   with **no environment at all**, which then crashed
   `feature/command.lpc`'s `command_hook()` on
   `environment(me)->query("limit_cmds")` (line 62, `env` was `0`) —
   `Bad argument 1 to EFUN call_other() ... Got: int(0)` — for **every
   single post-login command**, `look`/`score`/`quit` all failing
   identically, discovered exactly per the standing §15ae policy of
   testing a real post-login command. Fixed with a guard matching the
   EXACT same fallback pattern already used a few lines below in the
   SAME function for a missing `startroom`: `if
   (load_object("/d/wiz/init")) user->move("/d/wiz/init",1); else
   user->move(START_ROOM);`. Verified fixed: after the fix, `look`
   correctly shows the real starting room (南城客栈/South City Inn) and
   `score` shows a full, correct character sheet.
7. **§15w, `master.lpc`'s `log_error()` broadcasting every compile
   WARNING (not just real errors) to the connected player** — same shape
   as `wuhanzhan`/`shenzhou`/`shenmo`: `if(this_player(1)) { if(wizardp(...))
   efun::write("编译时段错误："+message); else
   efun::write(get_config(__DEFAULT_ERROR_MESSAGE__)); }` fired
   unconditionally for BOTH wizard and non-wizard connected players on
   ANY `log_error()` call, including harmless warnings (`Illegal to
   declare nosave function`, `Unknown #pragma, ignored`, etc — this
   archive's `#pragma optimize`/`#pragma save_binary` directives aren't
   recognized by this driver). Fixed by gating the broadcast on the
   message NOT containing the substring `"warning:"`, matching the
   established fix pattern exactly; still writes everything to the log
   file unconditionally.
8. **§14, `valid_override()` upgraded to the 3-arg form** — the original
   2-arg `valid_override(file, name)` only recognized
   `file==SIMUL_EFUN_OB||file==MASTER_OB`; added the `main_file`
   parameter and `main_file==SIMUL_EFUN_OB||main_file==MASTER_OB` too, so
   an `efun::` override written inside a file `#include`d into
   simul_efun/master (rather than being simul_efun.lpc/master.lpc itself)
   is still recognized. Applied proactively per the catalog's "free fix"
   guidance; never observed to matter in a real boot here either (same
   as most other libs where this was tried).
9. **§8d/§15o, `master.lpc` missing `get_include_path()`** — added the
   standard implementation (prepends the compiling file's own directory,
   falls back to `:DEFAULT:`). 1768 files use the local
   `#include <x.h>`-angle-bracket idiom in this lib; `convert_lib.sh`'s
   automatic local-include-to-quote conversion handled 28 of them
   directly during the standard pass, and this master apply is insurance
   for the rest reached only mid-connection (matches the pattern
   documented for `shenmo`/`mhxyqd`). The real boot +
   registration test produced zero `Cannot #include` errors either way.
10. **§15b, `message_combatd` restored as an alias to `message_vision`**
    (`adm/simul_efun/message.lpc`) — same "called (obj/weapon/bow.lpc)
    but never defined anywhere" gap already catalogued for
    `wmkj`. Needed a `varargs void message_vision(...)`
    **forward declaration** ahead of the new `message_combatd` wrapper
    (§8b/§15aa: `message_combatd` is defined textually before
    `message_vision` in this file) to avoid an `Undefined function
    message_vision` compile error — confirmed with a targeted `lpcc`
    re-check on the 3 affected files (`obj/weapon/qimeigun.lpc`,
    `obj/weapon/changqiang.lpc`, `obj/weapon/bow.lpc`) after the fix, all
    now PASS.
11. **New §8g-variant: `CLUB`/`F_CLUB` macros never added to
    `include/weapon.h`'s otherwise-complete weapon-type table**, even
    though `/std/weapon/club.lpc` and `/std/weapon/_club.lpc` both exist
    on disk. `weapon.h` defines `ARCHERY`/`AXE`/`BLADE`/`BOW`/`DAGGER`/
    `FORK`/`HAMMER`/`MACE`/`RAKE`/`SWORD`/`STAFF`/`STICK`/`THROWING`/
    `WHIP`/`SPEAR`/`NEEDLE` (plus their `F_`-prefixed feature-base
    counterparts) exhaustively but simply omitted `CLUB`/`F_CLUB` — a
    genuine oversight, not missing content (the target files are right
    there). Affected exactly 2 files (`obj/weapon/qimeigun.lpc`,
    `obj/weapon/changqiang.lpc`, both `inherit CLUB;`) — fixed by adding
    the two missing `#define`s following the exact same naming
    convention as every other weapon type in the file. Both files now
    compile clean.
12. **§15ac, bare `SAVE_EXTENSION` instead of `__SAVE_EXTENSION__`** —
    found 2 files in the (non-critical, non-preloaded) intermud-mail
    subsystem (`include/net/ftpdsupp.h`, `adm/daemons/network/netmail.lpc`).
    Fixed via a blanket word-boundary replace in both files; cheap
    insurance even though this subsystem is out of scope for registration
    testing.

## Confirmed NOT needed (verified by reading the actual source, not assumed from a sibling's precedent)

- **§4 (`load_object()`-during-compile recursion in `valid_read`/
  `valid_write`)**: both are the plain
  `if (ob = find_object(SECURITY_D)) return (int)ob->valid_X(...); return
  0/1;` shape — no `load_object()` call anywhere in either. Confirmed by
  a clean boot with zero `Too deep recursion`/`Object cannot be loaded
  during compilation` anywhere in `debug.log`.
- **§7 (missing `get_root_uid()`/`get_bb_uid()`)**: both present verbatim
  in `master.lpc` (`return ROOT_UID;`/`return BACKBONE_UID;`).
- **§15l (`master.lpc create()` destructing `SIMUL_EFUN_OB`)**:
  `create()` is a single `write("master: loaded successfully.\n");` line
  — no `destruct()` call anywhere in it.
- **§15n (custom `securityd.lpc` blocking mid-connection
  `load_object`/`include`)**: `adm/daemons/securityd.lpc`'s `valid_read()`
  is a flat, unconditional `return 1;` (allow everything) — no ACL table
  gating reads at all (unlike the shujian2008-family shape this fix
  normally targets). Confirmed empirically too: zero `Read access denied`
  anywhere in `debug.log` across two full registration + post-login
  test runs.
- **§8c (`this_player()`-override footgun in `securityd.lpc`)**: grepped
  for `this_player()` in `securityd.lpc` — zero hits. `valid_write`
  derives `euid`/`status` directly from the passed-in `user` parameter
  (`geteuid(user)`/`get_status(user)`), never re-assigning
  `user = this_player()`.
- **§15u (dormant "phone-home" destructive license check)**: grepped
  `securityd.lpc`/`master.lpc` for suspicious `rm`/`destruct`/`shutdown`
  gated on an opaque check — the only `rm()`/`shutdown()` calls found are
  legitimate (rewriting `WIZLIST` before saving it, rewriting an `.edrc`
  file, and the DNS-gate `shutdown(1)` already covered/fixed in item 5
  above, which is an accidental self-DoS rather than a deliberate
  anti-piracy trap).
- **§15v (`LONELY_IMPROVED`-gated `efun::` family)** and **§15 (bare
  simul_efun-based `set`/`query`/`delete` dbase architecture bug, the
  nitan/NT/Lonely lineage's signature issue)**: neither applies — this is
  the ES-II lineage, not NT/nitan/Lonely. Grepped for `LONELY_IMPROVED`
  (0 hits) and `efun::set(`/`efun::query(`/`efun::delete(`/`efun::addn`
  (0 hits each). `feature/dbase.lpc` already defines real local
  `set`/`query`/`delete`/`add` methods (lines 25/35/54/66), confirmed
  before assuming anything.
- **§15t (absolute-path angle-bracket / `..`-relative / inherit-after-globals
  #include failures)**: grepped for all three specific shapes across the
  whole tree — zero hits for each.
- **§15s (2-arg `tell_room()`/`message()` wrapper passing a raw `int 0`
  as the 4th `message()` argument)**: `adm/simul_efun/message.lpc`'s
  `tell_room(mixed ob, string str, object *exclude)` (varargs) does pass
  a possibly-unset `exclude` straight through to `message("tell_room",
  str, ob, exclude)`, structurally identical to the bug found on
  `yueyingqiyuan`/`shenmo` — but confirmed via direct read of this
  driver's own `f_message()` (`~/src/fluffos/src/packages/core/efuns_main.cc`,
  `switch(args[3].type)`'s `default:` case sets `avoid = &the_null_array;`
  with NO `bad_argument()` call for the 4th argument position) that this
  specific driver build tolerates a raw `0` in that slot gracefully — the
  bug does not reproduce here, matching `shenmo`'s finding on the exact
  same driver build. Not fixed since there is nothing to fix.
- **§15aa (same-named wrapper calling the bare efun identifier before its
  own definition)**: `adm/simul_efun/message.lpc` has NO local override
  of `message()` itself (only `tell_room`/`tell_object`/`shout`/`write`/
  `say`, all calling the real efun directly) — the specific footgun this
  entry describes cannot occur here since there is no `message()`
  wrapper to bypass. (The forward-declaration fix in item 10 above for
  the NEW `message_combatd` alias is the same *general* ordering
  principle, applied preventively while adding new code, not a case of
  this exact pre-existing bug.)
- **§15ae (`private nomask` command-hook silently breaking every
  post-login command) — checked hardest per the standing policy**:
  `feature/command.lpc`'s `command_hook(string arg)` is declared
  `protected nomask`, NOT `private nomask` — confirmed by direct read
  (line 26) and empirically twice over (both interactive test runs had
  working `look`/`score` after the unrelated `/d/wiz/init` fix above was
  applied). Grepped the whole tree for `private nomask` — zero hits.
- **§15ag (`__OLD_ED__`/`ed_start`/`ed_cmd`/`query_ed_mode`)**: grepped
  the whole tree for all three names — zero hits. No editor-feature
  dependency on the removed applies.
- **§15ah (missing save-data directory silently aborting a
  `write_file()`/`log_file()` call mid-registration)**: proactively
  audited every `log_file("path/subdir", ...)` call site across the
  whole lib for a directory component (`cmds`, `nature`, `player`,
  `player/chat`, `quest`, `static`, `wizcmds`, `wizcmds/call`,
  `wizcmds/edit`) and confirmed all 9 already exist in the archive's own
  shipped `log/` tree — copied that whole directory-structure (dirs only,
  no seed-data duplication needed) into the top-level `libs/xiyouji2003/log/`
  (the CWD-relative log directory per §6, NOT `work/log/`) before the
  first boot, alongside `mkdir -p adm/tmp` for the configured swap-file
  directory. Confirmed via a fully clean boot + two registration runs
  with zero missing-directory errors anywhere in `debug.log`.
- **§8e (`tail()` missing efun)**: exactly one call site
  (`cmds/wiz/tail.lpc:16`), a wizard admin command, never preloaded or
  `#include`d elsewhere — same non-fatal shape as several other libs. Not
  fixed (dead-unless-invoked admin tooling, out of scope).
- **§15x (hardcoded `MUD_PORT` constant mismatching the assigned port)**:
  this lib's port resolution goes through `LOCAL_PORT()` →
  `get_config(__MUD_PORT__)` (the real driver-config value), not a
  hardcoded constant in `globals.h` — confirmed via `grep -rn MUD_PORT`
  across `include/`. Nothing to fix.
- **§15q (hidden client-protocol-version gate)**: read the full
  `get_id`/`confirm_id`/`get_name` callback chain before scripting the
  test — no hidden literal-string check anywhere in the pre-id sequence,
  just the documented `①进入②离开` age/consent-style gate (a real,
  intentional content gate, not a bug) followed directly by the English
  id prompt.
- **§15j (anti-flood "one registration per N minutes per IP" throttle)**:
  no such throttle found in `logind.lpc`/`band.lpc`; three separate full
  registrations were run back-to-back from the same test host with no
  rejection.

## Registration flow (read from `logind.lpc`'s actual `input_to` chain before testing, per standing policy)

`logon()` → banner + `Select GB or BIG5 (gb/big5):` (send `gb`) →
`encoding()` → site stats display → `请您做出选择：① 进入(Enter) ② 离开(Exit)`
(send `1`) → `if_young()` → intermud site list + `您的英文名字：（新玩家请键入 new 注册）`
(send `new`) → `get_id()` → registration-notice banner +
`请您给自己取一个英文名字：` (send a **3-8 lowercase-letter-only** English
id, e.g. `qinling`) → `get_new_id()` → `confirm_id()` shows the Chinese-name
banner + `请输入您要取的中文名字(二到四个中文字)：` (send a real **2-4
character** Chinese name) → `get_name()` (validates via
`NAME_D->invalid_new_name()` + `check_legal_name()`, no y/n confirmation
step when a real name is typed) → `现在请设定您的密码：` (send a
**≥5-character** password) → `new_password()` → `请再输入一次您的密码：`
(same password again) → `confirm_password()` → email-registration banner +
`您的电子邮件地址：` (send `user@address.tld` form) → `get_email()` →
`您要扮演男性(m)的角色或女性(f)的角色？` (send `m`/`f`) → `get_gender()` →
`make_body()` + `confirm_gift("n", ...)` (automatic, unconditional — no
further prompt) → `enter_world()` → welcome banner, "第 1 次连线" stats,
Guanyin-bodhisattva reincarnation news flavor text, then the real starting
room (南城客栈/South City Inn).

## Registration + post-login-command test transcripts

**Run 1** (id `qinfeng`, name `秦风`, gender `m`) — run BEFORE the
`/d/wiz/init` fix (item 6 above) was applied: registration completed
successfully end-to-end (banner → gb → stats → new → English id → Chinese
name accepted → password/confirm → email → gender → welcome message +
reincarnation news flavor text, all rendered correctly), but every
post-login command (`look`, `score`, `quit`) failed identically in
`debug.log` with `*Bad argument 1 to EFUN call_other() ... Got: int(0)`
rooted at `feature/command.lpc:62` — this is the exact §15ae-class
"registration works, every post-login command silently does nothing"
signature the standing policy exists to catch, root-caused to the missing
`/d/wiz/init` room (item 6) rather than a `private`-visibility bug this
time. Player-visible symptom: three `系统局部错误，请向巫师汇报。` lines
(the non-wizard branch of `log_error()`/`error_handler()`) instead of any
real command output.

**Run 2** (id `qinling`, name `秦岭`, gender `f`) — run AFTER the fix:
full registration completed identically, `enter_world()` placed the
character in `南城客栈`, `look` correctly displayed the real room
description (店小二/inn staff greeting, board/vote-box/exits, matching
the room's actual content), `score` displayed a complete, correct
character sheet (`你现在的头衔 : 【 少 女 】`, gender-correct fields:
`性别：[女性]`/`状态：[ 处 女 ]`, stats/attributes all populated), `quit`
correctly triggered the "new account needs 30 minutes online before quit
preserves it, confirm deletion? (y/n)" gate (a genuine, intentional
gameplay safeguard, not a bug). **Zero errors of any kind in `debug.log`**
across this entire connection.

**Run 3** (id `qinlan`, name attempt `秦岭` → correctly rejected as
already-registered by run 2 above — `对不起，这个名字和已注册用户 qinling
的名字重复了。`, confirming the dup-name check works — then retried with
name `林风`, gender `m`): full registration + `look` + `score` both
succeeded cleanly again in a SECOND independent continuous connection,
landing in the same starting room, correct male-specific fields
(`性别：[男性]`/`状态：[ 童 男 ]`/头衔 `【 少 年 】`). **Zero errors in
`debug.log`** for this run either.

## `lpcc_check.sh` sweep results

Ran twice: once before the `message_combatd`/`CLUB` fixes (items 10-11)
to establish a baseline, once after.

- **Before**: total=2599, pass=2317, fail=282 (89.15%).
- **After**: total=2599, pass=2322, fail=277 (89.3%).

**Triage of the remaining 277 failures** (by category, none on the
boot/registration/post-login-command critical path — all confirmed via
`debug.log` staying clean across 3 real interactive runs):

- **14× `Cannot #include`** — all in the never-preloaded intermud
  mail/telnet/ping subsystem (`adm/daemons/network/{mail_serv,ms,netmail,
  pingd,pingtcp,telnetd,userid,user_weapond}.lpc`) referencing headers
  (`net/uid.h`, `mailer.h`, `priv.h`, `user_weapon.h`) that are genuinely
  absent from this archive — a §13-style content gap in an optional
  subsystem, not fabricated.
- **8× `syntax error`** — 4 are cascades from the missing-header files
  above (`pingd`/`pingtcp`/`telnetd`/`userid`, `inherit UID_D;`-shaped
  lines choking without their header); the rest (`d/city/npc/duke.lpc`,
  `d/city/obj/dami.lpc` via the genuinely-missing `UNARMED` macro/std
  type, `feature/itemmake.lpc`/`obj/weapon/lingshe.lpc` via the
  genuinely-missing `F_OBSAVE` feature — no `std/weapon/unarmed.lpc` or
  any "obsave" feature file exists anywhere in the archive, confirmed via
  `find` before concluding this is missing content rather than a typo)
  are real, isolated content gaps affecting exactly 1-2 files each — not
  fixed, per §13's "don't fabricate missing content" policy.
- **6× `Undefined function message_sort`** (all in one file,
  `obj/insect/bingcan.lpc`) and **6× `Undefined function
  function_improved`** (all in one file,
  `daemon/class/ghost/tonsillitis/fight.lpc`) — the same "§15b-shaped,
  called but never defined" simul_efun gap as `message_combatd` (fixed in
  item 10), but isolated to single, non-critical NPC/skill files; not
  fixed given the "breadth over depth" time budget — noted here as a
  known, easily-reproducible fix pattern if this content is ever needed.
- **`TABLE`/`NUM`/`GAMEINFO`/`CARDNO`** (3 each, one card-game feature
  file) and **`USER_WEAPON`/`THIS_MUD`/`SUPER_B`/`SPECIAL_B`/`POSTAL_D`/
  `MAILER_D`/`MAILDIR`/`GREAT_B`/`family_path`/`DIR_POSTAL`/
  `DEFAULT_SETTINGS`** (1 each) — all missing macros/globals confined to
  isolated, non-critical content (a card-game minigame, the intermud-mail
  subsystem, one `inventroom.lpc`) — not chased individually.
- **`find_large`** (3, `d/city/piggy_two.lpc`/`d/city/piggy-partner.lpc`),
  **`day_event`** (2, one of which is `cmds/std/go.old.lpc` — an
  apparently-superseded duplicate of the WORKING `cmds/std/go.lpc`, which
  itself calls `day_event()` successfully since it `#include`s the header
  that defines it locally; the "old" file just never `#include`s
  anything), **`data_netmail_file`**, **`remove_ansi`** (1,
  `std/item/book.lpc` — a real §15b-shaped gap, but a single isolated
  call site), **`mud_name`**, **`init_blade`**, **`get_color`**,
  **`file_exists`**, **`dump_socket_status`**, **`tail`** (the same known
  non-fatal §8e gap) — all single-digit, isolated occurrences, not
  chased further.
- **2× `Bad assignment`, 3× `Type mismatch`, 1× `Too many arguments to
  'random'`, 1× `Invalid argument types`, 1× `Bad type for argument 1 of
  set_leader`, 1× `Bad argument 1 to efun restore_object`, 1× `Bad
  argument 1 to efun lower_case`** — scattered pre-existing single-file
  typos in room/NPC/skill content, not on the critical path, not chased
  given the overall pass rate and time budget.

## How to run

```
cd libs/xiyouji2003
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40075 --timeout 30 --idle 1.5 \
  --send "gb" --send "1" --send "new" --send "<3-8 lowercase letters>" \
  --send "<2-4 real Chinese characters>" --send "<password>=5+" \
  --send "<same password>" --send "user@example.com" --send "m" \
  --send "look" --send "score" --send "quit"
```

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  2,506 files reformatted, 28 unchanged, 65 refused (self-check
  failures on messy legacy code, expected). Confirmed the earlier
  `printf("%O\n", ob);` removals (both occurrences) and the `tell_room()`
  §15s fix in `adm/simul_efun/message.lpc` survived reformatting intact.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风归** (male, id `qinretst`), reaching the actual starting room
  (南城客栈), `look`/`score`/`quit` all correct, including the
  intentional "new account needs 30 min online, confirm deletion?"
  quit gate.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings). **Full registration + login succeeded end-to-end
  under WASM too** — real Chinese name **秦风网** (id `qfwasmb`), through
  gb/site-choice/new/id/name/password/email/gender, landed in the real
  starting room (南城客栈), `look` rendered the actual room, and the
  quit-deletion confirmation gate (`y`) worked correctly. One cosmetic-
  only WASM artifact noted: the "您目前连线的地址是：" (your current
  connection address) line displayed a blank IP under WASM instead of
  the port/host shown natively — a visible symptom of the same
  `query_ip_number()` WASM limitation documented elsewhere, but here
  it's purely cosmetic (blank display) rather than gating — this lib's
  registration/login path does not actually branch on the IP string's
  format, so the login itself is unaffected.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban gates** —
   `adm/daemons/band.lpc`: added `is_local_ip(string ip)` helper (127.*,
   empty/non-string, or non-dotted-quad => local) and short-circuited
   `is_banned()`, `create_char_banned()`, `is_strict_banned()` to
   `return 0` for local IPs. (Shipped ban lists empty — defensive
   standard patch. The `check_ip_()` DNS-mirror gate was already
   neutralized in an earlier pass.)
2. **Uptime startup gate**: none in this lib.
3. **Anti-flood throttles exempt loopback** — `adm/daemons/logind.lpc`:
   (a) `logon()`'s per-IP concurrent-connection cap (`logon_cnt > 8`,
   was ~L186) now skipped for local IPs; (b) the `#ifdef MAX_LOGIN`
   per-IP multi-login cap in `get_id()` (was ~L491,
   `allow_multi_login`) now skipped for local IPs. KEPT: the
   new-account 30-minute quit-retention window in `cmds/usr/quit.lpc`
   (game design; wizards are exempt from it anyway).
4. **Admin account seeded** — id `fluffos`, password `Mud@2026`, 浮浮
   (male), via the real flow (`gb` → `1` 进入 → `new` → id → name →
   password ×2 → email → gender). Granted `(admin)` via
   `adm/etc/wizlist` (`fluffos (admin)`; file previously lacked a
   trailing newline — rewritten with one so the appended line parses).
   NOTE this lineage forces wizards to set a separate 巫师专用密码 on
   first wizard login (must contain upper+lower+other chars, differ
   from the normal password): set to `Wiz@2026`. So fluffos login is:
   normal password `Mud@2026`, then wizard password `Wiz@2026`.
   Verified after restart: 目前权限：主管天神(admin),
   `update /adm/daemons/band` → 文件顺利更新成功, `goto` worked, quit
   clean (wizardp exempt from the new-account deletion prompt).
   Save files: `work/data/user/f/fluffos.o` +
   `work/data/login/f/fluffos.o` (untracked, NOT gitignored —
   orchestrator must `git add`).

Retest: fresh registration (fluffos itself) reached 南城客栈 with
`look` correct; fluffos wizard re-login verified; debug.log free of
runtime errors.

## 深度功能测试（第二轮，2026-08-03）

之前只做过注册流程的浅层烟雾测试（fluffos 管理员账号那一轮），本
轮做了完整的 §10.7 深度功能测试：新注册一个真实中文名角色（秦风游
/ id `qindive`），进入起始房间南城客栈后，走遍朱雀大街东西两段、
长安鼓楼（中心广场）、南安大道等约十个城内房间，和店小二、疥顶小
僧等 NPC 对话，读了留言板上大量保留下来的历史开发者公告（任务修
改说明、bug 修复公告、系统更新通知），查看 `score`（属性面板正
常，食物/饮水槽满，没有 §8.9 那个坏 age 检查的问题），确认 quit/
reconnect 都正常工作。

**主要发现并修复：一个覆盖全城约 35 个 NPC 档案的路径失效 bug（新增
AGENTS.md §7.66）。** 移动进入朱雀大街东段（zhuque-e1）时，客户端
每次都收到一条毫无细节的通用提示"系统局部错误，请向巫师汇报。"——
这是驱动 config.fluffos 里 `default error message` 配置项的内容，
真正的报错细节只在 debug.log 里：`*call_other() couldn't find object
'/d/obj/cloth/sengyi'`，来自疥顶小僧（jieding.lpc）create() 里的
`carry_object("/d/obj/cloth/sengyi")->wear()`。往下查发现：这份档
案的 `d/` 目录下只有 `city/` 和 `wiz/` 两个子目录——`d/obj/`
`d/moon/` `d/nanhai/` `d/lingtai/` 等原版目录整个都不存在于这份快
照里。但"僧衣"（sengyi）"僧鞋"（sengxie）这两件衣物本身其实还在，
只是被挪到了 `d/city/obj/` 下（用 set_name() 核对确认是同一件东
西，不是巧合同名）。进一步全库搜索发现，同样的坏路径模式还出现在
另外 ~35 个 NPC 档案里，其中 `linen`（粗布衣）和 `choupao`（绸袍）
这两种衣物也同样在 `d/city/obj/` 下找得到对应文件——于是用二进制
安全的批量替换（保留每个档案原本的 CRLF/LF 混合换行，参照 AGENTS.md
§10.4 的教训）把这 58 个档案里的
`/d/obj/cloth/linen`→`/d/city/obj/linen`、
`/d/obj/cloth/choupao`→`/d/city/obj/choupao` 全部改正，`jieding.lpc`
的 sengyi/sengxie 两行手工改正。LPC 格式化器对 57 个档案确认"已经
是规范格式，无需改动"，`biaoshi.lpc` 一个档案被格式化器自己的安全
网拦下（token 不匹配，跟这次的改动无关，是这个档案本身早就存在的
问题，格式化器选择不写入而不是冒险破坏它——我的单行路径修复本身不
受影响）。重启驱动后重新走一遍之前会报错的房间，debug.log 确认
linen/choupao/sengyi/sengxie 这几个类别的错误全部消失。

同一次排查也确认了三个**真的无法修复、只能如实记录**的缺失内容（同
样在 AGENTS.md §7.66 里归档）：`hua_girl.lpc`（花店老板娘 NPC）的
`/d/moon/obj/luoyi`（月宫罗衣，整个 `d/moon/` 区域这份快照根本没
带）、`jieding.lpc` 自己的 `/d/obj/books-nonskill/book-qujing`
（取经书）、`dashi.lpc`（疥癞和尚）的
`/d/obj/weapon/staff/gangzhang`（钢杖）——这三样物件在整个档案里
搜不到任何同名同类的替代文件，不是路径写错，是内容本来就没有被打
包进这份存档，没有去凭空捏造替代内容。另外 `d/city/zhuque-e2.lpc`/
`zhuque-e3.lpc` 因为引用的 `/d/nanhai/npc/bonze`（南海观音座下的和
尚 NPC）同样缺失，报错形态不太一样（`room.lpc` 的
`make_inventory()` 没有对 `load_object()` 返回 0 做防御，表现为
`Bad argument 1 to EFUN call_other()`），但根因和上面完全一样。

关于"东门（east）连不通"的提示："你要去的区域还没有连通,请post通
知巫师。"——这不是 bug，是这个 lib 自己设计好的、对未搭建区域的优
雅降级提示（`cmds/std/go.lpc` 显式处理了 `load_object()` 失败的情
况），南城客栈的东门（指向 `/d/obj/heidian/city_heidian`，同样属
于上面提到的整个缺失掉的 `/d/obj/` 子树）就是这种情况——是内容缺
口，不是程序错误，未做处理。

**未覆盖范围（诚实记录，不假装测试过）**：本轮多次尝试对城内 NPC
发起战斗（先后试过 jieding、nukid/"小女孩"），但长安鼓楼一带有个
"土地"公告 NPC，几乎每次进入房间或稍作停留都会自动弹出一段很长的
历史开发者留言分页阅读，反复吞掉后续测试指令的时机，导致战斗指令
始终没能在一次干净的会话里送达并观察到结果；`nukid` 本身也有
`random_move` 漫游行为，不一定总在原地。技能学习（learn）、门派加
入、经济系统（购物、加工厂）同样因为时间原因没有实测，仅通过代码
review 确认了对应的 `cmds/`/`d/city/*` 逻辑存在，不代表已验证可
用。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2003/光辉岁月（master.c 约等于 xyj2000f）。
