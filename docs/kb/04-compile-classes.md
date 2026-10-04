# KB 04 — Compile-time bug classes / driver-compat (§6)

Grammar, preprocessor, and efun-set differences between this driver and
the MudOS/LPmud/LDMud targets. Format per entry: symptom → cause → fix →
detection.

### 6.1 `#include` resolution

- **`<local.h>` next to the including file.** Angle brackets search the
  include path only. Implement `master::get_include_path()` so it
  prepends the compiling file's own directory:
  ```lpc
  string *get_include_path(string file) {
      string *parts = explode(file, "/");
      if (sizeof(parts) <= 1) return ({ "/", ":DEFAULT:" });
      return ({ "/" + implode(parts[0..<2], "/"), ":DEFAULT:" });
  }
  ```
  - It is not consulted for preload-time compiles. Change those includes
    to `"quotes"`.
  - With no `get_include_path` at all, lazy compiles mid-connection
    resolve no include path whatsoever (`shujian2008`).
- **Absolute paths in angle brackets (`<d/x/y.h>`) never resolve.**
  Either quote them, or add one `master::include_file()` apply that
  returns `"/" + path`. The leading double slash forces `merge()`
  resolution. Grep case-insensitively; use the apply when there are
  hundreds of hits (`kxkjii2`: 358 files).
- **`..` in include paths is forbidden.** Use the real absolute path.
- **Case sensitivity.** `<Action.h>` vs `action.h`. One wrong-case
  include can dominate a sweep. Use `find -iname`.
- **`inherit` after globals is fatal**, including globals pulled in from
  an included header. Reorder, and fix the shared header once.

### 6.2 Things that were never real efuns on this driver

- **`tail()`**: reimplement it in LPC. It's fatal if it sits inside
  simul_efun.
- **`efun::set/query/delete/addn`** (nitan property system): see §7.15.
- **`LONELY_IMPROVED`-gated `efun::` families**: flip the guard to the
  pure-LPC `#else` branch. The `count_*` bignum wrappers have no
  fallback; reimplement them with int arithmetic via the lib's own
  `atoi()`, never a `(int)` cast.
- **`ed_start`/`ed_cmd`/`query_ed_mode`**: this build is `OLD_ED`, so
  only `ed()` exists. If the player-body editor mixin uses them,
  registration dies silently. Rewrite against `ed()`. See §7.161 for
  modern libs.
- **Never-defined simul_efun globals** surface at runtime one at a time:
  `remove_ansi`, `noansi_strlen`, `B2G` (passthrough), `db_affected`,
  `clr_ansi`, `chinese_number`, `changed_match_path` (§7.29: implement
  real nested descent), `query_bandwide` (`({0.0,0.0})`),
  `query_shadowed` (`shadow(previous_object(),0)`, never
  `this_object()`). Watch `debug.log` during play.
- **Classic efuns to reimplement:**
  - `extract()` → slicing. Caveat: a varargs shim can't tell an omitted
    `end` from an explicit `0`. Rewrite `extract(s,0,0)` call sites as
    `s[0..0]`.
  - `version()` → `"FluffOS " + __VERSION__`.
  - `wizlist()` → `cat("/WIZLIST")`.
  - `localcmd()` → `commands()`.
  - `log_file()` → `write_file(LOG_DIR…)`; add `assure_file` (§7.11) and
    `seteuid` (§7.184).
  - `privp()` → `strlen(geteuid(ob))`.
  - `cat()` → `read_file` + `write`.
  - `indices()` → `keys()`.
  - `set_this_object()` → just drop it when the ACL doesn't depend on
    caller identity.
  - `command(str, ob)`, `transfer()`, `add_verb()`: see
    §7.172–§7.174.
- **`new` and `class` are always reserved words.** Rename parameters or
  locals that use them.
- **`get_dir(dir, 2)`** (Amylaar's "detailed" flag) is `-1` here. Index
  `[1]` for size and `[2]` for mtime.

### 6.3 Grammar strictness

- `static` on functions: see §4.3.
- **A bare `array x;`** declares nothing. Change it to `mixed *` where it
  surfaces (bulk-fix only when there are hundreds of hits).
- **`TYPE * a, b;`**: the `*` binds only to `a`. Script-fix the narrow
  shape.
- **`switch` with only `default:`** is a parse error, fatal in
  `master::connect()`. Rewrite it as a plain block.
- **`MACRO.0` float trick**: rewrite as `(MACRO * 1.0)`.
- **Multi-character char literals**: `case '''` → `case '\''`;
  `'25'` is invalid.
- **`TYPE array NAME`** (needs `ARRAY_RESERVED_WORD`, which is off here):
  drop the word `array` and use `TYPE *NAME`. Variants are
  `TYPE array *NAME` (just drop `array`) and `class X array NAME`
  (§7.163). Base-class instances cascade: `brassring` had 49% of its
  files fail from 2 base files.

### 6.4 One shared root cause, not N bugs

If dozens of sweep failures share an identical error string, find the
one shared `inherit`/`#include` first. Examples: a bad base declaration
(`ds386`: 299 failures), a missing `#define` (`xyzx3`: 81).

### 6.5 Function-binding order within a file

- **Calling a same-file helper before its definition** can fail. Define
  it first or forward-declare it.
- **A wrapper named after a real efun** (`message`, `write`,
  `tell_room`) that is called before its definition binds to the REAL
  efun silently. Add a `varargs` forward declaration at the top.
- **Overriding an inherited function:** a forward declaration isn't
  enough. The real body must precede every same-file call site.
- See also §7.12: inside the defining simul_efun file itself, a bare
  call to a same-named-as-efun function hits the efun. Use `efun::` plus
  a guard.

### 6.6 Pre-existing author typos

Confirm each one is in `raw/`, and fix only where the compiler flags it.
- Fullwidth punctuation used as syntax (`，`, `。h`). Never
  blanket-replace inside strings.
- A missing closing quote before `+`.
- A copy-paste inherit of a nonexistent base: match the file's real
  content to an existing sibling base. Don't invent new bases.
- A `//` comment glued to code on the same line (swallows a
  declaration).
- `convertd.lpc`'s Greek table `"α\",` (西游记/ES II family, ~45 per
  lib, often fatal in simul_efun). Use a CRLF-aware sed and re-grep
  afterwards.
- A truncated file: close it with an empty body. Check siblings for the
  same truncation.

### 6.7 Build options can contradict the archive's own `local_options`

What matters is how THIS driver was built, not what the archive's own
`local_options` says. `REF_RESERVED_WORD` is defined here, so a variable
named `ref` is a syntax error. `ARRAY_RESERVED_WORD` is undefined.
Grep `(string|object|int|mixed|float|mapping)\s*\*?\s*ref\b\s*[,;=)]`.
Check `src/base/internal/options_internal.h` for the real flags.

### 6.8 `status` used as a type

There is no `status` keyword here. Replace it with `int` wherever it
appears in type position. Grep bare `\bstatus\b` and filter out prose
(`nosave private status x;` defeats narrower patterns).

### 6.9 MudOS-v21 `ident?()` predicates; `MACRO -> meth(`

- `?` is not legal in identifiers. Rename `foo?(` to `foo_q(`, but only
  for identifier tokens; don't touch question marks in prose strings.
- `#define FOO "/path"` followed by `FOO->meth()` parses as class
  access. Use `efun::call_other(FOO, "meth", args)`, with no trailing
  comma when there are no args (`mundoscuro`).

### 6.10 Compiler warnings: each one is a fix, never `#pragma no_warnings`
`scripts/lpc_warnings.py <slug>` builds a site-like tree, runs `lpcc
--batch` over every `.lpc`, and groups the diagnostics. Read the boot-time
block that lpcc prints *before* the first `=====` header too (master,
simul_efun and preloaded daemons are reported there, not under their file),
accept warnings with no column (`file:13: warning: Macro ...`), and rescan
until stable: a file stops listing after its warning cap ("too many warnings
in this file"). The driver's own run (`log/errors/*`, console) must end with
none. `Foundation I` went from ~480 to 0 this way.
`--fix` applies the mechanical classes: `nosave` functions, unused locals, unknown escapes, negative range ends, unknown pragma lines, and `varargs` for an arg-count mismatch. Its unused-locals pass leaves a name alone (and lists it under "not fixed automatically") when the name also appears on a line inside an `#if`/`#ifdef` block of the same function -- the `fuzzymatch.lpc` shape below -- and a call initializer (`x = time()`) is listed rather than guessed. **Do not wrap it in `timeout`:** stdout is block-buffered, so a killed run prints nothing although every edit it made is already on disk (a 2300-file lib takes ~2 minutes per scan, two scans per round); run it with the harness's background mode instead.

| Warning | Cause and fix |
|---|---|
| `Illegal to declare nosave function` | §4.3's blanket `static`→`nosave` also hit functions. A function that was `static` is `protected`; beside `private` drop the `nosave`; keep it public when another object calls it (`reset()` from the `reset` command). Variables keep `nosave`. A rejected outside call to a `protected` function is logged as `apply() with insufficient permission ... needs: public, has: protected` in the driver output: run the batteries, grep for it, expect none. Driver applies (`create`, `crash`, `slow_shutdown`, ...) are not affected. |
| `Unused local variable 'x'` (reported at the closing brace of its scope) | Delete the declarator (several in one statement: rebuild it). If the variable was meant to be read, read it (`get_stack()` printed the function name twice; `stack0` was the program name). |
| `Function pointer returning string constant is NOT a function call` | `(: "name" :)` was the pre-NEW_FUNCTIONS this_object pointer. It is now a function returning the string. Write `(: name :)` (forward-declare `name` if it is defined later). If `name()` never existed the old pointer answered 0: say so with a real function. The object form `(: this_object(), "name" :)` is the same bug **with no warning**: it compiles as a comma expression, so `SetLong()`, exit checks and `SetSearch()` get the string back (a room whose long description is `go_away`). Detect with `grep -rnE '\(: *(this_object\(\)\|ob\|obj\|who) *, *"'`; write `(: call_other, ob, "name" :)` (arguments are bound when the pointer is made) or `(: name :)` for this_object(). Once the pointer really runs, read the target: a function that `write()`s or `message()`s instead of returning the text raises an error in `GetExternalDesc` (`Praxis/obj/misc/stone.lpc`). |
| `Unknown escape sequence '\x'` | The character stands for itself: drop the backslash (`"%s\.%s"`, `"\Problem"`, `"%%\|%ds"`). |
| `Previous function prototype for f does not match current function in return type` | The header disagrees with the definition. Make the prototype match the definition (callers use the definition). |
| `Expression has no side effects` / `Value of conditional expression is unused` | Read each one: it is often a real typo. `res == who;` was meant `res = who;` (`dsI` `GetRaceAdverb()` answered "godly" for every race name); `if( !env ) "You are nowhere!";` and `string f() { "text"; }` lost their `return`; `return ("help", "text")` carries a pointless first operand. Only an empty `if (x) { }` with just a comment inside, or a stray `tmp + "";`, is deletable (the line reported is the *next* statement; a variable that was only read there becomes unused: delete that too). |
| `Macro 'X' redefined` | Several files `#include`d into one object spell the body differently. Make the text identical, and define what the body uses in each file so each still compiles on its own. |
| `f() inherited from both A and B` + `Redeclaration of global variable` | Diamond inheritance (a daemon that inherits both DAEMON and OB_USER brings /std/clean_up in twice). Overriding the functions does not silence the variable warning: drop one inherit and spell out what it added. **When A and B in the warning are the *same file*** (`"inherited from both /lib/mount.lpc and /lib/mount.lpc (via /lib/sentient.lpc)"`), it is not two classes sharing a feature — it is one mixin pulled in by two different paths, almost always because a content file redundantly re-inherits something its own base class already provides (`dsIII`'s `horse.lpc` directly inherited `LIB_MOUNT`/`LIB_DOMESTICATE` on top of `LIB_SENTIENT`, which already supplies both via `LIB_NPC`/`LIB_LIVING`). Find the redundant `inherit` with `grep -rln "LIB_X\b"` (every file that pulls it in directly) and check which of those *also* inherits a class that transitively provides it; drop the redundant line (confirm the file never calls `mixin::func()` with an explicit scope, which would need its own copy). This is a different, safer case than two *different* classes colliding on a name: there is only one piece of code, so removing either copy changes nothing. A large cluster of these at once (`dsIII`: `storage.lpc`, `flask.lpc`, `base_armor.lpc`, `secure/lib/net/client.lpc` each redundantly re-inheriting several event mixins or `daemon.lpc`/`clean.lpc`/`save.lpc`) is a real class worth fixing, but verify each pair before touching it — unlike `horse.lpc`, a mixin-level redundant inherit might be relied on by something that expects its *own* override to win in one specific case. |
| `Number of arguments to 'f' disagrees with previous definition` | Either a stale same-file forward declaration (fix the prototype to match the real definition — check the rest of the file for copy-pasted siblings of the same bug, `merentha`'s `login.lpc` had 7), or an override that legitimately needs more/fewer arguments than the **inherited** function it replaces (`money.lpc`'s `remove(object env)` over `clean_up.lpc`'s 0-arg `remove()`, to know who to pay out to): add `varargs` to the override, which resolves the count mismatch without changing any call site. Checked against the driver source (`compiler.cc` `define_new_function`, `apply.cc`, `interpret.cc`): the warning is skipped when *either* the new or the previous declaration is `varargs`, and `varargs` only skips two things -- the `call other type check` config's runtime "Wrong number of arguments" (off in these libs) and the compile-time "Wrong number of arguments" *error* for a strict-types call with too few arguments. It can only remove a failure, never add one, so it is safe to add on whichever declaration the warning is reported on (`scripts/lpc_warnings.py --fix` does exactly that, to a head that starts its line; `dsIII`'s `eventSuffer`/`eventTurnOn`/`create` families, `dsI`'s `CanClose`/`CanOpen`/`eventReceiveObject`). It does not fix a *return-type* mismatch: that is the separate `does not match current function in return type` row, which needs a decision about which side is right. |
| `Unknown #pragma, ignored` | `#pragma save_binary` (Dead Souls dsI/dsII: 79 files). The driver ignores the line, so delete it -- no behaviour changes; `--fix` does it as its own first pass because it removes lines. |
| `A negative constant as the second element of arr[x..y]` | §7.209. |

**Verifying `Redeclaration of global variable 'X'` before touching anything.** The driver's own fix for the name collision (`compiler.cc`'s `define_variable()`) forces the *second*-declared side `nosave`, specifically so `save_object()` never has two values competing for the same key — i.e. the driver already prevents the obvious save-file corruption. That makes most instances genuinely cosmetic: if **both** colliding declarations were already `nosave` on their own (grep each declaring file for the name), forcing it again changes nothing, full stop (`dsIII`'s `Search` — `lib/std/room.lpc` and `lib/events/search.lpc` both already `nosave`; `my_save` — four `std/*.lpc` storage/armor files, all four already `nosave`). The **only** real-bug shape is a variable that was NOT `nosave` in its own file (meant to persist) losing that silently because a sibling mixin it happens to get inherited alongside also uses the name — check whether it is actually written with data worth keeping, and whether `create()` already reinitializes it on every boot regardless (if so, the forced nosave changes nothing observable either, same as `dsIII`'s `room.lpc` heartbeat-tick `counter`, which wraps at 9999 and is meaningless across a reboot anyway). A name that `grep`'s "declared in 1 file(s)" is usually not one file declaring it once — it is one mixin inherited twice by some downstream object (the diamond-inheritance case above); find the second path before concluding anything. Given the verification cost per name, treat a large count (`dsIII`: 1671 warnings, 60 distinct names, 929 files) as its own scoped follow-up, not part of a routine warning-fixing pass — spot-check the top offenders by warning count first, since they dominate the total.

**Trap in `--fix`'s unused-locals pass: a declaration unused only because an `#ifdef`/`#else` branch that uses it is not compiled into *this* driver.** A variable declared before the conditional and used only inside the untaken branch looks genuinely unused to the compiler on this build, so `--fix` deletes it — but a driver built *with* that feature (a package, a `#define` some other installation sets) would then fail to compile. Real case: `merentha`'s `functionprofile.lpc` declared `object ob, *ob_list; mixed *list;` for use inside `#else` (no `__PROFILE_FUNCTIONS__` package on this driver); `--fix` deleted them as unused in round 1. The fix is to move the declaration inside the branch that uses it, not to leave it deleted — spot-check `--fix`'s unused-locals diff for any name that also appears inside an `#ifdef`/`#ifndef`/`#else` elsewhere in the same file before trusting the run.
