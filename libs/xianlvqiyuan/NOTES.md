# xianlvqiyuan — 仙侣情缘 / XLQY (2001 "知秋站" snapshot)

Archive: `仙侣奇缘新版.rar`. Port: 40032. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"仙侣情缘" ("XLQY"), a 2001.2.22-dated build per its own `readme.txt`,
credited to vikee@263.net / www.mudfan.com, "知秋站" ("Zhiqiu Station")
as its home station. `adm/obj/{master,simul_efun}` layout. Despite the
similar Chinese title, this is a genuinely **different, older codebase
snapshot** than `xlqy_new2007` (archive #26) — confirmed via `md5sum`
diff on `chinese.c`/`logind.c`/`master.c` (all different). Similar
naming across archives in this collection has now proven unreliable as
a lineage signal twice (`sjpl2` vs `shujian2008` was the
first case) — always verify via file diff, never assume from the title
alone. ~9,118 raw files, 7,237 after `.c`→`.lpc` rename (511 files hit
lossy conversion — the highest lossy count of any lib processed so far,
though only one turned out to actually break the boot/registration
path).

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 12` → character-count bound `< 1 || > 6`, removed the
   `i%2==0` gate. The `name[i..<0]` slice was already a clean
   single-character-to-end slice, no change needed there.
2. **Proactively added `get_include_path()`** to `master.lpc` (§15o/§8d
   shape) as insurance — not proven strictly necessary, booted clean
   without hitting that specific symptom.
3. **Confirmed NOT needed, via source reading rather than by hitting a
   crash**: no §4 fix (`master.c` gates via `find_object` only); no
   §15n risk (`securityd.c`'s `valid_read` has an allow-by-default-
   unless-known-data-op pattern — `if (func != "read_file" && func !=
   "file_size" && func != "stat" && func != "read_bytes" && func !=
   "tail" && func != "ed_start") return 1;` — which already covers
   `load_object`/`include` implicitly, no explicit allowlist needed);
   no `named.c` daemon exists in this lib.
4. **AGENTS.md §8h recurrence**: `adm/daemons/convertd.lpc`'s Greek-table
   stray-trailing-backslash typo (`"α\",` should be `"α",`) — 45
   occurrences this time. No CRLF present, so the plain sed pattern
   (`s/\\"(,)?$/"\1/`) applied directly; verified via re-grep that the
   count dropped to 0.
5. **New case-sensitivity bug (§15g/§15k pattern), the nastiest one
   found today**: `adm/etc/BANNER` exists uppercase on disk, but
   `include/login.h`'s `BANNER` macro references lowercase
   `/adm/etc/banner`. This was worse than a typical case mismatch:
   `adm/simul_efun/file.lpc`'s `cat(string file)` did
   `write(read_file(file))` completely unguarded — `read_file()` on the
   missing lowercase path returns `0`, and `write(0)` crashes deep in
   `receive()`/`receive_message()` ("Bad argument 1 to receive(),
   Expected: string or buffer Got: 0"), killing the connection via
   `new_conn_handler: logon() ... has failed, the user is disconnected`
   with **literally zero player-visible output** — an empty
   `mudclient.py` transcript that looked exactly like a dead server.
   Fixed two ways: (a) copied `BANNER` to the lowercase name the macro
   expects (kept the original uppercase file too), and (b) hardened
   `cat()` itself to guard against a missing/unreadable file (`if
   (stringp(content)) write(content);`), since this same fragile
   pattern could recur for any other file this codebase references by a
   hardcoded path.
6. **One transient, non-reproduced anomaly, noted but not chased**:
   during one test run, the generic `default error message` config text
   ("你发现事情不大对了，但是又说不上来。") appeared briefly right after
   the banner, with no corresponding `debug.log` entry and no impact on
   the rest of that session or later clean retests — not investigated
   further given it didn't block registration and wasn't reproducible.

## Interactive test result — full registration flow

This lib's registration shape differs from most others processed
recently: **GB/BIG5 encoding preference** → **"are you a student"
age-gate** (any non-"no" answer — including accidentally typing a
username too early — is treated as "yes" and politely ends the session,
not a bug) → **English-name prompt where `new` must be typed literally**
for new-player registration (not "any unused id directly") → English
name → **Chinese name with NO y/n confirmation step in between** → password.

Verified in one continuous connection: `gb` → `no` → `new` → `xlqyc`
(English name) → **`秦风`** (real Chinese name) → accepted, proceeds to
"请设定您的密码：". An earlier attempt in the same investigation
accidentally sent `y` as the Chinese-name input (from a stale
expectation of a confirmation step) and it was correctly **REJECTED**
("对不起，请您用「中文」取名字。") before the retry with `秦风` succeeded
— incidentally reconfirming the fix rejects non-Chinese input correctly,
not just accepting everything.

## lpcc sweep

7,237 files, 7,126 pass / 111 fail (98.5%). Failure tail includes the
usual shape (`Undefined function query`, missing `setup` inherits, some
syntax typos) plus 17 "Invalid UTF8 codepoint in string literal" errors
— likely residual corruption from the unusually high lossy-conversion
count (511 files), not triaged individually per AGENTS.md §6b/§13 since
none of them are on the boot/registration path. Memory stayed healthy
throughout (~15GB free).

## Re-verification pass (2026-07-23)

Extended the interactive test past the password prompt through full
registration (id `xlqyriz`, name `秦河`), gift confirmation, `look`,
`score`, and `quit` — all completed correctly with real content (entered
the game world at 南城客栈/"South City Inn" with real NPCs, `score`
rendered the full character sheet, `quit` showed the real flavor-text
quit sequence). Zero genuine runtime errors in `debug.log`.

Also observed (across several runs) the same `default error message`
noise (`你发现事情不大对了，但是又说不上来。`) documented in more depth in
sibling lib `xlqyzdb`'s NOTES.md — the count varies 0 to
dozens per connection against byte-identical code, never blocks any
tested flow, and is very likely a shared engine-family artifact (same
XLQY lineage, same "d/wiz/init" gift-selection room code) rather than
something specific to this archive's own content. Not re-investigated
here given the sibling lib's more thorough diagnosis already ruled out a
single deterministic cause and pointed to host-load/timing sensitivity.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 7,237 total. First run
  failed outright with a filesystem permission error (`EACCES` writing
  `adm/obj/simul_efun.lpc`) — 9 files under `adm/obj/` and
  `adm/simul_efun/` were mode `0444` (read-only) on disk, apparently an
  artifact of the original archive extraction, not anything deliberate
  (no NOTES.md mention from the earlier pass). `chmod u+w` on those 9
  files, then reformatted cleanly: 5,675 written, 1,556 already-
  idempotent, 6 refused (self-check errors, expected).
  Same formatter bug as the sibling `xlqyzdb` lib (identical
  shared file, same fix): `d/sky/xitian.lpc`'s `if (::valid_leave(me,dir))
  return notify_fail(...)` got mangled into `if (: : valid_leave(me, dir)
  ...)` — hand-restored to the original single-line form. Not on the
  registration path, so didn't surface as a boot failure, but fixed
  proactively for correctness.
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  fatal errors. Full registration flow (GB prompt → `no` age-gate →
  `new` → English id → real Chinese name, no confirm step, per this
  lib's known shape) plus gift-roll, gender, and post-login commands
  re-verified in one continuous connection (id `qinrizc`, real Chinese
  name `秦河岭`): entered the game world at 南城客栈/South City Inn,
  `look`/`score` produced correct real content, `quit` showed the proper
  flavor-text sequence. The previously-documented `default error message`
  noise reproduced again at a variable count, consistent with the
  host-load/timing-sensitive diagnosis already on file — never blocked
  any step.
- **WASM test**: boots clean, reaches the Chinese-name prompt without
  crashing. No IP-gating or other blocking issue observed in the portion
  exercised; did not push to a full playthrough (not required).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched
(same family shape as `xlqyzdb`, patched analogously):

1. **Loopback always allowed** — `adm/daemons/band.lpc`: added
   `is_local_site(site)` helper (127.0.0.1 / leading `127.` /
   empty/non-string / malformed non-dotted-quad = WASM garbage) and
   short-circuited `is_banned()`, `is_strict_banned()`,
   `create_char_banned()` with it. Covers the `is_strict_banned` gate in
   `logind.lpc` `encoding()` (~line 136) and the
   `create_char_banned`/`is_banned` guest-jail check at world entry.
2. **IP-format checks bypassed for loopback** — `adm/daemons/logind.lpc`
   `encoding()` (~line 145): the `!ip_name` destruct and the
   digit-or-dot-only loop over `query_ip_number()` now only run when
   `band->is_local_site()` is false.
3. **Anti-flood** — the `MAX_LOGIN` (=500, effectively inert but patched
   for consistency) per-IP multi-login cap in `get_id()` (~line 314) now
   skips local connections. This older snapshot has NO reconnect throttle
   or per-IP logon_cnt cap in `logon()` (unlike the zheda fork).
4. **Uptime startup gate** — none exists; nothing to bypass.
5. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   via the real flow (`gb` → `no` → `new` → id → Chinese name → password
   x2 → email → gender `m` → gift screen `9`/`y`). Granted `(admin)` via
   `adm/etc/wizlist`. Verified `update /adm/daemons/band` recompiles
   successfully; character finalized in 南城客栈.

Save files (untracked, NOT gitignored — orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login save: password)
- `work/data/user/f/fluffos.o`  (player body save)

Retest: fresh normal registration (id `qinfxy`, 秦风) works end-to-end,
`score` renders, `quit` clean; fluffos login + wizard `update` works.
debug.log: only the pre-existing, CAUGHT preload error
`restore_object(): Illegal mapping format while restoring emote`
(corrupt archive seed `/data/emoted`, §7.7 class, intercepted by the
master's own catch — present before this pass). Test char saves removed.

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** Same fix as
`xlqyzdb`'s (shared `band.lpc` lineage): `is_local_site()`
originally treated an empty/non-string/malformed IP as "local"
(fail-open) — a stopgap for a since-fixed WASM driver bug. Tightened to
fail-closed:

```lpc
int is_local_site(string site) {
  if (!stringp(site)) return 0;
  if (site == "127.0.0.1" || site == "::1") return 1;
  if (strlen(site) >= 4 && site[0..3] == "127.") return 1;
  return 0;
}
```

Every gate that consults this helper (`is_banned()`,
`is_strict_banned()`, `create_char_banned()`, and `logind.lpc`'s
IP-format/anti-flood checks that call it) now treats an unparseable IP
as remote/untrusted. Retested: fresh registration (id `xlqygate`, name
秦岭峰) still completes end-to-end via loopback (`look`/`score`/`quit`
all correct); fluffos login + `update /adm/daemons/band` still succeeds
(`重新编译 /adm/daemons/band.lpc：成功！`). Zero new runtime errors. Test
char save removed after verification.

## 深度功能测试 / Deep functional test (2026-07-24, AGENTS.md §10.7)

Full checklist pass: read `doc/help/newbie` first (confirms start room
南城客栈, sect-join via `apprentice`/`recruit`, `learn <skill> from
<teacher>`, `wimpy` for safe retreat, and the game's own advice to spar
low-level NPCs rather than a dedicated dummy). Native driver, port
40032, one continuous `scripts/mudclient.py` session per phase,
`debug.log` grepped after every `quit`/reconnect. Registered several
real-Chinese-name characters over the session (`吴垚`/wuyao,
`林清羽`/linqing, `林清月`/linqingm, `王承志`/wangchz, `姚心薇`/yaoxinw,
etc.) — final debug.log byte count is **identical** to the pre-session
baseline (`work/log/debug.log`, 31531 bytes, last real content from a
prior pass) through the entire test: registration ×many, sect join,
organic skill learning, a real fight, a shop purchase attempt, three
`quit`s, two unclean (net-dead) disconnects with both prompt and
delayed reconnect, and one clean-quit-then-wait-then-relogin — **zero
new lines**, i.e. zero runtime errors surfaced anywhere in this pass.

### Bug found and fixed: leftover debug `printf("%O", ob)` leaks the login object's internal path to every registering player

`adm/daemons/logind.lpc`'s `get_name()` (the Chinese-name step of new
registration) had `printf("%O\n", ob);` immediately after the
name-validation block and before `ob->set("name", arg)` — no comment,
serves no functional purpose, clearly a leftover debug statement from
development. `%O` on FluffOS renders an object's identity as its file
path plus clone index (`/obj/login#2`), so **every single new
registration** showed a raw internal object reference between the
Chinese-name prompt and the password prompt:

```
您的中文名字：/obj/login#2
请设定您的密码：
```

Confirmed live pre-fix (multiple registrations, e.g. id `shendep`/`沈德鹏`,
id `wuyao`/`吴垚`) and confirmed gone post-fix (id `yaoxinw`/`姚心薇`: the
Chinese-name prompt now falls straight through to the password prompt
with no stray line). This is a real, if minor, programming defect —
unintentional internal-state disclosure to every new player, not a
design choice (there is no explanatory comment, and every sibling
`get_*` step in the same file is otherwise clean of debug output).

Fix (`adm/daemons/logind.lpc:614`, in `get_name()`): deleted the line.

```lpc
// BEFORE
	printf("%O\n", ob);
	ob->set("name", arg);
// AFTER
	ob->set("name", arg);
```

Two structurally-identical dead copies of the same daemon —
`adm/daemons/login.lpc:606` and `adm/daemons/loggind.lpc:564` (note the
double-g typo'd filename) — carry the exact same leftover `printf`, but
neither file is ever loaded (`LOGIN_D` in `include/globals.h` points
only at `/adm/daemons/logind`, and `grep -rn` confirms no code anywhere
references `/adm/daemons/login` or `/adm/daemons/loggind`). Left
untouched per AGENTS.md's dead-code convention — not on any live path.

**This doesn't match any existing AGENTS.md §7 bug class** (closest is
§7.10/§7.26, but those are about `log_error()`'s own ACL/attribution,
not a stray developer `write`/`printf` shipped into a live prompt
sequence). Draft class for AGENTS.md, offered in the session report
rather than committed here per task instructions.

### Root-caused, not fixed: the "default error message" noise is a real (but practically harmless) race between a 0-delay `call_out` and fast/scripted client input

This lib's NOTES.md (and sibling `xlqyzdb`'s) already
documented an unexplained, non-deterministic appearance of the driver's
own `default error message` (`adm/etc/config.xiyou:126`, "你发现事情不
大对了，但是又说不上来。") during registration, with no fix attempted
because no deterministic trigger had been found. This pass pins the
exact mechanism:

`enter_world()` (`adm/daemons/logind.lpc`) moves a brand-new character
into `/d/wiz/init` (the gift-allocation room) synchronously. That
room's `init()` (`d/wiz/init.lpc`) does **not** register its
`input_to("get_input", ...)` synchronously — it schedules
`call_out("get_start0", 0, me)`, and only `get_start0()` (running on
the *next* server tick, not the same call stack) actually calls
`me->command("start")`, which is what ultimately shows the gift menu
and registers the real `input_to`. Between the room-entry text
finishing ("...局面进入请先help whatsnew。") and that call_out actually
firing, the player is briefly a normal command-dispatch target with
**no** matching `add_action` and **no** pending `input_to` — any input
arriving in that window is treated as an unrecognized ordinary command,
producing the driver's generic `default error message` fallback
instead of anything the room intended, and — if a script (not a human)
keeps firing more scripted input immediately afterward — misaligns
every subsequent scripted answer by one, cascading into a real
false-negative test failure (confirmed: a batch of `9`/`y`/`look`/etc.
sent at `--idle 0.4`–`0.6` reliably desyncs the whole gift-selection
exchange, while the identical batch at `--idle 3.0` never reproduces
it, 1-for-1 across repeated trials).

**Not fixed, and not proposed as a new AGENTS.md class**: this requires
input arriving inside a sub-second window immediately after the room's
banner text — no real human types that fast, and a human who *did* see
the stray "default error message" would simply see the real gift menu
appear a moment later and answer it normally (the call_out reliably
fires within well under a second even under this host's heavy
concurrent-agent load in every trial observed). The mechanism is now
understood and written down here so the next tester of this lib or its
XLQY-family siblings doesn't have to re-derive it, but per §10.7's
scope note this reads as a test-harness-timing artifact with no
demonstrated real-player impact, not a programming defect to change
code for.

### Sect join and organic skill learning — both verified live, no bugs

Followed the newbie doc's own path: `kezhan` (南城客栈, start) → `west`
→ `north` reaches 十字街头 (`d/city/center.lpc`), where 张果老
(`d/qujing/wuzhuang/npc/zhangguolao.lpc`, a 五庄观 sect teacher) stands
reachable in exactly 2 moves from spawn. `apprentice zhang` correctly
completed the kowtow flow and joined 五庄观 as its 4th generation
disciple (`score` afterward showed `门派：五庄观` / `师承：五庄观张果老`
correctly). `skills zhang` listed his teachable skills; `learn force
from zhang` correctly charged spirit, printed "你的「内功心法」进步
了！", and `skills` afterward showed `内功心法 (force)` newly at level
1 — the full organic teacher-NPC path works end to end. The NPC's own
`attempt_apprentice()` uses `command("recruit " + ob->query("id"))` to
self-accept — this lib's `command_hook` is correctly **not** `private`
(`feature/command.lpc:35`, with a stale `// private nomask...` comment
above it showing this was already fixed in an earlier pass, just never
written up) — so this NPC-issued `command()` call dispatches correctly
(the §8.3a addendum shape that broke `xuanjianlu`/`shiji` does **not**
recur here; already fixed, confirmed live).

### Safe-sparring mechanism exists in source but is unreachable content (not a bug — documented, not touched)

Two byte-identical files, `d/city/obj/muren.lpc` and
`d/obj/misc/muren.lpc` ("木人"/wooden training dummy), implement exactly
the §10.7-checklist "mirror the attacker's own stats in `accept_fight()`"
safe-sparring pattern this project looks for first. Neither file is
referenced from any room's `set("objects", ...)` anywhere in the
tree (`grep -rln "muren"` outside the two files themselves returns
nothing) — genuinely orphaned dev content, not wired into the live map
in this archive snapshot. Several other NPCs that look like they
*should* be teachers reachable near town (`d/city/npc/shubao.lpc`
秦琼, `d/changan/npc/huang.lpc` 黄飞虎, both with full
`recruit_apprentice`/`attempt_apprentice` bodies) are similarly
orphaned — likely-live-elsewhere duplicates of NPCs that DO appear in
reachable rooms under different paths (e.g. `d/jjf/npc/qinqiong.lpc`).
This is a content gap (§13-shaped), not a programming defect — the
newbie doc itself already documents the actual intended safe-practice
method as fighting low-level, similarly-matched NPCs and using
`wimpy`, not a dedicated dummy, so nothing was changed. Followed that
documented path instead (below).

### Combat, wimpy, and a shop purchase — verified live

`wimpy 70` set, then walked to 鞋帽店 (`d/city/zhuque-s3.lpc` →
`xiemao.lpc`, `west, south, south, east` from spawn) and `kill yitai`
(二姨太, `d/city/npc/eryi.lpc`, `combat_exp` 1000 — the lowest-`combat_exp`
reachable-and-attackable NPC found within a 4-room BFS of spawn).
Combat played out with real damage messages on both sides; the
character's 气血 dropped into the "受伤"/"似乎非常疲惫" bands and the
`wimpy` auto-flee correctly triggered ("看来该找机会逃跑了．．．"),
succeeding on the second attempt and returning the character to 朱雀大街
unharmed further — the self-preservation mechanism the newbie doc
promises works as documented. Did not reach death/respawn this pass
(fled before that point, by design) — **death/reincarnation is
therefore unverified live**, noted explicitly rather than assumed
tested. `list` at 南城客栈 and 鞋帽店 both rendered real shop
inventories; `buy huasheng from xiao er` (a fresh character with 0
cash) correctly failed with "你的钱不够。" — the purchase-rejection path
works; a successful purchase was not exercised since no test character
in this pass had any money and grinding for some was out of scope for
this pass's time budget.

### Disconnect/reconnect — no §7.20/§7.21-class bug; this lineage doesn't use void-parking at all

`obj/user.lpc`'s `net_dead()`/`do_net_dead()`/`user_dump()` chain
**never moves the player into a VOID_OB or any holding room** — the
body simply stays in its current room with `set_heart_beat(0)` and a
`netdead` temp flag while disconnected; `NET_DEAD_TIMEOUT` is 600s
before an unrecovered net-dead session force-quits via the same
`QUIT_CMD` a real quit uses (so no separate stale-location save path to
get wrong). `reconnect()` is a plain "resume heartbeat, clear the
netdead flag" function, and `adm/daemons/logind.lpc`'s login flow
genuinely calls `user->reconnect()` (line 872) on the SAME function —
so, unlike the two flavors cataloged in AGENTS.md §7.20, there is
structurally no location-loss path here to hit. Verified live: (1)
disconnected without `quit` mid-session (character in 朱雀大街),
reconnected within ~2s — "重新连线完毕。", `look` showed the same room,
no data loss; (2) disconnected again, waited 25 real seconds (past the
15s `do_net_dead` confirmation mark, so the driver-level `netdead` flag
was genuinely set this time), reconnected — same clean "重新连线完毕。"
and same room; (3) sent a clean `quit` (real flavor-text quit message),
waited 20 real seconds, logged back in via the normal (non-reconnect)
path — landed correctly at the persisted `startroom` (南城客栈, not
wherever the character last stood before quitting, confirming
`valid_startroom` gating works), `score` showed all prior state
(gender, name, sect membership from a different, earlier test
character) intact. `debug.log` stayed byte-identical to the
pre-session baseline through all three cases.

### Not verified live (explicitly)

- **Death/reincarnation**: not reached — the `wimpy`-triggered flee
  worked before the test character's HP ran out. Code was not
  separately reviewed for correctness beyond what the §7.24-style grep
  (`set("startroom"` in death/reincarnation code) below covers.
- **A completed shop purchase**: only the correctly-rejected
  insufficient-funds path was exercised (see above).
- Grepped `set("startroom"` lib-wide for the §7.24 shape (death/limbo
  code silently overwriting the persistent login-location field). One
  hit under `d/death/`: `d/death/block.lpc` ("鸿蒙之外", the "your spirit
  has dissolved, use suicide/reborn" limbo room) unconditionally does
  `this_player()->set("startroom", "/d/death/block")` in `init()` for
  every non-wizard who enters. Read (not live-reproduced, since death
  was never reached this pass): unlike §7.24's `zzfy` shape, this room
  itself carries `set("valid_startroom", 1)` in its own `create()` —
  the same "may this room be a permanent home" flag `d/city/kezhan.lpc`
  uses for the real start room — so this reads as an intentional
  "you're now stuck here as your only reachable location until you
  `suicide`/`reborn`" limbo design, not an accidental hijack of a
  living player's real chosen home. Neither `cmds/std/suicide.lpc` nor
  `cmds/usr/suicide.lpc` touch `startroom` at all, consistent with
  "reincarnating starts you over," not "silently changes where your
  ORIGINAL character logs in." Flagged as a content/design read, not
  fixed, per §10.7's scope note — genuinely unverified live and stated
  as such.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

一个独立的、更早期的 2001 年 XLQY 代码库。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：是 xlqyzdb 的 XLQY 家族手足档案。管理员登录干净正常：GB/BIG5 选择→未成年人关卡（否）→id+密码→"目前权限：(admin)"。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 32 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复两处问题：

1. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明（`cat()` 早前一轮已加过
   `stringp()` 空值防护，本轮确认仍在，未改动）。
2. **`obj/user.lpc::reconnect()`（AGENTS.md §7.108，第十条独立确认
   的血统）**：`adm/daemons/logind.lpc` 有同款 `exec(old_link,
   user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

`cmds/wiz/update.lpc`（§7.106）与 `master.lpc::log_error()`（§7.10
的 `"arning:"` 大小写无关写法）均已是正确写法，`maximum evaluation
cost` 已经是 `5000000`，均无需改动；本档案无 `adm/daemons/
closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录（GB/BIG5 选择→未成
年人关卡"no"→id+密码）确认 `目前权限：(admin)`，`update
/adm/daemons/logind` 成功验证真实写入权限。踢掉重复登录重连路径现
场验证通过（见上）。`debug.log` 全程干净（743 行，无真实错误）。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/obj/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 210 live occurrences deleted: 209 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 3 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40032.

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

## 深度功能测试第三/四轮 / Round-three/four deep functional test (2026-08-23)

Full re-test against a native `build-debug` driver, closing the two gaps
explicitly left unverified by the 2026-07-24 §10.7 pass (death/
reincarnation and a completed shop purchase), and re-confirming the
§7.100/§7.30 mechanical sweeps didn't regress anything live. One
continuous `tmux_mud.sh` session plus a couple of short raw-socket
probes; `work/log/log` (this lib's debug.log, named `log` not
`debug.log` per its own runtime config) diffed after every phase.
**Result: clean pass, zero new runtime errors anywhere, no code
changes.**

- **Registration**: same documented shape as before (`gb` → `no` →
  `new` → English id `xlqyfor` → Chinese name `秦风` → password ×2 →
  email → gender) completed cleanly. Confirmed the 2026-07-24
  `printf("%O", ob)` leak fix still holds — no stray object-path line
  between the Chinese-name prompt and the password prompt.
- **Sect join & skill learning**: `apprentice zhang` (张果老,
  十字街头, 2 moves from spawn) joined 五庄观 as 4th-generation
  disciple; `learn force from zhang` correctly advanced 内功心法. No
  errors.
- **Combat and death/reincarnation — newly verified live (previously
  documented as untested)**: `wimpy 0` (disabled auto-flee, unlike the
  prior pass's `wimpy 70`), then `kill yitai` (二姨太, 鞋帽店) fought to
  a real death: full HP-band narration down through 半昏迷/头重脚轻,
  "你死了。", broadcast death message, transition to `阴阳界` (judge
  崔珏). `score` there correctly showed 仙衔 as `【鬼魂】` with all
  other state (sect, master, name) intact. After a short wait 崔珏
  auto-revived the character ("命不该死...我这便送你还阳去吧") into
  `荒郊小店`, a real, distinct revival room (not the `d/death/block.lpc`
  "鸿蒙之外" limbo room read about but never reached in the prior pass —
  that room is apparently reached by a different death path, not this
  one). Movement, `score`, and further play all worked normally
  post-revival — no stuck state, no corrupted `startroom`. Zero
  `debug.log` growth across the entire fight-death-revival sequence.
- **A completed shop purchase — newly verified live**: picked up
  "二两银子" (a money item) lying on the ground in `荒郊野外` (just
  south of the revival room), then `list` at the `荒郊小店` innkeeper
  (店小二) and `buy jitui from xiao er` succeeded — inventory
  afterward showed the item plus correctly-deducted change (2两 − 80文
  = 1两20文 remaining, exact). Confirms the purchase-success path
  (previously only the insufficient-funds rejection path had been
  exercised) has no arithmetic or state bug.
- **Clean quit**: real flavor-text quit sequence, connection closed
  cleanly, zero new `debug.log` lines.
- **Investigated, not a bug — tmux input-transmission artifact**: mid-
  registration, sending the 3-character Chinese name `秦岚枫` over the
  `tmux_mud.sh` session was rejected ("对不起，请您用「中文」取名字。")
  even though `is_chinese()`/`check_legal_name()` (read directly) place
  no special restriction on 3-character names and every individual
  character (秦/岚/枫, all U+4E00–U+9FFF) passes the codepoint check.
  Reproduced the *exact same* name over a fresh raw Python socket
  connection immediately afterward and it was accepted cleanly through
  to the password prompt — confirming this was a `tmux_mud.sh`/telnet
  multi-byte-input transmission glitch (the project's own known
  "tmux_mud.sh gotchas" class), not a driver or mudlib defect. No code
  change made.

No bugs found or fixed this pass. Test character (`xlqyfor`/`秦风`)
and the leftover untracked save pair from the interrupted prior attempt
(`xlqyrfa`, never played past the gift screen) were both removed after
verification.

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (1 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 280 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xianlvqiyuan --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（两份 `xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`），共改动 595 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：578 -> 578 通过，无回退；改过的头文件的 227 个包含者 223 -> 223 通过。`cmds/arch/full.lpc` 连写了两个 `else`，HEAD 起就编译不过，未动。

启动时警告 73 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 14 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 7 个，只在 #if 分支用的声明移进分支 0 个文件；改动 19 个文件，HEAD 与工作树各载入一次无回退（19 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 41 -> 20。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 8 处多余继承；搬来 xyj2000（969f36bdd8c）逐 token 相同的 8 个文件（`feature/alias.lpc` 的 `last_cmd_time`、`d/kaifeng/npc/colors.h` 防重、`reporting.lpc`、袈裟 `jiasha.lpc` 补 `cloth::init()` 让撕袈裟的 `tear` 生效等），其余 8 个与 xyj2000 不同的照同样改法手工：`d/kaifeng/ground.h` 表格守卫、`d/city/npc/yg/yaoguai.lpc` 没人读的 `yaoguai_type`、李靖 `die`/`unconcious`、玉兔 `kill_ob` 改 `void`。能编译的文件警告清零；改动的 21 个对象在 HEAD 与工作树各载入一次，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 4 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

1 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

13 个文件、17 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/d/city/npc/obj/sengpao`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 14 个（13 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（8 个名字，最多的是 `cuff`、`strike`、`kunlun-zhang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 3 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 12 处、12 个文件：`dagonforce`→`dragonforce`（4 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`lahua-shou`→`lanhua-shou`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 4 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/houquan.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_wiz/whip/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 武功文件里混进了分页器的文字（2026-10-19，KB 06 §7.263）

`daemon/skill/boxing.lpc` 第一行是 `> more boxing.c  // houquan.c 猴拳`，`daemon/skill/westsword.lpc` 两个数组元素中间有一行 `已 经 显 示 26 % (ENTER 继 续 下 一 页 ， q 离 开 ， b 前 一 页)`：这两个文件是从 `more` 分页器里复制出来的，命令行和分页提示留在了文本里，驱动报 `unexpected L_ORDER`、`Illegal character 0xe5`。前后的代码是完整的（与 chidi、yxjh 的同名文件逐记号对照，除了数值调整之外一致），删掉这两行就能载入。

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`、`F_DISASTER`，用到它们的物件（名单里 3 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/cmds/imm/cast2.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。
