// powerup.c 葵花心法加力

#include <ansi.h>
inherit F_CLEAN_UP;
string query_name() { return "葵花"ZJBR"战气"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能提升自己的战斗力。\n");
	if( (int)me->query("neili")<200)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");
	if( (int)me->query_skill("kuihua-xinfa",1) < 50)
		return notify_fail("你的葵花心法还不够精熟。\n");

	skill = me->query_skill("force");

	message_combatd(
	HIC "$N身形如鬼如魅，飘忽来去，直似轻烟，"HIW"周身竟无半分破绽"HIC"！\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   me->add_temp("apply/attack", -skill/3);
   me->add_temp("apply/dodge", -skill/3);

	me->delete_temp("powerup");
	tell_object(me, "你的葵花心法运行完毕，将内力收回丹田。\n");
}
