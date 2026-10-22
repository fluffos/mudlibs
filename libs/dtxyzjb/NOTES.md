# dtxyzjb（大唐西游指间版）-- porting notes

Archive `大唐西游指间版.rar`（编号 930）是带注释的加密 RAR：

```
地狱玩家服群号：676036579
密码：676036579
```

`unrar t -p676036579` 全档 All OK。与空状态的 GitHub `dtxy`（duplicate_of `dtxywzxzb`）不是同一份档案；这是 2009「指间版」完整 mudlib（`大唐西游2009/`，`master file : /adm/obj/master`）。

`convert_lib.sh … GB18030`：already_utf8=1199 converted=14582 lossy=595 skipped_binary=25；13469 个 `.lpc`。lossy 偏高（不少 `death/npc`），登录提示里 BIG5 那一行有乱码。端口 **40267**。

这是「指间」手机网关版：`logon()` 先写 `ver1.0,<crypt>` 再
`input_to("jiance")`。普通 telnet 发任意非网关密文就会落到 `get_id`
（不是先选 gb）。`preload` 里 `/adm/daemons/convertd` 编不过（No
program），不挡 telnet 登录。`is_chinese()` 已改成 Unicode 码点检查。
`adm/etc/wizlist` 加了 `fluffos (admin)`。

## 商店 + 拜师（2026-09-04 librarian shop slice）

新角度：南城客栈付费购买 + 将军府秦平拜师。进口笔记只写了握手，
没有 `buy` / 拜师实测。本机 `debug.log` 仍是 13:06 的进口启动残档
——`log directory : /log` 是绝对路径，`/log` 不存在，驱动从不打开
`work/log/debug.log`。运行时错误看 tmux 和 mudlib 自己的
`work/log/log`（`master->log_error()`）。

### 修了三处真编程 bug

1. **`CONVERT_D` 编不过，每个 telnet 在 `logon()` 第一行 `write()`
   就断线。** `login.lpc` 的 `receive_message()` 把所有 write 交给
   `CONVERT_D->output()`。原档 `convertd.lpc` 的 GB/BIG5 对照表是
   iconv 残留垃圾，FluffOS 在希腊字母那几行报 `Illegal character
   0xce`，daemon 是 `*No program`。第一次 `write("\n")` 走
   `logon()` → simul_efun `write()` → `receive_message()` → 死
   daemon，`new_conn_handler` 直接踢人。工作树已经是 UTF-8，手足
   `dtxywzxzb` 把 GB/BIG5 都映射成 passthrough。换成同接口的恒等
   `input`/`output`/`BIG2GB`/`GB2BIG` 之后，`ver1.0,<crypt>` 握手
   能出来，任意非网关行落到 `get_id`。

2. **telnet 注册入口 `new` 永远走不到。** `check_legal_id()` 的
   4–20 长度闸（指间客户端加的）排在 `get_id()` 对 `"new"` /
   `"guest"` 的特殊处理前面。发 `new` 只回「ID长度不符合要求
   (4-20)」。放行这两个保留字；同时 `MAX_LOGIN` 那段
   `new(USER_OB)` + `restore()` 对保留字也跳过，免得拿 `"new"`
   当玩家档冷加载一整棵 user 物件。

3. **`clone` 因 `/log/nosave/` 不存在崩溃**（§7.11，与
   `wlqxcmudlib` 同形）：`adm/simul_efun/file.lpc` 的 `log_file()`
   直接 `write_file`，没有 `assure_file()`。`clone /obj/money/gold`
   写 `nosave/CLONE` 时报 `Wrong permissions ... No such file or
   directory`，黄金变不出来。已加前向声明、`seteuid(ROOT_UID)`、
   写入前建目录。修复后「黄金复制成功」。

### 实测过程

指间握手：先发任意非网关行（这里用 `x`）再进 `get_id`。注册
`new` → `fluffos` → 云游 → 管理密码 `Mud@2026` ×2 → 登陆密码
`Play2026x` ×2 → `test@dtxy.net` → `m`。`confirm_gift("n")` 自动
进南城客栈 `/d/city/kezhan`。提示是每秒时钟（`env/prompt` =
time），`mudclient.py` 用 `--idle 0.5`。巫师再登会要「巫师专用
密码」，本轮设了 `Wiz@2026x`（不能和管理/登陆密码相同）。

`list` 炸鸡腿八十文 / 花生二十文 / 桂花酒袋一两银子。指间
`do_buy` 没有数量就弹 `INPUTTXT`「你要买多少【jitui】」，telnet
要写 `buy 1 jitui`，不是手足那句 `buy jitui from xiaoer`。`clone
/obj/money/gold` 后 `buy 1 jitui`：「你从店小二那里买下了一根炸鸡
腿。」`i` 二十文钱 + 九十九两银子 + 炸鸡腿（10000−80=9920）。

`goto /d/jjf/jjf_bingqi`，`bai qin ping` 秦平（管家，无门槛）
`command("pat/say/recruit")` 全有输出，「恭喜您成为将军府的第四代
弟子」，`score` 职称「将军府第四代弟子 云游」、师承「将军府秦平」。
`save` / 退出 / 再登：门派、炸鸡腿、找零都在。

第一次冷加载 `USER_OB` 会刷一串「系统局部错误」（其实是
`log_error()` 把 `Unknown #pragma` / unused-variable 警告写给还没
进世界的连线物件）。物件编过之后再登就安静了，不是本轮要改的
功能缺口。管理员存档未提交。

## WASM (2026-09-11 leftover 653)

指间 `logon()` 仍写 `ver1.0,<crypt>`，手机客户端走 `crypt(ZJKEY,str[2..3])`
分支。浏览器/WASM 没有指间客户端：原先非网关第一行被丢掉，再
`input_to(get_id)`，访客得先发一个废行。已改成非网关第一行直接当
英文 id。`wasm_client.js`：`fluffos` / `Play2026x` / `Wiz@2026x` →
南城客栈 `/d/city/kezhan`，`look` 有客栈长描（夹指间 `$zj#` 标记，
这是档里原有的指间输出，不是新造房间），`score`「将军府第四代弟子
云游」「师承秦平」，`quit` 大唐西游告别。已提交管理员存档。
`wasm_status` 改为 `playable`。提示仍是每秒时钟，`--idle 0.5`。
不要把 `zjdyzj` 翻回 limited。

## 深度功能测试（§10.7，2026-09-13）

原生 driver 端口 40267，`fluffos` / `Play2026x` / `Wiz@2026x`。stdout
tee 到 `/tmp/dtxyzjb-driver.out`。`log directory : /log` 在 slug 目录
启动时先开 `libs/dtxyzjb/log/debug.log`（§10.9：建了 slug 级 `log/`）；
mudlib 自己的编译/运行时诊断在 `work/log/log`（`master->log_error()`）。
`work/log/debug.log` 仍是 09-04 残档，不当作本轮证据。

### 发现并修复

1. **§7.90 `maximum evaluation cost : 600000` 过低。** 冷登录走
   `get_passwd_wiz` 时懒编译客栈 NPC（`d/city/npc/bai`）触发
   `Eval interrupted … limit: 600000 usec` / `*Too long evaluation`，
   `enter_world` 半截中止，身体落在 void（`look` →「四周灰蒙蒙」），
   店小二等房间物件也不在。手足 `dtxywzxzb` 已是 `5000000`。已把
   `config.fluffos` 提到 `5000000`。重启后首次登录直接落在
   `/d/city/kezhan`，`look` 可见店小二/地狱使者/千里眼/唐三藏/门派
   使者。

2. **`file_owner()` 把 `/u/<wiz>/…` 误解析成中间目录名。** 本树巫师
   家是扁平 `/u/lying/…`（`user_path()` 亦然），旧
   `sscanf("/u/%s/%s/%s")` 把 `/u/lying/npc/angel.lpc` 当成 owner
   `"npc"`，`log_error` 写 `/u/npc/log` → `Wrong permissions … No such
   file`。已改成 `sscanf("/u/%s/%*s", name)`，返回第一段巫师名。

### 游玩证据

- `help newbie`：南城客栈起步、`buy`/`list`/`拜师`/`learn` 说明可读。
- 商店：`list` 出花生豆二十文 / 炸鸡腿八十文；有机 `buy 1 jitui` →
  「你从店小二那里买下了一根炸鸡腿。」（指间 `do_buy` 数量前缀，不是
  `buy … from …`）。
- 拜师/学艺（切片已拜秦平）：`goto /d/jjf/jjf_bingqi`，
  `learn unarmed from qin ping`，潜能 99→98/97；`score`「将军府第四
  代弟子 / 师承秦平」。
- 战斗：`clone /d/city/npc/obj/muren`，`fight mu ren` 互出拳脚，
  `surrender` 干净结束（客栈 `no_fight`，木人是巫师 clone 进场）。
- `quit` → 大唐西游告别文；隔约一分钟重连（退出锁），`i` 仍有
  20 文钱 + 98 两银子 + 两根炸鸡腿 + 花生豆，门派/师承在。

### 日志

本轮修复后的 boot：`work/log/log` / slug `log/debug.log` / driver
stdout 无 `cost limit` / `Too long` / `Wrong permissions` / `/u/npc`。
编译期 `Unknown #pragma` / unused-variable 警告仍会刷给巫师屏，不是
本轮功能缺口。

### 未改

管理员运行时存档未提交（与仓库惯例一致）。`oo.lpc` 里有一份未
`#include` 的旧 `file_owner` 副本，未动。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (1 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`, `u/lying/ic2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply dtxyzjb`: 25 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 1 path reference(s) in 1 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 33 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 27 PASS, 0 that loaded before fail now, 25 more load.

25 files moved (25 `.C`); mostly under `d/shenjian/obj` (5), `u/lying/obj` (3), `clone/armor/bang.C` (1), `clone/armor/blade.C` (1). A rescan with `scripts/lpc_warnings.py dtxyzjb` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退；`adm/daemons/questd.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 飞贼的装备路径

`u/lying/feizei/feizei` 和 `u/lying/tonggang/feizei/feizei` 给飞贼带的装备写成 `/u/tianlin/feizei/obj/…`，本库没有这个目录，装备在各自的 `obj/` 下。`carry_object()` 出错时 `choose_feizei()` 在重新 `call_out` 之前中断，飞贼事件第一次就停止。路径改成各自所在目录（与 sjcs 同一处代码）。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py dtxyzjb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/dntg/yunlou/npc/yaoguai.lpc`、`yaoguai-b.lpc` 的 `for(t==0; ...)` 改成 `=`，`xuanyuan-archery` 删去 `(: throw_weapon :);` 等），共改动 906 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：865 -> 864，少的那个 `u/pujing/room/leitai4/milin` 只删了两个没用到的局部变量，单独加载通过，是批量加载的假象；改过的头文件的 465 个包含者 416 -> 416 通过。
手工：`daemon/skill/huomo-dao/boyue.lpc` 和 `daemon/class/tianmo/huomo-dao/boyue.lpc`（火魔刀「波月」）的出招描述被多余的 `;` 截断，后半句"$n只觉刀光如电，竟不知如何躲避了！"从来没显示过、颜色也没还原；接回去（`scripts/lpc_join_cut_strings.py`）。`adm/daemons/natured.lpc` `event_night()` 里只在注释掉的钟馗段落用的 `badguy`、`room2` 删去。
未动：`d/jjf/npc/xiaomotou1.lpc`、`d/npc/vr_room/obj/tai1.lpc` 本身有语法错误，HEAD 起就编译不过。

启动时警告 53 -> 0；新进程登录正常（新人物用 `new`）。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 24 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 20 个，只在 #if 分支用的声明移进分支 0 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 33, tree PASS 33; regress 0; newly loading 0），这些文件的警告 116 -> 72。

## 深度功能测试（§10.7，2026-10-11）：全库严格 UTF-8 检查

- `d/sea/npc/beast1.lpc` 转码时漏了，仍是 GBK，且文件末尾 `}` 之后多两个垃圾字节（`\xff\xba`）。去掉垃圾字节后按 GB18030 转成 UTF-8，代码完整，名字（花皮、绿背、双头、虎齿……龟）恢复正常，载入通过。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 205 -> 0（`scripts/lpc_warnings.py dtxyzjb` 重扫：13175 个文件可编译；剩下 11 条都在本来就编译不过的 3 个文件里：`adm/simul_efun/oo.lpc` 是 `object.lpc` 的旧拷贝、没人引用；`d/npc/vr_room/obj/tai1.lpc` 是缺了开头的残片；`u/xdao/verifyd.lpc` 有语法错误）。同系的 dtxywzxzb 今天已收尾，`lpc_twin_port.py classify` 显示两库对应文件多数“differs”，所以按它的修法逐个手改（ground.h 表格 guard、quest.lpc 的 colors.h 移进 guard、toptend 的 `#undef`、reporting 的未用 `str`）。

**真问题：**
- `adm/daemons/network/mail_serv.lpc`：`else if(tmp[i] == EOT) tmp[i] == EOT+".";` 是比较不是赋值（TMI-2 那次全库清扫因为没空格的写法漏了这一处），改成 `=`。
- `u/yhq/npc/anong.lpc` 阿浓：`int fight_ob()` / `int kill_ob()` 覆盖基类却不调用 `::fight_ob()` / `::kill_ob()`，她只换出招表、从不真的进入战斗；改成 `void`，先调用基类（该文件因缺技能档在 HEAD 就载入失败，修改只在它能载入时生效）。
- `d/jjf/npc/xiaomotou1.lpc` 小魔头：`attempt_apprentice` 前残留了半截旧函数头 `void attempt_apprentice(object ob, object me) {`，整个文件编译不过；删去这两行，现在能载入。

**其余：**
- `d/dntg/yunlou/npc/yaoguai.lpc`、`yaoguai-b.lpc`、`yao.lpc` 及 `u/lxmas/` 的 5 份拷贝：自己的 `nosave int tick`（出绝招的节拍）与 `std/char.lpc` 的 `tick`（心跳节拍）同名，驱动本就给了两个变量；把叶子这边改名 `perform_tick`，行为不变（35 条 `Redeclaration` 来自它和继承它的 `yg-*`）。
- `include/vrm.h`：迷宫表被 `std/room/vrm_server.lpc` 和继承它的 8 个 `d/room/vr_room/vrm_*.lpc` 各包含一次；表格包进 `#ifndef VRM_TABLES_INHERITED`，这些房间在包含前定义它。`u/pujing/room/leitai1-4/ground.h` 同样处理（`GROUND_TABLES_INHERITED`）。
- `d/kaifeng/npc/quest.lpc` 与 `u/pujing/room/leitai1-4/npc/quest.lpc`：`#include "colors.h"` 移进 `__KAIFENG_QUEST__` guard。
- `d/game/give/yuan.lpc`：`int bt = 2;` 连写三遍，留一遍。
- `u/kicky/workroom*.lpc`、`u/xzg/workroom-bak.lpc`：多余的 `inherit newitemname`（`newitems` 已继承它）删去；它们自己那份内容不同的 `tianfu1/tianfu2` 改名 `room_tianfu1/2`，行为不变。
- `toolkit_fix.sh`：8 个多余 `inherit`（多为 `F_CLEAN_UP`），`u/yhq/westseastore.lpc` 的 `reset()` 改 `void`（原型同改）；`u/rocky/toptend.lpc` 8 个 `#undef`。

验证：改动文件、包含 `vrm.h`/`ground.h` 的对象和继承改名后 `yaoguai` 的对象共 161 个，HEAD 与工作树各用新进程载入：152 -> 153 通过，regress 0。删除声明审计 0 项待看。161 个对象载入无回退。

- 2026-10-12：`d/jjf/npc/xiaomotou1.lpc` 拜师广播的字符串里直接换行（LPC 字符串不能跨行，6986ce28cd8 删了外层函数头后仍编不过），改成 `\n\n`，输出不变；现在能载入（zitengzhan 同修）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。8 个文件 18 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：擂台 `d/leitai/leitai.lpc` 整份不编译：`fullup()` 缺了收尾的 `}`，后面那份重复的 `do_quit()` 被读成 `fullup()` 里的局部声明。补上 `}`，删去那份从未生效的重复 `do_quit()`（前面那份照旧是 add_action 的目标）。现在载入。

- 2026-10-14：1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

49 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bainiao-jian/feijian`、`bawang-qiang/ba`、`bawang-qiang/meihua`、`bawang-qiang/zhuiming`、`bingpo-blade/ningxie`、`canxin-jian/jinsheng`、`canxin-jian/xiaoyao`、`dali-bang/mantian`、`dali-bang/shenli`、`dashen-bian/diaoyu`、`daya-jian/badao`、`duo-sword/shisan` 等 44 个。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`huomo-dao/moguan`、`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

14 个文件、14 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/weapon/sword/xy_sword.lpc`、`/d/obj/weapon/hand/hand.lpc`、`/u/ken/obj/weapon/blade/dongyangdao.lpc`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 9 个，改后 15 个（6 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/shouxing.lpc`。改后载入：1/1 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 29 个对象设了本库没有文件的武功（50 个名字，最多的是 `zhaoyangbu`、`huxiaoquan`、`huntianforce`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：28 个里 25 个通过，其余 3 个停在别的错误上（`d/game/biao/fan`：*Inherited file '/d/snowtu/npc/super_npc' does not exist!；`quest/renzhi/npc/quest_bandit`：*Bad argument 1 to EFUN call_other()……）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 31 处、31 个文件：`lahua-shou`→`lanhua-shou`（19 处）、`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）、`xuanhu-balde`→`xuanhu-blade`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::die()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 4 个：`/daemon/skill/taiji-quan.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill/zhuihun-sword.lpc`、`/daemon/skill_wiz/whip/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## enable_player() 重入保护（2026-10-19，KB 05 §7.19）

`feature/command.lpc` 的 `enable_player()` 没有重入保护：门派掌门大弟子 `zhangmen.lpc` 的 `init()` 以 `me->setup();` 收尾，`setup()` 调 `enable_player()`，`enable_commands()` 又重跑 `init()`，第一个进房间的活物就触发 `Too deep recursion`（dtxyzjb `d/tianmo/door` 载入就失败，另有 5 个掌门房间在有活物走进来时失败）。按 §7.19 加了标志变量（`scripts/lpc_fix_enable_player_guard.py`）。改后同样的测试（载入掌门房间，再克隆一个活物走进去）不再出错，没有退步。

## 开封擂台头文件的重复全局变量（2026-10-19，KB 04 §6.10）

`d/kaifeng/ground.h` 里的 `modes`、`mode_hints`、`families` 三张表被 `ground0.lpc` 和继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次，每次 `inherit` 都报 `Redeclaration of global variable`。表只放在 `ground0.lpc` 里：头文件用 `#ifndef GROUND_TABLES_INHERITED` 包住表，继承的几个程序在 `#include "ground.h"` 前 `#define GROUND_TABLES_INHERITED`（与 xiyouji 系其余库同一改法）。`d/kaifeng/npc/colors.h` 也加了防重复包含。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/u/allenc/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/cmds/std/fly.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/yhq/npc/annie.lpc`。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：7 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/quest/renzhi/vrm_server.lpc`（1 处）、`/std/room/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（2 处）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 登录计数文件 `UserNumber` 缺失（2026-10-20，KB 06 §7.298）

`logind.lpc` 的 `do_counter()` 读 `/adm/daemons/UserNumber`（访客计数，运行中的 mud 才会写）；`.gitignore` 把它排除在仓库之外，所以新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不调用它，但同样会在调用时出错。加了 `if (stringp(file))` 的守卫（与 dtxywzxzb、rzrmud、xiyouji2006、zitengzhan 早先的做法相同）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 4 个存档共 20 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/cmds/usr/quest.c.o`（6 处）、`/d/obj/npc/yao.o`（8 处）、`/d/qujing/lingshan/npc/rulai2/obj/jingshu.o`（2 处）、`/d/ygbz/baokudt.c.o`（4 处）（共 4 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/wiz/info.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 22 条注册（15 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/fangzhang1.lpc`（`do_get`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/leitai/wizroom.lpc`（`do_life`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/qujing/baoxiang/obj/baxianzhu.lpc`（`do_zhengzhi`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/shengdoushi/7hai/shendian/npc/haihuangnpc.lpc`（`do_noshoot`） 等共 15 个文件。最多的函数名：`do_get` 2 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处、`do_push` 2 处。没有动（读过）：`/d/game/biao/biao.lpc` 的 `do_none`（对象本身编译不过，登记留着，等对象能加载再处理）、`/death/npc/heiwuchang.lpc` 的 `doAgree`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/shengdoushi/7hai/shendian/npc/haihuangnpc.lpc` 的 `do_shoot8`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。3 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 3 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（1 处调用）；`/cmds/std/go.lpc` ← fyzfqyy：`query_chinese_dir()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（inquiry 4）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/bwbj/npc/hsg.lpc`:`say_position`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/death/npc/heiwuchang.lpc`:`askLeave`、`/death/npc/yanluowang.lpc`:`ask_cancel`。
