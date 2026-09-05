// Created by iszt@pkuxkx, 2007-03-27

#include <ansi.h>

int exert(object me, object target)
{
	int busynum;

	if( !target || !target->is_character() )
		return notify_fail("你要给谁疗伤？\n");
	if( target->is_corpse() )
		return notify_fail("来不及了，这人已经死了。\n");
	if( target->query("disable_type") == "<睡梦中>" )
		return notify_fail("还是等这人睡醒了再治疗吧。\n");		
	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够。\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够。\n");
	if(living(target) && target->query("eff_qi") == target->query("max_qi"))
		return notify_fail("没有受伤，疗什么？\n");

	if(target != me)
		message_vision(HIG"\n$N左手中指连弹，已封闭了$n伤处的穴道，"NOR, me, target);
	else
		message_vision(HIG"\n$N左手中指连弹，已封闭了自己伤处的穴道，"NOR, me);

	target->receive_curing("qi", 20 + (int)me->query_skill("force")/3 );

	if(target->query("eff_qi") == target->query("max_qi"))
		message_vision(HIG"血流立止，看来已完全恢复了。\n"NOR, me);
	else
		message_vision(HIG"伤势好多了。\n"NOR, me);

	me->add("neili", -300);
	busynum = 1+random(2);
	if( !living(target) && target != me )
	{
		message_vision(HIC"$N又使一招"HIW"「星丸跳掷」"HIC"，一股北冥真气射入$n的臂根「中府穴」中。\n"
			HIY"$n「啊」的一声大叫，醒了转来。\n"NOR, me, target);
		target->revive();
		if(!target->is_busy())
			target->start_busy(5);
		me->add("neili", -200);
		me->add("max_neili", -2);
		busynum += 1+random(4);
	}
	if(me->is_fighting())
		busynum *= 2;
	me->start_busy(busynum);

	return 1;
}