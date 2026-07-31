
inherit SKILL;

string *dodge_msg = ({
	"$n身形陡地变得飘忽不定，令$N无法看清。\n",
	"$n双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
	"$n如一阵清风，舒缓地闪过了$N的凌厉攻势。\n",
	"$n便如闲庭信步，在弹指间已然退出丈外。\n",
	"可是$n左一转，右一绕，身影已消失不见。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge"||usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法练幻梦步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("你的气或内力不够，不能练幻梦步法。\n");
	me->receive_damage("jing", 30);
	me->add("neili", -3);
	return 1;
}
int effective_level() { return 19;}

int learn_bonus()
{
	return -90;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 40;
}


string perform_action_file(string action)
{
        return __DIR__"meng-steps/" + action;
}

