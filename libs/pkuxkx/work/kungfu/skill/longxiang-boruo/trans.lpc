// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
        int skill,skill2;
        skill = me->query_skill("longxiang-boruo");
        skill2 = me->query_skill("force");
        if( !target )
                return notify_fail("你要把真力传送给谁？\n");

        if( me->is_fighting())
                return notify_fail("在战斗中无法送出真力给他人！\n");

        if(target == me)
                return notify_fail("只能把真力传给别人。\n");

        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 1500 )
                return notify_fail("你的真气不够。\n");
        if (me->query_skill("longxiang-boruo",1)<100)
                return notify_fail("你的龙象般若功修为不够，无法传出内力给别人。\n");
/*
        if (target->query_skill("longxiang-boruo",1)<80)
            return notify_fail("对方龙象般若功修为不够，内力无法和你融合为一。\n");
*/
        if (target->query_temp("trans") >= 1)
            return notify_fail("对方已经受过功了，再传他的身体就吃不消了。\n");
        message_vision(
                HIC "$N运起内功，将手掌贴在$n背心，一股真气在两人体内盘旋流动，将两人内力串为一体。\n\n"
                "过了不久，$N一声长啸向后跃开，部分真力却早已留在$n体内，和$n内力融为一体，再也无法分离。\n" NOR,me, target );

        target->add("neili",skill+random(skill2*4));
        target->add("max_neili",skill/20);
        me->add("neili", -(skill+skill2)*2);
        me->add("max_neili", -skill/20);
        target->set_temp("trans",1);
        target->add_temp("apply/damage", skill/5);
        target->set_temp("trans_1",skill /5);
        target->add_temp("apply/attack", skill2 /5); 
        target->set_temp("trans_2",skill2 /5);
        me->start_busy(5);
        
        target->set_temp("active_force_buffer/longxiang-boruo.trans/name", "传功");                                  //buff名称
        target->set_temp("active_force_buffer/longxiang-boruo.trans/last_time", time() + skill2 );                   //持续时间
        target->set_temp("active_force_buffer/longxiang-boruo.trans/effect1", "攻击命中+"+(skill2/5)+"级");          //效果描述1   
        target->set_temp("active_force_buffer/longxiang-boruo.trans/effect2", "攻击伤害+"+(skill/5)+"点");           //效果描述2

        call_out("remove_effect", skill2, target);
        if(!target->is_busy())
          target->start_busy(1);
        return 1;
}

void remove_effect(object target)//call_out没对象造成的报错 Zine 2013/5/28
{
	if (!target)
	return;
	target->add_temp("apply/damage", - target->query_temp("trans_1") );
	target->add_temp("apply/attack", - target->query_temp("trans_2") );
	target->delete_temp("trans_1");
	target->delete_temp("trans_2");
	target->delete_temp("active_force_buffer/longxiang-boruo.trans");
	message_vision(MAG"$N脸上紫气一闪，又恢复如常。\n" NOR, target);
}
