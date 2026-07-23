// suolong.c 锁龙诀

#include <ansi.h>
#include <combat.h>

#define SUOLONG "「" HIW "锁龙诀" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("你的五毒神功修为还不够！\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("你的基本毒功修为还不够！\n");


        if (! target || ! me->is_fighting(target))
                return notify_fail(SUOLONG "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对，无法施展" SUOLONG "。\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 200)
                return notify_fail("你的软红蛛索不够娴熟，无法施展" SUOLONG "。\n");

        if (me->query("neili") < 350)
                return notify_fail("你的真气不够，无法施展" SUOLONG "。\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("你没有激发软红蛛索，无法施展" SUOLONG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "$N" HIW "使出「锁龙」诀，手中" + weapon->name() +
              HIW "一抖，登时幻出漫天鞭影，宛如蛟龙通天，一齐袭向$n"
              HIW "而去！\n\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 4;
        if (random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3)
        {
                msg += HIC "结果$p" HIC "被$P" HIC
                       "攻了个措手不及，目接不暇，疲于奔命！\n" NOR;
                count = ap / 12;
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
                attack_time += random(ap / 35)+2;
        } else
        {
                msg += HIC "$n" HIC "见$N" HIC "鞭势恢弘，心下凛然，凝神应付。\n" NOR;
                count = 0;
        }
                
        message_combatd(msg, me, target);

        if (attack_time > 9)
                attack_time = 9;

        me->add("neili", -attack_time * 20);

                me->add_temp("apply/attack", 80);
        if (random(3)==0) target->start_busy(3);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -80);
        me->start_busy(2);
        return 1;
}
