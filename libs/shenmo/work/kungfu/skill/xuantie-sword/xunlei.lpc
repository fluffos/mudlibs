// jinshe-jianfa perform
//by snowman

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int j, z;
        object weapon;
        j = me->query_skill("xuantie-sword", 1);
        z = me->query_skill("xuantie-sword", 1);
 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「迅雷」只能在战斗中对对手使用。\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "xuantie-sword")
                return notify_fail("你必须在使用剑时才能使出「迅雷」！\n");

        if(me->query_skill("xuantie-sword", 1) < 200 )
                return notify_fail("你的玄铁剑法还不够娴熟，使不出「迅雷」。\n");

//        if(me->query_skill("yunu-xinjing", 1) < 160 )
//                return notify_fail("你的玉女心经修为不够，使不出「迅雷」。\n");

        if( (int)me->query_skill("force") < 200 )
                return notify_fail("你的内功等级不够，使不出「迅雷」。\n");

        if( (int)me->query_str() < 32)
                return notify_fail("你的膂力还不够，使不出「迅雷」。\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("你的身法还不够，使不出「迅雷」。\n");                                                                               

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("你现在内力太弱，使不出「迅雷」。\n");      

        if( (int)me->query("neili") < 200 )
                return notify_fail("你现在真气太弱，使不出「迅雷」。\n"); 
//                if( (int)me->query("jingli") < 700 )
//                return notify_fail("你现在体力太弱，使不出「迅雷」。\n"); 
        me->add_temp("apply/attack", j/3); 
        me->add_temp("apply/strength", z/3);
 
        msg = BLU"\n$N将手中的"+weapon->name()+"缓缓向$n一压，忽然剑光一闪， 一剑幻为五剑，宛如奔雷掣电攻向$n！\n\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 

              me->add("neili",-200);

         me->add_temp("apply/strength", -z/3);
        me->add_temp("apply/attack", -j/3);

        me->start_busy(2);
//        target->start_busy(1);
        return 1;
}
