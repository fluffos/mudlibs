// Zine fuchen

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) 
        {
            me->delete("taijian/nofuchen");
		    return 0;
	    }
    me->apply_condition("fuchen", duration - 1);
	return 1;
}
