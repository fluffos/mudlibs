#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail("你要解谁的生死符？\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("你的本门内功不够娴熟，不能解生死符。\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 20 )
		return notify_fail("你的天山六阳掌不够娴熟，不能解生死符。\n");

	if (!objectp(obj=present("jiudai", me)))
           return notify_fail("你身上没有酒袋，不能化冰为水。\n");

	if (me->query("neili")<200)
		return notify_fail("你真气不足。\n");

       if (!target->query_condition("ss_poison"))
            return notify_fail("目标没有中生死符。\n");

	msg = CYN "$N拍向$n，化冰为水解了生死符。\n";
	me->add("neili",-200);
	me->start_busy(2);
	 target->apply_condition("ss_poison", 0);

		message_combatd(msg, me, target);
	return 1;
}
