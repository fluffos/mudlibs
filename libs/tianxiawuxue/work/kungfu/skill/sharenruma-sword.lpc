// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// taotao
// 慕容陶
// 姑苏慕容第三代弟子
// 1870207
// 男性
// sword
// 杀人如麻剑法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"HIW $N一声阴笑，飞身纵起，一式「灭绝人性」，身影豁然间一分为二,手中$w狂舞,万道剑光虚虚实实,直逼$n的$l",
"force" :60,
"dodge" :40,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "灭绝人性"
]),
// ZHAOSHI :1

([
"action" :"$N一声厉啸，身形冲天而起，似是御风而行,足不沾地地徒然滑进七尺,$n不知对方是何用意，心想还是避之为妙，刚向左踏开一步，眼前白光急闪，掌中$w如鬼魅般连刺$n全身九道大穴,正是「不留活口」",
"force" :90,
"dodge" :60,
"damage_type": "刺伤",
"lvl" : 1,
"skill_name" : "不留活口"
]),
// ZHAOSHI :2

([
"action" :"$N神情突然间变地十分落索,一式「行尸走肉」,手中$w似乎漫不经心斜斜刺向$n,$n见剑式钝拙,潇洒向旁一避,突然$w剑尖一变,迅疾无比地直取$n的裆部",
"force" :120,
"dodge" :80,
"damage_type": "刺伤",
"lvl" : 2,
"skill_name" : "行尸走肉"
]),
 });
// ZHAOSHI :3
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"杀人如麻剑法"+"。\n");
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
    level = (int)me->query_skill("sharenruma-sword",1);
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
