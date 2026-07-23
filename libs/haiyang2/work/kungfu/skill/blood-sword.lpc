// TIE@FY3
// blood-sword.c
#include <ansi.h>
inherit SKILL;
mapping *action = ({
       ([     "name":             "平刺",
              "action":		"$N平握$w，挟著闪闪赤红剑光刺向$n的$l",
              "dodge":            20,
              "damage":           50,
              "damage_type":      "刺伤"
	]),
       ([     "name":             "突刺",
              "action":		"$N将$w斜向左边，随着踏步声，往$n的$l狂刺数剑",
              "dodge":            10,
              "parry" :           30,
              "damage":           150,
              "damage_type":	"刺伤"
	]),
       ([     "name":             "闪突刺",
		"action":		"$N侧身平握$w，剑尖下沉而后倾，以闪电之势刺向$n的$l",
              "dodge":            50,
              "parry":            100,
              "damage":           200,
              "damage_type":      "刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力不够，没有办法学"RED"血衣剑法"NOR"。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习"RED"血衣剑法"NOR"。\n");
	me->receive_damage("jing", 30);
	me->add("neili", -5);
	//write("你按著所学练了一遍"RED"血衣剑法"NOR"。\n");
	return 1;
}

int effective_level() { return 12;}



int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 30;
}
int black_white_ness()
{
	return 100;
}


string perform_action_file(string action)
{
        return __DIR__"blood-sword/" + action;
}


