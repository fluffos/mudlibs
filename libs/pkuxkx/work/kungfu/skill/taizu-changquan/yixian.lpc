#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[拳打一条线]只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("taizu-changquan", 1) < 60)
                return notify_fail("你的[太祖长拳]级别还不够，使用这一招会有困难！\n");
        
//        if(objectp(me->query_temp("weapon")) )
 //       	return notify_fail("你手持武器，无法使用[葵花三段]！\n");

        message_vision("\n$N使出-"HIY"[太祖长拳]绝技"NOR"-"HIR"拳打一条线"HIG".."NOR"\n", me);



        COMBAT_D->do_attack(me, target);
        //message_vision("\n"HIY"葵花一段"NOR"-------"BLINK HIR"落花流水\n"NOR, me);
        COMBAT_D->do_attack(me, target);
        //message_vision("\n"HIY"葵花二段"NOR"-------"BLINK HIG"摧花斫柳\n"NOR, me);
        COMBAT_D->do_attack(me, target);
        //message_vision("\n"HIY"葵花三段"NOR"-------"BLINK HIR"月缺花残\n"NOR, me);
        COMBAT_D->do_attack(me, target);

        me->add("neili", -100);

        me->start_busy(2);
        return 1;
}

