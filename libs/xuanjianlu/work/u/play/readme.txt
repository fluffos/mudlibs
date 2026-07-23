[188] 关于2002/7/20日的文件更新                游戏小子(play)(Sun Jul 21)
----------------------------------------------------------------------
1./adm/daemons/chinesed.c
目地--添加了对量词显示的设定 string getchinese(int sum)部分
2./inherit/room/room.c
目地--将以前的设定int query_max_encumbrance() { return 100000000000; };
修改成为了int query_max_encumbrance() { return 2000000000; }
因为现在的底层数峰值只到21亿多，以前的会反回10亿多一点，因此改成20亿
3./inherit/item/combined.c
目地--添加了物品被move后，除了以前shore()的判断外，name and id 及物品
量词的同步判断，这样可以使除了short()相同的物品累加外，同name and id
及量词的物品也可以累加。
4./cmds/usr/inventory.c
目地--从新编写了这个文件，玩家身上的物品可以量化的显示。
5./cmds/std/look.c
目地--编写了int look_room(object me, object env)部分，A:使得房间的物
品及人物可以量化显示；B：添加了biref的三个设定，为别是exit、all、和
非零值，可以按设定分别屏蔽玩家look时显示的信息，相关帮助看settings。
6./doc/help/settings
目地--改写了brief部分的帮助说明，相关改动为/cmds/std/look.c
7./feature/move.c
目地--将以前对move后，到房间里是否设定brief部分给于删除，因为新的判断
放到了/cmds/std/look.c中，也为了相应房间中物品量化的显示。
8./d/xueshan/inherit
目地：这里的两个文件都做了更改，为了雪山新的工作系统。
9./d/xueshan/npc/zrlama.c
目地：这个文件更新成了发布新工作任务的系统人物。
10./d/xueshan/npc/xs_job
目地：本文件夹下的文件全部为新工作系统调用
11./d/xueshan/npc/obj/xs_youhu.c
目地：这个文件是为雪山第一个工作而设定的油壶。
12./d/xueshan/pingtai.c  pingtai1-pingtai4   /d/xueshan/obj/jitan.c
目地：这组文件是雪山第四个任务而设定。
13./d/xueshan/*room.c
目地：这里有几个房间增加了进香客，因为本次调整工作，会大量消耗油的量。
14./cmds/std/kill.c
目地：加了一行代码 if(query("no_kill")) 这个判断是在设定些参数的人物将不会被杀。
15./adm/daemons/combatd.c
目地：加一几行代码在void killer_reward(object killer, object victim)里
有play的注释，用于雪山工作第四套任务记录奖励点数，结合文件在
/d/xueshan/npc/xs_job/xs_npc/job/shouxin.c
16./cmds/std/throw.c
目地：设定判断query("no_kill")如果有此设定，则不能对设定人使用。
17./kungfu/class/murong/baichuan.c
目地：结合全mud的任务奖励及新增加的雪山门派，给予了奖励点数的调整。
18./kungfu/skill/douzhuan-xingyi/lifeheal.c
目地：改变了疗伤时的显示，及新的疗伤能力的判断和恢复量的调整。
19./kungfu/skill/murong-jianfa/xingbao.c
目地：增加了本特功，可以按功夫的等级出招数量来杀伤敌人。
20.//kungfu/skill/canhe-zhi.c
20./kungfu/skill/canhe-zhi/shedou.c (上一行错误，本行有效)
目地：改变了判断击中敌手的有效率。
21./d/murong/mishi/ +murongbo
目地：在这个房间中加上了慕容博。他的文件在/kungfu/class/murong/bo.c
22./doc/help/mizong
目地：添加了雪山派新任务的说明。

整理: Play
时间: 2002.7.20