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
