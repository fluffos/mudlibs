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
