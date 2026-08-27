// liuh-ken.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「古松掛月」﹐對準$n的$l「呼」地一拳",
		"dodge":		-40,
		"parry":		40,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N揚起拳頭﹐一招「傲雪冬梅」便往$n的$l招呼過去",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N左手虛晃﹐右拳「孤崖聽濤」往$n的$l擊出",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀傷"
	]),
	([	"action":		"$N步履一沉﹐左拳拉開﹐右拳使出「荒山虎吟」擊向$n$l",
		"dodge":		-30,
		"parry":		30,
		"damage_type":	"瘀傷"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("練柳家拳法必須空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
