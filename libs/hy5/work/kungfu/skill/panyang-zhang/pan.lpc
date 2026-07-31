#include <ansi.h>
#include <combat.h>

#define PAN "「" HIR "攀阳邀月" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PAN "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("panyang-zhang", 1) < 60)
                return notify_fail("你的攀阳掌不够娴熟，难以施展" PAN "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功修为不够，难以施展" PAN "。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你现在真气不够，难以施展" PAN "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "只听$N" HIR "一声断喝，双掌纷飞，一式「攀阳邀月」接"
              "二连三向$n" HIR "攻去。\n" NOR;

        if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
        {
                me->start_busy(1);
                damage = me->query_skill("strike");
                damage = damage / 2 + random(damage / 2);
                me->add("neili", -50);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "结果$p" HIR "闪避不及，被$P" HIR
                                           "接连击中数掌，顿时口喷鲜血，几乎昏厥"
                                           "！\n" NOR;
        } else
        {
                me->start_busy(2);
                me->add("neili", -30);
                msg += CYN "可是$p" CYN "识破了$P"
                       CYN "这一招，斜斜一跃避开。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
