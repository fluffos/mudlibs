#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        lvl = me->query_skill("xuanyin-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用玄阴诀。\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 120 )
                return notify_fail("你的玄阴剑法不够娴熟，无法施展出玄阴诀。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 120)
                return notify_fail("你的九阴真功火候不够，无法施展出玄阴诀。\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 120)
                return notify_fail("你的九阴身法火候不够，无法施展出玄阴诀。\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出玄阴诀。\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法施展出玄阴诀。\n");
        if ((int)me->query("jingli") < 500)
                return notify_fail("你的精气不够，无法施展出玄阴诀。\n");
        message_vision(HIB"$N使出九阴「玄阴诀」，迅捷无比的攻向$n！\n"NOR,me, target);

        me->add("neili", -(300 +random(100)) );
        me->add("jingli", -150);

        me->add_temp("apply/attack",lvl/10);
        me->add_temp("apply/dexerity",lvl/10);
        me->add_temp("apply/damage",lvl/10);

        message_vision(HIB"$N连出数剑，一剑比一剑凌利！\n"NOR,me);
        message_vision(HIB"$N连连後退，防守尚有困难，更别说攻击了。\n"NOR,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->start_busy(lvl/50);
        me->start_busy(random(2) + 1);
        me->add_temp("apply/attack", -lvl/10);
        me->add_temp("apply/damage", -lvl/10);
        me->add_temp("apply/dexerity",-lvl/10);
        me->start_perform(7,"「玄阴诀」");
        return 1;
}

