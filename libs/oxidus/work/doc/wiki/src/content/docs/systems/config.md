---
title: Configuration
description: Cascading LPML configuration through CONFIG_D and mud_config().
---

Game configuration is held by the configuration daemon (`CONFIG_D`) and read everywhere through the `mud_config()` simul_efun. Settings live in LPML files using a cascading two-file pattern: shipped defaults plus local overrides that survive upgrades.

## How It Works

`CONFIG_D` loads two files, in order:

| File | Tracked in git? | Purpose |
|---|---|---|
| `adm/etc/default.lpml` | yes | Shipped defaults |
| `adm/etc/config.lpml` | no (`.gitignore`d) | Local overrides for your instance |

The daemon reads `default.lpml` first to establish the baseline, then merges `config.lpml` on top. The merge is a **shallow** mapping addition (`+=`) -- any top-level key in `config.lpml` replaces the same key from the defaults. Nested mappings replace as a whole; they do not deep-merge. Because your overrides live in a separate, untracked file, they are preserved across updates to the library.

Sensitive values -- API tokens, webhooks, Discord/Grapevine credentials -- belong in `config.lpml`, never in `default.lpml`.

## Reading Configuration

Read any value with the `mud_config()` simul_efun. It is available everywhere with no `#include`:

```lpc
string status = mud_config("OPEN_STATUS");
```

The key may be a flat top-level key (`"PORT"`) or a dot-separated path into nested mappings, resolved via `dot_walk`. Prefer the dotted path over cracking open a returned sub-mapping at the call site -- it keeps the schema inside the config layer:

```lpc
// Preferred -- opaque key, single call:
int chance = mud_config("RESOURCE.GLOBAL_SPAWN_CHANCE");

// Avoid -- exposes the structure to the caller:
int chance = mud_config("RESOURCE")["GLOBAL_SPAWN_CHANCE"];
```

`mud_config()` raises an error for unknown keys, so do not call it speculatively. If a key might not exist, walk `CONFIG_D->get_all_config()` yourself instead.

## Daemon API

`CONFIG_D` inherits `STD_DAEMON` and exposes:

| Function | Signature | Purpose |
|---|---|---|
| `get_mud_config(key)` | `mixed get_mud_config(string key)` | Get one value by flat key or dot-path. `mud_config()` wraps this. |
| `get_all_config()` | `mapping get_all_config()` | Returns a copy of the entire config mapping. |
| `rehash_config()` | `void rehash_config()` | Reloads both files and re-merges. Runs automatically on startup. |

## Adding a Configuration Key

1. Add the default in `adm/etc/default.lpml`:

   ```lpml
   MY_NEW_KEY: "default_value",
   ```

2. Read it in code:

   ```lpc
   string val = mud_config("MY_NEW_KEY");
   ```

3. To override it locally, add the key to `adm/etc/config.lpml` (create the file if needed):

   ```lpml
   {
     MY_NEW_KEY: "local_override",
   }
   ```

Keys are case-sensitive and uppercase by convention.

## Rehashing at Runtime

After editing either file, reload without restarting the game by running the `master` admin command (which rehashes config among other reloads), or by calling `CONFIG_D->rehash_config()` directly. The `mudconfig` wizard command dumps the entire current configuration for inspection.

## A Note on Driver Configuration

This system covers *library* configuration. Driver-level settings -- ports, stack sizes, protocol toggles -- are separate: they use `get_config()`/`set_config()` with constants from `include/runtime_config.h` and are not part of `CONFIG_D`.

## Key Files

| File | Role |
|---|---|
| `adm/daemons/config.c` | `CONFIG_D` -- loads, merges, and serves configuration |
| `adm/simul_efun/system.c` | `mud_config()` simul_efun |
| `adm/etc/default.lpml` | Shipped default settings |
| `adm/etc/config.lpml` | Local overrides (not tracked) |
| `cmds/dev/mudconfig.c` | `mudconfig` command -- dumps current config |
