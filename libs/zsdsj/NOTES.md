# zsdsj — 重生的世界 v1.0.1 (Revival World / RWlib)

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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

GPLv2 的 BIG5 生活模拟游戏，血统完全独立（RWlib v1.0.1，一个带有约 70 个预加载系统精灵的大型内核式 mudlib 代码库，和本项目其它武侠类档案完全无关）。之前被分类为 'noboot'：2026-07-23 的一次复核发现 system/kernel/simul_efun/ansi.lpc 的 ANSI 颜色处理直接从这个启动关键的 simul_efun 档案本身呼叫了 pcre_replace_callback()/pcre_replace()/pcre_match_all()，而当时的 WASM 构建版本根本没有带 pcre 包（fluffos 自己的 docs/build-wasm.md 里有记载）——fluffos_boot() 直接失败报"No program in object '/system/kernel/simul_efun'!"，没有产生任何会话记录，是真正的驱动能力缺口，不是 mudlib 本身的 bug。本次会话针对当前的 WASM 驱动构建版本重新测试，确认 docs/build-wasm.md 现在记载已经加入了 PCRE 支持（"the pcre package is on, so its tests run for real"）——这份档案现在完全干净地启动，不需要任何代码改动。已通过一次完整连续的会话确认：干净启动全部约 70 个预加载系统（少数几个纯粹依赖 socket 的精灵——dict_d、ftp_d、http_client_d、im_d、realnews_d、smtp_d、socket_d、socket_ob、translate_d、whois_d——编译不过被跳过，和本项目其它地方一贯容忍的情况一样，都不阻断启动）；能到达 GB/BIG5 字符集提示和英文 ID 提示；一次完整的全新玩家注册（id→名字→密码+确认→电子邮件→性别）从头到尾完成，进入起始房间（巫師神殿），带有新手提示信息；既有的管理员账号（fluffos，是更早一次 WASM 适配过程中播种进 system/kernel/data/secure.o 的 wizards 映射的）通过本地回环触发的巫师登录自动重定向登录（在再次被提示时重新输入一次 ID，然后输入管理员密码），进入仅限巫师的起始房间（巫師大廳），系统横幅'由<Admin/...>連線進入'确认了管理员阶层；两条流程的 quit 都干净（'你離開遊戲了'）。这份档案更早一次 WASM 适配过程（本地回环放行门槛、节流豁免、播种进 secure.o 的管理员账号）保持不变、依然有效——本轮不需要任何进一步的代码改动，纯粹是因为上游驱动的能力缺口已经补上，属于状态修正。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到"注册+look+score+quit"的浅层冒烟测试（见上一节），
从未真正走进这份档案自己独特的经营/生活模拟系统。本轮找到并修复了
一个会让**每一个新角色永远无法真正喝水**的真实 bug，并借助浏览器环
境（Playwright 驱动的真实 Chromium）确认了这份代码库若干与本项目其
它武侠类档案完全不同的独特设计。

### 发现并修复的 bug：`stat/water/*` 和 `stat/drink/*` 键名不一致

`system/daemons/char_d.lpc` 的 `create_char()`/`create_npc()`（新角
色/NPC 建立时唯一执行一次的初始化函式）把饮水状态写在
`stat/water/max`/`stat/water/cur` 键下；`system/daemons/
birthday_d.lpc` 的生日奖励逻辑也用同一个"water"键给饮水上限加成
（`addn("stat/water/max", random(6) + 15, user)`）。但真正被整个游戏
读写这项状态的唯一实现——`std/inherit/feature/living/
_attribution_liv.lpc` 的 `query_drink_max()`/`query_drink_cur()`/
`cost_drink()`/`add_drink()`——从头到尾用的都是"drink"这个键
（`stat/drink/max`/`stat/drink/cur`），而且这套函式正是 `cmds/std/
ppl/score.lpc`（score 面板显示）、`cmds/std/npc/drink.lpc`（真正的
`drink` 指令）、以及玩家/NPC 两份 `_heart_beat_*.lpc`（心跳一点点消
耗饮水）唯一调用的接口。也就是说 `char_d.lpc`/`birthday_d.lpc` 写的
`stat/water/*` 是一处完全没有任何代码读取的死键，而真正被读取的
`stat/drink/max` 从未被初始化过，映射查找会得到默认值 0——每一个新
角色的"飲水"上限永远卡在 0，`add_drink()` 里
`query_drink_cur() + i > query_drink_max()` 对任何正数 `i` 都恒成
立，导致 `drink` 指令**永远不可能成功**，生日奖励给饮水上限加成的
逻辑也永远是在给一个没人读取的死键加数字。用真实浏览器实测复现：一
个全新角色的 `score` 面板显示"飲水 0 / 0"，`drink` 指令因为上限为 0
根本没有意义。

已把 `char_d.lpc`（`create_char()`/`create_npc()` 两处）和
`birthday_d.lpc`（生日加成那一行）里的 `stat/water/*` 全部改成
`stat/drink/*`，和 `_attribution_liv.lpc`/`score.lpc`/`drink.lpc`/
心跳档案已经在用的真实键名保持一致。修复前后各创建一个全新角色对照
验证：修复前 `score` 显示"飲水 0 / 0"；修复后（`drinktest`/喝水測
試）显示"飲水 0 / 100"，和食物的"0 / 100"完全对称，符合
`char_d.lpc` 本来的设计意图。这份档案既有的存档角色（比如
`ceshiliu`）不会被这次修复自动补正，因为 `create_char()` 只在建立
新角色的那一刻执行一次——这是预期行为，不是本次修复范围内需要处理
的问题（矫正既有存档数据是内容/设计决策，不属于 AGENTS.md §10.7 界
定的编程 bug 修复范围）。

### 已确认属于设计、不是 bug 的观察

- **分批式预加载 + 主动断线重连**：`system/daemons/system_d.lpc` 的
  `distributed_preload()` 会把约 70 个系统精灵的载入拆成多个
  `call_out`，期间任何连线上来的用户都会看到一段完整的载入动画；载
  入全部完成后，`system_d.lpc` 会对所有等待中的连线明确发送"啟動完
  畢，重新連線中..."，然后主动 `destruct()` 掉这个连线对象，要求客
  户端重新连线——这是刻意的架构选择（避开在分批载入期间维护一个半初
  始化的连线状态），不是崩溃。`scripts/wasm_client.js` 自己的文档注
  释里早就记载了这个模式（"a distributed/staggered preload that
  finishes AFTER the connection object already exists"），本次实测
  确认这份档案正是那个模式的实例——WASM 环境下这整个动画耗时明显比
  原生驱动长得多（WASM 下等了 90 秒仍未播完，原生驱动下同样的动画
  在十几秒内就能播完），这是 WASM 模拟层的固有开销，不是这份档案的
  bug；生产网站的播放页面（`index.html`）目前对这种"载入完成后断
  线"没有自动重连处理，只会在 Logs/终端显示"*** disconnected ***"，
  真实访客需要手动点击"+"或重新整理页面——这是站点层面的可用性观
  察，超出本轮"单一 mudlib 深度测试"的范围，留给后续网站体验改进
  一并处理，本轮不做改动。
- **每日新角色注册上限**：`system/daemons/ppl_login_d.lpc` 对同一
  IP 每天限制建立 5 个新角色（`newchar[ip]`，纯内存映射，驱动重启
  即重置，不持久化），本轮测试期间反复注册触发过这个上限——是正常
  的防滥用设计，不是 bug。
- **socket 依赖精灵按预期跳过**：`dict_d`/`ftp_d`/`html_d`/
  `http_client_d`/`im_d`/`translate_d`/`whois_d` 等纯粹依赖 socket
  的精灵在 WASM 下逐一"Failed"，和上一节已经记载的一致，均不阻断
  启动或后续注册/游玩流程。

### 完整验证：从注册到城市地图

用全新账号在原生驱动上完整走通：GB/BIG5 编码选择 → `new` → 英文 id
→ 中文名字 → 密码 + 确认 → 电子邮件（留空跳过）→ 性别 → 巫師神殿
（新角色共享的出生点，一段石造神殿的场景描写）→ `score` 显示完整
五维属性面板（力量/体格/智商/敏捷/魅力，均为 10）→ `command player`
列出完整指令表（`build`/`buildbridge`/`buildterrain`、`buy`/`sell`、
`grow`、`land`/`occupy`、`estate`、`enterprise`、`labor`、`tax`/
`levy`、`quest` 等，印证 README 里"生活模拟/城市经营"的定位不是空
话）→ `mayor` 查看城市列表（目前只有一座"廢棄都市"<Fallencity1>）→
`gocity Fallencity1` 进入该城市地图，触发一套即时渲染的 ANSI 小地
图系统——玩家坐标、地形类型（荒地）、实时时钟、天气、方向罗盘全部
动态显示，是这批档案里见过最精致的自定义终端 UI 之一，和 CITY_D 模
块启动时报告的 1163KB 体积相称。`occupy`/`buy`/`estate` 均正确提示
"必须先加入城市才能拥有房地产"或要求具体参数，`grow` 正确提示"这块
土地不是你的"，`quest` 正确提示"尚未完成任何任务"——经济系统的各条
入口在未入籍状态下全部有意义、无崩溃地拒绝，符合"尚未入籍任何城市
者"这条既有说明。`quit` 干净退出，附带一段郑愁予《赋别》的诗句作为
告别语，"你離開遊戲了。"

### 未覆盖范围（诚实说明）

预算集中在饮水 bug 排查和核心注册/城市/经济入口的验证，没有走到：
真正入籍某个城市、`build`/`grow` 完整产出一轮农作物或建筑、
`enterprise`（企业系统）从零创建一家公司、以及 `fight` 战斗系统
（这份档案的战斗看起来是次要机制，不是核心玩法）。这些留给下一轮，
目前的验证边界如上所述。

## 深度功能测试（第四轮，2026-08-19）——发现并修复四个真实 bug

补测上一轮留下的入籍/build-grow/enterprise/战斗四个系统时，负责本
轮的子代理在验证阶段中途停滞（约 90 分钟无提交、无回应），但已完成
的修复本身经确认是真实、完整、正确的——原地接手，重新独立验证（全
新驱动进程干净启动，`debug.log` 全程无错误）后提交。

### 发现并修复的真实 bug

1. **`set_living_name()`/`enable_commands()` 全档案从未被呼叫过（corpus-wide
   grep 确认），导致 `find_player()` 永远找不到任何在线玩家（含玩家
   自己）**：`load_user()`/`user_exists()` 的后备分支因而会把一个已
   经在线、内存中持有未存档异动的活跃角色物件误判为离线存档，对它
   多做一次 `restore()`（甚至 `destruct()`），静默丢弃尚未落盘的异
   动，没有任何错误提示。修复：在 `ppl_ob.lpc`/`wiz_ob.lpc` 玩家/巫
   师物件本身新增 `register_living_name()`（`set_living_name()`/
   `enable_commands()` 都是只能作用于 `this_object()` 的驱动 efun，
   无法透过 `call_other` 指定别的物件，必须定义在物件自身上），由
   `ppl_login_d.lpc`/`wiz_login_d.lpc` 的 `ENTER_GAME` 分支用 `->`
   呼叫。呼叫前已确认这份档案没有 AGENTS.md §7.112 那种
   `enable_commands()` 重播 `init()` 引发的未防护 `call_out()` 形状。
2. **`city_d_main.lpc` 的 `occupy_new_city()`/`occupy_section_city()`
   占领城市后没有立即写盘**：依赖下一次排程的 `save_all()` 或正常
   关机才落盘，期间若当机/重开机，刚占领的城市会整个恢复成占领前
   的废弃状态（市长、市民、新名称全部遗失），但玩家已经付出的整顿
   费用拿不回来。修复：比照既有的 `create_new_city()` 做法，占领后
   立即 `save_city(..., SAVE_ALL)`。
3. **`emote_d.lpc` 的 `create()` 对存档损毁没有兜底**：`restore_object()`
   是边解析边赋值，就算已经预先把 `emotions` 设成空 mapping，一份
   半损毁的存档仍可能在抛出例外之前就把 `emotions` 覆盖成非 mapping
   值（含 `0`），任何后续呼叫 `is_emote()` 的地方（包含和表情系统完
   全无关的生物初始化路径）都会对 `keys(0)` 崩溃。修复：restore 结
   束后（无论成功与否）强制确保 `emotions` 是 mapping。
4. **`string.lpc` 的 `is_chinese()` 是经典 §8.1 形状**：GBK 双字节
   隔位检查在这个驱动上（`str[i]` 是 Unicode 码位，`strlen()` 按字
   符数计）永远不成立，静默拒绝所有中文字符串。修复为直接检查 CJK
   统一表意文字码位区间。

### 本轮实测消耗的游戏内容（非 bug，如实记录）

验证 bug 2（城市占领落盘）时，占领了 `fallencity1`（一座"废弃城
市"模板）并将其转化重命名为测试用的 `testcityfour`——这是练兵这个
修复本身所必需的真实游玩动作，不是误删；`fallencity1` 原本的
`0/data`/`0/estate`/`0/map`/`info` 档案随占领流程转移/消失，
`www/map/citymap_testcityfour_0.html` 等新档案随之生成。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). This lib's room base class
is `STANDARD_ROOM` (`/std/inherit/standard/standard_room.lpc`), not the
usual `ROOM` macro (`ROOM` here is an unrelated integer constant in
`map.h`). 6 live `replace_program(STANDARD_ROOM);` occurrences across
6 quest room files (`quest/suphia_and_benjamin/room_s_*.lpc` x4,
`quest/old_farmer/room_1.lpc`/`room_2.lpc`). No real room-building tool
exists in this lib (only a static help-doc file happens to share the
name). Fixed by deleting the redundant lines. Verified via a clean
native driver boot (zero new `debug.log` errors, port listening, killed
by exact PID after ~8s).
