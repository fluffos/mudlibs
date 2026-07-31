// focus.c, 聚力 by darken@SJ

#include <ansi.h>

int exert(object me)
{
	int improve;
	if(!me->is_fighting() )
		return notify_fail("你只能在战斗中聚力。\n");

	if ((int)me->query_skill("guiyuan-tunafa", 1) < 100)
		return notify_fail("你的归元吐纳法法修为还不够。\n");

	if(me->query_temp("tz/focus"))
		return notify_fail("你已经在使用了。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够。\n");
      
	message_vision(HBBLU"$N一凝神，手上的力道似乎增强了。\n" NOR, me);
	improve = me->query_skill("force")/10;
	if (improve > 50)
		improve = 50;
	me->add("neili", -300-random(200));
	me->start_exert(1, "聚力");
	me->start_busy(random(2));
	me->set_temp("tz/focus", improve);
	me->add_temp("apply/attack", improve);
	me->add_temp("apply/damage", improve/2);
	call_out("remove_eff", 1, me, improve);
	return 1;
}

void remove_eff(object me, int count)
{
	if (!me) return;
	if (!me->is_fighting()
	|| --count < 1) {
		int improve = me->query_temp("tz/focus");

		me->delete_temp("tz/focus");
		me->add_temp("apply/attack", -improve);
		me->add_temp("apply/damage", -improve/2);
		return;
	}
	call_out("remove_eff", 1, me, count);
}
