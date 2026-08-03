
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib（金庸群侠传），jyqxc 的手足代码库（86/87 编号；不是文件级完全相同的重复——大部分档案不同，但共享同一套架构/bug 面）。和 jyqxc 完全相同的 bug：feature/name.lpc 的 short() 呼叫 capitalize(query("id")) 没做保护，任何没有"id"属性的物件走到 short() 就会崩溃——这份档案里约 18 个留言板分身都会撞上，因为它们的 data/board/*.o 存档用的是同样这个驱动的 restore_object() 解析不了的旧式紧凑二进制编码（魔术字节"#inh"/"?inh"），抛出异常之前会先清空物件的 dbase 映射（包括"id"）。修法完全相同：让 short() 的兜底逻辑用 stringp(id) 判断。通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)。没有中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就是正确的码点判断，commandd.lpc 的 sscanf 本来就匹配 .lpc）。完整的注册→look→score→quit 流程和管理员流程在排版格式化前后都验证过。格式化工具还原了 3 个损坏的 ASCII 地图档案（d/huashan/map.lpc、d/shaolin/obj/map.lpc、d/shaolin/npc/obj/map.lpc），和 jyqxc 逐字节相同的损坏模式。
