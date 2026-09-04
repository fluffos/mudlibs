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
