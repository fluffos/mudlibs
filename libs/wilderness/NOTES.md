# Wilderness -- porting notes

Source: `https://www.cs.hmc.edu/~jhsu/wilderness/wlib051100.tar.gz` (dated
May 2000; the archive's own `USAGE` file credits it as a build of the
LIMA Mudlib, authored by John Viega/Rust, Greg Stein/Deathblade, and Tim
Hollebeek/Beek at "Lima Bean", with the security system contributed by
Reimer Behrends/Ellery at TMI-2). 2,642 files. `README` describes itself
as "the ALPHA release of the Lima Mudlib"; `include/config.h` sets
`AUTODOC_MUDNAME "wilderness"`, confirming this specific archive is a
real game instance built on that base, not the reference Lima Bean
codebase itself. Slug `wilderness`, number 949, port 40251. Same
cs.hmc.edu (Harvey Mudd College) academic hosting as `libs/lpmud141`,
but an entirely unrelated codebase from a different era of that
department's LPMud hosting -- no code lineage between the two.

## 0. This is the SAME driver-flag conflict as `libs/lima`, but a different snapshot with a genuinely different requirement

`secure/check_config.c` (present in this archive, confirming a real
MudOS-era master-object architecture -- no from-scratch master.lpc
needed here, unlike `lpmud141`) refuses to boot unless the driver was
compiled with `NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS` defined,
`OLD_ED`/`PACKAGE_UIDS` undefined, plus several always-satisfied-by-this-
project's-default-driver checks (`SANE_EXPLODE_STRING`,
`MUDLIB_ERROR_HANDLER`, `PACKAGE_CONTRIB`, `PACKAGE_PARSER`) -- the exact
LIMA-lineage flag set documented in AGENTS.md §7.46 and solved once
already for `libs/lima` via a dedicated driver worktree
(`~/src/fluffos-lima`).

**One flag genuinely differs from `libs/lima`'s own requirement, and
this matters**: `libs/lima` (a 2026-era `fluffos/lima` fork) requires
`#undef ARRAY_RESERVED_WORD`; this 2000-era Wilderness snapshot's own
`check_config.c` requires the OPPOSITE, `#define ARRAY_RESERVED_WORD`
(confirmed: line-by-line diff of both `check_config.lpc`s shows this is
the ONLY substantive difference in the whole `need()` list -- everything
else is identical modulo formatting). The two requirements are mutually
exclusive on one driver binary, so `libs/lima`'s existing
`~/src/fluffos-lima` worktree could NOT be reused as-is. A second,
separate worktree was built instead:

```
cd ~/src/fluffos && git worktree add ~/src/fluffos-wilderness <same commit as fluffos-lima> --detach
```

`src/local_options` edited identically to `fluffos-lima`'s own changes
(`NO_ADD_ACTION`/`NO_WIZARDS`/`NO_LIGHT` from `#undef` to `#define`,
`OLD_ED` from `#define` to `#undef`), PLUS one more line neither
`fluffos`'s nor `fluffos-lima`'s `local_options` had touched:

```c
/* wilderness (Lima-lineage, 2000-era snapshot) requires this DEFINED --
 * the opposite of libs/lima's modern fork, which requires it undef'd. */
#define ARRAY_RESERVED_WORD
```

(`ARRAY_RESERVED_WORD` isn't exposed in `local_options.h`'s own comment
block at all -- it's a `base/internal/options_internal.h` default
[`#undef`] that `local_options` is free to override, since
`options_incl.h` includes `options_internal.h` BEFORE `local_options`.)

Built with the identical CMake flags `libs/lima` used
(`-DCMAKE_BUILD_TYPE=Debug -DMARCH_NATIVE=OFF -DUSE_JEMALLOC=ON
-DSTATIC=OFF -DPACKAGE_UIDS=OFF`), targets `driver`+`lpcc`. **This lib
requires `~/src/fluffos-wilderness/build-debug/{src/driver,src/lpcc}` --
neither the project's shared default driver nor `~/src/fluffos-lima`
will boot it** (`check_config.lpc`'s `ARRAY_RESERVED_WORD` check alone
guarantees exactly one of `libs/lima`/`libs/wilderness` fails on any
single shared binary). Like the `fluffos-lima` worktree, this one lives
outside `libs/wilderness/` and outside git version control -- rebuild
from the steps above if this checkout is ever lost (a few minutes,
one-time).

`scripts/lpcc_check.sh`'s hardcoded `LPCC=~/src/fluffos/build-debug/src/lpcc`
path was changed to `LPCC="${LPCC:-$HOME/src/fluffos/build-debug/src/lpcc}"`
(env-var overridable, same default when unset) so this and any future
LIMA-lineage lib can point it at their own special lpcc without editing
the shared script every time: `LPCC=~/src/fluffos-wilderness/build-debug/src/lpcc
bash scripts/lpcc_check.sh libs/wilderness/config.fluffos libs/wilderness/work`.

**Practical implication for AGENTS.md §7.46**: that entry's "out of
scope for now" verdict (citing `sgzmudsgz`, since purged) is stale --
`libs/lima` already proved the flag conflict is solvable with a
dedicated worktree, and this lib proves the fix generalizes to a second,
independently-configured LIMA-lineage snapshot with a genuinely
different flag requirement. §7.46 has been updated accordingly.

## 1. Conversion

Pure ASCII archive (`LC_ALL=C grep -rlP '[\x80-\xFF]'` found zero
non-ASCII files among 2,642) -- `scripts/convert_lib.sh` ran with
`UTF-8` as the source encoding (skip transcode, rename + reference-fixup
only), matching `libs/lima`'s own precedent for an already-ASCII
archive. 887 `.c` files renamed to `.lpc`, 163 literal `.c"` references
fixed, 11 local angle-bracket `#include`s converted to quotes, 6 files
hit by the `static`->`nosave` sweep.

- **Same `finger_d` extension-missing-duplicate trap as documented in
  AGENTS.md §4.2 item 5**: `secure/daemons/finger_d` (no extension,
  4755 bytes) and `secure/daemons/finger_d.c` (4398 bytes, renamed to
  `.lpc`) are DIFFERENT content -- the extensionless one has an extra
  `PLAYER_INFO_IS_PUBLIC` privacy-gating feature the `.c` one lacks. No
  git history exists (single tarball snapshot) to prove which is
  "current" the way `libs/lima`'s precedent could via `git log`, but
  since this driver (and the original MudOS driver, which also resolves
  bare object names by appending `.c`) only ever loads the
  extension-bearing file, the bare-named file was NEVER reachable by
  normal path resolution on ANY driver, past or present -- it's dead
  draft content either way. Deleted, keeping the `.lpc`-extensioned
  (compiler-reachable) version. Recorded here rather than silently
  discarded since the privacy feature it carried is real content, just
  never live.
- **Same `static`->`nosave` false-positive collision AGENTS.md §4.3
  documents for `libs/lima`, in the SAME shared file**:
  `include/global.h`'s `#ifndef __SENSIBLE_MODIFIERS__ #define nosave
  static #define protected static #endif` compatibility shim (dead code
  on this driver, which always defines `__SENSIBLE_MODIFIERS__`) had its
  own RHS `static` tokens blindly rewritten to `#define nosave nosave` /
  `#define protected nosave` by the sweep. Reverted to original text for
  source fidelity (behavior-neutral either way, since the branch never
  executes). Two more real string-literal false positives caught the
  same way: `domains/std/lima/workroom_ob.lpc`'s room-description text
  "a burst of *static* darts across your screen" (the EXACT same room
  file `libs/lima`'s own conversion notes flagged for this exact false
  positive -- both archives ship this Lima Bean workroom scene
  verbatim) and `wiz/mog/clubhouse.lpc`'s "The TV shows only *static*."
  Both restored to the real English word.

## 2. `ARRAY_RESERVED_WORD`'s bare `array` produces `TYPE_UNKNOWN`, not `TYPE_ANY` -- breaks any double-indexing or strict-typed use, ~285 files affected corpus-wide

The single largest bug class in this lib, and worth cataloging in detail
since `ARRAY_RESERVED_WORD` is a real, still-supported driver feature
(not a legacy-only quirk) that could recur in any future LIMA-lineage or
other classic-MudOS archive.

**Root cause** (confirmed by reading this driver's own compiler source,
not by guessing): `grammar.y`'s `basic_type: opt_atomic_type L_ARRAY`
production computes the array's element type from `opt_atomic_type`,
and `opt_atomic_type`'s empty alternative
(`grammar_rules_types.cc:rule_opt_basic_type_empty()`) returns
`TYPE_UNKNOWN` (0) -- NOT `TYPE_ANY` (1) as a surface reading of the
grammar comment ("defaults to TYPE_ANY") would suggest. So a BARE
`array` declaration (no preceding element type, e.g. `array x = ...`,
as opposed to `int array x` / `string array x` which supply an
explicit `opt_atomic_type`) compiles to `TYPE_UNKNOWN | TYPE_MOD_ARRAY`.
Indexing it once (`x[i]`) hits the `default:` branch of
`rule_primary_expr_index()`/`rule_expr_index()`
(`grammar_rules_exprs.cc`), which strips the array bit and yields bare
`TYPE_UNKNOWN` for the element -- and a SECOND index on that result
(`x[i][j]`), or passing it to a strictly-typed parameter, or an
argument-type check, then falls through to `type_error("Value indexed
has a bad type ", TYPE_UNKNOWN)` (prints as `"unknown"`) or a `Bad type
for argument`/`Bad type of argument used for range` error, because
`TYPE_UNKNOWN` doesn't match any of the switch's other cases the way
`TYPE_ANY` would have.

On the classic MudOS driver this archive actually shipped for, bare
`array` was almost certainly equivalent to today's `mixed *` (freely
re-indexable, no static-type friction) -- this archive uses the idiom
pervasively (~285 real declarations across the whole tree: local
variables holding `unique_array()`/`explode()`/similar results,
function parameters, `varargs`/`...` collector parameters, function
return types) with the clear intent of "array of anything, don't care
what's inside, may itself contain nested arrays." This driver's
stricter, `TYPE_UNKNOWN`-yielding interpretation of the SAME keyword is
a genuine dialect gap, not a mudlib bug -- exactly the kind of
driver-compat issue this project fixes proactively.

**Fix**: mechanical sweep changing every bare `array` type token (in an
actual declaration position -- function return type, parameter type, or
local variable type; never inside a comment or string literal) to
`mixed *`, which is `TYPE_ANY | TYPE_MOD_ARRAY` and behaves exactly as
intended (freely re-indexable, passes any argument-type check expecting
`mixed`/`mixed *`). Already-typed forms (`int array`, `string array`,
`object array`, `class Foo array`) were left untouched -- they already
carry a real, non-`TYPE_UNKNOWN` element type and aren't affected by
this bug.

Implementation: a small Python script
(`scratchpad/fix_array_type.py`, not committed -- throwaway tooling)
walked every `.lpc`/`.h` file, tracked block-comment state across lines,
and replaced `\barray\b` tokens NOT immediately preceded by
`(int|string|object|mixed|mapping|float|function|buffer|class NAME)`
with `mixed *`. **First pass had a real bug, caught by manual audit
before trusting the result**: the script's string-literal handling was
incomplete (it correctly avoided misreading `//`/`/* */` comment
delimiters found INSIDE a string, but never actually excluded the
string's OWN contents from substitution) -- 5 genuine string literals
containing the word "array" as legitimate text got corrupted into
"mixed *" mid-sentence (`secure/daemons/imail_d.lpc`'s "BCC list should
be an array" error message, `secure/daemons/lpscript_d.lpc`'s two
code-generation strings that literally emit the text `"array patterns =
({ "` as LPScript source, `include/driver/type.h`'s `#define ARRAY
"array"` string constant, and `trans/obj/dataedit.lpc`'s `case
"array":` switch label). Found by re-running the same sweep against a
freshly-reconverted pristine copy and diffing every changed file's full
content (not just spot-checking), then grep-verified corpus-wide for any
`"[^"]*mixed \*[^"]*"` pattern (i.e., "mixed *" appearing inside a
quoted string, always wrong) -- exactly 5 hits, all fixed by hand back
to their original text. A second full-tree audit after the fix (masking
already-typed prefixes and checking for any REMAINING bare-`array`
match in a real code position, ignoring the same 5 confirmed-legitimate
string literals) found zero further instances. Also caught in the same
sweep: two `domains/std/2.4.5/`-tree files
(`domains/std/2.4.5/obj/tmp_leo.lpc`, `domains/lpscript/tmp_harry.lpc`)
whose `array patterns`/`array num` declarations were somehow NOT
converted by the sweep's first real run against the live `work/` tree
despite matching the same pattern (root cause not fully pinned down --
possibly a `tail -N` truncation in this session's own review of the
sweep's file list hid them from an earlier verification pass, not a
flaw in the sweep logic itself, since a later masked full-tree scan
found and fixed them cleanly); fixed identically by hand once found via
the same audit.

Verified: `lpcc_check.sh` failure count dropped from 285/887 to 144/887
after this one fix alone -- the dominant bug class in this lib by a wide
margin.

## 3. Same LIMA-lineage `.c`->`.lpc` extension-width bugs `libs/lima` already found, PLUS new instances in files lima's own conversion didn't touch

`libs/lima`'s own NOTES.md documents `[0..<3]`/`[<2..]`-style fixed
2-character slices (correct for stripping `.c`, wrong for `.lpc`) in
`cmd_d.lpc`, `spell_d.lpc`, and `quest_d.lpc`. This archive -- an older,
independent LIMA snapshot, not derived from `libs/lima`'s modern fork --
has the exact same idiom, confirming it's baked into the LIMA lineage
itself rather than being fork-specific drift. All of `libs/lima`'s three
known files needed the identical fix here too, PLUS four more instances
`libs/lima`'s own sweep never encountered (either because that fork's
`cmd_d.lpc`/etc. genuinely differ, or because this session searched more
exhaustively):

- `secure/daemons/cmd_d.lpc`: `cache_dir()`'s `map(files, (:
  $1[0..<3] :))` and `smart_arg_parsing()`'s `cmd_name = tmp[1][0..<3]`
  -- **the single highest-impact instance**: this is the bare-word
  command-name cache (`score`, `inventory`, `quit`, etc. all resolve
  through this), so EVERY bare-word command in the game was unusable
  before this fix (`I don't know the word: score.` etc., reproduced
  live). Both widened to `[0..<5]`.
- `daemons/spell_d.lpc`: rebuild-spell-cache loop's `string obname = dir
  + file[0..<3]` (unconditional, no guard) -- widened to `[0..<5]`.
- `daemons/quest_d.lpc`: `if(base[<2..] == ".lpc") { base =
  base[0..<3]; }` -- the GUARD itself compared a 2-character slice
  against the 4-character string `".lpc"`, which can never be true, so
  the strip silently never fired (harmless-looking today since nothing
  else in this archive currently depends on the stripped form, but
  fixed for correctness: guard widened to `base[<4..]`, strip to
  `[0..<5]`).
- **New, not in `libs/lima`'s list**: `daemons/doc_d.lpc`'s
  documentation-cache rebuild, `item[0][<2..<1] == ".lpc"` (a 2-char
  slice via the `[<2..<1]` bounded form, same bug, same "guard never
  fires" consequence) -- widened to `[<4..<1]`.
- **New**: `trans/cmds/dir.lpc`'s wizard-shell `ls`-equivalent
  `colourize()`, `file[<2..] == ".lpc"` (alongside correctly-untouched
  2-char `.h`/`.o` checks in the same function) -- cosmetic-only
  (ANSI syntax-highlighting color for `.lpc` files in directory
  listings falls through to a different color instead of erroring), but
  fixed for consistency: widened to `[<4..]`.
- **New**: `secure/daemons/rcp_d.lpc`'s remove-file handler, `if(
  arg[<2..] == ".lpc" ) { arg = arg[0..<3]; }` -- same never-fires
  guard; widened identically (`[<4..]` / `[0..<5]`).
- **New**: `cmds/create/scr_command.lpc`'s `not_a_cmd()`,
  `__FILE__[0..<3]` with an explicit `// no .c` comment confirming
  original intent -- widened to `[0..<5]`.
- **New**: `WWW/cgi/autodoc.lpc` (dead code -- `http_d`, the only daemon
  that would ever invoke it, is commented out of `data/config/preload`
  exactly as in `libs/lima`'s own precedent): 4 instances across
  `last_part()`'s guard+strip, `module_summary_line()`, and
  `object_summary_line()`, plus 2 more `filter(tmp, (: $1[<2..] ==
  ".lpc" :))` calls in `handle_overview()`. Fixed for source-fidelity
  consistency even though unreachable in normal play, same reasoning
  `libs/lima` applied to this identical file.

One genuinely NEW instance in this archive that has no `libs/lima`
analog at all: `contrib/http_connection.lpc:93`'s `file[<1..<2] ==
".lpc"` uses a BACKWARDS range (`<1` = last-char index, `<2` =
second-to-last -- since `<1`'s underlying index is numerically LARGER
than `<2`'s, `[<1..<2]` is an empty/invalid range regardless of what
string length or extension width is involved). This is a pre-existing
authoring bug unrelated to the `.c`->`.lpc` rename (it would have been
equally broken checking for the 2-character `.c` too) -- left unfixed,
consistent with this project's "don't guess at content intent" policy;
`contrib/` is optional bonus code and `http_d` isn't preloaded anyway.

## 4. `secure/simul_efun/string.lpc`'s `chr(0)` crashes `create()` -- this driver rejects embedding a literal NUL byte via `sprintf("%c", 0)`

`create()` builds a 256-entry `ascii` lookup table (`for(i=0; i<256;
i++){ if(i==0)ascii+=" "; ascii += chr(i); }`, where `chr(i)` is this
lib's own `sprintf("%c",i)` simul_efun) later sliced up into
case-conversion tables (`_lower`/`_upper`/`_swapcase`). The author's own
`if(i==0)ascii+=" "` line shows they already knew byte value 0 needed a
substitute placeholder (a literal NUL inside an LPC string is
problematic on C-string-based drivers) -- but the very next
unconditional statement, `ascii += chr(i)`, still ran for `i==0` anyway
and called `chr(0)` regardless, which THIS driver's `sprintf("%c", ...)`
outright rejects: `*(s)printf(): Incorrect argument to type %c, must be
valid UTF8 char. (arg: 0)`, thrown from inside `simul_efun`'s own
`create()` -- fatal at boot (`The simul_efun ... object must be
loadable`), before `master.lpc` even attempts to load. This is also a
genuine PRE-EXISTING bug independent of the driver crash: the original
code appended BOTH the placeholder space AND (before crashing here) the
real `chr(0)` for `i==0`, which would have made `ascii` 257 characters
long instead of 256 and shifted every subsequent index by one relative
to its real byte value -- i.e. the intended fix (skip the real `chr(0)`
call entirely when substituting the placeholder) also happens to fix a
latent indexing bug, not just the crash.

Fixed with an `else`, so `i==0` gets ONLY the placeholder and `chr(0)`
is never actually invoked:

```c
for(i=0; i < 256; i++){
   if(i==0)
	ascii+=" ";
   else
	ascii += chr(i);
}
```

## 5. `secure/master.lpc`'s virtual-object compile fallback + a `STR()`-vs-`STRINGIZE()` stringify-before-expand macro bug together produce genuine infinite recursion, not just a cosmetic path

`secure/master.lpc`'s `compile_object(path)` implements a classic
virtual-object fallback: walk UP `path`'s directory components looking
for a real `.lpc` ancestor file, and if found, call
`ancestor->virtual_create(remaining_suffix)` via `call_other()`. This is
normal, working LIMA-lineage code -- the bug is what path gets fed into
it.

`std/classes/event_info.lpc` and `include/combat_modules.h`'s `MODULE()`
macro both used this header's OWN `STR(y)` (`#define STR(y) #y` -- a
raw C-preprocessor stringify, which does NOT macro-expand its argument
first, per standard `#`-operator semantics) on `BLOW_MODULE`, itself a
macro (`#define BLOW_MODULE simple`, selected by
`include/combat_modules.h`'s own config). `STR(BLOW_MODULE)` therefore
stringifies the LITERAL TOKEN TEXT `"BLOW_MODULE"`, not its expansion
`"simple"` -- `inherit __DIR__ "event_info/" STR(BLOW_MODULE);` compiles
to `inherit "/std/classes/event_info/BLOW_MODULE";`, a path that never
corresponds to a real file (the real files are `event_info/simple.lpc`
/ `event_info/types.lpc`). The header's OWN author already anticipated
this exact trap and defined the correct two-level-indirection fix right
next to the broken one -- `#define STRINGIZE(z) STR(z)` (the extra
macro layer causes `z` to be expanded as a normal macro argument BEFORE
`STR` stringifies it, the standard C idiom for "stringify the expansion,
not the token") -- and even used `STRINGIZE(BLOW_MODULE)` correctly in
a SIBLING file (`std/adversary/blows/base.lpc`). `event_info.lpc` and
the `MODULE()` macro itself just used the wrong one of the two.

This isn't merely a wrong/dead path, though -- it's genuinely
**infinitely recursive**, confirmed by instrumenting `compile_object()`
with a temporary `write_file()` debug line and reproducing live: walking
up from the bogus path `/std/classes/event_info/BLOW_MODULE` finds
`/std/classes/event_info.lpc` (the file containing the broken `inherit`
line itself!) as the nearest real ancestor, so the driver tries to
`call_other()` into `/std/classes/event_info` to find its
`virtual_create` function -- which requires COMPILING
`/std/classes/event_info.lpc` first -- which re-triggers resolving its
OWN unresolved `inherit "/std/classes/event_info/BLOW_MODULE"` -- which
calls `compile_object()` again for the exact same bogus path -- forever.
295 identical debug-log entries for the one path confirmed this before
the fix. The recursion eventually trips this driver's hardcoded
`CFG_MAX_CALL_DEPTH` (150, a compile-time C++ array bound, NOT the
runtime-configurable `maximum call depth` setting) and aborts with
`Too deep recursion.`, repeatedly, every time ANYTHING tries to load a
combat-capable object (i.e. constantly, since `std/adversary.lpc`
inherits `event_info`-consuming modules) -- surfaced first as spurious
noise during boot (8 occurrences while preloading unrelated daemons)
then, far more consequentially, as a hard block on creating the very
first player body (`std/body.lpc` -> `std/adversary.lpc` ->
`event_info`), immediately followed by a cascading `*Bad argument 1 to
EFUN call_other() ... Got: int(0)` once the recursion aborted mid-setup
and left the body in a broken half-initialized state. **No character
could ever finish logging in before this fix.**

Fixed by changing both misuses to `STRINGIZE()`:

```c
// include/combat_modules.h
#define MODULE(x, y) SUBDIR x "/" STRINGIZE(y)   // was STR(y)
// std/classes/event_info.lpc
inherit __DIR__ "event_info/" STRINGIZE(BLOW_MODULE);   // was STR(BLOW_MODULE)
```

Corpus-wide grep confirmed these were the ONLY two `STR(...)` call sites
in the whole tree not already using the correct `STRINGIZE(...)` form.

**A related, initially-misleading config workaround that turned out to
be unnecessary**: before root-causing the above, `inherit chain size`
was raised from 30 (borrowed from `libs/lima`'s own config) to 300 in
`config.fluffos`, reasoning that this archive's much larger combat-module
composition (`std/adversary.lpc` alone inherits 8 `MODULE()`/`SUBDIR`
combat submodules on top of `std/body.lpc`'s own ~20) might legitimately
need a higher `num_objects_this_thread` budget than Lima's own simpler
body class. This DID stop the original `Inherit chain too deep: > 30`
symptom, but only by giving the SAME underlying infinite recursion 10x
more iterations before hitting the (also-configurable) inherit-count
ceiling instead -- it then surfaced as `Too deep recursion` against the
driver's separate, non-configurable 150-deep C++ call-stack limit
instead. The 300 value was kept in the final config regardless (this
archive's combat system genuinely does load more distinct files per
player-body creation than Lima's own simpler composition, confirmed by
the corrected boot completing cleanly with zero `Inherit chain too deep`
noise even after the real recursion bug was fixed), but it was NOT the
actual fix -- worth flagging explicitly so a future reader doesn't
mistake a symptom-mitigating config bump for the real root cause the way
this session initially did.

## 6. `private protected` -- both access modifiers on one declaration, illegal here (AGENTS.md §7.48 sibling)

`std/modules/m_exit.lpc:306`: `private protected string eval_dest(mixed
arg)` -- this driver hard-errors on `Multiple access modifiers` for ANY
two-modifier combination among `private`/`protected`/`public`; the
classic driver apparently tolerated (or silently resolved) stacking
them. Confirmed as genuine original archive content (byte-identical in
`raw/`, not a conversion artifact). `eval_dest()` is called from a
SIBLING file that inherits `m_exit.lpc` (`std/modules/m_exit_obj.lpc`),
i.e. exactly the §7.48 "inherited-private" shape this project already
catalogs -- and `protected` (which permits inherited access, unlike a
strictly-enforced `private`) is clearly the intended single modifier
here. This was the ONLY `private protected`/`public private`/etc.
dual-modifier instance anywhere in the whole tree (corpus-wide regex
grep after the fix confirms zero remaining). Fixed by dropping
`private`, keeping `protected`.

## 7. Same `ENSURE(x /* comment */)` inline-block-comment-in-macro-argument driver bug `libs/lima` already found, same file even

`libs/lima`'s NOTES.md documents this driver's real preprocessor bug:
a `/* ... */` block comment written INSIDE a macro call's argument list
breaks macro expansion entirely (`Undefined function ENSURE`, cascading
into unrelated syntax errors). This archive hits the EXACT SAME macro in
the EXACT SAME FILE (`daemons/spell_d.lpc`'s `register_spell()`,
`ENSURE(spell_name /* You didn't provide a spell name. */);` and the
following line) -- unsurprising, since `ENSURE`/`assert.h` is shared
LIMA-lineage infrastructure, but confirms this driver bug (not yet fixed
upstream, not in this project's scope to fix at the driver level) is a
recurring hazard for ANY future LIMA-derived archive. Fixed with the
same equivalent, meaning-preserving rewrite `libs/lima` used -- move the
comment OUTSIDE the macro call:

```c
ENSURE(spell_name); /* You didn't provide a spell name. */
ENSURE(valid_spell_name(spell_name)); /* Your spell name wasn't valid. */
```

This one fix unblocked `daemons/spell_d.lpc` itself plus the 5 spell
files that fail to compile whenever their base daemon does
(`domains/std/spells/{unlock,test,stock-mage/std_mage_spell,
stock-mage/frotz}`, `daemons/spell_d` -- confirmed via `lpcc_check.sh`'s
before/after failure list).

## 8. Too-narrow declared parameter types where the function body/doc comment already documents wider real usage (recurring pattern, `libs/lima`'s own §2 bug #2 precedent, 4 more instances found here)

`libs/lima`'s own NOTES.md documents exactly this shape once
(`set_droppable(int g)` declared too narrow when the body already
branches on `functionp(g)||stringp(g)` and the doc comment says so).
This archive has the SAME root shared-module file (`m_gettable.lpc`) --
confirming this is a LIMA-lineage-wide authoring habit (declare the
common case, let the body handle the documented wider contract, and
never notice the mismatch until a driver enforces static argument
types) -- plus three more independent instances found by the same
"declared type narrower than the function's own body/doc comment"
read-through:

- `std/modules/m_gettable.lpc`'s `set_droppable(int g)` -- same file,
  same bug, same fix as `libs/lima`: widened to `mixed g` (doc comment:
  "If a function or string is passed..."; body: `functionp(g) ||
  stringp(g)`).
- `std/object/description.lpc`'s `set_in_room_desc(string arg)` (plus
  its forward-declaration prototype in `std/modules/m_openable.lpc`) --
  the backing storage variable `in_room_desc` is itself declared `mixed`
  and `query_in_room_desc()` calls `evaluate(in_room_desc)` (this
  codebase's standard "resolve if function pointer, else return as-is"
  idiom), but callers passing a function pointer
  (`contrib/board.lpc`/`contrib/boards/board.lpc`/
  `wiz/branin/workroom.lpc`'s `set_in_room_desc((: do_desc :))`) failed
  static type-checking against the too-narrow `string` parameter.
  Widened both declarations to `mixed arg`.
- `std/fluid.lpc`'s `set_fluid_level(int x, string y)` -- the body does
  `if (y) set_quantity(y); else set_quantity(x);`, i.e. `y` is meant to
  be an alternate numeric quantity override just like `x`, not a
  string; every real call site (`std/modules/m_fluid_container.lpc`,
  `std/fluid.lpc`'s own recursive call) only ever passes the first
  argument, so this branch is presently dead code at runtime, but the
  declared type was still a genuine static mismatch against
  `set_quantity(int x)`. Fixed by correcting the declaration to `int y`
  (matching the parameter's actual intended semantics, not guessing at
  new behavior).
- `std/portal.lpc` and `std/ladder.lpc`'s `set_destination(function f)`
  -- both doc comments explicitly say "Valid arguments are a function
  pointer or a filename", and both bodies pass `f` straight into
  `add_method("enter"/"climb", f)`, whose own `destination` parameter is
  `mixed` (widened separately, see below). `portal.lpc`'s own live call
  site (`domains/std/cult/portal.lpc`'s `set_destination(WIZARD_START)`,
  a string constant) tripped this exactly. Both widened to `mixed f`.
- `std/modules/m_complex_exit.lpc`'s `set_method()`/`add_method()` --
  the `exit_messages`/`enter_messages` parameters were declared `mixed
  array` (itself a `TYPE_ANY|TYPE_MOD_ARRAY` combo, unaffected by the
  §2 bug above since it has an explicit `mixed` element type), but the
  function BODY explicitly branches `if(arrayp(exit_messages)) ... else
  if(stringp(exit_messages)) ...` -- a single bare string is a
  documented, working input (`std/furniture.lpc`'s
  `add_method("sit on", ..., "$N $vsit on the $o,")` passes one), yet
  the array-only declared type rejected it statically. Widened both
  parameters on both functions to plain `mixed`.

## 9. `std/book.lpc`'s `remove_contents()`: `foreach` loop ignores its own loop variable

`remove_contents(string array headings...) { foreach(string heading in
flatten_array(headings)) remove_synonym(headings); }` -- passes the
WHOLE outer array `headings` to `remove_synonym()` on every iteration
instead of the per-iteration loop variable `heading`. A genuine
pre-existing authoring typo (would have behaved wrong -- silently
removing nothing useful, or erroring on the type mismatch depending on
driver leniency -- on the original driver too), only surfaced now
because this driver's stricter `remove_synonym(string syn)` argument
type-check turns the always-passing-an-array mistake into a hard compile
error instead of a silent runtime no-op. Fixed: `remove_synonym(heading)`.

## 10. `std/modules/m_exit.lpc`'s per-direction accessors dereference `exits[direction]` unconditionally -- crashes any room that queries/sets an enter/exit message, description, or check for a direction that was never added via `set_exits()`/`add_exit()`

16 call sites across 13 functions (`query_enter_msg`, `set_enter_msg`,
`add_enter_msg`, `remove_enter_msg`, `list_enter_msgs`,
`query_exit_msg`, `set_exit_msg`, `add_exit_msg`, `remove_exit_msg`,
`list_exit_msgs`, `query_exit_description`, `set_exit_description`,
`set_exit_check`) all did `exits[direction]->SOMETHING` with no check
that `exits[direction]` (a `class move_data`, populated only by
`add_exit()`/`set_exits()`) actually exists yet. When it doesn't, this
is `0->SOMETHING` -- `*Tried to take a member of something that isn't a
class.`, uncaught, aborting the calling object's `create()`/`setup()`
entirely. (One accessor, `query_exit_check()`, already had its own
`member_array(direction,keys(exits))==-1` guard -- confirmed as the
correct existing pattern, extended to the other 13.)

Live-reproduced via `domains/std/Car_Wash.lpc` (the connected "example
room" area reachable one hop east of Grand Hall, so this is genuinely
on the explorable path, not deep dead content): its `setup()` calls
`set_exits((["west":"Example_Room1"]))` (registering ONLY "west") then
`set_enter_msg("east", "As $N $venter the car wash...")` -- an "east"
direction this room never actually has an exit for (the room's only
real connectivity is the reciprocal "west" back to Example_Room1; there
is no design reason this room needs an "east" exit at all, so this
reads as leftover/copy-pasted content rather than a intended-but-broken
feature. Whether the message was meant to live on Example_Room1's own
"east" exit instead -- `set_enter_msg`'s own doc comment: "This message
will be displayed in the DESTINATION room" -- is exactly this kind of
"can't guess original intent, don't invent new content" case this
project's methodology says to leave alone).

The SAME bug, via a different trigger, also crashed EVERY object
carrying a sword: `std/sword.lpc`/`domains/std/sword.lpc`/
`wiz/mog/sword.lpc` all called `set_combat_messages("combat-sword")` --
a message-type key that was never actually added to
`daemons/messages_d.lpc`'s data table (only `"unarmed"`, `"edged"`,
`"blunt"`, `"piercing"`, `"weapon"`, `"poke"`, `"fish"`, and
`"combat-torch"` exist there; sibling sword-like weapons
`crystal_sword.lpc`/`broadsword.lpc`/`flaming_zweihander.lpc`/
`scimitar.lpc` all correctly use `"edged"`, and all three `sword.lpc`
copies ALSO call `set_weapon_skill("edged")` two lines later, confirming
`"edged"` -- not `"combat-sword"` -- was always the intended category).
`set_combat_messages()`'s own body (`std/modules/m_damage_source.lpc`)
already guards this with a real `error()` on an unknown type (`"No
messages of that type."`), so THIS particular gap was already a hard,
correctly-signposted crash rather than a silent 0-dereference -- but it
took down every sword-carrying object's `create()`, including
`std/adversary.lpc`'s base `mudlib_setup()`->`set_combat_messages("unarmed")`
call for the object that TRIES to wield the sword (an NPC picking up
a chest-spawned sword, or a room's `set_objects()` eagerly creating one
at `make_objects_if_needed()` time), confirmed live via
`domains/std/rooms/caves/Grotto`/`domains/std/Attic`/`domains/std/Shop`
(all spawn a chest or an NPC that ends up holding
`/domains/std/objects/sword`, which inherits `SWORD` = `/std/sword`)
all failing to `update`/load until this was fixed. Both bugs needed
fixing together to get these rooms clean: `set_combat_messages()`'s
argument corrected to `"edged"` in all three `sword.lpc` copies, PLUS
the `m_exit.lpc` defensive guards (since even with the sword crash
fixed, `Car_Wash.lpc`'s own unrelated bad direction would still have
crashed it).

Fix applied to all 16 sites: an `if(!exits[direction]) return;` (void
setters) / `return 0;` (list-type getters) / fall through to the
existing `query_default_exit_message()` default (message-text getters,
matching what already happens when the resolved message list is empty)
guard immediately before the first dereference in each function, added
without touching the earlier `present(direction)->is_exit()`
special-case branch each function already has for the OTHER
(complex-exit-object) exit representation. This is a defensive-guard
fix in the same spirit as this project's many other "old driver
tolerated a stray 0-dereference, this driver doesn't" fixes (e.g. the
`get_dir()`-returns-0-not-empty-array class) -- restoring the original
archive's presumably-silent behavior for a case its own author never
guarded against, not inventing new game behavior.

## 11. Compile-sweep results and confirmed non-bugs (`lpcc_check.sh`, 887 files)

After all fixes above: **853 pass, 34 fail**. Every remaining failure
was individually triaged (via `lpcc_check.sh`'s batch output AND,
wherever the batch tool's own error text looked suspicious, a live
`update <path>` from a real wizard session to cross-check against actual
boot behavior per this project's own "batch mode can be a spurious
artifact" precedent):

- **`daemons/channel/moderation.lpc`, `secure/daemons/ftp_d.lpc`**:
  confirmed `lpcc_check.sh` sweep false positives, NOT real bugs.
  `moderation.lpc` is explicitly `#include`-text-spliced into
  `channel_d.lpc` (its own comment: "this file is currently included
  into the channel daemon (rather than inherited cuz we can't do this
  inherit (driver))") -- it only ever compiles as PART OF
  `channel_d.lpc` (which loads and runs cleanly, confirmed live), never
  standalone; the batch sweep's blind "compile every `.lpc` file
  independently" approach naturally can't see the `class channel_info`
  that's only visible via `channel_d.lpc`'s own `inherit` chain. Same
  class as this project's documented precedent for test-fixture/
  include-only files (`lpmud141`'s `soul_com.lpc`, `libs/lima`'s own
  ftp_d `functional`-local-variable note). `ftp_d.lpc`'s "Illegal to use
  local variable in functional" is the SAME genuine driver limitation
  `libs/lima`'s NOTES.md already documents for the identically-named
  file in that fork -- `ftp_d` isn't in `data/config/preload` here
  either (commented out, same as `libs/lima`), so it's dead by design,
  not a live bug.
- **`obj/secure/mailers/{mailer,Mh,standard}`**: batch sweep shows a
  bare, textless "Fail to load object" for all three with zero error
  text -- but a live `update /obj/secure/mailers/mailer` from a real
  wizard session shows `Updated and loaded.` with no error at all. This
  is a genuine `lpcc --batch` cross-object-state artifact (this
  project's own memory already documents "batch compile can spuriously
  trip cost-limit; cross-check real boot" as a known class) -- these
  three compile and load cleanly on a real boot, no fix needed or
  possible. (Unlike `libs/lima`'s OWN mailer files, which reference a
  genuinely-missing `trim_spaces()` in that fork -- this archive's own
  `trim_spaces()` IS defined, both in `secure/simul_efun/string.lpc` and
  `secure/master.lpc`, so that specific `libs/lima` gap does not apply
  here at all.)
- **`std/accountant`/`domains/std/bank_accountant`**: `Bad type for
  argument 2 of add_menu_item ( class flag_set_info vs class
  flag_set_info )` -- both sides of the reported mismatch print the
  IDENTICAL class name, and that class (`std/object/flags.lpc`'s
  `flag_set_info`) has nothing to do with `add_menu_item`'s real
  `MENU`/`MENU_ITEM` (= `class menu`/`class menu_item`, both defined
  once, unambiguously, in `std/menu.lpc`) parameter types at all --
  confirmed real (reproduces identically on a live `update`, not a
  batch-only artifact), but looks like a genuine driver-level struct/
  class type-name bug in this driver's own error-message formatter (an
  internal type-name lookup returning a stale/wrong entry), not a
  mudlib bug -- out of this project's scope to fix a driver defect
  directly. Low priority regardless: `bank_accountant.lpc` is
  unreferenced by any other file in the whole archive (no domain places
  or clones it), so this is dead, unreachable content either way.
- **`std/room/exits.lpc`**: `Unable to find the inherited function
  'can_go_somewhere'` -- `can_go_somewhere()` calls `::can_go_somewhere()`
  but no ancestor in its `inherit M_EXIT` chain defines that function at
  all (confirmed: zero definitions anywhere else in the tree). A
  genuine pre-existing broken super-call, but this file is never
  inherited by anything in the whole archive (confirmed via grep) --
  dead, unreachable code, left as-is per this project's "don't guess at
  content intent" policy.
- **`domains/std/{river,table,keg}`, `contrib/{homepage_d,marriage/body}`**:
  `syntax error ... expecting L_STRING or '('` on `inherit
  DAEMON;`/`inherit MONSTER;`/`inherit M_DRINK_SOURCE;`/`inherit
  COMPLEX_CONTAINER;` -- these 4 macro names are not `#define`d ANYWHERE
  in this archive, raw OR converted (confirmed by grep against
  `raw/lib/` directly), across 5 unrelated files (2 drink-themed rooms,
  1 furniture room, 1 contrib daemon, 1 contrib mixin). Pre-existing,
  archive-original incompleteness (the classic driver would have failed
  these identically -- an undefined bareword before `inherit` was never
  going to compile on ANY driver), not something this project's
  conversion caused or can safely guess a fix for.
- **`domains/std/rooms/caves/Sloping_Tunnel`,
  `domains/std/attic/{townroom,coffee_table,beavis,butthead}`**:
  undefined functions (`set_default_exit`, `set_preposition`,
  `run_script`/`add_script`) and an undefined variable (`townroom.lpc`'s
  `switch(i)` with no `i` ever declared) -- the `attic/` directory name
  is this codebase's own "deprecated/incomplete" marker (matching
  `libs/lima`'s identical precedent for its own `attic/` content, two
  easter-egg NPCs using undefined script-hook functions); the caves
  room references a helper (`set_default_exit`) genuinely absent
  archive-wide, matching `libs/lima`'s own documented gap for its
  sibling `domains/std/rooms/{caves,labyrinth}` tutorial content.
  Pre-existing incomplete demo content, not fixed.
- **`contrib/marriage/{finger_d,finger}`**: `Class 'finger' has no
  member 'spouse'` -- the EXACT SAME gap `libs/lima`'s NOTES.md already
  documents for its own copy of this optional contrib module (an
  incomplete refactor left `spouse` referenced but never added to the
  `class finger` definition). Left unfixed for the same reason: fixing
  it means inventing a plausible definition for a member nobody ever
  wrote, not restoring anything.
- **`domains/std/objects/portable_board`**: `Inherited file
  '/obj/mudlib/board' does not exist!` -- `BOARD_OB` (`include/
  mudlib.h`) points at a path that was never actually shipped in this
  archive (the real bulletin-board implementations live at
  `contrib/board.lpc`/`contrib/boards/board.lpc` instead); unreferenced
  by anything else in the tree, so dead content either way.
- **`domains/std/Car_Wash`**: was a real, now-fixed bug (§10 above);
  listed here only to note it no longer appears in a fresh sweep.
- **`domains/std/2.4.5/{tmp_yard,tmp_hump,tmp_sea_bottom,tmp_adv_guild}`,
  `wiz/mog/Wizroom`, `contrib/bboard/{news_d,exampleboard}`,
  `contrib/transient_effect/drunk`, `domains/std/{Attic,Shop}`**: batch
  sweep shows a bare, textless "Fail to load object". Live `update`
  testing on each: `Attic`/`Shop` were the SAME sword-combat-messages
  bug (§10, now fixed, confirmed "Updated and loaded." on re-test).
  `Wizroom` genuinely fails live too, but with a real, different,
  content-level cause: `*Couldn't find file '/wiz/mog/map' to clone!` --
  this wizard's own decorative wall-map object (matching Grand Hall's
  own "A map of Lima Bean is pinned to the wall." feature, apparently a
  per-wizard-workroom decoration pattern) was never included in this
  archive snapshot; unrelated wizard workrooms have their own map files
  and load fine, so this is one wizard's individually-missing personal
  file, not a systemic gap. `bboard/news_d` genuinely fails live with
  `*Cannot index value of type 'class'` inside its own from-scratch
  `class news_msg` handling -- `contrib/`'s own alternate/older news
  daemon implementation (the ACTIVE `daemons/news_d.lpc` used by
  preload is a different file and loads/works fine, confirmed via the
  clean preload boot log). `tmp_yard`/`tmp_hump`/`tmp_sea_bottom`/
  `tmp_adv_guild`/`exampleboard`/`drunk` show no error either way (live
  `update` prints nothing at all, neither a success nor a failure
  message) -- `tmp_yard`'s own content confirms it's LPscript-compiler
  (`.scr`) generated code (`#pragma no_warnings`, a mechanically-shaped
  `function f = function(function f) {...}` closure body, referencing
  sibling `.scr` files for its own exits/spawns) rather than
  hand-authored `.lpc`, consistent with `update`'s normal-object
  confirmation message simply not applying to however LPScript-compiled
  objects report back. None of this remaining tail blocks the core
  playable path (registration, world entry, `look`/`score`/`inventory`,
  movement, `quit`/reconnect all independently verified live, see §12) --
  logged here per this project's "content bugs: log, don't chase
  further once the reachable/blocking ones are fixed" convention.

## 12. Verification performed (live, real driver via `~/src/fluffos-wilderness`, raw Python `socket` client)

- **check_config.c gate**: driver boots past the LIMA driver-flag
  self-test cleanly with the dedicated worktree; the shared project
  driver and the unrelated `~/src/fluffos-lima` worktree both correctly
  refuse to boot this lib (confirms the two LIMA-lineage snapshots
  genuinely need separate binaries, not a shared one).
- **New player registration, mortal path**: connect -> name (letters-
  only, confirmed via a rejected digit-containing test name: "Sorry,
  that name is forbidden by the implementors... choose a name containing
  only letters.") -> password (typed twice) -> gender -> email -> real
  name -> homepage (blank ok) -> referral source (blank ok) -> 8-attribute
  400-point-budget allocation (30-70 range enforced, confirmed a bounds
  violation is rejected: "Please choose a number that is in bounds.")
  -> size selection (40-60 keraf range) -> a 5-question personality quiz
  (A-E multiple choice, invalid letters rejected: "Please choose a valid
  selection.") -> arrives correctly lit and described in **The Void**
  (`config.h`'s `START` -- `AUTO_WIZ` is `#undef`d in this archive,
  unlike upstream Lima's own demo default, so ordinary characters
  genuinely start as mortals here, not wizards) -> `look` (full room
  text, matches source) -> `score` ("You have earned 0 out of the 40
  points on Wilderness. This gives you the rank of complete and utter
  newbie.") -> `inventory` ("You are empty handed.") -> `quit` ("You
  have left Wilderness.") -> reconnect under the same name/password
  ("You have reconnected.", correct restored HP/Stam and position, "The
  lifeless body of Questor..." from an earlier still-uncleaned test
  character correctly still lying in the room, confirming persistence
  works both for the reconnecting character and for OTHER objects left
  in the world).
- **The Void's only exit -- `enter portal`**: confirmed working, and
  confirmed RANDOMIZED across multiple destinations on repeat testing
  (two separate playthroughs landed in "Branin's Study", full of
  placed weapons including several of the exact swords/sibling weapons
  whose combat-message bug is documented in §10, and "Kesrin's House --
  Front Entryway", a different wizard's home with its own multi-room
  layout) -- matches `Void.lpc`'s own `set_objects()` config listing
  multiple candidate destination workrooms for its portal.
- **Movement**: `north`/`south` between "Kesrin's House -- Front
  Entryway" and "Kesrin's Bedroom" -- correct room transitions both
  directions, "You enter." message, and a direction with no real exit
  (`south` again from the entryway) correctly rejected: "It doesn't
  appear possible to go that way."
- **First-admin bootstrap (`AUTO_WIZ`-independent path)**: a brand-new
  character named `testhero` (test-only, cleaned up afterward) became
  the mud's first `Admin` automatically (`>>>>> You have been made
  admin. Remember to use admtool. <<<<<`), confirming
  `secure/user/sw_body.lpc`'s "no admins yet -> promote the first
  character" bootstrap (the SAME mechanism `libs/lima` documents,
  confirmed working identically in this independent LIMA snapshot) --
  `admtool`/`update <path>` both verified functional under this
  identity (used throughout this session's own triage, see §11).
- **Admin seeding (`fluffos`/`Mud@2026`, this project's standing
  convention)**: `data/secure/access.o`/`access_backup.o` reset to the
  archive's pristine blank slate (`wizards ([])`, `domains["admin"]
  ([])`) after test-character cleanup, then a REAL registration under
  the literal username `fluffos` (letters-only, passes `valid_name()`)
  with password `Mud@2026` -- correctly triggered the SAME first-admin
  bootstrap for real (not a hand-edited save file), confirmed via `who`
  (lists "Fluffos the title-less") and `admtool` (shows the `1 - priv
  1` admin-only menu option). This is the account this project's
  automated re-test tooling should use going forward.
- **Test-data cleanup**: every test character's save pair
  (`data/links/<letter>/<name>.o` + `data/players/<letter>/<name>.o`)
  for `testhero`/`wanderer`/`questor`/`quinnq` deleted after use, per
  this project's `git add -u` / no-test-save-clutter convention; only
  the seeded `fluffos` account's saves are committed. `data/daemons/
  last_login.o`, `data/news/{recent,news_d.o}`, `data/secure/
  {access,access_backup}.o` all diffed against `raw/lib/` and restored
  to pristine content wherever a test session had only touched harmless
  bookkeeping fields (map key order, timestamps) with no real data
  change; a stray empty `data/news/archive/` directory created by
  `news_d` during testing was removed. `work/log/{runtime,catch}` and
  `data/secure/LOG` (this driver's real-time error/debug output,
  confirmed to actually matter here since `debug.log` itself is dead
  for the same CWD-relative-`fopen`-before-chdir reason `libs/lima`'s
  own NOTES.md already documents) cleared before the final commit.
- **`lpcc_check.sh`** (against the dedicated `~/src/fluffos-wilderness`
  lpcc, via the new `LPCC` env-var override): 853/887 pass; the
  remaining 34 are all individually triaged in §11 above (batch-mode
  artifacts, a suspected driver-level struct-name-printing bug in one
  unreachable file, and genuine pre-existing incomplete/dead archive
  content) -- none block the verified-live playable path.

## 13. Not attempted this session

WASM status left `""` (native-only verification per this session's
scope, matching how `libs/lima`'s own WASM pass was deferred as future
work -- a WASM build of this lib would need the SAME
`ARRAY_RESERVED_WORD`-flipped `local_options` change layered onto an
`emcmake cmake --preset wasm` build, analogous to what `libs/lima`'s
NOTES.md already flags as its own outstanding WASM work).

## §10.7 deep functional test (2026-08-31, round two)

Full continuous playthrough on the dedicated `~/src/fluffos-wilderness`
native driver, going well beyond the onboarding pass's registration/
recursion-fix verification above -- specifically to re-confirm the §5
infinite-recursion fix and the §10 sword/exit fixes hold under fresh,
independent exploration, and to exercise systems (economy, real
combat, quit/reconnect, a long-sit boot watch) the onboarding pass
didn't reach. Used the seeded `fluffos`/`Mud@2026` admin account for
exploration/instrumentation, plus a fresh throwaway mortal
registration (`Questorwild`/`Test12345`, real male human, 50/50/.../50
attribute spread, deleted after use per this project's no-test-clutter
convention) to independently re-verify the mortal registration and
restore paths on an account other than the onboarding session's own.

### Bug found and fixed: `domains/std/rooms/beach/Outside_Cave.lpc`'s `object_arrived` hook destructed the PLAYER'S OWN BODY on ordinary entry -- new AGENTS.md §7.189

Found via ordinary exploration, no combat or edge-case input involved:
`goto`-ing (or simply walking, confirmed both ways) from the connected,
portal-reachable `Grotto` room `out` into `Outside_Cave` destructed the
player's own body object mid-move, 100% reproducible. The visible
symptom was severe and immediate -- the room's own flavor text
("Fluffos sinks into the surf, and you quickly lose track of it in the
violent crashing waves.") printed as if describing the PLAYER
themselves, followed by a cascade of driver errors (`*Bad argument 1
to EFUN call_other() ... Got: int(0)`, `*Bad argument 1 to
environment() ... Got: 0`, `*Parse accepted, but no do_* function
found`) and a fully dead connection (`Can't use verb with no body.` on
every subsequent command) until reconnecting. Root-caused via
`log/runtime`'s stack trace to `std/modules/m_smartmove.lpc:170`
(`environment()->call_hooks("person_arrived", ...)` returning 0 right
after a successful move) plus a direct read of
`Outside_Cave.lpc`'s own `obj_arrived()`: it checked `ob->get_size() >=
VERY_LARGE` to pick between a "large splash" and a "sinks into the
surf" message, but only the VERY_LARGE branch checked `is_living()`
before deciding whether to destruct at all -- the small-object branch
(what every ordinary humanoid player or NPC entering the room hits)
unconditionally printed the sinks-into-the-surf message and called
`destruct(ob)` with **no living/vehicle check whatsoever**. Confirmed
this is a `wilderness`-specific regression, not an inherent Lima-
lineage bug: the sibling `domains/std/Lava_Room.lpc` in this SAME
codebase implements the identical "destruct small non-living arrivals"
idiom correctly (`if ( !o->is_living() && !o->is_vehicle() )` before
its own `destruct()`), and BOTH `libs/lima`'s modern fork AND
`libs/spacemud`'s independent archive ship their own copies of this
exact `Outside_Cave.lpc` file with the correct `if (!ob->is_living())`
guard already present -- three of four known copies have the guard,
strong evidence the fourth (this one) genuinely lost it rather than
never having it. Fixed by adding the missing guard (see AGENTS.md
§7.189 for the full writeup and general lesson); verified live,
before/after: pre-fix, `out` from `Grotto` crashes the connection
every time; post-fix, `out` correctly shows "You enter." + the room
description, and `north` back into `Grotto` immediately afterward
confirms the round trip and the player's body survive intact. The
connection always recovered on reconnect (only the in-memory body was
destroyed, not the save file), so this was "only" a forced-disconnect
crash rather than true permadeath, but it was a 100%-reproducible
crash on an entirely ordinary two-hops-from-the-portal exploration
path.

### Bug found and fixed: `daemons/messages_d.lpc`'s unarmed "graze" combat message baked a hardcoded `-s` into the verb token, breaking this codebase's own `$v` conjugation contract in both directions

`"unarmed"`'s `"none"` (near-miss/graze) tier read `"$N $vgrazes to $t
with $p fist."` -- note `$vgrazes`, not `$vgraze` -- while every
sibling weapon category's identical tier (`"edged"`, `"blunt"`,
`"piercing"`) correctly used `$vgraze`. Root-caused by reading
`std/modules/m_messages.lpc`'s `$v` handler: for the second-person
subject ("you"), it uses the verb token verbatim (so a token that
already ends in `-s` prints wrong for "you" -- confirmed live,
`"You grazes to Bill the Troll with your fist."`); for a third-person
subject, it calls `M_GRAMMAR->pluralize(str)` to append the `-s`
itself, so a token that ALREADY has one gets doubled --
confirmed with an isolated instrumented test,
`M_GRAMMAR->pluralize("grazes")` returns `"grazesses"` (efun
`pluralize()`'s real "ends in s -> add -es" rule firing on an
already-conjugated word). So the bug was wrong for BOTH grammatical
persons, not just cosmetically wrong for one. Fixed by dropping the
baked-in `-s`, matching the three sibling categories: `"$N $vgraze $t
with $p fist."`. Verified live (a fresh player-body instance was
needed since `set_combat_messages()` caches `MESSAGES_D->get_messages()`
once per object at `setup()` time, so an already-loaded body doesn't
pick up a live `update` to `messages_d.lpc` until it reconnects):
post-fix, the exact same fight now correctly shows "You graze Bill the
Troll with your fist." Narrow enough (one file, a single message
string, no corpus-wide grep hits for the same `$v<word>s` doubled-verb
shape) that it doesn't warrant its own AGENTS.md entry.

### What was tested and confirmed working

- **Fresh mortal registration, independent of the onboarding session's
  own test characters**: full flow (name confirm -> password (twice)
  -> gender -> email -> real name -> homepage -> 5-question personality
  quiz -> 8-attribute 400-point budget -> size) for `Questorwild`,
  landing correctly in `The Void` with 25/25 HP (NOT auto-promoted to
  admin, confirming the first-character-only bootstrap correctly stays
  off for a second/later character) -> `enter portal` -> landed in
  `Branin's Study`, surrounded by 6 different sword/dagger/mace/
  zweihander weapons with zero crash (independently re-confirms the
  §10 `set_combat_messages("combat-sword")`/`m_exit.lpc` guard fixes
  hold for a brand-new account, not just the ones onboarding tested).
- **Shop/economy, a full two-sided transaction**: `domains/std/Shop`
  (Biff the Shopkeeper, reached via admin `goto`) -- `list` shows a
  red apple (1 copper) and a rusty sword (1 electrum 5 copper); cloned
  a sword, `sell sword to biff` correctly paid 1 electrum; `buy apple`
  correctly charged 1 copper and made change (9 copper back); a second
  `buy sword` correctly refused for insufficient funds. Full
  sell-then-buy-with-correct-change loop verified, not just a
  read-only `list`.
  `ask biff about swords` returned "Nothing in this shop matches that!"
  -- `M_VENDOR`'s "ask" handling appears to only match the room's own
  authored `add_item("sign", ...)` topics, not a shopkeeper's own stock
  by name; not chased further since `list`/`buy`/`sell` are the shop's
  real, documented interface (the sign's own text says exactly that)
  and all three work correctly -- flagging as an observation, not
  fixing, since it's unclear whether `ask about <item>` was ever meant
  to be wired to vendor stock at all.
- **Real combat** (this lib has no dedicated safe-sparring
  dummy/mechanism -- grepped for the `accept_fight` pattern documented
  in AGENTS.md as the thing to look for and found zero hits anywhere
  in the tree, confirmed honestly rather than assuming one exists):
  used `domains/std/rooms/caves/Grotto`'s placed `Bill the Troll`
  (`max_health` 30, a genuinely weak, deliberately-reachable "starter
  monster" per its own file, fought at full admin HP as the safest
  available substitute) -- full fight with both hit/miss/graze
  messages and off-balance/clumsy-swipe flavor text all rendering
  correctly (post-fix). Did not press the fight to a kill (admin
  landed zero solid unarmed hits in ~130 rounds -- low unarmed skill
  by design, not a bug) since the immediate priority once combat was
  confirmed working was root-causing the `Outside_Cave` crash above;
  the corpse-decay/insect-scavenging flavor system was independently
  observed working correctly on an unrelated NPC corpse during the
  same fight.
- **`quit`, `debug.log`(`log/execute`)/`log/runtime` grep, reconnect
  after a real gap** -- multiple passes: (1) admin same-session
  reconnects across 4 separate tmux sessions while iterating on the
  two bugs above, full state preserved every time including HP/
  inventory-affecting actions (heal, clone, sell, buy); (2) the fresh
  mortal `Questorwild` registered, played through to `Branin's Study`,
  `quit`, then reconnected after the driver had been fully restarted
  (picking up both fixes) -- correct password prompt, full state
  restored (`Branin's Study`, 25/25 HP, 100/100 Stam) confirming the
  restore path independently of the onboarding session's own accounts.
- **Long-sit boot watch (native-driver equivalent of §10.0, no WASM
  build exists for this lib)**: killed and rebooted the driver fresh
  with both fixes applied, opened one idle raw-socket connection at
  the login-name prompt (never logging in), and sat through a full
  ~225-second window. Zero growth in `log/execute` (the debug-log
  equivalent for this driver -- see §0's config note; confirmed
  working correctly for a properly-launched-from-`libs/wilderness/`
  driver, unlike the CWD-relative-fopen concern flagged for other
  launch methods) and zero new entries in `log/runtime` beyond the
  pre-fix crash artifacts from earlier in this same session -- no
  lazily-triggered daemon failures surfaced during the idle window.
- **Death/respawn**: **not verified live this pass** -- time-budgeted
  out in favor of root-causing and fixing the `Outside_Cave` crash
  (judged higher-value: a severe, 100%-reproducible crash on an
  ordinary path clearly outweighs a code-reviewed-only death sequence
  for this session's available time). `std/adversary/health/
  hit_points.lpc`'s `reincarnate()` (`if(health < 1) health = 1;`) and
  the death/ghost machinery referenced throughout this codebase were
  read but not live-triggered. Flagging honestly as unverified rather
  than silently skipping it.
- **Skill/guild acquisition**: **no reachable guild exists in this
  archive's explorable world** -- grepped for `inherit.*M_GUILD_MASTER`
  and found exactly one hit, `domains/std/monsters/fighter_master2.lpc`,
  which is referenced only from a wizard-facing HELP file
  (`help/wizard/coding/guilds/guild_d`), never `set_objects()`'d into
  any actual room anywhere in the tree -- i.e. it's example/template
  content for wizards building their OWN guild, not a preloaded,
  reachable NPC. `std/body/guilds.lpc`'s full `add_guild`/`revoke_guild`/
  `suspend_guild` API is real and functional (a wizard-facing coding
  primitive), but there is no organic OR admin-shortcut in-game path to
  actually join a guild as an ordinary player in this snapshot.
  Documented honestly per this project's "don't guess at a shortcut
  that doesn't exist" precedent (matching `pd`'s own round-two
  writeup) rather than fabricating a test that isn't possible here.

WASM status unchanged from §13 above (native-only this pass too, same
`ARRAY_RESERVED_WORD` flag blocker as a WASM build would need).

## WASM measurement (2026-09-03): still noboot on every existing WASM binary

`meta.json` was flipped to `playable` on 2026-08-31 (`2ec643a7c45`) to
unblock the Pages deploy pipeline -- that commit equated a native
§10.7 pass with WASM playability. Measured this session against both
binaries the site can actually serve:

- Shared `~/src/fluffos/build-wasm`: `check_config` fails the full
  LIMA list (`NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS`/`OLD_ED`/
  `ARRAY_RESERVED_WORD`/`PACKAGE_UIDS`).
- Lima-flavor `~/src/fluffos-lima/build-wasm` (the
  `scripts/custom_drivers/lima_swmud/` binary, which now also serves
  `spacemud`): only remaining miss is `#define ARRAY_RESERVED_WORD`.

So the live play page, if packed with the shared driver, cannot boot.

That gap is now closed in the same session: `~/src/fluffos-wilderness`
got an `emcmake cmake --preset wasm -DPACKAGE_UIDS=OFF` build, the
artifacts live in `scripts/custom_drivers/wilderness/`, and
`build_site.sh` maps the slug there. One mudlib-side compile fix was
required -- the same lima §1.3(c) `dump_socket_status()` /
`socket_status()` eager-simul_efun hole -- guarded with
`#ifdef __PACKAGE_SOCKETS__` in `secure/simul_efun/misc.lpc`.
`/obj/secure/socket.lpc` still fails to compile during the `rcp_d`
preload (no `sockets` package); same graceful skip as lima/spacemud,
not on the login path.

Verified with `scripts/wasm_client.js` against
`~/src/fluffos-wilderness/build-wasm/src`: `fluffos` / `Mud@2026` →
Grand Hall → `look` → `score` ("You are an implementor.") → `quit`
("You have left Wilderness."). `wasm_status` is `playable` again,
now actually true for the browser. Native play on
`~/src/fluffos-wilderness` is unchanged.
