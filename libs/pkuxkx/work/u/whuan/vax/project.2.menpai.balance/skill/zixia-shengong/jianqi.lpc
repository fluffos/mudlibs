// jianqi.c 紫霞神功加力 稍微加强版，
// 气宗大弟子专用

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能用紫霞神功来提升自己的战斗力。\n");

        if( (int)me->query("neili") < 1000  )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
		
        // dewolf 大弟子判定
        if( me->query("family/family_name")!="华山派" || !me->query("family/topone")
		        || me->query("family/master_id")=="feng qingyang")
                return notify_fail("只有本派气宗大弟子才有权使用紫霞神功之「剑气」！\n");
    
        if ((int)me->query_skill("zixia-shengong", 1) < 300)
                return notify_fail("你的紫霞神功等级不够，不能提升战斗力。\n");

        if ((int)me->query_skill("huashan-neigong", 1) >100)
                return notify_fail("你的剑宗内功太高，会严重影响了紫霞神功的气宗法门。\n");
		
        skill = me->query_skill("force");
        me->add("neili", -1000);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N运起紫霞神功，脸上微微泛出一丝紫气。\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/4);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的紫霞神功运行完毕，将内力收回丹田。\n");
}
