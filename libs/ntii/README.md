# 泥潭II (ntii)

[nte](../nte/) 的同架构家族版本（ES2/Annihilator 系），本次修复涉
及的档案（`logind.lpc`、`named.lpc`、`versiond.lpc`、
`dns_master.lpc`、`clone/user/user.lpc`）和 nte 修复前逐字节相
同——不是整个 lib 的重复（全库 10731/14000+ 个档案不同，主要是游
戏内容），但这几个基础设施档案是共用的。

## 本次修复的关键 bug

和 [nte](../nte/) 完全相同的四类 bug（详见该 lib 的 README 完整说
明）：

1. `is_chinese()` 经典 GBK 字节区间判断错误，以及 `logind.lpc`/
   `named.lpc` 里两处独立的、没有随码点计数减半的姓名长度边界
   （`check_legal_name(arg, 4)` 应为 `2`，`strlen(name) < 2` 应为
   `< 1`）。
2. `logind.lpc` 的 `uptime() < 30` 启动宽限期检查，对本地回环放
   行。
3. `dns_master.lpc`（整个清空）和 `versiond.lpc`（只清空 13 个含
   socket 呼叫的函数，保留其余被 32 处其他档案调用的公开接口）两
   个 socket 精灵编译失败问题。
4. `user.lpc` 的 `accept_kill()` 把物件传给要字符串 id 的
   `is_killing()`，导致角色创建编译失败。

由于本次涉及的每一个档案都和 nte 修复前完全一致，直接把 nte 已验
证过的修复版本档案原样复制过来，而不是重新推导一遍相同的补丁；随
后在这个 lib 自己身上独立跑了一次完整的 WASM 注册验证，确认结果
一致。

## 内容亮点

- 和 `nte` 共享同一套基础设施档案（`logind.lpc`/`named.lpc`/
  `versiond.lpc`/`dns_master.lpc`/`clone/user/user.lpc` 逐字节相
  同），但全库约 1 万个文件内容不同——不是重复压缩包，而是同一套
  引擎骨架配上各自独立的游戏内容。
- 同样有"出生仪式"叙事关卡，`score` 在完成创世神话 NPC 对话前会
  拒绝正常工作，和 `nte`/`nt6` 是同一类设计。
- 本次修复直接复用了 `nte` 已验证过的补丁文件，但仍在这份档案自己
  身上独立跑了一次完整的 WASM 注册验证。

## 注册流程

和 [nte](../nte/) 相同：选择编码 GB 或 BIG5 → 英文名字（3-10 个英
文字母）→ 确认建立新角色（y/n）→ 中文姓氏（1-2 个汉字，可留空）→
中文名字（1-2 个汉字）→ 管理密码（至少 5 位）→ 确认管理密码 → 普
通密码（至少 3 位，不能和管理密码相同）→ 确认普通密码 → 性别
（m/f）→ 进入游戏世界。

真正的"score"同样要求角色先完成一段创世神话 NPC 对话的"出生仪
式"，不是 bug，本次验证范围内没有走完整这段剧情。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `AdminPass1`（管理密码）/ `loginpw1`（普通
  密码）
- **权限 / level**: `(admin)`

管理员身份通过正常注册流程创建，注册完成后已确认自动落在巫师专属
的"巫师休息室"，验证了权限判定正确生效。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/ntii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40151**。
