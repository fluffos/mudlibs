// reserve.c 蛤蟆功经脉倒转

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount);

int exert(object me, object target)
{
	object weapon;
	
	string msg;
       int skill;
       if( !me->query("reverse"))
                return notify_fail("你的外功中没有这种功能。\n");

       if( me->query("id") != DADIZI_D->query_name("baituo") ) 
		return notify_fail("你不是白驼山大弟子，没有得到真传，经脉倒转就是找死呢。\n");
		
       if( target != me ) 
		return notify_fail("你只能使自己的经脉倒转。\n");

	if( (int)me->query_skill("hamagong", 1) < 120 )
		return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");

	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("hmg_dzjm") ) 
		return notify_fail("你已经倒转经脉了。\n");

	msg = HIB "$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，攻击防御同时大增。\n"NOR;
	message_vision(msg, me);
       
      skill = (int)me->query_skill("hamagong",1)/12;

	me->add_temp("apply/attack", skill*3);
	me->add_temp("apply/dodge", skill*5);
        me->add_temp("apply/parry", skill*3);
        me->add_temp("apply/strength", skill/2);
        me->add_temp("apply/armor", skill*3);

	me->set_temp("hmg_dzjm", 1);

//	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/2 :), skill);
       me->start_call_out(__FILE__, "remove_effect", skill*6, me, skill);
	me->add("neili", -300);
	if( me->is_fighting() ) 
         me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount)
{
	me->add_temp("apply/attack", - a_amount*3);
	me->add_temp("apply/dodge", - a_amount*5);
	me->add_temp("apply/parry", - a_amount*3);
	me->add_temp("apply/strength", - a_amount/2);
	me->add_temp("apply/armor", - a_amount*3);
	me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "你双手一撑，一跃而起，将内力收回丹田。\n"NOR);
}
