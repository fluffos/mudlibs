// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// hxsd
// 小人物
// 大理镇南王府家奴
// 8000000
// 男性
// blade
// 无敌刀





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，手中$w一招「金光泻地」对准$n的$l斜斜刺出一刀",
"force" :60,
"dodge" :40,
"damage_type": "割伤",
"lvl" : 1,
"skill_name" : "无敌一"
]),
// ZHAOSHI :1

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :90,
"dodge" :60,
"damage_type": "割伤",
"lvl" : 2,
"skill_name" : "无敌二"
]),
// ZHAOSHI :2

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :120,
"dodge" :80,
"damage_type": "割伤",
"lvl" : 3,
"skill_name" : "无敌三"
]),
// ZHAOSHI :3

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :150,
"dodge" :100,
"damage_type": "割伤",
"lvl" : 4,
"skill_name" : "无敌四"
]),
// ZHAOSHI :4

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :180,
"dodge" :120,
"damage_type": "割伤",
"lvl" : 5,
"skill_name" : "无敌五"
]),
// ZHAOSHI :5

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :210,
"dodge" :140,
"damage_type": "割伤",
"lvl" : 6,
"skill_name" : "无敌六"
]),
// ZHAOSHI :6

([
"action" :"creatskill blade cao 无敌刀 7",
"force" :240,
"dodge" :160,
"damage_type": "割伤",
"lvl" : 7,
"skill_name" : "无敌六"
]),
// ZHAOSHI :7

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :270,
"dodge" :180,
"damage_type": "割伤",
"lvl" : 8,
"skill_name" : "无敌六"
]),
// ZHAOSHI :8

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :300,
"dodge" :200,
"damage_type": "割伤",
"lvl" : 9,
"skill_name" : "无敌六"
]),
// ZHAOSHI :9

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :330,
"dodge" :220,
"damage_type": "割伤",
"lvl" : 10,
"skill_name" : "无敌六"
]),
// ZHAOSHI :10

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
"force" :360,
"dodge" :240,
"damage_type": "割伤",
"lvl" : 11,
"skill_name" : "无敌六"
]),
 });
// ZHAOSHI :11
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"无敌刀"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
string query_skill_name(int level)
{
        int i;
//        for(i = sizeof(action)-1; i >= 0; i--)
//                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level = (int)me->query_skill("cao-blade",1);
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
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
