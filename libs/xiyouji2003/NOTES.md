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

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD`、`J_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 37 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 105 live occurrences deleted: 104 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). No already-commented-out instances found. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40075.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## Round-four gap-closing pass (2026-08-23): combat / learn / 拜师 / buy

Closed the four items this lib's earlier round explicitly left
"未覆盖" (code-reviewed only, never live-tested): the 土地 news-daemon
pagination obstacle (`adm/daemons/newsd.lpc::auto_notice()`, a
call_out-driven periodic broadcast to ANY connected player with unread
news, not room-specific as the earlier round assumed) was worked around
by auto-detecting its `未完继续...(ENTER 继续下一页，q 离开，b 前一页)`
prompt and sending `q` to dismiss it before the next scripted command.

**Real bug found and fixed — §7.66 addendum, 49+12 files, 165 sites**:
while routing around the 土地 NPC, hit the exact §7.66 "missing `/d/obj/`
shared-item tree" crash class on several DIFFERENT NPCs than the
original pass covered (`youxia.lpc`'s `xijian` sword, `bing.lpc`'s
`bingfu` uniform, `sengren.lpc`'s `sengyi`, etc.) — but this time also
found that **`dashi.lpc`'s `/d/obj/weapon/staff/gangzhang`, previously
declared "genuinely gone" in AGENTS.md §7.66, is NOT actually gone**: a
byte-for-byte `set_name()`-verified match (`钢杖`) sits at
`/obj/weapon/staff/gangzhang.lpc` — the top-level, non-`/d/`, generic
weapon-class library this lineage also ships. Auditing every `/d/obj/`
reference in the whole archive (161 unique path strings) against BOTH
recovery locations (`/obj/...` with the leading `/d` stripped, and the
already-known `/d/city/obj/...` relocation) found **49 more recoverable
under `/obj/...`** and **12 more recoverable under `/d/city/obj/...`**
beyond what the earlier pass had already fixed — all verified by
matching `set_name()` between the broken reference and the candidate
file before touching anything, never by filename alone. Swept via a
binary-safe literal-string substitution (preserves each file's own
line endings), 89 files / 165 replacements total. `lpcc --batch`
before/after: **2322/277 (89.3%) → 2436/163 (93.7%)** with **zero new
failures** among the touched files — every remaining FAIL in a touched
file traces to a separate, still-genuinely-missing item in the same
`create()` (e.g. `yulinjun.lpc` now compiles past its fixed
`jingua` hammer but still fails on an unrelated, still-missing
`/d/obj/armor/tongjia`). Full addendum with the detection-rule
correction filed under AGENTS.md §7.66.

**Combat (item 1) — CONFIRMED WORKING, live.** `fight <target>`/real
combat both exercised. The `fight` "safe spar" path itself was blocked
for the two nearest peaceful NPCs (`jieding`/`nukid` in `d/city/zhuque-e1`)
by a related, ALREADY-documented, genuinely-unfixable content gap (see
below) that also turned out to have a nastier consequence than the
earlier round realized: `std/room/room.lpc`'s `make_inventory()` loop
over a room's `objects` mapping has no per-entry error isolation, so
ONE NPC's `create()` throwing (e.g. `jieding`'s `book-qujing` load)
silently voids EVERY subsequent NPC in that same room's spawn list for
the rest of the driver's uptime — `jieding` AND `nukid` both, even
though `nukid` itself has no missing-content problem at all. Also
confirmed this crash reproduces on every occasion the room falls out of
the driver's live-object cache and gets recreated (not a true
one-time-only cold-start cost as an earlier working theory this
session assumed) — routing around it long-term isn't reliable; picking
a target NPC with a verified-clean spawn chain is. Pivoted to `bing`
(city guard, `d/city/npc/bing.lpc`, verified clean after the §7.66
addendum fix above) at the west gate (`d/city/ximen`), reached via
`goto` on the admin account: a full, real (non-spar — `bing`'s
`can_speak` apparently false, so `fight` took the direct-`kill_ob()`
branch) combat exchange ran to completion — multiple attack/defend
rounds with real damage numbers on both sides, ending in the admin
character's death. **Confirms the combat resolution mechanism itself
works correctly, no crash in the fight/damage code path.**

**NEW, severe content gap found via that same death — `/d/death/gate`
(`DEATH_ROOM`) does not exist anywhere in this archive; EVERY player
death crashes.** `feature/damage.lpc::die()`'s
`this_object()->move(DEATH_ROOM); DEATH_ROOM->start_death(this_object());`
(same unguarded shape already catalogued as AGENTS.md §7.96) throws
`*call_other() couldn't find object '/d/death/gate'` on the second line
— confirmed live via `debug.log`. This is the SAME root cause as the
already-documented `/d/` zone gaps (only `d/city/` and `d/wiz/` survive
in this snapshot at all — `d/death/` never shipped, and `grep -rl
start_death` finds zero implementations anywhere in the archive), so
per this lib's own established policy this is recorded as a genuine,
unfixable-without-fabricating-content gap, NOT patched — there is no
real death/resurrection room anywhere in the archive to route to
instead. Worth flagging as more severe than it first looks: this is
not the "benign shared-lineage no-op" shape noted elsewhere in this
project's cross-lib findings (where `DEATH_ROOM` exists as an object
but merely lacks a `start_death()` method) — here `DEATH_ROOM` doesn't
resolve to an object AT ALL, so death is a hard crash on this specific
snapshot, for every character, every time. **Side effect discovered the
hard way**: the crash happens AFTER the standing 30-real-minute
new-account retention window is what actually protects a save file
across a disconnect (`cmds/usr/quit.lpc`'s `force_quit()`, gated on
`me->query("mud_age") < 1800`, no `wizardp()` exemption despite an
earlier session's note to the contrary) — combining a fresh sub-30-
minute test session with this crash's abrupt link-loss cost the
project's own persistent admin test account (`fluffos`) its save file
twice this session. Re-registered a third time and left a background
connection holding the line open past the 30-minute mark before
`quit`-ing cleanly to re-establish it long-term (same credentials as
before: id `fluffos`, password `Mud@2026`, wizard password `Wiz@2026`,
granted via the pre-existing `adm/etc/wizlist` entry which was never
touched). **Lesson for future sessions on this lib**: don't `fight`/
force death on a short-lived test connection here — any real death
crashes before `move()`/`start_death()` complete, and if that
connection then also drops abnormally before 30 real minutes of total
`mud_age`, the account is gone, wizard or not.

**Skill learning (`learn`, item 2) — mechanism confirmed non-crashing,
full success not reachable.** `learn <teacher> <skill>` against
multiple live NPCs (`jieding`) consistently returned the correct,
graceful `notify_fail` messages (`"你要向谁求教？"` when the teacher
wasn't present/found, matching real room state each time) — no crash,
no undefined-function trace, in any of several live attempts. Reading
`cmds/std/learn.lpc` in full: the teacher-gate logic
(`is_apprentice_of`/family-match/`recognize_apprentice`) is intact and
consistent with the rest of this lineage. Completing an actual lesson
requires an accepted apprenticeship first (see below), which this
snapshot's surviving content cannot produce — same root cause, not a
separate bug.

**Sect/clan joining (拜师, item 3) — mechanism confirmed non-crashing,
but genuinely unreachable in this snapshot's surviving content.**
`apprentice <target>` was live-tested against `jieding` (correctly
rejects: target has no `family`) and reaches the real accept/pending
flow against a real family-holder. Traced the full accept path: when
the target NPC is not itself a connected player, `cmds/std/
apprentice.lpc` calls `ob->attempt_apprentice(me)` to let the NPC decide
whether to accept — **and in this ENTIRE archive, `attempt_apprentice()`
is defined in exactly ONE file, `d/city/npc/shubao.lpc` (秦琼,
"将军府" sect master) — and that file is never placed in any room's
`objects` list anywhere in the archive** (confirmed: `grep -rn
'"shubao"'` outside its own file returns zero hits). Every OTHER
family-holding NPC that IS actually reachable (`d/city/shangshu/npc/
shangshu.lpc`, family "朝廷", confirmed reachable via `d/city/zhuque-e2`
→ south → `shangshu/gate` → east → `yuan` → east → `keting`) has no
`attempt_apprentice()` override, so `ob->attempt_apprentice(me)`
call-others into nothing (silently returns 0, no crash — confirmed the
non-crashing part live), and the player's request just sits in
`pending/apprentice` forever with no NPC-side code path that will ever
accept it. **This is content-authoring, not a shared-mixin bug**:
checked sibling `xyj2000f` (closest relative per this lib's own lineage
note above) — its `feature/apprentice.lpc` has NO default
`attempt_apprentice()` either, and instead DOZENS of individual sect-
master NPCs across `d/nanhai`, `d/xueshan`, `d/moon`, `d/qujing/*`,
`d/lingtai`, `d/death`, `d/jjf`, `d/sky` each hand-author their own
`attempt_apprentice()` with custom dialogue — confirming every reachable
sect master is SUPPOSED to have one, hand-written per-NPC, and this
snapshot's surviving city-zone content (only `d/city/`+`d/wiz/`, per
the well-established missing-zone finding above) simply never included
one for `shangshu` (or `d/city/misc/npc/bing.lpc`'s "将军府" family,
or `d/city/quest/biao/npc/robber.lpc`'s, both also missing the
override). Not fixed — adding a plausible `attempt_apprentice()` body
to `shangshu.lpc` would mean inventing game-design content (what the
NPC says, whether/how it decides to accept), which is exactly the kind
of judgment call this lib's own standing scope policy prohibits.

**Shop purchase (`buy`, item 4) — mechanism verified sound by code
read; live purchase blocked by pre-existing content gaps on the
specific vendors reached, not by any new bug.** Read `cmds/std/buy.lpc`
and `feature/vendor.lpc` in full: price calculation, `can_afford()`
gating, and the `owner->complete_trade(me, item)` item-transfer call are
all internally consistent and call real, defined methods. Noted one
harmless pre-existing dead call: `buy.lpc` line 98 calls
`owner->compelete_trade(me, item)` (note the typo — extra `e`) AFTER
the real `complete_trade()` already ran; this method is never defined
anywhere in the archive, so it's a silent no-op call_other (confirmed:
call_other on an undefined method returns 0 without crashing, same as
the `attempt_apprentice()` case above) — not fixed, since it has zero
observable effect on the transaction either way and "fixing" it would
require guessing what a second, currently-nonexistent post-trade hook
was originally meant to do. Live-tested `buy N from <vendor>` against
three different vendor NPCs (`wangsao`/miantiao noodles, `cuihua`, and
attempted `laowei`/`bag`): the first two both have a genuinely-missing
`/d/obj/cloth/skirt` clothing item in their OWN `create()` (same §7.66
class, confirmed in this session's miss-list, not fixable), which
crashes their spawn before the vendor NPC ever exists to sell anything
— correctly reproduces the "target not found" `notify_fail` on `buy`,
no crash. Also confirmed a fresh, newly-registered character starts
with zero money (`score` shows "钱庄存款：目前是个穷鬼" — "pauper"), so
even a fully-reachable vendor would additionally need a funded test
character to reach the actual `can_afford()`/payment code path — noted
as unverified-live per this lib's own standing policy (§10.7 checklist
item 6) rather than silently presented as fully tested. No item-
processing/加工厂 mechanic exists anywhere in this archive at all
(`grep -rl 加工厂` across all `.lpc`/`.h` files returns zero hits; the
phrase only appears in `doc/help/master_job` and two `doc/help/story/*`
narrative files, describing a mechanic near "泾水桥南" that has no
corresponding room/NPC file anywhere in the snapshot) — genuine missing
content, not a bug, consistent with this lib's other confirmed
missing-zone findings.

## AGENTS.md §7.19 sweep (2026-09-01): false positive, not fixed

Flagged by the corpus-wide scoping scan as sharing the `mhxy`/`wuhanzhan`
`enable_player()`-reentrancy-from-`init()` shape (`feature/command.lpc`
does define an `enable_player()` wrapper around the raw
`enable_commands()` efun, and `feature/damage.lpc`'s `revive()` /
`cmds/std/sleep.lpc`'s `wakeup()` do legitimately re-invoke it while
`living()`), but the actual reachability leg never exists here: a
body-aware static scan of every `init()` function in this lib (354
`init()` bodies total, two independent regex passes) found **zero**
cases of `init()` calling `setup()`/`reset_me()`, directly or
indirectly. The naive whole-file grep that the original scoping scan
likely used (`file contains both "void init()" and "setup()"`)
over-matches here: several `d/city/*.lpc` room files (e.g. `proom.lpc`)
call `setup()` from `create()` and separately define an `init()` that
only does unrelated `add_action()` calls -- same function names, same
file, but no call edge between them. Same false-positive pattern already
ruled out for `shzs`/`xzyx` earlier in this sweep (see the sweep's
top-level memory doc). No fix applied.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/taskd.lpc` 在新进程里加载，HEAD 通过 0 个、工作树通过 0 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`std/weapon/lance.lpc`、`std/weapon/katana.lpc`、`std/weapon/stabber.lpc`、`std/weapon/club.lpc`。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xiyouji2003 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`：共改动 411 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：389 -> 389 通过，无回退。
手工：`adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`job/merchant/chaomai/npc/obj/check.lpc` 进货 `jinhuo all` 时 `if (... used_money < 0) used_money == 0;` 是比较不是赋值，钱数溢出成负数时没有归零、下一行"帑钱不足"的检查也就拦不住；改成 `=`。`std/weapon/club.lpc` 等四个兵器基类的 `actions` 见同日的兵器函数指针一节。

启动时警告 94 -> 0；新进程登录正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 1 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 2 -> 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：
  - `adm/daemons/diablod.lpc`、`toptend.lpc` 各自多声明了一个从未使用的 `nosave mapping dbase`，与 `F_DBASE` 的重名；删去。
  - `std/char/kzznpc.lpc` 的 `remove()` 改 `void`，与 `feature/move.lpc` 一致。
  - `yaoguai_type` 重复声明、`alias.lpc` 的 `last_time` 照同源各库修。
  - 改动的 12 个对象 HEAD 与工作树各载入一次，无回退。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。8 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

30 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`huntianqigong`→`huntian-qigong`（`baguazhou`、`buddhism`、`dao`、`dengxian-dafa`、`dragonforce`、`duoqing-force` 等 34 个文件）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`huoxue-force`→`huaxue-force`（`baguazhou`、`buddhism`、`dao`、`dengxian-dafa`、`dragonforce`、`duoqing-force`、`fofa`、`gouhunshu`、`huntian-qigong`、`huomoforce`、`jiuyin-xinjing`、`lengquan-force`、`lotusforce`、`moonforce`、`moonshentong`、`ningxie-force`、`pansi-dafa`、`pingtian-dafa`、`seashentong`、`taiyi`、`taoism`、`tonsillit`、`wuneng-force`、`wuxiangforce`、`xuanhu-shentong`、`xuanhu-xinfa`、`yaofa`、`zhenyuan-force`、`zhiqing-spells`、`zixia-shengong`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

61 个文件、82 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/cloth/pink_cloth`、`/d/gao/obj/changpao`、`/d/obj/armor/jinjia`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 56 个（55 个原来载入不了），没有退步；其余 6 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（1 个名字，最多的是 `freezing-force`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 0 个通过，其余 1 个停在别的错误上（`obj/insect/bingcan`：*No program in object '/obj/insect/bingcan'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 2 处、2 个文件：`hellfire_whip`→`hellfire-whip`（1 处）、`lahua-shou`→`lanhua-shou`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/std/room/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 17 处）。改动：`/adm/daemons/race/human.lpc`（1 处）、`/cmds/std/look.lpc`（1 处）、`/cmds/usr/inventory.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/city/npc/mjlady3.lpc`（3 处）、`/daemon/skill/qiankun-danuoyi.lpc`（7 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（1 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `taskd` 的 `create()` 读不到任务表就加载失败（2026-10-20，KB 06 §7.326）

`/adm/daemons/taskd.lpc` 的 `create()` 把 `/d/obj/quest/dynamic_location`、`dynamic_quest` 和 `/adm/daemons/find.map` 直接 `explode()`；本库没有 `/d/obj/quest/`，`job` 指令一加载守护就 `Bad argument 1 to explode()`。三处改成 `read_file(...) || ""`：任务表为空，`job` 列出空榜，其余循环（`sizeof(quests) / 2`）本来就按空表处理。加载检查：HEAD FAIL → tree PASS。wuhanzhan 的 `qqzqqjob.lpc` 是同一份代码，那里加了以后下一步是缺 `/adm/daemons/cron.lpc`，所以没有动。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `xupdate`：`file[sizeof(file)] != '/'` 永远为真（2026-10-21，KB 06 §7.343）

管理员扫描里 `xupdate`（xyj2000）从根目录 `/` 开始递归时报 `Bad argument 2 to foreach Expected: array Got: 0.`：`UpdateDir()` 用 `file[sizeof(file)] != '/'` 判断路径是否已经以 `/` 结尾，下标等于长度读到的是 0，条件永远成立，`/` 变成 `//`，`get_dir("//")` 答 0。改成 `file[<1] != '/'`。同一个写法在 `xrm`、`rm`、`rmdir1`、`rmhir` 里有 55 处，没有动：对普通路径新旧写法的行为相同，唯一改变的是 `xrm /`，旧写法让它死在第一个 `get_dir("//")`，改了它就能递归删光整个游戏目录。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 10 条注册（7 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/biaoju-e.lpc`（`do_yao`）、`/d/city/misc/chatroom2.lpc`（`do_jump`）、`/d/city/misc/npc/guinu.lpc`（`do_sell`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/daemon/skill/hubo.lpc`（`do_hubo`）、`/std/char/smith.lpc`（`do_buy`、`do_list`）。最多的函数名：`do_list` 2 处、`do_yao` 1 处、`do_jump` 1 处、`do_sell` 1 处、`do_vendor_list` 1 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。3 个文件里 6 处（`new`, `carry_object`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 3 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 3 个（新增可加载 1 个，回归 0 个）。
