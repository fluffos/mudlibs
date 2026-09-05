//碧血心法

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	if ( ((int)me->query_skill("kuangfeng-xinfa", 1)) < 100 )
		return notify_fail("你的狂风心法火候还不够，无法领会碧血心法。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("碧血心法只能用学的，或是从读书中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bixue-xinfa/" + func;
}

string query_yinyang()
{
	return "少阴";
}
