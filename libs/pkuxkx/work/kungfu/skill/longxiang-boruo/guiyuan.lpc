
#include <ansi.h>

//inherit SSERVER;

int exert(object me, object target)
{
    if (!objectp(target) || target == me)
        return notify_fail("你想要帮谁凝魄归元？\n");

    if ((int)me->query_skill("longxiang-boruo", 1) < 700)
        return notify_fail("只有修炼到龙象般若功第七层之后，才能施展聚魄归元。\n");

    if ((int)me->query("max_neili") < 2000)
        return notify_fail("你的内力修为太差，多多打坐吧。\n");

    if ((int)me->query("neili") < 1000)
        return notify_fail("你的真气不够。\n");

    if ( living(target) || target->query("disable_type") == "<睡梦中>" )
        return notify_fail("人家好好的，你归什么元？\n");

    if (target->is_corpse())
        return notify_fail("来不及了，只有活人才能救醒。\n");

    if ((int)me->query("jingli") < 50)
        return notify_fail("你的精力不够！\n");

    me->add("jingli", -50);
    me->add("neili", -500);
    message_vision(HIY "$N一手放在$n的天灵盖上，一手贴在$n的後心，闭上眼睛缓缓低吟 ...\n" NOR,
                   me, target);
    if (random(me->query("max_jingli")) > 500)
    {
        target->revive();
        me->receive_wound("jing", 100, "使用搜魂归元大法耗尽精神而");
        me->receive_damage("qi", 300);
        me->start_busy(5);
    }
    else
        me->unconcious();
    if (me->is_fighting())
        me->start_busy(2);
    return 1;
}

