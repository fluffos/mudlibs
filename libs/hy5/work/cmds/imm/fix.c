#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
    int i;
    object obj;

if (me->query_temp("apply/attack")<0)
{
me->set_temp("apply/attack",0);
}
if (me->query_temp("apply/defense")<0)
{
me->set_temp("apply/defense",0);
}
if (me->query_temp("apply/dodge")<0)
{
me->set_temp("apply/dodge",0);
}
if (me->query_temp("apply/dexerity")<0)
{
me->set_temp("apply/dexerity",0);
}
if (me->query_temp("apply/strength")<0)
{
me->set_temp("apply/strength",0);
}
if (me->query_temp("apply/damage")<0)
{
me->set_temp("apply/damage",0);
}
if (me->query_temp("apply/armor")<0)
{
me->set_temp("apply/armor",0);
}
if (me->query_temp("apply/intelligence")<0)
{
me->set_temp("apply/intelligence",0);
}
if (me->query_temp("apply/karey")<0)
{
me->set_temp("apply/karey",0);
}
if (me->query_temp("apply/percao")<0)
{
me->set_temp("apply/percao",0);
}
if (me->query_temp("apply/constitution")<0)
{
me->set_temp("apply/constitution",0);
}

    write(HIR"恢复状态成功。请用SCORE查看。\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
指令格式 : fix

利用此指令可完全恢复玩家的初始的状态。
HELP
    );
    return 1;
}

