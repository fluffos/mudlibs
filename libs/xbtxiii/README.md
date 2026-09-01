# 雄霸天下III

这是一个真正的1997-2001年代 mudlib，据其自带 readme 承认，这其实是一次刻意的拼接：地图大部分区域借自 ES2、XKX 和风云等既有档案的地盘，只有一处原创区域——一座受小说《魔法师日记》启发、意在做"中西合璧"实验却因团队失去服务器而中途搁置的迷雾岛（本项目另一档案 ldtx 虽然同样打着"雄霸天下"的招牌，但经比对只与本作有较远的 ES II 共同祖先，并非同一血统）。角色创建混合了西式 MUD 的职业体系与中文武侠包装：选定性别后要从 A-L 共12种属性类别里挑一种，再从英文拼写的 `enchanter`（魔法师）/`fighter`（武士）职业里二选一。据作者自述，战斗系统是本作最大特色：战斗在3x3/5x5/7x7的战术网格上展开，讲究站位与法术射程的距离判定，比常见的"同一房间对砍"更有战术性。死亡后的鬼魂流程写得格外完整：鬼门大道→奈何桥→酆都城门→森罗殿→地狱入口，五段场景全程由"白无常"陪同念白，最后由阎罗王亲自判定阳寿未尽，送回阳间。

## 注册流程

`new` 触发注册 → 英文 id（3-10 个英文字母，游客请用 `Guest`）→ 确认
创建（y/n）→ 中文名字（1-6 个中文字）→ 密码 → 确认密码 → 性别（m/f）
→ 电子邮件地址 → 人物属性类别（A-L，12 种任选一）→ 天赋确认（Y/N）
→ 职业选择（`enchanter` 魔法师 / `fighter` 武士，英文拼写）→ 职业确认
（y/n）→ 进入一个简短的新手教程房间，再走到真正的起始区域。

## 内容亮点

- 地图里能看到"雪"（`d/snow/`、`d/dsnow/`）、"冰火"
  （`d/icefire/`）、"红/绿"（`d/red/`、`d/green/`）等偏向意象化、
  而非地理写实的场景命名，和常见的"长安/洛阳"式城池命名习惯不同。
- 原始压缩包本身就是分卷 zip（4 部分）套 12 个按目录拆开的
  tar.gz，不是扁平目录树，转换前需要先拼接解压。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，已改为按字符数
  （1-6）+ 逐字符 `is_chinese()` 判断。
- `adm/daemons/network/dns_master.lpc`（互联 UDP daemon）和
  `adm/daemons/network/smtp.lpc`（原始 SMTP 发信 daemon）都无条件调用
  `socket_*` efun，导致各自整个文件编译失败——前者会让**每一次连线**
  的登录都静默卡死（启动流程会间接触碰它），后者会让 `natured.lpc`
  的周期性检查报错。均已按 AGENTS.md §7.52 的模式把涉及 socket 的函
  数体清空为 no-op。
- 缺失的 `/topten/` 目录导致 `toptend.lpc` 在每次角色进入游戏世界时
  存档失败崩溃，已 `mkdir -p` 补上。
- `cmds/usr/score.lpc` 里 `100*.../EXPLORE_D->query_total_explore()`
  未做零值防御——在探索数据尚未被任何人扫描过的全新安装上，
  `query_total_explore()` 合法地返回 0，导致 `score` 指令必崩，已加
  三元判断防御。

以上均为 WASM 阶段修复。以下为 §10.7 深度功能测试（实际注册+移动+
留言板+战斗+死亡复活全流程游玩）新发现并修复的 bug：

- `adm/daemons/logind.lpc` 的 `get_kind()`：属性类别选择提示写着大写
  `(A,B,...,L)`，实际校验却只认小写，照提示打大写字母反而被拒、卡
  在死循环里——已在校验前加 `lower_case()`（AGENTS.md §8.12）。
- `cmds/std/fight.lpc`：NPC 婉拒"讨教/切磋"挑战时，该显示的
  `notify_fail()` 提示因为同一分支后面接着 `return 1`（成功）而永
  远不会显示，玩家只能看到自己喊出的挑战台词后一片死寂——已改为
  `return 0`，让排队的提示正常显示（AGENTS.md §7.95）。
- `config.fluffos` 的 `maximum evaluation cost` 从本项目常见的默认值
  `700000` 提到 `5000000`——后台 `taskd.lpc` 扫描任务目标时懒编译
  少林寺一个从未被玩家造访过的房间/NPC，曾在纯游玩过程中触发一次
  `cost limit reached` 中断（AGENTS.md §7.90 追加实例）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/xbtxiii/

## 本地运行

```
cd libs/xbtxiii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40201**。
