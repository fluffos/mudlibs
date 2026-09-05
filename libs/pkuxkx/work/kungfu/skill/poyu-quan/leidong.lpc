// leidong 雷动九天
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount, int amount1);

int perform(object me)
{
	int skill, count, count1;

	if( (int)me->query_temp("leidong") ) 
		return notify_fail("你已经在运功中了。\n");
	if( !me->is_fighting() )
		return notify_fail("雷动九天只能在战斗中使用。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");

	count = me->query_str();
	skill = me->query_skill("cuff");
	if( skill < 135  ) 
		return notify_fail("你的破玉拳修为还不够。\n");

	me->add("neili", -400);
	message_combatd( HIM "$N深深吸了一口气，脸上顿时紫气大盛，出手越来越重！\n" NOR, me);

	count = me->query("str") + (int)(skill/10);
	count1 = me->query("dex") + (int)(skill/10);

	me->add_temp("str", count);
	me->add_temp("dex", count1);
	me->set_temp("leidong", 1);
	//me->start_call_out( (: call_other,  __FILE__, "remove_effect", me, count, count1 :), skill/3 );
    me->start_call_out(__FILE__, "remove_effect", skill/3, me, count, count1);

	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ( (int)me->query_temp("leidong") ) 
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount1);
		me->delete_temp("leidong");
		tell_object(me, CYN"你的雷动九天运行完毕，将内力收回丹田。\n"NOR);
		me->start_busy(4);
	}
}
