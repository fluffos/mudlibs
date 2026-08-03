# 金庸群侠传2013_服务器版 (jyqxc2013fwq)

[jyqxc](../jyqxc/)/[jyqxc2](../jyqxc2/) 同一架构家族的另一份存档
（2013 年服务器版），文件内容大部分不同，但整体结构和已知 bug 面
基本一致。

## 内容亮点

- 和 `jyqxc`/`jyqxc2` 同一架构家族的又一个存档（2013 年服务器版），
  地图目录结构一致，但具体文件内容各自独立。
- 这份档案独有一处 `#include` 路径写法的疏漏：`combatd.lpc` 全库
  唯一一处用了尖括号绝对路径写法，导致每个玩家执行 `score` 都会崩
  溃（详见下方 bug 修复说明）——同样的 `combatd.lpc` 尖括号 include
  错误此前也在完全不同的"侠客行"家族档案（`xkx2000zxb`/`xkx2017`）
  里独立出现过，是一种在不同代码库间反复出现的常见笔误模式，不是
  同源代码导致的。
- 同样踩中留言板旧存档格式导致的 `capitalize()` 崩溃，修法照搬
  `jyqxc`/`jyqxc2` 已知方案。

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
- **密码 / password**: `Mud2026Adm`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist`（LF 换行）里；原文件
末尾没有换行符，添加新条目时补上了换行以避免两条记录粘连成一行。
账号本身通过正常注册流程创建，已在游戏内确认 "目前权限：(admin)"
显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/jyqxc2013fwq
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40108**。
