//handu.c -冰魄寒毒
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    object weapon;
    int damage;

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「冰魄寒毒」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff")
        return notify_fail("连个杖都没有，施展什么「冰魄寒毒」呀。\n");

    if (me->query_skill("force", "huagong-dafa") < 180)
        return notify_fail("有效内功 180 级以上才能施展「冰魄寒毒」。\n");

    if (me->query_skill("staff", "tianshan-zhang") < 180)
        return notify_fail("有效杖法 180 级以上才能施展「冰魄寒毒」。\n");

    if (me->query("neili") < 400)
        return notify_fail("内力 400 以上才能施展「冰魄寒毒」。\n");

/*    if (!(weapon = me->query_temp("weapon")))
        weapon = me->query_temp("secondary_weapon");
    if (!weapon)
        return notify_fail("连个武器都没有，施展什么「冰魄寒毒」呀。\n"); */


    msg = CYN"$P突然诡秘一笑，手中" + weapon->name() + CYN"向$p横扫过去。\n"NOR;
    me->start_busy(2);
    //命中率级别是C-
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9, me, target))
    {
        msg += HIG"$p突然打了个寒战，明显感到一股寒流已经侵入体内！\n" NOR;
        damage = 2 * (int)me->query_skill("tianshan-zhang", 1);
        //target->set_temp("death_cond_origin/xxx_poison", me);
		F_POISON->poison_attack(me,target,"xxx_poison", me->query_skill("huagong-dafa", 1) / 10 + target->query_condition("xxx_poison"));
        F_KUNGFU->hit_wound("qi", damage, damage / 4, me, target);
    }
    else
    {
        msg += CYN"$p下意识地跳到一旁，但还是被吓出了一身冷汗。\n" NOR;
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    target->kill_ob(me);
    return 1;
}

