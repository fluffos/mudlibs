// xianyun-bufa.c 纤云步法
// By Kayin @ CuteRabbit Studio 1999/3/15
inherit SKILL;
#include <ansi.h> 
mapping *action = ({
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"身不倾，脚不移，身体如行云流水般直滑出丈余。\n",
	"dodge"  : 50,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。\n",
	"dodge"  : 100,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"足不动，手不抬，一转眼间便绕到了$N的身后。\n",
	"dodge"  : 150,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。\n",
	"dodge"  : 200,
]),	
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"左踏巽，右转乾，身行一晃，便到几丈远的地方。\n",
	"dodge"  : 250,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"身在空中，左脚在右足上一点，从$N头顶腾空而过。\n",
	"dodge"  : 300,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。\n",
	"dodge"  : 350,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。\n",
	"dodge"  : 400,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。\n",
	"dodge"  : 450,
]),
([	"action" : "$n"NOR"使出"HIC" 纤云步法 "NOR"身行倏的从$N的眼前飘过，长发一甩，潇洒之极。\n",
	"dodge"  : 500,
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("xianyun-bufa");


	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{	
	if( (int)me->query_skill("tianluo-diwang",1)<30)
	 	return notify_fail("你的天罗地网势还不够纯熟,不能学习先云步法。\n");
	if( (int)me->query_skill("yunu-xinfa",1)<30)
	 	return notify_fail("你的玉女心法修为不够,不能练纤云步法。\n");
	 if((int)me->query_skill("yunu-xinfa",1)<(int)me->query_skill("xianyun-bufa",1))
	 	return notify_fail("你的玉女心法修为不够了，不能继续学习纤云步法。\n");
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练纤云步法。\n");
	me->receive_damage("qi", 20);
	return 1;
}
