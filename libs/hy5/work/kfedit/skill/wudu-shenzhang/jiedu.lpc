// jiedu.c 解五毒神掌
// By Kayin @ CuteRabbit Studio 99-4-16 15:19 new
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target )
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("你要给谁解毒。\n");

        if( (int)me->query_skill("yunu-xinfa", 1) < 40 )
                return notify_fail("你的玉女心法不够娴熟，不能解五毒神掌。\n");

        if( (int)me->query_skill("wudu-shenzhang", 1) < 40 )
                return notify_fail("你的五毒神掌不够娴熟，不能解五毒神掌。\n");

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("你现在内力太弱，不能解毒。\n");
                
        if( target->query_condition("wuduz_poison")< 1)
        	return notify_fail("他没有中毒。\n");
if (!userp(target))
	return notify_fail("对方不接受你的医疗。\n");

if (!userp(me))
	return notify_fail("对方不接受你的医疗。\n");
        me->add("neili", -300);
        target->apply_condition("wuduz_poison", 0);
        msg = HIW "$N使出五毒神掌解毒的手法为$n推拿。接着给$n服下一粒解药.\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
