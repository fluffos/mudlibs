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

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Sibling of `bxsj` (diverged
fork, not byte-identical, but shares this exact bug in the same 24
files). 24 live `replace_program(ROOM);` occurrences deleted
(`d/wanshou/*.lpc`, `data/group/groom/*.lpc`,
`d/cangzhou/dangpu.lpc`). No roommaker.lpc factory-bug variant. Verified
via a clean native driver boot (zero new `debug.log` errors, port
listening, killed by exact PID after ~8s).
