# 西游记451 (xyj451)

西游记（ES II mudlib 家族，4.50 版）。注册流程**没有**"new"关键
字：只要输入的英文 ID 还没有存档，就会直接问"使用 X 这个名字将会
创造一个新的人物，您确定吗(y/n)？"。天赋点数不是选栏位调整，而是
不断重掷的循环："您同意这组天赋数值吗？[n|y|q]"——`n` 重掷、`y`
接受、`q` 大概是放弃。

## 本次修复的关键 bug

本次借助会话新写的 `scripts/lib_bulk_fix.py`/`scripts/
scan_known_bugs.py` 在第一次开机测试前就先抓出来：

1. **经典 §8.1 GBK 字节区间 `is_chinese()`**（`str[0] > 160 &&
   str[0] < 255`）改成逐码点检查（0x4e00–0x9fff）；配套的
   `check_legal_name()` 的 `i%2` 奇偶校验/`[i..<0]` 后缀切片也改成
   逐码点的 `name[i..i]`。
2. **`master.lpc` 的 `valid_read()`/`valid_write()` 原样转呼叫
   `SECURITY_D`，没有 `user == this_object()` 短路判断**——这正是
   在同宗档案 `xyj20032` 上让每一次新角色注册都静默卡死的那个
   bug（详见该档案 README），这里虽然没有被实际触发，还是提前补
   上防御。
3. **14 处 `is_killing(me)`/`is_killing(who)` 传对象给宣告成
   `is_killing(string id)` 的函式**（§7.50），分布在各门派内功daemon
   和 `cmds/std/surrender.lpc`。

`httpd.lpc`/`dns_master.lpc` 本来就已经在 `adm/etc/preload` 里被注
释掉（原始档案自带的状态），休眠状态，没有开机崩溃风险，未作处理。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

`gb` → 英文 ID（没有 "new" 关键字，直接输入想要的 ID）→ `y`（确认
创建新角色）→ 中文名字 → 密码 + 确认 → 电子邮件 → 性别（m/f）→
`y`（接受当前这组天赋数值，或 `n` 重掷）→ 进入游戏前会先显示一段
分页 MOTD，`q` 可以直接跳过。

## 本地运行

```
cd libs/xyj451
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40112**。
