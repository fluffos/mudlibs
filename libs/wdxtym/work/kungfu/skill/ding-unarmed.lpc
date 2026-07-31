// ding-unarmed.c 一横一勾拳
inherit SKILL;

mapping *action = ({
([	"action" : "$N左手轻轻一抹，向$n的$l拍去",
	"force"  : 180,
	"damage" : 80,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N右手一提，插向$n的$l",
	"force"  : 230,
	"damage" : 100,
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < 40)
		return notify_fail("你的内力不够练一横一勾拳。\n");

	me->receive_damage("qi", 35);
	me->add("neili", -32);

	return 1;
}
