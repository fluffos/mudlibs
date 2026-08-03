
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 huoying（Naruto.rar，044 号，可玩）是同一套 火影/Naruto ES2 代码库的第二份上传——按路径有 567/569 个档案重合，每一个重合但内容不同的档案差异都只是排版（大括号是否独立成行、注释缩进），已用去空白差异比对 adm/simul_efun/chinese.lpc、adm/obj/master.lpc、adm/daemons/securityd.lpc、adm/daemons/logind.lpc 确认没有功能性内容差异。仅 huoying 有的档案都是上一次会话留下的运行时 artifact（玩家存档、日志、mud.bat、trace_lpcc.json）。仅 hy2 有的档案是一个 Windows mudos.exe 二进制文件和一份下载站横幅文字档案（小熊泥苑.txt），都不是 mudlib 内容。没有尝试重建/单独跑一轮 WASM 修复——相对已经验证过的 huoying 没有任何净新增内容价值。
