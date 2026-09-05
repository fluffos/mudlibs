// curing.c 养精
inherit F_CLEAN_UP;
#include <condition.h>

int update_condition(object me, int duration)
{
        if( !duration ) return 0;
        if( (int)me->query("eff_jing") < (int)me->query("max_jing") )
                me->receive_curing("jing", 30);

        me->apply_condition("jing_curing", duration - 1);

        return CND_CONTINUE;
}
