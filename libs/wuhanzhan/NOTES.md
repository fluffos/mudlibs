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
es1_win/esI/xkx2001/rzrmud/xo/bmxkx2001/kxkj/
yueyingqiyuan (archives #12/13/25/23/28/45/53/54), sharing the
`adm/obj/{master,simul_efun}` + `adm/simul_efun/` + `adm/daemons/` +
`cmds/{std,wiz,usr,adm,...}/` + `std/` + `obj/` + `d/<zone>/` layout shape.
It is NOT byte-identical or even structurally close to any single prior ES
II lib checked (confirmed via `diff` against `mhxyqd`'s/`mhxy`'s
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
"archive bundles a driver too" situation seen on `xyj2000f` and
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

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 9898 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 9829 written, 66 already
  idempotent-clean, 3 refused by the tool's own token/byte-identity guard
  (expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log` (exact-PID
  kill used throughout, no broad `pkill`). Full registration flow
  re-verified with a fresh real Chinese name (`秦风终七`/id `qretest`),
  reaching the actual starting room (`南城客栈`), `look`/`score`/`quit`
  all producing correct output — no regressions from either the driver
  rebuild or the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `wasmwhz` → real Chinese name `秦坤` → recovery
  PIN/login password/email/gender/stat-roll accept → landed in the same
  `南城客栈` starting room, `look`/`quit` both produced correct output.
  This lib has **no IP-format-dependent login gate**, so it isn't
  affected by the known `query_ip_number()` WASM limitation — fully
  playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

Gates found and patched (AGENTS.md §1.3b/§1.3e/§1.5):

- `adm/daemons/logind.lpc` `encoding()` (~line 107 onward) — the whole
  address-gate block (create_char_banned/is_banned destruct, strict-ban
  destruct, `!ip_name` destruct, and the non-numeric-ip-character
  destruct loop) is now wrapped in an else-branch that only runs for a
  well-formed, non-loopback dotted-quad; loopback / "127."-prefix /
  empty / malformed ips (the WASM shapes) skip it entirely and are
  normalized to "127.0.0.1"/"localhost".
- `adm/daemons/band.lpc` — added a shared `is_local_addr()` helper;
  `is_banned()`, `create_char_banned()`, `is_strict_banned()` all
  short-circuit return 0 for local/malformed addresses.

**Retrofitted fail-open → fail-closed (2026-07-24)**: `is_local_addr()`
and the `logind.lpc encoding()` address-gate condition were both
originally written so that ANY malformed/non-string ip was treated as
local — defensive against the old WASM driver bug where
`query_ip_number()` returned garbage for every WASM connection. That
driver bug is now fixed (WASM reports a clean `"127.0.0.1"` same as
native), so there is no remaining justification for "can't parse it" ⇒
"must be loopback". Changed:
  - `band.lpc is_local_addr()`: `!stringp(site) || site=="127.0.0.1" ||
    strsrch(site,"127.")==0 || sscanf(site,"%*d.%*d.%*d.%*d")!=4` →
    `stringp(site) && (site=="127.0.0.1" || strsrch(site,"127.")==0)`.
    Its three callers (`is_banned`/`create_char_banned`/
    `is_strict_banned`) each got an added `if (!stringp(site)) return
    1;` right after the `is_local_addr()` check, so a non-string site
    is now treated as banned (deny) instead of falling into the
    `regexp()` match on a non-string array element.
  - `logind.lpc encoding()`: the condition deciding whether the whole
    non-loopback address-gate block runs was `!stringp(ip_number) ||
    ip_number=="127.0.0.1" || strsrch(ip_number,"127.")==0 ||
    sscanf(ip_number,"%*d.%*d.%*d.%*d")!=4` (true ⇒ skip every gate
    below AND coerce `ip_number` to `"127.0.0.1"`). Replaced with a new
    `is_local` local computed as `stringp(ip_number) &&
    (ip_number=="127.0.0.1" || strsrch(ip_number,"127.")==0)`; only
    that now skips the gate block. An unparseable/non-string
    `ip_number` falls into the else-branch and goes through the real
    ban/strict-ban/name checks and the digit-validation loop, same as
    the pre-WASM original code (which would legitimately `destruct()`
    a connection whose reported ip isn't a clean dotted-quad — no
    longer expected to trigger for WASM now that the driver bug is
    fixed).
- No `uptime()` startup gate and no per-IP multi-login/registration
  throttle exist in this lib (the id_count flood counter is per-
  connection, not per-IP; MAX_USERS is a global cap) — nothing else to
  exempt. The 10-minute kickout penalty is game design — kept.

Admin account: id `fluffos`, login password `Mud@2026`, recovery PIN
(身份识别码) `Pin@2026a`, name 浮浮, granted `(admin)` (top rank) via
`adm/etc/wizlist`. Verified: login shows 权限：(admin), `update
/adm/daemons/band` → 成功.

Save files for the orchestrator to force-add (untracked, not gitignored):
- `libs/wuhanzhan/work/data/user/f/fluffos.o`
- `libs/wuhanzhan/work/data/login/f/fluffos.o`

Retest: fresh normal registration (qinshier / 秦十二) lands in 南城客栈,
look/score/quit correct, zero 执行时段错误 in transcript and debug.log.
Test char removed (fluffos kept).

**Re-retest after the fail-closed retrofit (2026-07-24)**: fresh boot,
fresh registration (id `qretest`, real Chinese name 秦十三, PIN
`Pin@2026a`) through `look`/`score`/`quit` — landed in 南城客栈,
`score` output correct, clean quit. `fluffos`/`Mud@2026` admin login
re-verified: `look` then `update /adm/daemons/band` → `成功！` (cosmetic
compile-warning spam shown to the player as usual, no actual error),
then clean `quit`. `debug.log` had exactly the one pre-existing,
already-documented boot-time `emoted.o` restore error (caught by
`master.lpc`'s `preload()`, harmless — see the §15m entry above) and
zero NEW runtime errors. Test char `qretest` removed afterward;
fluffos kept.

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib (all prior passes verified only
registration + `look`/`score`/`quit` + admin login, or watched boot
output). Read `doc/help/newbie` first (a generic, shared-template "西游记
新手指南" — branding mismatch from "大话西游" but its content matches
this lib's actual starting room/mechanics exactly: 南城客栈, `fight` vs
`kill`, `learn`/`skills`/`practice`, `apprentice`/`bai`, `hp` bars,
`buy ... from ...`), then played native (`build-debug`) via
`scripts/mudclient.py`. **Two real, live, first-ever-visit "Too deep
recursion" crash bugs were found and fixed** — this pass is the third
lib (after `bxsj` §7.16 and `xiyouji` §7.17) where a genuine playthrough
caught something no earlier boot/registration pass ever could.

Test character: id `qiufeng`, Chinese name **秋风然**, password
`Passwd2026` — **kept** as the representative playthrough character
(save files `work/data/user/q/qiufeng.o`, `work/data/login/q/qiufeng.o`).
State: 潜能 105499, 道行 一百十年, skills dodge/force/literate/parry/
spells all 60 (from the newbie-gift NPC) plus unarmed 60/32 (from the
organic teacher-NPC `learn` path below); inventory: one 粗布衣 (default
linen robe, re-granted on full login per the quit-drop mechanic already
documented above). A second, throwaway id `linfeng`/秦风起 was used
during the bug-hunting phase and its save files were deleted afterward
(not kept — messier state, no incremental evidence value once `qiufeng`
existed).

### Bug 1 (existing class, §6.1) — absolute-path angle-bracket include silently voided a book item, first found via a room-first-visit crash

`d/obj/books-nonskill/book-qujing.lpc:7`: `#include </d/qujing/obstacle.h>`
— an ABSOLUTE path inside angle brackets, which per AGENTS.md §6.1 never
resolves on this driver (the `<>` resolver doesn't special-case absolute
names). This is the exact, already-cataloged bug class — just not
previously found in this lib, because the earlier pass's grep for it
(`#include <[A-Z]`, see this file's own "Confirmed NOT needed" §15t
entry above) was case-sensitive and only matched absolute paths starting
with an uppercase letter; this one starts lowercase (`/d/...`) and slid
through. Whole-lib rescan with `grep -rn '#include <\/' --include='*.lpc'`
found exactly this one occurrence lib-wide.

- Symptom: walking a fresh character `west` out of 南城客栈 into
  `d/city/zhuque-s1` (朱雀大街) for the first time after a boot showed
  the scary default error message
  (`你发现事情不大对了，但是又说不上来。`) to the player, followed by a
  full genuine trace in `work/log/RUNTIME_ERRORS` (this lib's
  `master::error_handler()` fix from an earlier pass, §15u, made this
  catchable at all): `zhuque-s1.lpc`'s `create()`→`setup()`→`reset()`→
  `make_inventory("/d/city/npc/jieding")` clones the NPC 疥顶小僧
  (`npc/jieding.lpc`), whose own `create()` does
  `carry_object("/d/obj/books-nonskill/book-qujing")` — and `new()`ing an
  object whose only compile error is the bad `#include` throws `*No
  program in object '/d/obj/books-nonskill/book-qujing'!`, uncaught,
  right in the middle of the room's own `create()`.
- Fix: `#include </d/qujing/obstacle.h>` → `#include "/d/qujing/obstacle.h"`
  (quoted form resolves an absolute path unconditionally, matching
  AGENTS.md §6.1's documented fix). Re-verified with `lpcc`
  (`PASS /d/obj/books-nonskill/book-qujing`, previously a hard compile
  error) and live (`west` from 南城客栈 into 朱雀大街 on a fresh boot: no
  error message, clean room description).

### Bug 2 (NEW bug class, draft below) — calling `enable_player()`/`enable_commands()` from `init()` (not `create()`) makes a room's first-ever visit call the room's own NPC's `init()` recursively until "Too deep recursion"

Found while walking `qiufeng`/`linfeng` from 南城客栈 to 将军府
(General Qin's mansion, `d/jjf/`) to test the sect/apprentice mechanism
— the room `d/jjf/front_yard2` (`练武场`, home to the sect's `掌门大师兄`
identity-succession NPC, `d/jjf/npc/zhangmen.lpc`) crashed with the same
scary default-error message on its first-ever visit, **every single
time**, reproduced across five independent fresh-boot attempts before
being root-caused and fixed. Player-visible symptom matched §7.17's own
prior description almost exactly: the room is still entered, but the
NPC's title renders with a stray leading `"0"` (`0掌门大师兄 大弟子`)
— corrupted state from the crash, not a content typo.

**Diagnosis** (the two false leads, then the real one — kept here since
neither is obvious from reading the code cold):
1. First suspected §7.17's own two documented shapes verbatim
   (`std/room.lpc`'s `setup()`→`reset()` reentrancy, and `zhangmen.lpc`'s
   `create_identity()` self-locating its room via a forced
   `call_other(path,"???"); find_object(path)` instead of
   `environment(this_object())`, exactly the §7.17 "belt-and-suspenders"
   anti-pattern). Fixed BOTH proactively (a `nosave int resetting_now;`
   reentrancy guard added to `std/room.lpc reset()`; `create_identity()`
   changed to prefer `environment(this_object())` when it already
   matches the hardcoded `where` path). Both are real, safe, permanent
   improvements — kept — but **neither one stopped the crash**: `debug.log`
   still showed `Too deep recursion` on the exact same two lines
   (`zhangmen.lpc:39`/`:626`) after both fixes, on a genuinely fresh boot.
2. `debug.log`'s terse `Too deep recursion` lines (unlike a normal LPC
   error, this class doesn't get a full call-argument trace in
   `RUNTIME_ERRORS` — the interpreter can't safely unwind through
   `master::error_handler()`'s own apply when the stack is already
   exhausted) gave only single stack frames, not a call chain. Per
   AGENTS.md §10.3, switched instrumentation from `write_file()` to
   `efun::write()` (write_file's own ACL check needs stack headroom too,
   and was silently swallowing the diagnostic lines closest to the
   actual crash). With that, the real shape became visible: **the SAME
   `zhangmen#66` object's `init()` was being called over 40 times in a
   row, each nested call starting before the previous one returned**,
   every single time reporting `caller=/obj/user#1` (the connecting
   player) — a real reentrant self-loop, not a room re-populating twice.
3. `zhangmen.lpc`'s `init()` ends with an unconditional `me->setup();`
   (also reachable via `me->reset_me(me)`'s own internal `setup()` call
   a few lines earlier) — redundant, since `create()` already called
   `setup()` once before the object was ever moved into a room.
   `std/char.lpc`'s `setup()` calls `enable_player()`
   (`feature/command.lpc`), which calls the real efun
   `enable_commands()` with no explicit argument. Per this driver's own
   docs (`~/src/fluffos/docs/efun/interactive/enable_commands.md`,
   BUGS section): *"Do not call this function in any other place than
   create() or strange things will likely occur"* — calling it with a
   truthy/default `setup_actions` re-runs `init()` on the object's
   environment, siblings, AND own inventory as a side effect. Calling
   `enable_player()` a SECOND time on an object that's already living
   (i.e., from `init()`, not `create()`) makes the driver call that
   object's own `init()` again while the current `init()` call is still
   on the stack — genuinely reentrant, repeating until the driver's
   call-depth limit aborts.

**Fix** (`feature/command.lpc`'s `enable_player()`, the single shared
entry point every `setup()` call in this lib routes through): added
`if (living(this_object())) return;` as the very first line.
`living()` reliably reflects whether `enable_commands()` has already
run for this object, and `disable_player()`'s own path (`disable_commands()`
immediately followed by `enable_commands()` again) still works
correctly since it calls the real efun directly, not through
`enable_player()` — so the guard is inert for every legitimate call site
(the original `create()`-time call, or any post-`disable_player()`
re-enable) and only blocks the pathological repeat-call case. Verified:
5 independent fresh-boot reproductions before the fix (100% reproduction
rate, `debug.log` showing `Too deep recursion` at
`securityd.lpc:178`×1-6 then `zhangmen.lpc:39`/`:626`×2 every time);
zero reproductions in 3 independent fresh-boot retests after
(`RUNTIME_ERRORS`/`debug.log` both clean except the one pre-existing,
already-documented `emoted.o` preload error). The stray `"0"` in the
NPC's title is also gone post-fix (`将军府掌门大师兄 大弟子`, correct).

**Scope**: `d/jjf/npc/zhangmen.lpc` was the only one live-reproduced
(it's what a fresh character's most direct sect-mansion route reaches
first), but the identical `create_identity()`/`init()` shape — including
the same redundant `me->setup();` — is copy-pasted into every other
sect's "掌门/大师兄" identity-succession NPC in this lib: confirmed
byte-identical via script across **27 more files**
(`d/nanhai,xueshan,tianwang,sea,moon,lingtai,death,shaolin,mojiao,
shushan,qujing/{wudidong×2,wuzhuang,pansi×3},lingjian×2/npc/zhangmen*`,
plus `d/npc/zhangmen.lpc` — dead/unreachable, no room ever places it —
`d/zhangmen.lpc`, and personal-wizard-dir copies under
`u/{moonr/sadboy,qlwy,sadboy}/.../zhangmen*.lpc`, `wizu/focus/zhangmen.lpc`).
Applied the SAME `create_identity()` `environment()`-preference patch to
all 27 by exact byte-for-byte block match (verified via `lpcc --batch`,
all 28 total `PASS`) — proactive fix by code-shape match, not
individually live-reproduced, per the `xiyouji` §7.17 precedent ("only
one was live-reproduced, the rest fixed proactively"). The root
`enable_player()` guard in `feature/command.lpc` protects ALL of these
(and anything else in the lib with the same misuse shape) uniformly,
since it's the single shared choke point every `setup()` call routes
through — this is why the fix was placed there rather than patched
per-file.

**Cross-lib risk flagged, not chased further (out of this task's
scope)**: `wuhanzhan` is documented in AGENTS.md §11 as a `大话西游`
sibling of the 西游记/xiyouji.org ES II branch, and this exact
"神话世界·西游记·版本4.50"-headered `create_identity()`/`init()`
template (header comment only — NOT proof of shared codebase, per this
file's own earlier caution) appears, per `grep -rl "神话世界"
libs/*/work --include='*.lpc'`, in **60 different libs** in this
corpus. Any of them that also calls `setup()`/`enable_player()` from
`init()` (not just `create()`) is a candidate for the same crash on
first room visit — worth a targeted grep
(`grep -rln 'me->setup();' <lib>/work --include='*.lpc'` cross-referenced
against which of those hits are inside a `void init()` function) on a
future pass through any sibling, rather than assuming this fix's scope
stops at `wuhanzhan`.

### What else was tested and confirmed working

- **Registration**: real Chinese name (秋风然), full flow, landed in
  南城客栈; `look`/`score`/`i` all correct at every state change
  (fresh, post-gift, post-skill-learn, post-combat, post-relogin).
- **Newbie-gift shortcut**: `d/city/npc/xiaoer`/`bigeye`/`u/lol/npc/newbie`
  in the start room — `ask hui zhang about 红包` (`u/lol/npc/newbie.lpc`
  `do_bu()`) granted 100,000 潜能 + 150 年道行 + six base skills at 60,
  gated correctly behind `mud_age`/one-time-only checks (confirmed the
  second `ask` on the same character correctly declined with "你已经
  领过新手援助啦").
- **Movement/exploration**: walked 南城客栈→长安武馆 (5 moves:
  west/north/north/north/east) and 南城客栈→将军府正厅 (8 moves via
  `d/jjf/`, gated by 秦安's `answer 拜师` challenge at the mansion gate
  — `d/jjf/gate.lpc`'s `valid_leave()`, confirmed both the blocked
  path — `south` 3× before answering, correctly rejected each time —
  and the correct unblock after `answer 拜师`).
- **Skills — organic teacher path**: `d/city/npc/jiaotou.lpc`
  (范芦平, 武馆教头, `recognize_apprentice()` hardcoded `1` — teaches
  ANY player, matching `bxsj`'s equivalent pattern) via `skills fan`
  (room-level `do_skills` override in `wuguan.lpc`, lists his 4 base
  skills) → `learn unarmed from fan` (correctly required 悟性-scaled 精
  cost, correctly capped the gain at the teacher's own skill level,
  correctly showed the "已经不输为师了，一起切磋" message once caught
  up) → `skills` (own skill list) confirmed the gain (unarmed 60/32).
- **Sect/faction-join mechanism**: found and exercised
  `cmds/std/apprentice.lpc` (`apprentice`/`bai`) against
  `d/jjf/npc/qinqiong.lpc` (秦琼, 将军府/JJF sect master,
  `attempt_apprentice()` unconditionally accepts — but gated by a
  `combat_exp >= 100000` floor first) — correctly rejected a fresh
  character ("这位小兄弟还是先去跟本府家将打打基础吧！") since even
  post-newbie-gift `combat_exp` is far under that floor. Confirms the
  mechanism is real, reachable, and correctly gated; **not completed**
  (no sect actually joined) since clearing the floor needs real combat
  grinding — explicitly left as unverified-live rather than chased
  further, honestly noted here rather than silently skipped.
- **Combat**: `fight <target>` (not `kill`) against `d/city/npc/dizi.lpc`
  (武馆弟子, a weak generic trainee NPC stationed alongside the
  teacher at 长安武馆 — this lib's non-lethal default combat verb
  itself is the "safe sparring" mechanism per `help combat`, rather
  than a single dedicated training-dummy NPC like `bxsj`'s `muren`;
  `fight` "只持续到一方昏迷、认输或逃走"). Combat ran a normal round or
  two (attack power drifted 1191→1181→1141 across the session from
  normal wear, no HP/kee crisis) and ended safely with no crash, no
  over-death — confirms this lib's built-in fight/kill distinction
  works as `help combat` documents.
- **Shop**: `d/city/kezhan.lpc`'s 店小二 (Xiao er) — `list` correctly
  showed the goods menu (水晶球/挑战金牌/红烧狗肉/下棋指南/桂花酒袋/
  天赋丹/养身丹); `buy jiudai from xiao er` correctly rejected with
  "你的钱不够" (a fresh character has 0 money by design — no starting
  cash grant found anywhere in the registration flow). **Not
  completed** (no successful purchase) — same honest-gap flag as the
  sect-join above; the `buy`/`list` mechanism itself is confirmed
  working end-to-end except for the money precondition, which would
  need either combat loot or the pawn-shop/bank systems, out of this
  pass's time budget.
- **Death/respawn**: **not tested live** — same as `bxsj`'s own honest
  gap for this checklist item. Not chased given the sect-join and
  shop gaps above were already the priority uses of remaining time,
  and after the two live crash-bug fixes this pass already ran long.
  Left as a concrete to-do for whoever plays this lib next.
- **`quit` + debug.log**: grepped `debug.log`/`RUNTIME_ERRORS`
  immediately after every `quit` in this pass (not just after the two
  bugs above) — zero new errors beyond the one pre-existing, already
  documented, harmless boot-time `emoted.o` restore failure, on every
  check.
- **Persistence**: confirmed both layers — (a) *silent reconnect*
  (mid-fight disconnect/reconnect resumed at the same room with combat
  already resolved safely, no data loss); (b) *full quit+relogin* (real
  `save()`/`restore()`) — 道行/潜能/all 6 skills/inventory (the 粗布衣
  re-grant) all round-tripped correctly across a genuine `quit` →
  real wall-clock wait (~40s) → fresh reconnect → `look`/`score`/`i`/
  `skills` cycle, landing back in 南城客栈 (full login, not silent
  reattach, matching the explicit-quit-vs-reconnect distinction
  documented elsewhere in this file and in `bxsj`'s own NOTES.md).

### Draft new AGENTS.md bug-class entry (for the orchestrating session)

Proposed as a new §7.18 (or a sibling case folded into §7.17's own
"first-ever-visit reentrancy" family, orchestrator's call), title:
**"Calling a create()-only driver primitive (`enable_commands()`/
`enable_player()`) from `init()` reentrantly re-triggers that same
object's own `init()`, crashing a room's first-ever visit."**

Body draft: This driver's own docs
(`efun/interactive/enable_commands.md`, BUGS section) state plainly:
*"Do not call this function in any other place than create() or
strange things will likely occur."* `enable_commands()` (with no
explicit `setup_actions` argument, or any truthy one) re-runs `init()`
on the calling object's environment, siblings, AND inventory as a
documented side effect — a normal, intentional mechanism for "an object
just became live/interactive, re-announce it to everyone nearby." If a
mudlib's shared `setup()`/`enable_player()` wrapper (a common pattern:
`create()` calls `setup()` once to configure a fresh object, and some
OTHER code path — an NPC's own `init()`, a `reset_me()`/respawn helper,
a "wake up"/"revive" handler — ALSO calls the same `setup()` later,
expecting it to just be idempotent stat recalculation) is reachable
from `init()` itself, the second `enable_commands()` call re-triggers
`init()` on the SAME object while the first `init()` call is still on
the stack — genuinely reentrant, not a one-shot double-call, because
each new `init()` invocation runs the same `setup()` line again,
compounding until the driver's call-depth limit aborts with `Too deep
recursion.` First found+fixed in `wuhanzhan`'s
`d/jjf/npc/zhangmen.lpc` (and 27 structurally-identical sibling sect
NPCs, all sharing a "神话世界·西游记" template) — its `init()` calls
`me->setup()` (both directly and via `reset_me()`), redundant with
`create()`'s own earlier `setup()` call, and that redundancy is what
triggers the cascade. Symptom shape mirrors §7.17 closely (first-ever
room visit only, invisible once objects are warm in memory, corrupted
NPC state showing as a stray literal `"0"` in a title/name field) but
the mechanism is a different, more general driver-API-misuse class —
not a room-reset double-fire, and not a hardcoded self-locate path —
so it can recur in ANY lib whose `setup()`-style wrapper calls
`enable_commands()`/`enable_player()` and is reachable from anywhere
other than `create()`, independent of lineage. **Detection**: grep for
`enable_commands(` / `enable_player(` call sites, then check whether
each one's enclosing function is reachable from `init()` (directly, or
transitively through a same-purpose "recover"/"reset_me"/"revive"
helper) rather than only from `create()`. **Fix**: guard the
`enable_player()`-equivalent wrapper itself with
`if (living(this_object())) return;` at its top (inert for every
legitimate call site — first-time `create()`, or any real
post-`disable`-re-enable — since `living()` tracks exactly whether
`enable_commands()` already succeeded for this object) — a single,
low-risk, shared choke-point fix rather than patching every individual
redundant `setup()` call site.

### Process hygiene note for this pass

The native driver for this lib was restarted many times during the
bug-2 diagnosis (each fresh-boot repro needed a truly first-ever
`front_yard2` visit); every restart used the exact recorded PID for the
kill, `ss -tlnp`-verified before starting the next one. One collision
found mid-pass: a driver already listening on port 40052 at session
start turned out to be a DIFFERENT lib's process (`rzrmud`, confirmed
via `readlink /proc/<pid>/cwd`) that happened to be bound to this port
from a stale prior run — not killed, left alone, this lib's own driver
was simply started on its correct configured port after confirming the
mismatch. Temporary `efun::write()`/`write_file()` diagnostic lines
added to `d/jjf/npc/zhangmen.lpc` and `std/room.lpc` during the bug-2
diagnosis were fully removed before the final commit-ready state (only
the two real structural fixes remain in those files); no `DBGTRACE.log`
or other scratch file was left behind. Runtime side-effect files
touched incidentally by testing (`u/npc/log`, `u/sadboy/log` —
per-wizard-dir compile-warning logs; `data/zhangmen/zhangmen_qin_qiong.o`
— an NPC's own save data) were reverted to their pre-session committed
state, keeping the diff limited to the intentional source fixes plus
this NOTES.md update plus the `qiufeng` test-character save files.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 64 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `1400000` 提升
   到 `5000000`（本项目标准安全值，预防性调整，此前的值本身未被确
   认在风险区间内）。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
3. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第九条独立确认
   的血统）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

**复核确认非 bug**：`update`/`score` 等指令首次惰性编译时，管理员
账号屏幕上出现"编译时段错误：...Warning: Unused local variable"这
类原始编译诊断文字——这是 `master.lpc::log_error()`（AGENTS.md
§15u，本档案自己第一轮已修复并留有详细注释）的**既有设计**：巫师
账号（`wizardp(this_player(1))`）本来就应该看到完整原始编译诊断，
只有非巫师普通玩家才走过滤警告的分支。本轮误以为是泄漏又重新核对
了一遍代码，确认这是正确行为，未做任何改动。

`cmds/wiz/update.lpc`（§7.106）已经是正确写法；本档案无
`adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录确认
`您已经成功登陆游戏！目前权限：(admin)`，`update /adm/daemons/
logind` 成功验证真实写入权限。踢掉重复登录重连路径现场验证通过
（见上）。`debug.log` 全程干净（710 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/obj/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 375 live occurrences deleted: 368 via scripted sweep (`fix_710_room.py`), plus 7 hand-fixed roommaker-tool templates across 5 separate tool copies (`clone/misc/roommaker.lpc`, `obj/roommaker.lpc`, `d/obj/clone/misc/roommaker.lpc`, `u/ken/obj/roommaker.lpc` — simple variant, 1 each; `wizu/link/obj/roommaker.lpc` — "room_code"/`str` 3-occurrence variant). 10 already-commented-out instances (incl. 2 in `wizu/link/obj/citymaker.lpc`) left untouched. One occurrence NOT fixed: `d/wiz/officer/officer.lpc` has a non-standalone `setup() replace_program(ROOM)` with no semicolons anywhere in its `create()` — this file is already syntactically broken independent of this bug (`inherit ROOM void create() {` is missing its own semicolon), so it never compiles regardless; left alone as out of scope for this sweep. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile (only pre-existing pragma/unused-variable warnings), port 40052 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

## 深度功能测试第三轮 / Deep functional test round three (2026-08-20) — resolved all 3 flagged gaps

Followed up on the three items explicitly flagged as unresolved at the end of the round-two pass above (sect-join, shop purchase, death/respawn), using the kept representative character `qiufeng`/秋风然 plus admin (`fluffos`) `goto`/`summon`/`clone`/`call` to move faster, while letting every actual game-mechanic transition (combat resolution, purchase, death, respawn) run through real, unmodified game logic. Native `build-debug` driver, port 40052, `debug.log`/`RUNTIME_ERRORS` watched throughout.

1. **Sect-join — RESOLVED, works correctly.** `qiufeng`'s `combat_exp` was already 110000 (above `d/jjf/npc/qinqiong.lpc`'s 100000 floor, grown from the round-two combat testing) — the "far under the floor" gap from round two was a stale snapshot, not a live retest. `apprentice qin` (id is `qin`, not `qinqiong` — the two-word `"qin qiong"` alias needs `present()`'s single-token match) correctly triggered `attempt_apprentice()` → `command("recruit ...")`; a second `apprentice qin` completed the join for real: "你恭恭敬敬地向秦琼磕了四个响头，叫道：「师父！」" + "恭喜你成为将军府第三代弟子" — `score` confirmed title changed to 将军府第三代弟子, 师父 秦琼, `family` dbase entry populated (`master_id`, `family_name`, `generation:3`). No admin shortcut was used for the join itself, only to reach qinqiong's room (`d/jjf/keting`) via `goto`+`summon`.

2. **Shop purchase — RESOLVED, real combat-loot income path confirmed working end-to-end.** Traced the actual currency system: `cmds/std/buy.lpc`'s `can_afford()`/`pay_money()` (`feature/finance.lpc`) check real coin/silver/gold/cash **inventory objects**, NOT the `balance` dbase field used by `feature/vendor_sale.lpc`'s bid/deposit shop-ownership-auction subsystem (a red herring — `F_VENDOR_SALE`'s `buy_object()`/`complete_trade()` route purchase payment through `finance.lpc`, not `balance`). The `feature/bankowner.lpc`/`bankpawnowner.lpc` pawnshop/bank system suggested by the round-two note is **dead code** — confirmed via `grep -rn F_BANKOWNER\|F_BANKPAWNOWNER` returning zero hits anywhere in the lib; not a viable income path. Real path: killed `d/city/npc/liumang.lpc` (小流氓, a weak civilian NPC with `add_money("coin", 40+random(90))` in its own `create()`) via the real `kill` command (admin `clone`d fresh instances into a fightable room, `d/city/beiyin4`, since the original wandered off via its own `random_move` chat behavior before it could be engaged — 南城客栈 itself has `no_fight:1`, confirmed real design, so combat has to happen elsewhere). `cmds/std/kill.lpc`'s `do_kill()` has the NPC reciprocally call `kill_ob(me)` on the player whenever `obj->accept_kill(me)` is undefined (true for `liumang`, which doesn't override it) — genuine two-way lethal combat, not scripted. Looted `get all from corpse` for 56 then another 98 coins (154 total, two liumang kills); returned to 南城客栈 via admin `summon`, `list` showed 桂花酒袋(jiudai) priced at 一两银子 (100 raw currency units), `buy jiudai from xiao er` succeeded: "你向店小二买下一个桂花酒袋" — inventory confirmed 154→54 coins deducted (exactly 100) and the jiudai item received. (The purchased item and remaining coins were later dropped on a subsequent unrelated `quit`, per this lib's own already-documented "only worn/equipped items persist via autoload" mechanic — not a bug, the live-transcript proof of the successful purchase/deduction was already captured before that.)

3. **Death/respawn — RESOLVED, full real death→limbo→revival cycle confirmed working, zero debug.log/RUNTIME_ERRORS regressions.** `qiufeng`'s huge combat_exp (110000) and full vitals made this untestable against any actually-reachable early NPC in reasonable time, so used admin `call qiufeng->set(...)` to temporarily reduce `combat_exp` to 200 and `kee`/`gin`/`sen`/`eff_kee`/`eff_gin`/`eff_sen` to 5 each (restored afterward — see below) — purely to get a real fight to a lethal conclusion quickly; the death transition itself ran entirely through unmodified game logic. `kill liumang` (freshly `clone`d) produced real mutual damage; `feature/damage.lpc`'s `receive_wound()` (gated on `me->is_killing(victim)`, true for both sides here since `kill` triggers reciprocal `kill_ob()`) pushed `eff_kee` negative, triggering the real "你的眼前一黑...你死了。" → `die()` → move to `DEATH_ROOM` (`/d/death/gate`, "阴阳界") → **the exact `d/death/npc/pang.lpc` `death_stage()` reentrancy-guarded NPC already verified clean for §7.112 in this same pass's standard-checklist section above** — confirmed live: judge NPC 崔珏 (Cui Jue) dialogue fired correctly, `death_stage()` progressed through its message sequence without any reentrancy/"Too deep recursion" symptom, then `reincarnate()` correctly restored `eff_kee`/`eff_gin`/`eff_sen` to `max_kee`/`max_gin`/`max_sen` and moved the player to `REVIVE_ROOM` (荒郊小庙). `score` post-revival showed the expected death penalty applied (道行/combat rank reduced, per the `death` dbase mapping's own `skill_loss`/`combat_exp_loss` fields — game design, not a bug) and full HP bars (matching the restored `eff_*` caps). Sect membership (`family` dbase entry) survived death correctly. `combat_exp` restored to its real pre-test value (110000) via admin `call`+`save()` afterward so the kept representative character's progression isn't left corrupted by the test scaffolding.

**Bonus fix found via RUNTIME_ERRORS while watching the above (not part of the 3 flagged gaps, found for free):** `master.lpc`'s `log_error()` (the same apply already touched by §15u) unconditionally does `efun::write_file(home + "log", message)` to log every compile diagnostic to the offending file's owner's home directory — but `home = user_path(file_owner(file))` doesn't always point at a real, existing top-level `/u/<name>/` directory: files under a *nested* wizard subdirectory (e.g. `/u/sadboy/pansi/npc/zhangmen.lpc`, one of the 27 §7.17 `create_identity()` sibling fixes from the round-one pass) can carry a euid (`"pansi"`) that only exists as a subdirectory name, not a real home (there is no `/u/pansi/` — only `/u/sadboy/pansi/`). This threw an uncaught `*Wrong permissions for opening file /u/pansi/log for append` runtime error on every boot (confirmed reproducible: appeared in a clean `RUNTIME_ERRORS` on the pre-fix boot for `/u/sadboy/pansi/npc/zhangmen.lpc`'s own benign "Unused local variable" warnings, gone entirely on a fresh post-fix boot). Fixed by wrapping the write in `catch()` — this is a best-effort diagnostic log write, not critical state, so silently swallowing a bad/nonexistent per-wizard home directory is safe and matches this function's already-established defensive posture from the §15u fix. Verified: fresh boot after the fix shows only the one pre-existing, already-documented `emoted.o` restore error in `RUNTIME_ERRORS`, zero `pansi` entries; registration/login/sect-join/combat/purchase/death/respawn all re-verified working post-fix via a fresh `qiufeng` login.

### Standard checklist re-confirmation (2026-08-20)

All already fixed/clean from prior passes, reconfirmed this round without needing new changes:
- **§7.90**: `config.fluffos` `maximum evaluation cost : 5000000` — confirmed already at the standard value.
- **§7.100**: `grep -rn "replace_program(ROOM"` — 12 hits, 11 already commented out, the 12th is the already-documented pre-existing-broken `d/wiz/officer/officer.lpc` (never compiles regardless, out of scope) — zero live occurrences.
- **§7.111**: `master.lpc`'s two `file_name(error["object"])` call sites both already null-guard via `undefinedp(error["object"]) || !error["object"]`.
- **§7.112**: all 5 `death_stage()`-style functions in this lib (`d/death/npc/{pang,wgargoyle,b,bgargoyle}.lpc`, `u/sadboy/b.lpc`) checked branch-by-branch — every exit path (no-ob, not-ghost, hostile-non-ghost, low-max-stat, final reincarnate) correctly clears the `death_stage_active` temp guard before returning; the reschedule branch correctly leaves it set. No incomplete-branch gap found (unlike the `xajh2`/`hhsj`/`nt6nitan6win` instances found elsewhere this session). Live-confirmed working end-to-end by item 3 above.
- **§7.79**: zero bare 2-arg `addn(`/`addn_temp(` calls found.
- **§7.108**: `obj/user.lpc`'s `reconnect()` already calls `enable_commands()` (fixed in the round-two pass above).

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 9 here-document block(s) repaired (2 with the terminator glued to the last text line, 7 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`, `u/skyhawk/cmds/adcp.lpc`, `u/doer/wanju.lpc`, `u/kexin/baigu/baigudong.lpc`, `u/kexin/baigu/baigushan.lpc`, `u/kexin/baigu/banshanpo.lpc` and 3 more. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 where the text sits on the opener's line (`@LONG   text...LONG`, the newlines were lost): `u/kvv/jiaowai.lpc`.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `u/bqt/questd.lpc`、`u/qqzqq/adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 0 个、工作树通过 0 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`d/obj/inherit/weapon/throwing.lpc`、`d/obj/inherit/weapon/fork.lpc`、`d/obj/inherit/weapon/whip.lpc`、`d/obj/inherit/weapon/sword.lpc`、`d/obj/inherit/weapon/axe.lpc`、`d/obj/inherit/weapon/blade.lpc`、等共 9 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py wuhanzhan --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1286 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1233 -> 1233 通过，无回退；改过的头文件的 358 个包含者 343 -> 343 通过。
记录、未改：`story/*.lpc` 六个故事（牛郎、宋代、起床、西游、砸缸、征西）的 `give_gift()` 只剩一句什么也不做的 `HIM "…掉到你面前。" NOR;`——对照 mhxy 的同名文件，原本是 `STORY_D->give_gift("/obj/money/gold", 20, HIM "…" NOR);`。归档里就是这样：只删了 `STORY_D->give_gift(…,` 那一行，续行的缩进还在，征西的奖品描述也从倚天剑改成了万年灵芝。看来是本站有意取消故事奖励、删得不干净（玩家看到"掉到你面前"却什么也没有）。要不要恢复奖励是站务设计，不在本次范围。

启动时警告 59 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 14 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 10 个，只在 #if 分支用的声明移进分支 3 个文件；改动 22 个文件，HEAD 与工作树各载入一次无回退（22 objects; HEAD PASS 20, tree PASS 20; regress 0; newly loading 0），这些文件的警告 70 -> 31。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `story/` 下六个故事（niulang、songdai、wakeup、xiyou、zagang、zhengxi，及 `u/bqt/story/` 副本）的 `give_gift()` 只剩 `HIM "“啪”的一声…掉到你面前。" NOR;` 一行：`STORY_D->give_gift(物品, 数量, 消息)` 调用被删掉、只留下参数，故事结束时从不发奖励。本库 `adm/daemons/storyd.lpc` 有 `give_gift()`，按 mhxy 等同码库补回调用（灵芝、黄金、冰糖葫芦；物品文件都在）。
- 12 个对象载入无回退。

## 深度功能测试（§10.7，2026-10-13）：编译警告清零

- 收尾一轮（toolkit + 手修），新进程分别加载 HEAD 与工作树：39 个对象 38 -> 38 通过，无回退；可编译文件的警告清零。
- `d/kaifeng/ground.h` 的 `modes`/`mode_hints`/`families` 表加 `GROUND_TABLES_INHERITED` 守卫，`ground*.lpc` 与 `kk.lpc` 继承基类时不再重复声明。
- `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`，与 `u/skyhawk/xiaocaishen` 等 NPC 自己的 `last_time` 不再冲突。
- `d/city/npc/yg/yaoguai.lpc`、`d/kaifeng/npc/yg/yaoguai.lpc` 去掉与基类重复的 `yaoguai_type`；`long.lpc`/`nn.lpc` 删掉多余的 `int long();` 原型。
- `kill_ob`、`die`、`unconcious`、`skill_improved` 的 int/void 与基类对齐（调用者不用返回值）；`wizu/focus/toptend.lpc` 有意重定义的宏前加 `#undef`；`huashan-jianfa.lpc` 删多余的 `;`；`xianlvqiyuan` 采用同码库已修好的写法。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemon/class/shaolin/banruo-zhang/banruo.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`break_string()`。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14：1 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：4 个对象，新增载入 3，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

43 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`po`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`liumai-shenjian`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

25 个文件、36 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/suburb/xkx/shaolin/obj/changjian`、`/d/suburb/xkx/city/obj/cloth`）。本库 NPC 基类 `std/char/np.lpc`、`std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 6 个，改后 26 个（20 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`adm/daemons1/network/netmail.lpc`、`include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:20: error: Cannot #include mailer.h；`adm/daemons1/network/netmail`：/adm/daemons1/network/netmail.lpc:20: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/fuxing.lpc`、`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：3/3 通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 8 个对象设了本库没有文件的武功（12 个名字，最多的是 `sevensteps`、`hunyuan-force`、`ruyi-blade`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：8 个里 8 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 12 处、12 个文件：`dragon-step`→`dragonstep`（3 处）、`hellfire_whip`→`hellfire-whip`（3 处）、`lingjian-steps`→`lingjian-step`（2 处）、`lunhun-zhang`→`lunhui-zhang`（1 处）、`yange_blade`→`yange-blade`（1 处）、`huntian-qiong`→`huntian-qigong`（1 处）、`dangmo_axe`→`dangmo-axe`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/city/liangdian2` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 13 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/shaolin/obj/basi-shanyao.lpc`、`/d/shaolin/obj/bocai-fentiao.lpc`、`/d/shaolin/obj/changjian.lpc`、`/d/shaolin/obj/furong-huagu.lpc`、`/d/shaolin/obj/hulu.lpc`、`/d/shaolin/obj/jiaxin-biji.lpc`、`/d/shaolin/obj/jiedao.lpc`、`/d/shaolin/obj/liuli-qiezi.lpc`、`/d/shaolin/obj/mala-doufu.lpc`、`/d/shaolin/obj/mizhi-tianou.lpc`、`/d/shaolin/obj/qimeigun.lpc`、`/d/shaolin/obj/shanhu-baicai.lpc`、`/u/bqt/quest/gift/yitianjian.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`；`/u/moonr/sadboy/pansi/skill/zixia-force.lpc`：`inherit FORCE;`；`/u/sadboy/pansi/skill/zixia-force.lpc`：`inherit FORCE;`；`/u/test/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 4 个文件，2 个原来编译不过、现在载入，没有退步。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←xyj451：5/6 个继承它的对象载入
- 玩家打造兵器的模板（5 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `wizu/link/obj/roommaker.lpc`：`special_props` 声明了两遍，删掉前一个（同 sjshv150）。这个物件还有别的错误，修前修后都载入不了。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 23 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/cmds/adm/adcp.lpc`（mohuanshiji）、`/daemon/skill/beiming-shengong.lpc`（fy2mg）、`/daemon/skill/fanliangyi-dao.lpc`（fy2mg）、`/daemon/skill/hanbing-mianzhang.lpc`（fy2mg）、`/daemon/skill/huashan-shenfa.lpc`（fy2mg）、`/daemon/skill/huashan-zhangfa.lpc`（fy2mg）、`/daemon/skill/hunyuan-zhang.lpc`（fy2mg）、`/daemon/skill/lingboweibu.lpc`（fy2mg）、`/daemon/skill/liumai-shenjian.lpc`（fy2mg）、`/daemon/skill/longxiang.lpc`（fy2mg）、`/daemon/skill/poyu-quan.lpc`（fy2mg）、`/daemon/skill/qiankundanuoyi.lpc`（fy2mg）、`/daemon/skill/taizuchangquan.lpc`（fy2mg）、`/daemon/skill/xiaowuxiang.lpc`（fy2mg）、`/daemon/skill/yunlong-shenfa.lpc`（fy2mg）、`/daemon/skill/yunlong-zhua.lpc`（fy2mg）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/daemon/class/dragon/pangu-hammer/feijian.lpc`、`/daemon/skill/dalibang.lpc`、`/daemon/skill/unused/snowshade-force.lpc`、`/u/bqt/game/mj.lpc`（2 个）、`/u/ken/obj/mark2.lpc`、`/u/kvv/work.lpc`、`/u/skyhawk/cmds/adcp.lpc`。修后与 HEAD 逐个对比载入：这 23 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 补回标点后新载入的物件里的未使用局部变量（2026-10-19，KB 04 §6.10）

之前载入失败、补回丢失的标点后才载入的物件里还有未使用的局部变量警告，共 1 个文件：`/u/bqt/game/mj.lpc`。删掉没有用到的声明；用 `scripts/lpc_listcheck.sh` 对比 HEAD 和改后，物件仍然载入，没有警告。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/wizu/link/obj/citymaker.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。另有 `/d/city/new-mj.lpc`（2 处）、`/wizu/litchi/mj/1mj.lpc`（3 处）、`/wizu/litchi/mj/new-mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/bin/v22pre11.orphaned-driver-src/src/compat/simuls/process_string.lpc`（2 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 10 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/city/puke-room.lpc`（4 处）、`/d/obj/baoshi/baoshi_blue.lpc`（1 处）、`/d/obj/baoshi/bsbl.lpc`（1 处）、`/wizu/litchi/mj/mj.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/wiz/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/obj/inherit/char/npc.lpc`、`/std/char/np.lpc`、`/std/char/npc.lpc`（共 3 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/arch/coordinate.lpc`（`sscanf`）、`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/adm/blockade.lpc`。

## 新手保护块 `added by vikee`：目标还没找到就 `userp(target)`（2026-10-21，KB 06 §7.348）

施法、祭法宝、偷窃指令在查找目标之前就判断 `userp(target)` / `userp(victim)`，参数是 0 时抛错；改成 `objectp(..) && userp(..)`（和 sjsh、mohuanshiji 的同一批文件一致，这一块在目标找到之前永远不会触发）。改动：`/wizu/focus/cmd/cast.lpc`、`/wizu/focus/cmd/steal.lpc`。

## 兵器架 `create()`：断剑那一句赋给 `d`、移动的却是 `b`，路径写成 `/b/obj`（2026-10-21，KB 06 §7.348）

`if (d = new("/b/obj/weapon/sword/duanjian")) b->move(this_object());`：路径是 `/d/obj/...`，赋值和移动用的是同一个变量 `b`（`d` 是后面铁剑的）。兵器架缺一把断剑。改动：`/d/lingjian/obj/rack.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 14 条注册（9 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/lingtai/npc/kancai.lpc`（`do_vendor_list`）、`/d/obj/inherit/misc/fboard.lpc`（`do_list`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/qujing/wuzhuang/renshenguo-yuan.lpc`（`do_none`）、`/wizu/link/obj/donkey.lpc`（`do_unride`）。最多的函数名：`do_vendor_list` 2 处、`do_list` 2 处、`do_push` 2 处、`do_pass` 1 处、`do_resign` 1 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（4 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（inquiry 1, chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/huanggong/npc/xrg.lpc`:`ask_bad`、`/d/qujing/pansi/npc/bao.lpc`:`do_drink`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 4 行只含这个指针的行（`(: do_drink :),` `"剃度": (: ask_for_join :),` `"出家": (: ask_for_join :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 7 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 7 处（5 个文件）：拼名字的赋值 7 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:105`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：4 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 4 处（2 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons1/logind.lpc:743`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 11 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 6 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## vikee 新手门在 present 之前（2026-10-27，KB 06 §7.348 Also）

`ssteal` / `pperform` / `jji` / `ccast`（及同族 `steal`/`cast`）里 vikee 加的年龄 / 经验 / 道行门用 `objectp(victim|target)`，却写在 `present()` 赋值之前：局部仍是 0，门永远不进。挪到 `present` 与空指针检查之后，并去掉多余的 `objectp`。证明：HEAD `ssteal` 仍在 `present` 前有 `objectp(victim)`；改后在其后且对象加载成功。


## 洗衣盆 is_container 映射缺值编不过（2026-10-27，KB 04 §6.28 Also）

`d/gao/obj/pen.lpc`（或 `d/qujing/gao/obj/pen`）的 `is_container()` 写成 `set("objects", ([ "/u/bula/gao/obj/kaoji" ]));`：映射只有键没有值（`unexpected ']'`），对象无程序。同族 hy5 / xyj2000 已把该函数注释掉。改成标准的 `return 1;`。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## toy 旁缺 message.h（2026-10-27，KB 04 §6.23 Also）

`obj/toy/*.lpc`（及少数 `obj/obj/toy`、嵌套副本）写 `#include "message.h"`，引号 include 只解析同目录；本 lib 的 `d/obj/misc/message.h` 有同内容副本，toy 目录没有。玩具对象无法编译（`Cannot #include message.h`）。从本 lib 的 `d/obj/misc/message.h` 复制到缺失的 toy 目录旁。证明：HEAD `buwawa` 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## fabao EXAMPLE 缺 ) 与 !（2026-10-27，KB 04 §6.25 Also）

`d/obj/fabao/EXAMPLE.lpc` 写 `if (objectp(victim = present(target, environment()))`，丢了 `!` 和右括号，驱动报 `unexpected L_RETURN`。按手足 `kunxian-suo` 改为 `if (!objectp(victim = present(target, environment(me))))`。证明：HEAD 加载失败；改后加载成功。

## d/wiz/officer 粘连 inherit（2026-10-27，KB 04 §6.25 Also）

`d/wiz/officer/officer.lpc` 写成 `inherit ROOM void create()`，语句间分号全丢，驱动无法编译。按原文重写为带 `setup()` / `replace_program(ROOM)` 的房间（出口仍指向档案里的 `/d/xyj/kezhan` 与 `/u/power/doorroom`）。同目录 `kenofficer.lpc` 更残，未动。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（guest.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。

## 深度功能测试（2026-10-27，§6.25 cakepiece 截断）

`u/bqt/obj/cakepiece` 丢了文件头，只剩 `do_eat` 数组残片（`Illegal character`）。用 xlqy_new2007 `d/obj/food/cakepiece` 覆盖。证明：HEAD 失败；改后加载。
