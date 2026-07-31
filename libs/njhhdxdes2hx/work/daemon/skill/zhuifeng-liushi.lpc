// zhuifeng-liushi.c 追风六式

inherit SKILL;

mapping *action = ({
([	"action" : "$n一招「孤飞一雁」，纵身一跃，飘至半空 。转眼间便绕到了$N的身后。\n",
	"dodge"  : 20
]),
([	"action" : "$n一招「雁逐明月」，全身笔直，拔地而起。\n",
	"dodge"  : 40
]),
([	"action" : "$n一式「「天在清溪底」」身形急拔而起。\n",
	"dodge"  : 60
]),
([	"action" : "$n一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n",
	"dodge"  : 80
]),
([	"action" : "$n一式「如觅水影」伏下身去，在半空中一转，已落到几丈远的地方。\n",
	"dodge"  : 100
]),
([	"action" : "$n一式「苍龙出水」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
	"dodge"  : 120
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("zhuifeng-liushi");

	if (level < 60 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练追风六式。\n");
	me->receive_damage("qi", 30);
	return 1;
}
