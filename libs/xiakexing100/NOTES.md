# xiakexing100 — 侠客行一百

Archive: `侠客行100.rar`. Port: 40037. Status: **done** (boots clean and
quick, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行一百", credited to "Coollizard & xkx100 2003-2004",
http://yoyo.xm.fj.cn/xkx100, up since 2001-01-14 per its own connection
banner. Same "Century-family" `adm/single/{master,simul_efun}` layout
as `shiji`/`zhonghua2`/`shujian2008`/etc. ~14,227 raw files, 12,209
after `.c`→`.lpc` rename — the largest lib processed in this session
run.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 4 || > 10` → character-count bound `< 2 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only,
   `valid_read` is a bare `return 1;`); no deep `named.lpc` fix
   (`named.c` exists but lacks the `PATH()`/sliding-window pattern seen
   in the nitan-family shape — a simpler, different implementation
   here).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 20 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxbtest` → confirm `y` → **real Chinese
name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous Jin Yong
character found in this lib's `banned_name` list) → accepted, proceeds
straight to "请设定您的密码：".

## lpcc sweep

12,209 files, 12,118 pass / 91 fail (99.3%). Failure tail dominated by
an `accept_hit` type-mismatch cluster (120 of the reported instances
across files, string vs object argument), plus the usual handful of
missing globals/syntax typos — not triaged individually per AGENTS.md
§6b/§13. Memory stayed comfortably healthy throughout the sweep despite
this being the largest lib in the current session run (~13GB free
consistently, lpcc RSS peaked well within normal range, no pressure
requiring an early kill).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 12209 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 10795 written, 1414 already
  idempotent-clean, 0 refused. Verified the earlier §15ae fix
  (`feature/command.lpc`'s `command_hook` staying `nomask` with
  `private` still commented out) survived unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxbrew`, then `秦徽`/id `xkxbrev`), reaching an actual
  starting room, `look`/`score`/`quit` all producing correct output —
  also separately re-confirmed post-login command dispatch (the §15ae
  fix) via a reconnect + `look` on the saved character. No regressions
  from either the driver rebuild or the reformat.
- **WASM build test found and fixed a real, pre-existing mudlib bug**
  (`scripts/wasm_client.js` against `~/src/fluffos/build-wasm/src`):
  boot itself was clean, but every connection attempt silently stalled
  right after the login banner, never reaching the id prompt at all —
  no fatal error printed anywhere. Root-caused by reproducing the exact
  same stall **natively** (temporarily moving aside
  `work/log/MUDVISITOR`, the untracked runtime-state visitor-counter
  file `adm/daemons/logind.lpc`'s `howmany_visitor()` reads on every
  connection): `read_file(VISITORS)` returns a non-string (`0`) when the
  file doesn't exist, and the un-guarded `sscanf(content, "%s %d", ...)`
  that follows throws `Bad argument 1 to sscanf` — uncaught, this aborts
  the rest of `logon()` silently (confirmed via `debug.log`'s
  `执行时段错误：*Bad argument 1 to sscanf`), before the player ever sees
  an id prompt. This is a **genuine pre-existing mudlib bug**, not a
  WASM-specific driver gap — it just never manifested in earlier native
  testing passes because `MUDVISITOR` already existed on disk from prior
  test runs (it's untracked/gitignored runtime state, not shipped in the
  original archive's git history), whereas `scripts/wasm_client.js`'s
  in-memory filesystem deliberately never copies `log/`'s *contents*
  (only creates the empty directory, by design, to keep the harness
  fast), so a WASM run is effectively always a "genuinely fresh archive,
  first boot ever" scenario for this file — the exact condition that
  triggers the bug. **Fixed**: added a `stringp(content)` guard (return
  `0`/treat as "no visitors yet" if the file doesn't exist) to both
  `howmany_visitor()` and the identically-shaped `howmany_card()`
  (`GIFTCARD` file, same pattern, fixed proactively). Re-verified: (a)
  natively, with `MUDVISITOR` moved aside, connection now proceeds
  straight to the id prompt showing "第一位访问者" and a full
  registration completes cleanly, zero `debug.log` errors; (b) under
  WASM, full registration now also completes end-to-end (id `xkxwasmz` →
  real Chinese name `秦岫` → stat roll → gift/email/gender → landed in an
  actual starting room, `look`/`score`/`quit` all producing correct
  output). This lib has no IP-format-dependent login gate, so once this
  fix was in place it was fully playable under WASM too.
