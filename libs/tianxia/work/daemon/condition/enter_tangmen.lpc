// enter_tangmen.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int tt;

	tt = me->query("decide_enter_tangme_time");
	if(!tt)
	{
		me->set("decide_enter_tangme_time", time());
		return CND_NO_CHANGE;
	}

	if(time() - tt < 3*1440)
		return CND_NO_CHANGE;

	me->apply_condition("tangdu", 5);
	return CND_STOP;
}
