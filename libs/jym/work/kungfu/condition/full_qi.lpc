 //Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_qi", duration - 1);
        if(me->query("qi")<me->query("max_qi"))
        me->set("qi", me->query("max_qi"));
        if(me->query("eff_qi")<me->query("max_qi"))
        me->set("eff_qi", me->query("max_qi"));

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

