# xiakexing3 — 侠客行三 / 金庸群侠传

Archive: `侠客行III .rar` (note: trailing space before `.rar`; TODO.md's
table originally listed this as `侠客行III 可用.zip`, which was wrong —
corrected once the real filename was discovered during extraction).
Port: 40038. Status: **done** (boots clean and quick, full registration
flow verified end-to-end including a real Chinese name).

## What this is

Config's `MUD_NAME` is "侠客行三", but the live connection banner
actually reads "金庸群侠传" ("Jin Yong's Gathering of Heroes") — yet
another instance of a lib's internal game name differing from its
config/archive name. `adm/obj/{master,simul_efun}` layout — confirmed
genuinely **unrelated** to `xiakexing100` (archive #43, `adm/single/`
layout) despite the shared "侠客行" title prefix, reinforcing the
established lesson that similar titles aren't a reliable lineage
signal. Small lib, ~3,651 raw files.

## Extraction quirk (new, see AGENTS.md's "Archive tooling" section)

Despite the `.rar` extension, this archive is actually a **plain POSIX
tar** (`unrar` correctly refused it: "not RAR archive"). Its members are
stored with **relative `../xkx3/...` paths**, which GNU `tar -xf`
unconditionally refuses to extract ("Member name contains '..'") even
with `--transform` (the safety check runs before transforms apply).
Worked around by extracting with Python's `tarfile` module directly,
stripping each member's leading `../` before calling `extract()` — see
AGENTS.md for the reusable snippet.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 12` → character-count bound `< 1 || > 6`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed**: no §4 fix (`master.c`'s `valid_write` gates
   via `find_object` only, `valid_read` is a bare `return 1;`); no
   `named.lpc` (doesn't exist in this lib).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 10 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxctest` → confirm `y` → **real Chinese
name `秦风`** → accepted, proceeds straight to "请设定您的密码：". This
lib's registration prompt text warns against using Jin Yong novel
character names, but the actual `banned_name` array only contains
pronouns + "时空" (no specific character names), so no specific name
needed to be avoided this time.

## lpcc sweep

2,981 files, 2,887 pass / 94 fail (96.8%). Failure tail is the usual
shape (missing globals, a handful of syntax typos) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~13GB free).

## Retroactive fix (found via archive #91, jqxz2008): this lib was completely command-dead after registration (AGENTS.md §15ae)

Archive #91 (`金庸群侠传2008加强版.rar`) turned out to have a master.c
byte-identical (in both `adm/single/` and `adm/obj/` locations) to this
lib's raw archive -- confirmed via md5sum, not assumed -- explaining
this lib's previously-unexplained "config says 侠客行三 but live banner
says 金庸群侠传" oddity: this is a rebrand of the same underlying
codebase. That later processing pass (after §15ae, the `private
nomask` command-hook bug, had been discovered) flagged this lib for a
check, since its own original testing above never verified a
post-login command -- exactly the blind spot §15ae warns about.

Checked and confirmed: `feature/command.lpc`'s `command_hook()` was
`private nomask` (the `home/command.lpc` copy was already correct,
`nomask` without `private`). `commandd.lpc`'s `sscanf` pattern was
ALREADY `"%s.lpc"` (not the `".c"` variant found on `bxsj`/`bxsj1`/
`jinyongwenzi` — so §15ar's second bug does not apply here, only
§15ae's). Fixed by dropping `private`; re-verified with a fresh full
registration (id → confirm → real Chinese name "秦岳"/"秦淮" → password
→ stat-gift accept → email → gender) reaching an actual starting room
(客店), with `look`/`score`/`quit` all now producing correct real
output, `debug.log` clean (0 `error:` lines — the "编译时段错误"
warning-spam visible to the player during testing is the separate,
still-unfixed §15w bug, cosmetic and unrelated to command dispatch).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 2981 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 2948 written, 13 already
  idempotent-clean, 20 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the §15ae
  fix above (`feature/command.lpc`'s `command_hook` staying `nomask`
  with `private` dropped) survived the reformat unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxcnex`), reaching the actual starting room (`客店`),
  `look`/`score`/`quit` all producing correct output — confirms the
  §15ae fix continues to hold under both the rebuilt driver and the
  reformatted source. No regressions.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `xkxcwas` → real Chinese name `秦岭` → password/
  stat-roll-accept/email/gender → landed in the same `客店` starting
  room, `look`/`score`/`quit` all produced correct output (post-login
  command dispatch, i.e. the §15ae fix, also confirmed working under
  WASM). This lib has **no IP-format-dependent login gate**, so it isn't
  affected by the known `query_ip_number()` WASM limitation — fully
  playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib is byte-identical (per §2.1 lineage check) to the
`jqxz2008` engine/daemon files, whose WASM pass was
already done and verified with the correct fail-closed convention —
ported that fix here and re-verified independently rather than
assuming it (§2.1's "ported fixes still need per-lib verification").

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc`'s `BAN_D->is_banned(query_ip_name(ob))` gate in
  `logon()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (checked the full `logind.lpc`
  input_to chain; the only other connection-adjacent gate is the
  in-memory `mad_lock` admin lockdown flag, default off — game/admin
  design, left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (id → y → 浮浮 → password ×2 → talent accept `y` → email →
`m`). Granted `(admin)` by appending `fluffos (admin)` to
`adm/etc/wizlist` (shipped with `sbaa (admin)` already present;
`securityd.lpc` reads this file at `create()`, so a driver restart was
needed to pick up the new line). Verified after restart: `目前权限：
(admin)`, title `【天神】`, `update /adm/daemons/band` →
`重新编译 /adm/daemons/band.lpc：成功！`.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xiakexing3/work/data/user/f/fluffos.o`
- `libs/xiakexing3/work/data/login/f/fluffos.o`

Retest: fresh boot, fresh registration (id `qretest`, real Chinese name
秦风十) through `look`/`score`/`quit` — landed in 客店, correct output,
clean quit. `fluffos`/`Mud@2026` admin login verified twice (once via
`update`, once via `score` to confirm `(admin)`/天神 status directly).
Zero `执行时段错误` lines in `debug.log` across the whole session. Test
character `qretest` removed afterward; fluffos kept.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一代码库换牌重发（master.c 逐字节相同）。

## 深度功能测试（§10.7，2026-08-05）

WASM 阶段的"完整验证过注册流程，没有发现 bug"结论需要更正——这次
§10.7 深挖在注册后的日常操作（留言板发帖）里找到一个此前从未触发
过的致命 bug，此外还确认并修好了两个在本轮次开头就已发现的问题。

- **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/logind.lpc`
  `enter_world()` 里 `if (!user->query("food") && !user->query("water")
  && ob->query("age") == 14)` 判断的 `ob->query("age")` 拿的是登录阶段
  用完即弃的连线桩物件，而不是真正的玩家角色本体 `user`——桩物件永
  远没有 `age` 这个属性，条件恒为假，导致**每一个新角色的食物/饮水
  永远初始化成 0**。改成 `user->query("age") == 14` 后，live 验证：
  修复前新注册角色 `score` 食物/饮水两栏都是空的（□□□），修复并
  重启驱动后同一注册流程走到底食物/饮水都是满格（■■■），第二次
  重启后（新角色 `testfive`）依然保持满格，确认修复稳定。
- **`get_name()` 里一行遗留调试 `printf("%O\n", ob)`**：紧跟在玩家
  输入中文姓名之后，会把连线桩物件的原始引用（形如
  `/clone/user/login#0`）直接回显给正在注册的新玩家，是内部调试信
  息泄漏。已删除该行；删除前后的注册流程 transcript 对比确认泄漏
  行消失、其余流程不受影响。
- **缺失的 `log/nosave/` 目录**：`adm/daemons/combatd.lpc`、
  `cmds/std/kill.lpc`、`cmds/skill/apprentice.lpc`、
  `cmds/skill/bai.lpc` 都会往这个目录写文件（主要是 PK 击杀记录和
  拜师技能的 FENG 记录，多数写入点还带 `userp()` 判断，NPC 战斗未
  必会触发），但 AGENTS.md §7.11 已经在这个 `jqxz2008` 系列的其它
  版本上确认过"目录缺失导致复活流程卡死"这个确切形状，属于零风险
  的预防性修复，提前建了这个目录（.gitignore 规则本身就会忽略
  `work/**/log`，不需要额外 git 操作）。
- **§7.86（第四个确认命中的独立血统家族）留言板 `post` 崩溃**：在
  起始房间"客店"的留言板（`clone/board/kedian_b.lpc`）测试
  `post board` 时，瞬间抛出运行时错误：
  ```
  执行时段错误：*cannot bind an lfun fp to an object with a pending replace_program()
  程式：/inherit/misc/bboard.lpc 第 102 行
  物件: /clone/board/kedian_b
  呼叫来自：/inherit/misc/bboard.lpc 的 do_post() 第 102 行，物件： /clone/board/kedian_b ("客店留言板")
  ```
  这行错误文字和 AGENTS.md §7.86（首次在 `xhcii` 上发现）记录的完
  全逐字一致（仅行号不同，102 行对应这份档案自己的
  `/inherit/misc/bboard.lpc` 里同一处
  `this_player()->edit((: done_post, this_player(), note :))` 闭包
  创建语句）。检查 `kedian_b.lpc` 确认是标准的致命形状：既
  `inherit BULLETIN_BOARD;`，`create()` 结尾又多余地对自己
  `replace_program(BULLETIN_BOARD);`。`grep` 全档案后确认这份档案
  一共 18 个留言板实例全部命中同一形状（`clone/board/` 下 17 个
  `*_b.lpc`/`*_r.lpc` 加上 `d/taohua/taohua_b.lpc` 一个重复放置的
  桃花岛留言板），没有发现 `sje` 那种运行时生成留言板源码的工厂变
  体。修复：18 个文件全部只删除多余的 `replace_program(BULLETIN_BOARD);`
  一行，保留 `inherit BULLETIN_BOARD;`，CRLF 行尾格式原样保留。
  Live 验证：重启驱动后用测试角色 `testfive`（李四）在客店留言板
  `post board` 顺利进入编辑器，输入正文、`.` 结束后提示"留言完
  毕。"；`look board` 显示未读数正确从 1 涨到 2，新增一条署名"李
  四"、时间戳为当天的记录；`read 2` 能完整读出刚才写的内容。测试
  完成后已把该留言板存档 `work/data/board/kedian_b.o` 还原到修复
  前的原始内容（只保留档案自带的那条测试留言），不留会话痕迹。此
  修复顺带把该存档文件的类头从 `#/inherit/misc/bboard.c`（`post`
  以外的场景之前一直"变身"成的那个类）改成了 `#/clone/board/kedian_b.lpc`
  （物件自己的真实文件）——纯粹是移除多余 `replace_program()` 的
  自然结果，存档数据本身不受影响，`restore()` 也不严格校验这行类
  头字符串。已在 AGENTS.md §7.86 追加这份档案作为第四个确认命中的
  独立血统。
- **§7.88 message() 参数缺失检查**：走查了 `adm/simul_efun/message.lpc`
  （通过 `adm/obj/simul_efun.lpc` 的 `#include`），`message_vision`/
  `tell_room`/`shout`/`say`/`write` 全部只是转呼叫内建 `message()`，
  没有本档案自己重新定义/包装一个签名不一致的 `message()`，不适用
  §7.88 这个特定形状。
- **§8.3a/§8.3b 指令表**：本轮登录、`look`、`score`、`post board`、
  `kill`、移动指令全部正常响应，WASM 阶段笔记里"已检查过没问题"的
  结论继续成立。
- **战斗与移动测试**：从"客店"往西走到"北大街"（遇到"白驼山少庄
  主「玉面蛇心」欧阳克"这个调戏 NPC，纯对话骚扰不主动攻击），再往
  南到"中央广场"，对普通"流氓"（Liu mang）发起 `kill`，多回合拳脚
  攻防（出拳/踢腿的命中、闪避、擦伤判定文字均正常），最终测试角色
  体力耗尽昏死，`debug.log` 全程零 `执行时段错误`。
- **死亡→复活流程完整走通，无需人工干预**：角色死亡后自动送入
  "鬼门关"，NPC"白无常"翻账册确认"阳寿未尽"后放行 `north` 到
  "酆都城门"，NPC"黑无常"重复同一套账册判断后主动"哼"一声送出，
  一股"阴冷的浓雾"把角色直接传送到复活点"武庙"（岳王庙正殿）。全
  程无需任何指令输入之外的干预，也没有出现 AGENTS.md §7.68 记录
  的那种"present() 判断游戏对象已经不在场导致流程卡死"的鬼魂卡死
  形状——**按 §7.68 的既有结论，这里明确不施加那条已经在其它 lib
  撤回的重试修复**，只如实记录观察到的行为。复活后 `score` 确认
  精/气恢复到约四成、食物/饮水依旧满格（§8.9 修复在多次死亡后依
  然生效）、实战经验从 0 涨到 3。
- 本轮测试方法论：中文角色名（李四）通过 `mudclient.py` 原始
  socket 发送，注册流程与两次驱动重启后的复测均未再撞上此前记录
  过的本地 `telnet`/CJK 字节转义问题；`post`/`kill`/移动等纯
  ASCII 指令改用 `scripts/tmux_mud.sh` 的 tmux 会话完成，全程无异
  常。
- 会话结束前清理：删除测试角色 `testfive`/`testfour` 的存档
  （`work/data/{login,user}/t/*.o`，均无 git 历史、确认是本轮测试
  产物）；`kedian_b` 留言板存档已还原；停止 tmux 会话、终止驱动进
  程；未触碰其它 lib 的任何未追踪文件。
