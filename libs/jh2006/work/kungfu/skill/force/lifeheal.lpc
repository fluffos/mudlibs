// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	string msg, force;

	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( ! present(target,environment(me)))
		return notify_fail("这里有这个人吗？\n");

	if( target == me)
		return notify_fail("你帮自己疗伤，可以用exert heal指令。\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( target->is_busy())
		return notify_fail( target->name()+ "正忙着呢！\n");

	if( target->query("env/no_lifeheal"))
		return notify_fail( target->name()+"拒绝你帮其疗伤。\n");

	if( !living(target) || !target->query("can_speak"))
		return notify_fail("它不是活物，给它疗伤干什么？\n");

	if(!(force = me->query_skill_mapped("force")))
		return notify_fail("你还没有选择你要使用的内功。\n");

	if(me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if(me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if( me->query_skill("force") < 150 ) 
		return notify_fail("你的内功等级还太低，不能运功疗伤。\n");

	if( me->query_skill("medicine", 1) < 120 )
		return notify_fail("你本草术理的等级不够，无法为他人疗伤。\n");

	if(target->query_temp("reverse_healing"))
		return notify_fail("他受到了逆转乾坤的攻击，你要他伤上加伤？\n");
	if( target->query("eff_qi")+target->query_temp("apply/qi")
	< (target->query("max_qi")+target->query_temp("apply/qi")) / 4 )
		return notify_fail( target->name()+ "已经受伤过重，经受不起你的真气震荡！\n");

	if (target->query("eff_qi") >= target->query("max_qi"))
		return notify_fail( target->name()+"并没有受伤，不需要你的疗伤。\n");

	msg = HIW"$N坐了下来运起"+to_chinese(force)+"，将手掌贴在$n背心，缓缓地将真气输入$n体内……\n\n"NOR;
	msg +=HIW"$n只觉一股暧阳阳的真气源源不绝的输入体内，只见$N头顶上丝丝白气冒出。\n\n"NOR;
	msg +=HIW"$n吐出一口瘀血，脸色看起来红润多了，伤势有了很大的好转，全身真气无比充沛。\n\n"NOR;

	message_vision(msg ,me ,target);			     

	target->receive_curing("qi", 10 + me->query_skill("force")/3 );
	target->receive_heal("qi", 10 + me->query_skill("force")/3 );

	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(4);
	target->start_busy(4);
	return 1;
}
