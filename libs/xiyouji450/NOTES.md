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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记450 手足档案（master.c 约等于 mhxy）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 23 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
