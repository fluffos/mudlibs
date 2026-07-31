#include <ansi.h>



inherit F_CLEAN_UP;



void remove_effect(object me, int amount);



int exert(object me, object target)

{

        int skill;



        if( target != me ) 

                return notify_fail("你只能用天魔大法来提升自己的战斗力。\n");



        if( (int)me->query("neili") < 100  ) 

                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") ) 

                return notify_fail("你已经在运功中了。\n");



        skill = me->query_skill("force");

        me->add("neili", -100);

        me->receive_damage("qi", 0);



        message_vision(

        HIY "$N运起天魔大法，全身骨骼叻嘞作响，肌肉贲张，体形"

            "暴涨近半，全身发出金色豪光。\n" NOR, me);



        me->add_temp("apply/attack", skill/3);

        me->add_temp("apply/dodge", skill/3);

        me->set_temp("powerup", 1);



        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);



        if( me->is_fighting() ) me->start_busy(3);



        return 1;

}



void remove_effect(object me, int amount)

{

        int skill;
        skill = me->query_skill("force");
        me->add_temp("apply/attack", -skill/3);

        me->add_temp("apply/dodge", -skill/3);

        me->delete_temp("powerup");

        tell_object(me, "你的天魔大法运行完毕，全身筋肉缓缓恢复原样。\n");

}

