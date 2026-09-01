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

## 深度功能测试（第四轮，2026-08-21）：离岛/拜师/留言板三项未覆盖范围全部补测

第二轮的"未覆盖范围"明确列出三项：离岛乘船去中原、门派拜师、留言板
具体内容阅读。本轮逐一实测，全部走通，另发现并修复两个真实 bug
（一个是新发现的、之前从未记录过的 `natured.lpc` 僵尸对象崩溃，另
一个是 §7.100 的漏网实例）。

**1. 离岛（乘船去中原）——真实游戏机制走通，验证方法与 xuanjianlu
先例一致：先读代码找出精确时序，再写定时脚本，而不是瞎猜或直接
admin goto。**

`d/xiakedao/shatan.lpc`（挂号后新手落脚的沙滩，也是离岛唯一起点）
的 `check_trigger()`/`on_board()`/`arrive()`/`close_passage()` 四段
`call_out` 链完整读了一遍，精确时序是：进入房间 1 秒后 `check_
trigger()` 打开登船窗口（`exits/enter` 指向 `chuan.lpc`）→ 玩家有
15 秒时间输入 `enter` 上船 → 上船后 20 秒（`on_board`→`arrive`）小
船抵达中原沙滩 `shatan3.lpc`，`chuan` 的 `exits/out` 被设为
`shatan3` → 这个"下船窗口"只维持 20 秒（`arrive`→`close_passage`），
过期后又被摆渡回外海，需要等下一轮完整周期重新触发。写了一个
Python 定时脚本（`enter` 在触发后~5秒内送出，`out` 在上船后~33秒
时开始轮询），成功真实走完全程：`enter`→（等待）→"你正要下船，船
家塞了点东西在你手中……"→ 落地中原 `沙滩`（`shatan3.lpc`，无渔夫、
有"大车"NPC，与出发点视觉上刻意做成一样的房间名"沙滩"但内容不同，
不是 bug）。中原一侧 `大车`（`d/xiakedao/obj/car.lpc`）的 `qu`/
`hire`/`goto` 指令验证了真实江湖内容确实就在门后：扬州、杭州、泉
州、泰山、少林、神龙塘沽口、武当、峨嵋、大理、西夏、华山、星宿、
雪山、兰州、佛山，全部是真实可达的地图目的地（非占位/未完成）。
额外用 `qu huashan` 实测坐了一趟马车（同样是 `call_out` 定时到站，
无需赶窗口，40 秒后到），真实抵达"玉女峰"（华山主峰），确认目的
地房间货真价实，不是空壳。全程真实指令通关，没有用 admin goto 作
弊（唯一用到 admin 账号 `fluffos` 的地方是诊断阶段一次 `eval` 尝试
把卡在船上的另一个测试角色挪回岸上，未采纳因为 `/tmp/tmp_eval.lpc`
需要的 `work/tmp/` 目录本档案未转档，遂放弃该路径，改用重新注册一
个干净测试角色的办法完整重跑）。

**2. 门派拜师——`bai` 指令端到端验证，含一次成功的真实拜师。**

侠客岛本岛的 `迎宾厅`（从沙滩 `north`→`north` 可达，偶尔会被"引路
使"系统 NPC 强行拽去别处，重试几次即可到达）常驻一个"华山第十四代
弟子 凌逍"（round-two 里差点把测试角色打死的那个 NPC，`combat_exp`
120，`attitude peaceful` 不会主动攻击）。`bai lingxiao` 指令正确
找到目标、检查 `family`，因为凌逍自己只是个弟子（非掌门），代码给
出了合理的拒绝台词："要拜师，你得去拜我师父。"——这是刻意的游戏设
计（凌逍这类岛上"介绍人"NPC 统一 `generation` 较低、title 是"弟
子"，真正能收徒的"掌门"级 NPC 没有一个被摆在岛上，全部在中原对应
门派本部），不是 bug。为了完整验证"正确的 family/title 赋值"，追
加坐马车去华山，一路走到"客厅"找到"华山派第十三代掌门「君子剑」
岳不群"（`d/huashan/npc/buqun.lpc`，`create_family("华山派", 13,
"掌门")`），`bai yue` 一次成功："岳不群决定收你为弟子……恭喜您成为
华山派的第十四代弟子。"`score` 确认 title 正确变为"华山派第十四代
弟子"、`家门`字段显示"你的师父是岳不群"，两项赋值均正确，无崩溃。

**3. 留言板内容读写——`post`/`list`/`read` 全流程走通，确认 §7.86
的编译期修复在真实游玩下同样有效。**

岛上真正挂载留言板对象（`d/xiakedao/obj/xkd_b.lpc`）的房间不是
`ybting.lpc`（该文件里的引用是注释掉的死代码，之前误判过一次，浪
费了几轮尝试），而是 `dadong.lpc`（"大山洞"，含义上对应"侠客洞"，
"引路使"系统 NPC 在玩家滞留 `ybting` 太久时会明确提示"阁下请移驾
到侠客洞中再发呆吧"，这本身印证了 dadong 才是设计上的目的地）。到
达后 `post <标题>` 正确进入内建行编辑器（"结束离开用'.'……"），逐行
输入正文、以单独一行`.`结束后提示"留言完毕"；`list` 正确显示新留
言的标题/作者/时间戳；`read 1` 正确显示完整标题+正文，与实际输入
内容逐字一致。全程无报错，确认 §7.86 的 `replace_program()` 修复
不仅编译期干净，运行期 `post`/`read`/`list` 命令本身也完全正常。

**发现并修复的真实 bug：**

1. **新发现：`register_char()` 在活跃连线上直接 `destruct()`，留下
   的僵尸对象让 `natured.lpc` 的日夜循环每次都崩溃——已新增
   AGENTS.md §7.116。** 诊断过程见 §7.116 正文；简言之
   `adm/daemons/regid.lpc`（挂号改密码流程）在玩家连线仍然存活时直
   接 `destruct(body)`，如果客户端没有立刻干净 `quit` 就断线（"看到
   新密码提示后客户端崩了"——这是提示文字本身邀请玩家做的下一步动
   作），这个已销毁对象会永久残留：`userp()`（检查的是"历史上是否
   连过线"这个一次性标记，不是"现在是否在线"）永远返回真，导致
   `adm/daemons/natured.lpc` 的 `event_common()` 每隔一个昼夜周期
   （本档案 240 秒）就会对它调用一次 `move()`，因为它已经没有
   euid（`destruct()` 清空的），`move()` 内部的强制预编译
   `call_other(dest,"???")` 必现"Can't load objects when no
   effective user"运行时报错，永远不会自愈，永远重复。用一个真实
   注册后不 `quit`直接断线的角色实测复现，跨两个完整周期反复报错；
   一个正常 `quit` 的对照角色则完全没有这个问题。**修复**：把
   `natured.lpc` 里的判断从 `userp(ob[i])`（历史标记）换成
   `interactive(ob[i])`（真实在线状态），僵尸对象改为正确
   `destruct()`（幂等，安全）。重启驱动后用同样"注册后不 quit 强行
   断线"的手法复现，等满 270 秒（超过一整个周期）确认 `debug.log`
   零报错，且该角色下次干净登录也不再触发"踢掉重复连线？"提示（证
   实僵尸真的被回收了，不是巧合没踩中）。这个模式（`register_char()`
   的 `destruct` 写法 + `natured.lpc` 的 `userp()` 判断）在同源的
   `xkx2001` 里逐字相同（`grep` 确认，未修），值得未来做一次跨库
   扫描，本次round-four单库测试未做。
2. **§7.100 房间基类 `replace_program()` 漏网实例，2 处：**
   本档案 2026-08-19 的 §7.100 扫尾修复自称"work/ 下 0 处存活残
   留"，但那次扫描的脚本按 `.lpc` 后缀匹配文件，漏掉了两类非
   `.lpc` 后缀的真实房间源码：
   - `d/beijing/tulu.h`——26 个"土路"系列房间（`d/beijing/tulu_*.lpc`，
     北京城门之间的野外道路网）共享的 `#include` 模板头文件，
     `create()`（含 `replace_program(ROOM)`）写在 `.h` 里，`#include`
     进每个 `.lpc` 后原样展开——这是**真实可达**的漏网实例（不是死
     代码），只是因为藏在被 `#include` 的头文件里而不是独立 `.lpc`
     文件里逃过了上一次的扫描。
   - `d/forest/cl_bajiaoting`（无扩展名，是 `d/forest/clbajiaoting.lpc`
     "八角亭"房间的一份孤立重名旧副本，`grep` 全档案确认没有任何
     地方引用不带下划线的这个文件名，真正生效的 `clbajiaoting.lpc`
     早已在上次扫尾里修好）——这份是**死代码**，但同一个已知致命
     bug 形状既然要修，顺手一并清理，不留隐患。
   两处均按标准修法删除多余的 `replace_program(ROOM)` 调用（保留
   `inherit ROOM`），驱动重启后干净启动，无新增编译错误。

**标准清单快速核对（大多数早已修复，仅确认未回归）：**
§7.90（`maximum evaluation cost` 已是 5000000，达标）、§7.100（本
轮发现并补上 2 处漏网实例，见上）、§7.111（`master.lpc` 里
`standard_trace()` 唯一一处出现，属驱动框架文件非本档案自身逻辑，
未见相关报错）、§7.108（`clone/user/user.lpc` 的 `reconnect()` 已
含 `enable_commands()`，且本轮意外真实触发过一次"踢掉重复连线"场
景，重连后指令立即正常，确认修复有效）、§7.79（无 `addn()` 2 参用
法，不适用）、§7.30（`feature/skill.lpc` 4 个 accessor 均已带
`mapp(x) ? x : ([])` 防御）、combatd.lpc 的 `bounce` 除零模式（本档
案 `combatd.lpc` 里根本没有 `bounce` 相关代码，不适用）、
`cmds/std/go.lpc` 的 `.lpc` 后缀切片越界 bug（无 `sizeof(exit[arg])`
用法，不适用）。

**死亡/复活 `death_stage()` 重入守卫逐文件核查：** 全档案 `grep`
出 10 个含 `death_stage` 的文件。三个鬼差 NPC
（`wgargoyle.lpc`/`wgargoyle1.lpc`/`bgargoyle.lpc`，round-two 修
过 §7.68/§7.69 的那三个）和少林 `yu-zu2.lpc` 之外，另有 6 个
`d/bwdh/sjsz{,2,3}/{east,west}_xiangfang.lpc`——逐一读了完整函数
体：三个鬼差 NPC 的守卫形状正确（每个终止分支都清理
`death_stage_active`，`!present(ob)` 分支正确重试而非放弃，与
round-two 的修复一致，未回归）；6 个 `_xiangfang.lpc` 是"生死之
战"活动房间的单次事件触发（进房 90 秋后分配队伍），不是幽灵复活
循环，进入即在函数顶部无条件清理守卫，没有重入风险。**唯一的例
外，但确认是死代码，不是需要修的 bug：** `d/shaolin/npc/yu-zu2.lpc`
（"狱卒"，少林监狱场景）的 `death_stage()` 确实是 §7.68 那种"不在
场就永久放弃"的旧形状（`if (!ob || !present(ob)) { ...; return; }`
没有重试），但全档案 `grep` 确认这个文件从未被任何房间当作
clone 目标引用过（真正被 `d/shaolin/jianyu1.lpc` 监狱房引用的是同
目录下另一份不同代码的 `yu-zu.lpc`，无 `2` 后缀，逻辑完全不同、
没有这个 bug）——`yu-zu2.lpc` 是孤立的未接线遗留文件，不会被驱动
实际加载/触发，没有可观测的错误路径，按项目"没有错误信号就是设计
不是 bug"的准则不做修改，仅记录在此以备日后万一被接上线时参考。

**结论：** 第二轮标记的三项未覆盖范围全部真实验证通过。新发现并修
复一个此前完全未记录的真实 bug（§7.116，natured.lpc 僵尸对象崩
溃），以及一个 §7.100 的漏网实例（含一处非 `.lpc` 后缀导致脚本漏
扫的真实可达实例）。全程测试中 `debug.log` 除上述两个已修复问题
外无其它报错；测试角色存档已清理，不落入提交。

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/zhongnan/npc/killer.lpc`
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
