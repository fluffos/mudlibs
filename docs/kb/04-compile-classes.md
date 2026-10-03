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
