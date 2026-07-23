// /kungfu/condition/pfm_bishen.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if ( duration < 1 ) 
        {
                tell_object(me, WHT "你将身体放松下来，顿感到一阵清凉，心里也不似刚才般难受欲呕啦。\n" NOR);
                return 0;
        }
//      tell_object(me, "Condition apply spare only " + duration + " times...\n");
        me->apply_condition("pfm_dzxy", duration - 1);
        return 1;
}
