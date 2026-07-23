#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }


        if (! target || ! me->is_fighting(target))
                return notify_fail("「九穹绝刹掌」只能在战斗中对对手使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("「九穹绝刹掌」只能空手使用。\n");
                
        if (me->query("max_neili") < 2200)
                return notify_fail("你的内力修为还不够，无法施展「九穹绝刹掌」。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你的真气不够！\n");

        if ((int)me->query_skill("tongbi-zhang", 1) < 280)
                return notify_fail("你通臂六合掌不够娴熟，难以施展。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功修为不够，无法使用「九穹绝刹掌」！\n");

        if (me->query_skill_mapped("strike") != "tongbi-zhang")
                return notify_fail("你没有激发通臂六合掌，难以施展「九穹绝刹掌」。\n");

        //if (me->query_skill_prepared("strike") != "tongbi-zhang")
        //        return notify_fail("你现在没有准备使用通臂六合掌，难以施展「九穹绝刹掌」。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "一声怒喝，猛然施出铁掌掌法绝技「" NOR + WHT 
              "九穹绝刹掌" NOR + HIR "」！体内天雷真气急速运转，双臂陡"
              "然\n暴长数尺。只听破空之声骤响，双掌幻出漫天掌影，铺天"
              "盖地向$n" HIR "连环拍出！\n\n" NOR;
        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        if (ap / 2 + random(ap) > dp)
        {
                ap = me->query_skill("tongbi-zhang");
                count = ap / 15;
                msg += RED "$n" RED "面对$P" RED "这排山倒海攻势，完全"
                       "无法抵挡，唯有退后。\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "凝神应战，竭尽所能化解$P" HIC "这"
                       "几掌。\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", 80);

        me->add("neili", -300);
        me->add("qi", -100);    // Why I don't use receive_damage ?
                                // Becuase now I was use it as a cost
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(2);
        me->add_temp("apply/attack", -80);

        return 1;
}
