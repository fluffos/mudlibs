# chongshengdeshijie — 重生的世界 v1.0.1 (Revival World / RWlib)

Archive #89: `archives/重生的世界v1.0.1.rar`. Port **40081**. Status: **done**.

## What this lib is

A genuine LPC mudlib — confirmed via `inherit` statements, `master file`/
`simulated efun file` directives, and a `system/kernel/`, `system/daemons/`,
`std/`, `cmds/`, `obj/`, `data/` tree shaped exactly like the pipeline
expects. **Not** part of any lineage seen in this project so far (not
wuxia, not ES II, not "nitan"/Lonely, not the TMI-2/XO family): this is
"重生的世界" / "Revival World" ("RW mudlib"), a from-scratch, self-authored,
GPLv2 Taiwanese life-simulation/city-builder MUD — farming, fishing,
ranching, factories, real estate, a stock exchange, city building/city
halls, a lottery, mahjong minigames — built on **MudOS v22.2b14** plus a
handful of custom driver packages the author (`Clode@RevivalWorld`,
`Cookys@RevivalWorld`) wrote and bundled reference C source for under
`doc/driver/modify/source_files/` (ansi, chinese, database,
arith_operator, and a partial contrib package). `master.lpc`'s own header
credits "Author: Clode@RevivalWorld"; the copyright file explicitly
documents both the MudOS driver license and RW's own GPLv2 library
license. Archive title "重生的世界" IS the live banner name
(`重生的世界(Revival World) v1.0.1`), matching exactly.

The archive's own `cssj/小熊泥苑.txt` distribution note matches the
"小熊泥苑" (nd169.com) site signature seen on several prior archives in
this project (a common redistribution point), but the actual *codebase*
is unrelated to any of those — this is a wholly distinct lineage. The
extracted archive also bundled a byte-identical duplicate copy of the
whole lib (under `cssj/RWlib-1.0.1/`, confirmed via `diff -rq`, 2117/2117
files identical) plus a separate Windows prebuilt driver binary
(`cssj/MudOS-v22.2b14-RW-Build-Win32/v22.2b14-RW Build.exe`) which was left
alone (not part of the pipeline).

**Encoding: this archive is BIG5 (Traditional Chinese, specifically
CP950 — BIG5 plus box-drawing extension characters), not GBK/GB18030**
like every other archive processed in this project so far. Confirmed
definitively by decoding sample files both ways and comparing: GB18030
decodes every file "successfully" (no invalid-byte errors) but produces
valid-but-wrong mojibake (`"秖"`/`"戈癟"` instead of real words), while
CP950 produces correct, readable Traditional Chinese (`"稻秧"`,
`"敘述精靈"`, `"武者乃一綜合型之職業"`, etc.) — this matches the config
file's own `mudlib directory : C:\mud\lib` (Windows-authored) and its
credit trail ("Lima Mudlib" in the bundled MudOS doc comments, a
Taiwan-origin driver lineage). Of 2117 raw files, 1846 decoded cleanly
under strict CP950, 229 were already valid UTF-8 (mostly `www/`,
`doc/v22doc/` reference material), 40 were genuinely binary (PNGs, GIFs,
a Java applet, `Thumbs.db`, a zip) and correctly skipped, and only **3**
files needed a lossy CP950 pass (a couple of generic MudOS doc articles
with a handful of bad bytes, not lib source) — a very clean archive by
this project's standards. A custom Python conversion pass was used
instead of `convert_lib.sh`'s built-in GB18030 assumption (pre-decode
BIG5→UTF-8 into a staging copy, then run `convert_lib.sh` against that
staging copy so its own GB18030 step just detects "already UTF-8" and
passes through — the rename/`.c"`-ref-fix/`static`→`nosave` steps all ran
normally afterward).

Four filenames under `system/daemons/etc/weather_*` are garbled in a way
that predates this pipeline entirely (`weather_甃ぱ` etc. — the raw bytes
on disk are already valid UTF-8 that decodes to nonsense, i.e. the
original archive itself already had double-mis-encoded filenames, not
fixable by any single-direction re-decode). Left as-is; these are just
alternate weather-flavor-text data files, not referenced anywhere by
literal name (the daemon that uses them presumably does a directory scan).

## Fixes applied (proactive catalog checks + new findings)

### Mechanical / pipeline
- Standard `.c`→`.lpc` rename + literal `".c"` ref fixes via
  `convert_lib.sh` (see encoding note above for why it was fed a
  pre-decoded staging tree instead of raw GBK bytes).
- `static`→`nosave` blanket sed: no counterexamples found (no
  `"static/..."` path strings, no `#define nosave static` compat shim).
- No uppercase `.C` files found.
- §2 second variant (`[<N..<1]`/`[0..<N]` fixed-width slices calibrated
  for the old 2-char `.c` extension, now wrong for 4-char `.lpc`) —
  **found and fixed in 5 files**: `system/daemons/command_d.lpc` (2
  occurrences, including the live command-registration extension check —
  **this one was high-impact**, see below), `system/daemons/system_d.lpc`
  (preload-directory-expansion extension check), `system/daemons/
  building_d.lpc`, `std/inherit/feature/room/_remove_room.lpc`, and
  **`system/kernel/creator.lpc`** (4 occurrences — this one was the most
  impactful of all, see below).
- §8f-shaped bare-`array`-keyword bug (this driver rejects `array` as a
  standalone type — needs `mixed *`): **~470 occurrences across 179
  files**, fixed via a scripted whole-tree pass. Two follow-up variants
  the blanket regex initially missed, found via compile errors and fixed
  by hand: (a) `array *name` (space between the keyword and the star —
  2 files: `system/daemons/emote_d.lpc`, `cmds/std/guest/children.lpc`),
  and (b) a genuine pre-existing double-type-keyword typo,
  `private nosave string array DAYLIGHT_SAVINGS` in
  `cmds/std/ppl/localtime.lpc` (predates this pass — the blanket sed
  turned it into nonsensical `string mixed *`, caught and hand-fixed to
  `string *`).
- Orphaned non-LPC `.c` files renamed back (§12): the ENTIRE
  `doc/driver/modify/source_files/` tree (20 files) is bundled *reference
  C driver source* for the packages the author wrote (ansi, chinese,
  database, arith_operator, contrib, plus core driver files like
  `add_action.c`/`backend.c`/`efuns_main.c`/`sprintf.c`/`ed.c`/`lex.c`) —
  never meant to be compiled by the mudlib itself, incorrectly caught by
  the blanket rename since it lives under `doc/`. Also 2 plain-text
  Chinese-language articles *about* LPC (`doc/v22doc/ref/lpc.c`,
  `doc/v22doc/concepts/lpc.c`) renamed to `.txt`.
- Bare `\bstatic\b` counterexample: none found.

### `.c`-extension-width bug in `system/kernel/etc/preload` itself (§15c)
The raw preload data file listed 3 daemons with bare, unquoted `.c`
paths (`/system/daemons/city_d.c`, `/system/daemons/area_d.c`,
`/system/kernel/creator.c`) that the quote-scoped sed pass never
touches. Fixed by hand (`.c`→`.lpc`).

### `system/kernel/creator.lpc` — auto-generated header regeneration bug (critical, self-inflicted, found the hard way)
This daemon auto-generates `/include/feature.h`, `/include/inherit.h`,
`/include/daemon.h`, and `/include/condition.h` from a live directory
scan every single boot (via `create()`→`create_all_include()`, preloaded
last). Its 4 file-scanning loops all had the exact §2-second-variant bug
(`f[<2..<1] != ".lpc"` — comparing the **last 2 characters** against the
4-character string `".lpc"`, which can never match). Before this was
found and fixed, **every single boot silently wiped all 4 of these
header files down to just their comment header**, since the "no files
matched the extension check" loop body never executed and
`write_file(..., 1)` (overwrite mode) still ran unconditionally at the
end. This is *catastrophic* and cascades hard: with `daemon.h` empty,
every `#define AREA_D "..."`/`CHANNEL_D`/`SECURE_D`/etc constant used
throughout the whole daemon tree evaluates to nothing, and dozens of
daemons (`money_d`, `ppl_login_d`, `login_d`, `nature_d`, `emote_d`,
`estate_d`, `growth_d`, `html_d`, `shopping_d`, ...) failed to compile
during preload with `Undefined variable 'AREA_D'`/`'CHANNEL_D'`/etc —
**including the two daemons that actually drive registration**
(`login_d`, `ppl_login_d`). First noticed via a `*master object: No
function creator_file() defined!` unrelated error (see below) that
happened to occur before creator.lpc's own bug could even manifest on
the very first attempts; once that was fixed, the *next* boot's very
first real symptom was `master::connect()`'s own `catch()` silently
swallowing `new(LOGIN_OB)`'s failure with no diagnostic at all — required
temporarily instrumenting `master.lpc`'s `connect()` with
`efun::write_file()` to see the actual underlying error (per AGENTS.md
§8d/§15d technique), which turned out to be `emote_d`'s pre-existing
corrupted save file (see below), itself only reachable because
`daemon.h` was empty at the time. Restored the original, correct
`include/*.h` content from the raw archive (BIG5→UTF-8 decoded +
`.c`→`.lpc` ref fix by hand, same as the rest of the pipeline) as an
immediate unblock, then fixed all 4 loops in `creator.lpc` itself
(`<2..<1>`→`<4..<1>`, and the corresponding name-extraction
`[...+N..<3]`→`[...+N..<5]`, including the condition.h builder's
extension-stripping `f[0..<3]`→`f[0..<5]`) so the auto-regeneration is
correct going forward — confirmed on every subsequent boot (`feature.h`/
`inherit.h`/`daemon.h` all came back with full, correct content,
matching the raw archive's line counts almost exactly).

### §7 — missing `master::creator_file()`
This driver requires `master::creator_file()` (uid-assignment apply,
called on every `new()`) to exist when `AUTO_SETEUID`/`PACKAGE_UIDS` are
compiled in (confirmed via `~/src/fluffos/docs/apply/master/
creator_file.md`) — this lib never implemented it at all (only
`domain_file`/`author_file`/`privs_file` existed in `system/kernel/
master/file.lpc`). Every single `new()` — starting with `master::
connect()`'s own `new(LOGIN_OB)` — threw `*master object: No function
creator_file() defined!` uncaught. Same family as the already-catalogued
§7 `get_root_uid`/`get_bb_uid` gap (also missing here, added alongside);
fixed with a one-line `return "ROOT";` stub, same as those two.

### `emote_d.lpc` — pre-existing corrupted save file crashing the ENTIRE command system (new §15m variant, high impact)
`data/emotion/emotion.o` has a genuine, pre-existing corruption (243 open
parens vs 245 close parens) — confirmed byte-identical in the raw
archive before any conversion touched it, so not something this pipeline
introduced. `emote_d.lpc`'s `create()` had no `catch()` around
`restore_object(DATA)`; the malformed file makes `restore_object()`
throw `*restore_object(): Illegal mapping format while restoring
emotions.` (matching §15m's precedent exactly, just a different daemon).
The high-impact part: `system/daemons/command_d.lpc`'s
`reset_commands()` — which builds the *entire* `std_commands` table used
by **every single player/wizard/npc command in the game** — calls
`EMOTE_D->query_emotions_fpointer()` as its *first* step, with no
`catch()` either. The uncaught exception from the corrupted save file
therefore aborted `reset_commands()` immediately, before it ever reached
the loop that registers `look`/`score`/`quit`/etc — so on any boot before
this was found, **every single post-login command** (not just
emote-related ones) would have returned "沒有「X」這個指令" forever, a
much bigger blast radius than the emote subsystem alone. Fixed two ways:
(1) `emote_d.lpc`'s own `create()` now wraps `restore_object(DATA)` in
`catch()` and no longer `destruct()`s itself on any restore failure
(the original code unconditionally suicided the whole daemon even on a
merely-missing, not corrupted, save file — clearly not intended for the
common "fresh install" case either); (2) `command_d.lpc`'s
`reset_commands()` now wraps both the emote and channel fpointer-query
blocks in `catch { ... }` as defense in depth, so *no* daemon's
`query_*_fpointer()` misbehaving can ever again take down command
registration for the whole game. (`catch { statements }` — the
block-statement form — needs a **trailing semicolon**, since `catch` is
grammatically an expression here per this driver's grammar; two early
attempts at this fix hit "syntax error, unexpected L_CATCH" from omitting
it before landing on the working form.)

### `_input_usr.lpc`'s `process_input()` return-value contract (new finding, high impact on every single typed command)
This mudlib is architecturally unusual for this project: it implements
its **own, completely custom command-dispatch system** end to end
(`COMMAND_D`'s `std_commands`/`query_actions()` mapping, populated from a
live directory scan of `cmds/std/{ppl,npc,guest,wiz,adv,adm}/`), and does
**not** use the driver's real `add_action()`/`command()` mechanism at all
for ordinary player commands (it does define its own, differently-shaped
`add_action(object, mapping)` wrapper for object/room-specific
interactions, unrelated to the driver's real efun of the same name) —
so the classic §15ae "private nomask command hook silently drops
add_action dispatch" bug **does not apply here at all** (confirmed: no
`private` on anything reachable via a real add_action call). Instead, a
different, new bug hit the exact same symptom class ("every post-login
command looks broken"): `_input_usr.lpc`'s `process_input()` fully
handles each command itself via `process_command()`, but its very last
line unconditionally `return input;` (the ORIGINAL, unmodified string).
Per this driver's actual `process_input` apply contract (confirmed by
reading `~/src/fluffos/src/comm.cc`'s `process_input()`): returning a
**string** makes the driver run its own, separate `add_action`-based
parser on that string; returning `0` (or nothing) does the *same thing*
using the *original* input (0 and "nothing" behave identically here,
**not** "suppress further processing" as one might assume from a quick
skim); only returning a **non-zero integer** actually tells the driver
"already fully handled, don't parse again." Since this lib never
registers anything via the real `add_action()`, that second parse always
finds nothing and prints `config.fluffos`'s `default fail message`
("你可以打 help 求助。") — meaning **every single successfully-executed
command was followed by a confusing, unrelated-looking "no such
command"-flavored message**, easy to misread as the command itself
having silently failed. Fixed by changing the final `return input;` to
`return 1;`. (The other 3 early-return points inside `process_input()` —
empty input, the backdoor-password check, and the input-disabled gate —
were left returning `input` since none of them are proven to cause any
observable problem and they run *before* `process_command()` is ever
reached.)

### `find_command_object()` — call_other on a bare `0` errors on this driver, and unmasks a second issue once fixed (new §15e variant)
`command_d.lpc`'s `find_command_object(verb)` did
`return function_owner(std_commands[ADMIN][verb]);` with no guard —
`function_owner(0)` (correctly `0` for the many verbs never registered
as ADMIN-level commands, e.g. `"snoop"`, which this archive simply
doesn't ship as a real command file) throws `*Bad argument 1 to
function_owner() Expected: function Got: 0.` uncaught on this driver,
visibly spamming the connected player with the scary `log_error`/
`error_handler` default message on **every private message send and
every typed command** (both `_message_usr.lpc`'s `catch_tell()` and
`_input_usr.lpc`'s `process_input()` call `COMMAND_D->find_command_object
("snoop")->notify_snooper_*(...)` unconditionally, snoop-hook style).
Fixed `find_command_object()` with a `functionp()` guard (returns `0`
cleanly instead of erroring). That alone still crashes at the *next*
step though — `call_other()` on a bare `int 0` (as opposed to calling a
missing function ON a real object, which silently returns 0) is *also*
a hard type error on this driver (`Bad argument 1 to EFUN call_other()
... Got: int(0)`) — so the 3 call sites (`_message_usr.lpc`,
`_input_usr.lpc`, `std/module/room/labor.lpc`'s `score`/`skill`
lookups) also needed explicit `objectp()` guards before the `->` call,
matching §15e's general "guard every unchecked factory-call result"
principle exactly, just with the factory here being a lookup table
instead of a `new()`.

### `system/daemons/login_d.lpc`'s `is_repeat_login()` — `private` blocking legitimate `call_other` (new, minor but real)
`ppl_login_d.lpc` calls `LOGIN_D->is_repeat_login(arg)` via ordinary
`call_other`, but the function was declared `private` in `login_d.lpc` —
this driver enforces `private` strictly for `call_other` too (confirmed
via a live `apply() with insufficient permission ... needs: public, has:
private` line in `debug.log`), so the "already logged in with this ID"
duplicate-login check silently always failed/denied, i.e. never actually
worked. Dropped `private` (kept `nomask`).

### `system/kernel/simul_efun/dbase.lpc` — the big one: bare `query()`/`set()`/etc. from *sibling*-inherited fragment files don't reach the real per-object storage (systemic architecture fix, likely the single highest-value fix in this pass)
This lib's `set`/`query`/`set_temp`/`query_temp`/`addn`/`addn_temp`/
`delete`/`delete_temp` were **real driver EFUNs** on the original MudOS
target (a custom "database" package — full C reference source
preserved at `doc/driver/modify/source_files/packages/database.c`),
providing generic nested-path property storage (`"abi/stamina/max"`
etc.) keyed off any object that declares a global `mapping database`/
`temp_database` variable — resolved by the *original* driver via
low-level introspection (`find_global_variable(ob->prog, "database",
...)`), completely independent of inheritance. FluffOS has no such
package at all — restored as simul_efuns, with the real, primary
per-object implementation living in `std/inherit/feature/object/
_database.lpc` (already declares `database`/`temp_database`, inherited
everywhere via `STANDARD_OBJECT`).

**The subtle, high-impact bug found empirically** (not from reading the
code — the numbers just didn't add up): `CHAR_D->create_char()` (a
daemon, no local DATABASE inherit) sets a new character's
`"abi/stamina/max"` to `500` via the 3-arg redirect form
(`set(path, value, user_ob)`), which correctly reaches `user_ob`'s real,
local `_database.lpc`-provided `set()` via `call_other` — confirmed
correct by inspecting the saved `.o` file (`"stamina":(["max":500,
"cur":500,])`, exactly right). But `std/inherit/feature/living/
_attribution_liv.lpc`'s own `query_stamina_max()` — running as
genuinely-inherited code *on that same, already-correctly-populated*
object — calling **bare** `query("abi/stamina/max")` (no explicit
target), read back `0`. Direct instrumentation confirmed it: the SAME
object, moments after CHAR_D set 500, read back 0 via its own bare
`query()`. Root cause: `_attribution_liv.lpc` is a *sibling*-inherited
fragment (pulled in via `_living_liv.lpc`, itself inherited into
`interactive.lpc`/`standard_npc.lpc` — neither of which is
`_database.lpc` itself) — this driver's bare-call resolution for such a
file does **not** dynamically bind against the *final, fully-composed*
object's complete symbol table the way one might expect from ordinary
LPC inheritance; a bare call inside a fragment that doesn't itself
`inherit DATABASE` resolves to the simul_efun instead (confirmed
independently by the fact that a bare call to `query_database()` — a
real function in `_database.lpc`, but *not* a simul_efun — is a flat
"Undefined function" **compile** error from inside `_attribution_liv.lpc`,
proving the file's own compile unit genuinely has no visibility into
`_database.lpc`'s exports, unlike `query`/`set`, which silently fall back
to matching the simul_efun name instead of erroring). Concretely: the
original `dbase.lpc` fallback kept its **own separate storage bucket**
keyed by `previous_object()` — meaning every bare call from one of these
common sibling-inherited fragments (and there are dozens throughout
`std/inherit/feature/living/*.lpc` alone) was silently reading and
writing a completely different mapping than the object's real,
call_other-reachable `database`, with no error of any kind. Symptom in
practice: the `score` command's stamina/health/energy bars all showed
`0 / 0`, which then fed `GRAPH_D->graph()` a `max` of `0`, producing a
`*Division by 0.0` crash — and because that crash propagated all the way
up through the whole `process_input()` apply uncaught, the C++-level
`safe_apply()` call failed entirely (`ret == nullptr`), which **also
permanently disabled this player's `process_input` hook for the rest of
the session** (`ip->iflags &= ~HAS_PROCESS_INPUT`, straight from
`comm.cc`) — so after the *first* `score` crash, `quit` (and every other
subsequent command) silently fell through to the driver's own
`add_action` parser instead of this lib's real dispatcher, which never
actually executed the intended command at all. A single stat-display
bug in one command was one crash away from silently breaking a whole
session's worth of commands. **Fix**: rewrote `dbase.lpc`'s fallback to
never keep its own storage at all — for the bare-call shape, it now
simply `call_other`s back to `previous_object()` (the object whose own
code made the bare call) using the *same* function name.
`call_other()` always resolves against the target's real, complete,
final compiled program regardless of which inherited fragment the
*caller's* code happens to live in, so this correctly reaches the
object's genuine `_database.lpc`-provided storage whenever it has one
(virtually everywhere, via `STANDARD_OBJECT`), and harmlessly no-ops
(matching this driver's normal call-a-missing-function-via-`->`-returns-0
behavior) for the rare caller that has no per-object storage at all
(e.g. a bare daemon self-call). Re-verified via the same live
instrumentation: `query("abi/stamina/max")` on the same object now
correctly returns `500`; a full registration→`score` run afterward
showed the fully correct character sheet (`力量 10`/`體力 500 / 500`/
`生命 100 / 100`/`精神 100 / 100`, all matching the saved data exactly),
no crash, no session-breaking side effect. **This almost certainly fixed
many more latent bugs than just this one stat display** — any bare
`query()`/`set()`/etc. call from any of the many `std/inherit/feature/
living/*.lpc`, `std/inherit/feature/object/*.lpc`, etc. fragment files
throughout this whole mudlib would have had the identical silent-wrong-
storage problem before this fix.

### `obj/etc/lotto.lpc` — defensive `catch()` around `restore_object()` (precautionary, not confirmed to be the actual root cause of anything)
Added the same `catch(restore_object(DATA_PATH))` pattern as
`emote_d.lpc` here too, since a `data/object/lotto.o` bracket-count
check initially looked corrupted the same way — turned out to be a
**false alarm**: the "imbalance" is just from literal bare `[NNNm`
ANSI-escape-shaped text inside the saved `"long"`/`"id_name"` string
values (which legitimately contain `[` with no matching `]`, since ANSI
codes aren't bracket-delimited), not real structural corruption — a
second save file (`data/object/mj112.o`) was checked the same naive way
and showed the identical false-positive pattern for the identical
reason, which is what exposed the heuristic as unreliable. The `catch()`
was kept anyway as cheap, harmless insurance (matches this codebase's
own pattern elsewhere), but is **not** the fix for the actual issue
below.

### `std/module/object/{furniture,vehicle,tools}/*` — genuinely missing `OBJECT_ACTION_MOD` base class (content gap, reconstructed from an identical in-lib template)
6 files (`chest`/`stool`/`chair`/`car`/`rod`/`ring`) `inherit
OBJECT_ACTION_MOD;` but neither the macro nor any file it could plausibly
point to exists anywhere in this archive — while its two structural
siblings, `PRODUCT_ACTION_MOD`/`ROOM_ACTION_MOD` (identical job, "refresh
all objects using this compiled module file's actions"), both ship
completely normally. Reconstructed `std/inherit/feature/module/object/
_object_action_mod.lpc` **verbatim from the `_product_action_mod.lpc`
template** (the two existing siblings are themselves near-identical
2-function files) and added the `OBJECT_ACTION_MOD` macro — not
fabricated new game content, just restoring an evidently-omitted piece
of shared boilerplate infrastructure using a pattern the archive already
demonstrates twice. `creator.lpc`'s auto-generation picked the new file
and macro up correctly on the very next boot with no further changes
needed.

### `obj/etc/mj/mj.lpc` + both `obj/etc/oldmj/mj_broken{,2}.lpc` — missing `*` on an array variable (§8f, found via the lpcc sweep)
`string arr, tile, str="";` — `arr` is used exclusively as `arr[0] +=
"..."`/passed as `string ref *arr` to `otile_display()` (an actual array
parameter), so it needed to be `string *arr` (plain `string` makes
`arr[0]` a single character/codepoint, producing `Bad assignment (int vs
string)` the moment anything tries to append a string onto it). Same
one-line typo present identically in all 3 near-duplicate mahjong-game
files; fixed all 3.

## Confirmed NOT needed (checked proactively, found not applicable)
- **§4** (master's lazy `load_object` in `valid_read`/`valid_write`
  recursing to a stack overflow): `master/valid_readwrite.lpc` just
  delegates to `SECURE_D->valid_check(...)` with no lazy-load pattern at
  all; `secure_d.lpc`'s own `valid_check()` is permissive-by-default
  (`return 1` for any caller lacking a resolvable interactive identity)
  and has no ACL-blocking-the-driver's-own-compile issue (§15n also
  confirmed not needed for the same reason).
- **§8c** (`this_player()` override in valid_read/write wrongly denying a
  privileged system caller): not applicable, same reasoning as §4 above.
- **§8e** (`tail` efun gap): this lib already implements its own real
  `tail(fname, bytes)` function in `cmds/std/guest/tail.lpc` — not a
  call to a nonexistent efun at all.
- **§14** (`valid_override` needing the 3-arg signature for `#include`d
  simul_efuns): already correctly implemented — `file[0..24] ==
  SIMUL_EFUN_OB[0..24]` is a 25-character prefix match that already
  covers both `simul_efun.lpc` itself and every file under
  `system/kernel/simul_efun/` (the directory prefix is exactly 25 chars),
  achieving the same effect as checking `mainfile` without needing the
  3rd parameter at all.
- **§15h** (GBK byte-range `is_chinese`-family checks broken by
  UTF-8 codepoints): `is_chinese()` (in `system/kernel/simul_efun/
  string.lpc`) had the exact GBK-byte-range bug (`a < 160 || a > 255`
  gated on `--len%2`) and was fixed the standard way (CJK codepoint range
  `0x4e00..0x9fff`, check every character) — but **this did NOT gate
  registration** in this lib: the actual character-name prompt
  (`INPUT_NEW_NAME` in `ppl_login_d.lpc`) only checks length (2-12) and
  absence of control characters/spaces, no Chinese-specific validation
  at all. `is_chinese()` is only used by a handful of in-game features
  (`cityhall.lpc`, `research.lpc`, `order.lpc` command, `city_d_main.lpc`).
  Still fixed since it's clearly wrong and used elsewhere, just not the
  registration blocker it usually is in this project.
- **§15ae** (private nomask command-hook breaking add_action dispatch):
  this lib's whole command architecture is custom-built and never uses
  the driver's real `add_action()` for ordinary commands at all (see the
  `process_input()` write-up above) — the bug class doesn't apply, though
  a different bug with the identical *symptom* was found and fixed.
- **§15al** (`crypt(str, 0)` random-salt login-handshake breakage):
  password verification uses the correct `crypt(arg, stored_hash)` 2-arg
  form (stored hash reused as salt) for comparison; `crypt(arg, 0)` is
  only used once, to *create* the hash at registration time, which is
  fine regardless of per-call randomness since nothing needs to
  reproduce that exact value independently.
- **§15am** (`file_size()==-1` truthy trap): audited every bare
  `file_size(...)` conditional in the codebase — all are explicit
  `== -2`/`!= -2`/`< 1`/`<= 0` comparisons, never a bare truthy check.
  `system/kernel/simul_efun/path.lpc`'s `intact_path()` (mkdir-chain
  helper used before every `save_object()`) correctly uses
  `file_size(file) != -1`.
- **§15p** (DNS/intermud daemon hang risk): `mud_d.lpc` (hardcoded
  external IP `59.124.167.216:9994`, unconditional `socket_connect()` in
  `create()`) and `intermud2_d.lpc` (UDP `resolve()`+`socket_bind()` in
  `create()`) both matched this pattern and are both swept in
  wholesale via a bare `/system/daemons/` directory entry in the preload
  list (no per-file preload exclusion possible) — patched
  `system_d.lpc`'s directory-expansion loop with an explicit
  `PRELOAD_EXCLUDE` filename list instead. `network_d.lpc`/`socket_d.lpc`
  (empty stub files) and `ftp_d.lpc` (`#undef AUTO_DETECT_HOSTIP` already
  present, takes the static-IP branch, no resolve() call) were checked
  and confirmed to not need it. `whois_d.lpc`/`dict_d.lpc`/
  `translate_d.lpc` open outbound sockets but only from inside explicit
  player-invoked command functions, never from `create()` — confirmed
  safe to leave preloaded.
- **§15v** (`LONELY_IMPROVED`/bignum-family `efun::X()` gaps): this
  lib's own count-based bignum wrapper, `count(n1, op, n2)`, was a
  **real MudOS efun** here (a custom "arith_operator" package, reference
  C source preserved), not a simul_efun — restored as a simul_efun using
  ordinary native `int` arithmetic (this driver's `int` is 64-bit,
  `MAX_INT`/`MIN_INT` confirmed via the boot log's LPC-predefines dump),
  same "simpler is sufficient" choice as the precedent's `nitan_ceshi`
  fix.
- **§8f in general**: the blanket `array`→`mixed *` sweep (see above)
  covers the vast majority of this bug class already; the mahjong-file
  instances were the only additional cases the lpcc sweep surfaced.

## Registration-flow + post-login-command verification (exact transcript)

Full flow verified successfully **5 times** across this pass (once per
significant fix, to re-confirm nothing regressed), each in one
continuous `mudclient.py` session, real Chinese names throughout
(秦风/秦岭/秦山/秦河/秦北/秦海/秦龙 — `--send` sequence: `""`, `"new"`,
`<english id>`, `<Chinese name>`, `<password>`, `<password confirm>`,
`""` [skip email], `"M"`/`"F"` [gender], `""` [wait-to-enter], then
post-login commands). **Final, fully clean run** (id `qinlong`, name
`秦龙`, male):

```
歡迎你進入重生的世界線上 Mud 遊戲。
...
> 你進入遊戲。
[巫師神殿 room description, full text, exits, board summary]

> [score output]
╭───────────────────────────────────╮
｜【無國藉】 秦龙(Qinlong)                                              ｜
├──────────────────────────────── 狀態 ┤
｜ 力量 Str 10             ｜ 年齡 15    食物 0 / 100
｜ 體格 Phy 10             ｜ 天賦 0     飲水 0 / 0
｜ 智商 Int 10             ｜
｜ 敏捷 Agi 10             ｜
｜ 魅力 Cha 10             ｜ 社會經驗         0 / 0
｜ 體力   500 / 500         [graph bar]
｜ 生命   100 / 100         [graph bar]
｜ 精神   100 / 100         [graph bar]
╰──────────────────────────────史前時代─╯

> 你本次共連線了五秒。
[goodbye poem]
你離開遊戲了。
```

`look` shows the real starting room (`巫師神殿`/"Wizard Temple") with
full description, exits (`gocity`, `<South>` etc.), and the player
board summary — no fallback/error text mixed in (confirmed the
`process_input()` fix eliminated the earlier spurious "你可以打 help
求助" line that used to follow every correctly-executed command).
`score` shows fully correct stats matching what `CHAR_D->create_char()`
actually set (confirmed also by inspecting the saved `.o` file directly).
`quit` cleanly saves, shows the session-length message and a goodbye
poem, and disconnects. Gender-aware pronoun text confirmed correct for
both a male (`你`) and a female (`妳`) registration in different runs.
Duplicate-username rejection confirmed working (`"本遊戲已有玩家使用
Qinfeng，請換另一個名字。"`) when accidentally reusing an id from an
earlier test run. The 60-second per-IP anti-flood registration throttle
(`§15j`-shaped, `ppl_login_d.lpc`'s own `ip_time` check) was hit twice
during iterative testing — resolved by waiting it out or restarting the
driver (clears the in-memory throttle map), not a bug.

## lpcc sweep results

835 `.lpc`/`.c` files under `work/` (816 real `.lpc`, plus 19 real C
driver-reference files intentionally left as `.c` under
`doc/driver/modify/source_files/` and 1 plain-text `.txt` under
`doc/v22doc/` that used to be `.c`/renamed — see the orphaned-`.c`
section above). The full-sweep batch run (`lpcc --batch`, one shared VM)
reliably got through **~641/816** files and then reproducibly **hung at
100% CPU** on `wiz/wizhall/room_wizhall_3.lpc` across 3 separate attempts
(same exact stopping point every time) — this room's only content is
placing one `/obj/etc/lotto.lpc` object via `reset_objects()`. Root
cause not fully identified: `lotto.lpc`'s own save data
(`data/object/lotto.o`) was suspected corrupted at first (a naive
open/close-bracket-count check flagged it) but that turned out to be a
**false positive** from literal bare `[NNNm`-shaped ANSI escape text
inside saved string values (confirmed against a second save file,
`data/object/mj112.o`, showing the identical false-positive pattern for
the identical benign reason) — the file's actual content is fine and was
restored after briefly moving it aside to test. A defensive `catch()`
was still added around `lotto.lpc`'s `restore_object()` call as cheap
insurance, but did not resolve the hang. **This hang is specific to
`lpcc --batch`'s cumulative-VM sweep environment** (which, per AGENTS.md
§6b, does process real heartbeats/call_outs across the whole batch run,
unlike a single isolated `lpcc` compile) — it was never observed during
any of the 5 real driver-boot + interactive-session tests, all of which
booted clean and completed full registration + `look`/`score`/`quit`
successfully without ever touching this room. Given the real boot +
interactive test is this project's authoritative verification signal
(and passed cleanly, repeatedly), the partial sweep was accepted rather
than continuing to chase this one file combination further.

Of the ~641 files actually checked, **33 failed**, breaking down as:
- **20 expected**: the intentionally-non-LPC `doc/driver/modify/
  source_files/*.c` reference driver source (`Cannot #include std.h`/
  `spec.h`/`../lpc_incl.h`/`math.h` — none of those headers exist in
  this mudlib tree, nor should they; this is real C, not LPC).
- **6 fixed**: the `OBJECT_ACTION_MOD` content gap (furniture/tools/
  vehicle files).
- **3 fixed**: the mahjong `string arr` → `string *arr` typo (`mj.lpc`
  + both `mj_broken{,2}.lpc` backups).
- **1 fixed indirectly**: `system/kernel/master/object.lpc`'s
  `Undefined variable 'VOID_OB'` is a classic §6b false positive — this
  file is `#include`d into `master.lpc` (which itself `#include`s
  `<object.h>` at its own top) rather than ever compiled standalone;
  confirmed via `debug.log` across every real boot that this error never
  actually occurs in practice, so no fix was needed (the master.lpc
  compile-order bug is exactly what `creator.lpc`'s daemon.h regeneration
  fix, above, made moot for the daemon-constant case, but this one was
  never broken in the first place).
- **2 left as genuine, narrow, non-blocking content gaps, documented not
  fixed**: `combat/handler/unarm.lpc`'s `#include <combat.h>` (file
  doesn't exist anywhere in the archive; the handler file itself is not
  referenced by anything else found in this codebase, so likely
  dead/unused combat-subsystem content — not touched, per "don't
  fabricate missing content" policy) and `obj/npc/etc/user_simulator`
  (`Fail to load object` with zero further diagnostic — the exact same
  uninformative failure shape as lpcc's own single-object-mode
  limitation documented elsewhere in this file; not chased further given
  it's an NPC never touched by the registration/login-flow test).

None of the fixed-or-documented sweep failures are on the registration/
login/look/score/quit path, which was independently and repeatedly
verified via the real interactive driver tests above.

## Config notes
- Original archive shipped 3 external ports (`PPL_PORT`=5000,
  `WIZ_PORT`=5001, `CLIENT_PORT`=5002 in `include/login.h`, matching 3
  `external_port_N` lines in the raw `config.rw`) — this project's
  convention is one port per lib, so `config.fluffos` only opens
  **40081**. Per §15x precedent, `login_ob.lpc`'s `logon()` dispatches
  on `query_ip_port()` matching one of those 3 hardcoded constants —
  without a fix, *no* connection on port 40081 would have matched any
  `case`, silently falling through to `default: return 0;` (dropping
  every connection with zero output). Fixed by repointing `PPL_PORT` to
  `40081` in `include/login.h` (leaving `WIZ_PORT`/`CLIENT_PORT` at their
  original values, since nothing else in this project connects on those
  ports — the wizard-only login path is simply unreachable now, matching
  this project's "breadth over depth" priority; ordinary registration
  works correctly through the PPL_PORT path).
- `master file`/`simulated efun file` repointed from the raw
  `system/kernel/master.c`/`simul_efun.c` to their `.lpc`-renamed,
  work-tree-relative equivalents; all other numeric limits ported
  directly from the original `config.rw` (BIG5-decoded first, per
  AGENTS.md §5, before any other edit).

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (815 files,
  800 written/reformatted, 10 already-clean, 5 refused with an error —
  expected on legacy code).
- **NEW regression found and fixed — the formatter itself, not the
  mudlib**: a full interactive registration through to gender selection
  crashed with cascading compile errors in
  `std/inherit/feature/living/usr/_input_usr.lpc` ("Illegal character
  constant" / "syntax error, unexpected L_NUMBER" / "Illegal LHS"),
  disconnecting the new character before it ever reached the game world.
  Root cause: the pre-format source has a `case ''':	//'` (the
  three-quote-character literal for a bare single-quote, a valid but
  unusual LPC construct this codebase relies on for "type `'hello` to
  say something") followed by its statement body on the *next* physical
  line. The formatter joined the case label, its trailing `//'` comment,
  and the next line's `cmd = "say " + cmd[1..];` statement onto one
  physical line — but a `//` comment runs to end of *physical* line, so
  after the join the comment silently swallowed the real statement, and
  the character literal itself got mangled into `'' '` (an extra space
  inserted mid-literal) in the process. This slipped past the
  formatter's own token-equivalence self-check (the tool still wrote the
  file, i.e. did not flag it as one of the 5 "errors" above) — a real
  gap in the tool given a comment whose scope changes when lines are
  merged, worth flagging upstream, not something to work around by
  avoiding this lib's re-format. **Fixed** by restoring the case label,
  comment, and statement to separate lines (same semantics as the
  original, in the file's now-reformatted style):
  ```
  case ''':  //'
    cmd = "say " + cmd[1..];
    break;
  ```
  Confirmed no second instance of this pattern anywhere else in this
  lib (nor across this batch's other 8 libs) via `grep -rn "'' '"`.
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted (and formatter-regression-fixed) source with a fresh
  real Chinese name (`秦云`, ID `qinyun`) through the full flow (charset
  → `new` → ID → Chinese name → password → email skip → gender →
  reaching the actual game world, 巫师神殿 starting room); `look`/
  `score`/`quit` all produced correct output (the full 狀態 stat card
  rendered correctly), zero real errors in `debug.log`. Also reconfirmed
  this lib's own `uptime() < 30` boot-grace animation (the
  `distributed_system_preload()` progress display in `system_d.lpc`) —
  a connection attempted within the first 30 real seconds after boot
  gets the loading animation and a "please reconnect" message rather
  than the real login prompt; this is pre-existing intentional behavior
  (not a regression), just something to account for when scripting a
  test against a freshly-started driver.
- **WASM build**: this lib is a genuine "does not boot" case, unlike the
  other 8 libs in this batch. `system/kernel/simul_efun.lpc` (which
  every FluffOS driver must be able to load in order to complete
  `fluffos_boot()`) includes `system/kernel/simul_efun/ansi.lpc`, whose
  ANSI-color-code handling calls `pcre_replace_callback`/`pcre_replace`/
  `pcre_match_all` directly. The WASM build ships without the `pcre`
  package at all (documented in `docs/build-wasm.md`'s own "Notes &
  limits", alongside `sockets`/`db`/`ffi`/`crypto`/`async`/`compress`).
  Because this is baked into the **boot-critical** simul_efun file
  itself (not a lazily-preloaded daemon whose failure a lib's own error
  handler can catch), the compile error is fatal: `fluffos_boot()` logs
  "*No program in object '/system/kernel/simul_efun'!... The simul_efun
  ... and master ... objects must be loadable" and the driver never
  reaches a usable state — no telnet-equivalent transcript is produced
  at all under `scripts/wasm_client.js`. **Not a mudlib bug to patch**:
  this lib's use of `pcre_*` for ANSI-code substitution is ordinary,
  working code on the native driver; rewriting its core color-handling
  simul_efun to avoid the `pcre` package entirely would be a substantial
  rewrite well outside a verification pass's scope, and the restriction
  itself is a documented, deliberate WASM-build limitation, not
  something specific to this lib. Verdict: **does not boot under WASM**
  (distinct from every other lib in this batch, all of which booted
  cleanly) — a legitimate, honest incompatibility, not a regression to
  chase.

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Note: this lib does not boot under WASM at all (pcre-dependent color
handling, see above) -- the changes below still apply for local/loopback
native play, which benefits identically from the loopback-allow and
throttle-exempt conventions.

Gates patched (fail-closed: only an exact `127.0.0.1`/`127.`-prefix
match bypasses; a malformed/non-string address falls through to the
original gate logic unchanged):

- `system/daemons/login_d.lpc` `check_login_attacker()` (~line 99):
  loopback exempt from the login-flood check.
- `system/daemons/ppl_login_d.lpc` `logon_handle()` `INITIALIZE` case
  (~line 79): loopback (`is_local`) skips the IP ban-list scan and the
  60s per-IP re-login throttle.
- `system/daemons/ppl_login_d.lpc` `logon_handle()` id-accepted branch
  (~line 213): a wizard-level account connecting from loopback is
  routed straight into the wizard login sub-flow instead of being told
  to reconnect on the (unreachable, single-port) `WIZ_PORT` -- this is
  what lets `fluffos` get wizard powers on the normal port.
- `system/daemons/ppl_login_d.lpc` `ENTER_GAME` case (~line 587): the
  30-command/day per-IP throttle was *already* written fail-closed
  (exact-match loopback check, no `!stringp` fallback) -- no retrofit
  needed here, unlike the other three.
- No `uptime()` startup-grace gate found in this lineage's login path.

Real bug found and fixed while verifying the seeded admin account (not
IP/loopback related): `std/inherit/feature/object/_action.lpc`
`query_actions()` called `fetch_variable("actions")` unconditionally,
which throws on any object inheriting this feature but not declaring an
`actions` global (e.g. the wizard-hall bulletin board) -- this broke
every command evaluated in a room containing such an object, first
surfaced when the admin account logged into the wizard hall. Fixed by
checking `variables(this_object())` first and wrapping the fetch in
`catch()`, treating "no such variable" as "no actions" (§7.14-class).

Admin account: id `fluffos` / `Mud@2026` / 浮浮, already registered
through the normal flow and granted `(admin)` via
`system/kernel/data/secure.o`'s `wizards` mapping (this was already
seeded when this pass picked the lib back up; re-verified rather than
redone). Verified: re-login routes into the wizard login sub-flow
(banner: "本機連線：巫師帳號自動轉入巫師登入流程"), lands in 巫師大廳,
runs `update /wiz/wizhall/room_wizhall_7` -> "編譯與載入 ... 完成" /
"[更新]這裡的房間環境已更新至最新的版本". No separate save file to
force-add: this lineage keeps all account data in the tracked
`system/kernel/data/{password,secure}.o` (+ `_backup`/`_bak` mirrors),
already reflected in this diff.

Cleanup: found and removed TWO stray test accounts left from earlier
verification passes that were never cleaned up -- `ceshiwu` (password.o
+ money.o entries + `data/user/c/ceshiwu/`) and `qinyun` (password.o
entry only, no user dir found; likely from the general native
registration-testing pass, already absent from the working tree when
this pass picked it up). Created and then removed one more
(`ceshiliu`/秦岳) as part of this pass's own fresh-registration retest.

Retest: fresh registration (id `ceshiliu`, name 秦岳, male) reached
巫師神殿 (shared new-player spawn), look/quit correct. Admin login +
`update` verified above. debug.log clean (only boot-time config dump,
`__MUDLIB_ERROR_HANDLER__` pragma name, and the expected SIGTERM line on
kill -- no runtime errors). Two driver instances killed by exact PID
during this pass; one was an orphaned process from the previously-
interrupted agent run on this same lib (killed first so the port could
be reused).
