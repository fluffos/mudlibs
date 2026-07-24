// reserve.c 轻身

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( (int)me->query_skill("yunlong-shengong", 1) < 100 )
		return notify_fail("你的云龙神功不够娴熟，不会轻身。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("yl_dzjm") ) 
		return notify_fail("你已经用了轻身了。\n");

	skill = me->query_skill("yunlong-shengong",1);
	msg = HIR  "$N高高跳起，运起云龙神功，顿时内息暗生，轻功大增。\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("yl_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
int skill;
	skill = me->query_skill("yunlong-shengong",1);
	me->add_temp("apply/attack", -skill/5);
	me->add_temp("apply/dodge", -skill/2);
	me->delete_temp("yl_dzjm");
	tell_object(me, HIR "你的内息不够，只好一跃而起，将内力收回丹田。\n");
}
