
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib（金庸群侠传），jyqxc 的手足代码库（86/87 编号；不是文件级完全相同的重复——大部分档案不同，但共享同一套架构/bug 面）。和 jyqxc 完全相同的 bug：feature/name.lpc 的 short() 呼叫 capitalize(query("id")) 没做保护，任何没有"id"属性的物件走到 short() 就会崩溃——这份档案里约 18 个留言板分身都会撞上，因为它们的 data/board/*.o 存档用的是同样这个驱动的 restore_object() 解析不了的旧式紧凑二进制编码（魔术字节"#inh"/"?inh"），抛出异常之前会先清空物件的 dbase 映射（包括"id"）。修法完全相同：让 short() 的兜底逻辑用 stringp(id) 判断。通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断，commandd.lpc 的 sscanf 本来就匹配 .lpc）。完整的注册→look→score→quit 流程和管理员流程在排版格式化前后都验证过。格式化工具还原了 3 个损坏的 ASCII 地图档案（d/huashan/map.lpc、d/shaolin/obj/map.lpc、d/shaolin/npc/obj/map.lpc），和 jyqxc 逐字节相同的损坏模式。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 18 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-05）

### 血统确认：与 `jyqxc` 实质上是同一份代码，不是"架构相同、内容各异"的姊妹档

本档案自己的 README/meta.json 此前的描述（"和 jyqxc 是同一套架构衍生
的姊妹版本……大部分具体文件内容不同——不是简单的重复压缩包"）**是错
误的，本次用 `diff -rq` 直接逐文件核对后推翻**：`jyqxc`（086 号，
archive `金庸群侠传 (1).rar`）与 `jyqxc2`（087 号，archive `金庸群侠
传.rar`）的 `work/` 目录树（各约 3690 个文件）用 `diff -rq` 比对，
只有 3 处差异——`adm/daemons/logind.lpc`（见下）、`log/log`、
`log/USAGE`（纯运行期日志文件，非源码），外加各自遗留的一个测试角色
存档（`jyqxc` 侧的 `qindongxi.o`）。连 `raw/jy`（未转换的原始压缩包
内容）都近乎一致，只多了 `jyqxc2` 那份多出的一个 `svr.exe`（Windows
版驱动可执行档，与 mudlib 源码无关）。`adm/single/master.lpc`、
`adm/daemons/securityd.lpc` 逐字节完全相同（`diff` 输出为空）。归档
文件名 `金庸群侠传.rar` / `金庸群侠传 (1).rar` 的 `(1)` 后缀是典型的
浏览器重复下载命名模式——这两份archive 极可能就是同一次下载的两份
拷贝，只是没有被本项目原有的去重流程识别出来（去重大概率是按压缩包
本身的字节比对，而不是解压后内容比对，两份 `.rar` 容器本身不是逐字
节相同的）。已在 AGENTS.md §11 补充说明这第 15 个"漏网的 `(1)` 重复
下载"实例。结论：**这不是同一引擎的独立衍生档，而是同一份原始数据
的另一份几乎完整的快照**——`jyqxc`那一轮（本 session 更早完成）留
下的 bug 修复没有回灌到这一份，`jyqxc2` 的 `logind.lpc` 携带的正是
`jyqxc` 自己修复前的原始内容。

### 管理员账号：README 记录与实际存档不符，已重新播种

README 此前记录的 `fluffos`/`Mud2026Adm`/(admin)，`adm/etc/wizlist`
确实已有一行 `fluffos (admin)`，但 `work/data/login/f/` 和
`work/data/user/f/` 下都没有对应的 `fluffos.o` 存档——上一轮只写了
权限名单，从未真正走过注册流程创建账号（这是本 session 反复遇到的同
一类"README 记录与实际存档不符"陷阱，已是第三次遇到）。本次用标准
`fluffos`/`Mud@2026` 走了一遍完整正常注册流程（英文 id → y 确认 →
中文名"风清扬" → 密码×2 → 系统随机天赋展示 → y 接受 → 邮箱 → 性别
m），`目前权限：(admin)` 立即生效；`update /d/city/kedian` 验证了写
ACL（成功触发重新编译，副作用是顺带复现了下面记录的旧式留言板存档
读取异常，被 `update` 自身的 `CATCH()` 干净拦截，未影响权限验证结
论）。**已知问题**：中文名字用 `scripts/tmux_mud.sh`（走本地
`telnet` 二进制）发送时，"清"字的字节被转发损坏，实际存下的名字显示
为"风�扬"——这正是 AGENTS.md §10.2 记录过的本地 telnet CJK 字节转发
损坏，不是 `is_chinese()` 或注册逻辑的 bug，纯粹是这次测试工具选择
的副作用，不影响本次验证的实质结论（admin 权限已确认生效），未重新
注册。

### 修复：§8.9 食物/饮水初始化用错对象（第十例）+ §7.34 调试残留 printf

`adm/daemons/logind.lpc` 的 `enter_world()` 一次性携带了两个已知
bug 类的实例，和 `jyqxc` 自己（该 bug 类的第六例，见 AGENTS.md §8.9）
逐字节相同的错误代码：

1. **§8.9**：`if (!user->query("food") && !user->query("water") &&
   ob->query("age") == 14)` 最后一项读的是登录桩物件 `ob` 而不是刚
   `setup()` 过的角色本体 `user`——`ob` 的 `"age"` 属性从未被设置过，
   永远是驱动默认值 `0`，整个门槛永久为假，新角色食物/饮水永远卡在
   0。修法：`ob->query("age")` → `user->query("age")`。
2. **§7.34**：`get_name()` 里紧接着中文名字设定前有一行调试残留
   `printf("%O\n", ob);`，会把登录物件的内部路径（如
   `/clone/user/login#0`）直接印在中文名字提示的正下方。已删除。

**现场验证**：修复前用 `fluffos` 账号注册，`get_name` 后确实在屏幕
上看到裸露的 `/clone/user/login#0`；`score` 显示食物/饮水两栏全空
（□×25）。用 `update /adm/daemons/logind` 热编译（"成功！"）后，
另注册一个非管理员测试角色"黄蓉"（英文 id `testchar`，用于后续死
亡测试的抛弃号），注册过程中不再出现 `/clone/user/login` 字样，
`score` 显示食物/饮水两栏全满（■×25）。测试结束后已删除
`work/data/login/t/testchar.o`、`work/data/user/t/testchar.o` 这两
个我方注册的存档文件，不触碰目录本身或其中任何其他既有文件。

### 死亡/复活系统：§7.101 形状不适用，§7.68 形状经现场验证也不适用（均为有意设计）

用非管理员测试角色"黄蓉"、`set wimpy 0`（关闭自动逃跑）后在北大街
（`/d/city/beidajie1`）主动 `kill` NPC 欧阳克（"白驼山少庄主「玉面
蛇心」"，和 `jyqxc` 自己 §10.7 记录的那位同一个 NPC、同一个坐标）
——欧阳克明显不是给新手陪练用的对手，几回合内就把测试角色打死，与
`jyqxc` 自己的记录一致（内容强度问题，非 bug，未做任何改动）。死亡
后角色被送到"鬼门关"（`/d/death/gate.lpc`），"实习无常"
（`newgargoyle.lpc`）与"白无常"（`wgargoyle.lpc`）同时在场，**全程
未主动断线或制造任何中断**，完整看着两个 NPC 各自的五段对话
`call_out` 链跑完（约 35 秒），`实习无常`先完成，触发
`reincarnate()` + `move(REVIVE_ROOM)`，角色被送到"武庙"，重连后
`score` 确认精/气降到约 40%（10/25 格，符合死亡惩罚），食物/饮水
仍全满。

- **§7.101 形状（exits 缺失 valid_leave 已实现的方向）不适用**：读
  `/d/death/gate.lpc` 源码，`exits` 只有一个 `"north"` 键（指向
  `gateway`），没有 `valid_leave()` 覆写——不存在"exits 缺了一个
  valid_leave 已经写好逻辑的方向"这种情况；死亡区其余两个带
  `valid_leave()` 的房间（`gateway.lpc`、`road2.lpc`）里，
  `valid_leave()` 判断到的每一个方向（`"south"`/`"north"`）都确实是
  `exits` 里的真实键，没有遗漏。现场进入"鬼门关"时 `look` 只列出
  `north` 一个出口，与代码、与房间描述原文"一进鬼门关就无法再回阳间
  了"三者一致——这是有意为之的单向门，玩家不该、也不能靠自己走出去，
  唯一的回程手段就是 NPC 对话链自动触发的 `reincarnate()`。
- **§7.68 形状（present() 守卫误伤"暂时不在场"）也不适用，现场独立
  复核，不套用 `jyqxc` 已撤销的旧结论**：`wgargoyle.lpc`/
  `bgargoyle.lpc`/`newgargoyle.lpc` 三个鬼差档案与 `jyqxc` 逐字节相
  同（`diff -rq` 已确认整个 `d/death/` 目录零差异），`death_stage()`
  用的仍是原始 `if (!ob || !present(ob)) return;` 单次判定，`init()`
  也仍然显式排除 `wizardp(previous_object())`（管理员测试号预期不会
  进入这条流程——本次也确认了这点，`fluffos` 账号从未触发过对话）。
  读遍这三个档案与整个死亡区，**没有发现任何强制把鬼魂从鬼门关移走
  的第二套机制**（不像 `bmxkx2001` 那边有一个不相关的巡游 NPC 会强
  行拖走任意在场角色）；本次现场全程无中断的死亡→复活流程顺利走完，
  与 `jyqxc` 自己此前"独立发现 2 处 §7.68 实例、后又撤销"的最终结论
  一致——这里同样是"鬼魂正常情况下走不动，`present(ob)` 恒真，缺席即
  等于真的走了"的有意设计，不套用旧修复。

### 留言板：post/read/discard 全流程验证通过

在客店（`/d/city/kedian`）对 `kedian_b` 留言板执行了完整的
post（内建列编辑器，`.`结束）→ read 1 → discard 1 流程，全程无崩
溃、无残留。`update /d/city/kedian` 强制重新编译该房间时，触发了
`kedian_b` 存档的 `restore_object(): Illegal file format - 1 (?inh
...)` 运行期错误（旧式紧凑二进制存档，本驱动无法解析）——这正是
README 已记录的"18 个留言板受影响"的根因再现，但这次被 `update`
自身的 `CATCH()` 干净拦截，物件继续存在（`id` 属性因 restore 失败
而为空），后续 `look`/`post`/`read` 均未受影响——`feature/name.lpc`
的 `stringp(id)` 兜底修复（已在更早一轮完成，见 README）在这个新
触发路径下同样有效，未发现需要补丁的新变体。

### 其余检查

- `mailbox`：`look mailbox` 正常列出 `mail`/`forward`/`from`/
  `read`/`discard` 指令说明。
- `command_hook`：`private command_hook` 跨库扫描（AGENTS.md §8.3a）
  在更早一轮（2026-08-03 的 30 库批量修复）已把 `jyqxc2` 列入修复
  目标之一，本次未见回归。
- **§7.100 观察，未现场触发，不做处理**：`grep -c
  "replace_program(ROOM)"` 在本档案 `work/` 下命中 845 处（41 处已
  注释，804 处存活），是 AGENTS.md §7.100（`jhfy3` 记录的"ROOM 基类
  自我 replace_program()" 形状）在一个不相关血统家族里的又一次独立
  命中。本次注册→移动→战斗→死亡→复活→留言板→邮箱的完整会话里
  `debug.log` 没有出现任何一行"cannot replace a program"，说明没有
  被现场触发（本次路径没有踩中任何在 `create()` 之后才绑定闭包到房
  间自身的操作）。按 §7.100 自己记录的既定 scope 决定（804 处属于
  "留给专门扫描 session"的量级，不适合塞进单 lib 的 §10.7 pass 里顺
  手改），本次不做修复，仅在 AGENTS.md §7.100 补充记录本档案也带有
  这个形状。
- `debug.log` 全程没有真实的 `error:`/`denied`/`Bad argument`/
  `Too deep recursion` 行（唯一一行 `System Error:
  init_addr_server: connect:No such file or directory` 是沙盒环境
  没有外部网络导致，与 mudlib 代码无关，历次测试都会出现）。
- `quit` 两个测试角色（`fluffos`、`testchar`）均正常退出，"当你下次
  连线进来时，会从这里开始。欢迎下次再来！"

修改文件：`adm/daemons/logind.lpc`（本次 §8.9 + §7.34 两处修复）。
新增未跟踪存档：`work/data/login/f/fluffos.o`、
`work/data/user/f/fluffos.o`（管理员种子账号，按 AGENTS.md §1.5 约
定提交）。测试用抛弃角色 `testchar`/黄蓉的存档已删除，未提交。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 803 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与手足档案
`jyqxc`/`jqxz2008` 系列同一血统同一形状。`clone/misc/roommaker.lpc`
同样有两套模板——"造一间空房间"的 heredoc 本来干净，"克隆我所在的
房间"命令的字符串拼接模板把同一枚多余的 `replace_program(ROOM);`
烤进了每一个新克隆的房间，已同步修正。已用 `build-debug` 驱动干
净启动验证（0 个新增编译错误，端口正常监听）；未做完整 §10.7 深
度游玩测试。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-05 第一轮覆盖了注册/食物饮水/死亡复活/留言板，没有
走商店或有机拜师。本轮只补这两条 + quit+reconnect。

- **商店**：`goto /d/city/datiepu`，铁匠铺老板「铁匠」`list` 列出长
  剑/铁锤/屠刀/匕首/铁棍/钢刀；`clone /clone/money/gold` 后
  `buy changjian` 成功（「你从铁匠那里买下了一柄长剑」）。`sell` 回
  「什麼？」——`d/city/npc/smith.lpc` 的 `init()` 只 `add_action`
  了 `list`/`buy`，没有把 `F_DEALER` 的 `do_sell`/`do_value` 挂上。
  同库里挂了 `sell` 的是当铺/收购类 NPC（`d/city/npc/tang`、
  `aqingsao`、`d/city2/npc/jia`、`d/quanzhou/npc/chen`），和
  AGENTS.md §13.4 已记录的「只有当铺接 sell」设计一致，不按 bug 修。
- **拜师**：`goto /d/xingxiu/xxh1`，`bai zhaixing`（摘星子）当场
  「好吧，我就收下你了。」→ 星宿派第三代弟子，师承摘星子。`save` +
  `quit` 后重连 `score` 仍是「星宿派第三代弟子 / 你的师父是摘星子」，
  八十五两白银仍在。长剑未进 `autoload`（普通兵器无 autoload 标记，
  存档只有 `silver:85`），属该血统常规存盘范围，不是丢物品 bug。
- **中文名「风�扬」**：第一轮 NOTES 已定性为当时 telnet CJK 转发损
  坏，不是 `is_chinese()` bug；本轮未改名。
- **日志**：live `debug.log` 为 `libs/jyqxc2/log/debug.log`。无
  `error:` / `Too deep recursion`。`work/log/log` 只有编译警告。
- **结论**：商店购买 / 有机拜师 / 重连均通过，本轮无新编程 bug。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-05）— 巫师留言板存档 `data/board/*.o.gz`

巫师留言板 `wiz_b` / `towiz_b` 以 `.o.gz` 存档（1996 年的帖子）。本机驱动 `restore_object()` 优先读 `.o.gz`，而留言板用 `save_object(file)` 写明文 `.o`，所以本机上新帖每次重启都退回旧快照；网页版驱动没有 zlib，只读 `.o`，而归档自带的 `.o` 是读不出的二进制。`.gz` 内容为 GB18030（转码时没被处理），转成 UTF-8 写成 `.o`，替换归档里那个读不出的二进制 `.o`；`towiz_b` 原文有 4 个残字节，转为替换符。删除 `.o.gz`（KB 01）。用 lpcc 载入留言板核对条数（jqxz2008：wiz_b 47 条、towiz_b 115 条）。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py jyqxc2 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 223 个 `.lpc` 和 8 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：207 -> 207 通过，无回退；改过的头文件的 36 个包含者 34 -> 34 通过。启动时警告 16 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 9 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 9 个文件，HEAD 与工作树各载入一次无回退（9 objects; HEAD PASS 9, tree PASS 9; regress 0; newly loading 0），这些文件的警告 9 -> 0。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

- 与 jyqxc 同码：`lpc_twin_port.py adopt` 移植 37 个文件（35 处多余 inherit、`ftpdconf.h` 的 `#undef`、`hubo.lpc` 的 `clean_up()`）。37 个对象载入无回退，3 个原本失败的现在能载入。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：2 个存档文件（留言板 2 个；`data/board/gaibang_b.o`, `data/board/tiandi_b.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：5 个对象，新增载入 4，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`liumai-shenjian`、`taiji-shengong`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。7 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/tudao`、`/d/city2/obj/obj/diaopi`、`/d/xueshan/npc/obj/senggun`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`cmds/arch/purge.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：4 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 留言板存档损坏时 `setup()` 不再抛错（2026-10-18）

`data/board/*.o` 里有几个是外来的二进制数据（以 `?inh` 开头，`restore_object()` 报 `Illegal file format - 1`）。`inherit/misc/bboard.lpc` 的 `setup()` 里 `restore()` 直接抛，留言板对象（连带创建它的客店房间，比如 `d/city/kedian`）载入失败。改成 `catch(restore());`，留言板以空板启动（`xkx2017` 的同一个文件早就是这样写的）。上面「存档损坏」那一条里说的“`setup()` 已经包住了”并不准确。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（4 个名字，最多的是 `xiake-force`、`xiake-strike`、`xiake-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 0 个通过，其余 1 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/emei/duguangtai` 的 `north`：`huazangzn` → `huazangan`；`/d/emei/jietuopo` 的 `west`：`guanyitang` → `guanyintang`；`/d/emei/jiulaodong` 的 `northeast`：`jiudaoguai4` → `jidaoguai4`；`/d/mingjiao/jmqshulin6` 的 `west`：`jmqjiguan` → `jmqshenmu`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 4 处、3 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/usr/to.lpc`（1 处）、`/cmds/wiz/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 存档里的乱码文件：`restore_object()` 报 `Illegal file format`（2026-10-20，KB 06 §7.316）

存档里有一批数据文件是乱码：开头是 `?adm`、`?inh`、`?clo`、`?obj`（`#/adm/…` 的第一个字节被换成了 `?`），后面是随机字节，没有任何驱动读得了。`adm/daemons/chinesed` 在预载时 `restore()` 读 `data/e2c_dict.o`，首次登录时起始房间的留言板 `/clone/board/kedian_b` 读 `data/board/*_b.o`；`restore_object()` 对不是文本的文件抛 `Illegal file format`，调用处的 `catch()`（KB 06 §7.255）保住了房间和精灵，但本库 master 的 `error_handler()` 把调用栈返回给驱动，每次启动和首次登录都在控制台打印一次或两次 `错误讯息被拦截`。现在共用的 `feature/save.lpc` 的 `restore()` 先读文件第一个字节，不是 `#` 就返回 0（读被 master 拒绝时 `read_bytes()` 返回 0，仍由 `restore_object()` 决定，和以前一样）；留言板和字典从空开始，第一次 `save()` 写出合法文件，乱码文件原样留在树里。实测：启动和登录都没有报错，已保存的角色重新连线照常加载。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 3 个存档共 6 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/shaolin/npc/obj/kat.o`（1 处）、`/d/shaolin/obj/kat.o`（1 处）、`/d/shenlong/obj/lxlx.o`（4 处）（共 3 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/recover.lpc`、`/cmds/arch/blockade.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 1 条注册（1 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/huashan/npc/teller.lpc`:`tell_fortune`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 11 个文件里有 16 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/CALL_PLAYER`、`nosave/PURGE` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"算命": (: tell_fortune :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
