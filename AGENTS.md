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
