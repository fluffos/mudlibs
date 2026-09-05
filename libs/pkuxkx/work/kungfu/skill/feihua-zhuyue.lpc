// feihua-zhuyue.c 飞花逐月
//Made By:pingpang
inherit SKILL;

mapping *action = ({
([	"action" : "$N使出一招[百里飘香]，$n的身影开始摇晃，摇摇欲坠的样子",
	"force" : 300,
        "dodge" : 100,
	"skill_name" : "百里飘香",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招[万里雪飘],顿时间狂风大作，漫天飞雪向$n袭去",
	"force" : 300,
        "dodge" : 100,
	"skill_name" : "万里雪飘",
        "damage_type" : "瘀伤"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练飞花逐月必须空手。\n");
        if ((int)me->query("max_neili") < 10000)
		return notify_fail("你的内力太弱，无法练飞花逐月。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 1000)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 2000)
		return notify_fail("你的内力不够练飞花逐月。\n");
	me->receive_damage("qi", 100);
        if ((int)me->query_skill("feihua-zhuyue", 1) < 300)
                me->add("neili", -500);
        else
                me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"feihua-zhuyue/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
	"$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打空了似的，对$n毫无伤害。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
