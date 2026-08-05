# 西游记2000 (xyj2000)

西游记（"Journey to the West"，又名"西游记之新纪元"），以吴承恩原
著为背景的一套老牌 MudOS mudlib，注册流程带有"不欢迎中小学生玩家"
的年龄声明问答，属于原始设计的一部分，不是 bug。

## 内容亮点

- 以吴承恩原著《西游记》为背景，三十三天、蟠桃园、蓬莱、天宫等地
  标齐全，和"三界神话"系家族地名风格相似但代码库完全独立。
- 这是 `scripts/scan_known_bugs.py`（本次会话新写的只读静态扫描工
  具）第一次派上用场的档案：常规的"注册+look+score+quit"通关测试
  完全没有踩到的 5 个潜伏 bug（详见下方"补充修复"），都是靠这个新
  工具事后扫描才挖出来的——包括一本特定藏经阁书籍的坏 include 路
  径、一个 NPC 档案里漏转的原始 GBK 字节。
- 注册流程里连锁出现过一个特别隐蔽的 bug：`preload` 文件里一个互
  联互通精灵的加载行被人为注释掉（大概率是有人在真正的 socket 兼
  容性问题修好之前，为了让整个 mudlib 能开机而留下的权宜之计），
  导致每一次连线选完编码后都会立即被动断线——根源在于开机预载状
  态，而不是编码选择本身（详见下方 bug 修复第 3 条）。
- 深度功能测试（§10.7）发现全档案 28 块留言板的 `post` 指令必然崩
  溃（AGENTS.md §7.86）——这是这个 bug 第三次在互不相关的代码库家
  族里被独立发现（此前只在"天涯"和"hy/海洋"两个家族见过），而且这
  次还发现了一个新变体：3 份留言板用的是另一个同样有问题的基类
  `BBS_BOARD`，不只是常见的 `BULLETIN_BOARD`。

## 本次修复的关键 bug

1. **`adm/daemons/convertd.lpc` 的字节级损坏**：GB/BIG5 转码用的
   `inittable` 初始数组，本应是每个元素一个符号的字符串数组，实际
   存档内容里大量元素被压成了一整行、符号之间互相粘连（和这批档案
   里 `sjsh` 系列同款的转档损坏），已用标准修复脚本按码位重新切
   分（约 45 行受影响）。
2. **`adm/daemons/network/dns_master.lpc` 的 §7.52 socket 依赖**：
   这是一个真正的多用途互联互通精灵（`query_mud_name()`/`muds`
   mapping 等被 `mudlist_a`/`mudlist_q`/`gtell`/`gchannel`/`rwho`
   等约 28 个其他服务文件呼叫），按 AGENTS.md §7.52 对多用途精灵的
   例外处理，**没有**整个文件停用：只把两个真正碰 socket 的入口函
   式掏空（`startup_udp()` 现在直接 `return 0`，正好符合它原本失败
   时的返回惯例，`create()` 里 `if (startup_udp())
   init_database();` 不需要改动就会自然跳过依赖 socket 的资料库初
   始化；`send_udp()` 变成空函式），并清掉了 `send_shutdown()` 里一
   处残留的 `socket_close()` 呼叫。
3. **由上一条引出的连锁 bug——`adm/etc/preload` 里 `dns_master` 被
   注释掉了**：这份档案的 `preload` 文件里 `#/adm/daemons/
   network/dns_master` 这一行被人为注释掉（原始压缩包里是启用状态；
   多半是有人在 socket 兼容性 bug 修好之前，为了让整个 mudlib 能开
   机而临时关掉的权宜之计），导致 `DNS_MASTER` 精灵永远不会在开机
   时被预加载。`adm/daemons/logind.lpc` 的 `encoding()` 在选完编码
   后第一次连线会检查 `if(!find_object(DNS_MASTER) || ...)
   shutdown(1);`——`find_object()` 只对已加载的对象返回真，精灵没
   被预加载所以这个检查恒真，**每一次连线都会在选完编码后立刻触发
   `shutdown(1)`**，导致注册流程在编码选择之后彻底卡死（所有后续
   输入都显示"什么？"）。这不是编码选择本身的 bug，是 `shutdown(1)`
   调用之后连线对象再也没有注册任何 `input_to()`，所以后续输入落
   进了没有挂钩的通用解析器。既然 §7.52 的编译修复已经让
   `dns_master.lpc` 能正常载入，把 `preload` 里那一行重新启用即可，
   不需要改动 `logind.lpc` 本身的检查逻辑。

## 深度功能测试（§10.7）修复的 bug

- **printf 调试残留**：`adm/daemons/logind.lpc` 的 `get_name()` 里
  有一处 `printf("%O\n", ob)`，每次注册都会把整个玩家对象的原始引
  用打印到连线画面上（和"天涯"/"hy"两个家族里已经修过的同款泄漏一
  样）。已删除。
- **留言板 `post` 崩溃（AGENTS.md §7.86）**：全档案 28 份留言板文
  件都同时 `inherit` 一个留言板基类又多余地对自己
  `replace_program()` 成同一个类，导致 `post` 指令必然崩溃。其中
  25 份用的是常见的 `BULLETIN_BOARD`，另外 3 份（`xyj_b.lpc`、
  `menpai_bbs.lpc`、`query_bbs.lpc`）用的是一个此前没见过的变体基
  类 `BBS_BOARD`（`/std/bbsboard.lpc`），同样的致命形状。已删除全
  部 28 处多余调用，live 验证过两块不同的留言板 `post` 都能正常保
  存。这是 §7.86 第三次在互不相关的代码库家族里被独立发现，已更新
  AGENTS.md 记录这个跨家族确认。
- **§8.9 确认不适用**：这份代码库的食物/饮水初始化本来就是无条件
  执行，没有任何年龄判断包装，不存在错对象年龄检查的问题。
- **死亡/复活流程确认正常**：`d/death/npc/pang.lpc`（"朱笔判官 崔
  珏"）的判定守卫是标准的 `if (!ob || !present(ob)) return;`
  （AGENTS.md §7.68，现已收窄到仅 `bmxkx2001` 适用），未做任何改
  动；确认其 `init()` 没有 `hy2000` 那次发现的 `wizardp()` 排除判
  断，管理员测试账号可以正常走完整个复活流程——现场验证五阶段对话
  全部播放、`reincarnate()` 正确执行、送到"荒郊小店"复活，系统本
  身没有问题。

## 补充修复（静态扫描工具发现的潜伏 bug）

本次会话新写了 `scripts/scan_known_bugs.py`（一个只读静态扫描工具），
对已经标记 playable 的档案回头扫了一遍，抓到 5 个原本的"注册+look+
score+quit"通关测试没有踩到的潜伏/延迟加载 bug：

- `d/obj/books-nonskill/book-qujing.lpc` 的绝对路径
  `#include </d/qujing/obstacle.h>`（读这本书才会触发，改成双引号）。
- `logind.lpc` 的 `check_legal_name()` 有标准 §8.1 的 `i%2` 奇偶校验
  + `[i..<0]` 后缀切片写法——这份档案因为 `is_chinese()` 恰好只检查
  第一个字符所以没有实际造成拒绝，但还是按标准逐码点写法修正，保持
  一致性和稳健性。
- `master.lpc` 的 `valid_read()`/`valid_write()` 原样转呼叫
  `SECURITY_D`，没有 `user == this_object()` 的短路判断——这正是让
  同宗档案 `xyj20032` 每一次新角色注册都在选完性别后静默卡死的那个
  bug（详见该档案的 README），这里虽然没有被实际触发，还是提前补上
  同样的防御。
- 3 处 `is_killing(me)` 传对象给宣告成 `is_killing(string id)` 的函
  式（§7.50，`daemon/class/dragon/dragonforce/roar.lpc`、`daemon/
  class/yaomo/kusong/huomo/fire.lpc`、`cmds/std/surrender.lpc`）。
- `d/sky/npc/zz-tianwang.lpc` 还是原始 GBK 字节，最早那一轮批量转
  码没有转到，用 `iconv -c -f GB18030 -t UTF-8` 补转。

另外还发现并修复了 `adm/simul_efun/message.lpc` 的 `tell_room()`
把未设定的 `exclude` 直接传给 `message()` 第 4 个参数的 §7.12 bug
（`exclude || ({})`）。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（
  `adm/daemons/securityd.lpc` 真的会在开机时读取 `WIZLIST`），登录
  后自动显示"目前权限：(admin)"确认生效。

> 警告：对外公开架设前请务必修改此密码。

## 注册流程提示（供后续测试参考）

编码选择（`gb`/`big5`）之后会先问"您是否是中小学学生或年龄更小？
(yes/no)"，答 `no` 才能继续到英文 ID 提示；新玩家在英文 ID 提示处
键入 `new` 才会进入取中文名字/设密码/设 email/选性别的完整创角流
程；创角最后一步是天赋点数分配菜单，键入 `9` 接受默认值后还会有一
次 `[y/n]` 二次确认。

## 本地运行

```
cd libs/xyj2000
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40155**。
