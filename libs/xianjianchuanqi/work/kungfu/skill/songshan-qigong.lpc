// songshan-qigong.c 嵩山气功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
       if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("你的基本内功火候还不够。\n");

       return 1;
}

int practice_skill(object me)
{
        return notify_fail("嵩山气功只能靠领悟和研习。\n");
}

string exert_function_file(string func)
{
       return __DIR__"songshan-qigong/" + func;
}
