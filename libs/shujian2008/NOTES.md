# shujian2008 — 「书剑天下」2008 (ShuJian MUD, 2008 build)

Archive: `书剑2008.rar`. Port: 40029. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese name and
correct rejection of a banned novel-character name).

## What this is

"「书剑天下」" ("ShuJian" / "Book and Sword, the World"), credited to
"ShuJian MUD Wizard Group", hosted at www.cqmud.com ("重庆电信" / Chongqing
Telecom). Same "Century-family" `adm/single/{master,simul_efun}` layout
as `shiji`/`zhonghua2` (archives #32/#34), but with a much more
elaborate, genuinely custom `securityd.lpc` ACL system (directory-based
`trusted_read`/`exclude_read` tables keyed by wizard-status categories)
rather than the simpler `find_object`-only pattern seen in those two —
this turned out to matter a great deal (see below). ~11,714 raw files,
9,936 after `.c`→`.lpc` rename.

## Fixes applied

### Standard §15h Chinese-detection fixes

1. `adm/simul_efun/chinese.lpc`'s `is_chinese()` — a two-specific-byte
   variant (`str[0]` lead-byte range 176-247, `str[1]` trail-byte range
   161-254, plus a reserved-codepoint exclusion for `str[0]==215 &&
   str[1]>249`) — rewritten to the standard single-character CJK
   codepoint check.
2. `adm/daemons/logind.lpc`'s `check_legal_name(object ob, string name)`
   — bound `i<4||i>8||i%2` (byte count, plus an odd-BYTE-count rejection
   that's meaningless for character counts) → `i<2||i>4`; removed the
   `i%2==0` even-byte-offset gate so every character position is
   checked; `name[i..<1]` (a multi-byte suffix, since the old `is_chinese`
   only read the first 2 bytes of whatever it was given) → `name[i..i]`
   (a clean single-character slice, matching the simplified
   single-character `is_chinese`).
3. `adm/daemons/named.lpc`'s `valid_name()` — a banned-substring double
   loop stepping over GBK byte-pair boundaries (`i/j += 2`, `j` starting
   at `i+1`) building substrings of whole 2-byte characters — rewritten
   to step per-character (`i++`/`j` starting at `i`, `j++`).

### Two new architectural bug classes (AGENTS.md §15n, §15o)

These aren't Chinese-detection bugs at all — they're driver-vs-custom-ACL
interaction bugs, and took by far the most diagnostic effort of any lib
this session. **See AGENTS.md §15n/§15o for the full writeup** (this is
the short version):

- **§15n**: this lib's real `securityd.lpc` denies `(player)`-status
  callers from reading `/adm` or `/cmds` at all — correct for actual
  data reads, but the driver ALSO routes compile-time source loading
  (`func=="load_object"`/`"recompile_object"`) and `#include` resolution
  (`func=="include"`) through this exact same `valid_read` gate, and a
  fresh pre-login connection defaults to `(player)` status. Every
  never-preloaded `/adm`/`/cmds` object's first lazy compile — triggered
  incidentally by the registration flow (`BAN_D`, then `UPTIME_CMD`,
  `mudlist`, `sited`, one at a time as each was reached) — crashed with
  "Read access denied" instead of just compiling. **Fixed by adding
  `case "load_object": case "recompile_object": case "include": return
  1;`** to `securityd.lpc`'s `valid_read` switch — compiling/including
  code is routine operation, never a sensitive data read, and should
  never be gated by the caller's status. Also preloaded `/adm/daemons/band`
  as a belt-and-suspenders first attempt (harmless to keep, though the
  securityd fix alone would have covered it).
- **§15o**: `master.lpc` never defined `get_include_path()` at all. Per
  the driver source, a compile with no VM context (preload, bare `lpcc
  --batch`) just uses the config's raw include path; a compile WITH a VM
  context (live, mid-connection, exactly this lib's registration flow)
  calls `master->get_include_path()` instead, and with no apply defined,
  no path gets resolved. Symptom looked identical to §15n at first (a
  compile error mid-registration) but was actually the NEXT layer once
  §15n let the underlying read through — "Cannot #include globals.h",
  a compile error, not "Read access denied", a runtime error. Fixed with
  the same `get_include_path()` shape already used in `es1_win`/`esI`
  (AGENTS.md §8d), returning `({ file's own directory, ":DEFAULT:" })`.
  **Caveat honestly noted**: once §15n's `"include"` case was in place,
  this specific symptom was gone before I got to retest §15o's fix in
  isolation — so it's not proven independently necessary here, just
  applied on the same reasoning that made it necessary in the ES-family
  libs. Future libs: apply §15n first, retest, and only add §15o if
  `Cannot #include <file>` errors persist for mid-connection compiles
  specifically.

### Minor defensive fixes (now likely redundant given the above, harmless to keep)

- `logind.lpc`'s `gb_big5()`: `UPTIME_CMD->main(1)` and `"/cmds/usr/
  mudlist"->main(ob, "all")` wrapped in `catch()`.
- `band.lpc`'s `load_sites()`: the `read_file(BANNED_SITES)` call
  wrapped in `catch()` (the target file doesn't even exist in this
  archive; harmless either way).

## Re-verification pass (2026-07-23) — two new bugs found and fixed

The original pass above never tested a post-login command — exactly the
gap AGENTS.md §15ae's standing policy (adopted after this lib's original
pass) warns about. Re-testing the full flow through `look`/`score`/`quit`
found this lib was actually **fully broken post-registration** (every
command after landing in the game world silently produced `什么？` — "What?"
— with zero output), caused by TWO independent, compounding bugs:

1. **AGENTS.md §15ae**: `feature/command.lpc` declared its central dispatch
   function `private nomask int command_hook(string arg)`, inherited into
   the player body and registered via `add_action("command_hook", "", 1)`.
   This driver treats `private` as hidden from `add_action`'s own external
   dispatch, not just same-file callers — silently breaking every
   post-login command with zero visible error. Fixed by dropping `private`
   (kept `nomask`).
2. **AGENTS.md §15ar**: `adm/daemons/commandd.lpc`'s `rehash()` filters
   `get_dir()`'s listing with `sscanf(cmds[i]+"$", "%s.c$", cmds[i])` to
   strip the old `.c` extension — after this project's blanket
   `.c`→`.lpc` rename, every real command file is `.lpc`, so this pattern
   matched **zero** files, forever, leaving `commandd`'s command-search
   table permanently empty and `find_command()` always failing. This is a
   live runtime `sscanf`, invisible to both the quoted-`".c"`-reference
   fixer and the bare-preload-data-file fixer, and is a SEPARATE root
   cause from #1 above that independently produces the exact same "every
   command does nothing" symptom (per AGENTS.md §15ar's own precedent that
   more than one cause can compound in the same lib). Fixed by changing
   the pattern to `"%s.lpc$"`.

Both bugs had to be fixed before any post-login command worked at all —
fixing only one would still have left the lib fully broken. Re-verified
with a full fresh registration (id `sjqfdd`, real Chinese name `秦风十`,
male) through to `look` (re-displayed the actual starting room, 武馆前院/
Martial-arts-hall Front Courtyard), `score` (real character card with
correct name/stats), and `quit` (clean exit) — all producing genuine,
correct output. `debug.log` for the session has zero `denied`/`cannot`/
`undefined function`/`bad argument`/`error in error handler` lines.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection,
including an incidental but valuable extra check:

1. `sjbteste` → passes `check_legal_id`, reaches confirmation.
2. `y` → password prompt.
3. `Pass1234` (twice, matching, meets the digit+uppercase requirement) →
   accepted, reaches the Chinese-name prompt.
4. **`萧峰`** → correctly **REJECTED** ("对不起，这种名字会造成其他人的
   困扰" — this name would cause trouble for others) — 萧峰 is a real
   Jin Yong novel character (*Demi-Gods and Semi-Devils*), and this game
   explicitly warns against novel character names. This is CORRECT
   behavior, not a bug — and it incidentally proves the fixed
   `valid_name()`/banned-name check is ALSO working correctly
   post-UTF8-fix (rejecting a real match), not just that legitimate
   names pass.
5. **`秦风`** (an invented, non-novel name) → accepted, proceeds into
   character-attribute selection (根骨/膂力/悟性/身法 stat prompt) — the
   actual proof the full fix chain works end-to-end for a real name.

## lpcc sweep

9,936 files, 9,860 pass / 76 fail (99.2%). Failure tail is the usual
shape (a `is_killing` type-mismatch pattern, a handful of missing
globals/functions, some genuine syntax typos) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~16GB free
consistently, no pressure).

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 9,936 `.lpc` files in `work/`:
   `{"total":9936,"written":9680,"wouldChange":0,"unchanged":102,
   "errors":154}`. Verified post-format that all four load-bearing fixes
   from this lib's own §15n/§15o/§15ae/§15ar diagnostic work survived
   intact: `feature/command.lpc`'s `command_hook` is still plain
   `nomask` (no `private`), `adm/daemons/commandd.lpc`'s `rehash()`
   still matches `"%s.lpc$"`, `adm/daemons/securityd.lpc`'s `valid_read`
   still allow-lists `load_object`/`recompile_object`/`include`, and
   `adm/single/master.lpc` still defines `get_include_path()`.
   **Found and fixed a genuine formatter bug** (same class discovered
   while working `tianxia` this same pass — see its NOTES.md for the
   full writeup): the formatter mis-tokenizes a `::fn(...)` call with no
   space between the preceding `(` and the `::`, mistaking it for a
   `(: ... :)` closure literal. Hit in **both** copies of this lib's
   leitai-arena NPC file — `cmds/leitai/npc_leitai.lpc` and
   `d/tanggu/npc/npc_leitai.lpc` — where `if(::move(dest, silently))`
   got rewritten to the syntactically broken `if (: : move(dest,
   silently)\n)`. Neither file is on the registration/boot path (both
   are leitai/arena NPC objects, only compiled on-demand), so this
   didn't surface during the interactive test below — caught instead by
   comparing `lpcc_check.sh`'s pass count before/after formatting.
   **Fixed by hand-restoring** `if (::move(dest, silently)) { ... }` in
   both files; re-verified via a full `lpcc_check.sh` sweep afterward:
   9,861/9,936 pass (76 fail), one MORE pass than the pre-format
   baseline below (9,860), confirming the fix, with neither file
   appearing in the failure log.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal errors in `log/debug.log`, only ordinary
   compile warnings). Full registration verified end-to-end via
   `mudclient.py`: id `sjrfmtf` → confirm → password ×2 → real Chinese
   name **`秦风十六`** (accepted, not a banned novel name) → attribute
   roll (`0`/random) → accept → email `test01@abcd.com` → gender `m` →
   entered the game world at 武馆前院, `look` displayed the room, `score`
   showed a correctly-populated character card (name/stats matching
   registration), `quit` produced "正在退出游戏……". `debug.log` for the
   session: zero `error in error handler`/`denied`/`undefined
   function`/`bad argument` lines. Confirms the reformatted source is
   still fully sound against the rebuilt driver; no new fixes needed.
3. **WASM test**: boots cleanly — `dns_master.lpc`'s preload failure (no
   sockets package under wasm: `Undefined function socket_create`/
   `socket_bind`/`socket_close`) is caught by `master.lpc`'s own
   `preload()` `CATCH()` wrapper this time (unlike `shiji`'s uncaught
   runtime call — this lib's preload path handles it gracefully, logging
   "执行时段错误" but continuing to `Initializations complete.`).
   **Login itself is blocked by the documented `query_ip_number()`
   WASM limitation**: `adm/daemons/logind.lpc`'s `get_id()` calls
   `adm/daemons/sited.lpc`'s `is_valid(arg, ip)`, which does
   `sscanf(ip, "%d.%d.%*d.%*d", ip1, ip2) != 4` — exactly the
   documented pattern (same shape as `bxsj`'s `sited.lpc`). Since
   `query_ip_number()` doesn't return a well-formed dotted-quad under
   this wasm build, the sscanf never matches 4 fields, `is_valid()`
   always returns 0, and every login id is rejected with "对不起，这个
   英文名字不能从当前地址登录。" regardless of validity. **This is the
   known, driver-side, non-mudlib WASM limitation called out in the task
   brief — not patched.** Assessment: boots cleanly under wasm; login
   cannot complete due to the known IP-format limitation, not a mudlib
   bug (native boot+login both verified working above, same session).

## WASM-enablement pass (2026-07-23)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback-allow** (empty/non-string/`127.*` IP treated as loopback in
   all cases):
   - `adm/daemons/logind.lpc` `logon()` — per-IP connection-flood cap
     (`login_cnt > 3` over login clones) now skipped for loopback.
   - `adm/daemons/logind.lpc` `get_passwd()` — per-IP wrong-password
     lockout counters (`step1/`/`step2/` temp mappings, 10-min ban) now
     skipped for loopback; non-loopback behavior unchanged.
   - `adm/daemons/sited.lpc` `is_valid()` — loopback short-circuits to
     valid BEFORE the `sscanf("%d.%d.%*d.%*d")` format check (which
     rejected every WASM login — this was the documented WASM blocker)
     and before the wizard-address-restriction check (which would
     otherwise refuse ANY wizard id not present in its `valid_login`
     whitelist, including the new `fluffos` admin).
   - `adm/daemons/sited.lpc` `is_multi()` — loopback exempt from the
     "your address just had someone log in, wait" 10-second throttle and
     all per-IP multi-login caps.
   - `adm/daemons/band.lpc` `is_banned()` — loopback/malformed sites
     never banned.
2. **Uptime gate**: none present.
3. **Admin account seeded**: `fluffos` / `Mud@2026` / 浮浮, granted
   `(admin)` (top rank) via `/adm/etc/wizlist` (was empty; securityd
   reads it at load). Save files: `work/data/login/f/fluffos.o`,
   `work/data/user/f/fluffos.o` (data/ is not gitignored — plain adds).
   Verified live: password login lands in the wizard workroom, `update
   /cmds/imm/update.lpc` recompiles successfully.
4. Retest: fresh registration (sjtestqf/秦风, deleted after test)
   end-to-end into 武馆前院 with look/score/quit OK; debug.log free of
   runtime errors.

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## 深度功能测试 / Deep functional test (2026-07-24)

Round-two deep functional test per AGENTS.md §10.7. Read `doc/help/
newbie` and `doc/help/help_wuguan`/`map_wuguan` first, then played one
continuous native-driver session as a fresh Chinese-named character
through registration → exploration → safe sparring → organic skill
learning → sect join → clean quit → prompt net-dead reconnect → a real
~16-minute full `NET_DEAD_TIMEOUT` wait (done twice) → post-quit
state-persistence verification. This lib's "adm-single" family is
confirmed distinct from the "书剑"/`bxsj` lineage already deep-tested
earlier this round, despite the similar title (AGENTS.md §11).

**Bugs found and fixed** (both already-cataloged AGENTS.md classes,
first occurrence on this specific lib — no new class needed):

1. **AGENTS.md §7.16** — `cmds/usr/top.lpc`: five `add_rank_*()`
   functions (`add_rank_beauty`, `add_rank_pk`, `add_rank_rich`,
   `add_rank_worker`, `add_rank`) ran an unbounded per-hour decay loop
   against the shipped `/log/rank.o`'s genuine ~2008 timestamps. Since
   `cmds/usr/quit.lpc:218` calls `TOP_CMD->add_rank(me)` unconditionally
   on every `quit`, this crashed the very first `quit` attempted
   (`Too long evaluation. Execution aborted.`), silently dropping an
   in-flight `startroom` update since the crash landed before
   `do_quit()`'s own `save()`. Fixed with the established §7.16
   pattern: cap each loop at 240 iterations, then unconditionally
   resync the timestamp to `t` afterward.
2. **AGENTS.md §7.12** — `adm/simul_efun/message.lpc`'s `tell_room()`
   wrapper forwarded a bare `int 0` as `message()`'s 4th argument when
   called with only 2 args. Reached from `clone/user/user.lpc`'s
   `user_dump()` on the `NET_DEAD_TIMEOUT` (900s) force-quit path —
   reproduced live via a real 16-minute net-dead wait: the crash
   aborted `user_dump()` before it ever reached `"/cmds/usr/quit"->
   main(me)`, silently disabling the entire net-dead force-quit safety
   net (confirmed live: a reconnect >20 minutes later found the old
   character object still alive/un-destructed and just relinked to it
   via "重新连线完毕。" instead of a fresh login). Fixed with the
   standard `exclude || ({})` pattern from §7.12, then re-verified with
   a second full 16-minute wait producing a clean force-quit and
   fresh-login banner on reconnect.

**Test character left behind:** id `qinshiyu`, Chinese name 秦时雨,
password `Sj2026Test` — 武当派 (Wudang) disciple, 17 skills, standing
at 西练武场. Saves: `work/data/{login,user}/q/qinshiyu.o`.

**Verified working:** registration with a real Chinese name; multi-room
exploration; safe sparring vs. the training dummy; organic sect join;
organic skill learning (17 skills total); clean `quit` + immediate
`debug.log` grep; prompt net-dead reconnect; two full real 16-minute
`NET_DEAD_TIMEOUT` waits (the second post-fix, confirming the fix);
state persistence (location/sect/skills) across all of the above.

**Explicitly not verified live** (documented, not silently skipped):
a shop purchase (no shop in the starting zone; real commerce is in a
distant Yangzhou city zone not mapped this pass) and a full
combat-to-death cycle (core combat mechanics already exercised via the
safe-sparring dummy fight; the two real 16-minute net-dead waits
consumed most of the remaining time budget).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

书剑天下2008 基础版。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：是 shiji（021）/sjtx2 的 Century 家族手足档案。管理员登录（fluffos/Mud@2026，这个家族特有的"先问 BIG5 字体"式书剑流程）干净正常，"您目前的权限是：(admin)"。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`cmds/app/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上（`cmds/imm/update.lpc` 已是正
   确写法）。
2. **`adm/simul_efun/file.lpc`**：`cat()` 补上 `read_file() || ""`
   空值防护（`log_file()` 委托给 `LOG_D`，不是本档案直接
   `write_file()`，未处理；`assure_file()` 本身已有正确的存在性检
   查）。
3. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，第三条独
   立确认的血统——shiji（同 Century 手足家族）也命中过同一处）**：
   `logind.lpc` 同样有 `exec(old_link, user);` 踢掉重复登录的写法，
   `reconnect()` 缺少 `enable_commands()`。按 §7.108 记录的写法预防
   性修复，现场用两个真实连线复现"保持第一个连线不断开→第二个连线
   登录→答 Y 踢掉旧连线"验证：`score` 修复后立即正常显示完整角色档
   案。

`master.lpc::log_error()` 的广播行本身是注释掉的（无泄漏风险），
`maximum evaluation cost` 已经是 `5000000`，均无需改动；本档案无
`adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录确认
`您目前的权限是：(admin)`，`update /adm/daemons/logind` 成功验证真实
写入权限。踢掉重复登录重连路径现场验证通过（见上）。`debug.log`
全程干净（377 行，无真实错误）。

（一处方法论记录，非 bug：第一次登录尝试因为工具调用间隔较长，触发
了本档案自己的"您花在连线进入手续的时间太久了"登录超时保护，属预
期行为，用更短间隔重新连线后正常完成。）

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/cmds/app/update.lpc`
- `work/clone/user/user.lpc`

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Same lineage/shape as
sibling libs `bxsj`/`bxsj1`: 24 live `replace_program(ROOM);`
occurrences deleted (`d/wanshou/*.lpc`, `data/group/groom/*.lpc`,
`d/cangzhou/dangpu.lpc`). No roommaker.lpc factory-bug variant.
Verified via a clean native driver boot (zero new `debug.log` errors,
port listening, killed by exact PID after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: the touched header here (`death2.h`) turned out to be dead/unreferenced code in this lib -- the live NPCs (`yanluo.lpc`/`mengpo.lpc`/`pusa.lpc`) actually `#include` a sibling `death.h`, which was already guarded from an earlier fix. This edit is a harmless no-op; no live vulnerability existed in this lib for this file.

## Round-four deep functional test (2026-08-20) — the two flagged gaps closed

Targeted resolution of the two items explicitly deferred in the 2026-07-24
深度功能测试 above ("Explicitly not verified live"). Booted natively
(`/home/sunyc/src/fluffos/build-debug/src/driver`, PID confirmed against
`work` before kill), watched `log/debug.log` live via a persistent Python
telnet bridge (validated each response before sending the next command,
no blind-fired script).

**1. Shop purchase — resolved, verified clean.** The only literal `SHOP`-
class room in the whole archive (`clone/shop/yangzhou_shop.lpc`, the
Yangzhou room the prior round's note speculated about) turned out to be
dead content by design: `owner: "VOID_SHOP"`, `shop_type: 0`, and its own
`long` text says the shelves have sat empty for years, no one runs it —
not a bug, just an unfinished/abandoned shop the archive shipped with.
Real commerce in this lib is NPC-vendor-based (`feature/dealer.lpc` /
per-NPC `do_buy`/`is_vendor_good` overrides, `add_action("do_buy",
"buy")`), scattered across many city zones (`changan`, `hz`, `hmy`,
`zhiye`, `sld`, `gb`, `village`, `hj` — not specifically Yangzhou).
Used admin `goto /d/zhiye/yaodian1` (a pharmacy in 成都/Chengdu run by
`d/zhiye/npc/yaodian-zhanggui.lpc`), `clone /clone/money/gold` (1 gold =
10000 copper) for funding, `list` to see real prices, then `buy yangjing
dan`: charged exactly 五十七两白银又五十文铜钱 (5750 copper, matching
the listed price), inventory correctly went from 1 gold (10000) to 42
silver + 50 coin (4250) and the character received "一颗养精丹
(Yangjing dan)". Price deduction and item receipt both verified exactly
correct. `debug.log` stayed clean.

**2. Combat-to-death cycle — resolved, verified clean, three full real
death/respawn cycles observed.** Created a fresh throwaway character
(id `sjdthtst`, Chinese name 测死人, password redacted) rather than
reusing the existing `qinshiyu` (whose `combat_exp: 1000000` from prior
rounds made it far too strong for any real starting-zone threat to pose
lethal danger). Confirmed `kill.lpc` has no safe-sparring-style gate
against real NPC targets (only PK-specific and `/d/wuguan/`-zone
protections) — matches this session's cross-lib precedent. Admin-cloned
a `/d/wuguan/npc/snake.lpc` (a real, weak, poison-on-hit wild animal)
into the character's room purely to get combat started quickly (its own
`init()` has a random auto-aggro chance); real, unmodified `hit_ob()`/
poison-condition/`die()` code did the rest — no `smash`/forced `die()`
call was needed this time, real mechanics alone produced a real death.
Sequence observed, twice for the player and once (via poison DoT
outliving the snake) for the admin account itself:
`die()` (蛇毒发作死了 — snake venom took effect) → 鬼门关 (death
gate/`DEATH_ROOM`) → a death-judge NPC (孟婆/Meng Po one time, 阎罗殿's
转轮王/Wheel-Turning King another — confirming both `mengpo.lpc` and
`yanluo.lpc`'s independently-`#include`d `death.h` guard chains work,
consistent with the already-closed §7.112 gap noted below) →
`death_stage()` dialogue chain → `reincarnate()` → respawn at
`START_ROOM` (武馆前院, since `enter_wuguan` was set) with stats fully
restored. `score` correctly recorded 死亡：一次／有效：一次 with 上次
遇害：蛇毒发作死了 after each death. `debug.log` (341 lines total this
session) had **zero** new `error`/`denied`/`bad argument`/`undefined
function`/`divide` lines through all three death/respawn cycles — no
new bug found by this test. Cleaned up by admin `smash`-ing the leftover
snake once done (verified `die()` alone, not `smash`'s forced path, was
what produced every death observed above).

**Other checklist items** (fast sanity pass per task brief, all
already fixed by earlier passes in this document, none re-derived):
§7.90 (`maximum evaluation cost : 5000000`, confirmed in
`config.fluffos`), §7.100 (only a commented-out
`replace_program(ROOM)` leftover in `d/xueshan/jlshan.lpc`, not live),
§7.111 (`standard_trace` present in `adm/single/master.lpc`), §7.112
(`death_stage_active` guard confirmed present via `death.h` `#include`
in all three of `mengpo.lpc`/`pusa.lpc`/`yanluo.lpc`, and exercised
live twice above with zero reentry symptoms), §7.108
(`enable_commands()` confirmed present in `clone/user/user.lpc`'s
`reconnect()`), §7.30 (`feature/skill.lpc`'s accessors confirmed using
the `mapp(x) ? x : ([])` guard pattern). No `combatd.lpc` `bounce`-
variable §-shape bug found — this lib's `combatd.lpc` has no `bounce`
variable at all, a different lineage from the sibling libs where that
bug was found.

**Test character left behind:** id `sjdthtst`, Chinese name 测死人,
password redacted — 普通百姓 (unaffiliated commoner), empty
inventory, standing at 武馆前院, `死亡：一次`. Admin account `fluffos`
also died once and reincarnated cleanly during this pass (a byproduct of
the test snake's poison outliving the snake itself) — no lasting state
issue.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).
