# 梦幻西游2002版.rar → `menghuanxiyou2002`

- Archive: `archives/梦幻西游2002版.rar` (15.8MB — "梦幻西游(青岛站)" /
  "Fantasy Journey to the West (Qingdao Station)"). Self-identified name
  per `config.mhxy`: `name : 梦幻西游`; the in-game banner/welcome text
  brands it `梦幻西游(青岛站)`.
- Mudlib root: nested at `mhxy/world/` (same layout convention as archive
  #19). Config at `mhxy/config.mhxy` (MudOS 0.9.20 format, jjgod's
  Chinese localization of the standard MudOS sample config — same
  template as archive #19's `mhxy`).
- Port: **40050** (per TODO.md's next-free-port ledger at the time this
  archive was picked up; 40046-40049 reserved for archives #52-55 being
  processed concurrently).

## Lineage: SAME codebase as `mhxy` (archive #19) — confirmed via diff, not assumed from the title

The task brief called for verifying this explicitly rather than trusting
similar Chinese titles (per the project's repeated "similar titles ≠
same lineage" lesson) — and repeated for the opposite conclusion this
time: **this archive and archive #19 (`mhxy.rar`) are the same release**,
not just the same lineage family.

Diff method: extracted both archives' raw `mhxy/world/` trees and
compared file-by-file.
- **File tree structure**: byte-identical (both 14,563 files, identical
  path listing, zero diff in `find -type f | sort`).
- **Content**: md5sum every file in both trees and joined on path — only
  **2 real differences** out of 14,563 files:
  1. `adm/daemons/logind.c` — this archive's copy adds the branding
     string `(青岛站)` into two banner lines (`"梦幻西游现有注册玩家..."`
     → `"梦幻西游(青岛站)现有注册玩家..."`); everything else in the file
     (including `check_legal_name`, `check_legal_id`, the whole
     registration callback chain) is byte-identical to #19's copy.
  2. `adm/etc/wizlist` — differs (expected: reflects each site's actual
     wizard roster/admin state at snapshot time, not mudlib code).
  3. (A handful of duplicate-named `复件 (n).c` backup files under one
     NPC directory showed up as differing in a naive per-path md5 compare,
     but this was an artifact of `awk` field-splitting on the literal
     space in those filenames, not a real content difference — the
     files' multiset of hashes across that directory matched between
     the two trees.)
  - `adm/obj/master.c` and `adm/simul_efun/chinese.c` (the two files
    AGENTS.md specifically calls out to check): **byte-identical** to
    archive #19's copies, confirmed via md5sum before touching either.

Conclusion: this is effectively the SAME 2002-era mhxy release
re-uploaded/re-shared as its own archive, with only the site-branding
string edited. **Every fix already proven on `mhxy` (#19) was ported
directly** rather than rediscovered — confirmed applicable file-by-file
since the underlying source (aside from that one cosmetic string) is
identical.

## Status: DONE — boots clean, full registration flow verified end-to-end into the game world

## Fixes applied (all ported directly from `mhxy`/#19's proven fixes, confirmed applicable via the diff above)

1. **Standard conversion** (`scripts/convert_lib.sh`): GB18030→UTF-8 on
   every text file, `.c`→`.lpc` rename (11,785 `.lpc` files), literal
   `".c"` reference fixes, angle-bracket `#include <x.c>` fixes, local
   angle-bracket `#include <x.h>`→`"x.h"` conversion (same "west of
   xiyouji.org lineage" pattern noted as unusually common on #19), and
   `static`→`nosave` (confirmed 0 remaining `static` on functions/vars
   after the pass). A handful of files (`d/lingtai/obj/yuanpinzhu.lpc`,
   `u/tianlin/tianlin/*.lpc`, `d/qujing/start/24/12.lpc`,
   `daemon/class/yaomo/xueshan/cuixin-zhang/cuixin.lpc`) are flagged by
   `file` as "data" post-conversion but verified to be valid UTF-8 via
   `iconv -f UTF-8 -t UTF-8` — same known `file`-heuristic false-positive
   documented in #19's NOTES.md, not actually broken.
2. **AGENTS.md §15h (is_chinese / check_legal_name GBK byte-range bug)**
   — applied proactively to `adm/simul_efun/chinese.lpc`'s `is_chinese()`
   (GBK lead-byte range `str[0]>160 && str[0]<255` → CJK Unicode block
   `str[0]>=0x4e00 && str[0]<=0x9fff`) and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bounds `<2 || >12` → character-count
   bounds `<1 || >6`; dropped the `i%2==0 &&` byte-lead-position gate).
   Both functions were confirmed byte-for-byte identical to #19's
   PRE-fix originals before editing, so #19's already-proven fix was
   applied verbatim rather than re-derived.
3. **`adm/daemons/convertd.lpc`'s Greek-table stray-trailing-backslash
   typo (§8h)** — same 45 occurrences as #19 (confirmed: file is
   byte-identical), same CRLF gotcha (`s/\\"(,)?$/"\1\r/` — the naive
   `$`-anchored sed silently matches 0 without the `\r?` since the file
   has CRLF line endings). Fixed all 45 with the CRLF-aware pattern.
4. **`/u/feizei/log` missing file** — `adm/obj/master.lpc`'s
   `log_error()` does `efun::write_file(home + "log", message)` where
   `home = user_path("feizei") = "/u/feizei/"` (NOT `/u/tianlin/feizei/`,
   despite the wizard's actual home directory being nested under
   `tianlin/` — `user_path()` resolves independently of the real
   directory layout). The archive never shipped `/u/feizei/log` as a
   file, causing repeated `Wrong permissions for opening file
   /u/feizei/log for append` / `"No such file or directory"` errors
   every time `choose_feizei()` (a `baoshi`-daemon treasure-placement
   routine) ran during preload. **Gotcha hit while porting this fix**:
   the first attempt created `/u/feizei/log` as a DIRECTORY (mirroring
   the wrong mental model from the task description's phrasing "log
   directory"), which does NOT fix the problem — `write_file()` wants a
   plain FILE at that exact path, and a directory there causes the same
   class of open failure. Verified against #19's actual on-disk state
   (`libs/mhxy/work/u/feizei/log` is a 9.8KB **plain text file**, not a
   directory) before correcting: removed the directory, `touch`ed an
   empty file instead. Confirmed fixed by rebooting and diffing the
   error-count before/after: 14 occurrences → 0.
5. **§15p (DNS/intermud daemon preload exclusion)** — applied
   proactively before the first boot attempt: removed
   `/adm/daemons/network/dns_master` from `adm/etc/preload` (identical
   preload list to #19's, same standing project policy).

## What was checked and confirmed NOT needed (verified by reading the actual source, not assumed from #19's precedent)

- **§4 (master.lpc `load_object()`-in-`valid_read`/`valid_write`
  recursion)**: `master.lpc`'s `valid_read`/`valid_write` only call
  `find_object(SECURITY_D)`, never `load_object()` — no lazy-load
  recursion risk. `securityd` is preloaded up front. Confirmed by
  reading both functions directly; matches #19 (which also needed no §4
  fix).
- **§7 (`get_root_uid`/`get_bb_uid` master applies)**: both present in
  `master.lpc` (lines 205/210 in this copy). No stub needed.
- **§15l (master.lpc `create()` destructing `SIMUL_EFUN_OB`)**: grepped
  `master.lpc` for `destruct`/`SIMUL_EFUN_OB` — no such bootstrap-reload
  pattern present.
- **§8c / §15n (custom `securityd.lpc` `this_player()`-override /
  func-discrimination gap)**: this lib DOES have a genuinely custom
  `securityd.lpc` ACL (`exclude_read`/`trusted_read` tables keyed by
  euid/status), but its `valid_read()` already has the correct shape
  natively — it early-returns `1` (allow) for any `func` OTHER than
  `read_file`/`file_size`/`stat`/`read_bytes`/`tail`/`ed_start`, which
  means `load_object`/`recompile_object`/`include` (the driver's own
  compile-time file accesses) are never subjected to the ACL table at
  all. This is architecturally the *inverse* structure of the
  shujian2008-family bug (§15n) that needs an explicit allowlist added —
  here the allow-by-default-except-these-specific-data-read-funcs shape
  already has the correct behavior built in. No `this_player()`-override
  footgun (§8c) present either — grepped `securityd.lpc` for
  `this_player()`, zero hits. Confirmed empirically too: the real boot +
  full registration test produced **zero** "Read access denied" errors.
- **§8d/§15o (`get_include_path()` master apply for `<local.h>`-style
  includes)**: `master.lpc` does not define `get_include_path()` at all,
  and the lib has ~7,168 angle-bracket `#include <x.h>` directives, but
  the real boot + full registration test produced **zero** `Cannot
  #include` errors — `convert_lib.sh`'s automatic local-angle-bracket
  detection already converted every include that actually needed to
  resolve against its own directory into quote-form during conversion
  (matches #19's experience, where this was likewise not needed as a
  master.lpc-level fix).
- **§15 (nitan/NT-family simul_efun-based generic dbase architecture
  bug)**: `adm/simul_efun/wizard.lpc` (this lineage's simul_efun
  aggregate) defines no bare `set`/`query`/`delete`/`add` functions at
  all — grepped for the defining signatures, zero hits. This lineage's
  actual generic-property engine lives in `feature/dbase.lpc`, which
  already implements real LOCAL `set`/`query`/`delete`/`add` methods
  (confirmed by reading the file) — the architecturally-correct pattern,
  not the simul-efun-shared-storage bug. Not applicable to this lineage,
  same as #19.
- **named.lpc PATH()/sliding-window bug (part of the §15h family, common
  in the nitan lineage)**: `adm/daemons/named.lpc` in this lib is a
  Chinese-surname→pinyin lookup table (`mapping surname = (["赵":"zhao",
  ...])`), a completely different implementation from the nitan-family's
  byte-indexed `named.lpc` — no `PATH()` macro, no `strlen`/byte-offset
  logic present. Not applicable.
- **§8e (missing `tail()` efun)**: found exactly one call site,
  `cmds/wiz/tail.lpc:15` (`tail(file)`), a wizard admin command — same
  as lib #1's non-fatal instance, not lib #6's fatal
  compiled-into-simul_efun instance. This file is never preloaded or
  `#include`d elsewhere; it only shows up as one `lpcc`-sweep failure,
  confirmed absent from the real boot/registration debug.log. Not fixed
  (dead-unless-invoked admin tool, out of scope per the "breadth over
  depth" policy).

## Boot verification

`cd libs/menghuanxiyou2002 && ~/src/fluffos/build-debug/src/driver config.fluffos`
— accepts telnet connections within ~1 second of start; preload of the
full NPC/room tree (hundreds of `/d/qujing/...` treasure-placement NPCs
via `adm/daemons/baoshi.lpc`) continues for roughly another 1-2 minutes
in the background after the socket opens. **Zero FATAL errors, zero
SIGSEGV, zero "Read access denied", zero "Cannot #include", zero
"Undefined function" across the full boot.** The only recurring
non-fatal error categories seen in `log/debug.log` across a full boot
(all confirmed non-blocking, all caught by the preload loop's own
`CATCH()`):
- 5-6× `*Too long evaluation. Execution aborted.` — a `baoshi.lpc`
  treasure-placement routine occasionally exceeds the 400,000usec eval
  budget while placing a large batch of preload NPCs/items; aborts that
  one placement call, preload continues normally afterward.
- 1× `*restore_object(): Illegal mapping format while restoring emote.`
  — `adm/daemons/emoted.lpc`'s save data (`/data/emoted`) has a corrupted
  entry in the ORIGINAL archive (same known category as archive #1's
  seed-data corruption, not introduced by this conversion pass); caught
  by master's preload `CATCH()`, daemon continues with an empty
  emote-history mapping.
- 1× `*Bad argument 1 to EFUN call_other()` in
  `adm/daemons/questd.lpc:153` (`spread_quest()`) — a `create_object`
  style factory call returning `0` for one quest-room path with no
  `objectp()` guard at the call site (§15e-shaped pattern); caught by
  preload's `CATCH()`, does not block boot or any other daemon.
- 1× `*Can't catch eval cost too big error.`

## Registration flow — read from source before testing

Read `adm/daemons/logind.lpc`'s full `input_to` callback chain before
scripting the test (per the task's explicit instruction — hidden
pre-id gates have bitten other libs in this project):
`logon()` → (GB/BIG5 encoding prompt, conditionally compiled under
`#ifdef GB_AND_BIG5`) → `encoding()` → age-gate `if_young()` ("are you a
student", any non-"no" answer ends the session) → `get_id()` (English
id; typing the literal `new` branches to new-player registration) →
`get_new_id()` (pick an English id) → `confirm_id()` (auto-invoked with
"Yes", no separate y/n prompt) → `get_name()` (**the Chinese name
prompt, gated by `check_legal_name`/`is_chinese`** — the fix under
test) → `new_password()` → `confirm_password()` → `get_new_superpasswd()`
(a SEPARATE "identity token" password, must contain both upper- and
lower-case letters plus a non-letter character, ≥6 chars) →
`confirm_new_superpasswd()` → `get_email()` → `get_webpage()` →
`get_icq()` → `get_gender()` → `confirm_gift()` (auto-invoked with
default `"n"`, sets up starting stats) → `enter_world()`. No hidden
client-version/BIG5-literal gate found in this chain (unlike
xiyangzaixian3's §15q case) — the only pre-id gate is the visible
GB/BIG5 encoding choice and the age-gate question, both confirmed by
reading the code, not inferred from prompt text.

Also checked `banned_name`/`banned_id` lists (`logind.lpc`'s
`banned_name` array, `adm/etc/banned_id` file) to pick a real test name
that wasn't pre-rejected: `"秦风"` / id `"qinfeng"` — neither is banned
in this lib's lists (banned names here: 你/我/他/她/它/江泽民/邓小平/
李鹏/朱榕基/自己/某人/尸体/我们/你们/他们/大家/他妈的/去你的/毛泽东/巫师/
他奶奶的/田林/田/杜剑锋/杜剑/杜/尹/尹斌/晕/雲/暈/李).

## Registration flow — actual transcript outcome (ONE continuous `mudclient.py` connection)

```
python3 scripts/mudclient.py 127.0.0.1 40050 --timeout 20 \
  --send "gb" --send "no" --send "new" --send "qinfeng" \
  --send "秦风" --send "test1234" --send "test1234" \
  --send "Qinfeng123" --send "Qinfeng123" \
  --send "qinfeng@example.com" --send "" --send "12345" --send "m" \
  --send "look" --send "quit"
```

Outcome, in order, all confirmed from the actual transcript (not
inferred):
1. `"gb"` → GB banner accepted, full MOTD/stats/uptime banner rendered
   correctly in UTF-8 Chinese, no mojibake.
2. `"no"` → student age-gate passed, advanced past it.
3. `"new"` at the English-id prompt → "欢迎您，新玩家!" (welcome new
   player) banner shown, advanced to `get_new_id`.
4. `"qinfeng"` → accepted as a legal, unused English id (3-8 lowercase
   letters, not in `banned_id`, no existing save file) — advanced
   straight to the Chinese-name prompt with NO rejection message.
5. **`"秦风"`** (the critical test) → accepted with **NO** "对不起，
   请您用「中文」取名字" / "至少要..." rejection message — advanced
   directly to "请设定您的密码：" (set your password). This is the
   §15h fix working correctly, confirmed by the flow actually
   advancing to the next stage, not just reaching the prompt.
6. Password set (`test1234`, ≥5 chars) and confirmed — no mismatch
   rejection, advanced to the superpasswd prompt.
7. Superpasswd set (`Qinfeng123` — has uppercase Q, lowercase, and
   digits, ≥6 chars) and confirmed — no rejection, advanced through
   email/webpage/icq prompts.
8. Gender `"m"` selected → auto-flowed through `confirm_gift()` and
   `enter_world()` with **zero crash** — reached the actual gift/stat
   allocation screen ("请选择你想重新设置哪一项天赋的取值[0-3]") and the
   full in-game welcome banner/MOTD/news feed, i.e. **the real game
   world**, not just a login-adjacent prompt.
9. One pre-existing cosmetic wart (present verbatim in #19 too, not
   introduced by this conversion): `get_name()` has a leftover debug
   `printf("%O\n", ob);` right before `ob->set("name", arg)`, which
   leaks the object's default string representation
   (`/obj/login#81`-shaped text) into the player's own terminal for one
   line. Harmless, not fixed (pre-existing in the original archive,
   confirmed identical in #19's copy).
10. Some `default error message` ("你发现事情不大对了，但是又说不上来。")
    lines appeared interleaved in the transcript during registration —
    traced to `master.lpc log_error()`'s behavior of broadcasting the
    generic error message to `this_player(1)` for ANY preload-time error
    that happens to fire while a player connection exists (this test ran
    while the background NPC-tree preload was still active) — i.e. this
    is preload noise bleeding into the only connected session's screen,
    not a registration-flow defect. Confirmed non-blocking: the flow
    still advanced correctly at every single prompt with no re-prompt or
    rejection.

**Definitive independent confirmation** (beyond the transcript): the
completed registration was actually **persisted to disk** with the
correct Chinese name, in valid UTF-8:
```
$ grep -a name libs/menghuanxiyou2002/work/data/login/q/qinfeng.o
dbase (["email":"qinfeng@example.com",...,"name":"秦风","icq":"12345",...])
$ grep -a name libs/menghuanxiyou2002/work/data/user/q/qinfeng.o
dbase (["...,"gender":"男性",...,"race":"人类",...,"name":"秦风",...])
```
Both the login record and the full player-body record (race, gender,
starting stats, channels) were created and saved correctly with the
real Chinese name intact.

## `lpcc_check.sh` sweep result

**11,468 / 11,785 pass (97.31%)** — essentially identical to #19's
97.3% (expected, given the near-identical codebase). 317 failures
triaged by category (not all individually fixed, consistent with
AGENTS.md §6b's "triage by category, fix genuine bugs, note the rest"
policy — none of the categories below appear anywhere in the real boot
log):
- **~40+ failures**: NPC/room files under `u/tianlin/d/shaolin/`,
  `d/qujing/kusongbak/`, `d/guzhanchang/`, `u/redrain/menpai/d/tianpeng/`
  etc. referencing zone/NPC paths that genuinely don't exist anywhere in
  this archive (e.g. `/daemon/class/shaolin/cheng-shi` — confirmed via
  `find` that neither the directory nor the file exists anywhere in the
  tree). This is AGENTS.md §13's "missing zone content is a real archive
  gap, not a bug" category — these rooms/NPCs are never on any preload
  list and never touched by normal play.
- **22 failures**: `error: Unable to find the inherited function
  'setup'` and related "Undefined function query" cascades, all rooted
  in quest-definition fragment files (e.g. `d/kaifeng/npc/quest.lpc`,
  `#include`d by `quest_wr.lpc` and siblings) that are `#include`-only
  data/logic fragments with no `inherit` of their own — meant to be
  pulled into a real NPC file that already inherits the right base
  class, not compiled standalone. Confirmed via source read (no
  `inherit` statement in the fragment) and confirmed absent from the
  real boot log — classic §6b fragment-file sweep artifact.
- **13 failures**: `www/cgi-bin/*.lpc` files using an undefined
  `F_REMOVEANSI` macro (`inherit F_REMOVEANSI;` with no corresponding
  `#define` anywhere in `include/`). This is a legacy web-CGI interface
  subsystem, entirely separate from and never touched by the telnet
  mudlib (confirmed absent from the boot log) — a real but low-priority
  content gap in a feature area out of scope for this conversion.
- **Remainder (~240 failures)**: a long tail of one-off syntax errors,
  undefined variables (`SAVE_EXTENSION`, `F_DISASTER`, `WELCOMEN`, `ID`),
  and "Illegal character" hits scattered across individual, rarely-
  reached NPC/item/room files — consistent with genuine pre-existing
  authoring-era typos in content that was never exercised during
  original play either (the same long-tail pattern documented across
  most other libs in this project). Not fixed given the "breadth over
  depth" policy and the fact that none of them touch the boot or
  registration path.

## How to re-run

```
cd libs/menghuanxiyou2002
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40050 --timeout 20 \
  --send "gb" --send "no" --send "look" --send "quit"
```
(Use a fresh, never-before-used id/name if re-testing full registration
— `qinfeng`/`秦风` is already registered from this pass's test, saved
under `data/login/q/qinfeng.o` and `data/user/q/qinfeng.o`.)

Driver process was killed after testing — confirmed no lingering
`driver config.fluffos` process left running on port 40050 or
otherwise.

## QA re-verification pass (2026-07-23) — found and fixed a real, intermittent bug plus two minor robustness gaps

**Bug found: ~1-in-6 chance every connection silently died with zero output
at the very first prompt.** `adm/daemons/logind.lpc`'s `logon()` picks a
random banner via `switch(random(6))` between `BANNER`/`BANNER1`..`BANNER5`
(`include/login.h`: `/adm/etc/banner`, `/adm/etc/banner1`..`banner5`). Only
`banner1`..`banner5` existed on disk — the base `/adm/etc/banner` (no
numeric suffix) did not, only a differently-cased `/adm/etc/Banner` (a
Windows-origin case-sensitivity mismatch, AGENTS.md §15k's pattern). Since
`cat()` is `write(read_file(file))`, a missing file makes `read_file()`
return `0`, and `write(0)` then threw inside the player object's
`receive_message()`, which the driver's `new_conn_handler` catches by
silently disconnecting the connection with **zero output at all** — exactly
matching an apparently "hung"/dead server, but only on the `random(6)==0`
branch (~16.7% of connections). Confirmed by direct read of `logon()` and by
reproducing it live (my first test connection hit exactly this branch).
Fixed by `cp adm/etc/Banner adm/etc/banner` (matching AGENTS.md §15k's
established fix pattern — copy to the exact case-sensitive path the code
expects, leave the original in place too). Re-verified with 8 quick
connection attempts plus a full registration — no further silent
disconnects, and the previously-missing banner variant now renders correctly
when selected.

**Second fix**: `adm/obj/master.lpc`'s `log_error()` broadcast every message
reaching it — including ordinary compile *warnings*, not just real errors —
to a connected non-wizard player as the alarming generic `default error
message`. A real registration session showed several of these lines
interleaved with the registration prompts (this was already noted as
"preload noise" in the original pass's NOTES above, but not fixed). Applied
the standard AGENTS.md §15w fix: gate the broadcast on the message NOT
containing `"warning:"`, still logging everything to file regardless.
Verified: a post-fix registration session showed zero such lines.

**Third, minor fix**: the gift-finalization step (`d/wiz/init.lpc`'s
`do_finish()`) triggers a `log_error()`-adjacent write to
`/u/npc/log` (a lazily-compiled file's `file_owner()` resolves to wizard
"npc", whose home directory was never shipped in this archive) — every new
character's registration hit `*Wrong permissions for opening file
/u/npc/log for append. "No such file or directory"` (caught, non-fatal, same
class as the already-documented `/u/feizei/log` fix from the original pass,
just a different user). Fixed the same way: created `/u/npc/` and an empty
`/u/npc/log` file (not a directory).

**Re-verified after all three fixes**: full registration (`gb → no → new →
id → 中文姓名 → password ×2 → 身份标识 ×2 → email → webpage → icq → gender →
gift-accept(9,y)`) followed by `look`/`score`/`quit`, with both genders
(male "秦岭十三" / female "秦岭十四" — the female run also showed correct
gender-specific NPC dialogue "这位小姑娘"). Both landed correctly in the real
starting room (南城客栈), `look` and `score` rendered correctly, zero
`"你发现事情不大对了"` spam and zero new runtime errors beyond the
already-documented pre-existing preload noise (corrupted `emote` save data,
one `questd.lpc` factory-return-0 gap, a few `baoshi.lpc` eval-cost
timeouts during large treasure-placement batches — all non-fatal, all
pre-existing, none on the registration/gameplay path).
