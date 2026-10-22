# 侠客行一百 UTF-8 (xkx100utf8) — porting notes

Source: `fluffos/xkx100` submodule at `51396a26` (leftover 688:
`.lpc` + §9 formatted on that repo; mudlib root is the repo root;
filename-extension slices widened for `.lpc`). In-game name `侠客行`
/ banner `侠客行一百`. Slug `xkx100utf8`, number **110-1**, port
40275.

## leftover 688: work/ is the fluffos/xkx100 submodule

`hosting` is `fluffos-upstream`. `work/` is now the `fluffos/xkx100`
gitlink (pin `51396a26afaa0123bbed5fe61a1ae5191f060b70`), not a
second formatted fork. `config.fluffos` mudlib directory still points
at `work/` (this repo's root *is* the mudlib). `patches/` stays empty
— the rename, §9 format, `.lpc` slices, always-UTF-8 login,
`log_error` filter, visitor/card guards, wizard vitals, `tell_room`
exclude, and commented I3 preload live on that fluffos-org repo.
`doc/board` and other convert-lib encoding sidecars were **not**
copied upstream (lossy GBK noise). Catalog-only overlay:
`data/login|user` for `fluffos` / `Mud@2026`. Native 苏州客店
`look`/`score`/`quit` on `fluffos` / `Mud@2026` (秦风, 目前权限：(admin)).
Zip pack: `.lpc` + overlay seed, no `.git/` store.

## earlier snapshot note (superseded)

Onboard convert was 2026-09-05 from `ee022c90`. Leftover 688 landed
the catalog LPC delta on `fluffos/xkx100` and pinned that SHA.

`MudRen/xkx100` is the same tree with a MudCore wrap. Do not onboard
it again.

## 0. Relation to collection `xkx100` (110)

Collection `xkx100` is the Coollizard `侠客行一百.rar` (14255 `.lpc`,
master `/adm/obj/master`). This GitHub tree is a UTF-8 FluffOS
modernization of the **same 侠客行一百 game** (banner credits
“CopyRight Coollizard & xkx100 2003-2004” and
`https://github.com/MudRen/xkx100`). Core files are not byte-identical
(`adm/single/master` vs `adm/obj/master`; 12192 `.c` vs 14255 `.lpc`;
logind/chinesed/securityd all differ). Numbered **110-1**, not a new
unique game.

## 1. Convert (2026-09-05)

`rsync --exclude .git` into `raw/` (do not copy `.git` into `work/` —
that registers as a submodule). `convert_lib.sh` UTF-8:
`already_utf8=12993 converted=0 lossy=994 skipped_binary=35`. Lossy hits
were leftover `.old`/`.bak`/`.tmp` sidecars, not live `.c`. 12192
`.lpc`. 606 `.c"` refs. 11 local angle-bracket includes. 17 files
`static`→`nosave`. Exit 0.

`is_chinese()` is already `pcre_match(..., "^\\p{Han}+$")`.
`check_legal_name` uses `strwidth` 4–10 (2–5 Han). 秦风 passed.

## 2. Always-UTF-8 login

Upstream `connect()` set GBK only on port 5555 (6666/websocket left
as driver default). This project uses a single telnet port: always
`set_encoding("utf-8")`.

## 3. Preload I3

`adm/etc/preload` listed `/adm/daemons/network/dns_master`. Commented
out (AGENTS.md §7.6). Do not put this lib on a high-frequency reboot
loop if that line is ever re-enabled — it is a real outbound I3
socket.

## 4. Bugs fixed this onboard

1. **`log_error()` warning filter (AGENTS.md §7.10).**
   `strsrch(..., "Warning")` → `"arning:"`.
2. **`howmany_visitor()` / `howmany_card()` unguarded `sscanf`
   (same shape as collection `xkx100` §7.9).**
   `read_file("/log/MUDVISITOR")` is present in this snapshot
   (`VISITORS 999`), so first login did not hang. Still added
   `if (!stringp(content)) return 0;` on both helpers. `/log/GIFTCARD`
   is missing; the card helper is not on the login path.

`command_hook` is already `protected nomask`. `wizlist` already
ships `fluffos (admin)` and `mudren (admin)`.

## 5. Registration / admin

Flow: unused English id → `y` → Chinese name (2–5 Han) → password
(≥5) → confirm → hometown region `1`–`5` (city random) → 膂力/悟性/
根骨 (80-point budget, 10–30) → accept `y` → character `0`–`5` →
email (`id@address`) → `m`/`f`.

Live: `fluffos` / `秦风` / `Mud@2026` / hometown 3 → 苏州客店 /
stats 20/20/20/20 / 普通. `目前权限：(admin)` (天帝). `look` /
`score` (food/water full) / `quit`.

`LOGIN_TIMEOUT` is 300 seconds.

## 6. Not done

No full §9 format of 12192 files. WASM status **playable** (no
MySQL). Native play verified. §10.7 shop/拜师/combat done 2026-09-05
(below).

## 深度功能测试（§10.7，2026-09-05）

管理员 `fluffos` / `Mud@2026`，秦风，苏州客店出生。登录横幅带活
时钟，脚本 idle 0.45s。`LOGIN_TIMEOUT` 300s。Driver PID this boot
960668，cwd `libs/xkx100utf8/work`，port 40275。Live `debug.log` is
`libs/xkx100utf8/log/debug.log`（Boot Time Sat Sep 5 12:05:06 2026）
— slug-level `log/` so the pre-chdir fopen succeeds; `work/log/
debug.log` was not opened. `error_handler` returns traces to that
driver log. Collection `xkx100` already had a 扬州醉仙楼 + 丐帮左全
pass; this snapshot replayed the same destinations organically from
苏州.

### 实测过程

1. **Login hp 0/0.** First look/score after onboard quit: 精气/气血
   `0/0`. Save had `qi`/`jing` 0 and no `eff_qi`/`eff_jing`.
   `chard.lpc` skips player vital init (comment: moved to
   `updated.c`); `updated.c` then `if (wizardp(ob)) return;`
   **before** the `eff_*` fill. Admin characters never get
   `eff_qi`/`eff_jing`; the next `heal_up` caps current qi to 0.
   `full` recovered 100/100. Collection `xkx100` still has the same
   early return (not patched this pass).
2. **苏州立春堂 shop.** Organic: 客店 west → 沧浪亭 → 东大街 →
   药铺. `list` 金创药/养精丹 五十两白银, 朱睛冰蟾 四两黄金（无
   pager）. `clone /clone/money/gold` then `buy yao` → 一包金创药 +
   五十两白银找零（10000−5000）。`eat yao` hits `cmds/std/eat.lpc`
   (`food_supply` gate: 「看清楚点，这东西能吃吗？」); medicine
   verb is `fu`. Not a programming bug.
3. **Combat.** 胡同 `/d/suzhou/hutong1` `fight liu`. Multi-round
   spar, qi 100→43, auto-yield 「这场比试算我输了」. No crash.
4. **苏州马厩 `rideyz`.** Age 14 rides free. Arrived 扬州马厩, but
   arrival `tell_room(env, msg)` (no exclude) threw
   `*Bad argument 4 to EFUN message() Expected: object, array, Got:
   int(0)` from `adm/simul_efun/message.lpc` `tell_room` passing a
   raw 0 exclude — AGENTS.md §7.12. Collection `xkx100` already had
   `exclude || ({})`; this UTF-8 snapshot did not. Ride still
   completed (error after `move`).
5. **扬州醉仙楼 shop.** west/west/north/north/east. `list` paginates
   (`== 未完继续 76% ==`); `q` then `buy jitui` 三十文铜板. Ledger
   五十两白银 → 四十九两白银 + 七十文铜钱 (5000−30 = 4970).
6. **拜师.** 中央广场 `enter dong` → 左全. `apprentice zuo` once:
   丐帮第二十代弟子, 师父左全. `xue zuo force 10` 「今天太累了」
   but `cha` shows 基本内功 0/0 (skill key created). Design /
   mud_age, not a crash.
7. **Quit / persist.** `save` then `quit`. Wall-clock gap, real
   `enter_world` (not 重新连线) landed in 树洞. Family / 师傅 /
   四十九两白银 + 七十文铜钱 persisted. 金创药 and 烤鸡腿 are not
   autoload (design). `user.o` has
   `family_name":"丐帮"` / `master_name":"左全"` / `generation":20`.

### Bugs fixed this pass

1. **`adm/simul_efun/message.lpc` `tell_room` §7.12.** 2-arg call
   passed int 0 as `message()` exclude. Now: no-object return;
   `efun::message` 4-arg only when `exclude` is truthy, else 3-arg
   (AGENTS.md §7.12 zhyx self-call shape). Live: `update` the
   simul_efun, `ridesz` 扬州→苏州 printed 「一路顺利到达苏州城」
   with no new error.
2. **`adm/daemons/updated.lpc` wizard vital skip.** Moved
   `if (wizardp(ob)) return;` to **after** the `eff_qi`/`eff_jing`/
   `neili` clamps so admin newbies get vitals; skill-vs-exp clamp
   still skipped for wizards.
3. **`adm/daemons/logind.lpc` `init_new_player`.** Also sets
   `max_jing`/`max_qi`/`eff_jing`/`eff_qi` to 100 so the first
   heartbeat cannot zero qi before `check_user` runs.

Admin save not committed. No new AGENTS.md class (both shapes
already cataloged).

## 7. Local run

```
cd libs/xkx100utf8
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40275**.

```
python3 scripts/mudclient.py 127.0.0.1 40275 --timeout 55 --idle 0.45 \
  --send "fluffos" --send "Mud@2026" \
  --send "look" --send "score" --send "quit"
```

## 深度功能测试（§10.7，2026-10-12）：“无副作用表达式”警告复查（上游 PR）

- fluffos-upstream 库，修复走上游 fluffos/xkx100 PR #7（已合并）：`dns_master.lpc` 空 if、`adm/daemons/event/qiantang.lpc` 钱塘潮 `"…\n"; NOR;` 颜色不复位、三个 `d/xingxiu` 房间空的 `if (current_water == 0) {}`。6 个对象改前改后均载入。pin 升到 182fe371。

## 深度功能测试（§10.7，2026-10-13）：编译警告清零（上游 fluffos/xkx100#8）

`work/` 是 `fluffos/xkx100` 子模块，此前的警告整理只扫 vendored 库，本库一直没扫到（可编译文件警告 1657 条）。在
`scripts/submodule_patch_scratch.py build xkx100utf8` 建的副本里先用 `lpc_twin_port.py adopt xkx100 xkx100utf8 --pre cb9eeb980cd~1`
（`TWIN_DST_TREE` 指向副本）照搬同一游戏 xkx100 已修好、代码相同的 349 个文件，再跑 `lpc_warnings.py --fix` 和
`scripts/toolkit_fix.sh`，剩下 19 条手修，警告 1657 -> 0。改动的 686 个对象新进程各载入一次：686 -> 686，无回退；打过补丁的树开机到
登录提示。修复提交到上游（PR #8，合并提交 `2ec5d095`），本库钉到该提交（`rebase_upstreams.py`）。

- 行为上的修正：条件里把按位 `&` 当逻辑与（三种解毒丹、蝎子毒囊、火把、五毒功门槛），`a == x & b == y` 实际是
  `a == (x & b) == y`，改 `&&`；`d/tiezhang/pingtai.lpc` 多余的 `"\n";` 语句。
- 手修：`d/yixing/doc/info_{biao,guest,store}.h` 加防重复包含（`bangzhu.lpc` 直接包含一次，又经 `bangzhu_duty.h` -> `guanjia.h`
  再包含一次）；`open/xiangyang/task/guo.lpc` 先后包含 `zzzjob.lpc`、`teamjob.lpc`，两者的 `names` 表一字不差，`teamjob.lpc` 的那份加
  `#ifndef XIANGYANG_JOB_NAMES`；有意重定义的 `STORY_DIR`/`BANGZHU`/`BIAOHUO` 前加 `#undef`；两条继承路径都到 `/feature/clean_up`
  的 6 个文件写明 `clean_up()` 用哪一份（驱动本来就用那份）；`d/city/pai9room.lpc` 去掉多余的 `inherit F_CLEAN_UP`；
  `d/city/daxiaoroom.lpc` 整段注释里残留的 `/*` 改 `//`。
- xkx100 的 teamjob 越界修复（`random(40)`）这里不需要：本库原本就是 `random(sizeof(...))`。

- 2026-10-14：FluffOS 970d9f09 的 `Float value truncated to int` 92 处在上游修掉（fluffos/xkx100 PR #9，已合并，pin 更新到 `c1b87db`）。36 个技能文件的 `power_point()` 改为 `float`，按内功等级分支的三个 `yunlong-*` 也一样；`adm/daemons/combatd.lpc` 的攻击行由 `damage *= (int)...->power_point(me)` 改为 `damage = to_int(damage * ...)`，伤害仍是整数。**玩家可见**：威力系数大于 1 的武功和轻功按原设计计算。改动的 77 个对象载入无回退。

## `log/` subdirectories nobody created: the logging `write_file()` / `log_file()` raises (2026-10-22, KB 06 §7.358)

The code of this lib writes logs into 5 subdirectories of `log/`: `log/board` (`inherit/misc/bboard.lpc`), `log/gift` (`clone/gift/gift/gift.lpc`), `log/mission` (`d/city/task2/renzhi.lpc`) .... Neither the archive, a `git clone` nor the site pack has them (no local boot wrote into them, so `gen_keep_dirs.py` never recorded them), and `write_file()` raises `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"` for a missing directory: the function that logs stops on that line and what came after it (the reward, the flag, the next step) never runs. This lib's `log_file()` is `write_file(LOG_DIR + file, text)` and raises the same error for a missing directory (measured). `log/board`, `log/gift`, `log/mission`, `log/nosave`, `log/test` are now in `scripts/wasm_keep_dirs.txt` (`scripts/lpc_keep_log_dirs.py`; the site and the pristine tree create the empty directories from it). Proof (`scripts/lpcc_eval.py`, an eval object under `/adm/daemons` or similar writes `/log/zzdirprobe/...`, fresh processes): the measured table in KB 06 §7.358.
