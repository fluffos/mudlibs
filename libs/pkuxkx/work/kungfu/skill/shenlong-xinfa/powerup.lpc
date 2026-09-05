// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int level, int skill);

int exert(object me, object target)
{
        int skill, level;

        if( target != me ) 
                return notify_fail("你只能用神龙心法提升自己的战斗力。\n");
        if( (int)me->query("neili") < 200)
                return notify_fail("你的内力不够!");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("shenlong-xinfa",1) > 600) level = 3;
        else if ( (int)me->query_skill("shenlong-xinfa",1) > 400) level = 4;
        else level = 5;

        message_combatd(HIM "$N舌尖一咬，喷出一口紫血，顿时一股内力直贯双臂！\n" NOR, me);

        me->add_temp("apply/attack", skill/(level+1));
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);
        
        me->set_temp("active_force_buffer/shenlong-xinfa.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/shenlong-xinfa.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/shenlong-xinfa.powerup/effect1", "攻击命中+"+(skill/(level+1))+"级");   //效果描述1   
        me->set_temp("active_force_buffer/shenlong-xinfa.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2
        if ( me->query_skill("dulong-bi", 1)>= 150 &&
      	     me->query_skill("shenlong-xinfa", 1)>= 150 )
          me->set_temp("active_force_buffer/shenlong-xinfa.powerup/effect3", "毒龙匕法攻击速度+"+(20+me->query("dex"))+"%");     //效果描述3
        
        me->start_call_out(__FILE__, "remove_effect", skill/level, me, level, skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int level, int skill)
{
        me->add_temp("apply/attack", - skill/(level+1));
        me->add_temp("apply/dodge", - skill/level);
        me->delete_temp("powerup"); 
        me->delete_temp("active_force_buffer/shenlong-xinfa.powerup");
        tell_object(me, "你的神龙心法运行完毕，将内力收回丹田。\n");
}

