#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUI "「" HIW "穿心锥" NOR "」"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (! target) target = offensive_target(me);

 

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "只能对战斗中的对手使用。\n");


        if ((int)me->query_skill("tongbi-zhang", 1) < 90)
                return notify_fail("你通臂六合掌不够娴熟，难以施展。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功修为不够，难以施展" ZHUI "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在真气不够，无法使用" ZHUI "。\n");


        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "\n$N" HIY "一声冷笑，双掌一错，陡然施出一招"
              "「" HIW "穿心锥" HIY "」，幻出千百之手掌一齐"
              "插向$n" HIY "！" NOR;

        if (random(me->query_skill("tongbi-zhang")) > target->query_skill("dodge") / 3)
        {
                me->start_busy(1);
                damage = me->query_skill("tongbi-zhang");
                damage = damage  + random(damage);
                me->add("neili", -150);
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n结果$p" HIR "没能避开$P" HIR
                                          "变幻莫测的掌法，掌劲顿时透胸而过，"
                                          "口喷鲜血，几乎摔倒！\n" NOR;
        } else
        {
                me->start_busy(2);
                me->add("neili", -50);
                msg = CYN "\n可是$p" CYN "识破了$P"
                      CYN "这一招，斜斜一跃避开。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

