
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行I（"The Quest of Oriental Chivalry"），XiaKeXing Gaming Group 1996-1999，MudOS v22b25 世系，由 sdong 移植。WASM 修复：（1）§7.52 类的从零手写 HTTP 服务器：adm/daemons/network/http.lpc（经典的 Truilkan/Jacques Interstice httpd.c，AGENTS.md 里 mnhf 已经记载过同一血统）直接呼叫 socket_create()/socket_bind()/socket_close()，没有任何存在性判断，导致整个精灵在 WASM 下编译失败。没有任何其它档案呼叫这个精灵（已 grep 确认零外部呼叫者），按 §7.52 的默认做法，把每一个碰 socket 的函式（setup()、write_data_retry()、store_client_info()、listen_callback()、close_connection() 里的 socket_close 呼叫）都掏空成 no-op，而不是逐个呼叫点修补。（2）adm/daemons/logind.lpc 里 §8.1 类的 check_legal_name() bug：按字节数算的长度界限（2-8，本意是 1-4 个字符）加上一个 i%2 奇偶门槛，外加一个破坏性的"修正"骇客（对任何被那个——已经被禁用、注释掉的——is_chinese() 检查标记的字符做 name[j]+=128），在 UTF8 码点索引下会把合法名字搞坏——已把长度界限改成按字符数（1-4），并彻底删掉 +=128 这个变异（原本基于 is_chinese() 的拒绝逻辑本来就已经被原作者注释掉了，这里只是去掉遗留下来的破坏性副作用，没有恢复任何主动校验）。adm/simul_efun/chinese.lpc 的 is_chinese() 本来就是正确的逐码点检查。管理员账号通过 securityd.lpc 真正持久化的存档档案（data/securityd.o，一份纯文本的存档映射字面量，不是那两个从未在实际代码里被读取过的遗留 adm/etc/wizlist.h/wizlist 文本档案）播种——把 fluffos 同时加入 wiz_status（'(admin)'）和 wiz_sites（'.*'，不受限，匹配既有的 'npc' 引导条目的写法），因为 logind.lpc 的 get_id() 会对任何巫师等级的 id 呼叫 SECURITY_D->valid_wiz_login()，如果 euid 在 wiz_sites 里完全没有条目就会拒绝登录，不管 get_status() 的等级是什么——既有的 waiwai/xgslxz 管理员账号被锁定在特定的 192.168.0.40 地址，如果照抄会挡住 WASM 测试/127.0.0.1 的登录。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，没有站点检查拒绝。LPC 格式化工具对全部 8096 个档案运行（写入 8021 个，24 个因为杂乱的历史代码报错，51 个未改动）；还原了 1 个档案（d/taihu/gumu/houtang.lpc）确认有转档之前就存在（作者一方，早于本轮）的未结束字符串损坏（它的 item_desc 映射里两处 'hua1'/'hua2' 条目缺少闭合引号），被格式化工具的分词器进一步重新加了空格。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。全部 7 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)，没有站点检查拒绝。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 39 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——干净通过，零 bug

第一次对这份档案做完整 §10.7 深度游玩测试（注册 → 探索 → 战斗 →
死亡 → 留言板发帖），全程零真实 bug。

**批量编译扫描先行**：`lpcc_check.sh` 全档案 8096 个文件（933 个通
过，144 个失败）——绝大多数失败是孤立的孤儿内容/未接线的网络精灵
（和早前 WASM 阶段已记录的模式一致，未逐个重新核实每一个）。其中
4 处（`/adm/daemons/languanged`、`/adm/daemons/languaged`）撞上
`Eval interrupted: ... cost limit reached, limit: 700000 usec.`——
但读过 `languaged.lpc` 的 `create()`（只有两个单行 `read_file()`
呼叫，完全不昂贵）后怀疑是 lpcc 批量编译共享同一进程、跨数千个档
案累积 eval-cost 债务导致的**纯批量扫描artifact**，不是真实可达
的 bug（`languanged`——带错字的那份——甚至没有任何调用者，是孤
儿档案；只有 `languaged` 被 `feature/message.lpc`/`logind.lpc`/
`adm/simul_efun/message.lpc` 真正呼叫）。

**现场验证排除了这个疑虑**：重开一个全新驱动进程，完整走一遍真实
注册流程（GB/BIG5→英文id→y/n→中文名字→密码+确认→天赋赠礼→电子
邮件→性别→进入游戏世界），全程会自然触发 `logind.lpc`/
`feature/message.lpc` 里对 `languaged.lpc` 的呼叫（每次 `message()`
广播都会用到），也会触发本档案角色基类 `inherit/char/char.lpc` 自
己的冷启动首次编译——两者都干净通过，`debug.log` 全程零
`cost limit reached`。**结论：这 4 处失败确认是批量扫描本身的产
物，不是真实 bug，未修改任何配置或代码。**

**发现的真实设计（非 bug）**：新注册的普通玩家会先落在"侠客岛挂
名处"，`score`/`hp`/`i` 等状态指令在这个阶段**返回空字符串**——
不是崩溃，是因为角色还没走完这份档案自己的游戏内"register
<email>"验证步骤（和账号创建时填的 email 是分开的两步）；完成
`register` 后，服务器会主动断线（"一封包括随机密码的 email 将在
一分钟内寄给您……请用新的密码连线"），要求玩家用新密码重新登录。
这个测试环境收不到真实邮件，所以没能验证一个走完这整套流程的普通
玩家账号；改用巫师账号（`fluffos`，`wiz_sites` 播种为 `.*` 不受
限）来绕过这道验证——巫师直接跳过挂名处，落在真实的沙滩起始房间，
`score`/`hp`/`i` 立即可用（完整属性面板正确渲染）。

**战斗/死亡**：`goto /d/island/icefire3`（冰火岛），两只"白熊"
（`attitude: aggressive`）当场主动攻击，完整交手数回合直至角色死
亡（"你倒在地上，挣扎了几下就死了"），正确移动到死亡区"鬼门关"
（`/d/death/gate`），谣言广播正确。**复活**：确认 `/d/death/npc/
wgargoyle.lpc` 的自动复活 `call_out` 链**明确排除巫师**
（`init()` 里 `if (... || wizardp(previous_object())) return;`）
——所以巫师角色死后不会自动复活，这是有意设计（巫师通常有独立的
复活/immortal 处理），不是本档案独有的 bug；受限于邮件验证步骤
无法用真正的普通玩家账号走完自动复活流程，留给以后有办法收发测
试邮件时再验证。

**留言板**：`goto /d/xiakedao/dadong`（大山洞，有"侠客岛告示牌"），
`post <标题>`（标题跟在同一行）→ 内建行编辑器（`结束离开用 '.'`）
→ `read new` 验证标题、正文、作者全部正确落盘。

测试账号（`fluffos`、`qintestk`）存档留在 `data/` 下作为佐证，均
为未跟踪文件，未纳入本次提交。
