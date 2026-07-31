 //Pwoered By yeer@shenzhou

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        me->apply_condition("full_jing", duration - 1);
        if(me->query("jing")<me->query("max_jing"))
        me->set("jing", me->query("max_jing"));
        if(me->query("eff_jing")<me->query("max_jing"))
        me->set("eff_jing", me->query("max_jing"));

        if( duration < 1 )
        {
                return 0;
        }
        return 1;
}

