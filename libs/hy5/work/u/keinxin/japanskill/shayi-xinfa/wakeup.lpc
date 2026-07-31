// wakeup 救人

#include <ansi.h>

int exert(object me, object target)
{
    if( !objectp(target) )
		return notify_fail("你要用真气救谁？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法救人！\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够。\n");


	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 250)
		return notify_fail("你的杀意心法修为还不够。\n");

        if( living(target) )
		return notify_fail( target->name() +
			"还没有昏迷不醒啊！\n");

	message_vision(
          HIG "$N收起了杀气，将手掌贴在$n背心，以救世之心将真气输入$n体内......\n\n"
		"$n只觉一股真气源源不绝的输入体内，瞬间流遍全身各大穴位。$n吐出一\n\n"
		"口瘀血，悠悠醒来！\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/4 );
	target->add("qi", 10 + (int)me->query_skill("force")/4 );
  target->remove_call_out("revive");
  target->revive();
  target->reincarnate();

	me->add("neili", -800);
	me->set("jiali", 0);
        me->start_busy(10);
	return 1;
}
