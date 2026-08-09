
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
