// kongling-jian.c
//  空灵剑法
inherit SKILL;

mapping *action = ({
    ([  "action":"$N一招「匪神之灵」，高举手中$w，向$n迎头一劈",
        "force" : 100,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "匪神之灵",
        "damage_type":  "刺伤" 
        	]),
    ([  "action":"$N反手一招「匪机之微」，手中$w向$n的$l一抹",
        "force" : 140,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 30,
        "skill_name" : "匪机之微",
        "damage_type":  "刺伤"
        	]),
    ([  "action":"只见$N弓步上前，双手紧握$w，一招「乱山乔木」，向$n的头部由下而上一撩",
        "force" : 180,
        "dodge" : 10,
        "damage": 60,
        "lvl" : 60,
        "skill_name" : "乱山乔木",
        "damage_type":  "刺伤"  
        	 ]),
    ([  "action":"$N手拿$w，一招「碧苔芳晖」，向$n的$l飞速一击",
        "force" : 220,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 90,
        "skill_name" : "碧苔芳晖",
        "damage_type":  "刺伤"  
        	]),
        ([      "action":
"$N使出「清风与归」，$w连挥剑光霍霍斩向$n的$l",
        "force" : 240,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 120,
        "skill_name" : "清风与归",
        "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一招「诵之思之」，纵身飘开数尺，手中$w斩向$n的$l",
        "force" : 200,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 150,
        "skill_name" : "诵之思之",
        "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N纵身一跃，手中$w一招「终与俗违」，对准$n的气海穴斜刺出一剑",
        "force" : 160,
        "dodge" : 10,
        "damage": 120,
        "lvl" : 180,
        "skill_name" : "终与俗违",
        "damage_type":  "刺伤"
        ]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("kongdong-xinfa", 1) < 20)
		return notify_fail("你的『崆峒心法』火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("你的基本内功火候太浅。\n");
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
	level   = (int) me->query_skill("kongling-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query_skill("kongdong-xinfa", 1) < 20)
		return notify_fail("你的『崆峒心法』火候太浅。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练『空灵剑法』。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"kongling-jian/" + action;
}