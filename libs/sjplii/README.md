# 书剑飘零II (sjplii)

和 `sjplgfjxb`（书剑飘零官方教学版）同属飞白工作室的《书剑飘零》ES II 引擎家族，这份档案用的是 `adm/daemons/securityd.lpc`（没有 `sjplgfjxb` 那种 `securd`/`securityd` 双档案混淆的问题），而且与同一批档案里的 `sjpl2`（书剑飘零II）其实是同一次发布的两份快照——两者约 13,073/13,080 个档案路径相同，其中 98.2% 逐字节一致，应理解为一份发布分别打包成 zip、rar 两种形式的结果，而非各自独立开发的游戏。出生时可选四种"家境"（书香门第/商贾之家/贫寒农家/武力世家），各自带来不同的初始技能与出身技能（商贾之家带交易术、贫寒农家带乞讨术），实际出生地点也随之落在山东泰安或沿海福州的对应民居，而非固定的单一新手村（巫师权限账号仍会被固定送到长安城"大慈恩寺"，是刻意的巫师起始点设计，与出生状况选择无关）。拜师用的 `apprentice` 指令身兼二职：第一次拜师加入门派，此后再敲同一指令则变成向师父磕头请安，能提升自己在门派中的地位。门派之外还有一套"江湖营生"玩法：山东粮店/马场可以打工赚钱，福州街头看卖艺人表演能长拆招技能，沿海船坞能造船出海捕鱼、练徒手搏击，这些都能换取潜能或江湖阅历。地图规模明显大于 `sjplgfjxb`：除了共享的长安"大慈恩寺"新手区，还有一整套皇宫场景（大殿、丹凤门、白虎/青龙门等）以及杭州、苏州、宁波、扬州、襄阳、成都、武汉等多座城市。

## 本次修复的 bug

WASM 启动/注册流程本身确实一次性顺利通过（`sjplgfjxb` 的
`report_error()`/`CHANNEL_D` 编译期递归崩溃、未定义的 `REMOTE_DIR`
这两个 bug在这个快照里确实不存在），但后续 §10.7 深度功能测试发现：
`sjplgfjxb` 的另外三个 bug——`d/fuzhou/npc/chess_player.lpc` 编译期
`error`（自由函数误用 `feature/name.lpc` 的 `name(int raw)`）、
`adm/daemons/logind.lpc` 的两处 printf 路径泄漏、`obj/board/
wizard_j.lpc` 的 `/std/jboard` 版 §7.86 留言板崩溃——在 `sjplii`
里其实**同样存在**，均已修复并在原生驱动上逐条验证（细节见
`NOTES.md` "深度功能测试"一节）。此外还独立发现并修复了 `sjplgfjxb`
没有的第四个问题：`adm/daemons/emoted.lpc` 的存档 `data/emoted.o`
里有一段从未转换成 UTF-8 的遗留 GBK 字节，导致 preload 时
`restore()` 抛出未捕获异常（§7.41 类）；已给 `restore()` 包一层
`catch()` 并补上空 mapping 兜底。

管理员账号通过标准方式写入 `/adm/etc/wizlist`——需要注意的是这份档
案下还散落着好几个同名的 `securityd.lpc`/`wizlist`
（`adm/`、`adm/tmp/`、`adm/daemons/bak/`），已经用
`include/globals.h`/`login.h` 里的宏定义确认真正生效的是
`adm/daemons/securityd.lpc` + `adm/etc/wizlist` 这一对。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjplii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40153**。
