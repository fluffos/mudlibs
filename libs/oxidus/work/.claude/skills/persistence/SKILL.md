---
name: persistence
description: Understand and work with the persistence system in Oxidus. Covers save_var() variable marking, save_to_string/load_from_string serialization, the persist_data module (setPersistent/saveData/restore_data), the PERSIST_D daemon, and recursive inventory persistence.
---

# Persistence Skill

You are helping work with the Oxidus persistence system. Follow the `lpc-coding-style` skill for all LPC formatting.

## Architecture Overview

Persistence operates at two levels:

1. **Object-level** (`std/object/persist.lpc`) — explicit variable marking and string serialization with recursive inventory support
2. **Daemon-level** (`std/modules/persist_data.lpc`) — file-based save/restore via `save_object()`/`restore_object()`, registered with PERSIST_D for periodic saves

Most daemons use the daemon-level approach. Items that need to preserve inventory (storage containers, players) use the object-level approach.

## Object-Level Persistence — `std/object/persist.lpc`

### Marking Variables for Save

```lpc
protected void save_var(mixed *vars...)
```

Accepts one or more variable name strings. Only variables explicitly marked with `save_var()` are included in serialization. Uses `distinct_array()` to prevent duplicates.

```lpc
// Mark individual variables
save_var("_value");

// Mark multiple at once
save_var("_uses", "_max_uses", "_use_status_message");
```

Query marked variables:
```lpc
public string *get_saved_vars()
```

### String Serialization

**Saving:**
```lpc
varargs string save_to_string(int recursep)
```

1. Fires `event(({this_object()}), "saving")` — pre-save hook
2. Collects all variables named in `saved_vars` into a mapping
3. Builds output mapping:
   - `"#vars#"` — mapping of variable name to value
   - `"#base_name#"` — object's `base_name()` for type identification
   - `"#inventory#"` — array of serialized inventory items (only if `recursep == 1`)
4. Returns `save_variable(map)` — driver function producing LPC-encoded string

**Restoring:**
```lpc
void load_from_string(mixed value, int recurse)
```

1. Calls `restore_variable(value)` to decode string back to mapping
2. For `"#vars#"` key: restores only variables that are in `saved_vars` (ignores unknown)
3. For `"#inventory#"` key (if `recurse == 1`):
   - Instantiates each object from its `#base_name#`
   - Calls `load_from_string()` recursively on each
   - Moves objects into this container
4. Fires `event(({this_object()}), "restored")` — post-restore hook

### Recursive Inventory Flag

```lpc
protected void set_save_recurse(int flag)
```

Controls whether `save_to_string()` includes inventory by default.

## Daemon-Level Persistence — `std/modules/persist_data.lpc`

This is a module (mixin) inherited by daemons and objects that need file-based persistence.

### Enabling Persistence

```lpc
varargs int setPersistent(int x: (: 1 :))
```

- Default argument is 1 (enabled)
- Registers with `PERSIST_D` when enabled
- Unregisters when disabled
- Sets internal `persistent` flag

```lpc
int query_persistent()
```

### Data File

```lpc
varargs string set_data_file(string file)
string query_data_file()
```

- If not explicitly set, auto-determined from `object_data_file()` (which derives from the object's filename)
- Strips `__SAVE_EXTENSION__` suffix
- Auto-creates directories under `/data/` paths

### Save and Restore

```lpc
int saveData()
```

- Calls `save_object(data_file)` — driver function that saves all non-nosave variables
- Only operates if `persistent == 1`

```lpc
int restore_data()
```

- Calls `restore_object(data_file)` — driver function that restores variables from file
- Only operates if `persistent == 1`
- Called automatically during the setup chain (in `std/object/setup.lpc`)

## PERSIST_D Daemon — `adm/daemons/persist.lpc`

Coordinates periodic saves for all persistent objects.

| Function | Purpose |
|---|---|
| `register_persistent(object ob)` | Add object to persistence list |
| `unregister_persistent(object ob)` | Remove object from persistence list |
| `find_persistent_objects()` | Scan all loaded objects for `query_persistent()` |
| `persist_objects()` | Call `save_data()` on all registered objects |

**Automatic saves:**
- Heartbeat every 30 ticks calls `persist_objects()`
- Registers signal slots for:
  - `SIG_SYS_CRASH` — save on crash
  - `SIG_SYS_PERSIST` — manual persist signal

## Usage Patterns

### Daemon with Persistence (Most Common)

```lpc
inherit STD_DAEMON;

mapping data = ([]);

void setup() {
  setPersistent(1);
}

void modify_data(string key, mixed value) {
  data[key] = value;
  saveData();  // Save immediately after modification
}
```

All non-nosave variables are saved automatically. No need for `save_var()` — that's only for the object-level serialization system.

### Item with save_var

```lpc
inherit STD_ITEM;

private int _value;
private int _uses;
private int _max_uses;

void mudlib_setup() {
  save_var("_value", "_uses", "_max_uses");
}
```

These variables are included when `save_to_string()` is called (e.g., by a storage container saving its contents).

### Storage Container (Recursive Serialization)

```lpc
// Saving contents to file
void save_contents() {
  if(sizeof(all_inventory())) {
    string data = save_to_string(1);  // 1 = include inventory
    write_file(dest, data, 1);
  }
}

// Restoring contents from file
void restore_contents() {
  if(file_exists(dest)) {
    string data = read_file(dest);
    if(sizeof(data))
      load_from_string(data, 1);  // 1 = restore inventory
  }
}
```

### Player Inventory Persistence

```lpc
// In player.lpc
void save_inventory() {
  string save = save_to_string(1);
  write_file(user_inventory_data(...), save, 1);
}

void restore_inventory() {
  if(file_exists(file)) {
    string data = read_file(file);
    load_from_string(data, 1);
  }
}

int save_body() {
  catch(result = save_object(user_body_data(...)));
  save_inventory();
  return result;
}
```

## Serialization Format

The `save_to_string()` output (via `save_variable()`) produces an LPC-encoded string. The mapping structure:

```
([
  "#base_name#": "/obj/weapon/sword",
  "#vars#": ([
    "_value": 100,
    "_uses": 3,
  ]),
  "#inventory#": ({
    "(...serialized child 1...)",
    "(...serialized child 2...)",
  }),
])
```

- `#vars#` only contains variables registered with `save_var()`
- `#inventory#` only present when `recursep == 1`
- Each inventory entry is itself a `save_variable()` encoded string
- On restore, `#base_name#` is used to `new()` the correct object type

## Important Notes

- **save_var vs saveData**: `save_var()` marks variables for `save_to_string()` serialization. `saveData()` uses `save_object()` which saves all non-nosave variables to a `.o` file. They are separate systems.
- **nosave variables** are never persisted by either system.
- **restore_data()** is called automatically during the setup chain — you don't need to call it manually for daemons.
- **save_var() is additive** — calling it multiple times accumulates variables, doesn't replace.
- **load_from_string only restores known vars** — if a variable was removed from `saved_vars`, its stored value is silently ignored.
- **Events**: Listen for `"saving"` and `"restored"` events on objects if you need pre/post hooks.
- **PERSIST_D heartbeat** is every 30 ticks — don't rely on it for immediate saves. Call `saveData()` explicitly after critical changes.
