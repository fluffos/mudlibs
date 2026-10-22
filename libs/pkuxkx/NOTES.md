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

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 5 处比较、4 处去后缀（如 `clone/misc/roommaker.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：4 个 NPC 同时继承 `NPC` 和 `F_UNIQUE`、自己没有 `init()`，驱动只取其中一份（`init() inherited from both /feature/unique.lpc and /feature/attack.lpc`）：要么 `attack.lpc` 的主动攻击/仇杀检查从不执行，要么 `F_UNIQUE` 的持有者检查从不执行。每个补一个两份都调的 `init()`（`scripts/lpc_fix_unique_init.py`）；HEAD 与工作树载入结果相同，这条警告清零。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `d/xingxiu/nanjiang2/3.lpc`、`shanjiao.lpc`：删去空的 `if (current_water==0) { }`（行为不变）。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `clone/obj/gemlocker.lpc`：`allamount + amount;` 结果被丢弃，“宝石袋里共有 N 个宝石”永远显示 0；改为 `+=`。
- `d/city/npc/refugee-2.lpc`：`tempskill/5*6;` 结果被丢弃，官兵技能没像气血一样加成；改为 `tempskill = tempskill / 5 * 6;`。
- `kungfu/skill/shanjue.lpc`：`for (…) t ;` 循环体空，`t` 恒为 1，修炼所需正气不随等级翻倍；按全库 205 处同型写法改为 `t *= 2;`。
- `d/luoyang/npc/dian.lpc`：`if (!arg) 0;` 改为 `return 0;`；`quest/escort/escort_board.lpc`：`else 0;` 改为 `else return 0;`。
- `u/boost/gift.lpc`：`#ifndef TEST_MODE` 包住了 if 的全部内容，挪到 if 外面；`adm/daemons/moneyd.lpc` 只剩注释的 `else if (cc) { }` 挪进注释；`d/changbai/ssmiao.lpc` 孤立的 `"\n";` 删去；`inherit/char/family_npc1.lpc`、`u/whuan/familyd.lpc` 空的 `if(armed) { }` 删去；`u/idle/mudi.lpc` `i==0;j==0;` 改为 `=`；`u/jason/13954955881.lpc` `mud_status;` 改为调用；`liangyi-jian.bak.lpc` 去掉无用 `level;`。
- 13 个对象载入无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾（一）

- `toolkit_fix.sh`：24 个返回类型/原型对齐、21 个带初始化的未用局部变量、22 处多余 inherit、2 处转义。54 个对象载入无回退，删除声明审计为 0。
- `u/bibi/obj/fire/xiaomao.lpc` 烟花猫脸图案：`/\ ` 在字符串里是未知转义，原本显示成 `/ `；改为 `/\\ `，猫耳朵的反斜杠才显示出来。该文件本身另有未转义的 `"` 导致编译失败（原档如此），未处理。
- 剩余（约 250 条：`Redeclaration`、die/init/unconcious 等返回类型与基类不符、clean_up 菱形）另行处理。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾（第二轮）

- 能编译的文件里的警告：103 → 0（全库扫描 `lpc_warnings.py`；剩下的 103 条都在本身编译失败的文件里，如 `u/iszt/lingxiao/npc/wenwanfu.lpc`、`data/home/std_file/stdroom.lpc`、`u/whuan/vax/` 草稿，不在本轮范围）。
- 返回类型（46 个函数、4 个原型）：`die`/`unconcious`/`start_busy`/`add_busy`/`fight_ob`/`heart_beat`/`receive_message` 叶子写成 `int`，基类是 `void`。全库查过，没有任何调用方读取这些函数的返回值（`return ::die();` 只出现在 void 函数里），叶子改为 `void`、`return 1;` 改 `return;`。`d/bwdh/sjsz/obj/control.lpc`、`d/diaoyudao/xiaodao/npc/wokou.lpc` 的前置原型一并改正。`d/menggu/npc/liping.lpc` 的 `string ask_job();` 原型与 `muyang.h` 里的 `int ask_job()` 不符，改为 `int`。
- 变量重复声明（31 处）：叶子与基类同名、各存各的数据，两边各自读取，改叶子一侧的名字，行为不变：宝石/打造装备 13 个文件的 `all_colors`（与 `feature/gems.h` 的宝石颜色表不同）→ `grade_colors`；9 个镖局 NPC 的 `mapping *escort_info`（与 `F_ESCORT` 的 `mapping escort_info` 不同，叶子是作为参数传给 `get_dart()` 的）→ `dart_list`；麻将 `mj.lpc` 的牌堆位置 `count` → `mj_count`；国战兵器的重量表 `weight` → `type_weights`（与 `F_MOVE` 的 `weight` 冲突）；剿匪土匪的路线号 `int path`（与命令搜索路径 `string *path` 冲突）→ `route_no`；`d/quanzhen/npc/kid2.lpc` 同一文件里 `string *name` 与 `string name` 两个变量，数组改名 `candy_names`。`kungfu/music/*.lpc` 13 首乐曲继承了 `F_MUSIC` 又再 include `<combat/music.h>`，表格两份完全相同，删去叶子的 include。`d/changan/npc/sunsimiao.lpc` 继承 NPC 已有 `cond_def`，include `<condition.h>` 前加 `#define CONDITION_NO_TABLE`（库里 char/damage/name 已用此法）。`u/zhx/combatd.lpc` 两份相同的 `verbs` 表删去后一份。
- `clone/user/user.lpc`：`apply_buffer()` 同时来自 `feature/login.lpc` 和 `feature/skill.lpc`，两份不同（login 版对玩家多了 eff_qi/eff_jing 补足）。驱动一直用的是 login 版，所以玩家切换技能时 skill.lpc 里的调用也走 login 版；在 user.lpc 写明 `login::apply_buffer()`，行为不变。
- **潜伏 bug**：`feature/skill.lpc` 的 `apply_buffer()` 处理嵌套 mapping 的内层循环写成 `for(lp2=0; lp2<sizeof(nbufs); lp++ )`，`lp2` 永远为 0，一旦遇到嵌套 buffer 就是死循环（eval cost）。目前所有 `buffer_applied()` 返回的都是平坦整数表，玩家又走 login 版，所以没有触发；改为 `lp2++`。
- 其他：`adm/room/lxguan.lpc`、`cmds/arch/make_npc.lpc` 生成 NPC 文件的宏里 `"\#include"`、`"\}"` 的未知转义去掉反斜杠（输出相同）；未用局部变量 10 处（`bonus.h` 的 `limit_sk`、`xytaskd` 的 `hour=now_hour()`、`danuoyi` 的 `pure`、`song/transfer.h` 的 `ob`，都是纯查询）；`d/beijing/npc/mingzhu.lpc`、`duolong.lpc`、`shenghuo-lingfa/jindou.lpc` 已整段注释掉的代码里嵌套的 `/*` 改为 `//`（注释内文字，无行为变化）。
- 验证：改动的 .lpc 及改动头文件的全部 includer 共 135 个对象，HEAD 与工作树载入对比 134/134 PASS，无回退；`d/anqimen/npc/ouyangxue.lpc` 在 HEAD 与工作树都载入失败（create() 运行期，非本轮引入，未处理）。删除声明审计 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。109 个文件 177 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/adm/daemons/jiaofeid.lpc`（`reward +=`）、`/clone/cs/obj/cs_weapon.h`（`penality *=`）、`/d/changbai/npc/hu-quest.h`（`reward +=`）、`/d/changbai/npc/huyidao1.lpc`（`reward +=`）、`/d/changbai/npc/obj/newmap.lpc`（`reward +=`）、`/d/changbai/npc/obj/newmap.lpc`（`reward +=`）、`/d/jiaofei/npc/qqz.lpc`（`reward *=`）、`/d/suzhou/npc/shenlong-zhanglao.lpc`（`reward +=`）、`/d/xytaskd/guojing.lpc`（`jiangli *=`）、`/feature/hockshop.lpc`（`value *=`）、`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）、`/kungfu/skill/xueshan-jianfa/linhai.lpc`（`ap +=`）、`/kungfu/skill/xueshan-jianfa/linhai.lpc`（`ap +=`）、`/kungfu/skill/xueshan-jianfa/linhai.lpc`（`dp +=`）、`/kungfu/skill/xueshan-jianfa/linhai.lpc`（`dp +=`）、`/u/haiv/huyidao/huyidao.lpc`（`reward +=`）、`/u/haiv/murong/murongfu.lpc`（`skill +=`）、`/u/iszt/force/qi.lpc`（`q *=`）、`/u/iszt/force/recover.lpc`（`q *=`）、`/u/whuan/hu/hu.lpc`（`reward +=`）、`/u/whuan/vax/bugfix/1126/createskill.lpc`（`ex /=`）、`/u/whuan/vax/project.0.create.skill/createskill.lpc`（`ex /=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：`feature/vein/BasicVein/shoutaiyin.lpc`（手太阴经）的 `int benefit_effect()` 返回 0.1、0.2、0.33。旧驱动在运行时把浮点原样返回，新驱动编译时就截成 0，所以打通经脉后 `exercise`/`respirate` 的加成全部失效。现改为 `float`；调用处本来就是 `to_float(gain)*(benefit_effect(me)+1.0)`。**玩家可见**：打通手太阴经后打坐、吐纳按原设计多得 10%–33%。`d/xytaskd/guojing.lpc` 奖励、`xiyi-jian`/`yangwu-jian` 的等级、`/u/` 下四份 combatd 的护体减伤、`chan.lpc` 的忙乱时间写明 `to_int()`。改动的 193 个对象载入无回退。

- 2026-10-14：4 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：9 个对象，新增载入 8，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/xiantian-quan`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 5 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 5 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。1 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`jinwu-dao`。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`（`ob->query_temp("weapon")` 报错），还把兵器对象和字符串 "银针" 比较。改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`zhuihun-jian/zhuihun`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：驯马的 `/d/dalicheng/npc/mafu`、`/d/tianlong/npc/mafu`、`/d/wuliang/npc/mafu`（成功率少了福缘一项）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`longxiang-boruo` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`buddhsim`→`buddhism`（`qianye-shou`）；`huanxi_chan`→`huanxi-chan`（`longxiang-boruo/yinyang`）；`jinshe-zhuifa`→`jinshe-zhui`（`/d/bwdh/sjsz/obj/obj/weapon/jinshe-zhui`）；`jiuyin-baiguzhua`→`jiuyin-baiguzhao`（`jiuyin-shenzhua`）；`qufeng-shu`→`qufengshu`（`/d/gumu/npc/yufengqun`）；`yan-fly`→`yanfly`（`yanfly`）；`yunv-xinfa`→`yunu-xinfa`（`xuantian-wuji`）；`zhengqi-jue`→`zhengqijue`（`/d/bwdh/human`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`jingang-buhai`→`jingang-buhuai`（`/adm/daemons/toptend`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 存档读不出来：BIG5/GBK 0x5C 字后的反斜杠（2026-10-15，KB 03 §4.4）

`/data/cname_list.o`：第二字节为 0x5C 的字（功、许、么、俞、賊……）MudOS 存档时写成 `\\`，转成 GB 后字保留，多出的一个反斜杠转义了后面的引号（`成功\",` 字符串收不了尾），或反过来，MudOS 当作被 0x5C 转义的引号成了字符串的结尾（`出\"俞" >`）。`restore_object()` 报 `Illegal mapping format`，留言板等从空白开始。在出错处去掉或补上这一个反斜杠，直到能读回（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回。


## 新闻档读不出来（2026-10-15，KB 03 §4.4）

`data/news/newsd.o` 里一条新闻标题是 `"服务器更新内存成功?,`：上游 UTF-8 转换把一个转不了的字和后面的引号一起变成了 `?`，`restore_object()` 报 `Illegal mapping format`，新闻系统空白。补上引号，驱动核对能读回。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参、虎骨，`clone/drug/cb_renshen`、`clone/drug/hugu`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、8 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/biwu/xy/obj/bcloth`、`/biwu/xy/obj/buxue`、`/clone/weapon/qiang`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 4 个（4 个原来载入不了），没有退步；其余 3 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/include/net/ftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 12 个对象设了本库没有文件的武功（19 个名字，最多的是 `zixia-gong`、`guishoushe`、`liangyi-dao`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：12 个里 11 个通过，其余 1 个停在别的错误上（`obj/npc/half_god`：*No program in object '/obj/npc/half_god'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/lanzhou/east_avenue2` 的 `south`：`datie` → `datiepu`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 17 处、17 个文件：`huashan-jinfa`→`huashan-jianfa`（6 处）、`xiake-trike`→`xiake-strike`（3 处）、`cuixinzhang`→`cuixin-zhang`（2 处）、`yijinjing`→`yijin-jing`（2 处）、`banrou-zhang`→`banruo-zhang`（1 处）、`huashan_shenfa`→`huashan-shenfa`（1 处）、`douzhuan-xiongyi`→`douzhuan-xingyi`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 11 处、11 个文件：`::create()`（11 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 5 个文件：`/clone/gem/blade.lpc`、`/clone/gem/sword.lpc`、`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## simul_efun 丢了 unew()（2026-10-19，KB 06 §7.262）

`adm/simul_efun/object.lpc` 没有 `unew()`（带“独一无二”次数限制的 `new()`），`kungfu/class/dalunsi/laozu2` 按 xkx 一系的写法调用它，`Undefined function unew`。从同系的 xkxz2 把这个函数原样补回 `object.lpc` 末尾（`scripts/lpc_transplant_function.py`）。这个物件还差宏 `BINGQI_D`（本库的头文件没有定义），所以仍载入不了，属于未定义宏一类，另案处理。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 6 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/lingzhou/npc/yun.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 4 个文件：`/adm/daemons/ftaskd.lpc`、`/kungfu/skill/sword/jianyi.lpc`、`/u/vast/gems/cmds/combine.lpc`、`/u/whuan/vax/project.3.userlevel.huamanrace.sp/char.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 2 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/city/npc/boji.lpc`（1 处）、`/d/mingjiao/npc/obj/shenghuo-ling.lpc`（1 处）。

## 深度功能测试（§10.7，2026-10-20）：实机指令扫描的第一批发现（KB 08 §10.16）

用 `scripts/play_boot.sh` + `mudplay.py` + `playsweep.py` 起实例，注册新人物、对每条普通玩家指令发十种参数，同时看驱动控制台和 `log/debug.log`（本库的 `error_handler` 把运行时错误写在这里，玩家屏幕只显示“WARNING 这里发现了臭虫”）。找到并修复的程序错误：

1. **`adm/daemons/toptend.lpc`**（排行榜）：`mapping topten_data;` 在第一条排行数据出现之前是 0，`topten_add()` 里 `topten_data[type]` 报 `Value being indexed is zero`；新人物进游戏时（`enter_world` → `topten_checkplayer`）和之后每个心跳的 `decrease_activity()` 都触发，全新安装的游戏里每个玩家都反复看到“WARNING 这里发现了臭虫”。改为 `mapping topten_data = ([]);`。
2. **`adm/daemons/logind.lpc`、`logind2.lpc` 的 `check_legal_id()` / `check_legal_describe()`**：`i = strwidth(id)` 之后 `while(i--) id[i]`；`strwidth` 数的是显示宽度（一个汉字算 2），按字符下标就越界 `String index out of bounds`。在“英文名字”提示符下输入中文名字、或给 NPC / 物品设中文描述（`LOGIN_D->check_legal_describe()`，`adm/npc/wang.lpc`、`shopgirl.lpc`）都会报错。改为 `i = strlen(id)`。
3. **`cmds/std/ask.lpc` 的 `check_en()`**（`ask 某人 about 某事` 在对方不懂这个话题时选择回答用）：同样是 `i = strwidth(id)` 加字符下标，中文话题就报错、玩家看到的是臭虫提示而不是“他不懂”；改为 `strlen`。同类的 `logind.lpc` 密码复杂度检查（`lp = strwidth(passwd)`）、`d/city/npc/huang.lpc`（取名字的后两个字，4 处）、`d/changan/npc/zhuangjia.lpc`（`chn_check()` 和 `odds_init()` 的字符下标循环）一并修了：长度限制仍用 `strwidth`（显示宽度），下标用 `strlen`。检测脚本：`~/.cache/lpc-scratch/probe/strwidth_index.py`，另有约 30 处同形代码（`createskill.lpc`、`player_hockshop.lpc`、`zongrenling.lpc` 等）按 GBK 字节语义写、改成字符语义会同时改变长度限制，留待以后逐个看。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/d/ludingshan/vrm_server.lpc`（1 处）、`/inherit/room/virtualmaze.lpc`（1 处）、`/std/json.lpc`（10 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 29 处）。改动：`/adm/daemons/damingd.lpc`（1 处）、`/adm/daemons/dasongd.lpc`（1 处）、`/clone/gift/liwu.lpc`（10 处）、`/d/beijing/npc/mj.lpc`（3 处）、`/d/changbai/obj/bigstone.lpc`（1 处）、`/d/city/npc/mj.lpc`（3 处）、`/d/city/puke-room.lpc`（4 处）、`/d/guozhan/room_config.lpc`（1 处）、`/d/yideng/yideng/npc/yu.lpc`（1 处）、`/feature/skill.lpc`（1 处）、`/feature/vein/vein.lpc`（1 处）、`/kungfu/skill/sanwu-shou/sanbu.lpc`（1 处） 等 13 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/eventd.lpc`（1 处）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 8 个存档共 155 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/wizard/zine/labaz.o`（142 处）、`/data/business/hockshop_7.o`（1 处）、`/data/business2/hockshop_7.o`（1 处）、`/data/recover/beixia.o`（5 处）（等共 8 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`；没有 `help()` 的是 `return notify_fail("…\n");`。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/kickout_room.lpc`（`find_object`）、`/cmds/arch/srl.lpc`（`get_dir`）、`/cmds/wiz/telnet.lpc`（`strsrch`）。加载检查 HEAD 与工作树对照，没有退步。

## 九阴真经上篇：`/cmds/skill/du.lpc` 本库叫 `study`（2026-10-21，KB 06 §7.344）

`/d/bwdh/sjsz/obj/obj/unique/jiuyin_force_book.lpc` 的 `do_read()`：`9yin == "granted"` 的玩家读书时 `"/cmds/skill/du.lpc"->main(me, arg)`。本库把这条指令改了名（`cmds/skill/study.lpc`，代码和别的库的 `du.lpc` 相同，用法行写着 `study|du`），`du.lpc` 不存在，读书就是一条 `couldn't find object`。改成 `"/cmds/skill/study.lpc"`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`chck_me` → `check_me`；`destory` → `destroy`；`destory` → `destroy`；`disappear1` → 文件里定义的 `disapper1`。改动：`/clone/npc/camel1.lpc`、`/d/changjiang/npc/shaogong.lpc`、`/d/gift/rsbb.lpc`、`/d/huanghe/npc/shaogong.lpc`、`/d/huashan/npc/newdizi.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 52 条注册（39 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`）、`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`）、`/d/beijing/qishi.lpc`（`do_pass`、`do_resign`）、`/d/changan/doujichang.lpc`（`do_bet`）、`/d/city/changjiang.lpc`（`do_xiang`、`do_zhan`）、`/d/city/idleroom.lpc`（`do_none`） 等共 39 个文件。最多的函数名：`do_none` 7 处、`do_pour` 5 处、`do_decide` 4 处、`do_rehash` 2 处、`do_test` 2 处。没有动（读过）：`/clone/npc/sellern.lpc` 的 `do_ding`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/npc/sellern.lpc` 的 `do_fuhuo`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/bwdh/sjsz/obj/obj/weapon/yaoqin.lpc` 的 `do_lianxi`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/yingtianfu/neicheng/fengtiandian.lpc` 的 `do_join`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/yingtianfu/neicheng/obj/guanyin.bak.lpc` 的 `do_repair_daming`（对象本身编译不过，登记留着，等对象能加载再处理）、`/kungfu/class/xiakedao/mujianfeng.lpc` 的 `do_dismiss`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 6 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/bwdh/kantai.lpc`（`do_abandon`、`do_practice`、`do_study`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/city/npc/lver.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

目标文件的位置也改了：`d/city/npc/lver.lpc` 不在 `d/wudang/npc/` 里，`../obj/nuerxiang` 指向它自己区域下的一个不存在的路径；女儿香茶杯在 `/d/wudang/obj/nuerxiang`，所以改成 `"/d/wudang/obj/nuerxiang"`。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（3 处调用）、`check_length()`（3 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 12 个函数没有补（inquiry 11, chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/jinyang/npc/guanyuan.lpc`:`ask_job`、`/d/jinyang/npc/guanyuan.lpc`:`askforhelp`、`/d/luoyang/npc/huang.lpc`:`ask_finish`、`/d/parties/public/npc/niwajiang.lpc`:`ask_build`、`/d/quanzhen/npc/yueru.lpc`:`ask_bf`、`/d/xiakedao/npc/zhangsan.lpc`:`ask_me`、`/kungfu/class/huashan/job/killer.lpc`:`ask_surrender`、`/kungfu/class/huashan/job/killer2.lpc`:`ask_surrender`、`/kungfu/class/niwajiang.lpc`:`ask_build`、`/kungfu/class/xiakedao/longyifan.lpc`:`ask_me` 等另外 2 个。 另有 3 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 大明官场（应天府内城）的头衔宏 `TITLE_MING1..4` 没有定义，31 个包含 `promote.h` 的文件加载不了（2026-10-22，KB 04 §6.16 补充）

`d/yingtianfu/neicheng/` 的大明官场系统（`adm/daemons/damingd.lpc` 管理，`npc/promote.h` 被 31 个文件包含：24 条官场命令里的大部分、`shengzhi` / `datong2` / `tongzhen` 等房间、`li-shangshu` 等 NPC）用 `TITLE_MING1`（官职）、`TITLE_MING2`（散阶）、`TITLE_MING3`（加官）、`TITLE_MING4`（爵位）调用 `set_title()` / `get_title()`，而 `include/title.h` 只有 `TITLE_SONG1..5`：`Undefined variable 'TITLE_MING2'`（`promote.h` 第 248、265、281、321、839、846 行），这些文件整个加载不了，`damingd` 启动时加载 `shengzhi` 也失败。`feature/name.lpc` 的 `set_title()` 对 `check_title()` 查不到的类型会抛 `输入的头衔类型未定义`，所以只补宏不够：`include/title.h` 加 4 个宏（值 `"ming1"`..`"ming4"`，照 `TITLE_SONGn`），`check_title()` 的类型表加 4 行（`大明官职头衔`、`大明散阶头衔`、`大明加官头衔`、`大明爵位头衔`，配色照 SONG 系列；含义取自 `commands/query.lpc` 的显示标签 `【散阶】`MING2、`【加官】`MING3、`【爵位】`MING4，和 `promote.h` 把 MING1 设成「大明 官名」）。证明：`scripts/lpc_listcheck.sh` 载入 753 个对象（大明官场 449 个文件 + 其他区域随机 300 个 + `damingd` / 告示板 / `gemlocker`），HEAD 636 → 工作区 747 个能加载，新增 111（NPC 36、命令 16、房间约 58、`damingd`、告示板、`gemlocker`），0 个变坏；剩下的 6 个失败全在随机抽样里（备份目录、片段文件），和本条无关。新进程 `scripts/lpcc_eval.py`：`li-shangshu` 加载，`set_title("ming1", ...)` 成功、`get_title()` 取回，`check_title("ming4")` 有名字，`damingd` 和 `shengzhi` 加载；24 条命令用一个带 `mingpin` 的 NPC 各调用一次 `main()`，22 条正常返回，`jili`（用 `environment(me)`）和 `query`（用 `this_player()`）在没有房间和玩家的测试条件下出错，不是缺陷。没动：`commands/query.lpc` 把 MING4 当爵位、`tongzhen.lpc` 的「特进」封爵却写在 MING3，两处用法不一致，是作者没写完的设计，不是我能判定的。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 4 处（`d/dali/obj/hupi`、`d/dali/obj/mandao`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 3 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 3 个（新增可加载 2 个，回归 0 个）。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 7 个子目录写日志：`log/acct`（`cmds/guider/unblockapp.lpc`）、`log/antirobot`（`d/wizard/judge_room.lpc`）、`log/helpnew`（`d/city/npc/obj/tianxiangyulu.lpc`）等。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/acct`、`log/antirobot`、`log/helpnew`、`log/job`、`log/money`、`log/quest`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 14 个文件里 19 行只含这个指针的行（`"job" : (: ask_job :),` `"护送" : (: ask_job :),` `(:askforhelp:),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 31 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；改名官 `zhuce` 的长度检查按字节算，合法的名字一个也过不了；NPC 的称呼和提示里取到两个字而不是一个字。

本库 31 处（18 个文件）：拼名字的赋值 4 处、与汉字常量比较 5 处、改名官的长度检查 1 处、`query("name")[..]` 21 处。例：`name[0..3]` → `name[0..1]`（`/d/yideng/yideng/npc/yideng.lpc:198`）；`name[0..5]` → `name[0..2]`（`/d/yideng/yideng/npc/yideng.lpc:200`）；`myipfrom[0..5]=="北京市"` → `myipfrom[0..2]=="北京市"`（`/cmds/usr/who.lpc:369`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
