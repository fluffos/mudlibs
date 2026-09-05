#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能用冰川心法来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                 return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("bingchuan-xinfa", 1) < 50)
                return notify_fail("你的冰川心法等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("kuihua-shengong",1) > 600) level = 3;
        else if ( (int)me->query_skill("kuihua-shengong",1) > 400) level = 4;
        else level = 5;  
        message_vision(HIR "$N气沉丹田，运用冰川心法来提升自己的战斗力。\n" NOR, me);        

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的冰川心法运行完毕，将内力收回丹田。\n");
}

