
inherit SKILL;

string *dodge_msg = ({
	"$n一招「飞流直下」身形一飘，有如飞瀑，直退出数丈之外。\n",
	"$n步法翩翩，身影左躲右闪，，一式「逶迤盘桓」避开$N的锋芒。\n",
	"$n腾空而起，身形在空中连换三个方向，一式「一波三折」，轻轻松松地闪过。\n",
	"$n步法连绵，身形连续晃动，一招「溪水潺潺」腾空而起，避了开去。\n",
	"$n身似流水，向旁跃出三尺，一招「细水常流」，身子轻轻飘了开去。\n",
	"$n腰身一矮，却突然腾空跃起，「深谷喷泉」轻轻闪过。\n",
	"但是$n一招「水复山穷」使出，早已绕到$N身後！\n",
        "但是$n身形飘忽，轻轻一纵，一招「流润翠微」，避开这一击。\n",
        "$n身形往上一拔，一招「覆水能收」，一个转折落在数尺之外。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力不够，没有办法练流泉步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("你的气或内力不够，不能练流泉步。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return __DIR__"liuquan-steps/" + action;
}
