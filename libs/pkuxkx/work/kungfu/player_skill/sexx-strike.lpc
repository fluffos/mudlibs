// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// idle
// [1;33m发呆[2;37;0m
// 0
// 40003346
// 无性
// strike
// 干柴烈火掌





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前掌拍出，后掌点地，一式「拍死$N」，拍向$n的中路",
"force" :60,
"damage" :40,
"damage_type": "内伤",
"lvl" : 0,
"skill_name" : "拍死你"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"干柴烈火掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"干柴烈火掌"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("sexx-strike",1);
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
