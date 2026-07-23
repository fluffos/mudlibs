# shiji — 世纪 (Century)

Archive: `世纪.zip`. Port: 40026. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese name).

## What this is

"世纪(CENTURY)" ("Century"), mudlib root at `century/lib/`, config at
`config.cfg` (referencing `mudos.exe`/`mudos.dll` — a Windows MudOS
build). Uses the `adm/single/{master,simul_efun}` layout convention (same
shape as the ES II/bxsj-family libs, though otherwise unrelated content —
its startup banner actually credits "星战英雄之乱世风沙" as the
copyright, suggesting this is a modified/rebranded fork of the
xingzhanyingxiong (archive #2) codebase or a shared common ancestor).
~3,554 raw files.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: `adm/single/master.lpc`'s
   `valid_write` called `load_object(SECURITY_D)` unconditionally on
   every call (wrapped only in a bare `catch()`, no re-entrancy guard).
   Applied the standard `nosave` flag + `find_object()` gate fix.
   `valid_read` was already a hardcoded `return 1;` — no fix needed
   there.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `adm/simul_efun/
   chinese.lpc`'s `is_chinese()` (GBK lead-byte range → CJK codepoint
   range) and `adm/daemons/logind.lpc`'s `check_legal_name()` (byte-count
   bound `< 2 || > 10` → character-count bound `< 1 || > 5`, removed the
   `i%2==0` even-byte-offset gate). Both applied proactively before first
   boot, recognized on sight from the identical shape seen in every prior
   lib.
3. **New: case-sensitive filename mismatch on a DATA file, not a
   `#include`** (generalizes §15g beyond source includes — see new
   catalog entry §15k below). `adm/daemons/logind.lpc`'s
   `howmany_visitor()` does `read_file("/adm/single/MUDVISITOR")`
   (hardcoded uppercase), but the actual file extracted from the archive
   is `adm/single/mudvisitor` (lowercase) — silently resolved on the
   original Windows build's case-insensitive filesystem, hard-fails
   here. Symptom was much nastier than a compile error: `read_file()`
   returns `0` (not found) instead of a string, and the following
   `sscanf(content, "%s %d", format, num)` crashes with "Bad argument 1
   to sscanf, Expected: string Got: 0", which happens inside
   `logon()` → `howmany_visitor()`, i.e. on literally every single new
   connection's `new_conn_handler`, immediately disconnecting the user
   before any prompt renders (empty `mudclient.py` transcript, looked
   like a totally dead server on the first probe). Fixed by copying the
   file to the uppercase name the code expects (kept the original
   lowercase file alongside, untouched, in case anything else reads it).

## Re-verification pass (2026-07-23) — found and fixed two new bugs

The original pass above only tested registration up through Chinese-name
acceptance, never a post-login command — exactly the gap AGENTS.md §15ae's
standing policy warns about. Re-running the full flow through `look`/
`score`/`quit` surfaced two real, previously-undiscovered bugs in
`adm/single/master.lpc`:

1. **AGENTS.md §15w** (`log_error()` broadcasting every compile *warning*
   to the connected player as if it were a fatal crash): `log_error()` did
   `if(this_player(1)) efun::write(HIW+"\n编译时段错误：" + HIG +message)`
   unconditionally. Since almost every lazily-compiled file in this old
   codebase emits at least one harmless `warning:` (unused locals, `Illegal
   to declare nosave function`, etc.), a freshly registered player's very
   first `look`/`score`/etc. produced a wall of `编译时段错误：...warning:...`
   lines that look exactly like real crashes. **Fixed**: gated the
   broadcast on the message NOT containing `"warning:"` (still logged to
   file regardless), same pattern already applied in `shenmo`/`shenzhou`.
2. **AGENTS.md §4/§15af variant, worse than the exact catalogued shape**:
   `error_handler()`'s `standard_trace()` calls `CHANNEL_D->do_channel(...)`
   unconditionally, and `log_error()` calls `efun::write_file(home +
   "error.log", ...)` unconditionally — both fire the very first time
   ANY compile warning appears anywhere in the preload chain, including
   warnings from `/feature/treemap.lpc` (inherited by `/feature/dbase`,
   inherited by `securd` itself) that fire WHILE `securd` (=`SECURITY_D`)
   is still mid-compile. `write_file()`'s `valid_write()` then tries to
   `load_object(SECURITY_D)` while that exact object is mid-compile — this
   driver forbids that, AND (verified empirically, worse than the §4
   catalog entry's documented shape) **this specific compile-abort
   condition is not catchable at this call site even when wrapped in an
   explicit `catch()`** — it still cascaded into `Error in error handler`/
   `Error in mudlib error handler` noise in `debug.log` on every boot,
   dozens of times, though never reaching a connected player (purely a
   preload-time-only artifact, boot never crashed). **Fixed differently
   from the catalogued §4 pattern**: since `catch()` doesn't help here,
   guarded both calls with `find_object(SECURITY_D)`/`find_object(CHANNEL_D)`
   and skip entirely (not even try) when the target isn't loaded yet,
   rather than try-and-catch. Verified via a clean re-boot: zero `Error in
   error handler` lines anywhere in `debug.log` afterward, across two full
   registration sessions.

Re-verified end-to-end after both fixes: fresh registration (id `sjqftwo`,
real Chinese name `秦岭儿`, gender f) → `look`/`score`/`quit` all produced
correct real output with **zero** `编译时段错误` spam and **zero**
`Error in error handler` lines in `debug.log`. A second session using the
already-registered `sjqfid` (an existing-login re-test) also came through
clean via the password-login path.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:

1. Connect → ASCII-art banner + status screen → English-id(ID) prompt.
2. Empty input / an id outside the 3-8 character bound is correctly
   rejected with a clear message and re-prompts (not a bug).
3. `sjitest` → passes `check_legal_id`, reaches the "创造一个新的人物，
   您确定吗(y/n)？" confirmation.
4. `y` → reaches the Chinese-name prompt.
5. **Real Chinese name `萧峰`** → accepted by the fixed
   `check_legal_name` (no rejection message), confirmed via the summary
   screen printing "你的帐号:sjitest / 你的名字:萧峰" — proceeds straight
   to the password-setup prompt. This is the actual proof the §15h fix
   works, not just that the prompt renders.

## lpcc sweep

2642 files, 2474 pass / 168 fail (93.6%). Failure tail is the usual shape
(missing `QUEST_D` daemon accounting for 26 of the 168, a handful of
genuine syntax typos, a few missing headers) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~17GB free
consistently, no pressure — this is a small lib).
