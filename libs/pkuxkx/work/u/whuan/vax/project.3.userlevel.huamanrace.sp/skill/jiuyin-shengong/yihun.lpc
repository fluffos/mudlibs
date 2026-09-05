//yihun.c 移魂大法

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
    if( (int)me->query_skill("jiuyin-shengong",1) <80 )
        return notify_fail("九阴神功 80 级以上才能施加移魂大法。\n");

    if( (int)me->query("neili",1) < 50 )
        return notify_fail("你的内力不到 50，不能使用移魂大法。\n");

    if( target->is_busy() )
        return notify_fail("你的移魂大法还在" + target->name() + "身上发挥着效力，放胆攻击吧！\n");

    message_vision(HIR"$N突然神秘的一笑，双眼紧叮着$n，象要把$n的魂摄下来。\n\n" NOR, me, target );

    me->add("neili", -50);
    if(random(me->query("combat_exp")+me->query_skill("force")*900)>target->query("combat_exp")/2 )
    {
        tell_object(target, HIR "你恍恍忽忽，乱蹦乱舞，不知道自己在做什么。\n" NOR);
        message_vision(HIG "只见$n乱蹦乱舞，象一只无头苍蝇一样地到处转。\n" NOR, me, target);
        target->start_busy(5+random(6));
    }
    else
    {   
        message_vision(HIY "可是$p看破了$P的企图，继续攻击。\n" NOR, me, target);
        me->start_busy(2);
    }
    return 1;
}
