# AGENTS.md — working notes for converting these mudlibs to modern FluffOS

Read this before touching a new archive. Update it whenever you learn
something that will save time on the *next* lib — this is the accumulated
knowledge base for a ~100-archive batch job, not a diary of one run.

## The pipeline, per lib

-1. **`lpcc` has a `--batch` mode — use it, not one process per file.**
   `lpcc --batch config_file [file1 file2 ...]` (or pipe newline-separated
   object paths on stdin, extension-less, e.g. via `find work -name
   '*.lpc' | sed ...`) boots the VM ONCE and compiles every listed file in
   that same process, instead of a fresh boot per file. This is a driver
   patch made in this project (`src/main_lpcc.cc`, plus two related fixes
   below) — ~15-70x faster than the original one-process-per-file
   approach (a 1909-file lib: ~15s vs several minutes), and `scripts/
   lpcc_check.sh` already uses it. If you ever reach for raw `lpcc` by
   hand instead of the script, use `--batch`, not a shell loop.
   - **Gotcha if you ever touch this code again**: `set_eval(max_eval_cost)`
     MUST be called before each file's compile inside the batch loop.
     `set_eval()` arms a real OS timer (`vm/internal/eval_limit.cc`), not a
     simple counter — without rearming it per file, elapsed wall-clock time
     across the WHOLE batch run accumulates against one budget, and every
     file compiled after that budget is exhausted spuriously fails with
     "Too long evaluation. Execution aborted." regardless of its own cost
     (this exact regression appeared once already: 22 real failures on the
     pilot lib inflated to 447 before this fix).
   - Batch mode reuses ONE VM/object-table for every file, matching how a
     real boot compiles many objects in the same process (no state reset
     between them) — this is arguably a MORE realistic test than the old
     one-process-per-file approach, not just a faster one.

0. **Two driver builds exist** — use the right one:
   - `~/src/fluffos/build/src/driver` — RelWithDebInfo, pre-existing.
   - `~/src/fluffos/build-debug/src/driver` (+ `lpcc`, `lpcshell`) — Debug
     build (`-DCMAKE_BUILD_TYPE=Debug`, same package set as `build/`,
     configured with `-G "Unix Makefiles"` since `ninja` isn't installed on
     this host). **Use `build-debug` for all mudlib bring-up work** — better
     assertions/diagnostics for exactly the kind of crash in §4 below.
     Rebuild with `cd ~/src/fluffos/build-debug && make -j8 driver lpcc lpcshell`
     if the fluffos source has moved on.
1. **Extract** `archives/<name>` → `libs/<slug>/raw/` with `scripts/extract.sh`
   (handles zip/rar/7z/tar.gz, see "Archive tooling" below).
2. **Identify the mudlib root.** Archives are NOT consistent: some have the
   mudlib files directly at top level, some nest one level (`simple/`,
   `mudlib/`, the game's Chinese name, etc.), some bundle a prebuilt Windows
   driver/binaries alongside the LPC source, some bundle multiple things
   (client + server, source + compiled binary release). Find the real root
   by locating `master file`'s target (from a `config`/`config.cfg`/`*.conf`
   file — grep for `master file` or `mudlib directory`) or, absent a config
   file, by finding `secure/master.c` / `adm/obj/master.c` / similar.
3. **Copy to `work/`**, then in `work/`:
   - Transcode every text source file GB18030 → UTF-8 (see "Encoding").
   - Rename `.c` → `.lpc` for LPC source files ONLY (not for driver/tool C
     sources some archives bundle — see "What counts as LPC source").
   - Fix up literal `".c"` extension references that the rename breaks (see
     "The .c → .lpc rename is not just a `mv`").
4. **Write `libs/<slug>/config.fluffos`** adapted from the lib's original
   config file (see "Config file format").
5. **Verify compilation with `lpcc` before booting the full driver.**
   `~/src/fluffos/build-debug/src/lpcc <config> <object-path>` boots the VM
   (loads master + simul_efun, same as a real boot) then compiles ONE
   object and dumps its bytecode. Caveat: this means `lpcc` on ANY file is
   only useful once master/simul_efun themselves already compile — if
   they're still broken, fix that chain first (that IS effectively a boot
   attempt, just of the two entry files) using the real driver directly,
   THEN switch to `lpcc` to sweep every other file in the lib without
   paying for a full driver startup+shutdown each time.
   `scripts/lpcc_check.sh <config> <work-dir>` automates the sweep: finds
   every `.lpc`/`.c` under `work/`, runs `lpcc` on each (fresh VM boot per
   file — ~0.1-0.5s each, not fast, but accurate), reports PASS/FAIL per
   file and logs full compiler output for failures to `lpcc_fail.log`. Run
   this after the boot-chain (master/simul_efun) compiles clean, to catch
   everything else (rooms, NPCs, items, admin commands) that never gets
   exercised just by booting — a plain boot only compiles what's `#include`d,
   inherited, or explicitly preloaded; most of a mudlib's object tree is
   untouched by that and can still be full of `.c`-rename fallout or
   `static`-on-function errors nobody's seen yet.
   NOTE: a bare-bones synthetic master (`epilogue()` returning 0, nothing
   else) is NOT a valid `lpcc` test harness — `find_object()` silently
   failed to produce a compiled program for even a trivial one-line object
   against a minimal master in testing here (exit 255, no diagnostic
   printed anywhere, not even to the debug log). Always test against the
   real lib's own master, never a stand-in.
6. **Boot the full driver and connect with a real client** — `lpcc`
   compiling everything clean is necessary but not sufficient; things like
   preload-time daemon init, save/restore of seed data, and the login flow
   only run on a real boot. `cd libs/<slug> && ~/src/fluffos/build-debug/src/driver config.fluffos`
   (must `cd` first — see §5 in the catalog below on `log directory`), then
   from another shell: `python3 scripts/mudclient.py 127.0.0.1 <port>
   --timeout N --send "" --send "look" --send "quit"` (adjust `--send` for
   the lib's actual login sequence — character name, then usually a
   confirmation prompt for new characters). Read the transcript for mangled
   text (missed an encoding conversion somewhere — see §1) and driver-side
   errors in the lib's `log/debug.log`.
   - **Launching the driver reliably**: a plain `nohup ... & disown` has
     been observed to die from an unexplained external `SIGTERM` between
     tool calls on this host, even mid-interactive-test with the process
     otherwise healthy (found on `jianghufengyun`, archive #59). Prefer
     `setsid nohup ~/src/fluffos/build-debug/src/driver config.fluffos &
     disown` (own session, immune to whatever signals the parent shell's
     process group) if you hit this; the tool-provided `run_in_background`
     option on a Bash call is an equally reliable alternative.
7. **Record findings** in `libs/<slug>/NOTES.md` and update the status row
   in `TODO.md`. Promote anything reusable into the catalog below.

**Definition of "done" for a lib** (until told otherwise): driver boots with
no fatal compile errors, master/simul_efun/login objects load, and you can
telnet in and reach a prompt (character creation or login). Deeper gameplay
bugs (individual skill/room scripts erroring at runtime) are logged in
NOTES.md as known issues, not necessarily fixed — there isn't time to fully
QA 100 codebases. Prioritize breadth (every lib boots) over depth (every
lib fully playable) unless a specific lib is called out for deeper work.

---

## Archive tooling

- `unzip`, `unrar`, `7z`/`7za`/`p7zip`, `tar` are all available.
- `unrar x -y <archive>` handles Chinese filenames fine in this environment
  (UTF-8 locale) — no special `-sc` flag needed, verified on 山海战神.rar.
- Watch for **self-extracting .exe** (RAR SFX) — `金庸文字版.exe` is one;
  `7z x` or `unrar x` can usually still open them directly.
- Watch for archives that are just a renamed `.gz`/`.tar` of something
  unrelated (e.g. `西行战记.gz` unpacks to `xxzj.tar`).
- **Found on archive #26 (`xlqy_new2007.rar`)**: `extract.sh`'s `.rar`/
  `.exe`-SFX branches `cd "$DEST"` before invoking `unrar x ... "$ARCHIVE"`
  — since the normal calling convention passes a RELATIVE path
  (`archives/foo.rar`), after the `cd` that path no longer resolves,
  `unrar` prints `Cannot open ... No such file or directory` and (because
  the script has no `-e`) exits 0 anyway, so the script happily reports
  "extracted" with an EMPTY `raw/`. **Fixed**: `ARCHIVE` is now resolved
  to an absolute path up front, and the script now fails loudly (checks
  `raw/` actually has files, `exit 1` if not) instead of silently
  succeeding with nothing extracted — catches this class of bug for ANY
  archive type, not just `.rar`, going forward.
- **Found on archive #44 (`侠客行III .rar`)**: `file` identifies it as a
  plain POSIX tar (`unrar` correctly refuses it: "not RAR archive"), and
  its members are stored with **relative `../xkx3/...` paths** (a tar
  created from one directory up from the intended root). GNU `tar -xf`
  unconditionally refuses to extract ANY member whose name contains
  `..` ("Member name contains '..'"), regardless of destination or
  `--transform` (the safety check runs before transforms are applied),
  so plain `tar -xf` fails entirely with zero files extracted. Fix:
  extract with Python's `tarfile` module instead (no such restriction),
  stripping each member's leading `../` before calling `extract()`:
  ```python
  import tarfile
  tf = tarfile.open(archive_path)
  for m in tf.getmembers():
      name = m.name
      while name.startswith('../'):
          name = name[3:]
      m.name = name
      tf.extract(m, path=dest_dir)
  ```
  Symptom to watch for: `extract.sh`'s `.rar` branch reports `unrar:
  ... is not RAR archive` — run `file <archive>` next; if it says tar,
  try plain `tar -xf` first (fast path for normal tars), and if THAT
  fails with `Member name contains '..'`, use the Python `tarfile`
  workaround above.

## Encoding — `file`'s text/binary guess is not reliable enough to gate on

Found processing lib #4 (bxsj): `convert_lib.sh` originally gated encoding
conversion on `file -b`'s classification (`*text*|*script*` = convert,
anything else = skip as binary). A handful of genuine GBK **source** files
(CRCRLF line endings — `\r\r\n`, not the usual `\r\n` — apparently confuses
`file`'s heuristic) get misclassified as `data` and silently skipped,
leaving them permanently un-converted (raw GBK bytes shipped straight into
`work/`). This surfaces later as `error: Invalid UTF8 codepoint in string
literal` at BOOT/compile time, not during conversion — easy to miss since
the conversion step reports no failure at all for these files.

**Fix applied**: `convert_lib.sh` now treats known source/text extensions
(`.c .lpc .h .txt .log .cfg .conf .map`) as text UNCONDITIONALLY,
regardless of what `file` reports, and only falls back to the `file`-based
guess for extensionless files and other extensions where there's no prior
(`.o` deliberately excluded from the forced list — genuine compiled/
bytecode-dump `.o` files exist alongside plain-text save-data `.o` files in
this ecosystem, so that one extension still needs the real per-file guess).

**After running `convert_lib.sh` on a new lib, double-check for stragglers**
it might have already missed (from before this fix, or from some other
`file`-classifier edge case not yet seen):
```
find work \( -name "*.lpc" -o -name "*.h" \) -print0 \
  | while IFS= read -r -d '' f; do
      file -b "$f" | grep -qE "text|script|empty" || echo "$f"
    done
```
Any hit is raw un-converted GBK masquerading as a `.lpc`/`.h` file — just
`iconv -f GB18030 -t UTF-8 [-c]` it directly, same as any other file.

**`iconv -c`'s invalid-byte recovery can eat an adjacent REAL byte too, not
just the invalid one** — found on `xo_final`/`shujian2008`/`xianlvqiyuan`
(a corrupted string literal's closing quote silently disappearing) and, in
a new specific manifestation on `tianxia` (archive #50): a `set("long",
@LONG ... LONG)` text block's closing `LONG` tag ending up merged onto the
end of the preceding text line, breaking the syntax rule that the closing
tag must start its own line (`error: End of file in text block`). Root
cause confirmed by diffing against the raw pre-conversion bytes: the
original file had an invalid GBK lead byte immediately followed by a
literal newline (`0x0A` is not a legal GBK trail byte) right before the
closing tag — `iconv -c`'s skip-forward heuristic on an invalid multi-byte
start advances by the presumed character width, which swallowed the real
newline along with the bad byte. **Signal to watch for**: any `error: End
of file in text block` (or a missing-closing-quote-shaped error) on a file
ALSO flagged `LOSSY conversion` in `convert_lib.sh`'s log is a strong hint
to check for exactly this — a merged closing-tag/quote line — rather than
assume a from-scratch content bug. Fix by re-inserting the dropped
newline/quote at the exact point indicated by the raw byte layout (not a
guess) — Python line-index read/write if hidden PUA characters are also
present (see the `xo_final` mohe-zhi.lpc precedent below), otherwise a
straightforward line-numbered edit.

## Encoding

Mudlib source is GBK/GB2312 (simplified) in the vast majority of archives.
**Verified working**: `iconv -f GB18030 -t UTF-8 in.c > out.c` (GB18030 is a
superset of GBK/GB2312, safe default). Exit code 0 and clean output on the
pilot file tested (`daemon/skill/dodge.c` in 山海战神).

- If GB18030 conversion fails (invalid byte sequence) on a file, the archive
  may be Traditional Chinese (Big5) — try `-f BIG5` next. `消失的亞特蘭提斯`
  (traditional characters in the name itself) is the most likely candidate.
- Some files may already be UTF-8 (mixed-encoding archives happen when a lib
  was edited over the years by different tools) — detect before blindly
  converting: `iconv -f UTF-8 -t UTF-8 f >/dev/null 2>&1 && already_utf8`.
- Binary files (compiled `.o`, Windows `.exe`, save-game data files under
  `log/`, `save/`, player save files) must NOT be run through iconv — only
  convert LPC source / doc / help text. Restrict conversion to text files
  (`file` output containing "text", or by extension allowlist).
- CRLF line endings are common (MS-DOS-era tooling) — harmless to FluffOS,
  no need to strip `\r` unless it interferes with a diff/patch step.

## What counts as "LPC source" (for the .c → .lpc rename)

Only rename `.c` files that are actually LPC, i.e. everything under the
mudlib root that the driver will compile. Do NOT rename:
- Any bundled C/C++ driver source (some archives ship a whole MudOS/FluffOS
  driver tree alongside the mudlib — that's a separate concern, we're using
  our own driver build, not theirs; leave their driver tree alone or drop it).
- `eval.c` at the top of this repo is NOT part of any lib — investigate
  separately if relevant, don't treat it as an archive.

## The `.c` → `.lpc` rename is not just a `mv`

FluffOS resolves an **explicit** extension exactly (`load_object("/foo.c")`
only ever looks for `foo.c`, never `foo.lpc`) — see
`~/src/fluffos/AGENTS.md` §"Source File Extensions". Old mudlibs hardcode
`.c` extensively:
- `inherit "/std/room.c";` style inherits with explicit `.c`
- `load_object(path + ".c")` / string-built paths
- suffix checks: `strsrch(file, ".c") == strlen(file) - 2` or similar, used
  by in-game editors, autoload systems, `ls`-alikes
- filenames stored in save-data / config referencing `.c`

Strategy: after renaming files, `grep -rn '\.c"' work/` (and `\.c\x27`, and
bare `.c` in string concatenation) across the whole tree and fix references
file-by-file. This is the single biggest time sink in the conversion step —
budget for it. A blanket `sed -i 's/\.c"/\.lpc"/g'` is tempting but WILL
corrupt unrelated strings (e.g. version strings, `.cfg`, `.com`, French
possessive-looking substrings) — inspect matches before batch-replacing, or
scope the sed to patterns anchored to known file-reference idioms
(`inherit "..."`, `load_object(...)`, `/std/...\.c"`, etc).

Since FluffOS **also** still resolves `.c` explicitly and falls back to
`.lpc` when no extension is given at all, an alternative lower-effort
strategy for a lib with intractably many `.c`-literal references: rename
the files to `.lpc` but ALSO leave a same-named `.c` `#include`-forwarding
stub is NOT supported (driver resolves by exact filename on disk, not
include-style) — so that shortcut doesn't work. If a lib's `.c` references
are too extensive to fix in reasonable time, it is acceptable to note in
NOTES.md and leave that lib's non-critical/rarely-loaded files as `.c`
(the driver runs mixed-extension trees fine), so long as the master/login
path is fully `.lpc` and boots.

**Watch for uppercase `.C`** (found on `shenmo`, archive #73, a large
long-lived multi-author lib): `convert_lib.sh`'s glob for the rename pass
only matches lowercase `.c`, so any files saved with an uppercase `.C`
extension (363 of them here — likely from a Windows-originated editor or
a case-insensitive-filesystem author's workflow) are silently skipped by
the automated rename and need a separate manual pass (`find work/ -name
'*.C'`, case-sensitive, then rename each). Cheap to check on every lib
going forward, not just ones that look unusually old/large.

## Config file format

Old MudOS/FluffOS config files (`config.cfg` / `config.dwar` / etc, various
names per lib) use the same `key : value` line format FluffOS still reads
(see `~/src/fluffos/testsuite/etc/config.test` for the canonical modern
example, and `~/src/fluffos/docs/driver/config.md`). Verified: `simple`
pilot lib's `config.cfg` (labeled "MudOS 0.9.20") uses directives
(`mudlib directory`, `master file`, `include directories`, `log directory`,
`simulated efun file`) that map directly.

Per-lib adaptation checklist when writing `libs/<slug>/config.fluffos`:
- `mudlib directory` → point at `libs/<slug>/work` (absolute or relative
  to the config file's own location — confirm which FluffOS expects; the
  testsuite config uses a path relative to itself, `./`-style, with a
  comment "all paths are relative to the mudlib directory except mudlib
  directory itself and binary directory").
- `port number` → assign a unique port per lib (increment from a base, e.g.
  40001, 40002, ... — track assignments in TODO.md to avoid collisions).
- Directories the driver needs writable that may not exist yet (`/log`,
  `/save`, etc relative to mudlib root) — create them, `git`-style old
  archives sometimes ship them empty and RAR/zip drops empty dirs.
- FluffOS may require config keys the old file lacks (compare against
  `testsuite/etc/config.test` for anything the old file is missing that
  isn't optional) or reject keys it no longer recognizes — check driver
  boot stderr for "unknown config key" style warnings and prune/add as
  needed. Log any such diffs here once you've done 2-3 libs, so later libs
  don't rediscover the same missing keys one at a time.

---

## Common driver-compatibility issues (catalog — fill in as discovered)

Validated end-to-end on the pilot lib (`libs/shanhaizhanshen`, from
山海战神.rar — a `simple`/ES-II-derived MudOS 0.9.20 lib) which now boots
clean on the debug driver and is playable over telnet with correct Chinese
text. These fixes are expected to recur across most/all of the other ~99
archives since they share this same MudOS-era lineage.

### 1. Encoding: convert EVERY text file, not just source

The original mistake: only converting `.c`/`.h` files. **Any file under the
mudlib root can be GBK-encoded Chinese text regardless of extension** —
extensionless files (`adm/etc/welcome`, `motd`, help topics), and `.o` save
files (LPC's plain-text `save_object()` format, NOT a compiled binary
despite the extension) all need the same GB18030→UTF-8 pass. Detect with
`file`: convert anything reported as "text" (or "ASCII text"/"ISO-8859
text"), skip anything reported as ELF/PE/data/compressed (`mudos.exe`, real
`.o` object files from a bundled prebuilt driver, images).
- A handful of save-data `.o` files may have genuinely undecodable bytes
  (seen: `emoted.o`, position 25324) — fall back to `iconv -c` (drops
  invalid bytes) rather than leaving the file untouched; it's seed/example
  data, not source, so minor loss there is acceptable. Note it in NOTES.md.
- `iconv -f GB18030 -t UTF-8` from a bash loop is fast (~5ms/file) — if a
  batch conversion run seems to hang for a long time with zero progress
  output, don't assume a bad file; kill it and retry as a **backgrounded
  script with progress logging** (`nohup ... & disown`, poll the log) rather
  than a long blocking foreground call — a foreground `while read` loop
  piped from `find ... -print0` mysteriously hung once for 2 minutes with
  zero throughput in this environment before a rewritten version (find →
  tmp file → `while read` from the file, `timeout 2` per iconv call)
  processed the same 898 files in under 10 seconds. Cause unconfirmed; the
  backgrounded-with-progress pattern sidesteps it either way and gives real
  visibility into a 1000s-of-files conversion pass.

### 2. `.c` → `.lpc` rename breaks literal `".c"` references — in `.h` too

Covered in principle further down this file, but the concrete trap: grep
for `\.c"` scoped to `--include="*.lpc"` **misses `#define` macros in `.h`
files** (e.g. `#define F_DBASE "/feature/dbase.c"` in `globals.h`), which
then surface as runtime failures (`Inherited file '/feature/dbase' does not
exist!`) rather than compile errors, because the macro only gets expanded
where used. **Always scope this grep/sed to `--include="*.lpc" --include="*.h"`
together**, and re-check after: an `Inherited file '...' does not exist!` or
`Fail to load object` error naming a path with no visible `.c`/`.lpc` in the
*failing* file is a strong signal to grep the include chain's headers.

**A second, unrelated rename-fallout variant** (found on `nitan_ceshi`,
archive #60): code that lists a directory and strips a filename's
extension via a **hardcoded fixed-width slice** rather than an actual
extension-aware string op, e.g. `map_array(get_dir(DIR+"*.lpc"), (:
$1[0..<3] :))`. `<3` (drop the last 3 chars) was correct for stripping the
original 2-character `.c` extension (`"foo.c"[0..<3]` → the last 3 chars
dropped leaves `"foo"`... check the sibling math for whatever the
original file actually used), but is now wrong for the 4-character `.lpc`
extension, silently leaving a trailing letter (e.g. `"foo.lpc"[0..<3]` →
`"foo.l"`, not `"foo"`) that then fails a subsequent `load_object()`/
`call_other()` with a filename that looks almost-but-not-quite right.
Grep for `\[0\.\.<[0-9]\]` (or similar fixed small slice widths) anywhere
near a `get_dir()`/directory-listing call as part of the standard convert
pass, and widen the cutoff by the same +2 characters the extension grew
by (`.c`→`.lpc`).

### 3. `static` is illegal on FUNCTIONS in this driver — use `nosave`

Old MudOS/FluffOS mudlibs freely write `static <type> function_name(...)`
(meaning roughly "not saved, protected" — same modifier as a `static`
*variable*). This driver's grammar still accepts `static` as a
`L_TYPE_MODIFIER` (`{"static", L_TYPE_MODIFIER, DECL_NOSAVE | DECL_PROTECTED}`
in `lexer_utils.cc`) for **variables**, but a **function** declared
`static <type> name(...)` is a **hard parse error**:
`syntax error, unexpected L_BASIC_TYPE, expecting L_ASSIGN or ';' or '(' or ','`
pointing at the return-type token. Swapping the modifier to `nosave` fixes
it — `nosave <type> name(...)` parses fine, and only emits a soft warning
(`Illegal to declare nosave function`, non-fatal, function is still defined
normally). **Fix: blanket word-boundary replace `\bstatic\b` → `nosave`**
across every `.lpc` AND `.h` file in the lib (`static` on a variable becomes
`nosave` too, which is the intended/legal spelling for that case anyway —
no behavior change there). Verified safe via manual spot-check (89 hits in
the pilot lib, zero false positives — no lib in this family seems to use
`static`/`nosave` as an identifier or inside a string/comment, but spot-check
a sample of matches on each new lib before trusting the blanket sed, the
same way you would for the `.c"` rename fix).

**Counterexample found** (`moniHuafu`, archive #57): the word-boundary
match still fires inside a **string literal** when the string happens to
contain the bare word `static` as a path segment, e.g.
`log_file("static/CRASHES", ...)` — a lib-specific naming convention for a
log subdirectory, unrelated to the `static`/`nosave` keyword entirely. The
blanket sed rewrote 10 such string literals to `"nosave/CRASHES"` etc.,
silently orphaning the archive's real pre-existing seed data that lived
on disk at `.../static/`. Always grep for `"static` (opening quote
immediately followed by `static`) as a distinct check from the keyword
sed, and revert any string-literal hits rather than rely on the
"spot-check a sample" step above catching a rare path-name collision.

### 4. Master's lazy security-daemon load recurses to a stack overflow

Symptom: driver hangs/crashes with a flood of
`Object cannot be loaded during compilation.` and `Too deep recursion.`
tracebacks rooted at `master.lpc`'s `valid_read`/`valid_write`, eventually a
real SIGSEGV-class crash (backward-cpp stack trace dump).

Root cause: this MudOS-era idiom in `master.lpc`:
```
int valid_read( string file, mixed user, string func ) {
    if( !find_object( SECURITY_D ) )
        load_object( SECURITY_D );
    return (int)SECURITY_D->valid_read(file, user, func);
}
```
worked under the original driver but this FluffOS build forbids
`load_object()` while ANY object is mid-compile (including on the very
first file access checks that happen while master/a preload target is
itself still compiling) — the resulting error is thrown from inside a
master apply, so the driver's own error-reporting path calls back into
`valid_read`/`valid_write` (to check permissions for writing the error/log),
which retries the same disallowed `load_object()`, which throws again... an
unbounded loop until the C++ call stack overflows.

**Fix** (mudlib-side, in `master.lpc`): guard both `valid_read` and
`valid_write` with a re-entrancy flag and wrap the load in `catch()` so a
disallowed/failed load degrades to "allow" (`return 1`) instead of
recursing:
```lpc
private nosave int loading_security_d;

int valid_write( string file, mixed user, string func ) {
    if( !find_object( SECURITY_D ) ) {
        if( loading_security_d ) return 1;
        loading_security_d = 1;
        catch( load_object( SECURITY_D ) );
        loading_security_d = 0;
        if( !find_object( SECURITY_D ) ) return 1;
    }
    return (int)SECURITY_D->valid_write(file, user, func);
}
// same shape for valid_read
```
Check every lib's `master.lpc` for this pattern (`valid_read`/`valid_write`/
similar bootstrap-sensitive applies doing a lazy `load_object` of a security/
permission daemon) — grep `load_object` inside `master.lpc` early in the
per-lib pass, before even attempting a boot, and pre-apply this guard.

### 5. Convert `config.fluffos`'s encoding FIRST, before any other edit

`libs/<slug>/config.fluffos` starts life as a `cp` of the lib's original
(GBK-encoded) config file, and needs several mechanical edits (`port
number`, `mudlib directory`, dropping obsolete keys — see §6). **Do the
`iconv -f GB18030 -t UTF-8` pass on it BEFORE any `sed`/text-editor edit,
never after.** Editing a still-GBK file with tools that assume/round-trip
UTF-8 can silently replace invalid-as-UTF-8 byte sequences with U+FFFD; a
*later* GBK→UTF-8 pass over those already-mangled bytes then decodes the
UTF-8 encoding of U+FFFD (`EF BF BD`) as if it were GBK, producing the
distinctive "锟斤拷" mojibake — which looks like a normal encoding failure
but is actually unrecoverable double-corruption (the original bytes are
gone). This bit `default fail message`/`default error message` in the
pilot lib's config; fixed by re-copying the config fresh from `raw/` and
converting it before touching anything else. This isn't config-file-
specific — it's a general rule for every file this pipeline touches:
**encoding conversion is always step 1, before any rename/sed/reference
fix**, which is exactly the order `convert_lib.sh` already enforces for the
`work/` tree; just remember `config.fluffos` is a second, separate file
that needs the same discipline since it's created and edited by hand
outside that script.

### 6. `log directory` resolves relative to the driver's CWD, not the mudlib

Confirmed from `src/base/internal/rc.cc`'s own flag doc string: `"log
directory"` is "resolved relative to the driver's working directory
(leading slashes are stripped); not a mudlib virtual path" — unlike almost
every other config path, which IS relative to `mudlib directory`. **The
log directory will silently fail to open (non-fatal warning, but you get no
debug.log and, worse, some errors cascade differently without it) unless
you `mkdir` it at the driver's actual launch CWD and always launch from
there.** Convention adopted: `libs/<slug>/log/` (sibling of
`config.fluffos`, NOT inside `work/`), and the driver is always launched
via `cd libs/<slug> && .../driver config.fluffos` — never invoked with a
config path from elsewhere. `scripts/boot.sh` (once written) should enforce
this via `cd "$(dirname "$CONFIG")"` internally so it's never launched
wrong by accident.

### 6b. `lpcc_check.sh`'s per-file sweep has real, expected false-positive categories

Running every file through `lpcc` in isolation (§ pipeline step 5) is
still worth doing — it found several genuine pre-existing typos in both
pilot libs (see §9-§12 below) — but a large fraction of what it flags is
**not a bug**, just an artifact of compiling a file completely divorced
from its normal runtime context. Recognize these patterns before "fixing"
them:

- **`#include`-only fragment files** (e.g. this lib family's `/adm/simul_efun/*.lpc`,
  which are `#include`d INTO `/adm/obj/simul_efun.lpc` rather than loaded
  standalone) compile fine as part of that larger unit but can FAIL when
  `lpcc`/`find_object()` compiles them as an independent top-level object —
  because driver-visible things like `main_file_name()` (used by
  `master::valid_override()` to know "what's the real compilation unit,
  as opposed to which physical file the `efun::` call is textually in") now
  report the fragment itself instead of the file that really includes it.
  **Verify against the real full-driver boot log before trusting an lpcc-only
  failure on one of these**: if `grep` for the error string comes up empty
  in an actual `driver config.fluffos` boot log, it's a sweep artifact, not
  a live bug.
- **Room/NPC/board files that reference other objects by hardcoded path**
  (`move(loc)`, `call_other(path, ...)`) fail with `Bad argument 1 to EFUN
  call_other()` or `call_other() couldn't find object 'PATH'` when `lpcc`
  compiles them alone, if the referenced object hasn't been compiled yet in
  this isolated run (no real player, no real room graph, no preload
  ordering) OR — the more common real-content case — if `PATH` genuinely
  doesn't exist in this archive at all (see §13, missing zone content).
  Distinguish the two by checking whether the target file exists on disk
  (`find work -name "targetname.lpc"`); if it doesn't exist anywhere, it's
  a real content gap, not a testing artifact, and isn't something to
  fabricate a fix for.
- Net effect: **triage the sweep's failures by category before fixing
  anything** (group by error message text), fix the small number that are
  genuine driver-compat/typo bugs (typically distinctive one-off error
  types: syntax errors, "Undefined function/variable" on somewhat common
  names, illegal-character errors, return-type mismatches), and just note
  the big repetitive categories (call_other/couldn't-find-object clusters)
  in that lib's `NOTES.md` as expected noise once you've spot-checked a
  couple and confirmed the pattern.
- **On a mega-lib (tens of thousands of files, e.g. the "nitan" family at
  26,000-55,000 `.lpc` files), the full sweep's memory use can become the
  real bottleneck, not time.** `lpcc --batch` keeps every compiled object
  loaded in ONE VM session for the whole run (that's the whole point — no
  reboot per file), but that means memory grows *unbounded* across tens of
  thousands of files with no unloading; on this 23GB host it drove free
  memory down to ~370MB with 2.6GB swapped after ~18 minutes on a 54,600-
  file lib, well before finishing, at real risk of OOM-killing something
  else. If a sweep on a mega-lib is eating most of system RAM after many
  minutes, kill it rather than let it run to potential OOM — the boot +
  interactive-connect test (this pipeline's other verification step) is
  the test that actually caught every real bug found on nitan170911/nitan6
  (see §15), and is a perfectly sufficient signal on its own for a lib this
  size; treat the full sweep as a nice-to-have on mega-libs, not a
  required gate the way it is on normal-sized (hundreds to low-thousands
  of files) libs.
  **The threshold is lower than "tens of thousands"**: `xo_final`, at only
  ~7,174 files, ALSO drove this same 23GB host down to ~214MB free with
  heavy swapping after ~12 minutes/18GB RSS on the lpcc process alone —
  apparently something about this particular lib's content (large/deeply
  nested mapping literals in skill-action tables?) makes its memory
  footprint per file much heavier than a typical lib. **Don't assume
  "normal-sized" (low thousands of files) is automatically safe** — watch
  `free -h` / the lpcc process's RSS while a sweep runs on ANY lib, and
  kill it the moment it's eating a large fraction of system RAM,
  regardless of file count.

### 7. Missing `get_root_uid()`/`get_bb_uid()` master applies (PACKAGE_UIDS)

Our driver builds have `PACKAGE_UIDS` on. FluffOS's `set_master()`
(`src/vm/internal/master.cc`) requires `master::get_root_uid()` and
`master::get_bb_uid()` (note: the apply is named `get_bb_uid`, NOT
`get_backbone_uid` despite the C++ constant being `APPLY_GET_BACKBONE_UID` —
see `src/base/internal/applies` `GET_BACKBONE_UID:get_bb_uid`) to exist and
return a uid string; if either is missing, `set_master()` calls `exit(-1)`.
Many of these old libs (pre-uid-package MudOS mudlibs) don't implement one
or both. **Fix per-lib: add a minimal stub to `master.lpc`** returning a
sensible uid string (`"ROOT"`, or whatever `ROOT_UID`/`BACKBONE_UID`
constants the lib already defines resolve to) — grep the lib's `master.lpc`
for `get_root_uid`/`get_bb_uid` early in the per-lib pass, before attempting
a boot, alongside the §4 `load_object`-in-`valid_read` check.

### 8. Driver bug (patched upstream in `~/src/fluffos`): null `backbone_domain`

Distinct from #7 above and NOT a mudlib bug — a real FluffOS driver
null-pointer bug, now fixed in this checkout
(`src/packages/mudlib_stats/mudlib_stats.cc`, `init_domain_for_ob()`).
Symptom: clean compile, then a SIGSEGV during boot with a backtrace through
`f__call_other → find_object → load_object → init_object →
init_stats_for_object → init_domain_for_ob`, crashing on
`backbone_domain->name`.

Root cause: `set_master()` calls the `author_file()`/`domain_file()` master
applies **before** it calls `set_backbone_domain()` (that ordering is
deliberate/documented in a comment right above the crash site — `domain
init` is supposed to short-circuit via the `!current_object->uid` guard
during master's own bootstrap). But by the time `author_file()`/
`domain_file()` run, `master_ob->uid` has ALREADY been set (a few lines
earlier in the same function), so that guard no longer protects this
window. If the lib's `author_file()` (commonly implemented as `call_other`
to the simul_efun object, itself calling back into other daemons) causes
ANY new object to load during this window, that object's
`init_stats_for_object()` reaches `init_domain_for_ob()` with
`backbone_domain` still null → crash.

**Fix applied**: guard the one unguarded dereference —
`if (backbone_domain && strcmp(backbone_domain->name, domain_name) == 0)`.
Null `backbone_domain` now degrades to "no match yet" instead of crashing;
domain gets assigned once the real backbone domain is set moments later.
Both driver builds (`build/`, `build-debug/`) were rebuilt after this
patch — **if you ever rebuild fluffos from a fresh checkout or pull
upstream, re-apply/verify this patch is present** (`git log`/`git diff` in
`~/src/fluffos` should show it; it isn't upstreamed anywhere else). This is
a systemic old-MudOS-lineage pattern (author_file/domain_file implemented
via call_other during bootstrap) — expect to hit the SAME crash signature
on other libs and NOT need to re-diagnose it, just confirm the patched
driver is what's running (`build-debug`/`build`, not some other checkout).

### 8b. Calling a same-file function before its definition can fail to resolve

When adding a new function to an existing file (e.g. the `message_combatd`
alias in §8's write-up), calling a function defined LATER in the same file
produced `error: Undefined function message_vision` even though it's
defined a few lines below, in the same compilation unit. Simplest fix:
just reorder so the alias/wrapper comes AFTER the function it calls (don't
rely on whole-file symbol-table-first resolution within one file for a
brand-new addition — existing code in these libs is presumably already
ordered call-site-after-definition throughout, which is probably exactly
why this never surfaced as a pre-existing bug).

### 8c. `valid_read`/`valid_write` overriding the caller with `this_player()` can wrongly deny a privileged system caller

Found on lib #4 (bxsj) and likely to recur on any lib sharing this
`securityd.lpc` lineage (same family as §4's `SECURITY_D` pattern — many of
these libs derive from a common ancestor mudlib): a common idiom is

```lpc
int valid_read(string file, mixed user, string func) {
    if (this_player())
        user = this_player();
    ...
}
```

The intent is "if a player is driving this read, check THEIR permissions,
not the calling object's" — reasonable for genuine player-initiated file
access. But it fires unconditionally, including when `user` is actually a
privileged SYSTEM caller (e.g. `master.lpc` lazily `load_object()`ing a
daemon that was never on the preload list, well after boot) that merely
happens to run while some unrelated player is connected (`this_player()`
is non-null for totally incidental reasons — the code path was reached
from inside that player's login `input_to` chain). The read gets
attributed to the connected player's own (unprivileged, "(player)")
status instead of the real caller's root euid, and a normal `exclude_read`
rule protecting `/adm` from ordinary players denies it — **permanently
stranding every new connection** the first time such a lazy load happens
post-connect (in this lib: `BAN_D`/`band` and `UPTIME_CMD`/`cmds/usr/uptime`,
both un-preloaded, both first touched from inside the brand-new
connection's own login sequence).

**Diagnosis approach that found this fast**: don't guess from the generic
`*Read access denied.` driver message (`src/vm/internal/simulate.cc:463`)
alone — temporarily instrument the master apply itself
(`efun::write_file("/DEBUG.log", sprintf("file=%O user=%O func=%O
result=%O\n", file, user, func, result))` around the `SECURITY_D->
valid_read()` call in `master.lpc`) to see the EXACT file/user/func/result
for every check during a real repro, then remove the instrumentation once
diagnosed. This took minutes and pinpointed the exact two denied
`load_object` calls and their (surprising) `user` identity, versus a much
longer path of reading ACL tables and guessing.

**Fix**: only fall back to `this_player()` when the passed-in `user`
doesn't already carry a resolvable identity:
```lpc
if (this_player() && !geteuid(user) && !getuid(user))
    user = this_player();
```
This preserves the original intent (attribute ambiguous-identity reads to
the connected player) without clobbering a caller that already has a
legitimate euid (like `master_ob`, running with root euid).
**Check for this exact `if (this_player()) user = this_player();` shape in
any lib's `securityd.lpc`-equivalent early, right alongside the §4/§7
master.lpc checks** — it's cheap to grep for and expensive to hit blind
(it looks like a total, unexplained login lockup with no compile errors
at all, since everything up to this point boots clean).

### 8d. `#include <local.h>` for a header that lives next to the including file

Found on lib #3 (unknownlib20150716/小雨西游II), affecting ~200+ files: a
common idiom in this lineage is a per-NPC/per-room "flavor" header
(`greeting.h`, `ground.h`, etc) sitting in the SAME directory as the `.lpc`
file that uses it, but included with angle brackets —
`#include <ground.h>` — not quotes. Per this driver's documented
resolution rule (`docs/lpc/preprocessor/include.md`): `"file"` searches
the including file's own directory THEN the include path; `<file>`
searches the include path ONLY, never the local directory. Whatever
driver these libs originally ran on apparently didn't enforce that
distinction as strictly; here it's `Cannot #include ground.h`/`greeting.h`/
etc for every such file.

**Fix (one shot, not per-file)**: implement `master::get_include_path()`
(a real apply, `docs/apply/master/get_include_path.md` — returns an array
of directories to search, `":DEFAULT:"` standing in for the configured
`include directories` list) to prepend the COMPILING file's own directory:
```lpc
string *get_include_path(string file)
{
    string *parts = explode(file, "/");
    if (sizeof(parts) <= 1)
        return ({ "/", ":DEFAULT:" });
    return ({ "/" + implode(parts[0..<2], "/"), ":DEFAULT:" });
}
```
This fixes every `<local.h>`-next-to-its-user file in the whole lib at
once, without touching a single `#include` line. (No `strrchr`/similar
efun exists in this driver for dirname-style string ops — use
`explode()`/`implode()` on `/`, as above.) Check whether a lib's
`master.lpc` already implements `get_include_path()` before adding this —
don't overwrite an existing one, extend it (prepend the local directory to
whatever it already returns).

**Timing gotcha (found on lib #12, es1_win): `get_include_path()` is NOT
consulted for files compiled during PRELOAD.** Per the driver source
(`compiler/internal/lexer_utils.cc`'s `init_include_path()`): "No VM
context: keep the config-file include path as-is -- there is no master
object to ask" — `compiler_vm_context` isn't set yet for at least some
preload-time compiles, so the master apply is silently skipped and the
`<local.h>` `#include` still fails to resolve for anything reached via
preload (which, transitively, can be almost anything — a preloaded room
inheriting a base that `#include`s the broken header). Symptom is
confusing: no compile error shows anywhere obvious, because it surfaces
much later, e.g. as an "Undefined function" error the first time a live
feature actually calls the missing function — and if that first call
happens inside a new connection's `logon()` chain, the DRIVER's own
`new_conn_handler` swallows the error and just silently disconnects the
user with NO message at all (see the diagnosis technique note right
below). **If a `<local.h>` failure shows up in a file that's ever reached
via preload (most `std/`-tree base classes are), don't rely on
`get_include_path()` alone — also change that specific `#include
<x.h>` to `#include "x.h"` (quotes)**, which resolves against the
including file's own directory unconditionally, with no VM-context
dependency at all.

**Diagnosis technique for "server hangs / silently disconnects on
connect, no error anywhere I can see"**: the LPC-level error IS being
thrown (check `debug.log` in full, not just a filtered grep — the crucial
line can be far from where you're looking) but the driver's
`new_conn_handler` catches any error escaping a connection's `logon()`
chain and disconnects with zero message to the client. If even
`debug.log` seems clean, temporarily instrument the suspect function with
`write("DEBUG A\n"); ... write("DEBUG B\n");` bracketing each statement,
reboot, connect once, and see which markers printed — narrows the failure
to one statement in seconds instead of guessing. Remove the instrumentation
once found (same technique used for the securityd.lpc diagnosis in §8c).

### 8e. `tail` is not a real FluffOS efun (never was, in this driver)

Seen on lib #1 (`cmds/wiz/tail.lpc`, non-fatal there — an unused admin
command) and lib #6 (`adm/simul_efun/file.lpc`, FATAL there — inside a
function that gets compiled as part of `simul_efun.lpc`, so the whole
boot fails): `efun::tail(file)` / bare `tail(file)` calls that expect a
"print the last N lines of a file" builtin that doesn't exist anywhere in
this driver (`error: Unknown efun: tail`, and no `docs/efun/*/tail.md`
either). Whatever old driver these libs targeted apparently had one; it
isn't part of FluffOS's efun set at all, not something removed/renamed
here. **Fix: reimplement in plain LPC** — `read_file()` + `explode()` on
`"\n"` + slice the last N elements + `write(implode(...))`:
```lpc
int do_tail_lpc(string file, int n) {
    string content, *lines;
    int start;
    content = read_file(file);
    if (!stringp(content)) return 0;
    lines = explode(content, "\n");
    start = sizeof(lines) - n;
    if (start < 0) start = 0;
    write(implode(lines[start..], "\n") + "\n");
    return 1;
}
```
Check whether the surrounding function actually has any live callers
before spending time matching old return-value semantics exactly — in
both places seen so far it was dead/rarely-used admin tooling.

### 8f. `TYPE * name1, name2;` — the array modifier doesn't propagate across a comma list

Found on lib #7 (ds386, Dead Souls) — a different lineage entirely (English,
Nightmare-derived, not Chinese-wuxia) but relevant to ANY future English-
language archive since this looks like an old-codebase-wide habit, not a
one-off typo. This driver's grammar scopes a declaration's `*` to the
FIRST declarator only, C-style (`int *a, b;` declares `a` as `int *` but
`b` as plain `int`) — but Dead Souls writes `object * dummies, all_inv;`
throughout, clearly INTENDING both to be arrays (both get assigned
array-returning calls a few lines later: `all_inv = all_inventory();`,
`dummies = ({})`). Symptom: `error: Bad assignment ( TYPE vs TYPE * )`
and cascading `Value indexed has a bad type` on the very next use of the
"forgotten-star" variable — often in a totally different, unrelated-
looking file each time, since it's one instance of a systemic authoring
habit, not a single bug.

**Fix (one shot, not per-declaration)**: found 33 affected files by
grepping for the shape `TYPE * name1, name2, ...;` (a full declaration
line, 2+ bare comma-separated identifiers, ending in `;`) and wrote a
small Python script to add a `*` before every subsequent identifier in
the list that doesn't already have one (leaves an already-correct
`string *a, *b;` untouched). Safe because the pattern is narrow enough to
only match genuine multi-declarator statements, not function calls or
other comma-separated contexts. Re-run the same grep after `convert_lib.sh`
finishes on any new lib — if it's non-empty, this bug is present.

### 8g. Before treating N identical lpcc-sweep errors as N bugs, check for one shared inherited file

If the exact same error string shows up in dozens/hundreds of otherwise-
unrelated files in an lpcc sweep, check whether they all `inherit` (or
`#include`) one common base file first — fixing that ONE file can
resolve the entire cascade in one shot, versus wasting time investigating
each affected file individually assuming they're separate bugs. (Found on
ds386/Dead Souls: 299 files all failed identically because they all
inherit `lib/body.lpc`, which had one bad `class TYPENAME array Foo()`
declaration — fixing that single line resolved all 299 sweep failures at
once. General technique: extract the exact same underlying error line
from a handful of the failing blocks — if it's byte-identical across all
of them, it's almost certainly one shared dependency, not independent
bugs.)

**Variant found on `xiyangzaixian3` (archive #48)**: the shared
dependency isn't always a broken FILE — it can be a missing `#define`.
81 files under `quest/game/` all did `inherit WQA_ROOM;`, and
`include/globals.h` simply never defined the `WQA_ROOM` macro at all
(genuinely absent in the raw archive too, not an artifact of
conversion) — the target file it should have pointed at
(`/quest/game/wqa_room.c`) existed and was fine. Adding one `#define
WQA_ROOM "/quest/game/wqa_room"` resolved all 81 failures in one shot.
Same "one shared root cause, not N bugs" principle, just check for a
missing macro definition (not only a broken shared file) when N
failures share an `inherit`/`#include` target name that never resolves.

### 8h. `convertd.lpc`'s Greek-table stray-backslash typo can recur, and CRLF silently breaks the naive sed fix

The stray-trailing-backslash-before-closing-quote bug documented for
`fluffos_xiyou2000` (`"α\",` should be `"α",`, in a charset-conversion
daemon's Greek-alphabet lookup table) recurred verbatim in `mhxy` (same
西游记 lineage) — check `adm/daemons/convertd.lpc` for this shape on any
lib in this family. **The straightforward fix
(`sed -i -E 's/\\"(,)?$/"\1/'`) can silently do nothing if the file has
CRLF line endings** — `sed`'s `$` anchors before the `\n`, not before a
`\r` that precedes it, so a trailing `\r` after the comma means the
pattern never matches, `sed` reports 0 changes with no error, and it's
easy to assume the file was already clean. **Verify a "no changes made"
result actually means "nothing left to fix"** (re-`grep` the pattern
after any such sed, don't just trust silence) — and if the file has CRLF,
use `s/\\"(,)?\r?$/"\1\r/` (allow and preserve the optional trailing
`\r`) instead.

### 9. Fullwidth Chinese punctuation used as code syntax (typo, not encoding)

A handful of pre-existing typos (found via the lpcc sweep's "Illegal
character 0xXX" errors spanning 3 UTF-8 bytes) where the original author's
input method left a **fullwidth punctuation mark inside actual code
syntax** instead of the ASCII equivalent — `set("short"， "...")` (fullwidth
comma `，` U+FF0C as an argument separator) and `#include <ansi。h>`
(fullwidth period `。` U+3002 in an include filename). This is a genuine
authoring mistake predating our involvement, not something the encoding
conversion introduced — confirmed by checking the raw GBK bytes decode to
the same fullwidth character. **Do not blanket-replace fullwidth
punctuation** (it's correct and intentional inside actual Chinese string
content, which is most of every file) — only fix the specific occurrences
the compiler flags as illegal characters, by hand, checking each is really
in code position (between/around syntax tokens) and not inside a string.

### 10. Missing closing quote before string concatenation (typo)

Another pre-existing typo category: `"$N把身上的 + ob->query("name") + "卖掉。\n"`
— the string literal is missing its closing `"` before the `+`, so the
parser reads everything up to the NEXT `"` (the one opening `ob->query("name"`'s
argument) as part of one giant malformed literal, then chokes on the `+`
inside it as a syntax error, cascading into further "Illegal character"
noise. Fix: add the missing `"` (`"$N把身上的" + ob->query("name") + "卖掉。\n"`).
Same shape recurs wherever `notify_fail`/`message_vision`/etc concatenate a
literal + a `->call()` + another literal — grep the lpcc sweep's "Illegal
character" hits for a mid-Chinese-text location (as opposed to a
standalone punctuation typo per §9) and check for a dropped closing quote
before assuming it's something else.

### 11. Copy-paste bugs: inherit/init calls pointing at nonexistent std types

Found via "Inherited file 'X' does not exist" / "Undefined function
init_X": an object file whose OWN header comment and in-game name disagree
with what it actually `inherit`s — e.g. `obj/weapon/axe.lpc` (comment says
"dagger.c", sets `id: "dagger"`, item name "钢刀"/steel blade) was written
`inherit AXE; ... init_axe(...)`, but `/std/weapon/axe.lpc` was never
implemented in this lib (only blade/dagger/staff/sword/weapon exist) —
clearly a copy-paste-and-half-rename artifact from whatever file this was
cloned from. Fix by matching the inherit/init call to what the file's own
content (name/id/comment) says it actually is, using an existing sibling
`std/` file with the same init-function signature as the template — don't
try to implement the missing base class from scratch (that's fabricating
a whole new item subtype, out of scope).

### 12. Orphaned non-LPC `.c` files (data mistakenly caught by the rename)

`convert_lib.sh` renames every `*.c` to `*.lpc` unconditionally, which is
usually right (§ "What counts as LPC source") but can catch a stray
non-source file that happens to end in `.c` — found one instance: a
plain-text ASCII-art map (`d/shenmin/shenminmap.c`, pure box-drawing/room-
layout art, not a single line of LPC) that isn't `#include`d, inherited,
or referenced by path anywhere else in the lib (`grep -rl` for its
basename came up empty besides itself) — almost certainly dead/orphaned
content from a removed "map" command. Once renamed to `.lpc` it shows up
as an lpcc-sweep "failure" (real: it doesn't compile, it's not code) that
is harmless in practice since nothing ever `load_object()`s it. If you hit
one of these: confirm nothing references it, then rename it to `.txt` (or
its original extension) instead of leaving it as a permanently-broken
`.lpc` — keeps the sweep's pass/fail signal meaningful for files that
actually matter.

### 13. Missing zone/room content is a real archive gap, not a bug to fix

`clone/board/*` (bulletin-board objects that `move()` themselves into a
named room on `create()`) commonly reference room paths that don't exist
ANYWHERE in the archive — not just unloaded-yet, genuinely absent (whole
zone directories missing: no `/d/wudang`, `/d/shaolin`, `/d/huashan`, etc,
despite dozens of board objects referencing rooms under them). This means
the archive shipped without most of its game-world content — likely a
"core/skeleton" release separated from a much larger world pack that never
made it into this particular download. **Don't fabricate the missing
rooms.** Document the gap in that lib's `NOTES.md` (which zones/how many
files affected) and move on — these board clones aren't on any preload
list, so they simply never get created in normal play; the only symptom is
lpcc-sweep noise, not a real boot/gameplay defect.

### 14. `valid_override()` needs the 3-arg signature for `#include`d simul_efuns

`master::valid_override(file, name)` (2-arg, old-style) can wrongly reject
a legitimate `efun::` override written inside a file that's `#include`d
into `simul_efun.lpc` rather than being `simul_efun.lpc` itself (e.g.
`/adm/simul_efun/object.lpc`'s `efun::destruct()` call, wrapped by a
logging `destruct()` override) — `file` is the physical file containing
the `efun::` call, which for an `#include`d fragment is never equal to
`SIMUL_EFUN_OB`. The docs (`docs/apply/master/valid_override.md`) have
always specified a 3rd `main_file` parameter for exactly this reason ("file
will be the actual file the call appears in; mainfile will be the file
being compiled (the two can differ due to #include)") — old libs that only
implemented the 2-arg version are relying on undefined/permissive behavior
for the missing arg. Fix: add the 3rd parameter and check
`main_file == SIMUL_EFUN_OB` (or `MASTER_OB`) too. **In practice this may
never surface in a real boot** (confirmed on the pilot lib: the real driver
boot never hit this error even before the fix, only `lpcc` compiling the
fragment as a standalone top-level object did — see §6b) — but the fix is
correct and free, so apply it whenever you spot a 2-arg `valid_override`
during the master.lpc read-through from §4/§7.

### 15. Simul_efun-based generic `set`/`query`/`delete` property storage: `this_object()` is the SIMUL_EFUN OBJECT during a bare simul_efun call, not the caller — a whole-mudlib architecture bug, not a missing function

This is the single most important/subtle finding of the whole project so
far (discovered on `nitan170911`, and it applies verbatim to `nitan6` and
any other "NT/nitan/Lonely" lineage lib with the same `adm/kernel/
simul_efun/wizard.lpc` pattern — check for it proactively).

**The pattern.** These mudlibs implement a generic per-object property
system via `bare set(prop, data)` / `query(prop)` / `delete(prop)` calls
used EVERYWHERE (tens of thousands of call sites), resolved as **simul_efun
calls** (`adm/kernel/simul_efun/wizard.lpc` defines them) whenever the
calling file has no local override. The overwhelmingly dominant calling
convention (35000+ call sites for `query`, 4000+ for `set` on this one lib)
is actually **3 args**: `query(prop, ob)` / `set(prop, data, ob)` — an
explicit *target object*, not the documented 2-arg "raw" flag form.

**The bug.** Per FluffOS's `call_direct()` (`vm/internal/base/interpret.cc`,
used by `call_simul_efun()` in `vm/internal/simul_efun.cc`),
`current_object` — and so `this_object()` — becomes **the simul_efun
object itself** for the duration of a bare simul_efun call, not the
original caller (`previous_object()` is the caller). Confirmed empirically
with a two-object `lpcc` test: object A calls `set("hp", 42)` with no
target; object B (never touched) then calls `query("hp")` and gets back
`42` — **every caller that relies on the plain simul_efun for its own
storage is reading and writing the simul_efun's own single shared `dbase`
mapping**, not its own. In a live game this means every character/room/
item without its own override would (mostly) share one property bag.

**The fix — two parts:**
1. **Give `feature/dbase.lpc` real, local `set`/`query`/`delete` (+
   `_temp` variants) methods**, not just the storage variable. Almost
   every relevant object (`inherit/char/char.lpc`, `inherit/room/room.lpc`,
   etc.) already does `inherit F_DBASE` directly — once dbase.lpc defines
   these as real functions, every such object gets them as genuine
   *inherited, local* functions. A bare `set(...)` call from any feature
   file composed into that object's program then resolves locally against
   *that object's own* `dbase`, never touching the simul_efun at all. The
   trailing `ob` parameter, when given and not `this_object()`, redirects
   via a plain `ob->set(prop, data)` call_other (ordinary call_other
   semantics are fine here — `current_object` becomes `ob` correctly, no
   simul_efun weirdness, since this is a real function call not a bare
   simul_efun dispatch).
2. **Keep a matching set in the simul_efun's own `wizard.lpc`** as a
   fallback ONLY for objects that don't inherit F_DBASE at all — with the
   same `ob`-redirect logic, so at least the common `query(prop, ob)` /
   `set(prop, data, ob)` convention behaves correctly there too instead of
   silently hitting the shared fallback dbase.

**A trap inside the fix — infinite recursion.** A handful of files define
their OWN local `set`/`query`/`delete` override for a couple of special
properties (room.lpc's `short`/`long`, user.lpc's level-up cascades,
baby.lpc's `combat_exp`, master.lpc/giftd.lpc/examined.lpc similar), and
fall through to "the generic implementation" for everything else. In the
original archive this fallback was `efun::set(...)` etc. (not a real efun
on this driver — see the pattern below). **Do not "fix" that fallback by
routing it through the simul_efun object** (`SIMUL_EFUN_OB->set(idx, data,
this_object())`): since `ob == this_object()` in the pure-fallback case,
the simul_efun's own `ob`-redirect (part 2 above) calls straight back into
`ob->set(...)` — i.e. back into the SAME overriding function — infinite
recursion ("Too deep recursion", crashes the whole connection). The
correct fallback, since these files `inherit F_DBASE` (directly or
transitively), is `::set(idx, data)` / `::query(idx)` / `::delete(idx)` /
`::add(prop, data)` — explicit **parent-scope** call to F_DBASE's real
implementation, bypassing the local override without going anywhere near
the simul_efun. Only use `ob->X(...)` (plain call_other) when `ob` is
confirmed to be a *different* object than `this_object()`.

**Related: `efun::X()` for X that was never a real efun.** Grep the whole
lib for `efun::set(`, `efun::query(`, `efun::delete(`, `efun::addn(` —
none of these are real FluffOS efuns (verify against `find ~/src/fluffos/
src -iname '*.spec' | xargs grep`), they only ever existed as user-defined
simul_efuns on the original server. `addn(prop, data, ob)` / `addn_temp`
(numeric increment-or-set) show the same "never actually defined, only
referenced" gap as `remove_ansi`/`B2G`/`db_affected`/`noansi_strlen` (see
below) — restore as real simul_efuns delegating to `ob->add(prop, data)`
(F_DBASE's own `add()`, which already does the increment-or-set logic).

### 15b. More "only ever called, never defined" globals in the same family

Beyond `addn`/`addn_temp` (§15), this lineage has several more bare
functions called everywhere but genuinely undefined anywhere reachable —
each one only surfaces as a *runtime* "Undefined function called: X" (not
a compile error) the first time actual game logic reaches that code path,
so a clean boot + lpcc PASS does not mean these are all found; keep
watching debug.log during interactive testing:
- **`remove_ansi(str)`** — strip ANSI color codes. Was only ever a real
  method inside one unrelated inherited object (`feature/quest.lpc`), not
  reachable from simul_efun context. Restore as a simul_efun (see
  `adm/kernel/simul_efun/ansi_util.lpc` on nitan170911) using the same
  color-table logic, included EARLY in `simul_efun.lpc` (before anything
  that calls it — same #include-order rule as everything else in this
  composed file, §8b).
- **`noansi_strlen(str)`** — `strlen(remove_ansi(str))`, trivial, same gap.
- **`B2G(str)`** — "Big5 to GBK" charset conversion; every call site but
  one or two is commented out, confirming it was already being phased out.
  Since the whole mudlib runs in UTF-8 post-conversion, there's no Big5 vs
  GBK distinction left — a passthrough (`return str;`) is correct, not a
  stopgap.
- **`db_affected(db)`** — affected-row count after `db_exec()`. This
  driver's DB package (`src/packages/db/db.spec`) has no such efun, and
  `db_exec()` itself returns 0 for INSERT/UPDATE/DELETE (no result set) —
  there's no real affected-row count obtainable through this driver's DB
  API at all. Since every call site already checks `db_exec()`'s own
  return for the real success/failure signal, a stub returning `1` (assume
  ≥1 row) is a reasonable, documented compromise, not a silent lie.
- **`clr_ansi(str)`** (found on `tianxia`, archive #50) — same job as
  `remove_ansi` above, just a different name from a different lineage;
  called from ~10+ files including the lib's own `valid_chinese()`. Same
  fix, same include-order caveat.
- **`chinese_number(int)`** (found on `tianxia`) — Arabic-to-Chinese
  numeral spellout (一二三...), called from ~90 files. Restore using the
  same algorithm as `nitan170911`/`nitan6`'s `chinesed.lpc` — confirmed via
  a doc-file credit that `tianxia` shares an author ("发现号/Find") with
  that lineage, so the ported implementation is exact, not a guess.
- **`changed_match_path(mapping, string)`** (found on `tianxia`) — thin
  historical wrapper; restore as a straight passthrough to the real
  `match_path()` efun.
- **`query_bandwide()`** (found on `tianxia`) — bandwidth-readout stub with
  no FluffOS equivalent at all (checked core/sockets/contrib specs).
  Called UNGUARDED from `logind.lpc`'s connection-entry function on
  *every* connection with no `catch()` — this is the same silent-crash-in-
  logon()-chain shape as §15d, and on `tianxia` it was killing every
  connection before any prompt appeared. Stub returning `({ 0.0, 0.0 })`
  (purely cosmetic) fully resolves it.
- **`query_shadowed()`** (found on `tianxia`) — called bare from
  `feature/self.lpc`/`std/equip.lpc`. The correct restoration is
  `shadow(previous_object(), 0)` — **not** `shadow(this_object(), 0)`.
  Since this is a bare simul_efun call, `this_object()` inside it resolves
  to the simul_efun object itself (§15's core footgun), so the naive
  `this_object()` version always returns 0. On `tianxia` this was blocking
  `/obj/user/user` (the player body class) from compiling at all, which
  silently broke character-creation completion (`make_body()` returning 0)
  immediately after the Chinese name/password were accepted — the single
  most impactful fix in that lib's pass, and worth checking first whenever
  a lib accepts registration input but then never actually drops the
  player into the game world.

  **This is now a recognized recurring failure mode, not a one-off**:
  found again on `nitan_ceshi` (archive #60) in an unrelated shape — a
  direct (non-`->`) call `is_killing(ob)` in `/clone/user/user.lpc` (the
  player body class there) passed an object where `is_killing(string id)`
  declares a `string` parameter; every other one of 60+ call sites
  elsewhere in the same lib correctly passed `ob->query("id")`. Because
  it's a *direct* function call, this driver's static type checker
  enforced the declared parameter type strictly and refused to compile
  the whole file. **General lesson**: whenever registration accepts a
  real Chinese name/password but the character never actually lands in
  the game world (silently, with no crash message pointing at the
  problem), suspect the player-body class object itself failing to
  compile — grep its own file's `debug.log` compile line specifically,
  don't assume the registration daemon's own logic is at fault. The two
  known root causes so far are a never-defined-simul_efun call (§15b) and
  a genuine same-object function-argument-type mismatch like this one —
  both are single-call-site bugs with an outsized, easy-to-misdiagnose
  effect.

### 15c. `/adm/etc/preload`-style data files also need their `.c` refs fixed — the quote-based sed pass doesn't touch them

`convert_lib.sh`'s literal-`".c"`-reference fixer (§2) only touches lines
matching a *quoted* `".c"` inside `.lpc`/`.h` source. Some mudlibs also
have a **plain-text data file** (no quotes, one bare path per line, e.g.
`/adm/etc/preload` listing daemons to load — `/adm/daemons/securityd.c`,
`/adm/daemons/logind.c`, ...) that the mudlib's own preload logic
`explode()`s and `load_object()`s directly. After the `.c`→`.lpc` rename,
these bare `.c` paths point at files that no longer exist; `load_object()`
on them fails, usually silently swallowed by the mudlib's own `catch()`
around the preload loop — so the daemon in question (often
`securityd`!) just **never loads, with no visible error at all**. Symptom:
`master.lpc`'s `valid_write`/`valid_read` (which defer to
`find_object(SECURITY_D)`, defaulting to **deny** for write if not found)
silently reject every write, and any `->method()` call on the
security daemon's macro path just does nothing. Confirmed the daemon
never loaded by running `lpcc --batch` against `SECURITY_D`'s own path
directly and seeing `FAIL`. Fix: `sed -i 's/\.c$//' <the data file>` (or
rename to `.lpc` if the reader is extension-strict) — check any
`config`-like directory (`adm/etc/`) for OTHER files with this same bare
`/path.c` pattern, not just `preload`.

### 15d. Diagnosing a silent runtime crash inside a simul_efun/master apply chain — safe_apply()/find_object() swallow the error silently, even with a plain `catch()`

Extending §8c: `new_conn_handler`'s call to `logon()` uses `safe_apply()`
(`vm/internal/apply.cc`), which wraps the call in a raw C++ `try/catch`
that discards the LPC error string entirely — no trace, no master
`error_handler` call, nothing. **A plain LPC `catch(expr)` wrapped around
the suspect call is the fix**, but note: wrap the *smallest* enclosing
statement, not just the top-level call — if the real error is buried
several call-other layers deep (`logon() -> LOGIN_D->logon() -> …`), you
need the `catch()` at (or need to add one temporarily at) the level that
actually executes the throwing statement, since `safe_apply`'s outer catch
still eats anything that isn't caught by an LPC `catch()` first. Once
caught, `efun::write(err)` (not the mudlib's own `write()` — that itself
routes through `this_player()`/`previous_object()` plumbing that may not
be safely established yet) reliably reaches the connected telnet client;
`efun::write_file()` to a scratch path does NOT reliably work at this
stage if the security daemon hasn't loaded yet (see §15c) since
`valid_write` denies by default. Bisect by wrapping progressively smaller
statements in `catch()` (or adding sequential `efun::write("CKPTn\n")`
checkpoints) until you isolate the exact failing line; **always remove
this instrumentation once the root cause is fixed** — it's easy to forget
one checkpoint buried in a large function (happened once: a leftover
`efun::write("CKPT9\n")` etc. leaked into the actual welcome-banner output
because the running driver process had compiled the OLD (uncleaned)
version of the file before the cleanup edit landed — **LPC objects don't
recompile just because their source file changed on disk; you must
restart the driver process** after every edit to see it take effect, even
mid-investigation).

### 15e. A "restore graceful degradation" pattern: guard every un-checked `->method()` chained straight onto a factory call

Several bugs in this family share one shape: `SOME_D->create_x(...)
->move(...)` or `ob = SOME_D->create_x(...); set(..., ob); ob->color(...)`
with **no check that the factory call actually returned an object** —
`create_object()`/`create_dynamic()`-style factories in this codebase
legitimately return `0` on a data/content mismatch (e.g. a randomly picked
item template file that doesn't `file_size()` correctly), and the
original (looser-typed) driver apparently no-op'd a call_other on `0`
instead of throwing. Search for the *caller's* immediate next line rather
than assuming the factory itself is broken — the minimal, correct fix is
an `if (objectp(ob))` guard at the call site, not "fix" the factory to
never return 0 (it's supposed to be able to, for legitimately-missing
content).

### 15f. Bare `array` as a full type-by-itself declaration silently doesn't declare anything on this driver

`array name;` or `array name = expr;` (no preceding element type — as
opposed to `mixed *name`, `int *name`, etc.) is common across this whole
mudlib family (~30-40 occurrences per lib). The compiler's grammar
(`opt_atomic_type L_ARRAY`) technically allows an *empty* atomic type
before `array`, but empirically on this driver it does not actually
register `name` as a declared variable at all: `array lines;` alone
compiles with **no error**, but any later use of `lines` (e.g. `lines =
({...})`) fails with `Undefined variable`/`Illegal lvalue`; the combined
form `array name = expr;` in one statement fails immediately with `Illegal
LHS`. Confirmed with a minimal `lpcc` test isolating the exact statement.
Fix per-occurrence as it surfaces (via lpcc sweep or an interactive-test
crash) by inserting the actual element type: `array` → `mixed *`. **Do
not try to bulk-fix every occurrence found via grep** — most are in files
that are never reached during a basic boot+login test, and this is
exactly the "long tail, not all reachable at once" situation in §6b;
fixing only what a real lpcc/interactive-test failure actually surfaces
keeps the signal-to-effort ratio sane on a lib with 50,000+ files.

### 15g. `#include <Foo.h>` vs the actual `foo.h` on disk — case-sensitivity mismatch from a Windows-origin archive

Found on `xo` (archive #28): a small number of `#include <Action.h>`
(capital A) directives referenced an actual file that only exists as
`include/action.h` (lowercase) — silently resolves fine on the original
Windows development environment's case-insensitive filesystem, hard
compile error (`Cannot #include`, cascading to `Undefined class`/
`Undefined variable` everywhere that transitively depends on it) on this
Linux/case-sensitive one. Diagnose via the lpcc sweep: if ONE error
category (`Cannot #include X.h`, `Undefined class/variable Y`) dominates
the failure count by a wide margin, `grep -rn "include.*<X.h>"` and
compare against the real on-disk filename's case before assuming a
missing-content gap — fixing the (usually very small number of) include
directives with the wrong case can resolve a huge fraction of a sweep's
failures in one edit (762+155 out of 1395 total failures here, down to
72, from fixing just 3 files). Cross-check the whole tree isn't also
missing the reverse case or has genuine duplicate-cased files
(`find . -iname '*.h'` grouped case-insensitively) before assuming a
single fix location.

### 15h. `chinesed.lpc`-style GBK byte-range checks are silently wrong now, everywhere, and specifically break registration — the most important systemic bug in this whole project

**This affects every lib converted so far and every lib still to come.**
Check for it proactively on every new lib, the same way §4/§8f are
already checked proactively.

**The root cause.** On this driver, indexing a string (`str[i]`) returns
the character's Unicode **codepoint** (e.g. `0x4e2d` for 中), and
`strlen()` counts **characters**, not bytes (confirmed by reading the
driver source: `u8_egc_index_as_single_codepoint()` in `src/base/
internal/strutils.cc`, `f_sizeof()`'s `EGCSmartIterator` in
`src/packages/core/efuns_main.cc`). Every one of these mudlibs was
written against a GBK-byte driver, where `str[i]` returned a raw byte
(0-255) and `strlen()` counted bytes (2 per Chinese character). Every
piece of code that inspected string bytes to detect/validate Chinese
text is now silently checking the wrong thing:

- `str[0] > 160 && str[0] < 255` (a GBK lead-byte range check) is now
  comparing a full codepoint like `19968` (0x4E00) against `160-255` —
  **always false** for real Chinese text. `is_chinese()` never matches
  Chinese text anymore; it doesn't error, it just silently always
  returns wrong.
- `strlen(str) < 2` used to mean "reject if not even one full 2-byte GBK
  character exists" (i.e. reject empty/corrupt input) — with UTF-8 char
  counts, this now **rejects every genuine single-character name**
  ("云" alone, `strlen == 1`), which is completely valid input.
- Sliding-window / substring logic indexed by *byte* offset
  (`name[i..i+3]` = "the next 2 GBK characters", `i%2==0` to land on
  each character's lead byte) is walking the wrong number of *characters*
  now — half the string goes unchecked, or the windows are simply the
  wrong size.
- A `PATH(name)` sharding macro using `name[0..1]` ("first GBK
  character") now takes the first **two characters**, not one — silently
  changes the on-disk storage/lookup key shape.

**Why this is the most impactful bug found in this whole project**:
every one of these symptoms shows up **specifically during character
registration** — is_chinese, name-length bounds, and the similar-name
sliding-window check are almost universally used to validate the
surname/given-name a new player picks. Before this fix, on every
affected lib, registration was reachable but **silently un-completable
with any real Chinese name** — every valid Chinese name got rejected
with "请您用「中文」取名字" (please use Chinese for your name) or "至少
要有两个汉字" (needs at least 2 characters) or similar, even though the
player *did* enter Chinese characters. This was never caught by earlier
passes on any of these ~20 libs because testing stopped at "reaches the
name-entry prompt", never actually typing a Chinese name and confirming
acceptance through to the next step (password setup). **"Boots and
reaches a prompt" is not the same as "the feature actually works" — for
any registration/name-entry flow, always send a real UTF-8 Chinese
string through it and confirm you land on the NEXT prompt, not just that
the current one appears.**

**The fix pattern** (mechanical, once you know what to look for):

1. **`is_chinese`/`is_chinese2`/similar in the lib's `chinese.lpc`
   simul_efun fragment** (`adm/simul_efun/chinese.lpc`, `adm/kernel/
   simul_efun/chinese.lpc`, `secure/sefun/chinese.lpc`, etc. — this file
   exists in nearly every lib in this collection). Replace the GBK
   byte-range comparison with a CJK Unicode codepoint range check
   (`str[i] >= 0x4e00 && str[i] <= 0x9fff` covers the CJK Unified
   Ideographs block, which is what these mudlibs' character names use).
   Do NOT touch `is_english`-style checks (`a >= 'a' && a <= 'z'`) — pure
   ASCII-range comparisons are unaffected by UTF-8 vs GBK, since ASCII
   codepoints are identical either way.
2. **Any `strlen(x) < N` / `> N` bound calibrated against "N bytes = N/2
   Chinese characters"** — halve N. The message text (e.g. "必须是 2 到
   5 个中文字", "2 to 5 Chinese characters") almost always already states
   the CORRECT intended character count — halving the numeric bound
   makes the code match what the message already promises, it's not a
   guess. Watch for this recurring in more than one place per lib: a
   simple bound in `check_legal_name`'s own signature/body, AND a
   *separate* combined-length check where the caller concatenates
   surname + given name (`if (strlen(fname) < 4) ...`) before validating
   the whole name — found this second site by actually testing
   registration through to completion, not from a text search.
3. **`i%2==0 && !is_chinese(name[i..<N])`-style loop gates** — the
   `i%2==0` was landing on alternating BYTE offsets to catch each GBK
   character's lead byte; with UTF-8 every index is already one
   character, so drop the `i%2==0 &&` entirely and check every position.
4. **Byte-shift "auto-correct" hacks** like `name[j]+=128;` (seen in one
   lib, presumably a GBK/BIG5 byte-fixup) have **no valid meaning against
   Unicode codepoints** — adding 128 to a codepoint corrupts the
   character. Don't try to preserve this kind of hack; replace it with a
   straightforward reject-if-not-Chinese check, matching what every
   sibling lib's equivalent function already does.
5. **Sliding-window substring checks indexed by byte offset** (`name[i..
   i+3]` for a 2-char window, guarded by `strlen(name) < 4`) — convert
   byte-window-width N to character-window-width N/2 throughout
   (`name[i..i+1]`, guard `< 2`), and the loop bound `i <= l - 4` becomes
   `i <= l - 2`.
6. **A `PATH(name)`-style sharding macro using `name[0..1]`** ("first GBK
   char") — change to `name[0..0]` (first character). Low risk either
   way (it's just a storage bucket key, self-consistent as long as it's
   used the same way everywhere), but correctness matters if anything
   else ever assumes the bucket key really is "the first character".

**Verification approach that actually caught all of this**: write a tiny
throwaway LPC file, `#include`/call the fixed functions directly inside
`create()`, and dump results with `efun::write("label=" + fn(args) +
"\n");` piped through `lpcc --batch` (this reliably reaches stdout in
that context — `write_file()` to a scratch path often does NOT, gated by
`valid_write`/whatever security daemon hasn't loaded yet in a bare
single-file `lpcc` run). Confirmed `is_chinese("测试")==1`,
`is_chinese("test")==0`, `is_english("test")==1`,
`is_english("测试")==0` this way in seconds, across every fixed variant.
Then — critically — follow up with a REAL interactive registration test
via `mudclient.py`, sending an actual Chinese surname + given name and
confirming the flow reaches the NEXT prompt (password setup), not just
that no crash occurred at the name prompt itself.

**Libs fixed so far** (as of this pass): `chinese.lpc`-family fix applied
in bxsj, bxsj1, chidi, dtsl, fengyun434, fluffos_xiyou2000, fy2, fy2005,
llmud_datangshuanglong, mhxy, nitan170911, nitan6, rzrmud,
shanhaizhanshen, unknownlib20150716, xiakexing2017, xingzhanyingxiong,
xkx2001, xlqy_new2007, xo, xo_final (21 files). `check_legal_name`
length-bound fix applied in the same set (20 files, one per lib except
`xo`, whose copy was already fully commented out / a no-op). The deeper
`named.lpc` (`PATH()` macro + sliding-window + combined-length-guard) fix
was needed and applied in the "nitan" family plus chidi/dtsl/
llmud_datangshuanglong (5 files) — **check every NEW lib for a
`named.lpc` with the same shape**, it's not universal but recurs often
enough to check for by name. `dtsl`'s and `llmud_datangshuanglong`'s
`named.lpc` also has a separate, PRE-EXISTING, unrelated compile failure
(`Cannot #include limit.h` — a genuinely missing header, nothing to do
with this fix) that predates this pass; not fixed here, noted for
whoever picks it up next.

**Apply this proactively on every remaining lib** before/alongside the
normal pipeline: grep for `is_chinese\|is_chinese2` definitions and
`check_legal_name`/`named.lpc`'s `PATH(` macro on sight, fix using the
patterns above, and — this is the part earlier passes skipped — actually
type a Chinese name through registration before marking a lib `done`.

### 15i. A no-leading-whitespace Chinese comment can eat the start of the *next* physical line, silently deleting a declaration

Found twice in `xo_final`: a `//`-style comment written directly against
the left margin, immediately followed (same line, no space) by the start
of the actual code on the line below it in the source's visual layout —
except it isn't actually "the line below", the comment and the code were
on the same physical line all along (`// <中文文字>int is_native_skill()`),
so `//` swallows the rest of that line, including the function's return
type and name, leaving a bare `{` on the next line with no matching
declaration. Compile error is something like "unexpected `{`" pointing at
the *following* line, which is misleading — the real defect is one line
above. Fix: split the comment onto its own line. Cheap to grep for
proactively: `grep -rn '^//.*[a-zA-Z_][a-zA-Z_0-9]*(' ` flags candidates,
but false-positive-heavy (Chinese text often contains stray parens); in
practice it's faster to just fix each compile error as it surfaces and
recognize the shape once you've seen it once.

### 15j. Anti-flood "one new registration per N minutes per IP" throttles will make a *repeat* interactive test look like a silent registration bug

Several of these mudlibs throttle `new` character registration per source
IP (e.g. `xo_final`'s `band.lpc`'s `IsTimeAllowed()`, a 180-second
in-memory `NewIps` mapping) to stop registration spam. Since
`mudclient.py` always connects from localhost, running a second
registration test shortly after a first one from the same driver process
trips this — and the rejection path (`logind.lpc`'s `die()`) has its
error-message `write()` commented out, so the connection just drops with
**zero output**, indistinguishable at first glance from an actual crash.
Symptom: a `new` → `<id>` sequence that worked moments ago now produces
nothing at all, no error in `debug.log` either. Before chasing this as a
bug, check: (a) did a prior test from the same IP already register
someone recently, (b) does the lib have an `IsTimeAllowed`/`NewIps`-shaped
throttle. Fix for testing purposes: the throttle mapping is normally
in-memory-only (not saved to disk) — killing and restarting the driver
process clears it instantly, cheaper than waiting out the real cooldown.
Do a full `new → id → confirm → Chinese name → password` sequence in ONE
continuous `mudclient.py` connection/session rather than several separate
connections, so the throttle never has a chance to trigger mid-test.

### 15k. Case-sensitive filename mismatches aren't limited to `#include`s (§15g) — plain DATA files hit the same Windows-origin bug, and it's much nastier at runtime

`shiji`'s `adm/daemons/logind.lpc` does `read_file("/adm/single/
MUDVISITOR")` (hardcoded uppercase), but the file that actually extracted
from the archive is `adm/single/mudvisitor` (lowercase) — same root cause
as §15g (authored/tested on Windows' case-insensitive filesystem, silently
resolves there, hard-fails on this Linux host), but a plain data file
instead of a source `#include`, so it doesn't show up as a compile error
at all. `read_file()` on a missing path returns `0` instead of a string,
and if that return value flows straight into something type-strict (here,
`sscanf(content, "%s %d", ...)`) it throws a *runtime* error instead —
and if that code runs during connection setup (here: `logon()` →
`howmany_visitor()`), it fails EVERY single new connection before any
prompt renders, which looks exactly like a dead/crashed server (empty
`mudclient.py` transcript) rather than a name-lookup bug. Fix: `cp` the
file to the exact-case path the code expects (leave the original
lowercase file in place too, in case anything else reads it by that
name). **Lesson**: when a fresh boot produces zero prompt output at all
on the very first connection attempt (not a specific input further into
the flow), suspect a case-sensitivity data-file miss before anything
else — check the debug log for a runtime `Bad argument`/`sscanf`-shaped
error rooted in `logon()`/`connect()`, and grep the suspect daemon for
hardcoded ALL-CAPS or mixed-case paths, then `find -iname` to see if the
real file on disk uses different casing.

### 15l. `master.lpc`'s `create()` destructing/reloading `SIMUL_EFUN_OB` as an old-MudOS bootstrap trick segfaults this driver

Found in `dongfanggushi2`: some MudOS-era `master.lpc`s have a `create()`
that looks like this —
```lpc
void create() {
    write("master: loaded successfully.\n");
    seteuid(getuid());
    if( ob = find_object(SIMUL_EFUN_OB) ) {
        efun::destruct(ob);
        call_other(SIMUL_EFUN_OB, "???");
    }
}
```
— an intentional force-reload of the simul_efun object, presumably to
work around some old-driver staleness issue. On this driver, calling
`efun::destruct()` on the simul_efun object from inside master's OWN
`create()` — i.e. during the driver's own very early bootstrap, before
`master_ob`/`simul_efun_ob` internal pointers are fully settled — is not
an LPC-catchable error at all: it **segfaults the entire driver
process**. The crash trace (visible only as a raw backward-cpp stack
dump in the log, nothing resembling a normal LPC error) is rooted in
`vm/internal/simulate.cc`'s `destruct_object()` dereferencing
`master_ob->obname` on a not-yet-initialized pointer. Symptom: the driver
just dies with "Segmentation fault" moments after starting, no
`Accepting telnet connections` line, `catch()` doesn't help because
there's nothing to catch — it's a process-level crash, not a thrown LPC
error. Fix: the driver already loads simul_efun fresh before master's
`create()` ever runs, so this destruct+reload dance serves no purpose on
this driver — just delete it (keep the `write()`/`seteuid()` lines,
they're harmless). **Check every new lib's `master.lpc create()` for a
`destruct()`/`efun::destruct()` call targeting `SIMUL_EFUN_OB` (or
`MASTER_OB`) proactively** — this is exactly the kind of thing that's
silent in a compile-only `lpcc --batch` check (no error, no warning) and
only shows up as a hard crash on the very first real driver boot.

### 15m. A daemon's unguarded `restore()` in `create()` can crash on stale/corrupted save data and masquerade as an intentional maintenance gate

Found in `zhonghua2`: `adm/daemons/versiond.lpc` (a version-sync/
replication daemon, relevant to any lib with a "release server" /
multi-station-sync concept) calls `restore()` directly inside its own
`create()`, with no `catch()`. The archive shipped with a stale/corrupted
save file (`data/versiond.o` — confirmed via byte-for-byte comparison
against the raw pre-conversion archive to be corrupted in the ORIGINAL
archive, not something the UTF-8 conversion introduced) that threw
`*restore_object(): Illegal mapping format`, aborting `create()` before
it reached the code that would otherwise set a "we're ready" flag (here,
`version_ok = 1`, gated behind a `RELEASE_SERVER() == "local"` check that
should have made it trivially true). Because another code path
(`logind.lpc`'s login gate) checks that flag on every connection, the
visible symptom was every non-wizard connection stuck behind a
maintenance-sounding message ("现在本站正在同步版本" — "currently
syncing version") that implied an intentional, deliberate gate to wait
out — when actually the daemon had simply crashed once at boot and never
initialized the flag at all. Fix: rename/move the stale save file out of
the way so `restore()` finds nothing and returns cleanly (LPC's
`restore_object()` on a missing file is not an error) instead of
crashing on the corrupt one; then `create()` proceeds normally. **Lesson
generalizes beyond this one daemon**: if a fresh boot's first-connection
banner shows ANY unexpected "syncing"/"please wait"/maintenance-sounding
message that doesn't correspond to anything in `config`, check
`debug.log` for a `restore_object()`/`Illegal mapping format` error near
a daemon whose name suggests version/sync/replication bookkeeping BEFORE
assuming it's a real gate to wait out or work around — it may just be a
crashed `create()` that never got to flip a readiness flag.

### 15n. A custom `securityd.lpc`'s `valid_read` ACL, correct for real data reads, can block the driver's own compile-time source/`#include` loading — crashing every never-preloaded object's FIRST lazy compile mid-connection

Found on `shujian2008`, and likely to recur on any lib with a genuinely
custom (not `find_object`-only) security daemon: a real `exclude_read`
ACL table, keyed by directory and caller "status" (`(player)`,
`(wizard)`, etc.), correctly denies an ordinary player from reading
`/adm` or `/cmds` — that's the intended security boundary. The problem:
the DRIVER routes its OWN compile-time file access through this exact
same `valid_read` master apply, with distinct `func` values —
`"load_object"`/`"recompile_object"` when lazily compiling an object for
the first time (any ordinary `call_other`/`new()` on a never-touched
file), and `"include"` (a SEPARATE case) when resolving a `#include`
during that compile — and a fresh, not-yet-authenticated connection's
`this_player()` defaults to `(player)` status, which most `exclude_read`
tables deny for `/adm`/`/cmds`. Net effect: the FIRST TIME any
never-preloaded `/adm` or `/cmds` object gets touched by the
registration flow (in practice: whatever daemon/cmd the flow happens to
call first that isn't in `adm/etc/preload` — `BAN_D`, `UPTIME_CMD`,
`mudlist`, `sited`, one at a time as each was reached on this lib), the
compile crashes with `"Read access denied"` instead of just succeeding —
a completely different failure mode than an actual permission bug, and
one that looks like it's blocking a NEW thing every time you fix the
last one, because it is: each never-before-touched dependency hits the
same wall independently. Symptom in `debug.log`: `执行时段错误：*Read
access denied.` rooted at the CALLING line (e.g. `BAN_D->is_banned(...)`),
not inside the callee. **Fix**: add an explicit early-allow to the
custom `valid_read`'s `switch(func)` (the same pattern most of these
daemons already use for `"file_size"`/`"stat"`):
```lpc
switch (func) {
    case "file_size":
    case "stat":
        return 1;
    case "load_object":
    case "recompile_object":
    case "include":
        return 1;   // compiling/including code is never a sensitive data read
}
```
This is far more robust than patching the preload list one discovered
dependency at a time (which doesn't scale — there's no way to know in
advance every object the registration flow will eventually lazily touch).
**Check any lib with a genuinely custom `securityd`/`TRUST_D`-style
`valid_read`** (as opposed to the simpler `find_object(SECURITY_D)`-only
master.lpc pattern seen in `shiji`/`zhonghua2`) for this gap proactively,
before the first boot attempt.

### 15o. `master.lpc` missing `get_include_path()` breaks `#include`s specifically for compiles triggered mid-connection (not preload, not a bare `lpcc` check)

A distinct but related gotcha, easy to mistake for §15n's symptom since
both surface as a broken compile during the SAME registration-flow
dependency chain. Per the driver source
(`compiler/internal/lexer_utils.cc`'s `init_include_path()`): when there
is no VM context (preload-time compiles, a bare `echo path | lpcc
--batch` check), the driver just uses the config file's raw `include
directories` list directly. When there IS a VM context — i.e. a REAL
compile triggered live, mid-connection, by an ordinary `call_other`/
`new()` from inside an `input_to` callback — the driver instead calls
`master->get_include_path()` to build the search path, and if that apply
isn't defined at all, no path gets resolved (not even the config
default). Symptom: `Cannot #include globals.h` (or any other header) —
note this is a COMPILE error, distinguishable from §15n's RUNTIME "Read
access denied" — for an object that compiles perfectly cleanly via a
bare `lpcc --batch` check or during preload, but fails specifically when
lazily triggered live mid-connection. Fix: add the same
`get_include_path()` shape already documented for the `es1_win`/`esI`
lineage (§8d):
```lpc
string *get_include_path(string file)
{
    string *parts = explode(file, "/");
    if (sizeof(parts) <= 1)
        return ({ "/", ":DEFAULT:" });
    return ({ "/" + implode(parts[0..<2], "/"), ":DEFAULT:" });
}
```
`":DEFAULT:"` tells the driver to also search the config's normal
include path. **Caveat**: on `shujian2008`, once §15n's fix let the
underlying `#include` read through, this specific symptom was gone
before it was re-tested in isolation — so treat §15n as the fix to try
FIRST on any lib with a custom `securityd`, and only add this one if
`Cannot #include <file>` errors persist for mid-connection compiles
specifically after that.

### 15p. Proactively exclude DNS/intermud/network daemons from `adm/etc/preload` on every lib — don't wait to discover a boot hang

Standing policy (per explicit user direction): before the first boot
attempt, grep `adm/etc/preload` for any DNS/intermud/mudlist daemon
(commonly `network/dns_master`, sometimes just `dns_master`) and remove
it. These daemons typically bootstrap a cross-mud database via `resolve()`
+ UDP `socket_create()`/`socket_bind()` against a hardcoded remote
server address (a "boot server") that doesn't exist / isn't reachable in
this sandboxed environment, and can cause the boot to hang or become
extremely slow (observed on `xianlvqingyuanzheda`: minutes of wall-clock
time with only single-digit seconds of accumulated CPU time — heavily
I/O-blocked, not computing). This is pure intermud/cross-mud-list
functionality, never needed for registration-flow testing — don't spend
time diagnosing exactly which call blocks or why; just exclude the
daemon from preload proactively, the same way §4/§15g/etc. are checked
for on sight. If a lib's boot is still unusually slow after removing the
obvious DNS daemon, don't chase it further either — trim `preload` down
to just the entries needed for registration (`securityd`/`band`/
`virtuald`/`logind`/`cmd_d`/`chinesed`/`convertd`-shaped daemons) and
document in that lib's `NOTES.md` which daemons were excluded and why,
rather than open-ended bisection across ~20 preload entries for one of
~100 archives.

### 15q. A hidden pre-id prompt can be a literal client-protocol-version gate, not a BIG5/student-age question — always read the actual callback, don't trust the prompt text

Found on `xiyangzaixian3` (archive #48), extending the "hidden pre-id
prompt" family already documented (BIG5/GB font questions, "are you a
student" age-gates): the very first prompt reads
"请输入您的英文名字:" ("please enter your English name") — indistinguishable
from a normal id prompt by its text alone — but the actual `input_to`
callback bound to it (`get_id`) checks the input against a **hardcoded
literal client-version string** (here, `"2060"`, a Tomud/笑傲江湖-client
handshake code), rejecting anything else with "你的客户端非Tomud或者非
笑傲江湖WWW客户端" and disconnecting. Only after receiving that exact
literal does it advance to the REAL id-collecting callback
(`get_id1`/similar). Extra trap: a failed real-id check often loops back
to the FIRST callback (the version gate), not the second — so the gate
must be re-satisfied on every retry, not just once at the start of the
session. Symptom: sending what looks like a perfectly valid English id
first produces a confusing "wrong client" rejection that has nothing to
do with the id's own validity. **Lesson**: never infer a registration
flow's shape from the prompt TEXT alone — always read the actual
`input_to` callback chain (`logon()`/`get_id`/`get_id1`/`confirm_id`/
`get_name`, whatever the lib's own names are) before scripting a test,
and if the very first real input gets rejected in a way that doesn't
match the visible prompt's apparent meaning, suspect a hidden gate
checking for a specific literal (client version, magic string) rather
than assuming the id-validation logic itself is broken.

### 15r. A `check_config.lpc`-shaped driver-version self-check, `inherit`ed straight into `simul_efun.lpc`/`master.lpc`, can fatally `error()` on obsolete MudOS-era `#ifdef` assumptions that don't hold on this FluffOS build

Found on `tianxia` (archive #50): `adm/obj/check_config.lpc`, pulled in
via `private inherit __DIR__ "check_config";` directly inside
`simul_efun.lpc`. Its `create()` walks a checklist of `#ifdef`/`#ifndef`
driver-flag assumptions from the original MudOS-era target and calls a
bare, unconditional `error()` on any mismatch — fatal here specifically
*because* it runs during simul_efun's own construction, with no `catch()`
anywhere in the chain, so one failed check takes down the entire
simul_efun object (same blast radius as §15's core `tail()`-in-
simul_efun.lpc crash). Two checks failed on this FluffOS build:
- `#ifdef __PRIVS__` — the original assumption was that `__PRIVS__` and
  `PACKAGE_UIDS` were mutually exclusive driver configurations; this
  driver defines **both**, breaking that assumption even though privileges
  actually work fine.
- `#ifndef __AUTO_TRUST_BACKBONE__` — the driver doesn't define this
  macro at all, but `master.lpc`'s own `valid_override()` already handles
  backbone trust explicitly, so the check's underlying concern is already
  satisfied by a different mechanism the self-check doesn't know about.

Fix: don't delete the whole file (it may catch a real future
misconfiguration) — disable just the specific failing checks, e.g. wrap
each in an always-false `#ifdef DISABLED_LEGACY_..._CHECK` guard, leaving
every other check intact and active. **Lesson**: any lib with a
`check_config`/`checkconfig`/`verify_driver`-shaped file inherited
directly into `master.lpc` or `simul_efun.lpc` is worth grepping for bare
`error()` calls gated on `#ifdef`/`#ifndef` BEFORE the first boot attempt
— on this driver such a file crashes construction with a config-sounding
message that can misdirect debugging toward "which package is missing"
when the real issue is a stale mutual-exclusivity assumption from a
different, older driver target.

### 15s. A shared 2-arg `tell_room()`/`message()`-family simul_efun wrapper can pass a raw `int 0` into this driver's `message()` efun, which rejects it — breaks silently on the FIRST preloaded room's heartbeat, not at compile time

Found on `yueyingqiyuan` (archive #54): `adm/simul_efun/message.lpc`'s
`tell_room()` was written to accept an optional "exclude" argument, and
when called in its common 2-arg form (~578 call sites across the lib)
passed a bare `int 0` through to the real `message()` efun as the 4th
("exclude") argument. This driver's `message()` requires that argument to
be an object, an array, or absent/`0` handled internally — but the way
this particular wrapper constructed the call, the literal `0` reached
`message()` in a form it rejects (`Bad argument 4 to message()`), and
since `tell_room()` is one of the most commonly called simul_efuns (any
room's `heartbeat()`/`init()`/emote broadcasting), the very first
preloaded room to fire its heartbeat surfaced it. This is a compile-clean,
lpcc-clean bug — it only manifests at runtime, and only once some room
actually calls the wrapper. Fix once at the shared root (e.g. `exclude ||
({})` before delegating to the real efun) rather than touching any of the
578 call sites. **Lesson**: when a preloaded room crashes on its own
heartbeat with an efun-argument-type error, suspect a shared simul_efun
wrapper's argument-passing shape before the room's own code — the room is
usually just the first caller to exercise a latent bug in a widely-used
helper.

### 15t. Three related `#include`-resolution failures, all silent at compile time until something actually reaches the affected code path: absolute paths in angle brackets, `..`-relative paths, and `inherit` textually preceding a header's globals

All three found on `xinkuangxiangkongjian2` (archive #53), a genuine ES II
lineage lib:

1. **`#include <ABSOLUTE/PATH/header.h>`** (359 files) — angle-bracket
   syntax is meant for the driver's configured include-path search, not
   an already-absolute path; this driver's `inc_open()` never special-
   cases an absolute name inside `<...>` and simply fails to resolve it.
   Since this can affect an object that's only reached lazily (e.g. the
   actual starting room), the failure doesn't show up at preload/boot
   time at all — on this lib it silently sent every newly created
   character into `VOID_OB` instead of the real start room, which then
   spammed the log with an unrelated-looking heartbeat error from a
   different daemon (`cbipd.lpc`) trying to operate on a void object.
   **If a lib's registration flow completes but new characters seem to
   land nowhere sensible (or a heartbeat/day-night daemon spams
   unrelated-looking errors), check whether the actual start-room file
   itself compiles — an angle-bracket absolute-path include is a good
   first guess.** Fix: convert to quoted form (`"ABSOLUTE/PATH/header.h"`)
   — the quoted resolver's `merge()` step already handles absolute paths
   correctly; add `master::get_include_path()` if not already present so
   relative quoted resolution also works from the right directory.
2. **`#include "../parent/header.h"`** — this driver disallows `..` in
   `#include` paths entirely (a security boundary, not a bug to work
   around cleverly). Fix by pointing directly at the real absolute quoted
   path once you've located where the header actually lives — don't try
   to preserve the relative form.
3. **`inherit` appearing textually *after* a `#include`d header (or a
   bare global variable) in the same file** — "Illegal to inherit after
   defining global variables" is fatal at compile time here even though
   many older LPC codebases tolerated it. This shows up in file clusters
   sharing one problematic header (fix the shared header's field order,
   or reorder each file's own `inherit`/`#include`/global-declaration
   sequence) — mechanical but easy to fumble with a blind sed pass (one
   agent's fix attempt this session accidentally deleted the `inherit`
   line itself from all affected files on a bad regex; always diff a
   sed-based bulk fix against a sample before trusting it across dozens
   of files).

### 15u. A dormant "phone-home license check" in `securityd.lpc` (or similar) can delete the whole mudlib and shut down the server if ever triggered — grep for it and neutralize even if unreachable

Found on `moniHuafu` (archive #57): a function named something like
`checking_status()` in `securityd.lpc`, clearly a circa-2000 anti-piracy
mechanism from the original author, whose body — if ever called — deletes
every file under the mudlib root and shuts down the driver. Confirmed
unreachable in this specific lib (nothing in the tree calls it), so it
wasn't an active bug, but it's cheap, safe insurance to disable the
destructive body outright (rather than delete the function, in case
something non-obvious does call it and depends on the call succeeding
harmlessly) any time a grep for suspicious combinations of
`rm`/`unlink`/`shutdown`/`rmdir`-on-mudlib-root turns up something that
reads like a licensing/anti-piracy gate rather than legitimate admin
tooling. **Lesson**: when skimming `securityd.lpc`/`master.lpc` for the
usual valid_read/valid_write/valid_override applies, also scan for any
function whose body does mass deletion or `shutdown()` gated on some
opaque check — these libs came from an era of informal, sometimes
hostile, anti-redistribution tricks aimed at whoever hosted the game
next, and this project is exactly that "whoever hosts it next."

### 15v. A `LONELY_IMPROVED`-style always-on flag can gate a whole family of `efun::X()` calls to functions that were never real on any driver in this project — check for an existing pure-LPC fallback before reimplementing

Found independently on both `nitan_ceshi` (archive #60) and `nitan_san`
(archive #61), siblings in the NT/nitan/Lonely lineage: `include/
globals.h` unconditionally `#define`s a flag like `LONELY_IMPROVED`
(originally meant to mark "this driver has my custom patch," but always
compiled in here since nothing ever undefines it), gating several
`adm/simul_efun/*.lpc` functions (`sort_string`, `filter_ansi`,
`file_crypt`, `file_valid`, `file_lines`, `sort_msg`, ...) to call
`efun::X()` versions that never existed on any FluffOS build. Before
reimplementing anything, check whether the same file already has a
working pure-LPC `#else`/`#ifndef` fallback branch sitting right next to
the dead branch — flipping the guard (or converting to `#if 0`) is a free
fix reusing code the original author already wrote and tested.

**The one sub-case with no fallback at all was a hard compile-blocker**:
`count_add`/`count_mul`/`count_sub`/`count_div`/`count_lt`/`count_gt`/
`count_le`/`count_ge`/`count_eq` wrap a bespoke MudOS-fork arbitrary-
precision bignum efun (`count(n1, op, n2)`) used for currency/damage math
at ~230-1000+ call sites — no fallback existed, so `simul_efun.lpc` itself
failed to compile. Two independent fixes were tried across the two
sibling libs: `nitan_ceshi` restored ordinary 64-bit int arithmetic
routed through the lib's own `atoi()` (`intp(n) ? n : atoi(n)` — **not** a
bare `(int)` cast, which is a type-assertion on this driver, not a
string-to-int parse, and crashes at runtime the first time a call site
passes a numeric string); `nitan_san` instead wrote a small from-scratch
arbitrary-precision `adm/simul_efun/bignum.lpc` library. Either approach
compiles and passes the interactive registration/gameplay test; the
int-arithmetic route is simpler and was sufficient for values seen in
practice, but note it silently loses precision beyond 64-bit `int` range
if a lib's economy ever produces genuinely huge numbers — prefer it as
the default, faster fix, but watch for overflow-shaped bugs later if the
lib's own numbers turn out to need true bignum semantics.

### 15w. `log_error()`/`APPLY_LOG_ERROR` on this driver funnels every compile *warning*, not just real errors, to whatever the mudlib's own handler does with it — a mudlib written assuming only fatal errors reach that apply will spam every connected player with the scary default message on ordinary warnings

Found on `wuhanzhan` (archive #58): `master.lpc`'s `log_error()` (bound to
the driver's `APPLY_LOG_ERROR`) displayed its message to every non-wizard
player present, which the original author intended only for genuine
fatal compile errors — but this driver calls the same apply for soft
compile *warnings* too (e.g. `Illegal to declare nosave function`, a
`self`/harmless warning from §3's own `nosave` fix), so ordinary
warnings during any lazy compile were spamming every online player with
what looks like a serious crash message — 98 spurious messages in one
short test session. Diagnosed by first ruling out `error_handler()` (zero
hits via temporary instrumentation) and finding the actual spam volume
matched `log_error()`'s own `/log/log` write instead. Fix: gate the
player-facing broadcast on the message NOT containing the substring
`"warning:"` (still write everything to the log file, just don't
broadcast warnings to players). **Lesson**: if a lib's registration flow
works but ordinary connected play is noisy with alarming-looking system
messages that don't correspond to an actual crash, check whether
`log_error()`/`error_handler()` conflates warnings and real errors —
don't assume every message reaching that apply is fatal just because the
original mudlib author assumed that on their own driver.

Related, same discovery: this driver's `error_handler()` apply is
declared `void` — a mudlib whose old comment says "falls through to
debug.log automatically" may be relying on a return-value path that
doesn't exist here. Adding an explicit `efun::write_file("/log/
RUNTIME_ERRORS", trace)` inside the handler is a cheap, permanent
insurance so runtime errors are never silently lost regardless of what
the handler's own logic does afterward.

### 15x. A hardcoded `MUD_PORT` mismatch silently rejects every connection at the TCP dispatch layer, with a completely clean boot log — always cross-check the mudlib's own compiled-in port constant against `config.fluffos`'s assigned port

Found on `huoying` (archive #65): `master.lpc`'s `connect(int port)` apply
dispatches on a hardcoded `MUD_PORT` constant from `globals.h` (here,
`8000` — the original author's own port), completely independent of
whatever port the driver was actually launched on via `config.fluffos`.
Since this project assigns each converted lib its own unique port
(40001, 40002, ...) to allow running several concurrently, every one of
these libs' `MUD_PORT`-style constants is near-certain to mismatch the
assigned port unless previously caught. When it mismatches, the driver
boots with **zero errors anywhere** (preload, compile, everything
succeeds) but every incoming connection is rejected at the mudlib's own
`connect()` dispatch (`error in connect()` or similar), which can look
identical to a driver-level "nothing's listening"/networking problem
rather than a one-line mudlib config bug. **Check for this proactively**:
grep for `MUD_PORT`/`PORTNO`/similar hardcoded port constants in
`globals.h`/`config.h`-equivalent files during the standard fix pass, and
update it to match the lib's assigned port — same category of "config
value baked into mudlib source, not just the driver's own
`config.fluffos`" as the daemon-address/hostname constants worth a
similar grep.

### 15y. A single config/data file can be mixed multiple Chinese encodings (GBK for most content, BIG5 for a few lines) — a straight GB18030 decode won't error, it will silently produce valid-but-wrong mojibake that `convert_lib.sh`'s lossy-conversion detector cannot catch

Found on `huoying` (archive #65): `config.cfg`'s header comments and two
default system messages were authored in BIG5 while the rest of the file
(and the rest of the lib) is ordinary GBK/GB2312. Because BIG5 and GBK
are both variable-width multi-byte encodings covering overlapping byte
ranges, decoding BIG5 bytes as GB18030 does not throw an invalid-sequence
error — it produces a different but still well-formed sequence of valid
Unicode characters (wrong text, not an error), so `convert_lib.sh`'s
lossy-conversion log (which watches for iconv's `-c` drop-invalid-bytes
recovery firing) never flags it. **This can only be caught by actually
reading the converted output** for text that looks like nonsense Chinese
(not the usual mangled-looking replacement-character garbage of a true
decode failure, but grammatically odd/wrong-topic real Chinese text) —
worth a quick visual skim of any file with prominent user-facing strings
(banners, config comments, default messages) even after a "successful"
lossless conversion, especially on any lib where BIG5 is plausible at all
(Traditional-region distribution, mixed-region community forks). Fix by
manually re-decoding just the affected lines/file with the correct BIG5
codec and patching them back in, rather than assuming a single encoding
choice is correct for 100% of a lib's text.

### 15z. §3's `\bstatic\b`→`nosave` blanket sed can collide with a lib's own `#define nosave static`/`#define protected static` compatibility macro, guarded by a flag this driver never predefines

Found on `yuxuechongsheng` (archive #62): some libs carry a small
compatibility shim — `#ifndef __SENSIBLE_MODIFIERS__` / `#define nosave
static` / `#define protected static` / `#endif` — written for an older
driver that didn't understand `nosave`/`protected` as real keywords,
translating them down to the `static` spelling that driver *did*
understand. `__SENSIBLE_MODIFIERS__` is never defined by this FluffOS
build, so the shim's branch is always active — meaning after §3's own
blanket keyword sed runs, this `#define` line itself gets rewritten too
(since it also contains the literal word `static`), producing `#define
nosave nosave` (a harmless self-map) but ALSO `#define protected nosave`
(since `protected` on the left survives untouched but the *value* on the
right was rewritten) — silently breaking `protected`'s distinct semantics
by aliasing it to `nosave`. **Fix**: after running §3's sed, specifically
grep for `#define\s+(nosave|protected)\s` in every `.h` file and confirm
each maps to itself (or delete/neutralize the compatibility shim
entirely, since both `nosave` and `protected` are independently
real, correctly-behaving keywords on this driver and need no translation
at all). This is a second, distinct collision case from §3's own
already-documented `"static/CRASHES"`-in-string-literal counterexample —
check both when auditing a lib's own copy of the `static`→`nosave` sed's
blast radius.

### 15aa. A same-named wrapper function calling the bare identifier of the real efun it wraps, *before* its own definition appears in the file, can get silently bound straight to the real efun — bypassing the wrapper's own guard entirely, with no "undefined function" error to flag it

Found on `yanhuangwuhun` (archive #66), a variant of the §15s
`message()`-wrapper family: `adm/simul_efun/message.lpc` defines its own
`message(...)` override (to patch the exclude-argument bug from §15s),
but several functions earlier in the *same file* (`tell_room()`,
`tell_object()`, `shout()`, `write()`, `say()`) call the bare identifier
`message(...)` **before** the file's own `message()` definition appears
textually. Because `message` is also a real driver efun name, the
compiler doesn't raise "undefined function" the way it would for a
made-up name (§8b's usual signal) — it silently resolves the earlier
calls straight to `efun::message()`, completely bypassing the local
override and its exclude-argument fix, for every call site that happens
to come first in file order. This crashed 9 preload daemons on boot plus
one live gameplay call site even after the wrapper itself had been
"fixed." **Fix**: add a `varargs` forward declaration of the wrapper's
own signature at the top of the file, before any caller — same rule as
§8b's ordinary "define before use" guidance, but the trap here is
specifically that a same-named-as-a-real-efun wrapper gives you NO
compile-time error to notice the ordering problem exists; a
differently-named helper would have failed loudly and obviously instead.
**Lesson**: whenever fixing a wrapper around an efun that shares the
efun's own name (not just `message()` — any `write()`/`tell_room()`
-style override), grep every call site in the same file and confirm the
wrapper's own definition (or a forward declaration of it) appears above
all of them, not just check that the wrapper's body itself looks correct.

### 15ab. Two more findings from `haiyang2` (archive #63): a player-body `receive_message()` missing the standard `!stringp(str)` guard kills every fresh connection at the first banner; and a DNS/intermud daemon's function calls can be inlined elsewhere even when the daemon itself is correctly excluded from preload

1. **Missing `!stringp(str)` guard on one code path, present everywhere
   else**: this driver's idiom of `write(read_file(path))` (or similar)
   relies on the receiving `receive_message()` silently no-op'ing when
   handed `0` instead of a string — every player-body-adjacent copy of
   `receive_message()` in this lib (`feature/message.lpc`,
   `feature/message1.lpc`) already has this guard, but `clone/user/
   login.lpc`'s own copy (the pre-authentication connection object,
   reached before the real player body even exists) was missing it.
   Since routine startup code (`uptime.lpc` reading a possibly-absent
   `LASTCRASH` file) calls `write(0)` unconditionally on ordinary boots,
   this crashed `receive()` on **every single fresh connection**, right
   at the very first banner line, before any prompt appeared — the
   `login.lpc`-stage object is easy to overlook since the "real" player
   body's copy is correct and might be the only one checked. **Lesson**:
   when auditing a `receive_message()`-family guard (per §15e's general
   "guard every unchecked chained call" principle), explicitly check the
   pre-login/pre-authentication connection object's own copy too, not
   just the post-registration player body — they're often separate files
   with independently-drifted implementations.
2. **§15p can still bite even when the daemon itself is properly
   excluded**: `DNS_MASTER`/`dns_master.lpc` was correctly absent from
   `adm/etc/preload` in this lib from the start, but `logind.lpc`'s
   `gb_big5()` (an intermud mud-list display shown during login) and a
   broadly-used `Mud_name()` macro both called into the DNS/intermud
   subsystem *inline*, independent of preload. §15p's "just exclude it
   from preload" fix is necessary but not always sufficient — also grep
   for direct calls into the DNS/intermud daemon's API from ordinary
   login/display code, not only from the preload list, and either
   disable the calling code path or reroute it to a local constant
   (here: `Mud_name()` rewritten to return `INTERMUD_MUD_NAME` directly).

### 15ac. Bare `SAVE_EXTENSION` (no leading/trailing underscores) instead of this driver's real autogenerated `__SAVE_EXTENSION__` constant

Found on `kuangxiangkongjian` (archive #69): 11 files referenced a plain
`SAVE_EXTENSION` macro/identifier that was never actually defined
anywhere in the lib — this driver autogenerates the real constant as
`__SAVE_EXTENSION__` in `options.autogen.h` (confirm via `grep
SAVE_EXTENSION ~/src/fluffos/build-debug/include/options.autogen.h` or
equivalent). The bare-name spelling is presumably a leftover from an
older driver/mudlib convention. Fix: replace every `SAVE_EXTENSION`
reference with `__SAVE_EXTENSION__`. Cheap to grep for on any lib as part
of the standard fix pass, same spirit as checking for `F_DBASE`/
`F_UNIQUE`-style macro gaps.

### 15ad. A non-fatal `versiond.lpc`/`socket_bind()` config-ID-mismatch error can appear harmlessly in `debug.log` on an otherwise clean boot — don't chase it if `version_ok` (or equivalent) is already set synchronously before the broken call fires

Found on `yanhuangyingxiongshi` (archive #67): a `versiond.lpc`-family
daemon's `create()` calls `socket_bind()` using a numeric config-ID that
doesn't match this driver's `runtime_config.h` numbering (an old-MudOS
convention drift, similar in spirit to §15r's `check_config.lpc` but
without the fatal `error()` — this one just logs a socket error and
moves on). Confirmed harmless by reading the surrounding code: the
daemon's actual purpose (setting a `version_ok`/ready flag consumed by
other code) already completes synchronously earlier in `create()`,
before the broken `socket_bind()` call ever executes — so the daemon's
real job is done regardless of whether the socket call itself succeeds.
**Lesson**: one stray non-fatal error line in an otherwise clean boot log
doesn't automatically need a fix — confirm what the surrounding code was
actually trying to accomplish and whether it already succeeded before the
line that errors, the same "read the actual code, don't just react to the
log line" discipline used throughout this catalog.

### 15ae. A `private nomask` command-hook function silently stops receiving `add_action()` dispatch once inherited into another object — breaks EVERY post-login command with zero visible error, and is easy to miss if testing stops at the login/registration prompt

Found on `xuanjianlu` (archive #70), and — once flagged — confirmed to
also affect the already-shipped `beimeixiakexing2001` (#45), which never
caught it because its own registration testing stopped at "reaches the
password prompt" rather than continuing into real post-login play. The
shape: `feature/command.lpc` declares its central command-dispatch
function (here, `command_hook(string arg)`) as `private nomask`, then
`inherit`s that feature into the player body class and registers it via
`add_action("command_hook", "", 1)`. On the *original* driver this
targeted, `private` scoped the function to same-file callers only but
still let the driver's own `add_action` dispatch call it externally. This
driver, however, treats a `private` function as `DECL_HIDDEN` for
dispatch purposes too, so `add_action`'s external call into the inherited
function silently fails — no error, no crash, just no command ever
executes. **This is uniquely dangerous because the symptom appears
nowhere near the cause**: registration completes fine (it's driven by
`input_to`/direct method calls, not `add_action`), the player lands in
the game world, and then every single typed command — including as basic
as `look` — does nothing at all, with zero output and zero `debug.log`
entry, indistinguishable from a hung connection or a client-side issue.
Fix: drop `private` (keep `nomask` if the lib relies on it elsewhere) so
the function is a plain visible method reachable from `add_action`'s
external dispatch, matching how sibling libs in the same lineage that
*don't* exhibit the bug already have it written. **Lesson, now standing
policy**: never mark a lib "done" without testing at least one ordinary
post-login command (`look` is enough) after registration completes —
reaching the game world is not the same as being able to play in it, and
this exact failure mode produces literally no signal in any log.

### 15af. `log_error()`/`APPLY_LOG_ERROR` calling `wizardp(this_player(1))` (or any other check that lazily `load_object()`s the security daemon) during a compile-time WARNING can crash the very first preloaded daemon, before securityd itself has ever loaded

Found on `shenzhou` (archive #72): `master.lpc`'s `log_error()` (already
known from §15w to receive both warnings and real errors) called
`wizardp(this_player(1))` unconditionally to decide whether to echo the
message — but `wizardp()` on a not-yet-loaded uid needs to consult the
security daemon, triggering a lazy `load_object(SECURITY_D)` mid-compile.
Since `log_error()` can fire from the very FIRST file the driver ever
compiles during preload (here: the first-listed daemon, before securityd
itself has been preloaded), this crashed every single boot attempt at
the earliest possible point — a different, earlier-firing variant of §4's
"lazy security-daemon load recurses" family, but through a compile-
warning path rather than a `valid_read`/`valid_write` apply. **Same file,
second bug**: the case-sensitivity of the warning-detection substring
itself was wrong (checking for `"Warning:"` when the driver's actual
compile diagnostic text is lowercase `"warning:"`), which would have
made §15w's own fix silently do nothing once the crash above was
resolved. **Lesson**: any code in `log_error()`/`error_handler()` that
calls into player/uid-checking functions (`wizardp`, `query_ip_name`, ACL
lookups) should be treated with the same suspicion as §4's lazy-load
family — it can fire before the daemon's own preload has completed, not
just from ordinary runtime traffic. Also worth double-checking every
substring/case comparison in these handlers against the driver's actual
diagnostic text, not the text you'd expect from the original MudOS-era
convention.

### 15ag. This driver build has `__OLD_ED__`, so `ed_start()`/`ed_cmd()`/`query_ed_mode()` don't exist — a lib whose player body or command-prompt logic inherits an editor feature using those calls can crash `make_body()` mid-registration with zero visible error

Found on `xiaoaojianghu2` (archive #74), the highest-impact fix in that
pass: `feature/editor.lpc` (inherited into the player body class) and
`message.lpc`'s `write_prompt()` both called `ed_start`/`ed_cmd`/
`query_ed_mode` — real applies/efuns on some driver targets, but this
build was compiled with `__OLD_ED__` defined instead, meaning the
in-game line editor uses the older, different `ed()` efun interface, and
none of those three names exist at all. Since `feature/editor.lpc` is
inherited directly into the player body class, the compile failure took
`make_body()` down with it — silently, right at the moment gender
selection completes, with no message anywhere (not even a debug.log
line, since this compiles fine as a *standalone* file — the failure only
surfaces when the whole inheritance chain is exercised by an actual
registration). Fixed by rewriting the editor-invoking call sites to use
the real `ed()` efun instead (confirmed via `~/src/fluffos/src/comm.cc`
that this driver bypasses the normal `process_input`/`write_prompt` path
entirely while an `ed()` session is active, which is why `write_prompt()`
needed its own fix too). **Lesson**: `grep -r "ed_start\|ed_cmd\|query_ed_mode"`
early on any lib, and cross-check against which editor mode this
project's driver build was actually compiled with, rather than assuming
editor-related code is dead/unreachable just because it never surfaced
in a boot log.

### 15ah. A missing save-data directory (e.g. `/log/nosave/`) can make an unguarded `write_file()`/`log_file()` call silently abort an entire in-progress multi-step flow, logging the failure ONLY to the mudlib's own internal error channel — not to `debug.log`, not to the player, nowhere a normal check would look

Found on `xiaoaojianghu2` (archive #74), described by the processing
agent as the hardest bug in that pass to diagnose: the raw archive
simply didn't ship a `/log/nosave/` directory, and some step of the
post-gender-selection registration chain wrote a routine log entry there
via an uncaught `write_file()`. On this driver, `write_file()` to a
directory that doesn't exist fails, and the surrounding code had no
`catch()` — but because the call sat inside a chain of `call_other()`s
already several frames deep in the registration flow, the failure never
reached the ordinary error-reporting path at all; it only appeared in
the mudlib's own separate `/log/runtime/secure` log (a custom, non-
standard log file this lib's own security layer maintains), completely
invisible to `debug.log` or anything the player saw. The registration
simply stopped silently right after gender selection with the connection
just sitting there. Fix: create the missing directory proactively as
part of the standard pre-boot checklist (`mkdir -p` every directory any
`log_file()`/`write_file()` call references, not just the ones obviously
tied to player-save paths), and wrap the specific call site in `catch()`
as defense in depth. **Lesson**: when a registration flow silently stalls
with literally no error anywhere in `debug.log`, don't stop looking after
checking the obvious channels — grep the whole lib for any custom
log-file path the mudlib itself might write failures to (`log_file(`/
`write_file(` calls with a hardcoded path other than the standard ones),
since a driver-level failure with no `catch()` can be swallowed by a
completely separate, easy-to-miss logging convention.

### 15ai. Excluding `dns_master` from preload (§15p) can surface a SECOND, independent problem: a "site verification" gate elsewhere in `logind.lpc` that assumes the daemon exists and calls `shutdown(1)` unconditionally on the very first connection

Found on `xiyouji2003` (archive #81): once `dns_master` was proactively
removed from preload per §15p's standing policy, the very next boot's
first connection attempt immediately disconnected everyone — traced to
a `logind.lpc` check (originally meant to verify the mud is registered
with an intermud directory before allowing play, a common circa-2000
anti-piracy/registration gate) that called `find_object(DNS_MASTER)` and
then called methods on the result unconditionally, without checking
whether `find_object` actually returned an object — since the daemon was
now never loaded, this returned `0`, and the resulting `0->method()`
call path led to the gate's failure branch, which calls `shutdown(1)`.
Fix: guard the check with an explicit `find_object(DNS_MASTER)` truthiness
test before proceeding, treating "daemon absent" as "skip the gate" rather
than "gate failed." **Lesson**: §15p's exclusion is not risk-free by
itself — after removing a DNS/intermud daemon from preload, boot the
driver AND actually attempt a real connection before considering the
exclusion complete, since some libs have OTHER code elsewhere that
assumes the daemon's presence and can fail in an even more disruptive
way (killing every connection) than the daemon's own hang would have.

### 15aj. A mandatory post-registration "choose your gift"/first-room object can be missing from the archive entirely — new characters get moved to a nonexistent destination and are left with no environment at all, silently crashing every subsequent command

Found on `xiyouji2003` (archive #81): `logind.lpc`'s registration
completion step unconditionally moves the new player object to a
hardcoded room (here, `/d/wiz/init`, a "select your starting gift" room)
— but that file simply doesn't exist anywhere in this archive (likely an
already-known gap even in the original, unconverted game, not something
our pipeline broke). Since `move_object`/`->move()` to a nonexistent
destination silently fails to actually relocate the player, the new
character ends up with **no environment object at all**, and every
subsequent command that assumes `environment(this_object())` is non-null
(which is nearly all of them — `look`, `score`, movement) crashes or does
nothing. This is symptomatically identical to §15ae's "post-login
commands silently do nothing" failure mode, but with a totally different
root cause (missing content, not a dispatch bug) — a second, now
recognized, class of "commands stop working right after registration"
bug. Fix: guard the move with `load_object()`/`find_object()` before
attempting it, falling back to whatever the lib's own normal
`START_ROOM` constant is (matching the same fallback pattern most libs
already use a few lines below for the *ordinary* returning-player case —
just extend it to also cover the fresh-registration gift-room path).
**Lesson**: when §15ae's checklist (test `look`/`score` after
registration) turns up a failure, don't assume it's automatically the
`private`-command-hook bug — check whether the player actually has a
valid environment first; a missing destination room produces the exact
same "commands do nothing" symptom.

### 15ak. A same-named extensionless "live" file sitting alongside a `.c` backup copy in the raw archive — the `.c`→`.lpc` rename can silently make the BACKUP authoritative instead of the file the original author was actually editing

Found on `zitengzhan` (archive #77), 35 such pairs: some editors/authors
kept a working extensionless copy of a critical file (e.g. `adm/obj/
master`, `adm/daemons/securityd`, `feature/message`) side-by-side with a
`.c`-suffixed backup of an earlier revision. On the *original* driver
target, config/macro paths that reference the file without an extension
(e.g. `master file : /adm/obj/master` in `config.fluffos`) resolved to
the literal extensionless filename if one existed — so the live,
currently-edited file was the one actually loaded, with the `.c` sibling
just inert backup content. This driver's resolution order for an
extensionless path is different — confirmed via `~/src/fluffos/src/
vm/internal/simulate.cc`, it tries `.lpc` then `.c`, never a literal
zero-extension match — so after the blanket rename turns the backup's
`.c` into `.lpc`, THAT becomes the first match, silently promoting the
stale backup over the live file the author actually intended, with no
error of any kind (both compile fine, they're just different content).
Found because two real bugs (a dead-code stray `return;` making
`log_error()` a permanent no-op, and an old force-load boot-spam trick)
were present in the master file that "shouldn't" have been there, and
turned out to live in a promoted-by-accident backup copy. **Direction is
not consistent within a single archive** — some `.c` siblings on
`zitengzhan` were actually the newer/better version — so every such pair
needs its own diff, not a blanket "trust the extensionless one" rule.
**Lesson**: `find work/ -name '*.lpc'` and cross-reference against
`find raw/ -type f -not -name '*.c' -not -name '*.h'` for same-directory,
same-basename collisions before trusting the converted tree; diff each
pair and pick whichever content is actually correct/current, not
whichever the rename happened to prioritize.

### 15al. `crypt(str, 0)` (an `int` salt, not a string) silently falls through to a fresh RANDOM hash every call on this driver instead of the deterministic old-style DES hash the original driver produced — can make a client-challenge/response login handshake mathematically unpassable by any client, with zero error anywhere

Found on `zhongjidiyu_zhijian` (archive #80): this lib wires in a mobile
"指间MUD" client protocol whose login flow requires the client to answer
a `crypt()`-based challenge — the mudlib computes `crypt(KEY, 0)` and
expects the connecting client to independently compute the same value
and echo it back. On the original driver target, `crypt(str, 0)` (or any
non-string salt) fell back to a default 2-character DES salt, producing
a **deterministic** hash for a given `KEY` — both sides could compute the
identical value. This driver's `crypt()`, when given a non-string salt,
instead generates a **fresh random** SHA-512 salt on every single call —
so the mudlib's own expected value changes every time it's computed, and
no client (real or scripted) can ever produce a matching response. This
silently blocks 100% of connections through that login path, with no
error anywhere (the crypt call itself succeeds, it just doesn't produce
what the mudlib's design assumes). Fix: pass an explicit string salt
(matching the original protocol's expected salt shape/prefix, e.g. `"zj"`
here) instead of `0`/an int, restoring deterministic output. Verify the
fix by writing a small Python script using the `crypt` module to compute
the expected response the same way a real client would, and confirming
it now matches across repeated calls. **Lesson**: any lib with a custom
client-handshake/challenge-response step built on `crypt()` needs its
salt argument checked specifically — a call that "worked" on the
original driver by relying on a fixed-format non-string salt can silently
turn into a per-call-random generator here, and this failure mode
produces literally no signal since the crypt call never errors.

### 15am. `file_size()` returning `-1` (path doesn't exist) can be mistaken for truthy "the file exists" by an unguarded `if (file_size(path))` check — a virtual-object compile daemon that gets this wrong recurses infinitely against any missing path

Found on `zhongjidiyu` (archive #78): `virtuald.lpc`'s check for whether
a requested virtual-object path has a real backing file used `if
(file_size(path))` — `file_size()` returns `-1` for a nonexistent path
and `-2` for a directory, both non-zero, so this check is true for
*every* path that doesn't actually exist, the opposite of the intended
guard. Combined with a fallback that re-triggers the same virtual-object
compile machinery on failure, this produced unbounded recursive compile
attempts against any missing path ever requested. Fix: use `file_size(path)
>= 0` (only a real, existing regular file has a non-negative size).
**Lesson**: `file_size()`'s `-1`/`-2` sentinel values are a classic
truthiness trap in any boolean-context check — grep for `file_size(`
used as a bare condition (not compared against `0`/`>=0`) as part of the
standard fix pass, the same way `strlen()` byte-vs-char bounds get
checked.

### 15an. A live/heartbeat prompt (e.g. a per-second updating clock in the command-line prompt) can defeat `mudclient.py`'s default idle-based send-pacing, making queued `--send` commands never actually get sent — looks exactly like §15ae's silent-command-dispatch failure and can cost significant misdirected diagnostic effort

Found on `zhongjidiyu` (archive #78): this lib's prompt updates every
second with a live clock/status line, which means the connection is
never truly "idle" by whatever heuristic `mudclient.py` uses to decide
when to send the next queued `--send` argument — the constant ~1-second
trickle of prompt updates keeps resetting the idle timer, so scripted
commands queue up but are never actually transmitted. Symptomatically
this is indistinguishable from §15ae's failure mode (the player appears
to be in the game world, but no post-login command ever seems to
produce output) and cost real diagnostic effort chasing `add_action`/
`process_input` before being correctly identified as a test-tooling
artifact, not a mudlib bug. **Fix**: pass a short `--idle` value (0.3-
0.5s) to `mudclient.py` on any lib whose banner/prompt shows a live-
updating clock or other heartbeat-driven status text. **Lesson**: before
concluding a lib has the §15ae command-hook bug because commands
"silently do nothing" in a scripted test, try the same commands with a
tighter `--idle` first — a live-clock prompt is a much more mundane
explanation than a driver-compat bug, and worth ruling out first.

### 15ao. A `switch` statement with only a `default:` case and no real `case` labels is a hard parse error on this driver, not a harmless no-op — can take down the whole file it's compiled into, including `master.lpc` itself

Found on `xixingzhanji` (archive #85): `master.lpc`'s `connect(int port)`
apply was written as `switch(port) { default: ... }` — no actual `case`
labels at all, just a catch-all default block, presumably meant as a
lazy way to write "run this code regardless of the port." This driver's
grammar requires at least one real `case` to accept a `switch` at all
("need case statements... not just default"), so this was a hard parse
error — and since it lived directly in `master.lpc`, it took down
master's entire compile, which is fatal at the earliest possible point
in boot. Fix: rewrite as a plain unconditional block (drop the `switch`
wrapper entirely, since there was no branching logic being expressed
anyway). **Lesson**: grep for `switch\s*\([^)]*\)\s*\{\s*default:` as a
quick proactive check — a `switch` with no real `case` is a distinctive,
easy-to-miss anti-pattern that reads as syntactically fine to a human
skim but isn't accepted by this driver's grammar.

---

## Per-archive gotchas index

*(One line per lib once processed, pointing at its `NOTES.md` for detail.
Kept here too so a `grep` across this single file surfaces everything.)*

---

## Duplicate archives (do not process twice)

Exact byte-duplicates found via `md5sum` (process the first, skip the
second — both listed for traceability):

| Keep | Skip (identical) |
|---|---|
| 风云III典藏版.rar | 风云III典藏版 (1).rar |
| 江湖风云.rar | 江湖风云 (1).rar |
| 海洋II 2010 正式无错完整版下载.rar | 海洋II 2010 正式无错完整版下载 (1).rar |
| 火影.rar | 火影 (1).rar |
| 狂想空间.rar | 狂想空间 (1).rar |
| 风云III修订版 .rar | 风云III修订版  (1).rar |
| 夕阳再现-疯狂江湖.rar | 夕阳再现-疯狂江湖(1).rar |
| 东方故事二.rar | 东方故事二 (1).rar |
| 金庸文字版.exe | 金庸文字版 (1).exe |
| 风云II (清华仿写版）.ZIP | 风云II (清华仿写版） (1).ZIP |

## Non-mudlib / needs-triage files at repo root

- `eval.c` — stray single C file, not part of any archive. Purpose unknown,
  investigate before assuming it's disposable.
- `金庸文字版.exe` — Windows self-extracting RAR (UPX-packed PE32 GUI exe).
  May be a standalone single-player text game, not an LPC/FluffOS mudlib at
  all — confirm what's inside before spending conversion effort on it.
- `西行战记.gz` — plain gzip of a tar (`xxzj.tar`), not `.tar.gz` despite
  looking like a bare archive; extracts fine with `tar` after `gunzip` or
  directly via `tar xzf`.
- `TOMud_VC源代码.rar` (archive #24) — confirmed NOT a mudlib: it's
  "MyMud", a Windows MFC/VC++ GUI mud **client** (`MainFrm.cpp`,
  `DialogGame.cpp`, `MudSock.cpp`, etc. — a telnet client with dialogs,
  not LPC source). Skipped entirely, not run through the conversion
  pipeline.
- `三国歪传.rar` (archive #31) — confirmed NOT an LPC mudlib: it's a
  DikuMUD/Merc-lineage **compiled C server** ("三国歪传" by mrec, Taiwan
  — a Three Kingdoms parody), `src/db.c`/`comm.c`/`fight.c`/`handler.c`
  (classic Diku/Merc/ROM file names), `area/` world files with a
  `directory.lst` index (Diku `.are` convention), zero `inherit`
  statements anywhere in the whole tree (LPC's most basic keyword).
  Fundamentally incompatible with this project's FluffOS/LPC pipeline —
  it's a different server architecture entirely, not something that
  needs UTF-8/registration fixes. Skipped entirely, not converted.
- `消失的亞特蘭提斯MUD破解版.zip` (archive #64) — confirmed NOT an LPC
  mudlib: another Merc 2.1/DikuMUD-derivative compiled C server
  ("EnvyMud" lineage — `envyb.exe`/`play.bat` scaffold), `src/act_*.c`/
  `comm.c`/`db.c`/`fight.c`/`handler.c` (same canonical Merc file names as
  三国歪传/#31), `area/*.are` Diku world-data files, a prebuilt
  `merc.exe`+`cygwin1.dll`, zero `inherit` statements anywhere. Same
  category as #31, skipped entirely. Despite the archive's Traditional-
  Chinese filename, its plain-text `readme.txt` decoded cleanly with the
  standard GB18030 conversion — no BIG5 fallback was actually needed here
  (though the embedded `.are` world-data text looked BIG5-shaped on raw-
  byte inspection; moot since none of this content runs through our
  pipeline).
- `重出江湖.rar` (archive #86) — confirmed NOT an LPC mudlib: a closed-
  source, compiled Windows C++/MFC MUD server (`mud.exe`, PE32 GUI exe
  linked against `MFC42D.DLL` etc) plus a bundled Windows GUI client,
  zero `.c`/`.lpc` files anywhere. `data/*.o` save files ARE genuine
  LPC-style `save_object()` text (likely descends from the same wuxia
  gene pool as many other archives in this project), but the room/npc/
  skill *source* that produced them isn't in this archive, only the
  compiled driver and its runtime output. Directly cross-referenced
  sibling archive #88 (`重出江湖完整源码linunx_2.71原版.rar`, "complete
  source, Linux, v2.71") and confirmed its actual `.cpp` files are real
  C++ (`#include "stdafx.h"`, MFC-style factory functions, zero
  `inherit`/LPC syntax) — `mud.exe` is a compiled build of this same
  C++ engine, not a MudOS/FluffOS-family driver at all. The whole
  "重出江湖" family (#86/#87/#88) is very likely entirely non-LPC;
  #87/#88 still need their own individual triage before being finalized
  the same way, in case an LPC scripting layer sits on top somewhere,
  but the evidence so far points the same direction for all three.
