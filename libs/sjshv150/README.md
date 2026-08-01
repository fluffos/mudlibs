# 三界神话「紫藤分站」(sjshv150)

"三界神话"系列第二个档案（另见 099 `sjsh`/宝鸡站），紫藤分站的内容，
和宝鸡站不完全一样，但核心代码库同源。

## 本次修复的关键 bug

和 `sjsh` 大部分相同（同源代码），另外还有两个这份档案独有的：

1. **§7.60** `master.lpc` 的 `log_error()`/`standard_trace()` 在
   `CHANNEL_D` 尚未加载时呼叫它——两处都补上
   `find_object(CHANNEL_D)` 判断。
2. **§7.61 `message()` 模拟超越函式缺了 `exclude` 参数的兜底**：
   一旦 `CHANNEL_D` 加载成功，`channeld.lpc` 的 `do_channel()` 只用
   3 个参数呼叫 `message()`（`exclude` 留空默认为整数 0），触发
   `*Bad argument 4 to EFUN message()`——已在
   `adm/simul_efun/message.lpc` 里改成
   `efun::message(arg, message, target, exclude || ({}))`。
3. 和 `sjsh` 相同的 44 行 `convertd.lpc` 损坏字节表格、`emoted.lpc`
   未加保护的 `restore()`。
4. **`is_chinese()`/`check_legal_name()` 的字节配对假设在 UTF8 下失
   效**：`check_legal_name()` 用 `i%2` 作为奇偶配对检查（假设 GBK
   每字 2 字节），但这个驱动下字符串是按码点索引的，每个中文字算 3
   字节——导致中文名字**字数为奇数**时 `i%2` 恒真，永远被拒绝，只
   有偶数字数的名字才凑巧能通过。已改成按码点检查的 `is_chinese()`
   加上正确的 1-6 字长度上限（去掉 `i%2` 判断）。
5. **仅限巫师从本地回环地址登录的限制连"new"这个关键字本身都会挡
   住**：`adm/daemons/sited.lpc` 的 `is_valid()`（和 `sje` 那份形状
   相同）只允许巫师身份的 id 从 `127.0.0.1` 登录，但因为 `new`（触
   发注册的关键字）本身永远不是巫师，导致本地/WASM 测试环境下**完
   全无法开始注册流程**。已比照这份档案自己已有的 `allenc` 硬编码
   例外，追加 `id=="new"` 例外——这属于 §1.3e 已经确立的"仅影响本地
   测试环境的额外摩擦"这一类，对真实远程部署没有任何影响（真实玩家
   永远不会从 127.0.0.1 连过来）。但陌生的（不在 wizlist 里的）全新
   id 依然无法从 WASM/本地环境注册成功，这是一个真实但范围很窄的测
   试限制，本次没有进一步处理。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **管理密码 / Admin password**: 注册时自设（至少 5 位）
- **普通密码 / Regular password**: 注册时自设（这份档案是管理密码+
  普通密码的双密码机制）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予——同时
  也是绕过上面第 5 条本地登录限制所必需的账号。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjshv150
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40171**。
