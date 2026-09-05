#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用侠客神功来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                 return notify_fail("你已经在运功中了。\n");
        if ((int)me->query_skill("xiake-shengong", 1) < 50)
                return notify_fail("你的侠客神功等级不够，不能提升战斗力。\n");

        skill = me->query_skill("force");

        message_vision(HIR"$N"HIR"气沉丹田，运用侠客神功来提升自己的战斗力。\n" NOR, me);

        me->add_temp("apply/dodge", skill/5);
        me->add_temp("apply/attack", skill/5);
        me->set_temp("powerup", 1);
        me->add("neili", -100);

        me->set_temp("active_force_buffer/xiake-shengong.powerup/name", "加力");                              //buff名称
        me->set_temp("active_force_buffer/xiake-shengong.powerup/last_time", time() + skill/5 );              //持续时间
        me->set_temp("active_force_buffer/xiake-shengong.powerup/effect1", "攻击命中+"+(skill/5)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/xiake-shengong.powerup/effect2", "轻功技能+"+(skill/5)+"级");       //效果描述2

        me->start_call_out(__FILE__, "remove_effect", skill/5, me, skill/5);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/xiake-shengong.powerup");
        tell_object(me, "你的侠客神功运行完毕，将内力收回丹田。\n");
}
