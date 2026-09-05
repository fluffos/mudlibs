// jianyi.c 华山内功 剑意 重在+apply/dam，/att, 对应的 剑气+ /dodge/att
// 剑宗大弟子专用

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        //if( target != me )
        //        return notify_fail("你只能用紫霞神功来提升自己的战斗力。\n");

        if( (int)me->query_str() < 50  )
                return notify_fail("你的臂力不够，使不出纯正的「剑意」。\n");
        if( (int)me->query_int() < 50  )
                return notify_fail("你的悟性不足，无法领会「剑意」万般皆剑的奥秘。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
		
        // dewolf 大弟子判定
        if( me->query("id") != DADIZI_D->query_name("huashanj") 
		        || me->query("family/master_id")!="feng qingyang" )
                return notify_fail("只有本派剑宗大弟子才有权使用华山内功之「剑意」！\n");
    
        if( (int)me->query("neili") < 100  )
                return notify_fail("你的内力不够。\n");
		
        if ((int)me->query_skill("huashan-neigong", 1) < 300)
                return notify_fail("你的华山内功等级不够，不能发出「剑意」。\n");
		
        if ((int)me->query_skill("zixia-shengong", 1) >100)
                return notify_fail("你的气宗内功太高，严重阻碍了「剑意」的施展。\n");		

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);

        message_vision(
        HIG "$N清叹一声：「招非招，剑非剑，无剑非无剑，无招非无招」，然而剑意似绝非断， 一举手一投足都发挥得淋漓尽致！\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/damage", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out(__FILE__, "remove_effect", skill, me, skill/4);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/damage", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的华山内功运行完毕，将内力收回丹田。\n");
}
