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
