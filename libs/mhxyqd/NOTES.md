# 梦幻西游2002版.rar → `mhxyqd`

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

`cd libs/mhxyqd && ~/src/fluffos/build-debug/src/driver config.fluffos`
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
xyzx3's §15q case) — the only pre-id gate is the visible
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
$ grep -a name libs/mhxyqd/work/data/login/q/qinfeng.o
dbase (["email":"qinfeng@example.com",...,"name":"秦风","icq":"12345",...])
$ grep -a name libs/mhxyqd/work/data/user/q/qinfeng.o
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
cd libs/mhxyqd
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

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter**: ran `format-corpus.mjs` over all 11,785 `.lpc`
  files — 11,635 reformatted in place, 112 already-idempotent, 38
  refused (nonzero `errors` expected/fine per the tool's own contract).
  Double-checked the §15k `adm/etc/banner` case-fix (`cp adm/etc/Banner
  adm/etc/banner`) survived — both files still present post-reformat.
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, freshly rebuilt from upstream master): booted clean,
  zero fatal errors. Full registration re-verified with fresh real
  names (秦风田, plus 秦风齐/秦风水 during flow discovery) via the
  documented `gb → no → new → id → 中文姓名 → password×2 → 身份标识×2 →
  email → webpage → icq → gender → gift(9,y)` flow; arrived correctly
  in 南城客栈 (banner rendered correctly, confirming §15k still holds),
  `look`/`score`/`quit` all correct. One single non-fatal, self-recovering
  `Too deep recursion.` (`/feature/name.lpc:14`, triggered by a lazily-
  compiled `/d/moon/npc/zhangmen` NPC during one run) was observed —
  the driver's recursion guard caught it and continued, the connection
  was unaffected (registration/look/score/quit all still succeeded in
  that same run) — noted as a pre-existing quirk, not chased further
  per this lib's breadth-over-depth policy. No regressions from the
  rebuilt driver or the reformat pass; nothing required fixing.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process (the sockets-requiring
  `ftpd.lpc`/`httpd.lpc` daemons correctly throw `Undefined function
  socket_create` etc. under WASM's no-`sockets`-package build, caught
  non-fatally by `master.lpc`'s preload `catch()`, same as natively
  when the package is absent). **Login is blocked**, but via a
  different concrete mechanism than the simple ban-check case: this
  lib's `logind.lpc` `encoding()` step calls into
  `adm/daemons/ipd.lpc`'s `seek_ip_address(query_ip_number(ob))` to do
  a geographic ISP lookup, and `seek_ip_address()` does
  `explode(ip, ".")` then indexes `user_ip[1]` assuming a real
  dotted-quad; under WASM's malformed/empty `query_ip_number()` return
  value this throws an uncaught `Array index out of bounds` (not even
  wrapped in `catch()`), which unwinds far enough to leave the
  connection stuck emitting "什么？" (unknown command) for every
  further input instead of ever reaching the id/name prompts. Root
  cause is the same documented `query_ip_number()` WASM limitation as
  the simpler ban-check case seen elsewhere in this batch — confirmed
  by the clean native run above using the identical code path on
  `127.0.0.1` — so no mudlib fix was attempted. Classified as: boots
  under WASM; login blocked by the driver's known `query_ip_number()`
  limitation (this lib's manifestation: an uncaught array-bounds error
  in its IP-geolocation daemon, rather than an explicit ban check).

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard pass per AGENTS.md §1.3(b)/(e), §1.5.

**Gates patched (all tightened to strict loopback -- see fail-closed
correction below):**
- `adm/daemons/band.lpc` `_is_loopback()` helper (~line 148), shared by
  `is_banned()` (~155), `create_char_banned()` (~170), and
  `is_strict_banned()` (~185): strict loopback short-circuits `return 0`
  before the regexp site-list scan.
- `adm/daemons/logind.lpc` `encoding()` (~line 156, `is_loopback` local):
  gates the "no IP name" kick (~175), the non-numeric-IP kick (~181), and
  the 40-characters-per-host cap (~215) — all three now apply to
  everything except strict loopback.
- `adm/daemons/logind.lpc` `get_id()` (~line 413): the per-IP
  multi-login cap (`NowLogin >= MaxLimit`) now applies to everything
  except strict loopback.
- `adm/daemons/securityd.lpc` `match_wiz_site()` (~line 117): strict
  loopback always matches (wizard per-site login restriction).
- `adm/daemons/ipd.lpc` `seek_ip_address()` (~line 13): NOT a security
  gate — this is the crash-prevention guard already documented above
  (§ "Re-verification pass") against the `explode()`/array-index crash
  on a malformed IP; kept as-is (returns `"本地"` cosmetic placeholder),
  no fail-closed retrofit needed since it grants no access.
- Uptime startup gate: none found.
- Anti-flood throttle: covered by the `is_loopback`/`NowLogin` gates
  above (this lineage's throttles are per-IP character-count caps, not a
  separate connect-time gate).

**Fail-closed correction (retrofit):** every gate above (except
`ipd.lpc`, which is not a security gate) was initially written with a
`!stringp(ip)`/`ip == ""` "treat malformed IP as loopback" fallback per
the original pre-driver-fix instructions. Since `query_ip_number()` is
now fixed upstream and always returns a clean `127.0.0.1` for loopback,
that fallback was tightened to strict `127.0.0.1`/`localhost`/`::1`/
`127.*` matching only — a malformed/non-string IP now falls through to
the ORIGINAL gate logic (fail closed) instead of being waved through.
Retested after tightening: `fluffos` loopback login + `update` still
works (native and WASM).

**Admin account:** id `fluffos`, pw `Mud@2026`, name 浮浮, `(admin)` via
`adm/etc/wizlist` (already registered by save-file evidence on disk when
this pass started; wizlist entry present). Verified: relogin as
`fluffos` shows 仙衔 `【天神】`; `update /adm/daemons/band` → 重新编译
：成功. Note: as a wizard, `fluffos` transits `/d/wiz/init` (the gift/
attribute-allocation room) on EVERY login, not just first registration —
this is `init.lpc`'s own `init()` logic (the "skip if already has
combat_exp/daoxing/no_gift" early-return only applies to non-wizards),
not a bug; just press `9` then `y` each time.
Save files (untracked, NOT gitignored — orchestrator must add):
`work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

**Retest:** fresh normal registration (id `ceshiliu`, name 秦风寅)
end-to-end OK (look/score/quit correct); test character saves removed
afterward — `ceshiliu` (this pass) and `ceshiwu` (an untracked leftover
from an earlier interrupted pass, confirmed via `git ls-files` to NOT be
committed, safe to delete). **Caution for future passes:** `qinfeng`
(`data/{user,login}/q/qinfeng.o`) LOOKS like a similar test-registration
leftover (it's documented above at "Registration flow — actual
transcript outcome" as this project's own earlier test character) but IS
committed to git (`git log -- ...qinfeng.o` → part of the original
`Add mhxyqd` commit) — it was deleted once during this pass by
mistake and had to be restored via `git show HEAD:path > path`; do NOT
delete it as "test-character cleanup" without first checking
`git ls-files`/`git log` on the exact path. No new errors in debug.log.
WASM retest (`wasm_client.js`): `fluffos`
login + `score` + `quit` also verified working post-`ipd.lpc`-guard —
this lib's WASM-login-blocked verdict in the "Re-verification pass"
section above is now superseded; WASM is fully playable.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一套代码库，14561/14563 个档案完全相同。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：完整流程（GB/BIG5 选择→未成年人关卡（否）→管理员 id+密码→如果存档数据还没经历过，登录成功后会立即在 /d/wiz/init.lpc 触发一次仅限首次的天赋/礼物定制画面，用'9'接受再用'y'确认）全程无错误地进入"南城客栈"，quit 也干净（"浮浮(Fluffos)离开游戏了"）。

## 深度功能测试（§10.7，本轮）：发现并修复一处真实的 printf 调试残留 leak，加上 3 处 §7.68 死亡软锁

这份档案此前只做过注册流程验证，没有真正玩到移动/战斗/死亡。这次先
核对了最近几轮在 jqxz2008/xkx2017/xkx100 系列上确认过的 5 个 bug——
虽然本档案自己的 README 说和 xyj2000f 同属"ES II 引擎家族/西游题材"，
但实测下来这几个 bug **一个都不存在**：`adm/daemons/logind.lpc` 没有
`ob->query("age") == 14` 这种错对象的年龄检查、`chinesed.lpc` 存在但
自己的 `data/e2c_dict.o` 根本不存在（同 xkx100，`restore()` 对着不存
在的档案不会抛异常）、`combatd.lpc`/`kill.lpc` 完全没有往
`/log/nosave/` 写任何东西、`bai.lpc`/`apprentice.lpc` 也没有那处括号
错误。说明这份档案和 jqxz2008/xkx 那条分支实际上是不同的、独立演化
的 ES II 变体，不能想当然地认为"同宗必有同 bug"。

**不过还是找到了一个真实、独立的 bug**：`adm/daemons/logind.lpc` 的
`get_name()` 函式在成功接受玩家的中文名字后，紧接着有一行明显的调试
残留 `printf("%O\n", ob);`——每一个新玩家输入完中文名字、正要进入下
一步设定密码的那一刻，都会在屏幕上看到一行 `/obj/login#123` 这样的
原始物件引用字串，纯属调试遗留、没有清理干净。已经删除这一行。用真
实驱动分两次完整注册验证：删除前能重现（"您的中文名字：/obj/login#123"
后紧接着"请设定您的密码："），删除后干净地直接进入密码设定，不再出
现物件引用。（在 `www/`、`adm/daemons/network/dns_master.lpc`、
`cmds/eld/where.lpc` 里也发现了同款 `printf("%O\n", ...)`，但这些都
不在真人玩家会走到的注册/游戏路径上——网页端专用副本、DNS 精灵、巫
师专属指令——本轮判断不在范围内，未处理。）

**另外发现并修复了 3 处 §7.68 死亡/复活软锁**：`d/death/npc/{b,
bgargoyle,wgargoyle}.lpc` 的 `death_stage()` 都有
`if (!ob || !present(ob)) return;` 这种把"角色永久离开"和"角色只是
暂时不在场"混在一起处理的写法，按各文件自己的重试间隔（均为 5 秒）
拆分成"暂时不在场则重试"。

用真实驱动完整验证了两次全新注册（走完英文 id→new→中文名字→登录密
码→身份标识/超级密码→email→个人主页→ICQ→性别→天赋赠礼确认的完整
流程，比 jqxz2008/xkx 系列多了身份标识和个人主页/ICQ 三个额外步骤），
成功进入"南城客栈"，NPC"黄飞鸿""孙悟空""店小二"都正确打招呼；
`score` 显示食物/饮水状态均为"正常"（不是空的，本来就没有 §8.9 那
个 bug）；在"南城客栈"尝试攻击"孙悟空"被正确挡下（"这里不准战斗。"，
合理设计不是 bug）；移动到"朱雀大街"实际攻击了游荡 NPC"疥顶小僧"，
角色被打死，干净地触发"你死了"→"阴阳界"死亡场景→NPC"崔判官"自动
（不需要玩家任何操作）念白+翻生死簿+还阳，把角色送到复活点"荒郊小
店"——`debug.log` 全程保持空白，确认没有任何遗留问题。

### 未继续测试的部分

时间关系，没有测试拜师、购物、留言板（虽然已经看到留言板存在且有历
史留言）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-14，post driver-upgrade re-test）

Round-two re-verification pass against the rebuilt `fluffos` driver
(picks up upstream PRs #1343/#1344) plus the corpus-wide `quest_times`
`%`-operator fix — neither of which touches this lib's own code paths,
but a live re-play was still warranted since this lib was last tested
before the rebuild.

**All previously-documented fixes independently re-verified still in
place** (grepped/read the actual source, not just NOTES.md prose):
`adm/etc/banner` exists as a real file alongside `Banner` (§15k case
fix), `adm/obj/master.lpc`'s `log_error()` still gates the broadcast on
`strsrch(message, "arning:") == -1` (§15w), `/u/npc/log` and
`/u/feizei/log` are both plain files (not directories), `logind.lpc`'s
`get_name()` debug-leak `printf("%O\n", ob);` is gone,
`is_chinese()`/`check_legal_name()` still use the CJK-codepoint /
character-count logic (not the old GBK byte-range check), and the
`d/death/npc/{b,bgargoyle,wgargoyle}.lpc` death files still carry the
ORIGINAL single-check `if (!ob || !present(ob)) return;` shape — the
2026-08-05 §7.68 revocation held, no regression crept back in. The
§7.86 board `replace_program()` sweep fix also spot-checked clean (0
files remaining with both a `BBS_BOARD`/`BULLETIN_BOARD` `inherit` and
a redundant `replace_program()`).

**New standard-checklist items checked this round (not previously
checked in this lib's history):**

1. **`adm/simul_efun/file.lpc`**: `log_file()` (line 7) textually
   precedes `assure_file()` (line 11), but `log_file()` doesn't call
   `assure_file()` at all — no forward-declaration risk here, unlike
   the sibling `mhxy`'s finding this session. No fix needed.
2. **`config.fluffos`'s `maximum evaluation cost`**: was `400000`,
   matching the exact value that caused 100%-reproducible
   `enter_world()`/`make_body()` aborts on the sibling `mhxy` this
   session (and matching this lib's own previously-documented
   `*Too long evaluation.`/`*Can't catch eval cost too big error.`
   preload noise). Raised to `5000000` (matching `mhxy`'s fix).
   Re-verified live: the preload's previously-documented eval-cost
   error categories (`Too long evaluation`, `Can't catch eval cost too
   big error`) are now **zero** across a full boot, vs. the
   previously-documented handful per boot.
3. **§7.106 (`cmds/wiz/update.lpc`'s `present(file, environment(me))`
   crash)**: already fixed (`environment(me) && (obj = present(file,
   environment(me))) && interactive(obj)`) — this lib was one of the
   135 libs covered by the corpus-wide mechanical sweep referenced in
   AGENTS.md §7.106. Live-verified: `update /adm/daemons/band` as
   admin succeeded cleanly (`重新编译 /adm/daemons/band.lpc：成功！`).

**New bug found and fixed (not from the standard checklist, found
while executing this round's required "two rapid reconnects" step):**
the admin account (a wizard) got blocked by the 40-second "刚退出就想
进来？为了降低系统负荷，还是等一小会再连入吧！" quick-reconnect
throttle in `adm/daemons/logind.lpc`'s `get_passwd()`, even though the
guard is written as `!wizardp(user) && ...` (i.e. intended to exempt
wizards). `wizardp(user)` evaluates false at this point in the login
sequence (before `enter_world()` grants full wizard status to the
freshly-restored body), so the exemption never actually fires for
anyone, admin included — reproduced live twice. The byte-identical
sibling `mhxy` hit and fixed this exact gap earlier this session by
adding an explicit loopback-IP exemption alongside the (non-functional
at this point) `wizardp()` check; ported that fix verbatim: a new
`reconn_ip` local captures `query_ip_number(ob)`, and the throttle is
skipped when it's `"127.0.0.1"`, `"::1"`, or a `"127."`-prefixed
string. Verified live: recompiled `logind.lpc` via `update`, then did
two back-to-back quit→reconnect cycles within a few seconds each —
both landed straight back into the game with no throttle message
(previously reproduced the block twice before the fix). This gap was
present in the archive from the original conversion; the
WASM-enablement pass's loopback carve-outs (band.lpc, `encoding()`'s
IP/host-cap gates, `get_id()`'s multi-login cap, `securityd.lpc`'s
`match_wiz_site()`) evidently didn't cover this specific throttle site
when `mhxy` and `mhxyqd` diverged in prior passes — now aligned with
`mhxy`.

**Live re-play** (real driver, `scripts/tmux_mud.sh`, existing admin
account, logging in via `gb → no → id → password`, transiting
`/d/wiz/init` with `9` then `y` each login as documented): confirmed
`look`/`score` render correctly (food/water both "正常", no §8.9
issue), `update` gives real write access, and re-walked the exact
death/resurrection path this lib's original §10.7 pass documented —
moved 南城客栈 → 朱雀大街 (west), attacked 疥顶小僧 (`kill seng`; the
`kill jieding` alias from the original NOTES no longer resolves since
the NPC's id list is `({"jieding xiaoseng", "xiaoseng", "seng"})`, not
a bare `"jieding"` token — a client/id quirk, not a mudlib bug), died,
landed at 「阴阳界」, and 崔判官 auto-ran the full unattended dialogue
→ judgment → "送你还阳" sequence, landing cleanly at 「荒郊小店」 —
identical to the pass documented before the driver upgrade.
`log/debug.log` grew only with expected lazy-compile warnings (unused
locals, a couple of pre-existing signature mismatches) across the
entire session; zero FATAL, zero SIGSEGV, zero new error classes.

**Process/repo hygiene**: driver killed by exact PID (`kill 1638278`,
confirmed dead via `ps`), never `pkill -f`. `git status --short
libs/mhxyqd/` post-test showed only the two genuine fixes
(`config.fluffos`, `adm/daemons/logind.lpc`) plus the admin's own
`data/{login,user}/f/fluffos.o` saves (real gameplay state from this
session — timestamp, kill/death record, stat drain from the death
tested above) — all kept. Six untracked `data/{login,user}/c/chen{ba,
shi,wu}.o` files predate this session (timestamped 2026-08-05, not in
`git ls-files`) and were left untouched, consistent with this lib's own
caution about not deleting unfamiliar test-character residue without
checking history first; `qinfeng`'s committed save files were not
touched.

## §7.100 sweep fix (`ROOM` base-class redundant `replace_program()`)

`#define ROOM "/std/room"`: deleted 550 redundant, live, standalone
`replace_program(ROOM);` lines (kept `inherit ROOM;`) — 548 caught by
the scripted sweep, plus 2 hand-fixed instances baked into the two
copies of this lib's room-building tool (`obj/roommaker.lpc`,
`clone/misc/roommaker.lpc`), same shape as sibling `mhxy`. 8
pre-existing `//`-commented instances remain untouched, confirmed
harmless. Verified via a clean `build-debug` driver boot (0 new
compile errors, port 40050 listening, zero new "cannot replace"/
"cannot bind" `debug.log` lines) plus a raw-socket connectivity check
(login banner rendered correctly) — a handful of transient "Too deep
recursion" errors during a weapon object's lazy compile
(`d/obj/weapon/mace/copperjian.lpc`, `/adm/obj/master.lpc:433`)
appeared well after "Initializations complete" and are unrelated to
this fix (no room/ROOM involvement); boot log growth briefly looked
stalled but was confirmed to be stdio buffering, not a real hang, via
the same connectivity check. No full §10.7 gameplay walkthrough this
pass. The 6 pre-existing untracked `data/{login,user}/c/chen{ba,shi,
wu}.o` files (timestamped 2026-08-05, predating this session) were
left untouched.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 55 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` call `enable_player()` again while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply mhxyqd`: 129 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 2 path reference(s) in 2 file(s) rewritten to the new spelling; 0 skipped, 1 ambiguous. Load check of the 161 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 19 PASS -> 137 PASS, 0 that loaded before fail now, 118 more load.

129 files moved (112 `.C`, 17 `.lpc`); mostly under `d/youxia/OBJ` (32), `d/youxia/NPC` (14), `u/tianlin/wuqi` (13), `d/newjob/longzhu` (11). A rescan with `scripts/lpc_warnings.py mhxyqd` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 281 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 2 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py mhxyqd --fix`：无用局部变量 2259 个、`varargs` 69 处、转义 50 处、`nosave` 函数 17 个改 `protected`、裸 `return` 7 处，共改动 1204 个 `.lpc`。这些文件在 HEAD 与工作树分别加载（新进程）：1178 -> 1178 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 21 条候选都是声明被重建（仍在用的名字保留；有 `#if` 的只有 `d/city/piggy*.lpc`，与被删的名字无关）。手工：`adm/daemons/logind.lpc` `enter_world()` 里的 `if (!silent) { }` 只剩一行被注释掉的进场消息，空的条件判断删去（注释保留）。启动时警告 546 -> 0；新进程启动后登录界面（学生问答、英文名校验）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 28 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 15 个，只在 #if 分支用的声明移进分支 0 个文件；改动 39 个文件，HEAD 与工作树各载入一次无回退（39 objects; HEAD PASS 38, tree PASS 38; regress 0; newly loading 0），这些文件的警告 83 -> 40。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `d/city/silao.lpc`：`if (msg == "ground") msg == "center";` 应为 `=`。
- `d/youxia/npc/shaolong.lpc`：注释掉的 `chat_msg` 里漏了一行字符串没注释，成了独立语句；一并注释。
- `daemon/skill_wiz/archery/xuanyuan-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用，删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

本库与 mhxy（梦幻西游青岛站）几乎逐字节相同。mhxy 今天的收尾（提交 a9cd825122a）改过的 40 个文件里，37 个在本库是 token 级孪生（`lpc_twin_port.py classify`），全部 `adopt`；另 3 个（`long.lpc`、两份 `YI.lpc`）本库没有。之后跑 `toolkit_fix.sh` 重扫：能编译的文件里的警告 62 -> 0（11698 个文件可编译，剩下 2 条警告在本来编译不过的文件里）。搬过来的 12 处删 `inherit F_CLEAN_UP` 都逐个核对过：本库自己的扫描都报了 `clean_up() inherited from both`，或继承的 `SSERVER` 与 mhxy 同一文件、本身已带 `F_CLEAN_UP`（KB 08 §10.13）。

**真问题（与 mhxy 相同）：**
- `d/qujing/sanda/npc/pusa.lpc`、`d/qujing/xihai/npc/aoshun.lpc`：关卡前置条件的括号写错（`if (A == "done") || B != "done"` 再另起一行 `)`），两个文件从来编译不过，三打白骨精、西海两关的 NPC 载不进来；改正后能载入。
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟：CLOTH 与 F_UNIQUE 都有 `init()`，`tear` 动作丢了；叶子里两个都调用。

**其余：** 开封擂台 `ground.h`/`colors.h` 表格 guard（含 `u/redrain` 拷贝）、`feature/alias.lpc` 私有 `last_time` 改名 `last_cmd_time`（三花计数器自己的 `last_time` 一直正常存档，不动）、`yg/yaoguai.lpc` 删掉从不读的 `yaoguai_type`、几个 `die/unconcious/kill_ob` 钩子改 `void`、`dns_master.lpc` 空 if、14 个多余 `inherit F_CLEAN_UP`。

验证：改动文件、开封两处目录、`d/city/npc` 全部对象、`/obj/user`、`/std/char` 共 550 个对象，HEAD 与工作树各用新进程载入：508 -> 510 通过（新增 pusa、aoshun），regress 0；删除声明审计 0 项待看。550 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。11 个文件 20 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemon/class/wudang/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/daemon/skill/evilmove`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。7 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

13 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。4 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`、`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`lingguan-quan`→`lingguang-quan`（`lingguang-quan`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

24 个文件、29 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/u/fly/obj/jinshan`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 23 个（22 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（10 个名字，最多的是 `strike`、`cuff`、`qiankun-danuoyi`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 4 个通过，其余 2 个停在别的错误上（`d/city/obj/npc/zhong`：*No program in object '/d/city/obj/npc/zhong'!；`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/qujing/baoxiang/gongmen` 的 `west`：`jitan1` → `jitan`；`/d/qujing/biqiu/jie4` 的 `north`：`jitan1` → `jitan`；`/d/qujing/chechi/xinshi` 的 `south`：`jitan6` → `jitan`；`/d/qujing/fengxian/shikou` 的 `up`：`jitai1` → `jitai`；`/d/qujing/jinping/fumen` 的 `north`：`jitan1` → `jitan`；`/d/qujing/jisaiguo/centermarket` 的 `north`：`jitan1` → `jitan`；`/d/qujing/nuerguo/towna2` 的 `north`：`jitan1` → `jitan`；`/d/qujing/qinfa/qiankun` 的 `north`：`jitan1` → `jitan`；`/d/qujing/tianzhu/jiedao18` 的 `north`：`jitan1` → `jitan`；`/d/qujing/wudidong/temple-houdian` 的 `south`：`jitan1` → `jitan`；`/d/qujing/wuji/square` 的 `south`：`jitan1` → `jitan`；`/d/qujing/yuhua/fumen` 的 `west`：`jitan1` → `jitan`；`/d/qujing/zhuzi/gulou` 的 `up`：`jitan1` → `jitan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 18 处、18 个文件：`dagonforce`→`dragonforce`（4 处）、`dragon-step`→`dragonstep`（4 处）、`yange_blade`→`yange-blade`（3 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`lahua-shou`→`lanhua-shou`（2 处）、`changqaun`→`changquan`（2 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 2 个：`d/city/obj/npc/zhong`、`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`、`MAILDIR`、`F_DISASTER`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/youxia/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/city/obj/npc/daiyu.lpc` 的 `#include "/u/fly/npc/npc.h"` 改成 `/d/city/obj/npc/npc.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `daemon/class/yaomo/xueshan/cuixin-zhang/cuixin.lpc` 的一句出招描述里夹着一个 NUL 字节（`接着\0:`），`d/lingtai/obj/yuanpinzhu.lpc` 的第一行注释里也有一个（`张天师\0,`）：驱动报 `Illegal embedded NUL byte (0x00) in source`，技能和物件都载入不了。删掉 NUL，其余文字不动。

逐个载入与 HEAD 对比，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：3 个未使用的局部变量，1 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/daemon/class/mojie/liejiuquan/ball.lpc`（1 处）、`/daemon/class/mojie/lingguang-quan/shoot.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/back/disaster.lpc`（2 处）、`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 21 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/cmds/wiz/finger.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/wiz/npc/jing.lpc`（3 处）、`/daemon/class/bonze/lunhui-zhang/puzhao.lpc`（1 处）、`/daemon/class/fighter/bawang-qiang/bailie.lpc`（1 处）、`/daemon/class/mojie/evilfight/dragonshoot.lpc`（3 处）、`/daemon/class/mojie/evilsword/16slash.lpc`（1 处）、`/daemon/class/mojie/segokee/mindshock.lpc`（1 处）、`/www/cgi-bin/board_h.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/adm/callouts.lpc`（1 处）、`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/www/cgi-bin/logind.lpc`、`/www/relative/logind.lpc`。

## `setmission`：`explode(read_file("/adm/daemons/wizmission"))`（2026-10-21，KB 06 §7.326）

巫师命令 `cmds/wiz/setmission` 读 `/adm/daemons/wizmission`（归档里没有，由这条命令自己写），`explode(0)` 抛错，读在写之前所以这个文件永远建不出来。`read_file(...) || ""`，第一次用时走 `write_file()` 新建的分支。mhxy 和 mhxyqd 同一处。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。
