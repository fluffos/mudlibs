// benlei-tiezhang.c 奔雷铁掌
// by hubo 2008-4-27

inherit SKILL;

mapping *action = ({
([	"action" : "$N使一招「切金断玉」，手掌作刀状，砍向$n的面门",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "切金断玉",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手摆动，使一招「双手开碑」，向$n的腹部功去",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "双手开碑",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「千斤顶」打向$n的$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "千斤顶",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记「猴子捞月」击向$n的裆部",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "猴子捞月",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「雷霆万钧」，双掌齐发，令人难以招架",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "雷霆万钧",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练奔雷铁章必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练奔雷铁掌。\n");
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
		return notify_fail("你的内力不够练奔雷铁掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

  int valid_combine(string combo) { return combo=="baihua-cuoquan"; }
string perform_action_file(string action)
{
	return __DIR__"benlei-tiezhang/" + action;
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

