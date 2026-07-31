#include <ansi.h>
int update_condition(object me, int duration)
{                                        
        if (duration < 1) {
            tell_object(me, HIW"你突然发现襄阳附近蒙哥主营放出信号火焰！\n"NOR);
            tell_object(me, HIW"看来似乎是要求援助的信号。\n"NOR);
            return 0;        
        }
        me->apply_condition("xyjob", duration - 1);
        return 1;
}

