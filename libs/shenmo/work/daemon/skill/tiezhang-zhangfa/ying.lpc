#include <ansi.h>

#define YING "「" MAG "无影掌" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "只能对战斗中的对手使用。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
                
        if ((int)me->query_skill("tiezhang-zhangfa", 1) < 100)
                return notify_fail("你的铁掌掌法还不够娴熟，难以施展" YING "。\n");

        if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa")
                return notify_fail("你没有激发铁掌掌法，难以施展" YING "。\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("你现在没有准备使用铁掌掌法，难以施展" YING "。\n");

        if (me->query("neili") < 100)
                return notify_fail("你现在真气不够，无法施展「无影掌」。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = MAG "只见$N" MAG "双掌急速运转，使出铁掌掌法绝技「无影掌」，掌影虚虚实"
              "实，毫无章理的拍向$n" MAG "！\n" NOR;

        me->add("neili", -80);
        if (random(me->query_skill("tiezhang-zhangfa")) > (int)target->query_skill("force") / 3)
        {
                msg += HIR "结果$p" HIR "完全琢磨不透$P" HIR "精妙的掌法，攻势顿时缓"
                       "滞。\n" NOR;
                target->start_busy((int)me->query_skill("tiezhang-zhangfa") / 50 + 3);
        } else
        {
                msg += CYN "可是$p" CYN "并没上当，硬生生格开了$P"
                       CYN "这几掌。\n" NOR;
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}
