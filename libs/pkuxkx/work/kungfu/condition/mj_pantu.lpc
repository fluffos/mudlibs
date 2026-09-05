// Code of ShenZhou
// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
                tell_object(me, "你悔过自新，被允许离开水牢！\n");
                me->set_temp("mj_canleave",1);
		return 0;
	}
        me->apply_condition("mj_pantu", duration - 1);
	    return 1;
}
