#include <ansi.h>
#include <combat.h>

#define ZHENG "「" HIY "谁与争锋" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp;

        if (! target) target = offensive_target(me);



        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHENG "只能对战斗中的对手使用。\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("你必须空手才能使用" ZHENG "。\n");

        if ((lvl = (int)me->query_skill("yitian-zhang", 1)) < 120)
                return notify_fail("你的倚天屠龙掌不够娴熟，难以施展" ZHENG "。\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("你现在真气太弱，难以施展" ZHENG "。\n");

        if (me->query_skill_mapped("strike") != "yitian-zhang")
                return notify_fail("你没有激发倚天屠龙掌，难以施展" ZHENG "。\n");

        if (me->query_skill_prepared("strike") != "yitian-zhang")
                return notify_fail("你没有准备使用倚天屠龙掌，难以施展" ZHENG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "神气贯通，将倚天屠龙掌二十四字一气呵成，双掌"
              "携带着排山倒海之劲贯向$n" HIY "。\n\n" NOR;
        me->add("neili", -150);

        ap = me->query_skill("strike") * 3 / 2 + me->query("level") * 20 + 
             me->query_skill("force", 1);
        dp = target->query_skill("force") + target->query("level") * 20 + 
             target->query_skill("force", 1);
         lvl = (int)me->query_skill("yitian-zhang", 1);
         count=(int)count/5;    
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "顿时觉得呼吸不畅，全然被这"
                       "股力道所制，只得拼命运动抵挡。\n" NOR;
                count = lvl / 5;
        } else
        {
                msg += HIC "$n" HIC "深吸一口气，凝神抵挡，犹如轻舟立"
                       "于惊涛骇浪之中，左右颠簸，却是不倒。\n" NOR;
                count = 0;
        }
        message_combatd(msg, me, target);
                me->add_temp("apply/attack", count);
                me->add_temp("apply/damage", count);
        for (i = 0; i < 4; i++)
        {


                if (random(3)==0) target->start_busy(3);
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count);
        me->start_busy(3);
        return 1;
}

