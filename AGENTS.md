# AGENTS.md — working notes for converting these mudlibs to modern FluffOS

Read this before touching a new archive. Update it whenever you learn
something that will save time on the *next* lib — this is the accumulated
knowledge base for a ~100-archive batch job, not a diary of one run.

## The pipeline, per lib

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
