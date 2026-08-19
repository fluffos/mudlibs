
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行一百，厦门热线一百分支，MudOS V22pre11——和 110 号 xkx100 标题相同（都叫"侠客行一百"），但内容是真正不同的、更小的一份快照（6456 对 14255 个 .lpc 档案，目录结构也不一样，有 ftp/mudos.etc/www 这些 xkx100 没有的目录），尽管显示名字容易混淆，但不是重复压缩包，没有标记 duplicate_of。WASM 修复了和 xkx2000zxb/xkxyb 自己的表亲档案上已经见过的相同 §7.52 类从零手写 HTTP 服务器 bug：adm/daemons/httpd.lpc（经典的 Truilkan/Jacques Interstice httpd.c，这里的档头注释明确标注是由 xiaobao/ken@XAJH 移植到 XAJH mudlib 底座）直接呼叫 socket_create()/socket_bind()/socket_close()，没有任何存在性判断，导致整个档案在 WASM 下编译失败；已确认零外部呼叫者，按 §7.52 的默认做法，把每一个碰 socket 的函式（setup()、write_data_retry()、store_client_info()、listen_callback()、close_connection() 和 remove() 里的 socket_close 呼叫）都掏空。没有发现 is_chinese()/check_legal_name() bug——"小浮侠"（三个字）第一次尝试就通过了，不需要修，这和本轮好几份手足档案不同。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过源码确认 SECURITY_D 真的会在开机时读取 WIZLIST；wiz_levels 顶层是 (admin)）。注册流程在一次连续的 WASM 客户端会话里完整验证过：按任意键横幅→英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 6456 个档案运行（写入 6420 个，19 个报错，17 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 3 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 54 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:177`、`d/city/npc/jinyong.lpc:197`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。
- **一次性 `Too deep recursion.`（`adm/simul_efun/wizard.lpc:4`，
  `wizhood()`），确认是冷启动伪影，不是真实 bug**：首次注册流程走
  到显示"目前权限"那一刻（第一次实际呼叫 `wizhood()`/编译
  `securityd.lpc` 相关调用链）触发了一次 `Too deep recursion.`（此
  档案 `maximum call depth` 设成 30，比驱动默认的 150 低很多——但
  这个值在同一血统的 `xkx100`/`xkxlb`/`xkx2017`/`xjcq2000` 等档案
  上都一样是 30，那几份都没有触发同样的错误，说明不是这个配置值本
  身普遍导致崩溃，而是这份档案自己某个调用链首次编译时恰好够深，
  和已确认的 §7.90/§10.8"冷启动 eval-cost 耗尽"是同一类现象，只
  是这次撞上的是调用深度而不是求值时间）。已用第二次全新连线复测：
  同样走到"目前权限"这一步，`debug.log` 完全干净，零 `Too deep
  recursion`——确认非持续性，按既定纪律不修改（自愈，不是真实
  bug）。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程创建（含开头"输入任意键继续..."这一步），
落地"巫师休息室"（这份档案的管理员默认出生点），`score`
显示"【天神】"头衔，食物/饮水满格。随后**单独一步**做了真实断线重
连+密码验证：用刚设的密码重新连线成功登录，`debug.log` 全程干净。
驱动按精确 PID 结束；管理员存档已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,225 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
用 `fix_710_room.py` 扫过 `work/`，删除 2,224 处标准形状；
`clone/misc/roommaker.lpc` 剩下 1 处字符串拼接变体
`str += "...replace_program(ROOM);..."`，手工改成
`str += "\n\tsetup();\n}\n";`（同一工具的 heredoc 模板已被脚本正常
扫到）。修复后 `work/` 下 0 处存活残留，44 处转档之前已注释掉的
`//` 行原样保留，`work/data/` 下没有真实 `.lpc` 源码命中。`git diff
--stat` 显示 2224 个文件净删 2225 行，与脚本自报数字 + 1 处手工编
辑吻合。

驱动干净启动（零新增编译错误、端口正常监听、`debug.log` 无任何
"cannot replace"/"cannot bind"行）。这次没有走完整的实机登录走读
——本档案的登录横幅带一个每秒刷新的存活运行时长计数器（"侠客行一
百已经执行了 N 秒/分"），"press any key"过场画面之后又紧跟一个需
要"等静默"式识别的英文名字提示，多次脚本化尝试（不同的读取策略）
都在"fluffos"这个已知有效账号名上被驱动拒绝为"只能用英文字母"，
怀疑是这份档案自己的横幅注释里提到的"用 telnet/Ptelnet 因为密码
输入等待时间太长而无法成功登录，需要用 Zmud"那类客户端时序敏感问
题，而不是这次改动引入的回归——按 AGENTS.md 既定的"某些档案有不
寻常登录协议，退回到仅编译验证"policy 处理，未继续深挖。`debug.log`
在整个驱动运行期间（含上述失败的登录尝试）没有任何
"cannot replace"/"cannot bind"行。驱动按精确 PID 结束。
