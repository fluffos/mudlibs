// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mudy
// 千面
// 普通百姓
// 200530864
// 男性
// sword
// 千面神剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N突然运功将内功激发到剑尖，$w在内功激发下嗡嗡作响！$n觉得自己的招数竟然被$N吸住，$N就势一招「万化连缠」，手中$w直指$n$l!",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "万化连缠"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"千面神剑"+"。\n");
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
    level = (int)me->query_skill("mudy-sword",1);
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
