# xiyangzaixian_fengkuang — 夕阳再现 (Sunset Reappears — "疯狂江湖" build)

Archive: `夕阳再现-疯狂江湖.rar` (byte-identical duplicate: `夕阳再现-疯狂
江湖(1).rar`, already listed in AGENTS.md's Duplicate archives table —
only this one processed). Port: 40040. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"夕阳再现" ("Sunset Reappears"), `adm/obj/{master,simul_efun}` layout,
~17,768 raw files — one of the larger libs processed in this session.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 10` → character-count bound `< 1 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only); no
   `named.c` daemon exists in this lib.
3. **Confirmed no DNS/intermud daemon to exclude** — unlike most recent
   libs, `adm/etc/preload` has NO `dns_master` entry at all (nothing to
   apply AGENTS.md §15p to here). `httpd` is in preload, confirmed safe
   — its socket setup is deferred via `call_out("setup", 5)`, non-
   blocking to preload.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xyzfktest` → confirm `y` → **real
Chinese name `秦风`** → accepted, proceeds straight to "请设定您的密码：".
This lib's registration prompt warns against Jin Yong novel character
names, but the actual `banned_name` array only contains pronouns and
generic words ("风云", "流氓", political figures) — no specific
character name needed to be avoided this time.

## Re-verification pass (QA sweep, later session)

Earlier pass's "full registration flow verified end-to-end" only actually
tested through to the password-setup prompt, not an ordinary post-login
command (per the project's standing §15ae policy of always testing at
least one post-login command like `look`/`score`). Re-tested the whole
flow end-to-end this pass:

- Confirmed `feature/command.lpc`'s `command_hook()` is `protected nomask`
  (not `private`) -- §15ae does not apply here.
- **Found and fixed a real bug**: `adm/obj/master.lpc`'s `log_error()`
  showed EVERY compile-time diagnostic to the connected player
  unconditionally (§15w), including harmless WARNINGS (`Unknown #pragma,
  ignored`, `Unused local variable`) from the first-ever lazy compile of
  a never-preloaded room/NPC file -- confirmed live: a fresh registration
  showed ~6 spurious `编译时段错误：... warning: ...` lines interleaved
  with the real welcome banner and room description. Fixed by gating the
  player-facing broadcast on the message NOT containing `"warning:"`
  (still logs everything to disk regardless, matching the established
  fix pattern used across this project). Re-verified with a fresh
  registration (`qinshu`/秦树, female) after restarting the driver: **zero**
  spurious messages, `look`/`score`/`quit` all correct (correct
  female-specific title "芊芊民女", landed in a real starting room
  "铁枪庙").
- Full registration + post-login-command flow now confirmed working with
  real Chinese names 秦天(male, landed in 北疆小镇)/秦树(female, landed in
  铁枪庙), `look`/`score`/`quit` all producing correct output, zero
  `执行时段错误` in `debug.log` after the fix.

## lpcc sweep

14,105 files, 13,798 pass / 307 fail (97.8%). Largest single cluster (53
failures) is a missing `GROUP_D` global — not triaged individually per
AGENTS.md §6b/§13. Memory stayed healthy throughout (~10-11GB free
during this sweep specifically), even while running concurrently
alongside several sibling libs' conversions/sweeps in the same session
as part of a push to parallelize more archives at once.
