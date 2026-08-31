---
title: Preferences
description: Per-character settings managed with the set command.
sidebar:
  order: 2
---

Preferences are per-character settings you manage with the `set` command. They control colour, paging, notifications, GMCP, and -- for wizards -- a handful of custom messages and debugging aids.

## Setting a Preference

```
set <preference> <value>     set a preference
set <preference>             clear a preference
set                          list your current preferences
```

For any preference whose name ends in `_colour`, you can pick a colour interactively instead of typing a code:

```
set highlight_colour prompt
```

## Player Preferences

These apply to every character.

| Preference | Default | Description |
|---|---|---|
| `auto_tune` | `all` | Channels to auto-tune on login. Space-separate names, or `all`. |
| `biff` | `on` | Mail notifications on login and on receipt. (`on`/`off`) |
| `colour` | `off` | Whether colour is sent to your terminal. (`on`/`off`) |
| `combat_hit_colour` | unset | Colour used for your combat hits. |
| `combat_miss_colour` | unset | Colour used for your combat misses. |
| `email` | unset | Your email address. |
| `feedback` | `on` | Whether system feedback messages (`ok`/`error`/`warn`/`info`) include their decoration symbol. Screen reader clients never receive decoration. (`on`/`off`) |
| `gmcp` | `on` | Whether [GMCP](/systems/gmcp/) data is sent to your client. (`on`/`off`) |
| `highlight` | `on` | Highlight items of interest in room and object descriptions. (`on`/`off`) |
| `highlight_colour` | `243` | Colour used for highlighting. Use `colour list` for available codes. |
| `keepalive` | `on` | Send keepalive packets to your client. (`on`/`off`) |
| `morelines` | `20` | Lines shown before the `more` prompt pauses. |
| `page_display` | `percent` | Pager position readout. (`percent`/`lines`) |
| `prompt` | `>` | Your command prompt. |
| `screenreader` | `off` | Screen reader mode. Auto-enabled if the game detects a screen reader client. (`on`/`off`) |
| `unicode` | `on` | Use Unicode characters where available. (`on`/`off`) |

## Administrator Preferences

These additional preferences are available to wizards. The custom-message preferences substitute tokens into the text you provide; you may also write your name in literally if you prefer.

| Preference | Description |
|---|---|
| `log_level` | Verbosity of body/user event logging to `debug.log`, `1` (least) to `4` (most). `0` or unset disables it. Generates a lot of output -- remember to turn it off. |
| `look_filename` | Show source filenames on `look`. `on` shows for rooms only, `all` shows for rooms and objects, `off` shows neither. |
| `custom_clone` | Message printed when you clone an object. `$N` -> your name, `$O` -> the object's name. |
| `custom_dest` | Message printed when you destruct an object. `$N` -> your name, `$O` -> the object's name. |
| `move_in` | Message shown to the room you move into. `$N` -> your name, `$D` -> the exit used. |
| `move_out` | Message shown to the room you move out of. `$N` -> your name, `$D` -> the exit used. |
| `teleport_in` | Message shown to the room you teleport into. `$N` -> your name, `$D` -> the destination. |
| `teleport_out` | Message shown to the room you teleport from. `$N` -> your name, `$D` -> the origin. |
| `start_location` | Where you log in. Defaults to the workroom in your home directory if it exists, otherwise the standard player start. |
