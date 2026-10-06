# AGENTS.md — handbook for restoring and polishing these mudlibs

The knowledge base for the `fluffos/mudlibs` restoration project
(mudlibs.fluffos.info). Read the section for your task before touching a
lib. Most problems you'll hit have been hit before and are cataloged in
`docs/kb/`.

**Layout.** This file holds only the operating rules: conventions,
safety rules, process, and an index. The technical knowledge base (every
bug class, the playbooks, the lineage map) lives in `docs/kb/`, one file
per topic. §-numbers are stable, so lib `NOTES.md` files can keep citing
`§7.86` and the like; look the number up in the index below. The frozen
pre-split long edition, with every per-lib case history, is
`docs/agents-catalog-full.md`.

**State.** `README.md`'s table and `scripts/lib_numbering.json` hold the
current lib count and statuses. Don't trust numbers in prose. The
WASM-conversion and §10.7 deep-test campaigns are done for the existing
corpus. To find work:
- Run `grep -L '深度功能测试' libs/*/NOTES.md`. Any `playable` lib
  without a dated §10.7 heading is the next candidate.
- Re-test passes use dated headings (`深度功能测试（YYYY-MM-DD…`).
- The live queue is `scratchpad/librarian-next.txt`.

**Numbering.**
- `NNN` per unique game; `NNN-M` for confirmed derivatives of the same
  codebase; `9xx` for non-LPC archives.
- English version stacks follow the same rule: Dead Souls = `006`,
  Nightmare 3/4 = `160`, Foundation I/II = `174`, Discworld v1–v3 = `901`,
  LPMud 1.4.1/2.4.5 = `941`.
- Different games that only share an engine keep their own numbers. Do
  not fold `dshakkard`/`riftsds`/`brassring` into Dead Souls,
  `swmud`/`spacemud` into Lima, `mortremains` into TMI-2, `residuum` into
  Nightmare, or Majik 3 into Majik 4.
- Refer to libs by slug (`libs/<slug>/`) and number. Never refer to them
  by "archive #N" or by a machine-local path.

## Conventions

- **Git:** commit on `main` and `git push origin main`. Agent work gets
  no topic branches and no PRs. External contributors may still send PRs.
  `fluffos/fluffos` (the driver repo) is the exception: always open a PR
  there.
- **Upstream rebase runs from an agent-armed timer, never a GitHub
  Action.**
  - The timer is a `cursor-subscriptions` `subscribe_timer` named
    `mudlibs-upstream-rebase`, cron `0 4,16 * * *` UTC. List timers first
    and dedupe by name.
  - When it fires: run `scripts/rebase_upstreams.py`, commit and push the
    safe pin bumps, watch Pages CI, and open or update the patch-failure
    issue.
  - Do not recreate `.github/workflows/upstream-rebase.yml`.
- **Document as you go, in the same turn.** Reusable traps go in the matching
  `docs/kb/` file as a compact entry (symptom → cause → fix → detection,
  3–10 lines; the long story goes in the lib's `NOTES.md`). Standing
  policies go here. Plans and leftovers go in `scratchpad/librarian-next.txt`,
  dated; mark them done so they don't get re-queued. Findings go in the
  lib's `NOTES.md`, in Chinese. Code without the matching doc update is
  not done.
- **Builds:** `~/src/fluffos` is one source tree with three builds:
  `build-debug/` (use for mudlib work), `build/`, and `build-wasm/`.
- **Lib layout:** `libs/<slug>/{config.fluffos, work/, raw/, NOTES.md,
  README.md, meta.json}`.
  - `work/` is the playable tree, UTF-8, with `.lpc` files.
  - `raw/` is the pristine extraction. It is gitignored; regenerate it
    with `scripts/extract.sh`.
  - `hosting` (§2.3) is `vendored` (the default), `submodule-patch`, or
    `fluffos-upstream`. Clone with `--recurse-submodules`.
- **Ports:** every lib has a unique port, recorded in `config.fluffos`,
  `meta.json`, and the README table. Before assigning a new one, take the
  current max from `lib_numbering.json` and re-check for collisions right
  before committing (§10.5).
- **§9 formatter (KB 08):** run it on every lib whose `.lpc`/`.h` files you
  edited, check its three blind spots, then re-boot and re-test.
- **Compile warnings are bugs (user, 2026-10-03).** A mudlib never carries
  `#pragma no_warnings` (not in `global.h`, not per file), and every warning
  the driver prints is fixed at its source. Scan with
  `scripts/lpc_warnings.py <slug>`; the classes and their fixes are KB 04
  §6.10. A lib whose files carry the same code as one already fixed takes
  the fix with `scripts/lpc_twin_port.py` (KB 08 §10.13), not by hand.
  Do not hide a warning to quiet the first visitor's screen.
- **Ranges count from the end with `<`:** `[0..<2]`, `[<2..]`. A negative
  literal (`[0..-2]`, `[-2..]`) is empty or the whole value in this driver
  (KB 06 §7.209). Never switch on `old range behavior`: it covers
  strings only, not arrays.
- **Slugs** are short pinyin initials of the Chinese name: `bxsj`
  (书剑天下), `yhyxcs`. Roman numerals become digits (`Ⅱ` → `2`). Add a
  suffix only to disambiguate siblings. To rename a slug:
  1. `git mv` the directory.
  2. Update `meta.json` `slug`.
  3. Fix the `mudlib directory` path in `config.fluffos`.
  4. Grep the whole tree for the old slug and replace it.
  5. Re-run `python3 scripts/gen_keep_dirs.py`. If you skip this, the
     site ships without the needed empty runtime dirs, and every WASM
     connection dies silently on its first `write_file()` into a missing
     `log/` dir.
- **`meta.json`** holds lightweight structured data only: number, slug,
  archive, name, wasm_status, port, duplicate_of, hosting, upstream,
  english_description. Prose about fixes goes in `NOTES.md`.
- **Site descriptions describe content, not changes.**
  `english_description` and the README intro paragraph say what the game
  is. No bug, porting, or QA narrative.
- **Preservation over throughput.** Read the actual rooms, NPC dialogue,
  and quests before writing a README. Lineage is history worth recording.

---

## Knowledge base index (`docs/kb/`)

| File | Sections | Covers |
|---|---|---|
| `01-wasm-site.md` | §1 | WASM build and test, WASM gaps and the loopback policy, triage, admin seeding, site packing, SEO and the publish invariant, the ZJ protocol adapter |
| `02-pipeline.md` | §2–§3 | bring-up steps, definition of done, the on-sight grep checklist, hosting modes (`vendored`/`submodule-patch`/`fluffos-upstream`), LDMud port policy, archive extraction traps |
| `03-encoding-config.md` | §4–§5 | GB18030/BIG5 conversion, `.o` CRLF, `.c`→`.lpc` fallout, `static`→`nosave` collisions, BIG5 `0x5C`, config and ports |
| `04-compile-classes.md` | §6 | includes, missing efuns, grammar strictness, binding order, reserved words, compiler warnings (§6.10) |
| `05-runtime-classes-1.md` | §7.1–§7.60 | ACL, `restore()`, missing dirs and `log_file`, message wrappers, nitan dbase, re-entrancy, death/netdead, sockets, eval-cost |
| `06-runtime-classes-2.md` | §7.61–§7.233 | `replace_program` (§7.86/§7.100), float/int, autoload, LDMud/TMI/Nightmare/Dead Souls/Genesis/Lima-specific traps, simul_efun overrides vs the sefun's own files (§7.221), the master's `author_file`/`domain_file` boot probes (§7.222), CD `map`/`filter` over mappings (§7.223), per-object CD alarms (§7.224), seeded CD `random` (§7.225), include checks that depend on the master's euid (§7.226), the Nightmare players-dir `else if` (§7.227), LDMud `reset(0)` at load (§7.228), LDMud compat sefuns `member`/`extract` (§7.229), `modify_command` → `process_input` (§7.230), two-argument `move_object` and shadows (§7.231), a fragment rebuilt as a standalone class (§7.232), one variable name saved twice (§7.233) |
| `07-login-classes.md` | §8 | Chinese detection (§8.1), dead command dispatch (§8.3), encoding menus, registration/relogin bugs |
| `08-formatter-testing.md` | §9–§10 | formatter blind spots, verification bar, client tools, lpcc sweeps and memory, process hygiene, §10.7 deep-test method, the debug.log-is-dead trap, §10.12 golden-master oracle (before/after diff for behaviour-neutral refactors) |
| `09-lineage-driver.md` | §11–§12 | lineage map, driver patches, `MARCH_NATIVE` SIGILL, WASM terminal |

When looking up a §-number: §1→01, §2–3→02, §4–5→03, §6→04,
§7.1–7.60→05, §7.61+→06, §8→07, §9–10→08, §11–12→09. A grep across
`docs/kb/` finds any symptom string.

### Quick start
- **New archive:** KB 02 §2 (steps), then §2.2 (checklist), then KB 03
  (encoding).
- **Lib won't boot:** KB 05 §7.1–§7.3, §7.43, §7.175; KB 04.
- **Registration or commands broken:** KB 07 §8.1, §8.3; KB 05 §7.5.
- **WASM-only failure:** KB 01 §1.3.
- **Before any playtest:** KB 08 §10.7 (scope + checklist), §10.9
  (`debug.log` may be dead).

---

## 13. Process and operating conventions

These are operating rules. When a process question here conflicts with
a KB file, this section wins.

### 13.1 Role
You are the curator of `fluffos/mudlibs`. There are two open-ended
mandates with no completion target:
1. **Quality.** Find and fix genuine programming bugs (§10.7), keep
   descriptions accurate and content-only, keep WASM statuses honest.
2. **Discoverability.** Bilingual site (English default, Chinese at
   `/zh/`), JSON-LD/sitemap/`llms.txt`/`games.json`, and onboarding
   genuine new mudlibs. Submit the sitemap to Search Console/Bing after
   SEO changes.

### 13.2 Act, don't ask
- Make the reasonable call and proceed: edit, commit, push to
  `origin/main`, then pick the next task.
- Ask only for destructive or irreversible actions outside the
  established pattern, or for genuine product decisions.
- Document as you decide (see Conventions). A playtest without its dated
  `NOTES.md` section is incomplete.
- There is no stopping condition, but don't manufacture busywork. When a
  channel is dry, say so and downshift to periodic review.

### 13.3 Hard safety rules
- **Never `rm -rf` `data/login/<letter>/` or `data/user/<letter>/`.**
  These are letter buckets shared by real players. Delete only the
  specific test files you created, by exact name, and run `git status`
  right after.
- Never derive a bulk-delete list from `git status`.
- **Never `pkill -f` a driver.** Kill by exact PID, and verify. Kill
  every driver you started before your turn ends; never kill one you
  didn't start.
- **Use `git add -u <path>` or explicit paths**, never a bare directory
  add (it sweeps untracked saves).
  A bare `git commit` also takes whatever is already staged, and `git mv` / `git rm` (and
  `scripts/lpc_case_paths.py`) stage on their own: commit with a pathspec
  (`git commit -m ... -- libs/<slug>`) so one lib's renames do not ride in another lib's commit.
- **Never force-push, `reset --hard`, rewrite history, or `git stash`
  in this shared tree.** Fix forward with additive commits. A leaked
  secret gets redacted in a new commit.
- No `$(...)` in Agent/SendMessage params. Inline the text yourself.
- Don't invent URLs.
- Never boot a lib with a big `data/closed.o` without a memory cap
  (§7.110).

### 13.4 Verification discipline
- After concurrent commits, `git fetch`, then run
  `git show origin/main:<path> | grep -c <marker>` per file, one command
  each (not in a loop). A clean merge exit can still have dropped
  content.
- A grep-"confirmed" sibling bug is only a candidate. Check that every
  symbol the fix uses exists in the target, then live-verify.
- Proof needs a fresh process. A retry in the same driver can pass only
  because the expensive compile is already cached.
- A scripted multi-step test must validate each response before sending
  the next input.
- "N of M entities share a pattern" is not a bug by itself; it can be
  deliberate per-entity design (§7.116 retracted). The tell for a real
  bug is a mechanical failure.
- Absence-triggered fallbacks are often intended (§7.68). Verify live.
- Before filing an upstream driver bug, build a minimal repro on a fresh
  build.
- Check each claim in a security warning independently against
  `git show`/`git log`/`reflog`.
- Log silence is not a hang. Use `nc -zv` or a real client before
  concluding a stall.
- A quiet `debug.log` is not a clean test (§10.7 item 5, §10.9).

### 13.5 Subagents
- Run at most 1–2 at a time, especially for CPU-heavy boots or `lpcc`.
- Brief each one fully and self-contained, including commit/push/cleanup
  rules.
- Silent ≠ stalled. Check with
  `find <dir> -type f -newermt "<time>"`.
- After 45+ minutes truly silent despite a SendMessage nudge:
  `TaskStop`, then inspect `git status`/`git diff`; work is usually
  recoverable.
- Unbounded RSS growth means intervene even if the agent still responds.
- Resume a stuck agent with SendMessage to its id. Don't spawn a
  duplicate without stopping the original.
- Inconsistent fork results may mean your own turn was redirected into a
  fork. `git fetch` and check ancestry; never force.

### 13.6 Sweeps and picking what's next
- A bug confirmed independently in **3+ unrelated lineages** gets a
  mechanical corpus sweep:
  1. Grep the exact shape.
  2. Read each hit.
  3. Fix every one.
  4. Spot-boot a sample.
  5. Commit as a batch.
- **Pick the next targets at the END of a cycle**, and leave a queue (3–4
  playthroughs) in `scratchpad/librarian-next.txt` and the timer prompt.
- When the user checks in, give a synthesis and a recommendation, not an
  activity log.

### 13.7 File-editing mechanics
- **Use binary mode (`rb`/`wb`) for scripted edits.** The corpus mixes
  CRLF and LF within files, and text mode or the Edit tool can normalize
  them. Check `git diff --stat` after every edit.
- `lpcc_check.sh` churns saves (re-check `git status`). Its eval-cost
  failures may be batch artifacts (§10.4).

### 13.8 Domain conventions
- `meta.json` is the source of truth. Run
  `python3 scripts/assemble_numbering.py` after editing it.
- Never hand-edit `lib_numbering.json`, `wasm_status.json`, or
  `upstream_status.json` (generated).
- Descriptions are content, not a changelog. Bugs go in `NOTES.md`.
  Never reference `boot.log`/`debug.log` scratch files in docs.
- Deep-test scope is programming bugs only (§10.7).
- Framework similarity (byte-identical master) and content similarity
  (`kungfu/`+`d/` overlap) are separate signals. Titles prove nothing.
- Binary-only archives are `binary-pending-tooling`.
- `noboot` libs are out of scope unless their structural blocker gets
  resolved. `realms` needs MySQL; don't retry it.

### 13.9 Discovery/onboarding policy
- **Museum inclusion criterion (user, 2026-10-03).** The museum holds
  only old archives, plus active libs that have an existing user base or
  a long history of development. We do not incorporate new
  experimental libs: no learning projects, skeletons, prototypes, young
  still-moving hobby repos, or testbeds for a custom driver (e.g.
  `dyher/mudlib_ro`: two weeks old, three rooms, needs
  `sqlite3_*`/`websocket_accept` efuns FluffOS lacks).
- **Focus on libs that have history.** Effort goes to the historically
  significant libs already in the collection: LPMud 1.4.1/2.4.5, TMI-2,
  Nightmare, Dead Souls, Discworld, Foundation, Lima, Genesis, Final
  Realms, the Eastern Story/xkx roots, and similar (KB 09 §11 English
  stacks and ES II family). Do §10.7 re-tests (thinnest or oldest
  coverage first), bug sweeps, description accuracy, WASM-status
  honesty. Onboard a new lib only if it is substantial, stable and
  historically meaningful, or the user names it.
- Existing libs that fail the criterion are listed in
  `scratchpad/librarian-next.txt` for the user to decide on. Do not
  delist or delete a lib on your own.
- Broad discovery grinding is **paused** (2026-09-04). The ~weekly
  `gh search repos --created=>DATE` re-sweep is now check-only. Last
  run 2026-10-03 (cutoff `>2026-09-12`); next ~2026-10-17 with
  `>2026-10-03`.
- Don't onboard zayaville.
- A **specific named lead** from the user is NOT paused. Chase it
  thoroughly.
- Don't post public GitHub issues or comments without the user's OK.
  Edit your own comment in place (`gh issue comment <n> --edit-last`).

### 13.10 Environment gotchas
- `node`/`emcc` missing in a subagent: PATH lives in `~/.zshenv`. A
  stale shell snapshot
  (`~/.claude/shell-snapshots/snapshot-zsh-*.sh`) may re-clobber it.
- In LPC, `(int)` is a compile-time no-op on floats. Use `to_int()`.
- Watch absolute RSS on long `lpcc`/driver runs; a host OOM needed a hard
  reset once.
- On every resume or wakeup, re-arm the timer, and verify real state
  before trusting the resume prompt's framing.
- Live-clock prompts defeat quiet-gap readers (§10.2).

### 13.11 Repo hygiene
Never commit or cite runtime logs. Omit investigations that reached no
conclusion.
