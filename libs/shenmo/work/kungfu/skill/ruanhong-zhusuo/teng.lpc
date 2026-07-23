// tengshe.c 腾蛇诀

#include <ansi.h>
#include <combat.h>

#define TENGSHE "「" WHT "腾蛇诀" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);


        if (! target || ! me->is_fighting(target))
                return notify_fail(TENGSHE "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对，无法施展" TENGSHE "。\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 60)
                return notify_fail("你的软红蛛索不够娴熟，无法施展" TENGSHE "。\n");

        if (me->query("neili") < 200)
                return notify_fail("你的真气不够，无法施展" TENGSHE "。\n");
         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("你的五毒神功修为还不够！\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("你的基本毒功修为还不够！\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("你没有激发软红蛛索，无法施展" TENGSHE "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "陡然施展出「腾蛇」诀，手腕轻轻一抖，" + weapon->name() +
              WHT "顿时拔地弹起，如同活物一般悄然袭向$n" + WHT "！\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3)
        {
                damage = ap / 2 + random(ap / 4)+500;
                me->add("neili", -150);
                me->start_busy(1);
target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "然而$n" HIR "未能看破企图，一声惨嚎，"
                                           + weapon->name() + HIR "鞭端已没入体内半寸"
                                           "，登时连退数步！\n" NOR;
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 50 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 50 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 50 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 50 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 50 );
	       target->apply_condition("wuhudu_poison",
		        (int)target->query_condition("wuhudu_poison") + 50 );
	       target->apply_condition("chilian_poison",
		        (int)target->query_condition("chilian_poison") + 50 );
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "运足内力，奋力挡住了"
                       CYN "$P" CYN "这神鬼莫测的一击！\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
