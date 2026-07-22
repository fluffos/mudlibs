// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"one",
		"action":		"$N上前一步，手中$w毒蛇般刺向$n的$l",
		"dodge":		50,
		"damage":		70,
		"damage_type":	"刺伤"
	]),
	([	"name":			"two",
		"action":		"$N身形一转，反手一挥，手中$w刺向$n的$l",
		"dodge":		50,
		"damage":		20,
		"damage_type":	"刺伤"
	]),
	([	"name":			"three",
		"action":		"$n眼前一花，$N手中的$w已经迅捷无比的刺向$n的$l",
		"dodge":		40,
		"force" :		100,
		"damage_type":	"刺伤"
	]),
	([	"name":			"four",
		"action":		"$N只攻不守，手中$w一抖，往$n的$l刺出一剑",
		"dodge":		40,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
	([	"name":			"five",
		"action":		"$N的「左手剑法」只有[31m刺[37m，简单而有效地往$n的$l刺去",
		"dodge":		60,
		"damage":		80,
		"force" :		100,
		"damage_type":	"刺伤"
	]),
	([	"name":			"six",
		"action":		"$N手中$w直指$n$l，发出逼人剑气闪电般刺去",
		"dodge":		20,
		"damage":		20,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;


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
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习左手剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍左手剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
		me->add("bellicosity", 10);
	} else
		me->add("bellicosity", 1);
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -20;
}
string perform_action_file(string action)
{
        return CLASS_D("assassin") + "/lefthand-sword/" + action;
}

