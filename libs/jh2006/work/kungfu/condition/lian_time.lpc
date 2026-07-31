// lian_time.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
              me->clear_condition("lian_time");
                }
        if (!duration) return 0;
        me->apply_condition("lian_time", duration - 1);
        return 1;
}
