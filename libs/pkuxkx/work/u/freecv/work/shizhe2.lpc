//shizhe2.c  负责教学的使者
//by zoom
//2003.3.31

#include "shizhe.h"

void greeting(object me)
{
        tell_object(me,HIG+this_object()->query("name")+"告诉你：  
    欢迎！欢迎！我是负责生活指令的使者，我将教你如何使用生活指令。

    当你到某个地方后，可能发现有些东西被丢在地上， 可以用get指令捡起来。
get 物品名可以拣起某件东西，get all则可以拣起地上所有的东西。当你不想要
身上的某件东西时，可以用drop 物品名来丢掉它。
    现在介绍赚钱方法，可以通过做任务赚钱，也可以杀有钱的NPC，总之，根据
自己的能力吧。
    辛辛苦苦赚了一点钱，赶快存起来吧，要不然不小心死掉可就什么都没有了。
钱庄里有四个常用的命令：
	存钱(cun|deposit)	取钱(qu|withdraw)
	兑换(convert|duihuan)	查帐(check|chazhang)
    各个城市一般都有钱庄，是连锁的哦。\n"+NOR);
        tell_object(me,HIG+this_object()->query("name")+"告诉你：  
    买东西使用buy指令，要到专门卖东西的地方或者当铺才行。可以先用list查
看出售的所有物品和价格。
    现在介绍当铺里的指令。当铺里卖东西可以直接用sell 物品名。当铺里专用
指令有：pawn|dang，retireve|shu和value。pawn 物品名可以典当东西，典当的
数量跟经验有关，不加参数可以查看当前当的东西。retireve 编号可以赎回典当
的东西。value 物品名可以对物品进行估价。
    说了这么多，差点忘了最主要的吃喝指令。eat和drink是最主要的吃喝指令。
这两种指令格式相同，在指令名后加上物品名就可以了。
    还有一条生活指令sleep，即使我不说你也肯定知道该指令的功能。睡上一觉
可以恢复精神和体能。当然只能在卧室睡觉，丐帮弟子可以随处睡觉。

    "+ NOR + HIW +"enter" + NOR + HIG + "方向是专门给新手练习这些指令的地方。" + NOR);
}
