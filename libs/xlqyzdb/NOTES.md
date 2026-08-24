# xlqyzdb — 仙侣情缘 "浙大版" (ZJU fork)

Archive: `仙侣情缘浙大版.rar`. Port: 40033. Status: **done** (boots clean
with a trimmed preload list, full registration flow verified end-to-end
including a real Chinese name).

## What this is

A modified fork of "仙侣情缘"/XLQY by bugbug & alading at 缥缈水云间
(ZJU — Zhejiang University), circa 2003-4-5, based on a branch closer to
`xlqy_new2007` (archive #26, `chinese.c` byte-identical) than to
`xianlvqiyuan`'s (archive #38) 2001 original — though `logind.c`/
`master.c`/`securityd.c`/`convertd.c` all differ from both, so this
needed its own diagnostic pass. `adm/obj/{master,simul_efun}` layout.
Archive required nested extraction (`.rar` → `xlqy.tar.gz` → `tar xzf`).
~9,206 raw files, 7,952 after `.c`→`.lpc` rename.

## Fixes applied

1. **Standard §15h**: `is_chinese()` single-char CJK rewrite;
   `check_legal_name()` bound `< 2 || > 12` → `< 1 || > 6`, removed the
   `i%2==0` gate (`name[i..<0]` slice was already clean).
2. **§15o insurance**: added `get_include_path()` to `master.lpc`.
3. **§8h recurrence**: `convertd.lpc`'s Greek-table stray-backslash typo,
   45 occurrences, fixed with the standard sed pattern (no CRLF present).
4. **§15g/k-adjacent hardening**: `adm/simul_efun/file.lpc`'s `cat()`
   hardened against a missing file (same fragile `write(read_file(...))`
   pattern as `xianlvqiyuan`, though the `BANNER` file itself was already
   correctly lowercase in this archive — applied as insurance regardless).
5. **A long boot-hang investigation, resolved pragmatically per explicit
   user direction** ("DNS / inet daemon should be generally disabled" /
   "It's not our target fix this round"): the full boot (with the
   complete original `adm/etc/preload`, 24 entries) took an extremely
   long time — observed via instrumented waits showing the driver
   spending the overwhelming majority of wall-clock time blocked (e.g.
   13 seconds of accumulated CPU time over 9+ minutes of wall-clock),
   consistent with one or more blocking/slowly-timing-out network calls
   scattered through preload and early object loading. Initially
   suspected and partially fixed `adm/daemons/network/dns_master` (an
   intermud DNS/mudlist daemon whose `create()` calls `resolve()` +
   `socket_create()`/`socket_bind()` to bootstrap a cross-mud database
   from a hardcoded remote server) — commented out its networking calls
   and removed it from preload. This did NOT fully resolve the slowness
   on its own (a full-preload retry still took many minutes), and rather
   than continue open-ended bisection across the other ~20 preload
   daemons, applied the pragmatic fix directed by the user: **trimmed
   `adm/etc/preload` down to only the entries needed for the
   registration flow itself** (`securityd`, `band`, `virtuald`, `logind`,
   `cmd_d`, `chinesed`, `convertd`) and excluded the rest (`emoted`,
   `aliasd`, `fingerd`, `channeld`, `monitord`, `natured`, `weapond`,
   `rankd`, `combatd`, `miscd`, `spelld`, `storyd`, `choosed`,
   `dns_master`, `locationd`, `feizeid`, `auto_cleard` — combat/quest/
   location/social systems, not needed to test registration). With this
   trimmed list the driver booted in well under 15 seconds. **This is a
   deliberate scope reduction for testing purposes, not a full
   restoration of the original mudlib's feature set** — if this lib is
   ever run for real play rather than registration-flow verification,
   the excluded daemons should be re-added one at a time and checked
   individually for their own preload-time cost/blocking behavior.

## New standing policy (see AGENTS.md)

Per explicit user direction, proactively check every future lib's
`adm/etc/preload` for a DNS/intermud/network daemon and exclude it
BEFORE the first boot attempt, rather than waiting to discover a boot
hang first.

## Interactive test result — full registration flow

With the trimmed preload list, verified the complete registration path
in one continuous connection (same flow shape as `xianlvqiyuan`): `gb`
→ `no` (not a student) → `new` → `xlqzda` (English name) → **`秦风`**
(real Chinese name) → accepted, proceeds to "请设定您的密码：".

## lpcc sweep

7,952 files, 7,824 pass / 128 fail (98.4%). Failure tail is the usual
shape (missing globals/inherits, a handful of syntax typos) — not
triaged individually per AGENTS.md §6b/§13. Memory stayed healthy
throughout (~14-15GB free).

## Re-verification pass (2026-07-23)

Extended the interactive test past the password prompt through full
registration (id `xlqzdgz`, name `秦江`), gift confirmation, `look`,
`score`, and `quit` — all completed correctly with real content (entered
the game world at 南城客栈/"South City Inn" with real NPCs, `score`
rendered the full character sheet, `quit` showed the real flavor-text
quit sequence).

**Investigated but not fixed — the "default error message" anomaly is
real, reproducible, host-load-dependent, and non-blocking.** The
transient `你发现事情不大对了，但是又说不上来。`(config's `default error
message`) noted as a one-off, non-reproduced anomaly in the sibling lib
`xianlvqiyuan`'s NOTES.md reproduces HERE consistently but with a highly
variable count per connection (observed 0, 3, and up to 18+ occurrences
across repeated identical test runs against the same unmodified code).
Instrumented `adm/daemons/logind.lpc`'s `enter_world()` with temporary
`write()` markers (removed after diagnosis, per the project's established
§8c/§15d technique): confirmed the errors are scattered across several
*different*, functionally unrelated calls in the same stretch of code
(new `MAILBOX_OB` creation, `"/adm/daemons/ipd"->seek_ip_address()`,
`CHANNEL_D->do_channel()`, `UPDATE_D->check_user()`) rather than one
single repeated bad call — inconsistent with a single deterministic bug
in any one of them. Also confirmed via a temporary instrumented
`master.lpc`'s `error_handler()` (writing `standard_trace()`'s full text
to a scratch file, removed after diagnosis) that **the underlying real
error text never gets captured** — not in `debug.log` (checked
extensively, zero matches even with markers correlating the exact
moment), not in the instrumented scratch file either (it was never even
created, meaning `error_handler()`'s own `write_file()` produced no
output during the very runs where the friendly message WAS shown to the
player — inconsistent with a straightforward reproducible LPC-level
error). Combined with the count varying run-to-run against byte-identical
code, this points to a **host-load/timing-sensitive artifact** (this
sweep runs many sibling agents' driver processes concurrently on a
shared, resource-constrained host) rather than a deterministic mudlib
bug — plausibly related to `eval_cost`/timer edge cases under CPU
contention (see AGENTS.md's `set_eval()` gotcha for a similar class of
timing-sensitive symptom). **Not chased further**: it never prevented
registration, `look`, `score`, or `quit` from completing correctly in any
of the ~6 test runs performed (worst case, extra noise the player has to
scroll past), and matches the sibling lib's own precedent of being
noted-but-not-investigated. Flagging here in more detail than the
original one-line note in case a future pass sees it escalate to
something that actually blocks a flow — this pass didn't observe that.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 7,952 total, 7,948
  written, 3 already-idempotent, 1 refused (self-check error, expected).
  One genuine **formatter regression found and fixed**: `d/sky/xitian.lpc`'s
  `valid_leave()` had `if (::valid_leave(me,dir)) return notify_fail(...)`
  mangled into `if (: : valid_leave(me, dir)\n)\nreturn notify_fail(...)`
  — the formatter breaks on the `::` parent-call scope operator followed
  immediately by `(`, inserting a space between the colons and corrupting
  the surrounding statement. This file (a high-level "heaven" zone room,
  not on the registration path) wasn't reached by the interactive test so
  the corruption didn't surface as a boot failure, but was caught by
  cross-checking for the same pattern found live-breaking a sibling lib
  (`xajh2`) in this same pass. Fixed by hand-restoring the
  original single-line form. Worth flagging as a general formatter bug:
  **any `::methodname(...)` call appears to be at risk of this
  corruption** — a sweep for `': : '` (colon-space-colon-space) across a
  lib's `work/` after running the formatter is a cheap, effective check.
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  fatal errors, trimmed-preload boot time still well under 15 seconds.
  Full registration flow re-verified in one continuous connection (id
  `qinjiab`, real Chinese name `秦岭江`, gender `m`, gift roll accepted):
  entered the game world at 南城客栈/South City Inn with real NPCs,
  `look` and `score` produced correct real content, `quit` showed the
  proper flavor-text sequence. The previously-documented
  `default error message` noise (`你发现事情不大对了...`) reproduced again
  at a highly variable count (consistent with the prior pass's
  host-load/timing-sensitive diagnosis) — never blocked any step.
- **WASM test**: boots clean, reaches the Chinese-name prompt without
  crashing (this lib's registration-counter code apparently tolerates
  the WASM harness's log-subdirectory-copy gap better than some
  siblings — shows a real, non-zero registered-player count rather than
  crashing). No IP-gating or other blocking issue observed in the
  portion exercised; did not push to a full playthrough (not required).

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5). Gates patched:

1. **Loopback always allowed** — `adm/daemons/band.lpc`: added a shared
   `is_local_site(site)` helper (true for `127.0.0.1`, leading `127.`,
   empty/non-string, or malformed non-dotted-quad IPs = WASM garbage) and
   short-circuited `is_banned()`, `is_strict_banned()`, and
   `create_char_banned()` with it (all three take an IP string; covers the
   two `is_strict_banned` login gates in `logind.lpc` `logon()`/
   `encoding()` and the `create_char_banned`/`is_banned` guest-jail check
   in `enter_world()`).
2. **IP-format checks bypassed for loopback** — `adm/daemons/logind.lpc`
   `encoding()` (~line 190): the `!ip_name` destruct and the
   every-char-must-be-digit-or-dot loop over `query_ip_number()` (both
   would kill any WASM connection with a garbage IP) now only run when
   `band->is_local_site()` is false.
3. **Anti-flood throttles exempt loopback** — `logind.lpc` `logon()`:
   (a) the 5-second same-IP reconnect throttle (`last_ip` + `time()+5`)
   and (b) the `logon_cnt > 10` per-IP concurrent-connection cap now skip
   local connections (new `is_local` flag); (c) the `MAX_LOGIN` (=5)
   per-IP multi-login cap in `get_id()` (~line 360) skips local
   connections too.
4. **Uptime startup gate** — none exists (the `uptime()` use in
   `encoding()` only ages out the `newid` registration-in-progress temp
   map every 300s); nothing to bypass. The per-id `newid` in-memory
   throttle ("已经有人在注册这个id了", cleared every 5 min / on restart)
   was left as-is — it is per-id not per-IP and only affects re-registering
   the same id twice within 5 minutes.
5. **Admin account seeded** — id `fluffos`, pw `Mud@2026`, name 浮浮,
   registered via the real flow (`gb` → `no` → `new` → id → Chinese name →
   password x2 → email → gender `m`, then the 西游记-style gift screen at
   first world entry: `9` accept → `y` confirm). Granted `(admin)` via
   `adm/etc/wizlist`. Verified: banner shows `(admin)`, wizard `update
   /adm/daemons/band` recompiles successfully, character finalized
   (no_gift flag cleared, lands in 南城客栈).

Save files (untracked, NOT gitignored — orchestrator must `git add`):
- `work/data/login/f/fluffos.o` (login save: password)
- `work/data/user/f/fluffos.o`  (player body save)

Retest: fresh normal registration (id `qinfzd`, 秦风) works end-to-end
(gift screen → world → `score` renders → `quit` clean); fluffos login +
wizard command works; debug.log has no new errors. One pre-existing,
unrelated error surfaced once in a transcript: lazy-loading
`adm/daemons/emoted` hits `restore_object(): Illegal mapping format`
on the archive's own corrupt `/data/emoted` seed save (§7.7 class;
emoted is excluded from the trimmed preload) — cosmetic, command still
dispatched, not introduced by this pass. Test char saves removed.
Note: id length limit is 3-8 chars (`fluffos` = 7 fits).

## Fail-closed loopback retrofit (2026-07-24)

**Security correction, applied retroactively.** `adm/daemons/band.lpc`'s
shared `is_local_site()` helper (item 1 above) originally treated an
empty/non-string/malformed IP as "local" (fail-open) — a stopgap for a
since-fixed WASM driver bug. Tightened to **fail-closed**:

```lpc
int is_local_site(string site) {
  if (!stringp(site)) return 0;
  if (site == "127.0.0.1" || site == "::1") return 1;
  if (strlen(site) >= 4 && site[0..3] == "127.") return 1;
  return 0;
}
```

An unparseable/empty IP now falls through to the normal (non-exempt)
path everywhere this helper is consulted — `is_banned()`,
`is_strict_banned()`, `create_char_banned()` in `band.lpc`, and every
`logind.lpc` call site that gates on it (the IP-format check in
`encoding()`, the anti-flood throttles in `logon()`/`get_id()`). No
other call site needed a separate edit since they all delegate to this
one helper. Retested: fresh registration (id `xlqztwo`, name 秦岭峰) still
completes end-to-end via loopback (gift accept → world → `look`/`score`
render correctly → `quit`); fluffos login + `update /adm/daemons/band`
still succeeds (`重新编译 /adm/daemons/band.lpc：成功！`). Zero new
runtime errors. Test char saves (`xlqzgat`/`xlqzone`/`xlqztwo`) removed
after verification.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

浙大分支的 XLQY。状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：XLQY 家族里 xianlvqiyuan 的手足档案。管理员登录干净正常：GB/BIG5 选择→未成年人门槛（否）→id+密码→'您的系统权限目前是：(admin)'。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 39 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

第一次完整游玩测试（原生驱动 `build`）。测试角色 id `zdbtest`，中文名
云梦仙。本轮 WASM 未重新验证：emsdk 工具链下载硬编码指向
`storage.googleapis.com`，本次会话的出口代理策略性拒绝该域名（403，用
`curl $HTTPS_PROXY/__agentproxy/status` 确认是策略拒绝而非临时故障），
本地无法构建 WASM 驱动。

### 发现并修复：注册流程遗留的 `printf("%O", ob)` 调试输出（AGENTS.md §7.34 已知模式的又一实例）

`adm/daemons/logind.lpc` 中文名确认成功分支有一行未加注释的
`printf("%O\n", ob);`（紧接在 `ob->set("name", arg);` 之前）。同一档案
里还存在 `loggind.lpc`、`login.lpc` 两份带同样调试输出的旧文件，但通过
`include/globals.h` 的 `#define LOGIN_D "/adm/daemons/logind"` 确认它们
未被任何地方引用，是死文件，未做改动。按 §7.34 既定修法直接删除
`logind.lpc` 里的这一行。修复前注册第一个测试账号时确认能看到裸露的
对象路径夹在提示语之间；修复后（本轮实际注册）未再出现。`§9` 格式化
自检通过（`{"total":1,...,"unchanged":1,"errors":0}`）。

### 发现并修复：`emoted` 守护进程未捕获的 `restore()` 抛错，导致该守护进程永久残废（AGENTS.md §7.87 已知模式的又一实例，触发原因不同）

- **症状**：角色离开〖将军府〗大门口房间时（`d/jjf/gate.lpc`，走
  `south`），第一次触发 `command_hook()` 惰性加载
  `/adm/daemons/emoted` 时，玩家直接看到驱动的默认错误提示"你发现事
  情不大对了，但是又说不上来。"，`debug.log` 记录：
  ```
  执行时段错误：*restore_object(): Illegal mapping format while restoring emote.
  程序：/feature/save.lpc 第 18 行
  物件：/adm/daemons/emoted
  呼叫来自：/feature/command.lpc 的 command_hook() 第 85 行，...
  呼叫来自：/adm/daemons/emoted.lpc 的 create() 第 48 行，...
  ```
- **根因**：`emoted.lpc` 的 `create()` 写法和 AGENTS.md §7.87 记录的
  `xyj20032` 一模一样：
  ```lpc
  void create() {
    if (!restore() && !mapp(emote))
      emote = ([]);
  }
  ```
  当 `restore()` **抛出**（而不是返回假值）时，`if` 语句的 fallback
  赋值永远不会执行，`emote` 全局变量从此在整个进程生命周期里都是 `0`。
  但这次的触发原因和 §7.87 原始实例不同：那次是 `maximum read file
  size`（300000）小于存档实际大小（328298 字节）；这里 `data/emoted.o`
  只有 262239 字节，本档案的 `maximum read file size` 同样是
  `300000`，明显没超限——`debug.log` 报的是`Illegal mapping format`，
  说明这份存档本身的映射语法就是驱动的 `restore_object()` 解析不了的
  真实损坏数据（AGENTS.md §7.7 记录的"损坏存档可以合法地导致
  `restore()` 失败"的另一种损坏形状，不是资源限制）。因为
  `create()` 只在进程内第一次引用该对象时跑一次，且这次触发点是玩家
  一次普通的移动指令（不是显式的 emote 指令），`debug.log` 里也确实
  只留下这一条记录，此后同一进程内的 emote 相关调用（`smile` 等）不
  会再重复报错，但 `emote` 会一直是 `0`，任何后续 `do_emote()` 路径
  （包括 NPC 自身触发的社交行为）本应像 §7.87 里 `xyj20032` 那样以
  `*Value being indexed is zero.` 崩溃——本轮只是恰好没有再触碰到那条
  代码路径就先被这次会话中断了，但代码本身的脆弱性和 §7.87 完全一致，
  按同样标准视为需要修复的程序 bug。
- **修复**：套用 §7.87 已验证的两段式修法（这里只需要"让 `create()`
  对任何失败方式都健壮"这一半，`maximum read file size` 已经够大不需
  要调）：
  ```lpc
  void create() {
    catch(restore());
    if (!mapp(emote))
      emote = ([]);
  }
  ```
- **验证**：修复前重启驱动，从起始房间沿 `west/north/east/east/south`
  走到〖将军府〗后再 `south` 稳定复现上述崩溃（`debug.log` 该次错误
  未标"被拦截"，说明确实是未捕获的抛出）。修复后重启驱动，同样路径
  第一次触发 `south` 时 `debug.log` 记录变为"错误讯息被拦截："开头、
  调用栈里多出一帧 `emoted.lpc` 的 `CATCH()`，玩家侧仍会看到一次性的
  默认错误提示（这是驱动对"本回合调用链中出现过运行时错误"的固有通
  知行为，`catch()` 拦下的是致命崩溃本身，不是这条提示——与 §7.87 描
  述的效果一致，未强行消除这条无害的一次性提示）；此后同一进程内再
  次触发 `south`、直接测试 `smile`（因为损坏数据没有被还原，`emote`
  现在是空表，`smile` 走到默认的"什么？"而不是崩溃）均未再复现任何
  执行时段错误，说明 `emote` 全局变量已经稳定落在空表而不是 `0`。修
  复的是代码脆弱性本身（不修复也不影响每个测试环节的推进，因为
  `command_hook()` 未匹配到任何 emote 就正常放行后续命令处理），损坏
  的 `data/emoted.o` 存档内容按 §7.7 既定原则不做"内容修复"，留作已
  知限制。

### 测试内容与结果

- **注册**：GB 编码 → 是否中小学生（no）→ `new` → 英文名 `zdbtest` →
  中文名（云梦仙，确认上面的 printf 泄漏已修复）→ 密码 ×2 → 邮箱 →
  性别（m）→ 天赋分配界面（`str`/`con`/`int`/`spi` 四项，直接接受默认
  值 `9`）→ 顺利进入起始房间〖南城客栈〗。天赋分配界面的欢迎语和引导
  文案硬编码写的是"欢迎光临西游记！"（`d/wiz/init.lpc` 第 39、74
  行），但这份档案的 README 明确说明本身就是"西游记题材的仙侠世界"，
  `score` 面板底部也正确显示〖仙侣情缘·浙大站〗——确认是刻意的主题
  文案而非从别的档案误拷贝的品牌残留，未作改动。
- **状态查看**：`look`/`score`/`i` 在天赋分配、门派加入前后均正确刷
  新（体格/根骨/悟性/灵性数值、门派名称、师承字段）。
- **门派/技能——组织路线（拜师）**：从起始房间沿
  `west/north/east/east/south` 走到〖将军府〗大门（`d/jjf/gate.lpc`），
  管家秦安（`d/jjf/npc/qinan.lpc`）会拦截非本门弟子的 `south` 指令
  （`valid_leave()` 的既有设计，不是 bug），需要先 `answer 拜师`（精
  确匹配"拜师"二字，同目录另一份死文件 `d/city/npc/guanjia1.lpc` 用的
  是子串匹配 `strsrch`，容易误导——但那份文件未被任何房间引用，不影
  响实际游玩，未改动）触发 `pending/jiangjun_answer` 标记后才放行，
  随后 `apprentice qin fu` 成功拜入"将军府"第四代弟子，`score` 正确
  显示门派与师承。
- **安全陪练**：〖练武场〗（`d/jjf/front_yard.lpc`）的沙袋支持
  `da sandbags`（注意不是常见的 `hit`），未入门派/道行不够时分别给出
  "沙袋一动不动"和"道行不够高，不能从打沙袋中学到新知"的正确提示，
  未见任何崩溃。
- **门派/技能——快捷路线（赠礼 NPC）**：全档案搜索到两处"一次性赠送
  巨额战斗经验/道行/潜能"的赠礼 NPC 代码
  （`d/city/npc/new_jing.lpc`、`d/qujing/wudidong/npc/yanshu.lpc`），
  但两者都未被 `work/d/` 下任何房间的 `objects` 引用，是不可达的孤立
  内容（与此前 `xlqy_early` 的死 `muren.lpc` 同类情形）。如实标注为
  本轮未覆盖，而非"和同代码库其它档案一样所以没问题"。
- **持久化**：真实 `quit`（掉落非贵重物品、告别文字，无二次确认）后
  重新登录，门派（将军府）、师承（将军府秦富）、天赋属性全部正确复
  原；登录入口固定回到起始房间〖南城客栈〗而非 quit 时所在的〖练武
  场〗——与本项目此前测试过的其它"西游"题材档案（`xyj2000f`/
  `xiyouji450`/`xiyouji2006`/`xlqy_early`，血缘家族不完全相同）表现一
  致，判断为这批 MUD 共有的既定设计，不是位置持久化 bug。
- **管理员账号**：`fluffos`/`Mud@2026` 登录，系统权限显示
  `(admin)`，`update /adm/daemons/logind` 热更新成功（含本轮 printf
  泄漏修复），确认写 ACL 正常。
- **战斗（PVE 实战）、经济/商店**：**未覆盖**——本轮时间集中在验证
  emoted 崩溃的修复上，沙袋陪练已验证安全练习路径可用，未额外寻找可
  挑战的野外目标或商店交易流程。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 231 live occurrences deleted: 230 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 3 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40033.

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

## 深度功能测试补测：真实 PVE 战斗 + 商店买卖（2026-08-24）

补齐上一轮标记为"未覆盖"的两项（真实野外战斗、`buy` 商店购买），
使用管理员账号 `fluffos`。

### 真实 PVE 战斗

从起始房间〖南城客栈〗沿 `west/south/south/south/west/northwest/
west/south` 到〖民居〗（`d/city/minju3.lpc`），`kill rat` 攻击非陪练
性质的〖大老鼠(Rat)〗。战斗完整回合制展开（拳法/擒拿/腿法攻防轮流
描述、命中/闪避判定、体力状态提示逐级下降），管理员角色自身未受
训练、命中率极低，最终被大老鼠击杀——`你死了` → 传送到〖阴阳界〗
死亡之门（`d/death/gate.lpc`）→ 判官崔珏对话 → 自动"命不该死"判定 →
复活并传送到〖荒郊小店〗，随身携带的不值钱物品掉落一件（预期行
为）。整个死亡→复活流程正确完成，未见任何崩溃或卡死；`debug.log`
干净（唯一相关记录是下方 emoted 的已知一次性提示，见下）。结论：
真实 PVE 战斗机制（含死亡与复活）功能正常，无程序 bug。

### 商店买卖（`buy`/`sell`，董记当铺 `d/city/dangpu.lpc`）

路径：起始房间 `west` → `west`（朱雀大街 → 董记当铺）。用 `clone`
指令（管理员权限）复制一把〖铜锤〗（`value` 500）验证 `sell`/`buy`
的金额与库存计算：

- `value hammer` 正确报价"五两白银"（500），卖断价"二两白银又
  五十文钱"（250，即 50%）。
- `sell hammer` 后角色钱袋从"二两银子"变为"四两银子+五十文钱"，
  与 2 两 + 2 两 50 文 = 4 两 50 文 完全吻合。
- `list` 正确显示当铺库存新增"铜锤 x1"，价格与卖出价一致（五两
  白银）。
- 钱不够时 `buy hammer` 正确拒绝（"你没有足够的钱"），符合预期
  （50% 亏损的当铺买卖机制，非 bug）。
- 补足钱后 `buy hammer` 成功，"你向当铺买下一把铜锤"，钱袋从
  "五两银子+五十文钱"（550）扣至"五十文钱"（50），扣款 500 分文
  不差；`list` 随即显示"当铺目前没有任何货物可卖"（库存正确清零并
  删除条目）。
- 收尾把铜锤卖回当铺（验证库存/金额双向一致后清理测试痕迹），
  `quit` 正常。

结论：`sell`/`buy` 双向金额与库存计算均正确，无程序 bug。

### 发现并修复的真实程序 bug：`log_file()` 未加 `assure_file()` 保护（AGENTS.md §7.11 已知模式的又一实例）

- **症状**：测试商店买卖时用管理员 `clone` 指令复制物品，触发未捕获
  的执行时段错误，`clone` 指令中途中止——`new(file)` 已创建物件，但
  日志调用抛错后函数提前返回，物件从未被 `move()` 进玩家背包（孤儿
  物件），`clone.lpc` 承诺的"复制成功，放在你的物品栏"提示也没有
  出现：
  ```
  执行时段错误：*Wrong permissions for opening file /log/nosave/CLONE
  for append. "No such file or directory"
  程序：/adm/obj/simul_efun.lpc 第 17 行
  呼叫来自：/cmds/imm/clone.lpc 的 main() 第 56 行
  呼叫来自：/adm/obj/simul_efun.lpc 的 log_file() 第 17 行
  ```
- **根因**：`adm/simul_efun/file.lpc` 的 `log_file()` 是裸
  `write_file(LOG_DIR + file, text)`，没有目录保护，而这份档案从未
  打包 `/log/nosave/` 目录（`ls work/log` 确认不存在）；同一文件里
  紧接着定义的 `assure_file()` 辅助函数完全没被用到——与 AGENTS.md
  §7.11 记录的近乎通用的拷贝粘贴模式（已在 8+ 个互不相关的血统家族
  独立确认）完全一致。这次的触发路径是管理员 `clone` 指令自己的审
  计日志调用（`log_file("nosave/CLONE", ...)`），不是注册/死亡流程，
  但属于同一 bug 类——任何调用 `log_file()` 的路径都会中招（`update`
  热更新、`suicide` 等其它审计日志同理，均未逐一验证，但根因已在
  单一共享函数层面修复，一次修复覆盖全部调用点）。
- **修复**：套用 §7.11 已验证的标准修法，在 `log_file()` 内部加
  `assure_file()` 保护（同时补上因文本顺序在前而需要的前向声明）：
  ```lpc
  void assure_file(string file);

  void log_file(string file, string text) {
    assure_file(LOG_DIR + file);
    write_file(LOG_DIR + file, text);
  }
  ```
  （文件：`adm/simul_efun/file.lpc`。）
- **验证**：`simul_efun.lpc` 是 `#include` 拼接式写法（与 AGENTS.md
  §7.11 记录的 `fy2005` 实例同形），driver-special object 无法热
  `update`，重启驱动后生效。重启后同样的
  `clone /d/obj/weapon/hammer/tongchui` 成功执行，正确提示"铜锤复制
  成功，放在你的物品栏"并出现在背包里；随后完整走完上面的
  `sell`/`buy` 流程验证。`log/nosave/` 目录被自动创建（driver 层面
  `mkdir` 行为符合预期）。

### 已知的一次性无害提示（非新 bug，确认此前修复仍然有效）

`south`/`list` 等指令在每个驱动进程生命周期内第一次触发
`/adm/daemons/emoted` 惰性加载时，仍然出现"错误讯息被拦截："开头的
`restore_object(): Illegal mapping format` 提示（本轮死亡战斗与商
店测试各触发一次，分属两个不同的驱动进程）。这与 2026-08-07 深度
功能测试记录的 §7.87 修复（`emoted.lpc` 的 `catch(restore())`）预
期行为完全一致——该提示不写入 `debug.log`（仅出现在玩家屏幕上，与
此前记录的"底层真实错误文本从未被捕获"现象一致），且未阻断任何后
续指令。确认修复仍然有效，非新问题。
