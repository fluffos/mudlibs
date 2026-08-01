# 狂想空间II (kxkjii2)

ES II/Annihilator 系架构衍生的 mudlib，和 jyqxc 系列不是同一血统
（存档用驱动原生的明文格式，不是那一系的旧式二进制格式）。

## 注册流程

英文名字（3-10 个小写英文字母）→ 确认建立新角色（y/n）→ 中文名字
（1-6 个中文字）→ 密码（至少 5 位）→ 确认密码 → 电子邮件地址 →
性别（m/f）→ 互动式天赋分配（膂力→定力→悟性→胆识→根骨→灵性→容
貌，共 7 项手动输入，总点数池 160 点，每项合法范围 10-30；第 8 项
「福缘」由剩余点数自动填入，不再单独询问）→ 按 Enter 键继续 → 进
入游戏世界。

## 本次修复的关键 bug

1. **358 个文件用了尖括号绝对路径 `#include`**（例如
   `#include </open/open.h>`）。本驱动把尖括号 include 解释成「相
   对于 include 目录」而不是「相对于 mudlib 根目录」，这些绝对路径
   一个都解析不了。文件数量太多，不适合逐一手改，改用 AGENTS.md
   §6.1 记载的批量解法：在 `master.lpc` 加一个
   `include_file(compiled, from, path)` apply，对以 `/` 开头的
   路径前面再多加一个 `/`，逼driver走跟带引号 include 一样的
   `merge()` 路径解析逻辑——一次修好，不用碰任何一个原始文件。
2. **`adm/daemons/natured.lpc` 的 `check_heart_beat()`** 里有一个
   多打的分号，让一个 `if` 判断式提前结束，变成一句空语句，导致后
   面那句原本应该被这个 if 保护的
   `"/adm/daemons/temp.lpc"->record_heart_beat(...)` 变成每秒都会
   无条件执行一次——而这个 `/adm/daemons/temp.lpc` 档案在整个档案
   里根本不存在（应该是开发时期的调试用 daemon，发布时被拿掉但呼
   叫点没有清干净）。确认过整个仓库都没有这个档案后，直接移除了两
   处呼叫，而不是凭空补一个档案出来。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud2026Adm`
- **权限 / level**: `(manager)`

这个 lib 的权限体系里 `(manager)` 是比 `(admin)` 更高的一级，管理
员名单里原本两个条目（`chen`、`wun`）都是 `(manager)`，所以新增的
`fluffos` 账号也用了同一级别，存储在纯文本文件 `adm/etc/wizlist`
里；账号本身通过正常注册流程创建，已在游戏内确认
"目前权限 -> (manager)" 显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/kxkjii2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40160**。
