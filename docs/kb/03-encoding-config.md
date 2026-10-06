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
    For the heredoc terminator (`...。LONG`, the newline before `LONG` gone with a lone GBK
    lead byte) `scripts/lpc_fix_heredoc_terminator.py` does that for the whole corpus
    (2026-10-04: 269 glued and 107 indented terminators, KB 04 §6.10); the half character
    itself cannot be restored in UTF-8, the raw bytes show it as the lone byte before `\n`.
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
   matches; §4.5 for the tool that renames them and every wrong-case path.
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
- Source files carry the same stray `\` (UTF-8 after the conversion, so also after `許`->`许`, `縷`->`缕`, `髏`->`髅`,
  `擺`->`摆`, `蓋`->`盖`): `esI` had 438. The driver drops it and prints `Unknown escape sequence '\<byte>'` at the *end of
  the string or statement*, not at the backslash, so `scripts/lpc_warnings.py --fix` deletes every `\` before a
  multi-byte character in each file that reports one (an escaped `\\` pair is kept).
- **Before a closing quote in a source file the stray `\` is not a warning but a compile error**: `"force": "内功\",`,
  `set_name("豹\", ...)`, `if (temp == "功\") ...` escape the quote and the string runs into the next line.
  `cmds/std/enable.lpc` of yxsj, yxzsj, kxkj1 and dfgs2 did not load for that (the `enable` command), and neither did
  NPCs of dreamofseven, kxkj, kxkj1, kxkjii2 and the ES libs: 39 sites in 10 libs, found by a corpus scan 2026-10-04.
  `scripts/lpc_fix_big5_quote_backslash.py [--apply] SLUG...|--all` deletes the backslash when the character before it
  encodes to cp950 with 0x5C as second byte and the quote ends an expression. Two backslashes (`功\\"`, yxsj
  `bullets.lpc`) are not handled; read those by hand.
- **The GB18030 mirror image in save files: a stray half character in front of `\"`.** MudOS saves wrote a quote as `\"`; a
  text that held half of a GBK character right before a quote (`“` + `0xBA` + `\"` in the xyj/sjsh family's `nokiss` emote) was
  transcoded with the `0xBA 0x5C` pair as one character (`篭`), the backslash is gone, the bare quote ends the string and
  `restore_object()` stops: `Illegal mapping format while restoring emote`, so the emote daemon starts with no emotes at all.
  Repair: turn such a character (GB18030 second byte `0x5C`) back into `\` when a `"` follows it, accepting a line only if it then
  parses. 2026-10-06: 32 save files (`data/emoted.o` of 20 libs: mhxy, mhxyqd, shenmo, sjsh*, xiaoyuxiyou, xlqy*, xo*, xyj20032,
  yueyingqiyuan, ...; `xyj2000*/data/doc/1997/Dec/doc12.22.o`). Detection: parse every `#/`-headed save; a failing line with a CJK
  character directly before a `"`.

---

### 4.5 Paths the code names in another case than the archive stores them

**Symptom.** A room is "missing" although its file is there: an exit leads nowhere, `carry_object("/d/city/npc/tea/longjing")`
returns 0 (`Bad argument 1 to call_other` two lines later), `#include "bagua.h"` is `Cannot #include`, a whole directory
(`d/SHAOLIN/BAMBOO1.C`, `d/Mojie/`, `HELLZhen/`) is unreachable. The scan does not see it: a `.C` file is not an `.lpc` file, and a
reference that does not resolve is a run-time failure of the *caller*.
**Cause.** The archives come from DOS / Windows hosts that ignore case. Files are stored as `BAGUA0.lpc`, `longjing.C`, `ANSI.h`,
`d/SHAOLIN/`; the code says `__DIR__ "bagua0"`, `"tea/longjing"`, `#include "ansi.h"`, `"/d/shaolin/..."`, often both spellings in the same
lib. The extraction renamed `.c` -> `.lpc` but not `.C` (§4.2 item 7), and 15 of the 3274 uppercase-extension files were never transcoded.
**Fix.** `python3 scripts/lpc_case_paths.py [--convert] [--apply] [--list FILE] SLUG` (gitlink libs refused): resolves every path
literal of every code file (`"/d/x/y"`, `"d/x/y.c"`, `__DIR__ "y"`, `#include "x.h"` / `<x.h>`; comments, strings in heredocs and `#if 0` are
masked) as the driver would, treats a reference that resolves only when case (and `.C` / `.c` / `.LPC`) is ignored as a wrong-case
name, renames every such file and directory to lower case (`.C` -> `.lpc`, `.H` -> `.h`), staging the moves, and rewrites **every** reference
to a path that moved (the right ones in the old spelling too), changing only the components that were renamed. A target that exists, two
renames with one target, a reference that two real paths could mean and a non-UTF-8 `.C` file (`--convert` transcodes GB18030) are listed
and left. `--list` writes the objects to load-check (renamed, edited, naming a renamed path): `scripts/lpc_listcheck.sh` on that list, HEAD
against the tree.
`--dos` also renames what the references cannot show: in every directory that holds an upper-case-extension file or something the first phase renamed, the
remaining `.C` / `.H` / `.LPC` files, the code files with an all-upper-case stem and the all-upper-case directory names (the skills of the Journey-to-the-West libs are looked up
as `SKILL_D + name`: `daemon/skill/MAHAYANA.C` is invisible to a scan of literals). **Side effect to plan for:** an NPC that was unreachable behind a wrong-case path exists
for the first time and may raise in `create()` (a skill file or a `carry_object()` item that this archive never had); the room that holds it then stops loading (`sjshwzjqb`, `sjcs`).
`scripts/lpc_resilient_room.py SLUG` makes the room base's `make_inventory()` `catch` the `new(file)`, so the room loads without that NPC, as it did before.
**Detection.** Run the tool without `--apply`; `Cannot #include X` in a scan where a file of another case exists;
`git ls-files | grep -E '\.(C|H)$'`. After the rename run `scripts/lpc_warnings.py` again: files that never loaded show errors
of their own. Computed paths (`"/d/" + zone + "/NPC/"`) are invisible to the tool; it prints the old upper-case directory names that
still occur in string literals so they can be read. Commit with a pathspec: the moves are already staged (AGENTS.md section 13.3).

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

### `T array a, b` became `T * a, b`: only the first name stays an array (2026-10-05)

**Symptom:** a variable that should hold an array is declared as a plain type. Most of the time nothing shows, because the driver does
not enforce local types at run time. A global restored from a save file is different: nightmare4's finger daemon read the player's
`Religion` as a string, so `Religion[1]` was a character code and every finger said `Agnostic`; the scan reports
`Types in ?: do not match ( int vs string )`. **Cause:** in MudOS `array` belongs to the type (`string array a, b` makes two
arrays), while `*` belongs to one declarator. A conversion that rewrote `array` as `*` starred only the first name.
**Fix:** star every later name. **Detection:** compare against raw/ (`scripts/lpc_array_decl_scan.py [slug...]`, which needs raw/
extracted). Found in nightmare4 (4: `Religion`, `send_to`, `fun`, `ots`), sgzmudsgz (`nation_menu.lpc` x4) and swmud (1).

### A Latin-1 lib decoded as GB18030 (questmud, 2026-10-05)

**Symptom:** Finnish text turns into CJK (`ensimm鋓nen paikka on tyhj`), and an odd high byte swallows the ASCII byte after it,
often a space or a closing quote, so strings never end, save files fail `restore_object()` (`surname "牋牋`), and aliases lose
their keys. **Cause:** the onboarding transcoded a Latin-1 archive with the Chinese default. **Fix:**
`scripts/latin1_misdecode_repair.py SLUG [--apply]` aligns work lines with the raw ones and replaces a line by its true
Latin-1 decoding only when the two ASCII skeletons differ by nothing but bytes deleted next to a high byte (an edited line is kept).
Run it on save files *before* converting their mappings. **Detection:** a non-Chinese lib whose work tree has CJK characters
(`grep -rlP "[\x{4e00}-\x{9fff}]" libs/SLUG/work`); a raw file that is not valid GB18030. pd (2026-10-06) is Windows text:
`--encoding cp1252` (smart quotes `’`); its LPC textbook chapter is Mac Roman (`0xD5` = `’`, not `Õ`). Check what the repair
adds before committing: tally the new non-ASCII characters per file, and revert a file that really was GB2312 (full-width
spaces `A1A1` in ASCII art came out as `¡¡`). For lines the script keeps because they were edited, a CJK character whose
GB18030 second byte is ASCII maps back to `cp1252(first byte)` plus that byte (`抯` -> `’s`). cp437 block art in old letters stays.

### `\` + CR CR LF: a doubled DOS conversion ends macros and strings early (holymission, 2026-10-06)

**Symptom:** a multi-line `#define` stops at its first line (`syntax error, unexpected L_IF` in the header that uses it), and
a `"...\` string continuation keeps a CR and a hard line break mid-description. **Cause:** the archive went through CRLF
conversion twice (`\r\r\n`); the lexer joins `\` + `\r\n` but takes `\` + `\r` as an escape. **Fix:** drop the extra CRs
after an odd run of backslashes, outside `@`/`@@` text blocks (ASCII art there ends in `\` on purpose). **Detection:**
`grep -rlP '\\\r+\r\n'`; 170 files in holymission; the Chinese hits (help.h in five xyj/sjpl libs) sit inside `/* */`.

### LDMud save files: multi-value and width-0 mappings (questmud, 2026-10-05)

`([k:v1;v2;v3])` (wide), `(["a","b",])` (width 0, a key set) and `([:5])` (empty, width 5) do not parse in FluffOS, so a player
file, mail folder or daemon save holding one never restores. `scripts/ldmud_wide_save_convert.py [--apply] FILE.o...` rewrites
them as `([k:({v1,v2,v3})])`, `(["a":1,"b":1])` and `([])`, the layout of the ported code (`m[k][N]`, `m[k] = 1`); the code that
writes them needs the same change (`m[k, N]` -> `m[k][N]`, `m += ([ k ])` -> `m[k] = 1`, `m -= ([ k ])` -> `map_delete`).
Check with a probe that calls `restore_variable()` on every saved value.


### LDMud save files: `\n` in a string restores as a literal `n` (questmud, holymission, 2026-10-06)

**Symptom:** board posts, mail and player descriptions from old saves print `nn Sehän on…!!!n`: every newline is an `n`.
**Cause:** LDMud's `save_object()` writes a newline inside a string as the escape `\n` (a tab as `\t`); FluffOS writes a
raw CR byte instead, and its `restore_object()` turns any `\X` into a plain `X`. **Fix:**
`scripts/ldmud_save_newlines.py [--apply] PATH...` rewrites, inside quoted strings of files with LDMud's `#N:M` header,
`\n` to a CR byte and `\t` to a tab (`\"` and `\\` mean the same in both drivers). A `\r` cannot be kept: a raw CR restores
as a newline. **Detection:** `\n` escapes in `.o` files that start with `#N:M`; only questmud (41,888) and holymission
(72,364) have them. Many `.o` files in the Chinese libs are LPC sources with a `.o` name; ignore them.
LDMud saves can also share a value: `<1>=({})` defines it and a later `<1>` in the same file refers back; FluffOS stops with
`restore_object(): Illegal array format` (holymission's 40 player houses). `ldmud_wide_save_convert.py` expands each reference into a
copy (`grep -rlP '[,(\[:]<\d+>' --include='*.o'`; only holymission has them).

A related trap in the same saves: the 2026-10-05 Latin-1 line repair skips a line that was changed later, and a save line
whose mapping was converted counts as changed. Rebuild such lines from `raw/` by emulating the bad decode exactly (a
GB18030 pair, or an invalid pair dropped together with the byte after it); replace a work line only when it equals that
emulation, then run the same mapping conversion on the correct decoding.
