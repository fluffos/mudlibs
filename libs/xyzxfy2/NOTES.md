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
