---
name: virtual-object-creation
description: Create virtual (data-driven) items and mobs for Oxidus. Covers LPML data files, extension-based routing, virtual compile modules, base classes, and how to add new virtual object types.
---

# Virtual Object Creation Skill

You are helping create virtual items and mobs for Oxidus. Virtual objects are data-driven — instead of writing a `.c` file with code, you write an LPML data file containing properties. The system compiles it into a game object by cloning the appropriate base class and passing the data to `virtual_setup()`.

## How Virtual Objects Work

1. Code requests an object like `/obj/food/cheese.food`
2. No `.c` file exists at that path — the driver calls `master->compile_object()`
3. The master delegates to `VIRTUAL_D->compile_object(file)`
4. VIRTUAL_D extracts the extension (`.food`) and routes to `adm/daemons/modules/virtual/food.lpc`
5. The module reads the corresponding LPML file (`/obj/food/cheese.lpml`)
6. It decodes the LPML and creates: `new("/obj/food/food.lpc", data)`
7. The base class receives the data mapping in `virtual_setup()` and configures itself

## Architecture

```
VIRTUAL_D (adm/daemons/virtual.lpc)
    │
    ├── Extension routing: .food → modules/virtual/food.lpc
    ├── Extension routing: .loot → modules/virtual/loot.lpc
    ├── Extension routing: .mob  → modules/virtual/mob.lpc
    │
    └── Directory routing: /d/ → modules/virtual/d.lpc (zones)
                           /player/ → modules/virtual/player.lpc
                           etc.
```

## Core Files

| File | Purpose |
|---|---|
| `adm/daemons/virtual.lpc` | Central router — extracts extension, loads module |
| `adm/daemons/modules/virtual/ob.lpc` | Base compile module for items (food, loot inherit from this) |
| `adm/daemons/modules/virtual/food.lpc` | Compile module for `.food` files (inherits `ob.lpc`) |
| `adm/daemons/modules/virtual/loot.lpc` | Compile module for `.loot` files (inherits `ob.lpc`) |
| `adm/daemons/modules/virtual/mob.lpc` | Compile module for `.mob` files |
| `obj/food/food.lpc` | Base class for food items (inherits `STD_FOOD`) |
| `obj/loot/loot.lpc` | Base class for loot items (inherits `STD_ITEM`) |
| `std/mobs/monster.lpc` | Base class for mobs (inherits `STD_NPC`) |

## Data File Format (LPML)

Virtual objects use LPML files (see the **lpml** skill for full syntax). Key points:

- LPML is a superset of JSON5 — use `{}` for objects, `[]` for arrays
- Keys don't need quotes (but can have them)
- Supports "spacey keys" like `additional ids`, `weapon name`
- String concatenation with adjacent strings
- Comments with `//`

```lpml
// obj/food/cheese.lpml

{
  id: ["cheese"],
  additional ids: ["food", "snack"],
  adj: ["small"],
  name: "cheese",
  short: "a small piece of cheese",
  long: "This is a small, round piece of cheese. It looks tasty and would"
        "make a good snack.",
  mass: 10,
  value: 15,
  uses: 1,
  properties: {
    edible: true,
  },
}
```

## Existing Virtual Object Types

### Food (`.food`)

**Data file location:** `obj/food/{name}.lpml`
**Base class:** `obj/food/food.lpc` (inherits `STD_FOOD`)
**Compile module:** `adm/daemons/modules/virtual/food.lpc` (inherits `ob.lpc`)

| Property | Type | Purpose |
|---|---|---|
| `id` | `string[]` | Object identifiers |
| `additional ids` | `string[]` | Extra IDs added via `add_id()` |
| `adj` | `string[]` | Adjectives |
| `name` | `string` | Object name |
| `short` | `string` | Short description |
| `long` | `string` | Long description |
| `mass` | `int` | Weight |
| `value` | `int` | Monetary value |
| `uses` | `int` | Number of times it can be consumed |
| `properties` | `mapping` | Custom properties (e.g., `edible: true`) |

### Loot (`.loot`)

**Data file location:** `obj/loot/{name}.lpml`
**Base class:** `obj/loot/loot.lpc` (inherits `STD_ITEM`)
**Compile module:** `adm/daemons/modules/virtual/loot.lpc` (inherits `ob.lpc`)

| Property | Type | Purpose |
|---|---|---|
| `id` | `string[]` | Object identifiers |
| `additional ids` | `string[]` | Extra IDs |
| `adj` | `string[]` | Adjectives |
| `name` | `string` | Object name |
| `short` | `string` | Short description |
| `long` | `string` | Long description |
| `mass` | `int` | Weight |
| `value` | `int` | Monetary value |
| `material` | `string[]` | Material tags |
| `properties` | `mapping` | Custom properties (e.g., `crafting material: true`) |
| `custom setup` | `function` | Optional function called with the object |

Example (`obj/loot/rabbit_fur.lpml`):
```lpml
{
  id: ["fur", "patch"],
  adj: ["rabbit"],
  name: "rabbit fur",
  short: "a patch of soft rabbit fur",
  long: "This is a small patch of soft, fluffy fur.",
  mass: 10,
  material: ["fur"],
  properties: {
    autovalue: true,
    crafting material: true,
  },
}
```

### Mobs (`.mob`)

**Data file location:** `d/mobs/{name}.lpml`
**Base class:** `std/mobs/{type}.c` (e.g., `std/mobs/mammal.lpc` inherits `std/mobs/monster.lpc`)
**Compile module:** `adm/daemons/modules/virtual/mob.lpc`

The `type` field in the LPML determines which mob base class is used.

| Property | Type | Purpose |
|---|---|---|
| `type` | `string` | Mob type — maps to `std/mobs/{type}.c` (e.g., `"mammal"`) |
| `name` | `string` | Mob name |
| `short` | `string` | Short description |
| `long` | `string` | Long description |
| `id` | `string[]` | Identifiers |
| `weapon name` | `string` | Name of natural weapon |
| `weapon type` | `string` | Damage type (e.g., `"piercing"`) |
| `level` | `int` or `int[]` | Fixed level or `[min, max]` range |
| `gender` | `string` or `string[]` | Fixed or random from array |
| `race` | `string` | Race classification |
| `loot` | `string[]` | Paths to loot/food items dropped on death |
| `loot chance` | `float` | Percentage chance to drop loot |
| `coins` | `mapping` | Coin drops: `{ copper: [min, chance], ... }` |

Example (`d/mobs/waste_rat.lpml`):
```lpml
{
  type: "mammal",
  name: "waste rat",
  short: "waste rat",
  long: "A scrappy waste rat scurries through the debris, searching for "
        "scraps to eat.",
  id: ["waste rat", "rat"],
  weapon name: "teeth",
  weapon type: "piercing",
  level: [1, 3],
  gender: ["male", "female"],
  race: "mammal",
  loot: [
    "/obj/food/rat_meat.food",
    "/obj/loot/rat_fur.loot",
  ],
  loot chance: 70.0,
  coins: {
    copper: [1, 20.0],
  },
}
```

## How the Compile Module Works

The base compile module (`ob.lpc`) follows this pattern:

1. Extracts the object name from the file path
2. Constructs the LPML file path: `/obj/{module}/{name}.lpml`
3. Reads and decodes the LPML: `lpml_decode(read_file(lpml_file))`
4. Creates the object: `new("/obj/{module}/{module}.c", data)`
5. The data mapping is passed as a constructor argument

The base class receives this data in `virtual_setup()`:

```lpc
varargs void virtual_setup(mixed args...) {
    mapping data;
    if(!args || !mapp(args[0])) return;
    data = args[0];

    if(!nullp(data["id"])) set_id(data["id"]);
    if(!nullp(data["name"])) set_name(data["name"]);
    if(!nullp(data["short"])) set_short(data["short"]);
    if(!nullp(data["long"])) set_long(data["long"]);
    if(!nullp(data["mass"])) set_mass(data["mass"]);
    if(!nullp(data["value"])) set_value(data["value"]);
    // ... type-specific properties
}
```

## Referencing Virtual Objects in Code

```lpc
// Clone a virtual food item
object cheese = new("/obj/food/cheese.food");

// Clone a mob
object rat = new("/d/mobs/waste_rat.mob");

// Add to loot tables, room inventory, etc.
add_inventory("/obj/loot/rabbit_fur.loot");
```

No registration needed — the virtual system handles compilation automatically based on file extension.

## Creating a New Virtual Object Type

To add an entirely new type (e.g., `.potion`):

### 1. Create the base class

`obj/potion/potion.lpc`:

```lpc
inherit STD_ITEM;

varargs void virtual_setup(mixed args...) {
    mapping data;
    if(!args || !mapp(args[0])) return;
    data = args[0];

    if(!nullp(data["id"])) set_id(data["id"]);
    if(!nullp(data["name"])) set_name(data["name"]);
    if(!nullp(data["short"])) set_short(data["short"]);
    if(!nullp(data["long"])) set_long(data["long"]);
    if(!nullp(data["mass"])) set_mass(data["mass"]);
    if(!nullp(data["value"])) set_value(data["value"]);
    // ... potion-specific setup
}
```

### 2. Create the compile module

`adm/daemons/modules/virtual/potion.lpc`:

```lpc
inherit __DIR__ "ob";
```

That's it — inheriting from `ob.lpc` gives you the standard compile flow that reads `/obj/potion/{name}.lpml` and creates `/obj/potion/potion.lpc` with the data.

### 3. Create LPML data files

`obj/potion/healing.lpml`:

```lpml
{
  id: ["potion", "vial"],
  adj: ["healing"],
  name: "healing potion",
  short: "a vial of {{CC0000}}healing potion{{res}}",
  long: "A small glass vial filled with a glowing red liquid.",
  mass: 5,
  value: 50,
  properties: {
    hp restore: 25,
  },
}
```

### 4. Use it

```lpc
object potion = new("/obj/potion/healing.potion");
```

## Routing Fallbacks

If no extension module matches, VIRTUAL_D tries:

1. **Directory name concatenation**: `/player/gesslar` → `modules/virtual/player.lpc`
2. **Top-level directory**: `/d/forest/5,10,0` → `modules/virtual/d.lpc`

This is how non-extension-based virtual objects (players, ghosts, zones) are routed.

## Common Pitfalls

- **File extension mismatch**: the `.food` extension routes to `food.lpc` module, which reads `.lpml` files. The extension in the path (`cheese.food`) is different from the data file (`cheese.lpml`).
- **LPML not LPC**: data files use LPML syntax (`{}`, `[]`, unquoted keys, spacey keys) not raw LPC mapping syntax (`([`, `({`).
- **Mob type field**: the `type` property must match a file in `std/mobs/` (e.g., `"mammal"` → `std/mobs/mammal.lpc`).
- **virtual_setup not setup**: data processing happens in `virtual_setup()`, which runs after the normal setup chain.
- **New module inherits ob.lpc**: for standard item types, just `inherit __DIR__ "ob"` — the base module handles LPML reading, path construction, and object creation.
