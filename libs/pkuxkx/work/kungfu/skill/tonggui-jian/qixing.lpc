// qixing.c 同归剑法--七星会聚

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    int damage;
    object weapon;

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「七星会聚」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
/*        if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword") */
            return notify_fail("你右手无剑，如何使得出「七星会聚」？\n");

    if ((int)me->query_skill("tonggui-jian", 1) < 100)
        return notify_fail("你的同归剑法不够火候, 使不出「七星会聚」。\n");

    if ((int)me->query("neili") < 150)
        return notify_fail("你的内力不够呀!\n");

    msg = HIC "$N"HIC"一声长啸，使出同归剑法的「七星会聚」, 剑尖笼罩$n"HIC"身上七处大穴！\n";
    me->start_busy(2);
    me->add("neili", -100);
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target))
    {
        msg += HIR"结果$p"HIR"被$P"HIR"刺个正着。\n" NOR;
        message_vision(msg, me, target);
        damage = (int)me->query_skill("tonggui-jian", 1);
        damage = damage * 3;
        F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        me->start_busy(3);
        msg += CYN"可是$p"CYN"看破了$P"CYN"的企图，并没有上当。\n" NOR;
        message_vision(msg, me, target);
    }
    return 1;
}

