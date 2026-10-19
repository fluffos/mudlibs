# tianlongbabu（天龙八部）-- porting notes

`天龙八部.tgz`（编号 907）实际是 ZIP（`PK\x03\x04`），不是 gzip。内容是 2000-01 的 TLBB 残档：`DAEMONS/` `FEATURE/` `OBJ/` `INCLUDE/` 加上开封/洛阳/聚贤庄等地域，**没有** `master.c` / `simul_efun.c` 源码（只有 `BINARIES/ADM/OBJ/MASTER.B` 与 `simul_efun.b`），也没有 `cmds/`、`std/`、`/t/tutor`。FluffOS 不能加载 MudOS BINARIES。

按用户指示把残档接到已转换的 `es2` 骨架上：

1. `rsync` `libs/es2/work/` → `libs/tianlongbabu/work/`（带上 `/adm/obj/master`、`simul_efun`、`cmds/`、`std/`）。
2. DOS 大写树小写后叠上去：`DAEMONS`→`/adm/daemons`，`FEATURE`→`/feature`，`OBJ`→`/obj`，地域→`/t/<area>`。`convert_lib.sh` 只认小写 `.c`，大写 `.C` 先被当成 `.c` 再改成 `.lpc`（752 个），并补了 `.c"` 引用。
3. `LOGIN.H` 要的 `/t/tutor/start` 原先不存在，写了一间临时驿站，东门接到 `/t/kaifeng/temple`。

`LOGIN.H` 的 `START_ROOM`/`DEATH_ROOM`/`REVIVE_ROOM` 叠到
`work/include/login.h`。es2 的 `globals.h` 补了 TLBB 要的 `MAPDATA`、
`REGISTER_D`、`TOPTEN_D`，否则 overlay 上来的 `securityd.lpc` 编不过。

端口 **40320**（原 40269；§10.7 改到空闲段）。这是骨架嫁接，不是完整原站。已有 es2 管理员
`fluffos`/`Mud@2026` 可登录；`goto /t/tutor/start` 再 `east` 进开封
城隍庙（`/t/kaifeng/temple`，庙祝在场）。旧号落地仍是 es2 的
`/d/snow/inn`（存档位置），新号走 TLBB 起点。

## 商店 + 拜师（2026-09-04 librarian shop slice）

新角度：开封龙门客栈付费购买 + 洛阳易大彪拜师。进口笔记只写了
骨架落地，没有 `buy` / 拜师实测。`can_afford()` 和 `log_error()`
警告闸已经随 es2 骨架带过来。本机 `debug.log` 不打开（`log
directory : /log` 绝对路径，`/log` 不存在）。

### 修了三处真编程 bug

1. **易大彪编不过：`give_quest` 未定义。**
   `/t/ly/npc/master/master_yi.lpc` 的 inquiry 写 `(: give_quest :)`，
   残档没带这个函数。FluffOS 报 `Undefined variable 'give_quest'` /
   `Illegal to use local variable in a functional`，`square` 的
   `make_inventory` 吃掉错误，房间里没有师父。补了 `void give_quest()`
   桩（回「眼下帮里没有适合你的差事」）。

2. **丐帮技能文件不存在。** `set_skill("beggar-force")` 等走
   `SKILL_D` → `/daemon/skill/<name>`，残档没带这些文件，
   `F_SKILL: No such skill` 在 `square` 刷乞丐时再炸一次。补了
   `beggar-force` / `beggar-strike` / `beggar-steps` / `morality`
   四个最小 `inherit SKILL` 桩。

3. **`square` 的 init 把乞丐 `move()` 到不存在的地域。**
   `total_exits` 12 个目标里只有 `/t/kaifeng/center` 和
   `/t/ly/eastgate` 真的在树上。`易大彪` 第一次 `move` 进房间会触发
   `init()`，随机抽到 `/t/yunzhou/dajie4` 就
   `call_other() couldn't find object`，连玩家自己的 `goto` 也中止。
   已按 `file_size` 跳过缺档目标，`move` 再包 `catch`。

### 实测过程

管理员 `fluffos` / `Mud@2026`（旧号 秦风，普通百姓）。第一输入是
「您的英文名字」。落地饮风客栈 `/d/snow/inn`。`goto /t/kaifeng/inn`
龙门客栈，伙计 id `waiter`。`list` 包子十五文 / 鸡腿三十文 / 老酒
二十文 / 月饼一两银子 / 天龙八部排行榜一两黄金。`vendor_goods` 键是
中文（手足 es2 同形）。`clone /obj/money/coin` +
`call coin->set_amount(100)` 后 `buy 鸡腿 from waiter`：「你向伙计
买下一根烤鸡腿。」`i` 烤鸡腿 + 七十文（100−30）+ 原有一两黄金。
烤鸡腿是食物，quit 后不进档；七十文还在。

`goto /t/ly/square`，易大彪在场。es2 骨架拜师动词是 `apprentice`
不是 `bai`。`apprentice yi dabiao`：「我便收你为弟子」→「恭喜您
成为丐帮的第十六代弟子」。`score` 职称「丐帮一袋弟子 秦风」、
「你的师父是易大彪」。`save` / 退出 / 再登：门派和七十文都在。

管理员存档未提交。

## WASM (2026-09-11 leftover 652)

`wasm_client.js`：`fluffos` / `Mud@2026` → 饮风客栈 `/d/snow/inn`
（es2 旧号落地，不是 TLBB `/t/tutor/start`），`look` 同文，`score`
「普通百姓 秦风」，`quit`「欢迎下次再来」。preload 里 `ftpd` 因
WASM 无 sockets 编不过，被 master `catch` 跳过，不挡登录。
`wasm_status` 改为 `playable`。

## 深度功能测试（§10.7，2026-09-13）

原生 driver 端口 **40320**（原笔记 40269；本轮改到 §10.7 惯用
40320–40380 空闲段），`fluffos` / `Mud@2026`。从 slug 目录启动：
`~/src/fluffos/build-debug/src/driver config.fluffos`，stdout →
`/tmp/tlbb-driver.out`。slug `libs/tianlongbabu/log/debug.log`（`log
directory : /log` 相对启动 cwd）与 mudlib `work/log/log`
（`master->log_error()`）都按本轮 mtime 查了。

这是 **es2 骨架 + TLBB 残档叠层**，不是完整原站：缺档地域
（如 `/t/yunzhou/...`）仍不存在，不虚构房间。

### 游玩证据

- **新号** `qinlongce` / `Play2026x`（中文名秦龙测）：落地
  `天龙八部起点`（临时驿站，出口 east）；`east` →
  `/t/kaifeng/temple` 城隍庙，庙祝在场。
- **旧号** `fluffos`：仍落 es2 `/d/snow/inn` 饮风客栈（存档位置）；
  `goto /t/tutor/start` → `east` 同文城隍庙。
- 商店：`goto /t/kaifeng/inn` 龙门客栈，伙计 `list` 出鸡腿等；
  `clone /obj/money/coin` + `set_amount(100)` 后
  `buy 鸡腿 from waiter` →「你向伙计买下一根烤鸡腿。」
- 拜师：`goto /t/ly/square`，`apprentice yi dabiao` →「我便收你为
  弟子」/「恭喜您成为丐帮的第十六代弟子」；`score`
  「丐帮一袋弟子 秦风」。`ask … about quest` → 桩回复
  「眼下帮里没有适合你的差事」（残档无真任务）。
- 战斗：洛阳木人 `/t/ly/obj/muren` 是练刀 **ITEM**（`hack`），不是
  可 `fight` 的 NPC。巫师 `clone /obj/npc/zombie` 进饮风客栈后
  `fight zombie` 互出拳脚，僵尸倒地化血；`surrender` 在战后无目标
  时提示「现在没有人在打你」。
- `save` / `quit`「欢迎下次再来」；重连后门派仍在。烤鸡腿为食物，
  不随档（手足 es2 常见）。

### 日志

本轮 boot + 游玩：slug `debug.log` **无** `执行时段错误` /
`Bad argument` / `Too long evaluation`。`work/log/log` 本轮增量主要是
冷编译 `warning:`（unused-variable、Unknown escape/`#pragma`），无同形
功能缺口。

### 未改 / 剩余缺口

- 管理员与测试号运行时存档未提交。
- 嫁接上限：TLBB 地域不完整；易大彪 `give_quest` 仍是桩；无原生
  可练战斗木人 NPC（只有练刀木人道具）。
- 端口配置已改为 40320（本轮空闲优先），未改回 40269。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`std/weapon/throwing.lpc`、`std/weapon/fork.lpc`、`std/weapon/whip.lpc`、`std/weapon/sword.lpc`、`std/weapon/axe.lpc`、`std/weapon/blade.lpc`、等共 8 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py tianlongbabu --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 181 个 `.lpc` 和 1 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：176 -> 176 通过，无回退。手改 `include/net/ftpdsupp.h`：`check_access()` 的局部 `file` 只在 `#ifdef GUEST_WIZARD_FTP` 分支里用到，声明挪进同一个 `#ifdef`（其包含者 2 个，1 -> 1 通过）。启动时警告 21 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 1 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 1 个文件，HEAD 与工作树各载入一次无回退（1 objects; HEAD PASS 1, tree PASS 1; regress 0; newly loading 0），这些文件的警告 1 -> 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

能编译的文件里的警告 4 -> 0（`lpc_warnings.py tianlongbabu` 重扫：2731 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。这几处与 es2 同码，es2 当天的修复（提交 6e744ac9d59）改的 5 个文件在这里都是 token 级孪生，用 `lpc_twin_port.py adopt` 搬过来：`d/city/npc/walker.lpc` 的 inquiry、`d/city/shangshu/kefang.lpc`、`d/city/street3.lpc`、`daemon/class/scholar/taolin.lpc` 的 item_desc 原写成 `(: "一段文字" :)`，`query()`/`look` 求值后就是那段文字，改成直接写字符串，行为不变；`adm/daemons/network/mail_serv.lpc` 的 `tmp[i] == EOT+".";` 改为赋值（该文件本来就编译不过，顺手改）。

验证：5 个改动对象 HEAD 与工作树各用新进程载入：4 -> 4 通过，regress 0；删除声明审计 0 项待看。5 个对象载入无回退。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/t/dali/npc/cloth/color-dress`、`/t/dali/npc/cloth/boots`、`/t/yipin/npc/obj/kcloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`include/net/ftpdsupp.h`。
