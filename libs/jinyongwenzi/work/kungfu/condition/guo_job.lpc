#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        if (duration < 1) {
            tell_object(me, HIR"你突然发现襄阳主营放出信号火焰！\n"NOR);
            tell_object(me, HIR"看来似乎是要求援助的信号。\n"NOR);
            me->delete_temp("xy");
            return 0;        
        }
        me->apply_condition("guo_job", duration - 1);
        return 1;
}

