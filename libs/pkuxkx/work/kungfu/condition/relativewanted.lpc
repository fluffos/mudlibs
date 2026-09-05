// Code of ShenZhou
// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) 
        {
            if (me->query_temp("relative/wanted"))
            {
                me->delete_temp("relative/wanted");
                tell_object(me, BLINK+CYN+"你的动作太慢了，白白错失一个好机会。\n"NOR);
            }
            
		    return 0;
	    }
        me->apply_condition("relativewanted", duration - 1);
	    return 1;
}
