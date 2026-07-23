// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// game
// 游戏
// 钦赐一等鹿鼎公
// 3905352
// 男性
// finger
// 天才手





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N突然抬手，一招「伸手不见五指」，手指插向$n的双眼，他顿时什么都看不到了。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "伸手不见五指"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"天才手"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"天才手"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "finger" || usage=="parry"; }
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
    level = (int)me->query_skill("tiancai-finger",1);
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
