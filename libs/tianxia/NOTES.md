# tianxia — 《天下》Beta (archive #50, 天下.tar.gz)

Port: 40044. Status: **done** (boots clean, full registration flow
verified end-to-end including a real Chinese name, into an actual game
room).

## What this is

"《天下》Beta", credited throughout the source to author "Find" (also
seen as "发现号(Find@tx)" in a doc comment shared with the nitan170911/
nitan6 family's docs — same author lineage, different codebase). `adm/
obj/{master,simul_efun}` layout. The archive bundles a full MudOS driver
source tree at `raw/mud/MudOS/`, entirely ignored per this project's
standing policy — mudlib root is nested at `raw/mud/tx/`. ~7,741 raw
files, 5,786 `.lpc`/`.h` files after the `.c`→`.lpc` rename.

## Fixes applied

1. **AGENTS.md §15h, with a twist — TWO separate Chinese-detection
   functions in `adm/simul_efun/chinese.lpc`**, not just the usual one:
   - `is_chinese(str)`: standard GBK lead-byte check
     (`strlen>=2 && str[0]>160 && str[0]<255`) → standard CJK codepoint
     check (`strlen>=1 && str[0]>=0x4e00 && str[0]<=0x9fff`).
   - `valid_chinese(str)`: a **whole-string, byte-offset "commonly used
     character" GBK section-range check** (`section = tmp[i]-160`, valid
     range 16-87, gated to every other index via `i%2==0` to land on each
     character's GBK lead byte). This "commonly used character subset"
     refinement **cannot be faithfully preserved** under Unicode without
     a GBK→Unicode lookup table for exactly that subset — per this
     project's established practice for exactly this situation (see
     AGENTS.md §15h), simplified to a straight per-character CJK
     Unified Ideographs range check on every character, dropping the
     `i%2==0` byte-offset gate (every index is already one full
     character under UTF-8) and the "commonly used" refinement itself.
     A new lib-specific comment in the file documents this simplification
     explicitly, matching the project's existing style for this pattern.
2. **`adm/daemons/logind.lpc`'s `check_legal_name()`** (own inline copy
   of the same whole-string "commonly used character" logic, doesn't call
   `is_chinese`/`valid_chinese` at all):
   - Length bound `strlen<2 || strlen>12` (byte count, "1 到 6 个中文字"
     in the message) → `strlen<1 || strlen>6` (character count, matching
     what the message already promised).
   - The per-character loop (`name[i]<128` + `section=name[i]-160`
     range check + `i%2==0` gate) → single CJK range check per character,
     same simplification as `valid_chinese` above.
   - **Two byte-width surname slices found and fixed**, both AFTER the
     `check_legal_name` loop, both checking for lore-reserved surnames
     that conflict with in-game NPC factions (this lib has a whole
     "唐门"/Tang Clan zone under `wiz/qifan/tangmen/`):
     - `name[0..1] == "唐"` (a 2-BYTE GBK slice meaning "first
       character") → `name[0..0]` (1-character slice).
     - `name[0..3] == "踏雪"` (a 4-BYTE GBK slice meaning "first TWO
       characters") → `name[0..1]` (2-character slice).
   - Confirmed no other byte-width slices in this function beyond these
     two — the only other slice in the whole file, `id[1..]`/
     `id[0..<2]` in `check_wiz_legal_password`, operates on the
     ASCII-only English login `id`, unaffected by the byte/char
     distinction (verified by reading the surrounding function).
3. **Same GBK "commonly used character" section-range shape recurs in
   6 MORE files**, all unrelated to registration (guild-affiliation
   naming and weapon-smithing naming — gameplay features, not reachable
   during boot or registration): `std/banghui/banghui_auth.lpc`,
   `std/banghui/smith.lpc`, `std/char/smith.lpc`, `cmds/bangzhu/cdoor.lpc`,
   `cmds/bangzhu/mroom.lpc`, `cmds/bangzhu/cshort.lpc`. **Not fixed** —
   per AGENTS.md §15f's precedent, these are long-tail gameplay-content
   occurrences outside the boot/registration critical path; noted here
   for whoever picks up deeper §15h-pattern cleanup work on this lib.
4. **`adm/etc/preload`**: removed `/adm/daemons/network/dns_master` per
   AGENTS.md §15p (proactive, before first boot). Reviewed every other
   preload entry (`ftpd`, `smtp_d`, `ip_d`, etc.) for synchronous
   remote-connection attempts at `create()` time — none found (`ftpd`'s
   socket bind is local-listen-only and deferred via `call_out`, `smtp_d`'s
   `resolve()` call is already commented out) — no further preload
   trimming needed.
5. **NEW: a driver-version self-check (`adm/obj/check_config.lpc`)
   fatally errors during `simul_efun`'s own construction on this driver.**
   `simul_efun.lpc` does `private inherit __DIR__ "check_config";` — its
   `create()` walks a checklist of MudOS-era `#ifdef`/`#ifndef` driver
   preprocessor flags and calls `error()` if any mismatch, intended to stop
   the mudlib from running on an incompatible driver build. Two checks
   fail on this FluffOS build: `#ifdef __PRIVS__` (this driver DOES define
   `__PRIVS__`, alongside `PACKAGE_UIDS` — the old mutual-exclusivity
   assumption doesn't hold here) and `#ifndef __AUTO_TRUST_BACKBONE__`
   (this driver doesn't define it, but `master.lpc`'s own
   `valid_override()` already handles backbone-object trust explicitly).
   Since this check runs unconditionally inside `simul_efun`'s
   construction with no `catch()` around it anywhere, the unhandled
   `error()` kills the ENTIRE boot before a single object exists. Fixed by
   disabling just those two specific checks (wrapped in a
   `#ifdef DISABLED_LEGACY_..._CHECK` that's never defined), leaving every
   other check intact. **Worth checking proactively on any future lib from
   this same author/lineage** — a `check_config.lpc`-shaped self-test
   `inherit`ed directly into `simul_efun.lpc` or `master.lpc` is a new
   pattern class (distinct from the missing-apply gaps in §7): a
   mudlib-authored driver-compatibility gate that can be simply WRONG
   about what "compatible" means for a modern FluffOS build using a
   different package combination than the original MudOS target.
6. **NEW: three simul_efuns called pervasively but never defined
   anywhere in the archive** (AGENTS.md §15b-style gap, but new
   functions not seen in that catalog before) — all added to a new file,
   `adm/simul_efun/ansi_util.lpc`, included right before `chinese.lpc`
   in `simul_efun.lpc` (ordering matters — §8b):
   - **`clr_ansi(str)`** — strip ANSI color codes. Called by
     `valid_chinese()` itself (blocking `simul_efun`'s own compile) plus
     ~10 other files (weapon-naming, guild-naming, `nick` command).
     Restored using this lib's own `include/ansi.h` color-code table
     (same shape as the project's existing `remove_ansi()` precedent from
     the nitan family, adapted to this lib's own macro names — includes
     `HIK` which the nitan table didn't have, and omits macros this lib's
     `ansi.h` doesn't define).
   - **`chinese_number(int)`** — converts an integer to Chinese numeral
     text (e.g. `123` → `一百二十三`), called from **~90 files** across
     the whole codebase (currency amounts, dates, uptime displays) —
     including from `adm/simul_efun/time.lpc` itself, another file
     composed directly into `simul_efun.lpc`, so this gap alone was
     fatal to boot. This project's own `doc/efuns/chinese_number` doc
     file (found in the nitan170911 archive, credited "by 发现号
     (Find@tx)" — the SAME author as this lib) describes the exact
     contract; `nitan170911`/`nitan6`'s `adm/daemons/chinesed.lpc`
     (also Find-lineage) has a byte-identical integer-conversion
     algorithm already verified working in this project — ported that
     algorithm directly (int-only path; the string/arbitrary-precision
     path in the source lib's version isn't needed since every call site
     here passes an int).
7. **NEW: `changed_match_path(mapping, string)`, called from
   `feature/dbase.lpc`** (this lib's generic per-object property storage,
   inherited nearly everywhere) — never defined anywhere in the archive,
   but its signature is IDENTICAL to FluffOS's real `match_path()` efun
   (`mixed match_path(mapping m, string str)`, confirmed present in this
   driver's `core.spec`, and this lib's own
   `doc/driver/done-mudos` changelog explicitly lists `match_path()` as an
   efun the original MudOS driver added). "changed_" strongly suggests a
   thin local wrapper around the real efun (possibly for a since-lost
   local tweak), not a from-scratch reimplementation — restored as a
   straight passthrough to `match_path()`.
8. **`db_affected(db)`** (AGENTS.md §15b's documented gap, recurred
   verbatim here in `adm/daemons/databased.lpc`, 14 call sites) — stubbed
   returning `1`, same documented compromise as the catalog entry (every
   call site already checks `db_exec()`'s own return for the real
   success/failure signal).
9. **NEW: `query_bandwide()`, called UNGUARDED from
   `logind.lpc`'s `begain_enter()`** (`"/cmds/imm/bps"->main()`, on the
   path of literally every new connection, no `catch()`) — a genuine
   MudOS-driver efun for live port bandwidth stats
   (`cmds/imm/bps.lpc`'s own comment: "returns `float*` — `[0]` incoming
   data, `[1]` outgoing data") with **no FluffOS equivalent at all**
   (checked `core`/`sockets`/`contrib` specs). This was the bug that
   silently killed every connection attempt before the fix — matches
   AGENTS.md §15d's silent-crash-in-`logon()`-chain shape exactly
   (`new_conn_handler: logon() ... has failed, the user is disconnected`,
   zero player-visible output). Stubbed returning `({ 0.0, 0.0 })` — purely
   cosmetic admin bandwidth readout on the login banner, not gameplay.
10. **NEW: `query_shadowed()`, called bare from `feature/self.lpc` and
    `std/equip.lpc`** to ask "is THIS weapon object currently shadowed by
    a special-effect object (e.g. a glowing/elemental weapon effect), and
    if so which one" — never defined anywhere, but this driver's own
    `shadow(ob, flag)` efun already provides exactly this reverse lookup
    (`flag=0`: "either 0 will be returned, or the object that is already
    shadowing 'ob'"). Restored as `shadow(previous_object(), 0)` — NOT
    `shadow(this_object(), 0)`, since this resolves as a bare simul_efun
    call and `this_object()` inside it would be the SIMUL_EFUN object
    itself (AGENTS.md §15's `this_object()` footgun) — `previous_object()`
    correctly names the real caller during a simul_efun call. This was
    blocking `/obj/user/user` (the player body class) from compiling AT
    ALL, which silently broke character creation completion (`make_body()`
    returning 0) right after the Chinese name/password were accepted —
    the single most impactful fix in this lib's pass.
11. **NEW: a real (not simul_efun-family) pre-existing efun-misuse bug**:
    `daemon/effect/weapon_effect/bleeding.lpc` called the REAL efun
    `query_shadowing()` with **zero arguments**, but its signature requires
    one (`object query_shadowing(object)`). Fixed to
    `query_shadowing(this_object())` (correct here — this IS a real,
    non-bare call inside the shadow object's own method, no
    simul_efun-context issue).
12. **NEW variant of the "lossy iconv -c conversion eats a real newline"
    hazard** — found on 3 files independently flagged as lossy by
    `convert_lib.sh` (`d/shaolin/k_s24.c`, `d/tianshui/yidao1.c`,
    `d/tianshui/zahuopu.c`): all three have a `set("long", @LONG ... LONG)`
    text block whose CLOSING `LONG` tag ended up merged onto the end of
    the preceding Chinese text line (`...。LONG` instead of `...。\nLONG`),
    breaking the LPC text-block syntax (`error: End of file in text
    block`) since the closing tag must start its own line. Diffed against
    the raw pre-conversion bytes and confirmed: the ORIGINAL archive had a
    genuine `\xa3\n` (a GBK lead byte `0xA3` immediately followed by a
    literal newline `0x0A` — not a valid GBK 2-byte pair, since `0x0A`
    isn't a legal trail byte) right before the closing tag in all three
    files. `iconv -c` dropping this invalid sequence apparently consumed
    BOTH the bad lead byte AND the real newline that followed it (glibc's
    iconv skip-forward heuristic on an invalid multi-byte start advances
    by the presumed character width, not always just the one bad byte),
    merging the closing tag onto the text line. **Worth watching for on
    future libs**: any `error: End of file in text block` on a file that
    was ALSO flagged `LOSSY conversion` in `convert_lib.sh`'s log is a
    strong signal to check for exactly this — a merged closing-tag line —
    rather than assume a from-scratch content bug. Fixed by re-inserting
    the dropped newline before each closing `LONG` tag (verified against
    the raw file's byte layout, not guessed).
13. **AGENTS.md §8h recurrence**: `adm/daemons/convertd.lpc`'s Greek-table
    stray-trailing-backslash typo (`"α\",` should be `"α",`) — 45
    occurrences. No CRLF present, plain sed pattern applied directly;
    re-grep confirmed 0 remaining. (One unrelated, separate, non-fatal
    `warning: Unknown escape sequence '\额'` remains elsewhere in the
    same file — a different typo shape, warning-only, left as-is.)
14. **NEW: copy-paste duplicate `inherit ROOM;` in 12 near-identical
    room template files** (`wiz/qifan/tangbook/yaopu{2..9}.lpc`,
    `wiz/qifan/tangmen/yaopu{6,7,8,9}.lpc`) — each file had `inherit
    ROOM;` written TWICE (lines 3 and 9 in the affected files), causing a
    cascade of "Redeclaration of global variable" warnings followed by
    fatal "Illegal to redefine 'nomask' function" errors for every
    `nomask` method `/std/room` defines. Fixed by removing the duplicate
    line in each file (kept the first occurrence). Found by grepping
    `^inherit ROOM;$` count per file across the whole `tangbook`/`tangmen`
    template set — every file with count=2 was in the lpcc failure list,
    every count=1 file passed, confirming the diagnosis before fixing.
15. **Encoding straggler**: `data/emoted.o` (the emote-command-list save
    file) is NOT valid GB18030 even in the RAW pre-conversion archive
    (`iconv` fails at byte offset 994) — `file` classifies it as `data`
    (binary), so `convert_lib.sh`'s per-file guess for `.o` files (see
    AGENTS.md's "stragglers" check) skipped it entirely, leaving it as
    raw un-decodable bytes in `work/`. Manually converted with
    `iconv -f GB18030 -t UTF-8 -c` (drops the handful of invalid bytes) —
    this produced valid UTF-8, but `restore_object()` then threw a
    SEPARATE, genuine "Illegal mapping format" error (AGENTS.md §15m
    shape: the save data itself is structurally corrupted, not just an
    encoding artifact) — confirmed non-fatal to boot (caught by
    `master.lpc`'s own `preload()` catch wrapper) but leaves
    `emoted.lpc`'s `emote` mapping never initialized (partial `create()`).
    Per §15m's precedent, moved the corrupted file out of the way
    (`data/emoted.o.corrupted-orig`) so `restore()` finds nothing and
    returns cleanly instead of crashing — `emoted`'s emote-command
    feature now starts with an empty list rather than a half-initialized
    daemon. A full straggler sweep of the rest of `work/` (`.lpc`/`.h` via
    the documented `file -b` check, and all `.o` files via a UTF-8
    decodability check) found no other affected files.
16. **Minor content fixes found via the lpcc sweep** (all pre-existing,
    none touch the registration path):
    - `d/jinghai/shengji_quest.lpc`: bare `jinghai *shengji_quest=({...})`
      used an undefined identifier as a TYPE (should be `mapping`, given
      the array literally contains `(["key":val,...])` entries) plus 3
      missing `+` string-concatenation operators (`HIG"凤凰弓"NOR` should
      be `HIG+"凤凰弓"+NOR`) plus a missing `#include <ansi.h>` for the
      color macros. Fixed all three (this file is otherwise dead/orphaned
      — nothing else in the archive references it by path).
    - `adm/daemons/banghui_d.lpc`: `inherit F_SAVE;` was placed AFTER
      `#include <banghui.h>`, whose macro expansion declares real global
      variables — illegal ordering on this driver (inherit must precede
      any global variable declaration in the same compiled file).
      Reordered: inherit first, then the headers. Also added two missing
      local variable declarations (`int n; mixed *groups;`) in
      `buildup_new_guild()`. **Not fully fixed** — this file (guild
      creation, never preloaded, gameplay-only) has at least 2 more
      pre-existing bugs beyond this (a `string` value returned from an
      `int`-typed function, an undefined `tmp` variable) not chased
      further given zero registration-path relevance.
    - `std/banghui/banghui_auth.lpc`: removed one bare, nameless,
      initializer-less `protected mapping` declaration (a genuinely
      incomplete pre-existing edit — this whole file is dead/orphaned,
      nothing in the archive references it by path, so original intent
      is unrecoverable). Compiles further now but still has at least one
      more pre-existing bug (calls `save()` with no `inherit` providing
      it) — not fixed, dead code.

## What was NOT fixed (documented, not chased)

- **`adm/daemons/network/{ms,userid,pingtcp,name_server,mail_serv,
  netmail,telnetd,pingd,inetd}.lpc`** — old MudOS-era intermud/mail-relay
  daemon fragments, referenced from NOWHERE else in the archive (not in
  preload beyond the already-excluded `dns_master`, not called by path
  anywhere), missing headers (`uid.h`, `config.h`, `priv.h`, `post.h`,
  `mailer.h`, `daemons.h` — none of which exist anywhere in this lib).
  Genuinely dead template content bundled with this mudlib base, matching
  AGENTS.md §13's "missing content is a real archive gap" pattern.
- **~35 remaining lpcc failures in individual wizards' personal
  build/test directories** (`wiz/qifan/*`, `wiz/zling/*`, `wiz/aiai/*`,
  `wiz/saying/*`, `wiz/tag/*`, `wiz/gaoqi/test`) — a broad, unrelated long
  tail: undefined macros (`SAVE_EXTENSION` used without the header that
  defines it), undefined closures (functions referenced in a mapping
  literal that were apparently deleted elsewhere in the file), a
  `switch`/`case` with only a `default:` label (illegal on this driver —
  needs at least one real `case:`), a stray raw ESC byte (`0x1b`) leaked
  directly into one file's source, and several runtime "couldn't load
  referenced object" errors from missing/renamed NPCs. None are on any
  preload or registration-critical path (individual wizards' private
  work areas, not core game infrastructure) — per AGENTS.md §6b/§13,
  documented rather than fixed one-by-one.
- **`obj/npc/obj/steel_fork.lpc` (`inherit FORK;`) and
  `d/houjizhen/npc/obj/mask.lpc` (`inherit FACE;`)** — both reference
  weapon/armor base-class macros (`FORK`, `FACE`) that are defined
  NOWHERE in `include/weapon.h`/`include/armor.h`, and no
  `std/weapon/fork.lpc` or `std/armor/face.lpc` exists anywhere in the
  archive either — a genuine missing-content gap (AGENTS.md §13), not a
  copy-paste-to-an-existing-sibling case (§11) since no existing
  weapon/armor type is a close-enough semantic match to safely
  substitute. Affects 2 leaf item files plus the 2 NPC files that
  reference them (`obj/npc/jingang`, `obj/npc/hell_guard`).

## Re-verification pass (2026-07-23) — found and fixed a §15w bug, added `score` to the test

The original pass tested `look` but not `score` — re-testing the fuller
post-login flow surfaced `adm/obj/master.lpc`'s `log_error()` broadcasting
every compile *warning* (not just real errors) to the connected player as
a scary `编译时段错误：...warning:...` line (AGENTS.md §15w). Seen firing
10 times in a row for `/std/char.lpc:4: warning: Unknown #pragma, ignored`
during a routine registration, plus once more for `/std/room.lpc` — right
in the middle of an otherwise-correct session. Fixed by gating the
broadcast on the message not containing `"warning:"` (still always logged
to file). Re-verified with a fresh registration (id `qftxac`, real Chinese
name `秦风霜`, female) through `look`/`score`/`quit`: zero
`编译时段错误` lines this time, all three commands produced correct real
output (room description, full attribute/status sheet, clean save-and-quit
message), and `debug.log` stayed clean of `denied`/`cannot`/`undefined
function`/`bad argument`/`error in error handler`.

## Preload

`adm/etc/preload` reviewed entry-by-entry; only `network/dns_master`
excluded (§15p). No other daemon does a synchronous remote-connection
attempt at `create()` time.

## Interactive test result — full registration flow

`logind.lpc`'s actual chain (read directly, not assumed): `logon()` →
(no GB/BIG5 prompt shown — `GB_AND_BIG5` is undefined in this build, so
`encoding("gb", ob)` is called directly with no player input) →
`begain_enter()` (banner + player counts) → **English id prompt**
(`get_id`, lowercase-letters-only, 3-10 chars) → **y/n confirmation**
(`confirm_id`) → **Chinese name prompt** (`get_name` →
`check_legal_name()`) → **password** (`new_password` → `confirm_password`,
min 5 chars) → **gender** (`get_gender`, `m`/`f`) → **attribute
allocation** (`init_new_player` — type `str +5`-style deltas, or `0` for
random assignment, then `y` to confirm) → `set_new_player()` →
`enter_world()`.

Also checked: `driver` enforces a **30-second startup grace period**
(`if (uptime() < 30) { ...destruct(ob); }` in `logon()`) — a fresh
connection attempted before that window produces a single "还在启动中"
line and disconnects; not a bug, just needs the test to wait.

**Surname-conflict checks investigated**: `check_legal_name()` rejects
any name starting with "唐" or "踏雪" specifically because this game has
a whole "唐门" (Tang Clan) zone/faction (`wiz/qifan/tangmen/`,
`tangbook/`, `tangmiti/`) — this is a simple reserved-name collision
guard, not a deeper surname-selection or clan-affiliation mechanic tied
to character creation; no further clan-selection step exists in the
registration flow itself.

Verified in one continuous connection (`scripts/mudclient.py`):
`qinfengx` (English id) → `y` (confirm) → **`秦风`** (real Chinese name,
ACCEPTED) → `test1234` (password) → `test1234` (confirm) → `f` (gender)
→ `0` (random attribute assignment) → `y` (confirm attributes) →
successfully entered the actual game world at "松竹小院" (Bamboo
Courtyard), greeted by name by the NPC "小书童" ("秦风你好！师傅说你这两天
就会来的..."), `look` command worked, `quit` saved cleanly ("你决定离开
《天下》Beta，档案保存中......"). This is a complete, real, working
registration + login + basic gameplay loop, not just "reaches a prompt."

## lpcc sweep

5,786 files, final: **5,735 pass / 51 fail (99.1%)** (started at
5,717/5,786 = 98.8% before the fixes in items 12-14 above raised it).
Memory stayed healthy throughout both sweep runs (18-20GB free on this
23GB host, well below any concerning threshold). Remaining 51 failures
are the documented categories above (dead network daemons, individual
wizards' personal-workspace content bugs, the 2-file missing
FORK/FACE weapon/armor-type gap) — none on the boot or registration
path.
