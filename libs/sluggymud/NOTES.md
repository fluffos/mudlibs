# SluggyMUD -- porting notes

Source: `git clone https://github.com/Sluggy/SluggyMUD` (commit
`bad0123cd9dc32e0576e6a9c992c003702a64449`, single commit dated
2013-01-17, cloned 2026-08-28). Slug `sluggymud`, number 948, port
40250. Only checked for collisions against `scripts/lib_numbering.json`
and existing `config.fluffos` ports before assigning -- none found.

The repo's own (two-line) README: "A component-based mudlib designed to
run on the FluffOS LPC driver." -- one of the strongest a-priori
compatibility signals found this session, since it explicitly targets
FluffOS rather than a generic MudOS/LDMud archive. 1,016 files, 199
`.c` files, root at `lib/{core,public,secure}` (the archive's actual
shape, not the `core/{cfg,cmds,...}` flat-under-repo-root guess from
the initial discovery pass -- the mudlib root is `lib/`, one level
down, confirmed via `lib/core/lib/master/master.c` and
`lib/core/cfg/mudos.cfg`'s own `master file : /core/lib/master/master`
/ `mudlib directory : lib`).

## 1. Conversion

Pure ASCII/English source -- `convert_lib.sh` reported
`already_utf8=923 converted=0 lossy=0 skipped_binary=4` (no re-encoding
needed at all). Renamed 199 `.c` -> `.lpc`, fixed 25 literal `.c"`
references, converted 1 local angle-bracket `#include` to quotes, ran
the `static`->`nosave` sweep across 7 files with zero collisions. A
tree-wide `find ... file -b` straggler sweep after conversion found
nothing left over. No symlinks, no nested nonstandard extensions.

## 2. What this archive actually is

This is a **bare engine skeleton**, not a game with content -- and this
is the archive's own genuine, intentional scope (per §2.3's `imud`
precedent), not a conversion gap. Confirmed by direct inspection, not
assumption:

- `public/domains/`, `public/lib/{component,obj,daemon,single}`,
  `secure/lib/{component,obj,daemon,single}`, `core/lib/component/`,
  `core/cmds/`, `secure/cmds/` all contain nothing but a placeholder
  `fert.txt` (or a `README` describing the directory's intended future
  contents) -- zero rooms, zero NPCs, zero items, zero combat, zero
  account/login system.
- `core/lib/obj/login.lpc`'s `logon()` has its own comment "needs fixed
  to handle passwords" and unconditionally creates an anonymous
  `"stuf" + oid` identity with no name/password prompt at all --
  registration as this project usually defines it (§2's "definition of
  done") does not apply here, exactly like `imud`.
- `core/lib/obj/user.lpc`'s own `logon()` comment says "move this to
  /single/login.c when login.c gets written" -- the author's own
  acknowledgment that the login/account layer was unfinished.
- There is no environment/room system: `core/lib/single/void.lpc` (the
  landing spot every connection is moved to) is a one-line `dummy()`
  stub, and no `look`/`score`/`inventory` command exists anywhere in
  the tree.

What IS real and working: a genuine MudOS/FluffOS-style
`master.lpc`/`valid.lpc` (get_root_uid/get_bb_uid/creator_file/
domain_file/author_file/valid_read/valid_write/valid_override, all
present and permissive), a real `simul_efun.lpc`
(`same`/`cat`/`getoid`/`dump_variable`/`resolve_path`/
`mudlib_name`/`mudlib_ver`), a small set of real dev/admin commands
(`who`, `say`, `quit`, `ed`, `eval`, `codefor`, `rm`, `update`, `dest`,
`shutdown`, plus the hidden, non-advertised `speed` benchmark and
`tests` self-test runner), and -- once repaired, see below -- a
genuinely substantial ~113-file compiler/efun self-test suite under
`core/sefun/tests/`. Given the thin surface, this project's usual
"definition of done" (real name registration, look/score/quit) doesn't
mechanically apply, exactly as documented for `imud`; the bar used here
instead was "every implemented command produces correct output",
verified live below.

## 3. `config.fluffos`

Adapted directly from the archive's own `lib/core/cfg/mudos.cfg` (a
real MudOS v21 config). Two changes beyond the standard port/mudlib-dir
substitution:

- `log directory` was `/public/log` (mudlib-relative) in the original;
  changed to `/log` (driver-launch-CWD-relative, AGENTS.md §5.2) so
  `debug.log` actually gets written when launched the project's
  standard way (`cd libs/sluggymud && driver config.fluffos`). This is
  unrelated to the mudlib's OWN internal `PUBLIC_LOG_DIR`-based
  `write_file()` calls (`globals.h`'s `PUBLIC_LOG_DIR` etc.), which
  stay mudlib-relative and untouched.
- Removed two now-obsolete config keys the driver warned about on
  first boot: `reserved size` and `swap file`.

## 4. Bugs found and fixed (all pre-existing in the 2013 archive, none
   FluffOS-version-specific)

All found via `scripts/lpcc_check.sh` (initial: 43/199 compiled) and
confirmed live via a real driver boot + `mudclient.py` playthrough --
none of these are "design", all have a hard compile or runtime error
signature.

### 4a. `config.h`'s "global include file" never actually included anything

`core/include/config.h` is wired up as the driver's `global include
file` (auto-`#include`d into every compiled object per `mudos.cfg`'s
own comment: "this header file is automatically #include'd by all
objects"). It only did:

```lpc
#define GLOBAL_H "/secure/include/globals.h"
```

Two bugs stacked here: (1) the path is wrong -- the real header lives
at `/core/include/globals.h`; `secure/include/` holds only a
placeholder `README`/`fert.txt` -- and (2) even if the path were right,
defining a macro that names a file is not the same as `#include`-ing
it; nothing anywhere expanded `GLOBAL_H`. Net effect: every file that
didn't have its own explicit `#include <globals.h>` (most of the
`core/sefun/tests/` self-test suite, plus 3 real command files, see
4b/4c) compiled with zero access to the archive's own constants and
directory macros. Fixed by making `config.h` really
`#include <globals.h>`.

### 4b. Three real command files missing `#include <globals.h>`

`public/cmds/eval.lpc`, `public/cmds/codefor.lpc`, and
`public/cmds/speed.lpc` all reference macros from `globals.h`
(`TMP_EVAL_FILE`, `CODE_TMP_FILE`, `INH_OBJ`) with no `#include` of
their own -- before fix 4a, this meant "Undefined variable"/syntax
errors (`speed.lpc`'s bare `inherit INH_OBJ;` with `INH_OBJ` undefined
parses as a syntax error, not just an undefined-symbol warning). Fix
4a alone resolves these three now that the global auto-include chain
actually works; `#include <globals.h>` was also added explicitly to
`eval.lpc`/`codefor.lpc` (matching every other `#include`-conscious
command file in the tree) for clarity/robustness against a future
`config.fluffos` that drops the global-include-file setting.

### 4c. `eval.lpc`: `find_object()` called with zero arguments

```lpc
if (find_object(TMP_EVAL_FILE))
destruct(find_object());   // <-- should be find_object(TMP_EVAL_FILE)
```

This driver's `find_object()` requires its argument (no "current
object" default the way some very old MudOS/LPmud dialects allowed) --
every real invocation of the advertised `eval` command threw `*No
program in object '/public/cmds/eval'!` (the compile failure) at
runtime, since the whole file failed to load. Fixed to pass the
filename.

### 4d. `tests.h` genuinely exists but its `#include` was left commented out

The entire `core/sefun/tests/` self-test suite (~113 individual efun
tests plus `tests.lpc`'s own fixture-runner) calls
`ASSERT`/`ASSERT2`/`SAVETP`/`RESTORETP`. These are NOT missing from the
archive -- `core/include/tests.h` genuinely ships this exact macro set
(byte-for-byte the same shape as FluffOS's own current
`testsuite/include/tests.h`, confirming a shared lineage/ancestor, but
this archive's own copy is the simpler original: plain `error()`-based
assertions with no `master.lpc`-application dependency
(`clear_last_error`/`record_failure`) at all) -- but `globals.h`'s own
`//#include "tests.h"` was left commented out, so every one of these
~113 files failed to compile with "Undefined function ASSERT[2]" /
"Undefined variable SAVETP", which would have made
`tests`/`codefor`-adjacent dev tooling entirely non-functional. **Fix
was a one-line uncomment**, not a reconstruction -- an earlier pass of
this port mistakenly assumed `tests.h` was altogether absent (having
only grepped for the commented `#include`, not the file itself) and
hand-wrote replacement macros; those were discarded in favor of
restoring the archive's own real header once found, since the two
turned out to differ in a load-bearing way (see below).

```lpc
#define ASSERT(x) if (!(x)) { error(file_name() + ": Check failed.\n"); }
#define ASSERT2(x, r) if (!(x)) { error(file_name() + ":" + r + ", Check failed.\n"); }
#define SAVETP tp = this_player()
#define RESTORETP { if (tp) evaluate(bind( (: enable_commands :), tp)); else { object youd_never_use_this_as_a_var = new(VOID_OBJ); evaluate(bind( (: enable_commands :), youd_never_use_this_as_a_var)); destruct(youd_never_use_this_as_a_var); } }
```

Confirmed live that this driver's `bind()`/`evaluate()`/closures work
correctly for `RESTORETP`'s use (`SAVETP`/`RESTORETP` bracket an
`enable_commands()`/`set_living_name()` probe in 8 tests --
`add_action`, `remove_action`, `set_living_name`, `find_living`,
`find_player`, `query_verb`, `say` -- ran
`tests /core/sefun/tests/efuns/add_action` live with zero errors in
`debug.log`). The load-bearing difference from a `write()`-based
reconstruction: `ASSERT`/`ASSERT2` call the real `error()` efun on
failure, which -- correctly, by the suite's own design -- throws and
unwinds the current call, rather than printing a message and silently
continuing. See §5's `missing_type.lpc` finding for why that
distinction matters in practice.

### 4e. Stale pre-refactor absolute paths in 4 self-test files

`core/sefun/tests/efuns/inh1.lpc`/`inh2.lpc` used
`inherit "/single/tests/efuns/inh0.lpc"` / `"...inh1.lpc"`, and
`to_float.lpc`/`sscanf.lpc` used `inherit "/inherit/tests"` -- both
referencing a flat top-level `/single/`, `/inherit/` layout from
*before* this archive's own `core`/`public`/`secure` reorganization
(confirmed by `speed.lpc`'s own dead `"/command/speed"->lfun0()`
call-site comment using the same old flat convention). The real paths
today are `/core/sefun/tests/efuns/inh0.lpc` and
`/core/lib/inherit/tests` respectively. This refactor was evidently
never fully swept across the self-test tree. Fixed all 4 `inherit`
lines to the current real paths.

### 4f. `SEFUNTESTS_DIR` macro missing its trailing slash

```lpc
#define SEFUNTESTS_DIR        SEFUNS_DIR"/tests"   // no trailing "/"
```

`public/cmds/tests.lpc`'s `recurse(dir)` always concatenates
`dir + <name>` assuming `dir` already ends in `/` (e.g.
`dir + "*.lpc"`, `recurse(dir + subdir + "/")`). Without the trailing
slash, `recurse(SEFUNTESTS_DIR)`'s very first `get_dir(dir + "*.lpc")`
resolves against a squashed, off-by-one-component path
(`"/core/sefun/tests*.lpc"` instead of `"/core/sefun/tests/*.lpc"`),
and any deeper recursion resolves an entirely nonexistent directory
(e.g. `"/core/sefun/testscompiler/"`) -- `get_dir()` on a genuinely
nonexistent directory returns `0` rather than an empty array, and the
very first `foreach` over that result crashed every real invocation of
the bare `tests` command with `*Bad argument 2 to foreach / Expected:
array Got: 0`. Fixed by adding the trailing slash to the macro.

### 4g. `codefor.lpc`'s disassembly marker never matches this driver's `dump_prog()` output

```lpc
code = explode(code, ";;;  *** Disassembly ***\n");
code = code[1];   // Array index out of bounds -- explode() only ever
                   // returns a 1-element array against real output
```

Confirmed live (temporarily dumped the raw `dump_prog()` output to the
socket) that this FluffOS build's actual disassembly section header is
`"DISASSEMBLY:\n"`, not the archive's `";;;  *** Disassembly ***\n"` --
so `codefor` (a hidden debug command that compiles an arbitrary
expression via the same `eval`-file trick and prints its disassembly)
threw an uncaught array-bounds error on every real invocation before
this fix. Fixed the split marker to match; `codefor` now correctly
prints just the bytecode listing.

### 4h. `tests.lpc`'s top-level `.lpc` walk not resilient to one driver-incompatible fixture

`core/sefun/tests/compiler/succeed.lpc` deliberately exercises ANSI-C
`##` token pasting (`int paste = X1##X2;`) as a "this should compile"
positive test -- but this driver's LPC preprocessor has never
implemented `##` token pasting at all (`Illegal character '#'`), a
genuine, permanent driver-feature gap, not a regression to patch
around (compare `speed.lpc`'s own dead comment: "Evidentally, 3.2
doesn't have token pasting"). Before this fix, `recurse()`'s
unconditional `main(dir + file)` over every `.lpc` under
`core/sefun/tests/` meant a bare `tests` (no argument) run aborted
completely the moment it reached this one file (`fun->do_tests()` on
an object with "No program" since it never compiled), silently
skipping every other test file still queued after it alphabetically.
Wrapped the recursive `main()` call in `catch()` so one
driver-incompatible fixture reports and moves on instead of aborting
the whole walk -- the direct, explicit `tests <path>` invocation form
(main's other branch) is intentionally left un-caught, since a user
who names a specific test by hand should see its real error.

## 5. Verified live (real driver + `mudclient.py`/raw sockets, not just
   `lpcc_check.sh`)

- Clean boot: "Initializations complete", listening on 40250, no
  preload list configured (`secure/cfg/preload` doesn't exist in this
  archive -- `epilog()`'s `update_file()` degrades to `({})` cleanly,
  not a crash).
- Connect -> anonymous `logon()` -> `who` shows the connecting
  identity (`stuf<oid>`).
- `say <text>` -- correctly silent to the speaker (real `say()` efun
  semantics: broadcasts to the room, never echoes to
  `this_player()`) -- not a bug.
- `eval <expr>` -- compiles and runs an arbitrary expression, prints
  `Result = ...`.
- `codefor <expr>` -- prints the real bytecode disassembly (after 4g).
- `dest <path>` -- correctly reports "can't find that." for a
  nonexistent object.
- `update <path>` -- silently destructs+reloads (no confirmation text
  coded -- silence is success, matches `rm`'s own silent-efun
  contract).
- `rm <path>` -- silently removes a file.
- `ed <path>` -- enters the line editor (":" prompt) even for a
  not-yet-existing file, `q` exits cleanly.
- `tests <specific-test-path>` -- silent on success (the `ASSERT`
  macros only ever print on FAILURE, by design -- ran
  `/core/sefun/tests/efuns/sizeof` clean).
- `tests` (bare, full recursive self-test walk) -- after fixes 4a, 4d,
  4f, and 4h, walks into `core/sefun/tests/compiler/` and correctly
  discovers
  one genuine, interesting compiler-behavior difference:
  `compiler/fail/missing_type.lpc` (a "this should fail to compile"
  fixture) actually compiles successfully on this FluffOS build. Since
  `tests.h`'s real `ASSERT2` calls `error()` on a failed check (§4d) --
  by design, so a real regression is never silently swallowed -- this
  throws an uncaught error right there (the `fail/` directory's
  `ASSERT2(catch(load_object(...)), ...)` loop has no `catch()` of its
  own, unlike the unrelated `main(dir+file)` walk fixed in 4h), which
  unwinds all the way up through every `recurse()` frame and ends the
  whole bare `tests` command with a loud, visible error --
  `fail/missing_type.lpc loaded, Check failed.` -- instead of
  completing the rest of the tree (`compiler/succeed`,
  `compiler/constant_expr`, `compiler/at_block`, the ~113 `efuns/*`,
  `operators/*`). **This is the self-test framework working exactly as
  designed** (loudly stop on a real, unexpected assertion failure) and
  was intentionally NOT further patched with more `catch()`s -- doing
  so would suppress the very signal the suite exists to surface. Use
  `tests <specific-path>` (see above) to exercise any file past this
  point in the tree.

## 6. Known pre-existing content gap, left undocumented-fixed on purpose

`core/etc/motd` (the login banner) advertises: "The only commands in
this little mudlib are: dest, update, ed, eval, efun, rm, say, who,
quit, and shutdown." -- but no `efun` command exists anywhere in
`core/cmds/`, `public/cmds/`, or `secure/cmds/` (only a
`core/sefun/tests/efuns/` *test* directory and `public/doc/efun/`
*documentation* pages share the name). Invoking `efun <anything>`
falls through to the driver's generic "Beg your pardon?" fail message.
This is present in the archive's very first (and only) upstream commit
from 2013 -- genuine pre-existing content drift (a command the author
apparently planned, mentioned in the banner, and never got around to
implementing), not something introduced by this conversion. Per this
project's driver-bugs-only scope, documented here rather than invented
from scratch (there's no way to recover what the author intended
`efun` to do beyond guessing from its name -- plausibly a single raw
efun-call debug command alongside `eval`'s whole-expression version).

## 7. No outbound network side effects

No `socket_create`/`socket_connect`/`resolve()`/DNS/intermud code
anywhere in the real (non-doc) tree -- safe for routine automated
re-boot loops, unlike `imud`/`foundation1`/`foundation2`/`ninetears`.

## 8. WASM

Not yet attempted this session -- native driver boot/play verified
only. No known WASM-blocking pattern identified during this pass (no
`sockets`-package dependency, no `query_ip_number()`-adjacent login
gate given there's no login/ban system at all).

## 9. §10.7 deep functional test (2026-08-31) -- verified clean, plus WASM closed out

Definition of done for this lib, per its own §2/§5 precedent (a bare
engine skeleton with no game content): every implemented dev command
still produces correct output, exercised again end to end on the
native driver in one continuous session -- `who`, `say` (correctly
silent to the speaker), `eval` (`return 1+1;` -> `Result = 2`),
`codefor` (`return 3+3;` -> correct constant-folded disassembly,
`byte 6` / `return`), `dest` (correctly reports "can't find that." for
a nonexistent path), `update /public/cmds/who` (silent success,
`who` still works immediately afterward -- confirms the reload is
real, not just a silent no-op), `ed` (created a new file, wrote a
line, saved, exited cleanly -- confirmed the file's actual byte count
matched), `rm` (confirmed the file was actually gone from disk
afterward), `tests /core/sefun/tests/efuns/sizeof` (silent success),
the bare recursive `tests` walk (reproduced the exact same two
already-documented, expected stopping points from §4h/§5 -- the `##`
token-pasting gap in `compiler/succeed.lpc` caught and reported
without aborting the walk, then the intentional `Check failed.` in
`compiler/fail/missing_type.lpc` correctly halting the whole run by
the suite's own design), and `quit` (`Bye.`, clean disconnect). Zero
new findings -- every fix from §4 still holds, no regression.

**WASM, closed out this session** (§8's own "not yet attempted" note):
`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/sluggymud --send "who" --send "eval return 5+5;" --send "quit"`
-- identical correct output to native (`Result = 10`, clean `Bye.`).
Also ran `scripts/wasm_boot_watch.sh sluggymud 200`, a 200-second
long-sit with one connection open the whole time to catch any
lazily-triggered daemon failure a short smoke test would miss --
clean, no new failure signatures beyond the already-known cosmetic
`Unable to open log file` line. `wasm_status: playable`.

Zero errors in the driver's own captured stdout across the whole
native session (this build's `debug.log` is dead for the process's
whole life per AGENTS.md §10.9, so stdout is the only reliable error
channel) beyond the intentional, by-design compiler-fixture errors
from the `fail/*.lpc` test files themselves (each one IS a "this
should fail to compile" fixture; the compiler correctly rejecting
them is the test passing, not a bug).

## 10. §10.7 deep functional test, round two (2026-09-01) -- new angle:
    adversarial `eval`, `ed`/`update`/`rm` edge cases, and (the real
    find) bypassing the two known `tests` stopping points to finally
    exercise the ~113-file `efuns/`/`operators/` subtrees that no prior
    pass had ever reached

Genuinely different angles from §9 (which only tried trivial happy-path
`eval return 1+1;` and single-file `tests <path>` runs):

- **Adversarial `eval`**: division by zero, a call to an undefined
  function, deliberate syntax errors, out-of-bounds array indexing, an
  infinite `while(1){}` loop. All five correctly produce a compile-time
  or `eval_cost`-limit error caught by the driver -- `Divide by zero in
  constant`, `Undefined function ...`, `syntax error`, `Illegal index
  to array constant`, `*Too long evaluation. Execution aborted.` -- and
  the driver stayed fully responsive afterward every time (`who` kept
  working). Array/mapping literals, string concat, `sizeof()` all
  eval'd correctly. Not a bug: `eval.lpc`'s generic "*No program in
  object" player-facing message on any compile failure is the expected
  behavior of this bare, uncaught `TMP_EVAL_FILE->eval()` debug command.
- **`ed` edge cases**: editing an *existing* file (`$a` append, correct
  new line/byte count, correct saved content) and a hard socket
  disconnect *mid-edit*, after entering insert mode and typing a line
  but before `.`/`w`/`q` -- confirmed the on-disk file was **completely
  unchanged** (matching md5sum) and the driver logged nothing and
  stayed healthy. Clean on both counts.
- **`update`/`rm`/`dest` edge cases**: `update` on a file with a real
  syntax error reports a normal caught compile error (no crash);
  `update`/`rm` on a nonexistent file is silently a no-op (no crash);
  `rm` on a directory path does nothing (directory survives); `dest`
  on a real, currently-in-use command object (`/public/cmds/who`)
  correctly destructs just that instance, and the next `who` invocation
  transparently recompiles and works. All clean.
- **Two-connection concurrent `eval`**: both connections got their own
  correct, independent result despite both invocations using the exact
  same shared `TMP_EVAL_FILE` path -- expected, since this driver's
  single-threaded command-execution model means two telnet commands
  from different connections never actually execute concurrently at
  the interpreter level (no `call_out`/`sleep` in `eval.lpc` to yield
  mid-command). Rapid-fire same-connection `eval`/`who` repeats: clean.

**The real finding -- getting past the two known `tests` stopping
points**: §9 reproduced the same two already-documented halts
(`compiler/succeed.lpc`'s `##`-pasting gap, then the uncaught
`compiler/fail/missing_type.lpc` assertion failure that aborts the
*entire* bare `tests` walk). Directly invoking `tests.lpc`'s own
`recurse()` function via `eval` on the `efuns/` and `operators/`
subdirectories individually (bypassing the `compiler/` subtree
entirely, e.g. `eval "/public/cmds/tests"->recurse("/core/sefun/tests/efuns/");`)
reached ~113 fixture files that **no previous pass -- onboarding or
round one -- had ever actually executed**, because the bare `tests`
command dies in `compiler/` (alphabetically first) before it ever
reaches `efuns/`/`operators/` at all. `operators/` runs 100% clean
(zero failures, only a harmless deprecated-range-syntax compile
warning). `efuns/` surfaced **12 failures**, all individually
root-caused below:

**8 were the same stale-pre-refactor-absolute-path bug class as §4e,
just not exhaustively swept the first time** -- `grep -rl '"/single/'`
across `core/sefun/tests/` found 9 files still referencing the old
flat pre-`core`/`public`/`secure` layout (`/single/...` instead of
`/core/lib/single/...`, `/core/sefun/tests/efuns/...`, etc.); 7 of
these actually manifested as live failures and 1 more (`set_light.lpc`)
had the same stale-path defect masking a *separate*, pre-existing
fixture bug (see below). Fixed by point-correcting each stale literal
path to its real current location, matching §4e's exact fix style
(direct corrected literal, no new macros, except `VOID_OBJ` which
already exists in `globals.h` and is the established convention
used by `login.lpc`/`master.lpc`/`tests.h` for exactly this object):

  | File | Bad path | Fix |
  |---|---|---|
  | `efuns/cp.lpc` (:6,:8) | `/single/master.lpc` | `/core/lib/master/master.lpc` |
  | `efuns/deep_inherit_list.lpc` (:5,7,8) | `/single/tests/efuns/inh{0,1,2}.lpc` | `/core/sefun/tests/efuns/inh{0,1,2}.lpc` |
  | `efuns/inherit_list.lpc` (:4,6) | same | same |
  | `efuns/inherits.lpc` (:1-3, `#define`s) | same | same |
  | `efuns/find_object.lpc` (:5,8,9,10,12,13) | `/single/tests/efuns/unloaded` | `/core/sefun/tests/efuns/unloaded` |
  | `efuns/rename.lpc` (:6,8,9) | `rename(..., "/single")` (a *directory* rename target that no longer exists) | `rename(..., "/core/lib/single")` |
  | `efuns/say.lpc` (:28) | `new("/single/void")` | `new(VOID_OBJ)` |
  | `efuns/set_light.lpc` (:7) | `new("/single/void")` | `new(VOID_OBJ)` |

  `efuns/call_other.lpc` also references a stale `"/single/master"`
  (:25) but this one currently does **not** actually manifest as an
  observed failure (the call incidentally still behaves as the test
  expects even against the wrong path) -- left untouched per this
  project's evidence-only-fix rule, but flagged here for anyone doing
  a future sweep.

  **Confirmed live evidence of real, silent damage from this bug
  class**: before the fix, running `efuns/rename.lpc` actually
  **created a stray top-level file literally named `single`**
  (containing "Hmm.") at the mudlib root, because `rename("/ren_test",
  "/single")` silently renamed-to a nonexistent-directory target
  instead of erroring. Caught and removed (`git status` confirmed it
  was untracked, not part of the archive) before committing -- this is
  exactly the kind of quiet on-disk pollution the stale-path bug class
  can cause beyond just failing an `ASSERT`.

  Verified live post-fix: all 7 previously-failing files above now
  pass silently via direct `tests <path>`; re-running the full
  `efuns/` `recurse()` dropped from 12 failures to 5.

**The remaining 5 failures are genuine pre-existing archive
characteristics/driver-behavior differences, not programming bugs --
documented, not touched, per this lib's own established
`missing_type.lpc` precedent (§5):**

- **`read_bytes.lpc` / `read_file.lpc`** (cascading from the same root
  cause): both compare `read_bytes("/testfile")` against
  `read_file("/testfile")` and assert byte-identical output.
  `/testfile` is a `cp()` of `core/lib/master/master.lpc`, and that
  *specific* source file has **CRLF line endings throughout** (`grep
  -c $'\r'` = all 269 lines, confirmed present identically in the
  pristine `raw/` archive copy too -- not a conversion artifact; 184 of
  this whole lib's 202 `.lpc` files have `\r` somewhere, a pervasive
  original-archive characteristic). `read_file()` does universal
  newline translation (`\r\n`->`\n`); `read_bytes()` returns exact raw
  bytes -- this is standard, correct, intentional MudOS/FluffOS efun
  semantics (text-mode vs binary-mode read), confirmed via `eval`
  (`a[25]==13 ('\r'), b[25]==10 ('\n')`, first divergence). The test's
  own assumption that these two efuns return identical output for an
  arbitrary source file only holds for a CRLF-free file; fixing this
  would mean either normalizing `master.lpc`'s line endings (a broad,
  out-of-scope content decision touching most of the lib, not a
  compile/type-check-level bug) or picking a different comparison
  file (inventing new test behavior) -- documented only.
- **`call_stack.lpc`**: `ASSERT(catch(call_stack(4)))` (line 17)
  expects `call_stack(4)` to throw for an out-of-range `info` argument;
  this driver returns a value instead of throwing, so `catch()` yields
  falsy and the assert fails. A genuine `call_stack()` argument-range
  behavior difference from whatever original driver this fixture
  targeted -- same class as `missing_type.lpc`.
- **`set_light.lpc`**: fails on the *very first* assertion (line 15,
  `#define CHK ASSERT(light = set_light(0));`, called with
  `light` starting at 0) -- `set_light(0)` legitimately returns `0` for
  a freshly-created object with no light set yet (confirmed live via
  `eval`), so `ASSERT(0)` is unconditionally false by the macro's own
  construction, independent of any path bug or driver quirk. This is a
  pre-existing defect in the archive's own test fixture (asserting
  truthiness of a value that can legitimately be zero), not something
  introduced by porting -- documented only, not "fixed" (there's no
  way to guess what threshold the original author intended without
  inventing test logic).
- **`shadow.lpc`**: `goodshad.lpc:4`'s `ASSERT(shadow(previous_object()))`
  fails because the driver's `master.lpc`-mediated `valid_shadow()`
  check (`core/lib/master/valid.lpc:13`) calls
  `ob->query_prevent_shadow(previous_object())` on the bare test
  object being shadowed, which defines no such function and isn't
  approved as a result -- a driver/master-apply interaction difference
  from whatever base class the original archive expected all test
  objects to inherit. Same class as the others: documented, not fixed.

**Operationally important gotcha, also newly discovered by finally
reaching `efuns/`**: `core/sefun/tests/efuns/shutdown.lpc`'s
`do_tests()` schedules `call_out((: do_the_nasty_deed :), 60)`, which
60 seconds later calls the **real** `shutdown()` efun (exit code 55)
-- the file's own comment says "This one is hard to test :-)". This
does not error or show up in any `tests`/`recurse()` output at the
time it runs (`do_tests()` returns immediately, cleanly); it silently
armed a 60-second-delayed full driver shutdown that fired mid-session
during this test pass and was initially mistaken for external
interference before the `call_out` was found. **This is exactly why
the bare `tests` command dying early in `compiler/` has, by accident,
never actually been a problem in practice** -- it currently prevents
`efuns/` from ever being reached by a normal `tests` run at all. If a
future fix ever resolves the `missing_type.lpc` compiler gap (or
`compiler/succeed.lpc`'s `##`-pasting gap) enough to let the bare
walk continue past `compiler/`, running a bare `tests` on a live,
populated mud would, ~60 seconds later, silently kill the whole driver
for every connected player. Documented here as a standing operational
trap for any future maintainer or test pass on this lib, not
"fixed" -- the fixture is doing exactly what its author intentionally
wrote it to do, and disarming it would be a content/design change
outside this project's scope.

Verified live throughout with a real driver boot + `mudclient.py`;
`git status` re-checked and all incidental test-run scratch files
(`/testfile`, `OBJ_DUMP`, `OBJ_DUMP2`, `sf.o`, `test_file`, ad-hoc
`ed`-created files, a stray top-level `single` file) removed before
committing -- only the 8 genuine `.lpc` fixture fixes remain staged.
