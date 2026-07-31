// kuihua-xinfa.c 葵花心法
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    return notify_fail("葵花心法不能学。\n");
}
int practice_skill(object me)
{
    return notify_fail("葵花心法不能练。\n");
}
string exert_function_file(string func)
{
    return __DIR__"kuihua-xinfa/" + func;
}

void skill_improved(object me)
{
        int s;
        s=me->query_skill("kuihua-xinfa",1);
    if (s%10==0) {
                tell_object(me, HIW"你的葵花神功已经修炼到第"+HIY+CHINESE_D->chinese_number(s/10)+HIW+"重了。\n" NOR);
    }
}

