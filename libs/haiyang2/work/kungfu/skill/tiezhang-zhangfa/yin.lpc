#include <ansi.h>
#include <combat.h>

#define YIN "「" HIR "阴阳磨" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp, dd;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YIN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "只能空手施展。\n");

        if ((int)me->query_skill("tiezhang-zhangfa", 1) < 220)
                return notify_fail("你铁掌掌法火候不够，难以施展" YIN "。\n");

        if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa")
                return notify_fail("你没有激发铁掌掌法，难以施展" YIN "。\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("你没有准备铁掌掌法，难以施展" YIN "。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功修为不够，难以施展" YIN "。\n");

        if ((int)me->query("max_neili") < 3500)
                return notify_fail("你的内力修为不够，难以施展" YIN "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" YIN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "施出铁掌绝技「" HIR "阴阳磨"
              HIW "」，左掌不着半点力道，携着阴寒劲向$n"
              HIW "拂去。\n" NOR;  

        ap = me->query_skill("tiezhang-zhangfa") + me->query("str") * 6;
        dp = target->query_skill("parry") + target->query("con") * 5;
        dd = target->query_skill("dodge") + target->query("dex") * 5;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
target->apply_condition("tiezhang_yin",50);
                msg +=HIW "霎那间$n" HIW "已被$N" HIW "阴寒掌劲拂中要"
               "害，不由得浑身一颤，难受之极。\n" NOR;

        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "掌出如风，心知"
                       "此招后着极是凌厉，当即斜跳闪开。\n" NOR;
        }

        msg += HIR "\n紧接着$N" HIR "右掌一振，掌风过处，竟席"
               "卷起一股热浪，向$n" HIR "胸前猛然拍落。\n" NOR;  

        if (ap / 2 + random(ap) > dd)
        {
                damage = ap / 2 + random(ap / 2);
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
target->apply_condition("tiezhang_yang",50);
                msg +=HIR "只听嗤的一声，$N" HIR "右掌如击败革，正中"
               "$n" HIR "胸口，震断了数根肋骨。\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "忽闻呼啸声大至，眼见$N" CYN
                       "掌势如虹，急忙纵跃躲避开来。\n" NOR;
        }
        me->start_busy(3);
        me->add("neili", -400);
        message_combatd(msg, me, target);
        return 1;
}

