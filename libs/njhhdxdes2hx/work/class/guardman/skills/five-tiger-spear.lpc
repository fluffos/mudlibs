inherit SKILL;

mapping *action = ({
	([	"action":	"$N一抖枪杆，一招「黑虎掏心」，直向$n的$l刺去！",
		"damage":	200,
		"dodge":	70,
		"damage_type":	"刺伤"
	]),
	([	"action":	"$N身形一低，一招「犀牛望月」，手中$w自下而上刺向$n的$l",
		"damage":	100,
		"damage_type":	"刺伤"
	]),
	([	"action":	"$N改枪为棍，一招「搂草打兔」，手中$w呜的一声夹风望$n$l打来",
		"damage":	150,
		"damage_type":	"挫伤"
	]),
	([	"action":	"$N突然卖个破绽拖枪便走，待$n追时，猛然「回马一枪」翻身便刺",
		"damage":	180,
		"damage_type":	"刺伤"
	]),
});

int valid_enable(string usage)
{
	return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practive_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "spear" )
		return notify_fail("你必须先找一杆枪，才能练枪法。\n");
	if ((int)me->query("kee", 30))
		return notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
	me->receive_damage("kee",40);
	return 1;
}

int effective_level() {return 25;}

string *parry_msg = ({
	"$n大喝一声：开！一招「力开华山」，手中的$v将$N的$w架开。\n",
	"$n使出一招「拨草寻蛇」将$N的$w拨开。\n",
	"$n身体微沉手中的$v划向身后，一招「苏秦背剑」，将$N的$w磕向一边。\n",
});

string *unarmed_parry_msg = ({
	"$n手中的$v一抖，一连五朵枪花, 仿佛有无数枪尖在$N眼前晃动, 只得撤招自保。\n",
	"$n将手中的$v舞得车轮一般，封住了$N的攻势。\n",
});

string query_parry_msg(object weapon)
{
	if (weapon)
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus() { return 30; }

int practice_bonus() { return 20; }

int black_white_ness() { return 50; }
