# dongfanggushi2 — 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire)

Archive: `东方故事二.rar` (byte-identical duplicate: `东方故事二 (1).rar`,
already listed in AGENTS.md's Duplicate archives table — this row covers
both). Port: 40027. Status: **done** (boots clean, full registration
flow verified end-to-end through an unusually long chain, including a
real Chinese name).

## What this is

"东方故事Ⅱ之天朝帝国" ("Eastern Story II: The Celestial Empire"),
credited to Annihilator and Phoebus.suny, "建立架构 Nov 6, 1995" / "测试
游戏制度 Apr 22, 1996". Mudlib root at `es2/es2/`, config at
`es2/config.cfg`. Same `adm/obj/{master,simul_efun}` layout convention as
`es1_win`/`esI` (archives #12/#13, also "东方故事" lineage) — but a
genuinely **different, smaller, distinct codebase** (564 raw files vs.
es1_win's ~8000+), not a snapshot of the same tree: no `std/object/
prop.lpc` angle-bracket-include bug here, different `domain_file()`
implementation (no `explode("/","/")` empty-array bug). Don't assume
lineage-shared fixes transfer 1:1 just because the directory layout
matches — verify each one is actually present before applying it.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**, applied to **both**
   `valid_write` AND `valid_read` in `adm/obj/master.lpc` — unlike most
   libs processed so far (where `valid_read` is often a hardcoded
   `return 1`), this build's `valid_read` ALSO called
   `load_object(SECURITY_D)` unconditionally with no re-entrancy guard.
   Both fixed with the standard `nosave` flag + `find_object()` gate.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `adm/
   simul_efun/chinese.lpc`'s `is_chinese()` and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → `< 1 || > 6`,
   removed `i%2==0` gate) — same shape as every prior lib. Also found a
   **new sub-variant of fix pattern #5** (sliding-window byte-width):
   `check_legal_name()` had a *separate* full-width-space rejection check,
   `if( name[i..i+1]=="　" )`, a 2-BYTE window under the old GBK
   assumption — under UTF-8 this is a 2-CHARACTER slice that can never
   equal the 1-character string `"　"`, so the check silently never
   fired. Fixed to `name[i..i]` (1-character slice, matching the fixed
   `is_chinese`'s per-character indexing used elsewhere in the same
   function).
3. **New: a driver-crash bug, not a compile error** — `master.lpc`'s
   `create()` unconditionally did:
   ```lpc
   if( ob = find_object(SIMUL_EFUN_OB) ) {
       efun::destruct(ob);
       call_other(SIMUL_EFUN_OB, "???");
   }
   ```
   an old-MudOS trick to force-reload simul_efun. On this driver,
   destructing the simul_efun object from inside master's OWN `create()`
   — i.e. during the driver's own early bootstrap, before
   `master_ob`/`simul_efun_ob` are fully settled — **segfaults the whole
   driver process**, crash trace rooted in `destruct_object()` dereferencing
   `master_ob->obname` on a not-yet-initialized pointer (`vm/internal/
   simulate.cc`). Not an LPC-level error at all — nothing in `debug.log`
   short of the raw backward-cpp stack dump gave any clue beyond "it
   segfaults right after boot starts." Fixed by simply dropping the
   destruct+reload dance entirely: the driver already loads simul_efun
   fresh before master's `create()` ever runs, so there was nothing stale
   to work around here in the first place.

## Interactive test result — full registration flow

This build's registration chain is noticeably longer than every other
lib processed so far — `id → confirm → password → confirm password →
email → race select → gender → THEN Chinese name` (most libs go straight
from id-confirm to Chinese name). Verified the ENTIRE chain in one
continuous connection:

1. `dfgstwo` → passes `check_legal_id` (letters only, no digits — an
   earlier attempt with a digit in the id, e.g. `dfgs2test`, was
   correctly rejected, not a bug).
2. `y` → password prompt.
3. `password1` (twice, matching) → accepted, email prompt.
4. `a@b.com` → race selection prompt (`human`/`yenhold`/`woochan`/
   `jiaojao`).
5. `human` → gender prompt.
6. `m` → **real Chinese name prompt**.
7. **`萧峰`** → accepted by the fixed `check_legal_name` — and this time
   verification went all the way to actually **entering the game world**:
   the session landed in an actual room ("小客栈" / Small Inn) with a
   full room description, not just a password/next-step prompt. This is
   the deepest registration verification done on any lib so far in this
   project.

## Known remaining issues (documented, not fixed)

(none outstanding — the `eval_chat()` issue formerly documented here was
fixed during the 2026-07-23 QA re-verification pass; see below.)

## Retroactive fixes (QA re-verification pass, 2026-07-23)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test in a fresh session) — both are genuine bugs, not
present in the original conversion notes above:

1. **`adm/obj/master.lpc`'s `log_error()` showed raw compiler diagnostics
   (including harmless warnings) to ANY connected player, not just
   wizards** (AGENTS.md §15af family, but a distinct/worse variant: this
   lib's version had no `wizardp()` gate at all, so ordinary players saw
   the full `"编译时段错误：" + message` text — file paths, line numbers,
   "Unused local variable" noise — every time an as-yet-uncompiled
   room/NPC was first touched, e.g. simply typing `look` in the starting
   room). Fixed to only show the full diagnostic to a wizard, and only
   alarm an ordinary player with the generic `default error message` for
   a genuine compile **error** (gated on absence of `"warning:"` in the
   message, same pattern as `dtsl`/`wuhanzhan`/`shenzhou`). This also
   required `#include "/include/runtime_config.h"` at the top of
   `master.lpc` (for the `__DEFAULT_ERROR_MESSAGE__` macro used in the
   fix) since the file had no includes at all before.
2. **The previously-documented `eval_chat()` bug (see git history) was
   actually blocking the starting-room innkeeper NPC from compiling at
   all** — once (1) above stopped masking it with raw compiler spam, it
   became clear this fires on literally every single new character's
   first room entry (`/d/snow/npc/innkeeper` inherits the broken
   `std/char/npc.lpc`). Given the outsized, first-impression impact and
   the trivial/safe fix, this was resolved rather than left as a
   documented gap: `eval_chat()`'s `switch(typeof(chat))` had a dead
   `case MATCH:` (an int constant, `0x102`) with a body byte-identical to
   the preceding `case STRING:` — this driver's `typeof()` returns string
   type-name constants (`STRING`/`ARRAY`/`FUNCTION` from `include/type.h`
   are themselves strings), so mixing the stray int case label in was a
   hard "Mixed case label list not allowed" compile error, not a
   different behavior being lost. Removed the redundant `case MATCH:`
   label (its body was already covered by `case STRING:`) — not
   fabricating new behavior, just deleting dead/incorrect duplicate code.

Re-verified with a fresh registration (real name `秦兰`, female) followed
by `look`/`score`/`quit`: the innkeeper NPC now greets the player
correctly ("掌柜说道：欢迎！欢迎！请里面坐！"), zero spam, zero real
`error:` lines in `debug.log`.

## lpcc sweep

427 files, 367 pass / 60 fail (85.9%). Memory stayed healthy throughout
(~17GB free, no pressure — this is a small lib). Failure tail not
triaged individually per AGENTS.md §6b/§13 — the full interactive
registration test (which went deeper than any prior lib, reaching an
actual room) is the verification gate.
