// maze.c 奇门八卦迷阵

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, object target, int count, int skill);

int exert(object me, object target)
{
	int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("奇门五转只能对战斗中的对手使用。\n");

	if (me->query_temp("thd/mazed")) 
		return notify_fail("你正在陷入别人布的迷阵中。\n");

	if( (int)me->query("neili") < 80  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("thd/maze") ) 
		return notify_fail("你已经布了一个迷阵了。\n");

	skill = me->query_skill("qimen-wuxing", 1);
	me->add("neili", -80);

	message_vision(
	HIC "$N一边作战，一边利用周围的石块、树枝等布了一个简单的阵，看来敌人暂时间内难以打到$P了。\n" NOR, me);

	me->add_temp("apply/defense", skill/5);
	me->add_temp("apply/dexerity", skill/6);
	me->add_temp("apply/dodge", skill/6);
	me->set_temp("thd/maze", 1);
	target->set_temp("thd/mazed", 1);

	call_out("remove_effect", 1, me, target, skill / 2, skill);

	if( me->is_fighting() ) me->start_busy(1 + random(1));

	return 1;
}

void remove_effect(object me, object target, int count, int skill)
{
	if (objectp(me)) {
		if (count-- > 0 && me->is_fighting(target)) {
			call_out("remove_effect", 1, me, target, count, skill);
			return;
		}
		me->add_temp("apply/defense", - (skill/5));
		me->add_temp("apply/dexerity", - (skill/6));
		me->add_temp("apply/dodge", - (skill/6));
		me->delete_temp("thd/maze");
        if (target && me->is_fighting(target)) {
			tell_object(me, "你布的迷阵已经被" + target->name() + "破坏了。\n");
			if (userp(target) && living(target))
				tell_object(target, me->name() + "对你布的迷阵已经被你识破了。\n");
		}
		else {
			tell_object(me, "你布的迷阵已经失效了。\n");
		}
	}
	if (objectp(target))
		target->delete_temp("thd/mazed");
}
