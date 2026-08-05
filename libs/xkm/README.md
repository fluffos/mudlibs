# 侠客梦

与 147/jym（金庸梦）同源代码线（同一套 `simul_efun` 组成），但注册流
程有额外分支，不要假设两者的 `--send` 序列完全一致。

## 内容亮点

- 和 `jym`（金庸梦）同源代码线，也和 `xkx2000zxb` 共享同一套"侠客
  行I"地图骨架（太湖古墓、昆仑、少林等场景），三者是同一批底层代
  码库在不同站点的流通版本。
- 注册流程比 `jym` 多两步：先要确认阅读过"侠客梦玩家守则"，后面
  还要填 QQ 号码，是这份档案自己独有的额外步骤。
- 本次修复中发现一个原始存档里真实存在、和 WASM 无关的 bug：任何
  被授予巫师权限但从未真正注册过存档的账号（管理员账号种子恰好就
  是这种情况），下一次输入都会被无声地导向一个从未设置过的密码校
  验，永远报"密码错误"并断线——任何真实环境给一个未注册 id 授予巫
  师权限都会踩到（详见下方 bug 修复说明）。
- 深度功能测试（§10.7）走完新手教程、战斗（武当山路的"土匪"，回合制
  攻防+经验/阅历增长全部验证正常）、留言板系统，发现并修复一个此前
  从未记录过的新 bug：留言板 `read` 指令用来限流"每次读留言给
  chatpts"的冷却条件精灵 `/kungfu/condition/boardread.lpc` 整个文件
  都不存在（AGENTS.md 新增 §7.83），导致冷却从未生效（可无限刷分）
  且每次阅读都在玩家画面上炸出一条运行时错误——`log/condition.err`
  显示这个 bug 从 2002 年就存在，是原始档案里的真实缺陷。详见
  NOTES.md。

## 注册流程

`new` 触发注册 → BIG5 确认（y/n，任何非 y/yes 都视为 GB）→ 英文 id
（3-8 个英文字母）→ 确认创建（y/n）→【“侠客梦”玩家守则】确认（y/n）
→ 中文名字（2-4 个中文字）→ 管理密码（≥5 字元）→ 确认管理密码 → 普
通密码（≥3 字元，且不能与管理密码相同）→ 确认普通密码 → 天赋接受
（y/n，无需先选 0-4，直接展示随机天赋）→ QQ 号码 → 电子邮件地址
（需 `id@address` 格式）→ 性别（m/f）。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：与 jym 同款的 euid 被中途重置的
  bug——`make_body()` 里的 `seteuid(getuid())` 会把 `create()` 刚设置
  好的 euid 重置为空字符串。已改为显式 `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，且有一行
  `name[j]+=128; name[j+1]+=128;`（旧版高位字节判断的遗留代码，对
  Unicode 码点毫无意义甚至有害），已删除并改为按字符数（2-4）+
  逐字符 `is_chinese()` 判断。
- `adm/daemons/securityd.lpc`：`get_status()` 对尚未完成初始化的
  `wiz_status`/`wiz_levels` 重入调用会崩溃，已加防御（与 jym 相同）。
- `cmds/usr/quit.lpc`：`environment(me)->query(...)` 在玩家环境为 0
  时崩溃，已加 `environment(me) &&` 防御（与 jym 相同）。
- `adm/simul_efun/message.lpc`：`tell_room()` 的 `exclude` 参数缺省
  为裸 `int 0` 直接传给 `message()`，已按 AGENTS.md §7.12 修复为
  `exclude || ({})`（与 jym 相同）。
- **本 lib 独有的新 bug**：`get_id()` 对**任何** `wiz_level>0` 的 id
  都无条件注册 `input_to("get_passwdd", 1, ob)`，且没有检查存档是否
  真的存在，也没有 `return`——包括一个"刚被授予巫师权限但还从未注册
  过"的全新账号（正是给 admin 账号播种时的场景）。这会导致下一次玩
  家输入被静默地转发给 `get_passwdd()` 去校验一个从未设置过的密码，
  永远失败并断开连接（"密码错误！"）。已修复为只在
  `file_size(存档文件)>=0` 时才注册这个 input_to（与函数后面真正判
  断存档是否存在的逻辑保持一致），并补上缺失的 `return`。这是原始存
  档里真实存在的 bug，不是本次改动引入的问题——任何真实环境如果给一
  个尚未注册过的 id 授予巫师权限，都会踩到同样的坑。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在 `adm/daemons/securityd.lpc` 自身的存档文件
`data/securityd.o` 的 `wiz_status`/`wiz_sites` 属性里（与 jym 相同的
机制；`wiz_sites` 也需要一并设置成 `".*"`，否则会被"请从登记的地址
使用巫师帐号"拒绝登陆）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/xkm/

## 本地运行

```
cd libs/xkm
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40191**。
