# 夕阳再现 (xyzx)

《夕阳再现》之「风云再起Ⅱ」。`logind.lpc`/`master.lpc`/注册流程和
`xysylmhb`（夕阳三-炎龙美化版）/`xyzxiiylzymh`（夕阳再现II-炎龙专
用美化客户端）非常相似，但这份档案的**地图**（`d/city/sj.lpc` 等）
才是真正的"夕阳再现"血统——和 `jhfy3`/`xajh4gkb` 逐字节相同。反而
是打着同样"夕阳再现"招牌的 `xysylmhb`/`xyzxiiylzymh`，地图内容其
实是完全不同的"天涯"家族（详见这两份档案的 README）——三者的关系
和 `wlhd`/`tybxjh` 那种"核心系统档案同源、地图各自独立替换"的模式
如出一辙。这份档案在**标准端口不需要** Tomud 客户端握手——
`master.lpc` 的 `connect(port)` 只有连到专门的 TOMUD_PORT 才会设一
个临时标记，`logind.lpc` 只有那个标记被设置时才会走 `2060` 版本检
查，普通端口直接跳过。

## 内容亮点

- 是"夕阳再现"真正血统的源头版本之一，和 `jhfy3`（江湖风云3）、
  `xajh4gkb`（笑傲江湖4公开版）、`xyzxyl201412`（夕阳再现-炎龙
  20141231，内容最扩充的后期版本）共享同一套地图（`d/city/sj.lpc`
  逐字节相同）。
- 挂着同样"夕阳再现"品牌的 `xysylmhb`/`xyzxiiylzymh` 实际地图却是
  完全不同的"天涯"家族——这批档案里"核心系统同源但地图各自独立替
  换"的模式在这里再次出现，品牌名称完全不能作为地图内容血统的可
  靠依据。

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
