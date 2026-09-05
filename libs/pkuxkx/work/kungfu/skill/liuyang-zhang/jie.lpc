// /kungfu/skill/liuyang-zhang/jie.c 解生死符
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

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character())
        return notify_fail("你要给谁解生死符。\n");

    if (target == me)
        return notify_fail("你无法给自己解生死符！\n");

    if ( me->query_skill("bahuang-gong", 1) < 120 )
        return notify_fail("你的八荒六合功不够娴熟，不能解生死符。\n");

    if ((int)me->query_skill("liuyang-zhang", 1) < 150)
        return notify_fail("你的天山六阳掌不够娴熟，不能解生死符。\n");

    if ((int)me->query("neili", 1) < 200)
        return notify_fail("你现在内力太弱，不能解生死符。\n");

    if (!target->query_condition("ss_poison"))
        return notify_fail("目标没有中生死符。\n");

    me->add("neili", -200);
    target->clear_condition("ss_poison");
    msg = CYN "$N使出天山六阳掌，按解生死符的手法，快速的拍向$n的周身大穴。\n"NOR;
    message_vision(msg, me, target);
    return 1;
}
