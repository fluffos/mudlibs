# 侠客行一百 UTF-8 (xkx100utf8) — porting notes

Source: `git clone https://github.com/fluffos/xkx100` (commit
`ee022c90aabbbed6413acc6e10254e5a00f511fd`, “Add WASM pack script +
GitHub Pages deploy workflow”, 2026-07-29; converted 2026-09-05).
In-game name `侠客行` / banner `侠客行一百`. Slug `xkx100utf8`,
number **110-1**, port 40275.

This collection’s copy is a snapshot, not a live mirror. Local
login-encoding and preload patches mean it has diverged from
upstream. Upstream is `github.com/fluffos/xkx100` (fluffos org) —
genuine driver-compat fixes found later belong in an upstream PR as
well as here (AGENTS.md §2.3).

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
