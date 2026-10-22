# sjtx2 — 「书剑天下」("小熊泥苑" snapshot)

Archive: `书剑天下.rar`. Port: 40030. Status: **done** (boots clean, full
registration flow verified end-to-end).

## What this is

The exact same underlying codebase as `shujian2008` (archive #35,
processed just before this one) — confirmed via `diff` that every core
`.c` file (`chinese.c`, `logind.c`, `named.c`, `master.c`, `securityd.c`,
`band.c`, `adm/etc/preload`) is byte-identical between the two raw
archives. Only runtime state differs (logs, save files, wizlist). This
snapshot is branded "小熊泥苑" ("Little Bear Mud Garden",
http://dtxy.126.com) rather than shujian2008's site branding, but it's
the same "「书剑天下」" ShuJian game — a genuinely different, non-
duplicate archive (different md5sum) worth its own entry, just not worth
re-diagnosing from scratch.

## Fixes applied

All 7 fixes already proven on `shujian2008` were **ported directly**
(copied from `libs/shujian2008/work/`) rather than rediscovered:
`adm/simul_efun/chinese.lpc`'s `is_chinese`, `adm/daemons/logind.lpc`'s
`check_legal_name` bound/gate fix + `gb_big5()`'s `catch()`-wrapping,
`adm/daemons/named.lpc`'s `valid_name` character-stepping fix,
`adm/daemons/securityd.lpc`'s `valid_read` §15n allowlist
(`load_object`/`recompile_object`/`include`), `adm/single/master.lpc`'s
§15o `get_include_path()` apply, and `adm/daemons/band.lpc`'s
`load_sites()` `catch()`-wrapping. See `libs/shujian2008/NOTES.md` and
AGENTS.md §15n/§15o for the full technical writeup of these bug classes
— not repeated here.

**Booted clean on the very first attempt** (zero errors), confirming the
ported fixes transfer correctly to a byte-identical codebase — a much
faster pass than `shujian2008`'s multi-round diagnostic process.

## Re-verification pass (2026-07-23) — ported shujian2008's two new bug fixes

The original pass above never tested a post-login command (same gap as
`shujian2008`'s original pass, since it predates AGENTS.md §15ae's standing
policy). Re-testing found this lib had the exact same TWO compounding bugs
already found+fixed in `shujian2008` this same pass (unsurprising, given
the byte-identical source): `feature/command.lpc`'s `private nomask int
command_hook(string arg)` (§15ae — `private` hides it from `add_action`'s
external dispatch on this driver) and `adm/daemons/commandd.lpc`'s
`sscanf(cmds[i]+"$", "%s.c$", cmds[i])` (§15ar — matches zero files after
the `.c`→`.lpc` rename, leaving the command table permanently empty).
Ported both fixes directly (drop `private`; `.c$`→`.lpc$`). Verified with a
full fresh registration (id `sjtxee`, real Chinese name `秦风十一`, male)
through to `look`/`score`/`quit`, all producing correct real output.
`debug.log` clean.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:
id `tianxiab` → confirm `y` → password `Pass1234` (twice) → real Chinese
name **`秦风`** (an invented name, avoiding Jin Yong novel characters per
this game's own rule, same as verified on `shujian2008`) → accepted →
reached character attribute selection (根骨/膂力/悟性/身法 stat prompt).

## lpcc sweep

9,936 files, 9,860 pass / 76 fail (99.2%) — identical numbers to
`shujian2008`, as expected from identical source. Memory stayed healthy
throughout (~16GB free).

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

Same shape as `shujian2008`'s own re-verification pass this same day
(identical source, so identical results throughout):

1. **LPC formatter**: `{"total":9936,"written":9680,"wouldChange":0,
   "unchanged":102,"errors":154}` — identical summary to `shujian2008`.
   Confirmed the ported `command_hook` (still plain `nomask`),
   `commandd.lpc`'s `"%s.lpc$"` pattern, and `get_include_path()` all
   survived reformatting. **Same formatter bug as `shujian2008`** (see
   its NOTES.md / `tianxia/NOTES.md` for the full writeup — a bare
   `::fn(...)` immediately after `(` gets mis-lexed as a closure
   literal) hit in this lib's own byte-identical copies of
   `cmds/leitai/npc_leitai.lpc` and `d/tanggu/npc/npc_leitai.lpc`
   (`if(::move(dest, silently))`); hand-fixed identically. Re-verified
   via `lpcc_check.sh`: 9,860/9,936 pass (76 fail, matching the
   pre-format baseline), neither file in the failure log.
2. **Native re-test against the rebuilt driver**: booted clean (zero
   fatal errors). Full registration verified end-to-end: id `sjtxfmta`
   → password ×2 → real Chinese name **`秦风十八`** → attribute roll →
   email `test02@abcd.com` → gender `m` → entered the game world at
   武馆前院, `look`/`score`/`quit` all producing correct real output.
   `debug.log` clean (zero `error in error handler`/`denied`/`undefined
   function`/`bad argument`).
3. **WASM test**: boots cleanly (same caught `dns_master` preload
   failure as `shujian2008`, no sockets package under wasm). **Login
   blocked by the same documented `query_ip_number()` limitation** —
   this lib's `sited.lpc` is byte-identical to `shujian2008`'s, so the
   same `sscanf(ip, "%d.%d.%*d.%*d", ...) != 4` check rejects every
   login id under wasm with "对不起，这个英文名字不能从当前地址登录。"
   Not patched — known driver-side wasm limitation, not a mudlib bug
   (native login verified working above). See `shujian2008/NOTES.md`
   for the full technical writeup, not repeated here.

## WASM-enablement pass (2026-07-23)

Same codebase as `shujian2008` — its patched `adm/daemons/{logind,sited,
band}.lpc` were ported wholesale (files were byte-identical at HEAD) and
re-verified here. See shujian2008's NOTES for the per-gate detail:

1. Loopback-allow (empty/non-string/`127.*` IP): logind `logon()`
   flood cap, logind `get_passwd()` wrong-password per-IP lockout,
   sited `is_valid()` (the former WASM blocker + wizard address
   restriction), sited `is_multi()` throttle, band `is_banned()`.
2. Uptime gate: none present.
3. Admin seeded: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` via
   `/adm/etc/wizlist` (was empty). Save files:
   `work/data/login/f/fluffos.o`, `work/data/user/f/fluffos.o`.
   Verified: login lands in 巫师休息室, `update /cmds/imm/update.lpc`
   succeeds.
4. Retest: fresh registration (sjtxqf/秦风, deleted after test) into
   武馆前院 with look/score/quit OK. debug.log: one pre-existing content
   error unrelated to login (`baoshid.lpc choose_baosi()` returns 0 →
   `call_other` on 0 when `/d/wudang/npc/th.lpc` loads — §7.14
   factory-call class, fires on random NPC load, also present before
   this pass).

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

代码完全相同，只是"小熊泥苑"站点品牌不同。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：是 shiji（021）/shujian2008 的 Century 家族手足档案。管理员登录（fluffos/Mud@2026，先问 BIG5 字体）干净正常，"您目前的权限是：(admin)"。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

按 AGENTS.md §10.7 流程做的完整深度功能测试。因为源码与 `shujian2008`
（Century 家族手足档案）几乎逐字节相同，先读了 `shujian2008` 自己那
份深度测试记录（见其 NOTES.md）作为路线图，在开机前主动核对了该记录
里两个已确认修好的 bug 是否也存在于本档案。WASM 验证本轮仍被跳过：
emsdk 安装器把工具链下载硬编码到 `storage.googleapis.com`，本 session
的出站代理策略拒绝该域名（`curl -sS $HTTPS_PROXY/__agentproxy/status`
确认为 403），未重试；本档案目前仍是 WASM 下未验证状态，仅完成原生驱
动（linux-debug 预设，ASAN/UBSAN）下的完整测试。

**开机前主动移植（对照 `shujian2008` 已确认修好的两个 bug）：**

1. **AGENTS.md §7.16**（已确认第二例）——`cmds/usr/top.lpc` 的五个
   `add_rank_*()` 函数（`add_rank_beauty`/`add_rank_pk`/`add_rank_rich`/
   `add_rank_worker`/`add_rank`）都跑一个针对存档 `/log/rank` 里真实
   ~2008 年时间戳的无界逐时衰减循环；`cmds/usr/quit.lpc:218` 每次
   `quit` 都无条件调用 `TOP_CMD->add_rank(me)`，读代码确认与
   `shujian2008` 修复前的形状完全一致（未加 `steps` 计数器的裸
   `while (...["time"] + 3600 < t) {...} else ...["time"] = t;`）。
   按 `shujian2008` 已验证的修复模式逐一处理五个函数：加 `steps` 局
   部变量，把衰减逻辑包进 `if (!find_player(...)) { steps = 0; while
   (... && steps++ < 240) {...} ...["time"] = t; } else ...["time"] =
   t;`，循环结束后无条件把时间戳同步回 `t`。第二个 `add_rank`
   （524 行）经确认整段包在 `/* ... */` 块注释里，是被上方拆分版取代
   的死代码，未动。开机后用 `top` 命令验证排行榜正常渲染并把测试角色
   加入榜单，随后 `quit` 干净退出（debug.log 全程无 `Too long
   evaluation`/`error` 记录）。
2. **AGENTS.md §7.12**——检查 `adm/simul_efun/message.lpc` 的
   `tell_room()` 包装函数，发现本档案这一份 **已经是修好的形状**
   （`message("tell_room", str, ob, exclude || ({}));`），与
   `shujian2008` 修复前的裸 `0` 不同，无需改动。因此本轮未做
   `shujian2008` 那种真实 16 分钟 `NET_DEAD_TIMEOUT` 强制下线验证——
   该 bug 类在本档案不成立，没有可验证的目标。

**本轮新发现并修复的 bug：**

3. **AGENTS.md §7.93（新增条目）**——`cmds/wiz/setparty.lpc`、
   `cmds/arch/setparty.lpc`（对 `(admin)` 级角色来说 `arch` 目录里的
   同名命令会遮蔽 `wiz` 目录，实际生效的是这一份）以及两份未使用的历
   史备份 `setparty15.lpc`/`setparty18.lpc`，同一处 bug 共 4 份拷贝：
   函数最后一行 `me->set("family/family_name", party);` 应为
   `ob->set(...)`——函数前面全部 380 多行都正确地对 `ob`（目标角色）
   做 `set`/`set_skill`，唯独最后设置门派归属的这一行手滑写成了
   `me`（调用者自己）。实测复现：管理员 `fluffos` 对测试角色
   `sjtxdeep` 执行 `setparty sjtxdeep wd`，`sjtxdeep` 的属性/技能/VIP
   状态全部正确获得加成，但 `师承` 仍是【普通百姓】——而 `fluffos`
   自己的存档却被静默改成了【武当派】。已在 `cmds/wiz/setparty.lpc`、
   `cmds/arch/setparty.lpc`、`setparty15.lpc`、`setparty18.lpc` 四处
   全部改为 `ob->set(...)`（两份历史备份虽不在命令派发路径上，但改
   动只有一个词，顺手一并修正，避免以后误用）。修复后重新用
   `setparty sjtxdeep gb` 验证：`sjtxdeep` 正确显示 `师承:【丐帮】`，
   `fluffos` 自身门派归属未受影响，管理员存档（`work/data/{login,
   user}/f/fluffos.o`）在测试后已用 `git restore` 还原到测试前的干
   净状态。这是一个通用的"目标对象在函数开头正确解析、函数体全程正
   确使用，唯独某一行手滑写成调用者自己"拷贝粘贴风险，不限于门派数
   据，值得在任何新选中的档案里对 `cmds/{wiz,arch,adm}/set*.lpc`
   做一次 grep 排查。

4. **AGENTS.md §7.44（已确认第 N 例）**——开机后第一次以 `(admin)`
   身份执行别名解析型指令（`goto`）就在 debug.log 里看到：
   ```
   执行时段错误：*Wrong permissions for opening file /log/wiz/fluffos for append.
   "No such file or directory"
   程式：/adm/daemons/aliasd.lpc 第 115 行
   ```
   `aliasd.lpc` 每次巫师执行别名指令都会往 `/log/wiz/<id>` 追加一行
   操作记录，但 `work/log/wiz/` 目录在这份 `work/` 树里从未被创建
   （`work/log/` 本身被 gitignore，运行期目录，与仓库无关）。本地
   `mkdir -p work/log/wiz` 后重新连线复测，同一条 `goto` 指令不再报
   错。这不是需要提交的仓库改动——纯粹是本地运行期目录缺失，任何真
   实部署这份档案的人第一次执行巫师别名指令都会撞到同样的错误。

**测试路径**：读 `doc/help/newbie`、`help_wuguan`、`map_wuguan` 后，
在原生驱动下一次连续的会话里：注册（真实中文名 沈知秋，id
`sjtxdeep`）→ 落地武馆前院，`look`/`score`/`i` 确认干净 → 探索到
`d/wuguan/wuchang2.lpc`（西练武场，沙袋 `pai shadai` 组织性学到
`基本掌法`/`strike` 技能，多次命中确认技能进度提示正常）→
`d/wuguan/wuchang1.lpc`（西武场，`木人` NPC 是安全陪练机制；
`kill muren` 被 `/d/wuguan/` 全域禁杀规则正确拒绝，改用 `fight
muren` 正常进入战斗，`accept_fight()` 镜像我方技能/属性，几个回合后
体力耗尽自动认输退出战斗，`score` 确认角色状态完好）→ 门派加入：拜
访 `d/wudang/npc/yudaiyan.lpc`（俞岱岩，`kungfu/class/wudang/
yudaiyan.lpc` 无 `attempt_apprentice()`，设定上本就不收徒，`apprentice`
指令正确回应"武当三侠"人设，不是 bug）后改到
`kungfu/class/wudang/yu.lpc`（俞莲舟）尝试组织性拜师，NPC 正确要求
"先做几件侠义之事"（正气门槛，合理设计，未强行绕过）；随后用管理员
`setskill`（`cmds/wiz/setskill.lpc`，正常工作）和 `setparty`（修复
后）分别验证技能与门派归属的**捷径路径**——两者都是本档案自带的管
理员测试快捷指令，不是我临时加的后门 → `quit` 后 debug.log 全程无
错误 → 断线约 1 分钟后重新连线，`score` 确认位置（重连回到
`startroom` 武馆前院，符合预期——测试角色未在武当山执行过 `save`）、
门派归属、技能全部正确持久化。

**测试角色**：id `sjtxdeep`，中文名 沈知秋，密码 `Sjtx2Deep9`，丐帮
（`setparty` 捷径路径赋予），综合评价 544900，位于武馆前院。存档：
`work/data/{login,user}/s/sjtxdeep.o`。

**验证通过**：真实中文名注册；`look`/`score`/`i` 多次状态检查；沙袋
组织性技能学习；`木人` 安全陪练战斗（`fight` 指令，禁杀区域规则正
确生效）；门派加入的组织性路径（NPC 正气门槛正确拒绝）与管理员捷径
路径（`setskill`/`setparty`，后者本轮修复）；`top` 排行榜命令（验证
§7.16 修复）；`quit` 后 debug.log 检查；断线重连后状态持久化。

**明确未验证**（记录而非静默跳过）：完整战斗到死亡的循环（安全陪练
已覆盖核心战斗机制）；真实的 `NET_DEAD_TIMEOUT`（900 秒）强制下线
（§7.12 类 bug 在本档案不成立，没有可验证目标，且会消耗大量剩余时
间预算）；组织性拜师直到正气达标的完整流程（需要大量游戏内时间积
累善行，超出本轮深度测试的合理时间预算，改用管理员捷径验证同一底
层技能/门派赋予路径）；商店购买（起始区域武馆内未发现商店）。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Same lineage/shape as
sibling libs `bxsj`/`bxsj1`: 24 live `replace_program(ROOM);`
occurrences deleted (`d/wanshou/*.lpc`, `data/group/groom/*.lpc`,
`d/cangzhou/dangpu.lpc`). No roommaker.lpc factory-bug variant.
Verified via a clean native driver boot (zero new `debug.log` errors,
port listening, killed by exact PID after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: the touched header here (`death2.h`) turned out to be dead/unreferenced code in this lib -- the live NPCs (`yanluo.lpc`/`mengpo.lpc`/`pusa.lpc`) actually `#include` a sibling `death.h`, which was already guarded from an earlier fix. This edit is a harmless no-op; no live vulnerability existed in this lib for this file.

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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## 深度功能测试第三轮 / §10.7 round three (2026-09-03)

新角度：2026-08-07 测过武馆沙袋/木人、`setparty` 捷径门派、quit 重连，
当时写明没测商店，组织性拜师也只走到俞莲舟的正气门槛。本轮补扬州当铺
买卖，以及一次真正走 `attempt_apprentice`→`recruit` 的拜师。管理员
`fluffos` / `Mud@2026`（浮浮），登录先答 BIG5 `N`。

### 商店

`goto /d/city/dangpu` 在修之前会炸：当铺 `create()` 调 `getspec()`，
对 `/clone/spec/` 每个文件 `new()`。`clone/spec/putao.lpc` 的
`set("long", ...)` 把 `HIG"神奇葡萄"NOR` 写进字符串字面量中间，整档
编译失败，驱动报 `*No program in object '/clone/spec/putao'!`，栈在
`dangpu.lpc:102` / `goto.lpc:26`。房间加载失败，后续 `list` 落到巫师
休息室留言板分页器上。

修复：按同目录 `pearl.lpc` 的写法把葡萄描述改成
`"……中土"HIG"神奇葡萄"NOR"，……"`；`getspec()` 的 `new()` 包进
`catch()`，一个坏礼品不再拖死整间当铺。CRLF 按二进制保留。
`shujian2008` 的 `clone/spec/putao.lpc` 仍是同一行损坏（手足档，本轮
未改）。

复测：`goto` 进入当铺，老板在。`list weapon`：「目前没有可以卖的武
器。」`value changjian` = 7 银 50 文；`sell` 按该价成交。无崩溃。

### 拜师

`clone /d/dali/npc/gaoshengtai`，`bai gao`：高升泰收徒（悟性 23、正
气 0 过门槛）→「恭喜您成为天龙寺的第十五代弟子。」`score` 师承
【天龙寺】【高升泰】。quit 后重连仍在。

### 本轮修改的文件

- `work/clone/spec/putao.lpc`
- `work/d/city/dangpu.lpc`
- 管理员存档 `work/data/{login,user}/f/fluffos.o`

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py sjtx2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 515 个 `.lpc` 和 11 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：505 -> 505 通过，无回退；改过的头文件的 12 个包含者 11 -> 11 通过。启动时警告 17 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 19 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 18 个文件，HEAD 与工作树各载入一次无回退（18 objects; HEAD PASS 18, tree PASS 18; regress 0; newly loading 0），这些文件的警告 20 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

孪生库 shujian2008 同日的整理（baa6caf453e，其中大半又是从 bxsj 搬来的）用 `scripts/lpc_twin_port.py adopt shujian2008 sjtx2 --pre baa6caf453e~1` 搬来：55 个文件与 shujian2008 修前逐 token 相同，清单里的警告全部落在这些文件里。内容见 shujian2008 的 NOTES（门派表/路线表改名、`equip.lpc` 的 `ob_hit()`、幻境 NPC 的重复声明、`kill_ob` 返回类型、`NAME_D` 的 `#undef`、嵌套注释等）。改动的 52 个对象 HEAD 与工作树各载入一次：HEAD PASS 52，tree PASS 52，regress 0。

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

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## wushi.lpc 重复定义了头文件里的函数（2026-10-19，KB 06 §7.266）

`d/city/npc/wushi.lpc`（地下比武场的拳手）自己又写了一份 `nick_first`/`nick_second`/`create_nick()`，而它包含的 `skills_pfm.h` 里已经有一模一样的一份，驱动报 `Redeclaration of function 'create_nick'`，整个 NPC 载入不了；它还把 `skills_pfm.h` 已经包含过的 `r_name.h` 再包含一遍（`get_random_name()`/`random_name()` 因此也定义两次）。删掉文件里的重复定义和多余的那行 `#include "r_name.h"`，用头文件里的那份。

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

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `ad`：`efun::shout()` 通不过 `valid_override`（2026-10-21，KB 06 §7.311）

管理员扫描里 `ad`（`cmds/adm/ad.lpc`）编译失败：`23:9: error: Invalid simulated efunction override`，指令里的 `efun::shout(...)` 不在 master 允许的目录里。本库的 sefun `shout(str)` 就是 `message("shout", str, users(), this_player())`，与 efun 的行为相同，改成直接调用 `shout(`。同系的 bxsj、bxsj1、shujian3、jinyongwenzi 的 master 放行，没有动。

## `bwscore`：比武大会的广场房间档案里没有（2026-10-21，KB 06 §7.299）

玩家指令 `bwscore`（`cmds/usr/bwscore.lpc`）不带参数时打印 `/d/bwdh/sjsz/square.lpc` 的描述，本库没有 `d/bwdh`（只有 xkm、xkx2000zxb、shenzhou 带着），`new()` 答 0，`0->long_desc()` 就是玩家看到的系统错误。改成 `(square ? square->long_desc() : "")`，用法提示照常。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 张三丰 `ask_me_6`：`who->query("id")`（2026-10-21，KB 06 §7.348）

非武当弟子问“太极道袍”时先 `command("shake " + (string)who->query("id"))`，`who` 声明了没赋值，应是 `this_player()`；抛错在拒绝的 `say` 之前，什么也说不出来。改成 `this_player()`，去掉 `who`。改动：`/kungfu/skill/zhang.lpc`。

## 保护任务的商人 `clone/obj/job/job_protect_npc.lpc`：两处笔误让整个文件从来没编译过（2026-10-21，KB 04 §6.29）

`clone/obj/job/protect.h`（保护商人的任务）克隆这个 NPC，但文件有两处笔误：`int baohu(string age)` 的函数体用的是 `arg`（`Undefined variable 'arg'`），而 `init()` 登记的是 `do_baohu`，函数名也对不上；`query->("id")` 多了一个 `->`。改成 `int do_baohu(string arg)` 和 `query("id")`（`if (!player = find_player(...))` 报的 `Illegal LHS` 只是前面语法错误引出来的连锁错误，这种写法本身是对的，没有动）；文件第一次能编译后带出 7 个 `Unused local variable` 警告（`sacrifice`、`exp_rate`、`skill_rate`、`lmt`、`menpai`、`killer`、`kill_num`），按 KB 04 §6.10 删掉。`baohu` / `protect` 两个动词现在有处理函数，任务的商人也第一次能出现。改动：`/clone/obj/job/job_protect_npc.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 19 条注册（14 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/daemons/robot-judge.lpc`（`do_test`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/wuliang/muwu1.lpc`（`do_tiao`）、`/d/dali/wuliang/shanlin-6.lpc`（`do_tiao`）、`/d/huanghe/npc/mafu.lpc`（`do_rideyz`）、`/d/huashan/jinshe/obj/haigu.lpc`（`do_move`）、`/d/huashan/npc/yaba.lpc`（`do_follow`、`do_kill`）、`/d/mr/obj/chahua3.lpc`（`do_chu`）、`/d/plummanor/hall.lpc`（`do_answer`）、`/d/songshan/fengchantai.lpc`（`do_decide`、`do_jieti`） 等共 14 个文件。最多的函数名：`do_tiao` 2 处、`do_learn` 2 处、`do_test` 1 处、`do_pass` 1 处、`do_resign` 1 处。没有动（读过）：`/clone/obj/job/job_protect_npc.lpc` 的 `do_baohu`（对象本身编译不过，登记留着，等对象能加载再处理）、`/cmds/leitai/dzd/dzd_flag.lpc` 的 `do_check`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/boat"` → `"/d/dali/yideng/obj/boat"`）, `/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/jiang"` → `"/d/dali/yideng/obj/jiang"`）, `/d/lanzhou/npc/chen.lpc`（`__DIR__ "../obj/jiuyin-book2"` → `"/d/lanzhou/obj/jiuyin-book2"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（1 处调用）、`check_length()`（4 处调用）、`check_return()`（1 处调用）、`check_space()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/mr/npc/fu.lpc`:`ask_dan1`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"玉露清新散": (: ask_dan1 :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 91 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；改名官 `zhuce` 的长度检查按字节算，合法的名字一个也过不了；NPC 的称呼和提示里取到两个字而不是一个字。

本库 91 处（32 个文件）：拼名字的赋值 19 处、与汉字常量比较 52 处、改名官的长度检查 14 处、对切片赋值 3 处、两个名字切片互比 2 处、`query("name")[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/d/shaolin/npc/fangsheng.lpc:150`）；`old_name[2..3]` → `old_name[1..1]`（`/d/shaolin/npc/rong.lpc:66`）；`old_name[0..3]` → `old_name[0..1]`（`/d/thd/npc/yaoshi.lpc:405`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：24 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 24 处（7 个文件）：`if (strlen(cmd) < 4 || strlen(cmd) > 8)`（`/cmds/group/gforce.lpc:180`）；`if (strlen(rname) < 4 || strlen(rname) > 16) {`（`/cmds/usr/irc.lpc:135`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
