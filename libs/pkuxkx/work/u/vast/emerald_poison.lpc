#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int lev;
	if( duration < 1 ) return 0;

        message_vision(HIG"$N身体一阵颤抖，痛苦地哼了一声。混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, me);

	me->receive_wound("qi", 100 + random(100));
	me->receive_wound("jing", 50 + random(100));

	if (!random(3)) me->start_busy(1);
	me->apply_condition("emerald_poison", duration - 1);

	if( duration < 1 )
   	{
   		tell_object(me,HIG"你身上的毒性终于全部消失了。\n"NOR);
   		return 0;
   	}
	return CND_CONTINUE;
}
