// Code of ShenZhou
// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    
	if (duration < 1) 
        {
            me->delete("chblk_on");
            tell_object(me, "禁言期满，对你的惩罚结束！下次再犯不再轻饶。\n");
		    return 0;
	    }
    me->apply_condition("unchblk", duration - 1);
	return 1;
}
