// powerup.c 抱元劲

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能用抱元劲来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 200  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("hunyuan-gong", 1) < 50)
                return notify_fail("你的混元功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        if ( (int)me->query_skill("hunyuan-gong",1) > 400) level = 3;
        else if ( (int)me->query_skill("hunyuan-gong",1) > 300) level = 4;
        else level = 5;

        if ( level == 3)
                message_vision(HIW "$N潜运抱元劲诀窍，提升自身功力。\n" NOR, me);                
        else if ( level == 4)
                message_vision(HIW "$N运转抱元劲诀窍，提升自身功力。\n" NOR, me);
        else    message_vision(HIW "$N默运抱元劲诀窍，提升自身功力。\n" NOR, me);                

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);

        me->add("neili", -100);

        me->set_temp("active_force_buffer/hunyuan-gong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/hunyuan-gong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/hunyuan-gong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/hunyuan-gong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/hunyuan-gong.powerup");
        tell_object(me, "你的抱元劲运行完毕，将内力收回丹田。\n");
}

