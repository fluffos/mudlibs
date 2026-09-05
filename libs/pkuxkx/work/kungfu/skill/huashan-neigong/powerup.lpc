// powerup.c 紫霞神功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能用紫霞神功来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 200  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("huashan-neigong", 1) < 50)
                return notify_fail("你的华山内功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");
        level = 5;
        if ( me->query("huashan_newskills/jianzong") )
        {
          if ( (int)me->query_skill("zixia-shengong",1) > 600) 
          {
            level = 3;
            skill = skill*5/6;
          }
          else if ( (int)me->query_skill("zixia-shengong",1) > 300) level = 4;
          else level = 5;
        }
        else 
          level=5;

        if ( level == 3)
                message_vision(HIW "$N华山内功融会紫霞诀要，脸上泛起一团紫霞，劲力悉数提起。\n" NOR, me);                
        else if ( level == 4)
                message_vision(HIW "$N灵犀一动，化紫霞于气，暗运华山内功，提升自己的战斗力。\n" NOR, me);
        else    message_vision(HIW "$N暗运华山内功，提升自己的战斗力。\n" NOR, me);                

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);

        me->add("neili", -100);

        me->set_temp("active_force_buffer/huashan-neigong.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/huashan-neigong.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/huashan-neigong.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/huashan-neigong.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/huashan-neigong.powerup");
        tell_object(me, "你的华山内功运行完毕，将内力收回丹田。\n");
}

