//taiyi-zhang.c 侠客掌
//by zoom
//2003.4.6

inherit SKILL;

mapping *action = ({
([      "action" : "$N腾空而起，一招「太乙无虚」身子在空中倒转，头下脚上，双掌向$n的$l击去",
        "dodge": 10,
        "force": 40,
        "damage": 0,
        "lvl" : 0,  
        "damage_type" : "瘀伤"
]),

});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("taiyi-zhang", 1) > 20)
		return notify_fail("你的太乙神掌已经无法再提高了。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
      		return notify_fail("练太乙神掌必须空手。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query_skill("taiyi-zhang", 1) > 20)
		return notify_fail("你的太乙神掌已经无法再提高了。\n");
        if ((int)me->query("qi") < 20)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力太低了。\n");

	me->receive_damage("qi", 10);
	me->add("neili", -5);
	return 1;
}
