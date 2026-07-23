// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// zbz
// 小龙女
// 灵鹫宫第四代弟子
// 2380738
// 女性
// unarmed
// 移魂大法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃,一招「开天辟地」对准$n的$l斜斜击出一掌",
"force" :60,
"damage" :40,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "开天辟地"
]),
// ZHAOSHI :1

([
"action" :"$N大喝一声，一招「后羿射日」一股内气向$n$l射去！",
"force" :90,
"damage" :60,
"damage_type": "瘀伤",
"lvl" : 1,
"skill_name" : "后羿射日"
]),
// ZHAOSHI :2

([
"action" :"$N凝聚全身的功力发出了名震天下的「九天落日」,天空九个火球落下,攻向$n的上中下三路",
"force" :120,
"damage" :80,
"damage_type": "瘀伤",
"lvl" : 2,
"skill_name" : "九天落日"
]),
// ZHAOSHI :3

([
"action" :"$N心下又是痛惜，又是愤怒，当即大步迈出，左手一划，右手呼的一掌，便向$n击去，正是移魂大法的一式「神龙吐珠」",
"force" :150,
"damage" :100,
"damage_type": "瘀伤",
"lvl" : 3,
"skill_name" : "神龙吐珠"
]),
// ZHAOSHI :4

([
"action" :"$N身形化做一只九天飞凤一飞冲天，一招「凤舞九天」，幻出无数火凤凰飞向$n的上中下三路",
"force" :180,
"damage" :120,
"damage_type": "瘀伤",
"lvl" : 4,
"skill_name" : "凤舞九天"
]),
 });
// ZHAOSHI :5
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练"+"移魂大法"+"必须空手。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"移魂大法"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("yihun-unarmed",1);
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
