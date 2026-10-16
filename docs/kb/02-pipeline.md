# KB 02 — Per-lib bring-up pipeline and archive extraction (§2–§3)

## 2. The per-lib pipeline (bring-up from a raw archive)

1. **Extract:** `scripts/extract.sh archives/<file> libs/<slug>/raw/`
   (traps in §3).
2. **Find the mudlib root.** Grep `master file`/`mudlib directory` or
   find `master.c`. The real master defines `object connect(` (§7.42).
3. **Convert:** `scripts/convert_lib.sh`. Encoding first, then
   `.c`→`.lpc`, then reference fixups. Run the §4 post-checks.
4. **Write `config.fluffos`** (§5) with a fresh port.
5. **Apply the §2.2 checklist.**
6. **Compile sweep:** `scripts/lpcc_check.sh <config> <work>`, after
   master and simul_efun compile. Compile the core base classes cleanly
   first (§10.4).
7. **Boot and play:** `cd libs/<slug> && ~/src/fluffos/build-debug/src/driver
   config.fluffos`, then a full registration with `mudclient.py`.
8. **Record:** `NOTES.md`, `README.md`, this file, status, then the WASM
   pass (§1.4).

**Definition of done:**
- Clean boot.
- A real Chinese name registers all the way into a room.
- `look`, `score`, and `quit` are all correct.
- A re-login works.
- WASM status is recorded.
- `debug.log` and the mudlib's own error log are reviewed (§10.7 item 5).

### 2.1 Recognize the lineage first

`md5sum`/`diff` the core files (`master`, `chinesed`, `logind`, `named`,
`securityd`) against processed libs. A match means you can port the
sibling's fix list. Caveats:
- Similar titles prove nothing in either direction.
- Siblings drift independently, so verify each ported fix per instance.
- See the §11 lineage map.

### 2.2 Proactive on-sight checklist

```
grep -n "load_object\|get_root_uid\|get_bb_uid\|get_include_path\|valid_override\|creator_file" <master>   # §7.1/7.2/6.1/7.175
grep -n "destruct" <master> | grep -i "simul_efun"                        # §7.3
grep -n "this_player()" <securityd>                                       # §7.4/7.59
grep -n "dns_master\|intermud" adm/etc/preload                            # §7.6
grep -rn "is_chinese\|check_legal_name" adm/ secure/                      # §8.1
rg -n '^[ \t]*(nomask[ \t]+)?(private|static)[ \t]+(nomask[ \t]+)?int[ \t]+(command_hook|cmd_hook)\s*\(' --glob '*.lpc'   # §8.3a
grep -rn 'sscanf.*\.c[$"]\|\[0\.\.<3\]\|strlen(.*)-3' adm/ daemon/ secure/ # §8.3b/7.80/7.118
grep -rn "MUD_PORT\|PORTNO" include/                                      # §5.3
grep -rn "shutdown\|rm(\|unlink" <securityd>                              # §7.13
grep -rn "\bstatic\b\|\bstatus\b" --include='*.lpc' --include='*.h' . | head  # §4.3/§6.8
grep -rn "ed_start\|ed_cmd\|query_ed_mode\|efun::set(\|efun::query(" .    # §6.2/§7.15
grep -rn "switch\s*([^)]*)\s*{\s*default:" .                              # §6.3
grep -rn 'replace_program(' --include='*.lpc' . | wc -l                   # §7.86/§7.100
grep -rn 'maximum evaluation cost' config.fluffos                         # §7.90 (use >= 5000000)
```

**A `.gitignore` inside `work/` (an upstream repo's own) hides files the game needs from every git-built tree** (site zip, `pristine_tree.sh`, the warning-scan and listcheck trees) while the local working tree still has them. sunshadow (2026-10-10): `adm/db/access.db`, `groups.db` and `privs.db` were ignored, only the `.example` copies were tracked; the master's `load_access()` did `explode(read_file(ACCESS_DB))` on 0, every `check_access()` failed (the error handler's own `write_file()` too, so the real error was swallowed), and 38 of 40 NPCs in one area could not load. Detection: `git status --ignored --short libs/<slug>/work | grep -v '/save/\|/log/\|\.o$'`, and any tracked `X.example` whose `X` is untracked. Fix: `git add -f` the file (shadowgate tracks the same three).
Also apply the WASM standards: §1.3b, §1.3e, and §1.5.

### 2.3 Hosting modes and already-git-hosted sources

- **`vendored`** (default): no live upstream, so `work/` is the source
  of truth in this repo.
- **`submodule-patch`**: the upstream is active. `work/` is a submodule
  pinned by `upstream.commit`, keeping upstream's own conventions.
  - Catalog-only compat lives in `libs/<slug>/patches/NNNN-name.patch`,
    applied by `scripts/apply_lib_patches.py`.
  - `rebase_upstreams.py` bumps the pin only when every patch still
    `git apply --check`s.
  - `upstream.auto_rebase: false` holds the pin.
  - `upstream.branch` overrides the compare branch (`sagenwelt` uses
    `feature/player`).
  - A large patch set (lima's warnings, patches 0003-0006) is made in a
    scratch repo, not in the submodule: `scripts/submodule_patch_scratch.py
    build|export <slug>` (the scanners need `.lpc` names; export maps them
    back and splits the diff into per-directory patches). The same two
    commands regenerate it when a pin bump breaks a patch.
    `lpc_warnings.py` refuses a submodule's `work/`, so a corpus scan run
    only in place silently skips every such lib (fy2005, residuum,
    sanguozhi, xkx100utf8, nightmare3, nt7, oxidus were missed this way):
    scan them in the scratch repo. List the real ones with
    `git ls-files -s libs | awk '$1=="160000"'`. The scan tree now gets the
    lib's `overlay/` (oxidus keeps its driver headers there). Use the
    default `build-debug/src/lpcc`; the older `build-debug/bin/lpcc` lacks
    the promise combinators and oxidus compiles nothing with it. The
    toolkit's boot check reads `libs/<slug>/config.fluffos`, so point its
    `mudlib directory` at the scratch tree first. The builder rewrites `.c` path strings to `.lpc` (include and
    inherit lines and any `"/abs/path.c"`, e.g. residuum's
    `#define STD_OBJECT "/std/object.c"`), and export undoes only what
    upstream spelled `.c`, so a `.lpc`-named upstream (fy2005) round-trips.
    An added line ending in blanks, or a CRLF line spliced into an LF
    file by `lpc_twin_port.py adopt`, fails the byte-for-byte check
    (`git apply` trims both): strip them in the scratch tree first.
  - **Trust the gitlink, not `meta.json`.** About 48 libs (nightmare4,
    mundoscuro, genesis, arkadia, ...) say `submodule-patch` because an
    upstream is recorded, but `work/` is plain files tracked here with no
    `patches/`. They are vendored: edit `work/` directly. The tools check
    `git ls-files -s libs/<slug>/work` for mode `160000`
    (`rebase_upstreams.py` skips them as "not a git submodule checkout").
- **`fluffos-upstream`**: a live `github.com/fluffos/<repo>`. It uses a
  submodule with **empty** `patches/`. The remote itself follows this
  catalog's conventions (`.lpc`, §9-formatted), so land LPC fixes there.
  - Current: `imud`, `sanguozhi`, `xkx100utf8`, `nt7`, `nightmare3`
    (`work/lib`), `deadsouls_fluffos` (`work/lib`).
  - An archived fluffos-org repo is not a hosting target. `lima` tracks
    `limalib/lima` as `submodule-patch`.
  - A big pass (a warnings sweep) is made in the same scratch repo as a
    lima patch set: `scripts/submodule_patch_scratch.py build <slug>` (the
    mudlib subdir, `lib/` here, becomes `work/`), then commit the catalog
    `overlay/` files there as a baseline (and `git commit-tree` a second
    baseline of upstream + overlay for the oracle's HEAD side) so scans,
    `ds_oracle_run.sh` and live sessions boot like the site. The PR is two
    scratch diffs applied with `git apply --directory=lib -p4` on a branch
    of the fork (mechanical, then structural), after a paired
    baseline/branch live run; merge it yourself once tested, bump the pin
    with `rebase_upstreams.py`, and **rebuild every overlay file that is a
    full copy of an upstream file** (`deadsouls_fluffos`'s
    `overlay/lib/secure/sefun/sefun.lpc` is upstream's plus one `#include`,
    so a pin bump that touches `sefun.lpc` is undone on the site otherwise).
- The site zip contains the **patched playable tree** plus `patches/`
  and `meta.json`.
- `scripts/check_upstream_rebase.py` regenerates
  `scripts/upstream_status.json`. Never hand-edit it.
- **Every catalog patch must apply on its own.** `rebase_upstreams.py` runs
  `git apply --check` for each patch against the pristine pin, not after the
  earlier ones, so a patch whose context is another patch's lines fails and
  holds the pin (residuum `0006` on `0001`'s master stubs, 2026-10-05). A
  change to lines an earlier patch added belongs in that patch: rebuild it in
  a temp repo (pristine file, apply both, `git diff`). Check: `for p in
  libs/<slug>/patches/*.patch; do git -C libs/<slug>/work apply --check -p1
  $PWD/$p; done`.
- **A submodule's object store must stand alone.** One cloned with
  `--reference`/`--shared` against a `/tmp` clone keeps only a few loose
  objects; after a reboot every `git status` prints `object directory
  /tmp/... does not exist` and nothing past the pin is readable (`nt7`,
  2026-10-05). Repair: bare-clone the upstream, write its `objects` path into
  `.git/modules/libs/<slug>/work/objects/info/alternates`, confirm
  `git rev-list --objects --missing=print HEAD | grep -c '^?'` is 0, run
  `git repack -a -d` (no `-l`), delete the alternates file, then
  `git fsck --connectivity-only`. Detect: `find .git/modules -path
  '*objects/info/alternates'`.

Lessons from onboarding git-hosted sources (`imud`):
- Still run `convert_lib.sh`.
- A failing file that is upstream's own disabled scaffolding is fine.
- A thin, intentional surface (no rooms, no accounts) is a valid
  "playable".
- **`imud` makes a real outbound Intermud-3 connection at boot.** Keep
  it out of high-frequency reboot loops. Flag any lib that dials out
  from `create()` prominently in its `NOTES.md`.

LDMud-to-FluffOS porting: see `docs/ldmud-to-fluffos.md` and §7.158.
Policy (2026-09-11):
- A port is done when every archive-shipped room, object, and command
  loads and plays. Fix trivial load failures of existing objects.
- **Never invent missing content.**
- A pure skeleton framework with no rooms may add one void/example room
  so it can come online. Never let such a room hide a real world.

---

## 3. Archive extraction traps

**The archive store (2026-10-10).** `archives/` holds one file per
distinct archive (SHA-256), named `NNN[-M]_<slug>_<original-name>` from
the *current* catalog. Original bytes are never re-encoded.
`scripts/archives_manifest.py` (dry run; `--apply`) places new files,
drops byte-identical copies, and writes `archives/MANIFEST.tsv`,
`archives/SHA256SUMS` and the committed `scripts/archives_manifest.tsv`
(every name a file was seen under, plus its source). A bulk upload goes in
with `--bundle <extracted-dir> --bundle-name <upload.rar>`; add an
`OVERRIDES` entry for what the catalog can't place by name. Old filename
prefixes are not trustworthy (slugs were renamed, 901/930/931 renumbered),
and two different uploads can share a name (`重出江湖.rar` is 905 and 905-3;
`终极地狱.rar` in `mudlib.rar` is really `终极地狱2008完整版.rar`).
A lib onboarded from a download or a git clone also gets its source stored:
save the downloaded file itself (not only `raw/`), and for a git source a
`git clone --mirror` packed as `<owner>-<repo>.bundle` (`git bundle create
--all`; verify inside an empty bare repo, `bundle verify` refuses to run
outside one). The script places bundles by the GitHub URL in the catalog.
The off-machine copy is the maintainer's Google Drive (`backup-mud/archives/`);
after `--apply`, re-sync with `rclone copy archives <remote>:backup-mud/archives`
and confirm with `rclone check --one-way`.

- `unrar x -y`, `7z`, `unzip`, and `tar` all work. A self-extracting
  `.exe` opens with `unrar`/`7z`.
- **`7z` can report success while writing all-zero-byte files.**
  Spot-check sizes and retry with `unrar`.
- **A `.rar` that is really a tar with `../` members:** GNU tar refuses
  those members. Extract with Python `tarfile` and strip the `../`.
  `ls | grep` for exact filenames (some have trailing spaces).
- A bare `.gz` can be a tar. Some archives nest the mudlib in an inner
  archive.
- **Binary-only (`.b`, `MUDB` magic) archives** get
  `wasm_status: "binary-pending-tooling"`, never `not-convertible`, until
  §3.1 recovers their source. Look for a 源码版 sibling first.
- **A `d/`/`npc/` directory shape is not evidence of LPC.** If
  `grep -rIl inherit` finds nothing, it's a C engine. Don't create a
  `libs/` dir for it.

### 3.1 Recovering source from MudOS `.b` binaries (`scripts/mudos_b/`)

A lib that ships `binaries/**/*.b` (MudOS `save_binary` cache, `MUDB`
magic) with blanked `.c` files can be decompiled back to LPC. First
case: wllz3 (186), MudOS v22pre11, 9,365 programs, all but one
recovered; the full story and the commands are in `libs/wllz3/NOTES.md`
and `libs/wllz3/rebuild.sh`. Second: longyunmeng_binary (033-3), a Win32
v22pre11 build, 14,395 programs, all but one proven
(`libs/longyunmeng_binary/NOTES.md`, `rebuild.sh`).
- **Efun numbering comes from the game's own driver.** An unstripped ELF
  driver has `predefs`/`efun_table`; `python3 -m mudos_b.elfdriver`
  writes `mudos_b/drivers/<slug>.json`. Never guess the table from a
  MudOS version string: builds differ by compile options.
- **A Win32 `mudos.exe` has no symbols.** `python3 -m mudos_b.pedriver
  mudos.exe <out.json>` finds `predefs` by shape (the longest run of
  32-byte keyword_t whose `word` points at an identifier, `next` 0, sorted,
  holding `call_other`) and reads the operator opcodes from the
  `add_instr_name()` calls in `init_instrs()`. The 033-3 build carries
  three extra operators (`*_classstack_object`), so every efun token is 3
  higher than in the Linux build: the JSON then lists `operators`, and
  `entry_size` 16 (MSVC `compiler_function_t`; 12 on Linux). Symptom of a
  wrong base: efuns decode as nonsense names, `unknown efun` from `cli`.
- **Decompile:** `python3 -m mudos_b.cli <binaries> <driver.json>
  <simul_efun> --list <paths> --out <dir> [--fluffos] [--gbk]`. `--fluffos` emits
  `protected` for static functions, `nosave` for static vars, and drops
  unused locals (FluffOS errors on `nosave` functions and warns on the
  rest). `--gbk` keeps GBK characters whole in strings: a second byte
  `0x5c` written as `\\` leaves a stray backslash once the tree goes to
  UTF-8 (17 files in 033-3).
- **Prove it with the original driver** when it runs on the host:
  `python3 -m mudos_b.roundtrip` recompiles every decompiled file in the
  old driver and compares the new `.b` with the shipped one, canonically
  (`mudos_b.oracle`). Only a 0-diff round trip counts as recovered.
  Intact `.c` files that also round-trip are kept as-is (comments
  survive); the rest are replaced by the decompiled text.
- **No host-runnable original: a stand-in build of the same version.** The
  wllz3 Linux v22pre11 driver compiles the 033-3 code the way the Win32
  one did: `roundtrip <oracle-raw> <target.json> --bdir <shipped
  binaries> --oracle-table mudos_b/drivers/wllz3.json`; `canon()` compares
  by name, so the efun numbers may differ. Match the target's
  DEFAULT_PRAGMAS with `--pragma` (033-3: `no_strict_types`, untyped
  `create()` has no NAME_STRICT_TYPES there) and drop build-only codegen
  with `--fold transfer_local` (the Win32 build never emits it). Tell: one
  `differs` reason across thousands of programs is a build difference,
  not a decompiler bug.
- Traps in the oracle driver: `read_file` caps at 200,000 bytes (split
  job lists); `dump_prog` rejects paths with `#`; loading runs
  `create()` and can segfault the driver (restart and resume; the runner
  retries an object once, an error `catch()` cannot hold such as too deep
  recursion skips only that object). Preload the lib's security daemon:
  `write_file()` goes through it, and without it the runner logs nothing
  and waits out its stall timer.
- **Code shapes found on 033-3** (all in `decompile.py`): `continue` in
  `while (1)` (a branch to the closing `bbranch`); the compiler adds
  `return 0` after `return x;` only when the body has three or more
  top-level statements, local initializers counting as one (fold them
  back: initializers, a comma, a for-init or a block); two globals of one
  name (`#include` of two files that both declare `names`) and a simul_efun
  call to a function the program defines later both need declarations
  placed between the functions; an efun called while a same-named
  function is visible is `efun::name`.
- **A source edition of the same game is a source, not an oracle.**
  Compile its `.c` against the binary edition's tree in the stand-in and
  keep only exact matches (033-2 gave 8,202 of 12,125, `rebuild_tree
  --borrow`, with a header naming the source). Inherited programs go in
  rounds: a parent that differs fails its children, so retry those with
  the parent reverted to the decompiled text until nothing changes. Leave
  the master and simul_efun out of the big run (a later version that does
  not compile stops the boot).
- **Then port the source edition's fixes.** A borrowed file is the source
  edition's pre-fix text, so `lpc_twin_port.py classify/adopt SRC DST --pre
  <SRC's onboarding commit>` carries every later corpus fix over (033-3: 3,718
  files from 033-2). Decompiled files (`v1`, `arg1`) match neither the token
  diff nor the name-based fixers (`lpc_fix_perform_weapon.py` looks for
  `weapon =`): read the source edition's `tokdiff` of its core files (master,
  logind, user, `feature/*`, room base) and port by hand.
- **A generated `work/` drifts when a corpus sweep edits it.** wllz3's
  rebuild stopped reproducing its tree after a skill-name sweep
  (046704ce5fe); the sweep's hunks went into `fluffos-fixes.patch`. Check:
  `OUT=<dir> REC=<dir> libs/longyunmeng_binary/rebuild.sh`, then diff.
  Fold an edit back in: `PATCH=0` on the same command builds the unpatched
  base, and `decompile/mkpatch.sh <base> work decompile/fluffos-fixes.patch`
  rewrites the patch (033-3).
- **Originals that compile but disagree with their binary** are stale
  sources: the binary is what the game ran. Use the decompiled file.
  Unless the source is newer and the driver ran that directory from
  source: 033-3's `d/automap` (a regenerated maze, `.c` 14 minutes newer
  than its `.b`, `valid_c_or_bin_run()` allows `.c` there) keeps its `.c`.
- Source that MudOS took and FluffOS warns on comes out of the decompiler
  unchanged (it is faithful): arity mismatches with inherited
  definitions (`void remove()` vs `remove(string)`), `int setup()` over
  `void setup()`, an apply name reused for a private helper. Fix them
  after conversion and keep the fixes as a patch the rebuild applies.
