// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIR "赤血爪" NOR; }
string query_name() { return "赤血爪"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(name() + "只能空手施展。\n");

         if ((int)me->query_skill("sougu-yingzhua", 1) < 60)
                return notify_fail("你搜骨鹰爪功不够娴熟，难以施展" + name() + "。\n");

       if (me->query_skill_mapped("claw") != "sougu-yingzhua")
                return notify_fail("你没有激发搜骨鹰爪功，难以施展" + name() + "。\n");

        if (me->query_skill("force") < 80)
                return notify_fail("你的内功修为不够，难以施展" + name() + "。\n");

        if ((int)me->query("neili") < 220)
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        ap = me->query_skill("claw");
        dp = target->query_skill("parry");

        msg = HIW "\n$N" HIW "运转真气，双手忽成爪行，施出绝招「" HIR "赤"
              "血爪" HIW "」，迅猛无比地抓向$n" HIW "。\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("claw");

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           HIR "但见$N" HIR "双爪划过，$n" HIR "已闪避不及，胸口被$N" HIR
                                           "抓出十条血痕。\n" NOR);

                me->start_busy(3);
                me->add("neili", -200);
        } else
        {
                msg += CYN "$n" CYN "奋力招架，竟将$N" CYN "这招化解。\n" NOR;

                me->start_busy(4);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);
        return 1;
}


