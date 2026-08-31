---
name: object-finding
description: Understand and use the object-finding simul_efuns for Oxidus. Covers find_target, find_targets, find_ob, get_object, present_livings, present_players, present_npcs, present_clones, clones, top_environment, same_env_check, accessible_objects, this_body, and this_caller.
---

# Object Finding Skill

You are helping write or modify code that needs to locate objects in the game world. These are all simul_efuns — available everywhere without `#include`. Follow the `lpc-coding-style` skill for all formatting.

## Quick Reference: Which Function to Use

| Scenario | Function |
|---|---|
| Player command: find one item by name | `find_target(tp, arg, source)` |
| Player command: find all matching items | `find_targets(tp, arg, source)` |
| Get all living creatures in a room | `present_livings(room)` |
| Get all players in a room | `present_players(room)` |
| Get all NPCs in a room | `present_npcs(room)` |
| Find a specific living by name in a room | `get_living(name, room)` |
| Find a specific player by name in a room | `get_player(name, room)` |
| Find all clones of a file in a container | `present_clones(file, container)` |
| Find all clones of a file in the game | `clones(file)` |
| Flexible search with keywords ("me", "here") | `get_object(str, player)` |
| Programmatic file-name match in a container | `find_ob(ob, container)` |
| Get the room an object is ultimately in | `top_environment(ob)` |
| Check if two objects share an environment | `same_env_check(ob1, ob2)` |
| Get all reachable objects in a container | `accessible_objects(container)` |

## Player Command Functions

These are the workhorses for commands — they include **visibility checking** and **ID matching**.

### find_target(user, arg, source, f)

Find a **single** object visible to the user.

```lpc
varargs object find_target(object user, string arg, object source, function f)
```

- `user` — the player/NPC searching (used for visibility checks)
- `arg` — what to search for (matched via `ob->id(arg)`). Supports `"sword 2"` numeric indexing
- `source` — container to search in (defaults to `environment(user)`)
- `f` — optional extra filter function `(: func(ob, user) :)`

```lpc
// Find item in player's inventory
object ob = find_target(tp, arg, tp);

// Find item in the room
object ob = find_target(tp, arg, environment(tp));

// Find second sword in inventory
object ob = find_target(tp, "sword 2", tp);

// With custom filter
object ob = find_target(tp, arg, tp, (: $1->is_edible() :));
```

### find_targets(user, arg, source, f)

Find **all** matching objects visible to the user. Same parameters as `find_target`.

```lpc
varargs object *find_targets(object user, string arg, object source, function f)
```

```lpc
// All visible items in room (no arg = all)
object *obs = find_targets(tp, 0, environment(tp));

// All swords in inventory
object *obs = find_targets(tp, "sword", tp);
```

### Filtering Pipeline

Both functions apply filters in order:
1. `all_inventory(source)` — get everything in the container
2. `filter_by_id(obs, arg)` — keep only objects where `ob->id(arg)` is true (skipped if arg is null)
3. `filter_by_visibility(user, obs)` — keep only objects where `user->can_see(ob)` is true
4. Custom filter function (if provided)

## Room Population Functions

Quick ways to get living objects from a room. No visibility checks — returns all.

### present_livings(room)

All living objects (players + NPCs) in a room.

```lpc
object *present_livings(object room)
// Implementation: filter(all_inventory(room), (: living($1) :))
```

### present_players(room)

Only player characters.

```lpc
object *present_players(object room)
// Implementation: filter(present_livings(room), (: userp :))
```

### present_npcs(room)

Only non-player characters.

```lpc
object *present_npcs(object room)
// Implementation: filter(present_livings(room), (: !userp($1) :))
```

### get_living(id, room)

Find a specific living by name in a room.

```lpc
object get_living(string id, object room)
// Uses present(id, room), then checks living()
```

### get_livings(ids, room)

Find multiple livings by name array.

```lpc
object *get_livings(mixed ids, object room)
// ids can be string or string*
```

### get_player(name, room)

Find a specific player by name in a room.

```lpc
object get_player(string name, object room)
// Uses get_living(), then checks userp()
```

### get_players(names, room)

Find multiple players by name array.

```lpc
object *get_players(mixed names, object room)
```

## Clone Finding Functions

### present_clones(file, container)

Find all clones of a file within a specific container.

```lpc
object *present_clones(mixed file, object container)
```

- `file` — filename string or object (uses `base_name()` if object)
- `container` — where to search (defaults to `previous_object()`)

```lpc
object *coins = present_clones("/std/coin", tp);
object *potions = present_clones(potion_ob, chest);
```

### clones(file, env_only)

Find all clones of a file **game-wide**.

```lpc
varargs object *clones(mixed file, int env_only)
```

- `env_only` — if 1, only return clones that have an environment (filters out "floating" objects)

```lpc
object *all_monsters = clones("/std/monster");
object *placed_monsters = clones("/std/monster", 1);
```

## Flexible Search Functions

### get_object(str, player)

Broad search with special keyword support. Searches through multiple locations.

```lpc
varargs object get_object(string str, object player)
```

**Search order:**
1. `"me"` — returns the player
2. Player inventory (`present(str, player)`)
3. `"here"` / `"env"` / `"environment"` — returns player's environment
4. Environment inventory (`present(str, environment(player))`)
5. `find_player(str)` — global player lookup
6. `find_living(str)` — global living lookup
7. Path resolution (`resolve_path` against the caller's cwd) + `find_object()`/`load_object()` — file-based lookup

The context object defaults to `this_body()` when not supplied. Best for developer commands and flexible user input parsing.

### find_ob(ob, container)

Precise file-based lookup within a container. No visibility checks, no ID matching.

```lpc
varargs object find_ob(mixed ob, mixed cont)
```

- If `ob` is an object: checks `present(ob, cont)`
- If `ob` is a path with `#id`: exact `file_name()` match
- If `ob` is a path without `#`: `base_name()` match

```lpc
find_ob("/obj/sword#42", room);     // Exact clone
find_ob("/obj/sword", player);      // Any clone of sword
find_ob(sword_obj, chest);          // Is this object in chest?
```

## Environment Functions

### top_environment(ob)

Get the outermost environment (usually a room). Traverses up through nested containers, stops at objects where `is_room()` returns true.

```lpc
object top_environment(object ob)
```

```lpc
// sword in backpack in player in room -> returns room
object room = top_environment(sword);
```

### all_environment(ob)

Get all intermediate environments between an object and its room.

```lpc
object *all_environment(object ob)
// Stops at is_room(), does NOT include the room
```

### same_env_check(one, two, top_env)

Check if two objects share an environment.

```lpc
varargs int same_env_check(object one, object two, int top_env)
```

- `top_env = 0` (default): checks immediate `environment()`
- `top_env = 1`: checks `top_environment()` (same room, even if in different containers)

```lpc
// Are they in the same room?
if(same_env_check(player, target, 1)) { ... }

// Are they in the same container?
if(same_env_check(item1, item2)) { ... }
```

## Accessibility Functions

### accessible_objects(container, pov)

Get a nested array of all objects reachable within a container, respecting `inventory_accessible()`.

```lpc
varargs mixed *accessible_objects(object container, object pov)
```

Returns nested structure: `({container, item1, item2, ({subcontainer, sub_item1, sub_item2}), item3})`

Returns `0` if inventory is not accessible.

### accessible_objects_flat(container, pov)

Flat version of `accessible_objects()`.

```lpc
varargs object *accessible_objects_flat(object container, object pov)
```

## Caller Context Functions

### this_body()

The player/NPC executing the current command. Wrapper for `efun::this_player()`.

```lpc
object this_body()
```

### this_caller()

The original initiator of the call chain (through forces/shadows). Wrapper for `efun::this_player(1)`.

```lpc
object this_caller()
```

### caller_is(ob)

Check if the caller matches a specific object or filename.

```lpc
int caller_is(mixed ob)
```

**Note:** Does not work when called from other simul_efun functions.

### getoid(ob)

Get the unique numeric object ID from the driver. Extracts the `#N` from `file_name()`.

```lpc
int getoid(object ob)
// "/obj/sword#42" -> 42
```

## Common Patterns

### Standard command object lookup

```lpc
mixed main(object tp, string arg) {
  if(!arg)
    return _error("Eat what?");

  object ob = find_target(tp, arg, tp);  // search inventory
  if(!ob)
    return _error("You don't have that.");

  if(!ob->is_edible())
    return _error("You can't eat that.");

  // ...
}
```

### Search room then inventory

```lpc
object ob = find_target(tp, arg, environment(tp));
if(!ob)
  ob = find_target(tp, arg, tp);
```

### Find all enemies in room

```lpc
object *npcs = present_npcs(environment(tp));
object *enemies = filter(npcs, (: $1->is_hostile($(tp)) :));
```

### Check interaction range

```lpc
if(!same_env_check(tp, target, 1))
  return _error("They are not here.");
```
