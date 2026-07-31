// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
		return notify_fail("你的九阴真功修为还不够。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_jing") >= (int)target->query("max_jing") )
		return notify_fail( target->name() + "现在精气充沛！\n");

	message_vision(
		HIB "$N深深的吸了口气，将手掌贴在$n背心，九阴真气运转一周天....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吁了一口气，精神看来好多了。\n" NOR,
		me, target );

	target->receive_curing("jing", 10 + (int)me->query_skill("force")/2 );
	target->add("jing", 10 + (int)me->query_skill("force")/2 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
	me->add("neili", -150);
        target->start_busy(2);
	return 1;
}

