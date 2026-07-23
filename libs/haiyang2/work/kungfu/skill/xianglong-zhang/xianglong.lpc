// reserve.c 轻身

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( (int)me->query_temp("xianglong") ) 
		return notify_fail("你已经在运功中了。\n");
	if( !me->is_fighting() )
		return notify_fail("降龙大法只能在战斗中使用。\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

       skill = me->query_skill("xianglong-zhang",1);
	message_combatd( HIR "$N深吸一口气，运起降龙大法，结果越战越勇！\n" NOR, me);

	me->set_temp("xianglong", 1);

//	message_combatd(msg, me, target);

	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/dodge", skill/4);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/4 :), skill);

	me->add("neili", -100);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
int skill;
	skill = me->query_skill("xianglong-zhang",1);
	me->add_temp("apply/attack", -d_amount);
	me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("xianglong");
	tell_object(me, CYN "你的降龙大法运行完毕，将内力收回丹田。\n");
}
