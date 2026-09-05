// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me ) 
                return notify_fail("你只能用浩气苍冥功提升自己的战斗力。\n");
        if( (int)me->query("neili") < 200 ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup")) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("cangming-gong",1) > 600) level = 3;
        else if ( (int)me->query_skill("cangming-gong",1) > 400) level = 4;
        else level = 5;

        message_combatd(HIR "$N慷慨长啸，苍冥功陡然运起，周遭尽是磅礴之气，众人觉得甚是悲怀壮烈。\n" NOR, me);

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("force", -100);
        
        me->set_temp("active_force_buffer/cangming-gong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/cangming-gong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/cangming-gong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/cangming-gong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2
        
        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
       me->add_temp("apply/attack", - amount);
       me->add_temp("apply/dodge", - amount);
       me->delete_temp("powerup");
       me->delete_temp("active_force_buffer/cangming-gong.powerup");
       tell_object(me, "浩气苍冥功运功完毕，心中壮怀之激烈情绪犹留心中。\n");
}

