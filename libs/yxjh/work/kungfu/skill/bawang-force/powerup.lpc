#pragma save_binary
// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能用霸王功提升自己的战斗力。\n");

       if( (int)me->query("neili") < 1000 )     return 
notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return 
notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("bawang-force");
 
     me->add("neili", -800);

        message_vision(
                HIR 
"$N大喝一声！嘿～　　～　　～运起霸王功。顷刻之间功力提升了许多。。。\n" NOR, me);

        me->add_temp("apply/attack", 2*skill/5);
        me->add_temp("apply/dodge", 2*skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
2*skill/5 :), skill);

        if( me->is_fighting()&&userp(me) ) me->start_busy(6);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的霸王功运行完毕，将内力收回丹田。\n");
}
 

