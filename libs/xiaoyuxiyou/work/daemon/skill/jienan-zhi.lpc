//【劫难指】 jienan-zhi.c
inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action" : "但闻哧哧两声，$n脸色突变，$N却悠闲自在，并无动过手的迹象，好一招"+HIY"「瓶花落砚」"NOR"。\n",
		"dodge"  : -20,
		"parry"  : -20,
		"damage" : 100,
		"damage_type":	"刺伤",
		"weapon" : "一缕罡气",
	]),
	([	"action" : "$N一式"+HIY"「伽叶微笑」"NOR"，双手食指交叉，指端射出一缕罡气，穿过$n的$l。\n",
		"dodge"  : -30,
		"parry"  : -30,
		"damage" : 120,
		"damage_type":	"刺伤",		
		"weapon" : "一缕罡气",
	]),
	([	"action" : "$N左掌竖立胸前，一式"+HIY"「佛祖拈花」"NOR"，右手食指扣住拇指，轻轻对着$n一弹。\n",
		"dodge"  : -40,
		"parry"  : -40,
		"damage" : 140,
		"damage_type":	"刺伤",
		"weapon" : "一股指风",
	]),
	([	"action" : "$N右手伸出，十指叉开，一式"+HIY"「花开见佛」"NOR"，小指拂向$n的太渊穴。\n",
		"dodge"  : -50,
		"parry"  : -50,
		"damage" : 160,
		"damage_type":	"刺伤",
		"weapon" : "一股指风",
	]),
            ([	"action" : "$N微微一笑，一招"+HIY"「雪地红莲」"NOR"，衣袖连摆，指劲随机弹出，叫人琢磨不透，无法躲避。\n",
		"dodge"  : -60,
		"parry"  : -60,
		"damage" : 180,
		"damage_type":	"刺伤",
		"weapon" : "一股指劲",
	]),
            ([	"action" : "$N一招"+HIY"「无色无相」"NOR"向$n点出，闻得一破空之声，却见$P微笑点头，却再无任何动静。\n",
		"dodge"  : -70,
		"parry"  : -70,
		"damage" : 200,
		"damage_type":	"刺伤",
		"weapon" : "一缕罡气",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练劫难指必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");
	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);
	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("putuo") + "/jienan-zhi/" + func;
}


