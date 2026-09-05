// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// idle
// [1;33m发呆[2;37;0m
// 0
// 40003346
// 无性
// blade
// 眉来眼去刀





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，两眼发直，一招「看死$N」对准$n的$l重重砍了下去",
"force" :60,
"damage" :40,
"damage_type": "割伤",
"lvl" : 0,
"skill_name" : "看死你"
]),
// ZHAOSHI :1

([
"action" :"$N转身过去，背朝$n，放了一个屁，活活把$n气死了",
"force" :90,
"damage" :60,
"damage_type": "割伤",
"lvl" : 1,
"skill_name" : "气死你"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"眉来眼去刀"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
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
    level = (int)me->query_skill("ssex-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!
