// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
    if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if(target == me)
		return notify_fail("你没有为自己疗伤的能力！\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
		return notify_fail("你的九阴真功修为还不够。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		return notify_fail( target->name() + "并未受伤！\n");

	message_combatd(
		HIB "$N坐了下来运起内功，将手掌贴在$n背心，按照九阴锻筋篇开始运功疗伤....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/2 );
	target->add("qi", 10 + (int)me->query_skill("force")/2 );
	if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
	if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));
	me->add("neili", -150);
        target->start_busy(2);
	return 1;
}
