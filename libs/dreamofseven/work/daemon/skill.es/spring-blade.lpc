// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「春風拂人醉」﹐手中$w輕飄飄地向$n的$l斬去﹗",
		"damage":		200,
		"dodge":		70,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N金刃劈風﹐$w隨著一招「遠山伴人痴」由下而上撩往$n的$l",
		"damage":		40,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N身形一轉﹐一招「飛花逐人香」$w刀光不定﹐斬向$n的$l",
		"damage":		20,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N舞動$w﹐一招「柳葉隨人笑」迅捷無倫地劈向$n的$l",
		"damage_type":	"斲傷"
	]),
	([	"action":		"$N手中$w一晃﹐一招「倩影惹人憐」往$n的$l斜斜砍出一刀",
		"damage":		40,
		"damage_type":	"斲傷"
	]),
	([	"action":		"$N提刀過肩﹐蓄勁發力﹐一招「蘆雪碎人影」直劈$n$l",
		"damage":		40,
		"damage_type":	"斲傷"
	]),
	([	"action":		"$N移步側身﹐使一招「彩蝶灼人衣」刀光霍霍斬向$n的$l",
		"damage":		40,
		"damage_type":	"斲傷"
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必須先找一把刀﹐才能練刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的體力不夠練這門刀法﹐還是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
