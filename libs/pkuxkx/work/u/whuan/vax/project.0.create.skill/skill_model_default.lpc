int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力太弱，无法练"+SKILL_CH_NAME+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== SKILL_BASE_NAME || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]*40)
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill(SKILL_EN_NAME,1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]*40)
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
// fake line
//
//
//
//
//
	return notify_fail("只有创造者在侠客岛或自创帮派的闭关室中，清心寡欲，忘却俗事才能练习武功!\n");
} //total 34 lines!
