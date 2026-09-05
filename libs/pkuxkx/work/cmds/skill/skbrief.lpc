// skbrief.c 简化信息

#include <ansi.h>

inherit F_CLEAN_UP;


int main(object me, string arg)
{
    mapping lrn;
    if(!me->query_skill(arg))
    {
        write("0\n");
        return 1;
    }

    lrn = me->query_learned();

    printf("#%d/%d\n",me->query_skill(arg,1),lrn[arg]);
    return 1;
}



int help(object me)
{
        write(@HELP
指令格式 : skbrief 技能

这个指令可以让你查询某项技能的等级和学习点数。


HELP
    );
    return 1;
}
