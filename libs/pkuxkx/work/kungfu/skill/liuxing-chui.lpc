// 童家流星锤法 Zine 飞狐外传
#include <ansi.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N一招「星驰电走」，舞起$w，当胸撩向$n的$l",
	"skill_name" : "星驰电走",
	"force" : 60,
	"dodge" : 50,
	"parry" : 50,
	"lvl" : 0,
	"damage" : 30,
	"damage_type" : "割伤",
]),
([	"action" : "$N将手中$w舞得密不透风，这招「烟飞星散」快若流星，直轰$n",
	"skill_name" : "烟飞星散",
	"force" : 60,
	"dodge" : 50,
	"parry" : 40,
	"lvl" : 20,
	"damage" : 90,
	"damage_type" : "瘀伤",
]),
([	"action" : "$w凭空出现，一式「曙后星孤」，从$N手中飞出卷向$n的$l",
	"skill_name" : "曙后星孤",
	"force" : 70,
	"dodge" : 60,
	"parry" : 50,
	"lvl" : 40,
	"damage" : 80,
	"damage_type" : "割伤",
]),
([	"action" : "$N双眼圆睁，将那$w舞得密不透风，「星罗云布」的推动下，直取$n而去",
	"skill_name" : "星罗云布",
	"force" : 60,
	"dodge" : 70,
	"parry" : 200,
	"lvl" : 60,
	"damage" : 70,
	"damage_type" : "内伤",
]),
([	"action" : "$N双手$w越舞越急，将$n笼罩，这「擘两分星」分取$n两处大穴",
	"skill_name" : "擘两分星",
	"force" : 60,
	"dodge" : 100,
	"parry" : -10,
	"lvl" : 80,
	"damage" : 50,
	"damage_type" : "砸伤",
]),
([	"action" : HIR+"$N"+HIR+"口中念念有词，一招「屡变星霜」击出，$w"+HIR+"无处不在的击向$n"+NOR,
	"skill_name" : "屡变星霜",
	"force" : 160,
	"dodge" : 210,
	"parry" : -30,
	"lvl" : 100,
	"damage" : 100,
	"damage_type" : "瘀伤",
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;

	level = (int) me->query_skill("liuxing-chui",1);

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(object weapon)
{
        if (!weapon) 
               return "但是被$n挡开了。\n";
        if (weapon->query("skill_type") == "hammer")
               return "但是被$n格开了！\n";
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	    || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的气不够，无法练习童家流星锤。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的现在的内力不足，无法继续练童家流星锤。\n");
	me->add("qi", -25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuxing-chui/" + action;
}

