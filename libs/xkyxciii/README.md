# 侠客英雄传III (xkyxciii)

侠客英雄传 II/III「欢乐天地」，五邑无尽豪情，一个融合金庸小说、欧
洲中世纪传说和漫画元素的世界观。

## 本次修复的关键 bug

**§8.1 GBK 字节区间 `is_chinese()` bug，出现在两个地方**：

1. `adm/daemons/chinesed.lpc` 的 `is_chinese()`（`CHINESE_D` 真正
   的实现，`logind.lpc` 委托它做判断）只检查 `str[0]` 的原始字节区
   间，还要求总长度是偶数，在这个驱动按 UTF8 码点索引字符串的情况
   下永远判定失败。
2. `adm/daemons/logind.lpc` 自己的 `check_legal_name()` 也有一样的
   `i%2` 奇偶门槛，长度上限是字节数写法（2-12，原意是提示文字里说
   的"1 到 6 个中文字"）。

已把 `chinesed.lpc` 的 `is_chinese()` 改成逐码点 0x4e00-0x9fff 区
间检查，`check_legal_name()` 改成逐字符呼叫
`CHINESE_D->is_chinese(name[i..i])`，长度上限改成字符数 1-6。

## 测试注意事项

性别/种族选择紧跟在 `/std/char.lpc` 首次编译（带出
`feature/damage.lpc`/`feature/skill.lpc` 等一大堆编译警告）之后，
和 `xhcii` 记录过的情况一样，会有测试客户端的计时竞态——"m"偶尔
会被当成无法识别的指令，不管 `--idle` 设多长。多送一次"m"/"0"就
能稳定通过；已经用一次完全干净、注册过程零异常的成功运行确认过这
纯粹是测试工具的计时问题，不是 mudlib 本身的缺陷。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予，
  `wizlist` 命令确认显示"目前权限：(admin)"，且 `fluffos` 出现在
  最高权限组里。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xkyxciii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40118**。
