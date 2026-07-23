// kill_guo.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
              me->clear_condition("kill_guo");
        }
        if (!duration) return 0;
        me->apply_condition("kill_guo", duration - 1);
        return 1;
}
