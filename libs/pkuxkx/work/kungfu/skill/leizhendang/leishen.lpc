#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,weapon2;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『雷神戟』只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("leizhendang", 1) < 100)
                return notify_fail("你的『六十四路轰天雷震挡法』级别还不够，使用这一招会有困难！\n");
        
        if( (!objectp(weapon = me->query_temp("weapon"))||(!objectp(weapon2 = me->query_temp("secondary_weapon"))
      || (string)weapon->query("skill_type") != "halberd") ||(string)weapon2->query("skill_type") != "halberd"))
                return notify_fail("你必须双手使戟才能使「雷神戟」。\n");
        if (me->is_busy())
        {
            return notify_fail("你正忙着呢。\n");
        }
        message_vision("\n$N使出-"HIR"六十四路轰天雷震挡法绝技"NOR"-"BLINK HIR"『雷神戟』"NOR"\n", me);



        COMBAT_D->do_attack(me, target);
        message_vision("\n"HIW"雷神第一式——惊雷……\n"NOR, me);
        COMBAT_D->do_attack(me, target);
        message_vision("\n"WHT"雷神第二式——炸雷……\n"NOR, me);
        COMBAT_D->do_attack(me, target);
        message_vision("\n"CYN"雷神第三式——天雷……\n"NOR, me);
        COMBAT_D->do_attack(me, target);

        me->add("neili", -100);

        me->start_busy(2);
        return 1;
}

