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
  - **`#include <../hole.h>`** (a header named relative to the including file, in angle brackets) is the same
    refusal: the driver skips the search for any `<...>` name with `..` in it and resolves only a quoted one against
    the including file. 183 + 185 files under `d/` of `es1_win` and `esI` (and 35, 8, 7, 3 and 3 in `kxkjii2`, `kxkj`, `darkelib`, `sunshadow`,
    `shadowgate`) died with `Cannot #include` and a second
    error wherever the missing header's macros were used (`inherit MONSTER;` with `MONSTER` undefined: *syntax error,
    unexpected L_IDENTIFIER, expecting L_STRING*). One `master::include_file()` fixes them all: an answer that
    differs from the name makes the driver resolve it like a quoted include through `merge()`, which understands `..`:
    ```lpc
    string include_file(string compiled, string from, string path) {
        if (strlen(path) > 2 && path[0..2] == "../") return "./" + path;
        return path;
    }
    ```
    (`kxkjii2` already answered for an absolute name and `xyxy2` still does; one function can do both.) Detection:
    `grep -rlE '#[ \t]*include[ \t]*<\.\./' libs/<slug>/work`, or a scan whose top error is *Cannot #include ../x.h*
    in dozens of files. `lpcc --batch` runs `create()`, so feeding it those files proves they load.
- **Case sensitivity.** `<Action.h>` vs `action.h`. One wrong-case
  include can dominate a sweep. Use `find -iname`.
- **`inherit` after globals is fatal**, including globals pulled in from
  an included header. Reorder, and fix the shared header once.

### 6.2 Things that were never real efuns on this driver

- **`tail()`**: reimplement it in LPC. It's fatal if it sits inside
  simul_efun. A *definition* there is the fix for every command that
  calls it at once (`es1_win`/`esI`: `/adm/simul_efun/tail.lpc`, the last
  1000 bytes from the first whole line, `message()`d to `this_player()`).
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
Helpers around it (each prints a plan without `--apply`): `scripts/lpc_check_files.py SLUG OBJ...` recompiles just
the objects you edited in the scan tree in seconds (it re-copies every file an earlier call copied, so a file edited back to HEAD is not stale); `scripts/lpc_fix_unused_init.py` handles the unused locals whose
declaration has an initializer (a literal or a side-effect-free expression goes -- `environment()`, `this_player()`,
`sort_array(...)`, the `PURE_CALLS` list -- any other call stays as a statement); `scripts/lpc_move_decl.py` moves a
local that is only used in an inactive `#if` branch into that branch; `scripts/lpc_fix_strptr.py [--comma]` rewrites
`(: "name" :)` and `(: this_object(), "name" :)` into `(: name :)` with forward prototypes;
`scripts/lpc_fuzzy_patch.py` carries a patch from one lib to a reformatted sibling, and
`scripts/lpc_twin_port.py` does it exactly (and audits the rest) when the sibling is the formatter's output of the
same code (KB 08 §10.13).
`scripts/lpc_audit_removed_locals.py BASE` is the check for the one edit the scan cannot verify -- a deleted local declaration the function still reads (below).
Four more cover the structural classes (plan without `--apply`, byte-exact edits, `lpc_src.py` is their shared
scanner): `scripts/lpc_name_winner.py` answers `f() inherited from both A and B; using the definition in W` with
`RET f(params) { return Q::f(args); }` after the leaf's last `inherit` (W is the later inherit, which the driver already
used, so nothing changes at run time; it skips a header, a `private`/`nomask` W and a signature it cannot parse);
`scripts/lpc_fix_void_override.py` turns a leaf's `int init()` / `reset()` / `create()` / `setup()` into `void` when the
base says `void` and the body only returns flags (nothing reads a hook's result; `clean_up()` is **not** a hook, see the
table); `scripts/lpc_fix_macro_redef.py` puts `#undef X` in front of the later `#define X`;
`scripts/lpc_rename_ident.py SLUG OLD NEW FILE...` renames one identifier in code only (comments, strings, preprocessor
lines, `->OLD`, `::OLD` and `OLD(` stay) -- the leaf side of a private-name collision, or a variable called `class`
(reserved word, `std/skills/attic/*` in darkelib: `class` -> `cls`).
`--fix` applies the mechanical classes: `nosave` functions, unused locals, unknown escapes, negative range ends, unknown pragma lines, and `varargs` for an arg-count mismatch. Its unused-locals pass leaves a name alone (and lists it under "not fixed automatically") when the name also appears on a line inside an `#if`/`#ifdef` block of the same function -- the `fuzzymatch.lpc` shape below -- and a call initializer (`x = time()`) is listed rather than guessed. **Do not wrap it in `timeout`:** stdout is block-buffered, so a killed run prints nothing although every edit it made is already on disk (a 2300-file lib takes ~2 minutes per scan, two scans per round); run it with the harness's background mode instead.

| Warning | Cause and fix |
|---|---|
| `Illegal to declare nosave function` | §4.3's blanket `static`→`nosave` also hit functions. A function that was `static` is `protected`; beside `private` drop the `nosave`; keep it public when another object calls it (`reset()` from the `reset` command). Variables keep `nosave`. A rejected outside call to a `protected` function is logged as `apply() with insufficient permission ... needs: public, has: protected` in the driver output: run the batteries, grep for it, expect none. Driver applies (`create`, `crash`, `slow_shutdown`, ...) are not affected. |
| `Unused local variable 'x'` (reported at the closing brace of its scope) | Delete the declarator (several in one statement: rebuild it). If the variable was meant to be read, read it (`get_stack()` printed the function name twice; `stack0` was the program name). |
| `Function pointer returning string constant is NOT a function call` | `(: "name" :)` was the pre-NEW_FUNCTIONS this_object pointer. It is now a function returning the string. Write `(: name :)` (forward-declare `name` if it is defined later). If `name()` never existed the old pointer answered 0: say so with a real function. The object form `(: this_object(), "name" :)` is the same bug **with no warning**: it compiles as a comma expression, so `SetLong()`, exit checks and `SetSearch()` get the string back (a room whose long description is `go_away`). Detect with `grep -rnE '\(: *(this_object\(\)\|ob\|obj\|who) *, *"'`; write `(: call_other, ob, "name" :)` (arguments are bound when the pointer is made) or `(: name :)` for this_object(). Once the pointer really runs, read the target: a function that `write()`s or `message()`s instead of returning the text raises an error in `GetExternalDesc` (`Praxis/obj/misc/stone.lpc`). What each hook does with the target's return value decides the fix: `SetLong`, `SetSearch`, `SetSmell` and exit checks use it (a search handler that prints and returns nothing is followed by "You find nothing."); a `SetItems` function is evaluated and its return is printed (an `int` prints as `1`); `SetWear` blocks on 0; `SetInvis(fn)` is called with only the viewer. Nightmare-era targets (`void`, `message()`, `move()`, `query_alignment()`, `query_race()`) need adapting, or the real pointer breaks what the string pointer hid (Praxis helm: nobody could wear it; invis ring: every `look` at the wearer raised). A target that does not exist: restore its text from a lineage sibling (`grep -rl look_at_vault libs/`). |
| `Unknown escape sequence '\x'` | The character stands for itself: drop the backslash (`"%s\.%s"`, `"\Problem"`, `"%%\|%ds"`). |
| `Previous function prototype for f does not match current function in return type` | The header disagrees with the definition. Make the prototype match the definition (callers use the definition). |
| `Function f inherited from 'X' does not match current function in return type ( void vs int )` | A leaf declared `int init()` (old MudOS: no type means int) and never returns a flag, over a `void` base. For `init`/`reset`/`create`/`setup` nothing reads the result: the leaf becomes `void`, `return 1;` becomes `return;` (`lpc_fix_void_override.py`). **`clean_up()` is not a hook:** the driver reads it (`backend.cc`: a zero return, which a `void` function gives, clears `O_WILL_CLEAN_UP` and the object is never asked again). Make the leaf match the base (darkelib `daemon/voter.lpc`: `int clean_up() { return 1; }` over `std/daemon.lpc`'s `void` that destructs became `void clean_up() { }`, still never destructed), or change the base when most overrides are `int` (darkelib has 90 `int clean_up` to 31 `void`). Any other function: read its callers, then make the leaf match; the definition wins. |
| `Expression has no side effects` / `Value of conditional expression is unused` | Read each one: it is often a real typo. `res == who;` was meant `res = who;` (`dsI` `GetRaceAdverb()` answered "godly" for every race name); `if( !env ) "You are nowhere!";` and `string f() { "text"; }` lost their `return`; `return ("help", "text")` carries a pointless first operand. Only an empty `if (x) { }` with just a comment inside, or a stray `tmp + "";`, is deletable (the line reported is the *next* statement; a variable that was only read there becomes unused: delete that too). |
| `Macro 'X' redefined` | Several files `#include`d into one object spell the body differently. Make the text identical, and define what the body uses in each file so each still compiles on its own. |
| `f() inherited from both A and B` + `Redeclaration of global variable` | Diamond inheritance (a daemon that inherits both DAEMON and OB_USER brings /std/clean_up in twice). Overriding the functions does not silence the variable warning: drop one inherit and spell out what it added. **When A and B in the warning are the *same file*** (`"inherited from both /lib/mount.lpc and /lib/mount.lpc (via /lib/sentient.lpc)"`), it is not two classes sharing a feature — it is one mixin pulled in by two different paths, almost always because a content file redundantly re-inherits something its own base class already provides (`dsIII`'s `horse.lpc` directly inherited `LIB_MOUNT`/`LIB_DOMESTICATE` on top of `LIB_SENTIENT`, which already supplies both via `LIB_NPC`/`LIB_LIVING`). Find the redundant `inherit` with `grep -rln "LIB_X\b"` (every file that pulls it in directly) and check which of those *also* inherits a class that transitively provides it; drop the redundant line (confirm the file never calls `mixin::func()` with an explicit scope, which would need its own copy). This is a different, safer case than two *different* classes colliding on a name: there is only one piece of code, so removing either copy changes nothing. A large cluster of these at once (`dsIII`: `storage.lpc`, `flask.lpc`, `base_armor.lpc`, `secure/lib/net/client.lpc` each redundantly re-inheriting several event mixins or `daemon.lpc`/`clean.lpc`/`save.lpc`) is a real class worth fixing, but verify each pair before touching it — unlike `horse.lpc`, a mixin-level redundant inherit might be relied on by something that expects its *own* override to win in one specific case. |
| `Number of arguments to 'f' disagrees with previous definition` | Either a stale same-file forward declaration (fix the prototype to match the real definition — check the rest of the file for copy-pasted siblings of the same bug, `merentha`'s `login.lpc` had 7), or an override that legitimately needs more/fewer arguments than the **inherited** function it replaces (`money.lpc`'s `remove(object env)` over `clean_up.lpc`'s 0-arg `remove()`, to know who to pay out to): add `varargs` to the override, which resolves the count mismatch without changing any call site. Checked against the driver source (`compiler.cc` `define_new_function`, `apply.cc`, `interpret.cc`): the warning is skipped when *either* the new or the previous declaration is `varargs`, and `varargs` only skips two things -- the `call other type check` config's runtime "Wrong number of arguments" (off in these libs) and the compile-time "Wrong number of arguments" *error* for a strict-types call with too few arguments. It can only remove a failure, never add one, so it is safe to add on whichever declaration the warning is reported on (`scripts/lpc_warnings.py --fix` does exactly that, to a head that starts its line; `dsIII`'s `eventSuffer`/`eventTurnOn`/`create` families, `dsI`'s `CanClose`/`CanOpen`/`eventReceiveObject`). It does not fix a *return-type* mismatch: that is the separate `does not match current function in return type` row, which needs a decision about which side is right. |
| `bitwise operation on boolean values` | `a > 700 \| b < -700` typed for `\|\|` (brassring's Diku-Alfa armors and sword: 8 files, `GetMorality() > 700 \| GetMorality() < -700`). Both operands are evaluated and the result is the same, so `\|\|` (or `&&` for `&`) only restores the short circuit. A flags test (`x & FLAG`) does not warn. |
| `Unknown #pragma, ignored` | `#pragma save_binary` (Dead Souls dsI/dsII: 79 files). The driver ignores the line, so delete it -- no behaviour changes; `--fix` does it as its own first pass because it removes lines. |
| `A negative constant as the second element of arr[x..y]` | §7.209. |

**Verifying `Redeclaration of global variable 'X'` before touching anything.** The driver's own fix for the name collision (`compiler.cc`'s `define_variable()`) forces the *second*-declared side `nosave`, specifically so `save_object()` never has two values competing for the same key — i.e. the driver already prevents the obvious save-file corruption. That makes most instances genuinely cosmetic: if **both** colliding declarations were already `nosave` on their own (grep each declaring file for the name), forcing it again changes nothing, full stop (`dsIII`'s `Search` — `lib/std/room.lpc` and `lib/events/search.lpc` both already `nosave`; `my_save` — four `std/*.lpc` storage/armor files, all four already `nosave`). The **only** real-bug shape is a variable that was NOT `nosave` in its own file (meant to persist) losing that silently because a sibling mixin it happens to get inherited alongside also uses the name — check whether it is actually written with data worth keeping, and whether `create()` already reinitializes it on every boot regardless (if so, the forced nosave changes nothing observable either, same as `dsIII`'s `room.lpc` heartbeat-tick `counter`, which wraps at 9999 and is meaningless across a reboot anyway). A name that `grep`'s "declared in 1 file(s)" is usually not one file declaring it once — it is one mixin inherited twice by some downstream object (the diamond-inheritance case above); find the second path before concluding anything. Given the verification cost per name, treat a large count (`dsIII`: 1671 warnings, 60 distinct names, 929 files) as its own scoped follow-up, not part of a routine warning-fixing pass — spot-check the top offenders by warning count first, since they dominate the total.

**Lima-family trees (lima, swmud, spacemud, wilderness) keep `#pragma no_warnings` in `include/mudlib.h`, so a removed pragma exposes 550-1300 diagnostics of four root causes.** (1) A leaf that re-inherits a module its base already has (`inherit WEAPON; inherit M_VALUABLE;`) gets the module twice, *and* the module's tiny `mudlib_setup()` replaces the base's real one (weapon.lpc's runs damage-source, durability and wieldable setup): drop the redundant inherit (check for `module::` scoped calls first) -- naming the winner would keep the bug. (2) A mixin that itself `inherit`s a dependency (`m_accountant`, `m_conversation` -> `M_ACTIONS`) duplicates it under every class that already has it (`ADVERSARY`): let the mixin declare a prototype for what it calls and let the composing class inherit the dependency. (3) Module-private variables with common names (`base`, `env`, `queue`, `skills`, `death_message`) clash when two modules meet in one class: rename the private one with a module prefix (`lpc_rename_ident.py`; the driver forces `nosave` onto the second declaration only when the first is saveable, so check which side saves before renaming a saved variable). (4) A nomask winner cannot be named in the leaf: move the `nomask` keyword from the module to a wrapper in the leaf (`body/cmd.lpc` -> `body.lpc`). Build the scan with the Lima driver (`LPCC=~/src/fluffos-lima/build-debug/src/lpcc`; wilderness has its own build, `~/src/fluffos-wilderness`, and the default lpcc reports "0 files compile" for it). `lima` itself is a submodule that keeps upstream's `.c` names, so its warnings are fixed by catalog patches (`libs/lima/patches/0003-0006`), made in a scratch `.lpc` copy with `scripts/submodule_patch_scratch.py build|export`; a change that must reach the player layer (`inputsys`, KB 06 §7.217) is already upstream there.

**A leaf redeclaring a name its base declares** (`prepare_spell.lpc`'s `string skill` over `spell.lpc`'s `nosave int skill`, `long_term_spell.lpc`'s `private int spell_pow` redeclared by three leaves, a MONSTER leaf's `object following` over `std/living/follow.lpc`'s `private` one): the driver gave the leaf a second variable, so the base's functions and the leaf's functions never shared it. `lpc_rename_ident.py` on the *leaf* side keeps that behaviour exactly (and a rename of a saved variable needs `nosave` on it: the driver had forced that on the second declaration anyway). The other reading, a leaf that meant to share the base's value, is the real bug: delete the leaf's declaration (darkelib `d/excelsior/workroom.lpc`: `mapping props;` over Object's `props`, read as `props["skill level"]` while the leaf's own copy was 0). Read the leaf's uses to tell which one you have.

**A sweep can damage code the scan cannot see; four shapes, found 2026-10-04 by reading the diffs and by `scripts/lpc_audit_removed_locals.py BASE`.** (1) *Creator-help examples that exist to show one compiler message* (Discworld family and skylib `d/learning/help_topics/error_messages/*.lpc`: `int x = "hi";`, `(: x :)`, `void x;`) are content: a `--fix` pass emptied five of them in skylib and in the three Discworld libs. `lpc_warnings.py` skips that directory by default and prints how many diagnostics it dropped. (2) *"Unused local variable" in a file that does not compile can be wrong*: an earlier error (`Illegal to redeclare local name 'ob'`) leaves a scope confused, and the variable is read two lines later (`office_code/lists.lpc`: `object ob = find_player(word);` became `find_player(word);` above `if (ob)`). The unused-locals pass now leaves a name alone when its scope reads it again. (3) *A local read only in an inactive branch is declared in that branch, never deleted* (spacemud `hp.lpc` `shield` under `#ifdef LIMB_SHIELDS` / `#if ADVANCEMENT_STYLE == ADVANCEMENT_RIFTS`, the `login.lpc` `foo` under `#ifdef WELCOME_DIR` in spacemud and swmud, Discworld `USE_RAMDISK`, `DISABLED` and `#ifdef 0` blocks): the audit lists every removed declaration whose function still reads the name (`BASE` = the commit before the sweep; clean over all vendored libs after these fixes). (4) *A hand-named winner takes W from the message, not from the inherit order you remember*: `room_save.lpc`'s `dest_me()` was first written `basic_room::dest_me()`; the driver had said `using the definition in /std/room/inherit/room_save.lpc`, whose `dest_me()` only flushes pending saves, so the first version changed which `dest_me()` runs. `lpc_name_winner.py` reads W from the message; recompile the pristine file and read the message before writing one by hand.

**What a first scan of an old Eastern Story / TMI lineage lib turns up besides warnings (`esI`, 2026-10-04).** (1) *One base-class line behind a thousand warnings*: `std/npc.lpc` redeclared the body's `mapping alias` and only wrote `([])` into it, so every one of the 1099 NPC leaves reported `Redeclaration of global variable 'alias'`; read the first report, not the count. (2) *Reserved words as variable names keep whole files from loading*, and the warnings the driver prints around them (`Expression has no side effects`, `Unused local variable`) are error-recovery noise: `class` (17 files), `ref` (6), `new` (1). `lpc_rename_ident.py SLUG class cls FILE...` first, rescan after. (3) *`==` typed for `=`, `{ 50; }` for `{ dam = 50; }`, `{ 40 + 15 * level; }` for `return`*: `Expression has no side effects` in a file that compiles is a gameplay bug (a bribe whose `charm` never leaves 0, a spell that needs no skill, a top damage tier that adds nothing); read every one. (4) *Two parents that both define a real hook*: `inherit "/std/seller"; inherit MONSTER;` warns `init() inherited from both` and the later inherit's `init()` silently replaces the other, so the shopkeeper never gets `buy` (and `reset()` of a seller room never respawns its objects). Naming the winner keeps the bug; the leaf defines `void init() { npc::init(); seller::init(); }` itself, as the lib's own `obj/vendor.lpc` already does. (5) *A global search-and-replace of one name renames unrelated variables*: `es1_win`'s `obj/shells/shsh.lpc` went from `buffer` (a type name here) to `buffer1` everywhere, including the separate `BUFFER` message list, so one name declared two variables; after a rename conversion read the redeclaration warnings of that file, and `tokdiff` it against a twin that kept the old names. (6) *`case:` with the label missing* (`std/priv.lpc`, `PRIVATE` lost twice) is a syntax error in a file nothing loads, so no scan counts it; `tokdiff` against the twin showed it at once. (7) *`<../x.h>` includes*: see §6.1. (8) *Tools that read line numbers*: a file with a here-document (`@C_HELP ... C_HELP`) containing a `'` or `"` blanked the rest of the file in `mask()`, and `git diff --name-only` quotes a Chinese file name unless `core.quotepath=false`, so the scan kept compiling the old text of those files; both are fixed in `lpc_warnings.py`, `lpc_src.py` and the audit script.

**Trap in `--fix`'s unused-locals pass: a declaration unused only because an `#ifdef`/`#else` branch that uses it is not compiled into *this* driver.** A variable declared before the conditional and used only inside the untaken branch looks genuinely unused to the compiler on this build, so `--fix` deletes it — but a driver built *with* that feature (a package, a `#define` some other installation sets) would then fail to compile. Real case: `merentha`'s `functionprofile.lpc` declared `object ob, *ob_list; mixed *list;` for use inside `#else` (no `__PROFILE_FUNCTIONS__` package on this driver); `--fix` deleted them as unused in round 1. The fix is to move the declaration inside the branch that uses it, not to leave it deleted — spot-check `--fix`'s unused-locals diff for any name that also appears inside an `#ifdef`/`#ifndef`/`#else` elsewhere in the same file before trusting the run.

**A formatting pass that retypes later declarators: `T *a, *b;` became `T *a, b;` (`deadsouls_fluffos`, 12 declarations).** The star is per declarator in this grammar (`new_local_def: optional_star new_local_name`), so the second name turned from an array into a plain `string`/`object`/`mixed`. Where the variable is used as an array the program stops compiling (`Type mismatch ( string vs mixed * ) when initializing tmp`, `Invalid types to '-' ( object * vs object )`, `Bad assignment ( string vs mixed * )`): in `deadsouls_fluffos` the spells daemon, the `clean` creator command and `history` did not load at all (`No program in object '/daemon/spells'`), which the warning scan reports as an *error* row with no `Redeclaration` or warning near it, so read every error row of a first scan instead of counting them as dead files. Where it is only used as a scalar-compatible `mixed`, nothing changes at run time. The fix is the star back on every later name; the hunt is a diff of every `T *a, b;` line against a sibling or `raw/` copy that still has `*b` (20 of 46 such lines in `deadsouls_fluffos` against ds386, dsIII, dsII, dsI, dshakkard, riftsds and brassring; the rest are really `string *shorts, ret;`). The current `tools/lpc-syntax` formatter keeps the stars (tested 2026-10-04), so the damage comes from an older run of it: a tree formatted before that fix is the one to audit.
