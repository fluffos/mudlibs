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
