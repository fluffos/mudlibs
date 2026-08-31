---
title: Signals
description: Decoupled, system-wide pub/sub event notifications.
---

The signal system is a decoupled, system-wide publish/subscribe mechanism. Any object can broadcast a signal, and any object can subscribe to receive it -- the two never need to know about each other. Signals are not tied to location: an object anywhere in the game can react to an event emitted anywhere else.

## How It Works

A producer calls `emit()` with a signal identifier and optional arguments. The call passes through a simul_efun to the signal daemon (`SIGNAL_D`), which looks up every object subscribed to that signal and calls its registered handler:

1. A producer calls `emit(SIG_PLAYER_DIED, victim, killer)`
2. The `emit()` simul_efun validates the signal and forwards to `SIGNAL_D`
3. The daemon iterates every `(object, function)` pair registered for that signal
4. Each handler is called inside `catch()` -- a failing handler is logged and skipped, never blocking the others
5. Dead objects are silently ignored and pruned on the next cleanup pass

It is fire-and-forget: `emit()` has no return value, and handlers cannot communicate back to the emitter.

## The API

All three functions are simul_efuns -- available to every object with no `#include` required:

| Function | Signature | Purpose |
|---|---|---|
| `slot(sig, func)` | `int slot(string sig, string func)` | Register the calling object to receive `sig`, dispatched to `func`. Returns `SIG_SLOT_OK` (1) or a negative error code. |
| `emit(sig, args...)` | `void emit(string sig, mixed arg...)` | Broadcast `sig` with optional arguments to all handlers. |
| `unslot(sig)` | `int unslot(string sig)` | Unregister the calling object from `sig`. |
| `signal_d()` | `object signal_d()` | Returns the signal daemon object. |

All three throw `error()` if `sig` is not a string. There is **one slot per object per signal** -- calling `slot()` again for the same signal overwrites the previous handler.

## Signal Identifiers

Signals are namespaced strings, defined as `SIG_*` macros in `include/signal.h`. The category prefix groups related events:

| Prefix | Macro | Example |
|---|---|---|
| `sys:` | `SIG_SYS` | `SIG_SYS_BOOT` -> `"sys:boot"` |
| `user:` | `SIG_USER` | `SIG_USER_LOGIN` -> `"user:login"` |
| `player:` | `SIG_PLAYER` | `SIG_PLAYER_DIED` -> `"player:died"` |
| `game:` | `SIG_GAME` | `SIG_GAME_MIDNIGHT` -> `"game:midnight"` |
| `channel:` | `SIG_CHANNEL` | `SIG_CHANNEL_MESSAGE` -> `"channel:message"` |

### Common Signals

| Constant | Arguments | When |
|---|---|---|
| `SIG_SYS_BOOT` | none | MUD startup complete |
| `SIG_SYS_CRASH` | none | Crash handler triggered |
| `SIG_SYS_SHUTTING_DOWN` | `(int seconds)` | Shutdown countdown begins |
| `SIG_USER_LOGIN` | `(object user)` | Player login complete |
| `SIG_USER_LOGOUT` | `(object user)` | Player logs out |
| `SIG_USER_LINKDEAD` | `(object user)` | Connection lost |
| `SIG_PLAYER_DIED` | `(object player, object killer)` | Player death |
| `SIG_PLAYER_ADVANCED` | `(object player, mixed level)` | Level up |
| `SIG_CHANNEL_MESSAGE` | `(mixed data)` | Channel message broadcast |

The full list lives in `include/signal.h`.

## Registering for a Signal

Register in `setup()` (or `mudlib_setup()`) so the slot is established when the object loads. The handler receives whatever arguments the emitter passed:

```lpc
#include <signal.h>

inherit STD_DAEMON;

void setup() {
  slot(SIG_USER_LOGIN, "on_login");
}

void on_login(object user) {
  // React to the player logging in...
}
```

Use typed parameters when you know the signal's argument shape, or `mixed arg...` when it varies:

```lpc
void on_boot(mixed arg...) {
  // SIG_SYS_BOOT carries no arguments
}
```

## Emitting a Signal

Emit from the point where the event naturally happens:

```lpc
#include <signal.h>

emit(SIG_PLAYER_DIED, victim, killer);
```

## Unregistering

You usually do not need to -- the daemon prunes handlers automatically when their object is destructed. Call `unslot()` only to stop receiving a signal while the object is still alive:

```lpc
unslot(SIG_USER_LOGIN);
```

## Adding a New Signal

No daemon changes are needed -- `SIGNAL_D` dispatches any string dynamically.

1. Add a constant to `include/signal.h`:

   ```lpc
   #define SIG_PLAYER_RESPAWNED    SIG_PLAYER "respawned"
   ```

2. Emit it where the event occurs:

   ```lpc
   emit(SIG_PLAYER_RESPAWNED, player, location);
   ```

3. Register handlers in any object that should respond.

You can also emit an ad-hoc namespaced string (e.g. `emit("quest:completed", player, quest)`) without a define, but prefer a `SIG_*` macro for any signal shared across files.

## Persistence and Cleanup

`SIGNAL_D` survives reboots by persisting its registrations through the swap daemon -- slots are saved on shutdown via `SWAP_D` and restored on startup. Objects that reload on boot get their slots back automatically. A heartbeat runs `invalidate_slots()` every 60 seconds to drop any registration whose object was destructed or whose handler no longer exists.

Only the simul_efun wrappers may call the daemon directly -- the public daemon functions are `nomask` and reject any other caller.

## Key Files

| File | Role |
|---|---|
| `adm/daemons/signal.c` | `SIGNAL_D` -- registration, dispatch, cleanup, persistence |
| `adm/simul_efun/signal.c` | Public API: `slot()`, `emit()`, `unslot()`, `signal_d()` |
| `include/signal.h` | All `SIG_*` constants and status codes |
| `include/daemons.h` | `SIGNAL_D` daemon path define |
