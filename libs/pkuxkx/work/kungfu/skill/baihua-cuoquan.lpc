// baihua-cuoquan.c 百花错拳
// by hubo 2008-4-27

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「百花神抓」，五指成勾状，功向$n的面门",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "百花神抓",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手摆动，使一招「百花争芳」，向$n的腹部功去",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "百花争芳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「百花齐放」打向$n的$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "百花齐放",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记「百花飞扬」击向$n的裆部",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "指裆锤",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「百花乱错」，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "伏虎式",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练百花错拳必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练百花错拳。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练百花错拳。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"baihua-cuoquan/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
	"$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打在一团棉絮中，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

