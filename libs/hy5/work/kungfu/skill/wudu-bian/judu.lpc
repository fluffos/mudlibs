//五毒鞭法  聚毒

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你只能在站斗中才能聚毒。\n");

	if( (int)me->query_skill("wudu-bian",1) < 60 
		||(int)me->query_skill("wudu-xinfa",1) < 50 )
		return notify_fail("你的五毒心法功力太浅，无法聚毒！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "已经手忙脚乱了，不需要在用毒了。\n");
	me->start_busy(1);
	msg = BLU "$N默运内力，将毒气运于鞭上，只见一股蓝色的雾气罩住了长鞭。\n";

	if  ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 
	    && random(me->query_skill("wudu-xinfa",1)) >20) 
	{
		msg += "$p措不及防，不由身染毒气。\n" NOR;
	    target->receive_damage("qi",(int)me->query_skill("wudu-xinfa",1));
            target->receive_wound("qi",15 + random(10));
            target->receive_wound("jing", 10);
            target->apply_condition("wudu_poison", random(me->query_skill("wudu-xinfa",1)/10) + 1 +
			target->query_condition("wudu_poison"));
			target->start_busy(1 + random(2)); 
		
	} else {
		msg += "可是$p看出了$P的毒计，立刻屏住呼吸，没有中毒。\n" NOR;
		
	}
	message_vision(msg, me, target);

	return 1;
}
