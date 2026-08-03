
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib，游戏内标题为"江湖风云II 之 辽宁风云再起"（Jianghu Fengyun II）。异常干净：完全没有发现 mudlib 代码 bug——宏本来就和 config.fluffos 一致，is_chinese()/check_legal_name() 本来就是正确的码点判断，指令表开箱即用，也没有 this_player()/previous_object() 覆盖问题。完整的注册→look→score→quit 流程第一次真实尝试就顺利跑通。唯一需要做的是管理员播种：把 fluffos/loginpass1 加入既有的 CRLF 格式 adm/etc/wizlist，游戏内"★ 您目前权限：(admin)"显示确认生效。排版格式化后也重新验证过完整流程。格式化工具发现 2 个真正损坏的档案（d/huashan/map.lpc，一张 ASCII 地图，和手足档案里见过的同一种分词器混淆模式；d/player/fyue_room.lpc，一段房间描述）——两者都用 git checkout 还原。d/city/sj.lpc 有和 ffxymud 完全相同路径下那份档案一样的、转档之前就存在的、无法到达的缺引号损坏——未修，不是格式化工具造成的。
