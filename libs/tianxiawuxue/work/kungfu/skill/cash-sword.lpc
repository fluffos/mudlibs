// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hxsd
// 小人物
// 华山派第十四代弟子
// 20000000
// 男性
// sword
// 银票神剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N给了小想象一下$N和$n",
"force" :50,
"dodge" :20,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "银子"
]),
// ZHAOSHI :1

([
"action" :"$N给了$n一些银子",
"force" :80,
"dodge" :10,
"damage_type": "刺伤",
"lvl" : 12,
"skill_name" : "银白"
]),
// ZHAOSHI :2

([
"action" :"$N给了$n一些银白",
"force" :100,
"dodge" :10,
"damage_type": "刺伤",
"lvl" : 20,
"skill_name" : "银白"
]),
// ZHAOSHI :3

([
"action" :"$N给了$n一些银川",
"force" :130,
"dodge" :5,
"damage_type": "刺伤",
"lvl" : 30,
"skill_name" : "银川"
]),
// ZHAOSHI :4

([
"action" :"$N给了$n一些银河",
"force" :150,
"dodge" :-5,
"damage_type": "刺伤",
"lvl" : 40,
"skill_name" : "银河"
]),
// ZHAOSHI :5

([
"action" :"$N给了$n一些银幕",
"force" :180,
"dodge" :-5,
"damage_type": "刺伤",
"lvl" : 50,
"skill_name" : "银幕"
]),
// ZHAOSHI :6

([
"action" :"$N给了$n一些银行",
"force" :200,
"dodge" :-10,
"damage_type": "刺伤",
"lvl" : 60,
"skill_name" : "银行"
]),
// ZHAOSHI :7

([
"action" :"$N给了$n一些黄金",
"force" :220,
"dodge" :-10,
"damage_type": "刺伤",
"lvl" : 80,
"skill_name" : "黄金"
]),
// ZHAOSHI :8

([
"action" :"$N",
"force" :20,
"dodge" :-10,
"damage_type": "刺伤",
"lvl" : 100,
"skill_name" : "金"
]),
// ZHAOSHI :9

([
"action" :"$N",
"force" :30,
"dodge" :30,
"damage_type": "刺伤",
"lvl" : 15,
"skill_name" : "金"
]),
// ZHAOSHI :10

([
"action" :"$N",
"force" :240,
"dodge" :240,
"damage_type": "刺伤",
"lvl" : 19,
"skill_name" : "银"
]),
// ZHAOSHI :11

([
"action" :"$N",
"force" :260,
"dodge" :260,
"damage_type": "刺伤",
"lvl" : 20,
"skill_name" : "银子"
]),
 });
// ZHAOSHI :12
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"银票神剑"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("cash-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
