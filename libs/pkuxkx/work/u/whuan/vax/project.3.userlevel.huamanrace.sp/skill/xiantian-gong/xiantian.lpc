// xiantian.c 弥补全真内功不足， + 1/3 ，来自 powerup.c 先天功加力
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	
	 // dewolf 大弟子判定
    if( me->query("id") != DADIZI_D->query_name("quanzhen") )
        return notify_fail("只有本派大弟子才有权使用先天大法！\n");
		
	if( target != me )
		return notify_fail("你只能用先天大法来提升自己的战斗力。\n");
	if( (int)me->query("neili") < 150  )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 300)
		return notify_fail("你的先天功等级不够，不能提升战斗力。\n");
//        skill = me->query_skill("force")+me->query_skill("xiantian-gong");
        skill = me->query_skill("force");
	me->add("neili", -150);
	message_vision(HIR "$N气沉丹田，一股纯净的力量慢慢游走在全身。\n" NOR, me);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
//         me->add_temp("apply/defense",skill/5);
	me->set_temp("powerup", 1);
	me->start_call_out(__FILE__, "remove_effect", skill, me, skill/3);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
//          me->add_temp("apply/defense",-amount);
	me->delete_temp("powerup");
	tell_object(me, "你的先天功运行完毕，将内力收回丹田。\n");
}

