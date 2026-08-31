---
name: mud-telnet
description: Connect to the running Oxidus MUD via telnet to test in-game functionality, reload objects with update, run developer/admin commands, and verify colour rendering. Use when a task requires in-game verification or execution.
---

# MUD Telnet Access

You can connect to the running Oxidus MUD via telnet to test in-game
functionality. This skill covers the connection details, the account →
character login flow, and common recipes.

## When to Use Telnet

Use telnet access for:

- Testing in-game functionality (commands, output, messages, etc.)
- Reloading objects after code changes (`update /path/to/file.lpc`)
- Running developer/admin commands
- Verifying colour code rendering

Do NOT use for:

- Simple file editing (use file tools directly)
- Operations that can be done from the shell or via `fluffos_validate`
- Long-running interactive sessions

## Connection Details

- **Host**: localhost
- **Port**: **1336** (plain telnet)
  - Port 1337 is the TLS port — raw `telnet` cannot speak TLS, so always
    use 1336.
- **Login form**: `character@account` then password (see below)

Oxidus login is **account-based with character selection**. Each account
can own multiple characters. The login object (`/adm/obj/login.lpc`) accepts
a combined `character@account` form at the account prompt, which selects
that character directly and skips the character-select menu — this is the
form to script, because it logs straight into the world with no menu step.

There is a **60-second login timeout**: the login object self-destructs 60
seconds after connecting if you haven't entered the world. Keep the whole
handshake well under that.

## Security Protocol

**NEVER** put credentials directly in command lines. Use environment
variables (these are already set in the environment):

```bash
export OX_TELNET_HOST=127.0.0.1
export OX_TELNET_PORT=1336
export OX_TELNET_USERNAME=character@account
export OX_TELNET_PASSWORD=yourpassword
```

`OX_TELNET_USERNAME` is already the combined `character@account` login
string — send it verbatim at the account prompt.

## Login Sequence

After connecting you'll see the login banner, then:

```
Login as which account?        <- send: character@account
Please enter your password:    <- send: the password
```

If the character belongs to the account, you're dropped straight into the
world. (If you send a bare account name instead of `character@account`,
you'll land on a numbered character-select menu and have to send the
character's list number or `n` to create one — avoid this by always using
the `character@account` form.)

The first character ever created on a fresh MUD is auto-granted admin.

## Clean Output

Two per-character preferences clutter raw telnet output; turn both **off**
at the start of any session that isn't specifically testing them. Both are
saved prefs — set once and they persist across logins.

### Colour

Colour is on/off (no `high`/`low` modes), spelled **`colour`** (Canadian):

```text
> colour off      # no colour codes — use this by default for clean grep
> colour on       # true-colour ANSI output
> colour list     # list available colours
> colour show 42  # preview colour index 42
```

ANSI codes make output hard to read and grep, so **default to `colour
off`**. Flip to `colour on` only when colour rendering itself is what
you're verifying.

### Feedback decorations

System feedback (`_ok`/`_error`/`_info`/`_warn`/`_question`) is prefixed
with a status glyph — `•`/`●`/`◦`/`▲`/`◆`, or `o ` without unicode. That's
the leading `o ` you see on lines like `o Activity logged.`. Turn it off:

```text
> set feedback off    # strip the leading status glyph
> set feedback on     # restore it (default)
```

**Default to `set feedback off`** alongside `colour off` for clean,
greppable output. With it off, `_ok` etc. print just the bare message.

## Activity Logging

**Precede every in-game command with the `claude` command**, e.g.
`claude updating the score command`. This writes a timestamped line to the
`claude` log (`/log/claude`) and pings any online admin so they can watch
the session in real time. It's a `cmds/dev/` command, so it requires the
dev access the `claude` character already has.

```text
> claude <description of what you're about to do>
• Activity logged.
> <actual command>
```

Log the `quit` too. The log is an audit trail of what the agent did, so a
one-line description before each command keeps it readable.

## Connection Pattern

### Single Command

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour off\n"; sleep 0.4; printf "set feedback off\n"; sleep 0.4; printf "claude %s\n" "DESCRIPTION"; sleep 0.4; printf "%s\n" "COMMAND"; sleep 1.5; printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

Replace `DESCRIPTION` with what you're doing and `COMMAND` with the actual
command.

### Multiple Commands

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour off\n"; sleep 0.4; printf "set feedback off\n"; sleep 0.4; \
printf "claude %s\n" "DESCRIPTION_1"; sleep 0.4; printf "%s\n" "COMMAND_1"; sleep 1.5; \
printf "claude %s\n" "DESCRIPTION_2"; sleep 0.4; printf "%s\n" "COMMAND_2"; sleep 1.5; \
printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

Add more `printf "claude ...\n"; sleep 0.4; printf "%s\n" "..."; sleep 1.5;`
blocks for additional commands. Since `colour` and `feedback` are saved
prefs, the two setup lines can be dropped once they're set on the
character. Keep the total well under the 60-second
login timeout. Sleep timings give each command time to process; increase
them if output is truncated.

## Common Recipes

### Update / Reload a File

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour off\n"; sleep 0.4; printf "set feedback off\n"; sleep 0.4; \
printf "claude updating /path/to/file.lpc\n"; sleep 0.4; printf "update %s\n" "/path/to/file.lpc"; sleep 1.5; \
printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

### Run a Command and Read Output

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour off\n"; sleep 0.4; printf "set feedback off\n"; sleep 0.4; \
printf "claude running COMMAND\n"; sleep 0.4; printf "%s\n" "COMMAND"; sleep 1.5; \
printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

### Update Then Test

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour off\n"; sleep 0.4; printf "set feedback off\n"; sleep 0.4; \
printf "claude updating /path/to/file.lpc\n"; sleep 0.4; printf "update %s\n" "/path/to/file.lpc"; sleep 1.5; \
printf "claude testing the change\n"; sleep 0.4; printf "%s\n" "COMMAND_THAT_USES_IT"; sleep 1.5; \
printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

### Verify Colour Rendering

```bash
bash -lc '(sleep 0.5; printf "%s\n" "$OX_TELNET_USERNAME"; sleep 0.6; printf "%s\n" "$OX_TELNET_PASSWORD"; sleep 1.5; printf "colour on\n"; sleep 0.4; \
printf "claude checking colour rendering\n"; sleep 0.4; printf "%s\n" "COMMAND"; sleep 1.5; \
printf "colour off\n"; sleep 0.4; printf "claude quitting\n"; sleep 0.3; printf "quit\n"; sleep 0.3) | telnet "$OX_TELNET_HOST" "$OX_TELNET_PORT"'
```

## Important Rules

1. **Log every action** with `claude <description>` before each command,
   including the `quit`.
2. **Always use `quit`** to log out — never `exit` or just disconnecting.
3. **Set environment variables first** — never embed credentials in the
   command string.
4. Log in with the **`character@account`** form to skip the character menu.
5. Use **port 1336** (plain telnet); 1337 is TLS and won't work with
   `telnet`.
6. Keep the whole session under the **60-second login timeout**.

## Reading Telnet Output

- System feedback comes from the `_ok` / `_error` / `_info` / `_warn`
  helpers, so success/failure shows up as those styled lines.
- With `colour on`, output contains true-colour ANSI escapes; `colour off`
  gives clean, greppable text.
- `update` reports success or the compile error; a failed reload prints the
  driver error, which is your signal the file didn't load.

## Error Handling

- **Connection refused**: the MUD isn't running on `localhost:1336`.
- **Stuck at "Login as which account?"**: account/character names are
  wrong, or you sent a bare account name and are now at the character menu
  — re-send using the `character@account` form.
- **"That password is incorrect."**: wrong password (3 failures
  disconnects you).
- **No output**: increase the sleep timings between commands.
- Always finish with `quit`, even if errors occurred.
