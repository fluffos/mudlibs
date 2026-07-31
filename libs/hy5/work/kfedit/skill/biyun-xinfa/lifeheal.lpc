// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if(target == me)
		return notify_fail("你没有为自己疗伤的能力！\n");

	if( (int)me->query("max_neili") < 400 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIG "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	if ((int)me->query_skill("biyun-xinfa", 1) > 200)
{
	if (target->query_condition("zm_poison"))
		target->apply_condition("zm_poison",0);
	else if (target->query_condition("tmpili_poison"))
		target->apply_condition("tmpili_poison",0);
	else if (target->query_condition("tmzhuihun_poison"))
		target->apply_condition("tmzhuihun_poison",0);
        else if (target->query_condition("snake_poison"))
        {          target->clear_condition("snake_poison");}
        else if (target->query_condition("wugong_poison"))
        {          target->clear_condition("wugong_poison");}
        else if (target->query_condition("zhizhu_poison"))
        {          target->clear_condition("zhizhu_poison");}
        else if (target->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        else if (target->query_condition("chanchu_poison"))
        {          target->clear_condition("chanchu_poison");}
	me->add("neili", -100);
}
	me->add("neili", -100);
	me->set("jiali", 0);
                me->start_busy(5);
                target->start_busy(5);
	return 1;
}
