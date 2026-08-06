
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES II/Annihilator 衍生的 mudlib（狂想空间II，"Wild Imagination Space II"），和 jyqxc 家族是不同的血统（存档用驱动原生的明文格式，不是那种旧式二进制编码）。修复了两个 bug：（1）358 个档案用了 AGENTS.md §6.1 类的尖括号绝对路径 #include（例如 #include </open/open.h>），这个驱动会把它解析成相对于配置好的 include 目录而不是 mudlib 根目录——因为分散得太多，不适合逐一手改，改用了文档记载的批量解法：在 master.lpc 里加一个 include_file(compiled, from, path) apply，给看起来是绝对路径的 <> include 前面多加一个"/"，逼它走和带引号 include 相同的、基于 merge() 的路径解析。（2）adm/daemons/natured.lpc 的 check_heart_beat() 里有一个多余的分号提前终止了一个 if 条件（if (wizardp(...) && ...);），导致后面那句原本应该被这个 if 保护的、对不存在的精灵 /adm/daemons/temp.lpc 的 call_other() 变成每次心跳（每秒，永远）都会无条件执行——确认过这个档案在整个代码库里从来不存在（一个被剪掉的开发/调试用暂存精灵，两处呼叫点从没清理干净）；已直接移除这两处死呼叫点，而不是凭空捏造一个替代精灵。注册流程用的是一套特别的互动式点数分配（7 项明确询问的属性、从共享的 160 点数池里分配，第 8 项由剩余点数自动填入），不是 jyqxc 家族那种"自动生成后接受"的模式。这里的管理员等级惯例是 (manager)，比 (admin) 高一级——已把 fluffos 播种为 (manager)，匹配既有的两个条目。完整的注册→look→score→quit 流程和管理员流程在排版格式化前后都验证过；格式化工具还原了 6 个真正损坏的档案（中文字符密集的字符串字面量里出现了错误的"\ n"分词——这是一种 jyqxc 家族里没见过的新损坏形态，和那个家族的 ASCII 地图压缩模式不同）。有几个 diff 特别大的档案（删掉了几千行）经确认是格式化工具正确地清理掉了几千行原本就存在的尾随空行，不是损坏。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 14 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
