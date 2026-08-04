# niaoren — 鳥人世界 / "The Bird-Man World" (xkx codebase, MudOS v22-era)

Archive: `最新鳥人世界.zip`. Port: **40100**. Status: **done** (boots clean,
full registration flow verified end-to-end with a real Chinese name,
admin account verified in both native and WASM modes).

## What this is

`config.cfg`'s own `name` field (raw bytes `b3 be a4 48 a5 40 ac c9`,
BIG5-decoded) is 鳥人世界; the in-game banner also spells it out as
"THE BIRD-MAN WORLD" and stamps `MudOS: v22c2` / `* MudOs V22pre11 *`.
Root in the archive is nested two levels deep: `mudxkx/xkx/` (the
extraction's outer `mudxkx/` wraps the actual mudlib root `xkx/`, plus a
sibling `mudos.exe`/`mudos.log` — a Windows MudOS binary distribution, not
part of the mudlib itself). `config.cfg`: `master file : /adm/obj/master`,
`simulated efun file : /adm/obj/simul_efun`, `mudlib directory` pointed at
a hardcoded `d:\mudxkx\xkx` (Windows path, ignored — our `config.fluffos`
uses the correct absolute Linux path). This is a Jin-Yong-themed wuxia
mudlib (the intro text explicitly says the plot/setting draws on "金庸的
十五本小說" — Louis Cha's fifteen novels), same broad genre as most of this
project's other libs, built on what looks like a customized ES-family/xkx
codebase (not literally the same lineage as the ES2/Annihilator family
seen in `huoying` — different `master.lpc`/daemon shapes, no shared
copyright header).

Sizable archive: 7028 raw `.c` files (the vast majority of the tree; a
handful of oddly-extensioned leftover/backup copies also exist — see
below), no bundled driver source beyond the Windows `mudos.exe` binary
(harmless, left alone, not part of `work/`... actually IS copied into
`work/` by the mechanical `raw/`→`work/` copy since `convert_lib.sh`
copies the whole raw root; it's inert, never loaded by the driver, and
not worth special-casing out).

## Resumed session note

This lib's `libs/niaoren/{config.fluffos,raw/,work/,lpcc_*.log}` already
existed on disk when this session picked it up (a prior agent, stopped
for an unrelated reason — wrong model, not a quality problem — had
already done the BIG5 conversion, `.c`→`.lpc` rename, boot, and initial
registration/admin-seeding pass). This session **verified and extended**
that work rather than redoing it: confirmed the encoding fix was already
solid, found and fixed 3 additional small leftover bugs (below), applied
the fail-closed loopback-gate correction, and did full native+WASM
dual-mode verification from a fresh boot (a previous long-running driver
instance from the earlier session was still using a stale in-memory
compile of one file — see the "stale-process" gotcha below).

## The BIG5 "0x5C trail-byte" encoding gotcha (already fixed on disk; this
## session's job was verifying and scoping it, not applying it from scratch)

BIG5 is a variable-width, non-self-synchronizing encoding: a lead byte in
`0x81-0xFE` is always followed by exactly one trail byte, and BIG5's trail
byte range (`0x40-0x7E` and `0xA1-0xFE`) **includes `0x5C`, the ASCII
backslash**. 88 distinct BIG5 characters have a trail byte of exactly
`0x5C` (computed directly: `bytes([lead,0x5c]).decode('big5')` for every
`lead` in `0x81..0xFE`) — e.g. 許(`b3 5c`)/么(`a4 5c`)/功(`a5 5c`).

If ANY processing step in a conversion pipeline treats the raw byte stream
byte-wise instead of encoding-aware (the classic case: a shell/sed pass
that does a blanket "escape every backslash" substitution on bytes that
are still BIG5, before the real decode step) that trail byte gets
literally doubled: `[lead][0x5c]` → `[lead][0x5c][0x5c]`. A subsequent
correct BIG5 decode then reads `[lead][0x5c]` as the intended character
(e.g. 功) and is left with one **extra literal ASCII backslash** trailing
it — the character displays correctly but is immediately followed by a
stray `\` in the decoded UTF-8 text. This is easy to miss because it does
NOT throw a decode error (both bytes of the pair are still individually
valid under BIG5) — it just silently corrupts adjacent, unrelated text.

**Verification performed this session** (this is the "targeted sweep, not
just the one instance" the resume note asked for): generated all 88
trail-byte-0x5C BIG5 characters, then grepped the entire `work/` tree
(decoded as UTF-8) for `[one of the 88 chars]\` as a regex class across
every file, not just `.lpc`/`.h`:

- **All real, driver-loaded source (`.lpc`/`.h`, 7032+110 files): zero
  hits.** The fix (whatever exact mechanism the prior session used — no
  script survived in this session's `/tmp`, which is shared scratch space
  across many concurrent per-lib agent sessions on this same host, so the
  original fix script itself couldn't be recovered/audited directly, only
  its result) was already completely and correctly applied to every real
  `.c`→`.lpc` file before this session started.
- **657 hits, but ALL confined to inert leftover files** with
  non-standard extensions the driver never loads (`.java`, `.solo`,
  `.vns`, `.old`, `.jas`, `.jav`, etc. — old backup/draft copies the
  original author apparently kept alongside the real `.c` file, e.g.
  `kungfu/class/yunlong/chen.c` + a byte-different `chen.java` sibling).
  Confirmed these are genuinely inert: FluffOS only auto-resolves
  extensionless loads to `.lpc` then `.c`, never any other extension, and
  a raw-archive byte-level scan (`0x81-0xFE` lead byte + doubled `0x5C`)
  shows the SAME doubled-backslash pattern already present in the
  **pristine, unconverted raw archive bytes** for these odd-extension
  files specifically (e.g. `chen.java`'s raw bytes have `a5 5c 5c` at all
  13 occurrences of 功) — while the sibling `chen.c`'s raw bytes do NOT
  have the doubling at all. In other words: this specific doubling isn't
  something our pipeline introduced on these backup files either — it's
  baked into the archive itself, on files that were never live code, and
  is out of scope to chase further (no gameplay path reaches a `.java`/
  `.vns`/etc. file). Left as-is, matching AGENTS.md §13 (genuine archive
  content, not our conversion's problem).

**Net conclusion for this archive**: the trail-byte bug is real, was
correctly and completely fixed on the actually-playable source before
this session started, and does not need a further sweep — the remaining
657 instances are all in dead files outside the driver's load path.

### Stale-process gotcha hit while verifying the above

Before concluding the fix was complete, this session's first check
against a still-running driver instance (left over from the prior
session, PID confirmed via `/proc/<pid>/cwd` before touching it — same
precaution as `huoying`'s notes) showed a MANGLED title string at
runtime: `score` displayed `䏟 大鳥人 𨧨` around the admin rank name, where
`adm/daemons/rankd.lpc`'s on-disk source (byte-verified) has the correct
`HIW "【 大鳥人 】" NOR`. This looked at first like a live instance of
exactly the trail-byte bug — but grepping the source found nothing wrong.
Root cause: the long-running driver process (started ~before some earlier
edit to `rankd.lpc`) had that file's OLD compiled bytecode cached in
memory and was never sent an explicit `update /adm/daemons/rankd`, so it
kept serving whatever `rankd.lpc` looked like at the time it first
compiled — completely unrelated to the current, correct on-disk content.
Killed that stale process and did a **fresh** boot for all verification
in this session; the mangled brackets do not reproduce on a clean boot
(`score` now correctly shows `【 大鳥人 】` and `【 平  民 】` for a regular
player). **Lesson**: don't trust a long-running driver instance found
already listening on a lib's port as evidence of current-source behavior
— always verify PID/start-time against the files' last-modified time, or
just kill and reboot fresh before drawing conclusions from live output.

## Other fixes applied this session (mechanical, unrelated to encoding)

1. **`cmds/skill/array1.lpc`** — `inherit SKILL;` textually AFTER
   `int mean;` (a global variable declaration) — the standard "Illegal to
   inherit after defining global variables" shape (AGENTS.md §6.1).
   Reordered (`inherit` first, then the global). Isolated to this one
   file (grepped the rest of the `lpcc_fail.log` for the same error text
   — no other occurrences).
2. **`adm/npc/itemmaker.h`** (included by `adm/npc/ganjiang.lpc` and
   `d/cloud/npc/itemmaker.h`'s own copy) — a genuine original-author typo,
   confirmed present byte-for-byte in the raw pre-conversion archive too:
   `sprintf("\t\tset(\"unit\\", \"%s\\");\n", ...)` has one extra literal
   backslash before several closing escaped-quotes (`\"unit\\"` where it
   should be `\"unit\"`), which prematurely closes the C string literal
   one token early and desyncs the parser for the rest of the line/file
   (produces cascading "Illegal character '\'"/"unexpected token" errors,
   NOT a BIG5 issue — this is plain ASCII). This is a code-GENERATOR
   template (an admin "make item" authoring tool that emits `.lpc` source
   as text), so the bug never affected regular gameplay, only that one
   admin utility. Fixed by removing the 23 stray extra backslashes
   (`data.replace('\\\\"', '\\"')` across the file). Same shape recurred
   verbatim in `clone/misc/objmaker.lpc` (its "make armor" sibling tool,
   4 instances) — fixed identically.
3. **`d/cloud/npc/asd.lpc`** — an NPC's multi-line `"long"` description
   was missing the closing/re-opening quote marks between lines entirely
   (`set("long","...人物"\n\n                    其武功...` — no quote
   before `其武功`), again confirmed byte-identical in the raw archive (a
   genuine, always-broken original NPC file, not conversion fallout).
   Fixed by quoting and `\n`-joining each line properly. Low-impact (one
   NPC's flavor text), fixed because it was quick and matches the
   project's precedent for single-file typo fixes (cf. `huoying`'s
   `gai.lpc`).

## `lpcc` sweep

`scripts/lpcc_check.sh libs/niaoren/config.fluffos libs/niaoren/work`:
**6796/7032 pass (96.7%)**, up from 6765/7032 (96.2%) before this
session's 3 fixes above (the delta is larger than 3 because
`itemmaker.h` is `#include`d by more than one file). Remaining 236
failures are a long tail spread across dozens of independent world zones
(`/d/city` 14, `/d/shaolin` 12, `/clone/board` 10, `/d/foshan` 9,
`/kungfu/skill` 8, `/d/wudang` 8, `/d/dali` 8, `/d/city2` 8,
`/adm/daemons/network` 8, ...) — sampled several individually (not just
pattern-matched) and all are genuine, independent archive gaps: missing
rooms a clone tries to `move()` into at `create()` time
(`/clone/board/lpc_b` → nonexistent `/d/wizard/lpcroom`), MudOS-only
socket/network primitives with no FluffOS equivalent
(`adm/daemons/network/*`: `dump_socket_status`, raw `socket_create`
inetd/mailserv/pingd-style daemons), the well-known `tail()`/
`dump_socket_status()` missing-efun gaps (§8e-family, unused admin
commands), a handful of `Undefined variable 'GAOSHOU'`/`'THIS_MUD'`-style
missing shared constants in disused daemons (`postal`/`richman`/mail
system), and more single-file NPC/room typos of the `asd.lpc` shape that
weren't chased further per the "breadth over depth" policy across 3
archives this session. None of these are on the registration/first-room/
admin path (confirmed by the full interactive tests below reaching the
game world cleanly with zero runtime errors of these shapes).

## WASM-readiness / fail-closed loopback pass (this session)

Found the **previous session's loopback patch already used the
fail-open shape** the orchestrator's mid-task security correction
explicitly asks to retire (any malformed/non-string/unparseable IP was
being treated as "trust it, must be loopback"). Retrofitted both sites to
the fail-closed shape (loopback ⇒ exactly `"127.0.0.1"`/`"::1"`/a
`"127."` prefix/`"localhost"`; anything else, including something the
driver couldn't resolve, is now treated as an ordinary remote value and
still subject to the gate):

- **`adm/daemons/band.lpc`'s `is_banned()`** — was
  `if (!stringp(site) || site=="127.0.0.1" || site=="localhost" ||
  sscanf(site,"%*d.%*d.%*d.%*d")!=4) return 0;` (any non-dotted-quad
  string — including a plain hostname or a malformed value — silently
  bypassed the ban list entirely). Tightened to check loopback forms
  explicitly first, then fall through to the real ban-list check for
  everything else (including unresolved/non-string input, coerced to
  `""` rather than exempted).
- **`adm/daemons/logind.lpc`'s `get_passwd()` reconnect-flood throttle**
  (~line 220) — same fail-open shape on `query_ip_number()`; flipped the
  condition so the throttle applies to anything that ISN'T positively
  loopback, rather than only applying to things that ARE a valid non-loop
  back dotted-quad.
- **`adm/daemons/logind.lpc`'s same-IP concurrent-login cap** (~line 112,
  "只允許同時登陸三個IP") had no loopback exemption at all in either the
  original archive or the prior session's pass; added one (skip the whole
  counting block when the connecting IP is loopback) so repeated
  local/WASM test connections can never trip it.
- No `uptime()` startup gate exists — `UPTIME_CMD->main()` (called
  unconditionally at the top of `logon_main()`) is purely cosmetic output
  ("鳥人世界已經執行了...") via the real `uptime()` efun, not a gate of
  any kind. Confirmed by reading `cmds/usr/uptime.lpc` in full.
- No per-IP registration-count throttle (the `huoying`-style
  "创造的人物太多" pattern) exists in this lib at all — grepped for it,
  zero hits.

Recompiled both changed daemons live (`update /adm/daemons/band`,
`update /adm/daemons/logind`) and retested: loopback reconnect within the
16-tick throttle window still succeeds immediately (no "距上次退出僅...
tick" message), matching pre-patch behavior for local play.

## Boot + registration-flow verification (fresh boot, this session)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/niaoren/` (per AGENTS.md §5.2, log directory is CWD-relative).
Clean boot, only cosmetic `nosave`/unused-variable warnings, `Accepting
telnet connections on 0.0.0.0:40100.` / `Initializations complete.`.

**Registration flow order for this lib** (read from
`adm/daemons/logind.lpc`'s actual `input_to` chain, not guessed from
prompt text): `logon`→`get_id`→`confirm_id`(y/n)→**`get_name`
(Chinese name FIRST, before password)**→`new_password`→
`confirm_password`→`get_gift`(accept random stat roll, y/n)→`get_email`→
`get_gender`→`enter_world`. Note this lib's ordering differs from some
others in this project (Chinese name is asked before the password, not
after) — worth checking per-lib rather than assuming a fixed order.

Full transcript (`scripts/mudclient.py`), fresh id `qinfengniao` (must be
pure letters, digits are rejected with "你的英文名字只能用英文字母"):
```
--send ""              # "press any key to continue" banner
--send "qinfengniao"    # id
--send "y"              # confirm new character
--send "秦风"           # REAL Chinese name (get_name -> check_legal_name)
--send "test12345"      # password
--send "test12345"      # confirm password
--send "y"              # accept the random stat roll
--send "test1@test.com" # email
--send "m"              # gender
--send "look" / "score" / "quit"
```
Result: name "秦风" (2 Chinese characters) accepted without any rejection
message, character entered the world directly into 龍門客棧 ("Dragon Gate
Inn") with full scene text, NPC (店小二), and board present. Reconnect
(same id/password) → `重新連線完畢` → same room restored correctly.
`score` showed the correct title bracket rendering (`【 平  民 】`),
correct stats/bars, all in properly-rendered Traditional Chinese. `quit`
saved and disconnected cleanly (`歡迎下次再來！`). Immediate re-reconnect
(well within the 16-tick throttle window) succeeded without the flood
message, confirming the loopback exemption survived the fail-closed
tightening above.

## Admin account

Already seeded by the prior session (this session verified it end-to-end
and did not need to recreate it): id `fluffos`, password `Mud@2026`,
Chinese name 無敵鐵鳥 ("Undefeated Iron Bird" — a fitting pun on
鳥人世界/"bird-man"). Granted `(admin)` via `adm/etc/wizlist`'s plain-text
per-line format (`fluffos (admin)`, alongside the archive's original
admin accounts `andy`/`leos`/`sunpoet`/`nick`/`roye`... wait, those last
few are `(arch)`; the pre-existing `(admin)`-level accounts are `andy`,
`leos`, `sunpoet`, `nick`). Save files (must be committed — gitignored by
default): `work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

Verified THIS session, from a fresh boot, via the standard flow (id →
password, no confirm/registration since it already exists): login shows
`目前權限：(admin)`; ran the actual wizard command
`update /adm/daemons/rankd` → `重新編譯 /adm/daemons/rankd.lpc：成功！`
(and again for `band`/`logind` after the loopback-gate edits above) —
confirms real wizard-level access, not just a cosmetic permission string.
`score`/`quit` also verified clean for this account.

## WASM verification (`scripts/wasm_client.js` against `build-wasm/src`)

Both a fresh registration and the admin login were run against the WASM
build (in-process driver, `work/` copied into MEMFS — this does NOT
write back to the host's real save files, so no WASM-side test leaves
save-file cleanup to do):

- Fresh registration, id `wasmniao`, real Chinese name 秦风: full flow
  (same order as native above) completed into 龍門客棧, `look`/`score`
  showed correct `【 平  民 】` bracket rendering, `quit` clean.
- Admin login `fluffos`/`Mud@2026`: `目前權限：(admin)`, `score` shows the
  correct `【 大鳥人 】` bracket rendering (confirming the trail-byte fix
  holds under WASM too, not just native), `quit` clean.

**Verdict: native OK + WASM OK.**

## Process/cleanup notes

- Killed the prior session's stale long-running driver instance (PID
  verified via `/proc/<pid>/cwd` pointing at this lib's `work/` before
  touching it) and did a fresh boot for all of this session's testing.
- Deleted the leftover test character `qinfengniao`'s save files
  (`work/data/{user,login}/q/qinfengniao.o`) created during this
  session's native registration test, since this lib is being freshly
  committed and a stray one-off test account isn't worth keeping. The
  `fluffos` admin account's saves ARE kept/committed (see above).
- No other agent's driver instance was found on port 40100 at any point
  in this session (checked via `ss -ltnp` + `/proc/<pid>/cwd` for every
  `driver` process before killing anything).

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到浅层冒烟测试，而且血统标记为"未分类"（AGENTS.md 里
明确记载"treat as unclassified until someone actually diffs it against
xkx2001/xuanjianlu"）。本轮做了两件事：解决了血统悬案，并发现修复
了一个真实 bug——这个 bug 正是因为血统关系才被联想到要去检查的。

### 血统悬案解决：和 `cctx`（驰骋天下）是同一套代码库的独立分支

启动前先按 AGENTS.md 的建议，把这份档案的 `master.lpc` 和
`xkx2001`/`xuanjianlu` 做了字节级 diff——确认**不是**同一血统（两两
之间都有 500+ 行差异，相对于全文件只有 340-349 行，差异比例太高，
不可能是"同一份代码的少量修改"）。之前"未分类"的判断本身是对的，只
是比对错了对象。

真正的血统线索出现在实测注册流程中：天赋选择提示"一個人物的天賦對
于他或她所修習的武藝息息相關。俠馳騁江湖中的人物大多具有以下四項天
賦"，这段文字（连"俠馳騁江湖"这种不常见的措辞都一字不差，只是繁简
转换）和本次会话刚刚深度测试过的 `cctx`（驰骋天下）注册流程里的同
一段提示逐字相同。进一步确认：`adm/daemons/logind.lpc` 里至今还留
着一行 `write(read_file("/adm/etc/cctxinfo") + "\n");`——`cctxinfo`
这个档案名本身就是"cctx"的残留痕迹，`adm/etc/cctxinfo` 这个档案也
确实存在于这份代码库里，从未在分支/改名过程中被重新命名。这是确凿
的证据：`niaoren` 是从 `cctx` 同一套源码分支出来、重新包装成"鳥人
世界"（金庸十五本小说背景）品牌的独立版本，不只是"看起来像"。已把
这条血统关系写进 AGENTS.md §11 的血统地图。

### 由血统关联发现并修复：食物/饮水初始化门槛读错了物件（AGENTS.md §8.9 第二例）

既然确认和 `cctx` 同源，就顺手检查了 `cctx` 那次深度测试发现的
§8.9 类 bug（`enter_world()`-等价函式里食物/饮水初始化门槛混用了
`user`/`ob` 两个不同物件）是否也存在——**确实存在**，一字不差的同
一处坏代码：`adm/daemons/logind.lpc` 第 522 行
`if (!user->query("food") && !user->query("water") &&
ob->query("age") == 14)`，前两个条件读 `user`（玩家身体），最后一
个却读 `ob`（登录连线物件）。和 `cctx` 一样，`clone/user/login.lpc`
全代码库没有任何地方给 `ob` 这个物件设过 age，而
`clone/user/user.lpc` 的 `update_age()`（由 `setup()` 呼叫，在这个
判断之前就已经执行过）确实会把 `user` 自己的 age 设成 14。
`ob->query("age")` 因此永远回传驱动默认值 0，判断条件永远为假，
**每一个全新玩家食物/饮水槽永远是空的**，第一次 `look`/`score` 就
会触发"你餓得直冒金星，實在是頂不住了"的挨饿提示。已把
`ob->query("age")` 改成 `user->query("age")`，和 `cctx` 的修法完全
一致。修复前后各注册一个全新角色对照验证：修复前 `score` 显示食物/
饮水槽全空，伴随挨饿提示；修复后两条槽全满，没有挨饿提示。这也是这
个 bug 类别第一次在"因为确认了共享血统而主动去检查手足档案是否也有
同一个 bug"这种方式下被发现的，而不是独立踩雷。

### 完整验证：从注册到留言板

用全新账号在原生驱动上完整走通：英文 id（3-8 个字母）→ y 确认 → 中
文名字 → 密码 + 确认 → 天赋摇点（y/n 确认）→ 电子邮件 → 性别 → 进
入"龍門客棧"（客栈门口挂着一个牌子(paizi)）。店小二 NPC 主动搭话
（"這位小兄弟，進來喝杯茶，歇歇腿吧"），确认 `command()` 自呼叫对
话链路正常。`look board` 显示"客店留言板"——一块保留着真实历史玩家
留言的公告板，标题涵盖 bug 报告（"少林超大bug！！！！！"）、任务
修复公告（"單正quest 已修好"、"明教乾坤大挪移quest已增加"）、平衡
性调整（"東方不敗的武功稍做調整(變強一點點)!"）、门派讨论（"逍遙派
到中央"）等，是这批档案里少见的、完整保留下来的原始玩家社群历史记
录，很有保存价值。`quit` 干净退出（丢弃不值钱的布衣，"歡迎下次再
來！"），并确认下次连线会从当前位置继续（"當你下次連線進來時，會
從這裡開始"）。debug.log 除了驱动启动期噪音外没有来自本次实际游玩
会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证血统关系、食物/饮水 bug 修复、以及基础注册/移动/留
言板流程，没有走到：拜师（武馆在客店西南方向）、战斗、门派系统的
实际互动。这些留给下一轮，目前的验证边界如上所述。
