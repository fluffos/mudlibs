// duo.c 夺命

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define SHOU  "「" HIG "夺命" NOR "」"
 string query_name() { return "夺命"; }
int perform(object me, object target)
{
        string msg;
        int ap, ap1, dp1, damage;
        mixed dp;



                 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHOU "只能在战斗中对对手使用。\n");

        if (me->query_temp("weapon"))
                return notify_fail("此招只能空手施展！\n");

        if (me->query_skill("yinlong-shou", 1) < 160)
                return notify_fail("你的银龙手还不够娴熟，不能使用" SHOU "！\n");

        if (me->query("neili") < 300)
                return notify_fail("你的真气不够！\n");

        if (me->query_skill_mapped("strike") != "yinlong-shou"
           && me->query_skill_prepared("strike") != "yinlong-shou")
                return notify_fail("你没有准备使用银龙手，无法施展" SHOU "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "双手汇集了全身的内力，顿时全身衣衫鼓胀，双目放出惊人的杀气，\n"
              HIY "在$n" HIY "吃惊之际，$N" HIY "的双手已如流星闪电般挥出，只见一股强大的气流朝$n" HIY "心脏插去！\n" NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
        
        if (ap / 2 + random(ap) > dp)
        {
                ap = me->query_skill("yinlong-shou");
                dp = (int)target->query("combat_exp")< 10000;
                me->add("neili", -60);
                me->start_busy(1 + random(3));

                //me->want_kill(target);

                if (dp >= 10000) // 此招对千万修为以上的人无效
                { // 但是仍然受到伤害
                        damage = me->query_skill("strike");

                        msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 90,
                                        HIR "$n" HIR "只觉此招，来如闪电，无法招架，"
                                        "心中一惊，却猛然间觉得一股阴风透骨而过。\n" NOR);
                        me->add("neili", -140);

                        message_combatd(msg, me, target);
                        // target->start_busy(1 + random(2));
                        return 1;
                } else
                {
                        msg += HIR "这一招完全超出了$n" HIR "的想象，被$N"
                                HIR "双手插入心脏，顿时丧命！\n" NOR;
                        message_combatd(msg, me, target);
                        me->add("neili", -200);
                       // target->die(me);
                        return 1;
                }
        } else
        {
                msg += HIM "$n" HIM "大吃一惊，连忙胡乱抵挡，居"
                                "然没有一点伤害，侥幸得脱！\n" NOR;
                
                me->start_busy(1 + random(3));
        }

        message_combatd(msg, me, target);

        return 1;
}

