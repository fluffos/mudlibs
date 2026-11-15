// roar.c 鬼哭



inherit F_CLEAN_UP;

string query_name() { return "鬼哭"ZJBR"魔音"; }

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够。\n");

	skill = me->query_skill("kuihua-mogong")*2;

	me->add("neili", -100);
	me->receive_damage("qi", 10);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人! \n");

	me->start_busy(5);
	message_combatd(HIR "$N" HIR "极嘶长呼，声音凄厉之"
			"极，令人毛骨悚然！"NOR"\n", me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if (! ob[i]->is_character() || ob[i] == me)
			continue;
		if (! playerp(me) && !playerp(ob[i]))
			continue;

		if (skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2)
			continue;

		if (userp(ob[i]) && !ob[i]->die_protect(me))
			continue;

		me->want_kill(ob[i]);
		me->fight_ob(ob[i]);
		ob[i]->kill_ob(me);
		
		damage = skill - ((int)ob[i]->max_neili() / 10);
		if (damage > 0)
		{
			ob[i]->set("last_damage_from", me);
			ob[i]->receive_damage("qi", damage, me);
			if ((int)ob[i]->query("neili") < skill * 2)
				ob[i]->receive_damage("qi", damage/2, me);
			tell_object(ob[i], "你只觉得耳膜欲破，心烦气燥，恶心不止......\n");
		}
	}
	return 1;
}
