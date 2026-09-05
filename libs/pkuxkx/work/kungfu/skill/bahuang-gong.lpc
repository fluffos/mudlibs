// bahuang-gong.c 八荒六合唯我独尊功
#include <ansi.h>

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候尚浅，现在学习八荒六合唯我独尊功有害无益！。\n");
        if ((int)me->query_skill("force", 1) <= (int)me->query_skill("bahuang-gong",1))
                return notify_fail("你的基本内功修为还不够，你应该先在基本内功上下点功夫。\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"bahuang-gong/" + func;
}

string translate(string skill)
{
  return "xiaoyao-neigong";
}