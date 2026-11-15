// sui.c 太极剑法 「随」字决



inherit F_SSERVER;

void remove_effect(object me, int a_amount, int d_amount);

string query_name() { return "随字诀"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("太极剑法「随」字诀只能在战斗中使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("taiji-jian", 1) < 60)
		return notify_fail("你的太极剑法不够娴熟，不会使用「随」字诀。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_temp("tjj_sui"))
		return notify_fail("你已经在运功中了。\n");

	if (me->query_skill_mapped("sword") != "taiji-jian") 
		return notify_fail("你没有激发太极剑法，无法使用「随」字诀！\n");

	skill = me->query_skill("taiji-jian", 1);

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIB "$N" HIB "使出太极剑法「随」字诀，剑圈逐渐缩小将周身护住。"NOR"\n";
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill / 6);
	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("tjj_sui", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill / 6, skill / 3 :), skill / 3);

	me->add("neili", -100);
	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	if (me->query_temp("tjj_sui"))
	{
		me->add_temp("apply/attack", a_amount);
		me->add_temp("apply/dodge", -d_amount);
		me->delete_temp("tjj_sui");
		tell_object(me, "你的随字决运行完毕，将内力收回丹田。\n");
	}
}

