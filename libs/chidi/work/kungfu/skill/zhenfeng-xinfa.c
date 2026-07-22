//zhenfeng-xinfa.c （震风心法）

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "无性" )
                return notify_fail("「震风心法」讲的是阴阳分明，以公公无根无性之身，如何修得！\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("「震风心法」全在一心尚武，有违佛家清静之道，"
                        +RANK_D->query_respect(me)+"还是请回吧。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("「震风心法」只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhenfeng-xinfa/" + func;
}
