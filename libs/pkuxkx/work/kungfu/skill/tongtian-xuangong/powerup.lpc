// powerup.c 紫霞神功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

//        if( target != me )
//                return notify_fail("你只能用无常离合梅花功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
//        if( (int)me->query_temp("powerup") )
//                return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("wuchang", 1) < 30)
                return notify_fail("你的无常离合梅花功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force", 1);
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        tell_object(
        HIR "$N运起无常离合梅花功，脸上微微泛出一丝紫气。\n" NOR, me);

        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dodge", skill);
        me->set_temp("powerup", 1);

//        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/4);

        if( me->is_fighting() ) me->start_busy(0);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的无常离合梅花功运行完毕，将内力收回丹田。\n");
}
