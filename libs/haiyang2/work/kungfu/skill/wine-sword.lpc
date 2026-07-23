// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wine
// 绿啤
// 姑苏慕容第二代弟子
// 2189260
// 男性
// sword
// 绿啤





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N握紧手中$w一招「清瑟怨遥夜」缓缓点向$n的$l",
"force" :60,
"damage" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "清瑟怨遥夜"
]),
// ZHAOSHI :1

([
"action" :"$N一招「绕弦风雨哀」无数$w犹如和风细雨拂向$n",
"force" :90,
"damage" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "绕弦风雨哀"
]),
// ZHAOSHI :2

([
"action" :"$N向前跨上一步，手中$w使出「孤灯闻楚角」直取$n的喉部",
"force" :120,
"damage" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "孤灯闻楚角"
]),
// ZHAOSHI :3

([
"action" :"$N虚晃一步，使出「残月下章台」手中$w斜刺，眼看要触及$n的左肩，剑芒徒转向$l",
"force" :150,
"damage" :100,
"damage_type": "刺伤",
"lvl" : 3,
"skill_name" : "残月下章台"
]),
// ZHAOSHI :4

([
"action" :"$N手中$w向外一分，使出「芳草已云暮」带着哀愁扫向$n",
"force" :180,
"damage" :120,
"damage_type": "刺伤",
"lvl" : 4,
"skill_name" : "芳草已云暮"
]),
// ZHAOSHI :5

([
"action" :"$N捏起剑诀，手中的$w如盼似望，使出「故人殊未来」探往$n$l",
"force" :210,
"damage" :140,
"damage_type": "刺伤",
"lvl" : 5,
"skill_name" : "故人殊未来"
]),
 });
// ZHAOSHI :6
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"绿啤"+"。\n");
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
    level = (int)me->query_skill("wine-sword",1);
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
