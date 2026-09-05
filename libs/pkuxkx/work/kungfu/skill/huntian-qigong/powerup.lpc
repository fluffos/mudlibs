// powerup.c 混天气功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me ) 
                return notify_fail("你只能用混天气功来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 100  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        level = 5;
        // begging决定头衔，应该更合理一些。
        if ( (int)me->query_skill("begging",1) > 300) level = 3;
        else if ( (int)me->query_skill("begging",1) > 200) level = 4;
        else level = 5;

        message_vision(HIR "$N微一凝神，运起混天气功，全身骨节发出一阵爆豆般的声响！\n" NOR, me);

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);
        
        me->set_temp("active_force_buffer/huntian-qigong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/huntian-qigong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/huntian-qigong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/huntian-qigong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2
        
        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/huntian-qigong.powerup");
        tell_object(me, "你的混天气功运行完毕，将内力收回丹田。\n");
}

