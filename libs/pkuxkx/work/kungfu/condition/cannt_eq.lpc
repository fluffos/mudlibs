inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>



int update_condition(object me, int duration)
{
	if (duration < 1)
	{
                tell_object(me, HIY"你双手的伤势恢复了！\n"NOR);
		return 0;
	}
	me->apply_condition("cannt_eq", duration - 1);
	return 1;
}
