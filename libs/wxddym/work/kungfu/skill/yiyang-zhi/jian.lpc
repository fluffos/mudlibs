#include <ansi.h>
#include <combat.h>

#define JIAN "「" HIW "先天功" HIR "乾阳" HIY "剑气" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, i, damage;
        string msg;
        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("你的枯荣禅功太低。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIAN "只能对战斗中的对手使用。\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("没有枯荣禅功作为准备，无法使出！\n"); 

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIAN "只能空手施展。\n");


        if ((int)me->query_skill("yiyang-zhi", 1) < 280)
                return notify_fail("你一阳指诀不够娴熟，难以施展" JIAN "。\n");


        if (me->query("max_neili") < 5000)
                return notify_fail("你的内力修为不足，难以施展" JIAN "。\n");
        if (me->query_skill_mapped("unarmed") != "yiyang-zhi")
                return notify_fail("你没有激发一阳指为指法，难以施展" JIAN "。\n");

        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("你没有激发一阳指为指法，难以施展" JIAN "。\n");


        if (me->query("neili") < 1000)
                return notify_fail("你现在的真气不足，难以施展" JIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "霎时只见$N" HIY "逆运" HIW "先天真气" HIY "，化为" HIR
              "纯阳内劲" HIY "聚于指尖，以一阳指诀手法疾点$n" HIY "全身诸"
              "多要穴。\n" NOR;  

        ap = me->query_skill("force") +
           me->query_skill("finger") +
           me->query_skill("unarmed");

        dp = target->query_skill("force") +
           target->query_skill("parry") +
           target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "只觉全身一热，$P" HIR "「"
                                           HIW "先天功" HIR "乾阳" HIY "剑气" HIR
                                           "」顿时破体而入，便似身置洪炉，喷出一口"
                                           "鲜血。\n" NOR;
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "这指来势汹涌，不敢"
                       "轻易招架，当即飞身纵跃闪开。\n" NOR;
                message_combatd(msg, me, target);
        }

        msg = HIR "紧接着$N" HIR "十指纷飞，接连弹出数道无形剑气，$n"
              HIR "四面八方皆被剑气所笼罩。\n"NOR;
        message_combatd(msg, me, target);

        me->add_temp("apply/attack", 100);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -100);
        me->add("neili", -600);
        me->start_busy(4);
        return 1;
}
