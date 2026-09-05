// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能用临济十二庄来提升自己的战斗力。\n");
        
	if ((int)me->query_skill("linji-zhuang", 1) < 40)
		return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
               return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
        HIR "$N微一凝神，运起临济十二庄，脸上泛起一抹艳红。\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/3);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的临济十二庄运行完毕，将内力收回丹田。\n");
}
