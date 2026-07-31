// bandaged.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( (int)me->query("eff_jingli") < (int)me->query("max_jingli") )
                me->receive_curing("jingli", 3);

        me->apply_condition("jingli_curing", duration - 1);
        if( !duration ) return 0;

        return CND_CONTINUE;
}
