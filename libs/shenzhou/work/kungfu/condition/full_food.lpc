//Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_food", duration - 1);
        if(me->query("water") < me->max_food_capacity())
        me->set("food", me->max_food_capacity());

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

