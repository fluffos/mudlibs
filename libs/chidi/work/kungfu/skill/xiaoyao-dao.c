//
//xiaoyao-dao  逍遥刀法
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N身形微动，一招「彩虹飞天」手中$w化做一道白虹，直劈向$n的胸前",
        "skill_name" : "彩虹飞天",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "劈伤",
]),
([      "action" : "$N身形急转，一招「回风转云」，舞起一片刀花，$w飞劈$n",
        "skill_name" : "回风转云",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "劈伤",
]),
([      "action" : "$N气贯刀锋，$w扬起一阵风声，一招「大风起兮」，劈向$n的头顶",
        "skill_name" : "大风起兮",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "割伤",
]),
([      "action" : "$N刀锋急转，变幻莫测，一招「北燕南归」，$w反劈向$n的后心",
        "skill_name" : "北燕南飞",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 50,
        "damage" : 50,
        "damage_type" : "劈伤",
]),
([      "action" : "$N面带微笑，刀尖化出无数白点，一招「人面桃花」，攻击向$n全身",
        "skill_name" : "人面桃花",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 80,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「似是而非」，刀不象刀，剑不象剑，攻击向$n周身要害",
        "skill_name" : "似是而非",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 100,
        "damage" : 60,
        "damage_type" : "割伤",
]),
([      "action" : "$N使一式「轻于鸿毛」，$w如同虚无飘渺一般，不断的直向$n攻去   ",
        "skill_name" : "轻于鸿毛",
        "force" : 300,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 130,
        "damage" : 80,
        "damage_type" : "割伤",
]),
([      "action" : "$N劲运于$w,一招「天外来峰」，$w如有千斤一般，直直向$n劈去   ",
        "skill_name" : "天外来峰",
        "force" : 500,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 150,
        "damage" : 100,
        "damage_type" : "割伤",
]),


});


int valid_enable(string usage) { return usage == "blade" ; }


int valid_learn(object me)
{
	if ((int)me->query_skill("blade", 1) >= 30)
		return 1;
	else if ((int)me->query_skill("blade", 1) < 30)
		return notify_fail("你的基本刀法太差了，练不了逍遥刀法。\n");
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
	level   = (int) me->query_skill("xiaoyao-dao",1);
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
	if ((int)me->query("qi") < 20)
		return notify_fail("你的体力不够，练不了逍遥刀法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

