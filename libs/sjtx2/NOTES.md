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
