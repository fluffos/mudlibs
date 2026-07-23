// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// tianyu
// 白如梦
// [1;35m铁掌帮上官帮主弟子[2;37;0m
// 2219919
// 男性
// sword
// 九五之剑





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，手中$w一招「九五第一剑」对准$n的$l斜斜刺出一剑",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "九五第一剑"
]),
// ZHAOSHI :1

([
"action" :"$N纵身一跃，手中$w一招「九五第二剑」对准$n的$l斜斜刺出一剑",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "九五第二剑"
]),
// ZHAOSHI :2

([
"action" :"$N纵身一跃，手中$w一招「九五第三剑」对准$n的$l斜斜刺出一剑",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "九五第三剑"
]),
// ZHAOSHI :3

([
"action" :"$N纵身一跃，手中$w一招「九五第四剑」对准$n的$l斜斜刺出一剑",
"force" :150,
"damage" :100,
"damage_type": "刺伤",
"lvl" : 3,
"skill_name" : "九五第四剑"
]),
// ZHAOSHI :4

([
"action" :"$N纵身一跃，手中$w一招「九五第五剑」对准$n的$l斜斜刺出一剑",
"force" :180,
"damage" :120,
"damage_type": "刺伤",
"lvl" : 4,
"skill_name" : "九五第五剑"
]),
// ZHAOSHI :5

([
"action" :"$N纵身一跃，手中$w一招「九五第六剑」对准$n的$l斜斜刺出一剑",
"force" :210,
"damage" :140,
"damage_type": "刺伤",
"lvl" : 5,
"skill_name" : "九五第六剑"
]),
// ZHAOSHI :6

([
"action" :"$N纵身一跃，手中$w一招「九五第七剑」对准$n的$l斜斜刺出一剑",
"force" :240,
"damage" :160,
"damage_type": "刺伤",
"lvl" : 6,
"skill_name" : "九五第七剑"
]),
// ZHAOSHI :7

([
"action" :"$N纵身一跃，手中$w一招「九五第八剑」对准$n的$l斜斜刺出一剑",
"force" :270,
"damage" :180,
"damage_type": "刺伤",
"lvl" : 7,
"skill_name" : "九五第八剑"
]),
// ZHAOSHI :8

([
"action" :"$N纵身一跃，手中$w一招「九五第九剑」对准$n的$l斜斜刺出一剑",
"force" :300,
"damage" :200,
"damage_type": "刺伤",
"lvl" : 8,
"skill_name" : "九五第九剑"
]),
// ZHAOSHI :9

([
"action" :"$N纵身一跃，手中$w一招「九五第十剑」对准$n的$l斜斜刺出一剑",
"force" :330,
"damage" :220,
"damage_type": "刺伤",
"lvl" : 9,
"skill_name" : "九五第十剑"
]),
// ZHAOSHI :10

([
"action" :"$N纵身一跃，手中$w一招「九五第十一剑」对准$n的$l斜斜刺出一剑",
"force" :360,
"damage" :240,
"damage_type": "刺伤",
"lvl" : 10,
"skill_name" : "九五第十一剑"
]),
// ZHAOSHI :11

([
"action" :"$N纵身一跃，手中$w一招「九五之十二剑」对准$n的$l斜斜刺出一剑",
"force" :390,
"damage" :260,
"damage_type": "刺伤",
"lvl" : 11,
"skill_name" : "九五之十二剑"
]),
 });
// ZHAOSHI :12
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"九五之剑"+"。\n");
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
    level = (int)me->query_skill("ninefive-sword",1);
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
