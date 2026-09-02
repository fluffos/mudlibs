# 夕阳再现II-炎龙专用美化客户端 (xyzxiiylzymh)

《夕阳再现III 之 炎龙封印》，AKAI Studio 出品，`xysylmhb`（夕阳三- 炎龙美化版）家族的另一个版本，一样用 Tomud 客户端握手协议（连线后第一行是裸的 `version ` 提示，期待字面回传 `2060`）。和 `xysylmhb` 一样，地图其实是"天涯"家族血统（`d/city/sj.lpc` 逐字节相同），是这批档案里第八个确认的成员，标题品牌和实际代码血统再次对不上。

## 内容亮点

- 和 `xysylmhb` 一样挂着"夕阳再现"品牌，但地图是"天涯"家族血统。
- 起始房间在这份档案自己的 4 个候选房间里随机（本次测试落在"北疆
  小镇"），和 `xysylmhb` 固定的"南城客栈"不同——即使地图代码同源，
  两份档案在出生点配置上各自独立调整过。

## 本次修复的关键 bug

同样借助本次会话新写的 `scripts/lib_bulk_fix.py`/`scripts/
scan_known_bugs.py` 提前抓出来，和 `xysylmhb` 完全一样的两个 bug：

1. **`check_legal_name()` 的标准 §8.1 `i%2` 奇偶校验/`[i..<0]`
   后缀切片写法**（`is_chinese()` 本身已经是正确的逐码点写法）——
   改成逐码点的 `name[i..i]`。
2. **`master.lpc` 的 `valid_read()`/`valid_write()` 缺少
   `user == this_object()` 短路判断**——这份档案原本就有一段用
   `previous_object()` 判断的局部保护逻辑，为了和这次会话建立的标
   准防御一致，额外补上了明确的短路判断。

`adm/daemons/network/dns_master.lpc` 本来就已经在 `preload` 里被注
释掉，休眠状态，未作处理。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，登录
  后自动显示"★ 您目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

第一行必须是 `2060`。之后依序：英文 ID → `y`（确认创建新角色）→
中文名字 → 密码 + 确认 → 天赋菜单（`0` 随机整组，`y` 接受）→ 电子
邮件 → 性别（m/f）→ 进入游戏——起始地点在这份档案的 4 个候选房间
之间随机（和姊妹档案 `xysylmhb` 的南城客栈不一定相同）。

## 本地运行

```
cd libs/xyzxiiylzymh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40130**。
