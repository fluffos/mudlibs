//taiyi-zhang.c 侠客掌
//by zoom
//2003.4.6
//Modified by iszt@pkuxkx, 2007-04-02, added action 2 and allowed level 100
// 2009.8.17 finished by zgbl

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
	"action" : "$N贴地窜出，身子离地仅一尺，头前脚后，一招"CYN"「太乙无虚」"NOR"，双掌向$n的$l击去",
	"dodge": 15,
	"force": 240,
	"damage": 0,
	"lvl" : 0,  
	"damage_type" : "瘀伤"
]),
([
	"action" : "$N腾空而起，身子在空中倒转，头下脚上，一招"HIC"「太乙有虚」"NOR"，双掌向$n的$l击去",
	"dodge": 10,
	"force": 200,
	"damage": 0,
	"lvl" : 50,  
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

string *unarmed_parry_msg = ({
        CYN"$n手掌挥动间，顺着一道浑然天成的玄妙轨迹攻向了$N，$N的攻击居然莫名打在了空门，只能无奈回守。\n"NOR,
});
string query_parry_msg(object weapon)
{   
	return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


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
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太乙神掌必须空手。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("taiyi-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("family"))
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("chushi"))
  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
    if (me->query("betrayer") > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	if (me->query_skill("hunyuan-yiqi",1) > 0)
		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法练习，纯百姓技能
	if ((int)me->query("qi") < 60)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力太低了。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taiyi-zhang/" + action;
}
