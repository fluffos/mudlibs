// quanzhen-xinfa 全真心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "xiantian-gong" ||
	       force == "duanshi-xinfa";
}

int valid_learn(object me)
{
       if (me->query_skill("force",1) <= me->query_skill("quanzhen-xinfa",1) )
	return notify_fail("你的基本内功基础不够，无法领会更高深的全真心法。\n");
	   else    return 1;
}

int practice_skill(object me)
{
	return notify_fail("全真心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"quanzhen-xinfa/" + func;
}
