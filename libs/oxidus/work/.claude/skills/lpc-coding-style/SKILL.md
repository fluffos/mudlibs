---
name: lpc-coding-style
description: LPC coding style and formatting conventions for this project. Consult when writing or modifying any LPC code — covers spacing, indentation, braces, naming, control flow, and idiomatic patterns.
---

# LPC Coding Style Guide

This document prepares an LLM for how code should be written in LPC for this project.

## Language and Spelling

Use **Canadian English** spelling throughout all code, comments, documentation, strings, and file names. Key examples:

- colour (not color)
- behaviour (not behavior)
- honour (not honor)
- favourite (not favorite)
- centre (not center)
- defence (not defense)
- analyse (not analyze)
- catalogue (not catalog)
- modelling (not modeling)
- travelling (not traveling)
- initialise/initialisation are acceptable but initialize/initialization is also fine (both are used in Canadian English)

This applies to identifiers (variable names, function names, file names), comments, strings, and documentation.

## Spacing

- Use 2 spaces for indentation.
- Use spaces around operators and after commas.
- No trailing spaces at the end of lines.
- Files must end with a single trailing newline.
- No more than 1 consecutive empty line.
- Use a single space after `//` for comments.
- NO space after `#` for preprocessor directives.
- Use a single space before and after `=` for assignments.
- Use a single space after `,` for function arguments and parameter lists.
- NO space before or after `;` for statement terminators.
- NO space after `(` and before `)` for function calls and definitions.
- NO space after `{` and before `}` for blocks.
- NO space after `[` and before `]` for array indexing.
- NO space after `.` for member access.
- NO space after `->` for pointer member access.
- Use a single space before and after `?` and before and after `:` for ternary operators.
- NO space after `!` for negation.
- Always a single space before an opening brace `{`.

### Keyword Spacing

Control-flow keywords that take a parenthesised condition attach directly to it — no space before `(`:

- `if(`, `for(`, `while(`, `switch(`, `foreach(`

Keywords that sit between blocks or before a brace get a space on both sides:

- `} else {`, `} else if(`, `do {`
- `} catch {`, `} catch(`

Keywords that precede an expression get a space after:

- `return expr;`, `case VALUE:`, `error("...");`

## Bracing Style

- Opening braces for control structures are placed on the same line as the statement.
- Closing braces get their own line unless followed by an `else` or similar continuations.
- **Single-statement bodies do NOT use braces.** Place the body on the next line, indented.
- **Consistency rule:** If ANY branch in an `if`/`else if`/`else` chain requires braces (because it has multiple statements), then ALL branches in that chain use braces. For `switch`, braces are per-case — only the specific `case` that needs multiple statements gets braces; other cases in the same switch remain braceless.
- Examples:

  ```lpc
  // Single-statement if — no braces
  if(condition)
    do_something();

  // Single-statement if/else — no braces
  if(condition)
    do_something();
  else
    do_other_thing();

  // Multi-statement branch — ALL branches get braces
  if(condition) {
    do_something();
    do_more();
  } else {
    do_other_thing();
  }

  // Single-statement while — no braces
  while(condition)
    do_something();

  // Single-statement for — no braces
  for(int i = 0; i < sz; i++)
    do_something(i);

  // Switch: single-statement cases — no braces
  switch(value) {
    case 1:
      do_something();
      break;
    case 2:
      do_other_thing();
      break;
    default:
      do_default();
      break;
  }

  // Switch: multi-statement case — that case gets braces
  switch(value) {
    case 1: {
      do_something();
      do_more();
      break;
    }
    case 2:
      do_other_thing();
      break;
  }
  ```

## Declarations

FluffOS LPC now supports C-style mixed declarations. Declare things close to where they are first used for clarity, unless grouping them helps readability.

### Variables

Prefer declaring locals near their first use inside the narrowest scope that makes sense. Group related locals together when it improves readability. Global variables may be declared anywhere before use; placing them together near the top of the file is still helpful for discoverability.

Always use an explicit visibility modifier (`private`, `protected`, or `public`) on file-global variables. Global variables should be `private` by default. Only widen to `protected` or `public` when external objects or inheritors genuinely need direct access (which is rare — prefer accessor functions).

File-global variables are preferred to be prefixed with `__` (double underscore). This is a soft preference, not a hard rule — existing files without the prefix are fine and need not be churned. When you do use it, it serves three purposes: collision reduction when multiple inherits define similarly named variables, shadow evasion so locals never accidentally mask a global, and clear taxonomy — a `__` prefix immediately signals "file-global" at every use site. Favour adding it on new globals; leave established bare names alone unless you're already reworking that file.

```lpc
private nosave mapping __cmd_handlers = ([]);
private string *__cmd_paths = ({});
private nosave string *__cmd_history = ({});
```

### Functions

Forward declarations at the top of the file are recommended when functions are referenced before their definitions. They are no longer strictly required by the driver but can improve clarity in larger files.

Always use an explicit visibility modifier (`private`, `protected`, or `public`) on both forward declarations and function definitions. The modifiers mean:

- **`private`** — only callable within the defining object. Use by default for internal helpers, parsing routines, and implementation details.
- **`protected`** — callable by the defining object and any object that inherits it, but not by external callers. Use for functions that inheritors need to call or override.
- **`public`** — callable by any object. Use for the object's external API — functions meant to be called via `call_other` / `->`.

Default to `private`. Widen to `protected` or `public` only when there is a concrete need.

#### Choosing the modifier — by call mechanism

"Concrete need" is decided by *how* the function is reached, which is a
caller fact, not a style preference. Map it directly:

- Reached via `call_other` / `ob->fn()` / `master()->fn()` → must be
  **`public`**; only `public` survives a `call_other`. (Verify by
  grepping for `->fn` / `master()->fn`.)
- Called by an inheriting object as an inherited lfun (e.g. `master.lpc`
  inherits `valid.lpc` and calls `parse_group();` at boot) → **`protected`**;
  `private` is file-scope only and would hide it from the inheritor.
- Called only within the defining file → **`private`**.
- **Driver applies** (`valid_*`, `create`, `heart_beat`, `setup`, etc.) →
  the driver invokes these directly and ignores our visibility entirely,
  so make them **`private`** like any other internal function. Do *not*
  widen an apply just because "the driver calls it."

When unsure whether something has an external caller, grep for it
(`->name`, `"name"`, `master()->name`) rather than guessing — examining
adjacent files reveals convention, not the inheritance topology or call
sites that actually determine visibility.

## Naming Conventions

### snake_case (Primary Convention)

All identifiers use **snake_case** (lowercase words separated by underscores):

- **Function names:** `query_name()`, `set_value()`, `find_target()`, `calculate_damage()`
- **Variable names:** `max_health`, `current_enemy`, `regen_interval`, `attack_speed`
- **Function parameters:** `object target_object`, `string player_name`, `int damage_amount`

Accessor functions use the prefix `query` rather than `get`:
- `query_level()`, `query_name()`, `query_max_hp()`

Mutator functions use the prefix `set`:
- `set_level()`, `set_name()`, `set_max_hp()`

### Private Functions

Do **not** use an underscore `_` prefix to denote private functions — the `private` keyword is sufficient. Private helpers follow the same snake_case convention as all other functions.

### Local Variable Names

Do **not** name a local variable the same as any function in scope. This avoids shadowing and potential confusion. Choose a distinct name instead.

### Unused Parameters

When a function signature requires a parameter that the body does
not use (e.g., `caller` in `query_help`), prefix the name with `_`
to suppress the LSP "declared but never read" diagnostic:

```lpc
string query_help(object _caller) {
```

This convention applies only to **parameters** that must exist for
signature compatibility. Do not use `_` prefixed local variables
elsewhere.

### Renaming Functions

When renaming a function (e.g., converting from `snake_case` to `camelCase`, or any other rename), you **must** search the entire codebase for all call-sites and update them. This includes:

- Direct calls: `function_name()`
- `call_other` string references: `call_other(ob, "function_name")`
- Arrow calls: `ob->function_name()`
- String literals used as function names in mappings, callbacks, `call_out`, `evaluate`, signal slots, etc.

Use Grep to find all occurrences of the old name before making the change. A renamed function with stale call-sites will cause runtime errors.

### Exceptions

- **Constants** (`#define`) use `ALL_CAPS_WITH_UNDERSCORES`: `MAX_LEVEL`, `COLOUR_D`
- **Class names** use PascalCase (uppercase first letter): `ClassGMCP`, `ClassEvent`
- **GMCP handler functions** use PascalCase to match protocol convention: `Hello()`, `Supports()`, `Items()`

### Examples

```lpc
// Function names
mixed query_effective_boon(string cl, string type) { ... }
void process_expired_buffs() { ... }
object find_nearest_enemy(object tp) { ... }

// Variable names
int regen_interval;
string target_name;
mapping current_enemies = ([]);
float attack_speed = 2.0;

// File-global variables (soft __ preference)
private nosave mapping __current_enemies = ([]);

// Constants
#define MAX_CAPACITY 100
#define COMBAT_TICK_RATE 2
```

## Control Structures

- For switch statements, the `case` keyword is not indented, but case content is indented one level.
- Always include a `default` case in switch statements when appropriate.
- Switch bracing follows the rules in the **Bracing Style** section above — see there for examples.

## Blank Line Padding

Use blank lines to give code room to breathe. The rules below keep control blocks visually separate from the code around them.

### After control blocks

Always place a blank line **after** the closing of these control structures (unless the next line is itself a closing brace):

- `if` / `else if` / `else` chains
- `while` loops
- `for` / `foreach` loops
- `switch` statements
- `do` / `while` loops

### Before `return`

Always place a blank line **before** a `return` statement, unless the `return` is the only statement in the block.

### General

- No more than 1 consecutive empty line anywhere in a file.
- Use blank lines between logical sections of code (variable groups, setup blocks, etc.).

### Examples

```lpc
void do_work(int value) {
  if(value < 0)
    value = 0;

  string result = process(value);

  if(result) {
    log(result);
    notify(result);
  }

  for(int i = 0; i < sizeof(items); i++)
    handle_item(items[i]);

  return result;
}

// return as only statement — no blank line needed
int query_value() {
  return value;
}
```

## Comments

- File headers use block comments to describe the file's purpose.
- Function documentation is placed directly above the function definition.
- Use line comments (`//`) for inline clarifications.
- Complex algorithms should be explained with comments.
- Comment style should follow LPCDoc conventions for public APIs.

## Error Handling

Prefer returning a value — a message, `undefined`, `0` — when the condition is
ordinary control flow. When you must raise, LPC has two mechanisms and they are
not interchangeable. Choose by whether the condition is a **bug** or an
**outcome**.

- **`error()` — a hard error.** Contract violations and impossible states: a
  bad argument, a missing object the caller promised. Prefer `assert_arg()` for
  argument validation; it is a hard error too. Document with `@errors`.
- **`throw(value)` — a soft error.** Conditions the caller is expected to
  handle: a lookup that misses, a timeout, a race you meant to lose. It carries
  an arbitrary value rather than a message, so **that value is part of your
  API** — prefer a `#define`d constant over a prose string a caller would have
  to match on. Document with `@throws`.

Two consequences decide most cases:

- **A hard error is loud even when caught.** The driver builds a full stack
  trace and hands it to the master's `error_handler()` with `caught = 1`, and
  Oxidus writes it to `/log/catch` *and* notifies every online developer. A
  caught `throw()` never reaches `error_handler()` at all. Raising a routine,
  handled outcome with `error()` therefore pages the whole team.
- **The `*` prefix belongs to the driver.** It prepends one to every `error()`
  — `simulate.cc`, "all system errors get a * at the start" — so a leading `*`
  means *this came from the error machinery*. Never hand-write one onto a
  thrown value; it misrepresents a soft error as a system fault.

Use `catch` to handle either, or `acatch` in code that may suspend, and log with
enough information to debug from. See the `async-promises` skill for how this
plays out across a promise boundary, where the choice is made in the body and
the caller cannot change it.

## Type Handling

- Use explicit type checks where necessary (e.g., `objectp()`, `stringp()`, etc.).
- For array type checks, **prefer `pointerp()` over `arrayp()`** — both work and are aliases in FluffOS, but `pointerp` is the project convention.
- Prefer null-safe code using `nullp()` checks rather than relying on implicit conversions.
- When working with potentially missing or undefined values, check with `nullp()` before use.
- After testing for null, you can then use `intp()` to check if the value is an int, particularly when validating call_other function arguments.

### `0` is not "undefined"

LPC distinguishes between the integer `0` and a genuinely **undefined** value. They're both falsy, but only the latter satisfies `nullp()`:

| Value | `nullp()` returns |
|---|---|
| `0` (integer) | `0` |
| `""` (empty string) | `0` |
| `({})` (empty array) | `0` |
| `undefined` (the macro from `global.h`: `([])[0]`) | `1` |
| An unset/uninitialised local | `1` |

This matters in two places:

1. **When you write a function that has "no answer" to return**, prefer `return undefined;` over letting the function fall through to an implicit `0`. Callers can then test `nullp(result)` reliably to distinguish "no answer" from "the answer is zero". Implicit fall-through returns 0, which is *also* a valid integer, so callers can't tell them apart.

2. **When you write or document a function**, describe the return value as **"returns undefined"** when that's what it does — not "returns 0". They're not interchangeable. A caller doing `if(!result)` accepts both, but `if(nullp(result))` only accepts genuine undefined. Precision in the description sets the right caller expectations.

### Inline Type Annotations for Object Parameters

When a function parameter is typed as `object` but you call methods
specific to a particular class (e.g., `set_env`, `query_pref`), the
LSP cannot resolve those methods. Use an inline `/** @type */`
comment to narrow the type for the LSP:

```lpc
mixed main(/** @type {STD_PLAYER} */ object caller, string str) {
  caller->set_env("colour", "on");   // LSP can resolve this now
}
```

Go shallowest first — pick the shallowest macro the object is known
to be (shallow in the inherit-traversal sense: `STD_PLAYER` is
shallower than `STD_BODY` is shallower than `STD_OBJECT`). Reason
from where the object comes from, not from the methods this function
happens to call: a parameter fed by `main()` in a `cmds/adm/` or
`cmds/dev/` command is a player, whatever the body does with it.
Same principle as LPCDoc `@param` type selection (see the lpcdoc
skill). Common macros: `STD_PLAYER`, `STD_BODY`, `STD_NPC`,
`STD_OBJECT`, `STD_ROOM`, `STD_CONTAINER`.

This annotation is a comment and has no effect on compilation — it
exists solely to give the LSP enough information to validate
`call_other` calls on the parameter.

This is especially useful for ubiquitous functions like `main()` in
commands — `main()` is the only possible entry point and exists in
every command file, so writing an LPCDoc block for it is pointless
boilerplate. The inline `@type` annotation gives the LSP what it
needs without adding a redundant doc comment.

## File Organisation

- Each file should have a header comment describing its purpose and author.
- Header includes come first.
- **Don't include headers that are already auto-included via `<global.h>`** — the driver config sets `<global.h>` as the global include, and `/include/global.h` pulls in `<mudlib.h>`, `<dirs.h>`, `<colour.h>`, `<daemons.h>`, and several others. Re-including any of these is noise. If unsure whether a header is already in scope, grep `/include/global.h`.
- Inherit statements, if necessary, follow header includes.
- Forward declarations come next.
- Global variables follow forward declarations.
- Helper/utility functions placed at the bottom of the file.
- Primary functions should be at the top of the file.
- Related functions should be grouped together.
- Keep file length manageable — consider splitting very large files (>1000 lines) into modules.

## Special LPC Features

### Efuns and Apply Functions

- Driver efuns (built-in functions) are called directly without a namespace.
- Apply functions (like `init()`, `heart_beat()`) are special methods called by the driver — don't rename these.
- Simulated efuns may be provided by the mudlib and called as global functions.

### Inheritance and Object References

- Use the available macros when inheriting (e.g., `inherit STD_ROOM;`).
- When inheriting, use standard method calling convention for inherited functions (e.g., `::setup();`).
- For loading objects, prefer `load_object()` for static instances and `clone_object()` for creating new instances.
- Use `this_object()` to refer to the current object and `previous_object()` for the calling object.

### LPC-Specific Data Handling

- Use `copy()` when returning mappings or arrays to avoid reference issues, unless you want to share the reference.
- Prefer explicit casting (e.g., `to_int()`, `to_string()`) over implicit type conversion.
- Use varargs for optional parameters: `varargs void func(int required, int optional)`
- The rest operator `...` can be used to handle variable argument lists, but only if the function is declared with `varargs`, and the syntax is `varargs void func(int required, int optional...)`.
- The spread operator `...` can be used to handle variable argument lists, and the syntax is `func(x, arg....)` where `arg` is an array of arguments to be spread by the function.

### Call Methods

- Use `call_other(obj, "func", args...)` or `obj->func(args...)` for dynamic method calls.

## Defensive Programming

- Validate all inputs, especially those from user input or network sources.
- Check for null with `nullp()` before operations that might fail on null values.
- For user-provided objects, verify they exist with `objectp()` before use.
- When dealing with user input, never trust it — sanitise it first.

## Line Width

- Lines should be comfortable to read at a glance. Most lines
  naturally fall well under 80 columns; that's fine and normal.
- Don't wrap a line that reads cleanly just because it crosses a
  column threshold. A 90-character line in a block of one-liners
  reads better than an awkwardly broken 78-character one.
- When a line is genuinely hard to parse at a glance, the fix is
  usually structural — extract an intermediate variable, simplify
  the expression, or break a chain of calls into steps. Mechanical
  line-breaking is a last resort.
- If nothing structural helps and you must wrap, somewhere around
  80 columns is a reasonable guide — but use judgment, not a ruler.
- This applies to LPC source files and LPML data files alike.

## Performance Considerations

- Avoid expensive operations in frequently called functions.
- Cache results of expensive calculations where appropriate.
- Be mindful of eval cost limits for complex operations.
- Use call_out, or call_out_walltime for delayed execution rather than busy
  loops. For work that must be broken into pieces — a crawl, a sweep, a long
  build — prefer an `async` function with `await async_yield()` over a chain
  of call_outs that re-arm themselves; see the `async-promises` skill.
- Prefer filter/map/member_array over manual iteration where appropriate.

## Async, await, acatch

The full model — promises, the combinators, cancellation, scheduling and the
ways async code fails — lives in the `async-promises` skill. What follows is
only how it is *written*.

`async` is a function modifier and goes where any other modifier goes. It does
not change the declared return type — `async int f()` still checks `return 1;`
against `int` — but every call site receives `promise<int>` instead. A prototype
must agree with its definition about `async`, and an override with the function
it overrides.

```lpc
private async void collect_dir();          // prototype must agree about async
public async int async_act(string action, float delay) {
```

`await` is a prefix unary expression, so it takes a space after it like `return`
does, and binds tighter than binary operators — `await a + b` is `(await a) + b`.
Parenthesise when that is not what you mean.

```lpc
int completed = await tp->async_act("punch", 2.0);
```

`acatch` is `catch` for code that may suspend, with the same value convention
(`0` on success, the error otherwise). It takes an expression or a block; the
block form ends with a semicolon because it is an expression:

```lpc
mixed err = acatch {
  paths = await async_getdir(current);
};

mixed err = acatch(await tp->async_act("punch", 2.0));
```

`await` and `acatch` are legal **only directly inside an `async` body** — never
in a `(: :)` functional or an anonymous function, and never inside `catch(...)`
or `time_expression(...)`. An apply, a command entry point, a verb function or
anything else whose return value a caller reads immediately must **not** be
`async`; have it call an async function instead.

Reach for `async` when a function must suspend without blocking the driver, or
when long work needs a fresh evaluation-cost budget per piece. Sync is the
default, not the fallback — see the `async-promises` skill before writing
either.
