# 西游记2003-2 (xyj20032)

档案名叫"西游记2003-2"，但游戏本身开机后自报家门是**三界神话（SanJie
Myth）「测试二区」**——和 059 `sjcs`、060 `sanjieshenhua`
是同一套"三界"代码库家族的另一个成员（`get_gender()`/`enter_world()`/
`make_body()` 等核心函式和 `sanjieshenhua` 逐字比对完全一致），开机横
幅还留着一段"西游记之新纪元"的 ASCII 字画，应该是更早一次改名留下的
痕迹。

## 内容亮点

- 档案名叫"西游记2003-2"，开机横幅也留着"西游记之新纪元"的 ASCII
  字画，但实际是三界神话（99-101、118 号等）家族的又一个"测试二
  区"分身，说明这份档案至少经历过一次改名／换皮，是本轮里名实最不
  相符的一个。
- 保留了"天地劫"系统事件广播（`disasterd.lpc` 的 `announce()`），
  游戏内会有跨全服的天灾/异变类事件通知，不只是常规聊天频道。
- 本次修复里最难定位的一个 bug 在这份档案：新角色选完性别后会**完
  全无声无息**地卡死（没有任何报错），根源是驱动内部编译玩家身体
  类别时，`master.lpc` 的 `valid_read()` 把"系统自身发起的加载请
  求"误判成了权限不足而拒绝——这个 bug 后来用
  `scripts/scan_known_bugs.py` 静态扫描确认在其它同源档案里也有类
  似的死代码残留（未加载，未修）。
- 深度功能测试（§10.7）发现一个此前从未被记录过、影响面极大的严重
  bug（新增 AGENTS.md §7.87）：表情精灵 `emoted.lpc` 自己的存档文
  件超过了这份档案 `config.fluffos` 里配置的读档大小上限，导致
  `restore()` 直接抛出异常而不是老实回传失败——每一次 `smile` 之
  类的表情指令、甚至 NPC 自己心跳驱动的闲聊都会崩溃，而且完全没有
  任何 `debug.log` 记录。

## 本次修复的关键 bug

这份档案一共踩中 4 个 bug，后两个完全没有任何可见的错误讯息，是靠在
`get_gender()`→`make_body()`→`new(USER_OB)` 这条链路上逐步插入
`write()` 断点，一步步二分定位出来的：

1. **§7.61 `message()` 精灵的 exclude 参数默认值 bug**：
   `adm/simul_efun/message.lpc` 的 `message()` 转接函式只传 3 个参数
   呼叫 `efun::message()`，第 4 个 `exclude` 参数落空成裸的整数 0，
   `adm/daemons/disasterd.lpc` 的 `announce()`（天地劫系统事件广播）
   等多处呼叫点因此崩溃报"Bad argument 4 to EFUN message()"。改成
   `exclude || ({})`。
2. **§7.60 `log_error()` 在 `CHANNEL_D` 还没预加载时呼叫它**：
   `adm/obj/master.lpc` 的 `log_error()` 对**每一条**编译警告（包括
   完全无害的"Unknown #pragma, ignored"）都会呼叫
   `CHANNEL_D->do_channel()`；开机时最早被预加载的几个档案编译产生警
   告的那一刻，`CHANNEL_D` 自己还没编译完成，这个跨物件呼叫会在"正在
   编译中"的状态下触发一次新的编译，被驱动拒绝并报"Object cannot be
   loaded during compilation"——然后这个错误本身又被 `log_error()` 再
   记录一次，如此循环，刷出成千上万行重复的错误堆叠。用
   `find_object(CHANNEL_D)` 判断守卫。
3. **`channeld.lpc` 的 `do_channel()` 对 `environment(me)` 没做保护**：
   上一条 bug 修好之前，`log_error()` 的 `CHANNEL_D` 广播会把
   master 物件本身当作"me"传进去——master 物件没有 environment，
   `environment(me)->query("no_chat")` 直接对 0 取属性崩溃。加上
   `environment(me) &&` 判断。
4. **最深的一个 bug——`master.lpc` 的 `valid_read()` 拒绝驱动自身发起
   的编译请求**：新玩家选完性别后，`get_gender()` 呼叫
   `make_body()`，`make_body()` 呼叫 `new(USER_OB)` 第一次编译完整的
   玩家身体类别（`std/char/char.lpc` 一大串 `F_*` mixin）。驱动内部
   的 `load_object()` 会先呼叫 `master_ob->valid_read(...)` 做权限检
   查，这次呼叫把 **master 物件自己**当作"user"参数传进去；这份档案
   的 `master.lpc` 的 `valid_read()` 原样把这个 `user` 转呼叫给
   `securityd.lpc` 的 `valid_read()`，没有对"系统自身发起的加载"做任
   何特殊处理，而 `geteuid(master_ob)` 在这个时机点算出来是空字串，
   权限判断逻辑因此判定"拒绝读取"——`new()` 静静地返回 0，
   `make_body()` 理论上该走的失败分支 `write()` 讯息由于目标是还没
   `exec()` 过的登入物件，实际上从未真正显示出来。结果是**每一次新
   角色注册在选完性别后都会无声无息地卡死**，之后所有输入都变成"什
   么？"，没有任何报错、没有任何提示。修法是在 `master.lpc` 的
   `valid_read()` 里加一条 `if (user == this_object()) return 1;`，
   放在转呼叫 `SECURITY_D` 之前。
5. **经典 §8.1 GBK 字节区间 bug**：`adm/daemons/chinesed.lpc` 的
   `is_chinese()`（按字节区间+奇偶校验判断）和 `adm/daemons/
   logind.lpc` 的 `check_legal_name()`（同样的奇偶校验假设）都改成
   逐码点检查（0x4e00–0x9fff）——这也是为什么"小浮侠"这样三个字的名
   字一开始会被拒绝的原因。

## 深度功能测试（§10.7）修复的 bug

- **管理员账号播种缺失**：上一轮 WASM 修复笔记声称已经把 `fluffos
  (admin)` 加入 `adm/etc/wizlist`，但实际检查存档只有 `rwz
  (admin)` 一行——这次补上了 `fluffos (admin)`。
- **printf 调试残留**：`adm/daemons/logind.lpc` 的 `get_name()`。
- **留言板 `post` 崩溃（AGENTS.md §7.86，第四次跨家族确认）**：全档
  案 99 份留言板文件都有同样的 `inherit` + 多余 `replace_program`
  致命形状（97 处 `BULLETIN_BOARD` + 2 处 `BBS_BOARD`）。已删除全
  部 97 处多余调用。
- **`emoted.lpc` 存档超限导致 `restore()` 抛异常（AGENTS.md
  §7.87，新发现）**：`data/emoted.o` 328298 字节，超过
  `config.fluffos` 原来 `maximum read file size : 300000` 的限
  制，`restore()` 因此直接抛出异常而不是回传失败，导致 `create()`
  里"失败就给空 mapping"的兜底逻辑根本没机会执行——`emote` 这个全
  局 mapping 永久停留在 `0`，让每一次表情指令、乃至 NPC 自己心跳驱
  动的闲聊都崩溃，而且完全没有 `debug.log` 记录。双管齐下修复：把
  读档大小上限提到 400000（和 `esI`/`mhxy`/`mhxyqd`/`sjcs`/
  `xiyouji2003`/`zzhj` 等档案的做法一致），并给 `create()` 加上
  `catch(restore())`，让它无论 `restore()` 是回传失败还是直接抛出
  异常都能正确兜底。

## 已知但非 bug 的测试摩擦：注册流程的 call_out(0) 竞态

角色创建完成后，天赋点数分配菜单是靠 `d/wiz/init.lpc` 的 `init()`
里一个 `call_out("get_start0", 0, me)` 延迟到下一个 tick 才触发的；
玩家身体类别（`std/char/char.lpc`）第一次编译的负担很重，会和测试用
客户端按固定 idle 秒数发送后续输入的节奏抢跑，导致偶尔卡在性别选择
之后。这和本次 WASM 通关测试里 `xhcii`/`xkyxciii`/`xsfyssjb` 已经记
录过的时序竞态是同一类问题，不是 mudlib 的 bug——已经用一次完全干净
的通关记录（从性别选择一路到 `look`/`score` 全程零报错，天地劫系统
事件正常广播、自动存盘正常触发）确认核心逻辑没有问题。

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: 注册时自设（账号密码 + 管理密码双密码机制，
  两者不能相同）
- **权限 / Level**: `(admin)`，通过 `/adm/etc/wizlist` 授予（
  `securityd.lpc` 真的会在开机时读取 `WIZLIST`）。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/xyj20032
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40119**。
