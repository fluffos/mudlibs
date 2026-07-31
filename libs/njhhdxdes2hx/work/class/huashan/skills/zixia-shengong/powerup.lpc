// powerup.c 紫霞神功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用紫霞神功来提升自己的战斗力。\n");

        if ((int)me->query_skill("zixia-shengong", 1) < 40)
                return notify_fail("你的紫霞神功等级不够，无法提升自己的战斗力。\n");

        if( (int)me->query("force") < 100  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功\中了。\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 0);
        message_vision(
        MAG "$N脸色微微发紫，运起紫霞神功，只觉得全身充满了力量。\n" NOR, me);
        me->add_temp("apply/attack", skill/6);
        me->add_temp("apply/dodge", skill/6);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的紫霞神功运行完毕，将内力收回丹田。\n");
}
