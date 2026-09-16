---
name: async-promises
description: Understand and write asynchronous code in Oxidus. Covers the promise type and promise<T> payloads, the async modifier, await, acatch, where suspension is legal, the entry-point boundary, hand-built promises, the combinators (promise_all/any/race/all_settled), cancellation, async_yield scheduling, async_info, resource limits, and every way async code fails.
---

# Async and Promises Skill

You are helping create or modify asynchronous code in Oxidus. FluffOS provides
native coroutines: a first-class `promise` value, an `async` function modifier,
an `await` expression that suspends without blocking the driver, and `acatch`,
the suspension-safe form of `catch`. Follow the `lpc-coding-style` skill for all
formatting.

Async is **not** a better default than synchronous code. The driver is
single-threaded and stays that way; `async` buys you two things and nothing
else:

1. **Suspension without blocking** — a wait for real elapsed time or real I/O
   during which the driver keeps serving everyone else.
2. **A fresh evaluation-cost budget per resumption** — long work split into
   separately-metered pieces instead of one run that dies on "too long
   evaluation".

If a function needs neither, write it synchronously.

## When to Reach for It

| Situation | Reach for |
|---|---|
| A timed wind-up on a living | `await tp->async_act(action, delay)` |
| A pause with no act attached | `await call_out_walltime(secs)` |
| File or directory I/O off the main thread | `await async_read/async_write/async_getdir` |
| Long computation that must not stall the mud | a loop with `await async_yield()` |
| Fan out work and collect it | `promise_all` / `promise_all_settled` |
| Delivering a callback's result to a caller | `async_call_back()` |
| A driver apply, a command entry point, a verb function | **none of the above** — see **The Entry-Point Boundary** |

## The `promise` Type

A promise is a first-class value holding the eventual result of an operation.
It is created pending and settles **exactly once** — fulfilled with a value, or
rejected with a reason.

`promise` is a declared type like `mapping` or `object`, and it is
**parameterised by the payload it will eventually deliver**:

```lpc
promise<mapping> fetch(string uid);   // return type
private void handle(promise<int> p);  // parameter
promise<int> *pending = ({});         // array of promise<int>
promise<string *> names;              // one promise delivering an array
promise anything;                     // bare promise == promise<mixed>
```

`promise<T> *` and `promise<T *>` are different types: the first is an array of
promises, the second is one promise that delivers an array.

Payload rules worth knowing:

- Any type may be a payload — `class` types included — except `void` and
  `promise` itself. Resolving a promise with a promise **adopts** it, so a
  promise value is never itself a promise.
- Assignment compares payloads. `promise<int>` and `promise<string>` are
  incompatible; bare `promise` accepts either.
- `await` yields the payload type, so `int n = await fetch_count();` type-checks
  and `string s = await fetch_count();` does not.
- `typeof()` returns `"promise"` — the kind, not the payload. Use `promisep()`
  for the type test.
- Promises compare by identity, work as mapping keys, deep-copy shallowly like
  objects, and are **not serialised by `save_object()`**. Never `save_var()` a
  promise; see the `persistence` skill.

## Writing an `async` Function

`async` is a function modifier and sits where any other modifier sits. It does
**not** change the declared return type — `async int f()` still checks
`return 1;` against `int` — but every call site receives `promise<int>`.

```lpc
private async void collect_dir();     // a prototype must agree about async
public async int async_act(string action, float delay) {
```

Three rules the compiler enforces:

- **A prototype must agree with its definition about `async`.**
- **An override must agree with the inherited function about `async`**, in both
  directions. This is an error rather than a warning because nothing checks it
  at runtime: handing a promise to call sites compiled against `int` makes
  `if(f())` unconditionally true and errors on the first arithmetic, far from
  the cause.
- The modifier propagates through inheritance and applies on every call path —
  direct calls, `::`-qualified calls, `call_other()`, and function pointers.

**The body runs synchronously until its first `await` of a promise.** The caller
gets the promise at that moment — already fulfilled if the body finished without
awaiting anything, pending otherwise. This is load-bearing: everything an async
helper registers before its first `await` is in place by the time its caller
continues.

`return value` fulfils the promise, and a returned promise is adopted. An
uncaught error inside the body **rejects** it rather than propagating — an async
body behaves as if wrapped in an implicit `catch`. `throw(value)` rejects with
`value`.

The promise **belongs to the body**. `promise_resolve()` and `promise_reject()`
refuse a promise that came from an `async` function, because settling it would
discard whatever the body goes on to return and would not stop the body running.
To ask a body to stop, see **Cancellation** below.

## `await`

`await expr` is a unary prefix expression. It takes a space after it like
`return` does, and binds tighter than binary operators — `await a + b` parses as
`(await a) + b`, so parenthesise when that is not what you mean.

```lpc
int completed = await tp->async_act("punch", 2.0);
```

- A **non-promise** operand passes through unchanged. Awaiting a plain value is
  a no-op, not a scheduling point.
- A **promise always suspends**, even one that has already settled. The function
  resumes from the microtask drain with a fresh evaluation-cost budget,
  receiving the value — or with the rejection raised at the await point.

Because a resume is a microtask rather than a timer, a sequential loop of
`await`s runs at full speed with no wall-clock delay per iteration. That is also
why a plain `await` is **not** a way to hand the event loop a turn — see
**Scheduling and Yielding**.

While suspended, the object stays fully live. Incoming calls run normally, there
are no re-entrancy locks, and each async call has its own suspension state, so
concurrent invocations do not interfere. `this_body()` across a suspension
follows the same driver option as `call_out()` callbacks (`this_player in
call_out`, enabled by default), so it is restored on resume.

## `acatch`

`acatch` is `catch` for code that may suspend, with the same value convention —
`0` on success, the error value otherwise. It takes an expression or a block;
the block form **ends with a semicolon**, because it is an expression:

```lpc
mixed err = acatch {
  paths = await async_getdir(current);
};

mixed err = acatch(await tp->async_act("punch", 2.0));
```

An error raised inside the region reaches it whether it was raised
synchronously or arrived as the rejection of an awaited promise, even one that
settles long after the function suspended.

**A rejecting body decides whether it logs, and the caller cannot change that.**
The `lpc-coding-style` skill covers the base rule — a caught `error()` still
reaches the master's `error_handler()` and so lands in `/log/catch` with a
dev-wide notification, while a caught `throw()` does not. What async adds is
*when* that happens. The body's implicit catch reports the error **at the moment
it rejects, inside the body's own frame**: the caller's `acatch` is not even on
the traceback, and observing the rejection suppresses nothing.

So a rejection the caller is expected to handle must be raised with `throw()`
**in the body** — choosing at the catch site is too late. This catches any efun
error inside an async body too, which is a large share of unplanned rejections:
a bad argument deep inside an async helper pages the whole dev team even when
its caller handles the rejection perfectly. The `testing` skill's test-mode
suppression exists because of this path.

**One rejection never reaches an `acatch`.** If an awaited promise is garbage
collected while still pending — its last reference dropped, so it can never
settle — the parked frame is abandoned rather than resumed, and the async
function's own promise is rejected with `*awaited promise was collected before
settling`. There is no resume, so nothing inside the function runs. Observe that
case on the returned promise instead.

## Where `await` and `acatch` Are Legal

### Compile-time

- Only **directly inside an `async` function body**. Never in a `(: :)`
  functional or an anonymous function — those run in their own frames — and
  never at top level.
- `await` is not allowed inside `catch(...)` or `time_expression(...)`, whose
  implementations recurse the C++ stack. Use `acatch`.
- `break` / `continue` may not jump out of an `acatch` region, the same rule as
  `catch`. `return` works normally.

### Runtime: what an `await` can suspend across

An `await` cannot suspend while a transient reference sits on the value stack
that suspension cannot relocate. This is a runtime error rather than a compile
error because it depends on what the awaited expression turns out to be.

**A `foreach` over a local loop variable is fine** — arrays, mappings, strings,
buffers, nested loops included. That variable's lvalue addresses a slot inside
the frame, and the frame is exactly what parking copies and rebuilds.

```lpc
async void reindex(mixed *rows) {
  foreach(mixed row in rows) {     // local loop variable: parks correctly
    index(row);
    await async_yield();
  }
}
```

Still refused:

| Shape | Why |
|---|---|
| `foreach` over a **global** loop variable | its lvalue points into the object's variable block, a second relocation base |
| a **`ref`** loop variable or `ref` argument | owns heap state tied to the C++ frame |
| a string-char or buffer-byte lvalue (`s[i]`, `b[i]`) | backed by shared VM scratch state, one instance at a time by construction — permanently refused |

Compound assignment is **not** affected. `arr[i] += await p` and `s += await p`
evaluate the right-hand side before pinning the target, so they park and resume
normally.

## The Entry-Point Boundary

**Anything whose return value a caller reads immediately must not be `async`.**
An async function hands back a promise the instant its body parks — before it
has decided anything — and a consumer that treats an unrecognised value as
permissive reads that as "yes".

This covers driver applies, command entry points, verb functions, `id()`, and
test functions. The pattern is always the same: keep the entry point
synchronous and have it call an async helper **without awaiting it**.

```lpc
private async void strike(object tp, object victim);

public mixed main(object tp, string str) {
  object victim = find_target(tp, str);

  if(!victim)
    return "Attack whom?";

  strike(tp, victim);        // async, deliberately not awaited

  return 1;
}
```

The compiler enforces this **as far as a name can**: `async` on an object apply
(`create`, `init`, `id`, `heart_beat`, …) is an error, and on a master-only
apply (`valid_read`, `error_handler`, `compile_object`, …) a warning, since on
any other object that name is the author's to use.

**Treat that check as a lint, not a boundary.** It keys on the declaration, so
it does not catch an ordinary apply that returns the result of an async call —
`mixed id(string s) { return slow(); }` — and it cannot cover `add_action()`
verb functions at all, whose names are arbitrary. The real enforcement is at the
consumers, which refuse a promise on the principle that *a function that has not
answered has not said yes*:

- `check_valid_path()` denies a `valid_read()` / `valid_write()` returning one.
- Every master approval gate — `valid_bind`, `valid_shadow`, `valid_socket`,
  `valid_object`, `valid_link`, `valid_hide`, `valid_override` — denies and
  names itself in the log.
- The command parser treats a verb function returning one as having **declined**
  the command, moving on to the next sentence on that verb and eventually
  `notify_no_command()`.
- `present()` does not match an object whose `id()` returns one, and the parser
  does not set `living` / `inventory_accessible` / `inventory_visible` /
  `livings_are_remote` from one.

Two consequences for the fire-and-forget helper:

- **Nothing observes its promise**, so an uncaught error surfaces only as an
  unhandled-rejection line in the debug log, far from the cause. Wrap the body
  in `acatch` and log deliberately.
- **Its synchronous prefix still runs in order**, so registering an act,
  emitting a message, or setting a flag before the first `await` all happen
  before the entry point returns.

See the `command-creation` skill for the command-side detail and the
`signal-system` skill for the same boundary at `emit()`.

## Building and Settling Promises by Hand

| Efun | Purpose |
|---|---|
| `promise_create()` | a new pending `promise<mixed>` |
| `promise_resolve(p, value)` | fulfil it (a promise value is adopted) |
| `promise_reject(p, reason)` | reject it |
| `promise_then(p, on_ok, on_err)` | attach handlers, returning a chained promise |
| `promise_catch(p, on_err)` | the rejection-only half of `promise_then` |
| `promise_status(p)` | `0` pending, `1` fulfilled, `2` rejected |
| `promise_result(p)` | the value or reason; an error while pending |
| `promisep(v)` | the `*p()` type test |

Settlement delivery is **never synchronous**: `promise_then()` handlers and
suspended `await`s always run from the microtask drain, in attachment order,
each with a fresh evaluation-cost budget.

Two rules that differ from JavaScript and bite hard:

- **Settling an already-settled promise is an error, not a silent no-op.** Any
  hand-rolled race must guard with `promise_status()` on both paths — the second
  one to finish is the common case, not a rare one. Prefer `promise_race()`,
  which does this for you.
- **`promise_resolve()` / `promise_reject()` refuse an `async` function's own
  promise.** Only its body settles it.

The canonical Oxidus pattern for bridging a callback API into an async function
is a *separate* hand-built promise, resolved from the callback and awaited by
the body — `std/living/act.lpc`:

```lpc
public async int async_act(string action, float delay) {
  promise p = promise_create();
  mixed id = act(action, delay, assemble_call_back((: promise_resolve($(p), $1) :)));

  if(nullp(id))
    return 0;

  return await p;
}
```

Note `$(p)` — bound when the functional is created, not the call-time `$1`.
FluffOS has functionals, not closures: nothing captures the enclosing scope, so
anything a `(: :)` needs must be bound into it explicitly.

## Combining Promises

All four take an array and return a promise. A **non-promise element counts as
already fulfilled with itself**, so the output of an ordinary `map()` drops
straight in without wrapping. Results are **positional**: entry `i` corresponds
to `promises[i]`, whatever order they settled in.

| Efun | Fulfils when | Rejects when | Empty array |
|---|---|---|---|
| `promise_all` | every input fulfils | the **first** input rejects | fulfils with `({})` |
| `promise_any` | the first input **fulfils** | **every** input rejects, with an array of reasons | rejects |
| `promise_race` | the first input **settles**, either way | the first input settles, if it rejected | **error** |
| `promise_all_settled` | every input settles — it never rejects | never | fulfils with `({})` |

```lpc
mixed *rows = await promise_all(map(names, (: fetch($1) :)));
```

`promise_all_settled` fulfils with one mapping per input, using
`promise_status()`'s vocabulary:

```lpc
([ "status": 1, "value":  v ])   // fulfilled — no "reason" key
([ "status": 2, "reason": r ])   // rejected  — no "value" key
```

Reach for it instead of `promise_all` when a partial failure is a **result**
rather than an error, which is the usual case when fanning work out over many
rooms or objects.

Three things none of them do:

- **No cancellation.** Losing inputs to a race keep running and their results
  are discarded. A race stops your *waiting*, never the work.
- **`promise_race` on an empty array is a hard error**, deliberately unlike
  JavaScript. A promise that can never settle, once awaited, is a parked frame
  holding its object, its program and one suspension slot for the life of the
  driver — so the mistake is refused where it is made. The reason reaching an
  enclosing `acatch` is the string
  `"*promise_race: needs at least one promise; an empty array would never settle.\n"`
  — and because it is an `error()` rather than a `throw()`, catching it still
  logs and pages the devs, per **`acatch`** above. Guard the array instead.
- **No payload typing.** They are declared `promise` (that is, `promise<mixed>`),
  so the result needs a `mixed *` on the receiving end.

### Bounding a wait with a timeout

`promise_race()` against a timer is how you put a ceiling on an operation whose
own promise you do not control. The timeout arm **must reject with `throw()`,
not `error()`** — the two are equivalent to the caller's `acatch` except that
`error()` writes a traceback to `/log/catch` and pages every online developer
for what is a routine outcome. See **`acatch`** above.

```lpc
#define ERR_TIMEOUT "timed out"

private async int timeout_after(int secs) {
  mixed err = acatch(await call_out(secs));

  if(err)
    return 0;            // cancelled: settle quietly, do not re-raise

  throw(ERR_TIMEOUT);

  return 0;
}

public async void fetch_with_ceiling() {
  promise timer = timeout_after(10);
  mixed result;
  mixed err = acatch {
    result = await promise_race(({ timer, do_work() }));
  };

  if(!err) {
    promise_cancel(timer);              // work won; release the loser
    handle(result);
  } else if(err == ERR_TIMEOUT) {
    tell(this_body(), "That took too long.\n");
  } else {
    tell(this_body(), `It failed: ${err}\n`);
  }
}
```

**Signal the timeout by rejecting, not by fulfilling with a sentinel.** An arm
that *fulfils* with `-1` when the real answers are strings, or `"timed out"`
when they are ints, forces the caller to tell the two apart by value shape.
That couples the timeout signal to the work's return type, so it breaks
silently the moment the work returns `mixed`, legitimately returns the
sentinel, or you race two arms of different types.

Rejecting collapses the success case to nothing: a fulfilled race means the
work won, full stop — `!err` is the whole test, and `result` is the work's own
value at its own type.

The rejection branch is where the discrimination actually lives, because **the
work can reject too**. Give the timeout a defined reason constant —
`ERR_TIMEOUT` above — and test the reason against it. The rejection reason is a
channel of your own, so nothing the work returns can collide with it, and a
constant survives someone rewording the message.

Note the constant carries no `*`. That prefix belongs to the driver: it marks
a reason the driver authored, and it is how you tell one of its outcomes from
one of yours. Those reasons are named in `include/driver/promise.h` — see **Driver
rejection reasons** below, and the `lpc-coding-style` skill for the convention.

Do **not** discriminate with `promise_status(timer)` instead. It looks
equivalent — `PROMISE_REJECTED` for a timer that rejected and so won,
`PROMISE_PENDING` for one still pending — but a losing timer keeps running and
rejects on its own schedule, so a work
failure at t=9.99 against a 10s timer reads back as `2` and reports a timeout
that never happened. The status is a live value; the reason is a fact about the
settle that actually won.

Three more things this shape is getting right:

- **Pass promises, not functionals.** `promise_race(({ (: timeout_after, 1 :), … }))`
  does not race anything — a non-promise element counts as **already fulfilled
  with itself**, so the race fulfils instantly with the functional itself. It fails
  by silently succeeding with garbage, which is the worst way to fail. Call the
  functions; do not name them.
- **Cancel the loser when the winner is the work.** The losing timeout keeps
  running and holds a suspension slot until its delay elapses. Its eventual
  rejection is *not* reported as unhandled — the race attached a handler, which
  counts as observing it — so this is a resource point, not a noise one, and it
  only matters when the timeout is long.
- **The timeout body catches its own cancellation** and returns rather than
  re-raising. Without that `acatch`, cancelling the loser merely swaps one
  rejection for another.

## Cancellation

`promise_cancel(p)` asks the `async` function body that owns `p` to give up: its
**next `await` raises** a catchable value — the reason `PROMISE_REASON_CANCELLED`
(`include/driver/promise.h`). It returns `1` if a cancellation was armed and `0` if
there was nothing left to cancel — a body racing its canceller to completion is
a normal outcome, not an error.

**A cancel costs you nothing in the logs.** It is delivered through the driver's
throw path, not `error()`, so it never reaches `error_handler()`: no traceback,
no `/log/catch` entry, no dev notification. `promise_cancel()` also marks the
promise handled, so a fire-and-forget cancel does not produce an
`Unhandled promise rejection` line either. Cancelling on purpose is silent, as
routine control flow should be.

Four properties to hold onto:

- **It is cooperative, not preemptive.** A body part-way through straight-line
  code finishes that stretch first, and one that never awaits again runs to
  completion with the cancellation never delivered. Nothing is torn down
  mid-expression.
- **The request is consumed by the raise.** A body that catches its own
  cancellation may go on to `await` cleanup work and even return a value, in
  which case its promise *fulfils* normally. Cancellation is a request a body
  may decline. Cancel again if you mean it again.
- **It does not propagate.** If a cancelled body was awaiting another async
  function's promise, that inner body keeps running — its promise is
  first-class and may have other awaiters. A body that wants the inner work
  stopped catches its own cancellation and cancels the inner promise it holds.
- **It unwinds properly.** The raise travels through enclosing `acatch` regions
  and runs `defer()` handlers in order on the way out, exactly like any other
  rejection arriving at that `await`.

It is an **error** to cancel a promise that is not an async function's — only a
body has a "next await" for the cancellation to arrive at. That rules out
`promise_create()` promises, `async_read`/`async_write`/`async_getdir` promises
(the worker thread is already doing the I/O), `call_out(delay)` promises (use
the classic `call_out()` form and `remove_call_out()`), and `promise_then()`
chain links.

For a timed act on a living, note there are now two different interruptions and
they are not interchangeable: `cancel_act()` interrupts **the act**, which
fulfils `async_act()`'s promise with `0` and lets the caller handle the
interruption normally; `promise_cancel()` interrupts **the awaiting body**,
raising at its next `await`. Prefer `cancel_act()` for anything the game world
does to a character. See the `combat-system` skill.

## Scheduling and Yielding

```lpc
await async_yield();              // zero delay; let the event loop have a pass
await call_out_walltime(0.05);    // real elapsed time; rate limiting
await call_out(2);                // same, quantised to the gametick
```

`async_yield()` is the **cooperative preemption point**. It costs no wall-clock
time but its promise settles from the event loop's own post-poll queue, so the
driver reads network input, queues commands and fires timers before the function
resumes.

A plain `await` does not do this — the resume is re-queued into the *same* drain
turn, which is deliberate, and is what lets a sequential `await` loop run at full
speed. `await call_out(0)` is not a substitute either: a `call_out(0)` runs on
the same gametick, and `call_out(0) nest level` refuses one used as a yield
inside a loop. `await call_out(1)` does reach the loop but costs a whole
gametick.

So: for **long work that must not stall the mud**, yield periodically. This is
the pattern in `adm/daemons/crawler.lpc`:

```lpc
while(sizeof(todo)) {
  await async_yield();
  // ... one unit of work
}
```

Prefer this over a chain of `call_out`s that re-arm themselves. It reads as a
loop, keeps its state in locals instead of object globals, and is metered per
resumption.

**The callback forms are not awaitable.** `call_out("fn", 1)` still returns an
int handle, and `await` of a non-promise passes the value through with no
suspension — so `await call_out("fn", 1)` compiles, returns instantly, and does
nothing. Only the delay-only forms return a promise. The language server warns
on operands that can never be a promise; heed it.

The promise form of `call_out` returns **no handle**, so a timer you may need to
cancel individually must use the classic form.

## Watching the Scheduler

`async_info()` is the async counterpart of `call_out_info()`. With no argument
it returns one mapping per suspended frame, oldest first, with `"id"`,
`"object"`, `"function"`, `"file"`, `"line"`, `"promise"`, `"awaiting"`,
`"ready"` and `"acatch_depth"`.

With a non-zero argument it returns a single mapping describing the scheduler:
`"suspended"`, `"pending_deliveries"`, `"drain_yields"`, `"drain_eval_budget"`
and `"drain_arms_loop"`.

**A steadily rising `drain_yields` with a non-zero `pending_deliveries` is
backpressure** — async work arriving faster than it is delivered. That is the
number to look at when the mud feels sluggish under async load.

A frame stops being listed the moment its object is destructed, and does not
hold a suspension slot against live frames.

## Resource Limits

Each suspended function holds a heap copy of its frame, so the number of
concurrently suspended async functions is bounded by the driver option
**`max suspended async functions`** (default 10000; `0` disables). An `await`
that would exceed it raises a clean error at the await point instead of
suspending — catchable with `acatch`, otherwise rejecting that function's
promise. It is a runaway guard: a loop spawning async calls that never settle
hits a bounded error rather than eating memory.

`await async_yield()` holds a slot while parked like any other `await`, but only
between the yield and the loop's next pass.

Sustained async work runs the driver at 100% of one core rather than leaving it
idle between batches. That is intended behaviour, and worth knowing on a
co-tenanted host.

## How Async Code Fails

| Failure | What you see | What to do |
|---|---|---|
| Uncaught `error()` in an async body | the promise rejects **and** `/log/catch` gets a traceback with a dev-wide notification, observed or not | raise expected conditions with `throw()` in the body |
| Rejection nothing ever observes | additionally `Unhandled promise rejection (…): reason` in the debug log at deallocation — so an `error()` rejection logs through **both** paths | observe it, or reject with `throw()` |
| Awaited promise garbage collected while pending | the function's promise rejects with `PROMISE_REASON_AWAITED_COLLECTED`; **no `acatch` inside the function runs** | observe the returned promise |
| Object destructed while suspended | the resume is abandoned and the promise rejects | see the `defer()` caveat below |
| Object recompiled or `replace_program()`ed while suspended | same | reload deliberately, not mid-flight |
| `max suspended async functions` exceeded | clean error at the await point | find the leak with `async_info()` |
| Eval-cost overrun | **never** swallowed by an async body or `acatch`, matching `catch` | split the work with `await async_yield()` |

**`defer()` and destruction.** Handlers registered before an `await` survive the
suspension and run when the function finally finishes, including when it is
abandoned because its object was recompiled. They do **not** run in two cases:
when the object was destructed (frames are abandoned partway through teardown,
where running mudlib code is not safe — and a handler written the natural way is
a function pointer whose owner is now destructed, which the driver refuses to
call anyway), and when the awaited promise was garbage collected. **Do not rely
on `defer()` for cleanup that must survive the owner being destructed
mid-`await`** — put that cleanup in an object that outlives the operation.

Driver shutdown discards queued deliveries without running them, like pending
`call_out()`s.

### Driver rejection reasons

The driver rejects with a fixed set of constant strings, named in
`include/driver/promise.h` (pulled in by `<global.h>`, so they are always in
scope). That header is a verbatim copy of the driver's own
`src/include/promise.h`, which the driver `#include`s and rejects with — so the
names below cannot drift from what actually arrives. Compare against the
constant, never the literal:

```lpc
mixed err = acatch(await worker());

if(err == PROMISE_REASON_CANCELLED)
  return;                       // asked to stop; not a failure
else if(err)
  _error(this_body(), `Worker failed: ${err}`);
```

The same header names `promise_status()`'s return codes — `PROMISE_PENDING`
(0), `PROMISE_FULFILLED` (1), `PROMISE_REJECTED` (2). The driver's own state
field is typed from those three, so they cannot drift either.

| Constant | Raised when |
|---|---|
| `PROMISE_REASON_CANCELLED` | `promise_cancel()` reached the body's next `await` |
| `PROMISE_REASON_DESTRUCTED` | the suspended body's owner was destructed |
| `PROMISE_REASON_RECOMPILED` | the owner was recompiled while suspended |
| `PROMISE_REASON_REPLACED_PROGRAM` | the owner's program was replaced while suspended |
| `PROMISE_REASON_STACK_OVERFLOW` | no stack left to rebuild the frame on resume |
| `PROMISE_REASON_AWAITED_COLLECTED` | the promise a body was parked on died unsettled |
| `PROMISE_REASON_ADOPTION_COLLECTED` | a resolve-with-promise source died unsettled |
| `PROMISE_REASON_COLLECTED` | a combinator input died unsettled |
| `PROMISE_REASON_SELF_RESOLVED` | `promise_resolve(p, p)` |
| `PROMISE_REASON_ANY_EMPTY` | `promise_any()` over an empty array |
| `PROMISE_REASON_YIELD_SHUTDOWN` | an `async_yield()` was still queued at shutdown |
| `PROMISE_REASON_NO_REASON` | `promise_reject(p)` called with no reason |

All of these are delivered outcomes, not faults — they arrive at an `await` or
`acatch` like any other rejection and none of them reach the error handler.
Only `PROMISE_REASON_CANCELLED` is one you asked for; the rest mean something went
wrong. `PROMISE_REASON_NO_REASON` exists so a bare `promise_reject(p)` is never falsy,
which would read as success through `acatch`.

## Oxidus Helpers

- **`async_act(action, delay)`** — `std/living/act.lpc`.
  The async counterpart of `act()`. The act is registered exactly as `act()`
  registers it, so `is_acting()` reports it and `cancel_act()` still interrupts
  it; the promise fulfils with `1` if it ran to completion and `0` if it was
  cancelled. Prefer it over a bare `await call_out_walltime(delay)` for a
  wind-up, which registers no act and would let the character act freely during
  it.
- **`async_call_back(cb, args...)`** — `adm/simul_efun/function.lpc`.
  The async counterpart of `call_back()`. Where `call_back()` reports only
  whether the callback errored, this delivers what it returned and waits for it:
  if the callback is itself an async function, the promise adopts its promise. A
  rejection that is never observed is reported to the debug log, so do not call
  it and discard the result.
- **`async_read` / `async_write` / `async_getdir` / `async_db_exec`** — with the
  trailing callback **omitted**, each returns a promise fulfilled with the value
  the callback would have received, or rejected with the failure value:
  `string s = await async_read(path);`. Their completions arrive from outside
  gametick dispatch, so they are delivered on the event loop's next pass rather
  than waiting for the next gametick.

Adding a new async sefun means adding its prototype — `async` included — to
`adm/include/simul_efun.h`. Nothing at runtime
catches drift.

## Checklist

Before reporting async work as done:

- [ ] No apply, command entry point, verb function or `id()` is `async`.
- [ ] Every fire-and-forget async helper wraps its body in `acatch`.
- [ ] Prototypes and overrides agree with their definitions about `async`.
- [ ] Every hand-rolled settle either guards with `promise_status()` or uses a
      combinator.
- [ ] No `promise_resolve()` / `promise_reject()` targets an async function's
      own promise.
- [ ] `promise_race()` is never handed a possibly-empty array.
- [ ] Driver rejection reasons are compared against the `include/driver/promise.h`
      constants, not against the literal strings.
- [ ] Long loops yield with `await async_yield()`, not a plain `await`.
- [ ] Cleanup that must survive destruction is not in a `defer()` inside the
      suspended object.
- [ ] `fluffos_validate` passes, and behaviour is verified in-game — a clean
      compile proves nothing about scheduling. See the `mud-telnet` skill.
