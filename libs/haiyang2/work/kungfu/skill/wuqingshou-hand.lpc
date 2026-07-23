// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// dhxy
// 大话西游
// 星宿派第二代弟子
// 100000000
// 女性
// hand
// 无情手





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路;$N纵身一跃，手中武器一招「金光泻地」对准$n的$l斜斜刺出一剑",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "无情一式"
]),
// ZHAOSHI :1

([
"action" :"$N缓缓的用出第2招",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "无情二式"
]),
// ZHAOSHI :2

([
"action" :"$N缓缓的用出第3招",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "无情三式"
]),
// ZHAOSHI :3

([
"action" :"$N缓缓的用出第4招",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "无情四式"
]),
// ZHAOSHI :4

([
"action" :"$N缓缓的用出第5招",
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "无情五式"
]),
// ZHAOSHI :5

([
"action" :"$N缓缓的用出第6招",
"force" :210,
"damage" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "无情六式"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"无情手"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "hand" || usage=="parry"; }
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
    level = (int)me->query_skill("wuqingshou-hand",1);
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
