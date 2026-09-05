// duo.c 空手入白刃
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me)
{
    string msg;
    object weapon, weapon2, target;

    if ((int)me->query_temp("duo"))
        return notify_fail("你已经在夺敌人的兵刃了。\n");

    me->clean_up_enemy();
    target = me->select_opponent();

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「空手入白刃」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = target->query_temp("weapon")) && !objectp(weapon2 = target->query_temp("secondary_weapon")))
        return notify_fail("对方没有兵刃，你不用担心。\n");

    if ((int)me->query_skill("zhemei-shou", 1) < 120)
        return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！\n");

    if ( me->query_skill("xiaowuxiang-gong", 1) < 100 || me->query_skill("bahuang-gong", 1) < 100 )
        return notify_fail("你的灵鹫宫内功火候不够。\n");

    if (me->query("neili") < 100)
        return notify_fail("你的内力不够，无法空手入白刃！\n");

    if (me->query_skill_prepared("hand") != "zhemei-shou" || me->query_skill_mapped("hand") != "zhemei-shou")
        return notify_fail("你现在没有激发或者没有备天山折梅手。\n");

    msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技. \n";
    message_vision(msg, me);

    //命中率D-
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 12, me, target))
    {
        if (userp(me)) me->add("neili", -100);
        msg = HIW"$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
        if (!target->is_busy()) target->start_busy(2);
        if (objectp(weapon))
        {
            weapon->unequip();
            weapon->move(environment(me));
            if (!userp(me) && weapon) weapon->set("no_get", 1);
            if (target->query("kill_reward")) destruct(weapon);
        }
        else
        {
            weapon2->unequip();
            weapon2->move(environment(me));
            if (!userp(me)) weapon2->set("no_get", 1);
            if (target->query("kill_reward")) destruct(weapon2);
        }
        me->start_busy(random(2));
    }
    else
    {
        msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
        me->start_busy(random(3));
    }
    message_vision(msg, me, target);

    return 1;
}

