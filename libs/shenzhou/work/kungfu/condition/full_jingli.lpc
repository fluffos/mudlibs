//Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_jingli", duration - 1);
        if(me->query("jingli")<me->query("max_jingli")*3/2 )
        me->set("jingli", me->query("max_jingli")*8/5 );

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

