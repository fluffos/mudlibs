# dtxyzjb（大唐西游指间版）-- porting notes

Archive `大唐西游指间版.rar`（编号 930）是带注释的加密 RAR：

```
地狱玩家服群号：676036579
密码：676036579
```

`unrar t -p676036579` 全档 All OK。与空状态的 GitHub `dtxy`（duplicate_of `dtxywzxzb`）不是同一份档案；这是 2009「指间版」完整 mudlib（`大唐西游2009/`，`master file : /adm/obj/master`）。

`convert_lib.sh … GB18030`：already_utf8=1199 converted=14582 lossy=595 skipped_binary=25；13469 个 `.lpc`。lossy 偏高（不少 `death/npc`），登录提示里 BIG5 那一行有乱码。端口 **40267**。

这是「指间」手机网关版：`logon()` 先写 `ver1.0,<crypt>` 再
`input_to("jiance")`。普通 telnet 发任意非网关密文就会落到 `get_id`
（不是先选 gb）。`preload` 里 `/adm/daemons/convertd` 编不过（No
program），不挡 telnet 登录。`is_chinese()` 已改成 Unicode 码点检查。
`adm/etc/wizlist` 加了 `fluffos (admin)`。
