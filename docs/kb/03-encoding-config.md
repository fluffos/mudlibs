# KB 03 — Encoding, `.c`→`.lpc` fallout, config files (§4–§5)

## 4. Encoding and conversion

### 4.1 Encoding rules

- **Encoding conversion always runs first**, before any sed, rename, or
  edit. Editing GBK bytes with UTF-8 tools plants U+FFFD, which later
  turns into unrecoverable 锟斤拷. This applies to `config.fluffos` too.
- The default is `iconv -f GB18030 -t UTF-8`. Some files are already
  UTF-8; check with a round-trip decode first.
- **A pure-BIG5 archive decodes "cleanly" as GB18030 into mojibake**,
  often Bopomofo-range characters. No error is raised, and
  `convert_lib.sh` reports zero lossy files.
  - Detect: trial-decode 2–3 raw files as big5, gbk, gb18030, and cp950,
    and **read** the results.
  - Fix: re-run the whole conversion with BIG5. First check git for
    fixes already committed to `work/`, because regenerating wipes them
    (`dfgsiiv13b`).
- **Convert every text file, not just source.** Extensionless help text,
  `motd`, `adm/etc/*`, `doc/`, and plain-text `.o` saves are all GBK
  too.
  - `file(1)` misclassifies files (`data`, even "COM executable for DOS").
  - Uppercase `.C` files escape case-sensitive globs.
  - Run a whole-tree Python UTF-8 decode scan over `work/`. Filter real
    binaries out by inspecting content.
  - Typical misses: `help/rules`, `clone/game/{8,21}_hlp`
    (yh2003 siblings), `adm/etc/banned_name`, `doc/help/*`, and
    `adm/etc/nature/day_phase`.
  - **If a play session creates an unexpected new file in `adm/etc/`,
    check `raw/` for a same-path original.** A self-seeding fallback may
    have quietly replaced unconverted content with a weaker default
    (`syxjl`'s 137-entry `banned_name` became a 6-entry default).
- **`iconv -c` can eat a real byte next to an invalid one**: a newline,
  a quote, or a heredoc close tag.
  - Symptoms: "End of file in text block", a missing quote, or a `//`
    comment swallowing the next line's code. The swallowed code can
    silently delete a function or a `set_name()`, with no compile error.
  - Diff the bytes against `raw/` and re-insert the dropped character.
  - A file flagged LOSSY in the conversion log is suspect even if it
    compiles. Combat and movement exercise many lazily compiled files.
- **One file can mix encodings.** BIG5 lines inside a GBK file decode
  validly into wrong text. Only reading user-facing strings catches it.
  Re-decode the affected lines as BIG5.
- **Strip DOS Ctrl-Z (`0x1a`) bytes.**
- **Grep `raw/` with `grep -a`**. GNU grep treats GBK as binary.
- **GBK and CRLF in `.o` saves need a quote-aware fix.**
  - `save_object()` stores an embedded newline as a bare `\r`.
    `restore_object()` splits strictly on `\n`.
  - Collapse `\r\n`→`\r` **only inside string literals**. Outside a
    string, `\r\n` is a real statement boundary.
  - A blind collapse merges variables and silently restores empty
    mappings.
  - Symptoms: `Invalid utf8 string`, `Illegal file format`, or
    `Illegal mapping format` (`fy2`, `xyj451`).

### 4.2 The `.c` → `.lpc` rename and its long tail

An explicit extension is resolved exactly. An extensionless path tries
`.lpc` and then `.c`. Fallout to check:
1. Quoted refs inside `.h` macros (`#define F_DBASE "/feature/dbase.c"`).
   Grep `.lpc` and `.h` files together.
2. Bare `/path.c` lines in plain-text data files: `adm/etc/preload`,
   room-pool tables, scenery tables. Preload failures are silent. Verify
   every row in a data file with a script, not just a sample.
3. Runtime `sscanf(f+"$", "%s.c$", f)` filters (§8.3b).
4. Fixed-width slices (`[0..<3]`, `len-2..len-1` compared against
   `".lpc"`). See §7.80 and §7.118.
5. An extensionless live file plus a same-named `.c` backup: after the
   rename the backup can win. Diff every pair.
6. A *directory* named `x.c`. Rename it to something that doesn't look
   like a source file.
7. Uppercase `.C` files are missed by both the rename and the transcode.
   Run `find -name '*.C'`, then check macros whose case no longer
   matches.
8. Orphaned non-LPC `.c` files (ASCII maps): rename them to `.txt`.

A lib may keep non-critical `.c` files as long as the master and login
path are `.lpc`.

### 4.3 `static` → `nosave`, and its collisions

This driver has no `static` keyword at all (variables or functions).
Replace `\bstatic\b` on a *variable* with `nosave`. On a *function* it meant
"not callable from other objects": write `protected`, or just `private` if it
is already private. A blanket `static`→`nosave` also hits functions, and
`nosave` on a function compiles with a warning ("Illegal to declare nosave
function", hundreds per lib); `scripts/lpc_warnings.py --fix` repairs it (KB 04
§6.10). After that:
- **String literals.** `log_file("static/CRASHES")` becomes
  `"nosave/..."`, which orphans the real `log/static/` history and
  crashes on the missing `log/nosave/` dir.
  - Grep `"nosave/` and confirm each hit against `raw/`.
  - Revert real hits to `"static/..."`. Don't just create
    `log/nosave/`.
  - Also harden `log_file()` with `assure_file()` (§7.11).
  - Confirmed across 3+ lineages (`yxsj`/`yxzsj`, `hxxtjqb`,
    `jyqxc2013fwq`), so a corpus sweep is warranted.
- **Compat shims.** `#define nosave static` / `#define protected static`
  become aliases after the sed. Neutralize them; both keywords are real
  on this driver.

### 4.4 BIG5 characters whose second byte is `0x5C` (`\`)

- `功` (A5 5C) and `許` (B3 5C) were byte-escaped (`5C 5C`) by the old
  driver's `save_object()`. A naive iconv leaves a stray `\` after the
  character.
- Mid-string this is cosmetic (`Unknown escape sequence`). Before a
  closing quote it escapes the quote and breaks the `.o` file:
  `Illegal mapping format`. The variable restores as `0`, and an
  indexing crash follows (`chinesed` dict → `learn`/`skills` broken on
  `yxsj`/`yxzsj`).
- Fix: re-derive the `.o` from `raw/` with an escape-aware decoder.
  Tokenize each string, un-double `\\`, decode BIG5, then re-escape.
- Detect: grep `功\`/`許\`, and grep boot output for `Illegal mapping
  format`. This applies to any genuinely BIG5-sourced lib.

---

## 5. Config files

### 5.1 Format

The `key : value` format is unchanged (canonical example:
`~/src/fluffos/testsuite/etc/config.test`).
- Convert the encoding first.
- Point `mudlib directory` at `libs/<slug>/work`.
- Assign a unique port.
- Prune keys the driver rejects.
- Never trust the shipped absolute paths or `name:`; they are often
  copy-pasted from other muds.
- The driver prints a message for every key it does not take, and every
  one is a fix (2026-10-04 sweep: 371 messages in 277 configs, none left).
  `python3 scripts/lint_configs.py [SLUG]` prints them (it parses a copy of each config whose `mudlib
  directory` is an empty scratch dir; running `lpcc config.fluffos` inside `libs/S` boots the lib in place and
  rewrites tracked save files):
  `*Warning: obsolete line in config file, please delete:` (`address server
  ip/port`, `binary directory`, `reserved size`, `swap file`, `wombles`,
  `warn tab`: delete the line and the comment above it);
  `living hash table size: invalid new value` (must be 4, 16, 64, 256, 1024
  or 4096: the old generator wrote `100`; `docs/driver/config.md` has the
  minimums of `hash table size` 7001 and `object table size` 1024); and
  `external_port_1 already defined ... by the line 'port number : N'` (the
  `port number` line is the telnet port, so a second `external_port_1 :
  telnet N` is ignored: delete it). Every invalid value was already being
  reset to the default, so the fix keeps the effective setting.
  `scripts/lib_write_config.py` writes new configs without them.

### 5.2 `log directory` resolves against the launch CWD

Always launch with `cd libs/<slug> && …/driver config.fluffos`. See also
§10.9: debug.log can be silently dead under this convention.

### 5.3 Ports hardcoded in mudlib source

A `MUD_PORT`/`PORTNO` constant checked in `master::connect()` rejects
every connection when it doesn't match: the log looks clean, but the
server is dead (`huoying`, `dfgsiiv13b`). Read what the constant gates.
Some are cosmetic only.
