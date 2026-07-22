// SKILL sanhuajuding.c 三花聚顶掌

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N一招"HIW" 大关门式 "NOR"，右手斜斜的劈向$n的$l",
	"force" : 150,
	"dodge" : 20,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "大关门式",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双掌轻飘飘地拍向$n，突然反手上勾。一招"HIW" 乳燕抬腮 "NOR"击向$n的$l",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 20,
	"skill_name" : "乳燕抬腮",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N半跪半蹲一招"RED" 白猿献果 "NOR"，双掌幻化一片掌影，将$n笼罩于内。",
	"force" : 250,
	"dodge" : 30,
	"damage" : 35,
	"lvl" : 30,
	"skill_name" : "白猿献果",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N一招"RED" 虎门手 "NOR"，双手纷飞，手作虎式，双手反扣$n全身各处大穴",
	"force" : 300,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "虎门手",
    "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIY" 揩磨尘垢 "NOR"，中宫直进，只见一片掌影攻向$n",
	"force" : 350,
	"dodge" : 20,
	"damage" : 60,
	"lvl" : 50,
	"skill_name" : "揩磨尘垢",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N双掌平挥，一招"HIY" 无欠无馀 "NOR"击向$n,令$n无处可躲.",
	"force" : 400,
	"dodge" : 25,
	"damage" : 70,
	"lvl" : 60,
	"skill_name" : "无欠无馀",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N纵起丈余，头下脚上，一招"HIR" 红霞贯日 "NOR"击向$n",
	"force" : 450,
	"dodge" : 30,
	"damage" : 80,
	"lvl" : 70,
	"skill_name" : "红霞贯日",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N左掌虚晃，右掌一记"HIM" 紫电穿云 "NOR"击向$n的左颊，招未使老在途中陡变掌缘却劈向$n的右颈。",
	"force" : 500,
	"dodge" : 30,
	"damage" : 90,
	"lvl" : 80,
	"skill_name" : "紫电穿云",
           "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhuajuding"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练三花聚顶掌必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练三花聚顶掌。\n");
	if ((int)me->query_skill("xiantian-gong",1)< 20)
		return notify_fail("你的先天神功修为不够，无法练三花聚顶掌。\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("sanhuajuding",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练三花聚顶掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sanhuajuding/" + action;
}
