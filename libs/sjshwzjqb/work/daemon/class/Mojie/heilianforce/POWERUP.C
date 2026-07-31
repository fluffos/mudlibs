// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("heilianforce",1);

	if( skill > 300 ) {
		skill=300;
	}

        if( target != me ) 
		return notify_fail("你只能用黑莲心法壮大自己的战斗力。\n");

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIW "$N立足闭气,唤醒身体里的"BLK"黑莲之气"NOR""HIY"，肌肉迅速的膨胀了几倍 \n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/armor", skill/3);
        me->add_temp("apply/dodge", skill/3);
	me->add_temp("apply/strength", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
	me->add_temp("apply/strength", - amount);
	me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的黑莲之气运行一周天完毕，将内力收回丹田。\n");
}

