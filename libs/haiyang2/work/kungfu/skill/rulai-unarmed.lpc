// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xiaoyaozi
// 逍遥
// 大理镇南王府家奴
// 2894450
// 男性
// unarmed
// 如来神掌





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$n被$N一掌击中居然发了疯",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "佛光普照"
]),
// ZHAOSHI :1

([
"action" :"$n被$N一掌击中居然发了花痴",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "佛动山河"
]),
// ZHAOSHI :2

([
"action" :"$n被$N一掌击中居然变态了",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "神佛降世"
]),
// ZHAOSHI :3

([
"action" :"$n被$N一掌击中居然爱上$N了",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "佛祖保佑"
]),
// ZHAOSHI :4

([
"action" :"$n被$N一脚踢中下体命根子断掉了",
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "如来狂舞"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"如来神掌"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"如来神掌"+"。\n");
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
    level = (int)me->query_skill("rulai-unarmed",1);
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
