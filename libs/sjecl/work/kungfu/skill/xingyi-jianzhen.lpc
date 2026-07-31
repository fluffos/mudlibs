// xingyi-jianzhen.c

#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	MAG"\n$N纵声长笑，“唰”的一声长剑出鞘，寒芒吞吐，电闪星飞，遥指$n前胸要害。\n\n"NOR,
	MAG"\n$N一声呼啸，各人施展乾坤倒转，手中刀走剑式，剑走刀路，纵横交错地攻向$n。\n\n"NOR,
	MAG"\n各人手中兵刃脱手而出，有如流星飞坠，一同罩向$n周身要害。\n\n"NOR,
	MAG"\n众人脚步骤然加快，星光流转般围着$n急转，同时攻向$n身上各处大穴。\n\n"NOR,
	MAG"\n$n眼前一花，只见对方数人化身为二，刀剑齐施，一起功来。\n\n"NOR,
	MAG"\n只听一声清啸，$N掌风带着飞沙走石，击向$n，当真星云昏暗。\n\n"NOR,
	MAG"\n$N施展出$n的成名绝技，$n正目瞪口呆之际，另外两剑已从身后袭来。\n\n"NOR,
	MAG"\n$N双手握刀，向前向后划弧，一片刀光打向$n的腰间!\n\n"NOR,
	MAG"\n$N长剑前伸，连刺$n前胸十三处大穴，直如星星点点。\n\n"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 4;
}

void create()
{ 
	seteuid(getuid()); 
}

string type() 
{ 
        return "array"; 
}

int valid_learn(object me) 
{
	if( me->query_skill("shenyuan-gong",1) < 150)
		return notify_fail("你的神元功级别不够，无法学习星移剑阵。\n");
	if( me->query_int() < 36 )
		return notify_fail("你的悟性太低，无法领悟星移剑阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("星移剑阵只能通过学习(learn)来提高。\n");
}
