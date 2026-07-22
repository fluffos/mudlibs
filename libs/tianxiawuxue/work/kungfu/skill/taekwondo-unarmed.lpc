// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hongtian
// 宏天
// 凌霄城第七代弟子
// 10000425
// 男性
// unarmed
// 跆拳道





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一个脚点地，迅速转身另一个脚从背后回旋踢出，一招｛后旋踢｝踢向$n的后脑",
"force" :60,
"dodge" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "后旋踢"
]),
// ZHAOSHI :1

([
"action" :"$N前脚点地，转身后脚踢出，一式｛后踢｝攻向$n，并发出强大的杀气",
"force" :90,
"dodge" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "后踢"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"跆拳道"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"跆拳道"+"。\n");
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
    level = (int)me->query_skill("taekwondo-unarmed",1);
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
