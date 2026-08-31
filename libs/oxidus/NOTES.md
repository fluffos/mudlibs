# oxidus — technical notes

Source: `gh repo clone gesslar/oxidus-mudlib` (cloned 2026-08-28/30).
Number 954, port 40256. Status: **done** — boots clean natively, full
registration-to-gameplay playthrough verified live and repeatedly.

## What this lib is

A genuinely modern, actively-developed (pushed within the last day as of
this session), from-scratch FluffOS mudlib — not a 1990s/2000s legacy
archive like nearly everything else in this corpus. Already `.lpc`
throughout, already UTF-8, ships its own `AGENTS.md`/`.claude/skills/`
(37 skill files) documenting its own coding conventions, has a real unit
test suite under `tests/` (STD_TEST framework), and targets a specific,
current FluffOS build via its own `adm/dist/rebuild` pipeline (clones
fluffos/fluffos as a submodule and builds it from source with a custom
`local_options`). Ran `scripts/convert_lib.sh` per §2.3 convention
(cheap and safe even though 0 lossy conversions were needed) — it fixed
20 literal-`.c`-reference stragglers and converted 46 local
angle-bracket includes to quotes.

8 authored content areas confirmed real (not stock/copied): a village
(Olum) with a bakery, tailor, financier, manor interior, an arcanist
NPC/spell tree, forest/cavern/maze/tunnels/wastes zones. Account-based
login (register an ACCOUNT with a password, then create/select a
CHARACTER under it) rather than the straight-into-a-name flow most
libs in this corpus use — matches the README's own description. The
first character ever created becomes the mud's owner/admin
automatically (confirmed live).

## Driver-build mismatches found and fixed (see AGENTS.md for the full writeup)

This lib assumes a considerably newer/differently-configured driver
than this corpus's shared build had, in three independent ways. All
three are documented as new AGENTS.md catalog entries since they're
real, generalizable classes other modern-lib onboardings could hit:

1. **`async`/`await` support was simply not yet built** into this
   session's shared driver — the checked-out `~/src/fluffos` was on a
   local branch (`claude/async-phase15`) 3 commits ahead of its own
   `origin/master`, and the async/await feature itself (`858d5da9`,
   merged 2026-08-27) postdated the driver binary's last build
   (2026-08-21) by 6 days. **Not a driver bug** — confirmed via a clean
   minimal repro (`async mixed foo() { ... }` failed identically in a
   throwaway single-file test, succeeded after a plain rebuild) before
   concluding anything. Fixed by rebuilding `~/src/fluffos/build-debug`
   (`cmake --build . --target driver lpcc -j8`) from the current
   checkout — a corpus-wide driver rebuild, not an oxidus-specific
   change, so every other lib in this corpus benefits/is affected by it
   too going forward.
2. **`include/driver/*.h` didn't exist** — oxidus's own build pipeline
   (`adm/dist/rebuild`) copies the driver's own `src/include/*.h`
   (`type.h`, `socket.h`, `function.h`, etc. — "headers shared between
   driver and mudlib" per their own README) into the mudlib tree at
   `include/driver/` as a build step; this repo's `libs/oxidus/work`
   never got that step run. Fixed by copying
   `~/src/fluffos/src/include/*.h` into `libs/oxidus/work/include/driver/`
   once, by hand — this is a one-time bootstrap step, not something
   that needs to happen on every boot.
3. **PACKAGE_UIDS stub applies missing** — `adm/obj/master.lpc` had no
   `get_root_uid()`/`get_bb_uid()`/`creator_file()` at all (this lib
   doesn't use the UID/euid privilege model — "Oxidus uses the FluffOS
   privs model, not PACKAGE_UIDS" per its own `AGENTS.md`), but this
   corpus's shared driver build has `PACKAGE_UIDS` compiled in, which
   `exit(-1)`s the whole driver at boot without the first two apply.
   This is the well-catalogued AGENTS.md §7.2 pattern (also just seen
   again on `majik4`, §7.160) — fixed with the standard flat "everyone
   is Root"/"BACKBONE" stub, harmless since oxidus's real security model
   (path-based ACL + role groups in `adm/obj/master/security.lpc`) never
   consults these.
4. **`OLD_ED` vs the modern `ed_start()`/`ed_cmd()`/`query_ed_mode()`
   trio** — new AGENTS.md §7.161. This corpus's shared driver has
   `OLD_ED` defined (hundreds of other libs' own wizard editors depend
   on the classic `ed()` efun), which compiles the modern efun set out
   entirely; `std/living/ed.lpc`'s `ed_edit()` had been rewritten to use
   them, breaking `std/living/body.lpc`'s ENTIRE inheritance chain
   (every player/NPC class) at compile time. Fixed by reverting
   `ed_edit()` to the classic `ed(file, write_fn, exit_fn, restricted)`
   API — simpler than the session-style version it replaced, since the
   driver owns the whole input loop once `ed()` is called (no
   `input_to()` loop needed).

## Real programming bugs fixed (beyond the driver-mismatch items above)

- **New AGENTS.md §7.162**: `ed_write()`/`ed_exit()` (the write-
  authorization/session-end callbacks passed to `ed()` as plain string
  arguments) were declared `private`, following this lib's own correct
  convention that fixed-name driver applies (`create`, `heart_beat`,
  `valid_read`, etc.) should be `private` since "the driver ignores
  visibility" for those. But `ed_write`/`ed_exit` are a DIFFERENT
  mechanism — a mudlib-chosen callback name resolved via the driver's
  generic by-name `apply()`, the same path `call_out()`/socket
  callbacks use, which explicitly does NOT bypass visibility
  (`function_exists()`'s own docs: private/protected functions are
  "treated as not defined" for any external caller). A `private`
  `ed_write()` is silently never invoked: `ed`'s `w`/`x` commands always
  print the generic "Failed command.", with nothing in any log file
  anywhere (`safe_apply()` swallows "function not found" silently).
  Isolated with a throwaway command object before touching the real
  fix: identical `ed()`+callback code worked instantly as `public`,
  failed identically as `private`. Fixed by making both `public`.
- **New AGENTS.md §8.21**: `adm/obj/login.lpc`'s `create_body()` called
  `body->restore_body()` a second, redundant time immediately after
  `BODY_D->create_body()` had already restored the body AND run
  `std_setup()` (which computes role-based command search paths —
  `/cmds/adm/`, `/cmds/dev/`, or just the standard set, depending on
  `adminp()`/`devp()`). Since `__command_paths` isn't `nosave`, the
  second restore silently reverted it to whatever was saved BEFORE the
  character's last promotion — every admin/dev who reconnects (not just
  their very first post-promotion login, since `makeadmin`/`makedev`
  add the paths directly to the live body) gets full normal gameplay
  but every `/cmds/adm/`, `/cmds/dev/`, `/cmds/file/` command —
  including the in-game `ed`/`edit` editor — silently doesn't exist,
  with the driver's generic "What?" fail message giving zero signal
  this is a permissions bug rather than a typo. Root-caused via targeted
  debug instrumentation showing `std_setup()`'s own `get_path()` result
  (6 entries, correct) diverging from `command_hook()`'s live
  `__command_paths` (3 entries, stale) moments later. Fixed by deleting
  the redundant call in `login.lpc`.
- `std/living/body.lpc`'s `std_setup()` called `adminp()`/`devp()` with
  NO argument, which defaults to `previous_object()` — at that call
  site, `previous_object()` is `std_setup()`'s OWN caller (`body_d`, or
  the driver's `create()` apply), never the body itself, so the role
  check was silently checking the wrong identity's privileges (always
  false in practice). This bug was masked by the §8.21 restore-clobber
  bug above during testing (fixing one alone wasn't enough to observe
  correct behavior; both needed fixing together to actually see role-
  based paths survive a reconnect) but is independently real and worth
  fixing on its own merits. Fixed by passing `this_object()` explicitly.
- `std/cmd/reporter.lpc`'s `set_git_hub_label()` (shared by the `bug`,
  `idea`, and `todo` commands, both the `std` and `ghost`/`dev`
  variants — 5 command files total) called `mud_config("GITHUB_REPORTER")`
  directly; `CONFIG_D->get_mud_config()` `error()`s on any unset key
  rather than returning null/0, and GITHUB_REPORTER has no default and
  ships unconfigured in a fresh self-hosted install (nothing in
  `adm/etc/default.lpml`, no example config anywhere, no mention in
  README/DOCKER.md's setup steps). Since this ran from `setup()` during
  the object's own `create()`, the uncaught `error()` took the WHOLE
  command down for every player, not just the optional GitHub-issue-
  filing half — even though `finish_report()` already has a graceful
  `git_hub_label != ""` skip-if-unconfigured path built in, meaning the
  intended "GitHub filing is optional, local-log-only reporting always
  works" behavior (explicit in three of the five commands' own help
  text) was entirely broken by this one setup-time validation. Fixed by
  wrapping the `mud_config()` call in a `catch()` and returning early
  (leaving the label unset, matching the already-correct downstream
  skip) when the config key genuinely doesn't exist, while keeping the
  strict `error()` for a config that DOES exist but names a label the
  caller passed that isn't in its `types` list (a genuine caller bug,
  should stay loud).
- `std/object/include/object.h` had a stale duplicate/conflicting
  `void set_real_name(string str);` prototype (a second, correct
  `string set_real_name(...)` prototype already existed 4 lines later)
  and a stale `void remove();` prototype conflicting with the real
  `int remove()` implementation in `object.lpc` — both produced
  "Previous function prototype ... does not match" warnings on every
  single boot (cosmetic, no functional impact, but real dead/wrong
  declarations). Removed the two stale lines.

## lpcc-only artifact — NOT a real bug (cross-checked against a live boot)

`lpcc_check.sh`'s batch compile-sweep segfaults deterministically at
`/d/village/bakery` (confirmed reproducible: identical crash, same
file, same C++ stack trace, on two separate runs). Root cause: FluffOS's
`main_lpcc.cc` unconditionally calls `Tracer::start("trace_lpcc.json")`
at the top of `lpcc_main()` — `lpcc` ALWAYS runs with the internal
profiling Tracer active, unlike a normal `driver` boot (`mainlib.cc`
only starts it when a `--trace-log`-style flag is explicitly passed,
which nothing in this pipeline does). The crash itself is inside the
Tracer's `get_trace_id()` (a null/garbage `function_table[...].funcname`
pointer reaching `std::string`'s constructor → `strlen()` segfault) and
is reached via a nested `call_other` → simul_efun `evaluate()` →
`call_other` chain during `bakery.lpc`'s `create()` (it's the only file
in the village using `EXT_SHOP_MENU`). This looks like a real driver-
level bug in the Tracer/frame-bookkeeping code on this session's WIP
`claude/async-phase15` branch (a code comment elsewhere in the driver
already flags a concern about `FRAME_ASYNC`/`FUNC_VARARGS` bit overlap
in exactly this kind of frame-kind check) — but it is a **compile-sweep-
tool-only artifact**, not a real gameplay bug: bakery loads and plays
correctly under the real `driver` boot (confirmed live — visited the
room via a fresh player character, no crash, normal shop room). Per the
established "lpcc-vs-live-driver artifact" pattern in this project,
flagged here rather than "fixed," and NOT reported as an oxidus bug.
The rest of the corpus (482 other files, bakery excluded from that one
run) compiles 100% clean via `lpcc_check.sh`.

## Intentionally not "fixed" — real, environment-dependent, by design

- `adm/daemons/discord/chatter.lpc` (explicitly labeled "Chatter Discord
  Bot Example" in its own file header) fails to load with `error("Bot
  not setup")` — it needs a real Discord bot token via `DISCORD_BOT`
  config, which nothing in this sandboxed environment can provide. It
  is not preloaded and not reachable from normal gameplay; this is
  example/reference code for admins who want to wire up a real bot, not
  a broken feature. Matches this corpus's existing precedent for
  `imud`'s real Intermud-3 network dependency (§2.3).

## Playthrough verification

Full session via `scripts/tmux_mud.sh`, native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`, cwd
`libs/oxidus`), port 40256:

- Registered a new account (`elarion`/password, with confirmation) →
  became the mud's first character/owner automatically → landed in the
  admin-only "Developer Workroom" starting room (not the normal player
  start) → `look`/`score` both correct.
- Registered a second, independent account (`wisteria`) → normal
  character creation (lowercase-only name validation confirmed) →
  landed in the real starting room, "Village Square of Olum" → `look`/
  `score`/`inventory` all correct → walked west twice into the village
  content (tavern, a "gathering place for newcomers" room) → confirmed
  real, distinct room descriptions, not placeholders.
- Reconnect/restore path verified independently for both accounts
  (quit, disconnect, reconnect, select existing character — correct
  each time).
- Promoted `wisteria` to developer rank (`makedev`, run as the admin
  account) to test wizard-only commands on a non-admin identity; used
  `dest`/reconnect cycles (destroying and recreating the live body
  object) to confirm each fix against a genuinely freshly-compiled
  character rather than a stale in-memory clone predating a given fix —
  this was essential for finding and confirming both the §8.21 restore-
  clobber bug and the §7.162 private-callback bug, neither of which
  would have been distinguishable from "already fixed, just testing a
  stale object" without it.
- Full `ed` (in-game line editor) session verified end-to-end as a
  freshly-promoted developer: `ed <file>` on a nonexistent file → `a`
  (append) → typed a line → `.` (end input) → `x` (write and quit) →
  "Exit from ed." with no error, and the file's actual on-disk content
  confirmed correct afterward (`home/w/wisteria/final.txt`). Also
  confirmed the permission gate itself works correctly: a `write:
  "self"` path rule (`/home/*/*/**`) let a developer write their own
  home directory but correctly denied a write to mudlib root
  (`/tmp_final_verify.txt` → "Permission denied.", not a crash).
- `quit` clean both times (proper goodbye message, connection closed).

## Minor unfixed observation (not root-caused, doesn't block anything)

An empty directory named after the character (e.g. `wisteria`, `elarion`)
appeared at the mudlib ROOT (not under `/home/<letter>/<name>/`, the
correct home-directory location) after the first admin bootstrap login
and again after a `makedev` promotion. Harmless (empty, never referenced
by anything observed during the playthrough) and not chased down to a
specific line — `cwd` defaults to `/doc` (`std/living/player.lpc`), not
a bare name, so the stray `mkdir` isn't there; likely somewhere in
`login.lpc`'s admin/dev promotion path or `body_d`. Deleted both before
committing (test-session cruft, not shipped content). Worth a closer
look in a future pass if it turns out to recur for every ordinary
character too, rather than just the admin/dev promotion paths tested
here.

## WASM

Not yet WASM-packaged for the browser gallery (§1.4 pass) — this
session's scope was native onboarding + bring-up per the standard
pipeline; WASM triage left for a follow-up pass, matching the same
"native-boot verified, WASM pending" status other very recently
onboarded libs in this corpus (e.g. `rifts2`) currently carry.
