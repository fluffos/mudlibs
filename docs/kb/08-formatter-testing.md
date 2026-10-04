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
  - eval-cost accumulating across a batch.

  Confirm against a real boot. `lpcc` FAIL with a live boot OK is a
  known artifact when `create()` touches missing content.
- **Memory:** batch mode never unloads. A broken widely-inherited base
  class gets recompiled for every dependent (17GB RSS seen).
  1. Compile the core base classes cleanly first.
  2. Poll RSS (`ps -o rss= -p PID`).
  3. Kill by PID past ~10GB.
- `lpcc_check.sh` boots a real driver and can churn saves. Re-check
  `git status` before committing.

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
(admin names and passwords: `dsI`/`dsII` `fluffos`/`fluffwiz123`, `dsIII` `fluffos`/`Mud@2026`),
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

