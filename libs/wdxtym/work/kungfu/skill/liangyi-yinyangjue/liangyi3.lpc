// shield.c 九阳护体神功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "阴阳"ZJBR"护体"; }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用阴阳道经来提升自己的防御力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够。\n");

	if ((int)me->query_skill("liangyi-yinyangjue", 1) < 125)
		return notify_fail("你的阴阳道经等级不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -1000);
	me->receive_damage("qi", 0);

	message_combatd(HIC "$N" HIM "默念阴阳道经的口诀：两"
			    "仪为真，天地和而万物生，阴阳接而变化起，"
			    "……\n刹那间只见$N" 
			HIW "全身真气爆发，左眼化紫阴，右眼化橙阳，$P"
			HIR "宛若神魔。"NOR"\n", me);

	me->add_temp("apply/armor", skill / 2);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill  :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	if (me->query_temp("shield"))
	{
		me->add_temp("apply/armor", -amount);
		me->delete_temp("shield");
		tell_object(me, "你的阴阳道经运行完毕，将内力收回丹田。\n");
	}
}

