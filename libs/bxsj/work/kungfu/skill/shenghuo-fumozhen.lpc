// shenghuo-fumozhen.c


#include <ansi.h>

inherit SKILL;

string *action_msg = 
({
	HIR"\n突然之间，三人身形晃动，同时欺近，三只左手齐往$n身上抓去。\n\n"NOR,
	HIR"\n$n兵器挥出，向三人横扫过去，不料三人脚下不知如何移动，身形早变。$n一招\n"
		+"击空，已被三人的右手同时抓住后领，一抖之下，向外远远掷了出去。\n\n"NOR,
	HIR"\n三人步法既怪，出手又是配合得妙到毫巅，便似一个人生有三头六臂一般。\n\n"NOR,
	HIR"\n但见$N直欺而前，伸指点向$n咽喉。$n伸手一封，跟着还击一腿，突然间腾身\n"
		+"而起，后心已被另外两人抓住，提了起来。\n\n"NOR,
	HIR"\n$n身形一转，向左避开，不意拍的一响，后心已被$nN一令击中。\n\n"NOR,
	HIR"\n$N双手两根圣火令急挥横扫，突然连翻三个空心筋斗，$n不知他是何用意，眼前\n"
		+"白光急闪，右肩已被圣火令重重击中。\n\n"NOR,
	HIR"\n$N飞身而前，双手圣火令相互一击，铮的一响，$n心神一荡，身子从半空中直堕\n"
		+"下来，但觉腰胁中一阵疼痛，已被踢中了一脚。\n\n"NOR,
	HIR"\n霎时间四人均凝立不动，各运内力。突然之间，$n胸口一痛，似乎被一枚极细的\n"
		+"尖针刺了一下。\n\n"NOR,
	HIR"\n$n只觉对面的内劲同时后撤，突然之间，一股阴劲如刀、如剑、如匕、如凿，直\n"
		+"插入他胸口的“玉堂穴”中。\n\n"NOR,
	HIR"$n兵器刚向前刺出，后背已被$N一把抱住。"NOR,
	HIR"$N一令打来，依照武学的道理，这一招必须打在$n左肩，哪知圣火令在半途古古怪怪\n"
		+"的转了个弯，拍的一响，竟打中在他后颈。"NOR,
});


string query_action()
{
	return action_msg[random(sizeof(action_msg))];
}

int query_limit()
{
	return 3;
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
	if(! me->query_skill("jiuyang-shengong"))
	if( me->query_skill("shenghuo-shengong",1) < 150)
		return notify_fail("你的圣火神功级别不够，无法学习圣火伏魔阵。\n");
	if( me->query_skill("shenghuo-lingfa",1) < 150)
		return notify_fail("你的圣火令法级别不够，无法领悟圣火伏魔阵。\n");
	if( me->query_int(1) < 32 )
		return notify_fail("你的悟性不够，无法领悟圣火伏魔阵。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("圣火伏魔阵只能通过学习(learn)来提高。\n");
}
