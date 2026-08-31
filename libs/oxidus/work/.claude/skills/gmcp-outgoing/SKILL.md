---
name: gmcp-outgoing
description: Understand and extend the outgoing GMCP system for Oxidus. Covers the GMCP daemon, send_gmcp routing, all outgoing package modules (Char, Core, Comm, Client, Room), data formats, calling patterns from game code, and how to add new outgoing packages.
---

# GMCP Outgoing Skill

This skill covers the **outgoing** side of GMCP — sending data FROM the MUD TO clients. For receiving GMCP messages from clients, see the **gmcp-incoming** skill.

## Architecture Overview

```
Game code (vitals, combat, inventory, chat, etc.)
       │
       ▼
GMCP_D->send_gmcp(user, package, payload)    ← adm/daemons/gmcp.lpc
       │
       ├─ validates user, checks GMCP enabled
       ├─ routes to module: adm/daemons/modules/gmcp/<Package>.c
       │
       ▼
Module gathers data, calls user->do_gmcp(package, data)
       │                                     ← std/ext/gmcp.lpc (EXT_GMCP)
       ├─ stringifies all values
       ├─ JSON-encodes payload
       └─ sends via send_gmcp() driver efun to client
```

## Core Files

| File | Purpose |
|---|---|
| `adm/daemons/gmcp.lpc` | GMCP daemon (`GMCP_D`). Routes `send_gmcp()` calls to package modules |
| `adm/daemons/modules/gmcp/Char.lpc` | Character data: vitals, status, login, items |
| `adm/daemons/modules/gmcp/Core.lpc` | Protocol: Ping |
| `adm/daemons/modules/gmcp/Comm.lpc` | Communication: channel text |
| `adm/daemons/modules/gmcp/Client.lpc` | Client features: GUI install |
| `adm/daemons/modules/gmcp/Room.lpc` | Room info and travel paths |
| `std/ext/gmcp.lpc` | `EXT_GMCP` module on player/login objects. Provides `do_gmcp()` for final transmission |
| `include/gmcp_defines.h` | All `GMCP_PKG_*`, `GMCP_KEY_*`, `GMCP_VAL_*` defines |

## The send_gmcp() Function

`GMCP_D->send_gmcp(object body, string package, mixed payload)` is the primary way game code triggers outgoing GMCP.

**Guards:**
1. Target must be valid and have GMCP enabled (`body->gmcp_enabled()`)
2. Package must be a valid string

**Routing:**
- Parses package into components via `convert_message()`
- Loads module file: `adm/daemons/modules/gmcp/<Package>.c`
- Calls the module function with appropriate arguments:
  - With submodule: `Module->Function(user, submodule, payload)`
  - Without submodule: `Module->Function(user, payload)`

## broadcast_gmcp()

`GMCP_D->broadcast_gmcp(mixed audience, string package, mixed payload)` sends to multiple targets:

- `audience` can be: a room object (all players in room), a single player, or an array of players
- Calls `send_gmcp()` for each target

## init_gmcp()

`GMCP_D->init_gmcp(object who)` sends the initial GMCP state burst when a player enters the world. Called from login, resurrection, and GMCP enable. Sends: StatusVars, Status, Vitals, Room.Info, and inventory lists.

## Outgoing Packages

### Char.StatusVars

**Module:** `Char.lpc::StatusVars(object who, mapping payload)`

Sends label definitions mapping status keys to human-readable names. Sent once on login so the client knows what each Status field means.

### Char.Status

**Module:** `Char.lpc::Status(object who, mapping payload)`

Character state data: name, fill, capacity, xp, tnl, wealth, current enemy info, etc.

**Triggered by:** vitals changes, combat state changes, wealth changes, advancement, capacity changes.

### Char.Vitals

**Module:** `Char.lpc::Vitals(object who, mapping payload)`

Current and max HP/SP/MP values (all stringified).

**Triggered by:** `set_hp()`, `add_hp()`, `set_sp()`, `add_sp()`, `set_mp()`, `add_mp()` and their max counterparts in `std/living/vitals.lpc`.

### Char.Login

**Module:** `Char.lpc::Login(object who, string submodule, mapping payload)`

- `"Default"` — sends login default data
- `"Result"` — sends authentication result (from incoming Char handler)

### Char.Items

**Module:** `Char.lpc::Items(object who, string submodule, mixed arg)`

Complex inventory management:

| Submodule | Purpose | Data |
|---|---|---|
| `"List"` | Full item list for a location | Array of `([ "name", "id", "attrib", "hash" ])` |
| `"Add"` | Item added to container | `arg = ({ item, container })` |
| `"Remove"` | Item removed | `arg = ({ item, container })` |
| `"Update"` | Item changed (equipped/unequipped) | `arg = ({ item, container })` |

**Attrib flags:** `w` (worn), `W` (wearable), `l` (wielded), `g` (groupable), `c` (container), `t` (takeable), `m` (monster), `d` (dead corpse)

**Triggered by:** `event_gmcp_item_add()`, `event_gmcp_item_remove()`, `event_gmcp_item_update()` in player.lpc. Equipment changes in `std/equip/`.

### Core.Ping

**Module:** `Core.lpc::Ping(object who)`

Echoes back ping for RTT measurement.

### Comm.Channel.Text

**Module:** `Comm.lpc::Channel(object who, string sub, mapping data)`

Chat/communication messages:

```lpc
{
    "channel": "say",
    "talker": "PlayerName",
    "text": "Hello everyone!"
}
```

**Triggered by:** channel daemon, say/tell/whisper commands.

### Client.GUI

**Module:** `Client.lpc::GUI(object who, string submodule, mapping payload)`

- `"Install"` — sends UI package URL and version for client auto-install

### Room.Info

**Module:** `Room.lpc::Info(object who, object room)`

Room information. Calls `room->gmcp_room_info(who)` for custom data.

**Triggered by:** `move()` in `std/living/body.lpc` when entering a new room.

### Room.Travel

**Module:** `Room.lpc::Travel(object who, string *stops)`

Travel path data. Converts stop paths to MD4 hashes.

## When GMCP Gets Sent

### On Login (`init_gmcp()`)

Full initialization burst: StatusVars, Status, Vitals, Room.Info, inventory lists.

### On Events (Immediate)

| Event | Package | Source |
|---|---|---|
| HP/SP/MP change | `Char.Vitals` | `std/living/vitals.lpc` |
| Wealth change | `Char.Status` | `std/living/wealth.lpc` |
| Level/XP change | `Char.Status` | `std/living/advancement.lpc` |
| Combat start/stop | `Char.Status` | `std/living/combat.lpc` |
| Item added/removed | `Char.Items.Add/Remove` | `std/living/player.lpc` |
| Item equipped/unequipped | `Char.Items.Update` | `std/equip/` |
| Capacity change | `Char.Status` | `std/object/contents.lpc` |
| Room change | `Room.Info` | `std/living/body.lpc` |
| Chat message | `Comm.Channel.Text` | `adm/daemons/channels.lpc` |

## Final Transmission: do_gmcp()

`user->do_gmcp(string package, mixed data)` on `EXT_GMCP` performs the actual send:

1. Checks runtime config `__RC_ENABLE_GMCP__`
2. Checks `gmcp_enabled()` on the user
3. Stringifies all data values via `gmcp_stringify()` (GMCP sends everything as strings)
4. JSON-encodes the payload
5. Calls `send_gmcp(message)` driver efun

```lpc
// From module handler code:
who->do_gmcp(GMCP_PKG_CHAR_VITALS, info);
who->do_gmcp(GMCP_PKG_CHAR_ITEMS_LIST, data, 1);  // third arg is pass-through
```

## Adding a New Outgoing Package

### 1. Add defines in `include/gmcp_defines.h`

```lpc
#define GMCP_PKG_CHAR_SKILLS       "Char.Skills"
#define GMCP_PKG_CHAR_SKILLS_LIST  "Char.Skills.List"
```

### 2. Add the handler in the module

In `adm/daemons/modules/gmcp/Char.lpc` (or a new module file):

```lpc
void Skills(object who, string submodule, mixed payload) {
    if(submodule == "List") {
        mapping info = ([]);
        // ... gather skill data from who ...
        who->do_gmcp(GMCP_PKG_CHAR_SKILLS_LIST, info);
    }
}
```

### 3. Trigger from game code

```lpc
GMCP_D->send_gmcp(user, GMCP_PKG_CHAR_SKILLS_LIST);
```

### 4. For a new top-level package

Create `adm/daemons/modules/gmcp/<Package>.c`. The daemon's routing automatically finds it by file name.

## Calling Pattern Summary

**From game code** — use `GMCP_D->send_gmcp()`:
```lpc
GMCP_D->send_gmcp(player, GMCP_PKG_CHAR_VITALS);
GMCP_D->send_gmcp(player, GMCP_PKG_COMM_CHANNEL_TEXT, ([
    "channel" : "say",
    "talker"  : player_name,
    "text"    : message,
]));
```

**Broadcast to a room:**
```lpc
GMCP_D->broadcast_gmcp(room, GMCP_PKG_ROOM_INFO);
```

**From handler modules** — use `who->do_gmcp()`:
```lpc
who->do_gmcp(GMCP_PKG_CHAR_VITALS, data_mapping);
```

## GMCP Defines Reference

All defines in `include/gmcp_defines.h`:

| Pattern | Example | Purpose |
|---|---|---|
| `GMCP_PKG_*` | `GMCP_PKG_CHAR_VITALS` | Package name strings |
| `GMCP_KEY_*` | `GMCP_KEY_CHAR_VITALS_HP` | Data key names |
| `GMCP_VAL_*` | `GMCP_VAL_CHAR_STATUS_DEAD` | Predefined values |
| `GMCP_LIST_*` | `GMCP_LIST_INV`, `GMCP_LIST_ROOM` | List target constants |
