# wlqxcmudlib（武林群侠传 MUDLIB）-- porting notes

Archive `武林群侠传MUDLIB.7z`（编号 931）7z 头加密，档尾有一段明文 GBK：

```
MUD
游戏QQ群：9783836
解压密码： mud.ren
```

`7z t -p'mud.ren'` Everything is Ok。`Lib/` 是完整的炎黄/武林群侠传引擎（`adm/single/master.c`，与 `yanhuangwuhun` 同一 yh 2003 头）。

`convert_lib.sh … GB18030`：already_utf8=476 converted=10572 lossy=8 skipped_binary=15；10265 个 `.lpc`。端口 **40268**。

运行时补了 yh 血统两处（与 `yanhuangwuhun`/`zhyx` 相同）：

1. `adm/daemons/versiond.lpc`：`get_config(__MUD_PORT__)` 在这个驱动上是字符串，`socket_bind()` 要 int，加 `to_int()`。
2. `adm/simul_efun/message.lpc`：第四参 `exclude==0` 不能直接丢给 efun（§15s），按有无 exclude 分两路。

注册路径还要 §15h 的 UTF-8 姓名检查：`adm/simul_efun/chinese.lpc` 的
`is_chinese()`、`logind.lpc` 的 `check_legal_name`/组合长度、
`named.lpc` 的 `PATH()` 与滑动窗口，都从「GBK 字节」改成「汉字字符」。
管理员 `fluffos` 已写入 `adm/etc/wizlist`。

`clone/user/user.lpc` 的 `accept_kill()` 把 object 传给
`is_killing(string)`，本树的 `feature/attack.lpc` 没有 yanhuang 那份
`mixed` 签名，user 物件编不过，新号 `make_body` 失败、指令全是「什么？」。
改成 `is_killing(ob->query("id"))` 后，`qinfeng`/秦风 走完整注册进
世外桃源（水笙、狄云在场）。`logind.lpc` 的 `MESSAGE_D->find_chatter`
也加了 `find_object` 保护。

## 商店付费购买（2026-09-04 librarian shop slice）

手足 `yanhuangwuhun` 2026-09-03 的路径可套：醉仙楼买烤鸡腿、丐帮黎生拜师。
本轮注册了真正的 admin `fluffos`/`Mud@2026`（登录密码 `Play2026x`，中文名
云游）。第一行就是英文 id，没有 GB/Big5 选择。落地世外桃源
`/d/register/entry`，`register test@example.com` + `decide` + `west`
花铁干（阴险奸诈）+ `out` 阎罗殿，`washto 20 20 20 20`，`born 扬州人氏`
进扬州客店 `/d/city/kedian`。提示是每秒时钟（`env/prompt` = time），
`mudclient.py` 用 `--idle 0.4`–`0.6`。`help/rules` 仍是生 GB18030，分页
打断第一次 look，是 yh 血统已知内容缺口，不是本轮新 bug。

### 修了两处真编程 bug

1. **`goto` 第一次触发 `MESSAGE_D` 崩溃**（AGENTS.md §7.89 形状）：
   `/adm/daemons/network/messaged.lpc` 的 `create()` 写
   `my_port = LOCAL_PORT() + MESSAGE_PORT`，`LOCAL_PORT()` 是
   `(int) get_config(__MUD_PORT__)`，这个驱动上 `get_config` 回字符串，
   `(int)` 不强制转换，`"" + 10` 变成字符串 `"10"`，`socket_bind()` 报
   `Expected: int Got: "10"`，整条 `goto` 中止。本树 `versiond.lpc`
   进口时已经用 `to_int(get_config(__MUD_PORT__))` 修过，`messaged`
   漏了。已改成同样的 `to_int`，`socket_bind` 两处也包 `to_int(my_port)`，
   `send_udp()` 加了 `!socket_id` 守卫。修复后 `goto /d/city/zuixianlou`
   干净落到醉仙楼。

2. **`clone` 因 `/log/nosave/` 不存在崩溃**（§7.11）：
   `adm/simul_efun/file.lpc` 的 `log_file()` 直接 `write_file(LOG_DIR +
   file)`，没有 `assure_file()`。巫师 `clone /clone/money/gold` 写
   `/log/nosave/clone` 时报 `Wrong permissions ... No such file or
   directory`，物件没变出来。已加 `assure_file` 前向声明并在写入前建
   目录。修复后 `clone` 回「黄金复制成功」，`i` 见到一两黄金。

本机 `debug.log` 这轮没打开（`log directory : /log` 是绝对路径，驱动
cwd 进 work 之后没有对应 fd）。运行时错误当时打在玩家屏幕上。

### 商店

`goto /d/city/zuixianlou`，店小二 `list` 给出牛皮水袋/干粮/包子/烤鸡腿
（八十文铜板）/烤鸭/牛皮酒袋。`clone /clone/money/gold` 后 `buy jitui`
live 回「你从店小二那里买下了一根烤鸡腿」。`i` 为九十九两白银 +
二十文铜钱 + 烤鸡腿 + 零两黄金。扬州客店的 `list` 会先打到北丑（只卖
消息），要用醉仙楼的店小二。

### 拜师（2026-09-04 续：`command_hook` §8.3a）

同一次 wakeup 里先确认不是 `living()` 缺口：`call li->query_commands()`
已经登记了 `command_hook`（`""`, flag 1）和 path `{/cmds/std/, /cmds/skill/}`，
`bai li` 也确实进到了 `attempt_apprentice`。`f li to say` 却回「黎生无法执行你的命令」。
手足 `yanhuangwuhun` 已经是 `nomask int command_hook`（没有 `private`）。

根因是 AGENTS.md §8.3a：`feature/command.lpc` 的
`private nomask int command_hook` 被 inherit 后降成 `DECL_HIDDEN`。玩家手打
动词走 `ORIGIN_DRIVER`，NPC `command()` efun 走 `ORIGIN_EFUN`，apply 静默回 0。
本树是 2026-09-04 进口的，corpus sweep 之后才进来，所以还带着 `private`。

已改成 `nomask int command_hook`（只去掉 `private`）。重启后：

- `f li to say 测试说话` → `黎生说道：测试说话`
- `bai li` → nod + `我便收你为徒…` + `决定收你为弟子` + 磕头 +
  `恭喜您成为丐帮的第二十代弟子`
- `score` → `【 小叫花 】丐帮第二十代传人` / `师父是黎生`

商店切片上一轮已经付费买过醉仙楼烤鸡腿，本轮没有重做。
