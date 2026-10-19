# Mudlib repair toolkit

The scripts in this repository restored and cleaned up more than 270 old LPC
mudlibs so they run on the current [FluffOS](https://github.com/fluffos/fluffos)
driver. They work on any LPC mudlib, including yours. This page explains how to
point them at your own lib.

What they do well:

- **Bring an old lib onto a modern driver**: re-encode GB18030/BIG5 text as UTF-8,
  rename `.c` to `.lpc` and fix the references that rename breaks, and
  change `static` to `nosave`.
- **Fix compile warnings at their source** (every warning the driver prints is
  a bug until shown otherwise): unused locals, `nosave` functions, prototypes
  that disagree with their definitions, `&` used for `&&`, an `NPC` and an
  `F_UNIQUE` that both define `init()`, a file inherited twice through two paths,
  locals that only an inactive `#if` branch uses, and more.
- **Prove that nothing broke**: every changed object is loaded twice, once
  from your last commit and once from your working tree, each time in a fresh
  driver process, and anything that loaded before and fails now is reported.

Everything here is MIT-licensed (see `LICENSE`).

## What you need

- Linux or macOS with `git`, `python3` (3.8 or newer), `bash` and `iconv`.
- A FluffOS build from master (v2026.0724 or newer) that includes the `lpcc`
  target, which provides `lpcc --batch`. The scripts look for
  `~/src/fluffos/build-debug/src/lpcc`; set `LPCC=/path/to/lpcc` if yours is
  elsewhere.
- Disk space for scratch trees: every scan copies your lib into `$LPC_SCRATCH`
  (default `~/.cache/lpc-scratch`). lpcc runs are memory-capped at `LPCC_MEM_GB` (default 6).
  Every lpcc run is capped at 6 GB of address space so one runaway object
  fails its batch instead of exhausting the machine; set `LPCC_MEM_GB` to
  change it (`scripts/lpcc_mem.py`).

  Build dependencies are listed in FluffOS's own
  [build guide](https://github.com/fluffos/fluffos/blob/master/docs/build.mdx).

  ```
  git clone https://github.com/fluffos/fluffos ~/src/fluffos
  cd ~/src/fluffos && mkdir build-debug && cd build-debug
  cmake .. -DCMAKE_BUILD_TYPE=Debug && make -j"$(nproc)" lpcc driver
  ```
- A clone of this repository. You only need `scripts/` and `docs/`, so a
  sparse checkout keeps it small:

  ```
  git clone --filter=blob:none --sparse https://github.com/fluffos/mudlibs
  cd mudlibs && git sparse-checkout set scripts docs
  ```

## Quick start

```
# 1. import: copies (never modifies) your lib into libs/<slug>/work and commits it
#    on a local branch toolkit/<slug>.  Encoding: GB18030 (default), BIG5 or UTF-8.
git sparse-checkout add libs/mymud
scripts/toolkit_import.sh /path/to/your/lib mymud /path/to/your/config UTF-8

# 2. one repair round: scan, fix, load-check, audit.  Nothing is committed.
scripts/toolkit_fix.sh mymud

# 3. read the diff, keep what you like
git diff --stat
git commit -am "warning fixes"
```

`toolkit_fix.sh` prints a short report. Here is the report for TMI-2 as it
stood before its own cleanup, run through these scripts:

```
== 1. scan
  688 files compile, 27 do not; 961 distinct diagnostics
round 1: nosave functions 420 protected + 62 dropped, ..., unused locals 324
  688 files compile, 27 do not; 126 distinct diagnostics
== 2. diagnostics-driven fixers
   bitwise:      1 fixed ...   #if locals:   7 file(s)
== 4. load check: HEAD vs working tree
tkold: 223 objects; HEAD PASS 213, tree PASS 213; regress 0; newly loading 0
== 5. deleted declarations still read (look at each)
checked 543 removed declarator(s); 0 to look at
```

To copy the result back to your game, take `libs/<slug>/work`. FluffOS loads
`.lpc` and `.c` alike. If you need `.c` names for an older driver, rename the
files back and reverse the `".c"` → `".lpc"` string edits in the diff.

## If the lib does not boot

`toolkit_fix.sh` stops at step 0 if the driver cannot load your master object
and simul_efun file, and shows you the driver's last lines. The usual causes,
each with a knowledge-base entry:

| The driver says | Look at |
|---|---|
| `No function get_root_uid() in master object` | `docs/kb/05-runtime-classes-1.md` §7.2 (and §7.1 if the master then recurses while loading its security daemon) |
| `simul_efun ... destruct` / a crash while loading the simul_efun | §7.3 |
| `Cannot #include ...` | `docs/kb/04-compile-classes.md` §6.1 (`<../x.h>` includes are refused) |
| `Illegal to declare nosave function`, `static` errors | `docs/kb/03-encoding-config.md` §4.3 |
| garbled Chinese after import | re-import with `BIG5` instead of `GB18030` (§4) |
| `Error in config file. Missing line: ...` | a config line longer than 120 characters ends the parse early (KB 08 §10.4); shorten paths |

A grep across `docs/kb/` for the exact message usually finds the entry.

## Reading what is left

```
python3 scripts/lpc_warnings.py mymud --list 20
```

This groups everything the driver still reports by kind and gives up to 20
examples of each. `docs/kb/04-compile-classes.md` §6.10 lists every warning
class, with the fix that keeps behavior unchanged and the trap to avoid.
Classes the toolkit leaves to you on purpose:

- **`Expression has no side effects`** in a file that compiles is very often a
  gameplay bug: `==` typed for `=`, a getter with no `return`, `me->die;`
  without `()`. Read every one.
- **`F() inherited from both A and B`**: the driver already uses the later
  inherit. `scripts/lpc_name_winner.py` writes that choice down, but first
  read both definitions: if the winner is an empty stub, kept only so the
  file compiles standalone, the stub is the bug (KB 06 §7.239).
- **`Redeclaration of global variable`** across hundreds of files usually
  comes from one base class that inherits a file twice or redeclares a parent's
  variable (`scripts/lpc_diamonds.py`, KB 06 §7.213).
- **A typed `?:` with two different types, `/*` inside a comment, and macro
  redefinitions** are small hand edits.

## The tools

| Script | What it does |
|---|---|
| `toolkit_import.sh` | Brings a lib into `libs/<slug>/` and commits it on a local branch |
| `toolkit_fix.sh` | One repair round: boot check, scan, fixers, load check, audit |
| `convert_lib.sh` | Converts encoding, renames `.c` to `.lpc`, fixes the `".c"` references, changes `static` to `nosave` |
| `lpc_warnings.py SLUG [--fix] [--list N]` | Scans with `lpcc --batch` in chunks that survive a crashing object, then applies the mechanical fixes |
| `lpc_fix_bitwise_bool.py` | Turns a lone `&`/`|` between comparisons into `&&`/`||` |
| `lpc_fix_return_types.py [--also NAME]` | Fixes `int create/init/reset` where the base declares them `void`, and prototypes that disagree with their definition |
| `lpc_fix_float_trunc.py SLUG [--apply] [--diag TSV]` | "Float value truncated to int" (FluffOS 2026-10): `x = <float>`, initializers and `return` get `to_int()` (same value, explicit); `x op= <float>` zeroed or truncated the step before applying it and becomes `x = to_int(x op ...)`. Anything else is listed for a hand edit |
| `lpc_fix_void_return.py SLUG [--apply] [--diag TSV]` | Fixes `Type of returned value doesn't match function return type ( T vs void )`, a `void` (or untyped) function that returns a value. In applies whose value the driver ignores (`init`, `reset`, `heart_beat`, `create`, `setup`) the return becomes bare, and a call keeps its side effects (`{ ::init(); return; }`). Any other function, and its same-file prototypes, gets the type it returns (`mixed` if it returns several): add_action handlers and commands need the value (KB 04 §6.3). In `toolkit_fix.sh`. |
| `lpc_fix_array_type.py SLUG [--apply]` | `array` on its own used as a type (`array names;`, `array f()`, `void g(array a)`). This driver keeps `ARRAY_RESERVED_WORD` off, so the file fails with `Illegal lvalue`, `Illegal LHS` or a syntax error. Rewrites them to `mixed *`, starring every declarator, in code only; a variable named `array` is left alone (KB 04 §6.3). In `toolkit_fix.sh`. |
| `lpc_fix_damage_calls.py SLUG... [--apply]` | `receive_damage("qi", -12)` / `receive_damage("neili", -52)`: a cost written as negative damage. Where `damage.lpc` rejects a negative amount every practice of the skill errors; where it clamps, the cost vanishes. Makes the amount positive, or `add("neili", -52)` for a resource pool; leaves `-damage`-style variables alone (KB 06 §7.241). Runtime class, not in `toolkit_fix.sh`. |
| `lpc_damage_types.py [SLUG...]` | Report only: `receive_damage()`/`receive_wound()` with a type the lib's own `damage.lpc` rejects (xkx `jing/qi` content in a `gin/kee/sen` lib or the reverse). Read each hit (KB 06 §7.241). |
| `lpc_port_es_props.py SLUG... [--any-file] [--apply]` | Code from another pool lineage, in a lib whose `damage.lpc` errors on the unknown type: ES/xyj `kee`/`gin`/`sen`/`force` in an xkx lib (`qi`/`jing`/`neili`), the reverse (`jing` goes to whichever of `gin`/`sen` the lib's own study/learn commands charge), or xkx `jing` in the xxcq family (`jingli`). Renames the property keys of the dbase and damage calls in those files only. Default scope is kungfu/skill practice_skill(); `--any-file` takes performs, conditions, weapons, NPCs and skips directories nothing else names (KB 06 §7.241). |
| `lpc_fix_family_guard.py SLUG... [--apply]` | `mapping fam = ob->query("family");` indexed with no test: a sectless player gets `Value being indexed is zero`. Adds `if (!mapp(fam)) fam = ([ ]);` on the declaration line (KB 05 §7.30). |
| `lpc_fix_vision_env.py SLUG... [--apply]` | `message_vision(msg, environment(me), me)`: the room passed as the actor, so `replace_string(msg, "$N", 0)` errors (mostly poison conditions, every heart beat). Rewrites to `message_vision(msg, me)` (KB 06 §7.242). |
| `lpc_fix_eaten_quote.py SLUG... [--apply]` | A closing `"` lost in the GBK conversion (`return name + HIM "发作身亡了;`): the string runs on and the file, and everything inheriting it, fails to load. Puts the quote back before a line-final `;`/`);` (KB 03). |
| `lpc_action_index.py [SLUG...]` | Report only: a skill's `query_action()` indexing past its own move table (`action[random(9) + 6]` with 8 moves). Read each hit: one under a perform flag nothing sets is dead (KB 06 §7.243). |
| `lpc_fix_action_level.py SLUG... [--all-files] [--fallback] [--apply]` | A copied skill whose `query_action()` walks the move table by the original skill's level (`query_skill("tiesha-shenzhang", 1)` in tiezhang-zhangfa): points it at the file's own name, in skills the lib uses. `--fallback` adds `if (!a_action) a_action = action[0];` where the table's lowest "lvl" is above 0 (KB 06 §7.243). |
| `lpc_fix_perform_weapon.py SLUG... [--apply]` | A perform that uses `weapon = me->query_temp("weapon")` without testing it: used bare-handed (`perform stick.ban`) it errors, often after taking neili. Adds an `objectp()` guard with a message after the assignment (KB 06 §7.246). Also the inline shape, `(me->query_temp("weapon"))->name()` with no stored weapon: the refusal goes before the function-level statement holding the first use (never between an `if` block and its `else`; a move whose included `type()` helper maps no weapon to unarmed is left). |
| `lpc_fix_family_index.py SLUG... [--apply]` | The family mapping indexed inline, `ob->query("family")["master_name"]` / `query("family", ob)["family_name"]`: a sectless character (every new player) errors in NPC greetings, inquiries and sect checks. Rewrites each read as the path query `query("family/KEY")` (same value, 0 instead of an error); assignments into the mapping are left (KB 05 §7.30). |
| `lpc_fix_unit_cut.py SLUG... [--apply]` | `inventory` / brief item lists / `look` print a single item as `key[2..]` where the key is `unit + short()`: the one-hanzi unit was two GBK bytes, but after the UTF-8 conversion the cut also eats the first character of the name (「把长剑」 shows as 「剑」). Rewrites the `my[x[i]] == 1 ? x[i][2..] : x[i]` shape to `[1..]` (code only, multi-line ternaries included; KB 07 §8.1). |
| `lpc_unassigned_locals.py [--all-files] SLUG...` | Detector, no edits: an `object` local that a function dereferences but never assigns -- a perform reading a weapon it never fetched, a `check_fight()` whose `!weapon` is always true, a variable whose assignment was commented out, a call_out target declared without the parameters the call_out passes (KB 06 §7.246, §7.253). Perform and exert files by default; read each hit, a use behind a guard that is never true is listed too. |
| `lpc_guard_carry_object.py SLUG... [--apply] [--list] [--base \| --unew]` | An NPC whose `create()` carries an item the lib does not have: `carry_object("/missing")->wear()` raises and the NPC never loads (the room comes up without it). Rewrites each such statement whose literal path (absolute or `__DIR__`) names no file as a guarded block; the NPC loads without the item, a virtual or restored path is still carried (KB 06 §7.73). `--base` instead fixes an NPC base whose own `carry_object(string file)` starts with `file->query_unique()` (a call_other that raises for a missing file; xyj/sjsh/mhxy lineage): adds `load_object(file)` ahead of it. `--unew` fixes the simul_efun `unew(str)` that does `ob = new(str); ob->query("unique")` (new() of a missing file returns 0): adds `if (!ob) return ob;`. |
| `lpc_fix_pool_as_skill.py SLUG... [--apply]` | A pool, attribute or experience read through `query_skill()` (`query_skill("max_neili") < 500`, `random(query_skill("combat_exp"))`, `query_skill("int", 1)`): 0 in the xkx/ES F_SKILL (gates never open, `random(0) > 0` never lands), a missing skill daemon in Fengyun. Rewrites the names with one reading to `query("NAME")`; current pools (`neili`, `jing` ...) and jiali lines are listed as HAND, since they often mean the `force` skill. KB 06 §7.247. |
| `lpc_fix_skill_typo.py SLUG... [--dict-libs SLUG...] [--apply]` | A misspelled skill name in `query_skill()` (`beimin-shengong`, `douzhuan-xignyi`, a pre-rename name like `jinwu-dao`): always 0, so gates never open and exclusions never fire. Fixes a typo-shaped name only when a Chinese name confirms it (the site's message, a `data/e2c_dict.o`/`chinese.o` dictionary) or the difference is purely mechanical (`_`/`-`, a hyphen, swapped letters), or the site is in the skill's own file and one letter off its name; names a dictionary or the site calls a different skill are left (OTHER), unconfirmed ones are listed (SKIP). `--dict-libs` adds other libs' dictionaries. KB 06 §7.249. |
| `lpc_format_changed.py [--apply] FILE...` (or the list on stdin) | The fix-pass formatter step: runs the corpus formatter in `--check` mode on the HEAD copy and the working copy of each changed file, and formats only files that were normalized at HEAD and that your edit un-normalized. Files that were never formatted stay in their own style, so a one-line fix is not buried in a full rewrite. KB 08 §9. |
| `lpc_fix_inherit_order.py SLUG [--apply] [--diag TSV]` | Fixes `Illegal to inherit after defining global variables`. Top-level variable declarations, and `#include` lines of headers that declare globals (nested includes followed), that sit above the last `inherit` move, as whole lines in their order, to just below it. A file where an offender or that `inherit` is under `#if`, or an offender shares its line with other code, is listed for a hand edit (KB 04 §6.3). In `toolkit_fix.sh`. |
| `lpc_fix_float_hooks.py SLUG [--apply] [--diag TSV]` | The float sites `lpc_fix_float_trunc.py` lists for a hand edit when they are whole functions: an `int` function whose returns are all numeric literals, at least one a float (skill hooks `power_point()`/`hard_point()`, one line or branches), becomes `float`. Lists every caller: one that keeps the value in an `int` and multiplies gets a float at runtime, so give it a `float` receiver and `to_int()` the product (KB 04 §6.10). Not in `toolkit_fix.sh`: the callers need reading. |
| `lpc_save_encoding.py [--apply] [--from-raw] SLUG...\|FILE...\|--all` | Text save files (`.o` with a `#` header) still in the archive's GBK/BIG5/Windows-1252 bytes, which `restore_object()` rejects (`Invalid utf8 string`): transcodes each with the encoding that reads like the lib's own sources and keeps it only when it parses as a save (KB 03 §4). `--from-raw`: UTF-8 saves the onboarding transcode broke (a quote swallowed with a lone lead byte; a stray backslash after a BIG5/GBK 0x5C character): re-decoded from raw/ when iconv of raw/ still gives the tracked bytes, else only backslashes after 0x5C characters move, and only when the result parses (KB 03 §4.4). Both modes write a raw newline inside a string as `\r` and drop blank lines, which `restore_object()` refuses; the parser now refuses those and a missing element comma, as the driver does. |
| `lpc_save_restore_check.py [-v] [--driver-all] SLUG...\|FILE...\|--all` | Asks the driver whether tracked text saves restore: each `#/` save the save parser rejects (or every one) is restored by a throwaway object in a throwaway mudlib under `$LPC_SCRATCH/rtlib`; prints `FAIL path<TAB>error`. The ground truth for a save-repair list (the parser over-reports). |
| `lpc_fix_void_override.py SLUG [--mixed]` | `int create()`/`init()`/`reset()` where the base says `void`; with `--mixed`, an override whose return type clashes with the base (`mapping` vs `string`) becomes `mixed` |
| `lpc_fix_unique_init.py` | Adds `init()` to NPCs that inherit both `NPC` and `F_UNIQUE` |
| `lpc_fix_unused_init.py` | Handles unused locals with an initializer: deletes a pure one, keeps a single call as a statement |
| `lpc_move_decl.py` | Moves a declaration that only an inactive `#if` branch uses into that branch |
| `lpc_diamonds.py [--fix-redundant]` | Finds inherits another inherit already contains (text in comments, here-documents and multi-line strings is skipped: generator templates carry `inherit` lines) |
| `lpc_name_winner.py` | Writes down the function the driver already picks for an `inherited from both` overlap |
| `lpc_fix_double_decl.py` | Drops the bare copy when one declaration statement names a variable twice (`string a, b, a = "x";`), the `Redeclaration of global variable` it causes |
| `lpc_twin_port.py` | Ports fixes made in one lib to a sibling whose files carry the same code |
| `lpc_listcheck.sh SLUG LIST` + `lpc_load_diff.py SLUG` | Loads a list of objects at HEAD and in the working tree, then reports regressions |
| `lpc_audit_removed_locals.py BASE` | Finds deleted declarations whose function still reads the name |
| `lpc_audit_shadow_globals.py` | Finds deleted `int g = N;` locals that were really meant to assign the global `g` |
| `lpc_lpc_suffix_slice.py` | Finds `f[<2..] == ".lpc"` slices the `.c` rename left too narrow |
| `lpc_drop_replace_program.py [--apply] SLUG_OR_DIR...` | Deletes `replace_program(X);` lines whose `X` is the file's own `inherit` (a pending replacement makes every closure bound to the room or board fail); other arguments are listed, generator templates are left for a hand edit (KB 06 §7.86, §7.100) |
| `pristine_tree.sh SLUG PORT DIR` | Builds a throwaway copy of the committed lib, with its own port, to boot and test |
| `python3 -m mudos_b.cli` (+ `mudos_b.elfdriver`, `mudos_b.pedriver`, `mudos_b.roundtrip`) | A lib shipped as MudOS v22 `.b` binaries (`MUDB` magic) without its `.c`: reads the efun table from the game's own Linux or Win32 driver, decompiles every `.b` to LPC, and proves each file by recompiling it in a v22pre11 driver and comparing the programs (KB 02 §3.1) |

## Lessons from 270 libraries

These come from real damage that the checks above caught. Keep them in mind
when you write a fixer of your own.

1. **Compare against a commit, in fresh processes.** A second load in the same
   driver can pass only because the first one already compiled the file.
2. **The compiler's list has blind spots.** A name used only in an inactive
   `#if` branch looks unused. A file with an earlier error can report a local as
   unused while the code reads it. After every batch run
   `lpc_audit_removed_locals.py`.
3. **Some files are broken on purpose.** Compiler test suites (`tests/compiler/fail/`)
   and help pages that demonstrate error messages must stay broken.
4. **Text can look like code.** Here-documents (`@CODE ... CODE`) in room makers
   contain `inherit ROOM;`, and a line-based fixer must not touch them.
5. **Read files byte-exact.** Old libraries mix CRLF, LF and stray CR. Text mode
   counts a stray CR as a line break, which shifts every later line number.
6. **The driver picks the later inherit.** When two parents both define a
   hook, the earlier parent's version silently never runs. That is how 75 boss
   NPCs stopped picking fights and how keys stopped saving.

The full catalog of bug classes, each with symptom, cause, fix and detection,
is in `docs/kb/` (index in `AGENTS.md`).

## Help, and giving back

- Questions and bug reports about the tools: [open an issue](https://github.com/fluffos/mudlibs/issues/new).
- Have an old mudlib on a disk somewhere? See "Support this project" in
  [README.md](README.md). We preserve it, credit you, and make it
  playable in the browser.
- The project runs on donations: [Open Collective](https://opencollective.com/fluffos-579).
