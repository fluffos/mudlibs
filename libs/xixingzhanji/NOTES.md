# 西行战记 (xixingzhanji) — archive #85

## What this is

`archives/西行战记.gz` is, per AGENTS.md's own note, "a bare gzip of a tar, not
`.tar.gz` named" — `tar xzf` handled it transparently in one step (no
separate `gunzip` needed), unpacking to a single top-level directory `xxzj/`.

The lib self-identifies as **西行战记** ("Records of the Westward Battle
Journey" / "Journey West War Chronicle") — a Journey-to-the-West-themed
wuxia/xianxia mudlib. `bin/config.xxzj`'s `name` field says
`西行战记[总站]` ("headquarters/main station") but the live `logind.lpc`
banner text says `西行战记[宜昌站]` ("Yichang station") — the same kind of
branding drift already seen on other archives in this project (a
regional-site fork of a shared codebase, config field not updated to match).

**Lineage**: genuine **ES II** family (`master.c` header credits "original
from Lil, rewritten by Annihilator (11/07/94)"), the same large family as
es1_win/esI/xkx2001/rzrmud/bmxkx2001/kxkj/
yueyingqiyuan/wuhanzhan/haiyang2/yanhuangwuhun/yhyxs/
xuanjianlu/shenzhou/shenmo/zitengzhan/zhongjidiyu/xiyouji2003. Confirmed via
`master.c` MD5 (after GBK→UTF-8 normalization) that this is **not** a
byte-identical duplicate of any of those — it's its own distinct fork within
the family, not a hidden re-run of an already-processed archive.

~6500 `.lpc`/`.c` files after conversion — a mid-size lib, well within
`lpcc_check.sh`'s normal (non-mega-lib) bracket.

## Pipeline

1. Extracted with `tar xzf archives/西行战记.gz -C libs/xixingzhanji/raw/`
   (worked in one step) → `libs/xixingzhanji/raw/xxzj/`.
2. Converted with `scripts/convert_lib.sh` → `libs/xixingzhanji/work/`:
   encoding (288 already-UTF-8, 6749 converted, 487 lossy, 27 skipped
   binary), `.c`→`.lpc` rename (6493 files), 1035 literal `".c"` refs fixed,
   25 angle-bracket `<...c>` refs fixed, 169 local angle-bracket `<x.h>`
   includes converted to quotes, `static`→`nosave` (67 files touched).
3. Port **40080** assigned (next free per TODO.md after 40076-40079
   reserved for archives #27/#82-84's concurrent agents).
   `libs/xixingzhanji/config.fluffos` adapted from `bin/config.xxzj`
   (iconv'd BEFORE any edit, per §5): `port number` → 40080, `mudlib
   directory`/`binary directory` → absolute paths under this repo.

## Conversion-pass extras (beyond convert_lib.sh's automated pass)

- **3 uppercase `.C` files** missed by the rename glob (`d/obj/drug/YUNDAN.C`,
  `daemon/class/yaomo/kusong/dali-bang/SHENLI.C`,
  `daemon/class/yaomo/kusong/huoyun-qiang/huohun.C`) — manually renamed to
  `.lpc`. None referenced elsewhere by path, so this was cosmetic/hygiene,
  not a boot-blocker.
- **One un-converted raw-GBK straggler** that survived `convert_lib.sh`'s
  file-classifier: `d/sea/npc/beast1.lpc` (an ISO-8859-classified file per
  `file -b`, not caught by the extension-based forced-text list because it's
  `.lpc`... actually it WAS on the forced list but still ended up raw --
  likely a `file`-classifier edge case on this specific byte pattern, same
  class of gotcha AGENTS.md's Encoding section warns about generically).
  Found via the `lpcc_check.sh` sweep (`Invalid UTF8 codepoint in string
  literal`), fixed directly with `iconv -f GB18030 -t UTF-8 -c`. This also
  resolved two downstream cascade failures (`d/sea/maze1`, `d/sea/maze5`,
  both of which just reference this NPC and re-failed only because of it —
  confirmed one-shared-cause per §8g, not 3 separate bugs).

## Fixes applied, and why

### 1. `master.lpc`'s `connect()`: `switch(port){ default: ... }` is a hard compile error here — **the one fix required to get past boot at all**
The original `connect(int port)` used `switch(port) { default: ... }` with
no real `case` label (this lib never actually dispatches behaviour by port —
single-port mud). This driver's grammar requires at least one real `case`
in any `switch`/`case` block; a `default:`-only switch is a parse error
(`need case statements in switch/case, not just default:`), which took down
`master.lpc`'s entire compile (`*No program in object '/adm/obj/master'!`).
Fixed by removing the `switch` wrapper entirely (the `default:` body already
covered every port unconditionally, so a plain code block is behaviourally
identical and simpler). Not previously catalogued in AGENTS.md — worth
adding as a new entry (`switch` with only `default:`, no `case`, is a hard
parse error on this driver).

### 2. `adm/daemons/convertd.lpc` — 44 instances of the stray-backslash-before-closing-quote typo (§8h, much larger count than previously seen) — **fatal, blocked this preloaded daemon's compile**
`convertd.lpc`'s GBK/BIG5/Greek/pinyin charset lookup table has the same
"`\",`" typo documented in §8h (`"β\",` instead of `"β",`), but instead of
the usual 1-2 occurrences this file had **44** scattered throughout its
~7000-line table (verified via a byte-level Python scan, not just the
naive `grep '\\\\"'` which under-matched due to embedded PUA/private-use-area
characters sitting between the real content and the stray backslash on some
lines — e.g. `"α\xEE\x96\xA2\",` had a PUA glyph U+E5A2 immediately before
the erroneous `\"`). Fixed all 44 with a byte-level Python pass that only
strips the erroneous `\` immediately before a line-ending `"`/`",`, leaving
every embedded PUA character intact. `convertd` is on the preload list, so
this was a fatal, boot-blocking bug — the very first real error seen after
fixing the `switch` issue above.

### 3. `adm/simul_efun/chinese.lpc` — §15h `is_chinese()` GBK byte-range check
`if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 )` (GBK lead-byte range,
2-byte minimum) replaced with a CJK Unicode codepoint range check
(`str[0] >= 0x4e00 && str[0] <= 0x9fff`, 1-character minimum). Standard
§15h fix — this directly gates whether real Chinese names are ever accepted
during registration.

### 4. `adm/daemons/logind.lpc` — §15h `check_legal_name()` bounds + sliding-window fix
- `strlen(name) < 2 || > 12` (GBK-byte bounds, i.e. "1 to 6 Chinese
  characters") halved to `< 1 || > 6` — matches the message text itself
  ("必须是一到六个中文字" = "must be one to six Chinese characters").
- Dropped the `i%2==0 &&` filter in the per-character Chinese-check loop —
  under UTF-8 every string index is already one full character (not every
  other byte), so every position needs checking now, not every other one.

### 5. `adm/daemons/logind.lpc` — §15p/§15ab: `encoding_to_mudlist()` unconditionally called into `dns_master` even after its own `find_object()` check failed
The GB/BIG5 selection handler already had `if( !find_object(DNS_MASTER) )
write("...")` — but then called `DNS_MASTER->query_muds()` and `Mud_name()`
(itself a macro wrapping `DNS_MASTER->query_mud_name()`) **unconditionally
on the very next lines regardless of that check's result**. Since
`"/path"->method()` lazily loads the target object if it isn't already
loaded, this would have triggered `dns_master.lpc`'s real `create()` (a
genuine `socket_bind()` + `resolve()` against an unreachable external boot
server, confirmed by reading the file) on literally the first prompt after
GB/BIG5 selection, for every single connection — exactly the class of hang
§15p exists to prevent, except merely excluding `dns_master` from
**preload** would NOT have stopped it here (§15ab's finding #2: inline calls
bypass the preload exclusion). Fixed by removing the entire intermud
mudlist-display block (purely cosmetic) and printing a short notice instead.
`dns_master` was ALSO removed from `adm/etc/preload` as the standard §15p
proactive step (belt-and-suspenders, since the daemon is never touched by
anything else on the registration path either).

### 6. `adm/etc/preload` — typo: `/d/npc/choose` → `/d/npc/choosed`
The actual file on disk is `d/npc/choosed.lpc` (a faction/sect-choosing NPC
daemon) — the preload entry was missing the trailing `d`. Master's own
`preload()` already gracefully no-ops on a missing file
(`if (file_size(file+".lpc")==-1) return;`), so this was silent/non-fatal,
but a one-character, zero-risk mechanical fix, so applied. (Same graceful
no-op already covers `/adm/daemons/backupd` and `/adm/daemons/storyd`, both
of which only have a stale `.bak` sibling in the raw archive and no real
`.c`/`.lpc` — confirmed these two are genuinely absent, not a typo, and left
alone.)

### 7. `master.lpc` — §14 `valid_override` upgraded to 3-arg; §8d/§15o `get_include_path()` added; §4 explicit reentrancy guard on `valid_read`/`valid_write`
- `valid_override(file, name)` → `valid_override(file, name, main_file)`,
  also allowing when `main_file` (not just `file`) is `SIMUL_EFUN_OB`/
  `MASTER_OB` (fragments `#include`d into simul_efun/master).
- Added `get_include_path()` (the standard §8d/§15o shape) so per-room/
  per-NPC local flavor headers included with `<angle.h>` next to the
  including file resolve both at preload and mid-connection. Confirmed two
  real instances of this pattern: `d/penglai/baihuagu.h` (used by 25
  `baihuagu*.c` quest-room files) and `d/dntg/laojun/maze.h` (used by 8
  `laojunmaze*.c` files) — `convert_lib.sh`'s automated
  angle-bracket-to-quotes conversion (169 files) already handles the common
  case where the header is quoted; `get_include_path()` is additional
  insurance for anything still using angle brackets.
- `valid_read`/`valid_write` already wrapped the lazy `SECURITY_D` load in
  `catch()` (unlike §4's canonical broken example, which had no `catch()` at
  all) — so the classic infinite-recursion crash was likely already avoided
  here. Added an explicit `loading_security_d` reentrancy flag anyway as
  cheap defense-in-depth, matching the catalog's standard shape.

### 8. `master.lpc` — §15w: `log_error()` was broadcasting every compile WARNING (not just real errors) to the connected player
Gated the player-facing `efun::write("编译时段错误："+message)` broadcast on
`strsrch(message, "warning:") == -1` (still logs everything to `/log/log`
regardless). Also hardened `error_handler()` (declared `void` on this driver
per `docs/apply/master/error_handler.md` — the mudlib's own comment
"whatever we return goes to the debug.log" assumes a return-value path that
doesn't actually exist here) with an explicit
`efun::write_file("/log/RUNTIME_ERRORS", ...)` inside a `catch()`, as
permanent insurance against silently-lost runtime errors.

### 9. `adm/simul_efun/message.lpc` — §15s `tell_room()` exclude-arg
`varargs void tell_room(mixed ob, string str, object *exclude)` passes
`exclude` straight to `message(..., exclude)`; when called in the
overwhelmingly common 2-arg form, `exclude` is int `0` (varargs default),
not an object/array. Guarded with `exclude || ({})`. **Caveat**: reading
this driver's actual `f_message()` C++ implementation
(`packages/core/efuns_main.cc`) shows the 4th-arg type switch already falls
through to "no exclusion" for any type other than object/array (including
`T_NUMBER`) with no `bad_argument()` call — so this specific driver
checkout may not actually reject a raw `int 0` here the way §15s's
originally-documented case did. Applied anyway since it's a free, zero-risk
fix matching the established pattern; **not confirmed to have been a live
bug on this specific driver build** (unlike the other fixes in this list,
which were all confirmed via a real compile/boot failure).

### 10. `d/obj/books-nonskill/book-qujing.lpc` — §15t pattern 1: absolute path inside angle-bracket `#include`
`#include </d/qujing/obstacle.h>` (an already-absolute path inside `<...>`,
which this driver's angle-bracket resolver never special-cases) fixed to
the quoted form `#include "/d/qujing/obstacle.h"`.

### 11. `obj/toy/{buwawa,mallet}.lpc` — missing local `message.h`
Both use `message_vision()` via `#include "message.h"`, but no `message.h`
exists under `obj/toy/`. The exact same file (byte-identical) already exists
under `d/obj/flower/message.h` and `d/obj/misc/message.h` — copied it into
`obj/toy/message.h` (low-risk: reusing the lib's own existing, already-used
copy, not fabricating new content).

### 12. `cmds/wiz/tail.lpc` — §8e: `tail()` is not a real FluffOS efun
Reimplemented in plain LPC (`read_file()` + `explode("\n")` + slice the
last 10 lines + `write(implode(...))`), matching the catalog's standard
pattern. Non-fatal (unused admin command), fixed for hygiene/consistency
with the rest of the project.

## Confirmed NOT needed (checked explicitly, not just assumed)

- **§15n** (custom `securityd.lpc` ACL blocking mid-connection lazy
  compiles): this lib's `valid_read` already returns `1` unconditionally
  for any `func` NOT in `{read_file, file_size, stat, read_bytes, tail,
  ed_start}` — i.e. `load_object`/`include`/`recompile_object` are already
  implicitly allowed by construction, the opposite ordering from the
  vulnerable shape in §15n. No fix needed.
- **§15ae** (`private nomask command_hook` breaking every post-login
  command): `feature/command.lpc`'s `command_hook` was **already**
  `nomask int command_hook(...)` with `private` commented out
  (`// private nomask int command_hook(string arg)`) by a prior author —
  confirmed both by reading the source and empirically (`look`/`score`/`i`
  all worked after registration in every test run).
- **§7** (`get_root_uid`/`get_bb_uid`): both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB`): `create()`
  is a single trivial `write()` line, no `destruct()` call at all.
- **§15u** (dormant phone-home license-bomb function): grepped
  `shutdown(`/`rm(`/`rmdir(`/`unlink(` across `securityd.lpc`/`master.lpc`/
  `band.lpc` for anything reading like a licensing/anti-piracy gate —
  nothing found.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode` don't exist,
  `__OLD_ED__`): the only hit for these three names anywhere in the lib is
  a string-literal comparison inside `securityd.lpc`'s `valid_read`
  (`func != "ed_start"`, just checking the driver's own passed-in `func`
  name) — not an actual call to any of the missing applies.
  `feature/message.lpc`'s `write_prompt()` doesn't call `ed()` either.
- **§15z** (`#define nosave static`/`#define protected static`
  compatibility shim): no such shim present anywhere.
- **§15r** (`check_config.lpc`-style driver-version self-check): no such
  file exists in this archive.
- **§15/§15v** (nitan-family simul_efun-based `set`/`query`/`delete` dbase
  bug, `LONELY_IMPROVED`-gated `efun::` family): this is NOT nitan/Lonely
  lineage — `feature/dbase.lpc` has real, local `set`/`query`/`delete`/
  `set_temp`/`query_temp` methods (confirmed by reading the file), and
  `adm/simul_efun/wizard.lpc` has no `set`/`query`/`delete` at all (only
  `wiz_level`/`wizhood`). No `LONELY_IMPROVED`/`efun::count`/`count_add`
  etc. anywhere.
- **§8f** (`TYPE * name1, name2;` missing-star bug): found 62 grep hits for
  the shape, spot-checked every one — all are genuinely-intentional scalar
  second declarators (e.g. `string *apply, type;` where `type` really is
  used as a single string, `int *value, i;` where `i` is a loop counter),
  not the Dead-Souls-style "forgotten star" bug. No fix applied.
- **§15am** (`file_size()==-1` truthy bug): every bare
  `if (file_size(...))` site in the lib already compares against
  `-1`/`<=0`/`>=0` explicitly.
- **§15x** (hardcoded `MUD_PORT` mismatch): `master.lpc`'s
  `connect(int port)` never dispatches behaviour on the port value at all
  (see fix #1 above) — no possible mismatch.
- **§15y** (mixed BIG5+GBK in one file): not spotted; `convert_lib.sh`'s
  lossy-conversion log didn't flag anything beyond the one straggler file
  (fix noted above), and a skim of banner/config/error-message text reads
  coherently.
- **§15aj** (missing mandatory gift/first-room object): `/d/wiz/init.lpc`
  (the post-registration "choose your gift" room `enter_world()` moves new
  characters to) exists and works correctly — verified interactively twice,
  both characters landed in it and were able to accept the default gift
  allocation and proceed into the real starting room.
- **§15al** (`crypt(str,0)` random-hash bug): this lib's `crypt(pass,0)` is
  only ever used for the ordinary "hash once, verify via
  `crypt(candidate, stored_hash)`" idiom — no client-independently-computed
  challenge/response protocol involved, so the random-salt behaviour is
  harmless here (verification re-uses the stored hash as the salt either
  way).
- **§8g-style missing-macro cascade** (like the `WQA_ROOM` example): none
  found — the two large "N-identical-failures" clusters in the `lpcc`
  sweep (the `p/fystreet` street-feature fragments and the
  `d/kaifeng/npc/quest*` fragment chain) were both confirmed to be genuine
  `#include`-only fragment files (§6b category 1), not a missing macro.

## Boot

Booted clean on `~/src/fluffos/build-debug/src/driver config.fluffos`
(launched via `setsid nohup ... & disown`, tracked by exact PID throughout,
never killed via a broad `pkill -f` pattern for this lib's own process) —
zero fatal errors, only ordinary compile warnings (`Unused local variable`,
`Unknown #pragma`) in `log/debug.log`. `Accepting telnet connections on
0.0.0.0:40080.` / `Initializations complete.` on every boot attempt after
fix #1/#2 above.

**Incident during this session (must be reported)**: while investigating a
stray driver-process listing, this agent ran `pkill -f "driver
config.fluffos"` — the exact broad-pattern kill AGENTS.md/TODO.md
explicitly warn against — which killed **two other agents' concurrently-
running driver processes** (archive #82, cwd `libs/xiyouji2006/work`, and
archive #83, cwd `libs/xiyouji450/work`) in addition to (harmlessly, since
mine wasn't running yet at that point) not affecting this lib. Both other
agents were observed to have relaunched their own drivers within the same
minute (new PIDs with the same cwd seen shortly after), so the immediate
damage self-corrected, but the parent session should be aware this happened
in case either of those archives' agents lost in-progress state or need to
re-verify their own boot/registration test as a result. Every kill after
this point in this session used the exact tracked PID only.

## Registration + post-login-command verification (§15ae standing policy)

Full flow verified via `mudclient.py` in **two independent continuous
connections**, both ending in a clean `quit`:

**Run 1** — id `qfeng`, Chinese name **秦风** (male):
`gb → no → new → qfeng → 秦风 → test12345 → test12345 →
qfeng@test.com → m → 9 → y` → landed in the mandatory gift-selection room,
accepted defaults, then **"只见眼前霞光一闪，你已经来到了一个陌生的世界"**
→ real starting room **南城客栈** (South City Inn, with board + 2 NPCs
visible) → `look` showed the full room description/exits/NPCs → `score`
showed a complete, correctly-gendered character sheet (age, race, stats,
HP/MP/food/water bars, kill count, cultivation levels) → `quit` →
"欢迎下次再来！" (clean disconnect).

**Run 2** (after the final round of post-sweep fixes, fresh driver
restart) — id `qinfengc`, Chinese name **秦岭** (female):
same full flow, landed in **南城客栈** again, `look`/`score`/`i` (inventory)
all produced correct, gender-appropriate output (e.g. "你目前待字闺中" —
female-specific flavor text — and "你是一位十四岁的女性人类" in `score`).
`grep -in "error|denied|crash|bad argument|undefined function"
log/debug.log` (excluding startup-banner config-flag lines) came back
**empty** for this entire run.

Both runs confirm: GB/BIG5 encoding selection, the (non-blocking) student
age-gate cosmetic prompt, English-id validation + uniqueness check, real
Chinese name acceptance (is_chinese fix), password set+confirm, email,
gender selection, the mandatory gift-allocation room, and landing in the
real game world all work end-to-end, and ordinary post-login commands
(`look`, `score`, `i`) produce real, correct output — satisfying the
project's standing policy (never mark a lib done without testing a
post-login command after registration).

## lpcc_check.sh sweep

Ran twice (before and after the post-boot content-fix pass). Final result:
**6420 / 6496 pass (98.83%)**. Memory stayed healthy throughout (free RAM
never dropped below ~4.4GB on a 23GB host; sweep completed in ~100s, well
inside the non-mega-lib bracket).

Triage of the 76 remaining failures (all cross-checked against the real
boot+registration+post-login `debug.log`, which shows **zero** occurrences
of any of these error strings — confirming none of these are live/reachable
bugs on the tested path):

- **~17 genuine runtime content gaps** (`call_other() couldn't find
  object`/`No such skill`): individual NPCs referencing item files or skill
  names that don't exist anywhere in this archive snapshot — e.g.
  `d/city/npc/taizong.lpc` (唐太宗/Emperor Taizong) tries to
  `carry_object(__DIR__"obj/longpao")->wear()` but `d/city/npc/obj/`
  doesn't exist at all (though *other* zones have their own `longpao.lpc`
  — not assumed to be the intended fix, since guessing the right one would
  be fabrication); `d/nanhai/npc/master.lpc` (玄智和尚) sets a skill
  `"chanting"` that was never implemented anywhere. Not fixed — genuine
  archive gaps, matches §13.
- **13 `#include`-only fragment files** compiled standalone by `lpcc`
  (`p/fystreet/{indoor,outdoor}_func.lpc`, the `d/kaifeng/npc/quest*.lpc`
  chain) — confirmed real NPCs `#include` these fine as part of their own
  compile unit; the `lpcc`-standalone failure is the documented §6b
  category-1 artifact, not a live bug (zero hits in the real debug.log).
- **8 network-subsystem missing-header failures**
  (`config.h`/`daemons.h`/`mailer.h`/`post.h`/`priv.h`/`uid.h` under
  `adm/daemons/network/*`) — all inside the DNS/intermud daemon family
  that's excluded from preload (fix #5/#6 above) and never touched by
  anything else; genuinely absent from the archive.
- **3 `d/kaifeng/npc/old/{shan,bei,zhi}.lpc`** — reference per-NPC quest
  headers (`quest_ak.h`, `quest_fd.h`, `quest_gv.h`, `quest_kl.h`,
  `reporting.h` outside its own directory) that don't exist anywhere in the
  archive. The `old/` folder name itself suggests deprecated/unfinished
  content — a genuine gap, not fixed.
- **~35 miscellaneous individual pre-existing items**, each confirmed
  low-impact and none reachable from the tested registration/look/score/i
  path: a few undefined admin-command helpers (`BACKUP_D`/`TEMP_DIR` in
  `cmds/adm/restore.lpc`, `dump_socket_status()` in `cmds/adm/dumpsocket
  .lpc`, `callouts()` in `cmds/wiz/block.lpc`), one alt/legacy `quit2.lpc`
  command with its own pre-existing missing-quote typo (the *actual*
  `quit` command was tested and works fine), a genuinely-undefined
  `F_DEALER` macro used by exactly one vendor NPC (`d/city/npc/huoji.lpc`
  — `F_VENDOR` exists and is plausibly the intended replacement, but not
  swapped in since that would be guessing intent rather than a confirmed
  fix), a "Too deep recursion" seen only when `lpcc` compiles
  `d/nanhai/guangchang.lpc` standalone (never reproduced in real
  interactive testing, and the zone was never visited by either test run —
  flagged, not chased further), and `d/nanhai/luohanta/a.lpc`, whose
  **raw pre-conversion content is literally just the word "test"** (5
  bytes) — a placeholder stub left by the original author, not something
  this pipeline broke.

## Directories created

- `libs/xixingzhanji/log/` (driver's own log directory, resolves relative
  to launch CWD per §6 — `work/log/`, `work/data/`, etc. already existed in
  the raw archive).
- `work/adm/tmp/`, `work/binaries/` (referenced by `config.fluffos`'s `swap
  file`/`save binaries directory`, didn't exist in the raw archive).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (6496 files): 6419
  reformatted, 77 already-clean/unchanged, 0 self-checked errors.
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿五") — gb/big5 encoding → student-age y/n → `New` →
  English id → Chinese name → password ×2 → email → gender → attribute
  screen (`9` then `y` to accept) → landed in the real starting room
  (`南城客栈`); `look`/`score`/`quit` all produced correct Chinese
  output. `log/debug.log` clean of real errors. Reformat + new driver
  build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly — the only preload-time errors are the expected non-fatal
  `Undefined function socket_create`/`socket_bind`/`socket_close` in
  `adm/daemons/ftpd.lpc` (no `sockets` package under WASM). Full
  registration flow **completed successfully** under WASM with a real
  Chinese name ("秦风测试"), same prompt sequence, reaching the same
  `南城客栈` room, `look`/`quit` both correct. The known
  `query_ip_number()` WASM limitation shows up cosmetically (the
  "您的网路连线地址为：" banner line prints blank instead of
  `127.0.0.1`), but this lib doesn't gate login on IP format anywhere
  reached by this flow, so it's display-only — a clean, fully-playable
  WASM result.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, or an empty/non-string/malformed IP
(covers older WASM `query_ip_number()` garbage). Gates patched:

- `adm/daemons/band.lpc`: added `IS_LOOPBACK_IP()` macro (before
  `is_banned()`, ~line 149) and loopback short-circuits at the top of
  `is_banned()`, `create_char_banned()`, and `is_strict_banned()`.
- `adm/daemons/logind.lpc::logon()` (~line 92): the per-IP anti-flood
  throttle (`login_cnt > 19` destruct) is now loopback-exempt.
- `adm/daemons/logind.lpc::login()` (~line 174): the per-host character
  cap (`ip_cnt >= 30` destruct) is now loopback-exempt (added local
  `cip` to the declaration list).
- No `uptime()` startup-grace gate exists in this lib (checked; the only
  `uptime()` uses are cosmetic/cmwhod).

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (gb → "no" student gate → new → id → Chinese name
→ password x2 → email → gender m → gift room "9" then "y"; no
super-password step in this lineage, unlike sibling xiaoyuxiyou). Granted
`(admin)` by appending `fluffos (admin)` to `/adm/etc/wizlist` (the
`WIZLIST` file read by `securityd.lpc::create()`). Verified after
reboot: login as fluffos → `update /adm/daemons/logind` →
"重新编译 ...成功！".

Retest: fresh normal registration (`qfxxzj` / 秦风) re-verified
end-to-end into 南城客栈 with `look`/`score`/`quit` correct; test saves
removed afterwards. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths are tracked, not
gitignored):
- `libs/xixingzhanji/work/data/user/f/fluffos.o`
- `libs/xixingzhanji/work/data/login/f/fluffos.o`
