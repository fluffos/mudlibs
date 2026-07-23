// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// shazi
// 小海
// 唐门第七代弟子
// 76950540
// 男性
// claw
// 挫骨摧筋爪





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N一手扳住$n上腭，一手扳住其下颌，用力一分，即将把下巴撕下来。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "【第一式】"
]),
// ZHAOSHI :1

([
"action" :"$N扑向$n，一口咬住$n的喉咙，“喀嚓”一声！$n的食管、气管、血管全都被咬了出来。",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "【第二式】"
]),
// ZHAOSHI :2

([
"action" :"$N身形急动，五指已然插进$n的天灵盖，喀的一声就扳开了头骨，露出白糊糊的脑浆。$n啊的一声几乎痛死过去。",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "【第三式】"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"挫骨摧筋爪"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "claw" || usage=="parry"; }
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
    level = (int)me->query_skill("cuogucuijin-claw",1);
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
