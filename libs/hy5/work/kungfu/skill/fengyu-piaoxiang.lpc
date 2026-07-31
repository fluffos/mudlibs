
inherit SKILL;

string *dodge_msg = ({
	"$n一声大喝使出「风生万马间」，幻出满天掌影，将$N所有招式化于无形。\n",
	"$n使出一招「冥冥鸟去迟」，猛然纵起丈余，结果$N扑了个空。\n",
	"$n一个「漠漠帆来重」，随着$N的攻势飘起，从容躲过这一招。\n",
	"$n双足一点，斜斜飞起，使出「皎皎孤月轮」已闪到$N身侧。\n",
	"$n身形一摇，幻出几个人影，一招「山风吹空林」躲过了$N的攻势。\n",
       "$n一招「千峰同一色」纵身跃起，倏忽已落至$N身后。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge"||usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够，没有办法练风雨飘香步。\n");

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
		return notify_fail("你的气或内力不够，不能练风雨飘香步法 。\n");
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
        return __DIR__"fengyu-piaoxiang/" + action;
}

