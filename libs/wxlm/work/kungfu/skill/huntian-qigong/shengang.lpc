// shengang.c 混天气功混天神罡



inherit F_SSERVER;

void remove_effect(object me, int amount);

string query_name() { return "混天"ZJBR"神罡"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
   
	string msg;
	int skill;

	if ((int)me->query_temp("shengang"))
		return notify_fail(HIG"你已经在运混天神罡了。\n");

	if (! me->is_fighting())
		return notify_fail("「混天神罡」只能在战斗中使用。\n");

	if ((int)me->query("neili") < 200)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的混天气功的修为不够，不能使用混天神罡！\n");

	msg = HIY "$N" HIY "使出混天气功「混天神罡」，将真气贯注到手心！"NOR"\n";

	skill = (int)me->query_skill("huntian-qigong", 1);

	me->add_temp("apply/damage", skill / 2);
	me->add_temp("apply/unarmed_damage", skill / 2);
	me->set_temp("shengang", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill / 2 :), skill);
	me->add("neili", -150);

	message_combatd(msg, me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("shengang"))
	{
		me->add_temp("apply/damage", -amount);
		me->add_temp("apply/unarmed_damage", -amount);
		me->delete_temp("shengang");
		tell_object(me, "你的混天神罡运行完毕，将内力收回丹田。\n");
	}
}