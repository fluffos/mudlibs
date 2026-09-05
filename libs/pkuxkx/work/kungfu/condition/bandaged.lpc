// bandaged.c
inherit F_CLEAN_UP;
#include <condition.h>

int update_condition(object me, int duration)
{
        if( !duration ) return 0;
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") )
		me->receive_curing("qi", 3);
	
	me->apply_condition("bandaged", duration - 1);

	return CND_CONTINUE;
}
