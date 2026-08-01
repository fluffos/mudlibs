# 书剑恩仇录 (sjecl)

Century/adm-single 引擎家族的一支（`adm/single/master.lpc` +
`adm/daemons/securityd.lpc`），以金庸小说《书剑恩仇录》为背景的重庆
电信"书剑"泥潭。

## 本次修复的关键 bug

1. **§7.60 `master.lpc` 的 `log_error()`/`standard_trace()` 在
   `CHANNEL_D` 尚未加载时呼叫它，触发编译期递归加载崩溃**：一个普通
   的编译警告（甚至运行时错误）就会在启动早期炸出成千上万行重复的
   报错。两处都补上 `find_object(CHANNEL_D)` 判断。
2. **§7.59 `securityd.lpc` 的 `valid_read()` 无条件用
   `this_player()` 覆盖驱动传入的 `user` 参数**：导致每一次连线最开
   头 `logind.lpc` 检查 IP 黑名单（`BAN_D->is_banned()`，此时玩家还
   没输入 id）都会因为权限判定错误而报 `*Read access denied.`——已
   排除 `func=="load_object"`/`"include"` 两种情况，不再覆盖。
3. **经典 §8.1 GBK 字节区间 `is_chinese()`**，以及对应的姓名长度上
   限没有减半（原来是字节数时代的 4-8，改成 2-4，并去掉按字节配对
   的 `i%2` 窗口检查）。
4. **§7.50 `is_killing()` 传对象而非字符串**：这次不在
   `accept_kill()` 里，而是 5 个 NPC 揭穿身份后开打的对话档案里（
   `d/city/npc/{guidao,guidao1,guidao2,xiaosong}.lpc`、
   `d/foshan/npc/wanglaohan.lpc`、`d/shaolin/npc/xiaosong.lpc`）,
   这些是直接呼叫（非 `->`），会让 preload 阶段生成 NPC 时整个编译
   失败。约 20 处 `kungfu/skill/*.lpc` 里也有同样写法的
   `target->is_killing(me)`，但那些是 `->` 呼叫，不会导致编译失败，
   只是运行时判断不准（内容/平衡性问题），按惯例本次不追加修改。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（至少 5 位，必须同时包含数字和英
  文大写字母）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。
- 这份档案还有第二层限制：`adm/daemons/sited.lpc` 里硬编码了一个
  按巫师 id 生效的登录 IP 白名单（`valid_login`），巫师状态的账号
  如果不在这份表里，无论从哪个地址登录都会被拒绝并提示"巫师必须有
  地址限制"。已经在这份表里加了 `"fluffos": ({ "127.", "0." })`，
  允许本地/WASM 测试连线。正式对外开服后如果要开放巫师从其它地址
  登录，需要用巫师指令追加更多前缀。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjecl
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40139**。
