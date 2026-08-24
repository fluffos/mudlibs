
## 深度功能测试（第二轮，2026-08-03）

之前的会话只验证到"能登录、score 卡在'还没有出生'"这一步，把
"还没有出生"判断为既定的创世任务设计后就没有再往下走。本轮实际把
这整个"投胎"创世任务链走通了——`hhsj`（同宗，"洪荒世界"）那轮会
话明确说"完成整条链条超出首次上线验收的范围，没有走完"，本轮是这
个项目第一次真正把这一整套流程走到底。

proactive 检查 AGENTS.md 已归档的四类常见坏味道：`private nomask
command_hook` 命中的 `feature/command喵.lpc` 核实是死档案（真正生
效的是 `feature/command.lpc`，已经是干净的 `nomask`，通过
`F_COMMAND` 宏定义确认）；§8.9 的 age 判断本来就正确读的是
`user`；printf 调试残留、stat/water 键名均未命中。

**投胎流程实测**（通过自定义手机 App 协议，登录行格式
`id║密码║密文║邮箱`，命令走普通 telnet 一样的动词）：进入"世外桃
源"→（原本设计中提到的"四个方向选择品质"实际已被注释掉，只剩
south 一个有效出口，走 south）→"阎罗殿"→ 先 `washto 20 20 20 20`
（在忘忧池洗四项属性点，四个数之和须为80）→ `pianshu msx`（刷新天
赋）→ `knock 5`（选"光明磊落"性格）→ `born 扬州人氏`（选择投胎籍
贯，选项还有段氏皇族/唐门世家/中原苗家/关外胡家/慕容世家/欧阳世家
共七个）。

**发现并修复的一个真实 bug（新增 AGENTS.md §7.70）**：`born` 执行
到一半时，试图把角色移动进新手村"世界之树"广场，负责在这个场景生
成的 NPC `d/newbie/npc/laocunzhang.lpc`（老村长）编译失败：
`query("id", me)` ——这份代码库里 `query()` 的真正签名统一是
`query(string prop, int raw)`（`raw` 是"是否返回未格式化原始值"
的开关，不是目标物件！在 `feature/dbase.lpc`/`inherit/room/
room.lpc`/`adm/daemons/examined.lpc`/`u/rock/dbase.lpc` 四处定义
里核实过，签名完全一致）——把一个物件 `me` 传给期待 `int` 的第二
参数，是静态类型检查能直接抓到的错误。这行代码显然是想写"查询
`me` 自己的 id"，正确写法应该是 `me->query("id")`。已修复；用同一
个存档的 fluffos 账号在修复前后各走一次完整投胎流程对照验证：修复
前 `born` 卡死在这个编译错误上，`score` 一直显示"还没有出生呐"；
修复后完整走通，最终 `score` 正确显示【天界总管】称号、性格【光明
磊落】、天赋【如鬼似魅】【越空提升】、四项属性 20/20/20/20，食物/
饮水槽满，新手村场景和老村长 NPC 的问候语都正常渲染，没有再触发任
何报错。

**范围备注（这次没有一并修完，留给以后专门排查）**：用
`grep -rlP 'query\("[a-zA-Z_/]+",\s*(me|ob|user|this_player\(\)|
this_object\(\))\)'` 在这份档案全库扫了一遍，命中 **162 个档案**
——说明这不是孤立的一次打字失误，而是贯穿这份代码库很大一部分的
系统性习惯性写法（`feature/apprentice.lpc`、`kungfu/class/`下大
量武学招式档案等）。每一处具体会不会真的编译失败，取决于该调用点
`me`/`ob` 这类变量在当时的声明类型是不是能被驱动的静态类型检查器
看穿（比如声明成 `mixed` 就可能绕过编译期检查，只在运行时才出问
题，甚至完全不报错静默出错）——这次没有逐一验证，只修了实测过程
中真正拦路的这一处。162 个档案的规模明显超出单个 lib 深挖会话的合
理范围，已记录进 AGENTS.md §7.70，留给未来一次专门的系统性排查
（参照 §8.3a `command_hook` 那次批量排查的做法：先分类，每一处都
要过一遍真实开机验证再动手，不要盲目全局替换）。

顺带核对了 `d/register/entry.lpc`（"世外桃源"起始房间）`item_desc`
里注释掉的一段说明文字提到"四个不同方向的出口代表不同的角色发展方
向"，但对应的 east/south(原)/west 三个出口在代码里确实被注释掉
了——查证后发现这不是当前生效流程的缺陷：真正的选择"品质"/性格/
天赋机制早已迁移到阎罗殿的 `born`/`knock`/`pianshu` 这一套菜单命
令上，跑得完全正常，这三个方向出口和对应的 `roome.lpc`/`rooms.lpc`
/`roomw.lpc` 档案是被更新设计取代后留下的死代码，不是当前流程的必
经步骤，未做改动。

管理员账号 fluffos 因为本轮实际走完了投胎流程，存档
（`data/user/f/fluffos.o`、`data/login/f/fluffos.o`）里记录了真实
的天赋/性格/属性状态，已随本次改动一并提交（这是既有约定要持续维
护的演示管理员账号，不是随手创建的测试角色）。

**未覆盖范围**：门派拜师、真正的中原地图探索、战斗系统因时间原因
未实测（"投胎"完成后已可以正常使用 `score`，具备继续测试战斗的前
提条件，留给后续会话）。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

自定义手机 App 协议（不是原始 telnet）：登录发送"id║password║ciphertext║email"（║ = U+2551），新角色创建发送"gender║img║nickname"（通过直接阅读 logind.lpc 的 jiance()/get_user()/get_char() 调用链逆向工程得出）。WASM 修复：修好了 GBK 每字 2 字节的 is_chinese() 检查（现在是码点判断），给 band.lpc 的 is_banned() 打了本地回环放行补丁，修复了 clone/user/user.lpc 的 accept_kill() 里 §7.50 的 is_killing(ob) 对 is_killing(ob->query("id")) 不匹配。score 卡在和 hhsj 相同的 nitan 血统"已出生"dbase 属性上（不是 bug，是有意的创世任务设计）。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。完整的注册+look/score/quit+管理员 update 已在 WASM/原生下全程验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`DATABASE_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 5 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5921
处独立、未注释的 replace_program(ROOM); 整行。另外手工清理了造房工
具代码生成模板里内嵌的同一形状，共发现三份独立的造房工具
（`clone/misc/roommaker.lpc` 1 处、`u/lonely/obj/roommaker.lpc` 3
处、`u/lonely/obj/roommk.lpc` 3 处，后两份是巫师个人目录下的完整独
立拷贝，同样内嵌了这个模板 bug，一并清理）。删除总计 5928 行，与本
次扫描 FINDINGS.md 记录的 wxddym 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40189 正常监听，
work/log/debug.log 全程无新增内容。本库登录用自定义"指尖客户端" App
协议而非普通 telnet 文本菜单（详见上方"迁移自 meta.json"记录），且
第一行任意内容都会被 jiance() 无条件放行，真正的登录行要在第二行发
送 UTF-8 编码的 `id║密码║密文║email` 格式（GBK 编码会导致分隔符字
节不匹配、explode() 拆不出 4 段而报"未知错误"——排查耗时最长的一步）；
登录成功后世界会持续推送任务精灵后台广播消息，属正常游戏内容非卡
死。用已播种的 `fluffos`/`Mud@2026` 管理员账号连线成功（"目前权
限：(admin)"），在世界之树/村间小路之间往返移动，`look`/`score`
均正常，未见任何 "cannot replace"/"cannot bind" 或崩溃迹象（唯一
噪音是 `cmds/std/go.lpc` 首次惰性编译时打印的几个无害 Unused local
variable 警告，与本次修复无关）。测试产生的
`data/{login,user}/f/fluffos.o` 存档时间戳 diff 已 `git checkout`
撤销，不提交。驱动按精确 PID kill。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: `bai.lpc` has a PRE-EXISTING, unrelated compile error (`query("reborn_offer", ob)` -- bad arg-2 type, int vs object -- at the original file's own line, untouched by this edit) that makes the whole file fail to load regardless of this fix. Confirmed via `git diff` that the erroring line is unmodified context, not something this edit introduced. The guard fix is textually correct and ready the moment the underlying pre-existing bug gets fixed separately.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## §7.79 `addn()` investigation on this lib -- NOT the misdirected-write bug (2026-08-21)

AGENTS.md §7.79 documents `addn("stat", delta)` bare 2-arg calls silently
writing to the wrong object on the `xfbhh`/`hhsj`/`nitan170911`/`nitan6`/
`nt6`/`nt6nitan6win` lineage, because those libs' `adm/kernel/simul_efun/
wizard.lpc` defines a broken `addn` shim whose `this_object()` resolves to
the simul_efun object. `wxddym` was flagged unconfirmed because it has no
such shim anywhere in its tree (~67 files / ~143 call sites, mostly
`kungfu/class/` and `kungfu/skill/`), so it was unclear whether `addn()`
resolves to anything at all here.

Live-driver test (real boot on port 40189, admin `fluffos`/`Mud@2026` via
the app protocol, using the `update <file>` wizard command -- which forces
a real compile via `call_other(file, "???")` -- to force-load individual
`.lpc` files and read the compiler's own error text):

- Confirmed via source grep first: no `addn` definition anywhere in the
  simul_efun chain (`adm/single/simul_efun.lpc` includes 9 files under
  `adm/simul_efun/`, none define `addn`), and no `addn` in fluffos'
  own `src/packages/*/*.spec` efun tables -- so it isn't a native efun
  in this driver build either.
- Live compile of `/d/tiezhang/obj/haigu1.lpc` (a clean, isolated
  bare-call site: `addn("init", 1);` in `init()`, no other bugs in the
  file) produced a **hard compile-time error**, not a runtime
  misdirect: `Error: Undefined function addn`, and the whole file then
  fails to load (`*No program in object '/d/tiezhang/obj/haigu1'!`).
  Any room/NPC that clones or references this object is broken outright,
  not just the one stat write.
- Live compile of `/d/qingcheng/obj/zhui.lpc` confirms this is not
  limited to bare 2-arg calls: both `addn("count", -1);` (bare) and
  `addn("neili", -300, me);` (explicit 3-arg target, the "correct" form
  per the §7.79 remedy pattern) fail identically with `Undefined
  function addn`. So in this lib `addn` is not a degraded/misdirected
  efun -- it is completely absent, at every call arity.
- `/kungfu/class/misc/jinlun-fawang.lpc` and `/kungfu/class/hengshan/
  xian.lpc` also fail to compile, but carry additional *unrelated*
  pre-existing bugs of their own (an undefined `full_self()`, a
  `query("prop", object)` arg-2-type bug matching this file's own
  earlier `query()` signature note above, and in `xian.lpc` an
  `inherit F_MANAGER;` macro-not-a-string syntax error) -- so those two
  are not clean single-cause reproductions, `haigu1.lpc`/`zhui.lpc` are.
- Smoking gun for *why*: `clone/npc/warcraft.h:609` contains
  `return efun::addn(prop, data);` -- explicit `efun::` scope
  resolution, meaning whoever wrote this mudlib assumed `addn` was a
  genuine **compiled-in driver efun**, not a mudlib-level function. The
  `xfbhh`/`hhsj` lineage's `wizard.lpc` shim was almost certainly a
  patch someone wrote for a driver build that lacked this efun -- but
  the shim itself has the `this_object()` bug documented in §7.79. This
  driver build (`fluffos/build-debug`) lacks the efun entirely and
  `wxddym` never got an equivalent simul_efun shim, so every `addn()`
  call site in this lib -- bare or explicit-target, `kungfu/` skill
  effects or room objects like `haigu1.lpc`/`zhui.lpc`/`xiang.lpc` --
  fails to compile and the containing file never loads.

**Conclusion: this is scenario (a) from the investigation brief** -- a
hard "Undefined function" failure, not the silent stat-misdirection
shape from §7.79. It's also broader than a simple copy of the §7.79
remedy would fix: `warcraft.h`'s `efun::addn(...)` call would still fail
even with a working simul_efun `addn()` added (that scope operator
specifically bypasses simul_efun), and cross-object calls like
`no4->addn(...)`/`who->addn(...)`/`me->addn(...)` elsewhere in this lib
depend on the *target* object defining its own `addn`, not the caller's.
A real fix needs to enumerate all of: bare self-calls, explicit-target
calls, cross-object `->addn()` calls, and the `efun::addn()` call in
`warcraft.h`, and is out of scope for this investigation session --
left for the orchestrator to scope as a follow-up (no fix applied here).
No lasting changes made to this lib this session; the only writes were
transient login-tick save-file churn on the demo `fluffos` account,
reverted with `git checkout` since no real gameplay progress happened.

## §7.79 `addn()` fix on this lib (2026-08-21)

Implemented the fix scoped out of the investigation above. Added a
simul_efun shim in `adm/simul_efun/object.lpc` (the file's own object-
utility helpers, e.g. `present()`/`destruct()`, made it the closest
stylistic fit -- this lib's `wizard.lpc` is narrowly about wizhood/
SECURITY_D status, unlike the `xfbhh`/`hhsj` lineage where that
filename happened to hold the (broken) shim):

```lpc
varargs mixed addn(string prop, mixed data, object ob) {
  if (!ob) ob = this_object();
  return ob->add(prop, data);
}

varargs mixed addn_temp(string prop, mixed data, object ob) {
  if (!ob) ob = this_object();
  return ob->add_temp(prop, data);
}
```

Both delegate to `feature/dbase.lpc`'s existing `add()`/`add_temp()`,
matching the proven §7.79 remedy pattern exactly. Added `addn_temp` too
after grepping the tree and finding ~100 more bare `addn_temp(...)`
call sites with the identical undefined-function problem (not
mentioned in the original investigation, which only grepped for
`addn(`) -- same root cause, `add_temp()` already existed on
`feature/dbase.lpc` alongside `add()`.

Also fixed the one `efun::`-scoped call site: `clone/npc/warcraft.h:609`
was `return efun::addn(prop, data);` -- that scope-resolution operator
can only ever bind to a genuine compiled-in driver efun (which this
build lacks), so no simul_efun shim could ever fix it while the prefix
stayed. Changed to a bare `addn(prop, data)` so it now resolves through
the new shim.

**Live verification** (real boot, port 40189, admin `fluffos` via the
app-protocol Python harness -- note: this mud's status bar re-broadcasts
every real-time second or so, which made a naive fixed-idle-timeout
`recv()` loop hang indefinitely waiting for a quiet gap that never came;
had to switch to a hard wall-clock cap per read instead of relying on
socket idle-timeout):

- `update /adm/single/simul_efun` and the driver's own boot log: no
  compile errors, simul_efun object loads clean (also implicitly proven
  by the fact the driver accepted connections at all -- a broken
  simul_efun refuses to boot).
- `update` on both files named in the original investigation:
  `/d/tiezhang/obj/haigu1.lpc` recompiles clean (`重新编译...成功！`);
  `/d/qingcheng/obj/zhui.lpc` still fails, but now *only* on its
  pre-existing, unrelated `query("prop", object)` arg-2-type bug (the
  same widespread ~162-file pattern noted elsewhere in this file's
  earlier round-two entry) -- zero "Undefined function addn" anywhere
  in either file's output now.
- Spot-checked ~15 more files across different areas of the tree via
  `update` (`kungfu/skill/xianglong-zhang/long.lpc`,
  `maze/battle3/meng/kehan.lpc`, `clone/npc/warcraft.lpc` (pulls in the
  fixed `warcraft.h`), `maze/necropolis/npc/zombie_power.lpc`,
  `d/gaibang/obj/qingzhu-ling.lpc`, `kungfu/class/misc/qilin.lpc`,
  `maze/battle3/ydmen.lpc`, `clone/goods/cemashi.lpc`, several more):
  **zero** produced an "Undefined function addn" error anywhere. Several
  fully compiled clean end-to-end (`adm/npc/obj/drum.lpc`,
  `adm/daemons/bunchd.lpc`, `kungfu/skill/tie-zhang.lpc`); the rest
  still fail to load, but exclusively on the same pre-existing,
  unrelated `query()`/`query_temp()` arg-2-type bug family (and in a
  couple of cases `full_self()`/`add_skill()` undefined-function bugs
  and one `GUARD_CMD` undefined-macro bug) -- none of which this task
  was scoped to touch.
- **Live functional trigger** (not just compile-check): `clone
  /d/tiezhang/obj/haigu2` twice in a row, each time cleanly succeeding
  with no runtime error. That file's `init()` does
  `ob = new("/d/city/obj/duanjian"); ob->move(me); addn("init", 1);`
  guarded by `query("init") == 0` -- a bare, self-target 2-arg call
  identical in shape to the one from the investigation's clean repro.
  Before this fix the whole object would have failed to compile at
  clone time; after, it clones and its `init()` runs to completion
  (confirms the shim's `this_object()` default-target path actually
  executes at runtime, not just that it type-checks). Sibling
  `/d/tiezhang/obj/haigu1.lpc` was also tried but hit a *separate*,
  pre-existing, unrelated bug first: `new("/u/qingyun/mingjiao/obj/
  parry_book")` returns 0 because that file doesn't exist anywhere in
  this lib, so `ob->move(me)` on the next line throws before ever
  reaching the `addn()` call on the line after -- a genuine missing-
  content bug, not touched here, and coincidentally why the
  investigation's original repro on `haigu1.lpc` only ever exercised
  the *compile-time* addn error, never its runtime behavior.
  A full combat-triggered, `score`-visible stat change (e.g. via
  `kungfu/skill/tie-zhang.lpc`'s clean `addn("neili", -100, me)`) was
  not pursued -- it requires training the skill and a live combat
  encounter, which didn't fit this task's bounded budget on top of the
  compile sweep and the haigu2 functional trigger above; the shim's
  explicit-`ob`-target path is structurally identical to the proven
  self-target path already exercised live, and to the same one-line
  redirect pattern validated on six other libs per §7.79.

**Known, deliberately out-of-scope residual** (already flagged in the
investigation above, confirmed still present): bare/direct `addn()`/
`addn_temp()` calls -- including the explicit-3rd-arg-target form like
`addn("neili", -300, me)` -- resolve through the new simul_efun shim
correctly, because the compiler binds unqualified identifiers to
simul_efun at compile time. But dot-call sites like `me->addn(...)`,
`no4->addn(...)`, `who->addn_temp(...)` (found e.g. in
`adm/daemons/bunchd.lpc`, `adm/npc/obj/drum.lpc`,
`adm/daemons/auctiond.lpc`, `kungfu/skill/longxiang/perform/
longxiang.lpc`) do **not** -- `call_other()`/`apply_low()` has no
simul_efun fallback in this driver (confirmed by reading
`fluffos/src/vm/internal/apply.cc`'s `apply_low()`), so those call
sites compile clean (the compiler can't statically verify methods on a
dynamically-typed `object` call_other target) but will throw
"Undefined function addn" *at runtime* the moment they actually
execute, unless the target object happens to independently define its
own `addn()`. `bunchd.lpc` and `drum.lpc` both compiled 100% clean in
this session's spot-check specifically because of this blind spot --
compiling clean is not proof those particular calls work. Left
unfixed per this task's explicit scope (shim + the one `efun::` site
only); a real fix for the dot-call sites would need either a shared
base-class `addn()`/`addn_temp()` wrapper on `feature/dbase.lpc` itself
(so every object that already has `add()` also has `addn()` on its own
program, closing the `call_other` gap) or a per-call-site rewrite back
to bare calls with an explicit target -- worth a dedicated follow-up
session.

No driver crash, no new debug.log entries, no other files touched.
Reverted transient `data/{bunchd,dbased,newsd}.o` and demo-account
`fluffos` save-file churn from the login/clone testing with `git
checkout` before committing (per the standing "git add -u, not bare
dir" + "no runtime logs in docs" conventions) -- only the two real
source edits (`adm/simul_efun/object.lpc`, `clone/npc/warcraft.h`) are
part of this commit.

## §10.7 round-three/four gap closure: 拜师 apprenticeship, map exploration, combat (2026-08-24)

Closed the three gaps the earlier §10.7/round-two sessions left explicitly
untested (see the round-two entry above): sect apprenticeship, real map
exploration beyond the newbie-village starting room, and combat. Also
specifically checked whether `bai.lpc`/`apprentice.lpc` needed the §7.117
"first-time applicant has no family yet" guard, since this lib's
`bai.lpc`/`apprentice.lpc` files had only been touched for the unrelated
§7.70 `query()` arg-type bug this session, never audited for §7.117.

**§7.117 check -- clean, no fix needed.** `feature/apprentice.lpc`'s
`recruit_apprentice()` already guards the betrayer comparison with
`family_name = ob->query("family/family_name"); if (family_name &&
family_name != my_family["family_name"])` (existence-checked before
comparing). `cmds/skill/apprentice.lpc` and `cmds/skill/recruit.lpc`
(the interactive verb wrappers) both gate every family-name comparison
behind `mapp(family) && ...`/`mapp(ob->query("family")) && ...`. All
three already match the "correct" pattern from the AGENTS.md §7.117
catalog. Confirmed live: a fresh, family-less character's apprenticeship
completed cleanly with no false "背叛师门" rejection (see below).

**Map exploration**: walked the newbie-village road network on foot
(世界之树 -> 青石小路 -> 练武场 -> 后村小路 -> 后村山路 -> 乱石岗, and
back), then used the admin `goto` wizard command to reach
`/d/shushan/bingqiku` (蜀山派/Shushan-sect weapon hall, part of the
`中原正道` righteous-sect network reachable from the main city map) and
back to newbie-village combat rooms. No broken exits, no crashes.

Noted but NOT fixed (no error signature, matches the existing "dead
newbie-quest menu option" pattern already documented in this file's
round-two entry): `d/newbie/npc/huabo.lpc`'s village-exit dialog
(`ask hua about 出村`) only *displays* option "1" (leave to 扬州武庙) even
though the underlying `get_select()`/`get_sel_fam()` code for option "2"
(teleport to one of six family/宗族 entrance rooms) is still fully
functional if invoked directly -- looks like an intentionally
simplified/pruned menu, not a break. `d/newbie/npc/wubo.lpc` (the
newbie-quest's own designated apprenticeship target, id `wu bo`/`wu`/
`bo`) has its `attempt_apprentice()` override entirely commented out, so
`bai wu` there leaves the offer permanently pending (the base
`feature/apprentice.lpc` main-flow calls `ob->attempt_apprentice(me)`,
which silently no-ops via this driver's call_other-to-missing-function
behavior -- no error, just nothing happens). This makes the in-village
"拜师" newbie-quest step (topic 107 in `laocunzhang.lpc`) permanently
uncompletable as written, but it never surfaced as a crash or logged
error, so per this project's "no error signature = design, not a bug"
rule it's documented here rather than "fixed" -- worth flagging for a
future content-focused pass, not a programming-bug sweep.

**Apprenticeship -- works cleanly.** Used a real sect master instead:
`kungfu/class/shushan/lingyunzi.lpc` (凌云子, 蜀山派/Shushan sect,
reachable via `/d/shushan/bingqiku`), whose `attempt_apprentice()` calls
`command("recruit " + ob->query("id"))` for a family-less applicant.
`bai yunzi` (id must include the space-separated full alias, e.g.
`bai wu bo`/`bai yunzi` -- bare concatenated ids like `bai wubo` don't
match `present()`) on the demo `fluffos` account (previously family-less
per the round-two entry) completed instantly and correctly: `score`
went from 【门派】普通百姓/【师承】你还没有拜师 to 【门派】蜀山派/
【师承】凌云子, title 蜀山派第四代弟子. No crash, no rejection, no
§7.117-style false "背叛师门" -- consistent with the clean guard code
found above.

**Combat -- works cleanly, but confirms a real bug elsewhere.** The demo
account's combat stats are effectively zero (战斗攻击力 1, 战斗伤害力 0
-- an artifact of the round-two "投胎" reincarnation choices, not this
task's concern) and `qi` (气血/HP) regen was capped below the 30%
threshold `kill`/`fight`/`hit` all require (`cmds/std/kill.lpc:39`,
`fight.lpc:29`, `hit.lpc:32`: `me->query("qi") < me->query("max_qi") *
3/10` -- a legitimate anti-suicide safety gate, not a bug). `yun heal`
topped `qi` over the threshold; `kill tu` (野兔/wild rabbit,
`clone/quarry/tu`, present in numbers in several newbie-village rooms)
then engaged combat cleanly: `看起来野兔想杀死你！`, the character's
near-zero combat stats correctly triggered the auto-flee AI path
(`看来该找机会逃跑了...`, moved rooms), repeated twice more with the
same clean resolution. No crash, no debug.log error from the fight
itself.

**Real bug found and fixed: `feature/dbase.lpc`'s `add()` crashes on any
non-interactive `add("potential", ...)`/`add("combat_exp", ...)`
call.** While waiting (real-time, for `qi` to regen) for the combat
test above, a genuine new runtime error appeared in `debug.log`:

```
执行时段错误：*Bad argument 1 to EFUN call_other()
Expected: object, string, array,  Got: int(0).
程式：/feature/dbase.lpc 第 81 行
物件：/clone/user/user
呼叫来自：/clone/user/user.lpc 的 reset() 第 83 行
呼叫来自：/feature/dbase.lpc 的 add() 第 81 行
```

`feature/dbase.lpc`'s `add(string prop, mixed data)` (the core
mapping-backed stat-write primitive nearly every object in this lib
inherits via `F_DBASE`) does `object me; me = this_player();` and then,
for `prop == "combat_exp" || prop == "potential"` specifically, calls
`me->query_temp("last_eat/exp")` unconditionally to check for an active
"just ate a food buff" exp/potential multiplier -- with no null check.
`this_player()` is legitimately 0 whenever `add()` runs outside an
interactive command context. `clone/user/user.lpc`'s own `reset()`
(a driver-invoked lifecycle callback, not player-initiated) does exactly
that: `add("potential", 1)` whenever `potential - learned_points < 100`
-- a condition true for essentially every low-level/fresh character,
including the demo account mid-testing. This is a real, previously
undocumented crash bug (call_other on `int 0`, a driver-API-misuse
pattern with a clean error signature), not a content/balance issue, and
it fires on `reset()` for any qualifying character, not just this
session's test account -- high blast radius since `add()` is the single
shared stat-write primitive.

Fix (one line, `feature/dbase.lpc` line 81):
```lpc
// BEFORE:
    if (me->query_temp("last_eat/exp") > 1) {
// AFTER:
    if (me && me->query_temp("last_eat/exp") > 1) {
```

Verified: `lpcc --batch` full-tree compile check passes clean (`PASS
/feature/dbase`); live `update /feature/dbase` on the running driver
recompiled successfully (`重新编译 /feature/dbase.lpc：成功！`); a
further ~115s idle wait with the fix loaded produced no recurrence of
the error (the mudlib's own `debug.log` rotated mid-session so an exact
before/after count wasn't directly comparable, but zero new occurrences
appeared in the post-fix window against the same live triggers that
produced one in a comparable pre-fix window).

Committed: the `feature/dbase.lpc` fix, plus the demo `fluffos` account's
real apprenticeship-and-combat progress (`data/{login,user}/f/fluffos.o`
-- per the existing convention of keeping this account's genuine
playthrough state). Reverted transient `data/newsd.o` churn. Driver
killed by exact PID, no tmux session left running, no test characters
created (all testing reused the existing demo `fluffos` admin account).
