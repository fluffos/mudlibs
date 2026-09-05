// cuoluan.c 百花错乱
// by hubo 2008-4-27

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("百花错乱只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用百花错乱！\n");		
		
        if( (int)me->query_skill("baihua-cuoquan", 1) < 30 )
		return notify_fail("你的百花错拳不够娴熟，不会使用百花错乱。\n");
		
        if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用百花错乱。\n");
			
	msg = CYN "$N突然双手狂摆，使出百花错乱，似是而非,出其不意,招式大悖于祖传正宗手法。\n"NOR;

	if (random(me->query_skill("cuff")) > target->query_skill("force")/2 )
	{
		me->start_busy(1);
		//target->start_busy(random(3));
		
		damage = (int)me->query_skill("baihua-cuoquan", 1);
		
                damage = damage + random(damage);
		
		target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage, me);
		me->add("neili", -damage/10);
		
		if( damage < 20 ) msg += HIY"结果$n被$N的单拳击中，闷哼一声。\n"NOR;
        	else if( damage < 40 ) msg += HIY"结果$n被$N双拳打中，「嘿」地一声退了两步。\n"NOR;
        	else if( damage < 80 ) msg += RED"结果$n的胸口被$N的双拳狠狠击中，胸口有如受到一记重锤，连退了五六步！\n"NOR;
              else msg += HIR"结果$n被$N双拳击飞，眼前一黑，感觉很难再坚持下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
		msg += CYN"可是$p把眼一闭，不被乱拳所干扰。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

