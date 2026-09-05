// kongdong xinfa.c

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int practice_skill(object me)
{
        return notify_fail("崆峒心法只能用学(learn)来增加熟练度。\n");
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候尚浅，现在学习崆峒心法有害无益！。\n");
        if ((int)me->query_skill("force", 1) <= (int)me->query_skill("kongdong-xinfa",1))
                return notify_fail("你的基本内功修为还不够，你应该先在基本内功上下点功夫。\n");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"kongdong-xinfa/" + func;
}

