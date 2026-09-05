// 烫伤 Zine

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) 
        {
            tell_object(me, "终于，你的烫伤痊愈了！\n");
		    return 0;
	    }
        message_vision(RED"$N吹了吹被烫红的手，可是还是钻心地疼！\n"NOR,me);
        if (me->query("qi")<200)
        {
            message_vision("$N疼痛难忍，晕了过去。",me);
            me->unconcious();
        }
        else
        {
            me->add("qi",-200);
        }
        me->apply_condition("tangshang", duration - 1);
	    return 1;
}
