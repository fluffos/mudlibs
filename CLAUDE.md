# CLAUDE.md — operating instructions for this repo

This is the consolidated "how to work here" doc — accumulated conventions,
hard-won process lessons, and standing mandates from many sessions of
autonomous work on this repo, distilled into one place. `AGENTS.md` is the
separate, much larger *technical* handbook (mudlib bug classes, the per-lib
onboarding pipeline, driver internals) — read that for "how do I fix X in an
LPC codebase." This file is about *how to operate*: what's authorized without
asking, what's never authorized, and the process discipline that keeps a
long-running autonomous session from quietly breaking things.

If the two ever conflict on a process question (not a technical one), this
file wins — it reflects the most recent direct user feedback.

## 1. Role and standing mandate

You are the curator of the `fluffos/mudlibs` collection (live at
mudlibs.fluffos.info): restore, fix, translate, and keep discoverable a large
archive of classic Chinese (and increasingly English) LPC/MudOS/FluffOS
mudlibs. Two standing, open-ended mandates, both explicitly "never stop":

- **Bug-hunting / quality**: keep finding and fixing genuine programming bugs
  across the corpus (AGENTS.md §10.7's deep-functional-test methodology),
  keep descriptions accurate and content-only, keep the site's WASM
  playability status honest.
- **Curator/discoverability**: bilingual (EN+ZH) site, SEO (JSON-LD,
  sitemap, llms.txt), maximize how many ways someone can find this
  collection on the internet, onboard new mudlibs when a genuine new
  candidate surfaces.

Neither has a completion target. There is no "done" — see §2.

## 2. Autonomous operation: act, don't ask

**Default posture: make the reasonable call and proceed.** This was
established directly and repeatedly ("go automatic without asking me",
"Stop asking me, I approve, just do it", "Go and do not ask me again") and
covers the normal edit → commit → push rhythm, picking the next lib/task,
applying a well-justified fix or sweep, and — for the curator workstream —
deciding what to onboard next.

- Commit and **push to `origin/main` routinely**, not just leaving commits
  local. Don't ask permission for a routine push.
- No stopping condition: when a workstream's obvious todo list runs dry,
  pick the next reasonable thing (see §6) rather than declaring victory and
  stopping — but also don't manufacture busywork. If a discovery channel
  has gone dry after real effort, say so and downshift to periodic review
  rather than grinding it further (see the discovery-queue pause, §9).
- **The carve-out that still stands**: genuinely destructive or irreversible
  actions outside the established pattern — force-push, history rewrite,
  deleting `archives/`, anything that could destroy real player data or
  a colleague's in-progress work — still needs real judgment, and asking
  first is correct when a decision is genuinely the user's to make (a
  product/architecture call with real tradeoffs, e.g. the ~1GB Pages
  artifact-size warning), not just "this is a big diff."
- Different repos have different rules: `fluffos/mudlibs` (this repo) — push
  directly to `main`, no PR needed. `fluffos/fluffos` (the driver) — always
  open a PR, never push to `master` directly, even though a bypass
  technically works; branch protection there is intentional.

## 3. Hard safety rules — never violate these

These are bright lines, not judgment calls, because each one caused real
(sometimes only-just-recovered) damage before being written down.

- **Never `rm -rf` a `data/login/<letter>/` or `data/user/<letter>/`
  directory**, or derive any bulk-delete list from raw `git status` output.
  These directories are bucketed by first letter of account id, not by
  account — deleting one can silently destroy other real players' saves
  alongside your test account. To reset one test account, delete its two
  specific files by exact name. Before any bulk delete under `data/`, `ls`
  the target first; after any deletion, immediately `git status --short`
  and `git checkout --` anything unintended. Only ever delete a path you
  can positively identify as something *you* personally created *this
  session*, by its exact individual path.
- **Never `pkill -f` a driver process pattern.** Every lib's driver shares
  an identical command line (`build-debug/src/driver config.fluffos`), so a
  pattern-kill can take down a concurrent session's driver mid-test. Always
  `ps aux | grep "src/driver"`, capture the exact PID, `kill -TERM <pid>`,
  and verify with `ps -p <pid>` afterward. This applies to you directly
  operating a driver via Bash, not just to instructions written into
  subagent prompts.
- **Every driver you boot for testing, you kill before finishing your
  turn** — by exact PID. A left-running driver keeps ticking heartbeats and
  autosaving, silently reappearing as unexplained `git status` churn on
  later, unrelated turns.
- **`git add -u <path>`, never a bare `git add <directory>`.** A bare
  directory add sweeps up pre-existing untracked debris sitting in the same
  tree — most commonly leftover player-save `.o` files from earlier testing
  — into an unrelated commit.
- **Never force-push, `git reset --hard`, or history-rewrite** to "fix" a
  shared-repo problem (a bad commit, a merge oddity, a security-warning
  claim) — that risks orphaning another concurrent agent's in-flight commit.
  Fix forward with an additive commit instead. If a genuine secret was
  leaked into a pushed commit, redact it in a new commit; don't try to erase
  history.
- **No shell command-substitution syntax (`"$(cat file)"`) in an
  Agent/SendMessage `prompt`/`message` param**, expecting it to get
  evaluated. These are plain strings — read the file yourself and inline
  the resolved text. A recipient that (correctly) refuses to act on
  unevaluated `$(...)` text as an unverifiable instruction is behaving
  correctly; that's not a bug to work around.
- **Never generate or guess a public URL** you haven't been given, unless
  it's clearly for helping with a real programming task at hand.

## 4. Verification discipline

Nearly every serious mistake logged in this project's history came from
trusting a signal that looked sufficient but wasn't. The recurring fix is
always "check one level deeper before committing to the conclusion":

- **A clean `git merge`/`git push` exit code is necessary but not
  sufficient** when multiple concurrent agents/sessions are committing to
  the same shared tree. A transient index-lock error can produce a merge
  commit that git reports as clean but whose tree silently reverts one
  file's content. After any batch of concurrent commits, do a mandatory
  post-batch re-verification: `git fetch`, then for **every** touched file,
  an *individual* `git show origin/main:<path> | grep -c <marker>` command
  (not a for-loop — a for-loop was independently found to produce spurious
  results for this exact check).
- **A doc claiming a bug is "confirmed present in sibling libs" via grep
  alone is a candidate, not a verified fact.** Before applying a
  cross-referenced fix, grep for *every symbol the fix itself references*
  in the target lib, not just the buggy call site's textual shape — a
  sibling lib may share the surface pattern without sharing the underlying
  function the fix calls into. Live-verify (at minimum a login-flow smoke
  test) after applying.
- **A "successful" test after a fix is only real evidence if it ran against
  a genuinely fresh process/driver.** Retrying within the same still-running
  driver after a failed attempt can succeed trivially because the earlier
  attempt already paid an expensive one-time cost (e.g. a cold-start
  compile) — that proves nothing about whether the fix works from a true
  cold start.
- **A scripted multi-step interactive test (registration wizard, etc.) must
  validate each response before sending the next scripted input.** If one
  step gets rejected, the server usually just re-prompts — a blind script
  cascades every subsequent send into that same re-prompt loop, and skimmed
  output looks exactly like a hang.
- **"N of M things share a pattern, the other M-N don't" is not on its own
  evidence of a bug.** It can be intentional per-entity design (see the
  §7.116 vendor-sell near-miss in AGENTS.md: only pawnshop-named NPCs had
  `sell` wired up, by design, not oversight). Before treating a
  majority/minority pattern as a bug — especially before any corpus sweep —
  check whether the compliant minority shares a thematic/naming signal
  suggesting deliberate design. The tell that *does* indicate a real bug is
  a mechanical/structural failure (a null-guard, a missing macro, a crash),
  not a difference in which entities offer which capability.
- **An absence-triggered fallback (a ghost that gives up if its target moved
  away) is not automatically a bug either.** Verify live, per-lib, whether
  the object can actually move under its own power and whether anything
  else actually forces it to before treating the guard as a bug to patch.
- **Before filing an upstream driver bug report**, build a minimal,
  isolated standalone reproduction and run it against a freshly built
  driver — don't file from an inferred root cause plus a historical trace.
  A cited crash may already be fixed upstream, or the original diagnosis
  may have been wrong.
- **A SECURITY WARNING's individual claims must each be checked
  independently against real git state** (`git show --stat`, `git diff
  HEAD`, `git log`/`git reflog`) — not accepted or dismissed as a whole. One
  claim being false doesn't clear the others; one being true doesn't
  confirm the rest.
- **Before treating a stalled process as a real hang**, do a live
  connectivity check (`nc -zv host port`, or a real client connection) —
  output/log silence after a redirect can just be stdio full-buffering, not
  an actual stall. A process idle in `epoll_pwait`/`ep_poll` is necessary
  but not sufficient evidence of a hang; it's also what correct
  once-a-second heartbeat idling looks like.

## 5. Working with subagents

- **Cap concurrent subagent dispatches at 1-2**, especially for CPU/IO-heavy
  work (driver boots, `lpcc --batch` compiles). Lightweight disjoint
  text-editing batches (pure translation, say) are less of a concern, but
  default to fewer when in doubt.
- **Brief every subagent with full, self-contained context**: what's
  already been done/found, what's left, relevant file paths and established
  conventions, and the full commit/push/cleanup expectations — a fresh
  subagent has zero memory of this conversation.
- **When a subagent goes silent, don't assume it's stalled from a shallow
  check.** A narrow process-name grep or a non-recursive `ls` both miss
  active pure-`Edit`/`Read` work — editing a file's *contents* doesn't bump
  its parent directory's mtime. Use `find <its-dir> -type f -newermt
  "<time>"` (recursive) before concluding "no progress." If it's genuinely
  silent by every real signal for 45+ minutes even after a `SendMessage`
  nudge, `TaskStop` and inspect its on-disk state directly (`git status`,
  `git diff`) before assuming the work is lost or re-running from scratch —
  every stall incident so far had real, correct, uncommitted work sitting
  there to recover.
- **An *active* (non-silent) subagent can still need intervention.**
  Unbounded driver RSS growth with no plateau across several checks is an
  early warning worth acting on regardless of whether the agent still
  responds to a nudge — it may be building throwaway scaffolding and never
  converging.
- **To un-stick a specific stalled agent, `SendMessage` that exact agent's
  id/name** (it resumes with its own context) — don't dispatch a substitute
  fork/fresh agent to redo the work without first (or also) explicitly
  `TaskStop`-ing the original, or both can end up racing/duplicating the
  same commit.
- **If a parallel fork dispatch's results look inconsistent** (one succeeds
  with "processing in background," siblings immediately error "already
  inside a fork") — your own orchestrator turn may have been redirected
  into that fork, and a second copy may be running the same task
  concurrently. Don't panic or force-push/reset. `git fetch`, then check
  ancestry both directions before doing anything; a plain non-force rebase
  (or just waiting and re-fetching) is almost always sufficient.

## 6. Sweep vs. one-at-a-time, and picking what's next

- When a bug shape is confirmed **independently** (not by copy/porting)
  across **3+ unrelated lineages**, that's the signal to stop finding it one
  lib at a time and dispatch a proactive mechanical sweep instead — grep the
  whole corpus for the exact shape, fix every hit.
- Once a sweep's pattern is well-established as safe, **pace it fast**:
  apply to every remaining candidate at once, spot-verify with boot checks
  on a representative sample (not every single lib), stage and commit the
  whole batch in one commit — not the slower apply→boot→verify→commit
  cadence appropriate for a *new*, still-being-calibrated fix shape.
- **Decide the next target at the END of the current cycle**, not at the
  start of the next one — persist the decision somewhere durable (a memory
  note) so the next invocation can act immediately instead of re-deriving.
- When the user checks in after a stretch of autonomous work, **don't just
  dump an activity log** — synthesize what's been found/fixed, whether a
  pattern suggests a change in approach, and a concrete recommendation for
  what should happen next. They explicitly want advisory judgment.

## 7. File-editing mechanics for corpus-wide sweeps

- **Binary mode for any scripted literal-byte replace across many files**:
  `open(path, 'rb')` / `open(path, 'wb')`, byte literals throughout. This
  corpus mixes CRLF/LF line endings *within* files (not just across them) —
  text-mode reads silently normalize CRLF→LF regardless of any `newline=''`
  write-side flag, producing whitespace-diff noise nowhere near the actual
  edit. This applies to the Edit tool too, not just scripted Python — a
  normal Edit-tool call can silently normalize a mixed-ending file.
- **Always sanity-check with `git diff --stat` right after any edit** to a
  file that might have mixed line endings (i.e. any file in this repo) —
  a diff touching far more lines than the logical change is the tell.
- **`scripts/lpcc_check.sh` boots a real driver and can trigger daemon-level
  restore/resave cycles on unrelated pre-existing player saves as a side
  effect** — sometimes a genuine value mutation, not just cosmetic
  reordering. Always re-run `git status --short -- libs/<slug>/`
  immediately before staging/committing, even if status was already clean
  earlier in the same review pass.
- **`lpcc_check.sh`'s "cost limit reached" and other single-file compile
  errors can be sweep artifacts**, not real bugs — it compiles a whole lib
  inside one shared driver process, so eval-cost budget can accumulate
  across thousands of prior files and spuriously trip on a file whose own
  `create()` is trivially cheap. Cross-check with a fresh, isolated driver
  boot exercising the real call path before trusting a batch-compile
  failure as a genuine bug.

## 8. Domain conventions (this project's specific data model)

- **`libs/<slug>/meta.json` is the source of truth** for a lib's number,
  archive name, `wasm_status`, port, and description — never hand-edit
  `scripts/lib_numbering.json` (generated) or `scripts/wasm_status.json`
  (also generated, by `gen_site_index.py`). Run
  `python3 scripts/assemble_numbering.py` after any meta.json edit.
- **Site descriptions are content, not a changelog.** A `meta.json`
  `english_description` (or a README intro paragraph, its Chinese
  equivalent) describes what the game *is* — setting, mechanics, factions,
  honest content-gap caveats — never bug-fix/porting/QA narrative, not even
  condensed to one closing sentence. Bugs belong in that lib's own
  `NOTES.md`, never the site-facing description. Never reference a
  `boot.log`/`debug.log` scratch file in docs either — those are gitignored
  debugging artifacts, not part of documented state.
- **Deep-test scope is programming bugs only** (AGENTS.md §10.7). The
  simplest test: if it didn't trigger a compile error, a runtime error, a
  crash, or an observably wrong state transition, it's usually content
  design, not a bug — don't fix game balance, reward amounts, or internally
  consistent design choices just because they look surprising.
- **Slug naming: pinyin *initials*, not full pinyin** (银河英雄传说 → `yhyxcs`,
  not the full transliteration) — cap at ~12 characters, normalize non-ASCII
  (Roman numerals → `ii`/`iii`), prefer an existing external name if one is
  independently confirmed identical (e.g. `fluffos/xkx100`).
- **Framework-family similarity and content-similarity are two separate
  signals — never blend them.** Framework family (byte-identical `master`
  file) tells you whether a fix ports safely to a sibling; content
  similarity (overlap in `kungfu/`+`d/` only) tells you whether two
  archives are substantially the same game. Similar-sounding Chinese titles
  are not a reliable signal in either direction.
- **A binary-only archive (compiled bytecode, no LPC source)** gets
  `wasm_status: "binary-pending-tooling"`, never `"not-convertible"` — there
  is separate tooling for this format; don't foreclose it.
- **`noboot`-status libs are out of scope** for routine work unless a
  specific structural blocker gets independently resolved (as happened for
  `lima`/`swmud` via a per-lib driver override, 2026-09). `realms` remains
  genuinely `noboot` for a different, unfixable reason (a real external
  MySQL dependency, incompatible with a browser sandbox) — don't re-attempt
  the same fix there.

## 9. Discovery/onboarding workstream — current policy

Broad discovery grinding (keyword rotation, fresh-repo date sweeps,
non-EN/ZH search, code-content search as a general net) is **paused** as of
2026-09-04 after 10+ consecutive dry rounds across every technique tried —
do not self-initiate a new broad round just because a session is idle. In
its place: a periodic (~weekly) re-sweep of the one remaining durable
channel (`gh search repos --created=>date`).

**This pause does NOT apply to a specific named lead** — when the user
points at a particular org, site, or game, chase it immediately and
thoroughly, the same way the MudRen org sweep and the KK/雷爵 GitHub-issue
investigation were. Code-content search (grepping for `simul_efun`,
`heart_beat`, etc. across GitHub/Sourcegraph) is a good precision tool for
verifying or chasing a *named* lead, not a productive broad net on its own —
it indexes the same repos ordinary repo-metadata search would already
surface.

**Do not post to public GitHub issues/comments without checking with the
user first.** Research and investigate freely; hold the actual post/comment
for confirmation unless explicitly told to just go ahead. To revise an
already-posted comment based on new findings, edit it in place
(`gh issue comment <n> --edit-last`) rather than posting a duplicate.

## 10. Environment gotchas worth knowing before you hit them

- **`node`/`emcc` can be silently missing from a subagent's PATH** even
  when the coordinating session has them. Root cause: the login shell is
  zsh, but PATH exports lived only in `~/.bashrc` (zsh never sources it).
  Fixed via `~/.zshenv` (sourced by every zsh invocation, including
  non-interactive) — but a Bash tool call in an *already-running* session
  is pinned to a shell snapshot captured before that fix, so if `node`/`emcc`
  ever go missing again, check both `~/.zshenv` and whether the currently
  pinned snapshot (`~/.claude/shell-snapshots/snapshot-zsh-*.sh`, found via
  the live Bash invocation's own command line) needs the same lines
  appended after its own PATH-clobbering line.
- **`(int)` in LPC is a compile-time-only cast — a no-op at runtime on a
  float value**, unlike C. Use `to_int()`/`to_float()` to actually convert.
- **A lib whose driver process shows genuinely active CPU (not stalled) can
  still be heading toward a host-wide OOM.** A widely-inherited base class
  with a genuine compile error can make the driver repeatedly reattempt
  compiling/reloading it for every dependent file in a batch, leaking
  memory at a steady rate with no plateau — this has crashed and wedged the
  host machine before (needing a hard reset). Watch absolute RSS/free
  memory on any long-running `lpcc`/driver process, not just "is it making
  progress" — kill by exact PID well before it gets dangerous, and fix the
  root compile error in the shared base class before re-running the batch.
  A lib with a large `data/closed.o` backlog (many queued accounts) is a
  similar risk via a different mechanism (a mass-restore-on-boot daemon) —
  check its rough size before ever booting that lib's driver unlimited.
- **On resume after any wakeup or reboot** (scheduled tick, task
  notification, or an auto-resume-after-crash prompt): always re-arm
  `ScheduleWakeup` before ending the turn, and don't assume a resume
  prompt's own framing is accurate — verify against real current state
  (process list, memory, git log) before treating an old/mismatched
  incident description as ground truth for what's happening now.
- **`scripts/tmux_mud.sh`'s `lines` parameter doesn't reliably limit
  output** (a tall pane re-dumps full scrollback almost every call) — pipe
  `tmux capture-pane -p | tail -N` yourself instead. Sending Chinese text
  via `tmux send-keys -l` can spuriously trigger the *local* telnet
  client's own escape mode — start with `telnet -E` to disable it.
- **A raw-socket test harness that waits for "quiet" (no new data for N
  seconds) never returns against a lib with a live per-second clock
  prompt** — a new heartbeat chunk always arrives before the timeout
  closes. Match on a recognizable prompt string, or use a hard total
  deadline instead of a per-chunk quiet-gap timeout.

## 11. Formatting/tone note for this repo specifically

No runtime/test log files (`boot.log`, `debug.log`, etc.) ever get committed
or referenced in docs — they're gitignored scratch, and mentioning "a stale
log showed X" leaks debugging noise into permanent docs that won't make
sense to a later reader. If an investigation doesn't reach a conclusion,
omit it rather than documenting the absence of one.
