                                                 //Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_water", duration - 1);
        if(me->query("water") < me->max_water_capacity())
        me->set("water", me->max_water_capacity());

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

