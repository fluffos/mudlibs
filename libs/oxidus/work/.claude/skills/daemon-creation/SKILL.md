---
name: daemon-creation
description: Create and modify daemons for Oxidus. Covers inheriting STD_DAEMON, the setup chain, persistence (setPersistent/saveData/restore_data), preloading, SWAP_D for reload-safe data, logging with EXT_LOG, and the teardown chain.
---

# Daemon Creation Skill

You are helping create or modify daemons for Oxidus. Daemons are singleton LPC objects that provide system-wide services. Follow the `lpc-coding-style` skill for all formatting.

## Architecture Overview

```
STD_OBJECT (std/object/object.lpc)
  └── STD_DAEMON (std/daemon/daemon.lpc)
        └── Your daemon (e.g., adm/daemons/my_daemon.lpc)
```

- **`STD_DAEMON`** (`#define STD_DAEMON DIR_STD "daemon/daemon"`) — inherits `STD_OBJECT` + `EXT_PERSIST_DATA`
- Daemons are loaded once and persist in memory (not cloned)
- They are accessed via `load_object()` or a `#define` constant in `<daemons.h>`

## Minimal Daemon

```c
inherit STD_DAEMON;

void setup() {
  // Your initialization here
}
```

That's it. `STD_DAEMON`'s `create()` calls `setup_chain()`, which calls your `setup()` at the right time.

## File Location

Daemons live in:

| Directory | Purpose |
|---|---|
| `adm/daemons/` | Core system daemons |
| `lib/daemon/` | Library/utility daemons |

Define a constant in `include/daemons.h` for easy access:

```c
#define MY_DAEMON_D DIR_DAEMONS "my_daemon"
```

Then other code can use: `MY_DAEMON_D->some_function()`

## The Setup Chain

When a daemon is loaded, `create()` calls `setup_chain()` which runs these functions **in order**:

| Step | Function | Purpose |
|---|---|---|
| 1 | `std_setup()` | Most basic setup. Reserved for `/std` objects. |
| 2 | `mudlib_setup()` | Low-level mudlib initialization. Used by base inheritable classes (e.g., `STD_HTTP_CLIENT` uses this). **Do not use in your daemon** unless you are writing a base class. |
| 3 | `base_setup()` | Base type setup. For intermediate inheritables. |
| 4 | `pre_setup_0` .. `pre_setup_4` | Pre-setup hooks (5 levels) |
| 5 | **`setup()`** | **Main setup — this is what your daemon implements** |
| 6 | `post_setup_0` .. `post_setup_4` | Post-setup hooks (5 levels) |
| 7 | `restore_data()` + `post_restore()` | Automatic for persistent objects |
| 8 | `mudlib_complete_setup()` | Final setup completion |

### Which function to use

- **`setup()`** — Use this for your daemon's initialization. This is the standard entry point.
- **`mudlib_setup()`** — Only use this if you are writing a base class that other daemons will inherit (like `STD_HTTP_CLIENT` does). This runs before `setup()`, so the inheriting daemon's `setup()` can rely on `mudlib_setup()` having completed.
- **`post_setup_N`** — Use when you need something to run after `setup()` completes. The numbered levels (0-4) let multiple inherits coordinate ordering.

## The Teardown Chain

When a daemon is destructed, `unsetup_chain()` runs:

| Step | Function | Purpose |
|---|---|---|
| 1 | `std_unsetup()` | Most basic teardown. Reserved for `/std` objects. |
| 2 | `mudlib_unsetup()` | Low-level teardown |
| 3 | `base_unsetup()` | Base type teardown |
| 4 | `pre_unsetup_0` .. `pre_unsetup_4` | Pre-unsetup hooks |
| 5 | `unsetup()` | Main cleanup |
| 6 | `post_unsetup_0` .. `post_unsetup_4` | Post-unsetup hooks |
| 7 | `save_data()` + `post_save()` | Automatic for persistent objects |
| 8 | `mudlib_complete_unsetup()` | Final teardown completion |

The teardown chain is a step-for-step mirror of the setup chain. Virtual objects have their own pair, `virtual_setup_chain()` / `virtual_unsetup_chain()`, with the same shape and `virtual_`-prefixed hook names.

Implement `unsetup()` if your daemon needs cleanup (e.g., closing sockets, removing call_outs).

## Persistence

`STD_DAEMON` inherits `EXT_PERSIST_DATA`, giving every daemon access to persistence. To enable it:

```c
void setup() {
  setPersistent(1);
  // ... rest of setup
}
```

### How it works

1. **`setPersistent(1)`** — Registers the daemon with `PERSIST_D` and sets a default save file path
2. **`saveData()`** — Saves all non-`nosave` global variables to disk via `save_object()`
3. **`restore_data()`** — Called automatically during `setup_chain()` if persistent, restoring saved variables
4. **`post_restore()`** — Called after `restore_data()` — implement this to act on restored data

### Save file location

By default, the save file path is derived from the object's file path (e.g., `/data/adm/daemons/my_daemon.o`). Override with:

```c
set_data_file("/data/custom/path");  // No extension needed
```

### What gets saved

All global variables **without** the `nosave` modifier are saved. Use `nosave` for runtime-only state:

```c
// Saved to disk (persistent)
private int boot_number;
private mapping config_data = ([]);

// NOT saved (runtime only)
private nosave int call_out_id;
private nosave object *cached_objects = ({});
```

### Example: Persistent daemon

```c
inherit STD_DAEMON;
inherit EXT_LOG;

private int event_count;
private mapping event_log = ([]);
private nosave int poll_id;

void setup() {
  set_log_prefix("(MY DAEMON)");
  set_log_level(1);
  setPersistent(1);

  poll_id = call_out("poll", 60);
}

void post_restore() {
  // Act on restored data
  _log(1, "Restored %d events", event_count);
}

void record_event(string type, mixed data) {
  event_count++;
  event_log[type] = data;
  saveData();  // Save immediately for critical data
}
```

### Persistence lifecycle

```
Load daemon → setup_chain() → setup() → setPersistent(1)
                             → restore_data() → reads save file
                             → post_restore() → act on restored data

During runtime:
  PERSIST_D heart_beat (every 30 ticks) → saveData() on all registered objects

On shutdown/crash:
  SIG_SYS_CRASH emitted → PERSIST_D → saveData() on all registered objects

On destruct:
  unsetup_chain() → save_data() + post_save()
```

## Logging with EXT_LOG

`STD_OBJECT` does **not** include `EXT_LOG`. If your daemon needs logging, inherit it explicitly:

```c
inherit STD_DAEMON;
inherit EXT_LOG;
```

### Logging API

```c
set_log_prefix("(MY DAEMON)");  // Prefix for all log lines
set_log_level(0);               // 0=minimal, 1=normal, 2+=verbose with call stack info

_log(1, "Simple message");
_log(2, "Detailed: %s = %d", name, value);
_log(3, "Debug: %O", some_mapping);
```

Log levels control verbosity:
- **Level 0** — Only explicit `_log(0, ...)` messages
- **Level 1** — Normal operational messages
- **Level 2** — Includes calling function name
- **Level 3** — Includes file:function:line
- **Level 4** — Includes full file path:function:line

Messages with a level higher than the daemon's `set_log_level()` are suppressed.

## SWAP_D: Preserving Data Across Reloads

When a daemon is destructed and reloaded (e.g., during development), its `nosave` state is lost. Use `SWAP_D` to preserve data across this gap:

```c
#include <daemons.h>

inherit STD_DAEMON;

private nosave mapping runtime_cache = ([]);

void setup() {
  // Retrieve data stored before last destruct
  mixed swapped = SWAP_D->swap_out("my_daemon");
  if(swapped)
    runtime_cache = swapped;
}

void unsetup() {
  // Store data before being destructed
  SWAP_D->swap_in("my_daemon", runtime_cache);
}
```

**How SWAP_D works:**
- `swap_in(label, data)` — Store data under a string label
- `swap_out(label)` — Retrieve and **remove** data (one-time retrieval)
- SWAP_D refuses cleanup while holding data

This is different from persistence — SWAP_D is for temporary, reload-safe storage of `nosave` data. Persistence (`setPersistent`) is for long-term storage across reboots.

## Preloading

Daemons that must be available at boot time are listed in `/adm/etc/preload`. They load in the order listed.

### Adding to preload

Add a line to `/adm/etc/preload`:

```
# My Custom Daemon
/adm/daemons/my_daemon
```

**No `.c` extension.** No whitespace in the path.

### Ordering constraints

The preload list has critical ordering requirements:

```
# CONFIG_D must be FIRST — nothing above it can use mudConfig()
/adm/daemons/config

# SIGNAL_D second — needed for event coordination
/adm/daemons/signal

# ... other daemons ...
```

**Rules:**
- Nothing before `CONFIG_D` can call `mudConfig()` or use anything that depends on configuration
- Nothing before `SIGNAL_D` can use `slot()` or `emit()`
- If your daemon depends on another daemon, it must come after it in the list

### Daemons that don't need preloading

Not all daemons need to be in the preload list. If a daemon is only needed on-demand, it will be loaded automatically when first accessed via its `#define` constant (e.g., `MY_DAEMON_D->func()`). Preload is only for daemons that:
- Must be available immediately at boot
- Need to register signal slots during startup
- Provide services other preloaded daemons depend on

## Signal Integration

Daemons commonly register for system signals. Use the `slot()` simul_efun:

```c
void setup() {
  slot(SIG_SYS_BOOT, "on_boot");
  slot(SIG_SYS_CRASH, "on_crash");
  slot(SIG_SYS_PERSIST, "save_state");
}

void on_boot(mixed arg...) {
  if(previous_object() != signal_d())
    return;
  // Handle boot
}
```

Common signals for daemons:

| Signal | When |
|---|---|
| `SIG_SYS_BOOT` | MUD finished booting |
| `SIG_SYS_CRASH` | System crash (save data!) |
| `SIG_SYS_PERSIST` | Periodic persist timer |
| `SIG_SYS_SHUTTING_DOWN` | Shutdown initiated |

See the `signal-system` skill for the full signal reference.

## Complete Example: A Tracking Daemon

```c
/**
 * @file /adm/daemons/tracker.lpc
 * @description Tracks player achievements
 */

#include <daemons.h>

inherit STD_DAEMON;
inherit EXT_LOG;

// Persistent — saved across reboots
private mapping achievements = ([]);

// Runtime only — not saved
private nosave int check_id;

void setup() {
  set_log_prefix("(TRACKER)");
  set_log_level(1);
  setPersistent(1);

  slot(SIG_SYS_BOOT, "on_boot");

  check_id = call_out("check_achievements", 300);
}

void post_restore() {
  _log(1, "Restored %d player records",
    sizeof(achievements));
}

void on_boot(mixed arg...) {
  if(previous_object() != signal_d())
    return;

  _log(1, "Tracker ready");
}

void record(string player, string achievement) {
  if(!achievements[player])
    achievements[player] = ({});

  achievements[player] += ({ achievement });
  saveData();
}

string *query_achievements(string player) {
  return achievements[player] || ({});
}

void check_achievements() {
  // Periodic check logic
  check_id = call_out("check_achievements", 300);
}

void unsetup() {
  if(check_id)
    remove_call_out(check_id);
}
```

## Daemon Checklist

When creating a new daemon:

1. Inherit `STD_DAEMON` (and `EXT_LOG` if you need logging)
2. Implement `setup()` for initialization
3. Decide if it needs persistence (`setPersistent(1)`)
4. Decide if it needs preloading (add to `/adm/etc/preload`)
5. Add a `#define` to `include/daemons.h` if other code will reference it
6. Use `nosave` for runtime-only variables
7. Implement `unsetup()` if cleanup is needed (call_outs, sockets, etc.)
8. Guard signal callbacks with `if(previous_object() != signal_d()) return;`

## Replacing a call_out Chain with async/await

A daemon that processes a work queue in slices — a crawl, a sweep, a rebuild —
was traditionally written as a self-re-arming call_out chain: a function that
does one unit of work then schedules itself again, plus a separate "are we
finished?" check that every step has to call. That shape exists to escape the
evaluation-cost limit, not because anyone wanted it.

An `async` function expresses the same thing as an ordinary loop, because
resuming from an `await` starts a **new delivery with a fresh evaluation-cost
budget** — the same escape, without the wall-clock tax or the plumbing:

```lpc
public async void crawl() {
  todo = ({ start });

  while(sizeof(todo)) {
    await async_yield();       // yield first: see the guard note below

    string next = todo[0];

    todo = todo[1..];
    process(next);
  }

  publish();
}
```

What disappears: the call_out handles, the delay constants, the "is a step
already scheduled?" guard, and the termination check — the loop condition *is*
the termination check.

Points that matter in practice:

- **Yield at the top of the loop, not the bottom.** The condition has just
  proved the queue non-empty, so you never suspend holding an empty queue. That
  is what lets `sizeof(queue)` stand in for "a run is in flight" without a
  separate boolean, and it also means the first item gets its own budget rather
  than riding on the caller's.
- **Wrap the body in `acatch`.** An async body behaves as if implicitly caught,
  so an error after the first `await` no longer reaches the caller's `catch` —
  without `acatch` it silently rejects a promise nobody holds.
- **Clear the queue on the error path.** If `sizeof(queue)` is your in-flight
  guard, a crashed run that leaves the queue populated locks out every future
  run.
- **A boot-slotted daemon function may be async.** `dispatch_signal()` discards
  handler return values, so the promise is simply dropped — which is fine as
  long as the body cannot reject.

Use `await call_out_walltime(n)` instead of `async_yield()` only when you want
a genuine delay (rate limiting an external service). `async_yield()` costs no
wall-clock time and still lets the driver serve players between iterations.
