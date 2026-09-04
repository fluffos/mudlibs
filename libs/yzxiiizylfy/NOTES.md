
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现III之炎龙封印（阿凯工作室，AKAI Studio，2006）。和本次会话其它夕阳再现家族档案一样使用同样的 Tomud '2060' 客户端版本握手（get_id() 会拒绝除字面字符串 '2060' 之外的任何第一次输入，提示'not a Tomud client'，然后才继续到 get_id1() 真正的英文 id 提示）。WASM 修复了：（1）标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经是正确的逐码点写法）——改成了逐码点的 name[i..i]，界限从 2/10 减半为 1/5。（2）master.lpc 的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 短路判断——两处都已加上，和这份档案自己原有的（不同寻常、局部的）基于 previous_object() 的保护并存，保留不动。tell_room() 的 exclude 参数和 securityd.lpc 的 save_object() 扩展名检查在这份档案里本来就是正确的，不需要修。存在两份 dns_master.lpc 副本（adm/daemons/dns_master.lpc 和 adm/daemons/network/dns_master.lpc）；DNS_MASTER 宏只引用了 network/ 那一份（adm/daemons/dns_master.lpc 是死代码，没有任何宏或字面路径引用它），而真正生效的那份在 adm/etc/preload 里被注释掉，只有带 find_object() 保护的巫师指令呼叫者——两份都保持原样，不需要 §7.52 掏空处理。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在格式化前后都完整验证过（2060 客户端版本握手→英文 id→y 确认→中文名字→密码+确认→天赋菜单（'0' 随机→'y' 接受）→电子邮件→性别→进入铁枪庙），管理员权限已通过'★ 您目前权限：(admin)'确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的错误，33 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。一处 CJK 重新加空格/转义损坏命中（d/city/sj.lpc，一个转档之前就存在、本次会话改动之前就有的不配对引号打字错误，导致格式化工具的分词器失步）——已按 AGENTS.md §9 记载的第 3 个盲点还原，底层的打字错误保持原样，没有进一步深挖。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。连线握手
（"2060"）沿用同一"夕阳再现/炎龙封印"家族的机制，单一密码流程
（没有独立的管理密码步骤）。

### 发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。
2. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
3. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
4. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。
5. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。

### Proactive checks（无需改动）

- `get_id()`/`get_id1()` 签名是 `(string arg, object ob, int
  ip_cnt)`，全档案五处 `input_to("get_id", ...)` 调用点参数个数都
  一致，未发现 yxjh 那种参数错位。
- `feature/dbase.lpc` 未发现密码写保护，不适用 tybxjh/wlhd 那一类
  bug。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/refereew.lpc`/`referee.lpc` 未用到 `%`，不适
  用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含"2060"握手）创建，落地一处描述为"灰
蒙蒙一片，什么也没有"的房间（内容层面的空房间，非崩溃），`score`
显示"【天界总管】"头衔，食物/饮水满格。随后**连续两次**真实断线重
连+密码验证（每次都重新发送"2060"握手）：均成功登录，存档数据一
致，两次重连均未触发任何异常（未复现 yxjh 那类仅在连续快速重连时
才出现的错位崩溃）。全程 `debug.log` 无运行时错误。驱动按精确 PID
结束；管理员存档已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,070 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
用 `fix_710_room.py` 扫过 `work/`，删除 2,068 处标准形状；两份房间
建造工具（`clone/misc/roommaker.lpc`、`d/huanggon/obj/roommaker.lpc`
——本档案是这个双 roommaker 副本血统的另一个成员）各剩 1 处字符
串拼接变体 `str += "...replace_program(ROOM);..."`，手工改成
`str += "\n\tsetup();\n}\n";`。修复后 `work/` 下 0 处存活残留，其
余均为转档之前已注释掉的 `//` 行，原样保留；`work/data/` 下没有真
实 `.lpc` 源码命中。`git diff --stat` 显示 2068 个文件净删 2070
行、增 2 行，与脚本自报数字 + 2 处手工编辑吻合。

驱动干净启动（零新增编译错误、端口 40178 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`Mud@2026`（'2060' Tomud 客户端握手）实机登录成功，`look`/
`score`/`quit` 均正常，权限显示 (admin)，全程 `debug.log` 保持干
净。管理员存档的时间戳漂移已用 `git checkout HEAD --` 还原，未提
交。驱动按精确 PID 结束。

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

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。第一行仍发 `2060`（Tomud 握手）；
单密码 `fluffos`/`Mud@2026`，无巫师效验码。

### 实测过程

落地铁枪庙（`/d/quanzhou/tieqiang`）。`goto /d/city/zuixianlou`，
`list` 为铜钱尺度（烤鸡腿八十文钱）。**先买后拜**：`clone
/clone/money/gold` 后 `buy jitui` 成功（找零九十九两银子 + 二十个
铜板）。本血统 `feature/dealer.lpc` 在拜师后会拒绝全部丐帮（「你是
个穷叫化，买什麽东西！」），和 `xyzxiiylzymh` 相同。`goto
/d/gaibang/inhole`，`apprentice zuo` 一次成功，`score` 称谓「丐帮
第二十代弟子」、师傅左全。`save`/`quit` 干净（巫师，没有 zxty 那种
30 分钟删档）。

`quit_time` 50 秒冷却（`logind.lpc`，非 120 秒 `last_on`）。等满后
重连仍先发 `2060`：落地武庙，`score` 门派仍在，银子还在；烤鸡腿不
存档。全程驱动 `log/debug.log` 无运行时错误；mudlib
`error_handler` 写的 `work/log/debug.log` 仍是 2026-08-13 的旧档，
本轮没有新执行时段错误。无新编程 bug。
