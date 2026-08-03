# 夕阳再现 (xyzx)

《夕阳再现》之「风云再起Ⅱ」，是 `xysylmhb`（夕阳三-炎龙美化版）那
一整个家族的原始基础版本，`logind.lpc`/`master.lpc`/注册流程都非常
相似。这份档案在**标准端口不需要** Tomud 客户端握手——`master.lpc`
的 `connect(port)` 只有连到专门的 TOMUD_PORT 才会设一个临时标记，
`logind.lpc` 只有那个标记被设置时才会走 `2060` 版本检查，普通端口
直接跳过。

## 本次修复的关键 bug

同样借助本次会话新写的 `scripts/lib_bulk_fix.py`/`scripts/
scan_known_bugs.py` 提前抓出来：

1. **`uptime()` 开机保护闸门**（AGENTS.md §1.3(e) 既定处理方针）：
   改成只对非 loopback 连线生效。
2. **`check_legal_name()` 的标准 §8.1 `i%2` 奇偶校验/`[i..<0]`
   后缀切片写法**（`is_chinese()` 本身已经是正确的逐码点写法）——
   改成逐码点的 `name[i..i]`。
3. **`master.lpc` 的 `valid_read()`/`valid_write()` 缺少
   `user == this_object()` 短路判断**——这份档案和 `xysylmhb` 一
   样，原本就有一段用 `previous_object()` 判断的局部保护逻辑，为
   了和这次会话建立的标准防御一致，额外补上了明确的短路判断。

`httpd.lpc`/`dns_master.lpc` 本来就已经在 `preload` 里被注释掉，
休眠状态，未作处理。

`SECURITY_D` 正确指向真正会读取 `WIZLIST` 的 `securityd.lpc`（
`globals.h` 里另一个 `securd` 路径是注释掉的），没有 §7.56 的双档
案歧义问题。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"★ 您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

英文 ID → `y`（确认创建新角色）→ 中文名字 → 管理密码 + 确认 → 登
陆密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接受）→ 电子邮件 → 性
别（m/f）→ 进入游戏。

## 本地运行

```
cd libs/xyzx
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40180**。
