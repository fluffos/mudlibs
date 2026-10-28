# fluffos(西游记2000).tar.gz → `xyj2000f`

- Archive: `archives/fluffos(西游记2000).tar.gz` (59MB — a full FluffOS
  driver source checkout, `.git` included, bundling the mudlib as a
  NESTED `mudlib/world.tar.gz` inside it (extracted separately). The
  mudlib itself is "西游记"/"Xi You Ji"/"Journey to the West",
  `xiyouji.org`, up since ~1998 per in-file credits (`mon@xiyouji`).
- Mudlib root: `world/` (after extracting the nested tarball). Config at
  `world/config.xyj`.
- Port: **40012**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: ASCII banner, GB/BIG5 prompt (send "gb"), site
credits, age-appropriateness question (a real, intentional gameplay/
content gate, not a bug). Note the BIG5 hint line in the encoding-select
banner itself displays as mojibake (`﹁村癘舧眤...`) — likely a genuine
BIG5-encoded substring embedded in an otherwise-GBK file (same shape as
ds386's Latin-1-in-GBK-file issue) — cosmetic only, not fixed.

## What was fixed

1. Encoding: routine GB18030→UTF-8 pass, 766 `.c"` refs auto-fixed, 72
   angle-bracket `.c>`→`.lpc>` refs, and **89 local angle-bracket
   `#include <x.lpc>` → `"x.lpc"` conversions handled automatically** by
   `convert_lib.sh`'s newly-generalized fix (first real large-scale test
   of that generalization from lib #13's manual fix — worked cleanly,
   no manual follow-up needed for this pattern at all this time).
   `.c`→`.lpc`: 5637 files. `static`→`nosave`: 47 files.
2. `adm/daemons/convertd.lpc` (a charset-conversion daemon, containing a
   large Greek-alphabet lookup table as string literals) had 5 lines
   shaped like `"α\",` — a stray trailing backslash right before the
   closing quote, which escapes it instead of closing the string,
   turning the rest of the file into one runaway unterminated string
   literal (`Illegal character`/`syntax error` cascade). Pre-existing
   data typo, not something our pipeline introduced. Fixed with a
   targeted `sed -E 's/\\"(,)?$/"\1/'` on the whole file (removes a
   trailing `\"` → `"`, or `\",` → `",`, at end of line only, so it can't
   touch a legitimately-escaped quote appearing mid-string elsewhere).

## Known remaining issues (documented, not fixed)

- 66 lpcc-sweep failures (of 5637, 98.8% pass) — not triaged given the
  small count and time budget; boot/login path unaffected.

## How to run

```
cd libs/xyj2000f
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40012 --timeout 10 --send "gb" --send "" --send "quit"
```

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 5637 `.lpc` files; 5544
  reformatted, 91 unchanged, only 2 refused (self-check `errors`) —
  very clean corpus.
- **Native retest against rebuilt driver**: clean, zero fixes needed.
  Full registration flow (gb encoding → age-gate `no` → `new` keyword →
  English id → real Chinese name → password → email → gender → gift
  allocation `9`/`y`) verified end-to-end reaching 南城客栈, with
  `look`/`score`/`quit` all producing correct output, zero debug.log
  errors.
- **WASM test — 1 regression found + fixed** (WASM-specific, does not
  reproduce natively): `adm/daemons/logind.lpc`'s `encoding()` callback
  runs a one-time "mirror site verification" gate
  (`!find_object(DNS_MASTER) || !"/adm/daemons/band"->check_ip_(...)`)
  after every player selects gb/big5. This lib's `adm/etc/preload` DOES
  include `dns_master` (unlike libs where §15p's DNS-preload-exclusion
  policy applies) and it preloads fine natively (real sockets work), so
  `find_object(DNS_MASTER)` is truthy there and the gate passes cleanly
  — but under WASM (no sockets package) `dns_master` fails to compile
  at preload, `find_object(DNS_MASTER)` is always `0`, and the code
  unconditionally called `DNS_MASTER->get_host_name(...)` even inside
  its own "absent" branch (building the shutdown log message) — which
  itself crashed with `*No program in object` before ever reaching the
  intended `shutdown(1)`, leaving the connection stuck in a broken state
  (every subsequent input treated as an unrecognized command, no way to
  ever complete the encoding step). This is the exact AGENTS.md §15ai
  pattern (`xiyouji2003`'s finding, same lineage) applied to a lib that
  hadn't needed it before because it never excludes `dns_master` from
  preload. Fixed identically: guard with `find_object(DNS_MASTER) &&
  ...` so "daemon absent" means "skip the gate" (allow login) rather
  than "gate failed" (attempt, and crash trying, to shut down). This is
  a no-op change natively (dns_master is always present there) and only
  changes behavior under WASM. Re-verified clean both ways: native
  registration still reaches 南城客栈 with zero errors (real name
  孙悟空), and the full registration flow (incl. the age-gate and `new`
  keyword quirks, real name 猪八戒) now completes under WASM too,
  reaching 南城客栈 with `look`/`quit` both working — full WASM
  playthrough, not just boot. Not affected by the documented
  `query_ip_number()` WASM limitation (this lib's gate is
  `find_object`-based, not IP-format-based).

## WASM-enablement pass (loopback / admin seeding)

- **Loopback ban bypass** (§1.3b): `adm/daemons/band.lpc` — new private
  helper `is_loopback_site()` (~line 153), short-circuits
  `is_banned()` (~line 161), `create_char_banned()` (~line 179), and
  `is_strict_banned()` (~line 194) to return 0 (not banned) for
  `127.0.0.1`/`::1`/`localhost`/`127.`-prefix sites.
- **IP-format kick** (§1.3a, folded into the loopback patch):
  `adm/daemons/logind.lpc` `encoding()` (~line 180) — the "No IP" /
  "Non_number" destruct-on-connect checks now only run for genuinely
  remote `ip_number` values; loopback skips straight through.
- **Anti-flood / multi-login cap** (§1.3e): `adm/daemons/logind.lpc`
  `get_id()` (~line 348) — the `MAX_LOGIN` per-IP multi-login-cap block
  is now skipped entirely when `query_ip_number(ob)` is loopback.
- **Wizard site whitelist** (§1.3b): `adm/daemons/securityd.lpc`
  `match_wiz_site1()` (~line 116) — loopback sites always pass (return
  1) before the original whitelist-line logic runs.
- **Uptime gate**: none found (`logind.lpc` has no `uptime()` connection
  gate).
- **Fail-closed retrofit** (2026-07-24 security correction): all four
  gates above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken
  `query_ip_number()`). Since the driver's IP-reporting bug is now fixed
  upstream (WASM reports a clean `127.0.0.1` like native), that fallback
  was removed — loopback is now strictly `stringp(ip) &&
  (ip=="127.0.0.1" || ip=="::1" || ip[0..3]=="127.")`; anything
  unparseable/empty is treated as untrusted/remote and goes through the
  original gate logic, same as before this pass. Retested: fluffos
  login + `look`/`quit` still clean over loopback.
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
  `(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist` (read by
  `securityd.lpc`). Registered through the real flow. Verified re-login +
  `update /adm/daemons/band` → recompiled successfully as fluffos, score
  shows 【巫师】title.
- **Retest**: fresh normal registration (孙悟空-style real Chinese name)
  reaches 南城客栈 with working `look`/`score`/`quit`; test char saves
  removed; no new debug.log errors.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/xyj2000f/work/data/login/f/fluffos.o`,
  `libs/xyj2000f/work/data/user/f/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-08-06)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角
色 id `xyjtestb`，中文名 沙悟净。本轮 WASM 未重新验证：emsdk 工具链
下载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略性拒
绝该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策
略拒绝而非临时故障），本地无法构建 WASM 驱动。

### 发现并修复：`maximum evaluation cost` 过低，每一次新角色注册都会在 `make_body()` 里静默中止（AGENTS.md §7.90 新的、更严重的实例）

- **症状**：真实游玩（而非仅注册后立刻检查 `look`）触发。用第一个测
  试账号（`xyjtest`/沙悟净）走完性别选择前的所有步骤（英文名 → 中文
  名 → 密码 → 确认密码 → 邮箱）后，连线在邮箱提示之后卡住——没有任何
  玩家可见的错误信息，看起来就像连接挂起了。`debug.log` 里同一时刻有
  一条完整的运行时错误：`Eval interrupted: object adm/obj/simul_efun
  cost limit reached, limit: 400000 usec.`，栈追踪经过
  `logind.lpc` 的 `get_email()` → `make_body()` → `master.lpc`/
  `simul_efun.lpc` 的 `author_file()`，触发点是 `/std/char.lpc`（玩家
  身体类）第一次编译时连带加载 `feature/edit`、`feature/finance` 等
  继承链。
- **根因**：`config.fluffos` 里 `maximum evaluation cost : 400000`——
  比 AGENTS.md §7.90 记录的"这个项目最常见的 700000 模板默认值"还要
  低，而这份档案第一次编译整条 `std/char.lpc` 继承链的开销超过了这个
  预算。和 §7.90 原案例（只在某些从未访问过的房间移动时零星触发）不
  同，这里是**每一次新角色注册**都会 100% 复现——因为 `make_body()`
  是注册流程的必经步骤，第一次编译 `std/char.lpc` 的开销不会因为运气
  好而躲过去。
- **修复**：把 `maximum evaluation cost` 从 `400000` 提高到
  `5000000`（AGENTS.md §7.90 记录的同一个已在本项目 30+ 份档案验证过
  安全的数值）。
- **验证**：修复前用第一个测试账号复现了这次静默中止（`debug.log` 里
  完整的 `cost limit reached` 追踪，连接停在邮箱提示后不再有任何响
  应）；修复后重启驱动，用第二个测试账号（`xyjtestb`/沙悟净）完整走
  完注册全部步骤（含性别选择、天赋接受确认），顺利进入南城客栈，
  `debug.log` 全程无 `cost limit reached` 或任何其它运行时错误。

### 发现并修复：注册流程里遗留的 `printf("%O", ob)` 调试输出（AGENTS.md §7.34 已知模式的又一实例）

- **症状**：玩家输入完中文名之后，屏幕上多出一行裸露的对象内部路
  径，如 `/obj/login#0`，夹在"您的中文名字："和"请设定您的密码："
  两行正常提示之间。
- **根因**：`adm/daemons/logind.lpc:646`（中文名确认成功分支）有一行
  未加注释的 `printf("%O\n", ob);`，是原作者遗留的调试脚手架（该文件
  开头注明 `cracked by vikee 2/09/2002`），archive 里原样就是这样。
  该文件里没有找到第二条平行路径（比如接受系统随机名字的分支）里的
  重复实例。AGENTS.md §7.34 已把这个模式记录为登录/注册流程的常见通
  病。
- **修复**：删除这一行，与 §7.34 记录的既定修法一致。
- **验证**：修复前用第一个测试账号亲眼看到 `/obj/login#0` 出现；修复
  后用第二个测试账号完整走过一次注册（英文名→中文名→密码→确认密码
  →邮箱→性别→天赋），确认这一行不再出现。`§9` 格式化自检通过。

### 测试内容与结果

- **注册**：GB 编码 → 是否中小学生（回答 no）→ `new` 注册 → 英文名 →
  中文名（沙悟净）→ 密码（含大小写字母/数字）→ 确认密码 → 邮箱 → 性
  别（m）→ 天赋接受（体格/根骨/悟性/灵性四项，可重选或直接接受），
  全程顺利进入 `南城客栈`。
- **战斗**：`朱雀大街` 的疥顶小僧（`d/city/npc/jieding.lpc`，
  `attitude: peaceful`，物理属性较弱但技能等级 50-79）——`set wimpy
  70` 后 `fight seng` 触发真实对战，在气血降到 70%（140/200）时正确
  自动逃跑（"看来该找机会逃跑了．．．"），角色被传送到相邻的十字街
  头，无崩溃。`d/obj/misc/muren.lpc`（一个理论上更适合当陪练目标的
  木人，`accept_fight()` 里没有攻击者属性镜像，是固定弱属性
  `combat_exp 50000`）在这份档案的 `d/` 目录树里没有找到任何房间引用
  它——很可能是这份快照里未被实际放置使用的遗留内容，未深究。
- **持久化**：两种方式都验证了——(a) 驱动整体重启（比普通 quit+
  relogin 更强的持久化测试）后用第一个测试账号密码重新登录，正确恢
  复到南城客栈、`(player)` 权限、装备状态；(b) 真实 `quit`（丢弃不值
  钱的粗布衣，符合已知的丢弃机制）后立即重新登录，同样正确恢复——
  但两次都回到了南城客栈这个固定入口，而不是 `quit` 时所在的十字街
  头。查证 `help newbie` 第一条明确写着"进入西游记，你会最先出现在
  长安城的南城客栈"，没有措辞限定"仅第一次"，读作这条游戏本身固定
  的登录起点设计（不是位置持久化 bug），如实记录而非默认判定。
- **管理员账号**：`fluffos`/`Mud@2026` 登录，`update
  /adm/daemons/logind` 热更新成功，确认写 ACL 正常。
- **门派/拜师**：**未覆盖**——`朱雀大街` 上偶遇的门派弟子 NPC（五庄
  观第三代弟子 张果老）是过路巡逻角色，`ask ... about 拜师` 时人已经
  离开房间；`help menpai` 描述了八大门派的风格但没有给出具体的拜师
  地点/NPC 名字，需要进一步探索地图才能找到固定的拜师入口。经济/商
  店同样未覆盖。均如实标注为本轮未测，而非默认"和同引擎家族其它档
  案一样所以没问题"。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记 2000 的一份快照。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 28 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 142 live occurrences deleted: 141 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as sibling `xyj2000`). 1 already-commented-out instance left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40012.

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

## Round-four gap closure: sect apprenticeship + shop/economy (2026-08-24)

Closes the two items the 2026-08-06 §10.7 pass left explicitly
untested (see that section above).

### Sect apprenticeship

No stationary, map-placed sect-master NPC exists in this archive's
current room layout — `d/nanhai/npc/master.lpc` (玄智和尚, a bonze
master of 山烟寺, `create_family("山烟寺", 26, "住持")`) is a fully
functional recruiter NPC (`attempt_apprentice`/`do_recruit`/
`recruit_apprentice`), but a corpus-wide grep found **zero** room files
anywhere under `d/` that load it — same "written but never placed"
shape as `d/obj/misc/muren.lpc` noted in the original pass. Used the
admin account's `clone` wizard command to place it in 南城客栈 (the
same technique implicitly endorsed by this round's task framing) as
the practical way to reach it.

**Found and fixed a real instance of AGENTS.md §7.117** (`bai.lpc`/
`apprentice.lpc`'s "did you betray your old sect" check missing an
existence guard for first-time applicants): `cmds/std/apprentice.lpc`
line 59 had the exact dominant vulnerable form,
`if ((string)me->query("family/family_name") != (string)ob->query("family/family_name"))`,
with no guard on whether the applicant (`me`) already has a family.
Its sibling `cmds/std/recruit.lpc` already carries the fix on its own
matching branch (line 64, `if ((ob->query("family")) && ...)`, with
the tell-tale `// follow modified by elon 09-10-95 to fix a bug in 1st
time recruit` comment) — this lib was not part of the large corpus-wide
§7.117 sweep (not matched by that session's grep), so it's a new,
previously-uncaught instance of the same one-file-of-the-pair-missed
gap already seen on `sjshv150`. Fixed identically to the documented
remedy: `if (me->query("family") && (string)me->query("family/family_name")
!= (string)ob->query("family/family_name"))`.
- Confirmed via `lpcc --batch`: file compiles clean (not among this
  lib's pre-existing 64 unrelated batch failures).
- Confirmed live end-to-end via a full normal playthrough: registered
  a fresh character, `ask master about 出家` → `kneel` (剃度, renamed,
  `class` set to `bonze`) → `apprentice master` — completes via the
  NPC's own `attempt_apprentice`/`recruit.lpc` path (already-guarded
  sibling branch) and `score` correctly showed
  `山烟寺第二十七代弟子 <name>` with `你的师父是玄智和尚`.
- Separately, specifically exercised the buggy `apprentice.lpc`
  branch itself (which the natural NPC-driven flow above does NOT
  reach, since that NPC always recruits *after* the player calls
  `apprentice` first): registered a second fresh, family-less
  character, used the admin account's `call master->command("recruit
  <id>")` to force the master to recruit first (bypassing
  `attempt_apprentice`'s own class/gender gate, which is irrelevant to
  the bug under test), then had the applicant confirm with `apprentice
  master`. Before the fix this unconditionally took the "betrayed your
  old sect" branch (wrongly, since a first-timer has no family to
  betray) and would have zeroed score / set the `betrayer` flag; after
  the fix it correctly took the normal "拜师" branch (`你决定拜玄智和
  尚为师。`) with no betrayer flag, and `score` afterward showed clean
  membership (`山烟寺第二十七代弟子 <name>`, no score reset).

### Shop / economy

Found a real, placed vendor NPC: `d/city/bookstore.lpc` loads
`d/city/npc/bookseller.lpc` (孔方兄, `inherit F_VENDOR_SALE`), selling
several books via `vendor_goods`. Tested with the admin account
(`clone`d the vendor and some `/obj/money/silver` into the same room,
`set_amount()` via `call` to fund the purchase):
- `buy san from kongfang` (三字经, value 1000 = 10两银子): had exactly
  10 两银子, spent all of it, received the book, zero coin objects
  left over — correct exact-payment math.
- `buy xyjbook from kongfang` (《西游记》, value 100 = 1两银子): had 15
  两银子 (1500), paid 100, correctly received **14两银子** in change
  (`pay_money()`'s gold/silver/coin decomposition of the 1400
  remainder) plus the book — correct change-making math, not just
  exact-payment.
- No `debug.log` errors from either purchase.

No programming bugs found in the shop/vendor path itself
(`feature/vendor.lpc`/`vendor_sale.lpc`/`cmds/std/buy.lpc`) — the
type-mismatch-looking `mixed buy_object(object who, object item)`
override in `bookseller.lpc` (declared parameter type `object` but
always actually passed a `string` item id from `cmds/std/buy.lpc`) is
functionally harmless in this driver (no runtime type enforcement on
dynamically-dispatched call args), so not treated as a bug per the
scope rule (no crash, no error signature).

### Cleanup

Removed the two round-four test character saves (`xyjtc`/`xyjte`,
untracked `.o` files under `work/data/{login,user}/x/`) and destroyed
all admin-side clones (the two placed-for-testing NPCs, leftover
money/book clones) before stopping the driver. `xyjtestb` (from the
original 2026-08-06 pass, already tracked in git) was left untouched.

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyj2000f --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`daemon/skill/xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`），共改动 400 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：388 -> 388 通过，无回退；改过的头文件的 185 个包含者 182 -> 182 通过。

启动时警告 67 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 8 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 6 个，只在 #if 分支用的声明移进分支 0 个文件；改动 12 个文件，HEAD 与工作树各载入一次无回退（12 objects; HEAD PASS 12, tree PASS 12; regress 0; newly loading 0），这些文件的警告 34 -> 20。

## 深度功能测试（§10.7，2026-10-11）：全库严格 UTF-8 检查

- `d/sky/npc/zz-tianwang.lpc` 原档在函数中途变成二进制垃圾（GBK，未转码），无法恢复，保留原样。

## 编译警告收尾（2026-10-12）

`scripts/lpc_twin_port.py adopt xyj2000 xyj2000f` 搬来 xyj2000 同日整理（969f36bdd8c）里与本库逐 token 相同的 15 个文件；`d/death/npc/wgargoyle.lpc`（白无常）与 xyj2000 不同，`scripts/toolkit_fix.sh` 去掉了它多余的 `inherit F_CLEAN_UP`。能编译的文件警告清零；HEAD 与工作树各载入一次：14 个对象，HEAD PASS 14，tree PASS 14，regress 0。

- 袈裟 `d/obj/cloth/jiasha.lpc` 原来只跑 `F_UNIQUE` 的 `init()`，撕袈裟的 `tear` 命令从没加上；现在两个基类的 `init()` 都调。
- 开封 `d/kaifeng/ground.h` 的表格包进 `#ifndef GROUND_TABLES_INHERITED`，层层继承的 `ground1/2/3.lpc`、`ground.lpc` 不再各定义一份；`feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`；`yaoguai_type`、李靖 `die`/`unconcious`、玉兔 `kill_ob` 与 xyj2000 同改。
- 剩下的 `/adm/simul_efun/oo.lpc` 一条 `no side effects` 是没人包含的 `object.lpc` 旧副本单独编译的假象（KB 04 §6.10 表中 fragment 一行），不是警告。

- 2026-10-14：1 个文件的代码里有只含私用区字符（U+F8F5，GBK 转码留下的）的空行，编译器报 `Illegal character 0xef` 整份不编译；这些行清空（字符串、注释里的不动）。新进程比对 HEAD 与工作树：新增载入 1，回退 0。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:18: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/fuxing.lpc`、`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：3/3 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 4 处、4 个文件：`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`yange_blade`→`yange-blade`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 1 个：`/daemon/skill/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/sky/npc/zz-tianwang.lpc`（增长天王）：整个文件是未转码的 GBK，末尾被截断，`ask_me` 的最后一句 `return ("老夫脚正痒痒。。。` 没有收尾。照其余二十多个库里完整的同一个文件补上 `\n");` 和函数的 `}`（已转成 UTF-8），NPC 载入。

逐个载入与 HEAD 对比，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/cmds/wiz/dns.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `xupdate`：`file[sizeof(file)] != '/'` 永远为真（2026-10-21，KB 06 §7.343）

管理员扫描里 `xupdate`（xyj2000）从根目录 `/` 开始递归时报 `Bad argument 2 to foreach Expected: array Got: 0.`：`UpdateDir()` 用 `file[sizeof(file)] != '/'` 判断路径是否已经以 `/` 结尾，下标等于长度读到的是 0，条件永远成立，`/` 变成 `//`，`get_dir("//")` 答 0。改成 `file[<1] != '/'`。同一个写法在 `xrm`、`rm`、`rmdir1`、`rmhir` 里有 55 处，没有动：对普通路径新旧写法的行为相同，唯一改变的是 `xrm /`，旧写法让它死在第一个 `get_dir("//")`，改了它就能递归删光整个游戏目录。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 7 条注册（4 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）。最多的函数名：`do_push` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_vendor_list` 1 处、`do_get` 1 处。没有动（读过）：`/daemon/class/zhenyuan/taiyi/qimen2.lpc` 的 `finish`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））、`/daemon/class/zhenyuan/taiyi/qimen2.lpc` 的 `quit`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 6 个文件里有 10 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`nosave/promotion` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:102`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logindtest.lpc:940`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（guest.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。
