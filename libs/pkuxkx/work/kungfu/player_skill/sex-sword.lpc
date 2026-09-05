// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// idle
// [1;33m发呆[2;37;0m
// 0
// 40003346
// 无性
// sword
// 奸夫淫妇剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N两眼发出淫光，一招「干柴烈火」，剑尖直指$n胸部",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "干柴烈火"
]),
// ZHAOSHI :1

([
"action" :"$N左手握剑猛砍，右手成爪猛抓，一招「郎情妾意」，意图把$n撕成两半",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "郎情妾意"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"奸夫淫妇剑"+"。\n");
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
    level = (int)me->query_skill("sex-sword",1);
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
