// whuan 段家心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣禅功。\n");
   	return 1;
}

int practice_skill(object me)
{
	return notify_fail("段家心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"duanjia-xinfa/" + func;
}



