// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("jing", 10, "中蛇毒");
	me->receive_damage("qi", 10, "中蛇毒");
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "你中的" HIR "蛇毒" HIG "发作了！\n" NOR );
    COMBAT_D->report_status(me);
	if( duration < 1 ) return 0;
	return 1;
}
