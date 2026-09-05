//毒蛇内功

inherit FORCE;


int valid_enable(string usage)
{
        return usage == "force";
}
int valid_learn(object me)
// need more limit here
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");
        return 1;
}


string exert_function_file(string func)
{
        return __DIR__"dushe-neigong/" + func;
}

