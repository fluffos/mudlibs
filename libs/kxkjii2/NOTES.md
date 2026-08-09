
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II/Annihilator 衍生的 mudlib（狂想空间II，"Wild Imagination Space II"），和 jyqxc 家族是不同的血统（存档用驱动原生的明文格式，不是那种旧式二进制编码）。修复了两个 bug：（1）358 个档案用了 AGENTS.md §6.1 类的尖括号绝对路径 #include（例如 #include </open/open.h>），这个驱动会把它解析成相对于配置好的 include 目录而不是 mudlib 根目录——因为分散得太多，不适合逐一手改，改用了文档记载的批量解法：在 master.lpc 里加一个 include_file(compiled, from, path) apply，给看起来是绝对路径的 <> include 前面多加一个"/"，逼它走和带引号 include 相同的、基于 merge() 的路径解析。（2）adm/daemons/natured.lpc 的 check_heart_beat() 里有一个多余的分号提前终止了一个 if 条件（if (wizardp(...) && ...);），导致后面那句原本应该被这个 if 保护的、对不存在的精灵 /adm/daemons/temp.lpc 的 call_other() 变成每次心跳（每秒，永远）都会无条件执行——确认过这个档案在整个代码库里从来不存在（一个被剪掉的开发/调试用暂存精灵，两处呼叫点从没清理干净）；已直接移除这两处死呼叫点，而不是凭空捏造一个替代精灵。注册流程用的是一套特别的互动式点数分配（7 项明确询问的属性、从共享的 160 点数池里分配，第 8 项由剩余点数自动填入），不是 jyqxc 家族那种"自动生成后接受"的模式。这里的管理员等级惯例是 (manager)，比 (admin) 高一级——已把 fluffos 播种为 (manager)，匹配既有的两个条目。完整的注册→look→score→quit 流程和管理员流程在排版格式化前后都验证过；格式化工具还原了 6 个真正损坏的档案（中文字符密集的字符串字面量里出现了错误的"\ n"分词——这是一种 jyqxc 家族里没见过的新损坏形态，和那个家族的 ASCII 地图压缩模式不同）。有几个 diff 特别大的档案（删掉了几千行）经确认是格式化工具正确地清理掉了几千行原本就存在的尾随空行，不是损坏。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 14 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统确认：与 `kxkj` 同一份代码，非"改编"关系

`kxkjii2`（本档案，089 号）与 `kxkj`（036 号，本 session 早前已完成
§10.7 深度测试，结论"deep functional test，no programming bugs
found"）的 `adm/obj/master.lpc` 主体、`adm/daemons/securityd.lpc`
逐字节完全相同（`diff` 输出为空，除去两边各自独立打的 WASM 阶段
`#include`/`compile_error` 补丁）；`work/` 目录树结构、`open/death/`
整个死亡区（`start.lpc`、`bridge1-3.lpc`、`gate.lpc`、`gateway.lpc`、
`road1-3.lpc` 等）逐文件字节完全相同；档案总数仅差 10 个文件（均为
运行期存档差异，非源码）。结论：**这不是"狂想空间"改编或衍生的
"II"续作，而是同一份 2002 年台湾巫师 wade 发布源码的另一份独立快照/
存档**，与本档案自己 README 已有的"和 dfgsiiv13b 的雪村同名但内容不
同——应是各自独立搭建"判断相印证（雪村内容确实独立，但引擎/核心代码
是同一份）。这次比对方式：直接 `diff` 两份 `work/` 下的核心精灵文
件与整个 `open/death/` 目录，而非仅凭档案名或简介推测。

### 管理员账号：README 记录与实际存档不符，已重新播种

README 此前记录的 `fluffos`/`Mud2026Adm`/(manager) 虽然 `adm/etc/
wizlist` 里确实有一行 `fluffos (manager)`，但 `work/data/{login,
user}/f/` 下翻遍都没有对应的 `fluffos.o` 存档——说明上一轮只写了权
限名单，从未真正走过注册流程创建账号。本次用标准 `fluffos`/
`Mud@2026` 组合重新走了一遍正常注册流程（英文 id → y 确认 → 中文名
"浮浮" → 密码×2 → 邮箱 → 性别 → 7 项天赋各分配 20 点，第 8 项福缘
自动补满）,`目前权限 -> 【天帝】(manager)` 立即生效。**额外发现并
确认的存档时机细节**：本档案的 `LOGIN` 对象（含密码的账号存档）既
不在 `quit` 指令路径写盘，也不在注册完成时写盘，只有真正的 socket
断线（`net_dead()`）才会写——这点与 `kxkj` 已有 NOTES 记录的现象一
致。第一次用 `kill <driver pid>` 结束驱动进程时验证到这一点：重启
后 `data/login/f/` 目录为空，`fluffos` 账号"凭空消失"，被迫重新注
册；第二次改用正常 telnet 断线（结束 tmux 会话，触发真实 TCP
FIN/RST）后确认 `data/login/f/fluffos.o` 正确落盘，且用标准密码
`Mud@2026` 成功重新连线（"重新连线完毕。"），(manager) 权限保留。
密码沿用项目标准 `Mud@2026`，未被拒绝，无需变体密码。

### 核心发现并已修复：死亡后唯一的"复活"出口是死代码，此前每一次死亡都是无法恢复的死局

用 (manager) 账号在 `d/snow/eroad2`（雪村，与 `kxkj` 完全同一房间）
对 `野狗`（非会说话生物，走真杀分支）使用 `fight dog`，走完完整的
真实死亡流程（"你死了" → 送往 `阴曹入口`），`debug.log` 全程干净，
无任何报错——死亡本身完全正常，问题出在复活出口。

`open/death/start.lpc`（`阴曹入口`）的 `exits` 映射只有 `"north"`
一个活 key，`"up"`/`"south"` 两行被注释掉；但同一文件的
`valid_leave()` 紧接着就有这两个方向完整可用的逻辑（`"south"` 是
"你真的想回家吗"的 5-9 次随机重试门槛，`"up"` 才是真正的复活：
`reincarnate()` + `move()` 回到人间，打印"恭禧你又重回人世了"）。
本档案共用的 `cmds/std/go.lpc` 在呼叫 `valid_leave()` 之前先检查方
向是否是 `exits` 映射里的一个 key（`undefinedp(exit[arg])` 直接
`return 0`），所以 `"south"`/`"up"` 这两条分支从来没有被真正执行
过——玩家打 `south`/`up` 得到的是"什么? south? 请用 help cmds 查询
指令。"，和真正不存在的指令一模一样。已在 `open/death/start.lpc`
里把这两行注释还原（详见 AGENTS.md §7.101，新增条目）。已在
`kxkj` 上核对同一档案，确认逐字节相同、同样命中此 bug、本次未修
（留给下次触碰 `kxkj` 时同步）。

现场验证（修复前 → 修复后对照）：
1. 修复前：`阴曹入口` 处 `look` 只列出 `north` 一个出口；打
   `south`/`up`/`stand` 全部得到"什么? xxx? 请用 help cmds 查询
   指令。"。沿仅有的 `north` 出口一路走到底（`bridge1→bridge2→
   bridge3→鬼门关→酆都城门→鬼门大道`），发现这整条支线本身也是
   未完成内容：`open/death/road3.lpc` 的房间描述原文是"路的尽头
   ..... 还没想到 ...."（原作者自己留下的占位文字），且
   `open/death/gate.lpc` 一旦向北经过就永久拒绝向南返回（"进了鬼
   门关就别想回去了！"）——这条支线一旦被误闯，除了管理员
   `goto`/`transfer` 或 `suicide -n`/`-f`（自毁角色）之外没有任何
   出路。鉴于这条支线是原作者明显未完成的探索型旁支内容（非死亡
   恢复的必经之路），本次判定为超出"程序 bug"修复范围的既有设计
   /未完成内容，只记录不改动。
2. 用 `update /open/death/start` 热重载后，`look` 显示三个出口
   `up`、`north`、`south`；连续 `south` 6 次后出现"你真的那么想回
   家吗？ 好吧！！就如你所愿"门槛消息；`up` 立即触发完整复活：
   "突然天中降下一团祥光，令人无法用肉眼直视。过了一会儿，祥光散
   去，一道人影出现，你终于从阴间偷跑回来了。"，落地新手入门房，
   `score` 确认属性/气血/食物饮水全部正常。重启驱动（完整冷启动而
   非仅 `update`）后二次复验，行为一致。

**与 §7.68/§7.76 的区别（明确排除，非同一形状）**：本档案确实也有
经典的 `wgargoyle.lpc`/`bgargoyle.lpc`（白无常/黑无常）
`present(ob)` 门控 `call_out("death_stage", ...)` 五阶段对话链（位
于 `鬼门关`/`酆都城门`），且 `wgargoyle.lpc` 的 `init()` 正确地对
`wizardp(previous_object())` 做了排除（管理员角色路过不会触发这条
链，符合本项目已确认的既有惯例，未见异常）。但本条修复的根因与这
条对话链完全无关——是 `阴曹入口`（死亡后第一站）的移动指令被共用
派工器在方向未列入 `exits` 前直接拒绝，`valid_leave()` 根本没有机
会执行，不是 `present()` 检查落空或链条被中断。

### 已知 bug 类别逐项核对（除上述新发现外）

- **§7.86（留言板 `post` 崩溃）**：不适用，本档案在更早的 WASM 阶
  段已扫描修复过全部 14 处（见上一节）。本次现场复测 `post test
  post`（中央驿站"酸甜苦辣留言版"），`.` 结束后"留言完毕。"，
  `look board` 能看到新留言，无崩溃。
- **§7.11（`log_file()`/`write_file()` 缺 `assure_file()`）**：未观
  察到；死亡记录 `open/death/death_record`、`data/board/` 等写入路
  径均正常落盘，无 "No such file or directory" 类报错。
- **§7.5（自定义 securd/securityd ACL 拒绝编译期探测）**：不适
  用——`securityd.lpc` 与 `kxkj` 逐字节相同，那边已确认无此问题，
  本档案全程游玩（含死亡/复活/贴板）也未见任何 ACL 拒绝痕迹。
- **§7.73（NPC `create()` 里无防御的 `carry_object()->wear()` 链）**：
  未触发；新手房 `quest_girl.lpc`、雪村区多个 NPC 正常加载，无因
  装备链失败而中断房间 `create()` 的现象。
- **§7.98（daemon `create()` 忘记 `seteuid()`）**：未观察到；boot
  日志除既有的编译期警告外无 `explode()`/`sscanf()` 崩溃形状。
- **§7.34（printf 调试信息泄漏）**：未发现残留 `printf("%O...` 或
  裸 `tell_object` 调试断点。
- **§8.13（wizlist 二次登录死锁）**：不适用——本档案权限存于
  `adm/etc/wizlist` 纯文本，不是需要单独 WIZ 密码二次验证的机制；
  多次重连、`(manager)` 显示均正常。
- **§8.14（IP 封禁误用反解主机名）**：`goto`/`transfer` 等管理员
  路径正常，未见连线即被拒的现象；本轮均用 `127.0.0.1` 连线，未见
  反解相关报错。
- **§8.15（大小写不匹配档名运行期崩溃）**：全程游玩未触发；
  本档案是本 session 已知会命中 §8.15 一类模式的 ES2 家族之一，但
  本次实际路线（新手房→中央驿站→雪村→死亡区）未踩中任何一处。
- **§7.90（评估成本上限过低）**：`config.fluffos` 沿用家族常见默
  认值 `700000`（`kxkj` 自己是 `1500000`），本次游玩全程（含移动、
  战斗、复活）未观察到任何 eval-cost abort 或"bug found, report
  it"提示；暂不判定为需要调高，留待后续更大范围游玩时复查。

### 额外顺手修复：master.lpc 把编译警告当错误广播给玩家（对齐 `kxkj` 已有修法）

`kxkj`（同代码血统）的 `master.lpc` 早前已经把 `log_error()` 里的
`efun::write("编译时段错误：" + message)` 改成只在 `message` 不含
`"warning:"` 时才广播；`kxkjii2` 这份存档没有这个过滤，导致注册/
装备/进房间等任何触发懒编译的操作都会把内部档名、行号、"Unused
local variable"级别的无害警告原样刷给正在连线的普通玩家。已在
`kxkjii2` 自己的 `master.lpc` 里补上同样的过滤（保留写日志，只是不
再广播警告级别的消息）。现场验证：重启驱动后重新注册一次
`fluffos`，整个注册流程不再出现任何"编译时段错误："前缀的警告刷
屏，功能行为不变（真正的编译错误仍会照常广播，未测试到真错误场
景，逻辑与 `kxkj` 完全对齐）。

### 测试覆盖小结

注册（含账号丢失重建、密码变更核实）→ `look`/`score` → `enter` 正
式进世界 → 移动（新手房→狂想空间入口处→中央驿站→雪村黄土小径，管
理员 `goto` 快速定位）→ 留言板 `post`/`look board` → 战斗
（`fight dog`，真实杀伤分支）→ 完整死亡 → 复活出口 bug 定位与修复
→ 修复后完整复活链路复验（含冷启动后二次复验）→ 清理测试残留
（`death_record` 测试行、`data/board/start_b.o` 测试留言、
`data/clan.o` 的例行序列化 mtime 变动均已用 `git checkout` 还原，
不纳入本次提交）→ 正常 telnet 断线以确保账号存档落盘。
