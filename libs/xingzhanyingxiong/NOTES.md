# 星战英雄.rar → `xingzhanyingxiong`

- Archive: `archives/星战英雄.rar` (1.3MB — "乱世风沙之星战英雄", a
  `xkx`-lineage MudOS lib, config labeled 0.9.20 like lib #1 but a
  different codebase; ANSI-art login banner).
- Mudlib root in archive: nested at `xz/xkx/` (config.cfg lives in `xz/`,
  one level above the actual mudlib root — NOT at the archive top level,
  unlike lib #1. Always check `mudlib directory :` in the config rather
  than assuming the archive layout).
- Port: **40002**.

## Status: DONE — boots clean, playable over telnet

Full ANSI-art banner + Chinese login flow confirmed working. This lib is
the 2nd pilot and is where the FluffOS driver bug (AGENTS.md §8) and the
`message_combatd` mudlib bug (below) were found and fixed.

## What was fixed

1. Encoding: 1942 files converted GB18030→UTF-8, 193 already UTF-8/ASCII,
   15 skipped as genuinely binary (mudos.exe/.dll etc — bundled Windows
   driver binaries, irrelevant, left alone), 30 needed the lossy `-c`
   fallback (stray invalid bytes scattered through `kungfu/skill/*`,
   `clone/book/*`, `d/fenghuang/fenghuang/*`, a few `welcome` files, and
   `data/emoted.o` — all pre-existing single-byte corruption in the
   original archive, not something our pipeline introduced).
2. `.c` → `.lpc`: 1909 files renamed. 132 literal `.c"` references
   auto-fixed by `convert_lib.sh`, 0 left over needing manual attention.
3. `static` → `nosave`: 51 files.
4. `master.lpc` does NOT have the §4 `load_object`-in-`valid_read`
   recursion bug (no `load_object` calls in this master at all) — checked,
   not needed here.
5. Config: removed 5 obsolete keys, set `port number : 40002`,
   `mudlib directory` to absolute `work/` path, fixed `log directory`
   (was `/adm/log`, changed to `/log` to match the `libs/<slug>/log/`
   convention — AGENTS.md §6).
6. **Found and fixed a FluffOS driver bug** (AGENTS.md §8): null
   `backbone_domain` dereference in `mudlib_stats.cc`'s
   `init_domain_for_ob()`, triggered because this lib's `master::
   author_file()` calls `call_other(SIMUL_EFUN_OB, "author_file", ...)`
   during master's own bootstrap (before `backbone_domain` is set),
   causing a SIGSEGV the first time that call chain loads a new object.
   Patched `~/src/fluffos/src/packages/mudlib_stats/mudlib_stats.cc`;
   rebuilt both `build/` and `build-debug/`. Systemic pattern, likely to
   recur on other libs — no re-diagnosis needed, just confirm the patched
   driver binaries are what's running.
7. **Found and fixed a mudlib bug affecting 100+ files**: every file under
   `kungfu/skill/*` calls `message_combatd(msg, me, target)` to print
   combat messages, but no such function is defined ANYWHERE in the lib
   (checked exhaustively — not a simul_efun, not on `COMBAT_D`, not
   anywhere). The signature exactly matches `message_vision()` (an
   existing, working simul_efun in `adm/simul_efun/message.lpc`) — old
   MudOS's weaker compile-time checking apparently let this ship broken
   (every combat skill's flavor-text message was silently a no-op under
   whatever driver this last ran on); this driver rejects undefined-
   function calls at load time, which is what surfaced it. Fixed by
   adding `message_combatd()` as a thin alias for `message_vision()` in
   `adm/simul_efun/message.lpc` (placed AFTER `message_vision`'s own
   definition — same-file forward-reference didn't resolve, see AGENTS.md
   §8b) rather than touching 100+ call sites.
8. Full `lpcc_check.sh` sweep: 1729/1909 pass before the `message_combatd`
   fix → 1773/1909 pass after it + the driver's macro-nesting-depth fix
   (AGENTS.md, `MAX_EXPANSION_NESTING`) fixed `clone/misc/{card,newcard}.lpc`
   too. 136 failures remain, mostly the missing-zone-content and optional-
   network-daemon categories below.

## Known remaining issues (not fixed — documented, low/no priority)

- **~60 `clone/board/*.lpc` files** reference room paths under zones that
  don't exist ANYWHERE in this archive at all (no `/d/wudang`,
  `/d/shaolin`, `/d/huashan`, `/d/emei`, `/d/tangmen`, `/d/mingjiao`, and
  many more classic wuxia-sect zones — checked, genuinely absent, not just
  uncompiled-yet). This archive shipped without most of its game-world
  content, likely a "core" release split from a much larger world pack.
  Not fabricating the missing rooms (AGENTS.md §13) — these board clones
  aren't preloaded, so this has zero effect on normal play, only lpcc-sweep
  noise.
- `/adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,telnetd,pingd,
  inetd}.lpc` — same optional network-daemon-cluster-missing-headers issue
  as lib #1 (`config.h`/`mailer.h`/`daemons.h`/`uid.h`/`priv.h`/`post.h`
  absent from `include/`). Not on preload, not required for play.
- A handful of `d/*` room/NPC files have real syntax errors (missing
  brace/quote, `switch`/`case` shape issues similar to lib #1's rankd.lpc)
  — not yet individually triaged past the first pass; low priority since
  none are on the critical boot/login path.
- A few `F_SKILL: No such skill (...)` errors on some `clone/npc/killer-*`
  NPCs — reference skill names not present in `kungfu/skill/` under this
  archive; likely more missing-content (same shape as the board/zone gap
  above), not investigated further.

## How to run

```
cd libs/xingzhanyingxiong
~/src/fluffos/build-debug/src/driver config.fluffos
# separately:
python3 ../../scripts/mudclient.py 127.0.0.1 40002 --timeout 10 --send "" --send "look" --send "quit"
```

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
