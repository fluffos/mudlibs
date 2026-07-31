// powerup.c 碧云心法加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能用碧云心法来提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
	HIG "$N微一凝神，运起碧云心法，脸上泛过一层碧绿色,身上衣衫如鼓风般扬起。\n" NOR, me);

	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/dodge", skill/5);
	me->set_temp("powerup",1);

       me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/3);

       if( me->is_fighting() ) me->start_busy(1);

	return 1;
}

void remove_effect(object me, int amount)
{
  if ( (int)me->query_temp("powerup") ) {
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的碧波心法运行完毕，将内力收回丹田。\n");}
}
