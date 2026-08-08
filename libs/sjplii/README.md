# 书剑飘零II (sjplii)

和 097（`sjplgfjxb`，书剑飘零官方教学版）同属飞白工作室的《书剑飘
零》ES II 引擎家族，这份档案用的是 `adm/daemons/securityd.lpc`（没
有 097 那种 `securd`/`securityd` 双档案混淆的问题）。

## 内容亮点

- 出生时可选四种"家境"（书香门第/商贾之家/贫寒农家/武力世家），各
  自带来不同的初始技能与出身技能（如商贾之家带交易术、贫寒农家带乞
  讨术），实际出生地点也随之落在山东泰安或沿海福州的对应民居，而非
  固定的单一新手村；长安城"大慈恩寺"只在角色已保存的出生房间加载失
  败时才作为兜底出生点。注意：这条出生地规则只对普通玩家生效——巫
  师权限（学徒以上）的账号在 `adm/daemons/logind.lpc` 的
  `enter_world()` 里会被强制固定送到长安城"大慈恩寺"，与出生状况选
  择无关，是刻意的巫师起始点设计，不是 bug。
- 拜师用的 `apprentice` 指令身兼二职：第一次拜师加入门派，此后再敲
  同一指令则变成向师父磕头请安，能提升自己在门派中的地位——是这份
  档案自己特有的双重用途设计。
- 门派之外还有一套"江湖营生"玩法：山东粮店/马场可以打工赚钱，福州
  街头看卖艺人表演能长拆招技能，沿海船坞能造船出海捕鱼、练徒手搏
  击，这些都能换取潜能或江湖阅历。
- 地图规模明显大于 `sjplgfjxb`：除了共享的长安"大慈恩寺"新手区，
  还有一整套皇宫场景（`d/huanggong/`，含大殿、丹凤门、白虎/青龙门
  等）以及杭州、苏州、宁波、扬州、襄阳、成都、武汉等多座城市。

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
