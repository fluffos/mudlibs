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
(`20150716未知lib.zip` → `xyxy2`)** — confirmed via `md5sum`:
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
  `xyxy2`, this lib's sibling) — confirmed the one real
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
   `xyxy2`. Then a GB/BIG5 encoding-selection prompt.
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
  a broken file" variant (same shape as `xyzx3`'s `WQA_ROOM`
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

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Gates patched
(loopback = `127.0.0.1`, a `127.` prefix, or an empty/non-string/malformed
IP — the last covering older WASM `query_ip_number()` garbage):

- `adm/daemons/band.lpc`: added `IS_LOOPBACK_IP()` macro (after line 147)
  and a loopback short-circuit `return 0;` at the top of `is_banned()`
  (~line 154), `create_char_banned()` (~line 167), and `is_strict_banned()`
  (~line 180). Loopback is never treated as banned.
- `adm/daemons/logind.lpc::logon()` (~line 107-125): computed an
  `is_loopback` flag from `query_ip_number(ob)`; the `uptime() < 30`
  startup-grace destruct now only fires for non-loopback, and the per-IP
  anti-flood `logon_cnt > 15` throttle is loopback-exempt. (KEEP note: this
  removes the "wait 30s after boot" requirement for local/WASM play.)
- `adm/daemons/logind.lpc::encoding()` (~line 155-185): wrapped the
  inline ban + IP-format gate (`is_strict_banned`, the `!ip_name` "No IP"
  destruct, and the non-numeric-char destruct loop) so it is skipped
  entirely for loopback/malformed IPs.
- `adm/daemons/logind.lpc::get_id()` (~line 326): the multi-login-per-IP
  cap (`NowLogin >= 50`) is now loopback-exempt.

Admin seed: registered `fluffos` / display 浮浮 through the real flow
(super/recovery pw `Recover@9`, login pw `Mud@2026`), then added
`fluffos (admin)` to `/adm/etc/notices` (this is the `WIZLIST` file,
`#define WIZLIST "/adm/etc/notices"` in `include/login.h`, read by
`securityd.lpc::create()`). Verified after reboot: login as `fluffos`
then `update /adm/daemons/logind` → "重新编译 ...成功"; room display shows
the wizard-only object path. No new errors in `log/debug.log`.

Save files for the orchestrator to add (neither is gitignored — both
`data/user/` and `data/login/` are already tracked, so a normal add
picks them up):
- `libs/xiaoyuxiyou/work/data/user/f/fluffos.o` (character save)
- `libs/xiaoyuxiyou/work/data/login/f/fluffos.o` (login/credential record)

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real hands-on *playthrough* pass on this lib (all prior passes
verified registration + `look`/`score`/`quit` + admin login, or watched
boot output — see the WASM-enablement pass above). Read
`doc/help/newbie/newbie` in full first — it named the starting inn
(翠香楼), the `hp`/`score`/`i` commands, `learn <skill> from <teacher>`,
`help menpai`/`help apprentice` for sect info, and `help hints`/`wimpy`
for combat safety. `doc/help/statue/combat` separately documents this
lib's own safe-sparring convention: `fight` (non-lethal, ends at
unconsciousness/surrender/fleeing the room, no lasting grudge) versus
`kill` (fights to the death). Native driver
(`~/src/fluffos/build-debug/src/driver config.fluffos`), one continuous
session per test character via `scripts/mudclient.py`, per AGENTS.md
§10.7. Found and fixed **two** bugs: one an already-cataloged class
(AGENTS.md §7.21) with a notable additional twist not previously
recorded for that entry, the other a genuinely **new** class surfaced
only by the extended net-dead soak wait §10.7/§10.8 explicitly encourage
attempting when time allows (see below for both).

**Test characters** (state left behind as playthrough evidence, saves
under `work/data/user/` and `work/data/login/`, all with login password
`abcde123` and admin/recovery password `Passw0rd` unless noted):

- id `linqian`, Chinese name 林前 (男/male) — the main playthrough
  character. State: reached `/d/aolai/cuixiang` (翠香楼) normally through
  the gift wizard, explored the 傲来国 (Aolai) starting zone on foot
  (北菀街 → 傲云广场 → 东苑街 → 东方武馆 → 武馆教练场 → 武馆大厅 →
  储藏室), asked 武馆馆主 东方博玉 (`ask dongfang about 学艺`) which set
  the `aolai_dongfang` temp flag, then learned `扑击格斗之技 (unarmed)`
  to level 1 via the organic teacher-NPC path from his son 武馆教头
  东方聪 (`learn unarmed from dongfang cong`), then won a non-lethal
  `fight` against a `武馆弟子` (Wuguan dizi) for 5627 combat_exp/562
  potential, quit cleanly, and relogged in after a real multi-minute
  wall-clock gap with the learned skill still intact (`skills` correctly
  showed `扑击格斗之技 (unarmed) 初学乍练 1/0`). Also exercised (but did
  not complete) the shop path: `list`/`buy jiudai from xiao er` at
  翠香楼 both function correctly and `buy` correctly rejects with "你的
  钱不够" (no crash) for the character's starting 0 gold.
- id `wangshu`, Chinese name 王舒 (女/female) — created specifically to
  reproduce and then re-verify the reconnect-mid-wizard bug below, both
  before and after the fix, across several real disconnect/reconnect
  cycles (including one prompt reconnect after roughly 9.5 real minutes
  net-dead — see the "Second bug found and fixed" section below for the
  full-timeout edge this didn't quite reach, and why). Finished
  registration, reached 翠香楼, and was quit cleanly at the end of this
  pass.
- id `zhaoyun`, Chinese name 赵芸 (女/female) — a throwaway character
  used for the extended net-dead soak-timing attempt described below
  (registered, reached 翠香楼, deliberately net-dead disconnected for the
  full ~615s `NET_DEAD_TIMEOUT` window). **Left deliberately un-repaired
  in `/obj/void`** as direct evidence of the second bug found this pass
  (see below) — do not "fix" her location without also re-reading that
  section.
- id `hema`, Chinese name 何嫚 (女/female) — a throwaway character whose
  first registration attempt's connection closed (client-side timeout)
  before the gift wizard finished, so an unplanned net-dead-mid-wizard
  reconnect happened instead of reaching 翠香楼 as intended — ended up as
  an incidental *third* re-confirmation of the §7.21-class fix above (the
  gift table correctly auto-redisplayed on reconnect) rather than the
  `clean_up()` re-verification it was meant for. Finished registration
  and quit cleanly afterward; not otherwise used.
- id `yelan`, Chinese name 叶岚 (女/female) — the character that actually
  re-verified the `feature/clean_up.lpc` fix (registered with a longer
  client timeout this time to guarantee the wizard fully completed
  before disconnecting — confirmed via a full `score` reaching 翠香楼
  before disconnect). Net-dead disconnected alone in that room; see the
  "Second bug found and fixed" section for the wait duration and outcome.
- ids `qinye`, `qftest`, `qinfeng` and a handful of other `q*` ids are
  leftover from earlier registration-flow verification passes (already
  documented above in this file) and from this pass's own initial
  English-id-validation trial and error (`linfeng`/`linfeng26` were
  rejected — this driver's English id check is letters-only, **no
  digits**, which is stricter than what several `q*`-family ids in this
  file's earlier section imply; worth remembering for future passes on
  this lib).

### Confirmed working end-to-end

- Registration (GBK/BIG5 prompt → id → Chinese name → dual passwords →
  email → gender → gift-point wizard → world) with a real Chinese name,
  reaching the actual starting room `/d/aolai/cuixiang` (翠香楼).
- `look`/`score`/`i`/`skills` all correct, including after a clean
  `quit` + real wall-clock gap + relogin (skill data persisted).
- Exploration and room navigation (`std/room.lpc`-based `exits`/`objects`
  all resolve correctly across 8+ rooms visited; no first-visit "Too
  deep recursion" or eval-cost aborts hit in any of them — §7.17/§7.19/
  §7.22/§7.25's shapes did not reproduce here).
- The organic NPC-teacher skill-learning path
  (`东方博玉` → sets `aolai_dongfang` temp flag → `东方聪`'s
  `recognize_apprentice()` accepts it → `learn unarmed from dongfang
  cong` succeeds, deducts potential, saves).
- Non-lethal `fight` combat against a live NPC (`武馆弟子`), ending in a
  scripted surrender with a combat_exp/potential reward, no death risk —
  this lib's own documented safe-sparring convention (`help
  statue/combat`), used here in place of chasing down a dedicated
  training dummy (see "Observations" below).
- Shop `list`/`buy` command plumbing (insufficient-funds path rejects
  gracefully, no crash).
- Net-dead disconnect + **prompt** reconnect, repeated many times across
  both test characters in both a normal room (translation: never lost
  location — see "Confirmed NOT needed" below) and, once fixed, inside
  the mandatory gift wizard too.
- Clean `quit` + relogin (the full login/`restore()` path, not
  `reconnect()`) with all state intact.
- `debug.log` stayed completely free of `error:`/`Too deep recursion`/
  `eval cost`/`FATAL` lines through the entire session (many logins,
  quits, net-dead cycles, a combat, a skill-learn, two shop attempts) —
  confirmed by grep immediately after every `quit`, per §10.7's own
  `bxsj` lesson, not just at the end.

### Bug found and fixed: reconnecting mid the gift-allocation wizard strands the player — AGENTS.md §7.21's class, with an additional independent twist

**Files:line: `obj/user.lpc`'s `reconnect()` (~line 219, primary fix);
`d/wiz/init.lpc`'s `do_block()` (~line 365) and a new `do_start()`
wrapper (~line 391, secondary/defense-in-depth fix).**

This lib has the exact same structural shape AGENTS.md §7.21 already
catalogs (found on `rzrmud`): every brand-new character is moved into a
mandatory `/d/wiz/init` "limbo" room for gift-point allocation, driven
entirely by `input_to()` prompts, with the room's `init()` (fired once,
on the character's original `move()` in) registering a catch-all
`add_action("do_block", "", 1)` that blocks every verb except
`look`/`help`/`story`/`say`/`restart`/`quit`. `input_to()` registrations
do not survive a net-dead/reconnect cycle on this driver, and
`reconnect()` is a much simpler path than a fresh login — it never calls
`enter_world()`'s `no_gift` routing again, so nothing re-triggers the
lost prompt. **Reproduced live**: registered `wangshu`, deliberately let
the connection drop mid gift-selection (before answering `9`/`y`), then
reconnected — every command produced **zero output** except `look`
(which just re-showed the bare room short-description) and `quit`.

```
> «(pre-fix) reconnect mid /d/wiz/init»
您使用了登陆密码成功登陆！
重新连线完毕。
> 「」
    这里就是傲来国最有名的饭馆，...      ← "look" allowed through by do_block
> «score»                                ← ZERO output
> «start»                                ← ZERO output — see the twist below
```

**The twist, not previously recorded on §7.21's entry**: on `rzrmud`,
the room's own intended manual escape hatch (typing `start` to resume
the wizard) already worked correctly once discovered, and became part of
how that bug was diagnosed. On this lib, that same manual escape hatch
is **independently broken by two separate bugs**, so even a player who
somehow already knew to type `start` would get nothing:
1. `do_block()`'s own verb allow-list did not include `"start"` — the
   very command `init()` wires up via `add_action("do_start", "start")`
   (previously `add_action("get_start1", "start")`, see below) was
   itself caught and blocked by the catch-all sentence registered a
   line earlier in the same function.
2. Even if (1) were fixed, the original binding
   `add_action("get_start1", "start")` was wired directly to
   `int get_start1(object me)` — a function whose real, intentional
   calling convention is "pass the player object" (used correctly from
   `init()`'s own direct call `get_start1(me)`). `add_action`-bound
   handlers are always invoked as `fn(string arg)` by the driver
   (confirmed against `~/src/fluffos/src/packages/core/core.spec`), so
   typing bare `start` called `get_start1("")` — an empty string landed
   in the `object me` parameter, and `if (!me) return 1;` is true for an
   empty string in LPC, so the handler silently no-opped every time,
   with no compile-time warning (LPC's calling convention for
   `add_action` handlers isn't type-checked against the bound function's
   real signature).

Net effect pre-fix: a player who net-deads mid this wizard and
reconnects is not *permanently* stranded (an admin could always force a
fresh login, and `quit` still works so a full logout+relogin — which
correctly re-triggers `enter_world()`'s `no_gift` → fresh `move()` → a
real `init()` firing — recovers cleanly) but is left in a session that
looks completely dead for every ordinary command, with **zero
in-session recovery** available even to a player who guesses the
documented-sounding `start` command.

**Fix** (primary, matches §7.21's established pattern — detect the stuck
state in `reconnect()` and resume directly, no player action required):

```lpc
// obj/user.lpc, BEFORE:
void reconnect() {
  set_heart_beat(1);
  set_temp("netdead", 0);
  remove_netdead_enemy();
  remove_call_out("user_dump");
  remove_call_out("do_net_dead");
  tell_object(this_object(), "重新连线完毕。\n");
}

// AFTER:
void reconnect() {
  object env;
  set_heart_beat(1);
  set_temp("netdead", 0);
  remove_netdead_enemy();
  remove_call_out("user_dump");
  remove_call_out("do_net_dead");
  tell_object(this_object(), "重新连线完毕。\n");

  env = environment(this_object());
  if (env && query("no_gift") && base_name(env) == "/d/wiz/init")
    env->get_start1(this_object());
}
```

Plus the independent secondary fix (worth keeping even with the
`reconnect()` fix above, since it also fixes the manual command for any
future code path that reaches this room without going through
`reconnect()`, and is a genuine bug in its own right regardless of the
wizard-reconnect scenario):

```lpc
// d/wiz/init.lpc, do_block(): added "start" to the allow-list
  if (verb == "look" || verb == "help" || verb == "story"
    || verb == "say" || verb == "restart" || verb == "start")
    return 0;

// d/wiz/init.lpc, init(): rebound "start" to a new wrapper instead of
// get_start1 directly
  add_action("do_start", "start");   // was: add_action("get_start1", "start")

// d/wiz/init.lpc, new function:
int do_start(string arg) {
  object me = this_player();
  if (!userp(me) || wizardp(me)) return 0;
  if (!me->query("no_gift")) return 0;
  get_start1(me);
  return 1;
}
```

**Verified live, end-to-end, twice**:
1. Reproduced the exact broken-reconnect symptom pre-fix with `wangshu`
   (registered through the gift-point display, disconnected without
   answering, reconnected — `score`/`start` both produced zero output,
   only `look`/`quit` worked).
2. Restarted the driver with the fix applied, registered a **fresh**
   character (also `wangshu` — same id, since the first attempt never
   completed registration and had no saved body), disconnected again at
   the identical point, reconnected — this time the full gift-point
   table was **automatically redisplayed** immediately after "重新连线
   完毕。", exactly as if `init()` had just fired; completed the wizard
   (`9`, `y`) and reached 翠香楼 normally, with `look`/`score` both
   correct. No `debug.log` errors from either run.

AGENTS.md is not edited by this pass (draft-only per the task's own
instructions), but the finding is exactly an instance of the existing
§7.21 class — worth folding the "the room's own manual resume command
can be independently broken by an add_action signature mismatch, not
just absent" observation into that entry's text for future passes on
other libs in this family (`xyxy2` shares this same
`小雨西游Ⅱ` engine lineage per this file's own lineage note above and is
worth a targeted grep for the identical `add_action("get_start1",
"start")`-shaped pattern, though not checked live in this pass — out of
scope).

### Confirmed NOT needed (checked by reading source, not just by not hitting a crash)

- **§7.20** (net-dead void-parking without a location-restore path):
  this lib's `net_dead()`/`do_net_dead()` (`obj/user.lpc`) never moves
  the disconnected player at all — no `VOID_OB`, no temp-room parking;
  the object just sits in its real room with `set_heart_beat(0)` until
  reconnect or the `NET_DEAD_TIMEOUT` (600s) force-quit. Confirmed live,
  repeatedly: every prompt reconnect during this pass (both characters,
  many cycles, one after ~9.5 real minutes net-dead) landed back in the
  exact same room with `look` correct, no relocation. `reconnect()`
  really is called by the login flow too (`grep -rn "->reconnect("`
  finds `adm/daemons/logind.lpc`'s real call site) — not the "nothing
  ever calls it" flavor of §7.20 either.
- **§7.19/§7.28** (reentrant or duplicate `enable_commands()`/
  `add_action` registration): `feature/command.lpc`'s `enable_player()`
  already guards its own `add_action("command_hook", "", 1)` call behind
  a `nosave int enabled` flag (`if (!enabled) { enabled = 1;
  enable_commands(); add_action(...); }`), so this lib's own
  architecture is already immune to both the reentrancy and the
  duplicate-sentence shape — nothing to fix.
- **§8.3a** (`private nomask command_hook`): `feature/command.lpc:35`
  already reads `nomask int command_hook(string arg)` with the `private`
  keyword commented out one line above it — already fixed by an earlier
  pass, confirmed by reading the live source.
- **§7.29** (a restored-by-name-match simul_efun with wrong semantics):
  `feature/dbase.lpc`'s `query()`/`set()`/`delete()` implement their own
  genuine recursive `_query`/`_set`/`_delete` helpers for slash-path
  nested properties — not a passthrough to any real efun by name-match —
  confirmed this is the same "architecturally correct" dbase this file's
  earlier section already documented, not the nitan-family bug.
- **§7.30** (mapping accessor returning raw uninitialized `int 0`):
  `feature/skill.lpc`'s `mapping query_skills() { return skills; }` is
  exactly this shape (`skills` is genuinely unset, i.e. raw `0`, for a
  brand-new character), but every one of the 154 real call sites found
  via `grep -rn "query_skills()"` guards with `!skills || !mapp(skills)`
  before using the result — reproduced this live as a brand-new
  character with no skills learned yet hitting several of these call
  sites (`muren.lpc`'s `accept_fight`, `learn.lpc`, `wg_fighter.lpc`)
  with no crash. The one unguarded call site found
  (`u/snowtu/learn.lpc:93`) is an orphaned wizard-personal-sandbox
  duplicate of the real `cmds/std/learn.lpc`, not reachable from the
  live command table (same "u/\* dev-in-progress duplicate" pattern this
  file's lpcc-sweep section already documented for this lib) — left
  alone.

### Observations (not bugs — documented honestly, not fixed, per §10.7's scope note)

- **`d/aolai/npc/jiaotou.lpc`'s `do_answer()`**: the drill-instructor NPC
  presents four conversation options (`比武`/`看热闹`/`捣乱`/`从军` —
  "spar"/"watch"/"cause trouble"/"join the army") but only actually
  implements `看热闹`; every other choice, including the flavorful "join
  the army" option, falls through to a generic "你胡说什么？别来捣乱！"
  rejection. This reads like unfinished/stub content (a menu listing
  options whose questlines were never built) rather than a programming
  defect — there's no missing `return`, dangling `else`, or wrong
  variable reference, just three of four branches never written. Left
  untouched.
- **Shop purchase and sect/menpai joining not completed live** — stated
  explicitly per the task's own allowance for this, not silently
  presented as tested:
  - A completed purchase requires gold, and a brand-new character starts
    at literally 0 (`feature/dbase.lpc`'s `init_money()`). The lib's own
    documented newbie-funding NPC (`小雨`/`vikee.lpc`, "yao gold") lives
    in `/d/city/zhunbei.lpc` ("新手准备室"), reachable only from the
    `长安` (Chang'an) map, which is a **different zone from the starting
    傲来国 (Aolai) zone** — and `d/aolai/northgate.lpc`'s own
    `valid_leave()` explicitly gates the only exit toward the wider
    world/mainland behind `query_level() >= 5` ("武士将手中长剑一横，
    喝道：看你瘦骨伶仃的样子，出城也是送死！"). A brand-new level-1
    character genuinely cannot reach the shop-purchase content within
    the Aolai starting zone — confirmed this structurally by reading
    `d/aolai/aolai.lpc`'s `exits` (`west` → `/d/changan/aolaiws`) sitting
    behind that same gate, not merely assumed. `list`/`buy`'s own code
    path was still exercised and behaves correctly (see above).
  - The formal 门派 (sect) system (`help menpai`'s thirteen listed
    sects: 百花谷/蜀山派/大雪山/东海龙宫/南海普陀山/无底洞/月宫/火云洞/
    方寸山三星洞/阎罗地府/将军府/盘丝洞/五庄观, plus 将军府) all live in
    zones outside Aolai per the same map/level-gate reasoning above.
    `feature/apprentice.lpc`'s `recruit_apprentice()` is the real
    underlying primitive any such sect-entrance NPC would call to
    formally set a `family` mapping (family name/master/generation) —
    read and confirmed sound by inspection, but no live sect-entrance
    NPC was reached to exercise it end-to-end.
- **`d/obj/misc/muren.lpc`** (a "练功木人" training dummy with a
  stat-mirroring `accept_fight()`, the exact "safe sparring" shape
  §10.7's checklist describes) **is never placed in any room** — `grep
  -rl "muren"` across the whole `work/` tree finds only the file itself.
  Orphaned content, not reachable in play; the organic `fight`-vs-`武馆
  弟子` combat above was used instead, per this lib's own documented
  (`help statue/combat`) safe-sparring convention. Left alone per the
  established "don't fabricate/wire up missing content" precedent.
- **`d/wiz/obj/newbie_gift.lpc`** (a fully-implemented, multi-stage
  "新手锦囊" starter pouch — `doc/help/newbie/liwu` explicitly tells
  every new player "进入游戏后，每个人物都会被给予一个「新手锦囊」" —
  tracks food/water/combat milestones via `check_gift1`/`check_gift3`
  `call_out` chains and hands out combat_exp/potential/gold rewards with
  in-character hints at each stage) **is never instantiated anywhere** —
  `grep -rln "newbie_gift"` across the whole tree finds only the file
  itself, sitting in the wizard-workspace `d/wiz/obj/` directory rather
  than a live content path. Confirmed live: a brand-new character's
  inventory is genuinely empty (`目前你身上没有任何东西。`), contradicting
  the help text. Reads as unfinished/never-deployed content (the same
  `d/wiz/` "sandbox, not live" shape this file's lpcc-sweep section
  already documents for `u/snowtu/`) rather than a programming defect —
  no crash, no wrong efun call, just a whole feature that was written but
  never wired into `enter_world()`/`confirm_gift()`. Left undeployed;
  wiring it in would be a content/product decision (when, and under what
  conditions, should it be granted) that this pass shouldn't make
  unilaterally.

### Second bug found and fixed (NEW class): a room's idle `clean_up()` only checks `interactive()`, so it can destruct a room out from under a net-dead player, corrupting their `environment()` and silently skipping the auto-force-quit's own save

Found via exactly the §10.8-style extended net-dead soak wait the task
asks to attempt "if time budget allows" — this is the payoff for doing
it. **Not the driver-fatal crash class §10.8 catalogs** (the process
stayed alive throughout, RSS flat ~45→71MB across the whole ~35-minute
session from ordinary lazy compilation, nothing runaway) — a distinct,
mudlib-level, fully reproducible bug.

**Files:line: `feature/clean_up.lpc`'s `clean_up()` (~line 17-19,
primary fix); `obj/user.lpc`'s `user_dump()` (~line 154, defense-in-depth
fix).**

**Reproduced live**: registered a throwaway character (`zhaoyun`/赵芸),
completed the gift wizard, reached 翠香楼 (alone — no other player was
in that room at the time), then disconnected without `quit`. Waited
**~616 real seconds** (`NET_DEAD_TIMEOUT`=600s from `include/user.h`,
plus the driver's own 15s `net_dead()`→`do_net_dead()` stagger — the
exact deadline the automatic force-quit is supposed to fire at),
monitoring the driver's own stdout throughout (PID confirmed via
`readlink -f /proc/1857465/cwd`, never killed/restarted mid-wait).
`debug.log` then showed a caught runtime error that occurred right at
that boundary:

```
[执行时段错误]: *Bad argument 4 to EFUN message()
Expected: object, array,  Got: int(0).
[程式] /adm/simul_efun/message.lpc(/adm/obj/simul_efun.lpc):178
[物件]: /adm/obj/simul_efun
[回溯]:
user_dump()               /obj/user.lpc  160 行，物件： /obj/user#14 ("赵芸")
tell_room()               /adm/simul_efun/message.lpc(/adm/obj/simul_efun.lpc)  178 行
```

Reconnecting as `zhaoyun` immediately afterward confirmed the full
extent of the damage: **still a reconnect** ("重新连线完毕", not a fresh
login — meaning the force-quit's `QUIT_CMD->main()` call never actually
ran), and `look` showed **`「十八层地狱」`** ("The Eighteen Levels of
Hell" — this is `obj/void.lpc`'s `short`, i.e. `VOID_OB`) instead of
翠香楼, with only an `up` exit leading to `/d/city/center` — a
*different, higher-level-gated zone* than her real starting zone
(Aolai), reachable with zero level check via this path. Score/skills
were otherwise intact — only the location was corrupted, silently, with
nothing ever shown to the player explaining what happened.

**Root cause, two-part**:
1. `feature/clean_up.lpc`'s `clean_up()` — inherited by every room in
   the lib, driven by the driver's own idle-object sweep
   (`time to clean up : 300` in `config.fluffos`) — decides whether a
   room is safe to unload by checking whether any of its `all_inventory()`
   contents are `interactive()`:
   ```lpc
   inv = all_inventory();
   for (i = sizeof(inv) - 1; i >= 0; i--)
     if (interactive(inv[i])) return 1;
   destruct(this_object());
   ```
   `interactive()` is specifically **false for a net-dead player** — the
   defining characteristic of net-dead is that the connection (and thus
   interactivity) is gone, while the player's body object is still alive
   and logically "in" that room, reconnectable. A room containing *only*
   a net-dead player (no other currently-connected player, no living NPC)
   is therefore misjudged as empty and genuinely `destruct()`ed by the
   driver's own idle sweep after `time to clean up` (300s) of no other
   player touching it — a thoroughly ordinary, realistic timing window
   for 翠香楼 specifically during low-traffic hours, and for almost any
   less-trafficked room at any time. (Exactly how the driver's C++-level
   object destruction then relocated the still-referencing net-dead
   player into `/obj/void` rather than leaving a dangling reference
   wasn't traced to a specific line — plausibly a driver-level container-
   destruct safety net — but the mudlib-level defect, and the fix, don't
   depend on pinning that exact mechanism down.)
2. `obj/user.lpc`'s `user_dump()` (the function the net-dead
   `NET_DEAD_TIMEOUT` `call_out` actually invokes) does an **unguarded**
   `tell_room(environment(), ...)` as the FIRST statement of the
   `DUMP_NET_DEAD` case, with no check that `environment()` is a real
   object. Once (1) has corrupted the player's environment, this throws
   — and since nothing in `user_dump()` wraps it in a `catch()`, the
   error aborts the rest of the SAME function, meaning the line right
   after it — `QUIT_CMD->main(this_object(), "", 1)`, the actual
   force-quit/save that is the entire point of the net-dead timeout
   safety net — **never runs**. `DUMP_IDLE` (the analogous idle-timeout
   case a few lines below) has the identical unguarded-environment shape,
   one statement earlier and even more fragile (`environment(this_object())
   ->query("short")` — a method call directly on a value that could be
   `0`, which throws immediately rather than merely passing a bad
   argument).

Net effect: a net-dead player whose room happens to get idle-cleaned-up
before they reconnect is silently teleported into the void with zero
explanation, AND the very safety net that's supposed to force-quit
(and, critically, **save**) truly-abandoned net-dead sessions silently
fails to run for them — they remain unsaved and permanently reconnectable
in `debug.log`-invisible limbo (found alongside, not caused by, §7.20's
different mechanism — this lib's `net_dead()` never deliberately void-
parks anyone, unlike §7.20's affected libs; here the void-parking is an
unintended side effect of an unrelated idle-cleanup timing bug).

**Fix**:
```lpc
// feature/clean_up.lpc, BEFORE:
  inv = all_inventory();
  for (i = sizeof(inv) - 1; i >= 0; i--)
    if (interactive(inv[i])) return 1;

// AFTER: userp() reflects the driver's O_ONCE_INTERACTIVE flag, which
// (confirmed against ~/src/fluffos/src/packages/core/efuns_main.cc's
// f_userp()) stays true for a player body across a net-dead disconnect,
// unlike interactive() -- correctly keeps the room loaded either way.
  inv = all_inventory();
  for (i = sizeof(inv) - 1; i >= 0; i--)
    if (interactive(inv[i]) || userp(inv[i])) return 1;
```
```lpc
// obj/user.lpc, user_dump(): guard both cases so a null/dangling
// environment can never skip the actual QUIT_CMD->main() force-quit
// (full diff in obj/user.lpc; DUMP_NET_DEAD shape shown):
  env = environment(this_object());
  if (objectp(env))
    tell_room(env, query("name") + "断线超过..." + "分钟，自动退出这个世界。\n");
  QUIT_CMD->main(this_object(), "", 1);
```

**Verified live, end-to-end**: driver restarted with both fixes, booted
clean, no new compile warnings/errors on either file (`grep`-confirmed
against `debug.log`); a normal login/`look`/`quit` cycle (`linqian`)
still works identically post-fix. Re-ran the reproduction with a fresh
throwaway character (`yelan`/叶岚) — registered with extra client-side
timeout headroom to guarantee the gift wizard fully completed
(confirmed via a full `score` reaching 翠香楼 before disconnecting),
then net-dead alone in 翠香楼 for **~330 real seconds**, past the 300s
`time to clean up` threshold that triggered the original corruption
(short of the full 615s `NET_DEAD_TIMEOUT`, since the point of this
specific re-run was isolating the `clean_up()` fix). Reconnecting
afterward showed `look` correctly still displaying 翠香楼 and `score`
fully correct — the room was no longer destructed out from under a lone
net-dead player. (An earlier attempt at this same re-verification,
character `hema`/何嫚, accidentally tested the §7.21-class wizard fix a
third time instead, due to her original registration's connection
timing out mid-wizard rather than reaching 翠香楼 as intended — corrected
by registering `yelan` with more headroom and confirming her location
with `score` before disconnecting.) **Not independently re-verified for
the full 615s `user_dump()`/`QUIT_CMD` timing** a second time (would
need another ~10-minute wait beyond what this pass's time budget could
repeat a third time) — the `user_dump()` guard fix is a direct, narrow
`objectp()` check whose correctness is clear by inspection, so this is a
reasonable place to stop, but flagged honestly rather than claimed as
re-observed live.

`zhaoyun` (id `zhaoyun`, Chinese name 赵芸) is deliberately **left
in `/obj/void`** as direct evidence of the pre-fix bug — her save file
(`work/data/user/z/zhaoyun.o`) still reflects the corrupted location.
Not moved/repaired, per this project's "leave representative state as
evidence" convention.

**Lineages likely affected**: `feature/clean_up.lpc` is credited
`// by Annihilator@ES2` in its own header comment — worth checking any
other ES2-lineage-descended lib (AGENTS.md §11's ES II / 东方故事 family)
for the identical `interactive()`-only presence check in its own
`clean_up()`/equivalent, though not checked live on any sibling in this
pass (out of scope). More generally: any lib whose room/container
`clean_up()` uses `interactive()` as its sole "is anyone here" test
rather than `userp()` (or equivalent) is a candidate for this exact
shape, independent of lineage.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一套小雨西游代码库，2013 年站点快照，和 xyxy2/xyxyutf8 同一引擎家族（共享 chinese.c）。状态已从过时的 limited 修正——这份档案自己的 NOTES.md 记录了一次更早一轮会话里已经完成的彻底深度功能测试（§10.7）：对本地回环放行了 uptime()<30 开机闸门，另外发现并修复了两个真实 bug（feature/clean_up.lpc 的房间闲置清理检查只用了 interactive() 而不是 interactive()||userp()，会把网络已断但还没重连的玩家静默清空出一个已经被清理掉的房间；obj/user.lpc 的 user_dump() 强制退出/存档安全网对一个未加保护的 ->query('short') 呼叫在环境为空时崩溃，导致被遗弃的断网会话从来没能被强制存档）。这两处修复都已按 NOTES.md 的记录端到端实测过，包括一次约 330 秒的真实断网复现，确认房间不再会在唯一一个断线玩家还没走的时候就被销毁。管理员账号播种：fluffos (admin) 通过 /adm/etc/notices（WIZLIST）播种，密码 Mud@2026。这份档案的 meta.json/README 只是一直没有跟着更新反映这项已经完成的工作——本轮不需要新的测试，只是重新验证了一遍开机+注册能干净到达 id 提示，确认没有出现回归。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第三轮 / Deep functional test round three (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复四处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `400000`（已知
   风险区间）提升到 `5000000`。
2. **`cmds/arch/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上（`cmds/wiz/update.lpc` 已是正
   确写法）。
3. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
4. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第十一条独立确
   认的血统）**：本档案的 `reconnect()` 已经带有 §7.21 类礼物精灵恢
   复的既有修复（详见文件内注释），但仍然完全没有
   `enable_commands()`——两个类别互不重叠，礼物精灵修复解决的是
   `input_to()` 状态丢失，不解决指令派发本身。`adm/daemons/
   logind.lpc` 有同款 `exec(old_link, user);` 踢掉重复登录写法。按
   §7.108 记录的写法预防性修复，现场用两个真实连线复现"保持第一个
   连线不断开→第二个连线登录→答 y 踢掉旧连线"验证：`score` 修复后
   立即正常显示完整角色档案。

`master.lpc::log_error()` 已经是正确的 `"arning:"` 大小写无关写法，
均无需改动；本档案无 `adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录（GB/BIG5 选择→
"① 进入游戏(Enter)"菜单需送出字元 `1`，纯空白 Enter 不推进→id+密
码）确认 `目前权限：(admin)`，`update /adm/daemons/logind` 成功验证
真实写入权限。踢掉重复登录重连路径现场验证通过（见上）。
`debug.log` 全程干净（669 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/cmds/arch/update.lpc`
- `work/obj/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 205 live occurrences deleted: 204 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as sibling `xyxyutf8`). 4 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40046.
