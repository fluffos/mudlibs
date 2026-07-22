// kunlun-shenfa.c (kunlun) 昆仑身法

inherit SKILL;

mapping *action = ({
([	"action" : "$n一式「雁落平沙」，变招奇速，右足向前踢出，身子已然腾起，轻轻巧巧地落在一旁。\n",
	"dodge"  : 15
]),
([	"action" : "$n一式「玉龙飞起」，纵身高跃，半空中一折一转，已飘身在数丈之外。\n",
	"dodge"  : 25
]),
([	"action" : "$n一式「夏日消融」，两足足跟不动，足尖左磨，身子随之右转，卸开了$N这一招。\n",
	"dodge"  : 35
]),
([	"action" : "$n一式「枯松倒挂」，只见$n身子后仰，双掌往地下一撑，身子借势倒射而出，$N便已打$n不着。\n",
	"dodge"  : 45
]),
([	"action" : "$n一式「晴雪飞滩」，纵高伏低，东奔西闪，身形飘忽不定，$N手无足措，只得回招自守。\n",
	"dodge"  : 55
]),
([	"action" : "$n一式「冰丝带雨」，突然反手一招，竟然是两败俱伤的打法，趁$N手忙脚乱安全脱身。\n",
	"dodge"  : 65
]),
([	"action" : "$n一式「寒江钓雪」，不招不架，只微微一侧身，$N犹如暴风骤雨般的进攻便即落空。\n",
	"dodge"  : 75
]),
([	"action" : "$n一式「鱼龙潜跃」，陡然间身形拔起，直冲云霄，直如鹰隼，几个盘旋，飘飘荡荡落在数丈之外。\n",
	"dodge"  : 85
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("kunlun-shenfa");

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
	int na, nk;
	na = (int)me->query_skill("art", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") == "何足道" )
	{
		if ( na<120 && na<=nk )
		return notify_fail("琴棋书画当与武功并重，不然你无法领会更高深的昆仑身法。\n");
	}

	return 1;
}

string query_dodge_msg(object me)
{
	object ob;
	mapping action;

	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	int na, nk;
	na = (int)me->query_skill("art", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") == "何足道" )
	{
		if ( na<120 && na<=nk )
		return notify_fail("琴棋书画当与武功并重，不然你无法领会更高深的昆仑身法。\n");
	}

	if( (int)me->query("jingli") < 40 )
		return notify_fail("你的精力太差了，不能练昆仑身法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
