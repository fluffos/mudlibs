
## WASM 修复摘要（迁移自 meta.json 的 group_note）

时空游侠录（Roaming Swordsman）血统代码库，登入横幅为"非凡公子/新月传奇录II"。没有发现 mudlib bug——WASM 下开箱即用，全程零修复。唯一的门槛：get_id() 要求 id 提示后的第一个输入必须是字面字符串 "shikongyouxia3.0"（固定魔术字符串校验，不是加密），才会进入真正询问英文 id 的环节——不先发这个，每次注册尝试都会看到"你的客户端版本有问题"并断线。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 25 个"误报"里抓到了两处真正的损坏（d/huashan/map.lpc，一张 ASCII 地图，形态和 cctx 的一样；d/player/fyue_room.lpc，一段房间描述，格式化工具的分词器在这里失去同步）——两者都直接还原，没有手工修补。另外记录但没有修复：d/city/sj.lpc（一个无法到达、没有任何房间连向它的孤立房间）通篇有转档之前就存在的缺引号问题（该用字符串字面量的地方写成了裸词中文，比如 add_action(do_out, out) 应为 add_action("do_out", "out")）——如果真被加载会编译失败，但因为没有任何路径能到达这个房间，从不影响注册/游戏/退出流程。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。
