# 夕阳三-炎龙美化版 (xysylmhb)

《夕阳再现III 之 炎龙封印》，AKAI Studio 出品，但游戏地图其实并非"夕阳再现"血统：经档案比对，其地图数据和"天涯"家族逐字节相同（`d/city/sj.lpc` 的"世界之巅"跳崖场景一致）——根源档案是 `tybxjh`，同一血统下还包括 `wlhd`/`xhcii`/`zxty`/`ffxymud`/`jhfy2`/`xyzxiiylzymh`/`yxjh`/`yzxiiizylfy`，这份档案也是其中之一；真正的"夕阳再现"血统其实是本项目里的 `xajh4gkb`/`jhfy3` 等档案，品牌名称和实际地图血统在这批档案里经常对不上。连线协议沿用 Tomud/"笑傲江湖"客户端握手，连线后第一行须是裸的 `2060`。注册没有"new"关键字，任何还没存档的英文 ID 直接问"使用 X 这个名字将会创造一个新的人物，您确定吗(y/n)？"；天赋是菜单选栏位（`1-4` 指定单项数值，`0` 系统随机整组，然后 `y/n` 确认接受）。新角色从泉州起步，落脚铁枪庙，之后可以加入丐帮成都分舵，从入门弟子逐级晋升为有名号的高阶弟子。另外，`xyzx3`（同样叫做《夕阳再现III 之 炎龙封印》）无论 `.lpc` 文件总数、目录结构还是 `d/city/sj.lpc` 地图数据都和这份档案几乎完全一致，很可能是同一个原始压缩包被本项目拆分成了两份独立档案。

## 内容亮点

- 虽然标题写着"夕阳再现"，地图却是"天涯"家族血统，和 `xajh4gkb`/
  `jhfy3` 那支真正的"夕阳再现"代码完全不同源——是本项目里"标题和
  实际代码血统对不上"最典型的一个案例。
- Tomud/"笑傲江湖"客户端握手协议（连线第一行必须是 `2060`）和
  `xyj2006n`/`xyj2006zzzhx` 一致，但游戏地图却是完全不同的"天涯"
  家族，说明这几个"AKAI Studio"相关档案之间也不是铁板一块的同源
  代码。

## 本次修复的关键 bug

同样借助本次会话新写的 `scripts/lib_bulk_fix.py`/`scripts/
scan_known_bugs.py` 提前抓出来：

1. **`check_legal_name()` 的标准 §8.1 `i%2` 奇偶校验/`[i..<0]`
   后缀切片写法**（`is_chinese()` 本身已经是正确的逐码点写法）
   ——改成逐码点的 `name[i..i]`。
2. **`master.lpc` 的 `valid_read()`/`valid_write()` 缺少
   `user == this_object()` 短路判断**——这份档案原本就有一段用
   `previous_object()` 判断的局部保护逻辑，但为了和这次会话建立的
   标准防御一致，还是额外补上了明确的短路判断。

`adm/daemons/network/dns_master.lpc`（真正被 `DNS_MASTER` 宏使用
的那份，`include/net/daemons.h` 确认）本来就已经在 `preload` 里被
注释掉，休眠状态；还有一份没有引用的死档案 `adm/daemons/
dns_master.lpc` 也带有原始 socket 呼叫，但从未被加载，两者都未作
处理。

`SECURITY_D` 正确指向真正会读取 `WIZLIST` 的 `securityd.lpc`（
`globals.h` 里另一个 `securd` 路径是注释掉的），这份档案没有
§7.56 的双档案歧义问题。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"★ 您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

第一行必须是 `2060`。之后依序：英文 ID → `y`（确认创建新角色）→
中文名字 → 密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接受）→
电子邮件 → 性别（m/f）→ 进入游戏。

## 本地运行

```
cd libs/xysylmhb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40169**。
