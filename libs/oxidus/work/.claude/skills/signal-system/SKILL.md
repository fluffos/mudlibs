---
name: signal-system
description: Understand and extend the signal (event) system for Oxidus. Covers the signal daemon (SIGNAL_D), the simul_efun API (slot, emit, unslot), all signal categories and constants, persistence via SWAP_D, error handling, and every producer/consumer in the codebase.
---

# Signal System Skill

You are helping create or modify code that uses the signal (event notification) system in Oxidus. Signals provide a decoupled, system-wide pub/sub mechanism. Follow the `lpc-coding-style` skill for all formatting.

## Architecture Overview

```
Producer calls emit(SIG_*, args...)
       |
       v
simul_efun emit()                      <- adm/simul_efun/signal.lpc
       |  validates string type
       v
SIGNAL_D->dispatch_signal(sig, args)   <- adm/daemons/signal.lpc
       |
       +- iterates slots[sig] mapping
       +- for each (object, function) pair:
       |    +- validates object/function still exist
       |    +- catch(call_other(ob, func, args...))
       |    +- logs errors, continues to next handler
       v
All registered handlers receive the signal
```

## Core Files

| File | Macro | Purpose |
|---|---|---|
| `adm/daemons/signal.lpc` | `SIGNAL_D` | Signal daemon — registration, dispatch, cleanup, persistence |
| `adm/simul_efun/signal.lpc` | — | Public API: `slot()`, `emit()`, `unslot()`, `signal_d()` |
| `include/signal.h` | `SIG_*` | All signal constants and status codes |
| `include/daemons.h` | `SIGNAL_D` | Daemon path define |

## Public API (simul_efun)

These are available to all objects without any `#include` — they are simul_efuns.

### slot(sig, func)

Register the calling object to receive a signal.

```lpc
int slot(string sig, string func)
```

- `sig` — signal identifier (must use `SIG_*` macro)
- `func` — name of a function on the calling object
- Returns `SIG_SLOT_OK` (1) on success, or a negative error code
- Throws `error()` if `sig` is not a string
- One slot per object per signal — calling again overwrites the previous function
- The function must exist on the object at registration time

```lpc
// In setup() or mudlib_setup():
slot(SIG_USER_LOGIN, "onPlayerLogin");
```

### emit(sig, args...)

Broadcast a signal to all registered handlers.

```lpc
void emit(string sig, mixed arg...)
```

- `sig` — signal identifier (must use `SIG_*` macro)
- `arg...` — variable arguments passed through to all handlers
- Fire-and-forget: no return value, handler errors don't propagate
- Throws `error()` if `sig` is not a string

```lpc
emit(SIG_PLAYER_DIED, victim, killer);
```

### unslot(sig)

Unregister the calling object from a signal.

```lpc
int unslot(string sig)
```

- `sig` — signal identifier
- Returns `SIG_SLOT_OK` (1) on success
- Throws `error()` if `sig` is not a string

```lpc
unslot(SIG_USER_LOGIN);
```

### signal_d()

Returns the signal daemon object.

```lpc
object signal_d()
```

## Signal Daemon Internals (SIGNAL_D)

`adm/daemons/signal.lpc` — inherits `STD_DAEMON`.

### Internal State

```lpc
private nosave mapping slots;
// Structure: ([ "sig:name" : ([ object : "function_name" ]) ])
```

### Key Functions (all `nomask`)

| Function | Access | Purpose |
|---|---|---|
| `register_slot(sig, ob, func)` | public | Register a handler. Only callable from simul_efun |
| `unregister_slot(sig, ob)` | public | Remove a handler. Only callable from simul_efun |
| `dispatch_signal(sig, arg...)` | public | Broadcast to all handlers. Only callable from simul_efun |
| `invalidate_slots()` | private | Remove slots with dead objects or missing functions |

### Lifecycle

1. **setup()** — Loads persisted slots from `SWAP_D->swap_out("signal")`, starts heartbeat (60s), runs initial cleanup
2. **heart_beat()** — Calls `invalidate_slots()` every 60 seconds to clean dead references
3. **unsetup()** — Final cleanup, persists slots via `SWAP_D->swap_in("signal", slots)` before shutdown

### Dispatch Safety

Each handler call is wrapped in `catch()`:
```lpc
foreach(object ob, string func in sig_slot) {
  if(objectp(ob) && function_exists(func, ob)) {
    string e;
    catch(call_other(ob, func, arg...));
    if(e)
      log_file("SIGNAL_ERROR", "Error in signal dispatch: " + e);
  }
}
```

- A failing handler never prevents other handlers from running
- Errors are logged to the `SIGNAL_ERROR` log file
- Dead objects are silently skipped (cleaned up by next heartbeat)

### Security

All three public functions (`register_slot`, `unregister_slot`, `dispatch_signal`) check:
```lpc
if(previous_object() != simul_efun())
  return SIG_SLOT_INVALID_CALLER;  // or just return for dispatch
```

Only the simul_efun wrappers can call the daemon directly.

## Status Codes

Returned by `slot()` and `unslot()`:

| Constant | Value | Meaning |
|---|---|---|
| `SIG_SLOT_OK` | 1 | Success |
| `SIG_SLOT_INVALID_CALLER` | 0 | Caller was not simul_efun |
| `SIG_MISSING_SIGNAL` | -1 | Signal parameter null or not string |
| `SIG_MISSING_OBJECT` | -2 | Object parameter null |
| `SIG_MISSING_FUNCTION` | -3 | Function parameter null |
| `SIG_INVALID_FUNCTION` | -4 | Function doesn't exist in object |
| `SIG_INVALID_OBJECT` | -5 | Object is not objectp() |

## Signal Constants

All defined in `include/signal.h`. String-based identifiers with category prefixes.

### System Signals (`SIG_SYS` = `"sys:"`)

| Constant | String Value | Emitted By | Arguments | When |
|---|---|---|---|---|
| `SIG_SYS_BOOT` | `"sys:boot"` | `adm/daemons/boot.lpc` | none | MUD startup complete |
| `SIG_SYS_CRASH` | `"sys:crash"` | `adm/obj/master.lpc` | none | Crash handler triggered |
| `SIG_SYS_SHUTTING_DOWN` | `"sys:shutting-down"` | `adm/daemons/shutdown.lpc` | (int seconds) | Shutdown countdown begins |
| `SIG_SYS_SHUTDOWN` | `"sys:shutdown"` | `adm/simul_efun/override.lpc` | none | Immediate shutdown |
| `SIG_SYS_SHUTDOWN_CANCEL` | `"sys:shutdown-cancel"` | `adm/daemons/shutdown.lpc` | none | Shutdown cancelled |
| `SIG_SYS_REBOOTING` | `"sys:rebooting"` | `adm/daemons/shutdown.lpc` | (int seconds) | Reboot countdown begins |
| `SIG_SYS_REBOOT_CANCEL` | `"sys:reboot-cancel"` | `adm/daemons/shutdown.lpc` | none | Reboot cancelled |
| `SIG_SYS_PERSIST` | `"sys:persist"` | — | none | Manual persistence request |
| `SIG_SYS_CRAWL_COMPLETE` | `"sys:crawl-complete"` | `adm/daemons/crawler.lpc` | none | Room crawler finished |

### User Signals (`SIG_USER` = `"user:"`)

| Constant | String Value | Emitted By | Arguments | When |
|---|---|---|---|---|
| `SIG_USER_LOGIN` | `"user:login"` | `adm/obj/login.lpc` | (object user) | Player login complete |
| `SIG_USER_LOGOUT` | `"user:logout"` | `std/living/player.lpc` | (object user) | Player logs out |
| `SIG_USER_LINKDEAD` | `"user:linkdead"` | `std/living/player.lpc` | (object user) | Connection lost |
| `SIG_USER_LINK_RESTORE` | `"user:link-restore"` | `adm/obj/login.lpc` | (object user) | Reconnected after linkdead |

### Player Signals (`SIG_PLAYER` = `"player:"`)

| Constant | String Value | Emitted By | Arguments | When |
|---|---|---|---|---|
| `SIG_PLAYER_DIED` | `"player:died"` | `std/living/body.lpc` | (object player, object killer) | Player death |
| `SIG_PLAYER_REVIVED` | `"player:revived"` | `std/living/ghost.lpc` | (object player) | Player revival |
| `SIG_PLAYER_ADVANCED` | `"player:advanced"` | `adm/daemons/advance.lpc` | (object player, mixed level) | Level up |
| `SIG_USER_ENV_CHANGED` | `"player:env-changed"` | `cmds/dev/env.lpc` | (object user, string var, string val) | Env variable changed |
| `SIG_USER_PREF_CHANGED` | `"player:pref-changed"` | `cmds/std/set.lpc` | (object user, string pref, string val) | Preference changed |

Note: `SIG_USER_ENV_CHANGED` and `SIG_USER_PREF_CHANGED` use the `SIG_PLAYER` prefix despite having `SIG_USER` names.

### Game Signals (`SIG_GAME` = `"game:"`)

| Constant | String Value | Emitted By | Arguments | When |
|---|---|---|---|---|
| `SIG_GAME_MIDNIGHT` | `"game:midnight"` | `adm/daemons/time.lpc` | none | In-game midnight |

### Channel Signals (`SIG_CHANNEL` = `"channel:"`)

| Constant | String Value | Emitted By | Arguments | When |
|---|---|---|---|---|
| `SIG_CHANNEL_MESSAGE` | `"channel:message"` | channel modules | (mixed data) | Channel message broadcast |

## All Signal Consumers (slot registrations)

| File | Signal | Handler Function | Purpose |
|---|---|---|---|
| `adm/daemons/boot.lpc` | `SIG_SYS_BOOT` | `boot` | Increment boot counter, log |
| `adm/daemons/alarm.lpc` | `SIG_SYS_BOOT` | `execute_boot_alarms` | Run scheduled boot-time alarms |
| `adm/daemons/crawler.lpc` | `SIG_SYS_BOOT` | `crawl` | Start room crawler on boot |
| `adm/daemons/persist.lpc` | `SIG_SYS_CRASH` | `persist_objects` | Save all persistent objects on crash |
| `adm/daemons/persist.lpc` | `SIG_SYS_PERSIST` | `persist_objects` | Save on manual persist request |
| `adm/daemons/death.lpc` | `SIG_PLAYER_DIED` | `player_died` | Log death to death log |
| `adm/daemons/death.lpc` | `SIG_PLAYER_REVIVED` | `player_revived` | Log revival to death log |
| `adm/daemons/grapevine.lpc` | `SIG_USER_LOGIN` | `grapevine_send_event_players_sign_in` | Notify Grapevine network |
| `adm/daemons/grapevine.lpc` | `SIG_USER_LINK_RESTORE` | `grapevine_send_event_players_sign_in` | Notify Grapevine of reconnect |
| `adm/daemons/grapevine.lpc` | `SIG_USER_LOGOUT` | `grapevine_send_event_players_sign_out` | Notify Grapevine network |
| `adm/daemons/grapevine.lpc` | `SIG_USER_LINKDEAD` | `grapevine_send_event_players_sign_out` | Notify Grapevine of linkdead |
| `adm/daemons/modules/channel/channel.lpc` | `SIG_CHANNEL_MESSAGE` | `incomingTransmission` | Route channel messages to modules |
| `adm/daemons/modules/channel/herald.lpc` | `SIG_USER_LOGIN` | `heraldArrival` | Announce player login |
| `adm/daemons/modules/channel/herald.lpc` | `SIG_USER_LOGOUT` | `heraldDeparture` | Announce player logout |
| `adm/daemons/modules/channel/herald.lpc` | `SIG_SYS_CRAWL_COMPLETE` | `announce_crawl_complete` | Announce crawler done |
| `std/living/player.lpc` | `SIG_SYS_CRASH` | `on_crash` | Save player data on crash |
| `std/living/player.lpc` | `SIG_PLAYER_ADVANCED` | `on_advance` | Handle level advancement |
| `std/living/ghost.lpc` | `SIG_SYS_CRASH` | `on_crash` | Save ghost data on crash |

## Persistence

The signal daemon persists its slot registrations across reboots using the swap daemon:

- **On startup:** `slots = SWAP_D->swap_out("signal")` — restores previously saved slots
- **On shutdown:** `SWAP_D->swap_in("signal", slots)` — saves current slots
- **Automatic cleanup:** `invalidate_slots()` runs every 60 heartbeats to remove dead references that may exist after a reboot (objects that didn't reload)

This means objects that are persistent or reload on boot will have their slots automatically restored. Objects that don't reload will be cleaned up.

## Patterns and Best Practices

### Registering for Signals

Register in `setup()` or `mudlib_setup()` — these run when the object loads:

```lpc
#include <signal.h>

inherit STD_DAEMON;

void setup() {
  slot(SIG_USER_LOGIN, "onLogin");
  slot(SIG_USER_LOGOUT, "onLogout");
}

void onLogin(object user) {
  // Handle login...
}

void onLogout(object user) {
  // Handle logout...
}
```

### Emitting Signals

Emit from the code where the event naturally occurs:

```lpc
#include <signal.h>

// In the function where the event happens:
emit(SIG_PLAYER_DIED, victim, killer);
```

### Handler Function Signatures

Handler functions receive the variadic args passed to `emit()`. Use `mixed arg...` if you want flexibility:

```lpc
// For SIG_PLAYER_DIED which emits (object player, object killer):
void onPlayerDied(object player, object killer) {
  // Specific typed parameters
}

// Or for signals where args may vary:
void onBoot(mixed arg...) {
  // Flexible
}
```

### Unregistering

Usually unnecessary — the daemon automatically cleans up when objects are destructed. Use `unslot()` only when you need to stop receiving a signal while the object still exists:

```lpc
unslot(SIG_USER_LOGIN);  // Stop receiving login signals
```

### Adding a New Signal

1. Add the constant to `include/signal.h`:
```lpc
#define SIG_PLAYER_RESPAWNED    SIG_PLAYER "respawned"
```

2. Emit it from the appropriate code:
```lpc
emit(SIG_PLAYER_RESPAWNED, player, respawn_location);
```

3. Register handlers in any objects that need to respond:
```lpc
slot(SIG_PLAYER_RESPAWNED, "onRespawn");
```

No daemon changes needed — the signal daemon handles any string signal dynamically.

### Custom (Ad-Hoc) Signals

You can emit any string as a signal without adding it to `signal.h`. This is useful for module-specific events. Use a descriptive namespaced string:

```lpc
emit("quest:completed", player, quest_name);
```

However, prefer adding defines to `signal.h` for signals used across multiple files — the type checking enforces consistent naming.

## Key Design Points

- **Decoupled**: Producers don't know about consumers. Any object can listen to any signal.
- **One slot per object per signal**: Calling `slot()` again for the same signal overwrites the previous handler function.
- **Error-isolated**: A failing handler never blocks other handlers or the emitter.
- **Fire-and-forget**: `emit()` has no return value. Handlers cannot communicate back to the emitter.
- **String-based**: Signal identifiers are strings, enforced by `error()` in the simul_efuns. Use `SIG_*` macros.
- **Auto-cleanup**: Dead objects are pruned every 60 heartbeats. No manual cleanup needed.
- **Persistent**: Slots survive reboots via SWAP_D. Objects that reload get their slots restored.
- **Security**: Only simul_efun can call the daemon directly (`nomask` + caller check).

## Async Signal Handlers

A slotted handler may be `async`. `dispatch_signal()` invokes handlers with
`catch(call_other(ob, func, arg...))` and discards the return value, so an async
handler's promise is simply dropped and the handler runs fire-and-forget. That
is a legitimate pattern — `CRAWLER_D->crawl()` is slotted on `SIG_SYS_BOOT` and
is an async function.

Two consequences follow from the promise being discarded:

- **The dispatcher's `catch` no longer protects you.** An async body behaves as
  if implicitly caught, so any error after the first `await` rejects the
  handler's promise instead of propagating. Nothing observes that promise, so
  the failure surfaces only as an unhandled-rejection line in the debug log, far
  from the cause. Wrap the body in `acatch` and log deliberately.
- **The signal returns before the work finishes.** `emit()` completes once every
  handler has run *to its first await*. Do not slot an async handler where the
  emitter needs the work done by the time `emit()` returns — nothing in the
  signal system waits.

Everything a handler registers before its first `await` is in place by the time
`emit()` returns, so synchronous setup at the top of an async handler is still
ordered as you would expect.

See the `async-promises` skill for the model behind this — the entry-point
boundary, unhandled rejections, and how to break long handler work into pieces.
