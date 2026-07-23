# 小雨西游.zip → `xiaoyuxiyou`

Archive: `archives/小雨西游.zip` (34.7MB). Port: **40046**. Status: **done**
(boots clean, full registration flow verified end-to-end including a real
Chinese name reaching the actual game world).

## What this is

Self-identified in `config.xyj` as **`小雨西游`** ("Little Rain Journey to
the West", `name : 小雨西游`), but the live banner text hardcoded in
`adm/daemons/logind.lpc` (and the connection greeting `"Welcome to XYCQ!"`)
says **`小雨西游Ⅱ`** ("Little Rain Journey to the West **II**"), v3.0,
"站点创建时间：2013年12月30日" (site created 2013-12-30). This is the
**same "小雨西游Ⅱ" engine/lineage as archive #3
(`20150716未知lib.zip` → `unknownlib20150716`)** — confirmed via `md5sum`:
`adm/simul_efun/chinese.lpc` is byte-identical between the two archives.
`master.lpc`/`logind.lpc`/`securityd.lpc` differ (different site snapshot/
build), but the shared `chinese.c` and matching 30-second startup grace
period (`adm/daemons/logind.lpc`'s `logon()`: `if(uptime()<30) {...}`)
confirm common ancestry. Treating this archive's own `config.xyj` name
(`小雨西游`, no Ⅱ) as authoritative for the slug/port table per the task's
"pick a real lib name" instruction, and noting the internal Ⅱ-branding
discrepancy here rather than renaming.

Mudlib root in archive: `xymud/` (single top-level folder, config at
`xymud/config.xyj`). `adm/obj/{master,simul_efun}` layout,
`adm/daemons/*` for system daemons, `feature/dbase.lpc` provides real
per-object `set`/`query`/`delete`/`add` (architecturally correct pattern —
**not** the nitan-family bare-simul_efun-dbase bug, confirmed by reading
`adm/simul_efun/wizard.lpc`, which has no generic `set`/`query`/`delete`
at all).

Size: 31735 raw files, 11150 `.lpc` files after conversion (a
mid-sized lib, well below AGENTS.md §6b's mega-lib OOM-risk threshold —
the full `lpcc_check.sh` sweep was run without incident).

## IMPORTANT environment note for future agents

**`/tmp` is shared across concurrent agent sessions on this host.** Early
in this pass, a scratch file this agent wrote to `/tmp/logind_utf8.c` (a
generic, guessable filename) got silently overwritten mid-investigation
by what must have been a different concurrent agent's own scratch write
to the same literal path — several `sed -n` reads against that file later
in the same investigation showed content (a "夕阳再现"/"江湖风云" banner,
`BAN_D->is_welcome`/`vaild_allow_address` calls, a different `get_name`/
`get_resp` flow) that turned out to belong to a **different lib entirely**,
not `xiaoyuxiyou`. This was caught by re-deriving the same file two more
times (a fresh `iconv` re-run against the untouched `raw/` source, and a
direct `Read` of the post-`convert_lib.sh` `work/` copy) and finding both
agreed with each other but **disagreed with the contaminated `/tmp` file**
on everything except the tail (`check_legal_id`/`check_legal_name`, which
happened to be identical enough between the two libs' shared-lineage code
that the contamination wasn't obvious from that section alone). **Lesson:
use unique scratch filenames (`mktemp`, or embed `$$`/a random suffix)
for any multi-step shell-based file investigation in this environment, or
prefer direct `Read`-tool access over intermediate `/tmp` files entirely.**
The analysis and fixes below are all re-verified against the genuine,
uncontaminated `work/` files.

## Fixes applied

1. **AGENTS.md §15h** (the near-universal GBK-byte-range bug), standard
   shape, two sites:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range
     check (`str[0] > 160 && str[0] < 255`, `strlen(str)>=2`) → CJK
     Unicode codepoint range check (`str[0] >= 0x4e00 && str[0] <= 0x9fff`),
     length bound `>=2` (bytes) → `>=1` (character).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
     `strlen(name) < 4 || > 8` (message already said "2-4个中文字符") →
     character-count bound `< 2 || > 4`; dropped the `i%2==0 &&` gate on
     the per-character `is_chinese(name[i..<0])` sliding-window check (was
     landing on alternating GBK lead-byte offsets, now checks every
     character position since UTF-8 indices are already 1 char each).
   - Verified end-to-end: a real Chinese name (2-char `秦风`, then 3-char
     `秦风二`/`秦风三` in follow-up tests) was accepted and the flow
     proceeded through password/email/gender all the way into the game
     world (see Registration flow test below) — not just "reached a
     prompt".
2. **Proactively added `get_include_path()`** to `master.lpc` (AGENTS.md
   §8d/§15o shape) as insurance. Confirmed the underlying need is real:
   the raw tree has many per-file "flavor" headers included via
   `#include <foo.h>` from a file in the SAME directory (e.g.
   `d/dntg/laojun/maze.h`, `d/liandan/baihuagu.h`) — `convert_lib.sh`'s
   automatic local-angle-bracket-to-quote rewrite (1303 conversions this
   run) already handles the bulk of these unconditionally (including the
   preload-time-only timing gotcha `get_include_path()` alone wouldn't
   cover), so this addition is defense-in-depth rather than the primary
   fix; booted clean without hitting a `Cannot #include` error either way.
3. **§15p (DNS/intermud preload exclusion): checked, nothing to
   exclude.** `adm/etc/preload` has no `dns_master`/intermud/network
   daemon entry at all in this archive — confirmed by reading the file
   directly (26 active entries: securityd, band, backupd, virtuald,
   logind, cmd_d, chinesed, convertd, emoted, aliasd, fingerd, channeld,
   monitord, natured, weapond, rankd, combatd, miscd, spelld, obstacled,
   choosed, memoryd, titled, questd, removed — plus 2 already commented
   out: feizeid, msgd). Booted in well under 30s wall-clock, consistent
   with there being no blocking network daemon.

## Confirmed NOT needed (verified by reading source, not by hitting a crash)

- **§4** (`load_object` inside `valid_read`/`valid_write` recursing to a
  stack overflow): `master.lpc`'s `valid_write` gates via `find_object`
  only (`if( ob = find_object(SECURITY_D) ) return ...; return 0;`) — no
  `load_object` call in either apply, so the recursion trap this fix
  guards against cannot occur here.
- **§7** (missing `get_root_uid`/`get_bb_uid`): both already present and
  correct in `master.lpc` (`return ROOT_UID;` / `return BACKBONE_UID;`).
- **§14** (2-arg `valid_override` not handling `#include`d simul_efun
  fragments correctly): `master.lpc`'s `valid_override` already uses
  `sscanf(file, "/adm/simul_efun/%s", file)` to detect the fragment case
  (the same alternate-but-valid solution AGENTS.md documents for
  `unknownlib20150716`, this lib's sibling) — confirmed the one real
  caller (`adm/simul_efun/object.lpc`'s `efun::destruct()`) matches this
  pattern and is allowed.
- **§15l** (`master.lpc create()` destructing `SIMUL_EFUN_OB` — segfaults
  this driver): `create()` here is a single `write("master: loaded
  successfully.\n");`, no destruct call at all.
- **§15n** (custom `securityd.lpc` blocking the driver's own compile-time
  `load_object`/`include` — "Read access denied" mid-connection):
  `securityd.lpc`'s `valid_read` has an allow-by-default-unless-known-
  data-op shape — `if( func != "read_file" && func != "file_size" &&
  func != "stat" && func != "read_bytes" && func != "tail" && func !=
  "ed_start" ) return 1;` — which already implicitly allows
  `load_object`/`recompile_object`/`include` (none of those func values
  are in the restricted list), so the ACL never blocks a lazy compile.
- **§8c** (`this_player()` silently overriding a privileged caller's
  identity in `valid_read`/`valid_write`): `securityd.lpc` uses the
  passed-in `user` parameter directly throughout (`geteuid(user)`,
  `get_status(user)`), never falls back to `this_player()` at all — the
  footgun this fix addresses doesn't exist in this file's shape.
- **§8e** (`tail()` used as if it were a real efun): grepped the whole
  tree (`grep -rn '[^a-zA-Z_]tail(' --include="*.c" .` on `raw/`) — zero
  hits anywhere, not even in dead/unused admin tooling.
- **§8f** (`TYPE * a, b;` comma-declarator array-modifier bug): no bare
  `array name;`/`array name = expr;` declarations found (that specific
  §15f pattern is from a different, "nitan"-family lineage) and no
  Dead-Souls-style multi-declarator `*` scoping issue surfaced in the
  lpcc sweep (see below).
- **§15c** (bare `.c`-suffixed paths in `adm/etc/preload` breaking after
  the rename): `adm/etc/preload`'s entries are already extension-less
  (`/adm/daemons/securityd`, not `.../securityd.c`) — nothing to fix.
- **§15r** (a `check_config.lpc`-shaped driver-version self-check
  `inherit`ed into `master`/`simul_efun` erroring on stale `#ifdef`
  assumptions): grepped for `check_config`/`checkconfig` anywhere in the
  tree — no such file exists in this archive.
- **§8h** (`convertd.lpc`'s Greek-table stray-backslash typo): this lib's
  `adm/daemons/convertd.lpc` has no Greek-alphabet lookup table at all
  (a different, simpler charset-conversion daemon shape, all `GB2BIG`/
  `BIG2GB`/`input`/`output` are plain passthroughs) — nothing to fix.

## Known, pre-existing, non-blocking issue (documented, not fixed)

- **`data/emoted.o` (system-wide emote flavor-text save file) has a
  genuinely corrupted byte in the ORIGINAL archive** — confirmed by
  running `iconv -f GB18030 -t UTF-8` directly against the untouched
  `raw/xymud/data/emoted.o`: `iconv: illegal input sequence at position
  45464`, i.e. this predates any step of this pipeline. This is the exact
  same file/failure class AGENTS.md §1 already documents for this lineage
  ("A handful of save-data `.o` files may have genuinely undecodable
  bytes (seen: `emoted.o`...)"). `convert_lib.sh`'s `-c` fallback dropped
  the bad byte(s) and produced a still-malformed mapping literal, so
  `/adm/daemons/emoted`'s `create()` → `restore()` throws `*restore_object():
  Illegal mapping format while restoring emote.` at every boot. This is
  **caught by `master.lpc`'s own `preload()` catch wrapper**
  (`err = catch(call_other(file, "??"));`), so it is non-fatal to the
  boot and does not affect any other daemon — `emoted` itself just ends
  up with an empty/partial emote-text table (a cosmetic content gap in
  the `emote`-command feature, not a login/registration blocker; `emoted`
  is not on the registration critical path at all). Left as-is per the
  same precedent as the pilot lib.
- The many `编译时段错误：... warning: Unused local variable 'x'` lines
  visible mid-session in the mudclient.py transcript are **harmless
  compiler warnings**, not errors — `master.lpc`'s `log_error()` forwards
  every compile diagnostic (including plain warnings) to the connected
  player with a "编译时段错误" ("compile-time error") prefix whenever
  `this_player(1)` is set, which is how this codebase was originally
  authored (every object's first lazy compile during a live session
  prints its warnings to whoever's connected). Cosmetically noisy but
  does not indicate any functional problem; confirmed none of them
  correspond to an actual compile failure (all say "warning:", none say
  "error:").

## Registration flow (verified against the actual `logind.lpc`, not
inferred from prompt text)

Flow, in order (`logon()` → `encoding()` → `if_young()` → `get_id()` →
[`get_new_id()` if id=="new"] → `confirm_id()` (auto, no separate y/n) →
`get_name()` → `get_super_password()` → `confirm_super_password()` →
`new_password()` → `confirm_password()` → `get_email()` → `get_gender()`
→ `confirm_gift()` (auto) → `enter_world()`):

1. `logon()`: **30-second startup grace period** (`if(uptime()<30)` reject
   with "驱动程序正在启动过程中，请稍候再来。") — same as sibling lib
   `unknownlib20150716`. Then a GB/BIG5 encoding-selection prompt.
2. `encoding()`: needs an answer starting with `g`/`G` or `b`/`B` — sent
   `gb`.
3. `if_young()`: "请您做出选择：① 进入游戏(Enter) ② 立即退出(Exit)" — any
   answer not starting with `2` proceeds (sent `1`).
4. `get_id()`: English id prompt, "新玩家请键入 new 注册". Sent literal
   `new` (not any unused id — matches the established pattern for this
   whole family of libs).
5. `get_new_id()`: asks for a new English id (3-8 lowercase letters, not
   already taken, checked against `NAME_D->valid_id()`'s small banned-
   substring list `fuck/shit/mabi/cao/snowtu`). Sent a fresh unused id
   each test run. Auto-calls `confirm_id("Yes", ob)` on success — **no
   separate y/n confirmation prompt for the id**, unlike some sibling
   libs.
6. `confirm_id()`: prints instructions (取一个符合〖西游记〗中国神话世界
   的中文名字), asks "您的中文名字：".
7. `get_name()`: **the §15h-fixed step.** Runs input through
   `CONVERT_D->input()` first (confirmed a pure passthrough,
   `return str;`, no mangling), then `check_legal_name()`. Sent `秦风`
   (2 chars) in the primary test, `秦风二`/`秦风三` (3 chars) in
   follow-ups — all accepted on the first try with the fix applied
   (before the fix, `strlen()>=4` would reject even a maximal 4-character
   UTF-8 name, since character-count `4` used to require byte-count `8`).
8. `get_super_password()`/`confirm_super_password()`: an **admin/recovery
   password**, separate from the regular login password — must be >6
   chars, contain both upper- and lower-case letters, and not be
   all-letters (needs at least one digit/punctuation too). Sent
   `Passw0rd` twice.
9. `new_password()`/`confirm_password()`: regular login password, >=5
   chars, must differ from the super password. Sent `abcde123` twice.
10. `get_email()`: loose format check (needs `.` and `@`, `sscanf("%s@%s")`
    splits into two non-empty parts). Sent `qft@test.com`.
11. `get_gender()`: `m`/`f`. Sent `m`.
12. `confirm_gift()` (auto-called, sets fixed starting stats, `no_gift=1`)
    → `enter_world()`: moves the new character to `/d/wiz/init`, a
    talent/gift-reroll room (0-3 to reroll one stat, 9 to accept). Sent
    `9` then `y` to accept and enter the actual world.

### Transcript outcome (three separate full runs against one continuously-running driver, ids `qinfeng`/`qftest`/etc. to avoid the "id already taken" retry noise from re-using the same id across runs)

- Run 1 (`qinfeng` / `秦风`, without the final gift-accept step): reached
  `/d/wiz/init`'s gift-selection screen and a live `>` game prompt with
  "你有新的消息没有查看，请用news来查看最新的天界消息。" — confirms the
  Chinese name, both passwords, email, and gender were all accepted with
  zero rejection messages.
- Run 2 (`qftest` / `秦风`, full flow through `9` then `y`): **completed
  registration all the way into the actual starting room**:
  ```
  「翠香楼」
      这里就是傲来国最有名的饭馆，是早年一大唐来的富商所开，出售的都是长安府
  口味的佳肴。传说当时宰相尝后赞不绝口，乃赠翠香二字。在这可看到各处来的游人
  ，也可打听到天下发生的大事。二楼雅座里正大摆宴席，不知是那家有了喜事。
      这里唯一的出口是 west。
    翠香客栈留言板(Board) [ 4 张留言，4 张未读  本板板主：空缺]
    店小二(Xiao er) ㊣
  > 
  ```
  Then `look` re-displayed the room correctly, and `quit` produced a
  clean farewell ("一阵时空穿梭,神秘的西游世界在你视线里渐渐模糊....你
  依依不舍的离开了!") and disconnected gracefully — no crash, no stray
  error.
- A 3rd run reusing the already-taken id `qinfeng` correctly hit "这个
  名字已经被别的玩家使用了．．．" (expected behavior — save data
  persists across driver restarts on disk — not a bug), confirming the
  duplicate-id check also works correctly.

**Conclusion: registration is fully functional, verified past the point
of just reaching a prompt** — a real Chinese name is accepted, and the
character is played all the way into a real, populated starting room.

## lpcc sweep

`scripts/lpcc_check.sh libs/xiaoyuxiyou/config.fluffos libs/xiaoyuxiyou/work`
run against all 11150 `.lpc` files. Host memory stayed healthy throughout
(started ~19.6GB available, stayed above 14GB available at every check,
well clear of the AGENTS.md §6b danger zone; this lib's file count is far
below the "mega-lib" tens-of-thousands threshold).

**New finding: `/d/obj/quest/shuijingqiu.lpc` hangs the `lpcc --batch`
compiler indefinitely** (confirmed: killed after 3.5 CPU-minutes pinned at
100%, zero output growth, RSS flat — not a memory leak, a genuine
compile-time infinite loop, most likely in the lexer's error-recovery path
given the file's content, see below). This is a **pre-existing content
corruption in the original archive**, not introduced by this pipeline —
confirmed by running `iconv -f GB18030 -t UTF-8` directly against the
untouched `raw/xymud/d/obj/quest/shuijingqiu.c`: it decodes to the exact
same truncated/garbled tail (`arg厀)鲦?o~m#烎` followed by raw non-UTF8
bytes where the rest of the function body should be) — the file is
simply truncated/corrupted in the archive itself, not a conversion
artifact. Nothing else in the tree references `shuijingqiu` at all
(`grep -rl shuijingqiu` came up empty besides the file itself), so per
AGENTS.md §12's precedent (orphaned non-compilable content nothing ever
loads), **renamed it to `shuijingqiu.lpc.corrupted-orig`** so it can never
be mistaken for live code or hang a future sweep again. This is why the
final sweep total is 11149, not 11150. First sweep attempt (before this
was found) was silently truncated by the hang — killing it early cut the
run off after only 3919 of 11149 files with a misleadingly-good 33-failure
count; always sanity-check that a sweep's `total=` matches the expected
file count before trusting a pass-rate number.

**Result: total=11149, pass=11039, fail=110 → 99.0% pass rate.**

Triaged the 110 failures by category rather than fixing each individually
(per AGENTS.md §6b):
- **25 files** (`/quest/tianguan/*` — 19 files, `/quest/rzr/shushan*` — 5
  files, `/daemon/skill/tianlei-sword` — 1 file): all fail with **runtime**
  errors (`Bad argument 4 to EFUN message()... Got: int(0)`,
  `F_SKILL: No such skill (hunyuan-zhang)`) — the classic §6b false-positive
  shape: NPC/quest files calling `message()`/skill-lookup against a live
  player/skill-registry context that doesn't exist when `lpcc` compiles
  them as an isolated top-level object with no real room graph or preload
  ordering. **Confirmed as sweep artifacts, not real bugs**: the actual
  interactive boot+registration test (which exercises real NPCs, rooms,
  and skills along the way — e.g. `翠香客栈`'s NPC `店小二` loaded and
  displayed fine) produced zero errors of this shape in `debug.log`.
- **5 files** (`d/obj/amulet/amuletf/amuletfo/amuletm/amuletsheng/amuletstar.lpc`):
  all fail identically — `inherit AMULET;` where `AMULET` is a macro that
  is **never `#define`d anywhere in the archive** (confirmed: no
  `include/*.h` defines it, and no `std/obj/amulet.lpc`-shaped base class
  exists anywhere either). This is the AGENTS.md §8g "missing macro, not
  a broken file" variant (same shape as `xiyangzaixian3`'s `WQA_ROOM`
  case) — 5 nominal failures collapse to ONE real root cause. Per the
  §13 precedent (don't fabricate missing content), left as a documented
  content gap rather than inventing a plausible `AMULET` base class from
  scratch.
- **~39 files under `/u/*`** (wizard personal sandbox directories,
  `u/snowtu/`, `u/amy/`): duplicate/dev-in-progress copies of real system
  daemons (`u/snowtu/channeld.lpc`/`channeld2.lpc` vs the real, and
  already-passing, `adm/daemons/channeld.lpc`), missing intermud/DNS
  headers (`Cannot #include net/dns.h`/`net/macros.h`/`net/daemons.h` —
  the same intermud/DNS theme AGENTS.md §15p already flags as out-of-scope
  network functionality, here as abandoned personal-directory clutter
  rather than a preload entry), and one file with a literal space in its
  name (`u/amy/xiao amy.lpc`) containing what looks like a missing
  semicolon (pre-existing typo in a personal test file). None of these
  are reachable from the boot/registration path.
- **2 dead admin commands**, matching already-cataloged patterns:
  `cmds/wiz/tail.lpc` (§8e, `tail()` was never a real efun on this
  driver — exact same file/finding as documented for lib #1) and
  `cmds/adm/dumpsocket.lpc` (`dump_socket_status` — same "never a real
  efun on this driver" shape as `tail`, just a different missing builtin;
  confirmed via `find ~/src/fluffos/src -iname '*.spec' | xargs grep` —
  no such efun exists). Both non-fatal, unused wizard-only tooling.
- **Remaining ~39 files**: scattered, isolated pre-existing content bugs/
  gaps in individual NPC/book/room files — e.g. `d/npc/xianshi.lpc:78`
  (a dropped `+` before a trailing `target` variable in a
  `message_vision()` string-concatenation call, same shape as AGENTS.md
  §10), `d/obj/club/dragon_mark.lpc` (another missing macro, `CLUB_D`,
  same §8g shape as `AMULET` above but only 1 file this time),
  `d/obj/books-nonskill/book-qujing.lpc` (missing `#include
  /d/qujing/obstacle.h` — a book referencing quest content not present in
  this archive, §13-shaped gap), `d/obj/mieyao.lpc` (local undefined-
  variable typos in one NPC file). None are on the boot/registration
  critical path; not individually fixed, consistent with this batch
  job's "breadth over depth" policy.

## How to run

```
cd libs/xiaoyuxiyou
~/src/fluffos/build-debug/src/driver config.fluffos
# wait >30s after boot before connecting (startup grace period, see above)
python3 ../../scripts/mudclient.py 127.0.0.1 40046 --timeout 30 --idle 1.5 \
  --send "gb" --send "1" --send "new" --send "<unused-english-id>" \
  --send "<chinese-name>" --send "<super-password>" --send "<super-password>" \
  --send "<password>" --send "<password>" --send "<id>@test.com" --send "m" \
  --send "9" --send "y" --send "look" --send "quit"
```

## Minor cosmetic boot warnings (harmless, not fixed)

Boot log shows `maximum local variables: invalid new value, resetting to
default.` and `living hash table size: invalid new value, resetting to
default.` — the original `config.xyj`'s values (60 and 200, carried
into `config.fluffos`) are below this driver's hardcoded minimums for
those two flags (`INT_FLAGS` table in `src/base/internal/rc.cc`: both
flags have `minValue == defaultValue`, i.e. 64 and 256 respectively — any
lower value is rejected outright). Purely cosmetic: the driver silently
substitutes its own default and boots/runs identically either way.

## Environment gotcha: background driver processes started with plain
`&`/`disown`/`setsid` died unexpectedly after ~1-2 minutes

Twice during this pass, a driver process started via
`nohup ... & disown` (once) and `setsid nohup ... & disown` (once) from a
normal (non-`run_in_background`) Bash tool call died silently sometime
after the call returned (no crash trace in `debug.log`/stdout, no OOM
signature in `dmesg`/`free -h`) — once mid-idle, once mid-interactive-test.
Switching to the Bash tool's own `run_in_background: true` parameter (the
tool-native way to keep a long-running process alive across calls) fixed
this — that driver instance stayed up through the entire remaining test
session with zero issues. **Recommendation for future agents: always
launch the boot-test driver via `run_in_background: true`, not manual
shell backgrounding tricks**, in this harness.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (11149 files): 9931
  reformatted, 1188 already-clean/unchanged, 30 self-checked errors
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only cosmetic config-min-value warnings already
  documented above), full registration flow re-verified end-to-end with
  a fresh real Chinese name ("秦风十七") — encoding select → if_young
  gate → `new` → English id → Chinese name → admin/super password →
  login password → email → gender → default-gift entry, reaching the
  actual game world (`翠香楼`), `look`/`score`/`quit` all producing
  correct, correctly-encoded Chinese output; `log/debug.log` clean of
  real errors. `setsid nohup ... & disown` (this pass's launch method,
  per top-level AGENTS.md) stayed up fine for the whole session this
  time — did not reproduce the earlier random-death issue noted above.
  Reformat + new driver build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly (same preload sequence, no fatal errors). Could **not** be
  driven through registration, but for a lib-specific reason distinct
  from both the mudlib and the known `query_ip_number()` gap: this lib's
  `logind.lpc::logon()` has its own `uptime() < 30` startup-grace gate
  (`destruct(ob)` + "驱动程序正在启动过程中，请稍候再来" if a connection
  arrives in the first 30 real seconds after boot — see "How to run"
  above, which already documents waiting 30s+ before connecting
  natively). `scripts/wasm_client.js` calls `fluffos_connect()`
  synchronously right after `fluffos_boot()` with no pre-connect delay
  knob, so every WASM attempt hits this gate immediately and the
  connection is destructed before a single `--send` is processed — no
  amount of `--idle`/`--timeout` tuning helps since the object is
  already gone. This is a **harness-timing limitation** (the harness has
  no way to defer its one `fluffos_connect()` call), not a mudlib bug and
  not the query_ip_number issue — noted here rather than worked around,
  since patching either the mudlib's startup gate or the shared test
  harness is out of scope for this pass.
