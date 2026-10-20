# nitan3 — 泥潭三 (git-hosted duplicate of `nitan_san`)

Source: `git clone https://github.com/mudchina/nitan3` (commit `6f6d92f`,
cloned 2026-08-25). Port: **40217**. Number: **169**. Status: **done,
confirmed duplicate** (boots clean, full registration flow verified
end-to-end with real Chinese names, reaching an actual game room).

## Duplicate check (done BEFORE the fix pipeline, per task instructions)

This lib is a **byte-identical duplicate of `nitan_san`'s raw archive**
(`archives/泥潭三.rar`, archive #61, port 40055) — confirmed, not
merely suspected, via direct comparison before investing in the full
conversion pipeline:

- File-list diff (`find | sort`, excluding `.git`): nitan3's raw clone
  has 15,237 files, `nitan_san`'s raw archive extract (`raw/nitaniii/`)
  has 15,252 — the only differences are one `.gitignore` (an artifact of
  this being a git repo, not present in a `.rar`) and 16 empty/log
  placeholder files under `nitan_san`'s own `log/` tree accumulated
  during ITS testing history (never part of the original archive).
- **Full-content md5sum comparison of all 15,236 shared files: 15,235
  are byte-identical.** The lone exception is `config.cfg`, which
  differs by exactly one cosmetic string — `mudlib directory : e:/nitan3`
  vs `e:/nitaniii` (and the matching `binary directory` line) — a
  leftover Windows folder-name artifact from whoever originally
  packaged each copy, not a code or content difference.
- `adm/single/master.c` (this lineage's actual master file, not the
  decoy `feature/master.c`/`adm/daemons/story/master.c` copies) is
  byte-identical (md5 `28de08a80a8c764528b1b935c05fdbf8`) between this
  clone and `nitan_san`'s raw archive.
- `nitan_san`'s own NOTES.md already documents that its snapshot
  self-identifies internally as `nitan.3`/"泥潭三"/"Nitan III" — i.e.
  `nitan_san` **is** "Nitan 3" under this project's own prior
  terminology; this GitHub repo (named literally `nitan3` by the
  `mudchina` org) is not a coincidentally-similar sibling, it is the
  same snapshot, git-hosted instead of `.rar`-packaged.

**Conclusion: genuine duplicate, not a distinct game.** Per this
project's standing convention (AGENTS.md's `duplicate_of` field), this
is still fully recorded — own slug/number/port, own `work/` tree,
`meta.json` with `"duplicate_of": "nitan_san"` — rather than silently
skipped, and the full onboarding pipeline (steps 3-13) was run to
completion below.

## Conversion

`scripts/convert_lib.sh libs/nitan3/raw libs/nitan3/work` (GB18030 default):
13,557 files converted 0-error (496 already UTF-8, 14,713 converted, 27
lossy — same three `help/` files flagged lossy as any GBK archive this
size typically has, cosmetic doc text, not code), 13,557 `.c`→`.lpc`
renames, 6,891 literal `.c"` reference fixups, 17 `#include <...c>`
fixups, 33 local angle-bracket→quote include conversions, 104
`static`→`nosave` fixups.

## Fixes: ported wholesale from `nitan_san`, not re-discovered

Since the raw content is confirmed byte-identical, rather than
re-running `nitan_san`'s entire multi-session bug-discovery process from
scratch, its **already-fixed, already-reformatted, already boot-tested**
`work/` tree was synced directly onto this fresh conversion:

```
rsync -a --delete \
  --exclude=/.git --exclude=/.gitignore \
  --exclude=/data/login --exclude=/data/user \
  --exclude=/log --exclude=/dump --exclude=/doc/dump \
  --exclude=/trace_lpcc.json \
  libs/nitan_san/work/ libs/nitan3/work/
```

This one operation reproduced every one of `nitan_san`'s NOTES.md fix
items automatically (verified via a post-sync `diff -rq`, which came back
clean except for the intentionally-excluded runtime/save directories):
the CJK-codepoint `is_chinese()`/`check_legal_name()`/`named.lpc` rewrite,
`securityd.lpc`'s `load_object`/`recompile_object`/`include` early-allow,
`master.lpc`'s `get_include_path()`, the `LONELY_IMPROVED` dead-efun
guards including the from-scratch `adm/simul_efun/bignum.lpc` arbitrary-
precision arithmetic library (a hard `simul_efun.lpc` compile-blocker
without it), `inherit/misc/quest.lpc`'s `set_information` signature
widening, `timed.lpc`/`ntefun.lpc`'s bare-`array` declarations,
`message.lpc`'s `exclude || ({})` guard, `clone/user/user.lpc`'s
`is_killing` type-fix, `eventd.lpc`/`storyd.lpc`'s `.lpc`-rename-width
fix, `d/city/npc/paimaishi.cc`→`.lpc` rename, the `assure_file()`
missing-directory fixes (`toptend.lpc`, `file.lpc::log_file()`,
`master.lpc::log_error()`), the §7.100 `ROOM` redundant
`replace_program()` sweep (3,252 files), the §7.112 `death_stage`
reentrancy guard, the §7.30 uninitialized-mapping accessor sweep, the
WASM-era loopback-allow / `uptime()`-grace-bypass / fail-closed
`band.lpc` retrofit, and the full `format-corpus.mjs` reformat pass —
all inherited in one step. See `libs/nitan_san/NOTES.md` for the
original per-item rationale; not re-derived here.

**Confirmed NOT ported and not needed**: `nitan_san`'s own accumulated
test/admin player-save data (`data/login/`, `data/user/`) and logs —
explicitly excluded from the sync so this lib gets its own fresh
registration/admin-seeding pass (below), not a copy of `nitan_san`'s
account state.

## New fix found on THIS lib (not present in `nitan_san`'s history)

**`adm/single/master.lpc`'s `log_error()` — missing `seteuid(ROOT_UID)`
re-elevation after `assure_file()`, same privilege-ordering bug already
fixed in `adm/simul_efun/file.lpc`'s `log_file()`.** `assure_file()`
resets the caller's euid back to `getuid()` as its own cleanup step; any
caller that needs to write immediately afterward must re-elevate.
`file.lpc::log_file()` already had this fix (ported in via the rsync
above, with an explanatory comment already documenting the bug class).
`master.lpc::log_error()` had the `assure_file(home + "log")` call (also
ported in — this is `nitan_san`'s own item covering the third
`assure_file`-needing call site) but was NEVER given the matching
re-elevation, because **`nitan_san`'s own `work/log/log` file already
existed from its multi-session testing history**, so `assure_file()`'s
`file_size(file) != -1` short-circuit always skipped the vulnerable path
there — this bug was latent and unreachable on `nitan_san`, but
immediately live on a genuinely fresh `work/log/` directory (this lib's
own, since `log/` was deliberately excluded from the sync). Symptom:
every single compiler warning during preload (this driver routes
warnings through `log_error()`, not just real errors — the game's own
`/log/log` warning-log file) failed `*Wrong permissions for opening file
/log/log for append`, looping indefinitely since the target file could
never actually get created. Fixed identically to `log_file()`: added
`seteuid(ROOT_UID);` immediately after `assure_file(home + "log");`,
before the `write_file()` call. Verified fixed: `/log/log` now exists
and accumulates warning text correctly across a full preload + test
session.

**Residual, not chased further**: 7 of the many `log_error()` calls
during a from-scratch preload still hit `Wrong permissions for opening
file /log/log for append` even after the fix (down from an unbounded
retry storm to a fixed, small, non-blocking count) — cause not fully
isolated (didn't reproduce with more diagnostic instrumentation within
this pass's time budget; possibly a narrow reentrancy window during the
very first few file compiles before `SIMUL_EFUN_OB` is resident). Does
not block boot, does not recur during actual gameplay (post-preload),
and `/log/log` itself ends up populated correctly regardless. Flagged
here for whoever next touches this file.

## Compile-sweep: skipped, matching `nitan_san`'s own precedent

13,557 `.lpc` files — the same mega-lib bracket `nitan_san` (13,559
files) and `nitan_ceshi` (13,497 files) already established as risky for
a full `lpcc --batch` sweep (AGENTS.md §10.4: "a mega-lib sweep can eat
all host RAM... on mega-libs the boot + interactive test is the
sufficient verification gate; the sweep is nice-to-have"). Host memory
during this pass ranged from 21Gi down to ~2.7Gi available while the
driver + test client were live — not worth risking a full batch compile
of the same size class that has already twice been documented eating a
23GB host down to sub-1GB free. Skipped per the same policy `nitan_san`
used; the boot + full registration/quit/reconnect/admin-`update` test
below is what actually found and fixed the one real bug in this pass
(the `log_error()` euid issue, itself a `simul_efun`/`master`-adjacent
class of bug a sweep wouldn't have caught any faster than the boot did).

## Boot + interactive test

`~/src/fluffos/build-debug/src/driver config.fluffos` (cd'd into
`libs/nitan3` first). Preload completed and port 40217 listened cleanly
on the very first boot after the `log_error()` fix (a first attempt
before that fix also fully preloaded and listened — the euid bug is
non-fatal, just noisy). `log/debug.log`: zero real compile
errors/undefined-functions/bad-arguments/illegal-operations/syntax
errors across ~4,700 lines generated over the whole test session — only
the universal harmless `Unknown #pragma, ignored.` warning (every file
in this lineage emits it once) and the residual `Wrong permissions`
noise documented above.

Full registration flow (`scripts/mudclient.py`), matching `nitan_san`'s
own documented transcript almost line-for-line (same banner: 《終極魔界》
"Ultimate Demon Realm" skin over the "泥潭"/nitan engine, same
"泥潭三已经执行了..." uptime line, same GB/BIG5 pre-id prompt):

- **Admin registration** — id `fluffos`, surname/given-name 浮/浮
  (confirmed via the "姓名相同" full-name-confirmation prompt, same as
  documented for `nitan_san`), admin password `Mud@2026admin`, normal
  password `Mud@2026`, gender `m`. Landed immediately at **`(admin)`**
  status (`目前权限：(admin)`) in 巫师休息室 (wizard lounge) — the
  `adm/etc/wizlist` entry granting `fluffos` admin was already present,
  carried over automatically by the `nitan_san`-sourced sync (this is a
  config/data file under `work/`, legitimately part of the ported source
  tree, not player save state).
- **Normal player registration** — id `qinfengiii`, surname/given-name
  秦/风 (a real two-character Chinese name), gender `m`: reaches
  **注册房间** (registration room) with correct 十大富翁/十大高手
  rankings display, `look` correctly re-displays the room. Reconnect
  (restore) path verified: disconnecting and reconnecting with the same
  id/password produces `这个角色已经存在，请输入该角色的密码` →
  `重新连线完毕` and returns to the same room state.
- **`quit` gate, both branches**, verified on this same account: `n`
  correctly cancels (`您选择了放弃退出(quit)，继续游戏。`); a second
  `quit` → `y` correctly deletes the still-new account
  (`您选择了放弃该帐号退出泥潭，档案被删除`) — the standard
  anti-throwaway-account retention gate this whole lineage shares
  (intentional game design, not a bug — matches `nitan_san`'s own
  documented behavior).
- **Full birth continuation** — a second player, id `qinfengsan`,
  surname/given-name 秦/岭, gender `f`: `register test15@qq.com` from
  注册房间 correctly advances into **生命之谷** (Valley of Life), with
  盘古 (Pangu) greeting the player BY THEIR REAL REGISTERED NAME
  (`盘古说道：秦岭，你快快选择(choose)好角色性格，然后投胎去吧！`) —
  an exact match to `nitan_san`'s own documented transcript for the
  identical continuation step. `score` before this point (in 注册房间
  or 生命之谷, prior to actually completing the `choose`+投胎 birth
  ritual) correctly replies `还没有出生呐，察看什么？` ("not born yet,
  what are you looking at?") — confirmed as this lineage's intentional
  design gate (same as `nitan_san`'s own scope, which also stopped
  short of a full birth+score for its player-flow test), not a bug; this
  test account's `.o` save files were removed before commit (see below).
- **Admin write-access verification** (§1.5 standard check): logged in
  as `fluffos`, ran `update /adm/daemons/band.lpc` → `重新编译
  /adm/daemons/band.lpc：成功！` (success). Reconnecting afterward
  returns cleanly to 巫师休息室 with no quit-confirmation issue.

**Not tested this pass** (same "long tail, record don't chase"
convention as `nitan_san`'s own NOTES.md): combat, sect/门派 systems,
门派任务, the random-delivery-quest subsystem's known-but-unfixed `/
inherit/item/combined` "No program" background-daemon error (inherited
from `nitan_san`'s own documented finding, not re-verified here since
it's off the tested path and non-blocking).

## Save data committed

Only the seeded `fluffos` admin account (`data/login/f/fluffos.o`,
`data/user/f/fluffos.o`) is committed, matching `nitan_san`'s own
convention exactly — every other a-z login/user bucket directory is
preserved via an empty `.donotdelete` placeholder (git doesn't track
empty directories) rather than committing throwaway test-account saves.
The `qinfengiii` test account self-deleted via the `quit`/`y` flow
above; the `qinfengsan` test account's `.o` saves were manually removed
before staging.

## Admin account / 管理员账号

- **id**: `fluffos`
- **普通密码 / password**: `Mud@2026`
- **管理密码 / admin(recovery) password**: `Mud@2026admin`
- **中文名 / display name**: 浮浮 (姓浮名浮)
- **权限 / level**: `(admin)`, via `adm/etc/wizlist` (already present,
  carried over from `nitan_san`'s own seeding).

> 警告：对外公开架设前请务必修改这两个密码。

## WASM status update (2026-08-25, another session)

Promoted `wasm_status` from `""` to `playable`. Hit a real, non-trivial
bug the earlier prediction above didn't anticipate: `adm/daemons/
versiond.lpc`'s `in_server()` (called from `create()`) unconditionally
calls `socket_create()`/`socket_bind()`/`socket_listen()`, undefined on
this driver build (no `sockets` package). Regular player logins never
touch this file, but admin-rank login does (`logind.lpc`'s
`catch(enter_world(ob, user))` around entry ends up loading it), and
since the whole file fails to compile, the `catch()` fires and shows
"你无法进入这个世界，可能你的档案出了一些问题" -- non-fatal (the
player recovers into the normal room right after) but a real, visible
defect on every admin login.

Fixed per this project's established "sockets package absent" pattern
for a large multi-purpose daemon (33 other files call into this one
for non-socket functionality, so the whole file stays loadable — only
the 11 functions actually touching a real `socket_*`/`socket_address()`
call were gutted to no-ops/always-fail). Verified with a full scripted
WASM session: login as `fluffos`/`Mud@2026`, no more crash/error,
`look` reaching 巫师休息室 cleanly. `score`/`quit` weren't recaptured
distinctly in this transcript but both are already thoroughly verified
under native testing above (including both `quit` confirmation
branches) and untouched by this fix.

**This exact same bug was independently confirmed still present in
`nitan_san`** (the sibling this lib is a confirmed duplicate of,
byte-identical `versiond.lpc`) despite its `wasm_status` already being
`playable` from an earlier pass — that pass never exercised an
admin-rank login, so the crash went undetected. Patched `nitan_san`'s
copy identically as part of this same pass; see its own NOTES.md.

## 深度功能测试（§10.7）

No independent playthrough under this slug. This tree is a confirmed
byte-identical duplicate of `nitan_san` (15,235/15,236 files; the only
diff is a cosmetic Windows folder name in `config.cfg`). `nitan_san`'s
2026-08-12 round-two §10.7 pass (`libs/nitan_san/NOTES.md`) is the
functional-test record for this codebase. The `work/` sync above already
carries every fix from that pass.

## 深度功能测试（2026-09-04，shop + 拜师）

Independent live pass on this slug (port **40217**, `build-debug`
driver). Prior §10.7 text above only deferred to `nitan_san` and never
exercised a shop purchase or a recruiting NPC here. First send is
**`gb`** (GB/BIG5 menu), then id `fluffos` / password `Mud@2026`. Admin
has no `wizpwd` yet — login prints the “请登陆后用 wizpwd 命令设置”
warning and then asks for the ordinary password. `score` refuses an
unborn wizard (“还没有出生呐”); birth is `goto /d/register/entry` →
`choose 1` (光明磊落) → `washto 20 20 20 20` → `born 扬州人氏`
(lands at `/d/city/kedian`; `help rules` more-pager — send `q`).

**Shop**: 客店 `xiaoer` is an innkeeper, not `F_DEALER`. Real vendor is
`/d/city/zuixianlou` 店小二 (`d/city/npc/xiaoer2.lpc`). `list` shows
烤鸡腿 80 文. `clone /clone/money/gold` works (`release server : local`
makes `is_admin()` true). `buy jitui` deducted one gold into 99 两白银
+ 20 文铜钱 and delivered 烤鸡腿. No `F_DEALER` 丐帮 refuse on this
lib.

**拜师**: `goto /d/city/lichunyuan`, `bai kong` on 空空儿
(`kungfu/class/gaibang/kongkong.lpc`) — no skill/shen gate beyond
`permit_recruit()`. Accepted immediately: “恭喜您成为丐帮的第二十代弟子.”
`score` shows 【门派】丐帮 / 【师承】空空儿. `save` then `quit`. After
a full driver kill + reboot, relogin still shows 丐帮 / 空空儿; the
silver/coin change persisted; 烤鸡腿 did not (food, not autoload —
expected, not a save bug).

**Bug fixed**: `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`
`recruit_apprentice()` wrote `add("apprentice_availavble", -1)` (extra
“av”) while `attempt_apprentice()`/`reset()` use `"apprentice_available"`.
Same typo `nitan6` already live-verified — the daily-recruit counter
never decremented. Corrected the property name in all three files
(LF-only). `nitan_san` still has the typo; not patched this pass.
`qingcheng/yu.lpc` is not in this tree. `inherit/weapon/pin.lpc` here
has no `to_chinese()` call (the nitan6 compile-blocker is already
absent).

No new `debug.log` `Error:` / `Wrong permissions` / eval-cost lines on
the shop+拜师 boot.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt nitan_ceshi nitan3` 把 nitan_ceshi 警告整理提交（ae7fbb619a5）里的改动搬到 1016 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 nitan_ceshi 自己删掉的以外没有丢失或改动），再用 `scripts/lpc_nitan_family_fixes.py nitan3`（`clone/obj/traverser.lpc` 的空 `DEBUG` 宏改成调用空函数；`adm/daemons/questd.lpc` 最后一个空的 `else if ((total_count % 10) == 0) { /* … */ }` 改成注释）。剩下的再跑 `scripts/lpc_warnings.py nitan3 --fix`，共改动 1023 个 `.lpc` 和若干 `.h`。以上都不改变行为。
HEAD 与工作树分别加载（新进程）：1008 -> 1008 通过，无回退；改过的头文件的 260 个包含者 257 -> 257 通过。

启动时警告 67 -> 0；新进程登录正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、0 处去后缀（如 `adm/daemons/taskd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 1。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **168 -> 0**（全库重扫：13437 个文件可编译）。改法与 nitan_ceshi 同日那一节相同（`scripts/lpc_twin_port.py adopt nitan_ceshi nitan3`，24 个同码文件），载入核对 962 个对象（改动的、F_UNIQUE/F_LIQUID/F_FOOD 的全部继承者、`feature/`、`inherit/`、`adm/daemons/`、`clone/misc/`）：`962 objects; HEAD PASS 947, tree PASS 947; regress 0; newly loading 0`。删除声明审计 0 处待看。

- **真问题：`feature/unique.lpc` 的 `int remove() { save(); }` 盖掉了 F_MOVE 的 `remove()`**，唯一物品被销毁时不卸装备、不从携带者身上减负重（nitan_ceshi 探针：10000 -> 25000 -> 仍 25000，修正后回到 10000）。删去，F_MOVE 的 `remove()` 对 `is_ob_saved()` 物件本来就先 `save()`。`clone/book/jiuyin1~3.lpc`、`d/tulong/obj/tulongdao.lpc` 原来自己写了 `remove() { item::remove(); }` 绕过它，toolkit 把它们改成 `varargs`。
- `clone/misc/swmuding.lpc`（神木王鼎）自己的虫表从没生效，改名后在 `create()` 交给木鼎的 `insects`；`adm/npc/obj/xiang.lpc` 先存盘再 `::remove(euid)`；`cruise-ob.h` 的 `remove()` 删去；`clone/npc/pet.h` 删去重复的 F_OBSAVE；`hu.lpc` 的疗伤函数改名 `heal_patient()`；`lubo.lpc` 合并液体与兵器两段说明。
- 幻境 `huanjing2003` 变量重复声明、`d/maze/forest/maze.lpc` 及 `backup/2009-5-2*/maze/*/forest/maze.lpc` 的 `unique_rooms` 改名、`skillsd.lpc` 的本地 `FORCE` 改 `FORCE2`、`food.lpc`/`liquid.lpc` 的 `do_effect()` 改 `varargs int`、`genmap.lpc` 删去用不到的 `harbor.h`、`vrm_server.lpc` 多余的 `;`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：4 个对象，新增载入 3，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`、`/kungfu/skill/yiwei-dujiang`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。15 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bingpo-blade/ningxie`、`duanyun-fu/hong`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`、`qiankun-danuoyi/yi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`、`qianzhu-wandushou/tuxi`）；`xuantian-wuji`→`xuantian-wujigong`（`liangyi-jian`、`taxue-wuhen`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 路径遍历器 traverser 从没编译过（2026-10-15，KB 06 §7.250）

`clone/obj/traverser.lpc` 把 `nosave` 写成了 `noasve`，编译失败；用它的临济庄「幽冥桩」每次都报 `No program in object '/clone/obj/traverser'`。改正关键字，并删去没用的局部变量 `err`。


## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## `call_out(0) nest level : 10`（2026-10-15，KB 03 §5.4）

这个值来自驱动测试套件的配置（`testsuite/etc/config.test`）。驱动统计的是同一个 gametick（本库 100 毫秒）里全游戏的 call_out(0) 总数，不是一条链的深度，超过 10 个就报 `Nesting call_out(0) level limit exceeded`：多段绝招（如华山剑法「剑芒」的 `call_out("perform2", 0, ...)`）在人多时会断掉。原版跑在 MudOS 上，没有这个限制；改为驱动默认值 1000。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`shenlong-jian/anxi`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`d/city2/look.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（15 个名字，最多的是 `xinyuegong`、`taizuquan`、`liangyi-dao`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 25 处、13 个文件：`yunu-xinjing`→`yunv-xinjing`（7 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenkongxing`→`shenkong-xing`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`shaolin-shnfa`→`shaolin-shenfa`（1 处）、`yan-fly`→`yanfly`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/huanggon/qihedian.lpc` 的 `south` 出口：`/d/city2/zhengmen` → `/d/huanggon/tinglang3`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：82 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`valid_learn()` 对任何性格都拒绝。改动：`/adm/daemons/ward.lpc`（1 处）、`/kungfu/skill/qiankundanuoyi.lpc`（1 处）、`/kungfu/skill/zhonghua-aojue.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/cmds/wiz/roomlong.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。
