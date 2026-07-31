// powerup.c 明玉功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用明玉功来提升自己的战斗力。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force")/2;
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIR "$N" HIR "运起玉明功，全身皮肤瞬间变得晶莹无比，光滑异常，整个人\n"
                        "神圣而不可侵犯，散发着令人心颤的寒气。\n" NOR, me);
if (skill >200) skill=200;

        me->add_temp("apply/attack", skill * 2 / 5);
        me->add_temp("apply/parry", skill / 3);
        me->add_temp("apply/dodge", skill / 3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("powerup"))
        {
                me->add_temp("apply/attack", - (amount * 2 / 5));
                me->add_temp("apply/parry", - (amount / 3));
                me->add_temp("apply/dodge", - (amount / 3));
                me->delete_temp("powerup");
                tell_object(me, "你的明玉功运行完毕，将内力收回丹田。\n");
        }
}

