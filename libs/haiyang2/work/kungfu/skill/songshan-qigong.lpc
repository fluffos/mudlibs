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
       if ((int)me->query("jing") < 50)
		return notify_fail("你的精力不够练嵩山气功。\n");
       me->receive_damage("jing", 30);
       return 1;
}

string exert_function_file(string func)
{
       return __DIR__"songshan-qigong/" + func;
}
