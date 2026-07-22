//zhanqi by yushu 2001.2
// lilong alter 2002.01.17
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        skill = me->query_skill("shushan-force",1);
	 if( skill > 150 ) { skill=150;}
        if( target != me ) 
		return notify_fail("你只能对自己使用。\n");

        if( (int)me->query("neili") < skill*2 )     
		return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

        me->add("neili", -skill);
        me->receive_damage("qi", 50);

        message_vision(
                HIM "$N微一凝神，运起蜀山心法，一股天罡战气从丹天直冲天顶。\n" NOR, me);

        me->add_temp("apply/attack", 2*skill/3);
	 me->add_temp("apply/strength", 2*skill/3);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 2*skill/3 :), skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

void remove_effect(object me, int amount)
{
    if(!me) return;
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("powerup");
    tell_object(me, HIM"你的天罡战气循环一周天完毕，将内力收回丹田。\n"NOR);
}

