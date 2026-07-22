# xkx2001 — 侠客行 Ⅰ (Xiakexing/The Quest of Oriental Chivalry, 2001 test lib)

Archive: `xkx2001测试用老lib.zip`. Port: 40021. Status: **done** (boots
clean, connects, plays through login into "create new character?"
confirmation with zero crashes).

## What this is

"ES II mudlib" lineage (comment header in `adm/single/master.c`: "for ES
II mudlib... modified by Xiang for XKX"), same family as `rzrmud`
(archive #23, "大唐西游") — shares the exact same `master.c` function set
(`connect`/`epilog`/`preload`/`log_error`/`valid_*`/`standard_trace`/
`error_handler`) almost verbatim, both apparently descended from the
same "XKX"(侠客行)-authored base. `adm/single/master.c` +
`adm/single/simul_efun.c` layout, same as `bxsj`/`bxsj1` (archives #4/#5)
— but NOT the same lineage as those (checked: no `log_error()`/
`CHANNEL_D` reentrancy call, no lazy-load-in-valid_read pattern, 2-arg
`valid_override` but no allow-list issue hit in testing). MudOS v22b25,
"XiaKeXing Gaming Group 1996-2003".

## Fixes applied

None — booted clean with zero fixes on the first attempt (mechanical
`convert_lib.sh` pipeline only), same as `rzrmud`. Before starting,
checked this lib's `master.c` against the known bxsj-lineage bugs (§4
CHANNEL_D reentrancy, §14 valid_override 3-arg, §8c this_player()-override
footgun) since the `adm/single/` path layout matches bxsj/bxsj1 — none of
those specific bugs are present in this master.c despite the similar
directory layout, confirming layout similarity alone doesn't mean shared
bugs; the actual `master.c` *content* here is closer to rzrmud's.

## Known content gap (not fixed — see AGENTS.md §13)

lpcc sweep: 8124 files, 6884 pass / 1240 fail (84.7%). Largest cluster
(52 failures, one root cause per AGENTS.md §8g): `inherit/misc/
bboard.lpc` (and its `.bad.lpc` backup copy) calls `EDITOR_D->add(...)`/
`EDITOR_D->get_file_num(...)` — a whole daemon (`EDITOR_D`, apparently an
"anthology/featured-posts editor" service for bulletin boards) that
doesn't exist anywhere in this archive at all, not a typo or missing
`#define`. Genuine missing content (an entire daemon file), affecting
only the bulletin-board "compile into archive" feature — not fixed, out
of scope. The remaining ~1188 failures are the usual long tail (illegal-
character/encoding edge cases, syntax typos in individual files,
`#include`-only fragments failing standalone per §6b) — not triaged
individually.

## Interactive test result

Connects, ASCII banner + mudlist status table render correctly (Chinese
intact), GB/BIG5 charset prompt works, username length/alphabetic
validation works correctly (rejected both a too-long and an all-Chinese
attempt before accepting a valid one), and a valid new username reaches
the "create new character?" (y/n) confirmation prompt with zero crashes.
Did not create a full character or play further (out of scope).
