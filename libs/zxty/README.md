# 再现天涯 (zxty)

《再现天涯》（游戏内横幅：梦回天涯）。和本次会话之前处理过的
Doing 血统 `hell` 家族没有关系，但和 `tybxjh`/`wlhd`/`xhcii` 那个
"天涯"家族是同源代码——`d/city/sj.lpc`（"世界之巅"跳崖场景）逐字
节完全相同，此前处理这四份档案时都没有互相记录这层关系。档案里有
一个巫师个人目录 `u/zjb/`，里面放了好几份核心系统文件的旧
备份（`logind.lpc`、`master.lpc`、`securityd.lpc` 等）——用
grep 确认过这些备份没有被任何活动路径引用（`include/globals.h`
和 `config.fluffos` 里 `LOGIN_D`=`/adm/daemons/logind`、
`MASTER_OB`=`/adm/obj/master`），所以本次只修了这两份真正生效的
文件，`u/zjb/` 下的备份保持原样没动。

## 内容亮点

- 和"天涯"家族共享同一套地图；"世界之巅"跳崖场景
  （`d/city/sj.lpc`）与 `tybxjh`/`xhcii`/`ffxymud`/`jhfy2`/
  `xysylmhb`/`xyzxiiylzymh` 逐字节相同（`wlhd` 把同一个房间独立
  改写过），但权限阶梯用词不同：这份档案最高巫师等级是 `(boss)`，
  不是 `(admin)`。
- 单一姓名输入（2-4 个汉字，不像 `zjdywzb` 系列那样姓氏/名字分
  开），角色创建带属性天赋随机菜单，新角色从"有间客栈"起步。
- 巫师个人目录 `u/zjb/` 里留着好几份核心系统文件的旧备份
  （`logind.lpc`/`master.lpc`/`securityd.lpc` 等），已确认完全不
  被任何活动路径引用，属于历史遗留死代码，未做任何改动。
- 深度功能测试（§10.7）发现并修复了和 `tybxjh`/`xhcii` 共享的三个
  bug：进度条渲染缩放（食物/饮水/气血曾经无论真实数值都显示"满
  格"）、全档案 105 块留言板的 `post` 指令必然崩溃、以及 4 个
  NPC（升级师、转世僧人、两份"大魔道士"医疗 NPC）因为
  `exert_function()` 参数类型错误而编译失败、从房间里消失，详见下
  方和 NOTES.md。

## 本次修复的关键 bug

1. **一个预先存在（不是这次修复引入）、会挡住整个开机的编译错
   误**：正在生效的 `adm/daemons/logind.lpc` 第 28 行
   `string *banned_id = (...)` 前面多了一个孤立的冒号
   `:string *banned_id`，导致 `error: modifier list may not be
   empty`，logind 整个编译失败，每一个连线的玩家都会被
   `new_conn_handler` 直接断线——去掉了这个多余的冒号。
2. **`check_legal_name()` 的 §8.1 GBK 字节区间/奇偶判断 bug**：
   长度上限没有减半（`<4||>8`，本意是"2到4个中文字"）——改成
   `<2||>4`；还有一个 `i%2==0` 的奇偶门槛，配合只检查
   `str[0]` 的单码点 `is_chinese(name[i..<0])` 辅助函数，实际
   上只验证了一半的字符是不是中文——去掉了这个奇偶门槛，改成每
   个字符都检查。`is_chinese()`（`adm/simul_efun/chinese.lpc`）
   本身已经是正确的逐码点 `0x4e00`-`0x9fff` 判断，不需要修。
3. **`master.lpc`（`adm/obj/master.lpc`）的
   `valid_read()`/`valid_write()` 都缺少标准的
   `user == this_object()` 短路判断**——都补上了。

确认了本档案**不需要**修的地方：`is_killing()`
（`feature/attack.lpc`）本来就是 `object` 参数，所有呼叫点也都
传的是 object，没有 §7.50 的类型不匹配问题。`httpd.lpc`、
`dns_master.lpc`（经由 `inetd.lpc`）、`versiond.lpc`、
`closed.lpc` 虽然都有真正没被掏空的裸 `socket_*()` 呼叫，但都不
在 `adm/etc/preload` 里，也没有任何注册/登录路径能触发到它们
（`VERSION_D`/`CLOSED_D` 只互相呼叫，以及被少数几个同样不可达的
NPC/指令呼叫）——用 grep 确认过没有任何被预载的精灵或
`logind.lpc` 引用它们，因此保持休眠状态没有改动，和本项目其他档
案里 ftpd/dns_master 已确认的休眠先例一致。`log/nosave/` 目录本
来缺失（被好几个不在开机路径上的功能用到，比如 shell 日志、打造
日志、吃丹日志）——为保险起见建了这个目录，虽然这里并不是致命
bug（`logon()` 自己的 `log_file()` 呼叫都不走 nosave 路径）。

## 深度功能测试（§10.7）修复的 bug

sibling-check 自 `tybxjh`/`xhcii`（同一"天涯"家族，已完成深挖）：

- `adm/daemons/logind.lpc` 的 2 处 printf 调试残留，逐字节相同。
- §8.9 食物/饮水年龄检查错对象（`ob->query("age")` 应为
  `user->query("age")`）。
- **进度条渲染缩放 bug（AGENTS.md §7.85）**：`cmds/usr/score.lpc`
  的 `tribar_graph()` 和 `tybxjh` 修复前的版本逐字节相同（残留的
  GBK 时代 `*2` 宽度乘数），已用相同的字符数索引重写修复。
- **留言板 `post` 崩溃 bug（AGENTS.md §7.86）**：全档案 105 份留
  言板文件都同时 `inherit BULLETIN_BOARD` 又多余地对自己
  `replace_program(BULLETIN_BOARD)`，导致 `post` 指令必然崩溃。已
  删除全部 102 处多余调用（3 处已被前任巫师注释掉，未动）。
- **`exert_function(10)` 类型错误，4 处**：`d/zjb/shengji.lpc`（升
  级师）、`d/daniel/saveme.lpc` 和 `d/player/ltsh/npc/saveme.lpc`
  （两份"大魔道士--雅薇丝"）、`u/zjb/hlxy/zs.lpc`（转世僧人）——和
  `tybxjh` 完全相同的四个档案。**之前两次深挖用来排查这个 bug 的
  grep 写错了**（`exert_function([0-9])` 只匹配单个数字，漏掉两位
  数的 `10`）——这次死亡/复活测试期间在 `debug.log` 里直接撞见了
  编译错误才发现。已全部删除这行死代码，用 `goto` 重新编译确认。

（这份档案不需要 `xhcii` 的缺失 `/log/login/` 目录修复：这个目录
本来就存在。）

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（管理密码 `Mud@2026Adm`）
- **权限 / Level**: `(boss)`（这份档案的最高巫师等级字串是
  `(boss)`，不是 `(admin)`），通过 `/adm/etc/wizlist` 授予（保留
  了原档案里已有的 tangsheyu/baizhou/bzhou/baixzhou 几个条目），
  登录后自动显示"您目前权限：(boss)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/zxty
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40166**。
