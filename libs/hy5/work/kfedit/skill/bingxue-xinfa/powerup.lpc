// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("你只能用冰雪心法提升自己的战斗力。\n");
        if( (int)me->query("neili") < 100 ) return
            notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) return
            notify_fail("你已经在运功中了。\n");

        skill = (int)me->query_skill("bingxue-xinfa",1);

//        me->add("bellicosity", 100 + skill/2 );
        me->add("neili", -100);
        me->receive_damage("qi",0);

        message_combatd(
HIW"$N长啸一声,真气激发,周身一层青气氤氲,隐隐透体而出，弥漫四周。\n" NOR, me);
       me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->add_temp("apply/damage", skill/3);
        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);
  me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/3:),skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/damage", - amount);
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的冰雪心法运行完毕，将内力收回丹田。\n");
}


