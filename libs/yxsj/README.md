# 逸俠世界 (yxsj)

《逸俠之世界》（Daniel's World），ES II 引擎家族，台灣出品（BBS
140.127.179.161，聯絡信箱 leonguo@tpts4.seed.net.tw）。注册流程为
英文 ID → 中文名字 → 密码 + 确认 → 电子邮件 → 性别。

## 内容亮点

- 世界观非常特别：新角色从校园场景起步（`d/school/`，教室、中庭花
  園、實驗大樓、廚房、腳踏車停放處等一应俱全的现代校园地图），而
  不是常见的武馆或城镇——是这批档案里少有的"校园"题材开局。
- `d/Pili/` 收录了台湾"霹雳布袋戏"（Pili puppet-show franchise）相
  关的场景与 NPC，说明这份档案把布袋戏元素也编织进了世界观，和纯
  金庸/古龙武侠背景明显不同。
- 台湾 BIG5 编码血统带来了本轮最严重的一次转档事故：档案原文是
  BIG5，但最初的转档脚本以为是 GB18030，结果转出来的是"看起来正
  常但语意不通"的合法 UTF-8 乱码，连 `iconv` 都没报错——已扩充转档
  脚本支持指定来源编码并用 BIG5 重新转换（详见下方说明）。

## 重大编码问题（在任何 WASM 修复之前就先修好了）

这份档案是 **BIG5** 编码，但最初的 `convert_lib.sh` 转换（该脚本原
本写死用 GB18030 当来源编码）把每一个字串都用**错误的编码表**转
了一遍——结果是合法的 UTF-8，但每一句玩家看得到的讯息都变成了看起
来正常、实际上语意不通的乱码汉字（比如原本该是"您的英文"却变成
"眤璣ゅ"），而不是 iconv 直接报错，所以乍看之下像是转换成功了。用
两种编码分别解码同一份原始档案的 `write("...")` 字串比对后确认了
问题。已经把 `scripts/convert_lib.sh` 扩充成可以传第三个"来源编
码"参数（预设仍是 GB18030，不影响其它任何档案），用 `BIG5` 重跑
了这份档案的转换。由于 `convert_lib.sh` 会整个重建 `work/`，之前
已经套用在（乱码版）work 树上的 WASM 修复全部要在新转出来的
BIG5 版本上重做一遍。

## 本次修复的关键 bug

1. **经典 §8.1 GBK 字节区间 `is_chinese()`/`check_legal_name()`**
   （奇偶校验、`[i..<0]` 后缀切片、字节数没减半的 2/12 上下限）——
   改成逐码点的 `0x4e00`-`0x9fff` 判断和 `name[i..i]`，上下限减半
   成 1/6。
2. **§7.12 `tell_room()` 裸露 `exclude` 参数导致 `message()` 崩
   溃**——补上标准的 `exclude || ({})` 保护。
3. **`master.lpc` 的 `valid_write()`**（`valid_read()` 本来就无条
   件回传 `1`）补上了标准的 `user == this_object()` 短路判断。
4. **§7.50 `is_killing(object)` 与 `is_killing(string id)` 类型不
   匹配**，修好了 9 处呼叫点（几个门派 `roar`/`nuke` 档案、
   `u/d/daniel/` 底下几个 NPC 档案、`cmds/std/surrender.lpc`）。
5. **`data/` 目录下 39 个存档档案是 CRLF 换行**，统一转成了 LF。
6. **真正的（非 WASM 专属）bug**：`adm/daemons/securityd.lpc` 的
   `valid_write()` 在 `save_object` 快速通道里用
   `file == user->query_save_file()` 做完全相等比对，但这台驱动
   的 `save_object()` efun（`vm/internal/base/object.cc`）在呼叫
   `valid_write()` 之前会先把 `__SAVE_EXTENSION__`（`.o`）接在档
   名后面——完全相等比对永远不会成立，导致**每一次玩家存档**（注
   册、进入游戏、退出）都被拒绝，报"Denied write permission in
   save_object()"。改成和 `query_save_file() + __SAVE_EXTENSION__`
   比对就修好了（这个正确写法在本次会话的 yhwhpublicfi/yxjh 两份
   姊妹档案里本来就有，yxsj 这份只是漏掉了）。

`adm/daemons/ftpd.lpc`、`adm/daemons/network/dns_master.lpc` 都已
经在 `adm/etc/preload` 里被注释掉，仅有的呼叫者也都是巫师专用指
令，属于完全休眠，本次没有改动。

## 已知但未修复的问题

- `adm/daemons/chinesed.lpc`、`adm/daemons/emoted.lpc` 开机时都会
  报一次被拦截、非致命的"Illegal mapping format while restoring
  dict/emote"——和另一份档案（`yxjh` 的 `named.lpc`，内容完全不
  同）出现过一模一样的错误特征，可能是驱动本身的某种共性限制，不
  是这份档案独有的内容损坏，没有进一步深挖，不影响任何已观察到的
  游戏功能。
- 注册/登陆过程会出现一次"apply() with insufficient permission...
  needs: private, has: hidden"（关于 `obj/user` 的
  `command_hook`），但不影响指令处理、进入游戏或退出。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`（这份档案最高阶层就是 `(admin)`），
  通过 `/adm/etc/wizlist` 授予，登录后自动显示"目前權限﹕
  (admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/yxsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40167**。
