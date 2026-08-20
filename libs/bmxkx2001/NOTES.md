# bmxkx2001 — 侠客行 (The Quest of Oriental Chivalry, North America 2001 build)

Archive: `北美侠客行2001.rar`. Port: 40039. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行" / "The Quest of Oriental Chivalry", credited to "XiaKeXing
Gaming Group 1996-1999", MudOS v22b25. Confirmed via `diff` to be the
**same codebase lineage as `xkx2001`** (archive #25, already done):
`adm/simul_efun/chinese.c` and `adm/single/master.c` are byte-identical;
`adm/daemons/logind.c` differs by only a single commented-out IP address
line. However, many peripheral `clone/`/`cmds/` files genuinely differ
— a real, evolved snapshot at the content level, not a byte-identical
archive duplicate — so it still needed its own conversion/boot/test
pass, just with the core registration-path fixes already known.

## Fixes applied

1. **AGENTS.md §15h**: `is_chinese()`'s standard GBK lead-byte check →
   CJK codepoint check.
2. **Ported directly from `xkx2001`'s already-proven fix**:
   `check_legal_name(string name, object ob)` had the exact same
   byte-shift "auto-correct" hack (`name[j]+=128; name[j+1]+=128;`,
   meaningless against Unicode codepoints) — replaced with
   straightforward rejection, matching `xkx2001`'s fixed version
   verbatim. Bound `< 2 || > 8 || i % 2` (byte count + meaningless
   odd-byte rejection) → `< 1 || > 4` (character count).
3. **New instance of AGENTS.md §8e** (`tail` is not a real FluffOS
   efun): `adm/simul_efun/message.lpc`'s `tail(string file)` called
   `efun::tail(file)`. Unlike some other libs where this is a harmless
   dead admin command, here it's **fatal** — this function is compiled
   as part of `simul_efun.lpc` itself, so the compile error
   (`Unknown efun: tail`) took down the ENTIRE simul_efun object,
   which crashed the whole boot (`No program in object
   '/adm/single/simul_efun'!`, `The simul_efun ... and master ...
   objects must be loadable`). Fixed with the standard §8e
   reimplementation (`read_file()` + `explode()` + slice last 10 lines
   + `write(implode(...))`).
4. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. `/adm/daemons/network/http` is ALSO in preload but confirmed
   safe to leave (its socket setup is deferred via `call_out("setup",
   5)`, non-blocking to preload).
5. **Retroactive fix, AGENTS.md §15ae** (added after the original pass
   above — the original registration test here never continued past the
   password prompt, so this was missed): `feature/command.lpc` declared
   its `add_action`-dispatched command hook as `private nomask int
   command_hook(string arg)`. This driver treats `private` as opaque to
   `add_action`'s external dispatch once inherited into the player body
   class, so **every single post-login command silently did nothing at
   all** — no error, no output, indistinguishable from a hung connection.
   Found independently on `xuanjianlu` (archive #70, same underlying
   bug), which flagged this lib as also affected. Fixed by dropping
   `private` (keeping `nomask`). Re-verified with a fresh registration
   (id `hookabcd`, real Chinese name `秦淮`) followed by re-login and
   `look`/`score`, both now producing correct output.

## Interactive test result — full registration flow

This lib has a hidden pre-id prompt: **"Do you want to use BIG5
code?(y/n)"** right after the banner. Verified the complete registration
path in one continuous connection: `n` → id `bmxkxb` → confirm `y` →
**real Chinese name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous
Jin Yong character found in this lib's `banned_name` list) → accepted,
proceeds straight to "请设定您的密码：".

## lpcc sweep

8,145 files, 6,894 pass / 1,251 fail (84.6%). The largest single cluster
(52 failures) is the exact same missing `EDITOR_D` daemon documented in
`xkx2001`'s own NOTES.md (a bulletin-board "compile into archive"
feature, genuinely absent from this archive too — not a typo). The
remaining ~1,199 failures are the usual long tail (illegal-character/
encoding edge cases, syntax typos in individual files) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~12GB free).

## Retroactive fix (QA re-verification pass, 2026-07-23): tell_room() 2-arg call crashed the starting room (AGENTS.md §15s)

Found during a routine re-verification pass: a fresh registration reached
the password prompt fine, but the resulting character landed with **no
environment at all** — `look` printed "你的四周灰蒙蒙地一片，什么也没有。"
(the standard "you are nowhere" fallback), i.e. exactly the §15t-shaped
symptom of a new character silently ending up in the void. Root cause was
the classic §15s bug, not previously caught here: `adm/simul_efun/
message.lpc`'s `tell_room(ob, str)` 2-arg call form leaves the `varargs
object *exclude` parameter as its default `int 0`, which flows straight
into `message("tell_room", str, ob, exclude)` — this driver's `message()`
efun rejects a literal `int 0` in that 4th argument slot at runtime. The
starting room (`/d/xiakedao/shatan1.lpc`, picked randomly for every new
character) calls `tell_room()` from its own `reset()`→`make_inventory()`
chain, so this crashed the room's own creation on every single new
registration, leaving the new character with no valid environment.
Verified directly with `lpcc <config> d/xiakedao/shatan1` — reproduced the
exact crash (`*Bad argument 4 to EFUN message()`) outside a full boot.

**Fix**: `message("tell_room", str, ob, exclude || ({}));` (same pattern as
every other lib in this project with the same bug). Re-verified with
`lpcc` (clean load, no error) and a fresh full registration + `look` in a
real driver boot — the character now correctly lands on "沙滩" (the beach)
with full room text and the escort NPC's greeting, `debug.log` clean.

Also investigated (and confirmed NOT a bug) while diagnosing the above:
`score`/other non-allow-listed commands produce **no visible output** for
a few moments right after registration — this is intentional content, not
a broken command dispatcher. `d/xiakedao/shatan1.lpc`'s `init()` installs
`add_action("block_cmd", "", 1)` for any non-wizard, and `block_cmd()`
silently swallows every verb except `quit`/`goto`/`suicide`/`follow`/
`tell`/`say`/`reply`/`look` until the player follows the escort NPC to
the registration room and confirms an email via `register <email>` — the
same restriction is present in `d/xiakedao/register.lpc`'s own room too.
Confirmed via a temporary `write_file()` instrumentation of
`command_hook()` (removed after diagnosis) that `look` reaches
`find_command`/dispatch correctly while `score` never reaches
`command_hook` at all in this state — i.e. the driver's dispatch layer
itself is healthy; this is a deliberate "you can't do anything except
follow/register yet" onboarding gate, not the §15ae dead-command-hook
class of bug. `look` was used as this lib's verified post-login command.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (8,146 files,
  8,090 written/reformatted, 30 already-clean, 26 refused with an error —
  expected on legacy code, not chased individually per the tool's own
  self-check policy).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log` (only ordinary compile-time warnings, same shapes as
  before). Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦山`): BIG5
  prompt → id `qinshan` → confirm → Chinese name → password → talent
  roll → email → gender → reaches the actual starting room (沙滩), escort
  NPC `张三` greets by name. `look` correctly redisplays the room;
  `score`'s no-output behavior is the pre-existing documented onboarding
  gate above, not a regression. No new fixes were needed — the reformat
  and the fresh driver build did not introduce any regression.
- **WASM build**: booted cleanly under `build-wasm/src` via
  `scripts/wasm_client.js` (the only preload-time complaint is
  `Undefined function socket_close` in `adm/daemons/network/http.lpc`,
  caught by the lib's own `master.lpc` error handler exactly as it is for
  a missing daemon natively — non-fatal, `Initializations complete.`
  still printed). Unlike some sibling libs, this lib's login/registration
  path does **not** gate on `query_ip_number()`'s format, so registration
  proceeded all the way through under WASM too: id `qinfeng` → Chinese
  name `秦风` → password → talent roll → email → gender → reached the
  actual starting room (沙滩), escort NPC greeted by name, `look`
  produced correct room output, `quit` exited cleanly. **This lib is
  confirmed fully playable under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched (loopback/empty/malformed address short-circuits first, original logic intact):

- `adm/daemons/band.lpc` `is_banned()` (~line 42): loopback/localhost/empty/
  non-string → return 0. (Called from `logind.lpc logon()` line ~113 with
  `query_ip_name()`.)
- `adm/daemons/regband.lpc` `is_banned()` (~line 44): same guard (this is the
  new-character registration ban, `logind.lpc` line ~218).
- `adm/daemons/securityd.lpc` `valid_wiz_login()` (~line 100): loopback →
  return 1 (the per-wizard site-restriction gate at `logind.lpc` line ~161
  would otherwise reject any wizard id not present in `wiz_sites`).
- No uptime() startup gate; no per-IP connection-count throttle in this
  lineage's logind. `REGI_D->is_banned_email` is email-based, untouched.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, granted `(admin)` by editing
`data/securityd.o` (SECURITY_D restore data): `wiz_status["fluffos"]="(admin)"`,
`wiz_sites["fluffos"]=".*"`. Verified `update /d/xiakedao/shatan1` (成功) and
`goto` work after restart. Save files for the orchestrator to force-add:
**`libs/bmxkx2001/work/data/user/f/fluffos.o` and
`libs/bmxkx2001/work/data/login/f/fluffos.o`** (untracked dirs;
`data/securityd.o` is already tracked and modified).

Retest: fresh normal registration (id `ceshier`, name 秦风) reached 沙滩,
look correct, quit clean, 0 new errors in debug.log; test char saves removed.
(`score` is deliberately blocked pre-island-registration -- documented
onboarding gate, unchanged.)


## Retrofit (2026-07-24): fail-closed loopback check (security correction)

The loopback-allow gate patched above originally also treated a
non-string/empty/malformed `query_ip_number()` result as loopback (a
defensive stand-in for the WASM driver bug). That driver bug is now fixed
upstream, so this was tightened to fail-closed: only an exact
`"127.0.0.1"` / `"127."`-prefix / `"::1"` match bypasses the gate; a
malformed or non-string address now falls through to the original gate
logic (treated as untrusted/remote) instead of being auto-allowed.
Re-verified fluffos login still works after tightening.

## 深度功能测试（第二轮，2026-08-03）

之前的会话只测到"注册成功、到达沙滩、`look`正确、quit干净"这一步
——`score`在挂名（岛上登记）之前是刻意被封锁的，所以从未真正验证
过挂名之后的完整流程。本轮把 README 里提到的"侠客岛迎宾/登记"流程
完整走了一遍：新角色一入游戏被"赏善使"张三迎接 → `follow zhang
san` → 到达"侠客岛挂名处" → 向"登记使"木老六用
`register <email>` 命令登记 → 系统生成一个新的随机密码并要求用新密
码重新连线 → 重连后正式进入游戏，`score`/`hp`工作正常，食物/饮水/
气/精/内力槽创建时即为满值（无 §8.9 症状），落脚点是另一处沙滩场
景（渔夫 NPC 主动给新手提示）。

proactive 检查了 AGENTS.md 已归档的四类常见坏味道，均未命中
（`§8.9`附近命中的几处`query("age")`用法核对后确认是易筋丸
药效相关的正常游戏逻辑，不是登录初始化 bug）。

**发现并修复的三个真实 bug（均为战斗/死亡/复活链路里的新类型，已
分别新增 AGENTS.md §7.68、§7.69）：**

1. **死亡复活序列会被无关的"引路"NPC 打断后永久卡死**——正常打
   NPC练手时不慎被"华山第十四代弟子 凌逍"（combat_exp 只有120，
   看似很弱但实战中把满状态的新手角色直接打死）杀死，鬼魂被送到
   "鬼门关"，白无常按流程读五段台词、约50秒后让鬼魂复活。但鬼魂在
   复活流程进行中被另一个完全无关的"引路使龙x"系统 NPC（
   `d/xiakedao/npc/longx.lpc`，负责把偏离固定路线的玩家强行拽回
   剧情路径，不检查目标是死是活）强行`move()`带走，白无常这边的
   `death_stage()`发现`!present(ob)`就直接永久放弃、再也不重试
   ——鬼魂从此卡死，`score`一直显示【鬼魂】、气精槽全空，没有任
   何报错提示，reconnect 也不会自愈。实测复现：故意送死、被"龙"
   系NPC拖走、等待远超50秒确认彻底卡死；然后在三份鬼差NPC档案
   （`wgargoyle.lpc`/`wgargoyle1.lpc`/`bgargoyle.lpc`）里把"永久放
   弃"改成"暂时不在场就5秒后重试"，重启后正常复活流程依旧完整无
   误，第二次死亡+被同一系统NPC打断，这次角色最终还是正常复活并
   能自由行动（鬼魂状态下玩家自身无法移动，能自由行动本身就是已
   复活的证据）。
2. **"引路使龙x"自己也有一个空指针解引用**：`greeting()`里
   `present(query_temp("xkd/guest"), environment(this_object()))`
   结果没有判空就直接`.query_leader()`，玩家不在场时触发
   `*Bad argument 1 to EFUN call_other() ... Got: int(0)`。已加
   `if (!objectp(me)) return;` 防御。
3. **真正被驱动加载的`include/globals.h`漏了一个宏定义**：
   `inherit/misc/bboard.lpc`（留言板基类，被城内所有布告板 clone
   继承）编译时报`Undefined variable 'EDITOR_D'`，进而导致任何布告
   板 clone 都"No program in object"。查了`config.fluffos`的
   `global include file`配置，确认驱动实际加载的是`include/
   globals.h`，而不是树里另一份看起来一样、注释里自称"会被驱动自
   动包含"的`inherit/misc/globals.h`（这份反而是没被使用的旧副
   本，且它自己也缺另外几个新宏，不是简单的"更完整版本"）。已在真
   正生效的`include/globals.h`里补上缺失的一行`#define EDITOR_D
   "/adm/daemons/editord"`（`/adm/daemons/editord.lpc`确认真实存
   在，不是内容缺失）。

**完整流程验证**：多次注册全新角色，走完"迎宾→跟随→挂名登记→改
密码重连→渔夫新手提示"完整链路；在"山路"场景和"黄衣大汉"NPC互动
（`ask han about 武器`/`ask han about 防具`，一个用问答方式而非
list/buy 的兵器防具供应NPC）；和"凌逍"打斗致死，完整体验死亡→鬼门
关→复活的流程；`quit`干净退出。除上述三个已修复的 bug 外，全程
debug.log 无其它报错。

**未覆盖范围**：离岛（乘船去中原）之后的正式江湖内容、门派拜师、
留言板具体内容阅读，因时间原因未实测。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一套代码库，北美 2001 版构建。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`include/globals.h` 里定义了两次——`/std/room` 后又被
`/inherit/room/room` 重新定义，驱动的"Macro redefined"警告确认后
一个生效，但宏名本身不受影响，不影响这次扫描的匹配）在本档案
2,210 处房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后又多余调
用了一次 `replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个
休眠 bug，和上面 §7.86 那批 `BULLETIN_BOARD` 崩溃同一根本形状，只
是这次覆盖的是整个房间基类而不是留言板。用 `fix_710_room.py` 扫
过 `work/`，删除 2,209 处标准形状；`clone/misc/roommaker.lpc` 剩
下 1 处字符串拼接变体，手工改成 `str += "\n\tsetup();\n}\n";`。
修复后 `work/` 下 0 处存活残留，282 处转档之前已注释掉的 `//` 行
原样保留，`work/data/` 下没有真实 `.lpc` 源码命中。`git diff
--stat` 显示 2209 个文件净删 2210 行，与脚本自报数字 + 1 处手工编
辑吻合。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行），巫师账号 `fluffos`/`Mud@2026`
（GB 编码分支）登录后确认"目前权限：(admin)"，`look`/`goto` 走读
了 2 个曾经命中过这个 bug 的房间
（`d/zhongnan/zoudao4.lpc`、`kungfu/class/baituo/btyard.lpc`）均正
常，`quit` 干净退出。登录存档的时间戳增量已用 `git checkout HEAD
--` 撤销，未落入提交。

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
