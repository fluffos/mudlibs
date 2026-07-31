// powerup.c 易筋经加力

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能提升自己的战斗力。\n");
        if( (int)me->query("neili")<200)
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        message_combatd(
                HIR "$N面色火红，低声咏唱佛法将全身战斗力尽数提起。\n" NOR, me);

        me->add_temp("apply/attack", skill * 2 / 5);
        me->add_temp("apply/defense", skill * 2 / 5);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill * 2 / 5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/defense", - amount);
        me->delete_temp("powerup");
	tell_object(me, "你长吸一口真气，将内息调匀收了回去。\n");
}

