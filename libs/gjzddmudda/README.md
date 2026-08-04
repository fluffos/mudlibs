# 国家制度的MUD DA

一个 ES2 血统的 MUD（作者自己在横幅中致谢 Annihilator/ES2），游戏内
标题为"葫芦Ⅱ / Demon Angel"（泥潭中国简化版本）。

## 内容亮点

- 档案名"国家制度的MUD"名副其实：`cmds/king/`（`abdicate` 退位、
  `appoint` 封官、`set_tax` 收税、`teleport` 传送）和 `cmds/min/`
  （大臣指令：`declare` 宣战、`ally` 结盟、`arrest`/`banish` 抓捕/
  放逐、`build`/`develop` 建设、`war_score`/`kingdom_stat` 战绩与国
  力统计、`pool_gold` 国库）构成一整套玩家可操作的国家经营系统，
  在这批档案里是独一无二的治国玩法。
- 大臣指令里还有 `makeroom`/`linkroom`/`set_room`/`set_short`/
  `set_long` 这类房间建造工具，意味着国家的领土场景可以由玩家（大
  臣）在游戏内直接建造、连接，而不是完全预先写死的地图。
- `d/ship/`/`obj/ship`/`std/ship` 提供船只玩法，`d/gourd/`（葫芦）
  对应游戏内标题"葫芦Ⅱ/Demon Angel"，有专属的"选择职业"
  （`choice_class.lpc`）和"购买国家"（`buy_kingdom.lpc`）流程。
- 死亡/复活系统的实现方式在本项目已处理的 ES2 血统档案里独树一
  帜：不是常见的"判官/无常"式多阶段对话链，而是单次 `call_out`
  到点无条件把玩家从死亡室移回重生点，结构上不存在其它档案常见的
  §7.68 复活软锁死风险。

## 注册流程

英文名字（3-12 个英文字母）→ 确认建立（y/n）→ 中文名字（1-6 个中
文字）→ 密码（≥5 字元）→ 确认密码 → 电子邮件地址 → 性别（m/f）。

## 本次修复的关键 bug

没有发现任何需要修改的 mudlib 代码——在 WASM 下开箱即用。这个档案
的 `is_chinese()`/`check_legal_name()` 本来就是正确的 Unicode 码点
判断，不像本次处理的其他大部分 ES2 血统档案那样有旧版 GBK 字节假
设的问题。

## 深度功能测试新发现的 bug（§10.7，2026-08-04）

- **§7.34 printf 调试泄漏**：`adm/daemons/logind.lpc` 的
  `get_name()` 里有一行遗留的 `printf("%O\n", ob);`——每个新玩家刚
  输完中文名字，就会在自己屏幕上看到连线对象的原始调试信息。已删
  除。
- **原始档案自带的字符串损坏**：`adm/daemons/chard.lpc` 骸骨命名
  `"一具枯\干的骸骨"` 中间多了一个游离反斜杠（对照 raw 归档字节确
  认是原始压缩包自带的损坏，不是本项目转码引入的），编译时报
  `Unknown escape sequence`。已改回"一具枯干的骸骨"。
- 死亡/复活系统读代码确认结构上不存在 §7.68 的复活软锁死风险（见
  上方"内容亮点"）；`food`/`water` 初始化被注释掉是原作者成组精简
  掉的功能，不是 §8.9 的错误对象判断，未改动。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建。这个版本的 `logind.lpc` 把"目前权限："+ wizhood() 的
状态显示行注释掉了（死代码），所以游戏画面上看不到明确的权限提
示——但 `adm/etc/wizlist` 的格式已经对照 `securityd.lpc` 的解析逻辑
核实过，和本次处理的其他所有 ES2 血统档案完全一致。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/gjzddmudda
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40122**。
