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
