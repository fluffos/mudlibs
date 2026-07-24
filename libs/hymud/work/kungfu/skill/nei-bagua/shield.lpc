// shield.c 内功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("你只能用内功来提升自己的防御力。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你的真气不够。\n");

        if ((int)me->query_skill("force", 1) < 80)
                return notify_fail("你的内功等级不够。\n");


        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        if (skill>1000) skill=1000;
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_combatd(HIR "$N" HIR "默念八卦护体功的口诀\n刹那间只见$N" 
                        HIR "全身顿时浮现出一层刚猛的劲气，将$P"
                        HIR "全全笼罩。\n" NOR, me);

        
       
        me->add_temp("apply/dodge", skill/5);
        tell_object(me,HIG"你的轻功提高了!\n"NOR);
        me->add_temp("apply/armor", skill );
        tell_object(me,HIG"你的防御力提高了!\n"NOR);
        me->set_temp("shield", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shield"))
        {
        me->add_temp("apply/dodge", -(amount/5));
        me->add_temp("apply/armor", -amount);
                me->delete_temp("shield");
                tell_object(me, "你的金钟罩神功运行完毕，将内力收回丹田。\n");
        }
}

