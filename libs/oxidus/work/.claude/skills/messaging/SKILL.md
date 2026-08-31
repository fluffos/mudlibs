---
name: messaging
description: Understand and use the messaging system for Oxidus. Covers tell functions (tell, tell_up, tell_down, tell_all, tell_me, tell_them), the containment hierarchy, message reception and processing (EXT_MESSAGING), action messages (simple_action, targetted_action, etc.), system feedback (_ok, _error, _warn, _info), message type flags, and color/accessibility handling.
---

# Messaging Skill

You are helping write or modify code that sends messages to players, NPCs, or objects in Oxidus. The messaging system is containment-aware and accessibility-friendly. Follow the `lpc-coding-style` skill for all formatting.

## Architecture Overview

```
Game code calls tell(), tell_all(), simple_action(), _ok(), etc.
       |
       v
Simul_efun layer                       <- adm/simul_efun/messaging.lpc, system.lpc
       |                                  adm/daemons/action.lpc
       v
EXT_MESSAGING receive functions          <- std/ext/messaging.lpc
  receive_direct / receive_up / receive_down / receive_all
       |
       v
do_receive()                           <- core message processor
  +- color preference check
  +- COLOUR_D->bodyColourReplace()     <- body-specific color substitution
  +- COLOUR_D->substituteColour()      <- color code encoding
  +- LINES_D->substitute_lines()       <- line-drawing char substitution
  +- receive(message)                  <- driver efun, sends to connection
  +- event("message", ...)             <- fires message event
  +- telnet_ga() if MSG_PROMPT
```

## Core Files

| File | Purpose |
|---|---|
| `adm/simul_efun/messaging.lpc` | `tell`, `tell_direct`, `tell_up`, `tell_down`, `tell_all`, `tell_me`, `tell_them` |
| `adm/simul_efun/system.lpc` | `_ok`, `_error`, `_warn`, `_info`, `_question`, `_debug`, `debug` |
| `adm/daemons/action.lpc` | `simple_action`, `my_action`, `other_action`, `target_action`, `my_target_action`, `targetted_action`, `compose_message` |
| `std/ext/messaging.lpc` | `EXT_MESSAGING` — `receive_up`, `receive_down`, `receive_all`, `receive_direct`, `do_receive` |
| `include/messaging.h` | Message type flag defines |

## Quick Reference: Which Function to Use

| Scenario | Function | Example |
|---|---|---|
| Send text to one object | `tell(ob, msg)` | `tell(tp, "Hello.\n")` |
| Send text to yourself | `tell_me(msg)` | `tell_me("You feel warm.\n")` |
| Send text to everyone else in room | `tell_them(msg)` | `tell_them("Bob waves.\n")` |
| Actor does something (actor + room) | `simple_action(msg, obs...)` | `tp->simple_action("$N $vpick up $o.", sword)` |
| Only actor sees | `my_action(msg, obs...)` | `tp->my_action("$N $vfeel a tingle.")` |
| Only others see | `other_action(msg, obs...)` | `tp->other_action("$N $vsnore loudly.")` |
| Actor + target + others all see | `targetted_action(msg, target, obs...)` | `tp->targetted_action("$N $vkick $t.", victim)` |
| Only target sees | `target_action(msg, target, obs...)` | `tp->target_action("$N $vwhisper to $t.", target)` |
| Actor sees target-relative msg | `my_target_action(msg, target, obs...)` | `tp->my_target_action("You kick $t.", target)` |
| Success feedback | `_ok(msg)` or `_ok(ob, msg)` | `_ok(tp, "Quest complete!")` |
| Error feedback | `_error(msg)` | `_error("Target not found.")` |
| Warning | `_warn(msg)` | `_warn(tp, "Low health!")` |
| Info | `_info(msg)` | `_info(tp, "New area unlocked.")` |
| Question/prompt | `_question(msg)` | `_question("Are you sure?")` |
| Debug | `_debug(msg)` | `_debug("var = %O", var)` |

## Tell Functions (simul_efun)

All are simul_efuns — available everywhere without `#include`.

### tell(ob, msg, msg_type)

The primary messaging function. Sends a direct message to one object.

```lpc
varargs void tell(mixed args...)
```

Three calling styles:
- `tell("message")` — sends to `previous_object()`
- `tell(ob, "message")` — sends to specific object
- `tell(ob, "message", msg_type)` — with message type flags

Internally calls `tell_direct()`.

### tell_me(msg, msg_type)

Sends to `this_body()` (the player executing the current command).

```lpc
varargs void tell_me(string str, int message_type)
```

### tell_them(msg, exclude, msg_type)

Sends to everyone in the room except `this_body()` and any excluded objects.

```lpc
varargs void tell_them(string str, object *exclude, int message_type)
```

Uses `tell_all()` on the environment, auto-excludes `this_body()`.

### tell_direct(ob, msg, msg_type)

Sends directly to one object. No containment propagation.

```lpc
varargs void tell_direct(object ob, string str, int msg_type)
```

### tell_up(ob, msg, msg_type, exclude)

Sends upward through the containment hierarchy — from object to its environment, then to all contents of that environment, recursively up.

```lpc
varargs void tell_up(object ob, string str, int msg_type, mixed exclude)
```

### tell_down(ob, msg, msg_type, exclude)

Sends downward — to all objects contained within `ob`, recursively into nested containers.

```lpc
varargs void tell_down(object ob, string str, int msg_type, mixed exclude)
```

### tell_all(ob, msg, msg_type, exclude)

Sends in all directions — up to environment, down to contents, propagating through the full containment tree. Prevents double-delivery via exclude list.

```lpc
varargs void tell_all(object ob, string str, int msg_type, mixed exclude)
```

## Message Type Flags

Defined in `include/messaging.h`. Combined with bitwise OR.

| Flag | Value | Purpose |
|---|---|---|
| `DIRECT_MSG` | `1<<0` | Direct message (no propagation) |
| `UP_MSG` | `1<<1` | Upward propagation |
| `DOWN_MSG` | `1<<2` | Downward propagation |
| `ALL_MSG` | `1<<3` | All-direction propagation |
| `NO_COLOUR` | `1<<10` | Disable color substitution |
| `MSG_PROMPT` | `1<<11` | Send telnet go-ahead after message |
| `MSG_COMBAT_HIT` | `1<<20` | Combat hit message |
| `MSG_COMBAT_MISS` | `1<<21` | Combat miss message |

Direction flags are set automatically by the tell functions. Use `NO_COLOUR`, `MSG_PROMPT`, and combat flags explicitly:

```lpc
tell(tp, "Enter password: ", MSG_PROMPT);
tell(tp, "Raw text\n", NO_COLOUR);
```

## Message Reception (EXT_MESSAGING)

All objects inherit `EXT_MESSAGING` (via `std/object/object.lpc`). It provides:

### Control Functions

```lpc
set_contents_can_hear(int flag)    // Allow/block messages propagating to inventory
set_environment_can_hear(int flag) // Allow/block messages propagating to environment
query_contents_can_hear()          // Default: 1
query_environment_can_hear()       // Default: 1
```

### do_receive() — The Core Processor

Every message ultimately reaches `do_receive(message, message_type)` which:

1. Checks user color preference (`query_pref("colour")`)
2. If color is on: applies body-specific color replacements via `COLOUR_D->bodyColourReplace()`
3. Applies color encoding via `COLOUR_D->substituteColour()` (or strips colors if off)
4. Handles accessibility: screen reader mode, UTF-8/ASCII line-drawing substitution
5. Calls `receive(message)` — the driver efun that sends bytes to the connection
6. Fires a `"message"` event if body exists
7. Sends telnet go-ahead if `MSG_PROMPT` is set

## Action Messages (ACTION_D)

Action messages handle perspective-correct grammar. They're called on the acting object (the player/NPC doing the action). Defined in `adm/daemons/action.lpc`.

### Message Tokens

| Token | Meaning | For viewer=actor | For viewer=other |
|---|---|---|---|
| `$N` | Actor name (capitalized) | "You" | "Bob" |
| `$n` | Actor name | "you" | "Bob" |
| `$T` / `$t` | Target (defaults to who[1]) | "you" (if target) | name/pronoun |
| `$V` / `$v` | Verb (conjugated) | base form | third-person |
| `$P` / `$p` | Possessive | "your" | "Bob's" / "his" |
| `$O` / `$o` | Object reference | description | description |
| `$R` / `$r` | Reflexive | "yourself" | "himself" |
| `$B` / `$b` | Body reference | "you" | name/pronoun |

Uppercase tokens produce capitalized output. Numeric suffixes index into participants: `$N0` = who[0], `$N1` = who[1].

### Verb Conjugation

`$v` automatically conjugates:
- For actor viewing self: base form ("pick", "swing")
- For others viewing: third-person ("picks", "swings")
- Special handling for "is/am/are" contractions

```lpc
"$N $vpick up $o."
// Actor sees:  "You pick up the sword."
// Others see:  "Bob picks up the sword."
```

### Action Functions

All called on the acting object: `tp->simple_action(...)` or `previous_object()->simple_action(...)`.

**`simple_action(msg, obs...)`** — Actor + room both see (different perspectives)
```lpc
tp->simple_action("$N $vpick up $o.", sword);
// Actor: "You pick up the sword."
// Room:  "Bob picks up the sword."
```

**`my_action(msg, obs...)`** — Only actor sees
```lpc
tp->my_action("$N $vfeel a strange tingling.");
// Actor: "You feel a strange tingling."
```

**`other_action(msg, obs...)`** — Only others see
```lpc
tp->other_action("$N $vsnore loudly.");
// Room: "Bob snores loudly."
```

**`targetted_action(msg, target, obs...)`** — Actor, target, and others all see different versions
```lpc
tp->targetted_action("$N $vkick $t.", victim);
// Actor:  "You kick Bob."
// Target: "Gesslar kicks you."
// Others: "Gesslar kicks Bob."
```

**`target_action(msg, target, obs...)`** — Only target sees
```lpc
tp->target_action("$N $vwhisper something to $t.", target);
```

**`my_target_action(msg, target, obs...)`** — Only actor sees (target-aware grammar)
```lpc
tp->my_target_action("You kick $t hard.", target);
```

### Object Handling in Actions

Objects passed as `obs...` are referenced with `$o`, `$o0`, `$o1`, etc. The system handles:
- Articles: "a sword", "the sword" based on preceding text
- Pluralization: multiple same-name objects get consolidated ("3 swords")
- Pronoun substitution: "it" for previously mentioned objects

```lpc
tp->simple_action("$N $vput $o in $o1.", sword, chest);
// "You put the sword in the chest."
```

## System Feedback Functions

Defined in `adm/simul_efun/system.lpc`. Provide colored, accessible, formatted messages.

### Calling Styles

All six functions support two overloads:
```lpc
_ok("message")                    // Sends to this_body()
_ok(object, "message")            // Sends to specific object
_ok("format %s", arg)             // With sprintf formatting
_ok(object, "format %s", arg)     // Both
```

### Return Value

All return `1` on success, `0` if no target. This makes them usable as return values in commands:
```lpc
return _error("You can't do that.");  // Returns 1, displays error
```

### Symbols and Colors

| Function | Symbol (Unicode) | Symbol (ASCII) | Color |
|---|---|---|---|
| `_ok` | `\u2022` (bullet) | `o` | `{{009966}}` (teal) |
| `_error` | `\u25CF` (circle) | `o` | `{{CC0000}}` (red) |
| `_warn` | `\u25B2` (triangle) | `o` | `{{FF9900}}` (orange) |
| `_info` | `\u25A0` (square) | `o` | `{{FFFF66}}` (yellow) |
| `_question` | `\u25C6` (diamond) | `o` | `{{0066FF}}` (blue) |
| `_debug` | `\u25A1` (hollow square) | `o` | `{{CC00CC}}` (magenta) |

Accessibility handling:
- Screen reader users: color only, no symbols
- Unicode-capable: Unicode symbols
- ASCII fallback: `o` character
- Non-interactive recipients: falls back to `debug()` log

## Common Patterns

### Command with feedback

```lpc
mixed main(object tp, string arg) {
  if(!arg)
    return _error("Syntax: mycommand <target>");

  object target = find_target(tp, arg, environment(tp));
  if(!target)
    return _error("Could not find '%s'.", arg);

  tp->simple_action("$N $vexamine $o carefully.", target);
  _ok(tp, "You notice something interesting about %s.", target->query_name());
  return 1;
}
```

### Room message with exclusion

```lpc
// Message to everyone in room except player and their pet
tell_them("A bright flash fills the room.\n", ({ pet }));
```

### Direct message with prompt

```lpc
tell(tp, "Continue? [y/n] ", MSG_PROMPT);
```

## Key Design Points

- **Always include `\n`**: `tell()` does NOT auto-append newlines. You must include `\n` in your strings. Action messages and `_ok`/`_error`/etc. handle this automatically.
- **Containment-aware**: `tell_up`, `tell_down`, `tell_all` propagate through the object containment tree. Objects can opt out via `set_contents_can_hear(0)` or `set_environment_can_hear(0)`.
- **Duplicate prevention**: `receive_all` maintains an exclude list to prevent objects from receiving the same message twice during propagation.
- **Action messages are called on the actor**: `tp->simple_action(...)`, not `simple_action(tp, ...)`. The daemon uses `previous_object()` to identify the actor.
- **Color is opt-in**: Messages pass through `COLOUR_D` but colors are stripped for users with colour preference off, non-interactive objects, or when `NO_COLOUR` flag is set.
