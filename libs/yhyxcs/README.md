# 银河英雄传说

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `银河英雄传说.zip`。ES II 引擎
家族的一支（`master.c` 署名"原作 Lil，Annihilator 改写"），以田中芳树
的科幻小说/动画《银河英雄传说》为背景重新设计。

## 内容亮点

- 舞台设定在银河帝国与自由行星同盟对峙的宇宙历时代，出生地是费沙
  （Fezzan）中央宇宙港——原作粉丝会认出这个中立贸易星球的设定。
- 角色属性沿用原作的军事化风格：力量、胆识、才智、统率、沉着、魅力、
  体格、运气，还记录"曾率领舰队取得胜绩/败绩"次数与"银河使命榜"
  完成度，战斗/指挥两条经验线分开计算。
- 起名规则特别提醒"请勿使用《银河英雄传说》中的人名"——原作人物名
  (杨威利、莱因哈特等) 被显式排除在外，鼓励玩家给自己的角色单独取名。
- 城市间设有出租车（ID卡付款）系统，是这批归档里少见的"打车"玩法。

## 本次 WASM 修复的关键 bug

此前的原生驱动上线流程（记录在这份档案自己的 `NOTES.md` 里）已经修
好了 `master.lpc` 的强制重载崩溃、经典 §8.1 GBK 字节区间
`is_chinese()`/`check_legal_name()` bug、`/teature/`→`/feature/`目
录拼写错误，以及 `id_card.lpc` 一处 void 函式回传值的编译错误，本
次 WASM 复查没有重做这些。这次补上的是：

1. `adm/daemons/ftpd.lpc`、`adm/daemons/network/ftpd.lpc`、
   `adm/daemons/network/dns_master.lpc` 三个碰 socket 的精灵档案全
   部已经在 `adm/etc/preload` 里被注释掉，`DNS_MASTER` 唯一的两个
   呼叫者（`cmds/adm/shutdown.lpc`、`cmds/wiz/mudlist.lpc`）也都是
   已经用 `find_object()` 判断保护过的巫师指令——完全休眠，本次没
   有改动。
2. `master.lpc` 的 `valid_read()` 本来就无条件回传 `1`（完全没有
   转发给 `SECURITY_D`），所以不会出现常见的
   `new()`静默卡死问题；`valid_write()` 还是补上了标准的
   `user == this_object()` 短路判断，跟这次会话里其他档案保持一
   致。
3. §7.50 `is_killing(object)` 与 `is_killing(string id)` 类型不匹
   配，修好了 `cmds/std/surrender.lpc` 唯一一处呼叫点。

`securityd.lpc` 的 `valid_write()` 在每次登陆物件存档时都会打印一
次无害的"Too deep recursion"（`NOTES.md` 已经记录过，源头是
`feature/dbase.lpc` 的 `default_ob` 回退链），在 WASM 下同样复现，
但同样不影响注册、进入游戏或退出——纯粹是日志噪音，本次继续不修。

## 在线试玩

https://mudlibs.fluffos.info/yinhexiongxiongchuanshuo/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/yhyxcs
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40104**。
