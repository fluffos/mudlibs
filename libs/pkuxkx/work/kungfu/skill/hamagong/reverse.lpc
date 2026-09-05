// reserve.c 蛤蟆功经脉倒转

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount);

int exert(object me, object target)
{
        object weapon;
        
        string msg;
        int skill;
        if( !me->query("reverse"))
                return notify_fail("你的外功中没有这种功能。\n");        
        if( target != me ) 
                return notify_fail("你只能使自己的经脉倒转。\n");
        if( (int)me->query_skill("hamagong", 1) < 120 )
                return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");
        if( (int)me->query("neili") < 500  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("hmg_dzjm") ) 
                return notify_fail("你已经倒转经脉了。\n");
        if ( me->query_temp("powerup") )
        		return notify_fail("你已经在运功中了。\n");

        skill = (int)me->query_skill("hamagong",1)/12;
 
        message_vision(HIB "$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，攻击防御同时大增。\n"NOR, me);       
        me->set_temp("powerup", 1);
        me->add_temp("apply/attack", skill*3);
        me->add_temp("apply/dodge", skill*5);
        me->add_temp("apply/parry", skill*3);
        me->add_temp("apply/strength", skill/2);
        me->add_temp("apply/armor", skill*3);
        me->set_temp("apply/cant_busy_jiemai",1);
        me->set_temp("hmg_dzjm", 1);
        me->add("neili", -300);

        me->set_temp("active_force_buffer/hamagong.reverse/name", "经脉倒转");                          //buff名称
        me->set_temp("active_force_buffer/hamagong.reverse/last_time", time() + skill*6 );              //持续时间
        me->set_temp("active_force_buffer/hamagong.reverse/effect1", "攻击命中+"+(skill*3)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/hamagong.reverse/effect2", "轻功技能+"+(skill*5)+"级");       //效果描述2
        me->set_temp("active_force_buffer/hamagong.reverse/effect3", "招架技能+"+(skill*3)+"级");       //效果描述3
        me->set_temp("active_force_buffer/hamagong.reverse/effect4", "后天膂力+"+(skill/2)+"点");       //效果描述4
        me->set_temp("active_force_buffer/hamagong.reverse/effect5", "护甲防御+"+(skill*3)+"点");       //效果描述5
        me->set_temp("active_force_buffer/hamagong.reverse/effect6", "截脉免疫");                       //效果描述5

        me->start_call_out(__FILE__, "remove_effect", skill*6, me, skill);
        me->start_call_out(__FILE__, "remove_effect2", skill, me);

        if( me->is_fighting() )  me->start_busy(3);

        return 1;
}

void remove_effect(object me, int a_amount)
{
        me->add_temp("apply/attack", - a_amount*3);
        me->add_temp("apply/dodge", - a_amount*5);
        me->add_temp("apply/parry", - a_amount*3);
        me->add_temp("apply/strength", - a_amount/2);
        me->add_temp("apply/armor", - a_amount*3);
        me->delete_temp("hmg_dzjm");
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/hamagong.reverse");
        tell_object(me, HIY "你双手一撑，一跃而起，将内力收回丹田。\n"NOR);
}

void remove_effect2(object me)
{
        me->delete_temp("apply/cant_busy_jiemai");
        me->delete_temp("active_force_buffer/hamagong.reverse/effect6");
}