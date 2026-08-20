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
