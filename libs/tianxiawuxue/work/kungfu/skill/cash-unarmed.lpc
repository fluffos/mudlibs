// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// cash
// 银票
// 日月神教第三代弟子
// 8120595
// 无性
// unarmed
// 要钱大法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"银票伸手就拿$n钱",
"force" :50,
"dodge" :10,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "伸手就拿钱"
]),
// ZHAOSHI :1

([
"action" :"银票过去就抢$n的钱",
"force" :80,
"dodge" :-10,
"damage_type": "瘀伤",
"lvl" : 12,
"skill_name" : "过去就抢的钱"
]),
// ZHAOSHI :2

([
"action" :"银票就要$n的钱",
"force" :100,
"dodge" :-20,
"damage_type": "瘀伤",
"lvl" : 20,
"skill_name" : "死要钱"
]),
// ZHAOSHI :3

([
"action" :"$n给了银票一些铜板",
"force" :130,
"dodge" :-30,
"damage_type": "瘀伤",
"lvl" : 30,
"skill_name" : "还是要钱"
]),
// ZHAOSHI :4

([
"action" :"$n给了银票一些银子",
"force" :150,
"dodge" :-50,
"damage_type": "瘀伤",
"lvl" : 40,
"skill_name" : "再给钱"
]),
// ZHAOSHI :5

([
"action" :"$n给了银票一些金子",
"force" :180,
"dodge" :-60,
"damage_type": "瘀伤",
"lvl" : 50,
"skill_name" : "还要给钱"
]),
// ZHAOSHI :6

([
"action" :"$n给了银票一些银票",
"force" :200,
"dodge" :-80,
"damage_type": "瘀伤",
"lvl" : 60,
"skill_name" : "就给钱"
]),
// ZHAOSHI :7

([
"action" :"银票抢了$n一些铜板",
"force" :220,
"dodge" :-90,
"damage_type": "瘀伤",
"lvl" : 80,
"skill_name" : "抢钱"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"要钱大法"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"要钱大法"+"。\n");
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
    level = (int)me->query_skill("cash-unarmed",1);
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
