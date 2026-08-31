---
name: room-creation
description: Create rooms for Oxidus. Covers the setup chain, exits, descriptions, items, doors, terrain, zones, room metadata, and monster spawning.
---

# Room Creation Skill

You are creating rooms for Oxidus. Rooms use a function-based API — prefer calling functions (`set_long()`, `set_exits()`, `set_items()`, `add_exit()`) over raw `set()` property calls wherever functions exist.

## Inheritance Pattern

Rooms use a layered inheritance chain for area organisation:

```
STD_ROOM                            <- Base room class
  +-- d/{area}/{area_base}.c        <- Area base (sets zone, terrain)
       +-- d/{area}/{room}.c        <- Individual room (exits, descriptions)
```

Each layer uses a different setup function to avoid overriding parent setup.

## Setup Chain

The room class calls these functions in order during initialisation:

```c
mudlib_setup()       -> Internal library setup (don't override)
base_setup()         -> Rare — foundational defaults
pre_setup_0..4()     -> Pre-setup hooks (area bases use these)
setup()              -> Main room setup: exits, descriptions, items
post_setup_0..4()    -> Post-setup hooks
```

**Convention:**
- Area bases use `pre_setup_1()` (or similar) for zone/terrain shared by all rooms
- Individual rooms use `setup()` for exits, descriptions, items

## Room Base Class

`STD_ROOM` (`std/room/room.lpc`) inherits from:
- `STD_OBJECT` — descriptions, IDs, setup chain
- `STD_CONTAINER` — inventory (ignores capacity/mass by default)
- `exits.lpc` — exit management
- `items.lpc` — examinable room details
- `light.lpc` — light levels
- `terrain.lpc` — terrain type
- `zone.lpc` — zone membership
- `door.lpc` — door state management

## API Reference

### Descriptions

```lpc
// Short description (one-line, shown in room lists and movement)
set_short("Village Square of Olum");

// Long description
set_long("At the village centre lies a bustling square, surrounded by "
"ancient, timber-framed buildings. Cobblestone paths lead to a "
"moss-covered stone well.");
```

### Items (Examinable Details)

```lpc
// Set all items at once (replaces existing)
set_items(([
    "mirrors" :
    "The gold-framed mirrors reflect the light beautifully.",
    "chandelier" :
    "The massive crystal chandelier casts prismatic colours.",
    ({ "cobblestone paths", "paths", "cobblestones" }) :
    "Worn smooth by countless footsteps, the cobblestone paths "
    "weave through the square.",
]));

// Add individual items
add_item("statue", "A weathered stone statue of a forgotten king.");

// Remove an item
remove_item("statue");
```

Items can use arrays for aliases — all elements in the array share the same description. Descriptions can be strings, function pointers, or `"@@func_name"` to call a function on the room.

### Exits

```lpc
// Set all exits at once
set_exits(([
    "north": "village_path1",
    "south": "village_path2",
    "down" : "../tunnels/0,0,-1",
]));

// Add/remove individual exits
add_exit("east", "market");
remove_exit("east");
```

Exit paths are resolved relative to the room's directory — no need for `__DIR__` or absolute paths (though both work).

### Pre/Post Exit Functions

```lpc
// Gate movement in a specific direction
add_pre_exit_func("north", "checkNorth");

int checkNorth(object who) {
    if(!who->query("has_key")) {
        tell(who, "The gate is locked.\n");
        return 1;  // Block movement
    }
    return 0;  // Allow movement
}

// Run something after a player uses an exit
add_post_exit_func("south", "afterSouth");
```

### Doors

Doors use the `class Door` system:

```lpc
#include <classes.h>
inherit CLASS_DOOR;

void setup() {
    set_exits(([
        "north": "porch",
        "east" : "salon",
    ]));

    add_door(new(class Door,
        id: "foyer door",
        direction: "north",
        short: "A grand door",
        long: "A grand door that leads to the porch."
    ));
}
```

Door functions:
- `add_door(door)` / `remove_door(direction)`
- `set_door_open(dir, bool)` / `set_door_locked(dir, bool)`
- `is_door_open(dir)` / `is_door_locked(dir)`
- `query_door_status(dir, asNumber)` — string or `1`=open, `2`=closed, `3`=locked
- `reset_doors()` — syncs door states with connected rooms (called automatically on reset)

### Zone

```lpc
// Set in area base — shared by all rooms in the area
set_zone(__DIR__ "olum");    // Path to the zone object

// Query
query_zone_name();
query_zone();
```

### Terrain

```lpc
set_terrain("forest");
```

Valid terrain types: `"city"`, `"road"`, `"indoor"`, `"outdoor"`, `"forest"`, `"grass"`, `"ocean"`, `"plains"`, `"swamp"`, `"tunnels"`, `"wastes"`

### Room Metadata

```lpc
// Classification
set_room_type("shop");           // Primary type
set_room_subtype("armourer");    // Secondary classification
set_room_icon("shield");         // Icon for maps/displays

// Display
set_room_colour(42);             // Colour for map display
set_room_size(({2, 2, 1}));      // Width, length, height (default {1,1,1})
                                  // Affects movement cost calculations

// Environment
set_room_environment("underground"); // Affects gameplay mechanics

// Light
set_light(1);                    // 1 = lit, 0 = dark

// GMCP
add_custom_gmcp("special", "data");  // Custom GMCP data for clients
set_no_gmcp_room_info(1);           // Disable GMCP room info broadcasting
```

### Movement Cost

Movement cost is calculated automatically from room size:
- Cardinal directions (north/south) use width, (east/west) use length
- Diagonal directions average the relevant dimensions
- Up/down use height
- Cost = dimension * base cost (2.0)

### Monster/NPC Spawning

```lpc
// Use add_reset() for respawning on room reset
private nosave object *mobs = ({});

void base_setup() {
    add_reset((: repopulate :));
}

void repopulate() {
    mobs -= ({ 0 });  // Remove dead/destructed

    if(random_float(100.0) < 30.0) {
        mobs += ({ add_inventory("/d/forest/mob/wolf") });
    }
}
```

### Room Inventory

```lpc
add_inventory("/obj/torch");     // Clone and add object to room
```

## Complete Room Example

```lpc
// /d/village/square.lpc

inherit __DIR__ "village_base";

void setup() {
    set_short("Village Square of Olum");
    set_long(
    "At the village centre lies a bustling square, surrounded by ancient, "
    "timber-framed buildings. Cobblestone paths lead to a moss-covered stone "
    "well, the communal heart where market stalls flaunt local produce.");

    set_exits(([
        "north": "village_path1",
        "west" : "village_path2",
        "east" : "village_path3",
        "south": "village_path4",
        "down" : "../tunnels/0,0,-1",
    ]));

    set_room_size(({2, 2, 1}));

    set_items(([
        ({ "timber-framed buildings", "buildings" }) :
        "The buildings surrounding the square are a testament to the "
        "village's history.",
        ({ "moss-covered stone well", "well", "stone well" }) :
        "At the heart of the square stands the village well, its stones "
        "partially covered in a soft blanket of moss.",
        ({ "market stalls", "stalls" }) :
        "Colourful awnings and wooden counters mark the market stalls.",
    ]));
}
```

## Complete Door Example

```lpc
// /d/village/manor/foyer.lpc

#include <classes.h>

inherit __DIR__ "manor";
inherit CLASS_DOOR;

void setup() {
    set_short("The Foyer");
    set_long("You step into a grand foyer that is both overwhelming and "
    "extravagant. The walls are lined with gold-framed mirrors that reflect "
    "the light from a massive crystal chandelier.");

    set_exits(([
        "north": "porch",
        "south": "hall1",
        "east" : "salon",
    ]));

    set_items(([
        "mirrors" :
        "The gold-framed mirrors reflect the light beautifully.",
        "chandelier" :
        "The massive crystal chandelier casts prismatic colours.",
    ]));

    add_door(new(class Door,
        id: "foyer door",
        direction: "north",
        short: "A grand door",
        long: "A grand door that leads to the porch."
    ));

    add_door(new(class Door,
        id: "salon door",
        direction: "east",
        short: "A grand door",
        long: "A grand door that leads to the salon."
    ));
}
```

## Area Base Template

```lpc
// /d/{area}/{area}_base.lpc

inherit STD_ROOM;

void pre_setup_1() {
    set_zone(__DIR__ "zone_name");
    set_terrain("road");
}
```

## Key Files

| File | Purpose |
|---|---|
| `std/room/room.lpc` | Base room class |
| `std/room/exits.lpc` | Exit management (`set_exits`, `add_exit`, pre/post functions) |
| `std/room/items.lpc` | Examinable details (`set_items`, `add_item`) |
| `std/room/door.lpc` | Door state management |
| `std/room/terrain.lpc` | Terrain types |
| `std/room/zone.lpc` | Zone assignment |
| `std/room/light.lpc` | Light levels |
| `std/classes/door.lpc` | `class Door` definition |
| `std/zones/zone.lpc` | Zone daemon |

## Common Pitfalls

- **Using raw `set()` instead of functions**: prefer `set_exits()`, `set_items()`, `set_long()` etc.
- **Overriding `setup()` in an area base**: use `pre_setup_1()` or similar for shared area config. Individual rooms use `setup()`.
- **Absolute exit paths**: exit paths are resolved relative to the room's directory. Use relative paths like `"village_path1"` or `"../tunnels/room"`.
- **Missing `CLASS_DOOR` inherit**: rooms with doors must `inherit CLASS_DOOR` and `#include <classes.h>`.
