// by darken@SJ

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

string perform_name(){ return HBBLU"枯树盘根"NOR; }
int perform(object me, object target)
{
        int skill;
        skill = (int)me->query_skill("tiezhang-zhangfa", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「枯树盘根」只能在战斗中使用。\n");
        if( me->query_temp("weapon"))
                return notify_fail("你拿着武器怎么能使用「枯树盘根」！\n");
        if( skill < 100 )
                return notify_fail("你的铁掌掌法不够娴熟，使不出「枯树盘根」。\n");
        if(me->query_skill("guiyuan-tunafa",1) < 100 )
                return notify_fail("你的归元吐呐法不够娴熟，使不出「枯树盘根」。\n");
        if(me->query_skill_mapped("strike") != "tiezhang-zhangfa" )
               return notify_fail("你现在无法使用「枯树盘根」！\n");
        if( (int)me->query("max_neili") < 1000)
                return notify_fail("你现在内力太弱，使不出「枯树盘根」。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在真气太弱，使不出「枯树盘根」。\n");
                 message_vision(HBBLU"\n$N毫不容情，双手犹似两把铁钳，往$n咽喉扼去！\n"NOR,me,target);
        if (random(me->query_int()) > target->query_int()/2) {
           message_vision(HIR"$n暗暗心惊，翻身后退，只听得$N“嘿”的一声，$n双手已落入$N掌握之中。\n"NOR,me,target);
           me->start_busy(6);
           if (!target->is_busy()) target->start_busy(6);
        } else
           message_vision(HBBLU"\n$n以退为进，向斜前方一冲，$N便无法以逸待劳。\n"NOR,me,target);
        me->add("neili", -200-random(100));
        me->start_perform(10,"「枯树盘根」");
        return 1;
}


