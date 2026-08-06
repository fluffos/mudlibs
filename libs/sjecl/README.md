# 书剑恩仇录 (sjecl)

Century/adm-single 引擎家族的一支（`adm/single/master.lpc` +
`adm/daemons/securityd.lpc`，与 `sje`/`sjplgfjxb`/`sjplii` 等"书剑"
系列泥潭同源），以金庸小说《书剑恩仇录》为背景的重庆电信"书剑"泥潭。
WASM 阶段的"注册/look/score/quit 都干净"结论具有误导性——深度功能测
试（§10.7）发现注册完成后**任何玩家指令都会返回"什么？"，游戏事实
上完全无法操作**，详见下方"深度功能测试"一节。

## 内容亮点

- 新角色从"武馆前院"起步，两侧设有练武场，北面通往武馆大厅——是
  这批"书剑"系泥潭共用的经典新手区布局。
- 门派收录不限于《书剑恩仇录》原著：`ask shizhe about 拜师` 可以拜
  入武当、少林、星宿、华山、丐帮、神龙岛、昆仑、铁掌、古墓、慕容、
  桃花岛、天龙寺、大轮寺、嵩山、明教、峨嵋等十余个门派，横跨金庸
  绝大多数小说的门派体系，而非只围绕书剑恩仇录一部作品。
- "书剑天下礼物使者"NPC 是新手快速上手的捷径：`ask shizhe about
  newbie` 之后再报出想加入的门派名，即可一次性获得该门派整套武学
  （技能 201 级、识字 200 级、内力/精力上限拉满）与巨额初始经验，
  但每个角色只能使用一次。
- 地图以书剑恩仇录的江湖足迹为骨架，城镇场景包括长安、兰州、沧州、
  杭州、黄河、恒山、雪山等地。
- 巫师账号有独立的登录 IP 白名单机制（`adm/daemons/sited.lpc`），
  按 id 逐个授权，是这份档案自己的安全策略（详见下方管理员账号
  说明）。

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

## 深度功能测试（§10.7）修复的严重 bug

**注册流程本身完全正常**（欢迎信息、VIP 提示、新闻系统提示都正确显
示，角色也正确落地进游戏世界），**但落地之后任何一个玩家指令，包
括最基本的 `look`，都会返回"什么？"**——游戏事实上完全无法操作。
这个症状被埋在一长串正常的欢迎讯息后面，很容易被误认为是正常返回
而忽略过去。

根源是 AGENTS.md §8.3b 已经记录过的经典 bug：`adm/daemons/
commandd.lpc` 的 `rehash()` 用 `sscanf(cmds[i] + "$", "%s.c$",
cmds[i])` 从目录列表里筛出指令档案，但转档后所有档案都已经改名成
`.lpc` 后缀，这个模式永远匹配不到任何东西，指令表永远是空的。这份
档案之前在全库排查 §8.3a（`private nomask command_hook`）时就已经
被列为"已修复"——`command_hook()` 本身确实没问题——但 §8.3a 和
§8.3b 是两个完全独立的 bug，即使前者修好了，`command_hook()` 内部
呼叫的 `find_command()` 因为指令表是空的仍然对任何动词都返回 0，
一样导致每个指令都落空。已把 `"%s.c$"` 改成 `"%s.lpc$"` 修复。

修复前 `boot.log` 里还反复出现 `adm/daemons/baoshid.lpc`（随机放置
宝石/NPC 的精灵）的 eval 开销超限报错（一次会话 15 次），修好指令
表之后这个报错也完全消失了——很可能是空指令表导致每次按键都要
fallback 去尝试表情/频道系统的探测逻辑，间接给这个不相关的精灵造
成了额外编译压力。

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
