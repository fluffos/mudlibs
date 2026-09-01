# 金庸群侠传2013_服务器版 (jyqxc2013fwq)

[jyqxc](../jyqxc/)/[jyqxc2](../jyqxc2/) 同一架构家族的又一份存档
（2013 年服务器版），但地图规模明显更大——除华山、武当、少林、峨嵋、
明教、丐帮等核心门派外，还加入白驼山庄、黑木崖、彩虹谷、黄宫龙宫、
灵鹫宫、逍遥派、雪山、桃花岛/侠客岛等区域。逐文件比对确认（文件总数为
3942 个，明显多于 jyqxc/jyqxc2 各约 3693/3694 个，绝大多数源文件内容
也不同）这是一份真正独立、点位不同的存档快照，并非 jyqxc2 那样的
字节级重复压缩包，只是共享同一套整体地图骨架。

## 内容亮点

- 这份档案独有一处 `#include` 路径写法的疏漏：`combatd.lpc` 全库
  唯一一处用了尖括号绝对路径写法，导致每个玩家执行 `score` 都会崩
  溃（详见下方 bug 修复说明）——同样的 `combatd.lpc` 尖括号 include
  错误此前也在完全不同的"侠客行"家族档案（`xkx2000zxb`/`xkx2017`）
  里独立出现过，是一种在不同代码库间反复出现的常见笔误模式，不是
  同源代码导致的。
- 同样踩中留言板旧存档格式导致的 `capitalize()` 崩溃，修法照搬
  `jyqxc`/`jyqxc2` 已知方案。
- §10.7 深度测试新发现并修复：`combatd.lpc::killer_reward()` 结尾
  一处无保护的 `write_file("/log/nosave/KILLRECORD", ...)`，因为
  `/log/nosave/` 目录不存在而抛出未捕获异常，导致**每一次死亡**（不
  只是玩家互殴）都会在真正把玩家移到鬼门关之前被打断——现场复现为
  玩家被 NPC 打死后卡在原地反复"你死了"、持续挨打的死循环。已加
  `assure_file()` 修复（详见 AGENTS.md §7.11 新增条目）。同一份
  `logind.lpc` 里还有一处 IP 封禁检查传错参数（`query_ip_name()`
  而非 `query_ip_number()`，AGENTS.md §8.14），本档案的匹配逻辑是
  正则而非定长解析，所以表现为封禁列表"失效"（永远不命中），而不
  是像 `hy3` 那样"误封所有人"——已一并修复。`jyqxc`/`jyqxc2` 两份
  姊妹档案的 `logind.lpc` 都带有和本档案完全相同的这两处未修复代
  码，后续如再碰到可以直接照搬本次修法。

## 注册流程

英文名字（3-12 个英文字母）→ 确认建立新角色（y/n）→ 中文名字（1-6
个中文字）→ 密码（至少 5 位）→ 确认密码 → 系统自动产生一组天赋数
值，直接询问是否接受（y/n）→ 电子邮件地址 → 性别（m/f）→ 进入游戏
世界。

## 本次修复的关键 bug

两个 bug，都在 `adm/daemons/combatd.lpc`：

1. `#include </quest/quest.h>` 用的是尖括号绝对路径写法。本驱动
   把尖括号 `#include` 解释成「相对于 `config.fluffos` 里配置的
   include 目录（`/include`）」，而不是相对于 mudlib 根目录——这
   份档案里其余所有绝对路径 include 都正确地用双引号写法
   （`#include "/path.h"`），只有这一处用了尖括号，于是编译报错
   `Cannot #include /quest/quest.h`，接着连锁触发
   `Undefined function quest_finished`，导致整个 `combatd.lpc` 编
   译失败（`No program in object`），每个玩家执行 `score` 都会崩
   溃。改成双引号写法即可。
2. 修好 include 路径后又暴露第二个问题：`quest.h` 顶层有一个
   `mapping quest_name = ([...]);` 全局变量定义，而这行 `#include`
   原本写在 `inherit F_DBASE;` 之前，导致这个全局变量的定义抢先于
   inherit 语句——本驱动不允许在定义了全局变量之后才 inherit
   （`Illegal to inherit after defining global variables`）。把
   `#include "/quest/quest.h"` 挪到 `inherit F_DBASE;` 之后即可。

另外照搬了 jyqxc/jyqxc2 已知的 `feature/name.lpc` 的 `short()`
`capitalize(query("id"))` 防御性修复（同样是留言板存档用旧式二进
制格式、`restore_object()` 解析失败清空 `id` 属性导致的崩溃）。

没有发现 Chinese 姓名判断或指令表相关的 bug。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist`（LF 换行）里；原文件
末尾没有换行符，添加新条目时补上了换行以避免两条记录粘连成一行。
账号本身通过正常注册流程创建，已在游戏内确认 "目前权限：(admin)"
显示正确。

> 注（§10.7，2026-08-08）：本条目此前记录的密码 `Mud2026Adm` 与实
> 际存档不符——检查 `work/data/{login,user}/f/` 发现根本没有
> `fluffos.o` 存档文件，`wizlist` 里的条目此前只写了权限名单，从未
> 真正走过注册流程（本项目本 session 里反复出现的同一类陷阱）。本
> 次已用标准密码 `Mud@2026` 重新走完整注册流程，现场确认存档已生
> 成、密码可正常登录、"目前权限：(admin)" 显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/jyqxc2013fwq
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40108**。
