---
title: GMCP
description: Out-of-band client/server communication in both directions.
---

GMCP (Generic MUD Communication Protocol) is an out-of-band channel between the MUD and the client. It carries structured data -- character vitals, room info, inventory, chat, client identification -- alongside the normal text stream. Oxidus implements GMCP in both directions: messages received **from** the client and messages sent **to** it.

## How It Works

The two directions use separate machinery:

- **Incoming** (client -> server) is handled by the `EXT_GMCP` module on the player and login objects, which parses each message and routes it to a handler file by package name.
- **Outgoing** (server -> client) flows through the GMCP daemon (`GMCP_D`), which routes a package to a daemon module that formats the payload and sends it.

All package names, keys, and values are defined in `include/gmcp_defines.h` and should be referenced by their `GMCP_*` macros rather than written as literal strings.

## Incoming: Client to Server

When a GMCP message arrives, the driver calls `gmcp(string message)` on the user or login object. That function lives in `std/ext/gmcp.c` (`EXT_GMCP`), inherited by both `std/living/player.c` and `adm/obj/login.c`. It does **not** gate on whether the player has GMCP enabled -- this ensures the `Core.Hello` and `Core.Supports` handshake still runs during login.

The message is parsed by `GMCP_D->convert_message()` into a `ClassGMCP`, which splits the dotted name into its parts:

```lpc
class ClassGMCP {
  string name;       // "Core.Supports.Set"
  string package;    // "Core"
  string module;     // "Supports"
  string submodule;  // "Set"
  mixed  payload;    // JSON-decoded data, or null
}
```

It is then routed to `std/handlers/gmcp/<Package>.c`, calling the function named after the module:

- `Core.Hello` -> `Core.c::Hello(payload)`
- `Core.Supports.Set` -> `Core.c::Supports("Set", payload)`
- `Char.Items.Inv` -> `Char.c::Items("Inv", null)`

If no handler file exists for the package, the miss is logged to `system/gmcp`.

### Supported Incoming Packages

| Package | Handler | Purpose |
|---|---|---|
| `Core.Hello` | `Core.c` | Stores client name/version (login only) |
| `Core.Supports.Set/Add/Remove` | `Core.c` | Tracks which packages the client supports |
| `Core.Ping` | `Core.c` | Echoes a pong (rate-limited, 60s cooldown) |
| `Char.Login.Credentials` | `Char.c` | Authenticates and replies with `Char.Login.Result` |
| `Char.Items.Inv/Room/Contents` | `Char.c` | Sends inventory, room, or container item lists |
| `External.Discord.Hello/Get` | `External.c` | Discord integration info |

Handler modules inherit `std/handlers/gmcp/gmcp_module.c`, which provides the per-player cooldown system used to rate-limit requests like `Core.Ping`.

## Outgoing: Server to Client

Game code sends data by calling the daemon:

```lpc
#include <daemons.h>
#include <gmcp_defines.h>

GMCP_D->send_gmcp(tp, GMCP_PKG_CHAR_VITALS);
```

`GMCP_D` identifies the package and dispatches to the matching daemon module under `adm/daemons/modules/gmcp/` (`Char`, `Client`, `Comm`, `Core`, `Room`). That module assembles the payload -- when none is supplied it sends the full default set -- and calls `do_gmcp()` on the target to JSON-encode and transmit it. So a bare `send_gmcp(tp, GMCP_PKG_CHAR_VITALS)` causes the `Char` module to gather and send the player's current vitals.

## Adding a Handler

**Incoming, existing package:** add a function named after the module to the handler file (e.g. `Skills()` in `Char.c`), and add any new `GMCP_PKG_*` define. Routing finds it automatically.

**Incoming, new package:** create `std/handlers/gmcp/<Package>.c`, `inherit __DIR__ "gmcp_module";`, and add the defines. The router locates it by file name.

**Outgoing:** add a function for the package to the appropriate daemon module under `adm/daemons/modules/gmcp/`, then call `GMCP_D->send_gmcp()` from game code.

## Key Files

| File | Role |
|---|---|
| `std/ext/gmcp.c` | `EXT_GMCP` -- incoming entry point and `do_gmcp()` sender |
| `std/handlers/gmcp/` | Incoming handler modules (`Core`, `Char`, `External`) |
| `std/handlers/gmcp/gmcp_module.c` | Handler base class -- cooldown system |
| `adm/daemons/gmcp.c` | `GMCP_D` -- parsing and outgoing routing |
| `adm/daemons/modules/gmcp/` | Outgoing daemon modules (`Char`, `Client`, `Comm`, `Core`, `Room`) |
| `std/classes/gmcp.c` | `ClassGMCP` structure |
| `include/gmcp_defines.h` | All `GMCP_*` package, key, and value defines |
