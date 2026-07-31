#include <ansi.h>
#include <combat.h>

#define SHA "「" HIR "杀龙无悔" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(SHA "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对，难以施展" SHA "。\n");

        if (me->query_skill("force") < 250)
                return notify_fail("你的内功修为不够，难以施展" SHA "。\n");

        if (me->query_skill("bagua-dao", 1) < 180)
                return notify_fail("你的八卦刀法修为不够，难以施展" SHA "。\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("你没有激发八卦刀法，难以施展" SHA "。\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("你的临济十二庄火候太浅。\n");
                
        if (me->query("neili") < 300)
                return notify_fail("你的真气不够，难以施展" SHA "。\n");


        msg = HIR "$N" HIR "仰天清啸，手中" + weapon->name() +
              HIR "斜划出一道半弧，整个刀身顿时腾起凛冽无比的"
              "杀气，直贯$n" HIR "而去！\n" NOR;

        ap = me->query_skill("blade") + me->query_str() * 10;
        dp = target->query_skill("force") + target->query_con() * 10;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap  + random(ap);
                me->add("neili", -200);
                me->start_busy(2);
		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
		msg +=                     HIR "只听$n" HIR "一声惨叫，$N" HIR +
                                           weapon->name() + HIR "刀锋一闪，竟已嵌"
                                           "入$p" HIR "体内尺许，带出一蓬血雨。\n"
                                           NOR;

        } else
        {
                me->add("neili", -100);
                me->start_busy(2);
                msg += CYN "$n" CYN "见$P" CYN "来势汹涌，不敢轻易抵"
                       "挡，连忙飞身腾挪，躲闪开来。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
