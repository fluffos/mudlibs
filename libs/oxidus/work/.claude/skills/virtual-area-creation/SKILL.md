---
name: virtual-area-creation
description: Create virtual (procedurally generated) areas for Oxidus. Covers zone daemons, virtual servers, room templates, map daemons, description daemons, and coordinate-based room generation.
---

# Virtual Area Creation Skill

You are helping create virtual areas for Oxidus. Virtual areas are procedurally generated rooms that don't exist as individual files — instead, coordinate-based paths like `/d/forest/5,10,0` are compiled on-the-fly from a template room and map data.

Virtual areas are used for large open environments: forests, tunnels, wastes, caverns — anywhere hand-building hundreds of rooms would be impractical.

## How Virtual Areas Work

1. Player moves to `/d/forest/5,10,0`
2. No file exists — the driver calls `master->compile_object()`
3. The master delegates to `VIRTUAL_D->compile_object(file)`
4. VIRTUAL_D routes to the zone's `zone.lpc` (inherits `STD_VIRTUAL_SERVER`)
5. The zone's `generate_object()` validates coordinates against a map, then creates a room: `new(template, "5,10,0")`
6. The room's normal `setup()` runs, then `virtual_setup(args)` runs with the coordinate string
7. A description daemon configures exits, short/long descriptions based on coordinates

## Architecture

```
VIRTUAL_D (adm/daemons/virtual.lpc)
    │
    ▼
zone.lpc (STD_VIRTUAL_SERVER)     <- validates coords, creates rooms
    │
    ├── room_base.lpc (STD_ROOM)  <- room template, calls daemon in virtual_setup
    │
    └── area_daemon.lpc (STD_VIRTUAL_MAP)  <- map data, exits, descriptions
```

## Core Files

| File | Purpose |
|---|---|
| `adm/daemons/virtual.lpc` | Central router for all virtual object compilation |
| `std/daemon/virtual_server.lpc` | Base zone class (`STD_VIRTUAL_SERVER`). Handles subzone delegation |
| `std/daemon/virtual_map.lpc` | Map management daemon (`STD_VIRTUAL_MAP`). File-based or procedural maps |
| `std/object/setup.lpc` | Defines `virtual_setup_chain()` |

## Coordinate System

Coordinates use the format `x,y,z` in filenames (e.g., `5,10,0`, `3,7,-1`).

The room's `get_virtual_coordinates()` returns `({ z, y, x })` — note the reversed order internally.

When a daemon method receives coordinates, reorder them:

```lpc
int *coords = room->get_virtual_coordinates();
int x = coords[2], y = coords[1], z = coords[0];
```

## Setup Chain for Virtual Rooms

Virtual rooms run two setup chains:

1. **Normal chain**: `mudlib_setup` → `base_setup` → `pre_setup_0..4` → `setup` → `post_setup_0..4`
2. **Virtual chain**: `virtual_mudlib_setup` → `pre_virtual_setup_0..4` → `virtual_setup` → `post_virtual_setup_0..4` → `virtual_mudlib_complete_setup`

The coordinate string is passed as an argument to `virtual_setup()`.

## Creating a Virtual Area

### Step 1: Draw the Map

ASCII maps use rooms at even positions and connection symbols at odd positions:

```
O-O-O-O
|/|   |
O-O X-O
|\| |/|
O-O-O-O
```

- `O` = walkable room
- `X` = special room (clearing, landmark, etc.)
- `.` or space = no room
- `|` = north/south connection
- `-` = east/west connection
- `/` = NE/SW diagonal
- `\` = NW/SE diagonal

### Step 2: Create the Zone Daemon

`d/{area}/zone.lpc`:

```lpc
inherit STD_VIRTUAL_SERVER;

private mapping area_map = ([]);

void setup() {
    loadMap();
}

private void loadMap() {
    string *lines = explode(read_file(__DIR__ "area_map.txt"), "\n");
    int y = 0, z = 0;
    for(int i = 0; i < sizeof(lines); i += 2) {
        string line = lines[i];
        int x = 0;
        for(int j = 0; j < sizeof(line); j += 2) {
            string ch = line[j..j];
            if(ch == "O" || ch == "X") {
                area_map[sprintf("%d,%d,%d", x, y, z)] = ch;
            }
            x++;
        }
        y++;
    }
}

object generate_object(string file) {
    string *parts;
    int x, y, z;

    parts = dir_file(file);

    if(sscanf(parts[1], "%d,%d,%d", x, y, z) != 3)
        return 0;

    if(!area_map[parts[1]])
        return 0;

    return new(__DIR__ "area_base", parts[1]);
}
```

### Step 3: Create the Room Template

`d/{area}/area_base.lpc`:

```lpc
inherit STD_ROOM;

void repopulate();

private nosave string *mobFiles = ({});
private nosave object *mobs = ({});
private nosave float spawnChance = 10.0;

void setup() {
    set_light(1);
    set_terrain("forest");
}

void virtual_setup(mixed args...) {
    string file = args[0];

    set_zone("area_name");

    __DIR__ "area_daemon"->setup_exits(this_object(), file);
    __DIR__ "area_daemon"->setup_short(this_object(), file);
    __DIR__ "area_daemon"->setup_long(this_object(), file);

    add_reset((: repopulate :));

    mobFiles = ({
        "/mob/wolf",
        "/mob/bear",
    });
}

void repopulate() {
    mobs -= ({ 0 });
    foreach(object mob in mobs) {
        if(objectp(mob)) {
            mob->simple_action("$N $vwander away.");
            mob->remove();
        }
    }

    if(random_float(100.0) < spawnChance) {
        mobs += ({ add_inventory(element_of(mobFiles)) });
    }
}
```

### Step 4: Create the Description Daemon

`d/{area}/area_daemon.lpc`:

```lpc
inherit STD_VIRTUAL_MAP;

private nosave string *areaShorts;
private nosave string *areaLongs;
private nosave string clearingLong;

void setup() {
    apply_map_file(__DIR__ "area_map.txt");
    setupShorts();
    setupLongs();
}

private void setupShorts() {
    areaShorts = ({
        "Dense Woodland",
        "Shadowy Forest",
        "Thick Forest",
    });
}

private void setupLongs() {
    areaLongs = ({
        "You are surrounded by tall trees, their branches intertwining "
        "above you to form a thick canopy.",

        "The forest here is dense, with trees growing close together. "
        "Shafts of sunlight filter through the leaves.",
    });

    clearingLong =
    "You've stumbled upon a small clearing in the dense forest. "
    "Sunlight streams down, illuminating wildflowers and soft grass.";
}

public void setup_short(object room, string file) {
    int *coords = room->get_virtual_coordinates();
    int x = coords[2], y = coords[1], z = coords[0];
    string roomType = get_room_type(z, y, x);

    if(roomType == "X")
        room->set_short("Forest Clearing");
    else
        room->set_short(element_of(areaShorts));
}

public void setup_long(object room, string file) {
    int *coords = room->get_virtual_coordinates();
    int x = coords[2], y = coords[1], z = coords[0];
    string roomType = get_room_type(z, y, x);

    if(roomType == "X")
        room->set_long(clearingLong);
    else
        room->set_long(element_of(areaLongs));
}

public void setup_exits(object room, string file) {
    int *coords = room->get_virtual_coordinates();
    int x = coords[2], y = coords[1], z = coords[0];
    mapping exits = get_exits(z, y, x);

    room->set_exits(exits);
}
```

## STD_VIRTUAL_MAP Methods

The map daemon provides these key functions:

| Method | Purpose |
|---|---|
| `apply_map_file(path)` | Load ASCII map from file |
| `apply_map_generator(func)` | Use a function to generate map data procedurally |
| `get_exits(z, y, x)` | Returns mapping of exits based on map connections |
| `is_valid_room(z, y, x)` | Check if coordinates are a valid room |
| `get_room_type(z, y, x)` | Returns the map character at coordinates |
| `get_map_width()` / `get_map_height()` | Map dimensions |

Supports 8 cardinal directions. Exit symbols: `|` (N/S), `-` (E/W), `/` (NE/SW), `\` (NW/SE).

## STD_VIRTUAL_SERVER Methods

| Method | Override? | Purpose |
|---|---|---|
| `generate_object(path)` | **Yes** | Validate coords, return `new(template, coords)` |
| `compile_object(path)` | No | Handles subzone delegation, then calls `generate_object()` |

Subzone delegation is automatic — if `d/{area}/{subzone}/zone.lpc` exists, requests for `subzone/x,y,z` are forwarded to it.

## Procedural Map Generation

For areas that don't use file-based maps (e.g., noise-generated terrain):

```lpc
inherit STD_VIRTUAL_MAP;

void setup() {
    apply_map_generator((: generateMap :));
}

private mixed *generateMap() {
    // Return 3D array of room data
    // Use simplex noise, cellular automata, etc.
}
```

The wastes area uses simplex noise to determine terrain types; the cavern area uses cellular automata with a "drunk walk" algorithm for 3D maze generation.

## Description Daemon Convention

All description daemons implement these functions:

| Function | Purpose |
|---|---|
| `setup_short(object room, string file)` | Set room's short description |
| `setup_long(object room, string file)` | Set room's long description |
| `setup_exits(object room, string file)` | Add exits to room |

These are called from the room template's `virtual_setup()`.

## Existing Virtual Areas

| Area | Technique | Description |
|---|---|---|
| `d/forest/` | File-based ASCII map | 2D forest with clearings |
| `d/tunnels/` | File-based map, multi-level | Underground tunnels |
| `d/wastes/` | Simplex noise generation | Open wasteland terrain |
| `d/cavern/` | Cellular automata | 3D cave system with z-levels |
| `d/maze/` | Procedural | Multi-floor maze |
| `d/village/field/` | Simple grid | Basic field area |

## Common Pitfalls

- **Coordinate order**: `get_virtual_coordinates()` returns `({ z, y, x })`, not `({ x, y, z })`. Always reorder when passing to daemon methods.
- **Map parsing**: ASCII maps use double-spacing — rooms at even positions (0,2,4...), connection symbols at odd positions (1,3,5...). Skip every other line and character.
- **virtual_setup guard**: The coordinate string comes as `args[0]` in `virtual_setup()`.
- **Subzone delegation**: Zone daemons automatically delegate to `{subzone}/zone.lpc` if it exists. No registration needed.
- **Mob spawning**: Use `add_reset()` with a repopulate function. Clean up old mobs before spawning new ones.
