// /kungfu/skill/shaolin-tantui.c 少林弹腿

inherit SKILL;

mapping *action = ({
([
	"action" : "$N一式「落燕式」，右腿支地，左腿画弧，直踢$n的头部",
	"lvl" : 0,
	"skill_name" : "落燕式",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N身形一闪，已从$n身边掠过，右足反踢，正是一招「抚平式」，踹向$n的背心",
	"lvl" : 10,
	"skill_name" : "抚平式",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N身体半蹲，右足画出个半圆，使出「追月式」，扫向$n的膝部",
	"lvl" : 20,
	"skill_name" : "追月式",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N上身微侧，左足倏地弹出，踢向$n的头部，裆部，正是一式「连环式」",
	"lvl" : 30,
	"skill_name" : "连环式",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N右足独立，左足随身形反转横扫，又左足立定，右足横扫向前，一招「扫叶式」，踢向$n的$l",
	"lvl" : 40,
	"skill_name" : "扫叶式",
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N跃起在半空，双足乱舞，带起无数劲风，「盘龙式」！迅捷无伦地卷向$n",
	"lvl" : 50,
	"skill_name" : "盘龙式",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }

int valid_combine(string combo) { return combo=="fengyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学少林弹腿时手里不能拿武器。\n");
	if ((int)me->query_skill("yijin-jing", 1) < 10)
		return notify_fail("你的易筋经内功火候不够，无法学少林弹腿。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练少林弹腿。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
	level   = (int) me->query_skill("shaolin-tantui",1);
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 100 + random(250),
				"dodge": random(20)-10,
				"parry": random(10),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("shaolin-tantui", 1);
	int i = sizeof(action);

	while (i--) 
		if (lvl == action[i]["lvl"])
			return notify_fail("你现在的招式已经都练熟了，需要向师父请教新的招式了。\n");;
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练少林弹腿。\n");
	me->receive_damage("jingli", 20);
	me->add("neili", -5);
	return 1;
}
