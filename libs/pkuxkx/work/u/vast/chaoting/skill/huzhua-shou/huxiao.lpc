// huxiao.c 虎啸山林

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg; int extra;

   	extra = me->query_skill("huzhua-shou",1);
   	if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("「虎啸山林」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) || me->query_temp("secondary_weapon"))
                return notify_fail("使用「虎啸山林」时双手必须空着！\n");

        if( (int)me->query_skill("huzhua-shou", 1) < 120 )
                return notify_fail("你的虎爪擒拿手不够娴熟，不会使用「虎啸山林」。\n");

        if( (int)me->query_skill("bixue-xinfa", 1) < 120 )
                return notify_fail("你的内功等级不够，不能使用「虎啸山林」。\n");

        if( (int)me->query_dex() < 27 )
                return notify_fail("你的身法不够强，不能使用「虎啸山林」。\n");

        if (me->query_skill_prepared("hand") != "huzhua-shou"
        || me->query_skill_mapped("hand") != "huzhua-shou")
                return notify_fail("你现在无法使用「虎啸山林」进行攻击。\n");


        if( (int)me->query("neili") < 600 )
                return notify_fail("你现在内力太弱，不能使用「虎啸山林」。\n");

        msg = HIR "$N长啸一声，将内力聚于手心，如猛虎下山一般扑向$n！\n" NOR;

     	message_vision(msg, me, target);

 	me->add_temp("apply/damage", extra/4);
 	me->add_temp("apply/dodge", extra/4);
// 	me->add_temp("apply/strength", extra/4);
        me->add_temp("apply/attack", extra/4);


    if ( extra > 249)
               {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
  		me->add("neili", -300);
		}
    else if ( extra > 199)
              {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		me->add("neili", -250);
		}
    else if ( extra > 169)
              {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
	        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		me->add("neili", -200);
		}
    else if ( extra > 119)
              {
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
		me->add("neili", -100);
   		}

	me->add_temp("apply/damage", -extra/4);
//  	me->add_temp("apply/strength", -extra/4);
        me->add_temp("apply/attack", -extra/4);
	me->add_temp("apply/dodge", -extra/4);
	me->start_busy(2+random(2));

            return 1;
}

