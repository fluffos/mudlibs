// 妙手回春
// 97/9/30  by Aug

inherit SKILL;

mapping *action = ({
	([	"name":		"笔走龙蛇",
		"action":		"$N一招「笔走龙蛇」，手中的$w流星般袭向$n",
		"dodge":		20,
		"parry":		20,
		"force":		20,
		"damage":         30,
		"lvl":		0,
		"damage_type":	"刺伤"
	]),
	([	"name":		"天外飞仙",
		"action":		"$N以闪电般的速度飞出手中的$w,一式「天外飞仙」袭向$n的$l",
		"dodge":		10,
		"parry":		30,
		"force":		30,
		"damage":         35,
		"lvl":		0,
		"damage_type":	"刺伤"
	]),
	([	"name":		"星星点点",
		"action":		"$N一式「星星点点」，顿时空中布满了$w,使$n无处藏身",
		"dodge":		40,
		"parry":		40,
		"force":		40,
		"damage":         40,
		"lvl":		9,
		"damage_type":	"刺伤"
	]),
	([	"name":		"风雪连天",
		"action":		"$N吐气扬声，使出「风雪连天」，顿时$n被包围在一片银光之中",
		"dodge":		40,
		"parry":		30,
		"force":		40,
		"damage":         50,
		"lvl":		9,
		"damage_type":	"刺伤"
	]),
	([	"name":		"天女散花",
		"action":	"$N微微一笑，使出「天女散花」，手中$w不着边际的飞出，可都落在了$n的身上",
		"dodge":		50,
		"parry":		50,
		"force":		55,
		"damage":         55,
		"lvl":		29,
		"damage_type":	"刺伤"
	]),
	([	"name":		"无孔不入",
		"action":		"$N一式「无孔不入」，手中$w袭向$n的手指、脚趾等就不容易防护的部位。",
		"dodge":		100,
		"parry":		100,
		"force":		30,
		"damage":         30,
		"lvl":		49,
		"damage_type":	"刺伤"
	]),
	([	"name":		"洋洋洒洒",
		"action":		"$N一飞冲天，一式「洋洋洒洒」点向$n三十六大死穴",
		"dodge":		80,
		"parry":		80,
		"force":		60,
		"damage":         60,
		"lvl":		69,
		"damage_type":	"刺伤"
	]),
	([	"name":		"银针无敌",
		"action":	"$N手一震，手中$w碎成好几段，从不和能的角度飞向$n",
		"dodge":		80,
		"parry":		80,
		"force":		100,
		"damage":         100,
		"lvl":		99,
		"damage_type":	"刺伤"
	]),

});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("literate", 1) < 40 )
		return notify_fail("你的文学修养不足，不能领悟妙手回春的精髓。\n");
		
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法使用银针。\n");

	if( (string)ob->query_temp("weapon") != "银针" )
		return notify_fail("你必须先拿起银针才能练妙手回春。\n");

	return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" ;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	notify_fail("你只能用向师傅学或多实践的方法来提高妙手回春的水平。\n");
}

string perform_action_file(string action)
{
        return CLASS_D("xiake") + "/miaoshouhuichun/" + action;
}
 
