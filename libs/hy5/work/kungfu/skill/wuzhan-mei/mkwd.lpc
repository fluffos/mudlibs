 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit F_SSERVER;
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon; 
        extra = me->query_skill("wuzhan-mei",1);
        if ( extra < 280) return notify_fail("你的［五展梅］还不够纯熟！\n");
        	
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［梅开五度］只能对战斗中的对手使用。\n"); 

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「雨激梅花半瓣香」。\n");

	if(me->query_skill("wuzhan-mei")<300)
	return notify_fail("你的五展梅不够娴熟，不能运用「雨激梅花半瓣香」。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

        me->add_temp("apply/attack", 100);
        msg = HIG "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n"+HIW"第一剑！梅花初绽！" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "第二剑！梅开二度！" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "第三剑！朵朵寒梅！" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "第四剑！嘘寒问暖！" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "第五剑！梅花消逝！"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add("neili",-380);
        me->start_busy(2); 
        return 1; 
}      
