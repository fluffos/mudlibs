// maxsuck.c

#include <ansi.h>

int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

	my_max = me->query("max_neili");
	tg_max = target->query("max_neili");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("你要吸取谁的丹元？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");

	if( !me->is_fighting() || !target->is_fighting())
		return notify_fail("你必须在战斗中才能吸取对方的丹元！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 90 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +
			"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取丹元！\n");

	message_vision(
		HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
		me, target );

	if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

	me->set_temp("sucked", 1);		

	if( random(sp) > random(dp) ) 
	{
		tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);

		target->add("max_neili",  -1*(1+(me->query_skill("huagong-dafa", 1)-90)/20) );
		if (random(2))
		{
			// dewolf add for suck jingli
			tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
			me->add("max_neili",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/15) );
		}
		else
		{
			tell_object(me, HIG "你觉得" + target->name() + "的精气自手掌源源不绝地流了进来。\n" NOR);
			me->add("max_jingli",       1*(1+(me->query_skill("huagong-dafa", 1)-90)/15) );
		}

            if( (int)me->query("potential") - (int)me->query("learned_points") < 290 )
			me->add("potential",  10);
		me->add("combat_exp", 10);

		me->start_busy(random(10));
		me->add("neili", -20);
		if (me->query("max_neili") > 10*me->query_skill("force"))
		{
			if ( random(10*me->query_skill("force")) < 
				(me->query("max_neili") - 10*me->query_skill("force")) )
			{
				tell_object(me,HIR "你忽然觉得膻中气海中的内息有些异样，似乎不太能够听你使唤，你开始有些烦躁...\n" NOR);
				tell_room(environment(me),"你看到" + me->name() + "忽然皱了皱眉，深深吸了几口气。\n",me);
				me->add_temp("suck/zouhuo",1);
			}
			if ( random(me->query_temp("suck/zouhuo")) > 2 )
			{
				tell_object(me, HIR "你忽然发现吸来的丹元正在你身体各处游走，速度越来越快，你已经完全控制不住它们了！\n" NOR);
				tell_room(environment(me),"你忽然看到" + me->name() + "开始胡言乱语，手舞足蹈，不一会儿就口吐白沫，晕倒在地。\n",me);
				me->set("attitude","aggressive");
				me->delete_temp("suck");
				me->unconcious();
			}
		}

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
		me->start_busy(10);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if (!me) return;
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

