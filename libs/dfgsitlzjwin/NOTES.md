
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 esI（008-1，"屠龙之战"）、es1_win（008）是同一个 ES/TMI 引擎血统——文件重合度 91%（2092/2305），adm/obj/master.lpc 几乎完全一致（只有空白/注释差异），213 个不重合的档案里没有任何独有的游戏内容（几乎全是 .old/.c~/.bak 编辑器备份垃圾）。这份 WIN98 档案整个缺失 include/ 目录（没有 globals.h，没有 config.h——config.fluffos 的"global include file : <globals.h>"指向的档案在这份快照里根本不存在，不只是改名了而已，参见 §7.45），导致所有档案都编译失败（"Cannot #include globals.h"）。既然 esI 是同一款游戏完整、已可游玩的版本，为一份严格意义上冗余、更小、更不完整的快照去重建约 30 个缺失的头文件、冒着借用宏定义出错的风险并不划算——标记为 noboot 而不是"与某档案字节相同的重复档案"，因为压缩包本身不同，只是游戏内容相同。
