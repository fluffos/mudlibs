# xyzx3 — 夕阳再现III之炎龙封印

Archive: `夕阳再线III之炎龙封印.rar`. Port: 40042. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name, character entered the actual game world).

## What this is

"夕阳再现III" ("Sunset Reappears III: Seal of the Flame Dragon"), by
AKAI Studio (阿凯工作室, http://akai.isme.net/), copyright 2006. `adm/obj/`
layout (`master file : /adm/obj/master`, `simulated efun file :
/adm/obj/simul_efun`), MudOS 0.9.20-era config. The mudlib root was
nested two directories deep plus a `world/` subdirectory inside the
archive (`raw/夕阳再现III/夕阳再现III/world/`) — confirmed via
`config.xyzx`'s own `mudlib directory : ./world` setting, relative to
the config file one level up. ~9,360 raw files, 8,302 after the
`.c`→`.lpc` rename.

`chinese.c`'s `is_chinese` was byte-identical to `tianxiawuxue`
(archive #51, processed in parallel by a sibling agent this same
session) — same standard single-first-character GBK-byte-range shape,
suggesting shared lineage or a common code pool, though this wasn't
otherwise investigated deeper (not depended on).

## Fixes applied

1. **AGENTS.md §15h**, standard shape, applied proactively per the
   assignment brief:
   - `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte check
     (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK codepoint check
     (`str[0] >= 0x4e00 && str[0] <= 0x9fff`, `strlen>=1`).
   - `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
     `< 2 || > 10` → character-count bound `< 1 || > 5`; removed the
     `i%2==0 &&` even-byte-offset gate so every character position is
     checked.
2. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. No other preloaded daemon does synchronous socket setup
   (checked every preload entry for `socket_create`/`socket_bind`/
   `resolve()`; only files under `adm/daemons/network/` — none of which
   besides `dns_master` are preloaded — reference sockets at all).
3. **Confirmed NOT needed, via source reading**: `master.lpc`'s
   `valid_write`/`valid_read` only `find_object(SECURITY_D)` (no lazy
   `load_object`, so no §4 recursion risk); no `destruct()` on
   `SIMUL_EFUN_OB`/`MASTER_OB` in `create()` (no §15l crash risk);
   `get_root_uid()`/`get_bb_uid()` both present (no §7 gap); no
   `named.c` daemon exists in this lib at all; `securityd.c`'s
   `valid_read` is a bare `return 1;` (no §15n custom-ACL gap, no §8c
   `this_player()`-override footgun).
4. **NEW finding — missing `WQA_ROOM` macro, 81-file cascade**:
   `include/globals.h` never defined `WQA_ROOM`, despite 81 files across
   `quest/game/` doing `inherit WQA_ROOM;` — confirmed genuinely absent
   in the raw archive too (not a conversion artifact). The intended
   target, `/quest/game/wqa_room.c` (a lottery/"官运亨通" quest-room base
   class), does exist on disk, just never had its macro defined anywhere.
   Fix: added `#define WQA_ROOM "/quest/game/wqa_room"` to `globals.h`
   next to the other `ROOM`-family macros. This single-line fix resolved
   81 of the lpcc sweep's original 230 failures in one shot (matches
   AGENTS.md §8g's "one shared dependency, not N independent bugs"
   pattern, just via a missing `#define` rather than a broken shared
   file).
5. **NEW finding — `iconv -c`'s lossy-byte-drop can eat an adjacent
   legitimate newline, not just the genuinely invalid byte(s)**: three
   files (`d/heimuya/tang.c`, `d/heimuya/shenggu.c`, `d/heimuya/npc/tang.c`)
   were flagged by `convert_lib.sh` as "LOSSY conversion (invalid bytes
   dropped)". Root-caused via raw hex inspection: each file has a
   genuinely corrupt GBK byte sequence in the ORIGINAL archive right at
   the boundary between the room's `@LONG ... LONG` heredoc body and its
   closing `LONG` tag — two consecutive illegal GBK lead-byte fragments,
   the second of which unluckily consumes the very newline that
   separated the Chinese description text from the closing tag. With
   `iconv -c`, both illegal pairs get silently dropped, merging what were
   two lines into one (`...奕奕.LONG );` instead of `...奕奕.\nLONG );`),
   which breaks the heredoc parser (`error: End of file in text block`)
   since FluffOS requires the closing identifier alone on its own line.
   Two more files (`d/quanzhen/manglin1.c`, `manglin2.c`) had the exact
   same "closing tag glued onto the last text line" shape but WITHOUT
   any accompanying lossy-byte-drop warning — i.e. this exact authoring
   mistake (or one indistinguishable from it) also occurs as a genuine
   pre-existing typo, independent of the lossy-conversion mechanism.
   **Fix, all 5 files**: inserted the missing newline before the closing
   `LONG` tag. **Worth adding to AGENTS.md's encoding section**: any file
   flagged lossy AND using a `@TEXT...TEXT`-style heredoc is worth a
   quick manual check that the closing tag is still on its own line —
   the `-c` fallback's byte-drop isn't guaranteed to be "just" the
   invalid byte(s), it can eat a legitimate adjacent byte (here, a `\n`)
   too when two illegal sequences abut a real character.
6. **Pre-existing typos, unrelated to conversion** (confirmed present in
   the raw archive by direct byte inspection before fixing):
   - `kungfu/skill/hanbing-mianzhang2.lpc`: a stray backtick before
     `random(...)` inside `apply_condition(...)` turned the rest of the
     file into an unterminated "template literal" (`error: End of file
     in template literal`). Removed the backtick.
   - `kungfu/skill/iceforce/chillgaze.lpc`: an `if(...)  return
     notify_fail(...);` single-statement guard was immediately followed
     by a stray extra `}`, silently closing the function early and
     leaving the rest of the body as invalid top-level statements
     (`skill`/`damage` used without declaration, `->` arrow at file
     scope). Fix: removed the stray `}` and added the missing `int
     skill, damage;` declaration (the file already had an unused,
     seemingly-leftover `object *ob;` declaration hinting the original
     declaration line had been damaged/replaced at some point).
   - `d/city2/npc/zhengmen.lpc`: `valid_leave()` was missing its final
     two closing braces (confirmed via brace-depth counting — file ends
     at depth 2, needs to return to 0). Added the two missing `}`.
   - `kungfu/skill/guxing-sword.lpc` and `quest/baituo/qlist3.lpc`
     (twice): classic §10 missing-closing-quote-before-concatenation /
     missing-comma-in-array-literal typos. Fixed each.
7. **Documented, not fixed — pre-existing severe corruption, out of
   scope for a quick fix**:
   - `feature/vendor_sale.lpc` (inherited by 21 shop-NPC files): from
     roughly the halfway point of the file onward, virtually every
     statement is missing its terminating `;` and/or closing `)`/`{`
     (confirmed byte-identical to the raw archive — not something our
     pipeline introduced). This is far beyond a single-token typo;
     reconstructing correct intent for ~180 lines of shop/deposit/
     price-setting logic was judged not worth the time for one feature
     file not on the boot/registration path. Never reached during the
     verified boot+registration+room-entry test.
   - `d/city/sj.lpc` (a "jump off the summit" easter-egg room): every
     string literal argument in `do_out()`/`look_out()` is missing its
     quotes entirely (`message_vision($N大喊...\n, me)` instead of
     `message_vision("$N大喊...\n", me)`, `me` is also never assigned
     `this_player()`), confirmed identical in the raw archive. Same
     "not worth reconstructing intent for a non-critical isolated room"
     call as `vendor_sale.lpc` above.
   - `quest/mmid/*` (9 `qlistNNNN.lpc` files): all `#include "query.h"`,
     but no `query.h` exists anywhere in that directory (confirmed
     genuinely absent from the raw archive; a sibling directory,
     `quest/upr/`, has its own copy defining a generic `query_quest()`
     helper). A real content gap (AGENTS.md §13), not fabricated.
   - `clone/weapon/panguanbi.lpc` inherits a `PEN` macro that's never
     defined anywhere and has no corresponding base-class file on disk
     at all (unlike `WQA_ROOM` above, there's nothing to point the
     macro at) — one missing weapon subtype, a genuine content gap.
   - `adm/daemons/network/*` (userid, telnetd, pingd, pingtcp, ms,
     netmail, mail_serv, inetd, ...): the whole intermud/DNS network
     daemon family has several missing headers (`uid.h`, `mailer.h`,
     `daemons.h`, `config.h`) and simul_efun-override errors. None of
     these are preloaded (only `dns_master` was, and that's now
     excluded per §15p) — pure dead/unreachable code in this
     environment, matching the standing policy of not chasing this
     daemon family.
   - `/adm/obj/simul_efun_bak.lpc` and `/adm/simul_efun/file.lpc`: the
     former is a stray `.bak` copy caught by the blanket rename (§12-
     style, never loaded); the latter is a `#include`-only fragment of
     `simul_efun.lpc` (confirmed via grep) that only fails standalone
     under `lpcc` because `efun::ed/cp/rm` overrides are file-identity-
     sensitive — the classic §6b/§14 false-positive shape. Real boot
     loaded `simul_efun.lpc` (which `#include`s this fragment) with zero
     errors.
   - `d/city2/npc/liling2.lpc` and `d/city2/npc/zhengmen.lpc` (post-
     brace-fix): both still report a bare `Fail to load object` from
     `lpcc` with **no accompanying error/warning text at all** even
     after removing the eval-cost-limit noise (see next item) — tried
     re-running standalone multiple times, checked brace/paren balance
     (both balanced), found no lead. Neither object is preloaded or
     touched by the verified boot+registration+room-entry test; treated
     as an unexplained `lpcc`-only artifact per §6b rather than chased
     further given the two rounds of investigation already spent.

## Config tuning

Bumped `maximum evaluation cost` from the raw config's `400000` to
`5000000`, matching what's now the de facto standard across this
project's recent libs (`xianlvqiyuan`, `xlqyzdb`,
`xjcq2000`, `xkxz2`, `xiakexing100`, `shujian2008`,
`zhonghua2` all already use `5000000`). Confirmed this actually matters
here: `d/city2/npc/liling2.lpc` spuriously failed under the raw
`400000`-microsecond real-time budget (`Eval interrupted: ... cost
limit reached, limit: 400000 usec`) purely from compiling its own
(large, 1500+ line) inheritance chain, with zero relation to any real
bug — after bumping to `5000000` that specific "Eval interrupted"
message disappeared (the file still fails for the separate,
unexplained reason noted above, but the eval-cost false-positive itself
is gone). Worth flagging generally: **any lib whose original config
still has a low `maximum evaluation cost` should get this bump
proactively**, since this driver interprets the value as literal
real-time microseconds (`vm/internal/eval_limit.cc`), not an
instruction-count budget the way classic MudOS did — a value tuned for
the old semantics can be far too tight now.

## Interactive test result — full registration flow

Read `logind.lpc`'s actual `logon()`/`get_id`/`get_id1`/`confirm_id`/
`get_name` chain before testing (not assumed). **Hidden pre-id gate
found**: the very first prompt is captioned "请输入您的英文名字:" ("please
enter your English name") but the first `input_to` callback (`get_id`)
actually checks the literal string against a hardcoded client-protocol
version code, `"2060"` — rejecting anything else with "你的客户端非
Tomud或者非笑傲江湖WWW客户端" and disconnecting. Only after receiving
exactly `"2060"` does it advance to `get_id1`, which validates the real
English id (`check_legal_id`: lowercase letters only, length 3-14). A
failed `check_legal_id` loops back to `get_id` (i.e. the `"2060"` gate
must be re-satisfied on every retry, not just once) — a subtlety that
produced a confusing false rejection ("你的客户端非Tomud...") on a first
test attempt using an id containing a digit, until re-read carefully.

Verified the complete flow in one continuous connection:
`"2060"` → `qinfengwu` (English id) → confirm `y` → **real Chinese name
`秦风五`** (accepted — no rejection, no political/banned-name hit;
`banned_name` here includes politically-sensitive names like 毛泽东/
邓小平/江泽民 plus a few generic pronouns/profanity, not novel-character
names) → password `abc12345` (twice) → gift selection `0` (random) →
confirm `y` → email → gender `m` → **entered the actual game world**
(room "铁枪庙" near 嘉兴), `look` rendered a full room description with
NPCs, `quit` exited gracefully with "欢迎下次再来！". No crashes, no
mangled text, no unexpected disconnects anywhere in the chain.

## lpcc sweep

8,302 files, 8,161 pass / 141 fail (**98.3%**) after all fixes above.
Memory stayed healthy throughout every sweep run (multiple sibling
agents' lpcc sweeps were running concurrently on this host at various
points; free memory dipped to a low of ~16GB free out of 23GB total at
worst, never remotely close to the kill threshold).

Remaining failure categories (all triaged, none individually chased
further — see "Documented, not fixed" above for the ones with a clear
story): 9× "Cannot #include query.h" (quest/mmid content gap), 9×
"Invalid simulated efunction override" + assorted "Cannot #include
uid.h/mailer.h/daemons.h/config.h" (dead intermud network-daemon code,
unreachable), ~21 files cascading from `vendor_sale.lpc`'s pre-existing
corruption, plus a long tail of one-off "Undefined variable/function"
hits in individual quest/skill files not reached by the verified boot
path.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (8302 files): 8215
  reformatted, 33 already-clean/unchanged, 54 self-checked errors
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿六") — remembered the `"2060"` client-version gate must
  be re-sent after *every* `get_id1` rejection, not just once (bit by
  this exact subtlety on a first retry using an id containing a digit,
  exactly as this file already warned) — `"2060"` → English id (pure
  letters) → confirm `y` → Chinese name → password ×2 → gift `0` →
  confirm `y` → email → gender → entered the real game world
  (`北疆小镇`); `look`/`score`/`quit` all produced correct Chinese
  output, `log/debug.log` clean of real errors. Reformat + new driver
  build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly (no fatal preload errors; this lib's `dns_master` is already
  excluded from preload per an earlier fix, so no `socket_*`
  undefined-function noise either). Registration proceeds correctly
  through the `"2060"` gate and the English-name prompt, but is then
  **rejected by `BAN_D->is_banned(query_ip_number(ob))`** in
  `logind.lpc` ("你的地址在本 MUD 不受欢迎。") — this is the documented
  `query_ip_number()` WASM limitation exactly as described in
  AGENTS.md/`docs/build-wasm.md` (same shape as `bxsj`'s
  `adm/daemons/sited.lpc`): the welcome banner's own IP line already
  shows blank instead of `127.0.0.1` under this WASM build, and
  `BAN_D`'s ban-list lookup on that malformed value spuriously matches
  as banned. **Not a mudlib bug** — not patched, per this pass's
  instructions. Verdict: boots under WASM, registration reaches the
  English-name step, but login is gated by the known IP-format
  limitation before a Chinese name can even be entered.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, or an empty/non-string/malformed IP
(covers older WASM `query_ip_number()` garbage). Gates patched:

- `adm/daemons/band.lpc::is_banned()` (~line 108): loopback short-circuit
  `return 0` at the top; ALSO changed the malformed-IP branch
  (`sscanf(site, "%s.%s.%s.%s") != 4`) from `return 1` (banned!) to
  `return 0` — this was the exact gate that spuriously rejected every
  WASM connection ("你的地址在本 MUD 不受欢迎", see the earlier WASM
  verdict above, now obsolete).
- `adm/daemons/band.lpc::vaild_allow_address()` (~line 361): loopback
  connections now always pass the per-account allowed-address check.
- `adm/daemons/logind.lpc::get_id1()` (~line 219): the per-IP connection
  cap (`ip_cnt > 18` destruct) is now loopback-exempt.
- No `uptime()` startup-grace gate in this lib (the only non-cosmetic
  `uptime()` use is `natured.lpc:368`, a 2-day in-game world-event timer
  — game content, kept per policy).
- The `"2060"` client-version gate is NOT an IP/hosting gate (it is a
  documented flow quirk) — left as is.

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (`2060` → id → `y` → Chinese name → password x2 →
gift `0` → `y` → email → gender m). Granted `(admin)` by appending
`fluffos (admin)` to `/adm/etc/wizlist` (read by
`securityd.lpc::create()`). Verified after reboot: login as fluffos →
`update /adm/daemons/logind` → "重新编译 ...成功！" (and the account now
re-logs into the wizard start room 北疆小镇).

Retest: fresh normal registration (`qfxyzx` / 秦风) re-verified
end-to-end into 客店 with `look`/`score`/`quit` correct; test saves
removed. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths tracked, not
gitignored):
- `libs/xyzx3/work/data/user/f/fluffos.o`
- `libs/xyzx3/work/data/login/f/fluffos.o`

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：需要 Tomud '2060' 客户端版本握手作为第一行（和 xajhzcjh 同一家族的模式）——已现场确认：2060→id→密码→'★ 您目前权限：(admin)'，quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

先读 `README.md`/`group_note` 已知：本档案虽带"夕阳再现"招牌，但地图血统实
为"天涯"家族（与 `xysylmhb`/`xyzxiiylzymh`/`yzxiiizylfy` 同源），不是真正
的"夕阳再现"世系（`xyzxfk`/`xyzxfy2` 那支）——品牌名不可靠，本轮以
`d/city/sj.lpc` 字节比对方式独立确认过，细节见 README。同为 AGENTS.md §11
"XYZX/炎龙封印分支"（`xyzx3`/`ylfyxa3`/`longyunmeng`）的另一已深测同门是
`longyunmeng`；对照读过它的 §10.7 记录作为路线图，但两者代码已明显分叉（见
下方"分支不完全同源"一节）。

登陆需要先发送隐藏的 Tomud/笑傲江湖 WWW 客户端版本暗号 `"2060"` 作为连接后
第一行输入（`logind.lpc::get_id()`），随后才是正常的英文 id 流程；输错或漏
发直接被断线，这是本档案自己的合法握手机制，不是缺陷。

### 修复的程序性 bug

1. **§7.11（`log_file()` 未确保目录存在，注册必崩）**：`adm/simul_efun/
   file.lpc` 的 `log_file()` 直接 `write_file(LOG_DIR + file, text)`，
   `/log/login/`、`/log/nosave/` 在 `work/` 里并不存在；`logind.lpc::
   get_gender()` 在 `init_new_player()`/`enter_world()` 前调用
   `log_file("login/newid.log", ...)`，本会导致每次新注册崩溃。按本 session
   已确立的修法：把 `assure_file()` 挪到 `log_file()` 之前（本驱动的编译器
   要求同文件内被调函数需先声明/定义），并让 `log_file()` 内部先调用
   `assure_file(LOG_DIR + file)`。一次修复覆盖全档案所有 `log_file()`
   调用点。本回合是本 session 内本类 bug 第 4 次连续命中（继 jqxz2015→
   xyzxfk→xyzxfy2 之后），且跨越了互不相关的世系（ES II 系 / 夕阳再现真系 /
   本档案的天涯系），说明这个"忘记 `assure_file()`"的 `log_file()` 写法在
   这一代中文 MudOS 代码库里几乎是通病，与"血统"无关。
   另外 4 处同类隐患一并修：`adm/daemons/combatd.lpc`（PK 死亡记录
   `KILL_PLAYER`，本档案允许玩家间 PK，此路径可达）、`cmds/adm/
   shutdown.lpc`/`reboot.lpc`（`LASTCRASH`）、`cmds/adm/restoredata.lpc`
   （`RESTORE_PLAYER`）、`cmds/usr/helpbbs.lpc`（留言注册日志）——均加
   `assure_file()`。
2. **§8.9（食物/饮水初始化检查错对象）**：`logind.lpc::enter_world()` 用
   `ob->query("age")`（登录桩对象，永远没有 age 字段）判断是否新号，应为
   `user->query("age")`（真正的玩家 body）——导致新角色食物/饮水条永远是
   空的。改 `ob` 为 `user`，与本 session 内 5+ 例同类修法一致。
3. **§7.94（命令文件丢失 `.lpc` 扩展名，命令静默不存在）新增确认实例**：
   `cmds/adm/setskill.c.org`——管理员技能授予快捷命令，唯一候选（无竞争草
   稿，不构成内容判断），复制为 `cmds/adm/setskill.lpc` 使其重新可被驱动派
   发。恢复过程中在同一文件里又发现一个独立的拷贝粘贴 bug：单技能
   `level == 0` 分支的提示信息误引用了 `all` 分支专用、此处未初始化的
   `skills[i]` 数组，应为局部变量 `skill`——原样触发会是运行时错误
   （`setskill <目标> <单个技能> 0` 必现）。已改用 `skill`。已在
   AGENTS.md §7.94 补充了这第二例确认实例的说明。
4. **`cat()` 对不存在文件的空指针式崩溃（新发现，未归入既有编号）**：
   `adm/simul_efun/file.lpc::cat(string file)` 在 `file_size(file) == -1`
   （文件不存在）时仍会走 `write(read_file(file))` 分支，`read_file()`
   对不存在的文件返回 `0`（非字符串），传给 `write()`/`receive_message()`
   触发运行时错误 `*Bad argument 1 to receive() Expected: string or
   buffer Got: 0`。现场复现：`get_id()` 的 `"2060"` 校验失败分支会
   `cat("/adm/etc/new.txt")`，而该文件在 `work/` 里并不存在，每次输错客户
   端暗号都会命中。修法：`write(read_file(file) || "")`，不猜测/新增
   `new.txt` 的内容（那属于内容判断，超出本项目范围）。重启驱动后现场复测
   两次错误握手，`debug.log` 未再新增该错误（新驱动进程下错误计数保持不
   变）。注意：本档案的 `simul_efun` 实际编译单元是 `adm/obj/
   simul_efun.lpc`（`config.fluffos` 的 `simulated efun file` 指向此
   处），它通过 `#include "/adm/simul_efun/file.lpc"` 预处理拼入 —— 该
   include 型 simul_efun 只在驱动**启动时**编译一次，不会像普通对象那样按
   需热重载，因此这条修复必须重启驱动才能生效（前面 3 条也是同一物理文件，
   同样受此约束，但因为是在**驱动首次启动前**就已编辑完成，所以首次启动即
   生效，未受影响）。

### 分支不完全同源（未误移植 longyunmeng 的修复）

`longyunmeng` 那轮深测在其 `inherit/room/room.lpc` 的 `reset()`/
`xyzx_system_clean_up()` 里发现并修了一个 `filter_array()`+闭包在
`replace_program(ROOM)` 提交前被绑定导致的驱动级崩溃相关错误。直接读取
`xyzx3` 自己的 `work/inherit/room/room.lpc` 确认：`new_clean_up()`/
`reset()` 用的是 `all_inventory()` + 手写 for 循环，完全没有 `filter_array()`
闭包写法，结构上就不是同一份代码——因此**没有**移植该修复到本档案，这不是
遗漏，是确认了"§11 同分支标签 ≠ 代码字节甚至结构相同"，与本 session 之前
的观察一致。

### 测试覆盖

- **注册**：`2060` → 英文 id `xyzxdeep` → 中文名 **秦风廿七** → 密码
  `abc12345`（×2）→ 天资随机 `0`（膂力21/悟性18/根骨22/身法19）→ 邮箱 →
  性别 `m` → 落地北疆小镇（星宿海系新手村）。`look`/`score`/`i` 均正常；
  `score` 面板显示食物、饮水满格，确认 §8.9 已修复；`i` 正确列出新手赠品
  （布衣、魔法传送帖）。全程未见 debug.log 新增运行时错误，确认 §7.11 修
  复解决了注册必崩问题（`/log/login/newid.log` 成功写入并核对内容）。
- **安全切磋**：`fight.lpc` 自带 help 明确写"点到为止，因此只会消耗体力，
  不会真的受伤"。木人陪练在 `d/shaolin/wuchang.lpc`（少林练武场），但少林
  山门有 `knock gate` + `valid_leave()` 的俗家弟子拒入逻辑（"本寺不接待俗
  人"，正常设计，非 bug），测试角色未入少林门派，无法进入——改用已确认
  `(admin)` 身份（`fluffos`/`Mud@2026`）`goto /d/shaolin/wuchang` 现场验
  证木人机制本身：`fight mu ren` 完整跑完一轮判定文本、`死亡: 0 次`（
  `no_die` 生效）、冷却期内再次 `fight` 正确被拒绝（"你刚跟这个木人练过
  功！"）。木人机制经确认工作正常，仅因门派门槛借用了管理员身份，如实记
  录。
- **拜师+学艺（正规路径）**：`trans hs` 直达华山派练武场（未设门槛，与少
  林形成对比），`apprentice yue` 一次成功，`score` 确认"华山派第十四代弟
  子"/师傅"岳不群"。`learn <技能> from <某人>` 语法下 `learn unarmed from
  yue` 成功（岳不群内部技能 `huashan-ken` 通过 `map_skill("unarmed",
  "huashan-ken")` 映射，直接用 `huashan-ken` 当技能名反而学不到——这是设
  计内的映射机制，非 bug，是我自己第一次测试时的用法错误）。`skills` 确
  认"基本拳脚(unarmed) 1/0"。
- **学艺（管理员快捷路径）**：`setskill.lpc` 修复后现场验证：
  `setskill xyzxdeep force 1` 成功写入，玩家端 `skills` 确认"基本内功
  (force) 1/0"。
- **退出/重连**：`quit` 正常结算（丢弃不值钱物品，存档写入
  `data/user/x/xyzxdeep.o`/`data/login/x/xyzxdeep.o`）。`logind.lpc` 的
  重连防抖冷却是 50 秒（本档案比 longyunmeng 的 10 秒更长）；等待约 75 秒
  实际时间后重连，`2060` → id → 密码成功进入，`score`/`skills` 确认门派
  头衔、师傅、两项技能、潜能消耗（99/1%）均完整保留。
- **未测试/超出范围**：完整 900 秒 `NET_DEAD_TIMEOUT` 净断线软测试（本轮
  时间预算内未做，§10.8 类驱动级崩溃若存在未复现）；商店购买全流程（未
  找到可达且未测试的商铺）；30 分钟内退号删档的计时器——`grep` 未在
  `cmds/usr/quit.lpc` 找到此逻辑，本档案似乎没有这个机制（与
  longyunmeng 不同）。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝（`curl -sS $HTTPS_PROXY/__agentproxy/status`
返回 403），WASM 编译/运行验证本轮继续跳过，仅做原生驱动（linux-debug
预设，ASAN/UBSAN）下的完整 §10.7 测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。上面记录的所有修复（§7.11 `log_file()`、
§8.9 食物/饮水、§7.94 `setskill.lpc`、`cat()` 空指针）逐项核对代码
仍然生效，`win_times` 的 `%`-operator 也已用
`to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:146`）；
未发现新的 printf 调试残留，`feature/dbase.lpc` 未发现 tybxjh/wlhd
那种密码写保护，均不适用。管理员 `fluffos`/`Mud@2026`（含"2060"握
手）真实重连验证：落地此前保存的"客店"，`score` 显示"【天界总
管】"头衔，食物/饮水满格，`debug.log` 全程干净。驱动按精确 PID 结
束；测试期间产生的存档时间戳增量已 `git checkout --` 还原，本轮无
需新代码改动。
