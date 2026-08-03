
## WASM 修复摘要（迁移自 meta.json 的 group_note）

基于 LIMA mudlib 底座——驱动拒绝启动它（check_config.lpc 自己的自检要求 NO_LIGHT/NO_ADD_ACTION/NO_WIZARDS/ARRAY_RESERVED_WORD/undef OLD_ED/undef PACKAGE_UIDS，本项目共用的驱动构建一个都不满足）；需要单独编译一份 LIMA 专用驱动，超出源码层面修复的范围。
