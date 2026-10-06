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

`u/lying/feizei/feizei`（预载）和 `u/lying/tonggang/feizei/feizei` 给飞贼带的装备写成 `/u/tianlin/feizei/obj/…`，本库没有这个目录，装备在各自的 `obj/` 下。`carry_object()` 出错时 `choose_feizei()` 在重新 `call_out` 之前中断，飞贼事件第一次就停止。路径改成各自所在目录（与 sjcs 同一处代码）。
