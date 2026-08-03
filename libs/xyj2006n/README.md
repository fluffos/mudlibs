# 西游记2006年 (xyj2006n)

AKAI Studio 的 Tomud 品牌版西游记，和 xyj 系列/ES II 家族同宗，和
`dtxywzxzb`（大唐西游完整修正版）地图逐字节相同（`d/gao/gate.lpc`
等场景内容完全一致），应是同一套底层代码库的不同发行版本，此前两
份档案都没有互相记录这层关系。**连线
后第一行不是常见的 GB/BIG5 选择，而是一个裸的 `version ` 提示**，期待
客户端回传字面值 `2060`（Tomud 或"笑傲江湖"客户端的自动应答）；任何
其他内容都会被识别为"非法客户端"并立即断线——这是刻意设计的客户端识
别机制，不是 bug，测试时第一行务必送 `2060`。

## 内容亮点

- 独有的客户端识别握手：连线后第一行不是常见的 GB/BIG5 选择，而是
  一个裸的 `version ` 提示，只接受字面回复 `2060`（Tomud/"笑傲江
  湖"客户端的自动应答），其它任何输入都会被当作非法客户端立即断
  线——这是这份档案（以及同源的 `dtxywzxzb`）刻意设计的接入门槛。
- 新账号有"必须连线一小时以上才能存档"的反小号机制，`quit` 会先
  问"您决定想要保留这个账号吗？[Y/N]"，是这份档案自己的设计。
- 中文名字在管理密码之前输入（不是之后），注册顺序和大多数档案不
  同，测试或架设时需要按实际的 `input_to()` 链而非套用其它档案的
  假设。

## 本次修复的关键 bug

1. **4 处绝对路径 `#include </...>`**：`d/obj/misc/jitan.h` 的
   `</d/city/misc/banned.h>`、`d/obj/books-nonskill/book-qujing.lpc` 的
   `</d/qujing/obstacle.h>`，以及 `d/qujing/wudidong/monk1.lpc`、
   `u/vikee/dntg10/sky/tongmingdian.lpc` 里各一处——这个驱动的
   `<...>` 语法只在 `config.fluffos` 设定的 include directories（此档
   案里只有 `/include`）里找，绝对路径写法永远找不到，即使目标档案确
   实存在。全部改成双引号写法。
2. **经典 §6.6 convertd.lpc 希腊字母表漏斜杠错字**（`"α\",` 应为
   `"α",`），45 处，而且**同时存在于两份档案**：真正被 `CONVERT_D` 使
   用的 `adm/daemons/convertd.lpc`，和一份没有任何地方引用、形同虚设
   的 `daemons/convertd.lpc`——两份都修了，保持整棵树的一致性。
3. **`adm/simul_efun/message.lpc` 的 `tell_room()` 转发未设定的
   exclude 参数**：2 个参数呼叫 `tell_room()` 时，第三个 varargs 参
   数 `exclude` 落空成裸整数 0，直接传给 `message()` 的第 4 个参
   数，第一次有预载房间的 `sounding()`/心跳呼叫 2 参数版
   `tell_room()` 就崩溃报"Bad argument 4 to EFUN message()"。改成
   `exclude || ({})`。
4. **两个原始 GBK 转档批次漏转的档案**：`d/sea/npc/beast1.lpc`、
   `d/obj/quest/shuijingqiu.lpc` 整份还是原始 GBK 字节，没有被最早
   那一轮 GBK→UTF8 批量转换处理到，编译时报"Invalid UTF8 codepoint in
   string literal"。用 `iconv -c -f GB18030 -t UTF-8` 重新转换（`-c`
   丢弃了少数几个确实损坏、无法还原的尾部字节，纯内容层面的轻微损
   失，不影响编译或游戏逻辑）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（账号密码 + 管理密码双密码机制，
  两者不能相同，管理密码至少 7 个字符且不能与英文 ID 太相似）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（
  `securityd.lpc` 真的会在开机时读取 `WIZLIST`），登录后自动显示
  "目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

第一行必须是 `2060`（客户端版本握手，见上）。之后依序：`new`（新玩
家）→ 英文 ID → 中文名字（在管理密码之前，不是之后）→ 管理密码 +
确认 → 登陆密码 + 确认 → 电子邮件（`id@dtxy.net` 格式）→ 性别
（m/f）→ 天赋点数分配菜单（`9` 接受默认值，`y` 二次确认）→ 进入游
戏，直接落在南城客栈。新建账号有"必须连线一小时以上才能存档"的设
计，`quit` 会先问"您决定想要保留这个账号吗？[Y/N]"，这是游戏本身的
反小号机制，不是 bug。

## 本地运行

```
cd libs/xyj2006n
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40157**。
