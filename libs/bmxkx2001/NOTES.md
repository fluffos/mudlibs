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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— compile-warning and load-failure pass (ported from xkx2001)

`scripts/lpc_warnings.py bmxkx2001`: 3381 distinct diagnostics and 153 files that did not load at the start, 160 diagnostics and 119
files at the end (8014 load). 1164 files changed. The code is the xkx2001 root's, so the pass is its pass
(libs/xkx2001/NOTES.md has every class, the typos found through the no-side-effects list and the list of files left alone):
`lpc_twin_port.py adopt xkx2001 bmxkx2001` carried the fixes of the files whose code is the root's (928 reformatted, 121 spliced, 70 verbatim), then
`lpc_warnings.py --fix`, `lpc_fix_macro_redef.py`, `lpc_fix_prototype_types.py`, `lpc_name_winner.py` and `lpc_move_decl.py`
handled the diagnostics that depend on this lib's own files.

The files that do not load are the same ones as in xkx2001 (drafts, pasted logs, the TMI-2 network daemons without headers, half-written wizard work), with the same errors; the `sjsz/`, `sjsz2/`, `sjsz3/` challenge arenas of `d/bwdh/` carry the same `BOARD` macro clash and `void`/`int` prototypes as the rest of the family and are fixed the same way.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply bmxkx2001`: 10 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 11 objects that were renamed, edited or name a renamed path (HEAD against the working tree): 1 PASS -> 11 PASS, 0 that loaded before fail now, 10 more load.

After the rename: `scripts/lpc_warnings.py bmxkx2001` 152 distinct diagnostics, 8028 files compile and 115 do not (8014 / 119 / 160 before; the pass is the one of libs/xkx2001/NOTES.md). The four peak-view rooms `d/wudang/taoyuan/tyroad4-7.lpc` include their header through `__DIR_"feng.h"` (one trailing underscore, `Bad #include directive`) and now `#include "/d/wudang/feng.h"`, the file that `tybxjh` / `wlhd` / `yxjh` keep in `d/wudang/taoyuan/`.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

- 2026-10-10：`/clone/misc/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 bf237897b05 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。37 个文件 41 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；2 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：3 个对象，新增载入 1，回退 0。

- 2026-10-14（更正）：上一条把 `auto_perform()` 也改成了 `mixed`/`string`，其实那里返回值的类型是因为前面的错误（未定义的函数）才变成未知，不是真的返回字符串；恢复为 `int`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/laugh`、`/kungfu/condition/sanpoison`、`/kungfu/condition/xianglu-du`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/chan`、`dagou-bang/sansha`、`damo-jian/weituo`、`huashan-jianfa/feilong`、`jinshe-zhuifa/huayu`、`jinshe-zhuifa/tuwu`、`liangyi-dao/sanshen`、`mo-bang/mo`、`quanzhen-jian/lianhuan`、`riyue-bian/chanrao`、`taiji-jian/tongshou` 等 16 个。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：驯马的 `/d/dali/npc/mafu`（成功率少了福缘一项）。

## 临济庄 remove 没有运功时报错（2026-10-15）

`linji-zhuang/remove` 直接 `switch (lj_exert["name"])`，`lj_exert` 是 `query_temp("lj_exert")`；没有正在运用的临济庄功夫时它是 0，`exert remove` 每次都报 `Value being indexed is zero`。补上 `if (!mapp(lj_exert)) return notify_fail(...)`。本库的临济庄各 exert 都不设置 `lj_exert`，所以这个 exert 以前每次都报错，现在只会提示没有在运功。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`xiaowu-xiang`→`xiaowuxiang`（`liuyang-zhang`、`liuyang-zhang/qufu`、`liuyang-zhang/zhongfu`、`ruyi-dao`、`ruyi-dao/lianhuan`、`tianyu-qijian` 等 9 个文件）；`shenhuo-xuanming`→`shenghuo-xuanming`（`/d/kunlun/skill/dafeng-yunfei`、`dafeng-yunfei`、`xiaoyao-zhangfa`）；`quanzhen-jianfa`→`quanzhen-jian`（`dugu-jiujian`）；`xiatian-gong`→`xiantian-gong`（`/d/zhongnan/skill/chunyang-quan`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baitao-xuangong`→`bitao-xuangong`（`bitao-xuangong`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 随机取房间后不判断就过滤（2026-10-15，KB 06 §7.250）

`/d/city/npc/ftb_zhu.lpc`、`/d/qilian/obj/jinhe.lpc` 从 mapdb 随机取一个房间后直接 `strsrch(room_path, ...)` 排除区域；地图还没生成时取回的是 0，`strsrch(0, ...)` 报错，护镖等任务就此中断。条件前补 `!stringp(room_path) ||`，取不到房间时走原有的重试和“cannot find target room”提示。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-bian/duanyun`、`feiyu-bian/chanrao`、`yunu-jianfa/suxin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/ryu/`、`/u/wsky/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参、狐狸皮、虎骨，`clone/drug/cb_renshen`、`clone/drug/hugu`、`clone/drug/hulipi`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；逍遥三笑散（`d/xingxiu/npc/obj/sanxiao`）弹出之后报错，毒药留在身上，可以一再使用；疯魔杖法的掷杖绝招（`kungfu/skill/fengmo-zhang/feizhang`、`kungfu/skill/fengmo-zhang/fengmo`）：内力、精力已扣，杖已卸下，随后报错；接回杖的 `check_fight` 没有排上，`fengmo` 标记不再清除，重新登录之前不能再用；天山杖法「飞杖」（`kungfu/skill/tianshan-zhang/feizhang`）：杖“撞到山石上断成无数截”之后报错，杖仍留在身上。7 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

25 个文件、35 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/lingjiu/obj/qingyi`、`/d/lingjiu/obj/doupeng`、`/d/shenlong/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 25 个（25 个原来载入不了），没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（4 个名字，最多的是 `stuff`、`huashan-zhangfa`、`jingding-zhang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 4 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 19 处、16 个文件：`lingji-zhuang`→`linji-zhuang`（7 处）、`dashouyin`→`dashou-yin`（5 处）、`pudu-chang`→`pudu-zhang`（2 处）、`stuff`→`staff`（1 处）、`huagu-mainzhang`→`huagu-mianzhang`（1 处）、`banrou-zhang`→`banruo-zhang`（1 处）、`jingding-zhang`→`jinding-zhang`（1 处）、`bahuangh-gong`→`bahuang-gong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/beijing/east/wangfudajie3.lpc` 的 `southwest` 出口：`/d/beijing/zijincheng/dongchangan` → `/d/beijing/zijin/dongchangan`
- `/d/huangshan/ciguang.lpc` 的 `south` 出口：`wengquan` → `wenquan`
- `/d/huangshan/tiandu1.lpc` 的 `up` 出口：`jiyubei` → `jiyunbei`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 6 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/gaibang/ml.h`（1 处）。

## 比较链的人工修正（2026-10-20，KB 06 §7.282）

`d/hangzhou/huagang1.lpc`：挖泥的判断 `arg != "泥" || arg != "mud"` 永远为真，随便挖什么词都挖出湿泥，后面的“你要挖什么？”走不到；本意是参数是“泥”或 mud 时才挖，改成 `==` 和 `||`。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 19 处）。改动：`/d/city/jiuguan2.lpc`（2 处）、`/d/city/npc/mj.lpc`（3 处）、`/d/city/npc/mjxiaosi.lpc`（3 处）、`/d/city/wumiao.lpc`（1 处）、`/d/city/zuixianlou.lpc`（1 处）、`/d/heimuya/jiudian.lpc`（1 处）、`/d/kunlun/luanshiduibak.lpc`（2 处）、`/d/quanzhou/qzkedian.lpc`（1 处）、`/d/quanzhou/wglou1.lpc`（1 处）、`/d/xiakedao/no_pk_room.lpc`（1 处）、`/kungfu/skill/kurong-changong/liaoshang.lpc`（3 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：药炉：`burning2` / `burning3` → 文件里定义的 `buring2` / `buring3`；`do_destroy` → 文件里定义的 `do_destory`。改动：`/d/huanghe/npc/tc_wang.lpc`、`/d/xingxiu/npc/obj/yaolu.lpc`、`/d/xingxiu/obj/yaolu.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 14 条注册（9 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/beijing/obj/kuanglu.lpc`（`do_look`）、`/d/kunlun/npc/mingjiao_npc.lpc`（`do_qingjiao`）、`/d/quanzhou/npc/gongping-zi.lpc`（`do_bihua`、`do_halt`）、`/d/shenlong/obj/sg_mianzhao.lpc`（`do_open`）、`/d/xiakedao/obj/car.lpc`（`do_hire`）、`/d/xingxiu/npc/feng.lpc`（`do_ketou`）、`/d/xingxiu/obj/sanxiao.lpc`（`throw_ob2`）、`/inherit/misc/fboard.lpc`（`do_list`）、`/kungfu/class/mingjiao/mingjiao_npc.lpc`（`do_qingjiao`）。最多的函数名：`do_bihua` 3 处、`do_qingjiao` 2 处、`do_halt` 2 处、`do_hire` 2 处、`do_look` 1 处。

## 注册到不存在函数的 `add_action`，第二轮：宏路径父类和静态解析不了的对象（2026-10-21，KB 06 §7.349）

第一轮的静态解析读不了经宏路径继承父类的对象（`#define ROOM STD_DIR "room/room"` 这类定义的正文以另一个宏开头）和它解析不了的继承，这些对象当作 `UNSURE` 没有扫；第二轮修了解析器，重扫并对这些对象在运行时问 `function_exists()`。`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 11 条注册（2 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/xingxiu/xueling/exit1.lpc`（`do_ling`）、`/kungfu/class/gaibang/zhulin3.lpc`（`do_bake`、`do_cut`、`do_kao`、`do_remove`等）。最多的函数名：`do_cut` 2 处、`do_remove` 2 处、`do_wash` 2 处、`do_wrap` 2 处、`do_ling` 1 处。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 6 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/bwdh/kantai.lpc`（`do_abandon`、`do_practice`、`do_study`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 12 个函数没有补（inquiry 6, chat_msg_combat 6）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/npc/hua_girl.lpc`:`ask_me`、`/d/emei/npc/guide.lpc`:`ask_job_begin`、`/d/emei/npc/guide.lpc`:`ask_job_finish`、`/d/huanghe/npc/tc_hu.lpc`:`ask_job`、`/d/huanghe/npc/tc_you.lpc`:`ask_join`、`/d/shaolin/npc/xuanci.lpc`:`ask_tiaoshui`、`/d/xiakedao/npc/huang.lpc`:`auto_perform`、`/d/xiakedao/npc/laozu.lpc`:`auto_perform`、`/kungfu/class/murong/baichuan.lpc`:`auto_perform`、`/kungfu/class/shenlong/pang.lpc`:`auto_perform` 等另外 2 个。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 8 个文件里有 13 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`nosave/setskill_player` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/pigroom_b`；`/d/city/duchang2.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 2 个子目录写日志：`log/beijing`（`d/beijing/helper.lpc`）、`log/test`（`clone/npc/shan.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/beijing`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 10 个文件里 12 行只含这个指针的行（`"song": (: ask_me :),` `"出发": (: ask_job_begin :),` `"结束": (: ask_job_finish :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
