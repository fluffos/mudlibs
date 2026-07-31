# 风云之风起云涌

一个以古龙小说为背景的"风云"MUD。

## 注册流程（两套密码）

英文名字 → 确认建立（y/n）→ 中文名字（2-4 个中文字）→ **管理密码**
（≥5 字元，用于遗失普通密码时找回、修改密码，平时不要用）→ 确认管
理密码 → **普通密码**（≥5 字元，日常登录用，不能和管理密码一样）
→ 确认密码 → 民族（0-3）→ 性别（m/f）。

## 本次修复的关键 bug

- **新发现，已收录进 AGENTS.md §7.60**：`master.lpc` 的 `log_error()`
  ——每一条普通的编译警告（不只是真正的错误）都会调用它——最后会执
  行 `CHANNEL_D->do_channel(...)`。如果 `CHANNEL_D` 这时候还没有被
  preload（取决于它在 `adm/etc/preload` 里排在第几个），这次调用会
  在调用者自己还在编译的过程中，悄悄触发对 `channeld.lpc` 的一次新
  编译——这个驱动禁止这种嵌套编译，于是抛出
  `*Object cannot be loaded during compilation.`，又被 `log_error()`
  自己捕获并重新记录一次，如此循环，把一条本来毫无意义的 pragma 警
  告变成了几万行重复的错误堆栈输出。这个问题只存在于 `CHANNEL_D` 加
  载完成之前的极短启动窗口内（之后完全正常），但足以把真实输出淹没
  到没法看，因此还是修了：在广播前先判断 `find_object(CHANNEL_D)`。
- `is_chinese()` 和 `check_legal_name()` 都沿用旧版 GBK 字节双字节
  假设（字节区间判断 + 长度界限按字节数而非字符数 + 逐字节跳步循
  环），导致所有真实中文名字（包括标准测试名字）都被拒绝。已按
  AGENTS.md §8.1 的标准做法修复。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建（管理密码另设为 `AdminPw1`，与登录密码不同）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/fyzfqyy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40133**。
