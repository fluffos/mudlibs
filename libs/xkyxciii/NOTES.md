
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客英雄传 II/III（"欢乐天地"，五邑无尽豪情），一个金庸小说/欧洲中世纪/漫画风混搭的世界观设定。WASM 修复了两处经典的 §8.1 GBK 字节区间 is_chinese() bug：adm/daemons/chinesed.lpc 的 is_chinese()（CHINESE_D 委托的真正实现——只检查 str[0] 的原始字节区间，还要求总长度是偶数，在 UTF8 码点索引下永远失败）和 adm/daemons/logind.lpc 自己的 check_legal_name()（i%2 奇偶门槛，加上按字节数算的长度界限 2-12，本意是按用户提示"1 到 6 个中文字"应为 1-6 个字符）。已把 chinesed.lpc 的 is_chinese() 重写成逐码点 0x4e00-0x9fff 区间循环，check_legal_name() 改成通过 CHINESE_D->is_chinese(name[i..i]) 逐字符检查，长度界限修正为 1-6。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST；wiz_levels 顶层是 (admin)）。注册流程在多次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 确认创建→中文名字→密码+确认→性别（m/f）→种族选择（0-5）→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。测试笔记：性别/种族选择正好接在 /std/char.lpc 首次编译的大量负荷之后（加载 feature/damage.lpc、feature/skill.lpc 等），引发了和 xhcii 上记载过的同一类测试工具时序竞争——不论 --idle 设多少，'m' 有时会被当作无法识别的输入吞掉；补发一次重复的 'm'/'0' 能可靠绕过，这是客户端时序上的假象，不是 mudlib 本身的缺陷（一次完全干净的运行在注册流程里没有捕获到任何异常，可以证实这一点）。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 3178 个档案运行（写入 3145 个，12 个报错，21 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选，这份快照里没有 map.lpc 档案。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 4 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——严重 bug：AGENTS.md §7.11 类，新角色永久没有出生房间

第一次对这份档案做完整 §10.7 深度游玩测试，发现并修复一个严重的、
每个新角色都会撞上的 bug——不计其数（这份档案没有任何存活的角色曾
经真正进入过一个房间）。

- **症状**：无论用普通玩家账号还是巫师账号，走完完整注册流程（英
  文id→中文名字→密码→电子邮件→性别→种族）之后，`score` 正常显示
  完整属性面板，但 `look` 只回传 `cmds/std/look.lpc` 自己对
  `environment(me)` 为空时的兜底文字"你的四周灰蒙蒙地一片，什麽也
  没有。"——角色事实上从未被放进任何房间。走 `east`（起始房间自
  己声明的真实出口）也只得到"什麼？"，`goto`（巫师指令）在这个角
  色身上执行时会因为 `environment(me)` 是 0 而在
  `cmds/imm/goto.lpc` 第 11 行的 `file_name(where_me)` 抛出
  "*Bad argument 1 to file_name()"。断线重连、换用全新账号、换用
  巫师账号，症状完全一致，可稳定复现。
- **根因**：`adm/daemons/logind.lpc` 的 `enter_world()`，在
  `cat(MOTD)`/房间选择/`user->move(startroom)` 那一段代码**之前**，
  有一段"经验值/潜能值异常侦测"逻辑——`combat_exp` 和 `exp` 差值
  ≥1000，或 `potential` 和 `pot` 差值 ≥500，就会
  `log_file("nosave/WARNING", ...)`，完全没有 `catch()` 保护。
  这份档案的 `adm/simul_efun/file.lpc` 里 `log_file()` 的实现是
  裸 `write_file(LOG_DIR + file, text)`，同样没有目录存在性检查；
  而这份档案的原始压缩包**从未打包过 `/log/nosave/` 这个目录**。
  结果就是：几乎每一个新创建的角色（`combat_exp`/`exp`、
  `potential`/`pot` 默认值的落差天然就会超过这两个阈值）在
  `enter_world()` 执行到这个日志调用时就会因为
  "Wrong permissions for opening file /log/nosave/WARNING for
  append" 而未捕获地中止整个函式——包括它之后的一切，尤其是
  `user->move(startroom)`。角色从此永久卡在没有环境的状态，
  `score` 等不依赖 `environment()` 的指令仍然正常，制造出"部分功
  能正常，部分彻底失效"的迷惑现象。这正是 AGENTS.md §7.11 已经归
  档的"未打包的运行时目录 + 无保护的 write_file()/log_file()"类，
  但打击面比该条目里记录过的任何一个先例都更广——它不是命中某个
  边角功能，而是命中**每一个新角色的世界入口本身**。
- **修复**：`adm/simul_efun/file.lpc` 里 `log_file()` 补一行
  `assure_file(LOG_DIR + file);`（这份档案自己已经有
  `assure_file()` 这个帮助函式，委托给 `FILE_D->assure_file()`），
  和 AGENTS.md §7.11 里 `xajhxo` 那个实例用的是完全一致的修复手
  法。由于 `assure_file()` 在同一个档案里的文字位置**晚于**
  `log_file()`，这个编译器不会自动解析后向引用（和 §7.11 `xajhxo`
  条目记录的现象完全一样）——额外加了一行前向声明
  `void assure_file(string file);`，否则编译报
  "Undefined function assure_file" 并直接打断整个
  `simul_efun` 的载入（连驱动开机都会失败，`lpcc_check.sh` 全档
  案批量编译检查直接从 total=3178 变成 total=0）。
- **现场验证**：重开一个全新驱动进程，两个完全独立的角色（普通
  玩家 `qintestz`/`秦侠三`，和管理员 `fluffos`/`巫侠`）都干净地
  走完注册流程，`look` 正确显示起始房间"如何移动"（新手教程室）
  的完整描述、出口 `east`、以及会主动打招呼的 NPC"小花狗"；
  `debug.log` 全程零 "Wrong permissions"/"nosave" 记录。用巫师
  账号 `goto` 到有主动攻击型 NPC 的场景（扬州"异娼庙"的"疯狗"），
  完整交手数十回合，攻防/命中/闪避判定全部正常，疯狗被击晕
  （"跌在地上一动也不动了"）。因为这个 bug 已经严重到本轮大部分
  时间都花在定位它上，死亡/复活循环和留言板发帖本轮未覆盖，留给
  下一轮。
- **和早前 WASM 阶段记录的矛盾**：本文件顶部的 WASM 修复摘要写
  着"带着完整角色属性表和可用的 score/look 指令进入游戏世界，全
  程没有任何意外错误"——这条记录和本轮观察到的情况矛盾。由于这
  段"经验值异常侦测"逻辑是**基于角色具体属性差值的条件触发**，不
  是每次注册都 100% 必然命中，推测早前那次测试用的角色属性差值凑
  巧落在阈值以下，侥幸没有撞上——不代表这份档案曾经真的对所有角
  色都安全过。这也是本次能找到这个 bug 的关键：早前的测试只覆盖
  了"注册流程走没走通"，没有像本轮这样进一步验证"注册完之后
  `look` 是否真的显示了一个房间"。
