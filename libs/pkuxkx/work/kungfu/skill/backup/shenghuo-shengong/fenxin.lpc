// fenxin.c 圣火焚心
// Modified by iszt@pkuxkx, 2007-04-18, descriptions

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if ( (int)me->query("neili") <150)
                return notify_fail("你的内力不够，无法使出「圣火焚心」！\n");
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「圣火焚心」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
                || (string)weapon->query("skill_type") != "sword")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使得出剑法绝招？\n");

        if ((int)me->query_skill("shenghuo-shengong",1) < 150 )
                return notify_fail("你的圣火神功不够娴熟，不会使用「圣火焚心」。\n");

        msg = HIR "\n$N使出圣火神功的绝招「圣火焚心」，纵身一跃，从不可思议的角度连出七招，如烈焰般笼罩$n全身！\n"NOR;
        me->start_busy(2);
        if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) )
        {
                msg += HIR"结果$p被$P一剑刺中要害，无法支撑，倒在地上。\n" NOR ;
                message_vision(msg, me, target);
                F_KUNGFU->hit_wound("qi", me->query_skill("shenghuo-shengong",1)*5/2, 0, me, target);
                COMBAT_D->report_status(target);
        }
        else
        {
                msg += HIG"可是$p早有防备，轻松地躲开了。\n"NOR;
                message_vision(msg, me, target);
        }
        me->add("neili",-100);
        return 1;
}
