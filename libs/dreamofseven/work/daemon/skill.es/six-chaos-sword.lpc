// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"群魔亂舞",
		"action":		"$N使一招「群魔亂舞」﹐手中$w狂風驟雨般地向$n的$l連攻數劍",
		"dodge":		50,
		"damage":		170,
		"damage_type":	"刺傷"
	]),
	([	"name":			"厲鬼纏身",
		"action":		"$N身形一轉﹐一招「厲鬼纏身」$w斬向$n的$l",
		"dodge":		-50,
		"damage":		20,
		"damage_type":	"刺傷"
	]),
	([	"name":			"百鬼夜行",
		"action":		"$N舞動$w﹐一招「百鬼夜行」挾著閃閃劍光刺向$n的$l",
		"dodge":		-40,
		"damage_type":	"刺傷"
	]),
	([	"name":			"餓鬼攔路",
		"action":		"$N手中$w一抖﹐使出「餓鬼攔路」往$n的$l刺出一劍",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"刺傷"
	]),
	([	"name":			"鬼影幢幢",
		"action":		"$N手中$w劍光暴長﹐一招「鬼影幢幢」往$n$l刺去",
		"dodge":		-60,
		"damage":		20,
		"damage_type":	"刺傷"
	]),
	([	"name":			"秋墳鬼唱",
		"action":		"$N手中$w直指$n$l﹐一招「秋墳鬼唱」發出逼人劍氣刺去",
		"dodge":		-20,
		"damage":		50,
		"damage_type":	"刺傷"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的內力不夠﹐沒有辦法練六陰追魂劍。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必須先找一把劍才能練劍法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("你的內力或氣不夠﹐沒有辦法練習六陰追魂劍。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所學練了一遍六陰追魂劍法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
	if( (int)me->query_skill("six-chaos-sword", 1)	% 10 == 0 ) {
		tell_object(me,
			RED "\n你突然覺得一股惡氣衝上心頭﹐只覺得想殺人....\n\n" NOR);
		me->add("bellicosity", 1000);
	} else
		me->add("bellicosity", 100);
}
