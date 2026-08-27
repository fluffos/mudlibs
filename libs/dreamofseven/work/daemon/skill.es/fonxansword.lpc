// fonxansword.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「峰迴路轉」﹐手中$w如一條銀蛇般刺向$n的$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N使出封山劍法中的「空山鳥語」﹐劍光霍霍斬向$n的$l",
		"dodge":		-20,
		"damage":		30,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N一招「御風而行」﹐身形陡然滑出數尺﹐手中$w斬向$n的$l",
		"dodge":		-30,
		"damage":		20,
		"damage_type":	"割傷"
	]),
	([	"action":		"$N手中$w中宮直進﹐一式「旭日東昇」對準$n的$l刺出一劍",
		"dodge":		-40,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N縱身一躍﹐手中$w一招「金光瀉地」對準$n的$l斜斜刺出一劍",
		"dodge":		-40,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N的$w憑空一指﹐一招「童子引路」刺向$n的$l",
		"dodge":		20,
		"damage":		40,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N手中$w向外一分﹐使一招「柳暗花明」反手對準$n$l一劍刺去",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"刺傷"
	]),
	([	"action":		"$N橫劍上前﹐身形一轉手中$w使一招「空谷秋虹」畫出一道光弧斬向$n的$l",
		"dodge":		-30,
		"damage":		10,
		"damage_type":	"割傷"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的內力不夠﹐沒有辦法練封山劍法。\n");

	if( (string)me->query_skill_mapped("force")!= "fonxanforce")
		return notify_fail("封山劍法必須配合封山派內功\才能練。\n");

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
	||	(int)me->query("force") < 3 )
		return notify_fail("你的內力或氣不夠﹐沒有辦法練習封山劍法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所學練了一遍封山劍法。\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("swordsman") + "/fonxansword/" + action;
}
