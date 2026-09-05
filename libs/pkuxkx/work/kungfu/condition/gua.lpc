// Code of ShenZhou
// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) 
        {
            me->delete_temp("thnewbiejob/taolin");
            tell_object(me, BLINK+CYN+"天色大变，陆乘风给你算的卦也不那么准了。\n"NOR);
		    return 0;
	    }
        me->apply_condition("gua", duration - 1);
	    return 1;
}
