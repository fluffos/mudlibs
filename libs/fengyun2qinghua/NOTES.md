# 风云II (清华仿写版）.ZIP → `fengyun2qinghua`

- Archive: `archives/风云II (清华仿写版）.ZIP` (3.1MB — literally "Storm
  Rises Again II (Tsinghua University imitation/rewrite edition)"). Exact
  byte-duplicate `风云II (清华仿写版） (1).ZIP` skipped per AGENTS.md's
  duplicate-archives table.
- Mudlib root at `fy/` (extracted directly, no nested `fy/fy/` like fy2's
  raw layout), config at `fy/config.cfg`. Config's own `name` field already
  self-IDs as **风云再起Ⅱ** — the same in-game name as `fy2` (archive #17).
- Port: **40091** (next free after 40089-40090, reserved concurrently for
  archives #97-98 by sibling agents — confirmed those libs' directories
  were mid-extraction, not yet using the port, at the time this was
  assigned).

## Status: DONE — boots clean, full registration + post-login commands verified

## Lineage confirmation: this is (almost) literally `fy2`, not an independent "imitation"

Despite the archive's title implying a from-scratch clone ("清华仿写版" =
"Tsinghua imitation/rewrite edition"), this is evidence-based, not
assumption-based, confirmed to be the *same distribution* as already-shipped
`fy2` (archive #17, `风云再起Ⅱ`/Hohai University), not an independent
codebase sharing only a name:

- **`adm/obj/master.c` is byte-identical** (`md5sum` match) between this
  archive's raw extraction and `fy2`'s raw extraction.
- **All of the following core files are also byte-identical** (raw,
  pre-conversion): `adm/obj/simul_efun.c`, `adm/daemons/logind.c`,
  `adm/daemons/securityd.c`, `adm/simul_efun/chinese.c`,
  `adm/daemons/chinesed.c`, `feature/command.c`.
- **Whole-tree comparison**: 4071 files here vs 4073 in fy2's raw
  archive — a `diff -rq` of the two raw trees shows the only
  differences are player-save-data (`data/user/g/guest/guest.o`,
  `data/login/g/guest/guest.o` — different play sessions), two extra
  registered characters (`roses`/`zzzz`) present only in fy2's copy, log
  files (`debug.log`/`USAGE`/`ATTEMPT_LOGIN` — different session
  history), `mud.dat`, and the bundled prebuilt Windows driver binary
  itself (`mudos.exe`/`mudos.log` in fy2's copy vs `v22pre8.exe`/
  `v22pre8.tec` here — a different MudOS build bundled with the
  redistribution). **Zero source-tree content differences** were found.
  Every game-content file (rooms, NPCs, skills, daemons) is identical.
- **`convert_lib.sh`'s own mechanical-fix counts matched almost exactly**:
  9 local angle-bracket includes converted to quotes (fy2: 9),
  `static`→`nosave` touched 39 files (fy2: 39), yielding 2839 `.lpc` files
  (matches fy2's file count exactly).
- **The `lpcc_check.sh` sweep result is the clincher**: 2839 total, 2766
  pass, 73 fail — **exactly fy2's own previously-reported 97.4% pass
  rate (73/2839)** — and a direct diff of the two lpcc failure logs'
  file-name lists shows **zero differences**: the identical 73 files fail
  for the identical reasons in both libs (missing `PROP_*`/`TYPE_*` armor
  constants in a handful of `std/armor/*.lpc` files, a pre-existing
  content gap in the original codebase, not something this pass
  introduced).

**Conclusion**: this archive is not an independent "imitation" build —
it's the exact same `风云再起Ⅱ` codebase and content as `fy2`, redistributed
by a different site/mirror (name suggests a Tsinghua University hosting of
the same public release) bundling a different MudOS driver binary and a
different snapshot of player save data. Given this, every fix already
proven on `fy2` was ported directly rather than rediscovered.

## Fixes applied (all ported directly from `fy2`, verified identical need)

1. **AGENTS.md §15h (GBK byte-range Chinese-character detection)** —
   applied proactively before the first boot, using fy2's own already-fixed
   copy as the exact reference diff:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`) → CJK
     Unicode codepoint range check
     (`strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length
     bound (`< 2 || > 12`, message already says "一到六个中文字" / "1 to
     6 Chinese characters") halved to character count (`< 1 || > 6`);
     removed the `i%2==0 &&` even-byte-offset gate so every character
     position is checked, not just every other one.
   - Confirmed via two independent full interactive registrations, both
     with real Chinese given names (see below) — both accepted on the
     first attempt with no rejection.

No other fix was needed — every other proactive check (below) came back
clean, matching `fy2`'s own "zero fixes needed to boot" outcome exactly.

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon load recursion)**: `master.lpc`'s
  `valid_write`/`valid_read` only `find_object(SECURITY_D)` (no
  `load_object`), and `valid_read` is an unconditional `return 1;` — no
  recursive-load pattern present.
- **§7 (`get_root_uid`/`get_bb_uid`)**: both present in `master.lpc`,
  returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c (`valid_read`/`valid_write` overriding caller with
  `this_player()`)**: `securityd.lpc` has no `valid_read` at all, and its
  `valid_write` does not touch `this_player()`.
- **§8e (bare `tail()` efun)**: no `tail(` call anywhere in
  `simul_efun.lpc`/`master.lpc`.
- **§15ae (`private nomask` command-hook)**: `feature/command.lpc`'s
  `command_hook` is declared plain `nomask int` (not `private`) — the
  bug does not apply to this lineage (matches `fy2`/`zzfy`'s own
  confirmation of the same).
- **§15ar (`commandd.lpc` dead `.c$` sscanf)**: this lineage has no
  `commandd.lpc` file at all (command dispatch is handled entirely via
  `add_action`), so the bug class doesn't apply.
- **§15ag (`ed_start`/`ed_cmd`/`query_ed_mode`)**: no such calls anywhere
  in the tree.
- **§15l (`destruct(SIMUL_EFUN_OB)` in master's `create()`)**: master's
  `create()` is a single harmless `write()` line, no destruct/reload trick.
- **§15p (DNS/intermud daemon in preload)**: `adm/etc/preload` already
  has `#/adm/daemons/network/dns_master` commented out in the raw
  archive (and `#/adm/daemons/ftpd` too) — no edit needed.
- **§15v (`LONELY_IMPROVED`/nitan-family `efun::` gaps) / §15 (dbase
  simul_efun architecture bug)**: this is the ES II/"Annihilator" lineage
  (same family as `fy2`/`fy2005`/`fengyun434`/`zzfy`/`rzrmud`), which
  stores per-object properties via `inherit F_DBASE`-based local
  functions, not bare simul_efun calls — the nitan-family dbase-sharing
  bug does not apply here (consistent with `zzfy`'s and `rzrmud`'s
  findings that this bug is lineage-specific).
- **§15x (hardcoded `MUD_PORT` mismatch)**: `master.lpc`'s `connect()`
  takes no port argument and does no port-based dispatch at all — no
  hardcoded-port gate to mismatch.
- **§15ao (switch-with-only-default)**: no such construct found in
  `master.lpc`.
- Uppercase `.C` files, `.c`-named directories, and same-basename
  extensionless/`.c` backup pairs (§15ak): none found.

## Known, accepted, non-fatal issue

- **`emoted` daemon's save-data restore fails at boot** (caught by
  master's own `catch()` around `preload()`, non-fatal):
  ```
  执行时段错误：*restore_object(): Invalid utf8 string while restoring dbase.
  程式：/feature/save.lpc 第 19 行
  物件: /adm/daemons/emoted
  ```
  `data/emoted.o` (the daemon's seed emote-table save file) was flagged
  by `convert_lib.sh` as a LOSSY conversion (invalid GBK bytes dropped) —
  per AGENTS.md §1, a handful of save-data `.o` files can have genuinely
  undecodable bytes; this is seed/example data, not source, and the
  driver boots and reaches `Accepting telnet connections` regardless.
  Not fixed (matches project convention for this exact class of issue).

## Interactive test — full registration flow (TWO independent runs, one continuous connection each)

**Run 1** — id `qinfengtest` → `y` (confirm new character) → Chinese name
**秦风** (accepted immediately, no rejection — the §15h fix's proof) →
password `TestPass123` (set + confirmed) → email → gender `m` → nationality
`0` (汉族) → entered the game world at `/d/fy/fqkhotel` (凤求凰客栈), NPC
店小二 present. `score` produced a full, correct character sheet ("普通百姓
秦风(Qinfengtest)... 你是一位汉族十岁的男性人类..." with all 12 stat
lines, attack/defense values, 参数点). `quit` dropped starting inventory and
disconnected cleanly ("欢迎下次再来！").

**Run 2** (separate connection, different id/name/ethnicity, explicit
`look` + `score` + `quit` sequence to unambiguously distinguish command
output from the automatic on-entry room view) — id `zhaoritian` → `y` →
Chinese name **赵日天** (again accepted immediately) → password
`TestPass456` → email → gender `f` → nationality `1` (苗族) → entered the
game world at a DIFFERENT starting room, `/d/chenxiang/cxcenter` (沉香镇中
心 — confirms the nationality-based start-room branch works), with live
NPCs (地头蛇 ×2, 卖鱼的, 买鱼的小姑娘) actively emoting in real time
(买鱼的小姑娘问道："这鱼怎么卖？" between my `look` and `score` sends —
proof this is a live, ticking game world, not a static scripted reply).
`look` produced the room description + exits + NPC list; `score` produced
"普通百姓 赵日天(Zhaoritian)... 你是一位苗族十岁的女性人类..." with
correct stats distinct from Run 1's character; `quit` again dropped
starting inventory and disconnected cleanly.

Both runs confirm: real Chinese names are accepted (§15h fix verified
twice, independently), the character actually lands in the game world (not
a void/missing-room failure per §15aj), and ordinary post-login commands
(`look`, `score`) produce real, correct, differentiated output (§15ae/§15ar
checklist satisfied — no command-dispatch bug present).

Noted, not a bug (same as `zzfy`'s identical finding): `get_name()` has a
pre-existing `printf("%O\n", ob);` debug line that prints the login
object's default toString (e.g. `/obj/login#10`) right before the password
prompt on a successful Chinese name — leftover debug output from the
original author, harmless, out of scope to remove.

## lpcc sweep

`scripts/lpcc_check.sh` — **2839 total, 2766 pass, 73 fail (97.4%)**.
Failures are exclusively pre-existing content gaps (a handful of
`std/armor/*.lpc` files reference `PROP_*`/`TYPE_*` constants that were
never `#include`d/`#define`d anywhere in this codebase — a real gap in the
original archive, confirmed present identically in `fy2` too) plus the
`emoted` restore issue above. Diffed the full list of failing file names
against `fy2`'s own `lpcc_fail.log` — **zero differences**, the identical
73 files fail for the identical reasons in both libs, reinforcing the
lineage finding above. Not triaged further given the small count and that
none affect the boot/registration/gameplay path exercised.

## How to run

```
cd libs/fengyun2qinghua
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40091 --timeout 25 --idle 0.5 \
  --send "yourid" --send "y" --send "你的中文名" \
  --send "yourpassword" --send "yourpassword" --send "you@example.com" \
  --send "m" --send "0" --send "look" --send "score" --send "quit"
```
(`m`/`f` selects gender; `0`-`3` selects ethnicity, which determines the
starting room; the English id must be pure letters, 3-12 chars, or
`check_legal_id` rejects it and re-prompts.)
