#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int base_cd = 3; //单位秒

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    int ratio1, ratio2, ratio3; 
    string msg;

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天蝠嗜血」只能对战斗中的对手使用。\n");

    if ( me->query_temp("hanbing-zhang/shixue") )
        return notify_fail("你刚刚吸取过血！\n");

    if ( time() >= me->query_temp("hanbing-zhang/shixue2") && 
         (time()-me->query_temp("hanbing-zhang/shixue2") <= 2*base_cd) )
        return notify_fail("对手太弱，此招过狠，还是不使为妙。\n");

    if ( time() >= me->query_temp("hanbing-zhang/shixue3") && 
         (time()-me->query_temp("hanbing-zhang/shixue3") <= 2*base_cd) )
        return notify_fail("你的内力不够，无法施展「天蝠嗜血」。\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "guangming-shenghuogong" )
        return notify_fail("你没有激发光明圣火功，无法施展「天蝠嗜血」。");;

    if( me->query_skill("force", 1) / 2 + me->query_skill("guangming-shenghuogong", 1) < 120)
        return notify_fail("你的内功等级不够，无法施展「天蝠嗜血」。");

    if (me->query_skill("strike", 1) / 2 + me->query_skill("hanbing-zhang", 1) < 120)
        return notify_fail("你的寒冰绵掌等级不够，施展不出「天蝠嗜血」。\n");

    if (me->query("neili") < 300 || me->query("max_neili") < 300)
        return notify_fail("你的内力不够，无法施展「天蝠嗜血」。\n");

    // over flood here, fixed by jpei 20080120
    ratio1 = (int)random(me->query("combat_exp")) / 1000;
    ratio2 = (int)target->query("combat_exp") / 2000 + 1;
    ratio3 = (int)me->query_skill("hanbing-zhang", 1) * ratio1 / ratio2 / 5;

    if (ratio1 > (ratio2 * 40))
    {
        me->set_temp("hanbing-zhang/shixue2", time());
        return notify_fail("对手太弱，此招过狠，还是不使为妙。\n");
    }

    if (ratio3 > me->query("neili"))
    {
        me->set_temp("hanbing-zhang/shixue3", time());
        return notify_fail("你的内力不够，无法施展「天蝠嗜血」。\n");
    }

    msg = BLU "$N性情大变，脸色铁青，突然欺身到$n面前，露出森森白牙，向$n的脖子咬去\n";

    if (!target->is_killing(me->query("id")))
        target->kill_ob(me);

    me->set_temp("hanbing-zhang/shixue", 1);
    me->start_busy(2);
    if (ratio1 > ratio2)
    {
        msg += "结果$p全身鲜血大半都被$P吸去，$p登时浑身疲软，无比难受.\n" NOR;
        tell_object(target, sprintf("%d", me->query_skill("hanbing-zhang", 1) * ratio1 / ratio2));
        F_KUNGFU->hit_wound("qi", (int)me->query_skill("hanbing-zhang", 1) * ratio1 / ratio2,
                            (int)me->query_skill("hanbing-zhang", 1) * ratio1 / ratio2 / 4, me, target);
        if (target->query("combat_exp") >= me->query("combat_exp"))
            me->add("combat_exp", 2);

        me->start_busy(random(4));
        target->start_busy(random(4));
        me->add("neili", -ratio3);

        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        call_out("del_shixue", base_cd, me);
    }
    else
    {
        msg += "结果$p轻轻一闪躲过$P的一击，$P嗜血不中，浑身难受，元气大伤。\n" NOR;
        message_vision(msg, me, target);
        F_KUNGFU->hit_wound("qi", (int)me->query_skill("hanbing-zhang", 1) / 10, 0, target, me);
        COMBAT_D->report_status(me);
        me->add("neili", -50);
        me->start_busy(random(4));
        call_out("del_shixue", 2*base_cd, me);
    }

    return 1;
}


void del_shixue(object me)
{
    if (!me)
        return;
    if (me->query_temp("hanbing-zhang/shixue"))
        me->delete_temp("hanbing-zhang/shixue");
}

