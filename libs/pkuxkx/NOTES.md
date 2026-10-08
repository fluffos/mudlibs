# 北大侠客行 (pkuxkx) — porting notes

Source: `git clone https://github.com/ly19811105/pkuxkx-utf8` (commit
`0eaf237c9970795a51aa4cc04b5b762003300cbd`, “清理备份文件”,
2021-04-09; converted 2026-09-05). Config name `北大侠客行`. Slug
`pkuxkx`, number 966, port 40274.

This collection’s copy is a snapshot, not a live mirror. Local
driver-compat and login-encoding fixes mean it has diverged from
upstream.

Not the same game as collection `xkx100` / `xkx2017` / `xkx2001`.
Those are the older Xiang/ES-II “侠客行一百” family. This tree is
PKUXKX (北大侠客行): same distant ES-II ancestry, a much larger
original PKU mudlib (21981 `.lpc` after convert), its own newbie
valley (未明谷), and a dual-port GBK/UTF-8 login that we collapsed
to always-UTF-8.

## 0. Layout

Repo root **is** the mudlib. Copied wholesale into `raw/` then
`convert_lib.sh`. Ignored for play: nothing extra (no bundled
driver). Original `config.ini`: `master : /adm/single/master`,
`simul_efun : /adm/single/simul_efun`, `global include : <globals.h>`,
ports 5555 GBK / 6666 UTF-8 / 8888 websocket. This project uses a
single telnet port **40274**.

`raw/` is gitignored. Do not re-clone or re-convert.

## 1. Convert (already finished 2026-09-05)

`convert_lib.sh` UTF-8 pass: `already_utf8=28594 converted=0 lossy=5
skipped_binary=79`. 21981 `.lpc`. Literal `.c"` refs rewritten.
Local angle-bracket includes folded to quotes. `static` → `nosave`
on 93 files. Exit 0.

The upstream repo already claimed UTF-8. `file` on
`adm/single/master.lpc` is UTF-8. `CHINESE_D->is_chinese_character()`
is `pcre_match(str, "^\\p{Han}+$")`, so Chinese-name registration
works after convert without a GBK width hack.

## 2. Always-UTF-8 login — do not set the UTF8 temp flag

Upstream `connect()` did `set_encoding("GBK")` then, only on port
6666, `set_temp("UTF8", 1)` + `set_encoding("UTF8")`. The UTF8 temp
flag makes `feature/message.lpc` and `clone/user/login.lpc` run
`gb_to_utf8()` on every outgoing string.

After convert the whole corpus is UTF-8. Setting that flag would
**double-encode**. The patch is: `set_encoding("utf-8")` on every
connect, and do **not** set `UTF8`. Native registration of `秦风`
printed clean Chinese on look/score/who/quit.

## 3. MySQL is optional

`bsd.lpc` `db_connect("127.0.0.1","pkuxkx","pkuxkx")` fails soft
(`write` + return). Not in preload. Play does not need a database.
WASM is **playable**.

## 4. Bugs fixed this onboard

1. **`natured.lpc` empty-`users()` OOB (AGENTS.md §7.14).**
   `do_event1`–`do_event6` used `if (!(u = users())) return;` then
   `u[random(sizeof(u))]`. An empty array is truthy; `random(0)` is
   0; `u[0]` throws `*Array index out of bounds`. First boot hit
   this because the shipped `/adm/etc/meteoric` timestamp was already
   in the past, so `update_day_phase()` fired a meteor with nobody
   logged in. Guard is `!sizeof(u)` on all six events.

2. **`newsd.lpc` unguarded `restore()` (AGENTS.md §7.7).**
   `data/news/newsd.o` is a shipped 387KB save (almost no newlines,
   3708 embedded CRs, paren count 1293/1295). `restore_object()`
   throws `Illegal array format while restoring news` on first
   `enter_world()`. Wrapped in `catch(restore())` and fall back to
   `news = ({})` when the value is not an array. News listing is
   empty until someone posts; login no longer faults.

3. **`log_error()` warning filter (AGENTS.md §7.10 / §7.34).**
   `strsrch(message, "Warning")` → `strsrch(message, "arning:")` so
   lowercase `warning:` is not written as a hard error.

## 5. Registration / admin

Flow: `new` → English id → `y` → Chinese name (1–6 Han characters,
`pcre` `\p{Han}`) → password (length ≥6 and ≥2 of
upper/lower/digit/special) → confirm → email (`id@address`) →
`m`/`f`.

New characters with `combat_exp < 2000` and no
`newbie_village/done` land in **未明谷**
(`/d/newbie_lxsz/weiminggu.lpc`), not the Yangzhou inn
(`START_ROOM` `/d/city/kedian.lpc`).

Password used for the seeded admin: `Mud@2026` (complexity 16).
`adm/etc/wizlist` has `fluffos (admin)` (kept upstream `mudren
(admin)`). Live `who` listed 秦风 as 巫师; enter_world printed
`目前权限：(admin)`.

`LOGIN_TIMEOUT` is 60 seconds — finish the wizard in one session.

`allowed_sites` already includes `127.0.0.1`. `WIZ_LOCK_LEVEL` is 0.
`command_hook` is `nomask`, not `private`.

## 6. Not done this pass

§10.7 shop/拜师/combat is done 2026-09-05 (see heading below). No
news-save reconstruct (the shipped `newsd.o` is corrupt; catch is
enough). No full §9 format of the 21981-file tree (only the files we
edited). `im_d` is already commented out of preload — no outbound I3.

## 深度功能测试（§10.7，2026-09-05)

Organic 未明谷 → 柳秀山庄 playthrough on 秦风 / `fluffos` (admin,
`Mud@2026`, 十四岁男性, always-UTF-8 login). Driver PID 939959,
`cd libs/pkuxkx && ~/src/fluffos/build-debug/src/driver config.fluffos`,
port 40274. `LOGIN_TIMEOUT` is 60s; climb/bath/sleep/`follow a shu`
need `--idle` ≥10–18s or the next send races the `call_out`.

### Organic path (live)

1. `hp` / eat 野果 / `fill`+`drink hulu` / explore 乱石阵·树林·青石桥头
   / `look path`+`climb up` — already done earlier this day; this pass
   resumed on 缓坡 with the 葫芦 still in inventory. Quest: 拿着刻有
   “柳秀山庄”的葫芦去柳秀山庄一问究竟.
2. `n` `n` `n` to 山庄大门. Entering the room advanced the quest
   (`set_nextquest` in `shanzhuang-damen`). `knock gate` opened the
   door; `ask yahuan about 葫芦` sent her inside and closed it.
3. Second `knock gate`: 丫鬟 auto-led north over ~15s (`set_leader`)
   through 长廊 → 岩桂花园 → 正厅. `give hulu to you kunyi` accepted
   (`id` is `hu lu`/`hulu`). Sequential `ask you about here` / `name` /
   `葫芦` / `闯荡江湖` advanced the 打听 chain.
4. `follow a shu`: male tour 尚武堂 → 正厅 → 西厢房 → 男浴室.
   `follow none`, `remove all`, `bath` (18s busy) → quest 洗完穿上衣服.
   `wear all`, back to 正厅, `ask you about 闯荡江湖` → fight 武师.
5. **Combat.** `fight wushi` in 尚武堂. 武师 one-shot 秦风
   (`太乙有痕`, 气血 20/80, 状态 受伤). Room `die_notify` keeps qi≥1.
   Quest advanced without `halt`. `s` `w` `sleep` in 西厢房 (~12s);
   woke 精神抖擞, quest 向游鲲翼打听闯荡江湖！
6. **Bank.** `ask you about 闯荡江湖` set `balance` 10000. `localmaps`
   in 正厅 printed the 柳秀山庄 map (pager) and advanced. 长廊 south
   is closed until `open gate`. 票号 `check` = 一两黄金;
   `qu 1 gold` emptied the book and advanced.
7. **Shop.** 药铺 `list` = 金创药 五十两白银 / 养精丹 十五两白银.
   `buy yao` / `eat yao` healed to 100/100 健康 (age 14, so
   `cure_ob` is real, not the ≥18 fake-medicine branch). Leftover
   五十两白银.
8. **拜师.** Back in 正厅, `ask` → `bai wushi`. First bai is an
   errand, not a master flag. Leaving 尚武堂 the first time after
   `needmoney` paid **六两白银** and stopped the step
   (`notify_fail`). Organic buys: 铁匠铺 `buy jian` (钢剑 二两白银又
   五十文), 酒铺 `buy shaodaozi` (九十文) then later `buy jitui`
   (四十文), 杂货铺 `buy he` (食盒 五十文). `put jitui in shi he`,
   `give he to wushi`, second `bai wushi` set `newbie_village/master`,
   gave 太乙剑. `cha wushi` listed 九项 (dodge/force/parry/strike/
   sword + taiyi-jian/shengong/you/zhang). `xue wushi for force 10`
   → 基本内功 1.
9. **Quit / persist.** `quit` printed the 百年弹指 poem and closed
   the socket. `work/log/log` (mudlib compile log) gained only
   `quit.lpc:192` unused-`exp` warning. After a wall-clock gap, a
   real `enter_world` (not 重新连线) put 秦风 back in 未明谷
   (combat_exp 490 < 2000 and 尚武堂 is not `valid_startroom` —
   design, not a bug). Quest, 太乙剑, force 1, and 五十两白银 all
   persisted. `debug.log` is live for this boot (mtime 11:34 start,
   new lines at 11:55 / 11:58).

### Bugs fixed this pass

1. **`youkunyi.lpc` quest-key typo.** `init()` called
   `set_nextquest(..., "再次敲门，去见山庄庄主", ...)` — missing
   `(knock gate)` vs `quest_newbie[]`. That call never matched.
   `zhengting.lpc` had the correct key but a copy-pasted next hint
   (“不如去敲敲门”). Live: arriving in 正厅 printed the knock-again
   hint even though the 丫鬟 had just asked for the 葫芦. Fixed both
   strings so either `init()` advances with “快把你身上的葫芦给游鲲翼吧”.
   Not re-walked on a second newbie (this character is already past
   that step).

2. **`dropmoney.lpc` UTF-8 `*String index out of bounds`.** Morning
   `natured` → `move_money` → `write_log` walked a color-wrapped
   Chinese `long` with GBK `x+=2` / `strwidth` as the bound. Live
   crash 11:55:55 on `/d/beijing/zijin/zhaigong` (`j=50`, `x=43`).
   Also: empty `get_dir` would OOB; `get_write_number()` used
   `line[i]` (uninitialized) instead of `line[x]`. `write_log` now
   walks `sizeof` characters and sprinkles `□` on codepoints ≥128.
   `lpcc --batch` PASS. Live: `dest` the daemon, three
   `call /adm/daemons/dropmoney->move_money(5)` — two returned 1
   with 江湖 rumours, no new `debug.log` error. (`update` through
   `/d/wizard/update/` did not reload this file; dest+call did.)

### Observations, not fixed

- 武师 speech says `pu jitui in shi he`; the quest text says `put`.
  `put` works. Content typo.
- 金创药 `value` 5000 vs 武师's 6 silver — the quest funds the
  medicine from the 票号 1 gold, not from the 拜师 silver. Design.
- First `bai wushi` does not set a family (`score` stayed 普通百姓,
  师门忠诚 0). Intended: “只传你武功，今后莫要对外人提起”.
- `newsd` `catch(restore())` still logs the illegal-array restore
  on every `enter_world` (already documented §4.2).
- `work/log/log` unused-`exp` in `cmds/usr/quit.lpc` — compile
  warning only; quit completed.

## 7. Local run

```
cd libs/pkuxkx
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40274**.

```
python3 scripts/mudclient.py 127.0.0.1 40274 --timeout 40 --idle 0.5 \
  --send "fluffos" --send "Mud@2026" \
  --send "look" --send "score" --send "quit"
```

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/backup/dali/房间备份whuan/tianls9.lpc`, `d/wizard/zine/abc.lpc`, `u/iszt/city/huadian.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 OK、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py pkuxkx --fix`（大库单独跑，七轮）：无用局部变量约 5820 个、转义约 150 处、`varargs` 43 处、裸 `return` 6 处、`nosave` 函数 8 个改 `protected`，删去 233 行本驱动不认的 `#pragma save_binary`，共改动 2301 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：2086 -> 2086 通过，无回退；改过的头文件的 2333 个包含者 2088 -> 2088 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 97 条候选都是声明被重建（同一行剩下的变量还在）或同名 efun。
手工：`include/condition.h` 里的条件表 `cond_def` 被 `feature/condition.lpc`、`feature/damage.lpc`、`feature/name.lpc` 和 `inherit/char/char.lpc` 各包含一份，人物对象里四份同名全局变量（启动时 28 条 `Redeclaration of global variable 'cond_def'`）。表用 `#ifndef CONDITION_NO_TABLE` 包起来；只用 `CND_*` 宏的 `char.lpc`、`name.lpc` 先 `#define CONDITION_NO_TABLE`；`damage.lpc` 判断死因时要读毒的名字，改为调用 `F_CONDITION` 新增的 `query_condition_def(cnd)`。`kungfu/condition/*.lpc` 各自独立编译，仍各带一份表。

启动时警告 191 -> 0；新进程登录（标题画面、英文名、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-07）— 被 `;` 截断的消息

`d/baituo/shechang.lpc` 蛇场帮助里 `str += "ask she nu about 蛇(snake) …\n";` 后面三行（怪蛇、取蛇、怪蛇杖）各自成了单独的字符串语句，从来没显示过；接回 `str`。

验证：改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 风洞分身的技能减半

`clone/drug/fengdong.lpc`：`if (victim->query("combat_exp", 1) < 10000) max1/2;` 是空语句（写法没空格，2026-10-06 的全库清扫没认出来），改成 `max1 /= 2;`。新进程编译通过。
