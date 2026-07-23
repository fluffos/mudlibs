// sanjue 九阴三绝爪

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

int perform(object me, object target)
{
        int exp, str, dex, skill, i;
        exp = (int)me->query("combat_exp");
        str = (int)me->query("str");
        dex = (int)me->query("dex");
        skill = (int)me->query_skill("jiuyin-baiguzhua", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「九阴三绝爪」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「九阴三绝爪」！\n");   
        if( skill < 150 )
                return notify_fail("你的九阴白骨爪还不够娴熟，使不出「九阴三绝爪」绝技。\n");
        if ( skill < 200 ) i = 3;
        if ( skill < 300 ) i = 3;
        else i = 3;
        if ( me->query_skill_mapped("claw") != "jiuyin-baiguzhua" )
               return notify_fail("你现在无法使用「九阴三绝爪」！\n");
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你现在内力太弱，使不出「九阴三绝爪」。\n");      
        if( (int)me->query("neili") < 1100 )
                return notify_fail("你现在真气太弱，使不出「九阴三绝爪」。\n");
        me->start_perform(2, "九阴三绝爪");
        message_vision(RED"\n$N突然怪叫一声，全身骨骼如爆豆般噼啪作响，手臂突然暴涨三尺！\n"NOR,me);
        me->add_temp("apply/strength",str/i);
        me->add_temp("apply/dexerity",dex/i);
        me->add("neili", -600);
        me->add_temp("apply/attack", skill/i);
        me->add_temp("apply/damage", skill/i);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/damage", -skill/i);
        me->add_temp("apply/attack", -skill/i);
        me->add_temp("apply/strength",-str/i);
        me->add_temp("apply/dexerity",-dex/i);
        me->start_busy( 2 + random(i));
if (userp(target)) me->start_busy(4);
        return 1;
}
