// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// ninger
// 玉宁儿
// 采花淫贼
// 4672762
// 女性
// strike
// 白玉手





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N不管三七二十一，对准$n的鼻子就是一拳,打得他满脸开花",
"force" :60,
"damage" :40,
"damage_type": "内伤",
"lvl" : 0,
"skill_name" : "无双无对"
]),
// ZHAOSHI :1

([
"action" :"$N脸露傻笑，摇摇晃晃向$n撞了过去",
"force" :90,
"damage" :60,
"damage_type": "内伤",
"lvl" : 1,
"skill_name" : "神昏颠倒"
]),
// ZHAOSHI :2

([
"action" :"$N站在原地不动，大喊道，来打我啊，就在$n一愣之时，突然打出一拳",
"force" :120,
"damage" :80,
"damage_type": "内伤",
"lvl" : 2,
"skill_name" : "无所事事"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"白玉手"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"白玉手"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "strike" || usage=="parry"; }
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
    level = (int)me->query_skill("mmm-strike",1);
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
