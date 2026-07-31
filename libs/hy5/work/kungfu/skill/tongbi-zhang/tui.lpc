#include <ansi.h>
#include <combat.h>

#define KAI "「" HIW "破甲推山" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(KAI "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(KAI "只能空手施展。\n");

        if ((int)me->query_skill("tongbi-zhang", 1) < 120)
                return notify_fail("你通臂六合掌不够娴熟，难以施展。\n");

        if (me->query_skill("force") < 80)
                return notify_fail("你的内功修为不够，难以施展" KAI "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在的真气不够，难以施展" KAI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

   ap = me->query("combat_exp");
        dp = target->query("combat_exp");

        msg = HIC "\n$N" HIC "长啸一声，施出绝招「" HIW "开山破" HIC "」，一"
              "拳挥出，破空而响，直击$n" HIC "面门和胸口。\n" NOR;
        


        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("tongbi-zhang", 1);
                damage += random(damage)+300;
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n $N" HIR "出手既快，方位又奇，$n"
                                          HIR "闪避不及，闷哼一声，已然中拳。\n" NOR;

                me->add("neili", -100);
	        me->start_busy(1);                                         
        } else
        {
                msg = CYN "$n" CYN "不慌不忙，以快打快，将$N"
                      CYN "这招化去。\n" NOR;

                me->add("neili", -30);
	        me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
