// powerup.c 神元功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int level, int skill);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能用神元功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("douzhuan-xingyi",1) > 400) level = 3;
        else if ( (int)me->query_skill("douzhuan-xingyi",1) > 300) level = 4;
        else level = 5;
        message_vision(HIR "$N运起神元功，闭目养神，一会只见$N的脸色变得红润多了。\n" NOR, me);

        me->add_temp("apply/attack", skill/(level+1));
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/shenyuan-gong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/shenyuan-gong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/shenyuan-gong.powerup/effect1", "攻击命中+"+(skill/(level+1))+"级");   //效果描述1   
        me->set_temp("active_force_buffer/shenyuan-gong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, level, skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int level, int skill)
{ 
        me->add_temp("apply/attack", - skill/(level+1));
        me->add_temp("apply/dodge", - skill/level);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/shenyuan-gong.powerup");
        tell_object(me, "你运完神元功，将内力收回丹田。\n");
}

