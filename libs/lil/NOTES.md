# Lil -- porting notes

Source: `lil_0.3.zip`, a maintained, already-FluffOS-adapted archive from
lpmuds.net (a now-defunct LPMud archive site). The live site is down; this
exact archive was recovered from the Wayback Machine
(<https://web.archive.org/web/20160306101015id_/http://lpmuds.net/files/lil_0.3.zip>)
and content-verified (valid zip, intact central directory, 1473 files,
non-corrupted) before this session started. Slug `lil`, number 179, port
40226. The zip bundles a FluffOS 2.9-ds2.09 driver source snapshot
(`fluffos-2.9-ds2.09/`), plus `bin/`, `win32/` build/install scaffolding --
all ignored, this project uses its own driver. The real mudlib root is the
zip's `lib/` directory.

Lil is, per lpmuds.net's own listing, "a fixed up version of the MudOS
testsuite lib with MudOS docs added" -- genuinely a from-scratch
bootstrapping base, not a game. Its own shipped `README` says it plainly:
"about as bare bones as it gets without coding 100% from scratch... For
the seriously leet only." There is no login/password system, no rooms, no
combat, no accounts. Connecting drops you straight into an anonymous
session (auto-named `stufN`) with ~10 primitive commands
(`dest`/`update`/`ed`/`eval`/`rm`/`say`/`who`/`quit`/`shutdown`) plus a
sizeable bundled efun/operator/compiler self-test suite under
`single/tests/`. This matches this session's `libs/genesis/` (engine-only,
no game-world content) and `libs/imud/`'s "thin surface is the real,
intentional scope" precedent (AGENTS.md \S2.3) far more than a normal game
mudlib -- treat the minimalism as the archive working as designed, not as
a conversion failure.

## 1. Conversion

Pure-ASCII English archive -- `scripts/convert_lib.sh` against
`raw/lil_0.3/lib` confirmed this: 889/894 files already valid UTF-8 (5
skipped as genuinely binary, e.g. `.o` byte-code artifacts under
`single/tests`), **zero** lossy conversions. 199 files renamed `.c`->
`.lpc`; 25 literal `.c"` references fixed; 1 local angle-bracket
`#include` converted to quotes; 7 files touched by the `static`->`nosave`
sweep. No manual `"static` (string-literal) or `#define nosave/protected
static` (macro-shim) collisions found -- the only files hit were real
`static` keyword usages, all safe to convert.

`include/globals.h`'s own compat shim (`#ifdef __SENSIBLE_MODIFIERS__
#define staticf protected / staticv nosave #else #define staticf static /
staticv static #endif`) is a near-miss of the known collision class
(AGENTS.md \S4.3) but not an actual instance of it: the macro *names* are
`staticf`/`staticv` (used throughout the codebase as `staticf void
foo()`), not `nosave`/`protected` themselves, so the blind `static`->
`nosave` sed correctly touched only the `#else` branch's raw `static`
token, which is exactly the right fix regardless of which branch is
live (this driver's `lpcc` boot dump confirmed `__SENSIBLE_MODIFIERS__`
*is* predefined here, so the `#ifdef` branch -- `protected`/`nosave` --
was already correct pre-sed and untouched by it).

## 2. Compile-time driver-compat fixes

Exactly **one** real fix was needed, and it's not from any of the eight
recurring bug classes flagged going in (`add_action`/`NO_ADD_ACTION`
mismatch, `ed_start`/old-`ed()` mismatch, `.c`->`.lpc` filename-slice
arithmetic, `ref` as an identifier, missing `get_root_uid()`/
`get_bb_uid()`/`creator_file()`, `SANE_EXPLODE_STRING` edge cases, stale
`get_config()` indices, old `TYPE array NAME` declarations -- checked all
eight, all clean):

- **`include/config.h` (the "global include file" every object gets for
  free) was an empty site-customization stub**, but ~all of the bundled
  self-test suite (130 files under `single/tests/efuns/` and
  `single/tests/operators/`) uses `ASSERT()`/`ASSERT2()`/`SAVETP`/
  `RESTORETP` from `include/tests.h` with **no `#include` of their own** --
  relying entirely on the global-include mechanism to supply those macros.
  The shipped `config.h` never did that (it's explicitly a "customize this
  yourself" placeholder, per its own comment), so 150/199 files in a first
  `lpcc_check.sh` pass failed with `Undefined function ASSERT` /
  `Undefined variable SAVETP`. Fixed by adding `#include "tests.h"` to
  `config.h` (guarded, safe against double-inclusion from files that also
  explicitly `#include <globals.h>`, which itself pulls in `tests.h`).
  Confirmed this is a real gap in the shipped archive, not something this
  port broke: neither `bin/mudos.cfg` nor `etc/config.test` differ in
  their `global include file` setting, and zero `single/tests/efuns/*.lpc`
  files have any `#include` line at all.
  - After this fix: `lpcc_check.sh` goes from 49/199 to 157/199 passing.
    Every one of the remaining 42 failures is either one of the 41 files
    under `single/tests/compiler/fail/` (deliberately-broken syntax --
    `command/tests.lpc`'s own test runner `catch()`s these and asserts
    they fail to load, by design, exactly like the driver's own compiler
    unit tests) or `single/tests/compiler/succeed.lpc` (see below) --
    confirmed by grepping the raw compile log for every non-`ASSERT`
    error message and checking each one is either an intentional-failure
    fixture or the one known dialect gap.

## 3. A genuine driver-dialect gap, not fixed (by design)

`single/tests/compiler/succeed.lpc` fails to compile on this driver:
`error: Illegal character '#'` on `int paste = X1##X2;` -- isolated with a
minimal standalone repro (`X1##X2` alone, nothing else in the file) that
reproduces the exact same error. This driver's preprocessor does not
implement C-style `##` token-pasting, a genuine MudOS-dialect feature this
file is specifically testing (the heredoc `@END .../@@END ...` string/
string-array syntax elsewhere in the same file, tested in isolation,
compiles fine on this driver -- the token-paste is the only failure).
This is a real driver/dialect incompatibility, not a mudlib logic bug, and
per this project's standing rule (fix compile errors/driver
incompatibilities, never invent/patch around content or test semantics)
it's left as-is and just documented here. Practical effect: the built-in
self-test runner (`master()->flag("test")`, or equivalently `"/command/
tests"->main("")`) walks the entire `single/tests/` tree successfully and
then dies uncaught the moment it reaches this one file, because
`command/tests.lpc`'s own recursion only wraps `fail/`-directory loads in
`catch()` -- everything else is assumed to compile. Individual efun tests
still run fine one at a time via `eval` (see \S5) -- confirmed e.g.
`"/single/tests/efuns/capitalize"->do_tests()` returns cleanly with no
assertion failure.

## 4. `efun <name>` command referenced but not shipped

Both the boot `motd` ("The only commands in this little mudlib are:
dest, update, ed, eval, efun, rm, say, who, quit, and shutdown.") and the
mudlib's own top-level `README` ("Currently the only way setup to invoke
the tests is to login to Lil and type 'efun efun_name' e.g. 'efun
capitalize'.") describe an `efun` command for running one self-test at a
time -- but there is no `command/efun.lpc` (or any file that would resolve
via `commandHook`'s `/command/`+verb dispatch) anywhere in the archive.
Live-verified: typing `efun capitalize` just gets the default fail message
(`What?`). This is a pre-existing gap in the archive as packaged by
lpmuds.net, not something this conversion introduced or broke -- per this
project's standing rule against inventing content, no `command/efun.lpc`
was written. The individual self-tests remain fully runnable as a
workaround via `eval`, e.g.:
```
eval "/single/tests/efuns/capitalize"->do_tests();
```
which correctly returns without error (an `ASSERT()` failure would
`error()` out with a Check-failed message instead).

## 5. Master applies / driver predefines actually in effect (verified via a real boot)

This driver's `lpcc`/boot startup dump (all `#define __X__` lines) shows,
among others: `__SENSIBLE_MODIFIERS__`, `__PACKAGE_UIDS__`, `__OLD_ED__`,
`MUDOS`, `FLUFFOS` all predefined; `__NO_ADD_ACTION__`, `__NO_WIZARDS__`,
`__NO_ENVIRONMENT__` all **not** defined. Concretely this means: the
codebase's native (non-`NO_ADD_ACTION`) `add_action("commandHook", "",
1)` dispatch path is live (bug class 1, checked, clean -- the code
correctly branches on this driver having real `add_action()` support);
old-style single-argument `ed(file)` is used rather than `ed_start()`/
`ed_cmd()` (bug class 2 -- also correctly branched, live-verified: `ed
<path>` enters ed mode with a `:` prompt and `q` exits cleanly back to the
main prompt); `get_root_uid()`/`get_bb_uid()`/`creator_file()` (bug class
5) were already present in the shipped `single/master.c`, so `PACKAGE_UIDS`
booted with zero master-apply errors on the first try. Every user
connecting also gets `enable_wizard()` unconditionally (`#ifndef
__NO_WIZARDS__`, and that macro is never defined here) -- there is no
account/wizard-rank system to speak of, every session already has wizard
powers by construction. This is the reference lib's actual design, not
something to lock down.

## 6. No accounts, so no admin-account seeding (N/A, like `imud`)

Same as this session's `libs/imud/` precedent (AGENTS.md \S2.3): there is
no account/wizard-rank persistence system to seed a `fluffos`/`Mud@2026`
admin identity into. Every connection is auto-named `stufN` (N = the
object's clone-id) and is already a wizard from `setup()`'s unconditional
`enable_wizard()`. `update <path>` (this project's canonical ACL/compile-
permission smoke test) works immediately for any connecting session --
live-verified against `/command/who`.

## 7. No Intermud / no outbound network at boot -- confirmed, not assumed

Per the sweep instructions: several sibling lpmuds.net-sourced libs this
session made real outbound Intermud-3 connections despite not clearly
advertising it. Checked specifically for Lil: `grep -rn
"dns_master|dns_d|intermud|socket_create|socket_connect|external_start"`
across the whole tree returns **zero** hits; `etc/` has no `preload` file
(only `config.test`/`motd`), so `master.lpc`'s `epilog()` (which reads
`CONFIG_DIR + "/preload"` and returns `({})` if the file is absent)
preloads nothing at all; `ss -tnp` against the live driver PID during
testing showed no outbound sockets; `log/debug.log` stayed empty across
every boot in this session. "No intermud" (the archive's own description)
is genuinely true here, not just advertised.

## 8. Verification performed

- `scripts/lpcc_check.sh`: 157/199 pass; all 42 failures accounted for
  (\S2/\S3 above).
- Booted the real driver (`~/src/fluffos/build-debug/src/driver
  config.fluffos`) repeatedly with zero fatal errors and an empty
  `log/debug.log` each time.
- Raw Python socket sessions (this project's preferred verification
  method) confirmed: connecting gets a banner + auto-assigned name; `who`
  lists the session correctly; `say`, `eval` (arithmetic + calling into
  `single/tests/efuns/*`), `rm`, `update`, `ed` (enter/exit), `dest`, and
  `quit` all produce correct output; `quit` is clean (`Bye.` + socket
  close, no error).
- Ran the bundled self-test suite live via `eval "/command/tests"->
  main("");` -- walks the entire `single/tests/` tree (efuns, operators,
  compiler-pass, compiler-fail) with all the fixture-only failures caught
  as designed, stopping only at the one genuine driver-dialect gap
  (\S3), which is outside `command/tests.lpc`'s own `catch()` coverage
  (only `fail/`-directory loads are wrapped).
- **WASM status update (2026-08-26, another session)**: promoted to
  `playable`. Booted clean with zero fixes needed, consistent with the
  earlier confirmation that this lib has no real sockets/Intermud
  dependency at all. Verified with a scripted WASM session: `who`
  (correct output), `eval return 1+1;` (`Result = 2`), and `quit`
  (clean `Bye.` disconnect).
