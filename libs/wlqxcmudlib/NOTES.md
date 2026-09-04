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
