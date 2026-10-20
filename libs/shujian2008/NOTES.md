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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py shujian2008 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 515 个 `.lpc` 和 11 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：505 -> 505 通过，无回退；改过的头文件的 12 个包含者 11 -> 11 通过。启动时警告 17 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 20 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 4 处，覆盖函数返回类型 11 个）后，用 `scripts/lpc_twin_port.py adopt bxsj shujian2008 --pre 00dacc346b9~1` 和 `--pre 9624dde6015~1` 搬来孪生库 bxsj 的整理（52 个与 bxsj 修前逐 token 相同的文件：16 个 NPC 自带的门派表与 `FIGHTER` 的 `str_menpai` 同名、`inherit/misc/equip.lpc` 的 `ob_hit()` 改 `mixed`、`d/taishan/npc/runner.lpc` 的路线表与 `feature/command.lpc` 的 `path` 同名、`kungfu/skill/dzxy.lpc` 的招式表改在 `create()` 里赋给 `SKILL` 的 `attack_action` 等），再手工补其余，能编译的文件警告清零。改动的对象 HEAD 与工作树各载入一次：52 个，regress 0。

- `adm/daemons/huanjing2003/npc_obj/{dian,feng,lei,yu}_{npc,obj}.lpc`、`room_readygo_hj.lpc`：`string a, b, a = "x", b = "y";` 的写法让每个名字声明两次，合成一次带初值的声明（初始化顺序不变）。
- `d/gumu/npc/mmnz.h` 的 `kill_ob` 原型、`d/xingxiu/obj/duchong.lpc` 的 `kill_ob` 在 `void` 基类上写成 `int`，没人读返回值，改为 `void`。
- `cmds/usr/mygift.lpc`、`mygift2.lpc`：`?:` 两边 `int`/`string`，int 一边改 `(mixed)`。
- `d/village/npc/obj/robber.lpc`、`robber_n.lpc` 有意把 `NAME_D` 指向 `/inherit/misc/r_name`，`#define` 前加 `#undef`。
- `clone/npc/tdh/man1.h`：154 行开的注释实际被 164 行 `///*奖励控制开始*/` 末尾的 `*/` 关掉，改成 `*/ // 奖励控制开始`，注释结束位置不变；`d/shaolin/npc/h.lpc` 注释里嵌套的 `/*`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 21 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/fanchang`、`/kungfu/skill/hujia-daofa`、`/kungfu/skill/huntian-qigong/huntian`、`/kungfu/skill/lanhua-shou`、`/kungfu/skill/longxiang-boruo/fanchang`、`/kungfu/skill/yiyang-zhi`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-shengong`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`、`kuangwu`）；`qimen_baguazhen`→`qimen-baguazhen`（`suibo-zhuliu/wuzhuan`）；`xixing-dafa`→`xixin-dafa`（`tianlong-shengong`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuantia-wuji`→`xuantian-wuji`（`xuantian-wuji/wuji`）。

## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：任务系统 `job_area.h` 的 `get_arearoom()` 在 `keys(room)` 报错。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/cloth/cloth`、`/d/city/obj/blade`、`/u/lius/wudang/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 3 个，没有退步。

## `clone/spec/putao` 的 `long` 里引号错位（2026-10-18，KB 03 §4.6）

`set("long","这是一串由达摩传入中土HIG"神奇葡萄"NOR"，……")`：开引号落在 `HIG` 后面而不是前面，字符串在 `HIG` 处就闭合了，后面的 `神奇葡萄` 成了代码（`Illegal character 0xe7`），整个物件载入不了。把引号挪到 `HIG` 前面（`中土"HIG"神奇葡萄"NOR"，`，与同系其他库的同名文件一致）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## wushi.lpc 重复定义了头文件里的函数（2026-10-19，KB 06 §7.266）

`d/city/npc/wushi.lpc`（地下比武场的拳手）自己又写了一份 `nick_first`/`nick_second`/`create_nick()`，而它包含的 `skills_pfm.h` 里已经有一模一样的一份，驱动报 `Redeclaration of function 'create_nick'`，整个 NPC 载入不了；它还把 `skills_pfm.h` 已经包含过的 `r_name.h` 再包含一遍（`get_random_name()`/`random_name()` 因此也定义两次）。删掉文件里的重复定义和多余的那行 `#include "r_name.h"`，用头文件里的那份。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/shaolin/npc/xuan-du.lpc` 的 `#include "/u/hunthu/npc/xuan-du.h"` 改成 `/kungfu/class/shaolin/xuan-du.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon_combo`←sje：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/kungfu/skill/anran-zhang/jishi.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/clone/npc/mj.lpc`（3 处）、`/cmds/group/glist_new.lpc`（2 处）、`/d/city/npc/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。
