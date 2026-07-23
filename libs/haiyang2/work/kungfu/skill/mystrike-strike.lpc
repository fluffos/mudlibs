// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// bwd
// 哑口无言
// 丐帮第二十代弟子
// 4897392
// 男性
// strike
// 我的掌法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路;$N纵身一跃，手中武器一招「金光泻地」对准$n的$l斜斜刺出一剑",
"force" :60,
"damage" :40,
"damage_type": "内伤",
"lvl" : 0,
"skill_name" : "宋军伤兵"
]),
// ZHAOSHI :1

([
"action" :"$N翡翠豆腐有些腐烂了，发出刺鼻的味道。$n的上中下三路;$N翡翠豆腐有些腐烂了，发出刺鼻的味道。$n的$l斜斜刺出一剑",
"force" :90,
"damage" :60,
"damage_type": "内伤",
"lvl" : 1,
"skill_name" : "玉树临风"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"我的掌法"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"我的掌法"+"。\n");
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
    level = (int)me->query_skill("mystrike-strike",1);
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
