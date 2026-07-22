int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+SKILL_CH_NAME+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+SKILL_CH_NAME+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== SKILL_BASE_NAME || usage=="parry"; }
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
    level = (int)me->query_skill(SKILL_EN_NAME,1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
