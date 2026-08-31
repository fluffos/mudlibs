---
name: driver-overrides
description: Document driver efun overrides in Oxidus that change default FluffOS behavior. Covers exec, shutdown, set_privs, userp, query_num, ctime, element_of, debug_message, this_body, and this_caller — what they change and why, to prevent wrong assumptions about driver behavior.
---

# Driver Overrides Skill

This skill documents all driver efun overrides in Oxidus. These are simul_efun functions that **replace** standard FluffOS efuns with modified behavior. Knowing what's overridden prevents wrong assumptions.

## Override Summary

| Function | File | Override Type | Key Change |
|---|---|---|---|
| `exec()` | `override.lpc` | Security | Restricted to admin/ghost/user/su/link objects |
| `shutdown()` | `override.lpc` | Enhancement | Emits signal + persists before shutdown |
| `set_privs()` | `override.lpc` | Security | Admin-only, or self-claim from home path |
| `userp()` | `override.lpc` | Convenience | Optional argument (defaults to `previous_object()`) |
| `query_num()` | `override.lpc` | Enhancement | Supports negative numbers |
| `ctime()` | `override.lpc` | Standardization | Always returns `"YYYY-MM-DD HH:MM:SS"` |
| `element_of()` | `override.lpc` | Security | Optional `secure_random()` mode |
| `debug_message()` | `override.lpc` | Enhancement | Adds timestamp + file logging |
| `this_body()` | `object.lpc` | Wrapper | Semantic alias for `this_player()` |
| `this_caller()` | `object.lpc` | Wrapper | Alias for `this_player(1)` |

## Detailed Overrides

### exec(to, from)

**Driver default:** Switches the connection from one object to another.
**Override:** Restricts who can call it.

```lpc
int exec(object to, object from)
```

Only succeeds if `previous_object()` is one of:
- An admin (via `is_member(query_privs(...), "admin")`)
- `STD_GHOST` (ghost object)
- A user object (`userp()`)
- `CMD_SU` (the su command)

All other callers get `0` returned. This prevents arbitrary objects from hijacking connections.

### shutdown(how)

**Driver default:** Immediately terminates the MUD.
**Override:** Saves state and notifies listeners first.

```lpc
void shutdown(int how)
```

Only callable by `master()` or `SHUTDOWN_D`. Before calling `efun::shutdown()`:
1. Emits `SIG_SYS_SHUTDOWN` signal (notifies all registered handlers)
2. Calls `PERSIST_D->persist_objects()` (saves all persistent object data)

### set_privs(ob, privs)

**Driver default:** Assigns a privilege string to an object.
**Override:** Restricts who can assign privileges.

```lpc
void set_privs(object ob, string privs)
```

Succeeds only if:
- Caller has admin privilege, OR
- `ob` is the master object, OR
- Object's path matches `/home/%s/<name>/%s` and `name == privs` (users claiming their own privilege)

### userp(ob)

**Driver default:** Requires an object argument.
**Override:** Makes the argument optional.

```lpc
varargs int userp(object ob)
```

If `ob` is null, defaults to `previous_object()`. Then calls `efun::userp(ob)`.

This means you can write `if(userp())` inside an object to check if it's a user, without passing `this_object()`.

### query_num(x, many)

**Driver default:** Converts positive integers to English words ("five", "twenty-three").
**Override:** Adds negative number support.

```lpc
varargs string query_num(int x, int many)
```

If `x` is negative, prepends `"negative "` to the result. Takes `abs(x)` before calling the driver efun.

### ctime(x)

**Driver default:** Returns driver-default timestamp format.
**Override:** Always returns ISO-like format.

```lpc
varargs string ctime(int x)
```

If `x` is not provided, defaults to `time()`. Always returns `strftime("%Y-%m-%d %H:%M:%S", x)`.

**Important:** Code using `ctime()` anywhere in this mudlib will get `"2026-03-23 14:44:15"` format, not the driver's default format.

### element_of(arr, secure)

**Driver default:** Returns a random element from an array using standard `random()`.
**Override:** Adds a secure random option.

```lpc
varargs mixed element_of(mixed *arr, int secure)
```

- `secure = 0` (default): calls `efun::element_of(arr)` — standard random
- `secure = 1`: uses `secure_random(sizeof(arr))` — cryptographically secure

Use the secure flag when predictable randomness would be exploitable (loot drops, etc.).

### debug_message(str)

**Driver default:** Outputs to stderr/debug output.
**Override:** Adds timestamps and persistent file logging.

```lpc
void debug_message(string str)
```

1. Strips trailing newline from `str`
2. Generates timestamp: `"%Y/%m/%d %H:%M:%S"`
3. Calls `efun::debug_message()` with timestamp prepended
4. Also writes to `debug.log` via `master()->log_file()`

All debug output gets both console output AND a persistent log file.

### this_body()

**Not a driver override** — semantic wrapper.

```lpc
object this_body()
// Returns efun::this_player()
```

Use `this_body()` instead of `this_player()` throughout the codebase. It's the Oxidus convention.

### this_caller()

**Not a driver override** — semantic wrapper.

```lpc
object this_caller()
// Returns efun::this_player(1)
```

Returns the original initiator of the call chain (through force commands, shadows, etc.). Use when you need to know who *really* started an action, not just who's currently executing.

## Commented-Out Overrides

The following driver efuns have commented-out overrides in `override.lpc` that would throw `error("Use tell.")`:
- `write()`
- `say()`
- `shout()`
- `tell_object()`
- `tell_room()`

These are NOT currently active, but their presence indicates the intent: use the `tell()` family from `messaging.lpc` instead of driver messaging efuns. See the `messaging` skill.

## Key Takeaways

1. **Don't use `this_player()`** — use `this_body()` or `this_caller()`
2. **`ctime()` is not driver-default** — it always returns `"YYYY-MM-DD HH:MM:SS"`
3. **`shutdown()` is gated** — only master and SHUTDOWN_D can call it
4. **`exec()` is gated** — random objects cannot hijack connections
5. **`debug_message()` logs to file** — all debug output is persisted
6. **`element_of()` has a secure mode** — pass `1` as second arg for crypto-random
