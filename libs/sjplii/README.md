# 书剑飘零II (sjplii)

和 097（`sjplgfjxb`，书剑飘零官方教学版）同属飞白工作室的《书剑飘
零》ES II 引擎家族，这份档案用的是 `adm/daemons/securityd.lpc`（没
有 097 那种 `securd`/`securityd` 双档案混淆的问题）。

## 内容亮点

- 出生时可选四种"家境"（商贾/贫寒/中等等），各自带来不同的初始技
  能与出身技能（如商贾之家带交易术、贫寒农家带乞讨术），实际出生
  地点也随之落在山东泰安或沿海福州，而非固定的单一新手村。
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

**没有**——这份档案的 WASM 启动、注册流程、`look`/`score`/`quit`
全部一次性顺利通过，`sjplgfjxb` 那三个 bug（`report_error()` 触发
`CHANNEL_D` 编译期递归崩溃、未定义的 `REMOTE_DIR`、损坏的 emote 存
档）在这个快照里都不存在。

管理员账号通过标准方式写入 `/adm/etc/wizlist`——需要注意的是这份档
案下还散落着好几个同名的 `securityd.lpc`/`wizlist`
（`adm/`、`adm/tmp/`、`adm/daemons/bak/`），已经用
`include/globals.h`/`login.h` 里的宏定义确认真正生效的是
`adm/daemons/securityd.lpc` + `adm/etc/wizlist` 这一对。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjplii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40153**。
