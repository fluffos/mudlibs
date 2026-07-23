// jinglisuck.c

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	if ( target == me ) target = offensive_target(me);
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail("只有在战斗中才能使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的丹元？\n");
	if (target->query("race") != "人类")
		return notify_fail("搞错了！只有人才能有丹元！\n");

	my_max = me->query("max_jingli");
	tg_max = target->query("max_jingli");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");

	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 100 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_jingli") < 10 )
		return notify_fail( target->name() +
			"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

        if( (int)target->query("max_jingli") < (int)me->query("max_jingli")/10 )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取丹元！\n");

       if( target->query_temp("no_kill") )
        return notify_fail("不能打，打不得啊！\n");

        if(target==me)
        return notify_fail("用 suicide 指令会比较快:P。\n");

       if(me->is_busy())
        return notify_fail("你现在正忙。\n");
        
	message_combatd(
		HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
		me, target );

        if ( living(target) )
	{
me->kill_ob(target);
target->fight_ob(me);
//		if( !target->is_killing(me) ) target->kill_ob(me);
	}

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);

                target->add("max_jingli",  -1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
                me->add("max_jingli",       1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
                me->add("jingli",       1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
                if ( target->query("max_jingli") <1) target->set("max_jingli",0);

		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
			me->add("potential",  5);
		me->add("combat_exp", 10);

		me->start_busy(7);
		target->start_busy(random(7));
		me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

