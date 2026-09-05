# dw_fluffos_v1（Discworld bundle v1）-- porting notes

`archives/901_dw_fluffos_v1_dw_fluffos_v1.tar.gz` 是 Cratylus「Discworld
Bundle」三份快照里最早的一份。捆绑的 `fluffos-1.22c11/` 驱动按 §2
惯例忽略；mudlib 根是 `dw_fluffos_v1/lib/`（`master file :
/secure/master`）。

原先标 `deprioritized`，只留 `scripts/non_mudlib_meta/dw_fluffos_v1.json`。
按用户指示单独转换，不把 v3 的 `work/` 当静默 overlay。

`convert_lib.sh … GB18030`：already_utf8=5945 converted=31 lossy=1
skipped_binary=509；2016 个 `.lpc`。lossy 是
`doc/concepts/conversions`（与 v3 相同的 Mac Roman 遗产，见
`libs/discworld/NOTES.md`）。

从 v3 已验证过的机械修复原样移植到这份独立转换树上（不是拷
`libs/discworld/work/`）：

1. `global/virtual/virtual.h`：`#include "virtual.h"` 改回
   `#include <virtual.h>`（convert_lib 本地尖括号启发式自包含）。
2. `global/virtual/server.lpc`：`add_method("lpc", …)`。
3. 76 个 `.ob` 的 `::#Class:: "….c"` → `.lpc`。
4. `secure/command.lpc` 指令名切片 `[0..<3]` → `[0..<5]`。
5. `obj/{armour,clothing,shield,clothing_transport}.lpc` 的
   `__FILE__[0..<3]` → `[0..<5]`。
6. 五处 `add_action(fn, "*", …)` 改成这个驱动认的 `""` 万能动词；
   living/psoul 第三参改成 `V_NOSPACE`（2）。

另外从 v3 移植的开机阻断修复：

- `secure/simul_efun.lpc` 恢复 `multiple_short` inherit；
  `modified_efuns.lpc` 也直接 inherit，避免 `query_multiple_short`
  先有鸡先有蛋。
- `global/psoul.lpc` 的 `time_expression{}` `#if`/`#else` 闭合不对称。
- `global/wiz_channels.lpc` 命名 lambda 里的 `$1` 改成 `ob`。
- `obj/handlers/armoury.lpc` 对缺失目录的 `foreach` 空指防护。
- `secure/config/preload` 注释掉 `/net/intermud3/intermud`。

端口 **40271**。编号 **901-1**。已确认开机并出现南瓜菜单登录界面
（N/G/角色名）。客串角色创建能走到条款页；完整 look 还要按 v3 那样
把条款 more 翻完。

## 商店切片（2026-09-04）

英文 Discworld：shop/buy 是本轮角度；没有拜师。端口 40271，
`~/src/fluffos/build-debug/src/driver config.fluffos`。`config.fluffos`
的 `log directory : /log` 是文件系统绝对路径，本机没有 `/log`，驱动
`debug.log` 对本 boot 是死的（fd 里没有 log 文件）。以 mudlib 自己的
`work/log/runtime` / `work/log/catch` / `work/log/error-log` 为准。

南瓜菜单 `N` 注册（`shopdive` / `torchbuy` / `torchbee`，密码
`Play2026x`），30 秒条款后 `yes`，落到 `/d/liaison/NEWBIE/foyer`。
`commerce` 进新手商店 `/d/liaison/NEWBIE/shop`。

### 发现并修复的 bug

**`std/living/living.lpc` 无条件前向声明 `protected mixed
command(string)`，在这个驱动上把真正的 `command()` efun 阴影成空的
`FUNC_UNDEFINED`。** `global/psoul.lpc` 里真正的 `command()` 定义包在
`#if !efun_defined(add_action)` 里，本驱动有原生 `add_action`，所以
那个定义被编译掉。玩家对象只剩一个空槽。live：第一次进 `commerce`
门，`exit_move` → `room_look()` → `command("look")` 报 `*Undefined
function called: command`（`work/log/runtime` 17:14:17），玩家侧
"A runtime error occurred."，随后心跳停、指令全部 Queued。登录时
`move_to_start_pos()` 同一条也崩过一次（17:14:04）。这就是 v3
2026-08-27 笔记里把 shop `list` 标成"排队显示时序问题、未完全验证"
的根因——不是 soul 时序，是每次走门 `room_look` 都炸。修法与 v3
已有的同一处 guard 相同（import 时没移植过来）：把前向声明也包进
`#if !efun_defined(add_action)`。`global/wiz_file_comm.lpc` 的
`::command(txt)` 覆盖同样在本驱动上编不过
（`Unable to find the inherited function 'command'`），一并
#ifdef 掉。修复后冷启动：`commerce` 走门立刻打出商店房间描述，
`runtime` 不再出现 `command` 未定义。

**`global/newbie_junk.lpc` 的 `start_player()` 对
`ARMOURY->request_item("bucket small")` 返回值不判空，链式
`bucket->set_short(...)`。** 这份 distribution 缺 `/obj/clothes/` 等
内容目录，`request_item` 常返回 0（v3 §7.147 同类）。第一次注册的
`shopdive` 走到商店后 `money` 是 "You are flat broke."——启动礼包里的
8 Pumpkin dollar / 100 Pumpkin pence 在崩溃点之后，根本没发出去。
修法：先发钱，再对 armoury/clone 返回值逐段判空。修复后新角色
`torchbuy`/`torchbee` 登录即
`Your purse contains 8 Pumpkin dollar coins and 100 Pumpkin pence coins.`

### 已验证的商店路径

- 商店 `list` live 出货：`You find on offer: Our very last small
  bucket. Three lightable torches. Two large buckets.`（更早一次还有
  `Three medium buckets`）。武器/防具/衣服目录缺失，store.lpc 的
  `request_weapon`/`request_armour`/`request_clothing` 已经有判空，
  货架上只剩本地 clone 的桶和 armoury 能造出来的 torch。
- `buy dagger` → `Cannot find "dagger", no match.`（货架上没有）。
- `buy torch` → `There are multiple matches for "torch".`（要写成
  `buy a lightable torch`）。
- 走门 `commerce` 在 command() 修复后不再 runtime error。
- 本 lib 的 `no_time_left()` 会在登录时把指令队列耗尽，心跳大约
  十几秒才吐一条 Queued 指令；再叠加 net-dead 雕像
  （"X leaves the game"）会再次停心跳。同一会话里钱和 list 都确认过；
  把 `buy a lightable torch` 排进队列后断开，paid 成交回执被心跳/
  net-dead 吃掉，没有在同一条 transcript 里看到 "You buy" 成功句。
  不是商店代码再崩，是测试节奏 vs Discworld 指令队列。

没有拜师（distribution lib 公会内容未随包，见
`libs/discworld/NOTES.md` 2026-08-27）。
