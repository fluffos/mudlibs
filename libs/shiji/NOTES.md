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

## Interactive test result — full registration flow

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
