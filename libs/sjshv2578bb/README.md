# 三界神话「测试二区」(sjshv2578bb)

"三界神话"系列第三个档案（另见 099 `sjsh`/宝鸡站、100 `sjshv150`/紫
藤分站），测试二区的内容。这份档案的 `sited.lpc` 本来就无条件允许
本地回环地址连线（没有 `sjshv150` 那种"仅限巫师"的限制）。

## 本次修复的关键 bug

和同系档案大部分相同（同源代码），另外还有一个这份档案独有的：

1. **§7.60** `master.lpc` 的 `log_error()`/`standard_trace()` 在
   `CHANNEL_D` 尚未加载时呼叫它——两处都补上
   `find_object(CHANNEL_D)` 判断。
2. **`channeld.lpc` 的 `do_channel()` 没检查 `environment(me)` 是否
   为空就直接 `->query("no_chat")`**：一旦上面的 §7.60 修好，
   `CHANNEL_D` 真的能加载了，`log_error()` 广播一条"err"频道消息时
   传入的 `me` 是 `master.lpc` 自己的 `this_object()`——它没有
   `environment()`（永远是 0），触发 `*Bad argument 1 to EFUN
   call_other()`。已加上 `environment(me) &&` 判断。
3. **§7.61** `message()` 模拟超越函式缺了 `exclude` 参数的兜底，和
   `sjshv150` 相同的修法。
4. **§7.41** 损坏的 `emoted.o` 存档，同样的 `catch(restore())` 修
   法。
5. **经典 §8.1 GBK 字节区间 `is_chinese()`**：这次分别出现在
   `adm/daemons/chinesed.lpc`（`CHINESE_D` 真正的实现）和
   `logind.lpc` 的 `check_legal_name()`（同样的 `i%2` 字节配对假
   设，UTF8 码点索引下对奇数字数的中文名字永远误判）——两处都已修
   正。这份档案没有 `convertd.lpc`（不存在这个文件）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位）
- **普通密码 / Regular password**: 注册时自设（双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjshv2578bb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40125**。
