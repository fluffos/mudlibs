// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");
        if( me == target ) {
                write( HIY "你全身放松，盘膝坐下，运起先天功开始疗伤。\n" NOR);
                message("vision",
                        HIY + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,
                        environment(me), me);
	}
	else {message_vision(
                RED "$N坐了下来运起先天功，将手掌贴在$n背心，缓缓地将真气输入$n体内......\n"
                   "$n只觉一股暧阳阳的真气源源不绝的输入体内，只见$N头顶上丝丝白气冒出。$n\n"
                  "吐出一口瘀血，脸色看起来红润多了，伤势有了很大的好转，全身真气无比充沛。\n" NOR,
		me, target );
	}
	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -100);
	me->set("jiali", 0);

	return 1;
}
