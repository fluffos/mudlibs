---
title: Loot
description: Item and coin drops from NPCs.
---

The loot system handles item and coin drops from NPCs. It is entirely data-driven -- loot items and NPC loot tables are defined in LPML files, compiled on demand by the virtual object system, and dropped into corpses on death.

## How It Works

When an NPC dies, the death sequence calls the loot daemon (`LOOT_D`) which:

1. Iterates the NPC's loot table -- each entry is an `[item, chance]` pair
2. Rolls against the chance (0--100%) to decide whether the item drops
3. Resolves the item (which may be a file path, weighted map, array pool, or function)
4. Creates the loot object via `new()` -- for `.loot` files, the virtual system compiles them from LPML
5. Auto-values the item if the `autovalue` property is set
6. Moves the item into the corpse

Coin drops follow a similar flow using a separate coin table.

## Defining Loot Items

Loot items are LPML data files in `obj/loot/`. The file extension `.loot` tells the virtual daemon to route compilation through the loot module.

```lpml
// obj/loot/boar_tusk.lpml
{
  id: ["tusk"],
  additional ids: ["tooth"],
  adj: ["boar", "sharp"],
  name: "boar tusk",
  short: "a sharp boar tusk",
  long: "This is a curved, sharp tusk from a wild boar. It could be used for "
        "crafting or as a primitive weapon.",
  mass: 20,
  material: ["bone"],
  properties: {
    autovalue: true,
    crafting material: true,
  },
}
```

| Field | Description |
|---|---|
| `id` | Identification strings players can use to refer to the item |
| `additional ids` | Extra IDs beyond the primary set |
| `adj` | Adjectives for identification (e.g. "sharp tusk", "boar tusk") |
| `name` | Display name |
| `short` | Short description shown in inventory and room listings |
| `long` | Full description shown on `look` |
| `mass` | Weight of the item |
| `material` | Material tags for crafting or other systems |
| `properties` | A mapping of custom properties (see below) |

### Properties

| Property | Effect |
|---|---|
| `autovalue` | When `true`, the item's coin value is calculated automatically based on the NPC's level |
| `crafting material` | Tags the item as a crafting ingredient |

## Assigning Loot to NPCs

NPC definitions in LPML include `loot`, `loot chance`, and `coins` fields:

```lpml
// d/mobs/wild_boar.lpml
{
  type: "mammal",
  name: "wild boar",
  short: "wild boar",
  long: "A wild boar is here, snuffling around for food. Its tusks look sharp "
        "and dangerous.",
  id: ["wild boar", "boar"],
  weapon name: "tusks",
  weapon type: "piercing",
  level: [1, 2],
  gender: ["male", "female"],
  race: "pig",
  loot: [
    "/obj/loot/boar_skin.loot",
    "/obj/loot/boar_tusk.loot",
    "/obj/food/raw_pork.food",
  ],
  loot chance: 75.0,
  coins: {
    copper: [1, 100.0],
    silver: [1, 50.0],
  },
}
```

| Field | Description |
|---|---|
| `loot` | Array of item paths to drop |
| `loot chance` | Default drop chance (0--100%) applied to each item |
| `coins` | Mapping of currency type to `[amount, chance]` pairs |

Each item in `loot` is added to the NPC's loot table with the `loot chance` as its drop probability. The `coins` entries are rolled independently.

## Code-Based Loot

NPCs written in LPC can use the `EXT_LOOT` module directly:

```lpc
inherit STD_NPC;

void setup() {
  // ... NPC setup ...

  // Simple: file path with default 100% chance
  add_loot("/obj/loot/boar_tusk.loot");

  // With explicit chance
  add_loot("/obj/loot/boar_skin.loot", 75.0);

  // Weighted map -- element_of_weighted() picks one
  add_loot(([
    "/obj/loot/common_item.loot" : 80,
    "/obj/loot/rare_item.loot"   : 20,
  ]), 50.0);

  // Coins
  add_coin("copper", 3, 100.0);
  add_coin("silver", 1, 50.0);
}
```

### EXT_LOOT API

| Function | Description |
|---|---|
| `add_loot(item, chance)` | Add an item to the loot table. Item can be a string path, mapping, array, or function. Chance defaults to 100%. |
| `set_loot_table(table)` | Replace the entire loot table |
| `query_loot_table()` | Returns a copy of the loot table |
| `add_coin(type, amount, chance)` | Add a coin drop entry |
| `set_coin_table(table)` | Replace the entire coin table |
| `query_coin_table()` | Returns a copy of the coin table |

## Item Resolution

The loot daemon resolves items recursively. The `item` field in each loot table entry can be:

| Type | Behavior |
|---|---|
| **String** | Used directly as a file path to `new()` |
| **Mapping** | Treated as a weighted selection -- `element_of_weighted()` picks one key, then resolves it |
| **Array** | A random element is picked from the pool |
| **Function** | Called as `f(killer, npc)` and the return value is resolved recursively |

## Auto-Valuation

Items with the `autovalue` property have their coin value calculated based on the NPC's level:

- Base value = `level * COIN_VALUE_PER_LEVEL`
- A random variance (configured by `COIN_VARIANCE`) is applied
- The result is set as the item's sale value

This means the same loot item scales in value depending on what dropped it.

## Key Files

| File | Role |
|---|---|
| `adm/daemons/loot.c` | Loot daemon -- handles drops, item processing, auto-valuation |
| `std/ext/loot.c` | `EXT_LOOT` module -- loot table management for NPCs |
| `adm/daemons/modules/virtual/loot.c` | Virtual compiler for `.loot` files |
| `obj/loot/loot.c` | Base loot object class |
| `obj/loot/*.lpml` | Loot item data files |
| `d/mobs/*.lpml` | NPC definitions with loot tables |
