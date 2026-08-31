---
name: consumables
description: Understand and work with the consumable system in Oxidus. Covers the EXT_USES base module, EXT_EDIBLE (food/eat/nibble), EXT_POTABLE (drink/sip), STD_FOOD, STD_DRINK, action message customization, and creating food and drink items.
---

# Consumables Skill

You are helping work with the Oxidus consumable system. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

```
EXT_USES (std/ext/uses.lpc)         — base use-count tracking
  ├── EXT_EDIBLE (std/ext/edible.lpc)  — eat/nibble mechanics (protected)
  └── EXT_POTABLE (std/ext/potable.lpc) — drink/sip mechanics (protected)

STD_ITEM + EXT_EDIBLE  → STD_FOOD (std/consume/food.lpc)   — adds public *_obj wrappers
STD_ITEM + EXT_POTABLE → STD_DRINK (std/consume/drink.lpc) — adds public *_obj wrappers
```

The consumption verbs themselves (`eat`, `nibble`, `drink`, `sip`) are `protected` on the EXT_* modules — outside callers must go through the public `*_obj` wrappers on STD_FOOD/STD_DRINK.

## EXT_USES — `std/ext/uses.lpc`

Base module tracking consumable quantities.

### Properties

- `int _max_uses` — maximum available uses
- `int _uses` — current remaining uses
- `string _use_status_message` — optional custom status message

### Functions

| Function | Signature | Purpose |
|---|---|---|
| `set_uses` | `int set_uses(int uses)` | Set current uses; initializes `_max_uses` if null |
| `query_uses` | `int query_uses()` | Get remaining uses |
| `query_max_uses` | `int query_max_uses()` | Get maximum uses |
| `adjust_uses` | `mixed adjust_uses(int uses)` | Adjust by delta; returns null if would go negative or exceed max |
| `reset_uses` | `void reset_uses()` | Reset `_uses` to `_max_uses` |
| `set_use_status_message` | `void set_use_status_message(string msg)` | Set custom status message |
| `query_use_status_message` | `string query_use_status_message()` | Get status message |

## EXT_EDIBLE — `std/ext/edible.lpc`

Inherits `EXT_USES`. Adds eat/nibble mechanics with customizable action messages.

### Properties

- `int _edible` — flag (1 = edible)
- `mapping _actions` — custom action messages, keyed by `"eat"` and `"nibble"`

### Functions

| Function | Signature | Visibility | Purpose |
|---|---|---|---|
| `set_edible` | `int set_edible(int edible)` | public | Mark as edible |
| `is_edible` | `int is_edible()` | public | Check edibility |
| `eat` | `mixed eat(object user)` | **protected** | Eat entirely — depletes all remaining uses. Call via `eat_obj()` on STD_FOOD. |
| `nibble` | `mixed nibble(object user, int amount)` | **protected** | Eat specified amount. Call via `nibble_obj()` on STD_FOOD. |
| `reset_edible` | `void reset_edible()` | public | Calls `reset_uses()` |

**Error returns** from `eat`/`nibble`:
- `"You can't eat that."` / `"You can't nibble that."` — not edible
- `"There is nothing left to eat."` / `"There is nothing left to nibble."` — no uses remaining

### Action Message Customization

Each action type (`"eat"`, `"nibble"`) supports three message slots:

| Setter | Purpose |
|---|---|
| `set_eat_action(string)` | Combined message (overrides self + room) |
| `set_self_eat_action(string)` | Message to the eater only |
| `set_room_eat_action(string)` | Message to the room only |
| `set_nibble_action(string)` | Combined nibble message |
| `set_self_nibble_action(string)` | Nibble message to eater |
| `set_room_nibble_action(string)` | Nibble message to room |

**Default messages:**
- Eat: `"$N $veat a $o."`
- Nibble: `"$N $vnibble on a $o."`

**Display logic:**
- If combined `action` is set → `user->simple_action(action)`
- If both self and room are null → `user->simple_action(default)`
- Otherwise → `user->simple_action(self_msg)` for the eater, `user->simple_action(room_msg)` for room

## EXT_POTABLE — `std/ext/potable.lpc`

Inherits `EXT_USES`. Adds drink/sip mechanics. Mirrors EXT_EDIBLE's structure.

### Functions

| Function | Signature | Visibility | Purpose |
|---|---|---|---|
| `set_potable` | `int set_potable(int potable)` | public | Mark as drinkable |
| `is_potable` | `int is_potable()` | public | Check potability |
| `drink` | `mixed drink(object user)` | **protected** | Drink entirely. Call via `drink_obj()` on STD_DRINK. |
| `sip` | `mixed sip(object user, int amount)` | **protected** | Sip specified amount. Call via `sip_obj()` on STD_DRINK. |
| `reset_potable` | `void reset_potable()` | public | Calls `reset_uses()` |

**Error returns** from `drink`/`sip`:
- `"You can't drink that."` / `"You can't sip that."` — not potable
- `"There is nothing left to drink."` / `"There is nothing left to sip."` — no uses remaining

### Action Message Customization

| Setter | Purpose |
|---|---|
| `set_drink_action(string)` | Combined drink message |
| `set_self_drink_action(string)` | Drink message to drinker |
| `set_room_drink_action(string)` | Drink message to room |
| `set_sip_action(string)` | Combined sip message |
| `set_self_sip_action(string)` | Sip message to sipper |
| `set_room_sip_action(string)` | Sip message to room |

**Default messages:**
- Drink: `"$N $vdrink a $o."`
- Sip: `"$N $vsip from a $o."`

## STD_FOOD — `std/consume/food.lpc`

Inherits `STD_ITEM` + `EXT_EDIBLE`. Ready-to-use food inheritable.

**Automatic behavior:**
- Calls `set_edible(1)` in `mudlib_setup()`
- Marks `_uses`, `_max_uses`, `_use_status_message` for persistence via `save_var()`
- Auto-adds `"food"` to IDs when `set_id()` is called
- Adds a `"consume"` extra_long description showing consumption status
- Auto-removes item when uses reach 0 (after the wrapping `*_obj` call)

**Public wrappers** (call these from commands/external code, not the protected EXT_EDIBLE versions):

| Function | Signature | Purpose |
|---|---|---|
| `eat_obj` | `mixed eat_obj(object user)` | Calls protected `eat()`; on success and `query_uses() < 1`, emits "$N $vhave eaten the last of the $o." and removes the object. |
| `nibble_obj` | `int nibble_obj(object user)` | Calls protected `nibble(user, 1)`; same depletion handling. |
| `is_food` | `int is_food()` | Always returns 1 — type check. |

**Status messages** (based on remaining percentage):
- 100%: `"This [name] hasn't been touched."`
- 80–99%: `"This [name] has been nibbled on."`
- 50–79%: `"A lot of this [name] has been eaten."`
- 25–49%: `"Most of this [name] has been eaten."`
- 0–24%: `"There is very little left of this [name]."`

## STD_DRINK — `std/consume/drink.lpc`

Inherits `STD_ITEM` + `EXT_POTABLE`. Ready-to-use drink inheritable.

**Automatic behavior:**
- Calls `set_potable(1)` in `mudlib_setup()`
- Marks `_uses`, `_max_uses`, `_use_status_message` for persistence via `save_var()`
- Auto-adds `"drink"` to IDs when `set_id()` is called
- Adds a `"consume"` extra_long description showing consumption status
- Auto-removes item when uses reach 0 (after the wrapping `*_obj` call)

**Public wrappers** (call these from commands/external code):

| Function | Signature | Purpose |
|---|---|---|
| `drink_obj` | `mixed drink_obj(object user)` | Calls protected `drink()`; on success and `query_uses() < 1`, emits "$N $vhave drunk the last of the $o." and removes the object. |
| `sip_obj` | `int sip_obj(object user)` | Calls protected `sip(user, 1)`; same depletion handling. |
| `is_drink` | `int is_drink()` | Always returns 1 — type check. |

**Status messages** (based on remaining percentage):
- 100%: `"This [name] is full."`
- 80–99%: `"This [name] has barely been touched."`
- 50–79%: `"A lot of this [name] has been drunk."`
- 25–49%: `"Most of this [name] has been drunk."`
- 0–24%: `"There is very little left of this [name]."`

## Commands

All four player commands live under `cmds/action/` and follow the same shape: resolve the target with `find_target`, type-check it, check `query_uses()`, then call the public `*_obj` wrapper.

| Command | Type check | Wrapper called |
|---|---|---|
| `cmds/action/eat.lpc` | `is_edible()` | `eat_obj(tp)` |
| `cmds/action/nibble.lpc` | `is_food()` | `nibble_obj(tp)` |
| `cmds/action/drink.lpc` | `is_drink()` | `drink_obj(tp)` |
| `cmds/action/sip.lpc` | `is_drink()` | `sip_obj(tp)` |

Never call the protected `eat`/`nibble`/`drink`/`sip` directly via `->` — it will fail at runtime.

## Creating Consumables

### Simple Food

```lpc
inherit STD_FOOD;

void setup() {
  set_id("muffin");
  set_name("muffin");
  set_short("a muffin");
  set_long("A delicious muffin.");
  set_mass(5);
  set_value(2);
  set_uses(1);  // One bite consumes it
}
```

### Multi-Use Food

```lpc
inherit STD_FOOD;

void setup() {
  set_id("loaf");
  set_adj("bread");
  set_name("bread loaf");
  set_short("a bread loaf");
  set_long("A crusty loaf of bread.");
  set_mass(10);
  set_value(5);
  set_uses(4);  // Four bites/nibbles
}
```

### Drink with Custom Action

```lpc
inherit STD_DRINK;

void setup() {
  set_id("juice");
  set_adj("strawberry");
  set_name("strawberry juice");
  set_short("a strawberry juice");
  set_long("A delicious strawberry juice.");
  set_mass(5);
  set_value(2);
  set_uses(5);  // Five sips
  set_drink_action("$N $vgulp down the $o with gusto!");
}
```

## Defines

```lpc
#define STD_FOOD   DIR_STD "consume/food"
#define STD_DRINK  DIR_STD "consume/drink"
#define EXT_EDIBLE   DIR_STD_EXT "edible"
#define EXT_POTABLE  DIR_STD_EXT "potable"
#define EXT_USES     DIR_STD_EXT "uses"
```

## Important Notes

- The verbs `eat`, `nibble`, `drink`, `sip` on the EXT_* modules are `protected`. External callers must use the public `eat_obj` / `nibble_obj` / `drink_obj` / `sip_obj` wrappers on STD_FOOD/STD_DRINK.
- `set_uses()` initializes `_max_uses` on the first call. Subsequent calls only change `_uses`.
- `adjust_uses()` returns null (not 0) on boundary violation — check with `nullp()`.
- STD_FOOD/STD_DRINK auto-remove the object when uses hit 0 (inside the `*_obj` wrappers). If you don't want this, inherit EXT_EDIBLE/EXT_POTABLE directly and write your own wrapper.
- Action messages use the `$-token` system (see `action-messages` skill): `$N` = actor, `$v` = verb conjugation, `$o` = object.
- Uses are persisted via `save_var()` — they survive storage in containers and player inventory saves.
