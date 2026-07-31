// /u/beyond/mr/skill/shenyuan-gong.c 神元功
// this is made by beyond
// update 1997.6.23
inherit FORCE;
int valid_enable(string usage)
{
        return usage == "force";
}
int valid_learn(object me)
{

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，无法领会神元功。\n");
        if ((int)me->query_skill("murong-xinfa", 1) <= (int)me->query_skill("shenyuan-gong", 1))
                return notify_fail("你的慕容心法修为不够，无法领会更高深的神元功。\n");
        return 1;
}

int practice_skill(object me)
{
       return notify_fail("神元功只能用学(learn)的来增加熟练度。\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shenyuan-gong/" + func;
}
