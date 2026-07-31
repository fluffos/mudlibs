// chan.c 太极剑法「缠」字诀

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天山杖法「护身」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
                
        if( (int)me->query_skill("tianshan-zhang", 1) < 40 )
                return notify_fail("你的天山杖法不够娴熟，不会使用「护身」。\n");

        msg = HIY "$N使出天山杖法「护身」，拼命的舞动手中的武器，把周身保护住,企图扰乱$n的攻势。\n";
        me->add("neili",-50);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIG " 结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("corpse_poison",60);
                target->start_busy( (int)me->query_skill("tianshan-zhang",1) / 50 + 2 );
        } else {
                msg += HIR"可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

 if (me->query_skill("tianshan-zhang",1) > 250)
        {
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);        	
        message_vision(HIY"$N的杖头，冒出了绿光$n被绿光扫中，全身不由一震!\n"NOR,me,target);
        target->apply_condition("xx_poison",60);
        target->apply_condition("corpse_poison",60);
	 msg =  HIR  "「腐尸毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("x2_sandu",60);
	 msg =  HIR  "「毒砂掌」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("sanpoison",60);
	 msg =  HIR  "「无形毒」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        if (random(me->query("combat_exp")) >target->query("combat_exp")/2)
        {
       	 msg =  HIR  "「三笑逍遥散」" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N突然怪异的一笑，$n尽然跟着笑了笑!\n"NOR,me,target);
        target->apply_condition("sanxiao_poison",6);
        me->add("neili", -50);
        }
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);        	

}
        return 1;
}

