# bxsj1.rar → `bxsj1`

- Archive: `archives/bxsj1.rar` (23.8MB — "书剑·经典"/"ShuJian Classic",
  the SAME lineage as archive #4 (`bxsj.rar`/书剑天下), but a much more
  complete/later snapshot: bundles production driver binaries for
  multiple platforms (Windows/Cygwin, ARM, MIPS) plus leftover
  `.exe.stackdump` crash dumps from real prior usage.
- Mudlib root in archive: `bxsj1/shujian/` (config at `bxsj1/bin/
  config.sj`, sibling to a `bin/` dir of platform binaries — all ignored,
  we use our own driver). `mudlib directory : /home/sjmud/shujian/` in
  the shipped config is the original server's absolute path — overridden
  as always.
- Port: **40005**. 9938 `.lpc` files — similar size to bxsj.

## Status: DONE — boots clean, playable over telnet

Reached name entry / length validation / existing-ID detection / password
prompt, same as bxsj. Given the shared lineage with archive #4, the three
bugs found there (AGENTS.md §4/§8/§8c/§14) were applied **proactively**,
before ever attempting a first boot, by checking this lib's `master.lpc`/
`securityd.lpc` for the identical code shapes first — confirmed present,
fixed immediately, and the lib booted clean on the very next attempt (only
the `log_error()`/`CHANNEL_D` guard's benign caught-error log lines showed
up, matching bxsj's known-fine post-fix behavior, not a new problem).

## What was fixed

Same three fixes as `bxsj` (see that lib's NOTES.md / AGENTS.md §8/§8c/§14
for the full write-up), applied directly since this is the same codebase
lineage:
1. `master.lpc` `log_error()`: added the reentrancy-guard + `catch()`
   around `CHANNEL_D->do_channel(...)`.
2. `master.lpc` `valid_override()`: added the 3rd `main_file` parameter,
   plus the `shout`/`write`/`tell_object`/`tell_room`/`say` allow-list.
3. `securityd.lpc` `valid_read()`: only fall back to `this_player()` when
   the passed-in `user` has no resolvable euid/uid of its own.

Plus the routine per-lib steps: encoding (10883 converted, 743 already
UTF-8/ASCII, 37 skipped binary, 39 lossy), `.c`→`.lpc` rename (9938 files,
836 refs auto-fixed, 0 left over), `static`→`nosave` (197 files + 2 more
fixed by hand — **found a `convert_lib.sh` bug here**: a filename
containing a literal space (`"char - 副本.lpc"`, a Chinese-annotated
backup/duplicate file — "副本" = "copy") broke the newline-delimited
`xargs` pipe in the static-fix step, silently skipping just those 2
files. Fixed the script to use NUL-delimited (`-print0`/`grep -Z`/
`xargs -0`) throughout that step, matching how the `.c"`-reference-fix
step already did it correctly.

## Known remaining issues (documented, not fixed)

Same shape as `bxsj`: 74 lpcc-sweep failures, dominated by
`Bad type for argument 1 of is_killing`, `Undefined function
set`/`set_temp`/`query_lord`/`change_state`, a few `Illegal character`
(genuine source typos, not individually triaged), and the two expected
`#include`-fragment false positives (`adm/simul_efun/{message,object}` —
AGENTS.md §6b, confirmed harmless in a real boot).

## How to run

```
cd libs/bxsj1
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40005 --timeout 10 --send "n" --send "testuser" --send "quit"
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

## Retroactive fix (found via archive #90, jinyongwenzi): this lib was completely command-dead after registration (AGENTS.md §15ae + a new commandd.lpc variant)

Same shared lineage as `bxsj` -- carried the identical two bugs `bxsj`'s
own NOTES.md documents in full: `feature/command.lpc`'s `command_hook()`
was `private nomask` (§15ae, unreachable via `add_action`'s external
dispatch), AND `adm/daemons/commandd.lpc`'s `rehash()` used a live
`sscanf(cmds[i]+"$", "%s.c$", cmds[i])` that never matched anything after
the `.c`→`.lpc` rename, leaving `commandd`'s command table permanently
empty. Both fixed (dropped `private`; sscanf pattern → `"%s.lpc$"`), then
re-verified with a fresh full registration (real name "秦河") followed by
`look`/`score`/`quit` all producing correct output, `debug.log` clean (0
`error:` lines). See `bxsj`'s NOTES.md for the full discovery story --
this lib's own original testing pass had the same blind spot (never
tested a post-login command), so it was silently broken since first
marked "done."

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (9,938
  files, 6,195 written/reformatted, 3,589 already-clean, 154 refused
  with an error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦哲`, ID
  `qinzhe`) through the same flow documented in `bxsj`'s sibling NOTES
  (ID → password requiring a digit+uppercase and rejecting an
  ID-derived password → Chinese name → talent roll → email → gender),
  reaching the actual game world (武馆前院 starting room) with the
  welcome-NPC escort (`狄云`) firing correctly; `look`/`score`/`quit` all
  produced correct output (full 个人资料卡 stat card rendered correctly),
  zero real errors in `debug.log`. No regressions from the reformat or
  the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/network/dns_master.lpc`'s
  `socket_create`/`socket_bind`/`socket_close` → `Undefined function`,
  caught non-fatally, `Initializations complete.` still printed).
  Registration is blocked by the same documented `query_ip_number()`
  WASM-mode limitation as `bxsj` (same lineage, same
  `adm/daemons/sited.lpc`): every ID attempt is rejected with "对不起，
  这个英文名字不能从当前地址登录。". **Not a mudlib bug** — the
  documented driver-side gap, not something to patch. Verdict: boots
  cleanly under WASM; registration cannot complete due to the driver's
  IP-check limitation.

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched (ported from sibling bxsj; loopback/malformed-empty IP short-circuits first, original logic intact):

- `adm/daemons/band.lpc` `is_banned()` (~line 40): loopback/`127.` prefix/
  non-string/malformed IP → return 0.
- `adm/daemons/sited.lpc` `is_valid()` (~line 37): loopback → return 1.
  `is_multi()` (~line 68): loopback → return 0 (multi-login throttle exempt;
  `IP_D->ip2name` moved below the guard).
- `adm/daemons/logind.lpc` `logon()` (~line 95): per-IP concurrent-connection
  cap (`login_cnt > 3`) applies only to real remote dotted-quads now.
- No uptime() startup gate in this lineage (uptime() uses are content timers).
- `get_id()`'s quit-retention 30s re-login block (`last_on < 30`) KEPT (game
  design, and wizards are exempt in original code).

New real bug found & fixed during admin verification (bxsj1-only drift):
`feature/dbase.lpc` declared `tmp_dbase`/`default_ob` as `protected`
(sibling bxsj has `nosave`, original MudOS had `static`). `protected` is a
visibility modifier, NOT save-exempt, so `default_ob` (set to
"/adm/daemons/race/human.lpc" during play) was PERSISTED into player saves
and restored at next login BEFORE the body had an euid -- the first dbase
query for any missing key then did `default_ob->query(...)` which tried to
load the race file with no effective user: `*Can't load objects when no
effective user`, breaking every command for that character (symptom hit
the admin account first because its save was created/restored across a
restart). Fixed both to `nosave` (dbase.lpc lines 10/16) and stripped the
stale `default_ob` line from the existing fluffos save. §4.3-class bug.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, granted `(admin)` via
`adm/etc/wizlist` (winker entry preserved). Verified `update
/d/wizard/wizard_room` recompiles successfully and wizard start room works.
**Save files for the orchestrator to force-add:
`libs/bxsj1/work/data/user/f/fluffos.o` and
`libs/bxsj1/work/data/login/f/fluffos.o`** (untracked dirs).

Retest: fresh normal registration (id `ceshiyi`, name 秦风) end-to-end into
武馆前院, look/score/quit all correct, 0 new errors in debug.log; test char
saves removed. fluffos login + update + goto verified, 0 new errors.


## Retrofit (2026-07-24): fail-closed loopback check (security correction)

The loopback-allow gate patched above originally also treated a
non-string/empty/malformed `query_ip_number()` result as loopback (a
defensive stand-in for the WASM driver bug). That driver bug is now fixed
upstream, so this was tightened to fail-closed: only an exact
`"127.0.0.1"` / `"127."`-prefix / `"::1"` match bypasses the gate; a
malformed or non-string address now falls through to the original gate
logic (treated as untrusted/remote) instead of being auto-allowed.
Re-verified fluffos login still works after tightening.

## Proactive fix (2026-07-24): rank-decay loop crashed every `quit` (AGENTS.md §7.16/§10.7)

Found while pattern-matching a bug discovered on sibling `bxsj` during that
lib's first deep functional playthrough (AGENTS.md §10.7 methodology),
before ever booting this lib for the check. `cmds/usr/top.lpc`'s 5
`add_rank*()` functions each decay a stale rank entry's score via
`while (ranks[i]["time"] + 3600 < t) { ... }` with no iteration cap. The
shipped `work/log/rank.o` carries real timestamps from 2008
(`"time":1219369347`), so on any boot against today's wall clock the loop
runs ~150,000+ iterations per stale entry and blows the eval-cost limit.
`cmds/usr/quit.lpc:218` calls `TOP_CMD->add_rank(me)` unconditionally on
every `quit` — so every `quit` was silently crashing (driver's error
handler swallows it; the player-visible "正在退出游戏……" message looks
normal). Fixed all 5 copies (`add_rank_beauty`, `add_rank_pk`,
`add_rank_rich`, `add_rank_worker`, `add_rank`) the same way as `bxsj`:
cap the loop at 240 iterations (~10 days of decay, enough to crush any
stale score near zero) and unconditionally advance the stored timestamp
to `t` afterward regardless of whether the cap was hit. Compile-checked
clean via `lpcc --batch`; not re-verified live in this lib specifically
(verified live on `bxsj`, the source of the pattern) — flagging per
§10.7 point 6 rather than silently claiming a live retest.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一套"书剑"代码库（书剑·经典）。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：一次完整的 WASM 注册流程（英文 id 仅限小写字母、3-8 位 → 确认 → 管理密码/登录密码分别设置+确认，密码需含数字和大写字母 → 中文名字 → 天赋摇点，0 为随机 → 接受 → 电子邮件，需 id@address 格式 → 性别）全程无错误地进入起始区域，预先播种的管理员账号（fluffos/Mud@2026）也能正常登录（"您目前的权限是：(admin)"）。和 bxsj（004）是同一套底层引擎——共享的那个真实历史 bug（top.lpc 排名衰减循环）和深度测试覆盖情况见 bxsj 自己的说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-06)

第一次真正的完整游玩测试（此前所有测试都只覆盖了注册+`look`/`score`/`quit`
或纯编译检查）。原生驱动（`build`，ASAN/UBSAN debug 构建），测试角色
id `qintwo`，中文名 秦风，密码 `Abc12345`——保留未清理，已加入武当派，
留作有效状态的活证据。本轮 WASM 未重新验证：emsdk 的工具链下载硬编码
指向 `storage.googleapis.com`，本次会话的出口代理对该域名返回策略性
403（已通过 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策略拒绝而
非临时故障），因此本地无法构建 WASM 驱动；在 WASM 侧的状态维持上一轮
（README/`meta.json`）记录的结果不变。

### 结论：本轮未发现新 bug，此前的主动修复在真实 quit 中持续有效

`cmds/usr/top.lpc` 的 5 处 `add_rank*()` 迭代上限修复（2026-07-24 从
`bxsj` 主动移植，见上方条目）此前只做过编译检查，未在 `bxsj1` 自己身
上真正触发过 `quit`。本轮多次真实 `quit`（含首次注册后的 quit、学艺
后的 quit、加入武当后的 quit）全部干净——`debug.log` 全程无
`Too long evaluation`/任何运行时错误（只有 `SAVE_EXTENSION` 宏重复定
义和 `valid_learn` 参数数量不一致这两类良性编译期警告，与其它同族档
案已知一致，非本轮新问题）。确认这条此前只经编译检查、未经真实
quit 验证的修复，在这份档案自己的存档数据下同样成立。

### 测试内容与结果

- **注册**：真实中文名（秦风），完整流程（英文 ID 仅限字母，纯字母数
  字组合会被拒绝 → 密码含数字+大写字母，二次确认 → 中文名 → 天赋摇点
  0=随机 → 确认 → 邮箱 → 性别）全程无错误进入 `武馆前院`。
- **新手引导链**：`answer y` 触发 狄云→孙均 的教学对话（`ask sun about
  学习`/`about 襄阳武馆`），指令讲解正确发放经验/潜能奖励；`help
  map_wuguan` 输出的 ASCII 地图与房间实际出口存在若干处细节不完全一
  致（例如"碎石路"房间描述写"南面是一间偏厅"，实际房间名是"练功
  房"）——这是地图/房间描述这类**内容层面的历史小出入**，不影响任何
  指令/寻路的正确性，按 §10.7 的 scope 规则不作为 bug 处理。
- **战斗**：`d/wuguan/wuchang4`（东武场）的 `muren`（木人）陪练目标，
  `fight muren` 产生完整的攻防叙事，在约 50% 资源阈值正确自动终止
  （"这场比试算我输了，佩服，佩服！"），无崩溃。
- **技能**：组织路线——`东练武场`的 `武馆教头`（`recognize_apprentice()`
  硬编码为真，教任何人）`cha jiaotou` 查看技能表、`xue jiaotou cuff`
  学习成功。`enable strike taiji-quan` 正确拒绝（"这个技能不能当成这
  种用途"，因为 `taiji-quan` 实际映射到 `cuff` 而非 `strike`）、
  `enable cuff taiji-quan` 正确成功——与 `bxsj` 记录的结论一致，不是
  bug。
- **门派**：两条路径均验证——(1) 礼物使者捷径：`ask shizhe about
  newbie`→`about 拜师`→`about 武当`，清空技能后一次性授予武当全套特
  殊技能并传送至三清殿；(2) 组织路线：传送后对宋远桥 `bai song`，第一
  次执行了完整拜师流程（而不是像 `bxsj` 那样直接识别为"已是同门"——两
  种实现都不是 bug，只是这份快照里 `family`/`is_apprentice_of` 判定在
  礼物使者赠送和真实拜师之间不完全共享状态，行为上仍然幂等且正确：紧
  接着再次 `bai song` 就正确识别为"已经磕头请安"，不会重复消耗）。
- **持久化**：(a) 静默重连（net_dead 后 `find_body()` 重新绑定）—— 房
  间、装备、状态零丢失；(b) 完整 `quit`+重新登录（真实 `save()`/
  `restore()`）——门派身份、技能表、贵宾状态全部正确复原；`quit` 时
  非 `autoload`/`unique` 的普通衣物（布履/布衣、道袍）被丢弃，与
  `bxsj` 记录的原始设计一致（反屯积机制，非存档 bug）。
- **管理员账号**：`fluffos`/`Mud@2026` 登录显示 `(admin)`，`update
  /d/wuguan/dayuan` 成功重新编译，确认写 ACL 正常。
- **经济/商店、死亡/复活**：**未做实测**，与 `bxsj` 记录的缺口相同——
  `inherit/room/shop.lpc` 与 `bxsj` 的版本逐字节相同（`diff` 确认），
  已在 `bxsj` 一侧做过代码级审查、未发现红旗；`feature/damage.lpc` 的
  `die()`/`reincarnate()` 路径同样与 `bxsj` 共享，本轮测试角色被礼物
  使者一次性拉高到与附近 NPC 明显不对等的强度（综合评价 3615+，技能
  ~201），要在合理时间预算内制造一次真实、可控的死亡不现实（需要专门
  跑去找一个够格的对手，或回程翻越到武馆重新用 `kill muren`/
  `suicide -f`）。如实标注为未覆盖，而非默认"和 bxsj 一样所以没问
  题"。

## 商店/死亡缺口关闭 (2026-08-23): 全新非增强测试角色，全程干净

按 §10.7 方法论把上面标注的两处"未覆盖"缺口真正跑通，而不是继续沿用被
礼物使者拉到综合评价 3615+ 的旧角色。全新注册一个完全没走礼物使者捷径
的角色（id `qincetwo`，中文名 秦乐，`answer n` 跳过新手引导），保持在
出生即有的基线状态（膂力18/悟性22/根骨26/身法14，综合评价0，无任何
技能/门派）。原生驱动（`build-debug`），双 `tmux_mud.sh` 会话（测试角
色 + 管理员 `fluffos`），全程 Chinese 文本经交互式 `sendread` 确认无
乱码（未触发 tmux 转发的 mojibake 假警报）。

**商店购买（真实成交，非仅"资金不足"路径）**：管理员用
`call qincetwo->move("/d/xiangyang/zahuopu.lpc")` 把测试角色传送到牛老
板的杂货铺（与 `bxsj` 那次测试用的是同一家店），`goto qincetwo` 跟过
去，`clone /clone/money/silver` + `clone /clone/money/coin` 变出货币道
具，`call coin_money->set_amount(50)` 调整数量后用标准 `give` 指令交给
测试角色（一两白银 + 五十文铜钱 = 150 文等值），这是一条纯测试用的资
金注入捷径（`clone`/`call`/`give` 都是既有指令，不是新写的辅助工具，
用完未留任何痕迹）——因为这份档案和 `bxsj` 一样没有任何在游戏内直接发
钱的巫师指令。`list` 确认灯笼(denglong)标价"一两白银又四十文铜钱"
（=140，与 `feature/vendor.lpc`
`query_goods_value()`：`value(100) * (140-0)/100 = 140` 的公式手算结
果一致）。`buy deng long` 成交后 `i`：五十文铜钱+一两白银 → 十文铜钱
（150-140=10，`adm/daemons/moneyd.lpc` `player_pay()` 找零逻辑算出
`cc=10,sc=0,gc=0`，用完的白银道具在 `set_amount(0)` 后从物品栏里干净
消失），灯笼正确出现在物品栏里。找零和物品数量与手算完全一致，`list`
里的库存也从 5/5 正确扣到显示"库存"减一（实际输出的库存/总量行未重新
截图确认，但 `buy` 指令本身无报错）。这条路径此前 `bxsj` 只验证到"没
钱→拒绝"，这是本档案家族第一次真正验证"有钱→成交→找零"全链路。

**死亡/复活（真实 `die()` 触发，完整链路）**：管理员在同一房间对测试
角色执行 `smash qincetwo`（`cmds/wiz/smash.lpc`，`present()` 要求同室，
直接调用 `ob->die()`，绕过战斗）。观察到完整流程：击杀播报 → 秦乐倒地
死亡 → 移入 `鬼门关`(`d/death/gate.lpc`) → `阎罗大殿`(`d/death/npc/
yanluo.lpc`，`#include "death.h"`) → 5 段 `death_msg` 对话链（"喂！新
来的，你叫什么名字？"…"罢了罢了，你走吧。"）→ `reincarnate()` → 因
`enter_wuguan` 标记为真而送回 `武馆前院`（`START_ROOM`，与该角色注册
时进入的房间一致）。全程约 60 秒（`death.h` `init()` 里
`call_out("death_stage",40,...)` 首段延迟 + 4 个 5 秒间隔段）。复活后
`score`：`死亡：一次`，`上次遇害：被闪电劈死了`，均与 `smash.lpc` 的
`set_temp("last_damage_from","被闪电劈")` 一致。`death.h` 本身已经带有
`death_stage_active` 的 `query_temp`/`set_temp` 重入防护（此前
AGENTS.md §7.112 corpus 扫描已覆盖过这份文件的血统，本轮未发现需要新
增修复）。

**结论：本轮商店/死亡两条路径全程零 debug.log 报错**——`work/log/
debug.log` 在测试全程（注册、传送、变钱、购物、死亡、复活、双方
`quit`）始终不存在（0 行）；驱动进程全程存活，退出前用真实 PID
`kill`。未发现任何新的编程错误——两条路径的代码（`feature/vendor.lpc`
`do_buy`、`adm/daemons/moneyd.lpc` `player_pay`、`d/death/npc/death.h`
`death_stage`）都严格按预期执行，找零/库存数学和死亡状态机均可验证为
正确，无需任何代码改动。至此这份档案再没有"未覆盖"的 §10.7 缺口。

测试角色存档（`work/data/user/q/qincetwo.o`、`work/data/login/q/
qincetwo.o`）测试后已删除；管理员账号 `fluffos.o` 的位置/在线时长/食
水等纯会话状态字段也已 `git checkout` 还原，不留存档噪音。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Sibling of `bxsj` (diverged
fork, not byte-identical, but shares this exact bug in the same 24
files). 24 live `replace_program(ROOM);` occurrences deleted
(`d/wanshou/*.lpc`, `data/group/groom/*.lpc`,
`d/cangzhou/dangpu.lpc`). No roommaker.lpc factory-bug variant. Verified
via a clean native driver boot (zero new `debug.log` errors, port
listening, killed by exact PID after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death.h`, `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19), and
byte-identical to the sibling fix on `bxsj`: this lib's
`feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()`/`reset_me()` chain --
confirmed via a body-aware static scan of every `init()` in this lib: 5
NPC files call `setup()`/`reset_me()` from `init()` (e.g.
`data/group/npc/hufa.lpc`, `d/gb/npc/xixia-wushi.lpc`,
`d/gb/npc/xiaox-wushi.lpc`), after `create()` already made the object
`living()`. Calling `enable_commands()` a second time on an
already-`living()` object makes the driver re-invoke that object's own
`init()` as a side effect, re-entering the same chain while the
original call is still on the stack -- genuine reentrancy, crashing
with "Too deep recursion" (most likely on an NPC's first-ever
preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup()`
both call `enable_player()` again while the object is still `living()`.
This confirms a bare `if (living(this_object())) return;` guard would
be the WRONG fix -- used the same true reentrancy-flag fix as `mhxy`
instead: a `nosave private int in_enable_player_now;` set for the
duration of the wrapper's body, guarding only genuine same-call-stack
reentrancy while leaving every legitimate re-enable (revive/wakeup)
unaffected. `enable_player()` had a single fall-through exit (no early
`return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py bxsj1 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 514 个 `.lpc`。HEAD 与工作树分别加载（新进程）：504 -> 504 通过，无回退。
手工：`include/globals.h`（每个文件都会自动包含）先 `#define SAVE_EXTENSION __SAVE_EXTENSION__`，第 28 行又 `#define SAVE_EXTENSION ".o"`，每个对象编译时都报一次 `Macro 'SAVE_EXTENSION' redefined`（启动时 23 次）。驱动的 `__SAVE_EXTENSION__` 就是 `".o"`，删去第二个定义，值不变。`clone/obj/genmap.lpc`、`traverser.lpc` 的空 `DEBUG` 宏改成调用空函数（`scripts/lpc_nitan_family_fixes.py`）。

启动时警告 36 -> 0；新进程登录（编码选择、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 20 -> 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

把 bxsj 今天两轮编译警告修复（`00dacc346b9`、`9624dde6015`）移植过来：`scripts/lpc_twin_port.py classify --pre 00dacc346b9~1 bxsj bxsj1` 判定 56 个文件全部是孪生（52 个格式化差异、4 个原样），`adopt --apply` 一次改完，无需手工。内容同 bxsj NOTES 的“编译警告收尾（一）（二）”：11 个阵法技能的 `query_action()` 改 `mixed`、`equip.lpc` 的 `ob_hit()` 改 `mixed`、`kill_ob()` 改 void、5 处多余 inherit；`huanjing2003` 同名变量在一条声明里写两遍、16 个 `FIGHTER` 子类的 `str_menpai` 改名 `npc_menpai`、`d/city/npc/r_name.h` 姓名表改名 `c_*`、`mengdie_npc*` 多余的 `skills_pfm.h` 包含、`dzxy.lpc` 的 `attack_action` 改在 `create()` 赋值、`runner.lpc` 的 `path` 改名 `route`、`robber*.lpc` 的 `#undef NAME_D`、`mygift*.lpc` 的 `?:`、两处注释里的 `/*`。

移植后全库扫描警告为 0（`scripts/lpc_warnings.py bxsj1`），本库没有另外的遗留。改动文件及包含/继承改动文件的对象共 87 个，HEAD 与工作树各载入一次（新进程）：86 -> 86 通过，87 个对象载入无回退（唯一失败的 `adm/daemons/huanjing2003/temp/hj_room_created` 在 HEAD 也载入失败，是运行时生成的临时房间）；`lpc_audit_removed_locals.py` 0 处待查。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。12 个文件 21 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/fanchang`、`/kungfu/skill/hujia-daofa`、`/kungfu/skill/huntian-qigong/huntian`、`/kungfu/skill/lanhua-shou`、`/kungfu/skill/longxiang-boruo/fanchang`、`/kungfu/skill/yiyang-zhi`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-shengong`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`、`kuangwu`）；`qimen_baguazhen`→`qimen-baguazhen`（`suibo-zhuliu/wuzhuan`）；`xixing-dafa`→`xixin-dafa`（`tianlong-shengong`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuantia-wuji`→`xuantian-wuji`（`xuantian-wuji/wuji`）。

## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：任务系统 `job_area.h` 的 `get_arearoom()` 在 `keys(room)` 报错。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、3 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/cloth/cloth`、`/d/city/obj/blade`、`/u/lius/wudang/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 3 个，没有退步。

## `clone/spec/putao` 的 `long` 里引号错位（2026-10-18，KB 03 §4.6）

`set("long","这是一串由达摩传入中土HIG"神奇葡萄"NOR"，……")`：开引号落在 `HIG` 后面而不是前面，字符串在 `HIG` 处就闭合了，后面的 `神奇葡萄` 成了代码（`Illegal character 0xe7`），整个物件载入不了。把引号挪到 `HIG` 前面（`中土"HIG"神奇葡萄"NOR"，`，与同系其他库的同名文件一致）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/shaolin/npc/xuan-du.lpc` 的 `#include "/u/hunthu/npc/xuan-du.h"` 改成 `/kungfu/class/shaolin/xuan-du.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon_combo`←sje：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/kungfu/skill/anran-zhang/jishi.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/clone/npc/mj.lpc`（3 处）、`/cmds/group/glist_new.lpc`（2 处）、`/d/city/npc/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 峨嵋 `d/emei/npc/jing-xin.lpc` 找不到 `nigu.h`，静心师太加载不了（2026-10-20，KB 04 §6.24）

这个 NPC 是 `kungfu/class/emei/jing-xin.lpc` 的副本（文件头注释还写着原来的路径），`#include "nigu.h"` 却没有跟着改：`nigu.h` 只在 `kungfu/class/emei/` 里，`d/emei/npc/` 下没有，所以静心师太从来加载不了（登录调查的游戏阶段控制台 5 次 `/d/emei/npc/jing-xin.lpc:5: error: Cannot #include nigu.h`）。改成绝对路径 `#include "/kungfu/class/emei/nigu.h"`，不复制头文件（两份会各自漂移）。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过，无退化。同一家族的六个库（bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2）是同一处。

## `exchange` 指令：数据库结果还没检查大小就取下标（2026-10-20，KB 06 §7.324）

`cmds/usr/exchange.lpc` 的 `Update_Credit()` 在声明里就读 `ret[0][0]`，下一条语句才检查 `sizeof(ret) == 1`：博物馆没有 MySQL，`dbquery()` 返回空数组，每次敲 `exchange` 都是 `*Array index out of bounds.`（指令扫描里的裸指令）。改成 `int credit = (sizeof(ret) == 1 && sizeof(ret[0])) ? ret[0][0] : 0;`。实测：`exchange` 显示 `您目前可用书剑通宝为：零个……`，`exchange gold` 显示用法，控制台无报错。同一份文件在 bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2 六个库里逐字节相同。
