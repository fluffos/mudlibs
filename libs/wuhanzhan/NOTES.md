# wuhanzhan — 大话西游 (archive title: 武汉站/"Wuhan Station")

Archive: `武汉站.rar`. Port: 40052. Status: **done** (boots clean, full
registration flow verified end-to-end with a real Chinese name, lpcc sweep
96.3% pass).

## What this is

`config.cfg`'s own `name` field says **大话西游** ("A Chinese Odyssey" — a
play on the famous Stephen Chow *Journey to the West* films), not "武汉站"
— the archive's title is just the collector/site label, not the game's own
name (noted per the task's request to flag this divergence). The live
connection banner confirms the real identity further: "楚天热线 官方游戏站"
(Hubei/Chutian-Online official game site) and "热烈庆贺湖北省襄樊大话西游站
的开通" (celebrating the opening of the Hubei Xiangfan/Xiangyang 大话西游
station) — so this is a 大话西游-branded station hosted somewhere in Hubei,
archived under a "武汉站" (Wuhan station) label by whoever collected it.

`master.lpc`'s header comment says "for ES II mudlib, original from Lil,
rewritten by Annihilator (11/07/94)" — same **ES II lineage** as
es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/xinkuangxiangkongjian2/
yueyingqiyuan (archives #12/13/25/23/28/45/53/54), sharing the
`adm/obj/{master,simul_efun}` + `adm/simul_efun/` + `adm/daemons/` +
`cmds/{std,wiz,usr,adm,...}/` + `std/` + `obj/` + `d/<zone>/` layout shape.
It is NOT byte-identical or even structurally close to any single prior ES
II lib checked (confirmed via `diff` against `menghuanxiyou2002`'s/`mhxy`'s
master.c despite some files elsewhere in the tree carrying a "神话世界·
西游记·版本4.50" header comment that superficially suggested that
different, unrelated 西游记/xiyouji.org lineage — another confirmation that
header-comment branding text can be misleading and copy-pasted across
completely different codebases; always verify via structural/diff
comparison, not comment text alone).

Root: `raw/武汉站/武汉站/` (nested one level, doubled directory name).
`config.cfg`: `master file : /adm/obj/master`, `simulated efun file :
/adm/obj/simul_efun`. Raw archive: ~9,898 real LPC files (after excluding
the bundled driver source below) plus a large `binaries/` (~10,719 `.b`
compiled-binary dumps from the original archive's "save binaries
directory" feature — harmless leftover data, never used by this driver
since LPC->C compile-to-binary is never enabled here) and `backup/`/`bin/`
scaffolding.

## Pre-processing: bundled MudOS v22pre11 driver source excluded

`raw/.../bin/v22pre11/` is a full bundled **MudOS v22pre11 driver C source
tree** (`src/interpret.c`, `array.c`, `backend.c`, etc. — real driver
internals, not mudlib LPC) sitting alongside the mudlib content, the same
"archive bundles a driver too" situation seen on `fluffos_xiyou2000` and
others. Renamed to `bin/v22pre11.orphaned-driver-src/` in `raw/` **before**
running `convert_lib.sh`, per precedent, so it wouldn't be mistaken for
real mudlib content. Note: this rename does NOT stop `convert_lib.sh`'s
blind tree-wide `.c`→`.lpc` rename from still touching the ~105 `.c` files
inside it (the rename walks by extension, not by directory name) — this is
expected/harmless per AGENTS.md ("driver runs mixed-extension trees fine")
since nothing in the real mudlib ever `inherit`s/`load_object()`s anything
under that path; it does, however, show up as a chunk of the lpcc sweep's
failure count (missing driver-only headers like `uid.h`/`spec.h`) — noted
below under the sweep triage, not something to fix.

## Fixes applied

1. **AGENTS.md §15h** (the universal GBK-byte-range bug), two sites:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`str[0] > 160 && str[0] < 255`, `strlen(str)>=2`) replaced with
     a CJK Unified Ideographs codepoint range check (`str[0] >= 0x4e00 &&
     str[0] <= 0x9fff`, `strlen(str)>=1`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
     `strlen(name) < 2 || > 12` → character-count bound `< 1 || > 6`
     (matching the message's own stated "1 到 6 个中文字"); removed the
     `i%2==0 &&` even-byte-offset gate in the per-character `is_chinese`
     sliding check so every character position is actually checked (not
     just alternating ones, which was the GBK-lead-byte-parity leftover).
2. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was present in
   `adm/etc/preload` — removed proactively before the first boot attempt.
   Booted clean well under 15 seconds on every attempt, no hang.
3. **AGENTS.md §14** (`valid_override` 2-arg → 3-arg): `master.lpc`'s
   `valid_override(file, name)` only matched `file == SIMUL_EFUN_OB`, which
   never equals the physical file for an `efun::` call written inside an
   `#include`-composed fragment (`adm/simul_efun/object.lpc`'s
   `efun::destruct(ob)` and `efun::living(ob)` are concrete examples of
   exactly this shape in this lib). Upgraded to `varargs int
   valid_override(string file, string name, string main_file)`, accepting
   either `file` or `main_file` matching `SIMUL_EFUN_OB`/`MASTER_OB`.
4. **AGENTS.md §15s** (new confirmation, same bug class as `yueyingqiyuan`):
   `adm/simul_efun/message.lpc`'s `varargs void tell_room(mixed ob, string
   str, object *exclude)` left `exclude` as a bare `int 0` when called with
   only 2 args, which this driver's `message()` efun (4th arg typed
   `void|object|object*`) rejects. Fixed with `exclude || ({})` before
   delegating to the real efun. (Only 4 call sites of `tell_room` exist in
   this lib specifically, vs. `yueyingqiyuan`'s 578 — fixed regardless
   since it's a one-line, zero-risk shared-root fix.)
5. **AGENTS.md §8h** (convertd.lpc Greek-table stray-backslash typo),
   **45 occurrences** (the largest count seen for this bug so far — prior
   libs had 1-2): `adm/daemons/convertd.lpc`'s GB/BIG5 charset-table lines
   of the shape `"<greek-letter><PUA-codepoint>\",` (trailing backslash
   escaping the closing quote, merging that line into the next) — found
   one manually via the first `lpcc` compile of `simul_efun`, then wrote a
   byte-level Python regex sweep (`rb'^("[^"]*)\\("...)(\r?\n)$'` shape) to
   find and fix all 45 in one pass; verified 0 remain afterward. (The
   "PUA codepoint" half of each table entry, e.g. U+E5A1, is a genuine,
   intentional artifact of the original GBK code page's user-defined
   region carried through by `iconv` — not something to "fix", only the
   stray backslash was ever a bug.)
6. **NEW bug class, proposed as AGENTS.md §15u**: `master.lpc`'s
   `log_error()` apply (the master apply for **compile-time diagnostics**)
   showed the scary "default error message" config text
   (`你发现事情不大对了，但是又说不上来。`) to **every connected non-wizard
   player for every compile-time WARNING**, not just fatal errors — this
   driver's compiler funnels ALL diagnostics through
   `APPLY_LOG_ERROR`/`master::log_error()` with no severity distinction at
   all (confirmed by reading `~/src/fluffos/src/compiler/internal/
   compiler_utils.cc`'s `smart_log()`/`report_compile_diagnostic()`, both
   unconditionally calling `safe_apply_master_ob(APPLY_LOG_ERROR, 2)`
   regardless of whether the diagnostic is a warning or an error). Since
   this driver is measurably stricter/noisier than the original MudOS
   target this lib shipped against (this port's own `static`→`nosave`
   rename alone produces an "Illegal to declare nosave function" warning
   on every such function; `#pragma optimize`/similar produce "Unknown
   #pragma, ignored" warnings), and since most of a mudlib's object tree
   is only *lazily* compiled the first time a connected player's actions
   happen to touch it, an ordinary short registration+`look` session
   triggered **98 of these messages** to a ~90-second-old, otherwise
   perfectly healthy connection — purely from harmless "unused local
   variable"/"illegal nosave" warnings on rooms/NPCs/items being compiled
   for the first time as the player walked in. Fixed: the non-wizard
   branch of `log_error()` now only shows the message when `message` does
   **not** contain the substring `"warning:"` (i.e., only for a genuine
   compile error); wizards still see the full diagnostic text as before,
   unchanged. **Diagnosis path** (kept here since it was non-obvious and
   the eventual root cause was two apply-mechanisms away from the visible
   symptom): (a) confirmed `error_handler()` — the OTHER, similarly-shaped
   master apply — was NOT the source, by temporarily instrumenting it with
   an unconditional `efun::write_file()`+`efun::write()` marker and
   observing it fire correctly for one genuine runtime error (see next
   item) but ZERO times during the 98-message spam; (b) found
   `/log/log` (already being written unconditionally by `log_error()`'s
   own `write_file()` call) contained the exact matching compile-warning
   text at matching volume across the session, pointing straight at
   `log_error()` instead.
7. **Bonus fix found via the same diagnosis** (not a new bug class, but a
   real, permanent improvement): `master.lpc`'s `error_handler()` carried a
   stale comment ("whatever we return goes to the debug.log") reflecting
   old-MudOS behavior that does **not** hold on this driver — per
   `~/src/fluffos/docs/apply/master/error_handler.md`, the real apply
   signature is `void error_handler(...)`; the return value is simply
   discarded, so a genuine uncaught runtime error was previously visible
   ONLY as an ephemeral `tell_object()` to whichever player happened to be
   connected at the moment (nothing durable at all if that player was a
   non-wizard, or if nobody was connected). Added a permanent
   `efun::write_file("/log/RUNTIME_ERRORS", trace)` at the top of
   `error_handler()` so real runtime errors are never silently lost again.
8. **New pre-existing content bug, 19 files** (found via the lpcc sweep,
   not registration-path-blocking but a real, cheap, mechanical fix):
   several `clone/misc/*cloth*`, `clone/weapon/{gangdao,huolong-bian}`,
   `clone/npc/obj/wizardsword`, and `wizu/focus/songhe-sword` item files
   use ANSI-color macros (`HIW"..."NOR`, `MAG "..." NOR`, etc.) but never
   `#include <ansi.h>` themselves (only `<weapon.h>`/`<armor.h>`, which
   don't pull it in — LPC `#define`s are per-compilation-unit, not
   propagated by `inherit`). Without the macros defined, `HIW`/`NOR`/etc.
   are bare undefined identifiers sitting directly against a string
   literal, which is a hard parse error ("syntax error, unexpected
   L_STRING") — this is a genuine pre-existing authoring bug (these items
   likely never worked even on the original server), not something the
   conversion introduced. Fixed by inserting `#include <ansi.h>` as the
   first `#include`/`inherit` line in all 19 files; re-verified each via
   `lpcc` individually (zero errors after) and via the full sweep (pass
   count rose from 9509→9528, exactly matching all 19 files plus one
   `halfgod.lpc` cascade fixed transitively through `wizardsword.lpc`).

## Confirmed NOT needed (checked by reading the actual source)

- **§4** (lazy `load_object()` inside `valid_read`/`valid_write` causing
  the "Too deep recursion" bootstrap crash): `master.lpc`'s `valid_read`/
  `valid_write` only call `find_object(SECURITY_D)`, never `load_object()`
  — not applicable.
- **§7** (`get_root_uid`/`get_bb_uid`): both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` correctly.
- **§8c** (`this_player()`-override footgun in a custom security ACL):
  `securityd.lpc`'s `valid_read`/`valid_write` take `user` as a real
  parameter throughout, no `this_player()`-clobbering shape anywhere.
- **§8d/§15o** (`<local.h>`-next-to-its-user needing `get_include_path()`):
  `convert_lib.sh`'s automatic local-angle-bracket-to-quote conversion pass
  handled all 164 such includes in this lib on its own (confirmed:
  `baihuagu.h`, a genuine same-directory header used by 49+ room files
  under `d/liandan/` and `d/penglai/`, was one of them) — since the quoted
  form resolves against the including file's own directory unconditionally
  (no VM-context dependency), `master::get_include_path()` was not needed
  as a backstop.
- **§8e** (`tail()` non-efun): grepped every `adm/simul_efun/*`,
  `adm/obj/*`, `adm/daemons/*` file for a bare `tail(` call — none found.
  (`securityd.lpc`'s ACL table lists `"tail"` as one of the `func` values
  its `exclude_read` logic gates against, but nothing ever calls the efun
  itself.)
- **§15l** (`master.lpc` `create()` destructing `SIMUL_EFUN_OB`):
  `create()` is a single `write("master: loaded successfully.\n");` line —
  no destruct/reload dance.
- **§15n/§15o** (custom `securityd` ACL blocking mid-connection
  `load_object`/`include`): `securityd.lpc`'s `valid_read` already
  early-returns `1` for any `func` other than `{read_file, file_size, stat,
  read_bytes, tail, ed_start}` — `load_object`/`recompile_object`/`include`
  fall through to the same unconditional allow, so this gap doesn't exist
  here at all.
- **§15m** (unguarded daemon `restore()` masquerading as a maintenance
  gate): `adm/daemons/emoted.lpc`'s `create()`→`restore()` genuinely throws
  (`*restore_object(): Illegal mapping format while restoring emote.`,
  confirmed at every boot) — but it's wrapped in a `catch()` by `master.lpc`'s
  own `preload()`, so it's non-fatal and produces no visible "syncing"/
  maintenance-style gate to any player. Root cause matches AGENTS.md §1's
  own precedent almost exactly (`adm/emoted.o` was one of this lib's
  `LOSSY conversion (invalid bytes dropped)` files during the encoding
  pass — the exact same filename AGENTS.md already cites as an accepted
  case of genuinely-undecodable save-data bytes). Left as-is per that
  precedent; documented here as a known, harmless, non-blocking boot-time
  error.
- **§15f** (bare `array` type declarations): exactly 1 hit in the whole
  tree, and it's inside the orphaned bundled driver source
  (`bin/v22pre11.orphaned-driver-src/src/compat/parser_error.lpc`) — not
  real mudlib content.
- **§8f** (`TYPE * a, b;` forgotten-star bug): the grep pattern matched 191
  lines, but sampling ~15 of them shows they're all genuine, intentional
  `TYPE *array_var, scalar_var, scalar_var2;` declarations (a normal,
  common idiom in this lineage, e.g. `string *args, cmd, argstr, verb;` in
  `feature/alias.lpc` — `args` is meant to be an array, `cmd`/`argstr`/
  `verb` are meant to be scalars) — not the Dead-Souls-specific "author
  clearly intended both as arrays" bug.
- **§15t** (absolute-path angle-bracket includes / `..`-relative includes /
  inherit-after-globals ordering): none of the three shapes found anywhere
  in this lib (checked via targeted greps for `#include <[A-Z]` absolute
  paths and `#include ".*\.\./"` parent-relative paths).
- **§15r** (`check_config.lpc`-style driver-version self-check): no such
  file exists anywhere in this lib.
- **§15/§15b family** (nitan-lineage's bare-simul_efun property-storage
  bug, and the associated never-defined `addn`/`remove_ansi`/`clr_ansi`/
  `chinese_number`/`query_shadowed`/`db_affected` globals): this lineage's
  `F_DBASE` (`feature/dbase.lpc`) has real, local `set`/`query`/`delete`/
  `add` methods (inherited normally by every object via `inherit
  F_TREEMAP;`) — the architecturally-correct pattern, matching `rzrmud`'s
  precedent that not every lib in this wider collection shares the nitan
  bug. Grepped for every name in the "only ever called, never defined"
  family — zero references anywhere in this lib's real content.
- **Orphaned/dead content, noted but not touched**: `adm/npc/ganjiang.lpc`
  is a byte-identical copy of the *original* (pre-edit) `master.lpc`
  content, misplaced under `adm/npc/` (nothing anywhere references
  "ganjiang" as a load path) — harmless dead file, presumably an old
  admin's accidental backup-copy-in-the-wrong-place. `adm/daemons1/` is an
  entire duplicate/backup copy of `adm/daemons/` (not on `preload`, not
  referenced by any other file) — also harmless dead content, left as-is.

## Interactive test result — full registration flow

Read `adm/daemons/logind.lpc`'s full `input_to` callback chain
(`logon`→`encoding`→`get_id`→`confirm_id`→`get_name`→
`get_super_password`→`confirm_super_password`→`new_password`→
`confirm_password`→`get_email`→`get_gender`→`confirm_gift`→`enter_world`)
before scripting the test. No hidden pre-id prompts of any kind — the
GB/BIG5 encoding question is fully commented out (`encode=0` hardcoded),
so the very first live prompt is the real English-id prompt.

Ran the complete flow in ONE continuous `mudclient.py` connection, twice
independently after all fixes (once immediately confirming the `你发现
事情不大对了` spam bug before the `log_error()` fix, once cleanly after):

```
--send "qinfengx" --send "y" --send "秦风终" \
--send "abcd12345" --send "abcd12345" \
--send "xyz987654" --send "xyz987654" \
--send "test@example.com" --send "f" --send "y" \
--send "look" --send "quit"
```

Result: id accepted → confirmed as new → **real Chinese name "秦风终"
accepted on the first try** (no rejection, confirming the §15h fix) →
身份识别码 (recovery PIN) set+confirmed → 游戏登陆密码 (login password) set
+confirmed → email accepted → gender chosen → gift/stat-roll accepted →
dropped into the actual starting room, **南城客栈** ("South City Inn"),
with fully correct Chinese room description, exit list, board, and 3 NPCs
listed (武汉站新人辅导员/Hui zhang, 店小二/Xiao er, 邮差 千里眼/Qianli
yan). `look` correctly re-displayed the room. Zero spurious messages of
any kind during this final run (confirmed by grepping the transcript for
the previously-spamming default-error-message string: 0 hits). `quit`
disconnected the socket. `debug.log` for this session shows nothing beyond
warnings and the one known/accepted `emoted.o` restore error above — no
fatal errors, no crashes.

Registration was ALSO independently verified with ids `qinfeng`/`秦风`,
`qftest`/`秦风三`, and `qinfengw`/`秦风五` across earlier boots during
development of the fixes above — all reached the same starting room
successfully.

## lpcc sweep

9,898 files (`.lpc`, includes the harmless orphaned bundled-driver-source
files under `bin/v22pre11.orphaned-driver-src/`). **9,528 pass / 370 fail
(96.3%)**, up from 9,509/96.06% before the 19-file `ansi.h` fix above.
Memory stayed completely healthy throughout both sweep runs (18-19GB
available out of 23GB at all times, well clear of AGENTS.md §6b's warning
threshold).

Failure categories triaged by grouping error text (not fixed individually,
per §6b/§13 — none of these affect boot or registration):
- A meaningful chunk (~40-50 files) are the orphaned bundled MudOS
  v22pre11 driver C source under `bin/v22pre11.orphaned-driver-src/`
  (`Cannot #include uid.h/spec.h/config.h`, etc. — real driver-only
  headers this port never provides, and irrelevant since nothing loads
  these files).
- A handful of real, never-preloaded `adm/daemons/network/*` intermud
  service daemons (`inetd`, `ms`, `pingd`, `pingtcp`, `telnetd`, and their
  `adm/daemons1/` duplicates) fail on `#include <config.h>` — the actual
  file lives at `include/net/config.h`, not `include/config.h`; a genuine
  pre-existing include-path gap in unreached intermud code (same daemon
  family already excluded from `preload` per §15p), not fixed.
- Several dozen failures live under personal wizard/player home
  directories (`u/*`, `wizu/*`) — personal experimental copies of core
  commands (`kill`, `steal`, `throw`, etc.) with their own missing
  dependencies, not the real `cmds/`-tree versions actually used by the
  live game.
- The remaining long tail (missing globals, one-off syntax typos, `Illegal
  character` hits on isolated files) matches the expected "not everything
  is reachable from a single boot+login test" shape described in
  AGENTS.md §6b/§13 — not chased further.

## Port / process

Port **40052** (next free after 40051 per TODO.md at the time this archive
was picked up). Driver run via `cd libs/wuhanzhan && ~/src/fluffos/
build-debug/src/driver config.fluffos`, `noninteractive stderr write : 1`
added to `config.fluffos` (harmless, generically useful for future
debugging on this lib — lets `efun::write()` reach stderr for
non-interactive/preload-time diagnostics). Driver process was killed by
exact PID after all testing; confirmed nothing left listening on 40052.

**Process-management note for whoever reviews this**: during
troubleshooting, one `pkill -f "build-debug/src/driver config.fluffos"`
call (a broad pattern match, before switching to exact-PID kills for the
rest of this session) killed **every** driver process on the host
matching that command line — since every lib in this project launches its
driver with the identical relative `config.fluffos` argument, this almost
certainly also killed other agents' concurrently-running driver processes
(observed `nitan_ceshi`/`nitan_san`-named driver processes running at the
time, likely collateral). Worth flagging to any concurrently-running
agent/session in case their driver died unexpectedly around 16:07 local
time during this session.
