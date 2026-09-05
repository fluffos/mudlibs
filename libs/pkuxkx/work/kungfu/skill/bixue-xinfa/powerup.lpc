// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int level, int skill);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能用碧血心法来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 300  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                 return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("bixue-xinfa", 1) < 40)
                return notify_fail("你的碧血心法等级不够，不能提升战斗力。\n");
 
        skill = me->query_skill("force");
        level = 5; 
        if( (int)me->query("pin") == 1) level = 3;
        else if ( (int)me->query("pin") < 5) level = 4;
        else level = 5;
        message_vision(HIR "$N气沉丹田，运用碧血心法来提升自己的战斗力。\n" NOR, me);

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/(level+1));
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/bixue-xinfa.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/bixue-xinfa.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/bixue-xinfa.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/bixue-xinfa.powerup/effect2", "轻功技能+"+(skill/(level+1))+"级");   //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, level, skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int level, int skill)
{ 
        me->add_temp("apply/attack", - skill/level);
        me->add_temp("apply/dodge", - skill/(level+1));
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/bixue-xinfa.powerup");
        tell_object(me, "你的碧血心法运功完毕，将内力收回丹田。\n");
}

