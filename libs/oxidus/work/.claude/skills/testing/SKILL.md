---
name: testing
description: Write and run unit tests for Oxidus. Covers the STD_TEST framework, test file layout under /tests/, area runners (STD_TEST_RUNNER), the runtests developer command, assertion macros, deep-equality via same(), sad-path testing via master test-mode suppression, pending() tests for known-broken boundaries, the @lpc-nocheck directive, and LPC quirks that bite tests (0 vs undefined, functional binding limits, loose array compare).
---

# Testing

You are writing or running unit tests for Oxidus. Tests live under `/tests/`, mirroring the source-tree layout, and run via the `runtests` developer command.

Follow `/lpc-coding-style` for all formatting.

## Test Integrity (Critical)

- **Never modify a test to make it pass when the underlying implementation is broken.**
- If a test fails, report the failure and the likely implementation cause — do not silently weaken assertions, loosen expected values, or wrap failures in `catch{}` to swallow them.
- A green test suite that papers over real failures is worse than a failing one.
- A test can be wrong — incorrect expectation, testing the wrong behaviour, or misaligned with the function's documented contract. Changing a test for these reasons is valid and expected.
- **The requirement is reasoning, not prohibition.** State clearly why the test is wrong before changing it. "The test fails because the implementation is broken" is not a reason to change the test. "The test asserts X but the function's documented behaviour is Y" is.
- When you discover a buggy boundary you can't or won't fix immediately, you have two valid options: (a) leave a regular `test()` that asserts the *correct* behaviour and fails loudly until the bug is fixed, or (b) use `pending()` (see below) to register the test in the suite without running it. Both keep the bug visible. The forbidden path is editing the test to assert the buggy behaviour as though it were correct.

## Framework Files

| File | Purpose |
|---|---|
| `/std/test/test.lpc` | `STD_TEST` — base for individual test files |
| `/std/test/runner.lpc` | `STD_TEST_RUNNER` — base for area runners |
| `/include/test.h` | Assertion macros (system include: `#include <test.h>`) |
| `/cmds/dev/runtests.lpc` | The `runtests` developer command |

`STD_TEST` is defined in `mudlib.h` (auto-included via `global.h`); same for `STD_TEST_RUNNER`.

## Test File Layout

Tests mirror the source path under `/tests/`. Granularity depends on what's being tested:

- **One file per source file** — e.g. testing a daemon: `/tests/adm/daemons/colour.test.lpc` for `/adm/daemons/colour.lpc`.
- **One file per function** — for many-small-functions modules like simul_efuns: `/tests/adm/simul_efun/uniform_array.test.lpc`, `/tests/adm/simul_efun/simple_list.test.lpc`, etc.

Filenames always end in `.test.lpc`.

## Required First Line

Every test file MUST begin with `// @lpc-nocheck`:

```c
// @lpc-nocheck
/**
 * @file /tests/...
 * @description Tests for ...
 */
```

The LPC LSP can't trace through the assertion macros' inheritance chain and produces noise without it. Tests still compile and run normally — this only silences the LSP.

## Test File Structure

```c
// @lpc-nocheck
/**
 * @file /tests/adm/simul_efun/uniform_array.test.lpc
 * @description Tests for the uniform_array() simul_efun.
 */

#include <test.h>

inherit STD_TEST;

void setup() {
  describe("uniform_array", ({
    test("empty array is uniform", function() {
      ASSERT_EQ(1, uniform_array(({}), "string"));
    }),
    test("uniform string array returns 1", function() {
      ASSERT_EQ(1, uniform_array(({ "a", "b", "c" }), "string"));
    }),
    test("mixed types return 0", function() {
      ASSERT_EQ(0, uniform_array(({ "a", 1, "b" }), "string"));
    }),
  }));

  describe("another group", ({
    test("...", function() { ... }),
  }));
}
```

Suites are registered in `setup()` via `describe(description, tests)` where `tests` is an array built from `test(description, function, args...)` calls. A test file may have multiple `describe()` blocks.

## Assertion Macros (`<test.h>`)

| Macro | Behaviour |
|---|---|
| `ASSERT(x)` | Passes if `x` is truthy. Writes failure message to current player. |
| `ASSERT2(x, reason)` | Same as `ASSERT` with custom failure reason. |
| `ASSERT_EQ(expected, actual)` | Throws on mismatch (caught by runner). Uses `same()` — deep equality for arrays, mappings, buffers, primitives. |
| `ASSERT_NE(expected, actual)` | Throws if values are equal. |

`ASSERT_EQ` and `ASSERT_NE` are the right tools 95% of the time — they include `__FILE__:__LINE__` and a `Expected: ... Got: ...` diff in the failure.

`ASSERT` and `ASSERT2` are older, write-based forms that don't throw — prefer the `ASSERT_EQ`/`ASSERT_NE` form.

## How `same()` Compares Values

`same(x, y, [loose=1])` is what `ASSERT_EQ` uses:

- Primitives (`int`, `string`, `float`, `object`, `function`): `==` comparison.
- Mappings: same size, same keys, same values (recursive).
- Arrays: same size; **loose** (default) ignores order; **strict** (`loose=0`) compares positionally.
- Buffers: bytewise. Cross-comparison with arrays is allowed.
- Classes: not yet implemented (errors).

> ⚠️ **Order-sensitive array tests need explicit strict comparison.** Because `ASSERT_EQ` uses loose `same()` by default, `({1,2,3})` and `({3,2,1})` will compare equal. For sort tests, slice/splice positional tests, or anywhere order matters, wrap `same_array` directly:
>
> ```c
> ASSERT_EQ(1, same_array(({ "a", "b", "c" }), result, 1));
> ```
>
> The third argument `1` flips `same_array` into strict positional mode.

## Area Runners

Each test directory needs a `runner.lpc`. Minimum content:

```c
inherit STD_TEST_RUNNER;
```

Located at `/tests/<area>/runner.lpc`. The runner globs `__DIR__/*.test.lpc`, clones each file, calls `run()`, and aggregates pass/fail counts. Override `test_dir()` only if you want the runner to scan a different directory than its own.

## Running Tests

| Command | Behaviour |
|---|---|
| `runtests` | Walks `/tests/` recursively and invokes every `runner.lpc` found. |
| `runtests <area>` | Invokes `/tests/<area>/runner` directly. Example: `runtests adm/simul_efun`. |

Output uses raw ANSI (green ✔ for passing files, red ✘ for failures) so it works in non-interactive contexts (boot, cron) where `tell()` has no target.

## Sad-Path Testing

Tests that intentionally trigger errors are first-class. The master suppresses caught-error logging while a test runner is active:

```c
test("empty input errors", function() {
  string err = catch(base64_encode(""));
  ASSERT_NE(0, err);
}),
test("invalid type errors", function() {
  string err = catch(base64_encode(42));
  ASSERT_NE(0, err);
}),
```

### How the suppression works

1. `STD_TEST_RUNNER::run_tests()` calls `master()->set_test_mode(300)` before the sweep.
2. `master::error_handler(mp, caught)` early-returns when `caught && testing_in_progress > time()` (see [adm/obj/master.lpc](adm/obj/master.lpc)).
3. After the sweep (in a `catch{}`-protected block), runner calls `master()->clear_test_mode()`.
4. **Safety net:** `testing_in_progress` is a deadline timestamp, not a boolean. Even if both layers above fail, suppression auto-expires after 5 minutes.

Only `caught=1` errors are suppressed — uncaught errors (real crashes, runner bugs) still log normally.

`set_test_mode` and `clear_test_mode` are priv-checked via `inherits(STD_TEST_RUNNER, previous_object())`; only test runners can squelch.

## Pending Tests

Use `pending(description, [reason])` instead of `test(...)` to register a test that's listed in the suite but not executed. Useful for buggy boundaries you've identified but don't want to block the suite on, or behaviour that's intentionally unimplemented.

```c
describe("insert", ({
  test("inserts at head", function() { ... }),
  test("inserts at tail", function() { ... }),
  pending("inserts at middle of single-element array",
    "delegates to push() — see array.lpc#L920"),
}));
```

The runner counts pending tests separately, prints a `Pending:` block listing each one with its reason, and the per-file summary shows e.g. `✔ array.mutation.test.lpc — 12 passed, 1 pending`. Pending tests don't run, so they can't fail and don't gate the suite.

This is the right tool when you want a **known-broken** behaviour visible in the suite without it failing the run. For behaviour you expect *should* work, prefer a regular `test()` — the failing test surfaces the bug loudly.

## Adding a New Test File

1. **Create the area runner** if it doesn't exist: `/tests/<area>/runner.lpc` containing `inherit STD_TEST_RUNNER;`.
2. **Create the test file**: `/tests/<area>/<name>.test.lpc`.
3. **Start with `// @lpc-nocheck`** on the very first line.
4. **Inherit `STD_TEST`**, register suites in `setup()` via `describe()`/`test()`.
5. **Run with `runtests <area>`** in-game to verify.

## Worked Example

```c
// @lpc-nocheck
/**
 * @file /tests/adm/simul_efun/base64.test.lpc
 * @description Tests for base64_encode() and base64_decode().
 */

#include <test.h>

inherit STD_TEST;

void setup() {
  describe("base64_encode", ({
    test("encodes 'Hello World!'", function() {
      ASSERT_EQ("SGVsbG8gV29ybGQh", base64_encode("Hello World!"));
    }),
    test("UTF-8 multibyte", function() {
      ASSERT_EQ("Y2Fmw6k=", base64_encode("café"));
    }),
    test("empty string errors", function() {
      string err = catch(base64_encode(""));
      ASSERT_NE(0, err);
    }),
  }));

  describe("base64 roundtrip", ({
    test("UTF-8 roundtrip", function() {
      string s = "Héllo, wörld! 日本語";
      ASSERT_EQ(s, base64_decode(base64_encode(s)));
    }),
  }));
}
```

Run with `runtests adm/simul_efun`.

## LPC Quirks That Bite Tests

These are LPC-specific traps that have already cost us time. Internalize them before writing tests.

### `0` is not "undefined" — be precise

LPC distinguishes between the integer `0` and a genuinely **undefined** value. They are both falsy, but only the latter satisfies `nullp()`:

| Value | `nullp()` returns |
|---|---|
| `0` (integer) | `0` |
| `""` (empty string) | `0` |
| `({})` (empty array) | `0` |
| `undefined` (the macro from `global.h`: `([])[0]`) | `1` |
| An unset/uninitialized local | `1` |

**Implication:** if you're testing a function's null-arg path (typically guarded by `assert_arg(!nullp(x), …)` or `if(nullp(x))`), passing `0` will *not* trigger that path. Use `undefined`:

```c
// Wrong — passes 0; the function accepts it as a valid value
string err = catch(every(({ 1, 2 }), 0));
ASSERT_NE(0, err);  // FAILS — 0 is a legitimate value criterion

// Right
string err = catch(every(({ 1, 2 }), undefined));
ASSERT_NE(0, err);
```

When describing return values in tests, comments, or docs, use **"returns undefined"** when that's what the function actually does — not "returns 0". They're both falsy but they're not interchangeable, and the precision matters when callers do `if(nullp(result))` vs `if(!result)`.

### A functional cannot see an enclosing local at all

FluffOS has **functionals** and **anonymous functions**, not closures, and the difference is not pedantry — a closure captures its enclosing environment, and these capture nothing whatsoever. Not read-only, not by value: an enclosing local is simply **not in scope**, and touching one is a **compile error**, not a runtime surprise.

```c
// None of these compile:
int count = 0;
each(({ 1, 2, 3 }), function(int n) { count++; });
//                                    ^ Undefined variable 'count' + Illegal lvalue

int x = 42;
function f = function(int n) { return n + x; };  // Undefined variable 'x'
function g = (: $1 + x :);                       // Illegal to use local variable in functional.
```

Anything a functional needs must be **bound into it explicitly** — `$(EXPR)` at creation, or an argument at call time:

```c
int x = 42;

f = (: $1 + $(x) :);                 // bound at creation
evaluate(function(int n, int v) { return n + v; }, 1, x);   // bound as an argument
```

`$(EXPR)` is evaluated once, where the `(: :)` is written, and its **result** is stored in the functional. It is not a link to the variable: reassigning the local afterwards is invisible to the functional. It follows ordinary LPC assignment from there — **scalars are copied, containers are shared** — which decides how you accumulate.

**Accumulating:** a bound `int` cannot work, because the copy is what gets incremented. A bound array or mapping can, because the functional holds the same structure the caller does:

```c
int *acc = ({ 0 });

each(({ 1, 2, 3 }), (: $(acc)[0]++ :));
ASSERT_EQ(3, acc[0]);                       // works -- shared structure
```

That keeps the accumulator local to the test. The alternative is a `private nosave` file-level variable reset at the top of each test, which is what to use when several tests or helpers need to see it:

```c
private nosave int _count;

void setup() {
  describe("each", ({
    test("calls callback for every element", function() {
      _count = 0;
      each(({ 1, 2, 3 }), function(int n) { _count++; });
      ASSERT_EQ(3, _count);
    }),
  }));
}
```

The arrow form `(: ... :)` has the same constraint but is terser for one-liners. Use whichever reads better.

### `ASSERT_EQ` arrays compare loosely by default

Repeated here because it bites repeatedly: `ASSERT_EQ(({1,2,3}), ({3,2,1}))` **passes**. For order-sensitive tests use `ASSERT_EQ(1, same_array(expected, actual, 1))`.

## Common Pitfalls

- **Forgetting `// @lpc-nocheck`** — the file works but the LSP nags.
- **Inheriting `STD_TEST_RUNNER` from a `*.test.lpc` file** — wrong direction. Test files inherit `STD_TEST`; runners inherit `STD_TEST_RUNNER`.
- **Calling `run()` directly without going through a runner** — works (returns `({passed, failed, failures, pendings})`) but no formatted output, no test-mode suppression for sad-path tests.
- **Long-running test sweeps** — `reset_eval_cost()` is called per file, but if a single test file's tests collectively exceed eval cost, that file fails. Split into multiple test files.
- **Mutating shared state in tests** — each test file is cloned fresh, but tests within one file share an instance. Use separate `test()` entries for state isolation, or build setup/teardown into the test function itself.

## Async Code in Tests

**Test functions and `run()` must stay synchronous.** The area runner does
`results = ob->run();` (`std/test/runner.lpc`) and uses the value immediately,
and individual test bodies are invoked as functionals — `(*f)();` in
`std/test/test.lpc`. Both close the door on `async`:

- An `async run()` would hand the runner a promise instead of a results array
  the moment it parked. Same failure class as an async apply.
- `await` is illegal inside a `(: :)` functional or an anonymous function, so a
  test body cannot await even if you wanted it to.

That means an async function under test cannot be awaited from a test. Test what
you can reach synchronously, and treat the rest as a boundary:

- **Test the synchronous prefix.** An async body runs to its first `await`
  before returning, so anything it registers first — a queue entry, an act, a
  lock — is observable the instant the call returns. `tp->async_act("x", 2.0);`
  followed by `assert(tp->is_acting())` is a valid synchronous assertion.
- **Test the pieces, not the suspension.** Factor the decision logic out of the
  async function into ordinary functions and test those directly.
- **Assert on promise state, not on delivery.** `promise_status(p)` returns 0
  pending / 1 fulfilled / 2 rejected without suspending, and `async_info()`
  lists parked frames. Reading `promise_result(p)` on a *pending* promise is an
  error, so guard it with `promise_status()`.
- **Use `pending()` for the rest.** Behaviour that only exists after a
  suspension resumes is a known-untestable boundary in this framework, not a
  test to fake with a call_out.

Do not reach for `call_out` in a test to "wait" for async work — the runner has
already collected results and destructed the test object by the time it fires.
