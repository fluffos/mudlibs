// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［莫无尘］用在自己的身上。\n");
        if( (int)me->query("neili") < 100 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("wuchen") ) return 
	notify_fail("你已经在施展［莫无尘］了。\n");
	skill = me->query_skill("nodust-steps",1);
	if(skill < 150) return notify_fail("你的无尘步太差了！\n");
	 me->add("neili", -100);
        message_vision( HIR
"$N轻身一跃，使出无尘步法中的［莫无尘］，身影随风，无处不在！\n" NOR, me);
        me->add_temp("apply/dodge", skill/7);
        me->set_temp("wuchen", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/7 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("wuchen");
        tell_object(me, "你的［莫无尘］施展完毕，身行稳定了下来。\n");
}
 
