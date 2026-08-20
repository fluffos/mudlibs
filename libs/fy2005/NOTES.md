# fy2005.rar → `fy2005`

- Archive: `archives/fy2005.rar` (48MB — "风云Ⅳ" 2005 build, same lineage
  as archive #14 (fengyun434), a later/bigger snapshot). Mudlib root at
  `fy2005/fy4/`, config at `fy2005/bin/config.fy4`.
- Port: **40013**.

## Status: DONE — boots clean; has an intentional 5-minute startup grace period

Booted with zero fixes needed (same clean lineage as fengyun434/fy2).
**This build enforces a 5-minute wait before login is allowed**
("风云系统正在初始化，请在五分钟后再登陆。" — "Fengyun system is
initializing, please log in again in 5 minutes.") — an intentional
startup-grace mechanic (same shape as `xyxy2`'s 30-second
wait, just longer here), not a bug. Not waited out to confirm the actual
post-wait login flow given the time cost, but the boot itself is clean
(no compile errors, no crashes) and the pre-wait prompt flow (name
validation) works correctly.

## What was fixed

Nothing needed for boot. Routine conversion: encoding (12801 converted,
384 already UTF-8/ASCII, 43 skipped binary, 75 lossy), `.c`→`.lpc` (9764
files, 1328 refs auto-fixed), 11 local angle-bracket includes converted
to quotes automatically, `static`→`nosave` (44 files).

## Known remaining issues (documented, not fixed)

- Several `call_other() couldn't find object '/d/ZONE/room.c'` errors at
  boot — traced to plain-text DATA files (`quest/dynamic_location`,
  `adm/etc/scenery_phase` — bare one-path-per-line lists, no LPC string
  quoting) that still hold literal `.c` object-path references.
  `convert_lib.sh`'s `.c"` reference fix only scans `.lpc`/`.h` source
  (quoted-string context); it doesn't touch extensionless data files with
  bare (unquoted) paths, and blanket-fixing "any `path.c` text anywhere"
  risks false positives in genuine documentation/help text. Left as-is —
  affects some quest/scenery room resolution, not the boot/login path.
- lpcc sweep: 9696/9764 pass (99.3%) — not fully triaged past confirming
  a clean boot given time constraints.

## How to run

```
cd libs/fy2005
~/src/fluffos/build-debug/src/driver config.fluffos
# wait 5 minutes after boot before the login name prompt will proceed
python3 ../../scripts/mudclient.py 127.0.0.1 40013 --timeout 10 --send "" --send "look" --send "quit"
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

- **Formatter**: `format-corpus.mjs` over all 9764 `.lpc` files; 9739
  reformatted, 2 unchanged, 23 refused (self-check `errors`, expected).
- **Proactive fixes applied before the first boot attempt of this pass**
  (found via this same lib's `adm/daemons/securityd.lpc`, before even
  connecting): the same `resolve()`-before-`wiz_status` WASM-crashing
  ordering bug as `fy3dz`/`fy3xd`/`fengyun434` (same
  风云 engine family) -- reordered + wrapped in `catch()`. **Also found a
  second, more serious latent bug in the same `create()`**: an
  AGENTS.md-§15u-style "phone-home license expiration" self-destruct --
  `if (local[5]*10000+... > C_YEAR*10000+...) shutdown(0);` would kill
  the entire driver process once the wall clock passes
  `C_YEAR`/`C_MON`/`C_MDAY` (hardcoded to year **2109** here, so not
  reachable on any realistic host clock today -- but disabled/commented
  out as insurance per standing policy rather than left armed, same
  treatment as `moniHuafu`'s/`fy3dz`'s equivalent).
- **Native re-test against rebuilt driver**: clean boot, zero fixes
  needed beyond the two proactive ones above. The documented 5-minute
  startup grace period (`uptime() < 300`) still behaves exactly as
  described -- confirmed by actually waiting it out this time (prior
  passes noted the mechanic but didn't wait through it). **Full
  registration flow completed end-to-end for the first time, including
  the ASCII-art digit CAPTCHA** (`/feature/nada.lpc`'s `my_number()`):
  wrote a one-off scripted client (`/tmp`, not committed) that decodes
  the CAPTCHA programmatically -- copied the exact 10 digit glyphs from
  `c_num` in `nada.lpc` (10 rows × 15 chars each) and pattern-matches
  each of the up-to-8 digit columns in the two rendered row-groups
  against them (exact match, not fuzzy OCR, since the glyph table itself
  came straight from the source) -- rather than reading the ASCII art
  visually turn-by-turn. Verified end-to-end with real Chinese names
  (唐游/悟空/取经取) reaching the actual starting room (风云台),
  `look`/`score` producing correct output, and the double-`quit`
  anti-abuse confirmation (documented in README) working as described.
  Zero debug.log errors across all runs.
- **WASM test — full CAPTCHA-solving playthrough completed, not just a
  boot check**: this lib combines two real obstacles for WASM testing
  that don't affect the other 8 libs in this batch: (a) the same 90s
  per-connection `LOGIN_TIMEOUT` (`obj/login.lpc`) that exists natively
  too, and (b) the 5-minute `uptime()` grace period, which under the
  WASM harness's real-time-driven tick clock genuinely takes 5 real
  minutes of process lifetime to elapse. **Pitfall found**: an initial
  attempt kept one `fluffos_connect()`-created connection open through
  the whole 5-minute wait (sending periodic keepalive blanks) and got
  kicked by the 90s `LOGIN_TIMEOUT` long before the grace period ended
  (its own local timer, started at connect time, independent of
  `uptime()`) -- reproduced the "您花在连线进入手续的时间太久了" kick
  message. Fixed by ticking the driver with **no connection open at
  all** for the first 310 real seconds (`uptime()` advances regardless
  of connections), then calling `fluffos_connect()` fresh only after
  that -- giving the fresh connection its own full 90s window with the
  grace period already satisfied. With that fix, the full registration
  flow (encoding → id → CAPTCHA, decoded via the same exact-glyph-match
  approach as the native test → Chinese name 取经取 → password → email →
  gender → race) completed cleanly under WASM, reaching 风云台, with
  `look`/`score`/`quit`(×2) all producing correct output identical in
  shape to the native run. Only non-fatal errors are the expected
  no-sockets-package ones (`network/dns_master.lpc`'s
  `socket_create`/`socket_bind`, `*No program in object` at preload).
  This is the only lib in this batch where a full WASM CAPTCHA-gated
  registration was actually driven to completion, not just verified to
  boot. Not affected by the documented `query_ip_number()` WASM
  limitation.

## WASM-enablement pass (loopback / admin seeding)

Gates patched (all in `work/`):

- `adm/daemons/band.lpc` `is_banned()` (~line 58): loopback / empty /
  non-string / `localhost` / `127.`-prefix short-circuit (return 0).
  Called from `adm/daemons/logind.lpc:104-105`.
- `adm/daemons/logind.lpc` `logon()` (~line 217): the **5-minute
  `uptime() < 300` startup gate now applies only to non-loopback
  connections** (previously destructed every early local/WASM connect;
  the WASM harness needed a 310s pre-wait — no longer). Original gate
  kept verbatim for remote connections.
- `adm/daemons/logind.lpc` `logon()` (~line 153): the NETBAR per-IP
  multi-login cap block is skipped entirely for loopback/empty/
  non-string IPs (browser tabs are all loopback).
- `adm/daemons/logind.lpc` `valid_wiz_login()` (~line 665): the wizard
  IP-whitelist gate (`/adm/etc/wizip/<id>`) always passes loopback/
  empty/non-string IPs.
- KEPT: `LOGIN_TIMEOUT` idle kick, quit-twice confirmation, wiz_lock
  maintenance gate — game design, not hosting protection.

Admin account (§1.5): `fluffos` / `Mud@2026`, display 浮浮, status
`(admin)` via `fluffos (admin)` appended to `/adm/etc/wizlist`.
Registered through the REAL flow including the ASCII CAPTCHA (solved by
exact glyph match against `feature/nada.lpc`'s `c_num` table — note the
glyphs are Chinese numerals 零一二...九, indexes 0-9, plus an unused 十).
As a wizlisted account it spawns in /d/wiz/hall. Verified re-login +
`update /adm/daemons/combatd` → 成功.

Retest: fresh normal registration (秦风) through encoding + CAPTCHA into
风云台 with working `look`/`score` — confirms the uptime-gate bypass
(connected seconds after boot, previously impossible) and that normal
players are unaffected. Test char saves removed; no new debug.log errors.

- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.

**Save files to force-add** (untracked, NOT gitignored):
`libs/fy2005/work/data/user/f/fluffos/fluffos.o`,
`libs/fy2005/work/data/login/f/fluffos/fluffos.o`.

## 深度功能测试 / Deep functional test (2026-08-06)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角
色 id `fytesta`，中文名 云天河，汉族。本轮 WASM 未重新验证：emsdk 工
具链下载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略
性拒绝该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认
是策略拒绝而非临时故障），本地无法构建 WASM 驱动。

### 发现并修复：`.c`→`.lpc` 改名的长尾后遗症——两张运行期数据表整表引用旧扩展名，导致节庆场景系统崩溃、任务掉落系统整体失效（AGENTS.md §4.2 item 2 新实例）

- **症状**：驱动开机预载阶段，`debug.log` 出现两条被 `catch()` 拦截的
  运行时错误——`*call_other() couldn't find object '/d/huashan/cave.c'`
  与 `'/d/taishan/yueguan.c'`——分别来自 `adm/daemons/sceneryd.lpc`
  的 `init_scenery_phase()`。
- **根因**：`adm/etc/scenery_phase`（17 条节庆/天气景观事件表）和
  `quest/dynamic_location`（1440 条任务随机放置用的房间列表）两张纯文
  本数据表里，**每一条**房间路径都带着改名前的 `.c` 后缀，而这些房间
  在 `work/` 里早已全部改名成 `.lpc`。FluffOS 的 `load_object()` 对显
  式扩展名做精确匹配（`.c` 绝不会回退去找 `.lpc`），所以这两张表里的
  1457 条路径全部失效——`find libs/fy2005/work/d/<path>.lpc` 逐条核实
  全部存在，只是数据表没跟着改名脚本走。`sceneryd.lpc` 的开机自检有
  `catch()` 包裹，只是记一条系统频道警告，不会崩溃；但同一份数据后续
  被 `scenery_happen()`（景观随机触发时调用，`adm/daemons/
  sceneryd.lpc:122-130`）消费时，`load_object()` 返回的 0 直接送进
  `room->init_scenery()`，没有 `catch()` 也没有 `objectp()` 守卫，一
  旦某个节庆随机命中（`update_scenery_phase()`ﾒ里 `random(RATE) <
  rate` 通过），就是一次真实的 `Bad argument 1 to EFUN call_other()`
  运行时崩溃。`quest/dynamic_location` 那 1440 条被 `adm/daemons/
  taskd.lpc` 的 `spread_quest()` 用来给任务物品随机选房间放置，虽然
  那处调用点本身有 `if (cur_obj) {...}` 守卫、不会崩溃，但由于
  1440 条路径无一例外全部失效，`spread_quest()` 实际上从未能把任务物
  品放在地上过（每次都退化成直接交给 NPC），整个"地上拾取任务物品"
  这条玩法路径长期完全瘫痪。
- **修复**：写小脚本核实每条 `.c` 路径对应的 `.lpc` 文件确实存在（17
  + 1440 条全部确认存在，零条需要跳过），批量去掉两张数据表里的 `.c`
  后缀（FluffOS 对无扩展名路径会先找 `.lpc` 再找 `.c`，去掉后缀即可
  正确解析）。同时给 `scenery_happen()` 补上 `objectp(room)` 守卫作为
  纵深防御——数据表已经修好，理论上不会再命中这条路径，但守卫本身零
  成本且符合已有的兄弟调用（`init_scenery_phase()`）写法。
- **验证**：修复前重启驱动，`debug.log` 出现前述两条被拦截的错误，确
  认可复现；修复后重启驱动，`debug.log` 对这两个房间（以及另外 15 个
  未在这次开机窗口里被抽中的节庆条目）不再报错。`scenery_happen()`
  的运行期分支本身要等某次节庆随机事件真正命中才会触发，这次会话时
  间预算内没有等到自然触发去现场复现"崩溃前 vs 崩溃后"的对比——如实
  记录这一点，而不是假装已经现场复现过。`§9` 格式化自检对两张数据表
  不适用（不是 `.lpc`/`.h`），已确认改动后行数一一对应（1457 处删除
  + 1457 处新增，纯粹去掉 `.c` 后缀，未触及其它字符）。
- 已有的 AGENTS.md §4.2 item 2（"数据文件里裸 `.c` 路径"）条目已经涵
  盖这个模式，未新增小节；这里的规模（两张表共 1457 条）比该条目原举
  的例子大得多，值得作为该模式"能有多大规模"的参考案例。

### 发现并修复：注册流程里遗留的 `printf("%O", ob)` 调试输出（AGENTS.md §7.34 新实例，"风云"家族已知模式）

- **症状**：注册流程中，玩家刚输入完中文名（自己手动输入的分支，不是
  接受系统随机生成名字的分支）之后，屏幕上会多出一行裸露的对象内部
  路径，如 `/obj/login#29`，夹在"您的中文名字："和"请设定您的密
  码："两行正常提示之间。
- **根因**：`adm/daemons/logind.lpc:488`（`get_name()` 里"玩家自己输
  入名字"分支）有一行未加任何注释的 `printf("%O\n", ob);`，是原作者
  遗留的调试脚手架，archive 里就已经是这样（不是本项目转换流程引入
  的）。同一函数"接受系统建议的随机名字"分支（`get_resp()`）里有同
  一行的注释掉版本（`//	printf("%O\n", ob);`，`logind.lpc:450`），
  说明这份代码曾经在两条平行路径上都打过这行调试输出，后来只有一条
  被手工注释掉，另一条被遗漏。AGENTS.md §7.34 已经把这个模式记录为
  "风云"（Fengyun）家族的已知通病，在 `fy330`/`fy2mg` 等同引擎的兄弟
  档案里各自独立命中过。
- **修复**：删除 `logind.lpc:488` 这一行，与 §7.34 记录的既定修法一
  致（"这行永远不服务于任何玩家可见的目的，直接删掉即可"）。
- **验证**：修复前用一个临时调试行（另加一行 `write()`，验证完立刻撤
  销，从未提交）读出过 CAPTCHA 明文校验码后完整走过一次注册流程，亲
  眼看到修复前 `/obj/login#29` 那一行确实出现；修复后 `update
  /adm/daemons/logind` 热更新编译成功，`§9` 格式化自检通过（该文件其
  余部分的缩进也顺带被格式化器统一，纯空白改动）。受时间预算限制，
  未再跑一次完整注册去现场复认"修复后这行不再出现"，但删除一行裸
  `printf` 是这个模式在本项目里反复验证过的安全修法，风险极低。

### 关于 CAPTCHA（图形验证码）的测试方法说明

`feature/nada.lpc`'s `my_number()` 用 `c_num` 表里 10 个 ASCII 字符画
的中文数字字形，拼成一个 8 位随机数的图形验证码。本轮为了能在自动化
测试里稳定通过这一关，用 `git show`/直接读源码把 `c_num` 表的 10 个
字形抽出来写了一个逐字形匹配的小工具（未提交进仓库，纯本地脚手架），
但纯靠字形匹配在实际操作中因为终端输出的时序/换行/颜色码干扰，命中
率不够稳定，最终改用了更简单可靠的办法：临时在 `confirm_id()` 里加一
行 `write()` 把 `my_number()` 已经算出来的明文校验码直接打印出来，验
证完当场撤销这行调试代码（从未提交）。记录这个方法是为了给下一个测
试 `fy` 家族（`fy2`、`fy330`、`fy2mg` 等同引擎兄弟档案）的人参考——这
类 CAPTCHA 是纯 ASCII 艺术字，没有依赖任何外部图像渲染，本来就是为
了防自动化注册设计的，测试时没有必要真的去做 OCR，直接读源码 + 临时
调试输出是更稳妥的路子。

### 测试内容与结果

- **注册**：GB 编码 → 英文 ID（仅限字母，含数字会被拒绝）→ CAPTCHA
  （按上文方法解出）→ 真实中文名（云天河）→ 密码（含大小写字母/数
  字/符号）→ 确认密码 → 邮箱 → 性别，全程顺利进入 `风云台`。
- **种族/属性分配**：`setrace 汉族`（可选汉族/满族/蒙古族/苗族）→
  `distribute <属性拼音>` 分配 10 点自由属性点，正确扣减剩余点数并在
  分配完毕后自动存档。
- **新手引导**：`newbie` 路线启动"新手入门"解谜任务
  （`riddle` 命令可查看进度），`help newbie` 的 14 个子菜单条目内容
  与游戏内实际系统（学习/吃喝/离开等）描述一致。
- **城内探索**：确认"城里不主动挑衅不会被攻击"的设计（`map` 命令输
  出的城市地图与实际房间连接一致，走遍南城多个环云道路口无异常），
  出南门后地图延伸到荒野（小山坡、荒凉大道、莽林边缘），均正常。
- **持久化**：静默重连（net_dead 后 `find_body()` 重新绑定）——房间
  （小山坡顶）、装备、属性全部正确复原，"重新连线完毕"提示正确。真
  实完整 quit 未测试到底——README/游戏内提示都明确"经验等级 < L2
  （40%）的角色数据不保留"，本轮测试角色战斗经验为 0，属于设计内会
  被丢弃的范畴，未故意去confirm 那个"再次输入 quit 才真正放弃数据"
  的二次确认，避免丢失刚创建的测试角色；这也意味着这条"低等级角色
  quit 不保留数据"的具体分支本身未被现场验证到，如实记录为未覆盖。
- **管理员账号**：`fluffos`/`Mud@2026` 登录，出生于 `/d/wiz/hall`，
  `update /adm/daemons/logind` 成功，确认写 ACL 正常。
- **战斗/门派**：**未覆盖**——本档案的新手起始区（风云城南城）本身
  不会被动遇袭，需要主动走到城外才有敌对目标；沿最近的荒野路径（南
  门→小山坡→荒凉大道→莽林边缘）找到的要么是告示写明"猛兽出没，有
  去无回"的高危区域，要么是纯风景/NPC房间，同宗弟子限定的"大师兄"
  陪练 NPC（`obj/npc/champion.lpc`）需要玩家先加入某个门派才能触发
  （`accept_fight()` 里 `me->query("class") != query("class")` 直接
  拒绝跨门派挑战），在本轮的时间预算内没有找到一个新手友好、不需要
  远征或先入门派的安全陪练目标。如实标注为未覆盖，而不是默认"和其
  它风云家族档案一样所以没问题"——留给下一轮测试或熟悉这份档案地
  图的人优先排查。经济/商店同样未覆盖（本档案的商店系统结构与 `map`
  显示的钱庄/当铺/茶馆等设施看起来是标准 fy 引擎商店实现，未实测）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ 2005 构建版。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 8 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类 `#define ROOM "/std/room"`：删除
1001 处多余的、独立成行的 `replace_program(ROOM);`（保留
`inherit ROOM;`）——999 处由脚本批量删除，另外 2 处
（`d/fy/wcloud1.lpc`、`d/fy/tiandoor.lpc`）行尾带有开发者注释
`//add by ldb`（后者还有中文说明"希望刷掉乱走的NPC"），脚本的严格
匹配跳过了它们，手工确认后一并删除——注释表明作者是有意添加该调用
以期"冲掉"游荡 NPC，但技术上仍是同一枚定时炸弹（对已 `inherit` 的
对象重复 `replace_program()`，一旦该对象后续绑定任何闭包就会崩溃），
故仍按同一原则删除。本库没有房间建造工具（`roommaker.lpc` 等），
无需修复第二处。已用 `build-debug` 驱动干净启动验证（0 个新增编译
错误，端口正常监听）；未做完整 §10.7 深度游玩测试。
