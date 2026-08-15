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

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 5,786 `.lpc` files in `work/`:
   `{"total":5786,"written":5732,"wouldChange":0,"unchanged":36,
   "errors":18}`.
   **Found and fixed a genuine formatter bug, surfaced only by this
   lib's `obj/user/user.lpc`**: the formatter mis-tokenizes
   `copy(::query_skills())` — a `::`-prefixed (explicit-efun-override)
   call immediately following an opening `(` with no space — as the
   start of a `(: ... :)` closure literal. It rewrote
   `return copy(::query_skills());` into the syntactically broken
   `return copy (: : query_skills()\n);`, which failed to compile
   (`syntax error, unexpected L_FUNCTION_OPEN`) the first time any
   connected player's client called `query_skills()` (e.g. the `skills`
   command). **Fixed by hand-restoring the original
   `copy(::query_skills());` call** (confirmed via `git diff` against
   the pre-format version — no other change needed to this function).
   Re-verified via `lpcc_check.sh` (whole-lib batch compile): pass count
   unchanged at 5,735/51 fail, `obj/user/user.lpc` not in the failure
   list. The exact same `::fn()`-immediately-after-`(` pattern was found
   and fixed in **3 other libs this same pass** —
   `d/changan/chengxf.lpc`'s `if(::valid_leave(me,dir))` in this lib
   itself (a second, independent hit), plus `shujian2008`/
   `sjtx2`'s `cmds/leitai/npc_leitai.lpc` +
   `d/tanggu/npc/npc_leitai.lpc` (`if(::move(dest,silently))`) and
   `syxjl`'s `adm/object/bm.lpc`
   (`capitalize(::query("id"))`) — see those libs' own NOTES.md. All
   confirmed via `git diff` to be the identical `(: :` corruption
   signature, all hand-fixed and re-verified via `lpcc_check.sh` with no
   pass-count regression. **Worth flagging back to the formatter's own
   maintainers/AGENTS.md as a new bug class** (not something to
   rediscover per-lib): `X(::fn(...))` with zero whitespace between `(`
   and `::` is mis-lexed as a closure open.
2. **Native re-test against the rebuilt `build-debug/src/driver`**, after
   the fix above: booted clean (zero fatal errors). Full registration
   verified end-to-end via `mudclient.py`: id `txfmtb` → confirm →
   real Chinese name **`秦风三十一`** → password ×2 → gender `f` →
   attribute allocation (`0`/random) → confirm `y` → entered the game
   world at 松竹小院, greeted by 小书童 same as the original pass,
   `look` displayed the room, **`skills`** (exercises the just-fixed
   `query_skills()` — "你目前并没有学会任何技能", no crash) — `score` and
   `quit` also produced correct real output. `debug.log`: zero `error in
   error handler`/`denied`/`undefined function`/`bad argument`/`syntax
   error` lines. Also re-confirmed the driver's own 30-second startup
   grace period is still in effect (`uptime() < 30` in `logind.lpc`) —
   not a bug, just needs the test to wait, same as the original pass.
3. **WASM test**: boots cleanly through `Initializations complete`
   (only the expected caught missing-sockets/db-package preload errors
   for `ftpd`/`smtp_d`/`databased`, each wrapped in `master.lpc`'s own
   `preload()` `CATCH()`). **Could not get past this lib's own
   30-second startup grace period within `scripts/wasm_client.js`'s
   harness model**: the harness calls `fluffos_connect()` (which
   immediately invokes `logon()`, and thus the `uptime() < 30` check)
   right after boot/preload completes, *before* any `--idle`-paced
   `--send` line is dispatched — so no amount of `--idle`/`--timeout`
   tuning delays the connect itself, only the pacing of sends after it
   (tried up to `--idle 33` explicitly, no effect: the "《天下》Beta正在
   启动过程中" gate message is emitted as part of the very first output
   burst, before any input reaches the server). **This is not a wasm
   driver limitation or a mudlib bug** — the grace period is intentional
   mudlib behavior that the native test above waits out fine between
   separate shell commands — it's a harness/mudlib timing interaction
   specific to this one-shot wasm smoke-test tool's immediate-connect
   design. Did not force it further (e.g. by padding preload with
   artificial delay) per the task's "honest assessment over forcing a
   full playthrough" guidance. **Assessment**: boots cleanly under wasm;
   this specific harness invocation cannot exercise the login flow for
   this lib due to a startup-grace-period/connect-timing collision, not
   because of a real wasm incompatibility (query_ip_number() was never
   even reached to test).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Applied the
CORRECTED (fail-closed) loopback pattern throughout — loopback is
strictly `query_ip_number(ob) == "127.0.0.1"`, `== "::1"`, or a leading
`"127."` prefix; a non-string/empty/malformed IP is NOT treated as
loopback (the earlier WASM `query_ip_number()`/`resolve()` garbage-IP
bug this defensive fallback existed for is now fixed upstream).

1. **Loopback-allow**:
   - `adm/daemons/logind.lpc` `begain_enter()` (~line 127) — the
     `BAN_D->is_banned(query_ip_number(ob), 2)` IP-ban gate now
     short-circuits to allowed for loopback.
   - `adm/daemons/logind.lpc` `get_id()` (~line 192) — the
     `IP_D->identify_ip(arg, query_ip_number(ob))` wizard-address
     whitelist gate (self-registers a wizard's first-ever login IP as
     their allowed pattern, destructs on any later login from an
     unregistered address) now always passes for loopback. Without
     this, a wizard connecting from a second/different loopback-facing
     interface, or before their first-ever `identify_ip` self-registers,
     could be destructed — now moot for 127.0.0.1/::1.
   - `adm/daemons/ban_d.lpc` NOT touched directly — the call site gate
     above is sufficient (this daemon's `is_banned()` also handles
     id/name/word bans via the same function with a different `n`
     argument, so patching the call site keyed on the loopback IP is
     cleaner than threading a loopback exception through the shared
     multi-purpose function).
2. **Uptime gate**: `adm/daemons/logind.lpc` `logon()` (~line 62) —
   `if (uptime() < 30) { ...destruct(ob); }` (documented in AGENTS.md
   §1.3e as one of the known affected libs) now only applies to
   non-loopback connections; loopback connects immediately regardless
   of driver uptime.
3. **Anti-flood throttle**: none active — the only same-IP counter
   (`Same_Ip`/`MAX_SAME_IP` in `begain_enter()`) is already commented
   out in the original source (dead code), nothing to patch.
4. **Admin account seeded**: `fluffos`, registered through the real
   flow (`qinfengx`-style: id → confirm `y` → Chinese name 浮浮 →
   password → confirm → gender `f` → attribute alloc `0`/random →
   confirm `y` → entered 松竹小院). Granted `(admin)` via
   `/adm/etc/wizlist` (append `fluffos (admin)`; `securityd.lpc` only
   loads this file in `create()`, so the driver needed a restart for it
   to take effect — no hot-reload command found).
   **Password deviation, found and handled**: this lib enforces a
   SEPARATE, stricter password rule for any account whose status is not
   `(player)` (`WIZ_PASSWD_CHK` → `check_wiz_legal_password()`: >=10
   chars, must contain uppercase, lowercase, AND a symbol). The
   registration-time-only 8-char `Mud@2026` (fine under the *player*
   rule of >=5 chars) fails this the moment the account becomes
   `(admin)` and is not caught until the FIRST subsequent login attempt,
   where `get_passwd()` forces an interactive password reset before
   completing login. Handled it live: entered `Mud@2026Admin` (13
   chars, satisfies the rule, does not overlap with the id
   `fluffos`/its substrings per the similarity check) when prompted —
   this is now `fluffos`'s real login password, documented in
   README.md. Save files: `data/login/f/fluffos.o`,
   `data/user/f/fluffos.o`. Neither path is gitignored in this lib
   (its `data/` tree is already partly tracked, unlike several sibling
   libs) — a plain `git add` picks them up, no force-add needed.
   Verified: `update /cmds/usr/score.lpc` → 成功 (confirmed the
   self-update-destructs-silently quirk also applies here, same as
   `sjpl2`/others — not a bug introduced by this pass).
5. Retest: fresh registration (`qftxwasm`/秦风, deleted after test,
   including its `data/news/y100m1d15s452.p.1` "new player" announcement
   file) end-to-end into 松竹小院 with look/score/quit all producing
   correct output, immediately after boot (no 30s wait needed from
   loopback — confirms the uptime patch). `fluffos` login (with the new
   password) + `update` wizard command verified in a separate session.
   debug.log: no new `denied`/`undefined function`/`error in error
   handler`/`bad argument` lines from either session.

## Long-sit boot-watch pass (2026-07-24) — found and fixed a real
   WASM-only login blocker in the SQL-backed user database

`scripts/wasm_boot_watch.sh tianxia 200` (a real >3-minute sit, not the
usual 20-30s smoke test) caught a bug the quick registration test never
exercised: **every single connection under WASM was destroyed at
`logon()`**, before the id prompt even appeared. Root cause: this lib's
entire registered-user store is backed by a MySQL-ish daemon,
`adm/daemons/databased.lpc` (`db_connect`/`db_exec`/`db_close`/...), not
save files. Under WASM, the `db` package doesn't exist at all (AGENTS.md
§1.3c), so `databased.lpc` fails to *compile* (not just "fails to
connect") — every `DATABASE_D->...` call_other then throws `*No program
in object '/adm/daemons/databased'!`. `master.lpc`'s own `preload()`
already catches this for the initial preload attempt (cosmetic, harmless
— matches the already-documented "sockets/db absent, daemon just
absent" class), but `adm/simul_efun/user.lpc`'s `count_reg_user()` —
called UNGUARDED from `logind.lpc`'s `begain_enter()` (line 143, right
after the banner, on literally every connection) — re-triggers the same
compile failure with NO catch anywhere in the chain, and the resulting
error escapes all the way up through `logon()`, causing
`new_conn_handler: logon() ... has failed, the user is disconnected.`
Zero player-visible output (same silent-kill shape as AGENTS.md's
`query_bandwide()` fix, item 9 above, and the general §7.10/§1.3c
pattern) — this is exactly the class of bug the long-sit methodology
(§10.0) exists to catch and the quick smoke test structurally cannot.

**Fix** (`adm/simul_efun/user.lpc`, all 10 functions in the file —
`permit_add_cname`, `permit_reg_email`, `query_exceed_reg_time`,
`del_user_data`, `change_cname`, `count_reg_user`, `newbie_buildup`,
`newbie_reg`, `newbie_success_reg`, `query_register_station`): wrapped
every `DATABASE_D->...` call in `catch()`, degrading to a safe default
(0 / permit / no-op) when the database daemon is broken or absent,
per the standard §1.3c convention ("guard on `find_object()`/`catch()`
truthiness, absent ⇒ skip the gate") rather than inventing anything new.
Natively this is a no-op (the native driver's `db` package is present so
`databased.lpc` compiles fine and these calls succeed normally, verified
below) — the guard only changes behavior when the daemon is genuinely
broken, which under WASM it always is.

**Not fixed / flagged, not observed failing in this pass**: three OTHER
files also call `DATABASE_D->` directly (bypassing `user.lpc`'s
simul_efuns) and share the identical latent risk if reached:
`adm/daemons/paiming_d.lpc` (`db_query_bang_top_ten()` inside
`make_renyi_bang()`, only reachable via the `PAIMING_D->main()` cron job
that fires once daily at in-game 3am per `adm/etc/crontab` — didn't fire
during this test's ~7:50-8:03am window), `adm/daemons/pawn_d.lpc`
(`query_user_all_pob`/`query_count_user_pob`/`pawn_one_object`/
`retrieve_one_object`/`query_all_exceed_pob`, reached from
`logind.lpc`'s `restore_players_pawnstamp()` call gated on
`combat_exp >= 20000` — never true for a fresh character, so also didn't
fire), and `adm/daemons/renyi_d.lpc` (the bounty-quest system, a whole
family of `DATABASE_D->` calls, gameplay-only, not on the boot/login
path at all). None of these surfaced an actual error during this sit —
noted here for whoever next touches the pawn-shop/bounty/ranking
features so the same `catch()` treatment isn't rediscovered from
scratch, not fixed preemptively since nothing observed actually broke.

**Retest**: re-ran `wasm_boot_watch.sh tianxia 200` (full 200s) —
transcript now shows the SAME `databased.lpc` compile-error spew (that
part is unavoidable/cosmetic, matches the already-documented "sockets/db
absent" class) but this time followed by `错误讯息被拦截:` (caught) and
a `CATCH()` frame in `simul_efun.lpc`'s `count_reg_user()`, then the
full login banner completes normally and the connection sits cleanly at
the English-id prompt (`您的英文名字：`) for the rest of the 200s — no
disconnect, no further errors. Native sanity check (fresh registration,
real driver): id `wasmck`, Chinese name `测试客`, through attribute
allocation, into 松竹小院, `look` + `score` + `quit` all produced
correct output exactly as before; `debug.log` stayed clean (no
`denied`/`undefined function`/`bad argument`/error-in-error-handler
lines). Test save files removed afterward (not committed).

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib per AGENTS.md §10.7 (every
prior pass verified only registration + `look`/`score`/`i`/`quit`,
never real movement beyond the auto-entered start room, never combat,
never a sect/skill flow). Read `work/doc/help/newbie/{guide,new}` in
full first — `new` names the exact intended early path (start at 长安
谪仙楼, `east` to 后厨 to work for money, `mai`/`eat`/`drink` at the
inn, `bai`/`upgrade` to join a sect and learn) and `cmds` lists the
full command set. Native driver (`build-debug`), one character across
many continuous `scripts/mudclient.py` sessions (each session's own
close — no `quit` sent — is itself an unclean/net-dead disconnect;
NET_DEAD_TIMEOUT is only 60s here, `include/user.h`, so nearly every
reconnect below is a REAL exercise of either the prompt-reconnect path
or the full-timeout force-quit path, not a simulated one).

**Test character** (kept, not cleaned up, as playthrough evidence): id
`linhaoran`, Chinese name **林浩然** (male), password `TxTest2026#`.
Final state: at 谪仙楼 (长安, the `valid_startroom`-flagged start room),
member of 华山派 (5th generation, teacher 令狐冲), skill `dodge`
(纵跃闪躲之术) at level 1, inventory `Shoes`/`Cloth`/`Mailbox`, 298两20文
of the starting 信用点 credit balance (90-credit `qu hsp` coach fare to
Huashan). Saves: `work/data/user/l/linhaoran.o`,
`work/data/login/l/linhaoran.o`.

### Bug found and fixed (NEW class): `changed_match_path()`'s earlier "restore" used the WRONG efun semantics, silently breaking every 2+-level `query()`/`query_temp()` call lib-wide — including every bare directional movement command

**File:line of the fix: `adm/simul_efun/ansi_util.lpc`'s
`changed_match_path(mapping m, string str)` (originally added by a
prior pass, see item 7 of "Fixes applied" above).**

- **How this was found**: registered 林浩然, completed the mandatory
  `/d/wiz/welcome*` intro tutorial, landed at 谪仙楼, and simply typed
  `east` to walk into the kitchen per `doc/help/newbie/new`'s own
  instructions. It silently did nothing — no error, no message, just
  the driver's bare `config.fluffos` "default fail message" (`你想做
  什么?`). `go east` (the explicit form) worked perfectly. That
  asymmetry — bare direction fails, `go <direction>` succeeds — is the
  signature of this bug: `feature/command.lpc`'s `command_hook` has a
  fast-path specifically for bare directional typing,
  `environment()->query("exits/" + verb)`, that only bare typing goes
  through; `go` resolves its own destination independently in LPC
  after `env->query("exits")` (no slash), never touching this path.
- **Root cause**: a PRIOR pass on this lib (see item 7 in "Fixes
  applied" above) hit `feature/dbase.lpc` calling a bare
  `changed_match_path(mapping, string)` that was never defined
  anywhere in the archive, noticed its signature is IDENTICAL to this
  driver's real `match_path(mapping, string)` efun, and — reasonably,
  given the name and matching signature — restored it as a straight
  passthrough. That passthrough compiles fine, boots fine, and every
  *single-key* `query()`/`set()` call (the overwhelming majority) works
  fine through it, which is exactly why this survived several rounds of
  registration/`look`/`score` testing undetected. But the REAL
  `match_path()` efun implements ACL-style **longest-matching-prefix
  lookup over a FLAT mapping** (see `docs/efun/…/match_path.md` /
  `core/efuns_main.cc`'s `f_match_path` comment: "keys ended in '/' are
  assumed to match paths with characters that follow" — designed for
  TMI-style access-control mappings, not general-purpose data), while
  every call site in `feature/dbase.lpc` (`set()`/`query()`/`set_temp()`/
  `query_temp()`/`delete()`/`delete_temp()`, this lib's generic
  per-object property store, inherited nearly everywhere) obviously
  expects RECURSIVE DESCENT INTO A NESTED SUBMAPPING one `/`-segment at
  a time — visible directly in `set()`'s own code a few lines from each
  call site: `cont = changed_match_path(dbase, prop[0..r-1]); if
  (mapp(cont)) return cont[prop[r+1..]] = data;` only makes sense if
  `changed_match_path(dbase, "exits")` returns `dbase["exits"]` itself
  (the actual nested mapping), not an ACL prefix match. Under the real
  `match_path()` efun, a mapping storing `dbase["exits"] = (["east":
  path])` (the ordinary, ubiquitous room-`exits` convention — every
  room in this lib sets `"exits"` exactly this way) is NEVER matched by
  a lookup for `"exits/"` or `"exits/east"`, because match_path() never
  descends into `dbase["exits"]`'s VALUE — it only ever looks for a
  literal top-level KEY spelled `"exits/"` or `"exits/east"`, which
  doesn't exist. Traced by hand against the driver's actual C++
  algorithm (`~/src/fluffos/src/packages/core/efuns_main.cc`,
  `f_match_path`) to confirm this, not guessed.
- **Blast radius, all silently broken before this fix, all confirmed
  either by direct code reading or live reproduction**: every bare
  directional movement typed by a player, lib-wide, for every room
  (`feature/command.lpc`'s `"exits/"+verb` check) — the single most
  disruptive consequence, since it means no player could ever walk
  around by typing plain compass directions, only `go <direction>`,
  with zero error or explanation, in a Chinese-language MUD whose own
  `doc/help/newbie/new` literally instructs new players to type `east`
  bare. Also, by the same mechanism: `cmds/std/apprentice.lpc`'s
  `family/family_name`/`family/generation` sect-membership comparisons
  and the `score` display's whole "你投身师门…" sect-membership block
  (both live-reproduced below, now correct); the `"channel/chat_block"`
  chat-flood gate (`feature/command.lpc`); the `"env/brief"` auto-look
  toggle (`feature/move.lpc`); every per-quest state flag stored as
  `"quest/<name>/<key>"` (dozens of files under `d/*/npc/`,
  `d/*/*_quest.lpc`). None of these crash — they all just silently
  read back `0`/unset, which is why nothing in any earlier boot-log
  sweep or registration smoke test ever caught it.
- **Fix**: replaced the passthrough with a real recursive
  nested-mapping walk (`explode(str, "/")`, descend one segment per
  level, return the leaf — matching exactly what every caller already
  assumes):
  ```lpc
  // BEFORE:
  mixed changed_match_path(mapping m, string str) {
    return match_path(m, str);
  }
  // AFTER:
  mixed changed_match_path(mapping m, string str) {
    string *parts;
    mixed cur;
    int i;

    if (!mapp(m) || !stringp(str) || str == "")
      return 0;

    parts = explode(str, "/") - ({ "" });
    cur = m;
    for (i = 0; i < sizeof(parts); i++) {
      if (!mapp(cur))
        return 0;
      cur = cur[parts[i]];
    }
    return cur;
  }
  ```
  Confirmed `match_path()` (the real efun) has no OTHER call site in
  this archive (`grep -rn '\bmatch_path\b'` outside this one function),
  so this change cannot regress any genuine ACL-style use elsewhere —
  there isn't one.
- **Verified live, before/after, on a fresh boot each time**: before
  the fix, `east` from 松竹小院/谪仙楼/every room tried produced only
  the bare driver default-fail message, `go east` worked; `apprentice
  master` at 华山派's 有所不为轩 (see below) failed to even attempt the
  family comparison correctly (though this particular branch happens to
  short-circuit harmlessly for a player with no prior family). After
  the fix, restarted the driver and re-registered fresh: bare `east`,
  `west`, `north`, `south`, `northwest`, `out` etc. all correctly moved
  the character through 20+ distinct rooms across two zones (长安城
  and 华山派), the sect-join flow's family-name comparison and `score`'s
  "你投身师门华山派，从师令狐冲学艺" display both rendered correctly, and
  `debug.log` — checked after the ENTIRE session (registration through
  movement, sect join, skill learning, combat, quit, several
  reconnects) — gained **zero** new lines beyond the clean boot banner
  (stayed at 228 lines throughout).
- **This is a NEW bug class for AGENTS.md's catalog** — see draft below
  (not added to AGENTS.md directly per this task's instructions; the
  orchestrating session owns that file).

### Command-hook `private` / `command()`-self-call path: re-confirmed healthy, extends further than §8.3a's baseline note suggested

AGENTS.md §8.3a already lists `tianxia` as an empirical exception where
`private nomask command_hook` (`feature/command.lpc:40`, still `private`
in the current source) does not break ordinary *typed* dispatch, and its
addendum warns that exception does not necessarily extend to
`command()`-efun self-calls. This pass specifically hunted for and
exercised several such self-calls, live:

- `d/wiz/npc/tongzi1.lpc`'s `greeting()` — `command("tell "+id+" ...")`
  ×2 and `command("give book to "+id)`, fired via `call_out` from
  `init()` on the player's very first move into the tutorial room.
  **Worked**: 小书童's two greeting lines and the book hand-off all
  arrived correctly on a fresh registration.
- `d/wiz/npc/xianshi.lpc`'s `greeting()`/`tell_player()` — same shape,
  gating the tutorial's `enter` step. **Worked**.
- `d/changan/npc/chefu.lpc`'s `greeting()` — `command("hi "+id)` +
  `command("say ...")`, the 驿馆 sect-coach NPC's own greeting.
  **Worked**.
- `d/huashan_zx/master/master-lh.lpc`'s `attempt_apprentice()` — THREE
  chained self-calls (`command("smile")`, `command("say ...")`,
  `command("recruit "+id)`) triggered by the player's `apprentice
  master` command. **Worked end-to-end**: 令狐冲 smiled, spoke, and the
  `recruit` self-call completed the sect join (`score` afterward showed
  "你投身师门华山派，从师令狐冲学艺" — confirmed both the command()
  self-call chain AND the `changed_match_path` fix above, since that
  same `score` line reads `family/family_name` through the very
  function this pass fixed).

No new instance of the `private command_hook`/`command()`-self-call
failure (the shape documented for `shiji`/`xzyx`) was
found on this lib — every self-call path exercised here worked
correctly, consistent with `tianxia` already being listed as an
exception, now demonstrated on the `command()`-self-call axis
specifically (not just typed dispatch) rather than merely asserted.

### What was tested and confirmed working

- **Registration**: real Chinese name (林浩然) through the full
  mandatory `/d/wiz/welcome*` intro-tutorial gauntlet (小书童's gift,
  reading the book, the `大元仙师`/mirror `enter` sequence) into the
  real `START_ROOM` (谪仙楼) — matches `doc/help/newbie/new`'s own
  description exactly.
- **Movement/exploration**: walked (bare directional commands, post-fix)
  through 20+ rooms across 长安城 (谪仙楼→永泰路→驿馆→…→长安武馆→练功场,
  and separately →麒祥街→北安大道→…) and 华山派 (枫树林→…→紫霞宫门→
  前厅走廊→紫云影壁→曲径回廊→殿前石阶→草地→有所不为轩), reading room
  `.lpc` `exits` mappings directly to plan routes when the on-screen
  exit list alone wasn't enough context.
- **Safe sparring**: `doc/help/newbie/guide`'s documented distinction
  (`fight` = stops automatically when one side tires, no real death;
  `kill` = real, to the death) confirmed live against 长安武馆's
  练功场's 木人 (training dummy, `d/changan/npc/muren.lpc` — a training
  dummy is the canonical "spar first" target per AGENTS.md §10.7's own
  `accept_fight` guidance): `fight mu ren` (note: the NPC's real
  matchable id is the two-word `"mu ren"`, not `"muren"`) ran several
  rounds of real damage (bruises, stamina down to ~4/16 bars) and then
  correctly auto-conceded ("这场比试算我输了…") rather than killing the
  fresh, unequipped character.
- **Long-distance travel/economy**: 驿馆's 车夫 NPC `qu hsp` coach fare
  to 华山派 correctly deducted from the credit balance, ran a real
  multi-room scripted `call_out` sequence (车厢内→…→枫树林), and
  delivered the character to the correct LIVE zone
  (`/d/huashan_zx/guange3` — checked `d/changan/npc/che2.lpc`'s routing
  table by hand; confirmed it points at the live `huashan_zx` tree, not
  the `huashan_bak1` backup directory also present in this archive, so
  no §7.18-shaped stale-path bug here).
- **Skill learning (organic teacher path)**: `skills master` listed
  令狐冲's full teachable skill set; `upgrade dodge from master`
  correctly taught `dodge` (纵跃闪躲之术) at level 1, confirmed via
  `skills` afterward.
- **Sect join (organic NPC path)**: `apprentice master` (id `"master
  ling"`/`"master"`, NOT `"ling"` alone) against 令狐冲 at 有所不为轩
  succeeded via the `command()`-self-call chain documented above,
  confirmed via `score`.
- **Clean `quit`**: printed the correct "你决定离开《天下》Beta，档案
  保存中......" message, correctly went through the 3-second
  `start_busy`+delayed-`do_quit` path (a same-second follow-up command
  correctly got "你现在忙得很，无法做任何事情。" rather than double-firing
  quit); `debug.log` re-checked immediately after — zero new lines.
- **Unclean (net-dead) disconnect + reconnect, BOTH windows for real**:
  since this lib's `NET_DEAD_TIMEOUT` is only 60s (`include/user.h`),
  nearly every one of the many `mudclient.py` sessions in this pass
  that didn't end in `quit` (the tool always closes the raw socket, an
  unclean disconnect) naturally exercised one of the two paths:
  - **Prompt reconnect** (reconnecting inside the 60s window): several
    times, always printed `重新连线完毕。` (`obj/user/user.lpc`'s
    `reconnect()`) and resumed on the SAME live object at the exact
    room/state where the previous session left off (confirmed by
    `look` immediately after reconnecting showing mid-navigation rooms
    the character had no other way to be standing in).
  - **Full-timeout force-quit** (reconnecting after 60+ real seconds):
    happened repeatedly, simply as a byproduct of the real thinking/
    investigation time between test commands in this pass — confirmed
    via `work/log/USAGE`'s timestamps (a fresh `loggined` entry, not a
    silent reconnect, appears whenever the gap exceeded ~60s) that
    `user_dump(DUMP_NET_DEAD)`'s `command("quit 68#@")` path (itself
    ANOTHER `command()`-self-call, also confirmed working) correctly
    ran the real save-and-destruct flow and that the next login
    correctly restored the character at their last `valid_startroom`
    location with no state loss and no `debug.log` errors. This
    satisfies AGENTS.md §10.7 checklist item 8's "real full-duration
    net-dead timeout wait" cheaply, since 60s is trivially reachable
    within a normal investigation pass — no dedicated 15+-minute sleep
    was needed on this particular lib.
- **State persistence across a real clean quit + wait + reconnect**:
  waited ~13 real seconds after a clean `quit`'s save, then logged back
  in fresh — location (谪仙楼), sect membership (华山派/令狐冲), skill
  (`dodge` level 1), inventory (Shoes/Cloth/Mailbox), and credit balance
  all read back correctly identical to the pre-quit state.

### What was NOT verified live, and why

- **A real shop `list`/`mai` purchase** was attempted (后厨's 厨头 NPC)
  but that particular NPC isn't a shop; 谪仙楼's own 跑堂 shop is
  in-game-time-gated and was "打烊了" (closed for the night) for the
  whole of this pass — never found an open shop within the remaining
  time budget. Partially covered by a DIFFERENT real money transaction
  that exercises the same currency/payment code path: 驿馆's `qu hsp`
  coach fare (a real `player_pay()` call) correctly deducted funds —
  documented above — but this is not the same code as an actual
  `list`/`mai` shop interaction, so the shop system itself is
  explicitly unverified.
- **Real combat to death / respawn** was not attempted — only the safe
  `fight`-vs-`muren` sparring path (which cannot kill the player) was
  exercised live, per this task's guidance to use the lib's own
  safe-sparring mechanism before risking a real fight. Reaching a real
  `kill`-to-death cycle would have required either a deliberately
  unfair fight or significant additional leveling time neither of which
  fit this pass's remaining budget; death/reincarnation code
  (`AGENTS.md §7.24`'s bug class) was read but not exercised live on
  this lib.
- **WASM interactive playthrough**: this pass was native-driver only
  (per the task's own instructions); the existing WASM boot-watch
  coverage from the prior pass (above) was not re-run, since nothing in
  this pass's fix touches preload/boot behavior.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录干净正常，用的是这份档案自己记录的登录密码（Mud@2026Admin，不是标准的 Mud@2026——这份档案对巫师账号强制执行更严格的密码规则，首次管理员提升时会自动升级登录密码，这在它自己的 README 里有记录）——"目前权限：(admin)"。

## 深度功能测试第三轮 / Deep functional test round three (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复两处问题：

1. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明（`log_file()` 定义在
   `assure_file()` 之前，本驱动不容忍未声明的前向调用）；`cat()`
   两处 `write(read_file(file))` 补上 `|| ""` 空值防护（此文件本身
   已有 Find 加固过的 `valid_read()` 安全检查，未改动那部分逻辑）。
2. **`obj/user/user.lpc::reconnect()`（AGENTS.md §7.108，第八条独立
   确认的血统）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

`cmds/wiz/update.lpc`（§7.106）与 `master.lpc::log_error()`（§7.10
的 `"arning:"` 大小写无关写法）均已是正确写法，`maximum evaluation
cost` 已经是 `2000000`，均无需改动；本档案无 `adm/daemons/
closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026Admin`（此库自己文档记录
的巫师专用强密码，非标准 `Mud@2026`——首次尝试用标准密码触发
"密码错误！"并立即断线，重新连线用正确密码成功）登录确认
`目前权限：(admin)`，`update /adm/daemons/logind` 成功验证真实写入
权限。踢掉重复登录重连路径现场验证通过（见上）。`debug.log` 全程
干净（227 行，无真实错误）。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/obj/user/user.lpc`
