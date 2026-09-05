// longxiang.c
// modefied by emnil@sj 2/2/00

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level,face;

        if ((int)me->query_skill("longxiang-boruo", 1) < 200)
                return notify_fail("只有修炼到龙象般若功第二层之后，才能增强自己的攻击力。\n");
        if((int)me->query("max_neili")<1000)
                return notify_fail("你的内力修为太差，多多打坐吧。\n");
        if( (int)me->query("neili") < 300 ) 
                return notify_fail("你的真气不够。\n"); 
        if (me->query_temp("xs/longxiang"))
                return notify_fail("你已经在运真气增加攻击力。\n"); 
        if (me->query_temp("powerup"))
        		return notify_fail("你已经在运功中了。\n");
                

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("huanxi-chan",1) > 400) level = 3;
        else if ( (int)me->query_skill("huanxi-chan",1) > 300) level = 4;
        else level = 5;
          
        face=SKILL_D("longxiang-boruo")->query_level(me);
        if (face<2)
        {
            face=2;
        }
        message_vision(HIY"\n$N潜运真气，运起"+chinese_number(face)+"龙"+chinese_number(face)+"象之力，神色间隐约透出一种自信！\n" NOR, me);
        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("xs/longxiang", 1);
        me->set_temp("powerup",1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/longxiang-boruo.longxiang/name", "龙象");                                  //buff名称
        me->set_temp("active_force_buffer/longxiang-boruo.longxiang/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/longxiang-boruo.longxiang/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/longxiang-boruo.longxiang/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2
        me->set_temp("active_force_buffer/longxiang-boruo.longxiang/effect3", "加力消耗大幅降低");                   //效果描述3

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("xs/longxiang");
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/longxiang-boruo.longxiang");
        message_vision(HIY"$N全身真气缓缓平复。\n" NOR, me);
}

