// powerup.c 易筋经加力

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, level;

        if( target != me )
                return notify_fail("你只能提升自己的战斗力。\n");
        if( (int)me->query("neili")<200)
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_temp("jingang") ) 
                return notify_fail(HIG"你的全部功力都运在大金刚拳上了。\n"NOR);
        if( (int)me->query_temp("zuida") ) 
                return notify_fail(HIG"你内息翻滚在八仙醉打中，一时提不起易筋经神功。\n"NOR);

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("buddhism",1) > (int)me->query_skill("yijin-jing",1)) level = 3;
        else if ( (int)me->query_skill("buddhism",1) > (int)me->query_skill("yijin-jing",1)*2/3) level = 4;
        else level = 5; 
        if ( (int)me->query_skill("buddhism",1) > 400) level = 3;
        message_combatd(HIR "$N心念一动，浑身力气自然而发，如潮之涨，似雷之动，周而不散，行而不断。\n" NOR, me);

        me->add_temp("apply/attack", skill/level);
        me->add_temp("apply/dodge", skill/level);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/yijin-jing.powerup/name", "加力");                                  //buff名称
        me->set_temp("active_force_buffer/yijin-jing.powerup/last_time", time() + skill/level );              //持续时间
        me->set_temp("active_force_buffer/yijin-jing.powerup/effect1", "攻击命中+"+(skill/level)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/yijin-jing.powerup/effect2", "轻功技能+"+(skill/level)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/level, me, skill/level);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
		if (!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/yijin-jing.powerup");
        tell_object(me, "你的易筋经神功运行完毕，将内力收回丹田。\n");
}

