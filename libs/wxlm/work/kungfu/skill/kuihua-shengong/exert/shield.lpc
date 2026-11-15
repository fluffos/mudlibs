// shield.c 护体神功
//



inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "邪气护体"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用邪气护体来提升自己的防御力。\n");
	
	if (userp(me) && !me->query("special_skill/ghost"))
		return notify_fail("你没有鬼脉属性，无法运用邪气护体。\n");
	
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");

	if (userp(me) && (int)me->query_skill("kuihua-shengong", 1) < 100)
		return notify_fail("你的葵花神功修为不够。\n");

	if ((int)me->query_temp("shield"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW "$N" HIW "身子忽前忽后，忽左忽右，一"
			"层层气浪跌宕翻涌，护住全身！"NOR"\n", me);

	me->add_temp("apply/armor", skill*150/100);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	me->add_temp("apply/armor", -(amount*150/100));
	me->delete_temp("shield");
	tell_object(me, "你的葵花神功运行完毕，将内力收回丹田。\n");
}

