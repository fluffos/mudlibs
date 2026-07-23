// jiedu.c 解五毒神掌
// By Kayin @ CuteRabbit Studio 99-4-16 15:19 new
#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("你要给谁解毒。\n");

        if( (int)me->query_skill("shenlong-xinfa", 1) < 90 )
                return notify_fail("你的神龙心法不够娴熟，不能解毒。\n");

if (!userp(target))
	return notify_fail("对方不接受你的医疗。\n");

if (!userp(me))
	return notify_fail("对方不接受你的医疗。\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能解毒。\n");
        if( me->is_fighting() )
        return notify_fail("你正忙着呢！\n");
        if( me->is_busy() )
        return notify_fail("你正忙着呢！\n");                
        me->add("neili", -300);
me->start_busy(5);
        target->apply_condition("snake_poison", 0);
        target->apply_condition("ill_fashao",0);
        target->apply_condition("ill_kesou",0);
        target->apply_condition("ill_shanghan",0);
        target->apply_condition("ill_zhongshu",0);
        target->apply_condition("ill_dongshang",0);
        target->apply_condition("wugong_poison", 0);
        target->apply_condition("chanchu_poison", 0);
        target->apply_condition("xiezi_poison", 0);
        target->apply_condition("snake_poison", 0);
        target->apply_condition("zhizhu_poison", 0);
        msg = HIW "$N使出身龙心法解毒的手法为$n推拿。接着给$n服下一粒解药.\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
