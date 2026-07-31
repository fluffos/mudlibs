// reserve.c 神足
// 青云(diabio)版权所有2001年
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( (int)me->query_skill("shayi-xinfa", 1) < 100 )
		return notify_fail("你的杀意心法不够娴熟，不会神足。\n");
       if(me->query("shayi-xinfa") !=1 )
                        return notify_fail("你还没有领悟到神足，无法使用。\n");

	if( (int)me->query_skill("wuxing-dun", 1) < 100 )
		return notify_fail("你的五行遁还不够娴熟，用不了神足。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("sy_sz") ) 
		return notify_fail("你已经用了神足了。\n");

	skill = me->query_skill("shayi-xinfa",1);
    message_vision( HIR  "$N暗运内力，运起"HIY"[神足]"NOR""HIR"，顿时内息暗生，速度大增!\n" NOR, me);

	me->add_temp("apply/attack", skill/6);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("sy_sz", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("sy_sz");
	tell_object(me, HIR "你的内息不够，只好一跃而起，将内力收回丹田。\n");
}
