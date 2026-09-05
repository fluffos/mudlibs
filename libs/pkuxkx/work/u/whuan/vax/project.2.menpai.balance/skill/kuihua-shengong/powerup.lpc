// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用葵花神功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
             return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("kuihua-shengong", 1) < 120)
                return notify_fail("你的葵花神功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N气沉丹田，运用葵花神功来提升自己的战斗力。\n" NOR, me
);

        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/dodge", skill/4);
        me->set_temp("powerup", 1);

        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/5);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的葵花神功运行完毕，将内力收回丹田。\n");
}

