# xyzxfy2 — 夕阳再现 之「风云再起Ⅱ」

Archive: `夕阳再现-风云再起2.rar`. Port: 40041. Status: **done** (boots
clean and quick, full registration flow verified end-to-end including a
real Chinese name reaching the actual game world).

## What this is

"夕阳再现" ("Sunset Reappears"), subtitle "「风云再起Ⅱ」" ("Storm Rises
Again II"), domain www.zhaoshu.net, ZMUD port 5555 / TOMUD port 9999 per
its own connection banner. `adm/obj/{master,simul_efun}` layout —
credits in `master.c` ("change by Fan@wanxia") and `securityd.c`
("Annihilator@Eastern.Stories", "Modified by Xiang for XKX") place this
in the broad Eastern-Stories/"ES"-descended family that also produced
`es1_win`/`esI`/`xkx2001`/`rzrmud`/`dfgs2` (archives #12/13/25/
23/33) — but none of `master.c`/`securityd.c`/`logind.c` are byte-identical
to any of those (all distinct md5sums), so this is its own fork, not a
direct copy of a previously-processed lib.

**Lineage check against archive #46** (`夕阳再现-疯狂江湖.rar`, being
processed concurrently in this same session): `adm/simul_efun/chinese.c`
is byte-identical between the two archives (same md5sum), confirming a
shared "夕阳再现" base engine, but `logind.c`/`master.c`/`securityd.c` all
differ — consistent with the project's general finding that similar
Chinese titles/shared branding don't imply identical code (only the
"chinese.c" utility file happened to survive unmodified across the two
site forks; the site-specific daemons diverged).

~14,707 raw files, 13,560 after `.c`→`.lpc` rename — one of the larger
libs in this batch, but memory stayed healthy throughout (lpcc sweep RSS
peaked ~6.7GB out of 23GB host, never approached the OOM-risk threshold
in AGENTS.md §6b).

## Fixes applied

1. **AGENTS.md §15h** (standard shape, `chinese.lpc`'s `is_chinese()`):
   GBK lead-byte range check (`str[0] > 160 && str[0] < 255`, `strlen>=2`)
   → CJK codepoint range check (`str[0] >= 0x4e00 && str[0] <= 0x9fff`,
   `strlen>=1`).
2. **AGENTS.md §15h** (`logind.lpc`'s `check_legal_name()`): byte-count
   bound `strlen < 2 || > 10` → character-count bound `< 1 || > 5`
   (matches the message's own stated "1 到 5 个中文字"); removed the
   `i%2==0` even-byte-offset gate so every character position is checked
   via `is_chinese(name[i..i])` instead of the old 2-byte GBK window
   `name[i..<0]`.
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot attempt.
   Checked every other preload entry's source for `socket_create`/
   `resolve()` calls (fingerd, channeld, natured, monitord, storyd,
   autosaved, rankd, commandd, aliasd) — none use networking, confirmed
   safe to leave. `httpd` was already commented out in the shipped
   preload file. Booted clean in under 20 seconds.
4. **Confirmed NOT needed, via source reading** (all checked proactively
   before first boot):
   - §4 (lazy security-daemon load / stack-overflow recursion):
     `master.lpc`'s `valid_write`/`valid_read` only ever `find_object()`
     the security daemon, never `load_object()`s it lazily — no
     reentrancy-guard fix needed.
   - §7 (`get_root_uid`/`get_bb_uid`): both already present and correct.
   - §15l (`destruct(SIMUL_EFUN_OB)` in master's `create()`): not present.
   - §8d/§15o (`get_include_path()` / local-header angle-bracket
     includes): `convert_lib.sh`'s existing local-include-to-quotes pass
     (57 files) already neutralizes this whole class unconditionally
     (quotes resolve regardless of VM context), so no master.lpc
     `get_include_path()` addition was needed here.
   - §15n (custom securityd `valid_read` denying "(player)" status
     reads under `/adm`/`/cmds`): this lib's `securityd.lpc` IS a
     genuinely custom ACL (Eastern.Stories-lineage `trusted_read`/
     `exclude_read` tables), but its `exclude_read`/`trusted_read`
     tables never list `"(player)"` at all, and its `valid_read` returns
     `1` early whenever the caller has no resolvable euid (the case for
     essentially every pre-login compile trigger) — so the §15n failure
     mode never manifests here. Confirmed both by reading the source and
     by the clean interactive test (no "Read access denied" anywhere).
   - Nitan-family simul_efun-dbase architecture bug (§15): not present —
     `adm/simul_efun/wizard.lpc` only has `wizhood()`/`wiz_level()`
     helpers, no bare `set`/`query`/`delete`; `feature/dbase.lpc` (F_DBASE,
     widely inherited) implements real local `set`/`query`/`delete`
     methods directly. Correct inherit-based architecture, same as
     `rzrmud`/`xkx2001`.
   - No `named.lpc` daemon exists in this lib at all (grep came up
     empty) — the deep §15h `PATH()`/sliding-window fix doesn't apply.
5. **Two genuine pre-existing typos fixed during the lpcc sweep triage**
   (both matching AGENTS.md's existing "missing quote" catalog shape,
   §10): `d/quanzhen_old/hudi4.lpc`, `hudi5.lpc`, `hudi6.lpc` all had
   `set("long", <bare Chinese text with no opening quote>` (hudi5 was
   missing the closing quote too); `kungfu/skill/qingyi-jian.lpc` had
   `"skill_name" : "大悲式,` (missing closing quote before the comma).
   All 4 fixed and individually re-verified with a targeted `lpcc`
   compile (PASS on all 4 after the fix).

## Interactive test result — full registration flow

No hidden pre-id prompts (no GB/BIG5 gate, no student age-gate). Full
chain read from `logind.lpc`: `logon()` → English id (`get_id`) → confirm
y/n (`confirm_id`) → Chinese name (`get_name`) → "管理密码"/wizpwd (a
secondary backup password, `new_wizpwd`/`confirm_wizpwd`) → real login
password (`new_password`/`confirm_password`) → attribute-gift selection
(`select_gift`/`get_gift`, 0 = system random) → email (`get_email`) →
gender (`get_gender`) → `enter_world()`.

Verified the complete path in **one continuous `mudclient.py` connection**:
- `""` → correctly rejected ("必须是 3 到 10 个英文字母") confirming
  `check_legal_id` is live.
- `qinfeng` → accepted, "确定吗？" prompt.
- `y` → confirms new character, shows the "take a good name" banner.
- **`秦风` (real Chinese name)** → accepted silently, no rejection,
  proceeds straight to "请设定您的管理密码：" — confirms the §15h fix
  works correctly end-to-end, not just at the prompt-rendering level.
- `pass1234` / `pass1234` (wizpwd + confirm) → accepted.
- `pass5678` / `pass5678` (real password + confirm) → accepted, shows
  the attribute-gift explanation banner.
- `0` → system-random gift roll.
- `y` → accepts the rolled gift (膂力/悟性/根骨/身法 all shown).
- `test@test.com` → accepted as email.
- `m` → male gender.
- Character **actually entered the game world**, landing in
  `/d/xingxiu/beijiang` ("北疆小镇" / North Xinjiang Town, one of 4
  configured `start_room`s), saw two NPCs render correctly (维吾尔族妇女
  / Uyghur woman ×2), and `look`/subsequent commands worked normally.
  `CHANNEL_D` broadcast "听说又来了一位叫做秦风的小兄弟" (new-player
  channel announcement) with the correct Chinese name embedded.
- `banned_name` list checked before testing (你/你的/我/我的/自己/屁/他/
  他的/她/她的/它/它的/鬼王/风云/流氓/爸/妈/祖先/祖宗/爷/奶/毛泽东/邓小平/
  江泽民/【/】/马克思/恩格斯/列宁/抄/手淫/老百姓) — "秦风" doesn't match
  any as a substring, confirmed safe.

Some non-fatal `编译时段错误：... warning: Unknown #pragma, ignored`
lines appear in the transcript during first-time lazy compiles of
`inherit/char/char.lpc` and its dependents (the mudlib's own
`error_handler` mislabels compile-time *warnings* as "compile-time
errors" in its Chinese message text) — cosmetic only, does not affect
gameplay; the same pragma warnings appear in the clean boot log too.

## Re-verification pass (QA sweep, later session)

Re-tested the full flow end-to-end this pass (`feature/command.lpc`'s
`command_hook()` confirmed `protected nomask`, not `private` -- §15ae does
not apply). **Found and fixed a real bug**: `adm/obj/master.lpc`'s
`log_error()` showed EVERY compile-time diagnostic to the connected
player unconditionally (§15w), including harmless WARNINGS (`Unknown
#pragma, ignored`, etc) from the first-ever lazy compile of a
never-preloaded room/NPC file -- confirmed live: a fresh registration
showed several spurious `编译时段错误：... warning: ...` lines
interleaved with the real welcome banner. Fixed by gating the
player-facing broadcast on the message NOT containing `"warning:"` (still
logs everything to disk regardless, matching the established fix pattern
used across this project and applied to sibling lib
`xyzxfk` in the same pass). Re-verified with a fresh
registration (`qinruo`/秦若, female) after restarting the driver: **zero**
spurious messages, `look`/`score`/`quit` all correct (correct
female-specific title "芊芊民女", landed in 铁枪庙).

Also noted: `logind.lpc`'s `logon()` has a `uptime() < 30` gate that
rejects ALL logins (with a "游戏正在启动过程中，请稍候再login" message)
for the first 30 seconds after the driver starts -- a genuine, intentional
startup-settling guard, not a bug; just wait past 30s uptime before
attempting to connect after a fresh boot.

Full registration + post-login-command flow now confirmed working with
real Chinese names 秦朔(male, landed in 北疆小镇)/秦若(female, landed in
铁枪庙), `look`/`score`/`quit` all producing correct output, zero
`执行时段错误` in `debug.log` after the fix.

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  13,461 files reformatted, 37 unchanged, 62 refused (self-check
  failures on messy legacy code, expected per the tool's docs).
- **New bug found and fixed during this pass's native re-verification**
  (a sibling of the same bug found in `xyzxfk` in this
  same session): `adm/daemons/logind.lpc`'s `get_resp()`/`get_name()`
  had the same stray, pre-existing debug leftover `printf("%O\n", ob);`
  (2 occurrences) — dumped a raw internal object reference straight to
  the connecting player right after their Chinese name is accepted.
  Removed both; re-verified with a fresh registration (`qinshuoc`/
  秦朔再, male) — no stray object-reference text, `look`/`score`/`quit`
  all still correct.
- **Native re-test against the freshly rebuilt driver**: boots clean,
  zero `FATAL`/`SIGSEGV`/`执行时段错误` in `debug.log`. Full registration
  verified with real Chinese name **秦朔再** (male), reaching the actual
  starting room (北疆小镇), `look`/`score`/`quit` all correct. Reconfirmed
  the pre-existing `uptime() < 30` login gate in `logon()` — logins are
  intentionally rejected for the first 30s after boot; not a bug.
- **WASM build tested**: boots cleanly (only expected non-fatal
  preload warnings, no `sockets` package). Because `fluffos_connect()`
  in the harness happens immediately at boot, the very first connection
  attempt always lands inside the 30s `uptime()` gate and is rejected
  with "游戏正在启动过程中，请稍候再login" — a harness/timing artifact
  of instant-connect, not a real bug (confirmed by a one-off scratch
  variant of the harness that delays `fluffos_connect()` past 30
  real seconds: with that workaround, connection proceeds past the
  uptime gate and then **is** blocked by the documented
  `query_ip_number()` WASM limitation — `logon()`'s
  `BAN_D->is_banned(query_ip_number(ob))` check receives a malformed IP
  string under WASM and rejects the connection with "你的地址在本 MUD
  不受欢迎"). Driver-side WASM gap, not a mudlib bug — not patched.
  Native play is completely unaffected by either the uptime gate (once
  past 30s) or the IP-format issue (native `query_ip_number()` works
  correctly).

## lpcc sweep

13,560 files: **13,364 pass / 196 fail (98.6%)**, after fixing the 4
missing-quote typos above (raw sweep was 13,360/200 before those
fixes). Notable failure categories, triaged but not further pursued:

- **~27 files under `/u/snow/wudujiao/...` and a few under `/u/party/`,
  `/u/fyue/`** (personal wizard scratch/test directories, never
  reached by preload or the documented `start_room` list): fail with
  `Cannot #include globals.h` when reached via a *nested* nested compile
  (e.g. compiling room `bianzhai2` which clones an NPC in `npc/`) but
  fail differently (no visible error text at all, just "Fail to load
  object") when compiled directly as an isolated top-level `lpcc`
  target — suggesting a §15o-shaped VM-context-dependent include
  resolution gap specific to this subtree, though the exact mechanism
  wasn't fully root-caused given it's confined to non-preloaded personal
  wizard content with no bearing on registration or the main game world
  (confirmed: the real boot + full registration test cloned NPCs from
  `/d/xingxiu/npc/` with zero include errors).
- **5 files with `End of file in text block`** (`d/heimuya/{shenggu,tang}`,
  `d/heimuya/npc/tang`, `d/quanzhen_old/{manglin1,manglin2}`): traced to
  a genuine, interesting encoding-conversion edge case — these were
  already in the `LOSSY conversion (invalid bytes dropped)` list from
  `convert_lib.sh`'s encoding pass, and in at least one case (`shenggu.lpc`)
  the root cause was confirmed via `xxd`: the raw archive already had a
  corrupted GBK byte pair immediately before a text block's closing
  `LONG`/`TEXT` delimiter (`c8 2e a3 0a` where a valid character was
  expected), and `iconv -c`'s recovery doesn't just drop the *invalid
  lead byte* — it drops the **entire malformed 2-byte unit it attempted
  to decode, including the ASCII newline that happened to be the second
  byte of that attempted (invalid) pair**. This silently merges the
  text-block's last content line with its closing delimiter line
  (`...奕奕.LONG );` with no newline at all), so the parser never
  recognizes `LONG` as a line-initial closing marker and reads to true
  EOF. **Worth adding to AGENTS.md's existing lossy-conversion note**:
  this is a variant beyond the already-documented `.o` save-file case —
  it can silently eat a newline adjacent to the corrupted byte(s) in
  live *source* files too, specifically breaking `@TEXT`/`@LONG`-style
  heredoc closing delimiters. Not fixed here (5 files, none on the
  preload/registration path, would require guessing/restoring the
  original corrupted archive content) but documented since it's a new
  wrinkle on a previously-seen category.
- **2 orphaned/dead simul_efun fragments** (`adm/obj/simul_efun_bak.lpc`,
  a literal backup copy; `adm/simul_efun/user.lpc`) fail with "Invalid
  simulated efunction override" on their `efun::destruct()` calls (the
  §14 2-arg-`valid_override` gap) — but neither file is `#include`d by
  the real `adm/obj/simul_efun.lpc` (grep confirmed), so both are
  unreachable dead code; not fixed, matches §6b's fragment-file caveat.
- **5 files with `Redeclaration of function 'query_autoload'`**
  (`clone/book/{lbook5,pixie_book}`, `d/obj/quest/{chai,chai1,chai3}`):
  a base class already defines `query_autoload()` and these files
  redundantly redefine it — pre-existing content sloppiness, not a
  driver-compat bug, left as-is (not on the registration path).
- Remainder is the usual long tail of one-off syntax errors, undefined
  variables/functions, and `call_other`-couldn't-find-object noise in
  individual quest/room/skill files scattered across the world tree —
  consistent with every other lib in this batch, not triaged file-by-file
  per AGENTS.md §6b.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban/site gates**
   - `adm/daemons/band.lpc`: added reusable `is_local_ip(string ip)`
     helper (returns 1 for `127.*`, empty/non-string, or any string that
     fails `sscanf("%*d.%*d.%*d.%*d")` — WASM garbage IPs).
   - `band.lpc` `is_banned()` (~L108): short-circuit `return 0` for local
     IPs (this was the WASM login blocker).
   - `band.lpc` `vaild_allow_address()` (~L370): short-circuit `return 1`
     for local IPs.
2. **Uptime startup gate bypassed** — `adm/daemons/logind.lpc` `logon()`
   (~L80): `uptime()<30` destruct gate now `&& !BAN_D->is_local_ip(str)`
   (moved `str = query_ip_number(ob)` above it). Remote connections still
   see the startup-grace gate.
3. **Anti-flood throttles exempt loopback** — `logind.lpc`: `ban_cnt > 3`
   (~L142) and `ip_cnt > 8` (~L227) gates now `&& !BAN_D->is_local_ip(...)`.
   In-game kickout/last_on retention timers left intact (game design).
4. **Admin account seeded** — id `fluffos`, registered through the real
   flow. NOTE: this "风云再起Ⅱ" build's registration requires TWO
   passwords — a 管理密码 (wizpwd) *and* a 普通密码 (login password), and
   forbids them being equal. Set login password (普通密码) = `Mud@2026`
   and 管理密码 = `Adm@2026`. Display name 浮浮, male. Granted `(admin)`
   via `adm/etc/wizlist` (`fluffos (admin)`), read by
   `securityd.lpc::create()`. Verified after restart: score shows
   「您目前权限：(admin)」, `update /adm/daemons/band` recompiled OK,
   `goto` worked. Save files: `work/data/user/f/fluffos.o` and
   `work/data/login/f/fluffos.o` (both untracked, NOT gitignored —
   orchestrator must `git add`).

Retest: fresh registration reached 北疆小镇 as `(player)`; fluffos
re-login `(admin)` + wizard commands OK; `log/debug.log` 0 runtime errors.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一家族（风云再起2）。状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'★ 您目前权限：(admin)'，quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

按 AGENTS.md §10.7 流程做的第一轮完整交互式游玩测试。这份档案自己
的 README 已经确认与 `xyzxfk`（疯狂江湖，本 session 上一轮刚做过
§10.7 深挖的手足档案）共享部分底层"夕阳再现"引擎文件（`d/city/
sj.lpc` 逐字节相同），但登录/安全/世界内容各自独立开发——开机前直
接把上一轮在 `xyzxfk` 上新发现的两个严重 bug 拿来对照本档案的实际
源码，两个全部命中（细节见下）。WASM 本轮仍被跳过验证：emsdk 安装
器把工具链下载硬编码到 `storage.googleapis.com`，本 session 的出站
代理策略拒绝该域名（`curl -sS $HTTPS_PROXY/__agentproxy/status` 确
认为 403），未重试；这份档案自己 NOTES.md 里之前的 WASM 相关记录
（`uptime()<30` 启动门禁、`query_ip_number()` 驱动限制）仍然有效，
本轮只是没有重新验证这次新修的 bug 在 WASM 下同样生效。

**开机前主动核对手足档案 `xyzxfk` 新发现的 bug：**

1. **AGENTS.md §7.11（已确认第 N 例，含注册路径 + 死亡路径两处）**——
   `adm/simul_efun/file.lpc` 的 `log_file()` 和 `xyzxfk` 修复前逐字
   节相同的形状：裸 `write_file(LOG_DIR + file, text)`，同一文件里
   现成的 `assure_file()` 辅助函数从未被调用。`adm/daemons/
   logind.lpc` 的 `get_gender()`（注册流程最后一步，紧接着调用
   `enter_world()`）里同样有 `log_file("login/newid.log", ...)`，而
   `work/log/login/` 目录在这份 `work/` 树里同样不存在——这意味着
   **每一个新角色的注册流程本身就是坏的**，和 `xyzxfk` 一模一样的
   崩溃形状。修复：在 `log_file()` 内部加一行 `assure_file(LOG_DIR
   + file)`（`assure_file` 原本定义在 `log_file` 后面，这个编译器
   要求同文件内被调用的函数需要先声明/定义，顺手把两个函数的顺序
   对调了，和 `xyzxfk`/`jqxz2015` 遇到的完全相同的编译器限制）。
   `adm/daemons/combatd.lpc` 里也有一处独立的、不经过 `log_file()`
   的裸 `write_file("/log/nosave/KILL_PLAYER", ...)`——这一处比
   `xyzxfk` 的版本条件更窄（包在 `if (userp(killer))` 里，只有"玩家
   杀死玩家"才会触发，不像 `xyzxfk` 那样任何死亡都会触发），本档案
   README 明确写了"本MUD不禁止玩家之间的PK"，这是真实会被触碰到的
   路径，一并加了 `assure_file(...)`。顺手排查了同一目录类别下的其
   余 `write_file("/log/...", ...)` 直接调用点，全部补上
   `assure_file(...)`：`cmds/{arch,adm}/shutdown.lpc`、`cmds/arch/
   reboot.lpc`（各一处 `/log/nosave/LASTCRASH`，`arch`/`adm` 两份
   `shutdown.lpc`/`restoredata.lpc` 逐字节相同，两份都改了）、
   `cmds/{arch,adm}/restoredata.lpc`（`/log/nosave/RESTORE_PLAYER`）、
   `cmds/usr/helpbbs.lpc`（`/log/doc/register/<id>`）。
2. **AGENTS.md §8.9（已确认第 N 例）**——`adm/daemons/logind.lpc`
   `enter_world()` 食物/饮水初始化判断 `if (ob->query("age") == 14)`
   用的是登录桩对象 `ob` 而不是玩家本体 `user`，和 `xyzxfk`/三个
   "夕阳再现" 手足档案（`jhfy`/`wmkj`/`bixiecanyang`）确认过的形状
   完全一致。改成 `user->query("age") == 14`。
3. **AGENTS.md §7.94（新增，`xyzxfk` 那一轮命中）——本档案检查后确
   认不适用**：`cmds/usr/inventory.lpc`（以及一份 `inventory2.lpc`）
   都以正常文件名存在，`i` 指令实测正常工作，没有 `xyzxfk` 那种"只
   剩非标准扩展名备份文件"的缺失情况。
4. **AGENTS.md §7.34（printf 调试残留）——本档案自己此前已经修
   过**：读代码确认 `logind.lpc` 的 `get_resp()`/`get_name()` 没有
   `printf("%O\n", ob)` 残留，本轮实测注册流程也没有泄漏对象引用，
   未重复修改。

**测试路径**：读 `doc/help/newbie` 确认 `kill`/`hit`/`fight` 均可用
于练级后，在原生驱动下一次连续会话里：注册（真实中文名 沈知远，id
`xyzfydeep`，随机天赋，需要设置"管理密码"+"普通密码"两组独立密
码）→ 完整 MOTD/权限横幅显示、落地"铁枪庙"（bug 1 注册路径的修复
验证：修复前会卡死在裸提示符，`look`/`score`/`help` 全部返回默认
的"什么？"）→ `score`/`i` 确认食物/饮水满格（§8.9 修复验证）、`i`
正常工作 → `kill wuya` 攻击庙前的乌鸦，多回合拳脚攻防正常，组织性
学会"基本拳脚"，最终被乌鸦击杀，死亡讯息只出现一次、`debug.log`
全程零新增错误（NPC 击杀不经过 `KILL_PLAYER` 那一条 `userp(killer)`
门槛，但确认了死亡/复活整条流程本身干净，`combatd.lpc` 里唯一那处
`write_file` 已通过代码核对方式确认修复到位——见下方"未验证"部分）
→ 死亡 → 鬼门关 → 白无常判词全套自动走完 → 送回"武庙" → 门派加入：
拜访"忆香亭"红花会总舵主陈家洛，`apprentice` 正确按代码里的正气门
槛（`shen >= 50000`）拒绝（合理设计，和 `xyzxfk` 完全一致，未强行
绕过）→ 改用管理员 `setskill xyzfydeep sword 50` 验证捷径路径（此
引擎家族同样没有专门的 `setskill`/`setparty` 类快捷指令外的门派赋
予手段，`setskill.lpc` 存在 `cmds/{adm,arch}` 两份逐字节相同的拷
贝，均正确操作 `ob` 而非 `me`，未发现 sjtx2 那类 `me`/`ob` 错位
bug）→ `skills` 确认组织性的 `dodge`/`unarmed` 和捷径赋予的
`sword`（50 级）同时存在 → `quit` → `debug.log` 检查（零新增错误）
→ 断线重连：这份档案的 `logind.lpc` 有一个 120 秒的"刚退出游戏，为
了减轻系统负担请过一会再连入"防洪门禁（`time() - ob->query
("last_on") < 120`，独立于 §1.3e 已归档的 kickout 30 分钟惩罚门
禁，同属合理的游戏设计，未做任何改动），第一次重连在门禁窗口内被
正确拒绝，等待真实的 120+ 秒后重连成功，`skills`/`score` 确认门
派归属（未加入，符合预期）、组织性+捷径两条技能、死亡次数全部正确
持久化。

**测试角色**：id `xyzfydeep`，中文名 沈知远，普通密码
`Xfy2026Deep`，管理密码 `Adm2026xfy`，普通百姓（未入门派，
`apprentice` 门槛未达到），技能 dodge/unarmed（组织性）+ sword（捷
径路径，50 级），死亡 1 次，位于武庙（REVIVE_ROOM）。存档：
`work/data/{login,user}/x/xyzfydeep.o`。管理员账号 `fluffos` 存档
产生了正常的 food/water/mud_age/startroom 增量（无损坏，
`setskill.lpc` 全程正确操作 `ob` 而非 `me`），按这份档案自己既有
NOTES 里"必须提交，不受 gitignore"的约定一并提交；
`adm/daemons/maxonline`（本轮测试期间因驱动重启被意外改写为较低的
同时在线人数峰值）已用 `git restore` 还原到测试前的真实历史峰值。

**验证通过**：真实中文名注册（含两组独立密码，修复后）；
`look`/`score`/`i` 多次状态检查；食物/饮水初始化（§8.9）；`kill`
战斗与死亡→复活完整循环；组织性技能学习；管理员捷径路径
`setskill`；门派加入的正气门槛正确生效（未绕过）；`quit` 后
debug.log 检查；120 秒防洪门禁内重连正确拒绝、门禁过后重连正确成
功，全部状态正确持久化。

**明确未验证**（记录而非静默跳过）：`combatd.lpc` 里 `userp(killer)`
门槛保护的 `KILL_PLAYER` 写入路径（真实玩家对战玩家的击杀）未通过
实机 PK 复现——构造一次真正的玩家对玩家击杀需要两个同时在线的真实
角色，超出本轮时间预算；这一处的修复只通过代码核对（和已验证过的
`log_file()` 通用修复、以及本轮已验证的 NPC 击杀死亡流程都用的是
同一个 `assure_file()` 防护模式）确认，不是独立实机复现的。`cmds/
{arch,adm}/{shutdown,restoredata}.lpc`/`cmds/usr/helpbbs.lpc` 四组
新加的 `assure_file()` 防护同理（管理员专用或低频功能，未逐一实机
复现）。商店购买（本轮未探索到商店所在区域）。WASM 下的重新验证
（详见上方说明，proxy 阻断）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。核对上面记录的所有修复（§7.11
`log_file()` 及其覆盖的注册/死亡路径、`log_error()` severity 判
断）逐项确认代码仍然生效；`win_times` 的 `%`-operator 也已用
`to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:146`）；
`feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。管
理员 `fluffos`/`Mud@2026` 真实重连验证两次：`score` 显示食物/饮水
满格，`debug.log` 全程干净。驱动按精确 PID 结束；测试期间产生的存
档增量（纯游戏时间计数器）已 `git checkout --` 还原，本轮无需新代
码改动。

## AGENTS.md §7.100 修复（2026-08-19）

同 `jhfy3` 起源发现的 `ROOM` 基类冗余 `replace_program(ROOM);` 自崩
溃地雷（详见 AGENTS.md §7.100）：本 lib 5239 个房间文件的 `create()`
末尾（紧跟 `inherit ROOM;`）都有这一行多余调用，第一次对该房间对象
绑定闭包（`set(..., (: ... :))`、`edit()`、`call_out()` 闭包参数等）
会永久失败。同款地雷还烤进了自带建房工具
`clone/misc/roommaker.lpc`/`u/fyue/misc/roommaker.lpc` 的两处代码生
成模板（heredoc 与字符串拼接各一处），意味着玩家/巫师用建房工具新
建的房间也会天生带着这个地雷。

修复：脚本化删除所有 5239 个房间文件里独立成行的
`replace_program(ROOM);`，加上两份 roommaker 工具模板里各自手动摘
除字符串拼接里的 `\treplace_program(ROOM);\n` 片段，保留
`inherit`/`setup()` 不变。`git diff --stat`：5241 files changed, 2
insertions(+), 5243 deletions(-)，与脚本自报删除行数（5241 处标准
行）+ 2 处手动摘除（roommaker 字符串拼接）精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40041 正常监听，
`debug.log` 全程干净（无新增编译错误/警告）；管理员 `fluffos`账号
`goto` 走访 14 个刚修复的房间（`d/binghuodao`/`d/quanzhen_old`/
`d/taishan`/`d/baituo`/`d/migong`/`d/gaochang` 等区域），`look`/
`goto` 均正常返回，无 "cannot replace"/"cannot bind" 新增日志行。
按精确 PID 结束驱动，登录产生的两处存档增量（`fluffos.o` 登录/用户
档案）已 `git checkout --` 还原。

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

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了重连，没测商店和拜师。本轮用既有
`fluffos`/`Mud@2026`（中文名「浮浮」，男性，无门派）。

- **登录**：落地 `/d/honghua/yixiangting` 忆香亭（红花会陈家洛）。
  无巫师效验码额外一步。
- **商店**：`goto /d/city/zuixianlou`，`npc/xiaoer2` `list` 列出烤
  鸡腿 80 文 / 牛皮酒袋一两白银 / 包子 50 文。无现金时 `buy jitui`
  正确拒绝。`clone /clone/money/gold` 后再买成功（烤鸡腿 + 找零
  99 两白银 + 20 个铜板）。
- **拜师**：`goto /d/gaibang/inhole`，`apprentice zuo`（左全）一次
  完成 →「恭喜您成为丐帮的第二十代弟子」。`score`「丐帮第二十代
  弟子」、「你的师父是左全」。
- **重连**：同手足 `xyzx`，`last_on` 120 秒冷却。等满后重连仍在
  树洞内部，称谓/师傅/银钱均在；烤鸡腿未随存档回来。
- **日志**：live `debug.log` 是 `libs/xyzxfy2/log/debug.log`
  （Boot Time Thu Sep 3 21:41:53 2026）。无 `error:`。mudlib
  `work/log/debug.log` mtime 仍是 2026-08-19（无新捕获运行时错误）。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 3 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 1 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen_old/manglin1.lpc`, `d/quanzhen_old/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xyzxfy2`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 2 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 0 PASS -> 2 PASS, 0 that loaded before fail now, 2 more load.

1 files moved (1 `.C`); mostly under `d/city/npc` (1). A rescan with `scripts/lpc_warnings.py xyzxfy2` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`u/fyue/questd.lpc` 在新进程里加载，HEAD 通过 2 个、工作树通过 2 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xyzxfy2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 528 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：472 -> 472 通过，无回退；改过的头文件的 39 个包含者 39 -> 39 通过。启动时警告 8 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、1 处去后缀（如 `cmds/imm/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 63 个文件，HEAD 与工作树各载入一次无回退（63 objects; HEAD PASS 53, tree PASS 53; regress 0; newly loading 0），这些文件的警告 67 -> 0。

## 编译警告收尾（2026-10-12）

孪生库 bixiecanyang 同日的整理（7c2dd97d9a6：冗余继承 8 处，`u/isle/ToMud/tomud.h` 沙盒副本的 `TMI`/`TMA`/`TMB` 前 `#undef`，`kungfu/skill/huashan-jian.lpc` 多余的 `;`）用 `scripts/lpc_twin_port.py adopt bixiecanyang xyzxfy2 --pre 7c2dd97d9a6~1` 搬来，10 个文件与 bixiecanyang 修前逐 token 相同，清单里的警告全部落在这些文件里。HEAD 与工作树各载入一次：10 个对象，HEAD PASS 7，tree PASS 7，regress 0。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。9 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 8 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。


## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen_old/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、10 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/obj/weapon/blade`、`/d/gumu/obj/fuchen`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 4 个（4 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory2.lpc`、`feature/move.lpc`、`feature/move2.lpc`、`feature/复件 move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（9 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 27 处、25 个文件：`kunlun-shnfa`→`kunlun-shenfa`（4 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`shaolin-shnfa`→`shaolin-shenfa`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 2 处：`/clone/book/lbook5.lpc` 的 `query_autoload()`、`/clone/book/pixie_book.lpc` 的 `query_autoload()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city3/jiulou2/obj/food.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/allow-letter.lpc`、`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`、`/d/quanzhen_old/obj/hanzhu.lpc`、`/d/quanzhen_old/obj/shenmu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 5 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（jhfy3）、`/kungfu/skill/huang.lpc`（bixiecanyang）、`/quest/murong/qlist3.lpc`（bixiecanyang）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/kunlun-zhang.lpc`。修后与 HEAD 逐个对比载入：这 5 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（3 个文件）：`/cmds/adm/recover1.lpc`、`/cmds/arch/blockade.lpc`、`/cmds/arch/recover1.lpc`。

## `obj.h.es2`：`blockade` / `recover` 包含的头文件档案里没有（2026-10-21，KB 04 §6.23）

`blockade.lpc`、`recover*.lpc` `#include <obj.h.es2>`（`OBJ_*`、`NPC_*` 路径的 ES2 头文件，hy5、xkx100 等 33 个库带着），本库的 include 目录没有它，这些指令从来编译不了（`Cannot #include obj.h.es2`），`data/keep` 的修补也无从生效。指令本身不用里面的宏；从同系的 xkx100 复制一份头文件，加载检查 HEAD 与工作树对照：3 个对象原来加载失败，现在通过，没有退步。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 32 条注册（32 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/qinhuang/shidao5.lpc`（`do_train`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/npc/m_weapon/npc/jia.lpc`（`do_levelup`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`） 等共 32 个文件。最多的函数名：`do_send` 15 处、`do_decide` 7 处、`do_train` 2 处、`do_sell` 2 处、`do_jump` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 2 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）；`/adm/daemons/natured.lpc` ← chidi：`outdoor_room_outcolor()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 22 个文件里有 31 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/KILL_PLAYER`、`nosave/security`、`nosave/CRASHES` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 19 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 19 处（14 个文件）：拼名字的赋值 11 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:108`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：10 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 10 处（5 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）；`if ((strlen(name) < 4) || (strlen(name) > 30)) {`（`/cmds/usr/found.lpc:73`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 6 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 4 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 巫师区出口 faceoff / rence / niulang / yihua（2026-10-23，KB 06 §7.372）

`/u/f/faceoff/`、`/u/r/rence/`、`/u/onskyer/niulang/`、`/u/skinys/yihua/` 对应区域已在 `/open/world1/faceoff/bird/`、`/open/prayer/`、`/d/niulang/`、`/d/yihua/`。`scripts/lpc_fix_wizard_area_exits.py` 在目标存在时改写，仍缺失的出口行删除。本库 1 处。证明：dreamofseven wood5 四向可加载；xlqy_new2007 天河东西向 niulang；kxkj kitchen7 → prayer。


## hanbing `random 反引号（2026-10-27，KB 04 §6.25 Also）

`hanbing-mianzhang` / `hanbing-mianzhang2` 在 `random(` 前多了一个反引号，驱动按模板字面量读到 EOF。删掉。证明：HEAD 失败；改后加载。
