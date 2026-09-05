// canyun // bren

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

	int i;
	i = me->query_skill("xingyi-zhang", 1)/5;
		if( !target ) target = offensive_target(me);

        if( !target ||	!target->is_character() || !me->is_fighting(target) )
                return notify_fail("「星光点点」只能在战斗中对对手使用。\n");
        if( (int)me->query_skill("xingyi-zhang", 1) < 120 )
                return notify_fail("你的星移掌不够娴熟，不会使用「星光点点」。\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 120 )
                return notify_fail("你的神元功等级不够，不能使用「星光点点」。\n");

        if( (int)me->query_dex() < 30 )
                return notify_fail("你的身法不够强，不能使用「星光点点」。\n");

        if( (int)me->query("neili") < 700 )
                return notify_fail("你现在内力太弱，不能使用「星光点点」。\n");
        me->add("neili", -200);
        me->add("jing", -40);
        message_vision(HIW "\n$N双掌交相呼应,漫天的掌影犹如星星般在$n周围闪烁不定！\n" NOR,me, target);

//        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

	if( F_KUNGFU->hit_rate( me->query_dex(), (int)target->query_dex(), 9, me, target) )
	{
//		me->add_temp("apply/strength", i);
        	me->add_temp("apply/attack", i);
        	me->add_temp("apply/damage", i);
		msg =  HIW"$N将神元功发挥到极限，一双手掌发出耀眼的光芒，幻化出漫天掌影！" NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		me->add("neili", -100);
//		me->add_temp("apply/strength", -i);
        	me->add_temp("apply/attack", -i);
        	me->add_temp("apply/damage", -i);
	}
//  	me->add("neili", -400);
  	me->add_temp("apply/damage", -i);
//        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);
//        me->start_perform(4,"「"HIW"星光点点"NOR"」")  ;
        me->start_busy(2+random(3));
        return 1;
        }
