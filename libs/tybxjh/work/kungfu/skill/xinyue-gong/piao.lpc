// piao.c 落叶飘飘
// quit 99.12.14

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
        string msg;

        if( !target ) target = offensive_target(me);

         if( environment(me)->query("no_fight") )
              return notify_fail("落叶飘飘只能在战斗中使用。\n");
        if( !target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("落叶飘飘只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xinyue-gong", 1) < 40 )
                return notify_fail("你的飘花落叶手不够娴熟，不能使用落叶飘飘。\n");

                msg = HIB "$N突然身法一变，右手横拍而出呼啸的掌风，如狂猛的波涛，满天盖向$n。\n";

        me->start_busy(1);
        if( random( (int)me->query_skill("xinyue-gong",1))
          > random(target->query_skill("dodge") ) ) {
                msg += HIB " $p没有躲过，被$N的掌风击中，$p吐出一口"+HIR"鲜血！\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("xinyue-gong",1));
            target->receive_wound("qi",15 + random(10));
            target->start_busy(random(2));
        } else {
                msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
                me->start_busy(random(4));
        }
        message_vision(msg, me, target);
        return 1;
}

