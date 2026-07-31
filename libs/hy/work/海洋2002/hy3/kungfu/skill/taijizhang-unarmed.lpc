// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// yueming
// 月明
// 武当派第二代弟子
// 2491355
// 女性
// unarmed
// 太极绵掌





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N气运丹田，运起太极神功里的氤氲紫气，以太极拳意将内劲聚集，将一股虚虚实实的道家内劲激射到$n面前。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "太极绵劲"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"太极绵掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"太极绵掌"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("taijizhang-unarmed",1);
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
