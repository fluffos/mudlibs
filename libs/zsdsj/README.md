# 重生的世界 (Revival World)

RWlib v1.0.1，台湾团队开发的生活模拟/城市经营类 MUD，与本项目其他武侠
类 mudlib 完全不属于同一谱系，是一套独立自制的引擎。

## 内容亮点

- 不是打怪升级的武侠 MUD，而是一款以经营、生活为核心的模拟游戏：种田、
  钓鱼、养殖、开工厂、买卖房地产、炒股、打麻将、抽奖样样俱全——
  `command player` 列出的完整指令表里能看到 `build`/`buildbridge`/
  `buildterrain`、`buy`/`sell`、`grow`、`land`/`occupy`、`estate`、
  `enterprise`、`labor`、`tax`/`levy`、`quest` 等，不是文案夸张。
- 配有完整的城市市长、税收、企业系统——新角色可以选择加入某个城市定居，
  体验经营与养成的乐趣，风格更接近生活模拟游戏而非传统砍杀 MUD。目前
  只有一座城市"廢棄都市"<Fallencity1>。
- `gocity` 进入城市地图后会触发一套即时渲染的自定义 ANSI 小地图系统：
  玩家坐标、地形类型、实时时钟、天气、方向罗盘全部动态显示——是这批
  档案里见过最精致的自定义终端 UI 之一，开机动画里报告 `CITY_D` 模块
  体积高达 1163KB，规模和这套系统的复杂度相符。
- 每次连线都会展示一段完整的模块加载动画，是这款游戏自己的特色开场；
  这段动画由 `system_d.lpc` 的 `distributed_preload()` 分批驱动，载入
  全部完成后会主动跟所有等待中的连线说"啟動完畢，重新連線中..."并主
  动断线，要求客户端重新连线——这是刻意的架构选择，不是崩溃（WASM 环
  境下这段动画耗时明显比原生驱动长得多，属于模拟层开销，不是这份档
  案的 bug）。
- 巫师账号从 loopback（本机）连线时会被自动导向巫师登录流程，需要把
  英文 ID 重新输入一次（第一次输入用来触发跳转，第二次才是巫师登录
  流程自己的 ID 提示），然后才是密码。
- 深度功能测试（见 `NOTES.md`）发现并修复了一个真实 bug：新角色的饮
  水状态被写进一个从未被任何代码读取的死键，导致饮水上限永远卡在
  0——每一个全新角色事实上永远不可能喝水成功。

## WASM 状态说明

早前的验证曾把这份档案标为 `noboot`：`system/kernel/simul_efun/ansi.lpc`
的 ANSI 颜色处理直接呼叫 `pcre_replace_callback()`/`pcre_replace()`/
`pcre_match_all()`，而这几个函数所在的 `simul_efun` 档案是开机时的必要
档案，当时的 WASM 版驱动完全没有打包 `pcre` package，导致
`fluffos_boot()` 直接失败、连测试用的连线记录都产生不了——这不是这份
mudlib 自己的 bug，纯粹是当时 WASM 驱动的能力缺口。本次重新测试时确认
`fluffos` 上游的 `docs/build-wasm.md` 已经记录 WASM 驱动现在打包了
`pcre`，用现在的驱动重新开机、完整走完注册流程、以及巫师账号登录，三
者都顺利通过，档案本身没有再改动任何代码。

## 深度功能测试新发现的 bug

`system/daemons/char_d.lpc` 的 `create_char()`/`create_npc()`（新角
色/NPC 建立时唯一执行一次的初始化函式）把饮水状态的键名写成
`stat/water/max`/`stat/water/cur`，`system/daemons/birthday_d.lpc`
的生日奖励逻辑也用同一个"water"键给饮水上限加成。但真正读写这项状
态的唯一实现——`std/inherit/feature/living/_attribution_liv.lpc` 的
`query_drink_max()`/`cost_drink()`/`add_drink()`，以及 `score` 面
板、真正的 `drink` 指令、心跳消耗逻辑——从头到尾用的都是"drink"这
个键。也就是说初始化写的是一个没有代码读取的死键，真正被读取的
`stat/drink/max` 从未被初始化，默认值 0，导致 `add_drink()` 的判断
条件对任何正数增量都恒成立——**每一个新角色的饮水上限永远卡在 0，
`drink` 指令永远不可能成功**。已把 `char_d.lpc`/`birthday_d.lpc` 里
的 `stat/water/*` 全部改成 `stat/drink/*`，和实际被读取的键名保持一
致。修复前后各建一个全新角色对照验证：修复前 `score` 显示"飲水
0 / 0"，修复后显示"飲水 0 / 100"，和食物的"0 / 100"对称。详见
`NOTES.md` 的"深度功能测试"一节。

## 在线试玩

https://mudlibs.fluffos.info/zsdsj/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`SECURE_D` 的最高等级）
- 授权方式：`system/kernel/data/secure.o`（SECURE_D 的存档）`wizards`
  映射中加入 `"fluffos":"admin"`。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/zsdsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40081**。
