#include <ansi.h>
#include <combat.h>

#define SHI "「" HIR "万毒噬体" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "只能对战斗中的对手使用。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的内功不够火候，难以施展" SHI "。\n");
         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("你的五毒神功修为还不够！\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("你的基本毒功修为还不够！\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 100 )
		return notify_fail("你的蛇毒奇巧还不够娴熟, 不能打蛇 !\n");

        if (me->query("neili") < 120)
                return notify_fail("你的真气不够，难以施展" SHI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "将体内真气运于双掌之间，只见双掌微微泛出紫光，猛"
              "地拍向$n。\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        if ( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  )
        {

                damage = ap / 2 + random(ap / 2);
                                		target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "只见$n" HIR "被$N" HIR "一掌拍中"
                "，倒退几步，却见脸色已微微泛黑。\n" NOR;
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 10 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 10 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 10 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 10 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 10 );
                me->start_busy(2);
        } else
        {
                msg += CYN "可是$p" CYN "眼明手快，侧身一跳$P"
                       CYN "已躲过$N这招。\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

