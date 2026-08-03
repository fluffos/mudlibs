# 书剑贰 (sje)

和 096（`sjecl`，书剑恩仇录）同属 Century/adm-single 引擎家族
（`adm/single/master.lpc` + `adm/daemons/securityd.lpc`），湖北电信的
"书剑贰"泥潭，Ver2.1。

## 内容亮点

- 新角色同样从"武馆前院"起步，东西两侧是练武场，与 `sjecl` 共享
  同一套新手区蓝本，但新手照顾机制不同："武馆门卫"NPC（`ask menwei
  about 礼物`）提供一次性新手礼包，`ask menwei about 传功`则可以
  当面讨要内力灌顶，最多三次、每次增加 100 点内力上限。
- 武馆内还有一位会主动使出"天魔掌""天魔剑""天魔刀""天魔功"等技能
  的"护法使者"NPC，是这份档案自己特有的一位人物。
- 巫师账号有比 `sjecl` 更严格的本地登录限制：`adm/daemons/sited.lpc`
  规定只有已经具备巫师权限的 id 才能从 `127.0.0.1`/`localhost` 连线，
  其余一律拒绝（详见下方管理员账号说明）。

## 本次修复的关键 bug

大部分 bug 和 `sjecl` 完全一样（同宗代码），修法也相同：

1. **§7.60** `master.lpc` 的 `log_error()`/`standard_trace()` 在
   `CHANNEL_D` 尚未加载时呼叫它，触发编译期递归加载崩溃——两处都补
   上 `find_object(CHANNEL_D)` 判断。
2. **§7.59** `securityd.lpc` 的 `valid_read()` 无条件用
   `this_player()` 覆盖驱动传入的 `user` 参数——已排除
   `func=="load_object"`/`"include"` 两种情况。
3. **经典 §8.1** GBK 字节区间 `is_chinese()` + 对应姓名长度上限没有
   减半的 `check_legal_name()`。
4. **§7.50** `is_killing(who)` 传对象而非字符串——同样的 5 个 NPC
   揭穿身份对话档案（`sjecl` 有 6 个，这份档案少了少林那份）。

这份档案独有的新 bug：

5. **`adm/daemons/backupd.lpc` 用了未定义的 `BACKUP_DIR` 常量**，而
   且这个精灵在 preload 列表里，直接导致启动失败。硬盘上已经有一个
   `/backup` 目录（`libs/sje/work/backup/`），确认了原意——在
   `globals.h` 里补上 `#define BACKUP_DIR "/backup/"`。
6. **`adm/daemons/sited.lpc` 的 `is_valid()` 比 `sjecl` 那份更严
   格**：任何非巫师身份的 id 只要从 `127.0.0.1`/`localhost` 连线，
   一律直接拒绝（只有 `wiz_level(id)` 为真的账号才能用本地连线）。
   这是这条支线自己的安全策略，不是 bug——本次没有修改它，而是先把
   `fluffos` 写入 wizlist 再直接用它注册，一次性同时验证了注册流程
   和管理员权限。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（5-8 位，必须同时包含数字和英文
  大写字母）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sje
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40146**。
