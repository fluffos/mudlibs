# dtsl.rar → `dtsl`

- Archive: `archives/dtsl.rar` (3.4MB — "大唐双龙传"/"Twin Dragons of the
  Tang Dynasty", same "simple"/东方故事-ish lineage as lib #1
  (shanhaizhanshen) — `adm/obj/master.c`+`adm/obj/simul_efun.c` layout).
  **No config file shipped in this archive at all** — reused lib #1's
  `config.cfg` as a template (same lineage, same directive shapes) rather
  than reconstructing one from scratch.
- Port: **40008**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed on the first attempt** (matching lineage
to lib #1, and lib #1's proactive checks — no `load_object` in
`valid_read`/`valid_write`, `get_root_uid()` present — all held here too).

## What was fixed (all from the lpcc sweep, not the boot path)

1. Encoding: 6870 converted, 327 already UTF-8/ASCII, 377 skipped binary,
   4 lossy. `.c`→`.lpc`: 6521 files, 1037 refs auto-fixed. `static`→
   `nosave`: 87 files.
2. `F_UNIQUE` macro was referenced (`inherit F_UNIQUE;`) by ~91 clone
   item files but never `#define`d in `include/globals.h`, despite
   `feature/unique.lpc` (the file it should point to) existing —
   added `#define F_UNIQUE "/feature/unique.lpc"` alongside the other
   `F_*` macros. Fixed all ~91 files' "unexpected L_IDENTIFIER" errors
   in one shot (misleadingly, the error pointed at the NEXT line's
   `inherit F_UNIQUE`, since the undefined macro parses as a bare
   identifier where a string/path was expected).
3. 6 `clone/weapon/*.lpc` legendary-weapon files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` directly AND via `inherit THROWING;` (which
   already inherits `COMBINED_ITEM` itself) — a diamond that this driver's
   stricter `nomask` conflict detection rejects (`Illegal to redefine
   'nomask' function '_query'/'_delete'/'_set'/'weight'`), where an older/
   more permissive driver apparently just deduplicated it silently. Fixed
   by deleting the redundant top-level `inherit COMBINED_ITEM;` line (kept
   the one reached transitively via `THROWING`). **Gotcha while fixing**:
   these files use CRLF line endings — a `sed '/^inherit X;$/d'` silently
   no-ops on a line ending `;\r\n` because `$` doesn't absorb the `\r`;
   needed `/^inherit X;\r?$/d`.
4. `clone/weapon/sm_ding.lpc` (7th file in the same cluster) has a
   DIFFERENT, unrelated problem: `#include "/inherit/item/embed.h"`,
   which doesn't exist anywhere in this archive — genuine missing content,
   not fixed (not fabricating a header).

## Known remaining issues (documented, not fixed)

- 369 lpcc-sweep failures total (before the fixes above; not re-swept
  after — expect notably fewer on a re-run given F_UNIQUE alone likely
  accounted for close to a third of them). Not otherwise triaged past the
  categories above given time constraints.
- 3 `#include`-fragment false positives (`adm/simul_efun/{message,math,
  object}`, AGENTS.md §6b) plus one player-directory WIP file
  (`/u/fengfei/object`) under "Invalid simulated efunction override" —
  not investigated further (low priority, personal/test content).

## How to run

```
cd libs/dtsl
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40008 --timeout 10 --send "" --send "look" --send "quit"
```

## Retroactive fix (QA re-verification pass, 2026-07-23): log_error() compile-warning spam (AGENTS.md §15af)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test): `adm/obj/master.lpc`'s `log_error()` showed the
config's scary `default error message` ("你发现事情不大对了，但是又说不上
来。") to the connected (non-wizard) player for **every** compile-time
diagnostic funneled through `APPLY_LOG_ERROR` — including harmless "Unused
local variable" **warnings** triggered by the first lazy compile of an
ordinary room/NPC the player merely walked into (e.g. `/d/job/...`'s
`job_money.h`-included files, `/cmds/std/look.lpc`, etc). In a real
registration+play session this fired dozens of times per minute of walking
around — same bug class already documented and fixed on `wuhanzhan`/
`shenzhou` (§15af). Fixed identically: only show the default-error message
when `message` does NOT contain the substring `"warning:"` (still logs every
diagnostic to the per-file log either way; only the in-band player-visible
alarm is gated). Re-verified with a fresh registration (real name `秦北`)
followed by `look`/`score`/`quit` — zero spam, zero real `error:` lines in
`debug.log`.

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (6,521
  files, 6,369 written/reformatted, 29 already-clean, 123 refused with
  an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦诺`, ID
  `qinnuo`, following the same ID→confirm→Chinese name→password (5-8
  chars)→email→gender→4-stat-point-allocation flow as sibling
  `datangshuanglong`) reaching the actual game world (大唐学院 starting
  room); `look`/`score` both produced correct output (full 人物档案
  stat card rendered correctly), `quit` exited cleanly. One background
  `*Read access denied.` runtime error appeared during this run, same
  pre-existing job-daemon content gap already documented in
  `datangshuanglong`'s NOTES (`adm/daemons/jobmond.lpc`'s periodic
  job-posting logic trying to move an NPC into a room via a chain that
  hits an ACL denial) — fires from that daemon's own independent
  heartbeat, unrelated to the registration/look/score/quit path under
  test, not a regression. No regressions from the reformat or the fresh
  driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`/`include/net/
  ftpdsupp.h` and `adm/daemons/network/dns_master.lpc`'s
  `socket_create`/`socket_bind`/`socket_close`/`socket_address` →
  `Undefined function`, caught non-fatally, `Initializations complete.`
  still printed). Like `datangshuanglong`, this lib's login path does
  **not** gate on `query_ip_number()`'s format, so a full registration
  proceeded all the way through under WASM too: ID `qinao` → Chinese
  name `秦傲` → password → email → gender → stat allocation → reached
  the actual game world (大唐学院), `look` produced correct room
  output, `quit` exited cleanly. **This lib is confirmed fully playable
  under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, admin seed)

Same "大唐双龙" simple-lineage shape as sibling `datangshuanglong`
(byte-identical `adm/daemons/band.lpc`/`sited.lpc`) -- checked directly
rather than assumed:

- `adm/daemons/band.lpc` `is_banned()` (~line 39): loopback bypasses the
  ban-site regexp scan. Fail-closed: only an exact `127.0.0.1`/
  `localhost`/`127.`-prefix match bypasses; a malformed address falls
  through to the original scan. Called from `adm/daemons/logind.lpc`'s
  `logon()` (~line 97) with `query_ip_name(ob)`.
- No live `uptime()` startup-grace gate.
- No live per-IP throttle: `get_id()`'s `ip_cnt>8` cap (~line 222) is
  entirely commented-out dead code in the raw archive, same as
  `datangshuanglong` -- nothing to patch.
- `adm/daemons/sited.lpc`'s `is_valid(id, ip)` has the same dangling-
  else bug as `datangshuanglong` (loopback+non-wizard is rejected,
  every non-loopback IP unconditionally passes, the `valid_login`
  whitelist is unreachable) -- but it's dead code here too, only called
  from the unrelated `cmds/std/toupiao.lpc` voting command, so it does
  not gate logins. Left unpatched/undocumented-further for the same
  reason as `datangshuanglong`.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, registered through the
normal flow (id -> confirm y -> Chinese name 浮浮 -> password x2 ->
email skipped -> gender m -> stat allocation `20 20 20 20` -> confirm
yes), granted `(admin)` via `adm/etc/wizlist` (`fluffos (admin)` line
added, existing `fengfei`/`kouzhong`/`ttj`/`zhujiepo` entries kept)
before registration, so wizard status was active immediately
("作为巫师，你可以迅速离线" shown on the very first `quit`). Verified
on a SEPARATE re-login: password accepted, `update /d/newbie/door`
succeeded ("重新编译 /d/newbie/door.lpc：成功！") -- unlike sibling
`dongfanggushi2`, this lineage's restore path has no permission bug,
re-login just works. Save files (`data/user/f/fluffos.o`,
`data/login/f/fluffos.o`) are plain untracked paths, not covered by any
`.gitignore` pattern -- a normal `git add libs/dtsl/` picks them up, no
force-add needed.

Retest: fresh normal registration (id `ceshijiu`, name 秦鹏, female)
reached 大唐学院, look correct, clean quit. debug.log clean across both
driver runs this pass (only expected boot-time config dump and
SIGTERM-on-kill lines -- the visible "编译时段错误" warning spam during
fluffos's OWN session is expected/correct: this lib's `log_error()` fix
(see above, 2026-07-23 pass) shows full diagnostics to wizards and only
gates the generic scary message for non-wizards, and fluffos is a
wizard). Two driver instances started/killed by exact PID; test
character `ceshijiu`'s saves removed afterward (`data/user/c/
ceshijiu.o`, `data/login/c/ceshijiu.o`), `fluffos`'s kept. Note: this
lib's `data/user/`+`data/login/` trees already contained other untracked
leftover test saves (e.g. `q/` shard, from this lib's own earlier
`qinnuo`/`qinao` verification passes documented above) predating this
session -- left untouched as out of this pass's scope.
