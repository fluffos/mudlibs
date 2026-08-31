---
name: buff-system
description: Understand and work with the boon/curse (buff/debuff) system in Oxidus. Covers boon and curse application, class/type structure, stacking, expiration, querying effective values, and integration with attributes, vitals, and skills.
---

# Boon System Skill

The boon/curse system provides buffs and debuffs for living objects in Oxidus. Boons increase values; curses decrease them. The net effect is calculated as `boon - curse` for any given class/type combination.

**Core files:**
- `std/living/boon.lpc` — boon/curse implementation
- `std/living/include/boon.h` — header with function declarations

## Data Structure

Boons and curses are stored in separate mappings with identical structure:

```
boon = ([
    "class" : ([
        "type" : ([
            tag : ([ "name" : "Display Name", "amt" : 5, "expires" : 1711234567 ]),
            ...
        ]),
        ...
    ]),
    ...
])
```

- **class** — the category of bonus (e.g., `"attribute"`, `"vital"`, `"skill"`)
- **type** — the specific thing being modified (e.g., `"strength"`, `"max_hp"`, `"attack"`)
- **tag** — unique identifier generated via `time_ns()` (with collision avoidance)

## API

### Applying

```lpc
// Apply a boon (buff): returns unique tag
int tag = tp->boon("Iron Will", "attribute", "constitution", 3, 60);

// Apply a curse (debuff): returns unique tag
int tag = tp->curse("Chill", "attribute", "dexterity", 2, 30);
```

Parameters: `name`, `class`, `type`, `amount`, `duration_seconds`

### Querying

```lpc
// Total boon value for a class/type
int val = tp->query_boon("attribute", "strength");

// Total curse value for a class/type
int val = tp->query_curse("attribute", "strength");

// Net effect (boon - curse)
int val = tp->query_effective_boon("attribute", "strength");

// Full data copies
mapping all_boons = tp->query_boon_data();
mapping all_curses = tp->query_curse_data();
```

### Initialization

`init_boon()` is called during living object setup to ensure the mappings exist.

### Removing

```lpc
// Remove a specific boon by tag (returned from boon())
int success = tp->remove_boon("attribute", "strength", tag);

// Remove a specific curse by tag
int success = tp->remove_curse("attribute", "dexterity", tag);

// Remove all boons matching a name for a class/type
int count = tp->remove_boon_by_name(
  "attribute", "constitution", "Iron Will"
);

// Remove all curses matching a name for a class/type
int count = tp->remove_curse_by_name(
  "attribute", "dexterity", "Chill"
);
```

### Expiration

`process_boon()` runs on every heartbeat (both players and NPCs). It collects expired entries, removes them, prunes empty inner mappings, and sends a wear-off message via `tell()`: `"Your <name> has worn off.\n"`

## Currently Used Classes

| Class | Type Examples | Integrated In |
|---|---|---|
| `attribute` | `strength`, `dexterity`, `constitution`, `intelligence`, `wisdom`, `charisma` | `std/living/attributes.lpc` — `get_attribute()` adds `query_effective_boon("attribute", key)` |
| `vital` | `max_hp`, `max_sp`, `max_mp` | `std/living/vitals.lpc` — `query_max_hp/sp/mp()` adds `query_effective_boon("vital", ...)` |
| `skill` | Any skill name | `std/living/skills.lpc` — skill level queries add `query_effective_boon("skill", skill)` |

The class/type system is open-ended — any string can be used as a class or type. New classes take effect as soon as consuming code calls `query_effective_boon()` with that class.

## Stacking Rules

- Multiple boons/curses of different names stack additively
- There is no automatic replacement — applying a boon with the same name creates a separate entry with a new tag
- No caps or diminishing returns
- Net value is always `total_boons - total_curses` for a given class/type

## Persistence

The `boon` and `curse` mappings are `private nomask` but **not** `nosave`, so they persist when the object is saved. Active boons/curses survive save/load cycles. The `BOON` and `CURSE` integer constants are `nosave` (they are compile-time identifiers only).

## Notes

- Both players (`std/living/player.lpc`) and NPCs (`std/living/npc.lpc`) process boons on heartbeat
- Boons/curses can be removed early by tag (`remove_boon`/`remove_curse`) or by name (`remove_boon_by_name`/`remove_curse_by_name`)
- There are no gear-based buffs, room buffs, or special category buffs — all effects go through `boon()` / `curse()`
