// protected.c
#include <ansi.h>
#include <login.h>
int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->delete("done");
		tell_object(me, HIY "你又可以呼叫保护了.\n" NOR);
		return 0;
	}
//	tell_object(me, "debug: " + duration + " beats more to go...\n");
	me->apply_condition("protected", duration - 1);
	return 1;
}
