#include <ansi.h>
#include <combat.h>

#define LEI "「" HIY "雷霆万钧" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(LEI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LEI "只能空手施展。\n");

        if( (int)me->query_skill("lingshe-quan",1) < 120 )
                return notify_fail("你的灵蛇拳火候不够，无法使用「霹雳无形」！\n");
        if ((int)me->query_skill("hamagong", 1) < 50)
                return notify_fail("你的蛤蟆功不够娴熟。\n");


        if (me->query("neili") < 400)
                return notify_fail("你现在真气不够，难以施展" LEI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "只见$N" HIY "聚力于掌，平平推出，顿时掌风澎湃，掌力"
              "携着雷霆万钧之势猛贯向$n" HIY "而去！\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("parry") / 2)
        {
                me->start_busy(3);

                damage = me->query_skill("lingshe-quan", 1);
                damage = damage * 3 + random(damage * 5);
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);

                        msg +=                 HIR "结果只听$n" HIR "一声闷哼，$N"
                                           HIR "掌劲穿胸而过，“哇”的喷出一大"
                                           "口鲜血。\n" NOR;
                me->add("neili", -200);
        } else
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN "可是$p" CYN "看破了$N" CYN
                       "的企图，躲开了这招杀着。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

