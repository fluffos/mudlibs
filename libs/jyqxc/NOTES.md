
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib（金庸群侠传），游戏内标题为"The Story of Hero"。修复了两个 bug：feature/name.lpc 的 short() 呼叫 capitalize(query("id")) 没做保护——只要有物件在没设置"id"属性的情况下走到 short()，就会崩溃报"Bad argument 1 to capitalize()"，这份档案里约 49 个留言板分身（data/board/*.o 存档用一种这个驱动的 restore_object() 解析不了的旧式紧凑二进制编码，魔术字节"#inh"/"?inh"）全都会撞上这个问题——"Illegal file format"失败在抛出异常之前会先清空物件的 dbase 映射（包括刚在 create() 里设置好的"id"），导致每次 look 一个摆着留言板的房间都会崩溃。已改成让 short() 的兜底逻辑用 stringp(id) 判断，而不是重新格式化这约 49 个旧式存档档案。另外通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)。没有发现中文名字/宏定义/指令表相关的 bug（is_chinese() 本来就用正确的 Unicode 码点区间；check_legal_name() 的 i%2==0 隔字检查会漏检奇数位置的非中文字符，但从不会拒绝真实的中文名字，所以保持原样）。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次；管理员流程通过可见的"目前权限：(admin)"显示验证。格式化工具还原了 3 个损坏的档案，都是 ASCII 地图（d/huashan/map.lpc、d/shaolin/npc/obj/map.lpc 及其在 d/shaolin/obj/map.lpc 下的副本）——和这条血统里手足档案同样的分词器混淆模式。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40129）跑了一遍超出注册流程的完整游玩。读了
`doc/help/newbie`——比这批档案里常见的官方模板丰富得多，是一篇由
玩家（武痴/Hop）写的天资/练功攻略，明确解释了 `set wimpy`（逃跑系
数）、`fight`（较量，双方气/精跌到 50% 会自动停手）vs `kill`（死战，
打到一方死亡为止，"倘若对手比你强，你便会十分危险"）的区别——这份
文档直接解释了前两轮（`fy330`/`fy2mg`）会话里反复观察到的"自动逃跑
安全网"机制的设计意图和触发阈值。

**主动检查命中 2 处**：`adm/daemons/logind.lpc` 单一姓名输入路径
（没有随机取名的平行分支）紧挨在 `ob->set("name", arg)` 之前的
`printf("%O\n", ob)` 调试残留（AGENTS.md §7.34）；同一文件
`enter_world()` 里食物/饮水初始化用错对象的经典 §8.9 bug——
`ob->query("age") == 14` 应为 `user->query("age")`，紧跟在
`user->setup()` 之后。两处都已修复；注册后食物/饮水显示 279/280
（接近满值），确认 §8.9 修复生效。`command_hook` 有两份拷贝
（`feature/command.lpc` 是 `F_COMMAND` 宏实际指向的活文件，
`home/command.lpc` 是未被引用的死拷贝），两份都是干净的
`nomask`，没有 `private`，不是 bug。没有 MESSAGE_D-> 未防护调用或
stat/water 键名不一致的问题。

**注册流程**：`get_id` → `confirm_id`(y/n) → `get_name` → `new_password`
→ `confirm_password` → `get_gift`（随机天赋展示，y/n 决定接受或重
摇，不是选择固定档位）→ `get_email` → `get_gender` →
`enter_world()`，没有民族选择这一步（和 `fy330`/`fy2mg` 不同）。
注册了测试角色（秦冬 / id `qindongxi`），落在"客店"，自带专属邮箱
（"秦冬的信箱"）。

**邮件/留言板测试**：`look mailbox` 正确列出 mail/forward/from/
read/discard 指令说明；客店留言板 `post`/`read new` 正常工作
（用内建列编辑器"~e"/"~q"/"."结束的输入方式），验证完毕后
`discard` 掉了测试留言，没有留下痕迹。

**战斗测试：真实死亡+复活全流程现场验证（本项目 §7.68 系列里少见
的完整现场复现）**：客店门外北大街站着"欧阳克"（金庸小说里的反派
角色，白驼山少庄主）。按新手指南的建议先用较为"安全"的 `fight`
指令交手——结果一招"白蛇吐信"就直接把测试角色从满血打死，"较量"
的 50% 自动停手阈值根本来不及触发（这是内容强度问题，欧阳克本来
就不是新手陪练对象，不是 bug，故未做任何代码改动）。角色死亡后被
送到"鬼门关"，"实习无常"（本轮刚修复的 `newgargoyle.lpc`）和
"白无常"同时在场。**没有主动断线或制造中断**，让复活序列完整跑完，
重连后确认角色已经复活、站在"武庙"，`score` 显示精/气降到
40%（符合死亡惩罚），食物/饮水满格——这是目前这一系列里第一次
（`bixiecanyang`/`fy330`/`fy2mg` 都因为自动逃跑机制没能真正死亡）
现场完整验证了 §7.68 修复后undisturbed 路径的正确性，虽然仍然没有
专门复现"复活过程中被强制挪走"这个原始触发场景。

**死亡/复活系统：发现并修复 §7.68 的又一实例，外加一个全新变体
（新增归档条目）**：`d/death/npc/{newgargoyle,bgargoyle,wgargoyle}.lpc`
（实习无常/黑无常/白无常，和 `bixiecanyang`/`fy2mg` 同宗的死亡系统，
这里多了"实习无常"这个第三种鬼差角色，"白无常"死讯提示还带一段随
机游走的 chat_msg）都有同样的 `if (!ob || !present(ob)) return;`
复活软锁死守卫，`bgargoyle.lpc` 和 `fy2mg` 一样在多阶段复活循环前
多一段"活人闯入阴间就攻击"的判断。三个文件都已按已验证的修法拆分。

**全新变体，与死亡系统无关**：`d/shaolin/npc/yu-zu2.lpc`（"狱卒"，
少林寺地牢的看守）的 `death_stage()` 是同一个 bug 类在完全不同场
景下的实例——这不是阴曹地府的复活序列，而是少林寺对犯规弟子的"关
禁闭"惩罚机制：多阶段 `call_out` 链每 60 秒推进一次狱卒的台词，最
终把人放出监狱（`move("/d/shaolin/woshi1")`）。同样的
`if (!ob || !present(ob)) return;` 守卫意味着服刑期间任意一瞬间
"人不在场"（不只是真正离线，也可能是暂时的场景切换）就会让这个人
永久放弃出狱资格，卡在监狱里出不来，没有任何提示。已用同样的拆分
修法处理。这说明 §7.68 这个 bug 类不止出现在"阴曹地府"这一种叙事
包装里，任何"多阶段 call_out 链 + `!present(ob)` 兜底守卫"的组合都
值得同样检查——已经据此更新 AGENTS.md §7.68 的归纳表述。

`quit` 正常退出（"当你下次连线进来时，会从这里开始。欢迎下次再
来！"），formatter 检查（五个改动文件均已是干净格式，无需重排
版）、`git status --short libs/jyqxc/` 复查均确认改动范围干净——
只有五处源码修改是跟踪变更，测试角色的新存档保持未跟踪、未提交。
`debug.log` 全程没有真实的 `error:`/`denied`/`Bad argument`/
`Too deep recursion` 行。
