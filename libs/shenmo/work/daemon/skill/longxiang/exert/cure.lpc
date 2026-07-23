// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target || target == me)
		return notify_fail("你要用真气为谁治疗？\n");

	if( me->is_fighting() || target->is_fighting() || !living(target))
		return notify_fail("战斗中无法运功治疗！\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够。\n");
        if( !target->query_condition("dashouyin"))
                return notify_fail("对方并没中大手印内伤，你不用为他人疗伤。\n");

//        if( (int)me->query_skill("medicine", 1) < 40 )
//                return notify_fail("你本草术理的等级不够，无法为他人疗伤。\n");
        if( (int)me->query_skill("longxiang", 1) < 80 )
                return notify_fail("你内功等级不够，无法为他人疗伤。\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") / 2 )
		return notify_fail( target->name()+"现在受伤不是很重，你最好再观察一下！\n");

	else {message_vision(
                HIY "$N口念密宗伏魔真言，将手掌贴在$n背心，缓缓地将真气输入$n体内......\n"
                   "$n随即吐出一口瘀血，脸色看起来红润多了，伤势有了很大的好转。\n" NOR,
		me, target );
	}
	target->receive_curing("qi", 10 + (int)me->query_skill("force")/2 );
	target->add("qi", 10 + (int)me->query_skill("force")/2 );
    if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));
        target->clear_condition("dashouyin");
	me->add("neili", -300);

	return 1;
}
