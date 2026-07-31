// wenjia-daofa.c 温家刀法（NPC功夫）

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「苍松迎客」，身体微侧，刀锋平引，斜劈$n的$l",
	"force" : 120,
        "dodge" : -10,
	"damage" : 125,
	"lvl" : 0,
	"skill_name" : "苍松迎客",
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跃上一步，右手急速舞动手中的$w，一招「开门见山」直挑$n的$l",
	"force" : 140,
        "dodge" : -10,
	"damage" : 230,
	"lvl" : 10,
	"skill_name" : "开门见山",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一个斜侧步，一招「闻鸡起舞」，手中$w平平的推向$n的$l",
	"force" : 270,
        "dodge" : 5,
	"damage" : 135,
	"lvl" : 20,
	"skill_name" : "闻鸡起舞",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「推波助澜」，手里的$w划出一个大弧，急速砍向$n的$l",
	"force" : 290,
        "dodge" : 35,
	"damage" : 240,
	"lvl" : 30,
	"skill_name" : "推波助澜",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	 
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
        int i, level;
	level   = (int) me->query_skill("wenjia-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的体力不够练温家刀法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

