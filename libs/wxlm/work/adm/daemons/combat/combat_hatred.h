string *catch_hunt_msg = ({
	append_color(HIW "$N眼中杀机一闪，冷冷道：「$n，今日便要将你这血海深仇一并清算！」"NOR"\n", HIW),
	append_color(HIW "$N目光如电，一见$n便怒喝道：「孽障，今日便要将你碎尸万段！」"NOR"\n", HIW),
	append_color(HIW "$N见到$n的身影，浑身杀气暴涨，长啸一声：「血债血偿！」"NOR"\n", HIW),
	append_color(HIW "$N凝视着$n，咬牙切齿道：「仇人相见，分外眼红，今日便要你血溅五步！」"NOR"\n", HIW),
	append_color(HIW "$N双目赤红，对着$n厉声喝道：「今日便要将这血海深仇了结！」"NOR"\n", HIW),
	append_color(HIW "$N眸中寒光一闪，冷冷道：「$n，你我之间的生死大仇，今日便做个了断！」"NOR"\n", HIW),
	append_color(HIW "$N一见$n，浑身杀气四溢，怒喝道：「$n，纳命来！」"NOR"\n", HIW) });

void start_berserk(object me, object obj)
{
	int shen;

	// 检查对象是否存活
	if (! me || ! obj || ! living(me)) return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) || environment(me) != environment(obj) || (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N眼神中闪过一丝戾气，浑身散发出凌厉的杀意。\n", me);

	if (! userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 )
		return;

	if (shen > (int)me->query("score") && ! wizardp(obj))
	{
		message_vision("$N目光如电，对着$n冷冷道：" + RANK_D->query_self_rude(me) + "今日便要取你性命！\n", me, obj);
		me->kill_ob(obj);
		if (living(obj) && ! userp(obj))
			obj->kill_ob(me);
		else
			obj->fight_ob(me);
	} else
	{
		message_vision("$N双目精光四射，对着$n傲然道：" + RANK_D->query_rude(obj) + "，" + RANK_D->query_self_rude(me) + "正欲领教阁下高招，请赐教！\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}
}

void start_hatred(object me, object obj)
{
	if (! me || ! obj || ! living(me))
		return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) || environment(me) != environment(obj) || 
		(environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	if (me->query_temp("owner") == obj->query("id") ||
	    obj->query_temp("owner") == me->query("id"))
		return;

	// We found our hatred! Charge!
	if (me->query("can_speak"))
		message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);

	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);

	if (! playerp(me) && me->is_busy() && ! intp(me->query_busy()))
		me->interrupt_me(me);
}

void start_vendetta(object me, object obj)
{
	if (! me || ! obj || ! living(me))
		return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) ||
	    environment(me) != environment(obj) ||
	    (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	// We found our vendetta opponent! Charge!
	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);
}

void start_aggressive(object me, object obj)
{
	if (! me || ! obj || ! living(me)) return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) ||
	    environment(me) != environment(obj) ||
	    (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	// We got a nice victim! Kill him/her/it!!!
	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);
}