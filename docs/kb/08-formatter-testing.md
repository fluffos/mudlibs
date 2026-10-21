# KB 08 — Formatter and testing methodology (§9–§10)

## 9. LPC formatter (`~/src/fluffos/tools/lpc-syntax/`): required checks

```
find libs/<slug>/work -name '*.lpc' | node ~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs
```
Files it refuses (nonzero `errors`) are normal. After formatting, check
all three blind spots, then re-boot and re-test:
1. **`::` split into `: :`.** Fixed upstream; audit older output with
   `grep -rnE ':\s:\s*[a-zA-Z_]+\(' libs/<slug>/work`. Revert the file.
2. **`case` label plus trailing `//` comment** merge, deleting the next
   statement. No grep catches this; diff-review case-heavy files.
3. **Pre-existing unbalanced quotes** cause garbage re-spacing (spaced
   CJK, `\ n`). Detect with
   `grep -rl '\\ n' libs/<slug>/work --include='*.lpc'`, or a diff scan
   for `\\ [nrt]` / spaced CJK. Revert the file after confirming against
   the pre-format blob.

Formatter-clean is not compiler-clean (§7.73). Losing formatting on a
few files is always an acceptable trade.

**In a fix pass, format the changed files only** (`git diff --name-only ... | node .../format-corpus.mjs`). A file the
formatter already produced comes back `unchanged` or with only the edited lines moved; one that comes back rewritten end to
end (2026-10-14: 234 of 1040 files, 75k lines, in Discworld, the Dead Souls family, naruto, dreamofseven ...) was never
normalized, and reformatting a historic lib inside a warning fix buries the fix: revert those files (`git checkout --`) and
keep the hand edits in the file's own style. `scripts/lpc_format_changed.py [--apply] FILES` does this split: it runs `--check` on the HEAD copy and on the working copy and formats only files that were normalized at HEAD (the bare formatter writes in place, and a `wouldChange` on a file you edited by a line or two is such a never-normalized file). 2026-10-15: three headers with a one-quote fix were rewritten (337 lines each) and committed before the `"written":3` was read; restored in a fix-forward commit. 2026-10-19: the same thing at scale: the wrapper took a HEAD copy the formatter *refuses* (it does not parse: the lost quote you just repaired is the reason) for a normalized one, so 95 of the 264 repaired files in part 16 were formatted end to end (+49k / -48k lines staged); a refused HEAD copy counts as never formatted now, and `git diff --cached --numstat | sort -nr | head` before a commit is the check.

---

## 10. Testing methodology and multi-session hygiene

### 10.0 Long-sit boot watch
`scripts/wasm_boot_watch.sh <slug> [sec]` (default 200s) sits connected
and greps the transcript. Treat the grep as a starting point. The
`Unable to open log file: "log/debug.log"` line is the §10.9 artifact.

### 10.1 The verification bar
In one continuous session:
- register with a real Chinese name into a room;
- run `look`, `score`, and `quit`;
- re-login (the restore path).

Then review both logs (§10.7 item 5). Test both gender and other
branches where cheap.

### 10.2 Driving the client
- `python3 scripts/mudclient.py 127.0.0.1 <port> --timeout N --idle 0.3 --send ...`
  opens a new connection per call. The transcript shows send markers.
- `scripts/tmux_mud.sh {start|send|read|stop} SESSION ...` keeps one
  connection alive across calls.
  - `read` is cumulative scrollback; confirm with a fresh distinct
    command.
  - The local `telnet` can mangle specific CJK bytes. Re-test through
    `mudclient.py` before blaming `is_chinese()`.
  - Use `telnet -E`, and pipe `capture-pane | tail -N` yourself.
- Live-clock prompts break idle-based pacing. Keep `--idle` well under
  the tick interval, or use a fixed per-send wait or a hard deadline.
- Prefer small raw Python socket scripts that match on prompt strings.

### 10.3 Instrumentation
- Errors escaping `logon()` are swallowed. Wrap the smallest statement
  in `catch()` and print with `efun::write(err)`.
- Bisect with `write("CKPTn\n")` lines. `log_file` may be ACL-denied, and
  it does not persist across WASM runs.
- Inside non-privileged objects use `debug_message()`, which always
  writes to driver stdout.
- Instrument master applies with
  `efun::write_file("/DEBUG.log", sprintf(...))`.
- Remove ALL instrumentation and restart the driver.

### 10.4 lpcc sweeps
- `lpcc --batch` runs one VM. If you touch it, keep the per-file
  `set_eval()` re-arm.
- False-positive classes:
  - `#include`-only fragments;
  - hardcoded-path `call_other`s;
  - `valid_override` arity (use the 3-arg form);
  - eval-cost accumulating across a batch;
  - `Nesting call_out(0) level limit exceeded: 1000`: after about a thousand rooms whose `create()` does
    `call_out(f, 0)` every later one FAILs in the batch and loads fine alone (743 of es1_win's 927 FAILs).
    `scripts/lpcc_real_fails.py OUT` lists the other FAILs, one line each. A scan's "N files do not compile"
    counts the artifact too; its diagnostics are unaffected.

  Confirm against a real boot. `lpcc` FAIL with a live boot OK is a
  known artifact when `create()` touches missing content.
- **Memory:** batch mode never unloads. A broken widely-inherited base
  class gets recompiled for every dependent (17GB RSS seen).
  1. Compile the core base classes cleanly first.
  2. Every repo script now starts lpcc under `RLIMIT_AS` (`scripts/lpcc_mem.py`, default 6 GB,
     `LPCC_MEM_GB` to change): a runaway batch dies with exit 127 / an allocation failure and the
     scan resumes after it, instead of taking the host down (two hard resets on 2026-10-11 with
     several sessions scanning at once). A hand-run lpcc or driver needs the same:
     `ulimit -v "$(python3 scripts/lpcc_mem.py)"` in the subshell first.
  3. Still poll RSS (`ps -o rss= -p PID`) on a hand run and kill by PID if it climbs.
  4. Host-wide backstop: `scripts/mem_guard.py` runs as the systemd user service `mem-guard`
     (`python3 scripts/mem_guard.py --install`; lingering keeps it across reboots). Every 2 s it kills
     by PID any `lpcc`/`driver` of this user above 10 GB RSS, and the largest one when MemAvailable
     falls under 1.5 GB; kills are in `journalctl --user -u mem-guard`. The VM wedges in swap thrash
     before the kernel OOM killer acts, so the crashes leave no OOM line in the journal.
- `lpcc_check.sh` boots a real driver and can churn saves. Re-check
  `git status` before committing.
- **A config line over 120 characters ends the config parse.** `rc.cc` reads lines with
  `getline(tmp, K_MAX_CONFIG_LINE_LENGTH = 120)`; a longer line sets failbit, the loop stops, and
  every line after it is lost. The error names the first missing required line
  (`*Error in config file.  Missing line: mudlib directory`), not the long one. It bites
  `pristine_tree.sh`/`lpc_warnings.py --tree` with a deep destination (the session scratchpad):
  the absolute `mudlib directory` path is too long and every object "kills the VM alone".
  Keep scan trees short (`$LPC_SCRATCH/lpcw-SLUG`, `$LPC_SCRATCH/listchunk-SLUG`; default `~/.cache/lpc-scratch`) or set `mudlib directory : work`. Scratch trees never go in `/tmp` (user, 2026-10-12: it takes up memory on this host).
  FluffOS 774d1783 (2026-10-09) reads whole lines (limit 1024), but the site still ships the WASM driver of release v2026.1001.0, which has the 120 limit: a committed config line of 120+ bytes boots natively and breaks only in the browser (longyunmeng_binary's 127-byte first comment line: `Missing line: name` under `wasm_client.js`). Keep config lines under 120 bytes until the release moves on; mhxy, mhxyqd, moniHuafu, sjcs and xixingzhanji lose their last few settings (stack sizes, call depth) in the browser today.

### 10.4a ASAN/UBSAN builds can be 10–20× slower on some preloads
Re-test with `build-debug` before blaming content (`nitan_san`).

### 10.5 Process hygiene (multi-session, multi-agent)
- **Kill drivers by exact PID only.** Never `pkill -f`; every driver
  shares a command line. Verify with `ps`/`ss` afterward.
- **Kill every driver you started before ending your turn.** Never kill
  one you didn't start; check `/proc/<pid>/cwd`.
- Launch long-running drivers with `setsid nohup ... & disown`.
- Don't arm a background Monitor and go quiet waiting on it. Run
  blocking commands inline.
- **Port/number collisions between concurrent onboardings:**
  ```
  grep -h '"port"' libs/*/meta.json | grep -oE '[0-9]{5}' | sort -n | uniq -c | awk '$1>1'
  ```
  Re-run this right before your own commit.
- `git checkout <rev> -- p` STAGES the result. Use
  `git restore --source=<rev> -- p`.
- **Never `git stash` in this shared tree.** Use
  `git show <rev>:<path> > /tmp/x`.
- **Commit via `scripts/safe_commit_batch.sh [--dry-run] <slug>... [+ extra] -- <msg-file>`.**
  It resets the index, stages only the owned prefixes, refuses foreign
  content, and pushes.
  - Use it even for a single onboarding: a bare
    `git add`/`commit` once absorbed another agent's 27k staged files.
  - Its per-slug `git add libs/<slug>/` can sweep in huge untracked
    saves (over 100MB). Stage by hand for libs with deferred content.
- Runtime state must not be committed (player saves, counters, bans).
  Use lib-scoped `.gitignore` patterns, never repo-wide ones (a
  repo-wide pattern once hid shipped `banned_name` content).
- Publishing: `git push origin main`. Never commit `archives/`. Never
  force-push.

### 10.6 English-language archives
Historically deprioritized. Many are now onboarded (Dead Souls,
Nightmare, Discworld, TMI-2, Lima, LDMud ports). Treat them like any
other lib.

### 10.7 Deep functional testing methodology
Boot, registration, and compile checks prove the driver starts, not
that the game works. (`bxsj`'s `quit` crashed on every exit, invisible
to the player.)

**Scope: programming bugs only.** Fix:
- compile errors;
- wrong efun usage;
- crashes;
- missing guards;
- wrong object references;
- broken state transitions.

Do NOT fix balance, prices, or internally consistent design. If you're
unsure, document the observation and leave the code.

Checklist:
1. Read the lib's own newbie help first.
2. One continuous session: register, move, learn a skill, join a sect,
   fight, quit, relogin. Run `look`/`score`/`i` at each state change.
3. Use the lib's own safe-spar mechanism (`accept_fight` stat-mirroring
   dummies) for first combat (§7.105).
4. Test sect/skill acquisition through both the teacher NPC and any
   shortcut.
5. **After `quit`, grep the logs, then reconnect after a real gap.**
   - Confirm `debug.log` belongs to THIS boot (`/proc/<pid>/fd`, mtime).
     §10.9 can leave it dead.
   - Grep the mudlib's own `error_handler` log (`/log/catch`,
     `/log/log`, `/log/log_catch`). Caught errors never reach
     `debug.log`.
   - Grep the captured driver stdout.
   - An empty catch file counts only once you've confirmed the handler
     would write.
6. Budget real time for economy and death/respawn, or state them as
   untested-live in `NOTES.md`.
   - An admin ghost stalling is usually a deliberate
     `wizardp(previous_object())` exclusion. Retry with a non-admin.
   - Test disconnects mid-action (§10.10) and a net-dead soak (§10.8).
7. Run the first session on a pristine copy (`scripts/pristine_tree.sh
   <slug> <port>`: `git archive` of the tracked files, own config, port and
   `log/`, plus the directories `scripts/wasm_keep_dirs.txt` records for the
   slug, which is exactly what the site's browser gets), not on the working
   tree: the working tree keeps directories earlier boots created and hides
   §7.203 (and, for `log/` subdirectories, a character-creation crash:
   Foundation I). Cover mail, board `post`, the editor, `eval`, death + revive
   with money (§7.204), and a disconnect at every prompt (§7.206).
   Afterwards: `log/errors/*` and the console must hold no warning (§6.10),
   and `grep "insufficient permission"` on the console must be empty (a
   `protected` function reached from another object, §6.10).
8. Fix in place, then write a dated
   `## 深度功能测试（§10.7，YYYY-MM-DD）` section in `NOTES.md`, plus a
   compact KB entry if the pattern recurs. Check §11 siblings for the
   same bug.

**Catch-up rules (2026-09-13):**
- Empty `lib_numbering.json` rows with no `libs/` dir are duplicates.
- Re-fetch the live site before claiming cards are missing.
- Never kill another agent's driver.
- Incomplete or grafted libs: document the ceiling, don't invent rooms.

### 10.8 Long-sit soaks can expose driver-fatal crashes invisible to debug.log
Seen across 6 unrelated libs, after 10–25 minutes:
- `ref count 0, but not destructed`;
- `free_string on non-shared string`;
- debugmalloc abort;
- bare segfault.

These are driver-internal and unpinned. Always capture driver stdout on
long sessions. This needs an ASan soak in `~/src/fluffos`, not mudlib
fixes.

### 10.9 `debug.log` is dead for the whole boot under the standard launch
`init_main()` opens `log/debug.log` (leading `/` stripped) BEFORE
`chdir()` into the mudlib root, and never retries. From `libs/<slug>/`
the path doesn't exist, so every later `debug_message` goes nowhere.
Always capture and grep driver stdout. The real fix is in the driver
(call `reset_debug_message_fp()` after `chdir`); it needs a maintainer
PR.

### 10.10 Multi-step `input_to()` chains don't survive reconnect
A dead-end transitional room makes it a permanent soft-lock
(`darkelib`'s character creation). Give the room its own way out, or
auto-resume on reconnect.

A resume check in the destination's `init()` fires on the normal FIRST
entry too (`move_object` calls `init` synchronously). Guard it with an
explicit flag, or it recurses and can crash the driver.

### 10.11 A self-test suite's early abort masks its tail
Run the untested subtrees directly (via `eval` on the runner's own
`recurse()`). On `sluggymud` the tail held 8 more stale-path bugs plus
a fixture that `shutdown()`s the driver after 60s. Know that before
running a whole suite live.

### 10.12 Golden-master oracle for refactors that must not change behaviour
`scripts/ds_oracle.py` + `scripts/ds_oracle.lpc` (Dead Souls family). Build two throwaway
trees, the baseline (`REV=<sha> scripts/pristine_tree.sh SLUG PORT DIR`, `REV` defaults to
HEAD) and HEAD plus the working-tree edits (`pristine_tree.sh` + `lpc_warnings.sync_changes`),
boot each, run `python3 scripts/ds_oracle.py DIR/libs/SLUG/work PORT ADMIN PW out.txt --lib`
(admin names and passwords: `dsI`/`dsII` `fluffos`/`fluffwiz123`, `dsIII` `fluffos`/`Mud@2026`,
`deadsouls_fluffos` `shopdive`/`Mud@2026`: a submodule, so run the scripts from its scratch repo (KB 02 §2.3)
with the `shopdive` save and `ed_compat.lpc` in both trees),
kill each driver by exact PID, `diff` the two files (clone numbers are normalised). Per
probed program it records the file that defines the final version of every function and
whether it is public (`function_exists` with and without the flag), every global variable
with its modifiers, ~55 getters, and dynamic behaviour (radiance, smell, a lit lamp inside a
container, save string after edits). One run takes 1-3 minutes per lib.
A pure `nosave`→`protected` sweep must produce *only* `pub`→`hid` flips: `dsII` 212 distinct
functions and nothing else, `dsI` 769 flips plus the intended `Level`→`NpcLevel` rename,
`dsIII` 1385 flips plus the intended `SetCoordinates` rename. Audit the flipped names with a
grep for cross-object callers: `apply_low` lets driver-origin calls (`create`, `init`,
`heart_beat`, `add_action`/`input_to`/`get_char`/`ed` callbacks) ignore visibility and lets
`this_object()->f()` reach protected and private functions; only a call from another
object to a protected function fails (console: `apply() with insufficient permission`).
`scripts/ds_oracle_run.sh LABEL SLUG PORT ADMIN PW HEAD|WORK [--paths FILE]` does the build,
boot, probe and kill for one side (ports at least 100 apart: a lib's INET services bind
neighbours); `scripts/ds_oracle_diff.py OLD NEW --verbose --no-visibility` prints per object
the definer changes, added and removed functions, variable count changes and getter changes.
Limits: it probes `lib/` programs (add leaf objects with `--paths`: one path per line, the files
a refactor touched), not every domain file; a value that is random per creation (HP, MaxCarry,
clone-numbered ids) differs between runs and is noise. Two things it cannot see, both found
the hard way: a *definer* row can hide an identical body (ds386's horse: `direct_mount_liv`
moved from `LIB_MOUNT` to `LIB_LIVING`, both `return this_object()->GetMount()`, read both),
and it has no row for what a dropped class's `create()` called (`SetNoSink(1)`, KB 06 7.213
kind 5): run the same scripted session on the pre-change and the changed tree
(`REV=<pre-change sha>`) and compare the transcripts, including getters you pick for the case.

**A scan can miss a file that does not compile (shadowgate, 2026-10-12).** When the master's `log_error()` writes compile errors only to `log/debug.log`, some errors ("Undefined function ...") never reach lpcc's stdout: `lpc_warnings.py` then lists the file as compiling and warning-free. Only the HEAD-vs-tree load check (`lpc_listcheck.sh` + `lpc_load_diff.py`) shows it (`d/magic/obj/rebirther.lpc` after an include was removed). Run the load check on every changed file even when the rescan is clean.

### 10.13 Porting a fix to a sibling whose files carry the same code
**Symptom:** a lib you are about to fix looks like one you already fixed (same `lib/`, same domain files), but
`patch` and the fuzzy applier (`scripts/lpc_fuzzy_patch.py`) lose hunks on it and leave files that no longer compile
(brassring after the ds386 pass: council prototypes missing, creator modules half-renamed, oob.lpc half rewritten,
45 broken files). **Cause:** the sibling is the corpus formatter's output of the same sources, so every line break
differs and a hunk's context never matches. **Fix:** compare token streams, not text (`scripts/lpc_twin_port.py
classify SRC DST --pre REV`: `twin` = DST's tokens equal SRC's pre-fix tokens). When `format(SRC pre)` equals DST's
HEAD byte for byte (the tool checks it per file), `adopt --apply` writes `format(SRC post)`: tokens identical to the
verified fix by construction, style identical to the lib (brassring: 1409 of 1508 files, 1360 byte-checked, 49
unformatted; before this, 45 hand repairs). Files with the lib's own code (`differs`) take the fuzzy applier, then
`audit` lists every token hunk SRC made that DST lacks and every difference the port removed: an empty list means
the port is complete (brassring: 12 files, each an empty `if () {}` shell, a local moved into an inactive branch or a
missing `CanGet` override; the rest was the lib's own code). **Detection:** `git ls-tree -r REV libs/` hashes show how
much of a lib is byte-identical to another (36 families of two or more libs; the largest, 33 libs around `hy5`/`wdxtym`/`haiyang2`, holds 427k files); a
formatted twin only shows up in token streams. Then rescan the lib (`scripts/lpc_warnings.py DST`): inherit overlaps
depend on the lib's other files and do not travel with a file, and neither does a removed redundant `inherit` (xyzx3 from tianxiawuxue, 2026-10-12: `npcsave.lpc` and 4 NPCs were `twin`, but tianxiawuxue's NPC base carries F_SAVE and xyzx3's `CHARACTER` does not, so adopting the dropped `inherit F_SAVE;` left `save()`/`restore()` undefined and 5 objects failed: run the HEAD-vs-tree load check after every adopt and revert the files whose removed inherit the lib's own scan never flagged; a `twin` header carries the same risk: nt7 from nt6 (2026-10-13) adopted `include/dbase.h` with the `set`/`query` prototypes nt6 had added because its `feature/dbase.lpc` defines them; nt7's dbase has only `set_db`/`query_db` and `query()` is a simul_efun, so the prototype made `query()` an undefined local in every F_DBASE object (`Undefined function called: query`) and the scan fell from 29228 to 3736 loading files. Read every adopted `.h` against the lib's own definitions, and treat a collapse of the scan's PASS count as an adopt error), and the lib's own extra classes (brassring's `factions`
and `rent`) bring their own. A live pair of sessions found two bugs the scan could not: a room whose furniture sits
in the wrong directory (the room died in `create()` before `SetExits()`, so it had no exits) and an NPC file with a
missing `;` that made its room unloadable -- both warning-free in HEAD because the file failed earlier than any warning.

**Two artifacts of the HEAD-vs-tree load check (`scripts/lpc_listcheck.sh`, `scripts/lpc_load_diff.py --fold`), found 2026-10-05.** (1) A PASS at HEAD can be spurious: a room whose NPC raises in `create()` leaves the half-built NPC loaded, and a later `load_object()` of the NPC's own file in the same VM returns it (`d/Mojie/npc/humo` passed in the batch and fails alone at HEAD). Before reading a surprising regression as one, load the object alone in a pristine tree of the old state (`REV=<commit> scripts/pristine_tree.sh SLUG PORT DEST`, then `lpcc --batch` with one name). (2) After a rename the list holds the old and the new name of an object; compare objects by case-folded path and OR the two results, or every renamed object reads as a regression (a `d.get(k) == 'PASS'` merge hid real ones, a plain last-line-wins merge hid others).

**Ways the port itself goes wrong (xkx family, 2026-10-04: `xkx2001` -> 6 siblings, 5000+ files adopted).** (1) *`splice` next to an unterminated string*: a pre-image with `set("short", "X);` shifts the string/non-string alternation of every later token, so the token diff covers most of the file and the splice rewrote Chinese text SRC never touched (`xkx2000zxb`/`shenzhou` `d/city/qiyuan2.lpc` came out as `...一幠兯�联`, invalid UTF-8). `splice()` now refuses a result that differs from DST by more than `3 * (SRC's own change) + 200` bytes. After any adopt, run a text-preservation check: for every changed file the non-ASCII characters may change only by what SRC changed (a Counter difference per file; the three bad files were the only ones of 5000+). (2) *Modifier insertions*: SRC added `varargs` to a function; the splice put it "after the previous token", i.e. a lone `varargs` line behind the previous function's `}` (valid LPC, ugly; fixed: a modifier goes in front of the next token). (3) *Insertions at the top of a file* land as ` #undef SHIP//Cracked by Kafei` on line 1. (4) *Never run the fuzzy applier over files `adopt` already changed*: the splice had put the edit somewhere slightly wrong, the fuzzy hunk matched the right place, and `xkx2000zxb` got `inherit __DIR__ "no_pk_room";` twice (32 wrapper functions from the name-winner tool), `#ifndef HARBOR_NO_WILD` twice and `varargs varargs`. Use the fuzzy applier only for `differs` files and `git diff` the result. Order of the follow-up tools: `lpc_diamonds.py --fix-redundant` first (a leaf that inherits what its base already brings needs no `skill::fn()` wrappers), then the rest; `scripts/lpc_family_pass.py` does the whole sequence. (5) *The name-winner tool reads the diagnostics of the last scan*: a scan taken before `--fix-redundant` still lists `f() inherited from both A and B` for a leaf whose second inherit has since been deleted, and the tool wrote `skill::fn()` / `clean_up::clean_up()` wrappers for a scope that no longer exists (`Unable to find the inherited function 'f' in file 'skill'`: `xbtxiii` 24 files, `xkm` 11). Rescan between the two (the pass scripts do now); if it happened, delete the wrapper lines and the `/* Two inherits define ... name it */` comment above each. (6) *A splice that deletes a token span deletes the comments inside it* (longyunmeng_binary from longyunmeng, 2026-10-15, 3718 files adopted): SRC dropped an empty `if (ob) { }` that held two commented-out channel lines and kept the comments; the splice took them out with the `if` (`adm/daemons/story/new7.lpc`). The text-preservation check shows it as lost non-ASCII text in that one file; put the comments back by hand.

### 10.14 Runtime census: load a seeded sample of every lib (2026-10-18)
**Why:** `lpc_warnings.py` compiles every file but never runs a `create()`: an NPC that raises while it is built (a missing carried item, an unknown skill, a function the host lib never had) compiles clean. **Method:** `scripts/lpc_load_census.py [--n 300] [--seed S] SLUG...` loads N random objects of each lib (tracked `.lpc` outside wizard/backup/include/data/adm dirs) in its pristine tree, one lpcc VM under a 3 GB cap, and stores the first error line of each failure in `$LPC_SCRATCH/census/SLUG.json`; `--report [--playable]` blurs numbers and quoted names and ranks the classes. Full corpus: 266 libs, 74,396 objects, 96% load (the Chinese libs 98.6%); about 2.5 hours on two streams (split the slug list in two files, one process each, each lib about a minute).
**Reading it:** (1) a master `error_handler` can swallow the driver's message, so a `FAIL` has `(no message)`: load those objects again under `catch()` (`load_object()` inside `catch`, print the string) to get the text; the real classes were `Inherited file '/u/...' does not exist`, `F_SKILL: No such skill`, `Bad argument to call_other` (0 from a missing `new()`). (2) The LDMud ports in the `playable` set (`object_name`, `foreach (x : a)`, `member`) swamp the totals: read per lib. (3) A class that shows in one lib is a sample, not a count: take the class to the whole corpus with a static scan (`lpc_scan_for_scope.py`, `lpc_fix_predefined_macro.py`, `lpc_restore_macros.py`). Found and fixed this way (2026-10-18): KB 04 6.11, 6.12, 6.13, 6.14; KB 06 7.254, 7.255; a typo `ging_cost` for `jing_cost` in 35 libs' `shuitan`; an undeclared `lvl` in 19 libs' `quanzhen-xinfa`.
**Re-run 2026-10-20 (part 17e, same seed, `--out census3`, four lanes of 67 libs, about 70 minutes):** 266 playable libs, 74,364 objects, 97% load (72,182), 2,182 failed against 2,602 (-420, -16%); all 268 libs 72,306 of 74,597 (the baseline 71,918 of 74,629). What went: `F_SKILL: No such skill` 80 -> 0 (the `set_skill()` guard, KB 06 7.256), `执行时段错误: Bad argument to call_other` 54 -> 15, `Inherited file does not exist` 41 -> 15, `Undefined variable` 151 -> 123, `restore_object` illegal format 9 -> 0, `NewRandom` 6 -> 0, `Bad assignment` 12 -> 4; most improved libs: mortremains 57 -> 24 failures, kxkjii2 30 -> 7, kxkj 32 -> 13, sunshadow 32 -> 14, ninetears 95 -> 77. What is left is the archive: missing includes (`/d/abarrach/path.h`, `message.h`, `chan.h`), bases the lib never shipped (`setup`, `CLOTH_OB`, `set_max_items`), LDMud ports (`aoh`, `acme`, `morgengrauen`: `object_name`, `foreach (x : a)`, `member`). **Reading the delta:** a lib whose tracked file count changed (+1, +2) gets a different seeded sample, so its "new" failures are other objects of the same archive-loss classes (mhxy 0 -> 4, xianlvqiyuan 0 -> 2): compare classes, not objects; a regression check is the per-object HEAD-vs-tree gate (`scripts/lpc_load_diff.py`), which was 0 for every batch.
**Wizard commands (`--cmds`, 2026-10-20):** the sample skips every path with `/wiz/`, `/wizard/` or `/adm/` (meant for wizard HOME directories), which also kept it out of the xkx family's `cmds/wiz`, `cmds/adm`, `cmds/arch`, `cmds/imm`, `cmds/creator`: no census and no fixer had compiled a wizard command. `lpc_load_census.py --cmds SLUG...` loads every file of those directories (not a sample; results in `$LPC_SCRATCH/census-cmds`): 239 libs, 26,674 commands, 26,067 load, 358 fail. Classes: `Undefined function dump_socket_status` 91 files in 77 libs, `Undefined variable` 33, `tail` 15, `query_ip_rport` 13 (KB 06 7.291, fixed), `Undefined function ansi` 12 (6 libs), syntax errors about 40, `Cannot #include obj.h.esN` / `feature.h` 21, `actions_defined` 9, `Illegal to declare varargs variable` 8, `lpc_info` 6, `opcprof` 5, `Invalid simulated efun override` 4 (the last group is left: each is a one-lib wizard tool). Read the top error KIND before calling a class a content gap, as always (KB 04 6.1).

### 10.15 Reachability census: what a visitor meets, and whether it loads (2026-10-18)
The random sample of 10.14 counts dead code and backup trees. `scripts/lpc_reach_census.py SLUG...` starts at the lib's `START_ROOM` (or `ENTRY_ROOM`, ...) and walks the literal exits of each room (`"north": __DIR__"x"`, `"/d/y/z"`, `add_exit()`), collecting the `objects` entries and literal `new()` / `carry_object()` paths of the rooms it reaches: those are the files a player meets. Static, it prints `REACH slug rooms=N objects=M dead_exits=K`; `--load` loads every room and object in a pristine tree (600 per VM boot, `(no message)` rows again under `catch()`) and prints `FAIL slug depth path error`, nearest to the start first, then `LOAD slug rooms ok/total objects ok/total`; `--dead` lists the exits of reachable rooms that lead nowhere; `--out DIR` keeps the lists.
**Numbers (2026-10-18):** 192 libs have a start room in a header (76 do not: English libs set it in code); together they reach 104,669 rooms and 40,234 NPCs and items, and only 138 exits of those rooms lead nowhere. xkx100: 2,240 of 2,240 rooms load and 785 of 786 objects (the pet dealer `oldman` named a variable `class`, KB 04 6.14); bixiecanyang: 325/325 and 135/135. The walk follows only literal exits: a room reached through a macro or a computed exit is not counted, so the figures are a floor.
**Use:** run it on a lib before and after a sweep to see the visitor-facing change, and read the FAILs by depth: a failure at depth 3 is a room every new player walks through.
**`--walk` (2026-10-19):** after the load pass, a plain NPC (`zz_rt/visitor.lpc`, `inherit NPC`) is moved into every room that loaded, in a fresh pristine tree, one `reset_eval_cost()` per room: what the room's and its inhabitants' `init()` raise is printed as `WALK slug depth room error` and `WALKED slug rooms ok/total`. The driver runs `init()` under its own error handling, so the mover sees `ok` and the error text is printed ahead of the result line: the walk attributes the printed error to the room it came from. A room that loads is reloaded here by a script with no command giver, like a timed `reset()`: that is how the eager `RANK_D->query_respect(this_player())` of xkx100's wudang disciples showed (KB 06 7.273). The visitor is not interactive, so greetings guarded by `interactive()` do not run.
**Harness artifacts (2026-10-19):** `Denied write permission in save_object()` on nitan-family warehouse rooms (`inherit WAREHOUSE`: `d/city/business`, `/clone/shop/*_shop`; 9 in nt6, 3 in xfbhh) is not a lib bug: `lpcc --batch` preloads only what the master asks for and the nitan `systemd` preloads the rest by `call_out`, so `SECURITY_D` is not loaded when the first room asks it for `valid_write()`; the census now loads `/adm/daemons/securityd.lpc` first (load it first by hand in a `listcheck` list, and the room loads). `Bad argument 1 to switch` / `Too deep recursion` from a dynamic-quest weapon (`questd` spreading `/d/npc/m_weapon/...` into a room) belong to the quest tables (KB 06, dynamic_quest sweep), not to the room that happened to trigger them.

### 10.16 Command and context play sweep: every verb, every argument shape, in a live session (2026-10-20)
**Why:** the compile scan, the census (10.14) and the reachability walk (10.15) never run a player command. A command that dies on its first `write()`, a `quit` that never disconnects, an editor callback that does not compile, a board whose room is gone: all compile or load clean and fail only when someone types the verb. xkx100 had five of those (7.284, 7.285, 7.286, `npcd` and the `heal_up` call_other in KB 06), found by the first sweep.
**Method:** (1) `scripts/play_boot.sh SLUG PORT [DRIVER]` builds a pristine tree (plus the working-tree edits of that lib unless `PLAY_SYNC=0`: a fix is tested before it is committed) and starts the driver as the transient systemd user unit `play-SLUG[-TAG]` (3 GB cap, stdout+stderr to `$LPC_SCRATCH/play-SLUG.out`, never /tmp); `PLAY_TAG=old` plus an old driver gives a second instance for an A/B run. Stop with `scripts/play_stop.sh SLUG` (the exact unit, never a pkill). (2) `scripts/mudplay.py`: `Mud` is a scriptable telnet session (IAC answered with WONT/DONT, UTF-8 with a GB18030 fallback, `cmd()` returns whatever arrived and never raises on a quiet server, `expect()`), `Console` follows the driver's output file. (3) `scripts/playsweep.py`: `Sweep.run(verbs, shapes, skip)` sends `verb shape` for every verb and shape (`SHAPES`: empty, `me`, `here`, `1`, `all`, three words, `-h`, `?`, CJK, 300 characters; `SHAPES_X` adds `%s%d%n`, `-1`, `0`, `99999999999`, `../..`, quotes, `*`), then takes the driver console lines added meanwhile and the screen text, and records `console` (a run-time error, `Warning:`, `insufficient permission`), `screen` (error text shown to the player), `needed-escape` (a prompt was open: closed with `~q`, `q`, `.`, empty lines, probing after each so no stray `quit` is sent), `stuck-reconnect` and `connection-closed` (relogin). The caller supplies the verb list (the `add_action` strings of the user/living files, the files of `cmds/*`) and a login function; wizard verbs need an admin account (a seeded one, or `level` hand-set in the save file for lpmud141).
**Login:** `scripts/play_login.py PORT` is a generic robot (it reaches the game in lpmud141, lpmud245 and xkx100 without lib-specific glue); a lib whose dialogue it cannot answer (pkuxkx wants `new` first and rations new accounts per IP; Chinese name before the password) gets a few lines of its own in the scratch dir. A lib whose master `error_handler` swallows the console (pkuxkx writes `/log/debug.log`, the player sees only a bug banner) needs that log in the `Console` too.
**Context sweep:** the same loop over what a room or an item offers: `goto` every room of a list, clone every item, run the verbs its `init()` registers (`lpmud141_ctx.py` in the scratch: 108 rooms, 35 object kinds, 1,873 lines).
**Reading it:** a pager (`q`), an editor (`.`), `converse`, a password dialog show as `needed-escape` and are not bugs; `quit` / `exit` closing the connection is `connection-closed` and the expected result (a `quit` that does NOT close is the bug, 7.286); the signal is a `console` row: reproduce it by hand, read the trace, fix, reboot with `PLAY_SYNC=1` and rerun the verb. Skip the destructive verbs (`dest`, `shutdown`, `rm`, `su`, `force`, `snoop`, ...); never run it against a unit you did not start.
**Result 2026-10-20 (FluffOS 923cdbc0):** lpmud141 mortal sweep and context sweep clean (the two `stuck-reconnect` rows are a dead-end room whose `look` prints no exit line); xkx100 mortal sweep 1,470 lines, 5 real bugs in 4 commands and the NPC daemon (`npcd.lpc` `object dest` holding a path: the daemon never compiled, `natured` threw every morning; `boss`, `news`, `to`, `exit`), the admin sweep follows the same loop with `PLAY_PW`.
**Result, wizard sweeps (2026-10-20, second batch):** lpmud141 as a level-21 wizard (490 lines) clean; lpmud245 as a wizard: the old driver's functions its commands call (`add_worth`, `filter_objects`, `create_wizard`, `wizlist`, `localcmd`, `tail`) answered `Undefined function called:` (an untyped function compiles with a call to nothing, so no compile scan sees it; KB 06 7.291); pkuxkx as a mortal (1,410 lines, 13 findings, one real: `fullme` could not write into the missing `web/antirobot`, now a keep dir); xkx100 as an admin: `cip`, `w_lian`, `clone` (`if (msg = "none")`, 7.290, which became the corpus sweep of 980 files). Order that paid: `lpc_load_census.py --cmds` first (the commands that do not compile at all, 10.14), the sweep second (the run-time errors); wizard accounts are a hand-set `level` in the save or the seeded admin (`PLAY_PW`); a wizard without a workroom answers `home` with an error, the `cost` / `clone` failures of a wizard whose `pwd` is polluted are artifacts, not bugs.
**Login survey:** `scripts/play_survey.py [--all] [SLUG...]` runs the boot, the generic login (`play_login.py`) and the first commands for every lib in turn and reports one line each (result, driver errors during the boot and during the login): the run-time path that a load gate never walks (registration, `init_new_player()`, the first `look`). The robot decides on the prompt line first (a welcome screen that mentions "password" does not answer a name prompt), takes a creation menu's `0 - Done`, knows `y(es) or n(o)` and "By what name do you wish to be known?" (TMI-2 / Genesis); a `stuck` row is a dialogue the robot cannot answer, to be walked by hand.
**Survey columns and checks (2026-10-20, third to sixth batch):** one row per lib: `result` (`in` / `stuck` / `closed` / `noboot`), `steps`, `boot_errors`, `play_errors`, the first error line, the last prompt, `saved` and, with `--relogin`, `relogin`. `saved` counts the files whose path has `sweepzq` in it (the robot's character: `data/user/s/sweepzq.o`, or `data/user/s/sweepzq/login.o` for a per-user-directory lib such as xkyx3b) in the unit's tree after the `quit`; an `in` row with 0 is a character that was not persisted (yhyxcs: `valid_write()` compared the save file without the `.o` and recursed, KB 06 7.309; the three Discworld libs: the letter directory did not exist, 7.315) or a false `in`: the robot took a name prompt for the game (nte and the nitan family until it learned that a dialogue redisplays its prompt for `zzqxk` and that Chinese names are two characters; lpuni `Please select a name:` answered `1`; dtslmud has no name prompt at all and saves its first line as the name), or a lib with no accounts (`paomud`, `scratch`). skylib and Discworld refuse `save` in the first minute (`Sorry, you must be at least one minute old to save.`), but their quit and net-dead saves write the file, so 0 there is a finding. `--relogin` logs in again as the same character when something was saved (`in:0`, `stuck:0`, `closed:2:first console error`): a character that saves and does not load again is a restore or password-check bug. A second visit right after the quit is refused by design in many libs (the xkx family: `您刚刚断线，20秒钟之内不能连线进入`; jhfy3: 120 s; an ES quit finishes a few seconds after the link closed and the next visit meets the old body and its pending quit), so a `closed` second visit is retried after 25 s and again after 100 s before it is reported (25 `closed:0` rows of the first pass were this); the Discworld menu cannot be re-entered by the robot (`N` is New character, a name already taken is refused: use one letters-only name per visit, and the name `sweepa1` is invalid). A console count is not a verdict either way: `play_errors` also counts the driver's native stack trace printed when the unit is stopped while it is still busy. **What the first full pass turned up** (260 libs, KB 06 7.292-7.315): 114 in / 93 stuck / 51 closed / 2 noboot, most stuck rows being the robot; the robot's rules grew per family (a student-age question answered `no`, an admin and a normal password that must differ, `pick human` for Dead Souls, `[10-30]` ranges, `例如：20 20 20 20`, ES1's English race names, the Discworld licence pause, a slow first answer, `or "new" to create`, `select a name`), and a stuck row is worth walking by hand with `play_login.py PORT` (the transcript is the evidence) before blaming the lib. To find which call denies what, boot with `PLAY_TAG=dbg scripts/play_boot.sh SLUG PORT`, stop the unit, put a `debug_message()` into the scratch tree under `$LPC_SCRATCH/play-SLUG-dbg/`, and start it again with `systemd-run` (the tree is throwaway; the repo is untouched).

**Verb sweeps with the generic runner (2026-10-20):** `scripts/play_sweep_lib.py SLUG` takes the verbs from the command directories and runs them with the robot's login (a per-lib glue script is only needed for a lib the robot cannot enter). A command-throttling lib needs `--burst PACE`: Discworld queues every command after the first (`Queued command: i`) and answers it a heart beat later, so a per-line probe sees the previous answer, reports every verb as `needed-escape` and, because the womble in the start room never lets the connection go quiet, spends 12 s per line waiting for a quiet gap; sending a verb's shapes 1.3 s apart and reading the console once per verb takes 22 s per verb (176 verbs in an hour). Use one letters-only name per visit (`sweepaa`, `sweepab`...: Discworld refuses digits and an existing name at `N`), and remember that a tracked job outlives a lib's own timers: Discworld shut itself down 20 minutes after the boot (KB 06 7.319), which looked like `robot did not get in` (`It is too close to the shut-down`). `play_boot.sh` follows the driver's own `Accepting telnet connections on 0.0.0.0:N` line when a lib's config names its port outside `port number` (shadowgate: `external_port_1 : telnet 40246`; the survey had called it `noboot`), and the survey waits until the console has been quiet for 8 s before the robot logs in (nt1's `closed` daemon restores ~1000 users on its first heart beat and the first answers were silence).
