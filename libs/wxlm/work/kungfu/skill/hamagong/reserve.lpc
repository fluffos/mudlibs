// reserve.c 蛤蟆功经脉倒转



inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount);

string query_name() { return "经脉"ZJBR"逆转"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
 
	int skill;
	string msg;

	if ((int)me->query_skill("hamagong", 1) < 120)
		return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");

	if ((int)me->query("neili") < 200) 
		return notify_fail("你现在的真气不够。\n");

	if ((int)me->query_temp("hmg_dzjm"))
		return notify_fail("你已经倒转经脉了。\n");

	skill = me->query_skill("hamagong", 1);
	msg = HIB "$N" HIB "忽地双手撑地倒立，逆运经脉，顿时"
	      "内息暗生，防御力大增。"NOR"\n";
	message_combatd(msg, me);

	me->add_temp("apply/dodge", skill / 4);
	me->add_temp("apply/parry", skill / 4);
	me->add_temp("apply/armor", skill / 2);
	me->add_temp("apply/dispel_poison", skill / 2);
	me->set_temp("hmg_dzjm", skill);

	me->add("neili", -100);
	if (me->is_fighting()) me->start_busy(2);

	return 1;
}
