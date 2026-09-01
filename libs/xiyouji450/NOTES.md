# 西游记450.rar → `xiyouji450`

- Archive: `archives/西游记450.rar` (archive #83, 3.0MB). Extracted root:
  `xyj/` (the archive's own top-level folder — a stripped-down "mirror kit"
  distribution, not a full site snapshot: bundles `mud.dat`, `start-xiyou`
  (+ `.BAK`), `mudos.exe`/`driver.exe` (Windows/SPARC prebuilt binaries,
  ignored — we use our own `build-debug` driver throughout), and a
  `readme` explaining how to stand up a **mirror** of the "XYJ" game —
  i.e. this archive is specifically packaged for someone else to host a
  second copy of an existing game, not the origin site's own live data.
  The mudlib source itself lives at `xyj/world/`.
- Self-identified name: `config.cfg`'s `name :` field reads `西游记`
  ("Journey to the West") — matches the archive's own title once decoded
  (was mojibake pre-conversion). No distinct in-game brand name beyond
  that (see the readme excerpt below — this is explicitly a "mirror" kit
  for the `xiyouji.org` game already represented in this project by
  archive #15, `xyj2000f`).
- Config: `xyj/config.cfg` (MudOS 0.9.20 format, standard directive set,
  no legacy `external_port_*` weirdness). Original `port number : 5555`,
  `address server port : 6665` (the readme says a real mirror should use
  `6666`/`6665` — irrelevant to us, we assign our own project port below).
- Port: **40078** (per task instructions: 40076/40077 reserved for
  archives #27/#82's concurrently-running agents at the time this pass
  started; TODO.md's own ledger showed "next free: 40076" before that
  reservation).

## Lineage: confirmed via diff (not assumed from title) — genuine sibling of the whole "西游记/mhxy" ES-II-derived family, closest specifically to `mhxy`(#19)/`mhxyqd`(#56), NOT a duplicate of any of them

Per the task's explicit instruction, all 5 already-processed
Journey-to-the-West-themed siblings' `NOTES.md` were read first
(`xyj2000f`/#15, `mhxy`/#19, `mhxyqd`/#56, `shenmo`/#73,
`xiyouji2003`/#81), then this archive's `adm/obj/master.c`,
`adm/simul_efun/chinese.c`, `adm/daemons/logind.c`, `adm/daemons/securityd.c`,
`adm/daemons/chinesed.c`, `adm/daemons/convertd.c` were diffed (raw
pre-conversion bytes, CRLF-normalized) against the corresponding raw files
of `xyj2000f` and `mhxy` before any conversion work began.

**Findings, by file:**
- **`adm/obj/master.c`**: 485 lines, differs from `mhxy`'s copy by only 2
  trivial lines (a local-variable-declaration/one-statement refactor
  inside `standard_trace()` — `string err, var;` + a separate `var=...`
  assignment vs. an inlined expression; functionally identical) — this is
  essentially the SAME master.c. Diffed against `xyj2000f`'s copy
  too: only difference there is one extra header line ("cracked by vikee
  2/09/2002 vikee@263.net", a redistribution-crack credit `xyj2000f`
  picked up somewhere along its own distribution chain that this archive's
  copy never had) plus the same trivial refactor. All three trace to the
  same "for ES II mudlib / original from Lil / rewritten by Annihilator
  (11/07/94)" root, with `mon@xiyouji`-credited additions (`standard_trace`,
  the `object_name`/`query`/`valid_bind` block) layered on top — i.e. this
  archive, `xyj2000f`, and `mhxy` all descend from the same
  "xiyouji.org" codebase lineage, this archive's copy being closest to a
  clean/uncracked state.
- **`adm/simul_efun/chinese.c`**: byte-identical to `mhxy`'s copy (only
  differs from `xyj2000f`'s copy by the same "cracked by vikee"
  header line plus a harmless reordering of the `chinese_number`/
  `to_chinese` function bodies).
- **`adm/daemons/convertd.c`** (the Greek-alphabet charset-conversion
  table): near-identical to `mhxy`'s copy (one whitespace/tab difference
  on a single line, plus the same header-credit-line difference vs.
  `xyj2000f`) — and, importantly, carries the SAME known §8h
  stray-trailing-backslash Greek-table typo (45 occurrences, see below).
- **`adm/daemons/logind.c`/`securityd.c`/`chinesed.c`**: all differ
  substantially from both `mhxy` and `xyj2000f` (different ACL
  tables, different banned-name lists, different registration-flow
  details, a much simpler `securityd.c` with `valid_read` unconditionally
  `return 1;` and dead/commented-out `exclude_read` logic) — this is
  expected: these are the per-site customization layer, not the shared
  engine core, and every sibling in this family differs here too.

**Conclusion**: genuine member of the same 西游记/xiyouji.org ES-II-lineage
codebase family as `xyj2000f`(#15)/`mhxy`(#19)/`mhxyqd`
(#56), sharing byte-for-byte-or-near-identical core engine files
(`master.c`, `chinese.c`, `convertd.c`), but with its OWN distinct
site-customization layer (`logind.c`/`securityd.c`/`chinesed.c`) and its
own game-world content tree (`d/`, `daemon/class/`) — **not** a duplicate
of any of them. Distinct again from `shenmo`(#73, "Neolith" mega-lib
fork) and `xiyouji2003`(#81, itself confirmed closer to `xyj2000f`
specifically) — those two were read but not diffed byte-for-byte here
since master.c/chinese.c already clearly separate this archive from them
by shared-lineage-but-different-generation reasoning documented in their
own NOTES.md.

**FLAGGED FOR LATER CROSS-CHECK (per task instructions)**: archive #82
(`西游记2006之最终幻想.rar` → `libs/xiyouji2006/`) was being processed by a
concurrent sibling agent while this archive was worked and could not be
diffed against here. A follow-up pass should `md5sum`/diff this archive's
`adm/obj/master.c`/`adm/simul_efun/chinese.c` against `libs/xiyouji2006/raw/.../adm/obj/master.c`
once #82 has landed, to see whether #82 is ALSO part of this same
xiyouji.org lineage (plausible given the shared "西游记" title and 2006 vs.
this mirror-kit's apparent late-90s/2002-ish vintage) or a separate fork.

## Status: DONE — boots clean, full registration + post-login-command flow verified end-to-end into the game world, multiple independent runs

## Fixes applied (proactive, before first boot, plus reactive fixes found via boot/registration/lpcc testing)

1. **Standard conversion** (`scripts/convert_lib.sh`): GB18030→UTF-8 on
   6,399 files (already_utf8=812, converted=5514, lossy=52,
   skipped_binary=20, 1 failed-to-auto-convert — see below), `.c`→`.lpc`
   rename (4,988 `.lpc` files), 459 literal `".c"` references fixed, 62
   local angle-bracket `#include <x.lpc>` → `"x.lpc"` conversions, 39
   files' `static`→`nosave`. Zero uppercase `.C` files found (checked
   proactively per §"Watch for uppercase .C").
   - **One file the auto-converter flagged as failed**:
     `cmds/imm/cast1.c` — genuinely truncated in the RAW archive itself
     (1062 bytes, cuts off mid-string inside `notify_fail(...)`, no
     closing quote/parens/semicolon/brace for the rest of the function or
     file — confirmed by inspecting the raw pre-conversion bytes, not an
     artifact of our pipeline). Converted what bytes exist with
     `iconv -c` so it's valid UTF-8 (won't corrupt anything downstream);
     left the resulting syntax error undiagnosed/unfixed since completing
     it correctly would mean fabricating the missing command logic
     (an admin-only `imm` command, not on any critical path) — documented
     here per §13's "don't fabricate missing content" policy, not fixed.
2. **§15p (standing policy): proactively excluded `dns_master` from
   `adm/etc/preload`** before the first boot attempt (found listed there).
3. **§15ai: the exact predicted "dns_master exclusion surfaces a second
   gate" bug, found and fixed**. `adm/daemons/logind.lpc`'s `encoding()`
   callback (right after GB/BIG5 selection) has a one-time
   ("`new_start==0`... only check for once") mirror-site IP-verification
   gate:
   ```lpc
   if(!find_object(DNS_MASTER) || !"/adm/daemons/band"->check_ip(
       DNS_MASTER->get_host_name(mud_nname()))) {
       log_file("shutdown", ...);
       shutdown(1);
   }
   ```
   Since `dns_master` is now never loaded, `find_object(DNS_MASTER)` is
   always 0, and the `||` short-circuits straight to `shutdown(1)` —
   this would kill the ENTIRE DRIVER PROCESS on the very first
   connection's encoding choice, every time. Fixed by changing `||` to
   `&&` so the whole IP-verification gate is skipped (not "failed") when
   the daemon is simply absent — matches §15ai's documented fix pattern
   exactly. Verified: `shutdown(1)` was NOT called across ~10 subsequent
   test connections after this fix.
4. **§15ac**: `include/net/ftpdsupp.h` used the bare `SAVE_EXTENSION`
   identifier (never defined anywhere in this lib) instead of this
   driver's real autogenerated `__SAVE_EXTENSION__` constant. `ftpd` is
   on the preload list, so this would have broken preload entirely (a
   `Cannot #include`-adjacent-shaped chain: `ftpd.lpc` → `net/ftpd.h` →
   `net/ftpdconf.h` → `net/ftpdsupp.h`). Fixed the one occurrence.
5. **§15h (project-wide, most important recurring bug)**: applied to
   `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK byte-range check
   `str[0] > 160 && str[0] < 255` → CJK Unicode codepoint range check
   `str[0] >= 0x4e00 && str[0] <= 0x9fff`; length bound `strlen>=2` →
   `strlen>=1`) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (bound `strlen(name) < 2 || > 12` → `< 1 || > 6`, matching the message
   text's own "一到六个中文字" promise; dropped the `i%2==0 &&` byte-stride
   guard in the per-character Chinese-check loop since every UTF-8 index
   is already one character). Verified via 3 independent real
   registrations with real Chinese given names (秦风/秦淮/张三/秦风 again
   post-fix) all correctly accepted through to the password prompt.
6. **§14**: upgraded `master.lpc`'s `valid_override(file, name)` to the
   3-arg `valid_override(file, name, main_file)` form, also allowing when
   `main_file == SIMUL_EFUN_OB || main_file == MASTER_OB` (defensive/free
   fix per the catalog; never actually observed to matter on a real boot
   here, matching the catalog's own note that this rarely bites in
   practice).
7. **§8h (recurring convertd.lpc Greek-table typo)**: `adm/daemons/convertd.lpc`
   had 45 lines shaped like `"α\",` (a stray trailing backslash escaping
   the closing quote, corrupting the rest of the file into one runaway
   unterminated string — this crashed the WHOLE BOOT the very first
   attempt: `error: Illegal character 0xce` at line 249 and cascading).
   Confirmed CRLF line endings, used the CRLF-aware fix
   `sed -E 's/\\"(,)?\r?$/"\1\r/'`; verified 0 remaining matches
   afterward and a clean reboot.
8. **§15w (log_error() broadcasting compile WARNINGS, not just real
   errors, to every non-wizard player) — the single highest-impact bug
   found in this pass, and a genuinely NEW manifestation worth noting**:
   `master.lpc`'s `log_error()` unconditionally showed the scary default
   error message (`你发现事情不大对了，但是又说不上来。`) to `this_player(1)`
   for EVERY compile diagnostic reaching that apply, warnings included.
   This was invisible during boot (preload only compiles a handful of
   daemons, no warnings hit a connected player there) but fired
   **26-27 times in a row** the FIRST time any character's `make_body()`
   ran — because `/obj/user.lpc`'s entire ~16-feature inheritance tree
   (`std/char.lpc` + `feature/*.lpc`) is never preloaded, so its ~26
   pre-existing soft warnings ("Unknown #pragma, ignored", "Unused local
   variable", etc.) all got lazily compiled and individually broadcast to
   the one connected (non-wizard) player mid-registration, right between
   the email prompt and the gender prompt. **This one took real
   diagnostic effort to pin down** because it looked exactly like a
   flaky/intermittent RUNTIME bug (present on some driver boots' first
   character, absent on others depending on incidental timing/whether
   `/obj/user`'s tree had already been touched) rather than a
   deterministic compile-warning-count issue — confirmed by cross-referencing
   the exact error COUNT (26) against the exact number of `warning:` lines
   in `debug.log` appearing right after "Accepting telnet connections",
   which matched precisely. Fixed exactly per the catalog: gate the
   player-facing broadcast on `strsrch(message, "warning:") == -1`
   (still logs everything to `home+"log"` regardless). Verified: 0
   spurious messages across 3 subsequent full registrations post-fix.
   - **Also hardened, as insurance, while investigating this** (per
     §15w's own related note that `error_handler()`'s "falls through to
     debug.log automatically" comment doesn't hold on this driver):
     added `catch(efun::write_file("/log/RUNTIME_ERRORS", trace));` at
     the end of `error_handler()`. Discovered in the process that
     `securityd.lpc`'s `valid_write()` asserted `objectp(user)` (via a
     bare `error()`) BEFORE its own `LOG_DIR`-write allow-check, which
     would have made even this insurance write silently fail for any
     caller whose `user` argument isn't a live object (e.g. deep in the
     driver's own error-unwind machinery) — reordered so the
     `/log/`-write-file allow-check runs first. (No real errors have
     occurred since the §15w fix, so `/log/RUNTIME_ERRORS` has stayed
     empty in every subsequent run — expected, it's forward-looking
     insurance, not evidence of a live bug.)
9. **§11-shaped copy-paste bug, `d/city/npc/duguoyin.lpc`**: this NPC
   (a gambling-den boss) is a near-verbatim clone of `d/city/npc/bookseller.lpc`
   (identical `buy_object()`/`greeting()` logic, confirmed via `diff`) but
   its `inherit` line was left as plain `NPC` instead of `F_VENDOR_SALE`
   — the base class that actually defines the `buy_object()` its own
   override calls via `::buy_object(...)`. Fixed by changing the inherit
   to match what the file's own content clearly needs (matching the
   established "match inherit to actual content" precedent, §11).
10. **§11-shaped stale content, 2 files**: `d/city/obj/dami.lpc` and
    `d/obj/food/dami.lpc` (two near-identical rice-bag food items, both
    still headed `// chicken_leg.c` — another copy-paste-and-never-renamed
    artifact) each called `init_unarmed(5)` in `create()` — a function
    that doesn't exist ANYWHERE in this lib (confirmed via `grep`), and
    `d/city/obj/dami.lpc` additionally `inherit`ed a bare `UNARMED` macro
    that's also never `#define`d anywhere (a hard syntax error, not just
    an undefined-function warning). Since no real implementation exists
    anywhere in the archive to restore, and it's peripheral non-critical
    content (a rice-bag item, not on any critical path), fixed by
    dropping the erroneous inherit/call rather than fabricating a
    function — `inherit UNARMED;`→`inherit ITEM;` (matching its own
    sibling's already-correct inherit) and removed both `init_unarmed(5);`
    calls.
11. **§15i (comment-eats-next-statement), `daemon/class/moon/moonshentong/shiyue.lpc`**:
    line 1 was `// 蚀月咒inherit SSERVER;` — the Chinese skill-name comment
    and the `inherit SSERVER;` declaration sat on the same physical line
    with no separating space, so `//` swallowed the whole line including
    the inherit statement, silently deleting it. This broke
    `offensive_target()` (defined in `std/sserver.lpc`, the file
    `SSERVER` points at) with "Undefined function offensive_target".
    Fixed by splitting the comment onto its own line and restoring the
    `inherit SSERVER;` as real code. **Checked broadly for recurrence**:
    grepped the whole lib for the shape `^//.*inherit [A-Z_]*;` (18 hits)
    and manually inspected every one — the other 17 are all genuine,
    deliberately-commented-out alternate/historical inherit lines with
    normal spacing (each such file has its own real, active `inherit`
    line elsewhere) — only `shiyue.lpc` had the actual merged-line bug.
12. **§8e (`tail()` is not a real efun on this driver)**: `cmds/wiz/tail.lpc`
    (an admin command, not on any critical path) called bare `tail(file)`.
    Reimplemented in plain LPC (`do_tail_lpc`, last-10-lines) per the
    catalog's standard pattern; needed a forward declaration (§8b — the
    new helper is called from `main()` before its own textual definition
    in the same file, same shape as `help()`'s existing forward decl one
    line above it).
13. **Missing shared header restored verbatim from an identical sibling**:
    `obj/toy/buwawa.lpc` and `obj/toy/mallet.lpc` both `#include "message.h"`
    (quoted — searches their own directory first) but no `message.h`
    exists in `obj/toy/`. Found two byte-identical existing copies
    elsewhere in the lib (`d/obj/misc/message.h`, `d/obj/flower/message.h`
    — a generic `message_vision()` helper duplicated per-zone rather than
    centralized in `/include`, apparently this lib's own long-standing
    convention). Copied the same file to `obj/toy/message.h` — not
    fabricated content, a verbatim restoration of an already-duplicated
    generic helper, matching the established "restore from an identical
    sibling" precedent (e.g. `xajhzcjh`'s `cloth.lpc`).
14. **Genuine pre-existing truncation, `d/nanhai/obj/jingu2.lpc`** (Honghaier's
    "golden hoop" item): raw archive file is exactly 1024 bytes, cutting
    off right after the LAST statement of `free_jingu()` with no closing
    `}` for the function (all the actual logic/dialogue text is intact
    and complete — only the trailing brace is missing, unlike `cast1.c`'s
    mid-string truncation). Added the single missing `}` — a safe,
    minimal syntax fix that adds no new logic, not a §13 "don't
    fabricate" violation.
15. **§13-shaped missing-header content gap, restored where safely
    possible**: `d/kaifeng/npc/old/{shan,bei,zhi}.lpc` (3 quest-giving
    NPCs) `#include <quest_ak.h>` / `<quest_fd.h>` / `<quest_gv.h>` /
    `<quest_kl.h>` / `<reporting.h>` using ANGLE BRACKETS — but these
    headers actually live one directory UP, in `d/kaifeng/npc/` (their
    sibling NPCs in that same parent directory use QUOTED includes and
    compile fine). Angle-bracket resolution only ever searches the
    configured `/include` path, never a relative/parent directory, so
    `master::get_include_path()` (§8d) can't fix a PARENT-directory
    header reference either. Since the target headers are genuinely
    real, matching content (verified `quest_ak.h`'s `quests_ask` mapping
    is exactly what `shan.lpc` expects, keyed by the same quest text/NPC
    names it references), copied `quest_ak.h`/`quest_fd.h`/`quest_gv.h`/
    `quest_kl.h`/`reporting.h`/`quest.h` (a further transitive
    header-guarded dependency of all four) into `old/`, and converted the
    3 npc files' `<...>` includes to quoted `"..."` form to match. This
    is restoring real, correct, already-existing content to where it's
    needed — not fabricating anything.

## Confirmed NOT needed (checked proactively, verified via source read)

- **§4** (master's lazy security-daemon load recursion): `master.lpc`'s
  `valid_read`/`valid_write` only do `find_object(SECURITY_D)` (no
  `load_object()` call at all) — not vulnerable to this pattern.
- **§7** (`get_root_uid()`/`get_bb_uid()`): both already present in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c** (`valid_read`/`valid_write` overriding caller with `this_player()`):
  `securityd.lpc`'s `valid_read` is a bare `return 1;` (dead/commented-out
  ACL logic below it) — no such override pattern present at all.
  `valid_write` doesn't reference `this_player()` either.
- **§15n/§15o** (custom securityd ACL blocking mid-connection lazy
  compiles / missing `get_include_path()`): `valid_read` unconditionally
  allows everything, so the ACL-discrimination gap this catalog entry
  describes doesn't exist here; `get_include_path()` wasn't needed either
  since all ~59 angle-bracket header includes checked resolve correctly
  via the configured `/include` path (confirmed each target file
  actually lives under `include/`) — the ONE exception found (the
  kaifeng quest headers) was a parent-directory case that
  `get_include_path()` structurally can't fix anyway (see fix #15 above).
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`): no such
  `destruct()`/`efun::destruct()` call present in `create()`.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`): none referenced
  anywhere in the lib.
- **§15ah** (missing save-data directory silently swallowing
  `write_file()`): all directories referenced by `log_file()`/
  `write_file()` calls on the registration path already exist in the raw
  archive (`log/`, `log/static/`, `data/`, `adm/tmp/` — the last one
  created proactively since it didn't exist, for the `swap file` config
  path, though swap wasn't actually exercised in testing).
- **§15ae** (`private nomask command_hook` breaking every post-login
  command): `feature/command.lpc`'s active declaration is
  `nomask int command_hook(string arg)` — the `private` variant is
  already present only as a COMMENTED-OUT line right above it
  (`// private nomask int command_hook(string arg)`), i.e. this lib's own
  maintainer already avoided the bug. Confirmed empirically too: `look`
  and `score` both worked correctly after registration in every test run.
- **§15u** (dormant phone-home/self-destruct license check): grepped
  `securityd.lpc`/`master.lpc` for `rm`/`unlink`/`shutdown`/`rmdir`-on-root
  patterns outside the (harmless, guarded) `shutdown(1)` fixed in item #3
  above — nothing else found.
- **§15v** (`LONELY_IMPROVED`-gated `efun::X()` calls): this is not an
  NT/nitan/Lonely-lineage lib (confirmed no `LONELY_IMPROVED` macro, no
  bare simul_efun-based `set`/`query`/`delete` dbase architecture at all
  — see next item).
- **§15 (the nitan-family simul_efun dbase architecture bug)**:
  `feature/dbase.lpc` has real, local `set()`/`query()`/`delete()`
  methods (a proper `mapping dbase` per-object, inherited via `F_DBASE`)
  — the same architecturally-correct pattern as `rzrmud`/the ES-II family
  generally, not the nitan/Lonely lineage's shared-simul_efun-dbase bug.
- **§15x** (hardcoded `MUD_PORT` mismatch): `master.lpc`'s `connect()`
  apply doesn't dispatch on any hardcoded port constant at all (this
  driver-generation ES-II lineage doesn't have that pattern); confirmed
  `include/runtime_config.h` only exposes `__MUD_PORT__` as a
  `get_config()`-backed macro (reads the REAL configured port
  dynamically), not a separate hardcoded literal.
- **§15al** (`crypt(str,0)` random-hash-every-call footgun): `logind.lpc`'s
  password flow uses `crypt(pass, 0)` only to GENERATE the stored hash
  once at registration, and verifies with `crypt(pass, old_pass)` (a real
  string salt = the previously stored hash) on every subsequent login —
  the safe/standard idiom, not the client-challenge/response
  determinism-dependent pattern this bug describes.
- **§15am** (`file_size()==-1` truthy trap): `master.lpc`'s own
  `preload()` correctly checks `file_size(file + ".c") == -1` (explicit
  `-1` comparison, not a bare truthiness check); no other `file_size()`
  bare-condition use found on the registration/boot path.
- **§8f** (`TYPE * name1, name2;` comma-list array-modifier bug): this is
  an English/Dead-Souls-lineage-specific habit per the catalog; not
  checked exhaustively here given the Chinese-lib policy, but no such
  pattern surfaced during boot, registration, or the lpcc sweep.
- **Uppercase `.C` files**: none found (`find work -name '*.C'` → 0).
- **Extensionless-file/.c-backup pairs (§15ak)**: none found under
  `adm/obj/`/`adm/daemons/` (the two directories most likely to carry a
  stray backup of `master`/`securityd`/`logind`).

## Re-verification pass (QA sweep, later session)

Re-tested the full flow end-to-end this pass and found two real bugs:

1. **Stray pre-existing debug leftover `printf("%O\n", ob);`** in
   `adm/daemons/logind.lpc`'s Chinese-name-confirmation step -- dumps a
   raw internal object reference (e.g. `/obj/login#0`) straight to the
   connecting player right after their Chinese name is accepted, on
   every single registration. Confirmed live during a fresh registration
   test. The exact same leftover was found (and removed) in all three
   sibling libs processed in this same session (`xiyouji`, `xiyouji2003`
   -- 2 occurrences, `xiyouji2006`), confirming shared lineage at the
   source level. Removed here too; re-verified with a fresh registration
   (`qfmei`/秦美): no stray object-reference text anywhere in the
   transcript, `look`/`score`/`quit` all still correct (correct
   female-specific "你目前待字闺中" text).
2. **§15s, `tell_room()`'s raw-`int 0`-as-4th-arg bug, ported
   defensively.** This file's own earlier pass concluded (via source
   reading) that the driver tolerates a raw `0` in `message()`'s exclude
   slot -- but a live crash of the exact same call shape was
   subsequently confirmed on siblings `xkx2001` and `xiyouji2006` in this
   same later session. Ported the standard fix (`exclude || ({})`) here
   too, even though this archive's own boot/registration path never
   actually triggered the crash, since the underlying call shape is
   identical. Re-verified with a clean boot: zero regressions.

## Registration-flow test — exact transcript/outcome (real Chinese names, full continuous connections)

Shape (read from `logind.lpc`'s actual `input_to` chain, not inferred from
prompt text, per the standing "always read the actual callback" lesson):
`gb/big5 encoding choice` → `banner + age-gate question (yes/no, any
non-"no" ends session)` → `English id (any unused id skips straight to
confirm, no separate "new" keyword needed)` → `y/n confirm new character`
→ `Chinese name` → `password` → `confirm password` → `email` → `gender
(m/f)` → `stat-roll accept (n/y/q)` → **enters the actual game world**.

**Run 1** (`qinfeng` / real Chinese name **秦风**, male):
```
您是否是中小学学生或年龄更小？(yes/no)
> no
您的英文名字：（新玩家请选择一个您喜欢的名字）使用 qinfeng 这个名字将会创造一个新的人物，您确定吗(y/n)？
> y
您的中文名字：
> 秦风
请设定您的密码：
> test12345
请再输入一次您的密码，以确认您没记错：
> test12345
您的电子邮件地址：您要扮演男性(m)的角色或女性(f)的角色？
> m
[stat roll displayed]
您同意这组天赋数值吗？[n|y|q]
> y
目前权限：(player)
[...]
南城客栈 - [full room description, exits west/east/up, board, 2 NPCs]
> look
[same room re-displayed correctly]
> score
【 平  民 】普通百姓 秦风(Qinfeng)
你是一位十四岁的男性人类，...
[full correct stat sheet: 膂力/胆识/悟性/灵性/定力/容貌/根骨/福缘, 气/神 bars,
 战斗攻击力/防御力, 食物/饮水 bars, kill count, 潜能: 99]
> quit
欢迎下次再来！
```
Confirmed 0 spurious error messages, 0 `debug.log` errors, real Chinese
name accepted, `look`/`score`/`quit` all correct.

**Run 2** (real Chinese name **林枫**, female, different driver
boot/session): identical flow, correct female-specific text ("你目前待字
闺中" vs. run 1's male "你目前是光棍儿一条"), 0 spurious errors, 0
`debug.log` errors — confirms the §15h fix and §15w fix both hold across
independent sessions/genders.

**Run 3** (post-§15w-fix final verification, real Chinese name **秦风**
again as a fresh id `qinfengd` since the plain `qinfeng` id was already
registered from run 1's persisted save data — confirms save/load and
duplicate-id handling both work correctly too): same clean flow, 0
spurious messages, entered `南城客栈` again, `look`/`score`/`quit` all
correct, 0 `debug.log` errors.

## lpcc sweep results

Ran twice: once before the post-boot/registration-driven content fixes
(items #9-15 above), once after, to get an accurate final number.

- **First pass** (before items #9-15): `total=4988 pass=4921 fail=67`
  (98.66%).
- **Final pass** (after all fixes): **`total=4988 pass=4934 fail=54`
  (98.92%)**.

**Remaining 54 failures, triaged by category** (per §6b, not chased
individually — none are on the boot/registration/critical path):
- **§13-style genuine pre-existing archive corruption/truncation**
  (~10-15 files): `cmds/imm/cast1.lpc` (documented above, mid-string
  cutoff), `d/qujing/jingjiling/jingji1.lpc`/`jingji6.lpc` (both exactly
  1024 bytes, cut off mid-statement inside a `message_vision(...)` call —
  unlike `jingu2.lpc`, completing these correctly would mean inventing
  the missing dialogue/logic, left undone), `d/qujing/wudidong/npc/fangzhang-jail.lpc`
  (1072 bytes, "unexpected end of file", same zone/family of corruption),
  plus `d/qujing/wudidong/monk.lpc` (cascades from the previous one via
  `inherit`), and a handful more "syntax error, unexpected end of
  file"/"unexpected ';'" hits in the same general shape.
- **§13-style genuine missing content**: `d/obj/fabao/EXAMPLE.lpc` (a
  documentation/template stub explicitly commented "some files to
  inherit, include, and some functions to declare" by "pickle" — not
  referenced anywhere, never meant to be a real compilable object) and
  3 remaining `Cannot #include /d/qujing/obstacle.h`/`Undefined variable
  'obstacles'` hits in the same qujing "obstacle-clearing" quest content
  family as the corrupted jingji1/jingji6 files above — a genuinely
  missing header for that specific sub-feature, left undocumented-but-unfixed
  since (unlike the kaifeng quest headers) no matching real copy of
  `obstacle.h` exists anywhere else in this archive to restore from.
- **§6b false positive**: `adm/simul_efun/object.lpc` ("Invalid simulated
  efunction override") — an `#include`-only fragment composed into
  `simul_efun.lpc`, fails when `lpcc` compiles it as a standalone
  top-level object (no `main_file` context) but compiles fine as part of
  the real `simul_efun.lpc` (confirmed: zero such error in any real boot's
  `debug.log`).
- **Minor lossy-conversion/mojibake remnants** (~15-18 files, "Illegal
  character 0xXX" hits): isolated corrupted-byte remnants in a handful of
  content files' string literals — same general class as the
  already-accepted "minor loss in non-critical seed/example data"
  precedent used throughout this project; not chased individually given
  the small count and non-critical (flavor-text-only) nature.

## How to run

```
cd libs/xiyouji450
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40078 --timeout 40 --idle 1 \
  --send "gb" --send "no" --send "<english-id>" --send "y" \
  --send "<real-chinese-name>" --send "<password>" --send "<password>" \
  --send "<email>" --send "m" --send "y" --send "look" --send "score" \
  --send "quit"
```

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  4,988 files total, 4,573 already-idempotent from an earlier partial
  run in this same pass (interrupted by an overall time budget) plus
  411 freshly reformatted this run, 4 refused (self-check failures,
  expected). Confirmed the earlier `printf("%O\n", ob);` removal in
  `adm/daemons/logind.lpc` and the `tell_room()` §15s fix in
  `adm/simul_efun/message.lpc` both survived reformatting intact.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风复来** (male, id `qretfive`), reaching the actual starting room
  (南城客栈), `look`/`score`/`quit` all producing correct output.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings). **Full registration + login succeeded end-to-end
  under WASM too** — real Chinese name **秦风网五** (id `qfwfour`),
  through the full gb/age-gate/id/name/password/email/gender/
  gift-accept chain, landed in the real starting room (南城客栈), `look`
  rendered the actual room, `quit` disconnected cleanly. This lib's
  registration/login path does not gate on `query_ip_number()`'s
  format, so it is **not** affected by the documented WASM IP-format
  limitation — a genuinely clean, complete WASM result, matching its
  close sibling `xiyouji`'s outcome.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5),
same shape as sibling `xiyouji` (band.lpc is byte-identical between the
two apart from this patch):

1. **Loopback always allowed through ban gates** —
   `adm/daemons/band.lpc`: added `is_local_ip(string ip)` helper (127.*,
   empty/non-string, or non-dotted-quad => local) and short-circuited
   `is_banned()`, `create_char_banned()`, `is_strict_banned()` to
   `return 0` for local IPs. Shipped ban lists are empty, so this is a
   defensive standard patch, not a live-blocker fix.
2. **Uptime startup gate**: none in this lib.
3. **Anti-flood throttles**: none per-IP (global player-count caps and
   `match_wiz_site()` — which allows wizards with no wiz_sites entry —
   left intact as game/security design).
4. **Admin account seeded** — id `fluffos`, password `Mud@2026`, 浮浮
   (male), via the real flow (`gb` → `no` → id → y → name → password ×2
   → email; NOTE unlike sibling `xiyouji` there is no gender/talent
   prompt — after email the character enters the world directly).
   Granted `(admin)` via `adm/etc/wizlist`. Verified after restart:
   目前权限：(admin), `update /adm/daemons/band` OK (only pre-existing
   unused-variable warnings), `goto` OK. Save files:
   `work/data/user/f/fluffos.o` + `work/data/login/f/fluffos.o`
   (untracked, NOT gitignored — orchestrator must `git add`).

Flaky-first-registration note (environment, not a code bug): the very
first registration attempt after a cold boot aborted at `make_body()`
with `Too long evaluation` (config caps eval at 400000 usec) while
lazily compiling the whole `/std/char` inherit chain, with several other
drivers loading the host concurrently. The immediate retry (chain now
cached) completed normally. No mudlib change made for this.

Retest: fresh registration reached 南城客栈, `look` correct; fluffos
re-login `(admin)` + wizard commands OK; debug.log has no runtime errors
beyond the documented first-attempt eval-cost abort (which did not recur).

## 深度功能测试 / Deep functional test (2026-08-06)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角
色 id `xyfourf`，中文名 白龙马。本轮 WASM 未重新验证：emsdk 工具链下
载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略性拒绝
该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策略
拒绝而非临时故障），本地无法构建 WASM 驱动。

### 更正此前的误诊：上面记录的"首次注册偶发 eval-cost 中止"其实是 100% 可复现的真实配置 bug，不是环境偶发（AGENTS.md §7.90 严重实例）

上面"Flaky-first-registration note"一节把这次中止归因为"冷启动时并
发编译负载"，判定为环境偶发、未做任何修复。刚测试完同一血缘家族的
`xyj2000f`（`config.fluffos` 的 `maximum evaluation cost` 同样被设成
`400000`，比这个项目常见的 700000 模板默认值还低）才发现：这不是并
发负载导致的偶发，而是**每一次冷启动后的第一次注册都 100% 会撞上**
——`make_body()` 第一次编译整条 `/std/char` 继承链的开销本来就稳定超
过 400000 usec 预算，与是否有其它驱动同时在跑毫无关系。此前那次记录
之所以看起来像是"重试一次就好了"，只是因为失败的那次编译已经把继
承链的编译结果缓存进了驱动进程，同一进程内后续的注册自然不会再触发
冷编译——如果当时重启驱动再试一次全新注册，会看到同样的中止 100%
复现。这次深度测试**在动手注册前就先主动对齐**了 `xyj2000f` 那次找
到的修复：把 `maximum evaluation cost` 从 `400000` 提到 `5000000`
（AGENTS.md §7.90 记录的、本项目 30+ 份档案已验证安全的数值），此后
两次独立的全新注册（重启驱动之间跨越两个不同的驱动进程）均一次通
过，无需任何重试或运气。已在 AGENTS.md §7.90 的对应实例段落里追加了
这份档案作为第二例确认。

### 顺带更正 README 的一处失实描述

原 README 写"与姊妹版 `xiyouji` 不同，本版注册流程没有性别/天赋选择
环节，更简洁"——本轮实测注册流程完整包含性别选择（m/f）与八项天赋
（膂力/胆识/悟性/灵性/定力/容貌/根骨/福缘）确认环节，与 `xyj2000f`
一致，并没有省略。已在 README 里更正这一句。

### 测试内容与结果

- **注册**：GB 编码 → 是否中小学生（no）→ 直接输入英文名（无需先输
  `new`，与 `xyj2000f` 的流程略有差异）→ 中文名（白龙马，未出现
  `xyj2000f` 那种 `printf("%O", ob)` 调试泄漏——`logind.lpc` 全文 grep
  确认这份档案没有这一行）→ 密码 → 确认密码 → 邮箱 → 性别 → 天赋确
  认，全程顺利进入 `南城客栈`。
- **战斗**：同一血缘家族共享的 `朱雀大街` 疥顶小僧（`d/city/npc/
  jieding.lpc`，`attitude: peaceful`）——`set wimpy 70` 后 `fight
  seng` 触发真实对战，气血降到 59%（低于 70% 阈值）时角色正确说出
  "佩服，佩服"认输（与 `xyj2000f` 的"自动逃跑到相邻房间"不同的具体
  实现，但同属 wimpy 安全机制，无崩溃）。
- **持久化**：真实 `quit` 后重新登录（同一驱动进程内），正确恢复到
  `南城客栈`（这份家族的登录固定入口，非位置持久化 bug，参见
  `xyj2000f` 的同类记录）、气血自然回复（59→66，符合时间流逝的自然
  恢复，非存档丢失）。
- **管理员账号**：`fluffos`/`Mud@2026` 登录，`update
  /adm/daemons/logind` 热更新成功（编译警告是既有的未使用变量，非本
  轮引入），确认写 ACL 正常。
- **门派/拜师、经济/商店**：**未覆盖**——与 `xyj2000f` 本轮测试遇到
  的时间预算限制相同，如实标注为未覆盖，而非默认"同血缘家族所以没
  问题"。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记450 手足档案（master.c 约等于 mhxy）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 23 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 172 live occurrences deleted: 171 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as sibling `xiyouji`). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40078.

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

## 深度功能测试第二轮（2026-08-21）：门派/拜师、经济/商店、真实战斗/死亡/复活 — 全部覆盖，未发现新 bug

补上前一轮明确标注"未覆盖"的两个系统，以及从未真正测试过的"真实致死
战斗 + 死亡/转生"流程。测试角色 id `qzhan`（中文名 秦战，密码已略去不
记录），全程使用真实驱动（`~/src/fluffos/build-debug/src/driver`）、
`config.fluffos`（`maximum evaluation cost` 已确认仍是 5000000，本轮
高强度测试全程未再触发 eval-cost 中止，§7.90 修复保持有效）。

### 1. 门派/拜师（原文档"未覆盖"）——真实测试通过

找到方寸山三星洞第三代弟子`云清`(`d/lingtai/npc/yunqing.lpc`，房间
`/d/lingtai/inside6`)——`attempt_apprentice()`没有任何前置条件，直接
`recruit`，是全库里唯一无门槛收徒的师父，适合测试完整拜师链路。用
`apprentice yun`（注意：其 id 数组是 `"yun qing"`/`"yun"`，不含
`"yunqing"`，`apprentice yunqing`会因 `present()` 找不到目标而报错
"你想拜谁为师？"——不是 bug，只是 NPC 自身的 id 词组里确实没有这个
连写形式，其他别名同样能命中）。真实执行链路：`apprentice.lpc`里玩
家先 `set_temp("pending/apprentice", ob)`再调用
`ob->attempt_apprentice(me)`，NPC 内部 `command("recruit "+id)`，
`recruit.lpc`里检查`ob->query_temp("pending/apprentice")==me`成立后
调用`me->recruit_apprentice(ob)`——`feature/apprentice.lpc`里的
`create_family`/`assign_apprentice`/`recruit_apprentice`全部有
`mapp()`前置检查，没有踩到任务里提到的"ldtx 那种未加 mapp 保护直接
下标 `family["family_name"]`"的第二种形状（`cmds/std/apprentice.lpc`
第41行的`me->query("family/family_name")`用的是安全的路径查询语法，
不是裸下标）。实测一次执行即完整完成拜师：称号从"普通百姓"变为
"方寸山三星洞第四代弟子"，`score`正确显示"你的师父是云清"，
`class`被设为`taoist`，`debug.log`全程零新增错误。

### 2. 经济/商店（原文档"未覆盖"）——真实测试通过

`d/city/npc/xiaowang.lpc`(小酒馆`/d/city/jiuguan`，`inherit F_VENDOR`)
出售`jiuping`(粗磁酒瓶，1两银子=100文)。用管理员账号
`clone /obj/money/silver` + `call silver_money->set_amount(5)` +
`give silver to qzhan`（项目规定的合法管理员注资手法）给测试角色5两
银子，然后玩家真实执行`buy jiuping from xiaoer`：正确扣除1两银子
（5两→4两），正确收到"粗磁酒瓶"实物，`feature/vendor.lpc`里
`ob->query("value")`（`ob`是字符串路径，LPC的
`"path"->func()`语法糖，不是对字符串调用方法的 bug）工作正常，
`debug.log`全程零新增错误（除既有的惰性编译警告）。

### 3. 真实战斗→死亡→转生（原文档从未测试，仅测过 wimpy 安全脱战）

依据任务里"kill 指令通常对 NPC 无战力门槛检查"的经验（本会话
10+个库已验证），核实`cmds/std/valid_kill.h`确认属实——`valid_kill()`
只检查`no_pk_time`（防止连续杀人的玩家间冷却），对 NPC 目标完全放
行。进一步核实`feature/damage.lpc`的实际死亡判定逻辑：
`receive_damage()`扣减`kee/sen/gin`（临时值，归零后触发`unconcious()`
"昏迷"，会自动`revive()`，不是真死）；只有`receive_wound()`扣减
`eff_kee/eff_sen/eff_gin`（永久性"内伤"）归负才会真正触发`die()`——
而`adm/daemons/combatd.lpc`第466-472行只在`me->is_killing(victim)`
（即用`kill`而非`fight`发起）且伤害超过护甲时才调用`receive_wound`，
证实"safe spar vs. 真实kill有战力门槛差异"这条项目级经验在这份档案
上同样成立、且能精确定位到代码层面的原因。

实测：将秦战（刚拜师的初始角色，无技能）传送到朱雀大街疥顶小僧
(`d/city/npc/jieding.lpc`，闪避/招架技能79，此前只做过安全"fight"陪
练测试）身边，`wimpy 0`（禁用自动脱战）后`kill seng`——数回合内被
连续命中要害，从"气喘嘘嘘"→"头重脚轻"→"半昏迷"→真实昏迷
（"你的眼前一黑"）→**真实死亡**（"你死了"，全服谣言广播"秦战被疥顶
小僧杀死了"）。角色正确移动到 `/d/death/gate.lpc`（"阴阳界"），遇到
崔判官（`d/death/npc/pang.lpc`，即§7.112清单里已核对过 reentry guard
的四个`death_stage()`实现之一），逐条完整走完5条`death_msg`台词，
`death_stage_active`标记按代码路径应在最后一条消息后清除并调用
`ob->reincarnate()`，实测该函数被真实调用——角色魂魄送回阳间，落地
在"荒郊小店"，宗门称号（"方寸山三星洞第四代弟子"）在死亡/转生全程
正确保留，气血值重置为极低值后按`heal_up()`自然恢复（非满血复活，
符合死亡惩罚设计），潜能从99降为50（死亡惩罚，符合预期），随身物品
（银子、酒瓶）因`reincarnate()`里的`command("drop all")`留在了阴阳界
（無法找回，属于"死亡掉落"式的老派惩罚设计，不是 bug）。全程
`debug.log`零 FATAL/SIGSEGV/Undefined function/Cannot replace 等错误
信号，只有一贯的惰性编译未使用变量警告。

**注**：`feature/damage.lpc`的`die()`函数里有一行
`DEATH_ROOM->start_death(this_object())`——全库`grep`确认`start_death`
这个函数从未被任何文件定义过（包括`std/room.lpc`），这是一次对未定
义函数的`call_other`。实测证实驱动对这种调用静默返回0、不记录任何
`debug.log`错误、不影响后续死亡/转生流程——不是一个需要修的 bug（无
错误信号，符合项目"没有错误签名就是设计/无害遗留代码"的判定标准），
但记录在此供后续如遇到类似"看起来像功能缺失但从未报错"的情况参考。

### 附带核实：§7.108 重复登录踢人路径，真实触发测试通过

标准清单里§7.108要求确认"踢出重复登录角色"路径不会导致新连线角色卡
死收不到任何指令。之前的"netdead 后重连"测试路径（`get_passwd()`里
`user->query_temp("netdead")`分支）本轮已在每个测试阶段间隔间接测试
多次（每次开新 socket 连接前一个已断线），但§7.108 真正描述的是
"仍在线时被顶号踢出"的`confirm_relogin()`分支，代码路径不同（走
`exec(old_link,user)` + `destruct(old_link)` + `reconnect()`）。额外
专门测试：保持连线A在线（未断线），开新连线C用同一账号登录，确认收
到"您要将另一个连线中的相同人物赶出去，取而代之吗？"提示，回复`y`
后连线A收到"有人从别处连线取代你所控制的人物"并被正常踢出，新连线C
立即可执行`look`/`score`并有正常输出（未卡死），确认这份档案的
`logind.lpc`已经是修复后的正确实现，不需要改动。

### 标准清单复核结果汇总

- §7.90（eval-cost）：已修复，本轮高强度测试全程未复现。
- §7.100（ROOM replace_program）：此前已扫过（172处），未复查代码但
  全程实测未见任何"cannot replace"/"cannot bind"错误。
- §7.111（standard_trace file_name(0)）：源码确认三元判断保护已存在
  （与 mhxy 血缘一致），未改动。
- §7.112（death_stage reentry guard）：`d/death/npc/{b,bgargoyle,pang,
  wgargoyle}.lpc`四个实现逐一读码确认每个退出分支都正确清除
  `death_stage_active`标记，且`pang.lpc`本轮被真实死亡流程完整触发，
  实测零异常。
- §7.79/§7.108：`cmds/std/valid_kill.h`/`logind.lpc`确认无需改动
  （§7.108见上方专项测试）。
- §7.30 二次形状（`attempt_apprentice`裸下标`family["family_name"]`
  未加`mapp`保护）：全库`attempt_apprentice`调用点及`feature/
  apprentice.lpc`本体逐一确认均已有`mapp()`前置检查，未发现该形状。
- 四个已在其他库确认关闭的 bug 模式，本库逐一核对均不存在：
  `combatd.lpc`无`bounce`相关代码；全库无`chacha.lpc`文件；
  `natured.lpc`无`if (!userp(ob[i])) destruct(ob[i])`模式（甚至无
  `destruct`/`userp`调用）；`cmds/std/go.lpc`的`exit[arg]`用的是
  `mapp(exit)`真值检查+`undefinedp(exit[arg])`，不是
  `sizeof(exit[arg])`下标越界那种形状。

**本轮结论**：门派/拜师、经济/商店、真实致死战斗/死亡/转生三大此前
"未覆盖"或"从未测试"的系统均已通过真实端到端测试，零崩溃、零
`debug.log`新增错误，未发现需要修复的代码缺陷。


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).
