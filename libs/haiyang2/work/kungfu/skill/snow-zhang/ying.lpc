#include <ansi.h>
#include <combat.h>

#define YING "「" HIW "如影相随" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YING "只能空手施展。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

   if( (int)me->query_skill("bingxue-xinfa", 1) < 80 )
   return notify_fail("你的冰雪心法火候不够，使不出「"+HIW"烟雪春梅"NOR+"」。\n");

    if( (int)me->query_skill("snow-zhang", 1) < 100 )
   return notify_fail("你的飞雪映梅掌不够熟练，不会使用「"+HIW"烟雪春梅"NOR+"」。\n");

        if (me->query_skill("dodge") < 180)
                return notify_fail("你的轻功修为不够，难以施展" YING "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在的真气不够，难以施展" YING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("strike"); 

        dp = target->query_skill("dodge");

        msg = HIC "\n$N" HIC "长啸一声，施出绝招「" HIW "如影相随" HIC "」，"
              "双掌不断翻腾，掌风中透出阵阵阴寒之气，将$n" HIC "笼罩。\n" NOR;
        message_vision(msg, me, target);
        
     if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
		msg = HIR "$n" HIR "顿觉寒气避人，一时间无从应对，"
                      "竟被困在$N" HIR "的掌风之中。\n" NOR;

                target->start_busy(5);
                me->add("neili", -180);
        } else
        {
                msg = CYN "$n" CYN "看破$N" CYN "毫无攻击之意，于"
                      "是大胆反攻，将$N" CYN "这招尽数化解。\n" NOR;

                me->start_busy(1);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);

        return 1;
}
