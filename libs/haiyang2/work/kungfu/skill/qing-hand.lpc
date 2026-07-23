// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// qing
// 秋意浓
// [35m终南第一女侠[2;37;0m
// 19649265
// 女性
// hand
// 秋意随风腿





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一招「如影随形」，左腿踢出，但$n还在三丈开外，但见$N瞬间前移三丈，腿已击到$n胸口，左腿未落右腿又出，一道劲风扫过$n门面",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "如影随形"
]),
// ZHAOSHI :1

([
"action" :"但见漫天腿影飞舞，$n的衣衫已被腿风撕成一片片，散落地上，$N身形一跃，一式「往事随风」，半空中左右腿接连踢往$n胸口",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "往事随风"
]),
// ZHAOSHI :2

([
"action" :"「再扫落叶」！$N左腿横扫$n脑门，$n慌忙中低头避过，但发髻已被扫落，狼狈不堪，但见$N背对$n，躬身弯腰右腿往后一个弯月型反扫，脚底板直击$n下巴",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "再扫落叶"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"秋意随风腿"+"。\n");
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
    level = (int)me->query_skill("qing-hand",1);
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
