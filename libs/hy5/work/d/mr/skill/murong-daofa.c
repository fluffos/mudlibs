// murong-daofa.c 慕容刀法

inherit SKILL;

mapping *action = ({
([	"action" : "$N大喝一声「看招」，一招「劈天盖地满壮志」，刀锋自上而下向$n的$l挥去",
	"force" : 180,
        "dodge" : 10,
        "parry" : 10,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "劈天盖地满壮志",
	"damage_type" : "割伤"
]),
([	"action" : "$N一招「弯刀逆转倒乾坤」，手中$w在空中急速转动数圈，划向$n的$l",
	"force" : 260,
        "dodge" : 10,
        "parry" : 10,
	"damage": 70,
	"lvl" : 40,
	"skill_name" : "弯刀逆转倒乾坤",
	"damage_type" : "割伤"
]),
([	"action" : "$N猛一挫身，一招「遥看万疆千里雪」,$w直向$n的颈中斩去",
	"force" : 320,
        "dodge" : 5,
        "parry" : 5,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "遥看万疆千里雪",
	"damage_type" : "割伤",
]),
([	"action" : "$N一招「壮志豪气满江湖」，无数刀尖化作点点繁星，向$n的$l挑去",
	"force" : 380,
        "dodge" : 10,
        "parry" : 5,
	"damage": 150,
	"lvl" : 80,
	"skill_name" : "壮志豪气满江湖",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="murong-jianfa"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("你的神元功火候太浅。\n");
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
	level   = (int) me->query_skill("murong-daofa",1);
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
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的体力不够练慕容刀法。\n");
	me->receive_damage("jingli", 35);
	return 1;
}

