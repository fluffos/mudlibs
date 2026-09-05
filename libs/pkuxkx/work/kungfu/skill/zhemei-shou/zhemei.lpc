// zhemei.c
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("折梅只能对对手使用。\n");

    if (environment(me)->query("no_fight"))
        return notify_fail("这里不能攻击别人! \n");

    if ( me->check_hand() >= 1 )
        return notify_fail("折梅只能双手空手运用。\n");

    if ( me->query_skill("zhemei-shou", 1) < 120 )
        return notify_fail("你的折梅手不够娴熟，不会使用折梅。\n");

    if ( me->query_skill("beiming-shengong", 1) < 120
          && me->query_skill("xiaowuxiang-gong", 1) < 120
          && me->query_skill("bahuang-gong", 1) < 120 )
        return notify_fail("你的逍遥三大内功不够娴熟，不会使用折梅。\n");

    if ((int)me->query("neili") < 400 || (int)me->query("max_neili") < 1000)
        return notify_fail("你现在内力太弱，不能使用折梅。\n");

    me->add("neili", -200);
    msg = HIC "$N手法突然加快，迅速靠近$n，一式[折梅]切住$n手臂要穴，用力弯折。\n"NOR;
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target))
    {
        msg += HIR"结果$n的手臂被$N弯折得无法动弹，只觉一阵疼痛难忍。\n"NOR;
        message_combatd(msg, me, target);
        damage = me->query_skill("hand", "zhemei-shou")/2 + me->query_skill("force", "beiming-shengong")/3 + 
                 me->query_skill("force", "xiaowuxiang-gong")/3 + me->query_skill("force", "bahuang-gong")/3;
        damage = damage + random(damage);
        F_KUNGFU->hit_wound("qi", damage, damage / 3, me, target);
        COMBAT_D->report_status(target);
        if (!target->is_busy())
            target->start_busy(2);
    }
    else
    {
        msg += CYN"可是$p用力一震，震了开去。\n"NOR;
        message_combatd(msg, me, target);
        if (!target->is_busy())
            target->start_busy(1);
    }
    me->start_busy(2 + random(2));

    return 1;
}

