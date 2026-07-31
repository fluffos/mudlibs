// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// lxudd
// 高姓
// [1;33m活佛[2;37;0m
// 2516480
// 男性
// unarmed
// 摸妹妹





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，双手对准$n的全身乱摸一气，高低起伏",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "初探香体"
]),
// ZHAOSHI :1

([
"action" :"$N伸出双手，一式「摸摸胸部」，攻向$n的中路",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "双手摸胸"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"摸妹妹"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"摸妹妹"+"。\n");
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
    level = (int)me->query_skill("hamagong-unarmed",1);
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
