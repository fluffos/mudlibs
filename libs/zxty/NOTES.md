
## WASM 修复摘要（迁移自 meta.json 的 group_note）

再现天涯（游戏内横幅：梦回天涯 / 'Dream Return to Tianya'）。和本次会话更早处理过的 Doing 血统 'hell' 家族无关——是一个独立的 ES 衍生代码库，但带有一个巫师个人目录（u/zjb/）里放着好几份核心系统档案（logind.lpc、master.lpc、securityd.lpc）过时的备份副本，没有任何真实路径引用它们（根据 include/globals.h 和 config.fluffos，LOGIN_D=/adm/daemons/logind，MASTER_OB=/adm/obj/master）——已通过 grep 确认 u/zjb/ 之外没有任何地方引用这些备份副本，所以只改动了两份真正生效的档案；备份保持原样，作为无害的死代码。WASM 修复了：（1）真正生效的 adm/daemons/logind.lpc 里一个转档之前就存在（不是本轮引入）的、阻断启动的编译错误：第 28 行 'string *banned_id = (...)' 前面多了一个孤立的 ':'，产生"error: modifier list may not be empty"，导致 logind 完全编译不过，通过 new_conn_handler 把每一个连线用户都断开了——已删掉这个多余的冒号。（2）check_legal_name() 的 §8.1 GBK 字节区间/奇偶 bug：strlen 界限没有减半（<4||>8，本意"2 到 4 个中文字"，已改成 <2||>4）以及一个 i%2==0 的奇偶门槛，配合一个单码点的 is_chinese(name[i..<0]) 辅助函式，实际上只验证了每隔一个字符是不是中文——已删掉奇偶门槛，让每个字符都被检查。is_chinese() 本身（adm/simul_efun/chinese.lpc）本来就是正确的（对 str[0] 做逐码点的 0x4e00-0x9fff 区间检查），不需要修。（3）master.lpc（adm/obj/master.lpc）的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 保护——两处都已加上。已确认这里不需要的修复：is_killing()（feature/attack.lpc）本来就接受物件参数，每一个呼叫点也本来就传的是物件——这份档案不存在 §7.50 类的类型不匹配 bug。httpd.lpc、dns_master.lpc（通过 inetd.lpc）、versiond.lpc、closed.lpc 都带有真实、未掏空的 socket_*() 呼叫，但没有一个在 adm/etc/preload 里，也没有一个能从登录/注册路径触达（VERSION_D 和 CLOSED_D 互相呼叫，还被少数几个 NPC/指令呼叫，而那些呼叫者本身在启动时也触达不到）——保持原样，完全休眠，和本项目其它地方对 ftpd/dns_master 已经确立的先例一致；已通过 grep 确认没有任何预加载精灵或 logind.lpc 引用它们。log/nosave/ 目录缺失（很多非启动路径的功能会用到它——shell 日志、制作日志、吃道具日志）——出于预防已经创建，尽管这里不是阻断启动的（logon() 自己的 log_file() 呼叫都不指向 nosave 路径）。管理员账号播种：fluffos (boss) 加入 adm/etc/wizlist（这份档案的最高巫师阶层字符串是 '(boss)'，不是 '(admin)'——和压缩包原有的 tangsheyu/baizhou/bzhou/baixzhou 条目并存）。注册流程在格式化前后都完整验证过（英文 id→y 确认→单一中文全名（2-4 个字，不分姓名）→管理员密码+确认→登录密码+确认→属性赠礼菜单（0 随机）+确认→电子邮件地址→性别→进入有间客栈），管理员权限已通过'您目前权限：(boss)'确认。有一处格式化工具第 3 个盲点命中（d/city/sj.lpc，转档之前就存在的不配对引号导致 CJK 重新加空格损坏）——已通过 git checkout 还原，确认格式化前的原始内容里没有那个 '\ n' 签名。LPC 格式化工具对全部 13193 个档案运行（写入 13067 个，80 个转档之前就存在的错误，46 个未改动，包括 u/zjb/ 下很多死代码档案）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。

## 深度功能测试（§10.7，2026-08-05）

这份档案是"天涯"家族的又一分支，先检查了同家族已完成 §10.7 深挖
的 `tybxjh`/`xhcii` 的记录，逐项在 `zxty` 自己的源码里核实：

- **2 处 printf 调试残留**：`adm/daemons/logind.lpc` 的
  `get_resp()`/`get_name()`，和 `tybxjh`/`xhcii` 逐字节相同。已删除。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里
  `if (ob->query("age") == 14)`，同样的错对象判断。已改为
  `user->query("age")`。
- **§7.85（tybxjh 的进度条渲染缩放 bug）适用，已修复**：
  `cmds/usr/score.lpc` 的 `tribar_graph()` 和 `tybxjh` 修复前的版
  本逐字节相同（`bar_string`/`blank_string` 16 字符，
  `none_string` 34 字符，残留的 `*2` 宽度乘数），同样的两个失效模
  式（数值为 0 时因为负数下标 `[0..-1]` 反而显示满格；超过约一半
  时切片终点越界被静默截断成满格）。已用相同的重写修复，注册后食
  物/饮水条正确显示（战斗后再查看时能看到真实按比例扣减，比如
  15/16）。
- **§7.86（tybxjh/xhcii 的留言板 `post` 崩溃 bug）适用，已修复**：
  全档案 105 份留言板档案（`clone/board/*_b.lpc`、`d/**/`下多处、
  `p/residence/board/` 玩家自建的留言板）都同时 `inherit
  BULLETIN_BOARD` 和多余地 `replace_program(BULLETIN_BOARD)`，同
  样导致 `post` 指令必然崩溃（`*cannot bind an lfun fp to an
  object with a pending replace_program()`）。已删除全部 102 处
  多余调用（另外 3 处早就被前任巫师注释掉，保持不动）。live 验证
  过：`post` 正常打开编辑器，"新贴子完成"保存成功。
- **§7.86 的另一半（缺失 `/log/login/` 目录导致注册截断）不适
  用**：这份档案的 `work/log/login/` 目录本来就存在（里面已经有
  `newid.log` 等真实历史记录），`log_file("login/newid.log", ...)`
  从未失败过，注册流程干净。
- **exert_function(10) 类型错误，4 处——之前两次深挖（`tybxjh`/
  `xhcii`）用来排查这个 bug 的 grep 命令写错了**：早先用的是
  `exert_function([0-9])`（单个数字的字符类），根本匹配不到两位数
  的 `exert_function(10)`，所以 `xhcii` 那次深挖实际上是真的没有
  这个 bug（用修正后的 `exert_function([0-9]+)` 正则重新核实过，
  确认 `xhcii`/`tybxjh` 都干净），但 `zxty` 这边是真的有，而且是
  live 撞见的：死亡后在鬼门关等复活流程跑完时，`debug.log` 直接报
  出 `error: Bad type for argument 1 of exert_function (string vs
  int)`，来自 `d/daniel/saveme.lpc:23`。和 `tybxjh` 完全相同的四个
  档案（`d/zjb/shengji.lpc` 升级师、`d/daniel/saveme.lpc` 和
  `d/player/ltsh/npc/saveme.lpc` 两份"大魔道士--雅薇丝"、
  `u/zjb/hlxy/zs.lpc` 转世僧人）都有这一行死代码，已全部删除。用
  `goto /d/daniel/saveme` 直接重新编译确认修复生效（之前会编译失
  败，现在正常显示房间和 NPC）。
- **战斗/死亡/复活测试**：〖有间客栈〗禁止战斗（正常设计），移动到
  〖中央广场〗与"收破烂的"打了一场势均力敌的回合制战斗，最终力竭
  阵亡，落到鬼门关，`白无常` 在场，判定守卫是同样的
  `if (!ob || !present(ob)) return;`（AGENTS.md §7.68，现已收窄到
  仅 `bmxkx2001` 适用）——按新纪律未做任何改动，让流程原样跑完。
  第一次尝试时，流程进行到一半，`debug.log` 报出了上面提到的
  `exert_function` 编译错误（`d/daniel/saveme.lpc`）——没有确凿证
  据证明这次编译尝试和复活流程本身有因果关系（也可能是某个不相关
  的房间重置/巡逻逻辑恰好在同一时间触发了那个档案的惰性编译），但
  确实是在等待复活期间实际发生、抓到 debug.log 里的一次真实崩溃，
  值得记录。修复 `exert_function` bug 之后，`goto` 直接确认了那个
  档案能正常编译；死亡/复活流程本身（判定守卫、五阶段对话、
  `reincarnate()`）从代码读取上看没有问题，和已验证过的 `tybxjh`/
  `xhcii` 是同一套实现。
- **本次没有测试**：拜师/门派系统、商店（时间主要花在追查/验证上
  面几个更严重的 bug 上，留给后续深挖）。
