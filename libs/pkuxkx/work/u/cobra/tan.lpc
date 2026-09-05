// tan.c
// by aiai

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{       
	int sp,dp;      
	int damage;
	string msg;
	object obj; 
	int kill=0;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() )
		return notify_fail("暗器射敌只能对同地方的对手使用。\n");
	if( (int)me->query_skill("tanzhi-shengong", 1) < 100 )
		return notify_fail("你的弹指神功不够娴熟。\n");
	if( (int)me->query_skill("bihai-shengong", 1) < 100 )
		return notify_fail("你的碧海神功不够高，不能用内力发射暗器。\n");
	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能发射暗器。\n");
	tell_object(me, HIY "只见你手指一弹，一颗石子激射而出，击向" + target->name() + "。\n" NOR);
	message("vision", HIY "你只见眼前一闪，似乎有什么暗器打了过来。\n" NOR, environment(me), ({ me }));
	sp = me->query_skill("force",1) + me->query("tanzhi-shengong",1);
	dp = target->query_skill("dodge",1);
	sp = sp/2 + random(sp/2);
	dp = dp/2 + random(dp/2);
	if( sp > dp )
	{
		me->start_busy(1);
		target->start_busy(1+random(1));
		damage = (int)me->query_skill("tanzhi-shengong", 1) + (int)me->query_skill("force",1) + (int)me->query_skill("finger",1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi",damage/2);
		me->add("neili", -100);
		message("vision", HIR "\n结果" + target->name() + 
			"被石子射中，惨叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), target);
		tell_object(target, HIR "\n你眼见石子射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
	}
	else
	{
		me->start_busy(3);     
		target->start_busy(1);
		me->add("neili",-100);
		message_vision( HIC "\n可是$N看到了石子，身子急退，躲开了。\n" NOR, target);
	}                                    
	if(me->query("combat_exp")>(int)target->query("combat_exp")/2)
	{ 
		tell_object(target, HIC "\n你没有发现石子的来源！\n" NOR);
	}                                                 
	else
	{ 
		tell_object(target, HIR "\n你发现了射石子的人了！\n" NOR);
		kill = 1;                
	}
	if(kill==1)
		target->kill_ob(me);
	return 1;
}

