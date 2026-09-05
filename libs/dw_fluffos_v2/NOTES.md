# dw_fluffos_v2（Discworld bundle v2）-- porting notes

`archives/901-1_dw_fluffos_v2_dw_fluffos_v2.zip` 是 Cratylus「Discworld
Bundle」三份快照的中间一份。捆绑的 `fluffos-2.9-ds2.05/` 驱动按 §2
惯例忽略；mudlib 根是 `dw_fluffos_v2/lib/`。

原先标 `deprioritized`。按用户指示单独转换，不把 v3 的 `work/`
当静默 overlay。

`convert_lib.sh … GB18030`：already_utf8=5932 converted=31 lossy=1
skipped_binary=504；2016 个 `.lpc`。lossy 同样是
`doc/concepts/conversions`。

机械修复与 `dw_fluffos_v1` 相同（virtual.h、`add_method("lpc")`、
76 个 `.ob` `#Class`、`command.lpc` `[0..<5]`、四个 `__FILE__` 切片、
五处 `add_action` 万能动词）。详见 `libs/dw_fluffos_v1/NOTES.md` 与
`libs/discworld/NOTES.md`。

开机阻断修复与 `dw_fluffos_v1` 相同。端口 **40272**。编号 **901-2**。
已确认开机并出现与 v1 相同的南瓜菜单登录界面。

## 商店切片预备（2026-09-04）

与 v1 同一天从 v3 补移植了两处会挡商店路径的程序 bug（尚未在
40272 上 live 走买）：

- `std/living/living.lpc` / `global/wiz_file_comm.lpc`：`command()`
  前向声明 / `::command` 覆盖包进 `#if !efun_defined(add_action)`，
  避免本驱动上 `room_look()` 走门报 `Undefined function called:
  command`（v1 已 live 复现并修，见 `libs/dw_fluffos_v1/NOTES.md`）。
- `global/newbie_junk.lpc`：先发 8 Pumpkin dollar + 100 Pumpkin
  pence，再对 `ARMOURY->request_item` / clone 返回值判空。

下一轮应直接开机 40272 做 pumpkin-menu 注册 + `commerce` `list` +
`buy a lightable torch`（不要再从零挖 command() 阴影）。

## 商店切片（2026-09-04）

端口 **40272**。`command()` 阴影与 newbie_junk 先发钱已在树里，本轮
不再重挖。冷启动后南瓜菜单 `N` 注册 `buylite` / `Play2026x`，条款
约 30 秒后 `yes`，落到 foyer。`commerce` 立刻打出商店房间（无
runtime error）。

同一会话只发一条 `buy a lightable torch`，回执：
`You buy a lightable torch for 50 Pumpkin pence coins.`

### 发现并修复的 bug

**档案从未附带 `/save/money_handler.o`。** handler 的 `create()`
只内置 provincial `default`（brass/copper/silver/gold/platinum）。
新手钱是 `Pumpkin dollar` / `Pumpkin pence`，商店 `place` 是
`"Newbie Area"`，`query_value_in("Newbie Area")` 与
`query_value_in("default")` 对这两种币都是 0。玩家有钱对象（所以
不是 "You have no money"），但买任何标价物品都走
`$I costs too much.`——上一轮 `shopvtwo` 已 live 打到这一句。
`doc/concepts/currency` 写明 Newbie Area 用 Pumpkin 币；比值取自
本树 `/d/dist/pumpkin/money_symboliser`（P$1 == 100，即 dollar=100、
pence=1）。`create()` 在两处 place 表都缺失时补上这两行，并挂上
同一 symboliser。8 dollar + 100 pence = 900，torch `set_value(50)`，
成交 50 Pumpkin pence。

本轮 `work/log/runtime` / `catch` / `error-log` mtime 对应当次开机
（`debug.log` 仍因 `log directory : /log` 是死的）。没有
`Undefined function called: command`。没有拜师（distribution 公会
内容未随包）。
