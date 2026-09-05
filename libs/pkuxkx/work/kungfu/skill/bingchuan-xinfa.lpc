// bingchuan-xinfa.c 冰川心法
// by hubo 2008-4-27

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("冰川心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"bingchuan-xinfa/" + func;
}
