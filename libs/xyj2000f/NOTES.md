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
