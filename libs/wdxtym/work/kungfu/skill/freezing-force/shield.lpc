// shield.c 冰蚕寒功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount);

string query_name() { return "冰蚕"ZJBR"护体"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	string msg;

	if ((int)me->query_skill("freezing-force", 1) < 100)
		return notify_fail("你的冰蚕寒功不够深厚，不能使用冰蚕护体。\n");

	if ((int)me->query("neili") < 200) 
		return notify_fail("你现在的真气不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	msg = HIY "$N" HIY "缓提一口真气，慢慢凝聚，一股股寒冰之气犹如蚕茧开始慢慢包裹在$N的全身。"NOR"\n";
	message_combatd(msg, me);

	me->add_temp("apply/armor", skill *2 / 5 );
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill *2 / 5 :), skill);

	me->add("neili", -100);
	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/armor", -amount);
		me->delete_temp("shield");
		tell_object(me, "你将冰蚕寒功运转过一个周天，将内力收回丹田。\n");
	}
}

