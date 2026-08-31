---
name: help-file-creation
description: Create new help files for Oxidus. Covers file location, plain text format, search paths, command-based help via query_help(), and the autodoc system.
---

# Help File Creation

You are creating help files for Oxidus. The help system has two sources: static help files in the `doc/` directory and dynamic help from command objects via `query_help()`.

## Static Help Files

### Location and Naming

Help files are plain text files stored without extension in `doc/` subdirectories:

| Directory | Audience | Searched When |
|---|---|---|
| `doc/general/` | All players | Always |
| `doc/game/` | All players | Always |
| `doc/help/developer/` | Developers | `devp(tp)` is true |
| `doc/driver/efun/` | Developers | `devp(tp)` is true |
| `doc/driver/apply/` | Developers | `devp(tp)` is true |
| `doc/admin/` | Admins | `adminp(tp)` is true |

- Filenames are the topic name exactly as the player types it: `help preferences` reads `doc/general/preferences`
- Multi-word topics use spaces in the filename: `environmental variables`
- No file extension

### Format

Help files are **plain text**. No structured markup system — just write readable content.

```
The following preferences are available to be configured via the 'set' command:

auto_tune - what channels, if any, to auto-tune upon login
Default: all

colour - whether to use colour in the game.
Default: off
Options: on/off
```

Colour codes using the `{{hex}}` syntax can be used in help files (see the colour-coding skill).

### How Help Search Works

The help command (`cmds/std/help.lpc`) searches in this order:

1. **Command path** — checks if `<verb>.c` exists in the player's PATH and has `query_help()`
2. **Help directories** — searches `HELP_PATH` (`doc/general/`, `doc/game/`) for a matching file
3. **Dev directories** — if player is a developer, also checks `doc/help/developer/`, `doc/driver/efun/`, `doc/driver/apply/`
4. **Admin directory** — if player is admin, also checks `doc/admin/`

If nothing is found, the failed search is logged to `log/help.log`.

Output is wrapped in a decorative border and paged to the player.

## Command-Based Help

Commands provide help via two mechanisms:

### query_help() Function

```lpc
string query_help(object tp) {
    return
"SYNTAX: force <living> to <cmd>\n\n"
"Force a living object to execute a command.";
}
```

Or using `@text` heredoc syntax:

```lpc
string query_help(object tp) {
    return @text
Syntax: do cmd,cmd,cmd,...

Executes a list of commands separated by commas.
text;
}
```

### help_text / usage_text Variables

Set in `setup()` — available on commands inheriting `STD_CMD`:

```lpc
void setup() {
    usage_text =
"drop <object>\n"
"drop all\n"
"drop all <object>\n";
    help_text =
"This command will allow you to drop an object you are currently holding onto "
"the ground.\n\nSee also: get, put\n";
}
```

Command-based help takes priority over file-based help (the command path is searched first).

## Autodoc System

The autodoc daemon (`adm/daemons/autodoc.lpc`) parses JSDoc-style comments from LPC source files and generates documentation automatically.

Supported tags: `@description`, `@def`, `@param`, `@returns`, `@example`

Run via the `autodoc scan` developer command.

## Creating a New Help File

1. Choose the appropriate directory based on audience
2. Create a plain text file named exactly as the topic
3. Write clear, readable content
4. Use "See also:" at the end to reference related topics
5. Test in-game with `help <topic>`

### Example: Player Help File

File: `doc/general/combat`
```
Combat in the game is initiated by using the 'attack' command on a target.

Once in combat, your character will automatically attack each round. You can
use abilities and spells during combat for additional effects.

Useful commands:
  attack <target>  - Begin combat with a target
  flee             - Attempt to escape combat
  consider <target> - Evaluate a target's strength

See also: commands
```

### Example: Developer Help File

File: `doc/help/developer/virtual_objects`
```
Virtual objects are data-driven objects loaded from definition files rather
than compiled LPC source.

The virtual object system uses compile servers that intercept file loads
and generate objects from data files (e.g., .lpml files).

Key files:
  std/virtual/server.lpc     - Base virtual compile server
  adm/daemons/virtual.lpc    - Virtual object daemon

See also: getting_started
```
