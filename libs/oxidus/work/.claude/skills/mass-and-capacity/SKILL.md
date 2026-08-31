---
name: mass-and-capacity
description: Understand and work with the mass, capacity, and container systems in Oxidus. Covers mass tracking and propagation, container capacity/fill, open/close/lock states, opacity, key IDs, the transactional move system, and GMCP integration.
---

# Mass, Capacity, and Container Skill

You are helping work with the physical containment systems in Oxidus. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

Three tightly coupled subsystems handle physical object constraints:

1. **Weight** (`std/object/weight.lpc`) — mass tracking per object
2. **Contents** (`std/object/contents.lpc`) — capacity/fill tracking per container
3. **Container** (`std/object/container.lpc`) — open/close/lock states, access control

All three are config-gated: they only enforce constraints when `mudConfig("USE_MASS")` is true.

## Mass System — `std/object/weight.lpc`

**Property:** `int _mass` — the object's mass in abstract units.

| Function | Signature | Purpose |
|---|---|---|
| `query_mass` | `int query_mass()` | Get current mass |
| `set_mass` | `int set_mass(int new_mass)` | Set absolute mass; rejects negative; delegates to `adjust_mass()` |
| `adjust_mass` | `int adjust_mass(int delta)` | Adjust mass with environment propagation |

### Mass Propagation

When `adjust_mass(delta)` is called on an object that has an environment:

```
adjust_mass(delta) on object
  ├─ env->ignore_mass()? YES → skip mass propagation
  │                       NO  → env->adjust_mass(delta) — cascades up
  │                             On failure → return 0
  │
  └─ env->ignore_capacity()? YES → skip fill check
                              NO  → env->adjust_fill(delta)
                                    On failure → roll back env mass, return 0
```

This is **transactional** — if the fill check fails, the mass change on the environment is rolled back.

## Capacity System — `std/object/contents.lpc`

**Properties:**
- `int _capacity` — total capacity limit
- `nosave int _fill` — current fill level (transient, recalculated)

| Function | Signature | Purpose |
|---|---|---|
| `set_capacity` | `void set_capacity(int x)` | Set capacity; triggers rehash and GMCP |
| `adjust_capacity` | `void adjust_capacity(int x)` | Adjust capacity by delta |
| `query_capacity` | `int query_capacity()` | Get capacity (null if USE_MASS disabled) |
| `query_fill` | `int query_fill()` | Get current fill (null if USE_MASS disabled) |
| `adjust_fill` | `int adjust_fill(int x)` | Adjust fill; returns 0 if would go negative or exceed capacity |
| `can_hold_object` | `int can_hold_object(object ob)` | Check if object's mass fits |
| `can_hold_mass` | `int can_hold_mass(int mass)` | Check if mass units fit: `_fill + mass <= _capacity` |
| `rehash_capacity` | `void rehash_capacity()` | Recalculate fill from all inventory masses |

### rehash_capacity() Details

- Iterates all inventory, sums `query_mass()` on each
- Recursively calls `rehash_capacity()` on each contained object first
- For living objects: adds `query_total_coins()` to the total
- For living objects with no capacity set: defaults capacity to 1000
- Broadcasts GMCP update if the object is a player

## Container System — `std/object/container.lpc`

Inherits both `inventory.lpc` and `contents.lpc`.

### State Properties

| Property | Setter/Getter | Purpose |
|---|---|---|
| `_ignore_capacity` | `set_ignore_capacity(int)` / `ignore_capacity()` | Bypass capacity enforcement |
| `_ignore_mass` | `set_ignore_mass(int)` / `ignore_mass()` | Bypass mass propagation to parent |
| `_closeable` | `set_closeable(int)` / `is_closeable()` | Can be opened/closed |
| `_lockable` | `set_lockable(int)` / `is_lockable()` | Can be locked/unlocked |
| `_closed` | `set_closed(int)` / `is_closed()` | Current open/closed state |
| `_locked` | `set_locked(int)` / `is_locked()` | Current locked/unlocked state |
| `_opaque` | `set_opaque(int)` / `is_opaque()` | Contents hidden when closed (default: 1) |
| `_key_id` | `set_key_id(string)` / `query_key_id()` | Key identifier for lock mechanism |

All state properties are `nosave` — they reset on reload.

### Access Control

| Function | Signature | Purpose |
|---|---|---|
| `is_content_accessible` | `varargs int is_content_accessible(object pov)` | Check if inventory is reachable from pov's position |
| `inventory_accessible` | | Alias for `is_content_accessible()` |
| `inventory_visible` | | Alias for `is_content_accessible()` |
| `can_receive` | `int can_receive(object ob)` | Override point — default returns 1 |
| `can_release` | `int can_release(object ob)` | Override point — default returns 1 |
| `can_close_container` | `mixed can_close_container()` | Returns 1, 0 (not closeable), or error string |
| `can_open_container` | `mixed can_open_container()` | Returns 1, 0 (not closeable), or error string |

### Container Status

```lpc
varargs mixed query_container_status(int as_number)
```

Returns state as string or number:
- Locked: `3` or `"locked"`
- Closed: `2` or `"closed"`
- Open: `1` or `"open"`

### Events

- `"released"` — fired when an object leaves (args: object, new_env)
- `"gmcp_item_removed"` — GMCP notification on item removal
- `"container_empty"` — fired when last item is removed

### Identity

- `int is_container()` — always returns 1

## The Move System — `std/object/item.lpc`

### Move Result Codes (`include/move.h`)

| Code | Constant | Meaning |
|---|---|---|
| 0 | `MOVE_OK` | Success |
| 1 | `MOVE_TOO_HEAVY` | Exceeds capacity |
| 3 | `MOVE_NO_DEST` | Invalid destination |
| 4 | `MOVE_NOT_ALLOWED` | `can_receive()` or `can_release()` denied |
| 5 | `MOVE_DESTRUCTED` | Object was destructed |
| 6 | `MOVE_ALREADY_THERE` | Already in that environment |

### allow_move(mixed dest)

Pre-move validation:
1. Loads destination if string path
2. Checks not already there
3. Checks `dest->can_receive(this_object())`
4. If USE_MASS: checks `query_mass() + dest->query_fill() > dest->query_capacity()`
5. Checks `env->can_release(this_object())`

### move(mixed dest) — Transactional

```
move(dest)
  ├─ allow_move(dest) → returns error code on failure
  ├─ If USE_MASS:
  │   ├─ Previous env: adjust_mass(-mass), adjust_fill(-mass)
  │   ├─ Destination: adjust_mass(+mass), adjust_fill(+mass)
  │   └─ On any failure: roll_back() all changes, return MOVE_TOO_HEAVY
  ├─ move_object(dest) — driver function
  └─ Fire events: "moved", "base_released", "base_received", GMCP update
```

The rollback array tracks every mass/fill change so partial failures are fully reversed.

## Living Bodies

Living objects (`std/living/body.lpc`) call `set_ignore_mass(1)` in their `mudlib_setup()`. This means:
- Items in a living's inventory don't propagate mass upward (to the room)
- Capacity still enforces — livings have a default capacity of 1000

### Coin Mass

Coins have mass equal to their count (1 coin = 1 mass unit). The wealth system:
- Calls `can_hold_mass(amount)` before accepting coins
- Calls `rehash_capacity()` after wealth changes
- `query_total_coins()` is included in fill calculations for livings

## Common Patterns

### Basic Container Setup
```lpc
void setup() {
  set_id("chest");
  set_short("wooden chest");
  set_long("A sturdy wooden chest.");
  set_mass(50);
  set_capacity(100);
  set_closeable(1);
  set_closed(1);
}
```

### Lockable Container
```lpc
void setup() {
  set_id("chest");
  set_short("iron chest");
  set_mass(80);
  set_capacity(150);
  set_closeable(1);
  set_closed(1);
  set_lockable(1);
  set_locked(1);
  set_key_id("manor key");
}
```

### Bag of Holding (Ignores Mass)
```lpc
void setup() {
  set_id("bag");
  set_short("bag of holding");
  set_mass(5);
  set_capacity(200);
  set_ignore_mass(1);  // Items don't add mass to parent container
  set_closeable(1);
  set_closed(1);
}
```

### Checking Before Move
```lpc
int result = ob->move(destination);
if(result == MOVE_TOO_HEAVY)
  tell(tp, "It's too heavy to fit.");
else if(result == MOVE_NOT_ALLOWED)
  tell(tp, "You can't put that there.");
```

## Important Notes

- All mass/capacity functions return null (not 0) when `USE_MASS` is disabled — check with `nullp()` if needed.
- `_fill` is `nosave` — it's recalculated via `rehash_capacity()` on load, not persisted.
- `adjust_fill()` returns 0 on boundary violation (not an error) — this is the capacity enforcement mechanism.
- Container state properties (`_closed`, `_locked`, etc.) are all `nosave` — set them in `setup()`.
- The `put` command checks `can_hold_object()` before attempting `move()`.
- GMCP updates fire on capacity/fill changes for player-visible containers.
