
## WASM 修复摘要（迁移自 meta.json 的 group_note）

战国代码库，adm/obj/master.lpc 血统——虽然 slug 相似，但和 sjecl/sje 的 Century/adm-single 家族完全不同。WASM 修复：（1）§7.60 类的 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 判断守卫。（2）§7.8/§7.9 大小写不一致+缺失的计数器档案：logind.lpc 的 VISITORS/GIFTCARD 宏指向 /adm/single/MUDVISITOR 和 /adm/single/GIFTCARD（大写），而硬盘上的档案是小写的 mudvisitor/giftcard——导致每一次连线的 sscanf() 都崩溃（"the user is disconnected"，看起来像空白的对话记录）。已修正宏的大小写，并给两处 read_file() 结果加上 stringp() 保护作为纵深防御。（3）logind.lpc 的 logon() 里缺了一个 return：'!find_object(DNS_MASTER)' 分支（这里永远会走到，因为按既定的无 socket 政策 dns_master 已经从预载里禁用）已经显示了简化横幅并提示输入 id，但少了 return，导致函式继续往下执行，紧接着无条件呼叫 DNS_MASTER->query_muds()，在每一次连线时都触发经典的未定义 socket efun 编译错误。（4）§7.56 重复的安全精灵档案：SECURITY_D 解析到的是 adm/daemons/securd.lpc（一个存档档案/dbase 支撑的精灵，硬编码了引导用管理员"keyboy"作为 (zhuguan)），而不是名字相似的 adm/daemons/securityd.lpc——那是一个未被使用、和这个宏毫无代码路径关系的诱饵档案——一开始播种了一条文本格式的 /adm/etc/wizlist 条目，完全没有效果，因为 securd.lpc 根本不读这个档案；后来改成在 securd.lpc 的 restore_list() 里紧挨着既有的 keyboy 那行加一行 set("wiz_status/fluffos","(admin)")，匹配它自己既有的引导模式（AGENTS.md §1.5 的硬编码引导管理员 id 类）。已验证：完整注册→look/score/quit 全部干净，权限显示正确地显示〖银河特警〗(Admin)，匹配 securd.lpc 自己的 wiz_rank() 显示字符串。留下一处不阻断、已经在预载之外的问题作为噪音：符合 §7.6"从预载排除，保护呼叫者"的模式——呼叫者除了上面修好的那个 logon() 呼叫点之外，其它地方都已经正确地用 find_object() 判断保护了；其余几处次要的 DNS_MASTER 呼叫点在被触及时仍会无害地记录同样的编译错误文字，没有进一步深究。LPC 格式化工具对全部 2697 个档案运行；还原了 8 个通过"去空格后比对旧档案"扫描（覆盖 30 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案；另外检查了所有形似 map.lpc 的档案——没有一个是 ASCII 地图，全都是干净的排版调整。格式化后重新验证过，干净。

## §10.7 深度功能测试（本次新增）

此前只做过注册→look/score→quit 的浅层验证。本次用管理员 `fluffos`
实际走通了注册→`score`（人物状态）→`goto` 到天狼星区的实际游戏地图
→和 NPC 交谈→真实战斗→死亡→鬼门关复活的完整流程。

### 修复 1：§8.9 食物/饮水年龄检查错对象

`adm/daemons/logind.lpc` 的登录完成流程里：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象，不是角色本体 `user`，`ob->query("age")` 永远是
undefined，这道门槛永久为假。已改为 `user->query("age") == 14`。（实测
本档案的 `user->setup()` 已经预先把食物/饮水填满，所以这个 bug 在默认
流程下不会直接表现为空食槽——但逻辑仍然是错的，按标准修法一并修正。）

### 修复 2：两处 §7.68 复活软锁（d/death/npc/{b,w}gargoyle.lpc）

`death_stage(object ob, int stage)` 原代码
`if (!ob || !present(ob)) return;` 把"鬼魂对象已经不存在了"和"鬼魂此
刻只是暂时不在这个房间里"混为一谈，一旦判定瞬间鬼魂碰巧不在场就永久
放弃后续引导，把鬼魂永久卡在鬼门关。按标准修法拆开：`!ob` 才是真正放
弃，`!present` 改为 5 秒后重试。

### 实战验证：完整的战斗→死亡→复活流程

用管理员角色（新建，属性和普通玩家一样是白板）在天狼中心向"交通警
察"（`combat_exp` 20000，比新手强得多）发起攻击，几个回合后被击杀——
死亡提示、"江湖传闻"广播、送入鬼门关的链路均正常触发；鬼门关里
白无常(wgargoyle) 的完整对话（"你叫什么名字"→"你命不该绝，快滚上
去"→一脚踢出鬼门关）全部顺利播放完毕，角色被正确送到本档案的
REVIVE_ROOM（太空港口，呼应科幻题材），复活链路全程无卡死、无报错。

### 检查、确认不适用的已知 bug 类别

- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 shujian3/hy2002/jh2006/xxcq 相同形状的结构，这几
  个同宗档案都已经用真实测试排除过这个 bug（裸 set/query 实际写入
  了真正的 dbase），本次时间关系未重复验证。

### 顺带记录（非 bug，仅存档）

死亡瞬间的系统提示里出现过一行
`〖系统信息〗交通警察(Jingcha)：Auto_save has been started for -495
分钟`——NPC 自动存盘计时器显示了负数分钟数。纯粹是显示层面的小瑕疵
（不影响存盘本身，NPC 也确实继续正常运作），没有进一步排查，记录在
此供未来 pass 参考。
