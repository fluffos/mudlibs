// jiuyang-shengong.c 九阳神功
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang", 1);

				    
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");



	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang/" + func;
}
