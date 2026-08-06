
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib，jhfy2 的手足/后继档案（按路径和 jhfy2 重合 7977/9332 个档案，jhfy3 是一个更大的扩充超集），游戏内标题为"夕阳再现 之「风云再起Ⅱ」"。只有一个 bug：adm/daemons/logind.lpc 的 logon() 里 §1.3e 的 uptime()<30 开机保护闸门，在每一次 WASM 连线时都必然触发（测试环境开机后立刻连线，而且不管等多久现实时间都没用，因为 WASM 的事件后端是由宿主逐笔驱动而非真实系统时钟驱动）——已按 AGENTS.md §1.3e 既定方针对本地回环放行（query_ip_number(ob) != "127.0.0.1" && uptime() < 30）。没有发现中文名字/宏定义/指令表相关的 bug。管理员账号（fluffos，双密码机制）通过真实注册流程 + adm/etc/wizlist（CRLF 格式，和档案里既有条目一致）播种，游戏内"★ 您目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字——注意这份档案是双密码流程（先设管理密码再设登录密码），和 jhfy2 的单一密码不同。格式化工具发现 5 个真正损坏的档案（d/huashan/map.lpc 和它在 u/fyue/ 下的副本——都是 ASCII 地图，和手足档案里同样的分词器混淆模式；d/player/fyue_room.lpc；d/quanzhen_old/hudi5.lpc，一份和 ffxymud/jhfy2 的 d/city/sj.lpc 类似的、转档之前就存在的缺引号档案；kungfu/skill/jinshe-jian/kuangwu.lpc，一段两行的档头注释被合并、插入了空格）——全部用 git checkout 还原。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
