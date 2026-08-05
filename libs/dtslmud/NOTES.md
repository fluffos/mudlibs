# LLMUD(大唐双龙)v_0.11版.rar → `dtslmud`

- Archive: `archives/LLMUD(大唐双龙)v_0.11版.rar` (13.9MB — "大唐双龙传",
  same lineage as archive #8 (dtsl). Archive bundles a Qt-based Windows
  GUI client (`llmud.exe` + Qt DLLs) alongside the actual mudlib
  (`DTSL_0.11/`) — client ignored, only the mudlib processed.
- Mudlib root: `DTSL_0.11/`, config at `DTSL_0.11/config.xkx`.
- Port: **40015**.

## Status: DONE — boots clean, playable over telnet

Booted with **zero fixes needed** (same lineage as dtsl, and the boot
path itself was already fine there too — differences between these two
snapshots showed up only in the lpcc sweep, not the boot path).

## What was fixed (from the lpcc sweep, proactively applied since the

same two bugs were already known from `dtsl`'s NOTES.md)

1. `F_UNIQUE` macro missing from `include/globals.h` despite
   `feature/unique.lpc` existing — same fix as dtsl, added
   `#define F_UNIQUE "/feature/unique.lpc"`. Fixed ~101 files at once.
2. The same 6 `clone/weapon/*.lpc` files (`jin-sjian`, `shizi`,
   `feihuangshi`, `jinhua`, `sjian`, `feidao`) redundantly
   `inherit COMBINED_ITEM;` both directly and via `inherit THROWING;` —
   removed the redundant direct inherit, same as dtsl.
3. `sm_ding.lpc` (7th file in the same cluster) has the same unrelated,
   unfixed problem as dtsl: `#include "/inherit/item/embed.h"` doesn't
   exist anywhere in this archive either — genuine missing content,
   left as-is.

Routine conversion: encoding, `.c`→`.lpc` (6514 files, 1001 refs
auto-fixed), 18 local angle-bracket includes converted to quotes
automatically, `static`→`nosave` (85 files).

## Known remaining issues (documented, not fixed)

- 1457 lpcc-sweep failures remain (of 6514, down from 1530 before the two
  fixes above) — not otherwise triaged given time constraints; boot/login
  path unaffected.

## How to run

```
cd libs/dtslmud
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40015 --timeout 10 --send "" --send "look" --send "quit"
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

## QA re-verification pass (2026-07-23) — found and fixed a real, high-impact bug

The earlier passes above never actually completed a full registration through
to a live post-login `look`/`score`, so this genuine gap went undetected until
this pass followed the project's standing policy of testing a real command
after registration completes.

**Bug found: every candidate starting room failed to load, silently stranding
every new character in `VOID` instead of a real room** (AGENTS.md §15s
pattern). `adm/simul_efun/message.lpc`'s `tell_room(ob, str, exclude)` (2-arg
call form, ~99% of call sites) left `exclude` unset (`0`, an int, not an
array) and passed it straight through to the real `message()` efun's 4th
argument, which this driver rejects for a non-object/non-array value. Since
`tell_room()` fires from `feature/move.lpc`'s `move()` whenever any NPC's
`create()` carries an item into itself (i.e. almost every populated room),
this made **every room containing an NPC with inventory throw an uncaught
error out of its own `create()`**, which the driver treats as a failed
compile (`Fail to load object ...`). Confirmed directly via
`lpcc config.fluffos /d/yangzhou/zuihualou` (the configured `START_ROOM`)
failing with exactly this error before the fix, and compiling clean after.

Effect on a real registration: `logind.lpc`'s `enter_world()` tries
`/d/newbie/door` (the real new-player start room) first, and since it also
has an NPC with inventory, IT failed to load too; the `catch()`-guarded
fallback to `START_ROOM` then also failed to load for the identical reason,
and neither failure's return value is checked, so the newly-created character
was left with **no environment at all**. The very first `look` command's own
`!env` safety-net (`cmds/std/look.lpc`) then silently dumped the player into
`/clone/misc/void` ("最後乐园") instead — indistinguishable from a normal room
without inspecting `debug.log`, since the void room has its own flavor
description and exit.

**Fix**: `adm/simul_efun/message.lpc`, `tell_room()` — `exclude || ({})`
before the `message()` call; `shout()` — `this_player() || ({})` likewise
(same latent bug, same file, not yet observed live but same shape per
AGENTS.md §15s's precedent on other libs).

**Second fix, same pass**: `adm/obj/master.lpc`'s `log_error()` broadcast
EVERY message reaching it — including ordinary compile *warnings*, not just
real errors — to the connected non-wizard player as the alarming generic
`default error message` ("你发现事情不大对了，但是又说不上来。"). Since the
`tell_room`/`shout` bug above was firing constantly (any NPC anywhere with
inventory), a real registration session before the fix showed dozens of these
lines during ordinary preload/gameplay. Gated the broadcast on the message NOT
containing `"warning:"` (AGENTS.md §15w's standard fix), still logging
everything to file regardless. Verified: a post-fix session showed zero such
lines.

**Third, minor fix**: `d/gaoli/npc/xiake.lpc` had a double-slash path typo
(`carry_object("//d/gaoli/obj/armor")`) causing one `*Read access denied.`
runtime error whenever this background NPC's job-daemon-driven room load
fires while a player is connected — pre-existing content typo, unrelated to
the two fixes above, fixed to the correct single-slash path.

**Re-verified after all three fixes**: full registration (`id → y → 中文姓名
→ password ×2 → email → gender → 4-attribute allocation → y`) followed by
`look`/`score`/`quit`, across 2 fresh characters (male "秦岭七"/female
"秦岭八" — the female run also confirmed gender-specific starting clothes
"粉红绸衫"/"绣花小鞋"). Both landed correctly in the real starting room
(`大唐学院`/Tang Academy, `/d/newbie/door`), not VOID; `look` re-rendered the
room, `score` showed the full correct character sheet; zero
`"你发现事情不大对了"` lines and zero uncaught runtime errors in `debug.log`
in the final run.

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter**: ran `format-corpus.mjs` over all 6,514 `.lpc`
  files — 6,362 reformatted in place, 29 already-idempotent, 123
  refused (nonzero `errors` expected/fine per the tool's own contract).
  Specifically double-checked the §15s `tell_room()`/`shout()` fix in
  `adm/simul_efun/message.lpc` survived the reformat byte-for-byte
  (`exclude || ({})` still present) — it did.
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, freshly rebuilt from upstream master): booted clean,
  zero fatal errors, zero `"你发现事情不大对了"` spam. Full registration
  re-verified with a fresh real name (秦岭十一) via the
  `id → y → 中文名 → password×2 → email → gender → "20 20 20 20" → yes`
  flow; landed correctly in the real 大唐学院 starting room (not VOID),
  `look`/`score`/`quit` all correct, gender-specific starting clothes
  shown. Confirms the §15s `tell_room` fix and the log_error warning
  gate both still hold after the reformat + rebuilt driver — no
  regressions, nothing to fix.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process. Full registration/login
  flow completed successfully under WASM too (fresh name 秦岭十二, same
  flow as native), reaching 大唐学院 and cleanly `look`/`quit`-ing out —
  this lib's own site-check only *displays* the connecting IP (via
  `query_ip_number()`) rather than gating login on its format, so the
  documented WASM IP-formatting limitation surfaces here only as a
  cosmetic blank in the "您正在从...这个IP连线进入" banner line, not as
  a login blocker; the lib is otherwise fully playable under WASM.

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard pass per AGENTS.md §1.3(b)/(e), §1.5.

**Gates patched:**
- `adm/daemons/logind.lpc` `logon()` (~line 62): per-IP anti-flood cap
  (`logon_cnt > 8` same-IP login objects → destruct) skipped for strict
  loopback only.
- `adm/daemons/band.lpc` `is_banned()` (~line 40): strict-loopback
  short-circuit `return 0` (called from `logind.lpc` `encoding()` with
  `query_ip_name()`).
- Uptime startup gate: none (no `uptime() < N` connection gate).
- The antirobot NPC quiz files (`clone/npc/antirobot*.lpc`) are in-game
  content, not connection gates — untouched.
- **Fail-closed correction (retrofit):** both gates above initially
  treated a malformed/non-string IP as loopback (per the original
  pre-driver-fix instructions). Since `query_ip_number()` is now fixed
  upstream, tightened to strict `127.0.0.1`/`localhost`/`::1`/`127.*`
  matching only — a malformed IP now falls through to the original gate
  logic instead of being waved through.

**Admin account:** id `fluffos`, pw `Mud@2026`, name 浮浮, `(admin)` via
`adm/etc/wizlist`. Registered via the real flow (id → y → 浮浮 →
password ×2 → email → gender → "20 20 20 20" → yes). Verified: relogin
shows `目前权限：(admin)`, `update /adm/daemons/band` → 成功, wizard
fast-quit path ("作为巫师，你可以迅速离线"). Save files (untracked,
NOT gitignored — orchestrator must add):
`work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

**Retest:** fresh normal registration (ceshisan / 秦岭辛) end-to-end OK
(look/score/quit correct; test saves removed); no new errors in
debug.log.

## 深度功能测试（§10.7，本轮）

之前几轮只验证到"注册流程能走通+管理员权限确认"这一层，没有真正深入
玩过。这次用真实驱动起服，走了完整流程：注册（英文 id 3-8 字母、中文
名字、密码 5-8 字元、email、性别、"20 20 20 20" 分配属性）→ 进入"大唐
学院"新手村 → down 跳过新手教学 → 走到"石龙武馆"→ 逛兵器铺（list 正
确列出商品和价格，buy dagger from tie jiang 因为没钱被正确拒绝"你身
上带的钱不够啊!"）→ 走到正厅试图攻击"武馆教头"（正确被"这里不准战
斗。"挡下）→ 试图直接离开武馆去外面世界（正确被"你经验这么低，出武
馆太危险了！"等级门槛挡下）。这些拒绝都是合理的游戏设计，不是 bug。
全程 `debug.log` 保持空白。

这份档案不是 NT/nitan 血统（虽然同样有 feature/dbase.lpc，但没有本地
定义 set()/query()——这是另一套架构，XKX 系），所以专门检查了一下，
确认**不**受 §7.78（mixin 文件裸 set/query 解析不到 F_DBASE）影响。

### 发现并修复的 bug

**§7.68 死亡软锁的一个变体，`d/death/gate.lpc`。** 和 xfbhh/hhsj/nt1
等 nitan 系那种"多阶段 death_stage() 自我重新 call_out"的写法不同，这
份档案的死亡流程更简单：`init()` 只排了一次 `call_out("run", 5,
ob)`，`run()` 本身完全没有自我重试的机制。`if (!ob || !present(ob))
return;` 这行代码原本就没有"重试"这个选项——如果角色在鬼门关等待的这
5 秒内因为任何原因暂时不在场（卡顿、正在被别的 move() 挪动），整个复
活/转生序列会直接永久放弃，没有任何重试或提示。已经拆成 `!ob` 才真正
放弃、`!present(ob)` 则用 `call_out("run", 5, ob)` 重新排队重试（沿用
这个档案自己原有的 5 秒间隔）。另外确认了同目录下 `npc/yanluo.lpc` 的
`death_stage()` 虽然名字很像，但它自己的守卫只有 `if (!objectp(ob))`，
根本没有 bundled 的 `!present()` 检查，是一个假阳性，没有这个 bug。

### 未继续测试的部分

时间关系，没有走出武馆去实际打怪（等级门槛挡住了，需要先在武馆内练
功/拜师升到足够等级）、没有实际触发一次死亡去验证这次修好的鬼门关流
程本身、也没有测试邮件/帮派/任务系统。下一轮如果继续深挖，建议先在
武馆里找教头或师父问问"拜师"相关指令提升等级，再出武馆找真正的怪物
测试战斗和死亡循环。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 dtsl 是同一血统。
