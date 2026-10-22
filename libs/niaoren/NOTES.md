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

## 深度功能测试（第二轮，2026-08-18）——补完拜师、战斗测试，均正常工作

补完上一轮留下的拜师、战斗测试。两者都验证正常工作，未发现新 bug。

- **战斗验证**：注册后的欢迎文本本身就给出了到武馆的完整路径（"客
  店往西，南，西，西，南就到武馆了"），到达"扬州武馆"的"练武场"
  房间后，对场上的"木人"（新手专用陪练木偶）使用 `fight mu`，触
  发真实的攻防交换（命中/躲闪/格挡描述逐条推进），符合房间描述本
  身的设计意图（"场上立着几个木人看来是让新手练习的好对象"）。
  `debug.log` 全程零报错。
- **拜师系统验证**：武馆本身（"陈有德"所在的房间）没有 `family`，
  只是一个中性的技能预备学校，不是真正的门派——这和欢迎文本"没想
  好拜哪个门派就先去武馆学"的措辞一致。用巫师账号 `goto`+`summon`
  把测试角色带到"梅庄"的"丹青生"（梅庄四庄主）面前，`bai sheng`
  触发了 `attempt_apprentice()` 的真实执行：先检查
  `shen（声望）>= 0`（新角色默认满足），再检查
  `query_skill("wuzheng-xinfa") >= 30`（内功技能等级，新角色默认
  为 0，不满足）——收到的拒绝理由"我是不轻易收徒的，在我梅庄的内
  功上，小兄弟是否还应该多下点功夫？"完全对应代码里的第二个检查
  条件，**是一个正常、合理的"技能未达标"拒绝，不是像 aoxiangtianji
  南海普陀山那样"要求已经是本门弟子才收"的循环矛盾条件**。这证实
  `bai`/`attempt_apprentice()` 这条链路本身工作正常：正确路由到目
  标 NPC、正确执行其自定义验收逻辑、正确给出对应拒绝台词。一个真
  正练满内功技能的角色理论上可以被这个 NPC 收为弟子，只是本轮测试
  用的全新角色天然不满足条件，不代表系统有 bug。
- 本轮结论：拜师、战斗两大此前搁置的系统都验证正常工作。与
  aoxiangtianji 那轮"确认某个门派入门条件是设计使然的高等级终局门
  槛"不同，这里额外确认了 `attempt_apprentice()` 逻辑本身对"低门槛
  可达"的普通门派也能正确工作——是对同一条 bai 指令链路的第二个独
  立正面案例。经济系统（真正的商店 buy/sell）仍未测试，欢迎文本提
  到"到杂货店去买金丝甲"、"到醉仙楼去买东西吃"，留给下一轮。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 60 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

上面"第二轮"（2026-08-03）那次早于今天的驱动重建（全库
`quest_times`/`win_times` `%`-operator 修复 + Warning/warning 驱动
文本回退），不能算作针对当前驱动的覆盖——这是真正针对今天驱动的重
测。`log_error()`（`adm/obj/master.lpc`，CRLF 行尾档案）已经在更
早一轮正确修复过（`strsrch(message, "arning:")` 大小写无关判断，
注释虽然还写着"驱动文本是小写"的旧记录，但判断本身与大小写无
关，今天的驱动文本回大写后依然正确工作），管理员账号
（`fluffos`/`Mud@2026`，`adm/etc/wizlist` 已有 `fluffos (admin)`
且存档已提交）也已经用真实注册流程创建并提交过，本轮只发现并修复
了 `log_file()` 一处。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`，CRLF 行尾档案）完全没
   有 `assure_file()` 保护（AGENTS.md §7.11-class 的又一确认实
   例）**：`feature/dbase.lpc`/`inherit/item/combined.lpc` 等文件
   多处 `log_file("trace/...", ...)` 调用依赖对应子目录存在。注册
   /登录本身只写 `log_file("USAGE", ...)`（无子目录，本来就存
   在），不受影响。已补上 `assure_file(LOG_DIR + file);`（含前向
   声明，用 Python 字节级替换保留原 CRLF 行尾格式）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:184`
  （繁体字变体，`已獲勝`）。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

登录前有一个"輸入任意鍵繼續..."（press any key to continue）分页
步骤，紧跟在欢迎横幅之后、id 提示之前，和本轮 `ldtxii` 遇到的形状
完全一样——已提前读代码确认，避免重蹈覆辙丢失第一个真实输入。用已
提交的 `fluffos`/`Mud@2026` 登录，`score`（画面繁体输出"目前權
限：(admin)"）确认权限正确，`update /adm/simul_efun/file`（就是本
轮改过的文件）确认可正常重新编译。`adm/log/debug.log` 时间戳全程
未变化（`Jul 24`，早于本次会话），确认无新增未捕获运行期错误。登
录本身产生的存档时间戳类微小 diff 已用 `git checkout` 撤销，不提
交。驱动最终按精确 PID kill，`ps -p` 确认已退出。

## 深度功能测试（第四轮，2026-08-19）——经济系统（商店买卖）验证，发现并修复两个真实 crash

前几轮已确认战斗、拜师均正常工作，唯独经济系统（真实商店买卖）一
直未测试。本轮专门针对欢迎文本提到的"到雜貨店去買金絲甲"、"到醉
仙樓去買東西吃"这两家店做完整验证，过程中发现并修复了两个独立的
真实 programming bug（均为无保护的运行期错误，非平衡性/内容设
计问题），验证了经济系统本身是可用的。

### Bug 1：`toptend.lpc::topten_add()` 的 `sscanf` 传错参数（AGENTS.md
### 排行榜家族 bug 的第 N 个独立实例，同一 codebase 血统里的确认）

新号注册流程（`logind.lpc::get_gender()` → `enter_world()` →
`TOPTEN_D->topten_checkplayer()` → `topten_add()`）在 `debug.log`
里稳定触发一条未捕获运行期错误：
```
執行時段錯誤：*Bad argument 1 to sscanf
Expected: string Got: ({ ... }).
程式：/adm/daemons/toptend.lpc 第 319 行
```
`topten_add()` 解析既有排行榜文件的 fallback 分支把整个 `explode()`
结果数组 `astr` 传给了 `sscanf()`（应该传当前行 `astr[i]`）：
```lpc
if(sscanf(astr[i],"%s(%s)%d",name,id,data)!=3)
    if(sscanf(astr,"%s(%s)%d;%*s",name,id,data)!=3)   // 应为 astr[i]
        return notify_fail(...);
```
这正是 AGENTS.md 里已经记录过的、`toptend.lpc` 这个共享守护进程反
复出现的第三种独立 bug 形状（"whole line-array passed to sscanf
instead of current line"，此前在 `xixingzhanji` 等库独立发现过），
`niaoren` 与 `cctx` 共享同一份 `toptend.lpc`（含 `add by
jackyboy@cctx 1999/3/8` 注释残留），这次是这份共享代码在 `niaoren`
这一支里独立复现。因为 `enter_world()` 里 `user->move(startroom)`
先于 `TOPTEN_D->topten_checkplayer()` 执行，未捕获错误只会截断
`enter_world()` 尾部两个 `set_temp("temp_exp"/"temp_time", ...)`
调用，不影响玩家进入起始房间本身——注册/进游戏表面上看起来完全正
常，只有翻 `debug.log` 才能发现。修复：`astr` → `astr[i]`（第 319
行），`update /adm/daemons/toptend` 热编译后用第二个全新角色重新
注册验证：`debug.log` 干净，无新增 `執行時段錯誤`。

### Bug 2：`feature/dealer.lpc`（商人 mixin）对 `vendor_goods` 里指
### 向不存在档案的条目没有任何保护，导致 `list`/`buy` 直接崩溃

`d/city/npc/yang.lpc`（雜貨鋪老板 楊永福，正是欢迎文本"到雜貨店去
買金絲甲"指的那家店）的 `vendor_goods` 数组里有一条
`"/u/sunpoet/torch.lpc"`——这份档案在整个 archive 里根本不存在
（`work/u/sunpoet/` 目录都没有；`sunpoet` 是原始 admin 账号之一，
这条大概率是残留的、从未真正落地的赠品引用）。`feature/dealer.lpc`
的 `is_vendor_good()`／`do_list()` 对 `vendor_goods` 数组里每一项
都直接 `->id(arg)`／`->short()`／`->query("value")`，任何一项文件
缺失都会抛出未捕获的 `*call_other() couldn't find object` 错误，
**且是无保护的**——玩家在楊老板店里打 `list` 或 `buy <任何东西>`
都会先崩这一条，`list` 崩到看不全后半段商品，`buy` 直接崩到完全买
不了任何东西（`is_vendor_good()` 遍历数组时崩在缺失条目上，永远走
不到匹配的正常条目那一步，取决于崩溃条目在数组里的位置）。这是一
个真实 crash（有明确 `debug.log` trace，非"店家拒绝"/"功能未实现"
这类设计范畴），修复方式沿用项目里 §7.115（`QUEST` 宏）同款"保护
调用点，不发明缺失档案"的原则：`is_vendor_good()`／`do_list()` 里
每次访问 `vendor_goods[i]` 前都包一层 `catch()`，缺失条目静默跳
过、不影响数组里其余条目正常展示/购买。这个 mixin 是通用商人基
类，`sell`/`value` 两个函数没有类似逐项遍历 `vendor_goods` 的写
法，未改动。修复后重新验证：`list` 完整列出楊老板全部商品（缺失
的那一条被跳过，后面的"袋子"等条目正常显示），`buy jia`（金絲甲
的实际关键字是 `"jinsi jia"`/`"jia"`，不是欢迎文本字面的
"金絲甲"三个字，第一次用错关键字试成了"你想買什么？"，换关键字后
成功）扣款、拿到物品全部正确。

### 经济系统完整验证（两笔真实交易，金额扣减/物品到手均正确）

用已注册好的测试号 `qinjinghuo`（管理员账号 `eval
MONEY_D->pay_player(...)` 现场充值 10 兩黃金，模拟"缺錢花，也可以
請老玩家幫你暫渡難關"这句欢迎文本里描述的、新手找人接济的机制，
而不是发明一个游戏本身没有的起始资金）：

- **雜貨鋪**（`/d/city/zahuopu`，客店 west→north→east→south 或从
  中央廣場 east→dongdajie1→south 可达）：`buy jia` 从 10 兩黃金扣
  到 7 兩黃金（金絲甲标价"三兩黃金"，扣款 3 兩，精确匹配），
  `i` 确认背包里多了"金絲甲(Jinsi jia)"。
- **醉仙樓**（`/d/city/zuixianlou`，北大街东边）：`buy baozi` 从 7
  兩黃金扣到"六兩[白銀]九十九兩[銅板]五十文"（即 69950 文，包子
  标价"五十文銅板"，精确扣掉 50 文，驱动自动拆整找零逻辑正常），
  `i` 确认背包里多了"包子(Baozi)"。
- **卖出测试**（按任务要求做了，但确认是设计范畴不是 bug）：对楊
  老板/醉仙樓店小二两家店分别 `sell baozi`/`sell jinsi jia` 都返
  回"什么？"（命令未识别）——追查代码发现 `feature/dealer.lpc` 里
  确实有 `do_sell()` 函数体，但 `yang.lpc`/`xiaoer2.lpc` 的
  `init()` 都只 `add_action("do_buy","buy")`/`add_action("do_list",
  "list")`，从未给任何一家普通商店 `add_action` 过 `"sell"`。全库
  搜了一遍谁真的 wire 了 `"sell"`：只有 `feature/pawn.lpc`、
  `inherit/room/hockshop.lpc` 和几个明确带"当铺/估价"性质的 NPC
  （`aqingsao`/`wei`/`tang` 等）。这和本项目此前在 `hell` 上踩过
  的近失误一模一样——普通杂货店/食肆本来就设计成只卖不收，只有当
  铺类 NPC 才回收物品，**不是 bug，未做任何改动**。

### 标准 bug 清单快速核对（本轮，均已 corpus-sweep 过，抽查确认无异常）

- **§7.90**（eval-cost 上限）：`config.fluffos` 第 40 行
  `maximum evaluation cost : 5000000`，已是标准值，无需改动。
- **§7.111**（`master.lpc::standard_trace()` 的
  `file_name(error["object"])` 未保护）：真正被驱动加载的 master
  文件是 `config.fluffos` 里配置的 `/adm/obj/master`，其
  `standard_trace()` 已经是 `objectp(error["object"]) ?
  file_name(...) : "(driver)"` 的正确保护形式。另有一份
  `/adm/single/master.lpc`（`MASTER_OB` 宏指向的辅助对象，供
  `domain_file()`/`author_file()` 等 call_other 用）里的
  `standard_trace()` 确实是未保护的旧写法，但全库搜索确认没有任何
  地方真的调用 `MASTER_OB->standard_trace(...)`——是死代码，不影响
  实际错误处理路径，未改动。
- **§7.112**（NPC `init()` 里无保护重复 `call_out` 死亡阶段链）：
  `d/death/npc/{bgargoyle,wgargoyle}.lpc` 都已经有
  `query_temp("death_stage_active")` 防重入保护（AGENTS.md 里记录
  `niaoren` 正是最终查漏补缺那 4 个库之一，已在更早的 wave
  之外单独修过），本轮确认保护仍然完整存在。
- **§7.113**（netdead 重连不恢复 `heart_beat`）：`adm/daemons/
  logind.lpc::reconnect()` 无条件调用 `user->reconnect()`，
  `clone/user/user.lpc::reconnect()` 无条件 `set_heart_beat(1)`，
  是正确血统（本库不在 AGENTS.md 62 库候选名单里被专门列出过，本
  轮直接静态核对，链路正确）。
- **§7.114**（`private input_line()` 通过 mixin inherit 导致递归
  `input_to()` 静默失效）：`grep -rl 'private.*input_line'` 全库零
  命中，不适用。
- **§7.115**（`QUEST` 宏指向不存在档案）：`include/globals.h` 里根
  本没有 `QUEST` 宏定义，也没有任何 `QUEST->` 调用点，不适用。

### 其他观察（未处理，记录以备将来参考）

- 第一次全新 boot（本轮 fix 之前）在加载 `/adm/daemons/httpd` 时
  `debug.log` 打印过一次 `Too deep recursion.`（`program:
  /adm/obj/master.lpc, object: /adm/obj/master, file:
  /adm/obj/master.lpc:341`），驱动随即正常继续完成剩余 daemon 编
  译并进入 `Accepting telnet connections`；`httpd.lpc::create()`
  本身没有被本项目 §7.52 那种"gut 掉 socket 守护进程"的处理过（仍
  然完整 `call_out("setup",5)` + 频道公告），不属于那个已知模式。
  修完上面两个 bug 后的第二次全新 boot 未复现这条 recursion 打印，
  怀疑是编译顺序/依赖加载时序相关的一次性瞬态，而非稳定可复现的
  driver-level bug——记录在案，但没有足够证据认定是真实 bug，未
  作任何改动（按"不确定就不动"的原则处理）。
- `work/data/{user,login}/q/qinzhandou.o` 是一个 2026-08-18（本轮
  之前一天）就存在的未跟踪测试号存档，明显是上一轮（拜师/战斗测
  试）遗留、未清理干净的痕迹，不是本轮创建的，本轮未触碰。

### 清理与收尾

测试号 `qinjinghuo`（经济测试主号）、`qinerhuo`（topten 修复验证
用的干净对照号）的存档在验证完成后已删除
（`work/data/{user,login}/q/{qinjinghuo,qinerhuo}.o`）。管理员账
号 `fluffos` 因本轮登录/`update`/`eval` 操作产生的存档时间戳更新
属于正常存档演进，已随本轮改动一并提交。驱动全程用精确 PID
kill（两次重启各自记录 PID，`kill <pid>` + `ps -p <pid>` 确认已退
出），未使用任何 pattern-match 方式。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). `fix_710_room.py`
deleted 2,339 live standalone `replace_program(ROOM);` lines; a
follow-up hand fix caught 6 more files with the irregular
"space-before-semicolon" shape (`replace_program(ROOM) ;`) the strict
script correctly left alone — `d/shenlong/dahai.lpc`,
`d/quanzhou/dahai.lpc`, `d/taohua/chufang.lpc`, `d/taohua/dahai.lpc`,
`d/xiakedao/duchuan.lpc`, `d/xiakedao/dahai.lpc` — plus the
room-building tool's string-builder template
(`work/clone/misc/roommaker.lpc`). Total 2,346 live occurrences
removed, matching the survey's count exactly. No `.lpc` files under
`work/data/` at all in this lib, so no false-negative risk there.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`, traditional-Chinese client) into 巫師休息室,
`look`/`score`/`quit` all worked cleanly. Incidental
`data/{login,user}/f/fluffos.o` save drift from the login test was
reverted via `git checkout HEAD` before committing.

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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py niaoren --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 500 个 `.lpc` 和 14 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：471 -> 471 通过，无回退；改过的头文件的 146 个包含者 146 -> 146 通过。启动时警告 16 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 18 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 12 个文件，HEAD 与工作树各载入一次无回退（12 objects; HEAD PASS 12, tree PASS 12; regress 0; newly loading 0），这些文件的警告 18 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `d/xingxiu/nanjiang2/3.lpc`、`shanjiao.lpc`：删去空的 `if (current_water==0) { }`（行为不变）。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件中的编译警告 92 → 0，不加 pragma，逐条在源头修。

- 24 处冗余继承删去：20 个 `inherit F_CLEAN_UP;`（`NPC`/`sserver`/`money`/`boots`/`blade`/`SKILL` 基类已带）、`quest/helian.lpc`、`shan.lpc`、`weixiaobao.lpc` 在 `NPC` 之外又 `inherit F_SKILL;`（每个 4 条重复声明 + 14 个函数两份），`kungfu/skill/taixuan-gong.lpc` 在 `FORCE` 之外又 `inherit SKILL;`。同一份代码经两条路进来，删去一份不改行为。
- `inherit/private_room.lpc`、`recordable_room.lpc` 的 `int setup()` 在 `void` 基类上：改 `void`（无调用者读返回值）。
- `d/death/god1.lpc` 同时继承 `ROOM` 与 `SKILL`，两边的 `clean_up()` 都来自 `feature/clean_up.lpc`：照驱动原来的选择写出 `skill::clean_up()`。
- 没有找到玩法上的真 bug。
- 未修：`include/daemons.h`（Lima 的守护进程表）重定义 `ALIAS_D`/`CHANNEL_D` 等 6 个宏，只有 `adm/daemons/network/ms.lpc`、`mail_serv.lpc` 引用它，这两个文件缺 `uid.h`/`mailer.h` 等头文件，本身编译不过，不在范围内。

改动的 27 个文件与继承两个房间基类的对象共 29 个，HEAD 与工作树各载入一次：HEAD PASS 24，tree PASS 24，regress 0；5 个 FAIL 两边相同（`adm/npc/luban`、`d/quanzhou{,.old}/npc/tang{,3}` 批量载入时 `restore_object` 读存档被拒，运行期问题）。`lpc_audit_removed_locals.py` 0 处待看。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。4 个文件 4 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：`d/baituo/ouyangfeng.lpc` 闲聊的 `write("…")` 少了分号，整份不编译；补上。之后还卡在第 78 行的 `this player`（原文如此，留待逐行修）。

- 2026-10-14（补）：`ouyangfeng.lpc` 的 `inquiry_map()` 写成 `this-player()`，改为 `this_player()`，删去没用的 `ob`。现在载入。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-fu/du1`、`wuyue-blade/wu1`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`dragon-whip`（内力修为门槛 `query_skill("max_neili") < 500` 永远不过）；`liancheng-jian/li1`、`liancheng-jian/li2`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`taiji-shengong`、`xiantian-gong`）；`taijishengong`→`taiji-shengong`（`beiming-shengong/god-sword/godangry`、`god-sword/go1`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/f`）；`tanzhi_shentong`→`tanzhi-shentong`（`tanzhi-shentong/ta1`）。

## 八识神通 drift_sense 少一个括号（2026-10-15）

`bashi-shentong/drift_sense` 第 55 行改条件时漏了右括号（`if( random(me->query_skill("magic")) < 100 {`，原条件还注释在上一行），文件编译失败。补上括号，保留本库改过的 `< 100`。本库目前没有地方传授八识神通。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事要离开时报错，留在原地。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（5 个名字，最多的是 `shenlong-quanfa`、`xiake-force`、`xiake-strike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 3 个通过，其余 1 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 10 处、9 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`yan-fly`→`yanfly`（2 处）、`juemen-gung`→`juemen-gun`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::setup()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/city2/npc/zhengmen.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/d/city4/puke-room.lpc`（4 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `tail` 指令：`tail(file)` 驱动里没有（2026-10-20，KB 06 §7.291）

`cmds/*/tail.lpc` 调用 MudOS 的 `tail()` efun，FluffOS 没有，指令编译不过。模拟 efun 文件里补了 `tail(file)`（Discworld 家族的兼容版：文件最后约 20 行，从完整的一行开始，存在返回 1；`scripts/lpc_add_sefun.py tail`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `valid_read()` 不信任 sefun 对象的 euid `"NONAME"`（2026-10-20，KB 06 §7.295）

启动时 `Too deep recursion.` 两次（`/adm/simul_efun/file.lpc` 的 `log_file()` → `assure_file()` → `file_size()` → 主控 `valid_read()` → `SECURITY_D->valid_read()` 拒绝 sefun 对象（它的 euid 是 `"NONAME"`）→ 拒绝记录又调 `log_file()`），之后每次 `log_file()` 都递归，日志文件一个也写不出来。`valid_write()` 早就信任 `"NONAME"`，`valid_read()` 补上同样的判断（`securityd.lpc`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 华山论剑排行榜：第一场比武就读不到 `/data/ladder.txt`（2026-10-20，KB 06 §7.326）

比武裁判在一场比武结束时先 `list = explode(read_file("/data/ladder.txt"), "\n")`，读完再 `rm` 并 `write_file` 写回；`/data/ladder.txt` 是比武本身写出来的，全新的树里没有，第一场比武结束就是 `Bad argument 1 to explode()`，排行榜永远建不起来。把写回之前的那一次读改成 `read_file(...) || ""`（空表走原来的 `lost == -1 && win == -1` 分支，把第一对名字写进去）；写回之后的第二次读文件已经存在，没有动。加载检查各 1/1。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/adm/blockade.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 4 条注册（3 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city4/qishi.lpc`（`do_pass`、`do_resign`）、`/d/wudang/tyroad13.lpc`（`look_feng`）、`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_pass` 1 处、`do_resign` 1 处、`look_feng` 1 处、`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/chinesed.lpc` ← bxsj：`chinese_time()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/ximenroad.lpc`:`look_gaoshi`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 5 个文件里有 5 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/FENG`、`/log/nosave/KILL_PLAYER`、`/log/nosave/ATTEMP_KILL` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"gaoshi" : (: look_gaoshi :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 45 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 45 处（31 个文件）：拼名字的赋值 23 处、与汉字常量比较 22 处。例：`name[0..1]` → `name[0..0]`（`/d/tianlongsi/npc/kurong.lpc:402`）；`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/miejue.lpc:125`）；`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:2184`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
