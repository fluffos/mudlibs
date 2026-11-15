// dragon-strike.c 镇岳锁龙劲 龙战于野
// modified by Venus Oct.1997
// modified by Doing 1999

inherit SKILL;

mapping *action = ({
([      "action" : "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",
	"dodge"  : 40,
	"parry"  : -10,
	"force"  : 240,
	"damage" : 110,
	"damage_type": "震伤"
]),
});

string main_skill() { return "dragon-strike"; }

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
	if (me->query_skill("dragon_strike", 1) > 0)
		return notify_fail("你已经学全十八掌了，不必再单独学习。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练镇岳锁龙劲必须空手。\n");

	if ((int)me->query("str") < 30)
		return notify_fail("就你这身子骨还练镇岳锁龙劲？小心弄折了胳膊。\n");

	if ((int)me->query_skill("force") < 90)
		return notify_fail("你的内功火候不够无法学习镇岳锁龙劲。\n");

	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的内力太差无法学习镇岳锁龙劲。\n");

	if ((int)me->query_skill("strike", 1) < 30)
		return notify_fail("你的基本掌法火候不够，无法学习镇岳锁龙劲。\n");

	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("longzhan-yuye", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的镇岳锁龙劲。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 120)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练镇岳锁龙劲。\n");

	me->receive_damage("qi", 100);
	me->add("neili", -40);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"longzhan-yuye/" + action;
}
