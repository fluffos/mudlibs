// fenxin.c 圣火焚心
// Modified by iszt@pkuxkx, 2007-04-18, descriptions
// Modified by zine@pkuxkx, 2013-02
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version")
        return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg, color;
    object weapon;
    
    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「圣火令法」的精髓只能对战斗中的对手使用。\n");

    if ((int)me->query("neili") < 150)
        return notify_fail("你的内力不够，无法使出「圣火令法」的精髓！\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "dagger")
/*       if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "dagger") */
        return notify_fail("你右手没有匕首类武器,无法使出「圣火令法」的精髓！\n");

    if ((int)me->query_skill("shenghuo-lingfa", 1) < 180)
        return notify_fail("你的圣火令法不够娴熟，无法使出「圣火令法」的精髓！\n");

    if (custom_color(me) == NOR)
        color = BRED;
    else color = custom_color(me);

    if (!me->query("env/shenghuo"))
    {
        msg = color + "$N" + color + "突然连翻三个空心筋斗。$n" + color + "不知他是何用意，心想还是避之为妙。\n" + NOR;
        message_vision(msg, me, target);
    //    me->remove_all_killer();
    }
    //msg = HIR "\n$N使出圣火神功的绝招「圣火焚心」，纵身一跃，从不可思议的角度连出七招，如烈焰般笼罩$n全身！\n"NOR;
    me->start_busy(2);
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target))
    {
        msg = color + "$n" + color + "刚向左踏开一步，眼前白光急闪，右肩已被$N" + color + "的手中兵刃重重击中。这一招更是匪夷所思。\n"NOR;
        //msg += HIR"结果$p被$P一剑刺中要害，无法支撑，倒在地上。\n" NOR ;
        message_vision(msg, me, target);
        F_KUNGFU->hit_wound("qi", me->query_skill("shenghuo-lingfa", 1) * 5 / 2, 0, me, target);
        COMBAT_D->report_status(target);
        if (!me->query("env/shenghuo"))
            if (random(2))
                target->kill_ob(me);
    }
    me->add("neili", -100);
    return 1;
}
