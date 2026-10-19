
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

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). Confirmed the
real active wrapper is `feature/command.lpc` via `F_COMMAND` (`inherit/char/char.lpc`
etc. all `inherit F_COMMAND` -> `/feature/command.lpc`); a same-directory
`feature/command喵.lpc` also has an identical `enable_player()` body but
nothing inherits it (confirmed with a corpus grep) -- a dead orphan file,
left untouched. Originally flagged as a possible false positive
(pre-existing `static int enabled = 0;` flag) -- but this is NOT the safe
shape: `enabled = 1` is set AFTER `enable_commands()` returns, not before,
so it does not guard the synchronous reentrant
`init()`->`setup()`->`enable_player()` call that happens DURING
`enable_commands()`. Confirmed the reachable chain is real:
`d/shushan/npc/zhangmen.lpc`'s `init()` unconditionally calls `me->setup()`
(line 53), which reaches `enable_player()`; `feature/damage.lpc`'s
`revive()`/`cmds/std/sleep.lpc`'s `wakeup()` re-invoke `enable_player()`
while already `living()`, ruling out a bare `living()` guard. Fixed by
adding a true `in_enable_player_now` reentrancy flag alongside the existing
`enabled` bookkeeping variable (left untouched, `disable_player()` still
needs it). Verified via single-file `lpcc --batch` PASS.

## Shop + compile-warning flood + goto bind crash (2026-09-04)

2026-08-24 already apprenticed demo `fluffos` to 蜀山派凌云子 — this
pass is shop-only. Login is still the Lonely GUI protocol: first line
`ver1.0,<ZJKEY>` (this boot the salt was literally `123456789abcd`),
send that same token (any non-empty arg except `6278038` works —
`jiance()` compares the *server* salt `str` against `ZJKEY`, so the
illegal-client branch is dead), then `fluffos║Mud@2026║x║x@x.com`
(U+2551 `║`, four fields). Comma-separated still fails with 未知错误.
Lands 世界之树 every reconnect (room is not sticky). `score` still
shows 【门派】蜀山派 / 【师承】凌云子. No player-visible
`编译时段错误` flood after the master `log_error` patch below.

**Shop — works.** `goto /d/city/zuixianlou` (醉仙楼) after the
messaged bind fix below. 店小二 is `F_DEALER`
(`d/city/npc/xiaoer2.lpc`: jitui/jiudai/baozi/kaoya). This family's
`do_buy` is GUI-quantity: bare `buy jitui` prompts
`你要买多少【jitui】？`; the list itself emits `buy 1 烤鸡腿`.
`clone /clone/money/gold` then `buy 1 jitui` →
`你从店小二那里买下了一根烤鸡腿`. Inventory after: 1两黄金 +
99两碎银 + 20文铜钱 + 烤鸡腿 (2 gold − 80文). No 丐帮 refuse
(character is 蜀山派; `feature/dealer.lpc` has no 穷叫化 gate
anyway). `list`/`buy` at 世界之树 hit `cmds/usr/{list,buy}` (摆摊)
instead — must be in the dealer room.

**Bug 1 — `log_error()` has no warning gate (AGENTS.md §15w).**
`adm/single/master.lpc` unconditionally broadcast every compile
warning as `编译时段错误` (Unknown #pragma / unused-variable / illegal
nosave). First login on the previous boot dumped dozens of them.
Gated with `strsrch(message, "arning:") == -1` (same as nitan3/es2).
Master object only picks this up on driver reboot. File is LF.
Post-reboot login transcripts have zero `编译时段错误` lines.

**Bug 2 — `goto` aborted on `MESSAGE_D->find_user()`. **
`cmds/wiz/goto.lpc` calls `MESSAGE_D->find_user(arg)`, which
`create()`s `/adm/daemons/network/messaged.lpc`. `startup_udp()` →
`socket_bind(socket_id, my_port)` got string `"10"`
(`Expected: int Got: "10"`). Uncaught error aborted goto before move;
player stayed at 世界之树. `LOCAL_PORT()` is
`((int) get_config(__MUD_PORT__))` but the bare `(int)` cast is a
no-op on the string `get_config()` actually returns, and
`MESSAGE_PORT` (defined 10 in `include/net/messaged.h`) arrived as
string `"10"` too. Fixed `create()` to
`my_port = to_int(LOCAL_PORT()) + to_int(MESSAGE_PORT);`. File is LF.
Reboot: messaged loaded cleanly during preload; live `goto` then
reached 醉仙楼 (`你化作长虹而去` / `你到了地方，落下遁光`).

**Bug 3 — same string-port class in `versiond.lpc`.** After
`Initializations complete` this boot logged
`*Bad argument 2 to socket_bind() Expected: int Got: "12"` at
`versiond.lpc:239` `in_server()`. Same shape:
`port = get_config(__MUD_PORT__) + VERSION_PORT` (`VERSION_PORT` is
12). Changed to `to_int(get_config(__MUD_PORT__)) + to_int(VERSION_PORT)`.
File is LF. `in_server()` only runs from `create()`, so this needs a
later reboot to bind; shop path does not depend on it. `payd.lpc`
`ZJPAYPORT` 3001 did not fire on this boot; `dns_master.lpc` uses
`SRVC_PORT_UDP(mud_port())` and did not error.

`debug.log` for `cd libs/wxddym && driver` is
`libs/wxddym/log/debug.log` (opened before chdir into `work/`).
Mudlib `error_handler()` returns `standard_trace` into that same
driver log; `log_error()` also appends to `work/log/log`. Truncated
debug.log before this boot; Boot Time Fri Sep 4 04:39:54 2026 matches.
Only runtime error this boot was the versiond bind above (pre-patch).
No new errors after the shop commands. Demo `fluffos` save churn
(gold/jitui) left uncommitted.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 where the text sits on the opener's line (`@LONG   text...LONG`, the newlines were lost): `d/city/task1/huodu.lpc`.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1088 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questsd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 2286 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questsd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理、追杀任务杀手

`scripts/lpc_warnings.py wxddym --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 2479 个 `.lpc` 和 35 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：2124 -> 2123 通过，差的两项都不是这次改动造成：`d/migong/lev20/npc/lev3`/`lev5` 两边各有一个批量加载失败（已知的批量假象，单独加载都过），`quest/chousha/killer` HEAD 起就随机加载失败（见下）。改过的头文件的 2627 个包含者 2533 -> 2533 通过。审计列出的“删了但仍读取”都是重建后的声明语句里留下的名字（逐一看过不能编译的那些文件）。
手改：`globals.h` 有 `#define static nosave`，旧 `static` 函数成了 `Illegal to declare nosave function`，按扫描诊断把 10 个文件的 26 处改成 `protected`（master、treemap、questd、dbased、cmwhod 等）；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去。启动时警告 60 -> 0；新进程登录到版本验证正常。

追杀任务的三个杀手 `quest/chousha/killer.lpc`、`killer1.lpc`、`killer2.lpc` 的门派表里有本库没有的武功（honghua-shengong、dugu-jiujian、wugong-zhao 等十几种），`F_SKILL` 的 `set_skill()` 遇到就 `error`：`killer` 约一半加载失败，`killer2` 每次都失败。三个文件各加一个 `set_skill()`，跳过本库没有的武功（`map_skill` 随之跳过）；修正后 `killer` 单独加载 8 次全过，`killer2` 由 HEAD 失败变为通过。注意：本库没有地方放置 `quest/chousha/yelao1`（`d/wizard/guest_room` 里那一行被注释掉），`haojie.h` 也只有它在用，这几个杀手目前是休眠内容。
`d/city/task2/shashou.lpc`、`renzhi.lpc` 和 `inherit/char/manager.lpc` 调用 `NAME_D->man_name()` 等，本库的 `NAME_D`（`adm/daemons/named`）是保存玩家名字的，没有这些函数（来自 xkx100 的名字生成器没有带过来）；但没有任何文件生成 `renzhi` 或继承 `manager`，未改，记录在此。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、0 处去后缀（如 `adm/daemons/taskd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒，`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽，`taskd` 从来加载不起来——玩家的 `task`、`locate` 指令只显示“这里发现了臭虫”。改正切片和列表（列表空了就停）；真正走房间之后首次冷加载要 5 秒以上，`maximum evaluation cost` 提到 10000000（nt6 原本就是最大值）。新进程建人物后 `task` 列出使命物品、`locate` 可用；HEAD 两者都失败。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 22 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 2 个文件；改动 22 个文件，HEAD 与工作树各载入一次无回退（22 objects; HEAD PASS 20, tree PASS 20; regress 0; newly loading 0），这些文件的警告 27 -> 4。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `include/globals.h` 原档用 `#define replace_program(x) ""` 关掉 replace_program，每个调用展开成孤立的 `"";`（110 条警告）。改为空展开 `#define replace_program(x)`，意图不变。
- `d/maze/` 五个 NPC（孽龙等）：`atoi((userexp, 6000))` 是逗号表达式，本库 `atoi()` 对非字符串返回 0，这一项恒为 0；原意无法确定，删去这一项（行为不变）。
- `cmds/wiz/who1.lpc` 孤立的分隔线字符串、`u/rock/duihuan.lpc` `for (i - 0; …)`，一并改正。
- 47 个对象载入无回退。

- 2026-10-12：`adm/npc/obj/xiang.lpc`、`u/jerry/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮后，用 `scripts/lpc_twin_port.py adopt nitan170911 wxddym --pre e7b0eac1a63~1` 搬来 nitan170911 同日整理里与本库逐 token 相同的 15 个文件（幻境 `fairyland_quest/npc_obj/*` 的重复声明、`template/gem|weapon/*` 的模板表、`clone/obj/genmap.lpc`、`tianshen.lpc`），其余按同样的改法手工补，能编译的文件警告清零。改动的 81 个对象 HEAD 与工作树各载入一次：HEAD PASS 81，tree PASS 81，regress 0。

- `clone/misc/swmuding.lpc`（神木王鼎）：自己声明了一张 `insects` 表，与继承的 `clone/misc/muding.lpc` 的 `insects` 同名，而读表的是木鼎的代码，神木王鼎自己的虫表从来没用上。改名 `sw_insects`，`create()` 里 `insects = sw_insects;`（nitan170911 同修）。
- `clone/xiang.lpc`、`clone/newbox/xiang.lpc`、`clone/vip/xiang.lpc`：`varargs int remove() { saveone(); }` 盖掉了 `feature/move.lpc` 的 `remove(string euid)`，箱子销毁时不减负重、不清 handing；改成 `saveone(); ::remove(euid);`（KB 06 §7.239 变体）。
- `feature/food.lpc`、`feature/liquid.lpc`：`eat`/`drink` 对 `only_do_effect` 的物品 `return ob->do_effect(me)` 当命令结果，基类却是 `void do_effect()`；改 `varargs int do_effect(object me) { ...; return 1; }`，与重载它的 `water.lpc`、`wan.lpc`、`pigpart.h` 同型。
- `d/maze/*/maze.lpc`（9 个）与 `maze/forestnew/maze.lpc`：叶子的 `unique_rooms` 与 `VRM_SERVER` 的同名变量重复，叶子只把它传给 `set_unique_room()`，改名 `maze_unique_rooms`。
- `quest/shenshu/npc/man2.lpc` 前后两份 `order`/`data` 表，后面那份才被读到（`data` 前一份是短的旧稿），删去前一份；`man*.lpc` 的 `kill_ob` 在 `void` 基类上写成 `int`，改 `void`。
- `adm/daemons/fairyland_quest/room_readygo_hj.lpc` 每个名字声明两次的写法合成一次；`u/lonely/obj/roommaker.lpc`、`roommk.lpc` 的重复 `special_props` 删前一个；`d/jerry/job/peng/peng.lpc` 的 `ask_fail` 原型改 `int`（定义在 `dojob.lpc`，返回 1/0）；`u/lonely/obj/user/master.lpc` 两个 `static` 函数改 `protected`。
- 宏重定义 25 处（`BOOK`、`FUBEN_D`、`HISTORY_D`、`ansi2.h` 的 `BEEP`/`HIREV`/`ESC`/`DELLINE` 等）：有意的本地定义前加 `#undef`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 12 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/class/generate/killed1234.lpc`（`exp *=`）、`/kungfu/class/generate/killed1234.lpc`（`pot *=`）、`/kungfu/class/generate/killed1234.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed1234.lpc`（`score *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 29 处 `int power_point()` 返回浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（KB 04 §6.10）。

- 2026-10-14：36 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`changeshape()`。新进程比对 HEAD 与工作树：36 个对象，新增载入 36，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14（补）：上面改成有返回值的函数里残留的空 `return;` 改为 `return 0;`（值不变，消除 `Non-void functions must return a value`）。

- 2026-10-14：27 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；2 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：28 个对象，新增载入 20，回退 0。

- 2026-10-14（更正）：上一条把 `do_lianmo()`、`do_zhujian()` 也改成了 `mixed`/`string`，其实那里返回值的类型是因为前面的错误（未定义的函数）才变成未知，不是真的返回字符串；恢复为 `int`。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。7 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 7 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## 寒星掌毒的伤害种类（2026-10-15）

`kungfu/condition/hanxing_poison.lpc` 的 `receive_wound("sheng", ...)`：本库没有 sheng 这一项，报错发生在 `apply_condition(..., duration - 1)` 之前，中毒的人永远不会好。按上下文（另一行是 jing）改为 qi。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。9 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`songyang-strike`、`sougu-yingzhua`、`test`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`daojian-guizhen/xue`、`daya-jian/badao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`shigu-bifa/dian`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）；`/quest/wudang/song` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`wangran-xinfa`、`妄然心法`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/yi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`shicheng-liulang`→`shicheng-liulong`（`shicheng-liulong`）；`tiandao-shendong`→`tiandao-shengong`（`tiandao-shengong`）；`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 地图数据库 mapdb 读到只有文件头的 map.o（2026-10-15，KB 06 §7.250）

本库的 `data/npc/map.o` 只有一行文件头：genmap 第一次载入时 `if (!restore()) save();`，地图还没建就存了档，值为 0 的变量不写进去。mapdb 的 `restore()` 读它成功，`map` 却成了 0，`query_room_info()`、`query_room_exits()`、`query_map()` 都对 0 取下标或把 0 交出去：临济庄「幽冥桩」每次都报错。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。地图本身仍需巫师用 genmap 生成。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## 存档读不出来：转码损坏（2026-10-15，KB 03 §4.4）

`/u/lonely/e2c_dict.o` 在转码时坏了：原档里孤立的 GBK 前导字节被 `iconv -c` 连同后面的引号一起丢掉，`restore_object()` 报 `Illegal mapping format`，读档的对象（玩家、留言板、信件、表情）从空白开始。按 raw/ 原档重新解码（孤立字节丢掉、引号保留），驱动核对全部能读回（`scripts/lpc_save_encoding.py --from-raw`、`scripts/lpc_save_restore_check.py`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。5 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 刀剑归真「天下有血」没有第二件兵器时报错（2026-10-15，KB 06 §7.246）

`daojian-guizhen/xue` 直接读第二件兵器的 `skill_type`，手上只有一件兵器时报错；同目录的 `ben`、`jiu`、`tian` 都先拒绝。补上同样的“你没有同时装备刀剑”拒绝。


## 松风剑法「缠」每次报错（2026-10-15，KB 06 §7.246）

`songfeng-jian/chan` 在给 `weapon` 赋值之前就判断 `weapon->query_temp("noliving")`（本意是 `target`），每次使用都报错。改为 `target`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

40 个文件、47 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/kungfu/class/taohua/obj/bupao`、`/kungfu/class/taohua/obj/yuxiao`、`/d/xingxiu/obj/tiegun`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 20 个（19 个原来载入不了），没有退步；其余 20 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`d/city2/look.lpc`、`quest/quest_jun/look.lpc`。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`MEDAL` → `/inherit/armor/medal`（17 个文件）、`RING` → `/inherit/weapon/ring`（5 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：22 个里 5 个通过，其余 17 个还有别的错误（`clone/medal/diamond_xunzhang.lpc`：Undefined variable 'TYPE_MEDAL'；`clone/medal/hero_xunzhang1.lpc`：Undefined variable 'TYPE_MEDAL'；`clone/medal/hero_xunzhang2.lpc`：Undefined variable 'TYPE_MEDAL'……）。


## 迷宫首领 NPC 重复继承 NPC（2026-10-18，KB 06 §7.240）

`d/maze/boss/npc/` 下这 8 个首领先 `inherit NPC;` 再 `inherit BOSS;`，而 `BOSS`（`/inherit/char/boss`）本身已经继承 `NPC`：全局变量 `busy`、`interrupt`、`perform_busy`、`override` 等一律 `Redeclaration of global variable`，后面还有 `nomask` 函数被重定义，NPC 载入不了。去掉多余的 `inherit NPC;`（文件里的 `::init()`、`::die()` 现在落到 `BOSS` 上，正是它们原来想调的）：`d/maze/boss/npc/0004/dragon.lpc`、`d/maze/boss/npc/0005/dragon.lpc`、`d/maze/boss/npc/0011/shujing.lpc`、`d/maze/boss/npc/0012/baihuaxianzi.lpc`、`d/maze/boss/npc/0013/leijiu.lpc`、`d/maze/boss/npc/0014/leishen.lpc`、`d/maze/boss/npc/0501/nielong.lpc`、`d/maze/boss/npc/0502/jinyinshe.lpc`。改后载入：8/8 通过。
