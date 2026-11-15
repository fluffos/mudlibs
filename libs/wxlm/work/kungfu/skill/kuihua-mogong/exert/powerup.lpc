// powerup.c



inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "葵花"ZJBR"魔气"; }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用葵花魔功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("kuihua-mogong");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "脸色忽红忽白，邪气大现，眼"
			"中精光一亮，渐渐又失去神色。"NOR"\n", me);

	me->add_temp("apply/attack", skill * 2 / 5);
	me->add_temp("apply/defense", skill * 2 / 5);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill * 2 / 5 :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
		me->add_temp("apply/defense", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的葵花魔功运行完毕，将内力收回丹田。\n");
	}
}
