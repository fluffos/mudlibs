// 冰蚕衣减内力效果 by picewolf 2009-3-31
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
    me->add("neili",-500);
	me->apply_condition("bingcan_handu", duration);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
