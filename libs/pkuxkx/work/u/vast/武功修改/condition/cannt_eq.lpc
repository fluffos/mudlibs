
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
                tell_object(me, HIY"你从独孤九剑的震慑中恢复了过来！\n"NOR);
		return 0;
	}
	me->apply_condition("cannt_eq", duration - 1);
	return 1;
}
