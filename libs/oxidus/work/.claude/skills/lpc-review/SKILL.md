---
name: lpc-review
description: Review standard for Oxidus changes — what qualifies as a finding, how scope is bounded, the evidence required before asserting a failure mode, and the LPC/FluffOS semantics most often mistaken for defects. Consult before reviewing, critiquing, or reporting findings on any LPC change, diff, or pull request.
---

# Reviewing Oxidus

Oxidus is a mudlib written in **LPC**, running on the **FluffOS 2019+** driver.
It is a living, single-author game library, developed iteratively. It is not
C, not C++, not TypeScript, and not an enterprise service codebase, and review
conventions carried over from those settings mostly do not apply here.

A review of this repository has one job: identify defects the change
introduces. Everything else — shape, consistency, completeness across
surfaces, eventual direction — belongs to the author's own schedule.

## Scope

Repository knowledge, project memory, and unchanged code may be used only to
understand and validate the selected change. They do not grant permission to
review, critique, or recommend changes to anything outside it. Never report an
issue merely because it was encountered during investigation. There is no
"while you're here" category.

Report a condition only if the change **created** it. A consumer that worked
before this change and breaks after it is in scope no matter where it lives —
that is downstream, not adjacent. A condition that already existed, or that
exists only because the change has not yet been applied everywhere, is out of
scope: partial migrations, mixed conventions, and code that does not yet match
its eventual shape are states, not defects.

Every finding must state what the change did to cause the condition. If that
cannot be stated as a fact about the diff, the finding does not exist.

Two consequences worth making explicit, because they are the common failure
modes:

- **Resemblance is not evidence.** "This differs from how it is done in X" is a
  property of the gap between two files, not of either one. If the concern
  disappears when the file being compared against is set aside, it was never
  about this change.
- **Silence is not an invitation to discuss direction.** Whether an approach is
  the right one is a question the author raises when it is wanted. A change
  being provisional is not a prompt to relitigate it.

Scope of impact is a scheduling question, not a defect. That a change touches
many files, or might require follow-up elsewhere, is never a blocker and never
a finding on its own.

## What qualifies

Findings are defects in behaviour, traced to a specific path:

- Logic errors: inverted condition, wrong operator, off-by-one, a branch that
  cannot be reached.
- A dereference of null (`nullp`) or a destructed object on a path that
  actually occurs.
- Invocation of a functional that may be invalid — see `valid_function()` below.
- A caller whose contract this change broke.
- Missing permission or input validation ahead of a sensitive operation.
- A reserved type word (`buffer`, `function`, `class`, `mapping`, `object`,
  `mixed`, …) used as an identifier. These are compile errors.
- New source files using the legacy `.c` extension; the lib has migrated to
  `.lpc`.

Outside that set, and deliberately so: style, spacing, naming, documentation
format, architecture preferences, and test coverage as an abstract goal. Style
and documentation conventions are governed by other skills in
[.claude/skills/](../) — `/lpc-coding-style` and `/lpcdoc` — and a generic
guess at LPC convention will usually contradict them. Notably, private
functions here are **not** underscore-prefixed.

## How much to report

Report **every** finding that qualifies, in one pass, ordered strongest first.
There is no cap. A change with fifteen real defects should surface all fifteen
at once: the author fixes a batch, not a queue, and a review that withholds
qualifying findings to keep the list short converts one round of work into
several.

Volume is a consequence of the bar, never a target. The correct output for most
changes is **no findings at all**, and that is a complete review rather than a
failed one. A review is not scored by how much it found, so there is no reason
to reach for something to say — an empty result is the expected result when the
change is sound.

## Evidence

The whole repository is available, and so is the driver source. The driver this
lib actually runs against is a FluffOS checkout beside the lib root, at
`../fluffos` — local only, not part of this repository, so it is available to a
reviewer working on the author's machine and to nobody else. Reviewers without
it use the public `fluffos/fluffos` tree instead. Either is a semantics
reference; neither is under review.

There is no pinned driver version — the image is built from whatever
upstream FluffOS was at build time — so the driver in front of you is
authoritative.
Recent efuns, recent semantics, and language extensions added since the 2019
line are all fair to rely on, and code using them is not suspect for that
reason.

Any claim that the driver will *do* something — raise a runtime error, fail to
resolve a call, crash, truncate, coerce, reject a path — is a claim about that
source. Read the code that implements it first: the efun, the apply/call
dispatch, the relevant bytecode handler. C or C++ intuition is not evidence for
what this driver does, and neither is general LPC knowledge, since FluffOS
extends the language. If the implementing code cannot be found, the failure
mode is unconfirmed.

Proposing a defensive guard — `function_exists()`, `objectp()`, `nullp()`, or
similar — asserts a failure mode and carries the same burden. Where the driver
makes the unguarded call safe, the guard is noise.

State findings as facts. "If `foo()` returns null, this dereferences null" is
an unfinished trace: read `foo()` and its callers, and either name the real
path that reaches it or drop it. Uncertainty that cannot be resolved from the
repository lowers confidence to the point of omission; it does not become a
hedge attached to the comment. The first comment carries the validated premise
— a finding is a conclusion reached before posting, not a hypothesis refined
across a reply thread. Disagreement afterward is welcome and sometimes
correct, but it starts from a premise already established.

## LPC and FluffOS semantics

These are the facts most often mistaken for defects.

**Language shape.** `string *arr` is an array, not a pointer; LPC has no raw
pointers. Array literals are `({ ... })` and mappings are `([ key: value ])`.
There is no `main()` outside commands — entry points are lifecycle hooks
(`create`, `setup`, `init`).

**Execution model.** The driver is single-threaded and runs one execution at a
time, with no preemption. Synchronous code is first-class here. Locking, async
restructuring, and race conditions do not apply; a call is worth raising only
when its *duration* would stall the driver.

**Mid-block declarations.** C99-style declaration at first use is supported and
idiomatic. It does not need hoisting or a scope block.

**`sscanf` match counts.** Unlike C, FluffOS counts `%*s` conversions in the
return value. A format with assignment-suppressed fields returns more than the
number of values stored, so guards test the full match count.

**Path resolution.** File efuns resolve from the mudlib root; a leading `/` is
optional, and the author's convention omits it (`std/object.lpc`). Compilation
does not demonstrate path resolution in either direction.

**Security model.** Oxidus uses the FluffOS privs model, not `PACKAGE_UIDS`.
`valid_seteuid` and euid machinery never fire, and their absence is not a gap.
The defensive `set_privs("[master]")` re-assertions in
[adm/obj/master.lpc](../../../adm/obj/master.lpc) are intentional.

**Numeric coercion.** FluffOS preserves float values through int-typed locals.
`int x = <float expr>` does not necessarily truncate; confirm against the
driver before treating it as one.

**Calls to undefined functions.** `ob->foo()` and `call_other(ob, "foo")` return
`0` when `ob` does not define `foo()`; this is not a runtime error.
`apply_low()` in `src/vm/internal/apply.cc` pops the arguments and returns 0.
Duck-typed calls across mixed inventories are a normal idiom, so an unguarded
`->` is not a crash. A `function_exists()` guard is meaningful only where the
code must distinguish "absent" from a legitimately returned `0`.

**Functionals.** FluffOS has functionals, not closures — nothing captures the
enclosing scope. In `(: :)`, `$N` is a call-time positional argument and
`$(EXPR)` is a value bound at creation; `$(2)` is not `$2`. Guard invocation
with `valid_function()` rather than bare `functionp()`, which stays truthy for
functionals whose owner has been destructed.

**Truthiness.** `""` and `0.0` are truthy in LPC; only `0`, null, and undefined
are falsy. `if(!str)` does not catch an empty string. The `truthy()` / `falsy()`
simul_efuns do treat `""` as empty, so the two are chosen deliberately.

**`typeof()`** is overridden to return `T_UNDEFINED` for null, where the native
version reports an int.

**Conventions with a reason.** `pointerp()` is preferred over its alias
`arrayp()`. `mudlib.h` arrives via `global.h` and is not included directly.
Comments and documentation use lib-relative paths (`/std/object.lpc`), never
host-absolute ones, since the repository is meant to be forkable.

## How errors surface

Errors here are logged, not lost. The driver routes caught and runtime errors
through `error_handler` in
[adm/obj/master.lpc](../../../adm/obj/master.lpc), which writes a full trace to
the catch and runtime logs unconditionally. On-screen developer notification is
gated separately, on whether an interactive developer is present — so a failure
that prints nothing to a screen has still been recorded. The one exception is a
test-runner sweep, where caught errors are deliberate sad-path assertions and
suppression expires automatically.

Returning `0` or null, swallowing an error, and no-op-ing are deliberate idioms
throughout the lib: guard returns, unauthorised-caller no-ops such as the
`set_privs` override, and uniform result passthrough such as `evaluate_result`
handling `1`, `0`, and strings alike. "Fails silently" is therefore not a
defect on its own. It qualifies only with a specific traced caller that is
harmed by the swallowed signal, named alongside the concrete outcome.

Dormant-by-design scaffolding is likewise intended: unused configuration keys,
partially-wired APIs, and pinned procedural-generation seeds, which exist to
make reboots reproducible.

## Async, await, and promises

The async surface has several behaviours that read like defects and are not,
and a few genuine defects that produce no error at all. Both directions cost
review rounds, so check against this list before writing the finding.

### Not defects

- **Fire-and-forget async is idiomatic.** A sync function calling an `async`
  helper and discarding the promise — `strike(tp, victim); return 1;` — is the
  normal shape, not a leaked promise. Command entry points and applies *cannot*
  be async (the driver reads their return immediately), so the chain is
  required to terminate somewhere. In MUD code the async work is usually a side
  effect on the world, not a value for the caller.
- **`acatch` wrapping a whole async body** is usually deliberate: it guarantees
  a floated promise cannot reject, since an unobserved rejection is reported to
  the debug log at deallocation.
- **`@returns {promise<T>}` above a function declared `async T`** is correct.
  The declared type is the payload; the driver supplies the wrapper.
- **An `async` function that never awaits** is legal. It returns an
  already-fulfilled promise.
- **A rejection appearing in `/log/catch`** is documented driver behaviour — an
  async body's uncaught error is reported like a caught error — not something
  the mudlib code added.

### Genuine defects that are silent

Each of these compiles cleanly, passes a live smoke test, and reports nothing.

- **`await` on a non-promise** passes the value straight through with no
  suspension. `await call_out("fn", 1)` returns the int handle instantly; only
  the delay-only `call_out(delay)` form yields a promise. Likewise
  `await ob->missing_fn()` awaits the `0` that call_other returns.
- **A `private` call_out target declared in an inherited file never fires.**
  Name-based dispatch does not cross the inherit boundary for privates, and
  there is no error — the chain simply stops. Chain steps in anything
  inheritable must be at least `protected`.
- **`call_back()` discards an async callback's promise.** It returns
  `catch(fun(...))`, so it reports success the moment the callback parks, before
  it has done anything. `async_call_back()` is the async-aware sibling.
- **An apply or entry point that merely *returns* the result of an async call**
  is not caught by the compiler's `async`-on-apply check. Consumers treat a
  returned promise as "no": `check_valid_path()` denies, master approval gates
  deny, the parser treats a verb function as having declined the command.

### Evidence required

Do not assert that a promise leaks, a frame never resumes, or a settle races
without tracing it. Suspension state is inspectable at runtime — `async_info()`
lists every parked frame with what it awaits, and awaited timers appear in
`call_out_info()` with `"<timer>"` in the function slot. Prefer that over
reasoning about the scheduler.
