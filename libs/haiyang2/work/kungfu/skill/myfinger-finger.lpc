// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// mylove
// 西红柿蛋汤
// 唐门第九代弟子
// 24763020
// 男性
// finger
// 眉心指





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N嫣然一笑，右手食指慢慢探出，一式「眉心无情」，攻向$n的印堂穴，$N纵身一跃，左手紧接武器一招「灵犀一指」，对准$n的太阳穴点去。",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "眉心指"
]),
// ZHAOSHI :1

([
"action" :"$N提起一口真气，双手食指击出，一式「灵犀指」，攻向$n的太阳穴。",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "灵犀指"
]),
// ZHAOSHI :2

([
"action" :"$N纵身一跃，手中五指一招「惊魔」对准$n的$l斜斜刺出",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "惊魔一指"
]),
// ZHAOSHI :3

([
"action" :"$N嘿嘿冷笑一声，双手一招「乾坤无极」，对准$n的心脏斜斜点去。",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "乾坤指"
]),
// ZHAOSHI :4

([
"action" :"$N双手十指舞动如飞，使出［四起金龙］龙入九天，$n顿时呆若木鸡，根本不知如何应付。",
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "四起金龙"
]),
// ZHAOSHI :5

([
"action" :"葛伦暗运真气，内力聚于双手，一招「龙现于野」闪电般直扑$n",
"force" :210,
"damage" :140,
"damage_type": "瘀伤",
"lvl" : 5,
"skill_name" : "龙现于野"
]),
// ZHAOSHI :6

([
"action" :"$N微探双臂，凭空一点,使出［龙翔于天］！",
"force" :240,
"damage" :160,
"damage_type": "瘀伤",
"lvl" : 6,
"skill_name" : "龙翔于天"
]),
// ZHAOSHI :7

([
"action" :"$N一声长啸，猛然探出十指使出［龙游于渊］！幻出条条金磷飞龙，闪电般的扑向$n！",
"force" :270,
"damage" :180,
"damage_type": "瘀伤",
"lvl" : 7,
"skill_name" : "龙游于渊"
]),
// ZHAOSHI :8

([
"action" :"$N微微凝神，使出眉心指绝学「三才指」，无数道光影笼罩着$n。",
"force" :300,
"damage" :200,
"damage_type": "瘀伤",
"lvl" : 8,
"skill_name" : "三才指"
]),
 });
// ZHAOSHI :9
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"眉心指"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"眉心指"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "finger" || usage=="parry"; }
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
    level = (int)me->query_skill("myfinger-finger",1);
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
