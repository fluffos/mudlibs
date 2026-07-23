// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// xlssi
// 笑莫问
// 麻雀楼　第二代弟子
// 2000196
// 男性
// blade
// 英雄刀





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N使出英雄八刀中的起手式“初出江湖”，手中的$w划出一道寒光斩向$n的$l",
"force" :60,
"dodge" :40,
"damage_type": "割伤",
"lvl" : 0,
"skill_name" : "初出江湖"
]),
// ZHAOSHI :1

([
"action" :"$N手一抖，一招“雄心万丈”手中的$w幻成漫天刀花,散向$n的$l",
"force" :90,
"dodge" :60,
"damage_type": "割伤",
"lvl" : 1,
"skill_name" : "雄心万丈"
]),
// ZHAOSHI :2

([
"action" :"$N刀锋忽转，手中的$w一招“意气风发”，如同一道电光劈向$n的$l斜",
"force" :120,
"dodge" :80,
"damage_type": "割伤",
"lvl" : 2,
"skill_name" : "意气风发"
]),
// ZHAOSHI :3

([
"action" :"$N身影晃动，刀锋忽左忽右，一招“一夫当关”，手中的$w，从中路突然砍至$n的$l",
"force" :150,
"dodge" :100,
"damage_type": "割伤",
"lvl" : 3,
"skill_name" : "一夫当关"
]),
// ZHAOSHI :4

([
"action" :"$N的双脚点地，刀背贴身，一招“万人莫敌”全身转出一团刀光滚向$n的$l",
"force" :180,
"dodge" :120,
"damage_type": "割伤",
"lvl" : 4,
"skill_name" : "万人莫敌"
]),
// ZHAOSHI :5

([
"action" :"$N刀刃向上，一招“把酒问天”，从一个$n意想不到的角度撩向$n的$l",
"force" :210,
"dodge" :140,
"damage_type": "割伤",
"lvl" : 5,
"skill_name" : "把酒问天"
]),
// ZHAOSHI :6

([
"action" :"$N大喝一声,将手中的$w抛向天空,$w如有灵性,一招“英雄末路”，化出无边刀影将$n的$l团团围住",
"force" :240,
"dodge" :160,
"damage_type": "割伤",
"lvl" : 6,
"skill_name" : "英雄末路"
]),
// ZHAOSHI :7

([
"action" :"$N使出英雄八式中的收手式“谁是英雄”，身形与手中的$w化为一体,天地之间只闻$N笑声,笑声中忽然一刀迅捷无比地砍向$n的$l",
"force" :270,
"dodge" :180,
"damage_type": "割伤",
"lvl" : 7,
"skill_name" : "谁是英雄"
]),
 });
// ZHAOSHI :8
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "blade") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"英雄刀"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
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
    level = (int)me->query_skill("heroblade-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
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
