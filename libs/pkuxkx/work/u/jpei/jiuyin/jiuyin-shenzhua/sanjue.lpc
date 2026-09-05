#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
        int skill;
        skill = (int)me->query_skill("jiuyin-shenzhua", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「九阴三绝爪」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「九阴三绝爪」！\n");   
        if( skill < 150 )
                return notify_fail("你的九阴神爪不够娴熟，使不出九阴三绝爪。\n");
        if(me->query_skill("jiuyin-zhengong",1) < 150 )
                return notify_fail("你的九阴真功不够娴熟，使不出九阴三绝爪。\n");
        if(me->query_skill("jiuyin-shenfa",1) < 120 )
                return notify_fail("你的九阴身法不够娴熟，使不出九阴三绝爪。\n");
        if (me->query_skill_mapped("claw") != "jiuyin-shenzhua" )
               return notify_fail("你现在无法使用「九阴三绝爪」！\n");
        if( (int)me->query("max_neili") < 2000)
                return notify_fail("你现在内力太弱，使不出「九阴三绝爪」。\n");      
        if( (int)me->query("neili") < 1500 )
                return notify_fail("你现在真气太弱，使不出「九阴三绝爪」。\n");
        me->start_perform(5, "九阴三绝爪");
        message_vision(HIR"\n$N手臂突然伸长，向$n抓去！\n"NOR,me,target);
        message_vision(HIR"\n$N所使的似乎是江湖中驰名的阴毒功夫九阴白骨爪，是招数光明正大，威力强极！\n"NOR,me,target);
        me->add("neili", -500);
        me->add_temp("apply/dexerity", skill/3);
        me->add_temp("apply/damage", skill/3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if(me->is_fighting(target)) 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        if(me->is_fighting(target))
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->add_temp("apply/damage", -skill/3);       
        me->add_temp("apply/dexerity", -skill/3);       
        me->start_busy(2+random(2));
        return 1;
}

