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

**2026-08-26 addendum**: a separate onboarding pass considered
`git clone https://github.com/MudRen/txmud` ("天下MUD") as a candidate
new title and got as far as cloning it before a sanity check confirmed
it is this exact same codebase (identical `master.c` ACL mappings,
identical 47-entry `d/` domain list, near-identical `wiz/` wizard
list — see AGENTS.md §11's duplicate-archive log for the full diff
summary). Not re-onboarded; no `libs/txmud/` created.

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

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 2,526 处存活的 `replace_program(ROOM);` 相关行，与普查记录一致。
  除标准脚本删除外，手工修复三处不规则形状：`obj/wizard/
  roommaker.lpc` 模板、`wiz/zling/roommaker3.lpc`（3 处 `room_code`/
  `str` 拼接变体）、`wiz/zling/txmap.lpc` 的行尾注释变体
  （`replace_program(ROOM);  //`）。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## 深度功能测试第四轮 / Deep functional test round four (2026-08-20) — both previously-flagged gaps closed, both verified clean, no bug found

Native `build-debug` driver, tianxia's own `config.fluffos`, one continuous
`debug.log` watch (`log/debug.log`, baseline 227 lines) across the whole
session. Reused the existing test character `linhaoran`/林浩然 (id
`linhaoran`, password `TxTest2026#`) via `scripts` raw-socket sessions
(a purpose-built `tx_client.py`, not `tmux_mud.sh`), reconnecting between
short scripted segments per this project's standing practice, validating
each response before sending the next command.

### Gap 1 — real shop `list`/`mai` purchase: **VERIFIED, fully clean**

`std/char/dealer.lpc` (the generic "mai"/"buy"+"list" mixin, `init()`
registers both actions) gates `do_list`/`do_buy` on `is_day()` UNLESS
the vendor object sets `"sell_all_day"` — `谪仙楼`'s 跑堂 (the only shop
found in the prior round) doesn't set it, hence the earlier "打烊了"
closure. Grepped all ~85 `F_DEALER`-inheriting NPCs corpus-wide for
`sell_all_day`: 65 of them set it, including one in the immediate start
zone — `d/changan/npc/weaponboss.lpc` (兵器坊老板, "本店全天营业，敬
请随时光临" — literally advertises 24-hour business in its own greeting
text), housed in `d/changan/weapony.lpc` (长安兵器坊), reachable from
谪仙楼 in 10 moves (`west, north, east×7, north`) via the same 长安城
road network mapped in round two.

Live purchase, real character, real money: `score` before showed 298两
20文信用点credit; `list` printed the real price table (匕首/dagger at
五两白银); `mai bishou` → "你从兵器坊老板那里买下了一把匕首。"; `i`
confirmed 匕首(Bishou) now in inventory; `score` after showed exactly
293两20文 (5两 deducted, matching the listed price to the tael). This
is the actual `do_buy()` code path in `std/char/dealer.lpc` (`player_pay()`
→ `new(file)` → `move(me)`), not the coach-fare `player_pay()` call from
round two — confirms the shop system itself, not just the currency
plumbing underneath it. `debug.log`: zero new lines.

### Gap 2 — real combat to death/respawn: **VERIFIED, fully clean, one real death+respawn cycle completed**

Confirmed via direct code read (`cmds/std/kill.lpc`) before attempting
live: `kill` has no fight-vs-`accept_fight`-style safety net at all —
its only gates are `SAFE_ENV`, PROTECT_AGE (only relevant vs. other
*players*), `NO_KILL`/`is_master`, busy/netdead/edit-mode checks, and
`accept_kill()` (which `std/char/npc.lpc` implements to always return 1
for an ordinary NPC, only adding flavor text/master-guard-pileup
side-effects) — matching this session's established precedent that the
`fight` auto-concede gate does not extend to `kill`. Went back to 长安
武馆's 练功场 and used `kill mu ren` (the SAME 木人 training dummy that
safely auto-conceded under `fight` in round two — confirmed
`d/changan/npc/muren.lpc` has no `NO_KILL` flag) against the still-fresh,
still-unarmed, still only-`dodge`-level-1 test character (combat_exp 100
vs. 木人's 40000). Real combat ran automatically via `heart_beat` (no
repeated `kill` spam needed) — a real damage sequence (bruises → welts →
scratches → semi-conscious → "你的眼前一黑，接着什么也不知道了....") —
and the character genuinely died: "你死了。" + a real death broadcast
("【谣言】某人：林浩然被木人杀死了。"), moved to `DEATH_ROOM`
(`/d/death/gate`, 鬼门关).

Walked the real death-realm room chain north×3 (鬼门关→奈何桥→望乡亭→
阎罗殿, `d/death/{gate,gateway,road1,road2}.lpc`) into `d/death/npc/
yanluo.lpc`'s room, whose `init()` (guarded per the §7.112 fix
documented immediately above — re-verified this fix is the version that
actually ran, see below) started the real `death_stage()` `call_out`
chain. All 4 stages fired in order, one real ~5s tick apart, with no
duplication (confirming the reentry guard's `set_temp`/`delete_temp`
pairing is intact and doesn't misfire): 阎罗王's cold stare → flipping
through the『阴阳册』ledger → "你阳寿未尽，本王不能收留" → the final
"你回去吧" + fog line, immediately followed by `reincarnate()` (real
`gin`/`kee`/`sen` restored to half-max, `food`/`water` maxed) and a real
`move()` to `revive_loc[0]` (`/d/changan/badroom`, 土地庙) — landed
there correctly, `set_status_xuruo(30)` applied ("你感觉身体状况非常虚
弱。" / "你感觉身体非常的虚弱，一点力气也使不出来了。。。" both fired,
confirming the post-respawn debuff also ran for real). Post-respawn
`score`: no longer shows "鬼魂" (ghost) in the age line, "你共死亡一次"
correctly incremented, stats/hp bars correctly at half. A final clean
`quit` saved the post-death, post-respawn state.

`debug.log` monitored continuously through the ENTIRE sequence (shop
purchase, real kill, death broadcast, the 4-stage `death_stage()` chain,
`reincarnate()`, badroom landing, several reconnects, final `quit`) —
stayed at the exact same 227-line boot baseline throughout, zero new
lines. One incidental non-bug observation: `feature/damage.lpc`'s
`die()` calls `DEATH_ROOM->start_death(this_object())` (`DEATH_ROOM` =
`/d/death/gate`) but `start_death()` is never defined anywhere in the
archive (`grep -rn start_death` finds only this one call site) — this
call silently no-ops (FluffOS's default `call_other`-to-undefined-
function behavior, confirmed by the zero `debug.log` growth through a
real live death), so it has no observable effect and is not a bug by
this project's own standing "no error signature ⇒ not a bug" rule; the
real death-sequence trigger is entirely `d/death/npc/yanluo.lpc`'s
`init()`, reached by simply walking into its room, which is what
actually matters and is what this pass exercised.

Test character `linhaoran`/林浩然 kept as further playthrough evidence
(now: has died once, owns a 匕首/dagger bought at full price, resting at
土地庙 in a temporarily weakened state, 293两20文 credit remaining).
Saves: `work/data/user/l/linhaoran.o`, `work/data/login/l/linhaoran.o`.

### Fast standard-checklist confirmation pass (no changes needed, all already correct)

- **§7.90** (`config.fluffos` eval-cost): `maximum evaluation cost : 2000000` — already correct per the round-three note, unchanged.
- **§7.100** (`replace_program(ROOM)`): `grep -rn "replace_program(ROOM)"` → 11 hits corpus-wide, every one already commented out (`//`) — zero live occurrences, confirmed still clean since the round-three §7.100 sweep.
- **§7.111** (`file_name(error["object"])` null-guard): `adm/obj/master.lpc:206` already reads `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"` — correctly guarded, unchanged.
- **§7.112** (`death_stage()` reentrancy, every exit branch): only one file in the whole archive schedules a `death_stage()` `call_out` chain, `d/death/npc/yanluo.lpc` (fixed in the residual-gap closure documented immediately above this section). Re-read every exit branch by hand: the early `!ob || !present(ob)` return clears the guard when `ob` is non-null; the mid-sequence `++stage < sizeof(death_msg)` reschedule branch correctly does NOT clear the guard (by design — sequence still in progress); the final completion path clears the guard right after the `if/else`. All three exit paths handled correctly — and this is now also LIVE-verified (not just read), see Gap 2 above: exactly one clean 4-stage run, no duplicate firing.
- **§7.79** (bare 2-arg `addn()`/`addn_temp()`): zero call sites of either function anywhere in this archive — not applicable to this lib.
- **§7.108** (`reconnect()` calls `enable_commands()`): `obj/user/user.lpc`'s `reconnect()` (fixed in round three) still correctly calls `enable_commands()` as its first line — unchanged, and exercised live again this pass via the routine reconnects between test segments.

No bugs found this round — both explicitly-flagged gaps from round two/three are now fully closed by direct live verification (not just design reasoning), and the standard checklist is a clean confirm-only pass.

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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`wiz/aiai/treasure/treasure.lpc`。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 31 个，只在 #if 分支用的声明移进分支 0 个文件；改动 21 个文件，HEAD 与工作树各载入一次无回退（21 objects; HEAD PASS 17, tree PASS 17; regress 0; newly loading 0），这些文件的警告 65 -> 35。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮：FluffOS 不认的 `#pragma save_binary` 去掉，`int` 函数里光秃的 `return;` 改 `return 0;`（驱动本来就返回 0），没用的局部变量删去；手工：`wiz/zling/roommaker3.lpc` 两份 `special_props` 删去不用的前一份。能编译的文件警告清零；改动的 32 个对象在 HEAD 与工作树各载入一次：HEAD PASS 25，tree PASS 25，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。8 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/adm/daemons/combatd.lpc`（`gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。2 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。2 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/data/login/s/shutong.o`、`/data/user/s/shutong.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/jinghai/obj/saozhu`、`/obj/cloth`、`/obj/longsword`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 1 个（1 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/fork`（宏 `FORK`）←hy5，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/std/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 4 处）。改动：`/d/taxue/npc/obj/jiaokeli.lpc`（2 处）、`/obj/gift/dangao.lpc`（2 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/jinghai/npc/kangeng.lpc`:`ask_job`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 5 个文件里有 10 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/PURGE`、`nosave/crashes`、`nosave/addobj` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"job": (: ask_job :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 5 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：NPC 的称呼和提示里取到两个字而不是一个字。

本库 5 处（4 个文件）：`query("name")[..]` 5 处。例：`->name()[0..1]` → `->name()[0..0]`（`/d/changan/jiulou3.lpc:223`）；`->query("name")[0..1]` → `->query("name")[0..0]`（`/d/chengdu/npc/chunxier.lpc:43`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：4 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 4 处（2 个文件）：`if (strlen(tmp[i]) > 40) {`（`/std/banghui/smith.lpc:1017`）；`if (strlen(str) > 40) {`（`/std/banghui/smith.lpc:1033`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 3 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

