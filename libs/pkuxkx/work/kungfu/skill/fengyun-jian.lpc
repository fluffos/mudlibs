// fengyun-jian.c

inherit SKILL;

mapping * action=({
        ([      "action":
        "$N使一招「仙人拱手」，手中$w幻一条疾光刺向$n的$l",
        "force" : 10,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 0,
        "skill_name" : "仙人拱手",
        "damage_type":  "刺伤"
        ]),
        ([      "action":
        "$N一招「日月辉煌」，纵身飘开数尺，手中$w斩向$n的$l",
        "force" : 20,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 20,
        "skill_name" : "日月辉煌",
        "damage_type":  "刺伤"
        ]),
        ([      "action":
        "$N手中$w中宫直进，一式「白蛇吐信」对准$n的肩井穴刺出一剑",
        "force" : 40,
        "dodge" : 20,
        "damage": 80,
        "lvl" : 40,
        "skill_name" : "白蛇吐信",
        "damage_type":  "刺伤"
        ]),
        ([      "action":
        "$N的$w凭空一指，一招「金针指南」，$w跳动着刺向$n的颈部.......",
        "force" : 60,
        "dodge" : 25,
        "damage": 100,
        "lvl" : 60,
        "skill_name" : "金针指南",
        "damage_type":  "刺伤"
        ]),
    ([  "action":"$N左手捏了个剑诀，右手一招「二郎担山」，手中$w对准$n一点",
        "force" : 80,
        "dodge" : 40,
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "二郎担山",
        "damage_type":  "刺伤"
        	   ]),
    ([  "action":"只见$N弓步上前，双手紧握$w，一招「凤凰展翼」，向$n的头部由下而上一撩",
        "force" : 100,
        "dodge" : 30,
        "damage": 60,
        "lvl" : 100,
        "skill_name" : "凤凰展翼",
        "damage_type":  "刺伤" 
        	 ]),
    ([  "action":"$N手拿$w，一招「猛虎摆尾」，向$n的$l飞速一击",
        "force" : 120,
        "dodge" : 40,
        "damage": 120,
        "lvl" : 120,
        "skill_name" : "猛虎摆尾",
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
	level   = (int) me->query_skill("fengyun-jian",1);
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
		return notify_fail("你的体力不够练『风云剑法』。\n");
	me->receive_damage("qi", 25);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"fengyun-jian/" + action;
}
