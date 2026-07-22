// sanxiao_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("qi", 500);
	me->receive_damage("qi", 500);
	me->apply_condition("sanxiao_poison", duration - 1);
message_vision(HIG"$N脸上忽然露出诡异的一笑，看来是"HIB"三笑逍遥散"HIG"发作了！\n" NOR, me);
	if( duration < 1 ) return 0;
	return 1;
}
