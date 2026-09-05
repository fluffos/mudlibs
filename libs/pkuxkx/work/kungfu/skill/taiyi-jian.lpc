//taiyi-jian.c	太乙神剑
//by zoom
//2003.4.6
//Modified by iszt@pkuxkx, 2007-04-02, added action 2 and allowed level 100
// 2009.8.17 finished by zgbl

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
	"action" : "$N往下一矮身，一招"CYN"「太乙无痕」"NOR"，手中$w如一缕浮云向$n的$l横削而过",
	"force" : 240,
	"dodge" : 20,
	"damage" : 100,
	"lvl" : 0,
	"damage_type":  "刺伤"
]),
([
	"action" : "$N往上一纵身，一招"HIC"「太乙有痕」"NOR"，手中$w如一股流水向$n的$l竖劈而下",
	"force" : 240,
	"dodge" : 10,
	"damage" : 150,
	"lvl" : 0,
	"damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法学习，纯百姓技能
	return 1;
}

string *parry_msg = ({
        CYN"$n手中$v"CYN"一颤，化为一片虚幻的云雾，$N的攻击打进去，有如石沉大海。\n"NOR,
});
string *unarmed_parry_msg = ({
        CYN"$n双手一舒，一道道无形剑气化为一片虚幻的云雾，$N的攻击打进去，有如石沉大海。\n"NOR,
});

string query_parry_msg(object weapon)
{   
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("taiyi-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if(me->query("newbie_village"))
	{
		if ((int)me->query("qi") <= 25)
			return notify_fail("你的体力不够练太乙神剑。\n");
		me->receive_damage("qi", 25);
		return 1;
	}
//有门派或者有过门派都无法练习，纯百姓技能
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力不够练太乙神剑。\n");
		if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练太乙神剑。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiyi-jian/" + action;
}
