// taohua-force.c 桃花内功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{


	if ( me->query("gender") == "无性" )
		return notify_fail("你无根无性，阴阳不调，难以领会高深的桃花内功。\n");


	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");


	return 1;
}

int practice_skill(object me)
{
	return notify_fail("桃花内功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taohua-force/" + func;
}

