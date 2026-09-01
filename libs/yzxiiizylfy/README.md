# 夕阳再现III之炎龙封印 (yzxiiizylfy)

《夕阳再现III之炎龙封印》，阿凯工作室（AKAI Studio）2006 年出品。和这批档案里其他"夕阳再现"标题的档案一样，采用 Tomud "2060" 客户端版本握手（第一次输入必须是字面字符串 "2060"，否则会提示"你的客户端非Tomud或者非笑傲江湖WWW客户端"），新角色从祀奉铁枪王彦章的"铁枪庙"起步，注册流程为客户端握手、英文 ID、中文全名、密码加确认、天赋菜单、电子邮件、性别。虽然标题挂着"夕阳再现"，地图其实和真正的"夕阳再现"血统（`xyzx`/`jhfy3`/`xajh4gkb`/`xyzxyl201412`）没有关系，而是属于以 `tybxjh` 为根、囊括 `wlhd`/`xhcii`/`zxty`/`ffxymud`/`jhfy2`/`xysylmhb`/`xyzxiiylzymh`/`yxjh` 的"天涯"家族——`d/city/sj.lpc` 跳崖场景和 `xysylmhb`/`xyzxiiylzymh` 逐字节相同；其中和 `yxjh` 的关系尤其近，两者共享同一座铁枪庙起点、约 85% 的档案路径，但共享部分里只有约三分之一逐字节相同，是分化独立的姊妹档案而非重复打包。

## 内容亮点

- 又一个"标题挂夕阳再现、地图其实是天涯家族"的案例，说明这批
  AKAI Studio/Tomud 客户端相关的档案之间共享的其实只是客户端握手
  协议和部分核心系统档案，地图内容各自独立。
- 天涯家族全谱系：根源 `tybxjh`，加上 `wlhd`/`xhcii`/`zxty`/
  `ffxymud`/`jhfy2`/`xysylmhb`/`xyzxiiylzymh`/`yxjh`，本档案是其
  中之一，且和 `yxjh` 关系最近。



## 本次修复的关键 bug

1. **标准 §8.1 `check_legal_name()` 的 `i%2` 奇偶校验/`[i..<0]`
   后缀切片写法**（`is_chinese()` 本身已经是正确的逐码点写法）——
   改成逐码点的 `name[i..i]`，上下限从 2/10 减半成 1/5。
2. **`master.lpc` 的 `valid_read()`/`valid_write()` 都缺少标准的
   `user == this_object()` 短路判断**——补上了，`valid_read()`
   里这份档案自己原有的（少见的、不完整的）
   `previous_object()` 判断逻辑保留不动。`tell_room()` 的
   `exclude` 参数和 `securityd.lpc` 的 `save_object()` 扩展名检
   查本来就是对的，不用改。

档案里有两份 `dns_master.lpc`（`adm/daemons/dns_master.lpc` 和
`adm/daemons/network/dns_master.lpc`），只有 `network/` 那份被
`DNS_MASTER` 宏引用（另一份完全是死档案，没有任何宏或字面路径指
向它），而且已经在 `adm/etc/preload` 里被注释掉，剩下的呼叫者也
都是用 `find_object()` 保护过的巫师指令——两份都属于休眠状态，本
次没有改动。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"★ 您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

先发送 `2060`（Tomud 客户端版本握手）→ 英文 ID → `y`（确认创建新
角色）→ 中文名字 → 密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接
受）→ 电子邮件 → 性别（m/f）→ 进入游戏（铁枪庙）。

## 本地运行

```
cd libs/yzxiiizylfy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40178**。
