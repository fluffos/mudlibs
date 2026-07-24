# huoying — 火影 / "Naruto" (ES2 mudlib, Annihilator lineage)

Archive: `火影.rar` (archive #65; byte-identical duplicate `火影 (1).rar`
already flagged in AGENTS.md's Duplicate archives table and NOT
re-processed). Port: **40059**. Status: **done** (boots clean, full
registration flow verified end-to-end with a real Chinese name including
reconnect + quit, lpcc sweep 98.1% pass).

## What this is

`config.cfg`'s own `name` field says **火影** (matches the archive title),
and the header comment identifies the underlying engine: `Neolith 0.0.2`
by `Annihilator (09/07/2000)` — this is the **ES2 mudlib** lineage
(Annihilator, `muds.net`), the same family as `wuhanzhan`/`xinkuangxiangkongjian2`/
`yueyingqiyuan` (archives #53/#54/#58) — confirmed via `master.lpc`'s own
copyright header ("This program is a part of ES2 mudlib... Annihilator
<annihilator@muds.net>") repeated verbatim across `master.lpc`,
`simul_efun.lpc`, `chinese.lpc`, `logind.lpc`, `securityd.lpc`,
`virtuald.lpc`, etc.

`include/globals.h` has `#define MUD_NAME_INTERMUD "Naruto"`,
`#define MUD_NAME_ABBR "Naruto"`, and a commented-out
`#define MUD_NAME "火影忍者"` ("Naruto" literally, "Fire Shadow Ninja") —
confirms the lib is genuinely Naruto-themed, not just coincidentally named.
The archive's own included `火影说明.txt` (author's readme, by "AKAI",
2006.09) says it was found on a Taiwan site and redistributed because it
looks especially good over ZMUD's ANSI-art client — this checks out at
connect time: the MOTD includes real, quite elaborate ANSI-art banner
graphics (a large multi-color logo) that render correctly once terminal
codes pass through untouched.

Root: `raw/火影/` (one level, not nested further). `config.cfg`:
`master file : /adm/obj/master`, `simulated efun file : /adm/obj/simul_efun`,
`mudlib directory : .`. Modest-sized archive: 572 raw files, 466 real LPC
(`.c`→`.lpc`) source files — no bundled driver source, no mega-lib
concerns.

## Conversion (`convert_lib.sh`)

Clean pass, no manual stragglers found afterward (verified with the
standard `file -b` re-scan for `.lpc`/`.h` files, and grep for `.c"`
leftovers/directories literally named `*.c` — zero hits on both). Numbers:
572 files total, 471 converted GB18030→UTF-8, 70 already-UTF-8, 0 lossy,
31 skipped-binary (real binaries: `mudos.exe`, `.b` binary dumps, a few
`.o` genuinely-binary saves). 466 `.lpc` files after rename, 168 literal
`.c"` refs fixed automatically, 42 files touched by `static`→`nosave`.

### New encoding gotcha found here: a config file can be genuinely
### MIXED GBK+BIG5, and GB18030 decode does NOT error on the BIG5 bytes

`config.cfg`'s `name : 火影` line is correctly GBK (`bb f0 d3 b0` decodes
to 火影 under GBK/GB18030) — but the file's own header comment block
(`# Neolith 0.0.2 ...`, `# Annihilator (09/07/2000)`) and its
`default fail message`/`default error message` values are genuinely
**BIG5**-encoded (Traditional Chinese), left over from the original
Taiwan author and apparently never touched by whoever re-encoded the rest
of the lib's `.lpc` source to Simplified/GBK for redistribution. Confirmed
byte-for-byte with Python (`b'\xab\xfc\xa5O...'.decode('big5')` →
"指令錯誤，請輸入 help cmds 了解各項指令用法..." — coherent Traditional
Chinese; the same bytes under GBK decode to visible mojibake:
"���O岿粇�A叫块�J help cmds..."). **The dangerous part**: `iconv -f
GB18030` does NOT throw an error on these BIG5 byte sequences — GBK/BIG5
byte-ranges overlap enough that the bytes decode to *some* valid-looking
(but wrong) codepoints, so `convert_lib.sh`'s lossy-conversion detection
(which only catches genuine decode *failures*) can't catch this at all.
Manually identified the 4 affected lines (`grep -na '[^\x00-\x7F]'
config.cfg` to enumerate every non-ASCII line, then spot-decoded each
candidate both ways and compared for coherent output) and rebuilt
`config.fluffos` decoding those specific lines with BIG5 and everything
else with GB18030. Low real-world impact here (only affects 2 cosmetic
player-facing messages plus code comments, not gameplay), but this is a
new variant worth watching for on any other Taiwan-origin ES2/Neolith-family
lib: **a per-line mixed-encoding file where the wrong codec still "succeeds"
silently** is a strictly harder case than the previously-documented
whole-file BIG5-fallback scenario, since there's no error to trigger a
retry — only a manual read-through catches it. Did NOT find this issue
anywhere in the actual `.lpc` source tree (spot-checked several files,
including long room/item descriptions — all read as coherent Simplified
Chinese, i.e. genuinely GBK throughout).

## Fixes applied (mudlib-side, before/during first boot)

### 1. AGENTS.md §4 — `master.lpc`'s `valid_read`/`valid_write` lazy
`load_object(SECURITY_D)` recursion, confirmed via `lpcc` before ever
attempting a full driver boot

The original code already wrapped the lazy load in `catch()`:
```lpc
nosave int valid_read( string file, mixed user, string func ) {
    object ob;
    if( !catch(ob = load_object(SECURITY_D)) && objectp(ob) )
        return (int)SECURITY_D->valid_read(file, user, func);
    return 1;
}
```
This looked like it should already be safe (§4's catalog entry describes
the UNGUARDED variant as the bug) — but running `lpcc` on `logind.lpc`
(which pulls in the full chain including `securityd.lpc`) produced exactly
§4's signature symptom anyway: a flood of `Too deep recursion.` /
`Error in error handler: *Too deep recursion.` rooted at
`master.lpc:292` (the `valid_read` line). Root cause is exactly as §4
describes: `catch()` only protects the control flow of *that specific
call* — it does nothing to prevent the driver's own error-reporting path
from calling back into `valid_read`/`valid_write` (to check permission to
write the error/log) as a **brand-new** outer call, which retries the same
disallowed `load_object()` again, ad infinitum, overflowing the C++ call
stack regardless of the inner `catch()`. **Lesson for future libs**: don't
assume a `catch()`-wrapped `load_object(SECURITY_D)` is automatically safe
just because it superficially matches the "fixed" shape — always verify
with a real `lpcc` compile of a file that pulls in the daemon chain (not
just eyeballing the source) before concluding §4 doesn't apply.

Fix: added the standard re-entrancy-flag guard (`loading_security_d`) to
both `valid_write` and `valid_read` in `master.lpc`, matching the shape
already in the catalog. Re-ran `lpcc` on `logind.lpc` afterward: zero
recursion, zero errors, full compile chain succeeds (confirmed by reading
the complete `lpcc` output, not just grepping for "error").

### 2. AGENTS.md §15h — `is_chinese()` GBK-byte-range check and
`check_legal_name()`'s byte-count bounds/loop, in `adm/simul_efun/chinese.lpc`
and `adm/daemons/logind.lpc`

- `is_chinese(str)`: was `strlen(str)>=2 && str[0] > 160` (GBK lead-byte
  range check, requiring 2+ bytes = 1+ full GBK char). Fixed to
  `strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff` (CJK Unified
  Ideographs codepoint range, requiring 1+ character).
- `check_legal_name()`'s bound: was `strlen(name) < 2 || strlen(name) > 12`
  (2..12 bytes = 1..6 GBK chars) — halved to `< 1 || > 6` to match what the
  message text already said ("必须是 1 到 6 个中文字" — "must be 1 to 6
  Chinese characters").
- The per-character validity loop: was `if( i%2==0 && !is_chinese(name[i..<0]) )`
  — the `i%2==0` landed on alternating BYTE offsets to catch each GBK
  character's lead byte; dropped it entirely since every index is already
  one full character under UTF-8, so now every position is checked.
- **A third, previously-uncatalogued §15h-family variant found in this
  same function**: `if( name[i..i+1]=="　" )` (rejecting a literal
  fullwidth-space character in the name) — `name[i..i+1]` was a
  2-BYTE-wide GBK slice (matching the 2-byte encoding of "　" itself) but
  is now a 2-CHARACTER slice being compared against a 1-character literal,
  so the comparison can never be true again — the check silently stopped
  firing entirely (not "checking the wrong range" like the other §15h
  cases, but "never triggers at all"). Fixed by narrowing to `name[i..i]`
  (single character), restoring the intended behavior. Worth adding to the
  general §15h checklist: **any fixed-width substring compared against a
  literal for equality** (not just sliding-window "is this Chinese"
  checks) needs the same byte-width→char-width correction.

Verified via the interactive registration test below (a real 2-character
name "秦风" and a 3-character name "王小虎" both accepted correctly and
advanced past `check_legal_name` to world entry) — not just a standalone
`lpcc`-dumped function check.

### 3. Port-hardcoded `master.lpc connect()` dispatch via `MUD_PORT` —
new gotcha, not previously in the catalog

`master.lpc`'s `connect(int port)` switches on the literal incoming port
number (`case MUD_PORT: ... case HTTP_PORT: ...`), where `MUD_PORT`/
`HTTP_PORT` are `#define`d in `include/globals.h` to the archive's
*original* hardcoded ports (`8000`/`8015`). Since every lib in this batch
gets assigned a different sequential port (here, 40059) that has no
relationship to the archive's original port numbers, the `switch` fell
through with no matching case and no `default`, so `connect()` implicitly
returned nothing — every single connection attempt was rejected outright
at the TCP layer with `Can not accept connection from ... due to error in
connect().`, before `logon()` or any LPC login code ever ran at all (no
compile error, no debug.log error beyond that one line — this is a classic
"boots clean, but every real connection instantly fails" trap, easy to
miss if you only check for compile errors and the "Accepting telnet
connections" banner). Fixed by updating `MUD_PORT` in `globals.h` from
`8000` to `40059` to match `config.fluffos`'s actual `port number`. **Check
for this on any other lib in this ES2/Neolith lineage** (or any lib whose
`master.lpc connect()` dispatches on a literal port number) — grep
`master.lpc` for `connect(int port)` and a `switch`/`if` on the parameter,
and cross-check every compared constant against the lib's actual assigned
port before the first real client-connect test (a bare `lpcc` sweep or a
telnet-less driver boot will NOT catch this, since `connect()` is only
exercised by a real incoming socket).

### 4. AGENTS.md §15w — `log_error()` broadcasting compile *warnings* to
players as scary "compile-time error" messages

`master.lpc`'s `log_error(file, message)` (bound to `APPLY_LOG_ERROR`)
unconditionally did `if(this_player(1)) efun::write("编译时段错误﹕" +
message)` for every message reaching it — and this driver funnels every
soft compile *warning* (`Illegal to declare nosave function`, `Unused
local variable`, `Unknown #pragma, ignored`, etc. — all harmless,
expected noise from this batch's `static`→`nosave` conversion and old
`#pragma`s) through that same apply, not just genuine fatal errors like
the original author assumed. Reproduced directly: the very first
registration test (character "秦风") spammed dozens of `编译时段错误：...
warning: ...` lines to the connecting player as soon as gender selection
triggered the lazy compile of `/std/char.lpc` and its ~30-file inherit
chain (`/feature/char/*.lpc`, `/std/room.lpc`, `/std/bboard.lpc`, etc.).
Fixed by gating the player-facing `efun::write` on the message NOT
containing the substring `"warning:"` (kept the unconditional file-log
write for every message, warnings included). Re-ran the identical
registration test afterward (fresh id "qiufeng") — zero spam, `debug.log`
still cleanly split into a normal boot-time trace, not evidence the
warnings simply stopped occurring.

### 5. A pre-existing single-file typo, `world/eq/leg/gai.lpc` (§10-family:
missing/misplaced string-literal quote)

`set_name(HIG"阿盖\"NOR, ({ "gai" }) );` has a stray backslash directly
before the closing quote of the "阿盖" name literal — confirmed present
byte-for-byte in the RAW pre-conversion archive too (`5c 22` right after
the GBK bytes for "盖"), so this is a genuine original-author typo, not
conversion fallout. The escaped quote makes the string literal swallow
everything up to the next real unescaped quote, producing a cascade of
confusing "Illegal character 0xNN" errors on later, perfectly-valid UTF-8
Chinese text further down the same file (once the parser is desynced from
being "inside a string" when it shouldn't be, subsequent real string
literals get read as raw source tokens instead). Fixed by removing the
stray backslash: `set_name(HIG"阿盖"NOR, ({ "gai" }) );`. Low-impact (a
single leg-armor item, "阿盖" — an obvious Naruto/Rock Lee/"Gai-sensei"
reference given the theme), but a one-line fix worth taking since it was
trivial and matches a cataloged pattern.

## Checked and confirmed NOT applicable (verified by reading the actual
source, not assumed)

- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`/`MASTER_OB`
  as an old bootstrap trick): `master.lpc create()` here is just
  `write(...)` — no `destruct`/`efun::destruct()` call anywhere in it.
  Confirmed by reading the full file.
- **§15n** (custom `securityd.lpc`'s `valid_read` ACL blocking the
  driver's own compile-time `load_object`/`include` access): `securityd.lpc`
  here HAS a genuinely custom ACL (`trusted_read`/`exclude_read` mappings
  keyed by directory+status), the exact shape §15n warns about — but the
  full registration-through-world-entry test (which lazily touches dozens
  of never-preloaded files: `/std/char.lpc` and its ~30-file inherit
  chain, `/adm/daemons/questd.lpc`, `/world/area/wizard/*`, etc.) completed
  with ZERO "Read access denied" errors anywhere in `debug.log`. Read
  through `valid_read`'s logic to understand why it didn't bite here: the
  very first check is `if( !(euid = geteuid(user)) ) return 0` — but by
  the time any of these lazy compiles are triggered (mid-registration,
  well after `get_id`/`seteuid(arg)` has already run), the connection
  object already has a real euid set, and none of `exclude_read`'s
  directories (`/arch`, `/adm`, `/data`, `/u`, `/log`) matched anything
  actually touched during registration+first-room-entry (`/std`,
  `/feature`, `/world`, `/obj`, `/daemon` are NOT in `exclude_read` at
  all). Confirmed empirically, not just by inspection — worth re-checking
  per-lib since a different exclude-read table shape (e.g. one that also
  excludes `/std`/`/feature`) could still hit this.
- **§15o** (`master.lpc` missing `get_include_path()` breaking mid-connection
  `#include`s): `master.lpc` has no `get_include_path()` defined at all —
  the exact gap §15o describes. But the full registration+world-entry test
  never hit a `Cannot #include <file>` error (checked `debug.log`
  specifically for this string — zero hits), and the `lpcc` sweep (which
  exercises the entire `.lpc` tree, including many files never touched by
  registration) shows only 2 genuinely-missing-header failures
  (`ansi2.h`, `path.h` — see below), neither of which is an include-path
  resolution issue (both files are simply absent from the archive, quoted
  or not). Concluded this lib doesn't need the `get_include_path()`
  insurance patch — its `#include`s are already quote-form/local enough
  not to need it. Not adding the patch preemptively per the task's
  "verify per-lib" instruction, since it wasn't needed here.
- **§8e** (`tail` not a real efun): present (`cmds/wiz/tail.lpc`,
  `tail(file)`), fails in the `lpcc` sweep exactly as expected — an unused
  admin command, not reachable from simul_efun or preload context. Left
  as a known/documented failure per precedent (lib #1's identical case),
  not fixed.
- **§8f** (`TYPE * a, b;` comma-list array-modifier bug): one superficial
  match (`cmds/wiz/mudlist.lpc:43: string* args, mud_name;`) but `mud_name`
  is never used as an array anywhere in the file (grepped all uses) — a
  false positive, not the real bug; left alone.
- **§15b** (more "called everywhere, never defined" simul_efun globals):
  none of the previously-catalogued names (`remove_ansi`, `noansi_strlen`,
  `B2G`, `db_affected`, `clr_ansi`, `chinese_number` [this lib defines its
  own, delegating to `CHINESE_D`], `changed_match_path`, `query_bandwide`,
  `query_shadowed`) appear anywhere in this lib's source at all (grepped
  each name individually) — none of that family applies here.
- **§15t** (absolute-path angle-bracket includes / `..`-relative includes /
  inherit-after-globals ordering): grepped for `#include <[^>]*/` (a slash
  inside angle brackets, indicating an absolute-looking path) and
  `#include ".*\.\./"` — zero hits of either shape anywhere in the tree.
  Not applicable.
- **§15v** (`LONELY_IMPROVED`-style always-on flag gating dead `efun::X()`
  calls): grepped for `LONELY_IMPROVED` and the whole `count_add`/
  `count_mul`/... bignum-wrapper family — zero hits. This is a
  Neolith/ES2-lineage lib, not the NT/nitan/Lonely lineage §15v documents;
  not applicable.
- **§15u** (dormant phone-home/self-destruct license check): grepped
  `securityd.lpc`/`master.lpc` for `rm`/`shutdown`/mass-deletion patterns
  gated on an opaque check — found nothing beyond ordinary, legitimate
  admin commands (`cmds/adm/shutdown.lpc` is a normal wizard command,
  requires explicit invocation). Not applicable.
- **§8g** (N identical lpcc failures sharing one root cause): the 9
  remaining `lpcc` failures (after the `gai.lpc` fix) are all
  INDEPENDENT single-file issues (each a different root cause — see
  below), not one shared dependency producing a cascade. Confirmed by
  reading every failure's actual error text individually (only 149 lines
  total in `lpcc_fail.log`, small enough to read in full rather than
  pattern-match).

## `adm/etc/preload` — DNS/intermud daemon (§15p)

Already had `/adm/daemons/network/dns_master` commented out in the
ORIGINAL archive (`#/adm/daemons/network/dns_master` — the `#` was already
there pre-conversion, not something this pass added). Preload list left
as-is (11 active entries: securityd, virtuald, logind, cmd_d, chinesed,
emoted, aliasd, fingerd, channeld, natured, enterd) — boots in a few
seconds, no hang observed.

## Boot + registration-flow verification

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/huoying/` (per AGENTS.md §6 — `log directory` is CWD-relative;
created `libs/huoying/log/` as a sibling of `config.fluffos`, separate
from `libs/huoying/work/log/`). Clean boot: all 11 preload daemons load
with only cosmetic warnings (`Unknown #pragma, ignored`, `Unused local
variable`, `Illegal to declare nosave function` — all expected/harmless
per §3/§15w), `Accepting telnet connections on 0.0.0.0:40059.` /
`Initializations complete.`, zero fatal errors in `debug.log`.

**Full registration-flow transcript** (via `scripts/mudclient.py`, one
continuous connection), reading `adm/daemons/logind.lpc`'s actual
`input_to` callback chain first (`logon`→`get_id`→`confirm_id`→
`new_password`→`confirm_password`→`get_email`→`get_gender`→`get_name`→
`enter_world`) rather than inferring it from prompt text — no hidden
pre-id gate found in this lib (unlike §15q/precedent libs):

```
--send "qiufeng"        # English id (get_id, 3-10 lowercase letters)
--send "y"               # confirm new-character creation (confirm_id)
--send "test12345"       # password (new_password, >=5 chars)
--send "test12345"       # password confirmation (confirm_password)
--send "test2@test.com"  # email (get_email, format-checked)
--send "f"                # gender (get_gender)
--send "秦风"            # REAL Chinese name (get_name -> check_legal_name)
--send "look"
--send "quit"
```
Result: prompts advanced correctly at every step; "秦风" (2 real Chinese
characters) was accepted by `check_legal_name` (no rejection message),
immediately followed by `目前权限：(player)` (confirms `make_body`/`enter_world`
executed, not a silent stall) and then the full MOTD banner, the game's
opening-room description ("巫师神殿" — Wizard's Temple), and
`你连线进入这个世界。` ("You have connected into this world.") — full
success into actual gameplay, not just past the name prompt. Zero
"编译时段错误"/error text of any kind reached the player after the
§15w fix (compare against the FIRST test run, before that fix, which did
show ~40 lines of warning-spam during this exact same step).

**Second pass, reconnect + quit** (separate connection, same character):
```
--send "qiufeng"
--send "test12345"      # get_passwd (existing save found)
--send "look"
--send "quit"
```
Result: `重新连线完毕。` ("Reconnect complete") → room re-displayed
correctly (with a wandering NPC, "龙虾", visibly present) →
`你重新连线回到这个世界。` → `look` re-displayed the room → `quit` →
`欢迎下次再来！你(qiufeng) 离开游戏。` (clean disconnect message). Confirms
save/restore and the full session lifecycle work, not just first-time
character creation.

**Third pass** with a fresh id and a 3-character Chinese name ("王小虎")
also succeeded identically, confirming the fix isn't a fluke tied to one
specific name length.

## lpcc sweep

`scripts/lpcc_check.sh libs/huoying/config.fluffos libs/huoying/work`:
**457/466 pass (98.1%)**. Remaining 9 failures, all read individually
(not just pattern-matched) and confirmed independent, pre-existing archive
gaps/incompatibilities rather than conversion bugs — left unfixed per the
"breadth over depth" policy, documented here as known issues:

- `/world/area/wizard/hockshop` and `/adm/daemons/questd` (+
  `/cmds/usr/quest`, which shares `questd`'s `create()`/save file) — both
  fail with `restore_object(): Illegal file format`/`Illegal mapping
  format` while restoring pre-existing seed save data
  (`world/area/wizard/hockshop.o`, `data/questd.o`). Confirmed the save
  files are NOT corrupted by our conversion (byte-identical Chinese text
  either way; the raw archive's own `.o` files already contain literal
  embedded raw newline bytes inside quoted string values — e.g. a "long"
  room description ending mid-value with a real `\r\n` before its closing
  quote — which appears to be a legitimate but unusual old-MudOS
  save_object() quirk that this FluffOS build's `restore_object()` parser
  doesn't tolerate the same way). Tried stripping `\r` from the affected
  file as a quick experiment; did not fix it, so left as-is rather than
  chase further — neither file is on the registration/first-room path
  (confirmed by the successful interactive test above, which never
  touches the hockshop room or the quest system), so this doesn't block
  the "done" bar. Worth a deeper look if anyone picks up quest-system
  work on this lib specifically.
- `/world/item/mj.lpc` (`Cannot #include ansi2.h`), `/world/item/gobang.lpc`
  (`Cannot #include path.h`), `/obj/water.lpc` (`inherit F_DRINK;` where
  `F_DRINK` is never `#define`d anywhere) — all three genuinely missing
  dependencies in the ORIGINAL raw archive (confirmed: `ansi2.h`, `path.h`,
  and any `F_DRINK` definition are all absent from `raw/火影/` too, not a
  conversion artifact) — a mahjong item, a Go/gobang board item, and a
  water-drink object the original author apparently never finished wiring
  up. Per AGENTS.md §13, a real archive gap, not a bug to fix.
- `/cmds/usr/version.lpc` (`Undefined variable '__DRIVER__'`) and
  `/cmds/adm/socket.lpc` (`Undefined function dump_socket_status`) — both
  reference MudOS-only driver introspection primitives with no FluffOS
  equivalent; both are non-critical, non-preloaded utility/admin commands
  (a "show server version" command and a raw-socket-debug admin command).
  Left unfixed — low value, no gameplay impact.
- `/cmds/wiz/tail.lpc` — the well-known §8e `tail()` efun gap, an unused
  wiz command, same as lib #1's precedent. Left unfixed per that
  precedent.

## Process notes

- Confirmed via `/proc/<pid>/cwd` before killing anything that a second
  `build-debug/src/driver config.fluffos` process (pid varies by run) seen
  in a broad `pgrep`/`ps` during this session belonged to a DIFFERENT
  concurrently-running agent's lib (`libs/yuxuechongsheng/work`) — never
  touched it, only ever killed this lib's own driver by its exact,
  recorded PID. No lingering driver process for this lib at the end of
  this session.

## 2026-07-23 re-verification pass (driver rebuild + formatter + WASM)

- **LPC reformat**: ran `format-corpus.mjs` over all of `work/` (466
  `.lpc` files) — 465 written, 1 already-idempotent, 0 refused. Spot-
  checked the §15s `tell_room()`/`message()` fix in `adm/simul_efun/
  message.lpc` (`message("tell_room", str, ob, exclude || ({}));`) —
  reformatted but semantically untouched, confirmed by reading the
  formatted output directly.
- **Native retest against the freshly-rebuilt driver**: booted clean on
  port 40059, zero fatal preload errors. Full registration flow with a
  fresh real Chinese name ("秦风八"/`qinfengba`) through the complete
  wizard (id → confirm → password → confirm → email → gender → Chinese
  name) into the actual game world (巫师神殿); reconnected with the same
  id/password and ran explicit `look` (room description correct),
  `score` (full character sheet correct: stats, HP/查克拉 bars, equipment
  slots), and `quit` (clean save + disconnect) — all correct, zero
  runtime/compile errors logged during the whole session. No regressions
  from the reformat or the new driver binary. (Note for future
  testers: the login wizard's English id must be pure letters, 3-10
  chars — digits or >10 chars are silently re-prompted, easy to burn
  several `--send` lines on by accident.)
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly (same preload warnings as native). Registration
  proceeds all the way through the wizard — id, password, email,
  gender, Chinese name are all accepted — but the character never
  actually lands in the game world. Root cause is a genuine WASM
  limitation, **distinct from the documented `query_ip_number()` issue**:
  `adm/daemons/userid.lpc` (an ident/`auth` protocol lookup against the
  connecting client's port 113) is lazily compiled from `logind.lpc`'s
  `enter_world()` and uses `socket_address()`/`socket_create()`/
  `socket_connect()` — none of which exist under this WASM build (no
  `sockets` package, per AGENTS.md's documented WASM restriction list).
  The file fails to compile, and because this call site is a lazy
  runtime load at the tail end of login rather than a preloaded daemon
  wrapped by the mudlib's own error handler, `enter_world()` throws
  `*No program in object '/adm/daemons/userid'!` and aborts outright —
  confirmed the character was left outside any room (a same-session
  `look` immediately after returned "你现在什么也看不到" — not "in a
  room" at all) rather than merely a cosmetic feature gap. Confirmed via
  direct source read and by contrast with the fully-clean native login
  above (reaches 巫师神殿 every time) that this is WASM-build-specific,
  not a mudlib bug — not patched, since "fixing" it would mean removing
  a real feature (the ident lookup) to work around a driver-build
  limitation rather than fixing an actual bug.

## WASM-enablement pass (2026-07: loopback-allow + throttle exemptions + admin seeding)

Standard pass per AGENTS.md §1.3b/e + §1.5. Gates found and patched
(loopback = `127.0.0.1`/`127.*`/empty/non-string/malformed IP, defending
against the WASM `query_ip_number()` garbage-return bug):

- `adm/daemons/logind.lpc:80` new helper `is_loopback_conn()` (declared
  :73); used to exempt loopback from:
  - `:120` — `ENABLE_ANTISPAM` per-IP registration throttle in `logon()`
    ("创造的人物太多" ≥10 registrations per IP per reset → reject);
  - `:180` — `ENABLE_BAN_SITE` banned_ip/banned_hostname pattern gate in
    `get_id()` (both lists ship empty, but the gate is live);
  - `:589` — `check_ip()` per-account IP whitelist (`okip` property):
    loopback always passes.
- No `uptime()` startup-grace gate exists in this lib (zero non-cosmetic
  `uptime()` call sites).
- Incidental fix while verifying the admin account: created
  `work/log/nosave/` — the wizard `update` command's audit
  `log_file("nosave/UPDATE", ...)` threw "Wrong permissions/No such file
  or directory" on every use because the archive never shipped that
  subdirectory (AGENTS.md §7.11 class; never seen before because no
  admin account existed to run `update`). Clean after mkdir.

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real native flow (id → y → password ×2 → email → gender m → Chinese
name). Granted `(admin)` via `adm/etc/wizlist` (added `fluffos (admin)`
alongside the original `acme (admin)`). Verified after restart: login
shows `目前权限﹕(admin)`, wizard-vision file paths visible in room
descriptions, `update /world/area/wizard/guildhall` recompiles the room.
Save files (must be committed): `work/data/user/f/fluffos.o`,
`work/data/login/f/fluffos.o`.

Retest: fresh registration (秦风/ceshizhe) end-to-end + look/score/quit
clean; fluffos login + update clean; a stray typo character (`flufos`)
created during testing was deleted; one single "Too long evaluation"
eval-cost overrun was observed once in `world/area/wizard` NPC-inventory
creation during a first-touch lazy-compile burst (content-side, did not
recur on subsequent sessions, unrelated to this pass's patches);
`data/chinese.o` runtime churn reverted.

## Dual-mode verification pass (2026-07-24)

- **Fix applied** (AGENTS.md §1.3c, in scope for this pass):
  `adm/daemons/logind.lpc:663` (enter_world) and `:713` (reconnect) —
  the two lazy `IDENT_D->query_userid(...)` calls are now wrapped in
  `catch()`. Under WASM `userid.lpc` fails to compile (socket_address/
  socket_create/socket_connect absent — no sockets package), and the
  uncaught throw aborted `enter_world()`, leaving the fresh character
  outside any room (the previously-documented WASM blocker). With the
  catch, the ident lookup silently no-ops under WASM and is unchanged
  natively. Wizards see the caught compile error echoed once at login
  ("编译时段错误..."), cosmetic and wizard-only.
- **Native** (temp port 41059 — this lib's assigned 40059 was held as a
  secondary listener by another session's xuanjianlu driver, which was
  left alone per §10.5; `include/globals.h` MUD_PORT was temporarily
  pointed at 41059 for the test and reverted, byte-identical, after):
  fresh registration `ceshier`/秦风 end-to-end into 巫师神殿; re-login
  (restore path) + look/score/quit all correct; `fluffos`/`Mud@2026`
  login shows `(admin)` and `update /world/area/wizard/guildhall`
  succeeds. debug.log: compile warnings only, zero runtime errors.
  Driver killed by exact PID.
- **WASM** (build-wasm with query_ip_number/resolve fixes): fresh
  registration `wasmceshi`/秦风 lands in 巫师神殿, look/score/quit all
  correct; second invocation: `fluffos` admin login `(admin)` + `update`
  成功. **Verdict: native OK + wasm OK.** Test character saves removed;
  runtime churn (daemon.o, fluffos.o timestamps) reverted.
