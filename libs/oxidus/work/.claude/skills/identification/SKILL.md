---
name: identification
description: Understand and work with the identification and description systems in Oxidus. Covers IDs, adjectives, automatic pluralization, adjective+ID combinations, parse_command integration, short/long descriptions, extra descriptions, names, and how the look command displays objects.
---

# Identification and Description Skill

You are helping work with how objects are named, identified, and described in Oxidus. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

Two subsystems handle object identity and display:

1. **ID System** (`std/object/id.lpc`) — identifiers, adjectives, plurals, parse_command integration
2. **Description System** (`std/object/description.lpc`) — short/long text, extra descriptions

Both interact with the **Name System** in `std/object/object.lpc`.

## ID System — `std/object/id.lpc`

### Internal State

| Variable | Type | Purpose |
|---|---|---|
| `_ids` | `string *` | All identifiers (base + generated combinations) |
| `_base_ids` | `string *` | Raw IDs set by the developer |
| `_plural_ids` | `string *` | Auto-generated plural forms |
| `_adj` | `string *` | All adjectives (base + combinations) |
| `_base_adj` | `string *` | Raw adjectives set by the developer |

### Functions

| Function | Signature | Purpose |
|---|---|---|
| `set_id` | `void set_id(mixed str)` | Replace all IDs (string or array) |
| `add_id` | `void add_id(mixed str)` | Add IDs to existing set |
| `remove_id` | `void remove_id(mixed str)` | Remove specific IDs |
| `set_adj` | `void set_adj(mixed str)` | Replace all adjectives |
| `add_adj` | `void add_adj(mixed str)` | Add adjectives |
| `remove_adj` | `void remove_adj(mixed str)` | Remove adjectives |
| `query_ids` | `string *query_ids()` | Get all IDs (generated set) |
| `query_plural_ids` | `string *query_plural_ids()` | Get all plural IDs |
| `query_adjs` | `string *query_adjs()` | Get all adjectives |
| `rehash_ids` | `void rehash_ids()` | Regenerate IDs from base sets |
| `id` | `int id(string arg)` | Driver apply — check if arg matches any ID |

### How rehash_ids() Works

Called automatically after any `set_id`, `add_id`, `remove_id`, `set_adj`, `add_adj`, `remove_adj`, `set_name`, or `set_real_name` call.

1. Starts with `_base_ids`
2. Generates adjective+ID combinations: each `_base_adj` × each `_base_id` (e.g., `"red"` + `"sword"` → `"red sword"`)
3. Adds `query_name()` if not already present
4. Generates plural forms via `pluralize()` (driver efun)
5. Deduplicates with `distinct_array()`
6. Stores results in `_ids` and `_plural_ids`

### Example

```lpc
set_id(({ "sword", "blade" }));
set_adj(({ "red", "sharp" }));
```

Produces:
- `_ids`: `"sword"`, `"blade"`, `"red sword"`, `"red blade"`, `"sharp sword"`, `"sharp blade"`, plus `query_name()`
- `_plural_ids`: `"swords"`, `"blades"`, `"red swords"`, etc.

### parse_command Integration

Three `nomask` functions provide identifiers to the driver's `parse_command()`:

```lpc
string *parse_command_id_list()            // Returns _ids (nulls filtered)
string *parse_command_plural_id_list()     // Returns _plural_ids (nulls filtered)
string *parse_command_adjectiv_id_list()   // Returns _adj (nulls filtered)
```

These are called automatically by the driver when resolving command targets like `"get red sword"` or `"drop all swords"`.

### id() Apply

```lpc
int id(string arg)
```

Driver apply called to check if an object matches a string. Checks if `arg` is in `_ids`. If `_ids` is empty, initializes from `query_name()` as fallback.

## Name System — `std/object/object.lpc`

### Properties

| Variable | Type | Purpose |
|---|---|---|
| `real_name` | `string` | Internal lowercase name (for livings/users) |
| `_name` | `string` | Display name (may be capitalized for users) |

### Functions

| Function | Signature | Purpose |
|---|---|---|
| `set_name` | `string set_name(string str)` | Set display name; auto-capitalizes for valid users |
| `query_name` | `string query_name()` | Get display name |
| `set_real_name` | `string set_real_name(string str)` | Set internal name (lowercase); admin-only on interactives |
| `query_real_name` | `string query_real_name()` | Get internal name |

### Relationships

- `set_name("sword")` → stores `_name`, calls `set_real_name()` if none exists, then `rehash_ids()`
- `set_real_name("gesslar")` → stores `real_name` as lowercase, calls `set_living_name()` for livings, then `rehash_ids()`
- `rehash_ids()` always includes `query_name()` in the ID list
- For players: `set_name("gesslar")` → `_name` = `"Gesslar"` (capitalized)

## Description System — `std/object/description.lpc`

### Short and Long Descriptions

| Function | Signature | Purpose |
|---|---|---|
| `set_short` | `int set_short(mixed str)` | Set short description (string or function) |
| `query_short` | `string query_short(object viewer)` | Get short; calls function with viewer if callable |
| `set_long` | `int set_long(mixed str)` | Set long description (string or function) |
| `query_long` | `string query_long(object viewer)` | Get long; calls function with viewer if callable |

**Function descriptions** enable dynamic text:
```lpc
set_short((: "a " + (night_time() ? "dark" : "bright") + " lantern" :));
```

`set_short()` triggers a GMCP item update if the object has an environment.

### Extra Descriptions

Keyed supplementary descriptions displayed alongside the main short/long.

| Function | Signature | Purpose |
|---|---|---|
| `add_extra_short` | `void add_extra_short(string id, mixed str)` | Add keyed extra short (string or function) |
| `remove_extra_short` | `void remove_extra_short(string id)` | Remove by key |
| `query_extra_short` | `string query_extra_short(string id)` | Get single by key |
| `query_extra_shorts` | `string *query_extra_shorts()` | Get all values (sorted by key, strings only) |
| `add_extra_long` | `void add_extra_long(string id, mixed str)` | Add keyed extra long |
| `remove_extra_long` | `void remove_extra_long(string id)` | Remove by key |
| `query_extra_long` | `string query_extra_long(string id)` | Get single by key |
| `query_extra_longs` | `string query_extra_longs()` | Get all values (sorted, strings only) |

### How Extras Display

The simul_efun `get_short()` and `get_long()` (in `adm/simul_efun/description.lpc`) handle display:

**Short** (with extras):
```
"a sword (glowing) (magical)"
```
Each extra short is wrapped in parentheses and appended.

**Long** (with extras):
```
This is a sharp blade with a keen edge.

It hums with magical power.
The blade glows with a faint blue light.
```
Extra longs are appended after a newline separator.

## Common Patterns

### Basic Object Identity
```lpc
void setup() {
  set_id(({ "sword", "blade" }));
  set_adj(({ "rusty" }));
  set_name("rusty sword");
  set_short("a rusty sword");
  set_long("A battered old sword covered in rust.");
}
```

### Dynamic Extra Description
```lpc
void setup() {
  set_id("lantern");
  set_short("a lantern");
  set_long("A brass lantern with a glass pane.");
  add_extra_short("lit", (: is_lit() ? "lit" : 0 :));
  add_extra_long("flame", (: is_lit() ?
    "A warm flame flickers inside." : "It is unlit." :));
}
```

When lit: short displays as `"a lantern (lit)"`.

### Consumable Status (Used by STD_FOOD/STD_DRINK)
```lpc
add_extra_long("consume", (: consume_message :));
```

A function reference that returns status text based on `query_uses()` percentage.

### Multiple IDs for Parsing
```lpc
set_id(({ "potion", "bottle", "healing potion" }));
set_adj(({ "red", "small" }));
// Player can now use: "potion", "bottle", "healing potion",
// "red potion", "small bottle", "red healing potion", etc.
```

## Important Notes

- **set_id replaces all IDs**. Use `add_id()` to append without clearing.
- **Adjective combinations are automatic**. Setting `set_adj("red")` and `set_id("sword")` automatically creates `"red sword"` — you don't need to add it manually.
- **Plurals are automatic**. The `pluralize()` driver efun handles English pluralization rules.
- **query_name() is always an ID**. Even if you don't call `set_id()`, the object's name is matchable.
- **Function descriptions** receive the viewer as argument for `query_short`/`query_long`, but no arguments for extra descriptions.
- **Extra description keys** are arbitrary strings used for identification — they aren't shown to players, only the values are.
- **Extra shorts returning null/0** are silently omitted from display — this enables conditional extras.
- **STD_FOOD auto-adds "food"** and **STD_DRINK auto-adds "drink"** to IDs via `set_id()` override.
